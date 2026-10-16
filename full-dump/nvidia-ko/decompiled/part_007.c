// ===== 001400d0 __nvoc_dtor_DispSwObject =====

void __nvoc_dtor_DispSwObject(long param_1)

{
  dispswDestruct_IMPL();
  __nvoc_dtor_ChannelDescendant(param_1 + 8);
  return;
}


// ===== 00140100 __nvoc_objCreate_DispSwObject =====

int __nvoc_objCreate_DispSwObject
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x2c8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_dispsw_nvoc.c",0x29c);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_dispsw_nvoc.c",0x294);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x2c8);
  *(uint *)((long)puVar4 + 0x54) = param_3;
  if (param_2 == 0) {
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_dispsw_nvoc.c",0x2a5);
    iVar2 = 0x1f;
    goto LAB_0014028c;
  }
  if ((param_3 & 1) == 0) {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar4 + 5);
  }
  else {
    puVar4[7] = 0;
    lVar5 = 0;
  }
  lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
  if (lVar3 == 0) {
    lVar3 = objFindAncestor_IMPL(param_2,0x34a6d6);
    uVar6 = 0;
    if (lVar3 != 0) {
      uVar6 = objFindAncestor_IMPL(param_2,0x34a6d6);
    }
    lVar3 = __nvoc_dynamicCast(uVar6,__nvoc_class_def_RmHalspecOwner);
    if (lVar3 != 0) goto LAB_00140194;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_dispsw_nvoc.c",0x2b5);
    iVar2 = 0x1f;
  }
  else {
LAB_00140194:
    puVar1 = puVar4 + 1;
    puVar4[0x3c] = puVar4;
    puVar4[0x34] = puVar4 + 5;
    puVar4[0x35] = puVar4 + 4;
    puVar4[0x36] = puVar4 + 0x11;
    puVar4[0x37] = puVar4 + 3;
    puVar4[0x38] = puVar4 + 2;
    puVar4[0x39] = puVar4 + 0x23;
    puVar4[0x3a] = puVar4 + 0x22;
    puVar4[0x3b] = puVar1;
    __nvoc_init__ChannelDescendant(puVar1);
    puVar4[5] = 0xc42298;
    puVar4[4] = 0xc42280;
    puVar4[0x11] = 0xc42340;
    puVar4[3] = 0xc42268;
    puVar4[2] = 0xc42250;
    puVar4[0x23] = 0xc424e0;
    puVar4[0x22] = 0xc424c8;
    puVar4[1] = 0xc42238;
    *puVar4 = __nvoc_metadata__DispSwObject;
    iVar2 = __nvoc_ctor_ChannelDescendant(puVar1,lVar3,param_4,param_5,0);
    if (iVar2 == 0) {
      iVar2 = dispswConstruct_IMPL(puVar4,param_4,param_5);
      if (iVar2 == 0) {
        *param_1 = (long)puVar4;
        return 0;
      }
      __nvoc_dtor_ChannelDescendant(puVar1);
    }
  }
  if (lVar5 != 0) {
    objRemoveChild_IMPL(lVar5,puVar4 + 5);
  }
LAB_0014028c:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x2c8);
  }
  return iVar2;
}


// ===== 00140450 __nvoc_objCreateDynamic_DispSwObject =====

void __nvoc_objCreateDynamic_DispSwObject
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0014047e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0014047e:
  __nvoc_objCreate_DispSwObject(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001404b0 __nvoc_dtor_OBJENGSTATE =====

void __nvoc_dtor_OBJENGSTATE(long param_1)

{
  engstateDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 001404e0 __nvoc_ctor_OBJENGSTATE =====

void __nvoc_ctor_OBJENGSTATE(long param_1)

{
  __nvoc_ctor_Object(param_1 + 8);
  return;
}


// ===== 001404f0 __nvoc_init__OBJENGSTATE =====

void __nvoc_init__OBJENGSTATE(undefined8 *param_1)

{
  param_1[7] = param_1 + 1;
  param_1[8] = param_1;
  __nvoc_init__Object();
  param_1[1] = 0xc428b8;
  *param_1 = __nvoc_metadata__OBJENGSTATE;
  return;
}


// ===== 00140530 __nvoc_objCreate_OBJENGSTATE =====

int __nvoc_objCreate_OBJENGSTATE(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x148);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_eng_state_nvoc.c",0xb5);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_eng_state_nvoc.c",0xad);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x148);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc428b8;
    *puVar3 = __nvoc_metadata__OBJENGSTATE;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 != 0) goto LAB_0014069f;
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc428b8;
    *puVar3 = __nvoc_metadata__OBJENGSTATE;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 != 0) {
      if (lVar4 != 0) {
        objRemoveChild_IMPL(lVar4,puVar1);
      }
LAB_0014069f:
      if ((param_3 & 2) != 0) {
        portMemSet(puVar3,0,0x148);
        return iVar2;
      }
      portMemFree(puVar3);
      *param_1 = 0;
      return iVar2;
    }
  }
  *param_1 = (long)puVar3;
  return 0;
}


// ===== 00140710 __nvoc_objCreateDynamic_OBJENGSTATE =====

void __nvoc_objCreateDynamic_OBJENGSTATE(void)

{
  __nvoc_objCreate_OBJENGSTATE();
  return;
}


// ===== 00140720 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00140730 __nvoc_up_thunk_RmResource_eventapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf0))(param_1 + 8,param_2,param_3,param_4);
  return;
}


// ===== 00140750 __nvoc_up_thunk_RmResource_eventapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf8))(param_1 + 8);
  return;
}


// ===== 00140770 __nvoc_up_thunk_RmResource_eventapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x100))(param_1 + 8);
  return;
}


// ===== 00140790 __nvoc_up_thunk_RmResource_eventapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x108))(param_1 + 8,param_2);
  return;
}


// ===== 001407b0 __nvoc_up_thunk_RmResource_eventapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x110))(param_1 + 8);
  return;
}


// ===== 001407d0 __nvoc_up_thunk_RmResource_eventapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x118))(param_1 + 8);
  return;
}


// ===== 001407f0 __nvoc_up_thunk_RmResource_eventapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x120))(param_1 + 8);
  return;
}


// ===== 00140810 __nvoc_up_thunk_RmResource_eventapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x128))(param_1 + 8);
  return;
}


// ===== 00140830 __nvoc_up_thunk_RmResource_eventapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x130))(param_1 + 8);
  return;
}


// ===== 00140850 __nvoc_up_thunk_RsResource_eventapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x30))(param_1 + 0x10);
  return;
}


// ===== 00140870 __nvoc_up_thunk_RsResource_eventapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x38))(param_1 + 0x10);
  return;
}


// ===== 00140890 __nvoc_up_thunk_RsResource_eventapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x40))(param_1 + 0x10);
  return;
}


// ===== 001408b0 __nvoc_up_thunk_RsResource_eventapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x48))(param_1 + 0x10);
  return;
}


// ===== 001408d0 __nvoc_up_thunk_RsResource_eventapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x50))(param_1 + 0x10);
  return;
}


// ===== 001408f0 __nvoc_up_thunk_RsResource_eventapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x78))(param_1 + 0x10);
  return;
}


// ===== 00140910 __nvoc_up_thunk_RsResource_eventapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x80))(param_1 + 0x10);
  return;
}


// ===== 00140930 __nvoc_up_thunk_RsResource_eventapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x88))(param_1 + 0x10);
  return;
}


// ===== 00140950 __nvoc_up_thunk_RsResource_eventapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x90))(param_1 + 0x10);
  return;
}


// ===== 00140970 __nvoc_up_thunk_RsResource_eventapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x98))(param_1 + 0x10);
  return;
}


// ===== 00140990 __nvoc_up_thunk_RsResource_eventapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xa0))(param_1 + 0x10);
  return;
}


// ===== 001409b0 __nvoc_up_thunk_RsResource_eventapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x10) + 0xb8))(param_1,param_2 + 0x10);
  return;
}


// ===== 001409d0 __nvoc_down_thunk_Notifier_inotifyGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Notifier_inotifyGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x58))(param_1 + -8);
  return;
}


// ===== 001409f0 __nvoc_down_thunk_Notifier_inotifyGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Notifier_inotifyGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x60))(param_1 + -8);
  return;
}


// ===== 00140a10 __nvoc_down_thunk_Notifier_inotifySetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Notifier_inotifySetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x68))(param_1 + -8);
  return;
}


// ===== 00140a30 __nvoc_down_thunk_Notifier_inotifyUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Notifier_inotifyUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x70))(param_1 + -8);
  return;
}


// ===== 00140a50 __nvoc_down_thunk_Notifier_inotifyGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Notifier_inotifyGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x78))(param_1 + -8);
  return;
}


// ===== 00140a70 __nvoc_dtor_NotifShare =====

void __nvoc_dtor_NotifShare(long param_1)

{
  shrnotifDestruct_IMPL();
  __nvoc_dtor_RsShared(param_1 + 8);
  return;
}


// ===== 00140aa0 __nvoc_dtor_EventApi =====

void __nvoc_dtor_EventApi(long param_1)

{
  eventapiDestruct_IMPL();
  __nvoc_dtor_RmResource(param_1 + 8);
  return;
}


// ===== 00140ad0 __nvoc_dtor_INotifier =====

void __nvoc_dtor_INotifier(void)

{
  inotifyDestruct_IMPL();
  return;
}


// ===== 00140ae0 __nvoc_dtor_Notifier =====

void __nvoc_dtor_Notifier(long param_1)

{
  notifyDestruct_IMPL();
  inotifyDestruct_IMPL(param_1 + 8);
  return;
}


// ===== 00140b10 __nvoc_objCreate_NotifShare =====

int __nvoc_objCreate_NotifShare(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xb0);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_event_api_nvoc.c",0xb3);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_event_api_nvoc.c",0xab);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xb0);
  puVar1 = puVar4 + 1;
  *(uint *)((long)puVar4 + 0x3c) = param_3;
  puVar2 = puVar4 + 2;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[0x10] = puVar2;
    puVar4[4] = 0;
    puVar4[0x11] = puVar1;
    puVar4[0x12] = puVar4;
    __nvoc_init__RsShared(puVar1);
    puVar4[2] = 0xc43290;
    puVar4[1] = 0xc43278;
    *puVar4 = __nvoc_metadata__NotifShare;
    iVar3 = __nvoc_ctor_RsShared(puVar1);
    if (iVar3 == 0) {
      iVar3 = shrnotifConstruct_IMPL(puVar4);
      if (iVar3 == 0) goto LAB_00140be8;
      __nvoc_dtor_RsShared(puVar1);
    }
  }
  else {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar2);
    puVar4[0x11] = puVar1;
    puVar4[0x12] = puVar4;
    puVar4[0x10] = puVar2;
    __nvoc_init__RsShared(puVar1);
    puVar4[2] = 0xc43290;
    puVar4[1] = 0xc43278;
    *puVar4 = __nvoc_metadata__NotifShare;
    iVar3 = __nvoc_ctor_RsShared(puVar1);
    if (iVar3 == 0) {
      iVar3 = shrnotifConstruct_IMPL(puVar4);
      if (iVar3 == 0) {
LAB_00140be8:
        *param_1 = (long)puVar4;
        return 0;
      }
      __nvoc_dtor_RsShared(puVar1);
    }
    if (lVar5 != 0) {
      objRemoveChild_IMPL(lVar5,puVar2);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0xb0);
  }
  return iVar3;
}


// ===== 00140d80 __nvoc_objCreateDynamic_NotifShare =====

void __nvoc_objCreateDynamic_NotifShare(void)

{
  __nvoc_objCreate_NotifShare();
  return;
}


// ===== 00140d90 __nvoc_objCreate_EventApi =====

int __nvoc_objCreate_EventApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xf0);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_event_api_nvoc.c",0x26f);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_event_api_nvoc.c",0x267);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xf0);
  puVar1 = puVar4 + 3;
  *(uint *)((long)puVar4 + 0x44) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[5] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x16] = puVar1;
  puVar4[0x17] = puVar4 + 2;
  puVar4[0x18] = puVar4 + 0xf;
  puVar4[0x19] = puVar2;
  puVar4[0x1a] = puVar4;
  __nvoc_init__RmResource(puVar2);
  puVar4[3] = 0xc42fe8;
  puVar4[2] = 0xc42fd0;
  puVar4[0xf] = 0xc43090;
  puVar4[1] = 0xc42fb8;
  *puVar4 = __nvoc_metadata__EventApi;
  iVar3 = __nvoc_ctor_RmResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = eventapiConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_RmResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0xf0);
  }
  return iVar3;
}


// ===== 00140ff0 __nvoc_objCreateDynamic_EventApi =====

void __nvoc_objCreateDynamic_EventApi
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0014101e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0014101e:
  __nvoc_objCreate_EventApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00141050 __nvoc_ctor_Notifier =====

ulong __nvoc_ctor_Notifier(long param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = inotifyConstruct_IMPL(param_1 + 8);
  if ((int)uVar1 == 0) {
    uVar1 = notifyConstruct_IMPL(param_1,param_2);
    if ((int)uVar1 != 0) {
      inotifyDestruct_IMPL(param_1 + 8);
      return uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 001410b0 __nvoc_init__Notifier =====

void __nvoc_init__Notifier(undefined8 *param_1)

{
  param_1[4] = param_1;
  param_1[3] = param_1 + 1;
  param_1[2] = param_1 + 1;
  param_1[1] = 0xc42dd8;
  *param_1 = __nvoc_metadata__Notifier;
  return;
}


// ===== 001410e0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001410f0 __nvoc_up_thunk_RmResource_eventbufferAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf0))(param_1 + 8,param_2,param_3,param_4);
  return;
}


// ===== 00141110 __nvoc_up_thunk_RmResource_eventbufferShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf8))(param_1 + 8);
  return;
}


// ===== 00141130 __nvoc_up_thunk_RmResource_eventbufferGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x100))(param_1 + 8);
  return;
}


// ===== 00141150 __nvoc_up_thunk_RmResource_eventbufferCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x108))(param_1 + 8,param_2);
  return;
}


// ===== 00141170 __nvoc_up_thunk_RmResource_eventbufferGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x110))(param_1 + 8);
  return;
}


// ===== 00141190 __nvoc_up_thunk_RmResource_eventbufferControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x118))(param_1 + 8);
  return;
}


// ===== 001411b0 __nvoc_up_thunk_RmResource_eventbufferControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x120))(param_1 + 8);
  return;
}


// ===== 001411d0 __nvoc_up_thunk_RmResource_eventbufferControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x128))(param_1 + 8);
  return;
}


// ===== 001411f0 __nvoc_up_thunk_RmResource_eventbufferControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_eventbufferControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x130))(param_1 + 8);
  return;
}


// ===== 00141210 __nvoc_up_thunk_RsResource_eventbufferCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x30))(param_1 + 0x10);
  return;
}


// ===== 00141230 __nvoc_up_thunk_RsResource_eventbufferIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x38))(param_1 + 0x10);
  return;
}


// ===== 00141250 __nvoc_up_thunk_RsResource_eventbufferPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x40))(param_1 + 0x10);
  return;
}


// ===== 00141270 __nvoc_up_thunk_RsResource_eventbufferControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x48))(param_1 + 0x10);
  return;
}


// ===== 00141290 __nvoc_up_thunk_RsResource_eventbufferControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x50))(param_1 + 0x10);
  return;
}


// ===== 001412b0 __nvoc_up_thunk_RsResource_eventbufferMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x78))(param_1 + 0x10);
  return;
}


// ===== 001412d0 __nvoc_up_thunk_RsResource_eventbufferUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x80))(param_1 + 0x10);
  return;
}


// ===== 001412f0 __nvoc_up_thunk_RsResource_eventbufferIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x88))(param_1 + 0x10);
  return;
}


// ===== 00141310 __nvoc_up_thunk_RsResource_eventbufferMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x90))(param_1 + 0x10);
  return;
}


// ===== 00141330 __nvoc_up_thunk_RsResource_eventbufferUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x98))(param_1 + 0x10);
  return;
}


// ===== 00141350 __nvoc_up_thunk_RsResource_eventbufferGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xa0))(param_1 + 0x10);
  return;
}


// ===== 00141370 __nvoc_up_thunk_RsResource_eventbufferAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_eventbufferAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x10) + 0xb8))(param_1,param_2 + 0x10);
  return;
}


// ===== 00141390 __nvoc_dtor_EventBuffer =====

void __nvoc_dtor_EventBuffer(long param_1)

{
  eventbufferDestruct_IMPL();
  __nvoc_dtor_RmResource(param_1 + 8);
  return;
}


// ===== 001413c0 __nvoc_objCreate_EventBuffer =====

int __nvoc_objCreate_EventBuffer
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x1e8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_event_buffer_nvoc.c",0x1d7);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_event_buffer_nvoc.c",0x1cf);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x1e8);
  puVar1 = puVar4 + 3;
  *(uint *)((long)puVar4 + 0x44) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[5] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x16] = puVar1;
  puVar4[0x17] = puVar4 + 2;
  puVar4[0x18] = puVar4 + 0xf;
  puVar4[0x19] = puVar2;
  puVar4[0x1a] = puVar4;
  __nvoc_init__RmResource(puVar2);
  puVar4[3] = 0xc433e8;
  puVar4[2] = 0xc433d0;
  puVar4[0xf] = 0xc43490;
  puVar4[1] = 0xc433b8;
  *puVar4 = __nvoc_metadata__EventBuffer;
  iVar3 = __nvoc_ctor_RmResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = eventbufferConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_RmResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x1e8);
  }
  return iVar3;
}


// ===== 00141620 __nvoc_objCreateDynamic_EventBuffer =====

void __nvoc_objCreateDynamic_EventBuffer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0014164e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0014164e:
  __nvoc_objCreate_EventBuffer(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00141680 __nvoc_dtor_Fabric =====

void __nvoc_dtor_Fabric(long param_1)

{
  fabricDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 001416b0 __nvoc_objCreate_Fabric =====

int __nvoc_objCreate_Fabric(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x158);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_fabric_nvoc.c",0xac);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_fabric_nvoc.c",0xa4);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x158);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc43838;
    *puVar3 = __nvoc_metadata__Fabric;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = fabricConstruct_IMPL(puVar3);
      if (iVar2 == 0) goto LAB_0014176f;
      __nvoc_dtor_Object(puVar1);
    }
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc43838;
    *puVar3 = __nvoc_metadata__Fabric;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = fabricConstruct_IMPL(puVar3);
      if (iVar2 == 0) {
LAB_0014176f:
        *param_1 = (long)puVar3;
        return 0;
      }
      __nvoc_dtor_Object(puVar1);
    }
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar3,0,0x158);
  }
  return iVar2;
}


// ===== 001418d0 __nvoc_objCreateDynamic_Fabric =====

void __nvoc_objCreateDynamic_Fabric(void)

{
  __nvoc_objCreate_Fabric();
  return;
}


// ===== 001418e0 vaspaceGetFlags_edd98b =====

undefined8 vaspaceGetFlags_edd98b(void)

{
  return 0;
}


// ===== 001418f0 vaspaceReserveMempool_ac1694 =====

undefined8 vaspaceReserveMempool_ac1694(void)

{
  return 0;
}


// ===== 00141900 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceConstruct_ =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceConstruct_(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x120))(param_1 + -8);
  return;
}


// ===== 00141920 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceAlloc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceAlloc(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x128))(param_1 + -8);
  return;
}


// ===== 00141940 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceFree(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x130))(param_1 + -8);
  return;
}


// ===== 00141960 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x138))(param_1 + -8);
  return;
}


// ===== 00141980 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x140))(param_1 + -8);
  return;
}


// ===== 001419a0 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceApplyDefaultAlignment =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceApplyDefaultAlignment(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x148))(param_1 + -8);
  return;
}


// ===== 001419c0 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceGetVasInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceGetVasInfo(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x150))(param_1 + -8);
  return;
}


// ===== 001419e0 __nvoc_down_thunk_FABRIC_VASPACE_vaspacePinRootPageDir =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspacePinRootPageDir(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x158))(param_1 + -8);
  return;
}


// ===== 00141a00 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceUnpinRootPageDir =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceUnpinRootPageDir(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x160))(param_1 + -8);
  return;
}


// ===== 00141a20 __nvoc_down_thunk_FABRIC_VASPACE_vaspaceInvalidateTlb =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_FABRIC_VASPACE_vaspaceInvalidateTlb(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x168))(param_1 + -8);
  return;
}


// ===== 00141a40 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIncAllocRefCnt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIncAllocRefCnt(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x50))(param_1 + 8);
  return;
}


// ===== 00141a60 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetVaStart =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetVaStart(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x58))(param_1 + 8);
  return;
}


// ===== 00141a80 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetVaLimit =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetVaLimit(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x60))(param_1 + 8);
  return;
}


// ===== 00141aa0 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetFlags =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetFlags(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x70))(param_1 + 8);
  return;
}


// ===== 00141ac0 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceReserveMempool =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceReserveMempool(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x88))(param_1 + 8);
  return;
}


// ===== 00141ae0 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetHeap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetHeap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x90))(param_1 + 8);
  return;
}


// ===== 00141b00 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetMapPageSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetMapPageSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x98))(param_1 + 8);
  return;
}


// ===== 00141b20 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetBigPageSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetBigPageSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xa0))(param_1 + 8);
  return;
}


// ===== 00141b40 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIsFaultCapable =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIsFaultCapable(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xa8))(param_1 + 8);
  return;
}


// ===== 00141b60 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIsExternallyOwned =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIsExternallyOwned(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xb0))(param_1 + 8);
  return;
}


// ===== 00141b80 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIsAtsEnabled =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceIsAtsEnabled(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xb8))(param_1 + 8);
  return;
}


// ===== 00141ba0 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPasid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPasid(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xc0))(param_1 + 8);
  return;
}


// ===== 00141bc0 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPageDirBase =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPageDirBase(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 200))(param_1 + 8);
  return;
}


// ===== 00141be0 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPageTableInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPageTableInfo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xe8))(param_1 + 8);
  return;
}


// ===== 00141c00 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPteInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceGetPteInfo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf0))(param_1 + 8);
  return;
}


// ===== 00141c20 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceSetPteInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceSetPteInfo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf8))(param_1 + 8);
  return;
}


// ===== 00141c40 __nvoc_up_thunk_OBJVASPACE_fabricvaspaceFreeV2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJVASPACE_fabricvaspaceFreeV2(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x100))(param_1 + 8);
  return;
}


// ===== 00141c60 vaspaceFreeV2_14ee5e =====

undefined8 vaspaceFreeV2_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x282);
  return 0x56;
}


// ===== 00141c90 vaspaceSetPteInfo_14ee5e =====

undefined8 vaspaceSetPteInfo_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x27d);
  return 0x56;
}


// ===== 00141cc0 vaspaceGetPteInfo_14ee5e =====

undefined8 vaspaceGetPteInfo_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x278);
  return 0x56;
}


// ===== 00141cf0 vaspaceGetPageTableInfo_14ee5e =====

undefined8 vaspaceGetPageTableInfo_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x273);
  return 0x56;
}


// ===== 00141d20 vaspaceGetPageDirBase_9451a7 =====

undefined8 vaspaceGetPageDirBase_9451a7(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x263);
  return 0;
}


// ===== 00141d50 vaspaceGetPasid_14ee5e =====

undefined8 vaspaceGetPasid_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x25e);
  return 0x56;
}


// ===== 00141d80 vaspaceIsAtsEnabled_2fa1ff =====

undefined8 vaspaceIsAtsEnabled_2fa1ff(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x259);
  return 0;
}


// ===== 00141db0 vaspaceIsExternallyOwned_2fa1ff =====

undefined8 vaspaceIsExternallyOwned_2fa1ff(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x254);
  return 0;
}


// ===== 00141de0 vaspaceIsFaultCapable_2fa1ff =====

undefined8 vaspaceIsFaultCapable_2fa1ff(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x24f);
  return 0;
}


// ===== 00141e10 vaspaceGetBigPageSize_c26fae =====

undefined8 vaspaceGetBigPageSize_c26fae(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x24a);
  return 0;
}


// ===== 00141e40 vaspaceGetMapPageSize_c26fae =====

