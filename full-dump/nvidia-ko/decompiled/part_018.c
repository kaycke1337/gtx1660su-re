// ===== 0019e480 __nvoc_up_thunk_RmResource_sysmemControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_sysmemControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x120))(param_1 + 0x18);
  return;
}


// ===== 0019e4a0 __nvoc_up_thunk_RmResource_sysmemControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_sysmemControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x128))(param_1 + 0x18);
  return;
}


// ===== 0019e4c0 __nvoc_up_thunk_RmResource_sysmemControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_sysmemControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x130))(param_1 + 0x18);
  return;
}


// ===== 0019e4e0 __nvoc_up_thunk_RsResource_sysmemPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x40))(param_1 + 0x20);
  return;
}


// ===== 0019e500 __nvoc_up_thunk_RsResource_sysmemControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x50))(param_1 + 0x20);
  return;
}


// ===== 0019e520 __nvoc_up_thunk_RsResource_sysmemIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x88))(param_1 + 0x20);
  return;
}


// ===== 0019e540 __nvoc_up_thunk_RsResource_sysmemMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x90))(param_1 + 0x20);
  return;
}


// ===== 0019e560 __nvoc_up_thunk_RsResource_sysmemUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x98))(param_1 + 0x20);
  return;
}


// ===== 0019e580 __nvoc_up_thunk_RsResource_sysmemGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0xa0))(param_1 + 0x20);
  return;
}


// ===== 0019e5a0 __nvoc_up_thunk_RsResource_sysmemAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_sysmemAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x20) + 0xb8))(param_1,param_2 + 0x20);
  return;
}


// ===== 0019e5c0 __nvoc_dtor_SystemMemory =====

void __nvoc_dtor_SystemMemory(long param_1)

{
  sysmemDestruct_IMPL();
  __nvoc_dtor_StandardMemory(param_1 + 8);
  return;
}


// ===== 0019e5f0 __nvoc_init__SystemMemory =====

void __nvoc_init__SystemMemory(undefined8 *param_1,long param_2)

{
  code *pcVar1;
  
  param_1[0x45] = param_1 + 5;
  param_1[0x46] = param_1 + 4;
  param_1[0x47] = param_1 + 0x11;
  param_1[0x48] = param_1 + 3;
  param_1[0x49] = param_1 + 2;
  param_1[0x4a] = param_1 + 1;
  param_1[0x4b] = param_1;
  __nvoc_init__StandardMemory();
  param_1[5] = 0xc74818;
  pcVar1 = sysmemInitAllocRequest_HMM;
  param_1[4] = 0xc74800;
  param_1[0x11] = 0xc748c0;
  param_1[3] = 0xc747e8;
  param_1[2] = 0xc747d0;
  param_1[1] = 0xc747b8;
  *param_1 = __nvoc_metadata__SystemMemory;
  if ((*(ushort *)(param_2 + 0x10) >> 5 == 3) &&
     ((0xa000UL >> (*(ushort *)(param_2 + 0x10) & 0x1f) & 1) != 0)) {
    pcVar1 = sysmemInitAllocRequest_SOC;
  }
  param_1[0x4c] = pcVar1;
  return;
}


// ===== 0019e6d0 __nvoc_objCreate_SystemMemory =====

int __nvoc_objCreate_SystemMemory
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long local_50;
  
  if ((param_3 & 2) == 0) {
    lVar3 = portMemAllocNonPaged(0x268);
    if (lVar3 == 0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_system_mem_nvoc.c",0x265);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) || (lVar3 = *param_1, lVar3 == 0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_system_mem_nvoc.c",0x25d);
    return 0x3b;
  }
  portMemSet(lVar3,0,0x268);
  *(uint *)(lVar3 + 0x54) = param_3;
  if (param_2 == 0) {
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_system_mem_nvoc.c",0x26e);
    iVar1 = 0x1f;
    goto LAB_0019e7a5;
  }
  if ((param_3 & 1) == 0) {
    local_50 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_50,lVar3 + 0x28);
  }
  else {
    *(undefined8 *)(lVar3 + 0x38) = 0;
    local_50 = 0;
  }
  lVar2 = __nvoc_dynamicCast(param_2,__nvoc_class_def_GpuHalspecOwner);
  if (lVar2 == 0) {
    lVar2 = objFindAncestor_IMPL(param_2,0x74bc71);
    uVar4 = 0;
    if (lVar2 != 0) {
      uVar4 = objFindAncestor_IMPL(param_2,0x74bc71);
    }
    lVar2 = __nvoc_dynamicCast(uVar4,__nvoc_class_def_GpuHalspecOwner);
    if (lVar2 != 0) goto LAB_0019e769;
    nvCheckOkFailedNoLog(4,0x1f,"pGpuhalspecowner != NULL","generated/g_system_mem_nvoc.c",0x27e);
    iVar1 = 0x1f;
  }
  else {
LAB_0019e769:
    __nvoc_init__SystemMemory(lVar3,lVar2);
    iVar1 = __nvoc_ctor_StandardMemory(lVar3 + 8,param_4,param_5);
    if (iVar1 == 0) {
      iVar1 = sysmemConstruct_IMPL(lVar3,param_4,param_5);
      if (iVar1 == 0) {
        *param_1 = lVar3;
        return 0;
      }
      __nvoc_dtor_StandardMemory(lVar3 + 8);
    }
  }
  if (local_50 != 0) {
    objRemoveChild_IMPL(local_50,lVar3 + 0x28);
  }
LAB_0019e7a5:
  if ((param_3 & 2) == 0) {
    portMemFree(lVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(lVar3,0,0x268);
  }
  return iVar1;
}


// ===== 0019e970 __nvoc_objCreateDynamic_SystemMemory =====

void __nvoc_objCreateDynamic_SystemMemory
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
      goto LAB_0019e99e;
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
LAB_0019e99e:
  __nvoc_objCreate_SystemMemory(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019e9d0 __nvoc_dtor_OBJSYS =====

void __nvoc_dtor_OBJSYS(long param_1)

{
  sysDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  __nvoc_dtor_OBJTRACEABLE(param_1 + 0x38);
  return;
}


// ===== 0019ea00 __nvoc_ctor_OBJSYS =====

ulong __nvoc_ctor_OBJSYS(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_Object(param_1 + 8);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar1 = __nvoc_ctor_OBJTRACEABLE(param_1 + 0x38);
  if (uVar1 == 0) {
    *(undefined1 *)(param_1 + 0x6f) = 1;
    *(undefined4 *)(param_1 + 0x70) = 1;
    *(undefined1 *)(param_1 + 0x76) = 0;
    *(undefined4 *)(param_1 + 0x78) = 16000;
    *(undefined4 *)(param_1 + 0x7d) = 0x1000000;
    *(undefined1 *)(param_1 + 0x83) = 1;
    *(undefined1 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x184) = 0;
    *(undefined1 *)(param_1 + 400) = 0;
    *(undefined2 *)(param_1 + 0x86) = 0;
    uVar2 = sysConstruct_IMPL(param_1);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0) {
      return uVar2;
    }
    __nvoc_dtor_OBJTRACEABLE(param_1 + 0x38);
  }
  __nvoc_dtor_Object(param_1 + 8);
  return (ulong)uVar1;
}


// ===== 0019ead0 __nvoc_objCreate_OBJSYS =====

int __nvoc_objCreate_OBJSYS(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x280);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_system_nvoc.c",0xd2);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_system_nvoc.c",0xca);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x280);
  puVar1 = puVar4 + 7;
  *(uint *)((long)puVar4 + 0x34) = param_3;
  puVar2 = puVar4 + 1;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[9] = puVar2;
    puVar4[3] = 0;
    puVar4[10] = puVar1;
    puVar4[0xb] = puVar4;
    __nvoc_init__Object(puVar2);
    __nvoc_init__OBJTRACEABLE(puVar1);
    puVar4[1] = 0xc74d78;
    puVar4[7] = 0xc74d90;
    *puVar4 = __nvoc_metadata__OBJSYS;
    iVar3 = __nvoc_ctor_OBJSYS(puVar4);
    if (iVar3 != 0) goto LAB_0019ec75;
  }
  else {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar2);
    puVar4[10] = puVar1;
    puVar4[0xb] = puVar4;
    puVar4[9] = puVar2;
    __nvoc_init__Object(puVar2);
    __nvoc_init__OBJTRACEABLE(puVar1);
    puVar4[1] = 0xc74d78;
    puVar4[7] = 0xc74d90;
    *puVar4 = __nvoc_metadata__OBJSYS;
    iVar3 = __nvoc_ctor_OBJSYS(puVar4);
    if (iVar3 != 0) {
      if (lVar5 != 0) {
        objRemoveChild_IMPL(lVar5,puVar2);
      }
LAB_0019ec75:
      if ((param_3 & 2) != 0) {
        portMemSet(puVar4,0,0x280);
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


// ===== 0019ece0 __nvoc_objCreateDynamic_OBJSYS =====

void __nvoc_objCreateDynamic_OBJSYS(void)

{
  __nvoc_objCreate_OBJSYS();
  return;
}


// ===== 0019ecf0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019ed00 __nvoc_up_thunk_GpuResource_thirdpartyp2pControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 0019ed20 __nvoc_up_thunk_GpuResource_thirdpartyp2pMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 0019ed40 __nvoc_up_thunk_GpuResource_thirdpartyp2pUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 0019ed60 __nvoc_up_thunk_GpuResource_thirdpartyp2pShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 0019ed80 __nvoc_up_thunk_GpuResource_thirdpartyp2pGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 0019eda0 __nvoc_up_thunk_GpuResource_thirdpartyp2pGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 0019edc0 __nvoc_up_thunk_GpuResource_thirdpartyp2pInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 0019ede0 __nvoc_up_thunk_GpuResource_thirdpartyp2pGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_thirdpartyp2pGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 0019ee00 __nvoc_up_thunk_RmResource_thirdpartyp2pAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 0019ee20 __nvoc_up_thunk_RmResource_thirdpartyp2pGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 0019ee40 __nvoc_up_thunk_RmResource_thirdpartyp2pCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 0019ee60 __nvoc_up_thunk_RmResource_thirdpartyp2pGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 0019ee80 __nvoc_up_thunk_RmResource_thirdpartyp2pControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 0019eea0 __nvoc_up_thunk_RmResource_thirdpartyp2pControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 0019eec0 __nvoc_up_thunk_RmResource_thirdpartyp2pControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 0019eee0 __nvoc_up_thunk_RmResource_thirdpartyp2pControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_thirdpartyp2pControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 0019ef00 __nvoc_up_thunk_RsResource_thirdpartyp2pCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 0019ef20 __nvoc_up_thunk_RsResource_thirdpartyp2pIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 0019ef40 __nvoc_up_thunk_RsResource_thirdpartyp2pPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 0019ef60 __nvoc_up_thunk_RsResource_thirdpartyp2pControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 0019ef80 __nvoc_up_thunk_RsResource_thirdpartyp2pIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 0019efa0 __nvoc_up_thunk_RsResource_thirdpartyp2pMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 0019efc0 __nvoc_up_thunk_RsResource_thirdpartyp2pUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 0019efe0 __nvoc_up_thunk_RsResource_thirdpartyp2pGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 0019f000 __nvoc_up_thunk_RsResource_thirdpartyp2pAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_thirdpartyp2pAddAdditionalDependants
               (undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 0019f020 __nvoc_dtor_P2PTokenShare =====

void __nvoc_dtor_P2PTokenShare(long param_1)

{
  shrp2pDestruct_IMPL();
  __nvoc_dtor_RsShared(param_1 + 8);
  return;
}


// ===== 0019f050 __nvoc_dtor_ThirdPartyP2P =====

void __nvoc_dtor_ThirdPartyP2P(long param_1)

{
  thirdpartyp2pDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 0019f080 __nvoc_objCreate_P2PTokenShare =====

int __nvoc_objCreate_P2PTokenShare(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xa0);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_third_party_p2p_nvoc.c",0xb3);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_third_party_p2p_nvoc.c",0xab);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xa0);
  puVar1 = puVar4 + 1;
  *(uint *)((long)puVar4 + 0x3c) = param_3;
  puVar2 = puVar4 + 2;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[0x10] = puVar2;
    puVar4[4] = 0;
    puVar4[0x11] = puVar1;
    puVar4[0x12] = puVar4;
    __nvoc_init__RsShared(puVar1);
    puVar4[2] = 0xc75470;
    puVar4[1] = 0xc75458;
    *puVar4 = __nvoc_metadata__P2PTokenShare;
    iVar3 = __nvoc_ctor_RsShared(puVar1);
    if (iVar3 == 0) {
      iVar3 = shrp2pConstruct_IMPL(puVar4);
      if (iVar3 == 0) goto LAB_0019f158;
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
    puVar4[2] = 0xc75470;
    puVar4[1] = 0xc75458;
    *puVar4 = __nvoc_metadata__P2PTokenShare;
    iVar3 = __nvoc_ctor_RsShared(puVar1);
    if (iVar3 == 0) {
      iVar3 = shrp2pConstruct_IMPL(puVar4);
      if (iVar3 == 0) {
LAB_0019f158:
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
    portMemSet(puVar4,0,0xa0);
  }
  return iVar3;
}


// ===== 0019f2f0 __nvoc_objCreateDynamic_P2PTokenShare =====

void __nvoc_objCreateDynamic_P2PTokenShare(void)

{
  __nvoc_objCreate_P2PTokenShare();
  return;
}


// ===== 0019f300 __nvoc_objCreate_ThirdPartyP2P =====

int __nvoc_objCreate_ThirdPartyP2P
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x9e8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_third_party_p2p_nvoc.c",0x315);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_third_party_p2p_nvoc.c",0x30d);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x9e8);
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
  puVar4[4] = 0xc74f20;
  puVar4[3] = 0xc74f08;
  puVar4[0x10] = 0xc74fc8;
  puVar4[2] = 0xc74ef0;
  puVar4[1] = 0xc74ed8;
  *puVar4 = __nvoc_metadata__ThirdPartyP2P;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = thirdpartyp2pConstruct_IMPL(puVar4,param_4,param_5);
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
    portMemSet(puVar4,0,0x9e8);
  }
  return iVar3;
}


