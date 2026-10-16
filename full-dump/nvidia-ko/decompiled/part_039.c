// ===== 0043d260 tmrGetCurrentTime_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 tmrGetCurrentTime_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if ((((lVar1 == 0) || (*(char *)(lVar1 + 0x44f) != '\0')) || (*(char *)(lVar1 + 0x450) != '\0'))
     || ((*(char *)(lVar1 + 0x451) != '\0' || (*(char *)(lVar1 + 0x461) != '\0')))) {
    uVar2 = 0x10;
  }
  else {
    if (*(char *)(lVar1 + 0x44c) != '\0') {
      uVar2 = (**(code **)(param_1 + 0x1b0))(lVar1,param_1,0,*(code **)(param_1 + 0x1b0));
      *param_2 = uVar2;
      return 0;
    }
    uVar2 = 0xf;
  }
  *param_2 = 0xffffffffffffffff;
  return uVar2;
}


// ===== 0043d310 tmrEventOnList_IMPL =====

undefined8 tmrEventOnList_IMPL(long param_1,long param_2)

{
  long lVar1;
  
  if ((param_2 == 0) ||
     ((*(char *)(param_1 + 0x21a) == '\0' && ((*(byte *)(param_2 + 0x18) & 8) == 0)))) {
    lVar1 = *(long *)(param_1 + 0x220);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x228);
  }
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if (param_2 == lVar1) break;
    lVar1 = *(long *)(lVar1 + 0x48);
  }
  if (*(char *)(param_2 + 0x30) != '\0') {
    return 1;
  }
  nvAssertFailedNoLog("pEvent->bInUse","src/kernel/gpu/timer/timer.c",0x2d3);
  return 1;
}


// ===== 0043d3a0 _tmrInsertCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 _tmrInsertCallback(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x160);
  }
  uVar3 = gpuEngineGetGpu(uVar3);
  if ((*(char *)(param_2 + 0x30) != '\0') ||
     (cVar2 = tmrEventOnList_IMPL(param_1,param_2), cVar2 != '\0')) {
    nvAssertFailedNoLog("!\"Invalid call to insert, already in use\"","src/kernel/gpu/timer/timer.c"
                        ,0x330);
    return 0x1f;
  }
  *(undefined8 *)(param_2 + 0x38) = param_3;
  if (*(char *)(param_2 + 0x30) != '\0') {
    nvAssertFailedNoLog("!pEvent->bInUse","src/kernel/gpu/timer/timer.c",0x34b);
  }
  *(undefined1 *)(param_2 + 0x30) = 1;
  if ((*(char *)(param_1 + 0x21a) == '\0') && ((*(uint *)(param_2 + 0x18) & 8) == 0)) {
    lVar1 = *(long *)(param_1 + 0x220);
    if (lVar1 == 0) {
      if ((*(char *)(param_1 + 0x218) != '\0') &&
         ((**(code **)(param_1 + 0x1e8))(uVar3,param_1,0), *(char *)(param_1 + 0x218) != '\0')) {
        (**(code **)(param_1 + 0x1e0))(uVar3,param_1);
      }
    }
    else if (*(ulong *)(lVar1 + 0x38) < *(ulong *)(param_2 + 0x38)) {
      do {
        lVar4 = lVar1;
        lVar1 = *(long *)(lVar4 + 0x48);
        if (lVar1 == 0) {
          *(undefined8 *)(param_2 + 0x48) = 0;
          *(long *)(lVar4 + 0x48) = param_2;
          return 0;
        }
      } while (*(ulong *)(lVar1 + 0x38) < *(ulong *)(param_2 + 0x38));
      *(long *)(param_2 + 0x48) = lVar1;
      *(long *)(lVar4 + 0x48) = param_2;
      return 0;
    }
    *(long *)(param_2 + 0x48) = lVar1;
    *(long *)(param_1 + 0x220) = param_2;
    _tmrScheduleCallbackInterrupt(uVar3,param_1,*(undefined8 *)(param_2 + 0x38));
    return 0;
  }
  *(undefined8 *)(param_2 + 0x48) = *(undefined8 *)(param_1 + 0x228);
  *(long *)(param_1 + 0x228) = param_2;
  return 0;
}


// ===== 0043d550 tmrEventScheduleAbs_IMPL =====

undefined8 tmrEventScheduleAbs_IMPL(long param_1,long *param_2,ulong param_3)

{
  undefined8 uVar1;
  long lVar2;
  ulong local_20;
  
  if (param_2 != (long *)0x0) {
    if ((*(char *)(param_1 + 0x21a) != '\0') || ((*(byte *)(param_2 + 3) & 8) != 0)) {
      uVar1 = tmrGetCurrentTimeEx_IMPL(param_1,&local_20,0);
      if ((int)uVar1 == 0) {
        lVar2 = param_3 - local_20;
        if (param_3 <= local_20) {
          lVar2 = 0;
        }
        uVar1 = tmrEventScheduleRel_IMPL(param_1,param_2,lVar2);
        return uVar1;
      }
      return uVar1;
    }
    if ((*param_2 != 0) || (param_2[5] != 0)) {
      uVar1 = _tmrInsertCallback(param_1,param_2,param_3);
      return uVar1;
    }
  }
  nvAssertFailedNoLog("Attempting to schedule callback with NULL procedure.  Please update Bug 372159 with appropriate information."
                      ,"src/kernel/gpu/timer/timer.c",0x3c0);
  return 0x1f;
}


// ===== 0043d620 tmrEventScheduleRel_IMPL =====

ulong tmrEventScheduleRel_IMPL(long param_1,long param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong local_30;
  
  if ((param_2 == 0) ||
     ((*(char *)(param_1 + 0x21a) == '\0' && ((*(byte *)(param_2 + 0x18) & 8) == 0)))) {
    uVar2 = tmrGetCurrentTimeEx_IMPL(param_1,&local_30,0);
    uVar3 = (ulong)uVar2;
    if (uVar2 == 0) {
      if (!CARRY8(param_3,local_30)) {
        uVar3 = tmrEventScheduleAbs_IMPL(param_1,param_2,param_3 + local_30);
        return uVar3;
      }
      uVar3 = 0x1f;
      nvCheckFailedNoLog(4,"portSafeAddU64(currentTime, RelTime, &AbsTime)",
                         "src/kernel/gpu/timer/timer.c",0x289);
    }
  }
  else {
    uVar2 = tmrEventScheduleRelOSTimer_OSTIMER(param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    if (uVar2 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar2,"tmrEventScheduleRelOSTimer_HAL(pTmr, pEvent, RelTime)",
                 "src/kernel/gpu/timer/timer.c",0x277);
    }
    uVar4 = osGetMonotonicTimeNs();
    *(undefined8 *)(param_2 + 0x40) = uVar4;
    cVar1 = tmrEventOnList_IMPL(param_1,param_2);
    if (cVar1 == '\0') {
      _tmrInsertCallback(param_1,param_2,param_3);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 0043d740 tmrapiCtrlCmdTmrSetAlarmNotify_IMPL =====

undefined8 tmrapiCtrlCmdTmrSetAlarmNotify_IMPL(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long local_30 [2];
  
  local_30[0] = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(lVar1 + 0x1b88);
  lVar2 = inotifyGetNotificationList_IMPL(*(undefined8 *)(param_1 + 0x160));
  if (lVar2 != 0) {
    do {
      if (*(int *)(lVar2 + 4) == *param_2) {
        lVar5 = *(long *)(lVar2 + 0x38);
        if (*(long *)(lVar2 + 0x38) == 0) {
          uVar4 = tmrEventCreate_IMPL(uVar3,local_30,_nv0004CtrlCmdTmrSetAlarmNotifyCallback,lVar2,0
                                     );
          if ((int)uVar4 != 0) {
            return uVar4;
          }
          *(long *)(lVar2 + 0x30) = lVar1;
          *(long *)(lVar2 + 0x38) = local_30[0];
          lVar5 = local_30[0];
        }
        uVar3 = tmrEventScheduleRel_IMPL(uVar3,lVar5,*(undefined8 *)(param_2 + 2));
        return uVar3;
      }
      lVar2 = *(long *)(lVar2 + 0x40);
    } while (lVar2 != 0);
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer.c",0x203,"tmrapiCtrlCmdTmrSetAlarmNotify_IMPL",1,
               "NVRM: timer event is missing\n");
  return 0x1f;
}


// ===== 0043d830 tmrCallExpiredCallbacks_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrCallExpiredCallbacks_IMPL(undefined8 param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong local_30;
  
  local_30 = 0;
  if (param_2 != 0) {
    uVar4 = 0;
    puVar3 = *(undefined8 **)(param_2 + 0x220);
    if (puVar3 != (undefined8 *)0x0) {
      do {
        uVar1 = puVar3[7];
        if (local_30 < uVar1) {
          iVar2 = tmrGetCurrentTimeEx_IMPL(param_2,&local_30,0);
          if (iVar2 != 0) {
            return uVar4;
          }
          if (local_30 < uVar1) {
            _tmrScheduleCallbackInterrupt(param_1,param_2,uVar1);
            return uVar4;
          }
          puVar3 = *(undefined8 **)(param_2 + 0x220);
        }
        if (puVar3 == (undefined8 *)0x0) {
          nvAssertFailedNoLog("Attempting to execute callback with NULL timer event.",
                              "src/kernel/gpu/timer/timer.c",0x516);
          puVar3 = *(undefined8 **)(param_2 + 0x220);
        }
        else {
          *(undefined8 *)(param_2 + 0x220) = puVar3[9];
          *(undefined1 *)(puVar3 + 6) = 0;
          if (*(char *)(puVar3 + 4) == '\0') {
LAB_0043d880:
            if ((code *)*puVar3 != (code *)0x0) {
              (*(code *)*puVar3)(param_1,param_2);
              goto LAB_0043d897;
            }
LAB_0043d990:
            nvAssertFailedNoLog("Attempting to execute callback with NULL procedure.",
                                "src/kernel/gpu/timer/timer.c",0x511);
          }
          else {
            puVar3[9] = *(undefined8 *)(param_2 + 0x230);
            *(undefined8 **)(param_2 + 0x230) = puVar3;
            if (*(char *)(puVar3 + 4) == '\0') goto LAB_0043d880;
            if ((code *)puVar3[5] == (code *)0x0) goto LAB_0043d990;
            (*(code *)puVar3[5])(param_1,param_2,puVar3[1]);
LAB_0043d897:
            uVar4 = 1;
          }
          puVar3 = *(undefined8 **)(param_2 + 0x220);
        }
        if (puVar3 == (undefined8 *)0x0) {
          return uVar4;
        }
      } while( true );
    }
  }
  return 0;
}


// ===== 0043d9e0 tmrRmCallbackIntrEnable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrRmCallbackIntrEnable_IMPL(long param_1,undefined8 param_2)

{
  if (*(char *)(param_1 + 0x218) == '\0') {
    return;
  }
  (**(code **)(param_1 + 0x1e8))(param_2,param_1,0);
  if (*(char *)(param_1 + 0x218) != '\0') {
    (**(code **)(param_1 + 0x1e0))(param_2);
    return;
  }
  return;
}


// ===== 0043da40 tmrRmCallbackIntrDisable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void tmrRmCallbackIntrDisable_IMPL(long param_1,undefined8 param_2)

{
  if (*(char *)(param_1 + 0x218) != '\0') {
    (**(code **)(param_1 + 0x1d8))(param_2,param_1,*(code **)(param_1 + 0x1d8));
    return;
  }
  return;
}


// ===== 0043da70 tmrStatePreInitLocked_IMPL =====

undefined8 tmrStatePreInitLocked_IMPL(void)

{
  return 0;
}


// ===== 0043da80 tmrStateInitLocked_IMPL =====

undefined8 tmrStateInitLocked_IMPL(void)

{
  return 0;
}


// ===== 0043da90 tmrStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrStateLoad_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x228);
  if ((*(long *)(param_2 + 0x220) != 0) && (*(char *)(param_2 + 0x218) != '\0')) {
    (**(code **)(param_2 + 0x1e0))();
  }
  for (; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x48)) {
    uVar2 = osGetMonotonicTimeNs();
    *(undefined8 *)(lVar1 + 0x40) = uVar2;
    tmrEventScheduleRelOSTimer_OSTIMER(param_2,lVar1,*(undefined8 *)(lVar1 + 0x38));
  }
  return 0;
}


// ===== 0043db00 tmrStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrStateUnload_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_2 + 0x228);
  (**(code **)(param_2 + 0x1d8))();
  for (; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x48)) {
    uVar3 = osGetMonotonicTimeNs();
    uVar2 = *(ulong *)(lVar1 + 0x40);
    if ((uVar2 <= uVar3) && (uVar3 - uVar2 < *(ulong *)(lVar1 + 0x38))) {
      *(ulong *)(lVar1 + 0x38) = (uVar2 + *(ulong *)(lVar1 + 0x38)) - uVar3;
    }
    tmrEventCancelOSTimer_OSTIMER(param_2,lVar1);
  }
  return 0;
}


// ===== 0043db80 tmrStateDestroy_IMPL =====

void tmrStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  __nvoc_objDelete(*(undefined8 *)(param_2 + 0x24f0));
  *(undefined8 *)(param_2 + 0x24f0) = 0;
  return;
}


// ===== 0043dbb0 tmrapiConstruct_IMPL =====

undefined8 tmrapiConstruct_IMPL(void)

{
  return 0;
}


// ===== 0043dbc0 tmrapiDestruct_IMPL =====

void tmrapiDestruct_IMPL(void)

{
  return;
}


// ===== 0043dbd0 tmrapiGetRegBaseOffsetAndSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrapiGetRegBaseOffsetAndSize_IMPL
               (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_1c;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  iVar2 = (**(code **)(lVar1 + 0x200))(lVar1,2,&local_1c);
  if (iVar2 == 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_1c;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x414;
    }
  }
  return;
}


// ===== 0043dc30 tmrapiDeregisterEvents_IMPL =====

void tmrapiDeregisterEvents_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b88);
  for (lVar2 = inotifyGetNotificationList_IMPL(*(undefined8 *)(param_1 + 0x160)); lVar2 != 0;
      lVar2 = *(long *)(lVar2 + 0x40)) {
    if (*(long *)(lVar2 + 0x38) != 0) {
      tmrEventDestroy_IMPL(uVar1);
      *(undefined8 *)(lVar2 + 0x30) = 0;
      *(undefined8 *)(lVar2 + 0x38) = 0;
    }
  }
  return;
}


// ===== 0043dcb0 tmrCtrlCmdEventCreate =====

undefined8 tmrCtrlCmdEventCreate(long param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 local_20;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1b88);
  puVar1 = (undefined8 *)portMemAllocNonPaged(0x10);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = param_2[1];
    puVar1[1] = param_2[2];
    uVar2 = tmrEventCreate_IMPL(uVar2,&local_20,_tmrCallbackWrapperfunction,puVar1,
                                *(undefined4 *)(param_2 + 3));
    *(undefined8 *)*param_2 = local_20;
    return uVar2;
  }
  return 0x51;
}


// ===== 0043dd30 tmrCtrlCmdEventSchedule =====

void tmrCtrlCmdEventSchedule(long param_1,undefined8 *param_2)

{
  if (*(char *)(param_2 + 2) != '\0') {
    tmrEventScheduleAbs_IMPL();
    return;
  }
  tmrEventScheduleRel_IMPL(*(undefined8 *)(param_1 + 0x1b88),*param_2,param_2[1]);
  return;
}


// ===== 0043dd60 tmrCtrlCmdEventCancel =====

undefined8 tmrCtrlCmdEventCancel(long param_1,undefined8 *param_2)

{
  tmrEventCancel_IMPL(*(undefined8 *)(param_1 + 0x1b88),*param_2);
  return 0;
}


// ===== 0043dd80 tmrCtrlCmdEventDestroy =====

undefined8 tmrCtrlCmdEventDestroy(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *param_2;
  uVar2 = *(undefined8 *)(param_1 + 0x1b88);
  portMemFree(*(undefined8 *)(lVar1 + 8));
  tmrEventDestroy_IMPL(uVar2,lVar1);
  return 0;
}


// ===== 0043ddb0 __pfx_tmrEventServiceTimer_IMPL =====

undefined8 __pfx_tmrEventServiceTimer_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((param_3 == 0) ||
     ((*(char *)(param_2 + 0x21a) == '\0' && ((*(byte *)(param_3 + 0x18) & 8) == 0)))) {
    return 0x3f;
  }
  cVar2 = tmrEventOnList_IMPL(param_2,param_3);
  if (cVar2 == '\0') {
    return 0x3f;
  }
  lVar1 = *(long *)(param_2 + 0x228);
  if (param_3 == *(long *)(param_2 + 0x228)) {
    *(undefined8 *)(param_2 + 0x228) = *(undefined8 *)(param_3 + 0x48);
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined1 *)(param_3 + 0x30) = 0;
  }
  else {
    do {
      lVar3 = lVar1;
      if (lVar3 == 0) goto LAB_0043de51;
      lVar1 = *(long *)(lVar3 + 0x48);
    } while (param_3 != *(long *)(lVar3 + 0x48));
    *(undefined8 *)(lVar3 + 0x48) = *(undefined8 *)(param_3 + 0x48);
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined1 *)(param_3 + 0x30) = 0;
  }
LAB_0043de51:
  uVar4 = tmrEventServiceOSTimerCallback_OSTIMER(param_1,param_2);
  return uVar4;
}


// ===== 0043ddc0 tmrEventServiceTimer_IMPL =====

undefined8 tmrEventServiceTimer_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((param_3 == 0) ||
     ((*(char *)(param_2 + 0x21a) == '\0' && ((*(byte *)(param_3 + 0x18) & 8) == 0)))) {
    return 0x3f;
  }
  cVar2 = tmrEventOnList_IMPL(param_2,param_3);
  if (cVar2 == '\0') {
    return 0x3f;
  }
  lVar1 = *(long *)(param_2 + 0x228);
  if (param_3 == *(long *)(param_2 + 0x228)) {
    *(undefined8 *)(param_2 + 0x228) = *(undefined8 *)(param_3 + 0x48);
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined1 *)(param_3 + 0x30) = 0;
  }
  else {
    do {
      lVar3 = lVar1;
      if (lVar3 == 0) goto LAB_0043de51;
      lVar1 = *(long *)(lVar3 + 0x48);
    } while (param_3 != *(long *)(lVar3 + 0x48));
    *(undefined8 *)(lVar3 + 0x48) = *(undefined8 *)(param_3 + 0x48);
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined1 *)(param_3 + 0x30) = 0;
  }
LAB_0043de51:
  uVar4 = tmrEventServiceOSTimerCallback_OSTIMER(param_1,param_2);
  return uVar4;
}


// ===== 0043dea0 tmrRegisterIntrService_IMPL =====

void tmrRegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x18) != 0) {
    nvAssertFailedNoLog("pRecords[MC_ENGINE_IDX_TMR].pInterruptService == NULL",
                        "src/kernel/gpu/timer/timer.c",0x7a7);
  }
  if (param_2 == 0) {
    *(undefined8 *)(param_3 + 0x18) = 0;
    uVar1 = 0;
    if (*(long *)(param_3 + 0xf60) != 0) {
      nvAssertFailedNoLog("pRecords[MC_ENGINE_IDX_TMR_SWRL].pInterruptService == NULL",
                          "src/kernel/gpu/timer/timer.c",0x7ab);
      uVar1 = 0;
    }
  }
  else {
    *(undefined8 *)(param_3 + 0x18) = *(undefined8 *)(param_2 + 0x170);
    if (*(long *)(param_3 + 0xf60) != 0) {
      nvAssertFailedNoLog("pRecords[MC_ENGINE_IDX_TMR_SWRL].pInterruptService == NULL",
                          "src/kernel/gpu/timer/timer.c",0x7ab);
    }
    uVar1 = *(undefined8 *)(param_2 + 0x170);
  }
  *(undefined8 *)(param_3 + 0xf60) = uVar1;
  return;
}


// ===== 0043df80 tmrClearInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrClearInterrupt_IMPL(long param_1,undefined8 param_2,short *param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  if (param_3 == (short *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/timer/timer.c",0x7be);
  }
  else {
    if (*param_3 == 1) {
      lVar1 = *(long *)(param_1 + 0x1c20);
      uVar2 = intrGetVectorFromEngineId_IMPL(param_1,lVar1,1,0);
      (**(code **)(lVar1 + 0x1d0))(param_1,lVar1,uVar2,0);
      return 1;
    }
    if (*param_3 != 0xa4) {
      nvAssertFailedNoLog("invalid EngineIdx","src/kernel/gpu/timer/timer.c",0x7ce);
    }
  }
  return 0;
}


// ===== 0043e020 tmrGetTimeEx_OSTIMER =====

long tmrGetTimeEx_OSTIMER(void)

{
  uint local_10;
  uint local_c;
  
  osGetSystemTime(&local_10,&local_c);
  return ((ulong)local_10 * 1000000 + (ulong)local_c) * 1000;
}


// ===== 0043e060 tmrEventCreateOSTimer_OSTIMER =====

int tmrEventCreateOSTimer_OSTIMER(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  iVar1 = osCreateNanoTimer(*(undefined8 *)(lVar2 + 0x4e0),param_2,param_2 + 0x10);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined8 *)(param_2 + 0x10) = 0;
  nvDbg_Printf("src/kernel/gpu/timer/timer_ostimer.c",0x58,"tmrEventCreateOSTimer_OSTIMER",4,
               "NVRM: OS create timer failed\n");
  return iVar1;
}


// ===== 0043e0f0 tmrEventScheduleRelOSTimer_OSTIMER =====

int tmrEventScheduleRelOSTimer_OSTIMER(long param_1,long param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar2 = gpuEngineGetGpu(uVar4);
  if (*(long *)(param_2 + 0x10) != 0) {
    lVar3 = 1;
    if (param_3 != 0) {
      lVar3 = param_3;
    }
    iVar1 = osStartNanoTimer(*(undefined8 *)(lVar2 + 0x4e0),*(long *)(param_2 + 0x10),lVar3);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/timer/timer_ostimer.c",0x7d,"tmrEventScheduleRelOSTimer_OSTIMER",
                   4,"NVRM: OS Start timer FAILED!\n");
    }
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 4;
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer_ostimer.c",0x74,"tmrEventScheduleRelOSTimer_OSTIMER",4,
               "NVRM: OS Timer not created\n");
  return 0x3f;
}


// ===== 0043e1c0 tmrEventServiceOSTimerCallback_OSTIMER =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
tmrEventServiceOSTimerCallback_OSTIMER(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  if ((param_3 != (undefined8 *)0x0) && ((code *)*param_3 != (code *)0x0)) {
    (*(code *)*param_3)();
    *(uint *)(param_3 + 3) = *(uint *)(param_3 + 3) & 0xfffffffb;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer_ostimer.c",0x9e,"tmrEventServiceOSTimerCallback_OSTIMER",
               4,"NVRM: ERROR No Timer event callback found, invalid timer SW state\n");
  return 0x3f;
}


// ===== 0043e220 tmrEventCancelOSTimer_OSTIMER =====

undefined8 tmrEventCancelOSTimer_OSTIMER(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if ((param_2 != 0) && (*(long *)(param_2 + 0x10) != 0)) {
    uVar2 = osCancelNanoTimer(*(undefined8 *)(lVar1 + 0x4e0));
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffffb;
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer_ostimer.c",0xbf,"tmrEventCancelOSTimer_OSTIMER",4,
               "NVRM: ERROR No Timer event callback found, invalid timer SW state\n");
  return 0x3f;
}


// ===== 0043e2a0 tmrEventDestroyOSTimer_OSTIMER =====

undefined8 tmrEventDestroyOSTimer_OSTIMER(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if ((param_2 != 0) && (*(long *)(param_2 + 0x10) != 0)) {
    uVar2 = osDestroyNanoTimer(*(undefined8 *)(lVar1 + 0x4e0));
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffffb;
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer_ostimer.c",0xe1,"tmrEventDestroyOSTimer_OSTIMER",4,
               "NVRM: No Timer event callback found, invalid timer SW state\n");
  return 0x3f;
}


// ===== 0043e320 tmrGetTimeLo_OSTIMER =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrGetTimeLo_OSTIMER(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x1b0))(param_1,param_2,0);
  return;
}


// ===== 0043e340 tmrGetTime_OSTIMER =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrGetTime_OSTIMER(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x1b0))(param_1,param_2,0);
  return;
}


// ===== 0043e360 tmrGetGpuAndCpuTimestampPair_OSTIMER =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
tmrGetGpuAndCpuTimestampPair_OSTIMER
          (undefined8 param_1,long param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,0);
  *param_3 = uVar1;
  uVar1 = rdtsc();
  *param_4 = uVar1;
  return 0;
}


// ===== 0043e3a0 tmrDelay_OSTIMER =====

undefined8 tmrDelay_OSTIMER(undefined8 param_1,uint param_2)

{
  if (50000000 < param_2) {
    osDelay((ulong)param_2 / 1000000);
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  osDelayNs(param_2);
  return 0;
}


// ===== 0043e3f0 tmrDelay_PTIMER =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrDelay_PTIMER(long param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  
  uVar6 = 0;
  uVar9 = (ulong)param_2;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar3 = gpuEngineGetGpu(uVar6);
  if (((lVar3 == 0) || (*(char *)(lVar3 + 0x44c) == '\0')) || (*(char *)(lVar3 + 0x450) != '\0')) {
    return 0xf;
  }
  if (((*(char *)(lVar3 + 0x44f) != '\0') || (*(char *)(lVar3 + 0x451) != '\0')) ||
     (*(char *)(lVar3 + 0x461) != '\0')) {
    return 0x10;
  }
  if (*(char *)(lVar3 + 0x490c) != '\0') {
    nvDbg_Printf("src/kernel/gpu/timer/timer_ptimer.c",0x42,"tmrDelay_PTIMER",4,
                 "NVRM: Entered tmrDelay  - %d\n",uVar9);
  }
  if (*(char *)(lVar3 + 0x490e) == '\0') {
    if (param_2 == 0) {
      return 0;
    }
    if (param_2 < 0x2faf081) goto LAB_0043e4a7;
    nvDbg_Printf("src/kernel/gpu/timer/timer_ptimer.c",0x56,"tmrDelay_PTIMER",4,
                 "NVRM: Too long delay w/o yield, use osDelay instead.\n");
    uVar7 = (param_2 + 999) / 1000;
  }
  else if (param_2 < 0x186a1) {
    if (param_2 == 0) {
      return 0;
    }
LAB_0043e4a7:
    uVar7 = (param_2 + 999) / 1000;
    if (param_2 < 12000) {
      uVar7 = 0;
      iVar1 = (**(code **)(param_1 + 0x198))(lVar3,param_1);
      while (iVar2 = (**(code **)(param_1 + 0x198))(lVar3,param_1), (uint)(iVar2 - iVar1) < param_2)
      {
        if ((param_2 + 999) / 1000 < uVar7 >> 4) {
          nvDbg_Printf("src/kernel/gpu/timer/timer_ptimer.c",0x6f,"tmrDelay_PTIMER",1,
                       "NVRM: PTIMER may be stuck. Already at %d iterations for a delay of %d nsec\n"
                       ,uVar7,uVar9);
        }
        else {
          if (*(char *)(lVar3 + 0x44c) == '\0') {
            return 0xf;
          }
          if (*(char *)(lVar3 + 0x450) != '\0') {
            return 0xf;
          }
          uVar7 = uVar7 + 1;
        }
      }
      goto LAB_0043e6a0;
    }
  }
  else {
    uVar7 = 100;
    uVar9 = 100000;
  }
  lVar4 = (**(code **)(param_1 + 0x1a0))(lVar3,param_1);
  uVar8 = 0;
  while (uVar5 = (**(code **)(param_1 + 0x1a0))(lVar3,param_1), uVar5 < lVar4 + uVar9) {
    if (uVar7 < uVar8 >> 3) {
      nvDbg_Printf("src/kernel/gpu/timer/timer_ptimer.c",0x8e,"tmrDelay_PTIMER",1,
                   "NVRM: PTIMER may be stuck. Already at %d iterations for a delay of %d nsec\n",
                   uVar8,uVar9);
    }
    else {
      if (*(char *)(lVar3 + 0x44c) == '\0') {
        return 0xf;
      }
      if (*(char *)(lVar3 + 0x450) != '\0') {
        return 0xf;
      }
      uVar8 = uVar8 + 1;
    }
    osSpinLoop();
  }
LAB_0043e6a0:
  if (*(char *)(lVar3 + 0x490c) != '\0') {
    nvDbg_Printf("src/kernel/gpu/timer/timer_ptimer.c",0x9f,"tmrDelay_PTIMER",4,
                 "NVRM: Exiting tmrDelay\n");
  }
  return 0;
}


// ===== 0043e750 tmrGetTimerBar0MapInfo_PTIMER =====

undefined8
tmrGetTimerBar0MapInfo_PTIMER
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  *param_3 = 0x9000;
  *param_4 = 0x1000;
  return 0;
}


// ===== 0043e770 accesscntrConstruct_IMPL =====

ulong accesscntrConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  uint *puVar2;
  long lVar3;
  char cVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((*(char *)(lVar1 + 0x908) != '\0') &&
     ((*(char *)(lVar1 + 0x4913) == '\0' || (*(char *)(lVar1 + 0x491e) != '\0')))) {
    return 0x56;
  }
  puVar2 = *(uint **)(param_3 + 0x40);
  lVar3 = *(long *)(lVar1 + 0x1cd8);
  cVar4 = gpuIsClassSupported_IMPL(lVar1,*(undefined4 *)(param_3 + 0xc));
  if (cVar4 == '\0') {
    nvDbg_Printf("src/kernel/gpu/uvm/access_cntr_buffer.c",0x38,"accesscntrConstruct_IMPL",4,
                 "NVRM: class %x not supported\n",*(undefined4 *)(param_3 + 0xc));
    uVar5 = 0x22;
  }
  else {
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pUvm != NULL","src/kernel/gpu/uvm/access_cntr_buffer.c",0x3d);
      return 0x56;
    }
    uVar5 = 0;
    if (puVar2 != (uint *)0x0) {
      uVar5 = (ulong)*puVar2;
    }
    *(uint *)(param_1 + 0x180) = (uint)uVar5;
    if ((uint)uVar5 < *(uint *)(lVar3 + 0x280)) {
      if (*(long *)(*(long *)(lVar3 + 0x278) + uVar5 * 0x18) == 0) {
        uVar5 = uvmInitializeAccessCntrBuffer_IMPL(lVar1,lVar3,param_1);
        if ((int)uVar5 == 0) {
          *(long *)(*(long *)(lVar3 + 0x278) + (ulong)*(uint *)(param_1 + 0x180) * 0x18) = param_1;
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar5 & 0xffffffff,
                     "uvmInitializeAccessCntrBuffer(pGpu, pUvm, pAccessCounterBuffer)",
                     "src/kernel/gpu/uvm/access_cntr_buffer.c",0x48);
          uVar5 = uVar5 & 0xffffffff;
        }
      }
      else {
        nvCheckFailedNoLog(4,
                           "pUvm->pAccessCounterBuffers[pAccessCounterBuffer->accessCounterIndex].pAccessCounterBuffer == NULL"
                           ,"src/kernel/gpu/uvm/access_cntr_buffer.c",0x44);
        uVar5 = 0x40;
      }
    }
    else {
      nvCheckFailedNoLog(4,
                         "pAccessCounterBuffer->accessCounterIndex < pUvm->accessCounterBufferCount"
                         ,"src/kernel/gpu/uvm/access_cntr_buffer.c",0x41);
      uVar5 = 0x1f;
    }
  }
  return uVar5;
}


// ===== 0043e9a0 accesscntrDestruct_IMPL =====

void accesscntrDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  if (*(long *)(*(long *)(lVar2 + 0x278) + (ulong)*(uint *)(param_1 + 0x180) * 0x18) != param_1) {
    nvAssertFailedNoLog("pUvm->pAccessCounterBuffers[pAccessCounterBuffer->accessCounterIndex].pAccessCounterBuffer == pAccessCounterBuffer"
                        ,"src/kernel/gpu/uvm/access_cntr_buffer.c",0x57);
  }
  iVar3 = uvmTerminateAccessCntrBuffer_IMPL(lVar1,lVar2,param_1);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"uvmTerminateAccessCntrBuffer(pGpu, pUvm, pAccessCounterBuffer)",
               "src/kernel/gpu/uvm/access_cntr_buffer.c",0x59);
  }
  *(undefined8 *)(*(long *)(lVar2 + 0x278) + (ulong)*(uint *)(param_1 + 0x180) * 0x18) = 0;
  return;
}


// ===== 0043ea70 accesscntrMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 accesscntrMap_IMPL(long param_1,long param_2,undefined8 param_3,long param_4)

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
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/uvm/access_cntr_buffer.c",0x6e);
    return 0x1f;
  }
  uVar2 = *(undefined4 *)(param_4 + 0x10);
  uVar1 = (**(code **)(*plVar3 + 0xd8))(plVar3);
  uVar5 = rmapiValidateKernelMapping(uVar1,uVar2,&local_29);
  if ((int)uVar5 != 0) {
    return uVar5;
  }
  uVar2 = osGetCurrentProcess();
  *(undefined4 *)(param_4 + 0x48) = uVar2;
  uVar5 = memdescMap(*(long *)(param_1 + 0x178),0,*(undefined8 *)(*(long *)(param_1 + 0x178) + 0x30)
                     ,local_29,*(undefined4 *)(*(long *)(param_4 + 0x50) + 0x20),param_4 + 0x18,
                     *(long *)(param_4 + 0x50) + 0x18);
  return uVar5;
}


// ===== 0043eb80 accesscntrUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int accesscntrUnmap_IMPL(long param_1,long param_2,long param_3)

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
    iVar3 = 0x1f;
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/uvm/access_cntr_buffer.c",0x93);
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 0x10);
    uVar2 = (**(code **)(*plVar4 + 0xd8))(plVar4);
    iVar3 = rmapiValidateKernelMapping(uVar2,uVar1,&local_29);
    if (iVar3 == 0) {
      memdescUnmap(*(undefined8 *)(param_1 + 0x178),local_29,*(undefined8 *)(param_3 + 0x18),
                   *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18));
    }
  }
  return iVar3;
}


// ===== 0043ec60 accesscntrGetMapAddrSpace_IMPL =====

ulong accesscntrGetMapAddrSpace_IMPL
                (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  ulong uVar1;
  undefined4 local_1c [3];
  
  if (*(long *)(param_1 + 0x178) != 0) {
    uVar1 = rmapiGetEffectiveAddrSpace
                      (*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),*(long *)(param_1 + 0x178)
                       ,param_3,local_1c);
    if ((int)uVar1 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = local_1c[0];
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,
                 "rmapiGetEffectiveAddrSpace(pGpu, pMemDesc, mapFlags, &addrSpace)",
                 "src/kernel/gpu/uvm/access_cntr_buffer.c",0xb4);
      uVar1 = uVar1 & 0xffffffff;
    }
    return uVar1;
  }
  return 0x31;
}


// ===== 0043ecf0 accesscntrCtrlCmdAccessCntrBufferReadGet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void accesscntrCtrlCmdAccessCntrBufferReadGet_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  (**(code **)(lVar2 + 0x1b8))(lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),param_2);
  return;
}


// ===== 0043ed30 accesscntrCtrlCmdAccessCntrBufferWriteGet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void accesscntrCtrlCmdAccessCntrBufferWriteGet_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  (**(code **)(lVar2 + 0x1e0))(lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),*param_2);
  return;
}


// ===== 0043ed70 accesscntrCtrlCmdAccessCntrBufferReadPut_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void accesscntrCtrlCmdAccessCntrBufferReadPut_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  (**(code **)(lVar2 + 0x1b0))(lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),param_2);
  return;
}


// ===== 0043edb0 accesscntrCtrlCmdAccessCntrBufferGetSize_IMPL =====

undefined8 accesscntrCtrlCmdAccessCntrBufferGetSize_IMPL(long param_1,undefined4 *param_2)

{
  *param_2 = (int)*(undefined8 *)(*(long *)(param_1 + 0x178) + 0x30);
  return 0;
}


// ===== 0043edd0 accesscntrCtrlCmdAccessCntrBufferEnable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 accesscntrCtrlCmdAccessCntrBufferEnable_IMPL(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  if (*param_2 != 0) {
    if (*(long *)(lVar1 + 0x1b98) == 0) {
      nvCheckFailedNoLog(1,"pKernelGmmu != NULL","src/kernel/gpu/uvm/access_cntr_buffer_ctrl.c",0x6b
                        );
      return 0x56;
    }
    kgmmuAccessCntrChangeIntrOwnership_IMPL(lVar1,*(long *)(lVar1 + 0x1b98),*param_2 == 1);
  }
  if ((char)param_2[1] != '\0') {
    uVar3 = (**(code **)(lVar2 + 0x1e8))(lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),0);
    return uVar3;
  }
  uVar3 = (**(code **)(lVar2 + 0x1f0))(lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),0);
  return uVar3;
}


// ===== 0043eea0 accesscntrCtrlCmdAccessCntrBufferEnableIntr_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void accesscntrCtrlCmdAccessCntrBufferEnableIntr_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  iVar3 = (**(code **)(lVar2 + 0x1f8))(lVar1,lVar2,0);
  *(bool *)param_2 = iVar3 == 0;
  return;
}


// ===== 0043eee0 accesscntrCtrlCmdAccessCntrBufferGetRegisterMappings_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void accesscntrCtrlCmdAccessCntrBufferGetRegisterMappings_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  (**(code **)(lVar2 + 0x208))
            (lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),param_2,param_2 + 8,param_2 + 0x10,
             param_2 + 0x18,param_2 + 0x20,param_2 + 0x28,param_2 + 0x30);
  return;
}


// ===== 0043ef40 accesscntrCtrlCmdAccessCntrBufferGetFullInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void accesscntrCtrlCmdAccessCntrBufferGetFullInfo_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  (**(code **)(lVar2 + 0x1c0))(lVar1,lVar2,*(undefined4 *)(param_1 + 0x180),param_2);
  return;
}


// ===== 0043ef80 accesscntrCtrlCmdAccessCntrSetConfig_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 accesscntrCtrlCmdAccessCntrSetConfig_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  uVar1 = param_2[5];
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1cd8);
  if ((uVar1 & 1) != 0) {
    (**(code **)(lVar3 + 0x1c8))(lVar2,lVar3,*(undefined4 *)(param_1 + 0x180),0,*param_2);
  }
  if ((uVar1 & 2) != 0) {
    (**(code **)(lVar3 + 0x1c8))(lVar2,lVar3,*(undefined4 *)(param_1 + 0x180),1,param_2[1]);
  }
  if ((uVar1 & 4) != 0) {
    (**(code **)(lVar3 + 0x1d8))(lVar2,lVar3,*(undefined4 *)(param_1 + 0x180),0,param_2[2]);
  }
  if ((uVar1 & 8) != 0) {
    (**(code **)(lVar3 + 0x1d8))(lVar2,lVar3,*(undefined4 *)(param_1 + 0x180),1,param_2[3]);
  }
  if ((uVar1 & 0x10) != 0) {
    (**(code **)(lVar3 + 0x1d0))(lVar2,lVar3,*(undefined4 *)(param_1 + 0x180),param_2[4]);
  }
  return 0;
}


// ===== 0043f080 subdeviceCtrlCmdInternalUvmRegisterAccessCntrBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8
subdeviceCtrlCmdInternalUvmRegisterAccessCntrBuffer_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if ((param_2[1] + 0xfff >> 0xc) - 1 < 0x40) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    lVar2 = *(long *)(lVar1 + 0x1cd8);
    pcVar3 = *(code **)(lVar2 + 0x198);
    uVar4 = (*pcVar3)(lVar1,lVar2,*param_2,param_2[1],param_2 + 2,pcVar3);
    return uVar4;
  }
  return 0x1f;
}


// ===== 0043f0d0 subdeviceCtrlCmdInternalUvmUnregisterAccessCntrBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdInternalUvmUnregisterAccessCntrBuffer_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cd8);
  (**(code **)(lVar2 + 400))(lVar1,lVar2,*param_2);
  return;
}


// ===== 0043f100 uvmGetRegOffsetAccessCntrBufferPut_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferPut_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x321800003118;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x27);
  return 0;
}


// ===== 0043f150 uvmGetRegOffsetAccessCntrBufferGet_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferGet_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x321400003114;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x34);
  return 0;
}


// ===== 0043f1a0 uvmGetRegOffsetAccessCntrBufferHi_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferHi_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x320c0000310c;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x41);
  return 0;
}


// ===== 0043f1f0 uvmGetRegOffsetAccessCntrBufferLo_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferLo_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x320800003108;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x4e);
  return 0;
}


// ===== 0043f240 uvmGetRegOffsetAccessCntrBufferConfig_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferConfig_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x320000003100;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x5b);
  return 0;
}


// ===== 0043f290 uvmGetRegOffsetAccessCntrBufferInfo_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferInfo_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x321c0000311c;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x68);
  return 0;
}


// ===== 0043f2e0 uvmGetRegOffsetAccessCntrBufferSize_GB100 =====

undefined4 uvmGetRegOffsetAccessCntrBufferSize_GB100(undefined8 param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0x321000003110;
  if (param_2 < 2) {
    return *(undefined4 *)((long)&local_10 + (ulong)param_2 * 4);
  }
  nvAssertFailedNoLog("accessCounterIndex < NV_ARRAY_ELEMENTS(offsets)",
                      "src/kernel/gpu/uvm/arch/blackwell/uvm_gb100.c",0x75);
  return 0;
}


// ===== 0043f330 uvmGetRegOffsetAccessCntrBufferPut_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferPut_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x3118;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x2b);
  return 0x3118;
}


// ===== 0043f370 uvmGetRegOffsetAccessCntrBufferGet_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferGet_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x3114;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x37);
  return 0x3114;
}


// ===== 0043f3b0 uvmGetRegOffsetAccessCntrBufferHi_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferHi_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x310c;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x43);
  return 0x310c;
}


// ===== 0043f3f0 uvmGetRegOffsetAccessCntrBufferLo_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferLo_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x3108;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x4f);
  return 0x3108;
}


// ===== 0043f430 uvmGetRegOffsetAccessCntrBufferConfig_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferConfig_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x3100;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x5b);
  return 0x3100;
}


// ===== 0043f470 uvmGetRegOffsetAccessCntrBufferInfo_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferInfo_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x311c;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x67);
  return 0x311c;
}


// ===== 0043f4b0 uvmGetRegOffsetAccessCntrBufferSize_TU102 =====

undefined8 uvmGetRegOffsetAccessCntrBufferSize_TU102(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    return 0x3110;
  }
  nvAssertFailedNoLog("accessCounterIndex == 0","src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x73);
  return 0x3110;
}


// ===== 0043f4f0 uvmReadAccessCntrBufferPutPtr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
uvmReadAccessCntrBufferPutPtr_TU102
          (long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 0x240))(param_2,param_3,*(code **)(param_2 + 0x240));
  uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + iVar2,0);
  *param_4 = uVar3;
  return 0;
}


// ===== 0043f550 uvmReadAccessCntrBufferGetPtr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
uvmReadAccessCntrBufferGetPtr_TU102
          (long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 0x248))(param_2,param_3,*(code **)(param_2 + 0x248));
  uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + iVar2,0);
  *param_4 = uVar3;
  return 0;
}


// ===== 0043f5b0 uvmWriteAccessCntrBufferGetPtr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
uvmWriteAccessCntrBufferGetPtr_TU102
          (long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 0x248))(param_2,param_3,*(code **)(param_2 + 0x248));
  regWrite032(param_1 + 0x3a18,0,0,iVar1 + iVar2,param_4,0);
  return 0;
}


// ===== 0043f610 uvmEnableAccessCntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 uvmEnableAccessCntr_TU102(long param_1,long param_2,undefined4 param_3,char param_4)

{
  if ((*(byte *)(*(long *)(param_1 + 0x1b98) + 0x548) & 1) == 0) {
    (**(code **)(param_2 + 0x200))();
  }
  else if (param_4 == '\0') {
    (**(code **)(param_2 + 0x1f8))(param_1,param_2,2);
  }
  (**(code **)(param_2 + 0x228))(param_1,param_2,param_3,1);
  return 0;
}


// ===== 0043f6a0 uvmGetAccessCntrRegisterMappings_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
uvmGetAccessCntrRegisterMappings_TU102
          (long param_1,long param_2,undefined4 param_3,long *param_4,long *param_5,long *param_6,
          long *param_7,long *param_8,long *param_9,int *param_10)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1c20);
  plVar6 = (long *)gpuGetDeviceMapping_IMPL(param_1,0,0);
  lVar3 = *plVar6;
  uVar4 = intrGetVectorFromEngineId_IMPL(param_1,uVar2,0x3c,0);
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar5 = (**(code **)(param_2 + 0x248))(param_2,param_3);
  *param_4 = (ulong)(uint)(iVar5 + iVar1) + lVar3;
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar5 = (**(code **)(param_2 + 0x240))(param_2,param_3);
  *param_5 = (ulong)(uint)(iVar5 + iVar1) + lVar3;
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar5 = (**(code **)(param_2 + 0x268))(param_2,param_3);
  *param_6 = (ulong)(uint)(iVar5 + iVar1) + lVar3;
  iVar1 = (uVar4 >> 5) * 4;
  *param_7 = (ulong)(uint)(iVar1 + 0x1000 + *(int *)(param_1 + 0x3a64)) + lVar3;
  *param_8 = (ulong)(uint)(iVar1 + 0x1200 + *(int *)(param_1 + 0x3a64)) + lVar3;
  *param_9 = (ulong)(uint)(iVar1 + 0x1400 + *(int *)(param_1 + 0x3a64)) + lVar3;
  *param_10 = 1 << ((byte)uVar4 & 0x1f);
  return 0;
}


// ===== 0043f7e0 uvmReadAccessCntrBufferFullPtr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
uvmReadAccessCntrBufferFullPtr_TU102(long param_1,long param_2,undefined4 param_3,byte *param_4)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar3 = (**(code **)(param_2 + 0x268))(param_2,param_3,*(code **)(param_2 + 0x268));
  bVar2 = regRead032(param_1 + 0x3a18,0,0,iVar1 + iVar3,0);
  *param_4 = bVar2 & 1;
  return 0;
}


// ===== 0043f840 uvmAccessCntrSetThreshold_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
uvmAccessCntrSetThreshold_TU102(long param_1,long param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(param_2 + 0x260))(param_2,param_3,*(code **)(param_2 + 0x260));
  uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar1,0);
  regWrite032(param_1 + 0x3a18,0,0,iVar1 + *(int *)(param_1 + 0x3a64),
              param_4 & 0xffff | uVar2 & 0xffff0000,0);
  return 0;
}


// ===== 0043f8d0 uvmGetAccessCounterBufferSize_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int uvmGetAccessCounterBufferSize_TU102(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3a64);
  iVar1 = (**(code **)(param_2 + 0x270))(param_2,param_3,*(code **)(param_2 + 0x270));
  iVar2 = regRead032(param_1 + 0x3a18,0,0,iVar2 + iVar1,0);
  return iVar2 << 5;
}


// ===== 0043f920 uvmAccessCntrSetGranularity_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
uvmAccessCntrSetGranularity_TU102
          (long param_1,long param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(param_2 + 0x260))(param_2,param_3,*(code **)(param_2 + 0x260));
  uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar1,0);
  if (param_4 == 0) {
    if (param_5 == 2) {
      uVar3 = uVar2 & 0xfffcffff | 0x20000;
      goto LAB_0043f99e;
    }
    if (param_5 < 3) {
      uVar3 = uVar2 & 0xfffcffff | 0x10000;
      if (param_5 == 0) {
        uVar3 = uVar2 & 0xfffcffff;
      }
      goto LAB_0043f99e;
    }
    uVar3 = uVar2 | 0x30000;
  }
  else {
    if (param_4 != 1) {
      return 0x1f;
    }
    if (param_5 == 2) {
      uVar3 = uVar2 & 0xfff3ffff | 0x80000;
      goto LAB_0043f99e;
    }
    if (param_5 < 3) {
      uVar3 = uVar2 & 0xfff3ffff | 0x40000;
      if (param_5 == 0) {
        uVar3 = uVar2 & 0xfff3ffff;
      }
      goto LAB_0043f99e;
    }
    uVar3 = uVar2 | 0xc0000;
  }
  if (param_5 != 3) {
    return 0x1f;
  }
LAB_0043f99e:
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar1,uVar3,0);
  return 0;
}


// ===== 0043fa70 uvmProgramWriteAccessCntrBufferAddress_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void uvmProgramWriteAccessCntrBufferAddress_TU102
               (long param_1,long param_2,undefined4 param_3,ulong param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 0x250))(param_2,param_3);
  regWrite032(param_1 + 0x3a18,0,0,iVar1 + iVar2,param_4 >> 0x20,0);
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 600))(param_2,param_3);
  regWrite032(param_1 + 0x3a18,0,0,iVar1 + iVar2,param_4 & 0xffffffff,0);
  return;
}


// ===== 0043fb10 uvmProgramAccessCntrBufferEnabled_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void uvmProgramAccessCntrBufferEnabled_TU102
               (long param_1,long param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(param_2 + 600))(param_2,param_3,*(code **)(param_2 + 600));
  uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + iVar1,0);
  regWrite032(param_1 + 0x3a18,0,0,iVar1 + *(int *)(param_1 + 0x3a64),
              param_4 & 1 | uVar2 & 0xfffffffe,0);
  return;
}


// ===== 0043fba0 uvmIsAccessCntrBufferEnabled_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

uint uvmIsAccessCntrBufferEnabled_TU102(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 600))(param_2,param_3,*(code **)(param_2 + 600));
  uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + iVar2,0);
  return uVar3 & 1;
}


// ===== 0043fbf0 uvmIsAccessCntrBufferPushed_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

uint uvmIsAccessCntrBufferPushed_TU102(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3a64);
  iVar2 = (**(code **)(param_2 + 0x268))(param_2,param_3,*(code **)(param_2 + 0x268));
  uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + iVar2,0);
  return uVar3 >> 1 & 1;
}


// ===== 0043fc40 uvmEnableAccessCntrIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 uvmEnableAccessCntrIntr_TU102(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  if ((param_3 & 0xfffffffd) != 0) {
    return 0;
  }
  lVar1 = *(long *)(param_1 + 0x1c20);
  uVar2 = intrGetVectorFromEngineId_IMPL(param_1,lVar1,0x3c,0);
  (**(code **)(lVar1 + 0x1a8))(param_1,lVar1,uVar2);
  return 0;
}


// ===== 0043fc90 uvmDisableAccessCntrIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 uvmDisableAccessCntrIntr_TU102(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x1c20);
  uVar2 = intrGetVectorFromEngineId_IMPL(param_1,lVar1,0x3c,0);
  (**(code **)(lVar1 + 0x1b0))(param_1,lVar1,uVar2);
  return 0;
}


// ===== 0043fce0 uvmAccessCntrService_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int uvmAccessCntrService_TU102(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  long lVar3;
  undefined1 auVar4 [16];
  int local_40;
  int local_3c [3];
  
  if (*(int *)(param_2 + 0x280) == 0) {
    return 0;
  }
  lVar3 = 0;
  do {
    while( true ) {
      lVar1 = *(long *)(*(long *)(param_2 + 0x278) + lVar3 * 0x18);
      if (lVar1 != 0) break;
LAB_0043fd62:
      lVar3 = lVar3 + 1;
      if (*(uint *)(param_2 + 0x280) <= (uint)lVar3) {
        return 0;
      }
    }
    auVar4 = (**(code **)(**(long **)(lVar1 + 0x160) + 0x18))
                       (*(long **)(lVar1 + 0x160),*(long *)(param_2 + 0x278),param_3);
    param_3 = auVar4._8_8_;
    if (auVar4._0_8_ == (undefined8 *)0x0) goto LAB_0043fd62;
    if (1 < *(uint *)(param_2 + 0x280)) {
      iVar2 = (**(code **)(param_2 + 0x1b8))
                        (param_1,param_2,*(undefined4 *)(lVar1 + 0x180),&local_40);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "uvmReadAccessCntrBufferGetPtr(pGpu, pUvm, pAccessCounterBuffer->accessCounterIndex, &get)"
                   ,"src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x1c3);
        return iVar2;
      }
      iVar2 = (**(code **)(param_2 + 0x1b0))
                        (param_1,param_2,*(undefined4 *)(lVar1 + 0x180),local_3c);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "uvmReadAccessCntrBufferPutPtr(pGpu, pUvm, pAccessCounterBuffer->accessCounterIndex, &put)"
                   ,"src/kernel/gpu/uvm/arch/turing/uvm_tu102.c",0x1c4);
        return iVar2;
      }
      param_3 = extraout_RDX;
      if (local_40 == local_3c[0]) goto LAB_0043fd62;
    }
    iVar2 = notifyEvents(param_1,*auVar4._0_8_,0,0,0,0);
    param_3 = 1;
    if (iVar2 == 0) goto LAB_0043fd62;
    lVar3 = lVar3 + 1;
    nvAssertOkFailedNoLog
              (iVar2,
               "notifyEvents(pGpu, *ppEventNotification, NVC365_NOTIFIERS_ACCESS_COUNTER, 0, 0, NV_OK, NV_OS_WRITE_THEN_AWAKEN)"
               ,"src/kernel/gpu/uvm/arch/turing/uvm_tu102.c");
    param_3 = extraout_RDX_00;
    if (*(uint *)(param_2 + 0x280) <= (uint)lVar3) {
      return 0;
    }
  } while( true );
}


// ===== 0043fe80 uvmSetupAccessCntrBuffer_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong uvmSetupAccessCntrBuffer_GV100(long param_1,long param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_20;
  
  if ((*(char *)(param_1 + 0x909) == '\0') &&
     ((*(char *)(param_1 + 0x908) == '\0' ||
      ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))))) {
    lVar1 = *(long *)(*(long *)(param_2 + 0x278) + 0x10 + (ulong)param_3 * 0x18);
    if (lVar1 != 0) {
      uVar2 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x218))
                        (param_1,*(long *)(&DAT_00001b90 + param_1),lVar1,&local_20,
                         *(undefined8 *)(lVar1 + 0x30),0,0);
      if ((int)uVar2 == 0) {
        *(undefined8 *)(*(long *)(param_2 + 0x278) + 8 + (ulong)param_3 * 0x18) = local_20;
        (**(code **)(param_2 + 0x220))(param_1,param_2,param_3,local_20,*(code **)(param_2 + 0x220))
        ;
        (**(code **)(param_2 + 0x228))(param_1,param_2,param_3,0,*(code **)(param_2 + 0x228));
        uVar2 = uVar2 & 0xffffffff;
      }
      return uVar2;
    }
    return 0x32;
  }
  return 0;
}


// ===== 0043ff80 uvmDisableAccessCntr_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int uvmDisableAccessCntr_GV100(long param_1,long param_2,uint param_3,char param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint local_78;
  uint local_68;
  uint local_64;
  long local_60;
  undefined8 local_58;
  undefined1 local_50 [32];
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  iVar5 = gpuSanityCheckRegisterAccess_IMPL(param_1,0,0);
  if (iVar5 != 0) {
    return iVar5;
  }
  if (param_4 == '\0') {
    cVar4 = (**(code **)(lVar1 + 0x338))(param_1,lVar1);
    param_4 = '\0';
    if (cVar4 != '\0') {
      param_4 = '\x01';
      nvDbg_Printf("src/kernel/gpu/uvm/arch/volta/uvm_gv100.c",0x68,"uvmDisableAccessCntr_GV100",4,
                   "NVRM: Forcing bIsErrorRecovery = NV_TRUE because of WRITE_NACK.\n");
    }
  }
  (**(code **)(param_2 + 0x228))(param_1,param_2,param_3,0);
  timeoutSet(param_1 + 0x1af0,local_50,0,0);
  cVar4 = (**(code **)(param_2 + 0x230))(param_1,param_2,param_3);
  if (cVar4 != '\0') {
    nvDbg_Printf("src/kernel/gpu/uvm/arch/volta/uvm_gv100.c",0xcd,"uvmDisableAccessCntr_GV100",4,
                 "NVRM: Failed disabling notification buffer.\n");
    return 0x65;
  }
  while (cVar4 = (**(code **)(param_2 + 0x238))(param_1,param_2,param_3), cVar4 == '\0') {
    iVar5 = timeoutCheck(param_1 + 0x1af0,local_50,0x7b);
    if (iVar5 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/uvm/arch/volta/uvm_gv100.c",0x7d,"uvmDisableAccessCntr_GV100",4,
                   "NVRM: Timeout waiting for HW to write notification buffer.\n");
      return 0x65;
    }
  }
  if (param_4 != '\0') {
    return 0;
  }
  (**(code **)(param_2 + 0x1b0))(param_1,param_2,param_3,&local_68);
  (**(code **)(param_2 + 0x1b8))(param_1,param_2,param_3,&local_64);
  if (local_64 == local_68) {
    return 0;
  }
  lVar1 = *(long *)(*(long *)(*(long *)(param_2 + 0x278) + (ulong)param_3 * 0x18) + 0x178);
  uVar2 = *(ulong *)(lVar1 + 0x30);
  iVar5 = memdescMap(lVar1,(local_64 >> 7) << 0xc,0x1000,1,3,&local_60,&local_58);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/uvm/arch/volta/uvm_gv100.c",0xa2,"uvmDisableAccessCntr_GV100",4,
                 "NVRM: Failed to map access counter buffer while disabling it: %d\n",iVar5);
    return iVar5;
  }
LAB_00440100:
  do {
    lVar3 = local_60;
    if (local_64 == local_68) {
      (**(code **)(param_2 + 0x1e0))(param_1,param_2,param_3);
      memdescUnmap(lVar1,1,local_60,local_58);
      return 0;
    }
    uVar6 = (local_64 & 0x7f) * 0x20;
    piVar7 = (int *)((ulong)(uVar6 + 0x1c) + local_60);
    iVar5 = *piVar7;
    while (-1 < iVar5) {
      osSchedule();
      iVar5 = *piVar7;
    }
    portMemSet(lVar3 + (ulong)uVar6,0,0x20);
    local_64 = local_64 + 1;
    local_78 = (uint)(uVar2 >> 5);
    if (local_64 == local_78) {
      local_64 = 0;
    }
    else if ((local_64 & 0x7f) != 0) goto LAB_00440100;
    memdescUnmap(lVar1,1,local_60,local_58);
    iVar5 = memdescMap(lVar1,(local_64 >> 7) << 0xc,0x1000,1,3,&local_60,&local_58);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/uvm/arch/volta/uvm_gv100.c",0xbb,"uvmDisableAccessCntr_GV100",4,
                   "NVRM: Failed to map access counter buffer while disabling it: %d\n",iVar5);
      (**(code **)(param_2 + 0x1e0))(param_1,param_2,param_3,local_64);
      return iVar5;
    }
  } while( true );
}


// ===== 00440350 uvmUnloadAccessCntrBuffer_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 uvmUnloadAccessCntrBuffer_GV100(long param_1,long param_2,uint param_3)

{
  long lVar1;
  long lVar2;
  
  if ((*(char *)(param_1 + 0x909) == '\0') &&
     ((*(char *)(param_1 + 0x908) == '\0' ||
      ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))))) {
    lVar1 = *(long *)(&DAT_00001b90 + param_1);
    (**(code **)(param_2 + 0x1f0))();
    lVar2 = (ulong)param_3 * 0x18 + *(long *)(param_2 + 0x278);
    (**(code **)(lVar1 + 0x220))
              (param_1,lVar1,*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 8),0);
    *(undefined8 *)(*(long *)(param_2 + 0x278) + 8 + (ulong)param_3 * 0x18) = 0;
    return 0;
  }
  return 0;
}


// ===== 00440420 uvmDestroyAccessCntrBuffer_GV100 =====

undefined8 uvmDestroyAccessCntrBuffer_GV100(long param_1,long param_2,long param_3)

{
  if (param_2 == 0) {
    return 0x10007;
  }
  if ((*(char *)(param_1 + 0x908) != '\0') &&
     ((*(char *)(param_1 + 0x4913) == '\0' || (*(char *)(param_1 + 0x491e) != '\0')))) {
    return 0;
  }
  memdescFree(*(undefined8 *)(param_3 + 0x178));
  memdescDestroy(*(undefined8 *)(param_3 + 0x178));
  *(undefined8 *)(param_3 + 0x178) = 0;
  return 0;
}


// ===== 00440490 uvmInitAccessCntrBuffer_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int uvmInitAccessCntrBuffer_GV100(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  int local_48;
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_48 = 0;
  lVar2 = *(long *)(param_1 + 0x1b98);
  local_44 = 0;
  if ((*(char *)(param_1 + 0x908) != '\0') &&
     ((*(char *)(param_1 + 0x4913) == '\0' || (*(char *)(param_1 + 0x491e) != '\0')))) {
    return 0;
  }
  uVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,*(undefined4 *)(param_3 + 0x180));
  local_48 = 1;
  local_44 = 0;
  memdescOverrideInstLoc
            (*(uint *)(param_1 + 0x4930) >> 10 & 3,"UVM access counter",&local_48,&local_44);
  iVar4 = memdescCreate(&local_40,param_1,uVar3,0,0,local_48,local_44,4);
  if (iVar4 != 0) {
    return iVar4;
  }
  if ((local_48 == 1) && (*(char *)(lVar2 + 0x510) != '\0')) {
    memdescSetGpuCacheAttrib(local_40,1);
  }
  (**(code **)(lVar1 + 0x388))(param_1,lVar1,local_40,1,1);
  *(undefined4 *)(local_40 + 0x9c) = 0x4d;
  iVar4 = memdescAlloc();
  if (iVar4 == 0) {
    memdescSetName(param_1,local_40,"rm_access_counter_buffer_surface",0);
    iVar4 = memdescMap(local_40,0,*(undefined8 *)(local_40 + 0x30),1,3,&local_38);
    if (iVar4 == 0) {
      portMemSet(local_38,0,*(undefined8 *)(local_40 + 0x30));
      memdescUnmap(local_40,1,local_38,local_30);
      *(long *)(param_3 + 0x178) = local_40;
      return 0;
    }
    memdescFree();
    memdescDestroy(local_40);
    return iVar4;
  }
  memdescDestroy(local_40);
  return iVar4;
}


// ===== 004406f0 uvmAccessCntrSetCounterLimit_GV100 =====

undefined8
uvmAccessCntrSetCounterLimit_GV100
          (long param_1,undefined8 param_2,undefined8 param_3,int param_4,uint param_5)

{
  uint uVar1;
  long local_10;
  
  if (param_4 == 0) {
    if (param_5 == 2) {
      uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
      uVar1 = uVar1 & 0xcfffffff | 0x20000000;
    }
    else if (param_5 < 3) {
      if (param_5 == 0) {
        uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
        uVar1 = uVar1 & 0xcfffffff;
      }
      else {
        uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
        uVar1 = uVar1 & 0xcfffffff | 0x10000000;
      }
    }
    else {
      if (param_5 != 3) {
        return 0x1f;
      }
      uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
      uVar1 = uVar1 | 0x30000000;
    }
  }
  else {
    if (param_4 != 1) {
      return 0x1f;
    }
    if (param_5 == 2) {
      uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
      uVar1 = uVar1 & 0x3fffffff | 0x80000000;
    }
    else if (param_5 < 3) {
      if (param_5 == 0) {
        uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
        uVar1 = uVar1 & 0x3fffffff;
      }
      else {
        uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
        uVar1 = uVar1 & 0x3fffffff | 0x40000000;
      }
    }
    else {
      if (param_5 != 3) {
        return 0x1f;
      }
      uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_00100a00,0);
      uVar1 = uVar1 | 0xc0000000;
    }
  }
  local_10 = param_1 + 0x3a18;
  regWrite032(local_10,0,0,&DAT_00100a00,uVar1,0);
  return 0;
}


// ===== 00440900 _uvmSetupAccessCntrBuffer.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _uvmSetupAccessCntrBuffer_isra_0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong local_220;
  undefined1 local_218 [512];
  
  memset(&local_220,0,0x208);
  lVar1 = *(long *)(param_2 + 0x178);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0x30);
    uVar3 = 2;
    uVar4 = (int)lVar2 + 0xfff;
    if (uVar4 < 0x41000) {
      memdescGetPtePhysAddrs(lVar1,1,0,0x1000,uVar4 >> 0xc,local_218);
      local_220 = (ulong)*(uint *)(param_2 + 0x180) | lVar2 << 0x20;
      uVar3 = (**(code **)(*(long *)(param_1 + 0x290) + 0x38))
                        (*(long *)(param_1 + 0x290),*(undefined4 *)(param_1 + 0x284),
                         *(undefined4 *)(param_1 + 0x288),0x20800a1d,&local_220,0x208);
    }
    return uVar3;
  }
  return 0;
}


// ===== 004409e0 uvmStateInitUnlocked_IMPL =====

undefined4 uvmStateInitUnlocked_IMPL(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = rmapiGetInterface(4);
  *(undefined8 *)(param_2 + 0x290) = uVar2;
  uVar1 = rmapiutilAllocClientAndDeviceHandles(uVar2,param_1,param_2 + 0x284,0,param_2 + 0x288);
  if (*(uint *)(param_2 + 0x280) == 0) {
    *(undefined8 *)(param_2 + 0x278) = 0;
  }
  else {
    lVar3 = portMemAllocNonPaged((ulong)*(uint *)(param_2 + 0x280) * 0x18);
    *(long *)(param_2 + 0x278) = lVar3;
    if (lVar3 != 0) {
      portMemSet(lVar3,0,(ulong)*(uint *)(param_2 + 0x280) * 0x18);
      return uVar1;
    }
    uVar1 = 0x51;
    nvAssertFailedNoLog("pUvm->pAccessCounterBuffers != NULL","src/kernel/gpu/uvm/uvm.c",0x87);
  }
  return uVar1;
}


// ===== 00440aa0 uvmStateDestroy_IMPL =====

void uvmStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  portMemFree(*(undefined8 *)(param_2 + 0x278));
  rmapiutilFreeClientAndDeviceHandles
            (*(undefined8 *)(param_2 + 0x290),param_2 + 0x284,0,param_2 + 0x288);
  return;
}


// ===== 00440ae0 uvmInitializeAccessCntrBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int uvmInitializeAccessCntrBuffer_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(param_2 + 0x180))();
  if (iVar1 == 0) {
    iVar2 = _uvmSetupAccessCntrBuffer_isra_0(param_2,param_3);
    iVar1 = 0;
    if (iVar2 != 0) {
      (**(code **)(param_2 + 0x188))(param_1,param_2,param_3);
      return iVar2;
    }
  }
  return iVar1;
}


// ===== 00440b60 uvmTerminateAccessCntrBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 uvmTerminateAccessCntrBuffer_IMPL(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  undefined4 local_2c [3];
  
  if (*(long *)(param_3 + 0x178) != 0) {
    local_2c[0] = *(undefined4 *)(param_3 + 0x180);
    iVar1 = (**(code **)(*(long *)(param_2 + 0x290) + 0x38))
                      (*(long *)(param_2 + 0x290),*(undefined4 *)(param_2 + 0x284),
                       *(undefined4 *)(param_2 + 0x288),0x20800a1e,local_2c,4);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/uvm/uvm.c",0xd2,"uvmTerminateAccessCntrBuffer_IMPL",4,
                   "NVRM: Unloading UVM Access counters failed (status=0x%08x), proceeding...\n",
                   iVar1);
    }
  }
  iVar1 = (**(code **)(param_2 + 0x188))(param_1,param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/uvm/uvm.c",0xda,"uvmTerminateAccessCntrBuffer_IMPL",4,
               "NVRM: Freeing UVM Access counters failed (status=0x%08x), proceeding...\n",iVar1);
  return 0;
}


// ===== 00440c50 uvmAccessCntrBufferRegister_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int uvmAccessCntrBufferRegister_IMPL
              (long param_1,long param_2,uint param_3,int param_4,undefined8 param_5)

{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40 [2];
  
  local_48 = 1;
  local_44 = 0;
  if (*(long *)(param_2 + 0x278) != 0) {
    memdescOverrideInstLoc
              (*(uint *)(param_1 + 0x4930) >> 10 & 3,"UVM access counter",&local_48,&local_44);
    iVar1 = memdescCreate(local_40,param_1,param_4,0,0,local_48,local_44,0x800104);
    if (iVar1 == 0) {
      memdescFillPages(local_40[0],0,param_5,param_4 + 0xfffU >> 0xc,0x1000);
      *(undefined8 *)(*(long *)(param_2 + 0x278) + 0x10 + (ulong)param_3 * 0x18) = local_40[0];
      iVar1 = (**(code **)(param_2 + 0x1a8))(param_1,param_2,param_3);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/gpu/uvm/uvm.c",0x113,"uvmAccessCntrBufferRegister_IMPL",4,
                     "NVRM: Setup of UVM Access counters failed (status=0x%08x)\n");
        memdescDestroy(local_40[0]);
        *(undefined8 *)(*(long *)(param_2 + 0x278) + 0x10 + (ulong)param_3 * 0x18) = 0;
      }
    }
    return iVar1;
  }
  return 0x40;
}


// ===== 00440db0 uvmAccessCntrBufferUnregister_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 uvmAccessCntrBufferUnregister_IMPL(undefined8 param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (*(long *)(param_2 + 0x278) != 0) {
    iVar1 = (**(code **)(param_2 + 0x1a0))();
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/uvm/uvm.c",0x138,"uvmAccessCntrBufferUnregister_IMPL",4,
                   "NVRM: Unloading UVM Access counters failed (status=0x%08x), proceeding...\n",
                   iVar1);
    }
    memdescDestroy(*(undefined8 *)
                    (*(long *)(param_2 + 0x278) + 0x10 + (param_3 & 0xffffffff) * 0x18));
    *(undefined8 *)(*(long *)(param_2 + 0x278) + 0x10 + (param_3 & 0xffffffff) * 0x18) = 0;
    return 0;
  }
  return 0x40;
}


// ===== 00440e50 uvmRegisterIntrService_IMPL =====

void uvmRegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x5a0) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x170);
    }
    *(undefined8 *)(param_3 + 0x5a0) = uVar1;
    return;
  }
  nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL","src/kernel/gpu/uvm/uvm.c",
                      0x150);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 0x170);
  }
  *(undefined8 *)(param_3 + 0x5a0) = uVar1;
  return;
}


// ===== 00440ed0 uvmServiceInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 uvmServiceInterrupt_IMPL(undefined8 param_1,long param_2,short *param_3)

{
  int iVar1;
  
  if (param_3 != (short *)0x0) {
    if (*param_3 == 0x3c) {
      iVar1 = (**(code **)(param_2 + 0x210))();
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,"uvmAccessCntrService_HAL(pGpu, pUvm)","src/kernel/gpu/uvm/uvm.c",0x165);
      }
    }
    else {
      nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_ACCESS_CNTR",
                          "src/kernel/gpu/uvm/uvm.c",0x163);
    }
    return 0;
  }
  nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/uvm/uvm.c",0x162);
  return 0;
}


// ===== 00440f60 kvidengFromEngDesc_IMPL =====

long kvidengFromEngDesc_IMPL(long param_1,int param_2)

{
  long lVar1;
  
  lVar1 = param_1 + (ulong)*(uint *)(param_1 + 0x39f8) * 8;
  if (*(uint *)(param_1 + 0x39f8) != 0) {
    do {
      if (*(int *)(*(long *)(param_1 + 0x3948) + 0x48) == param_2) {
        return *(long *)(param_1 + 0x3948);
      }
      param_1 = param_1 + 8;
    } while (param_1 != lVar1);
  }
  return 0;
}


// ===== 00440fb0 kvidengIsVideoTraceLogSupported_IMPL =====

bool kvidengIsVideoTraceLogSupported_IMPL(long param_1)

{
  char cVar1;
  char cVar2;
  long lVar3;
  char *pcVar4;
  bool bVar5;
  
  cVar2 = *(char *)(param_1 + 0x490e);
  cVar1 = gpuIsCCFeatureEnabled_IMPL();
  if (*(char *)(param_1 + 0x908) == '\0') {
    bVar5 = cVar2 == '\0' && cVar1 == '\0';
LAB_00440fde:
    cVar2 = hypervisorIsVgxHyper_IMPL();
    if (cVar2 == '\0') {
      if (*(long *)(param_1 + 0x3948) != 0) {
        bVar5 = (bool)(bVar5 & *(int *)(*(long *)(param_1 + 0x3948) + 0x78) != 0);
      }
      pcVar4 = "supported";
      if (bVar5 == false) {
        pcVar4 = "unsupported";
      }
      goto LAB_0044103d;
    }
  }
  else {
    lVar3 = gpuGetStaticInfo(param_1);
    if (((lVar3 != 0) && (*(char *)(lVar3 + 0xa7ac) != '\0')) &&
       (*(char *)(param_1 + 0x4913) != '\0')) {
      bVar5 = (cVar2 == '\0' && cVar1 == '\0') && *(char *)(param_1 + 0x491e) == '\0';
      goto LAB_00440fde;
    }
    hypervisorIsVgxHyper_IMPL();
  }
  bVar5 = false;
  pcVar4 = "unsupported";
LAB_0044103d:
  nvDbg_Printf("src/kernel/gpu/video/kernel_video_engine.c",0x52,
               "kvidengIsVideoTraceLogSupported_IMPL",1,"NVRM: video engine event tracing is %s.\n",
               pcVar4);
  return bVar5;
}


// ===== 00441090 kvidengConstruct_IMPL =====

undefined8 kvidengConstruct_IMPL(long param_1,undefined8 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x48) = param_3;
  *(undefined1 *)(param_1 + 0x80) = 0;
  return 0;
}


// ===== 004410b0 kvidengFreeLogging_KERNEL =====

void kvidengFreeLogging_KERNEL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x58) != 0) {
    memdescUnmapInternal(param_1,*(undefined8 *)(param_2 + 0x50),0);
    *(undefined8 *)(param_2 + 0x58) = 0;
  }
  memdescFree(*(undefined8 *)(param_2 + 0x50));
  memdescDestroy(*(undefined8 *)(param_2 + 0x50));
  *(undefined8 *)(param_2 + 0x50) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x60));
  *(undefined8 *)(param_2 + 0x60) = 0;
  portCryptoPseudoRandomGeneratorDestroy(*(undefined8 *)(param_2 + 0x70));
  *(undefined8 *)(param_2 + 0x70) = 0;
  *(undefined1 *)(param_2 + 0x80) = 0;
  return;
}


// ===== 00441130 kvidengInitLogging_KERNEL =====

int kvidengInitLogging_KERNEL(long param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  
  cVar2 = kvidengIsVideoTraceLogSupported_STATIC_DISPATCH();
  if (cVar2 == '\0') {
    nvCheckFailedNoLog(1,"kvidengIsVideoTraceLogSupported(pGpu)",
                       "src/kernel/gpu/video/kernel_video_engine.c",0x72);
    return 0;
  }
  cVar2 = '\x01';
  uVar1 = *(uint *)(param_2 + 0x78);
  uVar7 = uVar1 >> 4 & 0x7fff000;
  if (*(char *)(param_1 + 0x44d) == '\0') {
    cVar2 = (*(char *)(param_1 + 1099) == '\0') + '\x01';
  }
  iVar3 = memdescCreate(param_2 + 0x50,param_1,uVar7,0,1,cVar2,1);
  if (iVar3 == 0) {
    iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x50));
    if (iVar3 == 0) {
      piVar4 = (int *)memdescMapInternal(param_1,*(undefined8 *)(param_2 + 0x50),0);
      if (piVar4 == (int *)0x0) {
        iVar3 = 0x1a;
        nvAssertFailedNoLog("pTraceBuf != NULL","src/kernel/gpu/video/kernel_video_engine.c",0x96);
      }
      else {
        portMemSet(piVar4,0,uVar7);
        *piVar4 = uVar7 - 0x10;
        piVar4[1] = 0;
        piVar4[2] = 0;
        piVar4[3] = uVar1 >> 0x1f;
        *(int **)(param_2 + 0x58) = piVar4;
        *(byte *)(param_2 + 0x7c) = (byte)(uVar1 >> 0x1f);
        lVar5 = portMemAllocNonPaged(0x1000);
        *(long *)(param_2 + 0x60) = lVar5;
        if (lVar5 != 0) {
          portMemSet(lVar5,0,0x1000);
          uVar6 = osGetMonotonicTimeNs();
          uVar6 = portCryptoPseudoRandomGeneratorCreate(uVar6);
          *(undefined1 *)(param_2 + 0x80) = 1;
          *(undefined8 *)(param_2 + 0x70) = uVar6;
          return 0;
        }
        iVar3 = 0x51;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,"memdescAlloc(pKernelVideoEngine->videoTraceInfo.pTraceBufferEngineMemDesc)",
                 "src/kernel/gpu/video/kernel_video_engine.c",0x8e);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,
               "memdescCreate(&pKernelVideoEngine->videoTraceInfo.pTraceBufferEngineMemDesc, pGpu, eventBufferSize, 0, NV_TRUE, addressSpace, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/video/kernel_video_engine.c",0x82);
  }
  kvidengFreeLogging_KERNEL(param_1,param_2);
  return iVar3;
}


// ===== 00441360 kvidengRingbufferMakeSpace_IMPL =====

undefined8
kvidengRingbufferMakeSpace_IMPL(undefined8 param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_4 == (uint *)0x0) {
    nvAssertFailedNoLog("pTraceBuffer != NULL","src/kernel/gpu/video/kernel_video_engine.c",0xf8);
    return 0x1f;
  }
  uVar1 = param_4[1];
  if (*param_4 < param_3) {
    param_3 = *param_4;
  }
  if (param_4[2] - param_2 < param_3) {
    param_3 = param_4[2] - param_2;
  }
  if (uVar1 != param_2) {
    uVar2 = (ulong)uVar1 + 0x100000000;
    if (param_2 <= uVar1) {
      uVar2 = 0;
    }
    if ((ulong)param_3 + (ulong)param_2 <= uVar2) {
      return 0;
    }
  }
  param_4[1] = param_2 + param_3;
  return 0;
}


// ===== 004413e0 kvidengRingbufferGet_IMPL =====

uint kvidengRingbufferGet_IMPL
               (undefined8 param_1,undefined8 param_2,long param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pDataOut != NULL","src/kernel/gpu/video/kernel_video_engine.c",0x13e);
  }
  else if (param_5 == (uint *)0x0) {
    nvAssertFailedNoLog("pTraceBuffer != NULL","src/kernel/gpu/video/kernel_video_engine.c",0x13f);
  }
  else {
    uVar1 = param_5[2];
    uVar2 = param_5[1];
    uVar3 = *param_5;
    uVar4 = uVar1 - uVar3;
    uVar5 = uVar3;
    if (uVar1 - uVar2 < uVar3) {
      uVar4 = uVar2;
      uVar5 = uVar1 - uVar2;
    }
    if ((param_4 <= uVar5) && (uVar4 != uVar1)) {
      uVar5 = (uint)((ulong)uVar4 % (ulong)uVar3);
      if ((uVar5 < uVar1 % uVar3) || (param_4 <= uVar3 - uVar5)) {
        portMemCopy(param_3,param_4,(long)param_5 + (ulong)uVar4 % (ulong)uVar3 + 0x10,param_4);
        if (param_5[1] != uVar2) {
          return 0;
        }
        param_5[1] = uVar4 + param_4;
      }
      else {
        kvidengRingbufferGet_IMPL(param_1,param_2,param_3);
        kvidengRingbufferGet_IMPL
                  (param_1,param_2,param_3 + (ulong)(uVar3 - uVar5),(param_4 - uVar3) + uVar5,
                   param_5);
      }
      return param_4;
    }
  }
  return 0;
}


// ===== 00441580 kvidengEventbufferGetRecord_IMPL =====

ulong kvidengEventbufferGetRecord_IMPL
                (undefined8 param_1,long param_2,uint *param_3,long param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (*(char *)(param_2 + 0x80) == '\0') {
    return 0;
  }
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pTraceBuffer != NULL","src/kernel/gpu/video/kernel_video_engine.c",0x1ff);
    return 0;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pRecord != NULL","src/kernel/gpu/video/kernel_video_engine.c",0x200);
    return 0;
  }
  if (*(long *)(param_2 + 0x60) == 0) {
    nvAssertFailedNoLog("pKernelVideoEngine->videoTraceInfo.pTraceBufferVariableData != NULL",
                        "src/kernel/gpu/video/kernel_video_engine.c",0x201);
    return 0;
  }
  uVar1 = param_3[1];
  uVar2 = *param_3;
  uVar3 = param_3[2] - uVar1;
  if (uVar2 < param_3[2] - uVar1) {
    uVar3 = uVar2;
  }
  uVar7 = uVar1 + uVar3;
  if (uVar3 < 8) {
LAB_00441702:
    if (uVar1 == uVar7) goto LAB_00441713;
  }
  else {
    uVar7 = uVar1 + 8;
    uVar8 = (uint)*(byte *)((long)param_3 + (ulong)(uVar1 + 3) % (ulong)uVar2 + 0x10) * 0x1000000 +
            (uint)*(byte *)((long)param_3 + (ulong)(uVar1 + 2) % (ulong)uVar2 + 0x10) * 0x10000 +
            (uint)*(byte *)((long)param_3 + (ulong)(uVar1 + 1) % (ulong)uVar2 + 0x10) * 0x100 +
            (uint)*(byte *)((long)param_3 + (ulong)uVar1 % (ulong)uVar2 + 0x10);
    iVar4 = 0;
    uVar6 = (ulong)uVar8;
    uVar5 = CONCAT44((uint)*(byte *)((long)param_3 + (ulong)(uVar1 + 5) % (ulong)uVar2 + 0x10) *
                     0x100 + (uint)*(byte *)((long)param_3 +
                                            (ulong)(uVar1 + 7) % (ulong)uVar2 + 0x10) * 0x1000000 +
                             (uint)*(byte *)((long)param_3 +
                                            (ulong)(uVar1 + 6) % (ulong)uVar2 + 0x10) * 0x10000 +
                     (uint)*(byte *)((long)param_3 + (ulong)(uVar1 + 4) % (ulong)uVar2 + 0x10),uVar8
                    );
    iVar9 = uVar3 - 8;
    if (iVar9 != 0) {
      while( true ) {
        if ((param_6 == (int)uVar6) && (param_5 == (int)(uVar5 >> 0x20))) {
          uVar7 = uVar1 + iVar4;
          if (iVar9 != iVar4) goto LAB_00441702;
          goto LAB_004417d4;
        }
        uVar3 = uVar7 + iVar4;
        iVar4 = iVar4 + 1;
        uVar6 = uVar5 >> 8;
        uVar5 = uVar6 | (ulong)*(byte *)((long)param_3 + (ulong)uVar3 % (ulong)uVar2 + 0x10) << 0x38
        ;
        if (iVar9 == iVar4) break;
        uVar6 = uVar6 & 0xffffffff;
      }
      uVar7 = uVar1 + iVar9;
LAB_004417d4:
      uVar7 = uVar7 + 8;
      goto LAB_00441702;
    }
  }
  kvidengRingbufferMakeSpace_IMPL(param_1,uVar1,uVar7 - uVar1,param_3);
LAB_00441713:
  uVar6 = kvidengRingbufferGet_IMPL(param_1,param_2,param_4,0x40,param_3);
  if ((int)uVar6 == 0x40) {
    if (*(int *)(param_4 + 0x10) != 3) {
      return uVar6;
    }
    if ((*(uint *)(param_4 + 0x1c) < 0x1001) &&
       (iVar4 = kvidengRingbufferGet_IMPL
                          (param_1,param_2,*(undefined8 *)(param_2 + 0x60),*(uint *)(param_4 + 0x1c)
                           ,param_3), *(int *)(param_4 + 0x1c) == iVar4)) {
      return (ulong)(iVar4 + 0x40);
    }
  }
  return 0;
}


// ===== 00441810 kvidengRingbufferGetDataSize_IMPL =====

uint kvidengRingbufferGetDataSize_IMPL(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  
  if (param_2 != (uint *)0x0) {
    uVar1 = param_2[2] - param_2[1];
    if (*param_2 < param_2[2] - param_2[1]) {
      uVar1 = *param_2;
    }
    return uVar1;
  }
  nvAssertFailedNoLog("pTraceBuffer != NULL","src/kernel/gpu/video/kernel_video_engine.c",0x235);
  return 0;
}


// ===== 00441850 _gpudbFindGpuInfoByUuid =====

long _gpudbFindGpuInfoByUuid(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(g_pSys + 0x268) + 0x48;
  lVar2 = listHead_IMPL(lVar3);
  while ((lVar2 != 0 && (iVar1 = portMemCmp(lVar2,param_1,0x10), iVar1 != 0))) {
    lVar2 = listNext_IMPL(lVar3,lVar2);
  }
  return lVar2;
}


// ===== 004418c0 gpudbConstruct_IMPL =====

undefined8 gpudbConstruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x48,uVar1,0x30);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  lVar2 = portSyncMutexCreate(uVar1);
  uVar1 = 0;
  *(long *)(param_1 + 0x70) = lVar2;
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_db.c",0x2f,"gpudbConstruct_IMPL",4,
                 "NVRM: Gpu data base list lock init failed\n");
    listDestroy_IMPL(param_1 + 0x48);
    uVar1 = 0x1a;
  }
  return uVar1;
}


// ===== 00441950 gpudbDestruct_IMPL =====

void gpudbDestruct_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x70) != 0) {
    portSyncMutexDestroy();
    listDestroy_IMPL(param_1 + 0x48);
    return;
  }
  listDestroy_IMPL(param_1 + 0x48);
  return;
}


// ===== 00441990 gpudbRegisterGpu =====

undefined8 gpudbRegisterGpu(undefined8 param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar2 = *(long *)(g_pSys + 0x268);
  portSyncMutexAcquire(*(undefined8 *)(lVar2 + 0x70));
  lVar3 = _gpudbFindGpuInfoByUuid(param_1);
  if (lVar3 == 0) {
    lVar3 = listAppendNew_IMPL(lVar2 + 0x48);
    if (lVar3 == 0) {
      uVar4 = 0x1a;
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_db.c",0x71,"gpudbRegisterGpu",4,
                   "NVRM: Append the list failed\n");
      goto LAB_004419d7;
    }
    portMemCopy(lVar3,0x10,param_1,0x10);
    *(int *)(lVar3 + 0x10) = (int)((ulong)param_3 >> 0x20);
    *(ushort *)(lVar3 + 0x14) = (ushort)param_3 << 8 | (ushort)param_3 >> 8;
    *(undefined2 *)(lVar3 + 0x16) = 0x100;
    *(undefined4 *)(lVar3 + 0x18) = *param_2;
    *(undefined1 *)(lVar3 + 0x1c) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)(lVar3 + 0x1d) = *(undefined1 *)((long)param_2 + 5);
    *(undefined1 *)(lVar3 + 0x1e) = *(undefined1 *)((long)param_2 + 6);
    uVar1 = *(undefined1 *)((long)param_2 + 7);
    *(undefined4 *)(lVar3 + 0x20) = 0;
    *(undefined1 *)(lVar3 + 0x1f) = uVar1;
    *(undefined2 *)(lVar3 + 0x24) = 0xff00;
    *(undefined8 *)(lVar3 + 0x28) = 0;
  }
  else {
    *(undefined1 *)(lVar3 + 0x24) = 0;
  }
  uVar4 = 0;
LAB_004419d7:
  portSyncMutexRelease(*(undefined8 *)(lVar2 + 0x70));
  return uVar4;
}


// ===== 00441ac0 gpudbSetGpuComputePolicyConfig =====

undefined4 gpudbSetGpuComputePolicyConfig(long param_1,int param_2,undefined4 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  if ((param_1 != 0) && (param_3 != (undefined4 *)0x0)) {
    lVar1 = *(long *)(g_pSys + 0x268);
    portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x70));
    lVar3 = _gpudbFindGpuInfoByUuid(param_1);
    if (lVar3 == 0) {
      uVar2 = 0x57;
    }
    else {
      uVar2 = 0x1f;
      if (param_2 == 0) {
        *(undefined4 *)(lVar3 + 0x20) = *param_3;
        uVar2 = 0;
      }
    }
    portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x70));
    return uVar2;
  }
  return 0x1f;
}


// ===== 00441b60 gpudbGetGpuComputePolicyConfigs =====

undefined8 gpudbGetGpuComputePolicyConfigs(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar1 = *(long *)(g_pSys + 0x268);
    portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x70));
    uVar3 = 0x57;
    lVar2 = _gpudbFindGpuInfoByUuid(param_1);
    if (lVar2 != 0) {
      uVar3 = 0;
      portMemCopy(param_2,4,lVar2 + 0x20,4);
    }
    portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x70));
    return uVar3;
  }
  return 0x1f;
}


// ===== 00441c00 gpudbSetShutdownState =====

undefined8 gpudbSetShutdownState(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(g_pSys + 0x268);
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x70));
  lVar2 = _gpudbFindGpuInfoByUuid(param_1);
  if (lVar2 == 0) {
    uVar3 = 0x57;
  }
  else {
    *(undefined1 *)(lVar2 + 0x24) = 1;
    uVar3 = 0;
  }
  portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x70));
  return uVar3;
}


// ===== 00441c60 gpudbSetRusdSettings =====

undefined8 gpudbSetRusdSettings(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(g_pSys + 0x268);
    portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x70));
    lVar2 = _gpudbFindGpuInfoByUuid(param_1);
    if (lVar2 == 0) {
      uVar3 = 0x57;
    }
    else {
      uVar3 = 0;
      *(undefined8 *)(lVar2 + 0x28) = *param_2;
    }
    portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x70));
    return uVar3;
  }
  return 0x1f;
}


// ===== 00441cf0 gpudbGetRusdSettings =====

undefined8 gpudbGetRusdSettings(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(g_pSys + 0x268);
    portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x70));
    lVar2 = _gpudbFindGpuInfoByUuid(param_1);
    if (lVar2 == 0) {
      uVar3 = 0x57;
    }
    else {
      uVar3 = 0;
      *param_2 = *(undefined8 *)(lVar2 + 0x28);
    }
    portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x70));
    return uVar3;
  }
  return 0x1f;
}


// ===== 00441d80 gpugrpCreate_IMPL =====

undefined8 gpugrpCreate_IMPL(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x48) = param_2;
  gpumgrAddDeviceInstanceToGpus(param_2);
  return 0;
}


// ===== 00441da0 gpugrpDestroy_IMPL =====

undefined8 gpugrpDestroy_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_1c;
  
  uVar2 = 0x57;
  local_1c = 0;
  while( true ) {
    lVar1 = gpumgrGetNextGpu(*(undefined4 *)(param_1 + 0x48),&local_1c);
    if (lVar1 == 0) break;
    *(undefined4 *)(lVar1 + 0x7b4) = 0x20;
    uVar2 = 0;
  }
  __nvoc_objDelete(param_1);
  return uVar2;
}


// ===== 00441e00 gpugrpGetGpuMask_IMPL =====

undefined4 gpugrpGetGpuMask_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0x48);
}


// ===== 00441e10 gpugrpSetParentGpu_IMPL =====

void gpugrpSetParentGpu_IMPL(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 200) = param_2;
  return;
}


// ===== 00441e20 gpugrpGetParentGpu_IMPL =====

undefined8 gpugrpGetParentGpu_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 200);
}


// ===== 00441e30 gpugrpCreateGlobalVASpace_IMPL =====

undefined8
gpugrpCreateGlobalVASpace_IMPL
          (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5,
          uint param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (param_7 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("ppGlobalVASpace != NULL","src/kernel/gpu_mgr/gpu_group.c",0xd6);
    return 0x1f;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x48);
  uVar2 = *(undefined8 *)(g_pSys + 0x230);
  *param_7 = 0;
  uVar2 = vmmCreateVaspace_IMPL
                    (uVar2,param_3,0,uVar1,param_4,param_5,0,0,0,param_6 | 0x4000000,param_1 + 0xd0)
  ;
  if ((int)uVar2 == 0) {
    *param_7 = *(undefined8 *)(param_1 + 0xd0);
    return uVar2;
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  return uVar2;
}


// ===== 00441f00 gpugrpDestroyGlobalVASpace_IMPL =====

undefined8 gpugrpDestroyGlobalVASpace_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0xd0) != 0) {
    vmmDestroyVaspace_IMPL(*(undefined8 *)(g_pSys + 0x230));
    *(undefined8 *)(param_1 + 0xd0) = 0;
    return 0;
  }
  return 0;
}


// ===== 00441f50 gpugrpGetGlobalVASpace_IMPL =====

undefined8 gpugrpGetGlobalVASpace_IMPL(long param_1,long *param_2)

{
  if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("ppVASpace != NULL","src/kernel/gpu_mgr/gpu_group.c",0x112);
    return 0x1f;
  }
  if (*(long *)(param_1 + 0xd0) != 0) {
    *param_2 = *(long *)(param_1 + 0xd0);
    return 0;
  }
  *param_2 = 0;
  return 0x57;
}


// ===== 00441fb0 gpugrpGetGpuFromSubDeviceInstance_IMPL =====

byte gpugrpGetGpuFromSubDeviceInstance_IMPL(long param_1,int param_2,long *param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  
  local_2c = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu_mgr/gpu_group.c",0x131);
    return 0x1f;
  }
  *param_3 = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x48);
  iVar2 = gpumgrGetSubDeviceCount(uVar1);
  if (iVar2 == 1) {
    lVar3 = gpumgrGetNextGpu(uVar1,&local_2c);
    *param_3 = lVar3;
  }
  else {
    while (lVar3 = gpumgrGetNextGpu(uVar1,&local_2c), lVar3 != 0) {
      iVar2 = gpumgrGetSubDeviceInstanceFromGpu(lVar3);
      if (iVar2 == param_2) {
        *param_3 = lVar3;
        return 0;
      }
    }
    lVar3 = *param_3;
  }
  return -(lVar3 == 0) & 0x57;
}


// ===== 004420a0 gpumgmtapiConstruct_IMPL =====

undefined8 gpumgmtapiConstruct_IMPL(void)

{
  return 0;
}


// ===== 004420b0 gpumgmtapiDestruct_IMPL =====

void gpumgmtapiDestruct_IMPL(void)

{
  return;
}


// ===== 004420c0 gpumgmtapiCtrlCmdSetShutdownState_IMPL =====

void gpumgmtapiCtrlCmdSetShutdownState_IMPL(undefined8 param_1,undefined8 param_2)

{
  gpudbSetShutdownState(param_2);
  return;
}


// ===== 004420d0 gpumgrThreadEnableExpandedGpuVisibility =====

undefined8 gpumgrThreadEnableExpandedGpuVisibility(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)tlsEntryAcquire(5);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 1;
    return 0;
  }
  return 0x1a;
}


// ===== 00442100 gpumgrThreadDisableExpandedGpuVisibility =====

void gpumgrThreadDisableExpandedGpuVisibility(void)

{
  long lVar1;
  int iVar2;
  
  lVar1 = tlsEntryGet(5);
  if (lVar1 == 1) {
    iVar2 = tlsEntryRelease(5);
    if (iVar2 != 0) {
      nvAssertFailedNoLog("refCount == 0","src/kernel/gpu_mgr/gpu_mgr.c",0x187);
      return;
    }
  }
  return;
}


// ===== 00442160 gpumgrAllocGpuInstance =====

undefined8 gpumgrAllocGpuInstance(uint *param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  
  uVar6 = 0;
  lVar7 = *(long *)(g_pSys + 0x1e0);
  uVar3 = *(uint *)(lVar7 + 0x3f158);
  if (uVar3 != 0) {
    if (uVar3 == 0x20) {
      uVar6 = 0x1a;
    }
    else {
      uVar8 = 0xffffffff;
      lVar4 = (ulong)uVar3 * 0x10 + lVar7;
      do {
        puVar1 = (undefined4 *)(lVar7 + 0x3ef60);
        lVar7 = lVar7 + 0x10;
        uVar8 = uVar8 & (uint)~(1 << ((byte)*puVar1 & 0x1f));
      } while (lVar7 != lVar4);
      uVar5 = 0;
      uVar3 = 0;
      uVar2 = uVar8;
      while ((uVar2 & 1) == 0) {
        uVar3 = (int)uVar5 + 1;
        uVar5 = (ulong)uVar3;
        uVar2 = uVar8 >> (uVar5 & 0x3f);
      }
      uVar6 = 0;
    }
  }
  *param_1 = uVar3;
  return uVar6;
}


// ===== 00442200 gpumgrGetGpu =====

long gpumgrGetGpu(int param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  if (*(int *)(lVar1 + 0x3f158) != 0) {
    plVar4 = (long *)(lVar1 + 0x3ef58);
    uVar5 = 0;
    do {
      if ((((int)plVar4[1] == param_1) && (lVar2 = *plVar4, lVar2 != 0)) &&
         ((lVar3 = tlsEntryGet(5), lVar3 == 1 || (*(char *)(lVar2 + 0x445) != '\0')))) {
        return lVar2;
      }
      uVar5 = uVar5 + 1;
      plVar4 = plVar4 + 2;
    } while (uVar5 < *(uint *)(lVar1 + 0x3f158));
  }
  return 0;
}


// ===== 00442300 _gpumgrDestroyGpu =====

void _gpumgrDestroyGpu(int param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  ulong uVar7;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  osSyncWithGpuDestroy(1);
  uVar4 = gpumgrGetGpu(param_1);
  __nvoc_objDelete(uVar4);
  lVar2 = g_pSys;
  if (*(uint *)(lVar1 + 0x3f158) != 0) {
    piVar5 = (int *)(lVar1 + 0x3ef60);
    uVar3 = 0;
    do {
      if (*piVar5 == param_1) {
        lVar6 = (ulong)uVar3 * 0x10;
        *(undefined4 *)(lVar1 + 0x3ef60 + lVar6) = 0x20;
        *(undefined8 *)(lVar1 + 0x3ef58 + lVar6) = 0;
        lVar1 = *(long *)(lVar2 + 0x1e0);
        if (uVar3 == 0x1f) {
          uVar7 = 0x1f;
        }
        else {
          lVar6 = lVar6 + lVar1;
          uVar7 = (ulong)uVar3;
          do {
            uVar3 = uVar3 + 1;
            if (*(long *)(lVar6 + 0x3ef68) != 0) {
              *(long *)(lVar6 + 0x3ef58) = *(long *)(lVar6 + 0x3ef68);
              *(undefined4 *)(lVar6 + 0x3ef60) = *(undefined4 *)(lVar6 + 0x3ef70);
              uVar7 = (ulong)uVar3;
            }
            lVar6 = lVar6 + 0x10;
          } while (uVar3 != 0x1f);
        }
        *(undefined4 *)(lVar1 + 0x3ef60 + uVar7 * 0x10) = 0x20;
        *(undefined8 *)(lVar1 + 0x3ef58 + uVar7 * 0x10) = 0;
        *(int *)(lVar1 + 0x3f158) = *(int *)(lVar1 + 0x3f158) + -1;
        break;
      }
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 4;
    } while (uVar3 != *(uint *)(lVar1 + 0x3f158));
  }
  osSyncWithGpuDestroy(0);
  return;
}


// ===== 00442440 _gpumgrGetPcieP2PCapsFromCache =====

undefined8 _gpumgrGetPcieP2PCapsFromCache(uint param_1,undefined1 *param_2,undefined1 *param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar5 = *(long *)(g_pSys + 0x1e0);
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0;
    uVar3 = param_1;
    do {
      uVar8 = uVar8 + 1;
      uVar3 = uVar3 & uVar3 - 1;
    } while (uVar3 != 0);
  }
  listTail_IMPL(lVar5 + 0x3f278);
  uVar4 = listHead_IMPL(lVar5 + 0x3f278);
  listIterRange_IMPL(&local_78,lVar5 + 0x3f278,uVar4);
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  do {
    do {
      uVar4 = listIterNext_IMPL(&local_58);
      piVar2 = local_58;
      if ((char)uVar4 == '\0') {
        return uVar4;
      }
    } while (local_58[8] != uVar8);
    piVar1 = local_58 + uVar8;
    uVar3 = uVar8;
    iVar7 = 0;
    do {
      iVar9 = iVar7 + 1;
      if ((1 << ((byte)iVar7 & 0x1f) & param_1) != 0) {
        lVar5 = gpumgrGetGpu(iVar7);
        if (lVar5 == 0) break;
        if (uVar8 != 0) {
          piVar6 = piVar2;
          do {
            if (*piVar6 == *(int *)(lVar5 + 0x7ac)) {
              uVar3 = uVar3 - 1;
              break;
            }
            piVar6 = piVar6 + 1;
          } while (piVar1 != piVar6);
        }
        if (uVar3 == 0) goto joined_r0x004425d4;
      }
      iVar7 = iVar9;
    } while (iVar9 != 0x20);
    if (uVar3 == 0) {
joined_r0x004425d4:
      if (param_2 != (undefined1 *)0x0) {
        *param_2 = (char)piVar2[9];
      }
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = *(undefined1 *)((long)piVar2 + 0x25);
      }
      return 1;
    }
  } while( true );
}


// ===== 004425f0 __pfx_gpumgrGetGpuAttachInfo =====

undefined8 __pfx_gpumgrGetGpuAttachInfo(int *param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uStack_40;
  
  iVar6 = 0;
  uVar1 = *(uint *)(*(long *)(g_pSys + 0x1e0) + 0x95c);
  uStack_40 = 0;
  iVar4 = 0;
  do {
    uVar7 = 1 << ((byte)iVar4 & 0x1f);
    iVar5 = iVar4 + 1;
    if ((uVar1 & uVar7) != 0) {
      lVar2 = gpumgrGetGpu(iVar4);
      if (lVar2 != 0) {
        lVar3 = tlsEntryGet(5);
        if ((lVar3 == 1) || (*(char *)(lVar2 + 0x445) != '\0')) {
          uStack_40 = uStack_40 | uVar7;
          iVar6 = iVar6 + 1;
        }
      }
    }
    iVar4 = iVar5;
  } while (iVar5 != 0x20);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar6;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uStack_40;
  }
  return 0;
}


// ===== 00442600 gpumgrGetGpuAttachInfo =====

undefined8 gpumgrGetGpuAttachInfo(int *param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_40;
  
  iVar6 = 0;
  uVar1 = *(uint *)(*(long *)(g_pSys + 0x1e0) + 0x95c);
  local_40 = 0;
  iVar4 = 0;
  do {
    uVar7 = 1 << ((byte)iVar4 & 0x1f);
    iVar5 = iVar4 + 1;
    if ((uVar1 & uVar7) != 0) {
      lVar2 = gpumgrGetGpu(iVar4);
      if (lVar2 != 0) {
        lVar3 = tlsEntryGet(5);
        if ((lVar3 == 1) || (*(char *)(lVar2 + 0x445) != '\0')) {
          local_40 = local_40 | uVar7;
          iVar6 = iVar6 + 1;
        }
      }
    }
    iVar4 = iVar5;
  } while (iVar5 != 0x20);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar6;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = local_40;
  }
  return 0;
}


// ===== 00442700 gpumgrGetSomeGpu =====

long gpumgrGetSomeGpu(void)

{
  long lVar1;
  int iVar2;
  uint local_10;
  undefined1 local_c [4];
  
  local_10 = 0;
  gpumgrGetGpuAttachInfo(local_c,&local_10);
  iVar2 = 0;
  if ((local_10 & 1) == 0) {
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x20) goto LAB_00442753;
    } while ((1 << ((byte)iVar2 & 0x1f) & local_10) == 0);
  }
  else {
    iVar2 = 0;
  }
  lVar1 = gpumgrGetGpu(iVar2);
  if (lVar1 != 0) {
    return lVar1;
  }
LAB_00442753:
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x213,"gpumgrGetSomeGpu",4,
               "NVRM: Failed to retrieve pGpu - Too early call!.\n");
  nvAssertFailedNoLog("NV_FALSE","src/kernel/gpu_mgr/gpu_mgr.c",0x215);
  return 0;
}


// ===== 004427c0 _gpumgrIsP2PObjectPresent =====

undefined8 _gpumgrIsP2PObjectPresent(void)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_30 [4];
  uint local_2c [3];
  
  gpumgrGetGpuAttachInfo(local_30,local_2c);
  uVar2 = local_2c[0] & 1;
  iVar4 = 0;
  if (uVar2 == 0) {
    do {
      iVar3 = iVar4;
      iVar4 = iVar3 + 1;
      if (iVar4 == 0x20) {
        return 0;
      }
    } while ((1 << ((byte)iVar4 & 0x1f) & local_2c[0]) == 0);
    uVar2 = iVar3 + 2;
  }
  else {
    iVar4 = 0;
  }
  lVar1 = gpumgrGetGpu(iVar4);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if ((*(long *)(&DAT_00001b90 + lVar1) != 0) &&
       (*(int *)(*(long *)(&DAT_00001b90 + lVar1) + 0xacfc) != 0)) break;
    do {
      uVar5 = uVar2;
      if (uVar5 == 0x20) {
        return 0;
      }
      uVar2 = uVar5 + 1;
    } while ((1 << ((byte)uVar5 & 0x1f) & local_2c[0]) == 0);
    lVar1 = gpumgrGetGpu(uVar5);
  }
  return 1;
}


// ===== 004428b0 gpumgrGetDeviceGpuMask =====

undefined8
gpumgrGetDeviceGpuMask
          (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 uVar1;
  
  if (param_1 < 0x20) {
    if (*(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)param_1 * 8) != 0) {
      uVar1 = gpugrpGetGpuMask_IMPL();
      return uVar1;
    }
  }
  else {
    nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc72,
                        param_4,param_5,param_1);
  }
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x269,"gpumgrGetDeviceGpuMask",3,
               "NVRM: Could not find GPU Group for deviceInstance 0x%x!\n",param_1);
  return 0;
}


// ===== 00442940 gpumgrIsDeviceInstanceValid =====

byte gpumgrIsDeviceInstanceValid(uint param_1)

{
  int iVar1;
  
  if (0x1f < param_1) {
    return 0x1f;
  }
  if (*(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)param_1 * 8) != 0) {
    iVar1 = gpugrpGetGpuMask_IMPL();
    return -(iVar1 == 0) & 0x1f;
  }
  return 0x25;
}


// ===== 00442990 gpumgrIsSubDeviceInstanceValid =====

bool gpumgrIsSubDeviceInstanceValid(uint param_1)

{
  return param_1 < 8;
}


// ===== 004429a0 gpumgrIsDeviceEnabled =====

bool gpumgrIsDeviceEnabled(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  long lVar4;
  int *piVar5;
  int iVar6;
  
  uVar3 = gpumgrGetDeviceGpuMask();
  if (uVar3 == 0) {
    return false;
  }
  if ((uVar3 - 1 & uVar3) == 0) {
    iVar6 = 0;
    if ((uVar3 & 1) == 0) {
      do {
        iVar6 = iVar6 + 1;
        if (iVar6 == 0x20) {
          return false;
        }
      } while ((1 << ((byte)iVar6 & 0x1f) & uVar3) == 0);
    }
    else {
      iVar6 = 0;
    }
    lVar4 = gpumgrGetGpu(iVar6);
    if (lVar4 == 0) {
      return false;
    }
    iVar6 = *(int *)(lVar4 + 0x7ac);
    piVar2 = *(int **)(g_pSys + 0x1e0);
    portSyncMutexAcquire(*(undefined8 *)(piVar2 + 0x252));
    uVar3 = 0;
    piVar5 = piVar2;
    do {
      piVar5 = piVar5 + 0x12;
      if (iVar6 == *piVar5) {
        cVar1 = *(char *)((long)piVar2 + (ulong)uVar3 * 0x48 + 0x59);
        portSyncMutexRelease(*(undefined8 *)(piVar2 + 0x252));
        return cVar1 == '\0';
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x20);
    portSyncMutexRelease(*(undefined8 *)(piVar2 + 0x252));
  }
  return true;
}


// ===== 00442ab0 gpumgrRegisterGpuId =====

undefined8 gpumgrRegisterGpuId(int param_1,undefined8 param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  undefined8 uVar5;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  while( true ) {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      uVar5 = 0x17;
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x2e5,"gpumgrRegisterGpuId",4,
                   "NVRM: GPU id 0x%x already registered at index %u\n",param_1);
      goto LAB_00442b40;
    }
    if (*piVar4 == -1) break;
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
    if (uVar2 == 0x20) {
      uVar5 = 0x1a;
LAB_00442b40:
      portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
      return uVar5;
    }
  }
  piVar1[uVar3 * 0x12 + 0x12] = param_1;
  uVar5 = 0;
  *(undefined8 *)(piVar1 + uVar3 * 0x12 + 0x14) = param_2;
  *(undefined1 *)(piVar1 + uVar3 * 0x12 + 0x16) = 0;
  *(undefined2 *)((long)piVar1 + uVar3 * 0x48 + 0x5b) = 0;
  (piVar1 + uVar3 * 0x12 + 0x22)[0] = 0;
  (piVar1 + uVar3 * 0x12 + 0x22)[1] = 0;
  goto LAB_00442b40;
}


// ===== 00442ba0 gpumgrExcludeGpuId =====

undefined8 gpumgrExcludeGpuId(int param_1)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      *(undefined1 *)((long)piVar1 + uVar3 * 0x48 + 0x5b) = 1;
      break;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return 0;
}


// ===== 00442c10 gpumgrSetUuid =====

undefined8 gpumgrSetUuid(int param_1,long param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  if (param_2 == 0) {
    return 0x25;
  }
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      portMemCopy(piVar1 + uVar3 * 0x12 + 0x1d,0x10,param_2,0x10);
      *(undefined1 *)(piVar1 + uVar3 * 0x12 + 0x17) = 1;
      break;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return 0;
}


// ===== 00442cc0 gpumgrGetGpuUuidInfo =====

uint gpumgrGetGpuUuidInfo(int param_1,long *param_2,undefined4 *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  int *piVar5;
  
  if ((param_2 == (long *)0x0) || (param_3 == (undefined4 *)0x0)) {
    return 0x25;
  }
  if ((param_4 & 4) == 0) {
    lVar3 = portMemAllocNonPaged(0x10);
    if (lVar3 != 0) {
      piVar1 = *(int **)(g_pSys + 0x1e0);
      portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
      uVar4 = 0;
      piVar5 = piVar1;
      do {
        piVar5 = piVar5 + 0x12;
        if (param_1 == *piVar5) {
          if ((char)piVar1[uVar4 * 0x12 + 0x17] == '\0') {
            uVar2 = 0x56;
            portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
          }
          else {
            portMemCopy(lVar3,0x10,piVar1 + uVar4 * 0x12 + 0x1d,0x10);
            portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
            if ((param_4 & 3) == 2) {
              *param_2 = lVar3;
              *param_3 = 0x10;
              return param_4 & 4;
            }
            uVar2 = transformGidToUserFriendlyString(lVar3,0x10,param_2,param_3,param_4,0);
          }
          goto LAB_00442dc1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar4 = (ulong)uVar2;
      } while (uVar2 != 0x20);
      uVar2 = 0x57;
      portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
LAB_00442dc1:
      portMemFree(lVar3);
      return uVar2;
    }
    uVar2 = 0x51;
  }
  else {
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 00442ea0 gpumgrGetRmFirmwareLogsEnabled =====

bool gpumgrGetRmFirmwareLogsEnabled(int param_1)

{
  return param_1 == 1;
}


// ===== 00442eb0 gpumgrIsVgxRmFirmwareCapableChip =====

bool gpumgrIsVgxRmFirmwareCapableChip(uint param_1)

{
  return 0x17 < (param_1 >> 0x18 & 0x3f);
}


// ===== 00442ed0 gpumgrIsDeviceRmFirmwareCapable =====

undefined8
gpumgrIsDeviceRmFirmwareCapable(uint param_1,undefined8 param_2,char param_3,long param_4)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  
  if (param_3 != '\0') {
    uVar3 = 1;
    bVar1 = false;
    goto LAB_00442eee;
  }
  cVar2 = hypervisorIsVgxHyper_IMPL();
  if ((cVar2 == '\0') && ((param_1 >> 0x18 & 0x3f) < 0x16)) {
LAB_00442f3e:
    bVar1 = false;
    uVar3 = 0;
  }
  else {
    cVar2 = hypervisorIsVgxHyper_IMPL();
    if (cVar2 == '\0') {
      cVar2 = hypervisorIsVgxHyper_IMPL();
      if (cVar2 == '\0') {
        uVar3 = 1;
        bVar1 = true;
      }
      else {
        uVar3 = 1;
        bVar1 = 0x17 < (param_1 >> 0x18 & 0x3f);
      }
      goto LAB_00442eee;
    }
    uVar4 = param_1 >> 0x18 & 0x3f;
    if (uVar4 < 0x1a) {
      if (1 < uVar4 - 0x18) goto LAB_00442f3e;
    }
    hypervisorIsVgxHyper_IMPL();
    uVar3 = 1;
    bVar1 = true;
  }
LAB_00442eee:
  if (param_4 != 0) {
    *(bool *)param_4 = bVar1;
  }
  return uVar3;
}


// ===== 00442fa0 gpumgrGetGpuArch_IMPL =====

long gpumgrGetGpuArch_IMPL(uint param_1,ulong param_2,int param_3)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long local_40 [2];
  
  bVar2 = (byte)(param_2 >> 8);
  uVar7 = param_1 >> 0x14 & 0xf;
  uVar5 = param_1 >> 0x18 & 0x3f;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x950));
  uVar6 = (uint)(param_2 >> 4) & 0xf;
  if ((bVar2 == 0x23) && (uVar6 == 10)) {
    uVar6 = 4;
  }
  local_40[0] = 0;
  uVar6 = (uint)bVar2 << 4 | uVar6;
  for (lVar4 = objGetChild_IMPL(*(undefined8 *)(lVar1 + 0x38)); lVar4 != 0;
      lVar4 = objGetSibling_IMPL(lVar4)) {
    local_40[0] = __nvoc_dynamicCast(lVar4,__nvoc_class_def_GpuArch);
    if ((((local_40[0] != 0) &&
         (nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x5bc,"gpumgrGetGpuArch_IMPL",1,
                       "NVRM: checking GpuArch(chipArch:%x chipImpl:%x hidrev:%x tegraType:%x)\n",
                       *(undefined4 *)(local_40[0] + 0x84),*(undefined4 *)(local_40[0] + 0x88),
                       *(undefined4 *)(local_40[0] + 0x8c),*(undefined4 *)(local_40[0] + 0x90)),
         *(uint *)(local_40[0] + 0x84) == uVar5)) && (*(uint *)(local_40[0] + 0x88) == uVar7)) &&
       ((*(uint *)(local_40[0] + 0x8c) == uVar6 && (*(int *)(local_40[0] + 0x90) == param_3))))
    goto LAB_004430f9;
    local_40[0] = 0;
  }
  if (local_40[0] == 0) {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x5c8,"gpumgrGetGpuArch_IMPL",1,
                 "NVRM: creating GpuArch(chipArch:%x chipImpl:%x hidrev:%x tegraType:%x)\n",uVar5,
                 uVar7,uVar6,param_3);
    iVar3 = __nvoc_objCreate_GpuArch
                      (local_40,lVar1,0,uVar5,uVar7,uVar6,param_3,uVar5,uVar7,uVar6,param_3);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "objCreate(&pGpuArch, pGpuMgr, GpuArch, chipArch, chipImpl, hidrev, tegraType, chipArch, chipImpl, hidrev, tegraType)"
                 ,"src/kernel/gpu_mgr/gpu_mgr.c",0x5cf);
    }
  }
LAB_004430f9:
  portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x950));
  return local_40[0];
}


// ===== 004431a0 gpumgrDetachGpu =====

undefined8 gpumgrDetachGpu(undefined4 param_1)

{
  char cVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  
  lVar2 = *(long *)(g_pSys + 0x1e0);
  lVar5 = gpumgrGetGpu();
  cVar1 = *(char *)(lVar5 + 0x456);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu_mgr/gpu_mgr.c",0x66b);
    uVar6 = 0x2f;
  }
  else {
    uVar7 = 1 << ((byte)param_1 & 0x1f);
    if (cVar1 == '\0') {
      rmapiSetDelPendingClientResourcesFromGpuMask(uVar7);
      osDpcDetachGpu(lVar5);
      *(undefined8 *)(lVar5 + 0x4e8) = 0;
      _gpumgrDestroyGpu(param_1);
      rmapiDelPendingDevices(uVar7);
      rmapiDelPendingClients();
    }
    else {
      osDpcDetachGpu(lVar5);
      *(undefined8 *)(lVar5 + 0x4e8) = 0;
      _gpumgrDestroyGpu(param_1);
    }
    uVar4 = *(uint *)(lVar2 + 0x95c);
    *(uint *)(lVar2 + 0x960) = *(uint *)(lVar2 + 0x960) & ~uVar7;
    if ((uVar4 & uVar7) == 0) {
      nvAssertFailedNoLog("pGpuMgr->gpuAttachMask & NVBIT(gpuInstance)",
                          "src/kernel/gpu_mgr/gpu_mgr.c",0x682);
      uVar4 = *(uint *)(lVar2 + 0x95c);
    }
    *(int *)(lVar2 + 0x958) = *(int *)(lVar2 + 0x958) + -1;
    uVar6 = 0;
    *(uint *)(lVar2 + 0x95c) = ~uVar7 & uVar4;
  }
  return uVar6;
}


// ===== 004432f0 gpumgrGetDeviceInstanceMask =====

uint gpumgrGetDeviceInstanceMask(void)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  do {
    if (*(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + uVar3 * 8) != 0) {
      iVar1 = gpugrpGetGpuMask_IMPL();
      if (iVar1 != 0) {
        uVar4 = uVar4 | 1 << ((uint)uVar3 & 0x1f);
      }
    }
    uVar2 = (uint)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  return uVar4;
}


// ===== 00443340 gpumgrGetGpuMask =====

undefined8 gpumgrGetGpuMask(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x7b4);
  if (uVar1 < 0x20) {
    if (*(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)uVar1 * 8) != 0) {
      uVar2 = gpugrpGetGpuMask_IMPL();
      return uVar2;
    }
  }
  else {
    nvAssertFailedNoLog("deviceInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0x70a);
    nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc72);
  }
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x269,"gpumgrGetDeviceGpuMask",3,
               "NVRM: Could not find GPU Group for deviceInstance 0x%x!\n",uVar1);
  return 0;
}


// ===== 004433f0 gpumgrGetSubDeviceCount =====

int gpumgrGetSubDeviceCount(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 & param_1 - 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// ===== 00443410 gpumgrGetSubDeviceMaxValuePlus1 =====

int gpumgrGetSubDeviceMaxValuePlus1(long param_1)

{
  return *(int *)(param_1 + 0x7b8) + 1;
}


// ===== 00443420 gpumgrGetNextGpu =====

undefined8 gpumgrGetNextGpu(uint param_1,uint *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  if (*param_2 < 0x20) {
    do {
      uVar3 = uVar2 + 1;
      if ((1 << ((byte)uVar2 & 0x1f) & param_1) != 0) {
        *param_2 = uVar3;
        uVar1 = gpumgrGetGpu(uVar2);
        return uVar1;
      }
      uVar2 = uVar3;
    } while (uVar3 != 0x20);
  }
  *param_2 = 0x20;
  return 0;
}


// ===== 00443480 gpumgrIsGpuPointerValid =====

undefined8 gpumgrIsGpuPointerValid(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_30;
  undefined1 local_2c [12];
  
  local_30 = 0;
  gpumgrGetGpuAttachInfo(local_2c,&local_30);
  uVar1 = local_30;
  uVar4 = local_30 & 1;
  iVar6 = 0;
  if (uVar4 == 0) {
    do {
      iVar5 = iVar6;
      iVar6 = iVar5 + 1;
      if (iVar6 == 0x20) {
        return 0;
      }
    } while ((1 << ((byte)iVar6 & 0x1f) & local_30) == 0);
    uVar4 = iVar5 + 2;
  }
  else {
    iVar6 = 0;
  }
  lVar2 = gpumgrGetGpu(iVar6);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    if ((*(char *)(lVar2 + 0x445) != '\0') && (param_1 == lVar2)) break;
    do {
      uVar3 = uVar4;
      if (uVar3 == 0x20) {
        return 0;
      }
      uVar4 = uVar3 + 1;
    } while ((1 << ((byte)uVar3 & 0x1f) & uVar1) == 0);
    lVar2 = gpumgrGetGpu(uVar3);
  }
  return 1;
}


// ===== 00443570 __pfx_gpumgrIsGpuPointerAttached =====

undefined8 __pfx_gpumgrIsGpuPointerAttached(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uStack_30;
  undefined1 auStack_2c [4];
  
  uStack_30 = 0;
  gpumgrGetGpuAttachInfo(auStack_2c,&uStack_30);
  uVar1 = uStack_30;
  uVar3 = uStack_30 & 1;
  iVar5 = 0;
  if (uVar3 == 0) {
    do {
      iVar4 = iVar5;
      iVar5 = iVar4 + 1;
      if (iVar5 == 0x20) {
        return 0;
      }
    } while ((1 << ((byte)iVar5 & 0x1f) & uStack_30) == 0);
    uVar3 = iVar4 + 2;
  }
  else {
    iVar5 = 0;
  }
  lVar2 = gpumgrGetGpu(iVar5);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    if (param_1 == lVar2) break;
    do {
      uVar6 = uVar3;
      if (uVar6 == 0x20) {
        return 0;
      }
      uVar3 = uVar6 + 1;
    } while ((1 << ((byte)uVar6 & 0x1f) & uVar1) == 0);
    lVar2 = gpumgrGetGpu(uVar6);
  }
  return 1;
}


// ===== 00443580 gpumgrIsGpuPointerAttached =====

undefined8 gpumgrIsGpuPointerAttached(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_30;
  undefined1 local_2c [4];
  
  local_30 = 0;
  gpumgrGetGpuAttachInfo(local_2c,&local_30);
  uVar1 = local_30;
  uVar3 = local_30 & 1;
  iVar5 = 0;
  if (uVar3 == 0) {
    do {
      iVar4 = iVar5;
      iVar5 = iVar4 + 1;
      if (iVar5 == 0x20) {
        return 0;
      }
    } while ((1 << ((byte)iVar5 & 0x1f) & local_30) == 0);
    uVar3 = iVar4 + 2;
  }
  else {
    iVar5 = 0;
  }
  lVar2 = gpumgrGetGpu(iVar5);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    if (param_1 == lVar2) break;
    do {
      uVar6 = uVar3;
      if (uVar6 == 0x20) {
        return 0;
      }
      uVar3 = uVar6 + 1;
    } while ((1 << ((byte)uVar6 & 0x1f) & uVar1) == 0);
    lVar2 = gpumgrGetGpu(uVar6);
  }
  return 1;
}


// ===== 00443660 gpumgrGetProbedGpuIds =====

undefined8 gpumgrGetProbedGpuIds(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar13;
  ulong uVar14;
  ulong uVar12;
  
  lVar8 = *(long *)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(lVar8 + 0x948));
  piVar4 = (int *)(lVar8 + 0x48);
  uVar12 = 0;
  uVar14 = 0;
  do {
    while( true ) {
      uVar10 = (uint)uVar12;
      uVar13 = (uint)uVar14;
      iVar3 = *piVar4;
      uVar11 = uVar12;
      if (iVar3 != -1) break;
LAB_004436ae:
      uVar10 = (uint)uVar11;
      piVar4 = piVar4 + 0x12;
      uVar12 = uVar11;
      if (piVar4 == (int *)(lVar8 + 0x948)) goto LAB_004436e1;
    }
    if (*(char *)((long)piVar4 + 0x13) != '\0') {
      uVar11 = (ulong)(uVar10 + 1);
      *(int *)(param_1 + 0x80 + uVar12 * 4) = iVar3;
      goto LAB_004436ae;
    }
    piVar5 = piVar4 + 0x12;
    uVar13 = uVar13 + 1;
    *(int *)(param_1 + uVar14 * 4) = iVar3;
    *(int *)(param_1 + 0x100 + uVar14 * 4) = piVar4[1];
    piVar4 = piVar5;
    uVar14 = (ulong)uVar13;
  } while (piVar5 != (int *)(lVar8 + 0x948));
LAB_004436e1:
  portSyncMutexRelease(*(undefined8 *)(lVar8 + 0x948));
  if (uVar13 < 0x20) {
    puVar6 = (undefined4 *)(param_1 + (ulong)uVar13 * 4);
    puVar1 = (undefined4 *)(param_1 + 4 + ((ulong)(0x1f - uVar13) + (ulong)uVar13) * 4);
    if (((int)puVar1 - (int)puVar6 & 4U) != 0) {
      *puVar6 = 0xffffffff;
      puVar6 = puVar6 + 1;
      if (puVar6 == puVar1) goto LAB_00443756;
    }
    do {
      *puVar6 = 0xffffffff;
      puVar7 = puVar6 + 2;
      puVar6[1] = 0xffffffff;
      puVar6 = puVar7;
    } while (puVar7 != puVar1);
  }
LAB_00443756:
  if (uVar10 < 0x20) {
    lVar8 = param_1 + (ulong)uVar10 * 4;
    lVar2 = param_1 + 4 + ((ulong)(0x1f - uVar10) + (ulong)uVar10) * 4;
    if (((int)lVar2 - (int)lVar8 & 4U) != 0) {
      *(undefined4 *)(lVar8 + 0x80) = 0xffffffff;
      lVar8 = lVar8 + 4;
      if (lVar8 == lVar2) {
        return 0;
      }
    }
    do {
      *(undefined4 *)(lVar8 + 0x80) = 0xffffffff;
      lVar9 = lVar8 + 8;
      *(undefined4 *)(lVar8 + 0x84) = 0xffffffff;
      lVar8 = lVar9;
    } while (lVar9 != lVar2);
  }
  return 0;
}


// ===== 004437d0 gpumgrSetProbedFlags =====

void gpumgrSetProbedFlags(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      piVar1[uVar3 * 0x12 + 0x13] = param_2;
      break;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return;
}


// ===== 00443840 gpumgrGetAttachedGpuIds =====

undefined8 gpumgrGetAttachedGpuIds(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  undefined1 local_40 [4];
  uint local_3c [3];
  
  gpumgrGetGpuAttachInfo(local_40,local_3c);
  uVar8 = 0;
  iVar5 = 0;
  do {
    while (uVar7 = (uint)uVar8, (1 << ((byte)iVar5 & 0x1f) & local_3c[0]) == 0) {
      iVar5 = iVar5 + 1;
      if (iVar5 == 0x20) goto LAB_004438b6;
    }
    iVar6 = iVar5 + 1;
    lVar2 = gpumgrGetGpu(iVar5);
    uVar7 = uVar7 + 1;
    *(undefined4 *)(param_1 + uVar8 * 4) = *(undefined4 *)(lVar2 + 0x7ac);
    uVar8 = (ulong)uVar7;
    iVar5 = iVar6;
  } while (iVar6 != 0x20);
LAB_004438b6:
  if (uVar7 < 0x20) {
    puVar3 = (undefined4 *)(param_1 + (ulong)uVar7 * 4);
    puVar1 = (undefined4 *)(param_1 + 4 + ((ulong)(0x1f - uVar7) + (ulong)uVar7) * 4);
    if (((int)puVar1 - (int)puVar3 & 4U) != 0) {
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 1;
      if (puVar3 == puVar1) {
        return 0;
      }
    }
    do {
      *puVar3 = 0xffffffff;
      puVar4 = puVar3 + 2;
      puVar3[1] = 0xffffffff;
      puVar3 = puVar4;
    } while (puVar4 != puVar1);
  }
  return 0;
}


// ===== 00443930 gpumgrGetSubDeviceInstanceFromGpu =====

undefined4 gpumgrGetSubDeviceInstanceFromGpu(long param_1)

{
  return *(undefined4 *)(param_1 + 0x7b8);
}


// ===== 00443940 gpumgrGetParentGPU =====

long gpumgrGetParentGPU(long param_1)

{
  uint uVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x7b4) < 0x20) {
    lVar2 = *(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)*(uint *)(param_1 + 0x7b4) * 8);
    if (lVar2 != 0) {
      uVar1 = gpugrpGetGpuMask_IMPL(lVar2);
      if ((uVar1 != 0) && ((uVar1 - 1 & uVar1) == 0)) {
        return param_1;
      }
      lVar2 = gpugrpGetParentGpu_IMPL(lVar2);
      return lVar2;
    }
  }
  else {
    nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc87);
  }
  nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x937);
  return 0;
}


// ===== 00443a00 gpumgrGetPrimaryForDevice =====

undefined4 gpumgrGetPrimaryForDevice(undefined4 param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = gpumgrGetDeviceGpuMask();
  if ((uVar1 == 0) || ((uVar1 - 1 & uVar1) != 0)) {
    iVar4 = 0;
    do {
      iVar5 = iVar4 + 1;
      if ((1 << ((byte)iVar4 & 0x1f) & uVar1) != 0) {
        lVar2 = gpumgrGetGpu(iVar4);
        if (lVar2 == 0) break;
        lVar3 = gpumgrGetParentGPU(lVar2);
        if (lVar3 == lVar2) {
          return *(undefined4 *)(lVar3 + 0x7a4);
        }
      }
      iVar4 = iVar5;
    } while (iVar5 != 0x20);
  }
  else {
    if ((uVar1 & 1) == 0) {
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
        if (iVar4 == 0x20) goto LAB_00443a5e;
      } while ((1 << ((byte)iVar4 & 0x1f) & uVar1) == 0);
    }
    else {
      iVar4 = 0;
    }
    lVar2 = gpumgrGetGpu(iVar4);
    if (lVar2 != 0) {
      return *(undefined4 *)(lVar2 + 0x7a4);
    }
  }
LAB_00443a5e:
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x2a9,"gpumgrGetPrimaryForDevice",4,
               "NVRM: deviceInstance 0x%x does not exist!\n",param_1);
  return 0;
}


// ===== 00443b20 gpumgrSetParentGPU =====

void gpumgrSetParentGPU(long param_1)

{
  if (*(uint *)(param_1 + 0x7b4) < 0x20) {
    if (*(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)*(uint *)(param_1 + 0x7b4) * 8) != 0) {
      gpugrpSetParentGpu_IMPL();
      return;
    }
  }
  else {
    nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc87);
  }
  nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x94c);
  return;
}


// ===== 00443ba0 gpumgrGetGpuFromId =====

long gpumgrGetGpuFromId(int param_1)

{
  long lVar1;
  int iVar2;
  undefined1 local_30 [4];
  uint local_2c;
  
  iVar2 = 0;
  gpumgrGetGpuAttachInfo(local_30,&local_2c);
  do {
    if ((1 << ((byte)iVar2 & 0x1f) & local_2c) != 0) {
      lVar1 = gpumgrGetGpu(iVar2);
      if (*(int *)(lVar1 + 0x7ac) == param_1) {
        return lVar1;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  return 0;
}


// ===== 00443c40 gpumgrGetGpuFromUuid =====

long gpumgrGetGpuFromUuid(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_4c [4];
  uint local_48;
  undefined4 local_44;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  gpumgrGetGpuAttachInfo(local_4c,&local_48);
  uVar3 = local_48 & 1;
  iVar1 = 0;
  if (uVar3 == 0) {
    do {
      iVar4 = iVar1;
      iVar1 = iVar4 + 1;
      if (iVar1 == 0x20) {
        return 0;
      }
    } while ((1 << ((byte)iVar1 & 0x1f) & local_48) == 0);
    uVar3 = iVar4 + 2;
  }
  else {
    iVar1 = 0;
  }
  lVar2 = gpumgrGetGpu(iVar1);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    iVar1 = gpuGetGidInfo_IMPL(lVar2,local_40,&local_44,param_2);
    if (iVar1 != 0) break;
    iVar1 = portMemCmp(local_40[0],param_1,local_44);
    if (iVar1 == 0) {
      portMemFree(local_40[0]);
      return lVar2;
    }
    portMemFree(local_40[0]);
    do {
      uVar5 = uVar3;
      if (uVar5 == 0x20) {
        return 0;
      }
      uVar3 = uVar5 + 1;
    } while ((1 << ((byte)uVar5 & 0x1f) & local_48) == 0);
    lVar2 = gpumgrGetGpu(uVar5);
  }
  return 0;
}


// ===== 00443da0 gpumgrGetGpuFromBusInfo =====

long gpumgrGetGpuFromBusInfo(int param_1,char param_2,char param_3)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 local_40 [4];
  uint local_3c [3];
  
  gpumgrGetGpuAttachInfo(local_40,local_3c);
  uVar4 = local_3c[0] & 1;
  iVar6 = 0;
  if (uVar4 == 0) {
    do {
      iVar5 = iVar6;
      iVar6 = iVar5 + 1;
      if (iVar6 == 0x20) {
        return 0;
      }
    } while ((1 << ((byte)iVar6 & 0x1f) & local_3c[0]) == 0);
    uVar4 = iVar5 + 2;
  }
  else {
    iVar6 = 0;
  }
  lVar2 = gpumgrGetGpu(iVar6);
  if (lVar2 != 0) {
    do {
      uVar1 = *(undefined8 *)(lVar2 + 0x878);
      if (((param_1 == (int)((ulong)uVar1 >> 0x20)) && ((char)((ulong)uVar1 >> 8) == param_2)) &&
         (param_3 == (char)uVar1)) {
        return lVar2;
      }
      do {
        uVar3 = uVar4;
        if (uVar3 == 0x20) {
          return 0;
        }
        uVar4 = uVar3 + 1;
      } while ((1 << ((byte)uVar3 & 0x1f) & local_3c[0]) == 0);
      lVar2 = gpumgrGetGpu(uVar3);
    } while (lVar2 != 0);
    return 0;
  }
  return 0;
}


// ===== 00443ec0 gpumgrGetGpuIdInfoV2 =====

undefined8 gpumgrGetGpuIdInfoV2(int *param_1)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  int iVar8;
  undefined1 local_84 [4];
  uint local_80 [8];
  undefined8 local_60;
  long local_48;
  
  iVar8 = 0;
  iVar4 = *param_1;
  gpumgrGetGpuAttachInfo(local_84,local_80);
  while (((1 << ((byte)iVar8 & 0x1f) & local_80[0]) == 0 ||
         (lVar5 = gpumgrGetGpu(iVar8), iVar4 != *(int *)(lVar5 + 0x7ac)))) {
    iVar8 = iVar8 + 1;
    if (iVar8 == 0x20) {
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x9e4,"gpumgrGetGpuIdInfoV2",1,
                   "NVRM: gpumgrGetGpuInfoV2: bad gpuid spec: 0x%x\n",*param_1);
      return 0x1f;
    }
  }
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') && (iVar4 = rmGpuLocksGetOwnedMask(), iVar4 == 0)) {
    nvAssertFailedNoLog("gpumgrIsSafeToReadGpuInfo()","src/kernel/gpu_mgr/gpu_mgr.c",0x9ea);
    return 0x2f;
  }
  if (*(int *)(lVar5 + 0x7b4) == 0x20) {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x9f3,"gpumgrGetGpuIdInfoV2",4,
                 "NVRM: gpumgrGetGpuInfoV2: deviceInstance not found\n");
    return 0x1f;
  }
  uVar1 = *(undefined8 *)(lVar5 + 0x7b4);
  param_1[6] = *(int *)(lVar5 + 0x7a4);
  *(undefined8 *)(param_1 + 2) = uVar1;
  iVar4 = *(int *)(lVar5 + 0x7b0);
  param_1[1] = 0;
  param_1[5] = iVar4;
  param_1[7] = -1;
  cVar2 = osGpuSupportsAts(lVar5);
  if (cVar2 != '\0') {
    param_1[1] = param_1[1] | 0x40;
    if (((*(char *)(lVar5 + 0x4915) == '\0') || (*(long *)(lVar5 + 0x1bc0) == 0)) ||
       (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar5), cVar2 == '\0')) {
      param_1[7] = *(int *)(lVar5 + 0x7bc);
    }
    else {
      lVar6 = resservGetTlsCallContext();
      clientRefIter(local_80,*(undefined8 *)(lVar6 + 8),0,0x91fde7,1,1);
      do {
        cVar2 = clientRefIterNext(local_60,local_80);
        if (cVar2 == '\0') goto LAB_00443fcc;
        lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                   __nvoc_class_def_GPUInstanceSubscription);
      } while ((*(long *)(*(long *)(lVar6 + 0x128) + 0xe0) != lVar5) ||
              (uVar3 = *(uint *)(*(long *)(lVar6 + 0x138) + 0x968), uVar3 == 0xfffffffe));
      pcVar7 = (char *)((ulong)uVar3 * 0x20 + *(long *)(*(long *)(lVar5 + 0x1b70) + 0x2b8));
      if (*pcVar7 != '\0') {
        param_1[7] = *(int *)(pcVar7 + 0x18);
      }
    }
  }
LAB_00443fcc:
  uVar3 = gpuIsInUse_IMPL(lVar5);
  uVar3 = uVar3 & 1 | param_1[1];
  param_1[1] = uVar3;
  if (*(char *)(lVar5 + 0x485) != '\0') {
    param_1[1] = uVar3 | 4;
  }
  if (*(char *)(lVar5 + 0x447) != '\0') {
    param_1[1] = param_1[1] | 8;
  }
  if ((*(char *)(lVar5 + 0x7a0) != '\0') || (*(char *)(*(long *)(lVar5 + 0x4d8) + 0x80) != '\0')) {
    param_1[1] = param_1[1] | 0x20;
  }
  if (*(char *)(lVar5 + 0x45a) == '\0') {
    if ((*(char *)(lVar5 + 0x4b2) == '\0') || (*(long *)(lVar5 + 0x1b80) == 0)) {
      if (*(char *)(*(long *)(lVar5 + 0x4d8) + 0x80) != '\0') {
        param_1[1] = param_1[1] & 0xfffffe7fU | 0x100;
      }
    }
    else {
      param_1[1] = param_1[1] | 0x180;
    }
  }
  else {
    param_1[1] = param_1[1] & 0xfffffe7fU | 0x80;
  }
  param_1[4] = *(int *)(lVar5 + 0x1b3c);
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xa69,"gpumgrGetGpuIdInfoV2",1,
               "NVRM: gpumgrGetGpuInfoV2: gpu[0x%x]: device 0x%x subdevice 0x%x\n",*param_1,
               param_1[2],param_1[3]);
  return 0;
}


// ===== 00444230 gpumgrGetGpuIdInfo =====

void gpumgrGetGpuIdInfo(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = *param_1;
  local_34 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  iVar1 = gpumgrGetGpuIdInfoV2(&local_38);
  if (iVar1 == 0) {
    param_1[1] = local_34;
    *(undefined8 *)(param_1 + 2) = local_30;
    *(undefined8 *)(param_1 + 6) = local_28;
    *(undefined8 *)(param_1 + 8) = local_20;
  }
  return;
}


// ===== 004442a0 gpumgrGetGpuInitStatus =====

undefined8 gpumgrGetGpuInitStatus(int *param_1)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  undefined8 uVar5;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == *param_1) {
      uVar5 = 0x40;
      if ((char)piVar1[uVar3 * 0x12 + 0x16] != '\0') {
        uVar5 = 0;
        param_1[1] = piVar1[uVar3 * 0x12 + 0x1c];
      }
      goto LAB_0044430d;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  uVar5 = 0x1f;
LAB_0044430d:
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return uVar5;
}


// ===== 00444340 gpumgrGetProbedGpuDomainBusDevice =====

undefined4 gpumgrGetProbedGpuDomainBusDevice(int param_1,undefined8 *param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  undefined4 uVar5;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      uVar5 = 0;
      *param_2 = *(undefined8 *)(piVar1 + uVar3 * 0x12 + 0x14);
      goto LAB_0044439f;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  uVar5 = 0x57;
LAB_0044439f:
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return uVar5;
}


// ===== 004443d0 gpumgrSetGpuInitStatus =====

void gpumgrSetGpuInitStatus(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      *(undefined1 *)(piVar1 + uVar3 * 0x12 + 0x16) = 1;
      piVar1[uVar3 * 0x12 + 0x1c] = param_2;
      break;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return;
}


// ===== 00444450 gpumgrStatePreInitGpu =====

int gpumgrStatePreInitGpu(long param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = rmGpuLocksAcquire(0,0x400000);
  if (iVar2 != 0) goto LAB_004444de;
  if (param_1 == 0) {
LAB_004444d0:
    iVar2 = 0xf;
  }
  else {
    cVar1 = gpuIsGpuFullPower_IMPL(param_1);
    if ((((cVar1 == '\0') || (*(char *)(param_1 + 0x44c) == '\0')) ||
        (*(char *)(param_1 + 0x44f) != '\0')) ||
       (((*(char *)(param_1 + 0x450) != '\0' || (*(char *)(param_1 + 0x451) != '\0')) ||
        (*(char *)(param_1 + 0x455) != '\0')))) goto LAB_004444d0;
    cVar1 = gpuCheckSysmemAccess_IMPL(param_1);
    if (cVar1 == '\0') goto LAB_004444d0;
    iVar2 = gpuStatePreInit_IMPL(param_1);
  }
  rmGpuLocksRelease(0,0);
LAB_004444de:
  gpumgrSetGpuInitStatus(*(undefined4 *)(param_1 + 0x7ac),iVar2);
  return iVar2;
}


// ===== 00444500 gpumgrStateInitGpu =====

int gpumgrStateInitGpu(long param_1)

{
  int iVar1;
  
  iVar1 = rmGpuLocksAcquire(0,0x400000);
  if (iVar1 == 0) {
    iVar1 = gpuStateInit_IMPL(param_1);
    rmGpuLocksRelease(0,0);
  }
  gpumgrSetGpuInitStatus(*(undefined4 *)(param_1 + 0x7ac),iVar1);
  return iVar1;
}


// ===== 00444560 gpumgrStateLoadGpu =====

int gpumgrStateLoadGpu(long param_1,undefined4 param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = rmGpuLocksAcquire(0,0x400000);
  if (iVar3 == 0) {
    iVar3 = gpuStateLoad_IMPL(param_1,param_2);
    rmGpuLocksRelease(0,0);
    if (iVar3 == 0) {
      bVar4 = false;
      lVar2 = *(long *)(g_pSys + 0x1e0);
      if (*(long *)(param_1 + 0x1ce8) != 0) {
        bVar4 = *(char *)(*(long *)(param_1 + 0x1ce8) + 0x2f3) != '\0';
      }
      uVar1 = *(uint *)(lVar2 + 0x95c);
      if ((uVar1 == 0) || ((uVar1 - 1 & uVar1) != 0)) {
        if ((bool)*(char *)(lVar2 + 0x3f170) != bVar4) {
          nvAssertFailedNoLog("pGpuMgr->nvleCaps.bNvlEncryptionEnabled == bNvlEncryptionEnabled",
                              "src/kernel/gpu_mgr/gpu_mgr.c",0xda);
          nvAssertOkFailedNoLog
                    (0x40,"_gpumgrDetermineNvlinkEncryptionCapabilities(pGpuMgr, pGpu)",
                     "src/kernel/gpu_mgr/gpu_mgr.c",0x821);
          return 0x40;
        }
      }
      else {
        *(bool *)(lVar2 + 0x3f170) = bVar4;
        iVar3 = 0;
      }
    }
  }
  gpumgrSetGpuInitStatus(*(undefined4 *)(param_1 + 0x7ac),iVar3);
  return iVar3;
}


// ===== 00444660 gpumgrUpdateBoardId_IMPL =====

void gpumgrUpdateBoardId_IMPL(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  short local_1c;
  ushort local_1a;
  
  if (*(char *)(param_1 + 0x479) == '\0') {
    return;
  }
  uVar1 = *(ulong *)(param_1 + 0x878);
  lVar3 = clFindBrdgUpstreamPort_IMPL
                    (param_1,*(undefined8 *)(g_pSys + 0x208),1,&local_1f,&local_1e,&local_1d,
                     &local_1c,&local_1a,0);
  if (lVar3 != 0) {
    if (local_1c == 0x10de) {
      if ((local_1a >> 4 != 0x5b) && (local_1a != 0x1b3)) {
        return;
      }
    }
    else if (local_1c == 0x10b5) {
      if ((local_1a & 0xef00) != 0x8700) {
        return;
      }
    }
    else if (local_1c == 0x11f8) {
      if (((local_1a & 0xff00) != 0x8500) && ((local_1a & 0xff00) != 0x4000)) {
        return;
      }
    }
    else {
      if (local_1c != 0x15b3) {
        return;
      }
      if (local_1a != 0x1976) {
        return;
      }
    }
    uVar2 = gpuGenerate32BitId(uVar1 >> 0x20,local_1f,local_1e);
    *(undefined4 *)(param_1 + 0x7b0) = uVar2;
  }
  return;
}


// ===== 00444760 gpumgrGetDefaultPrimaryGpu =====

uint gpumgrGetDefaultPrimaryGpu(uint param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("gpuMask","src/kernel/gpu_mgr/gpu_mgr.c",0xb30);
    return 0;
  }
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    if ((1 << ((byte)iVar3 & 0x1f) & param_1) != 0) {
      lVar2 = gpumgrGetGpu(iVar3);
      if (lVar2 == 0) break;
      if (*(char *)(lVar2 + 0x447) != '\0') goto LAB_00444800;
    }
    iVar3 = iVar4;
  } while (iVar4 != 0x20);
  iVar3 = 0;
LAB_004447d1:
  do {
    iVar4 = iVar3;
    if (iVar4 == 0x20) {
LAB_004447d6:
      iVar3 = 0;
      uVar1 = param_1 & 1;
      while (uVar1 == 0) {
        iVar3 = iVar3 + 1;
        if (iVar3 == 0x20) {
          return param_1 & 1;
        }
        uVar1 = 1 << ((byte)iVar3 & 0x1f) & param_1;
      }
      lVar2 = gpumgrGetGpu(iVar3);
      if (lVar2 == 0) {
        return 0;
      }
LAB_00444800:
      return *(uint *)(lVar2 + 0x7a4);
    }
    iVar3 = iVar4 + 1;
    if ((1 << ((byte)iVar4 & 0x1f) & param_1) == 0) goto LAB_004447d1;
    lVar2 = gpumgrGetGpu(iVar4);
    if (lVar2 == 0) goto LAB_004447d6;
    if (*(char *)(lVar2 + 0x44a) == '\0') goto LAB_00444800;
  } while( true );
}


// ===== 00444880 gpumgrGetGpuLockAndDrPorts =====

ulong gpumgrGetGpuLockAndDrPorts(long param_1,long param_2,uint *param_3,uint *param_4)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  uint *puVar7;
  ulong uVar8;
  byte bVar9;
  uint local_1c [3];
  
  uVar4 = *(uint *)(param_1 + 0x7a4);
  uVar5 = (ulong)uVar4;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  *param_3 = 0;
  *param_4 = 0;
  if (param_2 == 0) {
    if (*(uint *)(param_1 + 0x7b4) < 0x20) {
      lVar1 = *(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)*(uint *)(param_1 + 0x7b4) * 8);
      if (lVar1 != 0) {
        puVar7 = (uint *)(lVar1 + 0x58);
        uVar5 = 0;
        do {
          if (*puVar7 == uVar4) {
            *param_3 = *(uint *)(lVar1 + 0x60 + uVar5 * 0xc);
            uVar4 = *(uint *)(lVar1 + 0x5c + uVar5 * 0xc);
            goto LAB_00444a42;
          }
          uVar3 = (int)uVar5 + 1;
          uVar5 = (ulong)uVar3;
          puVar7 = puVar7 + 3;
        } while (uVar3 != 8);
        uVar4 = 0;
LAB_00444a42:
        *param_4 = uVar4;
        return 0;
      }
    }
    else {
      nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc87);
    }
    nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0xb98);
    return 0x25;
  }
  uVar6 = (ulong)*(byte *)(lVar1 + 0xaf0);
  uVar8 = (ulong)*(uint *)(param_2 + 0x7a4);
  bVar9 = *(byte *)(lVar1 + 1 + ((uVar6 * 0x20 + uVar5) * 0x20 + 0x578 + uVar8) * 2);
  if ((~bVar9 & 3) == 0) {
    bVar2 = false;
    goto LAB_00444936;
  }
  while (bVar9 = *(byte *)(lVar1 + 0xaf2 + ((uVar6 * 0x20 + uVar5) * 0x20 + uVar8) * 2),
        (~bVar9 & 3) == 0) {
    bVar2 = true;
LAB_00444936:
    uVar6 = gpumgrPinsetToPinsetTableIndex((uint)(bVar9 >> 4),local_1c);
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    if ((~*(byte *)((ulong)local_1c[0] + 0xaf1 +
                   lVar1 + (((ulong)*(byte *)(lVar1 + 0xaf0) * 0x20 +
                            (ulong)*(uint *)(param_2 + 0x7a4)) * 0x20 + uVar5) * 2) & 0xc) == 0) {
      *param_3 = *param_3 | (uint)(bVar9 >> 4);
      *param_4 = *param_4 | 1 << bVar2;
    }
    if (bVar2) break;
    uVar8 = (ulong)*(uint *)(param_2 + 0x7a4);
    uVar6 = (ulong)*(byte *)(lVar1 + 0xaf0);
  }
  uVar5 = 0x1f;
  if (*param_3 != 0) {
    uVar5 = (ulong)(-(uint)(*param_4 == 0) & 0x1f);
  }
  return uVar5;
}


// ===== 00444ab0 gpumgrGetGpuPhysFbAddr =====

long gpumgrGetGpuPhysFbAddr(long param_1)

{
  if ((*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') && (*(long *)(param_1 + 0x850) == 0)) {
    nvAssertFailedNoLog("pGpu->pGpuArch->bGpuArchIsZeroFb || physFbAddr",
                        "src/kernel/gpu_mgr/gpu_mgr.c",0xc0f);
    return 0;
  }
  return *(long *)(param_1 + 0x850);
}


// ===== 00444b00 gpumgrGetGpuFromSubDeviceInst =====

long gpumgrGetGpuFromSubDeviceInst(uint param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 < 0x20) {
    if (*(long *)(*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)param_1 * 8) != 0) {
      uVar1 = gpugrpGetGpuMask_IMPL();
      if (uVar1 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        uVar3 = uVar1;
        do {
          iVar4 = iVar4 + 1;
          uVar3 = uVar3 & uVar3 - 1;
        } while (uVar3 != 0);
        if (iVar4 == 1) {
          if ((uVar1 & 1) == 0) {
            iVar4 = 0;
            do {
              iVar4 = iVar4 + 1;
              if (iVar4 == 0x20) {
                return 0;
              }
            } while ((1 << ((byte)iVar4 & 0x1f) & uVar1) == 0);
          }
          else {
            iVar4 = 0;
          }
          lVar2 = gpumgrGetGpu(iVar4);
          return lVar2;
        }
        iVar4 = 0;
      }
      do {
        iVar5 = iVar4 + 1;
        if ((1 << ((byte)iVar4 & 0x1f) & uVar1) != 0) {
          lVar2 = gpumgrGetGpu(iVar4);
          if (lVar2 == 0) break;
          if (param_2 == *(int *)(lVar2 + 0x7b8)) {
            return lVar2;
          }
        }
        iVar4 = iVar5;
      } while (iVar5 != 0x20);
      nvAssertFailedNoLog(&DAT_00d7c2b7,"src/kernel/gpu_mgr/gpu_mgr.c",0xc30);
      return 0;
    }
  }
  else {
    nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc72);
  }
  nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0xc20);
  return 0;
}


// ===== 00444c80 gpumgrAddDeviceInstanceToGpus =====

undefined8 gpumgrAddDeviceInstanceToGpus(uint param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  
  uVar5 = 0x57;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  iVar4 = 0;
  do {
    while (iVar7 = iVar4 + 1, (param_1 & 1 << ((byte)iVar4 & 0x1f)) == 0) {
      iVar4 = iVar7;
      if (iVar7 == 0x20) {
        return uVar5;
      }
    }
    lVar3 = gpumgrGetGpu(iVar4);
    if (lVar3 == 0) {
      return uVar5;
    }
    lVar6 = 0;
    while ((*(long *)(lVar1 + 0x970 + lVar6 * 8) == 0 ||
           (uVar2 = gpugrpGetGpuMask_IMPL(),
           (1 << ((byte)*(undefined4 *)(lVar3 + 0x7a4) & 0x1f) & uVar2) == 0))) {
      lVar6 = lVar6 + 1;
      if (lVar6 == 0x20) {
        nvAssertOkFailedNoLog(0x57,"rmStatus","src/kernel/gpu_mgr/gpu_mgr.c",0xc5c);
        return 0x57;
      }
    }
    *(int *)(lVar3 + 0x7b4) = (int)lVar6;
    uVar5 = 0;
    iVar4 = iVar7;
  } while (iVar7 != 0x20);
  return 0;
}


// ===== 00444d70 gpumgrGetGpuGrpFromGpu =====

undefined8 gpumgrGetGpuGrpFromGpu(long param_1)

{
  if (*(uint *)(param_1 + 0x7b4) < 0x20) {
    return *(undefined8 *)
            (*(long *)(g_pSys + 0x1e0) + 0x970 + (ulong)*(uint *)(param_1 + 0x7b4) * 8);
  }
  nvAssertFailedNoLog("gpugrpInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xc87);
  return 0;
}


// ===== 00444dc0 gpumgrModifyGpuDrainState =====

undefined4 gpumgrModifyGpuDrainState(int param_1,char param_2,char param_3,char param_4)

{
  int *piVar1;
  ulong uVar2;
  char cVar3;
  long lVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  ulong uVar8;
  bool bVar9;
  int iVar10;
  undefined1 local_40 [4];
  uint local_3c [3];
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  if ((param_3 != '\0') && (cVar3 = osRemoveGpuSupported(), cVar3 == '\0')) {
    return 0x56;
  }
  iVar10 = 0;
  gpumgrGetGpuAttachInfo(local_40,local_3c);
  while (((1 << ((byte)iVar10 & 0x1f) & local_3c[0]) == 0 ||
         (lVar4 = gpumgrGetGpu(iVar10), param_1 != *(int *)(lVar4 + 0x7ac)))) {
    iVar10 = iVar10 + 1;
    if (iVar10 == 0x20) {
      lVar4 = 0;
LAB_00444e82:
      portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
      uVar8 = 0;
      piVar5 = piVar1;
      while (piVar5 = piVar5 + 0x12, *piVar5 != param_1) {
        uVar6 = (int)uVar8 + 1;
        uVar8 = (ulong)uVar6;
        if (uVar6 == 0x20) {
          portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
          return 0x1f;
        }
      }
      cVar3 = *(char *)((long)piVar1 + uVar8 * 0x48 + 0x59);
      *(char *)((long)piVar1 + uVar8 * 0x48 + 0x59) = param_2;
      uVar2 = *(ulong *)(piVar1 + uVar8 * 0x12 + 0x14);
      bVar9 = param_3 != '\0' && param_2 != '\0';
      *(bool *)((long)piVar1 + uVar8 * 0x48 + 0x5a) = bVar9;
      portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
      if ((param_3 == '\0') && (param_2 != '\0')) {
        uVar7 = 0x17;
        if (cVar3 != param_2) {
          uVar7 = 0;
        }
        return uVar7;
      }
      if ((lVar4 == 0) && (bVar9)) {
        osRemoveGpu(uVar2 >> 0x20,(char)(uVar2 >> 8),uVar2 & 0xff);
      }
      return 0;
    }
  }
  if ((param_4 != '\0') && (param_2 != '\0')) {
    return 0x17;
  }
  goto LAB_00444e82;
}


// ===== 00444fa0 gpumgrQueryGpuDrainState =====

undefined8 gpumgrQueryGpuDrainState(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      if (param_2 != (undefined1 *)0x0) {
        *param_2 = *(undefined1 *)((long)piVar1 + uVar3 * 0x48 + 0x59);
      }
      if (param_3 == (undefined1 *)0x0) {
        portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
      }
      else {
        *param_3 = *(undefined1 *)((long)piVar1 + uVar3 * 0x48 + 0x5a);
        portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
      }
      return 0;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return 0x57;
}


// ===== 00445060 gpumgrGetGrpMaskFromGpuInst =====

undefined4 gpumgrGetGrpMaskFromGpuInst(uint param_1)

{
  if (param_1 < 0x20) {
    return *(undefined4 *)(*(long *)(g_pSys + 0x1e0) + 0xa70 + (ulong)param_1 * 4);
  }
  nvAssertFailedNoLog("gpuInst < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr.c",0xd4e);
  return 0;
}


// ===== 004450b0 gpumgrAddDeviceMaskToGpuInstTable =====

void gpumgrAddDeviceMaskToGpuInstTable(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_1 != 0) {
    uVar2 = 0;
    puVar4 = (uint *)(*(long *)(g_pSys + 0x1e0) + 0xa70);
    uVar3 = param_1;
    do {
      if ((param_1 >> (uVar2 & 0x1f) & 1) != 0) {
        *puVar4 = param_1;
      }
      puVar4 = puVar4 + 1;
      bVar1 = (byte)uVar2;
      uVar2 = uVar2 + 1;
      uVar3 = uVar3 & ~(1 << (bVar1 & 0x1f));
    } while ((uVar3 != 0) && (uVar2 != 0x20));
  }
  return;
}


// ===== 00445110 gpumgrClearDeviceMaskFromGpuInstTable =====

void gpumgrClearDeviceMaskFromGpuInstTable(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    uVar2 = 0;
    puVar4 = (undefined4 *)(*(long *)(g_pSys + 0x1e0) + 0xa70);
    uVar3 = param_1;
    do {
      if ((param_1 >> (uVar2 & 0x1f) & 1) != 0) {
        *puVar4 = 0;
      }
      puVar4 = puVar4 + 1;
      bVar1 = (byte)uVar2;
      uVar2 = uVar2 + 1;
      uVar3 = uVar3 & ~(1 << (bVar1 & 0x1f));
    } while ((uVar3 != 0) && (uVar2 != 0x20));
  }
  return;
}


// ===== 00445170 gpumgrDestroyDevice =====

undefined8 gpumgrDestroyDevice(ulong param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = (param_1 & 0xffffffff) + 0x12e;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  lVar2 = *(long *)(lVar1 + lVar4 * 8);
  if (lVar2 != 0) {
    uVar3 = gpugrpGetGpuMask_IMPL(lVar2);
    if (uVar3 == 0) {
      nvAssertFailedNoLog("gpuMask != 0","src/kernel/gpu_mgr/gpu_mgr.c",0x6dd);
    }
    else if ((uVar3 - 1 & uVar3) == 0) {
      gpugrpDestroy_IMPL(lVar2);
      *(undefined8 *)(lVar1 + lVar4 * 8) = 0;
      gpumgrClearDeviceMaskFromGpuInstTable(uVar3);
    }
    *(int *)(lVar1 + 0x968) = *(int *)(lVar1 + 0x968) + -1;
    return 0;
  }
  nvAssertFailedNoLog("pGpuGrp != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x6da);
  return 0x57;
}


// ===== 00445240 gpumgrCreateDevice =====

undefined4 gpumgrCreateDevice(uint *param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined4 uVar6;
  
  lVar4 = g_pSys;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  iVar2 = *(int *)(lVar1 + 0x968);
  *(int *)(lVar1 + 0x968) = iVar2 + 1;
  if (param_2 == 0) {
    uVar6 = 0x3f;
    nvAssertFailedNoLog("gpuMask != 0","src/kernel/gpu_mgr/gpu_mgr.c",0x69b);
    iVar2 = *(int *)(lVar1 + 0x968) + -1;
  }
  else if ((param_2 - 1 & param_2) == 0) {
    uVar5 = 0;
    do {
      if (*(long *)(*(long *)(lVar4 + 0x1e0) + 0x970 + uVar5 * 8) == 0) {
        *param_1 = (uint)uVar5;
        iVar2 = __nvoc_objCreate_OBJGPUGRP(lVar1 + (ulong)((uint)uVar5 + 0x12e) * 8,lVar1,0);
        if (iVar2 == 0) {
          gpugrpCreate_IMPL(*(undefined8 *)(lVar1 + 0x970 + (uVar5 & 0xffffffff) * 8),param_2);
        }
        iVar2 = 0;
        if ((param_2 & 1) == 0) goto LAB_004453af;
        iVar2 = 0;
        goto LAB_00445300;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0x20);
    *param_1 = 0x20;
    uVar6 = 0xffff;
    iVar2 = *(int *)(lVar1 + 0x968) + -1;
  }
  else {
    uVar6 = 0x3f;
  }
  *(int *)(lVar1 + 0x968) = iVar2;
  return uVar6;
  while ((1 << ((byte)iVar2 & 0x1f) & param_2) == 0) {
LAB_004453af:
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x20) goto LAB_00445317;
  }
LAB_00445300:
  lVar4 = gpumgrGetGpu(iVar2);
  if (lVar4 != 0) {
    gpumgrSetParentGPU(lVar4,lVar4);
  }
LAB_00445317:
  gpumgrAddDeviceMaskToGpuInstTable(param_2);
  uVar3 = gpugrpGetGpuMask_IMPL(*(undefined8 *)(lVar1 + 0x970 + (ulong)*param_1 * 8));
  if (uVar3 == param_2) {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x6ca,"gpumgrCreateDevice",1,
                 "NVRM: gpumgrCreateDevice: deviceInst 0x%x mask 0x%x\n",*param_1,param_2);
    uVar6 = 0;
  }
  else {
    uVar6 = 0x25;
    nvAssertFailedNoLog(&DAT_00d7c2eb,"src/kernel/gpu_mgr/gpu_mgr.c",0x6c6);
    gpumgrDestroyDevice(*param_1);
  }
  return uVar6;
}


// ===== 00445460 gpumgrAddSystemNvlinkTopo_IMPL =====

void gpumgrAddSystemNvlinkTopo_IMPL(long param_1)

{
  long lVar1;
  uint uVar2;
  char *pcVar3;
  ulong uVar4;
  char *pcVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  pcVar5 = (char *)(lVar1 + 0x1b48);
  pcVar3 = pcVar5;
  while ((*pcVar3 == '\0' || (param_1 != *(long *)(pcVar3 + 8)))) {
    pcVar3 = pcVar3 + 0x148;
    if ((char *)(lVar1 + 0x4448) == pcVar3) {
      uVar4 = 0;
      do {
        if (*pcVar5 == '\0') {
          *(undefined1 *)(lVar1 + 0x1b48 + uVar4 * 0x148) = 1;
          *(long *)(lVar1 + 0x1b50 + uVar4 * 0x148) = param_1;
          return;
        }
        uVar2 = (int)uVar4 + 1;
        uVar4 = (ulong)uVar2;
        pcVar5 = pcVar5 + 0x148;
      } while (uVar2 != 0x20);
      return;
    }
  }
  return;
}


// ===== 00445500 gpumgrGetSystemNvlinkTopo_IMPL =====

undefined8 gpumgrGetSystemNvlinkTopo_IMPL(long param_1,undefined4 *param_2)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  
  uVar5 = 0;
  lVar6 = *(long *)(g_pSys + 0x1e0);
  pcVar1 = (char *)(lVar6 + 0x1b48);
  while ((*pcVar1 == '\0' || (*(long *)(pcVar1 + 8) != param_1))) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    pcVar1 = pcVar1 + 0x148;
    if (uVar4 == 0x20) {
      return 0;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    lVar3 = uVar5 * 0x148 + lVar6;
    *param_2 = *(undefined4 *)(lVar3 + 7000);
    param_2[1] = *(undefined4 *)(lVar3 + 0x1b5c);
    *(undefined1 *)(param_2 + 2) = *(undefined1 *)(lVar3 + 0x1b60);
    param_2[3] = *(undefined4 *)(lVar3 + 0x1b64);
    param_2[4] = *(undefined4 *)(lVar3 + 0x1b68);
    *(undefined1 *)(param_2 + 5) = *(undefined1 *)(lVar3 + 0x1b6c);
    lVar2 = 0;
    do {
      *(undefined4 *)((long)param_2 + lVar2 + 0x9c) = *(undefined4 *)(lVar3 + 0x1bf4 + lVar2);
      lVar2 = lVar2 + 4;
    } while (lVar2 != 0x80);
    lVar6 = lVar6 + uVar5 * 0x148;
    param_2[0x47] = *(undefined4 *)(lVar6 + 0x1c74);
    param_2[0x48] = *(undefined4 *)(lVar6 + 0x1c78);
    param_2[0x49] = *(undefined4 *)(lVar6 + 0x1c7c);
    param_2[0x4a] = *(undefined4 *)(lVar6 + 0x1c80);
    param_2[0x4b] = *(undefined4 *)(lVar6 + 0x1c84);
    param_2[0x4c] = *(undefined4 *)(lVar6 + 0x1c88);
    lVar6 = 0;
    do {
      *(undefined4 *)((long)param_2 + lVar6 + 0x18) = *(undefined4 *)(lVar3 + 0x1b70 + lVar6);
      lVar6 = lVar6 + 4;
    } while (lVar6 != 0x80);
  }
  return 1;
}


// ===== 00445640 gpumgrUpdateSystemNvlinkTopo_IMPL =====

void gpumgrUpdateSystemNvlinkTopo_IMPL(long param_1,undefined4 *param_2)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  
  uVar6 = 0;
  lVar3 = *(long *)(g_pSys + 0x1e0);
  pcVar1 = (char *)(lVar3 + 0x1b48);
  while ((*pcVar1 == '\0' || (*(long *)(pcVar1 + 8) != param_1))) {
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar5;
    pcVar1 = pcVar1 + 0x148;
    if (uVar5 == 0x20) {
      return;
    }
  }
  lVar4 = uVar6 * 0x148 + lVar3;
  *(undefined4 *)(lVar4 + 7000) = *param_2;
  *(undefined4 *)(lVar4 + 0x1b5c) = param_2[1];
  *(undefined4 *)(lVar4 + 0x1b64) = param_2[3];
  *(undefined4 *)(lVar4 + 0x1b68) = param_2[4];
  *(undefined1 *)(lVar4 + 0x1b60) = *(undefined1 *)(param_2 + 2);
  *(undefined1 *)(lVar4 + 0x1b6c) = *(undefined1 *)(param_2 + 5);
  lVar2 = 0;
  do {
    *(undefined4 *)(lVar4 + 0x1bf4 + lVar2) = *(undefined4 *)((long)param_2 + lVar2 + 0x9c);
    lVar2 = lVar2 + 4;
  } while (lVar2 != 0x80);
  lVar3 = lVar3 + uVar6 * 0x148;
  *(undefined4 *)(lVar3 + 0x1c74) = param_2[0x47];
  *(undefined4 *)(lVar3 + 0x1c78) = param_2[0x48];
  *(undefined4 *)(lVar3 + 0x1c7c) = param_2[0x49];
  *(undefined4 *)(lVar3 + 0x1c80) = param_2[0x4a];
  *(undefined4 *)(lVar3 + 0x1c84) = param_2[0x4b];
  *(undefined4 *)(lVar3 + 0x1c88) = param_2[0x4c];
  lVar3 = 0;
  do {
    *(undefined4 *)(lVar4 + 0x1b70 + lVar3) = *(undefined4 *)((long)param_2 + lVar3 + 0x18);
    lVar3 = lVar3 + 4;
  } while (lVar3 != 0x80);
  return;
}


// ===== 00445780 gpumgrGetNvlinkRecoveryInfo_IMPL =====

long gpumgrGetNvlinkRecoveryInfo_IMPL(long param_1)

{
  char *pcVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = 0;
  pcVar1 = (char *)(*(long *)(g_pSys + 0x1e0) + 0x4450);
  while ((*pcVar1 != '\0' && (*(long *)(pcVar1 + 8) != param_1))) {
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
    pcVar1 = pcVar1 + 0x38;
    if (uVar2 == 0x20) {
      return 0;
    }
  }
  return *(long *)(g_pSys + 0x1e0) + 0x4450 + uVar3 * 0x38;
}


// ===== 004457d0 gpumgrCheckIndirectPeer_IMPL =====

undefined8 gpumgrCheckIndirectPeer_IMPL(void)

{
  return 0;
}


// ===== 004457e0 gpumgrSetGpuInitDisabledNvlinks_IMPL =====

int gpumgrSetGpuInitDisabledNvlinks_IMPL
              (int param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_5c [2];
  undefined1 local_54 [4];
  uint local_50 [2];
  undefined8 local_48;
  undefined8 local_40;
  
  iVar6 = 0;
  piVar1 = *(int **)(g_pSys + 0x1e0);
  local_48 = 0;
  local_40 = 0;
  local_5c[0] = param_2;
  gpumgrGetGpuAttachInfo(local_54,local_50);
  do {
    if (((1 << ((byte)iVar6 & 0x1f) & local_50[0]) != 0) &&
       (lVar3 = gpumgrGetGpu(iVar6), param_1 == *(int *)(lVar3 + 0x7ac))) {
      return 0x17;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x20);
  iVar6 = convertLinkMasksToBitVector(local_5c,4,param_3,local_50);
  if (iVar6 == 0) {
    iVar6 = convertBitVectorToLinkMasks(local_50,0,0,&local_48);
    if (iVar6 == 0) {
      portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
      uVar4 = 0;
      piVar5 = piVar1;
      do {
        piVar5 = piVar5 + 0x12;
        if (*piVar5 == param_1) {
          *(undefined8 *)(piVar1 + uVar4 * 0x12 + 0x1a) = local_40;
          *(undefined8 *)(piVar1 + uVar4 * 0x12 + 0x18) = local_48;
          *(undefined1 *)((long)piVar1 + uVar4 * 0x48 + 0x5d) = param_4;
          goto LAB_00445911;
        }
        uVar2 = (int)uVar4 + 1;
        uVar4 = (ulong)uVar2;
      } while (uVar2 != 0x20);
      iVar6 = 0x26;
LAB_00445911:
      portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar6,"convertBitVectorToLinkMasks(&localLinkMask, NULL, 0, &links)",
                 "src/kernel/gpu_mgr/gpu_mgr.c",0xe83);
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar6,"convertLinkMasksToBitVector(&mask, sizeof(mask), pLinks, &localLinkMask)",
               "src/kernel/gpu_mgr/gpu_mgr.c",0xe7f);
  }
  return iVar6;
}


// ===== 00445980 gpumgrGetGpuInitDisabledNvlinks_IMPL =====

undefined8 gpumgrGetGpuInitDisabledNvlinks_IMPL(int param_1,undefined8 *param_2,undefined1 *param_3)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  undefined8 uVar5;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  uVar3 = 0;
  piVar4 = piVar1;
  do {
    piVar4 = piVar4 + 0x12;
    if (*piVar4 == param_1) {
      uVar5 = *(undefined8 *)(piVar1 + uVar3 * 0x12 + 0x1a);
      *param_2 = *(undefined8 *)(piVar1 + uVar3 * 0x12 + 0x18);
      param_2[1] = uVar5;
      *param_3 = *(undefined1 *)((long)piVar1 + uVar3 * 0x48 + 0x5d);
      uVar5 = 0;
      goto LAB_004459f2;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
  } while (uVar2 != 0x20);
  uVar5 = 0x26;
LAB_004459f2:
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return uVar5;
}


// ===== 00445a20 gpumgrGetGpuNvlinkBwMode_IMPL =====

undefined2 gpumgrGetGpuNvlinkBwMode_IMPL(void)

{
  return *(undefined2 *)(*(long *)(g_pSys + 0x1e0) + 0x4448);
}


// ===== 00445a40 gpumgrGetGpuNvlinkBwModeScope_IMPL =====

undefined1 gpumgrGetGpuNvlinkBwModeScope_IMPL(void)

{
  return *(undefined1 *)(*(long *)(g_pSys + 0x1e0) + 0x444a);
}


// ===== 00445a60 gpumgrSetGpuNvlinkBwModeFromRegistry_IMPL =====

void gpumgrSetGpuNvlinkBwModeFromRegistry_IMPL(long param_1)

{
  long lVar1;
  int iVar2;
  ushort uVar3;
  undefined4 local_40;
  short local_3c [2];
  undefined1 local_38 [32];
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  local_40 = 0x20;
  if (((*(byte *)(lVar1 + 0x4448) & 7) != 0) || (*(char *)(lVar1 + 0x444a) != '\0')) {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xefb,"gpumgrSetGpuNvlinkBwModeFromRegistry_IMPL",4,
                 "NVRM: BW mode already set. Cannot override with regkey.\n");
    return;
  }
  if (param_1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0xf00);
  }
  iVar2 = osReadRegistryString(param_1,"RmNvlinkBandwidth",local_38,&local_40);
  if (iVar2 == 0) {
    local_40 = portStringLength(local_38);
    iVar2 = portStringCompare(local_38,&DAT_00d7c410,local_40);
    if (iVar2 == 0) {
      uVar3 = *(ushort *)(lVar1 + 0x4448) & 0xfff8 | 1;
      *(ushort *)(lVar1 + 0x4448) = uVar3;
      goto LAB_00445ad2;
    }
    iVar2 = portStringCompare(local_38,&DAT_00d7c414,local_40);
    if (iVar2 == 0) {
      uVar3 = *(ushort *)(lVar1 + 0x4448) & 0xfff8 | 2;
      *(ushort *)(lVar1 + 0x4448) = uVar3;
      goto LAB_00445ad2;
    }
    iVar2 = portStringCompare(local_38,&DAT_00d7c418,local_40);
    if (iVar2 == 0) {
      uVar3 = *(ushort *)(lVar1 + 0x4448) & 0xfff8 | 3;
      *(ushort *)(lVar1 + 0x4448) = uVar3;
      goto LAB_00445ad2;
    }
    iVar2 = portStringCompare(local_38,"3QUARTER",local_40);
    if (iVar2 == 0) {
      uVar3 = *(ushort *)(lVar1 + 0x4448) & 0xfff8 | 4;
      *(ushort *)(lVar1 + 0x4448) = uVar3;
      goto LAB_00445ad2;
    }
    iVar2 = portStringCompare(local_38,"LINKCOUNT",local_40);
    if (iVar2 == 0) {
      iVar2 = osReadRegistryDword(param_1,"RmNvlinkBandwidthLinkCount",local_3c);
      if (iVar2 == 0) {
        *(undefined1 *)(lVar1 + 0x444a) = 1;
        uVar3 = local_3c[0] * 8 + 5;
        *(ushort *)(lVar1 + 0x4448) = uVar3;
        goto LAB_00445ad2;
      }
    }
  }
  uVar3 = *(ushort *)(lVar1 + 0x4448);
LAB_00445ad2:
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xf2f,"gpumgrSetGpuNvlinkBwModeFromRegistry_IMPL",1,
               "NVRM: nvlinkBwMode=%d\n",uVar3);
  return;
}


// ===== 00445ca0 gpumgrSetGpuNvlinkBwModePerGpu_IMPL =====

ulong gpumgrSetGpuNvlinkBwModePerGpu_IMPL(long param_1,ushort param_2)

{
  long lVar1;
  char cVar2;
  ushort uVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  if (*(char *)(lVar1 + 0x444a) == '\x01') {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xf6c,"gpumgrSetGpuNvlinkBwModePerGpu_IMPL",4,
                 "NVRM: Unable to override bw mode setting in current scope.\n");
  }
  else {
    uVar3 = 0;
    if (*(long *)(param_1 + 0x1ce8) != 0) {
      uVar3 = (ushort)*(byte *)(*(long *)(param_1 + 0x1ce8) + 0x16c0);
    }
    if (param_2 == uVar3) {
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xf73,"gpumgrSetGpuNvlinkBwModePerGpu_IMPL",4,
                   "NVRM: Requested RBM link count is already set.\n");
      return 0;
    }
    cVar2 = _gpumgrIsP2PObjectPresent();
    if (cVar2 == '\0') {
      uVar4 = gpuFabricProbeSetBwModePerGpu(param_1,param_2);
      if ((int)uVar4 == 0) {
        *(undefined1 *)(lVar1 + 0x444a) = 2;
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar4 & 0xffffffff,"gpuFabricProbeSetBwModePerGpu(pGpu, mode)",
                   "src/kernel/gpu_mgr/gpu_mgr.c",0xf7d);
        uVar4 = uVar4 & 0xffffffff;
      }
      return uVar4;
    }
  }
  return 0x17;
}


// ===== 00445dc0 gpumgrSetGpuNvlinkBwMode_IMPL =====

undefined8 gpumgrSetGpuNvlinkBwMode_IMPL(ushort param_1)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  if (*(char *)(lVar1 + 0x444a) == '\x02') {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xf9c,"gpumgrSetGpuNvlinkBwMode_IMPL",4,
                 "NVRM: Unable to override bw mode setting in current scope\n");
  }
  else {
    if (*(ushort *)(lVar1 + 0x4448) == param_1) {
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0xfa2,"gpumgrSetGpuNvlinkBwMode_IMPL",1,
                   "NVRM: Requested BW mode is already set.\n");
      return 0;
    }
    cVar2 = _gpumgrIsP2PObjectPresent();
    if (cVar2 == '\0') {
      uVar3 = 0x1f;
      if (((param_1 & 7) < 5) && (uVar3 = gpuFabricProbeSetBwMode(param_1), (int)uVar3 == 0)) {
        *(ushort *)(lVar1 + 0x4448) = param_1;
        *(bool *)(lVar1 + 0x444a) = (param_1 & 7) != 0;
        return uVar3;
      }
      return uVar3;
    }
  }
  return 0x17;
}


// ===== 00445ee0 gpumgrAddSystemMIGInstanceTopo_IMPL =====

void gpumgrAddSystemMIGInstanceTopo_IMPL(long param_1)

{
  long lVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  ulong uVar5;
  long lVar6;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  pcVar2 = (char *)(lVar1 + 0x4b50);
  pcVar4 = pcVar2;
  while ((*pcVar4 == '\0' || (param_1 != *(long *)(pcVar4 + 8)))) {
    pcVar4 = pcVar4 + 0x1c98;
    if (pcVar4 == (char *)(lVar1 + 0x3de50)) {
      uVar5 = 0;
      do {
        if (*pcVar2 == '\0') {
          lVar6 = uVar5 * 0x1c98;
          *(undefined1 *)(lVar1 + 0x4b50 + lVar6) = 1;
          *(long *)(lVar1 + 0x4b58 + lVar6) = param_1;
          *(undefined1 *)(lVar1 + 0x4b61 + lVar6) = 0;
          return;
        }
        uVar3 = (int)uVar5 + 1;
        uVar5 = (ulong)uVar3;
        pcVar2 = pcVar2 + 0x1c98;
      } while (uVar3 != 0x20);
      nvAssertFailedNoLog("i < NV_ARRAY_ELEMENTS(pGpuMgr->MIGTopologyInfo)",
                          "src/kernel/gpu_mgr/gpu_mgr.c",0xfe7);
      return;
    }
  }
  return;
}


// ===== 00445f70 gpumgrGetSystemMIGInstanceTopo_IMPL =====

undefined8 gpumgrGetSystemMIGInstanceTopo_IMPL(long param_1,long *param_2)

{
  uint uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  pcVar3 = (char *)(*(long *)(g_pSys + 0x1e0) + 0x4b50);
  while ((*pcVar3 == '\0' || (*(long *)(pcVar3 + 8) != param_1))) {
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    pcVar3 = pcVar3 + 0x1c98;
    if (uVar1 == 0x20) {
      return 0;
    }
  }
  if (param_2 != (long *)0x0) {
    *param_2 = *(long *)(g_pSys + 0x1e0) + 0x4b50 + uVar2 * 0x1c98;
  }
  return 1;
}


// ===== 00445fd0 gpumgrIsSystemMIGEnabled_IMPL =====

undefined1 gpumgrIsSystemMIGEnabled_IMPL(long param_1)

{
  char *pcVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = 0;
  pcVar1 = (char *)(*(long *)(g_pSys + 0x1e0) + 0x4b50);
  while ((*pcVar1 == '\0' || (*(long *)(pcVar1 + 8) != param_1))) {
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
    pcVar1 = pcVar1 + 0x1c98;
    if (uVar2 == 0x20) {
      return 0;
    }
  }
  return *(undefined1 *)(*(long *)(g_pSys + 0x1e0) + 0x4b61 + uVar3 * 0x1c98);
}


// ===== 00446020 gpumgrSetSystemMIGEnabled_IMPL =====

void gpumgrSetSystemMIGEnabled_IMPL(long param_1,undefined1 param_2)

{
  char *pcVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = 0;
  pcVar1 = (char *)(*(long *)(g_pSys + 0x1e0) + 0x4b50);
  while ((*pcVar1 == '\0' || (*(long *)(pcVar1 + 8) != param_1))) {
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
    pcVar1 = pcVar1 + 0x1c98;
    if (uVar2 == 0x20) {
      return;
    }
  }
  *(undefined1 *)(*(long *)(g_pSys + 0x1e0) + 0x4b61 + uVar3 * 0x1c98) = param_2;
  return;
}


// ===== 00446070 __pfx_gpumgrUnregisterRmCapsForMIGGI_IMPL =====

void __pfx_gpumgrUnregisterRmCapsForMIGGI_IMPL(long param_1)

{
  long lVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  uVar4 = 0;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  pcVar2 = (char *)(lVar1 + 0x4b50);
  while ((*pcVar2 == '\0' || (param_1 != *(long *)(pcVar2 + 8)))) {
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    pcVar2 = pcVar2 + 0x1c98;
    if (uVar3 == 0x20) {
      return;
    }
  }
  lVar8 = 0;
  lVar7 = lVar1 + 0x4f58 + uVar4 * 0x1c98;
  do {
    if (*(char *)(lVar7 + -0x3f0) != '\0') {
      lVar5 = lVar7 + -0x340;
      do {
        while (*(char *)(lVar5 + -0x60) != '\0') {
          lVar6 = lVar5 + 0x68;
          osRmCapUnregister(lVar5);
          *(undefined1 *)(lVar5 + -0x60) = 0;
          lVar5 = lVar6;
          if (lVar6 == lVar7) goto LAB_00446157;
        }
        lVar5 = lVar5 + 0x68;
      } while (lVar5 != lVar7);
LAB_00446157:
      osRmCapUnregister(lVar7 + -0x3a8);
      *(undefined1 *)(lVar7 + -0x3f0) = 0;
    }
    lVar8 = lVar8 + 0x390;
    lVar7 = lVar7 + 0x390;
    if (lVar8 == 0x1c80) {
      *(undefined1 *)(lVar1 + 0x4b60 + uVar4 * 0x1c98) = 0;
      return;
    }
  } while( true );
}


// ===== 00446080 gpumgrUnregisterRmCapsForMIGGI_IMPL =====

void gpumgrUnregisterRmCapsForMIGGI_IMPL(long param_1)

{
  long lVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  uVar4 = 0;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  pcVar2 = (char *)(lVar1 + 0x4b50);
  while ((*pcVar2 == '\0' || (param_1 != *(long *)(pcVar2 + 8)))) {
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    pcVar2 = pcVar2 + 0x1c98;
    if (uVar3 == 0x20) {
      return;
    }
  }
  lVar8 = 0;
  lVar7 = lVar1 + 0x4f58 + uVar4 * 0x1c98;
  do {
    if (*(char *)(lVar7 + -0x3f0) != '\0') {
      lVar5 = lVar7 + -0x340;
      do {
        while (*(char *)(lVar5 + -0x60) != '\0') {
          lVar6 = lVar5 + 0x68;
          osRmCapUnregister(lVar5);
          *(undefined1 *)(lVar5 + -0x60) = 0;
          lVar5 = lVar6;
          if (lVar6 == lVar7) goto LAB_00446157;
        }
        lVar5 = lVar5 + 0x68;
      } while (lVar5 != lVar7);
LAB_00446157:
      osRmCapUnregister(lVar7 + -0x3a8);
      *(undefined1 *)(lVar7 + -0x3f0) = 0;
    }
    lVar8 = lVar8 + 0x390;
    lVar7 = lVar7 + 0x390;
    if (lVar8 == 0x1c80) {
      *(undefined1 *)(lVar1 + 0x4b60 + uVar4 * 0x1c98) = 0;
      return;
    }
  } while( true );
}


// ===== 004461c0 _gpumgrUnregisterRmCapsForGpuUnderLock =====

void _gpumgrUnregisterRmCapsForGpuUnderLock(long param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  ulong uVar4;
  
  piVar1 = *(int **)(g_pSys + 0x1e0);
  gpumgrUnregisterRmCapsForMIGGI_IMPL();
  uVar4 = 0;
  piVar2 = piVar1;
  while ((*(long *)(piVar2 + 0x14) != param_1 || (piVar2[0x12] == -1))) {
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar2 = piVar2 + 0x12;
    if (uVar3 == 0x20) {
      return;
    }
  }
  osRmCapUnregister(piVar1 + uVar4 * 0x12 + 0x22);
  return;
}


// ===== 00446240 gpumgrCacheCreateGpuInstance_IMPL =====

void gpumgrCacheCreateGpuInstance_IMPL(long param_1,undefined4 param_2)

{
  char *pcVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  int *piVar6;
  
  lVar2 = *(long *)(g_pSys + 0x1e0);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x3de50));
  piVar6 = (int *)(lVar2 + 0x3de5c);
  uVar4 = 0;
  do {
    if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
      pcVar5 = (char *)(lVar2 + 0x3de60 + uVar4 * 0x88);
      pcVar1 = pcVar5 + 0x80;
      goto LAB_004462d0;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar6 = piVar6 + 0x22;
  } while (uVar3 != 0x20);
  nvAssertFailedNoLog("pGpuInstances != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x10ab);
  goto LAB_004462f6;
  while (pcVar5 = pcVar5 + 0x10, pcVar5 != pcVar1) {
LAB_004462d0:
    if (*pcVar5 == '\0') {
      *pcVar5 = '\x01';
      *(undefined4 *)(pcVar5 + 4) = param_2;
      goto LAB_004462f6;
    }
  }
  nvAssertFailedNoLog("!\"Unreachable\"","src/kernel/gpu_mgr/gpu_mgr.c",0x10b7);
LAB_004462f6:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x3de50));
  return;
}


// ===== 00446340 gpumgrCacheDestroyGpuInstance_IMPL =====

void gpumgrCacheDestroyGpuInstance_IMPL(long param_1,int param_2)

{
  char *pcVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  int *piVar6;
  
  lVar2 = *(long *)(g_pSys + 0x1e0);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x3de50));
  piVar6 = (int *)(lVar2 + 0x3de5c);
  uVar4 = 0;
  do {
    if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
      pcVar5 = (char *)(lVar2 + 0x3de60 + uVar4 * 0x88);
      pcVar1 = pcVar5 + 0x80;
      goto LAB_004463d0;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar6 = piVar6 + 0x22;
  } while (uVar3 != 0x20);
  nvAssertFailedNoLog("pGpuInstances != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x10d0);
  goto LAB_004463fc;
  while (pcVar5 = pcVar5 + 0x10, pcVar5 != pcVar1) {
LAB_004463d0:
    if ((*pcVar5 != '\0') && (*(int *)(pcVar5 + 4) == param_2)) {
      *pcVar5 = '\0';
      goto LAB_004463fc;
    }
  }
  nvAssertFailedNoLog("!\"Unreachable\"","src/kernel/gpu_mgr/gpu_mgr.c",0x10dc);
LAB_004463fc:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x3de50));
  return;
}


// ===== 00446440 gpumgrCacheCreateComputeInstance_IMPL =====

void gpumgrCacheCreateComputeInstance_IMPL(long param_1,int param_2,ulong param_3)

{
  char *pcVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  int *piVar6;
  
  lVar2 = *(long *)(g_pSys + 0x1e0);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x3de50));
  piVar6 = (int *)(lVar2 + 0x3de5c);
  uVar4 = 0;
  do {
    if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
      pcVar5 = (char *)(lVar2 + 0x3de60 + uVar4 * 0x88);
      pcVar1 = pcVar5 + 0x80;
      goto LAB_004464d0;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar6 = piVar6 + 0x22;
  } while (uVar3 != 0x20);
  nvAssertFailedNoLog("pGpuInstances != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x10f5);
  goto LAB_004464fc;
  while (pcVar5 = pcVar5 + 0x10, pcVar5 != pcVar1) {
LAB_004464d0:
    if ((*pcVar5 != '\0') && (*(int *)(pcVar5 + 4) == param_2)) {
      pcVar5[(param_3 & 0xffffffff) + 8] = '\x01';
      goto LAB_004464fc;
    }
  }
  nvAssertFailedNoLog("!\"Unreachable\"","src/kernel/gpu_mgr/gpu_mgr.c",0x1101);
LAB_004464fc:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x3de50));
  return;
}


// ===== 00446540 gpumgrCacheDestroyComputeInstance_IMPL =====

void gpumgrCacheDestroyComputeInstance_IMPL(long param_1,int param_2,ulong param_3)

{
  char *pcVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  int *piVar6;
  
  lVar2 = *(long *)(g_pSys + 0x1e0);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x3de50));
  piVar6 = (int *)(lVar2 + 0x3de5c);
  uVar4 = 0;
  do {
    if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
      pcVar5 = (char *)(lVar2 + 0x3de60 + uVar4 * 0x88);
      pcVar1 = pcVar5 + 0x80;
      goto LAB_004465d0;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar6 = piVar6 + 0x22;
  } while (uVar3 != 0x20);
  nvAssertFailedNoLog("pGpuInstances != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x111a);
  goto LAB_004465fc;
  while (pcVar5 = pcVar5 + 0x10, pcVar5 != pcVar1) {
LAB_004465d0:
    if ((*pcVar5 != '\0') && (*(int *)(pcVar5 + 4) == param_2)) {
      pcVar5[(param_3 & 0xffffffff) + 8] = '\0';
      goto LAB_004465fc;
    }
  }
  nvAssertFailedNoLog("!\"Unreachable\"","src/kernel/gpu_mgr/gpu_mgr.c",0x1126);
LAB_004465fc:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x3de50));
  return;
}


// ===== 00446640 gpumgrCacheSetMIGEnabled_IMPL =====

void gpumgrCacheSetMIGEnabled_IMPL(long param_1,char param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  long lVar8;
  
  iVar1 = *(int *)(param_1 + 0x7ac);
  lVar2 = *(long *)(g_pSys + 0x1e0);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x3de50));
  pcVar6 = (char *)(lVar2 + 0x3de58);
  uVar4 = 0;
  pcVar3 = pcVar6;
  do {
    if ((*pcVar3 != '\0') && (*(int *)(pcVar3 + 4) == iVar1)) {
      lVar8 = lVar2 + 0x3de58 + uVar4 * 0x88;
      *(char *)(lVar8 + 1) = param_2;
      if (param_2 != '\0') goto LAB_00446730;
      goto LAB_00446700;
    }
    uVar7 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar7;
    pcVar3 = pcVar3 + 0x88;
  } while (uVar7 != 0x20);
  uVar4 = 0;
  do {
    if (*pcVar6 == '\0') {
      lVar5 = uVar4 * 0x88;
      lVar8 = lVar2 + 0x3de58 + lVar5;
      *(undefined1 *)(lVar2 + 0x3de58 + lVar5) = 1;
      *(int *)(lVar2 + 0x3de5c + lVar5) = iVar1;
      *(char *)(lVar8 + 1) = param_2;
      if (param_2 == '\0') {
LAB_00446700:
        portMemSet(lVar8 + 8,0,0x80);
      }
      goto LAB_00446730;
    }
    uVar7 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar7;
    pcVar6 = pcVar6 + 0x88;
  } while (uVar7 != 0x20);
  nvAssertFailedNoLog("pMIGInfo != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x1150);
LAB_00446730:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x3de50));
  return;
}


// ===== 00446760 gpumgrCacheGetActiveDeviceIds_IMPL =====

undefined8 gpumgrCacheGetActiveDeviceIds_IMPL(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  bool bVar4;
  ulong uVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  undefined8 uVar9;
  uint uVar10;
  uint *puVar11;
  uint local_1a8 [32];
  uint local_128 [64];
  
  gpumgrGetProbedGpuIds(local_1a8);
  lVar3 = *(long *)(g_pSys + 0x1e0);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar3 + 0x3de50));
  puVar11 = local_1a8;
  uVar10 = 0;
  do {
    uVar1 = *puVar11;
    if (uVar1 == 0xffffffff) break;
    pcVar8 = (char *)(lVar3 + 0x3dee0);
    bVar4 = false;
    do {
      while ((pcVar8[-0x88] == '\0' || (*(uint *)(pcVar8 + -0x84) != uVar1))) {
        pcVar8 = pcVar8 + 0x88;
        if (pcVar8 == (char *)(lVar3 + 0x3efe0)) goto LAB_00446830;
      }
      if (pcVar8[-0x87] == '\0') break;
      pcVar7 = pcVar8 + -0x80;
      do {
        if (*pcVar7 != '\0') {
          uVar2 = *(uint *)(pcVar7 + 4);
          lVar6 = 0;
          do {
            if (pcVar7[lVar6 + 8] != '\0') {
              if (0xff < uVar10) {
                nvAssertFailedNoLog("total < NV0000_CTRL_GPU_MAX_ACTIVE_DEVICES",
                                    "src/kernel/gpu_mgr/gpu_mgr.c",0x119a);
                goto LAB_004468cd;
              }
              uVar5 = (ulong)uVar10;
              uVar10 = uVar10 + 1;
              param_1[uVar5 * 3 + 1] = uVar1;
              param_1[uVar5 * 3 + 2] = uVar2;
              param_1[uVar5 * 3 + 3] = (uint)lVar6;
            }
            lVar6 = lVar6 + 1;
          } while (lVar6 != 8);
        }
        pcVar7 = pcVar7 + 0x10;
      } while (pcVar8 != pcVar7);
      pcVar8 = pcVar8 + 0x88;
      bVar4 = true;
    } while (pcVar8 != (char *)(lVar3 + 0x3efe0));
LAB_00446830:
    if (!bVar4) {
      if (0xff < uVar10) {
        nvAssertFailedNoLog("total < NV0000_CTRL_GPU_MAX_ACTIVE_DEVICES",
                            "src/kernel/gpu_mgr/gpu_mgr.c",0x11a9);
LAB_004468cd:
        uVar9 = 0x40;
        goto LAB_004468d2;
      }
      uVar5 = (ulong)uVar10;
      uVar10 = uVar10 + 1;
      param_1[uVar5 * 3 + 1] = uVar1;
      (param_1 + uVar5 * 3 + 2)[0] = 0xffffffff;
      (param_1 + uVar5 * 3 + 2)[1] = 0xffffffff;
    }
    puVar11 = puVar11 + 1;
  } while (puVar11 != local_128);
  *param_1 = uVar10;
  uVar9 = 0;
LAB_004468d2:
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar3 + 0x3de50));
  return uVar9;
}


// ===== 00446920 gpumgrSetCurrentGpuInstance =====

undefined4 gpumgrSetCurrentGpuInstance(int param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  char cVar4;
  long lVar5;
  long *plVar6;
  
  cVar4 = portUtilIsInterruptContext();
  if (cVar4 == '\0') {
    if (g_pSys == 0) {
      nvAssertFailedNoLog("pSys != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x11c7);
    }
    else {
      lVar2 = *(long *)(g_pSys + 0x1e0);
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pGpuMgr != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x11ca);
      }
      else {
        lVar5 = portThreadGetCurrentThreadId();
        plVar6 = (long *)(lVar2 + 0x3f298);
        do {
          if (lVar5 == *plVar6) goto LAB_004469a5;
          plVar6 = plVar6 + 2;
          plVar3 = (long *)(lVar2 + 0x3f298);
        } while (plVar6 != (long *)(lVar2 + 0x3f318));
        do {
          plVar6 = plVar3;
          LOCK();
          lVar1 = *plVar6;
          if (lVar1 == -1) {
            *plVar6 = lVar5;
          }
          UNLOCK();
          if (lVar1 == -1) {
LAB_004469a5:
            lVar2 = plVar6[1];
            *(int *)(plVar6 + 1) = param_1;
            if (param_1 == -1) {
              LOCK();
              *plVar6 = -1;
              UNLOCK();
              return (int)lVar2;
            }
            return (int)lVar2;
          }
          plVar3 = plVar6 + 2;
        } while (plVar6 + 2 != (long *)(lVar2 + 0x3f318));
      }
    }
  }
  return 0xffffffff;
}


// ===== 00446a40 gpumgrAttachGpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpumgrAttachGpu(undefined4 param_1,ulong *param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  ulong uVar4;
  ulong uVar5;
  int *piVar6;
  char cVar7;
  char cVar8;
  undefined1 uVar9;
  int iVar10;
  undefined4 uVar11;
  long lVar12;
  ulong *puVar13;
  long lVar14;
  undefined8 uVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  uint uVar19;
  ulong uVar20;
  undefined4 uVar21;
  uint uVar22;
  bool bVar23;
  byte local_e0;
  ulong local_d0;
  undefined8 local_c8;
  ulong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  ulong local_88;
  undefined8 local_80;
  ulong local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  lVar16 = g_pSys;
  lVar2 = *(long *)(g_pSys + 0x1e0);
  cVar7 = rmapiLockIsOwner();
  lVar14 = g_pSys;
  if (cVar7 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu_mgr/gpu_mgr.c",0x5f0);
    return 0x2f;
  }
  lVar17 = *(long *)(g_pSys + 0x1e0);
  if ((char)param_2[0x22c] == '\0') {
    if ((char)param_2[0xc] != '\0') {
      uVar21 = (undefined4)param_2[0x22a];
      cVar7 = (char)param_2[0x22b];
      uVar11 = uVar21;
      goto joined_r0x00446e07;
    }
    local_d0 = *param_2;
    local_c8 = 0;
    local_c0 = param_2[8];
    local_b8 = 0;
    local_b0 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_98 = 0;
    local_90 = 0;
    uVar11 = osDevReadReg032(0,&local_d0,0);
    uVar22 = osDevReadReg032(0,&local_d0,0xa00);
    local_88 = *param_2;
    local_78 = param_2[8];
    local_80 = 0;
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    uVar19 = osDevReadReg032(0,&local_88,4);
    uVar19 = uVar19 & 0x30000;
    bVar23 = (int)param_2[0x22a] != 0;
    if ((char)param_2[0x22b] == '\0') {
      uVar15 = 0;
      uVar21 = 0;
      iVar10 = (uVar19 != 0x20000) + 1 + (uint)(uVar19 != 0x20000);
    }
    else if ((uVar22 >> 0x18 & 0x3f) < 0x16) {
      uVar21 = 0;
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x482,"gpumgrCheckRmFirmwarePolicy",4,
                   "NVRM: Disabling GSP offload -- GPU not supported\n");
      uVar15 = 0;
      if (uVar19 != 0x20000) goto LAB_00446af3;
      iVar10 = 1;
    }
    else {
      uVar21 = 0;
      iVar10 = 2 - (uint)(uVar19 == 0x20000);
      uVar15 = 1;
    }
  }
  else {
    if (*(char *)((long)param_2 + 0x1161) == '\0') {
      uVar11 = (undefined4)param_2[0x2a2];
      uVar21 = uVar11;
      if ((char)param_2[0x22b] != '\0') {
        bVar23 = false;
        uVar15 = 1;
        uVar22 = 0;
        iVar10 = 2;
        goto LAB_00446af9;
      }
    }
    else {
      uVar11 = osDevReadReg032(0,param_2 + 0x22d,0);
      uVar21 = (undefined4)param_2[0x2a2];
      cVar7 = (char)param_2[0x22b];
joined_r0x00446e07:
      if (cVar7 != '\0') {
        nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x482,"gpumgrCheckRmFirmwarePolicy",4,
                     "NVRM: Disabling GSP offload -- GPU not supported\n");
      }
    }
    uVar22 = 0;
    bVar23 = false;
LAB_00446af3:
    uVar15 = 0;
    iVar10 = 3;
  }
LAB_00446af9:
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x50d,"gpumgrGetGpuHalFactor",1,
               "NVRM: ChipId0[0x%x] ChipId1[0x%x] SocChipId0[0x%x] isFwClient[%d] RmVariant[%d] tegraType[%d]\n"
               ,uVar11,uVar22,uVar21,uVar15,iVar10,bVar23);
  lVar12 = gpumgrGetGpuArch_IMPL(uVar22,uVar21,bVar23);
  local_e0 = (byte)param_1;
  if (lVar12 != 0) {
    uVar20 = param_2[7];
    piVar3 = *(int **)(g_pSys + 0x1e0);
    portSyncMutexAcquire(*(undefined8 *)(piVar3 + 0x252));
    uVar18 = 0;
    piVar6 = piVar3;
    while( true ) {
      iVar1 = piVar6[0x12];
      if ((iVar1 != -1) && (uVar20 == *(ulong *)(piVar6 + 0x14))) break;
      uVar19 = (int)uVar18 + 1;
      uVar18 = (ulong)uVar19;
      piVar6 = piVar6 + 0x12;
      if (uVar19 == 0x20) goto LAB_00446e18;
    }
    if ((char)piVar3[uVar18 * 0x12 + 0x17] == '\0') {
      portSyncMutexRelease(*(undefined8 *)(piVar3 + 0x252));
      puVar13 = (ulong *)0x0;
    }
    else {
      portMemCopy(&local_88,0x10,piVar3 + uVar18 * 0x12 + 0x1d,0x10);
      portSyncMutexRelease(*(undefined8 *)(piVar3 + 0x252));
      puVar13 = &local_88;
    }
    iVar10 = __nvoc_objCreate_OBJGPU
                       (&local_d0,lVar14,0,*(undefined4 *)(lVar12 + 0x84),
                        *(undefined4 *)(lVar12 + 0x88),*(undefined4 *)(lVar12 + 0x8c),
                        *(undefined4 *)(lVar12 + 0x90),iVar10,0,param_1,iVar1,puVar13,lVar12);
    if (iVar10 != 0) goto LAB_00446e4d;
    iVar10 = gpuBindHalLegacy_IMPL(local_d0,uVar11,uVar22,uVar21);
    if (iVar10 != 0) {
      __nvoc_objDelete();
      goto LAB_00446e4d;
    }
    uVar22 = *(uint *)(lVar17 + 0x3f158);
    lVar14 = (ulong)uVar22 * 0x10;
    *(ulong *)(lVar17 + 0x3ef58 + lVar14) = local_d0;
    *(undefined4 *)(lVar17 + 0x3ef60 + lVar14) = param_1;
    *(uint *)(lVar17 + 0x3f158) = uVar22 + 1;
    lVar14 = gpumgrGetGpu(param_1);
    uVar11 = gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar14 + 0x7a4));
    if ((char)param_2[0x22c] == '\0') {
      if ((char)param_2[0xc] == '\0') {
        *(undefined1 *)(lVar14 + 0x7a0) = 0;
        uVar20 = *param_2;
        *(ulong *)(lVar14 + 0x938) = uVar20;
        *(ulong *)(lVar14 + 0x3a20) = param_2[1];
        uVar18 = param_2[3];
        *(ulong *)(lVar14 + 0x848) = uVar18;
        *(ulong *)(lVar14 + 0x850) = param_2[4];
        uVar4 = param_2[5];
        *(ulong *)(lVar14 + 0x858) = uVar4;
        *(ulong *)(lVar14 + 0x860) = param_2[6];
        *(undefined4 *)(lVar14 + 0x868) = *(undefined4 *)((long)param_2 + 0x1154);
        uVar5 = param_2[7];
        *(undefined1 *)(lVar14 + 0x880) = 1;
        *(ulong *)(lVar14 + 0x878) = uVar5;
        *(ulong *)(lVar14 + 0x948) = param_2[8];
        *(ulong *)(lVar14 + 0x910) = param_2[9];
        uVar21 = *(undefined4 *)((long)param_2 + 0x54);
        *(undefined4 *)(lVar14 + 0x934) = 1;
        *(undefined4 *)(lVar14 + 0x86c) = uVar21;
        *(undefined4 *)(lVar14 + 0x7c0) = *(undefined4 *)((long)param_2 + 0x115c);
        if (param_2[2] == 0) {
          *(undefined1 *)(lVar14 + 0x91c) = 0;
          *(ulong *)(lVar14 + 0x3a28) = uVar20 + 0x700000;
          if (uVar4 == 0) {
            *(ulong *)(lVar14 + 0x858) = uVar18 + 0x700000;
          }
          *(undefined4 *)(lVar14 + 0x918) = 0x100000;
        }
        else {
          *(undefined1 *)(lVar14 + 0x91c) = 1;
          *(ulong *)(lVar14 + 0x3a28) = param_2[2];
          *(int *)(lVar14 + 0x918) = (int)param_2[10];
        }
      }
      else {
        *(undefined1 *)(lVar14 + 0x7a0) = 1;
        *(int *)(lVar14 + 0x7f4) = (int)param_2[0x229];
        *(undefined4 *)(lVar14 + 0x7fc) = *(undefined4 *)((long)param_2 + 0x114c);
        *(undefined4 *)(lVar14 + 0x868) = *(undefined4 *)((long)param_2 + 0x1154);
      }
    }
    else {
      *(undefined1 *)(lVar14 + 0x7a0) = 1;
      lVar17 = 0x1f8;
      if ((~-(uint)(*(char *)((long)param_2 + 0x1161) == '\0') & 0xfffffffa) != 0) {
        lVar17 = 0x3a8;
      }
      lVar12 = 0;
      do {
        *(undefined8 *)(lVar14 + 0x938 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1168);
        *(undefined8 *)(lVar14 + 0x940 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1170);
        *(undefined8 *)(lVar14 + 0x948 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1178);
        *(undefined8 *)(lVar14 + 0x950 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1180);
        *(undefined8 *)(lVar14 + 0x958 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1188);
        *(undefined8 *)(lVar14 + 0x960 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1190);
        *(undefined8 *)(lVar14 + 0x968 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x1198);
        *(undefined8 *)(lVar14 + 0x970 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x11a0);
        *(undefined8 *)(lVar14 + 0x978 + lVar12) = *(undefined8 *)((long)param_2 + lVar12 + 0x11a8);
        lVar12 = lVar12 + 0x48;
      } while (lVar17 != lVar12);
      *(undefined4 *)(lVar14 + 0x868) = *(undefined4 *)((long)param_2 + 0x1514);
      cVar7 = *(char *)((long)param_2 + 0x1161);
      *(undefined8 *)(lVar14 + 0x848) = *(undefined8 *)(lVar14 + 0x940);
      if (cVar7 == '\0') {
        *(undefined4 *)(lVar14 + 0x934) = 1;
      }
      else {
        *(undefined4 *)(lVar14 + 0x934) = 0xd;
      }
    }
    *(undefined4 *)(lVar14 + 0x884) = 0;
    uVar15 = sysGetOs_IMPL(lVar16);
    *(undefined8 *)(lVar14 + 0x1b48) = uVar15;
    iVar10 = osDpcAttachGpu(lVar14,param_2[0xb]);
    uVar22 = 1 << (local_e0 & 0x1f);
    if ((iVar10 == 0) && (iVar10 = osAttachGpu(lVar14,param_2[0xb]), iVar10 == 0)) {
      uVar19 = *(uint *)(lVar2 + 0x95c);
      if ((uVar22 & uVar19) != 0) {
        nvAssertFailedNoLog("(pGpuMgr->gpuAttachMask & NVBIT(gpuInstance)) == 0",
                            "src/kernel/gpu_mgr/gpu_mgr.c",0x61b);
        uVar19 = *(uint *)(lVar2 + 0x95c);
      }
      *(uint *)(lVar2 + 0x95c) = uVar19 | uVar22;
      lVar16 = g_pSys;
      *(int *)(lVar2 + 0x958) = *(int *)(lVar2 + 0x958) + 1;
      piVar3 = *(int **)(lVar16 + 0x1e0);
      portSyncMutexAcquire(*(undefined8 *)(piVar3 + 0x252));
      uVar19 = 0;
      piVar6 = piVar3;
      do {
        uVar20 = (ulong)uVar19;
        if (((*(long *)(piVar6 + 0x14) == 0) && (*(char *)(lVar14 + 0x7a0) != '\0')) ||
           ((*(long *)(piVar6 + 0x14) == *(long *)(lVar14 + 0x878) && (piVar6[0x12] != -1)))) {
          if (*(long *)(piVar3 + uVar20 * 0x12 + 0x22) == 0) {
            iVar10 = osRmCapRegisterGpu(*(undefined8 *)(lVar14 + 0x4e0),
                                        piVar3 + uVar20 * 0x12 + 0x22);
            *(undefined8 *)(lVar14 + 0x4e8) = *(undefined8 *)(piVar3 + uVar20 * 0x12 + 0x22);
            if (iVar10 != 0) goto LAB_00447382;
          }
          else {
            *(long *)(lVar14 + 0x4e8) = *(long *)(piVar3 + uVar20 * 0x12 + 0x22);
          }
          portSyncMutexRelease(*(undefined8 *)(piVar3 + 0x252));
          iVar10 = gpuPostConstruct_IMPL(lVar14,param_2);
          if (iVar10 == 0) {
            local_d0 = local_d0 & 0xffffffff00000000;
            iVar10 = gpuGetClassList_IMPL(lVar14,&local_d0,0,0xe97b6c00);
            if ((iVar10 == 0) && ((int)local_d0 != 0)) {
              *(undefined4 *)(lVar14 + 0x49e0) = 0;
              lVar16 = gpuGetStaticInfo(lVar14);
              if (*(char *)(lVar14 + 0x908) == '\0') {
                local_88 = local_88 & 0xffffffff00000000;
                *(undefined4 *)(lVar14 + 0x49e0) = 1;
                iVar10 = osReadRegistryDword(lVar14,"EncSessionStatsReportingState",&local_88);
                if (iVar10 == 0) {
                  if ((int)local_88 == 0) {
                    *(undefined4 *)(lVar14 + 0x49e0) = 0;
                  }
                  else if ((int)local_88 == 1) goto LAB_00447897;
                }
              }
              else if (lVar16 == 0) {
LAB_00447897:
                *(undefined4 *)(lVar14 + 0x49e0) = 1;
              }
              else {
                *(undefined4 *)(lVar14 + 0x49e0) = *(undefined4 *)(lVar16 + 0xa7a8);
              }
            }
            else {
              *(undefined4 *)(lVar14 + 0x49e0) = 2;
            }
            lVar16 = *(long *)(lVar14 + 0x1c20);
            if ((lVar16 != 0) &&
               (iVar10 = (**(code **)(lVar16 + 0x328))(lVar14,lVar16,0), iVar10 != 0)) {
              (**(code **)(lVar16 + 800))(lVar14,lVar16,0,0);
              (**(code **)(lVar16 + 0x1c8))(lVar14,lVar16,0,0);
            }
            gpumgrAddSystemNvlinkTopo_IMPL(param_2[7]);
            gpumgrAddSystemMIGInstanceTopo_IMPL(param_2[7]);
            bVar23 = false;
            if (*(long *)(lVar14 + 0x1d18) != 0) {
              bVar23 = *(char *)(*(long *)(lVar14 + 0x1d18) + 0x2a8) != '\0';
            }
            uVar19 = *(uint *)(lVar2 + 0x95c);
            if ((uVar19 != 0) && ((uVar19 - 1 & uVar19) == 0)) {
              *(undefined1 *)(lVar2 + 0x3f15c) = 0;
              uVar9 = *(undefined1 *)(lVar14 + 0x4ae);
              *(bool *)(lVar2 + 0x3f15e) = bVar23;
              *(undefined1 *)(lVar2 + 0x3f15d) = uVar9;
              uVar9 = gpuIsCCDevToolsModeEnabled_IMPL(lVar14);
              *(undefined1 *)(lVar2 + 0x3f15f) = uVar9;
              uVar9 = gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(lVar14);
              *(undefined1 *)(lVar2 + 0x3f161) = uVar9;
              uVar9 = gpuIsCCMultiGpuNvleModeEnabled_IMPL(lVar14);
              *(undefined1 *)(lVar2 + 0x3f162) = uVar9;
              *(bool *)(lVar2 + 0x3f160) = *(char *)(lVar2 + 0x3f15f) != '\0';
LAB_004472cf:
              if ((*(char *)(lVar14 + 0x909) == '\0') && (*(char *)(lVar14 + 0x90a) == '\0')) {
                *(uint *)(lVar2 + 0x960) = *(uint *)(lVar2 + 0x960) | uVar22;
              }
              gpumgrSetCurrentGpuInstance(uVar11);
              return 0;
            }
            if ((bool)*(char *)(lVar2 + 0x3f15e) == bVar23) {
              if ((bVar23 == false) || (*(byte *)(lVar14 + 0x4ae) == *(byte *)(lVar2 + 0x3f15d))) {
                cVar7 = *(char *)(lVar2 + 0x3f15f);
                *(byte *)(lVar2 + 0x3f15d) = *(byte *)(lVar14 + 0x4ae) & *(byte *)(lVar2 + 0x3f15d);
                cVar8 = gpuIsCCDevToolsModeEnabled_IMPL(lVar14);
                if (cVar7 == cVar8) {
                  cVar7 = *(char *)(lVar2 + 0x3f161);
                  cVar8 = gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(lVar14);
                  if ((cVar7 == cVar8) ||
                     (cVar7 = *(char *)(lVar2 + 0x3f162),
                     cVar8 = gpuIsCCMultiGpuNvleModeEnabled_IMPL(lVar14), cVar7 == cVar8))
                  goto LAB_004472cf;
                  nvAssertFailedNoLog("(pGpuMgr->ccCaps.bMultiGpuProtectedPcieModeEnabled == gpuIsCCMultiGpuProtectedPcieModeEnabled(pGpu) || pGpuMgr->ccCaps.bMultiGpuNvleModeEnabled == gpuIsCCMultiGpuNvleModeEnabled(pGpu))"
                                      ,"src/kernel/gpu_mgr/gpu_mgr.c",0xba);
                }
                else {
                  nvAssertFailedNoLog("pGpuMgr->ccCaps.bDevToolsModeEnabled == gpuIsCCDevToolsModeEnabled(pGpu)"
                                      ,"src/kernel/gpu_mgr/gpu_mgr.c",0xb6);
                }
              }
              else {
                nvAssertFailedNoLog("pGpuMgr->ccCaps.bHccFeatureCapable == pGpu->getProperty(pGpu, PDB_PROP_GPU_CC_FEATURE_CAPABLE)"
                                    ,"src/kernel/gpu_mgr/gpu_mgr.c",0xab);
              }
            }
            else {
              nvAssertFailedNoLog("pGpuMgr->ccCaps.bCCFeatureEnabled == bCCFeatureEnabled",
                                  "src/kernel/gpu_mgr/gpu_mgr.c",0xa7);
            }
            nvAssertOkFailedNoLog
                      (0x40,"_gpumgrDetermineConfComputeCapabilities(pGpuMgr, pGpu)",
                       "src/kernel/gpu_mgr/gpu_mgr.c",0x640);
            return 0x40;
          }
          goto LAB_004473d0;
        }
        uVar19 = uVar19 + 1;
        piVar6 = piVar6 + 0x12;
      } while (uVar19 != 0x20);
      iVar10 = 0x40;
LAB_00447382:
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu_mgr/gpu_mgr.c",0x7f);
      portSyncMutexRelease(*(undefined8 *)(piVar3 + 0x252));
    }
LAB_004473d0:
    if ((*(uint *)(lVar2 + 0x95c) & uVar22) != 0) {
      *(int *)(lVar2 + 0x958) = *(int *)(lVar2 + 0x958) + -1;
      *(uint *)(lVar2 + 0x95c) = ~uVar22 & *(uint *)(lVar2 + 0x95c);
    }
    uVar15 = *(undefined8 *)(lVar14 + 0x878);
    lVar2 = *(long *)(g_pSys + 0x1e0);
    portSyncMutexAcquire(*(undefined8 *)(lVar2 + 0x948));
    _gpumgrUnregisterRmCapsForGpuUnderLock(uVar15);
    portSyncMutexRelease(*(undefined8 *)(lVar2 + 0x948));
    goto LAB_00446e85;
  }
  nvAssertFailedNoLog("pGpuArch != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x52f);
  iVar10 = 0x26;
LAB_00446e4d:
  uVar22 = 1 << (local_e0 & 0x1f);
  if ((*(uint *)(lVar2 + 0x95c) & uVar22) != 0) {
    *(int *)(lVar2 + 0x958) = *(int *)(lVar2 + 0x958) + -1;
    *(uint *)(lVar2 + 0x95c) = ~uVar22 & *(uint *)(lVar2 + 0x95c);
  }
  uVar11 = 0xffffffff;
  lVar14 = 0;
LAB_00446e85:
  osDpcDetachGpu(lVar14);
  _gpumgrDestroyGpu(param_1);
  gpumgrSetCurrentGpuInstance(uVar11);
  return iVar10;
LAB_00446e18:
  portSyncMutexRelease(*(undefined8 *)(piVar3 + 0x252));
  nvCheckOkFailedNoLog
            (4,0x57,
             "gpumgrGetRegisteredIds(pAttachArg->nvDomainBusDeviceFunc, &gpuId, &gpuUuid, &bGpuUuidValid)"
             ,"src/kernel/gpu_mgr/gpu_mgr.c",0x536);
  iVar10 = 0x57;
  goto LAB_00446e4d;
}


// ===== 00447960 gpumgrGetCurrentGpuInstance =====

undefined4 gpumgrGetCurrentGpuInstance(void)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  
  cVar2 = portUtilIsInterruptContext();
  if (((cVar2 == '\0') && (g_pSys != 0)) && (lVar1 = *(long *)(g_pSys + 0x1e0), lVar1 != 0)) {
    lVar4 = portThreadGetCurrentThreadId();
    uVar5 = 0;
    plVar6 = (long *)(lVar1 + 0x3f298);
    do {
      if (lVar4 == *plVar6) {
        return *(undefined4 *)(uVar5 * 0x10 + 0x3f2a0 + lVar1);
      }
      uVar3 = (int)uVar5 + 1;
      uVar5 = (ulong)uVar3;
      plVar6 = plVar6 + 2;
    } while (uVar3 != 8);
  }
  return 0xffffffff;
}


// ===== 004479f0 gpumgrGetGpuBridgeType =====

undefined1 gpumgrGetGpuBridgeType(void)

{
  return *(undefined1 *)(*(long *)(g_pSys + 0x1e0) + 0xaf0);
}


// ===== 00447a10 gpumgrDestroyPcieP2PCapsCache_IMPL =====

void gpumgrDestroyPcieP2PCapsCache_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x3f290) == 0) {
    return;
  }
  portSyncMutexAcquire();
  lVar1 = listHead_IMPL(param_1 + 0x3f278);
  while (lVar1 != 0) {
    lVar2 = listNext_IMPL(param_1 + 0x3f278,lVar1);
    portMemFree(lVar1);
    lVar1 = lVar2;
  }
  listDestroyIntrusive_IMPL(param_1 + 0x3f278);
  portSyncMutexRelease(*(undefined8 *)(param_1 + 0x3f290));
  portSyncMutexDestroy(*(undefined8 *)(param_1 + 0x3f290));
  return;
}


// ===== 00447ab0 gpumgrDestruct_IMPL =====

void gpumgrDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x14b,"gpumgrDestruct_IMPL",1,"NVRM: gpumgrDestruct\n"
              );
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x38);
  }
  lVar1 = objGetChild_IMPL(uVar3);
  while (lVar2 = lVar1, lVar1 != 0) {
    while( true ) {
      lVar1 = objGetSibling_IMPL(lVar2);
      lVar2 = __nvoc_dynamicCast(lVar2,__nvoc_class_def_GpuArch);
      if (lVar2 == 0) break;
      __nvoc_objDelete(lVar2);
      lVar2 = lVar1;
      if (lVar1 == 0) goto LAB_00447b31;
    }
  }
LAB_00447b31:
  if (*(long *)(param_1 + 0x950) != 0) {
    portSyncMutexDestroy();
  }
  if (*(long *)(param_1 + 0x948) != 0) {
    portSyncMutexDestroy();
  }
  if (*(long *)(param_1 + 0x3de50) != 0) {
    portSyncRwLockDestroy();
  }
  gpumgrDestroyPcieP2PCapsCache_IMPL(param_1);
  return;
}


// ===== 00447b80 gpumgrConstruct_IMPL =====

undefined8 gpumgrConstruct_IMPL(long param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr.c",0x10e,"gpumgrConstruct_IMPL",1,
               "NVRM: gpumgrConstruct\n");
  *(undefined4 *)(param_1 + 0x3f158) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x3ef60);
  do {
    *puVar1 = 0x20;
    puVar2 = puVar1 + 8;
    puVar1[4] = 0x20;
    puVar1 = puVar2;
  } while (puVar2 != (undefined4 *)(param_1 + 0x3f160));
  uVar3 = portMemAllocatorGetGlobalNonPaged();
  lVar4 = portSyncMutexCreate(uVar3);
  *(long *)(param_1 + 0x950) = lVar4;
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pGpuMgr->pChildListMutex != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x116);
  }
  else {
    uVar3 = portMemAllocatorGetGlobalNonPaged();
    puVar1 = (undefined4 *)(param_1 + 0x48);
    lVar4 = portSyncMutexCreate(uVar3);
    *(long *)(param_1 + 0x948) = lVar4;
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pGpuMgr->probedGpusLock != NULL","src/kernel/gpu_mgr/gpu_mgr.c",0x11c);
    }
    else {
      do {
        puVar2 = puVar1 + 0x12;
        portMemSet(puVar1,0,0x48);
        *puVar1 = 0xffffffff;
        puVar1 = puVar2;
      } while (puVar2 != (undefined4 *)(param_1 + 0x948));
      *(undefined8 *)(param_1 + 0x958) = 0;
      *(undefined4 *)(param_1 + 0x968) = 0;
      puVar5 = (undefined8 *)(param_1 + 0x970);
      do {
        *puVar5 = 0;
        puVar6 = puVar5 + 2;
        puVar5[1] = 0;
        puVar5 = puVar6;
      } while (puVar6 != (undefined8 *)(param_1 + 0xa70));
      *(undefined1 *)(param_1 + 0x1b20) = 0;
      listInitIntrusive_IMPL(param_1 + 0x3f278,0x28);
      uVar3 = portMemAllocatorGetGlobalNonPaged();
      lVar4 = portSyncMutexCreate(uVar3);
      *(long *)(param_1 + 0x3f290) = lVar4;
      if (lVar4 == 0) {
        nvAssertOkFailedNoLog
                  (0x1a,"gpumgrInitPcieP2PCapsCache(pGpuMgr)","src/kernel/gpu_mgr/gpu_mgr.c",0x130);
      }
      else {
        uVar3 = portMemAllocatorGetGlobalNonPaged();
        lVar4 = portSyncRwLockCreate(uVar3);
        *(long *)(param_1 + 0x3de50) = lVar4;
        if (lVar4 != 0) {
          portMemSet(param_1 + 0x3de58,0,0x1100);
          *(undefined8 *)(param_1 + 0x3f168) = 0x3c;
          portMemSet(param_1 + 0x3f298,0xff,0x80);
          return 0;
        }
        nvAssertFailedNoLog("pGpuMgr->cachedMIGInfoLock != NULL","src/kernel/gpu_mgr/gpu_mgr.c",
                            0x137);
      }
    }
    gpumgrDestruct_IMPL(param_1);
  }
  return 0x1a;
}


// ===== 00447de0 gpumgrStorePcieP2PCapsCache_IMPL =====

undefined8 gpumgrStorePcieP2PCapsCache_IMPL(uint param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x3f290));
  cVar3 = _gpumgrGetPcieP2PCapsFromCache(param_1,0,0);
  if (cVar3 == '\0') {
    lVar4 = portMemAllocNonPaged(0x38);
    if (lVar4 == 0) {
      uVar7 = 0x51;
      goto LAB_00447e2f;
    }
    lVar8 = 0;
    listAppendExisting_IMPL(lVar1 + 0x3f278,lVar4);
    iVar2 = 0;
    while (iVar6 = iVar2, iVar6 != 0x20) {
      iVar2 = iVar6 + 1;
      if ((1 << ((byte)iVar6 & 0x1f) & param_1) != 0) {
        lVar5 = gpumgrGetGpu(iVar6);
        if (lVar5 == 0) break;
        *(undefined4 *)(lVar4 + lVar8 * 4) = *(undefined4 *)(lVar5 + 0x7ac);
        lVar8 = lVar8 + 1;
      }
    }
    *(int *)(lVar4 + 0x20) = (int)lVar8;
    *(undefined1 *)(lVar4 + 0x24) = param_2;
    *(undefined1 *)(lVar4 + 0x25) = param_3;
  }
  uVar7 = 0;
LAB_00447e2f:
  portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x3f290));
  return uVar7;
}


// ===== 00447ef0 gpumgrGetPcieP2PCapsFromCache_IMPL =====

undefined4
gpumgrGetPcieP2PCapsFromCache_IMPL(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x3f290));
  uVar2 = _gpumgrGetPcieP2PCapsFromCache(param_1,param_2,param_3);
  portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x3f290));
  return uVar2;
}


// ===== 00447f50 gpumgrRemovePcieP2PCapsFromCache_IMPL =====

void gpumgrRemovePcieP2PCapsFromCache_IMPL(int param_1)

{
  long lVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x3f290));
  piVar3 = (int *)listHead_IMPL(lVar1 + 0x3f278);
  do {
    do {
      piVar2 = piVar3;
      if (piVar2 == (int *)0x0) {
        portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x3f290));
        return;
      }
      piVar3 = (int *)listNext_IMPL(lVar1 + 0x3f278,piVar2);
    } while (piVar2[8] == 0);
    piVar4 = piVar2;
    do {
      if (*piVar4 == param_1) {
        listRemoveIntrusive_IMPL(lVar1 + 0x3f278,piVar2);
        portMemFree(piVar2);
        break;
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != piVar2 + (uint)piVar2[8]);
  } while( true );
}


// ===== 00448020 gpumgrUnregisterGpuId =====

undefined8 gpumgrUnregisterGpuId(int param_1)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  int *piVar5;
  ulong uVar6;
  
  uVar6 = 0;
  piVar1 = *(int **)(g_pSys + 0x1e0);
  portSyncMutexAcquire(*(undefined8 *)(piVar1 + 0x252));
  piVar5 = piVar1;
  do {
    piVar5 = piVar5 + 0x12;
    if (*piVar5 == param_1) {
      lVar2 = *(long *)(g_pSys + 0x1e0);
      portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x3de50));
      piVar5 = (int *)(lVar2 + 0x3de5c);
      uVar4 = 0;
      goto LAB_004480af;
    }
    uVar3 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar3;
  } while (uVar3 != 0x20);
  goto LAB_0044810a;
  while( true ) {
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar5 = piVar5 + 0x22;
    if (uVar3 == 0x20) break;
LAB_004480af:
    if (param_1 == *piVar5) {
      portMemSet(lVar2 + 0x3de58 + uVar4 * 0x88,0,0x88);
      break;
    }
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x3de50));
  gpumgrRemovePcieP2PCapsFromCache_IMPL(piVar1[uVar6 * 0x12 + 0x12]);
  _gpumgrUnregisterRmCapsForGpuUnderLock(*(undefined8 *)(piVar1 + uVar6 * 0x12 + 0x14));
  *(undefined4 *)((long)piVar1 + uVar6 * 0x48 + 0x59) = 0;
  (piVar1 + uVar6 * 0x12 + 0x12)[0] = -1;
  (piVar1 + uVar6 * 0x12 + 0x12)[1] = 0;
LAB_0044810a:
  portSyncMutexRelease(*(undefined8 *)(piVar1 + 0x252));
  return 0;
}


// ===== 00448130 gpumgrAreAllGpusInOffloadMode =====

undefined4 gpumgrAreAllGpusInOffloadMode(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*(long *)(g_pSys + 0x1e0) + 0x960);
  return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 0);
}


// ===== 00448150 gpumgrIsDeviceMsixAllowed =====

undefined8 gpumgrIsDeviceMsixAllowed(undefined8 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = hypervisorGetHypervisorType_IMPL(*(undefined8 *)(g_pSys + 0x238));
  if ((iVar1 != 4) &&
     (((param_3 >> 0x18 & 0x3f) - 0x17 & 0xfffffffd) == 0 && (param_2 & 0x30000) == 0)) {
    uVar2 = gpuIsMsixAllowed_TU102(param_1);
    return uVar2;
  }
  return 1;
}


// ===== 004481d0 gpumgrWaitForBarFirewall =====

undefined8
gpumgrWaitForBarFirewall
          (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,short param_5
          ,short param_6)

{
  undefined8 uVar1;
  
  if ((((ushort)(param_5 + 0xd700U) < 0x100) || ((ushort)(param_5 + 0xce80U) < 0x100)) &&
     ((param_5 != 0x2901 || ((6 < (ushort)(param_6 + 0xde29U) && (param_6 != 0x21ea)))))) {
    uVar1 = gpuWaitForBarFirewall_GB100(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 1;
}


// ===== 00448240 gpuMgrIsNvleAlidPresent =====

undefined8 gpuMgrIsNvleAlidPresent(long param_1,int param_2)

{
  long lVar1;
  
  if (*(uint *)(param_1 + 0x3f274) != 0) {
    lVar1 = param_1 + (ulong)*(uint *)(param_1 + 0x3f274) * 8;
    do {
      if (*(int *)(param_1 + 0x3f174) == param_2) {
        return 1;
      }
      param_1 = param_1 + 8;
    } while (param_1 != lVar1);
  }
  return 0;
}


// ===== 00448280 gpuMgrCacheNvleAlidClid =====

undefined8 gpuMgrCacheNvleAlidClid(long param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  uVar1 = *(uint *)(param_1 + 0x3f274);
  uVar2 = 1;
  if (uVar1 == 0) {
    *(int *)(param_1 + 0x3f174) = param_2;
    *(undefined4 *)(param_1 + 0x3f178) = param_3;
    *(undefined4 *)(param_1 + 0x3f274) = 1;
    return 1;
  }
  while( true ) {
    if (*(int *)(param_1 + 0x3f16c + uVar2 * 8) == param_2) {
      return 0;
    }
    if (uVar2 == uVar1) break;
    uVar2 = uVar2 + 1;
  }
  if ((int)uVar2 == 0x20) {
    return 0;
  }
  lVar3 = (uVar2 & 0xffffffff) + 0x7e2e;
  *(int *)(param_1 + 4 + lVar3 * 8) = param_2;
  *(undefined4 *)(param_1 + 8 + lVar3 * 8) = param_3;
  *(uint *)(param_1 + 0x3f274) = uVar1 + 1;
  return 1;
}


// ===== 00448310 gpumgrAreGpusInitialized =====

undefined1 gpumgrAreGpusInitialized(undefined4 param_1)

{
  long lVar1;
  undefined4 local_1c [3];
  
  local_1c[0] = 0;
  do {
    lVar1 = gpumgrGetNextGpu(param_1,local_1c);
    if (lVar1 == 0) {
      return 1;
    }
  } while (*(char *)(lVar1 + 0x445) != '\0');
  return 0;
}


// ===== 00448360 gpumgrUpdateSliLinkRouting =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
gpumgrUpdateSliLinkRouting
          (long param_1,long param_2,uint param_3,ulong param_4,uint param_5,char param_6)

{
  byte *pbVar1;
  byte bVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  ulong uVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  
  param_4 = param_4 & 0xffffffff;
  lVar3 = *(long *)(param_1 + 0x1b80);
  lVar4 = *(long *)(g_pSys + 0x1e0);
  if (*(char *)(param_1 + 0x909) == '\0') {
    if (param_6 == '\0') {
      if (lVar3 == 0) goto LAB_00448580;
LAB_004483af:
      iVar6 = (**(code **)(lVar3 + 0x210))(lVar3,param_1,param_2);
      if (iVar6 != 0) {
LAB_00448580:
        uVar12 = (ulong)param_5;
        uVar11 = (ulong)param_3;
        uVar9 = (ulong)*(uint *)(param_1 + 0x7a4);
        uVar7 = (ulong)*(uint *)(param_2 + 0x7a4);
        lVar3 = lVar4 + ((uVar11 * 0x20 + uVar9) * 0x20 + uVar7) * 2;
        bVar2 = *(byte *)(param_4 + 0xaf1 + lVar3);
        if ((~bVar2 & 3) != 0) {
          *(byte *)(param_4 + 0xaf1 + lVar3) = bVar2 & 0xfc | 2;
          uVar9 = (ulong)*(uint *)(param_1 + 0x7a4);
          uVar7 = (ulong)*(uint *)(param_2 + 0x7a4);
        }
        lVar3 = lVar4 + ((uVar11 * 0x20 + uVar7) * 0x20 + uVar9) * 2;
        bVar2 = *(byte *)(lVar3 + 0xaf1 + uVar12);
        if ((~bVar2 & 3) != 0) {
          *(byte *)(lVar3 + 0xaf1 + uVar12) = bVar2 & 0xfc | 2;
          uVar9 = (ulong)*(uint *)(param_1 + 0x7a4);
          uVar7 = (ulong)*(uint *)(param_2 + 0x7a4);
        }
        lVar3 = lVar4 + ((uVar11 * 0x20 + uVar9) * 0x20 + uVar7) * 2;
        bVar2 = *(byte *)(param_4 + 0xaf1 + lVar3);
        if ((~bVar2 & 0xc) != 0) {
          *(byte *)(param_4 + 0xaf1 + lVar3) = bVar2 & 0xf3 | 8;
          uVar9 = (ulong)*(uint *)(param_1 + 0x7a4);
          uVar7 = (ulong)*(uint *)(param_2 + 0x7a4);
        }
        lVar4 = lVar4 + ((uVar11 * 0x20 + uVar7) * 0x20 + uVar9) * 2;
        bVar2 = *(byte *)(lVar4 + 0xaf1 + uVar12);
        if ((~bVar2 & 0xc) != 0) {
          *(byte *)(lVar4 + 0xaf1 + uVar12) = bVar2 & 0xf3 | 8;
        }
        return 0;
      }
      uVar8 = 1;
      goto LAB_00448436;
    }
  }
  else {
    if (lVar3 == 0) {
      nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpuParent) || pKernelDisp != NULL",
                          "src/kernel/gpu_mgr/gpu_mgr_sli.c",0x128);
      return 0;
    }
    if (param_6 == '\0') goto LAB_004483af;
  }
  uVar8 = 0;
LAB_00448436:
  iVar6 = 1 << ((byte)param_4 & 0x1f);
  iVar10 = 1 << ((byte)param_5 & 0x1f);
  uVar7 = (ulong)param_5;
  lVar5 = (ulong)param_3 * 0x20;
  pbVar1 = (byte *)(param_4 + 0xaf1 +
                   lVar4 + (((ulong)*(uint *)(param_1 + 0x7a4) + lVar5) * 0x20 +
                           (ulong)*(uint *)(param_2 + 0x7a4)) * 2);
  *pbVar1 = *pbVar1 | 3;
  pbVar1 = (byte *)(uVar7 + 0xaf1 +
                   lVar4 + (((ulong)*(uint *)(param_2 + 0x7a4) + lVar5) * 0x20 +
                           (ulong)*(uint *)(param_1 + 0x7a4)) * 2);
  *pbVar1 = *pbVar1 | 3;
  pbVar1 = (byte *)(param_4 + 0xaf1 +
                   lVar4 + (((ulong)*(uint *)(param_1 + 0x7a4) + lVar5) * 0x20 +
                           (ulong)*(uint *)(param_2 + 0x7a4)) * 2);
  *pbVar1 = *pbVar1 | 0xc;
  pbVar1 = (byte *)(uVar7 + 0xaf1 +
                   lVar4 + (((ulong)*(uint *)(param_2 + 0x7a4) + lVar5) * 0x20 +
                           (ulong)*(uint *)(param_1 + 0x7a4)) * 2);
  *pbVar1 = *pbVar1 | 0xc;
  lVar3 = lVar4 + (((ulong)*(uint *)(param_1 + 0x7a4) + lVar5) * 0x20 +
                  (ulong)*(uint *)(param_2 + 0x7a4)) * 2;
  *(byte *)(param_4 + 0xaf1 + lVar3) =
       *(byte *)(param_4 + 0xaf1 + lVar3) & 0xf | (byte)(iVar10 << 4);
  lVar4 = lVar4 + ((lVar5 + (ulong)*(uint *)(param_2 + 0x7a4)) * 0x20 +
                  (ulong)*(uint *)(param_1 + 0x7a4)) * 2;
  *(byte *)(lVar4 + 0xaf1 + uVar7) = *(byte *)(lVar4 + 0xaf1 + uVar7) & 0xf | (byte)(iVar6 << 4);
  *(long *)(param_1 + 0x4a58 + param_4 * 0x10) = param_2;
  *(int *)(param_1 + 0x4a60 + param_4 * 0x10) = iVar10;
  *(long *)(param_2 + 0x4a58 + uVar7 * 0x10) = param_1;
  *(int *)(param_2 + 0x4a60 + uVar7 * 0x10) = iVar6;
  return uVar8;
}


// ===== 004486c0 gpumgrDetectHighSpeedVideoBridges =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gpumgrDetectHighSpeedVideoBridges(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined4 local_30;
  int local_2c [3];
  
  uVar5 = 0;
  local_30 = 0;
  while( true ) {
    while( true ) {
      lVar3 = gpumgrGetNextGpu(param_1,&local_30);
      if (lVar3 == 0) {
        if ((char)uVar5 != '\0') {
          local_30 = 0;
          while (lVar3 = gpumgrGetNextGpu(param_1,&local_30), lVar3 != 0) {
            if (*(long *)(lVar3 + 0x1b80) == 0) {
              nvAssertFailedNoLog("pKernelDisp != NULL","src/kernel/gpu_mgr/gpu_mgr_sli.c",0x1b7);
            }
            else {
              *(undefined1 *)(lVar3 + 0x440) = 1;
            }
          }
        }
        return uVar5;
      }
      if (*(long *)(lVar3 + 0x1b80) != 0) break;
      nvAssertFailedNoLog("pKernelDisp != NULL","src/kernel/gpu_mgr/gpu_mgr_sli.c",0x188);
    }
    *(undefined1 *)(lVar3 + 0x440) = 0;
    local_2c[0] = 0;
    if (((*(char *)(lVar3 + 0x909) != '\0') &&
        (cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4)), cVar1 == '\0')) &&
       (uVar2 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar3 + 0x7a4),0,0,0x8002,local_2c),
       uVar2 != 0)) break;
    uVar4 = (**(code **)(lVar3 + 0x3b90))
                      (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                       *(undefined4 *)(lVar3 + 0x3b3c),0x20800add,0,0);
    uVar5 = uVar5 | (uint)CONCAT71((int7)((ulong)uVar4 >> 8),(int)uVar4 == 0);
    if (local_2c[0] != 0) {
      rmGpuGroupLockRelease(local_2c[0],0);
    }
  }
  nvAssertOkFailedNoLog
            (uVar2,
             "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuLockMask)"
             ,"src/kernel/gpu_mgr/gpu_mgr_sli.c",0x194);
  return uVar2 & 0xff;
}


// ===== 00448840 gpumgrDetectSliLinkFromGpus =====

void gpumgrDetectSliLinkFromGpus
               (char param_1,uint param_2,int param_3,int *param_4,int *param_5,undefined1 *param_6,
               undefined4 *param_7,undefined4 *param_8)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined1 auVar5 [16];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  local_4c = 0;
  *param_7 = 0;
  local_48 = 0;
  *param_5 = 0;
  local_44 = 0;
  local_4d = 0;
  local_40 = 0;
  *param_4 = 0;
  local_3c[0] = 0;
  while (lVar2 = gpumgrGetNextGpu(param_3,local_3c), lVar2 != 0) {
    if (*(char *)(lVar2 + 0x445) == '\0') {
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr_sli.c",0x6c,"gpumgrDetectSliLinkFromGpus",3,
                   "NVRM: All GPUs do not have state initialized\n");
      return;
    }
  }
  if (param_2 < 2) {
    nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr_sli.c",0x77,"gpumgrDetectSliLinkFromGpus",1,
                 "NVRM: gpumgrDetectSliLinkFromGpus: Need >=2 GPUs to test SliLink.\n          gpuMask = 0x%x\n"
                 ,param_3);
    return;
  }
  if ((param_3 == 0) && (param_1 == '\0')) {
    *param_4 = 0;
    *param_5 = local_44;
    *param_6 = local_4d;
    *param_7 = local_48;
    *param_8 = local_40;
    return;
  }
  local_4c = 0;
  do {
    lVar2 = gpumgrGetNextGpu(param_3,&local_4c);
    if (lVar2 == 0) {
      local_4d = 0;
      local_44 = 0;
      local_4c = 0;
      lVar2 = gpumgrGetNextGpu(param_3,&local_4c);
      if (lVar2 != 0) {
        do {
          lVar3 = gpumgrGetNextGpu(param_3,&local_4c);
        } while (lVar3 != 0);
        lVar3 = portMemAllocNonPaged(param_2);
        if (lVar3 == 0) {
          nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr_sli.c",0xbb,"gpumgrDetectSliLinkFromGpus",4,
                       "NVRM: gpumgrDetectSliLinkFromGpus: Insufficient resources.\n");
          return;
        }
        local_4c = 0;
        do {
          lVar4 = gpumgrGetNextGpu(param_3,&local_4c);
        } while (lVar4 != 0);
        gpuDetectSliLinkFromGpus_GK104(lVar2,param_2,param_3,&local_44,&local_4d,&local_48);
        local_4c = 0;
        lVar2 = gpumgrGetNextGpu(param_3,&local_4c);
        auVar5._8_8_ = &local_40;
        auVar5._0_8_ = lVar2;
        while (lVar2 != 0) {
          *(undefined1 *)(auVar5._0_8_ + 0x440) = 0;
          auVar5 = gpumgrGetNextGpu(param_3,&local_4c,auVar5._8_8_);
          lVar2 = auVar5._0_8_;
        }
        portMemFree(lVar3);
        iVar1 = local_44;
        if (local_44 != 0) {
          local_4c = 0;
          while (lVar2 = gpumgrGetNextGpu(iVar1,&local_4c), lVar2 != 0) {
            if (*(char *)(lVar2 + 0x4bf) != '\0') {
              local_44 = 0;
            }
          }
        }
        gpumgrDetectHighSpeedVideoBridges(local_44);
        *param_5 = local_44;
        *param_4 = param_3;
        *param_6 = local_4d;
        *param_7 = local_48;
        *param_8 = local_40;
        return;
      }
      break;
    }
  } while (*(long *)(lVar2 + 0x1b80) != 0);
  *param_4 = param_3;
  *param_5 = 0;
  return;
}


// ===== 00448b70 gpumgrPinsetToPinsetTableIndex =====

undefined8 gpumgrPinsetToPinsetTableIndex(uint param_1,uint *param_2)

{
  uint uVar1;
  
  if ((param_1 != 0) && (uVar1 = param_1 - 1, (uVar1 & param_1) == 0)) {
    if (1 < uVar1) {
      nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr_sli.c",0x1da,"gpumgrPinsetToPinsetTableIndex",4,
                   "NVRM: Unknown pin set value: 0x%x\n",param_1);
      return 0x1f;
    }
    *param_2 = (-uVar1 & 0x1010101) >> 0x18;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu_mgr/gpu_mgr_sli.c",0x1ce,"gpumgrPinsetToPinsetTableIndex",4,
               "NVRM: More than one bit set: 0x%x\n",param_1);
  return 0x1f;
}


// ===== 00448c10 gpumgrGetSliLinks =====

undefined8 gpumgrGetSliLinks(undefined4 *param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  byte bVar10;
  ulong uVar11;
  uint uVar12;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c [3];
  
  puVar4 = param_1;
  do {
    puVar4[1] = 0xffffffff;
    puVar5 = puVar4 + 9;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0xffffffff;
    puVar4[4] = 0xffffffff;
    puVar4[5] = 0xffffffff;
    puVar4[6] = 0xffffffff;
    puVar4[7] = 0xffffffff;
    puVar4[8] = 0xffffffff;
    *puVar4 = 0xffffffff;
    puVar4 = puVar5;
  } while (param_1 + 0x120 != puVar5);
  gpumgrGetGpuAttachInfo(&local_40,local_3c);
  if (1 < local_40) {
    local_4c = 0;
    lVar1 = *(long *)(g_pSys + 0x1e0);
    for (uVar12 = 0;
        (lVar6 = gpumgrGetNextGpu(local_3c[0],&local_4c), lVar6 != 0 && (uVar12 != 0x20));
        uVar12 = uVar12 + 1) {
      while (0x1f < *(uint *)(lVar6 + 0x7a4)) {
        nvAssertFailedNoLog("pGpu->gpuInstance < NV_MAX_DEVICES","src/kernel/gpu_mgr/gpu_mgr_sli.c",
                            0x216);
        lVar6 = gpumgrGetNextGpu(local_3c[0],&local_4c);
        if (lVar6 == 0) {
          return 0;
        }
      }
      local_48 = 0;
      uVar11 = 0;
      param_1[(ulong)uVar12 * 9] = *(undefined4 *)(lVar6 + 0x7ac);
LAB_00448d10:
      lVar7 = gpumgrGetNextGpu(local_3c[0],&local_48);
      if ((lVar7 != 0) && ((uint)uVar11 < 8)) {
        do {
          if ((local_48 != local_4c) && (*(uint *)(lVar7 + 0x7a4) < 0x20)) {
            uVar8 = (ulong)*(byte *)(lVar1 + 0xaf0);
            uVar9 = (ulong)*(uint *)(lVar6 + 0x7a4);
            bVar10 = *(byte *)(lVar1 + 1 +
                              ((ulong)*(uint *)(lVar7 + 0x7a4) + 0x578 +
                              (uVar8 * 0x20 + uVar9) * 0x20) * 2);
            if ((~bVar10 & 3) != 0) goto LAB_00448dd3;
            bVar2 = false;
            uVar9 = uVar11;
            if (*(byte *)(lVar1 + 0xaf0) == 0) goto LAB_00448e09;
            do {
              uVar11 = uVar9;
              if ((uint)uVar9 < 8) {
                uVar11 = (ulong)((uint)uVar9 + 1);
                param_1[uVar9 + (ulong)uVar12 * 9 + 1] = *(undefined4 *)(lVar7 + 0x7ac);
              }
              do {
                if (bVar2) goto LAB_00448d10;
                uVar8 = (ulong)*(byte *)(lVar1 + 0xaf0);
                uVar9 = (ulong)*(uint *)(lVar6 + 0x7a4);
LAB_00448dd3:
                bVar2 = true;
                bVar10 = *(byte *)(lVar1 + 0xaf2 +
                                  ((uVar8 * 0x20 + uVar9) * 0x20 + (ulong)*(uint *)(lVar7 + 0x7a4))
                                  * 2);
                if ((~bVar10 & 3) != 0) goto LAB_00448d10;
                uVar9 = uVar11;
                if ((char)uVar8 != '\0') break;
LAB_00448e09:
                iVar3 = gpumgrPinsetToPinsetTableIndex(bVar10 >> 4,&local_44);
                if (iVar3 != 0) {
                  return 0x1f;
                }
                uVar9 = uVar11;
              } while ((~*(byte *)((ulong)local_44 + 0xaf1 +
                                  lVar1 + (((ulong)*(byte *)(lVar1 + 0xaf0) * 0x20 +
                                           (ulong)*(uint *)(lVar7 + 0x7a4)) * 0x20 +
                                          (ulong)*(uint *)(lVar6 + 0x7a4)) * 2) & 0xc) != 0);
            } while( true );
          }
          lVar7 = gpumgrGetNextGpu(local_3c[0],&local_48);
        } while (lVar7 != 0);
      }
    }
  }
  return 0;
}


// ===== 00448ee0 griddisplaylessCtrlCmdVirtualDisplayGetNumHeads_IMPL =====

undefined8 griddisplaylessCtrlCmdVirtualDisplayGetNumHeads_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf8);
  uVar2 = griddisplaylessGetNumHeads_IMPL(uVar1);
  *param_2 = uVar2;
  uVar2 = griddisplaylessGetMaxNumHeads_IMPL(uVar1);
  param_2[1] = uVar2;
  return 0;
}


// ===== 00448f20 griddisplaylessCtrlCmdVirtualDisplayGetMaxResolution_IMPL =====

undefined8 griddisplaylessCtrlCmdVirtualDisplayGetMaxResolution_IMPL(long param_1,uint *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_2;
  uVar1 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf8);
  uVar2 = griddisplaylessGetNumHeads_IMPL(uVar1);
  if (uVar3 < uVar2) {
    uVar3 = griddisplaylessGetMaxHResolution_IMPL(uVar1);
    param_2[1] = uVar3;
    uVar3 = griddisplaylessGetMaxVResolution_IMPL(uVar1);
    param_2[2] = uVar3;
    return 0;
  }
  return 0x1f;
}


// ===== 00448f90 griddisplaylessCtrlCmdVirtualDisplayGetDefaultEdid_IMPL =====

void griddisplaylessCtrlCmdVirtualDisplayGetDefaultEdid_IMPL(long param_1,undefined8 *param_2)

{
  griddisplaylessGetDefaultEDID_IMPL
            (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf8),
             *(undefined1 *)((long)param_2 + 0xc),param_2 + 1,*param_2);
  return;
}


// ===== 00448fc0 griddisplaylessCtrlCmdVirtualDisplayIsActive_IMPL =====

undefined8 griddisplaylessCtrlCmdVirtualDisplayIsActive_IMPL(long param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = griddisplaylessVirtualDisplayIsActive_IMPL
                    (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf8));
  *param_2 = uVar1;
  return 0;
}


// ===== 00449000 griddisplaylessCtrlCmdVirtualDisplayIsConnected_IMPL =====

undefined8 griddisplaylessCtrlCmdVirtualDisplayIsConnected_IMPL(long param_1,uint *param_2)

{
  byte bVar1;
  
  bVar1 = griddisplaylessVirtualDisplayIsConnected_IMPL
                    (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf8));
  *param_2 = (uint)bVar1;
  return 0;
}


// ===== 00449040 griddisplaylessCtrlCmdVirtualDisplayGetMaxPixels_IMPL =====

undefined8 griddisplaylessCtrlCmdVirtualDisplayGetMaxPixels_IMPL(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = griddisplaylessGetMaxPixels_IMPL
                    (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf8));
  *param_2 = uVar1;
  return 0;
}


// ===== 00449080 griddisplaylessConstructEngine_IMPL =====

undefined8 griddisplaylessConstructEngine_IMPL(long param_1,long param_2)

{
  if (*(char *)(param_1 + 0x908) == '\0') {
    *(undefined4 *)(param_2 + 0x168) = 1;
    *(undefined8 *)(param_2 + 0x174) = 0x64000000a00;
    *(undefined8 *)(param_2 + 0x180) = 0x3e8000;
  }
  *(undefined4 *)(param_2 + 0x16c) = 4;
  return 0;
}


// ===== 004490c0 griddisplaylessGetNumHeads_IMPL =====

undefined4 griddisplaylessGetNumHeads_IMPL(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x168);
  }
  return uVar1;
}


// ===== 004490e0 griddisplaylessGetMaxNumHeads_IMPL =====

undefined4 griddisplaylessGetMaxNumHeads_IMPL(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x16c);
  }
  return uVar1;
}


// ===== 00449100 griddisplaylessGetMaxHResolution_IMPL =====

undefined4 griddisplaylessGetMaxHResolution_IMPL(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x174);
  }
  return uVar1;
}


// ===== 00449120 griddisplaylessGetMaxVResolution_IMPL =====

undefined4 griddisplaylessGetMaxVResolution_IMPL(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x178);
  }
  return uVar1;
}


// ===== 00449140 griddisplaylessUpdateHeadNumInfo_IMPL =====

undefined8 griddisplaylessUpdateHeadNumInfo_IMPL(long param_1,undefined8 param_2)

{
  if (param_1 != 0) {
    portMemCopy(param_1 + 0x168,8,param_2,8);
    return 0;
  }
  return 0x3d;
}


// ===== 00449180 griddisplaylessUpdateMaxResInfo_IMPL =====

undefined8 griddisplaylessUpdateMaxResInfo_IMPL(long param_1,undefined8 param_2)

{
  if (param_1 != 0) {
    portMemCopy(param_1 + 0x170,0xc,param_2,0xc);
    return 0;
  }
  return 0x3d;
}


// ===== 004491c0 griddisplaylessUpdateMaxPixels_IMPL =====

undefined8 griddisplaylessUpdateMaxPixels_IMPL(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0x3d;
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x180) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 004491e0 griddisplaylessGetMaxPixels_IMPL =====

undefined8 griddisplaylessGetMaxPixels_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x180);
  }
  return uVar1;
}


// ===== 00449200 griddisplaylessVirtualDisplayIsActive_IMPL =====

undefined8 griddisplaylessVirtualDisplayIsActive_IMPL(long param_1)

{
  long lVar1;
  
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x168) != 0)) {
    lVar1 = (ulong)*(uint *)(param_1 + 0x168) + param_1;
    do {
      if (*(char *)(param_1 + 0x17c) != '\0') {
        return 1;
      }
      param_1 = param_1 + 1;
    } while (param_1 != lVar1);
    return 0;
  }
  return 0;
}


// ===== 00449250 griddisplaylessVirtualDisplayIsConnected_IMPL =====

undefined4 griddisplaylessVirtualDisplayIsConnected_IMPL(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = CONCAT31((int3)((uint)*(int *)(param_1 + 0x168) >> 8),*(int *)(param_1 + 0x168) != 0);
  }
  return uVar1;
}


// ===== 00449270 griddisplaylessConstruct_IMPL =====

undefined8 griddisplaylessConstruct_IMPL(long param_1)

{
  char cVar1;
  
  cVar1 = gpuIsGridDisplaylessClassSupported_IMPL
                    (*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (cVar1 != '\0') {
    return 0;
  }
  nvCheckFailedNoLog(2,"gpuIsGridDisplaylessClassSupported(pGpu)",
                     "src/kernel/griddisplayless/objgriddisplayless.c",0x116);
  return 0x56;
}


// ===== 004492c0 griddisplaylessGetDefaultEDID_IMPL =====

undefined4
griddisplaylessGetDefaultEDID_IMPL(undefined8 param_1,char param_2,uint *param_3,long param_4)

{
  undefined4 uVar1;
  
  if (param_3 == (uint *)0x0) {
    nvDbg_Printf("src/kernel/griddisplayless/objgriddisplayless.c",0x129,
                 "griddisplaylessGetDefaultEDID_IMPL",4,
                 "NVRM: Parameter validation failed. NULL buffer passed.\n");
    return 0x1f;
  }
  uVar1 = 0;
  if (*param_3 != 0) {
    if (*param_3 < 0x100) {
      nvDbg_Printf("src/kernel/griddisplayless/objgriddisplayless.c",0x136,
                   "griddisplaylessGetDefaultEDID_IMPL",4,
                   "NVRM: Edid buffer of insufficient size passed\n");
      *param_3 = 0x100;
      return 2;
    }
    if (param_4 == 0) {
      nvDbg_Printf("src/kernel/griddisplayless/objgriddisplayless.c",0x13e,
                   "griddisplaylessGetDefaultEDID_IMPL",4,
                   "NVRM: Parameter validation failed. NULL buffer passed.\n");
      uVar1 = 0x1f;
    }
    else if (param_2 == '\0') {
      portMemCopy(param_4,0x100,g_GridDisplaylessDigitalEdid,0x100);
      uVar1 = 0;
    }
    else if (param_2 == '\x01') {
      portMemCopy(param_4,0x100,g_GridDisplaylessAnalogEdid,0x100);
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  *param_3 = 0x100;
  return uVar1;
}


// ===== 00449408 conmemConstruct_IMPL.cold =====

void conmemConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00449420 conmemConstruct_IMPL =====

ulong conmemConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  lVar3 = *(long *)(lVar1 + 0xf0);
  lVar3 = memmgrGetReservedConsoleMemDesc_IMPL(lVar3,*(undefined8 *)(lVar3 + 0x1b78));
  uVar4 = 0;
  if (*(long *)(param_3 + 0x58) == 0) {
    if (lVar3 == 0) {
      return 0x1f;
    }
    if (*(int *)(lVar3 + 0x68) == 1) {
      uVar5 = 0x3e;
    }
    else {
      uVar5 = 0x40;
      if (*(int *)(lVar3 + 0x68) != 2) {
        return 0x56;
      }
    }
    if (*(char *)(lVar3 + 100) != '\0') {
      nvAssertFailedNoLog("pMemDesc->Allocated == 0","src/kernel/mem_mgr/console_mem.c",0x4a);
    }
    memdescAddRef(lVar3);
    *(int *)(lVar3 + 0x94) = *(int *)(lVar3 + 0x94) + 1;
    uVar4 = memConstructCommon_IMPL(lVar1,uVar5,0,lVar3,0,0,0,0,0,0,0,0);
    if ((int)uVar4 == 0) {
      return uVar4;
    }
    memdescDestroy(lVar3);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 00449560 conmemCanCopy_IMPL =====

undefined8 conmemCanCopy_IMPL(void)

{
  return 1;
}


// ===== 0044956a conmemCtrlCmdNotifyConsoleDisabled_IMPL.cold =====

void conmemCtrlCmdNotifyConsoleDisabled_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00449580 conmemCtrlCmdNotifyConsoleDisabled_IMPL =====

undefined8 conmemCtrlCmdNotifyConsoleDisabled_IMPL(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x210) + 0xf0);
    if (*(long *)(&DAT_00001b90 + lVar1) != 0) {
      kbusUnmapPreservedConsole_GM107
                (lVar1,*(long *)(&DAT_00001b90 + lVar1),
                 *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x210) + 0x118) + 0xa8));
    }
    osDisableConsoleManagement(lVar1);
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 004495e0 ctxBufPoolIsSupported =====

undefined1 ctxBufPoolIsSupported(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char local_1d;
  int local_1c [3];
  
  local_1c[0] = 0;
  lVar1 = *(long *)(param_1 + 0x1b78);
  if (*(char *)(param_1 + 0x490) == '\0') {
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x41,"ctxBufPoolIsSupported",1,
                 "NVRM: Ctx buffers not supported in PMA\n");
    return 0;
  }
  if ((*(char *)(lVar1 + 0x433) == '\0') || (*(char *)(lVar1 + 0x432) == '\0')) {
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x47,"ctxBufPoolIsSupported",1,
                 "NVRM: PMA is disabled. Ctx buffers will be allocated in RM reserved heap\n");
  }
  else if ((((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) ||
           (*(char *)(lVar1 + 0x446) == '\0')) || (*(char *)(param_1 + 0x4915) == '\0')) {
    if (*(char *)(param_1 + 0x908) == '\0') {
      iVar3 = vgpuIsCallingContextPlugin(param_1,&local_1d);
      if (iVar3 == 0) {
        iVar3 = vgpuGetCallingContextGfid(param_1,local_1c);
        if (iVar3 == 0) {
          cVar2 = hypervisorIsVgxHyper_IMPL();
          if (((cVar2 == '\0') || (local_1d != '\0')) || (local_1c[0] == 0)) {
            nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x66,"ctxBufPoolIsSupported",1,
                         "NVRM: Ctx buffer pool enabled. Ctx buffers will be allocated from PMA\n");
            return 1;
          }
          nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x62,"ctxBufPoolIsSupported",1,
                       "NVRM: ctx buffers in PMA not supported for allocations host RM makes on behalf of guest\n"
                      );
        }
        else {
          nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                              "src/kernel/mem_mgr/ctx_buf_pool.c",0x5f);
        }
      }
      else {
        nvAssertFailedNoLog("vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin) == NV_OK",
                            "src/kernel/mem_mgr/ctx_buf_pool.c",0x5e);
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x56,"ctxBufPoolIsSupported",1,
                   "NVRM: Guest RM/GSP don\'t support ctx buffers in PMA\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x50,"ctxBufPoolIsSupported",1,
                 "NVRM: Ctx buffers not supported on simulation/emulation\n");
  }
  return 0;
}


// ===== 00449820 ctxBufPoolDestroy =====

void ctxBufPoolDestroy(undefined8 *param_1)

{
  long *plVar1;
  long *plVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    plVar2 = (long *)*param_1;
    if (plVar2 == (long *)0x0) {
      nvAssertFailedNoLog("(ppCtxBufPool != NULL) && (*ppCtxBufPool != NULL)",
                          "src/kernel/mem_mgr/ctx_buf_pool.c",0xce);
      plVar2 = (long *)*param_1;
      if (plVar2 == (long *)0x0) goto LAB_004498e0;
    }
    plVar1 = plVar2;
    do {
      if (*plVar1 != 0) {
        rmMemPoolDestroy();
        *plVar1 = 0;
      }
      plVar1 = plVar1 + 1;
    } while (plVar1 != plVar2 + 6);
    portMemFree(plVar2);
    *param_1 = 0;
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0xe1,"ctxBufPoolDestroy",1,
                 "NVRM: Ctx buf pool destroyed\n");
    return;
  }
  nvAssertFailedNoLog("(ppCtxBufPool != NULL) && (*ppCtxBufPool != NULL)",
                      "src/kernel/mem_mgr/ctx_buf_pool.c",0xce);
LAB_004498e0:
  nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0xd1,"ctxBufPoolDestroy",4,
               "NVRM: Ctx buf pool doesn\'t exist\n");
  return;
}


// ===== 00449940 ctxBufPoolInit =====

int ctxBufPoolInit(undefined8 param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *local_58;
  undefined8 *local_40 [2];
  
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("ppCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x7f);
    return 0x1f;
  }
  iVar2 = 0;
  cVar1 = ctxBufPoolIsSupported();
  if (cVar1 != '\0') {
    local_58 = (undefined8 *)portMemAllocNonPaged(0x30);
    local_40[0] = local_58;
    if (local_58 != (undefined8 *)0x0) {
      uVar3 = 0xfffffffe;
      portMemSet(local_58,0,0x30);
      iVar2 = 6;
      puVar4 = local_58;
      do {
        iVar2 = rmMemPoolSetup(*(undefined8 *)(param_2 + 0x128),puVar4,iVar2);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "rmMemPoolSetup((void*)pHeap->pPmaObject, &pCtxBufPool->pMemPool[i], poolConfig)"
                     ,"src/kernel/mem_mgr/ctx_buf_pool.c",0xa6);
          ctxBufPoolDestroy(local_40);
          local_58 = local_40[0];
LAB_00449a54:
          *param_3 = local_58;
          return iVar2;
        }
        cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
        if (cVar1 != '\0') {
          rmMemPoolAllocateProtectedMemory(*puVar4,1);
        }
        if (uVar3 == 3) {
          nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0xb1,"ctxBufPoolInit",1,
                       "NVRM: Ctx buf pool successfully initialized\n");
          goto LAB_00449a54;
        }
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 1;
        if (uVar3 < 4) {
          iVar2 = 5 - uVar3;
        }
        else {
          iVar2 = 6;
        }
      } while( true );
    }
    iVar2 = 0x51;
    nvAssertFailedNoLog("(pCtxBufPool != NULL)","src/kernel/mem_mgr/ctx_buf_pool.c",0x87);
  }
  return iVar2;
}


// ===== 00449b20 ctxBufPoolTrim =====

undefined8 ctxBufPoolTrim(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  if (param_1 != 0) {
    uVar1 = 0;
    do {
      rmMemPoolTrim(*(undefined8 *)(param_1 + uVar1 * 8),0,0);
      uVar2 = uVar1 & 0xffffffff;
      uVar1 = uVar1 + 1;
      nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x15d,"ctxBufPoolTrim",1,
                   "NVRM: Trimmed pool with RM_ATTR_PAGE_SIZE_* = 0x%x\n",uVar2);
    } while (uVar1 != 6);
    return 0;
  }
  nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x158);
  return 0x1f;
}


// ===== 00449bb0 ctxBufPoolRelease =====

void ctxBufPoolRelease(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x173);
  }
  puVar1 = param_1 + 6;
  do {
    uVar2 = *param_1;
    param_1 = param_1 + 1;
    rmMemPoolRelease(uVar2,0);
  } while (param_1 != puVar1);
  return;
}


// ===== 00449c10 ctxBufPoolGetGlobalPool =====

undefined8 ctxBufPoolGetGlobalPool(long param_1,int param_2,int param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = gpuGetKernelFifoShared_IMPL();
  if (param_4 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("ppCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x228);
  }
  else {
    uVar1 = param_3 - 1;
    if (uVar1 < 0x53) {
      if (param_2 == 1) {
        uVar2 = kfifoGetRunlistBufPool_IMPL(param_1,uVar2,param_3);
LAB_00449ca5:
        *param_4 = uVar2;
        return 0;
      }
      if (param_2 == 2) {
        if (uVar1 < 8) {
          uVar2 = kgraphicsGetCtxBufPool_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1bd0 + (ulong)uVar1 * 8));
          goto LAB_00449ca5;
        }
        nvAssertFailedNoLog("RM_ENGINE_TYPE_IS_GR(rmEngineType)","src/kernel/mem_mgr/ctx_buf_pool.c"
                            ,0x233);
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x238,"ctxBufPoolGetGlobalPool",4,
                     "NVRM: Invalid buf Id = 0x%x requested\n",param_2);
      }
    }
    else {
      nvAssertFailedNoLog("RM_ENGINE_TYPE_IS_VALID(rmEngineType)",
                          "src/kernel/mem_mgr/ctx_buf_pool.c",0x229);
    }
  }
  return 0x1f;
}


// ===== 00449d30 ctxBufPoolGetSizeAndPageSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ctxBufPoolGetSizeAndPageSize
              (undefined8 *param_1,long param_2,ulong param_3,uint param_4,char param_5,
              ulong *param_6,ulong *param_7)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 local_58;
  undefined4 local_54;
  ulong local_50;
  ulong local_48;
  ulong local_40 [2];
  
  lVar2 = *(long *)(param_2 + 0x1b78);
  local_50 = 0;
  local_58 = 0;
  local_54 = 0;
  local_48 = 0;
  if (param_6 == (ulong *)0x0) {
    nvAssertFailedNoLog("pSize != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x25f);
  }
  else {
    if (param_7 != (ulong *)0x0) {
      local_48 = *param_6;
      if (param_4 == 3) {
        local_58 = 0x1800000;
        uVar6 = 0x100000;
        uVar5 = 0x1800000;
        local_54 = 0x100000;
      }
      else if (param_4 < 4) {
        if (param_4 == 1) {
          local_58 = 0x800000;
        }
        else if (param_4 == 2) {
          local_58 = 0x1000000;
          uVar6 = 0;
          uVar5 = 0x1000000;
          goto LAB_00449dc8;
        }
        uVar6 = 0;
        uVar5 = 0x800000;
      }
      else if (param_4 == 4) {
        local_58 = 0x1800000;
        uVar6 = 0x200000;
        uVar5 = 0x1800000;
        local_54 = 0x200000;
      }
      else {
        if (param_4 != 5) {
          nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x27d,"ctxBufPoolGetSizeAndPageSize",4,
                       "NVRM: unsupported page size attr\n");
          return 0x56;
        }
        local_58 = 0x1800000;
        uVar6 = 0x300000;
        uVar5 = 0x1800000;
        local_54 = 0x300000;
      }
LAB_00449dc8:
      local_40[0] = param_3;
      iVar4 = (**(code **)(lVar2 + 0x1f8))(param_2,lVar2,&local_48,local_40,0,0,uVar5,uVar6,0);
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x28f,"ctxBufPoolGetSizeAndPageSize",4,
                     "NVRM: Couldn\'t determine buffer alignment\n");
        return iVar4;
      }
      if (param_5 == '\0') {
        local_50 = (**(code **)(lVar2 + 0x168))(lVar2,0,local_48,0,0,&local_58,&local_54);
        uVar3 = local_48;
LAB_00449eed:
        local_48 = uVar3;
        if ((local_50 == 0) || (local_50 < param_3)) {
          nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x2b8,"ctxBufPoolGetSizeAndPageSize",4,
                       "NVRM: Incorrect page size determination\n");
          return 0x40;
        }
        *param_7 = local_50;
        local_48 = (local_50 - 1) + local_48 & -local_50;
        *param_6 = local_48;
        nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x2c3,"ctxBufPoolGetSizeAndPageSize",1,
                     "NVRM: Buffer updated size = 0x%llx with page size = 0x%llx\n",local_48,
                     local_50);
        iVar4 = 0;
      }
      else {
        local_40[0] = 0;
        puVar1 = param_1 + 6;
        while (iVar4 = rmMemPoolGetChunkAndPageSize(*param_1,local_40,&local_50), iVar4 == 0) {
          uVar3 = local_40[0];
          if (local_48 <= local_40[0]) goto LAB_00449eed;
          param_1 = param_1 + 1;
          if (param_1 == puVar1) {
            nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x2a8,"ctxBufPoolGetSizeAndPageSize",4,
                         "NVRM: couldn\'t find pool with chunksize >= 0x%llx\n");
            return 0x51;
          }
        }
        nvAssertOkFailedNoLog
                  (iVar4,
                   "rmMemPoolGetChunkAndPageSize(pCtxBufPool->pMemPool[i], &chunkSize, &pageSize)",
                   "src/kernel/mem_mgr/ctx_buf_pool.c",0x29f);
      }
      return iVar4;
    }
    nvAssertFailedNoLog("pPageSize != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x260);
  }
  return 0x1f;
}


// ===== 0044a140 ctxBufPoolReserve =====

int ctxBufPoolReserve(undefined8 param_1,long param_2,long *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uStack_90;
  ulong local_78;
  long local_70 [8];
  
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  local_70[6] = 0;
  if (param_2 == 0) {
    nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x10e);
  }
  else if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("pBufInfoList != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x10f);
  }
  else {
    if (param_4 != 0) {
      iVar3 = 0;
      do {
        local_70[0] = *param_3;
        iVar2 = ctxBufPoolGetSizeAndPageSize
                          (param_2,param_1,param_3[1],(int)param_3[2],
                           *(undefined1 *)((long)param_3 + 0x14),local_70,&local_78);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "ctxBufPoolGetSizeAndPageSize(pCtxBufPool, pGpu, pBufInfoList[i].align, pBufInfoList[i].attr, pBufInfoList[i].bContig, &size, &pageSize)"
                     ,"src/kernel/mem_mgr/ctx_buf_pool.c",0x117,uStack_90);
          return iVar2;
        }
        if (local_78 == 0x200000) {
          local_70[4] = local_70[4] + local_70[0];
        }
        else if (local_78 < 0x200001) {
          if ((local_78 - 0x10000 & 0xfffffffffffeffff) == 0) {
            local_70[3] = local_70[3] + local_70[0];
          }
          else {
            if (local_78 != 0x1000) {
LAB_0044a320:
              nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x131,"ctxBufPoolReserve",4,
                           "NVRM: Unrecognized/unsupported page size = 0x%llx\n",local_78);
              nvAssertFailedNoLog(&DAT_00d7d7b6,"src/kernel/mem_mgr/ctx_buf_pool.c",0x132);
              return 0x1f;
            }
            local_70[2] = local_70[2] + local_70[0];
          }
        }
        else if (local_78 == 0x20000000) {
          local_70[5] = local_70[5] + local_70[0];
        }
        else {
          if (local_78 != 0x4000000000) goto LAB_0044a320;
          local_70[6] = local_70[6] + local_70[0];
        }
        uStack_90 = local_78;
        param_3 = param_3 + 3;
        iVar2 = iVar3 + 1;
        nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x134,"ctxBufPoolReserve",1,
                     "NVRM: Reserving 0x%llx bytes for buf Id = 0x%x in pool with page size = 0x%llx\n"
                     ,local_70[0],iVar3);
        iVar3 = iVar2;
        if (param_4 == iVar2) {
          lVar4 = 0;
          do {
            lVar1 = local_70[lVar4 + 1];
            if (lVar1 != 0) {
              iVar3 = rmMemPoolReserve(*(undefined8 *)(param_2 + lVar4 * 8),lVar1,0);
              if (iVar3 != 0) {
                nvAssertOkFailedNoLog
                          (iVar3,"rmMemPoolReserve(pCtxBufPool->pMemPool[i], totalSize[i], 0)",
                           "src/kernel/mem_mgr/ctx_buf_pool.c",0x13b);
                iVar2 = ctxBufPoolTrim(param_2);
                if (iVar2 != 0) {
                  nvAssertOkFailedNoLog
                            (0x1f,"ctxBufPoolTrim(pCtxBufPool)","src/kernel/mem_mgr/ctx_buf_pool.c",
                             0x143);
                }
                nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x144,"ctxBufPoolReserve",4,
                             "NVRM: Failed to reserve memory. trimming all pools\n");
                return iVar3;
              }
              nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x13c,"ctxBufPoolReserve",1,
                           "NVRM: Reserved 0x%llx bytes in pool with RM_ATTR_PAGE_SIZE_* = 0x%x\n",
                           lVar1,lVar4);
            }
            lVar4 = lVar4 + 1;
          } while (lVar4 != 6);
          return 0;
        }
      } while( true );
    }
    nvAssertFailedNoLog("bufCount > 0","src/kernel/mem_mgr/ctx_buf_pool.c",0x110);
  }
  return 0x1f;
}


// ===== 0044a4f0 ctxBufPoolAllocate =====

int ctxBufPoolAllocate(long param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong local_30 [2];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x18b);
    return 0x1f;
  }
  if (param_2 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x18c);
    return 0x1f;
  }
  iVar3 = memdescGetAddressSpace(param_2);
  if (iVar3 != 2) {
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x191,"ctxBufPoolAllocate",4,
                 "NVRM: ctx buf pool is only used for buffers to be allocated in FB\nSYSMEM buffers don\'t need memory to be pre-reserved in pool\n"
                );
    return 0x1f;
  }
  uVar4 = memdescGetPageSize(param_2,1);
  if (uVar4 == 0) {
    uVar1 = memdescGetContiguity(param_2,1);
    iVar3 = ctxBufPoolGetSizeAndPageSize(param_1,*param_2,param_2[5],0,uVar1,param_2 + 7,local_30);
    if (iVar3 != 0) {
LAB_0044a583:
      uVar5 = 0x19b;
      pcVar6 = 
      "ctxBufPoolGetSizeAndPageSize(pCtxBufPool, pMemDesc->pGpu, pMemDesc->Alignment, RM_ATTR_PAGE_SIZE_DEFAULT, memdescGetContiguity(pMemDesc, AT_GPU), &pMemDesc->ActualSize, &newPageSize)"
      ;
      goto LAB_0044a59d;
    }
    memdescSetPageSize(param_2,1,local_30[0]);
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x1a9,"ctxBufPoolAllocate",1,
                 "NVRM: Ctx buffer page size set to 0x%llx\n",local_30[0]);
    uVar4 = local_30[0];
  }
  else {
    cVar2 = memdescGetContiguity(param_2,1);
    if (cVar2 != '\0') {
      uVar1 = memdescGetContiguity(param_2,1);
      iVar3 = ctxBufPoolGetSizeAndPageSize(param_1,*param_2,param_2[5],0,uVar1,param_2 + 7,local_30)
      ;
      uVar4 = local_30[0];
      if (iVar3 != 0) goto LAB_0044a583;
    }
  }
  if (uVar4 == 0x200000) {
    uVar5 = *(undefined8 *)(param_1 + 0x18);
  }
  else if (uVar4 < 0x200001) {
    if ((uVar4 - 0x10000 & 0xfffffffffffeffff) == 0) {
      uVar5 = *(undefined8 *)(param_1 + 0x10);
    }
    else {
      if (uVar4 != 0x1000) {
LAB_0044a7d0:
        nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x1c2,"ctxBufPoolAllocate",4,
                     "NVRM: Unsupported page size = 0x%llx set for context buffer\n",uVar4);
        nvAssertFailedNoLog(&DAT_00d7d7b6,"src/kernel/mem_mgr/ctx_buf_pool.c",0x1c3);
        return 0x1f;
      }
      uVar5 = *(undefined8 *)(param_1 + 8);
    }
  }
  else if (uVar4 == 0x20000000) {
    uVar5 = *(undefined8 *)(param_1 + 0x20);
  }
  else {
    if (uVar4 != 0x4000000000) goto LAB_0044a7d0;
    uVar5 = *(undefined8 *)(param_1 + 0x28);
  }
  iVar3 = rmMemPoolAllocate(uVar5,param_2);
  if (iVar3 == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x1c6,"ctxBufPoolAllocate",1,
                 "NVRM: Buffer allocated from ctx buf pool with page size = 0x%llx\n",uVar4);
    return 0;
  }
  uVar5 = 0x1c5;
  pcVar6 = "rmMemPoolAllocate(pPool, (RM_POOL_ALLOC_MEMDESC*)pMemDesc)";
LAB_0044a59d:
  nvAssertOkFailedNoLog(iVar3,pcVar6,"src/kernel/mem_mgr/ctx_buf_pool.c",uVar5);
  return iVar3;
}


// ===== 0044a850 ctxBufPoolFree =====

int ctxBufPoolFree(long param_1,long *param_2)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong local_38;
  long local_30 [2];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x1da);
    return 0x1f;
  }
  if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x1db);
    return 0x1f;
  }
  uVar3 = memdescGetPageSize(param_2,1);
  local_38 = uVar3;
  cVar1 = memdescGetContiguity(param_2,1);
  if (cVar1 != '\0') {
    local_30[0] = param_2[7];
    iVar2 = ctxBufPoolGetSizeAndPageSize(param_1,*param_2,param_2[5],0,1,local_30,&local_38);
    uVar3 = local_38;
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "ctxBufPoolGetSizeAndPageSize(pCtxBufPool, pMemDesc->pGpu, pMemDesc->Alignment, RM_ATTR_PAGE_SIZE_DEFAULT, NV_TRUE, &size, &pageSize)"
                 ,"src/kernel/mem_mgr/ctx_buf_pool.c",0x1e8);
      return iVar2;
    }
  }
  if (uVar3 == 0x200000) {
    uVar4 = *(undefined8 *)(param_1 + 0x18);
  }
  else if (uVar3 < 0x200001) {
    if ((uVar3 - 0x10000 & 0xfffffffffffeffff) != 0) {
      if (uVar3 != 0x1000) {
LAB_0044aa10:
        nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x1ff,"ctxBufPoolFree",4,
                     "NVRM: Unsupported page size detected for context buffer\n");
        nvAssertFailedNoLog(&DAT_00d7d7b6,"src/kernel/mem_mgr/ctx_buf_pool.c",0x200);
        return 0x40;
      }
      uVar4 = *(undefined8 *)(param_1 + 8);
      cVar1 = rmMemPoolIsScrubSkipped(uVar4);
      goto joined_r0x0044a946;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x10);
  }
  else if (uVar3 == 0x20000000) {
    uVar4 = *(undefined8 *)(param_1 + 0x20);
  }
  else {
    if (uVar3 != 0x4000000000) goto LAB_0044aa10;
    uVar4 = *(undefined8 *)(param_1 + 0x28);
  }
  cVar1 = rmMemPoolIsScrubSkipped(uVar4);
joined_r0x0044a946:
  if (cVar1 != '\0') {
    memmgrMemsetInBlocks_IMPL(*(undefined8 *)(*param_2 + 0x1b78),param_2,0,0,param_2[6],0,0);
  }
  rmMemPoolFree(uVar4,param_2,0);
  nvDbg_Printf("src/kernel/mem_mgr/ctx_buf_pool.c",0x20e,"ctxBufPoolFree",1,
               "NVRM: Buffer freed from ctx buf pool with page size = 0x%llx\n",uVar3);
  return 0;
}


// ===== 0044aae0 ctxBufPoolIsScrubSkipped =====

undefined8 ctxBufPoolIsScrubSkipped(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x2d5);
    return 0x1f;
  }
  puVar1 = param_1 + 6;
  do {
    uVar2 = rmMemPoolIsScrubSkipped(*param_1);
    if ((char)uVar2 == '\0') {
      return uVar2;
    }
    param_1 = param_1 + 1;
  } while (param_1 != puVar1);
  return 1;
}


// ===== 0044ab60 ctxBufPoolSetScrubSkip =====

void ctxBufPoolSetScrubSkip(undefined8 *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar1 = param_1 + 6;
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      rmMemPoolSkipScrub(uVar2,param_2);
    } while (param_1 != puVar1);
    return;
  }
  nvAssertFailedNoLog("pCtxBufPool != NULL","src/kernel/mem_mgr/ctx_buf_pool.c",0x2ee);
  return;
}


// ===== 0044abc8 fabricvaspaceConstruct__IMPL.cold =====

void fabricvaspaceConstruct__IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044abe0 fabricvaspaceConstruct__IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int fabricvaspaceConstruct__IMPL
              (long param_1,int param_2,int param_3,ulong param_4,ulong param_5,undefined8 param_6,
              undefined8 param_7,uint param_8)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined8 extraout_RDX;
  bool bVar10;
  undefined8 uVar11;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar8 = rmapiGetInterface(4);
  uVar1 = *(undefined8 *)(g_pSys + 0x230);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar2 = *(long *)(param_1 + 0x88);
  uVar4 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(lVar2 + 0x48));
  lVar9 = gpumgrGetGpu(uVar4);
  local_7c = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_74 = 0;
  if (param_2 == 0xfc) {
    if (param_5 < param_4) {
      nvAssertFailedNoLog("vaStart <= vaLimit","src/kernel/mem_mgr/fabric_vaspace.c",0xf7);
    }
    else {
      uVar6 = *(uint *)(lVar2 + 0x48);
      if ((uVar6 == 0) || ((uVar6 - 1 & uVar6) != 0)) {
        nvAssertFailedNoLog("ONEBITSET(pVAS->gpuMask)","src/kernel/mem_mgr/fabric_vaspace.c",0xf8);
      }
      else {
        if (*(int *)(lVar9 + 0x7ac) == param_3) {
          iVar5 = vgpuGetCallingContextGfid(lVar9,&local_74);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,"vgpuGetCallingContextGfid(pGpu, &gfid)",
                       "src/kernel/mem_mgr/fabric_vaspace.c",0xfa);
            return iVar5;
          }
          uVar11 = 4;
          iVar5 = (**(code **)(lVar8 + 8))(lVar8,0,0,0,0,&local_7c);
          if (iVar5 == 0) {
            iVar5 = serverutilGenResourceHandle(local_7c,&local_78,extraout_RDX,uVar11);
            if (iVar5 == 0) {
              local_70 = CONCAT44(local_70._4_4_,*(undefined4 *)(lVar9 + 0x7b4));
              iVar5 = (**(code **)(lVar8 + 8))(lVar8,local_7c,local_7c,local_78,0x80,&local_70,0x38)
              ;
              if (iVar5 == 0) {
                uVar6 = param_8 | 0x98000;
                *(uint *)(param_1 + 0xac) = uVar6;
                if (local_74 != 0) {
                  *(int *)(param_1 + 0xe0) = local_74;
                  uVar6 = param_8 | 0x80098000;
                  *(uint *)(param_1 + 0xac) = uVar6;
                }
                bVar10 = false;
                if (*(char *)(lVar9 + 0x908) != '\0') {
                  bVar10 = *(char *)(lVar9 + 0x491e) != '\0';
                }
                *(bool *)(param_1 + 0xa8) = bVar10;
                iVar5 = vmmCreateVaspace_IMPL
                                  (uVar1,0x90f1,0,*(undefined4 *)(lVar2 + 0x48),param_4,param_5,0,0,
                                   0,uVar6,param_1 + 0x98);
                if (iVar5 == 0) {
                  *(long *)(param_1 + 0xb0) = lVar9;
                  *(ulong *)(param_1 + 0xa0) = CONCAT44(local_78,local_7c);
                  *(undefined8 *)(lVar2 + 0x60) = *(undefined8 *)(*(long *)(param_1 + 0x98) + 0x60);
                  *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68);
                  return 0;
                }
                nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x12d,
                             "fabricvaspaceConstruct__IMPL",4,
                             "NVRM: Failed allocating gvaspace associated with the fabric vaspace, status=0x%x\n"
                            );
              }
              else {
                nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x114,
                             "fabricvaspaceConstruct__IMPL",4,
                             "NVRM: failed creating device, status=0x%x\n");
              }
            }
            else {
              nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x108,
                           "fabricvaspaceConstruct__IMPL",4,
                           "NVRM: failed creating device handle, status=0x%x\n",iVar5);
            }
            iVar7 = (**(code **)(lVar8 + 0x18))(lVar8,local_7c,local_7c);
            if (iVar7 == 0) {
              return iVar5;
            }
            nvAssertFailedNoLog("pRmApi->Free(pRmApi, hClient, hClient) == NV_OK",
                                "src/kernel/mem_mgr/fabric_vaspace.c",0x13e);
            return iVar5;
          }
          nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x101,"fabricvaspaceConstruct__IMPL",4,
                       "NVRM: failed creating client, status=0x%x\n",iVar5);
          return iVar5;
        }
        nvAssertFailedNoLog("vaspaceId == pGpu->gpuId","src/kernel/mem_mgr/fabric_vaspace.c",0xf9);
      }
    }
  }
  else {
    nvAssertFailedNoLog("FABRIC_VASPACE_A == classId","src/kernel/mem_mgr/fabric_vaspace.c",0xf6);
  }
  return 0x1f;
}


// ===== 0044b040 fabricvaspaceDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void fabricvaspaceDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = 0;
  lVar5 = rmapiGetInterface(4);
  if (param_1 != 0) {
    lVar6 = *(long *)(param_1 + 0x88);
  }
  if (*(long *)(param_1 + 0x98) != 0) {
    uVar1 = *(undefined8 *)(g_pSys + 0x230);
    iVar4 = (**(code **)(lVar5 + 0x18))
                      (lVar5,*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa0),
                       *(code **)(lVar5 + 0x18));
    if (iVar4 != 0) {
      nvAssertFailedNoLog("pRmApi->Free(pRmApi, pFabricVAS->hClient, pFabricVAS->hClient) == NV_OK",
                          "src/kernel/mem_mgr/fabric_vaspace.c",0x151);
    }
    uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x98),__nvoc_class_def_OBJGVASPACE);
    cVar3 = gvaspaceIsInUse_IMPL(uVar2);
    if (cVar3 != '\0') {
      nvAssertFailedNoLog("!gvaspaceIsInUse(dynamicCast(pFabricVAS->pGVAS, OBJGVASPACE))",
                          "src/kernel/mem_mgr/fabric_vaspace.c",0x155);
    }
    vmmDestroyVaspace_IMPL(uVar1,*(undefined8 *)(param_1 + 0x98));
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(lVar6 + 0x60) = 0;
    *(undefined8 *)(lVar6 + 0x68) = 0;
  }
  return;
}


// ===== 0044b140 fabricvaspaceAlloc_IMPL =====

char fabricvaspaceAlloc_IMPL(void)

{
  char cVar1;
  
  cVar1 = fabricIsMemAllocDisabled_IMPL(*(undefined8 *)(g_pSys + 0x260));
  return (-(cVar1 == '\0') & 0x16U) + 0x40;
}


// ===== 0044b170 fabricvaspaceFree_IMPL =====

undefined8 fabricvaspaceFree_IMPL(void)

{
  nvAssertFailedNoLog(&DAT_00d7e036,"src/kernel/mem_mgr/fabric_vaspace.c",0x227);
  return 0x56;
}


// ===== 0044b1a0 fabricvaspaceMap_IMPL =====

undefined8 fabricvaspaceMap_IMPL(void)

{
  return 0x56;
}


// ===== 0044b1b0 fabricvaspaceUnmap_IMPL =====

void fabricvaspaceUnmap_IMPL(void)

{
  return;
}


// ===== 0044b1c0 fabricvaspaceApplyDefaultAlignment_IMPL =====

undefined8 fabricvaspaceApplyDefaultAlignment_IMPL(void)

{
  return 0x56;
}


// ===== 0044b1d0 fabricvaspaceGetVasInfo_IMPL =====

undefined8 fabricvaspaceGetVasInfo_IMPL(void)

{
  return 0x56;
}


// ===== 0044b1e0 fabricvaspacePinRootPageDir_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 fabricvaspacePinRootPageDir_IMPL(long param_1)

{
  undefined8 uVar1;
  
  if (*(long **)(param_1 + 0x98) != (long *)0x0) {
    uVar1 = (**(code **)(**(long **)(param_1 + 0x98) + 0xd0))();
    return uVar1;
  }
  nvAssertFailedNoLog("pFabricVAS->pGVAS != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x263);
  return 0x57;
}


// ===== 0044b230 fabricvaspaceUnpinRootPageDir_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fabricvaspaceUnpinRootPageDir_IMPL(long param_1,undefined8 param_2)

{
  if (*(long **)(param_1 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x98) + 0xd8))();
    return;
  }
  nvAssertFailedNoLog("pFabricVAS->pGVAS != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x26f);
  (**(code **)(**(long **)(param_1 + 0x98) + 0xd8))(*(long **)(param_1 + 0x98),param_2);
  return;
}


// ===== 0044b2b0 fabricvaspaceGetFreeHeap_IMPL =====

undefined8 fabricvaspaceGetFreeHeap_IMPL(long param_1,undefined8 *param_2)

{
  if (*(long *)(param_1 + 0x98) == 0) {
    nvAssertFailedNoLog("pFabricVAS->pGVAS != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x27b);
    return 0x57;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0xd8);
    return 0;
  }
  nvAssertFailedNoLog("freeSize != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x27c);
  return 0x1f;
}


// ===== 0044b320 fabricvaspaceBatchFree_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

void fabricvaspaceBatchFree_IMPL(long *param_1,long param_2,int param_3,int param_4)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  long local_50 [4];
  
  lVar1 = param_1[0x16];
  lVar8 = *(long *)(&DAT_00001b90 + lVar1);
  lVar13 = 0;
  if (param_3 != 0) {
    iVar12 = 0;
    uVar10 = 0;
    lVar14 = 0;
    do {
      while( true ) {
        plVar2 = (long *)param_1[0x13];
        uVar11 = (ulong)(uint)((int)uVar10 + param_4);
        uVar3 = *(ulong *)(param_2 + uVar10 * 8);
        uVar10 = uVar11;
        lVar13 = lVar14;
        if (uVar3 < (ulong)param_1[0x18]) break;
        uVar11 = param_1[0x19];
        iVar6 = (**(code **)(*plVar2 + 0x100))(plVar2,uVar3,local_50);
        if (iVar6 != 0) {
          nvAssertFailedNoLog("vaspaceFreeV2(pFabricVAS->pGVAS, pAddr[idx], &freeSize) == NV_OK",
                              "src/kernel/mem_mgr/fabric_vaspace.c",0x29a);
        }
        lVar13 = lVar14 + local_50[0];
        if (uVar11 <= uVar3) {
          lVar13 = lVar14;
        }
LAB_0044b3a9:
        iVar12 = iVar12 + 1;
        lVar14 = lVar13;
        if (param_3 == iVar12) goto LAB_0044b41b;
      }
      iVar6 = (**(code **)(*plVar2 + 0x100))(plVar2,uVar3,local_50);
      if (iVar6 == 0) goto LAB_0044b3a9;
      iVar12 = iVar12 + 1;
      nvAssertFailedNoLog("vaspaceFreeV2(pFabricVAS->pGVAS, pAddr[idx], &freeSize) == NV_OK",
                          "src/kernel/mem_mgr/fabric_vaspace.c",0x29a);
    } while (param_3 != iVar12);
  }
LAB_0044b41b:
  (**(code **)(lVar8 + 0x500))(lVar1,lVar8,3);
  (**(code **)(*param_1 + 0x168))(param_1,0,1);
  uVar7 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(param_1[0x11] + 0x48));
  lVar8 = gpumgrGetGpu(uVar7);
  local_50[1] = 0;
  lVar1 = *(long *)(&DAT_00001b90 + lVar8);
  local_50[2] = 0;
  uVar4 = *(undefined8 *)(lVar8 + 0x1b98);
  if (*(char *)(lVar1 + 0xa848) != '\0') {
    uVar9 = __nvoc_dynamicCast(param_1[0x13],__nvoc_class_def_OBJGVASPACE);
    cVar5 = gvaspaceIsInUse_IMPL(uVar9);
    if (cVar5 == '\0') {
      iVar12 = (**(code **)(lVar1 + 0x3c8))(lVar8,lVar1);
      if (iVar12 != 0) {
        nvAssertFailedNoLog("kbusSetupUnbindFla_HAL(pGpu, pKernelBus) == NV_OK",
                            "src/kernel/mem_mgr/fabric_vaspace.c",0xb7);
      }
      if (*(long *)(lVar1 + 0xa820) != 0) {
        iVar12 = kgmmuInstBlkInit_IMPL
                           (uVar4,*(undefined8 *)(lVar1 + 0xa828),*(long *)(lVar1 + 0xa820),
                            0xffffffff,local_50 + 1);
        if (iVar12 != 0) {
          nvAssertFailedNoLog("kgmmuInstBlkInit(pKernelGmmu, pKernelBus->flaInfo.pInstblkMemDesc, pKernelBus->flaInfo.pFlaVAS, FIFO_PDB_IDX_BASE, &instblkParams) == NV_OK"
                              ,"src/kernel/mem_mgr/fabric_vaspace.c",0xbc);
        }
        iVar12 = (**(code **)(lVar1 + 0x3d0))(lVar8,lVar1,(int)param_1[0x1c]);
        if (iVar12 != 0) {
          nvAssertFailedNoLog("kbusSetupBindFla_HAL(pGpu, pKernelBus, pFabricVAS->gfid) == NV_OK",
                              "src/kernel/mem_mgr/fabric_vaspace.c",0xc3);
        }
      }
    }
  }
  param_1[0x1b] = param_1[0x1b] + lVar13;
  param_1[0x1a] = param_1[0x1a] - lVar13;
  return;
}


// ===== 0044b5c0 fabricvaspaceAllocNonContiguous_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int fabricvaspaceAllocNonContiguous_IMPL
              (long param_1,ulong param_2,ulong param_3,ulong param_4,long param_5,ulong param_6,
              ushort param_7,long *param_8,uint *param_9)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong *puVar11;
  byte local_88;
  byte local_58;
  ulong local_48 [3];
  
  cVar4 = fabricIsMemAllocDisabled_IMPL(*(undefined8 *)(g_pSys + 0x260));
  if (cVar4 != '\0') {
    return 0x40;
  }
  if (*(long *)(param_1 + 0x98) == 0) {
    nvAssertFailedNoLog("pFabricVAS->pGVAS != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x192);
    return 0x57;
  }
  if (param_8 == (long *)0x0) {
    nvAssertFailedNoLog("ppAddr != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x193);
    return 0x1f;
  }
  if (param_9 == (uint *)0x0) {
    nvAssertFailedNoLog("pNumAddr != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x194);
    return 0x1f;
  }
  if (param_6 < 0x200000) {
    nvAssertFailedNoLog("pageSize >= RM_PAGE_SIZE_HUGE","src/kernel/mem_mgr/fabric_vaspace.c",0x195)
    ;
    return 0x1f;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("align != 0","src/kernel/mem_mgr/fabric_vaspace.c",0x196);
    return 0x1f;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("size != 0","src/kernel/mem_mgr/fabric_vaspace.c",0x197);
    return 0x1f;
  }
  uVar1 = param_6 - 1;
  if ((param_3 & uVar1) != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED64(align, pageSize)","src/kernel/mem_mgr/fabric_vaspace.c",
                        0x19a);
    return 0x1f;
  }
  if ((uVar1 & param_2) != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED64(size, pageSize)","src/kernel/mem_mgr/fabric_vaspace.c",
                        0x19b);
    return 0x1f;
  }
  uVar7 = param_2 / param_6;
  if (uVar7 >> 0x20 != 0) {
    nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x1a5,"fabricvaspaceAllocNonContiguous_IMPL",
                 4,"NVRM: Page count 0x%llx exceeds NvU32 max\n",uVar7);
    return 0x1f;
  }
  if (*(ulong *)(param_1 + 0xd8) < param_2) {
    nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x1b0,"fabricvaspaceAllocNonContiguous_IMPL",
                 4,
                 "NVRM: Not enough memory in eheap, size requested = 0x%llx, free memory = 0x%llx\n"
                 ,param_2,*(ulong *)(param_1 + 0xd8));
    return 0x51;
  }
  local_58 = (byte)(param_7 >> 8);
  local_88 = local_58 & 1;
  if ((param_7 & 0x200) == 0) {
    local_88 = local_88 ^ 1;
  }
  else {
    local_88 = 0;
    if ((param_7 >> 8 & 1) != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x1b9,
                   "fabricvaspaceAllocNonContiguous_IMPL",4,
                   "NVRM: Forcing both contiguous and noncontiguous is not allowed\n");
      return 0x1f;
    }
  }
  lVar8 = portMemAllocNonPaged(uVar7 * 8);
  *param_8 = lVar8;
  if (lVar8 == 0) {
    return 0x51;
  }
  portMemSet(lVar8,0,uVar7 * 8);
  lVar8 = *(long *)(param_1 + 0xb0);
  lVar2 = *(long *)(&DAT_00001b90 + lVar8);
  if (*(char *)(lVar2 + 0xa848) != '\0') {
    uVar3 = *(undefined8 *)(lVar8 + 0x1b98);
    uVar9 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 0xa820),__nvoc_class_def_OBJGVASPACE);
    cVar4 = gvaspaceIsInUse_IMPL(uVar9);
    if (cVar4 == '\0') {
      uVar9 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x98),__nvoc_class_def_OBJGVASPACE);
      cVar4 = gvaspaceIsInUse_IMPL(uVar9);
      if (cVar4 != '\0') goto LAB_0044ba20;
      iVar5 = (**(code **)(lVar2 + 0x3c8))(lVar8,lVar2);
      if (iVar5 == 0) {
        portMemSet(local_48,0,0x10);
        iVar5 = kgmmuInstBlkInit_IMPL
                          (uVar3,*(undefined8 *)(lVar2 + 0xa828),*(undefined8 *)(param_1 + 0x98),
                           0xffffffff,local_48);
        if (iVar5 == 0) {
          iVar5 = (**(code **)(lVar2 + 0x3d0))(lVar8,lVar2,*(undefined4 *)(param_1 + 0xe0));
          if (iVar5 == 0) goto LAB_0044ba20;
          nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x81,"_fabricvaspaceBindInstBlk",4,
                       "NVRM: Failed to bind instance block for fabricVAS, status=0x%x\n",iVar5);
        }
        else {
          nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x77,"_fabricvaspaceBindInstBlk",4,
                       "NVRM: Failed to setup instance block for fabricVAS, status=0x%x\n",iVar5);
        }
        portMemSet(local_48,0,0x10);
        iVar6 = kgmmuInstBlkInit_IMPL
                          (uVar3,*(undefined8 *)(lVar2 + 0xa828),*(undefined8 *)(lVar2 + 0xa820),
                           0xffffffff,local_48);
        if (iVar6 != 0) {
          nvAssertFailedNoLog("kgmmuInstBlkInit(pKernelGmmu, pKernelBus->flaInfo.pInstblkMemDesc, pKernelBus->flaInfo.pFlaVAS, FIFO_PDB_IDX_BASE, &instblkParams) == NV_OK"
                              ,"src/kernel/mem_mgr/fabric_vaspace.c",0x8c);
        }
        iVar6 = (**(code **)(lVar2 + 0x3d0))(lVar8,lVar2,*(undefined4 *)(param_1 + 0xe0));
        if (iVar6 != 0) {
          nvAssertFailedNoLog("kbusSetupBindFla_HAL(pGpu, pKernelBus, pFabricVAS->gfid) == NV_OK",
                              "src/kernel/mem_mgr/fabric_vaspace.c",0x91);
        }
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x6a,"_fabricvaspaceBindInstBlk",4,
                     "NVRM: Failed to unbind instance block for FlaVAS, status=0x%x\n",iVar5);
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x57,"_fabricvaspaceBindInstBlk",4,
                   "NVRM: FabricVAS and FlaVAS cannot be used simultaneously! Instance block setup for fabricVAS failed\n"
                  );
      iVar5 = 0x38;
    }
    nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x1ce,"fabricvaspaceAllocNonContiguous_IMPL",
                 4,"NVRM: Failed to bind instance block for fabric vaspace. Alloc failed\n");
LAB_0044b952:
    *(long *)(param_1 + 0xd8) = *(long *)(param_1 + 0xd8) + *param_9 * param_6;
    *(long *)(param_1 + 0xd0) = *(long *)(param_1 + 0xd0) - *param_9 * param_6;
    fabricvaspaceBatchFree_IMPL(param_1,*param_8,*param_9,1);
    portMemFree(*param_8);
    *param_8 = 0;
    *param_9 = 0;
    return iVar5;
  }
LAB_0044ba20:
  param_4 = param_4 & -param_6;
  uVar10 = -param_6 & (param_6 - 1) + param_5;
  *param_9 = 0;
  if (((param_7 >> 8 & 1) == 0) && (local_88 == 0)) {
joined_r0x0044bca7:
    if ((param_7 & 0x200) == 0) goto LAB_0044bcad;
  }
  else {
    iVar5 = (**(code **)(**(long **)(param_1 + 0x98) + 0x38))
                      (*(long **)(param_1 + 0x98),param_2,param_3,param_4,uVar10,0x200000,param_7,
                       local_48);
    if (iVar5 == 0) {
      *(ulong *)*param_8 = local_48[0];
      *param_9 = 1;
      goto joined_r0x0044bca7;
    }
    if ((param_7 & 0x100) != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x1e7,
                   "fabricvaspaceAllocNonContiguous_IMPL",4,
                   "NVRM: Failed to allocate contig vaspace\n");
      goto LAB_0044b952;
    }
    if (((param_7 & 0x200) == 0) && (local_88 == 0)) goto LAB_0044bcad;
  }
  if ((int)uVar7 != 0) {
    lVar8 = 0;
    do {
      param_7 = CONCAT11(local_58,(char)param_7);
      puVar11 = local_48;
      iVar5 = (**(code **)(**(long **)(param_1 + 0x98) + 0x38))
                        (*(long **)(param_1 + 0x98),param_6,param_3,param_4,uVar10,0x200000,param_7)
      ;
      if (iVar5 != 0) {
        nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x203,
                     "fabricvaspaceAllocNonContiguous_IMPL",4,"NVRM: Failed to allocate vaspace\n");
        goto LAB_0044b952;
      }
      if ((uVar1 & local_48[0]) != 0) {
        nvAssertFailedNoLog("NV_IS_ALIGNED64(addr, pageSize)","src/kernel/mem_mgr/fabric_vaspace.c",
                            0x1fc,puVar11);
      }
      *(ulong *)(*param_8 + lVar8) = local_48[0];
      lVar8 = lVar8 + 8;
      *param_9 = *param_9 + 1;
    } while (lVar8 != (uVar7 & 0xffffffff) << 3);
  }
LAB_0044bcad:
  *(long *)(param_1 + 0xd8) = *(long *)(param_1 + 0xd8) - param_2;
  *(long *)(param_1 + 0xd0) = *(long *)(param_1 + 0xd0) + param_2;
  return 0;
}


// ===== 0044bf00 fabricvaspaceInvalidateTlb_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fabricvaspaceInvalidateTlb_IMPL(long param_1)

{
  (**(code **)(**(long **)(param_1 + 0x98) + 0xe0))
            (*(long **)(param_1 + 0x98),*(undefined8 *)(param_1 + 0xb0));
  return;
}


// ===== 0044bf30 fabricvaspaceGetGpaMemdesc_IMPL =====

int fabricvaspaceGetGpaMemdesc_IMPL(long param_1,long param_2,undefined8 param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *local_38;
  long local_30;
  
  local_38 = (long *)0x0;
  local_30 = 0;
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("ppAdjustedMemdesc != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x2c7);
    return 0x1f;
  }
  iVar2 = memdescGetAddressSpace(param_2);
  if ((iVar2 == 6) && (cVar1 = memdescGetFlag(param_2,0x100000000000000), cVar1 == '\0')) {
    uVar3 = memdescGetRootMemDesc(param_2,&local_30);
    uVar4 = memdescGetPhysAddr(uVar3,1,0);
    if ((*(ulong *)(param_1 + 0xc0) <= uVar4) && (uVar4 <= *(ulong *)(param_1 + 200))) {
      iVar2 = btreeSearch(uVar4,&local_38,*(undefined8 *)(param_1 + 0xb8));
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"btreeSearch(physAddr, &pNode, pFabricVAS->pFabricVaToGpaMap)",
                   "src/kernel/mem_mgr/fabric_vaspace.c",0x2e4);
        return iVar2;
      }
      iVar2 = memdescCreateSubMem(param_4,*(undefined8 *)(*local_38 + 0x38),param_3,
                                  local_30 + *(long *)(*local_38 + 0x40),
                                  *(undefined8 *)(param_2 + 0x30));
      if (iVar2 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x2f7,"fabricvaspaceGetGpaMemdesc_IMPL",4,
                   "NVRM: Failed to create submMemdesc for the GVA->PA mapping\n");
      return iVar2;
    }
  }
  *param_4 = param_2;
  return 0;
}


// ===== 0044c0d0 fabricvaspacePutGpaMemdesc_IMPL =====

void fabricvaspacePutGpaMemdesc_IMPL(undefined8 param_1,undefined8 param_2)

{
  memdescDestroy(param_2);
  return;
}


// ===== 0044c0e0 fabricvaspaceVaToGpaMapRemove_IMPL =====

void fabricvaspaceVaToGpaMapRemove_IMPL(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *local_20 [2];
  
  local_20[0] = (undefined8 *)0x0;
  iVar2 = btreeSearch(param_2,local_20,*(undefined8 *)(param_1 + 0xb8));
  if (iVar2 != 0) {
    return;
  }
  uVar1 = *local_20[0];
  btreeUnlink(uVar1,param_1 + 0xb8);
  portMemFree(uVar1);
  return;
}


// ===== 0044c140 fabricvaspaceVaToGpaMapInsert_IMPL =====

int fabricvaspaceVaToGpaMapInsert_IMPL
              (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = portMemAllocNonPaged(0x48);
  if (lVar2 == 0) {
    iVar1 = 0x51;
  }
  else {
    portMemSet(lVar2,0,0x48);
    *(undefined8 *)(lVar2 + 0x38) = param_3;
    *(undefined8 *)(lVar2 + 0x40) = param_4;
    *(undefined8 *)(lVar2 + 8) = param_2;
    *(undefined8 *)(lVar2 + 0x10) = param_2;
    *(long *)lVar2 = lVar2;
    iVar1 = btreeInsert(lVar2,param_1 + 0xb8);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x339,"fabricvaspaceVaToGpaMapInsert_IMPL",
                   4,"NVRM: Failed to insert addr 0x%llx into the memory fabric tree\n",
                   *(undefined8 *)(lVar2 + 8));
      portMemFree(lVar2);
    }
  }
  return iVar1;
}


// ===== 0044c220 fabricvaspaceAllocMulticast_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong fabricvaspaceAllocMulticast_IMPL
                (long param_1,ulong param_2,ulong param_3,undefined2 param_4,ulong param_5,
                ulong param_6)

{
  long *plVar1;
  char cVar2;
  ulong uVar3;
  ulong local_40 [2];
  
  local_40[0] = 0;
  cVar2 = fabricIsMemAllocDisabled_IMPL(*(undefined8 *)(g_pSys + 0x260));
  uVar3 = 0x40;
  if (cVar2 == '\0') {
    plVar1 = *(long **)(param_1 + 0x98);
    if (plVar1 != (long *)0x0) {
      if (param_2 < 0x200000) {
        nvAssertFailedNoLog("pageSize >= RM_PAGE_SIZE_HUGE","src/kernel/mem_mgr/fabric_vaspace.c",
                            0x35a);
      }
      else if (param_3 == 0) {
        nvAssertFailedNoLog("alignment != 0","src/kernel/mem_mgr/fabric_vaspace.c",0x35b);
      }
      else if (param_6 == 0) {
        nvAssertFailedNoLog("size != 0","src/kernel/mem_mgr/fabric_vaspace.c",0x35c);
      }
      else {
        param_2 = param_2 - 1;
        if ((param_2 & param_3) == 0) {
          if ((param_2 & param_5) == 0) {
            if ((param_2 & param_6) == 0) {
              uVar3 = (**(code **)(*plVar1 + 0x38))
                                (plVar1,param_6,param_3,param_5,(param_5 - 1) + param_6,0x200000,
                                 param_4);
              if (local_40[0] == param_5) {
                return uVar3;
              }
              nvAssertFailedNoLog("addr == base","src/kernel/mem_mgr/fabric_vaspace.c",0x36b,
                                  local_40);
              return uVar3 & 0xffffffff;
            }
            nvAssertFailedNoLog("NV_IS_ALIGNED64(size, pageSize)",
                                "src/kernel/mem_mgr/fabric_vaspace.c",0x35f);
          }
          else {
            nvAssertFailedNoLog("NV_IS_ALIGNED64(base, pageSize)",
                                "src/kernel/mem_mgr/fabric_vaspace.c",0x35e);
          }
        }
        else {
          nvAssertFailedNoLog("NV_IS_ALIGNED64(alignment, pageSize)",
                              "src/kernel/mem_mgr/fabric_vaspace.c",0x35d);
        }
      }
      return 0x1f;
    }
    nvAssertFailedNoLog("pFabricVAS->pGVAS != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x359);
    uVar3 = 0x57;
  }
  return uVar3;
}


// ===== 0044c420 fabricvaspaceUnmapPhysMemdesc_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fabricvaspaceUnmapPhysMemdesc_IMPL
               (long *param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong *puVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  bool bVar12;
  ulong local_68 [7];
  
  uVar3 = memdescGetPageSize(param_2,1);
  uVar9 = (uVar3 - 1) + param_3 & -uVar3;
  if (param_3 < uVar9) {
    uVar4 = uVar9 - param_3;
    if (uVar4 <= param_4) {
      param_4 = (param_4 + param_3) - uVar9;
      uVar5 = 1;
      local_68[0] = param_3;
      local_68[1] = uVar4;
      if (param_4 == 0) goto LAB_0044c4d2;
      uVar4 = 2;
      bVar12 = true;
      lVar10 = 1;
      goto LAB_0044c62a;
    }
    if (param_4 == 0) goto LAB_0044c678;
    uVar5 = 1;
    lVar10 = 0;
  }
  else {
    if (param_4 == 0) {
LAB_0044c678:
      nvAssertFailedNoLog("numRegions != 0","src/kernel/mem_mgr/fabric_vaspace.c",0x3f7);
      return;
    }
    bVar12 = param_3 == uVar9;
    uVar4 = 1;
    lVar10 = 0;
    uVar9 = param_3;
LAB_0044c62a:
    uVar7 = -uVar3 & param_4;
    uVar5 = uVar4;
    param_3 = uVar9;
    if ((uVar3 <= uVar7) && (bVar12)) {
      local_68[lVar10 * 2] = uVar9;
      local_68[lVar10 * 2 + 1] = uVar7;
      if (param_4 - uVar7 != 0) {
        uVar5 = (ulong)((int)lVar10 + 2);
        local_68[uVar4 * 2] = uVar9 + uVar7;
        local_68[uVar4 * 2 + 1] = param_4 - uVar7;
      }
      goto LAB_0044c4d2;
    }
  }
  local_68[lVar10 * 2] = param_3;
  local_68[lVar10 * 2 + 1] = param_4;
LAB_0044c4d2:
  puVar8 = local_68;
  puVar6 = puVar8 + uVar5 * 2;
  do {
    iVar1 = memdescGetPteArraySize(param_2,1);
    uVar9 = puVar8[1];
    uVar2 = 1;
    if (iVar1 == 1) {
LAB_0044c540:
      uVar11 = 0;
      uVar4 = *puVar8;
      do {
        uVar11 = uVar11 + 1;
        lVar10 = memdescGetPhysAddr(param_2,1,uVar4);
        (**(code **)(*(long *)param_1[0x13] + 0x80))
                  ((long *)param_1[0x13],param_1[0x16],lVar10,lVar10 + (uVar9 - 1));
        uVar4 = uVar4 + uVar9;
      } while (uVar11 < uVar2);
    }
    else {
      if (uVar9 < uVar3) {
        uVar2 = 1;
        goto LAB_0044c540;
      }
      uVar2 = (uint)(uVar9 / uVar3);
      if ((uVar2 == 1) || (uVar9 = uVar3, uVar2 != 0)) goto LAB_0044c540;
    }
    puVar8 = puVar8 + 2;
    if (puVar6 == puVar8) {
      (**(code **)(*param_1 + 0x168))(param_1,0,1);
      return;
    }
  } while( true );
}


// ===== 0044c6b0 fabricvaspaceMapPhysMemdesc_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong fabricvaspaceMapPhysMemdesc_IMPL
                (long *param_1,long param_2,ulong param_3,long *param_4,ulong param_5,ulong param_6,
                uint param_7)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  char cVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 uVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  undefined8 extraout_RDX;
  ulong *puVar18;
  long lVar19;
  ulong *puVar20;
  bool bVar21;
  undefined1 auVar22 [16];
  ulong local_130;
  undefined4 local_124;
  ulong local_f0;
  int local_e4;
  ulong local_e0;
  undefined1 local_cc [4];
  undefined8 local_c8;
  long *local_c0;
  undefined1 local_b4 [28];
  undefined8 *local_98;
  undefined4 local_90;
  int local_8c;
  ulong local_68 [7];
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pFabricMemDesc != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x436);
    return 0x1f;
  }
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("pPhysMemDesc != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x437);
    return 0x1f;
  }
  lVar2 = param_1[0x16];
  lVar3 = *(long *)(lVar2 + 0x1bb8);
  uVar10 = memdescGetPageSize(param_4,1);
  uVar11 = memdescGetPageSize(param_2,1);
  uVar12 = uVar10 - 1;
  if (((param_3 & uVar12) == 0) && (param_3 < *(ulong *)(param_2 + 0x30))) {
    if (((param_5 & uVar12) == 0) && (param_5 < (ulong)param_4[6])) {
      if ((((param_6 == 0) || ((uVar12 & param_6) != 0)) || (param_4[6] - param_5 < param_6)) ||
         (*(ulong *)(param_2 + 0x30) - param_3 < param_6)) {
        nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x394,"_fabricVaspaceValidateMapAttrs",4,
                     "NVRM: Invalid map length passed for the physmem handle\n");
        uVar7 = 0x1f;
        goto LAB_0044cb9b;
      }
      if ((char)param_1[0x15] != '\0') {
        return 0;
      }
      lVar19 = *(long *)(*param_4 + 0x1b78);
      uVar7 = memmgrGetKindComprFromMemDesc_IMPL(lVar19,param_4,param_5,local_cc,local_b4);
      if (uVar7 != 0) {
        nvAssertOkFailedNoLog(uVar7,"status","src/kernel/mem_mgr/fabric_vaspace.c",0x44e);
        goto LAB_0044cd8d;
      }
      iVar8 = memdescGetAddressSpace(param_4);
      if (iVar8 == 2) {
        local_124 = 0xffffffff;
        local_e4 = 1;
      }
      else {
        cVar5 = memdescIsEgm(param_4);
        if (cVar5 == '\0') {
          iVar8 = memdescGetAddressSpace(param_4);
          if (iVar8 != 1) {
            nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x46b,
                         "fabricvaspaceMapPhysMemdesc_IMPL",4,"NVRM: Unsupported aperture\n");
            nvAssertFailedNoLog(&DAT_00d7e036,"src/kernel/mem_mgr/fabric_vaspace.c",0x46c);
            return 0x1f;
          }
          local_124 = 0xffffffff;
          local_e4 = 4 - (uint)(*(int *)((long)param_4 + 0x74) != 0);
        }
        else {
          if (*(char *)(lVar19 + 0x454) == '\0') {
            nvAssertFailedNoLog("pPhysMemManager->bLocalEgmEnabled",
                                "src/kernel/mem_mgr/fabric_vaspace.c",0x45b);
            return 0x40;
          }
          local_e4 = 2;
          local_124 = *(undefined4 *)(lVar19 + 0x458);
        }
      }
      uVar12 = (uVar11 - 1) + param_3 & -uVar11;
      if (param_3 < uVar12) {
        uVar16 = uVar12 - param_3;
        if (param_6 < uVar16) {
          uVar16 = 0;
          uVar17 = 1;
          goto LAB_0044c8cb;
        }
        param_6 = (param_3 + param_6) - uVar12;
        uVar17 = 1;
        local_68[0] = param_3;
        local_68[1] = uVar16;
        if (param_6 != 0) {
          uVar15 = 2;
          bVar21 = true;
          uVar16 = 1;
          goto LAB_0044c89e;
        }
      }
      else {
        bVar21 = param_3 == uVar12;
        uVar15 = 1;
        uVar16 = 0;
        uVar12 = param_3;
LAB_0044c89e:
        param_3 = uVar12;
        uVar12 = -uVar11 & param_6;
        uVar17 = uVar15;
        if ((uVar11 <= uVar12) && (bVar21)) {
          local_68[uVar16 * 2] = param_3;
          local_68[uVar16 * 2 + 1] = uVar12;
          param_6 = param_6 - uVar12;
          if (param_6 == 0) goto LAB_0044c8d9;
          param_3 = param_3 + uVar12;
          uVar17 = (ulong)((int)uVar16 + 2);
          uVar16 = uVar15;
        }
LAB_0044c8cb:
        local_68[uVar16 * 2] = param_3;
        local_68[uVar16 * 2 + 1] = param_6;
      }
LAB_0044c8d9:
      local_130 = 0;
      local_f0 = param_5;
      do {
        iVar8 = memdescGetPteArraySize(param_2,1);
        local_e0 = local_68[local_130 * 2 + 1];
        if (((iVar8 == 1) || (local_e0 < uVar11)) || (iVar8 = (int)(local_e0 / uVar11), iVar8 == 1))
        {
          uVar12 = local_68[local_130 * 2];
          portMemSet(&local_98,0,0x30);
          iVar8 = memdescGetPteArraySize(param_4,1);
          if (iVar8 == 1) {
            local_8c = 1;
            iVar8 = 1;
          }
          else {
            iVar8 = 1;
            local_8c = (int)(local_e0 / *(uint *)(param_4 + 0x2c));
          }
LAB_0044c9a0:
          iVar9 = 0;
          lVar19 = uVar12 - local_f0;
          do {
            lVar14 = memdescGetPhysAddr(param_2,1,local_f0 + lVar19);
            dmaPageArrayInitFromMemDesc(&local_98,param_4,1);
            if (local_8c == 1) {
              auVar22 = memdescGetPhysAddr(param_4,1,local_f0);
              local_98 = &local_c8;
            }
            else {
              auVar22._8_8_ = local_f0 % (ulong)*(uint *)(param_4 + 0x2c);
              auVar22._0_8_ = local_c8;
              local_90 = (undefined4)(local_f0 / *(uint *)(param_4 + 0x2c));
            }
            local_c8 = auVar22._0_8_;
            plVar4 = param_4;
            if (uVar11 < uVar10) {
              uVar12 = memdescCreateSubMem(&local_c0,param_4,*param_4,local_f0,local_e0);
              if ((int)uVar12 != 0) goto LAB_0044ccf8;
              memdescSetPageSize(local_c0,1,uVar11);
              auVar22._8_8_ = extraout_RDX;
              auVar22._0_8_ = local_c8;
              plVar4 = local_c0;
            }
            local_c0 = plVar4;
            local_c8 = auVar22._0_8_;
            uVar13 = memdescGetPageSize(local_c0,1,auVar22._8_8_);
            uVar6 = (**(code **)(lVar3 + 0x188))(lVar3,local_c0,local_e4,0);
            uVar12 = (**(code **)(lVar3 + 400))
                               (lVar2,lVar3,param_1[0x13],local_c0,0,lVar14,(local_e0 - 1) + lVar14,
                                (param_7 & 1) << 0x1b | 0x17ff,&local_98,local_b4,0,1,local_e4,uVar6
                                ,local_124,0xffffffffffffffff,1,0,uVar13);
            if (local_c0 != param_4) {
              memdescDestroy();
              uVar12 = uVar12 & 0xffffffff;
            }
            if ((int)uVar12 != 0) {
LAB_0044ccf8:
              if ((int)local_130 == 0) {
                return uVar12;
              }
              puVar18 = local_68;
              puVar20 = puVar18 + local_130 * 2;
              do {
                puVar1 = puVar18 + 1;
                uVar10 = *puVar18;
                puVar18 = puVar18 + 2;
                fabricvaspaceUnmapPhysMemdesc_IMPL(param_1,param_2,uVar10,*puVar1);
              } while (puVar18 != puVar20);
              return uVar12 & 0xffffffff;
            }
            local_f0 = local_f0 + local_e0;
            iVar9 = iVar9 + 1;
          } while (iVar9 != iVar8);
        }
        else {
          uVar12 = local_68[local_130 * 2];
          portMemSet(&local_98,0,0x30);
          iVar9 = memdescGetPteArraySize(param_4,1);
          local_8c = 1;
          if (iVar9 != 1) {
            local_8c = (int)(uVar11 / *(uint *)(param_4 + 0x2c));
          }
          local_e0 = uVar11;
          if (iVar8 != 0) goto LAB_0044c9a0;
        }
        local_130 = local_130 + 1;
      } while (local_130 != uVar17);
      (**(code **)(*param_1 + 0x168))(param_1,0,0);
LAB_0044cd8d:
      return (ulong)uVar7;
    }
    nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x389,"_fabricVaspaceValidateMapAttrs",4,
                 "NVRM: Invalid offset passed for the physmem handle\n");
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x380,"_fabricVaspaceValidateMapAttrs",4,
                 "NVRM: Invalid offset passed for the fabric handle\n");
  }
  uVar7 = 0x37;
LAB_0044cb9b:
  nvCheckOkFailedNoLog(4,uVar7,"status","src/kernel/mem_mgr/fabric_vaspace.c",0x445);
  return (ulong)uVar7;
}


// ===== 0044cf10 fabricvaspaceInitUCRange_IMPL =====

undefined8 fabricvaspaceInitUCRange_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  
  if (*(long *)(param_1 + 200) != 0) {
    return 0x17;
  }
  if (param_4 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/mem_mgr/fabric_vaspace.c",0x4df,"fabricvaspaceInitUCRange_IMPL",1,
               "NVRM: Setting UC Base: %llx, size: %llx \n",param_3,param_4);
  *(long *)(param_1 + 0xc0) = param_3;
  *(long *)(param_1 + 200) = param_4 + -1 + param_3;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(long *)(param_1 + 0xd8) = param_4;
  if (*(char *)(param_2 + 0x908) != '\0') {
    lVar1 = gpuGetStaticInfo(param_2);
    *(long *)(lVar1 + 0xa790) = param_3;
    *(long *)(lVar1 + 0xa798) = param_4;
  }
  return 0;
}


// ===== 0044d000 fabricvaspaceClearUCRange_IMPL =====

void fabricvaspaceClearUCRange_IMPL(long param_1)

{
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  return;
}


// ===== 0044d040 fabricvaspaceGetPageLevelInfo_IMPL =====

undefined8 fabricvaspaceGetPageLevelInfo_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x98),__nvoc_class_def_OBJGVASPACE);
  if (lVar1 != 0) {
    uVar2 = gvaspaceGetPageLevelInfo_IMPL(lVar1,param_2,param_3);
    return uVar2;
  }
  nvAssertFailedNoLog("pGVAS != NULL","src/kernel/mem_mgr/fabric_vaspace.c",0x507);
  return 0x57;
}


// ===== 0044d0b0 fabricvaspaceIsInUse_IMPL =====

void fabricvaspaceIsInUse_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x98),__nvoc_class_def_OBJGVASPACE);
  gvaspaceIsInUse_IMPL(uVar1);
  return;
}


// ===== 0044d0e0 _gvaspaceReserveTopForGrowth =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _gvaspaceReserveTopForGrowth(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined4 local_24;
  undefined1 local_20 [8];
  long local_18;
  long local_10;
  
  uVar1 = *(ulong *)(param_1 + 0x140);
  if (*(ulong *)(param_1 + 0x108) <= uVar1) {
    return 0;
  }
  local_18 = uVar1 + 1;
  local_10 = *(ulong *)(param_1 + 0x108) - uVar1;
  local_24 = 0x10;
  uVar2 = (**(code **)(*(long *)(param_1 + 0x98) + 8))
                    (*(long *)(param_1 + 0x98),0x72737664,&local_24,&local_18,&local_10,1,1,local_20
                     ,0,0);
  return uVar2;
}


// ===== 0044d156 _gmmuWalkCBFillEntries_SkipExternal.cold =====

void _gmmuWalkCBFillEntries_SkipExternal_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044d160 _gmmuWalkCBFillEntries_SkipExternal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16]
_gmmuWalkCBFillEntries_SkipExternal
          (long *param_1,byte *param_2,undefined8 param_3,uint param_4,uint param_5,
          undefined8 param_6,int *param_7)

{
  byte bVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  undefined8 uStack_40;
  
  lVar2 = *param_1;
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  bVar1 = *param_2;
  uVar4 = ~(-1L << (param_2[1] + 1 & 0x3f)) & -1L << (bVar1 & 0x3f);
  uVar7 = (uint)((*(ulong *)(*(long *)(lVar2 + 0x88) + 0x60) & uVar4) >> (bVar1 & 0x3f));
  if (uVar7 <= param_4) {
    uVar7 = param_4;
  }
  uVar4 = (uVar4 & *(ulong *)(lVar2 + 0x140)) >> (bVar1 & 0x3f);
  piVar5 = (int *)(uVar4 & 0xffffffff);
  if (param_5 <= (uint)uVar4) {
    piVar5 = (int *)(ulong)param_5;
  }
  piVar6 = piVar5;
  if (uVar7 <= (uint)piVar5) {
    (*(code *)g_gmmuWalkCallbacks._32_8_)();
    piVar6 = param_7;
    param_3 = uStack_40;
    if (*param_7 != ((uint)piVar5 + 1) - uVar7) {
      auVar8 = nvAssertFailedNoLog("*pProgress == (entryIndexHiClamp - entryIndexLoClamp + 1)",
                                   "src/kernel/mem_mgr/gpu_vaspace.c",0xace);
      return auVar8;
    }
  }
  *param_7 = (param_5 + 1) - param_4;
  auVar8._8_8_ = param_3;
  auVar8._0_8_ = piVar6;
  return auVar8;
}


// ===== 0044d252 _gmmuWalkCBCopyEntries_SkipExternal.cold =====

void _gmmuWalkCBCopyEntries_SkipExternal_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044d260 _gmmuWalkCBCopyEntries_SkipExternal =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16]
_gmmuWalkCBCopyEntries_SkipExternal
          (long *param_1,byte *param_2,undefined8 param_3,undefined8 param_4,uint param_5,
          uint param_6,int *param_7)

{
  byte bVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  undefined8 uStack_40;
  
  lVar2 = *param_1;
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  bVar1 = *param_2;
  uVar4 = ~(-1L << (param_2[1] + 1 & 0x3f)) & -1L << (bVar1 & 0x3f);
  uVar7 = (uint)((*(ulong *)(*(long *)(lVar2 + 0x88) + 0x60) & uVar4) >> (bVar1 & 0x3f));
  if (uVar7 <= param_5) {
    uVar7 = param_5;
  }
  uVar4 = (uVar4 & *(ulong *)(lVar2 + 0x140)) >> (bVar1 & 0x3f);
  piVar5 = (int *)(uVar4 & 0xffffffff);
  if (param_6 <= (uint)uVar4) {
    piVar5 = (int *)(ulong)param_6;
  }
  piVar6 = piVar5;
  if (uVar7 <= (uint)piVar5) {
    (*(code *)g_gmmuWalkCallbacks._40_8_)();
    piVar6 = param_7;
    param_3 = uStack_40;
    if (*param_7 != ((uint)piVar5 + 1) - uVar7) {
      auVar8 = nvAssertFailedNoLog("*pProgress == (entryIndexHiClamp - entryIndexLoClamp + 1)",
                                   "src/kernel/mem_mgr/gpu_vaspace.c",0xaf1);
      return auVar8;
    }
  }
  *param_7 = (param_6 + 1) - param_5;
  auVar8._8_8_ = param_3;
  auVar8._0_8_ = piVar6;
  return auVar8;
}


// ===== 0044d370 _gvaspaceMappingInsert =====

ulong _gvaspaceMappingInsert
                (long param_1,long param_2,undefined8 *param_3,long param_4,long param_5,
                uint param_6)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  long local_30;
  
  lVar4 = 0;
  if (param_1 != 0) {
    lVar4 = *(long *)(param_1 + 0x88);
  }
  local_30 = 0;
  if ((param_6 & 1) == 0) {
    uVar1 = 1 << ((byte)*(undefined4 *)(param_2 + 0x7a4) & 0x1f);
    uVar5 = *(uint *)(lVar4 + 0x48) & uVar1;
    if (uVar5 == uVar1) {
      iVar2 = btreeSearch(param_4,&local_30,*param_3);
      if (iVar2 != 0) {
        local_30 = portMemAllocNonPaged(0x40);
        if (local_30 == 0) {
          nvAssertFailedNoLog("NULL != pMapNode","src/kernel/mem_mgr/gpu_vaspace.c",0x11cf);
          uVar3 = 0x51;
        }
        else {
          portMemSet(local_30,0,0x40);
          *(long *)(local_30 + 8) = param_4;
          *(long *)(local_30 + 0x10) = param_5;
          *(uint *)(local_30 + 0x38) = uVar5;
          uVar3 = btreeInsert(local_30,param_3);
          if ((int)uVar3 == 0) {
            return uVar3;
          }
          nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x11d8);
          portMemFree(local_30);
          uVar3 = uVar3 & 0xffffffff;
        }
        return uVar3;
      }
      if ((*(uint *)(local_30 + 0x38) & uVar5) == 0) {
        if (*(long *)(local_30 + 8) == param_4) {
          if (*(long *)(local_30 + 0x10) == param_5) {
            *(uint *)(local_30 + 0x38) = *(uint *)(local_30 + 0x38) | uVar5;
            return 0;
          }
          nvAssertFailedNoLog("pMapNode->node.keyEnd == vaHi","src/kernel/mem_mgr/gpu_vaspace.c",
                              0x11c6);
        }
        else {
          nvAssertFailedNoLog("pMapNode->node.keyStart == vaLo","src/kernel/mem_mgr/gpu_vaspace.c",
                              0x11c5);
        }
      }
      else {
        nvCheckFailedNoLog(4,"0 == (pMapNode->gpuMask & gpuMask)","src/kernel/mem_mgr/gpu_vaspace.c"
                           ,0x11c3);
      }
    }
    else {
      nvAssertFailedNoLog("gpuMask == (pVAS->gpuMask & gpuMask)","src/kernel/mem_mgr/gpu_vaspace.c",
                          0x11bc);
    }
  }
  else {
    nvAssertFailedNoLog("!flags.bRemap","src/kernel/mem_mgr/gpu_vaspace.c",0x11b9);
  }
  return 0x1f;
}


// ===== 0044d5a0 _gvaspaceMappingRemove =====

int _gvaspaceMappingRemove
              (undefined8 param_1,long param_2,undefined8 *param_3,ulong param_4,ulong param_5)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  char cVar8;
  long lVar9;
  ulong local_58;
  ulong local_50;
  long local_40 [2];
  
  uVar1 = *(undefined4 *)(param_2 + 0x7a4);
  local_40[0] = 0;
  iVar3 = btreeSearch(param_4,local_40,*param_3);
  if (iVar3 != 0) {
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1217);
    return iVar3;
  }
  uVar4 = 1 << ((byte)uVar1 & 0x1f);
  uVar5 = *(uint *)(local_40[0] + 0x38);
  if ((~uVar5 & uVar4) != 0) {
    nvAssertFailedNoLog("gpuMask == (pMapNode->gpuMask & gpuMask)",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0x121a);
    return 0x1f;
  }
  if (*(ulong *)(local_40[0] + 8) == param_4) {
    uVar7 = *(ulong *)(local_40[0] + 0x10);
    if (uVar7 != param_5) goto LAB_0044d625;
    *(uint *)(local_40[0] + 0x38) = ~uVar4 & uVar5;
    if ((~uVar4 & uVar5) == 0) {
      btreeUnlink(local_40[0],param_3);
      bVar2 = false;
      local_58 = param_5;
      local_50 = param_4;
      goto LAB_0044d69e;
    }
  }
  else {
    if (param_4 < *(ulong *)(local_40[0] + 8)) goto LAB_0044d7f0;
    uVar7 = *(ulong *)(local_40[0] + 0x10);
LAB_0044d625:
    if (uVar7 < param_5) {
LAB_0044d7f0:
      nvAssertFailedNoLog("pMapNode->node.keyStart <= vaLo && pMapNode->node.keyEnd >= vaHi",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0x121f);
      return 0x1f;
    }
    if (uVar5 != uVar4) {
      nvAssertFailedNoLog("pMapNode->gpuMask == gpuMask","src/kernel/mem_mgr/gpu_vaspace.c",0x1222);
      return 0x1f;
    }
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x1224,"_gvaspaceMappingRemove",1,
                 "NVRM: Partial unmap: Removing vaLo: 0x%llx vaHi: 0x%llx.\n",param_4);
    local_50 = *(ulong *)(local_40[0] + 8);
    local_58 = *(ulong *)(local_40[0] + 0x10);
    uVar5 = ~uVar4 & *(uint *)(local_40[0] + 0x38);
    *(uint *)(local_40[0] + 0x38) = uVar5;
    if (uVar5 == 0) {
      btreeUnlink(local_40[0],param_3);
    }
    bVar2 = true;
    if (local_50 < param_4) {
      lVar9 = param_4 - 1;
      iVar3 = _gvaspaceMappingInsert(param_1,param_2,param_3,local_50,lVar9,0,lVar9);
      if (iVar3 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1237);
        goto LAB_0044d8a6;
      }
      nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x1238,"_gvaspaceMappingRemove",1,
                   "NVRM: Partial unmap: Inserting partial vaLo: 0x%llx vaHi: 0x%llx. status: 0x%x\n"
                   ,local_50,lVar9,0);
      cVar8 = '\x01';
    }
    else {
LAB_0044d69e:
      cVar8 = '\0';
    }
    if (param_5 < local_58) {
      iVar3 = _gvaspaceMappingInsert(param_1,param_2,param_3,param_5 + 1,local_58,0);
      if (iVar3 == 0) {
        nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x1240,"_gvaspaceMappingRemove",1,
                     "NVRM: Partial unmap: Inserting partial vaLo: 0x%llx vaHi: 0x%llx. status: 0x%x\n"
                     ,param_5 + 1,local_58,0);
      }
      else {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x123f);
        if (bVar2) {
          if ((cVar8 != '\0') &&
             (iVar6 = _gvaspaceMappingRemove(param_1,param_2,param_3,local_50,param_4 - 1),
             iVar6 != 0)) {
            nvAssertOkFailedNoLog
                      (iVar6,"_gvaspaceMappingRemove(pGVAS, pGpu, pVASBlock, nodeVaLo, vaLo - 1)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x124c);
          }
LAB_0044d8a6:
          portMemSet(local_40[0],0,0x40);
          *(ulong *)(local_40[0] + 8) = local_50;
          *(uint *)(local_40[0] + 0x38) = uVar4;
          *(ulong *)(local_40[0] + 0x10) = local_58;
          iVar6 = btreeInsert(local_40[0],param_3);
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,"btreeInsert(&pMapNode->node, (NODE**)&pVASBlock->pMapTree)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x125a);
            return iVar3;
          }
          return iVar3;
        }
      }
      iVar6 = *(int *)(local_40[0] + 0x38);
      goto joined_r0x0044d7de;
    }
  }
  iVar6 = *(int *)(local_40[0] + 0x38);
  iVar3 = 0;
joined_r0x0044d7de:
  if (iVar6 == 0) {
    portMemFree();
    return iVar3;
  }
  return iVar3;
}


// ===== 0044d970 _gmmuWalkCBMapSingleEntry =====

void _gmmuWalkCBMapSingleEntry
               (long param_1,long *param_2,undefined8 param_3,int param_4,int param_5,
               undefined4 *param_6)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_58 = 0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x1b78);
  local_50 = 0;
  local_48 = 0;
  lVar2 = param_2[1];
  local_40 = 0;
  uVar4 = memdescGetPtePhysAddr(param_3,1,0);
  nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0xd06,"_gmmuWalkCBMapSingleEntry",1,
               "NVRM: [GPU%u]: PA 0x%llX, Entries 0x%X-0x%X\n",
               *(undefined4 *)(*(long *)(param_1 + 8) + 0x7a4),uVar4,param_4,param_5);
  if (param_4 == param_5) {
    local_50 = (ulong)((uint)*(byte *)(*param_2 + 2) * param_4);
    local_58 = param_3;
    iVar3 = memmgrMemWrite_IMPL(uVar1,&local_58,lVar2,*(undefined1 *)(*param_2 + 2),0);
    if (iVar3 == 0) {
      *param_6 = 1;
    }
    else {
      nvAssertFailedNoLog("memmgrMemWrite(pMemoryManager, &surf, pIter->entry.v8, pTarget->pLevelFmt->entrySize, TRANSFER_FLAGS_NONE) == NV_OK"
                          ,"src/kernel/mem_mgr/gpu_vaspace.c",0xd10);
    }
    return;
  }
  nvAssertFailedNoLog("entryIndexLo == entryIndexHi","src/kernel/mem_mgr/gpu_vaspace.c",0xd0b);
  return;
}


// ===== 0044dac0 _gvaspaceAddPartialPtRange =====

void _gvaspaceAddPartialPtRange(long param_1,ulong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xf0);
  if (uVar1 < 5) {
    if ((uVar1 == 0) ||
       ((ulong)(*(long *)(param_1 + 0xc0) + *(long *)(param_1 + 200 + (ulong)(uVar1 - 1) * 8)) <=
        param_2)) {
      *(ulong *)(param_1 + 200 + (ulong)uVar1 * 8) = param_2;
      *(uint *)(param_1 + 0xf0) = uVar1 + 1;
    }
    return;
  }
  nvAssertFailedNoLog("pGVAS->numPartialPtRanges < GVAS_MAX_PARTIAL_PAGE_TABLE_RANGES",
                      "src/kernel/mem_mgr/gpu_vaspace.c",999);
  return;
}


// ===== 0044db20 _gvaspaceFreeVASBlock =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16]
_gvaspaceFreeVASBlock
          (undefined8 param_1,long *param_2,undefined8 *param_3,undefined8 param_4,
          undefined4 *param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  ulong uStack_30;
  
  if ((*(int *)(param_3 + 4) != -1) && (*(int *)(param_3 + 4) != 0x72737664)) {
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x119a,"_gvaspaceFreeVASBlock",3,
                 "NVRM: Virtual allocation leak in range 0x%llX-0x%llX\n",*param_3,param_3[1]);
    (**(code **)(*param_2 + 0x138))(param_2,*param_3);
    *param_5 = 1;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uStack_30;
    return auVar1 << 0x40;
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_3;
  return auVar2 << 0x40;
}


// ===== 0044dbad _gvaspaceControl_Prolog.constprop.0.cold =====

void _gvaspaceControl_Prolog_constprop_0_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044dbc0 _gvaspaceControl_Prolog.constprop.0 =====

int _gvaspaceControl_Prolog_constprop_0
              (long param_1,int param_2,int param_3,long *param_4,long *param_5)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long local_48;
  long local_40 [2];
  
  local_48 = 0;
  if (param_1 != 0) {
    puVar1 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
    iVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                      (*puVar1,*(undefined4 *)(puVar1[3] + 0x10),*(undefined4 *)(puVar1 + 2),
                       &local_48);
    if (iVar3 == 0) {
      lVar5 = __nvoc_dynamicCast(local_48,__nvoc_class_def_OBJGVASPACE);
      *param_4 = lVar5;
      if (lVar5 == 0) {
        iVar3 = 0x22;
        nvAssertFailedNoLog("NULL != *ppGVAS","src/kernel/mem_mgr/gpu_vaspace.c",0xf7b);
      }
      else if (param_2 == 0) {
        uVar4 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(local_48 + 0x48));
        lVar5 = gpumgrGetGpu(uVar4);
        *param_5 = lVar5;
        if (param_3 != 0) {
          lVar5 = gpumgrGetGpuFromSubDeviceInst(*(undefined4 *)(lVar5 + 0x7b4),param_3 + -1);
          *param_5 = lVar5;
          if (lVar5 == 0) {
            iVar3 = 0x1f;
            nvAssertFailedNoLog("NULL != *ppGpu","src/kernel/mem_mgr/gpu_vaspace.c",0xf90);
          }
        }
      }
      else {
        iVar3 = subdeviceGetByHandle_IMPL
                          (**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),param_2,local_40);
        if (iVar3 == 0) {
          *param_5 = *(long *)(*(long *)(local_40[0] + 0x158) + 0xe0);
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "subdeviceGetByHandle(RES_GET_CLIENT(pVaspaceApi), hSubDevice, &pSubDevice)",
                     "src/kernel/mem_mgr/gpu_vaspace.c",0xf81);
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,
                 "vaspaceGetByHandleOrDeviceDefault(RES_GET_CLIENT(pVaspaceApi), RES_GET_PARENT_HANDLE(pVaspaceApi), RES_GET_HANDLE(pVaspaceApi), &pVAS)"
                 ,"src/kernel/mem_mgr/gpu_vaspace.c",0xf75);
    }
    return iVar3;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0044dd60 _gvaspaceReserveRange.part.0.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gvaspaceReserveRange_part_0_isra_0(long param_1,long param_2,long param_3)

{
  undefined4 local_24;
  undefined1 local_20 [8];
  long local_18;
  long local_10;
  
  local_10 = (param_3 + 1) - param_2;
  local_24 = 0x10;
  local_18 = param_2;
  (**(code **)(param_1 + 8))(param_1,0x72737664,&local_24,&local_18,&local_10,1,1,local_20,0,0);
  return;
}


// ===== 0044ddab gvaspaceApplyDefaultAlignment_IMPL.cold =====

void gvaspaceApplyDefaultAlignment_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044ddc0 gvaspaceApplyDefaultAlignment_IMPL =====

undefined4
gvaspaceApplyDefaultAlignment_IMPL
          (long param_1,long param_2,ulong *param_3,ulong *param_4,ulong *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  uVar2 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(*(long *)(param_1 + 0x88) + 0x48));
  lVar4 = gpumgrGetGpu(uVar2);
  uVar5 = *(ulong *)(param_1 + 0xa8);
  if (*(char *)(lVar4 + 0x4921) == '\0') {
    lVar4 = *(long *)(lVar4 + 0x1b98);
    uVar8 = *(ulong *)(param_1 + 0xa0);
    uVar3 = dmaNvos32ToPageSizeAttr
                      (**(undefined4 **)(param_2 + 0x90),(*(undefined4 **)(param_2 + 0x90))[1]);
    if (uVar3 == 3) {
      uVar6 = 0x200000;
      uVar8 = 0x200000;
      uVar7 = 0xffffffffffe00000;
      if (*(char *)(lVar4 + 0x67d0) == '\0') {
        nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                            "src/kernel/mem_mgr/gpu_vaspace.c",0x6a4);
        return 0x56;
      }
    }
    else if (uVar3 < 4) {
      if (uVar3 == 1) {
        uVar7 = 0xfffffffffffff000;
        uVar6 = 0x1000;
        uVar8 = 0x1000;
      }
      else if (uVar3 == 2) {
        uVar7 = -uVar8;
        uVar6 = uVar8;
      }
      else if ((~*(uint *)(param_2 + 0x44) & 0x1800000) == 0) {
        uVar6 = uVar8 | 0x201000;
        uVar8 = 0x200000;
        uVar7 = 0xffffffffffe00000;
        if (*(char *)(lVar4 + 0x67d0) == '\0') {
          nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                              "src/kernel/mem_mgr/gpu_vaspace.c",0x699);
          return 0x56;
        }
      }
      else {
        uVar7 = -uVar8;
        uVar6 = uVar8 | 0x1000;
      }
    }
    else if (uVar3 == 5) {
      if (*(char *)(lVar4 + 0x67d2) == '\0') {
        nvAssertFailedNoLog("kgmmuIsPageSize256gbSupported(pKernelGmmu)",
                            "src/kernel/mem_mgr/gpu_vaspace.c",0x6b1);
        return 0x56;
      }
      uVar6 = 0x4000000000;
      uVar7 = 0xffffffc000000000;
      uVar8 = 0x4000000000;
    }
    else {
      if (uVar3 == 6) {
        nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x6b7,"gvaspaceApplyDefaultAlignment_IMPL",4
                     ,"NVRM: Invalid page size attr\n");
        return 0x1f;
      }
      if (uVar3 == 4) {
        uVar6 = 0x20000000;
        uVar8 = 0x20000000;
        uVar7 = 0xffffffffe0000000;
        if (*(char *)(lVar4 + 0x67d1) == '\0') {
          nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                              "src/kernel/mem_mgr/gpu_vaspace.c",0x6aa);
          return 0x56;
        }
      }
      else {
        uVar7 = 0xfffffffffffff000;
        uVar6 = 0;
        uVar8 = 0x1000;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x684,"gvaspaceApplyDefaultAlignment_IMPL",4,
                 "NVRM: Overriding page size to 4k in Cache only Mode\n");
    uVar8 = 0x1000;
    uVar7 = 0xfffffffffffff000;
    uVar6 = 0x1000;
  }
  *param_5 = *param_5 | uVar6;
  *param_4 = (uVar8 - 1) + *param_4 & uVar7;
  uVar3 = *(uint *)(*(long *)(param_2 + 0x90) + 8);
  if ((uVar3 & 0x100) == 0) {
    if (uVar5 < *param_3) {
      uVar5 = *param_3;
    }
    if (uVar5 < uVar8) {
      uVar5 = uVar8;
    }
    *param_3 = uVar5;
    uVar3 = *(uint *)(*(long *)(param_2 + 0x90) + 8);
  }
  if ((uVar3 & 0x400000) != 0) {
    uVar5 = *param_3;
    if (*param_3 < *(ulong *)(param_1 + 0xb0)) {
      uVar5 = *(ulong *)(param_1 + 0xb0);
    }
    *param_3 = uVar5;
    *param_4 = -*(long *)(param_1 + 0xb0) & *(long *)(param_1 + 0xb0) + -1 + *param_4;
  }
  return 0;
}


// ===== 0044e100 gvaspaceIncAllocRefCnt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gvaspaceIncAllocRefCnt_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = (**(code **)(*(long *)(param_1 + 0x98) + 0x40))(*(long *)(param_1 + 0x98),param_2,0);
  if (lVar1 != 0) {
    *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) + 1;
    return 0;
  }
  return 0x1f;
}


// ===== 0044e140 gvaspaceGetHeap_IMPL =====

undefined8 gvaspaceGetHeap_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x98);
}


// ===== 0044e150 gvaspaceGetBigPageSize_IMPL =====

undefined8 gvaspaceGetBigPageSize_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0xa0);
}


// ===== 0044e160 gvaspaceIsFaultCapable_IMPL =====

undefined1 gvaspaceIsFaultCapable_IMPL(long param_1)

{
  return *(undefined1 *)(param_1 + 0xf4);
}


// ===== 0044e170 gvaspaceIsExternallyOwned_IMPL =====

undefined1 gvaspaceIsExternallyOwned_IMPL(long param_1)

{
  return *(undefined1 *)(param_1 + 0xf5);
}


// ===== 0044e180 gvaspaceIsAtsEnabled_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gvaspaceIsAtsEnabled_IMPL(long param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  
  bVar1 = *(byte *)(param_1 + 0x100);
  if (bVar1 == 0) {
    return 0;
  }
  uVar3 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(*(long *)(param_1 + 0x88) + 0x48));
  lVar4 = gpumgrGetGpu(uVar3);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x1bc0) != 0)) {
    cVar2 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(lVar4);
    if (cVar2 != '\0') {
      uVar5 = (**(code **)(lVar4 + 0x348))();
      return uVar5;
    }
  }
  return (ulong)bVar1;
}


// ===== 0044e200 gvaspaceGetPasid_IMPL =====

undefined1  [16] gvaspaceGetPasid_IMPL(long param_1,int *param_2)

{
  undefined1 auVar1 [16];
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  ulong uStack_20;
  
  if (param_2 == (int *)0x0) {
    nvAssertFailedNoLog("pPasid != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x741);
    auVar3._8_8_ = extraout_RDX;
    auVar3._0_8_ = 0x1f;
    return auVar3;
  }
  nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x743,"gvaspaceGetPasid_IMPL",1,
               "NVRM: ATS enabled: %u PASID: %u\n",*(undefined1 *)(param_1 + 0x100),
               *(undefined4 *)(param_1 + 0x104));
  if (*(char *)(param_1 + 0x100) != '\0') {
    if (*(int *)(param_1 + 0x104) != -1) {
      *param_2 = *(int *)(param_1 + 0x104);
      auVar1._8_8_ = 0;
      auVar1._0_8_ = uStack_20;
      return auVar1 << 0x40;
    }
    auVar2._8_8_ = uStack_20;
    auVar2._0_8_ = 0x55;
    return auVar2;
  }
  nvAssertFailedNoLog("pGVAS->bIsAtsEnabled","src/kernel/mem_mgr/gpu_vaspace.c",0x746);
  auVar4._8_8_ = extraout_RDX_00;
  auVar4._0_8_ = 0x40;
  return auVar4;
}


// ===== 0044e2e0 gvaspaceGetFlags_IMPL =====

undefined4 gvaspaceGetFlags_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0xb8);
}


// ===== 0044e2f0 gvaspaceGetGpuState_IMPL =====

long gvaspaceGetGpuState_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = 0;
  if (param_1 != 0) {
    lVar2 = *(long *)(param_1 + 0x88);
  }
  if (*(long *)(param_1 + 0x110) != 0) {
    if ((*(uint *)(lVar2 + 0x48) >> (*(uint *)(param_2 + 0x7a4) & 0x1f) & 1) == 0) {
      nvAssertFailedNoLog("pVAS->gpuMask & NVBIT32(pGpu->gpuInstance)",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0x777);
      lVar2 = 0;
    }
    else {
      uVar1 = ~(-1 << ((byte)*(uint *)(param_2 + 0x7a4) & 0x1f)) & *(uint *)(lVar2 + 0x48);
      uVar1 = uVar1 - (uVar1 >> 1 & 0x55555555);
      uVar1 = (uVar1 & 0x33333333) + (uVar1 >> 2 & 0x33333333);
      lVar2 = *(long *)(param_1 + 0x110) +
              (ulong)(((uVar1 >> 4) + uVar1 & 0xf0f0f0f) * 0x1010101 >> 0x18) * 0x78;
    }
    return lVar2;
  }
  nvAssertFailedNoLog("NULL != pGVAS->pGpuStates","src/kernel/mem_mgr/gpu_vaspace.c",0x776);
  return 0;
}


// ===== 0044e3c0 gvaspaceGetMapPageSize_IMPL =====

long gvaspaceGetMapPageSize_IMPL(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined4 local_44;
  long local_40 [2];
  
  uVar5 = 0;
  plVar2 = (long *)gvaspaceGetGpuState_IMPL();
  uVar1 = *(undefined8 *)(*plVar2 + 8);
  uVar3 = mmuFmtAllPageSizes(uVar1);
  do {
    if ((uVar3 >> (uVar5 & 0x3f) & 1) != 0) {
      local_40[0] = 0;
      local_44 = 0;
      uVar4 = mmuFmtFindLevelWithPageShift(uVar1,uVar5);
      mmuWalkGetPageLevelInfo(plVar2[1],uVar4,*param_3,local_40,&local_44);
      if (local_40[0] != 0) {
        return 1L << ((byte)uVar5 & 0x3f);
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x40);
  nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x713);
  return 0;
}


// ===== 0044e4a0 gvaspaceGetPageDirBase_IMPL =====

undefined8 gvaspaceGetPageDirBase_IMPL(long param_1)

{
  long *plVar1;
  undefined4 local_24;
  undefined8 local_20 [2];
  
  plVar1 = (long *)gvaspaceGetGpuState_IMPL();
  local_20[0] = 0;
  local_24 = 0;
  if (*(char *)(param_1 + 0xf5) != '\0') {
    return *(undefined8 *)(param_1 + 0xf8);
  }
  mmuWalkGetPageLevelInfo(plVar1[1],*(undefined8 *)(*plVar1 + 8),0,local_20,&local_24);
  return local_20[0];
}


// ===== 0044e510 gvaspaceGetGmmuFmt_IMPL =====

undefined8 gvaspaceGetGmmuFmt_IMPL(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)gvaspaceGetGpuState_IMPL();
  if (puVar1 != (undefined8 *)0x0) {
    return *puVar1;
  }
  nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x76e);
  return 0;
}


// ===== 0044e552 gvaspaceInvalidateTlb_IMPL.cold =====

void gvaspaceInvalidateTlb_IMPL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  
  *(undefined4 *)(unaff_RBP + -0x40) = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044e560 gvaspaceInvalidateTlb_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gvaspaceInvalidateTlb_IMPL(long param_1,long param_2,undefined4 param_3)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  char local_49;
  undefined4 local_48;
  undefined4 local_44;
  long local_40 [2];
  
  if (param_1 == 0) {
    local_48 = 0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  local_48 = 0;
  if ((*(uint *)(*(long *)(param_1 + 0x88) + 0x48) >> (*(uint *)(param_2 + 0x7a4) & 0x1f) & 1) != 0)
  {
    plVar4 = (long *)gvaspaceGetGpuState_IMPL();
    local_40[0] = 0;
    local_44 = 0;
    iVar3 = vgpuIsCallingContextPlugin(param_2,&local_49);
    if (iVar3 == 0) {
      if ((local_49 == '\0') && (iVar3 = vgpuGetCallingContextGfid(param_2,&local_48), iVar3 != 0))
      {
        nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                            "src/kernel/mem_mgr/gpu_vaspace.c",0x840);
        return;
      }
      bVar1 = *(byte *)(param_1 + 0xb9);
      mmuWalkGetPageLevelInfo(plVar4[1],*(undefined8 *)(*plVar4 + 8),0,local_40,&local_44);
      if (local_40[0] != 0) {
        (**(code **)(*(long *)(param_2 + 0x1b98) + 0x1e8))
                  (param_2,*(long *)(param_2 + 0x1b98),local_40[0],*(undefined4 *)(param_1 + 0xb8),
                   param_3,local_48,((bVar1 & 0x80) == 0) + '\x01',0);
      }
    }
    else {
      nvAssertFailedNoLog("vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin) == NV_OK",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0x83d);
    }
    return;
  }
  nvAssertFailedNoLog("0 != (NVBIT(pGpu->gpuInstance) & pVAS->gpuMask)",
                      "src/kernel/mem_mgr/gpu_vaspace.c",0x835);
  return;
}


// ===== 0044e6bd gvaspaceGetVasInfo_IMPL.cold =====

void gvaspaceGetVasInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044e6d0 gvaspaceGetVasInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gvaspaceGetVasInfo_IMPL(long param_1,int *param_2)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  undefined4 uVar5;
  long lVar6;
  long *plVar7;
  char *pcVar8;
  char *pcVar9;
  undefined8 uVar10;
  uint uVar11;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar2 = *(long **)(param_1 + 0x88);
  uVar5 = gpumgrGetDefaultPrimaryGpu((int)plVar2[9]);
  lVar6 = gpumgrGetGpu(uVar5);
  lVar3 = *(long *)(lVar6 + 0x1b98);
  plVar7 = (long *)gvaspaceGetGpuState_IMPL(param_1,lVar6);
  if (param_2 != (int *)0x0) {
    lVar6 = *plVar7;
    *param_2 = *(byte *)(*(long *)(lVar6 + 8) + 1) + 1;
    pcVar8 = (char *)mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar6 + 8),0xc);
    if (pcVar8 == (char *)0x0) {
      nvAssertFailedNoLog("pSmallPageTable","src/kernel/mem_mgr/gpu_vaspace.c",0x86e);
    }
    else {
      uVar5 = nvLogBase2(*(undefined8 *)(param_1 + 0xa0));
      pcVar9 = (char *)mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar6 + 8),uVar5);
      if (pcVar9 != (char *)0x0) {
        uVar11 = (uint)*(undefined8 *)(param_1 + 0xa0);
        param_2[3] = uVar11;
        *(ulong *)(param_2 + 0x2e) = (ulong)(uVar11 | 0x1000);
        if (*(char *)(lVar3 + 0x67d0) != '\0') {
          *(ulong *)(param_2 + 0x2e) = (ulong)(uVar11 | 0x201000);
        }
        if (*(char *)(lVar3 + 0x67d1) != '\0') {
          *(ulong *)(param_2 + 0x2e) = *(ulong *)(param_2 + 0x2e) | 0x20000000;
        }
        if (*(char *)(lVar3 + 0x67d2) != '\0') {
          *(ulong *)(param_2 + 0x2e) = *(ulong *)(param_2 + 0x2e) | 0x4000000000;
        }
        param_2[5] = 1;
        param_2[1] = (byte)pcVar9[1] + 1;
        param_2[7] = (uint)(byte)pcVar9[2] << ((pcVar9[1] - *pcVar9) + 1U & 0x1f);
        cVar1 = pcVar9[1];
        param_2[2] = 1;
        param_2[8] = (int)(1L << (cVar1 + 1U & 0x3f));
        param_2[9] = (uint)(byte)pcVar8[2] << ((pcVar8[1] - *pcVar8) + 1U & 0x1f);
        cVar1 = pcVar8[1];
        param_2[6] = uVar11;
        param_2[10] = (int)(1L << (cVar1 + 1U & 0x3f));
        uVar10 = (**(code **)(*plVar2 + 0x58))(plVar2);
        *(undefined8 *)(param_2 + 0x2a) = uVar10;
        return 0;
      }
      nvAssertFailedNoLog("pBigPageTable","src/kernel/mem_mgr/gpu_vaspace.c",0x871);
    }
    return 0x28;
  }
  nvAssertFailedNoLog("NULL != pParams","src/kernel/mem_mgr/gpu_vaspace.c",0x867);
  return 0x3a;
}


// ===== 0044e900 gvaspaceGetPteInfo_IMPL =====

int gvaspaceGetPteInfo_IMPL(long param_1,long param_2,ulong *param_3,long *param_4)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  int iVar8;
  long *plVar9;
  byte *pbVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  long lVar14;
  byte bVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  undefined4 local_74;
  long local_70;
  ulong local_68 [7];
  
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  if (param_3 == (ulong *)0x0) {
    nvAssertFailedNoLog("NULL != pParams","src/kernel/mem_mgr/gpu_vaspace.c",0x953);
    return 0x3a;
  }
  if (((int)param_3[1] == 0) ||
     (param_2 = gpumgrGetGpuFromSubDeviceInst(*(undefined4 *)(param_2 + 0x7b4),(int)param_3[1] + -1)
     , param_2 != 0)) {
    uVar18 = 0;
    plVar9 = (long *)gvaspaceGetGpuState_IMPL(param_1,param_2);
    lVar2 = plVar9[1];
    lVar3 = *plVar9;
    uVar4 = *(undefined8 *)(lVar3 + 8);
    uVar5 = *(undefined8 *)(param_2 + 0x1b98);
    uVar6 = *(undefined8 *)(param_2 + 0x1b78);
    lVar14 = 0;
LAB_0044e9b5:
    do {
      local_70 = 0;
      local_74 = 0;
      local_68[0] = 0;
      local_68[1] = 0;
      if (lVar14 == 1) {
        uVar17 = *(ulong *)(param_1 + 0xa0);
        pbVar10 = (byte *)mmuFmtFindLevelWithPageShift
                                    (uVar4,(uVar17 >> 0x20 != 0) << 5 |
                                           (uVar17 & 0xaaaaaaaaaaaaaaaa) != 0 |
                                           ((uVar17 & 0xffff0000ffff0000) != 0) << 4 |
                                           ((uVar17 & 0xff00ff00ff00ff00) != 0) << 3 |
                                           ((uVar17 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                                           ((uVar17 & 0xcccccccccccccccc) != 0) * '\x02');
        if (pbVar10 == (byte *)0x0) {
          lVar14 = 2;
          goto LAB_0044e9b5;
        }
LAB_0044ea62:
        iVar8 = mmuWalkGetPageLevelInfo(lVar2,pbVar10,*param_3,&local_70,&local_74);
        if (iVar8 != 0) {
          nvAssertOkFailedNoLog
                    (iVar8,
                     "mmuWalkGetPageLevelInfo(pWalk, pLevelFmt, pParams->gpuAddr, (const MMU_WALK_MEMDESC**)&pMemDesc, &memSize)"
                     ,"src/kernel/mem_mgr/gpu_vaspace.c",0x97a);
          return iVar8;
        }
        if (local_70 != 0) {
          local_68[2] = local_70;
          local_68[3] = (ulong)((int)((~(-1L << (pbVar10[1] + 1 & 0x3f)) &
                                      -1L << (*pbVar10 & 0x3f) & *param_3) >> (*pbVar10 & 0x3f)) *
                               (uint)pbVar10[2]);
          iVar8 = memmgrMemRead_IMPL(uVar6,local_68 + 2,local_68,pbVar10[2],1);
          if (iVar8 != 0) {
            nvAssertOkFailedNoLog
                      (iVar8,
                       "memmgrMemRead(pMemoryManager, &surf, pte.v8, pLevelFmt->entrySize, TRANSFER_FLAGS_DEFER_FLUSH)"
                       ,"src/kernel/mem_mgr/gpu_vaspace.c",0x989);
            return iVar8;
          }
          if (4 < (uint)uVar18) {
            nvAssertFailedNoLog("pteBlockIndex < NV0080_CTRL_DMA_PDE_INFO_PTE_BLOCKS",
                                "src/kernel/mem_mgr/gpu_vaspace.c",0x98d);
            return 0x40;
          }
          param_3[uVar18 * 4 + 2] = uVar17;
          param_3[uVar18 * 4 + 3] = (ulong)pbVar10[2];
          kgmmuExtractPteInfo_IMPL(uVar5,local_68,param_3 + uVar18 * 4 + 2,lVar3,pbVar10);
          if ((param_4 != (long *)0x0) &&
             (lVar7 = *(long *)(lVar3 + 0x20),
             *(char *)(lVar7 + 0x10) !=
             (char)((*(uint *)((long)local_68 + (ulong)*(ushort *)(lVar7 + 0xe)) &
                    *(uint *)(lVar7 + 4)) >> ((byte)*(undefined2 *)(lVar7 + 0xc) & 0x1f)))) {
            if (*(byte *)(lVar7 + 0x24) != 0) {
              lVar16 = 0;
              do {
                if ((*(char *)(*(long *)(lVar7 + 0x28) + lVar16 * 2) != '\0') &&
                   ((*(uint *)((long)local_68 + (ulong)*(ushort *)(lVar7 + 0x22)) &
                    *(uint *)(lVar7 + 0x18)) >> ((byte)*(undefined2 *)(lVar7 + 0x20) & 0x1f) ==
                    (uint)*(byte *)(*(long *)(lVar7 + 0x28) + 1 + lVar16 * 2))) goto LAB_0044ed1a;
                lVar16 = lVar16 + 1;
              } while ((uint)lVar16 < (uint)*(byte *)(lVar7 + 0x24));
            }
            lVar16 = 0;
LAB_0044ed1a:
            puVar11 = (uint *)gmmuFmtPtePhysAddrFld(lVar7,lVar16,0);
            uVar17 = 0;
            if (*puVar11 != 0) {
              puVar12 = puVar11;
              iVar8 = 0;
              do {
                puVar13 = puVar12 + 6;
                puVar1 = puVar12 + 4;
                uVar17 = uVar17 | ((*(ulong *)((long)local_68 + (ulong)puVar12[6]) &
                                   *(ulong *)(puVar12 + 2)) >> ((byte)puVar12[5] & 0x3f)) <<
                                  ((byte)iVar8 & 0x3f);
                puVar12 = puVar13;
                iVar8 = iVar8 + *puVar1;
              } while (puVar13 != puVar11 + (ulong)*puVar11 * 6);
            }
            *param_4 = uVar17 << ((byte)puVar11[0xe] & 0x3f);
          }
          uVar18 = (ulong)((uint)uVar18 + 1);
        }
      }
      else {
        uVar17 = (&pageSizes)[lVar14];
        if (uVar17 < 0x100000000) {
          if ((uVar17 & 0xffff0000ffff0000) == 0) {
            bVar15 = 0xc;
            uVar17 = 0x1000;
          }
          else {
            bVar15 = ((uVar17 & 0xff00ff00ff00ff00) != 0) << 3 | (uVar17 & 0xaaaaaaaaaaaaaaaa) != 0
                     | ((uVar17 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 | 0x10;
          }
        }
        else {
          uVar17 = 0x4000000000;
          bVar15 = 0x26;
        }
        pbVar10 = (byte *)mmuFmtFindLevelWithPageShift(uVar4,bVar15);
        if (pbVar10 != (byte *)0x0) goto LAB_0044ea62;
      }
      lVar14 = lVar14 + 1;
    } while (lVar14 != 5);
    iVar8 = 0;
    if (((int)uVar18 == 0) && (*(char *)((long)param_3 + 0xc) == '\0')) {
      nvCheckFailedNoLog(4,"(pteBlockIndex > 0) || pParams->skipVASpaceInit",
                         "src/kernel/mem_mgr/gpu_vaspace.c",0x9ad);
      iVar8 = 0x3f;
    }
  }
  else {
    nvAssertFailedNoLog("NULL != pGpu","src/kernel/mem_mgr/gpu_vaspace.c",0x95a);
    iVar8 = 0x1f;
  }
  return iVar8;
}


// ===== 0044ee90 gvaspaceSetPteInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

uint gvaspaceSetPteInfo_IMPL(long *param_1,long param_2,ulong *param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  int *piVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  undefined8 *puVar14;
  byte *pbVar15;
  uint *puVar16;
  byte bVar17;
  byte bVar18;
  uint *puVar19;
  uint *puVar20;
  uint uVar21;
  ulong uVar22;
  uint uVar23;
  long lVar24;
  long lVar25;
  ulong uVar26;
  int iVar27;
  ulong *puVar28;
  bool bVar29;
  byte local_f4;
  undefined4 local_98;
  undefined4 local_94;
  long local_90;
  ulong local_88 [2];
  ulong local_78;
  undefined8 local_70;
  long local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar13 = 0;
  if (param_1 != (long *)0x0) {
    lVar13 = param_1[0x11];
  }
  lVar3 = *(long *)(param_2 + 0x1b78);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_3 == (ulong *)0x0) {
    uVar9 = 0x3a;
    nvAssertFailedNoLog("NULL != pParams","src/kernel/mem_mgr/gpu_vaspace.c",0x9e0);
  }
  else {
    uVar21 = *(uint *)(lVar13 + 0x48);
    uVar9 = 0;
    if (uVar21 != 0) {
      iVar27 = 0;
      do {
        for (; (uVar21 & 1) == 0; uVar21 = uVar21 >> 1) {
          iVar27 = iVar27 + 1;
        }
        lVar13 = gpumgrGetGpu(iVar27);
        if (lVar13 == 0) {
          nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x9e3);
        }
        else {
          puVar14 = (undefined8 *)gvaspaceGetGpuState_IMPL(param_1,lVar13);
          if (((int)param_3[1] == 0) || (*(int *)(lVar13 + 0x7b8) == (int)param_3[1] + -1)) {
            uVar4 = puVar14[1];
            uVar9 = 0;
            piVar5 = (int *)*puVar14;
            uVar6 = *(undefined8 *)(piVar5 + 2);
            puVar28 = param_3 + 2;
            do {
              uVar22 = *puVar28;
              local_88[0] = 0;
              local_90 = 0;
              local_98 = 0;
              local_88[1] = 0;
              if (uVar22 != 0) {
                if (uVar22 == param_1[0x14]) {
                  bVar18 = (uVar22 >> 0x20 != 0) << 5;
LAB_0044f40f:
                  bVar18 = ((uVar22 & 0xffff0000ffff0000) != 0) << 4 | bVar18;
LAB_0044f427:
                  bVar17 = ((uVar22 & 0xff00ff00ff00ff00) != 0) << 3;
                }
                else {
                  if (uVar22 == 0x200000) {
                    bVar18 = 0;
                    goto LAB_0044f40f;
                  }
                  if (uVar22 != 0x20000000) {
                    if (uVar22 != 0x4000000000) {
                      if (uVar22 != 0x1000) goto LAB_0044f39a;
                      bVar18 = 0;
                      bVar17 = 8;
                      goto LAB_0044f070;
                    }
                    bVar18 = 0x20;
                    goto LAB_0044f427;
                  }
                  bVar18 = 0x10;
                  bVar17 = 8;
                }
LAB_0044f070:
                pbVar15 = (byte *)mmuFmtFindLevelWithPageShift
                                            (uVar6,((uVar22 & 0xcccccccccccccccc) != 0) * '\x02' |
                                                   ((uVar22 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                                                   (uVar22 & 0xaaaaaaaaaaaaaaaa) != 0 | bVar18 |
                                                   bVar17);
                if (pbVar15 == (byte *)0x0) {
                  nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0xa1d);
                  return 0x40;
                }
                uVar9 = mmuWalkGetPageLevelInfo(uVar4,pbVar15,*param_3,&local_90,&local_98);
                if (uVar9 != 0) {
                  nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xa21);
                  return uVar9;
                }
                if (local_90 == 0) {
                  nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0xa27);
                  return 0x1e;
                }
                local_58 = local_90;
                uVar22 = (~(-1L << (pbVar15[1] + 1 & 0x3f)) & -1L << (*pbVar15 & 0x3f) & *param_3)
                         >> (*pbVar15 & 0x3f);
                local_50 = (ulong)((uint)pbVar15[2] * (int)uVar22);
                uVar9 = memmgrMemRead_IMPL(lVar3,&local_58,local_88,pbVar15[2],0);
                if (uVar9 != 0) {
                  nvAssertOkFailedNoLog
                            (uVar9,
                             "memmgrMemRead(pMemoryManager, &surf, pte.v8, pLevelFmt->entrySize, TRANSFER_FLAGS_NONE)"
                             ,"src/kernel/mem_mgr/gpu_vaspace.c",0xa32);
                  return uVar9;
                }
                uVar23 = (uint)puVar28[3];
                iVar11 = *piVar5;
                lVar25 = *(long *)(piVar5 + 8);
                local_78 = local_88[0];
                uVar9 = 0;
                local_70 = local_88[1];
                if ((uVar23 & 1) == 0) {
                  uVar9 = (uint)(*(char *)(lVar25 + 0x10) !=
                                (char)((*(uint *)((long)&local_78 + (ulong)*(ushort *)(lVar25 + 0xe)
                                                 ) & *(uint *)(lVar25 + 4)) >>
                                      ((byte)*(undefined2 *)(lVar25 + 0xc) & 0x1f)));
                }
                if (iVar11 == 3) {
                  local_94 = 0;
                  iVar11 = (**(code **)(*(long *)(lVar13 + 0x1b98) + 0x288))
                                     (*(long *)(lVar13 + 0x1b98),
                                      (*(uint *)((long)&local_78 +
                                                (ulong)*(ushort *)(lVar25 + 0x1aa)) &
                                      *(uint *)(lVar25 + 0x1a0)) >>
                                      ((byte)*(undefined2 *)(lVar25 + 0x1a8) & 0x1f),
                                      (byte)((*(uint *)((long)&local_78 +
                                                       (ulong)*(ushort *)(lVar25 + 0xe)) &
                                             *(uint *)(lVar25 + 4)) >>
                                            ((byte)*(undefined2 *)(lVar25 + 0xc) & 0x1f)) ^
                                      *(byte *)(lVar25 + 0x10),&local_94);
                  if (iVar11 == 0) {
                    uVar12 = (uint)puVar28[3];
                    iVar11 = *piVar5;
                    bVar18 = (byte)local_94 & 0x80;
                    goto LAB_0044f204;
                  }
                  uVar9 = 0x1f;
                  nvAssertFailedNoLog("(kgmmuTranslatePtePcfFromHw_HAL(pKernelGmmu, ptePcfHw, nvFieldGetBool(&pFmt->pPte->fldValid, curPte.v8), &ptePcfSw) == NV_OK)"
                                      ,"src/kernel/mem_mgr/gpu_vaspace.c",0x9c2);
                  uVar12 = (uint)puVar28[3];
                  iVar11 = *piVar5;
                }
                else {
                  bVar18 = (byte)((*(uint *)((long)&local_78 + (ulong)*(ushort *)(lVar25 + 0x116)) &
                                  *(uint *)(lVar25 + 0x10c)) >>
                                 ((byte)*(undefined2 *)(lVar25 + 0x114) & 0x1f)) ^
                           *(byte *)(lVar25 + 0x118);
                  uVar12 = uVar23;
LAB_0044f204:
                  uVar9 = ~(uVar23 >> 0xf) & (uint)(bVar18 == 0) | uVar9;
                }
                uVar23 = uVar12 >> 3 & 0xf;
                bVar29 = (uVar12 & 0x1800) == 0;
                cVar8 = (char)(uVar12 & 1);
                if (iVar11 == 3) {
                  local_78 = local_78 & 0xffffffff00000000;
                  uVar10 = uVar21 & 1;
                  if (cVar8 != '\0') {
                    lVar25 = *(long *)(piVar5 + 8);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0xe)) =
                         (uint)(*(byte *)(lVar25 + 0x10) ^ 1) <<
                         ((byte)*(undefined2 *)(lVar25 + 0xc) & 0x1f) |
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0xe)) &
                         *(uint *)(lVar25 + 8);
                    lVar25 = *(long *)(piVar5 + 8);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x22)) =
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x22)) &
                         *(uint *)(lVar25 + 0x1c) |
                         uVar23 << ((byte)*(undefined2 *)(lVar25 + 0x20) & 0x1f);
                    lVar25 = *(long *)(piVar5 + 8);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x186)) =
                         *(int *)((long)puVar28 + 0x14) <<
                         ((byte)*(undefined2 *)(lVar25 + 0x184) & 0x1f) |
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x186)) &
                         *(uint *)(lVar25 + 0x180);
                    uVar10 = (uint)bVar29 << 5;
                    if ((uVar12 & 0x8000) != 0) {
                      uVar10 = uVar10 | 0xc0;
                    }
                    uVar10 = uVar10 | 0x110;
                  }
                  pcVar7 = *(code **)(*(long *)(lVar13 + 0x1b98) + 0x280);
                  iVar11 = (*pcVar7)(*(long *)(lVar13 + 0x1b98),uVar10,&local_78,pcVar7);
                  if (iVar11 != 0) {
                    nvAssertFailedNoLog("(kgmmuTranslatePtePcfFromSw_HAL(GPU_GET_KERNEL_GMMU(pGpu), ptePcfSw, &ptePcfHw) == NV_OK)"
                                        ,"src/kernel/mem_mgr/gpu_vaspace.c",0xa6f);
                    return 0x1f;
                  }
                  lVar25 = *(long *)(piVar5 + 8);
                  *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x1aa)) =
                       (int)local_78 << ((byte)*(undefined2 *)(lVar25 + 0x1a8) & 0x1f) |
                       *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x1aa)) &
                       *(uint *)(lVar25 + 0x1a4);
                }
                else {
                  lVar25 = *(long *)(piVar5 + 8);
                  *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0xe)) =
                       ((uint)*(byte *)(lVar25 + 0x10) ^ uVar12 & 1) <<
                       ((byte)*(undefined2 *)(lVar25 + 0xc) & 0x1f) |
                       *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0xe)) &
                       *(uint *)(lVar25 + 8);
                  if (cVar8 != '\0') {
                    lVar25 = *(long *)(piVar5 + 8);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x22)) =
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x22)) &
                         *(uint *)(lVar25 + 0x1c) |
                         uVar23 << ((byte)*(undefined2 *)(lVar25 + 0x20) & 0x1f);
                    lVar25 = *(long *)(piVar5 + 8);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x156)) =
                         (uint)((uVar12 & 6) == 2 ^ *(byte *)(lVar25 + 0x158)) <<
                         ((byte)*(undefined2 *)(lVar25 + 0x154) & 0x1f) |
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x156)) &
                         *(uint *)(lVar25 + 0x150);
                    lVar25 = *(long *)(piVar5 + 8);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x116)) =
                         (uint)(byte)((byte)((uVar12 & 0x8000) >> 0xf) ^ *(byte *)(lVar25 + 0x118))
                         << ((byte)*(undefined2 *)(lVar25 + 0x114) & 0x1f) |
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x116)) &
                         *(uint *)(lVar25 + 0x110);
                    lVar25 = *(long *)(piVar5 + 8);
                    uVar2 = *(undefined4 *)((long)puVar28 + 0x14);
                    *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x106)) =
                         (uint)(bVar29 ^ *(byte *)(lVar25 + 0x108)) <<
                         ((byte)*(undefined2 *)(lVar25 + 0x104) & 0x1f) |
                         *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x106)) &
                         *(uint *)(lVar25 + 0x100);
                    cVar8 = (**(code **)(lVar3 + 0x2a8))(lVar3,5,uVar2);
                    lVar25 = *(long *)(piVar5 + 8);
                    if (cVar8 == '\0') {
                      *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x186)) =
                           *(int *)((long)puVar28 + 0x14) <<
                           ((byte)*(undefined2 *)(lVar25 + 0x184) & 0x1f) |
                           *(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x186)) &
                           *(uint *)(lVar25 + 0x180);
                    }
                    else {
                      if (*(byte *)(lVar25 + 0x24) != 0) {
                        lVar24 = 0;
                        do {
                          if ((*(char *)(*(long *)(lVar25 + 0x28) + lVar24 * 2) != '\0') &&
                             ((*(uint *)((long)local_88 + (ulong)*(ushort *)(lVar25 + 0x22)) &
                              *(uint *)(lVar25 + 0x18)) >>
                              ((byte)*(undefined2 *)(lVar25 + 0x20) & 0x1f) ==
                              (uint)*(byte *)(*(long *)(lVar25 + 0x28) + 1 + lVar24 * 2)))
                          goto LAB_0044f6fa;
                          lVar24 = lVar24 + 1;
                        } while ((uint)lVar24 < (uint)*(byte *)(lVar25 + 0x24));
                      }
                      lVar24 = 0;
LAB_0044f6fa:
                      puVar16 = (uint *)gmmuFmtPtePhysAddrFld(lVar25,lVar24,0);
                      uVar26 = 0;
                      if (*puVar16 != 0) {
                        puVar19 = puVar16;
                        iVar11 = 0;
                        do {
                          puVar20 = puVar19 + 6;
                          puVar1 = puVar19 + 4;
                          uVar26 = uVar26 | ((*(ulong *)((long)local_88 + (ulong)puVar19[6]) &
                                             *(ulong *)(puVar19 + 2)) >> ((byte)puVar19[5] & 0x3f))
                                            << ((byte)iVar11 & 0x3f);
                          puVar19 = puVar20;
                          iVar11 = iVar11 + *puVar1;
                        } while (puVar20 != puVar16 + (ulong)*puVar16 * 6);
                      }
                      uVar23 = puVar16[0xe];
                      lVar25 = (uVar22 & 0xffffffff) * *puVar28;
                      uVar12 = memmgrFillComprInfo_IMPL
                                         (lVar13,lVar3,*puVar28,1,
                                          *(undefined4 *)((long)puVar28 + 0x14),lVar25,
                                          (int)puVar28[2],&local_78);
                      if (uVar12 != 0) {
                        nvCheckOkFailedNoLog
                                  (4,uVar12,
                                   "memmgrFillComprInfo(pGpu, pMemoryManager, pPteBlock->pageSize, 1, pPteBlock->kind, surfOffset, pPteBlock->comptagLine, &comprInfo)"
                                   ,"src/kernel/mem_mgr/gpu_vaspace.c",0xa90,lVar25);
                        return uVar12;
                      }
                      local_f4 = (byte)uVar23;
                      kgmmuFieldSetKindCompTags_IMPL
                                (*(undefined8 *)(lVar13 + 0x1b98),piVar5,pbVar15,&local_78,
                                 uVar26 << (local_f4 & 0x3f),lVar25,uVar22 & 0xffffffff,local_88);
                    }
                  }
                }
                uVar23 = memmgrMemWrite_IMPL(lVar3,&local_58,local_88,pbVar15[2],0);
                if (uVar23 != 0) {
                  nvAssertOkFailedNoLog
                            (uVar23,
                             "memmgrMemWrite(pMemoryManager, &surf, pte.v8, pLevelFmt->entrySize, TRANSFER_FLAGS_NONE)"
                             ,"src/kernel/mem_mgr/gpu_vaspace.c",0xa9c);
                  return uVar23;
                }
              }
LAB_0044f39a:
              puVar28 = puVar28 + 4;
            } while (puVar28 != param_3 + 0x16);
            (**(code **)(*param_1 + 0x1b8))(param_1,lVar13,(char)uVar9 != '\0');
          }
        }
        if (uVar21 >> 1 == 0) {
          return uVar21 >> 1;
        }
        uVar21 = uVar21 >> 1;
        iVar27 = iVar27 + 1;
      } while( true );
    }
  }
  return uVar9;
}


// ===== 0044f8f0 gvaspaceWalkUserCtxAcquire_IMPL =====

ulong gvaspaceWalkUserCtxAcquire_IMPL
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  
  lVar1 = gvaspaceGetGpuState_IMPL();
  if ((lVar1 != 0) && (*(long *)(lVar1 + 8) != 0)) {
    lVar2 = mmuWalkGetUserCtx();
    if (lVar2 == 0) {
      *param_4 = param_1;
      param_4[1] = param_2;
      param_4[2] = lVar1;
      param_4[3] = param_3;
      uVar3 = mmuWalkSetUserCtx(*(undefined8 *)(lVar1 + 8),param_4);
      if ((int)uVar3 == 0) {
        return uVar3;
      }
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,"mmuWalkSetUserCtx(pUserCtx->pGpuState->pWalk, pUserCtx)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0xdfb);
      return uVar3 & 0xffffffff;
    }
    nvAssertFailedNoLog("NULL == mmuWalkGetUserCtx(pGpuState->pWalk)",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0xdf4);
  }
  return 0x40;
}


// ===== 0044f9e0 gvaspaceWalkUserCtxRelease_IMPL =====

void gvaspaceWalkUserCtxRelease_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_2 + 0x10) == 0) {
    nvAssertFailedNoLog("pUserCtx->pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0xe07);
    return;
  }
  if (*(long *)(*(long *)(param_2 + 0x10) + 8) != 0) {
    lVar2 = mmuWalkGetUserCtx();
    if (lVar2 != param_2) {
      nvAssertFailedNoLog("pUserCtx == mmuWalkGetUserCtx(pUserCtx->pGpuState->pWalk)",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0xe09);
    }
    iVar1 = mmuWalkSetUserCtx(*(undefined8 *)(*(long *)(param_2 + 0x10) + 8),0);
    if (iVar1 == 0) {
      return;
    }
    nvAssertOkFailedNoLog
              (iVar1,"mmuWalkSetUserCtx(pUserCtx->pGpuState->pWalk, NULL)",
               "src/kernel/mem_mgr/gpu_vaspace.c",0xe0a);
    return;
  }
  nvAssertFailedNoLog("pUserCtx->pGpuState->pWalk","src/kernel/mem_mgr/gpu_vaspace.c",0xe08);
  return;
}


// ===== 0044faa0 _gvaspaceReleaseUnreservedPTEs =====

int _gvaspaceReleaseUnreservedPTEs
              (long param_1,undefined8 param_2,ulong param_3,ulong param_4,undefined8 param_5)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  ulong *puVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar3 = gvaspaceGetGpuState_IMPL();
  if (lVar3 == 0) {
    iVar2 = 0xffff;
    nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x1317);
  }
  else {
    puVar4 = (ulong *)listHead_IMPL(lVar3 + 0x38);
    iVar2 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_68);
    if (iVar2 == 0) {
      while (param_3 <= param_4) {
        if (puVar4 == (ulong *)0x0) goto LAB_0044fbb6;
        if (param_3 < *puVar4) {
          uVar5 = *puVar4 - 1;
          if (param_4 < uVar5) {
            uVar5 = param_4;
          }
          if (uVar5 != 0) {
            bVar1 = *(byte *)(param_1 + 0xb8);
            while( true ) {
              if (((bVar1 & 0x80) == 0) &&
                 (iVar2 = mmuWalkUnmap(*(undefined8 *)(local_58 + 8),param_3,uVar5), iVar2 != 0)) {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1331);
              }
              iVar2 = mmuWalkReleaseEntries(*(undefined8 *)(local_58 + 8),param_5,param_3,uVar5);
              if (iVar2 != 0) {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1339);
              }
              param_3 = uVar5 + 1;
              if (puVar4 != (ulong *)0x0) break;
              if (param_4 < param_3) goto LAB_0044fc33;
LAB_0044fbb6:
              if (param_4 == 0) {
                if (param_3 == 0) {
                  do {
                    /* WARNING: Do nothing block with infinite loop */
                  } while( true );
                }
                goto LAB_0044fc33;
              }
              puVar4 = (ulong *)0x0;
              bVar1 = *(byte *)(param_1 + 0xb8);
              uVar5 = param_4;
            }
          }
        }
        if (param_3 < puVar4[1] + 1) {
          param_3 = puVar4[1] + 1;
        }
        puVar4 = (ulong *)listNext_IMPL(lVar3 + 0x38,puVar4);
      }
LAB_0044fc33:
      gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0x131a);
    }
  }
  return iVar2;
}


// ===== 0044fcc3 _gvaspaceInternalFree.isra.0.cold =====

void _gvaspaceInternalFree_isra_0_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0044fcd0 _gvaspaceInternalFree.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 _gvaspaceInternalFree_isra_0(long *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  int local_5c;
  long local_40 [2];
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar7 = param_1[0x11];
  uVar3 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(lVar7 + 0x48));
  lVar4 = gpumgrGetGpu(uVar3);
  if (lVar4 == 0) {
    return 0x40;
  }
  if (1 < *(uint *)((long)param_2 + 0x1c)) {
    *(uint *)((long)param_2 + 0x1c) = *(uint *)((long)param_2 + 0x1c) - 1;
    return 0;
  }
  puVar1 = (undefined8 *)param_2[0x10];
  if (((*(byte *)(param_1 + 0x17) & 1) != 0) && (uVar8 = *(uint *)(lVar7 + 0x48), uVar8 != 0)) {
    iVar9 = 0;
    while( true ) {
      for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
        iVar9 = iVar9 + 1;
      }
      lVar4 = gpumgrGetGpu(iVar9);
      if (lVar4 == 0) {
        nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x619);
      }
      else {
        pcVar2 = *(code **)(*(long *)(&DAT_00001b90 + lVar4) + 0x500);
        (*pcVar2)(lVar4,*(long *)(&DAT_00001b90 + lVar4),3,pcVar2);
      }
      uVar8 = uVar8 >> 1;
      if (uVar8 == 0) break;
      iVar9 = iVar9 + 1;
    }
  }
  while (btreeEnumStart(0,local_40,*puVar1), local_40[0] != 0) {
    uVar8 = *(uint *)(local_40[0] + 0x38);
    if (uVar8 != 0) {
      iVar9 = 0;
      while( true ) {
        for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
          iVar9 = iVar9 + 1;
        }
        lVar4 = gpumgrGetGpu(iVar9);
        if (lVar4 == 0) {
          nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x628);
        }
        else {
          (**(code **)(*param_1 + 0x158))
                    (param_1,lVar4,*(undefined8 *)(local_40[0] + 8),
                     *(undefined8 *)(local_40[0] + 0x10),*(code **)(*param_1 + 0x158));
        }
        uVar8 = uVar8 >> 1;
        if (uVar8 == 0) break;
        iVar9 = iVar9 + 1;
      }
    }
  }
  uVar8 = *(uint *)(lVar7 + 0x48);
  if (uVar8 != 0) {
    local_5c = 0;
joined_r0x0044fe14:
    for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
      local_5c = local_5c + 1;
    }
    lVar4 = gpumgrGetGpu(local_5c);
    if (lVar4 == 0) {
      nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x632);
    }
    else {
      plVar5 = (long *)gvaspaceGetGpuState_IMPL(param_1,lVar4);
      if (plVar5 == (long *)0x0) {
        nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x637);
      }
      else {
        uVar10 = puVar1[1];
        if (uVar10 != 0) {
          lVar11 = 0;
          do {
            if ((uVar10 & 1) != 0) {
              uVar6 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*plVar5 + 8),lVar11);
              iVar9 = _gvaspaceReleaseUnreservedPTEs(param_1,lVar4,*param_2,param_2[1],uVar6);
              if (iVar9 != 0) {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x646);
              }
              if (uVar10 >> 1 == 0) break;
            }
            uVar10 = uVar10 >> 1;
            lVar11 = lVar11 + 1;
          } while( true );
        }
      }
    }
    uVar8 = uVar8 >> 1;
    if (uVar8 != 0) {
      local_5c = local_5c + 1;
      goto joined_r0x0044fe14;
    }
    if (((*(byte *)((long)puVar1 + 0x11) & 4) == 0) && (uVar8 = *(uint *)(lVar7 + 0x48), uVar8 != 0)
       ) {
      iVar9 = 0;
      while( true ) {
        for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
          iVar9 = iVar9 + 1;
        }
        lVar7 = gpumgrGetGpu(iVar9);
        if (lVar7 == 0) {
          nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x650);
        }
        else {
          (**(code **)(*(long *)(&DAT_00001b90 + lVar7) + 0x500))
                    (lVar7,*(long *)(&DAT_00001b90 + lVar7),3);
          (**(code **)(*param_1 + 0x1b8))(param_1,lVar7,1);
        }
        uVar8 = uVar8 >> 1;
        if (uVar8 == 0) break;
        iVar9 = iVar9 + 1;
      }
    }
  }
  (**(code **)(param_1[0x13] + 0x10))(param_1[0x13],*param_2);
  return 0;
}


// ===== 004500b0 gvaspaceFree_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gvaspaceFree_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = (**(code **)(*(long *)(param_1 + 0x98) + 0x40))(*(long *)(param_1 + 0x98),param_2,0);
  if (lVar1 != 0) {
    uVar2 = _gvaspaceInternalFree_isra_0(param_1,lVar1);
    return uVar2;
  }
  nvAssertFailedNoLog("NULL != pMemBlock","src/kernel/mem_mgr/gpu_vaspace.c",0x667);
  return 0x1f;
}


// ===== 00450120 gvaspacePinRootPageDir_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gvaspacePinRootPageDir_IMPL(long *param_1,undefined8 param_2)

{
  byte *pbVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined8 local_58;
  undefined8 local_50;
  long *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_58 = 0;
  local_50 = 0;
  local_48 = (long *)0x0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (param_1[0x22] != 0) {
    iVar2 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_58);
    if (iVar2 == 0) {
      pbVar1 = *(byte **)(*local_48 + 8);
      lVar5 = 1L << (*pbVar1 & 0x3f);
      uVar3 = (**(code **)(*param_1 + 0x1e8))(param_1);
      uVar6 = -lVar5;
      lVar4 = (**(code **)(*param_1 + 0x1f0))(param_1);
      iVar2 = mmuWalkReserveEntries(local_48[1],pbVar1,uVar3 & uVar6,(lVar5 + lVar4 & uVar6) - 1,1);
      if (iVar2 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x796);
      }
      gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_58);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0x78b);
    }
    return iVar2;
  }
  return 0x56;
}


// ===== 00450280 gvaspaceUnpinRootPageDir_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gvaspaceUnpinRootPageDir_IMPL(long *param_1,undefined8 param_2)

{
  byte *pbVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 local_48;
  undefined8 local_40;
  long *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_48 = 0;
  local_40 = 0;
  local_38 = (long *)0x0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  if (param_1[0x22] != 0) {
    iVar2 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_48);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x7ae,"gvaspaceUnpinRootPageDir_IMPL",3,
                   "NVRM: Failed to acquire walk user context\n");
      return;
    }
    pbVar1 = *(byte **)(*local_38 + 8);
    lVar6 = 1L << (*pbVar1 & 0x3f);
    uVar3 = (**(code **)(*param_1 + 0x1e8))(param_1);
    uVar5 = -lVar6;
    lVar4 = (**(code **)(*param_1 + 0x1f0))(param_1);
    iVar2 = mmuWalkReleaseEntries(local_38[1],pbVar1,uVar3 & uVar5,(lVar6 + lVar4 & uVar5) - 1);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog(iVar2,"status","src/kernel/mem_mgr/gpu_vaspace.c",0x7bc);
    }
    gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_48);
  }
  return;
}


// ===== 004503d0 gvaspaceMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gvaspaceMap_IMPL(long param_1,undefined8 param_2,ulong param_3,ulong param_4,undefined8 *param_5
                    ,uint param_6)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  uVar2 = (1L << (*(byte *)*param_5 & 0x3f)) - 1;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if ((uVar2 & param_3) != 0) {
    nvAssertFailedNoLog("0 == (vaLo & (pageSize - 1))","src/kernel/mem_mgr/gpu_vaspace.c",0x7d5);
    return 0x1f;
  }
  if ((param_4 + 1 & uVar2) != 0) {
    nvAssertFailedNoLog("0 == ((vaHi + 1) & (pageSize - 1))","src/kernel/mem_mgr/gpu_vaspace.c",
                        0x7d6);
    return 0x1f;
  }
  if ((param_6 & 1) == 0) {
    lVar3 = (**(code **)(*(long *)(param_1 + 0x98) + 0x40))(*(long *)(param_1 + 0x98),param_3,0);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("NULL != pMemBlock","src/kernel/mem_mgr/gpu_vaspace.c",0x7e2);
      return 0x1f;
    }
    if (*(ulong *)(lVar3 + 8) < param_4) {
      nvAssertFailedNoLog("vaHi <= pMemBlock->end","src/kernel/mem_mgr/gpu_vaspace.c",0x7e6);
      return 0x1f;
    }
    local_78 = *(undefined8 *)(lVar3 + 0x80);
    iVar1 = _gvaspaceMappingInsert(param_1,param_2,local_78,param_3,param_4,param_6);
    if (iVar1 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar1,"_gvaspaceMappingInsert(pGVAS, pGpu, pVASBlock, vaLo, vaHi, flags)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0x7e9);
      return iVar1;
    }
  }
  else {
    local_78 = 0;
  }
  iVar1 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,local_78,&local_68);
  if (iVar1 == 0) {
    iVar1 = mmuWalkMap(*(undefined8 *)(local_58 + 8),param_3,param_4,param_5);
    gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
    if (iVar1 == 0) {
      return 0;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x7f4);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, pVASBlock, &userCtx)",
               "src/kernel/mem_mgr/gpu_vaspace.c",0x7ee);
  }
  if ((param_6 & 1) == 0) {
    _gvaspaceMappingRemove(param_1,param_2,local_78,param_3,param_4);
  }
  return iVar1;
}


// ===== 004506a0 gvaspaceUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gvaspaceUnmap_IMPL(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  lVar3 = (**(code **)(*(long *)(param_1 + 0x98) + 0x40))(*(long *)(param_1 + 0x98),param_3,0);
  if (lVar3 != 0) {
    lVar1 = *(long *)(lVar3 + 0x80);
    iVar2 = _gvaspaceMappingRemove(param_1,param_2,lVar1,param_3,param_4);
    if (iVar2 == 0) {
      iVar2 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,lVar1,&local_68);
      if (iVar2 == 0) {
        if ((((*(byte *)(lVar1 + 0x10) & 0x10) == 0) && ((*(uint *)(param_1 + 0xb8) & 0x80) == 0))
           && ((*(uint *)(lVar3 + 0x1c) < 2 || ((*(uint *)(param_1 + 0xb8) & 0x1000000) == 0)))) {
          iVar2 = mmuWalkUnmap(*(undefined8 *)(local_58 + 8),param_3,param_4);
          if (iVar2 != 0) {
            nvAssertOkFailedNoLog
                      (iVar2,"mmuWalkUnmap(userCtx.pGpuState->pWalk, vaLo, vaHi)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x824);
          }
        }
        else {
          iVar2 = mmuWalkSparsify(*(undefined8 *)(local_58 + 8),param_3,param_4,0);
          if (iVar2 != 0) {
            nvAssertOkFailedNoLog
                      (iVar2,"mmuWalkSparsify(userCtx.pGpuState->pWalk, vaLo, vaHi, NV_FALSE)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x81f);
          }
        }
        gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
      }
      else {
        nvAssertFailedNoLog("gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, pVASBlock, &userCtx) == NV_OK",
                            "src/kernel/mem_mgr/gpu_vaspace.c",0x818);
      }
    }
    else {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x816);
    }
    return;
  }
  nvAssertFailedNoLog("NULL != pMemBlock","src/kernel/mem_mgr/gpu_vaspace.c",0x811);
  return;
}


// ===== 0045088f gvaspaceGetPageTableInfo_IMPL.cold =====

void gvaspaceGetPageTableInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004508a0 gvaspaceGetPageTableInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gvaspaceGetPageTableInfo_IMPL(long param_1,ulong *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long *plVar9;
  ulong *puVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 uVar15;
  ulong uVar16;
  byte bVar17;
  ulong uVar18;
  int iVar19;
  ulong uVar20;
  ulong uVar21;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [4];
  long local_70;
  long local_68 [2];
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar1 = *(long *)(param_1 + 0x88);
  uVar5 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(lVar1 + 0x48));
  lVar8 = gpumgrGetGpu(uVar5);
  local_70 = 0;
  local_7c = 0;
  if (param_2 == (ulong *)0x0) {
    iVar6 = 0x3a;
    nvAssertFailedNoLog("NULL != pParams","src/kernel/mem_mgr/gpu_vaspace.c",0x8ad);
  }
  else if ((*(int *)((long)param_2 + 0x1c) == 0) ||
          (lVar8 = gpumgrGetGpuFromSubDeviceInst
                             (*(undefined4 *)(lVar8 + 0x7b4),*(int *)((long)param_2 + 0x1c) + -1),
          lVar8 != 0)) {
    plVar9 = (long *)gvaspaceGetGpuState_IMPL(param_1,lVar8);
    uVar13 = *param_2;
    lVar2 = plVar9[1];
    uVar3 = *(undefined8 *)(*plVar9 + 8);
    puVar10 = (ulong *)(**(code **)(*(long *)(param_1 + 0x98) + 0x40))
                                 (*(long *)(param_1 + 0x98),uVar13,0);
    if ((puVar10 != (ulong *)0x0) &&
       ((uVar21 = puVar10[0x10], (*(byte *)(uVar21 + 0x10) & 8) != 0 && (*(long *)(uVar21 + 8) != 0)
        ))) {
      local_68[0] = 0;
      local_68[1] = 0;
      local_58 = (long *)0x0;
      lVar11 = *(long *)(param_1 + 0xb0);
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      uVar20 = *puVar10;
      uVar18 = puVar10[1];
      iVar6 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar8,uVar21,local_68);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, pVASBlock, &userCtx)",
                   "src/kernel/mem_mgr/gpu_vaspace.c",0x1169);
LAB_00450efb:
        nvAssertFailedNoLog("(NV_OK == rmStatus)","src/kernel/mem_mgr/gpu_vaspace.c",0x8c4);
        return iVar6;
      }
      uVar21 = *(ulong *)(uVar21 + 8);
      if (uVar21 != 0) {
        uVar14 = -lVar11;
        uVar16 = uVar13 & uVar14;
        uVar13 = (uVar13 + lVar11 & uVar14) - 1;
        if (uVar20 <= uVar16) {
          uVar20 = uVar16;
        }
        if (uVar13 <= uVar18) {
          uVar18 = uVar13;
        }
        lVar8 = 0;
        do {
          if ((uVar21 & 1) != 0) {
            uVar15 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*local_58 + 8),lVar8);
            iVar6 = mmuWalkReserveEntries(local_58[1],uVar15,uVar20,uVar18,1);
            if (iVar6 != 0) {
              gvaspaceWalkUserCtxRelease_IMPL(param_1,local_68);
              goto LAB_00450efb;
            }
            if (uVar21 >> 1 == 0) break;
          }
          uVar21 = uVar21 >> 1;
          lVar8 = lVar8 + 1;
        } while( true );
      }
      gvaspaceWalkUserCtxRelease_IMPL(param_1,local_68);
    }
    uVar7 = 0;
    lVar8 = 0;
    do {
      local_68[0] = 0;
      local_78 = 0;
      if (lVar8 == 1) {
        uVar13 = *(ulong *)(param_1 + 0xa0);
        bVar17 = ((uVar13 & 0xffff0000ffff0000) != 0) << 4 | (uVar13 >> 0x20 != 0) << 5;
LAB_004509b6:
        bVar17 = ((uVar13 & 0xff00ff00ff00ff00) != 0) << 3 |
                 (uVar13 & 0xaaaaaaaaaaaaaaaa) != 0 | bVar17 |
                 ((uVar13 & 0xcccccccccccccccc) != 0) * '\x02' |
                 ((uVar13 & 0xf0f0f0f0f0f0f0f0) != 0) << 2;
      }
      else {
        uVar13 = (&pageSizes)[lVar8];
        if (uVar13 >> 0x20 == 0) {
          if ((uVar13 & 0xffff0000ffff0000) != 0) {
            bVar17 = 0x10;
            goto LAB_004509b6;
          }
          bVar17 = 0xc;
          uVar13 = 0x1000;
        }
        else {
          uVar13 = 0;
          bVar17 = 0x26;
        }
      }
      lVar11 = mmuFmtFindLevelWithPageShift(uVar3,bVar17);
      if (lVar11 != 0) {
        lVar12 = mmuFmtFindLevelParent(uVar3,lVar11,local_74);
        if (lVar12 == 0) {
          nvAssertFailedNoLog("NULL != pParentFmt","src/kernel/mem_mgr/gpu_vaspace.c",0x8d9);
          return 0x1f;
        }
        iVar6 = mmuWalkGetPageLevelInfo(lVar2,lVar11,*param_2,local_68,&local_78);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,
                     "mmuWalkGetPageLevelInfo(pWalk, pLevelFmt, pParams->gpuAddr, (const MMU_WALK_MEMDESC**)&pMemDesc, &memSize)"
                     ,"src/kernel/mem_mgr/gpu_vaspace.c",0x8db);
          return iVar6;
        }
        if (local_68[0] != 0) {
          if (uVar7 == 0) {
            param_2[1] = -1L << (*(char *)(lVar11 + 1) + 1U & 0x3f) & *param_2;
            *(uint *)(param_2 + 2) = (uint)*(byte *)(lVar12 + 2);
          }
          else if (4 < uVar7) {
            nvAssertFailedNoLog("pteBlockIdx < NV0080_CTRL_DMA_PDE_INFO_PTE_BLOCKS",
                                "src/kernel/mem_mgr/gpu_vaspace.c",0x8eb);
            goto LAB_00450b4b;
          }
          uVar21 = (ulong)uVar7;
          *(int *)(param_2 + uVar21 * 4 + 6) = (int)uVar13;
          uVar13 = memdescGetPhysAddr(local_68[0],*(undefined8 *)(lVar1 + 0x50),0);
          param_2[uVar21 * 4 + 4] = uVar13;
          *(uint *)((long)param_2 + uVar21 * 0x20 + 0x2c) = (uint)*(byte *)(lVar11 + 2);
          *(int *)(param_2 + uVar21 * 4 + 7) = (int)(1L << (*(char *)(lVar11 + 1) + 1U & 0x3f));
          *(undefined4 *)(param_2 + uVar21 * 4 + 5) = *(undefined4 *)(local_68[0] + 0x74);
          iVar6 = memdescGetAddressSpace();
          if (iVar6 == 1) {
            iVar19 = 2 - (uint)(*(int *)(local_68[0] + 0x74) == 0);
          }
          else {
            iVar19 = 0;
            if (iVar6 != 2) {
              nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x915);
              goto LAB_00450b4b;
            }
          }
          *(int *)((long)param_2 + uVar21 * 0x20 + 0x34) = iVar19;
          uVar7 = uVar7 + 1;
        }
      }
      lVar8 = lVar8 + 1;
    } while (lVar8 != 5);
    iVar6 = mmuWalkGetPageLevelInfo(lVar2,uVar3,0,&local_70,&local_7c);
    if (iVar6 == 0) {
      if (local_70 != 0) {
        uVar13 = memdescGetPhysAddr(local_70,*(undefined8 *)(lVar1 + 0x50),0);
        param_2[0x18] = uVar13;
        iVar6 = memdescGetAddressSpace(local_70);
        if (iVar6 == 1) {
          *(uint *)((long)param_2 + 0x14) = 2 - (uint)(*(int *)(local_70 + 0x74) == 0);
          return 0;
        }
        if (iVar6 == 2) {
          *(undefined4 *)((long)param_2 + 0x14) = 0;
          return 0;
        }
        nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x938);
      }
LAB_00450b4b:
      iVar6 = 0x40;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "mmuWalkGetPageLevelInfo(pWalk, pRootFmt, 0, (const MMU_WALK_MEMDESC**)&pRootMem, &rootSize)"
                 ,"src/kernel/mem_mgr/gpu_vaspace.c",0x91b);
    }
  }
  else {
    iVar6 = 0x1f;
    nvAssertFailedNoLog("NULL != pGpu","src/kernel/mem_mgr/gpu_vaspace.c",0x8b4);
  }
  return iVar6;
}


// ===== 00450f80 gvaspaceExternalRootDirCommit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gvaspaceExternalRootDirCommit_IMPL
              (long *param_1,undefined4 param_2,long param_3,undefined8 *param_4)

{
  ulong uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 *puVar14;
  ulong uVar15;
  ulong uVar16;
  long *plVar17;
  undefined4 local_b8;
  int local_b4;
  long local_b0;
  ulong local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  code *local_50;
  code *local_48;
  undefined8 local_40;
  
  plVar17 = (long *)0x0;
  if (param_1 != (long *)0x0) {
    plVar17 = (long *)param_1[0x11];
  }
  local_b0 = 0;
  local_b8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  plVar10 = (long *)gvaspaceGetGpuState_IMPL(param_1,param_3);
  uVar4 = *(uint *)((long)param_4 + 0xc);
  lVar6 = plVar10[2];
  bVar2 = **(byte **)(*plVar10 + 8);
  uVar15 = (**(code **)(*param_1 + 0x1e8))(param_1);
  lVar12 = param_1[0x28];
  iVar8 = vgpuGetCallingContextGfid(param_3,&local_b4);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/mem_mgr/gpu_vaspace.c",
               0xb1e);
    return iVar8;
  }
  cVar7 = (**(code **)(*plVar17 + 0xb0))(plVar17);
  if ((cVar7 != '\0') && (lVar13 = (**(code **)(*plVar17 + 200))(plVar17,param_3), lVar13 != 0)) {
    nvAssertFailedNoLog("pPDB == NULL","src/kernel/mem_mgr/gpu_vaspace.c",0xb28);
    return 0x40;
  }
  uVar9 = *(uint *)((long)param_4 + 0xc) & 3;
  if (uVar9 == 3) {
    nvAssertFailedNoLog("!\"invalid aperture\"","src/kernel/mem_mgr/gpu_vaspace.c",0xb3a);
    return 0x1f;
  }
  uVar1 = ((ulong)(*(uint *)(param_4 + 1) - 1) + 1 << (**(byte **)(*plVar10 + 8) & 0x3f)) - 1;
  if (uVar1 < (ulong)param_1[0x28]) {
    nvAssertFailedNoLog("vaLimitNew >= pGVAS->vaLimitInternal","src/kernel/mem_mgr/gpu_vaspace.c",
                        0xb41);
    return 0x1f;
  }
  if ((ulong)param_1[0x21] < uVar1) {
    nvAssertFailedNoLog("vaLimitNew <= pGVAS->vaLimitMax","src/kernel/mem_mgr/gpu_vaspace.c",0xb42);
    return 0x1f;
  }
  local_a8 = (ulong)(*(byte **)(*plVar10 + 8))[2] * (ulong)*(uint *)(param_4 + 1);
  if (local_a8 >> 0x20 != 0) {
    nvAssertFailedNoLog("(NvU64)pParams->numEntries * (NvU64)pGpuState->pFmt->pRoot->entrySize <= NV_U32_MAX"
                        ,"src/kernel/mem_mgr/gpu_vaspace.c",0xb45);
    return 0x1f;
  }
  iVar8 = *(int *)(CSWTCH_362 + (ulong)uVar9 * 4);
  uVar5 = *(undefined4 *)(CSWTCH_363 + (ulong)uVar9 * 4);
  lVar13 = plVar17[0xd];
  if ((char)param_1[0x20] == '\0') {
    bVar3 = *(byte *)((long)param_1 + 0xba);
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0xb4d,"gvaspaceExternalRootDirCommit_IMPL",1,
                 "NVRM: PASID: %u\n",*(undefined4 *)((long)param_4 + 0x1c));
    *(undefined4 *)((long)param_1 + 0x104) = *(undefined4 *)((long)param_4 + 0x1c);
    bVar3 = *(byte *)((long)param_1 + 0xba);
  }
  if (((bVar3 & 4) == 0) && (cVar7 = (**(code **)(*plVar17 + 0xb0))(plVar17), cVar7 == '\0')) {
    nvAssertFailedNoLog("(pGVAS->flags & VASPACE_FLAGS_SHARED_MANAGEMENT) || vaspaceIsExternallyOwned(pVAS)"
                        ,"src/kernel/mem_mgr/gpu_vaspace.c",0xb51);
    return 0x56;
  }
  lVar11 = 1L << (bVar2 & 0x3f);
  uVar16 = -lVar11;
  uVar15 = uVar15 & uVar16;
  lVar12 = (lVar11 + lVar12 & uVar16) - 1;
  if (iVar8 == 1) {
    if (local_b4 != 0) {
      nvCheckFailedNoLog(4,"IS_GFID_PF(gfid)","src/kernel/mem_mgr/gpu_vaspace.c",0xb57);
      return 0x1f;
    }
    iVar8 = RmDeprecatedConvertOs32ToOs02Flags(0x10000000,0,0,&local_b8);
    if (iVar8 == 0) {
      iVar8 = osCreateMemFromOsDescriptor(param_3,*param_4,param_2,local_b8,&local_a8,&local_b0);
      if (iVar8 == 0) goto LAB_00451245;
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xb69);
    }
    else {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xb62);
    }
LAB_00451510:
    plVar17[0xd] = lVar13;
    if (lVar6 == 0) goto LAB_00451670;
  }
  else {
    if ((*(char *)(param_3 + 0x908) != '\0') && (*(char *)(param_3 + 0x4913) == '\0')) {
      return 0;
    }
    iVar8 = memdescCreate(&local_b0,param_3,local_a8 & 0xffffffff,0x1000,1,2,uVar5,
                          (ulong)(local_b4 != 0) << 8);
    if (iVar8 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xb79);
      goto LAB_00451510;
    }
    memdescDescribe(local_b0,2,*param_4,local_a8 & 0xffffffff);
    memdescSetPageSize(local_b0,plVar17[10],0x1000);
LAB_00451245:
    if ((*(char *)(param_3 + 0x908) != '\0') && (*(char *)(param_3 + 0x4913) == '\0')) {
      return 0;
    }
    cVar7 = (**(code **)(*plVar17 + 0xb0))(plVar17);
    if (cVar7 != '\0') {
      if (*(char *)((long)param_1 + 0xf5) != '\0') {
        param_1[0x1f] = local_b0;
        return 0;
      }
      return 0;
    }
    iVar8 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_3,0,&local_a0);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0xb94);
      goto LAB_00451510;
    }
    if ((uVar4 & 8) == 0) {
      local_80 = (long)param_4 + 0x14;
    }
    if (lVar6 != 0) {
LAB_00451382:
      (**(code **)(*param_1 + 0x1b8))(param_1,param_3,1);
      puVar14 = (undefined8 *)mmuWalkGetCallbacks(plVar10[1]);
      local_70 = *puVar14;
      local_68 = puVar14[1];
      local_60 = puVar14[2];
      local_58 = puVar14[3];
      local_40 = puVar14[6];
      local_48 = _gmmuWalkCBCopyEntries_SkipExternal;
      local_50 = _gmmuWalkCBFillEntries_SkipExternal;
      mmuWalkSetCallbacks(plVar10[1],&local_70);
      plVar17[0xd] = uVar1;
      iVar8 = mmuWalkMigrateLevelInstance
                        (plVar10[1],*(undefined8 *)(*plVar10 + 8),0,local_b0,local_a8 & 0xffffffff,
                         uVar4 >> 4 & 1);
      if (iVar8 == 0) {
        mmuWalkSetCallbacks(plVar10[1],puVar14);
        goto LAB_00451451;
      }
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xbd4);
      mmuWalkSetCallbacks(plVar10[1],puVar14);
      goto LAB_00451510;
    }
    iVar8 = mmuWalkReserveEntries(plVar10[1],*(undefined8 *)(*plVar10 + 8),uVar15,lVar12,1);
    if (iVar8 == 0) {
      mmuWalkGetPageLevelInfo(plVar10[1],*(undefined8 *)(*plVar10 + 8),0,plVar10 + 2,&local_70);
      lVar11 = plVar10[2];
      if (lVar11 == 0) {
        nvAssertFailedNoLog("NULL != pGpuState->pRootInternal","src/kernel/mem_mgr/gpu_vaspace.c",
                            0xbb2);
        lVar11 = plVar10[2];
      }
      *(int *)(lVar11 + 0x90) = *(int *)(lVar11 + 0x90) + 1;
      cVar7 = *(char *)(plVar10[2] + 100);
      if (cVar7 != '\0') {
        *(char *)(plVar10[2] + 100) = cVar7 + '\x01';
      }
      goto LAB_00451382;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xbac);
    plVar17[0xd] = lVar13;
LAB_00451670:
    if (plVar10[2] != 0) {
      memdescFree();
      memdescDestroy(plVar10[2]);
      plVar10[2] = 0;
      mmuWalkReleaseEntries(plVar10[1],*(undefined8 *)(*plVar10 + 8),uVar15,lVar12);
    }
  }
  memdescDestroy(local_b0);
  local_b0 = 0;
LAB_00451451:
  if (local_90 != 0) {
    gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_a0);
    return iVar8;
  }
  return iVar8;
}


// ===== 00451833 gvaspaceExternalRootDirRevoke_IMPL.cold =====

void gvaspaceExternalRootDirRevoke_IMPL_cold(void)

{
  code *pcVar1;
  long lVar2;
  long unaff_RBP;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(unaff_RBP + -0x98);
  for (lVar2 = 0xc; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  gvaspaceGetGpuState_IMPL(0);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00451860 gvaspaceExternalRootDirRevoke_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gvaspaceExternalRootDirRevoke_IMPL(long *param_1,long param_2)

{
  byte bVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  long lVar13;
  ulong uVar14;
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
  code *local_50;
  code *local_48;
  undefined8 local_40;
  
  if (param_1 == (long *)0x0) {
    puVar11 = &local_a0;
    for (lVar13 = 0xc; lVar13 != 0; lVar13 = lVar13 + -1) {
      *(undefined4 *)puVar11 = 0;
      puVar11 = (undefined8 *)((long)puVar11 + 4);
    }
    gvaspaceGetGpuState_IMPL(0);
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  plVar2 = (long *)param_1[0x11];
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  plVar9 = (long *)gvaspaceGetGpuState_IMPL();
  if ((*(char *)(param_2 + 0x908) == '\0') || (*(char *)(param_2 + 0x4913) != '\0')) {
    lVar13 = param_1[0x28];
    bVar1 = **(byte **)(*plVar9 + 8);
    uVar3 = plVar2[0xc];
    cVar7 = (**(code **)(*plVar2 + 0xb0))(plVar2);
    if (cVar7 == '\0') {
      lVar4 = plVar9[2];
      if (lVar4 == 0) {
        nvAssertFailedNoLog("NULL != pGpuState->pRootInternal","src/kernel/mem_mgr/gpu_vaspace.c",
                            0xc2f);
        return 0x40;
      }
      uVar5 = *(ulong *)(lVar4 + 0x30);
      (**(code **)(*param_1 + 0x1b8))(param_1,param_2,1);
      iVar8 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_a0);
      if (iVar8 == 0) {
        lVar10 = 1L << (bVar1 & 0x3f);
        uVar14 = -lVar10;
        puVar11 = (undefined8 *)mmuWalkGetCallbacks(plVar9[1]);
        local_70 = *puVar11;
        local_68 = puVar11[1];
        local_60 = puVar11[2];
        local_58 = puVar11[3];
        local_50 = _gmmuWalkCBFillEntries_SkipExternal;
        local_40 = puVar11[6];
        local_48 = _gmmuWalkCBCopyEntries_SkipExternal;
        mmuWalkSetCallbacks(plVar9[1],&local_70);
        plVar2[0xd] = param_1[0x28];
        iVar8 = mmuWalkMigrateLevelInstance
                          (plVar9[1],*(undefined8 *)(*plVar9 + 8),0,lVar4,uVar5 & 0xffffffff,0);
        if (iVar8 != 0) {
          nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xc4e);
        }
        plVar9[2] = 0;
        iVar8 = mmuWalkReleaseEntries
                          (plVar9[1],*(undefined8 *)(*plVar9 + 8),uVar3 & uVar14,
                           (lVar13 + lVar10 & uVar14) - 1);
        if (iVar8 != 0) {
          nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xc56);
        }
        mmuWalkSetCallbacks(plVar9[1],puVar11);
        gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_a0);
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar8,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0xc3c);
      return iVar8;
    }
    uVar12 = (**(code **)(*plVar2 + 200))(plVar2,param_2);
    memdescDestroy(uVar12);
    if (*(char *)((long)param_1 + 0xf5) != '\0') {
      param_1[0x1f] = 0;
      return 0;
    }
  }
  else {
    uVar12 = (**(code **)(*plVar2 + 200))(plVar2,param_2);
    memdescFree(uVar12);
    memdescDestroy(uVar12);
  }
  return 0;
}


// ===== 00451bb0 gvaspaceDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gvaspaceDestruct_IMPL(long *param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 local_68;
  undefined8 local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar6 = param_1[0x13];
  if (lVar6 != 0) {
    (**(code **)(lVar6 + 0x50))(lVar6,param_1,_gvaspaceFreeVASBlock,1);
    (**(code **)param_1[0x13])();
    portMemFree(param_1[0x13]);
    param_1[0x13] = 0;
  }
  iVar4 = mapCount_IMPL(param_1 + 0x23);
  if (iVar4 != 0) {
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x398);
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x399,"gvaspaceDestruct_IMPL",4,
                 "NVRM: GVAS is still used by some channel group(s)\n");
  }
  mapDestroy_IMPL(param_1 + 0x23);
  lVar6 = param_1[0x22];
  if (lVar6 != 0) {
    lVar2 = param_1[0x11];
    uVar13 = *(uint *)(lVar2 + 0x48);
    if (uVar13 != 0) {
      iVar4 = 0;
joined_r0x00451c74:
      for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
        iVar4 = iVar4 + 1;
      }
      lVar6 = gpumgrGetGpu(iVar4);
      if (lVar6 == 0) {
        nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x3a6);
      }
      else {
        uVar12 = *(uint *)(param_1 + 0x17);
        if ((uVar12 & 0x80) != 0) {
          local_68 = 0;
          plVar3 = (long *)param_1[0x11];
          local_60 = 0;
          local_58 = (long *)0x0;
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          iVar5 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar6,0,&local_68);
          if (iVar5 == 0) {
            uVar11 = (**(code **)(*plVar3 + 0x60))(plVar3);
            uVar7 = (**(code **)(*plVar3 + 0x58))(plVar3);
            iVar5 = mmuWalkUnmap(local_58[1],uVar7,uVar11);
            gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
            if (iVar5 != 0) goto LAB_00452303;
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar5,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x332);
LAB_00452303:
            nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x348);
            nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x3ac);
          }
          uVar12 = *(uint *)(param_1 + 0x17);
        }
        if ((uVar12 & 0x1000000) != 0) {
          local_68 = 0;
          plVar3 = (long *)param_1[0x11];
          local_60 = 0;
          local_58 = (long *)0x0;
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          lVar8 = *(long *)(&DAT_00001b90 + lVar6);
          (**(code **)(*param_1 + 0x1b0))(param_1,lVar6);
          iVar5 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar6,0,&local_68);
          if (iVar5 == 0) {
            uVar11 = (**(code **)(*plVar3 + 0x60))(plVar3);
            uVar7 = (**(code **)(*plVar3 + 0x58))(plVar3);
            iVar5 = mmuWalkUnmap(local_58[1],uVar7,uVar11);
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "mmuWalkUnmap(userCtx.pGpuState->pWalk, vaspaceGetVaStart(pVAS), vaspaceGetVaLimit(pVAS))"
                         ,"src/kernel/mem_mgr/gpu_vaspace.c",0x35d);
              nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x3b2);
              goto joined_r0x00451ca2;
            }
            gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
          }
          else {
            nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x362,"_gvaspaceFlaVaspaceDestruct",3,
                         "NVRM: Failed to acquire walk user context\n");
          }
          nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x366,"_gvaspaceFlaVaspaceDestruct",1,
                       "NVRM: Releasing legacy FLA VASPACE, gpu: %x \n",
                       *(undefined4 *)(lVar6 + 0x7a4));
          *(undefined4 *)(lVar8 + 0xa81c) = 0;
          *(undefined8 *)(lVar8 + 0xa820) = 0;
        }
      }
joined_r0x00451ca2:
      if (uVar13 >> 1 != 0) {
        uVar13 = uVar13 >> 1;
        iVar4 = iVar4 + 1;
        goto joined_r0x00451c74;
      }
      uVar13 = uVar13 >> 1;
      uVar12 = *(uint *)(lVar2 + 0x48);
      if (uVar12 != 0) {
joined_r0x00451e14:
        for (; (uVar12 & 1) == 0; uVar12 = uVar12 >> 1) {
          uVar13 = uVar13 + 1;
        }
        lVar6 = gpumgrGetGpu(uVar13);
        if (lVar6 == 0) {
          nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x3b8);
        }
        else if (((*(char *)(lVar6 + 0x4913) != '\0') || (*(char *)(lVar6 + 0x909) != '\0')) &&
                (param_1[0x2a] != 0)) {
          local_68 = 0;
          local_60 = 0;
          local_58 = (long *)0x0;
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          iVar4 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar6,0,&local_68);
          if (iVar4 == 0) {
            uVar11 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*local_58 + 8),0x15);
            iVar4 = mmuWalkReleaseEntries(local_58[1],uVar11,param_1[0x2a],param_1[0x2b]);
            gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
            if (iVar4 == 0) goto joined_r0x00451e4a;
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x378);
          }
          nvAssertFailedNoLog("NV_OK == _gvaspaceReleaseVaForServerRm(pGVAS, pGpu)",
                              "src/kernel/mem_mgr/gpu_vaspace.c",0x3be);
        }
joined_r0x00451e4a:
        if (uVar12 >> 1 != 0) {
          uVar12 = uVar12 >> 1;
          uVar13 = uVar13 + 1;
          goto joined_r0x00451e14;
        }
        uVar12 = uVar12 >> 1;
        uVar13 = *(uint *)(lVar2 + 0x48);
        if (uVar13 != 0) {
          while( true ) {
            for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
              uVar12 = uVar12 + 1;
            }
            lVar6 = gpumgrGetGpu(uVar12);
            if (lVar6 == 0) {
              nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x3c3);
            }
            else {
              lVar8 = gvaspaceGetGpuState_IMPL(param_1,lVar6);
              if ((*(long *)(lVar8 + 0x10) != 0) &&
                 (iVar4 = gvaspaceExternalRootDirRevoke_IMPL(param_1,lVar6,&local_68), iVar4 != 0))
              {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x4d6);
              }
              local_68 = 0;
              local_60 = 0;
              lVar1 = lVar8 + 0x38;
              local_58 = (long *)0x0;
              local_50 = 0;
              local_48 = 0;
              local_40 = 0;
              lVar9 = listHead_IMPL(lVar1);
              while (lVar9 != 0) {
                lVar10 = listNext_IMPL(lVar1,lVar9);
                listRemove_IMPL(lVar1,lVar9);
                lVar9 = lVar10;
              }
              iVar4 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar6,0,&local_68);
              if (iVar4 == 0) {
                mmuWalkLevelInstancesForceFree(*(undefined8 *)(lVar8 + 8));
                gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
              }
              mmuWalkDestroy(*(undefined8 *)(lVar8 + 8));
              if (*(long *)(lVar8 + 0x30) != 0) {
                rmMemPoolRelease(*(long *)(lVar8 + 0x30),(int)param_1[0x17]);
              }
              *(undefined8 *)(lVar8 + 8) = 0;
              lVar6 = listHead_IMPL(lVar1);
              if (lVar6 != 0) {
                nvAssertFailedNoLog("NULL == listHead(&pGpuState->reservedPageTableEntries)",
                                    "src/kernel/mem_mgr/gpu_vaspace.c",0x4e6);
              }
              listDestroy_IMPL(lVar1);
            }
            uVar13 = uVar13 >> 1;
            if (uVar13 == 0) break;
            uVar12 = uVar12 + 1;
          }
          uVar13 = *(uint *)(lVar2 + 0x48);
          iVar4 = 0;
          if (uVar13 != 0) {
            while( true ) {
              for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
                iVar4 = iVar4 + 1;
              }
              lVar6 = gpumgrGetGpu(iVar4);
              if (lVar6 == 0) {
                nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x3d1);
              }
              else {
                uVar11 = gvaspaceGetGpuState_IMPL(param_1,lVar6);
                gmmuMemDescCacheFree(uVar11);
              }
              uVar13 = uVar13 >> 1;
              if (uVar13 == 0) break;
              iVar4 = iVar4 + 1;
            }
          }
        }
      }
      lVar6 = param_1[0x22];
    }
    portMemFree(lVar6);
    param_1[0x22] = 0;
  }
  return;
}


// ===== 00452370 gvaspaceUpdatePde2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int gvaspaceUpdatePde2_IMPL(long *param_1,long param_2,uint *param_3)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  uint *puVar16;
  ulong uVar17;
  uint uVar18;
  int local_e0;
  uint local_dc;
  uint local_d8 [2];
  undefined8 local_d0;
  ulong local_c8 [2];
  uint local_b8 [4];
  byte *local_a8;
  ulong *local_a0;
  code *local_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_a8 = (byte *)0x0;
  local_a0 = (ulong *)0x0;
  local_98 = (code *)0x0;
  local_90 = 0;
  puVar8 = (undefined8 *)gvaspaceGetGpuState_IMPL();
  piVar1 = (int *)*puVar8;
  uVar5 = param_3[1];
  lVar2 = *(long *)(param_3 + 0xc);
  portMemSet(local_c8,0,0x10);
  uVar17 = (**(code **)(*param_1 + 0x170))(param_1);
  uVar9 = (**(code **)(*param_1 + 0x170))(param_1);
  uVar10 = (**(code **)(*param_1 + 0x170))(param_1);
  uVar11 = (**(code **)(*param_1 + 0x170))(param_1);
  uVar12 = (**(code **)(*param_1 + 0x170))(param_1);
  uVar13 = (**(code **)(*param_1 + 0x170))(param_1);
  lVar14 = mmuFmtFindLevelWithPageShift
                     (*(undefined8 *)(piVar1 + 2),
                      (uVar17 >> 0x20 != 0) << 5 | (uVar13 & 0xaaaaaaaaaaaaaaaa) != 0 |
                      ((uVar9 & 0xffff0000ffff0000) != 0) << 4 |
                      ((uVar10 & 0xff00ff00ff00ff00) != 0) << 3 |
                      ((uVar11 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                      ((uVar12 & 0xcccccccccccccccc) != 0) * '\x02');
  lVar15 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(piVar1 + 2),0xc);
  if (lVar14 == 0) {
    nvAssertFailedNoLog("NULL != pPTBig","src/kernel/mem_mgr/gpu_vaspace.c",0xd35);
  }
  else if (lVar15 == 0) {
    nvAssertFailedNoLog("NULL != pPT4KB","src/kernel/mem_mgr/gpu_vaspace.c",0xd36);
  }
  else {
    local_a8 = (byte *)mmuFmtFindLevelParent(*(undefined8 *)(piVar1 + 2),lVar14,&local_e0);
    local_98 = _gmmuWalkCBMapSingleEntry;
    local_a0 = local_c8;
    if (local_a8 == (byte *)0x0) {
      nvAssertFailedNoLog("NULL != mapTarget.pLevelFmt","src/kernel/mem_mgr/gpu_vaspace.c",0xd3d);
    }
    else {
      if (local_a8[4] == 2) {
        lVar15 = 0;
        iVar6 = 0;
        lVar14 = gmmuFmtGetPde(piVar1,local_a8,local_e0 == 0);
        do {
          if (3 < param_3[lVar15 * 4 + 5]) {
            nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0xd64);
            return 0x1f;
          }
          uVar18 = *(uint *)(CSWTCH_368 + (ulong)param_3[lVar15 * 4 + 5] * 4);
          *(uint *)((long)local_c8 + (ulong)*(ushort *)(lVar14 + 0x12)) =
               (uint)*(byte *)(*(long *)(lVar14 + 0x18) + 1 + (ulong)uVar18 * 2) <<
               ((byte)*(undefined2 *)(lVar14 + 0x10) & 0x1f) |
               *(uint *)((long)local_c8 + (ulong)*(ushort *)(lVar14 + 0x12)) &
               *(uint *)(lVar14 + 0xc);
          if (uVar18 != 0) {
            lVar3 = *(long *)(param_2 + 0x1b98);
            uVar4 = *(undefined8 *)(param_2 + 0x1b78);
            uVar17 = kgmmuEncodePhysAddr_IMPL
                               (lVar3,(ulong)uVar18,*(undefined8 *)(param_3 + lVar15 * 4 + 2),
                                0xffffffffffffffff);
            puVar16 = (uint *)gmmuFmtPdePhysAddrFld(lVar14,uVar18);
            if (*puVar16 != 0) {
              uVar17 = uVar17 >> ((byte)puVar16[0xe] & 0x3f);
              uVar9 = 0;
              do {
                uVar18 = (int)uVar9 + 1;
                uVar10 = *(ulong *)((long)local_c8 + (ulong)puVar16[uVar9 * 6 + 6]);
                *(ulong *)((long)local_c8 + (ulong)puVar16[uVar9 * 6 + 6]) =
                     (uVar17 << ((byte)puVar16[uVar9 * 6 + 5] & 0x3f) ^ uVar10) &
                     *(ulong *)(puVar16 + uVar9 * 6 + 2) ^ uVar10;
                uVar17 = uVar17 >> ((byte)puVar16[uVar9 * 6 + 4] & 0x3f);
                uVar9 = (ulong)uVar18;
              } while (uVar18 < *puVar16);
            }
            if (*piVar1 == 3) {
              local_b8[0] = 0;
              local_b8[1] = 0;
              local_b8[2] = 0;
              local_b8[3] = 0;
              local_88 = 0;
              local_80 = 0;
              local_78 = 0;
              local_70 = 0;
              local_dc = 0;
              local_d8[0] = 0;
              local_d0 = 0;
              local_d8[1] = 0;
              iVar7 = mmuWalkGetPageLevelInfo
                                (puVar8[1],local_a8,(ulong)*param_3 << (*local_a8 & 0x3f),&local_d0,
                                 local_d8 + 1);
              if (iVar7 != 0) {
                nvAssertOkFailedNoLog
                          (iVar7,
                           "mmuWalkGetPageLevelInfo(pGpuState->pWalk, mapTarget.pLevelFmt, (pParams->pdeIndex * mmuFmtLevelPageSize(mapTarget.pLevelFmt)), (const MMU_WALK_MEMDESC**)&pMemDesc, &memSize)"
                           ,"src/kernel/mem_mgr/gpu_vaspace.c",0xd7d);
                return iVar7;
              }
              local_88 = local_d0;
              local_80 = (ulong)((uint)local_a8[2] * *param_3);
              iVar7 = memmgrMemRead_IMPL(uVar4,&local_88,local_b8,local_a8[2],1);
              if (iVar7 != 0) {
                nvAssertOkFailedNoLog
                          (iVar7,
                           "memmgrMemRead(pMemoryManager, &surf, pde.v8, mapTarget.pLevelFmt->entrySize, TRANSFER_FLAGS_DEFER_FLUSH)"
                           ,"src/kernel/mem_mgr/gpu_vaspace.c",0xd85);
                return iVar7;
              }
              local_dc = (*(uint *)((long)local_b8 + (ulong)*(ushort *)(lVar14 + 0xfa)) &
                         *(uint *)(lVar14 + 0xf0)) >> ((byte)*(undefined2 *)(lVar14 + 0xf8) & 0x1f);
              if (*(byte *)(lVar14 + 0x14) != 0) {
                uVar17 = 0;
                do {
                  if ((*(char *)(*(long *)(lVar14 + 0x18) + uVar17 * 2) != '\0') &&
                     ((*(uint *)((long)local_b8 + (ulong)*(ushort *)(lVar14 + 0x12)) &
                      *(uint *)(lVar14 + 8)) >> ((byte)*(undefined2 *)(lVar14 + 0x10) & 0x1f) ==
                      (uint)*(byte *)(*(long *)(lVar14 + 0x18) + 1 + uVar17 * 2))) {
                    if ((int)uVar17 != 0) {
                      iVar7 = (**(code **)(lVar3 + 0x298))
                                        (lVar3,local_dc,uVar17 & 0xffffffff,local_d8);
                      if (iVar7 != 0) {
                        nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromHw_HAL(pKernelGmmu, pdePcfHw, currAperture, &pdePcfSw) == NV_OK)"
                                            ,"src/kernel/mem_mgr/gpu_vaspace.c",0xd8f);
                        return 0x1f;
                      }
                      local_d8[0] = local_d8[0] | 0x20;
                      goto LAB_00452c0d;
                    }
                    break;
                  }
                  uVar17 = uVar17 + 1;
                } while ((uint)uVar17 < (uint)*(byte *)(lVar14 + 0x14));
              }
              local_d8[0] = 0x20;
LAB_00452c0d:
              iVar7 = (**(code **)(lVar3 + 0x290))(lVar3,local_d8[0],&local_dc);
              if (iVar7 != 0) {
                nvAssertFailedNoLog("(kgmmuTranslatePdePcfFromSw_HAL(pKernelGmmu, pdePcfSw, &pdePcfHw) == NV_OK)"
                                    ,"src/kernel/mem_mgr/gpu_vaspace.c",0xd97);
                return 0x1f;
              }
              *(uint *)((long)local_c8 + (ulong)*(ushort *)(lVar14 + 0xfa)) =
                   local_dc << ((byte)*(undefined2 *)(lVar14 + 0xf8) & 0x1f) |
                   *(uint *)((long)local_c8 + (ulong)*(ushort *)(lVar14 + 0xfa)) &
                   *(uint *)(lVar14 + 0xf4);
            }
            else {
              *(uint *)((long)local_c8 + (ulong)*(ushort *)(lVar14 + 0xea)) =
                   (uint)(*(byte *)(lVar14 + 0xec) ^ 1) <<
                   ((byte)*(undefined2 *)(lVar14 + 0xe8) & 0x1f) |
                   *(uint *)((long)local_c8 + (ulong)*(ushort *)(lVar14 + 0xea)) &
                   *(uint *)(lVar14 + 0xe4);
            }
            iVar6 = iVar6 + 1;
          }
          if (lVar15 == 1) {
            if (iVar6 == 0) {
              if ((uVar5 & 0x10) != 0) {
                lVar14 = kgmmuFmtGetFamily_IMPL(*(undefined8 *)(param_2 + 0x1b98),*piVar1);
                local_c8[1] = *(undefined8 *)(lVar14 + 0x4e8);
                local_c8[0] = *(ulong *)(lVar14 + 0x4e0);
              }
            }
            else {
              if ((uVar5 & 0x10) != 0) {
                nvAssertFailedNoLog("!bSparse","src/kernel/mem_mgr/gpu_vaspace.c",0xdb2);
                return 0x1f;
              }
              uVar5 = param_3[1] >> 2 & 3;
              if (uVar5 != 0) {
                piVar1 = *(int **)(piVar1 + 6);
                if (*piVar1 == 0) {
                  nvAssertFailedNoLog("nvFieldIsValid32(&pFmt->pPdeMulti->fldSizeRecipExp)",
                                      "src/kernel/mem_mgr/gpu_vaspace.c",0xdb7);
                  return 0x1f;
                }
                *(uint *)((long)local_c8 + (ulong)*(ushort *)((long)piVar1 + 10)) =
                     *(uint *)((long)local_c8 + (ulong)*(ushort *)((long)piVar1 + 10)) & piVar1[1] |
                     uVar5 << ((byte)(short)piVar1[2] & 0x1f);
              }
            }
            if (lVar2 != 0) {
              portMemCopy(lVar2,local_a8[2],local_c8,local_a8[2]);
              return 0;
            }
            uVar17 = (ulong)*param_3 << (*local_a8 & 0x3f);
            if (uVar17 < *(ulong *)(param_1[0x11] + 0x60)) {
              nvAssertFailedNoLog("vaLo >= pVAS->vasStart","src/kernel/mem_mgr/gpu_vaspace.c",0xdca)
              ;
              return 0x1f;
            }
            uVar9 = (uVar17 - 1) + (1L << (*local_a8 & 0x3f));
            if ((ulong)param_1[0x28] < uVar9) {
              nvAssertFailedNoLog("vaHi <= pGVAS->vaLimitInternal",
                                  "src/kernel/mem_mgr/gpu_vaspace.c",0xdcb);
              return 0x1f;
            }
            iVar6 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_68);
            if (iVar6 != 0) {
              nvAssertOkFailedNoLog
                        (iVar6,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                         "src/kernel/mem_mgr/gpu_vaspace.c",0xdce);
              return iVar6;
            }
            iVar6 = mmuWalkMap(*(undefined8 *)(local_58 + 8),uVar17,uVar9,&local_a8);
            gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
            if (iVar6 != 0) {
              nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xdd3);
              return iVar6;
            }
            if ((param_3[1] & 1) != 0) {
              (**(code **)(*param_1 + 0x1b8))(param_1,param_2,0);
              return 0;
            }
            return 0;
          }
          lVar15 = 1;
          lVar14 = gmmuFmtGetPde(piVar1,local_a8,local_e0);
        } while( true );
      }
      nvAssertFailedNoLog("2 == mapTarget.pLevelFmt->numSubLevels",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0xd3e);
    }
  }
  return 0x56;
}


// ===== 00452d50 gvaspaceResize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int gvaspaceResize_IMPL(long *param_1,long *param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  undefined8 *puVar7;
  long lVar8;
  uint uVar9;
  long lVar10;
  int local_9c;
  undefined8 *local_98;
  ulong local_90;
  char local_75;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar10 = 0;
  if (param_1 != (long *)0x0) {
    lVar10 = param_1[0x11];
  }
  if ((*(uint *)(param_1 + 0x17) & 0x40000) != 0) {
    nvAssertFailedNoLog("!(pGVAS->flags & VASPACE_FLAGS_SHARED_MANAGEMENT)",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0xc6e);
    return 0x56;
  }
  if (*param_2 == -1) {
    local_90 = param_1[0x21];
  }
  else {
    local_90 = *param_2 + -1 + *(long *)(lVar10 + 0x60);
  }
  if (*(ulong *)(lVar10 + 0x68) == local_90) {
LAB_00453016:
    *param_2 = (param_1[0x28] + 1) - *(long *)(lVar10 + 0x60);
    local_9c = 0;
  }
  else {
    if (local_90 < *(ulong *)(lVar10 + 0x68)) {
      nvAssertFailedNoLog("vaLimitNew >= pVAS->vasLimit","src/kernel/mem_mgr/gpu_vaspace.c",0xc82);
    }
    else {
      if (local_90 <= (ulong)param_1[0x21]) {
        if ((char)param_1[0x29] != '\0') {
          nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0xc8a,"gvaspaceResize_IMPL",4,
                       "NVRM: doesn\'t support clientVA expansion\n");
          nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0xc8b);
        }
        *(ulong *)(lVar10 + 0x68) = local_90;
        param_1[0x28] = local_90;
        (**(code **)(param_1[0x13] + 0x10))(param_1[0x13],param_1[0x21]);
        iVar3 = _gvaspaceReserveTopForGrowth(param_1);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"_gvaspaceReserveTopForGrowth(pGVAS)","src/kernel/mem_mgr/gpu_vaspace.c",
                     0xc95);
          return iVar3;
        }
        uVar9 = *(uint *)(lVar10 + 0x48);
        if (uVar9 != 0) {
          iVar3 = 0;
joined_r0x00452e63:
          for (; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1) {
            iVar3 = iVar3 + 1;
          }
          lVar5 = gpumgrGetGpu(iVar3);
          if (lVar5 == 0) {
            nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0xc98);
          }
          else {
            plVar6 = (long *)gvaspaceGetGpuState_IMPL(param_1,lVar5);
            local_68 = 0;
            local_60 = 0;
            local_58 = 0;
            local_50 = 0;
            local_48 = 0;
            local_40 = 0;
            puVar7 = (undefined8 *)mmuWalkGetCallbacks(plVar6[1]);
            local_75 = '\0';
            local_74 = 0;
            uVar1 = *(undefined8 *)(*plVar6 + 8);
            local_70 = 0;
            lVar8 = (**(code **)(*param_1 + 0x1a0))(param_1,lVar5);
            if (lVar8 != 0) {
              iVar4 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar5,0,&local_68);
              if (iVar4 != 0) {
                nvAssertOkFailedNoLog
                          (iVar4,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                           "src/kernel/mem_mgr/gpu_vaspace.c",0xca9);
LAB_00453080:
                if (local_70 != 0) {
                  (*(code *)puVar7[1])(&local_68,uVar1,0,local_70,(code *)puVar7[1]);
                }
                if (local_60 == 0) {
                  return iVar4;
                }
                gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
                return iVar4;
              }
              iVar4 = mmuWalkGetPageLevelInfo(plVar6[1],uVar1,0,&local_70,&local_74);
              if (iVar4 != 0) {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xcaf);
                goto LAB_00453080;
              }
              iVar4 = (*(code *)*puVar7)(&local_68,uVar1,0,local_90,1,&local_70,&local_74,&local_75)
              ;
              if (iVar4 != 0) {
                nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xcb7);
                goto LAB_00453080;
              }
              if (local_75 == '\0') {
                cVar2 = (*(code *)puVar7[2])(&local_68,uVar1,local_70,0);
                if (cVar2 == '\0') {
                  nvAssertFailedNoLog("bDone","src/kernel/mem_mgr/gpu_vaspace.c",0xcd1);
                  iVar4 = 0x40;
                  goto LAB_00453080;
                }
              }
              else {
                (**(code **)(*param_1 + 0x1b8))(param_1,lVar5,1);
                iVar4 = mmuWalkMigrateLevelInstance(plVar6[1],uVar1,0,local_70,local_74,0);
                if (iVar4 != 0) {
                  nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xcc5);
                  goto LAB_00453080;
                }
              }
            }
            if (local_60 != 0) {
              local_98 = &local_68;
              gvaspaceWalkUserCtxRelease_IMPL(param_1,local_98);
            }
          }
          uVar9 = uVar9 >> 1;
          if (uVar9 != 0) {
            iVar3 = iVar3 + 1;
            goto joined_r0x00452e63;
          }
        }
        goto LAB_00453016;
      }
      nvAssertFailedNoLog("vaLimitNew <= pGVAS->vaLimitMax","src/kernel/mem_mgr/gpu_vaspace.c",0xc83
                         );
    }
    local_9c = 0x2e;
  }
  return local_9c;
}


// ===== 00453300 gvaspaceUnregisterAllChanGrps_IMPL =====

byte gvaspaceUnregisterAllChanGrps_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = gpuGetKernelFifoShared_IMPL(param_2);
  if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x908) == '\0')) {
    return -(*(char *)(lVar1 + 0x4b3) != '\0') & 0x56;
  }
  return 0;
}


// ===== 00453350 gvaspaceGetPageLevelInfo_IMPL =====

int gvaspaceGetPageLevelInfo_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  byte *pbVar8;
  long lVar9;
  byte bVar10;
  long lVar11;
  int local_5c;
  uint local_44;
  long local_40 [2];
  
  lVar11 = 0;
  if (param_1 != 0) {
    lVar11 = *(long *)(param_1 + 0x88);
  }
  if (*(long *)(param_1 + 0x110) == 0) {
    return 0x56;
  }
  plVar5 = (long *)gvaspaceGetGpuState_IMPL();
  if (plVar5 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0xeaf);
  }
  else {
    lVar1 = plVar5[1];
    pbVar8 = *(byte **)(*plVar5 + 8);
    uVar2 = *(ulong *)(param_3 + 0x10);
    lVar6 = mmuFmtFindLevelWithPageShift
                      (pbVar8,(uVar2 & 0xaaaaaaaaaaaaaaaa) != 0 | (uVar2 >> 0x20 != 0) << 5 |
                              ((uVar2 & 0xffff0000ffff0000) != 0) << 4 |
                              ((uVar2 & 0xff00ff00ff00ff00) != 0) << 3 |
                              ((uVar2 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                              ((uVar2 & 0xcccccccccccccccc) != 0) * '\x02');
    if (lVar6 != 0) {
      local_5c = 0;
      lVar3 = param_3;
      while (pbVar8 != (byte *)0x0) {
        local_40[0] = 0;
        local_44 = 0;
        if (local_5c == 6) {
          nvAssertFailedNoLog("level < GMMU_FMT_MAX_LEVELS","src/kernel/mem_mgr/gpu_vaspace.c",0xebc
                             );
          return 0x40;
        }
        iVar4 = mmuWalkGetPageLevelInfo
                          (lVar1,pbVar8,*(undefined8 *)(param_3 + 8),local_40,&local_44);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "mmuWalkGetPageLevelInfo(pWalk, pLevelFmt, pParams->virtAddress, (const MMU_WALK_MEMDESC**)&pMemDesc, &memSize)"
                     ,"src/kernel/mem_mgr/gpu_vaspace.c",0xebe);
          return iVar4;
        }
        if (local_40[0] == 0) break;
        *(byte **)(lVar3 + 0x28) = pbVar8;
        *(ulong *)(lVar3 + 0x88) = (ulong)local_44;
        portMemCopy(lVar3 + 0x30,0x18,pbVar8,0x18);
        lVar9 = 0;
        bVar10 = 0;
        while (bVar10 < pbVar8[4]) {
          portMemCopy(lVar3 + 0x48 + lVar9,0x18,*(long *)(pbVar8 + 0x10) + lVar9,0x18);
          lVar9 = lVar9 + 0x18;
          if (bVar10 == 1) break;
          bVar10 = 1;
        }
        uVar7 = memdescGetPhysAddr(local_40[0],*(undefined8 *)(lVar11 + 0x50),0);
        *(undefined8 *)(lVar3 + 0x78) = uVar7;
        iVar4 = memdescGetAddressSpace(local_40[0]);
        if (iVar4 == 1) {
          iVar4 = (*(int *)(local_40[0] + 0x74) == 0) + 3;
        }
        else {
          if (iVar4 != 2) {
            nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0xee4);
            return 0x40;
          }
          iVar4 = 1;
        }
        *(int *)(lVar3 + 0x80) = iVar4;
        *(int *)(lVar3 + 0x90) =
             (int)((-1L << (*pbVar8 & 0x3f) & *(ulong *)(param_3 + 8) &
                   ~(-1L << (pbVar8[1] + 1 & 0x3f))) >> (*pbVar8 & 0x3f));
        pbVar8 = (byte *)mmuFmtGetNextLevel(pbVar8,lVar6);
        local_5c = local_5c + 1;
        lVar3 = lVar3 + 0x70;
      }
      *(int *)(param_3 + 0x20) = local_5c;
      return 0;
    }
    nvAssertFailedNoLog("NULL != pTargetFmt","src/kernel/mem_mgr/gpu_vaspace.c",0xeb5);
  }
  return 0x1f;
}


// ===== 00453700 _gvaspacePopulatePDEentries =====

int _gvaspacePopulatePDEentries(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined1 local_2f0 [8];
  undefined8 local_2e8;
  undefined8 local_2e0;
  uint local_2d0;
  undefined1 local_2c0 [664];
  
  portMemSet(local_2f0,0,0x2c8);
  portMemSet(param_3,0,0xb8);
  local_2e8 = *(undefined8 *)(param_1 + 0x150);
  local_2e0 = 0x200000;
  iVar1 = gvaspaceGetPageLevelInfo_IMPL(param_1,param_2,local_2f0);
  if (iVar1 == 0) {
    if (local_2d0 != 0) {
      lVar3 = param_3;
      puVar5 = local_2c0;
      do {
        lVar4 = lVar3 + 0x18;
        *(undefined1 *)(lVar3 + 0x3c) = *puVar5;
        *(undefined8 *)(lVar3 + 0x28) = *(undefined8 *)(puVar5 + 0x48);
        *(undefined4 *)(lVar3 + 0x38) = *(undefined4 *)(puVar5 + 0x50);
        *(undefined8 *)(lVar3 + 0x30) = *(undefined8 *)(puVar5 + 0x58);
        lVar3 = lVar4;
        puVar5 = puVar5 + 0x70;
      } while (lVar4 != param_3 + (ulong)local_2d0 * 0x18);
    }
    *(uint *)(param_3 + 0x20) = local_2d0;
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu(param_2);
    *(undefined8 *)(param_3 + 8) = 0x200000;
    *(undefined4 *)(param_3 + 4) = uVar2;
    lVar3 = *(long *)(param_1 + 0x150);
    *(long *)(param_3 + 0x10) = lVar3;
    *(long *)(param_3 + 0x18) = lVar3 + 0x1fffffff;
  }
  else {
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x139b);
  }
  return iVar1;
}


// ===== 00453850 gvaspaceCopyServerRmReservedPdesToServerRm_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int gvaspaceCopyServerRmReservedPdesToServerRm_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  char *pcVar9;
  ulong uVar10;
  int local_174;
  long local_170;
  undefined8 local_168;
  undefined4 local_160;
  undefined8 *local_158;
  undefined4 local_150;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  
  lVar6 = resservGetTlsCallContext();
  if (((*(char *)(param_2 + 0x4913) == '\0') && (*(char *)(param_2 + 0x909) == '\0')) ||
     (*(long *)(param_1 + 0x150) == 0)) {
    return 0;
  }
  lVar7 = gpumgrGetGpuGrpFromGpu(param_2);
  if (lVar6 == 0) {
    if (*(char *)(param_2 + 0x908) != '\0') {
      return 0;
    }
    lVar6 = *(long *)(lVar7 + 0xd0);
    lVar7 = __nvoc_dynamicCast(param_1,__nvoc_class_def_OBJVASPACE);
    if (lVar6 != lVar7) {
      return 0;
    }
    iVar5 = _gvaspacePopulatePDEentries(param_1,param_2,&local_f0);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"_gvaspacePopulatePDEentries(pGVAS, pGpu, &globalCopyParams.PdeCopyParams)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0xf5a);
      return iVar5;
    }
    iVar5 = (**(code **)(param_2 + 0x3b90))
                      (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                       *(undefined4 *)(param_2 + 0x3b3c),0x20800a9f,&local_f0,0xb8);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GMMU_COPY_RESERVED_SPLIT_GVASPACE_PDES_TO_SERVER, &globalCopyParams, sizeof(NV2080_CTRL_INTERNAL_GMMU_COPY_RESERVED_SPLIT_GVASPACE_PDES_TO_SERVER_PARAMS))"
                 ,"src/kernel/mem_mgr/gpu_vaspace.c",0xf5e);
      return iVar5;
    }
    return 0;
  }
  local_170 = 0;
  lVar7 = *(long *)(lVar6 + 0x10);
  uVar1 = *(undefined4 *)(*(long *)(lVar6 + 8) + 0x48);
  if (*(int *)(lVar7 + 0x118) == 0xcd048b) {
    local_174 = *(int *)(lVar7 + 0x10);
LAB_00453a29:
    iVar5 = refFindAncestorOfType(lVar7,&DAT_00e0ac20,&local_170);
    if (iVar5 != 0) {
      uVar8 = 0xf20;
      goto LAB_00453d9b;
    }
    bVar3 = false;
    uVar2 = *(undefined4 *)(local_170 + 0x10);
    if (local_174 == 0) goto LAB_00453920;
  }
  else {
    local_174 = 0;
    if (*(int *)(lVar7 + 0x118) != 0xe0ac20) goto LAB_00453a29;
    uVar2 = *(undefined4 *)(lVar7 + 0x10);
    local_170 = lVar7;
LAB_00453920:
    bVar3 = false;
    if (*(char *)(param_2 + 0x909) != '\0') {
      local_f0 = 0;
      local_e8 = 0;
      local_e0 = 0;
      local_d8 = 0;
      local_d0 = 0;
      local_c8 = 0;
      local_c0 = 0;
      iVar5 = serverutilGenResourceHandle(uVar1,&local_174);
      if (iVar5 != 0) {
        uVar8 = 0xf30;
LAB_00453d9b:
        pcVar9 = "NV_OK == status";
        goto LAB_00453b33;
      }
      local_f0 = CONCAT44(local_f0._4_4_,3);
      lVar6 = gpuGetRpc(param_2);
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0xf34);
      }
      else {
        if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x90a) == '\0')) {
          iVar5 = (**(code **)(lVar6 + 0x348))(param_2,lVar6,uVar1,uVar2,local_174,0x90f1,&local_f0)
          ;
        }
        else {
          iVar5 = (**(code **)(param_2 + 0x3b60))
                            (param_2 + 0x3b58,uVar1,uVar2,local_174,0x90f1,&local_f0,0x38);
        }
        if (iVar5 != 0) {
          uVar8 = 0xf3d;
          goto LAB_00453d9b;
        }
      }
      bVar3 = true;
    }
  }
  iVar4 = _gvaspacePopulatePDEentries(param_1,param_2,&local_f0);
  if (iVar4 == 0) {
    uVar10 = CONCAT44(local_174,uVar1);
    portMemSet(&local_168,0,0x78);
    local_160 = 0x90f10106;
    local_150 = 0xb8;
    local_168 = uVar10;
    local_158 = &local_f0;
    lVar6 = gpuGetRpc(param_2);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x135f);
      iVar4 = 0x1a;
    }
    else {
      if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x90a) == '\0')) {
        iVar4 = rpcDmaControl_wrapper
                          (param_2,lVar6,local_168 & 0xffffffff,local_168._4_4_,local_160,local_158,
                           local_150);
      }
      else {
        iVar4 = (**(code **)(param_2 + 0x3b90))(param_2 + 0x3b58);
      }
      if (iVar4 == 0) goto LAB_004539fa;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1366);
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xf4b);
  }
  else {
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0xf42);
  }
LAB_004539fa:
  if (!bVar3) {
    return iVar4;
  }
  lVar6 = gpuGetRpc(param_2);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0xf51);
    iVar5 = 0x1a;
  }
  else {
    if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x90a) == '\0')) {
      iVar5 = (**(code **)(lVar6 + 0xf0))(param_2,lVar6,uVar1,uVar2,local_174);
    }
    else {
      iVar5 = (**(code **)(param_2 + 0x3b70))(param_2 + 0x3b58,uVar1);
    }
    if (iVar5 == 0) {
      return iVar4;
    }
  }
  uVar8 = 0xf52;
  pcVar9 = "NV_OK == tmpStatus";
LAB_00453b33:
  nvAssertFailedNoLog(pcVar9,"src/kernel/mem_mgr/gpu_vaspace.c",uVar8);
  return iVar5;
}


// ===== 00453eb0 gvaspaceReserveSplitVaSpace_IMPL =====

int gvaspaceReserveSplitVaSpace_IMPL(long param_1,long param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  int iVar10;
  int local_60;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  long *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar3 = vgpuGetCallingContextGfid(param_2,&local_60);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/mem_mgr/gpu_vaspace.c",
               0x196);
    return iVar3;
  }
  iVar3 = 0;
  if (*(char *)(param_2 + 0x4913) == '\0') {
    if (*(char *)(param_2 + 0x909) == '\0') {
      if (local_60 == 0) {
        return 0;
      }
      uVar6 = *(ulong *)(param_1 + 0x140);
      uVar7 = uVar6 - 0x1fffffff;
      if (0x100000000 < uVar7) {
        uVar7 = 0x100000000;
      }
      bVar1 = true;
      bVar2 = false;
    }
    else {
      uVar6 = *(ulong *)(param_1 + 0x140);
      uVar7 = uVar6 - 0x1fffffff;
      if (0x100000000 < uVar7) {
        uVar7 = 0x100000000;
      }
      bVar2 = true;
      bVar1 = false;
    }
  }
  else {
    uVar6 = *(ulong *)(param_1 + 0x140);
    bVar2 = true;
    uVar7 = uVar6 - 0x1fffffff;
    if (0x100000000 < uVar7) {
      uVar7 = 0x100000000;
    }
    bVar1 = false;
  }
  lVar4 = *(long *)(param_1 + 0x88);
  *(ulong *)(param_1 + 0x150) = uVar7;
  if (uVar7 < *(ulong *)(lVar4 + 0x60)) {
    uVar7 = *(ulong *)(lVar4 + 0x60) + 0x100000000;
    *(ulong *)(param_1 + 0x150) = uVar7;
  }
  uVar9 = uVar7 + 0x1fffffff;
  *(ulong *)(param_1 + 0x158) = uVar9;
  if ((uVar7 & 0x1fffff) != 0) {
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x1b4);
    return 0x1f;
  }
  if (uVar6 < uVar9) {
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x1bf,"gvaspaceReserveSplitVaSpace_IMPL",4,
                 "NVRM: vaLimitServerRMOwned (0x%llx)> vaLimitInternal (0x%llx)\n",uVar9,uVar6);
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x1c2);
    return 0x1f;
  }
  if (!bVar1) {
    if (!bVar2) {
      return 0;
    }
    local_5c = *(int *)(lVar4 + 0x48);
    iVar3 = rmGpuGroupLockAcquire(0,2,2,0x2000,&local_5c);
    if (iVar3 == 0x10006) {
      local_5c = 0;
    }
    else if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = 0x1f;
    if ((*(ulong *)(param_1 + 0x158) < *(ulong *)(param_1 + 0x150)) ||
       (iVar3 = _gvaspaceReserveRange_part_0_isra_0(*(undefined8 *)(param_1 + 0x98)), iVar3 != 0)) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x159);
    }
    else {
      uVar8 = *(uint *)(lVar4 + 0x48);
      if (uVar8 != 0) {
        iVar10 = 0;
        while( true ) {
          for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1) {
            iVar10 = iVar10 + 1;
          }
          lVar4 = gpumgrGetGpu(iVar10);
          if (lVar4 == 0) {
            nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x15c);
          }
          else {
            local_58 = 0;
            local_50 = 0;
            local_48 = (long *)0x0;
            local_40 = 0;
            local_38 = 0;
            local_30 = 0;
            iVar3 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar4,0,&local_58);
            if (iVar3 != 0) goto LAB_004542d8;
            uVar5 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*local_48 + 8),0x15);
            iVar3 = mmuWalkReserveEntries
                              (local_48[1],uVar5,*(undefined8 *)(param_1 + 0x150),
                               *(undefined8 *)(param_1 + 0x158),1);
            gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_58);
            if ((iVar3 != 0) ||
               (iVar3 = gvaspaceCopyServerRmReservedPdesToServerRm_IMPL(param_1,lVar4), iVar3 != 0))
            goto LAB_004542d8;
          }
          uVar8 = uVar8 >> 1;
          if (uVar8 == 0) break;
          iVar10 = iVar10 + 1;
        }
      }
      iVar3 = 0;
    }
LAB_004542d8:
    if (local_5c == 0) {
      return iVar3;
    }
    rmGpuGroupLockRelease(local_5c,0);
    return iVar3;
  }
  if (*(ulong *)(lVar4 + 0x60) < uVar7) {
    if (uVar7 - 1 < *(ulong *)(lVar4 + 0x60)) {
      iVar10 = 0x1f;
    }
    else {
      iVar10 = _gvaspaceReserveRange_part_0_isra_0(*(undefined8 *)(param_1 + 0x98));
      if (iVar10 == 0) {
        uVar9 = *(ulong *)(param_1 + 0x158);
        uVar6 = *(ulong *)(param_1 + 0x140);
        goto LAB_0045405d;
      }
    }
    iVar3 = iVar10;
    nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",300);
  }
  else {
LAB_0045405d:
    if (uVar9 < uVar6) {
      iVar3 = 0x1f;
      if ((uVar6 < uVar9 + 1) ||
         (iVar3 = _gvaspaceReserveRange_part_0_isra_0
                            (*(undefined8 *)(param_1 + 0x98),uVar9 + 1,uVar6), iVar3 != 0)) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x134);
      }
    }
  }
  return iVar3;
}


// ===== 0045435d gvaspaceConstruct__IMPL.cold =====

void gvaspaceConstruct__IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00454370 gvaspaceConstruct__IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int gvaspaceConstruct__IMPL
              (long *param_1,int param_2,undefined8 param_3,ulong param_4,ulong param_5,
              ulong param_6,ulong param_7,uint param_8)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  bool bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  long *plVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  undefined8 uVar19;
  int iVar20;
  uint uVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  uint uVar25;
  long lVar26;
  ulong local_e0;
  uint local_d4;
  char local_7d;
  undefined4 local_7c;
  undefined1 local_78 [8];
  ulong local_70;
  long local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar18 = param_1[0x11];
  uVar5 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(lVar18 + 0x48));
  lVar10 = gpumgrGetGpu(uVar5);
  if (param_2 != 0x90f1) {
    nvAssertFailedNoLog("FERMI_VASPACE_A == classId","src/kernel/mem_mgr/gpu_vaspace.c",0x1ed);
    return 0x1f;
  }
  *(uint *)(param_1 + 0x17) = param_8;
  if ((param_8 & 0x20000000) != 0) {
    *(undefined1 *)((long)param_1 + 0xf4) = 1;
  }
  if ((param_8 & 0x40000000) != 0) {
    *(undefined1 *)((long)param_1 + 0xf5) = 1;
  }
  if ((param_8 & 4) != 0) {
    *(undefined1 *)(param_1 + 0x20) = 1;
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x1ff,"gvaspaceConstruct__IMPL",1,
                 "NVRM: ATS Enabled VaSpace\n");
    *(undefined4 *)((long)param_1 + 0x104) = 0xffffffff;
  }
  if ((param_8 & 0x1000000) != 0) {
    *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 0x8000;
  }
  uVar21 = param_8 >> 0x15 & 3;
  if (uVar21 == 3) {
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x21b);
    return 0x56;
  }
  lVar26 = 0x78;
  uVar6 = *(uint *)(lVar18 + 0x48) >> 1;
  if (uVar6 != 0) {
    iVar20 = 0x1f;
    if (uVar6 != 0) {
      for (; uVar6 >> iVar20 == 0; iVar20 = iVar20 + -1) {
      }
    }
    lVar26 = (ulong)(iVar20 + 2) * 0x78;
  }
  lVar11 = portMemAllocNonPaged(lVar26);
  param_1[0x22] = lVar11;
  if (lVar11 == 0) {
    nvAssertFailedNoLog("NULL != pGVAS->pGpuStates","src/kernel/mem_mgr/gpu_vaspace.c",0x223);
    return 0x51;
  }
  portMemSet(lVar11,0,lVar26);
  uVar12 = portMemAllocatorGetGlobalNonPaged();
  mapInit_IMPL(param_1 + 0x23,uVar12,4);
  uVar6 = *(uint *)(lVar18 + 0x48);
  if (uVar6 == 0) {
    local_d4 = 0;
    local_e0 = 0;
  }
  else {
    local_d4 = 0;
    local_e0 = 0;
    uVar7 = param_8 & 8;
    if (uVar7 == 0) {
      param_6 = param_4;
    }
    bVar4 = true;
    iVar20 = 0;
joined_r0x004544d4:
    for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
      iVar20 = iVar20 + 1;
    }
    lVar26 = gpumgrGetGpu(iVar20);
    if (lVar26 != 0) {
      plVar13 = (long *)gvaspaceGetGpuState_IMPL(param_1,lVar26);
      lVar11 = *(long *)(lVar26 + 0x1b98);
      lVar2 = param_1[0x11];
      lVar14 = kmemsysGetStaticConfig_IMPL(lVar26,*(undefined8 *)(lVar26 + 0x1b70));
      if (lVar11 == 0) {
        nvCheckFailedNoLog(1,"pKernelGmmu != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x41f);
      }
      else {
        if ((param_8 & 0x4000) != 0) {
          uVar12 = *(undefined8 *)(lVar26 + 0x1b78);
          lVar15 = resservGetTlsCallContext();
          local_68 = *(long *)(lVar15 + 0x10);
          if ((*(int *)(local_68 + 0x118) != 0xe0ac20) &&
             (iVar8 = refFindAncestorOfType(local_68,&DAT_00e0ac20,&local_68), iVar8 != 0)) {
            nvAssertOkFailedNoLog
                      (iVar8,"refFindAncestorOfType(pDeviceRef, classId(Device), &pDeviceRef)",
                       "src/kernel/mem_mgr/gpu_vaspace.c",0x42e);
            goto LAB_00454dc3;
          }
          lVar15 = __nvoc_dynamicCast(*(undefined8 *)(local_68 + 8),__nvoc_class_def_Device);
          if (lVar15 == 0) {
            nvAssertFailedNoLog("pDevice != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x432);
            iVar8 = 0x40;
            goto LAB_00454dc3;
          }
          iVar8 = memmgrPageLevelPoolsGetInfo_IMPL(lVar26,uVar12,lVar15,plVar13 + 6);
          if (iVar8 != 0) {
            nvAssertOkFailedNoLog
                      (iVar8,
                       "memmgrPageLevelPoolsGetInfo(pGpu, pMemoryManager, pDevice, &pGpuState->pPageTableMemPool)"
                       ,"src/kernel/mem_mgr/gpu_vaspace.c",0x434);
            goto LAB_00454dc3;
          }
        }
        lVar26 = kgmmuFmtGet_IMPL(lVar11,0,(ulong)uVar21 << 0x10);
        if (lVar26 != 0) {
          *plVar13 = lVar26;
          uVar9 = mmuFmtAllPageSizes(*(undefined8 *)(lVar26 + 8));
          uVar17 = (ulong)(uVar9 & 0x30000);
          uVar9 = *(uint *)(lVar14 + 0x14);
          uVar5 = nvLogBase2(uVar17);
          lVar11 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(lVar26 + 8),uVar5);
          if (lVar11 == 0) {
            nvAssertFailedNoLog("NULL != pBigPT","src/kernel/mem_mgr/gpu_vaspace.c",0x445);
          }
          else {
            uVar1 = **(uint **)(lVar26 + 0x18);
            uVar25 = 0;
            if (uVar1 != 0) {
              uVar25 = uVar1 >> ((byte)(short)(*(uint **)(lVar26 + 0x18))[2] & 0x1f);
            }
            uVar16 = (1L << ((*(byte **)(lVar26 + 8))[1] + 1 & 0x3f)) - 1;
            if (param_5 == 0) {
              uVar22 = uVar16;
              uVar23 = uVar16;
              if (uVar7 == 0) goto LAB_004546bc;
LAB_0045468c:
              if (uVar16 < param_7) {
                nvAssertFailedNoLog("vaLimitInternal <= vaLimitMax",
                                    "src/kernel/mem_mgr/gpu_vaspace.c",0x465);
              }
              else if (param_7 < param_6) {
                nvAssertFailedNoLog("vaStartInternal <= vaLimitInternal",
                                    "src/kernel/mem_mgr/gpu_vaspace.c",0x466);
              }
              else {
                uVar23 = param_7;
                if (0xfffff < param_6) goto LAB_004546bc;
                nvAssertFailedNoLog("vaStartInternal >= vaStartMin",
                                    "src/kernel/mem_mgr/gpu_vaspace.c",0x467);
              }
            }
            else if (uVar16 < param_5) {
              nvCheckFailedNoLog(4,"vaLimit <= vaLimitMax","src/kernel/mem_mgr/gpu_vaspace.c",0x45e)
              ;
            }
            else {
              uVar22 = param_5;
              uVar23 = param_5;
              if (uVar7 != 0) goto LAB_0045468c;
LAB_004546bc:
              uVar24 = 1L << (*(char *)(lVar11 + 1) + 1U & 0x3f);
              if ((param_8 & 0x40000) != 0) {
                lVar11 = 1L << (**(byte **)(lVar26 + 8) & 0x3f);
                uVar22 = (uVar22 + lVar11 & -lVar11) - 1;
              }
              if (bVar4) {
                param_1[0x15] = (ulong)uVar9;
                param_1[0x14] = uVar17;
                param_1[0x16] = uVar24;
                uVar17 = param_4;
                if (param_4 == 0) {
                  uVar17 = (ulong)((param_8 & 0x80000) == 0) << 0x14;
                }
                *(ulong *)(lVar2 + 0x60) = uVar17;
                if (param_6 != 0) {
                  uVar17 = param_6;
                }
                param_1[0x27] = uVar17;
                *(ulong *)(lVar2 + 0x68) = uVar22;
                param_1[0x28] = uVar23;
                param_1[0x21] = uVar16;
LAB_00454763:
                uVar9 = (**(code **)(*param_1 + 400))(param_1);
                iVar8 = mmuWalkCreate(*(undefined8 *)(lVar26 + 8),0,g_gmmuWalkCallbacks,
                                      (uVar9 & 1) * 2,plVar13 + 1,0);
                if (iVar8 == 0) {
                  uVar12 = portMemAllocatorGetGlobalNonPaged();
                  listInit_IMPL(plVar13 + 7,uVar12,0x10);
                  listInitIntrusive_IMPL(plVar13 + 3,0xf8);
                  bVar4 = false;
                  local_e0 = uVar24;
                  local_d4 = uVar25;
                  goto joined_r0x004547f0;
                }
                nvAssertOkFailedNoLog
                          (iVar8,
                           "mmuWalkCreate(pFmt->pRoot, NULL, &g_gmmuWalkCallbacks, walkFlags, &pGpuState->pWalk, NULL)"
                           ,"src/kernel/mem_mgr/gpu_vaspace.c",0x4b5);
                goto LAB_00454dc3;
              }
              if (uVar17 == param_1[0x14]) {
                if ((ulong)uVar9 == param_1[0x15]) {
                  if (uVar24 == param_1[0x16]) {
                    if ((param_4 == 0) && ((param_8 & 0x80000) == 0)) {
                      uVar17 = *(ulong *)(lVar2 + 0x60);
                      if (uVar17 < 0x100000) {
                        uVar17 = 0x100000;
                      }
                      *(ulong *)(lVar2 + 0x60) = uVar17;
                    }
                    uVar17 = *(ulong *)(lVar2 + 0x68);
                    if (uVar22 < *(ulong *)(lVar2 + 0x68)) {
                      uVar17 = uVar22;
                    }
                    *(ulong *)(lVar2 + 0x68) = uVar17;
                    uVar17 = param_1[0x27];
                    if ((ulong)param_1[0x27] < param_6) {
                      uVar17 = param_6;
                    }
                    param_1[0x27] = uVar17;
                    uVar17 = param_1[0x28];
                    if (uVar23 < (ulong)param_1[0x28]) {
                      uVar17 = uVar23;
                    }
                    param_1[0x28] = uVar17;
                    uVar17 = param_1[0x21];
                    if (uVar16 < (ulong)param_1[0x21]) {
                      uVar17 = uVar16;
                    }
                    param_1[0x21] = uVar17;
                    if (uVar24 == local_e0) {
                      if (uVar25 == local_d4) goto LAB_00454763;
                      nvAssertFailedNoLog("*pPartialPdeExpMax == partialPdeExpMax",
                                          "src/kernel/mem_mgr/gpu_vaspace.c",0x4ac);
                    }
                    else {
                      nvAssertFailedNoLog("*pFullPdeCoverage == fullPdeCoverage",
                                          "src/kernel/mem_mgr/gpu_vaspace.c",0x4ab);
                    }
                  }
                  else {
                    nvAssertFailedNoLog("extManagedAlign == pGVAS->extManagedAlign",
                                        "src/kernel/mem_mgr/gpu_vaspace.c",0x4a2);
                  }
                }
                else {
                  nvAssertFailedNoLog("compPageSize == pGVAS->compPageSize",
                                      "src/kernel/mem_mgr/gpu_vaspace.c",0x4a1);
                }
              }
              else {
                nvAssertFailedNoLog("bigPageSize == pGVAS->bigPageSize",
                                    "src/kernel/mem_mgr/gpu_vaspace.c",0x4a0);
              }
            }
          }
          iVar8 = 0x1f;
          goto LAB_00454dc3;
        }
        nvAssertFailedNoLog("NULL != pFmt","src/kernel/mem_mgr/gpu_vaspace.c",0x43a);
      }
      iVar8 = 0x56;
      goto LAB_00454dc3;
    }
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x22a);
joined_r0x004547f0:
    if (uVar6 >> 1 != 0) {
      uVar6 = uVar6 >> 1;
      iVar20 = iVar20 + 1;
      goto joined_r0x004544d4;
    }
  }
  if (*(ulong *)(lVar18 + 0x68) < *(ulong *)(lVar18 + 0x60)) {
    nvAssertFailedNoLog("pVAS->vasStart <= pVAS->vasLimit","src/kernel/mem_mgr/gpu_vaspace.c",0x23f)
    ;
    return 0x1f;
  }
  if (*(ulong *)(lVar18 + 0x68) < (ulong)param_1[0x28]) {
    nvAssertFailedNoLog("pVAS->vasLimit >= pGVAS->vaLimitInternal",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0x241);
    return 0x1f;
  }
  lVar26 = portMemAllocNonPaged(0xd8);
  param_1[0x13] = lVar26;
  if (lVar26 == 0) {
    nvAssertFailedNoLog("NULL != pGVAS->pHeap","src/kernel/mem_mgr/gpu_vaspace.c",0x248);
    iVar8 = 0x51;
    goto LAB_00454dc3;
  }
  constructObjEHeap(lVar26,*(undefined8 *)(lVar18 + 0x60),param_1[0x21] + 1,0x18,0);
  if ((*(char *)(lVar10 + 0x4922) != '\0') && ((*(uint *)(param_1 + 0x17) & 0x3810c01) == 0)) {
    iVar8 = vgpuIsCallingContextPlugin(lVar10,&local_7d);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",599);
      goto LAB_00454dc3;
    }
    if (((*(char *)(lVar10 + 0x4a4e) != '\0') || (local_7d == '\0')) &&
       (iVar8 = gvaspaceReserveSplitVaSpace_IMPL(param_1,lVar10), iVar8 != 0)) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x25b);
      goto LAB_00454dc3;
    }
  }
  if ((param_8 & 8) == 0) {
    iVar8 = _gvaspaceReserveTopForGrowth(param_1);
LAB_004549ff:
    if (iVar8 != 0) {
LAB_00455030:
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x271);
      goto LAB_00454dc3;
    }
    if (((param_8 & 0x10) != 0) && (local_d4 != 0)) {
      if ((param_8 & 8) != 0) {
LAB_00454ec8:
        nvAssertFailedNoLog("!(flags & VASPACE_FLAGS_RESTRICTED_RM_INTERNAL_VALIMITS)",
                            "src/kernel/mem_mgr/gpu_vaspace.c",0x27d);
        return 0x16;
      }
      uVar17 = -local_e0;
      uVar16 = local_e0 + param_1[0x28] & uVar17;
      uVar22 = *(ulong *)(lVar18 + 0x60) & uVar17;
      uVar17 = uVar16 - uVar22 >> 2 & uVar17;
      uVar5 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(lVar18 + 0x48));
      lVar10 = gpumgrGetGpu(uVar5);
      if (0x10000000 < uVar17) {
        uVar17 = 0x10000000;
      }
      param_1[0x18] = uVar17;
      _gvaspaceAddPartialPtRange(param_1,uVar22);
      if (((0x40000000 < uVar16) &&
          (_gvaspaceAddPartialPtRange(param_1,0x40000000), 0x100000000 < uVar16)) &&
         (*(char *)(*(long *)(lVar10 + 0x1bb8) + 0x1c5) != '\0')) {
        _gvaspaceAddPartialPtRange(param_1,0x100000000 - param_1[0x18]);
        _gvaspaceAddPartialPtRange(param_1,0x100000000);
      }
      _gvaspaceAddPartialPtRange(param_1,uVar16 - param_1[0x18]);
      if ((int)param_1[0x1e] != 0) {
        uVar21 = 0;
        do {
          uVar17 = 0;
          if (param_1[0x18] != 0) {
            do {
              local_7c = 0x10;
              local_70 = (local_e0 >> ((byte)local_d4 & 0x3f)) +
                         param_1[(ulong)uVar21 + 0x19] + uVar17;
              if (local_70 < *(ulong *)(lVar18 + 0x60)) {
                local_70 = *(ulong *)(lVar18 + 0x60);
              }
              if (local_70 <= (ulong)param_1[0x28]) {
                uVar22 = param_1[(ulong)uVar21 + 0x19] + uVar17 + local_e0;
                uVar16 = param_1[0x28] + 1;
                if (uVar22 < uVar16) {
                  uVar16 = uVar22;
                }
                local_68 = uVar16 - local_70;
                iVar8 = (**(code **)(param_1[0x13] + 8))
                                  (param_1[0x13],0x72737664,&local_7c,&local_70,&local_68,1,1,
                                   local_78,0,0);
                if (iVar8 != 0) {
                  nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x2fa);
                  goto LAB_00454dc3;
                }
              }
              uVar17 = uVar17 + local_e0;
            } while (uVar17 < (ulong)param_1[0x18]);
          }
          uVar21 = uVar21 + 1;
        } while (uVar21 < *(uint *)(param_1 + 0x1e));
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x29) = 1;
    if (*(ulong *)(lVar18 + 0x68) != param_1[0x21]) {
      iVar8 = 0x1f;
      if (*(ulong *)(lVar18 + 0x68) + 1 <= (ulong)param_1[0x21]) {
        iVar8 = _gvaspaceReserveRange_part_0_isra_0(param_1[0x13]);
        goto LAB_004549ff;
      }
      goto LAB_00455030;
    }
    if (((param_8 & 0x10) != 0) && (local_d4 != 0)) goto LAB_00454ec8;
  }
  if ((*(uint *)(param_1 + 0x17) & 0x80) == 0) {
    return 0;
  }
  uVar21 = *(uint *)(lVar18 + 0x48);
  if (uVar21 == 0) {
    return 0;
  }
  iVar20 = 0;
  iVar8 = 0;
joined_r0x00454be3:
  for (; (uVar21 & 1) == 0; uVar21 = uVar21 >> 1) {
    iVar20 = iVar20 + 1;
  }
  lVar18 = gpumgrGetGpu(iVar20);
  if (lVar18 == 0) {
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x304);
  }
  else {
    local_68 = 0;
    plVar13 = (long *)param_1[0x11];
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    iVar8 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar18,0,&local_68);
    if (iVar8 == 0) {
      uVar12 = (**(code **)(*plVar13 + 0x60))(plVar13);
      uVar19 = (**(code **)(*plVar13 + 0x58))(plVar13);
      iVar8 = mmuWalkSparsify(*(undefined8 *)(local_58 + 8),uVar19,uVar12,0);
      gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
      if (iVar8 == 0) goto LAB_00454c9b;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                 "src/kernel/mem_mgr/gpu_vaspace.c",0x101);
    }
    nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x118);
    nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x307);
  }
LAB_00454c9b:
  uVar21 = uVar21 >> 1;
  if (uVar21 != 0) {
    iVar20 = iVar20 + 1;
    goto joined_r0x00454be3;
  }
  if (iVar8 == 0) {
    return 0;
  }
LAB_00454dc3:
  gvaspaceDestruct_IMPL(param_1);
  return iVar8;
}


// ===== 004552d0 vaspaceapiCtrlCmdVaspaceGetGmmuFormat_IMPL =====

int vaspaceapiCtrlCmdVaspaceGetGmmuFormat_IMPL(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 0;
  local_20 = 0;
  iVar2 = _gvaspaceControl_Prolog_constprop_0(param_1,*param_2,param_2[1],&local_28,&local_20);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,
               "_gvaspaceControl_Prolog(pVaspaceApi, pGmmuFormatParams->hSubDevice, pGmmuFormatParams->subDeviceId, &pGVAS, &pGpu)"
               ,"src/kernel/mem_mgr/gpu_vaspace.c",0xfa3);
    return iVar2;
  }
  plVar3 = (long *)gvaspaceGetGpuState_IMPL(local_28,local_20);
  if (plVar3 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x76e);
    *(undefined8 *)(param_2 + 2) = 0;
  }
  else {
    lVar1 = *plVar3;
    *(long *)(param_2 + 2) = lVar1;
    if (lVar1 != 0) {
      return 0;
    }
  }
  nvAssertFailedNoLog("NULL != pGmmuFormatParams->pFmt","src/kernel/mem_mgr/gpu_vaspace.c",0xfa8);
  return 0x40;
}


// ===== 004553a0 vaspaceapiCtrlCmdVaspaceGetPageLevelInfo_IMPL.cold =====

void vaspaceapiCtrlCmdVaspaceGetPageLevelInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004553b0 vaspaceapiCtrlCmdVaspaceGetPageLevelInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong vaspaceapiCtrlCmdVaspaceGetPageLevelInfo_IMPL(long param_1,undefined4 *param_2)

{
  long *plVar1;
  undefined4 *puVar2;
  code *pcVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  long lVar9;
  ulong uVar10;
  long *local_38;
  long local_30 [2];
  
  local_38 = (long *)0x0;
  local_30[0] = 0;
  if (*(ulong *)(param_2 + 6) < 2) {
    uVar5 = _gvaspaceControl_Prolog_constprop_0(param_1,*param_2,param_2[1],&local_38,local_30);
    lVar4 = local_30[0];
    plVar8 = local_38;
    if (uVar5 != 0) {
      nvAssertOkFailedNoLog
                (uVar5,
                 "_gvaspaceControl_Prolog(pVaspaceApi, pPageLevelInfoParams->hSubDevice, pPageLevelInfoParams->subDeviceId, &pGVAS, &pGpu)"
                 ,"src/kernel/mem_mgr/gpu_vaspace.c",0xfba);
      return (ulong)uVar5;
    }
    if (local_38[0x22] == 0) {
      return 0x56;
    }
    if ((*(char *)(local_30[0] + 0x908) != '\0') && (*(char *)(local_30[0] + 0x4922) == '\0')) {
      uVar10 = (**(code **)(*local_38 + 0x178))(local_38);
      if ((uVar10 & 0x1000000) == 0) {
        lVar9 = resservGetTlsCallContext();
        puVar2 = *(undefined4 **)(*(long *)(lVar9 + 0x48) + 0x70);
        lVar9 = gpuGetRpc(lVar4);
        if (lVar9 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0xfcc);
          return 0x1a;
        }
        if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
          uVar10 = rpcDmaControl_wrapper
                             (lVar4,lVar9,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                              puVar2[6]);
          return uVar10;
        }
        uVar10 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58);
        return uVar10;
      }
    }
    if ((*(byte *)(param_2 + 6) & 1) == 0) {
LAB_004554fc:
      uVar10 = gvaspaceGetPageLevelInfo_IMPL(plVar8,lVar4,param_2);
      return uVar10;
    }
    lVar9 = *(long *)(&DAT_00001b90 + lVar4);
    lVar6 = (**(code **)(lVar9 + 0x4e8))(lVar4);
    uVar7 = 0;
    if (lVar6 != 0) {
      uVar7 = (**(code **)(lVar9 + 0x4e8))(lVar4);
    }
    plVar8 = (long *)__nvoc_dynamicCast(uVar7,__nvoc_class_def_OBJGVASPACE);
    if (plVar8 == (long *)0x0) {
      nvAssertFailedNoLog("pGVAS != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0xfde);
    }
    else {
      if (param_1 == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      plVar1 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
      lVar9 = CliFindMappingInClient
                        (*(undefined4 *)(*plVar1 + 0x48),*(undefined4 *)(plVar1[3] + 0x10),
                         *(undefined8 *)(param_2 + 2));
      if ((*(undefined8 **)(lVar9 + 0x50))[1] == 1) {
        *(long *)(param_2 + 2) =
             *(long *)(param_2 + 2) +
             (*(long *)**(undefined8 **)(lVar9 + 0x50) - *(long *)(lVar9 + 0x18));
        goto LAB_004554fc;
      }
      nvAssertFailedNoLog("pCpuMapping->pPrivate->memArea.numRanges == 1",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0xfe3);
    }
  }
  else {
    nvAssertFailedNoLog("pPageLevelInfoParams->flags <= NV90F1_CTRL_VASPACE_GET_PAGE_LEVEL_INFO_FLAG_BAR1"
                        ,"src/kernel/mem_mgr/gpu_vaspace.c",0xfb7);
  }
  return 0x1f;
}


// ===== 004556a0 vaspaceapiCtrlCmdVaspaceGetHostRmManagedSize_IMPL =====

ulong vaspaceapiCtrlCmdVaspaceGetHostRmManagedSize_IMPL(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  undefined1 local_28 [8];
  long local_20 [2];
  
  local_20[0] = 0;
  uVar1 = _gvaspaceControl_Prolog_constprop_0(param_1,*param_2,param_2[1],local_28,local_20);
  if ((int)uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1 & 0xffffffff,
               "_gvaspaceControl_Prolog(pVaspaceApi, pVaspaceGetHostRmManagedSizeParams->hSubDevice, pVaspaceGetHostRmManagedSizeParams->subDeviceId, &pGVAS, &pGpu)"
               ,"src/kernel/mem_mgr/gpu_vaspace.c",0x10fa);
    return uVar1 & 0xffffffff;
  }
  if ((*(char *)(local_20[0] + 0x909) == '\0') &&
     ((*(char *)(local_20[0] + 0x4913) == '\0' || (*(char *)(local_20[0] + 0x491e) != '\0')))) {
    *(undefined8 *)(param_2 + 2) = 0;
    return uVar1;
  }
  *(undefined8 *)(param_2 + 2) = 0x20000000;
  return uVar1;
}


// ===== 00455740 gvaspaceIsInternalVaRestricted_IMPL =====

undefined1 gvaspaceIsInternalVaRestricted_IMPL(long param_1)

{
  return *(undefined1 *)(param_1 + 0x148);
}


// ===== 00455750 gvaspaceReservePageTableEntries_IMPL =====

int gvaspaceReservePageTableEntries_IMPL
              (long param_1,undefined8 param_2,ulong param_3,undefined8 param_4,ulong param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong *puVar4;
  undefined8 uVar5;
  ulong local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar3 = gvaspaceGetGpuState_IMPL();
  if (lVar3 == 0) {
    nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x1281);
  }
  else {
    lVar3 = lVar3 + 0x38;
    puVar4 = (ulong *)listHead_IMPL(lVar3);
    while ((puVar4 != (ulong *)0x0 && (*puVar4 < param_3))) {
      puVar4 = (ulong *)listNext_IMPL(lVar3);
    }
    local_78 = param_3;
    local_70 = param_4;
    lVar3 = listInsertValue_IMPL(lVar3,puVar4,&local_78);
    if (lVar3 != 0) {
      local_68 = 0;
      local_60 = 0;
      local_58 = (long *)0x0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      iVar1 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_68);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                   "src/kernel/mem_mgr/gpu_vaspace.c",0x12c2);
        return iVar1;
      }
      lVar3 = 0;
      iVar1 = 0;
      if (param_5 == 0) {
LAB_004558e0:
        gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
        return iVar1;
      }
      do {
        if ((param_5 & 1) != 0) {
          uVar5 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*local_58 + 8),lVar3);
          iVar1 = mmuWalkReserveEntries(local_58[1],uVar5,param_3,param_4,1);
          if (iVar1 != 0) {
            nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x12cf,
                         "_gvaspaceReservePageTableEntries",4,"NVRM: Failed to Reserve Entries.\n");
            goto LAB_004558e0;
          }
          if (((*(byte *)(param_1 + 0xb8) & 0x80) != 0) &&
             (iVar2 = mmuWalkSparsify(local_58[1],param_3,param_4,0), iVar2 != 0)) {
            nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x12d8,
                         "_gvaspaceReservePageTableEntries",4,
                         "NVRM: Failed to sparsify reserved BAR1 page tables.\n");
            iVar1 = iVar2;
            goto LAB_004558e0;
          }
          if (param_5 >> 1 == 0) goto LAB_004558e0;
        }
        param_5 = param_5 >> 1;
        lVar3 = lVar3 + 1;
      } while( true );
    }
    nvAssertFailedNoLog("listInsertValue(&pGpuState->reservedPageTableEntries, pIter, &newReservedPageTableEntry)"
                        ,"src/kernel/mem_mgr/gpu_vaspace.c",0x128b);
  }
  return 0xffff;
}


// ===== 004559b0 vaspaceapiCtrlCmdVaspaceReserveEntries_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong vaspaceapiCtrlCmdVaspaceReserveEntries_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  long *local_38;
  long local_30 [2];
  
  local_38 = (long *)0x0;
  local_30[0] = 0;
  uVar4 = _gvaspaceControl_Prolog_constprop_0(param_1,*param_2,param_2[1],&local_38,local_30);
  lVar3 = local_30[0];
  plVar2 = local_38;
  if (uVar4 != 0) {
    nvAssertOkFailedNoLog
              (uVar4,
               "_gvaspaceControl_Prolog(pVaspaceApi, pReserveEntriesParams->hSubDevice, pReserveEntriesParams->subDeviceId, &pGVAS, &pGpu)"
               ,"src/kernel/mem_mgr/gpu_vaspace.c",0x1002);
    return (ulong)uVar4;
  }
  if (local_38[0x22] == 0) {
    uVar6 = 0x56;
  }
  else {
    uVar6 = *(ulong *)(param_2 + 2);
    if ((uVar6 == 0) || ((uVar6 - 1 & uVar6) != 0)) {
      nvAssertFailedNoLog("ONEBITSET(pReserveEntriesParams->pageSize)",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0x100c);
      return 0x1f;
    }
    if (((*(char *)(local_30[0] + 0x908) == '\0') || (*(char *)(local_30[0] + 0x4922) != '\0')) ||
       (uVar6 = (**(code **)(*local_38 + 0x178))(local_38), (uVar6 & 0x1000000) != 0)) {
      lVar5 = gvaspaceGetGpuState_IMPL(plVar2,lVar3);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x1021);
        uVar6 = 0x40;
      }
      else {
        uVar6 = gvaspaceReservePageTableEntries_IMPL
                          (plVar2,lVar3,*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6),
                           *(undefined8 *)(param_2 + 2));
        if ((int)uVar6 != 0) {
          nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1027);
          uVar6 = uVar6 & 0xffffffff;
        }
      }
    }
    else {
      lVar5 = resservGetTlsCallContext();
      puVar1 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
      lVar5 = gpuGetRpc(lVar3);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x1015);
        uVar6 = 0x1a;
      }
      else {
        if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x90a) != '\0')) {
          uVar6 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58);
          return uVar6;
        }
        uVar6 = rpcDmaControl_wrapper
                          (lVar3,lVar5,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                           puVar1[6]);
      }
    }
  }
  return uVar6;
}


// ===== 00455c20 gvaspaceCopyServerReservedPdes_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gvaspaceCopyServerReservedPdes_IMPL(long *param_1,long param_2,long param_3)

{
  undefined4 *puVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined4 uVar9;
  uint uVar10;
  undefined1 auVar11 [16];
  undefined8 uVar12;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar5 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_1 != (long *)0x0) {
    lVar5 = param_1[0x11];
  }
  if (param_1[0x22] == 0) {
    return 0x56;
  }
  if (*(uint *)(param_3 + 0x20) < 7) {
    uVar8 = *(ulong *)(param_3 + 8);
    if ((uVar8 != 0) && ((uVar8 - 1 & uVar8) == 0)) {
      if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x908) == '\0')) {
        lVar2 = *(long *)(param_2 + 0x1b98);
        plVar6 = (long *)gvaspaceGetGpuState_IMPL();
        if (plVar6 == (long *)0x0) {
          nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x10a5);
          uVar8 = 0x40;
        }
        else {
          if ((*(ulong *)(param_3 + 0x10) <= *(ulong *)(param_3 + 0x18)) &&
             (uVar4 = gvaspaceReservePageTableEntries_IMPL
                                (param_1,param_2,*(ulong *)(param_3 + 0x10),
                                 *(ulong *)(param_3 + 0x18),*(undefined8 *)(param_3 + 8)),
             uVar4 != 0)) {
            nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x10ad);
            return (ulong)uVar4;
          }
          (**(code **)(*param_1 + 0x1b8))(param_1,param_2,1);
          auVar11 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,param_2,0,&local_68);
          uVar12 = auVar11._8_8_;
          if (auVar11._0_4_ == 0) {
            uVar10 = *(int *)(param_3 + 0x20) - 1;
            uVar4 = 0;
            if (-1 < (int)uVar10) {
              param_3 = param_3 + (ulong)uVar10 * 0x18;
              do {
                if (*(int *)(param_3 + 0x38) == 1) {
                  uVar9 = 2;
                }
                else {
                  if (1 < *(int *)(param_3 + 0x38) - 3U) {
                    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x10cb);
                    uVar12 = extraout_RDX;
                    goto LAB_00455ea5;
                  }
                  uVar9 = 1;
                }
                uVar3 = memdescCreate(&local_70,param_2,*(undefined8 *)(param_3 + 0x30),0x1000,1,
                                      uVar9,*(undefined4 *)(lVar2 + 0x57c),0x100);
                if (uVar3 != 0) {
                  uVar12 = 0x10d5;
                  uVar4 = uVar3;
LAB_00456078:
                  nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",uVar12);
                  uVar12 = extraout_RDX_00;
                  goto LAB_00455ea5;
                }
                memdescDescribe(local_70,uVar9,*(undefined8 *)(param_3 + 0x28),
                                *(undefined8 *)(param_3 + 0x30));
                memdescSetPageSize(local_70,*(undefined8 *)(lVar5 + 0x50),0x1000);
                uVar7 = mmuFmtFindLevelWithPageShift
                                  (*(undefined8 *)(*plVar6 + 8),*(undefined1 *)(param_3 + 0x3c));
                uVar12 = 0;
                uVar3 = mmuWalkModifyLevelInstance
                                  (plVar6[1],uVar7,param_1[0x2a],local_70,
                                   *(undefined8 *)(param_3 + 0x30),0,0,0);
                if (uVar3 != 0) {
                  uVar12 = 0x10e8;
                  uVar4 = uVar3;
                  goto LAB_00456078;
                }
                uVar10 = uVar10 - 1;
                param_3 = param_3 + -0x18;
              } while (uVar10 != 0xffffffff);
              uVar4 = 0;
            }
LAB_00455ea5:
            gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68,uVar12);
            return (ulong)uVar4;
          }
          nvAssertOkFailedNoLog
                    (auVar11._0_8_ & 0xffffffff,
                     "gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                     "src/kernel/mem_mgr/gpu_vaspace.c",0x10b4);
          uVar8 = auVar11._0_8_ & 0xffffffff;
        }
      }
      else {
        lVar5 = resservGetTlsCallContext();
        puVar1 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
        lVar5 = gpuGetRpc(param_2);
        if (lVar5 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x109a);
          uVar8 = 0x1a;
        }
        else if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x90a) == '\0')) {
          uVar8 = rpcDmaControl_wrapper
                            (param_2,lVar5,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                             puVar1[6]);
        }
        else {
          uVar8 = (**(code **)(param_2 + 0x3b90))(param_2 + 0x3b58);
        }
      }
      return uVar8;
    }
    nvAssertFailedNoLog("ONEBITSET(pCopyServerReservedPdesParams->pageSize)",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0x1093);
  }
  else {
    nvAssertFailedNoLog("pCopyServerReservedPdesParams->numLevelsToCopy <= GMMU_FMT_MAX_LEVELS",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0x1091);
  }
  return 0x1f;
}


// ===== 004560e0 vaspaceapiCtrlCmdVaspaceCopyServerReservedPdes_IMPL =====

ulong vaspaceapiCtrlCmdVaspaceCopyServerReservedPdes_IMPL(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  long local_28;
  long local_20 [2];
  
  local_28 = 0;
  local_20[0] = 0;
  uVar1 = _gvaspaceControl_Prolog_constprop_0(param_1,*param_2,param_2[1],&local_28,local_20);
  if ((int)uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1 & 0xffffffff,
               "_gvaspaceControl_Prolog(pVaspaceApi, pCopyServerReservedPdesParams->hSubDevice, pCopyServerReservedPdesParams->subDeviceId, &pGVAS, &pGpu)"
               ,"src/kernel/mem_mgr/gpu_vaspace.c",0x1068);
    return uVar1 & 0xffffffff;
  }
  if ((((*(ulong *)(param_2 + 4) <= *(ulong *)(param_2 + 6)) ||
       (*(char *)(local_20[0] + 0x909) != '\0')) ||
      ((*(char *)(local_20[0] + 0x908) != '\0' && (*(char *)(local_20[0] + 0x4a4e) != '\0')))) &&
     (*(long *)(local_28 + 0x158) != 0)) {
    uVar1 = gvaspaceCopyServerReservedPdes_IMPL(local_28,local_20[0],param_2);
    return uVar1;
  }
  return uVar1;
}


// ===== 004561a0 gvaspaceReleasePageTableEntries_IMPL =====

ulong gvaspaceReleasePageTableEntries_IMPL
                (undefined8 param_1,undefined8 param_2,long param_3,long param_4,ulong param_5)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  lVar1 = gvaspaceGetGpuState_IMPL();
  if (lVar1 == 0) {
    nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x12a0);
  }
  else {
    plVar2 = (long *)listHead_IMPL(lVar1 + 0x38);
    while (plVar2 != (long *)0x0) {
      if ((*plVar2 == param_3) && (plVar2[1] == param_4)) {
        listRemove_IMPL(lVar1 + 0x38);
        plVar2 = (long *)gvaspaceGetGpuState_IMPL(param_1,param_2);
        if (plVar2 == (long *)0x0) {
          nvAssertFailedNoLog("NULL != pGpuState","src/kernel/mem_mgr/gpu_vaspace.c",0x12f1);
        }
        if (param_5 == 0) {
          return 0;
        }
        lVar1 = 0;
        do {
          if ((param_5 & 1) != 0) {
            uVar3 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*plVar2 + 8),lVar1);
            uVar4 = _gvaspaceReleaseUnreservedPTEs(param_1,param_2,param_3,param_4,uVar3);
            if ((int)uVar4 != 0) {
              nvAssertOkFailedNoLog
                        (uVar4 & 0xffffffff,
                         "_gvaspaceReleaseUnreservedPTEs(pGVAS, pGpu, vaLo, vaHi, pLevelFmt)",
                         "src/kernel/mem_mgr/gpu_vaspace.c",0x12fb);
              return uVar4 & 0xffffffff;
            }
            if (param_5 >> 1 == 0) {
              return uVar4;
            }
          }
          param_5 = param_5 >> 1;
          lVar1 = lVar1 + 1;
        } while( true );
      }
      plVar2 = (long *)listNext_IMPL();
    }
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x12af,"gvaspaceReleasePageTableEntries_IMPL",4,
                 "NVRM: Cannot find the reserved PTE to release.\n");
  }
  return 0xffff;
}


// ===== 00456360 vaspaceapiCtrlCmdVaspaceReleaseEntries_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong vaspaceapiCtrlCmdVaspaceReleaseEntries_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  long *local_28;
  long local_20 [2];
  
  local_28 = (long *)0x0;
  local_20[0] = 0;
  uVar4 = _gvaspaceControl_Prolog_constprop_0(param_1,*param_2,param_2[1],&local_28,local_20);
  lVar3 = local_20[0];
  plVar2 = local_28;
  if (uVar4 != 0) {
    nvAssertOkFailedNoLog
              (uVar4,
               "_gvaspaceControl_Prolog(pVaspaceApi, pReleaseEntriesParams->hSubDevice, pReleaseEntriesParams->subDeviceId, &pGVAS, &pGpu)"
               ,"src/kernel/mem_mgr/gpu_vaspace.c",0x1037);
    return (ulong)uVar4;
  }
  if (local_28[0x22] == 0) {
    uVar5 = 0x56;
  }
  else {
    uVar5 = *(ulong *)(param_2 + 2);
    if ((uVar5 == 0) || ((uVar5 - 1 & uVar5) != 0)) {
      nvAssertFailedNoLog("ONEBITSET(pReleaseEntriesParams->pageSize)",
                          "src/kernel/mem_mgr/gpu_vaspace.c",0x1041);
      return 0x1f;
    }
    if ((*(char *)(local_20[0] + 0x908) != '\0') && (*(char *)(local_20[0] + 0x4922) == '\0')) {
      uVar5 = (**(code **)(*local_28 + 0x178))();
      if ((uVar5 & 0x1000000) == 0) {
        lVar6 = resservGetTlsCallContext();
        puVar1 = *(undefined4 **)(*(long *)(lVar6 + 0x48) + 0x70);
        lVar6 = gpuGetRpc(lVar3);
        if (lVar6 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/gpu_vaspace.c",0x104a);
          return 0x1a;
        }
        if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
          uVar5 = rpcDmaControl_wrapper
                            (lVar3,lVar6,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                             puVar1[6]);
          return uVar5;
        }
        uVar5 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58);
        return uVar5;
      }
      uVar5 = *(ulong *)(param_2 + 2);
    }
    uVar5 = gvaspaceReleasePageTableEntries_IMPL
                      (plVar2,lVar3,*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6),uVar5)
    ;
    if ((int)uVar5 != 0) {
      nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/gpu_vaspace.c",0x1059);
      uVar5 = uVar5 & 0xffffffff;
    }
  }
  return uVar5;
}


// ===== 00456550 gvaspaceReserveMempool_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gvaspaceReserveMempool_IMPL
                (long *param_1,long param_2,undefined8 param_3,long param_4,ulong param_5,
                uint param_6)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  
  uVar2 = *(undefined8 *)(param_2 + 0x1b98);
  uVar1 = *(uint *)(param_1 + 0x17);
  uVar4 = kgmmuFmtGet_IMPL(uVar2,0,0);
  if ((((*(byte *)((long)param_1 + 0xb9) & 0x40) == 0) ||
      (lVar5 = gvaspaceGetGpuState_IMPL(param_1,param_2), lVar5 == 0)) ||
     (*(long *)(lVar5 + 0x30) == 0)) {
    return 0;
  }
  if (param_5 == 0) {
LAB_004566a0:
    nvAssertFailedNoLog("((pageSizeLockMask & RM_PAGE_SIZE) != 0)",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0x13f0);
    uVar8 = 0x1f;
  }
  else {
    if ((param_5 - 1 & param_5) == 0) {
      cVar3 = (**(code **)(*param_1 + 400))(param_1);
      if (cVar3 == '\0') {
        if ((param_6 & 1) == 0) {
          param_5 = 0x1000;
        }
      }
      else {
        param_5 = param_1[0x14] | 0x1000;
      }
    }
    else if ((param_5 & 0x1000) == 0) goto LAB_004566a0;
    lVar6 = kgmmuGetSizeOfPageDirs_IMPL(param_2,uVar2,uVar4,0,param_4 + -1,param_5);
    lVar7 = kgmmuGetSizeOfPageTables_IMPL(param_2,uVar2,uVar4,0,param_4 + -1,param_5);
    uVar8 = rmMemPoolReserve(*(undefined8 *)(lVar5 + 0x30),lVar6 + lVar7,(int)param_1[0x17]);
    if ((uVar1 & 0x20) != 0) {
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 == 0x51) {
        uVar9 = 0;
      }
      return uVar9;
    }
  }
  return uVar8;
}


// ===== 004566e0 gvaspaceIsInUse_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool gvaspaceIsInUse_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_20;
  
  local_20 = 0;
  iVar1 = (**(code **)(*(long *)(param_1 + 0x98) + 0x30))(*(long *)(param_1 + 0x98),&local_20);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("gvaspaceGetFreeHeap(pGVAS, &freeSize) == NV_OK",
                        "src/kernel/mem_mgr/gpu_vaspace.c",0x141f);
  }
  lVar2 = (**(code **)(**(long **)(param_1 + 0x88) + 0x60))();
  lVar3 = (**(code **)(**(long **)(param_1 + 0x88) + 0x58))();
  return (lVar2 + 1) - lVar3 != local_20;
}


// ===== 00456772 gvaspaceAlloc_IMPL.cold =====

void gvaspaceAlloc_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00456780 gvaspaceAlloc_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gvaspaceAlloc_IMPL(long *param_1,ulong param_2,undefined8 param_3,ulong param_4,ulong param_5,
                      long param_6,ushort param_7,long *param_8)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  code *pcVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  undefined8 uVar13;
  long lVar14;
  uint uVar15;
  ulong uVar16;
  int iVar17;
  ulong local_80;
  uint local_74;
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_80 = param_2;
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar14 = param_1[0x11];
  uVar7 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(lVar14 + 0x48));
  lVar10 = gpumgrGetGpu(uVar7);
  local_74 = 0;
  if (*(char *)((long)param_1 + 0xf5) != '\0') {
    nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x504,"gvaspaceAlloc_IMPL",4,
                 "NVRM: Cannot reserve VA on an externally owned VASPACE\n");
    return 0x56;
  }
  lVar1 = param_1[0x13];
  uVar2 = *(ulong *)(lVar1 + 0x80);
  uVar3 = *(ulong *)(lVar1 + 0x88);
  if ((*(long *)(*(long *)(&DAT_00001b90 + lVar10) + 0xa820) == lVar14) &&
     (*(long *)(lVar10 + 0x4a18) != 0)) {
    lVar10 = __nvoc_dynamicCast(*(long *)(lVar10 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
    uVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar10 + 0x98),__nvoc_class_def_OBJGVASPACE);
    cVar6 = gvaspaceIsInUse_IMPL(uVar13);
    if (cVar6 != '\0') {
      nvDbg_Printf("src/kernel/mem_mgr/gpu_vaspace.c",0x514,"gvaspaceAlloc_IMPL",4,
                   "NVRM: FabricVAS and FlaVAS cannot be used simultaneously! FlaVAS Alloc failed\n"
                  );
      return 0x38;
    }
  }
  if (param_4 <= uVar2) {
    param_4 = uVar2;
  }
  if (uVar3 <= param_5) {
    param_5 = uVar3;
  }
  if ((char)param_1[0x29] == '\0') goto LAB_00456855;
  uVar16 = param_1[0x27];
  if ((param_7 & 0x20) == 0) {
    param_5 = param_1[0x28];
    uVar11 = (param_5 + 1) - uVar16;
LAB_00456860:
    param_4 = uVar16;
    if (uVar11 < local_80) {
      nvCheckFailedNoLog(2,"size <= (rangeHi - rangeLo + 1)","src/kernel/mem_mgr/gpu_vaspace.c",
                         0x54f);
      return 0x1f;
    }
  }
  else {
    if ((param_7 & 0x40) != 0) {
      if (((uVar16 <= param_4) && (param_4 <= (ulong)param_1[0x28])) ||
         ((param_5 <= (ulong)param_1[0x28] && (uVar16 <= param_5)))) {
        return 0x3b;
      }
LAB_00456855:
      uVar11 = (param_5 + 1) - param_4;
      uVar16 = param_4;
      goto LAB_00456860;
    }
    if ((param_5 < uVar16) || (uVar11 = param_1[0x28], uVar11 < param_4)) goto LAB_00456855;
    if ((uVar11 < param_5) && (local_80 <= param_5 - uVar11)) {
      uVar16 = uVar11 + 1;
      uVar11 = param_5 - uVar11;
      goto LAB_00456860;
    }
    if ((uVar16 <= param_4) || (param_5 = uVar16 - 1, uVar16 - param_4 < local_80)) {
      return 0x1a;
    }
  }
  if (param_4 < uVar2) {
    nvAssertFailedNoLog("origRangeLo <= rangeLo","src/kernel/mem_mgr/gpu_vaspace.c",0x552);
  }
  else if (param_5 < param_4) {
    nvAssertFailedNoLog("rangeLo <= rangeHi","src/kernel/mem_mgr/gpu_vaspace.c",0x553);
  }
  else {
    if (param_5 <= uVar3) {
      iVar8 = (**(code **)(lVar1 + 0x48))(lVar1);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,"pHeap->eheapSetAllocRange(pHeap, rangeLo, rangeHi)",
                   "src/kernel/mem_mgr/gpu_vaspace.c",0x555);
        return iVar8;
      }
      if (((param_7 & 1) != 0) || ((*(byte *)((long)param_1 + 0xbb) & 0x10) != 0)) {
        local_74 = local_74 | 4;
      }
      if ((char)param_7 < '\0') {
        local_74 = local_74 | 0x10;
      }
      iVar8 = 0x51;
      iVar17 = (**(code **)(lVar1 + 8))
                         (lVar1,0x6e76726d,&local_74,param_8,&local_80,param_3,1,&local_70,0,0);
      if (iVar17 == 0) {
        lVar10 = local_70[0x10];
        *(ushort *)(lVar10 + 0x10) = param_7;
        *(long *)(lVar10 + 8) = param_6;
        if ((param_7 & 4) != 0) {
          *(undefined4 *)(lVar10 + 0x14) = 1;
        }
        if (((param_7 & 0x10) == 0) && ((*(uint *)(param_1 + 0x17) & 0x80) == 0)) {
          iVar8 = 0;
          if ((((param_7 & 0xc) == 0) && (param_6 != 0)) &&
             (uVar15 = *(uint *)(lVar14 + 0x48), uVar15 != 0)) {
            iVar17 = 0;
LAB_00456c10:
            for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
              iVar17 = iVar17 + 1;
            }
            lVar12 = gpumgrGetGpu(iVar17);
            if (lVar12 == 0) {
              nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x5b9);
            }
            else {
              local_68 = 0;
              local_60 = 0;
              local_58 = (long *)0x0;
              local_50 = 0;
              local_48 = 0;
              local_40 = 0;
              iVar8 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar12,lVar10,&local_68);
              if (iVar8 != 0) {
                nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x5bf);
LAB_00457049:
                uVar15 = *(uint *)(lVar14 + 0x48);
                if (uVar15 == 0) goto LAB_00456ab5;
                iVar17 = 0;
                goto LAB_00457070;
              }
              uVar16 = *(ulong *)(lVar10 + 8);
              if (uVar16 != 0) {
                lVar12 = 0;
                do {
                  if ((uVar16 & 1) != 0) {
                    uVar13 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*local_58 + 8),lVar12);
                    iVar8 = mmuWalkReserveEntries
                                      (local_58[1],uVar13,*param_8,*param_8 + -1 + local_80,1);
                    if (iVar8 != 0) {
                      gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
                      goto LAB_00457049;
                    }
                    if (uVar16 >> 1 == 0) break;
                  }
                  uVar16 = uVar16 >> 1;
                  lVar12 = lVar12 + 1;
                } while( true );
              }
              gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
            }
            uVar15 = uVar15 >> 1;
            if (uVar15 != 0) {
              iVar17 = iVar17 + 1;
              goto LAB_00456c10;
            }
            iVar8 = 0;
          }
        }
        else {
          uVar15 = *(uint *)(lVar14 + 0x48);
          iVar8 = 0;
          if (uVar15 != 0) {
            iVar17 = 0;
            while( true ) {
              for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
                iVar17 = iVar17 + 1;
              }
              lVar12 = gpumgrGetGpu(iVar17);
              if (lVar12 != 0) break;
              nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x57d);
LAB_00456a4b:
              uVar15 = uVar15 >> 1;
              iVar8 = 0;
              if (uVar15 == 0) goto LAB_00456ab5;
              iVar17 = iVar17 + 1;
            }
            lVar4 = *(long *)(&DAT_00001b90 + lVar12);
            local_68 = 0;
            local_60 = 0;
            local_58 = (long *)0x0;
            local_50 = 0;
            local_48 = 0;
            local_40 = 0;
            iVar8 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar12,lVar10,&local_68);
            if (iVar8 == 0) {
              iVar8 = mmuWalkSparsify(local_58[1],*param_8,*param_8 + -1 + local_80,0);
              gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
              if (iVar8 == 0) {
                (**(code **)(lVar4 + 0x500))(lVar12,lVar4,3);
                (**(code **)(*param_1 + 0x1b8))(param_1,lVar12,0);
                goto LAB_00456a4b;
              }
            }
            else {
              nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x584);
            }
            uVar15 = *(uint *)(lVar14 + 0x48);
            iVar17 = 0;
            if (uVar15 != 0) {
              while( true ) {
                for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
                  iVar17 = iVar17 + 1;
                }
                lVar14 = gpumgrGetGpu(iVar17);
                if (lVar14 == 0) {
                  nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x59a);
                }
                else {
                  lVar12 = *(long *)(&DAT_00001b90 + lVar14);
                  local_68 = 0;
                  local_60 = 0;
                  local_58 = (long *)0x0;
                  local_50 = 0;
                  local_48 = 0;
                  local_40 = 0;
                  iVar9 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar14,lVar10,&local_68);
                  if (iVar9 == 0) {
                    mmuWalkUnmap(local_58[1],*local_70,local_70[1]);
                    gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
                  }
                  else {
                    nvAssertFailedNoLog("acquireStatus == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",
                                        0x5a1);
                  }
                  (**(code **)(lVar12 + 0x500))(lVar14,lVar12,3);
                  (**(code **)(*param_1 + 0x1b8))(param_1,lVar14,0);
                }
                uVar15 = uVar15 >> 1;
                if (uVar15 == 0) break;
                iVar17 = iVar17 + 1;
              }
            }
          }
        }
      }
LAB_00456ab5:
      (**(code **)(lVar1 + 0x48))(lVar1,uVar2,uVar3);
      return iVar8;
    }
    nvAssertFailedNoLog("rangeHi <= origRangeHi","src/kernel/mem_mgr/gpu_vaspace.c",0x554);
  }
  return 0x1f;
LAB_00457070:
  for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1) {
    iVar17 = iVar17 + 1;
  }
  lVar14 = gpumgrGetGpu(iVar17);
  if (lVar14 == 0) {
    nvAssertFailedNoLog(&DAT_00d7ef7b,"src/kernel/mem_mgr/gpu_vaspace.c",0x5dc);
  }
  else {
    local_68 = 0;
    local_60 = 0;
    local_58 = (long *)0x0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    iVar9 = gvaspaceWalkUserCtxAcquire_IMPL(param_1,lVar14,lVar10,&local_68);
    if (iVar9 == 0) {
      uVar16 = *(ulong *)(lVar10 + 8);
      if (uVar16 != 0) {
        lVar14 = 0;
        do {
          if ((uVar16 & 1) != 0) {
            uVar13 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(*local_58 + 8),lVar14);
            mmuWalkReleaseEntries(local_58[1],uVar13,*local_70,local_70[1]);
            if (uVar16 >> 1 == 0) break;
          }
          uVar16 = uVar16 >> 1;
          lVar14 = lVar14 + 1;
        } while( true );
      }
      gvaspaceWalkUserCtxRelease_IMPL(param_1,&local_68);
    }
    else {
      nvAssertFailedNoLog("acquireStatus == NV_OK","src/kernel/mem_mgr/gpu_vaspace.c",0x5e1);
    }
  }
  uVar15 = uVar15 >> 1;
  if (uVar15 != 0) {
    iVar17 = iVar17 + 1;
    goto LAB_00457070;
  }
  goto LAB_00456ab5;
}


// ===== 004571d0 gvaspaceFreeV2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gvaspaceFreeV2_IMPL(long param_1,undefined8 param_2,long *param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)(**(code **)(*(long *)(param_1 + 0x98) + 0x40))
                             (*(long *)(param_1 + 0x98),param_2,0);
  if (plVar1 != (long *)0x0) {
    *param_3 = (plVar1[1] + 1) - *plVar1;
    uVar2 = _gvaspaceInternalFree_isra_0(param_1);
    return uVar2;
  }
  nvAssertFailedNoLog("NULL != pMemBlock","src/kernel/mem_mgr/gpu_vaspace.c",0x1431);
  return 0x1f;
}


// ===== 0045723a hwresConstruct_IMPL.cold =====

void hwresConstruct_IMPL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00457260 hwresConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int hwresConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  code *pcVar12;
  char cVar13;
  int iVar14;
  undefined4 uVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  long lVar20;
  uint uVar21;
  undefined8 uVar22;
  undefined8 *puVar23;
  long lVar24;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined4 local_94 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  
  local_78 = (undefined4 *)0x0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)invalidInstructionException();
    (*pcVar12)();
  }
  lVar7 = *(long *)(param_1 + 0x210);
  lVar8 = *(long *)(lVar7 + 0xf0);
  lVar9 = *(long *)(lVar8 + 0x1b78);
  uVar10 = *(undefined8 *)(lVar9 + 0x478);
  if (*(long *)(lVar7 + 0xe0) == 0) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)invalidInstructionException();
    (*pcVar12)();
  }
  uVar15 = *(undefined4 *)(*(long *)(*(long *)(*(long *)(lVar7 + 0xe0) + 0x110) + 0x48) + 0x10);
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  lVar16 = kmemsysGetStaticConfig_IMPL(lVar8,*(undefined8 *)(lVar8 + 0x1b70));
  if (*(long *)(param_3 + 0x58) != 0) {
    return 0;
  }
  puVar11 = *(undefined4 **)(param_3 + 0x40);
  cVar13 = (**(code **)(lVar8 + 0x2d8))(lVar8);
  if (cVar13 != '\0') {
    return 3;
  }
  local_68 = *(undefined8 *)(puVar11 + 0xc);
  local_70 = local_70 & 0xffffffff;
  local_60 = *(undefined8 *)(puVar11 + 0xe);
  if (0x11 < (uint)puVar11[2]) {
    *(undefined8 *)(puVar11 + 3) = 0;
    return 0xffff;
  }
  uVar2 = puVar11[3];
  lVar24 = *(long *)(lVar8 + 0x1b78);
  local_78 = puVar11;
  lVar17 = portMemAllocNonPaged(0xc0);
  if (lVar17 == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/hw_resources.c",0x45,"_hwresHwAlloc",4,
                 "NVRM: No memory for Resource %p\n",local_60);
    portMemFree(0);
    portMemFree(0);
    *(undefined8 *)(puVar11 + 3) = 0;
    return 0xffff;
  }
  lVar18 = portMemAllocNonPaged(0x14);
  if (lVar18 == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/hw_resources.c",0x4d,"_hwresHwAlloc",4,
                 "NVRM: No memory for Resource %p\n",local_60);
    portMemFree(0);
    portMemFree(lVar17);
    *(undefined8 *)(puVar11 + 3) = 0;
    return 0xffff;
  }
  portMemSet(lVar17,0,0xc0);
  portMemSet(lVar18,0,0x14);
  *(long *)(lVar17 + 0x90) = lVar18;
  *(undefined4 *)(lVar18 + 0x10) = puVar11[2];
  *(undefined4 *)(lVar17 + 4) = 0;
  *(undefined8 *)(lVar17 + 0x30) = 0;
  *(undefined4 *)(lVar17 + 8) = puVar11[5];
  *(undefined4 *)(lVar17 + 0xc) = puVar11[6];
  *(undefined4 *)(lVar17 + 0x10) = puVar11[7];
  uVar22 = *(undefined8 *)(puVar11 + 0x12);
  *(undefined8 *)(lVar17 + 0x18) = uVar22;
  *(undefined8 *)(lVar17 + 0x78) = uVar22;
  *(undefined4 *)(*(long *)(lVar17 + 0x90) + 0xc) = puVar11[0xb];
  uVar22 = (**(code **)(lVar24 + 0x240))(lVar8);
  *(undefined8 *)(lVar17 + 0x38) = uVar22;
  *(ulong *)(lVar17 + 0x98) = CONCAT44(uVar15,uVar1);
  *(undefined4 *)(*(long *)(lVar17 + 0x90) + 8) = puVar11[1];
  **(undefined4 **)(lVar17 + 0x90) = puVar11[3];
  *(undefined4 *)(*(long *)(lVar17 + 0x90) + 4) = puVar11[4];
  *(undefined4 *)(lVar17 + 0x44) = puVar11[3];
  *(undefined4 *)(lVar17 + 0x48) = puVar11[4];
  uVar15 = puVar11[9];
  *(undefined4 *)(lVar17 + 0x54) = 0;
  *(undefined4 *)(lVar17 + 0x50) = uVar15;
  uVar19 = 0x1000;
  *(undefined4 *)(lVar17 + 0x40) = 0;
  if ((*(ushort *)(puVar11 + 1) & 0x180) != 0) {
    uVar19 = (ulong)(uint)puVar11[8];
  }
  *(ulong *)(lVar17 + 0x20) = uVar19;
  lVar20 = (**(code **)(lVar24 + 0x168))
                     (lVar24,*(undefined4 *)(lVar17 + 0x98),*(undefined8 *)(lVar17 + 0x18),
                      *(undefined4 *)(lVar17 + 0x4c),*(undefined4 *)(*(long *)(lVar17 + 0x90) + 8),
                      lVar17 + 0x44,lVar17 + 0x48);
  if (lVar20 == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/hw_resources.c",0x78,"_hwresHwAlloc",4,
                 "NVRM: memmgrDeterminePageSize failed\n");
  }
  iVar14 = (**(code **)(lVar24 + 0x1f8))
                     (lVar8,lVar24,lVar17 + 0x18,lVar17 + 0x20,*(undefined8 *)(lVar17 + 0x28),
                      *(undefined4 *)(*(long *)(lVar17 + 0x90) + 8),*(undefined4 *)(lVar17 + 0x44),
                      *(undefined4 *)(lVar17 + 0x48),0);
  if (iVar14 == 0) {
    if (*(char *)(lVar8 + 0x908) == '\0') goto LAB_004575ae;
    lVar20 = gpuGetStaticInfo(lVar8);
    if (((lVar20 == 0) || (*(char *)(lVar20 + 0x1f100) == '\0')) ||
       ((*(byte *)(*(long *)(lVar17 + 0x90) + 1) & 0x30) != 0)) {
      local_40 = CONCAT71(local_40._1_7_,1);
      iVar14 = 0;
    }
    else {
      iVar14 = memmgrAllocHwResources_IMPL(lVar8,lVar24,lVar17);
      local_40 = local_40 & 0xffffffffffffff00;
      if (iVar14 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/hw_resources.c",0x92);
      }
    }
    puVar11[0x1c] = *(undefined4 *)(lVar17 + 0x58);
    puVar11[0x16] = *(undefined4 *)(lVar17 + 0x5c);
    puVar11[0x17] = *(undefined4 *)(lVar17 + 0x60);
    puVar11[0x18] = *(undefined4 *)(lVar17 + 100);
    puVar11[0x19] = *(undefined4 *)(lVar17 + 0x68);
    puVar11[0x1a] = *(undefined4 *)(lVar17 + 0x6c);
    puVar11[0x1b] = *(undefined4 *)(lVar17 + 0x70);
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/hw_resources.c",0x81,"_hwresHwAlloc",4,
                 "NVRM: memmgrAllocDetermineAlignment failed\n");
LAB_004575ae:
    iVar14 = memmgrAllocHwResources_IMPL(lVar8,lVar24,lVar17);
  }
  iVar3 = puVar11[3];
  if (iVar14 != 0) {
    nvDbg_Printf("src/kernel/mem_mgr/hw_resources.c",0xbc,"_hwresHwAlloc",4,
                 "NVRM: nvHalFbAlloc failure status = 0x%x Requested Attr 0x%x!\n",iVar14,iVar3);
    portMemFree(lVar18);
    portMemFree(lVar17);
    *(undefined8 *)(puVar11 + 3) = 0;
    return iVar14;
  }
  if ((iVar3 == 0) || (*(int *)(lVar17 + 0x44) != 0)) {
    puVar11[7] = *(undefined4 *)(lVar17 + 0x10);
    puVar11[5] = *(undefined4 *)(lVar17 + 8);
    uVar22 = *(undefined8 *)(lVar17 + 0x30);
    puVar11[0xb] = *(undefined4 *)(*(long *)(lVar17 + 0x90) + 0xc);
    local_70 = CONCAT44(*(undefined4 *)(lVar17 + 4),(int)uVar22);
    *(undefined8 *)(puVar11 + 0x12) = *(undefined8 *)(lVar17 + 0x18);
    uVar15 = *(undefined4 *)(lVar17 + 0x44);
    uVar21 = *(uint *)(lVar17 + 0x48);
    local_50 = CONCAT44(*(undefined4 *)(lVar17 + 0xa4),*(undefined4 *)(lVar17 + 0x50));
    local_58 = *(undefined8 *)(lVar17 + 0x44);
    local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)(lVar17 + 4));
    portMemFree(lVar18);
    portMemFree(lVar17);
    puVar11[3] = uVar15;
    puVar11[4] = uVar21;
    if ((uVar21 & 0xc) != 0) goto LAB_004576fe;
    uVar21 = uVar21 | 8;
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/hw_resources.c",0xc2,"_hwresHwAlloc",3,
                 "NVRM: nvHalFbAlloc Out of Resources Requested=%x Returned=%x !\n",iVar3,0);
    portMemFree(lVar18);
    portMemFree(lVar17);
    puVar11[3] = 0;
    uVar21 = 8;
    uVar15 = 0;
  }
  puVar11[4] = uVar21;
LAB_004576fe:
  lVar24 = (local_70 & 0xffffffff) + *(long *)(puVar11 + 0x12);
  uVar22 = (**(code **)(lVar9 + 0x240))(lVar8,lVar9);
  if ((uVar2 & 0x6000000) == 0) {
    iVar14 = memCreateMemDesc_IMPL(lVar8,&local_a0,2,uVar22,lVar24,uVar15,uVar21);
    if (iVar14 != 0) {
      return iVar14;
    }
    uVar4 = puVar11[2];
    uVar5 = puVar11[4];
    uVar22 = 0x40;
    uVar6 = puVar11[3];
    uVar1 = *puVar11;
    uVar15 = puVar11[1];
  }
  else {
    iVar14 = memCreateMemDesc_IMPL(lVar8,&local_a0,1,uVar22,lVar24,uVar15,uVar21);
    if (iVar14 != 0) {
      return iVar14;
    }
    uVar4 = puVar11[2];
    uVar5 = puVar11[4];
    uVar22 = 0x3e;
    uVar6 = puVar11[3];
    uVar1 = *puVar11;
    uVar15 = puVar11[1];
  }
  iVar14 = memConstructCommon_IMPL
                     (lVar7,uVar22,uVar15,local_a0,uVar1,uVar10,uVar6,uVar5,0,uVar4,0,&local_58);
  if (iVar14 == 0) {
    puVar23 = *(undefined8 **)(lVar7 + 0x118);
    if (puVar23 == (undefined8 *)0x0) {
      nvAssertFailedNoLog("pMemory->pMemDesc","src/kernel/mem_mgr/hw_resources.c",0x13f);
      puVar23 = *(undefined8 **)(lVar7 + 0x118);
    }
    memdescSetPteKindForGpu(puVar23,*puVar23,puVar11[0xb]);
    *(undefined4 *)(*(long *)(lVar7 + 0x118) + 0x98) = local_70._4_4_;
    *(undefined8 *)(lVar7 + 0x1a0) = *(undefined8 *)(puVar11 + 0x10);
    if (*(char *)(lVar8 + 0x908) != '\0') {
      lVar24 = gpuGetStaticInfo(lVar8);
      if ((lVar24 != 0) && (*(char *)(lVar24 + 0x1f100) != '\0')) {
        *(ulong *)(puVar11 + 0x16) = CONCAT44(puVar11[0xb],*(undefined4 *)(lVar16 + 0x18));
        cVar13 = (**(code **)(lVar9 + 0x2a8))(lVar9,5);
        if (cVar13 == '\0') {
          puVar11[0x1c] = puVar11[0xb];
        }
        else {
          uVar15 = (**(code **)(lVar9 + 0x290))(lVar8,lVar9,puVar11[0xb],0);
          puVar11[0x1c] = uVar15;
        }
      }
      if (*(char *)(lVar8 + 0x908) != '\0') {
        return 0;
      }
    }
    if (*(char *)(lVar8 + 0x909) != '\0') {
      return 0;
    }
    iVar14 = memmgrGetKindComprForGpu_KERNEL
                       (lVar9,*(undefined8 **)(lVar7 + 0x118),**(undefined8 **)(lVar7 + 0x118),0,
                        &local_a4,local_94);
    if (iVar14 == 0) {
      uVar15 = *(undefined4 *)(lVar16 + 0x18);
      *(ulong *)(puVar11 + 0x18) = CONCAT44(local_88,local_80);
      *(ulong *)(puVar11 + 0x1a) = CONCAT44(local_7c,local_84);
      *(ulong *)(puVar11 + 0x16) = CONCAT44(local_94[0],uVar15);
      cVar13 = (**(code **)(lVar9 + 0x2a8))(lVar9,5,local_a4);
      if (cVar13 != '\0') {
        local_a4 = (**(code **)(lVar9 + 0x290))(lVar8,lVar9,local_a4,0);
      }
      puVar11[0x1c] = local_a4;
      return 0;
    }
  }
  memdescDestroy(local_a0);
  return iVar14;
}


// ===== 00457c5e hwresDestruct_IMPL.cold =====

void hwresDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00457c70 hwresDestruct_IMPL =====

void hwresDestruct_IMPL(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x210) + 0x118);
    memDestructCommon_IMPL();
    if (*(char *)(lVar1 + 100) != '\0') {
      nvAssertFailedNoLog("pMemDesc->Allocated == 0","src/kernel/mem_mgr/hw_resources.c",0x18c);
    }
    memdescFree(lVar1);
    memdescDestroy(lVar1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 00457ce0 hwresCanCopy_IMPL =====

undefined8 hwresCanCopy_IMPL(void)

{
  return 1;
}


// ===== 00457cf0 _iovaspaceCreateMappingDataFromMemDesc =====

long _iovaspaceCreateMappingDataFromMemDesc(long param_1)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  
  cVar1 = memdescGetContiguity(param_1,0);
  if (cVar1 == '\0') {
    uVar3 = (ulong)((int)*(undefined8 *)(param_1 + 0x18) - 1) * 8 + 0x30;
    if (uVar3 >> 0x20 != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/io_vaspace.c",0xeb,"_iovaspaceCreateMappingDataFromMemDesc",4
                   ,"NVRM: too much memory to map! (0x%llx bytes)\n",uVar3);
      return 0;
    }
  }
  else {
    uVar3 = 0x30;
  }
  lVar2 = portMemAllocNonPaged(uVar3);
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/io_vaspace.c",0xf4,"_iovaspaceCreateMappingDataFromMemDesc",4,
                 "NVRM: failed to allocate 0x%x bytes for IOVA mapping metadata\n",
                 uVar3 & 0xffffffff);
  }
  else {
    portMemSet(lVar2,0,uVar3);
    *(long *)(lVar2 + 8) = param_1;
  }
  return lVar2;
}


// ===== 00457dc0 iovaspaceConstruct__IMPL =====

undefined8 iovaspaceConstruct__IMPL(long param_1,int param_2)

{
  if (param_2 == 0xf2) {
    *(undefined8 *)(param_1 + 0x98) = 0;
    return 0;
  }
  nvAssertFailedNoLog("IO_VASPACE_A == classId","src/kernel/mem_mgr/io_vaspace.c",0x36);
  return 0x1f;
}


// ===== 00457e10 iovaspaceDestruct_IMPL =====

undefined1  [16] iovaspaceDestruct_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  long lVar2;
  undefined1 auVar3 [16];
  undefined8 uStack_10;
  
  lVar2 = 0;
  if (param_1 != 0) {
    lVar2 = *(long *)(param_1 + 0x88);
  }
  if (*(long *)(param_1 + 0x98) == 0) {
    auVar3._8_8_ = param_3;
    auVar3._0_8_ = lVar2;
    return auVar3;
  }
  auVar1._4_4_ = 0;
  auVar1._0_4_ = *(uint *)(lVar2 + 0x5c);
  nvDbg_Printf("src/kernel/mem_mgr/io_vaspace.c",0x42,"iovaspaceDestruct_IMPL",4,
               "NVRM: %lld left-over mappings in IOVAS 0x%x\n");
  auVar1._8_8_ = uStack_10;
  return auVar1;
}


// ===== 00457e70 iovaspaceAlloc_IMPL =====

undefined8 iovaspaceAlloc_IMPL(void)

{
  return 0;
}


// ===== 00457e80 iovaspaceFree_IMPL =====

undefined8 iovaspaceFree_IMPL(void)

{
  return 0;
}


// ===== 00457e87 iovaspaceApplyDefaultAlignment_IMPL.cold =====

void iovaspaceApplyDefaultAlignment_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00457e90 iovaspaceApplyDefaultAlignment_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
iovaspaceApplyDefaultAlignment_IMPL(long param_1,long param_2,ulong *param_3,ulong *param_4)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar2 = dmaNvos32ToPageSizeAttr
                    (**(undefined4 **)(param_2 + 0x90),(*(undefined4 **)(param_2 + 0x90))[1]);
  if (uVar2 < 2) {
    uVar5 = *param_3;
    if (uVar5 < 0x1000) {
      uVar5 = 0x1000;
    }
    *param_3 = uVar5;
    *param_4 = *param_4 + 0xfff & 0xfffffffffffff000;
  }
  else {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    uVar3 = gpumgrGetDefaultPrimaryGpu(*(undefined4 *)(*(long *)(param_1 + 0x88) + 0x48));
    lVar4 = gpumgrGetGpu(uVar3);
    lVar4 = *(long *)(lVar4 + 0x1b98);
    if (lVar4 == 0) {
      nvAssertFailedNoLog("NULL != pKernelGmmu","src/kernel/mem_mgr/io_vaspace.c",0x8e);
      return 0x3d;
    }
    if (uVar2 == 3) {
      uVar6 = 0xffffffffffe00000;
      uVar5 = 0x200000;
      if (*(char *)(lVar4 + 0x67d0) == '\0') {
        nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                            "src/kernel/mem_mgr/io_vaspace.c",0x96);
        return 0x1f;
      }
    }
    else if (uVar2 == 4) {
      uVar6 = 0xffffffffe0000000;
      uVar5 = 0x20000000;
      if (*(char *)(lVar4 + 0x67d1) == '\0') {
        nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                            "src/kernel/mem_mgr/io_vaspace.c",0x9b);
        return 0x1f;
      }
    }
    else if (uVar2 == 2) {
      uVar5 = (**(code **)(lVar4 + 0x198))();
      uVar6 = -uVar5;
    }
    else {
      uVar6 = 0xfffffffffffff000;
      uVar5 = 0x1000;
    }
    uVar7 = *param_3;
    if (*param_3 < uVar5) {
      uVar7 = uVar5;
    }
    *param_3 = uVar7;
    *param_4 = (uVar5 - 1) + *param_4 & uVar6;
  }
  return 0;
}


// ===== 00458030 iovaspaceIncAllocRefCnt_IMPL =====

undefined8 iovaspaceIncAllocRefCnt_IMPL(void)

{
  return 0;
}


// ===== 00458040 iovaspaceGetVasInfo_IMPL =====

undefined8 iovaspaceGetVasInfo_IMPL(void)

{
  return 0;
}


// ===== 00458050 iovaspaceGetVaStart_IMPL =====

undefined8 iovaspaceGetVaStart_IMPL(void)

{
  return 0;
}


// ===== 00458060 iovaspaceGetVaLimit_IMPL =====

undefined8 iovaspaceGetVaLimit_IMPL(void)

{
  return 0xffffffff;
}


// ===== 00458070 iovaspaceReleaseMapping_IMPL =====

void iovaspaceReleaseMapping_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog(&DAT_00d81143,"src/kernel/mem_mgr/io_vaspace.c",0x234);
    return;
  }
  if (*(int *)(param_2 + 4) != 0) {
    iVar1 = *(int *)(param_2 + 4) + -1;
    *(int *)(param_2 + 4) = iVar1;
    if (iVar1 != 0) {
      return;
    }
    iovaspaceDestroyMapping_IMPL();
    return;
  }
  nvAssertFailedNoLog("pIovaMapping->refcount > 0","src/kernel/mem_mgr/io_vaspace.c",0x239);
  iVar1 = *(int *)(param_2 + 4) + -1;
  *(int *)(param_2 + 4) = iVar1;
  if (iVar1 != 0) {
    return;
  }
  iovaspaceDestroyMapping_IMPL(param_1,param_2);
  return;
}


// ===== 00458100 iovaspaceAcquireMapping_IMPL.cold =====

void iovaspaceAcquireMapping_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00458120 iovaspaceAcquireMapping_IMPL =====

int iovaspaceAcquireMapping_IMPL(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar6 = memdescGetIommuMap(param_2,*(undefined4 *)(*(long *)(param_1 + 0x88) + 0x5c));
  if (lVar6 == 0) {
    if (param_2[0x19] == 0) {
      lVar6 = *(long *)(param_1 + 0x88);
      uVar10 = gpumgrGetGpuFromId(*(undefined4 *)(lVar6 + 0x5c));
      iVar5 = memdescGetAddressSpace(param_2);
      if ((iVar5 == 1) || (cVar4 = gpumgrCheckIndirectPeer_IMPL(uVar10,*param_2), cVar4 != '\0')) {
        puVar8 = (undefined4 *)_iovaspaceCreateMappingDataFromMemDesc(param_2);
        if (puVar8 == (undefined4 *)0x0) {
          iVar5 = 0x51;
        }
        else {
          cVar4 = memdescGetContiguity(param_2,0);
          if (cVar4 == '\0') {
            uVar11 = 0;
            if (param_2[3] != 0) {
              do {
                uVar10 = memdescGetPte(param_2,0,uVar11);
                *(undefined8 *)(puVar8 + uVar11 * 2 + 10) = uVar10;
                uVar11 = (ulong)((int)uVar11 + 1);
              } while (uVar11 < (ulong)param_2[3]);
            }
          }
          else {
            uVar10 = memdescGetPte(param_2,0,0);
            *(undefined8 *)(puVar8 + 10) = uVar10;
          }
          uVar1 = *(undefined4 *)(lVar6 + 0x5c);
          puVar8[1] = 1;
          *puVar8 = uVar1;
          iVar5 = osIovaMap(puVar8);
          if (iVar5 == 0) {
            memdescAddIommuMap(param_2,puVar8);
            *(long *)(param_1 + 0x98) = *(long *)(param_1 + 0x98) + 1;
          }
          else {
            nvDbg_Printf("src/kernel/mem_mgr/io_vaspace.c",0x1cb,"_iovaspaceCreateMapping",4,
                         "NVRM: failed to map memdesc into I/O VA space 0x%x (status = 0x%x)\n",
                         *(undefined4 *)(lVar6 + 0x5c),iVar5);
            portMemFree(puVar8);
          }
        }
      }
      else {
        iVar5 = 0x40;
        nvAssertFailedNoLog(&DAT_00d81143,"src/kernel/mem_mgr/io_vaspace.c",0x1ad);
      }
    }
    else {
      lVar6 = *(long *)(param_1 + 0x88);
      puVar7 = (undefined8 *)memdescGetRootMemDesc(param_2,local_40);
      if (param_2 == puVar7) {
        nvAssertFailedNoLog("pRootMemDesc != pPhysMemDesc","src/kernel/mem_mgr/io_vaspace.c",0x10f);
      }
      iVar5 = iovaspaceAcquireMapping_IMPL(param_1,puVar7);
      if (iVar5 == 0) {
        puVar8 = (undefined4 *)memdescGetIommuMap(puVar7,*(undefined4 *)(lVar6 + 0x5c));
        if (puVar8 == (undefined4 *)0x0) {
          nvAssertFailedNoLog("pRootIovaMapping != NULL","src/kernel/mem_mgr/io_vaspace.c",0x11f);
        }
        local_40[0] = local_40[0] - *(uint *)(param_2 + 0xc);
        if ((*(int *)(param_2 + 0x2c) - 1 & local_40[0]) != 0) {
          nvAssertFailedNoLog("(rootOffset & GET_PAGE_MASK(pPhysMemDesc->pageArrayGranularity)) == 0"
                              ,"src/kernel/mem_mgr/io_vaspace.c",0x12a);
        }
        puVar9 = (undefined4 *)_iovaspaceCreateMappingDataFromMemDesc(param_2);
        if (puVar9 == (undefined4 *)0x0) {
          iVar5 = 0x51;
          iovaspaceReleaseMapping_IMPL(param_1,puVar8);
        }
        else {
          puVar9[1] = 1;
          uVar1 = *puVar8;
          *(undefined4 **)(puVar9 + 4) = puVar8;
          *puVar9 = uVar1;
          *(undefined8 *)(puVar9 + 6) = *(undefined8 *)(puVar8 + 4);
          *(undefined4 **)(puVar8 + 4) = puVar9;
          cVar4 = memdescGetContiguity(param_2,0);
          if (cVar4 == '\0') {
            uVar2 = *(uint *)(param_2 + 0x2c);
            uVar11 = local_40[0] >>
                     ((uVar2 & 0xaaaaaaaa) != 0 | (0xffff < uVar2) << 4 |
                      ((uVar2 & 0xff00ff00) != 0) << 3 | ((uVar2 & 0xf0f0f0f0) != 0) << 2 |
                     ((uVar2 & 0xcccccccc) != 0) * '\x02');
            lVar6 = param_2[3];
            if ((ulong)puVar7[3] < uVar11 + lVar6) {
              nvAssertFailedNoLog("((rootOffset >> GET_PAGE_SHIFT(pPhysMemDesc->pageArrayGranularity)) + pPhysMemDesc->PageCount) <= pRootMemDesc->PageCount"
                                  ,"src/kernel/mem_mgr/io_vaspace.c",0x150);
              lVar6 = param_2[3];
              uVar2 = *(uint *)(param_2 + 0x2c);
              uVar11 = local_40[0] >>
                       ((0xffff < uVar2) << 4 | (uVar2 & 0xaaaaaaaa) != 0 |
                        ((uVar2 & 0xff00ff00) != 0) << 3 | ((uVar2 & 0xf0f0f0f0) != 0) << 2 |
                       ((uVar2 & 0xcccccccc) != 0) * '\x02');
            }
            if (lVar6 != 0) {
              uVar12 = 0;
              do {
                if ((ulong)puVar7[3] <= uVar12 + uVar11) break;
                *(undefined8 *)(puVar9 + uVar12 * 2 + 10) =
                     *(undefined8 *)(puVar8 + uVar11 * 2 + uVar12 * 2 + 10);
                uVar12 = uVar12 + 1;
              } while (uVar12 < (ulong)param_2[3]);
            }
          }
          else {
            *(ulong *)(puVar9 + 10) = local_40[0] + *(long *)(puVar8 + 10);
          }
          memdescAddIommuMap(param_2,puVar9);
          *(long *)(param_1 + 0x98) = *(long *)(param_1 + 0x98) + 1;
        }
      }
    }
  }
  else {
    iVar5 = *(int *)(lVar6 + 4);
    if (iVar5 == 0) {
      nvAssertFailedNoLog("pIovaMapping->refcount != 0","src/kernel/mem_mgr/io_vaspace.c",0x1ee);
      iVar5 = *(int *)(lVar6 + 4);
    }
    *(int *)(lVar6 + 4) = iVar5 + 1;
    iVar5 = 0;
  }
  return iVar5;
}


// ===== 00458640 _iovaspaceDestroySubmapping =====

void _iovaspaceDestroySubmapping(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x10);
  lVar2 = *(long *)(lVar1 + 0x10);
  memdescRemoveIommuMap(*(undefined8 *)(param_2 + 8));
  if (param_2 == lVar2) {
    *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(param_2 + 0x18);
  }
  else {
    do {
      lVar3 = lVar2;
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pTmpIovaMapping != NULL","src/kernel/mem_mgr/io_vaspace.c",0x17f);
        goto LAB_004586b9;
      }
      lVar2 = *(long *)(lVar3 + 0x18);
    } while (*(long *)(lVar3 + 0x18) != param_2);
    *(undefined8 *)(lVar3 + 0x18) = *(undefined8 *)(param_2 + 0x18);
  }
LAB_004586b9:
  portMemFree(param_2);
  *(long *)(param_1 + 0x98) = *(long *)(param_1 + 0x98) + -1;
  iovaspaceReleaseMapping_IMPL(param_1,lVar1);
  return;
}


// ===== 004586f0 iovaspaceDestroyMapping_IMPL =====

void iovaspaceDestroyMapping_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 8);
  if (*(long *)(lVar1 + 200) == 0) {
    *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
    lVar3 = *(long *)(param_2 + 0x10);
    while (lVar3 != 0) {
      lVar2 = *(long *)(lVar3 + 0x18);
      _iovaspaceDestroySubmapping(param_1,lVar3);
      lVar3 = lVar2;
    }
    memdescRemoveIommuMap(lVar1,param_2);
    osIovaUnmap(param_2);
    portMemFree(param_2);
    *(long *)(param_1 + 0x98) = *(long *)(param_1 + 0x98) + -1;
    return;
  }
  _iovaspaceDestroySubmapping();
  return;
}


// ===== 00458790 iovaspaceFromId =====

undefined8 iovaspaceFromId(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_10;
  
  iVar1 = vmmGetVaspaceFromId_IMPL(*(undefined8 *)(g_pSys + 0x230),param_1,0xf2,&local_10);
  if (iVar1 == 0) {
    uVar2 = __nvoc_dynamicCast(local_10,__nvoc_class_def_OBJIOVASPACE);
    return uVar2;
  }
  return 0;
}


// ===== 004587e0 iovaspaceFromMapping =====

long iovaspaceFromMapping(undefined4 *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 local_10;
  
  iVar1 = vmmGetVaspaceFromId_IMPL(*(undefined8 *)(g_pSys + 0x230),*param_1,0xf2,&local_10);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(local_10,__nvoc_class_def_OBJIOVASPACE);
    if (lVar2 != 0) {
      return lVar2;
    }
  }
  nvAssertFailedNoLog("pIOVAS != NULL","src/kernel/mem_mgr/io_vaspace.c",0x256);
  return 0;
}


// ===== 00458850 iovaMappingDestroy =====

void iovaMappingDestroy(undefined4 *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 local_20 [2];
  
  iVar1 = vmmGetVaspaceFromId_IMPL(*(undefined8 *)(g_pSys + 0x230),*param_1,0xf2,local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(local_20[0],__nvoc_class_def_OBJIOVASPACE);
    if (lVar2 != 0) {
      iovaspaceDestroyMapping_IMPL(lVar2,param_1);
      return;
    }
  }
  nvAssertFailedNoLog("pIOVAS != NULL","src/kernel/mem_mgr/io_vaspace.c",0x256);
  nvAssertFailedNoLog("pIOVAS != NULL","src/kernel/mem_mgr/io_vaspace.c",0x25f);
  return;
}


// ===== 004588f0 memGetMapAddrSpace_IMPL =====

int memGetMapAddrSpace_IMPL(long param_1,undefined8 param_2,undefined4 param_3,int *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  int local_2c [3];
  
  lVar1 = *(long *)(param_1 + 0xf0);
  if (lVar1 == 0) {
    return 0x31;
  }
  uVar4 = memdescGetMemDescFromGpu(*(undefined8 *)(param_1 + 0x118),lVar1);
  iVar3 = rmapiGetEffectiveAddrSpace(lVar1,uVar4,param_3,local_2c);
  if (iVar3 == 0) {
    if (local_2c[0] == 1) {
      cVar2 = memdescGetFlag(uVar4,0x8000000);
      if (cVar2 == '\0') {
        cVar2 = memdescGetFlag(uVar4,0x10000000);
        if (cVar2 != '\0') {
          local_2c[0] = 2;
        }
      }
      else {
        local_2c[0] = 3;
      }
    }
    if (param_4 == (int *)0x0) {
      return 0;
    }
    *param_4 = local_2c[0];
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"rmapiGetEffectiveAddrSpace(pGpu, pMemDesc, mapFlags, &addrSpace)",
               "src/kernel/mem_mgr/mem.c",0x82);
  }
  return iVar3;
}