undefined8 vaspaceGetMapPageSize_c26fae(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x245);
  return 0;
}


// ===== 00141e70 vaspaceGetHeap_9451a7 =====

undefined8 vaspaceGetHeap_9451a7(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x240);
  return 0;
}


// ===== 00141ea0 vaspaceIncAllocRefCnt_14ee5e =====

undefined8 vaspaceIncAllocRefCnt_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x226);
  return 0x56;
}


// ===== 00141ed0 __nvoc_dtor_FABRIC_VASPACE =====

void __nvoc_dtor_FABRIC_VASPACE(long param_1)

{
  fabricvaspaceDestruct_IMPL();
  __nvoc_dtor_OBJVASPACE(param_1 + 8);
  return;
}


// ===== 00141f00 __nvoc_objCreate_FABRIC_VASPACE =====

int __nvoc_objCreate_FABRIC_VASPACE(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xe8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_fabric_vaspace_nvoc.c",0x18c);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_fabric_vaspace_nvoc.c",0x184);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xe8);
  puVar1 = puVar4 + 1;
  *(uint *)((long)puVar4 + 0x3c) = param_3;
  puVar2 = puVar4 + 2;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[0x10] = puVar2;
    puVar4[4] = 0;
    puVar4[0x11] = puVar1;
    puVar4[0x12] = puVar4;
    __nvoc_init__OBJVASPACE(puVar1);
    puVar4[2] = 0xc43990;
    puVar4[1] = 0xc43978;
    *puVar4 = __nvoc_metadata__FABRIC_VASPACE;
    iVar3 = __nvoc_ctor_OBJVASPACE(puVar1);
    if (iVar3 != 0) goto LAB_001420a6;
  }
  else {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar2);
    puVar4[0x11] = puVar1;
    puVar4[0x12] = puVar4;
    puVar4[0x10] = puVar2;
    __nvoc_init__OBJVASPACE(puVar1);
    puVar4[2] = 0xc43990;
    puVar4[1] = 0xc43978;
    *puVar4 = __nvoc_metadata__FABRIC_VASPACE;
    iVar3 = __nvoc_ctor_OBJVASPACE(puVar1);
    if (iVar3 != 0) {
      if (lVar5 != 0) {
        objRemoveChild_IMPL(lVar5,puVar2);
      }
LAB_001420a6:
      if ((param_3 & 2) != 0) {
        portMemSet(puVar4,0,0xe8);
        return iVar3;
      }
      portMemFree(puVar4);
      *param_1 = 0;
      return iVar3;
    }
  }
  *param_1 = (long)puVar4;
  return 0;
}


// ===== 00142110 __nvoc_objCreateDynamic_FABRIC_VASPACE =====

void __nvoc_objCreateDynamic_FABRIC_VASPACE(void)

{
  __nvoc_objCreate_FABRIC_VASPACE();
  return;
}


// ===== 00142120 fbsrInit_ac1694 =====

undefined8 fbsrInit_ac1694(void)

{
  return 0;
}


// ===== 00142130 fbsrDestroy_d44104 =====

void fbsrDestroy_d44104(void)

{
  return;
}


// ===== 00142140 fbsrBegin_395e98 =====

undefined8 fbsrBegin_395e98(void)

{
  return 0x56;
}


// ===== 00142150 fbsrEnd_395e98 =====

undefined8 fbsrEnd_395e98(void)

{
  return 0x56;
}


// ===== 00142160 fbsrSendMemsysProgramRawCompressionMode_ac1694 =====

undefined8 fbsrSendMemsysProgramRawCompressionMode_ac1694(void)

{
  return 0;
}


// ===== 00142170 __nvoc_dtor_OBJFBSR =====

void __nvoc_dtor_OBJFBSR(long param_1)

{
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 00142180 fbsrCopyMemoryMemDesc_f2d351 =====

void fbsrCopyMemoryMemDesc_f2d351(void)

{
  nvAssertFailed(&DAT_00c43bc8,"generated/g_fbsr_nvoc.h",0x13d);
  return;
}


// ===== 001421a0 __nvoc_init_funcTable_OBJFBSR_1.isra.0 =====

void __nvoc_init_funcTable_OBJFBSR_1_isra_0(long param_1,long param_2)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  uint uVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  
  uVar1 = *(ushort *)(param_2 + 0x10);
  uVar2 = uVar1 >> 5;
  if (uVar2 == 3) {
    if ((0xa000UL >> (uVar1 & 0x1f) & 1) == 0) {
LAB_001422c8:
      pcVar9 = fbsrInit_GM107;
      pcVar8 = fbsrDestroy_GM107;
      pcVar6 = fbsrBegin_GM107;
      pcVar5 = fbsrEnd_GM107;
      pcVar7 = fbsrCopyMemoryMemDesc_GM107;
      pcVar3 = fbsrSendMemsysProgramRawCompressionMode_ac1694;
      goto LAB_00142269;
    }
    pcVar9 = fbsrInit_ac1694;
    pcVar8 = fbsrDestroy_d44104;
    pcVar6 = fbsrBegin_395e98;
    pcVar5 = fbsrEnd_395e98;
    pcVar7 = fbsrCopyMemoryMemDesc_f2d351;
  }
  else {
    if (uVar2 == 1) {
      uVar4 = uVar1 & 0x1f;
      pcVar6 = fbsrBegin_GA100;
      pcVar5 = fbsrEnd_GA100;
      pcVar9 = fbsrInit_GM107;
      pcVar8 = fbsrDestroy_GM107;
      pcVar7 = fbsrCopyMemoryMemDesc_GM107;
      if ((0x1f0fc00UL >> (sbyte)uVar4 & 1) == 0) {
        pcVar6 = fbsrBegin_GM107;
        pcVar5 = fbsrEnd_GM107;
      }
      pcVar3 = fbsrSendMemsysProgramRawCompressionMode_GA100;
      if ((0xbdf0fc00UL >> uVar4 & 1) == 0) {
        pcVar3 = fbsrSendMemsysProgramRawCompressionMode_ac1694;
      }
      goto LAB_00142269;
    }
    if (uVar2 != 2) goto LAB_001422c8;
    pcVar9 = fbsrInit_GM107;
    pcVar8 = fbsrDestroy_GM107;
    pcVar6 = fbsrBegin_GM107;
    pcVar5 = fbsrEnd_GM107;
    pcVar7 = fbsrCopyMemoryMemDesc_GM107;
    if ((0x3f9UL >> (uVar1 & 0x1f) & 1) != 0) {
      pcVar3 = fbsrSendMemsysProgramRawCompressionMode_GA100;
      goto LAB_00142269;
    }
  }
  pcVar3 = fbsrSendMemsysProgramRawCompressionMode_ac1694;
LAB_00142269:
  *(code **)(param_1 + 0x48) = pcVar9;
  *(code **)(param_1 + 0x50) = pcVar8;
  *(code **)(param_1 + 0x58) = pcVar6;
  *(code **)(param_1 + 0x60) = pcVar5;
  *(code **)(param_1 + 0x68) = pcVar7;
  *(code **)(param_1 + 0x70) = pcVar3;
  return;
}


// ===== 00142300 __nvoc_objCreate_OBJFBSR =====

int __nvoc_objCreate_OBJFBSR(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  
  if ((param_3 & 2) == 0) {
    puVar6 = (undefined8 *)portMemAllocNonPaged(0x110);
    if (puVar6 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_fbsr_nvoc.c",0x100);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar6 = (undefined8 *)*param_1, puVar6 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL","generated/g_fbsr_nvoc.c"
                       ,0xf8);
    return 0x3b;
  }
  portMemSet(puVar6,0,0x110);
  *(uint *)((long)puVar6 + 0x34) = param_3;
  if (param_2 == 0) {
    iVar2 = 0x1f;
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_fbsr_nvoc.c",0x109);
    goto joined_r0x00142579;
  }
  if ((param_3 & 1) == 0) {
    lVar7 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar7,puVar6 + 1);
  }
  else {
    puVar6[3] = 0;
    lVar7 = 0;
  }
  lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_GpuHalspecOwner);
  if (lVar3 == 0) {
    lVar3 = objFindAncestor_IMPL(param_2,0x74bc71);
    uVar5 = 0;
    if (lVar3 != 0) {
      uVar5 = objFindAncestor_IMPL(param_2,0x74bc71);
    }
    lVar3 = __nvoc_dynamicCast(uVar5,__nvoc_class_def_GpuHalspecOwner);
    if (lVar3 != 0) goto LAB_00142398;
    nvCheckOkFailedNoLog(4,0x1f,"pGpuhalspecowner != NULL","generated/g_fbsr_nvoc.c",0x119);
LAB_00142462:
    iVar2 = 0x1f;
  }
  else {
LAB_00142398:
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
    if (lVar4 == 0) {
      lVar4 = objFindAncestor_IMPL(param_2,0x34a6d6);
      uVar5 = 0;
      if (lVar4 != 0) {
        uVar5 = objFindAncestor_IMPL(param_2,0x34a6d6);
      }
      lVar4 = __nvoc_dynamicCast(uVar5,__nvoc_class_def_RmHalspecOwner);
      if (lVar4 == 0) {
        nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_fbsr_nvoc.c",0x11c);
        goto LAB_00142462;
      }
    }
    puVar1 = puVar6 + 1;
    puVar6[8] = puVar6;
    puVar6[7] = puVar1;
    __nvoc_init__Object(puVar1);
    puVar6[1] = 0xc43cb8;
    *puVar6 = __nvoc_metadata__OBJFBSR;
    __nvoc_init_funcTable_OBJFBSR_1_isra_0(puVar6,lVar3);
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      *param_1 = (long)puVar6;
      return 0;
    }
  }
  if (lVar7 != 0) {
    objRemoveChild_IMPL(lVar7,puVar6 + 1);
  }
joined_r0x00142579:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar6);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar6,0,0x110);
  }
  return iVar2;
}


// ===== 001425f0 __nvoc_objCreateDynamic_OBJFBSR =====

void __nvoc_objCreateDynamic_OBJFBSR(void)

{
  __nvoc_objCreate_OBJFBSR();
  return;
}


// ===== 00142600 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00142610 __nvoc_up_thunk_RmResource_fmsessionapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf0))(param_1 + 8,param_2,param_3,param_4);
  return;
}


// ===== 00142630 __nvoc_up_thunk_RmResource_fmsessionapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf8))(param_1 + 8);
  return;
}


// ===== 00142650 __nvoc_up_thunk_RmResource_fmsessionapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x100))(param_1 + 8);
  return;
}


// ===== 00142670 __nvoc_up_thunk_RmResource_fmsessionapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x108))(param_1 + 8,param_2);
  return;
}


// ===== 00142690 __nvoc_up_thunk_RmResource_fmsessionapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x110))(param_1 + 8);
  return;
}


// ===== 001426b0 __nvoc_up_thunk_RmResource_fmsessionapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x118))(param_1 + 8);
  return;
}


// ===== 001426d0 __nvoc_up_thunk_RmResource_fmsessionapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x120))(param_1 + 8);
  return;
}


// ===== 001426f0 __nvoc_up_thunk_RmResource_fmsessionapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x128))(param_1 + 8);
  return;
}


// ===== 00142710 __nvoc_up_thunk_RmResource_fmsessionapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_fmsessionapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x130))(param_1 + 8);
  return;
}


// ===== 00142730 __nvoc_up_thunk_RsResource_fmsessionapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x30))(param_1 + 0x10);
  return;
}


// ===== 00142750 __nvoc_up_thunk_RsResource_fmsessionapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x38))(param_1 + 0x10);
  return;
}


// ===== 00142770 __nvoc_up_thunk_RsResource_fmsessionapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x40))(param_1 + 0x10);
  return;
}


// ===== 00142790 __nvoc_up_thunk_RsResource_fmsessionapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x48))(param_1 + 0x10);
  return;
}


// ===== 001427b0 __nvoc_up_thunk_RsResource_fmsessionapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x50))(param_1 + 0x10);
  return;
}


// ===== 001427d0 __nvoc_up_thunk_RsResource_fmsessionapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x78))(param_1 + 0x10);
  return;
}


// ===== 001427f0 __nvoc_up_thunk_RsResource_fmsessionapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x80))(param_1 + 0x10);
  return;
}


// ===== 00142810 __nvoc_up_thunk_RsResource_fmsessionapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x88))(param_1 + 0x10);
  return;
}


// ===== 00142830 __nvoc_up_thunk_RsResource_fmsessionapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x90))(param_1 + 0x10);
  return;
}


// ===== 00142850 __nvoc_up_thunk_RsResource_fmsessionapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x98))(param_1 + 0x10);
  return;
}


// ===== 00142870 __nvoc_up_thunk_RsResource_fmsessionapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xa0))(param_1 + 0x10);
  return;
}


// ===== 00142890 __nvoc_up_thunk_RsResource_fmsessionapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_fmsessionapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x10) + 0xb8))(param_1,param_2 + 0x10);
  return;
}


// ===== 001428b0 __nvoc_dtor_FmSessionApi =====

void __nvoc_dtor_FmSessionApi(long param_1)

{
  fmsessionapiDestruct_IMPL();
  __nvoc_dtor_RmResource(param_1 + 8);
  return;
}


// ===== 001428e0 __nvoc_objCreate_FmSessionApi =====

int __nvoc_objCreate_FmSessionApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xe0);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_fm_session_api_nvoc.c",0x1b9);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_fm_session_api_nvoc.c",0x1b1);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xe0);
  puVar1 = puVar4 + 3;
  *(uint *)((long)puVar4 + 0x44) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[5] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x16] = puVar1;
  puVar4[0x17] = puVar4 + 2;
  puVar4[0x18] = puVar4 + 0xf;
  puVar4[0x19] = puVar2;
  puVar4[0x1a] = puVar4;
  __nvoc_init__RmResource(puVar2);
  puVar4[3] = 0xc43e08;
  puVar4[2] = 0xc43df0;
  puVar4[0xf] = 0xc43eb0;
  puVar4[1] = 0xc43dd8;
  *puVar4 = __nvoc_metadata__FmSessionApi;
  iVar3 = __nvoc_ctor_RmResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = fmsessionapiConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_RmResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0xe0);
  }
  return iVar3;
}


// ===== 00142b40 __nvoc_objCreateDynamic_FmSessionApi =====

void __nvoc_objCreateDynamic_FmSessionApi
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_00142b6e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_00142b6e:
  __nvoc_objCreate_FmSessionApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00142ba0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00142bb0 __nvoc_down_thunk_GenericEngineApi_gpuresMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_GenericEngineApi_gpuresMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x290))(param_1 + -8);
  return;
}


// ===== 00142bd0 __nvoc_down_thunk_GenericEngineApi_gpuresGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_GenericEngineApi_gpuresGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x298))(param_1 + -8);
  return;
}


// ===== 00142bf0 __nvoc_down_thunk_GenericEngineApi_gpuresControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_GenericEngineApi_gpuresControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x2a0))(param_1 + -8);
  return;
}


// ===== 00142c10 __nvoc_up_thunk_GpuResource_genapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_genapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 00142c30 __nvoc_up_thunk_GpuResource_genapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_genapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 00142c50 __nvoc_up_thunk_GpuResource_genapiGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_genapiGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 00142c70 __nvoc_up_thunk_GpuResource_genapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_genapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 00142c90 __nvoc_up_thunk_GpuResource_genapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_genapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 00142cb0 __nvoc_up_thunk_RmResource_genapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 00142cd0 __nvoc_up_thunk_RmResource_genapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 00142cf0 __nvoc_up_thunk_RmResource_genapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 00142d10 __nvoc_up_thunk_RmResource_genapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 00142d30 __nvoc_up_thunk_RmResource_genapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 00142d50 __nvoc_up_thunk_RmResource_genapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 00142d70 __nvoc_up_thunk_RmResource_genapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 00142d90 __nvoc_up_thunk_RmResource_genapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_genapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 00142db0 __nvoc_up_thunk_RsResource_genapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 00142dd0 __nvoc_up_thunk_RsResource_genapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 00142df0 __nvoc_up_thunk_RsResource_genapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 00142e10 __nvoc_up_thunk_RsResource_genapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 00142e30 __nvoc_up_thunk_RsResource_genapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 00142e50 __nvoc_up_thunk_RsResource_genapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 00142e70 __nvoc_up_thunk_RsResource_genapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 00142e90 __nvoc_up_thunk_RsResource_genapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 00142eb0 __nvoc_up_thunk_RsResource_genapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_genapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 00142ed0 __nvoc_dtor_GenericEngineApi =====

void __nvoc_dtor_GenericEngineApi(long param_1)

{
  genapiDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 00142f00 __nvoc_objCreate_GenericEngineApi =====

int __nvoc_objCreate_GenericEngineApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x138);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_generic_engine_nvoc.c",0x23a);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_generic_engine_nvoc.c",0x232);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x138);
  puVar1 = puVar4 + 4;
  *(uint *)((long)puVar4 + 0x4c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[6] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x21] = puVar1;
  puVar4[0x22] = puVar4 + 3;
  puVar4[0x23] = puVar4 + 0x10;
  puVar4[0x24] = puVar4 + 2;
  puVar4[0x25] = puVar2;
  puVar4[0x26] = puVar4;
  __nvoc_init__GpuResource(puVar2);
  puVar4[4] = 0xc44240;
  puVar4[3] = 0xc44228;
  puVar4[0x10] = 0xc442e8;
  puVar4[2] = 0xc44210;
  puVar4[1] = 0xc441f8;
  *puVar4 = __nvoc_metadata__GenericEngineApi;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = genapiConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_GpuResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x138);
  }
  return iVar3;
}


// ===== 00143180 __nvoc_objCreateDynamic_GenericEngineApi =====

void __nvoc_objCreateDynamic_GenericEngineApi
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_001431ae;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_001431ae:
  __nvoc_objCreate_GenericEngineApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001431e0 __nvoc_down_thunk_IoAperture_regaprtReadReg08 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtReadReg08(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0x88))(param_1 + -0x38);
  return;
}


// ===== 00143200 __nvoc_down_thunk_IoAperture_regaprtReadReg16 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtReadReg16(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0x90))(param_1 + -0x38);
  return;
}


// ===== 00143220 __nvoc_down_thunk_IoAperture_regaprtReadReg32 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtReadReg32(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0x98))(param_1 + -0x38);
  return;
}


// ===== 00143240 __nvoc_down_thunk_IoAperture_regaprtWriteReg08 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtWriteReg08
               (long param_1,undefined8 param_2,undefined1 param_3)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0xa0))(param_1 + -0x38,param_2,param_3);
  return;
}


// ===== 00143260 __nvoc_down_thunk_IoAperture_regaprtWriteReg16 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtWriteReg16
               (long param_1,undefined8 param_2,undefined2 param_3)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0xa8))(param_1 + -0x38,param_2,param_3);
  return;
}


// ===== 00143280 __nvoc_down_thunk_IoAperture_regaprtWriteReg32 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtWriteReg32(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0xb0))(param_1 + -0x38);
  return;
}


// ===== 001432a0 __nvoc_down_thunk_IoAperture_regaprtWriteReg32Uc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtWriteReg32Uc(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0xb8))(param_1 + -0x38);
  return;
}


// ===== 001432c0 __nvoc_down_thunk_IoAperture_regaprtIsRegValid =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_IoAperture_regaprtIsRegValid(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x38) + 0xc0))(param_1 + -0x38);
  return;
}


// ===== 001432e0 __nvoc_dtor_IoAperture =====

void __nvoc_dtor_IoAperture(long param_1)

{
  ioaprtDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  __nvoc_dtor_RegisterAperture(param_1 + 0x38);
  return;
}


// ===== 00143310 __nvoc_ctor_IoAperture =====

ulong __nvoc_ctor_IoAperture
                (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8,
                undefined8 param_9)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_Object(param_1 + 8);
  if ((int)uVar2 == 0) {
    uVar1 = __nvoc_ctor_RegisterAperture(param_1 + 0x38);
    if (uVar1 == 0) {
      uVar2 = ioaprtConstruct_IMPL
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
      uVar1 = (uint)uVar2;
      if (uVar1 == 0) {
        return uVar2;
      }
      __nvoc_dtor_RegisterAperture(param_1 + 0x38);
    }
    __nvoc_dtor_Object(param_1 + 8);
    uVar2 = (ulong)uVar1;
  }
  return uVar2;
}


// ===== 001433d0 __nvoc_objCreate_IoAperture =====

int __nvoc_objCreate_IoAperture
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5,
              undefined4 param_6,undefined4 param_7,undefined8 param_8,undefined4 param_9,
              undefined4 param_10,undefined8 param_11)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x88);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_access_nvoc.c",0x100);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_access_nvoc.c",0xf8);
    return 0x3b;
  }
  puVar1 = puVar4 + 7;
  portMemSet(puVar4,0,0x88);
  *(uint *)((long)puVar4 + 0x34) = param_3;
  puVar2 = puVar4 + 1;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[9] = puVar2;
    puVar4[10] = puVar1;
    puVar4[3] = 0;
    puVar4[0xb] = puVar4;
    __nvoc_init__Object(puVar2);
    __nvoc_init__RegisterAperture(puVar1);
    puVar4[1] = 0xc447f8;
    puVar4[7] = 0xc44810;
    *puVar4 = __nvoc_metadata__IoAperture;
    iVar3 = __nvoc_ctor_IoAperture
                      (puVar4,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11);
    if (iVar3 != 0) goto LAB_001435bb;
  }
  else {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar2);
    puVar4[10] = puVar1;
    puVar4[0xb] = puVar4;
    puVar4[9] = puVar2;
    __nvoc_init__Object(puVar2);
    __nvoc_init__RegisterAperture(puVar1);
    puVar4[1] = 0xc447f8;
    puVar4[7] = 0xc44810;
    *puVar4 = __nvoc_metadata__IoAperture;
    iVar3 = __nvoc_ctor_IoAperture
                      (puVar4,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11);
    if (iVar3 != 0) {
      if (lVar5 != 0) {
        objRemoveChild_IMPL(lVar5,puVar2);
      }
LAB_001435bb:
      if ((param_3 & 2) != 0) {
        portMemSet(puVar4,0,0x88);
        return iVar3;
      }
      portMemFree(puVar4);
      *param_1 = 0;
      return iVar3;
    }
  }
  *param_1 = (long)puVar4;
  return 0;
}


// ===== 00143620 __nvoc_objCreateDynamic_IoAperture =====

void __nvoc_objCreateDynamic_IoAperture
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  
  uVar3 = *param_4;
  if (uVar3 < 0x30) {
    lVar6 = *(long *)(param_4 + 4);
    uVar1 = uVar3 + 8;
    *param_4 = uVar1;
    uVar9 = *(undefined8 *)(lVar6 + (ulong)uVar3);
    if (0x2f < uVar1) {
      puVar8 = *(undefined8 **)(param_4 + 2);
      goto LAB_001436ff;
    }
    uVar2 = uVar3 + 0x10;
    *param_4 = uVar2;
    uVar10 = *(undefined8 *)(lVar6 + (ulong)uVar1);
    if (0x2f < uVar2) {
      puVar7 = *(undefined8 **)(param_4 + 2);
      goto LAB_0014370a;
    }
    uVar1 = uVar3 + 0x18;
    *param_4 = uVar1;
    uVar11 = *(undefined4 *)(lVar6 + (ulong)uVar2);
    if (0x2f < uVar1) {
      puVar8 = *(undefined8 **)(param_4 + 2);
      goto LAB_00143715;
    }
    uVar2 = uVar3 + 0x20;
    *param_4 = uVar2;
    uVar12 = *(undefined4 *)(lVar6 + (ulong)uVar1);
    if (0x2f < uVar2) {
      puVar7 = *(undefined8 **)(param_4 + 2);
      goto LAB_00143720;
    }
    uVar1 = uVar3 + 0x28;
    *param_4 = uVar1;
    uVar13 = *(undefined8 *)(lVar6 + (ulong)uVar2);
    if (uVar1 < 0x30) {
      *param_4 = uVar3 + 0x30;
      puVar7 = *(undefined8 **)(param_4 + 2);
      uVar4 = *(undefined4 *)(lVar6 + (ulong)uVar1);
      goto LAB_001436b3;
    }
    puVar8 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar7 = *(undefined8 **)(param_4 + 2);
    puVar8 = puVar7 + 1;
    *(undefined8 **)(param_4 + 2) = puVar8;
    uVar9 = *puVar7;
LAB_001436ff:
    puVar7 = puVar8 + 1;
    *(undefined8 **)(param_4 + 2) = puVar7;
    uVar10 = *puVar8;
LAB_0014370a:
    puVar8 = puVar7 + 1;
    *(undefined8 **)(param_4 + 2) = puVar8;
    uVar11 = *(undefined4 *)puVar7;
LAB_00143715:
    puVar7 = puVar8 + 1;
    *(undefined8 **)(param_4 + 2) = puVar7;
    uVar12 = *(undefined4 *)puVar8;
LAB_00143720:
    puVar8 = puVar7 + 1;
    *(undefined8 **)(param_4 + 2) = puVar8;
    uVar13 = *puVar7;
  }
  puVar7 = puVar8 + 1;
  *(undefined8 **)(param_4 + 2) = puVar7;
  uVar4 = *(undefined4 *)puVar8;