// ===== 0019f580 __nvoc_objCreateDynamic_ThirdPartyP2P =====

void __nvoc_objCreateDynamic_ThirdPartyP2P
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
      goto LAB_0019f5ae;
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
LAB_0019f5ae:
  __nvoc_objCreate_ThirdPartyP2P(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019f5e0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019f5f0 __nvoc_down_thunk_TimedSemaSwObject_chandesGetSwMethods =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_TimedSemaSwObject_chandesGetSwMethods(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x428))(param_1 + -8);
  return;
}


// ===== 0019f610 __nvoc_up_thunk_ChannelDescendant_tsemaIsSwMethodStalling =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_ChannelDescendant_tsemaIsSwMethodStalling(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x318))(param_1 + 8);
  return;
}


// ===== 0019f630 __nvoc_up_thunk_ChannelDescendant_tsemaCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_ChannelDescendant_tsemaCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 800))(param_1 + 8,param_2);
  return;
}


// ===== 0019f650 __nvoc_up_thunk_GpuResource_tsemaControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b0))(param_1 + 0x10);
  return;
}


// ===== 0019f670 __nvoc_up_thunk_GpuResource_tsemaMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b8))(param_1 + 0x10);
  return;
}


// ===== 0019f690 __nvoc_up_thunk_GpuResource_tsemaUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c0))(param_1 + 0x10);
  return;
}


// ===== 0019f6b0 __nvoc_up_thunk_GpuResource_tsemaShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c8))(param_1 + 0x10);
  return;
}


// ===== 0019f6d0 __nvoc_up_thunk_GpuResource_tsemaGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d0))(param_1 + 0x10);
  return;
}


// ===== 0019f6f0 __nvoc_up_thunk_GpuResource_tsemaGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d8))(param_1 + 0x10);
  return;
}


// ===== 0019f710 __nvoc_up_thunk_GpuResource_tsemaInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e0))(param_1 + 0x10);
  return;
}


// ===== 0019f730 __nvoc_up_thunk_GpuResource_tsemaGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tsemaGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e8))(param_1 + 0x10);
  return;
}


// ===== 0019f750 __nvoc_up_thunk_RmResource_tsemaAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xf0))(param_1 + 0x18,param_2,param_3,param_4);
  return;
}


// ===== 0019f770 __nvoc_up_thunk_RmResource_tsemaGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x100))(param_1 + 0x18);
  return;
}


// ===== 0019f790 __nvoc_up_thunk_RmResource_tsemaGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x110))(param_1 + 0x18);
  return;
}


// ===== 0019f7b0 __nvoc_up_thunk_RmResource_tsemaControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x118))(param_1 + 0x18);
  return;
}


// ===== 0019f7d0 __nvoc_up_thunk_RmResource_tsemaControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x120))(param_1 + 0x18);
  return;
}


// ===== 0019f7f0 __nvoc_up_thunk_RmResource_tsemaControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x128))(param_1 + 0x18);
  return;
}


// ===== 0019f810 __nvoc_up_thunk_RmResource_tsemaControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tsemaControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x130))(param_1 + 0x18);
  return;
}


// ===== 0019f830 __nvoc_up_thunk_RsResource_tsemaCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x30))(param_1 + 0x20);
  return;
}


// ===== 0019f850 __nvoc_up_thunk_RsResource_tsemaIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x38))(param_1 + 0x20);
  return;
}


// ===== 0019f870 __nvoc_up_thunk_RsResource_tsemaPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x40))(param_1 + 0x20);
  return;
}


// ===== 0019f890 __nvoc_up_thunk_RsResource_tsemaControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x50))(param_1 + 0x20);
  return;
}


// ===== 0019f8b0 __nvoc_up_thunk_RsResource_tsemaIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x88))(param_1 + 0x20);
  return;
}


// ===== 0019f8d0 __nvoc_up_thunk_RsResource_tsemaMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x90))(param_1 + 0x20);
  return;
}


// ===== 0019f8f0 __nvoc_up_thunk_RsResource_tsemaUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x98))(param_1 + 0x20);
  return;
}


// ===== 0019f910 __nvoc_up_thunk_RsResource_tsemaGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0xa0))(param_1 + 0x20);
  return;
}


// ===== 0019f930 __nvoc_up_thunk_RsResource_tsemaAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tsemaAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x20) + 0xb8))(param_1,param_2 + 0x20);
  return;
}


// ===== 0019f950 __nvoc_up_thunk_Notifier_tsemaGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tsemaGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x58))(param_1 + 0x110);
  return;
}


// ===== 0019f970 __nvoc_up_thunk_Notifier_tsemaGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tsemaGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x60))(param_1 + 0x110);
  return;
}


// ===== 0019f990 __nvoc_up_thunk_Notifier_tsemaSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tsemaSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x68))(param_1 + 0x110);
  return;
}


// ===== 0019f9b0 __nvoc_up_thunk_Notifier_tsemaUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tsemaUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x70))(param_1 + 0x110);
  return;
}


// ===== 0019f9d0 __nvoc_up_thunk_Notifier_tsemaGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tsemaGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x78))(param_1 + 0x110);
  return;
}


// ===== 0019f9f0 __nvoc_dtor_TimedSemaSwObject =====

void __nvoc_dtor_TimedSemaSwObject(long param_1)

{
  tsemaDestruct_IMPL();
  __nvoc_dtor_ChannelDescendant(param_1 + 8);
  return;
}


// ===== 0019fa20 __nvoc_objCreate_TimedSemaSwObject =====

int __nvoc_objCreate_TimedSemaSwObject
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(600);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_timed_sema_nvoc.c",0x2b0);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_timed_sema_nvoc.c",0x2a8);
    return 0x3b;
  }
  portMemSet(puVar4,0,600);
  *(uint *)((long)puVar4 + 0x54) = param_3;
  if (param_2 == 0) {
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_timed_sema_nvoc.c",0x2b9);
    iVar2 = 0x1f;
    goto LAB_0019fbac;
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
    if (lVar3 != 0) goto LAB_0019fab4;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_timed_sema_nvoc.c",0x2c9);
    iVar2 = 0x1f;
  }
  else {
LAB_0019fab4:
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
    puVar4[5] = 0xc75658;
    puVar4[4] = 0xc75640;
    puVar4[0x11] = 0xc75700;
    puVar4[3] = 0xc75628;
    puVar4[2] = 0xc75610;
    puVar4[0x23] = 0xc758a0;
    puVar4[0x22] = 0xc75888;
    puVar4[1] = 0xc755f8;
    *puVar4 = __nvoc_metadata__TimedSemaSwObject;
    iVar2 = __nvoc_ctor_ChannelDescendant(puVar1,lVar3,param_4,param_5,0);
    if (iVar2 == 0) {
      iVar2 = tsemaConstruct_IMPL(puVar4,param_4,param_5);
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
LAB_0019fbac:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,600);
  }
  return iVar2;
}


// ===== 0019fd70 __nvoc_objCreateDynamic_TimedSemaSwObject =====

void __nvoc_objCreateDynamic_TimedSemaSwObject
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
      goto LAB_0019fd9e;
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
LAB_0019fd9e:
  __nvoc_objCreate_TimedSemaSwObject(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019fdd0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019fde0 __nvoc_down_thunk_TimerApi_gpuresGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_TimerApi_gpuresGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x310))(param_1 + -8);
  return;
}


