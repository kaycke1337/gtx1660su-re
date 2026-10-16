// ===== 003cd270 _pmaCheckScrubbedPages =====

int _pmaCheckScrubbedPages(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  undefined8 local_28;
  long local_20;
  
  local_28 = 0;
  local_20 = 0;
  if ((param_4 != 0) && (iVar1 = scrubWaitPages(*(undefined8 *)(param_1 + 0x2d8)), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = scrubCheck(*(undefined8 *)(param_1 + 0x2d8),&local_28,&local_20);
  if (iVar1 == 0) {
    if (local_20 != 0) {
      _pmaClearScrubBit(param_1,local_28);
    }
  }
  else {
    nvAssertFailedNoLog("(status == NV_OK)",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x353)
    ;
  }
  portMemFree(local_28);
  return iVar1;
}


// ===== 003cd320 _pmaEvictContiguous =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _pmaEvictContiguous(undefined8 *param_1,undefined8 param_2,ulong param_3,long param_4,
                       undefined4 param_5)

{
  ulong uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  uint local_84;
  long local_78;
  byte local_68;
  ulong local_50;
  undefined8 local_48;
  long local_40 [2];
  
  local_50 = param_3;
  lVar9 = (**(code **)(param_1[0x46] + 0x90))(param_2);
  uVar6 = (param_4 - local_50) + 1;
  cVar2 = *(char *)(param_1 + 0x5c);
  uVar10 = uVar6 >> 0x10;
  (**(code **)(param_1[0x46] + 0x98))(param_2,lVar9 + uVar10);
  pmaSetBlockStateAttribUnderPmaLock(param_1,local_50,uVar6,4,4);
  portSyncSpinlockRelease(*param_1);
  if (*(char *)(param_1 + 0x59) == '\0') {
    iVar3 = (*(code *)param_1[0x49])(param_1[0x47],local_50,param_4,param_5);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x1f5,
                 "_pmaEvictContiguous",1,"NVRM: evictRangeCb returned with status %llx\n");
LAB_003cd40f:
    portSyncSpinlockAcquire(*param_1);
    if (cVar2 != '\0') {
LAB_003cd570:
      uVar1 = local_50;
      if (*(uint *)(param_1 + 4) != 0) {
        uVar8 = 0;
        do {
          uVar7 = *(ulong *)param_1[uVar8 + 0x26];
          if ((local_50 <= ((ulong *)param_1[uVar8 + 0x26])[1]) && (uVar7 <= local_50)) {
            local_84 = (uint)uVar8;
            goto LAB_003cd5c6;
          }
          uVar8 = uVar8 + 1;
        } while (*(uint *)(param_1 + 4) != uVar8);
      }
      nvAssertFailedNoLog(&DAT_00d54f44,
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x4e
                         );
      local_84 = 0;
      uVar7 = *(ulong *)param_1[0x26];
LAB_003cd5c6:
      local_78 = param_1[0x5d] + uVar1;
      if (iVar3 == 0) {
        iVar3 = 0;
        if (uVar10 == 0) {
          pmaSetBlockStateAttribUnderPmaLock(param_1,local_50,uVar6,0,0x24);
          uVar6 = (**(code **)(param_1[0x46] + 0x90))(param_2);
          goto LAB_003cd458;
        }
        lVar9 = local_78;
        do {
          uVar4 = osGetPageRefcount(lVar9);
          uVar5 = osCountTailPages(lVar9);
          if (uVar5 < uVar4) {
            local_68 = osGetPageShift();
            if (local_68 < 0x11) goto LAB_003cd5fa;
            goto LAB_003cd786;
          }
          lVar9 = lVar9 + 0x10000;
        } while (uVar10 * 0x10000 + local_78 != lVar9);
      }
      else {
        local_68 = osGetPageShift();
        if (local_68 < 0x11) {
          if (uVar10 == 0) {
            iVar3 = 0x51;
            pmaSetBlockStateAttribUnderPmaLock(param_1,local_50,uVar6,0,0x24);
            uVar6 = (**(code **)(param_1[0x46] + 0x90))(param_2);
            goto LAB_003cd458;
          }
LAB_003cd5fa:
          local_68 = 0x10 - local_68;
          uVar8 = uVar1 - uVar7 >> 0x10;
          uVar1 = uVar10 + uVar8;
          do {
            uVar7 = (**(code **)(param_1[0x46] + 0x40))(param_1[(ulong)local_84 + 5],uVar8,1);
            if ((uVar7 & 0x20) != 0) {
              osAllocReleasePage(local_78,1 << (local_68 & 0x1f));
              (**(code **)(param_1[0x46] + 0x18))(param_1[(ulong)local_84 + 5],uVar8,0,0x23);
            }
            uVar8 = uVar8 + 1;
            local_78 = local_78 + 0x10000;
          } while (uVar8 != uVar1);
          iVar3 = 0x51;
        }
        else {
LAB_003cd786:
          iVar3 = 0x40;
          nvAssertFailedNoLog("PMA_PAGE_SHIFT >= osPageShift",
                              "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",
                              0x186);
        }
      }
    }
  }
  else {
    local_48 = 0;
    portSyncMutexRelease(param_1[3]);
    iVar3 = (*(code *)param_1[0x49])(param_1[0x47],local_50,param_4,param_5);
    portSyncMutexAcquire(param_1[3]);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x1c5,
                 "_pmaEvictContiguous",1,"NVRM: evictRangeCb returned with status %llx\n",iVar3);
    if (iVar3 != 0) goto LAB_003cd40f;
    if (cVar2 != '\0') {
      iVar3 = scrubSubmitPages(param_1[0x5b],uVar6 & 0xffffffff,&local_50,1,&local_48,local_40);
      if (iVar3 == 0) {
        if (local_40[0] != 0) {
          _pmaClearScrubBit(param_1,local_48,local_40[0],0x3cd4f2);
        }
        iVar3 = _pmaCheckScrubbedPages(param_1,uVar6,&local_50,1);
        if (iVar3 != 0) goto LAB_003cd6d0;
        portMemFree(local_48);
        portSyncSpinlockAcquire(*param_1);
        iVar3 = 0;
      }
      else {
LAB_003cd6d0:
        iVar3 = 0x1a;
        portMemFree(local_48);
        portSyncSpinlockAcquire(*param_1);
      }
      goto LAB_003cd570;
    }
    iVar3 = _pmaCheckScrubbedPages(param_1,uVar6,&local_50,1);
    if (iVar3 != 0) {
      portMemFree(local_48);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x1ee,
                   "_pmaEvictContiguous",1,"NVRM: ERROR: scrubber OOM!\n");
      return 0x1a;
    }
    portMemFree(local_48);
    portSyncSpinlockAcquire(*param_1);
    iVar3 = 0;
  }
  pmaSetBlockStateAttribUnderPmaLock(param_1,local_50,uVar6,0,0x24);
  uVar6 = (**(code **)(param_1[0x46] + 0x90))(param_2);
  if (uVar6 < uVar10) {
    nvAssertFailedNoLog("frameEvictionsInProcess >= numFramesToEvict",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x208)
    ;
  }
LAB_003cd458:
  (**(code **)(param_1[0x46] + 0x98))(param_2,uVar6 - uVar10);
  return iVar3;
}


// ===== 003cd8a0 _pmaEvictPages =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _pmaEvictPages(undefined8 *param_1,undefined8 param_2,ulong *param_3,ulong param_4,long param_5,
                  long param_6,ulong param_7,undefined8 param_8,undefined8 param_9,
                  undefined4 param_10)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  undefined8 local_48;
  long local_40 [2];
  
  uVar5 = (param_7 >> 0x10) * param_4;
  lVar9 = (**(code **)(param_1[0x46] + 0x90))(param_2);
  cVar2 = *(char *)(param_1 + 0x5c);
  (**(code **)(param_1[0x46] + 0x98))(param_2,uVar5 + lVar9);
  if (param_6 != 0) {
    lVar9 = 0;
    do {
      lVar1 = lVar9 * 8;
      lVar9 = lVar9 + 1;
      pmaSetBlockStateAttribUnderPmaLock(param_1,*(undefined8 *)(param_5 + lVar1),param_7,2,2);
    } while (param_6 != lVar9);
  }
  portSyncSpinlockRelease(*param_1);
  if (*(char *)(param_1 + 0x59) == '\0') {
    iVar3 = (*(code *)param_1[0x48])
                      (param_1[0x47],param_7,param_3,param_4 & 0xffffffff,param_8,param_9,param_10);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x279,
                 "_pmaEvictPages",1,"NVRM: evictPagesCb returned with status %llx\n",iVar3);
  }
  else {
    local_48 = 0;
    local_40[0] = 0;
    portSyncMutexRelease(param_1[3]);
    iVar3 = (*(code *)param_1[0x48])
                      (param_1[0x47],param_7,param_3,param_4 & 0xffffffff,param_8,param_9);
    portSyncMutexAcquire(param_1[3]);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x241,
                 "_pmaEvictPages",1,"NVRM: evictPagesCb returned with status %llx\n");
    if (iVar3 == 0) {
      uVar4 = 0;
      if (param_4 != 0) {
        if (*(uint *)(param_1 + 4) != 0) {
          uVar6 = *param_3;
          uVar7 = 0;
          do {
            uVar8 = *(ulong *)param_1[uVar7 + 0x26];
            if ((uVar6 <= ((ulong *)param_1[uVar7 + 0x26])[1]) && (uVar8 <= uVar6)) {
              uVar7 = uVar7 & 0xffffffff;
              goto LAB_003cdc06;
            }
            uVar7 = uVar7 + 1;
          } while (*(uint *)(param_1 + 4) != uVar7);
        }
        nvAssertFailedNoLog(&DAT_00d54f44,
                            "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",
                            0x4e);
        uVar6 = *param_3;
        uVar8 = *(ulong *)param_1[0x26];
        uVar7 = 0;
LAB_003cdc06:
        uVar4 = (**(code **)(param_1[0x46] + 0x50))(param_1[uVar7 + 5],uVar6 - uVar8 >> 0x10);
        uVar4 = uVar4 & 1;
      }
      iVar3 = scrubSubmitPages(param_1[0x5b],param_7,param_3,param_4 & 0xffffffff,&local_48,local_40
                               ,uVar4);
      if (iVar3 == 0) {
        if (local_40[0] != 0) {
          _pmaClearScrubBit(param_1,local_48);
        }
        iVar3 = _pmaCheckScrubbedPages(param_1,param_7,param_3,param_4 & 0xffffffff);
      }
      else {
        nvAssertFailedNoLog("(status == NV_OK)",
                            "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",
                            0x263);
      }
      portMemFree(local_48);
      if ((iVar3 != 0) && (cVar2 == '\0')) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x271,
                     "_pmaEvictPages",4,"NVRM: ERROR: scrubber OOM!\n");
        nvAssertOkFailedNoLog
                  (0x1a,"status",
                   "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x272);
        return 0x1a;
      }
    }
  }
  portSyncSpinlockAcquire(*param_1);
  if (param_6 != 0) {
    lVar9 = 0;
    do {
      lVar1 = lVar9 * 8;
      lVar9 = lVar9 + 1;
      pmaSetBlockStateAttribUnderPmaLock(param_1,*(undefined8 *)(param_5 + lVar1),param_7,0,2);
    } while (param_6 != lVar9);
  }
  uVar6 = (**(code **)(param_1[0x46] + 0x90))(param_2);
  if (uVar6 < uVar5) {
    nvAssertFailedNoLog("frameEvictionsInProcess >= numFramesToEvict",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x285)
    ;
  }
  (**(code **)(param_1[0x46] + 0x98))(param_2,uVar6 - uVar5);
  return iVar3;
}


// ===== 003cdcc0 _pmaPredictOutOfMemory =====

byte _pmaPredictOutOfMemory(long param_1,ulong param_2,ulong param_3,uint *param_4)

{
  uint uVar1;
  ulong uVar2;
  byte bVar3;
  uint uVar4;
  
  uVar1 = *param_4;
  uVar4 = uVar1 >> 0xc;
  if (((*(long *)(param_4 + 8) == 0x200000 & (byte)(uVar1 >> 9)) == 0) && (param_3 != 0x200000)) {
    if ((uVar1 & 0x100) == 0) {
LAB_003cdd2f:
      uVar2 = (*(long *)(param_1 + 0x268) - *(long *)(param_1 + 0x280)) * 0x10000;
    }
    else {
LAB_003cdd64:
      uVar2 = *(long *)(param_1 + 0x280) << 0x10;
    }
    if ((uVar2 < param_3) || ((uVar4 & 1) == 0)) {
      return -(uVar2 < param_3 * param_2) & 0x51;
    }
LAB_003cdd0c:
    bVar3 = 0;
  }
  else {
    uVar2 = *(ulong *)(param_1 + 0x288);
    if ((uVar1 & 0x100) == 0) {
      if ((*(ulong *)(param_1 + 0x270) != uVar2) && ((uVar4 & 1) != 0)) {
        return 0;
      }
      if (param_2 <= *(ulong *)(param_1 + 0x270) - uVar2) goto LAB_003cdd2f;
    }
    else {
      if ((uVar2 != 0) && ((uVar4 & 1) != 0)) goto LAB_003cdd0c;
      if (param_2 <= uVar2) goto LAB_003cdd64;
    }
    bVar3 = 0x51;
  }
  return bVar3;
}


// ===== 003cdd90 _pmaFreeBlacklistPages =====

void _pmaFreeBlacklistPages(long param_1,undefined8 param_2,ulong param_3,long param_4)

{
  ulong *puVar1;
  ulong uVar2;
  ulong *puVar3;
  
  if (*(uint *)(param_1 + 0x308) == 0) {
    return;
  }
  puVar1 = *(ulong **)(param_1 + 0x300);
  puVar3 = puVar1 + (ulong)*(uint *)(param_1 + 0x308) * 2;
  while (((*(char *)((long)puVar1 + 9) == '\0' || (uVar2 = *puVar1, uVar2 < param_3)) ||
         ((param_3 - 1) + param_4 < uVar2))) {
    puVar1 = puVar1 + 2;
    if (puVar1 == puVar3) {
      *(undefined1 *)(param_1 + 0x30c) = *(undefined1 *)(param_1 + 0x30c);
      return;
    }
  }
LAB_003cde00:
  pmaSetBlockStateAttribUnderPmaLock(param_1,uVar2 & 0xffffffffffff0000,0x10000,0,0x40);
  *(undefined1 *)((long)puVar1 + 9) = 0;
  while (puVar1 = puVar1 + 2, puVar1 != puVar3) {
    while ((*(char *)((long)puVar1 + 9) != '\0' && (uVar2 = *puVar1, param_3 <= uVar2))) {
      if (uVar2 <= (param_3 - 1) + param_4) goto LAB_003cde00;
      puVar1 = puVar1 + 2;
      if (puVar1 == puVar3) goto LAB_003cde70;
    }
  }
LAB_003cde70:
  *(undefined1 *)(param_1 + 0x30c) = 1;
  return;
}


// ===== 003cde80 _pmaReallocBlacklistPages =====

void _pmaReallocBlacklistPages(long param_1,undefined8 param_2,ulong param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *(uint *)(param_1 + 0x308);
  if ((*(char *)(param_1 + 0x30c) == '\0') || (uVar1 == 0)) {
    return;
  }
  lVar2 = *(long *)(param_1 + 0x300);
  if (*(char *)(param_1 + 0x2c8) != '\0') {
    nvAssertFailedNoLog("pPma->bScrubOnFree == NV_FALSE",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x401)
    ;
  }
  pcVar4 = (char *)(lVar2 + 9);
  uVar5 = 0;
  uVar6 = 0;
  do {
    while( true ) {
      if (*pcVar4 != '\0') break;
      uVar3 = *(ulong *)(pcVar4 + -9);
      if ((uVar3 < param_3) || ((param_3 - 1) + param_4 < uVar3)) goto LAB_003cdef3;
      pmaSetBlockStateAttribUnderPmaLock(param_1,uVar3 & 0xffffffffffff0000,0x10000,0x40,0x40);
      *pcVar4 = '\x01';
LAB_003cdf0c:
      uVar5 = uVar5 + 1;
      uVar6 = uVar6 + 1;
      pcVar4 = pcVar4 + 0x10;
      if (uVar1 <= uVar5) goto LAB_003cdf1d;
    }
    if (*pcVar4 == '\x01') goto LAB_003cdf0c;
LAB_003cdef3:
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 0x10;
  } while (uVar5 < uVar1);
LAB_003cdf1d:
  if (uVar6 == uVar1) {
    *(undefined1 *)(param_1 + 0x30c) = 0;
  }
  return;
}


// ===== 003cdfb0 pmaBuildList =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 pmaBuildList(long param_1,long *param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long *local_60;
  ulong local_58;
  
  if (param_2 == (long *)0x0) {
    return 0x1f;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    lVar8 = 0;
    local_58 = 0;
    local_60 = (long *)0x0;
    uVar9 = 0;
LAB_003ce010:
    plVar6 = *(long **)(param_1 + 0x130 + lVar8 * 8);
    lVar1 = *plVar6;
    uVar7 = (ulong)((plVar6[1] + 1) - lVar1) >> 0x10;
    if (uVar7 != 0) {
      uVar2 = *(undefined8 *)(param_1 + 0x28 + lVar8 * 8);
      bVar3 = false;
      uVar10 = 0;
LAB_003ce071:
      uVar4 = (**(code **)(*(long *)(param_1 + 0x230) + 0x40))(uVar2,uVar10,1);
      if ((param_3 & uVar4) != 0) {
        local_58 = uVar10;
        if (!bVar3) {
          bVar3 = true;
          uVar9 = uVar10;
        }
joined_r0x003ce06f:
        uVar10 = (ulong)((int)uVar10 + 1);
        if (uVar7 <= uVar10) goto LAB_003ce0f0;
        goto LAB_003ce071;
      }
      if (!bVar3) goto joined_r0x003ce06f;
      plVar6 = (long *)portMemAllocNonPaged(0x18);
      if (plVar6 != (long *)0x0) {
        bVar3 = false;
        plVar6[2] = (long)local_60;
        *plVar6 = uVar9 * 0x10000 + lVar1;
        plVar6[1] = lVar1 + 0xffff + local_58 * 0x10000;
        local_60 = plVar6;
        goto joined_r0x003ce06f;
      }
      if (local_60 == (long *)0x0) goto LAB_003ce1c4;
      do {
        plVar6 = (long *)local_60[2];
        portMemFree(local_60);
        local_60 = plVar6;
      } while (plVar6 != (long *)0x0);
      goto LAB_003ce1c1;
    }
    goto LAB_003ce0fd;
  }
  local_60 = (long *)0x0;
  uVar5 = 0;
  goto LAB_003ce1d9;
LAB_003ce0f0:
  if (!bVar3) {
LAB_003ce0fd:
    lVar8 = lVar8 + 1;
    if (*(uint *)(param_1 + 0x20) <= (uint)lVar8) goto LAB_003ce10b;
    goto LAB_003ce010;
  }
  plVar6 = (long *)portMemAllocNonPaged(0x18);
  if (plVar6 != (long *)0x0) {
    lVar8 = lVar8 + 1;
    plVar6[2] = (long)local_60;
    *plVar6 = uVar9 * 0x10000 + lVar1;
    plVar6[1] = lVar1 + 0xffff + local_58 * 0x10000;
    local_60 = plVar6;
    if (*(uint *)(param_1 + 0x20) <= (uint)lVar8) {
LAB_003ce10b:
      *param_2 = (long)local_60;
      return 0;
    }
    goto LAB_003ce010;
  }
  if (local_60 != (long *)0x0) {
    do {
      plVar6 = (long *)local_60[2];
      portMemFree(local_60);
      local_60 = plVar6;
    } while (plVar6 != (long *)0x0);
LAB_003ce1c1:
    local_60 = (long *)0x0;
  }
LAB_003ce1c4:
  uVar5 = 0x51;
LAB_003ce1d9:
  *param_2 = (long)local_60;
  return uVar5;
}


// ===== 003ce210 pmaFreeList =====

void pmaFreeList(undefined8 param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *param_2;
  while (lVar2 != 0) {
    lVar1 = *(long *)(lVar2 + 0x10);
    portMemFree(lVar2);
    lVar2 = lVar1;
  }
  *param_2 = 0;
  return;
}


// ===== 003ce250 pmaRegisterBlacklistInfo =====

undefined8
pmaRegisterBlacklistInfo(undefined8 *param_1,undefined8 param_2,ulong *param_3,int param_4)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  long lVar7;
  
  if ((param_4 != 0) && (param_3 != (ulong *)0x0)) {
    if (param_1[0x60] == 0) {
      lVar7 = portMemAllocNonPaged(0x2000);
      param_1[0x60] = lVar7;
      if (lVar7 == 0) {
        *(undefined4 *)(param_1 + 0x61) = 0;
        nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x4f9,
                     "pmaRegisterBlacklistInfo",4,
                     "NVRM: ERROR: Insufficient memory to allocate blacklisting tracking structure.\n"
                    );
        return 0x51;
      }
      portMemSet(lVar7,0,0x2000);
    }
    uVar2 = *(uint *)(param_1 + 0x61);
    uVar4 = param_4 + uVar2;
    if (uVar2 < uVar4) {
      lVar7 = (ulong)uVar2 * 0x10 - (long)param_3;
      puVar1 = param_3 + (ulong)(param_4 - 1) * 2 + 2;
      do {
        puVar6 = (ulong *)((long)param_3 + param_1[0x60] + lVar7);
        *puVar6 = *param_3;
        *(char *)(puVar6 + 1) = (char)param_3[1];
        uVar3 = *param_3;
        portSyncSpinlockAcquire(*param_1);
        pmaSetBlockStateAttribUnderPmaLock(param_1,uVar3 & 0xffffffffffff0000,0x10000,0x40,0x40);
        portSyncSpinlockRelease(*param_1);
        *(undefined1 *)((long)puVar6 + 9) = 1;
        if (((*(char *)(param_1 + 0x5c) != '\0') && (*(char *)((long)param_1 + 0x2fc) != '\0')) &&
           (*(char *)((long)param_1 + 0x2e1) != '\0')) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x51d,
                       "pmaRegisterBlacklistInfo",1,
                       "NVRM: NUMA enabled - blacklisting page through kernel at address 0x%llx (GPA) 0x%llx (SPA)\n"
                       ,*param_3,param_1[0x5d] + *param_3);
          iVar5 = osOfflinePageAtAddress(param_1[0x5d] + *param_3);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/phys_mem_allocator_util.c",0x525
                         ,"pmaRegisterBlacklistInfo",4,
                         "NVRM: osOfflinePageAtAddress() failed with status: %d\n",iVar5);
          }
        }
        param_3 = param_3 + 2;
      } while (param_3 != puVar1);
      uVar4 = param_4 + *(int *)(param_1 + 0x61);
    }
    *(uint *)(param_1 + 0x61) = uVar4;
    return 0;
  }
  return 0;
}


// ===== 003ce490 pmaQueryBlacklistInfo =====

void pmaQueryBlacklistInfo(long param_1,undefined4 *param_2,undefined1 *param_3,undefined8 *param_4)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x308);
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = *(undefined1 *)(param_1 + 0x30c);
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = *(undefined8 *)(param_1 + 0x300);
  }
  return;
}


// ===== 003ce4c0 pmaIsBlacklistingAddrUnique =====

undefined8 pmaIsBlacklistingAddrUnique(long param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  
  if (*(uint *)(param_1 + 0x308) != 0) {
    plVar1 = *(long **)(param_1 + 0x300);
    plVar2 = plVar1 + (ulong)*(uint *)(param_1 + 0x308) * 2;
    do {
      if (*plVar1 == param_2) {
        return 0;
      }
      plVar1 = plVar1 + 2;
    } while (plVar1 != plVar2);
  }
  return 1;
}


// ===== 003ce500 _scanContiguousSearchLoopReverse =====

ulong _scanContiguousSearchLoopReverse
                (long param_1,long param_2,ulong param_3,long param_4,long param_5,long param_6,
                byte param_7)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong *puVar5;
  byte *pbVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong local_68 [7];
  ulong uVar14;
  
  uVar7 = param_6 + param_2 & param_5 - 1U;
  uVar1 = *(ulong *)(param_1 + 0x10);
  uVar11 = ((param_4 + 1) - uVar7 & -param_5) + uVar7;
  local_68[0] = uVar11;
  local_68[1] = uVar11;
  local_68[2] = uVar11;
  local_68[3] = uVar11;
  local_68[4] = uVar11;
  local_68[5] = uVar11;
  local_68[6] = uVar11;
  if (uVar11 < param_2 + param_3) {
    return 0xffffffffffffffff;
  }
  uVar15 = *(long *)(param_1 + 0x18) + uVar1;
  if (uVar11 < uVar15) {
    uVar15 = uVar11;
  }
  do {
    if (uVar11 < uVar15) {
      uVar15 = uVar11;
    }
    uVar4 = uVar11 - param_2;
    do {
      uVar16 = uVar15;
      if (uVar16 <= uVar4) {
LAB_003ce5c1:
        puVar5 = local_68;
        puVar8 = puVar5;
        do {
          uVar15 = *puVar8;
          if (uVar11 < *puVar8) {
            uVar15 = uVar11;
          }
          puVar9 = puVar8 + 1;
          *puVar8 = uVar15;
          puVar8 = puVar9;
        } while ((ulong *)&stack0xffffffffffffffd0 != puVar9);
        uVar11 = 0;
        do {
          while (((uVar11 & 0xfffffffffffffffb) == 0 && ((param_7 & 1) != 0))) {
            uVar11 = uVar11 + 1;
            puVar5 = puVar5 + 1;
          }
          uVar15 = *puVar5;
          if (uVar4 < uVar15) {
            lVar2 = *(long *)(param_1 + 0x28 + uVar11 * 8);
            do {
              while( true ) {
                uVar12 = uVar15 - 1 >> 6;
                uVar13 = (uint)(uVar15 - 1) & 0x3f;
                uVar14 = (ulong)uVar13;
                uVar10 = *(ulong *)(lVar2 + uVar12 * 8);
                if (uVar14 == 0x3f) break;
                uVar17 = uVar10 << (~(byte)uVar13 & 0x3f) |
                         0xffffffffffffffffU >> ((byte)uVar13 + 1 & 0x3f);
LAB_003ce65f:
                uVar3 = 0x3f;
                if (uVar17 != 0) {
                  for (; uVar17 >> uVar3 == 0; uVar3 = uVar3 - 1) {
                  }
                }
                if ((int)(uVar3 ^ 0x3f) == 0) {
                  if (uVar14 != 0x3f) {
                    uVar10 = -1L << ((char)uVar13 + 1U & 0x3f) | uVar10;
                  }
                  if (uVar10 == 0xffffffffffffffff) {
                    uVar11 = (uVar15 - uVar14) - 1;
                    if (uVar11 <= param_3) {
                      return 0xffffffffffffffff;
                    }
                    puVar5 = (ulong *)(lVar2 + -8 + uVar12 * 8);
                    while (uVar10 = *puVar5, uVar10 == 0xffffffffffffffff) {
                      uVar11 = uVar11 - 0x40;
                      puVar5 = puVar5 + -1;
                      if (uVar11 <= param_3) {
                        return 0xffffffffffffffff;
                      }
                    }
                  }
                  else {
                    uVar11 = (uVar15 - uVar14) + 0x3f;
                  }
                  lVar2 = 0x3f;
                  if (~uVar10 != 0) {
                    for (; ~uVar10 >> lVar2 == 0; lVar2 = lVar2 + -1) {
                    }
                  }
                  uVar11 = ((uVar11 - uVar7) - (ulong)((uint)lVar2 ^ 0x3f) & -param_5) + uVar7;
                  goto LAB_003ce754;
                }
                uVar15 = uVar15 - ((uVar3 ^ 0x3f) & 0xffffffff);
                *puVar5 = uVar15;
                if (uVar15 <= uVar4) goto LAB_003ce6b9;
              }
              if (uVar10 != 0) {
                uVar13 = 0x3f;
                uVar17 = uVar10;
                goto LAB_003ce65f;
              }
              uVar15 = uVar15 - 0x40;
              *puVar5 = uVar15;
            } while (uVar4 < uVar15);
          }
LAB_003ce6b9:
          uVar11 = uVar11 + 1;
          if (uVar11 == 7) {
            return uVar4;
          }
          puVar5 = puVar5 + 1;
        } while( true );
      }
      if (uVar16 <= uVar1) {
        uVar16 = 0;
        goto LAB_003ce5c1;
      }
      uVar10 = (uVar16 - uVar1) - 1 >> 10;
      uVar15 = uVar10 * 0x400 + uVar1;
    } while ((*(byte *)(*(long *)(param_1 + 0x60) + uVar10 * 4) & 1) == 0);
    if (uVar15 <= param_3) {
      return 0xffffffffffffffff;
    }
    pbVar6 = (byte *)(*(long *)(param_1 + 0x60) + -4 + uVar10 * 4);
    uVar11 = uVar15;
    while ((uVar1 < uVar11 && ((*pbVar6 & 1) != 0))) {
      uVar11 = uVar11 - 0x400;
      pbVar6 = pbVar6 + -4;
      if (uVar11 <= param_3) {
        return 0xffffffffffffffff;
      }
    }
LAB_003ce754:
    uVar15 = uVar16;
    if (uVar11 < param_2 + param_3) {
      return 0xffffffffffffffff;
    }
  } while( true );
}


// ===== 003ce840 _scanContiguousSearchLoop =====

ulong _scanContiguousSearchLoop
                (long param_1,ulong param_2,long param_3,ulong param_4,long param_5,long param_6,
                char param_7,uint param_8,byte param_9)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  byte *pbVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong *puVar10;
  ulong *puVar11;
  long lVar12;
  byte bVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong local_a0;
  ulong local_68 [7];
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  if (param_7 == '\0') {
    local_a0 = 0;
  }
  else {
    if (0x200 < param_2) {
      return 0x1f;
    }
    local_a0 = (ulong)((uint)uVar1 & 0x1ff);
  }
  uVar4 = ((param_5 - param_6) + -1 + param_3 & -param_5) + param_6;
  lVar2 = *(long *)(param_1 + 0x18);
  local_68[0] = uVar4;
  local_68[1] = uVar4;
  uVar15 = uVar4;
  if (uVar4 <= uVar1) {
    uVar15 = uVar1;
  }
  local_68[2] = uVar4;
  local_68[3] = uVar4;
  local_68[4] = uVar4;
  local_68[5] = uVar4;
  local_68[6] = uVar4;
  if (param_7 != '\0') goto LAB_003ceb03;
LAB_003ce949:
  do {
    uVar14 = param_2 + uVar4;
    if (param_4 < uVar14 - 1) {
      return 0xffffffffffffffff;
    }
    if (uVar15 < uVar4) {
      uVar15 = uVar4;
    }
    if (uVar14 <= uVar15) {
LAB_003ce9ba:
      do {
        puVar7 = local_68;
        puVar10 = puVar7;
        do {
          uVar16 = *puVar10;
          if (*puVar10 < uVar4) {
            uVar16 = uVar4;
          }
          puVar11 = puVar10 + 1;
          *puVar10 = uVar16;
          puVar10 = puVar11;
        } while ((ulong *)&stack0xffffffffffffffd0 != puVar11);
        uVar16 = 0;
        while( true ) {
          while (((uVar16 & 0xfffffffffffffffb) == 0 && ((param_9 & 1) != 0))) {
            uVar16 = uVar16 + 1;
            puVar7 = puVar7 + 1;
          }
          uVar9 = *puVar7;
          if (uVar9 < uVar14) break;
LAB_003cec20:
          uVar16 = uVar16 + 1;
          if (uVar16 == 7) {
            return uVar4;
          }
          puVar7 = puVar7 + 1;
        }
        lVar12 = *(long *)(param_1 + 0x28 + uVar16 * 8);
LAB_003cea78:
        uVar8 = *(ulong *)(lVar12 + (uVar9 >> 6) * 8);
        bVar13 = (byte)uVar9 & 0x3f;
        if ((uVar9 & 0x3f) == 0) {
          uVar5 = 0x40;
          if (uVar8 != 0) {
            bVar13 = 0;
            uVar3 = 0;
            for (uVar5 = uVar8; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x8000000000000000) {
              uVar3 = uVar3 + 1;
            }
            goto joined_r0x003cea65;
          }
LAB_003cea69:
          uVar9 = uVar9 + uVar5;
          *puVar7 = uVar9;
          if (uVar14 <= uVar9) goto LAB_003cec20;
          goto LAB_003cea78;
        }
        uVar3 = 0;
        for (uVar5 = -1L << (-bVar13 & 0x3f) | uVar8 >> bVar13; (uVar5 & 1) == 0;
            uVar5 = uVar5 >> 1 | 0x8000000000000000) {
          uVar3 = uVar3 + 1;
        }
joined_r0x003cea65:
        if (uVar3 != 0) {
          uVar5 = (ulong)uVar3;
          goto LAB_003cea69;
        }
        if ((uVar9 & 0x3f) != 0) {
          uVar8 = 0xffffffffffffffffU >> (-bVar13 & 0x3f) | uVar8;
        }
        uVar4 = uVar9 & 0xffffffffffffffc0;
        if (uVar8 == 0xffffffffffffffff) {
          uVar4 = uVar4 + 0x40;
          if (param_4 < uVar4) {
            return 0xffffffffffffffff;
          }
          puVar7 = (ulong *)(lVar12 + 8 + (uVar9 >> 6) * 8);
          while (uVar8 = *puVar7, uVar8 == 0xffffffffffffffff) {
            uVar4 = uVar4 + 0x40;
            puVar7 = puVar7 + 1;
            if (param_4 < uVar4) {
              return 0xffffffffffffffff;
            }
          }
        }
        uVar3 = 0;
        for (uVar8 = ~uVar8; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x8000000000000000) {
          uVar3 = uVar3 + 1;
        }
        uVar4 = ((ulong)uVar3 + (uVar4 - 1) + (param_5 - param_6) & -param_5) + param_6;
        if (param_7 == '\0') goto LAB_003ce949;
LAB_003ceb03:
        lVar12 = 0x200 - local_a0;
        if (((uint)(uVar4 - uVar1 >> 9) & 1) != param_8) {
          uVar4 = (uVar4 + lVar12 & 0xfffffffffffffe00) + local_a0;
        }
        uVar16 = uVar4 + lVar12 & 0xfffffffffffffe00;
        uVar14 = local_a0 + uVar16;
        if ((uVar14 < uVar4 + param_2) &&
           (uVar4 = local_a0 + 0x200 + uVar16, param_8 == ((uint)(uVar14 - uVar1 >> 9) & 1))) {
          uVar4 = uVar14;
        }
        if (uVar4 <= param_4) {
          do {
            pbVar6 = (byte *)(*(long *)(param_1 + 0x60) + (uVar4 - uVar1 >> 10) * 4);
            if (((*pbVar6 & 1) != 0) || (*(short *)(pbVar6 + 2) == 0)) break;
            uVar4 = (uVar4 + (0x400 - uVar1) & 0xfffffffffffffc00) + uVar1;
            if (param_8 != 0) {
              uVar4 = (uVar4 + lVar12 & 0xfffffffffffffe00) + local_a0;
            }
          } while (uVar4 <= param_4);
        }
        uVar14 = uVar4 + param_2;
        if (param_4 < uVar14 - 1) {
          return 0xffffffffffffffff;
        }
      } while( true );
    }
    uVar16 = uVar1 + lVar2;
LAB_003ce989:
    if (uVar16 <= uVar15) {
      uVar9 = param_4 + 1;
joined_r0x003ce9b8:
      uVar15 = uVar9;
      if (uVar14 <= uVar15) goto LAB_003ce9ba;
      goto LAB_003ce989;
    }
    uVar8 = uVar15 - uVar1 >> 10;
    uVar9 = (uVar8 + 1) * 0x400 + uVar1;
    if ((*(byte *)(*(long *)(param_1 + 0x60) + uVar8 * 4) & 1) == 0) goto joined_r0x003ce9b8;
    if (param_4 < uVar9) {
      return 0xffffffffffffffff;
    }
    pbVar6 = (byte *)(*(long *)(param_1 + 0x60) + 4 + uVar8 * 4);
    uVar4 = uVar9;
    while ((uVar4 < uVar16 && ((*pbVar6 & 1) != 0))) {
      uVar4 = uVar4 + 0x400;
      pbVar6 = pbVar6 + 4;
      if (param_4 < uVar4) {
        return 0xffffffffffffffff;
      }
    }
  } while( true );
}


// ===== 003cecc0 maxZerosGet =====

ulong maxZerosGet(ulong param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (param_1 == 0) {
    *param_2 = 0;
    return 0x40;
  }
  uVar5 = 0x3f;
  if (param_1 != 0) {
    for (; param_1 >> uVar5 == 0; uVar5 = uVar5 - 1) {
    }
  }
  uVar5 = uVar5 ^ 0x3f;
  param_1 = param_1 << ((byte)uVar5 & 0x3f);
  uVar8 = uVar5 & 0xffffffff;
  uVar3 = 0x40 - (int)uVar5;
  uVar7 = param_1 ^ 0xffffffffffffffff;
  if (uVar7 != 0) {
    uVar5 = uVar5 & 0xffffffff;
    while( true ) {
      uVar6 = (uint)uVar5;
      iVar2 = 0;
      for (; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x8000000000000000) {
        iVar2 = iVar2 + 1;
      }
      uVar4 = (int)uVar8 + iVar2;
      if (0x3f < uVar4) break;
      param_1 = param_1 >> ((byte)iVar2 & 0x3f);
      if (param_1 == 0) {
        *param_2 = uVar4;
        return 0x40;
      }
      uVar1 = 0;
      for (uVar7 = param_1; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x8000000000000000) {
        uVar1 = uVar1 + 1;
      }
      uVar8 = (ulong)(uVar4 + uVar1);
      if (uVar6 < uVar1) {
        uVar5 = (ulong)uVar1;
        uVar3 = uVar4;
      }
      uVar6 = (uint)uVar5;
      if (0x3f < uVar4 + uVar1) break;
      param_1 = param_1 >> ((byte)uVar1 & 0x3f);
      uVar7 = ~param_1;
    }
    uVar8 = (ulong)uVar6;
  }
  *param_2 = uVar3;
  return uVar8;
}


// ===== 003ced80 pmaRegMapScanContiguousNumaEviction =====

undefined8
pmaRegMapScanContiguousNumaEviction
          (long param_1,long param_2,ulong param_3,ulong param_4,long *param_5,long *param_6)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  byte bVar5;
  ulong uVar6;
  ulong uVar7;
  sbyte sVar8;
  byte bVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  uint uVar20;
  ulong uVar21;
  
  uVar6 = param_3 >> 0x10;
  uVar2 = *(ulong *)(param_1 + 8);
  if (uVar2 < uVar6) {
    return 0x51;
  }
  uVar11 = param_4 >> 0x10;
  uVar12 = -uVar11;
  uVar16 = (-param_4 & param_2 + -1 + param_4) - param_2 >> 0x10;
  uVar13 = (uVar11 - 1) - uVar16;
  uVar19 = (uVar13 & uVar12) + uVar16;
  do {
    while( true ) {
      while( true ) {
        if (uVar2 - uVar6 < uVar19) {
          return 0x51;
        }
        lVar10 = 0;
        uVar7 = uVar19 >> 6;
        uVar20 = (uint)uVar19 & 0x3f;
        uVar17 = 0;
        sVar8 = (sbyte)uVar20;
        do {
          lVar15 = lVar10 * 8;
          bVar9 = (byte)lVar10;
          lVar10 = lVar10 + 1;
          uVar17 = uVar17 | ((*(ulong *)(*(long *)(param_1 + 0x28 + lVar15) + uVar7 * 8) &
                             1L << sVar8) >> sVar8) << (bVar9 & 0x3f);
        } while (lVar10 != 7);
        lVar10 = 0;
        uVar14 = 0;
        uVar1 = (uVar6 - 1) + uVar19;
        bVar9 = (byte)uVar1 & 0x3f;
        uVar21 = uVar1 >> 6;
        do {
          lVar15 = lVar10 * 8;
          bVar5 = (byte)lVar10;
          lVar10 = lVar10 + 1;
          uVar14 = uVar14 | ((*(ulong *)(*(long *)(param_1 + 0x28 + lVar15) + uVar21 * 8) &
                             1L << bVar9) >> bVar9) << (bVar5 & 0x3f);
        } while (lVar10 != 7);
        if (((uint)uVar14 & 3) == 1) break;
        uVar19 = ((((uVar6 - 1) + uVar11) - uVar16) + uVar19 & uVar12) + uVar16;
      }
      if (((uint)uVar17 & 3) == 1) break;
      uVar19 = uVar19 + uVar11;
    }
    lVar10 = *(long *)(param_1 + 0x38);
    if (uVar7 <= uVar21) {
      uVar17 = uVar21;
LAB_003cefa7:
      uVar14 = 0xffffffffffffffff;
      if (uVar21 == uVar17) {
        uVar14 = 0xffffffffffffffff >> (~bVar9 & 0x3f);
      }
      if (uVar7 == uVar17) {
        uVar14 = uVar14 & -(1L << sVar8);
      }
      uVar3 = *(ulong *)(*(long *)(param_1 + 0x28) + uVar17 * 8);
      uVar18 = uVar3 & uVar14;
      if (uVar14 == uVar18) break;
      if (uVar18 == 0) {
        uVar14 = uVar17 * 0x40 + 0x3f;
        if (uVar21 == uVar17) {
          uVar14 = uVar1;
        }
      }
      else {
        lVar15 = 0xffffffff;
        uVar14 = ~uVar3 & uVar14;
        if ((uVar14 != 0) && (lVar15 = 0x3f, uVar14 != 0)) {
          for (; uVar14 >> lVar15 == 0; lVar15 = lVar15 + -1) {
          }
        }
        uVar14 = uVar17 * 0x40 + lVar15;
      }
      if (uVar14 != 0xffffffffffffffff) goto LAB_003ceff3;
LAB_003cf02e:
      if (*(long *)(param_1 + 0x68) == 0) goto LAB_003cf0f8;
      if (uVar21 <= uVar7) goto LAB_003cf0b6;
      uVar17 = uVar7 + 1;
      if (uVar17 <= uVar21 - 1) {
        do {
          uVar14 = *(ulong *)(lVar10 + uVar17 * 8);
          if (uVar14 != 0) {
            uVar20 = 0;
            for (; (uVar14 & 1) == 0; uVar14 = uVar14 >> 1 | 0x8000000000000000) {
              uVar20 = uVar20 + 1;
            }
            uVar14 = uVar17 * 0x40 + (ulong)uVar20;
            goto LAB_003ceff3;
          }
          uVar17 = uVar17 + 1;
        } while (uVar21 != uVar17);
      }
      uVar17 = 0xffffffffffffffffU >> (~bVar9 & 0x3f) & *(ulong *)(lVar10 + uVar21 * 8);
      if (uVar17 == 0) {
        uVar7 = -1L << sVar8 & *(ulong *)(lVar10 + uVar7 * 8);
        if (uVar7 == 0) goto LAB_003cf0f8;
        uVar4 = 0;
        for (; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x8000000000000000) {
          uVar4 = uVar4 + 1;
        }
        if ((ulong)uVar4 < (ulong)uVar20) {
          nvAssertFailedNoLog("(NvU64)firstSetBit >= startBitIdx",
                              "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0xb0);
        }
        uVar14 = (uVar19 & 0xffffffffffffffc0) + (ulong)uVar4;
        goto LAB_003ceff3;
      }
      uVar20 = 0;
      for (; (uVar17 & 1) == 0; uVar17 = uVar17 >> 1 | 0x8000000000000000) {
        uVar20 = uVar20 + 1;
      }
      uVar14 = (ulong)uVar20 + (uVar1 & 0xffffffffffffffc0);
      goto LAB_003cf0ee;
    }
    if (*(long *)(param_1 + 0x68) == 0) {
LAB_003cf0f8:
      param_2 = uVar19 * 0x10000 + param_2;
      lVar10 = param_2 + -1 + param_3;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x181,
                   "pmaRegMapScanContiguousNumaEviction",1,
                   "NVRM: Evictable frame = %lld evictstart = %llx evictEnd = %llx\n",uVar19,param_2
                   ,lVar10);
      *param_5 = param_2;
      *param_6 = lVar10;
      return 0;
    }
    nvAssertFailedNoLog("startMapIdx == endMapIdx",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0xbd);
LAB_003cf0b6:
    uVar7 = -1L << sVar8 & *(ulong *)(lVar10 + uVar7 * 8) & 0xffffffffffffffffU >> (~bVar9 & 0x3f);
    if (uVar7 == 0) goto LAB_003cf0f8;
    uVar20 = 0;
    for (; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x8000000000000000) {
      uVar20 = uVar20 + 1;
    }
    uVar14 = (uVar19 & 0xffffffffffffffc0) + (ulong)uVar20;
LAB_003cf0ee:
    if (uVar14 == 0xffffffffffffffff) goto LAB_003cf0f8;
LAB_003ceff3:
    uVar19 = (uVar13 + 1 + uVar14 & uVar12) + uVar16;
  } while( true );
  uVar17 = uVar17 - 1;
  if (uVar17 < uVar7) goto LAB_003cf02e;
  goto LAB_003cefa7;
}


// ===== 003cf1f0 pmaRegmapDestroy =====

void pmaRegmapDestroy(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)(param_1 + 0x28);
  do {
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    portMemFree(uVar2);
  } while ((undefined8 *)(param_1 + 0x60) != puVar5);
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 8);
  *plVar1 = *plVar1 - *(long *)(param_1 + 8);
  if (*(char *)(param_1 + 0x78) != '\0') {
    plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
    *plVar1 = *plVar1 - *(long *)(param_1 + 8);
  }
  uVar3 = *(ulong *)(param_1 + 8) >> 5;
  **(long **)(param_1 + 0x70) = **(long **)(param_1 + 0x70) - uVar3;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
  *plVar1 = *plVar1 - uVar3;
  if (*(char *)(param_1 + 0x78) != '\0') {
    plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x18);
    *plVar1 = *plVar1 - uVar3;
    plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
    *plVar1 = *plVar1 - uVar3;
  }
  uVar3 = *(ulong *)(param_1 + 0x18) >> 6;
  uVar4 = *(ulong *)(param_1 + 0x18) >> 1;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
  *plVar1 = *plVar1 - uVar4;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x30);
  *plVar1 = *plVar1 - uVar3;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
  *plVar1 = *plVar1 - uVar3;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
  *plVar1 = *plVar1 - uVar4;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x38);
  *plVar1 = *plVar1 - uVar3;
  plVar1 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
  *plVar1 = *plVar1 - uVar3;
  portMemFree(*(undefined8 *)(param_1 + 0x60));
  portMemFree(param_1);
  return;
}


// ===== 003cf2e0 pmaRegmapInit =====

long * pmaRegmapInit(ulong param_1,long param_2,long *param_3,char param_4)

{
  ulong *puVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  uint uVar8;
  
  plVar2 = (long *)portMemAllocNonPaged(0x80);
  if (plVar2 != (long *)0x0) {
    portMemSet(plVar2,0,0x80);
    *plVar2 = param_2;
    plVar2[1] = param_1;
    uVar3 = param_1 >> 5;
    param_3[1] = param_3[1] + param_1;
    *param_3 = *param_3 + uVar3;
    param_3[2] = param_3[2] + uVar3;
    if (param_4 != '\0') {
      lVar4 = plVar2[1];
      param_3[3] = param_3[3] + uVar3;
      param_3[4] = param_3[4] + lVar4;
      param_3[5] = param_3[5] + uVar3;
    }
    uVar3 = (param_2 + 0x3ffffffU & 0xfffffffffc000000) - param_2 >> 0x10;
    plVar2[2] = uVar3;
    uVar3 = ((param_1 * 0x10000 + param_2 & 0xfffffffffc000000) - param_2 >> 0x10) - uVar3;
    plVar2[3] = uVar3;
    uVar6 = uVar3 >> 6;
    param_3[6] = param_3[6] + uVar6;
    param_3[8] = param_3[8] + (uVar3 >> 1);
    param_3[10] = param_3[10] + uVar6;
    param_3[9] = param_3[9] + (uVar3 >> 1);
    param_3[7] = param_3[7] + uVar6;
    param_3[0xb] = param_3[0xb] + uVar6;
    *(char *)(plVar2 + 0xf) = param_4;
    plVar2[0xe] = (long)param_3;
    plVar7 = plVar2 + 5;
    uVar6 = param_1 - 1 >> 6;
    lVar4 = uVar6 + 1;
    plVar2[4] = lVar4;
    while( true ) {
      lVar4 = portMemAllocNonPaged(lVar4 << 3);
      *plVar7 = lVar4;
      if (lVar4 == 0) break;
      plVar7 = plVar7 + 1;
      portMemSet(lVar4,0,plVar2[4] * 8);
      if (plVar2 + 0xc == plVar7) {
        uVar8 = (uint)(param_1 - 1) & 0x3f;
        uVar5 = ~(0xffffffffffffffffU >> (~(byte)uVar8 & 0x3f));
        if (uVar8 == 0x3f) {
          uVar5 = 0;
        }
        puVar1 = (ulong *)(plVar2[6] + uVar6 * 8);
        *puVar1 = *puVar1 | uVar5;
        uVar3 = uVar3 >> 10;
        if (uVar3 == 0) {
          return plVar2;
        }
        lVar4 = portMemAllocNonPaged(uVar3 * 4);
        plVar2[0xc] = lVar4;
        if (lVar4 != 0) {
          portMemSet(lVar4,0,uVar3 * 4);
          return plVar2;
        }
        break;
      }
      lVar4 = plVar2[4];
    }
    pmaRegmapDestroy(plVar2);
  }
  return (long *)0x0;
}


// ===== 003cf4b0 pmaRegmapChangeBlockStateAttrib =====

void pmaRegmapChangeBlockStateAttrib
               (long param_1,ulong param_2,long param_3,uint param_4,uint param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  ushort uVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  ulong uVar13;
  ulong uVar14;
  ulong *puVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  ulong uVar23;
  short sVar24;
  ulong uVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  uint local_c0;
  uint local_b0;
  ulong local_90;
  byte local_80;
  uint local_78;
  uint local_68;
  uint local_60;
  ulong local_50;
  
  uVar18 = param_4 & param_5;
  lVar11 = *(long *)(param_1 + 0x10);
  uVar1 = *(ulong *)(param_1 + 0x18) >> 10;
  uVar25 = param_2 + param_3;
  local_50 = (param_2 - lVar11) + 0x400 >> 10;
  uVar2 = (uVar25 + 0x3ff) - lVar11 >> 10;
  uVar13 = param_2 >> 6;
  lVar17 = local_50 - 1;
  uVar10 = -1L << ((byte)param_2 & 0x3f);
  if (local_50 != uVar2) {
    local_90 = lVar11 + local_50 * 0x400;
    uVar6 = (uint)(local_90 - 1) & 0x3f;
    uVar23 = local_90 - 1 >> 6;
    uVar3 = 0xffffffffffffffff >> (~(byte)uVar6 & 0x3f);
    if (*(ulong *)(param_1 + 8) < local_90) {
      nvAssertFailedNoLog("frame + len <= pRegmap->totalFrames",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x302);
    }
    lVar5 = uVar13 * 8;
    plVar12 = (long *)(param_1 + 0x38);
    lVar7 = 2;
    uVar16 = 0;
    lVar8 = uVar23 * 8;
    do {
      if ((param_5 >> ((uint)lVar7 & 0x1f) & 1) != 0) {
        bVar26 = (param_4 & 1 << ((byte)lVar7 & 0x1f)) != 0;
        puVar15 = (ulong *)(*plVar12 + lVar5);
        if (uVar23 == uVar13) {
          *puVar15 = *puVar15 & ~(uVar10 & uVar3);
          uVar19 = uVar10 & uVar3;
          if (!bVar26) {
            uVar19 = uVar16;
          }
          *(ulong *)(*plVar12 + lVar5) = *(ulong *)(*plVar12 + lVar5) | uVar19;
        }
        else {
          *puVar15 = *puVar15 & ~uVar10;
          uVar19 = uVar10;
          if (!bVar26) {
            uVar19 = uVar16;
          }
          *(ulong *)(*plVar12 + lVar5) = *(ulong *)(*plVar12 + lVar5) | uVar19;
          if (uVar13 + 1 < uVar23) {
            lVar4 = lVar5 + 8;
            do {
              *(ulong *)(*plVar12 + lVar4) = -(ulong)bVar26;
              lVar4 = lVar4 + 8;
            } while (lVar8 - lVar4 != 0);
          }
          *(ulong *)(*plVar12 + lVar8) = *(ulong *)(*plVar12 + lVar8) & ~uVar3;
          uVar19 = uVar16;
          if (bVar26) {
            uVar19 = uVar3;
          }
          *(ulong *)(*plVar12 + lVar8) = *(ulong *)(*plVar12 + lVar8) | uVar19;
        }
      }
      lVar7 = lVar7 + 1;
      plVar12 = plVar12 + 1;
    } while (lVar7 != 7);
    local_b0 = param_5 & 3;
    if ((param_5 & 3) != 0) {
      if (uVar23 == uVar13) {
        puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar5);
        uVar13 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar5);
        uVar23 = *puVar15;
        uVar10 = uVar10 & uVar3;
        uVar16 = uVar23 | uVar13;
        uVar3 = 0;
        if ((param_4 & 2) != 0) {
          uVar3 = uVar10;
        }
        uVar19 = uVar10;
        if ((param_4 & 1) == 0) {
          uVar19 = 0;
        }
        if ((param_5 & 2) != 0) {
          uVar23 = uVar23 & ~uVar10 | uVar3;
        }
        *puVar15 = uVar23;
        if ((param_5 & 1) != 0) {
          uVar13 = ~uVar10 & uVar13 | uVar19;
        }
        uVar23 = uVar23 | uVar13;
        *(ulong *)(*(long *)(param_1 + 0x28) + lVar5) = uVar13;
        uVar10 = (uVar16 ^ uVar23) - ((uVar16 ^ uVar23) >> 1 & 0x5555555555555555);
        uVar10 = (uVar10 & 0x3333333333333333) + (uVar10 >> 2 & 0x3333333333333333);
        uVar19 = ((uVar10 >> 4) + uVar10 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
        uVar10 = (ulong)((uint)((uVar16 >> 0x20 == 0) != (uVar23 >> 0x20 == 0)) +
                        (uint)(((int)uVar23 == 0) != ((int)uVar16 == 0)));
      }
      else {
        if ((param_2 & 0x3f) == 0) {
          if (uVar6 != 0x3f) {
            uVar10 = 0;
            uVar19 = 0;
LAB_003cf705:
            local_78 = param_5 & 2;
            puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar8);
            uVar16 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar8);
            uVar14 = *puVar15;
            uVar21 = uVar14 | uVar16;
            uVar20 = 0;
            if ((param_4 & 2) != 0) {
              uVar20 = uVar3;
            }
            uVar22 = uVar3;
            if ((param_4 & 1) == 0) {
              uVar22 = 0;
            }
            if (local_78 != 0) {
              uVar14 = uVar14 & ~uVar3 | uVar20;
            }
            *puVar15 = uVar14;
            if ((param_5 & 1) != 0) {
              uVar16 = ~uVar3 & uVar16 | uVar22;
            }
            uVar14 = uVar14 | uVar16;
            *(ulong *)(*(long *)(param_1 + 0x28) + lVar8) = uVar16;
            uVar3 = (uVar21 ^ uVar14) - ((uVar21 ^ uVar14) >> 1 & 0x5555555555555555);
            uVar3 = (uVar3 & 0x3333333333333333) + (uVar3 >> 2 & 0x3333333333333333);
            uVar19 = ((uVar3 + (uVar3 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38) +
                     uVar19;
            uVar23 = uVar23 - 1;
            uVar10 = ((uint)((uVar21 >> 0x20 == 0) != (uVar14 >> 0x20 == 0)) +
                     (uint)(((int)uVar14 == 0) != ((int)uVar21 == 0))) + uVar10;
            goto LAB_003cf808;
          }
          uVar19 = 0;
          uVar10 = 0;
          if (uVar23 < uVar13) goto LAB_003cf984;
        }
        else {
          puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar5);
          uVar16 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar5);
          uVar14 = *puVar15;
          uVar20 = uVar14 | uVar16;
          uVar19 = uVar10;
          if ((param_4 & 2) == 0) {
            uVar19 = 0;
          }
          uVar21 = 0;
          if ((param_4 & 1) != 0) {
            uVar21 = uVar10;
          }
          if ((param_5 & 2) != 0) {
            uVar14 = uVar14 & ~uVar10 | uVar19;
          }
          *puVar15 = uVar14;
          if ((param_5 & 1) != 0) {
            uVar16 = uVar21 | ~uVar10 & uVar16;
          }
          uVar14 = uVar14 | uVar16;
          *(ulong *)(*(long *)(param_1 + 0x28) + lVar5) = uVar16;
          uVar10 = (uVar20 ^ uVar14) - ((uVar20 ^ uVar14) >> 1 & 0x5555555555555555);
          uVar10 = (uVar10 >> 2 & 0x3333333333333333) + (uVar10 & 0x3333333333333333);
          uVar19 = (uVar10 + (uVar10 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
          uVar13 = uVar13 + 1;
          uVar10 = (ulong)((uint)(((int)uVar14 == 0) != ((int)uVar20 == 0)) +
                          (uint)((uVar14 >> 0x20 == 0) != (uVar20 >> 0x20 == 0)));
          if (uVar6 != 0x3f) goto LAB_003cf705;
LAB_003cf808:
          if (uVar23 < uVar13) goto LAB_003cf924;
          lVar5 = uVar13 * 8;
        }
        while( true ) {
          uVar3 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar5);
          puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar5);
          uVar16 = *puVar15;
          uVar14 = uVar3 | uVar16;
          if ((param_5 & 2) != 0) {
            uVar16 = -(ulong)(param_4 >> 1 & 1);
          }
          if ((param_5 & 1) != 0) {
            uVar3 = -(ulong)(param_4 & 1);
          }
          *puVar15 = uVar16;
          uVar16 = uVar3 | uVar16;
          *(ulong *)(*(long *)(param_1 + 0x28) + lVar5) = uVar3;
          uVar3 = (uVar16 ^ uVar14) - ((uVar16 ^ uVar14) >> 1 & 0x5555555555555555);
          uVar3 = (uVar3 >> 2 & 0x3333333333333333) + (uVar3 & 0x3333333333333333);
          uVar19 = uVar19 + (((uVar3 >> 4) + uVar3 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38)
          ;
          uVar13 = uVar13 + 1;
          uVar10 = uVar10 + ((uint)((uVar14 >> 0x20 == 0) != (uVar16 >> 0x20 == 0)) +
                            (uint)(((int)uVar14 == 0) != ((int)uVar16 == 0)));
          if (uVar23 < uVar13) break;
          lVar5 = uVar13 * 8;
        }
      }
LAB_003cf924:
      if (uVar19 != 0) {
        if ((uVar18 & 3) == 0) {
          if (local_50 != 0) {
            lVar17 = *(long *)(param_1 + 0x60) + lVar17 * 4;
            uVar9 = *(ushort *)(lVar17 + 2);
            if (uVar19 == uVar9) {
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
              *plVar12 = *plVar12 + 0x200;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
              *plVar12 = *plVar12 + 0x10;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
              *plVar12 = *plVar12 + 0x200;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
              *plVar12 = *plVar12 + 0x10;
              uVar9 = *(ushort *)(lVar17 + 2);
            }
            *(ushort *)(lVar17 + 2) = uVar9 - (short)uVar19;
          }
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
          *plVar12 = *plVar12 + uVar19;
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
          *plVar12 = *plVar12 + uVar10;
          if (*(char *)(param_1 + 0x78) != '\0') {
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
            *plVar12 = *plVar12 + uVar19;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
            *plVar12 = *plVar12 + uVar10;
          }
        }
        else {
          if (local_50 != 0) {
            lVar17 = *(long *)(param_1 + 0x60) + lVar17 * 4;
            sVar24 = *(short *)(lVar17 + 2);
            if (sVar24 == 0) {
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
              *plVar12 = *plVar12 + -0x200;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
              *plVar12 = *plVar12 + -0x10;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
              *plVar12 = *plVar12 + -0x200;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
              *plVar12 = *plVar12 + -0x10;
              sVar24 = *(short *)(lVar17 + 2);
            }
            *(short *)(lVar17 + 2) = sVar24 + (short)uVar19;
          }
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
          *plVar12 = *plVar12 - uVar19;
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
          *plVar12 = *plVar12 - uVar10;
          if (*(char *)(param_1 + 0x78) != '\0') {
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
            *plVar12 = *plVar12 - uVar19;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
            *plVar12 = *plVar12 - uVar10;
          }
        }
      }
    }
LAB_003cf984:
    uVar2 = uVar2 - 1;
    uVar6 = (uint)(uVar25 - 1) & 0x3f;
    uVar13 = uVar2 * 0x400 + lVar11;
    uVar3 = uVar13 >> 6;
    uVar16 = uVar25 - 1 >> 6;
    uVar23 = -1L << ((byte)uVar13 & 0x3f);
    uVar10 = 0xffffffffffffffff >> (~(byte)uVar6 & 0x3f);
    if (*(ulong *)(param_1 + 8) < uVar25) {
      nvAssertFailedNoLog("frame + len <= pRegmap->totalFrames",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x302);
    }
    lVar11 = uVar3 * 8;
    plVar12 = (long *)(param_1 + 0x38);
    lVar8 = 2;
    uVar25 = 0;
    lVar17 = uVar16 * 8;
    do {
      if ((param_5 >> ((uint)lVar8 & 0x1f) & 1) != 0) {
        bVar26 = (param_4 & 1 << ((byte)lVar8 & 0x1f)) != 0;
        puVar15 = (ulong *)(*plVar12 + lVar11);
        if (uVar3 == uVar16) {
          *puVar15 = *puVar15 & ~(uVar23 & uVar10);
          uVar19 = uVar23 & uVar10;
          if (!bVar26) {
            uVar19 = uVar25;
          }
          *(ulong *)(*plVar12 + lVar11) = *(ulong *)(*plVar12 + lVar11) | uVar19;
        }
        else {
          *puVar15 = *puVar15 & ~uVar23;
          uVar19 = uVar23;
          if (!bVar26) {
            uVar19 = uVar25;
          }
          *(ulong *)(*plVar12 + lVar11) = *(ulong *)(*plVar12 + lVar11) | uVar19;
          if (uVar3 + 1 < uVar16) {
            lVar5 = lVar11 + 8;
            do {
              *(ulong *)(*plVar12 + lVar5) = -(ulong)bVar26;
              lVar5 = lVar5 + 8;
            } while (lVar17 - lVar5 != 0);
          }
          *(ulong *)(*plVar12 + lVar17) = *(ulong *)(*plVar12 + lVar17) & ~uVar10;
          uVar19 = uVar25;
          if (bVar26) {
            uVar19 = uVar10;
          }
          *(ulong *)(*plVar12 + lVar17) = *(ulong *)(*plVar12 + lVar17) | uVar19;
        }
      }
      lVar8 = lVar8 + 1;
      plVar12 = plVar12 + 1;
    } while (lVar8 != 7);
    if (local_b0 == 0) goto LAB_003cfdbe;
    if (uVar3 == uVar16) {
      puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar11);
      uVar25 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar11);
      uVar13 = *puVar15;
      uVar23 = uVar23 & uVar10;
      uVar3 = uVar13 | uVar25;
      uVar10 = 0;
      if ((param_4 & 2) != 0) {
        uVar10 = uVar23;
      }
      uVar16 = uVar23;
      if ((param_4 & 1) == 0) {
        uVar16 = 0;
      }
      if ((param_5 & 2) != 0) {
        uVar13 = uVar13 & ~uVar23 | uVar10;
      }
      *puVar15 = uVar13;
      if ((param_5 & 1) != 0) {
        uVar25 = ~uVar23 & uVar25 | uVar16;
      }
      uVar13 = uVar13 | uVar25;
      *(ulong *)(*(long *)(param_1 + 0x28) + lVar11) = uVar25;
      uVar25 = (uVar3 ^ uVar13) - ((uVar3 ^ uVar13) >> 1 & 0x5555555555555555);
      uVar25 = (uVar25 & 0x3333333333333333) + (uVar25 >> 2 & 0x3333333333333333);
      uVar25 = ((uVar25 >> 4) + uVar25 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
      uVar13 = (ulong)((uint)(((int)uVar13 == 0) != ((int)uVar3 == 0)) +
                      (uint)((uVar13 >> 0x20 == 0) != (uVar3 >> 0x20 == 0)));
    }
    else {
      if ((uVar13 & 0x3f) == 0) {
        if (uVar6 != 0x3f) {
          uVar13 = 0;
          uVar25 = 0;
LAB_003cfb42:
          local_68 = param_5 & 2;
          local_60 = param_4 & 1;
          puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar17);
          uVar23 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar17);
          uVar19 = *puVar15;
          uVar20 = uVar19 | uVar23;
          uVar14 = 0;
          if ((param_4 & 2) != 0) {
            uVar14 = uVar10;
          }
          uVar21 = uVar10;
          if (local_60 == 0) {
            uVar21 = 0;
          }
          if (local_68 != 0) {
            uVar19 = uVar19 & ~uVar10 | uVar14;
          }
          *puVar15 = uVar19;
          if ((param_5 & 1) != 0) {
            uVar23 = ~uVar10 & uVar23 | uVar21;
          }
          uVar19 = uVar19 | uVar23;
          *(ulong *)(*(long *)(param_1 + 0x28) + lVar17) = uVar23;
          uVar10 = (uVar20 ^ uVar19) - ((uVar20 ^ uVar19) >> 1 & 0x5555555555555555);
          uVar10 = (uVar10 & 0x3333333333333333) + (uVar10 >> 2 & 0x3333333333333333);
          uVar25 = uVar25 + ((uVar10 + (uVar10 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >>
                            0x38);
          uVar16 = uVar16 - 1;
          uVar13 = uVar13 + ((uint)((uVar20 >> 0x20 == 0) != (uVar19 >> 0x20 == 0)) +
                            (uint)(((int)uVar19 == 0) != ((int)uVar20 == 0)));
          goto LAB_003cfc41;
        }
        uVar13 = 0;
        uVar25 = 0;
        if (uVar16 < uVar3) goto LAB_003cfdbe;
      }
      else {
        puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar11);
        uVar25 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar11);
        uVar13 = *puVar15;
        uVar14 = uVar13 | uVar25;
        uVar19 = uVar23;
        if ((param_4 & 2) == 0) {
          uVar19 = 0;
        }
        uVar20 = 0;
        if ((param_4 & 1) != 0) {
          uVar20 = uVar23;
        }
        if ((param_5 & 2) != 0) {
          uVar13 = uVar13 & ~uVar23 | uVar19;
        }
        *puVar15 = uVar13;
        if ((param_5 & 1) != 0) {
          uVar25 = uVar20 | ~uVar23 & uVar25;
        }
        uVar13 = uVar13 | uVar25;
        *(ulong *)(*(long *)(param_1 + 0x28) + lVar11) = uVar25;
        uVar25 = (uVar14 ^ uVar13) - ((uVar14 ^ uVar13) >> 1 & 0x5555555555555555);
        uVar25 = (uVar25 >> 2 & 0x3333333333333333) + (uVar25 & 0x3333333333333333);
        uVar25 = (uVar25 + (uVar25 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
        uVar3 = uVar3 + 1;
        uVar13 = (ulong)((uint)(((int)uVar13 == 0) != ((int)uVar14 == 0)) +
                        (uint)((uVar13 >> 0x20 == 0) != (uVar14 >> 0x20 == 0)));
        if (uVar6 != 0x3f) goto LAB_003cfb42;
LAB_003cfc41:
        if (uVar16 < uVar3) goto LAB_003cfd5c;
        lVar11 = uVar3 * 8;
      }
      while( true ) {
        uVar10 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar11);
        puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar11);
        uVar23 = *puVar15;
        uVar19 = uVar10 | uVar23;
        if ((param_5 & 2) != 0) {
          uVar23 = -(ulong)(param_4 >> 1 & 1);
        }
        if ((param_5 & 1) != 0) {
          uVar10 = -(ulong)(param_4 & 1);
        }
        *puVar15 = uVar23;
        uVar23 = uVar10 | uVar23;
        *(ulong *)(*(long *)(param_1 + 0x28) + lVar11) = uVar10;
        uVar10 = (uVar23 ^ uVar19) - ((uVar23 ^ uVar19) >> 1 & 0x5555555555555555);
        uVar10 = (uVar10 >> 2 & 0x3333333333333333) + (uVar10 & 0x3333333333333333);
        uVar25 = uVar25 + (((uVar10 >> 4) + uVar10 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38)
        ;
        uVar3 = uVar3 + 1;
        uVar13 = uVar13 + ((uint)((uVar19 >> 0x20 == 0) != (uVar23 >> 0x20 == 0)) +
                          (uint)(((int)uVar19 == 0) != ((int)uVar23 == 0)));
        if (uVar16 < uVar3) break;
        lVar11 = uVar3 * 8;
      }
    }
LAB_003cfd5c:
    if (uVar25 != 0) {
      if ((uVar18 & 3) == 0) {
        if (uVar2 < uVar1) {
          lVar17 = *(long *)(param_1 + 0x60) + uVar2 * 4;
          uVar9 = *(ushort *)(lVar17 + 2);
          if (uVar25 == uVar9) {
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
            *plVar12 = *plVar12 + 0x200;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
            *plVar12 = *plVar12 + 0x10;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
            *plVar12 = *plVar12 + 0x200;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
            *plVar12 = *plVar12 + 0x10;
            uVar9 = *(ushort *)(lVar17 + 2);
          }
          *(ushort *)(lVar17 + 2) = uVar9 - (short)uVar25;
        }
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
        *plVar12 = *plVar12 + uVar25;
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
        *plVar12 = *plVar12 + uVar13;
        if (*(char *)(param_1 + 0x78) != '\0') {
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
          *plVar12 = *plVar12 + uVar25;
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
          *plVar12 = *plVar12 + uVar13;
        }
      }
      else {
        if (uVar2 < uVar1) {
          lVar17 = *(long *)(param_1 + 0x60) + uVar2 * 4;
          sVar24 = *(short *)(lVar17 + 2);
          if (sVar24 == 0) {
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
            *plVar12 = *plVar12 + -0x200;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
            *plVar12 = *plVar12 + -0x10;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
            *plVar12 = *plVar12 + -0x200;
            plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
            *plVar12 = *plVar12 + -0x10;
            sVar24 = *(short *)(lVar17 + 2);
          }
          *(short *)(lVar17 + 2) = sVar24 + (short)uVar25;
        }
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
        *plVar12 = *plVar12 - uVar25;
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
        *plVar12 = *plVar12 - uVar13;
        if (*(char *)(param_1 + 0x78) != '\0') {
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
          *plVar12 = *plVar12 - uVar25;
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
          *plVar12 = *plVar12 - uVar13;
        }
      }
    }
LAB_003cfdbe:
    if (local_50 < uVar2) {
      local_c0 = param_4 & 2;
      do {
        uVar6 = (int)local_90 + 0x3ffU & 0x3f;
        uVar10 = -1L << ((byte)local_90 & 0x3f);
        uVar1 = local_90 >> 6;
        uVar13 = local_90 + 0x3ff >> 6;
        uVar25 = 0xffffffffffffffff >> (~(byte)uVar6 & 0x3f);
        if (*(ulong *)(param_1 + 8) < local_90 + 0x400) {
          nvAssertFailedNoLog("frame + len <= pRegmap->totalFrames",
                              "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x302);
        }
        plVar12 = (long *)(param_1 + 0x38);
        uVar3 = 0;
        lVar17 = uVar1 * 8;
        lVar11 = uVar13 * 8;
        lVar8 = 2;
        do {
          if ((param_5 >> ((uint)lVar8 & 0x1f) & 1) != 0) {
            bVar26 = (param_4 & 1 << ((byte)lVar8 & 0x1f)) != 0;
            puVar15 = (ulong *)(*plVar12 + lVar17);
            if (uVar1 == uVar13) {
              *puVar15 = *puVar15 & ~(uVar10 & uVar25);
              uVar23 = uVar10 & uVar25;
              if (!bVar26) {
                uVar23 = uVar3;
              }
              *(ulong *)(*plVar12 + lVar17) = *(ulong *)(*plVar12 + lVar17) | uVar23;
            }
            else {
              *puVar15 = *puVar15 & ~uVar10;
              uVar23 = uVar3;
              if (bVar26) {
                uVar23 = uVar10;
              }
              *(ulong *)(*plVar12 + lVar17) = *(ulong *)(*plVar12 + lVar17) | uVar23;
              if (uVar1 + 1 < uVar13) {
                lVar5 = lVar17 + 8;
                do {
                  *(ulong *)(*plVar12 + lVar5) = -(ulong)bVar26;
                  lVar5 = lVar5 + 8;
                } while (lVar5 != lVar11);
              }
              *(ulong *)(*plVar12 + lVar11) = *(ulong *)(*plVar12 + lVar11) & ~uVar25;
              uVar23 = uVar3;
              if (bVar26) {
                uVar23 = uVar25;
              }
              *(ulong *)(*plVar12 + lVar11) = *(ulong *)(*plVar12 + lVar11) | uVar23;
            }
          }
          lVar8 = lVar8 + 1;
          plVar12 = plVar12 + 1;
        } while (lVar8 != 7);
        if (local_b0 != 0) {
          if (uVar1 == uVar13) {
            uVar10 = uVar10 & uVar25;
            puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar17);
            uVar25 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar17);
            uVar1 = *puVar15;
            uVar3 = uVar1 | uVar25;
            uVar13 = 0;
            if (local_c0 != 0) {
              uVar13 = uVar10;
            }
            uVar23 = uVar10;
            if ((param_4 & 1) == 0) {
              uVar23 = 0;
            }
            if ((param_5 & 2) != 0) {
              uVar1 = uVar1 & ~uVar10 | uVar13;
            }
            if ((param_5 & 1) != 0) {
              uVar25 = ~uVar10 & uVar25 | uVar23;
            }
            *puVar15 = uVar1;
            uVar1 = uVar1 | uVar25;
            *(ulong *)(*(long *)(param_1 + 0x28) + lVar17) = uVar25;
            uVar25 = (uVar3 ^ uVar1) - ((uVar3 ^ uVar1) >> 1 & 0x5555555555555555);
            uVar25 = (uVar25 & 0x3333333333333333) + (uVar25 >> 2 & 0x3333333333333333);
            uVar23 = ((uVar25 >> 4) + uVar25 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
            uVar10 = (ulong)((uint)((uVar3 >> 0x20 == 0) != (uVar1 >> 0x20 == 0)) +
                            (uint)(((int)uVar1 == 0) != ((int)uVar3 == 0)));
          }
          else {
            if ((local_90 & 0x3f) == 0) {
              if (uVar13 < uVar1) goto LAB_003d0150;
              uVar23 = 0;
              uVar10 = 0;
            }
            else {
              puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar17);
              uVar3 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar17);
              uVar16 = *puVar15;
              uVar19 = uVar16 | uVar3;
              uVar23 = 0;
              if (local_c0 != 0) {
                uVar23 = uVar10;
              }
              uVar14 = ~uVar10;
              if ((param_4 & 1) == 0) {
                uVar10 = 0;
              }
              if ((param_5 & 2) != 0) {
                uVar16 = uVar23 | uVar16 & uVar14;
              }
              if ((param_5 & 1) != 0) {
                uVar3 = uVar14 & uVar3 | uVar10;
              }
              *puVar15 = uVar16;
              uVar16 = uVar16 | uVar3;
              *(ulong *)(*(long *)(param_1 + 0x28) + lVar17) = uVar3;
              uVar10 = (uVar19 ^ uVar16) - ((uVar19 ^ uVar16) >> 1 & 0x5555555555555555);
              uVar10 = (uVar10 & 0x3333333333333333) + (uVar10 >> 2 & 0x3333333333333333);
              uVar23 = ((uVar10 >> 4) + uVar10 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
              uVar1 = uVar1 + 1;
              uVar10 = (ulong)((uint)((uVar19 >> 0x20 == 0) != (uVar16 >> 0x20 == 0)) +
                              (uint)(((int)uVar16 == 0) != ((int)uVar19 == 0)));
              if (uVar6 != 0x3f) {
                puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar11);
                uVar3 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar11);
                uVar16 = *puVar15;
                uVar14 = uVar16 | uVar3;
                uVar19 = 0;
                if (local_c0 != 0) {
                  uVar19 = uVar25;
                }
                uVar20 = uVar25;
                if ((param_4 & 1) == 0) {
                  uVar20 = 0;
                }
                if ((param_5 & 2) != 0) {
                  uVar16 = uVar16 & ~uVar25 | uVar19;
                }
                if ((param_5 & 1) != 0) {
                  uVar3 = ~uVar25 & uVar3 | uVar20;
                }
                *puVar15 = uVar16;
                uVar16 = uVar16 | uVar3;
                *(ulong *)(*(long *)(param_1 + 0x28) + lVar11) = uVar3;
                uVar25 = (uVar14 ^ uVar16) - ((uVar14 ^ uVar16) >> 1 & 0x5555555555555555);
                uVar25 = (uVar25 & 0x3333333333333333) + (uVar25 >> 2 & 0x3333333333333333);
                uVar23 = uVar23 + (((uVar25 >> 4) + uVar25 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101
                                  >> 0x38);
                uVar13 = uVar13 - 1;
                uVar10 = uVar10 + ((uint)((uVar14 >> 0x20 == 0) != (uVar16 >> 0x20 == 0)) +
                                  (uint)(((int)uVar16 == 0) != ((int)uVar14 == 0)));
              }
              if (uVar13 < uVar1) goto LAB_003d00b3;
              lVar17 = uVar1 * 8;
            }
            while( true ) {
              uVar25 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar17);
              puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar17);
              uVar3 = *puVar15;
              uVar16 = uVar25 | uVar3;
              if ((param_5 & 2) != 0) {
                uVar3 = -(ulong)((param_4 & 2) != 0);
              }
              if ((param_5 & 1) != 0) {
                uVar25 = -(ulong)(param_4 & 1);
              }
              *puVar15 = uVar3;
              uVar3 = uVar25 | uVar3;
              *(ulong *)(*(long *)(param_1 + 0x28) + lVar17) = uVar25;
              uVar25 = (uVar3 ^ uVar16) - ((uVar3 ^ uVar16) >> 1 & 0x5555555555555555);
              uVar25 = (uVar25 >> 2 & 0x3333333333333333) + (uVar25 & 0x3333333333333333);
              uVar23 = uVar23 + ((uVar25 + (uVar25 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >>
                                0x38);
              uVar1 = uVar1 + 1;
              uVar10 = uVar10 + ((uint)((uVar16 >> 0x20 == 0) != (uVar3 >> 0x20 == 0)) +
                                (uint)(((int)uVar16 == 0) != ((int)uVar3 == 0)));
              if (uVar13 < uVar1) break;
              lVar17 = uVar1 * 8;
            }
          }
LAB_003d00b3:
          if (uVar23 != 0) {
            lVar17 = *(long *)(param_1 + 0x60) + local_50 * 4;
            uVar9 = *(ushort *)(lVar17 + 2);
            if ((uVar18 & 3) == 0) {
              if (uVar23 == uVar9) {
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
                *plVar12 = *plVar12 + 0x200;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
                *plVar12 = *plVar12 + 0x10;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
                *plVar12 = *plVar12 + 0x200;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
                *plVar12 = *plVar12 + 0x10;
                uVar9 = *(ushort *)(lVar17 + 2);
              }
              *(ushort *)(lVar17 + 2) = uVar9 - (short)uVar23;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
              *plVar12 = *plVar12 + uVar23;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
              *plVar12 = *plVar12 + uVar10;
              if (*(char *)(param_1 + 0x78) != '\0') {
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
                *plVar12 = *plVar12 + uVar23;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
                *plVar12 = *plVar12 + uVar10;
              }
            }
            else {
              if (uVar9 == 0) {
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
                *plVar12 = *plVar12 + -0x200;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
                *plVar12 = *plVar12 + -0x10;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
                *plVar12 = *plVar12 + -0x200;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
                *plVar12 = *plVar12 + -0x10;
                uVar9 = *(ushort *)(lVar17 + 2);
              }
              *(ushort *)(lVar17 + 2) = uVar9 + (short)uVar23;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
              *plVar12 = *plVar12 - uVar23;
              plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
              *plVar12 = *plVar12 - uVar10;
              if (*(char *)(param_1 + 0x78) != '\0') {
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
                *plVar12 = *plVar12 - uVar23;
                plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
                *plVar12 = *plVar12 - uVar10;
              }
            }
          }
        }
LAB_003d0150:
        local_50 = local_50 + 1;
        local_90 = local_90 + 0x400;
      } while (uVar2 != local_50);
    }
    return;
  }
  bVar27 = local_50 != 0;
  bVar26 = local_50 <= uVar1;
  if (bVar27 && bVar26) {
    uVar9 = *(ushort *)(*(long *)(param_1 + 0x60) + lVar17 * 4);
    uVar1 = 0;
    if ((uVar9 & 1) != 0) {
      uVar1 = (ulong)((uint)(param_2 - lVar11 >> 9) & 1);
    }
    local_80 = (byte)uVar9 & 1;
  }
  else {
    local_80 = 0;
    uVar1 = 0;
  }
  uVar6 = (uint)(uVar25 - 1) & 0x3f;
  uVar3 = uVar25 - 1 >> 6;
  uVar2 = 0xffffffffffffffff >> (~(byte)uVar6 & 0x3f);
  if (*(ulong *)(param_1 + 8) < uVar25) {
    nvAssertFailedNoLog("frame + len <= pRegmap->totalFrames",
                        "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x302);
  }
  lVar8 = uVar13 * 8;
  plVar12 = (long *)(param_1 + 0x38);
  lVar5 = 2;
  uVar25 = 0;
  lVar11 = uVar3 * 8;
  do {
    if ((param_5 >> ((uint)lVar5 & 0x1f) & 1) != 0) {
      bVar28 = (param_4 & 1 << ((byte)lVar5 & 0x1f)) != 0;
      puVar15 = (ulong *)(*plVar12 + lVar8);
      if (uVar3 == uVar13) {
        *puVar15 = *puVar15 & ~(uVar10 & uVar2);
        uVar23 = uVar10 & uVar2;
        if (!bVar28) {
          uVar23 = uVar25;
        }
        *(ulong *)(*plVar12 + lVar8) = *(ulong *)(*plVar12 + lVar8) | uVar23;
      }
      else {
        *puVar15 = *puVar15 & ~uVar10;
        uVar23 = uVar10;
        if (!bVar28) {
          uVar23 = uVar25;
        }
        *(ulong *)(*plVar12 + lVar8) = *(ulong *)(*plVar12 + lVar8) | uVar23;
        if (uVar13 + 1 < uVar3) {
          lVar7 = lVar8 + 8;
          do {
            *(ulong *)(*plVar12 + lVar7) = -(ulong)bVar28;
            lVar7 = lVar7 + 8;
          } while (lVar11 - lVar7 != 0);
        }
        *(ulong *)(*plVar12 + lVar11) = *(ulong *)(*plVar12 + lVar11) & ~uVar2;
        uVar23 = uVar25;
        if (bVar28) {
          uVar23 = uVar2;
        }
        *(ulong *)(*plVar12 + lVar11) = *(ulong *)(*plVar12 + lVar11) | uVar23;
      }
    }
    lVar5 = lVar5 + 1;
    plVar12 = plVar12 + 1;
  } while (lVar5 != 7);
  if ((param_5 & 3) == 0) {
    return;
  }
  if (uVar3 == uVar13) {
    puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar8);
    uVar25 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar8);
    uVar13 = *puVar15;
    uVar10 = uVar10 & uVar2;
    uVar3 = uVar13 | uVar25;
    uVar2 = 0;
    if ((param_4 & 2) != 0) {
      uVar2 = uVar10;
    }
    uVar23 = uVar10;
    if ((param_4 & 1) == 0) {
      uVar23 = 0;
    }
    if ((param_5 & 2) != 0) {
      uVar13 = uVar13 & ~uVar10 | uVar2;
    }
    if ((param_5 & 1) != 0) {
      uVar25 = uVar23 | ~uVar10 & uVar25;
    }
    *puVar15 = uVar13;
    uVar13 = uVar13 | uVar25;
    *(ulong *)(*(long *)(param_1 + 0x28) + lVar8) = uVar25;
    uVar25 = (uVar3 ^ uVar13) - ((uVar3 ^ uVar13) >> 1 & 0x5555555555555555);
    uVar25 = (uVar25 & 0x3333333333333333) + (uVar25 >> 2 & 0x3333333333333333);
    uVar25 = ((uVar25 >> 4) + uVar25 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
    uVar10 = (ulong)((uint)((uVar13 >> 0x20 == 0) != (uVar3 >> 0x20 == 0)) +
                    (uint)(((int)uVar13 == 0) != ((int)uVar3 == 0)));
  }
  else {
    if ((param_2 & 0x3f) == 0) {
      if (uVar6 != 0x3f) {
        uVar10 = 0;
        uVar25 = 0;
LAB_003d0793:
        puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar11);
        uVar23 = *puVar15;
        uVar16 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar11);
        uVar14 = uVar23 | uVar16;
        uVar19 = 0;
        if ((param_4 & 2) != 0) {
          uVar19 = uVar2;
        }
        uVar20 = uVar2;
        if ((param_4 & 1) == 0) {
          uVar20 = 0;
        }
        if ((param_5 & 2) != 0) {
          uVar23 = uVar23 & ~uVar2 | uVar19;
        }
        *puVar15 = uVar23;
        if ((param_5 & 1) != 0) {
          uVar16 = ~uVar2 & uVar16 | uVar20;
        }
        uVar23 = uVar23 | uVar16;
        *(ulong *)(*(long *)(param_1 + 0x28) + lVar11) = uVar16;
        uVar2 = (uVar14 ^ uVar23) - ((uVar14 ^ uVar23) >> 1 & 0x5555555555555555);
        uVar2 = (uVar2 >> 2 & 0x3333333333333333) + (uVar2 & 0x3333333333333333);
        uVar25 = uVar25 + ((uVar2 + (uVar2 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38);
        uVar3 = uVar3 - 1;
        uVar10 = uVar10 + ((uint)((uVar14 >> 0x20 == 0) != (uVar23 >> 0x20 == 0)) +
                          (uint)(((int)uVar23 == 0) != ((int)uVar14 == 0)));
        goto LAB_003d089c;
      }
      uVar10 = 0;
      uVar25 = 0;
      if (uVar3 < uVar13) {
        return;
      }
    }
    else {
      puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar8);
      uVar25 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar8);
      uVar23 = *puVar15;
      uVar19 = uVar23 | uVar25;
      uVar16 = uVar10;
      if ((param_4 & 2) == 0) {
        uVar16 = 0;
      }
      uVar14 = 0;
      if ((param_4 & 1) != 0) {
        uVar14 = uVar10;
      }
      if ((param_5 & 2) != 0) {
        uVar23 = uVar23 & ~uVar10 | uVar16;
      }
      if ((param_5 & 1) != 0) {
        uVar25 = ~uVar10 & uVar25 | uVar14;
      }
      *puVar15 = uVar23;
      uVar23 = uVar23 | uVar25;
      *(ulong *)(*(long *)(param_1 + 0x28) + lVar8) = uVar25;
      uVar25 = (uVar19 ^ uVar23) - ((uVar19 ^ uVar23) >> 1 & 0x5555555555555555);
      uVar25 = (uVar25 >> 2 & 0x3333333333333333) + (uVar25 & 0x3333333333333333);
      uVar25 = (uVar25 + (uVar25 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
      uVar13 = uVar13 + 1;
      uVar10 = (ulong)((uint)(((int)uVar23 == 0) != ((int)uVar19 == 0)) +
                      (uint)((uVar23 >> 0x20 == 0) != (uVar19 >> 0x20 == 0)));
      if (uVar6 != 0x3f) goto LAB_003d0793;
LAB_003d089c:
      if (uVar3 < uVar13) goto LAB_003d09c0;
      lVar8 = uVar13 * 8;
    }
    while( true ) {
      uVar2 = *(ulong *)(*(long *)(param_1 + 0x28) + lVar8);
      puVar15 = (ulong *)(*(long *)(param_1 + 0x30) + lVar8);
      uVar23 = *puVar15;
      uVar16 = uVar2 | uVar23;
      if ((param_5 & 2) != 0) {
        uVar23 = -(ulong)(param_4 >> 1 & 1);
      }
      if ((param_5 & 1) != 0) {
        uVar2 = -(ulong)(param_4 & 1);
      }
      *puVar15 = uVar23;
      uVar23 = uVar2 | uVar23;
      *(ulong *)(*(long *)(param_1 + 0x28) + lVar8) = uVar2;
      uVar2 = (uVar23 ^ uVar16) - ((uVar23 ^ uVar16) >> 1 & 0x5555555555555555);
      uVar2 = (uVar2 >> 2 & 0x3333333333333333) + (uVar2 & 0x3333333333333333);
      uVar25 = uVar25 + (((uVar2 >> 4) + uVar2 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38);
      uVar13 = uVar13 + 1;
      uVar10 = uVar10 + ((uint)((uVar23 >> 0x20 == 0) != (uVar16 >> 0x20 == 0)) +
                        (uint)(((int)uVar16 == 0) != ((int)uVar23 == 0)));
      if (uVar3 < uVar13) break;
      lVar8 = uVar13 * 8;
    }
  }
LAB_003d09c0:
  if (uVar25 == 0) {
    return;
  }
  sVar24 = (short)uVar25;
  if ((uVar18 & 3) == 0) {
    if (bVar27 && bVar26) {
      lVar17 = *(long *)(param_1 + 0x60) + lVar17 * 4;
      if (uVar25 == *(ushort *)(lVar17 + 2)) {
        if (local_80 != 0) {
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
          *plVar12 = *plVar12 + 0x400;
          plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
          *plVar12 = *plVar12 + 0x20;
          *(short *)(lVar17 + 2) = *(short *)(lVar17 + 2) - sVar24;
          goto LAB_003d138d;
        }
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
        *plVar12 = *plVar12 + 0x200;
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
        *plVar12 = *plVar12 + 0x10;
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
        *plVar12 = *plVar12 + 0x200;
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
        *plVar12 = *plVar12 + 0x10;
        *(short *)(lVar17 + 2) = *(short *)(lVar17 + 2) - sVar24;
        goto LAB_003d117d;
      }
      *(ushort *)(lVar17 + 2) = *(ushort *)(lVar17 + 2) - sVar24;
    }
    if (local_80 != 0) {
LAB_003d138d:
      plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40 + uVar1 * 8);
      *plVar12 = *plVar12 + uVar25;
      plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50 + uVar1 * 8);
      *plVar12 = *plVar12 + uVar10;
      return;
    }
LAB_003d117d:
    plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
    *plVar12 = *plVar12 + uVar25;
    plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
    *plVar12 = *plVar12 + uVar10;
    if (*(char *)(param_1 + 0x78) == '\0') {
      return;
    }
    plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
    *plVar12 = *plVar12 + uVar25;
    plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
    *plVar12 = *plVar12 + uVar10;
    return;
  }
  if (bVar27 && bVar26) {
    lVar17 = *(long *)(param_1 + 0x60) + lVar17 * 4;
    if (*(short *)(lVar17 + 2) == 0) {
      if (local_80 != 0) {
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
        *plVar12 = *plVar12 + -0x400;
        plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
        *plVar12 = *plVar12 + -0x20;
        *(short *)(lVar17 + 2) = *(short *)(lVar17 + 2) + sVar24;
        goto LAB_003d112d;
      }
      plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40);
      *plVar12 = *plVar12 + -0x200;
      plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50);
      *plVar12 = *plVar12 + -0x10;
      plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x48);
      *plVar12 = *plVar12 + -0x200;
      plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x58);
      *plVar12 = *plVar12 + -0x10;
      *(short *)(lVar17 + 2) = *(short *)(lVar17 + 2) + sVar24;
      goto LAB_003d0a35;
    }
    *(short *)(lVar17 + 2) = *(short *)(lVar17 + 2) + sVar24;
  }
  if (local_80 != 0) {
LAB_003d112d:
    plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x40 + uVar1 * 8);
    *plVar12 = *plVar12 - uVar25;
    plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x50 + uVar1 * 8);
    *plVar12 = *plVar12 - uVar10;
    return;
  }
LAB_003d0a35:
  plVar12 = (long *)(*(long *)(param_1 + 0x70) + 8);
  *plVar12 = *plVar12 - uVar25;
  plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x10);
  *plVar12 = *plVar12 - uVar10;
  if (*(char *)(param_1 + 0x78) == '\0') {
    return;
  }
  plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x20);
  *plVar12 = *plVar12 - uVar25;
  plVar12 = (long *)(*(long *)(param_1 + 0x70) + 0x28);
  *plVar12 = *plVar12 - uVar10;
  return;
}


// ===== 003d14d0 pmaRegmapChangeStateAttrib =====

void pmaRegmapChangeStateAttrib
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  pmaRegmapChangeBlockStateAttrib(param_1,param_2,1,param_3,param_4);
  return;
}


// ===== 003d14f0 pmaRegmapChangePageStateAttrib =====

void pmaRegmapChangePageStateAttrib(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  pmaRegmapChangeBlockStateAttrib(param_1,param_2,param_3 >> 0x10);
  return;
}


// ===== 003d1500 pmaRegmapChangeLocalizationState =====

void pmaRegmapChangeLocalizationState(long param_1,ulong param_2,ushort param_3,ushort param_4)

{
  ulong uVar1;
  ushort *puVar2;
  long lVar3;
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  if ((uVar1 <= param_2) && (param_2 < *(long *)(param_1 + 0x18) + uVar1)) {
    lVar3 = (param_2 - uVar1 >> 10) * 4;
    puVar2 = (ushort *)(*(long *)(param_1 + 0x60) + lVar3);
    *puVar2 = *puVar2 & ~param_4;
    puVar2 = (ushort *)(lVar3 + *(long *)(param_1 + 0x60));
    *puVar2 = *puVar2 | param_3;
  }
  return;
}


// ===== 003d1540 pmaRegmapChangeBlockLocalizationState =====

void pmaRegmapChangeBlockLocalizationState
               (long param_1,ulong param_2,long param_3,ushort param_4,ushort param_5)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ushort *puVar6;
  
  uVar2 = *(ulong *)(param_1 + 0x10);
  uVar4 = (param_2 - 1) + param_3;
  uVar1 = *(long *)(param_1 + 0x18) + -1 + uVar2;
  if (param_2 <= uVar2) {
    param_2 = uVar2;
  }
  uVar5 = param_2 - uVar2 >> 10;
  if (uVar1 <= uVar4) {
    uVar4 = uVar1;
  }
  puVar6 = (ushort *)(uVar5 * 4 + *(long *)(param_1 + 0x60));
  *puVar6 = *puVar6 & ~param_5;
  uVar4 = uVar4 - uVar2 >> 10;
  puVar6 = (ushort *)(uVar5 * 4 + *(long *)(param_1 + 0x60));
  *puVar6 = *puVar6 | param_4 & param_5;
  if (uVar5 < uVar4) {
    lVar3 = uVar5 * 4 + 4;
    do {
      puVar6 = (ushort *)(*(long *)(param_1 + 0x60) + lVar3);
      *puVar6 = *puVar6 & ~param_5;
      puVar6 = (ushort *)(*(long *)(param_1 + 0x60) + lVar3);
      lVar3 = lVar3 + 4;
      *puVar6 = *puVar6 | param_4 & param_5;
    } while (uVar4 * 4 + 4 != lVar3);
  }
  return;
}


// ===== 003d1600 pmaRegmapRead =====

ulong pmaRegmapRead(long param_1,ulong param_2,char param_3)

{
  long lVar1;
  byte bVar2;
  ulong uVar3;
  byte bVar4;
  ulong uVar5;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pRegmap != NULL","src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x3ec
                       );
  }
  bVar4 = (byte)param_2 & 0x3f;
  uVar5 = 0;
  uVar3 = 0;
  do {
    lVar1 = uVar5 * 8;
    bVar2 = (byte)uVar5;
    uVar5 = uVar5 + 1;
    uVar3 = uVar3 | ((*(ulong *)(*(long *)(param_1 + 0x28 + lVar1) + (param_2 >> 6) * 8) &
                     1L << bVar4) >> bVar4) << (bVar2 & 0x3f);
  } while (uVar5 != (-(uint)(param_3 == '\0') & 0xfffffffb) + 7);
  return uVar3;
}


// ===== 003d16f0 pmaRegmapReadLocalizationInfo =====

undefined4 pmaRegmapReadLocalizationInfo(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  if ((uVar1 <= param_2) && (param_2 < *(long *)(param_1 + 0x18) + uVar1)) {
    return *(undefined4 *)(*(long *)(param_1 + 0x60) + (param_2 - uVar1 >> 10) * 4);
  }
  return 0;
}


// ===== 003d1730 pmaRegmapReadLocalizationStatus =====

undefined2 pmaRegmapReadLocalizationStatus(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  if ((uVar1 <= param_2) && (param_2 < *(long *)(param_1 + 0x18) + uVar1)) {
    return *(undefined2 *)(*(long *)(param_1 + 0x60) + (param_2 - uVar1 >> 10) * 4);
  }
  return 0;
}


// ===== 003d1770 pmaRegmapGetLocalizedRegionAllocationCount =====

undefined2 pmaRegmapGetLocalizedRegionAllocationCount(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  if ((uVar1 <= param_2) && (param_2 < *(long *)(param_1 + 0x18) + uVar1)) {
    return *(undefined2 *)(*(long *)(param_1 + 0x60) + 2 + (param_2 - uVar1 >> 10) * 4);
  }
  return 0;
}


// ===== 003d17b0 pmaRegmapScanContiguous =====

undefined8
pmaRegmapScanContiguous
          (long param_1,long param_2,ulong param_3,ulong param_4,long param_5,long *param_6,
          ulong param_7,ulong param_8,char param_9,undefined4 param_10,long *param_11,char param_12,
          char param_13)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  
  if (param_9 == '\0') {
    uVar4 = param_3 >> 0x10;
    if (param_3 == 0 && param_4 == 0) {
      uVar4 = 0;
    }
    uVar5 = *(long *)(param_1 + 8) - 1;
    uVar2 = param_4 >> 0x10;
    if (uVar5 <= param_4 >> 0x10) {
      uVar2 = uVar5;
    }
    if (param_3 != 0 || param_4 != 0) {
      uVar5 = uVar2;
    }
  }
  else {
    if ((param_13 != '\0') || (0x2000000 < param_8)) {
      return 0x1f;
    }
    uVar4 = param_3 >> 0x10;
    uVar5 = *(long *)(param_1 + 8) - 1;
    if (param_3 == 0 && param_4 == 0) {
      uVar4 = 0;
    }
    uVar2 = param_4 >> 0x10;
    if (uVar5 <= param_4 >> 0x10) {
      uVar2 = uVar5;
    }
    if (param_3 != 0 || param_4 != 0) {
      uVar5 = uVar2;
    }
    if (*(long *)(param_1 + 0x18) == 0) {
      return 0x51;
    }
    uVar3 = *(ulong *)(param_1 + 0x10);
    uVar2 = (uVar3 - 1) + *(long *)(param_1 + 0x18);
    if (uVar4 < uVar3) {
      uVar4 = uVar3;
    }
    if (uVar2 <= uVar5) {
      uVar5 = uVar2;
    }
  }
  lVar6 = (param_7 >> 0x10) * param_5;
  uVar2 = param_8 >> 0x10;
  uVar3 = ((param_8 - 1) + param_2 & -param_8) - param_2 >> 0x10;
  if (param_13 == '\0') {
    lVar1 = _scanContiguousSearchLoop(param_1,lVar6,uVar4,uVar5,uVar2,uVar3,param_9,param_10,0);
    if (-1 < lVar1) {
LAB_003d19e0:
      *param_6 = lVar1 * 0x10000 + param_2;
      *param_11 = param_5;
      return 0;
    }
    *param_11 = 0;
    if (param_12 != '\0') {
      return 0x51;
    }
    lVar6 = _scanContiguousSearchLoop(param_1,lVar6,uVar4,uVar5,uVar2,uVar3,param_9,param_10,1);
  }
  else {
    lVar1 = _scanContiguousSearchLoopReverse(param_1,lVar6,uVar4,uVar5,uVar2,uVar3,0);
    if (-1 < lVar1) goto LAB_003d19e0;
    *param_11 = 0;
    if (param_12 != '\0') {
      return 0x51;
    }
    lVar6 = _scanContiguousSearchLoopReverse(param_1,lVar6,uVar4,uVar5,uVar2,uVar3,1);
  }
  if (lVar6 < 0) {
    return 0x51;
  }
  *param_6 = lVar6 * 0x10000 + param_2;
  return 0x17;
}


// ===== 003d1a00 pmaRegmapScanDiscontiguous =====

byte pmaRegmapScanDiscontiguous
               (long param_1,long param_2,ulong param_3,ulong param_4,ulong param_5,long param_6,
               ulong param_7,ulong param_8,char param_9,uint param_10,ulong *param_11,char param_12,
               char param_13)

{
  byte *pbVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  bool bVar6;
  ulong uVar7;
  ulong *puVar8;
  long lVar9;
  ulong uVar10;
  ulong *puVar11;
  ulong uVar12;
  byte bVar13;
  ulong uVar14;
  undefined8 *puVar15;
  long *plVar16;
  long *plVar17;
  ulong *puVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  ulong uVar24;
  ulong uVar25;
  uint uVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  long local_f0;
  long local_e8;
  ulong local_e0;
  ulong local_d0;
  ulong local_b8;
  ulong local_a8;
  ulong local_98;
  ulong local_80;
  ulong local_70 [7];
  ulong local_38;
  
  if (param_9 == '\0') {
    lVar9 = 0;
    uVar21 = 0;
  }
  else {
    if ((param_13 != '\0') || (0x2000000 < param_8)) {
      return 0x1f;
    }
    uVar21 = *(ulong *)(param_1 + 0x10);
    lVar9 = *(long *)(param_1 + 0x18);
  }
  if (param_8 != param_7) {
    nvAssertFailedNoLog("alignment == pageSize","src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c"
                        ,0x816);
  }
  uVar19 = param_7 >> 0x10;
  uVar28 = param_8 >> 0x10;
  uVar20 = ((param_8 - 1) + param_2 & -param_8) - param_2 >> 0x10;
  if (param_3 == 0 && param_4 == 0) {
    local_98 = 0;
    uVar12 = *(long *)(param_1 + 8) - 1;
  }
  else {
    if (param_3 % param_7 != 0) {
      nvAssertFailedNoLog("rangeStart %% pageSize == 0",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x826);
    }
    if ((param_4 + 1) % param_7 != 0) {
      nvAssertFailedNoLog("(rangeEnd + 1) %% pageSize == 0",
                          "src/kernel/gpu/mem_mgr/phys_mem_allocator/regmap.c",0x828);
    }
    local_98 = param_3 >> 0x10;
    uVar10 = *(long *)(param_1 + 8) - 1;
    uVar12 = param_4 >> 0x10;
    if (uVar10 <= param_4 >> 0x10) {
      uVar12 = uVar10;
    }
  }
  uVar10 = param_5;
  if (param_9 == '\0') {
    if (param_13 != '\0') goto LAB_003d1f00;
    local_f0 = *(long *)(param_1 + 0x18);
    local_d0 = 0;
    uVar21 = *(ulong *)(param_1 + 0x10);
    uVar7 = ((uVar28 - 1) - uVar20) + local_98 & -uVar28;
  }
  else {
    if (lVar9 == 0) {
      return 0x51;
    }
    if (local_98 < uVar21) {
      local_98 = uVar21;
    }
    uVar21 = (uVar21 - 1) + lVar9;
    if (uVar21 < uVar12) {
      uVar12 = uVar21;
    }
    if (param_13 != '\0') {
LAB_003d1f00:
      local_80 = 0;
      uVar7 = uVar20 + uVar19 & uVar28 - 1;
      uVar20 = *(ulong *)(param_1 + 0x10);
      lVar9 = *(long *)(param_1 + 0x18);
      uVar21 = ((uVar12 - uVar7) + 1 & -uVar28) + uVar7;
      local_70[0] = uVar21;
      local_70[1] = uVar21;
      local_70[2] = uVar21;
      local_70[3] = uVar21;
      local_70[4] = uVar21;
      local_70[5] = uVar21;
      local_70[6] = uVar21;
      local_a8 = param_5;
LAB_003d1fb0:
      while ((((local_98 < uVar21 && (uVar12 = uVar21 - 1, uVar20 <= uVar12)) &&
              (uVar12 < uVar20 + lVar9)) &&
             ((*(byte *)(*(long *)(param_1 + 0x60) + (uVar12 - uVar20 >> 10) * 4) & 1) != 0))) {
        uVar21 = (uVar12 - uVar20 & 0xfffffffffffffc00) + uVar20;
      }
      puVar18 = local_70;
      puVar11 = puVar18;
      do {
        uVar12 = *puVar11;
        if (uVar21 < *puVar11) {
          uVar12 = uVar21;
        }
        puVar8 = puVar11 + 1;
        *puVar11 = uVar12;
        puVar11 = puVar8;
      } while (&local_38 != puVar8);
      if (local_98 + uVar19 <= uVar21) {
        bVar6 = false;
        uVar29 = 0;
        uVar21 = uVar21 - uVar19;
        uVar12 = local_70[0];
        do {
          if (local_a8 <= local_80) goto LAB_003d20e8;
LAB_003d2080:
          do {
            if (uVar12 <= uVar21) goto LAB_003d20d4;
            uVar26 = (uint)(uVar12 - 1) & 0x3f;
            uVar24 = *(ulong *)(*(long *)(param_1 + 0x28 + uVar29 * 8) + (uVar12 - 1 >> 6) * 8);
            if (uVar26 == 0x3f) {
              if (uVar24 == 0) {
                uVar12 = uVar12 - 0x40;
                *puVar18 = uVar12;
                goto LAB_003d2080;
              }
            }
            else {
              bVar13 = (byte)uVar26;
              uVar24 = uVar24 << (~bVar13 & 0x3f) | 0xffffffffffffffffU >> (bVar13 + 1 & 0x3f);
            }
            uVar27 = 0x3f;
            if (uVar24 != 0) {
              for (; uVar24 >> uVar27 == 0; uVar27 = uVar27 - 1) {
              }
            }
            uVar12 = uVar12 - ((uVar27 ^ 0x3f) & 0xffffffff);
            *puVar18 = uVar12;
          } while ((int)(uVar27 ^ 0x3f) != 0);
          bVar6 = true;
LAB_003d20d4:
          uVar29 = uVar29 + 1;
          while( true ) {
            puVar18 = puVar18 + 1;
            uVar12 = *puVar18;
            if ((uVar29 & 0xfffffffffffffffb) == 0) break;
LAB_003d20e8:
            if (uVar21 < uVar12) {
              lVar3 = *(long *)(param_1 + 0x28 + uVar29 * 8);
              do {
                while( true ) {
                  uVar27 = uVar12 - 1 >> 6;
                  uVar26 = (uint)(uVar12 - 1) & 0x3f;
                  uVar25 = (ulong)uVar26;
                  uVar24 = *(ulong *)(lVar3 + uVar27 * 8);
                  if (uVar25 == 0x3f) break;
                  uVar14 = 0xffffffffffffffffU >> ((byte)uVar26 + 1 & 0x3f) |
                           uVar24 << (~(byte)uVar26 & 0x3f);
LAB_003d211e:
                  uVar5 = 0x3f;
                  if (uVar14 != 0) {
                    for (; uVar14 >> uVar5 == 0; uVar5 = uVar5 - 1) {
                    }
                  }
                  if ((int)(uVar5 ^ 0x3f) == 0) {
                    if (uVar25 != 0x3f) {
                      uVar24 = -1L << ((char)uVar26 + 1U & 0x3f) | uVar24;
                    }
                    if (uVar24 != 0xffffffffffffffff) {
                      uVar21 = (uVar12 - uVar25) + 0x3f;
                      goto LAB_003d220a;
                    }
                    uVar21 = (uVar12 - uVar25) - 1;
                    if (uVar21 <= local_98) goto LAB_003d235d;
                    puVar18 = (ulong *)(lVar3 + -8 + uVar27 * 8);
                    goto LAB_003d232d;
                  }
                  uVar12 = uVar12 - ((uVar5 ^ 0x3f) & 0xffffffff);
                  *puVar18 = uVar12;
                  if (uVar12 <= uVar21) goto LAB_003d2171;
                }
                if (uVar24 != 0) {
                  uVar26 = 0x3f;
                  uVar14 = uVar24;
                  goto LAB_003d211e;
                }
                uVar12 = uVar12 - 0x40;
                *puVar18 = uVar12;
              } while (uVar21 < uVar12);
            }
LAB_003d2171:
            uVar29 = uVar29 + 1;
            if (uVar29 == 7) {
              if (bVar6) {
                local_a8 = local_a8 - 1;
                *(ulong *)(param_6 + local_a8 * 8) = uVar21;
                goto LAB_003d1fb0;
              }
              *(ulong *)(param_6 + local_80 * 8) = uVar21;
              local_80 = local_80 + 1;
              if (param_5 != local_80) goto LAB_003d1fb0;
              lVar9 = 0;
              goto LAB_003d237a;
            }
          }
        } while( true );
      }
LAB_003d235d:
      lVar9 = param_5 - local_a8;
      uVar10 = local_80 + lVar9;
      goto LAB_003d237a;
    }
    local_f0 = *(long *)(param_1 + 0x18);
    uVar21 = *(ulong *)(param_1 + 0x10);
    uVar7 = ((uVar28 - 1) - uVar20) + local_98 & -uVar28;
    local_d0 = (ulong)((uint)uVar21 & 0x1ff);
  }
  local_e0 = -uVar28;
  local_e8 = uVar28 - 1;
  uVar7 = uVar7 + uVar20;
  local_70[0] = uVar7;
  local_70[1] = uVar7;
  local_70[2] = uVar7;
  local_70[3] = uVar7;
  local_70[4] = uVar7;
  local_70[5] = uVar7;
  local_70[6] = uVar7;
  local_80 = 0;
  local_b8 = param_5;
joined_r0x003d1baf:
  if (param_9 == '\0') {
    uVar29 = uVar7;
    while ((((uVar29 <= uVar12 && (uVar21 <= uVar29)) && (uVar29 < local_f0 + uVar21)) &&
           ((*(byte *)(*(long *)(param_1 + 0x60) + (uVar29 - uVar21 >> 10) * 4) & 1) != 0))) {
      uVar29 = (uVar29 + (0x400 - uVar21) & 0xfffffffffffffc00) + uVar21;
    }
  }
  else {
    lVar9 = 0x200 - local_d0;
    if (((uint)(uVar7 - uVar21 >> 9) & 1) != param_10) {
      uVar7 = (uVar7 + lVar9 & 0xfffffffffffffe00) + local_d0;
    }
    uVar24 = uVar7 + lVar9 & 0xfffffffffffffe00;
    uVar28 = local_d0 + uVar24;
    uVar29 = uVar7;
    if ((uVar28 < uVar19 + uVar7) &&
       (uVar29 = local_d0 + 0x200 + uVar24, param_10 == ((uint)(uVar28 - uVar21 >> 9) & 1))) {
      uVar29 = uVar28;
    }
    if (uVar29 <= uVar12) {
      do {
        pbVar1 = (byte *)(*(long *)(param_1 + 0x60) + (uVar29 - uVar21 >> 10) * 4);
        if (((*pbVar1 & 1) != 0) || (*(short *)(pbVar1 + 2) == 0)) break;
        uVar29 = (uVar29 + (0x400 - uVar21) & 0xfffffffffffffc00) + uVar21;
        if (param_10 != 0) {
          uVar29 = (uVar29 + lVar9 & 0xfffffffffffffe00) + local_d0;
        }
      } while (uVar29 <= uVar12);
    }
  }
  puVar18 = local_70;
  puVar11 = puVar18;
  do {
    uVar28 = *puVar11;
    if (*puVar11 < uVar29) {
      uVar28 = uVar29;
    }
    puVar8 = puVar11 + 1;
    *puVar11 = uVar28;
    puVar11 = puVar8;
  } while (&local_38 != puVar8);
  uVar7 = uVar29 + uVar19;
  if (uVar7 - 1 <= uVar12) {
    bVar6 = false;
    uVar24 = 0;
    uVar28 = local_70[0];
    do {
      if (local_b8 <= local_80) goto LAB_003d1ce1;
LAB_003d1c90:
      do {
        if (uVar7 <= uVar28) goto LAB_003d1ccd;
        uVar27 = *(ulong *)(*(long *)(param_1 + 0x28 + uVar24 * 8) + (uVar28 >> 6) * 8);
        bVar13 = (byte)uVar28 & 0x3f;
        if ((uVar28 & 0x3f) == 0) {
          if (uVar27 == 0) {
            uVar28 = uVar28 + 0x40;
            *puVar18 = uVar28;
            goto LAB_003d1c90;
          }
        }
        else {
          uVar27 = uVar27 >> bVar13 | -1L << 0x40 - bVar13;
        }
        uVar26 = 0;
        for (; (uVar27 & 1) == 0; uVar27 = uVar27 >> 1 | 0x8000000000000000) {
          uVar26 = uVar26 + 1;
        }
        uVar28 = uVar28 + uVar26;
        *puVar18 = uVar28;
      } while (uVar26 != 0);
      bVar6 = true;
LAB_003d1ccd:
      uVar24 = uVar24 + 1;
      while( true ) {
        puVar18 = puVar18 + 1;
        uVar28 = *puVar18;
        if ((uVar24 & 0xfffffffffffffffb) == 0) break;
LAB_003d1ce1:
        if (uVar28 < uVar7) {
          lVar9 = *(long *)(param_1 + 0x28 + uVar24 * 8);
          do {
            uVar27 = *(ulong *)(lVar9 + (uVar28 >> 6) * 8);
            bVar13 = (byte)uVar28 & 0x3f;
            if ((uVar28 & 0x3f) == 0) {
              uVar25 = 0x40;
              if (uVar27 != 0) {
                bVar13 = 0;
                uVar26 = 0;
                for (uVar25 = uVar27; (uVar25 & 1) == 0; uVar25 = uVar25 >> 1 | 0x8000000000000000)
                {
                  uVar26 = uVar26 + 1;
                }
                if (uVar26 != 0) goto LAB_003d1d27;
LAB_003d1d65:
                if ((uVar28 & 0x3f) != 0) {
                  uVar27 = 0xffffffffffffffffU >> (-bVar13 & 0x3f) | uVar27;
                }
                uVar7 = uVar28 & 0xffffffffffffffc0;
                if (uVar27 != 0xffffffffffffffff) goto LAB_003d1d90;
                uVar7 = uVar7 + 0x40;
                if (uVar12 < uVar7) goto LAB_003d24fa;
                puVar18 = (ulong *)(lVar9 + 8 + (uVar28 >> 6) * 8);
                goto LAB_003d24e0;
              }
            }
            else {
              uVar26 = 0;
              for (uVar25 = -1L << (-bVar13 & 0x3f) | uVar27 >> bVar13; (uVar25 & 1) == 0;
                  uVar25 = uVar25 >> 1 | 0x8000000000000000) {
                uVar26 = uVar26 + 1;
              }
              if (uVar26 == 0) goto LAB_003d1d65;
LAB_003d1d27:
              uVar25 = (ulong)uVar26;
            }
            uVar28 = uVar28 + uVar25;
            *puVar18 = uVar28;
          } while (uVar28 < uVar7);
        }
        uVar24 = uVar24 + 1;
        if (uVar24 == 7) {
          if (bVar6) {
            local_b8 = local_b8 - 1;
            *(ulong *)(param_6 + local_b8 * 8) = uVar29;
            goto joined_r0x003d1baf;
          }
          *(ulong *)(param_6 + local_80 * 8) = uVar29;
          local_80 = local_80 + 1;
          if (param_5 != local_80) goto joined_r0x003d1baf;
          lVar9 = 0;
          goto LAB_003d237a;
        }
      }
    } while( true );
  }
LAB_003d24fa:
  lVar9 = param_5 - local_b8;
  uVar10 = local_80 + lVar9;
LAB_003d237a:
  *param_11 = local_80;
  uVar21 = local_80;
  if (param_5 < uVar10) {
    lVar9 = param_5 - local_80;
    uVar10 = param_5;
LAB_003d239e:
    if ((param_12 != '\0') && (bVar13 = 0x51, local_80 != param_5)) goto LAB_003d229f;
    bVar13 = -(lVar9 != 0) & 0x17;
  }
  else {
    if (param_5 == uVar10) goto LAB_003d239e;
    bVar13 = 0x51;
  }
  if ((param_12 == '\0') && (uVar19 = param_5 - local_80 >> 1, uVar21 = uVar10, uVar19 != 0)) {
    puVar2 = (undefined8 *)(param_6 + param_5 * 8);
    puVar15 = (undefined8 *)(param_6 + (local_80 + uVar19) * 8);
    puVar22 = puVar2 + -uVar19;
    do {
      uVar4 = puVar15[-1];
      puVar23 = puVar22 + 1;
      puVar15 = puVar15 + -1;
      *puVar15 = *puVar22;
      *puVar22 = uVar4;
      puVar22 = puVar23;
    } while (puVar2 != puVar23);
  }
LAB_003d229f:
  local_80 = uVar21;
  plVar16 = (long *)(param_6 + -8) + local_80;
  if (local_80 == 0) {
    return bVar13;
  }
  do {
    plVar17 = plVar16 + -1;
    *plVar16 = *plVar16 * 0x10000 + param_2;
    plVar16 = plVar17;
  } while (plVar17 != (long *)(param_6 + -8));
  return bVar13;
LAB_003d232d:
  uVar24 = *puVar18;
  if (uVar24 != 0xffffffffffffffff) goto LAB_003d220a;
  uVar21 = uVar21 - 0x40;
  puVar18 = puVar18 + -1;
  if (uVar21 <= local_98) goto LAB_003d235d;
  goto LAB_003d232d;
LAB_003d220a:
  lVar3 = 0x3f;
  if (~uVar24 != 0) {
    for (; ~uVar24 >> lVar3 == 0; lVar3 = lVar3 + -1) {
    }
  }
  uVar21 = uVar7 + ((uVar21 - uVar7) - (ulong)((uint)lVar3 ^ 0x3f) & -uVar28);
  goto LAB_003d1fb0;
LAB_003d24e0:
  uVar27 = *puVar18;
  if (uVar27 != 0xffffffffffffffff) goto LAB_003d1d90;
  uVar7 = uVar7 + 0x40;
  puVar18 = puVar18 + 1;
  if (uVar12 < uVar7) goto LAB_003d24fa;
  goto LAB_003d24e0;
LAB_003d1d90:
  uVar26 = 0;
  for (uVar27 = ~uVar27; (uVar27 & 1) == 0; uVar27 = uVar27 >> 1 | 0x8000000000000000) {
    uVar26 = uVar26 + 1;
  }
  uVar7 = ((local_e8 - uVar20) + uVar7 + (ulong)uVar26 & local_e0) + uVar20;
  goto joined_r0x003d1baf;
}


// ===== 003d25f0 pmaRegmapGetSize =====

void pmaRegmapGetSize(long param_1,long *param_2)

{
  *param_2 = *(long *)(param_1 + 8) << 0x10;
  return;
}


// ===== 003d2600 pmaRegmapGetLocalizableSize =====

void pmaRegmapGetLocalizableSize(long param_1,uint param_2,long *param_3)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_2 < 2) {
    lVar1 = (*(ulong *)(param_1 + 0x18) >> 1) << 0x10;
  }
  *param_3 = lVar1;
  return;
}


// ===== 003d2620 pmaRegmapGetLargestFree =====

void pmaRegmapGetLargestFree(long param_1,long *param_2,long *param_3)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  uint uVar13;
  uint local_4c;
  uint local_3c [3];
  
  uVar10 = 0;
  uVar7 = 0;
  lVar8 = 0;
  uVar1 = *(ulong *)(param_1 + 8);
  local_4c = 0;
  uVar11 = uVar1 - 1 >> 6;
  do {
    iVar12 = (int)uVar10;
    uVar10 = *(ulong *)(*(long *)(param_1 + 0x28) + uVar7 * 8) |
             *(ulong *)(*(long *)(param_1 + 0x30) + uVar7 * 8);
    if ((uVar11 == uVar7) && ((uVar1 & 0x3f) != 0)) {
      uVar10 = uVar10 | -1L << ((byte)uVar1 & 0x3f);
      iVar5 = maxZerosGet(uVar10,local_3c);
      if (iVar5 == 0x40) {
LAB_003d26fa:
        uVar10 = (ulong)(iVar12 + 0x40);
      }
      else {
LAB_003d2671:
        uVar9 = 0;
        for (uVar3 = uVar10; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x8000000000000000) {
          uVar9 = uVar9 + 1;
        }
        uVar13 = iVar12 + uVar9;
        uVar4 = maxZerosGet(uVar10,local_3c);
        uVar6 = uVar13;
        if (uVar13 <= uVar4) {
          uVar6 = uVar4;
        }
        if (local_4c < uVar6) {
          local_4c = uVar6;
          if (uVar4 < uVar13) {
            lVar8 = (uVar7 * 0x40 - (ulong)uVar6) + (ulong)uVar9;
          }
          else {
            lVar8 = uVar7 * 0x40 + (ulong)local_3c[0];
          }
        }
        lVar2 = 0x3f;
        if (uVar10 != 0) {
          for (; uVar10 >> lVar2 == 0; lVar2 = lVar2 + -1) {
          }
        }
        uVar10 = (ulong)((uint)lVar2 ^ 0x3f);
      }
    }
    else {
      iVar5 = maxZerosGet(uVar10,local_3c);
      if (iVar5 == 0x40) goto LAB_003d26fa;
      if (uVar10 != 0) goto LAB_003d2671;
      uVar4 = iVar12 + 0x40;
      uVar10 = 0x40;
      uVar6 = maxZerosGet(0,local_3c);
      uVar9 = uVar6;
      if (uVar6 <= uVar4) {
        uVar9 = uVar4;
      }
      if (local_4c < uVar9) {
        local_4c = uVar9;
        if (uVar6 < uVar4) {
          lVar8 = (uVar7 * 0x40 - (ulong)uVar9) + 0x40;
        }
        else {
          lVar8 = (ulong)local_3c[0] + uVar7 * 0x40;
        }
      }
    }
    if (uVar11 == uVar7) {
      if (local_4c < (uint)uVar10) {
        lVar8 = (uVar7 + 1) * 0x40 - uVar10;
      }
      else {
        uVar10 = (ulong)local_4c;
      }
      *param_2 = uVar10 << 0x10;
      *param_3 = lVar8 << 0x10;
      return;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}


// ===== 003d2810 pmaRegmapGetEvictingFrames =====

undefined8 pmaRegmapGetEvictingFrames(long param_1)

{
  return *(undefined8 *)(param_1 + 0x68);
}


// ===== 003d2820 pmaRegmapSetEvictingFrames =====

void pmaRegmapSetEvictingFrames(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x68) = param_2;
  return;
}


// ===== 003d2830 _sec2AllocAndMapBuffer.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _sec2AllocAndMapBuffer_constprop_0(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0;
  undefined8 local_a0;
  undefined8 local_78;
  undefined4 local_4c;
  undefined4 local_48;
  
  lVar2 = rmapiGetInterface(4);
  local_f8 = 0;
  local_f0 = 0;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x1b78);
  *(undefined8 *)(param_2 + 6) = 0x10000;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  portMemSet(&local_b8,0,0x80);
  local_b8 = 0xdeaf0006;
  local_78 = *(undefined8 *)(param_2 + 6);
  local_b0 = 0;
  local_a0 = 0x400000003000000;
  local_48 = 4;
  uVar4 = 0x80;
  iVar1 = (**(code **)(lVar2 + 8))
                    (lVar2,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),*param_2,
                     0x3e,&local_b8);
  if (iVar1 == 0) {
    portMemSet(&local_b8,0,0x80,uVar4);
    local_a0 = 0x2000000;
    local_b8 = 0xdeaf0006;
    local_78 = *(undefined8 *)(param_2 + 6);
    local_b0 = local_b0 | 0x80000;
    local_4c = param_2[2];
    iVar1 = (**(code **)(lVar2 + 8))
                      (lVar2,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),
                       param_2[1],0x50a0,&local_b8,0x80);
    if (iVar1 == 0) {
      local_f8 = *(undefined8 *)(param_1 + 0x48);
      local_f0 = CONCAT44(*param_2,param_2[1]);
      local_e0 = *(undefined8 *)(param_2 + 6);
      local_d8 = CONCAT44(local_d8._4_4_,
                          (uint)(*(char *)(*(long *)(g_pSys + 0x208) + 0x68) != '\0') << 4) | 0x20;
      iVar1 = (**(code **)(lVar2 + 0x98))(lVar2,&local_f8);
      if (iVar1 == 0) {
        *(undefined8 *)(param_2 + 4) = local_c8;
        uVar3 = memmgrMemUtilsGetMemDescFromHandle_IMPL
                          (uVar3,*(undefined4 *)(param_1 + 0x48),*param_2);
        *(undefined8 *)(param_2 + 8) = uVar3;
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar1,"pRmApi->Map(pRmApi, &mapDmaParams)",
                   "src/kernel/gpu/mem_mgr/sec2_utils.c",0x99);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "pRmApi->AllocWithHandle(pRmApi, pSec2Utils->hClient, pSec2Utils->hDevice, pSec2Buf->hVirtMem, NV50_MEMORY_VIRTUAL, &memAllocParams, sizeof(memAllocParams))"
                 ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0x7f);
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "pRmApi->AllocWithHandle(pRmApi, pSec2Utils->hClient, pSec2Utils->hDevice, pSec2Buf->hPhysMem, NV01_MEMORY_SYSTEM, &memAllocParams, sizeof(memAllocParams))"
               ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0x6b);
  }
  return iVar1;
}


// ===== 003d2ae0 sec2utilsConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int sec2utilsConstruct_IMPL(long param_1,long param_2,undefined8 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint *puVar9;
  undefined8 extraout_RDX;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  uint local_3c [3];
  
  if (param_2 == 0) {
    nvAssertFailedNoLog(&DAT_00d556d3,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xbb);
    return 0x40;
  }
  if ((*(long *)(param_2 + 0x1d18) == 0) || (*(char *)(*(long *)(param_2 + 0x1d18) + 0x2a9) == '\0')
     ) {
    nvAssertFailedNoLog("((pConfCompute != NULL) && (pConfCompute->getProperty(pCC, PDB_PROP_CONFCOMPUTE_CC_FEATURE_ENABLED)))"
                        ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xbf);
    return 0x56;
  }
  lVar3 = *(long *)(param_2 + 0x1b78);
  *(long *)(param_1 + 0x60) = param_2;
  lVar6 = rmapiGetInterface(4);
  puVar7 = (undefined4 *)portMemAllocNonPaged(0x198);
  if (puVar7 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/sec2_utils.c",200);
    return 0x1a;
  }
  portMemSet(puVar7,0,0x198);
  iVar5 = (**(code **)(lVar6 + 8))(lVar6,0,0,0,0,param_1 + 0x48,4);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,
               "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pSec2Utils->hClient, sizeof(pSec2Utils->hClient))"
               ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xcc);
    goto LAB_003d2cd4;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x48);
  puVar7[0x2b] = uVar1;
  iVar5 = serverGetClientUnderLock(g_resServ,uVar1,puVar7 + 0x18);
  if (iVar5 == 0) {
    iVar5 = clientSetHandleGenerator_IMPL(*(undefined8 *)(puVar7 + 0x18),1,0xfffffffe);
    if (iVar5 == 0) {
      *puVar7 = 0;
      *(undefined1 *)(puVar7 + 0x2c) = 1;
      *(long *)(puVar7 + 0x5e) = param_2;
      puVar7[3] = 0;
      *(undefined8 *)(puVar7 + 0x62) = param_3;
      puVar7[0xb] = 0;
      *(undefined1 *)((long)puVar7 + 0x5e) = 0;
      puVar7[0x54] = 3;
      puVar7[0x1c] = 0x31;
      *(undefined1 *)((long)puVar7 + 0x195) = 1;
      local_3c[0] = 0;
      iVar5 = gpuGetClassList_IMPL(param_2,local_3c,0,0x28c40800);
      if (iVar5 == 0) {
        if (local_3c[0] == 0) {
          iVar5 = 0x56;
          nvAssertFailedNoLog("(numClasses != 0)","src/kernel/gpu/mem_mgr/sec2_utils.c",0x3a);
        }
        else {
          puVar8 = (uint *)portMemAllocNonPaged((ulong)local_3c[0] << 2);
          if (puVar8 == (uint *)0x0) {
            iVar5 = 0x1a;
            nvAssertFailedNoLog("(pClassList != NULL)","src/kernel/gpu/mem_mgr/sec2_utils.c",0x3d);
          }
          else {
            iVar5 = gpuGetClassList_IMPL(param_2,local_3c,puVar8,0x28c40800);
            if (iVar5 == 0) {
              if (local_3c[0] != 0) {
                puVar9 = puVar8;
                uVar11 = 0;
                do {
                  uVar10 = uVar11;
                  uVar2 = *puVar9;
                  uVar11 = uVar10;
                  if (uVar10 < uVar2) {
                    uVar11 = uVar2;
                  }
                  puVar9 = puVar9 + 1;
                } while (puVar8 + local_3c[0] != puVar9);
                if (uVar10 != 0 || uVar2 != 0) {
                  *(uint *)(param_1 + 0x68) = uVar11;
                  portMemFree(puVar8);
                  bVar12 = false;
                  puVar7[0x48] = *(undefined4 *)(param_1 + 0x68);
                  if (*(long *)(param_2 + 0x1bc0) != 0) {
                    cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL
                                      (param_2,*(long *)(param_2 + 0x1bc0),extraout_RDX,0);
                    bVar12 = cVar4 != '\0';
                  }
                  iVar5 = channelSetupIDs(puVar7,param_2,0,bVar12);
                  if (iVar5 == 0) {
                    uVar1 = puVar7[0xb];
                    *(undefined4 *)(param_1 + 0x90) = uVar1;
                    *(undefined4 *)(param_1 + 0xb8) = uVar1;
                    channelSetupChannelBufferSizes(puVar7);
                    uVar11 = *(uint *)(param_2 + 0x4930);
                    uVar2 = *(uint *)(param_2 + 0x4924);
                    *(uint *)(param_2 + 0x4930) = uVar11 & 0xfffffff3 | 8;
                    *(uint *)(param_2 + 0x4924) = uVar2 & 0xfffcffff | 0x20000;
                    puVar7[0x1c] = 0x26;
                    iVar5 = channelAllocSubdevice(param_2,puVar7);
                    if (iVar5 == 0) {
                      *(undefined1 *)(lVar3 + 0x445) = 1;
                      iVar5 = (**(code **)(lVar3 + 0x1a0))(param_2,lVar3,puVar7);
                      if (iVar5 == 0) {
                        *(undefined1 *)(lVar3 + 0x445) = 0;
                        *(undefined4 *)(param_1 + 0x4c) = *puVar7;
                        *(undefined4 *)(param_1 + 0x50) = puVar7[3];
                        nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x106,
                                     "sec2utilsConstruct_IMPL",1,
                                     "NVRM: Channel alloc successful for Sec2Utils\n");
                        *(undefined4 **)(param_1 + 0x58) = puVar7;
                        iVar5 = (**(code **)(lVar3 + 0x1b0))(param_2,lVar3,puVar7);
                        if (iVar5 == 0) {
                          *(uint *)(param_2 + 0x4930) = uVar11;
                          *(uint *)(param_2 + 0x4924) = uVar2;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined8 *)(param_1 + 0x78) = 0;
                          *(undefined8 *)(param_1 + 0xd8) = 0;
                          iVar5 = serverutilGenResourceHandle
                                            (*(undefined4 *)(param_1 + 0x48),param_1 + 0x88);
                          if (iVar5 == 0) {
                            iVar5 = serverutilGenResourceHandle
                                              (*(undefined4 *)(param_1 + 0x48),param_1 + 0x8c);
                            if (iVar5 == 0) {
                              iVar5 = _sec2AllocAndMapBuffer_constprop_0(param_1,param_1 + 0x88);
                              if (iVar5 == 0) {
                                iVar5 = serverutilGenResourceHandle
                                                  (*(undefined4 *)(param_1 + 0x48),param_1 + 0xb0);
                                if (iVar5 == 0) {
                                  iVar5 = serverutilGenResourceHandle
                                                    (*(undefined4 *)(param_1 + 0x48),param_1 + 0xb4)
                                  ;
                                  if (iVar5 == 0) {
                                    iVar5 = _sec2AllocAndMapBuffer_constprop_0
                                                      (param_1,param_1 + 0xb0);
                                    if (iVar5 == 0) {
                                      iVar5 = ccslContextInitViaChannel_IMPL
                                                        (param_1 + 0x80,
                                                         *(undefined4 *)(param_1 + 0x48),
                                                         *(undefined4 *)(param_1 + 0x50),puVar7[2]);
                                      if (iVar5 == 0) {
                                        return 0;
                                      }
                                      nvAssertOkFailedNoLog
                                                (iVar5,
                                                 "ccslContextInitViaChannel(&pSec2Utils->pCcslCtx, pSec2Utils->hClient, pSec2Utils->hSubdevice, pChannel->channelId)"
                                                 ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0x116);
                                      goto LAB_003d318a;
                                    }
                                    nvAssertOkFailedNoLog
                                              (iVar5,
                                               "_sec2AllocAndMapBuffer(pSec2Utils, RM_PAGE_SIZE_64K, &pSec2Utils->semaMthdAuthTagBuf)"
                                               ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xae);
                                  }
                                  else {
                                    nvAssertOkFailedNoLog
                                              (iVar5,
                                               "serverutilGenResourceHandle(pSec2Utils->hClient, &pSec2Utils->semaMthdAuthTagBuf.hVirtMem)"
                                               ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xad);
                                  }
                                }
                                else {
                                  nvAssertOkFailedNoLog
                                            (iVar5,
                                             "serverutilGenResourceHandle(pSec2Utils->hClient, &pSec2Utils->semaMthdAuthTagBuf.hPhysMem)"
                                             ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xac);
                                }
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (iVar5,
                                           "_sec2AllocAndMapBuffer(pSec2Utils, RM_PAGE_SIZE_64K, &pSec2Utils->scrubMthdAuthTagBuf)"
                                           ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xaa);
                              }
                            }
                            else {
                              nvAssertOkFailedNoLog
                                        (iVar5,
                                         "serverutilGenResourceHandle(pSec2Utils->hClient, &pSec2Utils->scrubMthdAuthTagBuf.hVirtMem)"
                                         ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xa9);
                            }
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar5,
                                       "serverutilGenResourceHandle(pSec2Utils->hClient, &pSec2Utils->scrubMthdAuthTagBuf.hPhysMem)"
                                       ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xa8);
                          }
                          nvAssertOkFailedNoLog
                                    (iVar5,"_sec2InitBuffers(pSec2Utils)",
                                     "src/kernel/gpu/mem_mgr/sec2_utils.c",0x114);
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar5,
                                     "memmgrMemUtilsSec2CtxInit_HAL(pGpu, pMemoryManager, pChannel)"
                                     ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0x109);
                        }
                      }
                      else {
                        nvAssertOkFailedNoLog
                                  (iVar5,
                                   "memmgrMemUtilsChannelInitialize_HAL(pGpu, pMemoryManager, pChannel)"
                                   ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0x100);
                      }
LAB_003d318a:
                      (**(code **)(lVar6 + 0x18))(lVar6,puVar7[0x2b],puVar7[2]);
                    }
                    else {
                      nvAssertOkFailedNoLog
                                (iVar5,"channelAllocSubdevice(pGpu, pChannel)",
                                 "src/kernel/gpu/mem_mgr/sec2_utils.c",0xfd);
                    }
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar5,
                               "channelSetupIDs(pChannel, pGpu, NV_FALSE, IS_MIG_IN_USE(pGpu))",
                               "src/kernel/gpu/mem_mgr/sec2_utils.c",0xeb);
                  }
                  goto LAB_003d2cc0;
                }
              }
              *(undefined4 *)(param_1 + 0x68) = 0;
              iVar5 = 0x40;
              portMemFree(puVar8);
            }
            else {
              portMemFree(puVar8);
            }
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,"gpuGetClassList(pGpu, &numClasses, NULL, ENG_SEC2)",
                   "src/kernel/gpu/mem_mgr/sec2_utils.c",0x39);
      }
      nvAssertOkFailedNoLog
                (iVar5,"_sec2GetClass(pGpu, &pSec2Utils->sec2Class)",
                 "src/kernel/gpu/mem_mgr/sec2_utils.c",0xe7);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar5,"clientSetHandleGenerator(pChannel->pRsClient, 1U, ~0U - 1U)",
                 "src/kernel/gpu/mem_mgr/sec2_utils.c",0xd4);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,"serverGetClientUnderLock(&g_resServ, pChannel->hClient, &pChannel->pRsClient)"
               ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0xd2);
  }
LAB_003d2cc0:
  (**(code **)(lVar6 + 0x18))(lVar6,puVar7[0x2b],puVar7[0x2b]);
LAB_003d2cd4:
  portMemFree(puVar7);
  return iVar5;
}


// ===== 003d32c0 sec2utilsDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void sec2utilsDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x60);
  puVar2 = *(undefined4 **)(param_1 + 0x58);
  if ((lVar1 == 0) || (puVar2 == (undefined4 *)0x0)) {
    pcVar6 = "NVRM: Possible double-free of Sec2Utils!\n";
    uVar4 = 3;
    uVar5 = 0x133;
  }
  else {
    if (*(long *)(puVar2 + 0x5e) == lVar1) {
      uVar4 = *(undefined8 *)(lVar1 + 0x1b78);
      lVar3 = rmapiGetInterface(4);
      ccslContextClear_IMPL(*(undefined8 *)(param_1 + 0x80));
      if ((*(char *)(puVar2 + 0x5c) != '\0') && (*(long *)(puVar2 + 0x3e) != 0)) {
        if (*(char *)(*(long *)(&DAT_00001b90 + lVar1) + 0xad0c) == '\0') {
          memmgrMemDescEndTransfer_IMPL(uVar4,*(undefined8 *)(puVar2 + 0x34),0x20);
          *(undefined8 *)(puVar2 + 0x3e) = 0;
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x149,"sec2utilsDestruct_IMPL",4,
                       "NVRM: Leaked USERD mapping from ceUtils!\n");
        }
      }
      if (*(long *)(puVar2 + 0x3a) != 0) {
        if (*(char *)(*(long *)(&DAT_00001b90 + lVar1) + 0xad0c) == '\0') {
          memmgrMemDescEndTransfer_IMPL(uVar4,*(undefined8 *)(puVar2 + 0x36),0x20);
          *(undefined8 *)(puVar2 + 0x3a) = 0;
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x156,"sec2utilsDestruct_IMPL",4,
                       "NVRM: Leaked pushbuffer mapping!\n");
        }
      }
      if (*(long *)(puVar2 + 0x50) != 0) {
        if (*(char *)(*(long *)(&DAT_00001b90 + lVar1) + 0xad0c) == '\0') {
          memmgrMemDescEndTransfer_IMPL(uVar4,*(undefined8 *)(puVar2 + 0x38),0x20);
          *(undefined8 *)(puVar2 + 0x50) = 0;
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x163,"sec2utilsDestruct_IMPL",4,
                       "NVRM: Leaked notifier mapping!\n");
        }
      }
      (**(code **)(lVar3 + 0x18))
                (lVar3,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x88));
      (**(code **)(lVar3 + 0x18))
                (lVar3,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x8c));
      (**(code **)(lVar3 + 0x18))
                (lVar3,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0xb0));
      (**(code **)(lVar3 + 0x18))
                (lVar3,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0xb4));
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],puVar2[2]);
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],puVar2[5]);
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],puVar2[8]);
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],puVar2[4]);
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],puVar2[0xb]);
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],*puVar2);
      (**(code **)(lVar3 + 0x18))(lVar3,puVar2[0x2b],puVar2[0x2b]);
      portMemFree(puVar2);
      return;
    }
    pcVar6 = "NVRM: Bad state during sec2Utils teardown!\n";
    uVar4 = 4;
    uVar5 = 0x138;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",uVar5,"sec2utilsDestruct_IMPL",uVar4,pcVar6);
  return;
}


// ===== 003d35f0 sec2utilsServiceInterrupts_IMPL =====

void sec2utilsServiceInterrupts_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_1 + 0x58);
  if (lVar1 != 0) {
    cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(*(long *)(lVar1 + 0x178) + 0x7a4));
    if (cVar2 != '\0') {
      channelServiceScrubberInterrupts(lVar1);
      return;
    }
  }
  osSchedule();
  return;
}


// ===== 003d3640 sec2utilsUpdateProgress_IMPL =====

ulong sec2utilsUpdateProgress_IMPL(long param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0x58), lVar3 == 0)) {
    nvAssertFailedNoLog("(pSec2Utils != NULL) && (pSec2Utils->pChannel != NULL)",
                        "src/kernel/gpu/mem_mgr/sec2_utils.c",0x28a);
    lVar3 = *(long *)(param_1 + 0x58);
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


// ===== 003d36c0 sec2utilsMemset_IMPL =====

int sec2utilsMemset_IMPL(long param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  long local_e0;
  int local_d8;
  undefined4 local_d4;
  undefined1 local_d0 [24];
  undefined1 local_b8 [24];
  undefined8 local_a0 [3];
  undefined4 local_88 [2];
  uint local_80 [4];
  undefined4 local_70;
  undefined4 local_68;
  
  lVar1 = *(long *)(param_1 + 0x58);
  plVar2 = (long *)*param_2;
  uVar8 = 0;
  do {
    uVar4 = (int)uVar8 + 0x20;
    *(undefined8 *)((long)local_a0 + uVar8) = 0;
    *(undefined8 *)((long)local_a0 + uVar8 + 8) = 0;
    *(undefined8 *)((long)local_a0 + uVar8 + 0x10) = 0;
    *(undefined8 *)((long)local_80 + (uVar8 - 8)) = 0;
    uVar8 = (ulong)uVar4;
  } while (uVar4 < 0x60);
  *(undefined8 *)((long)local_a0 + (ulong)uVar4) = 0;
  if (plVar2 == (long *)0x0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x223,"sec2utilsMemset_IMPL",4,
                 "NVRM: Invalid memdesc for Sec2Utils memset.\n");
  }
  else {
    iVar5 = memdescGetAddressSpace(plVar2);
    if ((iVar5 == 2) && (*plVar2 == *(long *)(*(long *)(param_1 + 0x58) + 0x178))) {
      uVar8 = plVar2[6];
      iVar5 = memdescGetPteArraySize(plVar2,1);
      if ((ulong)param_2[1] < uVar8) {
        if ((param_2[2] != 0) && ((ulong)param_2[2] <= uVar8 - param_2[1])) {
          uVar8 = plVar2[1];
          uVar13 = *(ulong *)(param_1 + 200) >> 5;
          uVar14 = uVar13 & 0xffffffff;
          uVar13 = (*(long *)(param_1 + 0x70) + 1U) % (uVar13 & 0xffffffff);
          uVar4 = sec2utilsUpdateProgress_IMPL(param_1);
          timeoutSet(*(long *)(param_1 + 0x60) + 0x1af0,local_d0,0,4);
          iVar6 = (int)((ulong)uVar4 % uVar14);
          while ((int)uVar13 == iVar6) {
            iVar6 = timeoutCheck(*(long *)(param_1 + 0x60) + 0x1af0,local_d0,0x247);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x24a,"sec2utilsMemset_IMPL",4,
                           "NVRM: Failed to finish previous scrub op before re-using method stream auth tag buf: lastCompleted = %d lastSubmitted = %lld\n"
                           ,uVar4,*(undefined8 *)(param_1 + 0x70));
              return iVar6;
            }
            uVar4 = sec2utilsUpdateProgress_IMPL(param_1);
            osSpinLoop();
            iVar6 = (int)((ulong)uVar4 % uVar14);
          }
          local_80[0] = *(int *)(param_1 + 0x70) + 1;
          *(ulong *)(param_1 + 0x70) = (ulong)local_80[0];
          local_70 = memdescGetAddressSpace(plVar2);
          local_68 = *(undefined4 *)((long)plVar2 + 0x74);
          uVar4 = *(uint *)(plVar2 + 0x2c);
          uVar14 = param_2[2];
          local_e0 = param_2[1];
          while( true ) {
            uVar9 = memdescGetPhysAddr(plVar2,1,local_e0);
            uVar10 = uVar14;
            if ((uVar8 >> 10 & 1) == 0 && iVar5 != 1) {
              uVar10 = (ulong)uVar4 - uVar9 % (ulong)uVar4;
            }
            uVar9 = 0x40000000;
            if (uVar14 < 0x40000001) {
              uVar9 = uVar14;
            }
            if (uVar10 < uVar9) {
              uVar9 = uVar10;
            }
            uVar10 = uVar9;
            nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x26d,"sec2utilsMemset_IMPL",1,
                         "NVRM: Sec2Utils Memset dstAddr: %llx,  size: %x\n");
            local_a0[1] = memdescGetPtePhysAddr(plVar2,1,local_e0);
            local_88[0] = (undefined4)uVar9;
            local_d8 = 0;
            local_d4 = 0;
            if (lVar1 == 0) break;
            uVar11 = *(undefined8 *)(*(long *)(lVar1 + 0x178) + 0x1b78);
            nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x1db,"_sec2utilsSubmitPushBuffer",1,
                         "NVRM: Actual size of copying to be pushed: %x\n",uVar9 & 0xffffffff);
            iVar6 = channelWaitForFreeEntry(lVar1,&local_d4);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x1e0,"_sec2utilsSubmitPushBuffer",
                           4,"NVRM: Cannot get putIndex.\n");
              goto LAB_003d3c0c;
            }
            bVar3 = false;
            if (*(long *)(lVar1 + 0xe8) == 0) {
              lVar12 = memmgrMemDescBeginTransfer_IMPL(uVar11,*(undefined8 *)(lVar1 + 0xd8),0x26);
              *(long *)(lVar1 + 0xe8) = lVar12;
              if (lVar12 == 0) {
                nvAssertFailedNoLog("pChannel->pbCpuVA != NULL",
                                    "src/kernel/gpu/mem_mgr/sec2_utils.c",0x1ea);
                iVar6 = 0xffff;
                goto LAB_003d3c0c;
              }
              bVar3 = true;
            }
            uVar10 = (ulong)(*(int *)(param_1 + 0xd8) + 1) %
                     (*(ulong *)(param_1 + 0xa0) >> 5 & 0xffffffff);
            timeoutSet(*(long *)(param_1 + 0x60) + 0x1af0,local_b8,0,4);
            iVar6 = *(int *)(param_1 + 0xdc);
            while (iVar6 == (int)uVar10) {
              iVar6 = timeoutCheck(*(long *)(param_1 + 0x60) + 0x1af0,local_b8,0x1b1);
              lVar12 = *(long *)(param_1 + 0x58);
              if (iVar6 != 0) {
                uVar11 = channelReadChannelMemdesc(lVar12,*(undefined4 *)(lVar12 + 0x54));
                nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x1b4,
                             "_sec2utilsGetNextAuthTagSlot",4,
                             "NVRM: Timed out waiting for next auth tag buf slot to free up: nextPut = %d get = %d\n"
                             ,uVar10,uVar11);
                nvAssertOkFailedNoLog
                          (iVar6,"_sec2utilsGetNextAuthTagSlot(pSec2Utils)",
                           "src/kernel/gpu/mem_mgr/sec2_utils.c",0x1ec);
                goto LAB_003d3c0c;
              }
              uVar7 = channelReadChannelMemdesc(lVar12,*(undefined4 *)(lVar12 + 0x54));
              *(undefined4 *)(param_1 + 0xdc) = uVar7;
              osSpinLoop();
              iVar6 = *(int *)(param_1 + 0xdc);
            }
            *(int *)(param_1 + 0xd8) = (int)uVar10;
            iVar6 = channelFillSec2Pb(lVar1,local_d4,uVar9 == uVar14,local_a0,
                                      *(undefined8 *)(param_1 + 0x80),
                                      *(undefined8 *)(param_1 + 0xa8),
                                      *(undefined8 *)(param_1 + 0xd0),
                                      *(undefined8 *)(param_1 + 0x98),uVar10,
                                      *(undefined8 *)(param_1 + 0xc0),uVar13,&local_d8);
            if (iVar6 != 0) {
              nvAssertOkFailedNoLog
                        (iVar6,
                         "channelFillSec2Pb(pChannel, putIndex, bInsertFinishPayload, pChannelPbInfo, pSec2Utils->pCcslCtx, pSec2Utils->scrubMthdAuthTagBuf.pMemDesc, pSec2Utils->semaMthdAuthTagBuf.pMemDesc, pSec2Utils->scrubMthdAuthTagBuf.gpuVA, pSec2Utils->authTagPutIndex, pSec2Utils->semaMthdAuthTagBuf.gpuVA, nextIndex, &methodsLength)"
                         ,"src/kernel/gpu/mem_mgr/sec2_utils.c",0x1ed);
              goto LAB_003d3c0c;
            }
            if (bVar3) {
              memmgrMemDescEndTransfer_IMPL(uVar11,*(undefined8 *)(lVar1 + 0xd8),0x26);
              *(undefined8 *)(lVar1 + 0xe8) = 0;
            }
            if (local_d8 == 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x1fa,"_sec2utilsSubmitPushBuffer",
                           4,"NVRM: Cannot push methods to channel.\n");
              iVar6 = 0x4f;
              goto LAB_003d3c0c;
            }
            iVar6 = channelFillGpFifo(lVar1,local_d4);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x205,"_sec2utilsSubmitPushBuffer",
                           4,"NVRM: Channel operation failures during memcopy\n");
              goto LAB_003d3c0c;
            }
            local_e0 = local_e0 + uVar9;
            *(undefined4 *)(lVar1 + 0x148) = local_d4;
            uVar14 = uVar14 - uVar9;
            if (uVar14 == 0) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x27d,"sec2utilsMemset_IMPL",1,
                           "NVRM: Async memset payload returned: 0x%x\n",local_80[0]);
              param_2[3] = (ulong)local_80[0];
              return 0;
            }
          }
          nvAssertFailedNoLog("pChannel != NULL","src/kernel/gpu/mem_mgr/sec2_utils.c",0x1cf,uVar10)
          ;
          iVar6 = 0x1f;
LAB_003d3c0c:
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x275,"sec2utilsMemset_IMPL",4,
                       "NVRM: Cannot submit push buffer for memset.\n");
          return iVar6;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x23a,"sec2utilsMemset_IMPL",4,
                     "NVRM: Invalid memset length passed.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x234,"sec2utilsMemset_IMPL",4,
                     "NVRM: Invalid offset passed for the memdesc.\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sec2_utils.c",0x22a,"sec2utilsMemset_IMPL",4,
                   "NVRM: Invalid memory descriptor passed.\n");
    }
  }
  return 0x1f;
}


// ===== 003d3f20 _semsurfGetValue =====

ulong _semsurfGetValue(long param_1,long param_2)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  
  puVar1 = (ulong *)(*(long *)(param_1 + 0x50) * param_2 + *(long *)(param_1 + 0x80));
  LOCK();
  UNLOCK();
  if (*(char *)(param_1 + 0xbc) != '\0') {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x4b,"_semsurfGetValue",1,
                 "NVRM:  Read semaphore surface value as 64-bit native\n");
    return *puVar1;
  }
  uVar3 = (ulong)(uint)*puVar1;
  LOCK();
  UNLOCK();
  puVar1 = (ulong *)(*(long *)(param_1 + 0x88) +
                    *(long *)(param_1 + 0x50) * param_2 + *(long *)(param_1 + 0x40));
  LOCK();
  uVar2 = *puVar1;
  *puVar1 = *puVar1;
  UNLOCK();
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x5d,"_semsurfGetValue",1,
               "NVRM:  Read maxSubmitted %llu and 32-bit semVal %llu from semaphore index %llu\n",
               uVar2,uVar3,param_2);
  if ((uVar2 & 0xffffffff) < uVar3) {
    uVar2 = uVar2 - 0x100000000;
  }
  return uVar2 & 0xffffffff00000000 | uVar3;
}


// ===== 003d4000 _semsurfSetValue =====

void _semsurfSetValue(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  ulong *puVar5;
  ulong *puVar6;
  
  lVar4 = *(long *)(param_1 + 0x50) * param_2;
  puVar6 = (ulong *)(*(long *)(param_1 + 0x80) + lVar4);
  if (*(char *)(param_1 + 0xbc) != '\0') {
    LOCK();
    UNLOCK();
    *puVar6 = param_3;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x7e,"_semsurfSetValue",1,
                 "NVRM:  Updated semaphore surface value as 64-bit native to %llu\n",param_3);
    return;
  }
  puVar5 = (ulong *)(lVar4 + *(long *)(param_1 + 0x40) + *(long *)(param_1 + 0x88));
  LOCK();
  UNLOCK();
  LOCK();
  uVar1 = *puVar5;
  *puVar5 = *puVar5;
  UNLOCK();
  uVar3 = uVar1;
  while (uVar3 < param_3) {
    LOCK();
    UNLOCK();
    LOCK();
    uVar2 = *puVar5;
    if (uVar3 == uVar2) {
      *puVar5 = param_3;
    }
    UNLOCK();
    if (uVar3 == uVar2) break;
    LOCK();
    uVar3 = *puVar5;
    *puVar5 = *puVar5;
    UNLOCK();
  }
  LOCK();
  UNLOCK();
  *(int *)puVar6 = (int)param_3;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0xa5,"_semsurfSetValue",1,
               "NVRM:  Updated maxSubmitted from %llu to %llu and 32-bit semVal %u at semaphore index %llu\n"
               ,uVar1,param_3,param_3,param_2);
  return;
}


// ===== 003d40d0 _semsurfNotifyCompleted =====

undefined1 _semsurfNotifyCompleted(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  undefined1 local_81;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x60) + 0xf0);
  uVar7 = listTail_IMPL(param_2);
  uVar8 = listHead_IMPL(param_2);
  listIterRange_IMPL(&local_78,param_2,uVar8,uVar7);
  local_81 = 0;
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  cVar5 = listIterNext_IMPL(&local_58);
  puVar3 = local_58;
  while (cVar5 != '\0') {
    local_58 = puVar3;
    uVar6 = osEventNotification(uVar2,puVar3[3],0,0,0);
    uVar7 = nvstatusToString(uVar6);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",199,"_semsurfNotifyCompleted",1,
                 "NVRM: SemMem(0x%08x, 0x%08x): Delivered OS events for value %llu at idx %llu. Status: %s (0x%08x)\n"
                 ,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x14),*puVar3,puVar3[2],
                 uVar7,uVar6);
    puVar4 = local_58;
    puVar9 = (undefined4 *)local_58[3];
    if (puVar9 != (undefined4 *)0x0) {
      puVar1 = local_58 + 3;
      do {
        unregisterEventNotificationWithData
                  (puVar1,*puVar9,0,puVar9[1],1,*(undefined8 *)(puVar9 + 10));
        puVar9 = (undefined4 *)puVar4[3];
      } while (puVar9 != (undefined4 *)0x0);
    }
    if (puVar3[1] != 0) {
      _semsurfSetValue(param_1,puVar3[2]);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0xeb,"_semsurfNotifyCompleted",1,
                   "NVRM: SemMem(0x%08x, 0x%08x): Value updated by waiter  to %llu at idx %llu\n",
                   *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x14),puVar3[1],puVar3[2])
      ;
      local_81 = 1;
    }
    listRemoveIntrusive_IMPL(param_2,local_58);
    portMemFree(local_58);
    listTail_IMPL(param_2);
    uVar7 = listHead_IMPL(param_2);
    listIterRange_IMPL(&local_78,param_2,uVar7);
    local_58 = local_78;
    local_50 = local_70;
    local_48 = local_68;
    local_40 = local_60;
    cVar5 = listIterNext_IMPL(&local_58);
    puVar3 = local_58;
  }
  return local_81;
}


// ===== 003d42e0 _semsurfSetMonitoredValue.part.0 =====

void _semsurfSetMonitoredValue_part_0(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x50);
  lVar2 = *(long *)(param_1 + 0x48);
  lVar3 = *(long *)(param_1 + 0x80);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x10f,"_semsurfSetMonitoredValue",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Setting monitored fence value at index %llu to %llu\n"
               ,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x14),param_2,param_3);
  LOCK();
  UNLOCK();
  *(undefined8 *)(lVar1 * param_2 + lVar2 + lVar3) = param_3;
  return;
}


// ===== 003d4350 _semsurfEventCallback =====

void _semsurfEventCallback
               (undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong extraout_RDX;
  ulong uVar8;
  ulong *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_90 [24];
  ulong *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  ulong *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x130,"_semsurfEventCallback",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Got a callback\n",*(undefined4 *)(param_1 + 1),
               *(undefined4 *)((long)param_1 + 0x14));
  puVar1 = param_1 + 0x13;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x131,"_semsurfEventCallback",1,
               "NVRM:   hEvent: 0x%08x surf event: 0x%08x, data 0x%08x, status 0x%08x\n",param_3,
               param_3,param_4,param_5);
  uVar6 = extraout_RDX;
LAB_003d43e0:
  listInitIntrusive_IMPL(local_90,0x30,uVar6);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x138,"_semsurfEventCallback",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Entering spinlock\n",*(undefined4 *)(param_1 + 1),
               *(undefined4 *)((long)param_1 + 0x14));
  portSyncSpinlockAcquire(*param_1);
  uVar4 = mapFindLEQ_IMPL(puVar1,0xffffffffffffffff);
  uVar5 = mapFindGEQ_IMPL(puVar1,0);
  mapIterRange_IMPL(&local_b8,puVar1,uVar5,uVar4);
  local_78 = local_b8;
  local_70 = local_b0;
  local_68 = local_a8;
  local_60 = local_a0;
  do {
    cVar2 = mapIterNext_IMPL(&local_78);
    while( true ) {
      if (cVar2 == '\0') {
        portSyncSpinlockRelease(*param_1);
        uVar6 = (ulong)*(uint *)((long)param_1 + 0x14);
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x172,"_semsurfEventCallback",1,
                     "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",*(undefined4 *)(param_1 + 1))
        ;
        cVar2 = _semsurfNotifyCompleted(param_1,local_90);
        if (cVar2 == '\0') {
          return;
        }
        goto LAB_003d43e0;
      }
      uVar4 = mapKey_IMPL(puVar1,local_78);
      uVar6 = _semsurfGetValue(param_1,uVar4);
      while( true ) {
        uVar5 = listTail_IMPL(local_78);
        uVar7 = listHead_IMPL(local_78);
        listIterRange_IMPL(&local_b8,local_78,uVar7,uVar5);
        local_58 = local_b8;
        local_50 = local_b0;
        local_48 = local_a8;
        local_40 = local_a0;
        cVar2 = listIterNext_IMPL(&local_58);
        if (cVar2 == '\0') break;
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x150,"_semsurfEventCallback",0,
                     "NVRM:   Checking index %llu value waiter %llu against semaphore value %llu\n",
                     uVar4,*local_58,uVar6);
        uVar8 = *local_58;
        if (uVar6 < uVar8) {
          iVar3 = listCount_IMPL(local_78);
          if (iVar3 != 0) goto LAB_003d46a0;
          if (uVar8 != 0xffffffffffffffff) {
            nvAssertFailedNoLog("minWaitValue == NV_U64_MAX","src/kernel/gpu/mem_mgr/sem_surf.c",
                                0x164);
          }
          goto LAB_003d459a;
        }
        listInsertExisting_IMPL(local_90,0);
        listRemoveIntrusive_IMPL(local_78,local_58);
      }
      uVar8 = 0xffffffffffffffff;
      iVar3 = listCount_IMPL(local_78);
      if (iVar3 != 0) break;
LAB_003d459a:
      mapRemoveIntrusive_IMPL(puVar1,local_78);
      portMemFree(local_78);
      if (*(char *)((long)param_1 + 0xbd) != '\0') {
        _semsurfSetMonitoredValue_part_0(param_1,uVar4,uVar8);
      }
      uVar4 = mapFindLEQ_IMPL(puVar1,0xffffffffffffffff);
      uVar5 = mapFindGEQ_IMPL(puVar1,0);
      mapIterRange_IMPL(&local_b8,puVar1,uVar5,uVar4);
      local_78 = local_b8;
      local_70 = local_b0;
      local_68 = local_a8;
      local_60 = local_a0;
      cVar2 = mapIterNext_IMPL(&local_78);
    }
LAB_003d46a0:
    if (*(char *)((long)param_1 + 0xbd) != '\0') {
      _semsurfSetMonitoredValue_part_0(param_1,uVar4,uVar8);
    }
  } while( true );
}


// ===== 003d4700 _semsurfDestroyShared =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void _semsurfDestroyShared(long *param_1)

{
  long *plVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar6 = rmapiGetInterface(4);
  if (param_1 == (long *)0x0) {
    return;
  }
  plVar1 = param_1 + 0x15;
  iVar5 = mapCount_IMPL(plVar1);
  if (iVar5 != 0) {
    nvAssertFailedNoLog("mapCount(&pShared->notifierMap) == 0","src/kernel/gpu/mem_mgr/sem_surf.c",
                        0x266);
  }
  while( true ) {
    uVar8 = mapFindLEQ_IMPL(plVar1,0xffffffffffffffff);
    uVar9 = mapFindGEQ_IMPL(plVar1,0);
    mapIterRange_IMPL(&local_68,plVar1,uVar9,uVar8);
    local_48 = local_68;
    local_40 = local_60;
    local_38 = local_58;
    local_30 = local_50;
    cVar4 = mapIterNext_IMPL(&local_48);
    piVar3 = local_48;
    if (cVar4 == '\0') break;
    lVar7 = rmapiGetInterface(4);
    iVar5 = *piVar3;
    if (iVar5 != 0) {
      (**(code **)(lVar7 + 0x18))(lVar7,iVar5,piVar3[1],*(code **)(lVar7 + 0x18));
    }
    mapRemoveIntrusive_IMPL(plVar1,local_48);
    portMemFree(local_48);
  }
  mapDestroyIntrusive_IMPL(plVar1);
  mapDestroyIntrusive_IMPL(param_1 + 0x13);
  if ((param_1[0xd] != 0) && (param_1[0xf] != 0)) {
    (**(code **)(lVar6 + 0x88))
              (lVar6,(int)param_1[1],*(undefined4 *)((long)param_1 + 0xc),(int)param_1[3],
               param_1[0xf],0,0);
    param_1[0xf] = 0;
    param_1[0x11] = 0;
  }
  if (param_1[0xc] != 0) {
    if (param_1[0xe] != 0) {
      (**(code **)(lVar6 + 0x88))
                (lVar6,(int)param_1[1],*(undefined4 *)((long)param_1 + 0xc),
                 *(undefined4 *)((long)param_1 + 0x14),param_1[0xe],0,0);
    }
    param_1[0xe] = 0;
    param_1[0x10] = 0;
  }
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  lVar6 = rmapiGetInterface(4);
  iVar5 = (int)param_1[1];
  if (iVar5 == 0) goto LAB_003d48f0;
  iVar2 = (int)param_1[3];
  if (iVar2 == 0) {
LAB_003d48e7:
    if (*(int *)((long)param_1 + 0x14) == 0) goto LAB_003d48f0;
    iVar5 = (int)param_1[1];
  }
  else if (iVar2 != *(int *)((long)param_1 + 0x14)) {
    (**(code **)(lVar6 + 0x18))(lVar6,iVar5,iVar2,*(code **)(lVar6 + 0x18));
    goto LAB_003d48e7;
  }
  (**(code **)(lVar6 + 0x18))(lVar6,iVar5);
LAB_003d48f0:
  *(undefined8 *)((long)param_1 + 0x14) = 0;
  if (*param_1 != 0) {
    portSyncSpinlockDestroy();
  }
  portMemFree(param_1);
  return;
}


// ===== 003d4960 _semsurfRemoveNotifyBinding =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 _semsurfRemoveNotifyBinding(long param_1,long param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  
  piVar2 = (int *)mapFind_IMPL(*(long *)(param_1 + 0x138) + 0xa8,param_2 << 0x20 | (ulong)param_3);
  if (piVar2 == (int *)0x0) {
    nvAssertFailedNoLog("pNotNode != NULL","src/kernel/gpu/mem_mgr/sem_surf.c",0x203);
  }
  else {
    if (piVar2[2] != 0) {
      iVar1 = piVar2[2] + -1;
      piVar2[2] = iVar1;
      if (iVar1 != 0) {
        return 0;
      }
      lVar3 = rmapiGetInterface(4);
      if (*piVar2 != 0) {
        (**(code **)(lVar3 + 0x18))(lVar3,*piVar2,piVar2[1],*(code **)(lVar3 + 0x18));
      }
      mapRemoveIntrusive_IMPL(*(long *)(param_1 + 0x138) + 0xa8,piVar2);
      portMemFree(piVar2);
      return 0;
    }
    nvAssertFailedNoLog("pNotNode->nUsers >= 1","src/kernel/gpu/mem_mgr/sem_surf.c",0x204);
  }
  return 0x40;
}


// ===== 003d4a76 _semsurfUnbindChannel.cold =====

void _semsurfUnbindChannel_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d4a80 _semsurfUnbindChannel =====

undefined4 _semsurfUnbindChannel(long param_1,long param_2)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  if (*(int *)(param_2 + 0x2c) != 0) {
    uVar5 = 0;
    uVar6 = 0;
    do {
      while( true ) {
        uVar4 = (ulong)uVar6;
        iVar3 = _semsurfRemoveNotifyBinding
                          (param_1,*(undefined4 *)(param_2 + 0x28),
                           *(undefined4 *)(param_2 + (uVar4 + 0xc) * 4));
        if (iVar3 == 0) break;
        uVar5 = 0x40;
        uVar6 = uVar6 + 1;
        if (*(uint *)(param_2 + 0x2c) <= uVar6) goto LAB_003d4b58;
      }
      if (param_1 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      uVar6 = uVar6 + 1;
      plVar1 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x22a,"_semsurfUnbindChannel",1,
                   "NVRM: SemSurf(0x%08x, 0x%08x): Unbound event for GPU instance 0x%08x notify index 0x%08x\n"
                   ,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],*(undefined4 *)(param_2 + 0x28),
                   *(undefined4 *)(param_2 + (uVar4 + 0xc) * 4));
    } while (uVar6 < *(uint *)(param_2 + 0x2c));
  }
LAB_003d4b58:
  mapRemoveIntrusive_IMPL(param_1 + 0x140,param_2);
  portMemFree(param_2);
  return uVar5;
}


// ===== 003d4b80 semsurfConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int semsurfConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  int *piVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  
  lVar6 = rmapiGetInterface(4);
  if (*(long *)(param_3 + 0x58) != 0) {
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                               __nvoc_class_def_SemaphoreSurface);
    lVar6 = *(long *)(lVar6 + 0x138);
    *(long *)(param_1 + 0x138) = lVar6;
    iVar5 = *(int *)(lVar6 + 0xb8);
    if (iVar5 == 0) {
      nvAssertFailedNoLog("pSemSurf->pShared->refCount > 0","src/kernel/gpu/mem_mgr/sem_surf.c",
                          0x249);
      lVar6 = *(long *)(param_1 + 0x138);
      iVar5 = *(int *)(lVar6 + 0xb8);
    }
    *(int *)(lVar6 + 0xb8) = iVar5 + 1;
    mapInitIntrusive_IMPL(param_1 + 0x140,0);
    plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x24e,"semsurfCopyConstruct",2,
                 "NVRM: SemSurf(0x%08x, 0x%08x): Copied with SemMem(0x%08x, 0x%08x)\n",
                 *(undefined4 *)(*plVar7 + 0x48),(int)plVar7[2],
                 *(undefined4 *)(*(long *)(param_1 + 0x138) + 8),
                 *(undefined4 *)(*(long *)(param_1 + 0x138) + 0x14));
    return 0;
  }
  piVar1 = *(int **)(param_3 + 0x40);
  if (*(long *)(piVar1 + 2) != 0) {
    nvCheckFailedNoLog(2,"pAllocParams->flags == 0ULL","src/kernel/gpu/mem_mgr/sem_surf.c",0x2c9);
    return 0x1f;
  }
  lVar10 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar2 = *(undefined8 *)(lVar10 + 0x1b78);
  plVar7 = (long *)portMemAllocNonPaged(0xc0);
  *(long **)(param_1 + 0x138) = plVar7;
  if (plVar7 == (long *)0x0) {
    nvAssertOkFailedNoLog(0x51,"pShared != NULL","src/kernel/gpu/mem_mgr/sem_surf.c",0x2ce);
  }
  else {
    portMemSet(plVar7,0,0xc0);
    *(undefined4 *)(plVar7 + 0x17) = 1;
    mapInitIntrusive_IMPL(plVar7 + 0x13,0x18);
    mapInitIntrusive_IMPL(plVar7 + 0x15,0x10);
    mapInitIntrusive_IMPL(param_1 + 0x140,0);
    uVar8 = portMemAllocatorGetGlobalNonPaged();
    lVar9 = portSyncSpinlockCreate(uVar8);
    *plVar7 = lVar9;
    if (lVar9 != 0) {
      iVar5 = memmgrGetInternalClientHandles_IMPL
                        (lVar10,uVar2,*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8),plVar7 + 1,
                         (long)plVar7 + 0xc,plVar7 + 2);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "memmgrGetInternalClientHandles(pGpu, pMemoryManager, GPU_RES_GET_DEVICE(pSemSurf), &pShared->hClient, &pShared->hDevice, &pShared->hSubdevice)"
                   ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x2d9);
        goto LAB_003d509b;
      }
      iVar5 = (**(code **)(lVar6 + 0x38))
                        (lVar6,(int)plVar7[1],(int)plVar7[2],0x20801352,plVar7 + 8,0x20);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "pRmApi->Control(pRmApi, pShared->hClient, pShared->hSubdevice, NV2080_CTRL_CMD_FB_GET_SEMAPHORE_SURFACE_LAYOUT, &pShared->layout, sizeof pShared->layout)"
                   ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x2de);
        goto LAB_003d509b;
      }
      *(byte *)((long)plVar7 + 0xbd) = (byte)*(uint *)(plVar7 + 0xb) & 1;
      *(byte *)((long)plVar7 + 0xbc) = (byte)(*(uint *)(plVar7 + 0xb) >> 1) & 1;
      lVar10 = serverutilGetClientUnderLock((int)plVar7[1]);
      if (lVar10 == 0) {
        nvAssertOkFailedNoLog(0x40,"pClient != NULL","src/kernel/gpu/mem_mgr/sem_surf.c",0x2eb);
        iVar5 = 0x40;
        goto LAB_003d509b;
      }
      lVar9 = *(long *)(param_1 + 0x138);
      uVar2 = *(undefined8 *)(lVar10 + 0x100);
      uVar8 = 0x3d4d24;
      lVar10 = rmapiGetInterface(4);
      iVar5 = (**(code **)(lVar10 + 0x50))
                        (lVar10,*(undefined4 *)(lVar9 + 8),*(undefined4 *)(lVar9 + 0xc),lVar9 + 0x14
                         ,*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                         *piVar1,0);
      if (iVar5 == 0) {
        iVar5 = piVar1[1];
        lVar3 = *(long *)(param_1 + 0x138);
        if (iVar5 == 0) {
          *(undefined4 *)(lVar3 + 0x18) = 0;
        }
        else {
          if (*(char *)(lVar3 + 0xbc) != '\0') {
            nvCheckFailedNoLog(2,"!pSemSurf->pShared->bIs64Bit","src/kernel/gpu/mem_mgr/sem_surf.c",
                               0x1ad);
            iVar5 = 0x3b;
            goto LAB_003d5050;
          }
          if (iVar5 == *piVar1) {
            *(undefined4 *)(lVar3 + 0x18) = *(undefined4 *)(lVar3 + 0x14);
          }
          else {
            iVar5 = (**(code **)(lVar10 + 0x50))
                              (lVar10,*(undefined4 *)(lVar9 + 8),*(undefined4 *)(lVar9 + 0xc),
                               lVar9 + 0x18,
                               *(undefined4 *)
                                (**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),iVar5,0);
            if (iVar5 != 0) {
              nvCheckOkFailedNoLog
                        (4,iVar5,
                         "pRmApi->DupObject(pRmApi, pShared->hClient, pShared->hDevice, &pShared->hMaxSubmittedMem, RES_GET_CLIENT_HANDLE(pSemSurf), pAllocParams->hMaxSubmittedMem, NV04_DUP_HANDLE_FLAGS_NONE)"
                         ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x1b3,uVar8);
              goto LAB_003d5050;
            }
          }
        }
        iVar5 = memGetByHandle_IMPL(uVar2,*(undefined4 *)((long)plVar7 + 0x14),plVar7 + 0xc);
        if (iVar5 == 0) {
          if ((*(uint *)(plVar7[0xc] + 0x188) & 0x6000000) == 0x2000000) {
            iVar5 = (**(code **)(lVar6 + 0x70))
                              (lVar6,(int)plVar7[1],*(undefined4 *)((long)plVar7 + 0xc),
                               *(undefined4 *)((long)plVar7 + 0x14),0,
                               *(undefined8 *)(*(long *)(plVar7[0xc] + 0x118) + 0x30),plVar7 + 0xe,0
                              );
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "pRmApi->MapToCpu(pRmApi, pShared->hClient, pShared->hDevice, pShared->hSemaphoreMem, 0, pShared->pSemaphoreMem->pMemDesc->Size, &pShared->semKernAddr, 0)"
                         ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x301);
              goto LAB_003d509b;
            }
            lVar10 = plVar7[0xc];
            uVar11 = *(ulong *)(*(long *)(lVar10 + 0x118) + 0x30) / (ulong)plVar7[10];
            plVar7[0x10] = plVar7[0xe];
            plVar7[0x12] = uVar11;
            if (*(char *)((long)plVar7 + 0xbc) != '\0') {
LAB_003d4e7d:
              plVar7[5] = (long)_semsurfEventCallback;
              plVar7[6] = (long)plVar7;
              if (uVar11 != 0) {
                uVar11 = 0;
                do {
                  if (*(char *)((long)plVar7 + 0xbd) != '\0') {
                    _semsurfSetMonitoredValue_part_0(plVar7,uVar11,0xffffffffffffffff);
                  }
                  uVar11 = uVar11 + 1;
                } while (uVar11 < (ulong)plVar7[0x12]);
              }
              plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x359,"semsurfConstruct_IMPL",1,
                           "NVRM: SemSurf(0x%08x, 0x%08x): Constructed with SemMem(0x%08x, 0x%08x)\n"
                           ,*(undefined4 *)(*plVar4 + 0x48),(int)plVar4[2],(int)plVar7[1],
                           *(undefined4 *)((long)plVar7 + 0x14));
              return 0;
            }
            if (*(int *)((long)plVar7 + 0x14) == (int)plVar7[3]) {
              plVar7[0x11] = plVar7[0xe];
              plVar7[0xd] = lVar10;
            }
            else {
              iVar5 = memGetByHandle_IMPL(uVar2,(int)plVar7[3],plVar7 + 0xd);
              if (iVar5 != 0) {
                nvAssertOkFailedNoLog
                          (iVar5,
                           "memGetByHandle(pRsClient, pShared->hMaxSubmittedMem, &pShared->pMaxSubmittedMem)"
                           ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x315);
                goto LAB_003d509b;
              }
              uVar11 = *(ulong *)(*(long *)(plVar7[0xd] + 0x118) + 0x30);
              if (uVar11 < *(ulong *)(*(long *)(plVar7[0xc] + 0x118) + 0x30)) {
                nvCheckFailedNoLog(4,
                                   "pShared->pMaxSubmittedMem->pMemDesc->Size >= pShared->pSemaphoreMem->pMemDesc->Size"
                                   ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x319);
                iVar5 = 2;
                goto LAB_003d509b;
              }
              iVar5 = (**(code **)(lVar6 + 0x70))
                                (lVar6,(int)plVar7[1],*(undefined4 *)((long)plVar7 + 0xc),
                                 (int)plVar7[3],0,uVar11,plVar7 + 0xf,0);
              if (iVar5 != 0) {
                nvAssertOkFailedNoLog
                          (iVar5,
                           "pRmApi->MapToCpu(pRmApi, pShared->hClient, pShared->hDevice, pShared->hMaxSubmittedMem, 0, pShared->pMaxSubmittedMem->pMemDesc->Size, &pShared->maxSubmittedKernAddr, 0)"
                           ,"src/kernel/gpu/mem_mgr/sem_surf.c",799);
                goto LAB_003d509b;
              }
              lVar10 = plVar7[0xd];
              uVar12 = *(ulong *)(*(long *)(lVar10 + 0x118) + 0x30) / (ulong)plVar7[10];
              uVar11 = plVar7[0x12];
              if (uVar12 < (ulong)plVar7[0x12]) {
                uVar11 = uVar12;
              }
              plVar7[0x12] = uVar11;
              plVar7[0x11] = plVar7[0xf];
            }
            if ((*(uint *)(lVar10 + 0x188) & 0x6000000) == 0x2000000) {
              if ((*(uint *)(lVar10 + 0x188) & 0xa0000000) != 0) {
                uVar11 = plVar7[0x12];
                goto LAB_003d4e7d;
              }
              nvCheckFailedNoLog(4,
                                 "(maxSubmittedCoherency != NVOS32_ATTR_COHERENCY_UNCACHED) && (maxSubmittedCoherency != NVOS32_ATTR_COHERENCY_WRITE_COMBINE)"
                                 ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x347);
            }
            else {
              nvCheckFailedNoLog(4,
                                 "DRF_VAL(OS32, _ATTR, _LOCATION, pShared->pMaxSubmittedMem->Attr) == NVOS32_ATTR_LOCATION_PCI"
                                 ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x33b);
            }
          }
          else {
            nvCheckFailedNoLog(4,
                               "DRF_VAL(OS32, _ATTR, _LOCATION, pShared->pSemaphoreMem->Attr) == NVOS32_ATTR_LOCATION_PCI"
                               ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x2fa);
          }
          iVar5 = 0x3b;
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "memGetByHandle(pRsClient, pShared->hSemaphoreMem, &pShared->pSemaphoreMem)",
                     "src/kernel/gpu/mem_mgr/sem_surf.c",0x2f3);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar5,
                   "pRmApi->DupObject(pRmApi, pShared->hClient, pShared->hDevice, &pShared->hSemaphoreMem, RES_GET_CLIENT_HANDLE(pSemSurf), pAllocParams->hSemaphoreMem, NV04_DUP_HANDLE_FLAGS_NONE)"
                   ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x1a2);
LAB_003d5050:
        nvCheckOkFailedNoLog
                  (2,iVar5,"_semsurfDupMemory(pSemSurf, pAllocParams)",
                   "src/kernel/gpu/mem_mgr/sem_surf.c",0x2ef);
      }
      goto LAB_003d509b;
    }
    nvAssertOkFailedNoLog
              (0x51,"pShared->pSpinlock != NULL","src/kernel/gpu/mem_mgr/sem_surf.c",0x2d7);
  }
  iVar5 = 0x51;
LAB_003d509b:
  mapDestroyIntrusive_IMPL(param_1 + 0x140);
  _semsurfDestroyShared(plVar7);
  return iVar5;
}


// ===== 003d53e0 semsurfDestruct_IMPL =====

void semsurfDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  ulong *puVar11;
  undefined8 extraout_RDX;
  undefined8 uVar12;
  int *piVar13;
  ulong uVar14;
  ulong *puVar15;
  
  plVar4 = *(long **)(param_1 + 0x138);
  if (*plVar4 == 0) {
    nvAssertFailedNoLog("pShared->pSpinlock","src/kernel/gpu/mem_mgr/sem_surf.c",0x37e);
    iVar8 = (int)plVar4[0x17];
  }
  else {
    uVar1 = *(undefined4 *)((long)plVar4 + 0x14);
    plVar5 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    iVar8 = (int)plVar5[2];
    uVar2 = (undefined4)plVar4[1];
    iVar3 = *(int *)(*plVar5 + 0x48);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x380,"semsurfDestruct_IMPL",1,
                 "NVRM: SemSurf(0x%08x, 0x%08x): Destructor with SemMem(0x%08x, 0x%08x)\n",iVar3,
                 iVar8,uVar2,uVar1);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x385,"semsurfDestruct_IMPL",1,
                 "NVRM: SemMem(0x%08x, 0x%08x): Entering spinlock\n",uVar2,uVar1);
    portSyncSpinlockAcquire(*plVar4);
    plVar5 = plVar4 + 0x13;
    lVar9 = mapFindGEQ_IMPL(plVar5,0);
    while (lVar9 != 0) {
      uVar14 = 0xffffffffffffffff;
      lVar10 = mapKey_IMPL(plVar5,lVar9);
      puVar11 = (ulong *)listHead_IMPL(lVar9);
joined_r0x003d54f9:
      puVar15 = puVar11;
      if (puVar11 != (ulong *)0x0) {
        do {
          piVar6 = (int *)puVar15[3];
          while (piVar13 = piVar6, piVar6 != (int *)0x0) {
            while ((piVar6 = *(int **)(piVar13 + 0x10), *piVar13 != iVar3 || (piVar13[1] != iVar8)))
            {
              piVar13 = piVar6;
              if (piVar6 == (int *)0x0) goto LAB_003d55c6;
            }
            nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x39e,"semsurfDestruct_IMPL",3,
                         "NVRM: SemSurf(0x%08x, 0x%08x): Deleting active waiter at index %llu value %llu\n"
                         ,iVar3,iVar8,lVar10,*puVar15);
            unregisterEventNotificationWithData
                      (puVar15 + 3,iVar3,0,iVar8,1,*(undefined8 *)(piVar13 + 10));
          }
LAB_003d55c6:
          puVar11 = (ulong *)listNext_IMPL(lVar9,puVar15);
          if ((puVar15[3] == 0) && (puVar15[1] == 0)) goto code_r0x003d55f7;
          if (*puVar15 < uVar14) {
            uVar14 = *puVar15;
          }
          puVar15 = puVar11;
          if (puVar11 == (ulong *)0x0) break;
        } while( true );
      }
      if (*(char *)((long)plVar4 + 0xbd) != '\0') {
        _semsurfSetMonitoredValue_part_0(plVar4,lVar10,uVar14);
      }
      iVar7 = listCount_IMPL(lVar9);
      if (iVar7 == 0) {
        if (uVar14 != 0xffffffffffffffff) {
          nvAssertFailedNoLog("minWaitValue == NV_U64_MAX","src/kernel/gpu/mem_mgr/sem_surf.c",0x3c5
                             );
        }
        mapRemoveIntrusive_IMPL(plVar5,lVar9);
        portMemFree(lVar9);
      }
      lVar9 = mapFindGEQ_IMPL(plVar5,lVar10 + 1);
    }
    portSyncSpinlockRelease(*plVar4);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x3cc,"semsurfDestruct_IMPL",1,
                 "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",uVar2,uVar1);
    uVar12 = 0x3d56a3;
    while (lVar9 = mapFindGEQ_IMPL(param_1 + 0x140,0,uVar12), lVar9 != 0) {
      _semsurfUnbindChannel(param_1);
      uVar12 = extraout_RDX;
    }
    mapDestroyIntrusive_IMPL(param_1 + 0x140);
    iVar8 = (int)plVar4[0x17];
  }
  if (iVar8 == 0) {
    nvAssertFailedNoLog("pShared->refCount > 0","src/kernel/gpu/mem_mgr/sem_surf.c",0x3d5);
    iVar8 = (int)plVar4[0x17];
  }
  *(int *)(plVar4 + 0x17) = iVar8 + -1;
  if (iVar8 + -1 != 0) {
    return;
  }
  _semsurfDestroyShared(plVar4);
  return;
code_r0x003d55f7:
  listRemoveIntrusive_IMPL(lVar9,puVar15);
  portMemFree(puVar15);
  goto joined_r0x003d54f9;
}


// ===== 003d5799 semsurfCtrlCmdRefMemory_IMPL.cold =====

void semsurfCtrlCmdRefMemory_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d57b0 semsurfCtrlCmdRefMemory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int semsurfCtrlCmdRefMemory_IMPL(long param_1,int *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int local_40;
  int local_3c [3];
  
  lVar7 = rmapiGetInterface(4);
  lVar2 = *(long *)(param_1 + 0x138);
  local_40 = *param_2;
  local_3c[0] = param_2[1];
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe8);
  if (lVar3 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  uVar1 = *(undefined4 *)(*(long *)(*(long *)(lVar3 + 0x110) + 0x48) + 0x10);
  iVar5 = (**(code **)(lVar7 + 0x50))
                    (lVar7,*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                     uVar1,&local_40,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x14),0);
  if (iVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar5,
               "pRmApi->DupObject(pRmApi, RES_GET_CLIENT_HANDLE(pSemSurf), hDeviceDst, &hSemMemOut, pShared->hClient, pShared->hSemaphoreMem, 0)"
               ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x3eb);
    return iVar5;
  }
  if (*(long *)(lVar2 + 0x68) == 0) {
    iVar5 = local_3c[0];
    if (param_2[1] != 0) {
      return 0x3b;
    }
  }
  else if (*(long *)(lVar2 + 0x68) == *(long *)(lVar2 + 0x60)) {
    iVar5 = local_40;
    if (param_2[1] != *param_2) {
      iVar6 = 0x3b;
LAB_003d590e:
      (**(code **)(lVar7 + 0x18))
                (lVar7,*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                 local_40);
      return iVar6;
    }
  }
  else {
    iVar6 = (**(code **)(lVar7 + 0x50))
                      (lVar7,*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                       uVar1,local_3c,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x18),0);
    iVar5 = local_3c[0];
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "pRmApi->DupObject(pRmApi, RES_GET_CLIENT_HANDLE(pSemSurf), hDeviceDst, &hMaxMemOut, pShared->hClient, pShared->hMaxSubmittedMem, 0)"
                 ,"src/kernel/gpu/mem_mgr/sem_surf.c",0x3fc);
      goto LAB_003d590e;
    }
  }
  *param_2 = local_40;
  param_2[1] = iVar5;
  return 0;
}


// ===== 003d5961 semsurfCtrlCmdBindChannel_IMPL.cold =====

void semsurfCtrlCmdBindChannel_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d5970 semsurfCtrlCmdBindChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int semsurfCtrlCmdBindChannel_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  long *plVar7;
  code *pcVar8;
  long lVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  int *piVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  char *pcVar18;
  ulong uVar19;
  uint local_6c;
  undefined4 local_5c;
  long local_58;
  int local_50 [2];
  undefined4 local_48;
  uint local_44;
  long local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)invalidInstructionException();
    (*pcVar8)();
  }
  lVar14 = **(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar17 = 0;
  if (lVar14 != 0) {
    uVar17 = *(undefined8 *)(lVar14 + 0x40);
  }
  iVar11 = CliGetKernelChannel(uVar17,*param_2,&local_58);
  if (iVar11 == 0) {
    if ((uint)param_2[1] < 9) {
      lVar14 = *(long *)(*(long *)(local_58 + 0x158) + 0xe0);
      uVar3 = *(undefined4 *)(lVar14 + 0x7a4);
      local_6c = 0;
      if (param_2[1] != 0) {
        local_6c = 0;
        do {
          uVar4 = param_2[(ulong)local_6c + 2];
          lVar13 = mapFind_IMPL(*(long *)(param_1 + 0x138) + 0xa8,CONCAT44(uVar3,uVar4));
          if (lVar13 == 0) {
            piVar15 = (int *)portMemAllocNonPaged(0x38);
            if (piVar15 == (int *)0x0) {
              pcVar18 = 
              "NVRM: SemSurf(0x%08x, 0x%08x): Failed to allocate an event notifier map node\n";
              uVar17 = 0x47b;
              plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
              uVar6 = (undefined4)plVar7[2];
              uVar4 = *(undefined4 *)(*plVar7 + 0x48);
              goto LAB_003d5eb4;
            }
            portMemSet(piVar15,0,0x38);
            lVar9 = local_58;
            uVar5 = param_2[(ulong)local_6c + 2];
            lVar13 = *(long *)(param_1 + 0x138);
            puVar16 = (undefined8 *)rmapiGetInterface(4);
            local_5c = 0;
            iVar11 = memmgrGetInternalClientHandles_IMPL
                               (lVar14,*(undefined8 *)(lVar14 + 0x1b78),
                                *(undefined8 *)(*(long *)(lVar9 + 0x158) + 0xe8),piVar15,0,&local_5c
                               );
            if (iVar11 == 0) {
              portMemSet(local_50,0,0x18);
              local_50[0] = *piVar15;
              local_48 = 0x7e;
              local_40 = lVar13 + 0x28;
              uVar12 = gpumgrGetSubDeviceInstanceFromGpu(lVar14);
              local_44 = (uVar12 & 0xff) << 0x10 | uVar5 | 0x38000000;
              iVar11 = (*(code *)*puVar16)(puVar16,*piVar15,local_5c,piVar15 + 1,0x7e,local_50);
              if (iVar11 == 0) {
                piVar15[2] = 1;
                uVar17 = 0x3d5d55;
                cVar10 = mapInsertExisting_IMPL
                                   (*(long *)(param_1 + 0x138) + 0xa8,CONCAT44(uVar3,uVar4));
                plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
                uVar4 = (undefined4)plVar7[2];
                uVar6 = *(undefined4 *)(*plVar7 + 0x48);
                if (cVar10 == '\0') {
                  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x495,
                               "semsurfCtrlCmdBindChannel_IMPL",3,
                               "NVRM: SemSurf(0x%08x, 0x%08x): Duplicate entry found for new event notifier map node\n"
                               ,uVar6,uVar4);
                  lVar14 = rmapiGetInterface(4);
                  if (*piVar15 != 0) {
                    (**(code **)(lVar14 + 0x18))
                              (lVar14,*piVar15,piVar15[1],*(code **)(lVar14 + 0x18),uVar17);
                  }
                  portMemFree(piVar15);
                  goto LAB_003d5bc8;
                }
                nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x4a1,
                             "semsurfCtrlCmdBindChannel_IMPL",1,
                             "NVRM: SemSurf(0x%08x, 0x%08x): Bound to new event for GPU instance 0x%08x notify index 0x%08x\n"
                             ,uVar6,uVar4,uVar3,param_2[(ulong)local_6c + 2]);
                goto LAB_003d5aa4;
              }
              uVar17 = 0x1eb;
              pcVar18 = 
              "pRmApi->Alloc(pRmApi, pNotNode->hClient, hSubdevice, &pNotNode->hEvent, NV01_EVENT_KERNEL_CALLBACK_EX, &nv0005AllocParams, sizeof(nv0005AllocParams))"
              ;
            }
            else {
              uVar17 = 0x1d9;
              pcVar18 = 
              "memmgrGetInternalClientHandles(pGpu, GPU_GET_MEMORY_MANAGER(pGpu), GPU_RES_GET_DEVICE(pKernelChannel), &pNotNode->hClient, NULL, &hSubdevice)"
              ;
            }
            nvAssertOkFailedNoLog(iVar11,pcVar18,"src/kernel/gpu/mem_mgr/sem_surf.c",uVar17);
            portMemFree(piVar15);
            uVar19 = (ulong)local_6c;
            goto LAB_003d5bce;
          }
          iVar11 = *(int *)(lVar13 + 8);
          if (iVar11 == 0) {
            nvAssertFailedNoLog("pNotNode->nUsers >= 1","src/kernel/gpu/mem_mgr/sem_surf.c",0x45d);
            iVar11 = *(int *)(lVar13 + 8);
          }
          if (iVar11 == -1) {
            plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
            nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x461,"semsurfCtrlCmdBindChannel_IMPL",
                         3,
                         "NVRM: SemSurf(0x%08x, 0x%08x): GPU instance 0x%08x notify index 0x%08x number of bound channels at max\n"
                         ,*(undefined4 *)(*plVar7 + 0x48),(int)plVar7[2],uVar3,
                         param_2[(ulong)local_6c + 2]);
LAB_003d5bc8:
            uVar19 = (ulong)local_6c;
            iVar11 = 0x40;
            goto LAB_003d5bce;
          }
          *(int *)(lVar13 + 8) = iVar11 + 1;
          plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x46e,"semsurfCtrlCmdBindChannel_IMPL",1,
                       "NVRM: SemSurf(0x%08x, 0x%08x): Bound to existing event for GPU instance 0x%08x notify index 0x%08x\n"
                       ,*(undefined4 *)(*plVar7 + 0x48),(int)plVar7[2],uVar3,
                       param_2[(ulong)local_6c + 2]);
LAB_003d5aa4:
          local_6c = local_6c + 1;
        } while (local_6c < (uint)param_2[1]);
      }
      lVar14 = portMemAllocNonPaged(0x50);
      if (lVar14 == 0) {
        uVar17 = 0x4ab;
        pcVar18 = 
        "NVRM: SemSurf(0x%08x, 0x%08x): Failed to allocate an channel binding map node for channel 0x%08x\n"
        ;
        plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
        uVar4 = *(undefined4 *)(*plVar7 + 0x48);
        uVar6 = (undefined4)plVar7[2];
LAB_003d5eb4:
        iVar11 = 0x51;
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",uVar17,"semsurfCtrlCmdBindChannel_IMPL",3,
                     pcVar18,uVar4,uVar6);
        uVar19 = (ulong)local_6c;
      }
      else {
        *(undefined4 *)(lVar14 + 0x28) = uVar3;
        uVar5 = param_2[1];
        *(uint *)(lVar14 + 0x2c) = uVar5;
        lVar13 = (ulong)uVar5 * 4;
        portMemCopy(lVar14 + 0x30,lVar13,param_2 + 2,lVar13);
        cVar10 = mapInsertExisting_IMPL(param_1 + 0x140,*param_2,lVar14);
        if (cVar10 != '\0') {
          return 0;
        }
        iVar11 = 0x19;
        plVar7 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x4c1,"semsurfCtrlCmdBindChannel_IMPL",3,
                     "NVRM: SemSurf(0x%08x, 0x%08x): Attempt to register duplicate channel binding for channel 0x%08x\n"
                     ,*(undefined4 *)(*plVar7 + 0x48),(int)plVar7[2],*param_2);
        portMemFree(lVar14);
        uVar19 = (ulong)local_6c;
      }
LAB_003d5bce:
      if ((int)uVar19 != 0) {
        puVar2 = param_2 + uVar19;
        do {
          puVar1 = param_2 + 2;
          param_2 = param_2 + 1;
          _semsurfRemoveNotifyBinding(param_1,uVar3,*puVar1);
        } while (param_2 != puVar2);
      }
    }
    else {
      iVar11 = 0x3b;
    }
  }
  else {
    nvCheckOkFailedNoLog
              (1,iVar11,"CliGetKernelChannel(pRsClient, pParams->hChannel, &pKernelChannel)",
               "src/kernel/gpu/mem_mgr/sem_surf.c",0x447);
  }
  return iVar11;
}


// ===== 003d5f8a semsurfCtrlCmdUnbindChannel_IMPL.cold =====

void semsurfCtrlCmdUnbindChannel_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d5fa0 semsurfCtrlCmdUnbindChannel_IMPL =====

ulong semsurfCtrlCmdUnbindChannel_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 local_20 [8];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar4 = **(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar5 = 0;
  if (lVar4 != 0) {
    uVar5 = *(undefined8 *)(lVar4 + 0x40);
  }
  uVar2 = CliGetKernelChannel(uVar5,*param_2,local_20);
  if (uVar2 == 0) {
    uVar3 = 0x3b;
    if ((uint)param_2[1] < 9) {
      lVar4 = mapFind_IMPL(param_1 + 0x140,*param_2);
      if (lVar4 == 0) {
        nvCheckFailedNoLog(1,"pChannelNode != NULL","src/kernel/gpu/mem_mgr/sem_surf.c",0x4f3);
        uVar3 = 0x31;
      }
      else {
        uVar3 = _semsurfUnbindChannel(param_1,lVar4);
      }
    }
    return uVar3;
  }
  nvCheckOkFailedNoLog
            (1,uVar2,"CliGetKernelChannel(pRsClient, pParams->hChannel, &pKernelChannel)",
             "src/kernel/gpu/mem_mgr/sem_surf.c",0x4e9);
  return (ulong)uVar2;
}


// ===== 003d6080 _semsurfSetValueAndNotify =====

undefined8 _semsurfSetValueAndNotify(long param_1,undefined8 param_2,ulong param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  undefined8 *puVar6;
  ulong uVar7;
  ulong uVar8;
  bool bVar9;
  undefined8 uVar10;
  ulong *local_98 [5];
  undefined1 local_70 [24];
  ulong *local_58 [5];
  
  _semsurfSetValue(*(undefined8 *)(param_1 + 0x138));
  uVar8 = extraout_RDX;
  do {
    listInitIntrusive_IMPL(local_70,0x30,uVar8);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x50e,"_semsurfSetValueAndNotify",1,
                 "NVRM: SemMem(0x%08x, 0x%08x): Entering spinlock\n",
                 *(undefined4 *)(*(long *)(param_1 + 0x138) + 8));
    portSyncSpinlockAcquire(**(undefined8 **)(param_1 + 0x138));
    lVar4 = mapFind_IMPL(*(long *)(param_1 + 0x138) + 0x98,param_2);
    uVar7 = param_3;
    if (lVar4 == 0) {
      puVar6 = *(undefined8 **)(param_1 + 0x138);
      bVar9 = true;
    }
    else {
      uVar10 = listTail_IMPL(lVar4);
      uVar5 = listHead_IMPL(lVar4);
      listIterRange_IMPL(local_98,lVar4,uVar5,uVar10);
      while (local_58[0] = local_98[0], cVar2 = listIterNext_IMPL(local_58), cVar2 != '\0') {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x51c,"_semsurfSetValueAndNotify",0,
                     "NVRM:   Checking index %llu value waiter %llu against semaphore value %llu from CPU write\n"
                     ,param_2,*local_58[0],param_3);
        uVar8 = *local_58[0];
        if (param_3 < uVar8) {
          iVar3 = listCount_IMPL(lVar4);
          if (iVar3 != 0) goto LAB_003d6314;
          if (uVar8 != 0xffffffffffffffff) {
            nvAssertFailedNoLog("minWaitValue == NV_U64_MAX","src/kernel/gpu/mem_mgr/sem_surf.c",
                                0x536);
          }
          goto LAB_003d62f6;
        }
        listInsertExisting_IMPL(local_70,0);
        listRemoveIntrusive_IMPL(lVar4,local_58[0]);
        uVar8 = local_58[0][1];
        if ((uVar8 != 0) && (bVar9 = uVar8 < uVar7, uVar7 = uVar8, bVar9)) {
          nvAssertFailedNoLog("vlIter.pValue->newValue >= newValue",
                              "src/kernel/gpu/mem_mgr/sem_surf.c",0x528);
          uVar7 = local_58[0][1];
        }
        listTail_IMPL(lVar4);
        uVar10 = listHead_IMPL(lVar4);
        listIterRange_IMPL(local_98,lVar4,uVar10);
      }
      uVar8 = 0xffffffffffffffff;
      iVar3 = listCount_IMPL(lVar4);
      if (iVar3 == 0) {
LAB_003d62f6:
        mapRemoveIntrusive_IMPL(*(long *)(param_1 + 0x138) + 0x98,lVar4);
        portMemFree(lVar4);
      }
LAB_003d6314:
      puVar6 = *(undefined8 **)(param_1 + 0x138);
      bVar9 = uVar7 <= param_3;
      if (*(char *)((long)puVar6 + 0xbd) != '\0') {
        _semsurfSetMonitoredValue_part_0(puVar6,param_2,uVar8);
        puVar6 = *(undefined8 **)(param_1 + 0x138);
      }
    }
    uVar10 = 0x3d6144;
    portSyncSpinlockRelease(*puVar6);
    uVar8 = (ulong)*(uint *)(*(long *)(param_1 + 0x138) + 0x14);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x53f,"_semsurfSetValueAndNotify",1,
                 "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",
                 *(undefined4 *)(*(long *)(param_1 + 0x138) + 8));
    bVar1 = _semsurfNotifyCompleted(*(undefined8 *)(param_1 + 0x138),local_70);
    param_3 = uVar7;
    if (((bVar1 & 1) == 0) || (!bVar9)) {
      if (bVar1 == 0) {
        return 0;
      }
    }
    else {
      nvAssertFailedNoLog("!valueChanged || (newValue > curValue)",
                          "src/kernel/gpu/mem_mgr/sem_surf.c",0x549,uVar10);
      uVar8 = extraout_RDX_00;
    }
  } while( true );
}


// ===== 003d63c5 semsurfCtrlCmdRegisterWaiter_IMPL.cold =====

void semsurfCtrlCmdRegisterWaiter_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d63d0 semsurfCtrlCmdRegisterWaiter_IMPL =====

uint semsurfCtrlCmdRegisterWaiter_IMPL(long param_1,ulong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulong uVar3;
  long *plVar4;
  ulong uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  ulong *puVar11;
  ulong uVar12;
  undefined8 uVar13;
  ulong uVar14;
  long lVar15;
  ulong *puVar16;
  long lVar17;
  undefined8 *puVar18;
  uint uVar19;
  ulong uVar20;
  ulong uVar21;
  bool bVar22;
  undefined1 auVar23 [16];
  undefined8 uVar24;
  ulong local_98;
  ulong *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulong local_60;
  ulong *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar24 = 0x3d63f6;
  lVar10 = resservGetTlsCallContext();
  uVar21 = *param_2;
  local_60 = 0;
  if (*(ulong *)(*(long *)(param_1 + 0x138) + 0x90) <= uVar21) {
    nvCheckFailedNoLog(4,"_semsurfValidateIndex(pSemSurf->pShared, pParams->index)",
                       "src/kernel/gpu/mem_mgr/sem_surf.c",0x69d);
    return 0x2c;
  }
  iVar9 = *(int *)(lVar10 + 0x2c);
  uVar20 = param_2[3];
  uVar3 = local_60;
  if ((uVar20 != 0) && (uVar3 = uVar20, iVar9 != 1)) {
    uVar24 = 0x3d683b;
    uVar19 = osUserHandleToKernelPtr(*(undefined4 *)(*(long *)(lVar10 + 8) + 0x48),uVar20,&local_60)
    ;
    if (uVar19 != 0) {
      uVar24 = nvstatusToString(uVar19);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x6b1,"semsurfCtrlCmdRegisterWaiter_IMPL",4,
                   "NVRM: Invalid semaphore surface notification handle: 0x%016llx, status: %s (0x%08x)\n"
                   ,param_2[3],uVar24,uVar19);
      return uVar19;
    }
    uVar21 = *param_2;
    uVar20 = local_60;
    uVar3 = local_60;
  }
  local_60 = uVar3;
  uVar3 = param_2[2];
  uVar14 = param_2[1];
  plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar1 = (undefined4)plVar4[2];
  lVar10 = *plVar4;
  if (lVar10 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar10 = *(long *)(lVar10 + 0x40);
  uVar2 = *(undefined4 *)(lVar10 + 0x48);
  if (uVar3 - 1 < uVar14) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x56b,"_semsurfAddWaiter",4,
                 "NVRM: SemSurf(0x%08x, 0x%08x): Requested backwards update from %llu->%llu at idx %llu\n"
                 ,uVar2,uVar1,uVar14,uVar3,uVar21);
    return 0x40;
  }
  uVar12 = (ulong)*(uint *)(*(long *)(param_1 + 0x138) + 0x14);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x573,"_semsurfAddWaiter",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Entering spinlock\n",
               *(undefined4 *)(*(long *)(param_1 + 0x138) + 8));
  portSyncSpinlockAcquire(**(undefined8 **)(param_1 + 0x138));
  auVar23 = mapFind_IMPL(*(long *)(param_1 + 0x138) + 0x98,uVar21);
  lVar15 = auVar23._0_8_;
  if ((lVar15 == 0) || (iVar8 = listCount_IMPL(lVar15,uVar24,auVar23._8_8_,uVar12), iVar8 == 0)) {
    local_98 = 0xffffffffffffffff;
  }
  else {
    puVar11 = (ulong *)listHead_IMPL(lVar15);
    local_98 = *puVar11;
  }
  lVar17 = *(long *)(param_1 + 0x138);
  if ((uVar14 < local_98) && (*(char *)(lVar17 + 0xbd) != '\0')) {
    _semsurfSetMonitoredValue_part_0(lVar17,uVar21,uVar14);
    lVar17 = *(long *)(param_1 + 0x138);
  }
  uVar12 = _semsurfGetValue(lVar17,uVar21);
  if (uVar12 < uVar14) {
    if (lVar15 != 0) {
LAB_003d65a8:
      uVar24 = listTail_IMPL(lVar15);
      uVar13 = listHead_IMPL(lVar15);
      listIterRange_IMPL(&local_88,lVar15,uVar13,uVar24);
      local_58 = local_88;
      local_50 = local_80;
      local_48 = local_78;
      local_40 = local_70;
      do {
        cVar7 = listIterNext_IMPL(&local_58);
        if (cVar7 == '\0') {
          puVar11 = (ulong *)portMemAllocNonPaged(0x40);
          if (puVar11 == (ulong *)0x0) goto LAB_003d6be8;
          portMemSet(puVar11,0,0x40);
          *puVar11 = uVar14;
          puVar11[2] = uVar21;
          puVar16 = (ulong *)0x0;
          goto LAB_003d6656;
        }
      } while (*local_58 < uVar14);
      puVar11 = local_58;
      if (uVar14 == *local_58) {
LAB_003d666f:
        if (uVar3 == 0) {
LAB_003d6691:
          if (uVar20 == 0) {
LAB_003d68fa:
            portSyncSpinlockRelease(**(undefined8 **)(param_1 + 0x138));
            nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x652,"_semsurfAddWaiter",1,
                         "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",
                         *(undefined4 *)(*(long *)(param_1 + 0x138) + 8),
                         *(undefined4 *)(*(long *)(param_1 + 0x138) + 0x14));
            nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x655,"_semsurfAddWaiter",1,
                         "NVRM: SemSurf(0x%08x, 0x%08x): Registered semaphore surface value listener at index %llu, value %llu current value %llu post-wait value %llu notification: %p\n"
                         ,uVar2,uVar1,uVar21,uVar14,uVar12,uVar3,uVar20);
            return 0;
          }
          for (uVar5 = puVar11[3]; uVar5 != 0; uVar5 = *(ulong *)(uVar5 + 0x40)) {
            if (*(ulong *)(uVar5 + 0x28) == uVar20) {
              nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x627,"_semsurfAddWaiter",4,
                           "NVRM: SemSurf(0x%08x, 0x%08x): Notification handle already registered at index %llu for wait value %llu.\n"
                           ,uVar2,uVar1,uVar21,uVar14);
              puVar11[1] = 0;
              goto LAB_003d6719;
            }
          }
          uVar24 = registerEventNotification
                             (puVar11 + 3,lVar10,0,uVar1,0x10000000,(iVar9 == 1) * '\x05' + 'y',
                              uVar20,iVar9 != 1);
          uVar19 = (uint)uVar24;
          if (uVar19 == 0) goto LAB_003d68fa;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x647,"_semsurfAddWaiter",4,
                       "NVRM: SemSurf(0x%08x, 0x%08x): Failed to register event notification for semaphore surface listener at index %llu, value %llu.  Status: 0x%08x\n"
                       ,uVar2,uVar1,uVar21,uVar14,uVar24);
          bVar22 = uVar19 == 0x7b && uVar3 != 0;
        }
        else {
          if (puVar11[1] == 0) {
            puVar11[1] = uVar3;
            goto LAB_003d6691;
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x610,"_semsurfAddWaiter",4,
                       "NVRM: SemSurf(0x%08x, 0x%08x): Existing value-updating waiter at index %llu for wait value %llu:\n Existing update value: %llu\n Requested update value: %llu\n"
                       ,uVar2,uVar1,uVar21,uVar14,puVar11[1],uVar3);
LAB_003d6719:
          bVar22 = false;
          uVar19 = 99;
        }
        if (puVar11[3] == 0) {
          listRemoveIntrusive_IMPL(lVar15,puVar11);
          portMemFree(puVar11);
        }
      }
      else {
        puVar11 = (ulong *)portMemAllocNonPaged(0x40);
        if (puVar11 != (ulong *)0x0) {
          portMemSet(puVar11,0,0x40);
          *puVar11 = uVar14;
          puVar11[2] = uVar21;
          puVar16 = local_58;
LAB_003d6656:
          listInsertExisting_IMPL(lVar15,puVar16,puVar11);
          goto LAB_003d666f;
        }
LAB_003d6be8:
        nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x5f6,"_semsurfAddWaiter",4,
                     "NVRM: SemSurf(0x%08x, 0x%08x): Failed to allocate a semaphore value listener node\n"
                     ,uVar2,uVar1);
        uVar19 = 0x51;
        bVar22 = false;
      }
      iVar9 = listCount_IMPL(lVar15);
      if (iVar9 == 0) {
        mapRemoveIntrusive_IMPL(*(long *)(param_1 + 0x138) + 0x98,lVar15);
        portMemFree(lVar15);
      }
      goto LAB_003d674f;
    }
    lVar15 = portMemAllocNonPaged(0x40);
    if (lVar15 == 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x5d0,"_semsurfAddWaiter",4,
                   "NVRM: SemSurf(0x%08x, 0x%08x): Failed to allocate a semaphore index listeners node\n"
                   ,uVar2,uVar1);
      uVar19 = 0x51;
    }
    else {
      listInitIntrusive_IMPL(lVar15,0x20);
      cVar7 = mapInsertExisting_IMPL(*(long *)(param_1 + 0x138) + 0x98,uVar21,lVar15);
      if (cVar7 != '\0') goto LAB_003d65a8;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x5de,"_semsurfAddWaiter",4,
                   "NVRM: SemSurf(0x%08x, 0x%08x): Duplicate entry found for new index listener list\n"
                   ,uVar2,uVar1);
      portMemFree(lVar15);
      uVar19 = 0x40;
    }
    if (local_98 <= uVar14) {
      uVar24 = **(undefined8 **)(param_1 + 0x138);
LAB_003d6d6c:
      portSyncSpinlockRelease(uVar24);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x675,"_semsurfAddWaiter",1,
                   "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",
                   *(undefined4 *)(*(long *)(param_1 + 0x138) + 8),
                   *(undefined4 *)(*(long *)(param_1 + 0x138) + 0x14));
      return uVar19;
    }
    puVar18 = *(undefined8 **)(param_1 + 0x138);
    if (*(char *)((long)puVar18 + 0xbd) == '\0') {
      uVar24 = *puVar18;
      goto LAB_003d6d6c;
    }
    bVar22 = false;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x5c2,"_semsurfAddWaiter",2,
                 "NVRM: SemSurf(0x%08x, 0x%08x): Detected already signalled wait for %llu at idx %llu current val %llu\n"
                 ,uVar2,uVar1,uVar14,uVar21,uVar12);
    uVar19 = 0x7b;
    bVar22 = uVar3 != 0;
LAB_003d674f:
    puVar18 = *(undefined8 **)(param_1 + 0x138);
    if ((local_98 <= uVar14) || (*(char *)((long)puVar18 + 0xbd) == '\0')) goto LAB_003d678c;
  }
  _semsurfSetMonitoredValue_part_0(puVar18,uVar21,local_98);
  puVar18 = *(undefined8 **)(param_1 + 0x138);
LAB_003d678c:
  portSyncSpinlockRelease(*puVar18);
  uVar14 = (ulong)*(uint *)(*(long *)(param_1 + 0x138) + 0x14);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x675,"_semsurfAddWaiter",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",
               *(undefined4 *)(*(long *)(param_1 + 0x138) + 8));
  if (bVar22) {
    _semsurfSetValueAndNotify(param_1,uVar21,uVar3,uVar14);
    uVar19 = -(uint)(uVar20 != 0) & 0x7b;
  }
  return uVar19;
}


// ===== 003d6dd0 semsurfCtrlCmdSetValue_IMPL =====

undefined8 semsurfCtrlCmdSetValue_IMPL(long param_1,ulong *param_2)

{
  undefined8 uVar1;
  
  if (*param_2 < *(ulong *)(*(long *)(param_1 + 0x138) + 0x90)) {
    uVar1 = _semsurfSetValueAndNotify(param_1,*param_2,param_2[1]);
    return uVar1;
  }
  nvCheckFailedNoLog(4,"_semsurfValidateIndex(pSemSurf->pShared, pParams->index)",
                     "src/kernel/gpu/mem_mgr/sem_surf.c",0x6cc);
  return 0x2c;
}


// ===== 003d6e20 semsurfCtrlCmdUnregisterWaiter_IMPL =====

int semsurfCtrlCmdUnregisterWaiter_IMPL(long param_1,ulong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulong uVar3;
  long *plVar4;
  ulong *puVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  ulong uVar15;
  ulong uVar16;
  undefined1 auVar17 [16];
  undefined8 uVar18;
  ulong *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulong local_60;
  ulong *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar18 = 0x3d6e4a;
  lVar9 = resservGetTlsCallContext();
  local_60 = 0;
  uVar16 = *param_2;
  lVar10 = *(long *)(param_1 + 0x138);
  if (*(ulong *)(lVar10 + 0x90) <= uVar16) {
    nvCheckFailedNoLog(4,"_semsurfValidateIndex(pSemSurf->pShared, pParams->index)",
                       "src/kernel/gpu/mem_mgr/sem_surf.c",0x736);
    return 0x2c;
  }
  uVar3 = param_2[2];
  if (uVar3 == 0) {
    uVar15 = param_2[1];
  }
  else if (*(int *)(lVar9 + 0x2c) == 1) {
    uVar15 = param_2[1];
    local_60 = uVar3;
  }
  else {
    uVar18 = 0x3d7038;
    iVar7 = osUserHandleToKernelPtr(*(undefined4 *)(*(long *)(lVar9 + 8) + 0x48),uVar3,&local_60);
    if (iVar7 != 0) {
      uVar18 = nvstatusToString(iVar7);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x74a,"semsurfCtrlCmdUnregisterWaiter_IMPL",4
                   ,
                   "NVRM: Invalid semaphore surface notification handle: 0x%016llx, status: %s (0x%08x)\n"
                   ,param_2[2],uVar18,iVar7);
      return iVar7;
    }
    uVar15 = param_2[1];
    uVar16 = *param_2;
    lVar10 = *(long *)(param_1 + 0x138);
  }
  uVar3 = local_60;
  uVar11 = (ulong)*(uint *)(lVar10 + 0x14);
  plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar1 = (undefined4)plVar4[2];
  uVar2 = *(undefined4 *)(*plVar4 + 0x48);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x6e7,"_semsurfDelWaiter",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Entering spinlock\n",*(undefined4 *)(lVar10 + 8));
  portSyncSpinlockAcquire(**(undefined8 **)(param_1 + 0x138));
  auVar17 = mapFind_IMPL(*(long *)(param_1 + 0x138) + 0x98,uVar16);
  lVar10 = auVar17._0_8_;
  if (lVar10 != 0) {
    uVar18 = listTail_IMPL(lVar10,uVar18,auVar17._8_8_,uVar11);
    uVar12 = listHead_IMPL(lVar10);
    listIterRange_IMPL(&local_88,lVar10,uVar12,uVar18);
    local_58 = local_88;
    local_50 = local_80;
    local_48 = local_78;
    local_40 = local_70;
    do {
      cVar6 = listIterNext_IMPL(&local_58);
      puVar5 = local_58;
      if (cVar6 == '\0') goto LAB_003d6f7a;
    } while (*local_58 < uVar15);
    if (*local_58 == uVar15) {
      iVar7 = unregisterEventNotificationWithData(local_58 + 3,uVar2,0,uVar1,1,uVar3);
      if (((iVar7 == 0) &&
          (nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x705,"_semsurfDelWaiter",1,
                        "NVRM: SemSurf(0x%08x, 0x%08x): Unregistered event notification %p from semaphore surface listener at index %llu, value %llu.\n"
                        ,uVar2,uVar1,uVar3,uVar16,uVar15), puVar5[3] == 0)) && (puVar5[1] == 0)) {
        listRemoveIntrusive_IMPL(lVar10,puVar5);
        portMemFree(puVar5);
        iVar8 = listCount_IMPL(lVar10);
        if (iVar8 == 0) {
          mapRemoveIntrusive_IMPL(*(long *)(param_1 + 0x138) + 0x98,lVar10);
          portMemFree(lVar10);
          puVar14 = *(undefined8 **)(param_1 + 0x138);
          if (*(char *)((long)puVar14 + 0xbd) != '\0') {
            _semsurfSetMonitoredValue_part_0(puVar14,uVar16,0xffffffffffffffff);
            puVar14 = *(undefined8 **)(param_1 + 0x138);
          }
          goto LAB_003d6f87;
        }
        puVar13 = (undefined8 *)listHead_IMPL(lVar10);
        puVar14 = *(undefined8 **)(param_1 + 0x138);
        if (*(char *)((long)puVar14 + 0xbd) == '\0') goto LAB_003d6f87;
        _semsurfSetMonitoredValue_part_0(puVar14,uVar16,*puVar13);
      }
      puVar14 = *(undefined8 **)(param_1 + 0x138);
      goto LAB_003d6f87;
    }
  }
LAB_003d6f7a:
  puVar14 = *(undefined8 **)(param_1 + 0x138);
  iVar7 = 0xffff;
LAB_003d6f87:
  portSyncSpinlockRelease(*puVar14);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sem_surf.c",0x723,"_semsurfDelWaiter",1,
               "NVRM: SemMem(0x%08x, 0x%08x): Exited spinlock\n",
               *(undefined4 *)(*(long *)(param_1 + 0x138) + 8),
               *(undefined4 *)(*(long *)(param_1 + 0x138) + 0x14));
  return iVar7;
}


// ===== 003d71f0 semsurfGetValue_IMPL =====

undefined8 semsurfGetValue_IMPL(long param_1,ulong param_2)

{
  undefined8 uVar1;
  
  if (param_2 < *(ulong *)(*(long *)(param_1 + 0x138) + 0x90)) {
    uVar1 = _semsurfGetValue();
    return uVar1;
  }
  nvAssertFailedNoLog("_semsurfValidateIndex(pSemSurf->pShared, index)",
                      "src/kernel/gpu/mem_mgr/sem_surf.c",0x762);
  return 0;
}


// ===== 003d7230 semsurfValidateIndex_IMPL =====

undefined8 semsurfValidateIndex_IMPL(long param_1,ulong param_2)

{
  return CONCAT71((int7)((ulong)*(long *)(param_1 + 0x138) >> 8),
                  param_2 < *(ulong *)(*(long *)(param_1 + 0x138) + 0x90));
}


// ===== 003d7250 _sysmemscrubProcessCompletedEntries =====

void _sysmemscrubProcessCompletedEntries(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  
  while( true ) {
    plVar2 = (long *)listHead_IMPL(param_1 + 0x58);
    if ((plVar2 == (long *)0x0) || (param_2 < (ulong)plVar2[1])) break;
    lVar1 = *plVar2;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x5d,"_sysmemscrubProcessCompletedEntries",
                 1,"NVRM: freeing scrubbed pMemDesc=%p RefCount=%u DupCount=%u\n",lVar1,
                 *(undefined4 *)(lVar1 + 0x90),*(undefined4 *)(lVar1 + 0x94));
    memdescFree(*plVar2);
    memdescDestroy(*plVar2);
    listRemove_IMPL(param_1 + 0x58,plVar2);
  }
  return;
}


// ===== 003d72f0 _sysmemscrubProcessCompletedEntriesCb =====

void _sysmemscrubProcessCompletedEntriesCb(undefined8 param_1,long *param_2)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  plVar1 = param_2 + 1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  lVar2 = *param_2;
  if ((int)*plVar1 == 0) {
    portMemFree(param_2);
  }
  if (lVar2 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x77,"_sysmemscrubProcessCompletedEntriesCb",
               0,"NVRM: processing completed scrub work in deferred work item\n");
  *(undefined1 *)(lVar2 + 0x81) = 0;
  uVar3 = ceutilsUpdateProgress_IMPL(*(undefined8 *)(lVar2 + 0x50));
  _sysmemscrubProcessCompletedEntries(lVar2,uVar3);
  return;
}


// ===== 003d7370 _sysmemscrubQueueProcessCompletedEntries =====

void _sysmemscrubQueueProcessCompletedEntries(long param_1)

{
  long *plVar1;
  ulong uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  
  plVar1 = *(long **)(param_1 + 0x88);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x91,
               "_sysmemscrubQueueProcessCompletedEntries",0,"NVRM: scrub completed callback\n");
  cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(*(long *)(param_1 + 0x48) + 0x7a4));
  if (cVar3 == '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 == '\0') {
      uVar7 = 0x93;
      pcVar8 = "rmDeviceGpuLockIsOwner(pSysmemScrubber->pGpu->gpuInstance) || rmGpuLockIsOwner()";
      goto LAB_003d7460;
    }
  }
  if ((*plVar1 != 0) && (*(char *)(param_1 + 0x81) == '\0')) {
    lVar5 = listHead_IMPL(param_1 + 0x58);
    if (lVar5 != 0) {
      uVar2 = *(ulong *)(lVar5 + 8);
      uVar6 = ceutilsUpdateProgress_IMPL(*(undefined8 *)(param_1 + 0x50));
      if (uVar2 <= uVar6) {
        iVar4 = osQueueWorkItem(*(undefined8 *)(param_1 + 0x48),
                                _sysmemscrubProcessCompletedEntriesCb,plVar1,0x283);
        if (iVar4 == 0) {
          *(int *)(plVar1 + 1) = (int)plVar1[1] + 1;
          *(undefined1 *)(param_1 + 0x81) = 1;
          return;
        }
        uVar7 = 0x99;
        pcVar8 = 
        "osQueueWorkItem(pSysmemScrubber->pGpu, _sysmemscrubProcessCompletedEntriesCb, pWorkerParams, (OsQueueWorkItemFlags){ .bDontFreeParams = NV_TRUE, .bFallbackToDpc = NV_TRUE, .bLockGpuGroupDevice = NV_TRUE, .bFullGpuSanity = NV_TRUE}) == NV_OK"
        ;
LAB_003d7460:
        nvAssertFailedNoLog(pcVar8,"src/kernel/gpu/mem_mgr/sysmem_scrub.c",uVar7);
        return;
      }
    }
  }
  return;
}


// ===== 003d7490 sysmemscrubConstruct_IMPL =====

ulong sysmemscrubConstruct_IMPL(long param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  int local_44;
  undefined8 local_40;
  ulong local_38;
  undefined8 local_30;
  
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (*(char *)(*(long *)(param_2 + 0x1b78) + 0x482) == '\0') {
    nvAssertFailedNoLog("pMemoryManager->bFastScrubberSupportsSysmem",
                        "src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x2d);
    return 0x56;
  }
  *(long *)(param_1 + 0x48) = param_2;
  *(undefined1 *)(param_1 + 0x80) = 0;
  iVar1 = osReadRegistryDword(param_2,"RMDisableAsyncSysmemScrub",&local_44);
  if (iVar1 == 0) {
    *(bool *)(param_1 + 0x80) = local_44 == 0;
  }
  plVar2 = (long *)portMemAllocNonPaged(0x10);
  if (plVar2 != (long *)0x0) {
    *plVar2 = param_1;
    *(undefined4 *)(plVar2 + 1) = 1;
    *(long **)(param_1 + 0x88) = plVar2;
    uVar3 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(param_1 + 0x58,uVar3,0x10);
    local_38 = local_38 | 0x40;
    uVar4 = __nvoc_objCreate_CeUtils(param_1 + 0x50,param_1,0,param_2,0,&local_40);
    if ((int)uVar4 == 0) {
      return uVar4;
    }
    nvAssertOkFailedNoLog
              (uVar4 & 0xffffffff,
               "objCreate(&pSysmemScrubber->pCeUtils, pSysmemScrubber, CeUtils, pGpu, NULL, &ceUtilsAllocParams)"
               ,"src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x42);
    portMemFree(plVar2);
    return uVar4 & 0xffffffff;
  }
  nvAssertFailedNoLog("pWorkerParams != NULL","src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x3a);
  return 0x51;
}


// ===== 003d7620 sysmemscrubScrubAndFree_IMPL =====

undefined4 sysmemscrubScrubAndFree_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long *plVar5;
  long local_68 [3];
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  code *local_38;
  long local_30;
  
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(*(long *)(param_1 + 0x48) + 0x7a4));
  if ((cVar1 == '\0') && (cVar1 = rmGpuLockIsOwner(), cVar1 == '\0')) {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pSysmemScrubber->pGpu->gpuInstance) || rmGpuLockIsOwner()"
                        ,"src/kernel/gpu/mem_mgr/sysmem_scrub.c",0xee);
    uVar3 = 0x40;
  }
  else {
    if (*(long *)(param_2 + 0x30) != *(long *)(param_2 + 0x38)) {
      nvAssertFailedNoLog("pMemDesc->Size == pMemDesc->ActualSize",
                          "src/kernel/gpu/mem_mgr/sysmem_scrub.c",0xf0);
    }
    uVar4 = ceutilsUpdateProgress_IMPL(*(undefined8 *)(param_1 + 0x50));
    _sysmemscrubProcessCompletedEntries(param_1,uVar4);
    if (*(char *)(param_1 + 0x80) != '\0') {
      local_68[2] = *(undefined8 *)(param_2 + 0x30);
      local_68[1] = 0;
      local_50 = 0;
      local_40 = 0;
      local_48 = 5;
      local_38 = _sysmemscrubQueueProcessCompletedEntries;
      local_68[0] = param_2;
      local_30 = param_1;
      plVar5 = (long *)listAppendNew_IMPL(param_1 + 0x58);
      if (plVar5 == (long *)0x0) {
        nvAssertFailedNoLog("pEntry != NULL","src/kernel/gpu/mem_mgr/sysmem_scrub.c",0xb9);
      }
      else {
        if (*(int *)(param_2 + 0x90) != 1) {
          nvAssertFailedNoLog("pMemDesc->RefCount == 1","src/kernel/gpu/mem_mgr/sysmem_scrub.c",0xc0
                             );
        }
        if (*(long *)(param_2 + 200) != 0) {
          nvAssertFailedNoLog("!memdescIsSubMemoryMemDesc(pMemDesc)",
                              "src/kernel/gpu/mem_mgr/sysmem_scrub.c",0xc1);
        }
        memdescAddRef(param_2);
        *(char *)(param_2 + 100) = *(char *)(param_2 + 100) + '\x01';
        iVar2 = ceutilsMemset_IMPL(*(undefined8 *)(param_1 + 0x50),local_68);
        if (iVar2 == 0) {
          *plVar5 = param_2;
          plVar5[1] = local_40;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/sysmem_scrub.c",0xf8,"sysmemscrubScrubAndFree_IMPL",1
                       ,"NVRM: pMemDesc=%p RefCount=%u DupCount=%u\n",param_2,
                       *(undefined4 *)(param_2 + 0x90));
          return 0;
        }
        nvAssertOkFailedNoLog(iVar2,"status","src/kernel/gpu/mem_mgr/sysmem_scrub.c",199);
        listRemove_IMPL(param_1 + 0x58,plVar5);
      }
    }
    local_68[2] = *(undefined8 *)(param_2 + 0x30);
    local_68[1] = 0;
    local_50 = 0;
    local_40 = 0;
    local_38 = (code *)0x0;
    local_30 = 0;
    local_48 = 4;
    local_68[0] = param_2;
    uVar3 = ceutilsMemset_IMPL(*(undefined8 *)(param_1 + 0x50),local_68);
  }
  return uVar3;
}


// ===== 003d78d0 sysmemscrubDestruct_IMPL =====

void sysmemscrubDestruct_IMPL(long param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 0x88);
  *puVar2 = 0;
  __nvoc_objDelete(*(undefined8 *)(param_1 + 0x50));
  _sysmemscrubProcessCompletedEntries(param_1,0xffffffffffffffff);
  piVar1 = (int *)(puVar2 + 1);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    portMemFree(puVar2);
    iVar3 = listCount_IMPL(param_1 + 0x58);
  }
  else {
    iVar3 = listCount_IMPL(param_1 + 0x58);
  }
  if (iVar3 == 0) {
    listDestroy_IMPL(param_1 + 0x58);
    return;
  }
  nvAssertFailedNoLog("listCount(&pSysmemScrubber->asyncScrubList) == 0",
                      "src/kernel/gpu/mem_mgr/sysmem_scrub.c",0x110);
  listDestroy_IMPL(param_1 + 0x58);
  return;
}


// ===== 003d7970 _vaspaceapiManagePageLevelsForSplitVaSpace =====

ulong _vaspaceapiManagePageLevelsForSplitVaSpace
                (long param_1,undefined8 param_2,uint param_3,uint param_4,int param_5)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  char local_41;
  undefined8 local_40 [2];
  
  if ((((*(char *)(param_1 + 0x4913) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) ||
      (lVar1 = *(long *)(param_1 + 0x1b78), *(char *)(lVar1 + 0x434) == '\0')) ||
     ((param_4 & 0x14000) != 0x4000)) {
    uVar3 = 0;
  }
  else {
    uVar3 = vgpuIsCallingContextPlugin(param_1,&local_41);
    if ((int)uVar3 == 0) {
      uVar5 = param_4 & 0x1000000;
      if ((((param_4 & 0x1000000) != 0) || (local_41 != '\0')) || (param_3 == 0)) {
        return uVar3;
      }
      do {
        for (; (param_3 & 1) == 0; param_3 = param_3 >> 1) {
          uVar5 = uVar5 + 1;
        }
        lVar4 = gpumgrGetGpu(uVar5);
        if (lVar4 == 0) {
          nvAssertFailedNoLog(&DAT_00d5823e,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x2f5);
        }
        else {
          local_40[0] = 0;
          uVar2 = memmgrPageLevelPoolsGetInfo_IMPL(lVar4,lVar1,param_2,local_40);
          if (uVar2 != 0) {
            nvAssertOkFailedNoLog
                      (uVar2,"memmgrPageLevelPoolsGetInfo(pGpu, pMemoryManager, pDevice, &pMemPool)"
                       ,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x2fe);
LAB_003d7acc:
            return (ulong)uVar2;
          }
          if (param_5 == 0) {
            uVar2 = rmMemPoolReserve(local_40[0],0x3000,param_4);
            if (uVar2 != 0) {
              nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/vaspace_api.c",0x303);
              goto LAB_003d7acc;
            }
          }
          else if (param_5 == 1) {
            rmMemPoolRelease(local_40[0],param_4);
          }
          else {
            rmMemPoolTrim(local_40[0],1,param_4);
          }
        }
        param_3 = param_3 >> 1;
        if (param_3 == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while( true );
    }
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
               "src/kernel/gpu/mem_mgr/vaspace_api.c",0x2f1);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 003d7b90 vaspaceapiCanCopy_IMPL =====

undefined8 vaspaceapiCanCopy_IMPL(void)

{
  return 1;
}


// ===== 003d7b9a vaspaceapiCopyConstruct_IMPL.cold =====

void vaspaceapiCopyConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d7bb0 vaspaceapiCopyConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 vaspaceapiCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  code *pcVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  undefined4 local_54;
  undefined4 local_3c [3];
  
  lVar5 = *(long *)(param_3 + 0x58);
  lVar6 = *(long *)(param_3 + 0x50);
  lVar9 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 8),__nvoc_class_def_VaSpaceApi);
  uVar1 = *(undefined4 *)(lVar6 + 0x48);
  plVar7 = *(long **)(lVar9 + 0x138);
  lVar6 = *(long *)(*(long *)(lVar9 + 0x128) + 0xe0);
  uVar2 = *(undefined4 *)(lVar5 + 0x10);
  uVar3 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  lVar9 = *(long *)(param_2 + 0x10);
  lVar11 = *(long *)(lVar9 + 0x18);
  local_3c[0] = *(undefined4 *)(lVar9 + 0x10);
  uVar4 = *(undefined4 *)(lVar11 + 0x10);
  if (plVar7 == (long *)0x0) {
    nvAssertFailedNoLog(&DAT_00d58250,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x1cd);
    return 0x1f;
  }
  if (((*(char *)(lVar6 + 0x4913) == '\0') || (*(char *)(lVar6 + 0x491e) != '\0')) &&
     (*(char *)(lVar6 + 0x909) == '\0')) {
    local_54 = 0;
    if (*(char *)(lVar6 + 0x908) == '\0') goto LAB_003d7c82;
  }
  else {
    uVar10 = (**(code **)(*plVar7 + 0x70))(plVar7);
    if (((uVar10 & 0x1000000) != 0) ||
       ((*(char *)(lVar6 + 0x908) == '\0' && (*(char *)(lVar6 + 0x909) == '\0')))) {
      lVar9 = *(long *)(param_2 + 0x10);
      local_54 = 0;
      lVar11 = *(long *)(lVar9 + 0x18);
      goto LAB_003d7c82;
    }
  }
  lVar9 = gpuGetRpc(lVar6);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/vaspace_api.c",0x1dc);
    lVar9 = *(long *)(param_2 + 0x10);
    local_54 = 0x1a;
    lVar11 = *(long *)(lVar9 + 0x18);
  }
  else if ((*(char *)(lVar6 + 0x909) == '\0') && (*(char *)(lVar6 + 0x90a) == '\0')) {
    local_54 = (**(code **)(lVar9 + 0x128))(lVar6,lVar9,uVar3,uVar4,local_3c[0],uVar1,uVar2,0);
    lVar9 = *(long *)(param_2 + 0x10);
    lVar11 = *(long *)(lVar9 + 0x18);
  }
  else {
    local_54 = (**(code **)(lVar6 + 0x3ba8))(lVar6 + 0x3b58,uVar3,uVar4,local_3c,uVar1,uVar2,0);
    lVar9 = *(long *)(param_2 + 0x10);
    lVar11 = *(long *)(lVar9 + 0x18);
  }
LAB_003d7c82:
  lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe8);
  if (lVar6 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x1e3,"vaspaceapiCopyConstruct_IMPL",1,
                 "NVRM: Shared vaspaceapi 0x%x, device 0x%x, client 0x%x, as vaspace 0x%x for hParent 0x%x device 0x%x client 0x%x varef 0x%p, deviceref 0x%p\n"
                 ,uVar2,*(undefined4 *)(*(long *)(lVar5 + 0x18) + 0x10),uVar1,local_3c[0],uVar4,
                 *(undefined4 *)(*(long *)(*(long *)(lVar6 + 0x110) + 0x48) + 0x10),uVar3,lVar9,
                 lVar11);
    vaspaceIncRefCnt_IMPL(plVar7);
    *(long **)(param_1 + 0x138) = plVar7;
    return local_54;
  }
                    /* WARNING: Does not return */
  pcVar8 = (code *)invalidInstructionException();
  (*pcVar8)();
}


// ===== 003d7ea0 vaspaceapiConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int vaspaceapiConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint *puVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined8 uVar16;
  undefined8 extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong uVar17;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  ulong extraout_RDX_05;
  ulong extraout_RDX_06;
  ulong extraout_RDX_07;
  undefined8 uVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  ulong local_b8;
  uint local_8c;
  int local_58;
  int local_54;
  long *local_50 [4];
  
  lVar9 = g_pSys;
  lVar15 = *(long *)(param_2 + 0x10);
  local_58 = 0;
  uVar1 = *(undefined4 *)(*(long *)(lVar15 + 0x18) + 0x10);
  local_50[0] = (long *)0x0;
  uVar18 = *(undefined8 *)(g_pSys + 0x230);
  lVar3 = *(long *)(param_1 + 0x128);
  lVar4 = *(long *)(lVar3 + 0xe0);
  lVar14 = *(long *)(&DAT_00001b90 + lVar4);
  uVar16 = *(undefined8 *)(lVar3 + 0xd8);
  lVar3 = *(long *)(lVar3 + 0xe8);
  lVar13 = *(long *)(lVar4 + 0x1b78);
  lVar5 = *(long *)(lVar4 + 0x1bc0);
  local_54 = 0;
  cVar10 = rmGpuLockIsOwner();
  if ((cVar10 != '\0') && (cVar10 = rmapiInRtd3PmPath(), cVar10 != '\0')) {
    rmGpuLocksRelease(0,0);
  }
  if (*(long *)(param_3 + 0x16) != 0) {
    iVar11 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar4 + 0x7a4),3,2,0x2000,&local_58);
    if (iVar11 == 0) {
      iVar11 = vaspaceapiCopyConstruct_IMPL(param_1,param_2,param_3);
      rmGpuGroupLockRelease(local_58,0);
      return iVar11;
    }
    nvAssertOkFailedNoLog
              (iVar11,
               "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_ALL, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_MEM, &gpuMask)"
               ,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x62);
    return iVar11;
  }
  if ((*(char *)(lVar4 + 0x491d) != '\0') &&
     (iVar11 = vgpuGetCallingContextGfid(lVar4,&local_54), iVar11 != 0)) {
    nvAssertOkFailedNoLog
              (iVar11,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/mem_mgr/vaspace_api.c",0x70);
    return iVar11;
  }
  puVar6 = *(uint **)(param_3 + 0x10);
  uVar2 = puVar6[1];
  uVar19 = (uVar2 & 1) << 4;
  if ((uVar2 & 2) != 0) {
    uVar19 = uVar19 | 0x20;
  }
  if ((uVar2 & 4) != 0) {
    uVar19 = uVar19 | 0x40000;
  }
  if ((uVar2 & 0x40) != 0) {
    uVar19 = uVar19 | 0x20000000;
  }
  if ((uVar2 & 8) != 0) {
    uVar19 = uVar19 | 0x40010000;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar19 = uVar19 | 4;
  }
  if ((uVar2 & 0x100) != 0) {
    uVar19 = uVar19 | 0x80000;
  }
  uVar20 = uVar2 & 0x200;
  if (uVar20 != 0) {
    uVar19 = uVar19 | 0x1000000;
  }
  if ((uVar2 & 0x400) != 0) {
    uVar19 = uVar19 | 0x100000;
  }
  if ((uVar2 & 0x800) != 0) {
    uVar19 = uVar19 | 0x8000000;
  }
  if ((uVar2 & 0x1000) != 0) {
    uVar19 = uVar19 | 0x40;
  }
  if ((uVar2 & 0x80) != 0) {
    uVar19 = uVar19 | 8;
  }
  uVar12 = uVar19 | 0x4000000;
  if (*(char *)(g_pSys + 0x7e) == '\0') {
    if ((uVar19 & 4) == 0) {
      if ((uVar19 & 0x60000000) == 0x20000000) {
LAB_003d8899:
        nvCheckFailedNoLog(3,
                           "!((flags & VASPACE_FLAGS_ENABLE_FAULTING) && !(flags & VASPACE_FLAGS_IS_EXTERNALLY_OWNED))"
                           ,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x2a5);
LAB_003d88b6:
        nvCheckOkFailedNoLog
                  (3,0x1f,
                   "translateAllocFlagsToVASpaceFlags(allocFlags, &flags, (pCallContext->secInfo.privLevel >= RS_PRIV_LEVEL_KERNEL), gfid)"
                   ,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x7a);
        return 0x1f;
      }
    }
    else if ((uVar19 & 0x40000000) == 0) {
      if (((uVar19 & 0x40000) == 0) || ((*(uint *)(param_2 + 0x28) < 2 && (local_54 == 0)))) {
        nvCheckFailedNoLog(3,
                           "!((flags & VASPACE_FLAGS_ENABLE_ATS) && !((flags & VASPACE_FLAGS_IS_EXTERNALLY_OWNED) || ((flags & VASPACE_FLAGS_SHARED_MANAGEMENT) && (bKernelClient || IS_GFID_VF(gfid)))))"
                           ,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x296);
        goto LAB_003d88b6;
      }
      if ((uVar19 & 0x20000000) != 0) goto LAB_003d8899;
    }
  }
  uVar7 = *(ulong *)(puVar6 + 10);
  uVar17 = *(ulong *)(puVar6 + 2);
  cVar10 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar4 + 0x7a4));
  if (cVar10 != '\0') {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x87,"vaspaceapiConstruct_IMPL",4,
                 "NVRM: VASpace alloc should be called without acquiring GPU lock\n");
    nvAssertFailedNoLog(&DAT_00d5823e,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x88);
    return 0x2f;
  }
  if (*puVar6 == 1) {
    local_58 = 1 << ((byte)*(undefined4 *)(lVar4 + 0x7a4) & 0x1f);
  }
  else {
    local_58 = gpumgrGetGpuMask(lVar4);
  }
  local_8c = uVar12;
  if ((((lVar13 != 0) && (*(char *)(lVar13 + 0x434) != '\0')) && (*(char *)(lVar13 + 0x436) != '\0')
      ) && (local_8c = uVar19 | 0x4004000, (uVar2 & 0x2208) != 0)) {
    local_8c = uVar12;
  }
  iVar11 = _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,0);
  if (iVar11 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/vaspace_api.c",0x9f);
    return iVar11;
  }
  iVar11 = rmGpuLocksAcquire(0,0x2000);
  if (iVar11 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/vaspace_api.c",0xa8);
    _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,1);
    return iVar11;
  }
  if (param_3[3] == 0x90f1) {
    uVar21 = extraout_RDX;
    if ((*puVar6 != 1) || (uVar21 = 0xb1, 1 < *(uint *)(param_2 + 0x28))) {
      if (*(int *)(lVar3 + 0x1d0) == 1) goto LAB_003d8a48;
      if (((*(char *)(lVar4 + 0x4922) != '\0') || (lVar5 == 0)) ||
         ((cVar10 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(lVar4,lVar5,uVar21), cVar10 == '\0' ||
          (iVar11 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar4,lVar5,lVar3), iVar11 == 0))))
      goto LAB_003d81b3;
      nvCheckOkFailedNoLog
                (4,iVar11,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                 "src/kernel/gpu/mem_mgr/vaspace_api.c",0xcd);
LAB_003d840d:
      _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,1);
      uVar17 = extraout_RDX_01;
      goto LAB_003d85f0;
    }
LAB_003d8a2b:
    nvAssertFailedNoLog(&DAT_00d5823e,"src/kernel/gpu/mem_mgr/vaspace_api.c",uVar21);
LAB_003d8913:
    _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,1);
    uVar17 = extraout_RDX_04;
LAB_003d892e:
    iVar11 = 0x1f;
  }
  else {
    if (*(int *)(lVar3 + 0x1d0) == 1) {
LAB_003d8a48:
      uVar18 = 0xb9;
LAB_003d8a4d:
      nvAssertFailedNoLog(&DAT_00d5823e,"src/kernel/gpu/mem_mgr/vaspace_api.c",uVar18);
LAB_003d8a60:
      iVar11 = 0x40;
      _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,1);
      uVar17 = extraout_RDX_06;
      goto LAB_003d85f0;
    }
LAB_003d81b3:
    cVar10 = hypervisorIsVgxHyper_IMPL();
    if ((cVar10 == '\0') && ((uVar2 & 0x4000) != 0)) {
      if (*(char *)(lVar9 + 0x7e) != '\0') {
        iVar11 = os_iommu_sva_bind(*(undefined8 *)(lVar4 + 0x4e0),param_1 + 0x140,puVar6 + 0xc);
        if (iVar11 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar11,
                     "os_iommu_sva_bind(pGpu->pOsGpuInfo, &pVaspaceApi->sva_handle, &pNvVASpaceAllocParams->pasid)"
                     ,"src/kernel/gpu/mem_mgr/vaspace_api.c",0xd9);
          goto LAB_003d840d;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0xdf,"vaspaceapiConstruct_IMPL",4,
                     "NVRM: os_iommu_sva_bind pasid: %d\n",puVar6[0xc]);
        goto LAB_003d8230;
      }
      nvCheckOkFailedNoLog
                (4,0x1f,"pSys->getProperty(pSys, PDB_PROP_SYS_ENABLE_RM_TEST_ONLY_CODE)",
                 "src/kernel/gpu/mem_mgr/vaspace_api.c",0xd5);
      goto LAB_003d8913;
    }
LAB_003d8230:
    if ((*(char *)(lVar4 + 0x908) == '\0') && (*(char *)(lVar4 + 0x909) == '\0')) {
LAB_003d8280:
      iVar11 = param_3[3];
      if ((iVar11 != 0x90f1) || (uVar19 = *puVar6, uVar19 == 0)) goto LAB_003d8291;
      if (uVar19 == 3) {
        iVar11 = vaspaceGetByHandleOrDeviceDefault_IMPL
                           (*(undefined8 *)(param_2 + 8),uVar1,0,local_50);
        if (iVar11 == 0) goto LAB_003d867d;
        goto LAB_003d8a60;
      }
      if (uVar19 < 4) {
        if (uVar19 == 1) {
LAB_003d8660:
          local_50[0] = (long *)(**(code **)(lVar14 + 0x4e8))(lVar4);
        }
        else {
          gpugrpGetGlobalVASpace_IMPL(uVar16,local_50);
        }
LAB_003d867d:
        iVar11 = 0;
        if (local_50[0] == (long *)0x0) {
          uVar18 = 0x138;
          goto LAB_003d8a4d;
        }
LAB_003d8688:
        vaspaceIncRefCnt_IMPL();
        goto LAB_003d8694;
      }
      if (uVar19 != 4) goto LAB_003d867d;
      iVar11 = (**(code **)(lVar14 + 0x398))(lVar4,lVar14,local_50);
      if (local_50[0] != (long *)0x0) goto LAB_003d8688;
    }
    else {
      if (*(char *)(lVar4 + 0x491e) != '\0') {
        if (((*puVar6 == 4) || (uVar20 != 0)) && (*(char *)(lVar14 + 0xa860) == '\0'))
        goto LAB_003d8280;
LAB_003d83b0:
        lVar13 = gpuGetRpc(lVar4);
        if (lVar13 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/vaspace_api.c",0x107);
        }
        else {
          if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
            iVar11 = (**(code **)(lVar13 + 0x348))
                               (lVar4,lVar13,*param_3,param_3[1],param_3[2],param_3[3],puVar6);
          }
          else {
            iVar11 = (**(code **)(lVar4 + 0x3b60))();
          }
          if (iVar11 != 0) goto LAB_003d840d;
        }
        goto LAB_003d8280;
      }
      if (*(char *)(lVar4 + 0x4913) == '\0') {
        if (*(char *)(lVar4 + 0x909) == '\0') goto LAB_003d83b0;
        uVar19 = *puVar6;
LAB_003d838e:
        if ((uVar19 == 4) || (uVar20 != 0)) goto LAB_003d8280;
        goto LAB_003d83b0;
      }
      uVar19 = *puVar6;
      if (uVar19 != 1) goto LAB_003d838e;
      iVar11 = param_3[3];
      if (iVar11 == 0x90f1) goto LAB_003d8660;
LAB_003d8291:
      uVar19 = puVar6[8];
      uVar20 = local_8c;
      if ((uVar19 - 0x10000 & 0xfffeffff) == 0) {
        if (*(char *)(lVar4 + 0x4922) == '\0') {
          uVar20 = local_8c | 0x80000000;
          if ((local_8c & 4) != 0) goto LAB_003d84f7;
          if (uVar19 != 0x10000) goto LAB_003d8517;
        }
        else {
          if (*(char *)(lVar4 + 0x908) == '\0') {
            uVar20 = local_8c | 0x80000000;
          }
          if ((uVar20 & 4) != 0) {
LAB_003d84f7:
            if (*(char *)(lVar4 + 0x45b) == '\0') {
LAB_003d82e6:
              iVar11 = 0x56;
              nvAssertFailedNoLog(&DAT_00d5823e,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x159);
              _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,uVar20,1);
              uVar17 = extraout_RDX_00;
              goto LAB_003d85f0;
            }
          }
          if (uVar19 != 0x10000) {
            if (uVar19 == 0x20000) {
LAB_003d8517:
              uVar20 = uVar20 | 0x400000;
            }
            goto LAB_003d851e;
          }
        }
        uVar20 = uVar20 | 0x200000;
      }
      else {
        if (uVar19 != 0) {
          uVar21 = 0x145;
          goto LAB_003d8a2b;
        }
        if (*(char *)(lVar4 + 0x4922) == '\0') {
          uVar20 = local_8c | 0x80000000;
          if (((local_8c & 4) != 0) && (*(char *)(lVar4 + 0x45b) == '\0')) goto LAB_003d82e6;
        }
        else {
          if (*(char *)(lVar4 + 0x908) == '\0') {
            uVar20 = local_8c | 0x80000000;
          }
          if ((local_8c & 4) != 0) goto LAB_003d84f7;
        }
      }
LAB_003d851e:
      local_b8 = uVar17;
      if ((uVar17 != 0) && (local_b8 = (uVar17 - 1) + uVar7, local_b8 < uVar7)) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x164,"vaspaceapiConstruct_IMPL",4,
                     "NVRM: Integer overflow !!! Invalid parameters for vaBase:%llx, vaSize:%llx\n",
                     uVar7);
        nvAssertFailedNoLog(&DAT_00d5823e,"src/kernel/gpu/mem_mgr/vaspace_api.c",0x169);
        _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,uVar20,1);
        goto LAB_003d892e;
      }
      if ((uVar2 & 0x80) == 0) {
        uVar21 = 0;
        uVar16 = 0;
      }
      else {
        uVar21 = 0x11fffffff;
        uVar16 = 0x100000000;
      }
      iVar11 = vmmCreateVaspace_IMPL
                         (uVar18,iVar11,*puVar6,local_58,uVar7,local_b8,uVar16,uVar21,0,uVar20,
                          local_50);
      local_8c = uVar20;
      if (iVar11 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x186,"vaspaceapiConstruct_IMPL",4,
                     "NVRM: Could not construct VA space. Status %x\n",iVar11);
        local_50[0] = (long *)0x0;
        _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,uVar20,1);
        uVar17 = extraout_RDX_02;
        goto LAB_003d85f0;
      }
LAB_003d8694:
      *(long **)(param_1 + 0x138) = local_50[0];
      if ((uVar2 & 0x4000) != 0) {
        if (*(char *)(lVar9 + 0x7e) == '\0') {
          nvCheckOkFailedNoLog
                    (4,0x1f,"pSys->getProperty(pSys, PDB_PROP_SYS_ENABLE_RM_TEST_ONLY_CODE)",
                     "src/kernel/gpu/mem_mgr/vaspace_api.c",400);
          _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,1);
          uVar17 = extraout_RDX_07;
          goto LAB_003d892e;
        }
        lVar14 = __nvoc_dynamicCast(local_50[0],__nvoc_class_def_OBJGVASPACE);
        if (lVar14 != 0) {
          *(uint *)(lVar14 + 0x104) = puVar6[0xc];
          nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x198,"vaspaceapiConstruct_IMPL",1,
                       "NVRM: pasid: %d\n");
        }
        iVar11 = 0;
      }
      plVar8 = *(long **)(*(long *)(lVar3 + 0x110) + 0x48);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x19c,"vaspaceapiConstruct_IMPL",1,
                   "NVRM: Created vaspaceapi 0x%x, hParent 0x%x, device 0x%x, client 0x%x, varef 0x%p, parentref 0x%p\n"
                   ,*(undefined4 *)(lVar15 + 0x10),uVar1,(int)plVar8[2],
                   *(undefined4 *)(*plVar8 + 0x48),lVar15,
                   *(undefined8 *)(*(long *)(param_2 + 0x10) + 0x18));
      uVar18 = (**(code **)(*local_50[0] + 0x58))();
      *(undefined8 *)(puVar6 + 10) = uVar18;
      lVar15 = (**(code **)(*local_50[0] + 0x60))();
      *(long *)(puVar6 + 2) = (lVar15 - *(long *)(puVar6 + 10)) + 1;
    }
    if (iVar11 == 0) {
      _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,2);
      uVar17 = extraout_RDX_03;
    }
    else {
      _vaspaceapiManagePageLevelsForSplitVaSpace(lVar4,lVar3,local_58,local_8c,1);
      uVar17 = extraout_RDX_05;
    }
  }
LAB_003d85f0:
  rmGpuLocksRelease(0,0,uVar17);
  return iVar11;
}


// ===== 003d8c9f vaspaceapiDestruct_IMPL.cold =====

void vaspaceapiDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003d8cb0 vaspaceapiDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void vaspaceapiDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  byte extraout_var_00;
  uint uVar8;
  byte extraout_var;
  long lVar9;
  ulong uVar10;
  long *plVar11;
  byte bVar12;
  byte bVar13;
  long local_48;
  undefined1 local_40 [16];
  
  uVar4 = *(undefined8 *)(g_pSys + 0x230);
  lVar5 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe8);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),&local_48,local_40);
  plVar11 = *(long **)(param_1 + 0x138);
  uVar1 = *(undefined4 *)(*(long *)(local_48 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(local_48 + 0x10) + 0x10);
  uVar3 = *(undefined4 *)(*(long *)(*(long *)(local_48 + 0x10) + 0x18) + 0x10);
  if ((*(char *)(lVar5 + 0x4913) == '\0') || (*(char *)(lVar5 + 0x491e) != '\0')) {
    bVar12 = 0;
    bVar13 = 0;
    if (*(char *)(lVar5 + 0x909) != '\0') {
      bVar13 = 0;
      (**(code **)(*plVar11 + 0x70))();
      plVar11 = *(long **)(param_1 + 0x138);
      bVar12 = extraout_var_00 & 1;
    }
  }
  else {
    bVar13 = (**(code **)(*plVar11 + 0x70))();
    bVar13 = bVar13 >> 7;
    (**(code **)(**(long **)(param_1 + 0x138) + 0x70))();
    plVar11 = *(long **)(param_1 + 0x138);
    bVar12 = extraout_var & 1;
  }
  lVar9 = __nvoc_dynamicCast(plVar11,__nvoc_class_def_OBJGVASPACE);
  if (lVar9 != 0) {
    _vaspaceapiManagePageLevelsForSplitVaSpace
              (lVar5,lVar6,*(undefined4 *)(*(long *)(param_1 + 0x138) + 0x48),
               *(undefined4 *)(lVar9 + 0xb8),1);
  }
  uVar10 = (**(code **)(**(long **)(param_1 + 0x138) + 0x70))();
  if (((uVar10 & 0x1000000) == 0) || (*(long *)(*(long *)(&DAT_00001b90 + lVar5) + 0xa820) != 0)) {
    if (*(long *)(param_1 + 0x140) != 0) {
      os_iommu_sva_unbind();
    }
    vmmDestroyVaspace_IMPL(uVar4,*(undefined8 *)(param_1 + 0x138));
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x220,"vaspaceapiDestruct_IMPL",1,
                 "NVRM: Skipping Legacy FLA vaspace destruct, gpu:%x \n",
                 *(undefined4 *)(lVar5 + 0x7a4));
  }
  if (((*(char *)(lVar5 + 0x908) != '\0') || (*(char *)(lVar5 + 0x909) != '\0')) &&
     (bVar12 == 0 && bVar13 == 0)) {
    lVar9 = gpuGetRpc(lVar5);
    if (lVar9 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/vaspace_api.c",0x23c);
    }
    else {
      if ((*(char *)(lVar5 + 0x909) == '\0') && (*(char *)(lVar5 + 0x90a) == '\0')) {
        uVar8 = (**(code **)(lVar9 + 0xf0))(lVar5,lVar9,uVar1,uVar3,uVar2,*(code **)(lVar9 + 0xf0));
      }
      else {
        uVar8 = (**(code **)(lVar5 + 0x3b70))(lVar5 + 0x3b58,uVar1,uVar2);
      }
      if ((uVar8 & 0xffffffef) == 0) goto LAB_003d8e19;
    }
    nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                        "src/kernel/gpu/mem_mgr/vaspace_api.c",0x23d);
  }
LAB_003d8e19:
  if (lVar6 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/vaspace_api.c",0x240,"vaspaceapiDestruct_IMPL",1,
                 "NVRM: Destroyed vaspaceapi 0x%x, hParent 0x%x, device 0x%x, client 0x%x varef 0x%p, deviceref 0x%p\n"
                 ,uVar2,uVar3,*(undefined4 *)(*(long *)(*(long *)(lVar6 + 0x110) + 0x48) + 0x10),
                 uVar1,*(long *)(local_48 + 0x10),*(undefined8 *)(*(long *)(local_48 + 0x10) + 0x18)
                );
    return;
  }
                    /* WARNING: Does not return */
  pcVar7 = (code *)invalidInstructionException();
  (*pcVar7)();
}


// ===== 003d8fc0 dmaConstructEngine_IMPL =====

void dmaConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    uVar2 = *(undefined8 *)(param_2 + 0x150);
  }
  uVar2 = gpuEngineGetGpu(uVar2);
  iVar1 = dmaConstructHal_VF(uVar2,param_2);
  if (iVar1 != 0) {
    return;
  }
  dmaInit_GM107(uVar2,param_2);
  return;
}


// ===== 003d9010 dmaStateInitLocked_IMPL =====

undefined8 dmaStateInitLocked_IMPL(void)

{
  dmaInitGart_GM107();
  return 0;
}


// ===== 003d9030 dmaConstructHal_VF =====

undefined8 dmaConstructHal_VF(void)

{
  return 0;
}


// ===== 003d9040 deviceCtrlCmdDmaFlush_VF =====

undefined8 deviceCtrlCmdDmaFlush_VF(void)

{
  return 0;
}


// ===== 003d9050 kmemsysProgramSysmemFlushBuffer_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysProgramSysmemFlushBuffer_GA100(long param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = *(ulong *)(param_2 + 0x468);
  if (uVar3 == 0) {
    nvAssertFailedNoLog("pKernelMemorySystem->sysmemFlushBuffer != 0",
                        "src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0x36);
    uVar3 = *(ulong *)(param_2 + 0x468);
  }
  bVar1 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  uVar3 = uVar3 >> (bVar1 & 0x3f);
  if ((uVar3 >> 0x20 & 0xffff80) != 0) {
    nvAssertFailedNoLog("(alignedSysmemFlushBufferAddrHi & (~NV_PFB_NISO_FLUSH_SYSMEM_ADDR_HI_MASK)) == 0"
                        ,"src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0x3c);
  }
  uVar2 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100c40,0);
  regWrite032(param_1 + 0x3a18,0,0,&DAT_00100c40,uVar2 & 0xff000000 | (uint)(uVar3 >> 0x20) & 0x7f,0
             );
  regRead032(param_1 + 0x3a18,0,0,&DAT_00100c10,0);
  regWrite032(param_1 + 0x3a18,0,0,&DAT_00100c10,uVar3 & 0xffffffff,0);
  return;
}


// ===== 003d9170 kmemsysInitFlushSysmemBuffer_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysInitFlushSysmemBuffer_GA100(undefined8 param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_2 + 0x460) == 0) {
    bVar1 = (**(code **)(param_2 + 0x1d8))();
    iVar2 = memdescCreate(param_2 + 0x460,param_1,0x1000,(long)(1 << (bVar1 & 0x1f)),1,1);
    if (iVar2 != 0) {
      return iVar2;
    }
    *(undefined4 *)(*(long *)(param_2 + 0x460) + 0x9c) = 0xac;
    iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0x460));
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0x78,
                   "kmemsysInitFlushSysmemBuffer_GA100",4,
                   "NVRM: Could not allocate sysmem flush buffer: %x\n",iVar2);
      return iVar2;
    }
    uVar3 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x460),1,0);
    *(undefined8 *)(param_2 + 0x468) = uVar3;
  }
  (**(code **)(param_2 + 0x1d0))(param_1,param_2);
  return 0;
}


// ===== 003d9280 kmemsysReadMIGMemoryCfg_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysReadMIGMemoryCfg_GA100(long param_1,long param_2)

{
  ulong uVar1;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a67,&local_38,0x20);
  if ((int)uVar1 == 0) {
    *(undefined8 *)(param_2 + 0x2c0) = local_38;
    *(undefined8 *)(param_2 + 0x2c8) = local_30;
    *(undefined4 *)(param_2 + 0x2d0) = (undefined4)local_28;
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_KMEMSYS_GET_MIG_MEMORY_CONFIG, &params, sizeof(params))"
             ,"src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0xac);
  return uVar1 & 0xffffffff;
}


// ===== 003d9330 kmemsysInitMIGMemoryPartitionTable_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysInitMIGMemoryPartitionTable_GA100(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(char *)(param_2 + 0x2a8) == '\0') {
    return 0;
  }
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a6b,param_2 + 0x440,0x20);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMSYS_GET_MIG_MEMORY_PARTITION_TABLE, &pKernelMemorySystem->migMemoryPartitionTable, sizeof(pKernelMemorySystem->migMemoryPartitionTable))"
             ,"src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0xca);
  return uVar1 & 0xffffffff;
}


// ===== 003d93b0 kmemsysSwizzIdToVmmuSegmentsRange_GA100 =====

ulong kmemsysSwizzIdToVmmuSegmentsRange_GA100
                (long param_1,undefined8 param_2,uint param_3,ulong param_4,uint param_5)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  ulong local_48 [3];
  
  param_4 = param_4 & 0xffffffff;
  local_48[0] = 1;
  local_48[1] = 0;
  auVar4 = memmgrGetMIGPartitionableMemoryRange_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
  uVar2 = kmemsysSwizzIdToMIGMemRange_IMPL
                    (param_1,param_2,param_3,auVar4._0_8_,auVar4._8_8_,local_48);
  if (uVar2 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar2,
               "kmemsysSwizzIdToMIGMemRange(pGpu, pKernelMemorySystem, swizzId, totalRange, pAddrRange)"
               ,"src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0xe3);
    nvCheckOkFailedNoLog
              (4,uVar2,
               "_kmemsysSwizzIdToFbMemRange_GA100(pGpu, pKernelMemorySystem, swizzId, vmmuSegmentSize, partitionableMemoryRange, &addrRange)"
               ,"src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0x10e);
    return (ulong)uVar2;
  }
  if (local_48[0] == 0) {
    local_48[0] = 0;
  }
  else {
    uVar3 = (param_4 - 1) + local_48[0];
    uVar1 = param_4 - 1 & local_48[0];
    local_48[0] = local_48[0] + param_4;
    if (uVar1 != 0) {
      local_48[0] = uVar3 & -param_4;
    }
  }
  if (param_3 < 7) {
    if (param_3 < 3) {
      if (param_3 - 1 < 2) {
        param_5 = param_5 - 1 >> 1;
      }
    }
    else {
      param_5 = param_5 - 3 >> 2;
    }
  }
  else if (param_3 - 7 < 8) {
    param_5 = param_5 - 7 >> 3;
  }
  uVar3 = kmemsysInitMIGGPUInstanceMemConfigForSwizzId_IMPL
                    (param_1,param_2,param_3,local_48[0] / param_4,param_5);
  if ((int)uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,
               "kmemsysInitMIGGPUInstanceMemConfigForSwizzId(pGpu, pKernelMemorySystem, swizzId, startingVmmuSegment, memSizeInVmmuSegment)"
               ,"src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0x13b);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 003d9540 kmemsysIsPagePLCable_GA100 =====

ulong kmemsysIsPagePLCable_GA100(undefined8 param_1,long param_2,ulong param_3,long param_4)

{
  long lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  long lVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  
  lVar5 = kmemsysGetStaticConfig_IMPL();
  uVar7 = *(uint *)(lVar5 + 0x20);
  if (uVar7 * *(uint *)(lVar5 + 0x24) != 0x50) {
    return 1;
  }
  lVar1 = *(long *)(param_2 + 0x2c0);
  lVar11 = (ulong)uVar7 * (ulong)*(uint *)(lVar5 + 0x24);
  uVar9 = (ulong)((*(long *)(param_2 + 0x2c8) + lVar1) * lVar11) >> 4;
  if ((((*(ulong *)(lVar5 + 0x20) & 0xffffffff00000003) == 0x400000000 && 3 < uVar7) &&
      (uVar9 < *(uint *)(param_2 + 0x2d0))) && (param_3 < (ulong)*(uint *)(param_2 + 0x2d0) << 0x10)
     ) {
    uVar12 = (ulong)(lVar11 * lVar1) >> 4;
    if ((uVar12 * 0x10000 <= param_3) && (param_3 < uVar9 << 0x10)) {
      uVar9 = uVar9 - uVar12;
      uVar10 = param_3 + uVar12 * -0x10000;
      uVar13 = (uVar9 & 0xffffffffffff) * 0x2000;
      uVar12 = uVar10 / uVar13;
      if (7 < (uint)uVar12) {
        nvAssertFailedNoLog("partition_id < 8",
                            "src/kernel/gpu/mem_sys/arch/ampere/kern_mem_sys_ga100.c",0x15f);
        return 1;
      }
      iVar8 = ((uint)lVar1 & 0x7f) * -0x10 + 0x800;
      uVar7 = *(uint *)(param_2 + 0x440 + (uVar12 & 0xffffffff) * 4);
      if (uVar7 < 7) {
        if (uVar7 < 3) {
          if (uVar7 == 0) goto LAB_003d97a0;
          lVar5 = (uVar10 - (((uint)(iVar8 * 10) >> 7) << 0x11)) -
                  (uVar9 & 0xffffffffffff) * 0x8000 * (ulong)(uVar7 - 1);
          uVar9 = lVar5 + 0xa00000;
          if (param_4 != 0x200000) {
            auVar2._8_8_ = 0;
            auVar2._0_8_ = uVar9;
            return CONCAT71(SUB167(auVar2 / ZEXT816(0x1400000),1),0x7ffff < uVar9 % 0x1400000);
          }
          if (uVar9 < lVar5 + 0xc00000U) {
            uVar7 = 0;
            do {
              uVar12 = uVar9 / 0x1400000;
              uVar10 = uVar9 % 0x1400000;
              uVar9 = uVar9 + 0x20000;
              uVar7 = uVar7 | (uint)CONCAT71((int7)(uVar12 * 0x1400000 >> 8),uVar10 < 0x80000);
            } while (uVar9 != lVar5 + 0xa20000 +
                              (ulong)(-(uint)(lVar5 + 0xa20000U < lVar5 + 0xc00000U) & 0x1e0000));
            goto LAB_003d96b0;
          }
        }
        else {
          lVar5 = (uVar10 - (((uint)(iVar8 * 10) >> 7) << 0x10)) -
                  (uVar9 & 0xffffffffffff) * 0x4000 * (ulong)(uVar7 - 3);
          uVar9 = lVar5 + 0xa00000;
          if (param_4 != 0x200000) {
            auVar4._8_8_ = 0;
            auVar4._0_8_ = uVar9;
            return CONCAT71(SUB167(auVar4 / ZEXT816(0xa00000),1),0x3ffff < uVar9 % 0xa00000);
          }
          if (uVar9 < lVar5 + 0xc00000U) {
            uVar7 = 0;
            do {
              uVar12 = uVar9 / 0xa00000;
              uVar10 = uVar9 % 0xa00000;
              uVar9 = uVar9 + 0x10000;
              uVar7 = uVar7 | (uint)CONCAT71((int7)(uVar12 * 0xa00000 >> 8),uVar10 < 0x40000);
            } while (uVar9 != lVar5 + 0xa10000 +
                              (ulong)(-(uint)(lVar5 + 0xa10000U < lVar5 + 0xc00000U) & 0x1f0000));
            goto LAB_003d96b0;
          }
        }
      }
      else {
        if (7 < uVar7 - 7) {
          return 1;
        }
        lVar5 = (uVar10 - (((uint)(iVar8 * 10) >> 8) << 0x10)) - (uVar7 - 7) * uVar13;
        pcVar6 = libspdm_is_signature_buffer_palindrome + lVar5;
        if (param_4 != 0x200000) {
          auVar3._8_8_ = 0;
          auVar3._0_8_ = pcVar6;
          return CONCAT71(SUB167(auVar3 / ZEXT816(0x500000),1),0x2ffff < (ulong)pcVar6 % 0x500000);
        }
        if (pcVar6 < (code *)(lVar5 + 0x700000U)) {
          uVar7 = 0;
          do {
            uVar9 = (ulong)pcVar6 / 0x500000;
            uVar12 = (ulong)pcVar6 % 0x500000;
            pcVar6 = pcVar6 + 0x10000;
            uVar7 = uVar7 | (uint)CONCAT71((int7)(uVar9 * 0x500000 >> 8),uVar12 < 0x30000);
          } while (pcVar6 != (code *)(lVar5 + 0x510000 +
                                     (ulong)(-(uint)((code *)(lVar5 + 0x510000) <
                                                    (code *)(lVar5 + 0x700000U)) & 0x1f0000)));
          goto LAB_003d96b0;
        }
      }
      uVar7 = 0;
      goto LAB_003d96b0;
    }
LAB_003d97a0:
    if (param_4 != 0x200000) {
LAB_003d95da:
      return CONCAT71((int7)((param_3 / 0x2800000) * 0x2800000 >> 8),0xbffff < param_3 % 0x2800000);
    }
  }
  else {
    if (param_4 != 0x200000) goto LAB_003d95da;
    if (0xffffffffffdfffff < param_3) {
      return 1;
    }
  }
  uVar7 = 0;
  uVar9 = param_3 + 0x40000;
  uVar12 = param_3;
  while (uVar10 = uVar9,
        uVar7 = uVar7 | (uint)CONCAT71((int7)((uVar12 / 0x2800000) * 0x2800000 >> 8),
                                       uVar12 % 0x2800000 < 0xc0000),
        uVar10 != param_3 + 0x40000 +
                  (ulong)(-(uint)(param_3 + 0x40000 < param_3 + 0x200000) & 0x1c0000)) {
    uVar12 = uVar10;
    uVar9 = uVar10 + 0x40000;
  }
LAB_003d96b0:
  return (ulong)(uVar7 ^ 1);
}


// ===== 003d99a0 kmemsysGetMaximumBlacklistPages_GA100 =====

undefined8 kmemsysGetMaximumBlacklistPages_GA100(void)

{
  return 0x200;
}


// ===== 003d99b0 kmemsysGetMaxFbpas_GA100 =====

undefined8 kmemsysGetMaxFbpas_GA100(void)

{
  return 0x18;
}


// ===== 003d99c0 kmemsysCheckReadoutEccEnablement_GA100 =====

uint kmemsysCheckReadoutEccEnablement_GA100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x823814,0);
  return uVar1 >> 0x10 & 1;
}


// ===== 003d99f0 kmemsysReadUsableFbSize_GA102 =====

undefined8 kmemsysReadUsableFbSize_GA102(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1183a4,0);
  *param_3 = (ulong)uVar1 << 0x14;
  return 0;
}


// ===== 003d9a40 kmemsysIsPagePLCable_GA102 =====

bool kmemsysIsPagePLCable_GA102(undefined8 param_1,undefined8 param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  byte bVar6;
  
  lVar2 = kmemsysGetStaticConfig_IMPL();
  iVar4 = *(int *)(lVar2 + 0x24) * *(int *)(lVar2 + 0x20);
  if (iVar4 == 0x30) {
    if (param_4 != 0x200000) {
      return 0x5ffff < param_3 % 0x1800000;
    }
    if (0xffffffffffdfffff < param_3) {
      return true;
    }
    bVar6 = 0;
    uVar1 = param_3 + 0x10000;
    uVar5 = param_3;
    while (uVar3 = uVar1, bVar6 = bVar6 | uVar5 % 0x1800000 < 0x60000,
          uVar3 != param_3 + 0x10000 +
                   (ulong)(-(uint)(param_3 + 0x10000 < param_3 + 0x200000) & 0x1f0000)) {
      uVar5 = uVar3;
      uVar1 = uVar3 + 0x10000;
    }
  }
  else if (iVar4 == 0x28) {
    if (param_4 != 0x200000) {
      return 0x4ffff < param_3 % 0x1400000;
    }
    if (0xffffffffffdfffff < param_3) {
      return true;
    }
    bVar6 = 0;
    uVar1 = param_3 + 0x10000;
    uVar5 = param_3;
    while (uVar3 = uVar1, bVar6 = bVar6 | uVar5 % 0x1400000 < 0x50000,
          uVar3 != param_3 + 0x10000 +
                   (ulong)(-(uint)(param_3 + 0x10000 < param_3 + 0x200000) & 0x1f0000)) {
      uVar5 = uVar3;
      uVar1 = uVar3 + 0x10000;
    }
  }
  else {
    if (*(int *)(lVar2 + 0x24) == 4) {
      if (*(int *)(lVar2 + 0x20) != 8) {
        return true;
      }
      if (param_4 != 0x200000) {
        return (param_3 & 0xfc0000) != 0;
      }
      if (param_3 < 0xffffffffffe00000) {
        bVar6 = 0;
        uVar1 = param_3 + 0x10000;
        uVar5 = param_3;
        while (uVar3 = uVar1, bVar6 = bVar6 | (uVar5 & 0xfc0000) == 0,
              uVar3 != param_3 + 0x10000 +
                       (ulong)(-(uint)(param_3 + 0x10000 < param_3 + 0x200000) & 0x1f0000)) {
          uVar5 = uVar3;
          uVar1 = uVar3 + 0x10000;
        }
        goto LAB_003d9bf5;
      }
    }
    else {
      if (*(long *)(lVar2 + 0x20) != 0x300000008) {
        return true;
      }
      if (param_4 != 0x200000) {
        return 0x2ffff < param_3 % 0xc00000;
      }
      if (param_3 < 0xffffffffffe00000) {
        bVar6 = 0;
        uVar1 = param_3 + 0x10000;
        uVar5 = param_3;
        while (uVar3 = uVar1, bVar6 = bVar6 | uVar5 % 0xc00000 < 0x30000,
              uVar3 != param_3 + 0x10000 +
                       (ulong)(-(uint)(param_3 + 0x10000 < param_3 + 0x200000) & 0x1f0000)) {
          uVar5 = uVar3;
          uVar1 = uVar3 + 0x10000;
        }
        goto LAB_003d9bf5;
      }
    }
    bVar6 = 0;
  }
LAB_003d9bf5:
  return (bool)(bVar6 ^ 1);
}


// ===== 003d9d80 kmemsysInitHshub0Aperture_GB100 =====

undefined8 kmemsysInitHshub0Aperture_GB100(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_10;
  
  local_10 = 0;
  iVar1 = __nvoc_objCreate_IoAperture
                    (&local_10,param_1,0,*(undefined8 *)(param_1 + 0x1a18),0,0,0,0,0,0x870000,0x1000
                    );
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_10;
  }
  return uVar2;
}


// ===== 003d9de0 kmemsysDestroyHshub0Aperture_GB100 =====

void kmemsysDestroyHshub0Aperture_GB100(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  __nvoc_objDelete(param_3);
  return;
}


// ===== 003d9df0 kmemsysProgramSysmemFlushBuffer_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysProgramSysmemFlushBuffer_GB100(undefined8 param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  
  lVar1 = (**(code **)(param_2 + 0x1b8))();
  if (lVar1 != 0) {
    uVar2 = *(ulong *)(param_2 + 0x468);
    if (uVar2 == 0) {
      nvAssertFailedNoLog("pKernelMemorySystem->sysmemFlushBuffer != 0",
                          "src/kernel/gpu/mem_sys/arch/blackwell/kern_mem_sys_gb100.c",0x98);
      uVar2 = *(ulong *)(param_2 + 0x468);
    }
    if (0xfffff < uVar2 >> 0x20) {
      nvAssertFailedNoLog("(alignedSysmemFlushBufferAddrHi & (~NV_PFB_HSHUB_ZB_PCIE_FLUSH_SYSMEM_ADDR_HI_ADR_MASK)) == 0"
                          ,"src/kernel/gpu/mem_sys/arch/blackwell/kern_mem_sys_gb100.c",0xa1);
    }
    uVar3 = (uint)(uVar2 >> 0x20) & 0xfffff;
    (**(code **)(**(long **)(lVar1 + 0x50) + 0x40))(*(long **)(lVar1 + 0x50),0xe54,uVar3);
    (**(code **)(**(long **)(lVar1 + 0x50) + 0x40))
              (*(long **)(lVar1 + 0x50),0xe50,uVar2 & 0xffffffff);
    (**(code **)(**(long **)(lVar1 + 0x50) + 0x40))(*(long **)(lVar1 + 0x50),0x6c4,uVar3);
    (**(code **)(**(long **)(lVar1 + 0x50) + 0x40))
              (*(long **)(lVar1 + 0x50),0x6c0,uVar2 & 0xffffffff);
    (**(code **)(param_2 + 0x1c0))(param_1,param_2,lVar1);
    return;
  }
  nvAssertFailedNoLog("pHshub0IoAperture != NULL",
                      "src/kernel/gpu/mem_sys/arch/blackwell/kern_mem_sys_gb100.c",0x97);
  return;
}


// ===== 003d9f60 kmemsysGetFlushSysmemBufferAddrShift_GB100 =====

undefined8 kmemsysGetFlushSysmemBufferAddrShift_GB100(void)

{
  return 8;
}


// ===== 003d9f70 kmemsysAssertFbAckTimeoutPending_GB100 =====

undefined8 kmemsysAssertFbAckTimeoutPending_GB100(void)

{
  return 0;
}


// ===== 003d9f80 kmemsysReadHdmTopFromVbios_GB100 =====

undefined8 kmemsysReadHdmTopFromVbios_GB100(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,nvswitch_initialize_device_state_lr10,0);
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x1180f0,0);
  lVar3 = (ulong)(uVar2 >> 4 & 0xffffff) << ((byte)uVar2 & 0xf) + 0x14;
  if (lVar3 == (ulong)(uVar1 >> 4 & 0xffffff) << ((byte)uVar1 & 0xf) + 0x14) {
    lVar3 = 0;
  }
  *param_3 = lVar3;
  return 0;
}


// ===== 003da010 kmemsysCheckReadoutEccEnablement_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kmemsysCheckReadoutEccEnablement_GB100(long param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(param_1 + 0x438))();
  uVar2 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x3814,0);
  return uVar2 >> 0x10 & 1;
}


// ===== 003da060 kmemsysGetL2EccDedCountRegAddr_GB100 =====

int kmemsysGetL2EccDedCountRegAddr_GB100
              (undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  return (param_3 * 0x10 + param_4) * 0x200 + 0x1404f8;
}


// ===== 003da080 kmemsysProgramSysmemFlushBuffer_GB10B =====

void kmemsysProgramSysmemFlushBuffer_GB10B(long param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_2 + 0x468);
  if (uVar1 == 0) {
    nvAssertFailedNoLog("pKernelMemorySystem->sysmemFlushBuffer != 0",
                        "src/kernel/gpu/mem_sys/arch/blackwell/kern_mem_sys_gb10b.c",0x31);
    uVar1 = *(ulong *)(param_2 + 0x468);
  }
  if (0xfffff < uVar1 >> 0x20) {
    nvAssertFailedNoLog("(alignedSysmemFlushBufferAddrHi & (~NV_PFB_FBHUB0_PCIE_FLUSH_SYSMEM_ADDR_HI_ADR_MASK)) == 0"
                        ,"src/kernel/gpu/mem_sys/arch/blackwell/kern_mem_sys_gb10b.c",0x3a);
  }
  regRead032(param_1 + 0x3a18,0,0,0x8a1d5c,0);
  regWrite032(param_1 + 0x3a18,0,0,0x8a1d5c,(uint)(uVar1 >> 0x20) & 0xfffff,0);
  regRead032(param_1 + 0x3a18,0,0,0x8a1d58,0);
  regWrite032(param_1 + 0x3a18,0,0,0x8a1d58,uVar1 & 0xffffffff,0);
  return;
}


// ===== 003da190 kmemsysGetFlushSysmemBufferAddrShift_GB10B =====

undefined8 kmemsysGetFlushSysmemBufferAddrShift_GB10B(void)

{
  return 8;
}


// ===== 003da1a0 kmemsysDoCacheOp_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kmemsysDoCacheOp_GH100
          (long param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  code *pcVar7;
  uint uVar8;
  undefined8 uVar9;
  long *plVar10;
  int iVar11;
  uint local_4c;
  
  lVar6 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x550))
                    (param_1,*(long *)(&DAT_00001b90 + param_1),0);
  if ((*(char *)(param_1 + 0x44c) == '\0') || (*(char *)(param_1 + 0x450) != '\0')) {
    return 0;
  }
  uVar1 = *(int *)(lVar6 + 0x7c) + 0x810;
  uVar4 = *(int *)(lVar6 + 0x7c) + 0x808;
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (param_3 != uVar1) {
      if (uVar4 != param_3) {
        if (param_3 != 0xf10) {
          if (param_3 != 0xf18) {
            return 0x56;
          }
          goto LAB_003da24c;
        }
        goto LAB_003da4ee;
      }
      goto LAB_003da478;
    }
    uVar9 = 0x810;
    plVar10 = *(long **)(lVar6 + 0x50);
    pcVar7 = *(code **)(*plVar10 + 0x28);
  }
  else {
    if (param_3 == uVar1) {
      return 0;
    }
    if ((param_3 & 0xfffffff7) != 0xf10) {
      return 0x56;
    }
    if (uVar4 != param_3) {
      if (param_3 != 0xf10) {
LAB_003da24c:
        local_4c = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf18,0);
        local_4c = local_4c & 0x7fffffff;
        goto LAB_003da283;
      }
LAB_003da4ee:
      local_4c = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf10,0);
      local_4c = local_4c & 0x7fffffff;
      goto LAB_003da283;
    }
LAB_003da478:
    plVar10 = *(long **)(lVar6 + 0x50);
    uVar9 = 0x808;
    pcVar7 = *(code **)(*plVar10 + 0x28);
  }
  local_4c = (*pcVar7)(plVar10,uVar9);
  local_4c = local_4c & 0x7fffffff;
LAB_003da283:
  uVar8 = 0;
  iVar5 = 0;
  iVar11 = 0;
  do {
    if (param_3 == uVar1) {
      uVar9 = 0x814;
      plVar10 = *(long **)(lVar6 + 0x50);
      pcVar7 = *(code **)(*plVar10 + 0x28);
LAB_003da365:
      uVar8 = (*pcVar7)(plVar10,uVar9);
      cVar3 = (char)(uVar8 >> 0x18);
LAB_003da375:
      uVar8 = uVar8 & 0x7fffffff;
      if (-1 < cVar3) {
        return 0;
      }
    }
    else {
      if (uVar4 == param_3) {
        uVar9 = 0x80c;
        plVar10 = *(long **)(lVar6 + 0x50);
        pcVar7 = *(code **)(*plVar10 + 0x28);
        goto LAB_003da365;
      }
      if (param_3 == 0xf10) {
        iVar2 = *(int *)(param_1 + 0x3a64) + 0xf14;
LAB_003da43d:
        uVar8 = regRead032(param_1 + 0x3a18,0,0,iVar2,0);
        cVar3 = (char)(uVar8 >> 0x18);
        goto LAB_003da375;
      }
      if (param_3 == 0xf18) {
        iVar2 = *(int *)(param_1 + 0x3a64) + 0xf1c;
        goto LAB_003da43d;
      }
    }
    if (0x8c < (local_4c - uVar8 & 0x7fffffff)) {
      return 0;
    }
    if (iVar5 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0xb9,
                   "kmemsysDoCacheOp_GH100",4,
                   "NVRM: - timeout error waiting for reg 0x%x update cnt=%d\n",param_3,iVar11);
      return 0x65;
    }
    if (*(char *)(param_1 + 0x44f) != '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x450) != '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x451) != '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x461) != '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x44c) == '\0') {
      return 0;
    }
    iVar11 = iVar11 + 1;
    iVar5 = timeoutCheck(param_1 + 0x1af0,param_6,0xca);
    osSpinLoop();
  } while( true );
}


// ===== 003da530 kmemsysCacheOp_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmemsysCacheOp_GH100(long param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  char *pcVar4;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar1 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x550))
                    (param_1,*(long *)(&DAT_00001b90 + param_1),0);
  if ((param_3 == 0) || (param_4 != 0)) {
    if ((param_5 != 0) && (param_4 != 0)) {
      (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x3e0))(param_1);
      timeoutSet(param_1 + 0x1af0,&local_50,0,0);
      if (param_4 == 4) {
        if (1 < param_5 - 2) {
          return 0;
        }
        iVar3 = *(int *)(lVar1 + 0x7c) + 0x810;
      }
      else {
        if (param_4 < 5) {
          if (param_4 == 3) {
            if ((param_5 & 0xfffffffd) != 1) {
              return 0;
            }
            uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0xf18,0,0,&local_50);
            return uVar2;
          }
          if (param_4 != 1) {
            if (param_4 != 2) {
              return 0;
            }
            goto LAB_003da7da;
          }
          goto LAB_003da6cd;
        }
        if (param_4 != 5) {
          if (param_4 != 6) {
            return 0;
          }
          if (param_5 != 3) {
            return 0;
          }
          uVar2 = kmemsysSendFlushL2AllRamsAndCaches_IMPL(param_1,param_2);
          return uVar2;
        }
        if (1 < param_5 - 2) {
          return 0;
        }
        iVar3 = *(int *)(lVar1 + 0x7c) + 0x808;
      }
      uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,iVar3,0,0,&local_50);
      return uVar2;
    }
    pcVar4 = "cache operation";
    if (param_5 == 0) {
      pcVar4 = "memory target";
    }
  }
  else {
    iVar3 = memdescGetAddressSpace(param_3);
    if (iVar3 == 2) {
      if (param_5 != 0) {
        (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x3e0))(param_1);
        timeoutSet(param_1 + 0x1af0,&local_50,0,0);
LAB_003da7da:
        if (*(char *)(param_1 + 0x908) != '\0') {
          return 0;
        }
        if (param_5 != 3) {
          if (param_5 == 1) {
            uVar2 = kmemsysSendL2InvalidateEvict_IMPL(param_1,param_2,1);
            return uVar2;
          }
          return 0x56;
        }
        uVar2 = kmemsysSendL2InvalidateEvict_IMPL(param_1,param_2,0x11);
        return uVar2;
      }
    }
    else if (param_5 != 0) {
      (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x3e0))(param_1);
      timeoutSet(param_1 + 0x1af0,&local_50,0,0);
LAB_003da6cd:
      if (param_5 == 1) {
        nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x10d,
                     "kmemsysCacheOp_GH100",1,
                     "NVRM: Invalidate not supported, promoting to an evict (writeback + invalidate clean lines).\n"
                    );
        (**(code **)(param_2 + 400))(param_1,param_2,*(int *)(lVar1 + 0x7c) + 0x810,0,0,&local_50);
      }
      else {
        if (1 < param_5 - 2) {
          return 0;
        }
        uVar2 = (**(code **)(param_2 + 400))
                          (param_1,param_2,*(int *)(lVar1 + 0x7c) + 0x810,0,0,&local_50);
        if (param_5 != 3) {
          return uVar2;
        }
      }
      uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0xf10,0,0,&local_50);
      return uVar2;
    }
    pcVar4 = "memory target";
  }
  nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0xfb,"kmemsysCacheOp_GH100"
               ,4,"NVRM: called with null %s\n",pcVar4);
  return 0;
}


// ===== 003da8d0 kmemsysProgramSysmemFlushBuffer_GH100 =====

void kmemsysProgramSysmemFlushBuffer_GH100(long param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_2 + 0x468);
  if (uVar1 == 0) {
    nvAssertFailedNoLog("pKernelMemorySystem->sysmemFlushBuffer != 0",
                        "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x187);
    uVar1 = *(ulong *)(param_2 + 0x468);
  }
  if (0xfffff < uVar1 >> 0x20) {
    nvAssertFailedNoLog("(alignedSysmemFlushBufferAddrHi & (~NV_PFB_FBHUB_PCIE_FLUSH_SYSMEM_ADDR_HI_ADR_MASK)) == 0"
                        ,"src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",400);
  }
  regRead032(param_1 + 0x3a18,0,0,&DAT_00100a38,0);
  regWrite032(param_1 + 0x3a18,0,0,&DAT_00100a38,(uint)(uVar1 >> 0x20) & 0xfffff,0);
  regRead032(param_1 + 0x3a18,0,0,&DAT_00100a34,0);
  regWrite032(param_1 + 0x3a18,0,0,&DAT_00100a34,uVar1 & 0xffffffff,0);
  return;
}


// ===== 003da9e0 kmemsysNumaAddMemory_GH100 =====

int kmemsysNumaAddMemory_GH100
              (long param_1,long param_2,uint param_3,undefined8 param_4,ulong param_5,
              undefined4 *param_6)

{
  int iVar1;
  long lVar2;
  undefined4 local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  iVar1 = osNumaMemblockSize(local_40);
  if (iVar1 == 0) {
    if ((local_40[0] - 1U & param_5) == 0) {
      lVar2 = (ulong)param_3 * 0x20;
      if (*(char *)(*(long *)(param_2 + 0x2b8) + lVar2) == '\0') {
        iVar1 = osNumaAddGpuMemory(*(undefined8 *)(param_1 + 0x4e0),param_4,param_5,&local_44);
        if (iVar1 == 0) {
          *(undefined1 *)(*(long *)(param_2 + 0x2b8) + lVar2) = 1;
          *(undefined8 *)(*(long *)(param_2 + 0x2b8) + 8 + lVar2) = param_4;
          *(ulong *)(*(long *)(param_2 + 0x2b8) + 0x10 + lVar2) = param_5;
          *(undefined4 *)(*(long *)(param_2 + 0x2b8) + 0x18 + lVar2) = local_44;
          *param_6 = local_44;
          *(undefined1 *)(param_2 + 0x29a) = 1;
          nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x1e6,
                       "kmemsysNumaAddMemory_GH100",1,
                       "NVRM: Memory partition: %u added successfully! numa id: %u offset: 0x%llx size: 0x%llx\n"
                       ,(ulong)param_3,local_44,param_4,param_5);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x1d7,
                     "kmemsysNumaAddMemory_GH100",4,
                     "NVRM: Memory partition: %u is already in use!\n",param_3);
        iVar1 = 0x17;
      }
    }
    else {
      nvAssertFailedNoLog("NV_IS_ALIGNED(size, memblockSize)",
                          "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x1d3);
      iVar1 = 0x40;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,"osNumaMemblockSize(&memblockSize)",
               "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x1d2);
  }
  return iVar1;
}


// ===== 003daba0 kmemsysNumaRemoveMemory_GH100 =====

void kmemsysNumaRemoveMemory_GH100(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = (ulong)param_3 * 0x20;
  pcVar2 = (char *)(*(long *)(param_2 + 0x2b8) + lVar1);
  if (*pcVar2 == '\0') {
    return;
  }
  osNumaRemoveGpuMemory
            (*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(pcVar2 + 8),
             *(undefined8 *)(pcVar2 + 0x10),*(undefined4 *)(pcVar2 + 0x18));
  *(undefined1 *)(*(long *)(param_2 + 0x2b8) + lVar1) = 0;
  *(undefined8 *)(*(long *)(param_2 + 0x2b8) + 8 + lVar1) = 0;
  *(undefined8 *)(*(long *)(param_2 + 0x2b8) + 0x10 + lVar1) = 0;
  *(undefined4 *)(*(long *)(param_2 + 0x2b8) + 0x18 + lVar1) = 0xffffffff;
  nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x20e,
               "kmemsysNumaRemoveMemory_GH100",1,
               "NVRM: memory partition: %u removed successfully!\n",param_3);
  return;
}


// ===== 003dac60 kmemsysNumaRemoveAllMemory_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysNumaRemoveAllMemory_GH100(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    (**(code **)(param_2 + 0x208))(param_1,param_2,iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0xf);
  return;
}


// ===== 003dacb0 kmemsysIsSwizzIdRejectedByHW_GH100 =====

undefined8 kmemsysIsSwizzIdRejectedByHW_GH100(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  ulong *puVar2;
  
  lVar1 = kmigmgrGetStaticInfo_IMPL(param_1,*(undefined8 *)(param_1 + 0x1bc0));
  if (param_3 < 0xf) {
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pStaticInfo != NULL",
                          "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x23e);
    }
    else if (*(long *)(lVar1 + 0x18) == 0) {
      nvAssertFailedNoLog("pStaticInfo->pSwizzIdFbMemPageRanges != NULL",
                          "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x23f);
    }
    else {
      puVar2 = (ulong *)(*(long *)(lVar1 + 0x18) + (ulong)param_3 * 0x10);
      if (*puVar2 <= puVar2[1]) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x245,
                   "kmemsysIsSwizzIdRejectedByHW_GH100",1,
                   "NVRM: GPU Instance Mem Config for swizzId = 0x%x is rejected by HW\n",param_3);
    }
  }
  else {
    nvAssertFailedNoLog("swizzId < KMIGMGR_MAX_GPU_SWIZZID",
                        "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x23d);
  }
  return 1;
}


// ===== 003dada0 kmemsysSwizzIdToVmmuSegmentsRange_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysSwizzIdToVmmuSegmentsRange_GH100
                (long param_1,long param_2,uint param_3,undefined8 param_4,ulong param_5)

{
  char cVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  lVar2 = kmigmgrGetStaticInfo_IMPL(param_1,*(undefined8 *)(param_1 + 0x1bc0));
  if (0xe < param_3) {
    nvAssertFailedNoLog("swizzId < KMIGMGR_MAX_GPU_SWIZZID",
                        "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x261);
    return 0x1f;
  }
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pStaticInfo != NULL",
                        "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x262);
  }
  else {
    if (*(long *)(lVar2 + 0x18) != 0) {
      cVar1 = (**(code **)(param_2 + 0x278))(param_1,param_2,param_3);
      if (cVar1 == '\0') {
        plVar3 = (long *)((ulong)param_3 * 0x10 + *(long *)(lVar2 + 0x18));
        lVar2 = *plVar3;
        uVar4 = (plVar3[1] + 1) - lVar2;
        if ((param_3 != 0) && ((param_5 & 0xffffffff) < uVar4)) {
          nvAssertFailedNoLog("(swizzId == 0)",
                              "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x278);
          return 0x40;
        }
      }
      else {
        uVar4 = 0;
        lVar2 = 0;
      }
      uVar4 = kmemsysInitMIGGPUInstanceMemConfigForSwizzId_IMPL(param_1,param_2,param_3,lVar2,uVar4)
      ;
      if ((int)uVar4 != 0) {
        nvAssertOkFailedNoLog
                  (uVar4 & 0xffffffff,
                   "kmemsysInitMIGGPUInstanceMemConfigForSwizzId(pGpu, pKernelMemorySystem, swizzId, startingVmmuSegment, memSizeInVmmuSegment)"
                   ,"src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x27b);
        return uVar4 & 0xffffffff;
      }
      return uVar4;
    }
    nvAssertFailedNoLog("pStaticInfo->pSwizzIdFbMemPageRanges != NULL",
                        "src/kernel/gpu/mem_sys/arch/hopper/kern_mem_sys_gh100.c",0x263);
  }
  return 0x40;
}


// ===== 003daf40 kmemsysAssertFbAckTimeoutPending_GH100 =====

undefined8 kmemsysAssertFbAckTimeoutPending_GH100(void)

{
  return 0;
}


// ===== 003daf50 kmemsysGetEccDedCountSize_GH100 =====

undefined8 kmemsysGetEccDedCountSize_GH100(void)

{
  return 4;
}


// ===== 003daf60 kmemsysGetEccDedCountRegAddr_GH100 =====

int kmemsysGetEccDedCountRegAddr_GH100
              (undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  return (param_3 * 0x1000 + 0x240968 + param_4) * 4;
}


// ===== 003daf80 kmemsysDoCacheOp_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kmemsysDoCacheOp_GM107
          (long param_1,long param_2,int param_3,undefined4 param_4,uint param_5,undefined8 param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x44c) == '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x450) != '\0') {
      return 0;
    }
    if (param_3 != 0x70004) {
      if (param_3 != 0x70008) {
        regWrite032(param_1 + 0x3a18,0,0,param_3,param_4,0);
        goto LAB_003db04a;
      }
      goto LAB_003db142;
    }
  }
  else {
    if (param_3 == 0x70008) {
      if (*(char *)(param_1 + 0x44c) == '\0') {
        return 0;
      }
      if (*(char *)(param_1 + 0x450) != '\0') {
        return 0;
      }
LAB_003db142:
      (**(code **)(param_2 + 0x1b0))(param_1,param_2,param_4);
      goto LAB_003db04a;
    }
    if (param_3 == 0x70010) {
      return 0;
    }
    if (param_3 != 0x70004) {
      return 0x56;
    }
    if (*(char *)(param_1 + 0x44c) == '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x450) != '\0') {
      return 0;
    }
  }
  (**(code **)(param_2 + 0x1a0))(param_1,param_2,param_4);
LAB_003db04a:
  iVar1 = 0;
  iVar3 = 0;
  while( true ) {
    if (param_3 == 0x70004) {
      uVar2 = (**(code **)(param_2 + 0x198))(param_1,param_2);
    }
    else if (param_3 == 0x70008) {
      uVar2 = (**(code **)(param_2 + 0x1a8))(param_1,param_2);
    }
    else {
      uVar2 = regRead032(param_1 + 0x3a18,0,0,param_3,0);
    }
    if ((uVar2 & param_5) == 0) {
      return 0;
    }
    if (iVar1 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/maxwell/kern_mem_sys_gm107.c",0x7c,
                   "kmemsysDoCacheOp_GM107",4,
                   "NVRM: - timeout error waiting for reg 0x%x update cnt=%d\n",param_3,iVar3);
      return 0x65;
    }
    if ((((*(char *)(param_1 + 0x44f) != '\0') || (*(char *)(param_1 + 0x450) != '\0')) ||
        (*(char *)(param_1 + 0x451) != '\0')) ||
       ((*(char *)(param_1 + 0x461) != '\0' || (*(char *)(param_1 + 0x44c) == '\0')))) break;
    iVar3 = iVar3 + 1;
    iVar1 = timeoutCheck(param_1 + 0x1af0,param_6,0x8c);
    osSpinLoop();
  }
  return 0;
}


// ===== 003db220 kmemsysInitFlushSysmemBuffer_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysInitFlushSysmemBuffer_GM107(long param_1,long param_2)

{
  ulong uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 extraout_RDX;
  undefined8 uVar6;
  
  if (*(long *)(param_2 + 0x460) == 0) {
    bVar2 = (**(code **)(param_2 + 0x1d8))();
    iVar3 = memdescCreate(param_2 + 0x460,param_1,0x1000,(long)(1 << (bVar2 & 0x1f)),1,1);
    if (iVar3 != 0) {
      return iVar3;
    }
    *(undefined4 *)(*(long *)(param_2 + 0x460) + 0x9c) = 0xad;
    iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x460));
    if (iVar3 == 0) {
      lVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x460),1,0);
      *(long *)(param_2 + 0x468) = lVar5;
      if (lVar5 + 0xfffU >> 0x28 == 0) {
        regRead032(param_1 + 0x3a18,0,0,&DAT_00100c10,0);
        uVar1 = *(ulong *)(param_2 + 0x468);
        bVar2 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
        regWrite032(param_1 + 0x3a18,0,0,&DAT_00100c10,uVar1 >> (bVar2 & 0x3f),0);
        return 0;
      }
    }
    memdescFree(*(undefined8 *)(param_2 + 0x460));
    memdescDestroy(*(undefined8 *)(param_2 + 0x460));
    bVar2 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
    uVar6 = 1;
    iVar3 = memdescCreate(param_2 + 0x460,param_1,0x1000,(long)(1 << (bVar2 & 0x1f)),1,1);
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar4 = (**(code **)(*(long *)(param_1 + 0x4d8) + 0x68))
                      (*(long *)(param_1 + 0x4d8),0,extraout_RDX,uVar6);
    if (uVar4 < 0x29) {
      *(undefined4 *)(*(long *)(param_2 + 0x460) + 0x9c) = 0xae;
      iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x460));
    }
    else {
      memdescOverridePhysicalAddressWidthWindowsWAR(param_1,*(long *)(param_2 + 0x460),0x28);
      osDmaSetAddressSize(*(undefined8 *)(param_1 + 0x4e0),0x28);
      *(undefined4 *)(*(long *)(param_2 + 0x460) + 0x9c) = 0xae;
      iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x460));
      osDmaSetAddressSize(*(undefined8 *)(param_1 + 0x4e0),uVar4);
    }
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/maxwell/kern_mem_sys_gm107.c",0x14b,
                   "kmemsysInitFlushSysmemBuffer_GM107",4,
                   "NVRM: Could not allocate sysmem flush buffer: %x\n",iVar3);
      return iVar3;
    }
    lVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x460),1);
    *(long *)(param_2 + 0x468) = lVar5;
    if (lVar5 + 0xfffU >> 0x28 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/maxwell/kern_mem_sys_gm107.c",0x155,
                   "kmemsysInitFlushSysmemBuffer_GM107",4,
                   "NVRM: GPU 0x%x: Allocated sysmem flush buffer not addressable 0x%llx\n",
                   *(undefined4 *)(param_1 + 0x7ac),lVar5);
      if (((*(char *)(param_1 + 0x4910) == '\0') && (*(char *)(param_1 + 0x4911) == '\0')) &&
         (*(char *)(param_1 + 0x446) == '\0')) {
        return 0x51;
      }
      lVar5 = *(long *)(param_2 + 0x468);
    }
  }
  else {
    lVar5 = *(long *)(param_2 + 0x468);
  }
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pKernelMemorySystem->sysmemFlushBuffer != 0",
                        "src/kernel/gpu/mem_sys/arch/maxwell/kern_mem_sys_gm107.c",0x174);
  }
  regRead032(param_1 + 0x3a18,0,0,&DAT_00100c10,0);
  uVar1 = *(ulong *)(param_2 + 0x468);
  bVar2 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  regWrite032(param_1 + 0x3a18,0,0,&DAT_00100c10,uVar1 >> (bVar2 & 0x3f),0);
  return 0;
}


// ===== 003db5d0 kmemsysProgramSysmemFlushBuffer_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysProgramSysmemFlushBuffer_GM107(long param_1,long param_2)

{
  ulong uVar1;
  byte bVar2;
  
  regRead032(param_1 + 0x3a18,0,0,&DAT_00100c10,0);
  uVar1 = *(ulong *)(param_2 + 0x468);
  bVar2 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  regWrite032(param_1 + 0x3a18,0,0,&DAT_00100c10,uVar1 >> (bVar2 & 0x3f),0);
  return;
}


// ===== 003db650 kmemsysGetFlushSysmemBufferAddrShift_GM107 =====

undefined8 kmemsysGetFlushSysmemBufferAddrShift_GM107(void)

{
  return 8;
}


// ===== 003db660 kmemsysGetMaximumBlacklistPages_GM107 =====

undefined8 kmemsysGetMaximumBlacklistPages_GM107(void)

{
  return 0x40;
}


// ===== 003db670 kmemsysCacheOp_GM200 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmemsysCacheOp_GM200(long param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined1 local_40 [24];
  
  if ((param_3 == 0) || (param_4 != 0)) {
    if ((param_5 != 0) && (param_4 != 0)) {
      kbusSendSysmembar_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1));
      timeoutSet(param_1 + 0x1af0,local_40,0,0);
      if (param_4 == 4) {
        if (1 < param_5 - 2) {
          return 0;
        }
        uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0x70010,1,3,local_40);
        return uVar2;
      }
      if (4 < param_4) {
        if (param_4 == 5) {
          if (1 < param_5 - 2) {
            return 0;
          }
          uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0x7000c,1,3,local_40);
          return uVar2;
        }
        if (param_4 != 6) {
          return 0;
        }
        if (param_5 != 3) {
          return 0;
        }
        uVar2 = kmemsysSendFlushL2AllRamsAndCaches_IMPL(param_1,param_2);
        return uVar2;
      }
      if (param_4 == 3) {
        if ((param_5 & 0xfffffffd) != 1) {
          return 0;
        }
        uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0x70008,1,3,local_40);
        return uVar2;
      }
      if (param_4 != 1) {
        if (param_4 != 2) {
          return 0;
        }
        goto LAB_003db88d;
      }
LAB_003db80d:
      if (param_5 == 1) {
        nvDbg_Printf("src/kernel/gpu/mem_sys/arch/maxwell/kern_mem_sys_gm200.c",0x56,
                     "kmemsysCacheOp_GM200",1,
                     "NVRM: Invalidate not supported, promoting to an evict (writeback + invalidate clean lines).\n"
                    );
        (**(code **)(param_2 + 400))(param_1,param_2,0x70010,1,3,local_40);
      }
      else {
        if (1 < param_5 - 2) {
          return 0;
        }
        uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0x70010,1,3,local_40);
        if (param_5 != 3) {
          return uVar2;
        }
      }
      uVar2 = (**(code **)(param_2 + 400))(param_1,param_2,0x70004,1,3,local_40);
      return uVar2;
    }
    pcVar3 = "cache operation";
    if (param_5 == 0) {
      pcVar3 = "memory target";
    }
  }
  else {
    iVar1 = memdescGetAddressSpace(param_3);
    if (iVar1 == 2) {
      if (param_5 != 0) {
        kbusSendSysmembar_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1));
        timeoutSet(param_1 + 0x1af0,local_40,0,0);
LAB_003db88d:
        if (*(char *)(param_1 + 0x908) != '\0') {
          return 0;
        }
        if (param_5 != 3) {
          if (param_5 == 1) {
            uVar2 = kmemsysSendL2InvalidateEvict_IMPL(param_1,param_2,1);
            return uVar2;
          }
          return 0x56;
        }
        uVar2 = kmemsysSendL2InvalidateEvict_IMPL(param_1,param_2,0x11);
        return uVar2;
      }
    }
    else if (param_5 != 0) {
      kbusSendSysmembar_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1));
      timeoutSet(param_1 + 0x1af0,local_40,0,0);
      goto LAB_003db80d;
    }
    pcVar3 = "memory target";
  }
  nvDbg_Printf("src/kernel/gpu/mem_sys/arch/maxwell/kern_mem_sys_gm200.c",0x44,
               "kmemsysCacheOp_GM200",4,"NVRM: called with null %s\n",pcVar3);
  return 0;
}


// ===== 003dba20 kmemsysReadUsableFbSize_GP102 =====

undefined8 kmemsysReadUsableFbSize_GP102(long param_1,undefined8 param_2,ulong *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100ce0,0);
  uVar2 = (ulong)(uVar1 >> 4 & 0x3f) << ((byte)uVar1 & 0xf) + 0x14;
  if ((uVar1 & 0x40000000) != 0) {
    uVar2 = (uVar2 & 0xfffffffffffffff0) - (uVar2 >> 4);
  }
  *param_3 = uVar2;
  return 0;
}


// ===== 003dba90 kmemsysNeedInvalidateGpuCacheOnUnmap_T194 =====

uint kmemsysNeedInvalidateGpuCacheOnUnmap_T194
               (long param_1,undefined8 param_2,char param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 == '\0') {
    uVar1 = 1;
    if (1 < param_4 - 2U) {
      uVar1 = (uint)CONCAT71((int7)((ulong)*(long *)(param_1 + 0x1b78) >> 8),
                             *(char *)(*(long *)(param_1 + 0x1b78) + 0x447) == '\0') &
              CONCAT31((int3)(param_4 - 2U >> 8),param_4 == 4);
    }
  }
  return uVar1;
}


// ===== 003dbad0 kmemsysWriteL2SysmemInvalidateReg_TU102 =====

void kmemsysWriteL2SysmemInvalidateReg_TU102(long param_1,undefined8 param_2,undefined4 param_3)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf00,param_3,0);
  return;
}


// ===== 003dbb00 kmemsysReadL2SysmemInvalidateReg_TU102 =====

void kmemsysReadL2SysmemInvalidateReg_TU102(long param_1)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf00,0);
  return;
}


// ===== 003dbb30 kmemsysWriteL2PeermemInvalidateReg_TU102 =====

void kmemsysWriteL2PeermemInvalidateReg_TU102(long param_1,undefined8 param_2,undefined4 param_3)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf04,param_3,0);
  return;
}


// ===== 003dbb60 kmemsysReadL2PeermemInvalidateReg_TU102 =====

void kmemsysReadL2PeermemInvalidateReg_TU102(long param_1)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0xf04,0);
  return;
}


// ===== 003dbb90 kmemsysGetMaxFbpas_TU102 =====

undefined8 kmemsysGetMaxFbpas_TU102(void)

{
  return 0x10;
}


// ===== 003dbba0 kmemsysGetEccDedCountSize_TU102 =====

undefined8 kmemsysGetEccDedCountSize_TU102(void)

{
  return 2;
}


// ===== 003dbbb0 kmemsysGetEccDedCountRegAddr_TU102 =====

int kmemsysGetEccDedCountRegAddr_TU102
              (undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  return (param_3 * 0x1000 + 0x240122 + param_4) * 4;
}


// ===== 003dbbd0 kmemsysGetL2EccDedCountRegAddr_TU102 =====

int kmemsysGetL2EccDedCountRegAddr_TU102
              (undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  return (param_3 * 0x10 + param_4) * 0x200 + 0x1404f8;
}


// ===== 003dbbf0 kmemsysGetEccCounts_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysGetEccCounts_TU102(undefined8 param_1,long param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int local_3c;
  
  iVar1 = (**(code **)(param_2 + 0x248))();
  iVar2 = (**(code **)(param_2 + 0x250))(param_1,param_2);
  if ((param_3 != (int *)0x0) && (param_4 != (int *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    if ((iVar1 != 0) && (local_3c = 0, iVar2 != 0)) {
      do {
        iVar6 = 0;
        do {
          while( true ) {
            uVar3 = (**(code **)(param_2 + 600))(param_1,param_2,local_3c,iVar6);
            uVar4 = osGpuReadReg032(param_1,uVar3);
            uVar5 = 0;
            if ((uVar4 != 0xffffffff) && (uVar5 = 0, (uVar4 & 0xfff00000) != 0xbad00000)) {
              uVar5 = uVar4;
            }
            *param_3 = *param_3 + uVar5;
            uVar3 = (**(code **)(param_2 + 0x268))(param_1,param_2,local_3c,iVar6);
            uVar5 = osGpuReadReg032(param_1,uVar3);
            if ((uVar5 != 0xffffffff) && ((uVar5 & 0xfff00000) != 0xbad00000)) break;
            iVar6 = iVar6 + 1;
            *param_4 = *param_4;
            if (iVar6 == iVar2) goto LAB_003dbd1e;
          }
          *param_4 = *param_4 + (uVar5 >> 0x10);
          iVar6 = iVar6 + 1;
        } while (iVar6 != iVar2);
LAB_003dbd1e:
        local_3c = local_3c + 1;
      } while (local_3c != iVar1);
    }
  }
  return;
}


// ===== 003dbd40 _kmemsysResetAtsPeerConfiguration.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _kmemsysResetAtsPeerConfiguration_isra_0(long param_1,undefined4 param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulong local_38;
  undefined8 local_30;
  
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800afb,&local_60,0x18);
  if (uVar1 == 0) {
    local_48 = CONCAT44(local_48._4_4_,param_2);
    local_40 = 0;
    local_38 = local_58 & 0xffffffff;
    local_30 = CONCAT44(local_30._4_4_,(undefined4)local_50);
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800afc,&local_48,0x20);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "pLocalRmApi->Control(pLocalRmApi, pLocalGpu->hInternalClient, pLocalGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMSYS_SET_PEER_ATS_CONFIG, &setParams, sizeof(NV2080_CTRL_INTERNAL_MEMSYS_SET_PEER_ATS_CONFIG_PARAMS))"
                 ,"src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0xbf);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,
             "pLocalRmApi->Control(pLocalRmApi, pLocalGpu->hInternalClient, pLocalGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMSYS_GET_LOCAL_ATS_CONFIG, &getParams, sizeof(NV2080_CTRL_INTERNAL_MEMSYS_GET_LOCAL_ATS_CONFIG_PARAMS))"
             ,"src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0xb2);
  return (ulong)uVar1;
}


// ===== 003dbe70 _kmemsysConfigureAtsPeers.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _kmemsysConfigureAtsPeers_isra_0(long param_1,long param_2,undefined4 param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  uVar1 = (**(code **)(param_2 + 0x3b90))
                    (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                     *(undefined4 *)(param_2 + 0x3b3c),0x20800afb,&local_50,0x18);
  if (uVar1 == 0) {
    local_38 = CONCAT44(local_38._4_4_,param_3);
    local_30 = local_50;
    local_28 = local_48;
    local_20 = CONCAT44(local_20._4_4_,(undefined4)local_40);
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800afc,&local_38,0x20);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "pLocalRmApi->Control(pLocalRmApi, pLocalGpu->hInternalClient, pLocalGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMSYS_SET_PEER_ATS_CONFIG, &setParams, sizeof(NV2080_CTRL_INTERNAL_MEMSYS_SET_PEER_ATS_CONFIG_PARAMS))"
                 ,"src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x91);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,
             "pRemoteRmApi->Control(pRemoteRmApi, pRemoteGpu->hInternalClient, pRemoteGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MEMSYS_GET_LOCAL_ATS_CONFIG, &getParams, sizeof(NV2080_CTRL_INTERNAL_MEMSYS_GET_LOCAL_ATS_CONFIG_PARAMS))"
             ,"src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x85);
  return (ulong)uVar1;
}


// ===== 003dbfa0 kmemsysGetFbNumaInfo_GV100 =====

int kmemsysGetFbNumaInfo_GV100
              (undefined8 param_1,long param_2,undefined8 *param_3,undefined8 *param_4,
              undefined8 param_5,undefined4 *param_6)

{
  int iVar1;
  
  iVar1 = osGetFbNumaInfo(param_1,param_3,param_4,param_5,param_6);
  if (iVar1 == 0) {
    if (*(char *)(param_2 + 0x488) != '\0') {
      *param_3 = *(undefined8 *)(param_2 + 0x490);
      nvDbg_Printf("src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x42,
                   "kmemsysGetFbNumaInfo_GV100",1,
                   "NVRM: NUMA FB Physical address overrided to 0x%llx via regkey.\n");
    }
    nvDbg_Printf("src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x46,
                 "kmemsysGetFbNumaInfo_GV100",1,
                 "NVRM: NUMA FB Physical address: 0x%llx Size: 0x%llxsNode ID: 0x%x\n",*param_3,
                 *param_4,*param_6);
  }
  return iVar1;
}


// ===== 003dc070 kmemsysNeedInvalidateGpuCacheOnMap_GV100 =====

bool kmemsysNeedInvalidateGpuCacheOnMap_GV100
               (undefined8 param_1,undefined8 param_2,char param_3,int param_4)

{
  return param_3 == '\0' && param_4 - 2U < 3;
}


// ===== 003dc090 kmemsysSetupAllAtsPeers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysSetupAllAtsPeers_GV100(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int local_5c;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar3 = *(long *)(param_1 + 0x1ce8);
  local_44 = 0;
  if (lVar3 == 0) {
    nvCheckFailedNoLog(3,"pKernelNvlink != NULL",
                       "src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x167);
  }
  else {
    gpumgrGetGpuAttachInfo(local_4c,&local_48);
    while (lVar7 = gpumgrGetNextGpu(local_48,&local_44), lVar7 != 0) {
      if (((param_1 != lVar7) && (cVar5 = gpuIsGpuFullPower_IMPL(lVar7), cVar5 != '\0')) &&
         (cVar5 = knvlinkIsNvlinkP2pSupported_IMPL(param_1,lVar3,lVar7), cVar5 != '\0')) {
        local_40 = 0xffffffff;
        local_3c[0] = 0xffffffff;
        lVar4 = *(long *)(lVar7 + 0x1b70);
        if (*(long *)(param_1 + 0x1ce8) != 0) {
          knvlinkTrainP2pLinksToActive_IMPL(param_1,lVar7);
        }
        uVar9 = 0x13;
        iVar6 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x270))
                          (param_1,*(long *)(&DAT_00001b90 + param_1),lVar7,
                           *(undefined8 *)(&DAT_00001b90 + lVar7),&local_40,local_3c);
        if (iVar6 != 0) {
          return iVar6;
        }
        if (((lVar4 != 0) && (param_2 != 0)) &&
           ((*(char *)(param_1 + 0x45b) != '\0' && (*(char *)(lVar7 + 0x45b) != '\0')))) {
          uVar9 = _kmemsysConfigureAtsPeers_isra_0(param_1,lVar7,local_40,uVar9);
          local_5c = (int)uVar9;
          if (local_5c != 0) {
            uVar2 = *(undefined4 *)(lVar7 + 0x7a4);
            uVar8 = 0xfc;
            uVar1 = *(undefined4 *)(param_1 + 0x7a4);
            goto LAB_003dc21a;
          }
          uVar9 = _kmemsysConfigureAtsPeers_isra_0(lVar7,param_1,local_3c[0]);
          local_5c = (int)uVar9;
          if (local_5c != 0) {
            uVar1 = *(undefined4 *)(lVar7 + 0x7a4);
            uVar2 = *(undefined4 *)(param_1 + 0x7a4);
            uVar8 = 0x106;
LAB_003dc21a:
            nvDbg_Printf("src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",uVar8,
                         "_kmemsysSetupAtsPeers",4,
                         "NVRM: Configuring ATS p2p config between GPU%u and GPU%u failed with status %x\n"
                         ,uVar1,uVar2,uVar9);
            return local_5c;
          }
        }
      }
    }
  }
  return 0;
}


// ===== 003dc2d0 kmemsysRemoveAllAtsPeers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysRemoveAllAtsPeers_GV100(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined1 auVar7 [16];
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined4 local_3c [3];
  
  local_3c[0] = 0;
  gpumgrGetGpuAttachInfo(local_44,&local_40);
  uVar6 = extraout_RDX;
  while( true ) {
    auVar7 = gpumgrGetNextGpu(local_40,local_3c,uVar6);
    uVar6 = auVar7._8_8_;
    lVar5 = auVar7._0_8_;
    if (lVar5 == 0) break;
    if (lVar5 != param_1) {
      cVar1 = gpuIsGpuFullPower_IMPL(lVar5);
      uVar6 = extraout_RDX_00;
      if ((cVar1 != '\0') && (*(long *)(lVar5 + 0x1b70) != 0)) {
        uVar2 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x288))
                          (param_1,*(long *)(&DAT_00001b90 + param_1),lVar5);
        uVar3 = (**(code **)(*(long *)(&DAT_00001b90 + lVar5) + 0x288))
                          (lVar5,*(long *)(&DAT_00001b90 + lVar5),param_1);
        iVar4 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x278))
                          (param_1,*(long *)(&DAT_00001b90 + param_1),lVar5,
                           *(undefined8 *)(&DAT_00001b90 + lVar5),uVar2,uVar3);
        if (iVar4 == 0) {
          uVar6 = extraout_RDX_01;
          if (((param_2 != 0) && (*(char *)(param_1 + 0x45b) != '\0')) &&
             (*(char *)(lVar5 + 0x45b) != '\0')) {
            uVar6 = _kmemsysResetAtsPeerConfiguration_isra_0(param_1,uVar2);
            if ((int)uVar6 != 0) {
              nvDbg_Printf("src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x13f,
                           "_kmemsysRemoveAtsPeers",4,
                           "NVRM: Removing ATS p2p config between GPU%u and GPU%u failed with status %x\n"
                           ,*(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar5 + 0x7a4),uVar6);
            }
            auVar7 = _kmemsysResetAtsPeerConfiguration_isra_0(lVar5,uVar3);
            uVar6 = auVar7._8_8_;
            if (auVar7._0_4_ != 0) {
              uVar6 = auVar7._0_8_;
              nvDbg_Printf("src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x148,
                           "_kmemsysRemoveAtsPeers",4,
                           "NVRM: Removinging ATS p2p config between GPU%u and GPU%u failed with status %x\n"
                           ,*(undefined4 *)(lVar5 + 0x7a4),*(undefined4 *)(param_1 + 0x7a4));
            }
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_sys/arch/volta/kern_mem_sys_gv100.c",0x1a0,
                       "kmemsysRemoveAllAtsPeers_GV100",4,
                       "NVRM: Failed to remove ATS peer access between GPU%d and GPU%d\n",
                       *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar5 + 0x7a4));
          uVar6 = extraout_RDX_02;
        }
      }
    }
  }
  return;
}


// ===== 003dc4c0 kmemsysCheckReadoutEccEnablement_GV100 =====

uint kmemsysCheckReadoutEccEnablement_GV100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x409660,0);
  return uVar1 >> 0x10 & 1;
}


// ===== 003dc4f0 kmemsysConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysConstructEngine_IMPL(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  uint local_1c;
  
  *(undefined8 *)(param_2 + 0x2b8) = 0;
  iVar1 = osReadRegistryDword(param_1,"RmL2CleanFbPull",&local_1c);
  if ((iVar1 == 0) && (local_1c == 1)) {
    *(undefined1 *)(param_2 + 0x29b) = 0;
  }
  iVar1 = osReadRegistryDword(param_1,"RMOverrideToGMK",&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    *(uint *)(param_2 + 0x2a4) = local_1c;
  }
  iVar1 = osReadRegistryDword(param_1,"RmOverrideCoherentCpuFbBase",&local_1c);
  if (iVar1 == 0) {
    *(undefined1 *)(param_2 + 0x488) = 1;
    *(ulong *)(param_2 + 0x490) = (ulong)local_1c << 0x20;
  }
  iVar1 = osReadRegistryDword(param_1,"RmOverrideNonPasidAtsSupport",&local_1c);
  if (iVar1 == 0) {
    *(undefined1 *)(param_2 + 0x498) = 1;
    *(bool *)(param_2 + 0x499) = local_1c != 0;
  }
  uVar2 = 0;
  if (*(char *)(param_1 + 0x909) != '\0') {
    uVar2 = (**(code **)(param_2 + 0x1c8))(param_1,param_2);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"kmemsysInitFlushSysmemBuffer_HAL(pGpu, pKernelMemorySystem)",
                 "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x5c);
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}


// ===== 003dc630 kmemsysStatePreInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysStatePreInitLocked_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = portMemAllocNonPaged(0x28);
  if (lVar2 == 0) {
    nvAssertOkFailedNoLog
              (0x1a,"(pStaticConfig != NULL)","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x6f);
    uVar1 = 0x1a;
  }
  else {
    portMemSet(lVar2,0,0x28);
    *(long *)(param_2 + 0x2b0) = lVar2;
    uVar3 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a1c,lVar2,0x28);
    uVar1 = (uint)uVar3;
    if (uVar1 == 0) {
      return uVar3;
    }
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,
               "kmemsysInitStaticConfig_HAL( pGpu, pKernelMemorySystem, pStaticConfig)",
               "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x7a);
  }
  portMemFree(*(undefined8 *)(param_2 + 0x2b0));
  *(undefined8 *)(param_2 + 0x2b0) = 0;
  return (ulong)uVar1;
}


// ===== 003dc730 kmemsysStatePreLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long kmemsysStatePreLoad_IMPL(long param_1,long param_2)

{
  char cVar1;
  
  (**(code **)(param_2 + 0x1d0))();
  if (((*(char *)(param_1 + 0x4915) != '\0') && (*(char *)(param_1 + 0x454) != '\0')) &&
     (cVar1 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0)), cVar1 != '\0')) {
    return (ulong)(*(char *)(param_2 + 0x29a) == '\0') << 6;
  }
  return 0;
}


// ===== 003dc7a0 kmemsysStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysStatePostLoad_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  
  if ((*(char *)(param_1 + 0x446) != '\0') || (*(char *)(param_1 + 0x490e) != '\0')) {
    return 0;
  }
  cVar1 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
  if ((cVar1 == '\0') || (*(char *)(param_1 + 0x45b) != '\0')) {
    if (((*(char *)(param_1 + 0x446) == '\0') &&
        (((*(char *)(param_1 + 0x490e) == '\0' &&
          (cVar1 = hypervisorIsVgxHyper_IMPL(), cVar1 == '\0')) &&
         (*(char *)(param_1 + 0x45b) != '\0')))) &&
       ((*(long *)(param_1 + 0x1ce8) != 0 && (*(char *)(param_1 + 0x4cc) != '\x01')))) {
      iVar2 = (**(code **)(param_2 + 0x230))(param_1,param_2);
      if (iVar2 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x12e,"kmemsysStatePostLoad_IMPL",4,
                   "NVRM: ATS peer setup failed.\n");
      return iVar2;
    }
    iVar2 = 0;
  }
  else {
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                        "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x118);
    iVar2 = 0x40;
  }
  return iVar2;
}


// ===== 003dc8b0 kmemsysStatePreUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmemsysStatePreUnload_IMPL(long param_1,long param_2)

{
  char cVar1;
  
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
    cVar1 = hypervisorIsVgxHyper_IMPL();
    if ((cVar1 == '\0') &&
       ((*(char *)(param_1 + 0x45b) != '\0' && (*(char *)(param_1 + 0x4cc) != '\x01')))) {
      (**(code **)(param_2 + 0x238))(param_1,param_2);
    }
    return 0;
  }
  return 0;
}


// ===== 003dc920 kmemsysStateDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysStateDestroy_IMPL(long param_1,long param_2)

{
  if (((*(long *)(param_1 + 7000) != 0) && (*(char *)(*(long *)(param_1 + 7000) + 0x3a8) != '\0'))
     && (*(char *)(param_1 + 0x454) != '\0')) {
    (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x528))
              (param_1,*(long *)(&DAT_00001b90 + param_1),0);
    *(undefined1 *)(param_1 + 0x454) = 0;
    portMemFree(*(undefined8 *)(param_2 + 0x2b0));
    return;
  }
  portMemFree(*(undefined8 *)(param_2 + 0x2b0));
  return;
}


// ===== 003dc9a0 kmemsysGetStaticConfig_IMPL =====

undefined8 kmemsysGetStaticConfig_IMPL(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    return *(undefined8 *)(param_2 + 0x2b0);
  }
  nvAssertFailedNoLog("pKernelMemorySystem != NULL","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x16c);
  return 0;
}


// ===== 003dc9e0 kmemsysDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void kmemsysDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  lVar2 = *(long *)(param_1 + 0x2b8);
  if (lVar2 != 0) {
    if (*(char *)(param_1 + 0x29a) == '\x01') {
      (**(code **)(param_1 + 0x210))(uVar1,param_1,*(code **)(param_1 + 0x210));
      lVar2 = *(long *)(param_1 + 0x2b8);
    }
    portMemFree(lVar2);
  }
  *(undefined8 *)(param_1 + 0x468) = 0;
  memdescFree(*(undefined8 *)(param_1 + 0x460));
  memdescDestroy(*(undefined8 *)(param_1 + 0x460));
  *(undefined8 *)(param_1 + 0x460) = 0;
  portMemSet(param_1 + 0x2d8,0,0x168);
  return;
}


// ===== 003dca90 kmemsysAllocComprResources_KERNEL =====

int kmemsysAllocComprResources_KERNEL
              (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
              uint *param_6)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int local_3c [3];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelMemorySystem != NULL","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x16c)
    ;
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = *(char **)(param_2 + 0x2b0);
  }
  iVar3 = vgpuGetCallingContextGfid(param_1,local_3c);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x1a4);
    return iVar3;
  }
  if (*pcVar4 == '\0') {
    if (pcVar4[2] == '\0') {
      nvAssertFailedNoLog("pMemorySystemConfig->bOneToOneComptagLineAllocation || pMemorySystemConfig->bUseRawModeComptaglineAllocation"
                          ,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0x1a6);
      return 0x40;
    }
    if (*(uint *)(param_3 + 0xa4) >> 0x1e == 1) goto LAB_003dcc38;
    if (*(char *)(lVar1 + 0x480) != '\0') goto LAB_003dcb1f;
  }
  else {
    if (*(uint *)(param_3 + 0xa4) >> 0x1e == 1) {
LAB_003dcc38:
      nvCheckFailedNoLog(4,
                         "!FLD_TEST_DRF(OS32, _ALLOC, _COMPTAG_OFFSET_USAGE, _FIXED, pFbAllocInfo->ctagOffset)"
                         ,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0x1a9);
      return 0x1f;
    }
    if (*(char *)(lVar1 + 0x480) != '\0') {
      if (*(char *)(lVar1 + 0x485) == '\0') {
        nvAssertFailedNoLog("memmgrUseVasForCeMemoryOps(pMemoryManager)",
                            "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x1c0);
        return 0x40;
      }
      goto LAB_003dcb1f;
    }
  }
  if ((((*(char *)(param_1 + 0x490e) == '\0') &&
       (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')) &&
      (cVar2 = hypervisorIsVgxHyper_IMPL(), cVar2 == '\0')) && (local_3c[0] == 0)) {
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x1b9,"kmemsysAllocComprResources_KERNEL",4
                 ,
                 "NVRM: Compressible surfaces cannot be allocated on a system, where scrub on free is disabled\n"
                );
    return 0x40;
  }
LAB_003dcb1f:
  *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 0xffff;
  *param_6 = *param_6 & 0xffffcfff | 0x1000;
  return 0;
}


// ===== 003dcc80 kmemsysSwizzIdToMIGMemSize_IMPL =====

undefined8
kmemsysSwizzIdToMIGMemSize_IMPL
          (long param_1,undefined8 param_2,uint param_3,ulong param_4,ulong param_5,
          undefined4 *param_6,ulong *param_7)

{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar1 = (param_5 + 1) - param_4 >> 3;
  if (param_5 < param_4) {
    uVar1 = 0;
  }
  if (param_3 < 7) {
    if (param_3 < 3) {
      if (param_3 == 0) {
        uVar1 = uVar1 << 3;
        uVar2 = 0;
      }
      else {
        uVar1 = uVar1 << 2;
        uVar2 = 1;
      }
    }
    else {
      uVar1 = uVar1 * 2;
      uVar2 = 2;
    }
  }
  else {
    if (7 < param_3 - 7) {
      nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x226,"kmemsysSwizzIdToMIGMemSize_IMPL",4
                   ,"NVRM: Unsupported SwizzId %d\n",param_3);
      return 0x1f;
    }
    uVar2 = 3;
  }
  *param_7 = uVar1;
  *param_6 = uVar2;
  if (((*param_7 == 0) && (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')) &&
     (*(char *)(param_1 + 0x44d) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x230,"kmemsysSwizzIdToMIGMemSize_IMPL",4,
                 "NVRM: Insufficient memory\n");
    return 0x1a;
  }
  return 0;
}


// ===== 003dcd80 kmemsysSwizzIdToMIGMemRange_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysSwizzIdToMIGMemRange_IMPL
              (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,ulong param_5,
              ulong *param_6)

{
  long lVar1;
  int iVar2;
  undefined1 auVar3 [16];
  
  lVar1 = *(long *)(param_1 + 0x1bc0);
  if (param_5 < param_4) {
    nvAssertFailedNoLog("!rangeIsEmpty(totalRange)","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x24c);
    return 0x1f;
  }
  iVar2 = kmemsysSwizzIdToMIGMemSize_IMPL();
  if (iVar2 == 0) {
    auVar3 = (**(code **)(lVar1 + 0x238))(param_1,lVar1,0);
    if (auVar3._8_8_ < auVar3._0_8_) {
      nvAssertFailedNoLog("!rangeIsEmpty(swizzIdRange)","src/kernel/gpu/mem_sys/kern_mem_sys.c",
                          0x253);
      return 0x1f;
    }
    *param_6 = param_4;
    param_6[1] = param_4 - 1;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,
               "kmemsysSwizzIdToMIGMemSize(pGpu, pKernelMemorySystem, swizzId, totalRange, &memSizeFlag, &memSize)"
               ,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0x24f);
  }
  return iVar2;
}


// ===== 003dced0 kmemsysGetMIGGPUInstanceMemInfo_IMPL =====

int kmemsysGetMIGGPUInstanceMemInfo_IMPL(long param_1,long param_2,uint param_3,ulong *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long local_30 [2];
  
  if (param_4 == (ulong *)0x0) {
    nvAssertFailedNoLog("pAddrRange != NULL","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x26f);
    return 0x1f;
  }
  *param_4 = 1;
  param_4[1] = 0;
  if (0xe < param_3) {
    nvAssertFailedNoLog("swizzId < KMIGMGR_MAX_GPU_SWIZZID","src/kernel/gpu/mem_sys/kern_mem_sys.c",
                        0x271);
    return 0x40;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')
     ) {
    lVar1 = *(long *)(param_1 + 0x3b10);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("(vmmuSegmentSize != 0)","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x284);
      return 0x40;
    }
    uVar7 = (ulong)param_3;
    uVar6 = *(long *)(param_2 + 0x2d8 + uVar7 * 0x18) * lVar1;
    uVar5 = lVar1 * *(long *)(param_2 + 0x2e0 + uVar7 * 0x18);
    cVar2 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
    uVar4 = uVar6;
    if (cVar2 != '\0') {
      iVar3 = osNumaMemblockSize(local_30);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,"osNumaMemblockSize(&memblockSize)","src/kernel/gpu/mem_sys/kern_mem_sys.c"
                   ,0x28e);
        return iVar3;
      }
      uVar4 = local_30[0] + -1 + uVar6 & -local_30[0];
      if (*(char *)(param_2 + 0x530) == '\0') {
        uVar5 = (uVar6 + uVar5) - uVar4;
      }
      else {
        uVar5 = *(ulong *)(param_2 + 0x4b8 + uVar7 * 8);
      }
      uVar5 = -local_30[0] & uVar5;
    }
    *param_4 = uVar4;
    param_4[1] = (uVar4 - 1) + uVar5;
  }
  return 0;
}


// ===== 003dd080 kmemsysPopulateMIGGPUInstanceMemConfig_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysPopulateMIGGPUInstanceMemConfig_KERNEL(long param_1,long param_2)

{
  ulong *puVar1;
  long lVar2;
  ulong uVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong *puVar12;
  ulong *puVar13;
  ulong uVar14;
  int iVar15;
  undefined1 auVar16 [16];
  long local_48;
  long local_40;
  
  auVar16 = memmgrGetMIGPartitionableMemoryRange_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
  lVar8 = auVar16._8_8_;
  uVar14 = auVar16._0_8_;
  if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')
     ) {
    lVar2 = *(long *)(param_1 + 0x1bc0);
    cVar4 = kmigmgrIsMIGSupported_IMPL(param_1,lVar2);
    if (cVar4 != '\0') {
      uVar10 = *(ulong *)(param_1 + 0x3b10);
      if (uVar10 == 0) {
        nvAssertFailedNoLog("(vmmuSegmentSize != 0)","src/kernel/gpu/mem_sys/kern_mem_sys.c",0x2ea);
        return 0x40;
      }
      lVar9 = 1;
      if (uVar14 != 0) {
        if ((uVar10 - 1 & uVar14) == 0) {
          lVar9 = (1 - uVar14) - uVar10;
        }
        else {
          lVar9 = 1 - (-uVar10 & (uVar10 - 1) + uVar14);
        }
      }
      lVar6 = lVar8 - uVar10;
      if ((lVar8 + 1U & uVar10 - 1) != 0) {
        lVar6 = lVar8;
      }
      iVar15 = 0;
      do {
        iVar5 = (**(code **)(param_2 + 0x1f8))
                          (param_1,param_2,iVar15,uVar10 & 0xffffffff,
                           (ulong)(lVar6 + lVar9) / uVar10 & 0xffffffff);
        if (iVar5 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar5,
                     "kmemsysSwizzIdToVmmuSegmentsRange_HAL(pGpu, pKernelMemorySystem, swizzId, vmmuSegmentSize, totalVmmuSegments)"
                     ,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0x2fd);
          return iVar5;
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 != 0xf);
      cVar4 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
      if (cVar4 == '\0') {
        return 0;
      }
      uVar14 = 0;
      local_40 = 0;
      local_48 = 1;
      do {
        kmemsysGetMIGGPUInstanceMemInfo_IMPL(param_1,param_2,uVar14 & 0xffffffff,&local_48);
        *(long *)(param_2 + 0x4b8 + uVar14 * 8) = (local_40 + 1) - local_48;
        uVar14 = uVar14 + 1;
      } while (uVar14 != 0xf);
      iVar15 = 0;
      do {
        auVar16 = (**(code **)(lVar2 + 0x238))(param_1,lVar2,iVar15);
        uVar10 = auVar16._8_8_;
        uVar14 = auVar16._0_8_;
        if (uVar14 <= uVar10) {
          uVar11 = uVar14 + 1;
          uVar7 = *(ulong *)(param_2 + 0x4b8 + uVar14 * 8);
          if (uVar11 <= uVar10) {
            if ((auVar16._8_4_ - auVar16._0_4_ & 1U) != 0) {
              uVar11 = *(ulong *)(param_2 + 0x4b8 + uVar11 * 8);
              if (uVar11 < uVar7) {
                uVar7 = uVar11;
              }
              uVar11 = uVar14 + 2;
              if (uVar10 < uVar11) goto LAB_003dd2e7;
            }
            do {
              uVar3 = *(ulong *)(param_2 + 0x4b8 + uVar11 * 8);
              if (uVar3 < uVar7) {
                uVar7 = uVar3;
              }
              uVar3 = *(ulong *)(param_2 + 0x4c0 + uVar11 * 8);
              if (uVar3 < uVar7) {
                uVar7 = uVar3;
              }
              uVar11 = uVar11 + 2;
            } while (uVar11 <= uVar10);
          }
LAB_003dd2e7:
          puVar1 = (ulong *)(param_2 + 0x4c0 + uVar10 * 8);
          puVar13 = (ulong *)(param_2 + 0x4b8 + uVar14 * 8);
          puVar12 = puVar13;
          if (((int)puVar1 - (int)puVar13 & 8U) != 0) {
            *puVar13 = uVar7;
            puVar12 = puVar13 + 1;
            if (puVar13 + 1 == puVar1) goto LAB_003dd320;
          }
          do {
            *puVar12 = uVar7;
            puVar13 = puVar12 + 2;
            puVar12[1] = uVar7;
            puVar12 = puVar13;
          } while (puVar13 != puVar1);
        }
LAB_003dd320:
        iVar15 = iVar15 + 1;
        if (iVar15 == 4) {
          *(undefined1 *)(param_2 + 0x530) = 1;
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}


// ===== 003dd3a0 kmemsysGetMIGGPUInstanceMemConfigFromSwizzId_IMPL =====

undefined8
kmemsysGetMIGGPUInstanceMemConfigFromSwizzId_IMPL
          (long param_1,long param_2,uint param_3,long *param_4)

{
  if (0xe < param_3) {
    nvAssertFailedNoLog("swizzId < KMIGMGR_MAX_GPU_SWIZZID","src/kernel/gpu/mem_sys/kern_mem_sys.c",
                        0x328);
    return 0x1f;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')
     ) {
    if (*(char *)(param_2 + 0x2e8 + (ulong)param_3 * 0x18) != '\0') {
      *param_4 = param_2 + 0x2d8 + (ulong)param_3 * 0x18;
      return 0;
    }
    nvAssertFailedNoLog("pKernelMemorySystem->gpuInstanceMemConfig[swizzId].bInitialized",
                        "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x334);
    return 0x40;
  }
  return 0x56;
}


// ===== 003dd430 kmemsysInitMIGGPUInstanceMemConfigForSwizzId_IMPL =====

undefined1  [16]
kmemsysInitMIGGPUInstanceMemConfigForSwizzId_IMPL
          (undefined8 param_1,long param_2,uint param_3,undefined8 param_4,ulong param_5)

{
  undefined1 auVar1 [16];
  ulong uVar2;
  undefined8 extraout_RDX;
  undefined1 auVar3 [16];
  
  if (param_3 < 0xf) {
    uVar2 = (ulong)param_3;
    *(undefined8 *)(param_2 + 0x2d8 + uVar2 * 0x18) = param_4;
    *(ulong *)(param_2 + 0x2e0 + uVar2 * 0x18) = param_5;
    *(undefined1 *)(param_2 + 0x2e8 + uVar2 * 0x18) = 1;
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x34d,
                 "kmemsysInitMIGGPUInstanceMemConfigForSwizzId_IMPL",1,
                 "NVRM: GPU Instance Mem Config for swizzId = 0x%x : MemStartSegment = 0x%llx, MemSizeInSegments = 0x%llx\n"
                 ,param_3,param_4);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_5;
    return auVar1 << 0x40;
  }
  nvAssertFailedNoLog("swizzId < KMIGMGR_MAX_GPU_SWIZZID","src/kernel/gpu/mem_sys/kern_mem_sys.c",
                      0x347);
  auVar3._8_8_ = extraout_RDX;
  auVar3._0_8_ = 0x1f;
  return auVar3;
}


// ===== 003dd4b0 kmemsysSetupCoherentCpuLink_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysSetupCoherentCpuLink_IMPL(long param_1,long param_2,undefined1 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  int local_68;
  int local_64;
  long local_60;
  long local_58;
  long local_50;
  long local_48;
  long local_40 [2];
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  local_60 = 0;
  lVar7 = *(long *)(param_1 + 0x1b78);
  local_64 = -1;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40[0] = 0;
  iVar5 = osReadRegistryDword(param_1,"RMForceBarPath",&local_68);
  if ((iVar5 == 0) && (local_68 == 1)) {
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x394,"kmemsysSetupCoherentCpuLink_IMPL",4,
                 "NVRM: Force disabling NVLINK/C2C mappings through regkey.\n");
    return 0;
  }
  iVar5 = (**(code **)(param_2 + 0x168))
                    (param_1,param_2,param_2 + 0x478,&local_60,param_2 + 0x4a0,&local_64);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,
               "kmemsysGetFbNumaInfo_HAL(pGpu, pKernelMemorySystem, &pKernelMemorySystem->coherentCpuFbBase, &coherentCpuFbSize, &pKernelMemorySystem->coherentRsvdFbBase, &numaNodeId)"
               ,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0x399);
    return iVar5;
  }
  if (local_60 == 0) {
    if (*(char *)(param_1 + 0x4912) != '\0') {
      iVar5 = (**(code **)(param_2 + 0x180))(param_1,param_2,&local_60);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kmemsysReadHdmTopFromVbios_HAL(pGpu, pKernelMemorySystem, &coherentCpuFbSize)",
                   "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x3a7);
        return iVar5;
      }
      if (local_60 != 0) goto LAB_003dd5a1;
    }
    local_60 = *(long *)(lVar7 + 0x830) << 0x14;
  }
LAB_003dd5a1:
  iVar5 = osReadRegistryDword(param_1,"RMOverrideGpuNumaNodeId",&local_68);
  if (iVar5 == 0) {
    local_64 = local_68;
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x3b5,"kmemsysSetupCoherentCpuLink_IMPL",4,
                 "NVRM: Override GPU NUMA node ID %d!\n");
  }
  iVar5 = osReadRegistryDword(param_1,"EnableUserNUMAManagement",&local_68);
  if ((((iVar5 == 0 && local_68 == 0) || (*(char *)(param_1 + 0x446) != '\0')) ||
      (*(char *)(param_1 + 0x490e) != '\0')) ||
     ((local_64 != -1 || (cVar4 = hypervisorIsVgxHyper_IMPL(), cVar4 != '\0')))) {
    if (*(long *)(param_2 + 0x478) != 0) {
      *(long *)(param_2 + 0x480) = *(long *)(param_2 + 0x478) + local_60;
      iVar5 = osNumaMemblockSize(&local_58);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"osNumaMemblockSize(&memblockSize)","src/kernel/gpu/mem_sys/kern_mem_sys.c"
                   ,0x3d6);
        return iVar5;
      }
      (**(code **)(lVar7 + 800))(param_1,lVar7,&local_50,&local_48,local_40);
      lVar2 = *(long *)(lVar7 + 0x498);
      lVar6 = local_48 + local_50 + local_40[0];
      lVar3 = *(long *)(lVar7 + 0x850);
      lVar7 = (**(code **)(lVar7 + 0x220))(param_1,lVar7);
      uVar8 = lVar7 + lVar6 + lVar3 + (lVar2 + 0xffffU & 0xffffffffffff0000);
      if ((*(char *)(param_1 + 0x4912) == '\0') || (*(char *)(param_2 + 0x2a1) == '\0')) {
        uVar9 = -local_58 & local_60 - uVar8;
      }
      else {
        if (0x40000000 < uVar8) {
          nvAssertFailedNoLog("rsvdSize >= totalRsvdBytes","src/kernel/gpu/mem_sys/kern_mem_sys.c",
                              0x3f8);
          return 0x40;
        }
        uVar8 = 0x40000000;
        uVar9 = local_60 - 0x40000000U & 0xffffffffe0000000;
      }
      nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x404,"kmemsysSetupCoherentCpuLink_IMPL",
                   1,
                   "NVRM: coherentCpuFbSize: 0x%llx NUMA reserved memory size: 0x%llx online memory size: 0x%llx\n"
                   ,local_60,uVar8,uVar9);
      cVar4 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0));
      if (cVar4 != '\0') {
        *(ulong *)(param_2 + 0x4b0) = uVar9;
        *(undefined8 *)(param_2 + 0x4a8) = 0;
        iVar5 = (**(code **)(param_2 + 0x200))(param_1,param_2,0,0,uVar9,&local_64);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "kmemsysNumaAddMemory_HAL(pGpu, pKernelMemorySystem, 0, 0, numaOnlineSize, &numaNodeId)"
                     ,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0x419);
        }
      }
      *(int *)(param_1 + 0x7bc) = local_64;
      iVar5 = (**(code **)(lVar1 + 0x510))(param_1,lVar1,uVar9,param_3);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kbusCreateCoherentCpuMapping_HAL(pGpu, pKernelBus, numaOnlineSize, bFlush)",
                   "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x41e);
        return iVar5;
      }
      *(undefined1 *)(param_1 + 0x454) = 1;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x3d0,"kmemsysSetupCoherentCpuLink_IMPL",4,
                 "NVRM: Failed to get coherent GPU memory base address\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0x3c9,"kmemsysSetupCoherentCpuLink_IMPL",4,
                 "NVRM: Failed to get NUMA node id for GPU memory\n");
  }
  return 0x40;
}


// ===== 003dd9b0 kmemsysStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysStateInitLocked_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  if (((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) &&
     (uVar3 = (**(code **)(param_2 + 0x1c8))(), uVar3 != 0)) {
    nvAssertOkFailedNoLog
              (uVar3,"kmemsysEnsureSysmemFlushBufferInitialized(pGpu, pKernelMemorySystem)",
               "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x9a);
    return (ulong)uVar3;
  }
  lVar6 = *(long *)(param_1 + 7000);
  lVar4 = portMemAllocNonPaged(0x1e0);
  *(long *)(param_2 + 0x2b8) = lVar4;
  if (lVar4 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0xa1,"kmemsysStateInitLocked_IMPL",4,
                 "NVRM: Failed to allocate memory for numa information.\n");
    nvAssertFailedNoLog(&DAT_00d5a49e,"src/kernel/gpu/mem_sys/kern_mem_sys.c",0xa3);
    return 0x51;
  }
  portMemSet(lVar4,0,0x1e0);
  if (((*(char *)(param_1 + 0x4915) == '\0') || (lVar6 == 0)) || (*(char *)(lVar6 + 0x3a8) == '\0'))
  goto LAB_003dda50;
  if (*(char *)(param_1 + 0x909) == '\0') {
LAB_003dda8d:
    if (*(char *)(param_1 + 0x4913) != '\0') goto LAB_003ddb42;
  }
  else {
    lVar6 = gpuGetGspStaticInfo(param_1);
    if (*(char *)(lVar6 + 0x60d) != '\0') {
      nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys.c",0xb9,"kmemsysStateInitLocked_IMPL",1,
                   "NVRM: ATS supported\n");
      *(undefined1 *)(param_1 + 0x45b) = 1;
    }
    if (*(char *)(param_1 + 0x909) == '\0') goto LAB_003dda8d;
LAB_003ddb42:
    *(undefined1 *)(param_1 + 0x49b) = 1;
  }
  uVar3 = kmemsysSetupCoherentCpuLink_IMPL(param_1,param_2,0);
  if (uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3,"kmemsysSetupCoherentCpuLink(pGpu, pKernelMemorySystem, NV_FALSE)",
               "src/kernel/gpu/mem_sys/kern_mem_sys.c",0xcf);
    return (ulong)uVar3;
  }
  if ((*(char *)(param_1 + 0x4915) != '\0') && (*(char *)(param_1 + 0x454) != '\0')) {
    cVar2 = rmcfg_IsHOPPER_CLASSIC_GPUS(param_1);
    if (cVar2 != '\0') {
      *(undefined1 *)(lVar1 + 0xad45) = 1;
    }
    *(undefined1 *)(lVar1 + 0xad46) = 1;
  }
LAB_003dda50:
  uVar5 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x4f0))(param_1);
  if ((int)uVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar5 & 0xffffffff,"kgmmuCheckAndDecideBigPageSize_HAL(pGpu, pKernelGmmu)",
               "src/kernel/gpu/mem_sys/kern_mem_sys.c",0xe4);
    uVar5 = uVar5 & 0xffffffff;
  }
  return uVar5;
}


// ===== 003ddc40 kmemsysTeardownCoherentCpuLink_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysTeardownCoherentCpuLink_IMPL(long param_1,undefined8 param_2,undefined1 param_3)

{
  (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x528))
            (param_1,*(long *)(&DAT_00001b90 + param_1),param_3);
  *(undefined1 *)(param_1 + 0x454) = 0;
  return;
}


// ===== 003ddc80 kmemsysSendL2InvalidateEvict_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysSendL2InvalidateEvict_IMPL(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_c;
  
  local_c = param_3;
  (**(code **)(param_1 + 0x3b90))
            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
             0x20800a6c,&local_c,4);
  return;
}


// ===== 003ddcc0 kmemsysSendFlushL2AllRamsAndCaches_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysSendFlushL2AllRamsAndCaches_IMPL(long param_1)

{
  (**(code **)(param_1 + 0x3b90))
            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
             0x20800a6d,0,0);
  return;
}


// ===== 003ddcf0 kmemsysGetUsableFbSize_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmemsysGetUsableFbSize_KERNEL(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x170))();
  return;
}


// ===== 003ddd00 kmemsysStateLoad_IMPL =====

ulong kmemsysStateLoad_IMPL(long param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  
  if (((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x908) != '\0')) &&
     ((param_3 & 0x25) == 5)) {
    uVar1 = *(undefined8 *)(param_1 + 0x1b78);
    uVar2 = memmgrRestorePowerMgmtState_KERNEL(param_1,uVar1);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"memmgrRestorePowerMgmtState(pGpu, pMemoryManager)",
                 "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x471);
      memmgrFreeFbsrMemory_KERNEL(param_1,uVar1);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  return 0;
}


// ===== 003ddd90 kmemsysStateUnload_IMPL =====

ulong kmemsysStateUnload_IMPL(long param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  
  if (((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x908) != '\0')) &&
     ((param_3 & 0x25) == 5)) {
    uVar1 = *(undefined8 *)(param_1 + 0x1b78);
    uVar2 = memmgrSavePowerMgmtState_KERNEL(param_1,uVar1);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"memmgrSavePowerMgmtState(pGpu, pMemoryManager)",
                 "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x487);
      memmgrFreeFbsrMemory_KERNEL(param_1,uVar1);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  return 0;
}


// ===== 003dde20 kmemsysPostHeapCreate_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmemsysPostHeapCreate_KERNEL(long param_1)

{
  ulong uVar1;
  
  if (*(char *)(param_1 + 0x454) == '\0') {
    return 0;
  }
  uVar1 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x4d0))();
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,"kbusVerifyCoherentLink_HAL(pGpu, GPU_GET_KERNEL_BUS(pGpu))",
             "src/kernel/gpu/mem_sys/kern_mem_sys.c",0x49c);
  return uVar1 & 0xffffffff;
}


// ===== 003dde80 kmemsysGetCpuCoherentFbRange_IMPL =====

undefined8
kmemsysGetCpuCoherentFbRange_IMPL(long param_1,long param_2,long *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  if ((param_3 == (long *)0x0) || (param_4 == (undefined8 *)0x0)) {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0x56;
    if (*(char *)(param_1 + 0x4915) != '\0') {
      if (*(long *)(param_2 + 0x478) == 0) {
        *param_3 = 0;
        *param_4 = 0;
        return 0;
      }
      *param_3 = *(long *)(param_2 + 0x478);
      *param_4 = *(undefined8 *)(param_2 + 0x480);
      return 0;
    }
  }
  return uVar1;
}


// ===== 003ddee0 kmemsysFlushGpuCache_IMPL.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmemsysFlushGpuCache_IMPL_part_0
              (undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar3 = *(uint *)(param_4 + 0xfb0);
  if ((uVar3 & 4) == 0) {
    iVar2 = 0;
    if ((uVar3 & 8) != 0) {
      if ((uVar3 & 3) == 3) goto LAB_003de0d0;
      uVar1 = *(undefined4 *)(CSWTCH_133 + (ulong)(uVar3 & 3) * 4);
      uVar6 = 1;
      if ((uVar3 & 0x10) == 0) goto LAB_003ddf90;
LAB_003ddf27:
      iVar2 = (**(code **)(param_2 + 0x188))(param_1,param_2,0,uVar1,uVar6);
      uVar3 = *(uint *)(param_4 + 0xfb0);
    }
LAB_003ddf52:
    if ((((uVar3 & 0x20) != 0) && (iVar4 = kbusSendSysmembar_IMPL(param_1,param_3), iVar4 != 0)) &&
       (nvCheckOkFailedNoLog
                  (4,iVar4,"kbusSendSysmembar(pGpu, pKernelBus)",
                   "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x619), iVar2 == 0)) {
      iVar2 = iVar4;
    }
  }
  else {
    uVar5 = uVar3 & 3;
    if ((uVar3 & 8) == 0) {
      if (uVar5 != 3) {
        uVar1 = *(undefined4 *)(CSWTCH_133 + (ulong)uVar5 * 4);
        uVar6 = 2;
LAB_003ddf8c:
        if ((uVar3 & 0x10) != 0) goto LAB_003ddf27;
LAB_003ddf90:
        if (*(int *)(param_4 + 4000) - 1U < 500) {
          iVar2 = 0xffff;
          if (*(long *)(param_4 + 0xfa8) == 0) {
            nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x603,
                         "kmemsysFlushGpuCache_IMPL",4,"NVRM: Invalid memBlock size (0x%llx)\n",0);
            iVar2 = 0x1f;
            uVar3 = *(uint *)(param_4 + 0xfb0);
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x5fb,
                       "kmemsysFlushGpuCache_IMPL",4,"NVRM: Invalid array size (0x%x)\n");
          iVar2 = 0x1f;
          uVar3 = *(uint *)(param_4 + 0xfb0);
        }
        goto LAB_003ddf52;
      }
    }
    else if (uVar5 != 3) {
      uVar1 = *(undefined4 *)(CSWTCH_133 + (ulong)uVar5 * 4);
      uVar6 = 3;
      goto LAB_003ddf8c;
    }
LAB_003de0d0:
    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x5dc,"kmemsysFlushGpuCache_IMPL",4,
                 "NVRM: Invalid aperture.\n");
    iVar2 = 0x1f;
  }
  return iVar2;
}


// ===== 003de110 _kmemsysSetZbcReferenced.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _kmemsysSetZbcReferenced_isra_0(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  ulong uVar3;
  int local_1c;
  
  lVar2 = resservGetTlsCallContext();
  uVar3 = vgpuGetCallingContextGfid(param_1,&local_1c);
  if ((int)uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x579);
    return uVar3 & 0xffffffff;
  }
  if ((local_1c == 0) && (*(uint *)(lVar2 + 0x28) < 2)) {
    nvCheckFailedNoLog(4,
                       "IS_GFID_VF(gfid) || pCallContext->secInfo.privLevel >= RS_PRIV_LEVEL_KERNEL"
                       ,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x57b);
    uVar3 = 0x1b;
  }
  else if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) {
    puVar1 = *(undefined4 **)(lVar2 + 0x48);
    lVar2 = gpuGetRpc(param_1);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x581);
      uVar3 = 0x1a;
    }
    else {
      if ((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x90a) != '\0')) {
        uVar3 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,*puVar1,puVar1[1]);
        return uVar3;
      }
      uVar3 = rpcDmaControl_wrapper
                        (param_1,lVar2,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                         puVar1[6]);
    }
  }
  return uVar3;
}


// ===== 003de270 kmemsysGetFbInfos_VF =====

undefined8 kmemsysGetFbInfos_VF(void)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  long in_R9;
  ulong *in_stack_00000008;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x37);
    return 0x40;
  }
  uVar2 = *in_stack_00000008;
  if (uVar2 == 0) {
    return 0;
  }
  lVar3 = 0;
  do {
    if ((uVar2 & 1) != 0) {
      uVar4 = *(uint *)(in_R9 + 4 + lVar3 * 8);
      if (uVar4 == 0x1b) {
        uVar4 = *(uint *)(lVar1 + 0x25e94);
LAB_003de300:
        *(uint *)(in_R9 + 8 + lVar3 * 8) = uVar4;
        *in_stack_00000008 = *in_stack_00000008 & ~(1L << ((byte)lVar3 & 0x3f));
      }
      else {
        if (0x1b < uVar4) {
          if (uVar4 == 0x2b) {
            uVar4 = *(uint *)(lVar1 + 0x25e88);
          }
          else if (uVar4 < 0x2c) {
            if (uVar4 == 0x22) {
              uVar5 = *(ulong *)(lVar1 + 0x25e88);
              uVar6 = uVar5 >> 1 & 0x5555555555555555;
              goto LAB_003de38a;
            }
            if (uVar4 != 0x23) goto LAB_003de313;
            uVar4 = *(uint *)(lVar1 + 0x25e90);
          }
          else if (uVar4 == 0x37) {
            uVar4 = *(uint *)(lVar1 + 0x1fd44);
          }
          else {
            if (uVar4 != 0x38) goto LAB_003de313;
            uVar4 = *(uint *)(lVar1 + 0x25e8c);
          }
          goto LAB_003de300;
        }
        if (uVar4 == 0x14) {
          uVar4 = *(uint *)(lVar1 + 0x1fd40);
          goto LAB_003de300;
        }
        if (0x14 < uVar4) {
          if (uVar4 == 0x19) {
            uVar5 = (ulong)*(uint *)(lVar1 + 0x25e80);
            uVar6 = (ulong)(*(uint *)(lVar1 + 0x25e80) >> 1 & 0x55555555);
            goto LAB_003de38a;
          }
          if (uVar4 != 0x1a) goto LAB_003de313;
          uVar4 = *(uint *)(lVar1 + 0x25e80);
          goto LAB_003de300;
        }
        if (uVar4 == 4) {
          uVar5 = *(ulong *)(lVar1 + 0x1fd40);
          uVar6 = uVar5 >> 1 & 0x5555555555555555;
LAB_003de38a:
          uVar5 = (uVar5 - uVar6 & 0x3333333333333333) + (uVar5 - uVar6 >> 2 & 0x3333333333333333);
          uVar4 = (uint)(byte)(((uVar5 >> 4) + uVar5 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >>
                              0x38);
          goto LAB_003de300;
        }
        if (uVar4 == 0xb) {
          uVar4 = *(uint *)(lVar1 + 0x25e7c);
          goto LAB_003de300;
        }
      }
LAB_003de313:
      if (uVar2 >> 1 == 0) {
        return 0;
      }
    }
    uVar2 = uVar2 >> 1;
    lVar3 = lVar3 + 1;
  } while( true );
}


// ===== 003de480 subdeviceCtrlCmdFbGetInfoV2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int subdeviceCtrlCmdFbGetInfoV2_IMPL(long param_1,int *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  byte bVar7;
  bool bVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  ulong uVar14;
  ulong uVar15;
  uint *puVar16;
  char *pcVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  uint *puVar21;
  ulong uVar22;
  undefined8 uVar23;
  long lVar24;
  uint uVar25;
  bool bVar26;
  long local_a8;
  uint local_98;
  uint local_94;
  long local_90;
  ulong local_88;
  ulong local_80;
  ulong local_78;
  ulong local_70;
  ulong local_68;
  ulong local_60;
  ulong local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar24 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  lVar4 = *plVar2;
  uVar1 = (undefined4)plVar2[2];
  cVar9 = rmapiLockIsOwner();
  if ((cVar9 == '\0') ||
     (cVar9 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar24 + 0x7a4)), cVar9 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x405);
    return 0x2f;
  }
  iVar13 = *param_2;
  if (0x7f < iVar13 - 1U) {
    return 0x1f;
  }
  lVar19 = *(long *)(lVar24 + 0x1b70);
  lVar5 = *(long *)(lVar24 + 0x1b78);
  lVar6 = *(long *)(lVar24 + 0x1bc0);
  local_90 = 0;
  local_a8 = *(long *)(lVar5 + 0x478);
  local_98 = 0;
  cVar9 = *(char *)(lVar5 + 0x434);
  if (lVar6 == 0) {
    cVar10 = '\0';
    bVar26 = false;
    bVar8 = false;
  }
  else {
    cVar10 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar24);
    if (cVar10 == '\0') {
      bVar8 = false;
      cVar10 = '\0';
      iVar13 = *param_2;
      bVar26 = false;
    }
    else {
      local_60 = 0;
      lVar18 = __nvoc_dynamicCast(lVar4,__nvoc_class_def_RmClient);
      if (lVar18 == 0) {
        nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0xad);
        return 0x23;
      }
      cVar10 = rmclientIsCapable_IMPL(lVar18,3);
      bVar26 = cVar10 != '\0';
      cVar10 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar24,lVar6,uVar3);
      bVar8 = true;
      iVar13 = *param_2;
    }
  }
  local_60 = 0xffffffffffffffff >> (-(char)iVar13 & 0x3fU);
  if (lVar19 != 0) {
    iVar13 = (**(code **)(lVar19 + 0x280))(lVar24,lVar19,lVar4,uVar3,uVar1,param_2,&local_60);
    if (iVar13 != 0) {
      if (local_60 == 0) goto LAB_003dedc0;
      goto LAB_003de673;
    }
    uVar14 = local_60 - (local_60 >> 1 & 0x5555555555555555);
    uVar14 = (uVar14 & 0x3333333333333333) + (uVar14 >> 2 & 0x3333333333333333);
    if (((uVar14 >> 4) + uVar14 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38 == 0) {
      return 0;
    }
    if (local_60 != 0) goto LAB_003de673;
    if ((*(char *)(lVar24 + 0x908) == '\0') && (iVar13 = 0, *(char *)(lVar24 + 0x909) == '\0'))
    goto LAB_003df769;
LAB_003dec99:
    puVar16 = (uint *)portMemAllocNonPaged(0x404);
    if (puVar16 == (uint *)0x0) {
      return 0x51;
    }
    portMemSet(puVar16,0,0x404);
    if (local_60 == 0) {
      uVar25 = 0;
    }
    else {
      puVar21 = (uint *)(param_2 + 1);
      uVar15 = 0;
      uVar14 = local_60;
      while( true ) {
        for (; (uVar14 & 1) == 0; uVar14 = uVar14 >> 1) {
          puVar21 = puVar21 + 2;
        }
        uVar25 = (int)uVar15 + 1;
        puVar16[uVar15 * 2 + 1] = *puVar21;
        if (uVar14 >> 1 == 0) break;
        puVar21 = puVar21 + 2;
        uVar14 = uVar14 >> 1;
        uVar15 = (ulong)uVar25;
      }
    }
    *puVar16 = uVar25;
    lVar19 = gpuGetRpc(lVar24);
    if (lVar19 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x3d2);
      iVar13 = 0x1a;
    }
    else if ((*(char *)(lVar24 + 0x909) == '\0') && (*(char *)(lVar24 + 0x90a) == '\0')) {
      iVar13 = rpcDmaControl_wrapper
                         (lVar24,lVar19,*(undefined4 *)(lVar4 + 0x48),uVar1,0x20801303,puVar16,0x404
                         );
    }
    else {
      iVar13 = (**(code **)(lVar24 + 0x3b90))
                         (lVar24 + 0x3b58,*(undefined4 *)(lVar4 + 0x48),uVar1,0x20801303,puVar16,
                          0x404);
    }
    if (local_60 != 0) {
      lVar24 = 0;
      uVar14 = 0;
      uVar15 = local_60;
      while( true ) {
        for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
          lVar24 = lVar24 + 1;
        }
        if (param_2[lVar24 * 2 + 1] != puVar16[uVar14 * 2 + 1]) {
          nvAssertFailedNoLog("pFbInfos[i].index == pRpcParams->fbInfoList[physIdx].index",
                              "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x3dd);
        }
        param_2[lVar24 * 2 + 2] = puVar16[uVar14 * 2 + 2];
        local_60 = local_60 & ~(1L << ((byte)lVar24 & 0x3f));
        if (uVar15 >> 1 == 0) break;
        lVar24 = lVar24 + 1;
        uVar14 = (ulong)((int)uVar14 + 1);
        uVar15 = uVar15 >> 1;
      }
    }
    portMemFree(puVar16);
    uVar14 = local_60 - (local_60 >> 1 & 0x5555555555555555);
    uVar14 = (uVar14 >> 2 & 0x3333333333333333) + (uVar14 & 0x3333333333333333);
    uVar14 = ((uVar14 >> 4) + uVar14 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
LAB_003deabe:
    if (uVar14 == 0) {
      return iVar13;
    }
LAB_003df769:
    nvCheckFailedNoLog(1,"nvPopCount64(fbInfoListIndicesUnset) == 0",
                       "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x3ee);
    return iVar13;
  }
  iVar13 = 0;
LAB_003de673:
  puVar16 = (uint *)(param_2 + 1);
  uVar14 = local_60;
LAB_003de6ed:
  if ((uVar14 & 1) == 0) goto LAB_003de6e9;
  if (*puVar16 < 0x37) {
    uVar15 = 1L << ((byte)*puVar16 & 0x3f);
    if ((uVar15 & 0x47f6d00181c049) == 0) {
      if ((uVar15 & 0x180) == 0) goto LAB_003de798;
      if (((bool)(cVar10 == '\0' & bVar8)) && (cVar10 == '\0' && !bVar26)) {
        iVar13 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar24,lVar6,uVar3,&local_48);
        if ((iVar13 == 0) || (cVar11 = kmigmgrIsMIGReferenceValid_IMPL(&local_48), cVar11 != '\0'))
        goto LAB_003de7a1;
        iVar13 = 0;
      }
    }
  }
  else {
LAB_003de798:
    if ((bool)((cVar10 == '\0' && !bVar26) & bVar8)) {
LAB_003de7a1:
      iVar12 = kmigmgrGetMemoryPartitionHeapFromDevice_IMPL(lVar24,lVar6,uVar3,&local_90);
      if (iVar12 != 0) {
        nvCheckFailedNoLog(1,
                           "(kmigmgrGetMemoryPartitionHeapFromDevice(pGpu, pKernelMIGManager, pDevice, &pMemoryPartitionHeap) == NV_OK)"
                           ,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x104);
        return 0x1b;
      }
      lVar18 = local_90;
      if (local_90 == 0) {
        lVar18 = local_a8;
      }
      local_a8 = lVar18;
      if (uVar14 >> 1 != 0) goto LAB_003de6e9;
LAB_003de820:
      uVar14 = uVar14 >> 1;
      uVar15 = local_60;
      if (local_60 == 0) {
        if (iVar13 != 0) {
LAB_003dedc0:
          nvCheckOkFailedNoLog(4,iVar13,"status","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x3bc)
          ;
          return iVar13;
        }
      }
      else {
joined_r0x003de834:
        for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
          uVar14 = uVar14 + 1;
        }
        uVar25 = param_2[uVar14 * 2 + 1];
        if (uVar25 == 0x1f) {
          local_48 = 0;
          local_40 = 0;
          iVar13 = (**(code **)(lVar5 + 0x218))(lVar24,lVar5,uVar3,&local_48);
          local_98 = 0;
          if (iVar13 == 0) {
            local_98 = local_40._4_4_;
          }
          goto LAB_003de8a0;
        }
        if (uVar25 < 0x20) {
          if (uVar25 == 0x10) {
            local_88 = (**(code **)(lVar5 + 0x220))(lVar24);
            local_98 = (uint)(local_88 >> 10);
LAB_003de8a0:
            if (iVar13 != 0) goto LAB_003dedc0;
          }
          else {
            if (uVar25 < 0x11) {
              if (uVar25 == 8) {
                if (*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) == '\0') {
                  if (local_90 != 0) {
                    if (cVar9 == '\0') {
                      heapGetSize_IMPL(local_a8);
                      uVar23 = 0x168;
joined_r0x003dfd10:
                      uVar20 = local_48;
                      if (local_48 >> 0x2a != 0) goto LAB_003dfc97;
                    }
                    else {
                      pmaGetTotalMemory(*(undefined8 *)(local_a8 + 0x128),&local_88);
                      uVar23 = 0x160;
joined_r0x003df131:
                      uVar20 = local_88;
                      if (local_88 >> 0x2a != 0) {
LAB_003dee83:
                        nvAssertFailedNoLog("NvU64_HI32(bytesTotal >> 10) == 0",
                                            "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",uVar23);
                        uVar20 = local_88;
                      }
                    }
                    goto LAB_003def2c;
                  }
                  uVar20 = *(ulong *)(lVar5 + 0x830);
                  uVar22 = uVar20 << 10;
                  if ((uVar20 & 0x3fffffffffffff) >> 0x16 != 0) {
                    uVar23 = 0x170;
LAB_003dfdd2:
                    nvAssertFailedNoLog("0 == NvU64_HI32(pMemoryManager->Ram.fbTotalMemSizeMb << 10)"
                                        ,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",uVar23);
                    uVar20 = *(ulong *)(lVar5 + 0x830);
                    uVar22 = uVar20 << 10;
                  }
LAB_003dfd7d:
                  iVar12 = (int)*(long *)(lVar5 + 0x848);
                  if (uVar22 < (ulong)(*(long *)(lVar5 + 0x848) << 10)) {
                    iVar12 = (int)uVar20;
                  }
                  local_98 = iVar12 * 0x400 - *(int *)(lVar19 + 0x470);
                }
                else {
                  local_98 = 0;
                  nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x155,
                               "_kmemsysGetFbInfos",1);
                }
              }
              else if (uVar25 < 9) {
                if (uVar25 == 5) {
                  local_48 = 0;
                  local_40 = 0;
                  iVar13 = (**(code **)(lVar5 + 0x218))(lVar24,lVar5,uVar3,&local_48);
                  local_98 = 0;
                  if (iVar13 == 0) {
                    local_98 = (uint)local_48;
                  }
                }
                else if (uVar25 < 6) {
                  if ((uVar25 != 0) && (uVar25 != 3)) goto LAB_003df07b;
LAB_003de890:
                  local_98 = 0;
                }
                else if (uVar25 == 6) {
                  local_48 = 0;
                  local_40 = 0;
                  iVar13 = (**(code **)(lVar5 + 0x218))(lVar24,lVar5,uVar3,&local_48);
                  local_98 = 0;
                  if (iVar13 == 0) {
                    local_98 = (uint)local_40;
                  }
                }
                else {
                  if (*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) == '\0') {
                    if (local_90 != 0) {
                      if (cVar9 == '\0') {
                        heapGetSize_IMPL(local_a8);
                        uVar23 = 399;
                        goto joined_r0x003dfd10;
                      }
                      pmaGetTotalMemory(*(undefined8 *)(local_a8 + 0x128),&local_88);
                      uVar23 = 0x187;
                      goto joined_r0x003df131;
                    }
                    uVar20 = *(ulong *)(lVar5 + 0x830);
                    uVar22 = uVar20 << 10;
                    if ((uVar20 & 0x3fffffffffffff) >> 0x16 != 0) {
                      uVar23 = 0x195;
                      goto LAB_003dfdd2;
                    }
                    goto LAB_003dfd7d;
                  }
                  local_98 = 0;
                  nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x17c,
                               "_kmemsysGetFbInfos",1);
                }
              }
              else if (uVar25 == 0xe) {
                local_98 = 1;
              }
              else {
                if (uVar25 == 0xf) goto LAB_003de890;
                if (uVar25 == 9) {
                  if (cVar9 == '\0') {
                    if (*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) != '\0') {
                      local_98 = 0;
                      nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x1ce,
                                   "_kmemsysGetFbInfos",1);
                      goto LAB_003de8a0;
                    }
                    heapGetUsableSize_IMPL(local_a8,&local_48);
                    uVar20 = local_48;
                    if (local_48 >> 0x2a != 0) {
                      nvAssertFailedNoLog("NvU64_HI32(size >> 10) == 0",
                                          "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x1d4);
                      uVar20 = local_48;
                    }
                  }
                  else {
                    pmaGetTotalMemory(*(undefined8 *)(local_a8 + 0x128));
                    uVar20 = local_88;
                    if (local_88 >> 0x2a != 0) {
                      nvAssertFailedNoLog("NvU64_HI32(bytesTotal >> 10) == 0",
                                          "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x1c4);
                      uVar20 = local_88;
                    }
                  }
                  local_98 = (uint)(uVar20 >> 10);
                }
                else {
                  if (uVar25 != 10) goto LAB_003df07b;
                  if (cVar9 == '\0') {
                    heapGetSize_IMPL(local_a8);
                    uVar20 = local_48;
                    if (local_48 >> 0x2a != 0) {
                      nvAssertFailedNoLog("NvU64_HI32(size >> 10) == 0",
                                          "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x288);
                      uVar20 = local_48;
                    }
                  }
                  else {
                    pmaGetTotalMemory(*(undefined8 *)(local_a8 + 0x128));
                    uVar20 = local_88;
                    if (local_88 >> 0x2a != 0) {
                      nvAssertFailedNoLog("NvU64_HI32(bytesTotal >> 10) == 0",
                                          "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x27b);
                      uVar20 = local_88;
                    }
                  }
                  iVar12 = memmgrGetMappableRamSizeMb_IMPL(lVar5);
                  uVar25 = (uint)(uVar20 >> 10);
                  local_98 = iVar12 << 10;
                  if (uVar25 < (uint)(iVar12 << 10)) {
                    local_98 = uVar25;
                  }
                }
                local_98 = local_98 - *(int *)(lVar19 + 0x470);
              }
              goto LAB_003de8a0;
            }
            if (uVar25 == 0x16) {
              if (*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) == '\0') {
                if (cVar10 == '\0' && !bVar26) {
                  if (cVar9 == '\0') {
                    heapGetFree_IMPL(local_a8);
                    uVar20 = local_48;
                    if (local_48 >> 0x2a != 0) {
                      uVar23 = 0x253;
LAB_003dfc97:
                      nvAssertFailedNoLog("NvU64_HI32(size >> 10) == 0",
                                          "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",uVar23);
                      uVar20 = local_48;
                    }
                  }
                  else {
                    pmaGetFreeMemory(*(undefined8 *)(local_a8 + 0x128));
                    uVar23 = 0x24b;
                    uVar20 = local_80;
                    if (local_80 >> 0x2a != 0) goto LAB_003df348;
                  }
                }
                else {
                  local_58 = 0;
                  local_80 = 0;
                  if (cVar9 == '\0') {
                    heapGetFree_IMPL(local_a8,&local_58);
                    local_80 = local_58;
                    cVar11 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(lVar24);
                    if (cVar11 != '\0') {
                      local_50 = 0;
                      local_48 = 0;
                      local_94 = 4;
                      memmgrGetFreeMemoryForAllMIGGPUInstances_IMPL(lVar24,lVar5,&local_50);
LAB_003dfec6:
                      local_80 = local_50 + local_80;
                    }
                  }
                  else {
                    pmaGetFreeMemory(*(undefined8 *)(local_a8 + 0x128),&local_58);
                    local_80 = local_58;
                    cVar11 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(lVar24);
                    if (cVar11 != '\0') {
                      local_50 = 0;
                      local_48 = 0;
                      local_94 = 4;
                      memmgrGetFreeMemoryForAllMIGGPUInstances_IMPL(lVar24,lVar5,&local_50);
                      iVar12 = pmaQueryConfigs(*(undefined8 *)(local_a8 + 0x128));
                      if ((iVar12 != 0) || ((local_94 & 4) == 0)) goto LAB_003dfec6;
                      memmgrGetTotalMemoryForAllMIGGPUInstances_IMPL(lVar24,lVar5,&local_48);
                      pmaGetTotalMemory(*(undefined8 *)(local_a8 + 0x128));
                      local_80 = (local_50 + local_58) - local_48;
                    }
                  }
                  uVar20 = local_80;
                  if (local_80 >> 0x2a != 0) {
                    uVar23 = 0x244;
                    goto LAB_003df348;
                  }
                }
                goto LAB_003def2c;
              }
              local_98 = 0;
              nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x20f,"_kmemsysGetFbInfos",1
                          );
              goto LAB_003de8a0;
            }
            if (uVar25 < 0x17) {
              if (uVar25 == 0x13) {
                if (cVar9 == '\0') {
                  iVar13 = heapInfo_IMPL(local_a8,&local_80,&local_88,&local_78,&local_70,&local_68)
                  ;
                }
                else {
                  pmaGetLargestFree(*(undefined8 *)(local_a8 + 0x128),&local_68,&local_78,&local_70)
                  ;
                }
                local_98 = (uint)(local_70 >> 10);
              }
              else if (uVar25 < 0x14) {
                if (uVar25 == 0x11) goto LAB_003deef8;
                if (cVar9 == '\0') {
                  iVar13 = heapInfo_IMPL(local_a8,&local_80,&local_88,&local_78,&local_70,&local_68)
                  ;
                }
                else {
                  pmaGetLargestFree(*(undefined8 *)(local_a8 + 0x128),&local_68,&local_78,&local_70)
                  ;
                }
                local_98 = (uint)(local_68 >> 10);
              }
              else {
                if (uVar25 != 0x15) goto LAB_003df07b;
                if (cVar9 == '\0') {
                  iVar12 = (**(code **)(lVar5 + 0x1f0))(lVar24);
                  local_98 = iVar12 << 10;
                }
                else {
                  if (local_90 != 0) goto LAB_003de890;
                  local_48 = 0;
                  (**(code **)(lVar5 + 0x318))(lVar24,lVar5,&local_48);
                  local_98 = (uint)(local_48 + 0x3ff >> 10);
                }
              }
              goto LAB_003de8a0;
            }
            if (uVar25 == 0x1d) {
              local_48 = 0;
              local_40 = 0;
              iVar13 = (**(code **)(lVar5 + 0x218))(lVar24,lVar5,uVar3,&local_48);
              local_98 = 0;
              if (iVar13 == 0) {
                local_98 = local_48._4_4_;
              }
              goto LAB_003de8a0;
            }
            if (uVar25 != 0x1e) {
              if (uVar25 == 0x17) goto LAB_003de890;
              if (uVar25 == 0x18) {
                uVar20 = 0;
                if (*(char *)(lVar24 + 0x44d) != '\0') {
                  uVar20 = (ulong)(*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) == '\0');
                }
                goto LAB_003dec80;
              }
              goto LAB_003df07b;
            }
            if (local_90 != 0) {
LAB_003deef8:
              if (cVar9 == '\0') {
                iVar13 = heapInfo_IMPL(local_a8,&local_80,&local_88,&local_78,&local_70,&local_68);
                uVar20 = local_78;
              }
              else {
                pmaGetLargestFree(*(undefined8 *)(local_a8 + 0x128),&local_68,&local_78,&local_70);
                uVar20 = local_78;
              }
              goto LAB_003def2c;
            }
            uVar20 = *(ulong *)(lVar19 + 0x470);
            if (uVar20 == 0) {
              iVar13 = heapGetBase_IMPL(local_a8);
              local_98 = (uint)(local_78 >> 10);
              if (local_78 == (local_78 >> 10 & 0xffffffff) * 0x400) goto LAB_003de8a0;
              nvAssertFailedNoLog("((NvU64) data << 10ULL) == heapBase",
                                  "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x203);
LAB_003df98e:
              iVar13 = 0x25;
              goto LAB_003dedc0;
            }
            local_98 = (uint)uVar20;
            if (uVar20 >> 0x20 != 0) {
              nvAssertFailedNoLog("(NvU64) data == pKernelMemorySystem->fbOverrideStartKb",
                                  "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x1f7);
              goto LAB_003df98e;
            }
          }
          param_2[uVar14 * 2 + 2] = local_98;
          bVar7 = (byte)uVar14 & 0x3f;
          local_60 = local_60 & (-2L << bVar7 | 0xfffffffffffffffeU >> 0x40 - bVar7);
        }
        else {
          if (uVar25 == 0x2f) {
            uVar20 = (ulong)*(byte *)(*(long *)(&DAT_00001b90 + lVar24) + 0xad03);
LAB_003dec80:
            local_98 = (uint)uVar20;
            goto LAB_003de8a0;
          }
          if (uVar25 < 0x30) {
            if (uVar25 == 0x29) {
              uVar20 = (**(code **)(lVar5 + 0x230))(lVar24);
              if (uVar20 >> 0x20 != 0) {
                nvAssertFailedNoLog("NvU64_HI32(rsvdSize) == 0",
                                    "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x2f5);
              }
              goto LAB_003dec80;
            }
            if (uVar25 < 0x2a) {
              if (uVar25 == 0x26) {
                local_98 = *(uint *)(lVar24 + 0x930);
              }
              else if (uVar25 < 0x27) {
                if (uVar25 == 0x20) {
                  if (*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) == '\0') {
                    if (local_90 != 0) {
                      if (cVar9 == '\0') {
                        heapGetSize_IMPL(local_a8);
                        uVar23 = 0x1b3;
                        goto joined_r0x003dfd10;
                      }
                      pmaGetTotalMemory(*(undefined8 *)(local_a8 + 0x128),&local_88);
                      uVar23 = 0x1ab;
                      goto joined_r0x003df131;
                    }
                    uVar20 = *(ulong *)(lVar5 + 0x828);
                    if (uVar20 >> 0x2a != 0) {
                      nvAssertFailedNoLog("0 == NvU64_HI32(pMemoryManager->Ram.fbUsableMemSize >> 10)"
                                          ,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x1b9);
                      uVar20 = *(ulong *)(lVar5 + 0x828);
                    }
                    iVar12 = (int)(uVar20 >> 10);
                    if ((ulong)(*(long *)(lVar5 + 0x848) << 10) <= uVar20 >> 10) {
                      iVar12 = (int)*(long *)(lVar5 + 0x848) << 10;
                    }
                    local_98 = iVar12 - *(int *)(lVar19 + 0x470);
                  }
                  else {
                    local_98 = 0;
                    nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x1a0,
                                 "_kmemsysGetFbInfos",1);
                  }
                }
                else {
                  if (uVar25 != 0x24) goto LAB_003df07b;
                  local_98 = (uint)(*(char *)(lVar24 + 0x4921) != '\0');
                }
              }
              else if (uVar25 == 0x27) {
                local_98 = *(uint *)(local_a8 + 0xf8);
              }
              else {
                pcVar17 = (char *)kmemsysGetStaticConfig_IMPL(lVar24);
                local_98 = (uint)(*pcVar17 != '\0');
              }
            }
            else if (uVar25 == 0x2d) {
              lVar18 = kmemsysGetStaticConfig_IMPL(lVar24);
              local_98 = (uint)(*(char *)(lVar18 + 5) != '\0');
            }
            else if (uVar25 == 0x2e) {
              local_98 = (uint)(*(char *)(lVar5 + 0x443) != '\0');
            }
            else if (uVar25 == 0x2a) {
              local_98 = (uint)(*(char *)(lVar24 + 0x457) != '\0');
            }
            else {
              if (uVar25 != 0x2c) goto LAB_003df07b;
              cVar11 = (**(code **)(lVar24 + 0x350))(lVar24);
              local_98 = (uint)(cVar11 != '\0');
            }
            goto LAB_003de8a0;
          }
          if (uVar25 == 0x34) {
            cVar11 = gpuIsCCorApmFeatureEnabled_IMPL(lVar24);
            if (cVar11 == '\0') goto LAB_003de890;
            if (cVar9 != '\0') {
              pmaGetFreeProtectedMemory(*(undefined8 *)(local_a8 + 0x128));
              uVar20 = local_80;
              if (local_80 >> 0x2a == 0) goto LAB_003def2c;
              uVar23 = 0x34f;
LAB_003df348:
              nvAssertFailedNoLog("NvU64_HI32(bytesFree >> 10) == 0",
                                  "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",uVar23);
              uVar20 = local_80;
LAB_003def2c:
              local_98 = (uint)(uVar20 >> 10);
              goto LAB_003de8a0;
            }
            nvAssertFailedNoLog(&DAT_00d5ab5a,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x358);
LAB_003dfc31:
            local_98 = 0;
            iVar13 = 0x1f;
            goto LAB_003dedc0;
          }
          if (uVar25 < 0x35) {
            if (uVar25 == 0x32) {
              lVar18 = *(long *)(&DAT_00001b90 + lVar24);
              local_98 = 0;
              if (*(char *)(lVar18 + 0xad01) != '\0') {
                (**(code **)(lVar18 + 600))(lVar24,lVar18,0,0);
              }
            }
            else {
              if (uVar25 == 0x33) {
                cVar11 = gpuIsCCorApmFeatureEnabled_IMPL(lVar24);
                if (cVar11 != '\0') {
                  if (cVar9 != '\0') {
                    pmaGetTotalProtectedMemory(*(undefined8 *)(local_a8 + 0x128),&local_88);
                    uVar20 = local_88;
                    if (local_88 >> 0x2a != 0) {
                      uVar23 = 0x334;
                      goto LAB_003dee83;
                    }
                    goto LAB_003def2c;
                  }
                  nvAssertFailedNoLog(&DAT_00d5ab5a,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",
                                      0x33d);
                  goto LAB_003dfc31;
                }
                goto LAB_003de890;
              }
              if (uVar25 == 0x30) {
                lVar18 = *(long *)(&DAT_00001b90 + lVar24);
                local_98 = 0;
                if (*(char *)(lVar18 + 0xad01) != '\0') {
                  (**(code **)(lVar18 + 600))(lVar24,lVar18,&local_98,0);
                }
              }
              else {
                lVar18 = *(long *)(&DAT_00001b90 + lVar24);
                local_98 = 0;
                if (*(char *)(lVar18 + 0xad01) != '\0') {
                  (**(code **)(lVar18 + 600))(lVar24,lVar18,0,&local_98);
                }
              }
            }
            goto LAB_003de8a0;
          }
          if (uVar25 == 0x3a) {
            if (*(long *)(lVar24 + 0x1b78) == 0) goto LAB_003de890;
            local_98 = (uint)(*(char *)(*(long *)(lVar24 + 0x1b78) + 0x447) != '\0');
            goto LAB_003de8a0;
          }
          if (uVar25 < 0x3b) {
            if (uVar25 == 0x36) {
              local_98 = (uint)(*(char *)(*(long *)(lVar24 + 0x4d8) + 0x80) != '\0');
            }
            else {
              if (uVar25 != 0x39) goto LAB_003df07b;
              if (*(long *)(lVar24 + 0x1cd8) == 0) goto LAB_003de890;
              local_98 = *(uint *)(*(long *)(lVar24 + 0x1cd8) + 0x280);
            }
            goto LAB_003de8a0;
          }
          if (uVar25 == 0x3b) {
            if (bVar8) {
              iVar12 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar24,lVar6,uVar3,&local_48);
              if ((iVar12 == 0) &&
                 (pcVar17 = (char *)((ulong)*(uint *)(local_48 + 0x968) * 0x20 +
                                    *(long *)(lVar19 + 0x2b8)), *pcVar17 != '\0')) {
                uVar20 = (ulong)*(uint *)(pcVar17 + 0x18);
              }
              else {
                uVar20 = 0xffffffff;
              }
            }
            else {
              uVar20 = (ulong)*(uint *)(lVar24 + 0x7bc);
            }
            goto LAB_003dec80;
          }
LAB_003df07b:
          if (iVar13 != 0) goto LAB_003dedc0;
        }
        if (uVar15 >> 1 != 0) {
          uVar14 = uVar14 + 1;
          iVar13 = 0;
          uVar15 = uVar15 >> 1;
          goto joined_r0x003de834;
        }
      }
      iVar13 = 0;
      uVar14 = local_60 - (local_60 >> 1 & 0x5555555555555555);
      uVar14 = (uVar14 >> 2 & 0x3333333333333333) + (uVar14 & 0x3333333333333333);
      uVar14 = ((uVar14 >> 4) + uVar14 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
      if ((*(char *)(lVar24 + 0x908) != '\0') || (*(char *)(lVar24 + 0x909) != '\0')) {
        if (uVar14 == 0) {
          return 0;
        }
        goto LAB_003dec99;
      }
      goto LAB_003deabe;
    }
  }
  if (uVar14 >> 1 == 0) goto LAB_003de820;
LAB_003de6e9:
  uVar14 = uVar14 >> 1;
  puVar16 = puVar16 + 2;
  goto LAB_003de6ed;
}


// ===== 003e0100 subdeviceCtrlCmdFbGetCliManagedOfflinedPages_IMPL =====

undefined8 subdeviceCtrlCmdFbGetCliManagedOfflinedPages_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  ulong *puVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  uint local_234;
  undefined4 local_230 [2];
  ulong local_228 [64];
  
  local_234 = 0;
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b78);
  lVar2 = *(long *)(lVar1 + 0x478);
  lVar3 = *(long *)(lVar2 + 0xe8);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 != '\0') {
    cVar4 = rmGpuLockIsOwner();
    if (cVar4 != '\0') {
      if (*(char *)(lVar1 + 0x434) == '\0') {
        uVar8 = 0;
        if (*(int *)(lVar2 + 0xf0) != 0) {
          puVar5 = (ulong *)(lVar3 + 8);
          uVar8 = 0;
          uVar7 = 0;
          do {
            if ((char)puVar5[2] == '\0') {
              uVar6 = (ulong)uVar8;
              uVar8 = uVar8 + 1;
              *(int *)(param_2 + uVar6 * 4) = (int)(*puVar5 >> 0xc);
            }
            uVar7 = uVar7 + 1;
            puVar5 = puVar5 + 4;
          } while (uVar7 < *(uint *)(lVar2 + 0xf0));
        }
        *(uint *)(param_2 + 0x104) = uVar8;
        *(undefined4 *)(param_2 + 0x100) = 0x1000;
      }
      else {
        pmaGetClientBlacklistedPages(*(undefined8 *)(lVar2 + 0x128),local_228,local_230,&local_234);
        if (0x40 < local_234) {
          nvAssertFailedNoLog("numChunks <= NV2080_CTRL_FB_OFFLINED_PAGES_MAX_PAGES",
                              "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x433);
        }
        if (local_234 != 0) {
          uVar6 = 0;
          do {
            *(int *)(param_2 + uVar6 * 4) = (int)(local_228[uVar6] >> 0xc);
            uVar6 = uVar6 + 1;
          } while (uVar6 != local_234);
        }
        *(uint *)(param_2 + 0x104) = local_234;
        *(undefined4 *)(param_2 + 0x100) = local_230[0];
      }
      return 0;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x42b);
  return 0x2f;
}


// ===== 003e0290 subdeviceCtrlCmdFbUpdateNumaStatus_IMPL =====

undefined8 subdeviceCtrlCmdFbUpdateNumaStatus_IMPL(long param_1,char *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b70);
  uVar4 = *(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x1b78) + 0x478) + 0x128);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*param_2 == '\0') {
        pmaNumaOfflined(uVar4);
        return 0;
      }
      uVar4 = pmaNumaOnlined(uVar4,*(undefined4 *)(lVar1 + 0x7bc),*(undefined8 *)(lVar2 + 0x478),
                             *(undefined8 *)(lVar2 + 0x4b0));
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x46e);
  return 0x2f;
}


// ===== 003e0360 subdeviceCtrlCmdFbGetNumaInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 subdeviceCtrlCmdFbGetNumaInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char cVar7;
  ushort uVar8;
  int iVar9;
  undefined4 uVar10;
  ulong *puVar11;
  ulong uVar12;
  long lVar13;
  char *pcVar14;
  ulong *puVar15;
  uint uVar16;
  uint uVar17;
  ulong uVar18;
  uint local_48;
  undefined4 uStack_44;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b70);
  lVar3 = *(long *)(lVar1 + 0x1b78);
  cVar7 = rmapiLockIsOwner();
  if ((cVar7 == '\0') || (cVar7 = rmGpuLockIsOwner(), cVar7 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x49c);
    return 0x2f;
  }
  uVar16 = param_2[6];
  if (0x40 < uVar16) {
    return 0x1f;
  }
  if ((*(char *)(lVar1 + 0x4915) == '\0') || (*(long *)(lVar1 + 0x1bc0) == 0)) {
LAB_003e03f0:
    *param_2 = *(undefined4 *)(lVar1 + 0x7bc);
    *(long *)(param_2 + 2) = *(long *)(lVar2 + 0x4a8) + *(long *)(lVar2 + 0x478);
    lVar13 = *(long *)(lVar2 + 0x4b0);
    *(long *)(param_2 + 4) = lVar13;
    uVar18 = *(ulong *)(lVar2 + 0x4a8);
  }
  else {
    cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    if (cVar7 == '\0') {
      uVar16 = param_2[6];
      goto LAB_003e03f0;
    }
    uVar5 = *(undefined8 *)(lVar1 + 0x1bc0);
    uVar6 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
    *param_2 = 0xffffffff;
    iVar9 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar5,uVar6,&local_48);
    if (iVar9 == 0) {
      lVar13 = (ulong)*(uint *)(CONCAT44(uStack_44,local_48) + 0x968) * 0x20;
      pcVar14 = (char *)(*(long *)(lVar2 + 0x2b8) + lVar13);
      if (*pcVar14 == '\0') goto LAB_003e06a0;
      *param_2 = *(undefined4 *)(pcVar14 + 0x18);
      *(long *)(param_2 + 2) =
           *(long *)(lVar2 + 0x478) + *(long *)(*(long *)(lVar2 + 0x2b8) + 8 + lVar13);
      *(undefined8 *)(param_2 + 4) = *(undefined8 *)(*(long *)(lVar2 + 0x2b8) + 0x10 + lVar13);
      lVar13 = lVar13 + *(long *)(lVar2 + 0x2b8);
      uVar18 = *(ulong *)(lVar13 + 8);
      lVar13 = *(long *)(lVar13 + 0x10);
    }
    else {
LAB_003e06a0:
      lVar13 = 0;
      uVar18 = 0;
    }
    uVar16 = param_2[6];
  }
  if (uVar16 == 0) {
    return 0;
  }
  if ((*(char *)(lVar1 + 0x457) == '\0') ||
     (cVar7 = (**(code **)(lVar1 + 0x2f0))(lVar1), cVar7 == '\0')) {
    param_2[6] = 0;
    return 0;
  }
  uVar8 = (**(code **)(lVar2 + 0x270))(lVar1,lVar2);
  local_48 = (uint)uVar8;
  puVar11 = (ulong *)portMemAllocNonPaged((ulong)uVar8 << 4);
  if (puVar11 == (ulong *)0x0) {
    return 0x51;
  }
  iVar9 = (**(code **)(lVar3 + 0x3a8))(lVar1,lVar3,puVar11,&local_48);
  if (iVar9 == 2) {
    nvAssertFailedNoLog("status != NV_ERR_BUFFER_TOO_SMALL",
                        "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x4d9);
  }
  else if (iVar9 == 0) {
    uVar10 = 0;
    uVar16 = 0;
    if (local_48 != 0) {
      uVar17 = 0;
      uVar16 = 0;
      puVar15 = puVar11;
      do {
        if ((uint)param_2[6] <= uVar16) {
          uVar10 = 2;
          break;
        }
        uVar4 = *puVar15;
        if ((uVar4 < uVar18) || (uVar18 + lVar13 <= uVar4)) {
          nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x4ee,
                       "subdeviceCtrlCmdFbGetNumaInfo_IMPL",1,
                       "NVRM: retired page address 0x%llx not in NUMA region\n");
        }
        else {
          uVar12 = (ulong)uVar16;
          uVar16 = uVar16 + 1;
          *(ulong *)(param_2 + uVar12 * 2 + 8) = uVar4 + *(long *)(lVar2 + 0x478);
        }
        uVar17 = uVar17 + 1;
        puVar15 = puVar15 + 2;
      } while (uVar17 < local_48);
    }
    goto LAB_003e05e5;
  }
  uVar10 = 0;
  uVar16 = 0;
LAB_003e05e5:
  param_2[6] = uVar16;
  portMemFree(puVar11);
  return uVar10;
}


// ===== 003e06e0 subdeviceCtrlCmdFbGetStaticBar1Info_IMPL =====

int subdeviceCtrlCmdFbGetStaticBar1Info_IMPL(long param_1,char *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  uint local_3c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = *(long *)(&DAT_00001b90 + lVar1);
  lVar2 = *(long *)(g_pSys + 0x208);
  iVar4 = vgpuGetCallingContextGfid(lVar1,local_3c);
  if (iVar4 == 0) {
    cVar3 = rmapiLockIsOwner();
    if ((cVar3 != '\0') &&
       (cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar3 != '\0')) {
      lVar5 = (ulong)local_3c[0] * 0x100 + lVar5;
      cVar3 = *(char *)(lVar5 + 0x6e8);
      *param_2 = cVar3;
      param_2[1] = *(char *)(lVar2 + 0x69) == '\0';
      if (cVar3 == '\0') {
        param_2[8] = '\0';
        param_2[9] = '\0';
        param_2[10] = '\0';
        param_2[0xb] = '\0';
        param_2[0xc] = '\0';
        param_2[0xd] = '\0';
        param_2[0xe] = '\0';
        param_2[0xf] = '\0';
        param_2[0x10] = '\0';
        param_2[0x11] = '\0';
        param_2[0x12] = '\0';
        param_2[0x13] = '\0';
        param_2[0x14] = '\0';
        param_2[0x15] = '\0';
        param_2[0x16] = '\0';
        param_2[0x17] = '\0';
        return 0;
      }
      *(undefined8 *)(param_2 + 8) = *(undefined8 *)(lVar5 + 0x700);
      *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(lVar5 + 0x708);
      return 0;
    }
    iVar4 = 0x2f;
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x51c);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x51a);
  }
  return iVar4;
}


// ===== 003e07f0 subdeviceCtrlCmdFbGetUgpuMemoryInfo_IMPL =====

undefined8 subdeviceCtrlCmdFbGetUgpuMemoryInfo_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
    if (cVar3 != '\0') {
      lVar2 = *(long *)(lVar2 + 0x1b78);
      if (*(char *)(lVar2 + 0x434) != '\0') {
        lVar2 = *(long *)(lVar2 + 0x478);
        iVar5 = 0;
        pmaGetTotalMemory(*(undefined8 *)(lVar2 + 0x128),param_2);
        lVar4 = param_2 + 0x10;
        pmaGetFreeMemory(*(undefined8 *)(lVar2 + 0x128),param_2 + 8);
        while( true ) {
          pmaGetUgpuTotalMemory(*(undefined8 *)(lVar2 + 0x128),iVar5,lVar4);
          lVar1 = lVar4 + 0x10;
          lVar4 = lVar4 + 8;
          pmaGetUgpuFreeMemory(*(undefined8 *)(lVar2 + 0x128),iVar5,lVar1);
          if (iVar5 == 1) break;
          iVar5 = 1;
        }
        return 0;
      }
      return 0x56;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x548);
  return 0x2f;
}


// ===== 003e0907 deviceCtrlCmdFbSetZbcReferenced_IMPL.cold =====

void deviceCtrlCmdFbSetZbcReferenced_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003e0920 deviceCtrlCmdFbSetZbcReferenced_IMPL =====

ulong deviceCtrlCmdFbSetZbcReferenced_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  long local_10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  puVar1 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar3 = subdeviceGetByInstance_IMPL(*puVar1,*(undefined4 *)(puVar1 + 2),*param_2,&local_10);
  if (uVar3 == 0) {
    uVar4 = _kmemsysSetZbcReferenced_isra_0(*(undefined8 *)(*(long *)(local_10 + 0x158) + 0xe0));
    return uVar4;
  }
  nvAssertOkFailedNoLog
            (uVar3,
             "subdeviceGetByInstance(RES_GET_CLIENT(pDevice), RES_GET_HANDLE(pDevice), pParams->subdevInstance, &pSubdevice)"
             ,"src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x599);
  return (ulong)uVar3;
}


// ===== 003e09a0 subdeviceCtrlCmdFbSetZbcReferenced_IMPL =====

void subdeviceCtrlCmdFbSetZbcReferenced_IMPL(long param_1)

{
  _kmemsysSetZbcReferenced_isra_0(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 003e09c0 kmemsysFlushGpuCache_IMPL =====

undefined8
kmemsysFlushGpuCache_IMPL(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
    if (cVar1 != '\0') {
      uVar2 = kmemsysFlushGpuCache_IMPL_part_0(param_1,param_2,param_3,param_4);
      return uVar2;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x5bc);
  return 0x2f;
}


// ===== 003e0a40 subdeviceCtrlCmdFbFlushGpuCache_IMPL =====

undefined8 subdeviceCtrlCmdFbFlushGpuCache_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar4 = *(undefined8 *)(lVar1 + 0x1b70);
  uVar2 = *(undefined8 *)(&DAT_00001b90 + lVar1);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar3 != '\0') {
      uVar4 = kmemsysFlushGpuCache_IMPL_part_0(lVar1,uVar4,uVar2,param_2);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x5bc);
  return 0x2f;
}


// ===== 003e0ad0 subdeviceCtrlCmdFbGetGpuCacheInfo_IMPL =====

undefined4 subdeviceCtrlCmdFbGetGpuCacheInfo_IMPL(long param_1,undefined4 *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b70) + 0x29c);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      if (iVar1 == 0) {
        param_2[1] = 0;
        uVar3 = 0;
      }
      else if (iVar1 == 1) {
        param_2[1] = 1;
        uVar3 = 0;
      }
      else {
        uVar3 = 0x40;
        nvDbg_Printf("src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x662,
                     "subdeviceCtrlCmdFbGetGpuCacheInfo_IMPL",4,"NVRM: Invalid write mode : %d\n",
                     iVar1);
      }
      *param_2 = 0;
      *(undefined8 *)(param_2 + 2) = 0;
      return uVar3;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x656);
  return 0x2f;
}


// ===== 003e0bb0 subdeviceCtrlCmdMemSysGetStaticConfig_VF =====

undefined8 subdeviceCtrlCmdMemSysGetStaticConfig_VF(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,0x28,lVar1 + 0x25e50,0x28);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x684);
  return 0x40;
}


// ===== 003e0c30 subdeviceCtrlCmdFbGetDynamicOfflinedPages_VF =====

undefined8 subdeviceCtrlCmdFbGetDynamicOfflinedPages_VF(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x697);
    return 0x40;
  }
  if (*(uint *)(param_2 + 0x404) < 0x200) {
    lVar4 = (ulong)(*(uint *)(param_2 + 0x404) >> 6) * 0x410;
    lVar1 = lVar3 + lVar4;
    uVar2 = *(uint *)(lVar1 + 0x6c70);
    *(uint *)(param_2 + 0x400) = uVar2;
    if (uVar2 < 0x41) {
      portMemCopy(param_2,(ulong)uVar2 << 4,lVar3 + 0x6870 + lVar4,(ulong)uVar2 << 4);
      *(undefined1 *)(param_2 + 0x408) = *(undefined1 *)(lVar1 + 0x6c78);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 003e0d00 subdeviceCtrlCmdFbGetLTCInfoForFBP_VF =====

undefined4 subdeviceCtrlCmdFbGetLTCInfoForFBP_VF(long param_1,byte *param_2)

{
  byte bVar1;
  long lVar2;
  undefined4 uVar3;
  
  lVar2 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar2 != 0) {
    bVar1 = *param_2;
    uVar3 = 0x1f;
    if (bVar1 < 0x18) {
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(lVar2 + 8 + (ulong)bVar1 * 0x14);
      uVar3 = 0;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(lVar2 + 4 + (ulong)bVar1 * 0x14);
    }
    return uVar3;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mem_sys/kern_mem_sys_ctrl.c",0x6b7);
  return 0x40;
}


// ===== 003e0d80 subdeviceCtrlCmdFbGetOfflinedPages_VF =====

undefined8 subdeviceCtrlCmdFbGetOfflinedPages_VF(void)

{
  return 0x56;
}


// ===== 003e0d90 zbcapiCtrlCmdGetZbcClearTableSize_VF =====

undefined4 zbcapiCtrlCmdGetZbcClearTableSize_VF(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  
  lVar2 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (lVar2 != 0) {
    uVar1 = param_2[2];
    uVar3 = 0x3b;
    if (uVar1 < 4) {
      *param_2 = *(undefined4 *)(lVar2 + 0x25e98 + (ulong)uVar1 * 0xc);
      uVar3 = 0;
      param_2[1] = *(undefined4 *)(lVar2 + 0x25e9c + (ulong)uVar1 * 0xc);
    }
    return uVar3;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mem_sys/zbc_api.c",0x24);
  return 0x40;
}


// ===== 003e0e20 kmigmgrIsDevinitMIGBitSet_GA100 =====

uint kmigmgrIsDevinitMIGBitSet_GA100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1404,0);
  return uVar1 >> 0xf & 1;
}


// ===== 003e0e50 kmigmgrCreateGPUInstanceCheck_GA100 =====

int kmigmgrCreateGPUInstanceCheck_GA100(long param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  undefined1 auVar7 [16];
  long local_1a0;
  ulong local_198;
  undefined1 local_190 [8];
  int local_188 [86];
  
  uVar4 = gpuGetKernelFifoShared_IMPL();
  lVar1 = *(long *)(param_1 + 0x1b78);
  auVar7 = memmgrGetMIGPartitionableMemoryRange_IMPL(param_1,lVar1);
  iVar3 = gpuUpdateEngineTable_IMPL(param_1);
  if (iVar3 == 0) {
    lVar6 = 0;
    uVar5 = 0;
    if (*(int *)(param_1 + 0x1e18) != 0) {
LAB_003e0ef6:
      do {
        cVar2 = kmigmgrIsEnginePartitionable_IMPL
                          (param_1,param_2,*(undefined4 *)(*(long *)(param_1 + 0x1e20) + lVar6 * 4))
        ;
        if (cVar2 != '\0') {
          iVar3 = *(int *)(*(long *)(param_1 + 0x1e20) + lVar6 * 4);
          if (iVar3 - 9U < 0x14) {
            if (param_3 == '\0') goto LAB_003e0ee9;
          }
          else if (iVar3 - 2U < 7) {
            lVar6 = lVar6 + 1;
            if (*(uint *)(param_1 + 0x1e18) <= (uint)lVar6) break;
            goto LAB_003e0ef6;
          }
          local_188[uVar5] = iVar3;
          uVar5 = (ulong)((int)uVar5 + 1);
        }
LAB_003e0ee9:
        lVar6 = lVar6 + 1;
      } while ((uint)lVar6 < *(uint *)(param_1 + 0x1e18));
    }
    cVar2 = kfifoEngineListHasChannel_IMPL(param_1,uVar4,local_188,uVar5);
    if (cVar2 == '\0') {
      iVar3 = kbusIsGpuP2pAlive_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1));
      if (iVar3 == 0) {
        lVar6 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
        if (*(char *)(lVar1 + 0x434) == '\0') {
          iVar3 = heapInfo_IMPL(lVar6,local_190,local_190,local_190,&local_198,&local_1a0);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,"heapInfo(pHeap, &unused, &unused, &unused, &base, &largestFreeSize)",
                       "src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x87);
            return iVar3;
          }
        }
        else {
          pmaGetLargestFree(*(undefined8 *)(lVar6 + 0x128),&local_1a0,&local_198,local_190);
        }
        if ((auVar7._8_8_ <= local_1a0 + -1 + local_198) && (local_198 <= auVar7._0_8_)) {
          return 0;
        }
      }
      else {
        nvCheckFailedNoLog(4,"!kbusIsGpuP2pAlive(pGpu, GPU_GET_KERNEL_BUS(pGpu))",
                           "src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x7f);
      }
    }
    iVar3 = 99;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"gpuUpdateEngineTable(pGpu)",
               "src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x51);
  }
  return iVar3;
}


// ===== 003e10b0 kmigmgrIsGPUInstanceFlagValid_GA100 =====

bool kmigmgrIsGPUInstanceFlagValid_GA100(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  char cVar1;
  
  cVar1 = kmigmgrIsGPUInstanceFlagLegal_IMPL();
  if (cVar1 == '\0') {
    nvCheckFailedNoLog(4,"kmigmgrIsGPUInstanceFlagLegal(pGpu, pKernelMIGManager, gpuInstanceFlag)",
                       "src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0xb1);
    return false;
  }
  if (5 < ((uint)((param_3 & 0xffffffff) >> 2) & 7)) {
    return false;
  }
  return (param_3 & 0x300000e0) == 0;
}


// ===== 003e1120 kmigmgrIsGPUInstanceCombinationValid_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrIsGPUInstanceCombinationValid_GA100(undefined8 param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined7 uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar4;
  
  uVar3 = (**(code **)(param_2 + 0x1f8))();
  if ((char)uVar3 == '\0') {
    return uVar3;
  }
  uVar4 = 0;
  uVar1 = (param_3 & 0xffffffff) >> 2;
  uVar2 = (uint)uVar1;
  uVar7 = (uint)param_3 & 3;
  uVar6 = uVar2 & 7;
  if ((param_3 & 0x40000000) == 0) {
    if (*(char *)(param_2 + 0x270) == '\0') goto LAB_003e1198;
    uVar2 = uVar6 - 2 & 0xfffffffd;
    uVar4 = (ulong)uVar2;
    if (uVar2 == 0) {
      return 0;
    }
  }
  else {
    if (*(char *)(param_2 + 0x270) == '\0') {
      if (uVar6 != 5) {
        return 0;
      }
      goto LAB_003e1169;
    }
    if ((uVar2 & 5) != 1) {
      return 0;
    }
LAB_003e1198:
    if (uVar6 == 2) goto LAB_003e11d4;
  }
  uVar5 = (undefined7)(uVar4 >> 8);
  if (2 < uVar6) {
    if (uVar6 == 4) {
      return CONCAT71(uVar5,uVar7 == 2);
    }
    if (uVar6 != 5) {
      if (uVar6 == 3) {
        return CONCAT71(uVar5,uVar7 == 2);
      }
      nvAssertFailedNoLog(&DAT_00d5aed0,"src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x124);
      return 0;
    }
LAB_003e1169:
    return CONCAT71((int7)(uVar4 >> 8),uVar7 == 3);
  }
  if ((uVar1 & 7) == 0) {
    return CONCAT71(uVar5,(param_3 & 3) == 0);
  }
LAB_003e11d4:
  return CONCAT71((int7)(uVar4 >> 8),uVar7 == 1);
}


// ===== 003e1210 kmigmgrMemSizeFlagToSwizzIdRange_GA100 =====

undefined1  [16]
kmigmgrMemSizeFlagToSwizzIdRange_GA100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined1 auVar1 [16];
  
  auVar1._8_8_ = *(undefined8 *)(CSWTCH_39 + (ulong)(param_3 & 3) * 8);
  auVar1._0_8_ = *(undefined8 *)(CSWTCH_38 + (ulong)(param_3 & 3) * 8);
  return auVar1;
}


// ===== 003e1230 kmigmgrIsMemoryPartitioningRequested_GA100 =====

bool kmigmgrIsMemoryPartitioningRequested_GA100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return (param_3 & 3) != 0;
}


// ===== 003e1240 kmigmgrIsMemoryPartitioningNeeded_GA100 =====

bool kmigmgrIsMemoryPartitioningNeeded_GA100(undefined8 param_1,undefined8 param_2,int param_3)

{
  return param_3 != 0;
}


// ===== 003e1250 kmigmgrSwizzIdToSpan_GA100 =====

byte kmigmgrSwizzIdToSpan_GA100(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  int iVar4;
  
  if (*(char *)(*(long *)(param_1 + 0x1bc8) + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x194);
    return 1;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                        ,"src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x195);
    return 1;
  }
  if (*(char *)(param_2 + 0x270) == '\0') {
    uVar1 = *(uint *)(lVar2 + 0x1b4);
    iVar4 = (uVar1 & 0xff) - 1;
    if (param_3 == 7) {
      bVar3 = 0;
      goto LAB_003e13b4;
    }
    if (param_3 < 8) {
      bVar3 = (byte)uVar1;
      if (param_3 == 3) {
        bVar3 = 0;
        goto LAB_003e13b4;
      }
      goto LAB_003e12af;
    }
    if (param_3 == 0xb) {
      bVar3 = 4;
      goto LAB_003e13b4;
    }
    if (param_3 < 0xc) {
      if (param_3 == 9) {
        bVar3 = 2;
      }
      else if (param_3 == 10) {
        bVar3 = 3;
      }
      else {
        bVar3 = 1;
      }
      goto LAB_003e13b4;
    }
    if (param_3 == 0xd) {
      bVar3 = 6;
      goto LAB_003e13b4;
    }
    if (param_3 == 0xe) {
      bVar3 = 7;
      goto LAB_003e13b4;
    }
  }
  else {
    if (param_3 == 7) {
      return 1;
    }
    if (param_3 < 8) {
      if (param_3 == 3) {
        return 0;
      }
      iVar4 = 3;
      bVar3 = 4;
LAB_003e12af:
      if (param_3 < 4) {
        if (param_3 == 1) {
          bVar3 = 0;
        }
        else {
          if (param_3 != 2) {
            return 0;
          }
          bVar3 = bVar3 >> 1;
        }
      }
      else if (param_3 == 5) {
        bVar3 = bVar3 >> 1;
      }
      else if (param_3 == 6) {
        bVar3 = (bVar3 >> 2) * '\x03';
      }
      else {
        bVar3 = bVar3 >> 2;
      }
      goto LAB_003e13b4;
    }
    if (param_3 == 0xb) {
      return 1;
    }
    if (param_3 < 0xc) {
      return 1;
    }
    if (param_3 == 0xd) {
      return 1;
    }
    iVar4 = 3;
    if (param_3 == 0xe) {
      return 1;
    }
  }
  bVar3 = 5;
  if (param_3 != 0xc) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x1cc,
                 "kmigmgrSwizzIdToSpan_GA100",4,"NVRM: Unsupported swizzid 0x%x\n");
    bVar3 = 1;
  }
LAB_003e13b4:
  if ((uint)(iVar4 * 2) < param_3) {
    bVar3 = 1;
  }
  return bVar3;
}


// ===== 003e1520 kmigmgrSwizzIdToGrSpan_GA100 =====

byte kmigmgrSwizzIdToGrSpan_GA100(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  int iVar4;
  
  if (*(char *)(*(long *)(param_1 + 0x1bc8) + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x1ec);
    return 1;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                        ,"src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x1ed);
    return 1;
  }
  if (*(char *)(param_2 + 0x270) == '\0') {
    uVar1 = *(uint *)(lVar2 + 0x1ac);
    iVar4 = (uVar1 & 0xff) - 1;
    if (param_3 == 7) {
      bVar3 = 0;
      goto LAB_003e1684;
    }
    if (param_3 < 8) {
      bVar3 = (byte)uVar1;
      if (param_3 == 3) {
        bVar3 = 0;
        goto LAB_003e1684;
      }
      goto LAB_003e157f;
    }
    if (param_3 == 0xb) {
      bVar3 = 4;
      goto LAB_003e1684;
    }
    if (param_3 < 0xc) {
      if (param_3 == 9) {
        bVar3 = 2;
      }
      else if (param_3 == 10) {
        bVar3 = 3;
      }
      else {
        bVar3 = 1;
      }
      goto LAB_003e1684;
    }
    if (param_3 == 0xd) {
      bVar3 = 6;
      goto LAB_003e1684;
    }
    if (param_3 == 0xe) {
      bVar3 = 7;
      goto LAB_003e1684;
    }
  }
  else {
    if (param_3 == 7) {
      return 1;
    }
    if (param_3 < 8) {
      if (param_3 == 3) {
        return 0;
      }
      iVar4 = 3;
      bVar3 = 4;
LAB_003e157f:
      if (param_3 < 4) {
        if (param_3 == 1) {
          bVar3 = 0;
        }
        else {
          if (param_3 != 2) {
            return 0;
          }
          bVar3 = bVar3 >> 1;
        }
      }
      else if (param_3 == 5) {
        bVar3 = bVar3 >> 1;
      }
      else if (param_3 == 6) {
        bVar3 = (bVar3 >> 2) * '\x03';
      }
      else {
        bVar3 = bVar3 >> 2;
      }
      goto LAB_003e1684;
    }
    if (param_3 == 0xb) {
      return 1;
    }
    if (param_3 < 0xc) {
      return 1;
    }
    if (param_3 == 0xd) {
      return 1;
    }
    iVar4 = 3;
    if (param_3 == 0xe) {
      return 1;
    }
  }
  bVar3 = 5;
  if (param_3 != 0xc) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",0x224,
                 "kmigmgrSwizzIdToGrSpan_GA100",4,"NVRM: Unsupported swizzid 0x%x\n");
    bVar3 = 1;
  }
LAB_003e1684:
  if ((uint)(iVar4 * 2) < param_3) {
    bVar3 = 1;
  }
  return bVar3;
}


// ===== 003e17f0 kmigmgrDetectReducedConfig_GA100 =====

void kmigmgrDetectReducedConfig_GA100(undefined8 param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  uint *puVar3;
  
  lVar2 = kmigmgrGetStaticInfo_IMPL();
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/mig_mgr/arch/ampere/kmigmgr_ga100.c",
                        0x241);
    return;
  }
  puVar3 = *(uint **)(lVar2 + 0x20);
  if (*puVar3 != 0) {
    puVar1 = puVar3 + (ulong)*puVar3 * 6;
    do {
      if ((char)puVar3[1] == '\x05') {
        return;
      }
      puVar3 = puVar3 + 6;
    } while (puVar3 != puVar1);
  }
  *(undefined1 *)(param_2 + 0x270) = 1;
  return;
}


// ===== 003e1870 kmigmgrIsGPUInstanceFlagValid_GB100 =====

bool kmigmgrIsGPUInstanceFlagValid_GB100(undefined8 param_1,long param_2,ulong param_3)

{
  char cVar1;
  
  cVar1 = kmigmgrIsGPUInstanceFlagLegal_IMPL();
  if (cVar1 == '\0') {
    nvCheckFailedNoLog(4,"kmigmgrIsGPUInstanceFlagLegal(pGpu, pKernelMIGManager, gpuInstanceFlag)",
                       "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb100.c",0x35);
    return false;
  }
  if ((((uint)((param_3 & 0xffffffff) >> 2) & 7) < 6) && ((param_3 & 0x30000000) == 0)) {
    if ((param_3 >> 5 & 7) == 0) {
      return true;
    }
    if (((uint)(param_3 >> 5) & 7) == 1) {
      return *(char *)(param_2 + 0x5380) != '\0';
    }
  }
  return false;
}


// ===== 003e1900 kmigmgrIsGfxCapabilitesRequested_GB100 =====

bool kmigmgrIsGfxCapabilitesRequested_GB100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return (param_3 & 0xe0) != 0;
}


// ===== 003e1910 kmigmgrCreateGPUInstanceCheck_GB10B =====

int kmigmgrCreateGPUInstanceCheck_GB10B(long param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  undefined1 auVar8 [16];
  long local_1a0;
  ulong local_198;
  undefined1 local_190 [8];
  int local_188 [86];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  uVar4 = gpuGetKernelFifoShared_IMPL();
  auVar8 = memmgrGetMIGPartitionableMemoryRange_IMPL(param_1,lVar1);
  iVar3 = gpuUpdateEngineTable_IMPL(param_1);
  if (iVar3 == 0) {
    uVar6 = 0;
    if (*(int *)(param_1 + 0x1e18) != 0) {
      uVar6 = 0;
      lVar7 = 0;
      do {
        cVar2 = kmigmgrIsEnginePartitionable_IMPL
                          (param_1,param_2,*(undefined4 *)(*(long *)(param_1 + 0x1e20) + lVar7 * 4))
        ;
        if ((cVar2 != '\0') &&
           (iVar3 = *(int *)(*(long *)(param_1 + 0x1e20) + lVar7 * 4), 6 < iVar3 - 2U)) {
          uVar5 = (ulong)uVar6;
          uVar6 = uVar6 + 1;
          local_188[uVar5] = iVar3;
        }
        lVar7 = lVar7 + 1;
      } while ((uint)lVar7 < *(uint *)(param_1 + 0x1e18));
    }
    cVar2 = kfifoEngineListHasChannel_IMPL(param_1,uVar4,local_188,uVar6);
    if (cVar2 == '\0') {
      lVar7 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
      if (*(char *)(lVar1 + 0x434) == '\0') {
        iVar3 = heapInfo_IMPL(lVar7,local_190,local_190,local_190,&local_198,&local_1a0);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"heapInfo(pHeap, &unused, &unused, &unused, &base, &largestFreeSize)",
                     "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x5a);
          return iVar3;
        }
      }
      else {
        pmaGetLargestFree(*(undefined8 *)(lVar7 + 0x128),&local_1a0,&local_198,local_190);
      }
      if ((auVar8._8_8_ <= local_1a0 + -1 + local_198) && (local_198 <= auVar8._0_8_)) {
        return 0;
      }
    }
    iVar3 = 99;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"gpuUpdateEngineTable(pGpu)",
               "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x3c);
  }
  return iVar3;
}


// ===== 003e1b00 kmigmgrIsGPUInstanceCombinationValid_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmigmgrIsGPUInstanceCombinationValid_GB10B(undefined8 param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = (**(code **)(param_2 + 0x1f8))();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar1 = kmigmgrSmallestComputeProfileSize_IMPL(param_1,param_2);
  if (uVar1 == 8) {
    nvCheckFailedNoLog(4,"smallestComputeSizeFlag != KMIGMGR_COMPUTE_SIZE_INVALID",
                       "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x7f);
  }
  else {
    if ((param_3 & 0x40000000) == 0) {
      return 1;
    }
    if (((uint)(param_3 >> 2) & 7) == uVar1) {
      return (ulong)((param_3 & 0x1f) != 0);
    }
  }
  return 0;
}


// ===== 003e1bc0 kmigmgrIsGPUInstanceFlagValid_GB10B =====

bool kmigmgrIsGPUInstanceFlagValid_GB10B(undefined8 param_1,long param_2,ulong param_3)

{
  char cVar1;
  
  cVar1 = kmigmgrIsGPUInstanceFlagLegal_IMPL();
  if (cVar1 == '\0') {
    nvCheckFailedNoLog(4,"kmigmgrIsGPUInstanceFlagLegal(pGpu, pKernelMIGManager, gpuInstanceFlag)",
                       "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0xb1);
    return false;
  }
  if ((((uint)((param_3 & 0xffffffff) >> 2) & 7) < 3) && ((param_3 & 0x30000003) == 0)) {
    if ((param_3 >> 5 & 7) == 0) {
      return true;
    }
    if (((uint)(param_3 >> 5) & 7) == 1) {
      return *(char *)(param_2 + 0x5380) != '\0';
    }
  }
  return false;
}


// ===== 003e1c60 kmigmgrGetComputeProfileFromGpcCount_GB10B =====

undefined1  [16]
kmigmgrGetComputeProfileFromGpcCount_GB10B
          (long param_1,undefined8 param_2,uint param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  uint *puVar4;
  uint *puVar5;
  undefined8 extraout_RDX;
  undefined8 uVar6;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  uint uVar7;
  char cVar8;
  uint uVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  lVar2 = *(long *)(param_1 + 0x1bc8);
  lVar3 = kmigmgrGetStaticInfo_IMPL();
  if (param_4 == 0) {
    nvAssertFailedNoLog("pProfile != NULL","src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",
                        0xfb);
    auVar11._8_8_ = extraout_RDX_00;
    auVar11._0_8_ = 0x1f;
    return auVar11;
  }
  if (lVar3 == 0) {
    nvCheckFailedNoLog(4,"pStaticInfo != NULL",
                       "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0xfc);
    uVar6 = extraout_RDX_01;
  }
  else {
    puVar5 = *(uint **)(lVar3 + 0x20);
    if (puVar5 == (uint *)0x0) {
      nvCheckFailedNoLog(3,"pStaticInfo->pCIProfiles != NULL",
                         "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0xfd);
      uVar6 = extraout_RDX_02;
    }
    else {
      uVar1 = *puVar5;
      uVar9 = *(uint *)(*(long *)(lVar2 + 0x430) + 0x1b4);
      if (uVar1 != 0) {
        puVar4 = puVar5;
        uVar7 = uVar9;
        do {
          if ((char)puVar4[1] == '\0') {
            uVar7 = puVar4[3];
          }
          puVar4 = puVar4 + 6;
        } while (puVar5 + (ulong)uVar1 * 6 != puVar4);
        cVar8 = '\x02';
        if (param_3 != 1) {
          if (((uVar9 >> 1) + 1 == param_3) && (uVar7 == uVar9)) {
            cVar8 = '\x01';
          }
          else {
            cVar8 = (uVar7 != param_3) * '\b';
          }
        }
        puVar5 = puVar5 + 1;
        uVar9 = 0;
        do {
          if (cVar8 == (char)*puVar5) {
            nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x11b,
                         "kmigmgrGetComputeProfileFromGpcCount_GB10B",1,
                         "NVRM: Found matching Compute Profile:%d for gpcCount=%d\n",cVar8,param_3);
            portMemCopy(param_4,0x18,*(long *)(lVar3 + 0x20) + 4 + (ulong)uVar9 * 0x18,0x18);
            return ZEXT816(0x3e1c83) << 0x40;
          }
          uVar9 = uVar9 + 1;
          puVar5 = puVar5 + 6;
        } while (uVar9 != uVar1);
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x121,
                   "kmigmgrGetComputeProfileFromGpcCount_GB10B",1,
                   "NVRM: Found no Compute Profile for gpcCount=%d\n",param_3);
      uVar6 = extraout_RDX;
    }
  }
  auVar10._8_8_ = uVar6;
  auVar10._0_8_ = 0x57;
  return auVar10;
}


// ===== 003e1e80 kmigmgrSwizzIdToSpan_GB10B =====

undefined1  [16] kmigmgrSwizzIdToSpan_GB10B(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  if (*(char *)(*(long *)(param_1 + 0x1bc8) + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x134);
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                          ,"src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x135);
    }
    else {
      uVar1 = *(uint *)(lVar2 + 0x1b4);
      if (param_3 == 1) {
        return ZEXT416((uint)((int)(((uVar1 & 0xff) - 1) - ((int)((uVar1 & 0xff) - 1) >> 0x1f)) >> 1
                             )) << 0x40;
      }
      if (param_3 == 2) {
        auVar4._0_8_ = (long)(int)((uVar1 & 0xff) - 1);
        auVar4._8_8_ = auVar4._0_8_;
        return auVar4;
      }
      if (param_3 == 0) {
        auVar3._8_8_ = 0;
        auVar3._0_8_ = (long)(int)((uVar1 & 0xff) - 1);
        return auVar3 << 0x40;
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x145,
                   "kmigmgrSwizzIdToSpan_GB10B",4,"NVRM: Unsupported swizzid 0x%x\n",param_3);
    }
  }
  return ZEXT816(1);
}


// ===== 003e1f70 kmigmgrSwizzIdToGrSpan_GB10B =====

byte kmigmgrSwizzIdToGrSpan_GB10B(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  
  if (*(char *)(*(long *)(param_1 + 0x1bc8) + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x15c);
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
    if (lVar1 != 0) {
      if (param_3 != 1) {
        if (param_3 == 2) {
          return (byte)*(undefined4 *)(lVar1 + 0x1ac) >> 1;
        }
        if (param_3 != 0) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x16d,
                       "kmigmgrSwizzIdToGrSpan_GB10B",4,"NVRM: Unsupported swizzid 0x%x\n",param_3);
          return 1;
        }
      }
      return 0;
    }
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                        ,"src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x15d);
  }
  return 1;
}


// ===== 003e2060 kmigmgrPatchCICapacity_GB10B =====

undefined8
kmigmgrPatchCICapacity_GB10B
          (undefined8 param_1,undefined8 param_2,long param_3,long param_4,uint param_5)

{
  if (param_3 == 0) {
    nvAssertFailedNoLog("pProfile != NULL","src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",
                        0x182);
  }
  else {
    if (param_4 != 0) {
      if ((*(uint *)(param_3 + 4) < *(uint *)(param_4 + 0x110)) &&
         (nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",400,
                       "kmigmgrPatchCICapacity_GB10B",1,
                       "NVRM: Total Span count:0x%x more than GR Count:0x%x\n",
                       *(uint *)(param_4 + 0x110),*(uint *)(param_3 + 4)),
         param_5 < *(uint *)(param_4 + 0x110))) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x194,
                     "kmigmgrPatchCICapacity_GB10B",1,
                     "NVRM: Clear profile and available spans count\n");
        *(undefined4 *)(param_4 + 4) = 0;
        *(undefined4 *)(param_4 + 0x88) = 0;
      }
      return 0;
    }
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",
                        0x183);
  }
  return 0x40;
}


// ===== 003e2170 kmigmgrConfigurePMSettings_GB10B =====

ulong kmigmgrConfigurePMSettings_GB10B(long param_1,long param_2)

{
  char cVar1;
  ulong uVar2;
  
  cVar1 = rmapiLockIsWriteOwner();
  if (cVar1 == '\0') {
LAB_003e2210:
    nvAssertFailedNoLog("rmapiLockIsWriteOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x1af);
    return 0x2f;
  }
  cVar1 = rmGpuLockIsOwner();
  if (cVar1 == '\0') goto LAB_003e2210;
  if (*(char *)(param_2 + 0x5340) == '\0') {
    if (*(char *)(param_2 + 0x5381) != '\0') {
      *(undefined1 *)(param_2 + 0x5381) = 0;
      rmGpuLocksRelease(0,0);
      osUnrefGpuAccessNeeded(*(undefined8 *)(param_1 + 0x4e0));
      goto LAB_003e21cf;
    }
  }
  else if (*(char *)(param_2 + 0x5381) == '\0') {
    *(undefined1 *)(param_2 + 0x5381) = 1;
    rmGpuLocksRelease(0,0);
    osRefGpuAccessNeeded(*(undefined8 *)(param_1 + 0x4e0));
    goto LAB_003e21cf;
  }
  rmGpuLocksRelease(0,0);
LAB_003e21cf:
  uVar2 = rmGpuLocksAcquire(0,0);
  if ((int)uVar2 != 0) {
    nvAssertOkFailedNoLog
              (uVar2 & 0xffffffff,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_NONE)",
               "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb10b.c",0x1d5);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}


// ===== 003e2280 kmigmgrIsGPUInstanceFlagValid_GB202 =====

bool kmigmgrIsGPUInstanceFlagValid_GB202(undefined8 param_1,long param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = kmigmgrIsGPUInstanceFlagLegal_IMPL();
  if (cVar1 == '\0') {
    nvCheckFailedNoLog(4,"kmigmgrIsGPUInstanceFlagLegal(pGpu, pKernelMIGManager, gpuInstanceFlag)",
                       "src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb202.c",0x35);
    return false;
  }
  if (((((param_3 & 0x30000000) == 0x20000000) || ((param_3 & 0x20000000) == 0)) &&
      ((~param_3 & 3) != 0)) && ((param_3 & 0x10) == 0)) {
    uVar2 = param_3 >> 5 & 7;
    if (uVar2 == 0) {
      return true;
    }
    if (uVar2 - 1 < 4) {
      return *(char *)(param_2 + 0x5380) != '\0';
    }
  }
  return false;
}


// ===== 003e2330 kmigmgrGpuInstanceSupportVgpuTimeslice_GB202 =====

bool kmigmgrGpuInstanceSupportVgpuTimeslice_GB202(undefined8 param_1,uint param_2)

{
  return (param_2 & 0xe0) != 0;
}


// ===== 003e2340 kmigmgrIsGPUInstanceCombinationValid_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmigmgrIsGPUInstanceCombinationValid_GB202(long param_1,long param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  undefined7 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(param_2 + 0x1f8))();
  if ((char)uVar4 == '\0') {
    return uVar4;
  }
  uVar2 = (uint)param_3 & 3;
  uVar4 = 0;
  uVar7 = (uint)(param_3 >> 2) & 7;
  if ((param_3 & 0x40000000) == 0) {
    if (uVar7 != 1) {
      if ((param_3 & 0x18) == 0) {
        if ((param_3 & 0x30000003) != 0) {
          return 0;
        }
        goto LAB_003e23c3;
      }
      if (uVar7 != 4) {
        if (4 < uVar7) {
          nvAssertFailedNoLog(&DAT_00d5b570,"src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb202.c",
                              0xea);
          return 0;
        }
        if (uVar7 == 2) goto LAB_003e24e0;
      }
LAB_003e23b9:
      if (uVar2 != 2) {
        return 0;
      }
      goto LAB_003e23c3;
    }
  }
  else {
    uVar6 = 0;
    uVar8 = 0;
    do {
      cVar1 = (**(code **)(param_1 + 200))(param_1,uVar6 | 0xd334df00);
      uVar3 = uVar8 | 1 << (uVar6 & 0x1f);
      uVar4 = (ulong)uVar3;
      if (cVar1 != '\0') {
        uVar8 = uVar3;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != 8);
    if (uVar7 != 2) {
      if (uVar7 != 3) {
        return 0;
      }
      if ((param_3 & 0x30000000) != 0) {
        return 0;
      }
      goto LAB_003e23b9;
    }
    uVar8 = uVar8 - (uVar8 >> 1 & 0x55555555);
    uVar8 = (uVar8 & 0x33333333) + (uVar8 >> 2 & 0x33333333);
    if (((uVar8 >> 4) + uVar8 & 0xf0f0f0f) * 0x1010101 >> 0x18 != 2) {
      return 0;
    }
    if ((param_3 & 0x30000000) != 0) {
      return 0;
    }
  }
LAB_003e24e0:
  uVar4 = 0;
  if (uVar2 != 1) {
    return 0;
  }
LAB_003e23c3:
  uVar2 = (uint)param_3 >> 5 & 7;
  uVar5 = (undefined7)(uVar4 >> 8);
  if (uVar2 == 2) {
    uVar4 = CONCAT71(uVar5,uVar7 == 1);
  }
  else if (uVar2 < 3) {
    if (uVar2 == 0) {
      return 1;
    }
    uVar4 = (ulong)((param_3 >> 2 & 7) == 0);
  }
  else {
    if (uVar2 != 3) {
      if (uVar2 == 4) {
        return CONCAT71(uVar5,uVar7 == 3);
      }
      nvAssertFailedNoLog(&DAT_00d5b570,"src/kernel/gpu/mig_mgr/arch/blackwell/kmigmgr_gb202.c",
                          0x106);
      return 0;
    }
    uVar4 = CONCAT71(uVar5,uVar7 == 2);
  }
  return uVar4;
}


// ===== 003e2590 kmigmgrApplyDefaultCeMappings_GH100 =====

void kmigmgrApplyDefaultCeMappings_GH100(long param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  
  uVar1 = *(uint *)(param_1 + 0x8fc);
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      if ((((uVar4 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar4 * 8), lVar2 != 0)) &&
          (*(char *)(lVar2 + 0x2d4) != '\0')) &&
         (iVar3 = kceTopLevelPceLceMappingsUpdate_IMPL(param_1), iVar3 != 0)) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x32,
                     "kmigmgrApplyDefaultCeMappings_GH100",4,
                     "NVRM: Failed to update PCE-LCE mappings\n");
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != uVar1);
  }
  return;
}


// ===== 003e2640 kmigmgrClearMIGGpuInstanceCeMapping_GH100 =====

undefined8 kmigmgrClearMIGGpuInstanceCeMapping_GH100(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  ulong uVar9;
  uint uVar10;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  
  uVar10 = 0;
  bitVectorClrAll_IMPL(local_58,0x54);
  bitVectorSetRange_IMPL(local_58,0x54,9,0x1c);
  bitVectorAnd_IMPL(local_58,0x54,local_58,0x54,param_3 + 0x98,0x54);
  bitVectorCopy_IMPL(local_48,0x54,local_58,0x54);
  iVar4 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  while (cVar3 = bitVectorTestAllCleared_IMPL(local_48,0x54), cVar3 == '\0') {
    cVar3 = ceIsCeGrce(param_1,iVar4);
    if (cVar3 == '\0') {
      uVar10 = uVar10 | 1 << (iVar4 - 9U & 0x1f);
    }
    bitVectorClr_IMPL(local_48,0x54,iVar4);
    iVar4 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x56,
               "kmigmgrClearMIGGpuInstanceCeMapping_GH100",1,
               "NVRM: Unmapping LCEs 0x%x as part of GPU Instance clean up\n",uVar10);
  puVar5 = (undefined4 *)portMemAllocNonPaged(0x80);
  puVar6 = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pLocalPceLceMap != NULL",
                        "src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x59);
    uVar8 = 0x51;
  }
  else {
    do {
      *puVar6 = 0xf;
      puVar7 = puVar6 + 2;
      puVar6[1] = 0xf;
      puVar6 = puVar7;
    } while (puVar7 != puVar5 + 0x20);
    uVar1 = *(uint *)(param_1 + 0x8fc);
    if (uVar1 != 0) {
      uVar9 = 0;
      do {
        if ((((uVar9 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar9 * 8), lVar2 != 0)) &&
            (*(char *)(lVar2 + 0x2d4) != '\0')) &&
           (cVar3 = kceApplyMIGMappings_IMPL(param_1,lVar2,puVar5,uVar10), cVar3 == '\0')) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",100,
                       "kmigmgrClearMIGGpuInstanceCeMapping_GH100",4,
                       "NVRM: Failure to clear MIG Mappings on lceAvailableMask 0x%x\n",uVar10);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 != uVar1);
    }
    portMemFree(puVar5);
    uVar8 = 0;
  }
  return uVar8;
}


// ===== 003e2860 kmigmgrApplyMIGGpuInstanceCeMapping_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrApplyMIGGpuInstanceCeMapping_GH100(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint uVar9;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  
  uVar9 = 0;
  bitVectorClrAll_IMPL(local_58,0x54);
  bitVectorSetRange_IMPL(local_58,0x54,9,0x1c);
  bitVectorAnd_IMPL(local_58,0x54,local_58,0x54,param_3 + 0x98,0x54);
  bitVectorCopy_IMPL(local_48,0x54,local_58,0x54);
  iVar4 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  while (cVar3 = bitVectorTestAllCleared_IMPL(local_48,0x54), cVar3 == '\0') {
    cVar3 = ceIsCeGrce(param_1,iVar4);
    if (cVar3 == '\0') {
      uVar9 = uVar9 | 1 << (iVar4 - 9U & 0x1f);
    }
    bitVectorClr_IMPL(local_48,0x54,iVar4);
    iVar4 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x93,
               "kmigmgrApplyMIGGpuInstanceCeMapping_GH100",1,
               "NVRM: Setup CE mappings on LCEs 0x%x as part of GPU Instance creation\n",uVar9);
  puVar5 = (undefined4 *)portMemAllocNonPaged(0x80);
  if (puVar5 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pLocalPceLceMap != NULL",
                        "src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x96);
    uVar7 = 0x51;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x8fc);
    if (uVar1 != 0) {
      uVar8 = 0;
LAB_003e29bd:
      do {
        if (((uVar8 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar8 * 8), lVar2 != 0)) &&
           (*(char *)(lVar2 + 0x2d4) != '\0')) {
          puVar6 = puVar5;
          if (((int)(puVar5 + 0x20) - (int)puVar5 & 4U) == 0) goto LAB_003e2a00;
          *puVar5 = 0xf;
          for (puVar6 = puVar5 + 1; puVar6 != puVar5 + 0x20; puVar6 = puVar6 + 2) {
LAB_003e2a00:
            *puVar6 = 0xf;
            puVar6[1] = 0xf;
          }
          (**(code **)(lVar2 + 0x230))(param_1,lVar2,uVar9,puVar5);
          cVar3 = kceApplyMIGMappings_IMPL(param_1,lVar2,puVar5,uVar9);
          if (cVar3 == '\0') {
            uVar8 = uVar8 + 1;
            nvDbg_Printf("src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0xa1,
                         "kmigmgrApplyMIGGpuInstanceCeMapping_GH100",4,
                         "NVRM: Failed to apply MIG Mappings on LCE mask 0x%x\n",uVar9);
            if (uVar8 == uVar1) break;
            goto LAB_003e29bd;
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 != uVar1);
    }
    portMemFree(puVar5);
    uVar7 = 0;
  }
  return uVar7;
}


// ===== 003e2ad0 kmigmgrIsGPUInstanceFlagValid_GH100 =====

bool kmigmgrIsGPUInstanceFlagValid_GH100(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  char cVar1;
  
  cVar1 = kmigmgrIsGPUInstanceFlagLegal_IMPL();
  if (cVar1 == '\0') {
    nvCheckFailedNoLog(4,"kmigmgrIsGPUInstanceFlagLegal(pGpu, pKernelMIGManager, gpuInstanceFlag)",
                       "src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0xc2);
    return false;
  }
  if (5 < ((uint)((param_3 & 0xffffffff) >> 2) & 7)) {
    return false;
  }
  return (param_3 & 0x300000e0) == 0;
}


// ===== 003e2b40 kmigmgrIsGPUInstanceCombinationValid_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kmigmgrIsGPUInstanceCombinationValid_GH100(undefined8 param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  
  uVar2 = (**(code **)(param_2 + 0x1f8))();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar1 = kmigmgrSmallestComputeProfileSize_IMPL(param_1,param_2);
  if (uVar1 != 8) {
    uVar3 = (uint)((param_3 & 0xffffffff) >> 2) & 7;
    if (((param_3 & 0x40000000) != 0) && (uVar3 != uVar1)) {
      return 0;
    }
    uVar1 = (uint)param_3 & 3;
    if (uVar3 != 3) {
      if ((param_3 & 0x10) == 0) {
        if ((uVar3 != 1) && (uVar3 != 2)) {
          return (ulong)((param_3 & 3) == 0);
        }
        return (ulong)(uVar1 == 1);
      }
      if (uVar3 != 4) {
        if (uVar3 == 5) {
          return (ulong)(uVar1 == 3);
        }
        nvAssertFailedNoLog(&DAT_00d5b778,"src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x128
                           );
        return 0;
      }
    }
    return (ulong)(uVar1 == 2);
  }
  nvCheckFailedNoLog(4,"smallestComputeSizeFlag != KMIGMGR_COMPUTE_SIZE_INVALID",
                     "src/kernel/gpu/mig_mgr/arch/hopper/kmigmgr_gh100.c",0x102);
  return 0;
}


// ===== 003e2c40 cisubscriptionCopyConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong cisubscriptionCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong extraout_RDX;
  
  lVar6 = *(long *)(param_3 + 0x58);
  lVar4 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_ComputeInstanceSubscription
                            );
  if (*(uint *)(param_2 + 0x28) < 2) {
    return 0x56;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if ((*(char *)(lVar1 + 0x4913) == '\0') && (*(char *)(lVar1 + 0x909) == '\0')) {
LAB_003e2d5b:
    lVar6 = *(long *)(lVar4 + 0x138);
    *(long *)(param_1 + 0x138) = lVar6;
    uVar7 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(lVar6 + 200));
    if ((int)uVar7 != 0) {
      nvAssertOkFailedNoLog
                (uVar7 & 0xffffffff,
                 "kmigmgrIncRefCount(pComputeInstanceSubscription->pMIGComputeInstance->pShare)",
                 "src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0x96);
      uVar7 = 0;
    }
  }
  else {
    lVar2 = *(long *)(param_2 + 0x10);
    lVar5 = gpuGetRpc();
    if (lVar5 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mig_mgr/compute_instance_subscription.c",
                          0x89);
      uVar3 = 0x1a;
    }
    else {
      uVar7 = (ulong)*(uint *)(lVar6 + 0x10);
      if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
        uVar3 = (**(code **)(lVar5 + 0x128))
                          (lVar1,lVar5,*(undefined4 *)(*(long *)(param_2 + 8) + 0x48),
                           *(undefined4 *)(*(long *)(lVar2 + 0x18) + 0x10),
                           *(undefined4 *)(lVar2 + 0x10),
                           *(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48),uVar7,0);
      }
      else {
        uVar3 = (**(code **)(lVar1 + 0x3ba8))();
        uVar7 = extraout_RDX;
      }
      if (uVar3 == 0) {
        lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 8),__nvoc_class_def_RmResource,uVar7);
        *(undefined1 *)(lVar6 + 0xa4) = 1;
        goto LAB_003e2d5b;
      }
    }
    nvCheckOkFailedNoLog
              (4,uVar3,"status","src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0x91);
    uVar7 = (ulong)uVar3;
  }
  return uVar7;
}


// ===== 003e2e20 cisubscriptionConstruct_IMPL =====

ulong cisubscriptionConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_2 + 8);
  puVar1 = *(undefined8 **)(param_3 + 0x40);
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 8),
                             __nvoc_class_def_GPUInstanceSubscription);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  osRmCapInitDescriptor(param_1 + 0x140);
  if (*(long *)(param_3 + 0x58) != 0) {
    uVar7 = cisubscriptionCopyConstruct_IMPL(param_1,param_2);
    return uVar7;
  }
  if (((lVar2 == 0) || (*(long *)(lVar2 + 0x1bc0) == 0)) ||
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), cVar3 == '\0')) {
    nvAssertFailedNoLog("Compute instance Subscription failed: MIG GPU partitioning not done",
                        "src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0x49);
    return 0x56;
  }
  uVar5 = *(uint *)(puVar1 + 1);
  if (uVar5 < 8) {
    lVar2 = *(long *)(lVar6 + 0x138);
    if ((lVar2 == 0) || (*(char *)(lVar2 + 0x988) == '\0')) {
      return 0x40;
    }
    lVar6 = (ulong)uVar5 * 0x110 + lVar2;
    if (*(char *)(lVar6 + 0x198) != '\0') {
      if (*(int *)(lVar8 + 0x4c) == 0) {
        uVar4 = osRmCapAcquire(*(undefined8 *)(lVar6 + 0x1b0),0x300,*puVar1,param_1 + 0x140);
        if ((uVar4 != 0x56) && (uVar4 != 0)) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0x5f,
                       "cisubscriptionConstruct_IMPL",4,
                       "NVRM: Capability validation failed: ID 0x%0x!\n",*(undefined4 *)(puVar1 + 1)
                      );
          return (ulong)uVar4;
        }
      }
      lVar8 = (ulong)uVar5 * 0x110;
      *(long *)(param_1 + 0x138) = lVar2 + 0xe0 + lVar8;
      uVar5 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(lVar2 + 0x1a8 + lVar8));
      if (uVar5 == 0) {
        return 0;
      }
      nvAssertOkFailedNoLog
                (uVar5,"kmigmgrIncRefCount(pMIGComputeInstance->pShare)",
                 "src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0x68);
      osRmCapRelease(*(undefined8 *)(param_1 + 0x140));
      return (ulong)uVar5;
    }
  }
  return 0x1f;
}


// ===== 003e3060 cisubscriptionDestruct_IMPL =====

void cisubscriptionDestruct_IMPL(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_28;
  undefined1 local_20 [16];
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x110);
  }
  resGetFreeParams_IMPL(uVar2,&local_28,local_20);
  osRmCapRelease(*(undefined8 *)(param_1 + 0x140));
  gisubscriptionCleanupOnUnsubscribe_IMPL(local_28);
  iVar1 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x138) + 200));
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,"kmigmgrDecRefCount(pComputeInstanceSubscription->pMIGComputeInstance->pShare)",
             "src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0xab);
  return;
}


// ===== 003e30e0 cisubscriptionGetComputeInstanceSubscription_IMPL =====

undefined8
cisubscriptionGetComputeInstanceSubscription_IMPL
          (long param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("ppComputeInstanceSubscription != NULL",
                        "src/kernel/gpu/mig_mgr/compute_instance_subscription.c",0xb9);
    return 0x1f;
  }
  lVar1 = serverutilFindChildRefByType(*(undefined4 *)(param_1 + 0x48),param_2,"apiControl_IMPL",1);
  if (lVar1 != 0) {
    uVar2 = __nvoc_dynamicCast(*(undefined8 *)(lVar1 + 8),
                               __nvoc_class_def_ComputeInstanceSubscription);
    *param_3 = uVar2;
    return 0;
  }
  return 0x57;
}


// ===== 003e3160 cisubscriptionCanCopy_IMPL =====

undefined8 cisubscriptionCanCopy_IMPL(void)

{
  return 1;
}


// ===== 003e3170 cisubscriptionCtrlCmdGetUuid_IMPL =====

undefined8 cisubscriptionCtrlCmdGetUuid_IMPL(long param_1,long param_2)

{
  portMemCopy(param_2,0x10,*(long *)(param_1 + 0x138) + 0xd8,0x10);
  nvGetUuidString(*(long *)(param_1 + 0x138) + 0xd8,1,param_2 + 0x10);
  return 0;
}


// ===== 003e31d0 gisubscriptionCopyConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong gisubscriptionCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong extraout_RDX;
  
  lVar7 = *(long *)(param_3 + 0x58);
  lVar4 = __nvoc_dynamicCast(*(undefined8 *)(lVar7 + 8),__nvoc_class_def_GPUInstanceSubscription);
  if (1 < *(uint *)(param_2 + 0x28)) {
    if (*(char *)(lVar4 + 0x140) == '\0') {
      lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
      if ((*(char *)(lVar1 + 0x4913) == '\0') && (*(char *)(lVar1 + 0x909) == '\0')) {
LAB_003e3245:
        lVar7 = *(long *)(lVar4 + 0x138);
        *(undefined1 *)(param_1 + 0x141) = 1;
        *(long *)(param_1 + 0x138) = lVar7;
        uVar5 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(lVar7 + 0x978));
        if ((int)uVar5 != 0) {
          nvAssertOkFailedNoLog
                    (uVar5 & 0xffffffff,
                     "kmigmgrIncRefCount(pGPUInstanceSubscription->pKernelMIGGpuInstance->pShare)",
                     "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",299);
          uVar5 = 0;
        }
        return uVar5;
      }
      lVar2 = *(long *)(param_2 + 0x10);
      lVar6 = gpuGetRpc();
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                            0x11c);
        uVar3 = 0x1a;
      }
      else {
        uVar5 = (ulong)*(uint *)(lVar7 + 0x10);
        if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
          uVar3 = (**(code **)(lVar6 + 0x128))
                            (lVar1,lVar6,*(undefined4 *)(*(long *)(param_2 + 8) + 0x48),
                             *(undefined4 *)(*(long *)(lVar2 + 0x18) + 0x10),
                             *(undefined4 *)(lVar2 + 0x10),
                             *(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48),uVar5,0);
        }
        else {
          uVar3 = (**(code **)(lVar1 + 0x3ba8))();
          uVar5 = extraout_RDX;
        }
        if (uVar3 == 0) {
          lVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 8),__nvoc_class_def_RmResource,uVar5);
          *(undefined1 *)(lVar7 + 0xa4) = 1;
          goto LAB_003e3245;
        }
      }
      nvCheckOkFailedNoLog
                (4,uVar3,"status","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x124);
      return (ulong)uVar3;
    }
    nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x112,
                 "gisubscriptionCopyConstruct_IMPL",4,
                 "NVRM: Subscription failed: Duping not allowed for Device-level-SwizzId\n");
  }
  return 0x56;
}


// ===== 003e3420 gisubscriptionConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gisubscriptionConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  long *plVar11;
  long lVar12;
  ulong uVar13;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  long local_c0;
  undefined8 local_b8;
  undefined8 local_a0;
  long local_98;
  long local_90 [2];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  puVar2 = *(undefined8 **)(param_3 + 0x10);
  lVar3 = *(long *)(param_2 + 8);
  plVar11 = (long *)__nvoc_dynamicCast(lVar3,__nvoc_class_def_RmClient);
  if (plVar11 == (long *)0x0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        0x89);
    return 0x23;
  }
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  osRmCapInitDescriptor(param_1 + 0x148);
  if (*(long *)(param_3 + 0x16) != 0) {
    uVar13 = gisubscriptionCopyConstruct_IMPL(param_1,param_2,param_3);
    return uVar13;
  }
  lVar5 = *(long *)(lVar4 + 0x1bc0);
  if (lVar5 != 0) {
    iVar1 = *(int *)(puVar2 + 1);
    cVar8 = kmigmgrIsMIGEnabled_IMPL(lVar4);
    if (cVar8 != '\0') {
      rmapiControlCacheSetMode(0);
      if (iVar1 == -2) {
        if ((*(char *)(lVar4 + 0x4a27) != '\0') &&
           (cVar8 = (**(code **)(*plVar11 + 0xe0))(plVar11,*(undefined4 *)(param_2 + 0x28)),
           cVar8 == '\0')) {
          return 0x1b;
        }
        cVar8 = kmigmgrIsDeviceProfilingInUse_IMPL(lVar4,lVar5);
        if (cVar8 != '\0') {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xb0,
                       "gisubscriptionConstruct_IMPL",4,
                       "NVRM: Subscription failed: Device-Level-Monitoring already in use\n");
          return 0x40;
        }
        uVar10 = kmigmgrSetDeviceProfilingInUse_IMPL(lVar4,lVar5);
        if (uVar10 != 0) {
          nvAssertOkFailedNoLog
                    (uVar10,"kmigmgrSetDeviceProfilingInUse(pGpu, pKernelMIGManager)",
                     "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xb6);
          return (ulong)uVar10;
        }
        *(undefined1 *)(param_1 + 0x140) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x140) = 0;
        if ((*(long *)(lVar4 + 0x1bc0) == 0) ||
           (cVar8 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar4), cVar8 == '\0')) {
          nvAssertFailedNoLog("Subscription failed: MIG GPU instancing not done\n",
                              "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xc1);
          return 0x56;
        }
        cVar8 = kmigmgrIsSwizzIdInUse_IMPL(lVar4,lVar5,iVar1);
        if (cVar8 == '\0') {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",199,
                       "gisubscriptionConstruct_IMPL",4,
                       "NVRM: Subscription failed: swizzid 0x%0x doesn\'t exist!\n",iVar1);
          return 0x1f;
        }
        lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
        uVar7 = *(undefined8 *)(lVar6 + 0x1bc0);
        iVar9 = refFindAncestorOfType(*(undefined8 *)(param_2 + 0x10),&DAT_00e0ac20,&local_98);
        if (iVar9 != 0) {
          nvAssertOkFailedNoLog
                    (iVar9,
                     "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)"
                     ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x49);
        }
        lVar12 = __nvoc_dynamicCast(*(undefined8 *)(local_98 + 8),__nvoc_class_def_Device);
        iVar9 = *(int *)(lVar12 + 0x1a8);
        if (iVar9 == 0) {
LAB_003e3970:
          nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xcf,
                       "gisubscriptionConstruct_IMPL",4,
                       "NVRM: Subscription failed: Client shares VAS with client not subscribed to target GPU instance!\n"
                      );
          return 99;
        }
        if (iVar9 != *(int *)(*(long *)(param_2 + 8) + 0x48)) {
          iVar9 = serverGetClientUnderLock(g_resServ,iVar9,&local_a0);
          if (iVar9 == 0) {
            clientRefIter(&local_f8,local_a0,0,&DAT_00e0ac20,0,1);
            local_80 = local_f8;
            local_78 = local_f0;
            local_70 = local_e8;
            local_68 = local_e0;
            local_60 = local_d8;
            local_58 = local_d0;
            local_50 = local_c8;
            local_48 = local_c0;
            local_40 = local_b8;
            do {
              cVar8 = clientRefIterNext(local_a0,&local_80);
              if (cVar8 == '\0') goto LAB_003e3970;
              lVar12 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device);
            } while (((lVar6 != *(long *)(*(long *)(lVar12 + 0x128) + 0xe0)) ||
                     (iVar9 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar6,uVar7,lVar12,local_90),
                     iVar9 != 0)) || (iVar1 != *(int *)(local_90[0] + 0x968)));
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar9,
                       "serverGetClientUnderLock(&g_resServ, pDevice->hClientShare, &pRsClientShare)"
                       ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x5f);
            if ((char)iVar9 != '\0') goto LAB_003e3970;
          }
        }
        uVar10 = kmigmgrGetGPUInstanceInfo_IMPL(lVar4,lVar5,iVar1,param_1 + 0x138);
        if (uVar10 != 0) {
          nvAssertOkFailedNoLog
                    (uVar10,
                     "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pGPUInstanceSubscription->pKernelMIGGpuInstance)"
                     ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xd4);
          return (ulong)uVar10;
        }
        if (*(int *)(lVar3 + 0x4c) == 0) {
          uVar10 = osRmCapAcquire(*(undefined8 *)(*(long *)(param_1 + 0x138) + 0x9b8),0x100,*puVar2,
                                  param_1 + 0x148);
          if ((uVar10 != 0x56) && (uVar10 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xe1,
                         "gisubscriptionConstruct_IMPL",4,
                         "NVRM: Capability validation failed: swizzid 0x%0x!\n",iVar1);
            return (ulong)uVar10;
          }
        }
        uVar10 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x138) + 0x978));
        if (uVar10 != 0) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xeb,
                       "gisubscriptionConstruct_IMPL",4,
                       "NVRM: GPU instance ref-counting failed: swizzid 0x%0x!\n",iVar1);
          osRmCapRelease(*(undefined8 *)(param_1 + 0x148));
          return (ulong)uVar10;
        }
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0xf2,
                   "gisubscriptionConstruct_IMPL",1,
                   "NVRM: Client 0x%x subscribed to swizzid 0x%0x.\n",*param_3,iVar1);
      return 0;
    }
  }
  nvAssertFailedNoLog("Subscription failed: MIG not enabled\n",
                      "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x96);
  return 0x56;
}


// ===== 003e3ab0 gisubscriptionGetGPUInstanceSubscription_IMPL =====

undefined8
gisubscriptionGetGPUInstanceSubscription_IMPL(long param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != ppGPUInstanceSubscription",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x163);
    return 0x1f;
  }
  lVar1 = serverutilFindChildRefByType(*(undefined4 *)(param_1 + 0x48),param_2,0x91fde7,1);
  if (lVar1 != 0) {
    uVar2 = __nvoc_dynamicCast(*(undefined8 *)(lVar1 + 8),__nvoc_class_def_GPUInstanceSubscription);
    *param_3 = uVar2;
    return 0;
  }
  return 0x57;
}


// ===== 003e3b30 gisubscriptionCanCopy_IMPL =====

undefined8 gisubscriptionCanCopy_IMPL(void)

{
  return 1;
}


// ===== 003e3b40 gisubscriptionCtrlCmdExecPartitionsCreate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int gisubscriptionCtrlCmdExecPartitionsCreate_IMPL(long param_1,char *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  char *local_168;
  char *local_158;
  uint uStack_13c;
  undefined4 uStack_134;
  undefined4 uStack_124;
  undefined4 uStack_11c;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100 [2];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 local_a0 [8];
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
  undefined4 local_48;
  
  lVar1 = *(long *)(param_1 + 0x138);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1bc0);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x18c);
    return 0x2f;
  }
  lVar7 = resservGetTlsCallContext();
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        0x191);
    return 0x40;
  }
  lVar8 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar8 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        0x194);
    return 0x23;
  }
  cVar5 = rmclientIsCapableOrAdmin_IMPL(lVar8,2,*(undefined4 *)(lVar7 + 0x28));
  if (cVar5 == '\0') {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x19a,
                 "gisubscriptionCtrlCmdExecPartitionsCreate_IMPL",4,
                 "NVRM: Non-privileged context issued privileged cmd\n");
    return 0x1b;
  }
  if (*(char *)(lVar2 + 0x467) == '\0') {
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_MIG_SUPPORTED)",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x19f);
  }
  else {
    if ((*(long *)(lVar2 + 0x1bc0) == 0) ||
       (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), cVar5 == '\0')) {
      nvAssertFailedNoLog("IS_MIG_IN_USE(pGpu)","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c"
                          ,0x1a0);
      return 0x40;
    }
    if (*(char *)(lVar2 + 0x908) != '\0') {
      lVar7 = gpuGetStaticInfo(lVar2);
      if (lVar7 == 0) {
        nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                            0x1a7);
        return 0x1f;
      }
      if ((*(byte *)(lVar7 + 0xa727) & 2) == 0) {
        return 0x56;
      }
    }
    if (8 < *(uint *)(param_2 + 8)) {
      return 0x1f;
    }
    if (*(uint *)(param_2 + 8) == 0) {
      return 0x10006;
    }
    if ((*(char *)(lVar2 + 0x908) != '\0') || (*(char *)(lVar2 + 0x909) != '\0')) {
      lVar7 = resservGetTlsCallContext();
      puVar4 = *(undefined4 **)(lVar7 + 0x48);
      lVar7 = gpuGetRpc(lVar2);
      if (lVar7 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                            0x1bb);
        iVar6 = 0x1a;
      }
      else {
        if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
          iVar6 = rpcDmaControl_wrapper
                            (lVar2,lVar7,*puVar4,puVar4[1],puVar4[2],*(undefined8 *)(puVar4 + 4),
                             puVar4[6]);
        }
        else {
          iVar6 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58);
        }
        if (iVar6 == 0) {
          iVar6 = *(int *)(param_2 + 8);
          if (*(char *)(lVar2 + 0x909) == '\0') {
            uVar11 = *(uint *)(param_2 + 4);
            if (*(char *)(lVar2 + 0x491d) == '\0') {
              uVar11 = *(uint *)(param_2 + 4) & 0xfffffffe;
            }
            if (*(char *)(lVar2 + 0x908) == '\0') {
              return 0x56;
            }
            if (*(char *)(lVar2 + 0x468) == '\0') {
              iVar6 = (**(code **)(lVar3 + 0x218))
                                (lVar2,lVar3,lVar1,*param_2,param_2 + 0x1ac,1,
                                 (ulong)uStack_13c << 0x20,CONCAT44(uStack_134,iVar6),param_2 + 0xc,
                                 CONCAT44(uStack_124,uVar11));
              uVar11 = *(uint *)(param_2 + 8);
            }
            else {
              if (iVar6 == 0) goto LAB_003e3eb0;
              uVar12 = 0;
              iVar6 = 0;
              local_158 = param_2 + 0x1ac;
              do {
                uVar10 = (ulong)uVar12;
                portMemSet(local_100,0,0x60);
                local_100[0] = *(undefined4 *)(param_2 + uVar10 * 4 + 0x1ac);
                lVar7 = gpuGetRpc(lVar2);
                if (lVar7 == 0) {
                  nvAssertFailedNoLog("pRpc != NULL",
                                      "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x1e5);
                  iVar6 = 0x1a;
LAB_003e4332:
                  uVar9 = 0x1eb;
                  goto LAB_003e4337;
                }
                if (iVar6 != 0) goto LAB_003e4332;
                if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
                  iVar6 = rpcDmaControl_wrapper
                                    (lVar2,lVar7,*(undefined4 *)(lVar1 + 0x9c0),
                                     *(undefined4 *)(lVar1 + 0x9cc),0xc6370105,local_100,0x60);
                }
                else {
                  iVar6 = (**(code **)(lVar2 + 0x3b90))
                                    (lVar2 + 0x3b58,*(undefined4 *)(lVar1 + 0x9c0),
                                     *(undefined4 *)(lVar1 + 0x9cc),0xc6370105,local_100,0x60);
                }
                if (iVar6 != 0) goto LAB_003e4332;
                uVar12 = uVar12 + 1;
                portMemSet(local_a0,0,0x68);
                local_48 = *(undefined4 *)(param_2 + uVar10 * 4 + 0x1ac);
                local_a0[0] = 1;
                local_98 = local_f8;
                local_90 = local_f0;
                local_88 = local_e8;
                local_80 = local_e0;
                local_78 = local_d8;
                local_70 = local_d0;
                local_68 = local_c8;
                local_60 = local_c0;
                local_58 = local_b8;
                local_50 = local_b0;
                iVar6 = (**(code **)(lVar3 + 0x218))
                                  (lVar2,lVar3,lVar1,*param_2,local_158,1,CONCAT44(uStack_11c,1),
                                   local_a0,local_110,local_108);
                uVar11 = *(uint *)(param_2 + 8);
                local_158 = local_158 + 4;
              } while (uVar12 < uVar11);
            }
            if (uVar11 != 0) {
              uVar11 = 0;
              do {
                uVar10 = (ulong)uVar11;
                uVar11 = uVar11 + 1;
                gpumgrCacheCreateComputeInstance_IMPL
                          (lVar2,*(undefined4 *)(lVar1 + 0x968),
                           *(undefined4 *)(param_2 + uVar10 * 4 + 0x1ac));
              } while (uVar11 < *(uint *)(param_2 + 8));
            }
          }
          else if (iVar6 != 0) {
            local_168 = param_2 + 0x1ac;
            uVar10 = 0;
            do {
              portMemSet(local_100,0,0x60);
              local_100[0] = *(undefined4 *)(param_2 + uVar10 * 4 + 0x1ac);
              iVar6 = (**(code **)(lVar2 + 0x3b90))
                                (lVar2 + 0x3b58,*(undefined4 *)(lVar1 + 0x9c0),
                                 *(undefined4 *)(lVar1 + 0x9cc),0xc6370105,local_100,0x60);
              if (iVar6 != 0) {
                nvAssertOkFailedNoLog
                          (iVar6,
                           "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_EXPORT, &export, sizeof(export))"
                           ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x21c);
                return iVar6;
              }
              portMemSet(local_a0,0,0x68);
              local_48 = *(undefined4 *)(param_2 + uVar10 * 4 + 0x1ac);
              local_a0[0] = 1;
              local_98 = local_f8;
              local_90 = local_f0;
              local_88 = local_e8;
              local_80 = local_e0;
              local_78 = local_d8;
              local_70 = local_d0;
              local_68 = local_c8;
              local_60 = local_c0;
              local_58 = local_b8;
              local_50 = local_b0;
              iVar6 = (**(code **)(lVar3 + 0x218))
                                (lVar2,lVar3,lVar1,0,local_168,1,CONCAT44(uStack_11c,1),local_a0,
                                 local_110,local_108);
              if (iVar6 != 0) {
                nvAssertOkFailedNoLog
                          (iVar6,
                           "kmigmgrCreateComputeInstances_HAL(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, NV_FALSE, restore, &pParams->execPartId[i], NV_TRUE)"
                           ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x229);
                return iVar6;
              }
              lVar7 = uVar10 * 4;
              uVar11 = (int)uVar10 + 1;
              uVar10 = (ulong)uVar11;
              gpumgrCacheCreateComputeInstance_IMPL
                        (lVar2,*(undefined4 *)(lVar1 + 0x968),
                         *(undefined4 *)(param_2 + lVar7 + 0x1ac));
              local_168 = local_168 + 4;
              iVar6 = 0;
            } while (uVar11 < *(uint *)(param_2 + 8));
          }
LAB_003e3eb0:
          if (*param_2 == '\0') {
            gpuNotifySubDeviceEvent_IMPL(lVar2,0x9f,0,0,0,0);
            return iVar6;
          }
          return iVar6;
        }
      }
      uVar9 = 0x1c1;
LAB_003e4337:
      nvAssertOkFailedNoLog
                (iVar6,"status","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",uVar9);
      return iVar6;
    }
  }
  return 0x56;
}


// ===== 003e4490 gisubscriptionCtrlCmdExecPartitionsDelete_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gisubscriptionCtrlCmdExecPartitionsDelete_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  uint *puVar9;
  uint uVar10;
  ulong local_30;
  
  lVar7 = *(long *)(param_1 + 0x138);
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x251);
    return 0x2f;
  }
  lVar5 = resservGetTlsCallContext();
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        599);
    return 0x40;
  }
  lVar6 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        0x25a);
    return 0x23;
  }
  cVar3 = rmclientIsCapableOrAdmin_IMPL(lVar6,2,*(undefined4 *)(lVar5 + 0x28));
  if (cVar3 == '\0') {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x260,
                 "gisubscriptionCtrlCmdExecPartitionsDelete_IMPL",4,
                 "NVRM: Non-privileged context issued privileged cmd\n");
    return 0x1b;
  }
  if (*(char *)(lVar1 + 0x467) == '\0') {
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_MIG_SUPPORTED)",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x265);
  }
  else {
    if ((*(long *)(lVar1 + 0x1bc0) == 0) ||
       (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar3 == '\0')) {
      nvAssertFailedNoLog("IS_MIG_IN_USE(pGpu)","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c"
                          ,0x268);
      return 0x40;
    }
    if (*(char *)(lVar1 + 0x908) != '\0') {
      lVar5 = gpuGetStaticInfo(lVar1);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                            0x26f);
        return 0x1f;
      }
      if ((*(byte *)(lVar5 + 0xa727) & 2) == 0) {
        return 0x56;
      }
    }
    uVar10 = *param_2;
    if (8 < uVar10) {
      return 0x1f;
    }
    if (uVar10 == 0) {
      return 0x10006;
    }
    puVar9 = param_2;
    do {
      if (7 < puVar9[1]) {
        nvCheckFailedNoLog(4,"execPartId < KMIGMGR_MAX_COMPUTE_INSTANCES",
                           "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x282);
        return 0x1f;
      }
      if (*(char *)(lVar7 + 0x198 + (ulong)puVar9[1] * 0x110) == '\0') {
        nvCheckFailedNoLog(4,"pKernelMIGGpuInstance->MIGComputeInstance[execPartId].bValid",
                           "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x285);
        return 0x1f;
      }
      puVar9 = puVar9 + 1;
    } while (puVar9 != param_2 + uVar10);
    uVar10 = 0;
    while ((*(char *)(lVar1 + 0x908) != '\0' || (*(char *)(lVar1 + 0x909) != '\0'))) {
      uVar4 = kmigmgrDeleteComputeInstance_IMPL
                        (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),lVar7,param_2[(ulong)uVar10 + 1],0);
      if (uVar4 != 0) {
        local_30 = (ulong)uVar4;
        nvCheckOkFailedNoLog
                  (4,uVar4,
                   "kmigmgrDeleteComputeInstance(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, pParams->execPartId[execPartIdx], NV_FALSE)"
                   ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x290);
        return local_30;
      }
      uVar8 = (ulong)uVar10;
      uVar10 = uVar10 + 1;
      gpumgrCacheDestroyComputeInstance_IMPL
                (lVar1,*(undefined4 *)(lVar7 + 0x968),param_2[uVar8 + 1]);
      if (*param_2 <= uVar10) {
        gpuNotifySubDeviceEvent_IMPL(lVar1,0x9f,0,0,0,0);
        if ((*(char *)(lVar1 + 0x908) == '\0') && (*(char *)(lVar1 + 0x909) == '\0')) {
          return 0;
        }
        lVar7 = resservGetTlsCallContext();
        puVar2 = *(undefined4 **)(lVar7 + 0x48);
        lVar7 = lVar1;
        lVar5 = gpuGetRpc();
        if (lVar5 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                              0x2a8);
          uVar8 = 0x1a;
        }
        else {
          if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
            uVar8 = rpcDmaControl_wrapper
                              (lVar1,lVar5,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                               puVar2[6],lVar7);
          }
          else {
            uVar8 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
          }
          if ((int)uVar8 == 0) {
            return uVar8;
          }
        }
        nvAssertOkFailedNoLog
                  (uVar8 & 0xffffffff,"status","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                   0x2ad);
        return uVar8 & 0xffffffff;
      }
    }
  }
  return 0x56;
}


// ===== 003e48d0 gisubscriptionCtrlCmdExecPartitionsGet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gisubscriptionCtrlCmdExecPartitionsGet_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  uint uVar12;
  long local_60;
  long local_50;
  undefined1 local_48 [24];
  
  local_50 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(param_1 + 0x138);
  lVar8 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar8 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        0x2c6);
    return 0x23;
  }
  lVar9 = resservGetTlsCallContext();
  if (lVar9 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                        0x2cb);
    return 0x40;
  }
  cVar4 = rmclientIsCapableOrAdmin_IMPL(lVar8,2,*(undefined4 *)(lVar9 + 0x28));
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x2d7);
    iVar6 = 0x2f;
  }
  else {
    if (*(char *)(lVar1 + 0x467) != '\0') {
      if ((*(long *)(lVar1 + 0x1bc0) != 0) &&
         (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar5 != '\0')) {
        puVar3 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
        cisubscriptionGetComputeInstanceSubscription_IMPL
                  (*puVar3,*(undefined4 *)(puVar3 + 2),&local_50);
        local_60 = local_50;
        if (local_50 == 0) {
          if (cVar4 == '\0') {
            return 0x1b;
          }
        }
        else {
          local_60 = *(long *)(local_50 + 0x138);
        }
        *param_2 = 0;
        uVar12 = 0;
        lVar8 = lVar2 + 0x170;
        do {
          if ((*(char *)(lVar8 + 0x28) != '\0') && ((local_60 == lVar8 + -0x90 || (cVar4 != '\0'))))
          {
            uVar7 = *param_2;
            uVar11 = (ulong)uVar7;
            param_2[uVar11 + 1] = uVar12;
            *param_2 = uVar7 + 1;
            param_2[uVar11 * 0xd + 9] = *(uint *)(lVar8 + -0x10);
            param_2[uVar11 * 0xd + 10] = *(uint *)(lVar8 + -0xc);
            param_2[uVar11 * 0xd + 0xb] = *(uint *)(lVar8 + -4);
            if (*(char *)(lVar1 + 0x469) == '\0') {
              uVar7 = kmigmgrCountEnginesOfType_IMPL(lVar8,9);
              param_2[uVar11 * 0xd + 0xc] = uVar7;
            }
            else {
              lVar9 = *(long *)(lVar1 + 0x1bc0);
              iVar6 = kmigmgrEngBitVectorXlate_IMPL(lVar2 + 0xa8,lVar8,lVar2 + 0x98,local_48);
              if (iVar6 != 0) {
                nvAssertOkFailedNoLog
                          (iVar6,
                           "kmigmgrEngBitVectorXlate(&pKernelMIGGpuInstance->resourceAllocation.localEngines, &pMIGComputeInstance->resourceAllocation.engines, &pKernelMIGGpuInstance->resourceAllocation.engines, &globalEngines)"
                           ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x303);
                return iVar6;
              }
              uVar10 = (**(code **)(lVar9 + 0x170))(lVar1,lVar9);
              uVar7 = kmigmgrCountEnginesInRange_IMPL(local_48,uVar10);
              param_2[uVar11 * 0xd + 0xc] = uVar7;
            }
            uVar7 = kmigmgrCountEnginesOfType_IMPL(lVar8,0x25);
            param_2[uVar11 * 0xd + 0xd] = uVar7;
            uVar7 = kmigmgrCountEnginesOfType_IMPL(lVar8,0x1d);
            param_2[uVar11 * 0xd + 0xe] = uVar7;
            uVar7 = kmigmgrCountEnginesOfType_IMPL(lVar8,0x36);
            param_2[uVar11 * 0xd + 0xf] = uVar7;
            uVar7 = kmigmgrCountEnginesOfType_IMPL(lVar8,0x3e);
            param_2[uVar11 * 0xd + 0x10] = uVar7;
            param_2[uVar11 * 0xd + 0x11] = *(uint *)(lVar8 + 0x2c);
            param_2[uVar11 * 0xd + 0x12] = *(uint *)(lVar8 + -8);
            param_2[uVar11 * 0xd + 0x13] = *(uint *)(lVar8 + 0x24);
            param_2[uVar11 * 0xd + 0x15] = *(uint *)(lVar8 + 0x70);
            param_2[uVar11 * 0xd + 0x14] = *(uint *)(lVar8 + 0x6c);
          }
          uVar12 = uVar12 + 1;
          lVar8 = lVar8 + 0x110;
        } while (uVar12 != 8);
        return 0;
      }
      nvAssertFailedNoLog("IS_MIG_IN_USE(pGpu)","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c"
                          ,0x2dc);
      return 0x40;
    }
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_MIG_SUPPORTED)",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x2d9);
    iVar6 = 0x56;
  }
  return iVar6;
}


// ===== 003e4cd0 gisubscriptionCtrlCmdExecPartitionsGetActiveIds_IMPL =====

undefined8 gisubscriptionCtrlCmdExecPartitionsGetActiveIds_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  uint uVar5;
  
  lVar4 = *(long *)(param_1 + 0x138);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x334);
    return 0x2f;
  }
  if (*(char *)(lVar2 + 0x467) == '\0') {
    nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_MIG_SUPPORTED)",
                        "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x336);
    return 0x56;
  }
  if ((*(long *)(lVar2 + 0x1bc0) != 0) &&
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), cVar3 != '\0')) {
    *param_2 = 0;
    lVar4 = lVar4 + 0x1b8;
    uVar5 = 0;
    do {
      if (*(char *)(lVar4 + -0x20) != '\0') {
        uVar1 = *param_2;
        param_2[(ulong)uVar1 + 1] = uVar5;
        nvGetUuidString(lVar4,1,(ulong)uVar1 * 0x29 + 0x24 + (long)param_2);
        *param_2 = *param_2 + 1;
      }
      uVar5 = uVar5 + 1;
      lVar4 = lVar4 + 0x110;
    } while (uVar5 != 8);
    return 0;
  }
  nvAssertFailedNoLog("IS_MIG_IN_USE(pGpu)","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                      0x339);
  return 0x40;
}


// ===== 003e4e40 gisubscriptionCtrlCmdExecPartitionsExport_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 gisubscriptionCtrlCmdExecPartitionsExport_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  uint uVar9;
  
  lVar8 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if ((lVar8 != 0) && (*(long *)(lVar8 + 0x1bc0) != 0)) {
    lVar6 = *(long *)(param_1 + 0x138);
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar8);
    if (cVar3 != '\0') {
      lVar4 = resservGetTlsCallContext();
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pCallContext != NULL",
                            "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x369);
        return 0x40;
      }
      lVar5 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                                 __nvoc_class_def_RmClient);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c"
                            ,0x36c);
        return 0x23;
      }
      cVar3 = rmclientIsCapableOrAdmin_IMPL(lVar5,2,*(undefined4 *)(lVar4 + 0x28));
      if (cVar3 == '\0') {
        return 0x1b;
      }
      if (*(char *)(lVar8 + 0x908) == '\0') {
        if (*(char *)(lVar8 + 0x909) != '\0') {
          lVar6 = resservGetTlsCallContext();
          puVar2 = *(undefined4 **)(lVar6 + 0x48);
          uVar7 = (**(code **)(lVar8 + 0x3b90))
                            (lVar8 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                             puVar2[6]);
          return uVar7;
        }
        if (7 < *param_2) {
          return 0x1f;
        }
        lVar8 = (ulong)*param_2 * 0x110;
        if (*(char *)(lVar6 + 0x198 + lVar8) == '\0') {
          return 0x57;
        }
        portMemCopy(param_2 + 10,0x10,lVar6 + 0x1b8 + lVar8,0x10);
        lVar4 = lVar6 + lVar8;
        param_2[0xe] = *(uint *)(lVar4 + 0x19c);
        param_2[0x10] = *(uint *)(lVar4 + 0x164);
        param_2[0x11] = *(uint *)(lVar4 + 0x168);
        param_2[0x12] = *(uint *)(lVar4 + 0x16c);
        param_2[0x13] = *(uint *)(lVar4 + 0x194);
        param_2[0x14] = *(uint *)(lVar4 + 0x1dc);
        param_2[0x15] = *(uint *)(lVar4 + 0x1e0);
        if (*(int *)(lVar4 + 0x160) != 0) {
          uVar9 = param_2[0xf];
          lVar5 = 0;
          do {
            lVar1 = lVar5 * 4;
            lVar5 = lVar5 + 1;
            uVar9 = uVar9 | 1 << ((byte)*(undefined4 *)(lVar4 + 0xe0 + lVar1) & 0x1f);
            param_2[0xf] = uVar9;
          } while ((uint)lVar5 < *(uint *)(lVar4 + 0x160));
        }
        bitVectorToRaw_IMPL(lVar6 + 0x170 + lVar8,0x54,param_2 + 2,0x20);
        return 0;
      }
    }
  }
  return 0x56;
}


// ===== 003e5110 gisubscriptionCtrlCmdExecPartitionsImport_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int gisubscriptionCtrlCmdExecPartitionsImport_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  long *plVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined4 uStack_ac;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
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
  undefined4 local_38;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (*(char *)(lVar1 + 0x467) != '\0') {
    uVar2 = *(undefined8 *)(param_1 + 0x138);
    lVar8 = resservGetTlsCallContext();
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pCallContext != NULL",
                          "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x3b9);
      return 0x40;
    }
    lVar9 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                               __nvoc_class_def_RmClient);
    if (lVar9 == 0) {
      nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                          0x3bc);
      return 0x23;
    }
    cVar5 = rmclientIsCapableOrAdmin_IMPL(lVar9,2,*(undefined4 *)(lVar8 + 0x28));
    if (cVar5 == '\0') {
      return 0x1b;
    }
    if (*(char *)(lVar1 + 0x908) == '\0') {
      if (*(char *)(lVar1 + 0x909) != '\0') {
        lVar8 = resservGetTlsCallContext();
        puVar3 = *(undefined4 **)(lVar8 + 0x48);
        iVar6 = (**(code **)(lVar1 + 0x3b90))
                          (lVar1 + 0x3b58,*puVar3,puVar3[1],puVar3[2],*(undefined8 *)(puVar3 + 4),
                           puVar3[6]);
        if (iVar6 != 0) {
          return iVar6;
        }
      }
      portMemSet(&local_90,0,0x68);
      local_38 = *param_2;
      local_90 = CONCAT31(local_90._1_3_,1);
      local_88 = *(undefined8 *)(param_2 + 2);
      local_80 = *(undefined8 *)(param_2 + 4);
      local_78 = *(undefined8 *)(param_2 + 6);
      local_70 = *(undefined8 *)(param_2 + 8);
      local_68 = *(undefined8 *)(param_2 + 10);
      local_60 = *(undefined8 *)(param_2 + 0xc);
      local_58 = *(undefined8 *)(param_2 + 0xe);
      local_50 = *(undefined8 *)(param_2 + 0x10);
      local_48 = *(undefined8 *)(param_2 + 0x12);
      local_40 = *(undefined8 *)(param_2 + 0x14);
      if (*(char *)(lVar1 + 0x909) != '\0') {
        iVar6 = (**(code **)(*(long *)(lVar1 + 0x1bc0) + 0x218))
                          (lVar1,*(long *)(lVar1 + 0x1bc0),uVar2,0,param_2,
                           *(undefined1 *)(param_2 + 0x16),CONCAT44(uStack_ac,1),&local_90,local_a0,
                           local_98);
        if (iVar6 == 0) {
          return 0;
        }
        nvCheckOkFailedNoLog
                  (4,iVar6,
                   "kmigmgrCreateComputeInstances_HAL(pGpu, pKernelMIGManager, pGPUInstance, NV_FALSE, restore, &pParams->id, pParams->bCreateCap)"
                   ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x3ee);
        if (*(char *)(lVar1 + 0x909) == '\0') {
          return iVar6;
        }
        portMemSet(&local_90,0,0x24);
        local_8c = *param_2;
        local_90 = 1;
        plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
        iVar7 = (**(code **)(lVar1 + 0x3b90))
                          (lVar1 + 0x3b58,*(undefined4 *)(*plVar4 + 0x48),(int)plVar4[2],0xc6370102,
                           &local_90,0x24);
        if (iVar7 == 0) {
          return iVar6;
        }
        nvAssertOkFailedNoLog
                  (iVar7,
                   "pRmApi->Control(pRmApi, RES_GET_CLIENT_HANDLE(pGPUInstanceSubscription), RES_GET_HANDLE(pGPUInstanceSubscription), NVC637_CTRL_CMD_EXEC_PARTITIONS_DELETE, &params, sizeof(params))"
                   ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x405);
        return iVar6;
      }
    }
  }
  return 0x56;
}


// ===== 003e5460 gisubscriptionCleanupOnUnsubscribe_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gisubscriptionCleanupOnUnsubscribe_IMPL(long param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  lVar4 = rmapiGetInterface(4);
  iVar3 = refFindAncestorOfType(*(undefined8 *)(param_1 + 0x10),&DAT_00e0ac20,&local_88);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,
               "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
               "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x445);
  }
  uVar7 = 0;
  serverutilRefIter(&local_d8,*(undefined4 *)(*(long *)(param_1 + 8) + 0x48),
                    *(undefined4 *)(local_88 + 0x10),0,1,0);
  local_80 = local_d8;
  local_78 = local_d0;
  local_70 = local_c8;
  local_68 = local_c0;
  local_60 = local_b8;
  local_58 = local_b0;
  local_50 = local_a8;
  local_48 = local_a0;
  local_40 = local_98;
LAB_003e5540:
  do {
    cVar2 = clientRefIterNext(local_60,&local_80);
    if (cVar2 == '\0') break;
    uVar8 = *(uint *)(local_48 + 0x118);
    if (uVar8 != 0xd1f238) {
      if (uVar8 < 0xd1f239) {
        if ((uVar8 == 0x4b01b3) || (uVar8 == 0x91fde7)) goto LAB_003e5540;
      }
      else if (uVar8 == 0xe0ac20) goto LAB_003e5540;
      uVar7 = uVar7 + 1;
      nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x457,
                   "gisubscriptionCleanupOnUnsubscribe_IMPL",1,
                   "NVRM: Will be freeing resource class id 0x%x on unsubscription!\n");
    }
  } while( true );
  if (uVar7 != 0) {
    puVar5 = (undefined4 *)portMemAllocNonPaged((ulong)uVar7 * 4);
    if (puVar5 != (undefined4 *)0x0) {
      serverutilRefIter(&local_d8,*(undefined4 *)(*(long *)(param_1 + 8) + 0x48),
                        *(undefined4 *)(local_88 + 0x10),0,1,0);
      local_80 = local_d8;
      local_78 = local_d0;
      local_70 = local_c8;
      local_68 = local_c0;
      local_60 = local_b8;
      local_58 = local_b0;
      local_50 = local_a8;
      local_48 = local_a0;
      local_40 = local_98;
      uVar9 = 0;
LAB_003e5690:
      do {
        cVar2 = clientRefIterNext(local_60,&local_80);
        uVar8 = (uint)uVar9;
        if (cVar2 == '\0') {
          puVar6 = puVar5;
          if (uVar7 == uVar8) {
            do {
              (**(code **)(lVar4 + 0x18))
                        (lVar4,*(undefined4 *)(*(long *)(param_1 + 8) + 0x48),*puVar6);
              puVar6 = puVar6 + 1;
            } while (puVar5 + uVar7 != puVar6);
          }
          else {
            nvAssertFailedNoLog("i == handleCount",
                                "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x47f);
          }
LAB_003e5704:
          portMemFree(puVar5);
          return;
        }
        uVar1 = *(uint *)(local_48 + 0x118);
      } while (uVar1 == 0xd1f238);
      if (uVar1 < 0xd1f239) {
        if ((uVar1 == 0x4b01b3) || (uVar1 == 0x91fde7)) goto LAB_003e5690;
      }
      else if (uVar1 == 0xe0ac20) goto LAB_003e5690;
      if (uVar7 <= uVar8) {
        nvAssertFailedNoLog("i < handleCount","src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",
                            0x476);
        goto LAB_003e5704;
      }
      puVar5[uVar9] = *(undefined4 *)(local_48 + 0x10);
      uVar9 = (ulong)(uVar8 + 1);
      goto LAB_003e5690;
    }
    nvAssertFailedNoLog(&DAT_00d5c3c9,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x464);
  }
  return;
}


// ===== 003e57f0 gisubscriptionDestruct_IMPL =====

undefined1  [16] gisubscriptionDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 auVar4 [16];
  undefined8 local_38;
  undefined1 local_30 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar2 = *(undefined8 *)(lVar1 + 0x1bc0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),&local_38,local_30);
  if (*(char *)(param_1 + 0x140) == '\0') {
    iVar3 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x138) + 0x978));
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"kmigmgrDecRefCount(pGPUInstanceSubscription->pKernelMIGGpuInstance->pShare)"
                 ,"src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x145);
    }
    osRmCapRelease(*(undefined8 *)(param_1 + 0x148));
    gisubscriptionCleanupOnUnsubscribe_IMPL(local_38);
    auVar4._4_4_ = 0;
    auVar4._0_4_ = *(uint *)(*(long *)(param_1 + 0x138) + 0x968);
    nvDbg_Printf("src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x14c,
                 "gisubscriptionDestruct_IMPL",1,
                 "NVRM: Client 0x%x unsubscribed from swizzid 0x%0x.\n",
                 *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48));
    auVar4._8_8_ = 0x3e586b;
    return auVar4;
  }
  auVar4 = kmigmgrClearDeviceProfilingInUse_IMPL(lVar1,uVar2);
  *(undefined1 *)(param_1 + 0x140) = 0;
  return auVar4;
}


// ===== 003e5907 gisubscriptionCtrlCmdExecPartitionsGetProfileCapacity_IMPL.cold =====

void gisubscriptionCtrlCmdExecPartitionsGetProfileCapacity_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003e5920 gisubscriptionCtrlCmdExecPartitionsGetProfileCapacity_IMPL =====

void gisubscriptionCtrlCmdExecPartitionsGetProfileCapacity_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xf0);
  if (lVar2 != 0) {
    kmigmgrComputeProfileGetCapacity_IMPL
              (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),**(undefined8 **)(param_1 + 0x138),
               *(undefined8 **)(param_1 + 0x138),
               *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
               *(undefined4 *)(*(long *)(*(long *)(lVar2 + 0x140) + 0x48) + 0x10),param_2);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 003e5990 gisubscriptionCtrlCmdGetUuid_IMPL =====

undefined8 gisubscriptionCtrlCmdGetUuid_IMPL(long param_1,long param_2)

{
  if (*(char *)(param_1 + 0x140) == '\0') {
    portMemCopy(param_2,0x10,*(long *)(param_1 + 0x138) + 0xa08,0x10);
    nvGetUuidString(param_2,1,param_2 + 0x10);
    *(undefined2 *)(param_2 + 0x11) = 0x4947;
    return 0;
  }
  nvCheckFailedNoLog(4,"!pGPUInstanceSubscription->bDeviceProfiling",
                     "src/kernel/gpu/mig_mgr/gpu_instance_subscription.c",0x4a2);
  return 0x56;
}


// ===== 003e5a20 _kmigmgrAllocKernelWatchdog.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _kmigmgrAllocKernelWatchdog_part_0(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long local_30;
  
  lVar3 = rmapiGetInterface(4);
  lVar1 = *(long *)(param_1 + 0x1c18);
  uVar4 = (ulong)*(uint *)(param_2 + 0xf0);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1158,"_kmigmgrAllocKernelWatchdog",1,
               "NVRM: Allocating KERNEL_WATCHDOG object for CI hClient 0x%x, hSubdevice 0x%x, gfxGpcCount(%d)\n"
               ,*(undefined4 *)(param_2 + 0xe8),uVar4,*(undefined4 *)(param_2 + 0x84));
  uVar2 = (**(code **)(lVar3 + 8))
                    (lVar3,*(undefined4 *)(param_2 + 0xe8),*(undefined4 *)(param_2 + 0xf0),
                     0x31425900,0x8f,0,uVar4 & 0xffffffff00000000);
  if (uVar2 == 0) {
    uVar2 = serverutilGetResourceRefWithType
                      (*(undefined4 *)(param_2 + 0xe8),0x31425900,0x7ace3d,&local_30);
    if (uVar2 == 0) {
      lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_30 + 8),__nvoc_class_def_KernelWatchdog);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pKernelWatchdog != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                            0x116e);
        uVar4 = 0x40;
      }
      else {
        uVar4 = (**(code **)(lVar1 + 0x168))(param_1,lVar1,lVar3);
        if ((int)uVar4 == 0) {
          *(long *)(param_2 + 0x108) = lVar3;
        }
        else {
          nvCheckOkFailedNoLog
                    (4,uVar4 & 0xffffffff,"krcWatchdogInit(pGpu, pKernelRc, pKernelWatchdog)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1170);
          uVar4 = uVar4 & 0xffffffff;
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar2,
                 "serverutilGetResourceRefWithType(pMIGComputeInstance->instanceHandles.hClient, KERNEL_WATCHDOG_OBJECT_ID, classId(KernelWatchdog), &pKernelWatchdogRef)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1166);
      uVar4 = (ulong)uVar2;
    }
    return uVar4;
  }
  nvAssertOkFailedNoLog
            (uVar2,
             "pRmApi->AllocWithHandle(pRmApi, pMIGComputeInstance->instanceHandles.hClient, pMIGComputeInstance->instanceHandles.hSubdevice, KERNEL_WATCHDOG_OBJECT_ID, KERNEL_WATCHDOG, NvP64_NULL, 0)"
             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x115d);
  return (ulong)uVar2;
}


// ===== 003e5be0 kmigmgrIncRefCount_IMPL =====

undefined8 kmigmgrIncRefCount_IMPL(long param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pShared != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x67);
    return 0x1f;
  }
  serverRefShare(g_resServ,param_1);
  iVar1 = serverGetShareRefCount(g_resServ,param_1);
  if (0 < iVar1) {
    return 0;
  }
  nvAssertFailedNoLog("refCount > 0","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x6d);
  return 0x40;
}


// ===== 003e5c80 kmigmgrDecRefCount_IMPL =====

undefined8 kmigmgrDecRefCount_IMPL(long param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pShared != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x7c);
    return 0x1f;
  }
  iVar1 = serverGetShareRefCount(g_resServ,param_1);
  serverFreeShare(g_resServ,param_1);
  if (1 < iVar1) {
    return 0;
  }
  nvAssertFailedNoLog("refCount > 0","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x83);
  return 0x40;
}


// ===== 003e5d20 kmigmgrMakeGIReference_IMPL =====

undefined1  [16] kmigmgrMakeGIReference_IMPL(ulong param_1)

{
  undefined1 auVar1 [16];
  
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1;
  return auVar1;
}


// ===== 003e5d30 kmigmgrMakeNoMIGReference_IMPL =====

undefined1  [16] kmigmgrMakeNoMIGReference_IMPL(void)

{
  return ZEXT816(0);
}


// ===== 003e5d40 kmigmgrIsInstanceAttributionIdValid_IMPL =====

undefined4 kmigmgrIsInstanceAttributionIdValid_IMPL(ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x87) {
    uVar1 = CONCAT31(param_1 / 0xf00,
                     (ushort)(param_1 - ((short)(param_1 / 0xf << 4) - param_1 / 0xf)) < 9);
  }
  return uVar1;
}


// ===== 003e5d70 kmigmgrIsMIGReferenceValid_IMPL =====

undefined8 kmigmgrIsMIGReferenceValid_IMPL(long *param_1)

{
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    return 0;
  }
  if (*(char *)(*param_1 + 0x988) == '\0') {
    nvAssertFailedNoLog("pRef->pKernelMIGGpuInstance->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbf);
    return 0;
  }
  if ((param_1[1] != 0) && (*(char *)(param_1[1] + 0xb8) == '\0')) {
    nvAssertFailedNoLog("pRef->pMIGComputeInstance->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc3);
    return 0;
  }
  return 1;
}


// ===== 003e5e10 kmigmgrAreMIGReferencesSame_IMPL =====

char kmigmgrAreMIGReferencesSame_IMPL(long *param_1,long *param_2)

{
  char cVar1;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    return false;
  }
  if (*(char *)(*param_1 + 0x988) == '\0') {
    nvAssertFailedNoLog("pRef->pKernelMIGGpuInstance->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbf);
    return false;
  }
  if ((param_1[1] != 0) && (*(char *)(param_1[1] + 0xb8) == '\0')) {
    nvAssertFailedNoLog("pRef->pMIGComputeInstance->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc3);
    return false;
  }
  cVar1 = kmigmgrIsMIGReferenceValid_IMPL(param_2);
  if (cVar1 != '\0') {
    if (*param_1 == *param_2) {
      if (param_1[1] != 0) {
        return param_2[1] == param_1[1];
      }
    }
    else {
      cVar1 = '\0';
    }
  }
  return cVar1;
}


// ===== 003e5ef0 kmigmgrCountEnginesInRange_IMPL =====

undefined8 kmigmgrCountEnginesInRange_IMPL(long param_1,ulong param_2,ulong param_3)

{
  undefined8 uVar1;
  undefined1 local_18 [16];
  
  if ((param_1 != 0) && (param_2 <= param_3)) {
    bitVectorClrAll_IMPL(local_18,0x54);
    bitVectorSetRange_IMPL(local_18,0x54,param_2,param_3);
    bitVectorAnd_IMPL(local_18,0x54,local_18,0x54,param_1,0x54);
    uVar1 = bitVectorCountSetBits_IMPL(local_18,0x54);
    return uVar1;
  }
  return 0;
}


// ===== 003e5f70 kmigmgrCountEnginesOfType_IMPL =====

undefined8 kmigmgrCountEnginesOfType_IMPL(long param_1,int param_2)

{
  undefined8 uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (param_2 - 1U < 0x53) {
      if (param_2 - 1U < 8) {
        param_2 = 1;
        iVar2 = 8;
      }
      else {
        if (param_2 - 9U < 0x14) {
          uVar1 = kmigmgrCountEnginesInRange_IMPL(param_1,9,0x1c);
          return uVar1;
        }
        if (param_2 - 0x1dU < 8) {
          param_2 = 0x1d;
          iVar2 = 0x24;
        }
        else if (param_2 - 0x25U < 4) {
          param_2 = 0x25;
          iVar2 = 0x28;
        }
        else if (param_2 - 0x36U < 8) {
          param_2 = 0x36;
          iVar2 = 0x3d;
        }
        else {
          iVar2 = param_2;
          if (param_2 - 0x3eU < 2) {
            param_2 = 0x3e;
            iVar2 = 0x3f;
          }
        }
      }
      uVar1 = kmigmgrCountEnginesInRange_IMPL(param_1,param_2,iVar2);
      return uVar1;
    }
  }
  return 0;
}


// ===== 003e6030 kmigmgrGetGRCERange_PF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] kmigmgrGetGRCERange_PF(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auVar3 [16];
  
  uVar1 = (**(code **)(param_1 + 0x408))();
  iVar2 = gpuGetRmEngineType_IMPL(uVar1);
  auVar3._8_4_ = iVar2 + -1;
  auVar3._0_8_ = 9;
  auVar3._12_4_ = 0;
  return auVar3;
}


// ===== 003e6060 kmigmgrGetGRCERange_VF =====

undefined1  [16] kmigmgrGetGRCERange_VF(void)

{
  long lVar1;
  undefined1 auVar2 [16];
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    auVar2._8_4_ = *(int *)(lVar1 + 0xa7c0) + -1;
    auVar2._0_8_ = 9;
    auVar2._12_4_ = 0;
    return auVar2;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x140);
  return ZEXT816(0);
}


// ===== 003e60b0 kmigmgrGetAsyncCERange_PF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kmigmgrGetAsyncCERange_PF(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_1 + 0x408))();
  uVar1 = gpuGetRmEngineType_IMPL(uVar1);
  return uVar1;
}


// ===== 003e60e0 kmigmgrGetAsyncCERange_VF =====

undefined4 kmigmgrGetAsyncCERange_VF(void)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    return *(undefined4 *)(lVar1 + 0xa7c0);
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16d);
  return 0;
}


// ===== 003e6130 kmigmgrGetAttributionIdFromMIGReference_IMPL =====

int kmigmgrGetAttributionIdFromMIGReference_IMPL(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0xe9;
  }
  if (*(char *)(param_1 + 0x988) == '\0') {
    nvAssertFailedNoLog("pRef->pKernelMIGGpuInstance->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbf);
  }
  else if (param_2 == 0) {
    if (*(uint *)(param_1 + 0x968) < 0xf) {
      return (*(uint *)(param_1 + 0x968) & 0xff) * 0xf + 8;
    }
  }
  else if (*(char *)(param_2 + 0xb8) == '\0') {
    nvAssertFailedNoLog("pRef->pMIGComputeInstance->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc3);
  }
  else if (*(uint *)(param_1 + 0x968) < 0xf) {
    iVar2 = (*(uint *)(param_1 + 0x968) & 0xff) * 0xf;
    iVar1 = iVar2 + *(uint *)(param_2 + 0xc0);
    if (7 < *(uint *)(param_2 + 0xc0)) {
      iVar1 = iVar2 + 8;
    }
    return iVar1;
  }
  return 0xe9;
}


// ===== 003e61f0 kmigmgrEngineTypeXlate_IMPL =====

undefined8 kmigmgrEngineTypeXlate_IMPL(long param_1,int param_2,long param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pSrc != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b4);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("pDst != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b5);
  }
  else {
    if (param_4 != (undefined4 *)0x0) {
      cVar1 = bitVectorTest_IMPL(param_1,0x54,param_2);
      if (cVar1 == '\0') {
        return 0x57;
      }
      bitVectorCopy_IMPL(local_48,0x54,param_1,0x54);
      bitVectorCopy_IMPL(local_38,0x54,param_3,0x54);
      while( true ) {
        iVar2 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
        uVar3 = bitVectorCountTrailingZeros_IMPL(local_38,0x54);
        cVar1 = bitVectorTestAllCleared_IMPL(local_48,0x54);
        if (cVar1 != '\0') break;
        cVar1 = bitVectorTestAllCleared_IMPL(local_38,0x54);
        if (cVar1 != '\0') break;
        if (iVar2 == param_2) goto LAB_003e6303;
        bitVectorClr_IMPL(local_48,0x54,iVar2);
        bitVectorClr_IMPL(local_38,0x54,uVar3);
      }
      nvAssertFailedNoLog("bFound","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1c6);
LAB_003e6303:
      *param_4 = uVar3;
      return 0;
    }
    nvAssertFailedNoLog("pDstEngineType != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b6
                       );
  }
  return 0x1f;
}


// ===== 003e63b0 kmigmgrEngBitVectorXlate_IMPL =====

int kmigmgrEngBitVectorXlate_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_3c;
  undefined1 local_38 [16];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pSrcRef != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e1);
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pSrc != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e2);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("pDstRef != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e3);
  }
  else {
    if (param_4 != 0) {
      bitVectorClrAll_IMPL(param_4,0x54);
      bitVectorCopy_IMPL(local_38,0x54,param_2,0x54);
      uVar2 = bitVectorCountTrailingZeros_IMPL(local_38,0x54);
      while( true ) {
        cVar1 = bitVectorTestAllCleared_IMPL(local_38,0x54);
        if (cVar1 != '\0') {
          return 0;
        }
        iVar3 = kmigmgrEngineTypeXlate_IMPL(param_1,uVar2,param_3,&local_3c);
        if (iVar3 != 0) break;
        bitVectorSet_IMPL(param_4,0x54,local_3c);
        bitVectorClr_IMPL(local_38,0x54,uVar2);
        uVar2 = bitVectorCountTrailingZeros_IMPL(local_38,0x54);
      }
      nvAssertOkFailedNoLog
                (iVar3,"kmigmgrEngineTypeXlate(pSrcRef, srcRmEngineType, pDstRef, &dstRmEngineType)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e9);
      return iVar3;
    }
    nvAssertFailedNoLog("pDst != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e4);
  }
  return 0x1f;
}


// ===== 003e6570 kmigmgrAllocateInstanceEngines_IMPL =====

undefined8
kmigmgrAllocateInstanceEngines_IMPL
          (undefined8 param_1,char param_2,ulong param_3,undefined8 param_4,int param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  
  bitVectorClrAll_IMPL(local_58,0x54);
  bitVectorAnd_IMPL(local_58,0x54,param_9,0x54,param_1,0x54);
  cVar1 = bitVectorTestEqual_IMPL(local_58,0x54,param_9,0x54);
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("bitVectorTestEqual(&engines, pAllocatableEngines)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x225);
    return 0x40;
  }
  iVar5 = 0;
  if (param_2 != '\0') {
    bitVectorClrAll_IMPL(local_58,0x54);
    bitVectorSetRange_IMPL(local_58,0x54,param_3,param_4);
    bitVectorAnd_IMPL(local_58,0x54,local_58,0x54,param_1,0x54);
    bitVectorCopy_IMPL(local_48,0x54,local_58,0x54);
    uVar2 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
    uVar4 = param_3;
    while ((cVar1 = bitVectorTestAllCleared_IMPL(local_48,0x54), cVar1 == '\0' && (iVar5 != param_5)
           )) {
      cVar1 = bitVectorTest_IMPL(param_9,0x54,uVar2);
      if ((cVar1 != '\0') && (cVar1 = bitVectorTest_IMPL(param_8,0x54,uVar2), cVar1 != '\0')) {
        iVar5 = iVar5 + 1;
        bitVectorSet_IMPL(param_6,0x54,uVar4 & 0xffffffff);
      }
      uVar4 = (ulong)((int)uVar4 + 1);
      bitVectorClr_IMPL(local_48,0x54,uVar2);
      uVar2 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
    }
  }
  bitVectorClrAll_IMPL(local_58,0x54);
  bitVectorSetRange_IMPL(local_58,0x54,param_3,param_4);
  bitVectorAnd_IMPL(local_58,0x54,local_58,0x54,param_1,0x54);
  bitVectorCopy_IMPL(local_48,0x54,local_58,0x54);
  uVar2 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  uVar3 = param_7;
  if (param_2 != '\0') {
    uVar3 = param_8;
  }
  while( true ) {
    cVar1 = bitVectorTestAllCleared_IMPL(local_48,0x54);
    if (cVar1 != '\0') {
      uVar3 = 0x1a;
      if (iVar5 == param_5) {
        uVar3 = 0;
      }
      return uVar3;
    }
    if (iVar5 == param_5) break;
    cVar1 = bitVectorTest_IMPL(param_9,0x54,uVar2);
    if (((cVar1 != '\0') && (cVar1 = bitVectorTest_IMPL(param_8,0x54,uVar2), cVar1 == '\0')) &&
       (cVar1 = bitVectorTest_IMPL(param_7,0x54,uVar2), cVar1 == '\0')) {
      iVar5 = iVar5 + 1;
      bitVectorSet_IMPL(uVar3,0x54,uVar2);
      bitVectorSet_IMPL(param_6,0x54,param_3 & 0xffffffff);
    }
    param_3 = (ulong)((int)param_3 + 1);
    bitVectorClr_IMPL(local_48,0x54,uVar2);
    uVar2 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  }
  return 0;
}


// ===== 003e68a0 kmigmgrGetLocalEngineMask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrGetLocalEngineMask_IMPL(long param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  
  bitVectorClrAll_IMPL(param_3,0x54);
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x469) == '\0') {
      return;
    }
  }
  else {
    iVar2 = kmigmgrCountEnginesInRange_IMPL(param_2,1,8);
    if (iVar2 == 0) {
      cVar1 = *(char *)(param_1 + 0x469);
    }
    else {
      bitVectorSetRange_IMPL(param_3,0x54,1,iVar2);
      cVar1 = *(char *)(param_1 + 0x469);
    }
    if (cVar1 == '\0') {
      iVar2 = kmigmgrCountEnginesInRange_IMPL(param_2,9,0x1c);
      if (iVar2 != 0) {
        bitVectorSetRange_IMPL(param_3,0x54,9,iVar2 + 8);
      }
      goto LAB_003e696b;
    }
  }
  lVar5 = *(long *)(param_1 + 0x1bc0);
  lVar4 = (**(code **)(lVar5 + 0x168))(param_1,lVar5);
  uVar3 = kmigmgrCountEnginesInRange_IMPL(param_2,lVar4);
  if (uVar3 != 0) {
    bitVectorSetRange_IMPL(param_3,0x54,lVar4,((ulong)uVar3 - 1) + lVar4);
  }
  lVar5 = (**(code **)(lVar5 + 0x170))(param_1,lVar5);
  uVar3 = kmigmgrCountEnginesInRange_IMPL(param_2,lVar5);
  if (uVar3 != 0) {
    bitVectorSetRange_IMPL(param_3,0x54,lVar5,((ulong)uVar3 - 1) + lVar5);
  }
  if (param_2 == 0) {
    return;
  }
LAB_003e696b:
  iVar2 = kmigmgrCountEnginesInRange_IMPL(param_2,0x1d,0x24);
  if (iVar2 != 0) {
    bitVectorSetRange_IMPL(param_3,0x54,0x1d,iVar2 + 0x1c);
  }
  iVar2 = kmigmgrCountEnginesInRange_IMPL(param_2,0x25,0x28);
  if (iVar2 != 0) {
    bitVectorSetRange_IMPL(param_3,0x54,0x25,iVar2 + 0x24);
  }
  iVar2 = kmigmgrCountEnginesInRange_IMPL(param_2,0x36,0x3d);
  if (iVar2 != 0) {
    bitVectorSetRange_IMPL(param_3,0x54,0x36,iVar2 + 0x35);
  }
  iVar2 = kmigmgrCountEnginesInRange_IMPL(param_2,0x3e,0x3f);
  if (iVar2 == 0) {
    return;
  }
  bitVectorSetRange_IMPL(param_3,0x54,0x3e,iVar2 + 0x3d);
  return;
}


// ===== 003e6b30 _kmigmgrAllocThirdPartyP2PObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kmigmgrAllocThirdPartyP2PObject(long param_1,long param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int local_30;
  undefined4 local_2c [3];
  
  puVar2 = (undefined8 *)rmapiGetInterface(4);
  local_2c[0] = 0;
  portMemSet(&local_30,0,4);
  local_30 = 2 - (uint)(*(char *)(param_1 + 0x454) == '\0');
  iVar1 = (*(code *)*puVar2)(puVar2,*(undefined4 *)(param_2 + 0x9c0),
                             *(undefined4 *)(param_2 + 0x9c8),local_2c,0x503c,&local_30,4);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2d8,
                 "_kmigmgrAllocThirdPartyP2PObject",3,
                 "NVRM: Error creating internal ThirdPartyP2P object: 0x%x\n",iVar1);
    local_2c[0] = 0;
  }
  *(undefined4 *)(param_2 + 0x9d0) = local_2c[0];
  return 0;
}


// ===== 003e6c00 kmigmgrAllocGPUInstanceHandles_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int kmigmgrAllocGPUInstanceHandles_IMPL(undefined8 param_1,undefined4 param_2,long param_3)

{
  int iVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [8];
  undefined4 local_40;
  
  puVar2 = (undefined8 *)rmapiGetInterface(4);
  local_58 = 0;
  iVar1 = rmapiutilAllocClientAndDeviceHandles(puVar2,param_1,&local_54,&local_50,&local_4c);
  if (iVar1 == 0) {
    *(ulong *)(param_3 + 0x9c0) = CONCAT44(local_50,local_54);
    *(undefined4 *)(param_3 + 0x9c8) = local_4c;
    portMemSet(local_48,0,0x10);
    local_40 = param_2;
    iVar1 = (*(code *)*puVar2)(puVar2,local_54,local_4c,&local_58,0xc637,local_48);
    if (iVar1 == 0) {
      *(undefined4 *)(param_3 + 0x9cc) = local_58;
      _kmigmgrAllocThirdPartyP2PObject(param_1,param_3,0x10,0x3e6c81);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,
                 "pRmApi->Alloc(pRmApi, hClient, hSubdevice, &hSubscription, AMPERE_SMC_PARTITION_REF, &params, sizeof(params))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2fe);
      if (*(int *)(param_3 + 0x9c0) != 0) {
        lVar3 = rmapiGetInterface(4);
        (**(code **)(lVar3 + 0x18))
                  (lVar3,*(undefined4 *)(param_3 + 0x9c0),*(undefined4 *)(param_3 + 0x9c0),
                   *(code **)(lVar3 + 0x18));
        *(undefined8 *)(param_3 + 0x9c0) = 0;
        *(undefined8 *)(param_3 + 0x9c8) = 0;
        *(undefined4 *)(param_3 + 0x9d0) = 0;
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,
               "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClient, &hDevice, &hSubdevice)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2f5);
  }
  return iVar1;
}


// ===== 003e6d70 kmigmgrIsGPUInstanceReadyToBeDestroyed_IMPL =====

undefined8 kmigmgrIsGPUInstanceReadyToBeDestroyed_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (*(long *)(param_2 + 0x978) != 0) {
    iVar3 = (3 - (uint)(*(int *)(param_2 + 0x9c0) == 0)) -
            (uint)(*(char *)(param_2 + 0x989) == '\0');
    iVar1 = serverGetShareRefCount(g_resServ,*(long *)(param_2 + 0x978));
    uVar2 = 0;
    if (iVar1 <= iVar3) {
      if (iVar3 != iVar1) {
        nvAssertFailedNoLog("actualRefCount == targetRefCount",
                            "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x350);
      }
      uVar2 = 1;
    }
    return uVar2;
  }
  return 1;
}


// ===== 003e6e00 kmigmgrDestruct_IMPL =====

void kmigmgrDestruct_IMPL(long param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*(long *)(param_1 + 0x278) != 0) {
    portMemFree(*(undefined8 *)(*(long *)(param_1 + 0x278) + 8));
    *(undefined8 *)(*(long *)(param_1 + 0x278) + 8) = 0;
    portMemFree(*(undefined8 *)(*(long *)(param_1 + 0x278) + 0x20));
    *(undefined8 *)(*(long *)(param_1 + 0x278) + 0x20) = 0;
    portMemFree(*(undefined8 *)(*(long *)(param_1 + 0x278) + 0x28));
    *(undefined8 *)(*(long *)(param_1 + 0x278) + 0x28) = 0;
    portMemFree(*(undefined8 *)(*(long *)(param_1 + 0x278) + 0x30));
    *(undefined8 *)(*(long *)(param_1 + 0x278) + 0x30) = 0;
    portMemFree(*(undefined8 *)(param_1 + 0x278));
    *(undefined8 *)(param_1 + 0x278) = 0;
  }
  pcVar4 = (char *)(param_1 + 0x418);
  do {
    if (pcVar4[0x7f0] != '\0') {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x392,"kmigmgrDestruct_IMPL",4,
                   "NVRM: Deleting valid GPU instance with swizzId - %d. Should have been deleted before shutdown!\n"
                   ,*(undefined4 *)(pcVar4 + 2000));
    }
    pcVar3 = pcVar4;
    iVar1 = 0;
    do {
      while (*pcVar3 != '\0') {
        iVar2 = iVar1 + 1;
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x3a0,"kmigmgrDestruct_IMPL",4,
                     "NVRM: Deleting valid compute instance - %d. Should have been deleted before shutdown!\n"
                     ,iVar1);
        pcVar3 = pcVar3 + 0x110;
        iVar1 = iVar2;
        if (iVar2 == 8) goto LAB_003e6f2e;
      }
      iVar1 = iVar1 + 1;
      pcVar3 = pcVar3 + 0x110;
    } while (iVar1 != 8);
LAB_003e6f2e:
    pcVar4 = pcVar4 + 0xa18;
    if (pcVar4 == (char *)(param_1 + 0x54d8)) {
      return;
    }
  } while( true );
}


// ===== 003e6f80 kmigmgrStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrStateInitLocked_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  int local_1c;
  
  cVar1 = (**(code **)(param_2 + 0x1d8))();
  if (cVar1 != '\0') {
    *(undefined1 *)(param_2 + 0x5340) = 1;
  }
  if (*(char *)(param_1 + 0x467) != '\0') {
    if (*(char *)(param_1 + 0x46d) != '\0') {
      iVar2 = osReadRegistryDword(param_1,"RMSetMIGAutoOnlineMode",&local_1c);
      if ((iVar2 == 0) && (local_1c == 1)) {
        *(undefined1 *)(param_2 + 0x5369) = 1;
      }
    }
    uVar3 = gpuGetKernelFifoShared_IMPL(param_1);
    iVar2 = kfifoAddSchedulingHandler_IMPL
                      (param_1,uVar3,_kmigmgrHandlePostSchedulingEnableCallback,0,
                       _kmigmgrHandlePreSchedulingDisableCallback,0);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "kfifoAddSchedulingHandler(pGpu, GPU_GET_KERNEL_FIFO(pGpu), _kmigmgrHandlePostSchedulingEnableCallback, NULL, _kmigmgrHandlePreSchedulingDisableCallback, NULL)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x4b6);
    }
  }
  return 0;
}


// ===== 003e7040 kmigmgrStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrStateUnload_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  
  (**(code **)(param_2 + 0x188))();
  if (*(char *)(param_1 + 0x467) != '\0') {
    uVar1 = gpuGetKernelFifoShared_IMPL(param_1);
    kfifoRemoveSchedulingHandler_IMPL
              (param_1,uVar1,_kmigmgrHandlePostSchedulingEnableCallback,0,
               _kmigmgrHandlePreSchedulingDisableCallback,0);
  }
  return 0;
}


// ===== 003e70a0 kmigmgrInitRegistryOverrides_IMPL =====

void kmigmgrInitRegistryOverrides_IMPL(long param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  int local_1c;
  
  iVar2 = osGetNvGlobalRegistryDword(param_1,"RmMIGBootConfigurationFeatureFlags",&local_1c);
  if (iVar2 == 0) {
    *(undefined1 *)(param_2 + 0x536c) = 1;
    bVar1 = (byte)local_1c & 1;
  }
  else {
    iVar2 = osReadRegistryDword(param_1,"RmMIGBootConfigurationFeatureFlags",&local_1c);
    if (iVar2 == 0) {
      bVar1 = (byte)local_1c & 1;
    }
    else {
      local_1c = 0;
      bVar1 = 0;
    }
  }
  *(byte *)(param_2 + 0x536a) = bVar1;
  *(byte *)(param_2 + 0x536b) = bVar1;
  *(undefined1 *)(param_2 + 0x5380) = *(undefined1 *)(param_1 + 0x46a);
  iVar2 = osReadRegistryDword(param_1,"RmEnableMIGGfx",&local_1c);
  if (iVar2 == 0) {
    if (local_1c == 1) {
      *(undefined1 *)(param_2 + 0x5380) = 1;
      return;
    }
    if (local_1c == 0) {
      *(undefined1 *)(param_2 + 0x5380) = 0;
    }
  }
  return;
}


// ===== 003e7170 kmigmgrGetMIGGpuInstanceSlot_IMPL =====

long kmigmgrGetMIGGpuInstanceSlot_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < 8) {
    return param_2 + 0x280 + (ulong)param_3 * 0xa18;
  }
  nvAssertFailedNoLog("i < NV_ARRAY_ELEMENTS(pKernelMIGManager->kernelMIGGpuInstance)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x50d);
  return 0;
}


// ===== 003e71b0 kmigmgrIsMIGSupported_IMPL =====

undefined1 kmigmgrIsMIGSupported_IMPL(long param_1)

{
  return *(undefined1 *)(param_1 + 0x467);
}


// ===== 003e71c0 kmigmgrIsMIGEnabled_IMPL =====

bool kmigmgrIsMIGEnabled_IMPL(long param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x467) != '\0') {
    bVar1 = *(char *)(param_2 + 0x5340) != '\0';
  }
  return bVar1;
}


// ===== 003e71e0 kmigmgrIsMIGGpuInstancingEnabled_IMPL =====

bool kmigmgrIsMIGGpuInstancingEnabled_IMPL(long param_1,long param_2)

{
  bool bVar1;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) {
    bVar1 = false;
    if ((*(char *)(param_1 + 0x467) != '\0') &&
       (bVar1 = false, *(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) != '\0')) {
      bVar1 = *(long *)(param_2 + 0x5348) != 0;
    }
    return bVar1;
  }
  return false;
}


// ===== 003e7230 kmigmgrIsMIGMemPartitioningEnabled_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrIsMIGMemPartitioningEnabled_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  int iVar4;
  
  if ((param_1 != 0) && (lVar1 = *(long *)(param_1 + 0x1bc0), lVar1 != 0)) {
    if (*(char *)(param_1 + 0x467) == '\0') {
      return 0;
    }
    if (*(char *)(lVar1 + 0x5340) == '\0') {
      return 0;
    }
    if (*(long *)(lVar1 + 0x5348) != 0) {
      uVar3 = *(ulong *)(param_2 + 0x5348);
      if (uVar3 == 0) {
        return 0;
      }
      iVar4 = 0;
      while( true ) {
        for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
          iVar4 = iVar4 + 1;
        }
        uVar2 = (**(code **)(param_2 + 0x228))(param_1,param_2,iVar4);
        if ((char)uVar2 != '\0') break;
        uVar3 = uVar3 >> 1;
        if (uVar3 == 0) {
          return uVar2;
        }
        iVar4 = iVar4 + 1;
      }
      return 1;
    }
  }
  return 0;
}


// ===== 003e7310 kmigmgrIsMIGNvlinkP2PSupported_IMPL =====

undefined8 kmigmgrIsMIGNvlinkP2PSupported_IMPL(long param_1)

{
  long lVar1;
  
  if (((param_1 != 0) && (lVar1 = *(long *)(param_1 + 0x1bc0), lVar1 != 0)) &&
     (*(char *)(param_1 + 0x467) != '\0')) {
    return CONCAT71((int7)((ulong)lVar1 >> 8),*(char *)(lVar1 + 0x5340) == '\0');
  }
  return 1;
}


// ===== 003e7350 kmigmgrGetStaticInfo_IMPL =====

char * kmigmgrGetStaticInfo_IMPL(undefined8 param_1,long param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  pcVar2 = pcVar1;
  if (pcVar1 != (char *)0x0) {
    pcVar2 = (char *)0x0;
    if (*pcVar1 != '\0') {
      pcVar2 = pcVar1 + 8;
    }
  }
  return pcVar2;
}


// ===== 003e7380 kmigmgrLoadStaticInfo_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrLoadStaticInfo_VF(long param_1,long param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  int local_3c [3];
  
  pcVar2 = *(char **)(param_2 + 0x278);
  lVar6 = gpuGetStaticInfo();
  if (pcVar2 == (char *)0x0) {
    nvAssertFailedNoLog("pPrivate != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x586);
    return 0x40;
  }
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x587);
    return 0x40;
  }
  if (*pcVar2 == '\0') {
    lVar7 = portMemAllocNonPaged(0x1958);
    *(long *)(pcVar2 + 8) = lVar7;
    if (lVar7 == 0) {
      nvCheckFailedNoLog(4,"pPrivate->staticInfo.pProfiles != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x58d);
    }
    else {
      portMemSet(lVar7,0,0x1958);
      lVar7 = *(long *)(pcVar2 + 8);
      *(undefined4 *)(lVar7 + 8) = 0;
      *(uint *)(lVar7 + 8) = (uint)(*(int *)(lVar6 + 0xa7e8) != 0) << 5;
      *(undefined4 *)(lVar7 + 0xc) = *(undefined4 *)(lVar6 + 0xa7d4);
      *(undefined4 *)(lVar7 + 0x14) = *(undefined4 *)(lVar6 + 0xa7e0);
      *(undefined4 *)(lVar7 + 0x18) = *(undefined4 *)(lVar6 + 0xa7e4);
      *(undefined4 *)(lVar7 + 0x1c) = *(undefined4 *)(lVar6 + 0xa7e8);
      *(undefined4 *)(lVar7 + 0x20) = *(undefined4 *)(lVar6 + 0xa7d8);
      *(undefined4 *)(lVar7 + 0x24) = *(undefined4 *)(lVar6 + 0xa87c);
      *(undefined4 *)(lVar7 + 0x28) = *(undefined4 *)(lVar6 + 0xa7dc);
      *(undefined4 *)(lVar7 + 0x2c) = *(undefined4 *)(lVar6 + 0xa870);
      *(undefined4 *)(lVar7 + 0x30) = *(undefined4 *)(lVar6 + 0xa86c);
      *(undefined4 *)(lVar7 + 0x34) = *(undefined4 *)(lVar6 + 0xa874);
      *(undefined4 *)(lVar7 + 0x38) = *(undefined4 *)(lVar6 + 0xa880);
      *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar6 + 0xa8a8);
      *(undefined8 *)(lVar7 + 0x48) = *(undefined8 *)(lVar6 + 0xa8b0);
      **(undefined4 **)(pcVar2 + 8) = 1;
      bitVectorClrAll_IMPL(pcVar2 + 0x10,0x54);
      lVar7 = gpuGetKernelFifoShared_IMPL(param_1);
      iVar3 = kfifoGetNumEschedDrivenEngines_IMPL(lVar7);
      iVar4 = gpuUpdateEngineTable_IMPL(param_1);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,"gpuUpdateEngineTable(pGpu)","src/kernel/gpu/mig_mgr/kernel_mig_manager.c")
        ;
      }
      if (iVar3 != 0) {
        iVar4 = 0;
        do {
          while( true ) {
            iVar5 = (**(code **)(lVar7 + 0x218))(param_1,lVar7,0xf,iVar4,2,local_3c);
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, engine, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x5bc);
              return iVar5;
            }
            if (local_3c[0] - 1U < 0x53) break;
            iVar4 = iVar4 + 1;
            nvAssertFailedNoLog(&DAT_00d5ccbb,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x5c4);
            if (iVar3 == iVar4) goto LAB_003e75a4;
          }
          if ((*(char *)(param_1 + 0x467) != '\0') &&
             ((local_3c[0] - 0x36U < 10 || (local_3c[0] - 1U < 0x28)))) {
            bitVectorSet_IMPL(pcVar2 + 0x10,0x54);
          }
          iVar4 = iVar4 + 1;
        } while (iVar3 != iVar4);
      }
LAB_003e75a4:
      lVar7 = portMemAllocNonPaged(0xc4);
      *(long *)(pcVar2 + 0x28) = lVar7;
      if (lVar7 != 0) {
        portMemSet(lVar7,0,0xc4);
        uVar9 = *(uint *)(lVar6 + 0x1e1d4);
        if (8 < uVar9) {
          nvAssertFailedNoLog("pVSI->ciProfiles.profileCount <= NV_ARRAY_ELEMENTS(pPrivate->staticInfo.pCIProfiles->profiles)"
                              ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x5da);
          uVar9 = *(uint *)(lVar6 + 0x1e1d4);
        }
        uVar11 = 0;
        if (uVar9 != 0) {
          puVar10 = (undefined1 *)(lVar6 + 0x1e1d8);
          uVar9 = 0;
          uVar11 = 0;
          do {
            if (*(uint *)(puVar10 + 0x10) <= *(uint *)(lVar6 + 0xa87c)) {
              uVar8 = (ulong)uVar11;
              uVar11 = uVar11 + 1;
              lVar7 = *(long *)(pcVar2 + 0x28) + uVar8 * 0x18;
              *(undefined4 *)(lVar7 + 8) = *(undefined4 *)(puVar10 + 4);
              *(undefined1 *)(lVar7 + 4) = *puVar10;
              uVar1 = *(undefined4 *)(puVar10 + 8);
              *(undefined4 *)(lVar7 + 0xc) = uVar1;
              *(undefined4 *)(lVar7 + 0x18) = uVar1;
              *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(puVar10 + 0xc);
              *(undefined4 *)(lVar7 + 0x14) = *(undefined4 *)(puVar10 + 0x10);
            }
            uVar9 = uVar9 + 1;
            puVar10 = puVar10 + 0x14;
          } while (uVar9 < *(uint *)(lVar6 + 0x1e1d4));
        }
        **(uint **)(pcVar2 + 0x28) = uVar11;
        pcVar2[0x20] = '\0';
        pcVar2[0x21] = '\0';
        pcVar2[0x22] = '\0';
        pcVar2[0x23] = '\0';
        pcVar2[0x24] = '\0';
        pcVar2[0x25] = '\0';
        pcVar2[0x26] = '\0';
        pcVar2[0x27] = '\0';
        pcVar2[0x30] = '\0';
        pcVar2[0x31] = '\0';
        pcVar2[0x32] = '\0';
        pcVar2[0x33] = '\0';
        pcVar2[0x34] = '\0';
        pcVar2[0x35] = '\0';
        pcVar2[0x36] = '\0';
        pcVar2[0x37] = '\0';
        *pcVar2 = '\x01';
        (**(code **)(param_2 + 0x180))(param_1);
        goto LAB_003e73c6;
      }
      nvCheckFailedNoLog(4,"pPrivate->staticInfo.pCIProfiles != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x5d1);
    }
    portMemFree(*(undefined8 *)(pcVar2 + 8));
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    pcVar2[0xc] = '\0';
    pcVar2[0xd] = '\0';
    pcVar2[0xe] = '\0';
    pcVar2[0xf] = '\0';
    portMemFree(*(undefined8 *)(pcVar2 + 0x20));
    pcVar2[0x20] = '\0';
    pcVar2[0x21] = '\0';
    pcVar2[0x22] = '\0';
    pcVar2[0x23] = '\0';
    pcVar2[0x24] = '\0';
    pcVar2[0x25] = '\0';
    pcVar2[0x26] = '\0';
    pcVar2[0x27] = '\0';
    portMemFree(*(undefined8 *)(pcVar2 + 0x28));
    pcVar2[0x28] = '\0';
    pcVar2[0x29] = '\0';
    pcVar2[0x2a] = '\0';
    pcVar2[0x2b] = '\0';
    pcVar2[0x2c] = '\0';
    pcVar2[0x2d] = '\0';
    pcVar2[0x2e] = '\0';
    pcVar2[0x2f] = '\0';
    iVar3 = 0x51;
  }
  else {
LAB_003e73c6:
    iVar3 = 0;
  }
  return iVar3;
}


// ===== 003e77f0 kmigmgrClearStaticInfo_VF =====

void kmigmgrClearStaticInfo_VF(void)

{
  return;
}


// ===== 003e7800 kmigmgrSaveToPersistenceFromVgpuStaticInfo_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int kmigmgrSaveToPersistenceFromVgpuStaticInfo_VF(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  undefined4 *puVar13;
  long local_60;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  
  lVar5 = gpuGetStaticInfo();
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x6dc);
    return 0x1f;
  }
  cVar3 = gpumgrGetSystemMIGInstanceTopo_IMPL(*(undefined8 *)(param_1 + 0x878),&local_60);
  lVar2 = local_60;
  if (cVar3 == '\0') {
    return 0;
  }
  iVar10 = 0;
  pcVar6 = (char *)(local_60 + 0x18);
  if (*(char *)(local_60 + 0x10) != '\0') {
    return 0;
  }
  do {
    if (*pcVar6 != '\0') {
      return 0;
    }
    iVar10 = iVar10 + 1;
    pcVar6 = pcVar6 + 0x390;
  } while (iVar10 != 8);
  *(undefined1 *)(local_60 + 0x18) = 1;
  *(undefined4 *)(local_60 + 0x58) = 0;
  *(undefined4 *)(local_60 + 0x40) = 0;
  gpumgrCacheCreateGpuInstance_IMPL(param_1,0);
  if (*(int *)(lVar5 + 0xa7e8) != 0) {
    *(uint *)(lVar2 + 0x40) = *(uint *)(lVar2 + 0x40) | 0x20;
  }
  bitVectorClrAll_IMPL(local_58,0x54);
  if (*(int *)(lVar5 + 0xa7d4) == 0) {
    if (*(char *)(param_1 + 0x469) != '\0') goto LAB_003e7c00;
LAB_003e78f9:
    if (*(int *)(lVar5 + 0xa7dc) != 0) {
      bitVectorSetRange_IMPL(local_58,0x54,9,*(int *)(lVar5 + 0xa7dc) + 8);
    }
  }
  else {
    bitVectorSetRange_IMPL(local_58,0x54,1,*(int *)(lVar5 + 0xa7d4));
    if (*(char *)(param_1 + 0x469) == '\0') goto LAB_003e78f9;
LAB_003e7c00:
    if (*(int *)(lVar5 + 0xa7e8) != 0) {
      lVar9 = (**(code **)(param_2 + 0x168))(param_1);
      if (*(uint *)(lVar5 + 0xa7d4) != 0) {
        bitVectorSetRange_IMPL(local_58,0x54,lVar9,((ulong)*(uint *)(lVar5 + 0xa7d4) - 1) + lVar9);
      }
    }
    lVar9 = (**(code **)(param_2 + 0x170))(param_1);
    if (*(uint *)(lVar5 + 0xa7dc) != 0) {
      bitVectorSetRange_IMPL(local_58,0x54,lVar9,((ulong)*(uint *)(lVar5 + 0xa7dc) - 1) + lVar9);
      iVar10 = *(int *)(lVar5 + 0xa86c);
      goto joined_r0x003e7911;
    }
  }
  iVar10 = *(int *)(lVar5 + 0xa86c);
joined_r0x003e7911:
  if (iVar10 == 0) {
    iVar10 = *(int *)(lVar5 + 0xa870);
  }
  else {
    bitVectorSetRange_IMPL(local_58,0x54,0x1d,iVar10 + 0x1c);
    iVar10 = *(int *)(lVar5 + 0xa870);
  }
  if (iVar10 == 0) {
    iVar10 = *(int *)(lVar5 + 0xa874);
  }
  else {
    bitVectorSetRange_IMPL(local_58,0x54,0x25,iVar10 + 0x24);
    iVar10 = *(int *)(lVar5 + 0xa874);
  }
  if (iVar10 == 0) {
    iVar10 = *(int *)(lVar5 + 0xa880);
  }
  else {
    bitVectorSetRange_IMPL(local_58,0x54,0x36,iVar10 + 0x35);
    iVar10 = *(int *)(lVar5 + 0xa880);
  }
  if (iVar10 != 0) {
    bitVectorSetRange_IMPL(local_58,0x54,0x3e,iVar10 + 0x3d);
  }
  bitVectorToRaw_IMPL(local_58,0x54,lVar2 + 0x20,0x20);
  if (*(uint *)(lVar5 + 0xa7d4) != 0) {
    uVar7 = 0;
    uVar11 = 0;
    do {
      if (*(int *)(lVar5 + 0xa7ec + uVar7 * 4) != 0) {
        uVar11 = uVar11 | 1 << ((uint)uVar7 & 0x1f);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 != *(uint *)(lVar5 + 0xa7d4));
    uVar11 = uVar11 - (uVar11 >> 1 & 0x55555555);
    uVar11 = (uVar11 >> 2 & 0x33333333) + (uVar11 & 0x33333333);
    if (*(uint *)(lVar5 + 0x1f6d4) < ((uVar11 >> 4) + uVar11 & 0xf0f0f0f) * 0x1010101 >> 0x18) {
      nvAssertFailedNoLog("nvPopCount32(assignableGrMask) <= pVSI->execPartitionInfo.execPartCount",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x745);
      return 0x1a;
    }
  }
  *(undefined4 *)(lVar2 + 0x4c) = 0;
  *(undefined4 *)(lVar2 + 0x50) = *(undefined4 *)(lVar5 + 0xa7d8);
  *(uint *)(lVar2 + 0x44) = 0xffffffff >> (-(char)*(undefined4 *)(lVar5 + 0xa7e0) & 0x1fU);
  *(undefined4 *)(lVar2 + 0x48) = *(undefined4 *)(lVar5 + 0xa7e4);
  iVar10 = osRmCapRegisterSmcPartition
                     (*(undefined8 *)(param_1 + 0x4e8),lVar2 + 0x60,*(undefined4 *)(lVar2 + 0x58));
  if (iVar10 == 0) {
    if (*(int *)(lVar5 + 0x1f6d4) != 0) {
      lVar12 = 0;
      puVar13 = (undefined4 *)(lVar5 + 0x1f6f8);
      lVar9 = lVar2 + 0x70;
      do {
        uVar11 = *(uint *)(lVar5 + 0x25f00 + lVar12 * 4);
        if (7 < uVar11) {
          nvCheckFailedNoLog(4,"grIdx < RM_ENGINE_TYPE_GR_SIZE",
                             "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x757);
          return 0x40;
        }
        *(undefined1 *)(lVar9 + -8) = 1;
        *(undefined4 *)(lVar9 + 0x30) = puVar13[8];
        uVar1 = *(uint *)(lVar5 + 0x1f6d8 + lVar12 * 4);
        *(uint *)(lVar9 + 0x50) = uVar1;
        if (uVar1 != uVar11) {
          nvCheckFailedNoLog(3,"pComputeInstanceSave->id == grIdx",
                             "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x763);
        }
        bitVectorClrAll_IMPL(local_48,0x54);
        bitVectorSetRange_IMPL(local_48,0x54,uVar11 + 1,uVar11 + 1);
        if (*(char *)(param_1 + 0x469) == '\0') {
          if (puVar13[3] == 0) goto LAB_003e7af9;
          uVar7 = (ulong)(puVar13[3] + 8);
          lVar8 = 9;
LAB_003e7db7:
          bitVectorSetRange_IMPL(local_48,0x54,lVar8,uVar7);
          iVar4 = puVar13[5];
          if (iVar4 == 0) goto LAB_003e7b05;
LAB_003e7dd7:
          bitVectorSetRange_IMPL(local_48,0x54,0x1d,iVar4 + 0x1c);
          iVar4 = puVar13[4];
          if (iVar4 == 0) goto LAB_003e7b11;
LAB_003e7e17:
          bitVectorSetRange_IMPL(local_48,0x54,0x25,iVar4 + 0x24);
          iVar4 = puVar13[6];
          if (iVar4 == 0) goto LAB_003e7b1d;
LAB_003e7e57:
          bitVectorSetRange_IMPL(local_48,0x54,0x36,iVar4 + 0x35);
          iVar4 = puVar13[7];
        }
        else {
          if (puVar13[1] != 0) {
            bitVectorSetRange_IMPL(local_48,0x54,uVar11 + 9,uVar11 + 9);
          }
          lVar8 = (**(code **)(param_2 + 0x170))(param_1);
          if (puVar13[3] != 0) {
            uVar7 = ((ulong)(uint)puVar13[3] - 1) + lVar8;
            goto LAB_003e7db7;
          }
LAB_003e7af9:
          iVar4 = puVar13[5];
          if (iVar4 != 0) goto LAB_003e7dd7;
LAB_003e7b05:
          iVar4 = puVar13[4];
          if (iVar4 != 0) goto LAB_003e7e17;
LAB_003e7b11:
          iVar4 = puVar13[6];
          if (iVar4 != 0) goto LAB_003e7e57;
LAB_003e7b1d:
          iVar4 = puVar13[7];
        }
        if (iVar4 != 0) {
          bitVectorSetRange_IMPL(local_48,0x54,0x3e,iVar4 + 0x3d);
        }
        bitVectorToRaw_IMPL(local_48,0x54,lVar9,0x20);
        *(uint *)(lVar9 + 0x34) = 0xffffffff >> (-(char)*puVar13 & 0x1fU);
        *(undefined4 *)(lVar9 + 0x38) = puVar13[1];
        *(undefined4 *)(lVar9 + 0x48) = puVar13[0xb];
        *(undefined4 *)(lVar9 + 0x44) = puVar13[10];
        *(undefined4 *)(lVar9 + 0x4c) = puVar13[0xc];
        *(undefined4 *)(lVar9 + 0x40) = puVar13[2];
        *(undefined4 *)(lVar9 + 0x3c) = puVar13[9];
        iVar4 = osRmCapRegisterSmcExecutionPartition
                          (*(undefined8 *)(lVar2 + 0x60),lVar9 + 0x58,*(undefined4 *)(lVar9 + 0x50))
        ;
        if (iVar4 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar4,
                     "osRmCapRegisterSmcExecutionPartition(pGPUInstanceSave->pOsRmCaps, &(pComputeInstanceSave->pOsRmCaps), pComputeInstanceSave->id)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x7a6);
          return iVar4;
        }
        lVar12 = lVar12 + 1;
        puVar13 = puVar13 + 0xd;
        gpumgrCacheCreateComputeInstance_IMPL
                  (param_1,*(undefined4 *)(lVar2 + 0x58),*(undefined4 *)(lVar9 + 0x50));
        lVar9 = lVar9 + 0x68;
      } while ((uint)lVar12 < *(uint *)(lVar5 + 0x1f6d4));
    }
    *(undefined1 *)(local_60 + 0x10) = 1;
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar10,
               "osRmCapRegisterSmcPartition(pGpu->pOsRmCaps, &pGPUInstanceSave->pOsRmCaps, pGPUInstanceSave->swizzId)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x74c);
  }
  return iVar10;
}


// ===== 003e8070 kmigmgrSetStaticInfo_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrSetStaticInfo_VF(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  lVar3 = gpuGetStaticInfo();
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x7d1);
    return 0x57;
  }
  if (((*(long *)(param_1 + 0x1bc0) == 0) || (*(char *)(param_1 + 0x467) == '\0')) ||
     (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) == '\0')) {
    iVar2 = 0;
  }
  else if ((*(char **)(param_2 + 0x278) == (char *)0x0) || (**(char **)(param_2 + 0x278) == '\0')) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x7d7);
    iVar2 = 0x40;
  }
  else {
    iVar2 = (**(code **)(param_2 + 400))(param_1,param_2);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"kmigmgrSaveToPersistenceFromVgpuStaticInfo_HAL(pGpu, pKernelMIGManager)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x7f2);
    }
    iVar2 = (**(code **)(lVar1 + 0x3b0))(param_1,lVar1,&local_38);
    if (iVar2 == 0) {
      memmgrSetMIGPartitionableMemoryRange_IMPL(param_1,lVar1,local_38,local_30);
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar2,
               "memmgrDiscoverMIGPartitionableMemoryRange_HAL(pGpu, pMemoryManager, &memoryRange)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x7fc);
  }
  return iVar2;
}


// ===== 003e81f0 kmigmgrDisableWatchdog_IMPL =====

undefined8 kmigmgrDisableWatchdog_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  int local_34;
  int local_30;
  int local_2c;
  
  lVar2 = *(long *)(param_1 + 0x1c18);
  uVar1 = *(uint *)(lVar2 + 0x1a8);
  krcWatchdogGetReservationCounts_IMPL(lVar2,0,&local_34,&local_30,&local_2c);
  if ((local_34 == 0 && local_30 == 0) && local_2c == 0) {
    if ((uVar1 & 1) == 0) {
      uVar3 = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x5350) = 1;
      *(byte *)(param_2 + 0x5351) = (byte)(uVar1 >> 1) & 1 ^ 1;
      uVar3 = krcWatchdogShutdown_IMPL(param_1,lVar2,0);
    }
    return uVar3;
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x870,"kmigmgrDisableWatchdog_IMPL",4,
               "NVRM: Failed to disable watchdog with outstanding reservations - enable: %d disable: %d softDisable: %d.\n"
               ,local_34,local_30,local_2c);
  return 99;
}


// ===== 003e82d0 kmigmgrRestoreWatchdog_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrRestoreWatchdog_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_2 + 0x5350) != '\0') {
    lVar1 = *(long *)(param_1 + 0x1c18);
    if (*(char *)(param_2 + 0x5351) != '\0') {
      krcWatchdogEnable_IMPL(lVar1,0,0);
    }
    *(undefined2 *)(param_2 + 0x5350) = 0;
    uVar2 = (**(code **)(lVar1 + 0x168))(param_1,lVar1,0);
    return uVar2;
  }
  return 0;
}


// ===== 003e8350 kmigmgrIsSwizzIdInUse_IMPL =====

undefined8 kmigmgrIsSwizzIdInUse_IMPL(undefined8 param_1,long param_2,byte param_3)

{
  ulong uVar1;
  
  uVar1 = 1L << (param_3 & 0x3f);
  return CONCAT71((int7)(uVar1 >> 8),(*(ulong *)(param_2 + 0x5348) & uVar1) != 0);
}


// ===== 003e8370 kmigmgrGetSwizzIdInUseMask_IMPL =====

undefined8 kmigmgrGetSwizzIdInUseMask_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined8 *)(param_2 + 0x5348);
}


// ===== 003e8380 kmigmgrSetEnginesInUse_IMPL =====

undefined8 kmigmgrSetEnginesInUse_IMPL(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  undefined1 local_28 [16];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pEngines != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x905);
    return 0x1f;
  }
  param_2 = param_2 + 0x5358;
  bitVectorAnd_IMPL(local_28,0x54,param_3,0x54,param_2,0x54);
  cVar1 = bitVectorTestAllCleared_IMPL(local_28,0x54);
  if (cVar1 != '\0') {
    bitVectorOr_IMPL(param_2,0x54,param_2,0x54,param_3,0x54);
    return 0;
  }
  nvAssertFailedNoLog("bitVectorTestAllCleared(&tempEngines)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x909);
  return 99;
}


// ===== 003e8450 kmigmgrClearEnginesInUse_IMPL =====

undefined8 kmigmgrClearEnginesInUse_IMPL(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  undefined1 local_28 [16];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pEngines != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x91f);
    return 0x1f;
  }
  param_2 = param_2 + 0x5358;
  bitVectorAnd_IMPL(local_28,0x54,param_3,0x54,param_2,0x54);
  cVar1 = bitVectorTestEqual_IMPL(local_28,0x54,param_3,0x54);
  if (cVar1 != '\0') {
    bitVectorComplement_IMPL(local_28,0x54,param_3,0x54);
    bitVectorAnd_IMPL(param_2,0x54,param_2,0x54,local_28,0x54);
    return 0;
  }
  nvAssertFailedNoLog("bitVectorTestEqual(&tempEngines, pEngines)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x923);
  return 99;
}


// ===== 003e8540 kmigmgrIsEnginePartitionable_IMPL =====

uint kmigmgrIsEnginePartitionable_IMPL(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x467);
  if (*(byte *)(param_1 + 0x467) != 0) {
    uVar1 = CONCAT31((int3)(param_3 - 1U >> 8),param_3 - 1U < 0x28) |
            CONCAT31((int3)(param_3 - 0x36U >> 8),param_3 - 0x36U < 10);
  }
  return uVar1;
}


// ===== 003e8570 kmigmgrIsLocalEngineInInstance_IMPL =====

undefined8
kmigmgrIsLocalEngineInInstance_IMPL
          (long param_1,undefined8 param_2,int param_3,long param_4,long param_5)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((*(char *)(param_1 + 0x467) != '\0') && ((param_3 - 1U < 0x28 || (param_3 - 0x36U < 10)))) {
    lVar1 = param_5 + 0xa0;
    if (param_5 == 0) {
      lVar1 = param_4 + 0xa8;
    }
    uVar2 = bitVectorTest_IMPL(lVar1,0x54);
    return uVar2;
  }
  return 1;
}


// ===== 003e85c0 kmigmgrDeleteGPUInstanceRunlists_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmigmgrDeleteGPUInstanceRunlists_FWCLIENT(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  
  lVar2 = gpuGetKernelFifoShared_IMPL();
  cVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968));
  if ((cVar1 == '\0') || (cVar1 = ctxBufPoolIsSupported(param_1), cVar1 == '\0')) {
    if (*(long *)(param_3 + 0x9b0) != 0) {
      nvAssertFailedNoLog("pKernelMIGGpuInstance->runlistIdMask == 0",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xa58);
      return 0x40;
    }
  }
  else {
    uVar4 = *(ulong *)(param_3 + 0x9b0);
    if (uVar4 != 0) {
      lVar5 = 0;
      do {
        if ((uVar4 & 1) != 0) {
          lVar3 = 0;
          while( true ) {
            plVar6 = (long *)(*(long *)(*(long *)(lVar2 + 0x798) + lVar5 * 8) + lVar3);
            if (*plVar6 != 0) {
              memdescFree();
              memdescDestroy(*plVar6);
              *plVar6 = 0;
            }
            if (lVar3 != 0) break;
            lVar3 = 8;
          }
          *(ulong *)(param_3 + 0x9b0) = *(ulong *)(param_3 + 0x9b0) & ~(1L << ((byte)lVar5 & 0x3f));
          if (uVar4 >> 1 == 0) {
            return 0;
          }
        }
        uVar4 = uVar4 >> 1;
        lVar5 = lVar5 + 1;
      } while( true );
    }
  }
  return 0;
}


// ===== 003e8720 kmigmgrRestoreFromPersistence_PF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrRestoreFromPersistence_PF(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  uint *local_78;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  long local_50;
  undefined1 local_48 [8];
  undefined4 local_40;
  
  lVar4 = rmapiGetInterface(4);
  local_50 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  cVar3 = gpumgrGetSystemMIGInstanceTopo_IMPL(*(undefined8 *)(param_1 + 0x878),&local_50);
  if (cVar3 != '\0') {
    iVar8 = 0;
    pcVar5 = (char *)(local_50 + 0x18);
    while (*pcVar5 == '\0') {
      iVar8 = iVar8 + 1;
      pcVar5 = pcVar5 + 0x390;
      if (iVar8 == 8) {
        iVar8 = (**(code **)(param_2 + 0x268))(param_1,param_2);
        if (iVar8 == 0) {
          return 0;
        }
        nvCheckOkFailedNoLog
                  (4,iVar8,"kmigmgrRestoreFromBootConfig_HAL(pGpu, pKernelMIGManager)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xa9a);
        return iVar8;
      }
    }
    if (((*(long *)(param_1 + 0x1bc0) != 0) && (*(char *)(param_1 + 0x467) != '\0')) &&
       (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) != '\0')) {
      iVar8 = rmapiutilAllocClientAndDeviceHandles(lVar4,param_1,&local_60,&local_5c,&local_58);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClient, &hDevice, &hSubdevice)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xaaa);
        return iVar8;
      }
      puVar6 = (undefined4 *)portMemAllocNonPaged(0x50);
      if (puVar6 == (undefined4 *)0x0) {
        nvCheckFailedNoLog(4,"pPartImportParams != NULL",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xaae);
        iVar8 = 0x51;
        local_78 = (uint *)0x0;
      }
      else {
        lVar13 = 0;
        local_78 = (uint *)portMemAllocNonPaged(0x60);
        if (local_78 == (uint *)0x0) {
          nvCheckFailedNoLog(4,"pExecPartImportParams != NULL",
                             "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xab2);
          iVar8 = 0x51;
        }
        else {
          uVar11 = 0;
          do {
            lVar2 = local_50;
            lVar12 = uVar11 * 0x390 + local_50;
            if (*(char *)(lVar12 + 0x18) != '\0') {
              portMemSet(puVar6,0,0x50);
              *puVar6 = *(undefined4 *)(lVar12 + 0x58);
              portMemCopy(puVar6 + 6,0x38,lVar2 + 0x20 + lVar13,0x38);
              iVar8 = (**(code **)(lVar4 + 0x38))(lVar4,local_60,local_58,0x20800aa9,puVar6,0x50);
              if (iVar8 != 0) {
                uVar7 = 0xac3;
                pcVar5 = 
                "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_KMIGMGR_IMPORT_GPU_INSTANCE, pPartImportParams, sizeof(*pPartImportParams))"
                ;
LAB_003e8ba4:
                nvAssertOkFailedNoLog
                          (iVar8,pcVar5,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar7);
                break;
              }
              if (0xe < *(uint *)(lVar12 + 0x58)) {
LAB_003e89c5:
                nvAssertOkFailedNoLog
                          (0x1f,
                           "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, pGPUInstanceSave->swizzId, &pKernelMIGGpuInstance)"
                           ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xacc);
                iVar8 = 0x1f;
                break;
              }
              lVar9 = param_2 + 0x280;
              uVar10 = 0;
              while (((lVar9 == 0 || (*(char *)(lVar9 + 0x988) == '\0')) ||
                     (*(uint *)(lVar12 + 0x58) != *(uint *)(lVar9 + 0x968)))) {
                uVar10 = uVar10 + 1;
                lVar9 = lVar9 + 0xa18;
                if (uVar10 == 8) goto LAB_003e89c5;
              }
              lVar12 = lVar2 + 0x70 + lVar13;
              lVar9 = uVar11 * 0x390 + lVar2;
              *(undefined8 *)(param_2 + 0xc38 + (ulong)uVar10 * 0xa18) =
                   *(undefined8 *)(lVar9 + 0x60);
              do {
                if (*(char *)(lVar12 + -8) != '\0') {
                  portMemSet(local_48,0,0x10);
                  local_40 = *(undefined4 *)(lVar9 + 0x58);
                  iVar8 = (**(code **)(lVar4 + 0x10))
                                    (lVar4,local_60,local_58,&local_54,0xc637,local_48,0x10,0,0,
                                     lVar4 + 0xb8);
                  if (iVar8 != 0) {
                    uVar7 = 0xade;
                    pcVar5 = 
                    "pRmApi->AllocWithSecInfo(pRmApi, hClient, hSubdevice, &hSubscription, AMPERE_SMC_PARTITION_REF, &alloc, sizeof(alloc), RMAPI_ALLOC_FLAGS_NONE, NULL, &pRmApi->defaultSecInfo)"
                    ;
                    goto LAB_003e8ba4;
                  }
                  portMemSet(local_78,0,0x60);
                  uVar1 = *(uint *)(lVar12 + 0x50);
                  *(undefined1 *)(local_78 + 0x16) = 0;
                  *local_78 = uVar1;
                  portMemCopy(local_78 + 2,0x50,lVar12,0x50);
                  iVar8 = (**(code **)(lVar4 + 0x38))
                                    (lVar4,local_60,local_54,0xc6370106,local_78,0x60);
                  if (iVar8 != 0) {
                    uVar7 = 0xaf1;
                    pcVar5 = 
                    "pRmApi->Control(pRmApi, hClient, hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_IMPORT, pExecPartImportParams, sizeof(*pExecPartImportParams))"
                    ;
                    goto LAB_003e8ba4;
                  }
                  *(undefined8 *)
                   (param_2 + 0x430 + (ulong)*local_78 * 0x110 + (ulong)uVar10 * 0xa18) =
                       *(undefined8 *)(lVar12 + 0x58);
                  (**(code **)(lVar4 + 0x18))(lVar4,local_60,local_54);
                }
                lVar12 = lVar12 + 0x68;
              } while (lVar12 != lVar2 + 0x3b0 + lVar13);
            }
            uVar10 = (int)uVar11 + 1;
            uVar11 = (ulong)uVar10;
            lVar13 = lVar13 + 0x390;
            iVar8 = 0;
          } while (uVar10 != 8);
        }
      }
      rmapiutilFreeClientAndDeviceHandles(lVar4,&local_60,&local_5c,&local_58);
      portMemFree(puVar6);
      portMemFree(local_78);
      return iVar8;
    }
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xaa0,
                 "kmigmgrRestoreFromPersistence_PF",3,
                 "NVRM: Skipping reinitialization of persistent MIG instances due to MIG disablement!\n"
                );
    gpumgrUnregisterRmCapsForMIGGI_IMPL(*(undefined8 *)(param_1 + 0x878));
  }
  return 0;
}


// ===== 003e8c80 kmigmgrInitGPUInstanceInfo_IMPL =====

void kmigmgrInitGPUInstanceInfo_IMPL(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  bitVectorClrAll_IMPL(param_3 + 0x18,0x54);
  bitVectorClrAll_IMPL(param_3 + 0x1a,0x54);
  pcVar1 = (char *)(param_3 + 0x33);
  do {
    if (*pcVar1 != '\0') {
      nvAssertFailedNoLog("!pKernelMIGGpuInstance->MIGComputeInstance[i].bValid",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xba7);
    }
    pcVar1[0x18] = '\0';
    pcVar1[0x19] = '\0';
    pcVar1[0x1a] = '\0';
    pcVar1[0x1b] = '\0';
    pcVar1[0x1c] = '\0';
    pcVar1[0x1d] = '\0';
    pcVar1[0x1e] = '\0';
    pcVar1[0x1f] = '\0';
    pcVar2 = pcVar1 + 0x110;
    pcVar1[8] = -1;
    pcVar1[9] = -1;
    pcVar1[10] = -1;
    pcVar1[0xb] = -1;
    pcVar1 = pcVar2;
  } while (pcVar2 != (char *)(param_3 + 0x143));
  *(undefined4 *)(param_3 + 0x12d) = 0xffffffff;
  *(undefined4 *)(param_3 + 0x12e) = 0;
  param_3[0x12f] = 0;
  param_3[0x130] = 0;
  *(undefined1 *)(param_3 + 0x131) = 0;
  param_3[0x132] = 1;
  param_3[0x133] = 0;
  param_3[0x135] = 0;
  param_3[0x137] = 0;
  *param_3 = 0;
  portMemSet(param_3 + 1,0,0xb8);
  return;
}


// ===== 003e8de0 kmigmgrConstructEngine_IMPL =====

undefined8 kmigmgrConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined1 *)(param_2 + 0x5340) = 0;
  *(undefined8 *)(param_2 + 0x5348) = 0;
  lVar1 = portMemAllocNonPaged(0x38);
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x38);
    *(long *)(param_2 + 0x278) = lVar1;
    lVar1 = param_2 + 0x280;
    do {
      lVar2 = lVar1 + 0xa18;
      kmigmgrInitGPUInstanceInfo_IMPL(param_1,param_2,lVar1);
      lVar1 = lVar2;
    } while (lVar2 != param_2 + 0x5340);
    kmigmgrInitRegistryOverrides_IMPL(param_1,param_2);
    return 0;
  }
  nvCheckFailedNoLog(4,"pPrivate != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x363);
  return 0x51;
}


// ===== 003e8ec0 kmigmgrIsDevinitMIGBitSet_VF =====

bool kmigmgrIsDevinitMIGBitSet_VF(void)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    return *(int *)(lVar1 + 0xa7d0) != -1;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbc6);
  return false;
}


// ===== 003e8f00 kmigmgrSetDeviceProfilingInUse_IMPL =====

undefined8 kmigmgrSetDeviceProfilingInUse_IMPL(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x5368) == '\0') {
    *(undefined1 *)(param_2 + 0x5368) = 1;
    return 0;
  }
  nvAssertFailedNoLog("!kmigmgrIsDeviceProfilingInUse(pGpu, pKernelMIGManager)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbd5);
  return 99;
}


// ===== 003e8f50 kmigmgrClearDeviceProfilingInUse_IMPL =====

void kmigmgrClearDeviceProfilingInUse_IMPL(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x5368) = 0;
  return;
}


// ===== 003e8f60 kmigmgrIsDeviceProfilingInUse_IMPL =====

undefined1 kmigmgrIsDeviceProfilingInUse_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 *)(param_2 + 0x5368);
}


// ===== 003e8f6c kmigmgrIsDeviceUsingDeviceProfiling_IMPL.cold =====

void kmigmgrIsDeviceUsingDeviceProfiling_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003e8f80 kmigmgrIsDeviceUsingDeviceProfiling_IMPL =====

undefined1 kmigmgrIsDeviceUsingDeviceProfiling_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  long local_18;
  long local_10;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) {
    return 0;
  }
  if (((*(char *)(param_1 + 0x467) != '\0') &&
      (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) != '\0')) &&
     (*(char *)(param_2 + 0x5368) != '\0')) {
    if (param_3 == 0) {
      nvAssertFailedNoLog("pDevice != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc0c);
    }
    else {
      puVar1 = *(undefined8 **)(*(long *)(param_3 + 0x110) + 0x48);
      uVar2 = *puVar1;
      iVar4 = subdeviceGetByInstance_IMPL(uVar2,*(undefined4 *)(puVar1 + 2),0,&local_10);
      if (iVar4 == 0) {
        if (local_10 == 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        iVar4 = gisubscriptionGetGPUInstanceSubscription_IMPL
                          (uVar2,*(undefined4 *)
                                  (*(long *)(*(long *)(local_10 + 0x140) + 0x48) + 0x10),&local_18);
        if (iVar4 == 0) {
          return *(undefined1 *)(local_18 + 0x140);
        }
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "gisubscriptionGetGPUInstanceSubscription(pRsClient, RES_GET_HANDLE(pSubdevice), &pGPUInstanceSubscription)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc13);
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar4,
                   "subdeviceGetByInstance(pRsClient, RES_GET_HANDLE(pDevice), 0, &pSubdevice)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc0f);
      }
    }
    return 0;
  }
  return 0;
}


// ===== 003e90b0 kmigmgrEnableAllLCEs_IMPL =====

int kmigmgrEnableAllLCEs_IMPL(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long local_30;
  
  local_30 = 0;
  iVar2 = kceFindFirstInstance_IMPL(param_1,&local_30);
  if (iVar2 == 0) {
    if (param_3 == '\0') {
      uVar1 = *(uint *)(param_1 + 0x8fc);
      if (uVar1 != 0) {
        uVar4 = 0;
        do {
          if ((((uVar4 < 0x14) &&
               (local_30 = *(long *)(param_1 + 0x1c30 + uVar4 * 8), local_30 != 0)) &&
              (*(char *)(local_30 + 0x2d4) != '\0')) &&
             (iVar3 = kceTopLevelPceLceMappingsUpdate_IMPL(param_1), iVar3 != 0)) {
            nvAssertOkFailedNoLog
                      (iVar3,"kceTopLevelPceLceMappingsUpdate(pGpu, pKCe)",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc36);
            return iVar3;
          }
          uVar4 = uVar4 + 1;
        } while (uVar1 != uVar4);
      }
    }
    else {
      iVar2 = kceUpdateClassDB_KERNEL(param_1,local_30);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"kceUpdateClassDB_HAL(pGpu, pKCe)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc31);
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"kceFindFirstInstance(pGpu, &pKCe)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc2d);
  }
  return iVar2;
}


// ===== 003e91d0 kmigmgrLoadStaticInfo_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrLoadStaticInfo_KERNEL(long param_1,long param_2)

{
  long lVar1;
  char *pcVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar2 = *(char **)(param_2 + 0x278);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (pcVar2 == (char *)0x0) {
    nvAssertFailedNoLog("pPrivate != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x61a);
    return 0x40;
  }
  if (*pcVar2 != '\0') {
    return 0;
  }
  lVar1 = param_1 + 0x3b58;
  lVar8 = *(long *)(param_1 + 0x1b70);
  *pcVar2 = '\x01';
  bitVectorClrAll_IMPL(pcVar2 + 0x10,0x54);
  if ((*(char *)(param_1 + 0x909) != '\0') &&
     (iVar6 = kmigmgrEnableAllLCEs_IMPL(param_1,param_2,1), iVar6 != 0)) {
    nvCheckFailedNoLog(4,"kmigmgrEnableAllLCEs(pGpu, pKernelMIGManager, NV_TRUE) == NV_OK",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x62a);
  }
  iVar6 = (**(code **)(param_1 + 0x3b90))
                    (lVar1,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
                     0x20800a65,&local_58,0x20);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_PARTITIONABLE_ENGINES, &params, sizeof(params))"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x62d);
    goto LAB_003e95b0;
  }
  bitVectorFromRaw_IMPL(local_78,0x54,&local_58,0x20);
  bitVectorCopy_IMPL(local_68,0x54,local_78,0x54);
  uVar4 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
  while (cVar3 = bitVectorTestAllCleared_IMPL(local_68,0x54), cVar3 == '\0') {
    uVar5 = gpuGetRmEngineType_IMPL(uVar4);
    bitVectorSet_IMPL(pcVar2 + 0x10,0x54,uVar5);
    bitVectorClr_IMPL(local_68,0x54,uVar4);
    uVar4 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
  }
  lVar7 = portMemAllocNonPaged(0x1b4);
  *(long *)(pcVar2 + 0x30) = lVar7;
  if (lVar7 == 0) {
    nvCheckFailedNoLog(4,"pPrivate->staticInfo.pSkylineInfo != NULL",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x646);
  }
  else {
    portMemSet(lVar7,0,0x1b4);
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (lVar1,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
                       0x20800aa2,*(undefined8 *)(pcVar2 + 0x30),0x1b4);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO, pPrivate->staticInfo.pSkylineInfo, sizeof(*pPrivate->staticInfo.pSkylineInfo))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x64c);
      goto LAB_003e95b0;
    }
    lVar7 = portMemAllocNonPaged(0xf0);
    *(long *)(pcVar2 + 0x20) = lVar7;
    if (lVar7 == 0) {
      nvCheckFailedNoLog(4,"pPrivate->staticInfo.pSwizzIdFbMemPageRanges != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x656);
    }
    else {
      portMemSet(lVar7,0,0xf0);
      iVar6 = (**(code **)(param_1 + 0x3b90))
                        (lVar1,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
                         0x20800a66,*(undefined8 *)(pcVar2 + 0x20),0xf0);
      if (iVar6 == 0x56) {
        portMemFree(*(undefined8 *)(pcVar2 + 0x20));
        pcVar2[0x20] = '\0';
        pcVar2[0x21] = '\0';
        pcVar2[0x22] = '\0';
        pcVar2[0x23] = '\0';
        pcVar2[0x24] = '\0';
        pcVar2[0x25] = '\0';
        pcVar2[0x26] = '\0';
        pcVar2[0x27] = '\0';
      }
      else if (iVar6 != 0) {
        nvCheckOkFailedNoLog(4,iVar6,"status","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x66c);
        goto LAB_003e95b0;
      }
      iVar6 = (**(code **)(lVar8 + 0x218))(param_1);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"kmemsysPopulateMIGGPUInstanceMemConfig_HAL(pGpu, pKernelMemorySystem)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x673);
        return iVar6;
      }
      lVar8 = portMemAllocNonPaged(0xc4);
      *(long *)(pcVar2 + 0x28) = lVar8;
      if (lVar8 == 0) {
        nvCheckFailedNoLog(4,"pPrivate->staticInfo.pCIProfiles != NULL",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x676);
      }
      else {
        portMemSet(lVar8,0,0xc4);
        iVar6 = (**(code **)(param_1 + 0x3b90))
                          (lVar1,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c)
                           ,0x20800aba,*(undefined8 *)(pcVar2 + 0x28),0xc4);
        if (iVar6 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar6,
                     "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_COMPUTE_PROFILES, pPrivate->staticInfo.pCIProfiles, sizeof(*pPrivate->staticInfo.pCIProfiles))"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x67c);
          goto LAB_003e95b0;
        }
        lVar8 = portMemAllocNonPaged(0x1958);
        *(long *)(pcVar2 + 8) = lVar8;
        if (lVar8 != 0) {
          portMemSet(lVar8,0,0x1958);
          iVar6 = (**(code **)(param_1 + 0x3b90))
                            (lVar1,*(undefined4 *)(param_1 + 0x3b34),
                             *(undefined4 *)(param_1 + 0x3b3c),0x20800a63,
                             *(undefined8 *)(pcVar2 + 8),0x1958);
          if (iVar6 == 0) {
            if ((*(char *)(param_1 + 0x909) != '\0') &&
               (iVar6 = kmigmgrEnableAllLCEs_IMPL(param_1,param_2,0), iVar6 != 0)) {
              nvCheckFailedNoLog(4,
                                 "kmigmgrEnableAllLCEs(pGpu, pKernelMIGManager, NV_FALSE) == NV_OK",
                                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x697);
              return 0;
            }
            return 0;
          }
          nvCheckOkFailedNoLog
                    (4,iVar6,
                     "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_PROFILES, pPrivate->staticInfo.pProfiles, sizeof(*pPrivate->staticInfo.pProfiles))"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x68c);
          goto LAB_003e95b0;
        }
        nvCheckFailedNoLog(4,"pPrivate->staticInfo.pProfiles != NULL",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x686);
      }
    }
  }
  iVar6 = 0x51;
LAB_003e95b0:
  portMemFree(*(undefined8 *)(pcVar2 + 8));
  pcVar2[8] = '\0';
  pcVar2[9] = '\0';
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  pcVar2[0xc] = '\0';
  pcVar2[0xd] = '\0';
  pcVar2[0xe] = '\0';
  pcVar2[0xf] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x20));
  pcVar2[0x20] = '\0';
  pcVar2[0x21] = '\0';
  pcVar2[0x22] = '\0';
  pcVar2[0x23] = '\0';
  pcVar2[0x24] = '\0';
  pcVar2[0x25] = '\0';
  pcVar2[0x26] = '\0';
  pcVar2[0x27] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x28));
  pcVar2[0x28] = '\0';
  pcVar2[0x29] = '\0';
  pcVar2[0x2a] = '\0';
  pcVar2[0x2b] = '\0';
  pcVar2[0x2c] = '\0';
  pcVar2[0x2d] = '\0';
  pcVar2[0x2e] = '\0';
  pcVar2[0x2f] = '\0';
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x278) + 0x30));
  *(undefined8 *)(*(long *)(param_2 + 0x278) + 0x30) = 0;
  *pcVar2 = '\0';
  return iVar6;
}


// ===== 003e97b4 kmigmgrGetInstanceRefFromDevice_IMPL.cold =====

void kmigmgrGetInstanceRefFromDevice_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003e97c0 kmigmgrGetInstanceRefFromDevice_IMPL =====

int kmigmgrGetInstanceRefFromDevice_IMPL
              (long param_1,undefined8 param_2,long param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long local_50;
  long local_48;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_48 = 0;
  if (param_4 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pRef != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc50);
    return 0x1f;
  }
  *param_4 = 0;
  param_4[1] = 0;
  if ((((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x1bc0), lVar1 == 0)) ||
      (*(char *)(param_1 + 0x467) == '\0')) ||
     ((*(char *)(lVar1 + 0x5340) == '\0' || (*(long *)(lVar1 + 0x5348) == 0)))) {
LAB_003e9920:
    iVar5 = 0x40;
  }
  else {
    if (param_3 == 0) {
      nvAssertFailedNoLog("pDevice != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc58);
      return 0x1f;
    }
    puVar2 = *(undefined8 **)(*(long *)(param_3 + 0x110) + 0x48);
    uVar7 = *puVar2;
    iVar5 = subdeviceGetByInstance_IMPL(uVar7,*(undefined4 *)(puVar2 + 2),0,&local_40);
    if (iVar5 == 0) {
      if (local_40 == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      iVar5 = gisubscriptionGetGPUInstanceSubscription_IMPL
                        (uVar7,*(undefined4 *)(*(long *)(*(long *)(local_40 + 0x140) + 0x48) + 0x10)
                         ,&local_50);
      if (iVar5 == 0) {
        uVar8 = 0;
        iVar5 = cisubscriptionGetComputeInstanceSubscription_IMPL
                          (uVar7,*(undefined4 *)
                                  (*(long *)(*(long *)(local_50 + 0x110) + 0x48) + 0x10),&local_48);
        uVar7 = *(undefined8 *)(local_50 + 0x138);
        if (iVar5 == 0) {
          uVar8 = *(undefined8 *)(local_48 + 0x138);
        }
        local_38 = uVar7;
        local_30 = uVar8;
        cVar4 = kmigmgrIsMIGReferenceValid_IMPL(&local_38);
        if (cVar4 == '\x01') {
          param_4[1] = uVar8;
          *param_4 = uVar7;
          return 0;
        }
        goto LAB_003e9920;
      }
      uVar7 = 0xc5e;
      pcVar6 = 
      "gisubscriptionGetGPUInstanceSubscription(pRsClient, RES_GET_HANDLE(pSubdevice), &pGPUInstanceSubscription)"
      ;
    }
    else {
      uVar7 = 0xc5b;
      pcVar6 = "subdeviceGetByInstance(pRsClient, RES_GET_HANDLE(pDevice), 0, &pSubdevice)";
    }
    nvCheckOkFailedNoLog(1,iVar5,pcVar6,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar7);
  }
  return iVar5;
}


// ===== 003e99d0 kmigmgrGetMemoryPartitionHeapFromDevice_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrGetMemoryPartitionHeapFromDevice_IMPL
              (long param_1,undefined8 param_2,long param_3,undefined8 *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  long local_48 [3];
  
  if ((((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x1bc0), lVar1 == 0)) ||
      (*(char *)(param_1 + 0x467) == '\0')) ||
     ((*(char *)(lVar1 + 0x5340) == '\0' || (*(long *)(lVar1 + 0x5348) == 0)))) {
    nvAssertFailedNoLog("IS_MIG_IN_USE(pGpu)","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc88);
    return 0x40;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pDevice != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc8a);
  }
  else {
    plVar5 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_3 + 0x110) + 0x48),
                                        __nvoc_class_def_RmClient);
    if (plVar5 == (long *)0x0) {
      nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc8d);
      return 0x23;
    }
    iVar3 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,param_2,param_3,local_48);
    if ((iVar3 != 0) || (cVar2 = kmigmgrIsMIGReferenceValid_IMPL(local_48), cVar2 == '\0')) {
      uVar4 = (**(code **)(*plVar5 + 0xd8))(plVar5);
      if (1 < uVar4) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc9b,
                   "kmigmgrGetMemoryPartitionHeapFromDevice_IMPL",1,
                   "NVRM: Failed to get GPU instance for non-privileged client hClient=0x%08x!\n",
                   *(undefined4 *)(**(long **)(*(long *)(param_3 + 0x110) + 0x48) + 0x48));
      if (iVar3 == 0) {
        iVar3 = 0x40;
      }
      return iVar3;
    }
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = *(undefined8 *)(local_48[0] + 0x980);
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xca8,
                   "kmigmgrGetMemoryPartitionHeapFromDevice_IMPL",1,
                   "NVRM: GPU instance heap found for hClient = 0x%08x with swizzId = %d!\n",
                   *(undefined4 *)(**(long **)(*(long *)(param_3 + 0x110) + 0x48) + 0x48),
                   *(undefined4 *)(local_48[0] + 0x968));
      return 0;
    }
    nvAssertFailedNoLog("ppMemoryPartitionHeap != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xca6);
  }
  return 0x1f;
}


// ===== 003e9c60 kmigmgrPrintGPUInstanceInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrPrintGPUInstanceInfo_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 uVar11;
  long lVar12;
  undefined1 auVar13 [16];
  long *local_40 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b70);
  auVar13 = memmgrGetMIGPartitionableMemoryRange_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78));
  uVar4 = kmigmgrCountEnginesInRange_IMPL(param_3 + 0x98,1,8);
  uVar11 = (**(code **)(param_2 + 0x170))(param_1,param_2);
  uVar5 = kmigmgrCountEnginesInRange_IMPL(param_3 + 0x98,uVar11);
  uVar6 = kmigmgrCountEnginesInRange_IMPL(param_3 + 0x98,0x1d,0x24);
  uVar7 = kmigmgrCountEnginesInRange_IMPL(param_3 + 0x98,0x25,0x28);
  uVar8 = kmigmgrCountEnginesInRange_IMPL(param_3 + 0x98,0x36,0x3d);
  uVar9 = kmigmgrCountEnginesInRange_IMPL(param_3 + 0x98,0x3e,0x3f);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xce5,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------",uVar5);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xce6,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n","SwizzId",
               "SwizzId Table Mask","Gpc Count");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcea,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xceb,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18d | %18s | %18d  |\n",
               *(undefined4 *)(param_3 + 0x968),"NOT IMPLEMENTED",*(undefined4 *)(param_3 + 0x88));
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcef,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcf0,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n","OBJGR Count",
               "OBJCE Count","NVDEC Count");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcf4,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcf5,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %61s |\n",
               "Note: GRCE Count is same as OBJGR Count");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcf7,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %61s |\n",
               "Note: OBJCE Count does not include GRCEs");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcf9,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcfb,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18d | %18d | %18d  |\n",uVar4,uVar5,
               uVar6);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xcff,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd00,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n","NVENC Count",
               "NVJPG Count","NVOFA Count");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd04,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd05,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18d | %18d | %18d  |\n",uVar7,uVar8,
               uVar9);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd09,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd0a,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n","VEID Offset",
               "VEID Count","VEID-GR Map");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd0e,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd0f,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18d | %18d | %18llx  |\n",
               *(undefined4 *)(param_3 + 0x90),*(undefined4 *)(param_3 + 0x94),
               (0xffffffffffffffffU >> (~(byte)*(undefined4 *)(param_3 + 0x94) & 0x3f)) <<
               ((byte)*(undefined4 *)(param_3 + 0x90) & 0x3f));
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd13,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd14,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
               "Partitionable","Partitionable",&DAT_00d5de2d);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd18,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
               "Memory Start Addr","Memory End Addr","L2TLB Mask");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd1c,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd1d,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18llx | %18llx | %18x  |\n",
               auVar13._0_8_,auVar13._8_8_,*(undefined4 *)(param_3 + 0xa04));
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd21,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd22,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
               "Local Instance","Local Instance","Local Instance");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd26,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
               "Memory Start Addr","Memory End Addr","Size in Bytes");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd2a,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  uVar2 = *(ulong *)(param_3 + 0x998);
  uVar3 = *(ulong *)(param_3 + 0x990);
  lVar12 = (uVar2 + 1) - uVar3;
  if (uVar2 < uVar3) {
    lVar12 = 0;
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd2b,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18llx | %18llx | %18llx  |\n",uVar3,
               uVar2,lVar12);
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd2f,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd30,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
               "Local Instance","Local Instance","Local Instance");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd34,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
               "Start VMMU Seg.","End VMMU Seg.","Size in VMMU Seg.");
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd38,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  iVar10 = kmemsysGetMIGGPUInstanceMemConfigFromSwizzId_IMPL
                     (param_1,uVar1,*(undefined4 *)(param_3 + 0x968),local_40);
  if (iVar10 == 0x56) {
    if ((*(char *)(param_1 + 0x908) == '\0') &&
       (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')) {
      nvAssertFailedNoLog("IS_VIRTUAL(pGpu) || pGpu->pGpuArch->bGpuArchIsZeroFb",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd43);
      return;
    }
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd45,
                 "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18s | %18s | %18s  |\n",
                 &DAT_00d5dea8,&DAT_00d5dea8,&DAT_00d5dea8);
  }
  else {
    if (iVar10 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd49);
      return;
    }
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd4a,
                 "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: | %18llx | %18llx | %18llx  |\n",
                 *local_40[0],local_40[0][1] + -1 + *local_40[0],local_40[0][1]);
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd50,
               "kmigmgrPrintGPUInstanceInfo_IMPL",1,"NVRM: %s\n",
               "-----------------------------------------------------------------");
  return;
}


// ===== 003ea520 kmigmgrGetGPUInstanceInfo_IMPL =====

undefined8
kmigmgrGetGPUInstanceInfo_IMPL(undefined8 param_1,long param_2,uint param_3,long *param_4)

{
  long lVar1;
  
  lVar1 = param_2 + 0x280;
  if (param_3 < 0xf) {
    do {
      if (((lVar1 != 0) && (*(char *)(lVar1 + 0x988) != '\0')) &&
         (param_3 == *(uint *)(lVar1 + 0x968))) {
        *param_4 = lVar1;
        return 0;
      }
      lVar1 = lVar1 + 0xa18;
    } while (lVar1 != param_2 + 0x5340);
  }
  return 0x1f;
}


// ===== 003ea580 kmigmgrGetLocalToGlobalEngineType_IMPL =====

undefined8
kmigmgrGetLocalToGlobalEngineType_IMPL
          (long param_1,undefined8 param_2,long param_3,long param_4,int param_5,int *param_6)

{
  int iVar1;
  undefined8 uVar2;
  int local_c;
  
  local_c = param_5;
  if (param_3 != 0) {
    if (*(char *)(param_3 + 0x988) == '\0') {
      nvAssertFailedNoLog("pRef->pKernelMIGGpuInstance->bValid",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbf);
    }
    else {
      if ((param_4 == 0) || (*(char *)(param_4 + 0xb8) != '\0')) {
        if (0x52 < param_5 - 1U) {
          nvAssertFailedNoLog("RM_ENGINE_TYPE_IS_VALID(localEngType)",
                              "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xdee);
          return 0x1f;
        }
        if ((*(char *)(param_1 + 0x467) != '\0') &&
           ((param_5 - 0x36U < 10 || (param_5 - 1U < 0x28)))) {
          if ((param_4 != 0) &&
             (iVar1 = kmigmgrEngineTypeXlate_IMPL(param_4 + 0xa0,param_5,param_4 + 0x90,&local_c),
             iVar1 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe01,
                         "kmigmgrGetLocalToGlobalEngineType_IMPL",1,
                         "NVRM: Compute instance Local Engine type 0x%x is not allocated to Compute instance\n"
                         ,local_c);
            return 0x1f;
          }
          uVar2 = kmigmgrEngineTypeXlate_IMPL(param_3 + 0xa8,local_c,param_3 + 0x98,&local_c);
          if ((int)uVar2 != 0) {
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe0c,
                         "kmigmgrGetLocalToGlobalEngineType_IMPL",1,
                         "NVRM: GPU instance Local Engine type 0x%x is not allocated to GPU instance\n"
                         ,local_c);
            return 0x1f;
          }
          *param_6 = local_c;
          return uVar2;
        }
        *param_6 = param_5;
        return 0;
      }
      nvAssertFailedNoLog("pRef->pMIGComputeInstance->bValid",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc3);
    }
  }
  nvAssertFailedNoLog("kmigmgrIsMIGReferenceValid(&ref)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xded);
  return 0x1f;
}


// ===== 003ea740 kmigmgrGetGlobalToLocalEngineType_IMPL =====

undefined4
kmigmgrGetGlobalToLocalEngineType_IMPL
          (long param_1,undefined8 param_2,long param_3,long param_4,int param_5,int *param_6)

{
  int iVar1;
  int local_c;
  
  local_c = param_5;
  if (param_3 != 0) {
    if (*(char *)(param_3 + 0x988) == '\0') {
      nvAssertFailedNoLog("pRef->pKernelMIGGpuInstance->bValid",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xbf);
    }
    else {
      if ((param_4 == 0) || (*(char *)(param_4 + 0xb8) != '\0')) {
        if (0x52 < param_5 - 1U) {
          nvAssertFailedNoLog("RM_ENGINE_TYPE_IS_VALID(globalEngType)",
                              "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe26);
          return 0x1f;
        }
        if ((*(char *)(param_1 + 0x467) == '\0') || ((9 < param_5 - 0x36U && (0x27 < param_5 - 1U)))
           ) {
          if (param_6 != (int *)0x0) {
            *param_6 = param_5;
          }
          return 0;
        }
        iVar1 = kmigmgrEngineTypeXlate_IMPL(param_3 + 0x98,param_5,param_3 + 0xa8,&local_c);
        if (iVar1 != 0) {
          if (param_6 == (int *)0x0) {
            return 0x1f;
          }
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe3c,
                       "kmigmgrGetGlobalToLocalEngineType_IMPL",1,
                       "NVRM: Global Engine type 0x%x is not allocated to GPU instance\n",local_c);
          return 0x1f;
        }
        if ((param_4 != 0) &&
           (iVar1 = kmigmgrEngineTypeXlate_IMPL(param_4 + 0x90,local_c,param_4 + 0xa0,&local_c),
           iVar1 != 0)) {
          if (param_6 == (int *)0x0) {
            return 0x1f;
          }
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe4b,
                       "kmigmgrGetGlobalToLocalEngineType_IMPL",4,
                       "NVRM: GPU instance Local Engine type 0x%x is not allocated to compute instance\n"
                       ,local_c);
          return 0x1f;
        }
        if (param_6 == (int *)0x0) {
          return 0;
        }
        *param_6 = local_c;
        return 0;
      }
      nvAssertFailedNoLog("pRef->pMIGComputeInstance->bValid",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xc3);
    }
  }
  nvAssertFailedNoLog("kmigmgrIsMIGReferenceValid(&ref)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe25);
  return 0x1f;
}


// ===== 003ea930 kmigmgrIsEngineInInstance_IMPL =====

bool kmigmgrIsEngineInInstance_IMPL
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  int iVar1;
  
  iVar1 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,param_4,param_5,param_3,0);
  return iVar1 == 0;
}


// ===== 003ea960 kmigmgrTrimInstanceRunlistBufPools_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrTrimInstanceRunlistBufPools_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  
  uVar5 = gpuGetKernelFifoShared_IMPL();
  cVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968));
  if ((cVar1 != '\0') && (cVar1 = ctxBufPoolIsSupported(param_1), cVar1 != '\0')) {
    uVar2 = 0;
    while (uVar3 = uVar2, uVar2 != 0x53) {
      while ((uVar2 = uVar3 + 1, *(char *)(param_1 + 0x467) != '\0' &&
             ((uVar3 - 0x35 < 10 || (uVar3 < 0x28))))) {
        iVar4 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,param_3,0,uVar2,0);
        uVar3 = uVar2;
        if ((iVar4 == 0) && (lVar6 = kfifoGetRunlistBufPool_IMPL(param_1,uVar5,uVar2), lVar6 != 0))
        {
          uVar7 = kfifoGetRunlistBufPool_IMPL(param_1,uVar5,uVar2);
          ctxBufPoolTrim(uVar7);
        }
      }
    }
    return;
  }
  return;
}


// ===== 003eaa80 kmigmgrCreateGPUInstanceRunlists_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrCreateGPUInstanceRunlists_FWCLIENT(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  undefined8 uVar12;
  ulong uVar13;
  ulong uVar14;
  int iVar15;
  bool bVar16;
  uint local_54;
  int local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  ulong local_40 [2];
  
  lVar9 = gpuGetKernelFifoShared_IMPL();
  iVar5 = kfifoGetNumEschedDrivenEngines_IMPL(lVar9);
  uVar6 = (**(code **)(lVar9 + 0x250))(param_1,lVar9);
  cVar3 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968));
  if ((cVar3 == '\0') || (cVar3 = ctxBufPoolIsSupported(param_1), cVar3 == '\0')) {
    return 0;
  }
  kfifoRunlistGetBufAllocParams_IMPL(param_1,&local_44,&local_48,local_40);
  local_40[0] = local_40[0] | 0x1000000000;
  if (iVar5 == 0) {
    bVar4 = (**(code **)(lVar9 + 0x278))(lVar9);
    lVar10 = portMemAllocNonPaged(0x1010);
    if (lVar10 == 0) goto LAB_003eaff4;
    uVar11 = *(ulong *)(param_3 + 0x9b0);
    *(ulong *)(lVar10 + 0x1000) = uVar11;
    *(undefined4 *)(lVar10 + 0x1008) = *(undefined4 *)(param_3 + 0x968);
    if (uVar6 != 0) goto LAB_003eac70;
  }
  else {
    iVar15 = 0;
    do {
      iVar8 = (**(code **)(lVar9 + 0x218))(param_1,lVar9,0xf,iVar15,3);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, index, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x9cc);
        goto LAB_003eae21;
      }
      if ((uVar6 <= local_54) || (0x3f < local_54)) {
        iVar8 = 0x40;
        goto LAB_003eae21;
      }
      if ((*(ulong *)(param_3 + 0x9b0) >> ((ulong)local_54 & 0x3f) & 1) == 0) {
        iVar8 = (**(code **)(lVar9 + 0x218))(param_1,lVar9,3,(ulong)local_54,2,local_50);
        if (iVar8 != 0) {
          nvAssertOkFailedNoLog
                    (iVar8,
                     "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RUNLIST, runlistId, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x9de);
          goto LAB_003eae21;
        }
        iVar8 = (**(code **)(lVar9 + 0x218))(param_1,lVar9,3,local_54,0);
        if (iVar8 != 0) {
          nvAssertOkFailedNoLog
                    (iVar8,
                     "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RUNLIST, runlistId, ENGINE_INFO_TYPE_ENG_DESC, &engDesc)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x9e4);
          goto LAB_003eae21;
        }
        if ((*(char *)(param_1 + 0x467) != '\0') &&
           (((local_50[0] - 0x36U < 10 || (local_50[0] - 1U < 0x28)) &&
            (iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,param_3,0), iVar8 == 0))
           )) {
          iVar8 = kfifoRunlistAllocBuffers_IMPL
                            (param_1,lVar9,local_44,(ulong)local_54,local_48,local_40[0],0,1,
                             *(undefined8 *)(*(long *)(lVar9 + 0x798) + (ulong)local_54 * 8));
          if (iVar8 != 0) {
            nvAssertOkFailedNoLog
                      (iVar8,
                       "kfifoRunlistAllocBuffers(pGpu, pKernelFifo, aperture, runlistId, attr, allocFlags, 0, NV_TRUE, pKernelFifo->pppRunlistBufMemDesc[runlistId])"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x9ff);
            goto LAB_003eae21;
          }
          *(ulong *)(param_3 + 0x9b0) = *(ulong *)(param_3 + 0x9b0) | 1L << ((byte)local_54 & 0x3f);
        }
      }
      iVar15 = iVar15 + 1;
    } while (iVar5 != iVar15);
    bVar4 = (**(code **)(lVar9 + 0x278))(lVar9);
    lVar10 = portMemAllocNonPaged(0x1010);
    if (lVar10 == 0) {
LAB_003eaff4:
      nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xa11);
      iVar8 = 0;
      goto LAB_003eae21;
    }
    uVar11 = *(ulong *)(param_3 + 0x9b0);
    *(ulong *)(lVar10 + 0x1000) = uVar11;
    *(undefined4 *)(lVar10 + 0x1008) = *(undefined4 *)(param_3 + 0x968);
LAB_003eac70:
    local_54 = 0;
    uVar13 = 0;
    while( true ) {
      uVar11 = uVar11 >> ((byte)uVar13 & 0x3f);
      if ((uVar11 & 1) != 0) {
        uVar14 = 0;
        do {
          lVar2 = *(long *)(*(long *)(*(long *)(lVar9 + 0x798) + uVar13 * 8) + uVar14 * 8);
          uVar12 = memdescGetPhysAddr(lVar2,1,0);
          *(undefined8 *)(lVar10 + (uVar14 + uVar13 * 2) * 0x20) = uVar12;
          lVar1 = lVar10 + (uVar14 + (ulong)local_54 * 2) * 0x20;
          *(undefined8 *)(lVar1 + 8) = *(undefined8 *)(lVar2 + 0x38);
          *(long *)(lVar1 + 0x10) = 1L << (bVar4 & 0x3f);
          uVar7 = memdescGetAddressSpace();
          *(undefined4 *)(lVar1 + 0x18) = uVar7;
          uVar13 = (ulong)local_54;
          *(undefined4 *)(lVar10 + 0x1c + (uVar14 + uVar13 * 2) * 0x20) = local_48;
          bVar16 = uVar14 != 1;
          uVar14 = (ulong)((uint)uVar11 & 1);
        } while (bVar16);
      }
      local_54 = (int)uVar13 + 1;
      uVar13 = (ulong)local_54;
      if (uVar6 <= local_54) break;
      uVar11 = *(ulong *)(lVar10 + 0x1000);
    }
  }
  iVar8 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a53,lVar10,0x1010);
  portMemFree(lVar10);
  if (iVar8 == 0) {
    kmigmgrTrimInstanceRunlistBufPools_IMPL(param_1,param_2,param_3);
    return 0;
  }
  nvAssertOkFailedNoLog(iVar8,"status","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xa32);
LAB_003eae21:
  iVar5 = (**(code **)(param_2 + 0x198))(param_1,param_2,param_3);
  if ((iVar5 != 0) &&
     (nvAssertOkFailedNoLog
                (iVar5,
                 "kmigmgrDeleteGPUInstanceRunlists_HAL(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xa3d), iVar8 == 0)) {
    iVar8 = iVar5;
  }
  return iVar8;
}


// ===== 003eb040 kmigmgrFilterEngineList_IMPL =====

int kmigmgrFilterEngineList_IMPL
              (long param_1,undefined8 param_2,long param_3,long param_4,uint *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  bool bVar8;
  int local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  if ((((param_1 == 0) || (lVar7 = *(long *)(param_1 + 0x1bc0), lVar7 == 0)) ||
      (*(char *)(param_1 + 0x467) == '\0')) || (*(char *)(lVar7 + 0x5340) == '\0')) {
    bVar8 = false;
  }
  else {
    bVar8 = *(long *)(lVar7 + 0x5348) != 0;
  }
  uVar2 = *(undefined8 *)(*(long *)(param_3 + 0x158) + 0xe8);
  cVar3 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(param_1,param_2,uVar2);
  *param_5 = 0;
  if (*(int *)(param_1 + 0x1e18) != 0) {
    lVar7 = 0;
    do {
      iVar6 = *(int *)(*(long *)(param_1 + 0x1e20) + lVar7 * 4);
      local_4c = iVar6;
      if (cVar3 == '\0') {
        if (bVar8) {
          iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,param_2,uVar2,&local_48);
          if (iVar5 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar5,
                       "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe87);
            return iVar5;
          }
          iVar5 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,local_48,local_40,iVar6,0);
          if (iVar5 == 0) {
            iVar6 = kmigmgrGetGlobalToLocalEngineType_IMPL
                              (param_1,param_2,local_48,local_40,iVar6,&local_4c);
            if (iVar6 != 0) {
              nvAssertOkFailedNoLog
                        (0x1f,
                         "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &newEngineType)"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xe8d);
            }
            goto LAB_003eb140;
          }
        }
        else if ((6 < iVar6 - 2U) &&
                (((*(char *)(param_1 + 0x46a) == '\0' || (0x13 < iVar6 - 9U)) ||
                 ((cVar4 = ceIsCeGrce(param_1,iVar6), local_4c = iVar6, iVar6 == 9 ||
                  (cVar4 == '\0')))))) goto LAB_003eb140;
      }
      else {
LAB_003eb140:
        uVar1 = *param_5;
        *param_5 = uVar1 + 1;
        *(int *)(param_4 + (ulong)uVar1 * 4) = local_4c;
      }
      lVar7 = lVar7 + 1;
    } while ((uint)lVar7 < *(uint *)(param_1 + 0x1e18));
  }
  return 0;
}


// ===== 003eb2c0 kmigmgrFilterEnginePartnerList_IMPL =====

int kmigmgrFilterEnginePartnerList_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("NULL != pPartnerListParams","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                        0xec5);
    return 0x1f;
  }
  if ((((param_1 != 0) && (lVar5 = *(long *)(param_1 + 0x1bc0), lVar5 != 0)) &&
      (*(char *)(param_1 + 0x467) != '\0')) &&
     ((*(char *)(lVar5 + 0x5340) != '\0' && (*(long *)(lVar5 + 0x5348) != 0)))) {
    iVar2 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (param_1,param_2,*(undefined8 *)(*(long *)(param_3 + 0x158) + 0xe8),&local_48)
    ;
    if (iVar2 == 0) {
      uVar7 = 0;
      if (*(int *)(param_4 + 0xc) != 0) {
        do {
          uVar9 = (ulong)uVar7;
          uVar3 = gpuGetRmEngineType_IMPL(*(undefined4 *)(param_4 + (uVar9 + 4) * 4));
          iVar4 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,local_48,local_40,uVar3,0);
          if (iVar4 == 0) {
            iVar4 = kmigmgrGetGlobalToLocalEngineType_IMPL
                              (param_1,param_2,local_48,local_40,uVar3,&local_4c);
            uVar1 = local_4c;
            if (iVar4 != 0) {
              nvAssertOkFailedNoLog
                        (0x1f,
                         "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xeea);
              return 0x1f;
            }
            uVar7 = uVar7 + 1;
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xeee,
                         "kmigmgrFilterEnginePartnerList_IMPL",1,
                         "NVRM: Overriding global engine type 0x%x to local engine type 0x%x (0x%x) due to MIG\n"
                         ,uVar3,local_4c,local_4c);
            uVar3 = gpuGetNv2080EngineType_IMPL(uVar1);
            *(undefined4 *)(param_4 + (uVar9 + 4) * 4) = uVar3;
            uVar8 = *(uint *)(param_4 + 0xc);
          }
          else {
            iVar4 = *(int *)(param_4 + 0xc);
            uVar8 = iVar4 - 1;
            if (uVar8 <= uVar7) {
              *(uint *)(param_4 + 0xc) = uVar8;
              return 0;
            }
            lVar5 = param_4 + uVar9 * 4;
            do {
              lVar6 = lVar5 + 4;
              *(undefined4 *)(lVar5 + 0x10) = *(undefined4 *)(lVar5 + 0x14);
              lVar5 = lVar6;
            } while (lVar6 != param_4 + 4 + (((iVar4 + -2) - uVar7) + uVar9) * 4);
            *(uint *)(param_4 + 0xc) = uVar8;
          }
        } while (uVar7 < uVar8);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,
                 "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pSubdevice), &ref)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xecd);
    }
    return iVar2;
  }
  return 0;
}


// ===== 003eb520 kmigmgrGetProfileByPartitionFlag_IMPL =====

undefined8
kmigmgrGetProfileByPartitionFlag_IMPL(undefined8 param_1,long param_2,uint param_3,long *param_4)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  ulong uVar4;
  uint *puVar5;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf06);
  }
  else {
    puVar2 = *(uint **)(pcVar1 + 8);
    if (puVar2 != (uint *)0x0) {
      uVar4 = 0;
      puVar5 = puVar2 + 2;
      if (*puVar2 != 0) {
        do {
          if (*puVar5 == param_3) {
            *param_4 = (long)(puVar2 + uVar4 * 0x12 + 2);
            return 0;
          }
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulong)uVar3;
          puVar5 = puVar5 + 0x12;
        } while (*puVar2 != uVar3);
      }
      return 0x57;
    }
    nvAssertFailedNoLog("pStaticInfo->pProfiles != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf07);
  }
  return 0x40;
}


// ===== 003eb5d0 kmigmgrSetPartitioningMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrSetPartitioningMode_IMPL(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  
  lVar1 = *(long *)(param_1 + 0x1d20);
  portMemSet(&local_2c,0,4);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a4c,&local_2c,4);
  if (iVar2 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar2,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_SMC_MODE, &params, sizeof(params))"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf4d);
    return iVar2;
  }
  if (local_2c == 0) {
    iVar2 = 0x40;
    nvAssertFailedNoLog("params.smcMode != NV2080_CTRL_GPU_INFO_GPU_SMC_MODE_UNSUPPORTED",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf56);
  }
  else {
    iVar2 = 0;
    if (1 < local_2c - 3U) {
      *(bool *)(param_2 + 0x5340) = local_2c == 1;
      gpumgrCacheSetMIGEnabled_IMPL(param_1,local_2c == 1);
      if (((*(long *)(param_1 + 0x1bc0) != 0) && (*(char *)(param_1 + 0x467) != '\0')) &&
         (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) != '\0')) {
        iVar3 = (**(code **)(param_2 + 0x178))(param_1,param_2);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"kmigmgrLoadStaticInfo_HAL(pGpu, pKernelMIGManager)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf6b);
          return iVar3;
        }
        iVar3 = gpuDisableAccounting_IMPL(param_1,1);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"gpuDisableAccounting(pGpu, NV_TRUE)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf6d);
        }
      }
      kbusUpdateRusdStatistics_IMPL(param_1);
      if (lVar1 != 0) {
        (**(code **)(lVar1 + 0x168))(param_1,lVar1,*(undefined1 *)(param_2 + 0x5340));
      }
    }
  }
  return iVar2;
}


// ===== 003eb7a0 _kmigmgrHandlePostSchedulingEnableCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kmigmgrHandlePostSchedulingEnableCallback(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  char local_2d;
  uint local_2c [3];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1bc0);
  if (*(char *)(param_1 + 0x908) == '\0') {
    local_2d = '\0';
    local_2c[0] = local_2c[0] & 0xffffff00;
    memmgrGetTopLevelScrubberStatus_IMPL(param_1,lVar1,&local_2d,local_2c);
    if ((local_2d != '\0') && ((char)local_2c[0] == '\0')) {
      return 0x10005;
    }
  }
  iVar4 = (**(code **)(lVar1 + 0x390))(param_1,lVar1);
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,"memmgrSetPartitionableMem_HAL(pGpu, pMemoryManager)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x3d4);
    return iVar4;
  }
  if ((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
    portMemSet(local_2c,0,4);
    iVar4 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a4c,local_2c,4);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_SMC_MODE, &params, sizeof(params))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x3dd);
      return iVar4;
    }
    if (local_2c[0] == 0) {
      *(undefined1 *)(param_1 + 0x467) = 0;
    }
  }
  if ((lVar2 != 0) && (*(char *)(param_1 + 0x467) != '\0')) {
    if ((((*(long *)(param_1 + 0x1bc0) == 0) ||
         (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) == '\0')) &&
        (*(char *)(param_1 + 0x908) == '\0')) &&
       ((*(char *)(param_1 + 0x46d) != '\0' &&
        (((cVar3 = gpumgrIsSystemMIGEnabled_IMPL(*(undefined8 *)(param_1 + 0x878)), cVar3 != '\0' ||
          (*(char *)(lVar2 + 0x5369) != '\0')) || (*(char *)(lVar2 + 0x536a) != '\0')))))) {
      portMemSet(local_2c,0,4);
      local_2c[0] = 2;
      iVar4 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800aa3,local_2c,4);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_PARTITIONING_MODE, &params, sizeof(params))"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x3fa);
        return iVar4;
      }
      iVar4 = kmigmgrSetPartitioningMode_IMPL(param_1,lVar2);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,"kmigmgrSetPartitioningMode(pGpu, pKernelMIGManager)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x402);
        return iVar4;
      }
    }
    gpumgrCacheSetMIGEnabled_IMPL(param_1,*(undefined1 *)(lVar2 + 0x5340));
    if ((((*(char *)(param_1 + 0x44d) == '\0') && (*(char *)(param_1 + 0x446) == '\0')) &&
        (*(char *)(param_1 + 0x490e) == '\0')) ||
       ((((*(char *)(param_1 + 0x908) != '\0' && (*(long *)(param_1 + 0x1bc0) != 0)) &&
         (*(char *)(param_1 + 0x467) != '\0')) &&
        (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) != '\0')))) {
      iVar4 = (**(code **)(lVar2 + 0x178))(param_1,lVar2);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,"kmigmgrLoadStaticInfo_HAL(pGpu, pKernelMIGManager)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x40d);
        return iVar4;
      }
      (**(code **)(lVar2 + 0x1e8))(param_1,lVar2);
    }
    iVar4 = (**(code **)(lVar2 + 0x1a8))(param_1,lVar2);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"kmigmgrRestoreFromPersistence_HAL(pGpu, pKernelMIGManager)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x413);
    }
    return iVar4;
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x3ed,
               "_kmigmgrHandlePostSchedulingEnableCallback",1,
               "NVRM: MIG not supported on this GPU.\n");
  return 0;
}


// ===== 003ebb90 kmigmgrGetMIGReferenceFromEngineType_IMPL =====

undefined8
kmigmgrGetMIGReferenceFromEngineType_IMPL(long param_1,long param_2,int param_3,long *param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("pRef != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xf8a);
    return 0x1f;
  }
  *param_4 = 0;
  param_4[1] = 0;
  if ((((param_1 == 0) || (lVar4 = *(long *)(param_1 + 0x1bc0), lVar4 == 0)) ||
      (*(char *)(param_1 + 0x467) == '\0')) ||
     ((*(char *)(lVar4 + 0x5340) == '\0' || (*(long *)(lVar4 + 0x5348) == 0)))) {
    return 0x56;
  }
  if (0x52 < param_3 - 1U) {
    return 0x1f;
  }
  if ((9 < param_3 - 0x36U) && (0x27 < param_3 - 1U)) {
    return 0x1f;
  }
  uVar3 = 0;
  lVar4 = param_2 + 0x280;
  while (((lVar4 == 0 || (*(char *)(lVar4 + 0x988) == '\0')) ||
         (iVar1 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,lVar4,0,param_3,0),
         iVar1 != 0))) {
    uVar3 = uVar3 + 1;
    if (uVar3 == 8) {
      if (lVar4 != 0) {
        uVar5 = 7;
LAB_003ebcd3:
        if (*(char *)(param_2 + 0xc08 + uVar5 * 0xa18) != '\0') {
          *param_4 = lVar4;
          iVar1 = 0;
          param_4[1] = 0;
          lVar6 = param_2 + 0xe0 + (lVar4 - param_2);
          while ((*(char *)((lVar6 - ((lVar4 - param_2) + -0x280)) + 0xb8 + uVar5 * 0xa18) == '\0'
                 || (uVar2 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                       (param_1,param_2,lVar4,lVar6,param_3,0), (int)uVar2 != 0))) {
            iVar1 = iVar1 + 1;
            lVar6 = lVar6 + 0x110;
            if (iVar1 == 8) {
              return 0;
            }
          }
          *param_4 = lVar4;
          param_4[1] = lVar6;
          return uVar2;
        }
      }
      return 0x40;
    }
    lVar4 = lVar4 + 0xa18;
  }
  uVar5 = (ulong)uVar3;
  goto LAB_003ebcd3;
}


// ===== 003ebde0 kmigmgrGetGPUInstanceScrubberCe_IMPL =====

int kmigmgrGetGPUInstanceScrubberCe_IMPL
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long local_58;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  *param_4 = 0;
  iVar2 = kmigmgrGetInstanceRefFromDevice_IMPL();
  if (iVar2 == 0) {
    bitVectorClrAll_IMPL(local_48,0x54);
    bitVectorSetRange_IMPL(local_48,0x54,9,0x1c);
    bitVectorAnd_IMPL(local_48,0x54,local_48,0x54,local_58 + 0x98,0x54);
    cVar1 = bitVectorTestAllCleared_IMPL(local_48,0x54);
    if (cVar1 == '\0') {
      bitVectorCopy_IMPL(local_38,0x54,local_48,0x54);
      iVar3 = bitVectorCountTrailingZeros_IMPL(local_38,0x54);
      while (cVar1 = bitVectorTestAllCleared_IMPL(local_38,0x54), cVar1 == '\0') {
        cVar1 = ceIsCeGrce(param_1,iVar3);
        if (cVar1 == '\0') {
          iVar3 = iVar3 + -9;
          *param_4 = iVar3;
          goto joined_r0x003ebf19;
        }
        bitVectorClr_IMPL(local_38,0x54,iVar3);
        iVar3 = bitVectorCountTrailingZeros_IMPL(local_38,0x54);
      }
      iVar3 = *param_4;
joined_r0x003ebf19:
      if (iVar3 == 0) {
        iVar2 = 0;
        iVar3 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
        *param_4 = iVar3 + -9;
      }
    }
    else {
      iVar2 = 0x1a;
      nvAssertFailedNoLog("!bitVectorTestAllCleared(&ces)",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xfe2);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xfdb);
  }
  return iVar2;
}


// ===== 003ebf90 kmigmgrDescribeGPUInstances_IMPL =====

undefined8 kmigmgrDescribeGPUInstances_IMPL(long param_1,long param_2,uint *param_3)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  uint uVar6;
  ulong uVar7;
  ulong local_48;
  ulong local_40;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  if (((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) && (*(int **)(pcVar1 + 8) != (int *)0x0)) {
    uVar2 = 0;
    if (**(int **)(pcVar1 + 8) != 0) {
      uVar7 = 0;
      do {
        if (*(char *)(param_1 + 0x908) == '\0') {
          local_40 = 0;
          local_48 = 1;
          uVar5 = 0;
          uVar2 = (*(uint *)(*(long *)(pcVar1 + 8) + uVar7 * 0x48 + 8) & 3) - 1;
          if (uVar2 < 3) {
            uVar5 = *(undefined4 *)(CSWTCH_611 + (ulong)uVar2 * 4);
          }
          iVar3 = kmemsysGetMIGGPUInstanceMemInfo_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1b70),uVar5,&local_48);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "kmemsysGetMIGGPUInstanceMemInfo(pGpu, pKernelMemorySystem, swizzId, &addrRange)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1030);
          }
          lVar4 = (local_40 + 1) - local_48;
          if (local_40 < local_48) {
            lVar4 = 0;
          }
          *(long *)(param_3 + uVar7 * 0x10 + 0x10) = lVar4;
        }
        else {
          lVar4 = gpuGetStaticInfo(param_1);
          if (lVar4 == 0) {
            nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1011)
            ;
            return 0x40;
          }
          *(undefined8 *)(param_3 + uVar7 * 0x10 + 0x10) = *(undefined8 *)(lVar4 + 0xa888);
        }
        uVar6 = (int)uVar7 + 1;
        lVar4 = uVar7 * 0x48;
        param_3[uVar7 * 0x10 + 2] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 8);
        param_3[uVar7 * 0x10 + 3] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0xc);
        param_3[uVar7 * 0x10 + 4] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x10);
        param_3[uVar7 * 0x10 + 5] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x14);
        param_3[uVar7 * 0x10 + 7] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x1c);
        param_3[uVar7 * 0x10 + 6] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x18);
        param_3[uVar7 * 0x10 + 8] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x20);
        param_3[uVar7 * 0x10 + 9] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x24);
        param_3[uVar7 * 0x10 + 10] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x28);
        param_3[uVar7 * 0x10 + 0xb] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x2c);
        param_3[uVar7 * 0x10 + 0xc] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x30);
        param_3[uVar7 * 0x10 + 0xd] = *(uint *)(*(long *)(pcVar1 + 8) + lVar4 + 0x34);
        param_3[uVar7 * 0x10 + 0xe] = *(uint *)(lVar4 + *(long *)(pcVar1 + 8) + 0x38);
        uVar2 = **(uint **)(pcVar1 + 8);
        uVar7 = (ulong)uVar6;
      } while (uVar6 < uVar2);
    }
    *param_3 = uVar2;
    return 0;
  }
  return 0x56;
}


// ===== 003ec240 kmigmgrSaveComputeInstances_IMPL =====

undefined8
kmigmgrSaveComputeInstances_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  
  if (param_3 != 0) {
    uVar6 = 0;
    iVar7 = 0;
    if (param_4 != 0) {
      do {
        if (*(char *)(param_3 + 0x198) != '\0') {
          puVar5 = (undefined1 *)((ulong)uVar6 * 0x68 + param_4);
          portMemSet(puVar5,0,0x68);
          *puVar5 = 1;
          uVar2 = *(undefined4 *)(param_3 + 0x19c);
          *(int *)(puVar5 + 0x58) = iVar7;
          *(undefined4 *)(puVar5 + 0x38) = uVar2;
          *(undefined8 *)(puVar5 + 0x60) = *(undefined8 *)(param_3 + 0x1b0);
          bitVectorToRaw_IMPL(param_3 + 0x170,0x54,puVar5 + 8,0x20);
          if (*(char *)(param_1 + 0x909) == '\0') {
            *(uint *)(puVar5 + 0x3c) = 0xffffffff >> (-(char)*(int *)(param_3 + 0x160) & 0x1fU);
          }
          else if (*(int *)(param_3 + 0x160) != 0) {
            uVar4 = *(uint *)(puVar5 + 0x3c);
            lVar3 = 0;
            do {
              lVar1 = lVar3 * 4;
              lVar3 = lVar3 + 1;
              uVar4 = uVar4 | 1 << ((byte)*(undefined4 *)(param_3 + 0xe0 + lVar1) & 0x1f);
              *(uint *)(puVar5 + 0x3c) = uVar4;
            } while ((uint)lVar3 < *(uint *)(param_3 + 0x160));
          }
          uVar6 = uVar6 + 1;
          *(undefined4 *)(puVar5 + 0x40) = *(undefined4 *)(param_3 + 0x164);
          *(undefined4 *)(puVar5 + 0x44) = *(undefined4 *)(param_3 + 0x168);
          *(undefined4 *)(puVar5 + 0x48) = *(undefined4 *)(param_3 + 0x16c);
          *(undefined4 *)(puVar5 + 0x4c) = *(undefined4 *)(param_3 + 0x194);
          *(undefined4 *)(puVar5 + 0x50) = *(undefined4 *)(param_3 + 0x1dc);
          *(undefined4 *)(puVar5 + 0x54) = *(undefined4 *)(param_3 + 0x1e0);
          portMemCopy(puVar5 + 0x28,0x10,param_3 + 0x1b8,0x10);
        }
        iVar7 = iVar7 + 1;
        param_3 = param_3 + 0x110;
      } while (iVar7 != 8);
      return 0;
    }
  }
  nvAssertFailedNoLog("(pKernelMIGGpuInstance != NULL) && (pComputeInstanceSaves != NULL)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1059);
  return 0x1f;
}


// ===== 003ec440 kmigmgrSwizzIdToResourceAllocation_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrSwizzIdToResourceAllocation_IMPL
              (long param_1,undefined8 param_2,uint param_3,long *param_4,long param_5,
              undefined8 param_6,int param_7,long param_8)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  uint local_78 [6];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  if (0xe < param_3) {
    nvCheckFailedNoLog(4,"swizzId < KMIGMGR_MAX_GPU_SWIZZID",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x10a2);
    return 0x1f;
  }
  if (param_7 == 0) {
    portMemSet(local_78,0,0x50);
    local_78[0] = param_3;
    iVar3 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800aa8,local_78,0x50);
    if (iVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar3,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_EXPORT_GPU_INSTANCE, &export, sizeof(export))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x10ad);
      return iVar3;
    }
    local_b0 = local_60;
    local_a8 = local_58;
    local_a0 = local_50;
    local_98 = local_48;
    local_90 = local_40;
    local_88 = (undefined4)local_38;
    uStack_84 = (undefined4)((ulong)local_38 >> 0x20);
    local_80 = (undefined4)local_30;
    uStack_7c = (undefined4)((ulong)local_30 >> 0x20);
  }
  else {
    local_b0 = *(undefined8 *)(param_8 + 8);
    local_a8 = *(undefined8 *)(param_8 + 0x10);
    local_a0 = *(undefined8 *)(param_8 + 0x18);
    local_98 = *(undefined8 *)(param_8 + 0x20);
    local_90 = *(undefined8 *)(param_8 + 0x28);
    local_88 = (undefined4)*(undefined8 *)(param_8 + 0x30);
    uStack_84 = (undefined4)((ulong)*(undefined8 *)(param_8 + 0x30) >> 0x20);
    local_80 = (undefined4)*(undefined8 *)(param_8 + 0x38);
    uStack_7c = (undefined4)((ulong)*(undefined8 *)(param_8 + 0x38) >> 0x20);
  }
  *(undefined4 *)(param_5 + 0x80) = 0;
  if (local_90._4_4_ != 0) {
    lVar2 = 1;
    uVar4 = local_90._4_4_;
    do {
      lVar5 = lVar2;
      iVar3 = 0;
      for (uVar1 = uVar4; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1 | 0x80000000) {
        iVar3 = iVar3 + 1;
      }
      *(int *)(param_5 + -4 + lVar5 * 4) = iVar3;
      uVar4 = uVar4 & ~(1 << ((byte)iVar3 & 0x1f));
      lVar2 = lVar5 + 1;
    } while (uVar4 != 0);
    *(int *)(param_5 + 0x80) = (int)lVar5;
  }
  *(ulong *)(param_5 + 0x88) = CONCAT44(local_80,uStack_84);
  *(undefined4 *)(param_5 + 0xb0) = local_88;
  *(undefined4 *)(param_5 + 0xb4) = *(undefined4 *)(*param_4 + 0x1c);
  bitVectorFromRaw_IMPL(param_5 + 0x90,0x54,&local_b0,0x20);
  kmigmgrGetLocalEngineMask_IMPL(param_1,param_5 + 0x90,param_5 + 0xa0);
  return 0;
}


// ===== 003ec680 kmigmgrSetGPUInstanceInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrSetGPUInstanceInfo_IMPL
              (long param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5,
              undefined8 param_6,int param_7,long param_8)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50 [2];
  undefined8 local_48;
  undefined8 local_40;
  
  local_6c = 0;
  local_60 = 1;
  local_58 = 0;
  local_68 = 0;
  if (param_7 != 0) {
    param_8._0_4_ = *(undefined4 *)(param_8 + 0x28);
  }
  iVar1 = 0x1f;
  if (param_3 < 0xf) {
    pcVar2 = (char *)(param_2 + 0xc08);
    uVar5 = 0;
    do {
      if (*pcVar2 == '\0') {
        iVar1 = (**(code **)(*(long *)(param_1 + 0x1b78) + 0x398))
                          (param_1,*(long *)(param_1 + 0x1b78),param_3,&local_6c,&local_60,&local_68
                          );
        if (iVar1 != 0) {
          nvCheckFailedNoLog(4,"rmStatus == NV_OK","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                             0xd7c);
          return iVar1;
        }
        lVar6 = (ulong)uVar5 * 0xa18;
        lVar3 = param_2 + lVar6;
        *(undefined4 *)(lVar3 + 0xbf0) = local_6c;
        *(undefined8 *)(lVar3 + 0xc18) = local_58;
        *(undefined8 *)(lVar3 + 0xc10) = local_60;
        *(undefined4 *)(lVar3 + 0xbec) = (undefined4)param_8;
        *(undefined1 *)(lVar3 + 0xc08) = 1;
        *(uint *)(lVar3 + 0xbe8) = param_3;
        *(undefined8 *)(lVar3 + 0xc00) = local_68;
        portMemCopy(param_2 + 0xc88 + lVar6,0x10,param_4,0x10);
        if (((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(param_1 + 0x908) == '\0')) &&
           (*(char *)(param_1 + 0x4a4e) != '\0')) {
          local_50[0] = *(undefined4 *)(lVar3 + 0xbe8);
          local_48 = *(undefined8 *)(lVar3 + 0xc10);
          local_40 = *(undefined8 *)(lVar3 + 0xc18);
          iVar1 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                             *(undefined4 *)(param_1 + 0x3b3c),0x20800a44,local_50,0x18);
          if (iVar1 != 0) {
            uVar4 = 0xd96;
            pcVar2 = 
            "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_KMIGMGR_PROMOTE_GPU_INSTANCE_MEM_RANGE, &memParams, sizeof(memParams))"
            ;
            goto LAB_003ec8a6;
          }
        }
        iVar1 = kmigmgrGetProfileByPartitionFlag_IMPL
                          (param_1,param_2,(undefined4)param_8,param_2 + 0x280 + lVar6);
        uVar4 = 0xd9f;
        pcVar2 = 
        "kmigmgrGetProfileByPartitionFlag(pGpu, pKernelMIGManager, partitionFlag, &pKernelMIGGpuInstance->pProfile)"
        ;
        if (iVar1 == 0) {
          iVar1 = serverAllocShare(g_resServ,__nvoc_class_def_RsShared,param_2 + 0xbf8 + lVar6,
                                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xd9f);
          if (iVar1 != 0) {
            nvAssertOkFailedNoLog
                      (iVar1,
                       "serverAllocShare(&g_resServ, classInfo(RsShared), &pKernelMIGGpuInstance->pShare)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xda3);
            return iVar1;
          }
          iVar1 = kmigmgrSwizzIdToResourceAllocation_IMPL
                            (param_1,param_2,param_3,param_2 + 0x280 + lVar6,param_2 + 0x288 + lVar6
                            );
          uVar4 = 0xda7;
          pcVar2 = 
          "kmigmgrSwizzIdToResourceAllocation(pGpu, pKernelMIGManager, swizzId, params, pKernelMIGGpuInstance, &pKernelMIGGpuInstance->resourceAllocation)"
          ;
          if (iVar1 == 0) {
            lVar3 = (ulong)uVar5 * 0xa18;
            *(undefined4 *)(param_2 + 0x30c + lVar3) =
                 *(undefined4 *)(*(long *)(param_2 + 0x280 + lVar3) + 0x14);
            iVar1 = kmigmgrSetEnginesInUse_IMPL
                              (param_1,param_2,param_2 + 0x318 + lVar6,
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xda7);
            if (iVar1 == 0) {
              bitVectorClrAll_IMPL(param_2 + 0x340 + lVar6,0x54);
              bitVectorClrAll_IMPL(param_2 + 0x350 + lVar6,0x54);
              return 0;
            }
            nvAssertOkFailedNoLog
                      (iVar1,
                       "kmigmgrSetEnginesInUse(pGpu, pKernelMIGManager, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xdaf);
            return iVar1;
          }
        }
LAB_003ec8a6:
        nvCheckOkFailedNoLog(4,iVar1,pcVar2,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar4);
        return iVar1;
      }
      uVar5 = uVar5 + 1;
      pcVar2 = pcVar2 + 0xa18;
    } while (uVar5 != 8);
    nvAssertFailedNoLog("i < KMIGMGR_MAX_GPU_INSTANCES",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xdba);
    iVar1 = 0x1a;
  }
  return iVar1;
}


// ===== 003eca40 kmigmgrAllocComputeInstanceHandles_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrAllocComputeInstanceHandles_IMPL
              (undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined1 local_38 [8];
  undefined4 local_30;
  
  puVar2 = (undefined8 *)rmapiGetInterface(4);
  local_4c = 0;
  local_48 = 0;
  iVar1 = rmapiutilAllocClientAndDeviceHandles(puVar2,param_1,&local_44,local_40,&local_3c);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClient, &hDevice, &hSubdevice)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x10e5);
    return iVar1;
  }
  portMemSet(local_38,0,0x10);
  local_30 = *(undefined4 *)(param_3 + 0x968);
  uVar3 = 0x10;
  iVar1 = (*(code *)*puVar2)(puVar2,local_44,local_3c,&local_4c,0xc637,local_38);
  if (iVar1 == 0) {
    portMemSet(local_38,0,0x10,uVar3);
    local_30 = *(undefined4 *)(param_4 + 0xc0);
    iVar1 = (*(code *)*puVar2)(puVar2,local_44,local_4c,&local_48,0xc638,local_38,0x10);
    if (iVar1 == 0) {
      *(undefined4 *)(param_4 + 0xe8) = local_44;
      *(ulong *)(param_4 + 0xf0) = CONCAT44(local_48,local_3c);
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar1,
               "pRmApi->Alloc(pRmApi, hClient, hGPUInstanceSubscription, &hComputeInstanceSubscription, AMPERE_SMC_EXEC_PARTITION_REF, &params, sizeof(params))"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x10f5);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,
               "pRmApi->Alloc(pRmApi, hClient, hSubdevice, &hGPUInstanceSubscription, AMPERE_SMC_PARTITION_REF, &params, sizeof(params))"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x10ec);
  }
  (*(code *)puVar2[3])(puVar2,local_44,local_44);
  return iVar1;
}


// ===== 003ecbf0 kmigmgrGenerateComputeInstanceUuid_VF =====

ulong kmigmgrGenerateComputeInstanceUuid_VF
                (long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                undefined8 param_5)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 local_30;
  
  lVar2 = gpuGetStaticInfo();
  if (lVar2 != 0) {
    uVar1 = *(uint *)(param_1 + 0x8ec);
    portMemCopy(&local_30,8,lVar2 + 0x1f8a4,8);
    uVar3 = nvGenerateSmcUuid(uVar1 >> 0x14 & 0x3ff,local_30,param_3,param_4,param_5);
    if ((int)uVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar3 & 0xffffffff,"nvGenerateSmcUuid(chipId, gid, swizzId, globalGrIdx, pUuid)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1125);
      uVar3 = uVar3 & 0xffffffff;
    }
    return uVar3;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x111c);
  return 0x40;
}


// ===== 003eccd0 kmigmgrGenerateGPUInstanceUuid_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrGenerateGPUInstanceUuid_VF(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x208))();
  return;
}


// ===== 003eccf0 kmigmgrReleaseComputeInstanceEngines_IMPL =====

void kmigmgrReleaseComputeInstanceEngines_IMPL
               (undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x159d);
    return;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pMIGComputeInstance != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                        0x159e);
    return;
  }
  bitVectorCopy_IMPL(local_58,0x54,param_3 + 0x98,0x54);
  bitVectorCopy_IMPL(local_48,0x54,param_3 + 0xa8,0x54);
  uVar2 = bitVectorCountTrailingZeros_IMPL(local_58,0x54);
  uVar3 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  do {
    cVar1 = bitVectorTestAllCleared_IMPL(local_58,0x54);
    if (cVar1 != '\0') {
      return;
    }
    cVar1 = bitVectorTestAllCleared_IMPL(local_48,0x54);
    if (cVar1 != '\0') {
      return;
    }
    cVar1 = bitVectorTest_IMPL(param_4 + 0x90,0x54,uVar3);
    if (cVar1 != '\0') {
      bitVectorClr_IMPL(param_3 + 0xc0,0x54,uVar2);
      cVar1 = bitVectorTest_IMPL(param_3 + 0xd0,0x54,uVar2);
      if (cVar1 != '\0') {
        lVar5 = param_3 + 0x170;
        iVar4 = 0;
        do {
          if ((*(char *)(lVar5 + 0x28) != '\0') &&
             (cVar1 = bitVectorTest_IMPL(lVar5,0x54,uVar3), cVar1 != '\0')) goto LAB_003ecd80;
          iVar4 = iVar4 + 1;
          lVar5 = lVar5 + 0x110;
        } while (iVar4 != 8);
        bitVectorClr_IMPL(param_3 + 0xd0,0x54,uVar2);
      }
    }
LAB_003ecd80:
    bitVectorClr_IMPL(local_58,0x54,uVar2);
    bitVectorClr_IMPL(local_48,0x54,uVar3);
    uVar2 = bitVectorCountTrailingZeros_IMPL(local_58,0x54);
    uVar3 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  } while( true );
}


// ===== 003ecee0 kmigmgrDestroyGPUInstanceGrBufPools_IMPL =====

void kmigmgrDestroyGPUInstanceGrBufPools_IMPL(long param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  int iVar2;
  undefined1 local_28 [16];
  
  cVar1 = ctxBufPoolIsSupported();
  if (cVar1 != '\0') {
    if (param_3 == 0) {
      nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x18da);
    }
    bitVectorCopy_IMPL(local_28,0x54,param_3 + 0x98,0x54);
    iVar2 = bitVectorCountTrailingZeros_IMPL(local_28,0x54);
    while( true ) {
      cVar1 = bitVectorTestAllCleared_IMPL(local_28,0x54);
      if (cVar1 != '\0') break;
      if (iVar2 - 1U < 8) {
        kgraphicsDestroyCtxBufPool_IMPL
                  (param_1,*(undefined8 *)(param_1 + 0x1bd0 + (ulong)(iVar2 - 1U) * 8));
      }
      bitVectorClr_IMPL(local_28,0x54,iVar2);
      iVar2 = bitVectorCountTrailingZeros_IMPL(local_28,0x54);
    }
  }
  return;
}


// ===== 003ecfc0 kmigmgrDestroyGPUInstancePool_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrDestroyGPUInstancePool_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) == '\0') ||
     (*(char *)(*(long *)(param_1 + 0x1b78) + 0x436) == '\0')) {
    if (*(long *)(param_3 + 0x9a0) == 0) {
      return;
    }
    uVar2 = 0x18fc;
  }
  else {
    cVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968));
    lVar3 = *(long *)(param_3 + 0x9a0);
    if (cVar1 != '\0') {
      if (lVar3 == 0) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1908,
                     "kmigmgrDestroyGPUInstancePool_IMPL",1,
                     "NVRM: page table memory pool not setup\n");
        return;
      }
      goto LAB_003ed022;
    }
    if (lVar3 == 0) {
      return;
    }
    uVar2 = 0x1902;
  }
  nvAssertFailedNoLog("(pKernelMIGGpuInstance->pPageTableMemPool == NULL)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar2);
  lVar3 = *(long *)(param_3 + 0x9a0);
LAB_003ed022:
  rmMemPoolDestroy(lVar3);
  *(undefined8 *)(param_3 + 0x9a0) = 0;
  return;
}


// ===== 003ed0b0 kmigmgrDestroyGPUInstanceRunlistBufPools_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrDestroyGPUInstanceRunlistBufPools_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  
  lVar3 = gpuGetKernelFifoShared_IMPL();
  cVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968));
  if (cVar1 != '\0') {
    cVar1 = ctxBufPoolIsSupported(param_1);
    if (cVar1 != '\0') {
      plVar6 = (long *)(lVar3 + 0x4f8);
      uVar5 = 0;
      while (uVar4 = uVar5, uVar5 != 0x53) {
        while( true ) {
          plVar6 = plVar6 + 1;
          uVar5 = uVar4 + 1;
          if ((*(char *)(param_1 + 0x467) == '\0') || ((9 < uVar4 - 0x35 && (0x27 < uVar4)))) break;
          iVar2 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,param_3,0,uVar5,0);
          uVar4 = uVar5;
          if ((iVar2 == 0) && (*plVar6 != 0)) {
            ctxBufPoolRelease();
            ctxBufPoolDestroy(plVar6);
          }
        }
      }
      return;
    }
  }
  return;
}


// ===== 003ed1b0 kmigmgrPrintSubscribingClients_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kmigmgrPrintSubscribingClients_IMPL(undefined8 param_1,undefined8 param_2,int param_3)

{
  long *plVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  long local_90 [2];
  undefined1 local_80 [56];
  long local_48;
  
  plVar5 = (long *)serverutilGetFirstClientUnderLock();
  do {
    if (plVar5 == (long *)0x0) {
      return;
    }
    lVar8 = 0;
    plVar1 = (long *)*plVar5;
    if (plVar1 != (long *)0x0) {
      lVar8 = plVar1[0x20];
    }
    uVar3 = (**(code **)(*plVar1 + 0xd8))();
    clientRefIter(local_80,lVar8,0,&DAT_00e0ac20,0,1);
    pcVar6 = "Usermode";
    if (1 < uVar3) {
      pcVar6 = "Kernel";
    }
    while (cVar2 = clientRefIterNext(lVar8,local_80), cVar2 != '\0') {
      while (((lVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device),
              lVar7 != 0 &&
              (iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,param_2,lVar7,local_90),
              iVar4 == 0)) && (*(int *)(local_90[0] + 0x968) == param_3))) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x195e,
                     "kmigmgrPrintSubscribingClients_IMPL",1,
                     "NVRM: %s client %x device %x currently subscribed to swizzId %u\n",pcVar6,
                     *(undefined4 *)(lVar8 + 0x48),
                     *(undefined4 *)(*(long *)(*(long *)(lVar7 + 0x110) + 0x48) + 0x10),param_3);
        cVar2 = clientRefIterNext(lVar8,local_80);
        if (cVar2 == '\0') goto LAB_003ed328;
      }
    }
LAB_003ed328:
    plVar5 = (long *)serverutilGetNextClientUnderLock(plVar5);
  } while( true );
}


// ===== 003ed360 kmigmgrSetMIGState_VF =====

undefined8 kmigmgrSetMIGState_VF(long param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  if (param_4 == '\0') {
    return 0;
  }
  kgraphicsInvalidateStaticInfo_IMPL(param_1,*(undefined8 *)(param_1 + 0x1bd0));
  return 0;
}


// ===== 003ed3a0 kmigmgrSetMIGState_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrSetMIGState_FWCLIENT(long param_1,long param_2,char param_3,char param_4,char param_5)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  ulong uVar13;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1bc8);
  lVar10 = gpuGetKernelFifoShared_IMPL();
  uVar3 = *(undefined8 *)(param_1 + 0x1b78);
  uVar1 = *(undefined1 *)(param_2 + 0x5340);
  if (param_4 == '\0') {
    if (param_3 == '\0') {
      puVar4 = *(undefined8 **)(lVar10 + 0x798);
    }
    else {
      memmgrFreeMIGMemoryAllocationInternalHandles_IMPL(param_1,uVar3);
      puVar4 = *(undefined8 **)(lVar10 + 0x798);
    }
    if (puVar4 != (undefined8 *)0x0) {
      portMemFree(*puVar4);
      portMemFree(*(undefined8 *)(lVar10 + 0x798));
      *(undefined8 *)(lVar10 + 0x798) = 0;
    }
    uVar6 = (**(code **)(param_1 + 0x3c0))(param_1);
    *(undefined1 *)(param_1 + 0x490) = uVar6;
    iVar7 = kmigmgrEnableAllLCEs_IMPL(param_1,param_2,0);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,"kmigmgrEnableAllLCEs(pGpu, pKernelMIGManager, NV_FALSE)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a47);
    }
LAB_003ed45d:
    iVar8 = gpuAddClassToClassDBByClassId_IMPL(param_1,0x503b);
    if ((iVar8 != 0) &&
       (nvAssertOkFailedNoLog
                  (iVar8,"gpuAddClassToClassDBByClassId(pGpu, NV50_P2P)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a4d), iVar7 == 0)) {
      iVar7 = iVar8;
    }
    if ((*(long *)(param_1 + 0x4c0) != 0) && (iVar8 = gpuFabricProbeResume(), iVar8 != 0)) {
      nvAssertOkFailedNoLog
                (iVar8,"gpuFabricProbeResume(pGpu->pGpuFabricProbeInfoKernel)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a56);
    }
LAB_003ed48b:
    if (param_5 == '\0') {
      iVar8 = memmgrInitInternalChannels_IMPL(param_1,uVar3);
      if (iVar8 == 0) {
        *(undefined1 *)(param_2 + 0x5340) = 0;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar8,"memmgrInitInternalChannels(pGpu, pMemoryManager)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a5d);
        *(undefined1 *)(param_2 + 0x5340) = 0;
        if (iVar7 == 0) {
          iVar7 = iVar8;
        }
      }
LAB_003ed71d:
      lVar10 = *(long *)(param_1 + 0x1bd0);
      iVar8 = (**(code **)(lVar10 + 0x1b0))(param_1,lVar10,0xffffffff);
      if ((iVar8 != 0) &&
         (nvAssertOkFailedNoLog
                    (iVar8,"kgraphicsLoadStaticInfo(pGpu, pKGr, KMIGMGR_SWIZZID_INVALID)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a6a), iVar7 == 0)) {
        iVar7 = iVar8;
      }
      iVar8 = kmigmgrRestoreWatchdog_IMPL(param_1,param_2);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,"kmigmgrRestoreWatchdog(pGpu, pKernelMIGManager)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a6c);
      }
      iVar8 = kgraphicsCreateGoldenImageChannel_IMPL(param_1,lVar10);
      if ((iVar8 != 0) &&
         (nvAssertOkFailedNoLog
                    (iVar8,"kgraphicsCreateGoldenImageChannel(pGpu, pKGr)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a6e), iVar7 == 0)) {
        iVar7 = iVar8;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x5340) = 0;
    }
  }
  else {
    uVar5 = *(undefined8 *)(param_1 + 0x1bd0);
    iVar7 = kgrmgrDiscoverMaxGlobalCtxBufSizes_IMPL(param_1,uVar2);
    if (iVar7 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "kgrmgrDiscoverMaxGlobalCtxBufSizes(pGpu, pKernelGraphicsManager, pKGr, bMemoryPartitioningNeeded)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x19a9);
      goto LAB_003ed65f;
    }
    iVar7 = kmigmgrDisableWatchdog_IMPL(param_1,param_2);
    if (iVar7 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar7,"kmigmgrDisableWatchdog(pGpu, pKernelMIGManager)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x19ad);
      goto LAB_003ed65f;
    }
    kgraphicsInvalidateStaticInfo_IMPL(param_1,uVar5);
    fecsBufferTeardown(param_1,uVar5);
    kgraphicsFreeGlobalCtxBuffers_IMPL(param_1,uVar5,0);
    iVar7 = memmgrDestroyInternalChannels_IMPL(param_1,uVar3);
    if (iVar7 == 0) {
      iVar7 = (**(code **)(param_2 + 0x1c8))(param_1,param_2,param_3);
      if (iVar7 == 0) {
        gpuFabricProbeSuspend(*(undefined8 *)(param_1 + 0x4c0));
        iVar7 = gpuDeleteClassFromClassDBByClassId_IMPL(param_1,0x503b);
        if (iVar7 == 0) {
          *(char *)(param_1 + 0x490) = param_3;
          if ((param_3 == '\0') ||
             (iVar7 = memmgrAllocMIGMemoryAllocationInternalHandles_IMPL(param_1,uVar3), iVar7 == 0)
             ) {
            uVar9 = (**(code **)(lVar10 + 0x250))(param_1,lVar10);
            if (*(long *)(lVar10 + 0x798) != 0) {
              nvAssertFailedNoLog("pKernelFifo->pppRunlistBufMemDesc == NULL",
                                  "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a0b);
            }
            plVar11 = (long *)portMemAllocNonPaged(uVar9 * 8);
            if (plVar11 == (long *)0x0) {
              nvAssertFailedNoLog("pppMemDesc != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c"
                                  ,0x1a0e);
            }
            else {
              portMemSet(plVar11,0,uVar9 * 8);
              lVar12 = portMemAllocNonPaged(uVar9 << 4);
              *plVar11 = lVar12;
              if (lVar12 != 0) {
                portMemSet(lVar12,0,uVar9 << 4);
                if (uVar9 != 0) {
                  uVar13 = 0;
                  do {
                    plVar11[uVar13] = *plVar11 + (ulong)(uint)((int)uVar13 * 2) * 8;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 != uVar9);
                }
                *(long **)(lVar10 + 0x798) = plVar11;
                iVar8 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x218))(param_1);
                iVar7 = 0;
                if (iVar8 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar8,
                             "kmemsysPopulateMIGGPUInstanceMemConfig_HAL(pGpu, pKernelMemorySystem)"
                             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a23);
                  return iVar8;
                }
                goto LAB_003ed65f;
              }
              nvAssertFailedNoLog("*pppMemDesc != NULL",
                                  "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1a12);
            }
            if (*(undefined8 **)(lVar10 + 0x798) == (undefined8 *)0x0) {
              uVar6 = (**(code **)(param_1 + 0x3c0))(param_1);
              *(undefined1 *)(param_1 + 0x490) = uVar6;
            }
            else {
              portMemFree(**(undefined8 **)(lVar10 + 0x798));
              portMemFree(*(undefined8 *)(lVar10 + 0x798));
              *(undefined8 *)(lVar10 + 0x798) = 0;
              uVar6 = (**(code **)(param_1 + 0x3c0))(param_1);
              *(undefined1 *)(param_1 + 0x490) = uVar6;
            }
            iVar7 = 0x51;
          }
          else {
            nvCheckOkFailedNoLog
                      (4,iVar7,"memmgrAllocMIGMemoryAllocationInternalHandles(pGpu, pMemoryManager)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x19fd);
            uVar6 = (**(code **)(param_1 + 0x3c0))(param_1);
            *(undefined1 *)(param_1 + 0x490) = uVar6;
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar7,"gpuDeleteClassFromClassDBByClassId(pGpu, NV50_P2P)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x19f2);
        }
        goto LAB_003ed45d;
      }
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "kmigmgrCreateGPUInstanceCheck_HAL(pGpu, pKernelMIGManager, bMemoryPartitioningNeeded)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x19c9);
      goto LAB_003ed48b;
    }
    nvAssertOkFailedNoLog
              (iVar7,"memmgrDestroyInternalChannels(pGpu, pMemoryManager)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x19c0);
    *(undefined1 *)(param_2 + 0x5340) = 0;
    if (param_5 == '\0') goto LAB_003ed71d;
  }
  (**(code **)(param_2 + 0x1b0))(param_1,param_2);
LAB_003ed65f:
  *(undefined1 *)(param_2 + 0x5340) = uVar1;
  return iVar7;
}


// ===== 003eda50 kmigmgrInitGPUInstancePool_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrInitGPUInstancePool_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)kgmmuFmtGet_IMPL(*(undefined8 *)(param_1 + 0x1b98),0,0);
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b4b);
    return 0x1f;
  }
  if (((*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) == '\0') ||
      (*(char *)(*(long *)(param_1 + 0x1b78) + 0x436) == '\0')) ||
     (cVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968)),
     cVar1 == '\0')) {
    return 0;
  }
  if (piVar3 == (int *)0x0) {
    nvAssertFailedNoLog("pFmt != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b56);
    return 0x1f;
  }
  if (*(long *)(param_3 + 0x980) != 0) {
    iVar2 = rmMemPoolSetup(*(undefined8 *)(*(long *)(param_3 + 0x980) + 0x128),param_3 + 0x9a0,
                           *piVar3 != 1);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "rmMemPoolSetup((void*)pKernelMIGGpuInstance->pMemoryPartitionHeap->pPmaObject, &pKernelMIGGpuInstance->pPageTableMemPool, version)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b5b);
      return iVar2;
    }
    cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
    if (cVar1 == '\0') {
      return 0;
    }
    rmMemPoolAllocateProtectedMemory(*(undefined8 *)(param_3 + 0x9a0),1);
    return 0;
  }
  nvAssertFailedNoLog("pKernelMIGGpuInstance->pMemoryPartitionHeap != NULL",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",6999);
  return 0x40;
}


// ===== 003edbe0 kmigmgrInitGPUInstanceRunlistBufPools_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrInitGPUInstanceRunlistBufPools_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  long *plVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  long lVar11;
  undefined8 uVar12;
  ulong local_80;
  undefined8 *local_60;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  lVar5 = gpuGetKernelFifoShared_IMPL();
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1bb7);
    return 0x1f;
  }
  lVar1 = *(long *)(param_3 + 0x980);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pHeap != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1bba);
    return 0x40;
  }
  cVar2 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(param_3 + 0x968));
  if (cVar2 != '\0') {
    plVar7 = (long *)(lVar5 + 0x4f8);
    uVar8 = 0;
LAB_003edc88:
    uVar3 = uVar8;
    if (uVar8 != 0x53) {
LAB_003edc95:
      do {
        plVar7 = plVar7 + 1;
        uVar8 = uVar3 + 1;
        if ((*(char *)(param_1 + 0x467) == '\0') || ((9 < uVar3 - 0x35 && (0x27 < uVar3))))
        goto LAB_003edc88;
        iVar4 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,param_3,0,uVar8,0);
        uVar3 = uVar8;
      } while (iVar4 != 0);
      iVar4 = (**(code **)(lVar5 + 0x218))(param_1,lVar5,2,uVar8,3);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)rmEngineType, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1bcc);
        return iVar4;
      }
      lVar11 = *(long *)(param_1 + 0x1bc0);
      if ((((lVar11 == 0) || (*(char *)(param_1 + 0x467) == '\0')) ||
          (*(char *)(lVar11 + 0x5340) == '\0')) ||
         ((*(long *)(lVar11 + 0x5348) == 0 || (*(char *)(param_1 + 0x909) != '\0')))) {
        local_60 = (undefined8 *)portMemAllocNonPaged(0x30);
        if (local_60 == (undefined8 *)0x0) goto LAB_003edf50;
        portMemSet(local_60,0,0x30);
        local_80 = 2;
LAB_003edd54:
        uVar12 = 0;
        puVar10 = local_60;
        lVar11 = param_3;
        do {
          iVar4 = kfifoGetRunlistBufInfo_IMPL
                            (param_1,lVar5,local_4c,0,&local_48,local_40,lVar11,uVar12);
          if (iVar4 != 0) {
            uVar12 = 0x1be4;
            pcVar6 = "kfifoGetRunlistBufInfo(pGpu, pKernelFifo, runlistId, 0, &rlSize, &rlAlign)";
            goto LAB_003edddd;
          }
          puVar9 = puVar10 + 3;
          *puVar10 = local_48;
          *(undefined4 *)(puVar10 + 2) = 0;
          puVar10[1] = local_40[0];
          *(undefined1 *)((long)puVar10 + 0x14) = 1;
          puVar10 = puVar9;
        } while (local_60 + local_80 * 3 != puVar9);
      }
      else {
        iVar4 = vgpuMgrGetVmsetCountToAllocate(param_1,uVar8);
        local_60 = (undefined8 *)portMemAllocNonPaged(iVar4 * 0x30);
        if (local_60 == (undefined8 *)0x0) {
LAB_003edf50:
          nvAssertFailedNoLog("runlistBufInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c"
                              ,0x1bdb);
          return 0x51;
        }
        local_80 = (ulong)(uint)(iVar4 * 2);
        portMemSet(local_60,0,iVar4 * 0x30);
        if (iVar4 * 2 != 0) goto LAB_003edd54;
      }
      iVar4 = ctxBufPoolInit(param_1,lVar1,plVar7);
      if (iVar4 == 0) {
        if (*plVar7 == 0) {
          nvAssertOkFailedNoLog
                    (0x40,"pKernelFifo->pRunlistBufPool[rmEngineType] != NULL",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1bf3);
          portMemFree(local_60);
          return 0x40;
        }
        ctxBufPoolSetScrubSkip(*plVar7,1);
        iVar4 = ctxBufPoolReserve(param_1,*plVar7,local_60,local_80);
        if (iVar4 == 0) {
          portMemFree(local_60);
          goto LAB_003edc95;
        }
        uVar12 = 0x1bfd;
        pcVar6 = 
        "ctxBufPoolReserve(pGpu, pKernelFifo->pRunlistBufPool[rmEngineType], &runlistBufInfo[0], rlCount)"
        ;
      }
      else {
        uVar12 = 0x1bef;
        pcVar6 = "ctxBufPoolInit(pGpu, pHeap, &pKernelFifo->pRunlistBufPool[rmEngineType])";
      }
LAB_003edddd:
      nvAssertOkFailedNoLog(iVar4,pcVar6,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar12);
      portMemFree(local_60);
      return iVar4;
    }
  }
  return 0;
}


// ===== 003ee040 kmigmgrInitGPUInstanceGrBufPools_IMPL =====

/* WARNING: Type propagation algorithm not settling */

int kmigmgrInitGPUInstanceGrBufPools_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  long extraout_RDX;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long lStack_150;
  undefined1 local_138 [16];
  undefined8 local_128 [2];
  undefined8 uStack_118;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1c20);
    return 0x1f;
  }
  lVar1 = *(long *)(param_3 + 0x980);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pHeap != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1c22);
    return 0x40;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x1bc8);
  lStack_150 = param_3;
  uVar9 = 0;
  uVar11 = 0;
  do {
    while( true ) {
      iVar5 = (int)uVar11;
      cVar3 = kgrmgrIsGlobalCtxBufSupported_IMPL(uVar11,1,lStack_150);
      if (cVar3 == '\0') break;
      lStack_150 = 0x3ee0cd;
      puVar7 = (undefined8 *)kgrmgrGetGlobalCtxBufInfo_IMPL(param_1,uVar2,uVar11);
      if (puVar7 == (undefined8 *)0x0) {
        nvAssertFailedNoLog("pBufInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1c30)
        ;
        return 0x40;
      }
      local_128[uVar9 * 3] = *puVar7;
      local_128[uVar9 * 3 + 1] = puVar7[1];
      *(undefined8 *)((long)&uStack_118 + uVar9 * 0x18) = puVar7[2];
      if ((0x240UL >> (uVar11 & 0x3f) & 1) == 0) {
        if (iVar5 - 7U < 2) {
          uVar4 = *(undefined1 *)(param_1 + 0x4a23);
          *(undefined1 *)((long)&uStack_118 + uVar9 * 0x18 + 4) = uVar4;
        }
        else {
          uVar4 = *(undefined1 *)((long)&uStack_118 + uVar9 * 0x18 + 4);
        }
      }
      else {
        *(undefined1 *)((long)&uStack_118 + uVar9 * 0x18 + 4) = 1;
        uVar4 = 1;
      }
      uVar10 = (ulong)((int)uVar9 + 1);
      kgrmgrSetGlobalCtxBufInfo_IMPL
                (param_1,uVar2,uVar11,local_128[uVar9 * 3],local_128[uVar9 * 3 + 1],
                 *(undefined4 *)((long)&uStack_118 + uVar9 * 0x18),uVar4);
      uVar9 = uVar10;
      uVar11 = (ulong)(iVar5 + 1U);
      if (iVar5 + 1U == 10) goto LAB_003ee15f;
    }
    uVar11 = (ulong)(iVar5 + 1U);
    lStack_150 = extraout_RDX;
  } while (iVar5 + 1U != 10);
LAB_003ee15f:
  bitVectorCopy_IMPL(local_138,0x54,param_3 + 0x98,0x54);
  iVar5 = bitVectorCountTrailingZeros_IMPL(local_138,0x54);
  do {
    cVar3 = bitVectorTestAllCleared_IMPL(local_138,0x54);
    if (cVar3 != '\0') {
      return 0;
    }
    if (iVar5 - 1U < 8) {
      uVar2 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)(iVar5 - 1U) * 8);
      iVar6 = kgraphicsInitCtxBufPool_IMPL(param_1,uVar2,lVar1);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"kgraphicsInitCtxBufPool(pGpu, pKernelGraphics, pHeap)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1c52);
LAB_003ee26b:
        kmigmgrDestroyGPUInstanceGrBufPools_IMPL(param_1,param_2,param_3);
        return iVar6;
      }
      lVar8 = kgraphicsGetCtxBufPool_IMPL(param_1,uVar2);
      if (lVar8 == 0) {
        iVar6 = 0x40;
        goto LAB_003ee26b;
      }
      ctxBufPoolSetScrubSkip(lVar8,1);
      iVar6 = ctxBufPoolReserve(param_1,lVar8,local_128,uVar9);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"ctxBufPoolReserve(pGpu, pGrCtxBufPool, &globalCtxBufInfo[0], bufCount)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1c63);
        goto LAB_003ee26b;
      }
    }
    bitVectorClr_IMPL(local_138,0x54,iVar5);
    iVar5 = bitVectorCountTrailingZeros_IMPL(local_138,0x54);
  } while( true );
}


// ===== 003ee390 kmigmgrInitGPUInstanceBufPools_IMPL =====

ulong kmigmgrInitGPUInstanceBufPools_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint local_4c;
  long local_48;
  long local_40 [2];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_4c = 8;
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b77);
    return 0x1f;
  }
  lVar2 = *(long *)(param_3 + 0x980);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pHeap != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b79);
LAB_003ee4e0:
    uVar5 = 0x40;
  }
  else {
    cVar3 = ctxBufPoolIsSupported();
    if (cVar3 == '\0') {
      return 0;
    }
    if ((*(char *)(lVar1 + 0x434) != '\0') &&
       (iVar4 = pmaQueryConfigs(*(undefined8 *)(lVar2 + 0x128),&local_4c),
       (local_4c & 8) == 0 && iVar4 == 0)) {
      pmaGetFreeMemory(*(undefined8 *)(lVar2 + 0x128),&local_48);
      pmaGetTotalMemory(*(undefined8 *)(lVar2 + 0x128),local_40);
      if (local_48 != local_40[0]) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b92,
                     "kmigmgrInitGPUInstanceBufPools_IMPL",4,
                     "NVRM: Assumption that PMA is empty at this time is broken\n");
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b93,
                     "kmigmgrInitGPUInstanceBufPools_IMPL",4,
                     "NVRM: free space = 0x%llx bytes total space = 0x%llx bytes\n",local_48,
                     local_40[0]);
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b95,
                     "kmigmgrInitGPUInstanceBufPools_IMPL",4,
                     "NVRM: This means PMA allocations may trigger UVM evictions at this point causing deadlocks!\n"
                    );
        goto LAB_003ee4e0;
      }
    }
    uVar5 = kmigmgrInitGPUInstanceRunlistBufPools_IMPL(param_1,param_2,param_3);
    uVar6 = 0x1b9a;
    pcVar7 = "kmigmgrInitGPUInstanceRunlistBufPools(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)"
    ;
    if ((int)uVar5 == 0) {
      uVar5 = kmigmgrInitGPUInstanceGrBufPools_IMPL(param_1,param_2,param_3,0x1b9a);
      if ((int)uVar5 == 0) {
        return uVar5;
      }
      uVar6 = 0x1b9b;
      pcVar7 = "kmigmgrInitGPUInstanceGrBufPools(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)";
    }
    nvAssertOkFailedNoLog
              (uVar5 & 0xffffffff,pcVar7,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar6);
    uVar5 = uVar5 & 0xffffffff;
  }
  return uVar5;
}


// ===== 003ee5c0 kmigmgrSaveToPersistence_IMPL =====

undefined8 kmigmgrSaveToPersistence_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  uint local_64;
  long local_40 [2];
  
  local_40[0] = 0;
  cVar3 = gpumgrGetSystemMIGInstanceTopo_IMPL(*(undefined8 *)(param_1 + 0x878),local_40);
  if (cVar3 != '\0') {
    portMemSet(local_40[0] + 0x18,0,0x1c80);
    if (*(char *)(param_1 + 0x46d) != '\0') {
      gpumgrSetSystemMIGEnabled_IMPL
                (*(undefined8 *)(param_1 + 0x878),*(undefined1 *)(param_2 + 0x5340));
    }
    lVar7 = *(long *)(param_1 + 0x1bc0);
    if ((((lVar7 != 0) && (*(char *)(param_1 + 0x467) != '\0')) &&
        (*(char *)(lVar7 + 0x5340) != '\0')) && (*(long *)(lVar7 + 0x5348) != 0)) {
      lVar7 = param_2 + 0x280;
      local_64 = 0;
      do {
        while ((lVar2 = local_40[0], lVar7 != 0 && (*(char *)(lVar7 + 0x988) != '\0'))) {
          lVar9 = (ulong)local_64 * 0x390;
          lVar8 = local_40[0] + lVar9;
          *(undefined1 *)(lVar8 + 0x18) = 1;
          *(undefined4 *)(lVar8 + 0x58) = *(undefined4 *)(lVar7 + 0x968);
          *(undefined8 *)(lVar8 + 0x60) = *(undefined8 *)(lVar7 + 0x9b8);
          *(undefined4 *)(lVar8 + 0x40) = *(undefined4 *)(lVar7 + 0x96c);
          bitVectorToRaw_IMPL(lVar7 + 0x98,0x54,local_40[0] + 0x20 + lVar9,0x20);
          if (*(int *)(lVar7 + 0x88) != 0) {
            uVar6 = *(uint *)(lVar8 + 0x44);
            lVar5 = 0;
            do {
              lVar1 = lVar5 * 4;
              lVar5 = lVar5 + 1;
              uVar6 = uVar6 | 1 << ((byte)*(undefined4 *)(lVar7 + 8 + lVar1) & 0x1f);
              *(uint *)(lVar8 + 0x44) = uVar6;
            } while ((uint)lVar5 < *(uint *)(lVar7 + 0x88));
          }
          lVar8 = (ulong)local_64 * 0x390;
          *(undefined4 *)(lVar2 + 0x4c + lVar8) = *(undefined4 *)(lVar7 + 0x90);
          *(undefined4 *)(lVar2 + 0x50 + lVar8) = *(undefined4 *)(lVar7 + 0x94);
          *(undefined4 *)(lVar2 + 0x48 + lVar8) = *(undefined4 *)(lVar7 + 0xb8);
          iVar4 = kmigmgrSaveComputeInstances_IMPL(param_1,param_2,lVar7,lVar2 + 0x68 + lVar9);
          if (iVar4 != 0) {
            nvAssertOkFailedNoLog
                      (0x1f,
                       "kmigmgrSaveComputeInstances(pGpu, pKernelMIGManager, pKernelMIGGPUInstance, pGPUInstanceSave->saveCI)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ca3);
            return 0x1f;
          }
          lVar7 = lVar7 + 0xa18;
          local_64 = local_64 + 1;
          if (param_2 + 0x5340 == lVar7) {
            return 0;
          }
        }
        lVar7 = lVar7 + 0xa18;
      } while (param_2 + 0x5340 != lVar7);
    }
  }
  return 0;
}


// ===== 003ee830 __pfx_subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL =====

undefined8 __pfx_subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  char cVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1bc0);
  *(undefined4 *)(param_2 + 0x24) = 0;
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4)), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d33);
    return 0x2f;
  }
  if ((lVar3 == 0) || (*(char *)(lVar2 + 0x467) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d38,
                 "subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL",1,
                 "NVRM: MIG not supported on this GPU.\n");
  }
  else {
    if ((*(long *)(lVar2 + 0x1bc0) != 0) && (*(char *)(*(long *)(lVar2 + 0x1bc0) + 0x5340) != '\0'))
    {
      uVar1 = *(uint *)(param_2 + 0x24);
      uVar9 = uVar1 + 1;
      *(uint *)(param_2 + 0x24) = uVar9;
      *(undefined4 *)(param_2 + (ulong)uVar1 * 4) = 0xfffffffe;
      uVar8 = *(ulong *)(lVar3 + 0x5348);
      if (uVar8 != 0) {
        do {
          uVar7 = (ulong)uVar9;
          uVar9 = uVar9 + 1;
          iVar4 = 0;
          for (uVar5 = uVar8; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x8000000000000000) {
            iVar4 = iVar4 + 1;
          }
          *(int *)(param_2 + uVar7 * 4) = iVar4;
          uVar8 = uVar8 & ~(1L << ((byte)iVar4 & 0x3f));
        } while (uVar8 != 0);
        *(uint *)(param_2 + 0x24) = uVar9;
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d3e,
                 "subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL",1,
                 "NVRM: MIG Mode has not been turned on.\n");
  }
  return 0x56;
}


// ===== 003ee840 subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  char cVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1bc0);
  *(undefined4 *)(param_2 + 0x24) = 0;
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4)), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d33);
    return 0x2f;
  }
  if ((lVar3 == 0) || (*(char *)(lVar2 + 0x467) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d38,
                 "subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL",1,
                 "NVRM: MIG not supported on this GPU.\n");
  }
  else {
    if ((*(long *)(lVar2 + 0x1bc0) != 0) && (*(char *)(*(long *)(lVar2 + 0x1bc0) + 0x5340) != '\0'))
    {
      uVar1 = *(uint *)(param_2 + 0x24);
      uVar9 = uVar1 + 1;
      *(uint *)(param_2 + 0x24) = uVar9;
      *(undefined4 *)(param_2 + (ulong)uVar1 * 4) = 0xfffffffe;
      uVar8 = *(ulong *)(lVar3 + 0x5348);
      if (uVar8 != 0) {
        do {
          uVar7 = (ulong)uVar9;
          uVar9 = uVar9 + 1;
          iVar4 = 0;
          for (uVar5 = uVar8; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x8000000000000000) {
            iVar4 = iVar4 + 1;
          }
          *(int *)(param_2 + uVar7 * 4) = iVar4;
          uVar8 = uVar8 & ~(1L << ((byte)iVar4 & 0x3f));
        } while (uVar8 != 0);
        *(uint *)(param_2 + 0x24) = uVar9;
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d3e,
                 "subdeviceCtrlCmdGpuGetActivePartitionIds_IMPL",1,
                 "NVRM: MIG Mode has not been turned on.\n");
  }
  return 0x56;
}


// ===== 003ee9d0 subdeviceCtrlCmdGpuGetPartitionCapacity_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 subdeviceCtrlCmdGpuGetPartitionCapacity_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1bc0);
  lVar4 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d64);
    return 0x23;
  }
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d66);
    return 0x2f;
  }
  if (*(char *)(lVar1 + 0x467) == '\0') {
    nvCheckFailedNoLog(1,"kmigmgrIsMIGSupported(pGpu, pKernelMIGManager)",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1d68);
    return 0x56;
  }
  if (*(char *)(lVar1 + 0x908) != '\0') {
    if ((char)param_2[0x45] == '\0') {
      lVar5 = resservGetTlsCallContext();
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                            0x1d74);
        return 0x40;
      }
      cVar3 = rmclientIsCapableOrAdmin_IMPL(lVar4,2,*(undefined4 *)(lVar5 + 0x28));
      if (cVar3 == '\0') {
        return 0x1b;
      }
      cVar3 = (**(code **)(lVar2 + 0x1f0))(lVar1,lVar2,*param_2);
      uVar6 = *param_2;
      if (((cVar3 == '\0') || ((uVar6 & 0x1c) != 0)) ||
         ((lVar4 = *(long *)(lVar1 + 0x1bc0), lVar4 != 0 &&
          (((*(char *)(lVar1 + 0x467) != '\0' && (*(char *)(lVar4 + 0x5340) != '\0')) &&
           (*(long *)(lVar4 + 0x5348) != 0)))))) {
        param_2[1] = 0;
        param_2[0x22] = 0;
      }
      else {
        param_2[1] = 1;
        param_2[0x22] = 1;
        param_2[2] = 1;
        param_2[3] = 0;
        param_2[4] = 0;
        param_2[5] = 0;
      }
    }
    else {
      uVar6 = *param_2;
    }
    cVar3 = (**(code **)(lVar2 + 0x1f0))(lVar1,lVar2,uVar6);
    if ((cVar3 != '\0') && ((*param_2 & 0x1c) == 0)) {
      param_2[0x23] = 1;
      param_2[0x44] = 1;
      param_2[0x24] = 1;
      param_2[0x25] = 0;
      param_2[0x26] = 0;
      param_2[0x27] = 0;
      return 0;
    }
    param_2[0x23] = 0;
    param_2[0x44] = 0;
    return 0;
  }
  return 0x56;
}


// ===== 003eeca0 subdeviceCtrlCmdGpuDescribePartitions_IMPL =====

undefined8 subdeviceCtrlCmdGpuDescribePartitions_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      if (*(char *)(lVar1 + 0x467) != '\0') {
        uVar3 = kmigmgrDescribeGPUInstances_IMPL(lVar1,uVar3,param_2);
        return uVar3;
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1dbd,
                   "subdeviceCtrlCmdGpuDescribePartitions_IMPL",1,
                   "NVRM: MIG not supported on this GPU.\n");
      return 0x56;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1db9);
  return 0x2f;
}


// ===== 003eed70 subdeviceCtrlCmdGpuSetPartitioningMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdGpuSetPartitioningMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  ulong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1bc0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1dd4);
    return 0x2f;
  }
  if (*(char *)(lVar1 + 0x908) != '\0') {
    return 0x56;
  }
  if ((lVar2 != 0) && (*(char *)(lVar1 + 0x467) != '\0')) {
    uVar4 = (**(code **)(lVar1 + 0x3b90))
                      (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                       *(undefined4 *)(lVar1 + 0x3b3c),0x20800aa3,param_2,4);
    uVar6 = 0x1de1;
    pcVar5 = 
    "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_PARTITIONING_MODE, pParams, sizeof(*pParams))"
    ;
    if ((int)uVar4 == 0) {
      uVar4 = kmigmgrSetPartitioningMode_IMPL
                        (lVar1,lVar2,
                         "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_PARTITIONING_MODE, pParams, sizeof(*pParams))"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1de1);
      uVar6 = 0x1de9;
      pcVar5 = "kmigmgrSetPartitioningMode(pGpu, pKernelMIGManager)";
      if ((int)uVar4 == 0) {
        uVar4 = (**(code **)(lVar2 + 0x1e0))
                          (lVar1,lVar2,"kmigmgrSetPartitioningMode(pGpu, pKernelMIGManager)",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1de9);
        if ((int)uVar4 == 0) {
          return uVar4;
        }
        uVar6 = 0x1dec;
        pcVar5 = "kmigmgrConfigurePMSettings_HAL(pGpu, pKernelMIGManager)";
      }
    }
    nvCheckOkFailedNoLog
              (4,uVar4 & 0xffffffff,pcVar5,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar6);
    return uVar4 & 0xffffffff;
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ddd,
               "subdeviceCtrlCmdGpuSetPartitioningMode_IMPL",1,
               "NVRM: MIG not supported on this GPU.\n");
  return 0x56;
}


// ===== 003eef10 subdeviceCtrlCmdGpuGetPartitions_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGpuGetPartitions_IMPL(long param_1,int *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int *piVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  int *piVar15;
  byte local_90;
  ulong local_88;
  int *local_80;
  uint local_6c;
  long local_58 [2];
  undefined1 local_48 [24];
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1bc0);
  lVar7 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ee9);
    return 0x23;
  }
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') ||
     (cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4)), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ef0);
    return 0x2f;
  }
  piVar8 = (int *)portMemAllocNonPaged(0x748);
  if (piVar8 == (int *)0x0) {
    nvCheckFailedNoLog(1,"pRpcParams != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ef4);
    return 0x51;
  }
  memcpy(piVar8,param_2,0x748);
  if (*(char *)(lVar2 + 0x908) == '\0') {
    lVar9 = resservGetTlsCallContext();
    iVar5 = (**(code **)(lVar2 + 0x3b90))
                      (lVar2 + 0x3b58,**(undefined4 **)(lVar9 + 0x48),
                       (*(undefined4 **)(lVar9 + 0x48))[1],0x20800aa6,piVar8,0x748);
    if (iVar5 != 0) {
      nvCheckOkFailedNoLog
                (3,iVar5,
                 "pRmApi->Control(pRmApi, pRmCtrlParams->hClient, pRmCtrlParams->hObject, NV2080_CTRL_CMD_INTERNAL_MIGMGR_GET_GPU_INSTANCES, pRpcParams, sizeof(*pRpcParams))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1eff);
      goto LAB_003ef12d;
    }
  }
  if (*(char *)(lVar2 + 0x467) == '\0') {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f0a,
                 "subdeviceCtrlCmdGpuGetPartitions_IMPL",1,"NVRM: MIG not supported on this GPU.\n")
    ;
    iVar5 = 0x56;
    goto LAB_003ef12d;
  }
  lVar9 = *(long *)(lVar2 + 0x1bc0);
  if ((lVar9 == 0) || (*(char *)(lVar9 + 0x5340) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f10,
                 "subdeviceCtrlCmdGpuGetPartitions_IMPL",1,
                 "NVRM: Entered MIG API with MIG disabled.\n");
    lVar9 = *(long *)(lVar2 + 0x1bc0);
    if ((lVar9 != 0) && ((*(char *)(lVar2 + 0x467) != '\0' && (*(char *)(lVar9 + 0x5340) != '\0'))))
    goto LAB_003eeffd;
LAB_003ef120:
    param_2[0x1d0] = 0;
  }
  else {
LAB_003eeffd:
    if (*(long *)(lVar9 + 0x5348) == 0) goto LAB_003ef120;
    if ((char)param_2[0x1d1] == '\0') {
      local_58[0] = 0;
      iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL
                        (lVar2,lVar3,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),local_58);
      if (iVar5 != 0) goto LAB_003ef120;
      uVar1 = *(undefined4 *)(local_58[0] + 0x968);
      param_2[0x1d0] = 0;
      local_88 = 1L << ((byte)uVar1 & 0x3f);
    }
    else {
      lVar9 = resservGetTlsCallContext();
      if (lVar9 == 0) {
        nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                            0x1f1f);
LAB_003ef766:
        iVar5 = 0x40;
        goto LAB_003ef12d;
      }
      cVar4 = rmclientIsCapableOrAdmin_IMPL(lVar7,2,*(undefined4 *)(lVar9 + 0x28));
      if (cVar4 == '\0') {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f26,
                     "subdeviceCtrlCmdGpuGetPartitions_IMPL",4,
                     "NVRM: Non privileged client requesting global gpu instance info\n");
        iVar5 = 0x1b;
        goto LAB_003ef12d;
      }
      iVar5 = 0x40;
      local_88 = *(ulong *)(lVar3 + 0x5348);
      param_2[0x1d0] = 0;
      if (local_88 == 0) {
LAB_003ef064:
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f49,
                     "subdeviceCtrlCmdGpuGetPartitions_IMPL",4,
                     "NVRM: Unable to get gpu instance info for swizzId - %d\n",iVar5);
        iVar5 = 0x1f;
        goto LAB_003ef12d;
      }
    }
    local_6c = 0;
    piVar15 = param_2;
    local_80 = piVar8;
    do {
      iVar5 = 0;
      for (uVar13 = local_88; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1 | 0x8000000000000000) {
        iVar5 = iVar5 + 1;
      }
      if (0xe < iVar5) goto LAB_003ef064;
      uVar13 = 0;
      lVar7 = lVar3 + 0x280;
      while (((lVar7 == 0 || (*(char *)(lVar7 + 0x988) == '\0')) ||
             (iVar5 != *(int *)(lVar7 + 0x968)))) {
        uVar12 = (int)uVar13 + 1;
        uVar13 = (ulong)uVar12;
        lVar7 = lVar7 + 0xa18;
        if (uVar12 == 8) goto LAB_003ef064;
      }
      lVar11 = uVar13 * 0xa18 + lVar3;
      lVar9 = lVar7 + 0x98;
      piVar15[1] = *(int *)(lVar11 + 0xbec);
      *piVar15 = *(int *)(lVar11 + 0xbe8);
      iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,1,8);
      piVar15[2] = iVar6;
      piVar15[4] = *(int *)(*(long *)(lVar11 + 0x280) + 0x1c);
      piVar15[3] = *(int *)(lVar7 + 0x94);
      if (*(char *)(lVar2 + 0x469) == '\0') {
        iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,9,0x1c);
      }
      else {
        uVar10 = (**(code **)(lVar3 + 0x170))(lVar2);
        iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,uVar10);
      }
      piVar15[5] = iVar6;
      piVar15[10] = *(int *)(lVar7 + 0x88);
      piVar15[0xc] = *(int *)(lVar7 + 0x8c);
      piVar15[0xb] = *(int *)(lVar7 + 0xb8);
      iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,0x1d,0x24);
      piVar15[7] = iVar6;
      iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,0x25,0x28);
      piVar15[6] = iVar6;
      iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,0x36,0x3d);
      piVar15[8] = iVar6;
      iVar6 = kmigmgrCountEnginesInRange_IMPL(lVar9,0x3e,0x3f);
      lVar11 = uVar13 * 0xa18 + lVar3;
      piVar15[9] = iVar6;
      lVar7 = (*(ulong *)(lVar11 + 0xc18) + 1) - *(ulong *)(lVar11 + 0xc10);
      if (*(ulong *)(lVar11 + 0xc18) < *(ulong *)(lVar11 + 0xc10)) {
        lVar7 = 0;
      }
      *(long *)(piVar15 + 0x2e) = lVar7;
      *(undefined8 *)(piVar15 + 0x36) = *(undefined8 *)(*(long *)(lVar11 + 0x280) + 0x38);
      uVar10 = *(undefined8 *)(*(long *)(lVar11 + 0x280) + 0x40);
      *(undefined1 *)(piVar15 + 0x34) = 1;
      *(undefined8 *)(piVar15 + 0x38) = uVar10;
      if (*(char *)(lVar2 + 0x908) == '\0') {
        if ((char)local_80[0x34] == '\0') {
          nvAssertFailedNoLog("pRpcParams->queryPartitionInfo[i].bValid",
                              "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f95);
          goto LAB_003ef766;
        }
        if (*piVar15 != *local_80) {
          nvAssertFailedNoLog("pParams->queryPartitionInfo[i].swizzId == pRpcParams->queryPartitionInfo[i].swizzId"
                              ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f97);
          goto LAB_003ef766;
        }
        bitVectorCopy_IMPL(local_48,0x54,lVar9,0x54);
        iVar6 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
        uVar13 = 0;
        while (cVar4 = bitVectorTestAllCleared_IMPL(local_48,0x54), cVar4 == '\0') {
          uVar14 = uVar13;
          if (iVar6 - 1U < 8) {
            uVar14 = (ulong)((int)uVar13 + 1);
            lVar7 = uVar13 + (ulong)local_6c * 0x3a;
            param_2[lVar7 + 0xd] = piVar8[lVar7 + 0xd];
            param_2[lVar7 + 0x1d] = piVar8[lVar7 + 0x1d];
            param_2[lVar7 + 0x25] = piVar8[lVar7 + 0x25];
            param_2[lVar7 + 0x15] = piVar8[lVar7 + 0x15];
          }
          bitVectorClr_IMPL(local_48,0x54,iVar6);
          iVar6 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
          uVar13 = uVar14;
        }
        *(undefined1 *)((long)piVar15 + 0xd1) = *(undefined1 *)((long)local_80 + 0xd1);
        uVar10 = *(undefined8 *)(local_80 + 0x32);
        *(undefined8 *)(piVar15 + 0x30) = *(undefined8 *)(local_80 + 0x30);
        *(undefined8 *)(piVar15 + 0x32) = uVar10;
      }
      else {
        lVar7 = gpuGetStaticInfo(lVar2);
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1f7b);
          iVar5 = 0x57;
          goto LAB_003ef12d;
        }
        *(undefined1 *)((long)piVar15 + 0xd1) = 0;
        piVar15[0x30] = 1;
        piVar15[0x31] = 0;
        piVar15[0x32] = 0;
        piVar15[0x33] = 0;
        bitVectorCopy_IMPL(local_48,0x54,lVar9,0x54);
        iVar6 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
        uVar13 = 0;
        while (cVar4 = bitVectorTestAllCleared_IMPL(local_48,0x54), cVar4 == '\0') {
          uVar14 = uVar13;
          if (iVar6 - 1U < 8) {
            uVar14 = (ulong)((int)uVar13 + 1);
            lVar9 = lVar7 + uVar13 * 4;
            lVar11 = uVar13 + (ulong)local_6c * 0x3a;
            param_2[lVar11 + 0xd] = *(int *)(lVar9 + 0xa7ec);
            param_2[lVar11 + 0x25] = *(int *)(lVar9 + 0xa84c);
            param_2[lVar11 + 0x15] = *(int *)(lVar9 + 0xa80c);
            param_2[lVar11 + 0x1d] = *(int *)(lVar9 + 0xa82c);
          }
          bitVectorClr_IMPL(local_48,0x54,iVar6);
          iVar6 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
          uVar13 = uVar14;
        }
      }
      local_90 = (byte)iVar5;
      param_2[0x1d0] = param_2[0x1d0] + 1;
      local_88 = local_88 &
                 (-2L << (local_90 & 0x3f) | 0xfffffffffffffffeU >> 0x40 - (local_90 & 0x3f));
      if (local_88 == 0) break;
      local_6c = local_6c + 1;
      piVar15 = piVar15 + 0x3a;
      local_80 = local_80 + 0x3a;
    } while (local_6c != 8);
  }
  iVar5 = 0;
LAB_003ef12d:
  portMemFree(piVar8);
  return iVar5;
}


// ===== 003ef7e0 subdeviceCtrlCmdInternalKMIGmgrExportGPUInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdInternalKMIGmgrExportGPUInstance_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = resservGetTlsCallContext();
  lVar5 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1fca);
    return 0x23;
  }
  if ((((lVar1 != 0) && (lVar2 = *(long *)(lVar1 + 0x1bc0), lVar2 != 0)) &&
      (*(char *)(lVar1 + 0x467) != '\0')) &&
     ((*(char *)(lVar2 + 0x5340) != '\0' && (*(long *)(lVar2 + 0x5348) != 0)))) {
    cVar3 = rmclientIsCapableOrAdmin_IMPL(lVar5,2,*(undefined4 *)(lVar4 + 0x28));
    if (cVar3 == '\0') {
      return 0x1b;
    }
    if (*(char *)(lVar1 + 0x908) == '\0') {
      uVar6 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                         *(undefined4 *)(lVar1 + 0x3b3c),0x20800aa8,param_2,0x50);
      if ((int)uVar6 == 0) {
        return uVar6;
      }
      nvCheckOkFailedNoLog
                (4,uVar6 & 0xffffffff,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_EXPORT_GPU_INSTANCE, pParams, sizeof(*pParams))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1fde);
      return uVar6 & 0xffffffff;
    }
  }
  return 0x56;
}


// ===== 003ef940 kmigmgrGetGpuProfileFromFlag_IMPL =====

undefined8
kmigmgrGetGpuProfileFromFlag_IMPL(undefined8 param_1,long param_2,uint param_3,undefined8 param_4)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  ulong uVar4;
  uint *puVar5;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    puVar2 = *(uint **)(pcVar1 + 8);
    uVar4 = 0;
    puVar5 = puVar2 + 2;
    if (*puVar2 != 0) {
      do {
        if (*puVar5 == param_3) {
          portMemCopy(param_4,0x48,puVar2 + uVar4 * 0x12 + 2,0x48);
          return 0;
        }
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulong)uVar3;
        puVar5 = puVar5 + 0x12;
      } while (uVar3 != *puVar2);
    }
    return 0x57;
  }
  nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2062);
  return 0x40;
}


// ===== 003ef9d0 kmigmgrGetNextComputeSize_IMPL =====

uint kmigmgrGetNextComputeSize_IMPL(undefined8 param_1,undefined8 param_2,char param_3,uint param_4)

{
  long lVar1;
  uint local_28 [8];
  
  local_28[2] = 1;
  local_28[3] = 2;
  local_28[4] = 3;
  local_28[5] = 4;
  local_28[0] = 8;
  local_28[1] = 0;
  local_28[6] = 5;
  local_28[7] = 8;
  if (param_4 < 9) {
    lVar1 = 1;
    if (param_4 == 8) {
      return -(uint)(param_3 == '\0') & 5;
    }
    do {
      if (local_28[lVar1] == param_4) {
        if (param_3 == '\0') {
          return local_28[(int)lVar1 - 1];
        }
        return local_28[(int)lVar1 + 1];
      }
      lVar1 = lVar1 + 1;
    } while (lVar1 != 7);
  }
  else {
    nvAssertFailedNoLog("computeSize <= KMIGMGR_COMPUTE_SIZE_INVALID",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2112);
  }
  return 8;
}


// ===== 003efa90 kmigmgrGetSkylineFromSize_IMPL =====

undefined8 kmigmgrGetSkylineFromSize_IMPL(undefined8 param_1,long param_2,int param_3,long *param_4)

{
  char *pcVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  int *piVar5;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    if (param_4 == (long *)0x0) goto LAB_003efb68;
    nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x213b)
    ;
  }
  else {
    if (param_4 == (long *)0x0) {
LAB_003efb68:
      nvAssertFailedNoLog("ppSkyline != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x213a);
      return 0x1f;
    }
    lVar2 = *(long *)(pcVar1 + 0x30);
    if (lVar2 == 0) {
      nvCheckFailedNoLog(3,"pStaticInfo->pSkylineInfo != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x213c);
    }
    else {
      piVar5 = (int *)(lVar2 + 0x28);
      uVar4 = 0;
      if (*(uint *)(lVar2 + 0x1b0) != 0) {
        do {
          if (*piVar5 == param_3) {
            *param_4 = lVar2 + uVar4 * 0x30;
            return 0;
          }
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulong)uVar3;
          piVar5 = piVar5 + 0xc;
        } while (*(uint *)(lVar2 + 0x1b0) != uVar3);
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2146,
                   "kmigmgrGetSkylineFromSize_IMPL",1,"NVRM: No skyline for with compute size %d\n",
                   param_3);
    }
  }
  return 0x57;
}


// ===== 003efbc0 kmigmgrGetComputeProfileFromSize_IMPL =====

undefined8
kmigmgrGetComputeProfileFromSize_IMPL(undefined8 param_1,long param_2,uint param_3,long param_4)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  ulong uVar4;
  uint *puVar5;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    if (param_4 == 0) goto LAB_003efcb8;
    nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2160)
    ;
  }
  else {
    if (param_4 == 0) {
LAB_003efcb8:
      nvAssertFailedNoLog("pProfile != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x215f);
      return 0x1f;
    }
    puVar2 = *(uint **)(pcVar1 + 0x28);
    if (puVar2 == (uint *)0x0) {
      nvCheckFailedNoLog(3,"pStaticInfo->pCIProfiles != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2161);
    }
    else {
      puVar5 = puVar2 + 1;
      uVar4 = 0;
      if (*puVar2 != 0) {
        do {
          if ((byte)*puVar5 == param_3) {
            portMemCopy(param_4,0x18,puVar2 + uVar4 * 6 + 1,0x18);
            return 0;
          }
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulong)uVar3;
          puVar5 = puVar5 + 6;
        } while (*puVar2 != uVar3);
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x216b,
                   "kmigmgrGetComputeProfileFromSize_IMPL",1,
                   "NVRM: Found no Compute Profile for computeSize=%d\n",param_3);
    }
  }
  return 0x57;
}


// ===== 003efd20 kmigmgrGetComputeProfileFromSmCount_IMPL =====

undefined8
kmigmgrGetComputeProfileFromSmCount_IMPL(undefined8 param_1,long param_2,uint param_3,long param_4)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  pcVar2 = *(char **)(param_2 + 0x278);
  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
    if (param_3 != 0) {
      if (param_4 != 0) {
        nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                           0x2188);
        return 0x57;
      }
      goto LAB_003efe90;
    }
  }
  else if (param_3 != 0) {
    if (param_4 != 0) {
      puVar3 = *(uint **)(pcVar2 + 0x28);
      if (puVar3 == (uint *)0x0) {
        nvCheckFailedNoLog(3,"pStaticInfo->pCIProfiles != NULL",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2189);
        return 0x57;
      }
      uVar1 = *puVar3;
      if (0x1f < uVar1) {
        nvAssertFailedNoLog("pStaticInfo->pCIProfiles->profileCount < 32",
                            "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x218c);
        return 0x40;
      }
      puVar6 = puVar3 + 5;
      uVar5 = 0;
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          if (*puVar6 == param_3) {
            uVar4 = uVar4 | 1 << (uVar5 & 0x1f);
          }
          uVar5 = uVar5 + 1;
          puVar6 = puVar6 + 6;
        } while (uVar5 != uVar1);
        if (uVar4 != 0) {
          uVar1 = 0;
          for (uVar5 = uVar4; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
            uVar1 = uVar1 + 1;
          }
          uVar5 = uVar4 - (uVar4 >> 1 & 0x55555555);
          uVar5 = (uVar5 & 0x33333333) + (uVar5 >> 2 & 0x33333333);
          if (0x1ffffff < ((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101) {
            puVar6 = puVar3;
            do {
              puVar6 = puVar6 + 6;
              if ((uVar4 & 1) != 0) {
                if (*puVar6 != puVar3[(ulong)uVar1 * 6 + 6]) {
                  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x21aa,
                               "kmigmgrGetComputeProfileFromSmCount_IMPL",3,
                               "NVRM: Profiles aliased. Falling back to GPC look-up\n");
                  return 0x57;
                }
                if (uVar4 >> 1 == 0) break;
              }
              uVar4 = uVar4 >> 1;
            } while( true );
          }
          portMemCopy(param_4,0x18,puVar3 + (ulong)uVar1 * 6 + 1,0x18);
          return 0;
        }
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x219a,
                   "kmigmgrGetComputeProfileFromSmCount_IMPL",4,
                   "NVRM: Found no Compute Profile for smCount=%d\n",param_3);
      return 0x57;
    }
LAB_003efe90:
    nvAssertFailedNoLog("pProfile != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2187);
    return 0x1f;
  }
  nvCheckFailedNoLog(3,"smCount != 0","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2186);
  return 0x57;
}


// ===== 003eff60 kmigmgrGetComputeProfileFromGpcCount_IMPL =====

undefined8
kmigmgrGetComputeProfileFromGpcCount_IMPL(long param_1,long param_2,uint param_3,long param_4)

{
  char *pcVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char cVar7;
  
  pcVar1 = *(char **)(param_2 + 0x278);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    if (param_4 == 0) goto LAB_003f0170;
    nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x21d4)
    ;
  }
  else {
    if (param_4 == 0) {
LAB_003f0170:
      nvAssertFailedNoLog("pProfile != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x21d3);
      return 0x1f;
    }
    puVar6 = *(uint **)(pcVar1 + 0x28);
    if (puVar6 == (uint *)0x0) {
      nvCheckFailedNoLog(3,"pStaticInfo->pCIProfiles != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x21d5);
    }
    else {
      lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
      uVar4 = *(uint *)(lVar2 + 0x1ac);
      uVar3 = *(uint *)(lVar2 + 0x1b4);
      if (*(char *)(param_2 + 0x270) != '\0') {
        uVar3 = uVar3 >> 1;
      }
      if (((uVar3 >> 3 < param_3) || (cVar7 = '\x05', uVar4 < 8)) &&
         ((uVar3 >> 2 < param_3 || (cVar7 = '\x03', uVar4 < 4)))) {
        uVar3 = uVar3 >> 1;
        if (uVar3 - 1 < param_3) {
          cVar7 = 1 < uVar4 && param_3 <= uVar3;
        }
        else {
          cVar7 = '\x02';
          if (uVar4 - 2 < 2) {
            cVar7 = param_3 <= uVar3;
          }
        }
      }
      if (*puVar6 != 0) {
        puVar5 = puVar6 + 1;
        uVar4 = 0;
        do {
          if ((char)*puVar5 == cVar7) {
            if (puVar6[(ulong)uVar4 * 6 + 3] != param_3) {
              nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x21ed,
                           "kmigmgrGetComputeProfileFromGpcCount_IMPL",1,
                           "NVRM: GPC count %d doesn\'t match compute size %d \n",param_3,cVar7);
              puVar6 = *(uint **)(pcVar1 + 0x28);
            }
            portMemCopy(param_4,0x18,puVar6 + (ulong)uVar4 * 6 + 1,0x18);
            return 0;
          }
          uVar4 = uVar4 + 1;
          puVar5 = puVar5 + 6;
        } while (uVar4 != *puVar6);
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x21f4,
                   "kmigmgrGetComputeProfileFromGpcCount_IMPL",1,
                   "NVRM: Found no Compute Profile for gpcCount=%d\n");
    }
  }
  return 0x57;
}


// ===== 003f01c0 kmigmgrComputeProfileSizeToCTSIdRange_IMPL =====

char kmigmgrComputeProfileSizeToCTSIdRange_IMPL(uint param_1)

{
  char cVar1;
  
  if (param_1 == 3) {
    return '\x05';
  }
  if (3 < param_1) {
    if (param_1 == 4) {
      return '\t';
    }
    cVar1 = '\r';
    if (param_1 != 5) {
      cVar1 = '\x01';
    }
    return cVar1;
  }
  if (param_1 == 1) {
    return '\x01';
  }
  return (param_1 == 2) * '\x03';
}


// ===== 003f0280 kmigmgrGetFreeCTSId_IMPL =====

undefined8
kmigmgrGetFreeCTSId_IMPL
          (long param_1,long param_2,int *param_3,ulong param_4,ulong param_5,ulong param_6,
          undefined4 param_7,char param_8,char param_9)

{
  long lVar1;
  ulong uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  ulong *puVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  undefined1 auVar10 [16];
  ulong local_78 [7];
  undefined *local_40;
  ulong local_38;
  
  auVar10 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(param_7);
  if (auVar10._8_8_ < auVar10._0_8_) {
    nvCheckFailedNoLog(3,"!rangeIsEmpty(ctsRange)","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                       0x22f5);
    return 0x1a;
  }
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pCtsId != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x22f6);
    return 0x1f;
  }
  bVar4 = 0;
  if (param_6 != 0) {
    while( true ) {
      for (; (param_6 & 1) == 0; param_6 = param_6 >> 1) {
        bVar4 = bVar4 + 1;
      }
      local_78[0] = 0x222b;
      puVar6 = local_78;
      uVar8 = 0xffffffffffe00000;
      local_78[1] = 0x422b;
      local_78[2] = 0x844b;
      local_78[3] = 0x1044b;
      local_78[4] = 0x20895;
      local_78[5] = 0x40895;
      local_78[6] = 0x81115;
      local_40 = &DAT_00101115;
      do {
        uVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        uVar8 = uVar8 | -(ulong)((uint)(uVar9 >> (bVar4 & 0x3f)) & 1) & uVar9;
      } while (&local_38 != puVar6);
      param_4 = param_4 & ~uVar8;
      param_6 = param_6 >> 1;
      if (param_6 == 0) break;
      bVar4 = bVar4 + 1;
    }
  }
  bVar4 = auVar10[0] & 0x3f;
  uVar8 = (0xffffffffffffffffU >> ((~auVar10[8] & 0x3f) + bVar4 & 0x3f)) << bVar4 & param_4;
  if (param_8 != '\0') {
    if (param_9 == '\0') {
      uVar9 = ~param_5 & uVar8;
      if (uVar9 != 0) goto LAB_003f03bd;
    }
    else {
      uVar8 = uVar8 & param_5;
    }
  }
  uVar9 = uVar8;
  if (uVar9 == 0) {
    return 0x1a;
  }
LAB_003f03bd:
  if (*(char *)(*(long *)(param_1 + 0x1bc8) + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2322);
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
    if (lVar1 != 0) {
      if (((*(int *)(lVar1 + 0x19c) == 1) && (param_8 != '\0')) &&
         (*(char *)(param_2 + 0x5380) != '\0')) {
        lVar1 = 0x3f;
        if (uVar9 != 0) {
          for (; uVar9 >> lVar1 == 0; lVar1 = lVar1 + -1) {
          }
        }
        *param_3 = (int)lVar1;
      }
      else {
        iVar5 = 0;
        bVar4 = 0;
        iVar7 = 0;
        for (uVar8 = uVar9; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x8000000000000000) {
          iVar7 = iVar7 + 1;
        }
        while( true ) {
          for (; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1) {
            iVar5 = iVar5 + 1;
          }
          local_78[0] = 0x222b;
          puVar6 = local_78;
          uVar8 = 0xffffffffffe00000;
          local_78[1] = 0x422b;
          local_78[2] = 0x844b;
          local_78[3] = 0x1044b;
          local_78[4] = 0x20895;
          local_78[5] = 0x40895;
          local_78[6] = 0x81115;
          local_40 = &DAT_00101115;
          do {
            uVar2 = *puVar6;
            puVar6 = puVar6 + 1;
            uVar8 = uVar8 | -(ulong)((uint)(uVar2 >> ((byte)iVar5 & 0x3f)) & 1) & uVar2;
          } while (puVar6 != &local_38);
          uVar8 = (~uVar8 & param_4) - ((~uVar8 & param_4) >> 1 & 0x5555555555555555);
          uVar8 = (uVar8 & 0x3333333333333333) + (uVar8 >> 2 & 0x3333333333333333);
          bVar3 = (byte)((uVar8 + (uVar8 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38);
          if (bVar4 < bVar3) {
            iVar7 = iVar5;
            bVar4 = bVar3;
          }
          uVar9 = uVar9 >> 1;
          if (uVar9 == 0) break;
          iVar5 = iVar5 + 1;
        }
        *param_3 = iVar7;
      }
      return 0;
    }
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                        ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2323);
  }
  return 0x40;
}


// ===== 003f0640 kmigmgrIsCTSAlignmentRequired_PF =====

bool kmigmgrIsCTSAlignmentRequired_PF(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_10 [8];
  
  iVar1 = kmigmgrGetSkylineFromSize_IMPL(param_1,param_2,4,local_10);
  return iVar1 == 0;
}


// ===== 003f0670 kmigmgrIsCTSAlignmentRequired_VF =====

bool kmigmgrIsCTSAlignmentRequired_VF(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_20 [24];
  
  iVar1 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,4,local_20);
  return iVar1 == 0;
}


// ===== 003f06a0 kmigmgrGetComputeSizeFromCTSId_IMPL =====

int kmigmgrGetComputeSizeFromCTSId_IMPL(long param_1,uint param_2)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auVar4 [16];
  
  iVar3 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
  while( true ) {
    auVar4 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(iVar3,uVar1);
    iVar2 = kmigmgrGetComputeProfileFromSize_IMPL(param_1);
    if (((iVar2 == 0) && (auVar4._0_8_ <= (ulong)param_2)) && ((ulong)param_2 <= auVar4._8_8_))
    break;
    iVar3 = kmigmgrGetNextComputeSize_IMPL(param_1,uVar1,1,iVar3);
    if (iVar3 == 8) {
      return 8;
    }
  }
  return iVar3;
}


// ===== 003f0730 kmigmgrSmallestComputeProfileSize_IMPL =====

int kmigmgrSmallestComputeProfileSize_IMPL(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_40 [32];
  
  iVar2 = 5;
  do {
    iVar1 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,iVar2,local_40);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = kmigmgrGetNextComputeSize_IMPL(param_1,param_2,0,iVar2);
  } while (iVar2 != 8);
  return 8;
}


// ===== 003f0790 kmigmgrSetCTSIdInUse_IMPL =====

void kmigmgrSetCTSIdInUse_IMPL(long param_1,int param_2,uint param_3,char param_4)

{
  int iVar1;
  byte bVar2;
  long lVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23b7);
    return;
  }
  if (param_4 != '\0') {
    *(int *)(param_1 + 0x9e0 + (ulong)param_3 * 4) = param_2;
    if (param_2 != -1) {
      *(ulong *)(param_1 + 0x9d8) = *(ulong *)(param_1 + 0x9d8) | 1L << ((byte)param_2 & 0x3f);
      return;
    }
    nvAssertFailedNoLog("ctsId != KMIGMGR_CTSID_INVALID",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23be);
    return;
  }
  lVar3 = (ulong)param_3 + 0x278;
  iVar1 = *(int *)(param_1 + lVar3 * 4);
  if (iVar1 != -1) {
    bVar2 = (byte)iVar1 & 0x3f;
    *(ulong *)(param_1 + 0x9d8) =
         *(ulong *)(param_1 + 0x9d8) & (-2L << bVar2 | 0xfffffffffffffffeU >> 0x40 - bVar2);
    *(undefined4 *)(param_1 + lVar3 * 4) = 0xffffffff;
    return;
  }
  nvCheckFailedNoLog(3,"ctsId != KMIGMGR_CTSID_INVALID",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23cb);
  return;
}


// ===== 003f0850 kmigmgrInvalidateGrGpcMapping_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrInvalidateGrGpcMapping_IMPL(long param_1,long param_2,undefined8 param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  char local_3d;
  undefined4 local_3c [3];
  
  iVar2 = vgpuGetCallingContextGfid(param_1,local_3c);
  if (iVar2 == 0) {
    iVar2 = vgpuIsCallingContextPlugin(param_1,&local_3d);
    if (iVar2 == 0) {
      if (local_3d != '\0') {
        local_3c[0] = 0;
      }
      cVar1 = (**(code **)(param_2 + 0x260))(param_1,param_2);
      if (cVar1 != '\0') {
        kmigmgrSetCTSIdInUse_IMPL(param_3,0xffffffff,(ulong)param_4,0);
      }
      uVar3 = 0;
      if (param_4 < 8) {
        uVar3 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)param_4 * 8);
      }
      fecsBufferTeardown(param_1,uVar3);
      kgraphicsFreeGlobalCtxBuffers_IMPL(param_1,uVar3,local_3c[0]);
      kgraphicsClearCtxBufferInfo_IMPL(param_1,uVar3);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x17c7);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x17c6);
  }
  return iVar2;
}


// ===== 003f0970 kmigmgrInvalidateGr_IMPL =====

int kmigmgrInvalidateGr_IMPL(long param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (param_4 < 8) {
    uVar3 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)param_4 * 8);
  }
  uVar1 = *(undefined8 *)(param_1 + 0x1bc8);
  iVar2 = kmigmgrInvalidateGrGpcMapping_IMPL(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    kgrmgrClearVeidsForGrIdx_IMPL(param_1,uVar1,param_4);
    kgraphicsInvalidateStaticInfo_IMPL(param_1,uVar3);
    return 0;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,
             "kmigmgrInvalidateGrGpcMapping(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, grIdx)",
             "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x17e9);
  return iVar2;
}


// ===== 003f0a20 kmigmgrInvalidateGPUInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int kmigmgrInvalidateGPUInstance_IMPL(long param_1,long param_2,uint param_3,char param_4)

{
  undefined8 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  ulong uVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  uint uVar11;
  long lVar12;
  int local_4c;
  undefined1 local_48 [24];
  
  if (param_3 < 0xf) {
    lVar12 = param_2 + 0x280;
    do {
      if (((lVar12 != 0) && (*(char *)(lVar12 + 0x988) != '\0')) &&
         (param_3 == *(uint *)(lVar12 + 0x968))) {
        uVar1 = *(undefined8 *)(param_1 + 0x1b78);
        lVar2 = *(long *)(param_1 + 0x1b70);
        cVar3 = kmigmgrIsGPUInstanceReadyToBeDestroyed_IMPL(param_1,lVar12);
        if (cVar3 == '\0') {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x181b,
                       "kmigmgrInvalidateGPUInstance_IMPL",4,
                       "NVRM: Gpu instance with SwizzId - %d still in use by other clients\n",
                       param_3);
          kmigmgrPrintSubscribingClients_IMPL(param_1,param_2,param_3);
          return 99;
        }
        pcVar6 = (char *)(lVar12 + 0x198);
        iVar9 = 0;
        do {
          if (*pcVar6 != '\0') {
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1827,
                         "kmigmgrInvalidateGPUInstance_IMPL",4,
                         "NVRM: Cannot destroy gpu instance %u with valid compute instance %d \n",
                         param_3,iVar9);
            return 99;
          }
          iVar9 = iVar9 + 1;
          pcVar6 = pcVar6 + 0x110;
        } while (iVar9 != 8);
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x182f,
                     "kmigmgrInvalidateGPUInstance_IMPL",1,"NVRM: FREEING GPU INSTANCE\n");
        kmigmgrPrintGPUInstanceInfo_IMPL(param_1,param_2,lVar12);
        if (param_4 == '\0') {
          osRmCapUnregister(lVar12 + 0x9b8);
        }
        bitVectorCopy_IMPL(local_48,0x54,lVar12 + 0x98,0x54);
        iVar9 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
        local_4c = 0;
        while (cVar3 = bitVectorTestAllCleared_IMPL(local_48,0x54), cVar3 == '\0') {
          uVar11 = iVar9 - 1;
          if (uVar11 < 8) {
            iVar4 = kmigmgrInvalidateGr_IMPL(param_1,param_2,lVar12,uVar11);
            iVar5 = local_4c;
            if ((iVar4 != 0) &&
               (nvAssertOkFailedNoLog
                          (iVar4,
                           "kmigmgrInvalidateGr(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, engineIdx)"
                           ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1849), iVar5 = iVar4,
               local_4c != 0)) {
              iVar5 = local_4c;
            }
            local_4c = iVar5;
            fecsClearRoutingInfo(param_1,*(undefined8 *)(param_1 + 0x1bd0 + (ulong)uVar11 * 8));
          }
          bitVectorClr_IMPL(local_48,0x54,iVar9);
          iVar9 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
        }
        if (*(int *)(lVar12 + 0x9c0) != 0) {
          lVar8 = rmapiGetInterface(4);
          (**(code **)(lVar8 + 0x18))
                    (lVar8,*(undefined4 *)(lVar12 + 0x9c0),*(undefined4 *)(lVar12 + 0x9c0),
                     *(code **)(lVar8 + 0x18));
          *(undefined8 *)(lVar12 + 0x9c0) = 0;
          *(undefined8 *)(lVar12 + 0x9c8) = 0;
          *(undefined4 *)(lVar12 + 0x9d0) = 0;
        }
        iVar5 = kmigmgrClearEnginesInUse_IMPL(param_1,param_2,lVar12 + 0x98);
        iVar9 = local_4c;
        if ((iVar5 != 0) &&
           (nvAssertOkFailedNoLog
                      (iVar5,
                       "kmigmgrClearEnginesInUse(pGpu, pKernelMIGManager, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1854), iVar9 = iVar5,
           local_4c != 0)) {
          iVar9 = local_4c;
        }
        local_4c = iVar9;
        kmigmgrDestroyGPUInstanceGrBufPools_IMPL(param_1,param_2,lVar12);
        uVar10 = *(ulong *)(param_2 + 0x5348);
        uVar7 = 1L << ((byte)param_3 & 0x3f);
        if ((uVar7 & uVar10) != 0) {
          uVar10 = uVar10 & ~uVar7;
          *(ulong *)(param_2 + 0x5348) = uVar10;
        }
        if ((uVar10 >> ((ulong)param_3 & 0x3f) & 1) != 0) {
          nvAssertFailedNoLog("!(NVBIT64(swizzId) & pKernelMIGManager->swizzIdInUseMask)",
                              "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1861);
          local_4c = 0x40;
        }
        iVar5 = (**(code **)(lVar2 + 0x1f0))(param_1);
        iVar9 = local_4c;
        if ((iVar5 != 0) &&
           (nvAssertOkFailedNoLog
                      (iVar5,"kmemsysInitMIGMemoryPartitionTable_HAL(pGpu, pKernelMemorySystem)",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1863), iVar9 = iVar5,
           local_4c != 0)) {
          iVar9 = local_4c;
        }
        local_4c = iVar9;
        if (((*(char *)(lVar12 + 0x989) != '\0') &&
            (*(char *)(*(long *)(param_1 + 0x1b78) + 0x480) != '\0')) &&
           (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) != '\0')) {
          scrubberDestruct(param_1,*(undefined8 *)(lVar12 + 0x980));
          *(undefined1 *)(lVar12 + 0x989) = 0;
        }
        kmigmgrDestroyGPUInstancePool_IMPL(param_1,param_2,lVar12);
        cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(param_1);
        iVar9 = local_4c;
        if (((cVar3 != '\0') &&
            (cVar3 = (**(code **)(param_2 + 0x200))(param_2,*(undefined4 *)(lVar12 + 0x96c)),
            cVar3 != '\0')) &&
           ((iVar5 = kvgpuMgrClearVgpuPlacementInfoPerGI(param_1,param_3), iVar5 != 0 &&
            (nvAssertOkFailedNoLog
                       (iVar5,"kvgpuMgrClearVgpuPlacementInfoPerGI(pGpu, swizzId)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1870), iVar9 = iVar5,
            local_4c != 0)))) {
          iVar9 = local_4c;
        }
        local_4c = iVar9;
        iVar5 = (**(code **)(param_2 + 0x198))(param_1,param_2,lVar12);
        iVar9 = local_4c;
        if ((iVar5 != 0) &&
           (nvAssertOkFailedNoLog
                      (iVar5,
                       "kmigmgrDeleteGPUInstanceRunlists_HAL(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1874), iVar9 = iVar5,
           local_4c != 0)) {
          iVar9 = local_4c;
        }
        local_4c = iVar9;
        kmigmgrDestroyGPUInstanceRunlistBufPools_IMPL(param_1,param_2,lVar12);
        iVar5 = memmgrFreeMIGGPUInstanceMemory_IMPL
                          (param_1,uVar1,(ulong)param_3,*(undefined4 *)(lVar12 + 0x970),
                           lVar12 + 0x980);
        iVar9 = local_4c;
        if ((iVar5 != 0) &&
           (nvAssertOkFailedNoLog
                      (iVar5,
                       "memmgrFreeMIGGPUInstanceMemory(pGpu, pMemoryManager, swizzId, pKernelMIGGpuInstance->hMemory, &pKernelMIGGpuInstance->pMemoryPartitionHeap)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x187b), iVar9 = iVar5,
           local_4c != 0)) {
          iVar9 = local_4c;
        }
        local_4c = iVar9;
        if (*(long *)(lVar12 + 0x978) != 0) {
          serverFreeShare(g_resServ);
          *(undefined8 *)(lVar12 + 0x978) = 0;
        }
        kmigmgrInitGPUInstanceInfo_IMPL(param_1,param_2,lVar12);
        if (((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(param_1 + 0x491d) != '\0')) &&
           (iVar9 = intrRefetchInterruptTable_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c20)),
           iVar9 != 0)) {
          nvAssertOkFailedNoLog
                    (iVar9,"intrRefetchInterruptTable_HAL(pGpu, GPU_GET_INTR(pGpu))",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1891);
          if (local_4c == 0) {
            return iVar9;
          }
          return local_4c;
        }
        return local_4c;
      }
      lVar12 = lVar12 + 0xa18;
    } while (param_2 + 0x5340 != lVar12);
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1813,
               "kmigmgrInvalidateGPUInstance_IMPL",4,
               "NVRM: No valid gpu instance with SwizzId - %d found\n",param_3);
  return 0x1f;
}


// ===== 003f1080 kmigmgrCreateGPUInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrCreateGPUInstance_IMPL
              (long param_1,long param_2,ulong param_3,undefined8 param_4,char param_5,char param_6,
              int param_7)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  uint *puVar7;
  char *extraout_RDX;
  char *extraout_RDX_00;
  char *pcVar8;
  uint uVar9;
  undefined8 uVar11;
  int local_4c;
  undefined1 local_48 [24];
  ulong uVar10;
  
  uVar10 = param_3 & 0xffffffff;
  if (param_5 == '\0') {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b2c,
                 "kmigmgrCreateGPUInstance_IMPL",1,"NVRM: Invalidating swizzId - %d.\n",
                 param_3 & 0xffffffff);
    iVar4 = kmigmgrInvalidateGPUInstance_IMPL(param_1,param_2,uVar10,0);
    if (iVar4 == 0) {
      return 0;
    }
    nvCheckOkFailedNoLog
              (4,iVar4,"kmigmgrInvalidateGPUInstance(pGpu, pKernelMIGManager, swizzId, NV_FALSE)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b2e);
    return iVar4;
  }
  if ((param_7 == 1) && ((*(ulong *)(param_2 + 0x5348) >> (param_3 & 0x3f) & 1) != 0)) {
    nvAssertFailedNoLog("!kmigmgrIsSwizzIdInUse(pGpu, pKernelMIGManager, swizzId)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ab0);
    return 0x40;
  }
  lVar2 = *(long *)(param_1 + 0x1b70);
  if (((*(ulong *)(param_2 + 0x5348) == 0) && (*(char *)(param_1 + 0x909) != '\0')) &&
     (iVar4 = kmigmgrEnableAllLCEs_IMPL(param_1,param_2,1), iVar4 != 0)) {
    nvCheckOkFailedNoLog
              (4,iVar4,"kmigmgrEnableAllLCEs(pGpu, pKernelMIGManager, NV_TRUE)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1abb);
  }
  else {
    iVar4 = kmigmgrSetGPUInstanceInfo_IMPL(param_1,param_2,uVar10,param_4);
    if (iVar4 == 0) {
      if ((uint)param_3 < 0xf) {
        uVar6 = 1L << ((byte)param_3 & 0x3f);
        if ((uVar6 & *(ulong *)(param_2 + 0x5348)) == 0) {
          *(ulong *)(param_2 + 0x5348) = uVar6 | *(ulong *)(param_2 + 0x5348);
          puVar7 = (uint *)(param_2 + 0xbe8);
          uVar10 = 0;
          do {
            if (((char)puVar7[8] != '\0') && ((uint)param_3 == *puVar7)) {
              lVar1 = param_2 + 0x280 + uVar10 * 0xa18;
              iVar4 = kmigmgrAllocGPUInstanceHandles_IMPL(param_1,param_3 & 0xffffffff,lVar1);
              if (iVar4 != 0) {
                nvCheckOkFailedNoLog
                          (4,iVar4,
                           "kmigmgrAllocGPUInstanceHandles(pGpu, swizzId, pKernelMIGGpuInstance)",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ac9);
                goto LAB_003f1195;
              }
              iVar4 = kmigmgrInitGPUInstanceBufPools_IMPL(param_1,param_2,lVar1);
              if (iVar4 != 0) {
                nvCheckOkFailedNoLog
                          (4,iVar4,
                           "kmigmgrInitGPUInstanceBufPools(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)"
                           ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1acc);
                goto LAB_003f1195;
              }
              iVar4 = (**(code **)(param_2 + 0x1a0))(param_1,param_2,lVar1);
              if (iVar4 != 0) goto LAB_003f1195;
              iVar4 = (**(code **)(lVar2 + 0x1f0))(param_1);
              if (iVar4 == 0) {
                bitVectorCopy_IMPL(local_48,0x54,lVar1 + 0x98,0x54);
                iVar4 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
                goto LAB_003f1329;
              }
              nvAssertOkFailedNoLog
                        (iVar4,"kmemsysInitMIGMemoryPartitionTable_HAL(pGpu, pKernelMemorySystem)",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ad2);
              goto LAB_003f1195;
            }
            uVar9 = (int)uVar10 + 1;
            uVar10 = (ulong)uVar9;
            puVar7 = puVar7 + 0x286;
          } while (uVar9 != 8);
          nvCheckOkFailedNoLog
                    (4,0x1f,
                     "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pKernelMIGGpuInstance)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ac6);
LAB_003f1190:
          iVar4 = 0x1f;
          goto LAB_003f1195;
        }
        iVar4 = 99;
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x8af,
                     "kmigmgrSetSwizzIdInUse_IMPL",4,"NVRM: SwizzID - %d already in use\n",uVar10);
      }
      else {
        iVar4 = 0x1f;
      }
      nvCheckOkFailedNoLog
                (4,iVar4,"kmigmgrSetSwizzIdInUse(pGpu, pKernelMIGManager, swizzId)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ac3);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "kmigmgrSetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, pUuid, params)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1abf);
    }
  }
  goto LAB_003f1195;
LAB_003f1329:
  cVar3 = bitVectorTestAllCleared_IMPL(local_48,0x54);
  if (cVar3 != '\0') goto code_r0x003f133f;
  if (iVar4 - 1U < 8) {
    uVar11 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)(iVar4 - 1U) * 8);
    iVar5 = kmigmgrGetGlobalToLocalEngineType_IMPL(param_1,param_2,lVar1,0,iVar4,&local_4c);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (0x1f,
                 "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, kmigmgrMakeGIReference(pKernelMIGGpuInstance), rmEngineType, &localEngineType)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ae1);
      goto LAB_003f1190;
    }
    fecsSetRoutingInfo(param_1,uVar11,*(undefined4 *)(lVar1 + 0x9c0),*(undefined4 *)(lVar1 + 0x9c8),
                       local_4c + -1);
  }
  bitVectorClr_IMPL(local_48,0x54,iVar4);
  iVar4 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  goto LAB_003f1329;
code_r0x003f133f:
  iVar4 = kmigmgrInitGPUInstancePool_IMPL(param_1,param_2,lVar1);
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,"kmigmgrInitGPUInstancePool(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1af2);
    goto LAB_003f1195;
  }
  if ((*(char *)(*(long *)(param_1 + 0x1b78) + 0x480) != '\0') &&
     (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) != '\0')) {
    iVar4 = scrubberConstruct(param_1,*(undefined8 *)(lVar1 + 0x980));
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"scrubberConstruct(pGpu, pKernelMIGGpuInstance->pMemoryPartitionHeap)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x18a9);
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "kmigmgrInitGPUInstanceScrubber(pGpu, pKernelMIGManager, pKernelMIGGpuInstance)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1af6);
      goto LAB_003f1195;
    }
    *(undefined1 *)(lVar1 + 0x989) = 1;
  }
  cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(param_1);
  pcVar8 = extraout_RDX;
  if ((cVar3 == '\0') ||
     (cVar3 = (**(code **)(param_2 + 0x200))(param_2,*(undefined4 *)(lVar1 + 0x96c)),
     pcVar8 = extraout_RDX_00, cVar3 == '\0')) {
LAB_003f14e0:
    if ((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(param_1 + 0x491d) != '\0')) {
      iVar4 = intrRefetchInterruptTable_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c20),pcVar8);
      uVar11 = 0x1b16;
      pcVar8 = "intrRefetchInterruptTable_HAL(pGpu, GPU_GET_INTR(pGpu))";
      if (iVar4 != 0) goto LAB_003f13d5;
    }
    if ((param_6 == '\0') ||
       (iVar4 = osRmCapRegisterSmcPartition
                          (*(undefined8 *)(param_1 + 0x4e8),lVar1 + 0x9b8,
                           *(undefined4 *)(lVar1 + 0x968)), iVar4 == 0)) {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1b27,
                   "kmigmgrCreateGPUInstance_IMPL",1,"NVRM: CREATING GPU instance\n");
      kmigmgrPrintGPUInstanceInfo_IMPL(param_1,param_2,lVar1);
      return 0;
    }
    uVar11 = 0x1b21;
    pcVar8 = 
    "osRmCapRegisterSmcPartition(pGpu->pOsRmCaps, &pKernelMIGGpuInstance->pOsRmCaps, pKernelMIGGpuInstance->swizzId)"
    ;
  }
  else {
    iVar4 = kvgpuMgrReserveVgpuPlacementInfoPerGI(param_1,param_3 & 0xffffffff);
    uVar11 = 0x1afd;
    pcVar8 = "kvgpuMgrReserveVgpuPlacementInfoPerGI(pGpu, swizzId)";
    if (iVar4 == 0) goto LAB_003f14e0;
  }
LAB_003f13d5:
  nvCheckOkFailedNoLog(4,iVar4,pcVar8,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar11);
LAB_003f1195:
  kmigmgrInvalidateGPUInstance_IMPL(param_1,param_2,param_3 & 0xffffffff,0);
  return iVar4;
}


// ===== 003f1770 _kmigmgrProcessGPUInstanceEntry =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kmigmgrProcessGPUInstanceEntry(long param_1,long param_2,undefined8 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char cVar6;
  undefined8 uVar7;
  uint uStack_5c;
  undefined4 uStack_54;
  undefined7 uStack_3f;
  
  puVar4 = (undefined4 *)portMemAllocNonPaged(0x188);
  if (puVar4 == (undefined4 *)0x0) {
    nvCheckFailedNoLog(4,"pParams != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e02);
    return 0x51;
  }
  *puVar4 = 1;
  *(undefined8 *)(puVar4 + 2) = *param_3;
  *(undefined8 *)(puVar4 + 4) = param_3[1];
  *(undefined8 *)(puVar4 + 6) = param_3[2];
  *(undefined8 *)(puVar4 + 8) = param_3[3];
  *(undefined8 *)(puVar4 + 10) = param_3[4];
  *(undefined8 *)(puVar4 + 0xc) = param_3[5];
  if (*(char *)(param_3 + 3) == '\0') {
LAB_003f18e0:
    cVar6 = '\0';
    if (*(char *)(param_1 + 0x909) == '\0') {
LAB_003f18f3:
      iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800aa5,puVar4,0x188);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_GPU_INSTANCES, pParams, sizeof(*pParams))"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e43);
        goto LAB_003f1a67;
      }
      gpumgrCacheDestroyGpuInstance_IMPL(param_1,*(undefined4 *)param_3);
    }
    else {
LAB_003f19a0:
      iVar2 = kmigmgrCreateGPUInstance_IMPL
                        (param_1,param_2,*(undefined4 *)param_3,(undefined4 *)((long)param_3 + 4),
                         cVar6,1,(ulong)uStack_5c << 0x20,
                         CONCAT44(uStack_54,*(undefined4 *)((long)param_3 + 0x14)) &
                         0xffffffff7fffffff,param_3[4],param_3[5],
                         CONCAT71(uStack_3f,
                                  (byte)((uint)*(undefined4 *)((long)param_3 + 0x14) >> 0x1f)));
      if (iVar2 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar2,
                   "kmigmgrCreateGPUInstance(pGpu, pKernelMIGManager, pEntry->swizzId, pEntry->uuid, request, pEntry->bValid, NV_TRUE )"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e3b);
        if (*(char *)(param_3 + 3) != '\0') {
          *(undefined1 *)(puVar4 + 8) = 0;
          iVar3 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                             *(undefined4 *)(param_1 + 0x3b3c),0x20800aa5,puVar4,0x188);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_GPU_INSTANCES, pParams, sizeof(*pParams))"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e65);
          }
          goto LAB_003f1acf;
        }
        goto LAB_003f1a67;
      }
      cVar6 = *(char *)(param_3 + 3);
LAB_003f18cc:
      if (cVar6 == '\0') goto LAB_003f18f3;
      gpumgrCacheCreateGpuInstance_IMPL(param_1,*(undefined4 *)param_3);
    }
    if (*(long *)(param_2 + 0x5348) == 0) {
      uVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,puVar4[2]);
      iVar2 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar1,0,0);
      if (iVar2 != 0) {
        uVar7 = 0x1e58;
        pcVar5 = 
        "kmigmgrSetMIGState(pGpu, pKernelMIGManager, bMemoryPartitioningNeeded, NV_FALSE, NV_FALSE)"
        ;
        goto LAB_003f1a54;
      }
    }
    portMemFree(puVar4);
    iVar2 = 0;
  }
  else {
    if (*(long *)(param_2 + 0x5348) == 0) {
      uVar1 = (**(code **)(param_2 + 0x220))(param_1,param_2,*(undefined4 *)((long)param_3 + 0x14));
      iVar2 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar1,1,0);
      uVar7 = 0x1e18;
      pcVar5 = 
      "kmigmgrSetMIGState(pGpu, pKernelMIGManager, bMemoryPartitioningRequested, NV_TRUE, NV_FALSE)"
      ;
      if (iVar2 == 0) {
        if (*(char *)(param_3 + 3) == '\0') goto LAB_003f18e0;
        goto LAB_003f185a;
      }
LAB_003f1a54:
      nvCheckOkFailedNoLog(4,iVar2,pcVar5,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar7);
    }
    else {
LAB_003f185a:
      iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800aa5,puVar4,0x188);
      if (iVar2 == 0) {
        *(undefined4 *)param_3 = puVar4[2];
        portMemCopy((undefined4 *)((long)param_3 + 4),0x10,puVar4 + 3,0x10);
        cVar6 = *(char *)(param_3 + 3);
        if (*(char *)(param_1 + 0x909) != '\0') goto LAB_003f19a0;
        goto LAB_003f18cc;
      }
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_GPU_INSTANCES, pParams, sizeof(*pParams))"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e1f);
LAB_003f1acf:
      if ((*(char *)(param_3 + 3) != '\0') && (*(long *)(param_2 + 0x5348) == 0)) {
        uVar1 = (**(code **)(param_2 + 0x220))
                          (param_1,param_2,*(undefined4 *)((long)param_3 + 0x14));
        iVar3 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar1,0,0);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "kmigmgrSetMIGState(pGpu, pKernelMIGManager, bMemoryPartitioningRequested, NV_FALSE, NV_FALSE)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e72);
        }
      }
    }
LAB_003f1a67:
    portMemFree(puVar4);
  }
  return iVar2;
}


// ===== 003f1bf0 subdeviceCtrlCmdGpuSetPartitions_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGpuSetPartitions_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  ulong uVar11;
  uint *puVar12;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1bc0);
  lVar6 = resservGetTlsCallContext();
  lVar7 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e91);
    return 0x23;
  }
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e93);
    return 0x2f;
  }
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e95)
    ;
    return 0x40;
  }
  cVar3 = rmclientIsCapableOrAdmin_IMPL(lVar7,2,*(undefined4 *)(lVar6 + 0x28));
  if (cVar3 == '\0') {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e9b,
                 "subdeviceCtrlCmdGpuSetPartitions_IMPL",4,
                 "NVRM: Non-privileged context issued privileged cmd\n");
    return 0x1b;
  }
  if (((*(long *)(lVar1 + 0x1bc0) == 0) || (*(char *)(lVar1 + 0x467) == '\0')) ||
     (*(char *)(*(long *)(lVar1 + 0x1bc0) + 0x5340) == '\0')) {
    nvCheckFailedNoLog(1,"IS_MIG_ENABLED(pGpu)","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1e9f
                      );
  }
  else {
    uVar8 = *param_2;
    if (8 < uVar8) {
      return 0x1f;
    }
    if (uVar8 == 0) {
      return 0x10006;
    }
    uVar11 = 0;
    do {
      if ((char)param_2[uVar11 * 0xc + 8] != '\0') {
        cVar3 = (**(code **)(lVar2 + 0x1f0))(lVar1,lVar2,param_2[uVar11 * 0xc + 7] & 0x7fffffff);
        if (cVar3 == '\0') {
          nvCheckFailedNoLog(4,
                             "kmigmgrIsGPUInstanceCombinationValid_HAL(pGpu, pKernelMIGManager, partitionFlag)"
                             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1eb1);
          return 0x56;
        }
        uVar8 = *param_2;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulong)uVar10;
    } while (uVar10 < uVar8);
    if (*(char *)(lVar1 + 0x908) == '\0') {
      if (uVar8 != 0) {
        puVar12 = param_2 + 2;
        uVar8 = 0;
        do {
          iVar4 = _kmigmgrProcessGPUInstanceEntry(lVar1,lVar2);
          if (iVar4 != 0) {
            nvCheckOkFailedNoLog
                      (1,iVar4,
                       "_kmigmgrProcessGPUInstanceEntry(pGpu, pKernelMIGManager, &pParams->partitionInfo[i])"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ebf);
            if (uVar8 != 0) {
              puVar9 = puVar12 + (ulong)uVar8 * 0xc;
              do {
                *(bool *)(puVar12 + 6) = (char)puVar12[6] == '\0';
                iVar5 = _kmigmgrProcessGPUInstanceEntry(lVar1,lVar2,puVar12);
                if (iVar5 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar5,
                             "_kmigmgrProcessGPUInstanceEntry(pGpu, pKernelMIGManager, &pParams->partitionInfo[j])"
                             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ed1);
                }
                *(bool *)(puVar12 + 6) = (char)puVar12[6] == '\0';
                puVar12 = puVar12 + 0xc;
              } while (puVar12 != puVar9);
              return iVar4;
            }
            return iVar4;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *param_2);
      }
      gpuNotifySubDeviceEvent_IMPL(lVar1,0x9f,0,0,0,0);
      return 0;
    }
  }
  return 0x56;
}


// ===== 003f1f30 subdeviceCtrlCmdInternalKMIGmgrImportGPUInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdInternalKMIGmgrImportGPUInstance_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined1 *puVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined4 local_1c0;
  undefined4 uStack_1bc;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined1 local_1a0;
  undefined7 uStack_19f;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1bc0);
  lVar8 = resservGetTlsCallContext();
  lVar9 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ff6);
    return 0x23;
  }
  if (*(char *)(lVar2 + 0x467) == '\0') {
    return 0x56;
  }
  if (lVar8 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ffb)
    ;
    return 0x40;
  }
  cVar4 = rmclientIsCapableOrAdmin_IMPL(lVar9,2,*(undefined4 *)(lVar8 + 0x28));
  if (cVar4 == '\0') {
    return 0x1b;
  }
  if (*(char *)(lVar2 + 0x908) != '\0') {
    return 0x56;
  }
  if (*(long *)(lVar3 + 0x5348) == 0) {
    uVar5 = (**(code **)(lVar3 + 0x228))(lVar2,lVar3,*param_2);
    iVar7 = (**(code **)(*(long *)(lVar2 + 0x1bc0) + 0x250))
                      (lVar2,*(long *)(lVar2 + 0x1bc0),uVar5,1,0);
    uVar12 = 0x200f;
    pcVar11 = 
    "kmigmgrSetMIGState(pGpu, GPU_GET_KERNEL_MIG_MANAGER(pGpu), bMemoryPartitioningNeeded, NV_TRUE, NV_FALSE)"
    ;
    if (iVar7 != 0) goto LAB_003f2093;
  }
  iVar6 = (**(code **)(lVar2 + 0x3b90))
                    (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),*(undefined4 *)(lVar2 + 0x3b3c),
                     0x20800aaa,param_2,0x50);
  if (iVar6 == 0) {
    if (*(char *)(lVar2 + 0x909) == '\0') {
      return 0;
    }
    puVar10 = (undefined1 *)portMemAllocNonPaged(0x390);
    if (puVar10 == (undefined1 *)0x0) {
      nvCheckFailedNoLog(4,"pSave != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x201f);
      iVar6 = 0x51;
    }
    else {
      local_1c0 = 1;
      *puVar10 = 1;
      uVar1 = *param_2;
      *(undefined8 *)(puVar10 + 0x48) = 0;
      *(undefined4 *)(puVar10 + 0x40) = uVar1;
      local_1b8 = puVar10;
      portMemCopy(puVar10 + 8,0x38,param_2 + 6,0x38);
      iVar6 = kmigmgrCreateGPUInstance_IMPL
                        (lVar2,lVar3,*param_2,param_2 + 1,1,0,CONCAT44(uStack_1bc,local_1c0),
                         local_1b8,local_1b0,local_1a8,CONCAT71(uStack_19f,local_1a0));
      portMemFree(puVar10);
      if (iVar6 == 0) {
        return 0;
      }
      nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2032);
      portMemSet(&local_1c0,0,0x188);
      local_1c0 = 1;
      local_1a0 = 0;
      local_1b8 = (undefined1 *)CONCAT44(local_1b8._4_4_,*param_2);
      iVar7 = (**(code **)(lVar2 + 0x3b90))
                        (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),
                         *(undefined4 *)(lVar2 + 0x3b3c),0x20800aa5,param_2,0x50);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_GPU_INSTANCES, pParams, sizeof(*pParams))"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2040);
      }
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_IMPORT_GPU_INSTANCE, pParams, sizeof(*pParams))"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2013);
  }
  if (*(long *)(lVar3 + 0x5348) != 0) {
    return iVar6;
  }
  uVar5 = (**(code **)(lVar3 + 0x228))(lVar2,lVar3,*param_2);
  iVar7 = (**(code **)(*(long *)(lVar2 + 0x1bc0) + 0x250))
                    (lVar2,*(long *)(lVar2 + 0x1bc0),uVar5,0,0);
  if (iVar7 == 0) {
    return iVar6;
  }
  uVar12 = 0x204e;
  pcVar11 = 
  "kmigmgrSetMIGState(pGpu, GPU_GET_KERNEL_MIG_MANAGER(pGpu), bMemoryPartitioningNeeded, NV_FALSE, NV_FALSE)"
  ;
LAB_003f2093:
  nvCheckOkFailedNoLog(4,iVar7,pcVar11,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar12);
  return iVar7;
}


// ===== 003f2340 kmigmgrConfigureGPUInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int kmigmgrConfigureGPUInstance_IMPL
              (long param_1,long param_2,uint param_3,long param_4,uint param_5)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  uint *puVar14;
  byte bVar15;
  uint uVar16;
  int iVar17;
  long lVar18;
  bool bVar19;
  undefined4 uVar20;
  int local_68 [4];
  int local_58 [10];
  
  uVar10 = gpuGetKernelFifoShared_IMPL();
  uVar4 = *(undefined8 *)(param_1 + 0x1bc8);
  cVar6 = (**(code **)(param_2 + 0x260))(param_1,param_2);
  if ((*(ulong *)(param_2 + 0x5348) & 1L << ((byte)param_3 & 0x3f)) == 0) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16e1,
                 "kmigmgrConfigureGPUInstance_IMPL",4,"NVRM: Invalid swizzId - %d.\n",param_3);
  }
  else if (param_3 < 0xf) {
    puVar14 = (uint *)(param_2 + 0xbe8);
    uVar11 = 0;
    do {
      if (((char)puVar14[8] != '\0') && (param_3 == *puVar14)) {
        uVar16 = 0;
        lVar3 = param_2 + 0x280 + uVar11 * 0xa18;
        portMemSet(local_58,0,0x20);
        lVar1 = lVar3 + 0x98;
        bVar15 = 0;
        bitVectorCopy_IMPL(local_68,0x54,lVar1,0x54);
        iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
        bVar19 = false;
        while (cVar5 = bitVectorTestAllCleared_IMPL(local_68,0x54), cVar5 == '\0') {
          if (iVar7 - 1U < 8) {
            if ((1 << (bVar15 & 0x1f) & param_5) == 0) {
              bVar15 = bVar15 + 1;
            }
            else {
              lVar13 = (ulong)uVar16 * 0x20 + param_4;
              if (cVar6 == '\0') {
                if (*(uint *)(lVar3 + 0x88) < *(uint *)(lVar13 + 8)) {
                  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1708,
                               "kmigmgrConfigureGPUInstance_IMPL",4,
                               "NVRM: Invalid GPC count - %d requested for GrIdx - %d.\n",
                               *(uint *)(lVar13 + 8),iVar7 - 1U);
                  return 0x1f;
                }
              }
              else if (*(int *)(lVar13 + 0x18) == -1) {
                nvCheckFailedNoLog(4,"pConfigRequestsPerCi[localIdx].ctsId != KMIGMGR_CTSID_INVALID"
                                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16ff);
                return 0x1a;
              }
              if (!bVar19) {
                bVar19 = *(int *)(lVar13 + 8) != 0;
              }
              local_58[uVar16] = iVar7;
              bVar15 = bVar15 + 1;
              uVar16 = uVar16 + 1;
            }
          }
          bitVectorClr_IMPL(local_68,0x54,iVar7);
          iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
        }
        cVar5 = kfifoEngineListHasChannel_IMPL(param_1,uVar10,local_58,uVar16);
        if (cVar5 != '\0') {
          return 99;
        }
        if (!bVar19) {
          bitVectorCopy_IMPL(local_68,0x54,lVar1,0x54);
          bVar15 = 0;
          iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
          do {
            cVar6 = bitVectorTestAllCleared_IMPL(local_68,0x54);
            if (cVar6 != '\0') {
              return 0;
            }
            if (iVar7 - 1U < 8) {
              if (((1 << (bVar15 & 0x1f) & param_5) != 0) &&
                 (iVar8 = kmigmgrInvalidateGr_IMPL(param_1,param_2,lVar3,iVar7 - 1U), iVar8 != 0)) {
                nvAssertOkFailedNoLog
                          (iVar8,
                           "kmigmgrInvalidateGr(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, engineIdx)"
                           ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x172f);
                return iVar8;
              }
              bVar15 = bVar15 + 1;
            }
            bitVectorClr_IMPL(local_68,0x54,iVar7);
            iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
          } while( true );
        }
        bitVectorCopy_IMPL(local_68,0x54,lVar1,0x54);
        iVar8 = 0;
        iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
        uVar16 = 0;
        do {
          cVar5 = bitVectorTestAllCleared_IMPL(local_68,0x54);
          if (cVar5 != '\0') {
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1677,
                         "_kmigmgrPrintComputeInstances",1,"NVRM: \n");
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1678,
                         "_kmigmgrPrintComputeInstances",1,"NVRM: %s\n",
                         "----------------------------------------------------");
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1679,
                         "_kmigmgrPrintComputeInstances",1,"NVRM: | %14s | %14s | %14s |\n",
                         "SwizzId","GR Count","Gpc Count");
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x167d,
                         "_kmigmgrPrintComputeInstances",1,"NVRM: %s\n",
                         "----------------------------------------------------");
            uVar20 = *(undefined4 *)(lVar3 + 0x88);
            uVar10 = kmigmgrCountEnginesInRange_IMPL(lVar1,1,8);
            lVar18 = 0;
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x167e,
                         "_kmigmgrPrintComputeInstances",1,"NVRM: | %14d | %14d | %14d |\n",
                         *(undefined4 *)(lVar3 + 0x968),uVar10,uVar20);
            lVar13 = lVar3;
            do {
              if (*(char *)(lVar13 + 0x198) != '\0') {
                iVar7 = kmigmgrEngineTypeXlate_IMPL(lVar13 + 0x180,1,lVar13 + 0x170,local_68);
                if (iVar7 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar7,
                             "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &rmEngineType)"
                             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1690);
                }
                nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1694,
                             "_kmigmgrPrintComputeInstances",1,"NVRM: %s\n",
                             "----------------------------------------------------");
                iVar7 = local_68[0] + -1;
                if (*(char *)(param_1 + 0x909) == '\0') {
                  uVar20 = 0;
                  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16a8,
                               "_kmigmgrPrintComputeInstances",1,"NVRM: | %23s | %23s |\n",
                               "Gr Engine IDX","GPC Count");
                  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16ab,
                               "_kmigmgrPrintComputeInstances",1,"NVRM: | %23d | %23X |\n",iVar7,
                               CONCAT44(uVar20,*(undefined4 *)(lVar13 + 0x160)));
                }
                else {
                  uVar16 = 0;
                  if (*(uint *)(lVar13 + 0x160) != 0) {
                    uVar16 = 0;
                    lVar12 = lVar13;
                    do {
                      puVar2 = (undefined4 *)(lVar12 + 0xe0);
                      lVar12 = lVar12 + 4;
                      uVar16 = uVar16 | 1 << ((byte)*puVar2 & 0x1f);
                    } while (lVar12 != lVar3 + ((ulong)*(uint *)(lVar13 + 0x160) + lVar18) * 4);
                  }
                  uVar20 = 0;
                  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x169e,
                               "_kmigmgrPrintComputeInstances",1,"NVRM: | %23s | %23s |\n",
                               "Gr Engine IDX","GPC Mask");
                  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16a1,
                               "_kmigmgrPrintComputeInstances",1,"NVRM: | %23d | %23X |\n",iVar7,
                               CONCAT44(uVar20,uVar16));
                }
              }
              lVar13 = lVar13 + 0x110;
              lVar18 = lVar18 + 0x44;
            } while (lVar3 + 0x880 != lVar13);
            iVar8 = 0;
            uVar11 = 0;
            nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x16b0,
                         "_kmigmgrPrintComputeInstances",1,"NVRM: %s\n",
                         "----------------------------------------------------");
            bitVectorCopy_IMPL(local_68,0x54,lVar1,0x54);
            iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
            do {
              cVar5 = bitVectorTestAllCleared_IMPL(local_68,0x54);
              if (cVar5 != '\0') {
                return 0;
              }
              uVar16 = iVar7 - 1;
              if (uVar16 < 8) {
                if ((1 << ((byte)iVar8 & 0x1f) & param_5) != 0) {
                  lVar13 = uVar11 * 0x20 + param_4;
                  if (*(int *)(lVar13 + 8) == 0) {
                    uVar11 = (ulong)((int)uVar11 + 1);
                    iVar8 = iVar8 + 1;
                    goto LAB_003f2b68;
                  }
                  if (cVar6 != '\0') {
                    iVar9 = *(int *)(lVar13 + 0x18);
                    *(int *)(lVar3 + 0x9e0 + (ulong)uVar16 * 4) = iVar9;
                    if (iVar9 == -1) {
                      nvAssertFailedNoLog("ctsId != KMIGMGR_CTSID_INVALID",
                                          "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23be);
                    }
                    else {
                      *(ulong *)(lVar3 + 0x9d8) =
                           *(ulong *)(lVar3 + 0x9d8) | 1L << ((byte)iVar9 & 0x3f);
                    }
                  }
                  lVar13 = *(long *)(param_1 + 0x1bd0 + (ulong)uVar16 * 8);
                  iVar9 = (**(code **)(lVar13 + 0x1b0))
                                    (param_1,lVar13,*(undefined4 *)(lVar3 + 0x968));
                  if ((iVar9 != 0) ||
                     (iVar9 = kgrmgrDiscoverMaxLocalCtxBufInfo_IMPL(param_1,uVar4,lVar13,param_3),
                     iVar9 != 0)) goto LAB_003f2c55;
                }
                iVar8 = iVar8 + 1;
              }
LAB_003f2b68:
              bitVectorClr_IMPL(local_68,0x54,iVar7);
              iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
            } while( true );
          }
          if (iVar7 - 1U < 8) {
            if ((1 << ((byte)iVar8 & 0x1f) & param_5) != 0) {
              lVar13 = (ulong)uVar16 * 0x20 + param_4;
              if (*(int *)(lVar13 + 8) == 0) {
                uVar16 = uVar16 + 1;
                iVar8 = iVar8 + 1;
                goto LAB_003f2717;
              }
              iVar9 = kgrmgrAllocVeidsForGrIdx_IMPL
                                (param_1,uVar4,iVar7 - 1U,*(undefined4 *)(lVar13 + 0x1c),
                                 *(undefined4 *)(lVar13 + 0xc),lVar3);
              if (iVar9 != 0) {
                nvCheckOkFailedNoLog
                          (4,iVar9,
                           "kgrmgrAllocVeidsForGrIdx(pGpu, pKernelGraphicsManager, engineIdx, pConfigRequestsPerCi[localIdx].veidSpanStart, pConfigRequestsPerCi[localIdx].profile.veidCount, pKernelMIGGpuInstance)"
                           ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1759);
LAB_003f2c55:
                iVar17 = 0;
                bitVectorCopy_IMPL(local_68,0x54,lVar1,0x54);
                iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
                while( true ) {
                  cVar6 = bitVectorTestAllCleared_IMPL(local_68,0x54);
                  if (cVar6 != '\0') {
                    return iVar9;
                  }
                  if (iVar8 == iVar17) break;
                  uVar16 = iVar7 - 1;
                  if (uVar16 < 8) {
                    if ((1 << ((byte)iVar17 & 0x1f) & param_5) != 0) {
                      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x17a8,
                                   "kmigmgrConfigureGPUInstance_IMPL",4,
                                   "NVRM: Failed to configure GPU instance. Invalidating GRID - %d\n"
                                   ,uVar16);
                      kmigmgrInvalidateGr_IMPL(param_1,param_2,lVar3,uVar16);
                    }
                    iVar17 = iVar17 + 1;
                  }
                  bitVectorClr_IMPL(local_68,0x54,iVar7);
                  iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
                }
                return iVar9;
              }
            }
            iVar8 = iVar8 + 1;
          }
LAB_003f2717:
          bitVectorClr_IMPL(local_68,0x54,iVar7);
          iVar7 = bitVectorCountTrailingZeros_IMPL(local_68,0x54);
        } while( true );
      }
      uVar16 = (int)uVar11 + 1;
      uVar11 = (ulong)uVar16;
      puVar14 = puVar14 + 0x286;
    } while (uVar16 != 8);
  }
  return 0x1f;
}


// ===== 003f2d90 kmigmgrDeleteComputeInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrDeleteComputeInstance_IMPL
              (long param_1,undefined8 param_2,long param_3,uint param_4,char param_5)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  int local_4c;
  long local_48 [3];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x15eb);
    return 0x1f;
  }
  if (7 < param_4) {
    nvAssertFailedNoLog("CIID < NV_ARRAY_ELEMENTS(pKernelMIGGpuInstance->MIGComputeInstance)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x15ec);
    return 0x1f;
  }
  uVar9 = (ulong)param_4;
  lVar4 = uVar9 * 0x110 + param_3;
  if (*(char *)(lVar4 + 0x198) == '\0') {
    return 0x10006;
  }
  if ((*(long *)(lVar4 + 0x1a8) != 0) && (iVar3 = serverGetShareRefCount(g_resServ), 2 < iVar3)) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x15fe,
                 "kmigmgrDeleteComputeInstance_IMPL",4,
                 "NVRM: Compute Instance with id - %d still in use by other clients\n",param_4);
    return 99;
  }
  lVar4 = uVar9 * 0x110;
  if (param_5 == '\0') {
    osRmCapUnregister(param_3 + 0x1b0 + lVar4);
  }
  cVar2 = gpuIsClassSupported_IMPL(param_1,0x8f);
  if ((cVar2 != '\0') &&
     ((*(char *)(param_1 + 0x909) == '\0' || (*(char *)(param_1 + 0x4a4e) == '\0')))) {
    lVar5 = param_3 + uVar9 * 0x110;
    if (*(long *)(lVar5 + 0x1e8) == 0) {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1183,"_kmigmgrFreeKernelWatchdog"
                   ,3,"NVRM: Freeing Kernel Watchdog while it\'s already freed.\n");
    }
    else if ((*(char *)(lVar5 + 0x198) != '\0') && (*(int *)(lVar5 + 0x164) != 0)) {
      lVar7 = rmapiGetInterface(4);
      uVar8 = *(undefined8 *)(param_1 + 0x1c18);
      uVar1 = *(undefined4 *)(lVar5 + 0x164);
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x118e,"_kmigmgrFreeKernelWatchdog"
                   ,1,"NVRM: Freeing KERNEL_WATCHDOG object for CI hClient 0x%x, gfxGpcCount(%d)\n",
                   *(undefined4 *)(lVar5 + 0x1c8));
      iVar3 = serverutilGetResourceRefWithType
                        (*(undefined4 *)(lVar5 + 0x1c8),0x31425900,0x7ace3d,local_48);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "serverutilGetResourceRefWithType(pMIGComputeInstance->instanceHandles.hClient, KERNEL_WATCHDOG_OBJECT_ID, classId(KernelWatchdog), &pKernelWatchdogRef)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1192);
LAB_003f3419:
        nvAssertOkFailedNoLog
                  (iVar3,"_kmigmgrFreeKernelWatchdog(pGpu, pMIGComputeInstance)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1614);
        return iVar3;
      }
      lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48[0] + 8),__nvoc_class_def_KernelWatchdog,
                                 uVar1,0x3f30b0);
      if (lVar6 == 0) {
        iVar3 = 0x40;
        nvAssertFailedNoLog("pKernelWatchdog != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                            0x1199);
        goto LAB_003f3419;
      }
      iVar3 = krcWatchdogShutdown_IMPL(param_1,uVar8,lVar6);
      if (iVar3 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar3,"krcWatchdogShutdown(pGpu, pKernelRc, pKernelWatchdog)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x119b);
        goto LAB_003f3419;
      }
      (**(code **)(lVar7 + 0x18))(lVar7,*(undefined4 *)(lVar5 + 0x1c8),0x31425900);
      *(undefined8 *)(lVar5 + 0x1e8) = 0;
    }
  }
  uVar1 = *(undefined4 *)(param_3 + 0x968);
  lVar5 = portMemAllocNonPaged(0x100);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pConfigRequestPerCi != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                        0x161b);
    return 0x51;
  }
  portMemSet(lVar5,0,0x100);
  bitVectorClrAll_IMPL(local_48,0x54);
  bitVectorSetRange_IMPL(local_48,0x54,1,8);
  bitVectorAnd_IMPL(local_48,0x54,local_48,0x54,param_3 + 0x170 + lVar4,0x54);
  cVar2 = bitVectorTestAllCleared_IMPL(local_48,0x54);
  if (cVar2 != '\0') {
    iVar3 = 0x40;
    nvAssertFailedNoLog("!bitVectorTestAllCleared(&grEngines)",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1622);
    goto LAB_003f3034;
  }
  cVar2 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
  iVar3 = kmigmgrConfigureGPUInstance_IMPL(param_1,param_2,uVar1,lVar5,1 << (cVar2 - 1U & 0x1f));
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,
               "kmigmgrConfigureGPUInstance(pGpu, pKernelMIGManager, swizzId, pConfigRequestPerCi, updateEngMask)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1624);
    goto LAB_003f3034;
  }
  lVar4 = param_3 + 0xe0 + lVar4;
  iVar3 = kmigmgrGetLocalToGlobalEngineType_IMPL(param_1,param_2,param_3,lVar4,1,&local_4c);
  if (iVar3 == 0) {
    lVar7 = param_3 + uVar9 * 0x110;
    if (*(int *)(lVar7 + 0x1c8) != 0) {
      lVar6 = rmapiGetInterface(4);
      (**(code **)(lVar6 + 0x18))
                (lVar6,*(undefined4 *)(lVar7 + 0x1c8),*(undefined4 *)(lVar7 + 0x1c8));
      *(undefined4 *)(lVar7 + 0x1c8) = 0;
      *(undefined8 *)(param_3 + 0x1d0 + uVar9 * 0x110) = 0;
    }
    iVar3 = bitVectorCountTrailingZeros_IMPL(local_48,0x54);
    uVar8 = 0;
    if (local_4c - 1U < 8) {
      uVar8 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)(local_4c - 1U) * 8);
    }
    fecsSetRoutingInfo(param_1,uVar8,*(undefined4 *)(param_3 + 0x9c0),
                       *(undefined4 *)(param_3 + 0x9c8),iVar3 + -1);
    lVar7 = uVar9 * 0x110 + param_3;
    if (*(long *)(lVar7 + 0x1a8) != 0) {
      serverFreeShare(g_resServ);
      *(undefined8 *)(lVar7 + 0x1a8) = 0;
    }
    lVar7 = uVar9 * 0x110 + param_3;
    *(undefined1 *)(lVar7 + 0x198) = 0;
    kmigmgrReleaseComputeInstanceEngines_IMPL(param_1,param_2,param_3,lVar4);
    if (*(char *)(param_1 + 0x908) != '\0') {
      lVar4 = *(long *)(param_1 + 0x1d20);
      lVar6 = gpuGetStaticInfo(param_1);
      if (lVar6 == 0) {
        nvAssertOkFailedNoLog
                  (0x1f,"pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x164b);
        goto LAB_003f339d;
      }
      if (((lVar4 != 0) && ((*(byte *)(lVar6 + 0xa727) & 1) != 0)) &&
         (iVar3 = kccuDeInitVgpuMigSharedBuffer_IMPL
                            (param_1,lVar4,uVar1,*(undefined4 *)(lVar7 + 0x1a0)), iVar3 != 0)) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1655,
                     "kmigmgrDeleteComputeInstance_IMPL",3,
                     "NVRM: De-initialization process of the MIG GPM buffer for vGPU failed.\n");
      }
    }
    *(undefined8 *)(param_3 + 0x19c + uVar9 * 0x110) = 0xffffffff00000000;
    *(undefined8 *)(param_3 + 0x1b0 + uVar9 * 0x110) = 0;
    iVar3 = 0;
  }
  else {
    nvAssertOkFailedNoLog
              (0x1f,
               "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(0), &globalRmEngType)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x162b);
LAB_003f339d:
    iVar3 = 0x1f;
  }
LAB_003f3034:
  portMemFree(lVar5);
  return iVar3;
}


// ===== 003f348b kmigmgrUpdateCiConfigForVgpu_IMPL.cold =====

void kmigmgrUpdateCiConfigForVgpu_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003f34a0 kmigmgrUpdateCiConfigForVgpu_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrUpdateCiConfigForVgpu_IMPL
              (long param_1,long param_2,uint param_3,undefined4 *param_4,undefined4 param_5,
              char param_6)

{
  undefined4 *puVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  undefined8 uVar7;
  long local_140;
  undefined8 local_138;
  long local_130;
  long local_128;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 *local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100 [2];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a0;
  undefined4 local_9c;
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
  undefined4 local_48;
  
  lVar5 = rmapiGetInterface(4);
  if ((((*(char *)(param_1 + 0x909) == '\0') || (lVar2 = *(long *)(param_1 + 0x1bc0), lVar2 == 0))
      || (*(char *)(param_1 + 0x467) == '\0')) ||
     (((*(char *)(lVar2 + 0x5340) == '\0' || (*(long *)(lVar2 + 0x5348) == 0)) ||
      (*(char *)(param_1 + 0x4a4e) == '\0')))) {
    iVar4 = 0x56;
  }
  else if (param_3 < 9) {
    iVar4 = kvgpumgrGetHostVgpuDeviceFromGfid(*(undefined4 *)(param_1 + 0x7ac),param_5,&local_140);
    uVar7 = 0x1ccf;
    pcVar6 = "kvgpumgrGetHostVgpuDeviceFromGfid(pGpu->gpuId, gfid, &pKernelHostVgpuDevice)";
    if (iVar4 == 0) {
      iVar4 = serverGetClientUnderLock
                        (g_resServ,*(undefined4 *)(local_140 + 4),&local_138,
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ccf);
      uVar7 = 0x1cd2;
      pcVar6 = "serverGetClientUnderLock(&g_resServ, pKernelHostVgpuDevice->hMigClient, &pRsClient)"
      ;
      if (iVar4 == 0) {
        iVar4 = subdeviceGetByInstance_IMPL
                          (local_138,*(undefined4 *)(local_140 + 8),0,&local_128,0x1cd2);
        if (iVar4 == 0) {
          if (local_128 == 0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          iVar4 = gisubscriptionGetGPUInstanceSubscription_IMPL
                            (local_138,
                             *(undefined4 *)(*(long *)(*(long *)(local_128 + 0x140) + 0x48) + 0x10),
                             &local_130);
          if (iVar4 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar4,
                       "gisubscriptionGetGPUInstanceSubscription(pRsClient, RES_GET_HANDLE(pSubdevice), &pGPUInstanceSubscription)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1cd7);
            return iVar4;
          }
          lVar2 = *(long *)(local_130 + 0x138);
          if (param_6 == '\0') {
            if (param_3 != 0) {
              puVar1 = param_4 + param_3;
              do {
                local_120 = 1;
                local_118 = &local_a0;
                portMemSet(local_100,0,0x60);
                local_100[0] = *param_4;
                iVar4 = (**(code **)(lVar5 + 0x38))
                                  (lVar5,*(undefined4 *)(lVar2 + 0x9c0),
                                   *(undefined4 *)(lVar2 + 0x9cc),0xc6370105,local_100,0x60);
                if (iVar4 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar4,
                             "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_EXPORT, &execPartExportParams, sizeof(execPartExportParams))"
                             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1cef);
LAB_003f38ae:
                  portMemSet(&local_a0,0,0x24);
                  local_9c = *param_4;
                  local_a0 = 1;
                  lVar5 = gpuGetRpc(param_1);
                  if (lVar5 != 0) {
                    return iVar4;
                  }
                  nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                                      0x1d1a);
                  return 0x1a;
                }
                portMemSet(&local_a0,0,0x68);
                local_48 = *param_4;
                local_a0 = CONCAT31(local_a0._1_3_,1);
                local_98 = local_f8;
                local_90 = local_f0;
                local_88 = local_e8;
                local_80 = local_e0;
                local_78 = local_d8;
                local_70 = local_d0;
                local_68 = local_c8;
                local_60 = local_c0;
                local_58 = local_b8;
                local_50 = local_b0;
                iVar4 = (**(code **)(param_2 + 0x218))
                                  (param_1,param_2,lVar2,0,param_4,1,CONCAT44(uStack_11c,local_120),
                                   local_118,local_110,local_108);
                if (iVar4 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar4,
                             "kmigmgrCreateComputeInstances_HAL(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, NV_FALSE, restore, &pExecPartId[i], NV_TRUE)"
                             ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1cfd);
                  goto LAB_003f38ae;
                }
                param_4 = param_4 + 1;
              } while (puVar1 != param_4);
            }
          }
          else if (param_3 != 0) {
            puVar1 = param_4 + param_3;
            do {
              iVar4 = kmigmgrDeleteComputeInstance_IMPL(param_1,param_2,lVar2,*param_4,0);
              if (iVar4 != 0) {
                uVar7 = 0x1d07;
                pcVar6 = 
                "kmigmgrDeleteComputeInstance(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, pExecPartId[i], NV_FALSE)"
                ;
                goto LAB_003f3699;
              }
              param_4 = param_4 + 1;
            } while (puVar1 != param_4);
          }
          gpuNotifySubDeviceEvent_IMPL(param_1,0x9f,0,0,0,0);
          return 0;
        }
        uVar7 = 0x1cd4;
        pcVar6 = 
        "subdeviceGetByInstance(pRsClient, pKernelHostVgpuDevice->hMigDevice, 0, &pSubdevice)";
      }
    }
LAB_003f3699:
    nvCheckOkFailedNoLog(4,iVar4,pcVar6,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar7);
  }
  else {
    nvAssertFailedNoLog("execPartCount <= NVC637_CTRL_MAX_EXEC_PARTITIONS",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1ccb);
    iVar4 = 0x1f;
  }
  return iVar4;
}


// ===== 003f3a00 _kmigmgrHandlePreSchedulingDisableCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kmigmgrHandlePreSchedulingDisableCallback(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 local_1c0;
  int local_1bc;
  undefined4 local_1b8;
  undefined1 local_1a0;
  
  lVar2 = *(long *)(param_1 + 0x1bc0);
  puVar6 = (undefined8 *)(lVar2 + 0xc00);
  do {
    while ((((*(char *)(puVar6 + 1) == '\0' || (*(char *)((long)puVar6 + 9) == '\0')) ||
            (*(char *)(*(long *)(param_1 + 0x1b78) + 0x480) == '\0')) ||
           (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) == '\0'))) {
      puVar6 = puVar6 + 0x143;
      if (puVar6 == (undefined8 *)(lVar2 + 0x5cc0)) goto LAB_003f3a90;
    }
    puVar7 = puVar6 + 0x143;
    scrubberDestruct(param_1,*puVar6);
    *(undefined1 *)((long)puVar6 + 9) = 0;
    puVar6 = puVar7;
  } while (puVar7 != (undefined8 *)(lVar2 + 0x5cc0));
LAB_003f3a90:
  iVar4 = kmigmgrSaveToPersistence_IMPL(param_1,lVar2);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (0x1f,"kmigmgrSaveToPersistence(pGpu, pKernelMIGManager)",
               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x433);
  }
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) {
    bVar3 = false;
    pcVar9 = (char *)(lVar2 + 0x418);
    do {
      while (pcVar9[0x7f0] == '\0') {
        pcVar9 = pcVar9 + 0xa18;
        if (pcVar9 == (char *)(lVar2 + 0x54d8)) goto LAB_003f3ca6;
      }
      iVar4 = 0;
      uVar1 = *(undefined4 *)(pcVar9 + 2000);
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x444,
                   "_kmigmgrHandlePreSchedulingDisableCallback",1,
                   "NVRM: Invalidating valid gpu instance with swizzId = %d\n",uVar1);
      pcVar8 = pcVar9;
      do {
        while (*pcVar8 == '\0') {
LAB_003f3b60:
          iVar4 = iVar4 + 1;
          pcVar8 = pcVar8 + 0x110;
          if (iVar4 == 8) goto LAB_003f3c60;
        }
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x454,
                     "_kmigmgrHandlePreSchedulingDisableCallback",1,
                     "NVRM: Invalidating valid compute instance with id = %d\n",iVar4);
        iVar5 = kmigmgrDeleteComputeInstance_IMPL(param_1,lVar2,pcVar9 + -0x198,iVar4,1);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "kmigmgrDeleteComputeInstance(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, CIIdx, NV_TRUE)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x458);
        }
        if (*(char *)(param_1 + 0x909) == '\0') goto LAB_003f3b60;
        portMemSet(&local_1c0,0,0x24);
        local_1c0 = 1;
        local_1bc = iVar4;
        iVar5 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(pcVar9 + 0x828),
                           *(undefined4 *)(pcVar9 + 0x834),0xc6370102,&local_1c0,0x24);
        if (iVar5 == 0) goto LAB_003f3b60;
        iVar4 = iVar4 + 1;
        pcVar8 = pcVar8 + 0x110;
        nvAssertOkFailedNoLog
                  (iVar5,
                   "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_DELETE, &params, sizeof(params))"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x464);
      } while (iVar4 != 8);
LAB_003f3c60:
      iVar4 = kmigmgrInvalidateGPUInstance_IMPL(param_1,lVar2,uVar1,1);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,"kmigmgrInvalidateGPUInstance(pGpu, pKernelMIGManager, swizzId, NV_TRUE)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x46e);
      }
      if (*(char *)(param_1 + 0x909) != '\0') {
        portMemSet(&local_1c0,0,0x188);
        local_1c0 = 1;
        local_1a0 = 0;
        local_1b8 = uVar1;
        iVar4 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x20800aa5,&local_1c0,0x188);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_GPU_INSTANCES, &params, sizeof(params))"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x47b);
        }
      }
      bVar3 = true;
      pcVar9 = pcVar9 + 0xa18;
    } while (pcVar9 != (char *)(lVar2 + 0x54d8));
LAB_003f3ca6:
    if (*(long *)(lVar2 + 0x5348) != 0) {
      nvAssertFailedNoLog(&DAT_00d5ccbb,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x48b);
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x48c,
                   "_kmigmgrHandlePreSchedulingDisableCallback",4,
                   "NVRM: leaked swizzid mask 0x%llx !!\n",*(undefined8 *)(lVar2 + 0x5348));
    }
    if ((bVar3) && (iVar4 = (**(code **)(lVar2 + 0x250))(param_1,lVar2,1,0,1), iVar4 != 0)) {
      nvAssertOkFailedNoLog
                (iVar4,"kmigmgrSetMIGState(pGpu, pKernelMIGManager, NV_TRUE, NV_FALSE, NV_TRUE)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x491);
    }
  }
  return 0;
}


// ===== 003f3e80 kmigmgrRestoreFromPersistence_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrRestoreFromPersistence_VF(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  long lVar7;
  int iVar8;
  uint *puVar9;
  undefined8 uVar10;
  long lVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  ulong uVar15;
  uint local_a4;
  long local_a0;
  undefined1 local_98 [24];
  undefined4 local_80;
  undefined4 uStack_7c;
  char *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_a0 = 0;
  cVar2 = gpumgrGetSystemMIGInstanceTopo_IMPL(*(undefined8 *)(param_1 + 0x878),&local_a0);
  if (cVar2 != '\0') {
    iVar8 = 0;
    pcVar6 = (char *)(local_a0 + 0x18);
    do {
      if (*pcVar6 != '\0') {
        if (((*(long *)(param_1 + 0x1bc0) == 0) || (*(char *)(param_1 + 0x467) == '\0')) ||
           (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) == '\0')) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb31,
                       "kmigmgrRestoreFromPersistence_VF",3,
                       "NVRM: Skipping reinitialization of persistent MIG instances due to MIG disablement!\n"
                      );
          gpumgrUnregisterRmCapsForMIGGI_IMPL(*(undefined8 *)(param_1 + 0x878));
          return 0;
        }
        uVar3 = (**(code **)(param_2 + 0x228))(param_1,param_2,*(undefined4 *)(local_a0 + 0x58));
        iVar8 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar3,1,0);
        if (iVar8 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar8,
                     "kmigmgrSetMIGState(pGpu, pKernelMIGManager, bMemoryPartitioningNeeded, NV_TRUE, NV_FALSE)"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb39);
          return iVar8;
        }
        lVar11 = 0;
        uVar15 = 0;
        goto LAB_003f3f9b;
      }
      iVar8 = iVar8 + 1;
      pcVar6 = pcVar6 + 0x390;
    } while (iVar8 != 8);
  }
  return 0;
LAB_003f3f9b:
  lVar1 = local_a0;
  local_60 = 1;
  local_58 = local_a0 + 0x18 + lVar11;
  lVar7 = uVar15 * 0x390 + local_a0;
  if (*(char *)(lVar7 + 0x18) != '\0') {
    uVar14 = *(uint *)(lVar7 + 0x58);
    iVar8 = (**(code **)(param_2 + 0x210))(param_1,param_2,uVar14,local_98);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"kmigmgrGenerateGPUInstanceUuid_HAL(pGpu, pKernelMIGManager, swizzId, &uuid)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb4b);
LAB_003f4112:
      pcVar6 = (char *)(param_2 + 0x418);
      do {
        if (pcVar6[0x7f0] != '\0') {
          iVar13 = 0;
          pcVar12 = pcVar6;
          do {
            if ((*pcVar12 != '\0') &&
               (iVar5 = kmigmgrDeleteComputeInstance_IMPL(param_1,param_2,pcVar6 + -0x198,iVar13,1),
               iVar5 != 0)) {
              nvCheckOkFailedNoLog
                        (4,iVar5,
                         "kmigmgrDeleteComputeInstance(pGpu, pKernelMIGManager, pKernelMIGGPUInstance, CIIdx, NV_TRUE)"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb86);
            }
            iVar13 = iVar13 + 1;
            pcVar12 = pcVar12 + 0x110;
          } while (iVar13 != 8);
          iVar13 = kmigmgrInvalidateGPUInstance_IMPL
                             (param_1,param_2,*(undefined4 *)(pcVar6 + 2000),1);
          if (iVar13 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar13,
                       "kmigmgrInvalidateGPUInstance(pGpu, pKernelMIGManager, pKernelMIGGPUInstance->swizzId, NV_TRUE)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb8a);
          }
        }
        pcVar6 = pcVar6 + 0xa18;
      } while (pcVar6 != (char *)(param_2 + 0x54d8));
      iVar13 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar3,0,0);
      if (iVar13 == 0) {
        return iVar8;
      }
      nvCheckOkFailedNoLog
                (4,iVar13,
                 "kmigmgrSetMIGState(pGpu, pKernelMIGManager, bMemoryPartitioningNeeded, NV_FALSE, NV_FALSE)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb8f);
      return iVar8;
    }
    iVar8 = kmigmgrCreateGPUInstance_IMPL
                      (param_1,param_2,uVar14,local_98,1,0,CONCAT44(uStack_5c,local_60),local_58,
                       local_50,local_48,local_40);
    if (iVar8 != 0) {
      uVar10 = 0xb50;
      pcVar6 = 
      "kmigmgrCreateGPUInstance(pGpu, pKernelMIGManager, swizzId, uuid.uuid, restore, NV_TRUE, NV_FALSE)"
      ;
LAB_003f4380:
      nvCheckOkFailedNoLog(3,iVar8,pcVar6,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar10);
      goto LAB_003f4112;
    }
    if (0xe < uVar14) {
LAB_003f40de:
      nvAssertOkFailedNoLog
                (0x1f,
                 "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pKernelMIGGPUInstance)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0xb54);
      iVar8 = 0x1f;
      goto LAB_003f4112;
    }
    puVar9 = (uint *)(param_2 + 0xbe8);
    uVar4 = 0;
    while (((char)puVar9[8] == '\0' || (uVar14 != *puVar9))) {
      uVar4 = uVar4 + 1;
      puVar9 = puVar9 + 0x286;
      if (uVar4 == 8) goto LAB_003f40de;
    }
    lVar7 = (ulong)uVar4 * 0xa18;
    pcVar6 = (char *)(lVar1 + 0x68 + lVar11);
    *(undefined8 *)(param_2 + 0xc38 + lVar7) = *(undefined8 *)(lVar1 + 0x60 + uVar15 * 0x390);
    do {
      local_a4 = *(uint *)(pcVar6 + 0x58);
      local_80 = 1;
      local_78 = pcVar6;
      if (*pcVar6 != '\0') {
        iVar8 = (**(code **)(param_2 + 0x218))
                          (param_1,param_2,param_2 + 0x280 + lVar7,0,&local_a4,0,
                           CONCAT44(uStack_7c,1),pcVar6,local_70,local_68);
        if (iVar8 != 0) {
          uVar10 = 0xb6e;
          pcVar6 = 
          "kmigmgrCreateComputeInstances_HAL(pGpu, pKernelMIGManager, pKernelMIGGPUInstance, NV_FALSE, restore, &id, NV_FALSE)"
          ;
          goto LAB_003f4380;
        }
        *(undefined8 *)(param_2 + 0x430 + (ulong)local_a4 * 0x110 + lVar7) =
             *(undefined8 *)(pcVar6 + 0x60);
      }
      pcVar6 = pcVar6 + 0x68;
    } while (pcVar6 != (char *)(lVar1 + 0x3a8 + lVar11));
  }
  uVar14 = (int)uVar15 + 1;
  uVar15 = (ulong)uVar14;
  lVar11 = lVar11 + 0x390;
  if (uVar14 == 8) {
    return 0;
  }
  goto LAB_003f3f9b;
}


// ===== 003f4470 kmigmgrGetSlotBasisMask_IMPL =====

undefined8 kmigmgrGetSlotBasisMask_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 auVar4 [16];
  undefined1 local_40 [24];
  
  if (param_3 == (long *)0x0) {
    nvCheckFailedNoLog(4,"pMask != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2424);
    return 0x1f;
  }
  iVar3 = 5;
  do {
    iVar2 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,iVar3,local_40);
    if (iVar2 == 0) break;
    iVar3 = kmigmgrGetNextComputeSize_IMPL(param_1,param_2,0,iVar3);
  } while (iVar3 != 8);
  auVar4 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(iVar3);
  if (auVar4._0_8_ <= auVar4._8_8_) {
    bVar1 = auVar4[0] & 0x3f;
    *param_3 = (0xffffffffffffffffU >> ((~auVar4[8] & 0x3f) + bVar1 & 0x3f)) << bVar1;
    return 0;
  }
  nvAssertFailedNoLog("!rangeIsEmpty(slotBasisIdRange)",
                      "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2429);
  return 0x40;
}


// ===== 003f4580 kmigmgrXlateSpanStartToCTSId_IMPL =====

ulong kmigmgrXlateSpanStartToCTSId_IMPL
                (undefined8 param_1,undefined8 param_2,int param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  undefined1 auVar5 [16];
  ulong local_70 [8];
  undefined *local_30;
  ulong local_28;
  
  if (param_5 == (uint *)0x0) {
    nvAssertFailedNoLog("pCtsId != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23ed);
  }
  else {
    *param_5 = 0xffffffff;
    if (param_3 == 8) {
      nvCheckFailedNoLog(3,"computeSize != KMIGMGR_COMPUTE_SIZE_INVALID",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23f5);
      return 0;
    }
    uVar1 = kmigmgrGetSlotBasisMask_IMPL(param_1,param_2,local_70);
    if (uVar1 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar1,"kmigmgrGetSlotBasisMask(pGpu, pKernelMIGManager, &slotBasisMask)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23f6);
      return (ulong)uVar1;
    }
    uVar2 = local_70[0] - (local_70[0] >> 1 & 0x5555555555555555);
    uVar2 = (uVar2 & 0x3333333333333333) + (uVar2 >> 2 & 0x3333333333333333);
    if (param_4 < (byte)(((uVar2 >> 4) + uVar2 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38)) {
      puVar3 = local_70 + 1;
      auVar5 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(param_3);
      local_70[1] = 0x222b;
      uVar2 = 0xffffffffffe00000;
      local_70[2] = 0x422b;
      local_70[3] = 0x844b;
      local_70[4] = 0x1044b;
      local_70[5] = 0x20895;
      local_70[6] = 0x40895;
      local_70[7] = 0x81115;
      local_30 = &DAT_00101115;
      do {
        uVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        uVar2 = uVar2 | -(ulong)((uint)(uVar4 >> (auVar5[0] & 0x3f)) & 1) & uVar4;
      } while (&local_28 != puVar3);
      uVar2 = (local_70[0] & uVar2) - ((local_70[0] & uVar2) >> 1 & 0x5555555555555555);
      uVar2 = (uVar2 & 0x3333333333333333) + (uVar2 >> 2 & 0x3333333333333333);
      uVar4 = ((uVar2 >> 4) + uVar2 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
      uVar2 = (ulong)param_4 % uVar4;
      if ((int)uVar2 == 0) {
        uVar1 = (int)(param_4 / uVar4) + auVar5._0_4_;
        *param_5 = uVar1;
        if ((auVar5._0_8_ <= (ulong)uVar1) && ((ulong)uVar1 <= auVar5._8_8_)) {
          return uVar2;
        }
        nvAssertFailedNoLog("(computeSizeIdRange.lo <= *pCtsId) && (*pCtsId <= computeSizeIdRange.hi)"
                            ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x240c);
        return uVar2;
      }
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2405,
                   "kmigmgrXlateSpanStartToCTSId_IMPL",4,
                   "NVRM: Compute span start of %d is not aligned\n",param_4);
    }
    else {
      nvCheckFailedNoLog(4,"spanStart < nvPopCount64(slotBasisMask)",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x23f9);
    }
  }
  return 0x1f;
}


// ===== 003f48c0 kmigmgrGetSpanStartFromCTSId_IMPL =====

int kmigmgrGetSpanStartFromCTSId_IMPL(undefined8 param_1,undefined8 param_2,int param_3)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong local_70;
  ulong local_68 [7];
  undefined *local_30;
  ulong local_28;
  
  iVar2 = kmigmgrGetComputeSizeFromCTSId_IMPL(param_1,param_3);
  if (iVar2 != 8) {
    iVar3 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(iVar2,param_2);
    iVar2 = kmigmgrGetSlotBasisMask_IMPL(param_1);
    if (iVar2 == 0) {
      local_68[0] = 0x222b;
      puVar4 = local_68;
      uVar5 = 0xffffffffffe00000;
      local_68[1] = 0x422b;
      local_68[2] = 0x844b;
      local_68[3] = 0x1044b;
      local_68[4] = 0x20895;
      local_68[5] = 0x40895;
      local_68[6] = 0x81115;
      local_30 = &DAT_00101115;
      do {
        uVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        uVar5 = uVar5 | -(ulong)((uint)(uVar1 >> ((byte)iVar3 & 0x3f)) & 1) & uVar1;
      } while (puVar4 != &local_28);
      uVar5 = (uVar5 & local_70) - ((uVar5 & local_70) >> 1 & 0x5555555555555555);
      uVar5 = (uVar5 & 0x3333333333333333) + (uVar5 >> 2 & 0x3333333333333333);
      iVar2 = (uint)(byte)(((uVar5 >> 4) + uVar5 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38) *
              (param_3 - iVar3);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar2,"kmigmgrGetSlotBasisMask(pGpu, pKernelMIGManager, &slotBasisMask)",
                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x244a);
    }
    return iVar2;
  }
  nvCheckFailedNoLog(3,"computeSize != KMIGMGR_COMPUTE_SIZE_INVALID",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2446);
  return 0;
}


// ===== 003f4a80 kmigmgrIsCTSIdAvailable_IMPL =====

bool kmigmgrIsCTSIdAvailable_IMPL
               (undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4,ulong param_5)

{
  ulong uVar1;
  byte bVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  ulong local_48 [8];
  
  if (param_4 != 0) {
    uVar5 = 0;
    bVar2 = 0;
    while( true ) {
      for (; (param_4 & 1) == 0; param_4 = param_4 >> 1) {
        bVar2 = bVar2 + 1;
      }
      local_48[0] = 0x222b;
      puVar3 = local_48;
      uVar4 = 0xffffffffffe00000;
      local_48[1] = 0x422b;
      do {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 | -(ulong)((uint)(uVar1 >> (bVar2 & 0x3f)) & 1) & uVar1;
      } while ((ulong *)&stack0xfffffffffffffff8 != puVar3);
      uVar5 = uVar5 | uVar4;
      param_4 = param_4 >> 1;
      if (param_4 == 0) break;
      bVar2 = bVar2 + 1;
    }
    return ((param_3 & ~uVar5) >> (param_5 & 0x3f) & 1) != 0;
  }
  return (param_3 >> (param_5 & 0x3f) & 1) != 0;
}


// ===== 003f4b60 kmigmgrCreateComputeInstances_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrCreateComputeInstances_FWCLIENT
              (long param_1,long param_2,long *param_3,char param_4,uint *param_5,char param_6,
              int param_7,char *param_8)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  undefined1 *puVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  undefined8 uVar15;
  char local_98 [4];
  int local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14b3);
    return 0x1f;
  }
  if (param_7 != 1) {
    nvAssertFailedNoLog("params.type == KMIGMGR_CREATE_COMPUTE_INSTANCE_PARAMS_TYPE_RESTORE",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14b4);
    return 0x1f;
  }
  if (param_8 == (char *)0x0) {
    nvAssertFailedNoLog("params.inst.restore.pComputeInstanceSave != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14b5);
    return 0x1f;
  }
  if (*param_8 == '\0') {
    nvAssertFailedNoLog("params.inst.restore.pComputeInstanceSave->bValid",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14b6);
    return 0x1f;
  }
  if (param_4 != '\0') {
    nvAssertFailedNoLog("!bQuery","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14b9);
    return 0x1f;
  }
  lVar5 = *(long *)(param_1 + 0x1bc8);
  uVar3 = *param_5;
  lVar10 = portMemAllocNonPaged(0x110);
  if (lVar10 == 0) {
    nvCheckFailedNoLog(2,"pMIGComputeInstance != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c"
                       ,0x14bc);
    return 0x51;
  }
  portMemSet(lVar10,0,0x110);
  if (*(char *)(lVar10 + 0xb8) != '\0') {
    nvAssertFailedNoLog("!pMIGComputeInstance->bValid","src/kernel/gpu/mig_mgr/kernel_mig_manager.c"
                        ,0x14c3);
    return 0x40;
  }
  puVar11 = (undefined1 *)portMemAllocNonPaged(0x100);
  if (puVar11 == (undefined1 *)0x0) {
    nvAssertFailedNoLog("pConfigRequestPerCi != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                        0x14c6);
    return 0x51;
  }
  portMemSet(puVar11,0,0x100);
  local_88 = *(undefined8 *)(param_8 + 8);
  local_80 = *(undefined8 *)(param_8 + 0x10);
  local_78 = *(undefined8 *)(param_8 + 0x18);
  local_70 = *(undefined8 *)(param_8 + 0x20);
  local_68 = *(undefined8 *)(param_8 + 0x28);
  local_60 = *(undefined8 *)(param_8 + 0x30);
  local_58 = *(undefined8 *)(param_8 + 0x38);
  local_50 = (undefined4)*(undefined8 *)(param_8 + 0x40);
  uStack_4c = (undefined4)((ulong)*(undefined8 *)(param_8 + 0x40) >> 0x20);
  local_48 = (undefined4)*(undefined8 *)(param_8 + 0x48);
  uStack_44 = (undefined4)((ulong)*(undefined8 *)(param_8 + 0x48) >> 0x20);
  local_40 = *(ulong *)(param_8 + 0x50);
  cVar7 = (**(code **)(param_2 + 0x260))(param_1);
  if (cVar7 == '\0') {
    *(undefined4 *)(puVar11 + 0x18) = 0xffffffff;
  }
  else {
    iVar8 = kmigmgrXlateSpanStartToCTSId_IMPL
                      (param_1,param_2,local_40._4_4_,local_40 & 0xffffffff,puVar11 + 0x18);
    if (iVar8 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar8,
                 "kmigmgrXlateSpanStartToCTSId(pGpu, pKernelMIGManager, info.computeSize, info.spanStart, &pConfigRequestPerCi[0].ctsId)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14cf);
      goto LAB_003f5090;
    }
    cVar7 = kmigmgrIsCTSIdAvailable_IMPL
                      (param_1,param_2,*(undefined8 *)(*param_3 + 0x38),param_3[0x13b],
                       *(undefined4 *)(puVar11 + 0x18));
    if (cVar7 != '\x01') {
      nvCheckFailedNoLog(4,
                         "kmigmgrIsCTSIdAvailable(pGpu, pKernelMIGManager, pKernelMIGGpuInstance->pProfile->validCTSIdMask, pKernelMIGGpuInstance->ctsIdsInUseMask, pConfigRequestPerCi[0].ctsId)"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x14d6);
      iVar8 = 99;
      goto LAB_003f5090;
    }
  }
  portMemCopy(lVar10 + 0xd8,0x10,&local_68,0x10);
  *(undefined4 *)(lVar10 + 0x80) = 0;
  *(undefined4 *)(lVar10 + 0xbc) = (undefined4)local_58;
  if (local_58._4_4_ != 0) {
    lVar1 = 1;
    uVar13 = local_58._4_4_;
    do {
      lVar14 = lVar1;
      iVar8 = 0;
      for (uVar6 = uVar13; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
        iVar8 = iVar8 + 1;
      }
      *(int *)(lVar10 + -4 + lVar14 * 4) = iVar8;
      uVar13 = uVar13 & ~(1 << ((byte)iVar8 & 0x1f));
      lVar1 = lVar14 + 1;
    } while (uVar13 != 0);
    *(int *)(lVar10 + 0x80) = (int)lVar14;
  }
  lVar1 = lVar10 + 0x90;
  *(undefined4 *)(lVar10 + 0x84) = local_50;
  *(ulong *)(lVar10 + 0x88) = CONCAT44(local_48,uStack_4c);
  *(undefined4 *)(lVar10 + 0xb4) = uStack_44;
  *(undefined4 *)(lVar10 + 0x100) = local_40._4_4_;
  bitVectorFromRaw_IMPL(lVar1,0x54,&local_88,0x20);
  lVar14 = lVar10 + 0xa0;
  kmigmgrGetLocalEngineMask_IMPL(param_1,lVar1,lVar14);
  *(undefined1 *)(lVar10 + 0xb8) = 1;
  *(uint *)(lVar10 + 0xc0) = uVar3;
  iVar8 = kmigmgrEngineTypeXlate_IMPL(lVar14,1,lVar1,local_98);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,
               "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &localEngineType)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1503);
  }
  *puVar11 = (char)(local_40 >> 0x20);
  *(undefined4 *)(puVar11 + 0x10) = *(undefined4 *)(lVar10 + 0xb4);
  *(undefined4 *)(puVar11 + 8) = *(undefined4 *)(lVar10 + 0x80);
  uVar4 = *(undefined4 *)(lVar10 + 0x8c);
  *(undefined4 *)(puVar11 + 0xc) = uVar4;
  *(undefined4 *)(puVar11 + 0x1c) = (undefined4)local_40;
  local_90 = *(undefined8 *)(lVar5 + 0x440);
  iVar8 = kgrmgrCheckVeidsRequest_IMPL(param_1,lVar5,&local_90,uVar4,puVar11 + 0x1c,param_3);
  if (iVar8 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar8,
               "kgrmgrCheckVeidsRequest(pGpu, pKernelGraphicsManager, &shadowVeidInUseMask, pConfigRequestPerCi[0].profile.veidCount, &pConfigRequestPerCi[0].veidSpanStart, pKernelMIGGpuInstance)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x150f);
    goto LAB_003f5090;
  }
  uVar12 = (ulong)uVar3;
  if ((int)param_3[uVar12 * 0x22 + 0x34] != -1) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance->MIGComputeInstance[CIIdx].id == KMIGMGR_COMPUTE_INSTANCE_ID_INVALID"
                        ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1518);
  }
  *(undefined4 *)(lVar10 + 0xfc) = *(undefined4 *)(puVar11 + 0x1c);
  plVar2 = param_3 + uVar12 * 0x22 + 0x1c;
  portMemCopy(plVar2,0x110,lVar10,0x110);
  iVar9 = 1 << (local_98[0] - 1U & 0x1f);
  iVar8 = kmigmgrConfigureGPUInstance_IMPL(param_1,param_2,(int)param_3[0x12d],puVar11,iVar9);
  if (iVar8 != 0) {
    portMemSet(plVar2,0,0x110);
    portMemSet(puVar11,0,0x100);
    kmigmgrConfigureGPUInstance_IMPL(param_1,param_2,(int)param_3[0x12d],puVar11,iVar9);
    goto LAB_003f5090;
  }
  if ((param_6 == '\0') ||
     (iVar8 = osRmCapRegisterSmcExecutionPartition
                        (param_3[0x137],param_3 + uVar12 * 0x22 + 0x36,
                         (int)param_3[uVar12 * 0x22 + 0x34]), iVar8 == 0)) {
    iVar8 = serverAllocShare(g_resServ,__nvoc_class_def_RsShared,param_3 + uVar12 * 0x22 + 0x35);
    if (iVar8 == 0) {
      if (*(char *)(param_1 + 0x4a4e) == '\0') {
        iVar9 = kmigmgrAllocComputeInstanceHandles_IMPL(param_1,param_2,param_3,plVar2);
        if (iVar9 == 0) {
          iVar9 = kmigmgrEngineTypeXlate_IMPL(lVar14,1,lVar1,&local_94);
          if (iVar9 != 0) {
            nvAssertOkFailedNoLog
                      (iVar9,
                       "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &globalEngineType)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x154e);
          }
          iVar9 = kmigmgrEngineTypeXlate_IMPL(param_3 + 0x15,local_94,param_3 + 0x13,&local_94);
          if (iVar9 != 0) {
            nvAssertOkFailedNoLog
                      (iVar9,
                       "kmigmgrEngineTypeXlate(&pResourceAllocation->localEngines, globalEngineType, &pResourceAllocation->engines, &globalEngineType)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1551);
          }
          uVar15 = 0;
          if (local_94 - 1U < 8) {
            uVar15 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)(local_94 - 1U) * 8);
          }
          fecsSetRoutingInfo(param_1,uVar15,(int)param_3[uVar12 * 0x22 + 0x39],
                             (int)param_3[uVar12 * 0x22 + 0x3a],0);
          iVar9 = kgraphicsCreateGoldenImageChannel_IMPL(param_1,uVar15);
          if (iVar9 == 0) goto LAB_003f4fdc;
          nvAssertOkFailedNoLog
                    (iVar9,"kgraphicsCreateGoldenImageChannel(pGpu, pKernelGraphics)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x155d);
          iVar8 = iVar9;
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar9,
                     "kmigmgrAllocComputeInstanceHandles(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, &pKernelMIGGpuInstance->MIGComputeInstance[CIIdx])"
                     ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x154a);
          iVar8 = iVar9;
        }
      }
      else {
LAB_003f4fdc:
        cVar7 = gpuIsClassSupported_IMPL(param_1,0x8f);
        if ((cVar7 == '\0') ||
           ((*(char *)(param_1 + 0x909) != '\0' && (*(char *)(param_1 + 0x4a4e) != '\0'))))
        goto LAB_003f5090;
        if (param_3[uVar12 * 0x22 + 0x3d] != 0) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x114c,
                       "_kmigmgrAllocKernelWatchdog",3,
                       "NVRM: Allocating Kernel Watchdog while it\'s already allcoated, ignore the allocation.\n"
                      );
          goto LAB_003f5090;
        }
        if ((((char)param_3[uVar12 * 0x22 + 0x33] == '\0') ||
            (iVar8 = 0, *(int *)((long)param_3 + uVar12 * 0x110 + 0x164) == 0)) ||
           (iVar8 = _kmigmgrAllocKernelWatchdog_part_0(param_1,plVar2), iVar8 == 0))
        goto LAB_003f5090;
        nvAssertOkFailedNoLog
                  (iVar8,
                   "_kmigmgrAllocKernelWatchdog(pGpu, &pKernelMIGGpuInstance->MIGComputeInstance[CIIdx])"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1565);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,
                 "serverAllocShare(&g_resServ, classInfo(RsShared), &pKernelMIGGpuInstance->MIGComputeInstance[CIIdx].pShare)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1542);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar8,
               "osRmCapRegisterSmcExecutionPartition(pKernelMIGGpuInstance->pOsRmCaps, &pKernelMIGGpuInstance->MIGComputeInstance[CIIdx].pOsRmCaps, pKernelMIGGpuInstance->MIGComputeInstance[CIIdx].id)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x153a);
  }
  kmigmgrDeleteComputeInstance_IMPL(param_1,param_2,param_3,uVar3,0);
LAB_003f5090:
  portMemFree(puVar11);
  portMemFree(lVar10);
  return iVar8;
}


// ===== 003f54c0 kmigmgrRestoreFromBootConfig_PF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrRestoreFromBootConfig_PF(long param_1,long param_2)

{
  undefined4 uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  uint *puVar8;
  uint *puVar9;
  long lVar10;
  ulong uVar11;
  uint uVar12;
  uint *puVar13;
  ulong uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  char *pcVar18;
  char *pcVar19;
  char *pcVar20;
  int iVar21;
  uint uVar22;
  undefined8 local_58c;
  undefined8 local_584;
  undefined8 local_57c;
  undefined8 local_574;
  undefined4 local_56c;
  uint local_568 [5];
  uint local_554 [91];
  undefined4 local_3e8;
  undefined8 local_3e4;
  undefined4 local_3dc;
  undefined4 local_3d8;
  undefined8 local_3d0;
  undefined8 local_3c8;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined4 local_3b4;
  undefined4 local_3b0;
  uint local_3ac;
  char local_218 [192];
  char local_158 [32];
  uint local_138 [66];
  
  lVar6 = rmapiGetInterface(4);
  memset(local_568,0,0x180);
  memset(local_218,0,0x1e0);
  if (*(char *)(param_2 + 0x536a) == '\0') {
    nvCheckFailedNoLog(1,"pKernelMIGManager->bBootConfigSupported",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x251c);
  }
  else if ((((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
           (*(char *)(param_1 + 0x467) == '\0')) ||
          (*(char *)(*(long *)(param_1 + 0x1bc0) + 0x5340) == '\0')) {
    nvCheckFailedNoLog(1,"IS_MIG_ENABLED(pGpu)","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x251f
                      );
  }
  else {
    pcVar20 = local_218;
    iVar21 = 0;
    pcVar18 = pcVar20;
    do {
      nvDbgSnprintf(&local_3e8,0x1b,"RmMIGBootConfigurationGI_%u",iVar21);
      if (*(char *)(param_2 + 0x536c) == '\0') {
        iVar5 = osReadRegistryDword();
      }
      else {
        iVar5 = osGetNvGlobalRegistryDword(param_1,&local_3e8,&local_58c);
      }
      if (iVar5 == 0) {
        uVar22 = (uint)local_58c & 0xff;
        uVar11 = (ulong)((uint)local_58c >> 8 & 0xff);
        *(uint *)(pcVar18 + 4) = uVar22;
        uVar7 = (ulong)((uint)local_58c >> 0x10 & 0xff);
        *(ulong *)(pcVar18 + 8) = uVar11;
        *(ulong *)(pcVar18 + 0x10) = uVar7;
        if ((int)(uint)local_58c < 0) {
          uVar22 = uVar22 | 0x40000000;
          *(uint *)(pcVar18 + 4) = uVar22;
        }
        if (uVar11 <= uVar7) {
          uVar22 = uVar22 | 0x80000000;
          *(uint *)(pcVar18 + 4) = uVar22;
        }
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24ac,"_kmigmgrReadBootConfig",1
                     ,
                     "NVRM: Found a GI config regkey \'%s\': flags=0x%x, placementLo=%llu, placementHi=%llu\n"
                     ,&local_3e8,uVar22,uVar11,uVar7);
        cVar3 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,uVar22);
        if (cVar3 == '\0') {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24b3,"_kmigmgrReadBootConfig"
                       ,4,"NVRM: Invalid partition flags 0x%x in %s\n",uVar22,&local_3e8);
          goto LAB_003f5ca2;
        }
        *pcVar18 = '\x01';
      }
      iVar21 = iVar21 + 1;
      pcVar18 = pcVar18 + 0x18;
    } while (iVar21 != 8);
    if (*(char *)(param_2 + 0x536c) == '\0') {
      iVar21 = osReadRegistryDword(param_1,"RmMIGBootConfigurationCIAssignment",&local_58c);
    }
    else {
      iVar21 = osGetNvGlobalRegistryDword();
    }
    if (iVar21 == 0) {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24bd,"_kmigmgrReadBootConfig",1,
                   "NVRM: Found a CI assignment regkey \'RmMIGBootConfigurationCIAssignment\': value=%x"
                   ,local_58c & 0xffffffff);
      puVar13 = local_138;
      bVar4 = 0;
      do {
        puVar8 = puVar13 + 9;
        *puVar13 = 0xffffffffU >> ((-bVar4 - 4 & 0x1c) + bVar4 & 0x1f) &
                   (uint)local_58c >> (bVar4 & 0x1f);
        puVar13 = puVar8;
        bVar4 = bVar4 + 4;
      } while (puVar8 != (uint *)&stack0xffffffffffffffe8);
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    pcVar18 = local_158;
    iVar21 = 0;
    pcVar19 = pcVar18;
    do {
      nvDbgSnprintf(&local_3e8,0x1b,"RmMIGBootConfigurationCI_%u",iVar21);
      if (*(char *)(param_2 + 0x536c) == '\0') {
        iVar5 = osReadRegistryDword(param_1,&local_3e8,&local_58c);
        if (iVar5 != 0) goto LAB_003f5c6d;
LAB_003f57d5:
        if (!bVar2) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24dd,"_kmigmgrReadBootConfig"
                       ,4,"NVRM: Regkey \'RmMIGBootConfigurationCIAssignment\' is missing\n");
          goto LAB_003f5ca2;
        }
        *pcVar19 = '\x01';
        uVar12 = (uint)local_58c >> 8 & 0xf;
        uVar22 = (uint)local_58c >> 0xc & 0xf;
        uVar15 = (uint)local_58c >> 0x10 & 0xf;
        uVar16 = (uint)local_58c >> 0x14 & 0xf;
        uVar17 = (uint)local_58c >> 0x18 & 0xf;
        *(uint *)(pcVar19 + 4) = (uint)local_58c & 0xff;
        *(uint *)(pcVar19 + 0x1c) = uVar12;
        *(uint *)(pcVar19 + 8) = uVar22;
        *(uint *)(pcVar19 + 0x10) = uVar15;
        *(uint *)(pcVar19 + 0xc) = uVar16;
        *(uint *)(pcVar19 + 0x14) = uVar17;
        *(uint *)(pcVar19 + 0x18) = (uint)local_58c >> 0x1c;
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24ea,"_kmigmgrReadBootConfig",1
                     ,
                     "NVRM: Found a CI config regkey \'%s\': flags=0x%x, placementLo=%u, CEs=%u, DECs=%u, ENCs=%u, JPGs=%u, OFAs=%u\n"
                     ,&local_3e8,(uint)local_58c & 0xff,uVar12,uVar22,uVar15,uVar16,uVar17,
                     (uint)local_58c >> 0x1c);
      }
      else {
        iVar5 = osGetNvGlobalRegistryDword();
        if (iVar5 == 0) goto LAB_003f57d5;
LAB_003f5c6d:
        if (*(int *)(pcVar19 + 0x20) != 0) {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24d2,"_kmigmgrReadBootConfig"
                       ,4,"NVRM: CI assignment for GI #%u must be 0\n",iVar21);
          goto LAB_003f5ca2;
        }
      }
      iVar21 = iVar21 + 1;
      pcVar19 = pcVar19 + 0x24;
    } while (iVar21 != 8);
    pcVar19 = local_218;
    iVar21 = 0;
    do {
      if ((*pcVar19 == '\0') && (pcVar19[0x18] != '\0')) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24f5,"_kmigmgrReadBootConfig",4
                     ,"NVRM: Regkey \'RmMIGBootConfigurationGI_%u\' is missing\n");
        goto LAB_003f5ca2;
      }
      iVar21 = iVar21 + 1;
      pcVar19 = pcVar19 + 0x18;
    } while (iVar21 != 7);
    iVar21 = 0;
    pcVar19 = pcVar18;
    do {
      if ((*pcVar19 == '\0') && (pcVar19[0x24] != '\0')) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x24ff,"_kmigmgrReadBootConfig",4
                     ,"NVRM: Regkey \'RmMIGBootConfigurationCI_%u\' is missing\n");
LAB_003f5ca2:
        nvCheckFailedNoLog(1,"_kmigmgrReadBootConfig(pGpu, pKernelMIGManager, &bootConfig)",
                           "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2522);
        return 0x3b;
      }
      iVar21 = iVar21 + 1;
      pcVar19 = pcVar19 + 0x24;
    } while (iVar21 != 7);
    puVar13 = local_568;
    uVar7 = 0;
    puVar8 = puVar13;
    do {
      if (*pcVar20 == '\0') break;
      uVar22 = *(uint *)(pcVar20 + 4);
      *(undefined1 *)(puVar8 + 6) = 1;
      puVar8[5] = uVar22;
      *(undefined8 *)(puVar8 + 8) = *(undefined8 *)(pcVar20 + 8);
      *(undefined8 *)(puVar8 + 10) = *(undefined8 *)(pcVar20 + 0x10);
      iVar21 = _kmigmgrProcessGPUInstanceEntry(param_1,param_2,puVar8);
      if (iVar21 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar21,
                   "_kmigmgrProcessGPUInstanceEntry(pGpu, pKernelMIGManager, &partitionInfo[GIIdx])"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2533);
        goto LAB_003f5c01;
      }
      uVar22 = (int)uVar7 + 1;
      uVar7 = (ulong)uVar22;
      pcVar20 = pcVar20 + 0x18;
      puVar8 = puVar8 + 0xc;
    } while (uVar22 != 8);
    uVar11 = 0;
    while( true ) {
      local_58c = 0;
      local_584 = 0;
      local_57c = 0;
      memset(&local_3e8,0,0x1cc);
      if (*pcVar18 == '\0') break;
      uVar1 = *(undefined4 *)(pcVar18 + 4);
      iVar21 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,uVar1,&local_58c);
      if (iVar21 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar21,
                   "kmigmgrGetComputeProfileFromSize(pGpu, pKernelMIGManager, bootConfig.CIs[CIIdx].flags, &computeProfileInfo)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2545);
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2547,
                     "kmigmgrRestoreFromBootConfig_PF",4,
                     "NVRM: Invalid partition flags 0x%x for CI #%u\n",uVar1,uVar11);
LAB_003f5a5f:
        if ((int)uVar11 != 0) {
          puVar8 = local_568;
          do {
            memset(&local_3e8,0,0x1c4);
            local_58c = 0;
            local_584 = 0;
            local_57c = 0;
            local_574 = 0;
            local_56c = 0;
            if (*puVar8 < 0xf) {
              puVar9 = (uint *)(param_2 + 0xbe8);
              uVar14 = 0;
              do {
                if (((char)puVar9[8] != '\0') && (*puVar8 == *puVar9)) {
                  lVar10 = param_2 + 0x280 + uVar14 * 0xa18;
                  goto LAB_003f5b4b;
                }
                uVar22 = (int)uVar14 + 1;
                uVar14 = (ulong)uVar22;
                puVar9 = puVar9 + 0x286;
              } while (uVar22 != 8);
            }
            lVar10 = 0;
            nvAssertOkFailedNoLog
                      (0x1f,
                       "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, partitionInfo[i].swizzId, &pKernelMIGGpuInstance)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2578);
LAB_003f5b4b:
            iVar5 = (**(code **)(lVar6 + 0x38))
                              (lVar6,*(undefined4 *)(lVar10 + 0x9c0),*(undefined4 *)(lVar10 + 0x9cc)
                               ,0xc6370103,&local_3e8,0x1c4);
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_GET, &getParams, sizeof(getParams))"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x257c);
            }
            local_58c = CONCAT44(local_58c._4_4_,local_3e8);
            portMemCopy((long)&local_58c + 4,0x20,&local_3e4,0x20);
            iVar5 = (**(code **)(lVar6 + 0x38))
                              (lVar6,*(undefined4 *)(lVar10 + 0x9c0),*(undefined4 *)(lVar10 + 0x9cc)
                               ,0xc6370102,&local_58c,0x24);
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_DELETE, &deleteParams, sizeof(deleteParams))"
                         ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2589);
            }
            puVar8 = puVar8 + 0xc;
          } while (puVar8 != local_568 + uVar11 * 0xc);
        }
LAB_003f5c01:
        if ((int)uVar7 == 0) {
          return iVar21;
        }
        do {
          *(undefined1 *)(puVar13 + 6) = 0;
          iVar5 = _kmigmgrProcessGPUInstanceEntry(param_1,param_2,puVar13);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "_kmigmgrProcessGPUInstanceEntry(pGpu, pKernelMIGManager, &partitionInfo[i])"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2596);
          }
          puVar13 = puVar13 + 0xc;
        } while (puVar13 != local_568 + uVar7 * 0xc);
        return iVar21;
      }
      if (0xe < local_568[(ulong)*(uint *)(pcVar18 + 0x20) * 0xc]) {
LAB_003f5a2e:
        nvAssertOkFailedNoLog
                  (0x1f,
                   "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, partitionInfo[bootConfig.CIs[CIIdx].GIIdx].swizzId, &pKernelMIGGpuInstance)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x254a);
        iVar21 = 0x1f;
        goto LAB_003f5a5f;
      }
      puVar8 = (uint *)(param_2 + 0xbe8);
      uVar22 = 0;
      while (((char)puVar8[8] == '\0' ||
             (local_568[(ulong)*(uint *)(pcVar18 + 0x20) * 0xc] != *puVar8))) {
        uVar22 = uVar22 + 1;
        puVar8 = puVar8 + 0x286;
        if (uVar22 == 8) goto LAB_003f5a2e;
      }
      local_3bc = 0x1f;
      local_3e4 = 0x100000002;
      local_3dc = (undefined4)local_584;
      local_3d8 = 0;
      if ((local_554[(ulong)*(uint *)(pcVar18 + 0x20) * 0xc] & 0xe0) != 0) {
        local_3d8 = local_58c._4_4_;
      }
      local_3b4 = (undefined4)local_57c;
      local_3ac = (uint)(byte)local_58c;
      local_3c8 = CONCAT44(*(undefined4 *)(pcVar18 + 0x14),*(undefined4 *)(pcVar18 + 0x10));
      local_3c0 = *(undefined4 *)(pcVar18 + 0x18);
      local_3d0 = CONCAT44(*(undefined4 *)(pcVar18 + 0xc),*(undefined4 *)(pcVar18 + 8));
      local_3b0 = *(undefined4 *)(pcVar18 + 0x1c);
      lVar10 = (ulong)uVar22 * 0xa18 + param_2;
      iVar21 = (**(code **)(lVar6 + 0x38))
                         (lVar6,*(undefined4 *)(lVar10 + 0xc40),*(undefined4 *)(lVar10 + 0xc4c),
                          0xc6370101,&local_3e8,0x1cc);
      if (iVar21 != 0) {
        nvAssertOkFailedNoLog
                  (iVar21,
                   "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_CREATE, &createParams, sizeof(createParams))"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2563);
        goto LAB_003f5a5f;
      }
      uVar22 = (int)uVar11 + 1;
      uVar11 = (ulong)uVar22;
      pcVar18 = pcVar18 + 0x24;
      if (uVar22 == 8) {
        return 0;
      }
    }
  }
  return 0;
}


// ===== 003f6090 kmigmgrGetComputeProfileForRequest_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kmigmgrGetComputeProfileForRequest_IMPL
          (long param_1,long param_2,long param_3,uint param_4,int param_5,int param_6,long param_7)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_7 == 0) {
    nvAssertFailedNoLog("pProfile != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x25ed);
    return 0x1f;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x25ee);
    return 0x1f;
  }
  if ((param_6 != 0) &&
     (uVar2 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,param_6,param_7),
     (int)uVar2 == 0)) {
    return uVar2;
  }
  uVar1 = *(uint *)(param_3 + 0x96c) >> 2 & 7;
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
    if (param_4 == 0) goto LAB_003f6126;
LAB_003f6166:
    uVar2 = kmigmgrGetComputeProfileFromSmCount_IMPL(param_1,param_2,param_4,param_7);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
  }
  else {
    if (*(uint *)(param_3 + 0xbc) <= param_4) {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2601,
                   "kmigmgrGetComputeProfileForRequest_IMPL",1,
                   "NVRM: CI request is at GPU instance\'s limit. Using GPU instance\'s size: %d\n",
                   uVar1);
      uVar2 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,uVar1,param_7);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    if (param_4 != 0) goto LAB_003f6166;
  }
  if (((*(char *)(param_1 + 0x446) != '\0') || (*(char *)(param_1 + 0x490e) != '\0')) &&
     (*(int *)(param_3 + 0x88) == param_5)) {
    nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x260e,
                 "kmigmgrGetComputeProfileForRequest_IMPL",1,
                 "NVRM: CI request is at GPU instance\'s limit. Using GPU instance\'s size: %d\n",
                 uVar1);
    uVar2 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,uVar1,param_7);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
  }
LAB_003f6126:
  uVar2 = (**(code **)(param_2 + 600))(param_1,param_2,param_5,param_7);
  return uVar2;
}


// ===== 003f62c0 kmigmgrCreateComputeInstances_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrCreateComputeInstances_VF
              (long param_1,long param_2,long *param_3,char param_4,uint *param_5,char param_6,
              int param_7,long param_8,uint *param_9,uint param_10)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  byte bVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  byte *pbVar12;
  long lVar13;
  undefined8 uVar14;
  ulong uVar15;
  uint uVar16;
  long *plVar17;
  ulong uVar18;
  uint *puVar19;
  char *pcVar20;
  uint *puVar21;
  uint uVar22;
  long lVar23;
  ulong uVar24;
  int *piVar25;
  uint uVar26;
  byte *pbVar27;
  byte *pbVar28;
  byte bVar29;
  ulong local_200;
  uint local_1b0;
  uint *local_1a8;
  uint local_174;
  undefined8 local_170;
  undefined1 local_168 [16];
  undefined1 local_158 [16];
  int local_148 [4];
  uint local_138 [2];
  undefined8 local_130 [32];
  
  bVar29 = 0;
  lVar3 = *(long *)(param_1 + 0x1bc8);
  cVar7 = (**(code **)(param_2 + 0x260))();
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x11cb);
    return 0x1f;
  }
  if (param_7 == 0) {
    local_1b0 = (uint)param_8;
    if ((uint)param_8 == 0) {
      return 0x1f;
    }
  }
  else {
    local_1b0 = 1;
  }
  lVar11 = portMemAllocNonPaged(0x880);
  if (lVar11 == 0) {
    nvCheckFailedNoLog(2,"pComputeInstanceInfo != NULL",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x11d5);
    return 0x51;
  }
  portMemSet(lVar11,0,0x880);
  pbVar12 = (byte *)portMemAllocNonPaged(0x100);
  if (pbVar12 == (byte *)0x0) {
    nvAssertFailedNoLog("pConfigRequestPerCi != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                        0x11db);
    iVar8 = 0x51;
  }
  else {
    plVar17 = param_3 + 0x2c;
    uVar16 = 0;
    portMemSet(pbVar12,0,0x100);
    uVar26 = 0;
    do {
      while ((char)plVar17[7] != '\0') {
        iVar8 = kmigmgrGetComputeProfileForRequest_IMPL
                          (param_1,param_2,param_3,*(undefined4 *)((long)plVar17 + 0x34),
                           (int)*plVar17,(int)plVar17[0x10],local_138);
        if (iVar8 != 0) {
          uVar14 = 0x11f0;
          pcVar20 = 
          "kmigmgrGetComputeProfileForRequest(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, smCount, gpcCount, computeSize, &ciProfile)"
          ;
          goto LAB_003f7140;
        }
        plVar17 = plVar17 + 0x22;
        uVar26 = uVar26 + (int)local_130[0];
        if (plVar17 == param_3 + 0x13c) goto LAB_003f6464;
      }
      plVar17 = plVar17 + 0x22;
      uVar16 = uVar16 + 1;
    } while (plVar17 != param_3 + 0x13c);
LAB_003f6464:
    if (uVar16 < local_1b0) {
      iVar8 = 0x1a;
    }
    else {
      uVar14 = 0x1203;
      pcVar20 = "pKernelMIGGpuInstance->resourceAllocation.virtualGpcCount >= inUseGpcCount";
      if (*(uint *)(param_3 + 0x17) < uVar26) {
LAB_003f7520:
        nvAssertFailedNoLog(pcVar20,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar14);
        iVar8 = 0x40;
      }
      else {
        uVar26 = *(uint *)(param_3 + 0x17) - uVar26;
        bitVectorCopy_IMPL(local_168,0x54,param_3 + 0x18,0x54);
        bitVectorCopy_IMPL(local_158,0x54,param_3 + 0x1a,0x54);
        local_200 = param_3[0x13b];
        uVar18 = (ulong)local_1b0;
        local_170 = *(undefined8 *)(lVar3 + 0x440);
        puVar19 = (uint *)(pbVar12 + 0x1c);
        puVar21 = param_9 + uVar18 * 0xd;
        lVar23 = lVar11 + 0x90;
        while( true ) {
          if (param_7 == 0) {
            uVar16 = param_9[10];
            uVar9 = *param_9;
            uVar10 = 0xffffffff;
            uVar22 = param_9[0xc];
            *(undefined1 *)(lVar23 + 0x28) = 1;
            *(uint *)(lVar23 + 0x2c) = param_9[8];
            if ((param_10 & 2) != 0) {
              iVar8 = kgrmgrGetVeidSizePerSpan_IMPL(param_1,lVar3,local_138);
              if (iVar8 != 0) {
                uVar14 = 0x122f;
                pcVar20 = "kgrmgrGetVeidSizePerSpan(pGpu, pKernelGraphicsManager, &veidSizePerSpan)"
                ;
                goto LAB_003f769f;
              }
              uVar10 = param_9[0xb];
              if (uVar10 == 0) {
                uVar10 = param_9[9] / local_138[0];
              }
            }
          }
          else {
            uVar9 = *(uint *)(param_8 + 0x3c);
            uVar16 = *(uint *)(param_8 + 0x4c);
            uVar22 = *(uint *)(param_8 + 0x54);
            *(undefined1 *)(lVar23 + 0x28) = 1;
            uVar9 = uVar9 - (uVar9 >> 1 & 0x55555555);
            uVar9 = (uVar9 >> 2 & 0x33333333) + (uVar9 & 0x33333333);
            *(undefined4 *)(lVar23 + 0x2c) = *(undefined4 *)(param_8 + 0x38);
            uVar10 = *(uint *)(param_8 + 0x50);
            uVar9 = ((uVar9 >> 4) + uVar9 & 0xf0f0f0f) * 0x1010101 >> 0x18;
          }
          *puVar19 = uVar10;
          local_174 = 0xffffffff;
          iVar8 = kmigmgrGetComputeProfileForRequest_IMPL
                            (param_1,param_2,param_3,uVar16,uVar9,uVar22,puVar19 + -7);
          if (iVar8 == 0) break;
          *(byte *)(puVar19 + -7) = 8;
          puVar19[-5] = uVar9;
          uVar16 = *(uint *)(*param_3 + 0x1c);
          uVar22 = *(uint *)(*param_3 + 0xc);
          *puVar19 = 0xffffffff;
          puVar19[-1] = 0xffffffff;
          puVar19[-3] = (uVar16 / uVar22) * uVar9;
          iVar8 = kgrmgrCheckVeidsRequest_IMPL(param_1,lVar3,&local_170,puVar19[-4],puVar19,param_3)
          ;
          if (iVar8 != 0) {
LAB_003f7126:
            uVar14 = 0x127d;
            pcVar20 = 
            "kgrmgrCheckVeidsRequest(pGpu, pKernelGraphicsManager, &shadowVeidInUseMask, pCIProfile->veidCount, &pConfigRequestPerCi[CIIdx].veidSpanStart, pKernelMIGGpuInstance)"
            ;
            goto LAB_003f7140;
          }
          if (cVar7 == '\0') {
LAB_003f6d4a:
            uVar16 = puVar19[-5];
            if (uVar26 < uVar16) {
              nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x128e,
                           "kmigmgrCreateComputeInstances_VF",4,
                           "NVRM: Not enough remaining GPCs (%d) for compute instance request (%d).\n"
                           ,uVar26,uVar16);
              iVar8 = 0x1a;
              goto LAB_003f7190;
            }
            uVar26 = uVar26 - uVar16;
          }
joined_r0x003f6d68:
          if (param_7 != 1) {
            uVar16 = param_9[3];
            plVar17 = param_3 + 0x13;
            uVar9 = param_9[5];
            uVar22 = param_9[4];
            uVar10 = param_9[6];
            uVar1 = param_9[7];
            bitVectorClrAll_IMPL(lVar23,0x54);
            iVar8 = kmigmgrAllocateInstanceEngines_IMPL
                              (plVar17,0,1,8,1,lVar23,local_168,local_158,plVar17);
            if (iVar8 == 0) {
              iVar8 = kmigmgrAllocateInstanceEngines_IMPL
                                (plVar17,*(uint *)(lVar23 + 0x2c) & 1,9,0x1c,uVar16,lVar23,local_168
                                 ,local_158,plVar17);
              if (iVar8 == 0) {
                iVar8 = kmigmgrAllocateInstanceEngines_IMPL
                                  (plVar17,*(byte *)(lVar23 + 0x2c) >> 1 & 1,0x1d,0x24,uVar9,lVar23,
                                   local_168,local_158,plVar17);
                if (iVar8 == 0) {
                  iVar8 = kmigmgrAllocateInstanceEngines_IMPL
                                    (plVar17,*(byte *)(lVar23 + 0x2c) >> 2 & 1,0x25,0x28,uVar22,
                                     lVar23,local_168,local_158,plVar17);
                  if (iVar8 == 0) {
                    iVar8 = kmigmgrAllocateInstanceEngines_IMPL
                                      (plVar17,*(byte *)(lVar23 + 0x2c) >> 4 & 1,0x36,0x3d,uVar10,
                                       lVar23,local_168,local_158,plVar17);
                    if (iVar8 == 0) {
                      iVar8 = kmigmgrAllocateInstanceEngines_IMPL
                                        (plVar17,*(byte *)(lVar23 + 0x2c) >> 3 & 1,0x3e,0x3f,uVar1,
                                         lVar23,local_168,local_158,plVar17);
                      if (iVar8 == 0) goto LAB_003f68c0;
                      uVar14 = 0x1362;
                      pcVar20 = 
                      "kmigmgrAllocateInstanceEngines(&pKernelMIGGpuInstance->resourceAllocation.engines, ((pMIGComputeInstance->sharedEngFlag & NVC637_CTRL_EXEC_PARTITIONS_SHARED_FLAG_OFA) != 0x0), RM_ENGINE_RANGE_OFA(), ofaCount, &pResourceAllocation->engines, &shadowExclusiveEngMask, &shadowSharedEngMask, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                      ;
                    }
                    else {
                      uVar14 = 0x1356;
                      pcVar20 = 
                      "kmigmgrAllocateInstanceEngines(&pKernelMIGGpuInstance->resourceAllocation.engines, ((pMIGComputeInstance->sharedEngFlag & NVC637_CTRL_EXEC_PARTITIONS_SHARED_FLAG_NVJPG) != 0x0), RM_ENGINE_RANGE_NVJPEG(), jpgCount, &pResourceAllocation->engines, &shadowExclusiveEngMask, &shadowSharedEngMask, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                      ;
                    }
                  }
                  else {
                    uVar14 = 0x134a;
                    pcVar20 = 
                    "kmigmgrAllocateInstanceEngines(&pKernelMIGGpuInstance->resourceAllocation.engines, ((pMIGComputeInstance->sharedEngFlag & NVC637_CTRL_EXEC_PARTITIONS_SHARED_FLAG_NVENC) != 0x0), RM_ENGINE_RANGE_NVENC(), encCount, &pResourceAllocation->engines, &shadowExclusiveEngMask, &shadowSharedEngMask, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                    ;
                  }
                }
                else {
                  uVar14 = 0x133e;
                  pcVar20 = 
                  "kmigmgrAllocateInstanceEngines(&pKernelMIGGpuInstance->resourceAllocation.engines, ((pMIGComputeInstance->sharedEngFlag & NVC637_CTRL_EXEC_PARTITIONS_SHARED_FLAG_NVDEC) != 0x0), RM_ENGINE_RANGE_NVDEC(), decCount, &pResourceAllocation->engines, &shadowExclusiveEngMask, &shadowSharedEngMask, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                  ;
                }
              }
              else {
                uVar14 = 0x1332;
                pcVar20 = 
                "kmigmgrAllocateInstanceEngines(&pKernelMIGGpuInstance->resourceAllocation.engines, ((pMIGComputeInstance->sharedEngFlag & NVC637_CTRL_EXEC_PARTITIONS_SHARED_FLAG_CE) != 0x0), RM_ENGINE_RANGE_COPY(), ceCount, &pResourceAllocation->engines, &shadowExclusiveEngMask, &shadowSharedEngMask, &pKernelMIGGpuInstance->resourceAllocation.engines)"
                ;
              }
            }
            else {
              uVar14 = 0x1326;
              pcVar20 = 
              "kmigmgrAllocateInstanceEngines(&pKernelMIGGpuInstance->resourceAllocation.engines, ((pMIGComputeInstance->sharedEngFlag & NVC637_CTRL_EXEC_PARTITIONS_SHARED_FLAG_NONE) != 0x0), RM_ENGINE_RANGE_GR(), grCount, &pResourceAllocation->engines, &shadowExclusiveEngMask, &shadowSharedEngMask, &pKernelMIGGpuInstance->resourceAllocation.engines)"
              ;
            }
            goto LAB_003f7140;
          }
          bitVectorClrAll_IMPL(lVar23,0x54);
          bitVectorFromRaw_IMPL(lVar23,0x54,param_8 + 8,0x20);
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorAnd_IMPL(local_148,0x54,lVar23,0x54,param_3 + 0x15,0x54);
          cVar6 = bitVectorTestEqual_IMPL(local_148,0x54,lVar23,0x54);
          if (cVar6 == '\0') {
            nvCheckFailedNoLog(4,"bitVectorTestEqual(&engines, &pResourceAllocation->engines)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x12a4);
LAB_003f7558:
            iVar8 = 0x1f;
            goto LAB_003f7190;
          }
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorSetRange_IMPL(local_148,0x54,1,8);
          bitVectorAnd_IMPL(local_148,0x54,local_148,0x54,lVar23,0x54);
          iVar8 = kmigmgrCountEnginesInRange_IMPL(local_148,1,8);
          if (iVar8 != 1) {
            nvCheckFailedNoLog(4,"(kmigmgrCountEnginesOfType(&engines, RM_ENGINE_TYPE_GR(0)) == 1)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x12ae);
            goto LAB_003f7558;
          }
          bitVectorAnd_IMPL(local_138,0x54,local_148,0x54,local_168,0x54);
          cVar6 = bitVectorTestAllCleared_IMPL(local_138,0x54);
          if (cVar6 == '\0') {
            nvCheckFailedNoLog(4,"bitVectorTestAllCleared(&tempVector)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x12ba);
LAB_003f7643:
            iVar8 = 99;
            goto LAB_003f7190;
          }
          bitVectorOr_IMPL(local_168,0x54,local_168,0x54,local_148,0x54);
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorSetRange_IMPL(local_148,0x54,9,0x1c);
          bitVectorAnd_IMPL(local_148,0x54,local_148,0x54,lVar23,0x54);
          if ((*(byte *)(lVar23 + 0x2c) & 1) == 0) {
            bitVectorAnd_IMPL(local_138,0x54,local_148,0x54,local_168,0x54);
            cVar6 = bitVectorTestAllCleared_IMPL(local_138,0x54);
            if (cVar6 == '\0') {
              uVar14 = 0x12cc;
              pcVar20 = "bitVectorTestAllCleared(&tempVector)";
              goto LAB_003f76ef;
            }
            bitVectorOr_IMPL(local_168,0x54,local_168,0x54,local_148,0x54);
          }
          else {
            bitVectorOr_IMPL(local_158,0x54,local_158,0x54,local_148);
          }
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorSetRange_IMPL(local_148,0x54,0x1d,0x24);
          bitVectorAnd_IMPL(local_148,0x54,local_148,0x54,lVar23,0x54);
          if ((*(byte *)(lVar23 + 0x2c) & 2) == 0) {
            bitVectorAnd_IMPL(local_138,0x54,local_148,0x54,local_168,0x54);
            cVar6 = bitVectorTestAllCleared_IMPL(local_138,0x54);
            if (cVar6 == '\0') {
              nvCheckFailedNoLog(4,"bitVectorTestAllCleared(&tempVector)",
                                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x12de);
              goto LAB_003f7643;
            }
            bitVectorOr_IMPL(local_168,0x54,local_168,0x54,local_148,0x54);
          }
          else {
            bitVectorOr_IMPL(local_158,0x54,local_158,0x54,local_148);
          }
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorSetRange_IMPL(local_148,0x54,0x25,0x28);
          bitVectorAnd_IMPL(local_148,0x54,local_148,0x54,lVar23,0x54);
          if ((*(byte *)(lVar23 + 0x2c) & 4) == 0) {
            bitVectorAnd_IMPL(local_138,0x54,local_148,0x54,local_168,0x54);
            cVar6 = bitVectorTestAllCleared_IMPL(local_138,0x54);
            if (cVar6 == '\0') {
              nvCheckFailedNoLog(4,"bitVectorTestAllCleared(&tempVector)",
                                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x12f0);
              goto LAB_003f7643;
            }
            bitVectorOr_IMPL(local_168,0x54,local_168,0x54,local_148,0x54);
          }
          else {
            bitVectorOr_IMPL(local_158,0x54,local_158,0x54,local_148);
          }
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorSetRange_IMPL(local_148,0x54,0x36,0x3d);
          bitVectorAnd_IMPL(local_148,0x54,local_148,0x54,lVar23,0x54);
          if ((*(byte *)(lVar23 + 0x2c) & 0x10) == 0) {
            bitVectorAnd_IMPL(local_138,0x54,local_148,0x54,local_168,0x54);
            cVar6 = bitVectorTestAllCleared_IMPL(local_138,0x54);
            if (cVar6 == '\0') {
              nvCheckFailedNoLog(4,"bitVectorTestAllCleared(&tempVector)",
                                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1302);
              goto LAB_003f7643;
            }
            bitVectorOr_IMPL(local_168,0x54,local_168,0x54,local_148,0x54);
          }
          else {
            bitVectorOr_IMPL(local_158,0x54,local_158,0x54,local_148);
          }
          bitVectorClrAll_IMPL(local_148,0x54);
          bitVectorSetRange_IMPL(local_148,0x54,0x3e,0x3f);
          bitVectorAnd_IMPL(local_148,0x54,local_148,0x54,lVar23,0x54);
          if ((*(byte *)(lVar23 + 0x2c) & 8) == 0) {
            bitVectorAnd_IMPL(local_138,0x54,local_148,0x54,local_168,0x54);
            cVar6 = bitVectorTestAllCleared_IMPL(local_138,0x54);
            if (cVar6 == '\0') {
              nvCheckFailedNoLog(4,"bitVectorTestAllCleared(&tempVector)",
                                 "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1314);
              goto LAB_003f7643;
            }
            bitVectorOr_IMPL(local_168,0x54,local_168,0x54,local_148,0x54);
          }
          else {
            bitVectorOr_IMPL(local_158,0x54,local_158,0x54,local_148);
          }
LAB_003f68c0:
          param_9 = param_9 + 0xd;
          puVar19 = puVar19 + 8;
          kmigmgrGetLocalEngineMask_IMPL(param_1,lVar23,lVar23 + 0x10);
          lVar23 = lVar23 + 0x110;
          if (puVar21 == param_9) goto code_r0x003f68ef;
        }
        if (cVar7 == '\0') {
          puVar19[-1] = 0xffffffff;
          iVar8 = kgrmgrCheckVeidsRequest_IMPL(param_1,lVar3,&local_170,puVar19[-4],puVar19,param_3)
          ;
          if (iVar8 == 0) goto LAB_003f6d4a;
          goto LAB_003f7126;
        }
        if (uVar10 == 0xffffffff) {
          iVar8 = kmigmgrGetFreeCTSId_IMPL
                            (param_1,param_2,&local_174,*(undefined8 *)(*param_3 + 0x38),0,local_200
                             ,(byte)puVar19[-7],0,0);
          uVar16 = local_174;
          if (iVar8 == 0) {
LAB_003f665f:
            if (uVar16 < 0x15) {
              uVar9 = kmigmgrGetSpanStartFromCTSId_IMPL(param_1,param_2,uVar16);
              puVar19[-1] = uVar16;
              *puVar19 = uVar9;
              iVar8 = kgrmgrCheckVeidsRequest_IMPL
                                (param_1,lVar3,&local_170,puVar19[-4],puVar19,param_3);
              if (iVar8 != 0) goto LAB_003f7126;
              local_200 = local_200 | 1L << ((byte)uVar16 & 0x3f);
              goto joined_r0x003f6d68;
            }
            nvCheckFailedNoLog(4,"ctsId < KMIGMGR_MAX_GPU_CTSID",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1268);
            iVar8 = 0x40;
            goto LAB_003f7190;
          }
          uVar14 = 0x125c;
          pcVar20 = 
          "kmigmgrGetFreeCTSId(pGpu, pKernelMIGManager, &ctsId, pKernelMIGGpuInstance->pProfile->validCTSIdMask, 0x0, shadowCTSInUseMask, pCIProfile->computeSize, NV_FALSE, NV_FALSE)"
          ;
        }
        else {
          iVar8 = kmigmgrXlateSpanStartToCTSId_IMPL
                            (param_1,param_2,(byte)puVar19[-7],uVar10,&local_174);
          uVar16 = local_174;
          if (iVar8 == 0) {
            cVar6 = kmigmgrIsCTSIdAvailable_IMPL
                              (param_1,param_2,*(undefined8 *)(*param_3 + 0x38),local_200,local_174)
            ;
            if (cVar6 == '\x01') goto LAB_003f665f;
            uVar14 = 0x1252;
            pcVar20 = 
            "kmigmgrIsCTSIdAvailable(pGpu, pKernelMIGManager, pKernelMIGGpuInstance->pProfile->validCTSIdMask, shadowCTSInUseMask, ctsId)"
            ;
LAB_003f76ef:
            nvCheckFailedNoLog(4,pcVar20,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar14);
            goto LAB_003f7643;
          }
          uVar14 = 0x124b;
          pcVar20 = 
          "kmigmgrXlateSpanStartToCTSId(pGpu, pKernelMIGManager, pCIProfile->computeSize, spanStart, &ctsId)"
          ;
        }
LAB_003f7140:
        nvCheckOkFailedNoLog(4,iVar8,pcVar20,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar14);
      }
    }
  }
  goto LAB_003f7190;
code_r0x003f68ef:
  if (param_4 == '\0') {
    uVar2 = (undefined4)param_3[0x12d];
    uVar26 = 0;
    do {
      uVar15 = (ulong)uVar26;
      uVar26 = uVar26 + 0x20;
      *(undefined8 *)((long)local_138 + uVar15) = 0;
      *(undefined8 *)((long)local_130 + uVar15) = 0;
      *(undefined8 *)((long)local_130 + uVar15 + 8) = 0;
      *(undefined8 *)((long)local_130 + uVar15 + 0x10) = 0;
    } while (uVar26 < 0x100);
    uVar26 = 0;
    lVar23 = lVar11 + 0xa0;
    do {
      iVar8 = kmigmgrEngineTypeXlate_IMPL(lVar23,1,lVar23 + -0x10,local_148);
      if (iVar8 != 0) {
        uVar14 = 0x1389;
        pcVar20 = 
        "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &localEngineType)"
        ;
LAB_003f769f:
        nvAssertOkFailedNoLog(iVar8,pcVar20,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",uVar14);
        goto LAB_003f7190;
      }
      if (7 < local_148[0] - 1U) {
        uVar14 = 0x138d;
        pcVar20 = "RM_ENGINE_TYPE_IS_GR(localEngineType)";
        goto LAB_003f7520;
      }
      lVar23 = lVar23 + 0x110;
      uVar26 = uVar26 | 1 << ((byte)(local_148[0] - 1U) & 0x1f);
    } while (lVar11 + 0xa0 + uVar18 * 0x110 != lVar23);
    uVar15 = 0;
    uVar16 = uVar26;
LAB_003f6a16:
    uVar9 = 0;
    for (uVar22 = uVar16; (uVar22 & 1) == 0; uVar22 = uVar22 >> 1 | 0x80000000) {
      uVar9 = uVar9 + 1;
    }
    uVar24 = 0;
    lVar23 = lVar11 + 0xa0;
LAB_003f6a4d:
    iVar8 = kmigmgrEngineTypeXlate_IMPL(lVar23,1,lVar23 + -0x10,local_148);
    if (iVar8 != 0) {
      uVar14 = 0x13a0;
      pcVar20 = 
      "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &localRmEngineType)"
      ;
      goto LAB_003f769f;
    }
    if (local_148[0] - 1U < 8) {
      uVar22 = (uint)uVar24;
      if (local_148[0] - 1U != uVar9) goto code_r0x003f6a8b;
      lVar23 = uVar15 * 8;
      uVar15 = (ulong)((int)uVar15 + 1);
      puVar19 = (uint *)(pbVar12 + uVar24 * 0x20);
      puVar21 = local_138 + lVar23;
      for (lVar13 = 8; lVar13 != 0; lVar13 = lVar13 + -1) {
        *puVar21 = *puVar19;
        puVar19 = puVar19 + (ulong)bVar29 * -2 + 1;
        puVar21 = puVar21 + (ulong)bVar29 * -2 + 1;
      }
      bVar4 = (byte)uVar9 & 0x1f;
      uVar16 = uVar16 & (-2 << bVar4 | 0xfffffffeU >> 0x20 - bVar4);
      if (local_1b0 <= uVar22) goto LAB_003f6ac5;
      goto LAB_003f6add;
    }
    uVar14 = 0x13a4;
    pcVar20 = "RM_ENGINE_TYPE_IS_GR(localRmEngineType)";
    goto LAB_003f7520;
  }
LAB_003f77fe:
  iVar8 = 0;
  goto LAB_003f7190;
code_r0x003f6a8b:
  uVar24 = uVar24 + 1;
  lVar23 = lVar23 + 0x110;
  if (uVar24 == uVar18) goto code_r0x003f6a9b;
  goto LAB_003f6a4d;
code_r0x003f6a9b:
  if (uVar22 + 1 < local_1b0) goto LAB_003f6a16;
LAB_003f6ac5:
  nvAssertFailedNoLog("CIIdx < count","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x13ae);
LAB_003f6add:
  if (uVar16 == 0) goto code_r0x003f6ae6;
  goto LAB_003f6a16;
code_r0x003f6ae6:
  iVar8 = kmigmgrConfigureGPUInstance_IMPL(param_1,param_2,uVar2,local_138,uVar26);
  if (iVar8 == 0) {
    bitVectorCopy_IMPL(param_3 + 0x18,0x54,local_168,0x54);
    bitVectorCopy_IMPL(param_3 + 0x1a,0x54,local_158,0x54);
    piVar25 = (int *)(lVar11 + 0x88);
    pbVar28 = pbVar12;
    do {
      iVar8 = kmigmgrEngineTypeXlate_IMPL(piVar25 + 6,1,piVar25 + 2,local_148);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &globalEngineType)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x13d5);
      }
      iVar8 = kmigmgrEngineTypeXlate_IMPL(param_3 + 0x15,local_148[0],param_3 + 0x13,local_148);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kmigmgrEngineTypeXlate(&pResourceAllocation->localEngines, globalEngineType, &pResourceAllocation->engines, &globalEngineType)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x13d9);
      }
      piVar25[-2] = *(int *)(pbVar28 + 8);
      piVar25[0xb] = *(int *)(pbVar28 + 0x10);
      if (*pbVar28 == 8) {
        iVar8 = (*(uint *)((long)param_3 + 0x94) / *(uint *)(param_3 + 0x11)) * piVar25[10];
      }
      else {
        iVar8 = *(int *)(pbVar28 + 0xc);
      }
      piVar25[1] = iVar8;
      pbVar27 = pbVar28 + 0x20;
      piVar25[0x1d] = *(int *)(pbVar28 + 0x1c);
      piVar25[0x1e] = (uint)*pbVar28;
      kgrmgrGetVeidBaseForGrIdx_IMPL(param_1,lVar3,local_148[0] + -1,piVar25);
      *piVar25 = *piVar25 - (int)param_3[0x12];
      piVar25 = piVar25 + 0x44;
      pbVar28 = pbVar27;
    } while (pbVar12 + uVar18 * 0x20 != pbVar27);
    plVar17 = param_3 + 0x1c;
    uVar18 = 0;
    uVar26 = 0;
    do {
      if ((((char)plVar17[0x17] == '\0') &&
          ((param_7 != 1 || (*(uint *)(param_8 + 0x58) == uVar26)))) &&
         (((param_10 & 1) == 0 || (*param_5 == uVar26)))) {
        if ((int)plVar17[0x18] != -1) {
          nvAssertFailedNoLog("pKernelMIGGpuInstance->MIGComputeInstance[CIIdx].id == KMIGMGR_COMPUTE_INSTANCE_ID_INVALID"
                              ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1408);
        }
        uVar16 = (int)uVar18 + 1;
        uVar15 = (ulong)uVar16;
        portMemCopy(plVar17,0x110,uVar18 * 0x110 + lVar11,0x110);
        *(uint *)(plVar17 + 0x18) = uVar26;
        param_5[uVar18] = uVar26;
        uVar18 = uVar15;
        if (uVar16 == local_1b0) break;
      }
      uVar26 = uVar26 + 1;
      plVar17 = plVar17 + 0x22;
      uVar15 = uVar18;
    } while (uVar26 != 8);
    puVar19 = param_5 + uVar15;
    local_1a8 = param_5;
    while( true ) {
      if (puVar19 == local_1a8) goto LAB_003f77fe;
      uVar26 = *local_1a8;
      uVar18 = (ulong)uVar26;
      iVar8 = kmigmgrEngineTypeXlate_IMPL
                        (param_3 + uVar18 * 0x22 + 0x30,1,param_3 + uVar18 * 0x22 + 0x2e,local_148);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kmigmgrEngineTypeXlate(&pComputeResourceAllocation->localEngines, RM_ENGINE_TYPE_GR(0), &pComputeResourceAllocation->engines, &globalEngineType)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x142b);
      }
      iVar8 = kmigmgrEngineTypeXlate_IMPL(param_3 + 0x15,local_148[0],param_3 + 0x13,local_148);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kmigmgrEngineTypeXlate(&pResourceAllocation->localEngines, globalEngineType, &pResourceAllocation->engines, &globalEngineType)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x142e);
      }
      iVar5 = local_148[0];
      if (*(uint *)(param_3 + uVar18 * 0x22 + 0x34) != uVar26) {
        nvAssertFailedNoLog("pMIGComputeInstance->id == CIIdx",
                            "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1433);
      }
      if ((param_6 != '\0') &&
         (iVar8 = osRmCapRegisterSmcExecutionPartition
                            (param_3[0x137],param_3 + uVar18 * 0x22 + 0x36,
                             (int)param_3[uVar18 * 0x22 + 0x34]), iVar8 != 0)) break;
      uVar26 = iVar5 - 1;
      iVar8 = (**(code **)(param_2 + 0x208))
                        (param_1,param_2,uVar2,uVar26,param_3 + uVar18 * 0x22 + 0x37);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kmigmgrGenerateComputeInstanceUuid_HAL(pGpu, pKernelMIGManager, swizzId, globalGrIdx, &pMIGComputeInstance->uuid)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1444);
        goto LAB_003f7bf5;
      }
      iVar8 = serverAllocShare(g_resServ,__nvoc_class_def_RsShared,param_3 + uVar18 * 0x22 + 0x35);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "serverAllocShare(&g_resServ, classInfo(RsShared), &pMIGComputeInstance->pShare)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x144a);
        goto LAB_003f7bf5;
      }
      iVar8 = kmigmgrAllocComputeInstanceHandles_IMPL
                        (param_1,param_2,param_3,param_3 + uVar18 * 0x22 + 0x1c);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kmigmgrAllocComputeInstanceHandles(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, pMIGComputeInstance)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1451);
        goto LAB_003f7bf5;
      }
      if (uVar26 < 8) {
        uVar14 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)uVar26 * 8);
      }
      else {
        uVar14 = 0;
      }
      fecsSetRoutingInfo(param_1,uVar14,(int)param_3[uVar18 * 0x22 + 0x39],
                         (int)param_3[uVar18 * 0x22 + 0x3a],0);
      iVar8 = kgraphicsCreateGoldenImageChannel_IMPL(param_1,uVar14);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,"kgraphicsCreateGoldenImageChannel(pGpu, pKernelGraphics)",
                   "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x145d);
        goto LAB_003f7bf5;
      }
      lVar3 = *(long *)(param_1 + 0x1d20);
      lVar23 = gpuGetStaticInfo(param_1);
      if (lVar23 == 0) {
        nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1463);
        return 0x1f;
      }
      if (((lVar3 != 0) && ((*(byte *)(lVar23 + 0xa727) & 1) != 0)) &&
         (iVar8 = kccuInitVgpuMigSharedBuffer_IMPL
                            (param_1,lVar3,uVar2,(int)param_3[uVar18 * 0x22 + 0x34]), iVar8 != 0)) {
        nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x146d,
                     "kmigmgrCreateComputeInstances_VF",3,
                     "NVRM: Initialization process of the MIG GPM buffer for vGPU failed.\n");
      }
      cVar7 = gpuIsClassSupported_IMPL(param_1,0x8f);
      if ((cVar7 != '\0') &&
         ((*(char *)(param_1 + 0x909) == '\0' || (*(char *)(param_1 + 0x4a4e) == '\0')))) {
        if (param_3[uVar18 * 0x22 + 0x3d] == 0) {
          if ((((char)param_3[uVar18 * 0x22 + 0x33] != '\0') &&
              (*(int *)((long)param_3 + uVar18 * 0x110 + 0x164) != 0)) &&
             (iVar8 = _kmigmgrAllocKernelWatchdog_part_0(param_1,param_3 + uVar18 * 0x22 + 0x1c),
             iVar8 != 0)) {
            nvAssertOkFailedNoLog
                      (iVar8,"_kmigmgrAllocKernelWatchdog(pGpu, pMIGComputeInstance)",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x1475);
            goto LAB_003f7bf5;
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x114c,
                       "_kmigmgrAllocKernelWatchdog",3,
                       "NVRM: Allocating Kernel Watchdog while it\'s already allcoated, ignore the allocation.\n"
                      );
        }
      }
      local_1a8 = local_1a8 + 1;
    }
    nvAssertOkFailedNoLog
              (iVar8,
               "osRmCapRegisterSmcExecutionPartition(pKernelMIGGpuInstance->pOsRmCaps, &pMIGComputeInstance->pOsRmCaps, pMIGComputeInstance->id)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x143c);
LAB_003f7bf5:
    do {
      uVar26 = *param_5;
      param_5 = param_5 + 1;
      kmigmgrDeleteComputeInstance_IMPL(param_1,param_2,param_3,uVar26,0);
    } while (puVar19 != param_5);
  }
  else {
    portMemSet(pbVar12,0,0x100);
    kmigmgrConfigureGPUInstance_IMPL(param_1,param_2,uVar2,pbVar12,uVar26);
  }
LAB_003f7190:
  portMemFree(lVar11);
  portMemFree(pbVar12);
  return iVar8;
}


// ===== 003f7f00 kmigmgrIsPartitionVeidAllocationContiguous_IMPL =====

undefined8
kmigmgrIsPartitionVeidAllocationContiguous_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  ulong uVar1;
  byte bVar2;
  undefined4 *puVar3;
  ulong uVar4;
  
  puVar3 = (undefined4 *)(param_3 + 0x168);
  uVar4 = 0;
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                        "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2629);
    return 0;
  }
  do {
    if (*(char *)(puVar3 + 0xc) != '\0') {
      bVar2 = (byte)*puVar3 & 0x3f;
      uVar4 = uVar4 | (0xffffffffffffffffU >>
                      ((-((byte)*puVar3 + (char)puVar3[1]) & 0x3f) + bVar2 & 0x3f)) << bVar2;
    }
    puVar3 = puVar3 + 0x44;
  } while (puVar3 != (undefined4 *)(param_3 + 0x9e8));
  if (0xfffffffffffffffd < uVar4 - 1) {
    return 1;
  }
  bVar2 = 0;
  for (uVar1 = uVar4; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1 | 0x8000000000000000) {
    bVar2 = bVar2 + 1;
  }
  uVar4 = uVar4 >> (bVar2 & 0x3f);
  uVar1 = uVar4 + 1;
  return CONCAT71((int7)(uVar1 >> 8),(uVar1 & uVar4) == 0);
}


// ===== 003f7ff0 __pfx_kmigmgrComputeProfileGetCapacity_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int __pfx_kmigmgrComputeProfileGetCapacity_IMPL
              (long param_1,long param_2,uint *param_3,long param_4,undefined4 param_5,
              undefined4 param_6,uint *param_7)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  ulong uVar8;
  ulong *puVar9;
  long lVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  uint uStack_c4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_88;
  undefined1 uStack_84;
  uint uStack_80;
  char cStack_7c;
  ulong uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined *puStack_40;
  ulong uStack_38;
  
  cVar2 = (**(code **)(param_2 + 0x260))();
  uVar7 = *param_7;
  if (uVar7 < 8) {
    if (cVar2 == '\0') {
      lVar1 = *(long *)(param_1 + 0x1bc8);
      iVar3 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,uVar7,&uStack_78);
      if (iVar3 == 0) {
        iVar3 = kgrmgrGetVeidSizePerSpan_IMPL(param_1,lVar1,&uStack_88);
        if (iVar3 == 0) {
          if (param_4 == 0) {
            uVar7 = 0;
            uVar4 = param_3[6];
            uVar16 = 0xffffffffffffffff >> (-(char)uVar4 & 0x3fU);
            uVar15 = uVar16;
          }
          else {
            uVar7 = *(uint *)(param_4 + 0x90);
            uVar4 = *(int *)(param_4 + 0x94) + uVar7;
            bVar6 = (byte)uVar7 & 0x3f;
            uVar16 = (0xffffffffffffffffU >> ((-(char)uVar4 & 0x3fU) + bVar6 & 0x3f)) << bVar6;
            uVar15 = ~*(ulong *)(lVar1 + 0x440) & uVar16;
          }
          uVar17 = 0;
          if (uVar7 < uVar4 - 1) {
            uVar14 = 0;
            uVar12 = 0;
            uStack_9c = 0;
            uVar11 = 0xffffffffffffffff >> (-(char)((ulong)uStack_70 >> 0x20) & 0x3fU);
            uVar8 = uVar17;
            uVar13 = uVar15;
            do {
              bVar6 = (byte)uVar7;
              iVar3 = (int)uVar14;
              uVar17 = uVar8;
              if ((~(uVar15 >> (bVar6 & 0x3f)) & uVar11) == 0) {
                uVar17 = (ulong)((int)uVar8 + 1);
                *(ulong *)(param_7 + uVar8 * 4 + 2) = uVar14;
                *(ulong *)(param_7 + uVar8 * 4 + 4) =
                     (ulong)(iVar3 + -1 + uStack_70._4_4_ / uStack_88);
              }
              if ((~(uVar16 >> (bVar6 & 0x3f)) & uVar11) == 0) {
                uVar8 = (ulong)uStack_9c;
                uStack_9c = uStack_9c + 1;
                *(ulong *)(param_7 + uVar8 * 4 + 0x24) = uVar14;
                *(ulong *)(param_7 + uVar8 * 4 + 0x26) =
                     (ulong)(iVar3 + -1 + uStack_70._4_4_ / uStack_88);
              }
              uVar8 = uVar13 >> (bVar6 & 0x3f) & uVar11;
              if (uVar8 == uVar11) {
                uVar12 = uVar12 + 1;
              }
              if (uVar8 == uVar11) {
                uVar13 = ~(uVar11 << (bVar6 & 0x3f)) & uVar13;
              }
              uVar7 = uVar7 + uStack_88;
              uVar14 = (ulong)(iVar3 + 1);
              uVar8 = uVar17;
            } while (uVar7 < uVar4 - 1);
          }
          else {
            uStack_9c = 0;
            uVar12 = 0;
          }
          uVar7 = param_3[6] / uStack_70._4_4_;
          if (param_3[4] / (uint)uStack_70 <= param_3[6] / uStack_70._4_4_) {
            uVar7 = param_3[4] / (uint)uStack_70;
          }
          param_7[0x23] = uVar7;
          uVar4 = param_3[1];
          if (uVar7 < param_3[1]) {
            uVar4 = uVar7;
          }
          param_7[0x23] = uVar4;
          param_7[1] = uVar12;
          param_7[0x44] = uStack_9c;
          uVar7 = param_3[1];
          if (uVar12 < param_3[1]) {
            uVar7 = uVar12;
          }
          param_7[0x22] = (uint)uVar17;
          param_7[1] = uVar7;
          iVar3 = (**(code **)(param_2 + 0x1d0))(param_1,param_2,param_3);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "kmigmgrPatchCICapacity_HAL(pGpu, pKernelMIGManager, pProfile, pParams, veidSlotCount)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2705);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "kgrmgrGetVeidSizePerSpan(pGpu, pKernelGraphicsManager, &veidSizePerSpan)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x26c9);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar3,
                   "kmigmgrGetComputeProfileFromSize(pGpu, pKernelMIGManager, pParams->computeSize, &profile)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x26c7);
      }
    }
    else {
      auVar18 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(uVar7);
      uVar15 = auVar18._0_8_;
      iVar3 = 5;
      do {
        iVar5 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,iVar3,&uStack_78);
        if (iVar5 == 0) {
          uVar16 = 0;
          if (param_4 != 0) {
            uVar16 = *(ulong *)(param_4 + 0x9d8);
          }
          auVar19 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(iVar3);
          if (auVar18._8_8_ < uVar15) {
            nvCheckFailedNoLog(4,"!rangeIsEmpty(totalRange)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2671);
          }
          else {
            if (auVar19._0_8_ <= auVar19._8_8_) {
              bVar6 = (byte)uVar15 & 0x3f;
              uVar15 = (0xffffffffffffffffU >> ((~auVar18[8] & 0x3f) + bVar6 & 0x3f)) << bVar6 &
                       *(ulong *)(param_3 + 0xe);
              if (uVar16 == 0) {
                uVar17 = 0;
              }
              else {
                bVar6 = 0;
                uVar17 = 0;
                while( true ) {
                  for (; (uVar16 & 1) == 0; uVar16 = uVar16 >> 1) {
                    bVar6 = bVar6 + 1;
                  }
                  uStack_78 = 0x222b;
                  puVar9 = &uStack_78;
                  uVar8 = 0xffffffffffe00000;
                  uStack_70 = 0x422b;
                  uStack_68 = 0x844b;
                  uStack_60 = 0x1044b;
                  uStack_58 = 0x20895;
                  uStack_50 = 0x40895;
                  uStack_48 = 0x81115;
                  puStack_40 = &DAT_00101115;
                  do {
                    uVar13 = *puVar9;
                    puVar9 = puVar9 + 1;
                    uVar8 = uVar8 | -(ulong)((uint)(uVar13 >> (bVar6 & 0x3f)) & 1) & uVar13;
                  } while (puVar9 != &uStack_38);
                  uVar17 = uVar17 | uVar8;
                  uVar16 = uVar16 >> 1;
                  if (uVar16 == 0) break;
                  bVar6 = bVar6 + 1;
                }
              }
              if (uVar15 == 0) {
                uStack_c4 = 0;
                uStack_a0 = 0;
              }
              else {
                uStack_c4 = 0;
                uStack_a0 = 0;
                bVar6 = auVar19[0] & 0x3f;
                uVar7 = 0;
                uVar4 = uStack_c4;
                while( true ) {
                  for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
                    uVar7 = uVar7 + 1;
                  }
                  uStack_80 = *param_3 >> 2 & 7;
                  uStack_88 = uVar7;
                  uStack_84 = param_4 != 0;
                  iVar3 = (**(code **)(param_1 + 0x3b90))
                                    (param_1 + 0x3b58,param_5,param_6,0x20800a46,&uStack_88,0x10);
                  if (iVar3 != 0) {
                    nvCheckOkFailedNoLog
                              (4,iVar3,
                               "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_CHECK_CTS_ID_VALID, &params, sizeof(params))"
                               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2695);
                    return iVar3;
                  }
                  uStack_c4 = uVar4;
                  if (cStack_7c != '\0') {
                    uStack_78 = 0x222b;
                    puVar9 = &uStack_78;
                    uVar16 = 0xffffffffffe00000;
                    uStack_70 = 0x422b;
                    uStack_68 = 0x844b;
                    uStack_60 = 0x1044b;
                    uStack_58 = 0x20895;
                    uStack_50 = 0x40895;
                    uStack_48 = 0x81115;
                    puStack_40 = &DAT_00101115;
                    do {
                      uVar8 = *puVar9;
                      puVar9 = puVar9 + 1;
                      uVar16 = uVar16 | -(ulong)((uint)(uVar8 >> ((byte)uVar7 & 0x3f)) & 1) & uVar8;
                    } while (puVar9 != &uStack_38);
                    uVar12 = 0;
                    uVar16 = uVar16 & (0xffffffffffffffffU >> ((~auVar19[8] & 0x3f) + bVar6 & 0x3f))
                                      << bVar6;
                    for (uVar8 = uVar16; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x8000000000000000)
                    {
                      uVar12 = uVar12 + 1;
                    }
                    uVar8 = (ulong)uVar12;
                    if (uVar16 == 0) {
                      uVar8 = 0x40;
                    }
                    lVar10 = uVar8 - auVar19._0_8_;
                    *(long *)(param_7 + (ulong)uStack_a0 * 4 + 0x24) = lVar10;
                    uVar16 = uVar16 - (uVar16 >> 1 & 0x5555555555555555);
                    uVar16 = (uVar16 & 0x3333333333333333) + (uVar16 >> 2 & 0x3333333333333333);
                    lVar1 = lVar10 + -1 +
                            ((uVar16 + (uVar16 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >>
                            0x38);
                    *(long *)(param_7 + (ulong)uStack_a0 * 4 + 0x26) = lVar1;
                    if ((uVar17 >> ((ulong)uVar7 & 0x3f) & 1) == 0) {
                      uStack_c4 = uVar4 + 1;
                      *(long *)(param_7 + (ulong)uVar4 * 4 + 2) = lVar10;
                      *(long *)(param_7 + (ulong)uVar4 * 4 + 4) = lVar1;
                    }
                    uStack_a0 = uStack_a0 + 1;
                  }
                  uVar15 = uVar15 >> 1;
                  if (uVar15 == 0) break;
                  uVar7 = uVar7 + 1;
                  uVar4 = uStack_c4;
                }
              }
              param_7[0x44] = uStack_a0;
              param_7[0x23] = uStack_a0;
              param_7[0x22] = uStack_c4;
              param_7[1] = uStack_c4;
              return 0;
            }
            nvCheckFailedNoLog(4,"!rangeIsEmpty(slotBasisIdRange)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2672);
          }
          goto LAB_003f8768;
        }
        iVar3 = kmigmgrGetNextComputeSize_IMPL(param_1,param_2,0,iVar3);
      } while (iVar3 != 8);
      nvCheckFailedNoLog(4,"slotBasisComputeSize != KMIGMGR_COMPUTE_SIZE_INVALID",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x266d);
      iVar3 = 0x40;
    }
  }
  else {
    nvCheckFailedNoLog(4,"pParams->computeSize < NV2080_CTRL_GPU_PARTITION_FLAG_COMPUTE_SIZE__SIZE",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x265b);
LAB_003f8768:
    iVar3 = 0x1f;
  }
  return iVar3;
}


// ===== 003f8000 kmigmgrComputeProfileGetCapacity_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kmigmgrComputeProfileGetCapacity_IMPL
              (long param_1,long param_2,uint *param_3,long param_4,undefined4 param_5,
              undefined4 param_6,uint *param_7)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  ulong uVar8;
  ulong *puVar9;
  long lVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  uint local_c4;
  uint local_a0;
  uint local_9c;
  uint local_88;
  undefined1 local_84;
  uint local_80;
  char local_7c;
  ulong local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined *local_40;
  ulong local_38;
  
  cVar2 = (**(code **)(param_2 + 0x260))();
  uVar7 = *param_7;
  if (uVar7 < 8) {
    if (cVar2 == '\0') {
      lVar1 = *(long *)(param_1 + 0x1bc8);
      iVar3 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,uVar7,&local_78);
      if (iVar3 == 0) {
        iVar3 = kgrmgrGetVeidSizePerSpan_IMPL(param_1,lVar1,&local_88);
        if (iVar3 == 0) {
          if (param_4 == 0) {
            uVar7 = 0;
            uVar4 = param_3[6];
            uVar16 = 0xffffffffffffffff >> (-(char)uVar4 & 0x3fU);
            uVar15 = uVar16;
          }
          else {
            uVar7 = *(uint *)(param_4 + 0x90);
            uVar4 = *(int *)(param_4 + 0x94) + uVar7;
            bVar6 = (byte)uVar7 & 0x3f;
            uVar16 = (0xffffffffffffffffU >> ((-(char)uVar4 & 0x3fU) + bVar6 & 0x3f)) << bVar6;
            uVar15 = ~*(ulong *)(lVar1 + 0x440) & uVar16;
          }
          uVar17 = 0;
          if (uVar7 < uVar4 - 1) {
            uVar14 = 0;
            uVar12 = 0;
            local_9c = 0;
            uVar11 = 0xffffffffffffffff >> (-(char)((ulong)local_70 >> 0x20) & 0x3fU);
            uVar8 = uVar17;
            uVar13 = uVar15;
            do {
              bVar6 = (byte)uVar7;
              iVar3 = (int)uVar14;
              uVar17 = uVar8;
              if ((~(uVar15 >> (bVar6 & 0x3f)) & uVar11) == 0) {
                uVar17 = (ulong)((int)uVar8 + 1);
                *(ulong *)(param_7 + uVar8 * 4 + 2) = uVar14;
                *(ulong *)(param_7 + uVar8 * 4 + 4) =
                     (ulong)(iVar3 + -1 + local_70._4_4_ / local_88);
              }
              if ((~(uVar16 >> (bVar6 & 0x3f)) & uVar11) == 0) {
                uVar8 = (ulong)local_9c;
                local_9c = local_9c + 1;
                *(ulong *)(param_7 + uVar8 * 4 + 0x24) = uVar14;
                *(ulong *)(param_7 + uVar8 * 4 + 0x26) =
                     (ulong)(iVar3 + -1 + local_70._4_4_ / local_88);
              }
              uVar8 = uVar13 >> (bVar6 & 0x3f) & uVar11;
              if (uVar8 == uVar11) {
                uVar12 = uVar12 + 1;
              }
              if (uVar8 == uVar11) {
                uVar13 = ~(uVar11 << (bVar6 & 0x3f)) & uVar13;
              }
              uVar7 = uVar7 + local_88;
              uVar14 = (ulong)(iVar3 + 1);
              uVar8 = uVar17;
            } while (uVar7 < uVar4 - 1);
          }
          else {
            local_9c = 0;
            uVar12 = 0;
          }
          uVar7 = param_3[6] / local_70._4_4_;
          if (param_3[4] / (uint)local_70 <= param_3[6] / local_70._4_4_) {
            uVar7 = param_3[4] / (uint)local_70;
          }
          param_7[0x23] = uVar7;
          uVar4 = param_3[1];
          if (uVar7 < param_3[1]) {
            uVar4 = uVar7;
          }
          param_7[0x23] = uVar4;
          param_7[1] = uVar12;
          param_7[0x44] = local_9c;
          uVar7 = param_3[1];
          if (uVar12 < param_3[1]) {
            uVar7 = uVar12;
          }
          param_7[0x22] = (uint)uVar17;
          param_7[1] = uVar7;
          iVar3 = (**(code **)(param_2 + 0x1d0))(param_1,param_2,param_3);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "kmigmgrPatchCICapacity_HAL(pGpu, pKernelMIGManager, pProfile, pParams, veidSlotCount)"
                       ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2705);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "kgrmgrGetVeidSizePerSpan(pGpu, pKernelGraphicsManager, &veidSizePerSpan)",
                     "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x26c9);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar3,
                   "kmigmgrGetComputeProfileFromSize(pGpu, pKernelMIGManager, pParams->computeSize, &profile)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x26c7);
      }
    }
    else {
      auVar18 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(uVar7);
      uVar15 = auVar18._0_8_;
      iVar3 = 5;
      do {
        iVar5 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,param_2,iVar3,&local_78);
        if (iVar5 == 0) {
          uVar16 = 0;
          if (param_4 != 0) {
            uVar16 = *(ulong *)(param_4 + 0x9d8);
          }
          auVar19 = kmigmgrComputeProfileSizeToCTSIdRange_IMPL(iVar3);
          if (auVar18._8_8_ < uVar15) {
            nvCheckFailedNoLog(4,"!rangeIsEmpty(totalRange)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2671);
          }
          else {
            if (auVar19._0_8_ <= auVar19._8_8_) {
              bVar6 = (byte)uVar15 & 0x3f;
              uVar15 = (0xffffffffffffffffU >> ((~auVar18[8] & 0x3f) + bVar6 & 0x3f)) << bVar6 &
                       *(ulong *)(param_3 + 0xe);
              if (uVar16 == 0) {
                uVar17 = 0;
              }
              else {
                bVar6 = 0;
                uVar17 = 0;
                while( true ) {
                  for (; (uVar16 & 1) == 0; uVar16 = uVar16 >> 1) {
                    bVar6 = bVar6 + 1;
                  }
                  local_78 = 0x222b;
                  puVar9 = &local_78;
                  uVar8 = 0xffffffffffe00000;
                  local_70 = 0x422b;
                  local_68 = 0x844b;
                  local_60 = 0x1044b;
                  local_58 = 0x20895;
                  local_50 = 0x40895;
                  local_48 = 0x81115;
                  local_40 = &DAT_00101115;
                  do {
                    uVar13 = *puVar9;
                    puVar9 = puVar9 + 1;
                    uVar8 = uVar8 | -(ulong)((uint)(uVar13 >> (bVar6 & 0x3f)) & 1) & uVar13;
                  } while (puVar9 != &local_38);
                  uVar17 = uVar17 | uVar8;
                  uVar16 = uVar16 >> 1;
                  if (uVar16 == 0) break;
                  bVar6 = bVar6 + 1;
                }
              }
              if (uVar15 == 0) {
                local_c4 = 0;
                local_a0 = 0;
              }
              else {
                local_c4 = 0;
                local_a0 = 0;
                bVar6 = auVar19[0] & 0x3f;
                uVar7 = 0;
                uVar4 = local_c4;
                while( true ) {
                  for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
                    uVar7 = uVar7 + 1;
                  }
                  local_80 = *param_3 >> 2 & 7;
                  local_88 = uVar7;
                  local_84 = param_4 != 0;
                  iVar3 = (**(code **)(param_1 + 0x3b90))
                                    (param_1 + 0x3b58,param_5,param_6,0x20800a46,&local_88,0x10);
                  if (iVar3 != 0) {
                    nvCheckOkFailedNoLog
                              (4,iVar3,
                               "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_CHECK_CTS_ID_VALID, &params, sizeof(params))"
                               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2695);
                    return iVar3;
                  }
                  local_c4 = uVar4;
                  if (local_7c != '\0') {
                    local_78 = 0x222b;
                    puVar9 = &local_78;
                    uVar16 = 0xffffffffffe00000;
                    local_70 = 0x422b;
                    local_68 = 0x844b;
                    local_60 = 0x1044b;
                    local_58 = 0x20895;
                    local_50 = 0x40895;
                    local_48 = 0x81115;
                    local_40 = &DAT_00101115;
                    do {
                      uVar8 = *puVar9;
                      puVar9 = puVar9 + 1;
                      uVar16 = uVar16 | -(ulong)((uint)(uVar8 >> ((byte)uVar7 & 0x3f)) & 1) & uVar8;
                    } while (puVar9 != &local_38);
                    uVar12 = 0;
                    uVar16 = uVar16 & (0xffffffffffffffffU >> ((~auVar19[8] & 0x3f) + bVar6 & 0x3f))
                                      << bVar6;
                    for (uVar8 = uVar16; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x8000000000000000)
                    {
                      uVar12 = uVar12 + 1;
                    }
                    uVar8 = (ulong)uVar12;
                    if (uVar16 == 0) {
                      uVar8 = 0x40;
                    }
                    lVar10 = uVar8 - auVar19._0_8_;
                    *(long *)(param_7 + (ulong)local_a0 * 4 + 0x24) = lVar10;
                    uVar16 = uVar16 - (uVar16 >> 1 & 0x5555555555555555);
                    uVar16 = (uVar16 & 0x3333333333333333) + (uVar16 >> 2 & 0x3333333333333333);
                    lVar1 = lVar10 + -1 +
                            ((uVar16 + (uVar16 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >>
                            0x38);
                    *(long *)(param_7 + (ulong)local_a0 * 4 + 0x26) = lVar1;
                    if ((uVar17 >> ((ulong)uVar7 & 0x3f) & 1) == 0) {
                      local_c4 = uVar4 + 1;
                      *(long *)(param_7 + (ulong)uVar4 * 4 + 2) = lVar10;
                      *(long *)(param_7 + (ulong)uVar4 * 4 + 4) = lVar1;
                    }
                    local_a0 = local_a0 + 1;
                  }
                  uVar15 = uVar15 >> 1;
                  if (uVar15 == 0) break;
                  uVar7 = uVar7 + 1;
                  uVar4 = local_c4;
                }
              }
              param_7[0x44] = local_a0;
              param_7[0x23] = local_a0;
              param_7[0x22] = local_c4;
              param_7[1] = local_c4;
              return 0;
            }
            nvCheckFailedNoLog(4,"!rangeIsEmpty(slotBasisIdRange)",
                               "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2672);
          }
          goto LAB_003f8768;
        }
        iVar3 = kmigmgrGetNextComputeSize_IMPL(param_1,param_2,0,iVar3);
      } while (iVar3 != 8);
      nvCheckFailedNoLog(4,"slotBasisComputeSize != KMIGMGR_COMPUTE_SIZE_INVALID",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x266d);
      iVar3 = 0x40;
    }
  }
  else {
    nvCheckFailedNoLog(4,"pParams->computeSize < NV2080_CTRL_GPU_PARTITION_FLAG_COMPUTE_SIZE__SIZE",
                       "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x265b);
LAB_003f8768:
    iVar3 = 0x1f;
  }
  return iVar3;
}


// ===== 003f8870 subdeviceCtrlCmdGpuGetComputeProfiles_IMPL =====

int subdeviceCtrlCmdGpuGetComputeProfiles_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  long *plVar6;
  int iVar7;
  ulong uVar8;
  uint *puVar9;
  char *pcVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  undefined1 *local_1c8;
  uint local_1b4;
  long *local_1a8 [2];
  undefined1 local_198 [16];
  uint local_188;
  uint local_17c;
  uint local_150 [35];
  int local_c4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = *(long *)(lVar3 + 0x1bc0);
  pcVar5 = *(char **)(lVar4 + 0x278);
  pcVar10 = pcVar5;
  if (pcVar5 != (char *)0x0) {
    pcVar10 = (char *)0x0;
    if (*pcVar5 != '\0') {
      pcVar10 = pcVar5 + 8;
    }
  }
  if ((*(char *)(lVar3 + 0x467) != '\0') && (*(char *)(lVar4 + 0x5340) != '\0')) {
    iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (lVar3,lVar4,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),local_1a8);
    if (iVar7 == 0) {
      lVar1 = *local_1a8[0];
      uVar2 = *(uint *)(lVar1 + 0x1c);
      local_1b4 = *(uint *)(lVar1 + 0x10);
      portMemCopy(local_198,0x48,lVar1,0x48);
    }
    else {
      iVar7 = kmigmgrGetGpuProfileFromFlag_IMPL(lVar3,lVar4,*param_2);
      local_1b4 = local_188;
      uVar2 = local_17c;
      if (iVar7 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar7,
                   "kmigmgrGetGpuProfileFromFlag(pGpu, pKernelMIGManager, pParams->partitionFlag, &giProfile)"
                   ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2099);
        return iVar7;
      }
    }
    local_1c8 = local_198;
    if (pcVar10 == (char *)0x0) {
      nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/mig_mgr/kernel_mig_manager.c",
                         0x20a0);
    }
    else {
      if (*(uint **)(pcVar10 + 0x20) != (uint *)0x0) {
        uVar11 = **(uint **)(pcVar10 + 0x20);
        if (8 < uVar11) {
          nvAssertFailedNoLog("pStaticInfo->pCIProfiles->profileCount <= NV_ARRAY_ELEMENTS(pParams->profiles)"
                              ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x20a2);
          uVar11 = **(uint **)(pcVar10 + 0x20);
        }
        uVar13 = 0;
        if (uVar11 != 0) {
          uVar13 = 0;
          uVar12 = 0;
          do {
            memset(local_150,0,0x118);
            puVar9 = *(uint **)(pcVar10 + 0x20);
            if (((puVar9[uVar12 * 6 + 5] <= uVar2) && (puVar9[uVar12 * 6 + 6] <= local_1b4)) &&
               (((uVar13 == 0 ||
                 ((((char)puVar9[uVar12 * 6 + 1] == '\0' ||
                   (uVar11 = uVar13 - 1, param_2[(ulong)uVar11 * 5 + 3] != puVar9[uVar12 * 6 + 2]))
                  || (param_2[(ulong)uVar11 * 5 + 4] != puVar9[uVar12 * 6 + 3])))) ||
                (puVar9[uVar12 * 6 + 5] != param_2[(ulong)uVar11 * 5 + 6])))) {
              lVar1 = uVar12 * 0x18;
              local_150[0] = (uint)(byte)puVar9[uVar12 * 6 + 1];
              plVar6 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
              iVar7 = kmigmgrComputeProfileGetCapacity_IMPL
                                (lVar3,lVar4,local_1c8,0,*(undefined4 *)(*plVar6 + 0x48),
                                 (int)plVar6[2],local_150);
              if (iVar7 != 0) {
                nvCheckOkFailedNoLog
                          (4,iVar7,
                           "kmigmgrComputeProfileGetCapacity(pGpu, pKernelMIGManager, &giProfile, NULL, RES_GET_CLIENT_HANDLE(pSubdevice), RES_GET_HANDLE(pSubdevice), &params)"
                           ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x20bd);
                return iVar7;
              }
              if (local_c4 != 0) {
                uVar8 = (ulong)uVar13;
                uVar13 = uVar13 + 1;
                *(undefined1 *)(param_2 + uVar8 * 5 + 2) =
                     *(undefined1 *)(*(long *)(pcVar10 + 0x20) + lVar1 + 4);
                param_2[uVar8 * 5 + 3] = *(undefined4 *)(*(long *)(pcVar10 + 0x20) + lVar1 + 8);
                param_2[uVar8 * 5 + 4] = *(undefined4 *)(*(long *)(pcVar10 + 0x20) + lVar1 + 0x18);
                param_2[uVar8 * 5 + 6] = *(undefined4 *)(*(long *)(pcVar10 + 0x20) + lVar1 + 0x14);
                param_2[uVar8 * 5 + 5] = *(undefined4 *)(*(long *)(pcVar10 + 0x20) + lVar1 + 0x10);
              }
              puVar9 = *(uint **)(pcVar10 + 0x20);
            }
            uVar11 = (int)uVar12 + 1;
            uVar12 = (ulong)uVar11;
          } while (uVar11 < *puVar9);
        }
        param_2[1] = uVar13;
        return 0;
      }
      nvCheckFailedNoLog(4,"pStaticInfo->pCIProfiles != NULL",
                         "src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x20a1);
    }
  }
  return 0x40;
}


// ===== 003f8c80 subdeviceCtrlCmdGpuGetComputeProfileCapacity_IMPL =====

int subdeviceCtrlCmdGpuGetComputeProfileCapacity_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  int iVar4;
  undefined1 local_198 [72];
  undefined4 local_150 [35];
  undefined4 local_c4;
  undefined1 local_c0 [128];
  undefined4 local_40;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(lVar1 + 0x1bc0);
  memset(local_150,0,0x118);
  iVar4 = kmigmgrGetGpuProfileFromFlag_IMPL(lVar1,uVar2,*param_2,local_198);
  if (iVar4 == 0) {
    local_150[0] = param_2[1];
    plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    iVar4 = kmigmgrComputeProfileGetCapacity_IMPL
                      (lVar1,uVar2,local_198,0,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],
                       local_150);
    if (iVar4 == 0) {
      param_2[2] = local_c4;
      param_2[0x24] = local_40;
      portMemCopy(param_2 + 4,0x80,local_c0,0x80);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "kmigmgrComputeProfileGetCapacity(pGpu, pKernelMIGManager, &profile, NULL, RES_GET_CLIENT_HANDLE(pSubdevice), RES_GET_HANDLE(pSubdevice), &params)"
                 ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x20e4);
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar4,
               "kmigmgrGetGpuProfileFromFlag(pGpu, pKernelMIGManager, pParams->partitionFlag, &profile)"
               ,"src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x20df);
  }
  return iVar4;
}


// ===== 003f8dc0 kmigmgrIsGPUInstanceFlagLegal_IMPL =====

undefined8 kmigmgrIsGPUInstanceFlagLegal_IMPL(undefined8 param_1,undefined8 param_2,uint param_3)

{
  if ((~param_3 & 0x30000000) != 0) {
    return 1;
  }
  nvDbg_Printf("src/kernel/gpu/mig_mgr/kernel_mig_manager.c",0x2755,
               "kmigmgrIsGPUInstanceFlagLegal_IMPL",4,
               "NVRM: Unrecognized GPU all media partitioning flag 0x%x\n",3);
  return 0;
}


// ===== 003f8e10 migconfigsessionConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int migconfigsessionConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long *plVar5;
  
  lVar2 = g_pSys;
  puVar1 = *(undefined8 **)(param_3 + 0x40);
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (plVar5 == (long *)0x0) {
    iVar4 = 0x23;
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/mig_mgr/mig_config_session.c",0x39);
  }
  else {
    osRmCapInitDescriptor(param_1 + 0xd8);
    iVar4 = osRmCapAcquire(*(undefined8 *)(lVar2 + 0x188),2,*puVar1,param_1 + 0xd8);
    if (iVar4 == 0x56) {
      iVar4 = 0;
      cVar3 = (**(code **)(*plVar5 + 0xe0))(plVar5,*(undefined4 *)(param_2 + 0x28));
      if (cVar3 == '\0') {
        iVar4 = 0x1b;
        nvDbg_Printf("src/kernel/gpu/mig_mgr/mig_config_session.c",0x4b,
                     "migconfigsessionConstruct_IMPL",4,"NVRM: insufficient permissions\n");
      }
    }
    else if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/mig_config_session.c",0x51,
                   "migconfigsessionConstruct_IMPL",4,"NVRM: Capability validation failed\n");
    }
  }
  return iVar4;
}


// ===== 003f8f60 migconfigsessionDestruct_IMPL =====

void migconfigsessionDestruct_IMPL(long param_1)

{
  osRmCapRelease(*(undefined8 *)(param_1 + 0xd8));
  return;
}


// ===== 003f8f70 migmonitorsessionConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int migmonitorsessionConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long *plVar5;
  
  lVar2 = g_pSys;
  puVar1 = *(undefined8 **)(param_3 + 0x40);
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (plVar5 == (long *)0x0) {
    iVar4 = 0x23;
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/mig_mgr/mig_monitor_session.c",0x39);
  }
  else {
    osRmCapInitDescriptor(param_1 + 0xd8);
    iVar4 = osRmCapAcquire(*(undefined8 *)(lVar2 + 0x188),3,*puVar1,param_1 + 0xd8);
    if (iVar4 == 0x56) {
      iVar4 = 0;
      cVar3 = (**(code **)(*plVar5 + 0xe0))(plVar5,*(undefined4 *)(param_2 + 0x28));
      if (cVar3 == '\0') {
        iVar4 = 0x1b;
        nvDbg_Printf("src/kernel/gpu/mig_mgr/mig_monitor_session.c",0x4b,
                     "migmonitorsessionConstruct_IMPL",4,"NVRM: insufficient permissions\n");
      }
    }
    else if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/mig_mgr/mig_monitor_session.c",0x51,
                   "migmonitorsessionConstruct_IMPL",4,"NVRM: Capability validation failed\n");
    }
  }
  return iVar4;
}


// ===== 003f90c0 migmonitorsessionDestruct_IMPL =====

void migmonitorsessionDestruct_IMPL(long param_1)

{
  osRmCapRelease(*(undefined8 *)(param_1 + 0xd8));
  return;
}


// ===== 003f90d0 kgmmuFmtInitLevels_GA10X =====

void kgmmuFmtInitLevels_GA10X(undefined8 param_1,long param_2)

{
  kgmmuFmtInitLevels_GP10X();
  *(undefined1 *)(param_2 + 0x33) = 1;
  return;
}


// ===== 003f90f0 kgmmuSetTlbInvalidationScope_GA100 =====

undefined8
kgmmuSetTlbInvalidationScope_GA100(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  if (param_3 == 1) {
    *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) & 0xfffe7fff | 0x8000;
    return 0;
  }
  if (param_3 != 2) {
    if (param_3 == 0) {
      *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) & 0xfffe7fff;
      return 0;
    }
    return 0x1f;
  }
  *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) & 0xfffe7fff | 0x10000;
  return 0;
}


// ===== 003f9160 kgmmuInitCeMmuFaultIdRange_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgmmuInitCeMmuFaultIdRange_GA100(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  *(undefined8 *)(param_2 + 0x67c8) = 0;
  iVar2 = (**(code **)(param_1 + 0xa0))();
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"gpuConstructDeviceInfoTable_HAL(pGpu)",
               "src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0x110);
    return iVar2;
  }
  if (*(uint *)(param_1 + 0x3b30) != 0) {
    puVar3 = *(uint **)(param_1 + 0x3b28);
    uVar5 = 0;
    uVar6 = 0xffffffff;
    puVar4 = puVar3 + (ulong)*(uint *)(param_1 + 0x3b30) * 0xc;
    do {
      if (puVar3[2] == 0x13) {
        uVar1 = *puVar3;
        if (uVar1 < uVar6) {
          uVar6 = uVar1;
        }
        if (uVar5 < uVar1) {
          uVar5 = uVar1;
        }
      }
      puVar3 = puVar3 + 0xc;
    } while (puVar4 != puVar3);
    if ((uVar6 != 0xffffffff) && (uVar5 != 0)) {
      *(uint *)(param_2 + 0x67cc) = uVar5;
      *(uint *)(param_2 + 0x67c8) = uVar6;
      nvDbg_Printf("src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0x125,
                   "kgmmuInitCeMmuFaultIdRange_GA100",1,
                   "NVRM: CE MMU Fault ID range [0x%x - 0x%x]\n",uVar6,uVar5);
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0x11d,
               "kgmmuInitCeMmuFaultIdRange_GA100",4,"NVRM: Failed to find any MMU Fault ID\n");
  nvAssertFailedNoLog(&DAT_00d64973,"src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0x11e);
  return 0x57;
}


// ===== 003f92d0 kgmmuSetupWarForBug2720120_GA100 =====

int kgmmuSetupWarForBug2720120_GA100(long param_1)

{
  char cVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  char *pcVar11;
  char *pcVar12;
  long lVar13;
  ulong uVar14;
  uint *puVar15;
  undefined8 uVar16;
  uint uVar17;
  ulong uVar18;
  int iVar19;
  long *plVar20;
  long lVar21;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (*(long *)(param_1 + 0x5c0) != 0) {
    return 0;
  }
  plVar20 = (long *)(param_1 + 0x550);
  while ((lVar21 = *plVar20, lVar21 == 0 || (*(char *)(param_1 + 0x67d3) == '\0'))) {
LAB_003f9327:
    plVar20 = plVar20 + 1;
    if ((long *)(param_1 + 0x568) == plVar20) {
      return 0;
    }
  }
  lVar8 = gpuEngineGetGpu(*(undefined8 *)(param_1 + 0x160));
  lVar3 = *(long *)(&DAT_00001b90 + lVar8);
  uVar16 = *(undefined8 *)(lVar8 + 0x1b78);
  lVar9 = kgmmuFmtGet_IMPL(param_1,0,0);
  uVar10 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar9 + 8),0x1d);
  pcVar11 = (char *)mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar9 + 8),0x15);
  pcVar12 = (char *)mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar9 + 8),0xc);
  lVar13 = gmmuFmtGetPde(lVar9,pcVar11,1);
  lVar9 = gmmuFmtGetPde(lVar9,uVar10,0);
  if (*(long *)(lVar3 + 0x7c98) != 0) {
    nvAssertFailedNoLog("pKernelBus->virtualBar2[GPU_GFID_PF].pCpuMapping == NULL",
                        "src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0x9d);
  }
  *(undefined8 *)(param_1 + 0x5b8) = 0;
  *(undefined8 *)(param_1 + 0x5c0) = 0;
  iVar6 = memdescCreate(param_1 + 0x5b8,lVar8,
                        (uint)(byte)pcVar12[2] << ((pcVar12[1] - *pcVar12) + 1U & 0x1f),0x1000,1,
                        *(undefined4 *)(param_1 + 0x578),*(undefined4 *)(param_1 + 0x57c));
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,
               "memdescCreate(&pKernelGmmu->pWarSmallPageTable, pGpu, mmuFmtLevelSize(pSmallPT), RM_PAGE_SIZE, NV_TRUE, kgmmuGetPTEAperture(pKernelGmmu), kgmmuGetPTEAttr(pKernelGmmu), 0)"
               ,"src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0xa4,0);
    goto LAB_003f9745;
  }
  *(undefined4 *)(*(long *)(param_1 + 0x5b8) + 0x9c) = 0x20;
  iVar6 = memdescAlloc(*(undefined8 *)(param_1 + 0x5b8));
  if (iVar6 == 0) {
    iVar6 = memmgrMemDescMemSet_IMPL(uVar16,*(undefined8 *)(param_1 + 0x5b8),0,0);
    if (iVar6 == 0) {
      uVar7 = kgmmuGetMemAperture_IMPL(param_1,*(undefined8 *)(param_1 + 0x5b8));
      lVar3 = lVar21 + 0x500;
      bVar5 = memdescGetVolatility(*(undefined8 *)(param_1 + 0x5b8));
      *(uint *)(lVar3 + (ulong)*(ushort *)(lVar13 + 0xea)) =
           (uint)(bVar5 ^ *(byte *)(lVar13 + 0xec)) << ((byte)*(undefined2 *)(lVar13 + 0xe8) & 0x1f)
           | *(uint *)(lVar3 + (ulong)*(ushort *)(lVar13 + 0xea)) & *(uint *)(lVar13 + 0xe4);
      *(uint *)(lVar3 + (ulong)*(ushort *)(lVar13 + 0x12)) =
           (uint)*(byte *)(*(long *)(lVar13 + 0x18) + 1 + (ulong)uVar7 * 2) <<
           ((byte)*(undefined2 *)(lVar13 + 0x10) & 0x1f) |
           *(uint *)(lVar3 + (ulong)*(ushort *)(lVar13 + 0x12)) & *(uint *)(lVar13 + 0xc);
      uVar10 = memdescGetPtePhysAddr(*(undefined8 *)(param_1 + 0x5b8),1,0);
      uVar14 = kgmmuEncodePhysAddr_IMPL(param_1,uVar7,uVar10,0xffffffffffffffff);
      puVar15 = (uint *)gmmuFmtPdePhysAddrFld(lVar13,(ulong)uVar7);
      if (*puVar15 != 0) {
        uVar14 = uVar14 >> ((byte)puVar15[0xe] & 0x3f);
        uVar7 = 0;
        do {
          uVar17 = uVar7 + 1;
          uVar18 = *(ulong *)(lVar3 + (ulong)puVar15[(ulong)uVar7 * 6 + 6]);
          *(ulong *)(lVar3 + (ulong)puVar15[(ulong)uVar7 * 6 + 6]) =
               (uVar14 << ((byte)puVar15[(ulong)uVar7 * 6 + 5] & 0x3f) ^ uVar18) &
               *(ulong *)(puVar15 + (ulong)uVar7 * 6 + 2) ^ uVar18;
          uVar14 = uVar14 >> ((byte)puVar15[(ulong)uVar7 * 6 + 4] & 0x3f);
          uVar7 = uVar17;
        } while (uVar17 < *puVar15);
      }
      iVar6 = memdescCreate(param_1 + 0x5c0,lVar8,
                            (uint)(byte)pcVar11[2] << ((pcVar11[1] - *pcVar11) + 1U & 0x1f),0x1000,1
                            ,*(undefined4 *)(param_1 + 0x578));
      if (iVar6 == 0) {
        *(undefined4 *)(*(long *)(param_1 + 0x5c0) + 0x9c) = 0x21;
        iVar6 = memdescAlloc(*(undefined8 *)(param_1 + 0x5c0));
        if (iVar6 == 0) {
          cVar1 = pcVar11[1];
          cVar2 = *pcVar11;
          iVar19 = 0;
          do {
            local_58 = *(undefined8 *)(param_1 + 0x5c0);
            local_48 = 0;
            local_40 = 0;
            local_50 = (ulong)((uint)(byte)pcVar11[2] * iVar19);
            iVar6 = memmgrMemWrite_IMPL(uVar16,&local_58,lVar3,pcVar11[2],0);
            if (iVar6 != 0) {
              nvAssertOkFailedNoLog
                        (iVar6,
                         "memmgrMemWrite(pMemoryManager, &pageDirEntry, pFam->bug2720120WarPde0.v8, pPageDir0->entrySize, TRANSFER_FLAGS_NONE)"
                         ,"src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0xd7);
              goto LAB_003f96e5;
            }
            iVar19 = iVar19 + 1;
          } while (1 << ((cVar1 - cVar2) + 1U & 0x1f) != iVar19);
          uVar7 = kgmmuGetMemAperture_IMPL(param_1,*(undefined8 *)(param_1 + 0x5c0));
          bVar5 = memdescGetVolatility(*(undefined8 *)(param_1 + 0x5c0));
          lVar21 = lVar21 + 0x510;
          *(uint *)(lVar21 + (ulong)*(ushort *)(lVar9 + 0xea)) =
               (uint)(bVar5 ^ *(byte *)(lVar9 + 0xec)) <<
               ((byte)*(undefined2 *)(lVar9 + 0xe8) & 0x1f) |
               *(uint *)(lVar21 + (ulong)*(ushort *)(lVar9 + 0xea)) & *(uint *)(lVar9 + 0xe4);
          *(uint *)(lVar21 + (ulong)*(ushort *)(lVar9 + 0x12)) =
               (uint)*(byte *)(*(long *)(lVar9 + 0x18) + 1 + (ulong)uVar7 * 2) <<
               ((byte)*(undefined2 *)(lVar9 + 0x10) & 0x1f) |
               *(uint *)(lVar21 + (ulong)*(ushort *)(lVar9 + 0x12)) & *(uint *)(lVar9 + 0xc);
          uVar16 = memdescGetPtePhysAddr(*(undefined8 *)(param_1 + 0x5c0),1,0);
          uVar14 = kgmmuEncodePhysAddr_IMPL(param_1,uVar7,uVar16,0xffffffffffffffff);
          puVar15 = (uint *)gmmuFmtPdePhysAddrFld(lVar9);
          if (*puVar15 != 0) {
            uVar14 = uVar14 >> ((byte)puVar15[0xe] & 0x3f);
            uVar18 = 0;
            do {
              uVar7 = (int)uVar18 + 1;
              uVar4 = *(ulong *)(lVar21 + (ulong)puVar15[uVar18 * 6 + 6]);
              *(ulong *)(lVar21 + (ulong)puVar15[uVar18 * 6 + 6]) =
                   (uVar14 << ((byte)puVar15[uVar18 * 6 + 5] & 0x3f) ^ uVar4) &
                   *(ulong *)(puVar15 + uVar18 * 6 + 2) ^ uVar4;
              uVar14 = uVar14 >> ((byte)puVar15[uVar18 * 6 + 4] & 0x3f);
              uVar18 = (ulong)uVar7;
            } while (uVar7 < *puVar15);
          }
          goto LAB_003f9327;
        }
        nvAssertOkFailedNoLog
                  (iVar6,"status","src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0xcf);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar6,
                   "memdescCreate(&pKernelGmmu->pWarPageDirectory0, pGpu, mmuFmtLevelSize(pPageDir0), RM_PAGE_SIZE, NV_TRUE, kgmmuGetPTEAperture(pKernelGmmu), kgmmuGetPTEAttr(pKernelGmmu), 0)"
                   ,"src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",199);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "memmgrMemDescMemSet(pMemoryManager, pKernelGmmu->pWarSmallPageTable, 0, TRANSFER_FLAGS_NONE)"
                 ,"src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0xae);
    }
  }
  else {
    nvAssertOkFailedNoLog(iVar6,"status","src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0xac);
  }
LAB_003f96e5:
  if (*(long *)(param_1 + 0x5b8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_1 + 0x5b8));
    *(undefined8 *)(param_1 + 0x5b8) = 0;
  }
  if (*(long *)(param_1 + 0x5c0) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_1 + 0x5c0));
    *(undefined8 *)(param_1 + 0x5c0) = 0;
  }
LAB_003f9745:
  nvAssertOkFailedNoLog
            (iVar6,"kgmmuSetupWarForBug2720120FmtFamily_GA100(pKernelGmmu, pFam)",
             "src/kernel/gpu/mmu/arch/ampere/kern_gmmu_ga100.c",0x13f);
  return iVar6;
}


// ===== 003f99b0 kgmmuIsP2PUnboundInstFault_GA100 =====

bool kgmmuIsP2PUnboundInstFault_GA100(undefined8 param_1,int param_2,int param_3)

{
  if (param_2 != 4) {
    return false;
  }
  return param_3 - 0x2bU < 8;
}


// ===== 003f99d0 kgmmuServiceMmuFault_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgmmuServiceMmuFault_GA100(undefined8 param_1,long param_2,long param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (*(int *)(param_3 + 0x28) != 4) {
    uVar2 = kgmmuServiceMmuFault_GV100();
    return uVar2;
  }
  uVar1 = param_4[6];
  lVar3 = gpuGetKernelFifoShared_IMPL();
  uVar2 = (**(code **)(lVar3 + 0x358))(param_1,lVar3,uVar1);
  uVar4 = (**(code **)(param_2 + 0x2a8))(param_2,param_4[2]);
  nvErrorLog_va(param_1,0x6c,
                "NVLink remote translation error: faulted @ 0x%x_%08x. Fault is of type %s %s",
                param_4[1],*param_4,uVar4,uVar2);
  return 0;
}


// ===== 003f9a70 kgmmuInstBlkMagicValueGet_GA10B =====

undefined8
kgmmuInstBlkMagicValueGet_GA10B(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0x20c;
  *param_3 = 0xcafeca11;
  return 0;
}


// ===== 003f9a90 kgmmuFmtInitLevels_GB10X =====

void kgmmuFmtInitLevels_GB10X(undefined8 param_1,long param_2)

{
  kgmmuFmtInitLevels_GH10X();
  *(undefined1 *)(param_2 + 0x33) = 1;
  return;
}


// ===== 003f9ab0 kgmmuCommitTlbInvalidate_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuCommitTlbInvalidate_GB100(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  if (*(int *)(param_3 + 0xc) == 0) {
    uVar2 = *(uint *)(param_3 + 0x10);
    if ((uVar2 & 2) == 0) {
      (**(code **)(param_2 + 0x208))();
      uVar2 = *(uint *)(param_3 + 0x10);
    }
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30b0,uVar2,0);
    uVar1 = (**(code **)(param_2 + 0x1f8))(param_1,param_2,param_3 + 0x18);
    return uVar1;
  }
  nvAssertFailedNoLog("IS_GFID_PF(pParams->gfid)",
                      "src/kernel/gpu/mmu/arch/blackwell/kern_gmmu_gb100.c",0x35);
  return 0x1f;
}


// ===== 003f9b60 kgmmuGetFaultTypeString_GB100 =====

char * kgmmuGetFaultTypeString_GB100(undefined8 param_1,uint param_2)

{
  char *pcVar1;
  
  pcVar1 = "UNRECOGNIZED_FAULT";
  if (param_2 < 0x10) {
    pcVar1 = *(char **)(CSWTCH_7 + (ulong)param_2 * 8);
  }
  return pcVar1;
}


// ===== 003f9b80 kgmmuGetFaultType_GB100 =====

undefined8 kgmmuGetFaultType_GB100(undefined8 param_1,undefined8 param_2,uint param_3,int *param_4)

{
  if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("pMmuFaultType != NULL",
                        "src/kernel/gpu/mmu/arch/blackwell/kern_gmmu_gb100.c",0x85);
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


// ===== 003f9d10 kgmmuReadClientShadowBufPutIndex_GB100 =====

undefined8 kgmmuReadClientShadowBufPutIndex_GB100(void)

{
  return 0;
}


// ===== 003f9d20 kgmmuWriteClientShadowBufPutIndex_GB100 =====

void kgmmuWriteClientShadowBufPutIndex_GB100(void)

{
  return;
}


// ===== 003f9d30 kgmmuCheckAccessCounterBar2FaultServicingState_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuCheckAccessCounterBar2FaultServicingState_GB100(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  
  lVar1 = *(long *)(param_1 + 0x1cd8);
  if (*(int *)(lVar1 + 0x280) == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      uVar2 = (**(code **)(lVar1 + 0x230))(param_1,lVar1,uVar3);
      if ((char)uVar2 != '\0') {
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(lVar1 + 0x280));
  }
  return uVar2;
}


// ===== 003f9db0 kgmmuWriteMmuFaultBufferSize_GB100 =====

void kgmmuWriteMmuFaultBufferSize_GB100
               (long param_1,long param_2,uint param_3,int param_4,uint param_5)

{
  if (param_5 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/blackwell/kern_gmmu_gb100.c",
                        0x10d);
  }
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3010 + *(int *)(param_1 + 0x3a64),param_4,0);
  if (-1 < param_4) {
    *(undefined4 *)(param_2 + 0x5f0 + (ulong)param_3 * 0x30 + (ulong)param_5 * 0x188) = 0;
  }
  return;
}


// ===== 003f9e60 kgmmuWriteMmuFaultBufferHiLo_GB100 =====

void kgmmuWriteMmuFaultBufferHiLo_GB100
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,ulong param_5,
               int param_6)

{
  if (param_6 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/blackwell/kern_gmmu_gb100.c",
                        0x125);
    param_5 = param_5 & 0xffffffff;
  }
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3004 + *(int *)(param_1 + 0x3a64),param_5,0);
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 0x20 + 0x3000 + *(int *)(param_1 + 0x3a64),param_4,0);
  return;
}


// ===== 003f9f10 kgmmuSetAndGetDefaultFaultBufferSize_GB100 =====

int kgmmuSetAndGetDefaultFaultBufferSize_GB100
              (long param_1,undefined8 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_4 != 0) {
    nvAssertFailedNoLog("IS_GFID_PF(gfid)","src/kernel/gpu/mmu/arch/blackwell/kern_gmmu_gb100.c",
                        0x142);
  }
  iVar2 = param_3 * 0x20 + 0x3010;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar2,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar2,uVar1 | 0x40000000,0);
  uVar1 = regRead032(param_1 + 0x3a18,0,0,iVar2 + *(int *)(param_1 + 0x3a64),0);
  return (uVar1 & 0xfffff) << 5;
}


// ===== 003f9fd0 kgmmuFmtInitLevels_GH10X =====

void kgmmuFmtInitLevels_GH10X
               (undefined8 param_1,undefined2 *param_2,uint param_3,int param_4,undefined1 param_5)

{
  if (param_4 != 3) {
    nvAssertFailedNoLog("version == GMMU_FMT_VERSION_3",
                        "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_fmt_gh10x.c",0x3b);
    return;
  }
  if (6 < param_3) {
    *param_2 = 0x3838;
    *(undefined2 **)(param_2 + 8) = param_2 + 0xc;
    *(undefined2 **)(param_2 + 0x14) = param_2 + 0x18;
    *(undefined2 **)(param_2 + 0x20) = param_2 + 0x24;
    *(undefined2 **)(param_2 + 0x2c) = param_2 + 0x30;
    *(undefined1 *)(param_2 + 1) = 8;
    *(undefined1 *)(param_2 + 2) = 1;
    *(undefined4 *)(param_2 + 4) = 0;
    param_2[0xc] = 0x372f;
    *(undefined1 *)(param_2 + 0xd) = 8;
    *(undefined1 *)(param_2 + 0xe) = 1;
    *(undefined4 *)(param_2 + 0x10) = 1;
    param_2[0x18] = 0x2e26;
    *(undefined1 *)(param_2 + 0x19) = 8;
    *(undefined1 *)(param_2 + 0x1a) = 1;
    *(undefined4 *)(param_2 + 0x1c) = 2;
    *(undefined1 *)(param_2 + 0x26) = 1;
    *(undefined4 *)(param_2 + 0x24) = 0x108251d;
    *(undefined4 *)(param_2 + 0x28) = 3;
    *(undefined1 *)(param_2 + 0x32) = 2;
    *(undefined4 *)(param_2 + 0x30) = 0x1101c15;
    *(undefined2 **)(param_2 + 0x38) = param_2 + 0x3c;
    *(undefined4 *)(param_2 + 0x34) = 4;
    *(undefined1 *)(param_2 + 0x3c) = param_5;
    *(undefined1 *)((long)param_2 + 0x79) = 0x14;
    param_2[0x3d] = 0x108;
    *(undefined4 *)(param_2 + 0x40) = 6;
    *(undefined4 *)(param_2 + 0x48) = 0x108140c;
    *(undefined4 *)(param_2 + 0x4c) = 5;
    return;
  }
  nvAssertFailedNoLog("numLevels >= 7","src/kernel/gpu/mmu/arch/hopper/kern_gmmu_fmt_gh10x.c",0x3c);
  return;
}


// ===== 003fa0f0 kgmmuFmtInitPdeMulti_GH10X =====

void kgmmuFmtInitPdeMulti_GH10X(undefined8 param_1,long param_2,int param_3,undefined8 param_4)

{
  if (param_3 == 3) {
    *(undefined4 *)(param_2 + 0x10) = 3;
    *(undefined8 *)(param_2 + 0x18) = 0xfffffff900000006;
    *(undefined8 *)(param_2 + 0x118) = 0xfffffff900000006;
    *(undefined8 *)(param_2 + 0xb8) = 0xfffffffffff00;
    *(undefined8 *)(param_2 + 0x1b8) = 0xffffffffff000;
    *(undefined4 *)(param_2 + 0x20) = 1;
    *(undefined1 *)(param_2 + 0x24) = 5;
    *(undefined8 *)(param_2 + 0x28) = param_4;
    *(undefined4 *)(param_2 + 0xb0) = 1;
    *(undefined8 *)(param_2 + 0xc0) = 0x80000002c;
    *(undefined4 *)(param_2 + 200) = 0;
    *(undefined4 *)(param_2 + 0xe8) = 8;
    *(undefined8 *)(param_2 + 0x100) = 0xffffffc700000038;
    *(undefined4 *)(param_2 + 0x108) = 3;
    *(undefined4 *)(param_2 + 0x110) = 3;
    *(undefined4 *)(param_2 + 0x120) = 0x80001;
    *(undefined1 *)(param_2 + 0x124) = 5;
    *(undefined8 *)(param_2 + 0x128) = param_4;
    *(undefined4 *)(param_2 + 0x1b0) = 1;
    *(undefined8 *)(param_2 + 0x1c0) = 0xc00000028;
    *(undefined4 *)(param_2 + 0x1c8) = 8;
    *(undefined4 *)(param_2 + 0x1e8) = 0xc;
    *(undefined8 *)(param_2 + 0x200) = 0xffffffc700000038;
    *(undefined4 *)(param_2 + 0x208) = 0x80003;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_3",
                      "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_fmt_gh10x.c",0x80);
  return;
}


// ===== 003fa220 kgmmuFmtInitPde_GH10X =====

void kgmmuFmtInitPde_GH10X(undefined8 param_1,undefined4 *param_2,int param_3,undefined8 param_4)

{
  if (param_3 == 3) {
    *param_2 = 3;
    *(undefined8 *)(param_2 + 2) = 0xfffffff900000006;
    *(undefined8 *)(param_2 + 0x3c) = 0xffffffc700000038;
    *(undefined8 *)(param_2 + 0x2a) = 0xffffffffff000;
    param_2[4] = 1;
    *(undefined1 *)(param_2 + 5) = 5;
    *(undefined8 *)(param_2 + 6) = param_4;
    param_2[0x3e] = 3;
    param_2[0x28] = 1;
    *(undefined8 *)(param_2 + 0x2c) = 0xc00000028;
    param_2[0x2e] = 0;
    param_2[0x36] = 0xc;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_3",
                      "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_fmt_gh10x.c",0x98);
  return;
}


// ===== 003fa2d0 kgmmuFmtInitPte_GH10X =====

void kgmmuFmtInitPte_GH10X(undefined8 param_1,undefined8 *param_2,int param_3,undefined8 param_4)

{
  if (param_3 == 3) {
    *(undefined1 *)(param_2 + 2) = 0;
    *param_2 = 0x100000003;
    param_2[1] = 0xfffffffe;
    param_2[3] = 0xfffffff900000006;
    param_2[0x1e] = 0x1fffffffe0000000;
    param_2[0x30] = 0x8fffff0ff;
    param_2[0x34] = 0xffffff07000000f8;
    *(undefined4 *)(param_2 + 4) = 1;
    *(undefined1 *)((long)param_2 + 0x24) = 5;
    param_2[5] = param_4;
    *(undefined4 *)(param_2 + 0x1f) = 0x4001d;
    *(undefined4 *)((long)param_2 + 0x17c) = 0xf00;
    *(undefined4 *)(param_2 + 0x35) = 3;
    *(undefined4 *)(param_2 + 0xe) = 1;
    param_2[0xf] = 0xffffffffff000;
    param_2[0x10] = 0xc00000028;
    *(undefined4 *)(param_2 + 0x11) = 0;
    *(undefined4 *)(param_2 + 0x15) = 0xc;
    *(undefined4 *)(param_2 + 0x16) = 1;
    param_2[0x17] = 0xffffffffff000;
    param_2[0x18] = 0xc00000028;
    *(undefined4 *)(param_2 + 0x19) = 0;
    *(undefined4 *)(param_2 + 0x1d) = 0xc;
    *(undefined4 *)(param_2 + 6) = 1;
    param_2[7] = 0xffffffffff000;
    param_2[8] = 0xc00000028;
    *(undefined4 *)(param_2 + 9) = 0;
    *(undefined4 *)(param_2 + 0xd) = 0xc;
    return;
  }
  nvAssertFailedNoLog("version == GMMU_FMT_VERSION_3",
                      "src/kernel/gpu/mmu/arch/hopper/kern_gmmu_fmt_gh10x.c",0xa6);
  return;
}


// ===== 003fa410 kgmmuFillFakeSparseTables =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kgmmuFillFakeSparseTables(long param_1,long param_2,ulong *param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  uint *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  ulong *puVar12;
  byte local_88;
  int local_70;
  int local_6c;
  uint local_68 [4];
  ulong local_58 [5];
  
  lVar1 = *(long *)(param_1 + 0x560);
  local_70 = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pFam != NULL","src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",999);
    return 0x40;
  }
  puVar4 = (uint *)gmmuFmtPdePhysAddrFld(lVar1 + 0x210,1);
  iVar3 = (**(code **)(param_1 + 0x290))(param_1,0,&local_70);
  if (iVar3 != 0) {
    nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromSw_HAL(pKernelGmmu, templatePdePcfSw, &templatePdePcfHw) == NV_OK)"
                        ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x3ea);
    return 0x1f;
  }
  lVar7 = 0;
  portMemSet(local_68,0,8);
  *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar1 + 0x30a)) =
       local_70 << ((byte)*(undefined2 *)(lVar1 + 0x308) & 0x1f) |
       *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar1 + 0x30a)) & *(uint *)(lVar1 + 0x304);
  *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar1 + 0x222)) =
       (uint)*(byte *)(*(long *)(lVar1 + 0x228) + 3) <<
       ((byte)*(undefined2 *)(lVar1 + 0x220) & 0x1f) |
       *(uint *)((long)local_68 + (ulong)*(ushort *)(lVar1 + 0x222)) & *(uint *)(lVar1 + 0x21c);
  puVar5 = param_3;
  do {
    puVar12 = puVar5 + 0x200;
    portMemCopy(local_58 + 2,8,local_68,8);
    if (lVar7 == 0) {
      local_6c = 0;
      iVar3 = (**(code **)(param_1 + 0x290))(param_1,4,&local_6c);
      if (iVar3 != 0) {
        nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromSw_HAL(pKernelGmmu, pdePcfSw, &pdePcfHw) == NV_OK)"
                            ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x408);
        return 0x1f;
      }
      portMemSet(local_58,0,8);
      *(uint *)((long)local_58 + (ulong)*(ushort *)(lVar1 + 0x222)) =
           (uint)*(byte *)(*(long *)(lVar1 + 0x228) + 1) <<
           ((byte)*(undefined2 *)(lVar1 + 0x220) & 0x1f) |
           *(uint *)((long)local_58 + (ulong)*(ushort *)(lVar1 + 0x222)) & *(uint *)(lVar1 + 0x21c);
      *(uint *)((long)local_58 + (ulong)*(ushort *)(lVar1 + 0x30a)) =
           local_6c << ((byte)*(undefined2 *)(lVar1 + 0x308) & 0x1f) |
           *(uint *)((long)local_58 + (ulong)*(ushort *)(lVar1 + 0x30a)) & *(uint *)(lVar1 + 0x304);
      uVar9 = *puVar4;
LAB_003fa5bd:
      if (uVar9 != 0) {
        uVar8 = (ulong)(((param_2 + -0x1000) - (long)param_3) + (long)puVar12) >>
                ((byte)puVar4[0xe] & 0x3f);
        uVar11 = 0;
        do {
          uVar9 = (int)uVar11 + 1;
          uVar2 = *(ulong *)((long)local_58 + (ulong)puVar4[uVar11 * 6 + 6] + 0x10);
          *(ulong *)((long)local_58 + (ulong)puVar4[uVar11 * 6 + 6] + 0x10) =
               uVar2 ^ (uVar8 << ((byte)puVar4[uVar11 * 6 + 5] & 0x3f) ^ uVar2) &
                       *(ulong *)(puVar4 + uVar11 * 6 + 2);
          uVar8 = uVar8 >> ((byte)puVar4[uVar11 * 6 + 4] & 0x3f);
          uVar11 = (ulong)uVar9;
        } while (uVar9 < *puVar4);
      }
    }
    else {
      uVar9 = puVar4[0xe];
      uVar11 = *(ulong *)(param_1 + 0x518 + lVar7 * 8);
      portMemCopy(local_58,8,local_68,8);
      if (*puVar4 != 0) {
        local_88 = (byte)uVar9;
        uVar8 = (-1L << (local_88 & 0x3f) & uVar11) >> ((byte)puVar4[0xe] & 0x3f);
        uVar11 = 0;
        do {
          uVar10 = (int)uVar11 + 1;
          uVar2 = *(ulong *)((long)local_58 + (ulong)puVar4[uVar11 * 6 + 6]);
          *(ulong *)((long)local_58 + (ulong)puVar4[uVar11 * 6 + 6]) =
               uVar2 ^ (uVar8 << ((byte)puVar4[uVar11 * 6 + 5] & 0x3f) ^ uVar2) &
                       *(ulong *)(puVar4 + uVar11 * 6 + 2);
          uVar9 = *puVar4;
          uVar8 = uVar8 >> ((byte)puVar4[uVar11 * 6 + 4] & 0x3f);
          uVar11 = (ulong)uVar10;
        } while (uVar10 < uVar9);
        goto LAB_003fa5bd;
      }
    }
    *(ulong *)(param_1 + 0x520 + lVar7 * 8) = local_58[2];
    do {
      *puVar5 = local_58[0];
      puVar6 = puVar5 + 2;
      puVar5[1] = local_58[0];
      puVar5 = puVar6;
    } while (puVar6 != puVar12);
    lVar7 = lVar7 + 1;
    puVar5 = puVar12;
    if (lVar7 == 3) {
      return 0;
    }
  } while( true );
}


// ===== 003fa790 kgmmuFmtIsVersionSupported_GH10X =====

bool kgmmuFmtIsVersionSupported_GH10X(undefined8 param_1,int param_2)

{
  return param_2 == 3;
}


// ===== 003fa7a0 kgmmuFmtFamiliesInit_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgmmuFmtFamiliesInit_GH100(undefined8 param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  int local_20;
  int local_1c;
  
  lVar2 = *(long *)(param_2 + 0x560);
  local_20 = 0;
  local_1c = 0;
  if (lVar2 == 0) {
    return 0;
  }
  iVar3 = (**(code **)(param_2 + 0x290))(param_2,0x204,&local_20);
  if (iVar3 == 0) {
    puVar1 = (uint *)(lVar2 + 0x4d0 + (ulong)*(ushort *)(lVar2 + 0x222));
    *puVar1 = (uint)*(byte *)(*(long *)(lVar2 + 0x228) + 1) <<
              ((byte)*(undefined2 *)(lVar2 + 0x220) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x21c);
    puVar1 = (uint *)(lVar2 + 0x4d0 + (ulong)*(ushort *)(lVar2 + 0x30a));
    *puVar1 = local_20 << ((byte)*(undefined2 *)(lVar2 + 0x308) & 0x1f) |
              *puVar1 & *(uint *)(lVar2 + 0x304);
    puVar1 = (uint *)(lVar2 + 0x4e0 + (ulong)*(ushort *)(lVar2 + 0x22));
    *puVar1 = (uint)*(byte *)(*(long *)(lVar2 + 0x28) + 1) <<
              ((byte)*(undefined2 *)(lVar2 + 0x20) & 0x1f) | *(uint *)(lVar2 + 0x1c) & *puVar1;
    puVar1 = (uint *)(lVar2 + 0x4e0 + (ulong)*(ushort *)(lVar2 + 0x10a));
    *puVar1 = *(uint *)(lVar2 + 0x104) & *puVar1 |
              local_20 << ((byte)*(undefined2 *)(lVar2 + 0x108) & 0x1f);
    puVar1 = (uint *)(lVar2 + 0x4e0 + (ulong)*(ushort *)(lVar2 + 0x122));
    *puVar1 = (uint)*(byte *)(*(long *)(lVar2 + 0x128) + 1) <<
              ((byte)*(undefined2 *)(lVar2 + 0x120) & 0x1f) | *puVar1 & *(uint *)(lVar2 + 0x11c);
    puVar1 = (uint *)(lVar2 + 0x4f0 + (ulong)*(ushort *)(lVar2 + 0x31e));
    *puVar1 = (uint)*(byte *)(lVar2 + 800) << ((byte)*(undefined2 *)(lVar2 + 0x31c) & 0x1f) |
              *puVar1 & *(uint *)(lVar2 + 0x318);
    iVar3 = (**(code **)(param_2 + 0x280))(param_2,2,&local_1c);
    if (iVar3 == 0) {
      puVar1 = (uint *)(lVar2 + 0x4f0 + (ulong)*(ushort *)(lVar2 + 0x4ba));
      *puVar1 = local_1c << ((byte)*(undefined2 *)(lVar2 + 0x4b8) & 0x1f) |
                *puVar1 & *(uint *)(lVar2 + 0x4b4);
      puVar1 = (uint *)(lVar2 + 0x4c0 + (ulong)*(ushort *)(lVar2 + 0x31e));
      *puVar1 = (uint)*(byte *)(lVar2 + 800) << ((byte)*(undefined2 *)(lVar2 + 0x31c) & 0x1f) |
                *puVar1 & *(uint *)(lVar2 + 0x318);
      uVar4 = (**(code **)(param_2 + 0x280))(param_2,4,&local_1c);
      if ((int)uVar4 == 0) {
        puVar1 = (uint *)(lVar2 + 0x4c0 + (ulong)*(ushort *)(lVar2 + 0x4ba));
        *puVar1 = local_1c << ((byte)*(undefined2 *)(lVar2 + 0x4b8) & 0x1f) |
                  *puVar1 & *(uint *)(lVar2 + 0x4b4);
        return uVar4;
      }
      nvAssertFailedNoLog("(kgmmuTranslatePtePcfFromSw_HAL(pKernelGmmu, ptePcfSw, &ptePcfHw) == NV_OK)"
                          ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x61);
    }
    else {
      nvAssertFailedNoLog("(kgmmuTranslatePtePcfFromSw_HAL(pKernelGmmu, ptePcfSw, &ptePcfHw) == NV_OK)"
                          ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x5a);
    }
  }
  else {
    nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromSw_HAL(pKernelGmmu, pdePcfSw, &pdePcfHw) == NV_OK)"
                        ,"src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0x44);
  }
  return 0x1f;
}


// ===== 003faa20 kgmmuTranslatePtePcfFromSw_GH100 =====

undefined8 kgmmuTranslatePtePcfFromSw_GH100(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  if (param_2 == 0x110) {
LAB_003fac20:
    *param_3 = 0;
    return 0;
  }
  if (param_2 < 0x111) {
    if (param_2 != 0x30) {
      if (0x30 < param_2) {
        if (param_2 == 0xd0) {
          *param_3 = 0xe;
          return 0;
        }
        if (param_2 < 0xd1) {
          if (param_2 == 0x70) {
            *param_3 = 0xb;
            return 0;
          }
          if (param_2 == 0xb0) {
            *param_3 = 7;
            return 0;
          }
          if (param_2 == 0x50) {
            *param_3 = 10;
            return 0;
          }
        }
        else {
          if (param_2 == 0xf0) {
            *param_3 = 0xf;
            return 0;
          }
          if (param_2 == 0x100) {
            *param_3 = 0x10;
            return 0;
          }
        }
        goto LAB_003faa6b;
      }
      if (param_2 == 4) goto LAB_003fac30;
      if (4 < param_2) {
        if (param_2 != 0x10) {
          if (param_2 == 0x20) {
            *param_3 = 0x13;
            return 0;
          }
          if (param_2 != 8) goto LAB_003faa6b;
        }
        *param_3 = 2;
        return 0;
      }
      if (param_2 == 1) goto LAB_003fac20;
      if (param_2 != 2) {
        if (param_2 == 0) {
          *param_3 = 0x12;
          return 0;
        }
        goto LAB_003faa6b;
      }
    }
    *param_3 = 3;
  }
  else {
    if (param_2 == 400) {
      *param_3 = 4;
      return 0;
    }
    if (400 < param_2) {
      if (param_2 == 0x1d0) {
        *param_3 = 0xc;
        return 0;
      }
      if (param_2 < 0x1d1) {
        if (param_2 == 0x1b0) {
          *param_3 = 5;
          return 0;
        }
        if (param_2 == 0x1c0) {
          *param_3 = 0x1c;
          return 0;
        }
        if (param_2 == 0x1a0) {
          *param_3 = 0x15;
          return 0;
        }
      }
      else {
        if (param_2 == 0x1e0) {
          *param_3 = 0x1d;
          return 0;
        }
        if (param_2 == 0x1f0) {
          *param_3 = 0xd;
          return 0;
        }
      }
LAB_003faa6b:
      nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0xab,
                   "kgmmuTranslatePtePcfFromSw_GH100",4,
                   "NVRM: Unsupported SW PTE PCF pattern requested : %x\n",param_2);
      return 0x56;
    }
    if (param_2 == 0x150) {
      *param_3 = 8;
      return 0;
    }
    if (0x150 < param_2) {
      if (param_2 == 0x170) {
        *param_3 = 9;
        return 0;
      }
      if (param_2 == 0x180) {
        *param_3 = 0x14;
        return 0;
      }
      if (param_2 == 0x160) {
        *param_3 = 0x19;
        return 0;
      }
      goto LAB_003faa6b;
    }
    if (param_2 != 0x130) {
      if (param_2 == 0x140) {
        *param_3 = 0x18;
        return 0;
      }
      if (param_2 == 0x120) {
        *param_3 = 0x11;
        return 0;
      }
      goto LAB_003faa6b;
    }
LAB_003fac30:
    *param_3 = 1;
  }
  return 0;
}


// ===== 003fad20 kgmmuTranslatePtePcfFromHw_GH100 =====

undefined8
kgmmuTranslatePtePcfFromHw_GH100(undefined8 param_1,uint param_2,char param_3,int *param_4)

{
  int iVar1;
  
  if (param_3 == '\0') {
    if (param_2 == 2) {
      *param_4 = 8;
      return 0;
    }
    if (2 < param_2) {
      if (param_2 == 3) {
        *param_4 = 2;
        return 0;
      }
      return 0x56;
    }
    if (param_2 == 0) {
      *param_4 = 1;
      return 0;
    }
    *param_4 = 4;
  }
  else if (param_2 == 0xd) {
    *param_4 = 0x1f0;
  }
  else if (param_2 < 0xe) {
    if (param_2 == 7) {
      *param_4 = 0xb0;
    }
    else if (param_2 < 8) {
      if (param_2 == 3) {
        *param_4 = 0x30;
      }
      else if (param_2 < 4) {
        if (param_2 == 1) {
          *param_4 = 0x130;
        }
        else {
          iVar1 = 0x10;
          if (param_2 != 2) {
            iVar1 = 0x110;
          }
          *param_4 = iVar1;
        }
      }
      else if (param_2 == 4) {
        *param_4 = 400;
      }
      else {
        if (param_2 != 5) goto LAB_003faee0;
        *param_4 = 0x1b0;
      }
    }
    else if (param_2 == 10) {
      *param_4 = 0x50;
    }
    else if (param_2 < 0xb) {
      iVar1 = 0x150;
      if (param_2 != 8) {
        iVar1 = 0x170;
      }
      *param_4 = iVar1;
    }
    else {
      iVar1 = 0x70;
      if (param_2 != 0xb) {
        iVar1 = 0x1d0;
      }
      *param_4 = iVar1;
    }
  }
  else if (param_2 == 0x14) {
    *param_4 = 0x180;
  }
  else if (param_2 < 0x15) {
    if (param_2 == 0x11) {
      *param_4 = 0x120;
    }
    else if (param_2 < 0x12) {
      if (param_2 == 0xf) {
        *param_4 = 0xf0;
      }
      else {
        iVar1 = 0x100;
        if (param_2 != 0x10) {
          iVar1 = 0xd0;
        }
        *param_4 = iVar1;
      }
    }
    else {
      *param_4 = (uint)(param_2 != 0x12) << 5;
    }
  }
  else if (param_2 == 0x19) {
    *param_4 = 0x160;
  }
  else if (param_2 < 0x1a) {
    if (param_2 == 0x15) {
      *param_4 = 0x1a0;
    }
    else {
      if (param_2 != 0x18) goto LAB_003faee0;
      *param_4 = 0x140;
    }
  }
  else if (param_2 == 0x1c) {
    *param_4 = 0x1c0;
  }
  else {
    if (param_2 != 0x1d) {
LAB_003faee0:
      nvDbg_Printf("src/kernel/gpu/mmu/arch/hopper/kern_gmmu_gh100.c",0xcd,
                   "kgmmuTranslatePtePcfFromHw_GH100",4,
                   "NVRM: Unsupported HW PTE PCF pattern requested : %x\n",param_2);
      return 0x56;
    }
    *param_4 = 0x1e0;
  }
  return 0;
}