LAB_001436b3:
  *(undefined8 **)(param_4 + 2) = puVar7 + 1;
  uVar5 = *(undefined4 *)puVar7;
  *(undefined8 **)(param_4 + 2) = puVar7 + 2;
  __nvoc_objCreate_IoAperture
            (param_1,param_2,param_3,uVar9,uVar10,uVar11,uVar12,uVar13,uVar4,uVar5,puVar7[1]);
  return;
}


// ===== 00143760 __nvoc_dtor_GpuAccounting =====

void __nvoc_dtor_GpuAccounting(long param_1)

{
  gpuacctDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 00143790 __nvoc_objCreate_GpuAccounting =====

int __nvoc_objCreate_GpuAccounting(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x21e48);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_acct_nvoc.c",0xac);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_acct_nvoc.c",0xa4);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x21e48);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc449b8;
    *puVar3 = __nvoc_metadata__GpuAccounting;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpuacctConstruct_IMPL(puVar3);
      if (iVar2 == 0) goto LAB_0014384f;
      __nvoc_dtor_Object(puVar1);
    }
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc449b8;
    *puVar3 = __nvoc_metadata__GpuAccounting;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpuacctConstruct_IMPL(puVar3);
      if (iVar2 == 0) {
LAB_0014384f:
        *param_1 = (long)puVar3;
        return 0;
      }
      __nvoc_dtor_Object(puVar1);
    }
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar3,0,0x21e48);
  }
  return iVar2;
}


// ===== 001439b0 __nvoc_objCreateDynamic_GpuAccounting =====

void __nvoc_objCreateDynamic_GpuAccounting(void)

{
  __nvoc_objCreate_GpuAccounting();
  return;
}


// ===== 001439c0 gpuarchGetDmaAddrWidth_b2b553 =====

undefined8 gpuarchGetDmaAddrWidth_b2b553(void)

{
  return 0;
}


// ===== 001439c7 __nvoc_init_funcTable_GpuArch_1.cold =====

void __nvoc_init_funcTable_GpuArch_1_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001439e0 __nvoc_init_funcTable_GpuArch_1 =====

void __nvoc_init_funcTable_GpuArch_1(long param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  code *pcVar5;
  code *pcVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  uVar1 = *(ushort *)(*(long *)(param_1 + 0x58) + 0x10);
  uVar2 = uVar1 >> 5;
  uVar3 = (uint)uVar1;
  if (uVar2 != 3) {
    if (uVar2 == 1) {
      if ((short)(uVar3 & 0x1f) != 0x1d) {
        pcVar4 = gpuarchGetSystemPhysAddrWidth_TU102;
        *(code **)(param_1 + 0x70) = gpuarchGetDmaAddrWidth_b2b553;
        if ((0x1f0ffe0UL >> (uVar3 & 0x1f) & 1) == 0) {
          pcVar4 = gpuarchGetSystemPhysAddrWidth_GH100;
        }
        *(code **)(param_1 + 0x78) = gpuarchGetGpcFuseStatusOffset_b2b553;
        *(code **)(param_1 + 0x68) = pcVar4;
        return;
      }
      pcVar4 = gpuarchGetSystemPhysAddrWidth_GB10B;
      pcVar5 = gpuarchGetDmaAddrWidth_GB10B;
      pcVar6 = gpuarchGetGpcFuseStatusOffset_GB10B;
    }
    else {
      if (uVar2 == 2) {
        pcVar4 = gpuarchGetSystemPhysAddrWidth_GB10B;
        *(code **)(param_1 + 0x70) = gpuarchGetDmaAddrWidth_b2b553;
        if ((0x300UL >> (uVar3 & 0x1f) & 1) == 0) {
          pcVar4 = gpuarchGetSystemPhysAddrWidth_GH100;
        }
        *(code **)(param_1 + 0x78) = gpuarchGetGpcFuseStatusOffset_b2b553;
        *(code **)(param_1 + 0x68) = pcVar4;
        return;
      }
      pcVar4 = gpuarchGetSystemPhysAddrWidth_GH100;
      pcVar5 = gpuarchGetDmaAddrWidth_b2b553;
      pcVar6 = gpuarchGetGpcFuseStatusOffset_b2b553;
    }
    *(code **)(param_1 + 0x68) = pcVar4;
    *(code **)(param_1 + 0x70) = pcVar5;
    *(code **)(param_1 + 0x78) = pcVar6;
    return;
  }
  pcVar4 = gpuarchGetSystemPhysAddrWidth_T234D;
  *(code **)(param_1 + 0x70) = gpuarchGetDmaAddrWidth_b2b553;
  if ((0xa000UL >> (uVar3 & 0x1f) & 1) == 0) {
    pcVar4 = gpuarchGetSystemPhysAddrWidth_GH100;
  }
  *(code **)(param_1 + 0x78) = gpuarchGetGpcFuseStatusOffset_b2b553;
  *(code **)(param_1 + 0x68) = pcVar4;
  return;
}


// ===== 00143b20 __nvoc_dtor_GpuArch =====

void __nvoc_dtor_GpuArch(long param_1)

{
  __nvoc_dtor_Object(param_1 + 8);
  __nvoc_dtor_GpuHalspecOwner(param_1 + 0x38);
  return;
}


// ===== 00143b50 gpuarchGetGpcFuseStatusOffset_b2b553 =====

undefined8 gpuarchGetGpcFuseStatusOffset_b2b553(void)

{
  return 0;
}


// ===== 00143b57 __nvoc_init_dataField_GpuArch.cold =====

void __nvoc_init_dataField_GpuArch_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00143b70 __nvoc_init_dataField_GpuArch =====

void __nvoc_init_dataField_GpuArch(long param_1)

{
  ushort uVar1;
  code *pcVar2;
  ushort uVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar1 = *(ushort *)(*(long *)(param_1 + 0x58) + 0x10);
  uVar3 = uVar1 >> 5;
  if (uVar3 == 1) {
    if ((uVar1 & 0x1f) == 0x1d) goto LAB_00143bca;
  }
  else if ((uVar3 == 2) && ((0x300UL >> (uVar1 & 0x1f) & 1) != 0)) {
LAB_00143bca:
    *(undefined1 *)(param_1 + 0x80) = 1;
    *(bool *)(param_1 + 0x81) = uVar3 == 1;
    return;
  }
  *(undefined1 *)(param_1 + 0x80) = 0;
  *(undefined1 *)(param_1 + 0x81) = 0;
  return;
}


// ===== 00143c00 __nvoc_ctor_GpuArch =====

ulong __nvoc_ctor_GpuArch(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_Object(param_1 + 8);
  if ((int)uVar2 == 0) {
    uVar1 = __nvoc_ctor_GpuHalspecOwner(param_1 + 0x38);
    if (uVar1 == 0) {
      __nvoc_init_dataField_GpuArch(param_1);
      uVar2 = gpuarchConstruct_IMPL();
      uVar1 = (uint)uVar2;
      if (uVar1 == 0) {
        return uVar2;
      }
      __nvoc_dtor_GpuHalspecOwner(param_1 + 0x38);
    }
    __nvoc_dtor_Object(param_1 + 8);
    uVar2 = (ulong)uVar1;
  }
  return uVar2;
}


// ===== 00143cb0 __nvoc_objCreate_GpuArch =====

int __nvoc_objCreate_GpuArch
              (long *param_1,long param_2,uint param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x98);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_arch_nvoc.c",0x10a);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_arch_nvoc.c",0x102);
    return 0x3b;
  }
  puVar1 = puVar4 + 7;
  portMemSet(puVar4,0,0x98);
  *(uint *)((long)puVar4 + 0x34) = param_3;
  puVar2 = puVar4 + 1;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[10] = puVar2;
    puVar4[0xb] = puVar1;
    puVar4[3] = 0;
    puVar4[0xc] = puVar4;
    __nvoc_init__Object(puVar2);
    __nvoc_init__GpuHalspecOwner(puVar1,param_4,param_5,param_6,param_7);
    puVar4[1] = 0xc44ad8;
    puVar4[7] = 0xc44af0;
    *puVar4 = __nvoc_metadata__GpuArch;
    __nvoc_init_funcTable_GpuArch_1(puVar4);
    iVar3 = __nvoc_ctor_GpuArch();
    if (iVar3 != 0) goto LAB_00143e8c;
  }
  else {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar2);
    puVar4[0xb] = puVar1;
    puVar4[0xc] = puVar4;
    puVar4[10] = puVar2;
    __nvoc_init__Object(puVar2);
    __nvoc_init__GpuHalspecOwner(puVar1,param_4,param_5,param_6,param_7);
    puVar4[1] = 0xc44ad8;
    puVar4[7] = 0xc44af0;
    *puVar4 = __nvoc_metadata__GpuArch;
    __nvoc_init_funcTable_GpuArch_1(puVar4);
    iVar3 = __nvoc_ctor_GpuArch();
    if (iVar3 != 0) {
      if (lVar5 != 0) {
        objRemoveChild_IMPL(lVar5,puVar2);
      }
LAB_00143e8c:
      if ((param_3 & 2) != 0) {
        portMemSet(puVar4,0,0x98);
        return iVar3;
      }
      portMemFree(puVar4);
      *param_1 = 0;
      return iVar3;
    }
  }
  *param_1 = (long)puVar4;
  return 0;
}


// ===== 00143ef0 __nvoc_objCreateDynamic_GpuArch =====

void __nvoc_objCreateDynamic_GpuArch
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  uVar3 = *param_4;
  if (uVar3 < 0x30) {
    lVar6 = *(long *)(param_4 + 4);
    uVar1 = uVar3 + 8;
    *param_4 = uVar1;
    uVar9 = *(undefined4 *)(lVar6 + (ulong)uVar3);
    if (0x2f < uVar1) {
      puVar8 = *(undefined4 **)(param_4 + 2);
      goto LAB_00143fce;
    }
    uVar2 = uVar3 + 0x10;
    *param_4 = uVar2;
    uVar10 = *(undefined4 *)(lVar6 + (ulong)uVar1);
    if (0x2f < uVar2) {
      puVar7 = *(undefined4 **)(param_4 + 2);
      goto LAB_00143fd9;
    }
    uVar1 = uVar3 + 0x18;
    *param_4 = uVar1;
    uVar11 = *(undefined4 *)(lVar6 + (ulong)uVar2);
    if (0x2f < uVar1) {
      puVar8 = *(undefined4 **)(param_4 + 2);
      goto LAB_00143fe4;
    }
    uVar2 = uVar3 + 0x20;
    *param_4 = uVar2;
    uVar12 = *(undefined4 *)(lVar6 + (ulong)uVar1);
    if (0x2f < uVar2) {
      puVar7 = *(undefined4 **)(param_4 + 2);
      goto LAB_00143fef;
    }
    uVar1 = uVar3 + 0x28;
    *param_4 = uVar1;
    uVar13 = *(undefined4 *)(lVar6 + (ulong)uVar2);
    if (uVar1 < 0x30) {
      *param_4 = uVar3 + 0x30;
      puVar7 = *(undefined4 **)(param_4 + 2);
      uVar4 = *(undefined4 *)(lVar6 + (ulong)uVar1);
      goto LAB_00143f83;
    }
    puVar8 = *(undefined4 **)(param_4 + 2);
  }
  else {
    puVar7 = *(undefined4 **)(param_4 + 2);
    puVar8 = puVar7 + 2;
    *(undefined4 **)(param_4 + 2) = puVar8;
    uVar9 = *puVar7;
LAB_00143fce:
    puVar7 = puVar8 + 2;
    *(undefined4 **)(param_4 + 2) = puVar7;
    uVar10 = *puVar8;
LAB_00143fd9:
    puVar8 = puVar7 + 2;
    *(undefined4 **)(param_4 + 2) = puVar8;
    uVar11 = *puVar7;
LAB_00143fe4:
    puVar7 = puVar8 + 2;
    *(undefined4 **)(param_4 + 2) = puVar7;
    uVar12 = *puVar8;
LAB_00143fef:
    puVar8 = puVar7 + 2;
    *(undefined4 **)(param_4 + 2) = puVar8;
    uVar13 = *puVar7;
  }
  puVar7 = puVar8 + 2;
  *(undefined4 **)(param_4 + 2) = puVar7;
  uVar4 = *puVar8;
LAB_00143f83:
  *(undefined4 **)(param_4 + 2) = puVar7 + 2;
  uVar5 = *puVar7;
  *(undefined4 **)(param_4 + 2) = puVar7 + 4;
  __nvoc_objCreate_GpuArch
            (param_1,param_2,param_3,uVar9,uVar10,uVar11,uVar12,uVar13,uVar4,uVar5,puVar7[2]);
  return;
}


// ===== 00144030 __nvoc_dtor_OBJGPUBOOSTMGR =====

void __nvoc_dtor_OBJGPUBOOSTMGR(long param_1)

{
  gpuboostmgrDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 00144060 __nvoc_objCreate_OBJGPUBOOSTMGR =====

int __nvoc_objCreate_OBJGPUBOOSTMGR(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x918);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_boost_mgr_nvoc.c",0xac);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_boost_mgr_nvoc.c",0xa4);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x918);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc44c18;
    *puVar3 = __nvoc_metadata__OBJGPUBOOSTMGR;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpuboostmgrConstruct_IMPL(puVar3);
      if (iVar2 == 0) goto LAB_0014411f;
      __nvoc_dtor_Object(puVar1);
    }
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc44c18;
    *puVar3 = __nvoc_metadata__OBJGPUBOOSTMGR;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpuboostmgrConstruct_IMPL(puVar3);
      if (iVar2 == 0) {
LAB_0014411f:
        *param_1 = (long)puVar3;
        return 0;
      }
      __nvoc_dtor_Object(puVar1);
    }
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar3,0,0x918);
  }
  return iVar2;
}


// ===== 00144280 __nvoc_objCreateDynamic_OBJGPUBOOSTMGR =====

void __nvoc_objCreateDynamic_OBJGPUBOOSTMGR(void)

{
  __nvoc_objCreate_OBJGPUBOOSTMGR();
  return;
}


// ===== 00144290 gpuGetGenericClassList_IMPL =====

undefined1 * gpuGetGenericClassList_IMPL(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x10;
  return genericClassDescriptorList_62;
}


// ===== 001442b0 gpuGetNoEngClassList_TU102 =====

undefined1 * gpuGetNoEngClassList_TU102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x21;
  return halTU102ClassDescriptorList_61;
}


// ===== 001442d0 gpuGetEngClassDescriptorList_TU102 =====

undefined1 * gpuGetEngClassDescriptorList_TU102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x35;
  return halTU102ClassDescriptorList_60;
}


// ===== 001442f0 gpuGetNoEngClassList_TU104 =====

undefined1 * gpuGetNoEngClassList_TU104(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x21;
  return halTU104ClassDescriptorList_59;
}


// ===== 00144310 gpuGetEngClassDescriptorList_TU104 =====

undefined1 * gpuGetEngClassDescriptorList_TU104(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x36;
  return halTU104ClassDescriptorList_58;
}


// ===== 00144330 gpuGetNoEngClassList_TU106 =====

undefined1 * gpuGetNoEngClassList_TU106(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x21;
  return halTU106ClassDescriptorList_57;
}


// ===== 00144350 gpuGetEngClassDescriptorList_TU106 =====

undefined1 * gpuGetEngClassDescriptorList_TU106(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x37;
  return halTU106ClassDescriptorList_56;
}


// ===== 00144370 gpuGetNoEngClassList_TU117 =====

undefined1 * gpuGetNoEngClassList_TU117(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x21;
  return halTU117ClassDescriptorList_53;
}


// ===== 00144390 gpuGetEngClassDescriptorList_TU117 =====

undefined1 * gpuGetEngClassDescriptorList_TU117(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x35;
  return halTU117ClassDescriptorList_52;
}


// ===== 001443b0 gpuGetNoEngClassList_GA100 =====

undefined1 * gpuGetNoEngClassList_GA100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x29;
  return halGA100ClassDescriptorList_51;
}


// ===== 001443d0 gpuGetEngClassDescriptorList_GA100 =====

undefined1 * gpuGetEngClassDescriptorList_GA100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x3f;
  return halGA100ClassDescriptorList_50;
}


// ===== 001443f0 gpuGetNoEngClassList_GA102 =====

undefined1 * gpuGetNoEngClassList_GA102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2a;
  return halGA102ClassDescriptorList_49;
}


// ===== 00144410 gpuGetEngClassDescriptorList_GA102 =====

undefined1 * gpuGetEngClassDescriptorList_GA102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x3c;
  return halGA102ClassDescriptorList_48;
}


// ===== 00144430 gpuGetNoEngClassList_AD102 =====

undefined1 * gpuGetNoEngClassList_AD102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2a;
  return halAD102ClassDescriptorList_39;
}


// ===== 00144450 gpuGetEngClassDescriptorList_AD102 =====

undefined1 * gpuGetEngClassDescriptorList_AD102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x44;
  return halAD102ClassDescriptorList_38;
}


// ===== 00144470 gpuGetNoEngClassList_GH100 =====

undefined1 * gpuGetNoEngClassList_GH100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2d;
  return halGH100ClassDescriptorList_29;
}


// ===== 00144490 gpuGetEngClassDescriptorList_GH100 =====

undefined1 * gpuGetEngClassDescriptorList_GH100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x4c;
  return halGH100ClassDescriptorList_28;
}


// ===== 001444b0 gpuGetNoEngClassList_GB100 =====

undefined1 * gpuGetNoEngClassList_GB100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2d;
  return halGB100ClassDescriptorList_27;
}


// ===== 001444d0 gpuGetEngClassDescriptorList_GB100 =====

undefined1 * gpuGetEngClassDescriptorList_GB100(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x58;
  return halGB100ClassDescriptorList_26;
}


// ===== 001444f0 gpuGetNoEngClassList_GB102 =====

undefined1 * gpuGetNoEngClassList_GB102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2d;
  return halGB102ClassDescriptorList_25;
}


// ===== 00144510 gpuGetEngClassDescriptorList_GB102 =====

undefined1 * gpuGetEngClassDescriptorList_GB102(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x45;
  return halGB102ClassDescriptorList_24;
}


// ===== 00144530 gpuGetNoEngClassList_GB10B =====

undefined1 * gpuGetNoEngClassList_GB10B(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2e;
  return halGB10BClassDescriptorList_23;
}


// ===== 00144550 gpuGetEngClassDescriptorList_GB10B =====

undefined1 * gpuGetEngClassDescriptorList_GB10B(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x41;
  return halGB10BClassDescriptorList_22;
}


// ===== 00144570 gpuGetNoEngClassList_GB202 =====

undefined1 * gpuGetNoEngClassList_GB202(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2d;
  return halGB202ClassDescriptorList_17;
}


// ===== 00144590 gpuGetEngClassDescriptorList_GB202 =====

undefined1 * gpuGetEngClassDescriptorList_GB202(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 100;
  return halGB202ClassDescriptorList_16;
}


// ===== 001445b0 gpuGetNoEngClassList_GB20B =====

undefined1 * gpuGetNoEngClassList_GB20B(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2e;
  return halGB20BClassDescriptorList_7;
}


// ===== 001445d0 gpuGetEngClassDescriptorList_GB20B =====

undefined1 * gpuGetEngClassDescriptorList_GB20B(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x66;
  return halGB20BClassDescriptorList_6;
}


// ===== 001445f0 gpuGetNoEngClassList_GB20C =====

undefined1 * gpuGetNoEngClassList_GB20C(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x2e;
  return halGB20CClassDescriptorList_5;
}


// ===== 00144610 gpuGetEngClassDescriptorList_GB20C =====

undefined1 * gpuGetEngClassDescriptorList_GB20C(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x66;
  return halGB20CClassDescriptorList_4;
}


// ===== 00144630 gpuGetNoEngClassList_T234D =====

undefined4 * gpuGetNoEngClassList_T234D(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return &halT234DClassDescriptorList_3;
}


// ===== 00144650 gpuGetEngClassDescriptorList_T234D =====

undefined1 * gpuGetEngClassDescriptorList_T234D(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0xe;
  return halT234DClassDescriptorList_2;
}


// ===== 00144670 gpuGetNoEngClassList_T264D =====

undefined4 * gpuGetNoEngClassList_T264D(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return &halT264DClassDescriptorList_1;
}


// ===== 00144690 gpuGetEngClassDescriptorList_T264D =====

undefined1 * gpuGetEngClassDescriptorList_T264D(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0xd;
  return halT264DClassDescriptorList_0;
}


// ===== 001446b0 __nvoc_dtor_GpuDb =====

void __nvoc_dtor_GpuDb(long param_1)

{
  gpudbDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 001446e0 __nvoc_objCreate_GpuDb =====

int __nvoc_objCreate_GpuDb(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x78);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_db_nvoc.c",0xac);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_db_nvoc.c",0xa4);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x78);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc47898;
    *puVar3 = __nvoc_metadata__GpuDb;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpudbConstruct_IMPL(puVar3);
      if (iVar2 == 0) goto LAB_0014479f;
      __nvoc_dtor_Object(puVar1);
    }
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc47898;
    *puVar3 = __nvoc_metadata__GpuDb;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpudbConstruct_IMPL(puVar3);
      if (iVar2 == 0) {
LAB_0014479f:
        *param_1 = (long)puVar3;
        return 0;
      }
      __nvoc_dtor_Object(puVar1);
    }
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar3,0,0x78);
  }
  return iVar2;
}


// ===== 00144900 __nvoc_objCreateDynamic_GpuDb =====

void __nvoc_objCreateDynamic_GpuDb(void)

{
  __nvoc_objCreate_GpuDb();
  return;
}


// ===== 00144910 __nvoc_dtor_OBJGPUGRP =====

void __nvoc_dtor_OBJGPUGRP(long param_1)

{
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 00144920 __nvoc_objCreate_OBJGPUGRP =====

int __nvoc_objCreate_OBJGPUGRP(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0xd8);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_group_nvoc.c",0xa2);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_group_nvoc.c",0x9a);
    return 0x3b;
  }
  portMemSet(puVar3,0,0xd8);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc479b8;
    *puVar3 = __nvoc_metadata__OBJGPUGRP;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 != 0) goto LAB_00144a8f;
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc479b8;
    *puVar3 = __nvoc_metadata__OBJGPUGRP;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 != 0) {
      if (lVar4 != 0) {
        objRemoveChild_IMPL(lVar4,puVar1);
      }
LAB_00144a8f:
      if ((param_3 & 2) != 0) {
        portMemSet(puVar3,0,0xd8);
        return iVar2;
      }
      portMemFree(puVar3);
      *param_1 = 0;
      return iVar2;
    }
  }
  *param_1 = (long)puVar3;
  return 0;
}


// ===== 00144b00 __nvoc_objCreateDynamic_OBJGPUGRP =====

void __nvoc_objCreateDynamic_OBJGPUGRP(void)

{
  __nvoc_objCreate_OBJGPUGRP();
  return;
}


// ===== 00144b10 __nvoc_dtor_RmHalspecOwner =====

void __nvoc_dtor_RmHalspecOwner(void)

{
  return;
}


// ===== 00144b20 __nvoc_dtor_GpuHalspecOwner =====

void __nvoc_dtor_GpuHalspecOwner(void)

{
  return;
}