// ===== 0019fe00 __nvoc_up_thunk_GpuResource_tmrapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 0019fe20 __nvoc_up_thunk_GpuResource_tmrapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 0019fe40 __nvoc_up_thunk_GpuResource_tmrapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 0019fe60 __nvoc_up_thunk_GpuResource_tmrapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 0019fe80 __nvoc_up_thunk_GpuResource_tmrapiGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 0019fea0 __nvoc_up_thunk_GpuResource_tmrapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 0019fec0 __nvoc_up_thunk_GpuResource_tmrapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_tmrapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 0019fee0 __nvoc_up_thunk_RmResource_tmrapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 0019ff00 __nvoc_up_thunk_RmResource_tmrapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 0019ff20 __nvoc_up_thunk_RmResource_tmrapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 0019ff40 __nvoc_up_thunk_RmResource_tmrapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 0019ff60 __nvoc_up_thunk_RmResource_tmrapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 0019ff80 __nvoc_up_thunk_RmResource_tmrapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 0019ffa0 __nvoc_up_thunk_RmResource_tmrapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 0019ffc0 __nvoc_up_thunk_RmResource_tmrapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_tmrapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 0019ffe0 __nvoc_up_thunk_RsResource_tmrapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 001a0000 __nvoc_up_thunk_RsResource_tmrapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 001a0020 __nvoc_up_thunk_RsResource_tmrapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001a0040 __nvoc_up_thunk_RsResource_tmrapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001a0060 __nvoc_up_thunk_RsResource_tmrapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001a0080 __nvoc_up_thunk_RsResource_tmrapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 001a00a0 __nvoc_up_thunk_RsResource_tmrapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 001a00c0 __nvoc_up_thunk_RsResource_tmrapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 001a00e0 __nvoc_up_thunk_RsResource_tmrapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_tmrapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 001a0100 __nvoc_up_thunk_Notifier_tmrapiGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tmrapiGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x58))(param_1 + 0x108);
  return;
}


// ===== 001a0120 __nvoc_up_thunk_Notifier_tmrapiGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tmrapiGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x60))(param_1 + 0x108);
  return;
}


// ===== 001a0140 __nvoc_up_thunk_Notifier_tmrapiSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tmrapiSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x68))(param_1 + 0x108);
  return;
}


// ===== 001a0160 __nvoc_up_thunk_Notifier_tmrapiUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tmrapiUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x70))(param_1 + 0x108);
  return;
}


// ===== 001a0180 __nvoc_up_thunk_Notifier_tmrapiGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_tmrapiGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x78))(param_1 + 0x108);
  return;
}


// ===== 001a01a0 __nvoc_dtor_TimerApi =====

void __nvoc_dtor_TimerApi(long param_1)

{
  tmrapiDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  __nvoc_dtor_Notifier(param_1 + 0x108);
  return;
}


// ===== 001a01d0 __nvoc_ctor_TimerApi =====

ulong __nvoc_ctor_TimerApi(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_GpuResource(param_1 + 8);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar1 = __nvoc_ctor_Notifier(param_1 + 0x108,param_2);
  if (uVar1 == 0) {
    uVar2 = tmrapiConstruct_IMPL(param_1,param_2,param_3);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0) {
      return uVar2;
    }
    __nvoc_dtor_Notifier(param_1 + 0x108);
  }
  __nvoc_dtor_GpuResource(param_1 + 8);
  return (ulong)uVar1;
}


// ===== 001a0270 __nvoc_objCreate_TimerApi =====

int __nvoc_objCreate_TimerApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x178);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_tmr_nvoc.c",0x247);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL","generated/g_tmr_nvoc.c",
                       0x23f);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x178);
  puVar1 = puVar3 + 4;
  *(uint *)((long)puVar3 + 0x4c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[6] = 0;
    lVar4 = 0;
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
  }
  puVar3[0x27] = puVar1;
  puVar3[0x28] = puVar3 + 3;
  puVar3[0x29] = puVar3 + 0x10;
  puVar3[0x2a] = puVar3 + 2;
  puVar3[0x2c] = puVar3 + 0x22;
  puVar3[0x2b] = puVar3 + 1;
  puVar3[0x2d] = puVar3 + 0x21;
  puVar3[0x2e] = puVar3;
  __nvoc_init__GpuResource();
  __nvoc_init__Notifier(puVar3 + 0x21);
  puVar3[4] = 0xc75d40;
  puVar3[3] = 0xc75d28;
  puVar3[0x10] = 0xc75de8;
  puVar3[2] = 0xc75d10;
  puVar3[1] = 0xc75cf8;
  puVar3[0x22] = 0xc75f88;
  puVar3[0x21] = 0xc75f70;
  *puVar3 = __nvoc_metadata__TimerApi;
  iVar2 = __nvoc_ctor_TimerApi(puVar3,param_4,param_5);
  if (iVar2 == 0) {
    *param_1 = (long)puVar3;
  }
  else {
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
    if ((param_3 & 2) == 0) {
      portMemFree(puVar3);
      *param_1 = 0;
    }
    else {
      portMemSet(puVar3,0,0x178);
    }
  }
  return iVar2;
}


// ===== 001a04c0 __nvoc_objCreateDynamic_TimerApi =====

void __nvoc_objCreateDynamic_TimerApi
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
      goto LAB_001a04ee;
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
LAB_001a04ee:
  __nvoc_objCreate_TimerApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a0520 __nvoc_dtor_OBJTRACEABLE =====

void __nvoc_dtor_OBJTRACEABLE(void)

{
  return;
}


// ===== 001a0530 __nvoc_ctor_OBJTRACEABLE =====

undefined8 __nvoc_ctor_OBJTRACEABLE(void)

{
  return 0;
}


// ===== 001a0540 __nvoc_init__OBJTRACEABLE =====

void __nvoc_init__OBJTRACEABLE(undefined8 *param_1)

{
  param_1[1] = param_1;
  *param_1 = __nvoc_metadata__OBJTRACEABLE;
  return;
}


// ===== 001a0550 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a0560 memCheckMemInterUnmap_ac1694 =====

undefined8 memCheckMemInterUnmap_ac1694(void)

{
  return 0;
}


// ===== 001a0570 memCheckCopyPermissions_ac1694 =====

undefined8 memCheckCopyPermissions_ac1694(void)

{
  return 0;
}


// ===== 001a0580 memIsGpuMapAllowed_e661f0 =====

undefined8 memIsGpuMapAllowed_e661f0(void)

{
  return 1;
}


// ===== 001a0590 memIsExportAllowed_e661f0 =====

undefined8 memIsExportAllowed_e661f0(void)

{
  return 1;
}


// ===== 001a05a0 __nvoc_down_thunk_UserModeApi_resCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_UserModeApi_resCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x298))(param_1 + -0x18);
  return;
}


// ===== 001a05c0 __nvoc_down_thunk_UserModeApi_memGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_UserModeApi_memGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x2a0))(param_1 + -8);
  return;
}


// ===== 001a05e0 __nvoc_up_thunk_Memory_usrmodeIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001a0600 __nvoc_up_thunk_Memory_usrmodeGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001a0620 __nvoc_up_thunk_Memory_usrmodeControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 001a0640 __nvoc_up_thunk_Memory_usrmodeMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001a0660 __nvoc_up_thunk_Memory_usrmodeUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 001a0680 __nvoc_up_thunk_Memory_usrmodeCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8,param_2);
  return;
}


// ===== 001a06a0 __nvoc_up_thunk_Memory_usrmodeGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001a06c0 __nvoc_up_thunk_Memory_usrmodeCheckCopyPermissions =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeCheckCopyPermissions(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1f0))(param_1 + 8);
  return;
}


// ===== 001a06e0 __nvoc_up_thunk_Memory_usrmodeIsReady =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeIsReady(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1f8))(param_1 + 8,param_2);
  return;
}


// ===== 001a0700 __nvoc_up_thunk_Memory_usrmodeIsGpuMapAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeIsGpuMapAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x200))(param_1 + 8);
  return;
}


// ===== 001a0720 __nvoc_up_thunk_Memory_usrmodeIsExportAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_usrmodeIsExportAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x208))(param_1 + 8);
  return;
}


// ===== 001a0740 __nvoc_up_thunk_RmResource_usrmodeAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_usrmodeAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001a0760 __nvoc_up_thunk_RmResource_usrmodeShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_usrmodeShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf8))(param_1 + 0x10);
  return;
}


// ===== 001a0780 __nvoc_up_thunk_RmResource_usrmodeControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_usrmodeControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 001a07a0 __nvoc_up_thunk_RmResource_usrmodeControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_usrmodeControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 001a07c0 __nvoc_up_thunk_RmResource_usrmodeControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_usrmodeControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 001a07e0 __nvoc_up_thunk_RmResource_usrmodeControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_usrmodeControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 001a0800 __nvoc_up_thunk_RsResource_usrmodePreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodePreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001a0820 __nvoc_up_thunk_RsResource_usrmodeControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodeControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001a0840 __nvoc_up_thunk_RsResource_usrmodeIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodeIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001a0860 __nvoc_up_thunk_RsResource_usrmodeMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodeMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 001a0880 __nvoc_up_thunk_RsResource_usrmodeUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodeUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 001a08a0 __nvoc_up_thunk_RsResource_usrmodeGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodeGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 001a08c0 __nvoc_up_thunk_RsResource_usrmodeAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_usrmodeAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 001a08e0 __nvoc_dtor_UserModeApi =====

void __nvoc_dtor_UserModeApi(long param_1)

{
  __nvoc_dtor_Memory(param_1 + 8);
  return;
}


// ===== 001a08f0 __nvoc_objCreate_UserModeApi =====

int __nvoc_objCreate_UserModeApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x228);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_usermode_api_nvoc.c",0x1e9);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_usermode_api_nvoc.c",0x1e1);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x228);
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
  puVar4[0x3e] = puVar1;
  puVar4[0x3f] = puVar4 + 3;
  puVar4[0x40] = puVar4 + 0x10;
  puVar4[0x41] = puVar4 + 2;
  puVar4[0x42] = puVar2;
  puVar4[0x43] = puVar4;
  __nvoc_init__Memory(puVar2);
  puVar4[4] = 0xc76320;
  puVar4[3] = 0xc76308;
  puVar4[0x10] = 0xc763c8;
  puVar4[2] = 0xc762f0;
  puVar4[1] = 0xc762d8;
  *puVar4 = __nvoc_metadata__UserModeApi;
  iVar3 = __nvoc_ctor_Memory(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = usrmodeConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_Memory(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x228);
  }
  return iVar3;
}


// ===== 001a0b70 __nvoc_objCreateDynamic_UserModeApi =====

void __nvoc_objCreateDynamic_UserModeApi
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
      goto LAB_001a0b9e;
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
LAB_001a0b9e:
  __nvoc_objCreate_UserModeApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a0bd0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a0be0 __nvoc_up_thunk_GpuResource_uvmchanrtnrControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001a0c00 __nvoc_up_thunk_GpuResource_uvmchanrtnrMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001a0c20 __nvoc_up_thunk_GpuResource_uvmchanrtnrUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 001a0c40 __nvoc_up_thunk_GpuResource_uvmchanrtnrShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001a0c60 __nvoc_up_thunk_GpuResource_uvmchanrtnrGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 001a0c80 __nvoc_up_thunk_GpuResource_uvmchanrtnrGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 001a0ca0 __nvoc_up_thunk_GpuResource_uvmchanrtnrInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 001a0cc0 __nvoc_up_thunk_GpuResource_uvmchanrtnrGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmchanrtnrGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001a0ce0 __nvoc_up_thunk_RmResource_uvmchanrtnrAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001a0d00 __nvoc_up_thunk_RmResource_uvmchanrtnrGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 001a0d20 __nvoc_up_thunk_RmResource_uvmchanrtnrCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 001a0d40 __nvoc_up_thunk_RmResource_uvmchanrtnrGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 001a0d60 __nvoc_up_thunk_RmResource_uvmchanrtnrControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 001a0d80 __nvoc_up_thunk_RmResource_uvmchanrtnrControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 001a0da0 __nvoc_up_thunk_RmResource_uvmchanrtnrControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 001a0dc0 __nvoc_up_thunk_RmResource_uvmchanrtnrControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmchanrtnrControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 001a0de0 __nvoc_up_thunk_RsResource_uvmchanrtnrCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 001a0e00 __nvoc_up_thunk_RsResource_uvmchanrtnrIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 001a0e20 __nvoc_up_thunk_RsResource_uvmchanrtnrPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001a0e40 __nvoc_up_thunk_RsResource_uvmchanrtnrControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001a0e60 __nvoc_up_thunk_RsResource_uvmchanrtnrIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001a0e80 __nvoc_up_thunk_RsResource_uvmchanrtnrMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 001a0ea0 __nvoc_up_thunk_RsResource_uvmchanrtnrUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 001a0ec0 __nvoc_up_thunk_RsResource_uvmchanrtnrGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 001a0ee0 __nvoc_up_thunk_RsResource_uvmchanrtnrAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmchanrtnrAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 001a0f00 __nvoc_dtor_UvmChannelRetainer =====