// ===== 00144b30 __nvoc_ctor_RmHalspecOwner =====

undefined8 __nvoc_ctor_RmHalspecOwner(void)

{
  return 0;
}


// ===== 00144b40 __nvoc_init__RmHalspecOwner =====

void __nvoc_init__RmHalspecOwner(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  *param_1 = __nvoc_metadata__RmHalspecOwner;
  param_1[1] = param_1;
  __nvoc_init_halspec_RmVariantHal(param_1 + 2);
  __nvoc_init_halspec_DispIpHal((long)param_1 + 0x12,param_3);
  return;
}


// ===== 00144b80 __nvoc_ctor_GpuHalspecOwner =====

undefined8 __nvoc_ctor_GpuHalspecOwner(void)

{
  return 0;
}


// ===== 00144b90 __nvoc_init__GpuHalspecOwner =====

void __nvoc_init__GpuHalspecOwner(undefined8 *param_1)

{
  undefined4 in_R8D;
  
  *param_1 = __nvoc_metadata__GpuHalspecOwner;
  param_1[1] = param_1;
  __nvoc_init_halspec_ChipHal(param_1 + 2);
  __nvoc_init_halspec_TegraChipHal((long)param_1 + 0x12,in_R8D);
  return;
}


// ===== 00144bd0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00144be0 __nvoc_down_thunk_GPUInstanceSubscription_resCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_GPUInstanceSubscription_resCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x290))(param_1 + -0x18);
  return;
}


// ===== 00144c00 __nvoc_up_thunk_GpuResource_gisubscriptionControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 00144c20 __nvoc_up_thunk_GpuResource_gisubscriptionMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 00144c40 __nvoc_up_thunk_GpuResource_gisubscriptionUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 00144c60 __nvoc_up_thunk_GpuResource_gisubscriptionShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 00144c80 __nvoc_up_thunk_GpuResource_gisubscriptionGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 00144ca0 __nvoc_up_thunk_GpuResource_gisubscriptionGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 00144cc0 __nvoc_up_thunk_GpuResource_gisubscriptionInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 00144ce0 __nvoc_up_thunk_GpuResource_gisubscriptionGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_gisubscriptionGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 00144d00 __nvoc_up_thunk_RmResource_gisubscriptionAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 00144d20 __nvoc_up_thunk_RmResource_gisubscriptionGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 00144d40 __nvoc_up_thunk_RmResource_gisubscriptionCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 00144d60 __nvoc_up_thunk_RmResource_gisubscriptionGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 00144d80 __nvoc_up_thunk_RmResource_gisubscriptionControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 00144da0 __nvoc_up_thunk_RmResource_gisubscriptionControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 00144dc0 __nvoc_up_thunk_RmResource_gisubscriptionControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 00144de0 __nvoc_up_thunk_RmResource_gisubscriptionControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gisubscriptionControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 00144e00 __nvoc_up_thunk_RsResource_gisubscriptionIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 00144e20 __nvoc_up_thunk_RsResource_gisubscriptionPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 00144e40 __nvoc_up_thunk_RsResource_gisubscriptionControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 00144e60 __nvoc_up_thunk_RsResource_gisubscriptionIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 00144e80 __nvoc_up_thunk_RsResource_gisubscriptionMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 00144ea0 __nvoc_up_thunk_RsResource_gisubscriptionUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 00144ec0 __nvoc_up_thunk_RsResource_gisubscriptionGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 00144ee0 __nvoc_up_thunk_RsResource_gisubscriptionAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gisubscriptionAddAdditionalDependants
               (undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 00144f00 __nvoc_dtor_GPUInstanceSubscription =====

void __nvoc_dtor_GPUInstanceSubscription(long param_1)

{
  gisubscriptionDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 00144f30 __nvoc_objCreate_GPUInstanceSubscription =====

int __nvoc_objCreate_GPUInstanceSubscription
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x150);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_instance_subscription_nvoc.c",
                         0x267);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_instance_subscription_nvoc.c",0x25f);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x150);
  puVar1 = puVar4 + 4;
  *(uint *)((long)puVar4 + 0x4c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[6] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x21] = puVar1;
  puVar4[0x22] = puVar4 + 3;
  puVar4[0x23] = puVar4 + 0x10;
  puVar4[0x24] = puVar4 + 2;
  puVar4[0x25] = puVar2;
  puVar4[0x26] = puVar4;
  __nvoc_init__GpuResource(puVar2);
  puVar4[4] = 0xc47c60;
  puVar4[3] = 0xc47c48;
  puVar4[0x10] = 0xc47d08;
  puVar4[2] = 0xc47c30;
  puVar4[1] = 0xc47c18;
  *puVar4 = __nvoc_metadata__GPUInstanceSubscription;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = gisubscriptionConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_GpuResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x150);
  }
  return iVar3;
}


// ===== 001451b0 __nvoc_objCreateDynamic_GPUInstanceSubscription =====

void __nvoc_objCreateDynamic_GPUInstanceSubscription
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_001451de;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_001451de:
  __nvoc_objCreate_GPUInstanceSubscription(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00145210 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00145220 __nvoc_up_thunk_RmResource_gpumgmtapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf0))(param_1 + 8,param_2,param_3,param_4);
  return;
}


// ===== 00145240 __nvoc_up_thunk_RmResource_gpumgmtapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf8))(param_1 + 8);
  return;
}


// ===== 00145260 __nvoc_up_thunk_RmResource_gpumgmtapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x100))(param_1 + 8);
  return;
}


// ===== 00145280 __nvoc_up_thunk_RmResource_gpumgmtapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x108))(param_1 + 8,param_2);
  return;
}


// ===== 001452a0 __nvoc_up_thunk_RmResource_gpumgmtapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x110))(param_1 + 8);
  return;
}


// ===== 001452c0 __nvoc_up_thunk_RmResource_gpumgmtapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x118))(param_1 + 8);
  return;
}


// ===== 001452e0 __nvoc_up_thunk_RmResource_gpumgmtapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x120))(param_1 + 8);
  return;
}


// ===== 00145300 __nvoc_up_thunk_RmResource_gpumgmtapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x128))(param_1 + 8);
  return;
}


// ===== 00145320 __nvoc_up_thunk_RmResource_gpumgmtapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_gpumgmtapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x130))(param_1 + 8);
  return;
}


// ===== 00145340 __nvoc_up_thunk_RsResource_gpumgmtapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x30))(param_1 + 0x10);
  return;
}


// ===== 00145360 __nvoc_up_thunk_RsResource_gpumgmtapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x38))(param_1 + 0x10);
  return;
}


// ===== 00145380 __nvoc_up_thunk_RsResource_gpumgmtapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x40))(param_1 + 0x10);
  return;
}


// ===== 001453a0 __nvoc_up_thunk_RsResource_gpumgmtapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x48))(param_1 + 0x10);
  return;
}


// ===== 001453c0 __nvoc_up_thunk_RsResource_gpumgmtapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x50))(param_1 + 0x10);
  return;
}


// ===== 001453e0 __nvoc_up_thunk_RsResource_gpumgmtapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x78))(param_1 + 0x10);
  return;
}


// ===== 00145400 __nvoc_up_thunk_RsResource_gpumgmtapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x80))(param_1 + 0x10);
  return;
}


// ===== 00145420 __nvoc_up_thunk_RsResource_gpumgmtapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x88))(param_1 + 0x10);
  return;
}


// ===== 00145440 __nvoc_up_thunk_RsResource_gpumgmtapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x90))(param_1 + 0x10);
  return;
}


// ===== 00145460 __nvoc_up_thunk_RsResource_gpumgmtapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x98))(param_1 + 0x10);
  return;
}


// ===== 00145480 __nvoc_up_thunk_RsResource_gpumgmtapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xa0))(param_1 + 0x10);
  return;
}


// ===== 001454a0 __nvoc_up_thunk_RsResource_gpumgmtapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_gpumgmtapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x10) + 0xb8))(param_1,param_2 + 0x10);
  return;
}


// ===== 001454c0 __nvoc_dtor_GpuManagementApi =====

void __nvoc_dtor_GpuManagementApi(long param_1)

{
  gpumgmtapiDestruct_IMPL();
  __nvoc_dtor_RmResource(param_1 + 8);
  return;
}


// ===== 001454f0 __nvoc_objCreate_GpuManagementApi =====

int __nvoc_objCreate_GpuManagementApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xd8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_mgmt_api_nvoc.c",0x1aa);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_mgmt_api_nvoc.c",0x1a2);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xd8);
  puVar1 = puVar4 + 3;
  *(uint *)((long)puVar4 + 0x44) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[5] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x16] = puVar1;
  puVar4[0x17] = puVar4 + 2;
  puVar4[0x18] = puVar4 + 0xf;
  puVar4[0x19] = puVar2;
  puVar4[0x1a] = puVar4;
  __nvoc_init__RmResource(puVar2);
  puVar4[3] = 0xc48348;
  puVar4[2] = 0xc48330;
  puVar4[0xf] = 0xc483f0;
  puVar4[1] = 0xc48318;
  *puVar4 = __nvoc_metadata__GpuManagementApi;
  iVar3 = __nvoc_ctor_RmResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = gpumgmtapiConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_RmResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0xd8);
  }
  return iVar3;
}


// ===== 00145750 __nvoc_objCreateDynamic_GpuManagementApi =====

void __nvoc_objCreateDynamic_GpuManagementApi
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0014577e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0014577e:
  __nvoc_objCreate_GpuManagementApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001457b0 __nvoc_dtor_OBJGPUMGR =====

void __nvoc_dtor_OBJGPUMGR(long param_1)

{
  gpumgrDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 001457e0 __nvoc_objCreate_OBJGPUMGR =====

int __nvoc_objCreate_OBJGPUMGR(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x3f318);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_gpu_mgr_nvoc.c",0xac);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_gpu_mgr_nvoc.c",0xa4);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x3f318);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc48698;
    *puVar3 = __nvoc_metadata__OBJGPUMGR;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpumgrConstruct_IMPL(puVar3);
      if (iVar2 == 0) goto LAB_0014589f;
      __nvoc_dtor_Object(puVar1);
    }
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc48698;
    *puVar3 = __nvoc_metadata__OBJGPUMGR;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) {
      iVar2 = gpumgrConstruct_IMPL(puVar3);
      if (iVar2 == 0) {
LAB_0014589f:
        *param_1 = (long)puVar3;
        return 0;
      }
      __nvoc_dtor_Object(puVar1);
    }
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar3,0,0x3f318);
  }
  return iVar2;
}


// ===== 00145a00 __nvoc_objCreateDynamic_OBJGPUMGR =====

void __nvoc_objCreateDynamic_OBJGPUMGR(void)

{
  __nvoc_objCreate_OBJGPUMGR();
  return;
}


// ===== 00145a10 gpuConstructDeviceInfoTable_ac1694 =====

undefined8 gpuConstructDeviceInfoTable_ac1694(void)

{
  return 0;
}


// ===== 00145a20 gpuGetRtd3GC6Data_d44104 =====

void gpuGetRtd3GC6Data_d44104(void)

{
  return;
}


// ===== 00145a30 gpuCheckEngine_e661f0 =====

undefined8 gpuCheckEngine_e661f0(void)

{
  return 1;
}


// ===== 00145a40 gpuIsSocSdmEnabled_d69453 =====

undefined8 gpuIsSocSdmEnabled_d69453(void)

{
  return 0;
}


// ===== 00145a50 gpuReadPBusScratch_395e98 =====

undefined8 gpuReadPBusScratch_395e98(void)

{
  return 0x56;
}


// ===== 00145a60 gpuWritePBusScratch_d44104 =====

void gpuWritePBusScratch_d44104(void)

{
  return;
}


// ===== 00145a70 gpuGetResetScratchBit_395e98 =====

undefined8 gpuGetResetScratchBit_395e98(void)

{
  return 0x56;
}


// ===== 00145a80 gpuMarkDeviceForReset_395e98 =====

undefined8 gpuMarkDeviceForReset_395e98(void)

{
  return 0x56;
}


// ===== 00145a90 gpuRefreshRecoveryAction_d44104 =====

void gpuRefreshRecoveryAction_d44104(void)

{
  return;
}


// ===== 00145aa0 gpuGetBusIntfType_28ceda =====

undefined8 gpuGetBusIntfType_28ceda(void)

{
  return 1;
}


// ===== 00145ab0 gpuGetBusIntfType_f222ee =====

undefined8 gpuGetBusIntfType_f222ee(void)

{
  return 8;
}


// ===== 00145ac0 gpuGetBusIntfType_2f2c74 =====

undefined8 gpuGetBusIntfType_2f2c74(void)

{
  return 3;
}


// ===== 00145ad0 gpuWriteBusConfigReg_395e98 =====

undefined8 gpuWriteBusConfigReg_395e98(void)

{
  return 0x56;
}


// ===== 00145ae0 gpuReadBusConfigReg_395e98 =====

undefined8 gpuReadBusConfigReg_395e98(void)

{
  return 0x56;
}


// ===== 00145af0 gpuReadPcieConfigCycle_395e98 =====

undefined8 gpuReadPcieConfigCycle_395e98(void)

{
  return 0x56;
}


// ===== 00145b00 gpuWritePcieConfigCycle_395e98 =====

undefined8 gpuWritePcieConfigCycle_395e98(void)

{
  return 0x56;
}


// ===== 00145b10 gpuGenUgidData_395e98 =====

undefined8 gpuGenUgidData_395e98(void)

{
  return 0x56;
}


// ===== 00145b20 gpuHandleSanityCheckRegReadError_d44104 =====

void gpuHandleSanityCheckRegReadError_d44104(void)

{
  return;
}


// ===== 00145b30 gpuGetSanityCheckRegReadError_d44104 =====

void gpuGetSanityCheckRegReadError_d44104(void)

{
  return;
}


// ===== 00145b40 gpuSanityCheckVirtRegAccess_ac1694 =====

undefined8 gpuSanityCheckVirtRegAccess_ac1694(void)

{
  return 0;
}


// ===== 00145b50 gpuMnocMboxSyncRecv_395e98 =====

undefined8 gpuMnocMboxSyncRecv_395e98(void)

{
  return 0x56;
}


// ===== 00145b60 gpuMnocMboxSend_395e98 =====

undefined8 gpuMnocMboxSend_395e98(void)

{
  return 0x56;
}


// ===== 00145b70 gpuMnocMboxRecv_395e98 =====

undefined8 gpuMnocMboxRecv_395e98(void)

{
  return 0x56;
}


// ===== 00145b80 gpuMnocMboxIsMsgAvailable_d69453 =====

undefined8 gpuMnocMboxIsMsgAvailable_d69453(void)

{
  return 0;
}


// ===== 00145b90 gpuMnocMboxInterruptEnable_d44104 =====

void gpuMnocMboxInterruptEnable_d44104(void)

{
  return;
}


// ===== 00145ba0 gpuFuseSupportsDisplay_e661f0 =====

undefined8 gpuFuseSupportsDisplay_e661f0(void)

{
  return 1;
}


// ===== 00145bb0 gpuIsDebuggerActive_d7131d =====

undefined1 gpuIsDebuggerActive_d7131d(long param_1)

{
  return *(undefined1 *)(param_1 + 0x1b28);
}


// ===== 00145bc0 gpuGetNvlinkLinkDetectionHalFlag_039569 =====

undefined8 gpuGetNvlinkLinkDetectionHalFlag_039569(void)

{
  return 2;
}


// ===== 00145bd0 gpuDetectNvlinkLinkFromGpus_d44104 =====

void gpuDetectNvlinkLinkFromGpus_d44104(void)

{
  return;
}


// ===== 00145be0 gpuGetFirstAsyncLce_77d68d =====

undefined8 gpuGetFirstAsyncLce_77d68d(void)

{
  return 0xb;
}


// ===== 00145bf0 gpuRequireGrCePresence_ac1694 =====

undefined8 gpuRequireGrCePresence_ac1694(void)

{
  return 0;
}


// ===== 00145c00 gpuWaitForBarFirewallHal_e661f0 =====

undefined8 gpuWaitForBarFirewallHal_e661f0(void)

{
  return 1;
}


// ===== 00145c0a __nvoc_init_funcTable_OBJGPU_1.cold =====

void __nvoc_init_funcTable_OBJGPU_1_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00145c20 __nvoc_init_funcTable_OBJGPU_1 =====

/* WARNING: Type propagation algorithm not settling */

void __nvoc_init_funcTable_OBJGPU_1(long param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  sbyte sVar5;
  code *pcVar6;
  short sVar7;
  uint uVar8;
  code *pcVar10;
  ulong uVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcVar14;
  code *pcVar15;
  bool bVar16;
  ulong uVar9;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  uVar1 = *(ushort *)(*(long *)(param_1 + 0x80) + 0x10);
  uVar2 = *(ushort *)(*(long *)(param_1 + 0x88) + 0x10);
  uVar3 = uVar1 >> 5;
  uVar8 = uVar1 & 0x1f;
  uVar9 = (ulong)uVar8;
  uVar4 = (uint)(uVar2 >> 5);
  sVar7 = (short)uVar8;
  sVar5 = (sbyte)uVar8;
  if (uVar3 == 1) {
    if ((0xbdf0fc00UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0xa0) = gpuConstructDeviceInfoTable_ac1694;
      if (uVar2 == 0) {
        *(code **)(param_1 + 0xa8) = gpuGetNameString_VF;
        *(code **)(param_1 + 0xb0) = gpuGetShortNameString_VF;
        *(code **)(param_1 + 0xb8) = gpuInitBranding_VF;
        *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_d44104;
        *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
        goto LAB_001487f7;
      }
LAB_001463a8:
      *(code **)(param_1 + 0xa8) = gpuGetNameString_FWCLIENT;
      *(code **)(param_1 + 0xb0) = gpuGetShortNameString_FWCLIENT;
      *(code **)(param_1 + 0xb8) = gpuInitBranding_FWCLIENT;
      *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_FWCLIENT;
      *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
    }
    else {
LAB_00145e63:
      if (uVar2 == 0) {
        *(code **)(param_1 + 0xa0) = gpuConstructDeviceInfoTable_VF;
        *(code **)(param_1 + 0xa8) = gpuGetNameString_VF;
        *(code **)(param_1 + 0xb0) = gpuGetShortNameString_VF;
        *(code **)(param_1 + 0xb8) = gpuInitBranding_VF;
        *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_d44104;
        *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
        if (uVar3 == 2) goto LAB_001485bc;
LAB_001487f7:
        *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_d69453;
        if ((0x5f0ffe0UL >> uVar9 & 1) == 0) goto LAB_00147be7;
        *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_TU102;
        *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_TU102;
        goto LAB_00147bfd;
      }
      *(code **)(param_1 + 0xa0) = gpuConstructDeviceInfoTable_FWCLIENT;
      *(code **)(param_1 + 0xa8) = gpuGetNameString_FWCLIENT;
      *(code **)(param_1 + 0xb0) = gpuGetShortNameString_FWCLIENT;
      *(code **)(param_1 + 0xb8) = gpuInitBranding_FWCLIENT;
      *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_FWCLIENT;
      *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
      if (uVar3 == 2) goto LAB_00146439;
    }
    *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_d69453;
    if (uVar3 != 1) {
LAB_00146460:
      *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_GB100;
      *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_GB100;
      if (uVar4 == 0) {
        if (uVar2 == 0) goto LAB_00147bfd;
        *(code **)(param_1 + 0xe8) = gpuSetResetScratchBit_GP100;
        *(code **)(param_1 + 0xf0) = gpuGetResetScratchBit_GP100;
        *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_FWCLIENT;
        *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_IMPL;
        *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_IMPL;
        *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_IMPL;
        *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_GA100;
        *(code **)(param_1 + 0x120) = gpuGetDrainAndResetScratchBit_GA100;
        *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_IMPL;
        *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_IMPL;
        *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_IMPL;
        *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_KERNEL;
        if (uVar3 == 2) goto LAB_00147feb;
      }
      else {
        *(code **)(param_1 + 0xe8) = gpuSetResetScratchBit_GP100;
        *(code **)(param_1 + 0xf0) = gpuGetResetScratchBit_GP100;
        *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_FWCLIENT;
        *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_IMPL;
        *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_IMPL;
        *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_IMPL;
        *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_GA100;
        *(code **)(param_1 + 0x120) = gpuGetDrainAndResetScratchBit_GA100;
        *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_IMPL;
        *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_IMPL;
        *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_IMPL;
        *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_KERNEL;
        if (uVar3 == 2) {
          if ((0x300UL >> uVar9 & 1) == 0) {
            *(code **)(param_1 + 0x148) = gpuPowerOff_KERNEL;
            goto LAB_0014704a;
          }
          *(code **)(param_1 + 0x148) = gpuPowerOff_GB20B;
LAB_00147edb:
          *(code **)(param_1 + 0x150) = gpuPowerOn_GB20B;
          pcVar6 = gpuPowerOnHda_GB20B;
          *(code **)(param_1 + 0x158) = gpuPowerOffHda_GB20B;
LAB_00147067:
          *(code **)(param_1 + 0x160) = pcVar6;
          *(code **)(param_1 + 0x168) = gpuGetBusIntfType_2f2c74;
          goto LAB_00147079;
        }
      }
      *(code **)(param_1 + 0x148) = gpuPowerOff_KERNEL;
      *(code **)(param_1 + 0x150) = gpuPowerOn_KERNEL;
      *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
      *(code **)(param_1 + 0x160) = gpuPowerOnHda_395e98;
LAB_00146539:
      *(code **)(param_1 + 0x168) = gpuGetBusIntfType_2f2c74;
LAB_00146544:
      pcVar14 = gpuWriteBusConfigReg_GH100;
      pcVar6 = gpuReadBusConfigReg_GH100;
      goto LAB_00146552;
    }
    if ((0x5f0ffe0UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_GB100;
      *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_GB100;
    }
    else {
      *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_TU102;
      *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_TU102;
    }
    if (uVar4 != 0) {
      *(code **)(param_1 + 0xe8) = gpuSetResetScratchBit_GP100;
      *(code **)(param_1 + 0xf0) = gpuGetResetScratchBit_GP100;
      *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_FWCLIENT;
      *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_IMPL;
      *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_IMPL;
      *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_IMPL;
      if ((0x3e0UL >> uVar9 & 1) == 0) {
        *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_GA100;
        pcVar6 = gpuGetDrainAndResetScratchBit_GA100;
      }
      else {
        *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_395e98;
        pcVar6 = gpuGetDrainAndResetScratchBit_395e98;
      }
      *(code **)(param_1 + 0x120) = pcVar6;
      *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_KERNEL;
LAB_00145f97:
      *(code **)(param_1 + 0x148) = gpuPowerOff_KERNEL;
      *(code **)(param_1 + 0x150) = gpuPowerOn_KERNEL;
      *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
      *(code **)(param_1 + 0x160) = gpuPowerOnHda_395e98;
      *(code **)(param_1 + 0x168) = gpuGetBusIntfType_2f2c74;
      if (uVar3 != 1) goto LAB_00146544;
LAB_00145fe4:
      if ((0x1f0ffe0UL >> uVar9 & 1) == 0) {
        pcVar6 = gpuWriteBusConfigReg_GH100;
        pcVar13 = gpuReadBusConfigReg_GH100;
        pcVar12 = gpuReadBusConfigRegEx_5baef9;
        pcVar10 = gpuReadFunctionConfigReg_5baef9;
        pcVar15 = gpuWriteFunctionConfigReg_5baef9;
        pcVar14 = gpuWriteFunctionConfigRegEx_5baef9;
      }
      else {
        pcVar6 = gpuWriteBusConfigReg_GM107;
        pcVar13 = gpuReadBusConfigReg_GM107;
        pcVar12 = gpuReadBusConfigRegEx_GM107;
        pcVar10 = gpuReadFunctionConfigReg_GM107;
        pcVar15 = gpuWriteFunctionConfigReg_GM107;
        pcVar14 = gpuWriteFunctionConfigRegEx_GM107;
      }
      *(code **)(param_1 + 0x198) = pcVar14;
      *(code **)(param_1 + 0x170) = pcVar6;
      *(code **)(param_1 + 0x178) = pcVar13;
      *(code **)(param_1 + 0x180) = pcVar12;
      *(code **)(param_1 + 0x188) = pcVar10;
      *(code **)(param_1 + 400) = pcVar15;
      if ((0xb8000000UL >> uVar9 & 1) == 0) {
        if (sVar7 != 0x1a) {
          *(code **)(param_1 + 0x1a0) = gpuReadPassThruConfigReg_395e98;
          goto LAB_00146063;
        }
        pcVar14 = gpuReadBusConfigCycle_GM107;
        pcVar6 = gpuWriteBusConfigCycle_GM107;
        *(code **)(param_1 + 0x1a0) = gpuReadPassThruConfigReg_GH100;
        *(code **)(param_1 + 0x1a8) = gpuConfigAccessSanityCheck_ac1694;
      }
      else {
        *(code **)(param_1 + 0x1a0) = gpuReadPassThruConfigReg_GB100;
LAB_00146063:
        pcVar6 = gpuConfigAccessSanityCheck_GB100;
        if ((0x98000000UL >> uVar9 & 1) == 0) {
          pcVar6 = gpuConfigAccessSanityCheck_ac1694;
        }
        pcVar14 = gpuReadBusConfigCycle_GM107;
        *(code **)(param_1 + 0x1a8) = pcVar6;
        bVar16 = (0x18000000UL >> sVar5 & 1) != 0;
        if (bVar16) {
          pcVar14 = gpuReadBusConfigCycle_GB100;
        }
        pcVar6 = gpuWriteBusConfigCycle_GB100;
        if (!bVar16) {
          pcVar6 = gpuWriteBusConfigCycle_GM107;
        }
      }
      *(code **)(param_1 + 0x1b0) = pcVar14;
      *(code **)(param_1 + 0x1b8) = pcVar6;
      *(code **)(param_1 + 0x1c0) = gpuReadPcieConfigCycle_395e98;
      *(code **)(param_1 + 0x1c8) = gpuWritePcieConfigCycle_395e98;
      goto LAB_001460e7;
    }
    if (uVar2 == 0) goto LAB_00147bfd;
    *(code **)(param_1 + 0xe8) = gpuSetResetScratchBit_GP100;
    *(code **)(param_1 + 0xf0) = gpuGetResetScratchBit_GP100;
    *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_FWCLIENT;
    *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_IMPL;
    *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_IMPL;
    *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_IMPL;
    if ((0x3e0UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_GA100;
      pcVar6 = gpuGetDrainAndResetScratchBit_GA100;
LAB_00148741:
      *(code **)(param_1 + 0x120) = pcVar6;
      *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_IMPL;
      if (uVar3 == 3) {
        uVar4 = (uint)(0xa000UL >> sVar5) & 1;
        if ((0xa000UL >> sVar5 & 1) == 0) {
          *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_KERNEL;
        }
        else {
          *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_d44104;
          uVar4 = 0;
        }
        goto LAB_00145df6;
      }
    }
    else {
      *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_395e98;
      *(code **)(param_1 + 0x120) = gpuGetDrainAndResetScratchBit_395e98;
      *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_IMPL;
      *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_IMPL;
    }
    *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_KERNEL;
    if (uVar3 != 2) {
      uVar4 = 0;
      goto LAB_00145f97;
    }
LAB_00147feb:
    uVar4 = (uint)(0x300UL >> sVar5) & 1;
    if ((0x300UL >> sVar5 & 1) == 0) {
      *(code **)(param_1 + 0x148) = gpuPowerOff_KERNEL;
      if (uVar2 != 0) {
LAB_0014704a:
        *(code **)(param_1 + 0x150) = gpuPowerOn_KERNEL;
        pcVar6 = gpuPowerOnHda_395e98;
        *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
        goto LAB_00147067;
      }
    }
    else {
      *(code **)(param_1 + 0x148) = gpuPowerOff_GB20B;
      uVar4 = 0;
      if (uVar2 != 0) goto LAB_00147edb;
    }
    *(code **)(param_1 + 0x150) = gpuPowerOn_395e98;
    uVar4 = 0;
    *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
    *(code **)(param_1 + 0x160) = gpuPowerOnHda_395e98;
    *(code **)(param_1 + 0x168) = gpuGetBusIntfType_28ceda;
LAB_00147079:
    *(code **)(param_1 + 0x170) = gpuWriteBusConfigReg_GH100;
    *(code **)(param_1 + 0x178) = gpuReadBusConfigReg_GH100;
    *(code **)(param_1 + 0x180) = gpuReadBusConfigRegEx_5baef9;
    *(code **)(param_1 + 0x188) = gpuReadFunctionConfigReg_5baef9;
    *(code **)(param_1 + 400) = gpuWriteFunctionConfigReg_5baef9;
    *(code **)(param_1 + 0x198) = gpuWriteFunctionConfigRegEx_5baef9;
    if (uVar1 != 0x40) {
      if (uVar3 == 2) {
        pcVar6 = gpuReadPassThruConfigReg_GH100;
        if ((0x3f8UL >> uVar9 & 1) == 0) {
          pcVar6 = gpuReadPassThruConfigReg_395e98;
        }
        *(code **)(param_1 + 0x1a0) = pcVar6;
        uVar11 = uVar9;
        if ((0xf8UL >> uVar9 & 1) == 0) {
          pcVar6 = gpuConfigAccessSanityCheck_ac1694;
          pcVar15 = gpuReadPcieConfigCycle_395e98;
          pcVar14 = gpuWritePcieConfigCycle_395e98;
        }
        else {
          pcVar6 = gpuConfigAccessSanityCheck_ac1694;
          pcVar15 = gpuReadPcieConfigCycle_GB202;
          pcVar14 = gpuWritePcieConfigCycle_GB202;
        }
        goto LAB_0014711b;
      }
      goto LAB_0014658c;
    }
    pcVar6 = gpuConfigAccessSanityCheck_GB100;
    pcVar15 = gpuReadPcieConfigCycle_395e98;
    pcVar14 = gpuWritePcieConfigCycle_395e98;
    uVar11 = 0;
    *(code **)(param_1 + 0x1a0) = gpuReadPassThruConfigReg_GB100;
LAB_0014711b:
    *(code **)(param_1 + 0x1c8) = pcVar14;
    *(code **)(param_1 + 0x1a8) = pcVar6;
    *(code **)(param_1 + 0x1b0) = gpuReadBusConfigCycle_GM107;
    *(code **)(param_1 + 0x1b8) = gpuWriteBusConfigCycle_GM107;
    *(code **)(param_1 + 0x1c0) = pcVar15;
    if ((0x101UL >> uVar11 & 1) == 0) {
      *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GH100;
      if ((uVar4 != 0) || (uVar2 != 0)) goto LAB_0014681a;
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_VF;
      pcVar6 = gpuGenUgidData_GB100;
      if ((0x3f9UL >> uVar11 & 1) == 0) {
        pcVar6 = gpuGenUgidData_395e98;
      }
      *(code **)(param_1 + 0x1e0) = pcVar6;
LAB_001471a1:
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
      *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
      goto joined_r0x001471c6;
    }
    *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GB100;
    if ((uVar2 == 0) && (uVar4 == 0)) {
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_VF;
      pcVar6 = gpuGenUgidData_GB100;
      if ((0x3f9UL >> uVar9 & 1) == 0) {
        pcVar6 = gpuGenUgidData_395e98;
      }
      *(code **)(param_1 + 0x1e0) = pcVar6;
      goto LAB_001471a1;
    }
LAB_0014681a:
    *(code **)(param_1 + 0x1d8) = gpuGenGidData_FWCLIENT;
    if ((0x3f9UL >> uVar9 & 1) != 0) {
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_GB100;
      if (uVar4 != 0) goto LAB_0014684c;
      goto LAB_00147009;
    }
    *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
    if (uVar4 != 0) {
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
      *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_GH100;
      goto LAB_001472ab;
    }
    if (uVar2 != 0) goto LAB_0014684c;
    *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
    *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
    *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
LAB_001469b2:
    *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_GB100;
    *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
    if (uVar3 == 2) {
      uVar4 = (uint)(0x300UL >> sVar5) & 1;
      if ((0x300UL >> sVar5 & 1) != 0) {
        *(code **)(param_1 + 0x210) = gpuHandleSecFault_GB20B;
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        goto LAB_001469fc;
      }
LAB_001472bb:
      if ((0xf8UL >> uVar9 & 1) == 0) {
        if (sVar7 != 0) {
          pcVar6 = gpuHandleSecFault_d44104;
          goto LAB_001472d2;
        }
        *(code **)(param_1 + 0x210) = gpuHandleSecFault_GB100;
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        if (uVar4 == 0) {
          if (uVar2 != 0) {
LAB_00147f1f:
            *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
            *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
            if (uVar3 == 1) goto LAB_001461eb;
            goto LAB_00147876;
          }
          goto LAB_0014808a;
        }
        *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
        *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
LAB_00147876:
        if (uVar3 == 2) goto LAB_00147303;
LAB_00147880:
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB102;
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB102;
LAB_00147896:
        *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_GB102;
        if ((uVar4 != 0) || (uVar2 != 0)) goto LAB_001478b0;
LAB_00147588:
        pcVar14 = gpuInitSriov_VF;
        uVar4 = 0;
        pcVar6 = gpuDeinitSriov_ac1694;
LAB_00147395:
        *(code **)(param_1 + 0x248) = pcVar14;
        *(code **)(param_1 + 0x250) = pcVar6;
        if (uVar3 == 1) goto LAB_00146243;
        if (uVar3 != 2) goto LAB_001473b7;
        if (sVar7 != 0) goto LAB_0014819e;
        *(code **)(param_1 + 600) = gpuMnocMboxSyncRecv_GB100;
        *(code **)(param_1 + 0x260) = gpuMnocMboxSend_GB100;
        *(code **)(param_1 + 0x268) = gpuMnocMboxRecv_GB100;
        *(code **)(param_1 + 0x270) = gpuMnocMboxIsMsgAvailable_GB100;
        *(code **)(param_1 + 0x278) = gpuMnocMboxInterruptEnable_GB100;
        *(code **)(param_1 + 0x280) = gpuMnocMboxInterruptDisable_GB100;
        *(code **)(param_1 + 0x288) = gpuMnocMboxInterruptRaised_GB100;
        *(code **)(param_1 + 0x290) = gpuMnocMboxInterruptClear_GB100;
        *(code **)(param_1 + 0x298) = gpuMnocMboxMinMessageSize_GB100;
        *(code **)(param_1 + 0x2a0) = gpuMnocMboxMaxMessageSize_GB100;
        if ((uVar4 == 0) && (uVar2 == 0)) {
          *(code **)(param_1 + 0x2a8) = gpuCreateDefaultClientShare_VF;
          *(code **)(param_1 + 0x2b0) = gpuDestroyDefaultClientShare_VF;
        }
        else {
          *(code **)(param_1 + 0x2a8) = gpuCreateDefaultClientShare_ac1694;
          *(code **)(param_1 + 0x2b0) = gpuDestroyDefaultClientShare_d44104;
        }
LAB_0014839c:
        *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_d69453;
        *(code **)(param_1 + 0x2c0) = gpuJtVersionSanityCheck_TU102;
        *(code **)(param_1 + 0x2c8) = gpuValidateRmctrlCmd_ac1694;
        *(code **)(param_1 + 0x2d0) = gpuValidateBusInfoIndex_ac1694;
        *(code **)(param_1 + 0x2d8) = gpuIsDebuggerActive_d7131d;
        *(code **)(param_1 + 0x2e0) = gpuExtdevConstruct_GK104;
LAB_001483de:
        if (sVar7 != 0) {
          *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_d69453;
          if (uVar4 != 0) {
LAB_001483fb:
            *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
            *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
            *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
            *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
            goto LAB_00148427;
          }
          goto LAB_00146b74;
        }
        *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_GH100;
        if (uVar4 != 0) goto LAB_001483fb;
        goto LAB_00146e44;
      }
      pcVar6 = gpuHandleSecFault_GB202;
LAB_001472d2:
      *(code **)(param_1 + 0x210) = pcVar6;
      *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
      if (uVar4 == 0) {
        if (uVar2 != 0) {
          *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
          *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
          if (uVar3 != 1) goto LAB_00147303;
LAB_001461eb:
          if (sVar7 == 6) {
            *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_TU104;
            pcVar6 = gpuGetNoEngClassList_TU104;
            *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU104;
            goto joined_r0x00146216;
          }
          if (sVar7 != 7) goto LAB_001479aa;
          *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_TU106;
          *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU106;
          *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_TU106;
          if ((uVar2 == 0) && (uVar4 == 0)) goto LAB_00148900;
          *(code **)(param_1 + 0x248) = gpuInitSriov_FWCLIENT;
          *(code **)(param_1 + 0x250) = gpuDeinitSriov_FWCLIENT;
          goto LAB_00146aa0;
        }
LAB_0014808a:
        if (uVar3 != 2) {
          *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
          uVar4 = 0;
          *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
          goto LAB_00147880;
        }
        if (sVar7 != 0) {
          uVar4 = (uint)(0x3f8UL >> sVar5) & 1;
          if ((0x3f8UL >> sVar5 & 1) == 0) {
            *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
            bVar16 = true;
            *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
          }
          else {
            *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_GH100;
            uVar4 = 0;
            bVar16 = true;
            *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
          }
          goto LAB_00147309;
        }
        *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_GB100;
        uVar4 = 0;
        bVar16 = true;
        *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB102;
LAB_001489f0:
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB102;
        *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_GB102;
joined_r0x0014737d:
        if ((uVar2 != 0) || (!bVar16)) goto LAB_00147387;
        goto LAB_00147588;
      }
      *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
      *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
LAB_00147303:
      bVar16 = uVar4 == 0;
LAB_00147309:
      pcVar6 = gpuGetChildrenPresent_GB20B;
      if (((0x300UL >> uVar9 & 1) == 0) &&
         (pcVar6 = gpuGetChildrenPresent_GB202, (0xf8UL >> uVar9 & 1) == 0)) {
        pcVar6 = gpuGetChildrenPresent_GB102;
      }
      *(code **)(param_1 + 0x230) = pcVar6;
      if (sVar7 == 8) {
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB20B;
        *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_GB20B;
      }
      else {
        if (sVar7 != 9) {
          if ((0xf8UL >> uVar9 & 1) == 0) goto LAB_001489f0;
          *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB202;
          *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_GB202;
          goto joined_r0x0014737d;
        }
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB20C;
        *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_GB20C;
      }
      if ((uVar2 != 0) || (!bVar16)) {
        *(code **)(param_1 + 0x248) = gpuInitSriov_FWCLIENT;
        *(code **)(param_1 + 0x250) = gpuDeinitSriov_FWCLIENT;
        if (uVar3 != 1) {
          if (uVar3 != 2) goto LAB_001473b7;
          goto LAB_0014819e;
        }
        goto LAB_00146aa0;
      }
      *(code **)(param_1 + 0x248) = gpuInitSriov_VF;
      *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
      if (uVar3 == 1) {
LAB_00148916:
        uVar4 = 0;
        goto LAB_00146aa0;
      }
      if (uVar3 != 2) {
        uVar4 = 0;
        goto LAB_001473b7;
      }
      uVar4 = 0;
LAB_0014819e:
      *(code **)(param_1 + 600) = gpuMnocMboxSyncRecv_395e98;
      *(code **)(param_1 + 0x260) = gpuMnocMboxSend_395e98;
      *(code **)(param_1 + 0x268) = gpuMnocMboxRecv_395e98;
      *(code **)(param_1 + 0x270) = gpuMnocMboxIsMsgAvailable_d69453;
      *(code **)(param_1 + 0x278) = gpuMnocMboxInterruptEnable_d44104;
      *(code **)(param_1 + 0x280) = gpuMnocMboxInterruptDisable_d44104;
      *(code **)(param_1 + 0x288) = gpuMnocMboxInterruptRaised_d69453;
      *(code **)(param_1 + 0x290) = gpuMnocMboxInterruptClear_d44104;
      *(code **)(param_1 + 0x298) = gpuMnocMboxMinMessageSize_edd98b;
      *(code **)(param_1 + 0x2a0) = gpuMnocMboxMaxMessageSize_edd98b;
      if ((uVar4 == 0) && (uVar2 == 0)) {
        *(code **)(param_1 + 0x2a8) = gpuCreateDefaultClientShare_VF;
        *(code **)(param_1 + 0x2b0) = gpuDestroyDefaultClientShare_VF;
      }
      else {
        *(code **)(param_1 + 0x2a8) = gpuCreateDefaultClientShare_ac1694;
        *(code **)(param_1 + 0x2b0) = gpuDestroyDefaultClientShare_d44104;
      }
      if ((0x300UL >> uVar9 & 1) == 0) {
        uVar8 = (uint)(0xf8UL >> sVar5);
        if ((0xf8UL >> sVar5 & 1) == 0) goto LAB_0014839c;
        *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_GB100;
      }
      else {
        *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_e661f0;
        uVar8 = (uint)(0xf8L >> sVar5);
      }
      *(code **)(param_1 + 0x2c0) = gpuJtVersionSanityCheck_TU102;
      *(code **)(param_1 + 0x2c8) = gpuValidateRmctrlCmd_ac1694;
      *(code **)(param_1 + 0x2d0) = gpuValidateBusInfoIndex_ac1694;
      *(code **)(param_1 + 0x2d8) = gpuIsDebuggerActive_d7131d;
      *(code **)(param_1 + 0x2e0) = gpuExtdevConstruct_GK104;
      if ((uVar8 & 1) == 0) goto LAB_001483de;
      *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_GB202;
      if (uVar4 != 0) goto LAB_001483fb;
      if (uVar2 != 0) goto LAB_00146e4e;
      *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_VF;
      *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_d69453;
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_395e98;
    }
    else {
LAB_00146d80:
      *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
      uVar4 = 0;
      if (uVar3 != 3) {
LAB_00147222:
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        goto LAB_001469fc;
      }
LAB_001468a2:
      if ((0xa000UL >> uVar9 & 1) == 0) {
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        if (uVar4 == 0) {
LAB_00147b25:
          *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
          *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
          *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB102;
          goto joined_r0x00147b4a;
        }
LAB_001490cb:
        *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
        *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB102;
        if (sVar7 != 0xd) goto LAB_001468f2;
LAB_00147e05:
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_T234D;
        *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_T234D;
      }
      else {
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_d44104;
        if (uVar4 == 0) goto LAB_001468c5;
LAB_00147dda:
        *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
        *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_T234D;
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_T234D;
        if (sVar7 == 0xd) goto LAB_00147e05;
LAB_001468f2:
        if (sVar7 != 0xf) {
          *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB102;
          goto LAB_00147896;
        }
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_T264D;
        *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_T264D;
        if ((uVar4 == 0) && (uVar2 == 0)) {
          *(code **)(param_1 + 0x248) = gpuInitSriov_VF;
          *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
          goto LAB_001473b7;
        }
      }
LAB_00147e1b:
      *(code **)(param_1 + 0x248) = gpuInitSriov_ac1694;
      *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
LAB_001473b7:
      *(code **)(param_1 + 600) = gpuMnocMboxSyncRecv_395e98;
      if (uVar4 == 0) {
        pcVar6 = gpuCreateDefaultClientShare_VF;
        if (uVar2 != 0) {
          pcVar6 = gpuCreateDefaultClientShare_ac1694;
        }
        pcVar14 = gpuDestroyDefaultClientShare_VF;
        if (uVar2 != 0) {
          pcVar14 = gpuDestroyDefaultClientShare_d44104;
        }
      }
      else {
        pcVar6 = gpuCreateDefaultClientShare_ac1694;
        pcVar14 = gpuDestroyDefaultClientShare_d44104;
      }
      *(code **)(param_1 + 0x260) = gpuMnocMboxSend_395e98;
      *(code **)(param_1 + 0x268) = gpuMnocMboxRecv_395e98;
      *(code **)(param_1 + 0x270) = gpuMnocMboxIsMsgAvailable_d69453;
      *(code **)(param_1 + 0x278) = gpuMnocMboxInterruptEnable_d44104;
      *(code **)(param_1 + 0x280) = gpuMnocMboxInterruptDisable_d44104;
      *(code **)(param_1 + 0x288) = gpuMnocMboxInterruptRaised_d69453;
      *(code **)(param_1 + 0x290) = gpuMnocMboxInterruptClear_d44104;
      *(code **)(param_1 + 0x298) = gpuMnocMboxMinMessageSize_edd98b;
      *(code **)(param_1 + 0x2a0) = gpuMnocMboxMaxMessageSize_edd98b;
      *(code **)(param_1 + 0x2a8) = pcVar6;
      *(code **)(param_1 + 0x2b0) = pcVar14;
      if (uVar3 != 3) {
        if (uVar3 == 1) goto LAB_00146df3;
        *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_d69453;
        *(code **)(param_1 + 0x2c0) = gpuJtVersionSanityCheck_TU102;
        *(code **)(param_1 + 0x2c8) = gpuValidateRmctrlCmd_ac1694;
        *(code **)(param_1 + 0x2d0) = gpuValidateBusInfoIndex_ac1694;
        *(code **)(param_1 + 0x2d8) = gpuIsDebuggerActive_d7131d;
        *(code **)(param_1 + 0x2e0) = gpuExtdevConstruct_GK104;
        *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_d69453;
        if (uVar4 == 0) {
          if (uVar2 == 0) goto LAB_001475a0;
          *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
          if (uVar3 == 3) goto LAB_001476d2;
          *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
          *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
          *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
          goto LAB_001474f4;
        }
        *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
        if (uVar3 != 3) {
          *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
          *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
          *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
          goto LAB_00148427;
        }
        goto LAB_001476d2;
      }
      if ((0xa000UL >> uVar9 & 1) == 0) {
        *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_d69453;
        *(code **)(param_1 + 0x2c0) = gpuJtVersionSanityCheck_TU102;
        *(code **)(param_1 + 0x2c8) = gpuValidateRmctrlCmd_ac1694;
        *(code **)(param_1 + 0x2d0) = gpuValidateBusInfoIndex_ac1694;
        *(code **)(param_1 + 0x2d8) = gpuIsDebuggerActive_d7131d;
        *(code **)(param_1 + 0x2e0) = gpuExtdevConstruct_GK104;
        *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_d69453;
      }
      else {
        *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_e661f0;
        *(code **)(param_1 + 0x2c0) = gpuJtVersionSanityCheck_ac1694;
        *(code **)(param_1 + 0x2c8) = gpuValidateRmctrlCmd_T234D;
        *(code **)(param_1 + 0x2d0) = gpuValidateBusInfoIndex_T234D;
        *(code **)(param_1 + 0x2d8) = gpuIsDebuggerActive_d69453;
        *(code **)(param_1 + 0x2e0) = gpuExtdevConstruct_ac1694;
        *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_d69453;
      }
      if ((uVar4 != 0) || (uVar2 != 0)) {
        *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
        goto LAB_001476d2;
      }
LAB_001475a0:
      *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_VF;
      *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_d69453;
LAB_001475b6:
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_395e98;
      if (uVar3 == 3) {
LAB_001475e4:
        *(code **)(param_1 + 800) = gpuPrePowerOff_395e98;
        *(code **)(param_1 + 0x328) = gpuVerifyExistence_ac1694;
        bVar16 = (0xa000UL >> sVar5 & 1) == 0;
        pcVar6 = gpuCheckIsP2PAllocated_86b752;
        if (bVar16) {
          pcVar6 = gpuCheckIsP2PAllocated_GA100;
        }
        *(code **)(param_1 + 0x318) = pcVar6;
        if (bVar16) {
          *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
          *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
          *(code **)(param_1 + 0x340) = gpuGetFlaVasSize_GH100;
          *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
        }
        else {
          *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_b2b553;
          *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_d44104;
          *(code **)(param_1 + 0x340) = gpuGetFlaVasSize_474d46;
          *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
        }
        goto LAB_00147932;
      }
    }
LAB_00147510:
    *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_GA100;
    *(code **)(param_1 + 800) = gpuPrePowerOff_395e98;
    *(code **)(param_1 + 0x328) = gpuVerifyExistence_ac1694;
    *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
    *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
    *(code **)(param_1 + 0x340) = gpuGetFlaVasSize_GH100;
    if (uVar3 != 2) {
      *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
      *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_VF;
      *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_d69453;
joined_r0x00148964:
      if (uVar3 != 1) {
LAB_00147791:
        *(code **)(param_1 + 0x360) = gpuDetermineSelfHostedMode_d44104;
        return;
      }
      goto LAB_00146c9c;
    }
    pcVar6 = gpuIsAtsSupportedWithSmcMemPartitioning_GH100;
    if ((0x3f9UL >> uVar9 & 1) == 0) {
      pcVar6 = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
    }
    *(code **)(param_1 + 0x348) = pcVar6;
LAB_0014850e:
    *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_VF;
    *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_d69453;
LAB_001484af:
    pcVar6 = gpuDetermineSelfHostedMode_KERNEL_GH100;
    if (uVar1 != 0x40) {
      pcVar6 = gpuDetermineSelfHostedMode_d44104;
    }
    *(code **)(param_1 + 0x360) = pcVar6;
    return;
  }
  if (uVar3 == 2) {
    if ((0x3f9UL >> uVar9 & 1) != 0) goto LAB_00145e63;
    *(code **)(param_1 + 0xa0) = gpuConstructDeviceInfoTable_ac1694;
    if ((uVar4 == 0) && (uVar2 == 0)) {
      *(code **)(param_1 + 0xa8) = gpuGetNameString_VF;
      *(code **)(param_1 + 0xb0) = gpuGetShortNameString_VF;
      *(code **)(param_1 + 0xb8) = gpuInitBranding_VF;
      *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_d44104;
      *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
LAB_001485bc:
      if (sVar7 == 8) {
        *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_GB20B;
        *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_GB100;
        *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_GB100;
      }
      else {
        if (sVar7 != 9) goto LAB_00147bdc;
        *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_GB20C;
        *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_GB100;
        *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_GB100;
      }
      goto LAB_00147bfd;
    }
    *(code **)(param_1 + 0xa8) = gpuGetNameString_FWCLIENT;
    *(code **)(param_1 + 0xb0) = gpuGetShortNameString_FWCLIENT;
    *(code **)(param_1 + 0xb8) = gpuInitBranding_FWCLIENT;
    *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_FWCLIENT;
    *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
LAB_00146439:
    if (sVar7 == 8) {
      *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_GB20B;
    }
    else {
      pcVar6 = gpuIsSocSdmEnabled_GB20C;
      if (sVar7 != 9) {
        pcVar6 = gpuIsSocSdmEnabled_d69453;
      }
      *(code **)(param_1 + 0xd0) = pcVar6;
    }
    goto LAB_00146460;
  }
  *(code **)(param_1 + 0xa0) = gpuConstructDeviceInfoTable_ac1694;
  if (uVar2 == 0) {
    *(code **)(param_1 + 0xa8) = gpuGetNameString_VF;
    *(code **)(param_1 + 0xb0) = gpuGetShortNameString_VF;
    *(code **)(param_1 + 0xb8) = gpuInitBranding_VF;
    *(code **)(param_1 + 0xc0) = gpuGetRtd3GC6Data_d44104;
    if ((uVar3 == 3) && ((0xa000UL >> uVar9 & 1) != 0)) {
      *(code **)(param_1 + 200) = gpuCheckEngine_e661f0;
      *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_d69453;
      *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_395e98;
      *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_d44104;
    }
    else {
      *(code **)(param_1 + 200) = gpuCheckEngine_KERNEL;
LAB_00147bdc:
      *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_d69453;
LAB_00147be7:
      *(code **)(param_1 + 0xd8) = gpuReadPBusScratch_GB100;
      *(code **)(param_1 + 0xe0) = gpuWritePBusScratch_GB100;
    }
LAB_00147bfd:
    *(code **)(param_1 + 0xe8) = gpuSetResetScratchBit_395e98;
    *(code **)(param_1 + 0xf0) = gpuGetResetScratchBit_395e98;
    *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_395e98;
    *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_395e98;
    *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_395e98;
    *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_395e98;
    *(code **)(param_1 + 0x118) = gpuSetDrainAndResetScratchBit_395e98;
    *(code **)(param_1 + 0x120) = gpuGetDrainAndResetScratchBit_395e98;
    *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_395e98;
    *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_395e98;
    *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_395e98;
    if (uVar3 != 3) {
      *(code **)(param_1 + 0x140) = gpuRefreshRecoveryAction_KERNEL;
      *(code **)(param_1 + 0x148) = gpuPowerOff_395e98;
      *(code **)(param_1 + 0x150) = gpuPowerOn_395e98;
      *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
      *(code **)(param_1 + 0x160) = gpuPowerOnHda_395e98;
      *(code **)(param_1 + 0x168) = gpuGetBusIntfType_28ceda;
      if (uVar3 == 1) {
        uVar4 = 0;
        goto LAB_00145fe4;
      }
      uVar4 = 0;
      goto LAB_00147079;
    }
    *(code **)(param_1 + 0x148) = gpuPowerOff_395e98;
    *(code **)(param_1 + 0x150) = gpuPowerOn_395e98;
    pcVar6 = gpuRefreshRecoveryAction_d44104;
    *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
    uVar4 = (uint)(0xa000UL >> sVar5) & 1;
    bVar16 = (0xa000UL >> sVar5 & 1) == 0;
    *(code **)(param_1 + 0x160) = gpuPowerOnHda_395e98;
    if (bVar16) {
      pcVar6 = gpuRefreshRecoveryAction_KERNEL;
    }
    *(code **)(param_1 + 0x168) = gpuGetBusIntfType_28ceda;
    *(code **)(param_1 + 0x140) = pcVar6;
    if (bVar16) goto LAB_00146544;
    pcVar14 = gpuWriteBusConfigReg_395e98;
    uVar4 = 0;
    pcVar6 = gpuReadBusConfigReg_395e98;
  }
  else {
    if (uVar3 != 3) goto LAB_001463a8;
    if ((0xa000UL >> uVar9 & 1) == 0) {
      pcVar6 = gpuGetShortNameString_FWCLIENT;
      pcVar14 = gpuInitBranding_FWCLIENT;
      *(code **)(param_1 + 0xa8) = gpuGetNameString_FWCLIENT;
      pcVar15 = gpuGetRtd3GC6Data_FWCLIENT;
      if (uVar4 == 0) {
        pcVar13 = gpuCheckEngine_KERNEL;
        pcVar12 = gpuReadPBusScratch_GB100;
        pcVar10 = gpuWritePBusScratch_GB100;
LAB_0014866d:
        *(code **)(param_1 + 0xe0) = pcVar10;
        *(code **)(param_1 + 0xb0) = pcVar6;
        bVar16 = (0xa000UL >> sVar5 & 1) == 0;
        *(code **)(param_1 + 200) = pcVar13;
        pcVar10 = gpuSetResetScratchBit_395e98;
        pcVar6 = gpuSetDrainAndResetScratchBit_395e98;
        if (bVar16) {
          pcVar10 = gpuSetResetScratchBit_GP100;
        }
        *(code **)(param_1 + 0xd8) = pcVar12;
        pcVar12 = gpuGetResetScratchBit_395e98;
        if (bVar16) {
          pcVar12 = gpuGetResetScratchBit_GP100;
        }
        *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_d69453;
        if (bVar16) {
          pcVar6 = gpuSetDrainAndResetScratchBit_GA100;
        }
        *(code **)(param_1 + 0xe8) = pcVar10;
        *(code **)(param_1 + 0xf0) = pcVar12;
        *(code **)(param_1 + 0x118) = pcVar6;
        pcVar6 = gpuGetDrainAndResetScratchBit_395e98;
        *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_FWCLIENT;
        if (bVar16) {
          pcVar6 = gpuGetDrainAndResetScratchBit_GA100;
        }
        *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_IMPL;
        *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_IMPL;
        *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_IMPL;
        *(code **)(param_1 + 0xb8) = pcVar14;
        *(code **)(param_1 + 0xc0) = pcVar15;
        goto LAB_00148741;
      }
      pcVar13 = gpuCheckEngine_KERNEL;
      pcVar12 = gpuReadPBusScratch_GB100;
      pcVar10 = gpuWritePBusScratch_GB100;
    }
    else {
      pcVar6 = gpuGetShortNameString_T234D;
      pcVar14 = gpuInitBranding_ac1694;
      *(code **)(param_1 + 0xa8) = gpuGetNameString_T234D;
      pcVar15 = gpuGetRtd3GC6Data_d44104;
      if (uVar4 == 0) {
        pcVar13 = gpuCheckEngine_e661f0;
        pcVar12 = gpuReadPBusScratch_395e98;
        pcVar10 = gpuWritePBusScratch_d44104;
        goto LAB_0014866d;
      }
      pcVar13 = gpuCheckEngine_e661f0;
      pcVar12 = gpuReadPBusScratch_395e98;
      pcVar10 = gpuWritePBusScratch_d44104;
    }
    *(code **)(param_1 + 0xe0) = pcVar10;
    *(code **)(param_1 + 0xb0) = pcVar6;
    *(code **)(param_1 + 0xb8) = pcVar14;
    *(code **)(param_1 + 0xc0) = pcVar15;
    *(code **)(param_1 + 200) = pcVar13;
    *(code **)(param_1 + 0xd0) = gpuIsSocSdmEnabled_d69453;
    *(code **)(param_1 + 0xd8) = pcVar12;
    if ((0xa000UL >> uVar9 & 1) == 0) {
      pcVar6 = gpuSetResetScratchBit_GP100;
      pcVar15 = gpuGetResetScratchBit_GP100;
      pcVar14 = gpuSetDrainAndResetScratchBit_GA100;
    }
    else {
      pcVar6 = gpuSetResetScratchBit_395e98;
      pcVar15 = gpuGetResetScratchBit_395e98;
      pcVar14 = gpuSetDrainAndResetScratchBit_395e98;
    }
    *(code **)(param_1 + 0x118) = pcVar14;
    *(code **)(param_1 + 0xf0) = pcVar15;
    bVar16 = (0xa000UL >> sVar5 & 1) == 0;
    pcVar14 = gpuGetDrainAndResetScratchBit_395e98;
    *(code **)(param_1 + 0xe8) = pcVar6;
    *(code **)(param_1 + 0xf8) = gpuResetRequiredStateChanged_FWCLIENT;
    if (bVar16) {
      pcVar14 = gpuGetDrainAndResetScratchBit_GA100;
    }
    *(code **)(param_1 + 0x100) = gpuMarkDeviceForReset_IMPL;
    *(code **)(param_1 + 0x120) = pcVar14;
    pcVar6 = gpuRefreshRecoveryAction_d44104;
    *(code **)(param_1 + 0x108) = gpuUnmarkDeviceForReset_IMPL;
    if (bVar16) {
      pcVar6 = gpuRefreshRecoveryAction_KERNEL;
    }
    *(code **)(param_1 + 0x110) = gpuIsDeviceMarkedForReset_IMPL;
    *(code **)(param_1 + 0x128) = gpuMarkDeviceForDrainAndReset_IMPL;
    *(code **)(param_1 + 0x130) = gpuUnmarkDeviceForDrainAndReset_IMPL;
    *(code **)(param_1 + 0x138) = gpuIsDeviceMarkedForDrainAndReset_IMPL;
    *(code **)(param_1 + 0x140) = pcVar6;
LAB_00145df6:
    *(code **)(param_1 + 0x148) = gpuPowerOff_KERNEL;
    *(code **)(param_1 + 0x150) = gpuPowerOn_KERNEL;
    *(code **)(param_1 + 0x158) = gpuPowerOffHda_395e98;
    *(code **)(param_1 + 0x160) = gpuPowerOnHda_395e98;
    if ((0xa000UL >> uVar9 & 1) == 0) goto LAB_00146539;
    pcVar14 = gpuWriteBusConfigReg_395e98;
    pcVar6 = gpuReadBusConfigReg_395e98;
    *(code **)(param_1 + 0x168) = gpuGetBusIntfType_f222ee;
  }
LAB_00146552:
  *(code **)(param_1 + 0x170) = pcVar14;
  *(code **)(param_1 + 0x178) = pcVar6;
  *(code **)(param_1 + 0x180) = gpuReadBusConfigRegEx_5baef9;
  *(code **)(param_1 + 0x188) = gpuReadFunctionConfigReg_5baef9;
  *(code **)(param_1 + 400) = gpuWriteFunctionConfigReg_5baef9;
  *(code **)(param_1 + 0x198) = gpuWriteFunctionConfigRegEx_5baef9;
LAB_0014658c:
  *(code **)(param_1 + 0x1a0) = gpuReadPassThruConfigReg_395e98;
  *(code **)(param_1 + 0x1a8) = gpuConfigAccessSanityCheck_ac1694;
  *(code **)(param_1 + 0x1b0) = gpuReadBusConfigCycle_GM107;
  *(code **)(param_1 + 0x1b8) = gpuWriteBusConfigCycle_GM107;
  *(code **)(param_1 + 0x1c0) = gpuReadPcieConfigCycle_395e98;
  *(code **)(param_1 + 0x1c8) = gpuWritePcieConfigCycle_395e98;
  if (uVar3 == 3) {
    if (sVar7 == 0xd) {
      *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_T234D;
      if (uVar4 == 0) {
        if (uVar2 == 0) {
LAB_00148d10:
          *(code **)(param_1 + 0x1d8) = gpuGenGidData_VF;
          *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
          *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
          *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
          goto LAB_00148d3c;
        }
        *(code **)(param_1 + 0x1d8) = gpuGenGidData_SOC;
        uVar11 = 0xd;
        *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
        *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
        *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
LAB_00147adf:
        if ((0xa000UL >> uVar11 & 1) == 0) {
          *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
          *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
          *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_GH100;
          *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
          *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        }
        else {
LAB_00148b50:
          *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_b2b553;
          *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
          *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
          *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
          if ((0xa000UL >> uVar11 & 1) != 0) goto LAB_00148b8b;
          *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        }
        goto LAB_00147b25;
      }
LAB_00147d64:
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_SOC;
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
LAB_00147d93:
      *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_b2b553;
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
      *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
      if ((0xa000UL >> uVar9 & 1) == 0) {
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        goto LAB_001490cb;
      }
      *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_d44104;
      goto LAB_00147dda;
    }
    if (sVar7 == 0xf) {
      *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_T264D;
      if (uVar4 == 0) {
        if (uVar2 != 0) {
          *(code **)(param_1 + 0x1d8) = gpuGenGidData_SOC;
          uVar11 = 0xf;
          *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
          *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
          *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
          goto LAB_00148b50;
        }
        goto LAB_00148d10;
      }
      goto LAB_00147d64;
    }
    *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GH100;
    if ((uVar2 == 0) && (uVar4 == 0)) {
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_VF;
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
      uVar11 = 0xa000L >> uVar9;
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
    }
    else {
      pcVar6 = gpuGenGidData_SOC;
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
      uVar11 = 0xa000L >> sVar5;
      if ((uVar11 & 1) == 0) {
        pcVar6 = gpuGenGidData_FWCLIENT;
      }
      *(code **)(param_1 + 0x1d8) = pcVar6;
      if (uVar4 != 0) {
        *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
        *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
        if ((uVar11 & 1) != 0) goto LAB_00147d93;
        *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
        *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
        *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_GH100;
        *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        goto LAB_001490cb;
      }
      if (uVar2 != 0) {
        *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
        *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
        uVar11 = uVar9;
        goto LAB_00147adf;
      }
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
    }
    if ((uVar11 & 1) == 0) goto LAB_00146d5f;
LAB_00148d3c:
    *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_b2b553;
    *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_395e98;
    *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
    *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
LAB_00148b8b:
    *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_d44104;
LAB_001468c5:
    *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
    *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_T234D;
    *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_T234D;
joined_r0x00147b4a:
    if (sVar7 != 0xd) {
      uVar4 = 0;
      goto LAB_001468f2;
    }
    *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_T234D;
    *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_T234D;
    if (uVar2 == 0) {
      *(code **)(param_1 + 0x248) = gpuInitSriov_VF;
      uVar4 = 0;
      *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
    }
    else {
      *(code **)(param_1 + 0x248) = gpuInitSriov_ac1694;
      uVar4 = 0;
      *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
    }
    goto LAB_001473b7;
  }
  if (uVar3 != 1) {
    *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GH100;
    if ((uVar2 == 0) && (uVar4 == 0)) {
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_VF;
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
LAB_00146d5f:
      *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_GB100;
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
      goto LAB_00146d80;
    }
    *(code **)(param_1 + 0x1d8) = gpuGenGidData_FWCLIENT;
    *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
    if (uVar4 == 0) {
LAB_0014661b:
      if (uVar2 == 0) goto LAB_00146987;
LAB_00146625:
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
      *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
      if (uVar3 == 1) {
        uVar4 = 0;
        goto LAB_0014616f;
      }
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_GH100;
      if (uVar3 == 2) {
        uVar4 = 0;
        goto LAB_001472ab;
      }
      *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
      uVar4 = 0;
    }
    else {
LAB_0014684c:
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
      *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
LAB_00146878:
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_GH100;
      if (uVar3 == 2) {
LAB_001472ab:
        if ((0x300UL >> uVar9 & 1) == 0) goto LAB_001472bb;
        pcVar6 = gpuHandleSecFault_GB20B;
        goto LAB_001472d2;
      }
      *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
      if (uVar3 == 3) goto LAB_001468a2;
    }
    *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
    if (uVar4 == 0) goto LAB_001469fc;
    *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
    *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
    *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB102;
    *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB102;
    *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_GB102;
LAB_001478b0:
    if (uVar3 == 3) {
      if ((0xa000UL >> uVar9 & 1) != 0) goto LAB_00147e1b;
      *(code **)(param_1 + 0x248) = gpuInitSriov_FWCLIENT;
      *(code **)(param_1 + 0x250) = gpuDeinitSriov_FWCLIENT;
      goto LAB_001473b7;
    }
LAB_00147387:
    pcVar14 = gpuInitSriov_FWCLIENT;
    pcVar6 = gpuDeinitSriov_FWCLIENT;
    goto LAB_00147395;
  }
LAB_001460e7:
  if ((0x1f0ffe0UL >> uVar9 & 1) != 0) {
    *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GM107;
    if (uVar4 == 0) {
      if (uVar2 == 0) goto LAB_00146962;
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_FWCLIENT;
      if ((0xb8000000UL >> uVar9 & 1) == 0) {
        *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
        goto LAB_00146625;
      }
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_GB100;
    }
    else {
      *(code **)(param_1 + 0x1d8) = gpuGenGidData_FWCLIENT;
      pcVar6 = gpuGenUgidData_GB100;
      if ((0xb8000000UL >> uVar9 & 1) == 0) {
        pcVar6 = gpuGenUgidData_395e98;
      }
      *(code **)(param_1 + 0x1e0) = pcVar6;
    }
    goto LAB_00146139;
  }
  if ((0x98000000UL >> uVar9 & 1) == 0) {
    *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GH100;
  }
  else {
    *(code **)(param_1 + 0x1d0) = gpuGetIdInfo_GB100;
  }
  if ((uVar4 == 0) && (uVar2 == 0)) {
LAB_00146962:
    *(code **)(param_1 + 0x1d8) = gpuGenGidData_VF;
    if ((0xb8000000UL >> uVar9 & 1) != 0) {
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_GB100;
      goto LAB_001471a1;
    }
    *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
LAB_00146987:
    *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_b2b553;
    *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_VF;
    *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
joined_r0x001471c6:
    if (uVar3 != 1) goto LAB_001469b2;
    if ((0x5f0ffe0UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_GB100;
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
      if (sVar7 != 0x1a) goto LAB_001471fe;
LAB_00148c30:
      pcVar6 = gpuHandleSecFault_GH100;
    }
    else {
      *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_TU102;
      *(code **)(param_1 + 0x208) = gpuHandleSanityCheckRegReadError_d44104;
      if (sVar7 == 0x1a) goto LAB_00148c30;
LAB_001471fe:
      if (sVar7 != 0x1d) {
        if ((0x98000000UL >> uVar9 & 1) == 0) {
          *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
          goto LAB_00147222;
        }
        *(code **)(param_1 + 0x210) = gpuHandleSecFault_GB100;
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        goto LAB_001469fc;
      }
      pcVar6 = gpuHandleSecFault_GB10B;
    }
    *(code **)(param_1 + 0x210) = pcVar6;
    *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
    if (uVar2 == 0) {
LAB_00148fd8:
      uVar4 = (uint)(0x24000000UL >> sVar5) & 1;
      if ((0x24000000UL >> sVar5 & 1) == 0) {
LAB_001461d5:
        *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
        *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
        goto LAB_001461eb;
      }
      *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_GH100;
      *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
joined_r0x00148e92:
      if (sVar7 == 6) {
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_TU104;
        pcVar6 = gpuGetNoEngClassList_TU104;
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU104;
LAB_00149026:
        pcVar15 = gpuInitSriov_VF;
        uVar4 = 0;
        pcVar14 = gpuDeinitSriov_ac1694;
        goto LAB_0014622e;
      }
      if (sVar7 != 7) {
        uVar4 = 0;
        if (sVar7 == 10) goto LAB_00146910;
        uVar4 = 0;
        if (sVar7 != 0x1a) goto LAB_001479be;
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GH100;
        uVar4 = 0;
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GH100;
        goto LAB_00147ebb;
      }
      *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_TU106;
      *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU106;
      *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_TU106;
LAB_00148900:
      *(code **)(param_1 + 0x248) = gpuInitSriov_VF;
      *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
      goto LAB_00148916;
    }
    *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
    uVar4 = 0;
    *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
LAB_001479aa:
    if (sVar7 == 10) {
LAB_00146910:
      *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GA100;
      pcVar6 = gpuGetNoEngClassList_GA100;
      *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GA100;
joined_r0x00146216:
      if ((uVar2 != 0) || (uVar4 != 0)) goto LAB_00146220;
    }
    else {
      if (sVar7 == 0x1a) goto LAB_00147ea5;
LAB_001479be:
      if (sVar7 == 0x1d) goto LAB_00148865;
      if ((0x88000000UL >> sVar5 & 1) == 0) {
        pcVar6 = gpuGetChildrenPresent_TU102;
        if ((((800UL >> uVar9 & 1) == 0) &&
            (pcVar6 = gpuGetChildrenPresent_GA102, (0xf800UL >> uVar9 & 1) == 0)) &&
           (pcVar6 = gpuGetChildrenPresent_AD102, (0x1f00000UL >> uVar9 & 1) == 0)) {
          pcVar6 = gpuGetChildrenPresent_GB102;
        }
        *(code **)(param_1 + 0x230) = pcVar6;
      }
      else {
        *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB100;
      }
      if (sVar7 == 9) {
        *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU117;
        pcVar6 = gpuGetNoEngClassList_TU117;
      }
      else {
        pcVar6 = gpuGetEngClassDescriptorList_TU102;
        if ((((0x120UL >> uVar9 & 1) == 0) &&
            (pcVar6 = gpuGetEngClassDescriptorList_GB100, (0x88000000UL >> sVar5 & 1) == 0)) &&
           ((pcVar6 = gpuGetEngClassDescriptorList_GA102, (0xf800UL >> uVar9 & 1) == 0 &&
            (pcVar6 = gpuGetEngClassDescriptorList_AD102, (0x1f00000UL >> uVar9 & 1) == 0)))) {
          pcVar6 = gpuGetEngClassDescriptorList_GB102;
        }
        *(code **)(param_1 + 0x238) = pcVar6;
        if ((0x120UL >> uVar9 & 1) == 0) {
          if ((0x88000000UL >> uVar9 & 1) == 0) {
            if ((0xf800UL >> uVar9 & 1) != 0) {
              pcVar6 = gpuGetNoEngClassList_GA102;
              if (uVar4 == 0 && uVar2 == 0) goto LAB_00149026;
              goto LAB_00146220;
            }
            if ((0x1f00000UL >> uVar9 & 1) == 0) goto LAB_00147896;
            pcVar6 = gpuGetNoEngClassList_AD102;
          }
          else {
            pcVar6 = gpuGetNoEngClassList_GB100;
          }
          if (uVar4 != 0 || uVar2 != 0) goto LAB_00146220;
          goto LAB_00146940;
        }
        pcVar6 = gpuGetNoEngClassList_TU102;
      }
joined_r0x00148e68:
      if ((uVar4 != 0) || (uVar2 != 0)) goto LAB_00146220;
    }
LAB_00146940:
    pcVar15 = gpuInitSriov_VF;
    pcVar14 = gpuDeinitSriov_ac1694;
  }
  else {
    *(code **)(param_1 + 0x1d8) = gpuGenGidData_FWCLIENT;
    if ((0xb8000000UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_395e98;
      if (uVar4 == 0) goto LAB_0014661b;
LAB_00146139:
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
    }
    else {
      *(code **)(param_1 + 0x1e0) = gpuGenUgidData_GB100;
      if (uVar4 != 0) goto LAB_00146139;
LAB_00147009:
      if (uVar2 == 0) goto LAB_001471a1;
      *(code **)(param_1 + 0x1e8) = gpuGetChipSubRev_FWCLIENT;
      uVar4 = 0;
      *(code **)(param_1 + 0x1f0) = gpuGetSkuInfo_92bfc3;
    }
    *(code **)(param_1 + 0x1f8) = gpuGetVirtRegPhysOffset_TU102;
    *(code **)(param_1 + 0x200) = gpuGetRegBaseOffset_FWCLIENT;
    if (uVar3 != 1) goto LAB_00146878;
LAB_0014616f:
    pcVar6 = gpuHandleSanityCheckRegReadError_GM107;
    if ((0x1f0ffe0UL >> uVar9 & 1) == 0) {
      pcVar6 = gpuHandleSanityCheckRegReadError_GH100;
    }
    *(code **)(param_1 + 0x208) = pcVar6;
    if (sVar7 == 0x1a) {
      *(code **)(param_1 + 0x210) = gpuHandleSecFault_GH100;
      *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
      if ((uVar4 == 0) && (uVar2 == 0)) {
LAB_00146a13:
        uVar4 = (uint)(0x1f0ffe0UL >> sVar5) & 1;
        if ((0x1f0ffe0UL >> sVar5 & 1) != 0) {
          *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_TU102;
          *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
          goto joined_r0x00148e92;
        }
        if ((0x98000000UL >> uVar9 & 1) == 0) goto LAB_00148fd8;
        *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_GB100;
        *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
        if (sVar7 == 6) {
          *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_TU104;
          *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU104;
          *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_TU104;
          *(code **)(param_1 + 0x248) = gpuInitSriov_VF;
          *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
        }
        else {
          if (sVar7 != 7) goto LAB_001479aa;
          *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_TU106;
          *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_TU106;
          *(code **)(param_1 + 0x240) = gpuGetNoEngClassList_TU106;
          *(code **)(param_1 + 0x248) = gpuInitSriov_VF;
          *(code **)(param_1 + 0x250) = gpuDeinitSriov_ac1694;
        }
        goto LAB_00146aa0;
      }
      *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
      *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
LAB_00147ea5:
      *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GH100;
      *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GH100;
LAB_00147ebb:
      pcVar6 = gpuGetNoEngClassList_GH100;
      goto joined_r0x00148e68;
    }
    if (sVar7 != 0x1d) {
      if ((0x98000000UL >> uVar9 & 1) != 0) {
        *(code **)(param_1 + 0x210) = gpuHandleSecFault_GB100;
        *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
        if (uVar4 != 0) goto LAB_00147f1f;
LAB_001469fc:
        if (uVar2 != 0) {
          uVar4 = 0;
          goto LAB_00147f1f;
        }
        if (uVar3 != 1) goto LAB_0014808a;
        goto LAB_00146a13;
      }
      *(code **)(param_1 + 0x210) = gpuHandleSecFault_d44104;
      *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
      if (uVar4 == 0) goto LAB_001469fc;
      goto LAB_001461d5;
    }
    *(code **)(param_1 + 0x210) = gpuHandleSecFault_GB10B;
    *(code **)(param_1 + 0x218) = gpuGetSanityCheckRegReadError_GM107;
    if ((uVar4 == 0) && (uVar2 == 0)) goto LAB_00146a13;
    *(code **)(param_1 + 0x220) = gpuSanityCheckVirtRegAccess_ac1694;
    *(code **)(param_1 + 0x228) = gpuGetChildrenOrder_GM200;
LAB_00148865:
    *(code **)(param_1 + 0x230) = gpuGetChildrenPresent_GB10B;
    *(code **)(param_1 + 0x238) = gpuGetEngClassDescriptorList_GB10B;
    if ((uVar2 == 0) && (uVar4 == 0)) {
      pcVar6 = gpuGetNoEngClassList_GB10B;
      pcVar15 = gpuInitSriov_VF;
      pcVar14 = gpuDeinitSriov_ac1694;
    }
    else {
      pcVar6 = gpuGetNoEngClassList_GB10B;
LAB_00146220:
      pcVar15 = gpuInitSriov_FWCLIENT;
      pcVar14 = gpuDeinitSriov_FWCLIENT;
    }
  }
LAB_0014622e:
  *(code **)(param_1 + 0x240) = pcVar6;
  *(code **)(param_1 + 0x248) = pcVar15;
  *(code **)(param_1 + 0x250) = pcVar14;
LAB_00146243:
  if ((0x98000000UL >> uVar9 & 1) == 0) {
LAB_00146aa0:
    *(code **)(param_1 + 600) = gpuMnocMboxSyncRecv_395e98;
    *(code **)(param_1 + 0x260) = gpuMnocMboxSend_395e98;
    *(code **)(param_1 + 0x268) = gpuMnocMboxRecv_395e98;
    *(code **)(param_1 + 0x270) = gpuMnocMboxIsMsgAvailable_d69453;
    *(code **)(param_1 + 0x278) = gpuMnocMboxInterruptEnable_d44104;
    *(code **)(param_1 + 0x280) = gpuMnocMboxInterruptDisable_d44104;
    *(code **)(param_1 + 0x288) = gpuMnocMboxInterruptRaised_d69453;
    *(code **)(param_1 + 0x290) = gpuMnocMboxInterruptClear_d44104;
    *(code **)(param_1 + 0x298) = gpuMnocMboxMinMessageSize_edd98b;
    *(code **)(param_1 + 0x2a0) = gpuMnocMboxMaxMessageSize_edd98b;
    if (uVar4 == 0) goto LAB_00146e10;
    pcVar14 = gpuCreateDefaultClientShare_ac1694;
    pcVar6 = gpuDestroyDefaultClientShare_d44104;
LAB_00146b25:
    *(code **)(param_1 + 0x2b0) = pcVar6;
    *(code **)(param_1 + 0x2a8) = pcVar14;
    if ((0x3e0UL >> uVar9 & 1) == 0) {
LAB_00146b43:
      if ((0x1f0f800UL >> uVar9 & 1) == 0) {
LAB_00146df3:
        pcVar6 = gpuFuseSupportsDisplay_d69453;
        if (sVar7 == 0x1d) {
          pcVar6 = gpuFuseSupportsDisplay_GB100;
        }
      }
      else {
        pcVar6 = gpuFuseSupportsDisplay_GA100;
      }
      goto LAB_001462f7;
    }
    *(code **)(param_1 + 0x2b8) = gpuFuseSupportsDisplay_GM107;
  }
  else {
    *(code **)(param_1 + 600) = gpuMnocMboxSyncRecv_GB100;
    *(code **)(param_1 + 0x260) = gpuMnocMboxSend_GB100;
    *(code **)(param_1 + 0x268) = gpuMnocMboxRecv_GB100;
    *(code **)(param_1 + 0x270) = gpuMnocMboxIsMsgAvailable_GB100;
    *(code **)(param_1 + 0x278) = gpuMnocMboxInterruptEnable_GB100;
    *(code **)(param_1 + 0x280) = gpuMnocMboxInterruptDisable_GB100;
    *(code **)(param_1 + 0x288) = gpuMnocMboxInterruptRaised_GB100;
    *(code **)(param_1 + 0x290) = gpuMnocMboxInterruptClear_GB100;
    *(code **)(param_1 + 0x298) = gpuMnocMboxMinMessageSize_GB100;
    *(code **)(param_1 + 0x2a0) = gpuMnocMboxMaxMessageSize_GB100;
    if (uVar4 == 0) {
LAB_00146e10:
      if (uVar2 == 0) {
        pcVar14 = gpuCreateDefaultClientShare_VF;
        pcVar6 = gpuDestroyDefaultClientShare_VF;
        uVar4 = 0;
      }
      else {
        pcVar14 = gpuCreateDefaultClientShare_ac1694;
        pcVar6 = gpuDestroyDefaultClientShare_d44104;
        uVar4 = 0;
      }
      goto LAB_00146b25;
    }
    *(code **)(param_1 + 0x2a8) = gpuCreateDefaultClientShare_ac1694;
    *(code **)(param_1 + 0x2b0) = gpuDestroyDefaultClientShare_d44104;
    if ((0x3e0UL >> uVar9 & 1) == 0) goto LAB_00146b43;
    pcVar6 = gpuFuseSupportsDisplay_GM107;
LAB_001462f7:
    *(code **)(param_1 + 0x2b8) = pcVar6;
  }
  *(code **)(param_1 + 0x2c0) = gpuJtVersionSanityCheck_TU102;
  *(code **)(param_1 + 0x2c8) = gpuValidateRmctrlCmd_ac1694;
  *(code **)(param_1 + 0x2d0) = gpuValidateBusInfoIndex_ac1694;
  *(code **)(param_1 + 0x2d8) = gpuIsDebuggerActive_d7131d;
  *(code **)(param_1 + 0x2e0) = gpuExtdevConstruct_GK104;
  if ((0x9c000000UL >> uVar9 & 1) == 0) {
    *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_d69453;
    if (uVar4 == 0) {
LAB_00146b74:
      uVar4 = 0;
      if (uVar2 == 0) goto LAB_00146b80;
    }
    *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
    if (uVar3 != 3) {
      *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
      if (uVar3 == 1) {
LAB_00146e70:
        if ((0x4000400UL >> uVar9 & 1) == 0) {
          *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
          *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
        }
        else {
          *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_GA100;
          *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_GA100;
        }
        if (uVar2 == 0 && uVar4 == 0) {
LAB_00148110:
          *(code **)(param_1 + 0x310) = gpuGetSriovCaps_395e98;
          goto LAB_00146bd3;
        }
        *(code **)(param_1 + 0x310) = gpuGetSriovCaps_TU102;
        if ((uVar4 != 0) || (uVar2 != 0)) goto LAB_00146f70;
        pcVar6 = gpuCheckIsP2PAllocated_86b752;
        if ((0x3e0UL >> uVar9 & 1) == 0) {
          pcVar6 = gpuCheckIsP2PAllocated_GA100;
        }
        *(code **)(param_1 + 0x318) = pcVar6;
        goto LAB_00146ef0;
      }
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      if (uVar4 != 0) goto LAB_00148427;
LAB_001474f4:
      if (uVar2 != 0) goto LAB_001493e1;
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_395e98;
      goto LAB_00147510;
    }
LAB_001476d2:
    if ((0xa000UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      if ((uVar4 == 0) && (uVar2 == 0)) goto LAB_001488aa;
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_TU102;
      *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_d69453;
      *(code **)(param_1 + 800) = gpuPrePowerOff_ac1694;
    }
    else {
      *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_d69453;
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      if ((uVar4 == 0) && (uVar2 == 0)) {
LAB_001488aa:
        *(code **)(param_1 + 0x310) = gpuGetSriovCaps_395e98;
        goto LAB_001475e4;
      }
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_GM107;
      *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_d69453;
      *(code **)(param_1 + 800) = gpuPrePowerOff_ac1694;
    }
    if ((0xa000UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x328) = gpuVerifyExistence_IMPL;
      *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
      *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
      *(code **)(param_1 + 0x340) = gpuGetFlaVasSize_GH100;
      *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
    }
    else {
      *(code **)(param_1 + 0x328) = gpuVerifyExistence_ac1694;
      *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_b2b553;
      *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_d44104;
      *(code **)(param_1 + 0x340) = gpuGetFlaVasSize_474d46;
      *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
    }
    if ((uVar4 != 0) || (uVar2 != 0)) {
      *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_FWCLIENT;
      *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_FWCLIENT;
      goto LAB_00147791;
    }
LAB_00147932:
    *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_VF;
    *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_d69453;
    goto LAB_00147791;
  }
  *(code **)(param_1 + 0x2e8) = gpuIsGspToBootInInstInSysMode_GH100;
  if (uVar4 == 0) {
LAB_00146e44:
    if (uVar2 != 0) {
LAB_00146e4e:
      *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
      *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
      if (uVar3 == 1) {
        uVar4 = 0;
        goto LAB_00146e70;
      }
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
LAB_001493e1:
      uVar4 = 0;
LAB_00148427:
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_TU102;
      *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_d69453;
      *(code **)(param_1 + 800) = gpuPrePowerOff_ac1694;
      *(code **)(param_1 + 0x328) = gpuVerifyExistence_IMPL;
      *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
      *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
      *(code **)(param_1 + 0x340) = gpuGetFlaVasSize_GH100;
      if (uVar3 != 2) {
        *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
        if ((uVar4 == 0) && (uVar2 == 0)) {
          *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_VF;
          *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_d69453;
        }
        else {
          *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_FWCLIENT;
          *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_FWCLIENT;
        }
        goto joined_r0x00148964;
      }
      if ((0x3f9UL >> uVar9 & 1) == 0) {
        *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
      }
      else {
        *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_GH100;
      }
      if ((uVar4 != 0) || (uVar2 != 0)) {
        *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_FWCLIENT;
        *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_FWCLIENT;
        goto LAB_001484af;
      }
      goto LAB_0014850e;
    }
LAB_00146b80:
    *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_VF;
    *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_d69453;
    if (uVar3 != 1) goto LAB_001475b6;
    if ((0x4000400UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      goto LAB_00148110;
    }
    *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_GA100;
    *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_GA100;
    *(code **)(param_1 + 0x310) = gpuGetSriovCaps_395e98;
LAB_00146bd3:
    if ((0x3e0UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_GA100;
LAB_00146ef0:
      *(code **)(param_1 + 800) = gpuPrePowerOff_395e98;
      *(code **)(param_1 + 0x328) = gpuVerifyExistence_ac1694;
      *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
      *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
    }
    else {
      *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_86b752;
      if (uVar2 == 0) goto LAB_00146ef0;
      *(code **)(param_1 + 800) = gpuPrePowerOff_ac1694;
      *(code **)(param_1 + 0x328) = gpuVerifyExistence_IMPL;
      *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
      *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
    }
    uVar4 = 0;
  }
  else {
    *(code **)(param_1 + 0x2f0) = gpuCheckPageRetirementSupport_GSPCLIENT;
    *(code **)(param_1 + 0x2f8) = gpuIsInternalSku_FWCLIENT;
    if ((0x4000400UL >> uVar9 & 1) == 0) {
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_ac1694;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_d69453;
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_TU102;
    }
    else {
      *(code **)(param_1 + 0x300) = gpuClearFbhubPoisonIntrForBug2924523_GA100;
      *(code **)(param_1 + 0x308) = gpuCheckIfFbhubPoisonIntrPending_GA100;
      *(code **)(param_1 + 0x310) = gpuGetSriovCaps_TU102;
    }
LAB_00146f70:
    *(code **)(param_1 + 0x318) = gpuCheckIsP2PAllocated_d69453;
    *(code **)(param_1 + 800) = gpuPrePowerOff_ac1694;
    *(code **)(param_1 + 0x328) = gpuVerifyExistence_IMPL;
    *(code **)(param_1 + 0x330) = gpuGetNvlinkLinkDetectionHalFlag_039569;
    *(code **)(param_1 + 0x338) = gpuDetectNvlinkLinkFromGpus_GP100;
  }
  pcVar6 = gpuGetFlaVasSize_GA100;
  if (((0x1f0fc00UL >> uVar9 & 1) == 0) &&
     (pcVar6 = gpuGetFlaVasSize_474d46, (0x3e0UL >> uVar9 & 1) == 0)) {
    pcVar6 = gpuGetFlaVasSize_GH100;
  }
  *(code **)(param_1 + 0x340) = pcVar6;
  if ((0xbc000000UL >> uVar9 & 1) == 0) {
    *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_d69453;
  }
  else {
    *(code **)(param_1 + 0x348) = gpuIsAtsSupportedWithSmcMemPartitioning_GH100;
  }
  if ((uVar4 == 0) && (uVar2 == 0)) {
    *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_VF;
    *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_d69453;
  }
  else {
    *(code **)(param_1 + 0x350) = gpuIsGlobalPoisonFuseEnabled_FWCLIENT;
    *(code **)(param_1 + 0x358) = gpuIsSystemRebootRequired_FWCLIENT;
  }
LAB_00146c9c:
  pcVar6 = gpuDetermineSelfHostedMode_KERNEL_GH100;
  if ((0x9c000000UL >> uVar9 & 1) == 0) {
    pcVar6 = gpuDetermineSelfHostedMode_d44104;
  }
  *(code **)(param_1 + 0x360) = pcVar6;
  return;
}


// ===== 00149460 __nvoc_init_funcTable_OBJGPU_2.cold =====

void __nvoc_init_funcTable_OBJGPU_2_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00149470 __nvoc_init_funcTable_OBJGPU_2 =====

void __nvoc_init_funcTable_OBJGPU_2(long param_1)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  code *pcVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ulong uVar8;
  ulong uVar9;
  code *pcVar10;
  code *pcVar11;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  uVar1 = *(ushort *)(*(long *)(param_1 + 0x80) + 0x10);
  uVar2 = *(ushort *)(*(long *)(param_1 + 0x88) + 0x10);
  uVar5 = uVar1 >> 5;
  if (uVar5 == 1) {
    pcVar3 = gpuDetermineSelfHostedSocType_GH100;
    if ((0xbc000000UL >> (uVar1 & 0x1f) & 1) == 0) {
      pcVar3 = gpuDetermineSelfHostedSocType_6ac90c;
    }
    uVar7 = uVar2 >> 5;
    if ((uVar7 == 0) && (uVar2 == 0)) {
      pcVar11 = gpuValidateMIGSupport_VF;
      pcVar10 = gpuInitOptimusSettings_ac1694;
      pcVar4 = gpuDeinitOptimusSettings_ac1694;
    }
    else {
      pcVar11 = gpuValidateMIGSupport_KERNEL;
      pcVar10 = gpuInitOptimusSettings_IMPL;
      pcVar4 = gpuDeinitOptimusSettings_IMPL;
    }
    *(code **)(param_1 + 0x368) = pcVar3;
    *(code **)(param_1 + 0x378) = pcVar10;
    uVar6 = uVar1 & 0x1f;
    *(code **)(param_1 + 0x380) = pcVar4;
    *(code **)(param_1 + 0x370) = pcVar11;
    if ((0x9c000000UL >> uVar6 & 1) == 0) {
      *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_d69453;
      if (uVar2 == 0) goto LAB_00149bf5;
LAB_001498f2:
      if ((uVar1 & 0x1f) != 0x1a) {
        if ((0x98000000UL >> uVar6 & 1) == 0) {
          *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_d69453;
          *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
LAB_00149923:
          *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
          *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
          uVar6 = uVar1 & 0x1f;
          pcVar3 = gpuIsMultiGpuNvleEnabledInHw_GB100;
          if ((0xb8000000UL >> uVar6 & 1) == 0) {
            pcVar3 = gpuIsMultiGpuNvleEnabledInHw_d69453;
          }
LAB_0014995a:
          *(code **)(param_1 + 0x3b0) = pcVar3;
          if ((0x98000000UL >> uVar6 & 1) != 0) {
            *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_GB100;
            pcVar3 = gpuIsCtxBufAllocInPmaSupported_GA100;
            if ((0xbdf0fc00UL >> uVar6 & 1) == 0) {
              pcVar3 = gpuIsCtxBufAllocInPmaSupported_d69453;
            }
            goto LAB_00149998;
          }
        }
        else {
          *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_GB100;
          if (uVar7 != 0) {
            if ((0x98000000UL >> uVar6 & 1) == 0) {
              *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
            }
            else {
              *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_GB100;
            }
            if (uVar2 == 0) goto LAB_00149c0b;
            goto LAB_00149923;
          }
          if ((uVar1 & 0x1f) != 0x1a) {
            pcVar3 = gpuIsDevModeEnabledInHw_GB100;
            if ((0x98000000UL >> (uVar1 & 0x1f) & 1) == 0) {
              pcVar3 = gpuIsDevModeEnabledInHw_d69453;
            }
            *(code **)(param_1 + 0x398) = pcVar3;
            goto LAB_00149923;
          }
          *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_GH100;
          uVar6 = 0x1a;
          *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_GH100;
          *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_GH100;
          *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
        }
        *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
        goto LAB_00149c3c;
      }
      *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_GH100;
      *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_GH100;
      *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_GH100;
      *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_GH100;
      if (uVar7 == 0) {
        pcVar3 = gpuIsMultiGpuNvleEnabledInHw_d69453;
        uVar6 = 0x1a;
        goto LAB_0014995a;
      }
      *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
      pcVar3 = gpuIsCtxBufAllocInPmaSupported_GA100;
      uVar6 = 0x1a;
      *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
    }
    else {
      *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_e661f0;
      if (uVar2 != 0) goto LAB_001498f2;
LAB_00149bf5:
      *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_d69453;
      *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
LAB_00149c0b:
      *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
      *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
      uVar6 = uVar1 & 0x1f;
      *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
      *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
LAB_00149c3c:
      pcVar3 = gpuIsCtxBufAllocInPmaSupported_GA100;
      if ((0xbdf0fc00UL >> uVar6 & 1) == 0) {
        pcVar3 = gpuIsCtxBufAllocInPmaSupported_d69453;
      }
    }
LAB_00149998:
    *(code **)(param_1 + 0x3c0) = pcVar3;
    uVar8 = 0x3e0L >> (sbyte)uVar6;
    if ((0x5f0fc00UL >> uVar6 & 1) == 0) {
      if ((uVar8 & 1) == 0) {
        *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
        *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
      }
      else {
        *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_80f438;
        *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_9de355;
      }
    }
    else {
      pcVar3 = gpuUpdateErrorContainmentState_9de355;
      *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GA100;
      if ((uVar8 & 1) == 0) {
        pcVar3 = gpuUpdateErrorContainmentState_GA100;
      }
      *(code **)(param_1 + 0x3d0) = pcVar3;
    }
    if ((0xb8000000UL >> uVar6 & 1) == 0) {
      *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
      *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
      *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
      if (uVar2 == 0) goto LAB_00149cbb;
      *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_KERNEL;
      if ((0xbdf0ffe0UL >> uVar6 & 1) == 0) {
        *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_d69453;
      }
      else {
        *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_TU102;
        if (uVar7 != 0) goto LAB_00149a4c;
LAB_00149a45:
        uVar7 = 0;
        uVar6 = uVar1 & 0x1f;
      }
    }
    else {
      *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_KERNEL;
      *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
      *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
      if (uVar2 != 0) goto LAB_00149586;
LAB_00149cbb:
      *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_ac1694;
LAB_00149cc6:
      uVar6 = uVar1 & 0x1f;
      if ((0xbdf0ffe0UL >> uVar6 & 1) == 0) {
        *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_d69453;
        if ((uVar7 == 0) && (uVar2 == 0)) {
LAB_00149cf8:
          *(code **)(param_1 + 0x400) = gpuWaitForGfwBootComplete_5baef9;
          *(code **)(param_1 + 0x408) = gpuGetFirstAsyncLce_77d68d;
          *(code **)(param_1 + 0x410) = gpuIsInternalSkuFuseEnabled_d69453;
          *(code **)(param_1 + 0x418) = gpuRequireGrCePresence_ac1694;
          goto LAB_00149d24;
        }
      }
      else {
        *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_TU102;
        if (uVar7 == 0) {
          if (uVar2 != 0) goto LAB_00149a45;
          goto LAB_00149cf8;
        }
      }
    }
LAB_00149a4c:
    *(code **)(param_1 + 0x408) = gpuGetFirstAsyncLce_77d68d;
    *(code **)(param_1 + 0x410) = gpuIsInternalSkuFuseEnabled_d69453;
    pcVar3 = gpuWaitForGfwBootComplete_TU102;
    *(code **)(param_1 + 0x418) = gpuRequireGrCePresence_ac1694;
    if ((0x1f0ffe0UL >> uVar6 & 1) == 0) {
      pcVar3 = gpuWaitForGfwBootComplete_5baef9;
    }
    *(code **)(param_1 + 0x400) = pcVar3;
    if ((0x98000000UL >> uVar6 & 1) == 0) {
      *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_e661f0;
    }
    else {
      *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_GB100;
    }
    if ((uVar7 != 0) || (uVar2 != 0)) {
      pcVar3 = gpuGetIsCmpSku_72a2e1;
      goto LAB_00149ac3;
    }
  }
  else {
    if (uVar5 == 2) {
      pcVar3 = gpuDetermineSelfHostedSocType_GH100;
      if ((0x3f9UL >> (uVar1 & 0x1f) & 1) == 0) {
        pcVar3 = gpuDetermineSelfHostedSocType_6ac90c;
      }
      uVar7 = uVar2 >> 5;
      if (uVar7 != 0) {
        *(code **)(param_1 + 0x368) = pcVar3;
        *(code **)(param_1 + 0x370) = gpuValidateMIGSupport_KERNEL;
        *(code **)(param_1 + 0x378) = gpuInitOptimusSettings_IMPL;
        *(code **)(param_1 + 0x380) = gpuDeinitOptimusSettings_IMPL;
        if ((uVar1 & 0x1f) == 0) {
          *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_e661f0;
          *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_GB100;
LAB_0014968e:
          *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_GB100;
          *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
          *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
          if ((0x3f9UL >> (uVar1 & 0x1f) & 1) != 0) {
            *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_GB100;
            if (uVar2 != 0) goto LAB_001496e0;
LAB_00149c80:
            *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
            goto LAB_001496f4;
          }
          *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
          if (uVar2 != 0) {
LAB_0014a079:
            if ((uVar1 & 0x1f) == 0) goto LAB_001496e9;
          }
          *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
LAB_0014a08d:
          *(code **)(param_1 + 0x3c0) = gpuIsCtxBufAllocInPmaSupported_d69453;
          *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
          *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
        }
        else {
LAB_00149f86:
          *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_d69453;
          if (uVar2 == 0) goto LAB_0014a0ba;
          if ((0x3f9UL >> (uVar1 & 0x1f) & 1) == 0) {
            *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_d69453;
          }
          else {
            *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_GB100;
            if ((0x3f9UL >> (uVar1 & 0x1f) & 1) != 0) goto LAB_0014968e;
          }
          *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
          *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
          *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
          if ((0x3f9UL >> (uVar1 & 0x1f) & 1) == 0) {
            *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
            goto LAB_0014a079;
          }
          *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_GB100;
LAB_001496e0:
          if ((uVar1 & 0x1f) != 0) goto LAB_00149c80;
LAB_001496e9:
          *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_GB100;
LAB_001496f4:
          *(code **)(param_1 + 0x3c0) = gpuIsCtxBufAllocInPmaSupported_GA100;
          *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
          *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
        }
        if ((0x3f9UL >> (uVar1 & 0x1f) & 1) == 0) {
          pcVar3 = gpuRusdInitPhysical_ac1694;
          *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
          *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
          if (uVar2 != 0) {
            pcVar3 = gpuRusdInitPhysical_KERNEL;
          }
          *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
          *(code **)(param_1 + 0x3f0) = pcVar3;
LAB_00149760:
          uVar5 = uVar1 & 0x1f;
          uVar8 = 0x3f9L >> (sbyte)uVar5;
          pcVar3 = gpuCheckEccCounts_d69453;
          if ((uVar8 & 1) != 0) {
            pcVar3 = gpuCheckEccCounts_TU102;
          }
          *(code **)(param_1 + 0x3f8) = pcVar3;
          *(code **)(param_1 + 0x400) = gpuWaitForGfwBootComplete_5baef9;
          uVar9 = 0xf8L >> (sbyte)uVar5;
          if ((0x3f8UL >> uVar5 & 1) == 0) {
            pcVar4 = gpuIsInternalSkuFuseEnabled_d69453;
            pcVar3 = gpuGetFirstAsyncLce_77d68d;
            if ((uVar9 & 1) != 0) {
              pcVar4 = gpuIsInternalSkuFuseEnabled_GB202;
            }
            pcVar10 = gpuRequireGrCePresence_ac1694;
          }
          else {
            pcVar4 = gpuIsInternalSkuFuseEnabled_GB202;
            pcVar3 = gpuGetFirstAsyncLce_GB202;
            if ((uVar9 & 1) == 0) {
              pcVar4 = gpuIsInternalSkuFuseEnabled_d69453;
            }
            pcVar10 = gpuRequireGrCePresence_GB202;
          }
          *(code **)(param_1 + 0x408) = pcVar3;
          *(code **)(param_1 + 0x410) = pcVar4;
          *(code **)(param_1 + 0x418) = pcVar10;
          if ((uVar1 & 0x1f) == 0) {
            *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_GB100;
            if (uVar7 != 0) {
              *(code **)(param_1 + 0x428) = gpuGetIsCmpSku_72a2e1;
              pcVar3 = gpuGetXtlBaseAddr_474d46;
              goto LAB_00149819;
            }
            pcVar3 = gpuGetIsCmpSku_72a2e1;
            if (uVar2 == 0) {
              pcVar3 = gpuGetIsCmpSku_d69453;
            }
            *(code **)(param_1 + 0x428) = pcVar3;
          }
          else {
            pcVar3 = gpuGetIsCmpSku_72a2e1;
            if ((uVar7 == 0) && (uVar2 == 0)) {
              pcVar3 = gpuGetIsCmpSku_d69453;
            }
            *(code **)(param_1 + 0x428) = pcVar3;
            pcVar3 = gpuGetXtlBaseAddr_GB202;
            *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_e661f0;
            if ((uVar9 & 1) != 0) goto LAB_00149819;
          }
          pcVar3 = gpuGetXtlBaseAddr_GH100;
          if ((0x300UL >> uVar5 & 1) == 0) {
            pcVar3 = gpuGetXtlBaseAddr_474d46;
          }
LAB_00149819:
          pcVar4 = gpuGetPrimaryFuseBaseAddr_GH100;
          if ((uVar8 & 1) == 0) {
            pcVar4 = gpuGetPrimaryFuseBaseAddr_b2b553;
          }
          *(code **)(param_1 + 0x430) = pcVar3;
          *(code **)(param_1 + 0x438) = pcVar4;
          return;
        }
        *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_KERNEL;
        *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
        *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
        if (uVar2 != 0) {
          *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_KERNEL;
          goto LAB_00149760;
        }
LAB_0014a44f:
        *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_ac1694;
        if (uVar5 == 2) goto LAB_00149760;
        goto LAB_0014959b;
      }
LAB_00149b17:
      if (uVar2 == 0) {
        pcVar11 = gpuValidateMIGSupport_VF;
        pcVar10 = gpuInitOptimusSettings_ac1694;
        pcVar4 = gpuDeinitOptimusSettings_ac1694;
      }
      else {
        pcVar11 = gpuValidateMIGSupport_KERNEL;
        pcVar10 = gpuInitOptimusSettings_IMPL;
        pcVar4 = gpuDeinitOptimusSettings_IMPL;
      }
      *(code **)(param_1 + 0x368) = pcVar3;
      *(code **)(param_1 + 0x370) = pcVar11;
      *(code **)(param_1 + 0x378) = pcVar10;
      *(code **)(param_1 + 0x380) = pcVar4;
      if (uVar5 == 2) {
        if ((uVar1 & 0x1f) != 0) {
          uVar7 = 0;
          goto LAB_00149f86;
        }
        *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_e661f0;
        if (uVar2 != 0) {
          *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_GB100;
          uVar7 = 0;
          goto LAB_0014968e;
        }
      }
      else {
        *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_d69453;
        if (uVar2 != 0) {
          *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_d69453;
          if ((uVar1 == 0x6f) || (uVar5 == 3)) {
            *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
            *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
            *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
            *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
            *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
            *(code **)(param_1 + 0x3c0) = gpuIsCtxBufAllocInPmaSupported_d69453;
            goto LAB_00149d92;
          }
          *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
          uVar7 = 0;
          *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
          *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
          *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
          *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
          *(code **)(param_1 + 0x3c0) = gpuIsCtxBufAllocInPmaSupported_d69453;
          goto LAB_0014954f;
        }
      }
      uVar7 = 0;
LAB_0014a0ba:
      *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_d69453;
      *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
      *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
      *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
      *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
      *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
      if (uVar5 == 2) {
        if ((0x3f9UL >> (uVar1 & 0x1f) & 1) == 0) goto LAB_0014a08d;
        goto LAB_001496f4;
      }
      *(code **)(param_1 + 0x3c0) = gpuIsCtxBufAllocInPmaSupported_d69453;
      if (uVar5 != 3) {
        *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
        *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
        *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
        *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
        *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
        goto LAB_0014a44f;
      }
      if ((0xa000UL >> (uVar1 & 0x1f) & 1) != 0) {
        *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_80f438;
        *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_9de355;
        *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
        *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_ac1694;
        *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_ac1694;
        if (uVar7 == 0) goto LAB_0014a170;
LAB_00149de0:
        *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_KERNEL;
        *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_d69453;
        *(code **)(param_1 + 0x400) = gpuWaitForGfwBootComplete_5baef9;
        *(code **)(param_1 + 0x408) = gpuGetFirstAsyncLce_77d68d;
        *(code **)(param_1 + 0x410) = gpuIsInternalSkuFuseEnabled_d69453;
        *(code **)(param_1 + 0x418) = gpuRequireGrCePresence_ac1694;
        goto LAB_001495db;
      }
      *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
      *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
      *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
      *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
      *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
      if (uVar7 != 0) goto LAB_00149de0;
LAB_0014a170:
      *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_ac1694;
      *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_d69453;
    }
    else {
      uVar7 = uVar2 >> 5;
      if (uVar7 == 0) {
        pcVar3 = gpuDetermineSelfHostedSocType_6ac90c;
        goto LAB_00149b17;
      }
      *(code **)(param_1 + 0x368) = gpuDetermineSelfHostedSocType_6ac90c;
      *(code **)(param_1 + 0x370) = gpuValidateMIGSupport_KERNEL;
      *(code **)(param_1 + 0x378) = gpuInitOptimusSettings_IMPL;
      *(code **)(param_1 + 0x380) = gpuDeinitOptimusSettings_IMPL;
      *(code **)(param_1 + 0x388) = gpuIsSliCapableWithoutDisplay_d69453;
      *(code **)(param_1 + 0x390) = gpuIsCCEnabledInHw_d69453;
      *(code **)(param_1 + 0x398) = gpuIsDevModeEnabledInHw_d69453;
      *(code **)(param_1 + 0x3a0) = gpuIsProtectedPcieEnabledInHw_d69453;
      *(code **)(param_1 + 0x3a8) = gpuIsProtectedPcieSupportedInFirmware_d69453;
      *(code **)(param_1 + 0x3b0) = gpuIsMultiGpuNvleEnabledInHw_d69453;
      *(code **)(param_1 + 0x3b8) = gpuIsNvleModeEnabledInHw_d69453;
      *(code **)(param_1 + 0x3c0) = gpuIsCtxBufAllocInPmaSupported_d69453;
      if ((uVar1 == 0x6f) || (uVar5 == 3)) {
LAB_00149d92:
        if ((0xa000UL >> (uVar1 & 0x1f) & 1) == 0) {
          *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
          *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
          *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
          *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
          *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
        }
        else {
          *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_80f438;
          *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_9de355;
          *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
          *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_ac1694;
          *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_ac1694;
        }
        goto LAB_00149de0;
      }
LAB_0014954f:
      *(code **)(param_1 + 0x3c8) = gpuGetErrorContStateTableAndSize_GB100;
      *(code **)(param_1 + 0x3d0) = gpuUpdateErrorContainmentState_GA100;
      *(code **)(param_1 + 0x3d8) = gpuSetPartitionErrorAttribution_5baef9;
      *(code **)(param_1 + 0x3e0) = gpuCreateRusdMemory_IMPL;
      *(code **)(param_1 + 1000) = gpuHandleRusdPollingRegistry_KERNEL;
LAB_00149586:
      *(code **)(param_1 + 0x3f0) = gpuRusdInitPhysical_KERNEL;
      if (uVar5 == 1) goto LAB_00149cc6;
LAB_0014959b:
      *(code **)(param_1 + 0x3f8) = gpuCheckEccCounts_d69453;
      if ((uVar7 != 0) || (uVar2 != 0)) {
        *(code **)(param_1 + 0x400) = gpuWaitForGfwBootComplete_5baef9;
        *(code **)(param_1 + 0x408) = gpuGetFirstAsyncLce_77d68d;
        *(code **)(param_1 + 0x410) = gpuIsInternalSkuFuseEnabled_d69453;
        *(code **)(param_1 + 0x418) = gpuRequireGrCePresence_ac1694;
LAB_001495db:
        pcVar3 = gpuGetIsCmpSku_72a2e1;
        goto LAB_001495e2;
      }
    }
    *(code **)(param_1 + 0x400) = gpuWaitForGfwBootComplete_5baef9;
    *(code **)(param_1 + 0x408) = gpuGetFirstAsyncLce_77d68d;
    *(code **)(param_1 + 0x410) = gpuIsInternalSkuFuseEnabled_d69453;
    *(code **)(param_1 + 0x418) = gpuRequireGrCePresence_ac1694;
    if (uVar5 != 1) {
      pcVar3 = gpuGetIsCmpSku_d69453;
LAB_001495e2:
      *(code **)(param_1 + 0x428) = pcVar3;
      *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_e661f0;
      *(code **)(param_1 + 0x430) = gpuGetXtlBaseAddr_474d46;
      *(code **)(param_1 + 0x438) = gpuGetPrimaryFuseBaseAddr_b2b553;
      return;
    }
LAB_00149d24:
    uVar6 = uVar1 & 0x1f;
    if ((0x98000000UL >> uVar6 & 1) == 0) {
      *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_e661f0;
    }
    else {
      *(code **)(param_1 + 0x420) = gpuWaitForBarFirewallHal_GB100;
    }
  }
  pcVar3 = gpuGetIsCmpSku_d69453;
LAB_00149ac3:
  *(code **)(param_1 + 0x428) = pcVar3;
  pcVar3 = gpuGetXtlBaseAddr_GH100;
  if ((0x24000000UL >> uVar6 & 1) == 0) {
    pcVar3 = gpuGetXtlBaseAddr_474d46;
  }
  pcVar4 = gpuGetPrimaryFuseBaseAddr_GH100;
  if ((0xbc000000UL >> uVar6 & 1) == 0) {
    pcVar4 = gpuGetPrimaryFuseBaseAddr_b2b553;
  }
  *(code **)(param_1 + 0x430) = pcVar3;
  *(code **)(param_1 + 0x438) = pcVar4;
  return;
}


// ===== 0014a490 __nvoc_dtor_OBJGPU =====

void __nvoc_dtor_OBJGPU(long param_1)

{
  gpuDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  __nvoc_dtor_GpuHalspecOwner(param_1 + 0x38);
  __nvoc_dtor_RmHalspecOwner(param_1 + 0x50);
  __nvoc_dtor_OBJTRACEABLE(param_1 + 0x68);
  return;
}


// ===== 0014a4d0 gpuGetFlaVasSize_474d46 =====

undefined8 gpuGetFlaVasSize_474d46(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x14b4);
  return 0;
}


// ===== 0014a500 gpuCheckIsP2PAllocated_86b752 =====

undefined8 gpuCheckIsP2PAllocated_86b752(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x1484);
  return 0;
}


// ===== 0014a530 gpuGetSkuInfo_92bfc3 =====

undefined8 gpuGetSkuInfo_92bfc3(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x13df);
  return 0x56;
}


// ===== 0014a560 gpuWriteFunctionConfigRegEx_5baef9 =====

undefined8 gpuWriteFunctionConfigRegEx_5baef9(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x13b3);
  return 0x56;
}


// ===== 0014a590 gpuWriteFunctionConfigReg_5baef9 =====

undefined8 gpuWriteFunctionConfigReg_5baef9(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x13af);
  return 0x56;
}


// ===== 0014a5c0 gpuReadFunctionConfigReg_5baef9 =====

undefined8 gpuReadFunctionConfigReg_5baef9(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x13ab);
  return 0x56;
}