void __nvoc_dtor_UvmChannelRetainer(long param_1)

{
  uvmchanrtnrDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 001a0f30 __nvoc_objCreate_UvmChannelRetainer =====

int __nvoc_objCreate_UvmChannelRetainer
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x148);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_uvm_channel_retainer_nvoc.c",0x1ed);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_uvm_channel_retainer_nvoc.c",0x1e5);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x148);
  *(uint *)((long)puVar4 + 0x4c) = param_3;
  if (param_2 == 0) {
    nvCheckOkFailedNoLog
              (4,0x1f,"__nvoc_pParent != NULL","generated/g_uvm_channel_retainer_nvoc.c",0x1f6);
    iVar2 = 0x1f;
    goto LAB_001a1069;
  }
  if ((param_3 & 1) == 0) {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar4 + 4);
  }
  else {
    puVar4[6] = 0;
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
    if (lVar3 != 0) goto LAB_001a0fc1;
    nvCheckOkFailedNoLog
              (4,0x1f,"pRmhalspecowner != NULL","generated/g_uvm_channel_retainer_nvoc.c",0x206);
    iVar2 = 0x1f;
  }
  else {
LAB_001a0fc1:
    puVar1 = puVar4 + 1;
    puVar4[0x26] = puVar4;
    puVar4[0x21] = puVar4 + 4;
    puVar4[0x22] = puVar4 + 3;
    puVar4[0x23] = puVar4 + 0x10;
    puVar4[0x24] = puVar4 + 2;
    puVar4[0x25] = puVar1;
    __nvoc_init__GpuResource(puVar1);
    puVar4[4] = 0xc767c0;
    puVar4[3] = 0xc767a8;
    puVar4[0x10] = 0xc76868;
    puVar4[2] = 0xc76790;
    puVar4[1] = 0xc76778;
    *puVar4 = __nvoc_metadata__UvmChannelRetainer;
    iVar2 = __nvoc_ctor_GpuResource(puVar1,param_4,param_5);
    if (iVar2 == 0) {
      iVar2 = uvmchanrtnrConstruct_IMPL(puVar4,param_4,param_5);
      if (iVar2 == 0) {
        *param_1 = (long)puVar4;
        return 0;
      }
      __nvoc_dtor_GpuResource(puVar1);
    }
  }
  if (lVar5 != 0) {
    objRemoveChild_IMPL(lVar5,puVar4 + 4);
  }
LAB_001a1069:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x148);
  }
  return iVar2;
}


// ===== 001a1230 __nvoc_objCreateDynamic_UvmChannelRetainer =====

void __nvoc_objCreateDynamic_UvmChannelRetainer
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
      goto LAB_001a125e;
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
LAB_001a125e:
  __nvoc_objCreate_UvmChannelRetainer(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a1290 uvmInitAccessCntrBuffer_ac1694 =====

undefined8 uvmInitAccessCntrBuffer_ac1694(void)

{
  return 0;
}


// ===== 001a12a0 uvmAccessCntrBufferUnregister_ac1694 =====

undefined8 uvmAccessCntrBufferUnregister_ac1694(void)

{
  return 0;
}


// ===== 001a12b0 uvmAccessCntrBufferRegister_ac1694 =====

undefined8 uvmAccessCntrBufferRegister_ac1694(void)

{
  return 0;
}


// ===== 001a12c0 uvmReadAccessCntrBufferPutPtr_395e98 =====

undefined8 uvmReadAccessCntrBufferPutPtr_395e98(void)

{
  return 0x56;
}


// ===== 001a12d0 uvmAccessCntrSetGranularity_395e98 =====

undefined8 uvmAccessCntrSetGranularity_395e98(void)

{
  return 0x56;
}


// ===== 001a12e0 uvmAccessCntrSetThreshold_395e98 =====

undefined8 uvmAccessCntrSetThreshold_395e98(void)

{
  return 0x56;
}


// ===== 001a12f0 uvmEnableAccessCntr_395e98 =====

undefined8 uvmEnableAccessCntr_395e98(void)

{
  return 0x56;
}


// ===== 001a1300 uvmEnableAccessCntrIntr_395e98 =====

undefined8 uvmEnableAccessCntrIntr_395e98(void)

{
  return 0x56;
}


// ===== 001a1310 uvmDisableAccessCntrIntr_395e98 =====

undefined8 uvmDisableAccessCntrIntr_395e98(void)

{
  return 0x56;
}


// ===== 001a1320 uvmGetAccessCntrRegisterMappings_395e98 =====

undefined8 uvmGetAccessCntrRegisterMappings_395e98(void)

{
  return 0x56;
}


// ===== 001a1330 uvmGetRegOffsetAccessCntrBufferPut_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferPut_b2b553(void)

{
  return 0;
}


// ===== 001a1340 __nvoc_down_thunk_OBJUVM_engstateStateDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_OBJUVM_engstateStateDestroy(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -8) + 0xf0))(param_1,param_2 + -8);
  return;
}


// ===== 001a1360 __nvoc_down_thunk_OBJUVM_engstateStateInitUnlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_OBJUVM_engstateStateInitUnlocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -8) + 0xf8))(param_1,param_2 + -8);
  return;
}


// ===== 001a1380 __nvoc_down_thunk_OBJUVM_intrservRegisterIntrService =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_OBJUVM_intrservRegisterIntrService(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -0x150) + 0x100))(param_1,param_2 + -0x150);
  return;
}


// ===== 001a13a0 __nvoc_down_thunk_OBJUVM_intrservServiceInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_OBJUVM_intrservServiceInterrupt(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -0x150) + 0x108))(param_1,param_2 + -0x150);
  return;
}


// ===== 001a13c0 __nvoc_up_thunk_OBJENGSTATE_uvmConstructEngine =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmConstructEngine(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x30))(param_1,param_2 + 8);
  return;
}


// ===== 001a13e0 __nvoc_up_thunk_OBJENGSTATE_uvmInitMissing =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmInitMissing(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x38))(param_1,param_2 + 8);
  return;
}


// ===== 001a1400 __nvoc_up_thunk_OBJENGSTATE_uvmStatePreInitLocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStatePreInitLocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x40))(param_1,param_2 + 8);
  return;
}


// ===== 001a1420 __nvoc_up_thunk_OBJENGSTATE_uvmStatePreInitUnlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStatePreInitUnlocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x48))(param_1,param_2 + 8);
  return;
}


// ===== 001a1440 __nvoc_up_thunk_OBJENGSTATE_uvmStateInitLocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStateInitLocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x50))(param_1,param_2 + 8);
  return;
}


// ===== 001a1460 __nvoc_up_thunk_OBJENGSTATE_uvmStatePreLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStatePreLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x60))(param_1,param_2 + 8);
  return;
}


// ===== 001a1480 __nvoc_up_thunk_OBJENGSTATE_uvmStateLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStateLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x68))(param_1,param_2 + 8);
  return;
}


// ===== 001a14a0 __nvoc_up_thunk_OBJENGSTATE_uvmStatePostLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStatePostLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x70))(param_1,param_2 + 8);
  return;
}


// ===== 001a14c0 __nvoc_up_thunk_OBJENGSTATE_uvmStatePreUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStatePreUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x78))(param_1,param_2 + 8);
  return;
}


// ===== 001a14e0 __nvoc_up_thunk_OBJENGSTATE_uvmStateUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStateUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x80))(param_1,param_2 + 8);
  return;
}


// ===== 001a1500 __nvoc_up_thunk_OBJENGSTATE_uvmStatePostUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmStatePostUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x88))(param_1,param_2 + 8);
  return;
}


// ===== 001a1520 __nvoc_up_thunk_OBJENGSTATE_uvmIsPresent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_uvmIsPresent(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x98))(param_1,param_2 + 8);
  return;
}


// ===== 001a1540 __nvoc_up_thunk_IntrService_uvmClearInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_IntrService_uvmClearInterrupt(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x150) + 0x20))(param_1,param_2 + 0x150);
  return;
}


// ===== 001a1560 __nvoc_up_thunk_IntrService_uvmServiceNotificationInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_IntrService_uvmServiceNotificationInterrupt(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x150) + 0x30))(param_1,param_2 + 0x150);
  return;
}


// ===== 001a1580 __nvoc_init_funcTable_OBJUVM_1 =====