// ===== 0014a5f0 gpuReadBusConfigRegEx_5baef9 =====

undefined8 gpuReadBusConfigRegEx_5baef9(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x13a7);
  return 0x56;
}


// ===== 0014a620 gpuGetXtlBaseAddr_474d46 =====

undefined8 gpuGetXtlBaseAddr_474d46(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x1552);
  return 0;
}


// ===== 0014a650 gpuGetIsCmpSku_72a2e1 =====

undefined8 gpuGetIsCmpSku_72a2e1(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x154d);
  return 0;
}


// ===== 0014a680 gpuWaitForGfwBootComplete_5baef9 =====

undefined8 gpuWaitForGfwBootComplete_5baef9(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x152d);
  return 0x56;
}


// ===== 0014a6b0 gpuSetPartitionErrorAttribution_5baef9 =====

undefined8 gpuSetPartitionErrorAttribution_5baef9(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x1511);
  return 0x56;
}


// ===== 0014a6e0 gpuUpdateErrorContainmentState_9de355 =====

undefined8 gpuUpdateErrorContainmentState_9de355(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x150d);
  return 0;
}


// ===== 0014a710 gpuGetErrorContStateTableAndSize_80f438 =====

undefined8 gpuGetErrorContStateTableAndSize_80f438(void)