void __nvoc_init_funcTable_OBJUVM_1(long param_1,long param_2,long param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  code *pcVar4;
  ulong uVar5;
  code *pcVar6;
  uint uVar7;
  bool bVar9;
  uint uVar8;
  
  uVar1 = *(ushort *)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_3 + 0x10);
  uVar3 = uVar1 >> 5;
  uVar7 = (uint)uVar1;
  uVar8 = (uint)uVar1;
  if (uVar3 == 1) {
    if ((uVar1 & 0x1f) == 0x1d) {
      *(code **)(param_1 + 0x180) = uvmInitAccessCntrBuffer_ac1694;
      *(code **)(param_1 + 0x188) = uvmDestroyAccessCntrBuffer_ac1694;
      if ((uVar2 >> 5 == 0) && (uVar2 == 0)) {
        *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_IMPL;
        *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_IMPL;
      }
      else {
        *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_ac1694;
        *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_ac1694;
      }
LAB_001a1d96:
      *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_ac1694;
      *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_ac1694;
      *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_395e98;
      *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_395e98;
      *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_395e98;
      *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_395e98;
      *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_395e98;
      *(code **)(param_1 + 0x1d8) = uvmAccessCntrSetCounterLimit_395e98;
      *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_395e98;
LAB_001a1c8b:
      *(code **)(param_1 + 0x1e8) = uvmEnableAccessCntr_395e98;
      *(code **)(param_1 + 0x1f0) = uvmDisableAccessCntr_395e98;
      *(code **)(param_1 + 0x1f8) = uvmEnableAccessCntrIntr_395e98;
      uVar5 = 0x98000000L >> (sbyte)(uVar8 & 0x1f);
      *(code **)(param_1 + 0x200) = uvmDisableAccessCntrIntr_395e98;
      *(code **)(param_1 + 0x208) = uvmGetAccessCntrRegisterMappings_395e98;
      *(code **)(param_1 + 0x210) = uvmAccessCntrService_395e98;
      *(code **)(param_1 + 0x218) = uvmGetAccessCounterBufferSize_b2b553;
      *(code **)(param_1 + 0x220) = uvmProgramWriteAccessCntrBufferAddress_f2d351;
      *(code **)(param_1 + 0x228) = uvmProgramAccessCntrBufferEnabled_f2d351;
      *(code **)(param_1 + 0x230) = uvmIsAccessCntrBufferEnabled_72a2e1;
      *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_72a2e1;
      if ((0x5f0ffe0UL >> (uVar8 & 0x1f) & 1) != 0) {
        *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_TU102;
        if ((uVar5 & 1) != 0) goto LAB_001a1e28;
        goto LAB_001a18b8;
      }
      *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_b2b553;
      if ((uVar5 & 1) != 0) goto LAB_001a1e28;
    }
    else {
LAB_001a1917:
      *(code **)(param_1 + 0x180) = uvmInitAccessCntrBuffer_GV100;
      *(code **)(param_1 + 0x188) = uvmDestroyAccessCntrBuffer_GV100;
      if ((uVar2 >> 5 == 0) && (uVar2 == 0)) {
        *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_IMPL;
        *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_IMPL;
        if (uVar3 != 1) goto LAB_001a1961;
LAB_001a1bf8:
        if ((short)(uVar8 & 0x1f) == 0x1d) goto LAB_001a1d96;
        *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_GV100;
        *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_GV100;
        pcVar6 = uvmAccessCntrSetCounterLimit_GV100;
        *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_TU102;
        if ((0x5f0ffe0UL >> (uVar8 & 0x1f) & 1) == 0) {
          pcVar6 = uvmAccessCntrSetCounterLimit_395e98;
        }
        *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_TU102;
        *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_TU102;
        *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_TU102;
        *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_TU102;
        *(code **)(param_1 + 0x1d8) = pcVar6;
        *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_TU102;
        if (uVar1 == 0x3d) goto LAB_001a1c8b;
      }
      else {
        *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_ac1694;
        *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_ac1694;
        if (uVar3 == 1) goto LAB_001a1bf8;
LAB_001a1961:
        if (uVar3 == 3) goto LAB_001a1604;
        *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_GV100;
        *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_GV100;
        *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_TU102;
        *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_TU102;
        *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_TU102;
        *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_TU102;
        *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_TU102;
        *(code **)(param_1 + 0x1d8) = uvmAccessCntrSetCounterLimit_395e98;
        *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_TU102;
      }
      *(code **)(param_1 + 0x1e8) = uvmEnableAccessCntr_TU102;
      *(code **)(param_1 + 0x1f0) = uvmDisableAccessCntr_GV100;
      *(code **)(param_1 + 0x1f8) = uvmEnableAccessCntrIntr_TU102;
      *(code **)(param_1 + 0x200) = uvmDisableAccessCntrIntr_TU102;
      *(code **)(param_1 + 0x208) = uvmGetAccessCntrRegisterMappings_TU102;
      *(code **)(param_1 + 0x210) = uvmAccessCntrService_TU102;
      *(code **)(param_1 + 0x218) = uvmGetAccessCounterBufferSize_TU102;
      *(code **)(param_1 + 0x220) = uvmProgramWriteAccessCntrBufferAddress_TU102;
      *(code **)(param_1 + 0x228) = uvmProgramAccessCntrBufferEnabled_TU102;
      *(code **)(param_1 + 0x230) = uvmIsAccessCntrBufferEnabled_TU102;
      if (uVar3 == 1) {
        *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_TU102;
        if ((0x98000000UL >> (uVar8 & 0x1f) & 1) != 0) goto LAB_001a1e1d;
        if ((0x5f0ffe0UL >> (uVar8 & 0x1f) & 1) != 0) goto LAB_001a18ad;
        *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_b2b553;
      }
      else {
        *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_TU102;
        if (uVar1 == 0x40) {
LAB_001a1e1d:
          *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_GB100;
LAB_001a1e28:
          *(code **)(param_1 + 0x248) = uvmGetRegOffsetAccessCntrBufferGet_GB100;
          *(code **)(param_1 + 0x250) = uvmGetRegOffsetAccessCntrBufferHi_GB100;
          *(code **)(param_1 + 600) = uvmGetRegOffsetAccessCntrBufferLo_GB100;
          *(code **)(param_1 + 0x260) = uvmGetRegOffsetAccessCntrBufferConfig_GB100;
          *(code **)(param_1 + 0x268) = uvmGetRegOffsetAccessCntrBufferInfo_GB100;
          *(code **)(param_1 + 0x270) = uvmGetRegOffsetAccessCntrBufferSize_GB100;
          return;
        }
        *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_b2b553;
        if (uVar3 == 2) goto LAB_001a1b78;
      }
    }
  }
  else {
    if (uVar3 == 2) {
      pcVar6 = uvmInitAccessCntrBuffer_ac1694;
      bVar9 = (0x300UL >> ((byte)uVar1 & 0x1f) & 1) == 0;
      if (bVar9) {
        pcVar6 = uvmInitAccessCntrBuffer_GV100;
      }
      pcVar4 = uvmDestroyAccessCntrBuffer_ac1694;
      if (bVar9) {
        pcVar4 = uvmDestroyAccessCntrBuffer_GV100;
      }
      *(code **)(param_1 + 0x180) = pcVar6;
      *(code **)(param_1 + 0x188) = pcVar4;
      if ((uVar2 >> 5 == 0) && (uVar2 == 0)) {
        *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_IMPL;
        *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_IMPL;
      }
      else {
        *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_ac1694;
        *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_ac1694;
      }
      if ((0x300UL >> (uVar7 & 0x1f) & 1) == 0) {
        *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_GV100;
        *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_GV100;
        *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_TU102;
        *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_TU102;
        *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_TU102;
        *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_TU102;
        *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_TU102;
        *(code **)(param_1 + 0x1d8) = uvmAccessCntrSetCounterLimit_395e98;
        *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_TU102;
        *(code **)(param_1 + 0x1e8) = uvmEnableAccessCntr_TU102;
        *(code **)(param_1 + 0x1f0) = uvmDisableAccessCntr_GV100;
        *(code **)(param_1 + 0x1f8) = uvmEnableAccessCntrIntr_TU102;
        *(code **)(param_1 + 0x200) = uvmDisableAccessCntrIntr_TU102;
        *(code **)(param_1 + 0x208) = uvmGetAccessCntrRegisterMappings_TU102;
        *(code **)(param_1 + 0x210) = uvmAccessCntrService_TU102;
        *(code **)(param_1 + 0x218) = uvmGetAccessCounterBufferSize_TU102;
        *(code **)(param_1 + 0x220) = uvmProgramWriteAccessCntrBufferAddress_TU102;
        *(code **)(param_1 + 0x228) = uvmProgramAccessCntrBufferEnabled_TU102;
        *(code **)(param_1 + 0x230) = uvmIsAccessCntrBufferEnabled_TU102;
        *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_TU102;
      }
      else {
        *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_ac1694;
        *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_ac1694;
        *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_395e98;
        *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_395e98;
        *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_395e98;
        *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_395e98;
        *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_395e98;
        *(code **)(param_1 + 0x1d8) = uvmAccessCntrSetCounterLimit_395e98;
        *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_395e98;
        *(code **)(param_1 + 0x1e8) = uvmEnableAccessCntr_395e98;
        *(code **)(param_1 + 0x1f0) = uvmDisableAccessCntr_395e98;
        *(code **)(param_1 + 0x1f8) = uvmEnableAccessCntrIntr_395e98;
        *(code **)(param_1 + 0x200) = uvmDisableAccessCntrIntr_395e98;
        *(code **)(param_1 + 0x208) = uvmGetAccessCntrRegisterMappings_395e98;
        *(code **)(param_1 + 0x210) = uvmAccessCntrService_395e98;
        *(code **)(param_1 + 0x218) = uvmGetAccessCounterBufferSize_b2b553;
        *(code **)(param_1 + 0x220) = uvmProgramWriteAccessCntrBufferAddress_f2d351;
        *(code **)(param_1 + 0x228) = uvmProgramAccessCntrBufferEnabled_f2d351;
        *(code **)(param_1 + 0x230) = uvmIsAccessCntrBufferEnabled_72a2e1;
        *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_72a2e1;
      }
      if ((0xf8UL >> (uVar7 & 0x1f) & 1) != 0) {
LAB_001a18ad:
        *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_TU102;
LAB_001a18b8:
        *(code **)(param_1 + 0x248) = uvmGetRegOffsetAccessCntrBufferGet_TU102;
        *(code **)(param_1 + 0x250) = uvmGetRegOffsetAccessCntrBufferHi_TU102;
        *(code **)(param_1 + 600) = uvmGetRegOffsetAccessCntrBufferLo_TU102;
        *(code **)(param_1 + 0x260) = uvmGetRegOffsetAccessCntrBufferConfig_TU102;
        *(code **)(param_1 + 0x268) = uvmGetRegOffsetAccessCntrBufferInfo_TU102;
        *(code **)(param_1 + 0x270) = uvmGetRegOffsetAccessCntrBufferSize_TU102;
        return;
      }
      if (uVar1 != 0x40) {
        *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_b2b553;
LAB_001a1b78:
        if ((0xf8UL >> (uVar8 & 0x1f) & 1) != 0) goto LAB_001a18b8;
        *(code **)(param_1 + 0x248) = uvmGetRegOffsetAccessCntrBufferGet_b2b553;
        *(code **)(param_1 + 0x250) = uvmGetRegOffsetAccessCntrBufferHi_b2b553;
        *(code **)(param_1 + 600) = uvmGetRegOffsetAccessCntrBufferLo_b2b553;
        *(code **)(param_1 + 0x260) = uvmGetRegOffsetAccessCntrBufferConfig_b2b553;
        goto LAB_001a1bb6;
      }
      goto LAB_001a1e1d;
    }
    if ((uVar3 != 3) || ((0xa000UL >> (uVar7 & 0x1f) & 1) == 0)) goto LAB_001a1917;
    *(code **)(param_1 + 0x180) = uvmInitAccessCntrBuffer_ac1694;
    *(code **)(param_1 + 0x188) = uvmDestroyAccessCntrBuffer_ac1694;
    if ((uVar2 >> 5 == 0) && (uVar2 == 0)) {
      *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_IMPL;
      *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_IMPL;
    }
    else {
      *(code **)(param_1 + 400) = uvmAccessCntrBufferUnregister_ac1694;
      *(code **)(param_1 + 0x198) = uvmAccessCntrBufferRegister_ac1694;
    }
LAB_001a1604:
    if ((0xa000UL >> (uVar7 & 0x1f) & 1) == 0) {
      *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_GV100;
      *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_GV100;
      *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_TU102;
      *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_TU102;
      *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_TU102;
      *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_TU102;
      *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_TU102;
      *(code **)(param_1 + 0x1d8) = uvmAccessCntrSetCounterLimit_395e98;
      *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_TU102;
      *(code **)(param_1 + 0x1e8) = uvmEnableAccessCntr_TU102;
      *(code **)(param_1 + 0x1f0) = uvmDisableAccessCntr_GV100;
      *(code **)(param_1 + 0x1f8) = uvmEnableAccessCntrIntr_TU102;
      *(code **)(param_1 + 0x200) = uvmDisableAccessCntrIntr_TU102;
      *(code **)(param_1 + 0x208) = uvmGetAccessCntrRegisterMappings_TU102;
      *(code **)(param_1 + 0x210) = uvmAccessCntrService_TU102;
      *(code **)(param_1 + 0x218) = uvmGetAccessCounterBufferSize_TU102;
      *(code **)(param_1 + 0x220) = uvmProgramWriteAccessCntrBufferAddress_TU102;
      *(code **)(param_1 + 0x228) = uvmProgramAccessCntrBufferEnabled_TU102;
      *(code **)(param_1 + 0x230) = uvmIsAccessCntrBufferEnabled_TU102;
      *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_TU102;
      *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_b2b553;
    }
    else {
      *(code **)(param_1 + 0x1a0) = uvmUnloadAccessCntrBuffer_ac1694;
      *(code **)(param_1 + 0x1a8) = uvmSetupAccessCntrBuffer_ac1694;
      *(code **)(param_1 + 0x1b0) = uvmReadAccessCntrBufferPutPtr_395e98;
      *(code **)(param_1 + 0x1b8) = uvmReadAccessCntrBufferGetPtr_395e98;
      *(code **)(param_1 + 0x1c0) = uvmReadAccessCntrBufferFullPtr_395e98;
      *(code **)(param_1 + 0x1c8) = uvmAccessCntrSetGranularity_395e98;
      *(code **)(param_1 + 0x1d0) = uvmAccessCntrSetThreshold_395e98;
      *(code **)(param_1 + 0x1d8) = uvmAccessCntrSetCounterLimit_395e98;
      *(code **)(param_1 + 0x1e0) = uvmWriteAccessCntrBufferGetPtr_395e98;
      *(code **)(param_1 + 0x1e8) = uvmEnableAccessCntr_395e98;
      *(code **)(param_1 + 0x1f0) = uvmDisableAccessCntr_395e98;
      *(code **)(param_1 + 0x1f8) = uvmEnableAccessCntrIntr_395e98;
      *(code **)(param_1 + 0x200) = uvmDisableAccessCntrIntr_395e98;
      *(code **)(param_1 + 0x208) = uvmGetAccessCntrRegisterMappings_395e98;
      *(code **)(param_1 + 0x210) = uvmAccessCntrService_395e98;
      *(code **)(param_1 + 0x218) = uvmGetAccessCounterBufferSize_b2b553;
      *(code **)(param_1 + 0x220) = uvmProgramWriteAccessCntrBufferAddress_f2d351;
      *(code **)(param_1 + 0x228) = uvmProgramAccessCntrBufferEnabled_f2d351;
      *(code **)(param_1 + 0x230) = uvmIsAccessCntrBufferEnabled_72a2e1;
      *(code **)(param_1 + 0x238) = uvmIsAccessCntrBufferPushed_72a2e1;
      *(code **)(param_1 + 0x240) = uvmGetRegOffsetAccessCntrBufferPut_b2b553;
    }
  }
  *(code **)(param_1 + 0x248) = uvmGetRegOffsetAccessCntrBufferGet_b2b553;
  *(code **)(param_1 + 0x250) = uvmGetRegOffsetAccessCntrBufferHi_b2b553;
  *(code **)(param_1 + 600) = uvmGetRegOffsetAccessCntrBufferLo_b2b553;
  *(code **)(param_1 + 0x260) = uvmGetRegOffsetAccessCntrBufferConfig_b2b553;