{
  nvAssertFailed(&DAT_00c48707,"generated/g_gpu_nvoc.h",0x1509);
  return 0;
}


// ===== 0014a740 gpuReadPassThruConfigReg_395e98 =====

undefined8 gpuReadPassThruConfigReg_395e98(void)

{
  return 0x56;
}


// ===== 0014a750 gpuGetRegBaseOffset_395e98 =====

undefined8 gpuGetRegBaseOffset_395e98(void)

{
  return 0x56;
}


// ===== 0014a760 gpuMnocMboxInterruptRaised_d69453 =====

undefined8 gpuMnocMboxInterruptRaised_d69453(void)

{
  return 0;
}


// ===== 0014a770 gpuSetResetScratchBit_395e98 =====

undefined8 gpuSetResetScratchBit_395e98(void)

{
  return 0x56;
}


// ===== 0014a780 gpuResetRequiredStateChanged_395e98 =====

undefined8 gpuResetRequiredStateChanged_395e98(void)

{
  return 0x56;
}


// ===== 0014a790 gpuSetDrainAndResetScratchBit_395e98 =====

undefined8 gpuSetDrainAndResetScratchBit_395e98(void)

{
  return 0x56;
}


// ===== 0014a7a0 gpuIsDeviceMarkedForReset_395e98 =====