LAB_001a1bb6:
  *(code **)(param_1 + 0x268) = uvmGetRegOffsetAccessCntrBufferInfo_b2b553;
  *(code **)(param_1 + 0x270) = uvmGetRegOffsetAccessCntrBufferSize_b2b553;
  return;
}


// ===== 001a1fc0 __nvoc_dtor_OBJUVM =====

void __nvoc_dtor_OBJUVM(long param_1)

{
  __nvoc_dtor_OBJENGSTATE(param_1 + 8);
  __nvoc_dtor_IntrService(param_1 + 0x150);
  return;
}


// ===== 001a1ff0 uvmIsAccessCntrBufferPushed_72a2e1 =====

undefined8 uvmIsAccessCntrBufferPushed_72a2e1(void)

{
  nvAssertFailed(&DAT_00c76b27,"generated/g_uvm_nvoc.h",0x325);
  return 0;
}


// ===== 001a2020 uvmIsAccessCntrBufferEnabled_72a2e1 =====

undefined8 uvmIsAccessCntrBufferEnabled_72a2e1(void)

{
  nvAssertFailed(&DAT_00c76b27,"generated/g_uvm_nvoc.h",800);
  return 0;
}


// ===== 001a2050 uvmProgramAccessCntrBufferEnabled_f2d351 =====

void uvmProgramAccessCntrBufferEnabled_f2d351(void)

{
  nvAssertFailed(&DAT_00c76b27,"generated/g_uvm_nvoc.h",0x31c);
  return;
}


// ===== 001a2070 uvmProgramWriteAccessCntrBufferAddress_f2d351 =====

void uvmProgramWriteAccessCntrBufferAddress_f2d351(void)

{
  nvAssertFailed(&DAT_00c76b27,"generated/g_uvm_nvoc.h",0x318);
  return;
}


// ===== 001a2090 uvmAccessCntrSetCounterLimit_395e98 =====

undefined8 uvmAccessCntrSetCounterLimit_395e98(void)

{
  return 0x56;
}


// ===== 001a20a0 uvmReadAccessCntrBufferGetPtr_395e98 =====

undefined8 uvmReadAccessCntrBufferGetPtr_395e98(void)

{
  return 0x56;
}


// ===== 001a20b0 uvmReadAccessCntrBufferFullPtr_395e98 =====

undefined8 uvmReadAccessCntrBufferFullPtr_395e98(void)

{
  return 0x56;
}


// ===== 001a20c0 uvmWriteAccessCntrBufferGetPtr_395e98 =====

undefined8 uvmWriteAccessCntrBufferGetPtr_395e98(void)

{
  return 0x56;
}


// ===== 001a20d0 uvmDisableAccessCntr_395e98 =====

undefined8 uvmDisableAccessCntr_395e98(void)

{
  return 0x56;
}


// ===== 001a20e0 uvmDestroyAccessCntrBuffer_ac1694 =====

undefined8 uvmDestroyAccessCntrBuffer_ac1694(void)

{
  return 0;
}


// ===== 001a20f0 uvmUnloadAccessCntrBuffer_ac1694 =====

undefined8 uvmUnloadAccessCntrBuffer_ac1694(void)

{
  return 0;
}


// ===== 001a2100 uvmSetupAccessCntrBuffer_ac1694 =====

undefined8 uvmSetupAccessCntrBuffer_ac1694(void)

{
  return 0;
}


// ===== 001a2110 uvmGetAccessCounterBufferSize_b2b553 =====

undefined8 uvmGetAccessCounterBufferSize_b2b553(void)

{
  return 0;
}


// ===== 001a2120 uvmAccessCntrService_395e98 =====

undefined8 uvmAccessCntrService_395e98(void)

{
  return 0x56;
}


// ===== 001a2130 uvmGetRegOffsetAccessCntrBufferGet_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferGet_b2b553(void)

{
  return 0;
}


// ===== 001a2140 uvmGetRegOffsetAccessCntrBufferHi_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferHi_b2b553(void)

{
  return 0;
}


// ===== 001a2150 uvmGetRegOffsetAccessCntrBufferLo_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferLo_b2b553(void)

{
  return 0;
}


// ===== 001a2160 uvmGetRegOffsetAccessCntrBufferConfig_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferConfig_b2b553(void)

{
  return 0;
}


// ===== 001a2170 uvmGetRegOffsetAccessCntrBufferInfo_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferInfo_b2b553(void)

{
  return 0;
}


// ===== 001a2180 uvmGetRegOffsetAccessCntrBufferSize_b2b553 =====

undefined8 uvmGetRegOffsetAccessCntrBufferSize_b2b553(void)

{
  return 0;
}


// ===== 001a2190 __nvoc_init_dataField_OBJUVM =====

void __nvoc_init_dataField_OBJUVM(long param_1,long param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_2 + 0x10);
  uVar2 = uVar1 >> 5;
  uVar3 = (uint)uVar1;
  if (uVar2 == 1) {
    if ((0x88000000UL >> (uVar3 & 0x1f) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x280) = 2;
      return;
    }
    if ((0x15f0ffe0UL >> (uVar3 & 0x1f) & 1) != 0) {
LAB_001a21e0:
      *(undefined4 *)(param_1 + 0x280) = 1;
      return;
    }
    if ((uVar1 & 0x1f) != 0x1d) {
      return;
    }
  }
  else if (uVar2 == 2) {
    if ((0xf9UL >> (uVar3 & 0x1f) & 1) != 0) goto LAB_001a21e0;
    if ((0x300UL >> (uVar3 & 0x1f) & 1) == 0) {
      return;
    }
  }
  else {
    if (uVar2 != 3) {
      return;
    }
    if ((0xa000UL >> (uVar3 & 0x1f) & 1) == 0) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x280) = 0;
  return;
}


// ===== 001a2230 __nvoc_objCreate_OBJUVM =====

int __nvoc_objCreate_OBJUVM(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar6 = (undefined8 *)portMemAllocNonPaged(0x298);
    if (puVar6 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_uvm_nvoc.c",799);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar6 = (undefined8 *)*param_1, puVar6 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL","generated/g_uvm_nvoc.c",
                       0x317);
    return 0x3b;
  }
  portMemSet(puVar6,0,0x298);
  *(uint *)((long)puVar6 + 0x3c) = param_3;
  if (param_2 == 0) {
    iVar3 = 0x1f;
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_uvm_nvoc.c",0x328);
    goto LAB_001a237e;
  }
  if ((param_3 & 1) == 0) {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar6 + 2);
  }
  else {
    puVar6[4] = 0;
    local_58 = 0;
  }
  lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_GpuHalspecOwner);
  if (lVar4 == 0) {
    lVar4 = objFindAncestor_IMPL(param_2,0x74bc71);
    uVar7 = 0;
    if (lVar4 != 0) {
      uVar7 = objFindAncestor_IMPL(param_2,0x74bc71);
    }
    lVar4 = __nvoc_dynamicCast(uVar7,__nvoc_class_def_GpuHalspecOwner);
    if (lVar4 != 0) goto LAB_001a22c8;
    nvCheckOkFailedNoLog(4,0x1f,"pGpuhalspecowner != NULL","generated/g_uvm_nvoc.c",0x338);
LAB_001a24ad:
    iVar3 = 0x1f;
  }
  else {
LAB_001a22c8:
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
    if (lVar5 == 0) {
      lVar5 = objFindAncestor_IMPL(param_2,0x34a6d6);
      uVar7 = 0;
      if (lVar5 != 0) {
        uVar7 = objFindAncestor_IMPL(param_2,0x34a6d6);
      }
      lVar5 = __nvoc_dynamicCast(uVar7,__nvoc_class_def_RmHalspecOwner);
      if (lVar5 == 0) {
        nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_uvm_nvoc.c",0x33b);
        goto LAB_001a24ad;
      }
    }
    puVar1 = puVar6 + 1;
    puVar6[0x2f] = puVar6;
    puVar6[0x2c] = puVar6 + 2;
    puVar2 = puVar6 + 0x2a;
    puVar6[0x2e] = puVar2;
    puVar6[0x2d] = puVar1;
    __nvoc_init__OBJENGSTATE(puVar1);
    __nvoc_init__IntrService(puVar2);
    puVar6[2] = 0xc76c50;
    puVar6[1] = 0xc76c38;
    puVar6[0x2a] = 0xc76cd8;
    *puVar6 = __nvoc_metadata__OBJUVM;
    __nvoc_init_funcTable_OBJUVM_1(puVar6,lVar4,lVar5);
    iVar3 = __nvoc_ctor_OBJENGSTATE(puVar1);
    if (iVar3 == 0) {
      iVar3 = __nvoc_ctor_IntrService(puVar2);
      if (iVar3 == 0) {
        __nvoc_init_dataField_OBJUVM(puVar6,lVar4,lVar5);
        *param_1 = (long)puVar6;
        return 0;
      }
      __nvoc_dtor_OBJENGSTATE(puVar1);
    }
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar6 + 2);
  }
LAB_001a237e:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar6);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar6,0,0x298);
  }
  return iVar3;
}


// ===== 001a25b0 __nvoc_objCreateDynamic_OBJUVM =====

void __nvoc_objCreateDynamic_OBJUVM(void)

{
  __nvoc_objCreate_OBJUVM();
  return;
}


// ===== 001a25c0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a25d0 uvmswGetSwMethods_ac1694 =====

undefined8 uvmswGetSwMethods_ac1694(void)

{
  return 0;
}


// ===== 001a25e0 __nvoc_down_thunk_UvmSwObject_chandesGetSwMethods =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_UvmSwObject_chandesGetSwMethods(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x428))(param_1 + -8);
  return;
}


// ===== 001a2600 __nvoc_up_thunk_ChannelDescendant_uvmswIsSwMethodStalling =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_ChannelDescendant_uvmswIsSwMethodStalling(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x318))(param_1 + 8);
  return;
}


// ===== 001a2620 __nvoc_up_thunk_ChannelDescendant_uvmswCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_ChannelDescendant_uvmswCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 800))(param_1 + 8,param_2);
  return;
}


// ===== 001a2640 __nvoc_up_thunk_GpuResource_uvmswControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b0))(param_1 + 0x10);
  return;
}


// ===== 001a2660 __nvoc_up_thunk_GpuResource_uvmswMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b8))(param_1 + 0x10);
  return;
}


// ===== 001a2680 __nvoc_up_thunk_GpuResource_uvmswUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c0))(param_1 + 0x10);
  return;
}


// ===== 001a26a0 __nvoc_up_thunk_GpuResource_uvmswShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c8))(param_1 + 0x10);
  return;
}


// ===== 001a26c0 __nvoc_up_thunk_GpuResource_uvmswGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d0))(param_1 + 0x10);
  return;
}


// ===== 001a26e0 __nvoc_up_thunk_GpuResource_uvmswGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d8))(param_1 + 0x10);
  return;
}


// ===== 001a2700 __nvoc_up_thunk_GpuResource_uvmswInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e0))(param_1 + 0x10);
  return;
}


// ===== 001a2720 __nvoc_up_thunk_GpuResource_uvmswGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_uvmswGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e8))(param_1 + 0x10);
  return;
}


// ===== 001a2740 __nvoc_up_thunk_RmResource_uvmswAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xf0))(param_1 + 0x18,param_2,param_3,param_4);
  return;
}


// ===== 001a2760 __nvoc_up_thunk_RmResource_uvmswGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x100))(param_1 + 0x18);
  return;
}


// ===== 001a2780 __nvoc_up_thunk_RmResource_uvmswGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x110))(param_1 + 0x18);
  return;
}


// ===== 001a27a0 __nvoc_up_thunk_RmResource_uvmswControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x118))(param_1 + 0x18);
  return;
}


// ===== 001a27c0 __nvoc_up_thunk_RmResource_uvmswControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x120))(param_1 + 0x18);
  return;
}


// ===== 001a27e0 __nvoc_up_thunk_RmResource_uvmswControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x128))(param_1 + 0x18);
  return;
}


// ===== 001a2800 __nvoc_up_thunk_RmResource_uvmswControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_uvmswControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x130))(param_1 + 0x18);
  return;
}


// ===== 001a2820 __nvoc_up_thunk_RsResource_uvmswCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x30))(param_1 + 0x20);
  return;
}


// ===== 001a2840 __nvoc_up_thunk_RsResource_uvmswIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x38))(param_1 + 0x20);
  return;
}


// ===== 001a2860 __nvoc_up_thunk_RsResource_uvmswPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x40))(param_1 + 0x20);
  return;
}


// ===== 001a2880 __nvoc_up_thunk_RsResource_uvmswControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x50))(param_1 + 0x20);
  return;
}


// ===== 001a28a0 __nvoc_up_thunk_RsResource_uvmswIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x88))(param_1 + 0x20);
  return;
}


// ===== 001a28c0 __nvoc_up_thunk_RsResource_uvmswMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x90))(param_1 + 0x20);
  return;
}


// ===== 001a28e0 __nvoc_up_thunk_RsResource_uvmswUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x98))(param_1 + 0x20);
  return;
}


// ===== 001a2900 __nvoc_up_thunk_RsResource_uvmswGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0xa0))(param_1 + 0x20);
  return;
}


// ===== 001a2920 __nvoc_up_thunk_RsResource_uvmswAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_uvmswAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x20) + 0xb8))(param_1,param_2 + 0x20);
  return;
}


// ===== 001a2940 __nvoc_up_thunk_Notifier_uvmswGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_uvmswGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x58))(param_1 + 0x110);
  return;
}


// ===== 001a2960 __nvoc_up_thunk_Notifier_uvmswGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_uvmswGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x60))(param_1 + 0x110);
  return;
}


// ===== 001a2980 __nvoc_up_thunk_Notifier_uvmswSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_uvmswSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x68))(param_1 + 0x110);
  return;
}


// ===== 001a29a0 __nvoc_up_thunk_Notifier_uvmswUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_uvmswUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x70))(param_1 + 0x110);
  return;
}


// ===== 001a29c0 __nvoc_up_thunk_Notifier_uvmswGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_uvmswGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x78))(param_1 + 0x110);
  return;
}


// ===== 001a29e0 __nvoc_dtor_UvmSwObject =====

void __nvoc_dtor_UvmSwObject(long param_1)

{
  uvmswDestruct_IMPL();
  __nvoc_dtor_ChannelDescendant(param_1 + 8);
  return;
}


// ===== 001a2a10 __nvoc_objCreate_UvmSwObject =====

int __nvoc_objCreate_UvmSwObject
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x1f8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_uvm_sw_nvoc.c",0x283);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_uvm_sw_nvoc.c",0x27b);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x1f8);
  *(uint *)((long)puVar4 + 0x54) = param_3;
  if (param_2 == 0) {
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_uvm_sw_nvoc.c",0x28c);
    iVar2 = 0x1f;
    goto LAB_001a2b9c;
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
    if (lVar3 != 0) goto LAB_001a2aa4;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_uvm_sw_nvoc.c",0x29c);
    iVar2 = 0x1f;
  }
  else {
LAB_001a2aa4:
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
    puVar4[5] = 0xc76f58;
    puVar4[4] = 0xc76f40;
    puVar4[0x11] = 0xc77000;
    puVar4[3] = 0xc76f28;
    puVar4[2] = 0xc76f10;
    puVar4[0x23] = 0xc771a0;
    puVar4[0x22] = 0xc77188;
    puVar4[1] = 0xc76ef8;
    *puVar4 = __nvoc_metadata__UvmSwObject;
    iVar2 = __nvoc_ctor_ChannelDescendant(puVar1,lVar3,param_4,param_5,0);
    if (iVar2 == 0) {
      iVar2 = uvmswConstruct_IMPL(puVar4,param_4,param_5);
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
LAB_001a2b9c:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x1f8);
  }
  return iVar2;
}


// ===== 001a2d60 __nvoc_objCreateDynamic_UvmSwObject =====

void __nvoc_objCreateDynamic_UvmSwObject
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
      goto LAB_001a2d8e;
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
LAB_001a2d8e:
  __nvoc_objCreate_UvmSwObject(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a2dc0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a2dd0 __nvoc_down_thunk_VaSpaceApi_resCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_VaSpaceApi_resCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x290))(param_1 + -0x18);
  return;
}


// ===== 001a2df0 __nvoc_up_thunk_GpuResource_vaspaceapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001a2e10 __nvoc_up_thunk_GpuResource_vaspaceapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001a2e30 __nvoc_up_thunk_GpuResource_vaspaceapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 001a2e50 __nvoc_up_thunk_GpuResource_vaspaceapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001a2e70 __nvoc_up_thunk_GpuResource_vaspaceapiGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 001a2e90 __nvoc_up_thunk_GpuResource_vaspaceapiGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 001a2eb0 __nvoc_up_thunk_GpuResource_vaspaceapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 001a2ed0 __nvoc_up_thunk_GpuResource_vaspaceapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vaspaceapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001a2ef0 __nvoc_up_thunk_RmResource_vaspaceapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001a2f10 __nvoc_up_thunk_RmResource_vaspaceapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 001a2f30 __nvoc_up_thunk_RmResource_vaspaceapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 001a2f50 __nvoc_up_thunk_RmResource_vaspaceapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 001a2f70 __nvoc_up_thunk_RmResource_vaspaceapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 001a2f90 __nvoc_up_thunk_RmResource_vaspaceapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 001a2fb0 __nvoc_up_thunk_RmResource_vaspaceapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 001a2fd0 __nvoc_up_thunk_RmResource_vaspaceapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vaspaceapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 001a2ff0 __nvoc_up_thunk_RsResource_vaspaceapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 001a3010 __nvoc_up_thunk_RsResource_vaspaceapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001a3030 __nvoc_up_thunk_RsResource_vaspaceapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001a3050 __nvoc_up_thunk_RsResource_vaspaceapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001a3070 __nvoc_up_thunk_RsResource_vaspaceapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 001a3090 __nvoc_up_thunk_RsResource_vaspaceapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 001a30b0 __nvoc_up_thunk_RsResource_vaspaceapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 001a30d0 __nvoc_up_thunk_RsResource_vaspaceapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vaspaceapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 001a30f0 __nvoc_dtor_VaSpaceApi =====

void __nvoc_dtor_VaSpaceApi(long param_1)

{
  vaspaceapiDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 001a3120 __nvoc_objCreate_VaSpaceApi =====

int __nvoc_objCreate_VaSpaceApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x148);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_vaspace_api_nvoc.c",0x249);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_vaspace_api_nvoc.c",0x241);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x148);
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
  puVar4[4] = 0xc77580;
  puVar4[3] = 0xc77568;
  puVar4[0x10] = 0xc77628;
  puVar4[2] = 0xc77550;
  puVar4[1] = 0xc77538;
  *puVar4 = __nvoc_metadata__VaSpaceApi;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = vaspaceapiConstruct_IMPL(puVar4,param_4,param_5);
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
    portMemSet(puVar4,0,0x148);
  }
  return iVar3;
}