undefined8 gpuIsDeviceMarkedForReset_395e98(void)

{
  return 0x56;
}


// ===== 0014a7b0 gpuGetDrainAndResetScratchBit_395e98 =====

undefined8 gpuGetDrainAndResetScratchBit_395e98(void)

{
  return 0x56;
}


// ===== 0014a7c0 gpuIsDeviceMarkedForDrainAndReset_395e98 =====

undefined8 gpuIsDeviceMarkedForDrainAndReset_395e98(void)

{
  return 0x56;
}


// ===== 0014a7d0 gpuGetSriovCaps_395e98 =====

undefined8 gpuGetSriovCaps_395e98(void)

{
  return 0x56;
}


// ===== 0014a7e0 gpuMnocMboxInterruptDisable_d44104 =====

void gpuMnocMboxInterruptDisable_d44104(void)

{
  return;
}


// ===== 0014a7f0 gpuMnocMboxInterruptClear_d44104 =====

void gpuMnocMboxInterruptClear_d44104(void)

{
  return;
}


// ===== 0014a800 gpuValidateRmctrlCmd_ac1694 =====

undefined8 gpuValidateRmctrlCmd_ac1694(void)

{
  return 0;
}


// ===== 0014a810 gpuValidateBusInfoIndex_ac1694 =====

undefined8 gpuValidateBusInfoIndex_ac1694(void)

{
  return 0;
}


// ===== 0014a820 gpuInitBranding_ac1694 =====

undefined8 gpuInitBranding_ac1694(void)

{
  return 0;
}


// ===== 0014a830 gpuConfigAccessSanityCheck_ac1694 =====

undefined8 gpuConfigAccessSanityCheck_ac1694(void)

{
  return 0;
}


// ===== 0014a840 gpuGetVirtRegPhysOffset_b2b553 =====

undefined8 gpuGetVirtRegPhysOffset_b2b553(void)

{
  return 0;
}


// ===== 0014a850 gpuInitSriov_ac1694 =====

undefined8 gpuInitSriov_ac1694(void)

{
  return 0;
}


// ===== 0014a860 gpuDeinitSriov_ac1694 =====

undefined8 gpuDeinitSriov_ac1694(void)

{
  return 0;
}


// ===== 0014a870 gpuMnocMboxMinMessageSize_edd98b =====

undefined8 gpuMnocMboxMinMessageSize_edd98b(void)

{
  return 0;
}


// ===== 0014a880 gpuMnocMboxMaxMessageSize_edd98b =====

undefined8 gpuMnocMboxMaxMessageSize_edd98b(void)

{
  return 0;
}


// ===== 0014a890 gpuCreateDefaultClientShare_ac1694 =====

undefined8 gpuCreateDefaultClientShare_ac1694(void)

{
  return 0;
}


// ===== 0014a8a0 gpuJtVersionSanityCheck_ac1694 =====

undefined8 gpuJtVersionSanityCheck_ac1694(void)

{
  return 0;
}


// ===== 0014a8b0 gpuExtdevConstruct_ac1694 =====

undefined8 gpuExtdevConstruct_ac1694(void)

{
  return 0;
}


// ===== 0014a8c0 gpuClearFbhubPoisonIntrForBug2924523_ac1694 =====

undefined8 gpuClearFbhubPoisonIntrForBug2924523_ac1694(void)

{
  return 0;
}


// ===== 0014a8d0 gpuPrePowerOff_ac1694 =====

undefined8 gpuPrePowerOff_ac1694(void)

{
  return 0;
}


// ===== 0014a8e0 gpuVerifyExistence_ac1694 =====

undefined8 gpuVerifyExistence_ac1694(void)

{
  return 0;
}


// ===== 0014a8f0 gpuGetNvlinkLinkDetectionHalFlag_b2b553 =====

undefined8 gpuGetNvlinkLinkDetectionHalFlag_b2b553(void)

{
  return 0;
}


// ===== 0014a900 gpuDetermineSelfHostedSocType_6ac90c =====

undefined8 gpuDetermineSelfHostedSocType_6ac90c(void)

{
  return 0;
}


// ===== 0014a910 gpuInitOptimusSettings_ac1694 =====

undefined8 gpuInitOptimusSettings_ac1694(void)

{
  return 0;
}


// ===== 0014a920 gpuDeinitOptimusSettings_ac1694 =====

undefined8 gpuDeinitOptimusSettings_ac1694(void)

{
  return 0;
}


// ===== 0014a930 gpuCreateRusdMemory_ac1694 =====

undefined8 gpuCreateRusdMemory_ac1694(void)

{
  return 0;
}


// ===== 0014a940 gpuHandleRusdPollingRegistry_ac1694 =====

undefined8 gpuHandleRusdPollingRegistry_ac1694(void)

{
  return 0;
}


// ===== 0014a950 gpuRusdInitPhysical_ac1694 =====

undefined8 gpuRusdInitPhysical_ac1694(void)

{
  return 0;
}


// ===== 0014a960 gpuGetPrimaryFuseBaseAddr_b2b553 =====

undefined8 gpuGetPrimaryFuseBaseAddr_b2b553(void)

{
  return 0;
}


// ===== 0014a970 gpuGetChipSubRev_b2b553 =====

undefined8 gpuGetChipSubRev_b2b553(void)

{
  return 0;
}


// ===== 0014a980 gpuFuseSupportsDisplay_d69453 =====

undefined8 gpuFuseSupportsDisplay_d69453(void)

{
  return 0;
}


// ===== 0014a990 gpuIsDebuggerActive_d69453 =====

undefined8 gpuIsDebuggerActive_d69453(void)

{
  return 0;
}