// ===== 001a33a0 __nvoc_objCreateDynamic_VaSpaceApi =====

void __nvoc_objCreateDynamic_VaSpaceApi
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
      goto LAB_001a33ce;
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
LAB_001a33ce:
  __nvoc_objCreate_VaSpaceApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a3400 vaspaceGetFlags_edd98b =====

undefined8 vaspaceGetFlags_edd98b(void)

{
  return 0;
}


// ===== 001a3410 vaspaceReserveMempool_ac1694 =====

undefined8 vaspaceReserveMempool_ac1694(void)

{
  return 0;
}


// ===== 001a3420 vaspaceFreeV2_14ee5e =====

undefined8 vaspaceFreeV2_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x282);
  return 0x56;
}


// ===== 001a3450 vaspaceSetPteInfo_14ee5e =====

undefined8 vaspaceSetPteInfo_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x27d);
  return 0x56;
}


// ===== 001a3480 vaspaceGetPteInfo_14ee5e =====

undefined8 vaspaceGetPteInfo_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x278);
  return 0x56;
}


// ===== 001a34b0 vaspaceGetPageTableInfo_14ee5e =====

undefined8 vaspaceGetPageTableInfo_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x273);
  return 0x56;
}


// ===== 001a34e0 vaspaceUnpinRootPageDir_af5be7 =====

void vaspaceUnpinRootPageDir_af5be7(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x26d);
  return;
}


// ===== 001a3500 vaspacePinRootPageDir_14ee5e =====

undefined8 vaspacePinRootPageDir_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x268);
  return 0x56;
}


// ===== 001a3530 vaspaceGetPageDirBase_9451a7 =====

undefined8 vaspaceGetPageDirBase_9451a7(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x263);
  return 0;
}


// ===== 001a3560 vaspaceGetPasid_14ee5e =====

undefined8 vaspaceGetPasid_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x25e);
  return 0x56;
}


// ===== 001a3590 vaspaceIsAtsEnabled_2fa1ff =====

undefined8 vaspaceIsAtsEnabled_2fa1ff(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x259);
  return 0;
}


// ===== 001a35c0 vaspaceIsExternallyOwned_2fa1ff =====

undefined8 vaspaceIsExternallyOwned_2fa1ff(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x254);
  return 0;
}


// ===== 001a35f0 vaspaceIsFaultCapable_2fa1ff =====

undefined8 vaspaceIsFaultCapable_2fa1ff(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x24f);
  return 0;
}


// ===== 001a3620 vaspaceGetBigPageSize_c26fae =====

undefined8 vaspaceGetBigPageSize_c26fae(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x24a);
  return 0;
}


// ===== 001a3650 vaspaceGetMapPageSize_c26fae =====

undefined8 vaspaceGetMapPageSize_c26fae(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x245);
  return 0;
}


// ===== 001a3680 vaspaceGetHeap_9451a7 =====

undefined8 vaspaceGetHeap_9451a7(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x240);
  return 0;
}


// ===== 001a36b0 vaspaceUnmap_af5be7 =====

void vaspaceUnmap_af5be7(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x238);
  return;
}


// ===== 001a36d0 vaspaceMap_14ee5e =====

undefined8 vaspaceMap_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x233);
  return 0x56;
}


// ===== 001a3700 vaspaceIncAllocRefCnt_14ee5e =====

undefined8 vaspaceIncAllocRefCnt_14ee5e(void)

{
  nvAssertFailed("NV_FALSE","generated/g_vaspace_nvoc.h",0x226);
  return 0x56;
}


// ===== 001a3730 __nvoc_dtor_OBJVASPACE =====

void __nvoc_dtor_OBJVASPACE(long param_1)

{
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 001a3740 __nvoc_ctor_OBJVASPACE =====

void __nvoc_ctor_OBJVASPACE(long param_1)

{
  __nvoc_ctor_Object(param_1 + 8);
  return;
}


// ===== 001a3750 __nvoc_init__OBJVASPACE =====

void __nvoc_init__OBJVASPACE(undefined8 *param_1)

{
  param_1[7] = param_1 + 1;
  param_1[8] = param_1;
  __nvoc_init__Object();
  param_1[1] = 0xc77b38;
  *param_1 = __nvoc_metadata__OBJVASPACE;
  return;
}


// ===== 001a3790 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a37a0 __nvoc_up_thunk_GpuResource_vblcbControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001a37c0 __nvoc_up_thunk_GpuResource_vblcbMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001a37e0 __nvoc_up_thunk_GpuResource_vblcbUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 001a3800 __nvoc_up_thunk_GpuResource_vblcbShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001a3820 __nvoc_up_thunk_GpuResource_vblcbGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 001a3840 __nvoc_up_thunk_GpuResource_vblcbGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 001a3860 __nvoc_up_thunk_GpuResource_vblcbInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 001a3880 __nvoc_up_thunk_GpuResource_vblcbGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vblcbGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001a38a0 __nvoc_up_thunk_RmResource_vblcbAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001a38c0 __nvoc_up_thunk_RmResource_vblcbGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 001a38e0 __nvoc_up_thunk_RmResource_vblcbCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 001a3900 __nvoc_up_thunk_RmResource_vblcbGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 001a3920 __nvoc_up_thunk_RmResource_vblcbControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 001a3940 __nvoc_up_thunk_RmResource_vblcbControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 001a3960 __nvoc_up_thunk_RmResource_vblcbControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 001a3980 __nvoc_up_thunk_RmResource_vblcbControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vblcbControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 001a39a0 __nvoc_up_thunk_RsResource_vblcbCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 001a39c0 __nvoc_up_thunk_RsResource_vblcbIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 001a39e0 __nvoc_up_thunk_RsResource_vblcbPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001a3a00 __nvoc_up_thunk_RsResource_vblcbControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001a3a20 __nvoc_up_thunk_RsResource_vblcbIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001a3a40 __nvoc_up_thunk_RsResource_vblcbMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 001a3a60 __nvoc_up_thunk_RsResource_vblcbUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 001a3a80 __nvoc_up_thunk_RsResource_vblcbGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 001a3aa0 __nvoc_up_thunk_RsResource_vblcbAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vblcbAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 001a3ac0 __nvoc_dtor_VblankCallback =====

void __nvoc_dtor_VblankCallback(long param_1)

{
  vblcbDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 001a3af0 __nvoc_objCreate_VblankCallback =====

int __nvoc_objCreate_VblankCallback
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x1a8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_vblank_callback_nvoc.c",0x1fb);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_vblank_callback_nvoc.c",499);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x1a8);
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
  puVar4[4] = 0xc77da0;
  puVar4[3] = 0xc77d88;
  puVar4[0x10] = 0xc77e48;
  puVar4[2] = 0xc77d70;
  puVar4[1] = 0xc77d58;
  *puVar4 = __nvoc_metadata__VblankCallback;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = vblcbConstruct_IMPL(puVar4,param_4,param_5);
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
    portMemSet(puVar4,0,0x1a8);
  }
  return iVar3;
}


// ===== 001a3d70 __nvoc_objCreateDynamic_VblankCallback =====

void __nvoc_objCreateDynamic_VblankCallback
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
      goto LAB_001a3d9e;
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
LAB_001a3d9e:
  __nvoc_objCreate_VblankCallback(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a3dd0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a3de0 __nvoc_up_thunk_GpuResource_vgpuapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001a3e00 __nvoc_up_thunk_GpuResource_vgpuapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001a3e20 __nvoc_up_thunk_GpuResource_vgpuapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 001a3e40 __nvoc_up_thunk_GpuResource_vgpuapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001a3e60 __nvoc_up_thunk_GpuResource_vgpuapiGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 001a3e80 __nvoc_up_thunk_GpuResource_vgpuapiGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 001a3ea0 __nvoc_up_thunk_GpuResource_vgpuapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 001a3ec0 __nvoc_up_thunk_GpuResource_vgpuapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001a3ee0 __nvoc_up_thunk_RmResource_vgpuapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001a3f00 __nvoc_up_thunk_RmResource_vgpuapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 001a3f20 __nvoc_up_thunk_RmResource_vgpuapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 001a3f40 __nvoc_up_thunk_RmResource_vgpuapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 001a3f60 __nvoc_up_thunk_RmResource_vgpuapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 001a3f80 __nvoc_up_thunk_RmResource_vgpuapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 001a3fa0 __nvoc_up_thunk_RmResource_vgpuapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 001a3fc0 __nvoc_up_thunk_RmResource_vgpuapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 001a3fe0 __nvoc_up_thunk_RsResource_vgpuapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 001a4000 __nvoc_up_thunk_RsResource_vgpuapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 001a4020 __nvoc_up_thunk_RsResource_vgpuapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001a4040 __nvoc_up_thunk_RsResource_vgpuapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001a4060 __nvoc_up_thunk_RsResource_vgpuapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001a4080 __nvoc_up_thunk_RsResource_vgpuapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 001a40a0 __nvoc_up_thunk_RsResource_vgpuapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 001a40c0 __nvoc_up_thunk_RsResource_vgpuapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 001a40e0 __nvoc_up_thunk_RsResource_vgpuapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_vgpuapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 001a4100 __nvoc_dtor_VgpuApi =====

void __nvoc_dtor_VgpuApi(long param_1)

{
  vgpuapiDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 001a4130 __nvoc_objCreate_VgpuApi =====

int __nvoc_objCreate_VgpuApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x178);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_vgpuapi_nvoc.c",0x219);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_vgpuapi_nvoc.c",0x211);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x178);
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
  puVar4[4] = 0xc78240;
  puVar4[3] = 0xc78228;
  puVar4[0x10] = 0xc782e8;
  puVar4[2] = 0xc78210;
  puVar4[1] = 0xc781f8;
  *puVar4 = __nvoc_metadata__VgpuApi;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = vgpuapiConstruct_IMPL(puVar4,param_4,param_5);
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
    portMemSet(puVar4,0,0x178);
  }
  return iVar3;
}


// ===== 001a43b0 __nvoc_objCreateDynamic_VgpuApi =====

void __nvoc_objCreateDynamic_VgpuApi
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
      goto LAB_001a43de;
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
LAB_001a43de:
  __nvoc_objCreate_VgpuApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001a4410 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001a4420 __nvoc_up_thunk_GpuResource_vgpuconfigapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001a4440 __nvoc_up_thunk_GpuResource_vgpuconfigapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001a4460 __nvoc_up_thunk_GpuResource_vgpuconfigapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 001a4480 __nvoc_up_thunk_GpuResource_vgpuconfigapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001a44a0 __nvoc_up_thunk_GpuResource_vgpuconfigapiGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 001a44c0 __nvoc_up_thunk_GpuResource_vgpuconfigapiGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 001a44e0 __nvoc_up_thunk_GpuResource_vgpuconfigapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 001a4500 __nvoc_up_thunk_GpuResource_vgpuconfigapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_vgpuconfigapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001a4520 __nvoc_up_thunk_RmResource_vgpuconfigapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuconfigapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001a4540 __nvoc_up_thunk_RmResource_vgpuconfigapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuconfigapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 001a4560 __nvoc_up_thunk_RmResource_vgpuconfigapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuconfigapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 001a4580 __nvoc_up_thunk_RmResource_vgpuconfigapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_vgpuconfigapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


