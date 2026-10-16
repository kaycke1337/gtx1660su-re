// ===== 00458a20 memCreateMemDesc_IMPL =====

int memCreateMemDesc_IMPL
              (undefined8 param_1,long *param_2,int param_3,undefined8 param_4,undefined8 param_5,
              uint param_6,uint param_7)

{
  long lVar1;
  uint uVar2;
  bool bVar3;
  int local_4c;
  long local_40 [2];
  
  local_40[0] = 0;
  *param_2 = 0;
  if ((param_3 == 1) && ((param_6 & 0x18000000) != 0x10000000)) {
    nvAssertFailedNoLog("FLD_TEST_DRF(OS32, _ATTR, _PHYSICALITY, _CONTIGUOUS, attr)",
                        "src/kernel/mem_mgr/mem.c",0xc9);
    local_4c = 0x1f;
  }
  else {
    param_6 = param_6 >> 0x1d;
    if (param_6 != 2) {
      if (param_6 < 3) {
        param_6 = (uint)(param_6 == 0);
      }
      else {
        uVar2 = param_6 - 3;
        param_6 = 0;
        if (2 < uVar2) {
          nvAssertFailedNoLog(&DAT_00d81403,"src/kernel/mem_mgr/mem.c",0xdb);
          param_6 = 1;
        }
      }
    }
    local_4c = memdescCreate(local_40,param_1,param_5,0,1,param_3,param_6,0);
    if (local_4c == 0) {
      bVar3 = (param_7 & 0xc) != 4;
      if (*(uint *)(local_40[0] + 0x8c) < 2) {
        memdescDescribe(local_40[0],param_3,param_4,param_5);
        memdescSetGpuCacheAttrib(local_40[0],bVar3);
      }
      else {
        for (lVar1 = *(long *)(local_40[0] + 0xd8); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0xd8)) {
          memdescDescribe(lVar1,param_3,param_4,param_5);
          memdescSetGpuCacheAttrib(lVar1,bVar3);
        }
      }
      *param_2 = local_40[0];
    }
  }
  return local_4c;
}


// ===== 00458bc0 memCreateKernelMapping_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memCreateKernelMapping_IMPL(long *param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0x1f8))(param_1,0);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (param_1[0x27] == 0) {
      iVar1 = memdescGetAddressSpace(param_1[0x23]);
      iVar2 = 0x56;
      if (iVar1 == 1) {
        iVar2 = memdescMap(param_1[0x23],0,param_1[0x20],1,param_2,param_1 + 0x27,param_1 + 0x28);
        if (iVar2 == 0) {
          memdescSetKernelMapping(param_1[0x23],param_1[0x27],0x458c1c);
          memdescSetKernelMappingPriv(param_1[0x23],param_1[0x28]);
          if (param_3 != '\0') {
            portMemSet(param_1[0x27],0,param_1[0x20]);
          }
        }
        else {
          param_1[0x27] = 0;
          param_1[0x28] = 0;
        }
      }
    }
    return iVar2;
  }
  nvCheckOkFailedNoLog(1,iVar2,"memIsReady(pMemory, NV_FALSE)","src/kernel/mem_mgr/mem.c",0x108);
  return iVar2;
}


// ===== 00458d10 dmaNvos32ToPageSizeAttr =====

uint dmaNvos32ToPageSizeAttr(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1 >> 0x17 & 3;
  if (uVar1 != 2) {
    if (uVar1 != 3) {
      return (uint)(uVar1 != 0);
    }
    uVar1 = *(uint *)(CSWTCH_85 + (ulong)(param_2 >> 0x14 & 3) * 4);
  }
  return uVar1;
}


// ===== 00458d40 memRegisterWithGsp_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int memRegisterWithGsp_IMPL(long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar9;
  uint local_dc;
  long local_d8 [2];
  undefined4 local_c8 [2];
  undefined8 uStack_c0;
  undefined4 local_b8 [2];
  undefined8 auStack_b0 [3];
  undefined4 local_98;
  undefined4 local_8c;
  undefined8 local_60;
  undefined8 local_50;
  long local_48;
  uint local_40;
  ulong uVar8;
  
  local_d8[0] = 0;
  if ((*(char *)(param_1 + 0x909) != '\0') || (iVar2 = 0, *(char *)(param_1 + 0x90a) != '\0')) {
    iVar2 = clientGetResourceRef_IMPL(param_2,param_4,local_d8);
    if (iVar2 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar2,"clientGetResourceRef(pClient, hMemory, &pMemoryRef)",
                 "src/kernel/mem_mgr/mem.c",0x215);
      return iVar2;
    }
    lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_d8[0] + 8),__nvoc_class_def_Memory);
    if (lVar5 == 0) {
      nvCheckFailedNoLog(4,"pMemory != NULL","src/kernel/mem_mgr/mem.c",0x218);
      return 0x31;
    }
    if (*(char *)(lVar5 + 0x1b1) != '\0') {
      return 0;
    }
    puVar1 = *(undefined8 **)(lVar5 + 0x118);
    if (1 < *(uint *)((long)puVar1 + 0x8c)) {
      nvCheckFailedNoLog(4,"!memdescHasSubDeviceMemDescs(pMemDesc)","src/kernel/mem_mgr/mem.c",0x223
                        );
      return 0x40;
    }
    iVar2 = memdescGetAddressSpace(puVar1);
    if (iVar2 == 2) {
      uVar9 = 0x82;
    }
    else {
      iVar2 = memdescGetAddressSpace(puVar1);
      if (iVar2 != 1) {
        return 0x40;
      }
      uVar9 = 0x81;
    }
    local_dc = 0;
    iVar2 = RmDeprecatedConvertOs32ToOs02Flags
                      (*(undefined4 *)(lVar5 + 0x188),*(undefined4 *)(lVar5 + 0x18c),
                       *(undefined4 *)(lVar5 + 0x198),&local_dc);
    if (iVar2 == 0) {
      lVar6 = gpuGetRpc(param_1);
      if (lVar6 == 0) {
        iVar2 = 0x1a;
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem.c",0x236);
      }
      else {
        if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) {
          if (*(char *)(param_1 + 0x90a) == '\0') {
            iVar3 = (**(code **)(lVar6 + 0x50))
                              (param_1,lVar6,*(undefined4 *)(param_2 + 0x48),param_3,param_4,uVar9,
                               local_dc,puVar1);
          }
          else {
            uVar7 = 0;
            do {
              uVar4 = (int)uVar7 + 0x20;
              uVar8 = (ulong)uVar4;
              *(undefined8 *)((long)local_c8 + (uVar7 - 8)) = 0;
              *(undefined8 *)((long)local_c8 + uVar7) = 0;
              *(undefined8 *)((long)local_b8 + (uVar7 - 8)) = 0;
              *(undefined8 *)((long)local_b8 + uVar7) = 0;
              uVar7 = uVar8;
            } while (uVar4 < 0x80);
            *(undefined8 *)((long)local_c8 + (uVar8 - 8)) = 0;
            *(undefined8 *)((long)local_c8 + uVar8) = 0;
            *(undefined8 *)((long)local_b8 + (uVar8 - 8)) = 0;
            local_b8[0] = *(undefined4 *)(puVar1 + 0xc);
            local_98 = memdescGetPteKindForGpu(puVar1,*puVar1);
            local_60 = puVar1[6];
            local_8c = (undefined4)puVar1[3];
            local_50 = memdescGetPteArrayForGpu(puVar1,*puVar1,1);
            local_d8[1] = 0;
            local_48 = puVar1[6] + -1;
            local_c8[0] = 0;
            local_40 = local_dc & 0xf000 | 0x40000010;
            iVar3 = (**(code **)(param_1 + 0x3b60))
                              (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0x48),param_3,param_4,0x81
                               ,local_d8 + 1,0x98);
          }
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        *(undefined1 *)(lVar5 + 0x1b1) = 1;
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "RmDeprecatedConvertOs32ToOs02Flags(pMemory->Attr, pMemory->Attr2, pMemory->Flags, &os02Flags)"
                 ,"src/kernel/mem_mgr/mem.c",0x231);
    }
  }
  return iVar2;
}


// ===== 0045915b memConstructCommon_IMPL.cold =====

void memConstructCommon_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00459170 memConstructCommon_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

ulong memConstructCommon_IMPL
                (long param_1,undefined4 param_2,uint param_3,long *param_4,uint param_5,
                undefined8 param_6,undefined4 param_7,uint param_8,undefined4 param_9,
                undefined4 param_10,undefined4 param_11,undefined8 *param_12)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 *puVar9;
  long lVar10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  if (param_4 == (long *)0x0) {
    return 0x1f;
  }
  lVar10 = *(long *)(*(long *)(param_1 + 0xb8) + 0x48);
  uVar1 = *(undefined4 *)(lVar10 + 0x10);
  uVar2 = *(undefined4 *)(*(long *)(lVar10 + 0x18) + 0x10);
  *(undefined4 *)(param_1 + 0xfc) = param_2;
  *(long **)(param_1 + 0x118) = param_4;
  *(long *)(param_1 + 0x100) = param_4[6];
  *(ulong *)(param_1 + 0x108) = (ulong)param_5 | 0x100000000;
  *(undefined4 *)(param_1 + 0x188) = param_7;
  *(undefined8 *)(param_1 + 0x110) = param_6;
  *(undefined4 *)(param_1 + 400) = param_9;
  *(uint *)(param_1 + 0x18c) = param_8;
  *(undefined4 *)(param_1 + 0x194) = param_10;
  *(uint *)(param_1 + 0x198) = param_3;
  *(undefined4 *)(param_1 + 0x19c) = param_11;
  *(undefined1 *)(param_1 + 0x120) = 1;
  *(undefined1 *)(param_1 + 0x1b0) = 0;
  if (*(long *)(param_1 + 0xe0) == 0) {
LAB_0045938b:
    *(undefined1 *)(param_1 + 0xd8) = 1;
    uVar8 = 0;
  }
  else {
    if (*param_4 == 0) {
      return 0x40;
    }
    if ((param_12 == (undefined8 *)0x0) ||
       ((*(int *)(param_12 + 2) == 0 &&
        (*(int *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x11c) != 0xb1)))) {
joined_r0x00459273:
      if ((param_3 & 0x40000) != 0) {
        uVar7 = memdescGetMemDescFromGpu(param_4,*param_4);
        memdescSetFlag(uVar7,0x800,1);
      }
      if ((param_8 & 0x400000) != 0) {
        uVar7 = memdescGetMemDescFromGpu(param_4,*param_4);
        memdescSetFlag(uVar7,0x100000000,1);
      }
      if ((param_8 & 0x800000) == 0) {
        if ((param_8 >> 4 & 3) != 1) goto LAB_004592a4;
LAB_004593a8:
        lVar10 = *param_4;
        uVar7 = memdescGetMemDescFromGpu(param_4,lVar10);
        memdescSetGpuP2PCacheAttrib(uVar7,0);
        lVar4 = *param_4;
      }
      else {
        uVar7 = memdescGetMemDescFromGpu(param_4,*param_4);
        memdescSetFlag(uVar7,0x200000000,1);
        if ((param_8 >> 4 & 3) == 1) goto LAB_004593a8;
LAB_004592a4:
        if ((param_8 >> 4 & 1) != 0) {
          nvAssertFailedNoLog(&DAT_00d81403,"src/kernel/mem_mgr/mem.c",0x1b9);
        }
        lVar10 = *param_4;
        uVar7 = memdescGetMemDescFromGpu(param_4,lVar10);
        memdescSetGpuP2PCacheAttrib(uVar7,1);
        lVar4 = *param_4;
      }
      if (lVar4 != 0) {
        uVar6 = dmaNvos32ToPageSizeAttr(param_7,param_8);
        uVar7 = memdescGetMemDescFromGpu(param_4,lVar4);
        uVar8 = (**(code **)(*(long *)(lVar4 + 0x1b78) + 0x388))
                          (lVar4,*(long *)(lVar4 + 0x1b78),uVar7,1,uVar6);
        lVar10 = lVar4;
        if ((int)uVar8 != 0) goto LAB_00459510;
      }
      *(ulong *)(param_1 + 0x158) =
           (ulong)*(uint *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10);
      uVar3 = *(uint *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10);
      *(long *)(param_1 + 0x150) = param_1;
      *(ulong *)(param_1 + 0x160) = (ulong)uVar3;
      uVar8 = btreeInsert(param_1 + 0x150,*(long *)(param_1 + 0xe0) + 0x188);
      if (((int)uVar8 == 0) &&
         ((-1 < (int)param_8 ||
          (uVar8 = memRegisterWithGsp_IMPL
                             (lVar10,**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),uVar2,uVar1
                             ), (int)uVar8 == 0)))) {
        *(long *)(param_1 + 0x130) = param_1;
        *(long *)(param_1 + 0x128) = param_1;
        goto LAB_0045938b;
      }
    }
    else {
      puVar9 = (undefined8 *)portMemAllocNonPaged(0x1c);
      *(undefined8 **)(param_1 + 0x1a8) = puVar9;
      if (puVar9 != (undefined8 *)0x0) {
        *puVar9 = *param_12;
        puVar9[1] = param_12[1];
        puVar9[2] = param_12[2];
        *(undefined4 *)(puVar9 + 3) = *(undefined4 *)(param_12 + 3);
        *(undefined4 *)(*(long *)(param_1 + 0x1a8) + 0x14) = 1;
        goto joined_r0x00459273;
      }
      nvDbg_Printf("src/kernel/mem_mgr/mem.c",0x188,"memConstructCommon_IMPL",4,
                   "NVRM: Unable to allocate HWRESOURCE_INFO tracking structure\n");
      uVar8 = 0x51;
    }
LAB_00459510:
    if (*(long *)(param_1 + 0x1a8) != 0) {
      portMemFree();
      return uVar8 & 0xffffffff;
    }
  }
  return uVar8;
}


// ===== 0045958e memDestructCommon_IMPL.cold =====

void memDestructCommon_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004595a0 memDestructCommon_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void memDestructCommon_IMPL(long param_1)

{
  int *piVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  if (*(char *)(param_1 + 0xd8) == '\0') {
    return;
  }
  lVar3 = *(long *)(param_1 + 0xf0);
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x909) != '\0' || (*(char *)(lVar3 + 0x90a) != '\0')) &&
      (*(char *)(param_1 + 0x1b1) != '\0')))) {
    plVar4 = *(long **)(*(long *)(param_1 + 0xb8) + 0x48);
    lVar3 = *plVar4;
    uVar2 = (undefined4)plVar4[2];
    uVar9 = *(undefined4 *)(plVar4[3] + 0x10);
    lVar11 = gpuGetRpc();
    if (lVar11 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem.c",0x260);
      uVar10 = 0x1a;
    }
    else {
      lVar12 = *(long *)(param_1 + 0xf0);
      if ((*(char *)(lVar12 + 0x909) == '\0') && (*(char *)(lVar12 + 0x90a) == '\0')) {
        uVar10 = (**(code **)(lVar11 + 0xf0))
                           (lVar12,lVar11,*(undefined4 *)(lVar3 + 0x48),uVar9,uVar2,
                            *(code **)(lVar11 + 0xf0));
      }
      else {
        uVar10 = (**(code **)(lVar12 + 0x3b70))(lVar12 + 0x3b58,*(undefined4 *)(lVar3 + 0x48),uVar2)
        ;
      }
      if ((int)uVar10 == 0) {
        *(undefined1 *)(param_1 + 0x1b1) = 0;
        goto LAB_00459601;
      }
    }
    nvDbg_Printf("src/kernel/mem_mgr/mem.c",0x26d,"_memUnregisterFromGsp",4,
                 "NVRM: Failed to unregister hMemory 0x%08x from GSP, status 0x%08x\n",uVar2,uVar10)
    ;
  }
LAB_00459601:
  lVar3 = *(long *)(param_1 + 0xe0);
  if (lVar3 == 0) {
    *(undefined1 *)(param_1 + 0xd8) = 0;
    goto LAB_00459807;
  }
  lVar11 = *(long *)(param_1 + 0xf0);
  plVar4 = *(long **)(*(long *)(param_1 + 0xb8) + 0x48);
  lVar12 = *(long *)(*(long *)(lVar3 + 0x110) + 0x48);
  lVar13 = *plVar4;
  lVar6 = plVar4[2];
  uVar2 = *(undefined4 *)(lVar12 + 0x10);
  clientRefIter(&local_d8,lVar13,lVar12,0x4b01b3,0,1);
  local_80 = local_d8;
  local_78 = local_d0;
  local_70 = local_c8;
  local_68 = local_c0;
  local_60 = local_b8;
  local_58 = local_b0;
  local_50 = local_a8;
  local_48 = local_a0;
  local_40 = local_98;
  while( true ) {
    cVar7 = clientRefIterNext(lVar13,&local_80);
    if (cVar7 == '\0') break;
    lVar12 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Subdevice);
    if ((int)lVar6 == *(int *)(lVar12 + 0x670)) {
      *(undefined4 *)(lVar12 + 0x670) = 0;
      *(undefined8 *)(lVar12 + 0x678) = 0;
    }
  }
  dispcmnGetByDevice_IMPL(lVar13,uVar2,local_88);
  if (*(long *)(param_1 + 0x1a8) == 0) {
    lVar12 = 0;
    lVar11 = 0;
LAB_0045973c:
    iVar8 = btreeUnlink(param_1 + 0x150,lVar3 + 0x188);
    if (iVar8 == 0) {
      piVar1 = (int *)(*(long *)(param_1 + 0x118) + 0x94);
      *piVar1 = *piVar1 + -1;
      if (*(char *)(param_1 + 0x120) != '\0') {
        *(undefined1 *)(*(long *)(param_1 + 0x128) + 0x120) = 1;
      }
      lVar3 = *(long *)(param_1 + 0x128);
      *(long *)(*(long *)(param_1 + 0x130) + 0x128) = lVar3;
      *(undefined8 *)(lVar3 + 0x130) = *(undefined8 *)(param_1 + 0x130);
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined8 *)(param_1 + 0x128) = 0;
      *(undefined1 *)(param_1 + 0xd8) = 0;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,"btreeUnlink(&pMemory->Node, &pDevice->DevMemoryTable)",
                 "src/kernel/mem_mgr/mem.c",0x2db);
    }
  }
  else {
    piVar1 = (int *)(*(long *)(param_1 + 0x1a8) + 0x14);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      lVar12 = 0;
      lVar11 = 0;
      goto LAB_0045973c;
    }
    if (*(char *)(lVar11 + 0x45a) != '\0') {
      lVar13 = *(long *)(param_1 + 0x1a8);
      lVar12 = 0;
      lVar11 = 0;
LAB_004598f1:
      portMemFree(lVar13);
      *(undefined8 *)(param_1 + 0x1a8) = 0;
      goto LAB_0045973c;
    }
    lVar6 = *(long *)(lVar11 + 0x1b78);
    lVar11 = portMemAllocNonPaged(0xc0);
    if (lVar11 == 0) {
      lVar12 = 0;
      nvAssertFailedNoLog(&DAT_00d81403,"src/kernel/mem_mgr/mem.c",0x2a2);
    }
    else {
      lVar12 = portMemAllocNonPaged(0x14);
      if (lVar12 != 0) {
        portMemSet(lVar11,0,0xc0);
        portMemSet(lVar12,0,0x14);
        *(long *)(lVar11 + 0x90) = lVar12;
        *(undefined4 *)(lVar12 + 0x10) = *(undefined4 *)(param_1 + 0x194);
        **(undefined4 **)(lVar11 + 0x90) = *(undefined4 *)(param_1 + 0x188);
        *(undefined4 *)(*(long *)(lVar11 + 0x90) + 4) = *(undefined4 *)(param_1 + 0x18c);
        *(undefined4 *)(lVar11 + 4) = *(undefined4 *)(*(long *)(param_1 + 0x118) + 0x98);
        *(undefined8 *)(lVar11 + 0x18) = *(undefined8 *)(param_1 + 0x100);
        uVar9 = memdescGetPteKindForGpu
                          (*(undefined8 **)(param_1 + 0x118),**(undefined8 **)(param_1 + 0x118));
        *(undefined4 *)(lVar11 + 0x4c) = uVar9;
        *(ulong *)(lVar11 + 0x98) = CONCAT44(uVar2,*(undefined4 *)(lVar13 + 0x48));
        lVar13 = *(long *)(param_1 + 0x1a8);
        if (*(char *)(lVar13 + 0x18) == '\0') {
          iVar8 = (**(code **)(lVar6 + 0x170))(**(undefined8 **)(param_1 + 0x118),lVar6,lVar11);
          if (iVar8 != 0) {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/mem.c",0x2d4);
          }
          lVar13 = *(long *)(param_1 + 0x1a8);
        }
        goto LAB_004598f1;
      }
      nvAssertFailedNoLog(&DAT_00d81403,"src/kernel/mem_mgr/mem.c",0x2a9);
    }
  }
  portMemFree(lVar12);
  portMemFree(lVar11);
LAB_00459807:
  if (*(long *)(param_1 + 0x138) != 0) {
    memdescUnmap(*(undefined8 *)(param_1 + 0x118),1,*(long *)(param_1 + 0x138),
                 *(undefined8 *)(param_1 + 0x140));
    *(undefined8 *)(param_1 + 0x138) = 0;
    *(undefined8 *)(param_1 + 0x140) = 0;
  }
  return;
}


// ===== 00459b30 memDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void memDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  
  lVar3 = *(long *)(param_1 + 0xf0);
  plVar4 = *(long **)(*(long *)(param_1 + 0xb8) + 0x48);
  lVar5 = plVar4[2];
  uVar1 = *(undefined4 *)(*plVar4 + 0x48);
  uVar2 = *(undefined4 *)(plVar4[3] + 0x10);
  if ((*(char *)(param_1 + 0xd8) != '\0') && (*(long *)(param_1 + 0x118) != 0)) {
    memDestructCommon_IMPL();
    memdescFree(*(undefined8 *)(param_1 + 0x118));
    memdescDestroy(*(undefined8 *)(param_1 + 0x118));
  }
  if ((*(char *)(param_1 + 0x1b0) == '\0') ||
     (((*(char *)(lVar3 + 0x908) == '\0' && (*(char *)(lVar3 + 0x909) == '\0')) &&
      (*(char *)(lVar3 + 0x90a) == '\0')))) {
    return;
  }
  lVar7 = gpuGetRpc(lVar3);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem.c",0xb1);
  }
  else {
    if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
      uVar6 = (**(code **)(lVar7 + 0xf0))
                        (lVar3,lVar7,uVar1,uVar2,(int)lVar5,*(code **)(lVar7 + 0xf0));
    }
    else {
      uVar6 = (**(code **)(lVar3 + 0x3b70))(lVar3 + 0x3b58,uVar1,(int)lVar5);
    }
    if ((uVar6 & 0xffffffef) == 0) {
      return;
    }
  }
  nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                      "src/kernel/mem_mgr/mem.c",0xb2);
  return;
}


// ===== 00459c80 memGetByHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong memGetByHandle_IMPL(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  ulong uVar1;
  long *plVar2;
  long local_20 [2];
  
  *param_3 = 0;
  uVar1 = clientGetResourceRef_IMPL(param_1,param_2,local_20);
  if ((int)uVar1 == 0) {
    plVar2 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_20[0] + 8),__nvoc_class_def_Memory);
    *param_3 = plVar2;
    if (plVar2 == (long *)0x0) {
      uVar1 = 0x33;
    }
    else {
      uVar1 = (**(code **)(*plVar2 + 0x1f8))(plVar2,0,*(code **)(*plVar2 + 0x1f8));
      if ((int)uVar1 != 0) {
        nvCheckOkFailedNoLog
                  (1,uVar1 & 0xffffffff,"memIsReady(*ppMemory, NV_FALSE)","src/kernel/mem_mgr/mem.c"
                   ,0x345);
        uVar1 = uVar1 & 0xffffffff;
      }
    }
  }
  return uVar1;
}


// ===== 00459d18 memGetByHandleAndDevice_IMPL.cold =====

void memGetByHandleAndDevice_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00459d30 memGetByHandleAndDevice_IMPL =====

undefined8
memGetByHandleAndDevice_IMPL(undefined8 param_1,undefined8 param_2,int param_3,long *param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = memGetByHandle_IMPL(param_1,param_2,param_4);
  if ((int)uVar2 == 0) {
    if (*(long *)(*param_4 + 0xe0) == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if (*(int *)(*(long *)(*(long *)(*(long *)(*param_4 + 0xe0) + 0x110) + 0x48) + 0x10) != param_3)
    {
      *param_4 = 0;
      return 0x57;
    }
  }
  return uVar2;
}


// ===== 00459da0 memIsReady_IMPL =====

byte memIsReady_IMPL(long param_1)

{
  return -(*(long *)(param_1 + 0x118) == 0) & 0x31;
}


// ===== 00459dc0 memControl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memControl_IMPL(long *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x1f8))(param_1,0);
  if (uVar1 == 0) {
    uVar2 = resControl_IMPL(param_1[0x17],param_2,param_3);
    return uVar2;
  }
  nvCheckOkFailedNoLog(1,uVar1,"memIsReady(pMemory, NV_FALSE)","src/kernel/mem_mgr/mem.c",0x37d);
  return (ulong)uVar1;
}


// ===== 00459e3f memCopyConstruct_IMPL.cold =====

void memCopyConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00459e50 memCopyConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int memCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  code *pcVar15;
  bool bVar16;
  char cVar17;
  int iVar18;
  long *plVar19;
  undefined8 uVar20;
  long lVar21;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  bool bVar22;
  
  lVar6 = *(long *)(param_2 + 8);
  lVar7 = *(long *)(param_3 + 0x58);
  lVar8 = *(long *)(param_2 + 0x10);
  lVar9 = *(long *)(param_3 + 0x50);
  plVar19 = (long *)__nvoc_dynamicCast(*(undefined8 *)(lVar7 + 8),__nvoc_class_def_Memory);
  if (*(long *)(lVar7 + 0x18) == 0) {
    nvAssertFailedNoLog("pSrcParentRef != NULL","src/kernel/mem_mgr/mem.c",0x39b);
    return 0x36;
  }
  lVar10 = *(long *)(lVar8 + 0x18);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pDstParentRef != NULL","src/kernel/mem_mgr/mem.c",0x39c);
    return 0x36;
  }
  if (plVar19 == (long *)0x0) {
    nvAssertFailedNoLog("pMemorySrc != NULL","src/kernel/mem_mgr/mem.c",0x39d);
    return 0x33;
  }
  iVar18 = (**(code **)(*plVar19 + 0x1f8))(plVar19,1);
  if (iVar18 != 0) {
    nvCheckOkFailedNoLog
              (1,iVar18,"memIsReady(pMemorySrc, NV_TRUE)","src/kernel/mem_mgr/mem.c",0x39f);
    return iVar18;
  }
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar15 = (code *)invalidInstructionException();
    (*pcVar15)();
  }
  plVar11 = *(long **)(*(long *)(param_1 + 0xb8) + 0x48);
  if (*(int *)(*plVar11 + 0x48) == *(int *)(plVar11[3] + 0x10)) {
    if (*(int *)(**(long **)(plVar19[0x17] + 0x48) + 0x48) !=
        *(int *)((*(long **)(plVar19[0x17] + 0x48))[3] + 0x10)) {
      nvCheckFailedNoLog(4,"RES_GET_CLIENT_HANDLE(pMemorySrc) == RES_GET_PARENT_HANDLE(pMemorySrc)",
                         "src/kernel/mem_mgr/mem.c",0x3a8);
      return 0x36;
    }
    return 0;
  }
  if (plVar19[0x1c] == 0) {
    nvAssertFailedNoLog("pSrcDevice != NULL","src/kernel/mem_mgr/mem.c",0x3b6);
    return 0x36;
  }
  lVar21 = *(long *)(param_1 + 0xe0);
  if (lVar21 == 0) {
    nvAssertFailedNoLog("pDstDevice != NULL","src/kernel/mem_mgr/mem.c",0x3b7);
    return 0x36;
  }
  if ((plVar19[0x1d] != 0) != (*(long *)(param_1 + 0xe8) != 0)) {
    nvDbg_Printf("src/kernel/mem_mgr/mem.c",0x3bb,"memCopyConstruct_IMPL",1,
                 "NVRM: Parent type mismatch between Src and Dst objectsBoth should be either device or subDevice\n"
                );
    return 0x36;
  }
  lVar12 = plVar19[0x1e];
  lVar13 = *(long *)(param_1 + 0xf0);
  cVar17 = rmGpuLockIsOwner();
  if (cVar17 == '\0') {
    cVar17 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar12 + 0x7a4));
    if (cVar17 != '\0') {
      cVar17 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar13 + 0x7a4));
      bVar16 = false;
      if (cVar17 != '\0') goto LAB_00459f73;
    }
    iVar18 = rmGpuLocksAcquire(0,0x2000);
    bVar16 = true;
    if (iVar18 != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/mem.c",0x3ca,"memCopyConstruct_IMPL",4,
                   "NVRM: Failed to acquire GPU locks, error 0x%x\n",iVar18);
      return iVar18;
    }
  }
  else {
    bVar16 = false;
  }
LAB_00459f73:
  iVar18 = (**(code **)(*plVar19 + 0x1f0))(plVar19,lVar13,lVar21);
  if (iVar18 == 0) {
    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)((long)plVar19 + 0xfc);
    *(long *)(param_1 + 0x100) = plVar19[0x20];
    *(int *)(param_1 + 0x108) = (int)plVar19[0x21];
    *(long *)(param_1 + 0x110) = plVar19[0x22];
    lVar14 = plVar19[0x23];
    *(undefined8 *)(param_1 + 0x138) = 0;
    *(long *)(param_1 + 0x118) = lVar14;
    *(undefined8 *)(param_1 + 0x140) = 0;
    *(int *)(param_1 + 0x188) = (int)plVar19[0x31];
    *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)((long)plVar19 + 0x18c);
    *(int *)(param_1 + 400) = (int)plVar19[0x32];
    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)((long)plVar19 + 0x194);
    *(int *)(param_1 + 0x198) = (int)plVar19[0x33];
    *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)((long)plVar19 + 0x19c);
    lVar14 = plVar19[0x35];
    *(undefined1 *)(param_1 + 0x120) = 0;
    *(long *)(param_1 + 0x1a8) = lVar14;
    *(char *)(param_1 + 0x1b0) = (char)plVar19[0x36];
    *(ulong *)(param_1 + 0x158) =
         (ulong)*(uint *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10);
    uVar2 = *(uint *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10);
    *(long *)(param_1 + 0x150) = param_1;
    *(ulong *)(param_1 + 0x160) = (ulong)uVar2;
    iVar18 = btreeInsert(param_1 + 0x150,lVar21 + 0x188);
    lVar21 = extraout_RDX;
    if (iVar18 == 0) {
      uVar20 = memdescGetMemDescFromGpu(*(undefined8 *)(param_1 + 0x118),lVar13);
      lVar21 = memdescGetPageSize(uVar20,1);
      if (lVar21 == 0) {
        uVar20 = memdescGetMemDescFromGpu(*(undefined8 *)(param_1 + 0x118),lVar13);
        iVar18 = (**(code **)(*(long *)(lVar13 + 0x1b78) + 0x388))
                           (lVar13,*(long *)(lVar13 + 0x1b78),uVar20,1,0);
        if (iVar18 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/mem.c",0x3fa);
        }
      }
      if (*(long *)(param_1 + 0x1a8) != 0) {
        piVar1 = (int *)(*(long *)(param_1 + 0x1a8) + 0x14);
        *piVar1 = *piVar1 + 1;
      }
      memdescAddRef(*(undefined8 *)(param_1 + 0x118));
      piVar1 = (int *)(*(long *)(param_1 + 0x118) + 0x94);
      *piVar1 = *piVar1 + 1;
      lVar21 = *(long *)(param_1 + 0x118);
      if (*(char *)(lVar21 + 100) != '\0') {
        *(char *)(lVar21 + 100) = *(char *)(lVar21 + 100) + '\x01';
      }
      lVar13 = plVar19[0x25];
      *(long **)(param_1 + 0x130) = plVar19;
      *(long *)(param_1 + 0x128) = lVar13;
      plVar19[0x25] = param_1;
      *(long *)(*(long *)(param_1 + 0x128) + 0x130) = param_1;
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar18,"memCheckCopyPermissions(pMemorySrc, pDstGpu, pDstDevice)",
               "src/kernel/mem_mgr/mem.c",0x3d2);
    lVar21 = extraout_RDX_02;
  }
  if ((*(char *)(param_1 + 0x1b0) == '\0') ||
     (((*(char *)(lVar12 + 0x908) == '\0' && (*(char *)(lVar12 + 0x909) == '\0')) &&
      (*(char *)(lVar12 + 0x90a) == '\0')))) {
    bVar22 = iVar18 == 0;
  }
  else {
    lVar21 = gpuGetRpc(lVar12);
    if (lVar21 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem.c",0x416);
      iVar18 = 0x1a;
    }
    else if (iVar18 == 0) {
      uVar3 = *(undefined4 *)(lVar10 + 0x10);
      uVar4 = *(undefined4 *)(lVar9 + 0x48);
      uVar5 = *(undefined4 *)(lVar6 + 0x48);
      if ((*(char *)(lVar12 + 0x909) == '\0') && (*(char *)(lVar12 + 0x90a) == '\0')) {
        iVar18 = (**(code **)(lVar21 + 0x128))
                           (lVar12,lVar21,uVar5,uVar3,*(undefined4 *)(lVar8 + 0x10),uVar4,
                            *(undefined4 *)(lVar7 + 0x10));
        lVar21 = 0;
      }
      else {
        iVar18 = (**(code **)(lVar12 + 0x3ba8))
                           (lVar12 + 0x3b58,uVar5,uVar3,lVar8 + 0x10,uVar4,
                            *(undefined4 *)(lVar7 + 0x10),0);
        lVar21 = extraout_RDX_01;
      }
      bVar22 = true;
      if (iVar18 == 0) goto LAB_0045a306;
    }
    bVar22 = false;
    nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/mem.c",0x41b);
    lVar21 = extraout_RDX_00;
  }
LAB_0045a306:
  if (bVar16) {
    rmGpuLocksRelease(0,0,lVar21);
  }
  *(bool *)(param_1 + 0xd8) = bVar22;
  return iVar18;
}


// ===== 0045a5d0 memConstruct_IMPL =====

undefined8 memConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_2 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x18);
  uVar1 = __nvoc_dynamicCast(*(undefined8 *)(lVar3 + 8),__nvoc_class_def_Device);
  *(undefined8 *)(param_1 + 0xe0) = uVar1;
  lVar2 = __nvoc_dynamicCast(*(undefined8 *)(lVar3 + 8),__nvoc_class_def_Subdevice);
  *(long *)(param_1 + 0xe8) = lVar2;
  if (lVar2 == 0) {
    if (*(long *)(param_1 + 0xe0) == 0) {
      if (*(long *)(param_3 + 0x58) == 0) {
        return 0;
      }
      goto LAB_0045a693;
    }
  }
  else {
    lVar3 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(lVar3 + 0x18) + 8),__nvoc_class_def_Device)
    ;
    *(long *)(param_1 + 0xe0) = lVar3;
    if (lVar3 == 0) {
      return 0x33;
    }
  }
  lVar4 = CliGetGpuFromContext(lVar4,param_1 + 0xf8);
  *(long *)(param_1 + 0xf0) = lVar4;
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pMemory->pGpu != NULL","src/kernel/mem_mgr/mem.c",0x56);
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0;
    if (*(long *)(param_3 + 0x58) != 0) {
LAB_0045a693:
      uVar1 = memCopyConstruct_IMPL(param_1,param_2,param_3);
      return uVar1;
    }
  }
  return uVar1;
}


// ===== 0045a6df memGetMemInterMapParams_IMPL.cold =====

void memGetMemInterMapParams_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045a6f0 memGetMemInterMapParams_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memGetMemInterMapParams_IMPL(long *param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  
  uVar7 = *param_2;
  lVar6 = param_2[1];
  lVar1 = param_1[0x23];
  iVar3 = (**(code **)(*param_1 + 0x1f8))(param_1,0);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog(1,iVar3,"memIsReady(pMemory, NV_FALSE)","src/kernel/mem_mgr/mem.c",0x43b);
    return iVar3;
  }
  lVar5 = *(long *)(lVar6 + 0x18);
  if (lVar5 != 0) {
    lVar5 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 8),__nvoc_class_def_Device);
    if (lVar5 != 0) {
      uVar7 = *(undefined8 *)(*(long *)(lVar5 + 0x128) + 0xe0);
      uVar4 = *(undefined4 *)(*(long *)(*(long *)(lVar5 + 0x110) + 0x48) + 0x10);
      goto LAB_0045a76c;
    }
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(lVar6 + 0x18) + 8),
                               __nvoc_class_def_Subdevice);
    if (lVar6 != 0) {
      uVar7 = *(undefined8 *)(*(long *)(lVar6 + 0x158) + 0xe0);
      if (*(long *)(lVar6 + 0x338) == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      uVar4 = *(undefined4 *)(*(long *)(*(long *)(*(long *)(lVar6 + 0x338) + 0x110) + 0x48) + 0x10);
      goto LAB_0045a76c;
    }
  }
  uVar4 = 0;
LAB_0045a76c:
  param_2[3] = uVar7;
  *(undefined4 *)(param_2 + 5) = uVar4;
  param_2[4] = lVar1;
  return 0;
}


// ===== 0045a810 memGetMemoryMappingDescriptor_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memGetMemoryMappingDescriptor_IMPL(long *param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x1f8))(param_1,0);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog(1,iVar1,"memIsReady(pMemory, NV_FALSE)","src/kernel/mem_mgr/mem.c",0x468);
    return iVar1;
  }
  if (param_1[0x1e] != 0) {
    lVar2 = memdescGetMemDescFromGpu();
    *param_2 = lVar2;
    return 0;
  }
  *param_2 = param_1[0x23];
  return 0;
}


// ===== 0045a8b3 memIsDuplicate_IMPL.cold =====

void memIsDuplicate_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045a8c0 memIsDuplicate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memIsDuplicate_IMPL(long *param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long local_30;
  
  if (param_1 != (long *)0x0) {
    uVar1 = **(undefined8 **)(param_1[0x17] + 0x48);
    iVar3 = (**(code **)(*param_1 + 0x1f8))(param_1,0);
    if (iVar3 == 0) {
      iVar3 = memGetByHandle_IMPL(uVar1,param_2,&local_30);
      if (iVar3 == 0) {
        *(bool *)param_3 = *(long *)(local_30 + 0x118) == param_1[0x23];
      }
    }
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0045a940 memSetSysmemCacheAttrib_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memSetSysmemCacheAttrib_IMPL(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  iVar3 = memdescGetAddressSpace(param_3);
  if (iVar3 != 1) {
    nvAssertFailedNoLog("memdescGetAddressSpace(pMemDesc) == ADDR_SYSMEM","src/kernel/mem_mgr/mem.c"
                        ,0x499);
  }
  uVar5 = *(uint *)(param_2 + 0x1c) & 0xc;
  if (uVar5 == 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) & 0xfffffff3 | 8;
  }
  cVar2 = '\x01';
  uVar4 = *(uint *)(param_2 + 0x18) >> 0x1d;
  if (uVar4 != 0) {
    cVar2 = (uVar4 == 2) * '\x02';
  }
  memdescSetCpuCacheAttrib(param_3,cVar2);
  memdescSetGpuCacheAttrib(param_3,uVar5 != 4);
  cVar2 = (**(code **)(lVar1 + 0x400))(param_1,lVar1,param_2);
  memdescSetFlag(param_3,0x40000000000000,cVar2 == '\0');
  return;
}


// ===== 0045aa30 memSetGpuCacheSnoop_IMPL =====

undefined8 memSetGpuCacheSnoop_IMPL(long param_1,uint param_2,long param_3)

{
  if ((param_1 == 0) || (*(char *)(*(long *)(param_1 + 0x1b78) + 0x447) != '\0')) {
    param_2 = param_2 & 0x300;
    if (param_2 == 0) {
      *(undefined4 *)(param_3 + 0x78) = 0;
      return 0;
    }
    if (param_2 != 0x200) {
      if (param_2 != 0x100) {
        return 0x1f;
      }
      *(undefined4 *)(param_3 + 0x78) = 1;
      return 0;
    }
    *(undefined4 *)(param_3 + 0x78) = 2;
  }
  return 0;
}


// ===== 0045aaa0 _memoryexportUndupMem =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void _memoryexportUndupMem(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(4);
  iVar1 = (**(code **)(lVar2 + 0x18))
                    (lVar2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 8),
                     *(code **)(lVar2 + 0x18));
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,"pRmApi->Free(pRmApi, pParentInfo->hClient, pMemInfo->hDupedMem)",
             "src/kernel/mem_mgr/mem_export.c",0x193);
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}


// ===== 0045ab10 _memoryexportDetachParent =====

void _memoryexportDetachParent(long param_1,long *param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  byte bVar6;
  int iVar7;
  undefined8 local_40;
  long local_38;
  code *local_30;
  
  if (param_2[2] != 0) {
    nvAssertFailedNoLog("pParentInfo->refCount == 0","src/kernel/mem_mgr/mem_export.c",0x161);
    return;
  }
  if (*param_2 != 0) {
    lVar5 = param_2[4];
    uVar3 = *(uint *)(param_2[1] + 0x7b4);
    if (lVar5 != 0) {
      uVar4 = *(uint *)(lVar5 + 0x968);
      piVar1 = (int *)(param_1 + 8 + ((ulong)uVar4 + 0x44 + (ulong)uVar3 * 0x10) * 4);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        bVar6 = (byte)uVar4 & 0x1f;
        puVar2 = (uint *)(param_1 + 0x70 + (ulong)uVar3 * 4);
        *puVar2 = *puVar2 & (-2 << bVar6 | 0xfffffffeU >> 0x20 - bVar6);
      }
      iVar7 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(lVar5 + 0x978));
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,"kmigmgrDecRefCount(pKernelMIGGpuInstance->pShare)",
                   "src/kernel/mem_mgr/mem_export.c",0x173);
      }
    }
    iVar7 = threadStateGetCurrent(&local_40,0);
    if (iVar7 != 0) {
      nvAssertFailedNoLog("threadStateGetCurrent(&pThreadNode, NULL) == NV_OK",
                          "src/kernel/mem_mgr/mem_export.c",0x177);
      return;
    }
    local_38 = *param_2;
    local_30 = osReleaseGpuOsInfo;
    iVar7 = threadStateEnqueueCallbackOnFree(local_40,&local_38);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,"threadStateEnqueueCallbackOnFree(pThreadNode, &freeCallback)",
                 "src/kernel/mem_mgr/mem_export.c",0x17d);
    }
    piVar1 = (int *)(param_1 + 0x114 + (ulong)uVar3 * 0x40);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      bVar6 = (byte)uVar3 & 0x1f;
      *(uint *)(param_1 + 0x6c) =
           *(uint *)(param_1 + 0x6c) & (-2 << bVar6 | 0xfffffffeU >> 0x20 - bVar6);
    }
  }
  listRemove_IMPL(param_1 + 0x918,param_2);
  return;
}


// ===== 0045ac90 memoryExportGetNodeId =====

undefined2 memoryExportGetNodeId(long param_1)

{
  return *(undefined2 *)(param_1 + 8);
}


// ===== 0045ac99 memoryexportConstruct_IMPL.cold =====

void memoryexportConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045acb0 memoryexportConstruct_IMPL =====

ulong memoryexportConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  char cVar7;
  undefined2 uVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  uint uVar14;
  long lVar15;
  undefined8 local_48;
  undefined2 local_40;
  
  lVar6 = g_pSys;
  piVar2 = *(int **)(param_3 + 0x40);
  if ((piVar2[10] & 1U) == 0) {
    if (param_1 == 0) {
      uVar13 = memoryexportConstruct_IMPL_cold();
      return uVar13;
    }
    lVar9 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),
                               __nvoc_class_def_RmClient);
    if (*(int *)(lVar9 + 600) == -1) {
      uVar14 = 0x1b;
      goto LAB_0045adad;
    }
    if (*(ushort *)(piVar2 + 9) == 0) {
      uVar14 = 0x1f;
      goto LAB_0045adad;
    }
    lVar15 = (ulong)*(ushort *)(piVar2 + 9) * 0x10 + 0x1948;
    lVar11 = portMemAllocNonPaged(lVar15);
    if (lVar11 == 0) {
      uVar14 = 0x51;
      goto LAB_0045adad;
    }
    portMemSet(lVar11,0,lVar15);
    lVar15 = g_pSys;
    *(undefined4 *)(lVar11 + 0x110) = *(undefined4 *)(lVar9 + 600);
    uVar8 = fabricGetNodeId_IMPL(*(undefined8 *)(lVar15 + 0x260));
    *(undefined2 *)(lVar11 + 0x108) = uVar8;
    LOCK();
    plVar10 = (long *)(lVar15 + 0x1d0);
    lVar9 = *plVar10;
    *plVar10 = *plVar10 + 1;
    UNLOCK();
    *(long *)(lVar11 + 0x100) = lVar9 + 1;
    uVar12 = portMemAllocatorGetGlobalNonPaged();
    lVar9 = portSyncRwLockCreate(uVar12);
    *(long *)(lVar11 + 0x1940) = lVar9;
    if (lVar9 == 0) {
      uVar14 = 0x51;
LAB_0045b03e:
      portMemFree(lVar11);
    }
    else {
      portMemCopy(piVar2 + 1,0x10,lVar11 + 0x100,0x10);
      *(undefined8 *)(lVar11 + 4) = *(undefined8 *)(piVar2 + 1);
      *(undefined8 *)(lVar11 + 0xc) = *(undefined8 *)(piVar2 + 3);
      *(undefined8 *)(lVar11 + 0x14) = *(undefined8 *)(piVar2 + 5);
      *(undefined8 *)(lVar11 + 0x1c) = *(undefined8 *)(piVar2 + 7);
      *(short *)(lVar11 + 0x24) = (short)piVar2[9];
      *(int *)(lVar11 + 0x28) = piVar2[10];
      portMemCopy(lVar11 + 0x2c,0x40,piVar2 + 0xb,0x40);
      uVar12 = portMemAllocatorGetGlobalNonPaged();
      lVar9 = lVar11 + 0x918;
      listInit_IMPL(lVar9,uVar12,0x28);
      *(undefined8 *)(lVar11 + 0xf8) = 1;
      *(long *)(param_1 + 0xd8) = lVar11;
      portSyncRwLockAcquireWrite(*(undefined8 *)(lVar6 + 0x1c8));
      lVar15 = multimapFindSubmap_IMPL(lVar6 + 0x198,*(undefined2 *)(lVar11 + 0x108));
      if (lVar15 == 0) {
        lVar15 = multimapInsertSubmap_IMPL(lVar6 + 0x198,*(undefined2 *)(lVar11 + 0x108));
        if (lVar15 == 0) {
          uVar14 = 0x51;
          listDestroy_IMPL(lVar9);
          goto LAB_0045b0f6;
        }
        plVar10 = (long *)multimapInsertItemNew_IMPL
                                    (lVar6 + 0x198,*(undefined2 *)(lVar11 + 0x108),
                                     *(undefined8 *)(lVar11 + 0x100));
        if (plVar10 == (long *)0x0) {
          listDestroy_IMPL(lVar9);
          multimapRemoveSubmap_IMPL(lVar6 + 0x198,lVar15);
          goto LAB_0045b0f0;
        }
      }
      else {
        plVar10 = (long *)multimapInsertItemNew_IMPL
                                    (lVar6 + 0x198,*(undefined2 *)(lVar11 + 0x108),
                                     *(undefined8 *)(lVar11 + 0x100));
        if (plVar10 == (long *)0x0) {
          listDestroy_IMPL(lVar9);
LAB_0045b0f0:
          uVar14 = 0x19;
LAB_0045b0f6:
          portSyncRwLockReleaseWrite(*(undefined8 *)(lVar6 + 0x1c8));
          portSyncRwLockDestroy(*(undefined8 *)(lVar11 + 0x1940));
          *(undefined8 *)(lVar11 + 0x1940) = 0;
          goto LAB_0045b03e;
        }
      }
      *plVar10 = lVar11;
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar6 + 0x1c8));
      uVar14 = 0;
    }
    goto LAB_0045adad;
  }
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar9 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),
                             __nvoc_class_def_RmClient);
  iVar1 = *piVar2;
  portMemCopy(&local_48,0x10,piVar2 + 1);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar6 + 0x1c8));
  plVar10 = (long *)multimapFindItem_IMPL(lVar6 + 0x198,local_40,local_48);
  if (plVar10 == (long *)0x0) {
    uVar14 = 0x57;
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar6 + 0x1c8));
    goto LAB_0045adad;
  }
  lVar11 = *plVar10;
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar11 + 0x1940));
  cVar7 = rmclientIsCapable_IMPL(lVar9,4);
  if (cVar7 == '\0') {
    if (*(int *)(lVar9 + 600) == *(int *)(lVar11 + 0x110)) goto LAB_0045afae;
LAB_0045ad8b:
    uVar14 = 0x1b;
  }
  else {
    if (iVar1 != *(int *)(lVar11 + 0x110)) goto LAB_0045ad8b;
LAB_0045afae:
    *(undefined8 *)(piVar2 + 0x35) = *(undefined8 *)(lVar11 + 0xd4);
    *(undefined8 *)(piVar2 + 0x37) = *(undefined8 *)(lVar11 + 0xdc);
    *(undefined8 *)(piVar2 + 0x39) = *(undefined8 *)(lVar11 + 0xe4);
    *(undefined8 *)(piVar2 + 0x3b) = *(undefined8 *)(lVar11 + 0xec);
    uVar13 = 0;
    do {
      uVar14 = (int)uVar13 + 0x20;
      uVar12 = *(undefined8 *)(lVar11 + 8 + uVar13);
      uVar3 = *(undefined8 *)(lVar11 + 0x10 + uVar13);
      uVar4 = *(undefined8 *)(lVar11 + 0x18 + uVar13);
      *(undefined8 *)((long)piVar2 + uVar13) = *(undefined8 *)(lVar11 + uVar13);
      *(undefined8 *)((long)piVar2 + uVar13 + 8) = uVar12;
      *(undefined8 *)((long)piVar2 + uVar13 + 0x10) = uVar3;
      *(undefined8 *)((long)piVar2 + uVar13 + 0x18) = uVar4;
      uVar13 = (ulong)uVar14;
    } while (uVar14 < 0xe0);
    *(long *)(lVar11 + 0xf8) = *(long *)(lVar11 + 0xf8) + 1;
    uVar14 = 0;
    *(long *)(param_1 + 0xd8) = lVar11;
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar11 + 0x1940));
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar6 + 0x1c8));
LAB_0045adad:
  return (ulong)uVar14;
}


// ===== 0045b160 memoryexportDestruct_IMPL =====

void memoryexportDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  int *piVar6;
  ushort uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 local_3c [3];
  
  lVar2 = g_pSys;
  lVar1 = *(long *)(param_1 + 0xd8);
  local_3c[0] = 0xffffffff;
  if (lVar1 != 0) {
    *(undefined8 *)(param_1 + 0xd8) = 0;
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x1c8));
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x1940));
    plVar5 = (long *)(lVar1 + 0xf8);
    *plVar5 = *plVar5 + -1;
    if (*plVar5 != 0) {
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x1940));
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x1c8));
      return;
    }
    multimapRemoveItemByKey_IMPL
              (lVar2 + 0x198,*(undefined2 *)(lVar1 + 0x108),*(undefined8 *)(lVar1 + 0x100));
    lVar4 = multimapFindSubmap_IMPL(lVar2 + 0x198,*(undefined2 *)(lVar1 + 0x108));
    if (lVar4 != 0) {
      iVar3 = mapCount_IMPL(lVar4);
      if (iVar3 == 0) {
        multimapRemoveSubmap_IMPL(lVar2 + 0x198,lVar4);
      }
    }
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x1940));
    iVar3 = rmGpuGroupLockAcquire(0,2,0,0x2000,local_3c);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "rmGpuGroupLockAcquire(0, GPU_LOCK_GRP_MASK, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM, &gpuMask)"
                 ,"src/kernel/mem_mgr/mem_export.c",0x1e4);
    }
    if (*(short *)(lVar1 + 0x24) != 0) {
      plVar5 = (long *)(lVar1 + 0x1948);
      uVar7 = 0;
LAB_0045b26f:
      do {
        if ((int)plVar5[1] != 0) {
          lVar4 = *plVar5;
          _memoryexportUndupMem(lVar4,plVar5);
          *(long *)(lVar4 + 0x10) = *(long *)(lVar4 + 0x10) + -1;
          *plVar5 = 0;
          *(short *)(lVar1 + 0xf0) = *(short *)(lVar1 + 0xf0) + -1;
          if (*(long *)(lVar4 + 0x10) == 0) {
            uVar7 = uVar7 + 1;
            plVar5 = plVar5 + 2;
            _memoryexportDetachParent(lVar1,lVar4);
            if (*(ushort *)(lVar1 + 0x24) <= uVar7) break;
            goto LAB_0045b26f;
          }
        }
        uVar7 = uVar7 + 1;
        plVar5 = plVar5 + 2;
      } while (uVar7 < *(ushort *)(lVar1 + 0x24));
    }
    piVar8 = (int *)(lVar1 + 0x70);
    piVar9 = (int *)(lVar1 + 0x154);
    rmGpuGroupLockRelease(local_3c[0],0);
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x1c8));
    do {
      if (piVar9[-0x10] != 0) {
        nvAssertFailedNoLog("pExportInfo->attachedUsageCount[j].gpu == 0",
                            "src/kernel/mem_mgr/mem_export.c",0x1f9);
      }
      piVar6 = piVar9 + -0xf;
      do {
        while (*piVar6 != 0) {
          piVar6 = piVar6 + 1;
          nvAssertFailedNoLog("pExportInfo->attachedUsageCount[j].migGi[i] == 0",
                              "src/kernel/mem_mgr/mem_export.c",0x1fc);
          if (piVar6 == piVar9) goto LAB_0045b340;
        }
        piVar6 = piVar6 + 1;
      } while (piVar6 != piVar9);
LAB_0045b340:
      if (*piVar8 != 0) {
        nvAssertFailedNoLog("pExportInfo->cachedParams.giIdMasks[j] == 0",
                            "src/kernel/mem_mgr/mem_export.c",0x1fd);
      }
      piVar9 = piVar9 + 0x10;
      piVar8 = piVar8 + 1;
    } while (piVar9 != (int *)(lVar1 + 0x954));
    if (*(short *)(lVar1 + 0xf0) != 0) {
      nvAssertFailedNoLog("pExportInfo->cachedParams.numCurHandles == 0",
                          "src/kernel/mem_mgr/mem_export.c",0x200);
    }
    if (*(int *)(lVar1 + 0x6c) != 0) {
      nvAssertFailedNoLog("pExportInfo->cachedParams.deviceInstanceMask == 0",
                          "src/kernel/mem_mgr/mem_export.c",0x201);
    }
    iVar3 = listCount_IMPL(lVar1 + 0x918);
    if (iVar3 != 0) {
      nvAssertFailedNoLog("listCount(&pExportInfo->parentInfoList) == 0",
                          "src/kernel/mem_mgr/mem_export.c",0x203);
    }
    listDestroy_IMPL(lVar1 + 0x918);
    portSyncRwLockDestroy(*(undefined8 *)(lVar1 + 0x1940));
    *(undefined8 *)(lVar1 + 0x1940) = 0;
    portMemFree(lVar1);
    *(undefined8 *)(param_1 + 0xd8) = 0;
  }
  return;
}


// ===== 0045b4c0 memoryexportCanCopy_IMPL =====

undefined8 memoryexportCanCopy_IMPL(void)

{
  return 0;
}


// ===== 0045b4d0 memoryexportCtrlExportMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memoryexportCtrlExportMem_IMPL(long param_1,ushort *param_2)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  bool bVar8;
  bool bVar9;
  long lVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  long lVar15;
  undefined8 *puVar16;
  ulong uVar17;
  long *plVar18;
  long lVar19;
  undefined8 uVar20;
  int *piVar21;
  long lVar22;
  int *piVar23;
  long local_120;
  long local_e0;
  undefined4 local_c8;
  uint local_c4;
  long local_c0;
  long local_b8;
  long local_b0;
  long local_a8;
  long local_a0;
  long local_98;
  
  lVar10 = g_pSys;
  lVar5 = *(long *)(param_1 + 0xd8);
  uVar2 = param_2[0x204];
  local_c8 = 0xffffffff;
  if (0xff < (ushort)(uVar2 - 1)) {
    return 0x1f;
  }
  if ((CARRY2(uVar2,*param_2)) || (*(ushort *)(lVar5 + 0x24) < (ushort)(uVar2 + *param_2))) {
    return 0x5b;
  }
  lVar15 = resservGetTlsCallContext();
  local_c0 = 0;
  lVar22 = *(long *)(lVar15 + 8);
  lVar15 = *(long *)(lVar15 + 0x48);
  local_b8 = 0;
  if (*(int *)(lVar22 + 0x48) == *(int *)(param_2 + 2)) {
    uVar20 = 0;
LAB_0045b81a:
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar10 + 0x1c8));
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar5 + 0x1940));
    puVar16 = (undefined8 *)listAppendNew_IMPL(lVar5 + 0x918);
    if (puVar16 == (undefined8 *)0x0) {
      iVar12 = 0x51;
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0x1940));
      goto LAB_0045bcb9;
    }
    local_e0 = 0;
    bVar9 = true;
  }
  else {
    iVar12 = deviceGetByHandle_IMPL(lVar22,*(int *)(param_2 + 2),&local_c0);
    if (iVar12 == 0) {
      local_e0 = *(long *)(*(long *)(local_c0 + 0x128) + 0xe0);
    }
    else {
      iVar12 = subdeviceGetByHandle_IMPL(lVar22,*(undefined4 *)(param_2 + 2),&local_b8);
      if (iVar12 != 0) {
        return iVar12;
      }
      local_e0 = *(long *)(*(long *)(local_b8 + 0x158) + 0xe0);
    }
    cVar11 = osMatchGpuOsInfo(local_e0,*(undefined8 *)(lVar15 + 0x50));
    if (cVar11 == '\0') {
      return 0x26;
    }
    uVar20 = *(undefined8 *)(lVar15 + 0x50);
    if (local_e0 == 0) goto LAB_0045b81a;
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar5 + 0x1940));
    puVar16 = (undefined8 *)listAppendNew_IMPL(lVar5 + 0x918);
    if (puVar16 == (undefined8 *)0x0) {
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0x1940));
      return 0x51;
    }
    bVar9 = false;
  }
  local_120 = lVar5 + 0x918;
  *puVar16 = uVar20;
  puVar16[2] = 0;
  puVar16[1] = local_e0;
  puVar16[3] = 0;
  puVar16[4] = 0;
  iVar12 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_c8);
  lVar15 = local_b8;
  lVar22 = local_c0;
  if (iVar12 == 0) {
    uVar14 = *(undefined4 *)(g_pSys + 0x1d8);
    puVar16[4] = 0;
    puVar16[3] = CONCAT44(uVar14,uVar14);
    if (local_e0 == 0) {
      if (param_2[0x204] != 0) {
LAB_0045b901:
        piVar23 = (int *)(lVar5 + 0x948);
        lVar22 = 0;
        piVar21 = piVar23;
        do {
          iVar4 = *(int *)(param_2 + lVar22 * 2 + 4);
          if (iVar4 != 0) {
            lVar15 = **(long **)(*(long *)(param_1 + 0xb8) + 0x48);
            lVar19 = rmapiGetInterface(4);
            lVar6 = puVar16[4];
            lVar7 = puVar16[1];
            iVar13 = clientGetResourceRef_IMPL(lVar15,iVar4,&local_b0);
            if (iVar13 == 0) {
              plVar18 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_b0 + 8),
                                                   __nvoc_class_def_Memory);
              if (plVar18 == (long *)0x0) {
                iVar13 = 0x33;
              }
              else {
                cVar11 = (**(code **)(*plVar18 + 0x208))(plVar18);
                if (cVar11 == '\0') goto LAB_0045bd40;
                portMemSet(&local_a8,0,0x70);
                local_98 = local_b0;
                local_a0 = lVar15;
                iVar13 = (**(code **)(*plVar18 + 0x1b8))(plVar18,&local_a8,0x8000,&local_c4);
                if (iVar13 != 0) {
                  nvDbg_Printf("src/kernel/mem_mgr/mem_export.c",0x247,"_memoryexportVerifyMem",4,
                               "NVRM: Failed to query address space: 0x%x\n",iVar13);
                  goto LAB_0045bb27;
                }
                if (local_c4 == 6) {
                  *(undefined1 *)(piVar21 + 1) = 3;
joined_r0x0045bef7:
                  if (lVar7 != 0) {
LAB_0045ba40:
                    if ((lVar7 != plVar18[0x1e]) && (lVar7 != *(long *)plVar18[0x23])) {
LAB_0045bf68:
                      iVar13 = 0x36;
                      goto LAB_0045bb27;
                    }
                  }
                }
                else {
                  if (6 < local_c4) {
                    if (local_c4 != 7) {
LAB_0045bd40:
                      iVar13 = 0x56;
                      goto LAB_0045bb27;
                    }
                    *(undefined1 *)(piVar21 + 1) = 4;
                    goto joined_r0x0045bef7;
                  }
                  if (local_c4 == 1) {
                    *(undefined1 *)(piVar21 + 1) = 1;
                    goto joined_r0x0045bef7;
                  }
                  if (local_c4 != 2) goto LAB_0045bd40;
                  *(undefined1 *)(piVar21 + 1) = 2;
                  if (lVar7 != 0) {
                    if ((lVar6 == 0) || (*(long *)(lVar6 + 0x980) == plVar18[0x22]))
                    goto LAB_0045ba40;
                    goto LAB_0045bf68;
                  }
                }
                iVar13 = (**(code **)(lVar19 + 0x50))
                                   (lVar19,*(undefined4 *)(puVar16 + 3),
                                    *(undefined4 *)((long)puVar16 + 0x1c),piVar21,
                                    *(undefined4 *)(lVar15 + 0x48),iVar4,0);
                if (iVar13 == 0) goto LAB_0045ba9a;
              }
            }
LAB_0045bb27:
            nvDbg_Printf("src/kernel/mem_mgr/mem_export.c",0x371,"memoryexportCtrlExportMem_IMPL",4,
                         "NVRM: Failed to duping 0x%x\n");
            if ((short)lVar22 != 0) {
              lVar15 = lVar5 + 0x940;
              lVar22 = lVar22 * 0x10 + lVar15;
              do {
                if (*(int *)(lVar15 + 8) != 0) {
                  _memoryexportUndupMem(puVar16,lVar15);
                }
                lVar15 = lVar15 + 0x10;
              } while (lVar22 != lVar15);
              lVar22 = puVar16[4];
              iVar12 = iVar13;
              goto joined_r0x0045bfc7;
            }
            goto LAB_0045bfc0;
          }
LAB_0045ba9a:
          lVar22 = lVar22 + 1;
          piVar21 = piVar21 + 4;
        } while ((ushort)lVar22 < param_2[0x204]);
        if (param_2[0x204] != 0) {
          iVar13 = 0;
          do {
            lVar15 = (ulong)((uint)*param_2 + iVar13) * 0x10;
            lVar22 = lVar5 + lVar15;
            if (*(int *)(lVar22 + 0x1950) != 0) {
              lVar6 = *(long *)(lVar22 + 0x1948);
              _memoryexportUndupMem(lVar6,lVar5 + 0x1948 + lVar15);
              *(long *)(lVar6 + 0x10) = *(long *)(lVar6 + 0x10) + -1;
              *(undefined8 *)(lVar22 + 0x1948) = 0;
              *(short *)(lVar5 + 0xf0) = *(short *)(lVar5 + 0xf0) + -1;
              if (*(long *)(lVar6 + 0x10) == 0) {
                _memoryexportDetachParent(lVar5,lVar6);
              }
              if (*(int *)(lVar22 + 0x1950) != 0) {
                nvAssertFailedNoLog("pMemInfo->hDupedMem == 0","src/kernel/mem_mgr/mem_export.c",899
                                   );
              }
            }
            if (*piVar23 != 0) {
              uVar20 = *(undefined8 *)(piVar23 + -2);
              *(undefined8 *)(lVar22 + 0x1950) = *(undefined8 *)piVar23;
              *(undefined8 *)(lVar22 + 0x1948) = uVar20;
              puVar16[2] = puVar16[2] + 1;
              *(undefined8 **)(lVar22 + 0x1948) = puVar16;
              *(short *)(lVar5 + 0xf0) = *(short *)(lVar5 + 0xf0) + 1;
              *piVar23 = 0;
            }
            iVar13 = iVar13 + 1;
            piVar23 = piVar23 + 4;
          } while ((ushort)iVar13 < param_2[0x204]);
        }
        if (local_e0 != 0) goto LAB_0045b790;
      }
    }
    else {
      if ((*(long *)(local_e0 + 0x1bc0) != 0) &&
         (cVar11 = kmigmgrIsMIGEnabled_IMPL(), cVar11 != '\0')) {
        if (lVar15 != 0) {
          lVar22 = *(long *)(*(long *)(lVar15 + 0x158) + 0xe8);
        }
        iVar13 = kmigmgrGetInstanceRefFromDevice_IMPL
                           (local_e0,*(undefined8 *)(local_e0 + 0x1bc0),lVar22,&local_a8);
        if (iVar13 == 0) {
          cVar11 = kmigmgrIsMIGReferenceValid_IMPL(&local_a8);
          iVar13 = 0x40;
          if ((cVar11 != '\0') &&
             (iVar13 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(local_a8 + 0x978)), iVar13 == 0)) {
            puVar16[4] = local_a8;
            *(undefined4 *)(puVar16 + 3) = *(undefined4 *)(local_a8 + 0x9c0);
            if (lVar15 == 0) {
              uVar14 = *(undefined4 *)(local_a8 + 0x9c4);
            }
            else {
              uVar14 = *(undefined4 *)(local_a8 + 0x9c8);
            }
            goto LAB_0045b770;
          }
        }
LAB_0045bfc0:
        lVar22 = puVar16[4];
        iVar12 = iVar13;
joined_r0x0045bfc7:
        if ((lVar22 != 0) &&
           (iVar13 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(lVar22 + 0x978)), iVar13 != 0)) {
          bVar8 = true;
          goto LAB_0045bc4c;
        }
        listRemove_IMPL(local_120,puVar16);
        goto LAB_0045bc80;
      }
      *(undefined4 *)(puVar16 + 3) = *(undefined4 *)(*(long *)(local_e0 + 0x1b78) + 0xd10);
      if (lVar15 == 0) {
        uVar14 = *(undefined4 *)(*(long *)(local_e0 + 0x1b78) + 0xd14);
LAB_0045b770:
        *(undefined4 *)((long)puVar16 + 0x1c) = uVar14;
        uVar2 = param_2[0x204];
      }
      else {
        *(undefined4 *)((long)puVar16 + 0x1c) =
             *(undefined4 *)(*(long *)(local_e0 + 0x1b78) + 0xd18);
        uVar2 = param_2[0x204];
      }
      if (uVar2 != 0) goto LAB_0045b901;
LAB_0045b790:
      uVar3 = *(uint *)(local_e0 + 0x7b4);
      uVar17 = (ulong)uVar3;
      piVar23 = (int *)(lVar5 + 0x114 + uVar17 * 0x40);
      *piVar23 = *piVar23 + 1;
      *(uint *)(lVar5 + 0x6c) = *(uint *)(lVar5 + 0x6c) | 1 << ((byte)uVar3 & 0x1f);
      if (puVar16[4] != 0) {
        uVar3 = *(uint *)(puVar16[4] + 0x968);
        piVar23 = (int *)(lVar5 + 8 + ((ulong)uVar3 + 0x44 + uVar17 * 0x10) * 4);
        *piVar23 = *piVar23 + 1;
        puVar1 = (uint *)(lVar5 + 0x70 + uVar17 * 4);
        *puVar1 = *puVar1 | 1 << ((byte)uVar3 & 0x1f);
      }
    }
    if (puVar16[2] == 0) {
      _memoryexportDetachParent(lVar5,puVar16);
    }
LAB_0045bc80:
    rmGpuGroupLockRelease(local_c8,0);
  }
  else {
    nvAssertFailedNoLog(&DAT_00d81b4d,"src/kernel/mem_mgr/mem_export.c",0x357);
    if ((puVar16[4] == 0) ||
       (iVar13 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(puVar16[4] + 0x978)), iVar13 == 0)) {
      listRemove_IMPL(local_120,puVar16);
    }
    else {
      bVar8 = false;
LAB_0045bc4c:
      nvAssertOkFailedNoLog
                (iVar13,"kmigmgrDecRefCount(pParentInfo->pKernelMIGGpuInstance->pShare)",
                 "src/kernel/mem_mgr/mem_export.c",0x3ba);
      listRemove_IMPL(local_120,puVar16);
      if (bVar8) goto LAB_0045bc80;
    }
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0x1940));
  if (!bVar9) {
    return iVar12;
  }
LAB_0045bcb9:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar10 + 0x1c8));
  return iVar12;
}


// ===== 0045c02a memoryexportCtrlImportMem_IMPL.cold =====

void memoryexportCtrlImportMem_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045c050 memoryexportCtrlImportMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memoryexportCtrlImportMem_IMPL(long param_1,ushort *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  code *pcVar8;
  long lVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  long lVar15;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 uVar16;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  long lVar17;
  ushort *puVar18;
  ushort *puVar19;
  ulong uVar20;
  int iVar21;
  int iVar22;
  long local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  long local_c0;
  undefined8 local_b8;
  undefined4 local_9c;
  long local_98;
  long local_90 [2];
  long local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  lVar9 = g_pSys;
  lVar4 = *(long *)(param_1 + 0xd8);
  lVar14 = rmapiGetInterface(4);
  local_9c = 0xffffffff;
  uVar3 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xb8) + 0x48) + 0x48);
  uVar2 = param_2[1];
  if ((ushort)(uVar2 - 1) < 0x80) {
    if ((CARRY2(uVar2,*param_2)) || (*(ushort *)(lVar4 + 0x24) < (ushort)(uVar2 + *param_2))) {
      iVar11 = 0x5b;
    }
    else {
      portSyncRwLockAcquireRead(*(undefined8 *)(lVar9 + 0x1c8));
      portSyncRwLockAcquireWrite(*(undefined8 *)(lVar4 + 0x1940));
      iVar11 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_9c);
      if (iVar11 == 0) {
        iVar22 = 0;
        uVar16 = extraout_RDX;
        if (param_2[1] != 0) {
          puVar19 = param_2 + 0x102;
          puVar18 = param_2;
          do {
            puVar18 = puVar18 + 2;
            lVar17 = (ulong)((uint)*param_2 + iVar22) * 0x10 + lVar4;
            iVar13 = *(int *)(lVar17 + 0x1950);
            if (iVar13 != 0) {
              if (*(int *)puVar18 == 0) {
                iVar11 = 0x33;
                nvDbg_Printf("src/kernel/mem_mgr/mem_export.c",0x47e,
                             "memoryexportCtrlImportMem_IMPL",4,"NVRM: Invalid handle\n");
                uVar16 = extraout_RDX_03;
              }
              else {
                lVar15 = *(long *)(lVar17 + 0x1948);
                lVar5 = *(long *)(lVar15 + 8);
                lVar6 = **(long **)(*(long *)(param_1 + 0xb8) + 0x48);
                if (lVar5 == 0) {
                  iVar21 = *(int *)(lVar6 + 0x48);
                  goto LAB_0045c291;
                }
                if ((*(long *)(lVar5 + 0x1bc0) == 0) ||
                   (cVar10 = kmigmgrIsMIGEnabled_IMPL(lVar5), cVar10 == '\0')) {
                  iVar13 = *(int *)(lVar15 + 0x1c);
                  iVar21 = *(int *)(*(long *)(lVar5 + 0x1b78) + 0xd14);
                  iVar12 = deviceGetByGpu_IMPL(lVar6,lVar5,1,local_90);
                  if (iVar12 == 0) {
                    if (iVar21 == iVar13) {
                      if (local_90[0] == 0) {
                    /* WARNING: Does not return */
                        pcVar8 = (code *)invalidInstructionException();
                        (*pcVar8)();
                      }
                      iVar21 = *(int *)(*(long *)(*(long *)(local_90[0] + 0x110) + 0x48) + 0x10);
LAB_0045c438:
                      iVar13 = *(int *)(lVar17 + 0x1950);
                      lVar15 = *(long *)(lVar17 + 0x1948);
                    }
                    else {
                      iVar12 = subdeviceGetByDeviceAndGpu_IMPL(lVar6,local_90[0],lVar5,&local_80);
                      if (iVar12 != 0) goto LAB_0045c337;
                      if (local_80 == 0) {
                    /* WARNING: Does not return */
                        pcVar8 = (code *)invalidInstructionException();
                        (*pcVar8)();
                      }
                      iVar13 = *(int *)(lVar17 + 0x1950);
                      lVar15 = *(long *)(lVar17 + 0x1948);
                      iVar21 = *(int *)(*(long *)(*(long *)(local_80 + 0x140) + 0x48) + 0x10);
                    }
LAB_0045c291:
                    iVar13 = (**(code **)(lVar14 + 0x50))
                                       (lVar14,uVar3,iVar21,puVar18,*(undefined4 *)(lVar15 + 0x18),
                                        iVar13);
                    uVar16 = 0;
                    if (iVar13 == 0) {
                      uVar1 = *(undefined1 *)(lVar17 + 0x1954);
                      *(int *)puVar19 = iVar21;
                      *(undefined1 *)(puVar19 + 2) = uVar1;
                      goto LAB_0045c2d0;
                    }
                    nvDbg_Printf("src/kernel/mem_mgr/mem_export.c",0x494,
                                 "memoryexportCtrlImportMem_IMPL",4,"NVRM: Failed to duping 0x%x\n",
                                 iVar13);
                    uVar16 = extraout_RDX_04;
                    iVar11 = iVar13;
                    goto LAB_0045c36b;
                  }
                }
                else {
                  lVar5 = *(long *)(lVar15 + 8);
                  if (lVar5 == 0) {
                    nvAssertFailedNoLog("pSrcGpu != NULL","src/kernel/mem_mgr/mem_export.c",0x3d9);
                  }
                  else {
                    lVar7 = *(long *)(lVar15 + 0x20);
                    if (lVar7 != 0) {
                      iVar13 = *(int *)(lVar7 + 0x9c4);
                      iVar21 = *(int *)(lVar15 + 0x1c);
                      clientRefIter(&local_f8,lVar6,0,&DAT_00e0ac20,0,1);
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
                        do {
                          cVar10 = clientRefIterNext(lVar6,&local_80);
                          if (cVar10 == '\0') goto LAB_0045c61a;
                          lVar15 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                                      __nvoc_class_def_Device);
                        } while (((lVar15 == 0) ||
                                 (iVar12 = kmigmgrGetInstanceRefFromDevice_IMPL
                                                     (lVar5,*(undefined8 *)(lVar5 + 0x1bc0),lVar15,
                                                      local_90), iVar12 != 0)) ||
                                (lVar7 != local_90[0]));
                        if (iVar13 == iVar21) {
                          iVar21 = *(int *)(*(long *)(*(long *)(lVar15 + 0x110) + 0x48) + 0x10);
                          goto LAB_0045c611;
                        }
                        iVar12 = subdeviceGetByDeviceAndGpu_IMPL(lVar6,lVar15,lVar5,&local_98);
                      } while (iVar12 != 0);
                      if (local_98 == 0) {
                    /* WARNING: Does not return */
                        pcVar8 = (code *)invalidInstructionException();
                        (*pcVar8)();
                      }
                      iVar21 = *(int *)(*(long *)(*(long *)(local_98 + 0x140) + 0x48) + 0x10);
LAB_0045c611:
                      if (iVar21 != 0) goto LAB_0045c438;
LAB_0045c61a:
                      iVar12 = 0x57;
                      goto LAB_0045c337;
                    }
                    nvAssertFailedNoLog("pSrcKernelMIGGpuInstance != NULL",
                                        "src/kernel/mem_mgr/mem_export.c",0x3dc);
                  }
                  iVar12 = 0x40;
                }
LAB_0045c337:
                iVar11 = iVar12;
                nvDbg_Printf("src/kernel/mem_mgr/mem_export.c",0x488,
                             "memoryexportCtrlImportMem_IMPL",4,
                             "NVRM: Failed to find parent: 0x%x\n");
                uVar16 = extraout_RDX_01;
              }
LAB_0045c36b:
              if ((short)iVar22 != 0) {
                uVar20 = 1;
                do {
                  if (*(int *)(param_2 + uVar20 * 4 + 0xfe) != 0) {
                    (**(code **)(lVar14 + 0x18))(lVar14,uVar3,*(undefined4 *)(param_2 + uVar20 * 2))
                    ;
                    uVar16 = extraout_RDX_02;
                  }
                  uVar20 = uVar20 + 1;
                } while (iVar22 + 1 != uVar20);
              }
              break;
            }
            portMemSet(puVar19,0,8);
            uVar16 = extraout_RDX_00;
LAB_0045c2d0:
            iVar22 = iVar22 + 1;
            puVar19 = puVar19 + 4;
          } while ((ushort)iVar22 < param_2[1]);
        }
        rmGpuGroupLockRelease(local_9c,0,uVar16);
      }
      else {
        nvAssertFailedNoLog(&DAT_00d81b4d,"src/kernel/mem_mgr/mem_export.c",0x46b);
      }
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar4 + 0x1940));
      portSyncRwLockReleaseRead(*(undefined8 *)(lVar9 + 0x1c8));
    }
  }
  else {
    iVar11 = 0x1f;
  }
  return iVar11;
}


// ===== 0045c770 memoryexportCtrlGetInfo_IMPL =====

undefined8 memoryexportCtrlGetInfo_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  
  lVar1 = *(long *)(param_1 + 0xd8);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x1940));
  lVar2 = *(long *)(param_1 + 0xd8);
  *(undefined8 *)(param_2 + 0xd4) = *(undefined8 *)(lVar2 + 0xd4);
  *(undefined8 *)(param_2 + 0xdc) = *(undefined8 *)(lVar2 + 0xdc);
  *(undefined8 *)(param_2 + 0xe4) = *(undefined8 *)(lVar2 + 0xe4);
  *(undefined8 *)(param_2 + 0xec) = *(undefined8 *)(lVar2 + 0xec);
  uVar7 = 0;
  do {
    uVar6 = (int)uVar7 + 0x20;
    uVar3 = *(undefined8 *)(lVar2 + 8 + uVar7);
    uVar4 = *(undefined8 *)(lVar2 + 0x10 + uVar7);
    uVar5 = *(undefined8 *)(lVar2 + 0x18 + uVar7);
    *(undefined8 *)(param_2 + uVar7) = *(undefined8 *)(lVar2 + uVar7);
    *(undefined8 *)(param_2 + 8 + uVar7) = uVar3;
    *(undefined8 *)(param_2 + 0x10 + uVar7) = uVar4;
    *(undefined8 *)(param_2 + 0x18 + uVar7) = uVar5;
    uVar7 = (ulong)uVar6;
  } while (uVar6 < 0xe0);
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x1940));
  return 0;
}


// ===== 0045c830 memoryexportControl_IMPL =====

void memoryexportControl_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0xb8);
  }
  resControl_IMPL(uVar1);
  return;
}


// ===== 0045c850 memoryexportClearCache =====

void memoryexportClearCache(undefined2 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  char cVar4;
  long lVar5;
  undefined8 local_48 [5];
  
  lVar3 = g_pSys;
  portSyncRwLockAcquireWrite(*(undefined8 *)(g_pSys + 0x1c8));
  lVar5 = multimapFindSubmap_IMPL(lVar3 + 0x198,param_1);
  if (lVar5 != 0) {
    uVar1 = mapFindLEQ_IMPL(lVar5,0xffffffffffffffff);
    uVar2 = mapFindGEQ_IMPL(lVar5,0);
    multimapItemIterRange_IMPL(local_48,lVar3 + 0x198,uVar2,uVar1);
    while( true ) {
      cVar4 = multimapItemIterNext_IMPL(local_48);
      if (cVar4 == '\0') break;
      multimapRemoveItem_IMPL(lVar3 + 0x198,local_48[0]);
    }
    multimapRemoveSubmap_IMPL(lVar3 + 0x198,lVar5);
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar3 + 0x1c8));
  return;
}


// ===== 0045c920 _memoryfabricMemDescDestroyCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _memoryfabricMemDescDestroyCallback(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ulong uVar9;
  ulong extraout_RDX;
  ulong uVar10;
  ulong local_58;
  long local_40 [2];
  
  lVar5 = rmapiGetInterface(4);
  if (*(long *)(param_1 + 0x4a18) != 0) {
    lVar6 = __nvoc_dynamicCast(*(long *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
    puVar7 = (undefined8 *)memdescGetMemData(param_3);
    puVar8 = (undefined8 *)
             memdescGetPteArrayForGpu
                       (param_3,param_1,*(undefined8 *)(*(long *)(param_1 + 0x4a18) + 0x50));
    lVar2 = *param_3;
    uVar9 = memdescGetPageSize(param_3,*(undefined8 *)(*(long *)(lVar2 + 0x4a18) + 0x50));
    cVar3 = memdescGetContiguity(param_3,*(undefined8 *)(*(long *)(lVar2 + 0x4a18) + 0x50));
    local_58 = 1;
    uVar10 = extraout_RDX;
    if (cVar3 == '\0') {
      local_58 = (ulong)param_3[6] / uVar9;
      uVar10 = (ulong)param_3[6] % uVar9;
    }
    uVar10 = memdescGetPageSize(param_3,*(undefined8 *)(*(long *)(param_1 + 0x4a18) + 0x50),uVar10);
    uVar1 = *(uint *)(param_3 + 0x2c);
    fabricvaspaceVaToGpaMapRemove_IMPL(lVar6,*puVar8);
    if (*(char *)(lVar6 + 0xa8) == '\0') {
      fabricvaspaceBatchFree_IMPL
                (lVar6,puVar8,local_58 & 0xffffffff,
                 uVar10 >> ((uVar1 & 0xaaaaaaaa) != 0 | (0xffff < uVar1) << 4 |
                            ((uVar1 & 0xff00ff00) != 0) << 3 | ((uVar1 & 0xf0f0f0f0) != 0) << 2 |
                           ((uVar1 & 0xcccccccc) != 0) * '\x02'));
    }
    if (puVar7 != (undefined8 *)0x0) {
      btreeEnumStart(0,local_40,*puVar7);
      if (local_40[0] != 0) {
        nvAssertFailedNoLog("pNode == NULL","src/kernel/mem_mgr/mem_fabric.c",0x154);
      }
      if (*(int *)(puVar7 + 1) != 0) {
        iVar4 = (**(code **)(lVar5 + 0x18))(lVar5,*(undefined4 *)(lVar6 + 0xa0));
        if (iVar4 != 0) {
          nvAssertFailedNoLog("pRmApi->Free(pRmApi, pFabricVAS->hClient, pMemdescData->hDupedPhysMem) == NV_OK"
                              ,"src/kernel/mem_mgr/mem_fabric.c",0x158);
        }
      }
      portMemFree(param_3[8]);
      memdescSetMemData(param_3,0,0);
    }
    portMemFree(param_2);
    return;
  }
  nvAssertFailedNoLog("pGpu->pFabricVAS != NULL","src/kernel/mem_mgr/mem_fabric.c",0x135);
  return;
}


// ===== 0045cb70 _memoryfabricValidatePhysMem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _memoryfabricValidatePhysMem
              (undefined8 param_1,undefined8 param_2,long param_3,undefined8 *param_4,long *param_5,
              byte param_6)

{
  long *plVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long local_40 [2];
  
  lVar4 = *(long *)(param_3 + 0x1b78);
  iVar3 = memGetByHandle_IMPL(param_1,param_2,local_40);
  if (iVar3 == 0) {
    plVar1 = *(long **)(local_40[0] + 0x118);
    if (*plVar1 == 0) {
      nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x6c,"_memoryfabricValidatePhysMem",4,
                   "NVRM: Device-less memory isn\'t supported yet\n");
    }
    else if ((*plVar1 == param_3) || ((param_6 & 1) == 0)) {
      cVar2 = (**(code **)(lVar4 + 0x2c8))(param_3,lVar4,plVar1);
      if (cVar2 == '\0') {
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x7a,"_memoryfabricValidatePhysMem",4,
                     "NVRM: Invalid physmem handle passed\n");
      }
      else {
        lVar4 = memdescGetPageSize(plVar1,1);
        if ((lVar4 == 0x200000) || (lVar4 == 0x20000000)) {
          *param_4 = plVar1;
          if (param_5 == (long *)0x0) {
            return 0;
          }
          *param_5 = local_40[0];
          return 0;
        }
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x84,"_memoryfabricValidatePhysMem",4,
                     "NVRM: Physmem page size should be 2MB\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x73,"_memoryfabricValidatePhysMem",4,
                   "NVRM: Physmem handle\'s owner GPU does not match\n");
    }
    iVar3 = 0x1f;
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",100,"_memoryfabricValidatePhysMem",4,
                 "NVRM: Invalid object handle passed\n");
  }
  return iVar3;
}


// ===== 0045cd50 _memoryfabricFreeFabricVa_VGPU =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void _memoryfabricFreeFabricVa_VGPU(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = gpuGetRpc();
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem_fabric.c",0x16b);
  }
  else {
    if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
      iVar1 = (**(code **)(lVar2 + 0xf0))
                        (param_1,lVar2,*param_2,param_2[1],param_2[2],*(code **)(lVar2 + 0xf0));
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x3b70))(param_1 + 0x3b58);
    }
    if (iVar1 == 0) {
      return;
    }
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/mem_fabric.c",0x16d);
  return;
}


// ===== 0045cdf4 _memoryFabricDetachMem.cold =====

void _memoryFabricDetachMem_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045ce10 _memoryFabricDetachMem =====

int _memoryFabricDetachMem(long param_1,undefined8 param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long *local_40 [2];
  
  local_40[0] = (long *)0x0;
  if (param_1 != 0) {
    plVar1 = *(long **)(*(long *)(param_1 + 0x210) + 0x118);
    puVar6 = (undefined8 *)memdescGetMemData(plVar1);
    iVar5 = btreeSearch(param_2,local_40,*puVar6);
    if (iVar5 == 0) {
      lVar2 = *local_40[0];
      uVar7 = __nvoc_dynamicCast(*(undefined8 *)(*plVar1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
      fabricvaspaceUnmapPhysMemdesc_IMPL(uVar7,plVar1,param_2,*(undefined8 *)(lVar2 + 0x18));
      if (param_3 != '\0') {
        uVar7 = *(undefined8 *)(lVar2 + 8);
        uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x1f8) + 0x48);
        refRemoveInterMapping(uVar3,uVar7,0);
        refDestroyInterMapping(uVar3,uVar7);
      }
      btreeUnlink(lVar2 + 0x20,puVar6);
      portMemFree(lVar2);
    }
    return iVar5;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 0045cf09 memoryfabricConstruct_IMPL.cold =====

void memoryfabricConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045cf20 memoryfabricConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int memoryfabricConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong *puVar5;
  code *pcVar6;
  long *plVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  ulong *puVar15;
  long lVar16;
  undefined8 *puVar17;
  ulong uVar18;
  ulong uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  bool local_9d;
  int local_78;
  undefined4 local_74;
  undefined8 local_70;
  long *local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar3 = *(long *)(param_1 + 0x210);
  lVar4 = *(long *)(lVar3 + 0xf0);
  lVar12 = __nvoc_dynamicCast(*(undefined8 *)(lVar4 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
  puVar5 = *(ulong **)(param_3 + 0x10);
  lVar13 = rmapiGetInterface(4);
  lVar16 = *(long *)(lVar4 + 0x1b78);
  local_70 = 0;
  local_68 = (long *)0x0;
  local_60 = (undefined8 *)0x0;
  local_78 = 0;
  local_74 = 0;
  if (*(long *)(param_3 + 0x16) != 0) {
    return 0;
  }
  if (lVar12 == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x252,"memoryfabricConstruct_IMPL",4,
                 "NVRM: Fabric vaspace object not available\n");
    return 0x56;
  }
  if (*(long *)(lVar12 + 200) == 0) {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x25a,"memoryfabricConstruct_IMPL",4,
                 "NVRM: UC FLA ranges should be initialized by this time!\n");
    return 0x40;
  }
  iVar11 = (int)puVar5[5];
  cVar8 = (**(code **)(lVar16 + 0x2d0))(lVar4,lVar16,puVar5[2],0);
  if (cVar8 == '\0') {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x262,"memoryfabricConstruct_IMPL",4,
                 "NVRM: Unsupported pageSize: 0x%llx\n");
  }
  else if ((*puVar5 & puVar5[2] - 1) == 0) {
    if ((puVar5[1] & puVar5[2] - 1) == 0) {
      uVar2 = (uint)puVar5[3];
      if ((uVar2 & 8) == 0) {
        if ((iVar11 == 0) || ((uVar2 & 1) == 0)) {
          uVar10 = uVar2;
          if ((uVar2 & 1) == 0) {
            iVar9 = _memoryfabricValidatePhysMem
                              (*(undefined8 *)(param_2 + 8),iVar11,lVar4,&local_70,0,1);
            if (iVar9 != 0) {
              return iVar9;
            }
            uVar10 = (uint)puVar5[3];
          }
          if (*(char *)(lVar12 + 0xa8) == '\0') {
            iVar9 = fabricvaspaceAllocNonContiguous_IMPL
                              (lVar12,puVar5[1],*puVar5,*(undefined8 *)(lVar12 + 0xc0),
                               *(undefined8 *)(lVar12 + 200),puVar5[2],
                               (ulong)(byte)((byte)(uVar10 >> 2) & 1 | 4 |
                                            ((byte)(uVar10 >> 1) & 1) * '\x02') << 8,&local_60,
                               &local_78);
            if (iVar9 != 0) goto LAB_0045d630;
          }
          else {
            lVar14 = gpuGetRpc(lVar4);
            if (lVar14 == 0) {
              nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem_fabric.c",0x194);
            }
            else {
              if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
                iVar9 = (**(code **)(lVar14 + 0x348))
                                  (lVar4,lVar14,*param_3,param_3[1],param_3[2],param_3[3],puVar5);
              }
              else {
                iVar9 = (**(code **)(lVar4 + 0x3b60))(lVar4 + 0x3b58);
              }
              if (iVar9 != 0) {
                nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x19e,
                             "_memoryfabricAllocFabricVa_VGPU",4,
                             "NVRM: Alloc NV_MEMORY_FABRIC RPC failed, status: %x\n",iVar9);
                goto LAB_0045d630;
              }
            }
            puVar15 = (ulong *)portMemAllocNonPaged(0x858);
            if (puVar15 == (ulong *)0x0) {
              puVar17 = (undefined8 *)0x0;
              iVar9 = 0x51;
LAB_0045d60d:
              portMemFree(puVar17);
              portMemFree(puVar15);
              _memoryfabricFreeFabricVa_VGPU(lVar4,param_3);
LAB_0045d630:
              nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x2ac,"memoryfabricConstruct_IMPL",4,
                           "NVRM: VA Space alloc failed! Status Code: 0x%x Size: 0x%llx RangeLo: 0x%llx, RangeHi: 0x%llx, page size: 0x%llx\n"
                           ,iVar9,puVar5[1],*(undefined8 *)(lVar12 + 0xc0),
                           *(undefined8 *)(lVar12 + 200),puVar5[2]);
              return iVar9;
            }
            portMemSet(puVar15,0,0x858);
            uVar19 = (ulong)(uVar2 & 8);
            uVar18 = (ulong)(uVar2 & 8);
            puVar17 = (undefined8 *)0x0;
            do {
              *puVar15 = uVar18;
              lVar14 = gpuGetRpc(lVar4);
              if (lVar14 == 0) {
                nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/mem_fabric.c",0x1b0);
                iVar9 = 0x1a;
LAB_0045d83f:
                nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x1b7,
                             "_memoryfabricAllocFabricVa_VGPU",4,
                             "NVRM: CTRL_CMD_DESCRIBE failed, status: 0x%x, numPfns: 0x%x, totalPfns: 0x%llx, readSoFar: 0x%x \n"
                             ,iVar9,(int)puVar15[0x102],puVar15[1],uVar19);
                goto LAB_0045d60d;
              }
              if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
                iVar9 = rpcDmaControl_wrapper
                                  (lVar4,lVar14,*param_3,param_3[2],0xf80102,puVar15,0x858);
              }
              else {
                iVar9 = (**(code **)(lVar4 + 0x3b90))
                                  (lVar4 + 0x3b58,*param_3,param_3[2],0xf80102,puVar15,0x858);
              }
              if (iVar9 != 0) goto LAB_0045d83f;
              if ((puVar17 == (undefined8 *)0x0) &&
                 (puVar17 = (undefined8 *)portMemAllocNonPaged(puVar15[1] * 8),
                 puVar17 == (undefined8 *)0x0)) {
                iVar9 = 0x51;
                goto LAB_0045d60d;
              }
              if ((int)puVar15[0x102] != 0) {
                lVar14 = 0;
                do {
                  lVar1 = lVar14 * 4;
                  iVar9 = (int)lVar14;
                  lVar14 = lVar14 + 1;
                  puVar17[(uint)((int)uVar19 + iVar9)] =
                       (ulong)*(uint *)((long)puVar15 + lVar1 + 0x10) << 0x15;
                } while ((uint)lVar14 < (uint)puVar15[0x102]);
                uVar18 = (ulong)((int)uVar19 + (uint)puVar15[0x102]);
                uVar19 = uVar18;
              }
            } while (uVar18 < puVar15[1]);
            portMemFree(puVar15);
            local_78 = (int)uVar19;
            local_60 = puVar17;
          }
          uVar21 = 0;
          uVar20 = 1;
          iVar9 = memdescCreate(&local_68,lVar4,puVar5[1],0,local_78 == 1,6);
          if (iVar9 == 0) {
            if (local_78 == 1) {
              memdescSetPte(local_68,*(undefined8 *)(*(long *)(lVar4 + 0x4a18) + 0x50),0,*local_60,
                            uVar20);
            }
            else {
              memdescFillPages(local_68,0,local_60,local_78,puVar5[2]);
            }
            memdescSetPageSize(local_68,*(undefined8 *)(*(long *)(lVar4 + 0x4a18) + 0x50),puVar5[2])
            ;
            iVar9 = memConstructCommon_IMPL(lVar3,0xf8,0,local_68,0,0,0,0,0,0,0,0);
            if (iVar9 == 0) {
              iVar9 = (**(code **)(lVar16 + 0x2c0))(lVar4,lVar16,&local_74);
              if (iVar9 == 0) {
                memdescSetPteKindForGpu
                          (*(undefined8 **)(lVar3 + 0x118),**(undefined8 **)(lVar3 + 0x118),local_74
                          );
                memdescSetGpuCacheAttrib(*(undefined8 *)(lVar3 + 0x118),1);
                lVar16 = portMemAllocNonPaged(0x18);
                if (lVar16 == 0) {
                  iVar9 = 0x51;
                }
                else {
                  portMemSet(lVar16,0,0x18);
                  memdescSetMemData(local_68,lVar16,0);
                  puVar17 = (undefined8 *)portMemAllocNonPaged(0x18);
                  if (puVar17 == (undefined8 *)0x0) {
                    iVar9 = 0x51;
                  }
                  else {
                    portMemSet(puVar17,0,0x18);
                    *puVar17 = _memoryfabricMemDescDestroyCallback;
                    puVar17[1] = puVar17;
                    memdescAddDestroyCallback(local_68,puVar17);
                    if (iVar11 == 0) {
LAB_0045d568:
                      plVar7 = local_68;
                      *(int *)(lVar16 + 0x14) = (int)puVar5[3];
                      *(undefined1 *)(lVar3 + 0x1b0) = *(undefined1 *)(lVar12 + 0xa8);
                      lVar3 = *local_68;
                      lVar4 = *(long *)(lVar3 + 0x1ce8);
                      if (((char)(uVar2 & 1) == '\0') && ((puVar5[3] & 0x10) == 0)) {
                        local_9d = false;
                        if (lVar4 != 0) {
                          cVar8 = knvlinkIsP2pLoopbackSupported_IMPL(lVar3,lVar4);
                          local_9d = true;
                          if (cVar8 == '\0') {
                            cVar8 = knvlinkIsForcedConfig_IMPL(lVar3,lVar4);
                            local_9d = cVar8 != '\0';
                          }
                        }
                      }
                      else {
                        local_9d = false;
                        if (lVar4 != 0) {
                          cVar8 = knvlinkIsP2pLoopbackSupported_IMPL(lVar3,lVar4);
                          local_9d = true;
                          if (cVar8 == '\0') {
                            cVar8 = knvlinkIsForcedConfig_IMPL(lVar3,lVar4);
                            local_9d = cVar8 != '\0';
                          }
                        }
                        iVar11 = gpuFabricProbeGetfmCaps(*(undefined8 *)(lVar3 + 0x4c0),&local_48);
                        if (iVar11 == 0) {
                          local_9d = (bool)(local_9d | local_48._1_1_ >> 1 & 1);
                        }
                      }
                      memdescSetFlag(plVar7,0x100000000000000,local_9d);
                      portMemFree(local_60);
                      return 0;
                    }
                    iVar9 = (**(code **)(lVar13 + 0x50))
                                      (lVar13,*(undefined4 *)(lVar12 + 0xa0),
                                       *(undefined4 *)(lVar12 + 0xa4),lVar16 + 8,
                                       *(undefined4 *)(*(long *)(param_2 + 8) + 0x48),iVar11,0);
                    if (iVar9 == 0) {
                      local_50 = &local_48;
                      local_48 = 9;
                      local_40 = 1;
                      local_58 = 2;
                      iVar9 = (**(code **)(lVar13 + 0x38))
                                        (lVar13,*(undefined4 *)(lVar12 + 0xa0),
                                         *(undefined4 *)(lVar16 + 8),0x410110,&local_58,0x10);
                      uVar20 = local_70;
                      if (iVar9 == 0) {
                        *(undefined4 *)(lVar16 + 0xc) = local_48._4_4_;
                        *(uint *)(lVar16 + 0x10) = local_40._4_4_ >> 1 & 1;
                        iVar9 = fabricvaspaceMapPhysMemdesc_IMPL
                                          (lVar12,local_68,0,local_70,puVar5[4],puVar5[1],0);
                        if (iVar9 == 0) {
                          iVar9 = fabricvaspaceVaToGpaMapInsert_IMPL
                                            (lVar12,*local_60,uVar20,puVar5[4]);
                          if (iVar9 == 0) goto LAB_0045d568;
                        }
                        else {
                          nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x344,
                                       "memoryfabricConstruct_IMPL",4,
                                       "NVRM: Failed to map FLA at the given physmem offset\n");
                        }
                      }
                      else {
                        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x328,
                                     "memoryfabricConstruct_IMPL",4,
                                     "NVRM: Failed to query physmem info\n");
                      }
                      iVar11 = (**(code **)(lVar13 + 0x18))
                                         (lVar13,*(undefined4 *)(lVar12 + 0xa0),
                                          *(undefined4 *)(lVar16 + 8));
                      if (iVar11 != 0) {
                        nvAssertFailedNoLog("pRmApi->Free(pRmApi, pFabricVAS->hClient, pMemdescData->hDupedPhysMem) == NV_OK"
                                            ,"src/kernel/mem_mgr/mem_fabric.c",0x360);
                      }
                    }
                    else {
                      nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x314,
                                   "memoryfabricConstruct_IMPL",4,
                                   "NVRM: Failed to dup physmem handle\n");
                    }
                    memdescRemoveDestroyCallback(local_68,puVar17);
                    portMemFree(puVar17);
                  }
                  portMemFree(lVar16);
                }
              }
              else {
                nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x2df,"memoryfabricConstruct_IMPL",4,
                             "NVRM: Error getting kind attr for fabric memory\n");
              }
              memDestructCommon_IMPL(lVar3);
            }
            else {
              nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x2d8,"memoryfabricConstruct_IMPL",4,
                           "NVRM: MemoryFabric memConstructCommon failed\n");
            }
            memdescDestroy(local_68);
            local_68 = (long *)0x0;
          }
          else {
            nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x2bf,"memoryfabricConstruct_IMPL",4,
                         "NVRM: Failed to allocate memory descriptor\n",uVar21);
          }
          if (*(char *)(lVar12 + 0xa8) == '\0') {
            fabricvaspaceBatchFree_IMPL(lVar12,local_60,local_78,1);
          }
          else {
            _memoryfabricFreeFabricVa_VGPU(lVar4,param_3);
          }
          portMemFree(local_60);
          return iVar9;
        }
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x289,"memoryfabricConstruct_IMPL",4,
                     "NVRM: Physmem can\'t be provided during flexible object alloc\n");
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x27e,"memoryfabricConstruct_IMPL",4,
                     "NVRM: RO mappings are only supported on non-release builds\n");
      }
      return 0x56;
    }
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x273,"memoryfabricConstruct_IMPL",4,
                 "NVRM: AllocSize should be pageSize aligned\n");
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x26a,"memoryfabricConstruct_IMPL",4,
                 "NVRM: Alignment should be pageSize aligned\n");
  }
  return 0x1f;
}


// ===== 0045dc80 memoryfabricDestruct_IMPL =====

void memoryfabricDestruct_IMPL(void)

{
  return;
}


// ===== 0045dc90 memoryfabricCanCopy_IMPL =====

undefined8 memoryfabricCanCopy_IMPL(void)

{
  return 1;
}


// ===== 0045dca0 memoryfabricCopyConstruct_IMPL =====

undefined8 memoryfabricCopyConstruct_IMPL(void)

{
  return 0;
}


// ===== 0045dcb0 memoryfabricControl_IMPL =====

undefined8 memoryfabricControl_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(short *)(param_3 + 10) == 0xf8) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = *(undefined8 *)(param_1 + 0x1f8);
    }
    uVar1 = resControl_IMPL(uVar1);
    return uVar1;
  }
  return 0x1f;
}


// ===== 0045dcd6 memoryfabricCtrlGetInfo_IMPL.cold =====

void memoryfabricCtrlGetInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045dce0 memoryfabricCtrlGetInfo_IMPL =====

undefined8 memoryfabricCtrlGetInfo_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  if (*(long *)(lVar1 + 0x118) != 0) {
    lVar3 = memdescGetMemData();
    *param_2 = *(undefined8 *)(*(long *)(lVar1 + 0x118) + 0x30);
    uVar4 = memdescGetPageSize(*(undefined8 *)(lVar1 + 0x118),1);
    param_2[1] = uVar4;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(lVar3 + 0x14);
    *(undefined8 *)((long)param_2 + 0x14) = *(undefined8 *)(lVar3 + 0xc);
    return 0;
  }
  return 0x1f;
}


// ===== 0045dd70 __pfx_memoryfabricCtrlCmdDescribe_IMPL =====

int __pfx_memoryfabricCtrlCmdDescribe_IMPL(long param_1,ulong *param_2)

{
  ulong uVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  
  lVar10 = 0;
  if (param_1 != 0) {
    lVar10 = *(long *)(param_1 + 0x210);
  }
  lVar6 = resservGetTlsCallContext();
  lVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_RmClient);
  if (lVar7 == 0) {
    iVar5 = 0x23;
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/mem_fabric.c",0x3e5);
  }
  else {
    iVar5 = 0x1b;
    cVar2 = rmclientIsCapableOrAdmin_IMPL(lVar7,4,*(undefined4 *)(lVar6 + 0x28));
    if (cVar2 != '\0') {
      if (*(long **)(lVar10 + 0x118) == (long *)0x0) {
        iVar5 = 0x1f;
      }
      else {
        lVar6 = **(long **)(lVar10 + 0x118);
        lVar7 = memdescGetMemData();
        *(undefined4 *)(param_2 + 0x10a) = *(undefined4 *)(lVar7 + 0x14);
        param_2[0x109] = *(ulong *)(lVar7 + 0xc);
        uVar8 = memdescGetPageSize(*(undefined8 *)(lVar10 + 0x118),1);
        param_2[0x104] = uVar8;
        uVar4 = memdescGetPteKindForGpu
                          (*(undefined8 **)(lVar10 + 0x118),**(undefined8 **)(lVar10 + 0x118));
        *(undefined4 *)(param_2 + 0x103) = uVar4;
        param_2[0x105] = *(ulong *)(*(long *)(lVar10 + 0x118) + 0x30);
        cVar2 = gpuFabricProbeIsSupported();
        if (cVar2 == '\0') {
          param_2[0x107] = 0;
          *(undefined2 *)(param_2 + 0x108) = 0;
          *(undefined4 *)(param_2 + 0x106) = 0;
        }
        else {
          iVar5 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(lVar6 + 0x4c0),param_2 + 0x106);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x401,"memoryfabricCtrlCmdDescribe_IMPL",
                         4,"NVRM: unable to query cliqueId 0x%x\n",iVar5);
            return iVar5;
          }
          uVar3 = 0;
          if (*(long *)(lVar6 + 0x1ce8) != 0) {
            uVar3 = (ushort)*(byte *)(*(long *)(lVar6 + 0x1ce8) + 0x16c0);
          }
          *(ushort *)(param_2 + 0x108) = uVar3;
          uVar8 = knvlinkGetBWModeEpoch_IMPL(lVar6,*(undefined8 *)(lVar6 + 0x1ce8));
          param_2[0x107] = uVar8;
        }
        uVar8 = memdescGetPageSize(*(undefined8 *)(lVar10 + 0x118),1);
        cVar2 = memdescGetContiguity(*(undefined8 *)(lVar10 + 0x118),1);
        uVar9 = 1;
        if (cVar2 == '\0') {
          uVar9 = *(ulong *)(*(long *)(lVar10 + 0x118) + 0x30) / uVar8;
        }
        uVar1 = *param_2;
        param_2[1] = uVar9;
        if (uVar1 < uVar9) {
          uVar9 = uVar9 - uVar1;
          if (0x200 < uVar9) {
            uVar9 = 0x200;
          }
          *(int *)(param_2 + 0x102) = (int)uVar9;
          lVar7 = portMemAllocNonPaged(uVar9 * 8);
          if (lVar7 == 0) {
            iVar5 = 0x51;
          }
          else {
            memdescGetPtePhysAddrsForGpu
                      (*(undefined8 *)(lVar10 + 0x118),lVar6,1,*param_2 * uVar8,uVar8,
                       (int)param_2[0x102],lVar7);
            uVar8 = param_2[0x102];
            if ((uint)uVar8 != 0) {
              uVar9 = 0;
              do {
                *(int *)((long)param_2 + uVar9 * 4 + 0x10) =
                     (int)(*(ulong *)(lVar7 + uVar9 * 8) >> 0x15);
                uVar9 = uVar9 + 1;
              } while ((uint)uVar8 != uVar9);
            }
            iVar5 = 0;
            portMemFree(lVar7);
          }
        }
        else {
          iVar5 = 0x5b;
          nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x419,"memoryfabricCtrlCmdDescribe_IMPL",4,
                       "NVRM: offset: 0x%llx is out of range: 0x%llx\n",uVar1,uVar9);
        }
      }
    }
  }
  return iVar5;
}


// ===== 0045dd80 memoryfabricCtrlCmdDescribe_IMPL =====

int memoryfabricCtrlCmdDescribe_IMPL(long param_1,ulong *param_2)

{
  ulong uVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  
  lVar10 = 0;
  if (param_1 != 0) {
    lVar10 = *(long *)(param_1 + 0x210);
  }
  lVar6 = resservGetTlsCallContext();
  lVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_RmClient);
  if (lVar7 == 0) {
    iVar5 = 0x23;
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/mem_fabric.c",0x3e5);
  }
  else {
    iVar5 = 0x1b;
    cVar2 = rmclientIsCapableOrAdmin_IMPL(lVar7,4,*(undefined4 *)(lVar6 + 0x28));
    if (cVar2 != '\0') {
      if (*(long **)(lVar10 + 0x118) == (long *)0x0) {
        iVar5 = 0x1f;
      }
      else {
        lVar6 = **(long **)(lVar10 + 0x118);
        lVar7 = memdescGetMemData();
        *(undefined4 *)(param_2 + 0x10a) = *(undefined4 *)(lVar7 + 0x14);
        param_2[0x109] = *(ulong *)(lVar7 + 0xc);
        uVar8 = memdescGetPageSize(*(undefined8 *)(lVar10 + 0x118),1);
        param_2[0x104] = uVar8;
        uVar4 = memdescGetPteKindForGpu
                          (*(undefined8 **)(lVar10 + 0x118),**(undefined8 **)(lVar10 + 0x118));
        *(undefined4 *)(param_2 + 0x103) = uVar4;
        param_2[0x105] = *(ulong *)(*(long *)(lVar10 + 0x118) + 0x30);
        cVar2 = gpuFabricProbeIsSupported();
        if (cVar2 == '\0') {
          param_2[0x107] = 0;
          *(undefined2 *)(param_2 + 0x108) = 0;
          *(undefined4 *)(param_2 + 0x106) = 0;
        }
        else {
          iVar5 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(lVar6 + 0x4c0),param_2 + 0x106);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x401,"memoryfabricCtrlCmdDescribe_IMPL",
                         4,"NVRM: unable to query cliqueId 0x%x\n",iVar5);
            return iVar5;
          }
          uVar3 = 0;
          if (*(long *)(lVar6 + 0x1ce8) != 0) {
            uVar3 = (ushort)*(byte *)(*(long *)(lVar6 + 0x1ce8) + 0x16c0);
          }
          *(ushort *)(param_2 + 0x108) = uVar3;
          uVar8 = knvlinkGetBWModeEpoch_IMPL(lVar6,*(undefined8 *)(lVar6 + 0x1ce8));
          param_2[0x107] = uVar8;
        }
        uVar8 = memdescGetPageSize(*(undefined8 *)(lVar10 + 0x118),1);
        cVar2 = memdescGetContiguity(*(undefined8 *)(lVar10 + 0x118),1);
        uVar9 = 1;
        if (cVar2 == '\0') {
          uVar9 = *(ulong *)(*(long *)(lVar10 + 0x118) + 0x30) / uVar8;
        }
        uVar1 = *param_2;
        param_2[1] = uVar9;
        if (uVar1 < uVar9) {
          uVar9 = uVar9 - uVar1;
          if (0x200 < uVar9) {
            uVar9 = 0x200;
          }
          *(int *)(param_2 + 0x102) = (int)uVar9;
          lVar7 = portMemAllocNonPaged(uVar9 * 8);
          if (lVar7 == 0) {
            iVar5 = 0x51;
          }
          else {
            memdescGetPtePhysAddrsForGpu
                      (*(undefined8 *)(lVar10 + 0x118),lVar6,1,*param_2 * uVar8,uVar8,
                       (int)param_2[0x102],lVar7);
            uVar8 = param_2[0x102];
            if ((uint)uVar8 != 0) {
              uVar9 = 0;
              do {
                *(int *)((long)param_2 + uVar9 * 4 + 0x10) =
                     (int)(*(ulong *)(lVar7 + uVar9 * 8) >> 0x15);
                uVar9 = uVar9 + 1;
              } while ((uint)uVar8 != uVar9);
            }
            iVar5 = 0;
            portMemFree(lVar7);
          }
        }
        else {
          iVar5 = 0x5b;
          nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x419,"memoryfabricCtrlCmdDescribe_IMPL",4,
                       "NVRM: offset: 0x%llx is out of range: 0x%llx\n",uVar1,uVar9);
        }
      }
    }
  }
  return iVar5;
}


// ===== 0045e0b2 memoryfabricCtrlAttachMem_IMPL.cold =====

void memoryfabricCtrlAttachMem_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045e0d0 memoryfabricCtrlAttachMem_IMPL =====

int memoryfabricCtrlAttachMem_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined8 uVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  long lVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined8 local_50;
  long local_48;
  long local_40 [2];
  
  *(undefined2 *)(param_2 + 0x202) = 0;
  if ((param_2[0x201] == 0) && ((ushort)(*(short *)(param_2 + 0x200) - 1U) < 0x40)) {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)invalidInstructionException();
      (*pcVar6)();
    }
    uVar13 = 0;
    puVar12 = param_2;
    do {
      lVar2 = *(long *)(param_1 + 0x210);
      lVar3 = *(long *)(lVar2 + 0xf0);
      uVar4 = *(undefined8 *)(lVar2 + 0x118);
      uVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar3 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
      uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x1f8) + 0x48);
      lVar11 = memdescGetMemData(uVar4);
      if ((*(byte *)(lVar11 + 0x14) & 1) == 0) {
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0xd4,"_memoryFabricAttachMem",4,
                     "NVRM: Unsupported fabric memory type\n");
        return 0x56;
      }
      iVar8 = _memoryfabricValidatePhysMem
                        (**(undefined8 **)(*(long *)(lVar2 + 0xb8) + 0x48),*puVar12,lVar3,&local_50,
                         local_40,0);
      if (iVar8 != 0) {
        nvCheckOkFailedNoLog(4,iVar8,"status","src/kernel/mem_mgr/mem_fabric.c",0xdb);
        return iVar8;
      }
      iVar8 = refCreateInterMapping(uVar5,&local_48);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,"refCreateInterMapping(pMemoryFabricRef, &pInterMapping)",
                   "src/kernel/mem_mgr/mem_fabric.c",0xdd);
        return iVar8;
      }
      *(undefined8 *)(local_48 + 0x70) = 0;
      if (local_40[0] == 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)invalidInstructionException();
        (*pcVar6)();
      }
      iVar8 = refAddInterMapping(uVar5,*(undefined8 *)(*(long *)(local_40[0] + 0xb8) + 0x48),
                                 *(undefined8 *)(puVar12 + 2),
                                 *(undefined8 *)
                                  (*(long *)(*(long *)(param_1 + 0x1f8) + 0x48) + 0x18));
      uVar7 = local_50;
      if (iVar8 != 0) {
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0xe9,"_memoryFabricAttachMem",4,
                     "NVRM: Failed to setup inter mapping\n");
        refDestroyInterMapping(uVar5,local_48);
        return iVar8;
      }
      iVar8 = fabricvaspaceMapPhysMemdesc_IMPL
                        (uVar10,uVar4,*(undefined8 *)(puVar12 + 2),local_50,
                         *(undefined8 *)(puVar12 + 4));
      if (iVar8 != 0) {
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0xf7,"_memoryFabricAttachMem",4,
                     "NVRM: Failed to map FLA\n");
        goto LAB_0045e3b1;
      }
      puVar9 = (undefined8 *)portMemAllocNonPaged(0x58);
      if (puVar9 == (undefined8 *)0x0) {
        iVar8 = 0x51;
LAB_0045e3e6:
        fabricvaspaceUnmapPhysMemdesc_IMPL
                  (uVar10,uVar4,*(undefined8 *)(param_2 + (ulong)uVar13 * 8 + 2),
                   *(undefined8 *)(param_2 + (ulong)uVar13 * 8 + 6));
LAB_0045e3b1:
        refRemoveInterMapping(uVar5,local_48,0);
        refDestroyInterMapping(uVar5,local_48);
        return iVar8;
      }
      portMemSet(puVar9,0,0x58);
      uVar1 = *(undefined8 *)(puVar12 + 2);
      puVar9[5] = uVar1;
      puVar9[6] = uVar1;
      puVar9[2] = *(undefined8 *)(puVar12 + 4);
      uVar1 = *(undefined8 *)(puVar12 + 6);
      *puVar9 = uVar7;
      puVar9[3] = uVar1;
      puVar9[4] = puVar9;
      puVar9[1] = local_48;
      *(undefined8 *)(local_48 + 0x78) = uVar7;
      iVar8 = btreeInsert(puVar9 + 4,lVar11);
      if (iVar8 != 0) {
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric.c",0x111,"_memoryFabricAttachMem",4,
                     "NVRM: Failed to track attach mem info\n");
        portMemFree(puVar9);
        goto LAB_0045e3e6;
      }
      uVar13 = uVar13 + 1;
      puVar12 = puVar12 + 8;
      *(short *)(param_2 + 0x202) = *(short *)(param_2 + 0x202) + 1;
    } while (uVar13 < *(ushort *)(param_2 + 0x200));
    iVar8 = 0;
  }
  else {
    iVar8 = 0x1f;
  }
  return iVar8;
}


// ===== 0045e4e0 memoryfabricCtrlDetachMem_IMPL =====

undefined8 memoryfabricCtrlDetachMem_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  *(undefined2 *)(param_2 + 0x208) = 0;
  if ((*(int *)(param_2 + 0x204) == 0) && ((ushort)(*(short *)(param_2 + 0x200) - 1U) < 0x40)) {
    lVar2 = 0;
    do {
      uVar1 = _memoryFabricDetachMem(param_1,*(undefined8 *)(param_2 + lVar2 * 8),1);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      lVar2 = lVar2 + 1;
      *(short *)(param_2 + 0x208) = *(short *)(param_2 + 0x208) + 1;
    } while ((uint)lVar2 < (uint)*(ushort *)(param_2 + 0x200));
    return uVar1;
  }
  return 0x1f;
}


// ===== 0045e566 memoryfabricCtrlGetNumAttachedMem_IMPL.cold =====

void memoryfabricCtrlGetNumAttachedMem_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045e570 memoryfabricCtrlGetNumAttachedMem_IMPL =====

undefined8 memoryfabricCtrlGetNumAttachedMem_IMPL(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  long local_20;
  
  if (param_1 != 0) {
    puVar2 = (undefined8 *)memdescGetMemData(*(undefined8 *)(*(long *)(param_1 + 0x210) + 0x118));
    local_20 = 0;
    *(undefined2 *)(param_2 + 2) = 0;
    btreeEnumStart(*param_2,&local_20,*puVar2);
    while ((local_20 != 0 && (*(ulong *)(local_20 + 8) <= (ulong)param_2[1]))) {
      *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 1;
      btreeEnumNext(&local_20,*puVar2);
    }
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045e600 memoryfabricCtrlGetPageLevelInfo_IMPL.cold =====

void memoryfabricCtrlGetPageLevelInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045e610 memoryfabricCtrlGetPageLevelInfo_IMPL =====

int memoryfabricCtrlGetPageLevelInfo_IMPL(long param_1,ulong *param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  undefined1 *puVar10;
  ulong *puVar11;
  long local_310;
  undefined8 *local_308;
  undefined1 local_300 [8];
  undefined8 *local_2f8;
  ulong local_2f0;
  int local_2e0;
  undefined1 local_2d8 [680];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  lVar2 = *(long *)(lVar1 + 0xf0);
  uVar5 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 0x4a18));
  memset(local_300,0,0x2c8);
  lVar1 = *(long *)(lVar1 + 0x118);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pFabricMemDesc != NULL","src/kernel/mem_mgr/mem_fabric.c",0x4cf);
  }
  else {
    uVar7 = *param_2;
    local_308 = (undefined8 *)0x0;
    iVar4 = fabricvaspaceGetGpaMemdesc_IMPL(uVar5,lVar1,lVar2,&local_310);
    if (iVar4 == 0) {
      uVar7 = memdescGetPageSize(local_310,1);
      if (lVar1 != local_310) {
        fabricvaspacePutGpaMemdesc_IMPL(uVar5);
      }
    }
    else {
      if (iVar4 != 0x57) {
LAB_0045e6b7:
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "_memoryfabricGetPhysAttrsUsingFabricMemdesc(pGpu, pFabricVAS, pFabricMemDesc, pParams->offset, &physPageSize)"
                   ,"src/kernel/mem_mgr/mem_fabric.c",0x4d1);
        return iVar4;
      }
      puVar6 = (undefined8 *)memdescGetMemData(lVar1);
      iVar4 = btreeSearch(uVar7,&local_308,*puVar6);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,"btreeSearch(offset, &pNode, pMemdescData->pAttachMemInfoTree)",
                   "src/kernel/mem_mgr/mem_fabric.c",0x4b4);
        goto LAB_0045e6b7;
      }
      uVar7 = memdescGetPageSize(*(undefined8 *)*local_308,1);
    }
    uVar8 = memdescGetPageSize(lVar1,1);
    if (uVar8 <= uVar7) {
      uVar7 = memdescGetPageSize(lVar1,1);
    }
    uVar8 = *param_2;
    if ((uVar7 - 1 & uVar8) == 0) {
      if (uVar8 < *(ulong *)(lVar1 + 0x30)) {
        memdescGetPtePhysAddrsForGpu(lVar1,lVar2,1,uVar8,uVar7,1,&local_308);
        local_2f8 = local_308;
        local_2f0 = uVar7;
        iVar4 = fabricvaspaceGetPageLevelInfo_IMPL(uVar5,lVar2,local_300);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,"fabricvaspaceGetPageLevelInfo(pFabricVAS, pGpu, &pageLevelInfoParams)",
                     "src/kernel/mem_mgr/mem_fabric.c",0x4e7);
          return iVar4;
        }
        *(int *)(param_2 + 1) = local_2e0;
        if (local_2e0 == 0) {
          return 0;
        }
        puVar11 = param_2 + 2;
        puVar10 = local_2d8;
        uVar9 = 0;
        do {
          portMemCopy(puVar11,0x70,puVar10,0x70);
          uVar9 = uVar9 + 1;
          puVar11 = puVar11 + 0xe;
          puVar10 = puVar10 + 0x70;
        } while (uVar9 < (uint)param_2[1]);
        return 0;
      }
      nvCheckFailedNoLog(4,"pParams->offset < memdescGetSize(pFabricMemDesc)",
                         "src/kernel/mem_mgr/mem_fabric.c",0x4dd);
    }
    else {
      nvCheckFailedNoLog(4,"NV_IS_ALIGNED64(pParams->offset, mappingPageSize)",
                         "src/kernel/mem_mgr/mem_fabric.c",0x4d9);
    }
  }
  return 0x1f;
}


// ===== 0045e920 memoryfabricUnmapFrom_IMPL =====

ulong memoryfabricUnmapFrom_IMPL(undefined8 param_1,long *param_2)

{
  char cVar1;
  ulong uVar2;
  int local_1c;
  
  local_1c = 1 << ((byte)*(undefined4 *)(*param_2 + 0x7a4) & 0x1f);
  cVar1 = rmGpuGroupLockIsOwner(0,2,&local_1c);
  if (cVar1 != '\0') {
    uVar2 = _memoryFabricDetachMem(param_1,param_2[3],0);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "_memoryFabricDetachMem(pMemoryFabric, pParams->dmaOffset, NV_FALSE)",
                 "src/kernel/mem_mgr/mem_fabric.c",0x502);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertFailedNoLog("rmGpuGroupLockIsOwner(0, GPU_LOCK_GRP_MASK, &gpuMask)",
                      "src/kernel/mem_mgr/mem_fabric.c",0x4ff);
  return 0x40;
}


// ===== 0045e9e0 _memoryfabricImportMemDescDestroyCallback =====

void _memoryfabricImportMemDescDestroyCallback(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  
  lVar1 = memdescGetMemData(param_3);
  if (lVar1 != 0) {
    portMemFree(*(undefined8 *)(param_3 + 0x40));
    *(undefined8 *)(param_3 + 0x40) = 0;
  }
  portMemFree(param_2);
  return;
}


// ===== 0045ea20 memoryfabricimportedrefConstruct_IMPL =====

undefined8 memoryfabricimportedrefConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = *(long *)(param_3 + 0x40);
  lVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_3 + 0x20),__nvoc_class_def_RmClient);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/mem_fabric_import_ref.c",0x39);
    return 0x23;
  }
  cVar1 = rmclientIsCapable_IMPL(lVar2,4);
  if ((cVar1 == '\0') && (cVar1 = rmclientIsCapable_IMPL(lVar2,0x200), cVar1 == '\0')) {
    return 0x1b;
  }
  if (*(int *)(lVar3 + 0x14) == 0) {
    lVar3 = importDescriptorGetUnused
                      (lVar3,*(undefined2 *)(lVar3 + 0x10),*(undefined8 *)(lVar3 + 0x18));
    *(long *)(param_1 + 0xe8) = lVar3;
    uVar4 = 0;
    if (lVar3 == 0) {
      uVar4 = 0x10006;
    }
    return uVar4;
  }
  return 0x1f;
}


// ===== 0045eb10 memoryfabricimportedrefDestruct_IMPL =====

void memoryfabricimportedrefDestruct_IMPL(long param_1)

{
  memdescDestroy(*(undefined8 *)(param_1 + 0xe0));
  importDescriptorPutNonBlocking(*(undefined8 *)(param_1 + 0xe8));
  return;
}


// ===== 0045eb40 memoryfabricimportedrefCanCopy_IMPL =====

undefined8 memoryfabricimportedrefCanCopy_IMPL(void)

{
  return 0;
}


// ===== 0045eb50 _createTempMemDesc =====

long _createTempMemDesc(undefined4 *param_1,undefined8 *param_2,undefined4 param_3,
                       undefined1 param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long local_30;
  
  iVar2 = memdescCreate(&local_30,0,*(undefined8 *)(param_1 + 4),0,param_4,6,1);
  if (iVar2 == 0) {
    memdescSetPageSize(local_30,1,*(undefined8 *)(param_1 + 2),0);
    *(undefined4 *)(local_30 + 0x84) = *param_1;
    memdescSetFlag(local_30,2,1);
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x20);
    if (puVar3 != (undefined8 *)0x0) {
      portMemSet(puVar3,0,0x20);
      uVar1 = *param_2;
      *(undefined4 *)(puVar3 + 1) = param_3;
      *puVar3 = uVar1;
      *(undefined4 *)((long)puVar3 + 0xc) = param_1[6];
      *(undefined2 *)(puVar3 + 3) = *(undefined2 *)(param_1 + 10);
      puVar3[2] = *(undefined8 *)(param_1 + 8);
      memdescSetMemData(local_30,puVar3,0);
      puVar4 = (undefined8 *)portMemAllocNonPaged(0x18);
      if (puVar4 != (undefined8 *)0x0) {
        portMemSet(puVar4,0,0x18);
        *puVar4 = _memoryfabricImportMemDescDestroyCallback;
        puVar4[1] = puVar4;
        memdescAddDestroyCallback(local_30,puVar4);
        return local_30;
      }
      portMemFree(puVar3);
    }
    memdescDestroy(local_30);
  }
  return 0;
}


// ===== 0045ecc0 memoryfabricimportedrefCtrlValidate_IMPL =====

uint memoryfabricimportedrefCtrlValidate_IMPL(long param_1,long param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  bool bVar7;
  
  uVar1 = *(uint *)(param_2 + 0x850);
  lVar4 = *(long *)(param_1 + 0xe0);
  *(undefined1 *)(param_2 + 0x854) = 0;
  if ((uVar1 & 1) != 0) {
    puVar2 = (undefined8 *)0x0;
    uVar1 = importDescriptorInstallMemDesc(*(undefined8 *)(param_1 + 0xe8),0);
LAB_0045eed8:
    portMemFree(puVar2);
    return uVar1;
  }
  uVar5 = *(ulong *)(param_2 + 0x40);
  if (((uVar5 != 0) && (*(ulong *)(param_1 + 0xd8) < uVar5)) &&
     (uVar6 = (ulong)*(uint *)(param_2 + 0x848), *(uint *)(param_2 + 0x848) < 0x201)) {
    if ((uVar5 < uVar6 + *(ulong *)(param_2 + 0x38)) || (CARRY8(uVar6,*(ulong *)(param_2 + 0x38))))
    {
      return 0x5b;
    }
    lVar3 = *(long *)(param_2 + 8);
    if (((lVar3 == 0x200000 || lVar3 == 0x20000000) || (lVar3 == 0x4000000000)) &&
       ((*(ulong *)(param_2 + 0x10) != 0 && ((lVar3 - 1U & *(ulong *)(param_2 + 0x10)) == 0)))) {
      puVar2 = (undefined8 *)portMemAllocNonPaged(uVar6 << 3);
      if (puVar2 == (undefined8 *)0x0) {
        return 0x51;
      }
      if (*(int *)(param_2 + 0x848) != 0) {
        uVar5 = 0;
        do {
          puVar2[uVar5] = (ulong)*(uint *)(param_2 + 0x48 + uVar5 * 4) << 0x15;
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_2 + 0x848));
      }
      if (lVar4 == 0) {
        lVar4 = _createTempMemDesc(param_2,param_2 + 0x30,*(undefined4 *)(param_2 + 0x84c),
                                   *(long *)(param_2 + 0x40) == 1);
        if (lVar4 == 0) {
          uVar1 = 0x51;
          goto LAB_0045eed8;
        }
        *(long *)(param_1 + 0xe0) = lVar4;
      }
      uVar1 = uVar1 & 1;
      if (*(long *)(param_2 + 0x40) == 1) {
        memdescSetPte(lVar4,1,0,*puVar2);
      }
      else {
        memdescFillPages(lVar4,*(undefined4 *)(param_2 + 0x38),puVar2,
                         *(undefined4 *)(param_2 + 0x848),*(undefined8 *)(param_2 + 8));
      }
      lVar3 = (ulong)*(uint *)(param_2 + 0x848) + *(long *)(param_1 + 0xd8);
      *(long *)(param_1 + 0xd8) = lVar3;
      bVar7 = lVar3 == *(long *)(param_2 + 0x40);
      *(bool *)(param_2 + 0x854) = bVar7;
      if ((bVar7) &&
         (uVar1 = importDescriptorInstallMemDesc(*(undefined8 *)(param_1 + 0xe8),lVar4), uVar1 == 0)
         ) {
        *(undefined8 *)(param_1 + 0xe0) = 0;
      }
      goto LAB_0045eed8;
    }
  }
  return 0x1f;
}


// ===== 0045efa0 _importDescriptorDequeueWait =====

void _importDescriptorDequeueWait(long param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  
  param_1 = param_1 + 8;
  plVar2 = (long *)listHead_IMPL(param_1);
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return;
    }
    if (plVar2[1] == param_2) break;
    plVar2 = (long *)listNext_IMPL(param_1,plVar2);
  }
  if ((*plVar2 != 0) && (iVar1 = osDereferenceObjectCount(), iVar1 != 0)) {
    nvAssertOkFailedNoLog
              (iVar1,"osDereferenceObjectCount(pNode->pOsEvent)",
               "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x1b2);
  }
  listRemove_IMPL(param_1,plVar2);
  return;
}


// ===== 0045f040 _importDescriptorFlushImporters.part.0 =====

void _importDescriptorFlushImporters_part_0(long param_1)

{
  int iVar1;
  long *plVar2;
  
  while( true ) {
    plVar2 = (long *)listHead_IMPL(param_1 + 8);
    if (plVar2 == (long *)0x0) break;
    if (*(long *)(param_1 + 0x70) != 0) {
      iVar1 = memConstructCommon_IMPL(plVar2[1],0xf9,0,*(long *)(param_1 + 0x70),0,0,0,0,0,0,0,0);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,
                   "memConstructCommon(pNode->pMemory, NV_MEMORY_FABRIC_IMPORT_V2, 0, pFabricImportDesc->pMemDesc, 0, NULL, 0, 0, 0, 0, NVOS32_MEM_TAG_NONE, NULL)"
                   ,"src/kernel/mem_mgr/mem_fabric_import_v2.c",0x16e);
      }
    }
    if (*plVar2 != 0) {
      osSetEvent(0);
      iVar1 = osDereferenceObjectCount(*plVar2);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,"osDereferenceObjectCount(pNode->pOsEvent)",
                   "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x178);
      }
    }
    listRemove_IMPL(param_1 + 8,plVar2);
  }
  return;
}


// ===== 0045f110 _importDescriptorEnqueueWait =====

int _importDescriptorEnqueueWait(undefined8 param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  long *plVar2;
  long local_20;
  
  local_20 = 0;
  if (param_3 != 0) {
    iVar1 = osUserHandleToKernelPtr(param_1,param_3,&local_20);
    if (iVar1 != 0) goto LAB_0045f17f;
  }
  plVar2 = (long *)listAppendNew_IMPL(param_2 + 8);
  if (plVar2 != (long *)0x0) {
    *plVar2 = local_20;
    plVar2[1] = param_4;
    if (*(char *)(param_2 + 0x68) != '\0') {
      _importDescriptorFlushImporters_part_0(param_2);
    }
    return 0;
  }
  if (local_20 != 0) {
    osDereferenceObjectCount();
  }
  iVar1 = 0x51;
LAB_0045f17f:
  _importDescriptorDequeueWait(param_2,param_4);
  return iVar1;
}


// ===== 0045f1a0 _importDescriptorPutAndLockReleaseWrite =====

void _importDescriptorPutAndLockReleaseWrite(long *param_1,char param_2)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined1 local_70 [8];
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  undefined2 local_50;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  uVar1 = *(undefined8 *)(g_pSys + 0x260);
  lVar4 = *param_1 + -1;
  *param_1 = lVar4;
  if (((char)param_1[0xf] == '\0') && (lVar4 == param_1[6])) {
    if ((param_2 != '\0') && (((char)param_1[0xd] == '\0' || (param_1[0xe] != 0)))) {
      lVar2 = param_1[8];
      local_70[0] = 1;
      lVar4 = param_1[7];
      local_60 = *(undefined4 *)((long)param_1 + 0x7c);
      local_68 = fabricGenerateEventId_IMPL(*(undefined8 *)(g_pSys + 0x260));
      local_58 = lVar4;
      local_50 = (short)lVar2;
      iVar3 = fabricPostEventsV2_IMPL(uVar1,local_70,1);
      if (iVar3 != 0) {
        nvCheckFailedNoLog(3,"fabricPostEventsV2(pFabric, &unimportEvent, 1) == NV_OK",
                           "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x105);
      }
    }
    fabricImportCacheDelete_IMPL(uVar1,param_1 + 0xb,param_1[10]);
    lVar4 = *param_1;
    *(undefined1 *)(param_1 + 0xf) = 1;
    lVar2 = param_1[0x10];
  }
  else {
    lVar2 = param_1[0x10];
  }
  if (lVar4 == 0) {
    portSyncRwLockReleaseWrite(lVar2);
    iVar3 = listCount_IMPL(param_1 + 1);
    if (iVar3 != 0) {
      nvAssertFailedNoLog("listCount(&pFabricImportDesc->waitingImportersList) == 0",
                          "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x118);
    }
    if (param_1[6] != 0) {
      nvAssertFailedNoLog("pFabricImportDesc->extUsageCount == 0",
                          "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x119);
    }
    if (param_1[0x10] != 0) {
      portSyncRwLockDestroy();
    }
    listDestroy_IMPL(param_1 + 1);
    memdescDestroy(param_1[0xe]);
    param_1[0xe] = 0;
    portMemFree(param_1);
    return;
  }
  portSyncRwLockReleaseWrite(lVar2);
  return;
}


// ===== 0045f360 importDescriptorGetUnused =====

long * importDescriptorGetUnused(undefined8 param_1,ulong param_2,long param_3)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  
  lVar1 = *(long *)(g_pSys + 0x260);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x48));
  plVar2 = (long *)fabricImportCacheGet_IMPL
                             (*(undefined8 *)(g_pSys + 0x260),param_1,
                              param_3 << 0x10 | param_2 & 0xffff);
  plVar3 = plVar2;
  if (plVar2 != (long *)0x0) {
    portSyncRwLockAcquireWrite(plVar2[0x10]);
    *plVar2 = *plVar2 + 1;
    if (((char)plVar2[0xd] == '\0') && (plVar2[6] == 0)) {
      plVar2[6] = 1;
      portSyncRwLockReleaseWrite(plVar2[0x10]);
    }
    else {
      plVar3 = (long *)0x0;
      _importDescriptorPutAndLockReleaseWrite(plVar2,0);
    }
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x48));
  return plVar3;
}


// ===== 0045f410 importDescriptorPutNonBlocking =====

void importDescriptorPutNonBlocking(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(g_pSys + 0x260);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x48));
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x80));
  lVar2 = *(long *)(param_1 + 0x30);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pFabricImportDesc->extUsageCount > 0",
                        "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x152);
    lVar2 = *(long *)(param_1 + 0x30);
  }
  *(long *)(param_1 + 0x30) = lVar2 + -1;
  _importDescriptorPutAndLockReleaseWrite(param_1,0);
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x48));
  return;
}


// ===== 0045f490 importDescriptorInstallMemDesc =====

undefined4 importDescriptorInstallMemDesc(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x80));
    uVar1 = 0x17;
    if (*(char *)(param_1 + 0x68) == '\0') {
      *(undefined8 *)(param_1 + 0x70) = param_2;
      *(undefined1 *)(param_1 + 0x68) = 1;
      _importDescriptorFlushImporters_part_0(param_1);
      uVar1 = 0;
    }
    portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x80));
    return uVar1;
  }
  return 0x1f;
}


// ===== 0045f500 memoryfabricimportv2Destruct_IMPL =====

void memoryfabricimportv2Destruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar1 = *(long *)(g_pSys + 0x260);
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x210);
  }
  lVar2 = *(long *)(param_1 + 0x228);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x48));
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x80));
  memDestructCommon_IMPL(uVar3);
  _importDescriptorDequeueWait(lVar2,uVar3);
  _importDescriptorPutAndLockReleaseWrite(lVar2,1);
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x48));
  return;
}


// ===== 0045f580 memoryfabricimportv2CanCopy_IMPL =====

undefined8 memoryfabricimportv2CanCopy_IMPL(void)

{
  return 1;
}


// ===== 0045f590 memoryfabricimportv2IsReady_IMPL =====

byte memoryfabricimportv2IsReady_IMPL(long param_1)

{
  long lVar1;
  byte bVar2;
  short sVar3;
  
  lVar1 = *(long *)(param_1 + 0x228);
  sVar3 = fabricGetNodeId_IMPL(*(undefined8 *)(g_pSys + 0x260));
  if (sVar3 != -1) {
    portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x80));
    bVar2 = 0x55;
    if (*(char *)(lVar1 + 0x68) != '\0') {
      bVar2 = -(*(long *)(lVar1 + 0x70) == 0) & 0x31;
    }
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x80));
    return bVar2;
  }
  return 0x40;
}


// ===== 0045f610 memoryfabricimportv2CopyConstruct_IMPL =====

int memoryfabricimportv2CopyConstruct_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x210);
  }
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x16) + 8),
                             __nvoc_class_def_MemoryFabricImportV2);
  plVar1 = *(long **)(lVar3 + 0x228);
  portSyncRwLockAcquireWrite(plVar1[0x10]);
  iVar2 = _importDescriptorEnqueueWait(*param_3,plVar1,0,uVar4);
  if (iVar2 == 0) {
    *plVar1 = *plVar1 + 1;
    *(long **)(param_1 + 0x228) = plVar1;
    *(short *)(param_1 + 0x220) = (short)plVar1[8];
  }
  portSyncRwLockReleaseWrite(plVar1[0x10]);
  return iVar2;
}


// ===== 0045f6a4 memoryfabricimportv2Construct_IMPL.cold =====

void memoryfabricimportv2Construct_IMPL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  long unaff_R12;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
  memoryExportGetNodeId(unaff_R12 + 4);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0045f6d0 memoryfabricimportv2Construct_IMPL =====

ulong memoryfabricimportv2Construct_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  code *pcVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  ulong *puVar13;
  undefined8 uVar14;
  ulong uVar15;
  undefined1 local_98;
  undefined7 uStack_97;
  ulong local_90;
  int local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined1 local_74 [68];
  
  if (*(long *)(param_3 + 0x16) != 0) {
    uVar11 = memoryfabricimportv2CopyConstruct_IMPL();
    return uVar11;
  }
  lVar3 = *(long *)(g_pSys + 0x260);
  lVar4 = *(long *)(param_3 + 0x10);
  if (param_1 == 0) {
    memoryExportGetNodeId(lVar4 + 4);
                    /* WARNING: Does not return */
    pcVar7 = (code *)invalidInstructionException();
    (*pcVar7)();
  }
  uVar5 = *(undefined8 *)(param_1 + 0x210);
  sVar8 = memoryExportGetNodeId(lVar4 + 4);
  lVar12 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),
                              __nvoc_class_def_RmClient);
  iVar10 = *(int *)(lVar12 + 600);
  if (iVar10 == -1) {
    return 0x1b;
  }
  if (sVar8 == -1) {
    return 0x56;
  }
  uVar11 = *(ulong *)(lVar4 + 0x38);
  if (0xfffffffffffe < uVar11) {
    return 0x1f;
  }
  uVar1 = *(ushort *)(lVar4 + 0x24);
  lVar6 = *(long *)(g_pSys + 0x260);
  portMemCopy(&local_98,0x10,lVar4 + 4,0x10);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar6 + 0x48));
  uVar15 = uVar11 << 0x10 | (ulong)uVar1;
  puVar13 = (ulong *)fabricImportCacheGet_IMPL(*(undefined8 *)(g_pSys + 0x260),&local_98);
  if (puVar13 == (ulong *)0x0) {
    puVar13 = (ulong *)portMemAllocNonPaged(0x88);
    if (puVar13 == (ulong *)0x0) goto LAB_0045fb1b;
    portMemSet(puVar13,0,0x88);
    *(uint *)(puVar13 + 8) = CONCAT22(uVar1,sVar8);
    *puVar13 = 1;
    puVar13[9] = uVar11;
    puVar13[0xb] = CONCAT71(uStack_97,local_98);
    puVar13[0xc] = local_90;
    puVar13[10] = uVar15;
    *(int *)((long)puVar13 + 0x7c) = iVar10;
    uVar14 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(puVar13 + 1,uVar14,0x10);
    uVar14 = portMemAllocatorGetGlobalNonPaged();
    uVar11 = portSyncRwLockCreate(uVar14);
    puVar13[0x10] = uVar11;
    if (uVar11 != 0) {
      iVar10 = fabricImportCacheInsert_IMPL(lVar6,puVar13 + 0xb,uVar15,puVar13);
      if (iVar10 == 0) {
        portSyncRwLockAcquireWrite();
        goto LAB_0045f83e;
      }
      if (puVar13[0x10] != 0) {
        portSyncRwLockDestroy();
      }
    }
    listDestroy_IMPL(puVar13 + 1);
    memdescDestroy(puVar13[0xe]);
    puVar13[0xe] = 0;
    portMemFree(puVar13);
LAB_0045fb1b:
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar6 + 0x48));
    return 0x51;
  }
  portSyncRwLockAcquireWrite(puVar13[0x10]);
  *puVar13 = *puVar13 + 1;
LAB_0045f83e:
  *(ulong **)(param_1 + 0x228) = puVar13;
  *(short *)(param_1 + 0x220) = sVar8;
  uVar9 = _importDescriptorEnqueueWait(*param_3,puVar13,*(undefined8 *)(lVar4 + 0x30),uVar5);
  if (uVar9 == 0) {
    if (*(int *)((long)puVar13 + 0x7c) == *(int *)(lVar12 + 600)) {
      if (*puVar13 < 2) {
        uVar14 = *(undefined8 *)(lVar4 + 0x38);
        uVar2 = *(undefined2 *)(lVar4 + 0x24);
        local_98 = 0;
        local_88 = *(int *)(lVar12 + 600);
        local_90 = fabricGenerateEventId_IMPL(*(undefined8 *)(g_pSys + 0x260));
        local_80 = uVar14;
        local_78 = CONCAT22(sVar8,uVar2);
        portMemCopy(local_74,0x10,puVar13 + 0xb,0x10);
        puVar13[7] = local_90;
        uVar9 = fabricPostEventsV2_IMPL(lVar3,&local_98,1);
        if (uVar9 != 0) {
          nvDbg_Printf("src/kernel/mem_mgr/mem_fabric_import_v2.c",0x293,
                       "_memoryfabricimportv2Construct",4,
                       "NVRM: Failed to notify IMEX daemon of import event\n");
          goto LAB_0045f9c6;
        }
      }
      portSyncRwLockReleaseWrite(puVar13[0x10]);
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar3 + 0x48));
      return 0;
    }
    uVar9 = 0x1b;
  }
LAB_0045f9c6:
  _importDescriptorDequeueWait(puVar13,uVar5);
  _importDescriptorPutAndLockReleaseWrite(puVar13,0);
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar3 + 0x48));
  *(undefined8 *)(param_1 + 0x228) = 0;
  return (ulong)uVar9;
}


// ===== 0045fb60 memoryfabricimportv2Control_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memoryfabricimportv2Control_IMPL(long *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x2a0))(param_1,0);
  if (uVar1 == 0) {
    uVar2 = resControl_IMPL(param_1[0x3f],param_2,param_3);
    return uVar2;
  }
  nvCheckOkFailedNoLog
            (1,uVar1,"memoryfabricimportv2IsReady(pMemoryFabricImportV2, NV_FALSE)",
             "src/kernel/mem_mgr/mem_fabric_import_v2.c",0x339);
  return (ulong)uVar1;
}


// ===== 0045fbe0 memoryfabricimportv2CtrlGetInfo_IMPL =====

undefined8 memoryfabricimportv2CtrlGetInfo_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(param_1 + 0x228);
  lVar2 = *(long *)(param_1 + 0x210);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x80));
  puVar3 = (undefined8 *)memdescGetMemData(*(undefined8 *)(lVar2 + 0x118));
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(puVar3 + 1);
  *(undefined8 *)((long)param_2 + 0x14) = *puVar3;
  *param_2 = *(undefined8 *)(*(long *)(lVar2 + 0x118) + 0x30);
  uVar4 = memdescGetPageSize(*(undefined8 *)(lVar2 + 0x118),1);
  param_2[1] = uVar4;
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x80));
  return 0;
}


// ===== 0045fc70 memoryfabricimportv2GetMapAddrSpace_IMPL =====

undefined8 memoryfabricimportv2GetMapAddrSpace_IMPL(void)

{
  undefined4 *in_RCX;
  
  *in_RCX = 6;
  return 0;
}


// ===== 0045fc80 memoryfabricimportv2RemoveFromCache_IMPL =====

void memoryfabricimportv2RemoveFromCache_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x228);
  uVar2 = *(undefined8 *)(g_pSys + 0x260);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x80));
  fabricImportCacheDelete_IMPL(uVar2,lVar1 + 0x58,*(undefined8 *)(lVar1 + 0x50));
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x80));
  return;
}


// ===== 0045fcd0 memoryfabricimportv2IsExportAllowed_IMPL =====

undefined8 memoryfabricimportv2IsExportAllowed_IMPL(void)

{
  return 0;
}


// ===== 0045fce0 memoryfabricimportv2IsGpuMapAllowed_IMPL =====

undefined8 memoryfabricimportv2IsGpuMapAllowed_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  ushort uVar7;
  int local_2c [3];
  
  lVar3 = 0;
  if (param_1 != 0) {
    lVar3 = *(long *)(param_1 + 0x210);
  }
  cVar2 = gpuFabricProbeIsSupported(param_2);
  if (cVar2 == '\0') {
    return 1;
  }
  lVar3 = memdescGetMemData(*(undefined8 *)(lVar3 + 0x118));
  uVar4 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(param_2 + 0x4c0),local_2c);
  if ((int)uVar4 != 0) {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric_import_v2.c",0x39b,
                 "memoryfabricimportv2IsGpuMapAllowed_IMPL",4,
                 "NVRM: unable to query cliqueId 0x%x\n",uVar4 & 0xffffffff);
    return 0;
  }
  if (*(int *)(lVar3 + 0xc) != local_2c[0]) {
    nvDbg_Printf("src/kernel/mem_mgr/mem_fabric_import_v2.c",0x3a1,
                 "memoryfabricimportv2IsGpuMapAllowed_IMPL",4,
                 "NVRM: cliqueId does not match: owner %u, mapper %u\n",*(int *)(lVar3 + 0xc),
                 local_2c[0]);
    return 0;
  }
  uVar7 = *(ushort *)(lVar3 + 0x18);
  if (*(long *)(param_2 + 0x1ce8) == 0) {
    if (uVar7 == 0) goto LAB_0045fdd5;
  }
  else {
    if (uVar7 == *(byte *)(*(long *)(param_2 + 0x1ce8) + 0x16c0)) {
LAB_0045fdd5:
      lVar1 = *(long *)(lVar3 + 0x10);
      lVar5 = knvlinkGetBWModeEpoch_IMPL(param_2);
      if (lVar1 != lVar5) {
        uVar6 = knvlinkGetBWModeEpoch_IMPL(param_2,*(undefined8 *)(param_2 + 0x1ce8));
        nvDbg_Printf("src/kernel/mem_mgr/mem_fabric_import_v2.c",0x3af,
                     "memoryfabricimportv2IsGpuMapAllowed_IMPL",4,
                     "NVRM: bwModeEpoch does not match: owner %llu, mapper %llu\n",
                     *(undefined8 *)(lVar3 + 0x10),uVar6);
        return 0;
      }
      return 1;
    }
    if (*(long *)(param_2 + 0x1ce8) != 0) {
      uVar4 = (ulong)*(byte *)(*(long *)(param_2 + 0x1ce8) + 0x16c0);
    }
    uVar7 = *(ushort *)(lVar3 + 0x18);
  }
  nvDbg_Printf("src/kernel/mem_mgr/mem_fabric_import_v2.c",0x3a8,
               "memoryfabricimportv2IsGpuMapAllowed_IMPL",4,
               "NVRM: bwMode does not match: owner %u, mapper  %u\n",uVar7,uVar4);
  return 0;
}


// ===== 0045feac memlistConstruct_IMPL.cold =====

void memlistConstruct_IMPL_cold(void)

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


// ===== 0045fec0 memlistConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memlistConstruct_IMPL(long param_1,long param_2,long param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  long lVar9;
  long lVar10;
  code *pcVar11;
  char cVar12;
  char cVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  ulong *puVar18;
  undefined8 uVar19;
  long lVar20;
  long lVar21;
  long *plVar22;
  ulong uVar23;
  undefined4 *puVar24;
  ulong uVar25;
  ulong uVar26;
  undefined8 uVar27;
  uint uVar28;
  uint uVar29;
  long lVar30;
  bool bVar31;
  bool bVar32;
  long local_f0;
  long local_b8;
  long local_b0;
  undefined8 *local_70;
  long local_68;
  long local_60;
  ulong local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  long local_40 [2];
  
  lVar20 = *(long *)(param_2 + 0x10);
  uVar16 = *(uint *)(*(long *)(param_2 + 8) + 0x48);
  iVar14 = *(int *)(lVar20 + 0x11c);
  uVar2 = *(undefined4 *)(*(long *)(lVar20 + 0x18) + 0x10);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar11 = (code *)invalidInstructionException();
    (*pcVar11)();
  }
  lVar6 = *(long *)(param_1 + 0x210);
  iVar17 = *(int *)(param_2 + 0x2c);
  local_70 = (undefined8 *)0x0;
  local_68 = 0;
  lVar7 = *(long *)(lVar6 + 0xf0);
  if (*(long *)(param_3 + 0x58) != 0) {
    return 0;
  }
  puVar8 = *(uint **)(param_3 + 0x40);
  cVar12 = hypervisorIsVgxHyper_IMPL();
  if ((cVar12 == '\0') &&
     (((*(char *)(lVar7 + 0x908) == '\0' || (*(uint *)(param_2 + 0x28) < 2)) &&
      (*(char *)(lVar7 + 0x909) == '\0')))) {
    return 0x56;
  }
  cVar12 = '\x01';
  if ((puVar8[0x24] & 0xf000) != 0) {
    cVar12 = ((puVar8[0x24] & 0xf000) == 0x2000) * '\x02';
  }
  uVar28 = puVar8[3];
  uVar3 = puVar8[1];
  uVar29 = *puVar8;
  uVar4 = puVar8[4];
  uVar5 = puVar8[5];
  if (uVar29 == 0) {
    uVar29 = uVar16;
    local_60 = lVar7;
    if (uVar3 != 0) {
      return 0x36;
    }
  }
  else {
    iVar15 = serverGetClientUnderLock(g_resServ,uVar29,local_40);
    if (iVar15 != 0) {
      return iVar15;
    }
    iVar15 = gpuGetByHandle(local_40[0],uVar3,0,&local_60);
    if (iVar15 != 0) {
      return iVar15;
    }
    if (local_60 != lVar7) {
      return 0x36;
    }
  }
  uVar25 = (ulong)uVar29;
  if (iVar14 == 0x83) {
    if (puVar8[2] == 0) {
      return 0x1f;
    }
  }
  else if (puVar8[2] != 0) {
    return 0x1f;
  }
  if ((puVar8[7] != 0) || (0xfff < puVar8[6])) {
    return 0x1f;
  }
  uVar3 = puVar8[9];
  if ((uVar3 & 0x80000) != 0) {
    nvAssertFailedNoLog("!(pAllocParams->flags & NVOS32_ALLOC_FLAGS_VIRTUAL)",
                        "src/kernel/mem_mgr/mem_list.c",0xa8);
    return 0x56;
  }
  bVar31 = iVar17 == 0;
  uVar29 = uVar5;
  if (iVar14 == 0x82) {
    if (uVar5 == 0) {
      local_b8 = 0;
      bVar32 = (puVar8[0x24] & 0xf0) == 0;
      uVar28 = puVar8[0x24] & 0xf0;
      local_b0 = *(long *)(puVar8 + 0x22) + 1;
    }
    else {
      local_b8._0_4_ = uVar3 & 0x80000;
      iVar14 = serverGetClientUnderLock(g_resServ,uVar28,local_40);
      uVar29 = uVar3 & 0x80000;
      if ((iVar14 == 0) &&
         (iVar14 = memGetByHandleAndDevice_IMPL(local_40[0],uVar5,uVar4,&local_68),
         uVar29 = (uint)local_b8, iVar14 == 0)) {
        uVar29 = uVar5;
      }
      local_b8 = 0;
      bVar32 = (puVar8[0x24] & 0xf0) == 0;
      uVar28 = puVar8[0x24] & 0xf0;
      local_b0 = *(long *)(puVar8 + 0x22) + 1;
    }
  }
  else {
    if (iVar14 != 0x83) {
      if (iVar14 != 0x81) {
        return 0x22;
      }
      local_58 = local_58 & 0xffffffff00000000;
      local_40[0] = 0;
      iVar14 = memdescCreate(&local_70,lVar7,*(long *)(puVar8 + 0x22) + 1,0,
                             (puVar8[0x24] & 0xf0) == 0,1,cVar12,0x20000);
      if (iVar14 != 0) {
        return iVar14;
      }
      memdescSetFlag(local_70,0x100,1);
      *(uint *)(local_70 + 0xc) = puVar8[6];
      memdescSetPteKindForGpu(local_70,*local_70,puVar8[0xe]);
      memdescSetGuestId(local_70,*(undefined8 *)(puVar8 + 0x14));
      puVar18 = (ulong *)memdescGetPteArrayForGpu(local_70,*local_70,1);
      uVar16 = puVar8[0x11];
      if (((ulong)local_70[4] < (ulong)uVar16) || ((uVar16 & 0xe0000000) != 0)) {
        memdescDestroy();
        return 0x1f;
      }
      iVar14 = rmapiParamsCopyIn(0,puVar18,*(undefined8 *)(puVar8 + 0x20),uVar16 * 8,bVar31);
      if (iVar14 != 0) {
        memdescDestroy();
        return iVar14;
      }
      local_40[0] = local_70[6];
      iVar14 = memdescCalculateActualSize(local_70,local_40[0],local_40);
      if (iVar14 != 0) {
        memdescDestroy();
        return iVar14;
      }
      uVar25 = local_40[0] + 0xfffU >> 0xc;
      if (((*(byte *)((long)local_70 + 9) & 4) == 0) && ((ulong)local_70[4] < uVar25)) {
        memdescDestroy();
        return 2;
      }
      local_70[3] = uVar25;
      local_70[7] = local_40[0] + 0xfffU & 0xfffffffffffff000;
      *(undefined4 *)(local_70 + 0x2c) = 0x1000;
      lVar20 = *(long *)(&DAT_00001b90 + lVar7);
      if (*(uint *)(lVar20 + 0x55c) != 0) {
        uVar25 = 0;
        do {
          uVar23 = *(ulong *)(lVar20 + 0x560 + uVar25 * 8);
          if ((uVar23 >> 0xc <= *puVar18) &&
             (*puVar18 < uVar23 + *(long *)(lVar20 + 0x5a0 + uVar25 * 8) >> 0xc)) {
            memdescSetFlag(local_70,0x400000,1);
            if ((int)uVar25 == 0) {
              memdescSetFlag(local_70,0x8000000,1);
            }
            else if ((int)uVar25 == 1) {
              memdescSetFlag(local_70,0x10000000,1);
            }
            break;
          }
          uVar25 = uVar25 + 1;
        } while (uVar25 != *(uint *)(lVar20 + 0x55c));
      }
      uVar16 = puVar8[0x11];
      if (uVar16 != 0) {
        puVar18 = puVar18 + (uVar16 - 1);
        do {
          uVar16 = uVar16 - 1;
          uVar28 = *(uint *)(local_70 + 0x2c);
          uVar25 = *puVar18;
          puVar18 = puVar18 + -1;
          memdescSetPte(local_70,1,uVar16,
                        uVar25 << ((uVar28 & 0xaaaaaaaa) != 0 | (0xffff < uVar28) << 4 |
                                   ((uVar28 & 0xff00ff00) != 0) << 3 |
                                   ((uVar28 & 0xf0f0f0f0) != 0) << 2 |
                                  ((uVar28 & 0xcccccccc) != 0) * '\x02'));
        } while (uVar16 != 0);
      }
      *(undefined4 *)((long)local_70 + 0x9c) = 0x4f;
      iVar14 = memdescAlloc();
      if (iVar14 != 0) {
        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x16d,"memlistConstruct_IMPL",4,
                     "NVRM: *** Cannot fake guest sysmem allocation. status =0x%x\n",iVar14);
        memdescDestroy(local_70);
        return iVar14;
      }
      local_50 = 0;
      local_48 = (ulong)local_48._4_4_ << 0x20;
      iVar14 = RmDeprecatedConvertOs02ToOs32Flags(puVar8[0x24],&local_48,&local_58,&local_50);
      if (iVar14 != 0) {
        memdescDestroy(local_70);
        return iVar14;
      }
      iVar14 = memConstructCommon_IMPL
                         (lVar6,0x3e,local_50,local_70,0,0,local_48 & 0xffffffff,
                          local_58 & 0xffffffff,0,0,0,0);
      if (iVar14 != 0) {
        memdescDestroy(local_70);
        return iVar14;
      }
      return 0;
    }
    local_68 = 0;
    iVar14 = serverGetClientUnderLock(g_resServ,uVar25,&local_48);
    if (iVar14 != 0) {
      return 0x23;
    }
    iVar14 = memGetByHandle_IMPL(local_48,puVar8[2],&local_68);
    if (iVar14 != 0) {
      return iVar14;
    }
    local_b8 = *(long *)(local_68 + 0x118);
    if (local_b8 == 0) {
      return 0x22;
    }
    iVar14 = memdescGetAddressSpace();
    if (1 < iVar14 - 1U) {
      return 0x31;
    }
    cVar13 = memdescGetContiguity(local_b8,1);
    if ((cVar13 == '\0') &&
       ((ulong)(*(long *)(local_b8 + 0x18) << 0xc) < *(ulong *)(local_b8 + 0x30))) {
      return 2;
    }
    if (uVar5 != 0) {
      iVar17 = serverGetClientUnderLock(g_resServ,uVar28,local_40);
      uVar29 = 0;
      if ((iVar17 == 0) &&
         (iVar17 = memGetByHandleAndDevice_IMPL(local_40[0],uVar5,uVar4,&local_68), iVar17 == 0)) {
        uVar29 = uVar5;
      }
    }
    if (iVar14 == 1) {
      local_58 = local_58 & 0xffffffff00000000;
      local_40[0] = 0;
      nvCheckFailedNoLog(4,"src_pMemDesc == NULL","src/kernel/mem_mgr/mem_list.c",0x10b);
      return 0x56;
    }
    bVar32 = (puVar8[0x24] & 0xf0) == 0;
    uVar28 = puVar8[0x24] & 0xf0;
    local_b0 = *(long *)(puVar8 + 0x22) + 1;
  }
  lVar9 = *(long *)(lVar7 + 0x1b78);
  lVar10 = *(long *)(lVar7 + 0x1b98);
  local_48 = 0;
  iVar14 = refFindAncestorOfType(lVar20,&DAT_00e0ac20,&local_50);
  if (iVar14 != 0) {
    nvAssertOkFailedNoLog
              (iVar14,"refFindAncestorOfType(pResourceRef, classId(Device), &pDeviceRef)",
               "src/kernel/mem_mgr/mem_list.c",0x1b4);
    return iVar14;
  }
  uVar19 = __nvoc_dynamicCast(*(undefined8 *)(CONCAT44(uStack_4c,local_50) + 8),
                              __nvoc_class_def_Device);
  lVar20 = vidmemGetHeap_IMPL(lVar7,uVar19,0,0);
  if (lVar20 == 0) {
    nvAssertFailedNoLog("(pHeap != NULL)","src/kernel/mem_mgr/mem_list.c",0x1c0);
    return 0x40;
  }
  if (0x11 < puVar8[8]) {
    return 0x1f;
  }
  if ((uVar28 == 0) && (1 < puVar8[0x11])) {
    return 0x1f;
  }
  if ((*(byte *)((long)puVar8 + 0x2b) & 6) != 0) {
    return 0x1f;
  }
  uVar3 = puVar8[9];
  uVar4 = uVar3 & 0x401c0;
  if ((uVar3 & 0x401c0) != 0) {
    return 0x1f;
  }
  puVar8[9] = uVar3 | 0x4001;
  lVar21 = portMemAllocNonPaged(0xc0);
  if (lVar21 == 0) {
    nvAssertFailedNoLog(&DAT_00d82a12,"src/kernel/mem_mgr/mem_list.c",0x1d4);
    memdescDestroy(local_70);
    local_f0 = 0;
    iVar14 = 0x51;
    goto LAB_0046106e;
  }
  local_f0 = portMemAllocNonPaged(0x14);
  if (local_f0 == 0) {
    nvAssertFailedNoLog(&DAT_00d82a12,"src/kernel/mem_mgr/mem_list.c",0x1db);
    memdescDestroy(local_70);
    iVar14 = 0x51;
    goto LAB_0046106e;
  }
  uVar19 = CONCAT44(uVar2,uVar16);
  portMemSet(lVar21,0,0xc0);
  portMemSet(local_f0,0,0x14);
  *(long *)(lVar21 + 0x90) = local_f0;
  if (local_b8 == 0) {
    uVar25 = 0;
    local_40[0] = 0;
    heapGetSize_IMPL(lVar20,&local_58);
    heapGetBase_IMPL(lVar20,local_40);
    local_58 = local_58 + local_40[0];
  }
  else {
    local_58 = (ulong)*(uint *)(local_b8 + 0x60) + *(long *)(local_b8 + 0x30);
    memdescGetPhysAddr(local_b8,1,0);
  }
  if ((puVar8[5] != 0) && ((*(byte *)((long)puVar8 + 0x29) & 0x3c) != 0)) {
    nvAssertFailedNoLog("(pAllocParams->hHwResHandle == 0) || !(pAllocParams->attr & (DRF_SHIFTMASK(NVOS32_ATTR_COMPR) | DRF_SHIFTMASK(NVOS32_ATTR_ZCULL)))"
                        ,"src/kernel/mem_mgr/mem_list.c",0x1f5);
  }
  iVar14 = memdescCreate(&local_70,lVar7,local_b0,0,bVar32,2,cVar12,0);
  puVar24 = (undefined4 *)0x0;
  if (iVar14 == 0) {
    plVar22 = (long *)memdescGetPteArrayForGpu(local_70,*local_70,1);
    iVar14 = rmapiParamsCopyIn(0,plVar22,*(undefined8 *)(puVar8 + 0x20),puVar8[0x11] << 3,bVar31);
    if (iVar14 == 0) {
      local_48 = local_70[6];
      iVar14 = memdescCalculateActualSize(local_70,local_48,&local_48);
      uVar4 = 0;
      if (iVar14 == 0) {
        uVar23 = local_48 + 0xfff >> 0xc;
        uVar26 = local_48 + 0xfff & 0xfffffffffffff000;
        if (((*(byte *)((long)local_70 + 9) & 4) == 0) && ((ulong)local_70[4] < uVar23)) {
LAB_00461348:
          iVar14 = 2;
          uVar4 = 0;
        }
        else {
          local_70[3] = uVar23;
          local_70[7] = uVar26;
          *(undefined4 *)(local_70 + 0x2c) = 0x1000;
          if ((uVar28 == 0) &&
             (lVar30 = *plVar22 * 0x1000 + (ulong)puVar8[6], local_58 < (ulong)(local_b0 + lVar30)))
          {
            nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x220,"memlistConstruct_IMPL",4,
                         "NVRM: Out of range contig memory at 0x%016llx of size 0x%016llx\n",lVar30,
                         local_b0,uVar26);
            iVar14 = 0x1f;
            uVar4 = 0;
          }
          else {
            uVar23 = (ulong)puVar8[0x11];
            while ((int)uVar23 != 0) {
              uVar28 = *(uint *)(local_70 + 0x2c);
              uVar23 = (ulong)((int)uVar23 - 1);
              if (local_58 <
                  (ulong)uVar28 +
                  (plVar22[uVar23] <<
                  ((uVar28 & 0xaaaaaaaa) != 0 | (0xffff < uVar28) << 4 |
                   ((uVar28 & 0xff00ff00) != 0) << 3 | ((uVar28 & 0xf0f0f0f0) != 0) << 2 |
                  ((uVar28 & 0xcccccccc) != 0) * '\x02'))) {
                nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x22f,"memlistConstruct_IMPL",4,
                             "NVRM: Out of range page address 0x%016llx\n");
                goto LAB_00461348;
              }
              memdescSetPte(local_70,1,uVar23);
            }
            iVar14 = vgpuIsCallingContextPlugin(*local_70,local_40);
            if (iVar14 == 0) {
              if ((char)local_40[0] == '\0') {
                memdescSetFlag(local_70,0x100,1);
              }
              memdescSetFlag(local_70,0x400000000,1);
              uVar28 = puVar8[10];
              if ((uVar28 & 0x3c00) == 0) {
                uVar4 = 0;
                if (uVar29 != 0) {
                  puVar24 = *(undefined4 **)(local_68 + 0x1a8);
                  uVar4 = puVar24[4];
                }
LAB_004609f1:
                uVar16 = dmaNvos32ToPageSizeAttr(uVar28,puVar8[0xb]);
                if (uVar16 == 3) {
                  uVar27 = 0x2c8;
                  if (*(char *)(lVar10 + 0x67d0) == '\0') {
LAB_0046154f:
                    nvAssertFailedNoLog(&DAT_00d82a12,"src/kernel/mem_mgr/mem_list.c",uVar27);
                    iVar14 = 0x1f;
                    goto LAB_00460fc7;
                  }
                  memdescSetPageSize(local_70,1,0x200000);
                }
                else if (uVar16 < 4) {
                  if (uVar16 == 1) {
                    memdescSetPageSize(local_70,1,0x1000);
                  }
                  else if (uVar16 == 2) {
                    memdescSetPageSize(local_70,1,0x10000);
                  }
                  else {
                    nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2d8,"memlistConstruct_IMPL",1,
                                 "NVRM: page size default doesn\'t have any impact \n");
                  }
                }
                else if (uVar16 == 4) {
                  if (*(char *)(lVar10 + 0x67d1) == '\0') {
                    uVar27 = 0x2d1;
                    goto LAB_0046154f;
                  }
                  memdescSetPageSize(local_70,1,0x20000000);
                }
                else if (uVar16 - 5 < 2) {
                  nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2dc,"memlistConstruct_IMPL",1,
                               "NVRM: unexpected pageSizeAttr = 0x%x\n");
                  iVar14 = 0x40;
                  goto LAB_00460fc7;
                }
                iVar14 = memConstructCommon_IMPL
                                   (lVar6,0x40,0,local_70,0,lVar20,puVar8[10],puVar8[0xb],0,
                                    puVar8[8],0,puVar24);
                if (iVar14 == 0) {
                  if (uVar29 == 0) {
                    if (puVar24 != (undefined4 *)0x0) {
                      portMemFree(puVar24);
                    }
                  }
                  else if (puVar24 != (undefined4 *)0x0) {
                    piVar1 = (int *)(*(long *)(lVar6 + 0x1a8) + 0x14);
                    *piVar1 = *piVar1 + 1;
                  }
                  memdescSetPteKindForGpu
                            (*(undefined8 **)(lVar6 + 0x118),**(undefined8 **)(lVar6 + 0x118),
                             puVar8[0xe]);
                  *(uint *)(*(long *)(lVar6 + 0x118) + 0x98) = uVar4;
                  goto LAB_0046106e;
                }
              }
              else {
                *(uint *)(*(long *)(lVar21 + 0x90) + 0x10) = puVar8[8];
                *(undefined4 *)(lVar21 + 4) = 0;
                *(undefined8 *)(lVar21 + 0x30) = 0;
                *(undefined8 *)(lVar21 + 0x28) = 0;
                *(uint *)(lVar21 + 8) = puVar8[0xc];
                *(uint *)(lVar21 + 0xc) = puVar8[0xd];
                *(uint *)(lVar21 + 0x10) = puVar8[0x1a];
                uVar27 = *(undefined8 *)(puVar8 + 0x1c);
                *(undefined8 *)(lVar21 + 0x38) = 0xffffffffffffffff;
                *(undefined8 *)(lVar21 + 0x18) = uVar27;
                *(undefined8 *)(lVar21 + 0x78) = uVar27;
                *(uint *)(*(long *)(lVar21 + 0x90) + 8) = puVar8[9];
                *(undefined4 *)(lVar21 + 0x40) = 0;
                uVar28 = puVar8[10];
                **(uint **)(lVar21 + 0x90) = uVar28;
                *(uint *)(lVar21 + 0x44) = uVar28;
                uVar28 = puVar8[0xb];
                *(uint *)(*(long *)(lVar21 + 0x90) + 4) = uVar28;
                *(uint *)(lVar21 + 0x48) = uVar28;
                uVar28 = puVar8[0xe];
                *(uint *)(lVar21 + 0x4c) = uVar28;
                *(uint *)(lVar21 + 0x50) = puVar8[0xf];
                *(undefined4 *)(lVar21 + 0x54) = 0;
                *(uint *)(lVar21 + 0xa4) = puVar8[0x1b];
                *(undefined8 *)(lVar21 + 0x98) = uVar19;
                if ((puVar8[9] & 0x180) == 0) {
                  uVar23 = (ulong)*(uint *)(local_70 + 0x2c);
                }
                else {
                  uVar23 = *(ulong *)(puVar8 + 0x1e);
                }
                *(ulong *)(lVar21 + 0x20) = uVar23;
                lVar30 = (**(code **)(lVar9 + 0x168))
                                   (lVar9,uVar16,*(undefined8 *)(lVar21 + 0x18),uVar28,
                                    *(undefined4 *)(*(long *)(lVar21 + 0x90) + 8),lVar21 + 0x44,
                                    lVar21 + 0x48,uVar25);
                uVar4 = 0;
                if (lVar30 == 0) {
                  nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x26e,"memlistConstruct_IMPL",4,
                               "NVRM: memmgrDeterminePageSize failed\n");
                  iVar14 = 0x40;
                }
                else {
                  iVar14 = (**(code **)(lVar9 + 0x1f8))
                                     (lVar7,lVar9,lVar21 + 0x18,lVar21 + 0x20,
                                      *(undefined8 *)(lVar21 + 0x28),
                                      *(undefined4 *)(*(long *)(lVar21 + 0x90) + 8),
                                      *(undefined4 *)(lVar21 + 0x44),*(undefined4 *)(lVar21 + 0x48),
                                      0,puVar8);
                  if (iVar14 == 0) {
                    iVar14 = memmgrAllocHwResources_IMPL(lVar7,lVar9,lVar21);
                    if (iVar14 == 0) {
                      if (((*(byte *)((long)puVar8 + 0x27) & 0x10) == 0) &&
                         (*(uint *)(lVar21 + 0x4c) != puVar8[0xe])) {
                        nvAssertFailedNoLog("pFbAllocInfo->format == pAllocParams->format",
                                            "src/kernel/mem_mgr/mem_list.c",0x28e);
                      }
                      nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x291,"memlistConstruct_IMPL",1,
                                   "NVRM: fbAlloc for comptag successful!\n");
                      puVar24 = (undefined4 *)portMemAllocNonPaged(0x1c);
                      if (puVar24 != (undefined4 *)0x0) {
                        portMemSet(puVar24,0,0x1c);
                        *puVar24 = *(undefined4 *)(lVar21 + 0x44);
                        puVar24[1] = *(undefined4 *)(lVar21 + 0x48);
                        puVar24[2] = *(undefined4 *)(lVar21 + 0x50);
                        puVar24[3] = *(undefined4 *)(lVar21 + 0xa4);
                        puVar24[4] = *(undefined4 *)(lVar21 + 4);
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2a3,"memlistConstruct_IMPL",1
                                     ,"NVRM: memmgrAllocHwResources result\n");
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2a4,"memlistConstruct_IMPL",1
                                     ,"NVRM:                 Attr:0x%x\n",
                                     *(undefined4 *)(lVar21 + 0x44));
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2a6,"memlistConstruct_IMPL",1
                                     ,"NVRM:                Attr2:0x%x\n",
                                     *(undefined4 *)(lVar21 + 0x48));
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2a8,"memlistConstruct_IMPL",1
                                     ,"NVRM:            comprCovg:0x%x\n",
                                     *(undefined4 *)(lVar21 + 0x50));
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2aa,"memlistConstruct_IMPL",1
                                     ,"NVRM:            zcullCovg:0x%x\n",
                                     *(undefined4 *)(lVar21 + 0x54));
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2ac,"memlistConstruct_IMPL",1
                                     ,"NVRM:           ctagOffset:0x%x\n",
                                     *(undefined4 *)(lVar21 + 0xa4));
                        nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x2ae,"memlistConstruct_IMPL",1
                                     ,"NVRM:              hwResId:0x%x\n",
                                     *(undefined4 *)(lVar21 + 4));
                        uVar4 = *(uint *)(lVar21 + 4);
                        uVar28 = puVar8[10];
                        goto LAB_004609f1;
                      }
                      (**(code **)(lVar9 + 0x170))(lVar7,lVar9,lVar21);
                      uVar4 = 0;
                      iVar14 = 0x51;
                    }
                    else {
                      nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x287,"memlistConstruct_IMPL",4,
                                   "NVRM: memmgrAllocHwResources failure!\n");
                      uVar4 = 0;
                    }
                  }
                  else {
                    nvDbg_Printf("src/kernel/mem_mgr/mem_list.c",0x279,"memlistConstruct_IMPL",4,
                                 "NVRM: memmgrAllocDetermineAlignment failed\n");
                  }
                }
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar14,"vgpuIsCallingContextPlugin(pMemDesc->pGpu, &bCallingContextPlugin)"
                         ,"src/kernel/mem_mgr/mem_list.c",0x237);
              uVar4 = 0;
            }
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
  }
LAB_00460fc7:
  memdescDestroy(local_70);
  if (uVar29 == 0) {
    portMemFree(puVar24);
    portMemSet(lVar21,0,0xc0);
    portMemSet(local_f0,0,0x14);
    *(long *)(lVar21 + 0x90) = local_f0;
    *(uint *)(local_f0 + 0x10) = puVar8[8];
    *(uint *)(lVar21 + 4) = uVar4;
    *(long *)(lVar21 + 0x18) = local_b0;
    *(undefined8 *)(lVar21 + 0x98) = uVar19;
    (**(code **)(lVar9 + 0x170))(lVar7,lVar9,lVar21);
  }
LAB_0046106e:
  portMemFree(local_f0);
  portMemFree(lVar21);
  return iVar14;
}


// ===== 004616b0 memlistCanCopy_IMPL =====

undefined8 memlistCanCopy_IMPL(void)

{
  return 1;
}


// ===== 004616c0 _memorymulticastfabricValidateNvlAttrCommon =====

undefined8
_memorymulticastfabricValidateNvlAttrCommon
          (int *param_1,undefined8 param_2,short param_3,long param_4)

{
  if (*param_1 == (int)param_2) {
    if (*(long *)(param_1 + 2) == param_4) {
      if ((short)param_1[4] == param_3) {
        return 0;
      }
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x723,
                   "_memorymulticastfabricValidateNvlAttrCommon",4,"NVRM: bwMode mismatch %u:%u\n",
                   (short)param_1[4],param_3);
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x71d,
                   "_memorymulticastfabricValidateNvlAttrCommon",4,
                   "NVRM: bwModeEpoch mismatch %llu:%llu\n",*(long *)(param_1 + 2),param_4);
    }
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x717,
                 "_memorymulticastfabricValidateNvlAttrCommon",4,"NVRM: Clique ID mismatch %u:%u\n",
                 *param_1,param_2);
  }
  return 0x26;
}


// ===== 00461780 _memMulticastFabricDescriptorFlushClients =====

void _memMulticastFabricDescriptorFlushClients(long param_1)

{
  int iVar1;
  long *plVar2;
  
  while( true ) {
    plVar2 = (long *)listHead_IMPL(param_1 + 8);
    if (plVar2 == (long *)0x0) break;
    if (*plVar2 != 0) {
      osSetEvent(0);
      iVar1 = osDereferenceObjectCount(*plVar2);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,"osDereferenceObjectCount(pNode->pOsEvent)",
                   "src/kernel/mem_mgr/mem_multicast_fabric.c",0x1c5);
      }
    }
    listRemove_IMPL(param_1 + 8,plVar2);
  }
  return;
}


// ===== 004617f0 _memMulticastFabricDescriptorEnqueueWait =====

undefined8
_memMulticastFabricDescriptorEnqueueWait(undefined8 param_1,long param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  long *plVar2;
  long local_20;
  
  local_20 = 0;
  if ((param_3 != 0) &&
     (uVar1 = osUserHandleToKernelPtr(param_1,param_3,&local_20), (int)uVar1 != 0)) {
    return uVar1;
  }
  plVar2 = (long *)listAppendNew_IMPL(param_2 + 8);
  if (plVar2 == (long *)0x0) {
    if (local_20 != 0) {
      osDereferenceObjectCount();
    }
    uVar1 = 0x51;
  }
  else {
    *plVar2 = local_20;
    plVar2[1] = param_4;
    if (*(char *)(param_2 + 0x60) != '\0') {
      _memMulticastFabricDescriptorFlushClients(param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00461880 _memorymulticastfabricValidateNvlAttr =====

undefined8
_memorymulticastfabricValidateNvlAttr
          (long param_1,undefined4 param_2,undefined2 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar2 = listHead_IMPL(param_1 + 0x38);
  lVar3 = multimapFirstItem_IMPL(param_1 + 200);
  if ((lVar2 != 0) &&
     (iVar1 = _memorymulticastfabricValidateNvlAttrCommon(lVar2 + 0x20,param_2,param_3,param_4),
     iVar1 != 0)) {
    nvCheckOkFailedNoLog
              (4,0x26,
               "_memorymulticastfabricValidateNvlAttrCommon(&pHead->nvlAttr, cliqueId, bwMode, bwModeEpoch)"
               ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x73b);
    return 0x26;
  }
  uVar4 = 0;
  if ((lVar3 != 0) &&
     (uVar4 = _memorymulticastfabricValidateNvlAttrCommon(lVar3,param_2,param_3,param_4),
     (int)uVar4 != 0)) {
    nvCheckOkFailedNoLog
              (4,0x26,
               "_memorymulticastfabricValidateNvlAttrCommon(&pRemoteHead->nvlAttr, cliqueId, bwMode, bwModeEpoch)"
               ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x743);
    return 0x26;
  }
  return uVar4;
}


// ===== 00461970 _memorymulticastfabricCtrlSetFailure =====

undefined8 _memorymulticastfabricCtrlSetFailure(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar4 = resservGetTlsCallContext();
  lVar5 = __nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),__nvoc_class_def_RmClient);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",0x875);
    return 0x23;
  }
  lVar2 = *(long *)(param_1 + 0x228);
  cVar3 = rmclientIsCapableOrAdmin_IMPL(lVar5,4,*(undefined4 *)(lVar4 + 0x28));
  uVar6 = 0x1b;
  if (cVar3 != '\0') {
    if ((*(byte *)(lVar2 + 0xa0) & 1) == 0) {
      iVar1 = *param_2;
      if ((iVar1 == 0) || (iVar1 == 0x55)) {
        return 0x1f;
      }
      *(int *)(lVar2 + 0x78) = iVar1;
      _memMulticastFabricDescriptorFlushClients(lVar2);
      uVar6 = 0;
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x87f,
                   "_memorymulticastfabricCtrlSetFailure",4,
                   "NVRM: Only supported on prime MCLFA object\n");
      uVar6 = 0x56;
    }
  }
  return uVar6;
}


// ===== 00461a70 _memMulticastFabricDescriptorCleanup.part.0 =====

void _memMulticastFabricDescriptorCleanup_part_0(long param_1)

{
  int iVar1;
  
  iVar1 = listCount_IMPL(param_1 + 0x38);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("listCount(&pMulticastFabricDesc->gpuInfoList) == 0",
                        "src/kernel/mem_mgr/mem_multicast_fabric.c",0x165);
  }
  listDestroy_IMPL(param_1 + 0x38);
  multimapDestroy_IMPL(param_1 + 200);
  if (*(int *)(param_1 + 0xa8) == 0) {
    iVar1 = *(int *)(param_1 + 0x30);
  }
  else {
    nvAssertFailedNoLog("pMulticastFabricDesc->numAttachedGpus == 0",
                        "src/kernel/mem_mgr/mem_multicast_fabric.c",0x16a);
    iVar1 = *(int *)(param_1 + 0x30);
  }
  if (iVar1 == 0) {
    iVar1 = listCount_IMPL(param_1 + 8);
  }
  else {
    nvAssertFailedNoLog("pMulticastFabricDesc->localAttachedGpusMask == 0",
                        "src/kernel/mem_mgr/mem_multicast_fabric.c",0x16b);
    iVar1 = listCount_IMPL(param_1 + 8);
  }
  if (iVar1 != 0) {
    nvAssertFailedNoLog("listCount(&pMulticastFabricDesc->waitingClientsList) == 0",
                        "src/kernel/mem_mgr/mem_multicast_fabric.c",0x16d);
  }
  listDestroy_IMPL(param_1 + 8);
  memdescDestroy(*(undefined8 *)(param_1 + 0x68));
  if (*(long *)(param_1 + 0x100) != 0) {
    portSyncRwLockDestroy();
  }
  portMemFree(param_1);
  return;
}


// ===== 00461ba0 _memMulticastFabricDescriptorAlloc.isra.0 =====

undefined8 * _memMulticastFabricDescriptorAlloc_isra_0(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar1 = *(undefined8 *)(g_pSys + 0x260);
  puVar3 = (undefined8 *)portMemAllocNonPaged(0x108);
  if (puVar3 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  portMemSet(puVar3,0,0x108);
  uVar4 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(puVar3 + 1,uVar4,0x10);
  uVar4 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(puVar3 + 7,uVar4,0x48);
  *puVar3 = 1;
  *(undefined4 *)(puVar3 + 0xf) = 0x55;
  *(undefined4 *)(puVar3 + 6) = 0;
  puVar3[0x11] = *(undefined8 *)(param_1 + 0x28);
  puVar3[0x12] = *(undefined8 *)(param_1 + 0x30);
  puVar3[0x13] = *(undefined8 *)(param_1 + 0x38);
  *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)((long)puVar3 + 0xa4) = *(undefined4 *)(param_1 + 0x44);
  uVar4 = osGetTimestamp();
  puVar3[0x10] = uVar4;
  uVar4 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(puVar3 + 0x19,uVar4,0x20,0x20,0x10);
  *(undefined4 *)(puVar3 + 0x1f) = 0xffffffff;
  *(undefined2 *)((long)puVar3 + 0xac) = 0xffff;
  uVar4 = portMemAllocatorGetGlobalNonPaged();
  lVar5 = portSyncRwLockCreate(uVar4);
  puVar3[0x20] = lVar5;
  if (lVar5 != 0) {
    iVar2 = fabricMulticastSetupCacheInsert_IMPL(uVar1,puVar3[0x10],puVar3);
    if (iVar2 == 0) {
      return puVar3;
    }
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x1ab,
                 "_memMulticastFabricDescriptorAlloc",4,"NVRM: Failed to track memdesc 0x%x",iVar2);
  }
  _memMulticastFabricDescriptorCleanup_part_0(puVar3);
  return (undefined8 *)0x0;
}


// ===== 00461d30 _memorymulticastfabricCtrlDetachMem =====

int _memorymulticastfabricCtrlDetachMem(long param_1,long param_2,undefined8 param_3,char param_4)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  int local_44;
  long *local_40 [2];
  
  lVar2 = *(long *)(param_2 + 0x228);
  lVar1 = lVar2 + 0x38;
  lVar7 = listHead_IMPL(lVar1);
  while( true ) {
    if (lVar7 == 0) {
      return 0x26;
    }
    if (param_1 == *(long *)(lVar7 + 8)) break;
    lVar7 = listNext_IMPL(lVar1,lVar7);
  }
  local_44 = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
  cVar5 = rmGpuGroupLockIsOwner(0,2,&local_44);
  if (cVar5 != '\0') {
    iVar6 = btreeSearch(param_3,local_40,*(undefined8 *)(lVar7 + 0x40));
    if (iVar6 != 0) {
      return iVar6;
    }
    lVar1 = *(long *)(lVar2 + 0x68);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pFabricMemDesc != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",0x9fb
                         );
    }
    else {
      lVar2 = *local_40[0];
      lVar8 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(lVar7 + 8) + 0x4a18),
                                 __nvoc_class_def_FABRIC_VASPACE);
      if (lVar8 != 0) {
        fabricvaspaceUnmapPhysMemdesc_IMPL
                  (lVar8,lVar1,local_40[0][1],*(undefined8 *)(*local_40[0] + 0x10));
        if (param_4 != '\0') {
          uVar3 = *(undefined8 *)(lVar2 + 8);
          uVar4 = *(undefined8 *)(*(long *)(param_2 + 0x1f8) + 0x48);
          refRemoveInterMapping(uVar4,uVar3,0);
          refDestroyInterMapping(uVar4,uVar3);
        }
        btreeUnlink(local_40[0],lVar7 + 0x40);
        portMemFree(*local_40[0]);
        return 0;
      }
      nvAssertFailedNoLog("pFabricVAS != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",0x9fe);
    }
    return 0x40;
  }
  return 0x2f;
}


// ===== 00461eed _memMulticastFabricSendInbandTeamSetupRequestV2.cold =====

void _memMulticastFabricSendInbandTeamSetupRequestV2_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R14;
  
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00461f00 _memMulticastFabricSendInbandTeamSetupRequestV2 =====

int _memMulticastFabricSendInbandTeamSetupRequestV2(long param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ulong uVar11;
  ushort uVar12;
  ulong uVar13;
  uint uVar14;
  long local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  puVar7 = (undefined2 *)portMemAllocNonPaged(0x1404);
  if (puVar7 == (undefined2 *)0x0) {
    return 0x51;
  }
  sVar4 = mapCount_IMPL(param_2 + 200);
  uVar12 = sVar4 + 1;
  iVar5 = (*(int *)(param_2 + 0xa4) + 3 + (uint)uVar12) * 8;
  uVar6 = iVar5 + 0x1c;
  if (uVar6 < 0x1401) {
    portMemSet(puVar7,0,uVar6);
    *(undefined8 *)(puVar7 + 0xe) = *(undefined8 *)(param_2 + 0x90);
    uVar1 = *(undefined4 *)(param_2 + 0xa4);
    puVar7[0x19] = uVar12;
    puVar7[0x18] = (short)uVar1;
    lVar8 = listHead_IMPL(param_2 + 0x38);
    if (lVar8 == 0) {
      uVar11 = 0;
    }
    else {
      uVar13 = 0;
      do {
        uVar11 = (ulong)((int)uVar13 + 1);
        *(undefined8 *)(puVar7 + uVar13 * 4 + 0x1a) = *(undefined8 *)(lVar8 + 0x10);
        lVar8 = listNext_IMPL(param_2 + 0x38);
        uVar13 = uVar11;
      } while (lVar8 != 0);
    }
    uVar9 = mapFindLEQ_IMPL(param_2 + 200,0xffffffffffffffff);
    uVar10 = mapFindGEQ_IMPL(param_2 + 200,0);
    mapIterRange_IMPL(&local_98,param_2 + 200,uVar10,uVar9);
    local_78 = local_98;
    local_70 = local_90;
    local_68 = local_88;
    local_60 = local_80;
    do {
      cVar3 = mapIterNext_IMPL(&local_78);
      lVar8 = local_78;
      while( true ) {
        local_78 = lVar8;
        if (cVar3 == '\0') {
          uVar14 = (int)uVar11 + 1;
          *(undefined8 *)(puVar7 + uVar11 * 4 + 0x1a) = *(undefined8 *)(param_2 + 0x80);
          uVar9 = mapFindLEQ_IMPL(param_2 + 200,0xffffffffffffffff);
          uVar10 = mapFindGEQ_IMPL(param_2 + 200,0);
          mapIterRange_IMPL(&local_98,param_2 + 200,uVar10,uVar9);
          local_78 = local_98;
          local_70 = local_90;
          local_68 = local_88;
          local_60 = local_80;
          goto LAB_00462190;
        }
        uVar9 = mapFindLEQ_IMPL(lVar8,0xffffffffffffffff);
        uVar10 = mapFindGEQ_IMPL(lVar8,0);
        multimapItemIterRange_IMPL(&local_98,param_2 + 200,uVar10,uVar9);
        local_58 = local_98;
        local_50 = local_90;
        local_48 = local_88;
        local_40 = local_80;
        cVar3 = multimapItemIterNext_IMPL(&local_58);
        uVar13 = uVar11;
        if (cVar3 == '\0') break;
        do {
          if (local_58 == 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          uVar11 = (ulong)((int)uVar13 + 1);
          *(undefined8 *)(puVar7 + uVar13 * 4 + 0x1a) =
               *(undefined8 *)(local_58 + 8 + (long)*(int *)(param_2 + 0xe8));
          cVar3 = multimapItemIterNext_IMPL(&local_58);
          uVar13 = uVar11;
        } while (cVar3 != '\0');
        cVar3 = mapIterNext_IMPL(&local_78);
        lVar8 = local_78;
      }
    } while( true );
  }
  iVar5 = 0x1a;
  nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x2a3);
LAB_004622c4:
  portMemFree(puVar7);
  return iVar5;
LAB_00462190:
  cVar3 = mapIterNext_IMPL(&local_78);
  lVar8 = local_78;
  while( true ) {
    local_78 = lVar8;
    if (cVar3 == '\0') {
      if ((uint)(ushort)puVar7[0x18] + (uint)uVar12 == uVar14) {
        *(uint *)(puVar7 + 0xa00) = uVar6;
        uVar9 = *(undefined8 *)(param_2 + 0x80);
        puVar7[7] = 5;
        *(undefined8 *)(puVar7 + 1) = uVar9;
        *puVar7 = 0xadbc;
        *(undefined4 *)(puVar7 + 5) = 0;
        *(int *)(puVar7 + 8) = iVar5;
        *(undefined8 *)(puVar7 + 10) = 0;
        iVar5 = knvlinkSendInbandData_IMPL(param_1,*(undefined8 *)(param_1 + 0x1ce8),puVar7);
        if (iVar5 == 0) {
          *(undefined1 *)(param_2 + 0x7c) = 1;
        }
      }
      else {
        iVar5 = 0x40;
        nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x2e0);
      }
      goto LAB_004622c4;
    }
    uVar9 = mapFindLEQ_IMPL(lVar8,0xffffffffffffffff);
    uVar10 = mapFindGEQ_IMPL(lVar8,0);
    multimapItemIterRange_IMPL(&local_98,param_2 + 200,uVar10,uVar9);
    local_58 = local_98;
    local_50 = local_90;
    local_48 = local_88;
    local_40 = local_80;
    cVar3 = multimapItemIterNext_IMPL(&local_58);
    if (cVar3 == '\0') break;
    uVar11 = (ulong)uVar14;
    uVar14 = uVar14 + 1;
    *(undefined8 *)(puVar7 + uVar11 * 4 + 0x1a) = *(undefined8 *)(local_58 + 0x18);
    cVar3 = mapIterNext_IMPL(&local_78);
    lVar8 = local_78;
  }
  goto LAB_00462190;
}


// ===== 00462340 _memMulticastFabricSendInbandTeamSetupRequestV1 =====

int _memMulticastFabricSendInbandTeamSetupRequestV1(long param_1,long param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  int iVar3;
  undefined2 *puVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  
  puVar4 = (undefined2 *)portMemAllocNonPaged(0x1404);
  if (puVar4 != (undefined2 *)0x0) {
    iVar3 = *(int *)(param_2 + 0xa4) * 8;
    uVar6 = iVar3 + 0x32;
    if (0x1400 < uVar6) {
      nvAssertFailedNoLog("(NvU32)sendDataSize <= sizeof(sendDataParams->buffer)",
                          "src/kernel/mem_mgr/mem_multicast_fabric.c",0x31b);
    }
    uVar7 = 0;
    portMemSet(puVar4,0,uVar6);
    *(undefined8 *)(puVar4 + 0xe) = *(undefined8 *)(param_2 + 0x90);
    puVar4[0x18] = (short)*(undefined4 *)(param_2 + 0xa4);
    lVar5 = listHead_IMPL(param_2 + 0x38);
    uVar2 = 0;
    while (lVar5 != 0) {
      uVar7 = (int)uVar2 + 1;
      *(undefined8 *)(puVar4 + uVar2 * 4 + 0x19) = *(undefined8 *)(lVar5 + 0x10);
      lVar5 = listNext_IMPL(param_2 + 0x38);
      uVar2 = (ulong)uVar7;
    }
    if ((ushort)puVar4[0x18] != uVar7) {
      nvAssertFailedNoLog("idx == pMcTeamSetupReq->numGpuHandles",
                          "src/kernel/mem_mgr/mem_multicast_fabric.c",0x327);
    }
    *(uint *)(puVar4 + 0xa00) = uVar6;
    uVar1 = *(undefined8 *)(param_2 + 0x80);
    puVar4[7] = 2;
    *(undefined4 *)(puVar4 + 5) = 0;
    *(undefined8 *)(puVar4 + 1) = uVar1;
    *puVar4 = 0xadbc;
    *(undefined8 *)(puVar4 + 10) = 0;
    *(int *)(puVar4 + 8) = iVar3 + 0x16;
    iVar3 = knvlinkSendInbandData_IMPL(param_1,*(undefined8 *)(param_1 + 0x1ce8),puVar4);
    if (iVar3 == 0) {
      *(undefined1 *)(param_2 + 0x7c) = 1;
    }
    portMemFree(puVar4);
    return iVar3;
  }
  return 0x51;
}


// ===== 004624f0 _memMulticastFabricSendInbandTeamReleaseRequestV1 =====

undefined4 _memMulticastFabricSendInbandTeamReleaseRequestV1(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined2 *)portMemAllocNonPaged(0x1404);
  if (puVar2 != (undefined2 *)0x0) {
    portMemSet(puVar2,0,0x30);
    *(undefined8 *)(puVar2 + 0xe) = param_2;
    uVar3 = osGetTimestamp();
    *(undefined8 *)(puVar2 + 9) = 0;
    *(undefined8 *)(puVar2 + 1) = uVar3;
    *puVar2 = 0xadbc;
    puVar2[0xd] = 0;
    *(undefined8 *)(puVar2 + 5) = 0x14000400000000;
    *(undefined4 *)(puVar2 + 0xa00) = 0x30;
    uVar1 = knvlinkSendInbandData_IMPL(param_1,*(undefined8 *)(param_1 + 0x1ce8),puVar2);
    portMemFree(puVar2);
    return uVar1;
  }
  return 0x51;
}


// ===== 004625c0 _memMulticastFabricSendInbandTeamSetupRequest =====

undefined8 _memMulticastFabricSendInbandTeamSetupRequest(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulong local_20;
  
  uVar1 = gpuFabricProbeGetfmCaps(*(undefined8 *)(param_1 + 0x4c0),&local_20);
  if ((int)uVar1 == 0) {
    if ((local_20 & 0x20) != 0) {
      uVar1 = _memMulticastFabricSendInbandTeamSetupRequestV2(param_1,param_2);
      return uVar1;
    }
    uVar1 = 0x56;
    if ((local_20 & 1) != 0) {
      uVar1 = _memMulticastFabricSendInbandTeamSetupRequestV1(param_1,param_2);
      return uVar1;
    }
  }
  return uVar1;
}


// ===== 00462640 _memMulticastFabricSendInbandRequest =====

undefined8 _memMulticastFabricSendInbandRequest(long param_1,long param_2,int param_3)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  int local_34;
  byte local_30 [16];
  
  if (param_1 != 0) {
    local_34 = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
    cVar2 = rmGpuGroupLockIsOwner(0,2,&local_34);
    if (cVar2 == '\0') {
      nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x3b6);
      uVar3 = 0x40;
    }
    else if (param_3 == 1) {
      lVar1 = *(long *)(param_2 + 0x70);
      uVar3 = 0;
      if (lVar1 != 0) {
        uVar3 = gpuFabricProbeGetfmCaps(*(undefined8 *)(param_1 + 0x4c0),local_30);
        if (((int)uVar3 == 0) && (uVar3 = 0x56, (local_30[0] & 2) != 0)) {
          uVar3 = _memMulticastFabricSendInbandTeamReleaseRequestV1(param_1,lVar1);
        }
      }
    }
    else {
      uVar3 = _memMulticastFabricSendInbandTeamSetupRequest(param_1,param_2);
    }
    return uVar3;
  }
  return 0x56;
}


// ===== 00462710 _memMulticastFabricDescriptorFree =====

void _memMulticastFabricDescriptorFree(long *param_1)

{
  undefined2 uVar1;
  undefined8 uVar2;
  bool bVar3;
  ulong uVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  undefined4 local_ac;
  long local_a8;
  undefined8 local_a0;
  code *local_98;
  long local_90;
  code *local_88;
  int local_80;
  long local_78;
  undefined2 local_70;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  lVar7 = *(long *)(g_pSys + 0x260);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar7 + 0x50));
  portSyncRwLockAcquireWrite(param_1[0x20]);
  *param_1 = *param_1 + -1;
  if (*param_1 == 0) {
    if ((*(byte *)(param_1 + 0x14) & 1) != 0) {
      lVar11 = param_1[0x18];
      if (lVar11 == 0) {
        nvAssertFailedNoLog("pMulticastFabricDesc->cacheKey != 0",
                            "src/kernel/mem_mgr/mem_multicast_fabric.c",0x43a);
        lVar11 = param_1[0x18];
      }
      fabricImportCacheDelete_IMPL(lVar7,param_1 + 0x16,lVar11);
    }
    fabricMulticastSetupCacheDelete_IMPL(lVar7,param_1[0x10]);
    if (*(char *)((long)param_1 + 0x7c) != '\0') {
      local_a8 = 0;
      iVar6 = threadStateGetCurrent(&local_a8,0);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"threadStateGetCurrent(&pThreadNode, NULL)",
                   "src/kernel/mem_mgr/mem_multicast_fabric.c",0x453);
      }
      if ((*(byte *)(local_a8 + 0x3d) & 6) == 0) {
        local_a0 = 0;
        iVar6 = osAllocWaitQueue(&local_a0);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,"osAllocWaitQueue(&pWq)","src/kernel/mem_mgr/mem_multicast_fabric.c",
                     0x464);
        }
        if (local_a0 != 0) {
          iVar6 = fabricMulticastCleanupCacheInsert_IMPL(lVar7,param_1[0x10]);
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,
                       "fabricMulticastCleanupCacheInsert(pFabric, pMulticastFabricDesc->inbandReqId, pWq)"
                       ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x468);
          }
          local_90 = param_1[0x10];
          local_88 = fabricMulticastWaitOnTeamCleanupCallback;
          iVar6 = threadStateEnqueueCallbackOnFree(local_a8,&local_90);
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,"threadStateEnqueueCallbackOnFree(pThreadNode, &freeCallback)",
                       "src/kernel/mem_mgr/mem_multicast_fabric.c",0x470);
          }
        }
      }
    }
    portSyncRwLockReleaseWrite(param_1[0x20]);
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0x50));
    cVar5 = rmGpuLockIsOwner();
    if (cVar5 == '\0') {
      local_ac = 0xffffffff;
      iVar6 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_ac);
      if (iVar6 == 0) {
        bVar3 = true;
      }
      else {
        nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x48a);
        bVar3 = false;
      }
    }
    else {
      bVar3 = false;
    }
    if (param_1[0xd] != 0) {
      lVar7 = listHead_IMPL(param_1 + 7);
      if ((char)param_1[0xc] == '\0') {
        nvAssertFailedNoLog("pMulticastFabricDesc->bMemdescInstalled",
                            "src/kernel/mem_mgr/mem_multicast_fabric.c",0x493);
      }
      if (lVar7 == 0) {
        nvAssertFailedNoLog("pNode != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",0x494);
      }
      lVar11 = param_1[0xd];
      if (lVar11 == 0) {
        nvAssertFailedNoLog("pFabricMemDesc != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",
                            0x3f0);
      }
      else {
        for (lVar8 = listHead_IMPL(param_1 + 7); lVar8 != 0;
            lVar8 = listNext_IMPL(param_1 + 7,lVar8)) {
          lVar9 = *(long *)(lVar8 + 8);
          uVar4 = (ulong)local_a0 >> 0x20;
          local_a0 = CONCAT44((int)uVar4,1 << ((byte)*(undefined4 *)(lVar9 + 0x7a4) & 0x1f));
          cVar5 = rmGpuGroupLockIsOwner(0,2,&local_a0);
          if (cVar5 == '\0') {
            nvAssertFailedNoLog("rmGpuGroupLockIsOwner(0, GPU_LOCK_GRP_MASK, &gpuMask)",
                                "src/kernel/mem_mgr/mem_multicast_fabric.c",0x3f9);
          }
          lVar9 = __nvoc_dynamicCast(*(undefined8 *)(lVar9 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                    );
          if (lVar9 == 0) {
            nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x3fe);
          }
          else {
            btreeEnumStart(0,&local_90,*(undefined8 *)(lVar8 + 0x40));
            if (local_90 != 0) {
              nvAssertFailedNoLog("pMemNode == NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",
                                  0x404);
            }
            if (*(char *)(lVar8 + 0x18) != '\0') {
              fabricvaspaceBatchFree_IMPL(lVar9,lVar11 + 0x170,1,1);
              *(undefined1 *)(lVar8 + 0x18) = 0;
            }
          }
        }
      }
      _memMulticastFabricSendInbandRequest(*(undefined8 *)(lVar7 + 8),param_1,1);
    }
    local_a8 = 0;
    iVar6 = threadStateGetCurrent(&local_a8,0);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,"threadStateGetCurrent(&pThreadNode, NULL)",
                 "src/kernel/mem_mgr/mem_multicast_fabric.c",0x252);
    }
    while (plVar10 = (long *)listHead_IMPL(param_1 + 7), plVar10 != (long *)0x0) {
      if ((*(byte *)(param_1 + 0x14) & 1) != 0) {
        uVar2 = *(undefined8 *)(g_pSys + 0x260);
        iVar6 = (int)param_1[0x1f];
        uVar12 = uVar2;
        if (iVar6 == -1) {
          nvAssertFailedNoLog("pMulticastFabricDesc->imexChannel != -1",
                              "src/kernel/mem_mgr/mem_multicast_fabric.c",0x25f);
          iVar6 = (int)param_1[0x1f];
          uVar12 = *(undefined8 *)(g_pSys + 0x260);
        }
        uVar1 = *(undefined2 *)((long)param_1 + 0xac);
        lVar7 = plVar10[7];
        local_90 = CONCAT71(local_90._1_7_,1);
        local_80 = iVar6;
        local_88 = (code *)fabricGenerateEventId_IMPL(uVar12);
        local_78 = lVar7;
        local_70 = uVar1;
        iVar6 = fabricPostEventsV2_IMPL(uVar2,&local_90,1);
        if (iVar6 != 0) {
          nvCheckFailedNoLog(3,"fabricPostEventsV2(pFabric, &unimportEvent, 1) == NV_OK",
                             "src/kernel/mem_mgr/mem_multicast_fabric.c",0x266);
        }
      }
      local_98 = osReleaseGpuOsInfo;
      local_a0 = *plVar10;
      iVar6 = threadStateEnqueueCallbackOnFree(local_a8,&local_a0);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,"threadStateEnqueueCallbackOnFree(pThreadNode, &freeCallback)",
                   "src/kernel/mem_mgr/mem_multicast_fabric.c",0x26d);
      }
      listRemove_IMPL(param_1 + 7,plVar10);
    }
    *(undefined4 *)(param_1 + 6) = 0;
    *(undefined4 *)(param_1 + 0x15) = 0;
    if (bVar3) {
      rmGpuGroupLockRelease(local_ac,0);
    }
    _memMulticastFabricDescriptorCleanup_part_0(param_1);
    return;
  }
  portSyncRwLockReleaseWrite(param_1[0x20]);
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0x50));
  return;
}


// ===== 00462d7a _memMulticastFabricConstruct.cold =====

void _memMulticastFabricConstruct_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00462d90 _memMulticastFabricConstruct =====

int _memMulticastFabricConstruct(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  short sVar7;
  undefined2 uVar8;
  int iVar9;
  long lVar10;
  ulong uVar11;
  long *plVar12;
  long local_48;
  long local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  uVar2 = *(undefined8 *)(param_1 + 0x210);
  lVar3 = *(long *)(param_3 + 0x10);
  lVar10 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),
                              __nvoc_class_def_RmClient);
  if ((*(byte *)(lVar3 + 0x40) & 1) == 0) {
    plVar12 = (long *)_memMulticastFabricDescriptorAlloc_isra_0(lVar3);
    if (plVar12 != (long *)0x0) goto LAB_00462ecc;
  }
  else {
    if (*(int *)(lVar10 + 600) == -1) {
      return 0x1b;
    }
    sVar7 = memoryExportGetNodeId(lVar3);
    if (sVar7 == -1) {
      return 0x56;
    }
    uVar1 = *(undefined4 *)(lVar10 + 600);
    lVar4 = *(long *)(g_pSys + 0x260);
    portMemCopy(&local_48,0x10,lVar3,0x10);
    uVar11 = (ulong)*(ushort *)(lVar3 + 0x20) | 0xffffffffffff0000;
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar4 + 0x50));
    plVar12 = (long *)fabricImportCacheGet_IMPL(lVar4,&local_48,uVar11);
    if (plVar12 != (long *)0x0) {
      portSyncRwLockAcquireWrite(plVar12[0x20]);
      if ((*(byte *)(plVar12 + 0x14) & 1) == 0) {
        nvAssertFailedNoLog("!_memMulticastFabricIsPrime(pMulticastFabricDesc->allocFlags)",
                            "src/kernel/mem_mgr/mem_multicast_fabric.c",0x4e7);
      }
      *plVar12 = *plVar12 + 1;
      portSyncRwLockReleaseWrite(plVar12[0x20]);
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar4 + 0x50));
LAB_00462ecc:
      portSyncRwLockAcquireWrite(plVar12[0x20]);
      if (((*(byte *)(lVar3 + 0x40) & 1) == 0) || ((int)plVar12[0x1f] == *(int *)(lVar10 + 600))) {
        iVar9 = _memMulticastFabricDescriptorEnqueueWait
                          (*param_3,plVar12,*(undefined8 *)(lVar3 + 0x48),uVar2);
        if (iVar9 == 0) {
          *(long **)(param_1 + 0x228) = plVar12;
          *(undefined2 *)(param_1 + 0x220) = *(undefined2 *)((long)plVar12 + 0xac);
          *(byte *)(param_1 + 0x222) = *(byte *)(plVar12 + 0x14) & 1;
          portSyncRwLockReleaseWrite(plVar12[0x20]);
          return 0;
        }
      }
      else {
        iVar9 = 0x1b;
      }
      portSyncRwLockReleaseWrite(plVar12[0x20]);
      _memMulticastFabricDescriptorFree(plVar12);
      return iVar9;
    }
    plVar12 = (long *)_memMulticastFabricDescriptorAlloc_isra_0(lVar3);
    if (plVar12 == (long *)0x0) {
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar4 + 0x50));
    }
    else {
      *(undefined4 *)((long)plVar12 + 0xa4) = 0xffffffff;
      plVar12[0x12] = 0;
      lVar5 = *(long *)(lVar3 + 0x38);
      plVar12[0x13] = lVar5;
      plVar12[0x11] = lVar5;
      uVar8 = memoryExportGetNodeId(lVar3);
      *(undefined2 *)((long)plVar12 + 0xac) = uVar8;
      plVar12[0x17] = local_40;
      plVar12[0x16] = local_48;
      plVar12[0x18] = uVar11;
      *(undefined2 *)((long)plVar12 + 0xae) = *(undefined2 *)(lVar3 + 0x20);
      *(undefined4 *)(plVar12 + 0x1f) = uVar1;
      iVar9 = fabricImportCacheInsert_IMPL(lVar4,&local_48,uVar11,plVar12);
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar4 + 0x50));
      if (iVar9 == 0) goto LAB_00462ecc;
    }
    _memMulticastFabricDescriptorFree(plVar12);
  }
  return 0x51;
}


// ===== 00463070 _memMulticastFabricCreateMemDesc =====

int _memMulticastFabricCreateMemDesc(long param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long local_30;
  
  local_30 = 0;
  iVar1 = memdescCreate(&local_30,0,*(undefined8 *)(param_1 + 0x90),0,1,7,1,0);
  if (iVar1 == 0) {
    memdescSetPte(local_30,1,0,param_2);
    memdescSetPageSize(local_30,1,*(undefined8 *)(param_1 + 0x98));
    *(undefined4 *)(local_30 + 0x84) = 0xf;
    memdescSetFlag(local_30,2,1);
    memdescSetGpuCacheAttrib(local_30,1);
    *param_3 = local_30;
    return 0;
  }
  nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x58a,"_memMulticastFabricCreateMemDesc",
               4,"NVRM: Failed to allocate memory descriptor for multicast object\n");
  return iVar1;
}


// ===== 00463170 memorymulticastfabricTeamSetupResponseCallback =====

undefined8
memorymulticastfabricTeamSetupResponseCallback(undefined4 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  ulong local_70;
  ulong local_68;
  long local_60;
  int local_4c;
  long local_48;
  byte local_40;
  undefined7 uStack_3f;
  
  lVar2 = *(long *)(g_pSys + 0x260);
  if (param_3 == 0) {
    nvAssertFailedNoLog("pInbandRcvParams != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",0x67f
                       );
    cVar6 = rmGpuLockIsOwner();
  }
  else {
    cVar6 = rmGpuLockIsOwner();
  }
  if (cVar6 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/mem_mgr/mem_multicast_fabric.c",0x680);
  }
  lVar9 = gpumgrGetGpu(param_1);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("Invalid GPU instance","src/kernel/mem_mgr/mem_multicast_fabric.c",0x684);
    return 0x1f;
  }
  iVar8 = *(int *)(param_3 + 10);
  uVar14 = *(undefined8 *)(param_3 + 2);
  if (iVar8 == 0) {
    local_60 = *(long *)(param_3 + 0x1c);
    local_68 = *(ulong *)(param_3 + 0x30);
    local_70 = *(ulong *)(param_3 + 0x38);
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x50));
    lVar10 = fabricMulticastSetupCacheGet_IMPL(lVar2,uVar14);
    if (lVar10 == 0) {
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x50));
      if (((local_60 != 0) &&
          (iVar8 = gpuFabricProbeGetfmCaps(*(undefined8 *)(lVar9 + 0x4c0),&local_40), iVar8 == 0))
         && ((local_40 & 2) != 0)) {
        _memMulticastFabricSendInbandTeamReleaseRequestV1(lVar9,local_60);
      }
      goto LAB_004635e0;
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar10 + 0x100));
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x50));
    if (*(char *)(lVar10 + 0x7d) != '\0') goto LAB_0046321e;
    *(undefined1 *)(lVar10 + 0x7c) = 0;
    local_48 = 0;
  }
  else {
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar2 + 0x50));
    lVar10 = fabricMulticastSetupCacheGet_IMPL(lVar2,uVar14);
    if (lVar10 == 0) {
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x50));
LAB_004635e0:
      fabricMulticastCleanupCacheInvokeCallback_IMPL(lVar2,uVar14,fabricWakeUpThreadCallback);
      return 0;
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar10 + 0x100));
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar2 + 0x50));
    if (*(char *)(lVar10 + 0x7d) != '\0') goto LAB_0046321e;
    *(undefined1 *)(lVar10 + 0x7c) = 0;
    local_48 = 0;
    if (iVar8 == 0x55) {
      nvAssertFailedNoLog("mcTeamStatus != NV_ERR_NOT_READY",
                          "src/kernel/mem_mgr/mem_multicast_fabric.c",0x618);
    }
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
  }
  iVar7 = *(int *)(lVar10 + 0x78);
  if (iVar7 == 0x55) {
    if ((*(byte *)(lVar10 + 0xa0) & 1) == 0) {
      if (iVar8 == 3) {
        iVar7 = _memMulticastFabricSendInbandRequest(lVar9,lVar10,0);
        if (iVar7 != 0) {
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x634,
                       "_memMulticastFabricAttachGpuPostProcessor",4,"NVRM: MCFLA retry failed %x\n"
                       ,iVar7);
          local_68 = 0;
          goto LAB_004636db;
        }
        goto LAB_00463300;
      }
      if (iVar8 != 0) goto LAB_004636d0;
      if (*(ulong *)(lVar10 + 0x90) <= local_70) goto LAB_00463342;
      iVar7 = 0x1a;
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x647,
                   "_memMulticastFabricAttachGpuPostProcessor",4,
                   "NVRM: Insufficient mcAddressSize returned from Fabric Manager\n");
      local_68 = 0;
    }
    else {
      if (iVar8 != 0) {
LAB_004636d0:
        local_68 = 0;
        iVar7 = iVar8;
        goto LAB_004636db;
      }
      *(ulong *)(lVar10 + 0x90) = local_70;
LAB_00463342:
      if ((local_68 & *(long *)(lVar10 + 0x98) - 1U) == 0) {
        iVar7 = _memMulticastFabricCreateMemDesc(lVar10,local_68,&local_48);
        lVar2 = local_48;
        local_68 = local_48;
        if (iVar7 == 0) {
          lVar1 = lVar10 + 0x38;
          for (lVar11 = listHead_IMPL(lVar1); lVar11 != 0; lVar11 = listNext_IMPL(lVar1,lVar11)) {
            lVar5 = *(long *)(lVar11 + 8);
            local_4c = 1 << ((byte)*(undefined4 *)(lVar5 + 0x7a4) & 0x1f);
            cVar6 = rmGpuGroupLockIsOwner(0,2,&local_4c);
            if (cVar6 == '\0') {
              iVar7 = 0x40;
              nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x5c8);
              lVar11 = listHead_IMPL(lVar1);
joined_r0x004638b8:
              if (lVar11 != 0) {
                do {
                  if (*(char *)(lVar11 + 0x18) != '\0') {
                    uVar14 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(lVar11 + 8) + 0x4a18),
                                                __nvoc_class_def_FABRIC_VASPACE);
                    fabricvaspaceBatchFree_IMPL(uVar14,lVar2 + 0x170,1,1);
                    *(undefined1 *)(lVar11 + 0x18) = 0;
                  }
                  lVar11 = listNext_IMPL(lVar1,lVar11);
                } while (lVar11 != 0);
              }
              nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x65f,
                           "_memMulticastFabricAttachGpuPostProcessor",4,
                           "NVRM: Failed to allocate fabric VAS\n");
              memdescDestroy(lVar2);
              local_68 = 0;
              goto LAB_00463560;
            }
            lVar12 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 0x4a18),
                                        __nvoc_class_def_FABRIC_VASPACE);
            if (lVar12 == 0) {
              iVar7 = 0x40;
LAB_004638c9:
              lVar11 = listHead_IMPL(lVar1);
              goto joined_r0x004638b8;
            }
            iVar7 = gpuFabricProbeGetGpuFabricHandle(*(undefined8 *)(lVar5 + 0x4c0),&local_40);
            if ((iVar7 != 0) || (*(long *)(lVar11 + 0x10) != CONCAT71(uStack_3f,local_40))) {
              iVar7 = 0x26;
              nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x5dc,
                           "_memorymulticastFabricAllocVas",4,
                           "NVRM: Attached GPU\'s probe handle is stale\n");
              lVar11 = listHead_IMPL(lVar1);
              goto joined_r0x004638b8;
            }
            uVar14 = *(undefined8 *)(lVar10 + 0x90);
            uVar3 = *(undefined8 *)(lVar10 + 0x88);
            uVar4 = *(undefined8 *)(lVar2 + 0x170);
            uVar13 = memdescGetPageSize(lVar2,1);
            iVar7 = fabricvaspaceAllocMulticast_IMPL(lVar12,uVar13,uVar3,0,uVar4,uVar14);
            if (iVar7 != 0) {
              nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x5e8,
                           "_memorymulticastFabricAllocVas",4,
                           "NVRM: Fabric VA space alloc failed for GPU %d\n",
                           *(undefined4 *)(*(long *)(lVar11 + 8) + 0x7a4));
              goto LAB_004638c9;
            }
            *(undefined1 *)(lVar11 + 0x18) = 1;
          }
          goto LAB_004636db;
        }
        nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x658,
                     "_memMulticastFabricAttachGpuPostProcessor",4,
                     "NVRM: Failed to allocate fabric memdesc\n");
      }
      else {
        iVar7 = 0x1e;
        nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x64f,
                     "_memMulticastFabricAttachGpuPostProcessor",4,
                     "NVRM: Insufficient mcAddressSize returned from Fabric Manager\n");
        local_68 = 0;
      }
    }
LAB_00463560:
    if (*(long *)(lVar10 + 0x68) != 0) goto LAB_00463785;
    *(undefined1 *)(lVar10 + 0x60) = 1;
    *(int *)(lVar10 + 0x78) = iVar7;
    *(ulong *)(lVar10 + 0x68) = local_68;
    *(long *)(lVar10 + 0x70) = local_60;
    _memMulticastFabricDescriptorFlushClients(lVar10);
LAB_0046358c:
    _memMulticastFabricSendInbandRequest(lVar9,lVar10,1);
  }
  else if (iVar7 == 0) {
    nvAssertFailedNoLog("(status != NV_OK)","src/kernel/mem_mgr/mem_multicast_fabric.c",0x625);
    local_68 = 0;
LAB_004636db:
    if (*(long *)(lVar10 + 0x68) != 0) goto LAB_00463785;
    *(undefined1 *)(lVar10 + 0x60) = 1;
    *(int *)(lVar10 + 0x78) = iVar7;
    *(ulong *)(lVar10 + 0x68) = local_68;
    *(long *)(lVar10 + 0x70) = local_60;
    _memMulticastFabricDescriptorFlushClients(lVar10);
  }
  else {
    local_68 = *(long *)(lVar10 + 0x68);
    if (local_68 != 0) {
      local_68 = 0;
LAB_00463785:
      nvAssertFailedNoLog("pMulticastFabricDesc->pMemDesc == NULL",
                          "src/kernel/mem_mgr/mem_multicast_fabric.c",0x5a8);
    }
    *(undefined1 *)(lVar10 + 0x60) = 1;
    *(int *)(lVar10 + 0x78) = iVar7;
    *(ulong *)(lVar10 + 0x68) = local_68;
    *(long *)(lVar10 + 0x70) = local_60;
    _memMulticastFabricDescriptorFlushClients(lVar10);
    if ((iVar7 != 0) && (iVar8 == 0)) goto LAB_0046358c;
  }
LAB_00463300:
  *(bool *)(lVar10 + 0x7d) = *(char *)(lVar10 + 0x7c) == '\0';
LAB_0046321e:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar10 + 0x100));
  return 0;
}


// ===== 00463920 memorymulticastfabricConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 memorymulticastfabricConstruct_IMPL(long *param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (*(long *)(param_3 + 0x58) != 0) {
    uVar2 = (**(code **)(*param_1 + 0x2a8))();
    return uVar2;
  }
  lVar1 = *(long *)(param_3 + 0x40);
  lVar3 = *(long *)(lVar1 + 0x38);
  if (lVar3 == 0) {
    *(undefined8 *)(lVar1 + 0x38) = 0x20000000;
    lVar3 = 0x20000000;
  }
  if (*(long *)(lVar1 + 0x28) == 0) {
    *(long *)(lVar1 + 0x28) = lVar3;
  }
  if ((*(byte *)(lVar1 + 0x40) & 1) == 0) {
    if (lVar3 == *(long *)(lVar1 + 0x28)) {
      if ((*(ulong *)(lVar1 + 0x30) & lVar3 - 1U) == 0) {
        if (*(int *)(lVar1 + 0x44) - 1U < 0xfffffffe) {
          uVar2 = _memMulticastFabricConstruct();
          return uVar2;
        }
        nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x155,
                     "_memMulticastFabricValidateAllocParams",4,
                     "NVRM: Invalid number of GPUs to attach\n");
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x14d,
                     "_memMulticastFabricValidateAllocParams",4,
                     "NVRM: AllocSize should be pageSize aligned\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x146,
                   "_memMulticastFabricValidateAllocParams",4,
                   "NVRM: Alignment must be pageSize for now\n");
    }
    nvCheckOkFailedNoLog
              (4,0x1f,"_memMulticastFabricValidateAllocParams(pAllocParams)",
               "src/kernel/mem_mgr/mem_multicast_fabric.c",0x705);
    return 0x1f;
  }
  uVar2 = _memMulticastFabricConstruct();
  return uVar2;
}


// ===== 00463a50 memorymulticastfabricCtrlAttachGpu_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memorymulticastfabricCtrlAttachGpu_IMPL(long param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  char cVar13;
  ushort uVar14;
  int iVar15;
  long lVar16;
  long lVar17;
  undefined8 *puVar18;
  undefined8 uVar19;
  long lVar20;
  bool bVar21;
  int local_a4;
  long local_a0;
  byte local_98 [8];
  long local_90;
  undefined8 local_88;
  int local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined1 local_4e [30];
  
  lVar5 = *(long *)(param_1 + 0x228);
  iVar15 = subdeviceGetByHandle_IMPL
                     (**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),*param_2,&local_a0);
  if (iVar15 == 0x57) {
    return 0x26;
  }
  if (iVar15 != 0) {
    return iVar15;
  }
  lVar6 = *(long *)(*(long *)(local_a0 + 0x158) + 0xe0);
  local_a4 = 1 << ((byte)*(undefined4 *)(lVar6 + 0x7a4) & 0x1f);
  while( true ) {
    while( true ) {
      portSyncRwLockAcquireRead(*(undefined8 *)(lVar5 + 0x100));
      bVar21 = *(int *)(lVar5 + 0xa4) - *(int *)(lVar5 + 0xa8) == 1;
      portSyncRwLockReleaseRead(*(undefined8 *)(lVar5 + 0x100));
      if ((local_a4 == 0) || (!bVar21)) break;
      iVar15 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_a4);
      if (iVar15 != 0) {
        nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x841);
        return iVar15;
      }
      portSyncRwLockAcquireWrite(*(undefined8 *)(lVar5 + 0x100));
      if (*(int *)(lVar5 + 0xa4) - *(int *)(lVar5 + 0xa8) == 1) {
        bVar21 = true;
        goto LAB_00463bd7;
      }
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0x100));
      rmGpuGroupLockRelease(local_a4,0);
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar5 + 0x100));
    if (bVar21 == (*(int *)(lVar5 + 0xa4) - *(int *)(lVar5 + 0xa8) == 1)) break;
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0x100));
  }
  bVar21 = false;
LAB_00463bd7:
  lVar7 = *(long *)(param_1 + 0x228);
  lVar16 = resservGetTlsCallContext();
  if (param_2[1] != 0) {
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x761,
                 "_memorymulticastfabricCtrlAttachGpu",4,
                 "NVRM: flags passed for attach mem must be zero\n");
LAB_00463e21:
    iVar15 = 0x1f;
    goto LAB_00463d90;
  }
  if (*(int *)(lVar7 + 0xa8) == *(int *)(lVar7 + 0xa4)) {
    iVar15 = 0x38;
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x769,
                 "_memorymulticastfabricCtrlAttachGpu",4,
                 "NVRM: Max no. of GPUs have already attached!\n");
    goto LAB_00463d90;
  }
  if (*(char *)(lVar7 + 0x60) != '\0') {
    iVar15 = 99;
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x76f,
                 "_memorymulticastfabricCtrlAttachGpu",4,"NVRM: The object is already ready.\n");
    goto LAB_00463d90;
  }
  cVar13 = gpuIsCCFeatureEnabled_IMPL(lVar6);
  if (cVar13 != '\0') {
    iVar15 = 0x56;
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x777,
                 "_memorymulticastfabricCtrlAttachGpu",4,
                 "NVRM: Multicast attach not supported on Windows/CC modes\n");
    goto LAB_00463d90;
  }
  cVar13 = (**(code **)(*(long *)(lVar6 + 0x1b78) + 0x2d0))
                     (lVar6,*(long *)(lVar6 + 0x1b78),*(undefined8 *)(lVar7 + 0x98),1);
  if (cVar13 == '\0') {
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x77f,
                 "_memorymulticastfabricCtrlAttachGpu",4,"NVRM: Unsupported pageSize: 0x%llx.\n",
                 *(undefined8 *)(lVar7 + 0x98));
    goto LAB_00463e21;
  }
  lVar16 = *(long *)(lVar16 + 0x48);
  lVar20 = *(long *)(param_1 + 0x228);
  local_90 = 0;
  iVar15 = subdeviceGetByHandle_IMPL
                     (**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),
                      **(undefined4 **)(lVar16 + 0x10),&local_90);
  if (iVar15 == 0) {
    lVar8 = *(long *)(*(long *)(local_90 + 0x158) + 0xe0);
    cVar13 = osMatchGpuOsInfo(lVar8,*(undefined8 *)(lVar16 + 0x50));
    if (cVar13 == '\0') {
      iVar15 = 0x26;
    }
    else {
      lVar20 = lVar20 + 0x38;
      lVar17 = listHead_IMPL(lVar20);
      while (lVar17 != 0) {
        if (lVar8 == *(long *)(lVar17 + 8)) {
          iVar15 = 0x19;
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x236,
                       "_memMulticastFabricGpuInfoAdd",4,"NVRM: GPU %x has already attached\n",
                       *(undefined4 *)(lVar8 + 0x7a4));
          goto LAB_00463d2d;
        }
        lVar17 = listNext_IMPL(lVar20);
      }
      puVar18 = (undefined8 *)listAppendNew_IMPL(lVar20);
      if (puVar18 != (undefined8 *)0x0) {
        *puVar18 = *(undefined8 *)(lVar16 + 0x50);
        uVar19 = *(undefined8 *)(*(long *)(local_90 + 0x158) + 0xe0);
        puVar18[8] = 0;
        *(undefined1 *)(puVar18 + 3) = 0;
        puVar18[1] = uVar19;
        lVar16 = listTail_IMPL(lVar7 + 0x38);
        iVar15 = gpuFabricProbeGetGpuFabricHandle(*(undefined8 *)(lVar6 + 0x4c0),lVar16 + 0x10);
        if (iVar15 == 0) {
          iVar15 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(lVar6 + 0x4c0),lVar16 + 0x20);
          if (iVar15 == 0) {
            uVar14 = 0;
            if (*(long *)(lVar6 + 0x1ce8) != 0) {
              uVar14 = (ushort)*(byte *)(*(long *)(lVar6 + 0x1ce8) + 0x16c0);
            }
            *(ushort *)(lVar16 + 0x30) = uVar14;
            uVar19 = knvlinkGetBWModeEpoch_IMPL(lVar6,*(undefined8 *)(lVar6 + 0x1ce8));
            *(undefined8 *)(lVar16 + 0x28) = uVar19;
            iVar15 = _memorymulticastfabricValidateNvlAttr
                               (lVar7,*(undefined4 *)(lVar16 + 0x20),*(undefined2 *)(lVar16 + 0x30),
                                uVar19);
            if (iVar15 == 0) {
              lVar20 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 0x4a18),
                                          __nvoc_class_def_FABRIC_VASPACE);
              if (lVar20 == 0) {
                iVar15 = 0x56;
                nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7b1,
                             "_memorymulticastfabricCtrlAttachGpu",4,
                             "NVRM: Fabric vaspace object not available for GPU %x\n",
                             *(undefined4 *)(lVar6 + 0x7a4));
              }
              else {
                iVar15 = *(int *)(lVar7 + 0xa8) + 1;
                if (iVar15 == *(int *)(lVar7 + 0xa4)) {
                  if ((*(uint *)(lVar7 + 0xa0) & 1) != 0) {
                    nvAssertFailedNoLog("_memMulticastFabricIsPrime(pMulticastFabricDesc->allocFlags)"
                                        ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x7bb);
                  }
                  iVar15 = _memMulticastFabricSendInbandRequest(lVar6,lVar7,0);
                  if (iVar15 == 0) {
LAB_004640c4:
                    iVar15 = *(int *)(lVar7 + 0xa8) + 1;
                    goto LAB_00463f97;
                  }
                  nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7c2,
                               "_memorymulticastfabricCtrlAttachGpu",4,
                               "NVRM: Inband request Multicast Team Setup failed!\n");
                }
                else {
                  if ((*(uint *)(lVar7 + 0xa0) & 1) == 0) {
LAB_00463f97:
                    *(int *)(lVar7 + 0xa8) = iVar15;
                    *(uint *)(lVar7 + 0x30) =
                         *(uint *)(lVar7 + 0x30) |
                         1 << ((byte)*(undefined4 *)(lVar6 + 0x7a4) & 0x1f);
                    iVar15 = 0;
                    goto LAB_00463d90;
                  }
                  uVar19 = *(undefined8 *)(g_pSys + 0x260);
                  iVar15 = gpuFabricProbeGetfmCaps(*(undefined8 *)(lVar6 + 0x4c0),local_98);
                  if (iVar15 == 0) {
                    if ((local_98[0] & 0x20) == 0) {
                      iVar15 = 0x56;
                      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7d8,
                                   "_memorymulticastfabricCtrlAttachGpu",4,
                                   "NVRM: Remote attach is supported from V2+\n");
                    }
                    else if (*(int *)(lVar7 + 0xf8) == -1) {
                      iVar15 = 0x40;
                      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7df,
                                   "_memorymulticastfabricCtrlAttachGpu",4,
                                   "NVRM: IMEX channel subscription is not available\n");
                    }
                    else {
                      uVar9 = *(undefined8 *)(lVar7 + 0x98);
                      uVar1 = *(undefined2 *)(lVar7 + 0xac);
                      uVar4 = *(undefined4 *)(lVar16 + 0x20);
                      uVar2 = *(undefined2 *)(lVar7 + 0xae);
                      uVar10 = *(undefined8 *)(lVar7 + 0x80);
                      uVar11 = *(undefined8 *)(lVar16 + 0x10);
                      uVar3 = *(undefined2 *)(lVar16 + 0x30);
                      uVar12 = *(undefined8 *)(lVar16 + 0x28);
                      local_90 = CONCAT71(local_90._1_7_,2);
                      local_80 = *(int *)(lVar7 + 0xf8);
                      local_88 = fabricGenerateEventId_IMPL(*(undefined8 *)(g_pSys + 0x260));
                      local_78 = uVar11;
                      local_70 = uVar10;
                      local_68 = uVar12;
                      local_60 = uVar9;
                      local_58 = uVar4;
                      local_54 = CONCAT22(uVar1,uVar2);
                      local_50 = uVar3;
                      portMemCopy(local_4e,0x10,lVar7 + 0xb0,0x10);
                      *(undefined8 *)(lVar16 + 0x38) = local_88;
                      iVar15 = fabricPostEventsV2_IMPL(uVar19,&local_90,1);
                      if (iVar15 == 0) goto LAB_004640c4;
                      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7f5,
                                   "_memorymulticastfabricCtrlAttachGpu",4,
                                   "NVRM: Failed to notify IMEX daemon of import event\n");
                    }
                  }
                  else {
                    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7d2,
                                 "_memorymulticastfabricCtrlAttachGpu",4,
                                 "NVRM: Failed to query IMEX FM caps\n");
                  }
                }
              }
            }
            else {
              iVar15 = 0x26;
              nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x7aa,
                           "_memorymulticastfabricCtrlAttachGpu",4,
                           "NVRM: Clique ID etc. validation failed\n");
            }
          }
          else {
            nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x79a,
                         "_memorymulticastfabricCtrlAttachGpu",4,
                         "NVRM: Attaching GPU does not have a valid clique ID\n");
          }
        }
        else {
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x791,
                       "_memorymulticastfabricCtrlAttachGpu",4,
                       "NVRM: Attaching GPU does not have a valid probe handle\n");
        }
        listRemove_IMPL(lVar7 + 0x38,lVar16);
        goto LAB_00463d90;
      }
      iVar15 = 0x51;
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar15,
               "subdeviceGetByHandle(RES_GET_CLIENT(pMemoryMulticastFabric), pAttachParams->hSubdevice, &pSubdevice)"
               ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x227);
  }
LAB_00463d2d:
  nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x787,
               "_memorymulticastfabricCtrlAttachGpu",4,"NVRM: Failed to populate GPU info\n");
LAB_00463d90:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0x100));
  if (bVar21) {
    rmGpuGroupLockRelease(local_a4,0);
  }
  return iVar15;
}


// ===== 004643e0 memorymulticastfabricCtrlSetFailure_IMPL =====

undefined4 memorymulticastfabricCtrlSetFailure_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x228);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x100));
  uVar2 = _memorymulticastfabricCtrlSetFailure(param_1,param_2);
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x100));
  return uVar2;
}


// ===== 00464430 memorymulticastfabricCtrlAttachRemoteGpu_IMPL =====

int memorymulticastfabricCtrlAttachRemoteGpu_IMPL(long param_1,long *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined4 *puVar8;
  long lVar9;
  bool bVar10;
  long local_68;
  int local_40;
  int local_3c [3];
  
  lVar1 = *(long *)(param_1 + 0x228);
  if (param_2[3] == 0) {
    param_2[3] = 0x20000000;
  }
  while( true ) {
    while( true ) {
      portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x100));
      bVar10 = *(int *)(lVar1 + 0xa4) - *(int *)(lVar1 + 0xa8) == 1;
      lVar5 = listHead_IMPL(lVar1 + 0x38);
      lVar9 = 0;
      local_40 = 0;
      if ((lVar5 != 0) && (lVar9 = *(long *)(lVar5 + 8), local_40 = 0, lVar9 != 0)) {
        local_40 = 1 << ((byte)*(undefined4 *)(lVar9 + 0x7a4) & 0x1f);
      }
      portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x100));
      if ((local_40 == 0) || (!bVar10)) break;
      iVar3 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_40);
      if (iVar3 != 0) {
        nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0x991);
        return iVar3;
      }
      portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x100));
      if (*(int *)(lVar1 + 0xa4) - *(int *)(lVar1 + 0xa8) == 1) {
        bVar10 = true;
        goto LAB_0046458a;
      }
      portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x100));
      rmGpuGroupLockRelease(local_40,0);
    }
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x100));
    if (bVar10 == (*(int *)(lVar1 + 0xa4) - *(int *)(lVar1 + 0xa8) == 1)) break;
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x100));
  }
  bVar10 = false;
LAB_0046458a:
  lVar5 = *(long *)(param_1 + 0x228);
  lVar6 = resservGetTlsCallContext();
  lVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_RmClient);
  if (lVar7 == 0) {
    iVar3 = 0x23;
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/mem_multicast_fabric.c",0x8ce);
    goto LAB_0046471b;
  }
  iVar3 = 0x1b;
  cVar2 = rmclientIsCapableOrAdmin_IMPL(lVar7,4,*(undefined4 *)(lVar6 + 0x28));
  if (cVar2 == '\0') goto LAB_0046471b;
  if ((*(byte *)(lVar5 + 0xa0) & 1) == 0) {
    if (*(int *)(lVar5 + 0xa8) == *(int *)(lVar5 + 0xa4)) {
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x8e4,
                   "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                   "NVRM: Max no. of GPUs have already attached!\n");
      iVar3 = 0x38;
    }
    else if (param_2[3] == *(long *)(lVar5 + 0x98)) {
      iVar3 = _memorymulticastfabricValidateNvlAttr
                        (lVar5,(int)param_2[4],*(undefined2 *)((long)param_2 + 0x26),param_2[2]);
      if (iVar3 == 0) {
        if (*(short *)((long)param_2 + 0x24) == -1) {
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x8fd,
                       "_memorymulticastfabricCtrlAttachRemoteGpu",4,"NVRM: Invalid node ID\n");
          goto LAB_004646fc;
        }
        lVar6 = listHead_IMPL(lVar5 + 0x38);
        while (lVar6 != 0) {
          if (*(long *)(lVar6 + 0x10) == *param_2) {
            nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x908,
                         "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                         "NVRM: GPU is already attached\n");
            goto LAB_004646a8;
          }
          lVar6 = listNext_IMPL(lVar5 + 0x38);
        }
        lVar6 = lVar5 + 200;
        lVar7 = multimapFindSubmap_IMPL(lVar6,*(undefined2 *)((long)param_2 + 0x24));
        if (lVar7 == 0) {
          local_68 = multimapInsertSubmap_IMPL(lVar6,*(undefined2 *)((long)param_2 + 0x24));
          if (local_68 == 0) {
            iVar3 = 0x51;
            goto LAB_00464702;
          }
          puVar8 = (undefined4 *)
                   multimapInsertItemNew_IMPL(lVar6,*(undefined2 *)((long)param_2 + 0x24),*param_2);
          if (puVar8 != (undefined4 *)0x0) goto LAB_0046484c;
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x920,
                       "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                       "NVRM: Failed to track remote GPU info\n");
          multimapRemoveSubmap_IMPL(lVar6,local_68);
        }
        else {
          puVar8 = (undefined4 *)
                   multimapInsertItemNew_IMPL(lVar6,*(undefined2 *)((long)param_2 + 0x24),*param_2);
          if (puVar8 != (undefined4 *)0x0) {
            local_68 = 0;
LAB_0046484c:
            portMemSet(puVar8,0,0x20);
            *(long *)(puVar8 + 6) = param_2[1];
            *puVar8 = (int)param_2[4];
            *(undefined2 *)(puVar8 + 4) = *(undefined2 *)((long)param_2 + 0x26);
            *(long *)(puVar8 + 2) = param_2[2];
            iVar3 = *(int *)(lVar5 + 0xa8) + 1;
            if (iVar3 == *(int *)(lVar5 + 0xa4)) {
              iVar4 = _memMulticastFabricSendInbandRequest(lVar9,lVar5,0);
              if (iVar4 != 0) {
                nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x934,
                             "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                             "NVRM: Inband request Multicast Team Setup failed!\n");
                multimapRemoveItemByKey_IMPL(lVar6,*(undefined2 *)((long)param_2 + 0x24),*param_2);
                if (local_68 != 0) {
                  multimapRemoveSubmap_IMPL(lVar6,local_68);
                }
                iVar3 = 0xffff;
                if (iVar4 != 0x55) {
                  iVar3 = iVar4;
                }
                goto LAB_00464702;
              }
              iVar3 = *(int *)(lVar5 + 0xa8) + 1;
            }
            *(int *)(lVar5 + 0xa8) = iVar3;
            iVar3 = 0;
            goto LAB_0046471b;
          }
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x920,
                       "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                       "NVRM: Failed to track remote GPU info\n");
        }
LAB_004646a8:
        iVar3 = 0x19;
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x8f7,
                     "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                     "NVRM: Clique ID etc. validation failed\n");
        iVar3 = 0x26;
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x8b4,
                   "_memorymulticastfabricValidateFabricAttr",4,
                   "NVRM: Fabric validation failed. Prime and non-prime object page sizes do not match.\n"
                  );
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x8ed,
                   "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                   "NVRM: Page size of remote GPU does not match prime MCLFA object\n");
LAB_004646fc:
      iVar3 = 0x1f;
    }
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0x8db,
                 "_memorymulticastfabricCtrlAttachRemoteGpu",4,
                 "NVRM: Only supported on prime MCLFA object\n");
    iVar3 = 0x56;
  }
LAB_00464702:
  local_3c[0] = iVar3;
  iVar4 = _memorymulticastfabricCtrlSetFailure(param_1,local_3c);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"_memorymulticastfabricCtrlSetFailure(pMemoryMulticastFabric, &params)",
               "src/kernel/mem_mgr/mem_multicast_fabric.c",0x959);
  }
LAB_0046471b:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x100));
  if (bVar10) {
    rmGpuGroupLockRelease(local_40,0);
  }
  return iVar3;
}


// ===== 00464a60 memorymulticastfabricCtrlDetachMem_IMPL =====

ulong memorymulticastfabricCtrlDetachMem_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  int local_34;
  long local_30 [2];
  
  if (param_2[4] != 0) {
    return 0x1f;
  }
  lVar1 = *(long *)(param_1 + 0x228);
  uVar4 = subdeviceGetByHandle_IMPL
                    (**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),*param_2,local_30);
  if ((int)uVar4 != 0x57) {
    if ((int)uVar4 == 0) {
      lVar2 = *(long *)(*(long *)(local_30[0] + 0x158) + 0xe0);
      local_34 = 1 << ((byte)*(undefined4 *)(lVar2 + 0x7a4) & 0x1f);
      uVar3 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_34);
      if (uVar3 == 0) {
        portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x100));
        uVar3 = _memorymulticastfabricCtrlDetachMem(lVar2,param_1,*(undefined8 *)(param_2 + 2),1);
        portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x100));
        rmGpuGroupLockRelease(local_34,0);
        return (ulong)uVar3;
      }
      nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0xa35);
      uVar4 = (ulong)uVar3;
    }
    return uVar4;
  }
  return 0x26;
}


// ===== 00464b90 memorymulticastfabricCtrlAttachMem_IMPL.cold =====

void memorymulticastfabricCtrlAttachMem_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00464ba0 memorymulticastfabricCtrlAttachMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memorymulticastfabricCtrlAttachMem_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  char cVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 *puVar14;
  long lVar15;
  int local_50;
  int local_4c;
  long local_48;
  long local_40 [2];
  
  local_48 = 0;
  lVar1 = *(long *)(param_1 + 0x228);
  if (param_2[8] != 0) {
    return 0x1f;
  }
  iVar10 = subdeviceGetByHandle_IMPL
                     (**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),*param_2,&local_48);
  if (iVar10 == 0x57) {
    return 0x26;
  }
  if (iVar10 == 0) {
    lVar13 = *(long *)(*(long *)(local_48 + 0x158) + 0xe0);
    iVar10 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(param_1 + 0x1f8) + 0x48),param_2[1],
                                 local_40);
    if (iVar10 == 0) {
      plVar2 = *(long **)(local_40[0] + 0x118);
      if (*plVar2 == 0) {
        nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xa63,
                     "_memorymulticastfabricValidatePhysMem",4,
                     "NVRM: Device-less memory isn\'t supported yet\n");
      }
      else {
        cVar9 = (**(code **)(*(long *)(lVar13 + 0x1b78) + 0x2c8))(lVar13);
        if (cVar9 == '\0') {
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xa6a,
                       "_memorymulticastfabricValidatePhysMem",4,
                       "NVRM: Invalid physmem handle passed\n");
        }
        else {
          lVar11 = memdescGetPageSize(plVar2,1);
          lVar8 = local_40[0];
          if ((lVar11 == 0x200000) || (lVar11 == 0x20000000)) {
            local_50 = 1 << ((byte)*(undefined4 *)(lVar13 + 0x7a4) & 0x1f);
            iVar10 = rmGpuGroupLockAcquire(0,2,0,0x2000,&local_50);
            if (iVar10 == 0) {
              portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x100));
              lVar7 = local_48;
              lVar11 = *(long *)(param_1 + 0x228);
              uVar3 = *(undefined8 *)(lVar8 + 0x118);
              local_4c = 1 << ((byte)*(undefined4 *)(lVar13 + 0x7a4) & 0x1f);
              uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x1f8) + 0x48);
              cVar9 = rmGpuGroupLockIsOwner(0,2,&local_4c);
              if (cVar9 == '\0') {
                iVar10 = 0x2f;
              }
              else {
                lVar15 = *(long *)(param_1 + 0x228) + 0x38;
                for (lVar12 = listHead_IMPL(lVar15); lVar12 != 0;
                    lVar12 = listNext_IMPL(lVar15,lVar12)) {
                  if (lVar13 == *(long *)(lVar12 + 8)) {
                    lVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar13 + 0x4a18),
                                                __nvoc_class_def_FABRIC_VASPACE);
                    if (lVar13 == 0) {
                      nvAssertFailedNoLog("pFabricVAS != NULL",
                                          "src/kernel/mem_mgr/mem_multicast_fabric.c",0xa9f);
                    }
                    else {
                      lVar11 = *(long *)(lVar11 + 0x68);
                      if (lVar11 == 0) {
                        nvAssertFailedNoLog("pFabricMemDesc != NULL",
                                            "src/kernel/mem_mgr/mem_multicast_fabric.c",0xaa2);
                      }
                      else {
                        if (*(char *)(lVar12 + 0x18) != '\0') {
                          iVar10 = refCreateInterMapping(uVar4,local_40);
                          if (iVar10 != 0) {
                            nvAssertOkFailedNoLog
                                      (iVar10,
                                       "refCreateInterMapping(pMemoryMulticastFabricRef, &pInterMapping)"
                                       ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0xaa6);
                            goto LAB_00464ef0;
                          }
                          *(undefined8 *)(local_40[0] + 0x70) = 0;
                          if (lVar7 == 0) {
                    /* WARNING: Does not return */
                            pcVar6 = (code *)invalidInstructionException();
                            (*pcVar6)();
                          }
                          iVar10 = refAddInterMapping(uVar4,*(undefined8 *)
                                                             (*(long *)(lVar8 + 0xb8) + 0x48),
                                                      *(undefined8 *)(param_2 + 2),
                                                      *(undefined8 *)
                                                       (*(long *)(lVar7 + 0x140) + 0x48));
                          if (iVar10 != 0) {
                            nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xab2,
                                         "_memorymulticastfabricCtrlAttachMem",4,
                                         "NVRM: Failed to setup inter mapping\n");
                            refDestroyInterMapping(uVar4,local_40[0]);
                            goto LAB_00464ef0;
                          }
                          *(undefined4 *)(local_40[0] + 0x60) = param_2[8];
                          *(undefined8 *)(local_40[0] + 0x78) = uVar3;
                          iVar10 = fabricvaspaceMapPhysMemdesc_IMPL
                                             (lVar13,lVar11,*(undefined8 *)(param_2 + 2),uVar3,
                                              *(undefined8 *)(param_2 + 4),
                                              *(undefined8 *)(param_2 + 6));
                          if (iVar10 == 0) {
                            puVar14 = (undefined8 *)portMemAllocNonPaged(0x50);
                            if (puVar14 == (undefined8 *)0x0) {
                              iVar10 = 0x51;
                            }
                            else {
                              portMemSet(puVar14,0,0x50);
                              uVar5 = *(undefined8 *)(param_2 + 2);
                              puVar14[4] = uVar5;
                              puVar14[5] = uVar5;
                              puVar14[2] = *(undefined8 *)(param_2 + 6);
                              *puVar14 = uVar3;
                              puVar14[3] = puVar14;
                              puVar14[1] = local_40[0];
                              iVar10 = btreeInsert(puVar14 + 3,lVar12 + 0x40);
                              if (iVar10 == 0) goto LAB_00464ef0;
                              nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xada,
                                           "_memorymulticastfabricCtrlAttachMem",4,
                                           "NVRM: Failed to track attach mem info\n");
                              portMemFree(puVar14);
                            }
                            fabricvaspaceUnmapPhysMemdesc_IMPL
                                      (lVar13,lVar11,*(undefined8 *)(param_2 + 2),
                                       *(undefined8 *)(param_2 + 6));
                          }
                          else {
                            nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xac3,
                                         "_memorymulticastfabricCtrlAttachMem",4,
                                         "NVRM: Failed to map FLA\n");
                          }
                          refRemoveInterMapping(uVar4,local_40[0],0);
                          refDestroyInterMapping(uVar4,local_40[0]);
                          goto LAB_00464ef0;
                        }
                        nvAssertFailedNoLog("pGpuInfo->bMcflaAlloc",
                                            "src/kernel/mem_mgr/mem_multicast_fabric.c",0xaa4);
                      }
                    }
                    iVar10 = 0x40;
                    goto LAB_00464ef0;
                  }
                }
                iVar10 = 0x26;
              }
LAB_00464ef0:
              portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x100));
              rmGpuGroupLockRelease(local_50,0);
            }
            else {
              nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0xb1b);
            }
            return iVar10;
          }
          nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xa73,
                       "_memorymulticastfabricValidatePhysMem",4,
                       "NVRM: Physmem page size should be 2MB\n");
        }
      }
      iVar10 = 0x1f;
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xa5b,
                   "_memorymulticastfabricValidatePhysMem",4,"NVRM: Invalid object handle passed\n")
      ;
    }
    nvDbg_Printf("src/kernel/mem_mgr/mem_multicast_fabric.c",0xb0d,
                 "memorymulticastfabricCtrlAttachMem_IMPL",4,
                 "NVRM: Failed to validate physmem handle\n");
  }
  return iVar10;
}


// ===== 00465220 memorymulticastfabricDestruct_IMPL =====

void memorymulticastfabricDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  
  lVar1 = *(long *)(param_1 + 0x228);
  lVar2 = *(long *)(param_1 + 0x210);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x100));
  memDestructCommon_IMPL(lVar2);
  plVar3 = (long *)listHead_IMPL(lVar1 + 8);
  while (plVar4 = plVar3, plVar4 != (long *)0x0) {
    while (plVar3 = (long *)listNext_IMPL(lVar1 + 8,plVar4), lVar2 == plVar4[1]) {
      if (*plVar4 != 0) {
        osDereferenceObjectCount();
      }
      listRemove_IMPL(lVar1 + 8,plVar4);
      plVar4 = plVar3;
      if (plVar3 == (long *)0x0) goto LAB_004652bb;
    }
  }
LAB_004652bb:
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x100));
  _memMulticastFabricDescriptorFree(lVar1);
  return;
}


// ===== 004652e0 memorymulticastfabricUnmapFrom_IMPL =====

int memorymulticastfabricUnmapFrom_IMPL(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int local_2c;
  
  lVar1 = *param_2;
  local_2c = 1 << ((byte)*(undefined4 *)(lVar1 + 0x7a4) & 0x1f);
  cVar3 = rmGpuGroupLockIsOwner(0,2,&local_2c);
  if (cVar3 != '\0') {
    lVar2 = *(long *)(param_1 + 0x228);
    portSyncRwLockAcquireRead(*(undefined8 *)(lVar2 + 0x100));
    iVar4 = _memorymulticastfabricCtrlDetachMem(lVar1,param_1,param_2[3],0);
    if (iVar4 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/mem_multicast_fabric.c",0xb60);
    }
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar2 + 0x100));
    return iVar4;
  }
  nvAssertFailedNoLog(&DAT_00d83185,"src/kernel/mem_mgr/mem_multicast_fabric.c",0xb52);
  return 0x40;
}


// ===== 004653d0 memorymulticastfabricCanCopy_IMPL =====

undefined8 memorymulticastfabricCanCopy_IMPL(void)

{
  return 1;
}


// ===== 004653e0 memorymulticastfabricCopyConstruct_IMPL =====

undefined8 memorymulticastfabricCopyConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  
  lVar2 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                             __nvoc_class_def_MemoryMulticastFabric);
  plVar1 = *(long **)(lVar2 + 0x228);
  portSyncRwLockAcquireWrite(plVar1[0x20]);
  *plVar1 = *plVar1 + 1;
  *(long **)(param_1 + 0x228) = plVar1;
  *(undefined2 *)(param_1 + 0x220) = *(undefined2 *)((long)plVar1 + 0xac);
  *(byte *)(param_1 + 0x222) = *(byte *)(plVar1 + 0x14) & 1;
  portSyncRwLockReleaseWrite(plVar1[0x20]);
  return 0;
}


// ===== 00465460 memorymulticastfabricCtrlGetInfo_IMPL =====

undefined8 memorymulticastfabricCtrlGetInfo_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x228);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x100));
  lVar2 = *(long *)(param_1 + 0x228);
  *param_2 = *(undefined8 *)(lVar2 + 0x88);
  param_2[1] = *(undefined8 *)(lVar2 + 0x90);
  *(int *)(param_2 + 2) = (int)*(undefined8 *)(lVar2 + 0x98);
  *(undefined4 *)((long)param_2 + 0x14) = *(undefined4 *)(lVar2 + 0xa4);
  *(undefined4 *)(param_2 + 3) = *(undefined4 *)(lVar2 + 0xa8);
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x100));
  return 0;
}


// ===== 004654e0 memorymulticastfabricIsReady_IMPL =====

int memorymulticastfabricIsReady_IMPL(long param_1,char param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar2 = *(long *)(param_1 + 0x228);
  lVar3 = *(long *)(param_1 + 0x210);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar2 + 0x100));
  iVar1 = *(int *)(lVar2 + 0x78);
  if ((param_2 != '\0') && (iVar1 == 0x55)) {
    portSyncRwLockReleaseRead(*(undefined8 *)(lVar2 + 0x100));
    return 0;
  }
  if (*(long *)(lVar3 + 0x118) != *(long *)(lVar2 + 0x68)) {
    iVar4 = memConstructCommon_IMPL(lVar3,0xfd,0,*(long *)(lVar2 + 0x68),0,0,0,0,0,0,0,0);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "memConstructCommon(pMemory, NV_MEMORY_MULTICAST_FABRIC, 0, pMulticastFabricDesc->pMemDesc, 0, NULL, 0, 0, 0, 0, NVOS32_MEM_TAG_NONE, NULL)"
                 ,"src/kernel/mem_mgr/mem_multicast_fabric.c",0xbd1);
    }
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar2 + 0x100));
  return iVar1;
}


// ===== 004655b0 memorymulticastfabricCtrlRegisterEvent_IMPL =====

undefined4 memorymulticastfabricCtrlRegisterEvent_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x228);
  portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x100));
  uVar2 = _memMulticastFabricDescriptorEnqueueWait
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x1f8) + 0x48) + 0x48),
                     *(undefined8 *)(param_1 + 0x228),*param_2,*(undefined8 *)(param_1 + 0x210));
  portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x100));
  return uVar2;
}


// ===== 00465620 memorymulticastfabricControl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memorymulticastfabricControl_IMPL(long *param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  ulong uVar2;
  
  if ((*(int *)(param_3 + 8) - 0xfd0106U < 2) || (*(int *)(param_3 + 8) == 0xfd0104)) {
    if (param_1 != (long *)0x0) {
      uVar2 = resControl_IMPL(param_1[0x3f],param_2);
      return uVar2;
    }
    uVar2 = resControl_IMPL(0,param_2);
    return uVar2;
  }
  uVar2 = (**(code **)(*param_1 + 0x2b0))(param_1,0);
  iVar1 = (int)uVar2;
  if (*(int *)(param_3 + 8) == 0xfd0103) {
    if (iVar1 == 0) {
      return 0x10006;
    }
    if (iVar1 != 0x55) {
      return uVar2;
    }
  }
  else {
    if (iVar1 == 0x55) {
      return uVar2;
    }
    if (iVar1 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar2 & 0xffffffff,"status","src/kernel/mem_mgr/mem_multicast_fabric.c",0xc2f);
      return uVar2 & 0xffffffff;
    }
  }
  uVar2 = resControl_IMPL(param_1[0x3f],param_2);
  return uVar2;
}


// ===== 00465700 memorymulticastfabricIsExportAllowed_IMPL =====

uint memorymulticastfabricIsExportAllowed_IMPL(long param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x228);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar2 + 0x100));
  uVar1 = *(uint *)(lVar2 + 0xa0);
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar2 + 0x100));
  return ~uVar1 & 1;
}


// ===== 00465740 memorymulticastfabricIsGpuMapAllowed_IMPL =====

undefined4 memorymulticastfabricIsGpuMapAllowed_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x228);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar2 + 0x100));
  uVar1 = *(uint *)(lVar2 + 0x30);
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar2 + 0x100));
  return CONCAT31((int3)(*(uint *)(param_2 + 0x7a4) >> 8),
                  (uVar1 >> (*(uint *)(param_2 + 0x7a4) & 0x1f) & 1) != 0);
}


// ===== 00465790 memorymulticastfabricGetMapAddrSpace_IMPL =====

undefined8 memorymulticastfabricGetMapAddrSpace_IMPL(void)

{
  undefined4 *in_RCX;
  
  *in_RCX = 7;
  return 0;
}


// ===== 004657a0 memorymulticastfabricRemoveFromCache_IMPL =====

void memorymulticastfabricRemoveFromCache_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x222) == '\0') {
    return;
  }
  lVar1 = *(long *)(param_1 + 0x228);
  uVar2 = *(undefined8 *)(g_pSys + 0x260);
  portSyncRwLockAcquireRead(*(undefined8 *)(lVar1 + 0x100));
  fabricImportCacheDelete_IMPL(uVar2,lVar1 + 0xb0,*(undefined8 *)(lVar1 + 0xc0));
  portSyncRwLockReleaseRead(*(undefined8 *)(lVar1 + 0x100));
  return;
}


// ===== 004657fe nodevicememDestruct_IMPL.cold =====

void nodevicememDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00465810 nodevicememDestruct_IMPL =====

void nodevicememDestruct_IMPL(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  if (*(long *)(lVar1 + 0x138) != 0) {
    memdescUnmap(*(undefined8 *)(lVar1 + 0x118),1,*(long *)(lVar1 + 0x138),
                 *(undefined8 *)(lVar1 + 0x140));
    *(undefined8 *)(lVar1 + 0x138) = 0;
    *(undefined8 *)(lVar1 + 0x140) = 0;
  }
  if (*(long *)(lVar1 + 0x118) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(lVar1 + 0x118));
    return;
  }
  return;
}


// ===== 004658a0 nodevicememConstruct_IMPL =====

ulong nodevicememConstruct_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  
  lVar3 = *(long *)(param_3 + 0x40);
  if (param_1 == 0) {
    uVar1 = *(uint *)(lVar3 + 0x18);
    lVar8 = 0;
    lVar9 = 0x118;
  }
  else {
    uVar1 = *(uint *)(lVar3 + 0x18);
    lVar8 = *(long *)(param_1 + 0x210);
    lVar9 = lVar8 + 0x118;
  }
  uVar7 = memdescCreate(lVar9,0,*(undefined8 *)(lVar3 + 0x40),0,1,1);
  if ((int)uVar7 != 0) {
    return uVar7;
  }
  uVar5 = osAllocPagesInternal(*(undefined8 *)(lVar8 + 0x118));
  if (uVar5 == 0) {
    lVar9 = *(long *)(lVar8 + 0x118);
    *(undefined1 *)(lVar9 + 100) = 1;
    uVar6 = *(uint *)(lVar3 + 0x1c) & 0x400000;
    if (uVar6 != 0) {
      memdescSetFlag(lVar9,0x100000000,1);
    }
    uVar7 = memSetGpuCacheSnoop_IMPL(0,uVar1 & 0xe0000000,lVar9);
    uVar5 = (uint)uVar7;
    if (uVar5 == 0) {
      uVar2 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x11c);
      *(long *)(lVar8 + 0x118) = lVar9;
      *(undefined4 *)(lVar8 + 0xfc) = uVar2;
      uVar4 = *(undefined8 *)(lVar9 + 0x30);
      *(undefined8 *)(lVar8 + 0x108) = 0x100000000;
      *(undefined8 *)(lVar8 + 0x100) = uVar4;
      *(undefined8 *)(lVar8 + 0x110) = 0;
      *(uint *)(lVar8 + 0x188) = uVar1 & 0xe0000000;
      *(uint *)(lVar8 + 0x18c) = uVar6;
      uVar2 = *(undefined4 *)(lVar3 + 8);
      *(undefined1 *)(lVar8 + 0x120) = 1;
      *(undefined4 *)(lVar8 + 0x198) = uVar2;
      *(long *)(lVar8 + 0x130) = lVar8;
      *(long *)(lVar8 + 0x128) = lVar8;
      return uVar7;
    }
    nvCheckOkFailedNoLog
              (1,uVar7 & 0xffffffff,"memSetGpuCacheSnoop(NULL, attr, pMemDesc)",
               "src/kernel/mem_mgr/no_device_mem.c",0x53);
  }
  nodevicememDestruct_IMPL(param_1);
  return (ulong)uVar5;
}


// ===== 00465aa0 nodevicememGetMapAddrSpace_IMPL =====

undefined8 nodevicememGetMapAddrSpace_IMPL(void)

{
  undefined4 *in_RCX;
  
  *in_RCX = 1;
  return 0;
}


// ===== 00465aad osdescConstruct_IMPL.cold =====

void osdescConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00465ac0 osdescConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int osdescConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  char *pcVar16;
  undefined8 uVar17;
  uint local_150;
  undefined4 local_14c;
  undefined8 *local_148;
  long local_140;
  long local_138;
  ulong local_130;
  undefined8 local_128;
  int local_120;
  undefined1 local_118 [72];
  undefined8 local_d0;
  undefined4 local_c8 [2];
  undefined8 uStack_c0;
  undefined4 local_b8 [2];
  undefined8 auStack_b0 [3];
  undefined4 local_98;
  undefined4 local_8c;
  undefined8 local_60;
  undefined8 local_50;
  long local_48;
  uint local_40;
  ulong uVar15;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar13 = *(long *)(param_1 + 0x210);
  local_148 = (undefined8 *)0x0;
  local_138 = 0;
  uVar10 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  lVar3 = *(long *)(lVar13 + 0xf0);
  local_14c = 0;
  lVar4 = *(long *)(lVar3 + 0x1b78);
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
  uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x10);
  local_130 = 0;
  local_128 = 0;
  lVar12 = *(long *)(*(long *)(lVar13 + 0xb8) + 0x48);
  local_120 = 0;
  if (*(long *)(param_3 + 0x58) != 0) {
    return 0;
  }
  piVar5 = *(int **)(param_3 + 0x40);
  local_140 = *(long *)(piVar5 + 6);
  iVar8 = RmDeprecatedConvertOs32ToOs02Flags(piVar5[2],piVar5[3],piVar5[1],&local_150);
  if (iVar8 != 0) {
    uVar17 = 0x4f;
    pcVar16 = 
    "RmDeprecatedConvertOs32ToOs02Flags(pUserParams->attr, pUserParams->attr2, pUserParams->flags, &os02Flags)"
    ;
LAB_0046613c:
    nvCheckOkFailedNoLog(1,iVar8,pcVar16,"src/kernel/mem_mgr/os_desc_mem.c",uVar17);
    return iVar8;
  }
  iVar8 = piVar5[8];
  if (iVar8 == 3) {
    if (*(uint *)(param_2 + 0x28) < 2) {
      return 0x56;
    }
  }
  else if (iVar8 == 2) {
    local_150 = local_150 & 0x3fffffff | 0x80800000;
  }
  if (*piVar5 == 0x11) {
    local_150 = local_150 | 0x1000000;
  }
  iVar8 = osCreateMemFromOsDescriptor
                    (lVar3,*(undefined8 *)(piVar5 + 4),uVar10,local_150,&local_140,&local_148,iVar8,
                     **(undefined4 **)(param_3 + 0x38));
  if (iVar8 != 0) {
    uVar17 = 0x79;
    pcVar16 = 
    "osCreateMemFromOsDescriptor(pGpu, pUserParams->descriptor, hClient, os02Flags, &limit, &pMemDesc, pUserParams->descriptorType, pRmAllocParams->pSecInfo->privLevel)"
    ;
    goto LAB_0046613c;
  }
  cVar7 = memdescGetContiguity(local_148,2);
  if (cVar7 == '\0') {
    local_150 = local_150 & 0xffffff0f | 0x10;
    piVar5[2] = piVar5[2] & 0xe7ffffffU | 0x8000000;
  }
  if (piVar5[8] == 4) {
    memdescSetFlag(local_148,0x20000000000000,1);
  }
  if ((*(char *)(lVar4 + 0x473) != '\0') && (*(char *)((long)local_148 + 0x154) != '\0')) {
    piVar5[3] = piVar5[3] & 0xffcfffff;
    piVar5[2] = piVar5[2] | 0x1800000;
  }
  iVar8 = memSetGpuCacheSnoop_IMPL(lVar3);
  uVar17 = 0x95;
  pcVar16 = "memSetGpuCacheSnoop(pGpu, pUserParams->attr, pMemDesc)";
  if (iVar8 == 0) {
    iVar8 = memConstructCommon_IMPL
                      (lVar13,0x71,piVar5[1],local_148,0,0,piVar5[2],piVar5[3],0,0,piVar5[9],0);
    if (iVar8 == 0) {
      portMemSet(local_118,0,0x48);
      iVar8 = refAddMapping(lVar12,local_118,*(undefined8 *)(lVar12 + 0x18),&local_138);
      lVar12 = local_138;
      uVar17 = 0xa2;
      pcVar16 = "refAddMapping(pResourceRef, &dummyParams, pResourceRef->pParentRef, &pCpuMapping)";
      if (iVar8 == 0) {
        if (local_138 == 0) {
          nvAssertOkFailedNoLog
                    (0x1f,
                     "CliUpdateMemoryMappingInfo(pCpuMapping, pCallContext->secInfo.privLevel >= RS_PRIV_LEVEL_KERNEL, pUserParams->descriptor, NvP64_NULL, limit+1, flags)"
                     ,"src/kernel/mem_mgr/os_desc_mem.c",0xa6,0xa2);
          iVar8 = 0x1f;
          goto LAB_00465fa0;
        }
        uVar17 = *(undefined8 *)(piVar5 + 4);
        *(bool *)(*(long *)(local_138 + 0x50) + 0x24) = 1 < *(uint *)(param_2 + 0x28);
        *(long *)(local_138 + 8) = local_140 + 1;
        *(undefined4 *)(local_138 + 0x10) = 0x400000;
        uVar9 = osGetCurrentProcess();
        *(undefined4 *)(lVar12 + 0x48) = uVar9;
        *(undefined8 *)(lVar12 + 0x18) = uVar17;
        *(undefined8 *)(*(long *)(lVar12 + 0x50) + 0x18) = 0;
        portMemSet(*(undefined8 *)(lVar12 + 0x50),0,0x10);
        *(long *)(*(long *)(local_138 + 0x50) + 0x10) = lVar3;
        if (*(char *)(lVar3 + 0x908) != '\0') {
          lVar12 = gpuGetRpc(lVar3);
          if (lVar12 == 0) {
            nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/os_desc_mem.c",0xb7);
            iVar8 = 0x1a;
LAB_00466194:
            nvCheckOkFailedNoLog(1,iVar8,"status","src/kernel/mem_mgr/os_desc_mem.c",0xbf);
            goto LAB_00465fa0;
          }
          if ((*(char *)(lVar3 + 0x4913) == '\0') || (*(char *)(lVar3 + 0x491e) != '\0')) {
            if (*(char *)(lVar3 + 0x90a) == '\0') {
              iVar8 = (**(code **)(lVar12 + 0x50))
                                (lVar3,lVar12,uVar10,uVar2,uVar1,0x71,local_150,local_148);
            }
            else {
              uVar14 = 0;
              do {
                uVar11 = (int)uVar14 + 0x20;
                uVar15 = (ulong)uVar11;
                *(undefined8 *)((long)&local_d0 + uVar14) = 0;
                *(undefined8 *)((long)local_c8 + uVar14) = 0;
                *(undefined8 *)((long)local_b8 + (uVar14 - 8)) = 0;
                *(undefined8 *)((long)local_b8 + uVar14) = 0;
                uVar14 = uVar15;
              } while (uVar11 < 0x80);
              *(undefined8 *)((long)&local_d0 + uVar15) = 0;
              *(undefined8 *)((long)local_c8 + uVar15) = 0;
              *(undefined8 *)((long)local_b8 + (uVar15 - 8)) = 0;
              local_b8[0] = *(undefined4 *)(local_148 + 0xc);
              local_98 = memdescGetPteKindForGpu(local_148,*local_148);
              local_60 = local_148[6];
              local_8c = (undefined4)local_148[3];
              local_50 = memdescGetPteArrayForGpu(local_148,*local_148,1);
              local_d0 = 0;
              local_c8[0] = 0;
              local_48 = local_148[6] + -1;
              local_40 = local_150 & 0xf000 | 0x40000010;
              iVar8 = (**(code **)(lVar3 + 0x3b60))
                                (lVar3 + 0x3b58,uVar10,uVar2,uVar1,0x81,&local_d0,0x98);
            }
            if (iVar8 != 0) goto LAB_00466194;
          }
          *(undefined1 *)(lVar13 + 0x1b0) = 1;
          iVar8 = vgpuUpdateGuestSysmemPfnBitMap(lVar3,local_148,1);
          if (iVar8 != 0) {
            nvAssertOkFailedNoLog
                      (iVar8,"vgpuUpdateGuestSysmemPfnBitMap(pGpu, pMemDesc, NV_TRUE)",
                       "src/kernel/mem_mgr/os_desc_mem.c",0xc2);
            goto LAB_00465fa0;
          }
        }
        local_128 = CONCAT44(local_128._4_4_,piVar5[1]);
        local_120 = *piVar5;
        local_130 = *(ulong *)(piVar5 + 2);
        uVar14 = local_130 & 0xffffffff;
        if ((local_130 & 0x3000) != 0) {
          lVar13 = kmemsysGetStaticConfig_IMPL(lVar3,*(undefined8 *)(lVar3 + 0x1b70));
          if (*(char *)(lVar13 + 2) == '\0') {
            nvCheckFailedNoLog(4,"pMemorySystemConfig->bUseRawModeComptaglineAllocation",
                               "src/kernel/mem_mgr/os_desc_mem.c",0xd0);
LAB_00466355:
            iVar8 = 0x56;
            goto LAB_00465fa0;
          }
          if (*(char *)(lVar13 + 3) == '\0') {
            uVar10 = memdescGetAddressSpace(local_148);
            cVar7 = memmgrComprSupported_IMPL(lVar4,uVar10);
            uVar14 = local_130 & 0xffffffff;
            if (cVar7 == '\0') {
              if (((uint)local_130 & 0x3000) == 0x1000) {
                nvCheckFailedNoLog(4,
                                   "!FLD_TEST_DRF(OS32, _ATTR, _COMPR, _REQUIRED, fbAllocPageFormat.attr)"
                                   ,"src/kernel/mem_mgr/os_desc_mem.c",0xda);
                goto LAB_00466355;
              }
              uVar14 = local_130 & 0xffffcfff;
              local_130 = CONCAT44(local_130._4_4_,(int)uVar14);
            }
          }
          else {
            nvDbg_Printf("src/kernel/mem_mgr/os_desc_mem.c",0xd5,"osdescConstruct_IMPL",1,
                         "NVRM: compression disabled due to regkey\n");
            uVar14 = local_130 & 0xffffcfff;
            local_130 = CONCAT44(local_130._4_4_,(int)uVar14);
          }
        }
        iVar8 = (**(code **)(lVar4 + 0x2a0))
                          (lVar3,lVar4,&local_130,(uint)(uVar14 >> 0xc) & 3,&local_14c);
        if (iVar8 == 0) {
          cVar7 = (**(code **)(lVar4 + 0x2a8))(lVar4,9,local_14c);
          if (cVar7 != '\0') {
            memdescSetPteKindForGpu(local_148,*local_148);
            return 0;
          }
          nvDbg_Printf("src/kernel/mem_mgr/os_desc_mem.c",0xe9,"osdescConstruct_IMPL",4,
                       "NVRM: memmgrChooseKind_HAL() return (%d) kind(%x).\n",0,local_14c);
          goto LAB_00465fa0;
        }
        uVar17 = 0xe2;
        pcVar16 = 
        "memmgrChooseKind_HAL(pGpu, pMemoryManager, &fbAllocPageFormat, DRF_VAL(OS32, _ATTR, _COMPR, fbAllocPageFormat.attr), &kind)"
        ;
      }
      nvCheckOkFailedNoLog(4,iVar8,pcVar16,"src/kernel/mem_mgr/os_desc_mem.c",uVar17);
      goto LAB_00465fa0;
    }
    uVar17 = 0x98;
    pcVar16 = 
    "memConstructCommon(pMemory, NV01_MEMORY_SYSTEM_OS_DESCRIPTOR, pUserParams->flags, pMemDesc, 0, NULL, pUserParams->attr, pUserParams->attr2, 0, 0, pUserParams->tag, (HWRESOURCE_INFO *)NULL)"
    ;
  }
  nvCheckOkFailedNoLog(1,iVar8,pcVar16,"src/kernel/mem_mgr/os_desc_mem.c",uVar17);
LAB_00465fa0:
  memdescFree(local_148);
  memdescDestroy(local_148);
  return iVar8;
}


// ===== 0046637f osdescDestruct_IMPL.cold =====

void osdescDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00466390 osdescDestruct_IMPL =====

void osdescDestruct_IMPL(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x210) + 0x118);
  if (*(int *)(lVar2 + 0x94) == 1) {
    lVar3 = *(long *)(*(long *)(param_1 + 0x210) + 0xf0);
    if (*(uint *)(lVar2 + 0x90) < 2) {
      cVar1 = *(char *)(lVar3 + 0x908);
    }
    else {
      nvAssertFailedNoLog("Destroying memdesc but not all refs destroyed!\n",
                          "src/kernel/mem_mgr/os_desc_mem.c",0x108);
      cVar1 = *(char *)(lVar3 + 0x908);
    }
    if ((cVar1 != '\0') && (iVar5 = vgpuUpdateGuestSysmemPfnBitMap(lVar3,lVar2,0), iVar5 != 0)) {
      nvAssertFailedNoLog("vgpuUpdateGuestSysmemPfnBitMap(pGpu, pMemDesc, NV_FALSE) == NV_OK",
                          "src/kernel/mem_mgr/os_desc_mem.c",0x10d);
      return;
    }
    return;
  }
  return;
}


// ===== 00466440 osdescCanCopy_IMPL =====

undefined8 osdescCanCopy_IMPL(void)

{
  return 1;
}


// ===== 0046644a physmemConstruct_IMPL.cold =====

void physmemConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00466460 physmemConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong physmemConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  uint *puVar15;
  undefined8 uVar16;
  uint local_160;
  undefined8 *local_148;
  undefined8 local_140;
  undefined8 local_138;
  ulong local_12c;
  undefined8 local_124;
  undefined4 local_11c;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined8 auStack_f0 [3];
  undefined1 local_d8 [8];
  undefined8 local_d0;
  undefined8 local_c0;
  uint local_b4;
  uint uStack_b0;
  int local_ac;
  undefined4 local_a8;
  undefined8 local_80;
  ulong *local_68;
  undefined8 local_60;
  undefined4 local_54;
  
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x10);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar3 = *(long *)(param_1 + 0x210);
  local_148 = (undefined8 *)0x0;
  local_118 = 0;
  lVar4 = *(long *)(lVar3 + 0xf0);
  local_110 = 0;
  local_108 = 0;
  lVar5 = *(long *)(lVar4 + 0x1b78);
  lVar11 = *(long *)(lVar4 + 0x1b98);
  local_100 = 0;
  uVar16 = *(undefined8 *)(lVar5 + 0x478);
  pcVar10 = (char *)kmemsysGetStaticConfig_IMPL(lVar4,*(undefined8 *)(lVar4 + 0x1b70));
  if (*(long *)(param_3 + 0x58) != 0) {
    return 0;
  }
  puVar14 = *(undefined8 **)(param_3 + 0x40);
  cVar7 = (**(code **)(lVar5 + 0x2a8))(lVar5,5,*(undefined4 *)(puVar14 + 1));
  heapGetBase_IMPL(uVar16,&local_140);
  heapGetSize_IMPL(uVar16,&local_138);
  *puVar14 = local_138;
  if (puVar14[2] == 0x200000) {
    uVar9 = 0x100000;
    if (*(char *)(lVar11 + 0x67d0) == '\0') {
      nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)","src/kernel/mem_mgr/phys_mem.c",
                          100);
      return 0x1f;
    }
LAB_004665cd:
    uVar12 = 0x11800000;
    uVar8 = uVar9;
    if (cVar7 == '\0') goto LAB_004668b6;
LAB_004665da:
    uVar8 = 0;
    do {
      uVar13 = (ulong)uVar8;
      uVar8 = uVar8 + 0x20;
      *(undefined8 *)((long)&local_f8 + uVar13) = 0;
      *(undefined8 *)((long)auStack_f0 + uVar13) = 0;
      *(undefined8 *)((long)auStack_f0 + uVar13 + 8) = 0;
      *(undefined8 *)(local_d8 + (uVar13 - 8)) = 0;
    } while (uVar8 < 0xc0);
    local_12c = 0;
    local_124 = 0;
    local_11c = 0;
    if ((*pcVar10 == '\0') && (pcVar10[2] == '\0')) {
      nvCheckFailedNoLog(4,
                         "pMemorySystemConfig->bOneToOneComptagLineAllocation || pMemorySystemConfig->bUseRawModeComptaglineAllocation"
                         ,"src/kernel/mem_mgr/phys_mem.c",0x72);
      return 0x1f;
    }
    local_160 = uVar9 | 0x20001;
    uVar16 = 0x46668a;
    cVar7 = (**(code **)(lVar5 + 0x2a8))(lVar5,10,*(undefined4 *)(puVar14 + 1));
    uVar13 = local_124;
    local_c0 = 0;
    local_b4 = (uint)uVar12 | 0x1000;
    if (cVar7 != '\0') {
      local_b4 = (uint)CONCAT62((int6)(uVar12 >> 0x10),0x3000);
    }
    local_68 = &local_12c;
    puVar15 = &uStack_b0;
    auStack_f0[2] = local_138;
    local_80 = local_138;
    local_ac = *(int *)(puVar14 + 1);
    local_12c = CONCAT44(uVar9,local_b4) | 0x2000100000000;
    uStack_b0 = local_160;
    local_124 = CONCAT44(local_ac,(undefined4)local_124);
    local_60 = CONCAT44(uVar2,uVar1);
    lVar11 = (**(code **)(lVar5 + 0x168))
                       (lVar5,uVar1,local_138,local_ac,uVar13 & 0xffffffff,&local_b4);
    if (lVar11 == 0) {
      nvCheckFailedNoLog(4,
                         "memmgrDeterminePageSize(pMemoryManager, FbAllocInfo.hClient, FbAllocInfo.size, FbAllocInfo.format, FbAllocInfo.pageFormat->flags, &FbAllocInfo.retAttr, &FbAllocInfo.retAttr2) != 0"
                         ,"src/kernel/mem_mgr/phys_mem.c",0x8d,puVar15,uVar16);
      return 0x1f;
    }
    uVar9 = (**(code **)(lVar5 + 0x1f8))
                      (lVar4,lVar5,auStack_f0 + 2,local_d8,local_d0,(int)local_68[1],local_b4,
                       uStack_b0,0);
    uVar16 = 0x94;
    pcVar10 = 
    "memmgrAllocDetermineAlignment_HAL(pGpu, pMemoryManager, &FbAllocInfo.size, &FbAllocInfo.align, FbAllocInfo.alignPad, FbAllocInfo.pageFormat->flags, FbAllocInfo.retAttr, FbAllocInfo.retAttr2, 0)"
    ;
    if (uVar9 != 0) goto LAB_00466a04;
    uVar9 = memmgrAllocHwResources_IMPL(lVar4,lVar5,&local_f8,"src/kernel/mem_mgr/phys_mem.c",0x94);
    uVar8 = uStack_b0;
    if (uVar9 != 0) {
      uVar16 = 0x99;
      pcVar10 = "memmgrAllocHwResources(pGpu, pMemoryManager, &FbAllocInfo)";
      goto LAB_00466a04;
    }
    if (local_ac != *(int *)(puVar14 + 1)) {
      nvAssertFailedNoLog("FbAllocInfo.format == pAllocParams->format",
                          "src/kernel/mem_mgr/phys_mem.c",0x9a);
      return 0x1f;
    }
    uVar12 = (ulong)local_b4;
    local_110 = CONCAT44(local_54,local_a8);
    local_118 = CONCAT44(uStack_b0,local_b4);
    local_108 = CONCAT44(local_108._4_4_,local_f8._4_4_);
    uVar9 = memCreateMemDesc_IMPL(lVar4,&local_148,2,0,local_138,uVar12,uStack_b0);
    if (uVar9 == 0) {
      memdescDescribe(local_148,2,local_140,local_138);
      memdescSetPteKindForGpu(local_148,*local_148,*(undefined4 *)(puVar14 + 1));
      puVar14 = &local_118;
      *(undefined4 *)(local_148 + 0x13) = (undefined4)local_108;
      goto LAB_00466950;
    }
  }
  else {
    if (puVar14[2] == 0x20000000) {
      uVar9 = 0x200000;
      if (*(char *)(lVar11 + 0x67d1) == '\0') {
        nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                            "src/kernel/mem_mgr/phys_mem.c",0x5f);
        return 0x1f;
      }
      goto LAB_004665cd;
    }
    uVar8 = 0;
    uVar9 = 0;
    uVar12 = 0x11000000;
    if (cVar7 != '\0') goto LAB_004665da;
LAB_004668b6:
    uVar9 = memCreateMemDesc_IMPL(lVar4,&local_148,2,0,local_138,uVar12,uVar8);
    if (uVar9 == 0) {
      memdescDescribe(local_148,2,local_140,local_138);
      memdescSetPteKindForGpu(local_148,*local_148,*(undefined4 *)(puVar14 + 1));
      puVar14 = (undefined8 *)0x0;
LAB_00466950:
      uVar12 = memConstructCommon_IMPL(lVar3,0x40,0,local_148,0,0,uVar12,uVar8,0,0,0,puVar14);
      if ((int)uVar12 != 0) {
        nvCheckOkFailedNoLog
                  (4,uVar12 & 0xffffffff,
                   "memConstructCommon(pMemory, NV01_MEMORY_LOCAL_USER, 0, pMemDesc, 0, NULL, attr, attr2, 0, 0, NVOS32_MEM_TAG_NONE, bCompressedKind ? &hwResource : NULL)"
                   ,"src/kernel/mem_mgr/phys_mem.c",0xb1);
        memdescDestroy(local_148);
        return uVar12 & 0xffffffff;
      }
      if (*(char *)(lVar4 + 0x909) == '\0') {
        *(undefined1 *)(lVar3 + 0x1b0) = 1;
        return uVar12;
      }
      return uVar12;
    }
  }
  uVar16 = 0xa8;
  pcVar10 = "status";
LAB_00466a04:
  nvCheckOkFailedNoLog(4,uVar9,pcVar10,"src/kernel/mem_mgr/phys_mem.c",uVar16);
  return (ulong)uVar9;
}


// ===== 00466b20 physmemCanCopy_IMPL =====

undefined8 physmemCanCopy_IMPL(void)

{
  return 1;
}


// ===== 00466b40 allocUpstreamTopPool =====

int allocUpstreamTopPool(undefined8 *param_1,ulong param_2,long param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pCtx","src/kernel/mem_mgr/pool_alloc.c",0xdb);
  }
  else {
    if (param_4 != (undefined8 *)0x0) {
      local_70._0_4_ = (-(uint)(*(char *)(param_1 + 0xe) == '\0') & 0xfffffc00) + 0x482;
      local_70._4_4_ = 0;
      if (*(char *)((long)param_1 + 0x72) != '\0') {
        local_70._0_4_ = (uint)local_70 | 0x100;
      }
      if (param_2 == 0x10000) {
        iVar2 = 0x51;
        puVar3 = (undefined8 *)portMemAllocNonPaged(param_3 * 8);
        if (puVar3 != (undefined8 *)0x0) {
          iVar2 = pmaAllocatePages(*param_1,param_3,0x10000,&local_70,puVar3);
          if (iVar2 == 0) {
            if (param_3 != 0) {
              puVar4 = puVar3;
              puVar6 = param_4;
              do {
                uVar1 = *puVar4;
                puVar7 = puVar6 + 2;
                puVar4 = puVar4 + 1;
                puVar6[1] = 0;
                *puVar6 = uVar1;
                puVar6 = puVar7;
              } while (param_4 + param_3 * 2 != puVar7);
            }
          }
          else {
            nvCheckOkFailedNoLog
                      (2,iVar2,
                       "pmaAllocatePages(pMemReserveInfo->pPma, numPages, pageSize, &allocOptions, pPageStore)"
                       ,"src/kernel/mem_mgr/pool_alloc.c",0xf8);
          }
          portMemFree(puVar3);
          return iVar2;
        }
      }
      else {
        local_70 = (ulong)((uint)local_70 | 0x40);
        if (param_3 == 0) {
          iVar2 = 0;
        }
        else {
          lVar5 = 0;
          puVar3 = param_4;
          do {
            iVar2 = pmaAllocatePages(*param_1,param_2 >> 0x10,0x10000,&local_70,&local_78);
            if (iVar2 != 0) {
              nvAssertOkFailedNoLog
                        (iVar2,
                         "pmaAllocatePages(pMemReserveInfo->pPma, pageSize / PMA_CHUNK_SIZE_64K, PMA_CHUNK_SIZE_64K, &allocOptions, &pageBegin)"
                         ,"src/kernel/mem_mgr/pool_alloc.c",0x10e);
              puVar3 = param_4 + lVar5 * 2 + -2;
              for (; lVar5 != 0; lVar5 = lVar5 + -1) {
                pmaFreePages(*param_1,puVar3,1,param_2,*(char *)(param_1 + 0xe) != '\0');
                puVar3 = puVar3 + -2;
              }
              return iVar2;
            }
            lVar5 = lVar5 + 1;
            puVar3[1] = 0;
            *puVar3 = local_78;
            iVar2 = 0;
            puVar3 = puVar3 + 2;
          } while (param_3 != lVar5);
        }
      }
      return iVar2;
    }
    nvAssertFailedNoLog("NULL != pPage","src/kernel/mem_mgr/pool_alloc.c",0xdc);
  }
  return 0x1f;
}


// ===== 00466e40 freeUpstreamLowerPools =====

void freeUpstreamLowerPools(long param_1,undefined8 param_2,long param_3)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pCtx","src/kernel/mem_mgr/pool_alloc.c",0x180);
    return;
  }
  if (param_3 != 0) {
    poolFree(param_1,param_3);
    return;
  }
  nvAssertFailedNoLog("NULL != pPage","src/kernel/mem_mgr/pool_alloc.c",0x181);
  return;
}


// ===== 00466ea0 allocUpstreamLowerPools =====

int allocUpstreamLowerPools(long param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pCtx","src/kernel/mem_mgr/pool_alloc.c",0x138);
  }
  else {
    if (param_4 != 0) {
      lVar2 = 0;
      lVar3 = param_4;
      if (param_3 != 0) {
        do {
          iVar1 = poolAllocate(param_1,lVar3);
          if (iVar1 != 0) {
            nvAssertOkFailedNoLog
                      (iVar1,"poolAllocate((POOLALLOC *)pCtx, &pPage[i])",
                       "src/kernel/mem_mgr/pool_alloc.c",0x13d);
            lVar3 = param_4 + -0x10 + lVar2 * 0x10;
            for (; lVar2 != 0; lVar2 = lVar2 + -1) {
              poolFree(param_1,lVar3);
              lVar3 = lVar3 + -0x10;
            }
            return iVar1;
          }
          lVar2 = lVar2 + 1;
          lVar3 = lVar3 + 0x10;
        } while (param_3 != lVar2);
      }
      return 0;
    }
    nvAssertFailedNoLog("NULL != pPage","src/kernel/mem_mgr/pool_alloc.c",0x139);
  }
  return 0x1f;
}


// ===== 00466fd0 freeUpstreamTopPool =====

void freeUpstreamTopPool(undefined8 *param_1,undefined8 param_2,long param_3)

{
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pCtx","src/kernel/mem_mgr/pool_alloc.c",0x15f);
    return;
  }
  if (param_3 != 0) {
    pmaFreePages(*param_1,param_3,1,param_1[3],*(char *)(param_1 + 0xe) != '\0');
    return;
  }
  nvAssertFailedNoLog("NULL != pPage","src/kernel/mem_mgr/pool_alloc.c",0x160);
  return;
}


// ===== 00467040 rmMemPoolReserve =====

int rmMemPoolReserve(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  undefined1 uVar5;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("(NULL != pMemReserveInfo)","src/kernel/mem_mgr/pool_alloc.c",0x24b);
    return 0x1f;
  }
  portSyncMutexAcquire(*(undefined8 *)(param_1 + 8));
  uVar2 = *(ulong *)(param_1 + 0x18);
  if ((param_3 & 0x100000) == 0) {
    lVar3 = *(long *)(param_1 + 0x20 + (ulong)*(uint *)(param_1 + 0x10) * 8);
    if (lVar3 != 0) {
      uVar1 = (uVar2 - 1) + param_2;
      iVar4 = poolReserve(lVar3,uVar1 / uVar2,uVar1 % uVar2);
      if (iVar4 == 0) goto LAB_004670b7;
      if (iVar4 != 0x51) {
        nvAssertFailedNoLog("(status == NV_OK) || ((status == NV_ERR_NO_MEMORY) && (flags & VASPACE_FLAGS_RETRY_PTE_ALLOC_IN_SYS))"
                            ,"src/kernel/mem_mgr/pool_alloc.c",0x25d);
        goto LAB_004670b7;
      }
      if ((param_3 & 0x20) != 0) goto LAB_004670b7;
      uVar5 = 0;
LAB_0046716c:
      nvAssertFailedNoLog("(status == NV_OK) || ((status == NV_ERR_NO_MEMORY) && (flags & VASPACE_FLAGS_RETRY_PTE_ALLOC_IN_SYS))"
                          ,"src/kernel/mem_mgr/pool_alloc.c",0x25d);
      if ((param_3 & 0x100000) != 0) {
        iVar4 = 0x51;
        goto LAB_0046710d;
      }
    }
    iVar4 = 0x51;
  }
  else {
    uVar5 = *(undefined1 *)(param_1 + 0x70);
    *(undefined1 *)(param_1 + 0x70) = 1;
    lVar3 = *(long *)(param_1 + 0x20 + (ulong)*(uint *)(param_1 + 0x10) * 8);
    if (lVar3 == 0) {
      iVar4 = 0x51;
    }
    else {
      uVar1 = (uVar2 - 1) + param_2;
      iVar4 = poolReserve(lVar3,uVar1 / uVar2,uVar1 % uVar2);
      if (iVar4 != 0) {
        if (iVar4 == 0x51) {
          if ((param_3 & 0x20) == 0) goto LAB_0046716c;
        }
        else {
          nvAssertFailedNoLog("(status == NV_OK) || ((status == NV_ERR_NO_MEMORY) && (flags & VASPACE_FLAGS_RETRY_PTE_ALLOC_IN_SYS))"
                              ,"src/kernel/mem_mgr/pool_alloc.c",0x25d);
        }
      }
    }
LAB_0046710d:
    *(undefined1 *)(param_1 + 0x70) = uVar5;
  }
LAB_004670b7:
  portSyncMutexRelease(*(undefined8 *)(param_1 + 8));
  return iVar4;
}


// ===== 00467200 rmMemPoolAllocate =====

int rmMemPoolAllocate(long param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  uint local_6c;
  uint local_5c;
  undefined8 local_58 [5];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("(NULL != pMemReserveInfo)","src/kernel/mem_mgr/pool_alloc.c",0x27b);
    return 0x1f;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("(NULL != pMemDesc)","src/kernel/mem_mgr/pool_alloc.c",0x27c);
    return 0x1f;
  }
  local_6c = *(uint *)(param_1 + 0x10);
  lVar6 = portMemAllocNonPaged(0x28);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pPageHandleList != NULL","src/kernel/mem_mgr/pool_alloc.c",0x280);
    return 0x51;
  }
  portMemSet(lVar6,0,0x28);
  uVar7 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(lVar6,uVar7,0x10);
  portSyncMutexAcquire(*(undefined8 *)(param_1 + 8));
  lVar9 = (long)(int)local_6c + 4;
  poolGetListLength(*(undefined8 *)(param_1 + lVar9 * 8),&local_5c,0,0);
  nvDbg_Printf("src/kernel/mem_mgr/pool_alloc.c",0x289,"rmMemPoolAllocate",1,
               "NVRM: Total size of memory reserved for allocation = 0x%llx Bytes\n",
               (ulong)local_5c * *(long *)(param_1 + 0x18));
  uVar12 = *(ulong *)(param_2 + 0x38);
  uVar1 = *(ulong *)(poolAllocSizes + (long)(int)local_6c * 8);
  if (uVar1 < uVar12) {
    uVar2 = ((uVar1 - 1) + uVar12) / uVar1;
    if ((uint)uVar2 < 2) goto LAB_00467308;
    uVar12 = uVar2 & 0xffffffff;
    nvDbg_Printf("src/kernel/mem_mgr/pool_alloc.c",0x2b7,"rmMemPoolAllocate",1,
                 "NVRM: Allocating from pool with alloc size = 0x%llx Bytes\n",uVar1 * uVar12);
    cVar3 = memdescGetContiguity(param_2,1);
    if (cVar3 != '\0') {
      iVar4 = poolAllocateContig(*(undefined8 *)(param_1 + lVar9 * 8),uVar2 & 0xffffffff,lVar6);
      if (iVar4 == 0) {
        puVar8 = (undefined8 *)listHead_IMPL(lVar6);
        memdescDescribe(param_2,2,*puVar8,*(undefined8 *)(param_2 + 0x30));
        goto LAB_00467355;
      }
      portMemFree(0);
LAB_004674af:
      if (-1 < (int)local_6c) {
        uVar7 = listTail_IMPL(lVar6);
        uVar10 = listHead_IMPL(lVar6);
        listIterRange_IMPL(local_58,lVar6,uVar10,uVar7);
        while (cVar3 = listIterNext_IMPL(local_58), cVar3 != '\0') {
          poolFree(*(undefined8 *)(param_1 + 0x20 + (ulong)local_6c * 8),local_58[0]);
        }
      }
      goto LAB_004673f9;
    }
    puVar8 = (undefined8 *)portMemAllocNonPaged(uVar12 * 8);
    if (puVar8 == (undefined8 *)0x0) {
      iVar4 = 0x51;
      portMemFree(0);
      goto LAB_004674af;
    }
    portMemSet(puVar8,0,uVar12 * 8);
    puVar13 = puVar8;
    do {
      puVar11 = (undefined8 *)listAppendNew_IMPL(lVar6);
      if (puVar11 == (undefined8 *)0x0) {
        iVar4 = 0x51;
        nvAssertFailedNoLog("(pPageHandle != NULL)","src/kernel/mem_mgr/pool_alloc.c",0x2d5);
        portMemFree(puVar8);
        goto LAB_004674af;
      }
      iVar4 = poolAllocate(*(undefined8 *)(param_1 + lVar9 * 8),puVar11);
      if (iVar4 != 0) {
        listRemove_IMPL(lVar6,puVar11);
        nvAssertFailedNoLog(&DAT_00d84c7f,"src/kernel/mem_mgr/pool_alloc.c",0x2df);
        portMemFree(puVar8);
        goto LAB_004674af;
      }
      puVar14 = puVar13 + 1;
      *puVar13 = *puVar11;
      puVar13 = puVar14;
    } while (puVar14 != puVar8 + uVar12);
    memdescFillPages(param_2,0,puVar8,uVar2 & 0xffffffff,uVar1);
    portMemFree(puVar8);
LAB_00467355:
    *(long *)(param_2 + 0xb8) = lVar6;
    *(long *)(param_1 + 0x68) = *(long *)(param_1 + 0x68) + 1;
    portMemFree(0);
  }
  else {
    lVar9 = 8;
    if ((int)local_6c < 9) {
      do {
        uVar5 = (uint)lVar9;
        if (uVar12 <= *(ulong *)(poolAllocSizes + lVar9 * 8)) {
          nvDbg_Printf("src/kernel/mem_mgr/pool_alloc.c",0x2a1,"rmMemPoolAllocate",1,
                       "NVRM: Allocating from pool with alloc size = 0x%llx Bytes\n");
          local_6c = uVar5;
          goto LAB_004673e2;
        }
        lVar9 = lVar9 + -1;
      } while ((int)local_6c <= (int)lVar9);
      local_6c = uVar5 - 1;
LAB_004673e2:
      if (local_6c != 0xffffffff) goto LAB_00467308;
      iVar4 = 0x51;
      portMemFree(0);
LAB_004673f9:
      listDestroy_IMPL(lVar6);
      portMemFree(lVar6);
      goto LAB_0046736b;
    }
    local_6c = 8;
LAB_00467308:
    puVar8 = (undefined8 *)listAppendNew_IMPL(lVar6);
    if (puVar8 != (undefined8 *)0x0) {
      iVar4 = poolAllocate(*(undefined8 *)(param_1 + 0x20 + (long)(int)local_6c * 8));
      if (iVar4 != 0) {
        listRemove_IMPL(lVar6);
        portMemFree(0);
        goto LAB_004674af;
      }
      memdescDescribe(param_2,2,*puVar8,*(undefined8 *)(param_2 + 0x30));
      *(ulong *)(param_2 + 0x38) = uVar12;
      goto LAB_00467355;
    }
    nvAssertFailedNoLog("(NULL != pPageHandle)","src/kernel/mem_mgr/pool_alloc.c",0x2ed);
    portMemFree(0);
  }
  iVar4 = 0;
LAB_0046736b:
  portSyncMutexRelease(*(undefined8 *)(param_1 + 8));
  return iVar4;
}


// ===== 00467730 rmMemPoolTrim =====

void rmMemPoolTrim(long param_1,undefined4 param_2,uint param_3)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pMemReserveInfo","src/kernel/mem_mgr/pool_alloc.c",0x32b);
    return;
  }
  if ((param_3 & 0x100000) != 0) {
    uVar1 = *(undefined1 *)(param_1 + 0x70);
    *(undefined1 *)(param_1 + 0x70) = 1;
    poolTrim(*(undefined8 *)(param_1 + 0x20 + (ulong)*(uint *)(param_1 + 0x10) * 8),param_2);
    *(undefined1 *)(param_1 + 0x70) = uVar1;
    return;
  }
  poolTrim(*(undefined8 *)(param_1 + 0x20 + (ulong)*(uint *)(param_1 + 0x10) * 8),param_2);
  return;
}


// ===== 004677b0 rmMemPoolFree =====

void rmMemPoolFree(long param_1,long param_2,ulong param_3)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pMemReserveInfo","src/kernel/mem_mgr/pool_alloc.c",0x34a);
    return;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pMemDesc","src/kernel/mem_mgr/pool_alloc.c",0x34b);
    return;
  }
  if ((*(long *)(param_2 + 0xb8) == 0) ||
     (iVar4 = listCount_IMPL(*(long *)(param_2 + 0xb8)), iVar4 == 0)) {
    nvAssertFailedNoLog("(pMemDesc->pPageHandleList != NULL) && (listCount(pMemDesc->pPageHandleList) != 0)"
                        ,"src/kernel/mem_mgr/pool_alloc.c",0x34c);
    return;
  }
  portSyncMutexAcquire(*(undefined8 *)(param_1 + 8));
  if (*(uint *)(param_2 + 0x90) < 2) {
    uVar2 = *(uint *)(param_1 + 0x10);
    if (*(ulong *)(poolAllocSizes + (ulong)uVar2 * 8) < *(ulong *)(param_2 + 0x38)) {
      uVar5 = (ulong)uVar2;
      if (-1 < (int)uVar2) {
LAB_004678ac:
        uVar6 = listTail_IMPL(*(undefined8 *)(param_2 + 0xb8));
        uVar7 = listHead_IMPL(*(undefined8 *)(param_2 + 0xb8));
        listIterRange_IMPL(&local_78,*(undefined8 *)(param_2 + 0xb8),uVar7,uVar6);
        local_58 = local_78;
        local_50 = local_70;
        local_48 = local_68;
        local_40 = local_60;
        while (cVar3 = listIterNext_IMPL(&local_58), cVar3 != '\0') {
          poolFree(*(undefined8 *)(param_1 + 0x20 + uVar5 * 8),local_58);
        }
        listDestroy_IMPL(*(undefined8 *)(param_2 + 0xb8));
        portMemFree(*(undefined8 *)(param_2 + 0xb8));
        *(undefined8 *)(param_2 + 0xb8) = 0;
        if (*(long *)(param_1 + 0x68) == 0) {
          nvAssertFailedNoLog("pMemReserveInfo->validAllocCount > 0",
                              "src/kernel/mem_mgr/pool_alloc.c",0x1a8);
        }
        else {
          *(long *)(param_1 + 0x68) = *(long *)(param_1 + 0x68) + -1;
        }
        if (*(char *)(param_1 + 0x71) != '\0') {
          if ((param_3 & 0x100000) == 0) {
            poolTrim(*(undefined8 *)(param_1 + 0x20 + (ulong)*(uint *)(param_1 + 0x10) * 8),1);
          }
          else {
            uVar1 = *(undefined1 *)(param_1 + 0x70);
            *(undefined1 *)(param_1 + 0x70) = 1;
            poolTrim(*(undefined8 *)(param_1 + 0x20 + (ulong)*(uint *)(param_1 + 0x10) * 8),1);
            *(undefined1 *)(param_1 + 0x70) = uVar1;
          }
        }
        goto LAB_00467888;
      }
    }
    else {
      uVar5 = 8;
      do {
        if ((*(long *)(param_1 + 0x20 + uVar5 * 8) != 0) &&
           (*(ulong *)(param_2 + 0x38) <= *(ulong *)(poolAllocSizes + uVar5 * 8))) {
          uVar5 = uVar5 & 0xffffffff;
          goto LAB_004678ac;
        }
        bVar8 = uVar5 != 0;
        uVar5 = uVar5 - 1;
      } while (bVar8);
    }
    nvAssertFailedNoLog("(poolIndex >= 0)","src/kernel/mem_mgr/pool_alloc.c",0x373);
  }
LAB_00467888:
  portSyncMutexRelease(*(undefined8 *)(param_1 + 8));
  return;
}


// ===== 00467a40 rmMemPoolRelease =====

void rmMemPoolRelease(long param_1,ulong param_2)

{
  long *plVar1;
  undefined1 uVar2;
  undefined1 local_44 [4];
  int local_40;
  int local_3c [3];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pMemReserveInfo","src/kernel/mem_mgr/pool_alloc.c",0x396);
    return;
  }
  portSyncMutexAcquire(*(undefined8 *)(param_1 + 8));
  if (*(long *)(param_1 + 0x68) == 0) {
    uVar2 = 0;
    if ((param_2 & 0x100000) != 0) {
      uVar2 = *(undefined1 *)(param_1 + 0x70);
      *(undefined1 *)(param_1 + 0x70) = 1;
    }
    plVar1 = (long *)(param_1 + 0x60);
    do {
      if (*plVar1 != 0) {
        poolGetListLength(*plVar1,local_44,&local_40,local_3c);
        if (local_40 != 0) {
          nvAssertFailedNoLog("partialListLength == 0","src/kernel/mem_mgr/pool_alloc.c",0x3ba);
        }
        if (local_3c[0] != 0) {
          nvAssertFailedNoLog("fullListLenght == 0","src/kernel/mem_mgr/pool_alloc.c",0x3bb);
        }
        poolTrim(*plVar1,0);
      }
      plVar1 = plVar1 + -1;
    } while ((long *)(param_1 + 0x18) != plVar1);
    if ((param_2 & 0x100000) != 0) {
      *(undefined1 *)(param_1 + 0x70) = uVar2;
    }
  }
  portSyncMutexRelease(*(undefined8 *)(param_1 + 8));
  return;
}


// ===== 00467b90 rmMemPoolDestroy =====

void rmMemPoolDestroy(long param_1)

{
  long *plVar1;
  int local_34;
  int local_30;
  int local_2c [3];
  
  if (param_1 != 0) {
    if (*(long *)(param_1 + 0x68) != 0) {
      nvAssertFailedNoLog("rmMemPoolGetRef(pMemReserveInfo) == 0","src/kernel/mem_mgr/pool_alloc.c",
                          0x3d8);
    }
    plVar1 = (long *)(param_1 + 0x60);
    do {
      if (*plVar1 != 0) {
        poolGetListLength(*plVar1,&local_34,&local_30,local_2c);
        if (local_34 != 0) {
          nvAssertFailedNoLog("freeListLength == 0","src/kernel/mem_mgr/pool_alloc.c",0x3e5);
        }
        if (local_30 != 0) {
          nvAssertFailedNoLog("partialListLength == 0","src/kernel/mem_mgr/pool_alloc.c",0x3e6);
        }
        if (local_2c[0] != 0) {
          nvAssertFailedNoLog("fullListLenght == 0","src/kernel/mem_mgr/pool_alloc.c",999);
        }
        poolDestroy(*plVar1);
      }
      plVar1 = plVar1 + -1;
    } while ((long *)(param_1 + 0x18) != plVar1);
    if (*(long *)(param_1 + 8) != 0) {
      portSyncMutexDestroy();
      portMemFree(*(undefined8 *)(param_1 + 8));
      *(undefined8 *)(param_1 + 8) = 0;
    }
    portMemFree(param_1);
    return;
  }
  nvAssertFailedNoLog("NULL != pMemReserveInfo","src/kernel/mem_mgr/pool_alloc.c",0x3d6);
  return;
}


// ===== 00467cf0 rmMemPoolSetup =====

int rmMemPoolSetup(undefined8 param_1,long *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if (6 < param_3) {
    return 0x3b;
  }
  puVar3 = (undefined8 *)portMemAllocNonPaged(0x78);
  if (puVar3 == (undefined8 *)0x0) {
    return 0x51;
  }
  portMemSet(puVar3,0,0x78);
  *param_2 = (long)puVar3;
  *puVar3 = param_1;
  uVar4 = *(undefined8 *)(poolConfig + (ulong)param_3 * 0x10 + 8);
  *(int *)(puVar3 + 2) = (int)*(undefined8 *)(poolConfig + (ulong)param_3 * 0x10);
  puVar3[3] = uVar4;
  uVar4 = portMemAllocatorGetGlobalNonPaged();
  uVar1 = *(uint *)(puVar3 + 2);
  uVar4 = poolInitialize(puVar3[3],*(undefined8 *)(poolAllocSizes + (ulong)uVar1 * 8),
                         allocUpstreamTopPool,freeUpstreamTopPool,puVar3,uVar4,0);
  puVar3[(ulong)uVar1 + 4] = uVar4;
  uVar1 = *(uint *)(puVar3 + 2);
  if (puVar3[(ulong)uVar1 + 4] != 0) {
    if ((int)(uVar1 + 1) < 9) {
      lVar6 = (long)(int)(uVar1 + 1);
      lVar7 = lVar6;
      do {
        uVar4 = portMemAllocatorGetGlobalNonPaged();
        lVar5 = poolInitialize(*(undefined8 *)
                                (poolAllocSizes + lVar7 * 8 + (long)(int)uVar1 * 8 + lVar6 * -8),
                               *(undefined8 *)(poolAllocSizes + lVar7 * 8),allocUpstreamLowerPools,
                               freeUpstreamLowerPools,
                               puVar3[(long)(int)uVar1 + ((lVar7 + 4) - lVar6)],uVar4,1);
        puVar3[lVar7 + 4] = lVar5;
        if (lVar5 == 0) goto LAB_00467e3f;
        lVar7 = lVar7 + 1;
      } while ((int)lVar7 < 9);
    }
    lVar7 = portMemAllocNonPaged(portSyncMutexSize);
    puVar3[1] = lVar7;
    if (lVar7 != 0) {
      iVar2 = portSyncMutexInitialize(lVar7);
      if (iVar2 == 0) {
        *(bool *)((long)puVar3 + 0x71) = 3 < param_3 - 3;
        return 0;
      }
      portMemFree(puVar3[1]);
      puVar3[1] = 0;
      goto LAB_00467e44;
    }
  }
LAB_00467e3f:
  iVar2 = 0x51;
LAB_00467e44:
  rmMemPoolDestroy(puVar3);
  return iVar2;
}


// ===== 00467ef0 rmMemPoolIsScrubSkipped =====

undefined1 rmMemPoolIsScrubSkipped(long param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(param_1 + 0x70);
  }
  nvAssertFailedNoLog("pMemReserveInfo != NULL","src/kernel/mem_mgr/pool_alloc.c",0x3fe);
  return 0;
}


// ===== 00467f20 rmMemPoolSkipScrub =====

void rmMemPoolSkipScrub(long param_1,undefined1 param_2)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x70) = param_2;
    return;
  }
  nvAssertFailedNoLog("pMemReserveInfo != NULL","src/kernel/mem_mgr/pool_alloc.c",0x409);
  return;
}


// ===== 00467f50 rmMemPoolGetChunkAndPageSize =====

undefined8 rmMemPoolGetChunkAndPageSize(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("pMemReserveInfo != NULL","src/kernel/mem_mgr/pool_alloc.c",0x416);
  }
  else {
    if ((param_2 != (undefined8 *)0x0) && (param_3 != (undefined8 *)0x0)) {
      *param_2 = *(undefined8 *)(param_1 + 0x18);
      *param_3 = *(undefined8 *)(poolAllocSizes + (ulong)*(uint *)(param_1 + 0x10) * 8);
      return 0;
    }
    nvAssertFailedNoLog("(pChunkSize != NULL) && (pPageSize != NULL)",
                        "src/kernel/mem_mgr/pool_alloc.c",0x417);
  }
  return 0x1f;
}


// ===== 00467fc0 rmMemPoolAllocateProtectedMemory =====

void rmMemPoolAllocateProtectedMemory(long param_1,undefined1 param_2)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x72) = param_2;
    return;
  }
  nvAssertFailedNoLog("pMemReserveInfo != NULL","src/kernel/mem_mgr/pool_alloc.c",0x424);
  return;
}


// ===== 00467fe8 regmemConstruct_IMPL.cold =====

void regmemConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00468000 regmemConstruct_IMPL =====

ulong regmemConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 local_10;
  
  local_10 = 0;
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar4 = 0;
  if (*(long *)(param_3 + 0x58) == 0) {
    lVar1 = *(long *)(param_1 + 0x210);
    uVar3 = kbusGetPciBarSize_IMPL(*(undefined8 *)(&DAT_00001b90 + *(long *)(lVar1 + 0xf0)),0);
    uVar4 = memCreateMemDesc_IMPL(*(undefined8 *)(lVar1 + 0xf0),&local_10,3,0,uVar3,0,0);
    if ((int)uVar4 == 0) {
      uVar4 = memConstructCommon_IMPL(lVar1,0x3f,0,local_10,0,0,0,0,0,0,0,0);
      if ((int)uVar4 != 0) {
        memdescDestroy(local_10);
        return uVar4 & 0xffffffff;
      }
    }
  }
  return uVar4;
}


// ===== 004680c0 regmemCanCopy_IMPL =====

undefined8 regmemCanCopy_IMPL(void)

{
  return 1;
}


// ===== 004680d0 stdmemValidateParams_IMPL =====

undefined8 stdmemValidateParams_IMPL(undefined8 param_1,undefined8 param_2,int *param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = resservGetTlsCallContext();
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/mem_mgr/standard_mem.c",0x2e);
    return 0x40;
  }
  uVar1 = *(uint *)(lVar4 + 0x28);
  if (((1 < uVar1) || (param_3[0x1c] == 0)) && (*(long *)(param_3 + 0x10) != 0)) {
    param_3[0x18] = 0;
    param_3[0x19] = 0;
    uVar3 = param_3[2] & 0xfdffffffU | 0x8000;
    param_3[2] = uVar3;
    if ((0xfffffffd < *param_3 - 1U) || (*param_3 + 0x21510000U < 4)) {
      return 0x39;
    }
    if ((*(byte *)((long)param_3 + 0x1e) & 8) != 0) {
      cVar2 = hypervisorIsVgxHyper_IMPL();
      if ((uVar1 < 2) && (cVar2 == '\0')) {
        return 0x1b;
      }
      uVar3 = param_3[2];
    }
    uVar1 = param_3[1];
    if ((uVar1 < 9) && ((0x128UL >> ((ulong)uVar1 & 0x3f) & 1) != 0)) {
      param_3[7] = param_3[7] | 0x40000;
    }
    if (((uVar3 & 0x20000) == 0) &&
       ((*(long *)(param_3 + 0xc) != 0 || (*(long *)(param_3 + 0xe) != 0)))) {
      nvAssertFailedNoLog("(pAllocData->rangeLo == 0) && (pAllocData->rangeHi == 0)",
                          "src/kernel/mem_mgr/standard_mem.c",0x78);
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0x7b,"stdmemValidateParams_IMPL",1,
                   "NVRM: MMU_PROFILER Attr 0x%x Type 0x%x Attr2 0x%x\n",param_3[6],(ulong)uVar1,
                   param_3[7]);
      uVar1 = param_3[2];
      if ((uVar1 & 0x40000) == 0) {
        if ((*(byte *)((long)param_3 + 0x1f) & 8) == 0) goto LAB_004681c8;
        if ((*(byte *)((long)param_3 + 0x1b) & 6) == 0) {
          return 0x1f;
        }
      }
      else {
        if ((*(byte *)((long)param_3 + 0x1b) & 6) == 0) {
          nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0x82,"stdmemValidateParams_IMPL",4,
                       "NVRM: Encryption requested for video memory on a non-0FB chip;\n");
          return 0x1f;
        }
        if ((*(byte *)((long)param_3 + 0x1f) & 8) == 0) {
LAB_004681c8:
          if ((~uVar1 & 0x4080000) == 0) {
            param_3[2] = uVar1 & 0xfffffbff;
          }
          return 0;
        }
      }
      nvCheckFailedNoLog(4,"FLD_TEST_DRF(OS32, _ATTR, _LOCATION, _VIDMEM, pAllocData->attr)",
                         "src/kernel/mem_mgr/standard_mem.c",0x89);
    }
  }
  return 0x1f;
}


// ===== 00468300 stdmemDumpInputAllocParams_IMPL =====

void stdmemDumpInputAllocParams_IMPL(undefined4 *param_1,long param_2)

{
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa3,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM: stdmemConstruct input\n");
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa4,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:           Owner: 0x%x\n",*param_1);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa5,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:         hMemory: 0x%x\n",*(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa6,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:            Type: 0x%x\n",param_1[1]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa7,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:           Flags: 0x%x\n",param_1[2]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa8,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:           Begin: 0x%08llx\n",*(undefined8 *)(param_1 + 0xc));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xa9,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:             End: 0x%08llx\n",*(undefined8 *)(param_1 + 0xe));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xaa,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:          Height: 0x%x\n",param_1[4]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xab,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:           Width: 0x%x\n",param_1[3]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xac,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:           Pitch: 0x%x\n",param_1[5]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xad,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:            Size: 0x%08llx\n",*(undefined8 *)(param_1 + 0x10));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xae,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:       Alignment: 0x%08llx\n",*(undefined8 *)(param_1 + 0x12));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xaf,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:          Offset: 0x%08llx\n",*(undefined8 *)(param_1 + 0x14));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb0,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:            Attr: 0x%x\n",param_1[6]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb1,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:           Attr2: 0x%x\n",param_1[7]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb2,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:          Format: 0x%x\n",param_1[8]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb3,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:       ComprCovg: 0x%x\n",param_1[9]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb4,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:       ZCullCovg: 0x%x\n",param_1[10]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb5,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:      CtagOffset: 0x%x\n",param_1[0x1a]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb6,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:        hVASpace: 0x%x\n",param_1[0x1b]);
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xb7,"stdmemDumpInputAllocParams_IMPL",1,
               "NVRM:             tag: 0x%x\n",param_1[0x1d]);
  return;
}


// ===== 00468690 stdmemDumpOutputAllocParams_IMPL =====

void stdmemDumpOutputAllocParams_IMPL(long param_1)

{
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xbf,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM: stdmemConstruct output\n");
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc0,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:          Height: 0x%x\n",*(undefined4 *)(param_1 + 0x10));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc1,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:           Width: 0x%x\n",*(undefined4 *)(param_1 + 0xc));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc2,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:           Pitch: 0x%x\n",*(undefined4 *)(param_1 + 0x14));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc3,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:            Size: 0x%08llx\n",*(undefined8 *)(param_1 + 0x40));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc4,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:       Alignment: 0x%08llx\n",*(undefined8 *)(param_1 + 0x48));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc5,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:          Offset: 0x%08llx\n",*(undefined8 *)(param_1 + 0x50));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc6,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:            Attr: 0x%x\n",*(undefined4 *)(param_1 + 0x18));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",199,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:           Attr2: 0x%x\n",*(undefined4 *)(param_1 + 0x1c));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",200,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:          Format: 0x%x\n",*(undefined4 *)(param_1 + 0x20));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xc9,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:       ComprCovg: 0x%x\n",*(undefined4 *)(param_1 + 0x24));
  nvDbg_Printf("src/kernel/mem_mgr/standard_mem.c",0xca,"stdmemDumpOutputAllocParams_IMPL",1,
               "NVRM:       ZCullCovg: 0x%x\n",*(undefined4 *)(param_1 + 0x28));
  return;
}


// ===== 004688a0 stdmemConstruct_IMPL =====

undefined8 stdmemConstruct_IMPL(void)

{
  return 0;
}


// ===== 004688b0 stdmemCanCopy_IMPL =====

undefined8 stdmemCanCopy_IMPL(void)

{
  return 1;
}


// ===== 004688c0 stdmemQueryPageSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void stdmemQueryPageSize_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = *(undefined4 *)(param_3 + 0x18);
  local_c = *(undefined4 *)(param_3 + 0x1c);
  (**(code **)(param_1 + 0x168))
            (param_1,param_2,*(undefined8 *)(param_3 + 0x40),*(undefined4 *)(param_3 + 0x20),
             *(undefined4 *)(param_3 + 8),&local_10,&local_c);
  return;
}


// ===== 004688fd syncpointConstruct_IMPL.cold =====

void syncpointConstruct_IMPL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  
  *(undefined8 *)(unaff_RBP + -0x38) = 0;
  *(undefined8 *)(unaff_RBP + -0x30) = 0;
  *(undefined8 *)(unaff_RBP + -0x28) = 0;
  *(undefined4 *)(unaff_RBP + -0x3c) = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00468920 syncpointConstruct_IMPL =====

/* WARNING: Type propagation algorithm not settling */

int syncpointConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  uint local_44;
  undefined8 local_40;
  long local_38 [2];
  
  if (param_1 == 0) {
    local_40 = 0;
    local_38[0] = 0;
    local_38[1] = 0;
    local_44 = 0;
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  local_40 = 0;
  local_38[0] = 0;
  lVar2 = *(long *)(lVar1 + 0xf0);
  local_38[1] = 0;
  local_44 = 0;
  iVar4 = osGetSyncpointAperture
                    (*(undefined8 *)(lVar2 + 0x4e0),**(undefined4 **)(param_3 + 0x40),local_38,
                     local_38 + 1,&local_44);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/mem_mgr/syncpoint_mem.c",0x38,"syncpointConstruct_IMPL",4,
                 "NVRM: failed to get syncpoint aperture %x\n",iVar4);
    return iVar4;
  }
  iVar4 = osCreateMemFromOsDescriptor
                    (lVar2,(ulong)local_44 + local_38[0],
                     *(undefined4 *)(*(long *)(param_2 + 8) + 0x48),0x41100000,local_38 + 1,
                     &local_40,3,2);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/mem_mgr/syncpoint_mem.c",0x4f,"syncpointConstruct_IMPL",4,
                 "NVRM: failed to import syncpoint memory %x\n",iVar4);
    return iVar4;
  }
  iVar4 = memConstructCommon_IMPL(lVar1,0xc3,0,local_40,0,0,0,0,0,0,0,0);
  if (iVar4 == 0) {
    return 0;
  }
  memdescFree(local_40);
  memdescDestroy(local_40);
  return iVar4;
}


// ===== 00468ab0 syncpointCanCopy_IMPL =====

undefined8 syncpointCanCopy_IMPL(void)

{
  return 1;
}


// ===== 00468aba sysmemConstruct_IMPL.cold =====

void sysmemConstruct_IMPL_cold(void)

{
  code *pcVar1;
  long lVar2;
  long unaff_RBP;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(unaff_RBP + -0x140);
  for (lVar2 = 0x1e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00468ae0 sysmemConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int sysmemConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  undefined8 *puVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  char *pcVar17;
  uint uVar18;
  long *plVar19;
  undefined8 *puVar20;
  undefined8 uVar21;
  bool bVar22;
  byte bVar23;
  uint local_168;
  undefined8 local_164;
  undefined8 local_15c;
  undefined8 local_154;
  undefined4 local_14c;
  long local_148 [2];
  undefined4 local_138;
  undefined4 local_134;
  undefined8 *local_130 [10];
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_98;
  undefined4 local_8c;
  undefined8 local_60;
  undefined8 local_50;
  long local_48;
  uint local_40;
  
  bVar23 = 0;
  if (param_1 == 0) {
    plVar19 = local_148;
    for (lVar14 = 0x1e; lVar14 != 0; lVar14 = lVar14 + -1) {
      *(undefined4 *)plVar19 = 0;
      plVar19 = (long *)((long)plVar19 + 4);
    }
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar14 = *(long *)(param_1 + 0x248);
  lVar4 = *(long *)(param_3 + 0x40);
  uVar12 = 0;
  do {
    uVar9 = (int)uVar12 + 0x20;
    uVar15 = (ulong)uVar9;
    *(undefined8 *)((long)local_148 + uVar12) = 0;
    *(undefined8 *)((long)local_148 + uVar12 + 8) = 0;
    *(undefined8 *)((long)local_130 + (uVar12 - 8)) = 0;
    *(undefined8 *)((long)local_130 + uVar12) = 0;
    uVar12 = uVar15;
  } while (uVar9 < 0x60);
  lVar13 = *(long *)(param_2 + 8);
  *(undefined8 *)((long)local_148 + uVar15) = 0;
  lVar16 = *(long *)(param_2 + 0x10);
  lVar5 = *(long *)(lVar14 + 0xf0);
  *(undefined8 *)((long)local_148 + uVar15 + 8) = 0;
  *(undefined8 *)((long)local_130 + (uVar15 - 8)) = 0;
  uVar1 = *(undefined4 *)(lVar13 + 0x48);
  local_164 = 0;
  local_15c = 0;
  local_154 = 0;
  local_14c = 0;
  lVar13 = __nvoc_dynamicCast(lVar13,__nvoc_class_def_RmClient);
  if (lVar13 == 0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/system_mem.c",0xa7);
    return 0x23;
  }
  if (*(long *)(param_3 + 0x58) != 0) {
    lVar14 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                                __nvoc_class_def_Memory);
    uVar21 = *(undefined8 *)(lVar14 + 0x118);
    iVar10 = memdescGetCustomHeap(uVar21);
    if (iVar10 != 2) {
      return 0;
    }
    iVar10 = (**(code **)(*(long *)(lVar5 + 0x1b78) + 0x3f8))
                       (lVar5,*(long *)(lVar5 + 0x1b78),uVar21);
    return iVar10;
  }
  uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x10);
  iVar10 = stdmemValidateParams_IMPL(lVar5,lVar13,lVar4);
  if (iVar10 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar10,"stdmemValidateParams(pGpu, pRmClient, pAllocData)",
               "src/kernel/mem_mgr/system_mem.c",0xbf);
    return iVar10;
  }
  if (((*(byte *)(lVar4 + 0x1b) & 6) == 0) || ((*(byte *)(lVar4 + 10) & 8) != 0)) {
    nvCheckFailedNoLog(4,
                       "DRF_VAL(OS32, _ATTR, _LOCATION, pAllocData->attr) != NVOS32_ATTR_LOCATION_VIDMEM && !(pAllocData->flags & NVOS32_ALLOC_FLAGS_VIRTUAL)"
                       ,"src/kernel/mem_mgr/system_mem.c",0xc0);
    return 0x1f;
  }
  stdmemDumpInputAllocParams_IMPL(lVar4,param_2);
  local_e0 = 0x3e;
  local_138 = *(undefined4 *)(lVar16 + 0x10);
  local_134 = 1;
  local_130[0] = &local_164;
  local_148[0] = lVar4;
  local_148[1] = lVar5;
  local_dc = uVar1;
  local_d8 = uVar2;
  if ((*(long *)(lVar5 + 0x1c18) != 0) &&
     (cVar8 = krcTestAllowAlloc_IMPL(lVar5,*(long *)(lVar5 + 0x1c18),0x100), cVar8 == '\0')) {
    return 0x1a;
  }
  bVar22 = false;
  if ((*(ushort *)(lVar4 + 0x1a) & 0x180) == 0) {
    bVar22 = *(char *)(*(long *)(lVar5 + 0x1b78) + 0x483) != '\0';
  }
  do {
    iVar10 = (**(code **)(param_1 + 0x260))(lVar5,param_1,local_148);
    puVar7 = local_130[1];
    if (iVar10 != 0) {
      uVar21 = 0xf0;
      pcVar17 = "sysmemInitAllocRequest(pGpu, pSystemMemory, pAllocRequest)";
LAB_00469154:
      nvCheckOkFailedNoLog(1,iVar10,pcVar17,"src/kernel/mem_mgr/system_mem.c",uVar21);
      return iVar10;
    }
    if (local_130[1] == (undefined8 *)0x0) {
      nvAssertFailedNoLog("pAllocRequest->pMemDesc","src/kernel/mem_mgr/system_mem.c",0xf4);
      return 0x40;
    }
    lVar13 = local_130[1][6];
    *(long *)(lVar4 + 0x58) = lVar13 + -1;
    memSetSysmemCacheAttrib_IMPL(lVar5,lVar4,local_130[1]);
    iVar10 = memSetGpuCacheSnoop_IMPL(lVar5,*(undefined4 *)(lVar4 + 0x18),puVar7);
    if (iVar10 != 0) {
      uVar21 = 0xfe;
      pcVar17 = "memSetGpuCacheSnoop(pGpu, pAllocData->attr, pMemDesc)";
      goto LAB_00469154;
    }
    uVar9 = *(uint *)(lVar4 + 0x18);
    iVar10 = memdescGetAddressSpace(puVar7);
    if (iVar10 != 1) {
      nvAssertFailedNoLog("memdescGetAddressSpace(pMemDesc) == ADDR_SYSMEM",
                          "src/kernel/mem_mgr/system_mem.c",0x10c);
    }
    if (*(uint *)(param_2 + 0x28) < 2) {
      memdescSetFlag(puVar7,0x200,0);
    }
    if ((*(byte *)(lVar4 + 10) & 4) != 0) {
      memdescSetFlag(puVar7,0x800,1);
    }
    if ((*(byte *)(lVar4 + 0x1e) & 1) != 0) {
      memdescSetFlag(puVar7,0x4000000000,1);
    }
    memdescSetFlag(puVar7,0x100000000000,1);
    if (*(char *)(g_pSys + 0xa4) == '\0') {
LAB_00468e03:
      uVar18 = *(uint *)(lVar4 + 0x1c);
    }
    else {
      cVar8 = gpuIsCCorApmFeatureEnabled_IMPL(lVar5);
      uVar18 = *(uint *)(lVar4 + 0x1c);
      if ((cVar8 != '\0') && ((uVar18 & 0x6000000) == 0x4000000)) {
        memdescSetFlag(puVar7,0x200000000000,1);
        goto LAB_00468e03;
      }
    }
    if ((uVar18 & 0x80) != 0) {
      cVar8 = memdescGetFlag(puVar7,0x200000000000);
      if (cVar8 == '\0') {
        iVar10 = *(int *)(lVar5 + 0x7c0);
        iVar3 = *(int *)(lVar4 + 0x78);
        if ((iVar10 == -1) || (iVar3 == iVar10)) {
          *(int *)((long)puVar7 + 0x164) = iVar3;
          uVar18 = *(uint *)(lVar4 + 0x1c);
          goto LAB_00468e4c;
        }
        nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x12f,"sysmemConstruct_IMPL",4,
                     "NVRM: NUMA node mismatch. Requested node: %u CPU node: %u\n",iVar3,iVar10);
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x127,"sysmemConstruct_IMPL",4,
                     "NVRM: Cannot specify NUMA node in unprotected memory.\n");
      }
      iVar10 = 0x1f;
      goto LAB_00468f90;
    }
LAB_00468e4c:
    uVar11 = dmaNvos32ToPageSizeAttr(*(undefined4 *)(lVar4 + 0x18),uVar18);
    pcVar6 = *(code **)(*(long *)(lVar5 + 0x1b78) + 0x388);
    iVar10 = (*pcVar6)(lVar5,*(long *)(lVar5 + 0x1b78),puVar7,1,uVar11,pcVar6);
    if (iVar10 != 0) {
      nvCheckOkFailedNoLog
                (1,iVar10,
                 "memmgrSetMemDescPageSize_HAL(pGpu, GPU_GET_MEMORY_MANAGER(pGpu), pMemDesc, AT_GPU, pageSizeAttr)"
                 ,"src/kernel/mem_mgr/system_mem.c",0x139);
      goto LAB_00468f90;
    }
    cVar8 = memdescGetFlag(puVar7,0x8000000000000);
    if (cVar8 != '\0') {
      local_d0 = CONCAT44(local_d0._4_4_,4);
      iVar10 = (**(code **)(*(long *)(lVar5 + 0x1b78) + 0x3c8))
                         (*(long *)(lVar5 + 0x1b78),lVar4,local_dc,&local_d0);
      if (iVar10 != 0) {
        nvCheckOkFailedNoLog(4,iVar10,"rmStatus","src/kernel/mem_mgr/system_mem.c",0x147);
        goto LAB_00468f90;
      }
      lVar13 = puVar7[6];
      *(long *)(lVar4 + 0x58) = lVar13 + -1;
    }
    *(undefined4 *)((long)puVar7 + 0x9c) = 0xa5;
    iVar10 = memdescAlloc(puVar7);
    if (iVar10 == 0) {
      if ((*(uint *)(lVar4 + 0x1c) & 0x300) == 0x200) {
        nvAssertFailedNoLog("!FLD_TEST_DRF(OS32, _ATTR2, _SMMU_ON_GPU, _ENABLE, pAllocData->attr2)",
                            "src/kernel/mem_mgr/system_mem.c",0x17a);
        iVar10 = 0x56;
        goto LAB_0046961a;
      }
      uVar21 = 0;
      iVar10 = memConstructCommon_IMPL
                         (lVar14,local_e0,(uVar9 >> 0x1d) << 0xc | 0x40000000,puVar7,0,0,
                          *(undefined4 *)(lVar4 + 0x18),*(uint *)(lVar4 + 0x1c),0,0,
                          *(undefined4 *)(lVar4 + 0x74),&local_164);
      if (iVar10 != 0) {
        nvCheckOkFailedNoLog
                  (1,iVar10,
                   "memConstructCommon(pMemory, pAllocRequest->classNum, flags, pMemDesc, 0, NULL, pAllocData->attr, pAllocData->attr2, 0, 0, pAllocData->tag, &hwResource)"
                   ,"src/kernel/mem_mgr/system_mem.c",0x1a1);
        goto LAB_0046961a;
      }
      if (*(int *)(lVar4 + 4) == 0xd) {
        iVar10 = memCreateKernelMapping_IMPL(lVar14,3,0);
        if (iVar10 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar10,"memCreateKernelMapping(pMemory, NV_PROTECT_READ_WRITE, NV_FALSE)",
                     "src/kernel/mem_mgr/system_mem.c",0x1ad);
          goto LAB_0046960f;
        }
        if (*(char *)(lVar5 + 0x908) == '\0') goto LAB_004694bc;
        uVar9 = *(uint *)(lVar4 + 8);
        if (*(int *)(lVar4 + 4) == 0xd) {
          uVar9 = uVar9 | 0x2000000;
        }
      }
      else {
        if (*(char *)(lVar5 + 0x908) == '\0') goto LAB_004694bc;
        uVar9 = *(uint *)(lVar4 + 8);
      }
      iVar10 = RmDeprecatedConvertOs32ToOs02Flags
                         (*(undefined4 *)(lVar4 + 0x18),*(undefined4 *)(lVar4 + 0x1c),uVar9,
                          &local_168);
      if (iVar10 != 0) {
        nvCheckOkFailedNoLog
                  (1,iVar10,
                   "RmDeprecatedConvertOs32ToOs02Flags(pAllocData->attr, pAllocData->attr2, os32Flags, &os02Flags)"
                   ,"src/kernel/mem_mgr/system_mem.c",0x1bf);
        goto LAB_0046960f;
      }
      lVar16 = gpuGetRpc(lVar5);
      if (lVar16 != 0) {
        if ((*(char *)(lVar5 + 0x4913) == '\0') || (*(char *)(lVar5 + 0x491e) != '\0')) {
          if (*(char *)(lVar5 + 0x90a) == '\0') {
            iVar10 = (**(code **)(lVar16 + 0x50))
                               (lVar5,lVar16,uVar1,uVar2,local_138,local_e0,local_168);
          }
          else {
            puVar20 = &local_d0;
            for (lVar16 = 0x26; lVar16 != 0; lVar16 = lVar16 + -1) {
              *(undefined4 *)puVar20 = 0;
              puVar20 = (undefined8 *)((long)puVar20 + (ulong)bVar23 * -8 + 4);
            }
            local_b8 = *(undefined4 *)(puVar7 + 0xc);
            local_98 = memdescGetPteKindForGpu(puVar7,*puVar7);
            local_60 = puVar7[6];
            local_8c = (undefined4)puVar7[3];
            local_50 = memdescGetPteArrayForGpu(puVar7,*puVar7,1);
            local_d0 = 0;
            local_c8 = 0;
            local_48 = puVar7[6] + -1;
            local_40 = local_168 & 0xf000 | 0x40000010;
            iVar10 = (**(code **)(lVar5 + 0x3b60))
                               (lVar5 + 0x3b58,uVar1,uVar2,local_138,0x81,&local_d0,0x98,uVar21);
          }
          if (iVar10 != 0) {
LAB_004695ee:
            nvCheckOkFailedNoLog(4,iVar10,"rmStatus","src/kernel/mem_mgr/system_mem.c",0x1d7);
LAB_0046960f:
            memDestructCommon_IMPL(lVar14);
LAB_0046961a:
            memdescFree(puVar7);
LAB_00469517:
            cVar8 = memdescGetFlag(puVar7,0x8000000000000);
            if (cVar8 != '\0') {
              uVar21 = memdescGetPte(puVar7,0,0);
              (**(code **)(*(long *)(lVar5 + 0x1b78) + 0x3d8))(*(long *)(lVar5 + 0x1b78),uVar21);
            }
LAB_00468f90:
            memdescDestroy(puVar7);
            return iVar10;
          }
        }
        *(undefined1 *)(lVar14 + 0x1b0) = 1;
LAB_004694bc:
        *(undefined8 *)(lVar4 + 0x50) = 0;
        *(long *)(lVar4 + 0x40) = lVar13;
        stdmemDumpOutputAllocParams_IMPL(lVar4);
        return 0;
      }
      iVar10 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/system_mem.c",0x1ce);
      goto LAB_004695ee;
    }
    if (!bVar22) {
      nvCheckOkFailedNoLog(4,iVar10,"rmStatus","src/kernel/mem_mgr/system_mem.c",0x161);
      goto LAB_00469517;
    }
    uVar9 = *(uint *)(lVar4 + 0x18) >> 0x17 & 3;
    if (uVar9 != 2) {
      if (uVar9 == 3) {
        uVar12 = *(ulong *)(CSWTCH_32 + (ulong)(*(uint *)(lVar4 + 0x1c) >> 0x14 & 3) * 8);
        uVar15 = osGetPageSize();
        if (uVar12 != uVar15) {
          if (uVar12 == 0x20000000) {
            *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) | 0x1800000;
            uVar21 = 0x200000;
            *(uint *)(lVar4 + 0x1c) = *(uint *)(lVar4 + 0x1c) & 0xffcfffff | 0x100000;
          }
          else if (uVar12 < 0x20000001) {
            uVar21 = 0x10000;
            *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) & 0xfe7fffff | 0x1000000;
          }
          else {
            *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) | 0x1800000;
            uVar21 = 0x20000000;
            *(uint *)(lVar4 + 0x1c) = *(uint *)(lVar4 + 0x1c) & 0xffcfffff | 0x200000;
          }
          goto LAB_004690b9;
        }
      }
      else if (uVar9 == 1) {
        lVar14 = osGetPageSize();
        if (lVar14 != 0x1000) {
          nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x71,"_sysmemGetNextSmallestPageSize",4,
                       "NVRM: Invalid page size: 0x%llx\n",0x1000);
        }
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x51,"_sysmemGetNextSmallestPageSize",4,
                     "NVRM: Invalid page size attribute: 0x%x\n",0);
      }
LAB_00468f60:
      nvCheckOkFailedNoLog(4,iVar10,"rmStatus","src/kernel/mem_mgr/system_mem.c",0x156);
      goto LAB_00468f90;
    }
    lVar13 = osGetPageSize();
    if (lVar13 == 0x10000) goto LAB_00468f60;
    uVar21 = 0x1000;
    *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) & 0xfe7fffff | 0x800000;
LAB_004690b9:
    nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x158,"sysmemConstruct_IMPL",1,
                 "NVRM: Sysmem alloc failed, retrying with page size 0x%llx.\n",uVar21);
    memdescFree(puVar7);
    memdescDestroy(puVar7);
    local_130[1] = (undefined8 *)0x0;
  } while( true );
}


// ===== 004697f2 sysmemCtrlCmdGetSurfaceNumPhysPages_IMPL.cold =====

void sysmemCtrlCmdGetSurfaceNumPhysPages_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00469800 sysmemCtrlCmdGetSurfaceNumPhysPages_IMPL =====

int sysmemCtrlCmdGetSurfaceNumPhysPages_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x248);
  iVar3 = memdescGetAddressSpace(*(undefined8 *)(lVar1 + 0x118));
  if (iVar3 == 1) {
    iVar3 = osGetNumMemoryPages(*(undefined8 *)(lVar1 + 0x118),param_2);
    if (iVar3 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x203,"sysmemCtrlCmdGetSurfaceNumPhysPages_IMPL",
                 4,"NVRM: Failed to get sysmem pages\n");
    return iVar3;
  }
  nvAssertFailedNoLog("memdescGetAddressSpace(pMemory->pMemDesc) == ADDR_SYSMEM",
                      "src/kernel/mem_mgr/system_mem.c",0x1fd);
  return 0x56;
}


// ===== 004698a5 sysmemCtrlCmdGetSurfacePhysPages_IMPL.cold =====

void sysmemCtrlCmdGetSurfacePhysPages_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004698b0 sysmemCtrlCmdGetSurfacePhysPages_IMPL =====

int sysmemCtrlCmdGetSurfacePhysPages_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x248);
  iVar3 = memdescGetAddressSpace(*(undefined8 *)(lVar1 + 0x118));
  if (iVar3 == 1) {
    iVar3 = osGetMemoryPages(*(undefined8 *)(lVar1 + 0x118),*param_2,param_2 + 1);
    if (iVar3 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x21a,"sysmemCtrlCmdGetSurfacePhysPages_IMPL",4,
                 "NVRM: Failed to get sysmem pages\n");
    return iVar3;
  }
  nvAssertFailedNoLog("memdescGetAddressSpace(pMemory->pMemDesc) == ADDR_SYSMEM",
                      "src/kernel/mem_mgr/system_mem.c",0x213);
  return 0x56;
}


// ===== 00469960 sysmemInitAllocRequest_SOC =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int sysmemInitAllocRequest_SOC(long param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  uint local_40;
  uint local_3c [3];
  
  lVar1 = *param_3;
  local_40 = *(uint *)(lVar1 + 0x18);
  local_3c[0] = *(uint *)(lVar1 + 0x1c);
  if (*(long *)(lVar1 + 0x40) == 0) {
    nvCheckFailedNoLog(4,"pAllocParams->size != 0","src/kernel/mem_mgr/system_mem.c",0x232);
  }
  else if (*(uint *)(lVar1 + 4) < 0x12) {
    if ((local_40 & 0x2000000) != 0) {
      local_40 = local_40 & 0xf9ffffff | 0x2000000;
    }
    if ((*(uint *)(lVar1 + 8) & 0x10) == 0) {
      local_3c[0] = local_3c[0] & 0xfffffff0;
      puVar7 = (undefined8 *)param_3[4];
      bVar2 = false;
      uVar4 = local_40 & 0xffffc3ff;
      if (puVar7 == (undefined8 *)0x0) {
        uVar4 = local_40 & 0x18000000;
        local_40 = local_40 & 0xffffc3ff;
        iVar5 = memdescCreate(param_3 + 4,param_1,*(long *)(lVar1 + 0x40),0,uVar4 == 0x10000000,1,1,
                              0x20000);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "memdescCreate(&pAllocRequest->pMemDesc, pGpu, pAllocParams->size, 0, bContig, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_SKIP_RESOURCE_COMPUTE)"
                     ,"src/kernel/mem_mgr/system_mem.c",0x250);
          return iVar5;
        }
        bVar2 = true;
        puVar7 = (undefined8 *)param_3[4];
        uVar4 = local_40;
      }
      local_40 = uVar4;
      memdescSetPteKindForGpu(puVar7,*puVar7,*(undefined4 *)(lVar1 + 0x20));
      *(undefined4 *)(puVar7 + 0x13) = 0;
      cVar3 = memdescGetContiguity(param_3[4],1);
      uVar4 = local_40 & 0xe7ffffff;
      local_40 = uVar4 | 0x8000000;
      if (cVar3 != '\0') {
        local_40 = uVar4 | 0x10000000;
      }
      lVar6 = (**(code **)(*(long *)(param_1 + 0x1b78) + 0x168))
                        (*(long *)(param_1 + 0x1b78),*(undefined4 *)((long)param_3 + 0x6c),
                         *(undefined8 *)(lVar1 + 0x40),*(undefined4 *)(lVar1 + 0x20),
                         *(undefined4 *)(lVar1 + 8),&local_40,local_3c);
      if (lVar6 != 0) {
        *(undefined8 *)(lVar1 + 0x50) = 0xffffffffffffffff;
        *(ulong *)(lVar1 + 0x18) = CONCAT44(local_3c[0],local_40);
        return 0;
      }
      nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x273,"sysmemInitAllocRequest_SOC",4,
                   "NVRM: memmgrDeterminePageSize failed, status: 0x%x\n",0x40);
      if (bVar2) {
        memdescDestroy(param_3[4]);
        param_3[4] = 0;
      }
      return 0x40;
    }
    nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x242,"sysmemInitAllocRequest_SOC",4,
                 "NVRM: Fixed allocation on sysmem not allowed.\n");
  }
  else {
    nvCheckFailedNoLog(4,"(pAllocParams->type < NVOS32_NUM_MEM_TYPES)",
                       "src/kernel/mem_mgr/system_mem.c",0x235);
  }
  return 0x1f;
}


// ===== 00469c20 sysmemAllocResources =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int sysmemAllocResources(undefined8 param_1,long param_2,long *param_3,long param_4)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char local_41;
  undefined8 local_40 [2];
  
  lVar1 = *param_3;
  local_40[0] = 0;
  uVar3 = *(uint *)(lVar1 + 8);
  local_41 = '\0';
  if ((uVar3 & 0x26480400) == 0) {
    if ((*(byte *)(lVar1 + 0x1c) & 0x40) == 0) {
      if (*(int *)(lVar1 + 0x6c) == 0) {
        uVar5 = *(uint *)(lVar1 + 0x18);
        if (0x3fffffff < uVar3) {
          nvAssertFailedNoLog("!(pVidHeapAlloc->flags & NVOS32_ALLOC_FLAGS_WPR1) && !(pVidHeapAlloc->flags & NVOS32_ALLOC_FLAGS_WPR2)"
                              ,"src/kernel/mem_mgr/system_mem.c",0x2e8);
          uVar3 = *(uint *)(lVar1 + 8);
        }
        if ((uVar3 & 0x10) == 0) {
          iVar4 = memUtilsAllocMemDesc
                            (param_1,param_3,param_4,local_40,0,1,(uVar5 & 0x18000000) == 0x10000000
                            );
          if (iVar4 == 0) {
            *(undefined4 *)(lVar1 + 0x18) = *(undefined4 *)(param_4 + 0x44);
            *(undefined4 *)(lVar1 + 0x1c) = *(undefined4 *)(param_4 + 0x48);
            cVar2 = memdescGetContiguity(param_3[4],1,&local_41);
            uVar5 = *(uint *)(lVar1 + 0x18) & 0xe7ffffff;
            uVar3 = uVar5 | 0x8000000;
            if (cVar2 != '\0') {
              uVar3 = uVar5 | 0x10000000;
            }
            *(uint *)(lVar1 + 0x18) = uVar3;
            *(undefined8 *)(lVar1 + 0x50) = *(undefined8 *)(param_4 + 0x38);
            if ((undefined4 *)param_3[3] == (undefined4 *)0x0) {
              return 0;
            }
            *(undefined4 *)param_3[3] = *(undefined4 *)(param_4 + 0x44);
            *(undefined4 *)(param_3[3] + 4) = *(undefined4 *)(param_4 + 0x48);
            *(undefined4 *)(param_3[3] + 0x10) = *(undefined4 *)(param_4 + 4);
            *(undefined4 *)(param_3[3] + 8) = *(undefined4 *)(param_4 + 0x50);
            *(undefined4 *)(param_3[3] + 0xc) = *(undefined4 *)(param_4 + 0xa4);
            *(undefined4 *)(param_3[3] + 0x10) = *(undefined4 *)(param_4 + 4);
            return 0;
          }
          nvCheckOkFailedNoLog
                    (4,iVar4,
                     "memUtilsAllocMemDesc(pGpu, pAllocRequest, pFbAllocInfo, &pMemDesc, NULL, ADDR_SYSMEM, bContig, &bAllocedMemDesc)"
                     ,"src/kernel/mem_mgr/system_mem.c",0x2f2);
          goto LAB_00469da4;
        }
        nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x2ec,"sysmemAllocResources",4,
                     "NVRM: Expected fixed address allocation\n");
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x2e2,"sysmemAllocResources",4,
                     "NVRM: VA space handle used with physical allocation\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x2db,"sysmemAllocResources",4,
                   "NVRM: Virtual-only 32-bit pointer attr used with physical allocation\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/system_mem.c",0x2d4,"sysmemAllocResources",4,
                 "NVRM: Virtual-only flag used with physical allocation\n");
  }
  iVar4 = 0x1f;
LAB_00469da4:
  (**(code **)(param_2 + 0x170))(param_1,param_2,param_4);
  if (local_41 != '\0') {
    memdescDestroy(param_3[4]);
    param_3[4] = 0;
  }
  return iVar4;
}


// ===== 00469eb0 sysmemInitAllocRequest_HMM =====

int sysmemInitAllocRequest_HMM(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  lVar3 = portMemAllocNonPaged(0xc0);
  if (lVar3 == 0) {
    lVar4 = 0;
    nvAssertOkFailedNoLog(0x51,"pFbAllocInfo != NULL","src/kernel/mem_mgr/system_mem.c",0x295);
    iVar2 = 0x51;
  }
  else {
    lVar4 = portMemAllocNonPaged(0x14);
    if (lVar4 == 0) {
      nvAssertOkFailedNoLog
                (0x51,"pFbAllocPageFormat != NULL","src/kernel/mem_mgr/system_mem.c",0x298);
      iVar2 = 0x51;
    }
    else {
      portMemSet(lVar3,0,0xc0);
      portMemSet(lVar4,0,0x14);
      *(long *)(lVar3 + 0x90) = lVar4;
      memUtilsInitFBAllocInfo
                (*param_3,lVar3,*(undefined4 *)((long)param_3 + 0x6c),*(undefined4 *)(param_3 + 0xe)
                );
      iVar2 = memmgrAllocResources_IMPL(param_1,uVar1,param_3,lVar3);
      uVar6 = 0x2a0;
      pcVar5 = "memmgrAllocResources(pGpu, pMemoryManager, pAllocRequest, pFbAllocInfo)";
      if (iVar2 == 0) {
        iVar2 = sysmemAllocResources(param_1,uVar1,param_3,lVar3,param_2);
        if (iVar2 == 0) goto LAB_00469f7d;
        uVar6 = 0x2a4;
        pcVar5 = 
        "sysmemAllocResources(pGpu, pMemoryManager, pAllocRequest, pFbAllocInfo, pSystemMemory)";
      }
      nvCheckOkFailedNoLog(4,iVar2,pcVar5,"src/kernel/mem_mgr/system_mem.c",uVar6);
    }
  }
LAB_00469f7d:
  portMemFree(lVar4);
  portMemFree(lVar3);
  return iVar2;
}


// ===== 0046a027 sysmemDestruct_IMPL.cold =====

void sysmemDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046a040 sysmemDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void sysmemDestruct_IMPL(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  char cVar6;
  undefined8 uVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar1 = *(long *)(param_1 + 0x248);
  plVar2 = *(long **)(lVar1 + 0x118);
  lVar3 = *plVar2;
  lVar4 = *(long *)(lVar3 + 0x1b78);
  cVar6 = memdescGetFlag(plVar2,0x8000000000000);
  if (cVar6 == '\0') {
    if (((*(uint *)((long)plVar2 + 0x94) < 2) && (lVar1 = *(long *)(lVar1 + 0x1a8), lVar1 != 0)) &&
       (*(int *)(lVar1 + 0x10) != 0)) {
      lVar1 = *(long *)(lVar4 + 0x4b0);
      if (lVar1 != 0) {
        sysmemscrubScrubAndFree_IMPL(lVar1,plVar2);
        return;
      }
      nvAssertFailedNoLog("pMemoryManager->pSysmemScrubber != NULL",
                          "src/kernel/mem_mgr/system_mem.c",0x335);
      return;
    }
    return;
  }
  uVar7 = memdescGetPte(plVar2,0,0);
  lVar1 = *(long *)(lVar3 + 0x1b78);
  (**(code **)(lVar1 + 0x3d8))(lVar1,uVar7);
  return;
}


// ===== 0046a120 vaListMapCount =====

int vaListMapCount(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x75);
  }
  else {
    if (*param_1 == 0) {
      return ((*(long *)(param_1 + 4) != 0) + 1) - (uint)(*(long *)(param_1 + 10) == 0);
    }
    if (*param_1 == 1) {
      iVar1 = mapCount_IMPL(param_1 + 2);
      return iVar1 + -1 + (uint)(iVar1 == 0);
    }
  }
  return 0;
}


// ===== 0046a190 vaListInit =====

undefined8 vaListInit(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    portMemSet(param_1,0,0x40);
    *param_1 = 0;
    *(undefined1 *)(param_1 + 2) = 1;
    return 0;
  }
  nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x9a);
  return 0x1f;
}


// ===== 0046a1f0 vaListDestroy =====

void vaListDestroy(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  long *plVar3;
  long lVar4;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0xcc);
    return;
  }
  iVar1 = vaListMapCount();
  if (iVar1 != 0) {
    uVar2 = vaListMapCount(param_1);
    nvDbg_Printf("src/kernel/mem_mgr/vaddr_list.c",0xd4,"vaListDestroy",4,
                 "NVRM: non-zero mapCount(pVaList): 0x%x\n",uVar2);
  }
  if (*param_1 != 0) {
    if (*param_1 == 1) {
      param_1 = param_1 + 2;
      plVar3 = (long *)mapFind_IMPL(param_1,0);
      if (plVar3 != (long *)0x0) {
        if (*plVar3 != 0) {
          nvAssertFailedNoLog("pVaInfo->vAddr == 0","src/kernel/mem_mgr/vaddr_list.c",0xe7);
        }
        if (plVar3[1] != 0) {
          nvAssertFailedNoLog("pVaInfo->refCnt == 0","src/kernel/mem_mgr/vaddr_list.c",0xe8);
        }
        lVar4 = plVar3[2];
        if (lVar4 == 0) {
          nvAssertFailedNoLog("pVaInfo->pVaListInfo","src/kernel/mem_mgr/vaddr_list.c",0xe9);
          lVar4 = plVar3[2];
        }
        portMemFree(lVar4);
        plVar3[2] = 0;
        mapRemove_IMPL(param_1,plVar3);
      }
      mapDestroy_IMPL(param_1);
      return;
    }
    return;
  }
  portMemSet(param_1,0,0x40);
  return;
}


// ===== 0046a380 vaListGetManaged =====

undefined1 vaListGetManaged(int *param_1)

{
  long lVar1;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x12d);
  }
  else {
    if (*param_1 == 0) {
      return (char)param_1[2];
    }
    if (*param_1 != 1) {
      return 1;
    }
    lVar1 = mapFind_IMPL(param_1 + 2,0);
    if (lVar1 != 0) {
      return **(undefined1 **)(lVar1 + 0x10);
    }
    nvAssertFailedNoLog("pVaInfo != NULL","src/kernel/mem_mgr/vaddr_list.c",0x13b);
  }
  return 0;
}


// ===== 0046a410 vaListClear =====

void vaListClear(int *param_1)

{
  undefined1 uVar1;
  long lVar2;
  
  uVar1 = vaListGetManaged();
  if (param_1 != (int *)0x0) {
    if (*param_1 == 1) {
      lVar2 = mapFind_IMPL(param_1 + 2,0);
      if (lVar2 != 0) {
        portMemFree(*(undefined8 *)(lVar2 + 0x10));
      }
      mapDestroy_IMPL(param_1 + 2);
    }
    portMemSet(param_1,0,0x40);
    *param_1 = 0;
    *(undefined1 *)(param_1 + 2) = uVar1;
    return;
  }
  nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0xaa);
  return;
}


// ===== 0046a4b0 vaListSetManaged =====

undefined8 vaListSetManaged(int *param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x108);
    return 0x1f;
  }
  if (*param_1 == 0) {
    if (*(long *)(param_1 + 10) == 0 && *(long *)(param_1 + 4) == 0) goto LAB_0046a560;
LAB_0046a52a:
    cVar1 = vaListGetManaged(param_1);
    if (cVar1 != param_2) {
      nvAssertFailedNoLog("(vaListMapCount(pVaList) == 0) || (vaListGetManaged(pVaList) == bManaged)"
                          ,"src/kernel/mem_mgr/vaddr_list.c",0x10b);
      return 0x40;
    }
  }
  else {
    if (*param_1 != 1) {
      return 0;
    }
    uVar2 = mapCount_IMPL(param_1 + 2);
    if (1 < uVar2) goto LAB_0046a52a;
  }
  if (*param_1 != 0) {
    if (*param_1 != 1) {
      return 0;
    }
    lVar3 = mapFind_IMPL(param_1 + 2,0);
    if (lVar3 != 0) {
      **(char **)(lVar3 + 0x10) = param_2;
      return 0;
    }
    nvAssertFailedNoLog("pVaInfo != NULL","src/kernel/mem_mgr/vaddr_list.c",0x11b);
    return 0x40;
  }
LAB_0046a560:
  *(char *)(param_1 + 2) = param_2;
  return 0;
}


// ===== 0046a5b0 vaListAddVa =====

int vaListAddVa(int *param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x152);
  }
  else {
    if (param_2 != 0) {
      while( true ) {
        if (*param_1 != 0) {
          if (*param_1 == 1) {
            plVar3 = (long *)mapFind_IMPL(param_1 + 2,param_2);
            if (plVar3 != (long *)0x0) {
              lVar1 = plVar3[1];
              if (lVar1 == 0) {
                nvAssertFailedNoLog("pVaInfo->refCnt > 0","src/kernel/mem_mgr/vaddr_list.c",0x191);
                return 0x40;
              }
              if (lVar1 != -1) {
                if (*plVar3 != param_3) {
                  nvAssertFailedNoLog("pVaInfo->vAddr == vAddr","src/kernel/mem_mgr/vaddr_list.c",
                                      0x193);
                  return 0x40;
                }
                plVar3[1] = lVar1 + 1;
                return 0;
              }
              nvAssertFailedNoLog("pVaInfo->refCnt < NV_U64_MAX","src/kernel/mem_mgr/vaddr_list.c",
                                  0x192);
              return 0x40;
            }
            plVar3 = (long *)mapInsertNew_IMPL(param_1 + 2,param_2);
            if (plVar3 == (long *)0x0) {
              nvAssertFailedNoLog("pVaInfo != NULL","src/kernel/mem_mgr/vaddr_list.c",0x199);
              return 0x1a;
            }
            *plVar3 = param_3;
            plVar3[1] = 1;
          }
          return 0;
        }
        if (*(long *)(param_1 + 4) == param_2) {
          lVar1 = *(long *)(param_1 + 8);
          if (lVar1 == 0) {
            nvAssertFailedNoLog("pVaList->impl.simple.entries[0].refCnt > 0",
                                "src/kernel/mem_mgr/vaddr_list.c",0x15b);
          }
          else if (lVar1 == -1) {
            nvAssertFailedNoLog("pVaList->impl.simple.entries[0].refCnt < NV_U64_MAX",
                                "src/kernel/mem_mgr/vaddr_list.c",0x15c);
          }
          else {
            if (*(long *)(param_1 + 6) == param_3) {
              *(long *)(param_1 + 8) = lVar1 + 1;
              return 0;
            }
            nvAssertFailedNoLog("pVaList->impl.simple.entries[0].vAddr == vAddr",
                                "src/kernel/mem_mgr/vaddr_list.c",0x15d);
          }
          return 0x40;
        }
        if (*(long *)(param_1 + 10) == param_2) break;
        iVar2 = vaListMapCount();
        if (iVar2 != 2) {
          if (*(long *)(param_1 + 4) == 0) {
            *(long *)(param_1 + 4) = param_2;
            *(long *)(param_1 + 6) = param_3;
            param_1[8] = 1;
            param_1[9] = 0;
            return 0;
          }
          if (*(long *)(param_1 + 10) != 0) {
            nvAssertFailedNoLog("Simple va list full","src/kernel/mem_mgr/vaddr_list.c",0x185);
            return 0x40;
          }
          *(long *)(param_1 + 10) = param_2;
          *(long *)(param_1 + 0xc) = param_3;
          param_1[0xe] = 1;
          param_1[0xf] = 0;
          return 0;
        }
        iVar2 = vaListInitMap();
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      lVar1 = *(long *)(param_1 + 0xe);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pVaList->impl.simple.entries[1].refCnt > 0",
                            "src/kernel/mem_mgr/vaddr_list.c",0x164);
        return 0x40;
      }
      if (lVar1 != -1) {
        if (*(long *)(param_1 + 0xc) != param_3) {
          nvAssertFailedNoLog("pVaList->impl.simple.entries[1].vAddr == vAddr",
                              "src/kernel/mem_mgr/vaddr_list.c",0x166);
          return 0x40;
        }
        *(long *)(param_1 + 0xe) = lVar1 + 1;
        return 0;
      }
      nvAssertFailedNoLog("pVaList->impl.simple.entries[1].refCnt < NV_U64_MAX",
                          "src/kernel/mem_mgr/vaddr_list.c",0x165);
      return 0x40;
    }
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/mem_mgr/vaddr_list.c",0x153);
  }
  return 0x1f;
}


// ===== 0046a930 vaListInitMap =====

int vaListInitMap(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  long lVar10;
  
  if (param_1 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x2a);
    return 0x1f;
  }
  puVar8 = (undefined1 *)portMemAllocNonPaged(1);
  if (puVar8 == (undefined1 *)0x0) {
    return 0x1a;
  }
  *puVar8 = *(undefined1 *)(param_1 + 2);
  uVar1 = *(undefined8 *)(param_1 + 6);
  uVar2 = *(undefined8 *)(param_1 + 4);
  uVar3 = *(undefined8 *)(param_1 + 10);
  uVar4 = *(undefined8 *)(param_1 + 8);
  uVar5 = *(undefined8 *)(param_1 + 0xc);
  uVar6 = *(undefined8 *)(param_1 + 0xe);
  portMemSet(param_1,0,0x40);
  uVar9 = portMemAllocatorGetGlobalNonPaged();
  mapInit_IMPL(param_1 + 2,uVar9,0x18);
  lVar10 = mapInsertNew_IMPL(param_1 + 2,0);
  if (lVar10 == 0) {
    mapDestroy_IMPL(param_1 + 2);
    portMemFree(puVar8);
    return 0x1a;
  }
  *(undefined1 **)(lVar10 + 0x10) = puVar8;
  *param_1 = 1;
  iVar7 = vaListAddVa(param_1,uVar2,uVar1);
  if ((iVar7 == 0) && (iVar7 = vaListAddVa(param_1,uVar3,uVar5), iVar7 == 0)) {
    lVar10 = mapFind_IMPL(param_1 + 2,uVar2);
    if (lVar10 != 0) {
      *(undefined8 *)(lVar10 + 8) = uVar4;
      lVar10 = mapFind_IMPL(param_1 + 2,uVar3);
      if (lVar10 != 0) {
        *(undefined8 *)(lVar10 + 8) = uVar6;
        return 0;
      }
    }
    vaListDestroy(param_1);
    return 0x40;
  }
  vaListDestroy(param_1);
  return iVar7;
}


// ===== 0046ab10 vaListRemoveVa =====

int vaListRemoveVa(int *param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x1b2);
  }
  else {
    if (param_2 != 0) {
      iVar1 = *param_1;
      if (iVar1 == 0) {
        if (*(long *)(param_1 + 4) == param_2) {
          if (*(long *)(param_1 + 8) == 0) {
            nvAssertFailedNoLog("pVaList->impl.simple.entries[0].refCnt > 0",
                                "src/kernel/mem_mgr/vaddr_list.c",0x1bb);
            return 0x40;
          }
          lVar2 = *(long *)(param_1 + 8) + -1;
          *(long *)(param_1 + 8) = lVar2;
          if (lVar2 == 0) {
            param_1[4] = 0;
            param_1[5] = 0;
            param_1[6] = 0;
            param_1[7] = 0;
            return iVar1;
          }
        }
        else {
          if (*(long *)(param_1 + 10) != param_2) {
            return 0x57;
          }
          if (*(long *)(param_1 + 0xe) == 0) {
            nvAssertFailedNoLog("pVaList->impl.simple.entries[1].refCnt > 0",
                                "src/kernel/mem_mgr/vaddr_list.c",0x1c6);
            return 0x40;
          }
          lVar2 = *(long *)(param_1 + 0xe) + -1;
          *(long *)(param_1 + 0xe) = lVar2;
          if (lVar2 == 0) {
            param_1[10] = 0;
            param_1[0xb] = 0;
            param_1[0xc] = 0;
            param_1[0xd] = 0;
            return iVar1;
          }
        }
      }
      else if (iVar1 == 1) {
        lVar2 = mapFind_IMPL(param_1 + 2);
        if (lVar2 == 0) {
          return 0x57;
        }
        if (*(long *)(lVar2 + 8) == 0) {
          nvAssertFailedNoLog("pVaInfo->refCnt > 0","src/kernel/mem_mgr/vaddr_list.c",0x1db);
          return 0x40;
        }
        lVar3 = *(long *)(lVar2 + 8) + -1;
        *(long *)(lVar2 + 8) = lVar3;
        if (lVar3 == 0) {
          mapRemove_IMPL(param_1 + 2);
        }
      }
      return 0;
    }
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/mem_mgr/vaddr_list.c",0x1b3);
  }
  return 0x1f;
}


// ===== 0046acc0 vaListFindVa =====

int vaListFindVa(int *param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x1fe);
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/mem_mgr/vaddr_list.c",0x1ff);
  }
  else {
    if (param_3 != (undefined8 *)0x0) {
      iVar1 = *param_1;
      if (iVar1 == 0) {
        if (*(long *)(param_1 + 4) == param_2) {
          if (*(long *)(param_1 + 8) != 0) {
            *param_3 = *(undefined8 *)(param_1 + 6);
            return iVar1;
          }
          nvAssertFailedNoLog("pVaList->impl.simple.entries[0].refCnt > 0",
                              "src/kernel/mem_mgr/vaddr_list.c",0x208);
        }
        else {
          if (*(long *)(param_1 + 10) != param_2) {
            return 0x57;
          }
          if (*(long *)(param_1 + 0xe) != 0) {
            *param_3 = *(undefined8 *)(param_1 + 0xc);
            return iVar1;
          }
          nvAssertFailedNoLog("pVaList->impl.simple.entries[1].refCnt > 0",
                              "src/kernel/mem_mgr/vaddr_list.c",0x20d);
        }
        return 0x40;
      }
      if (iVar1 == 1) {
        puVar2 = (undefined8 *)mapFind_IMPL(param_1 + 2);
        if (puVar2 == (undefined8 *)0x0) {
          return 0x57;
        }
        if (puVar2[1] == 0) {
          nvAssertFailedNoLog("pVaInfo->refCnt > 0","src/kernel/mem_mgr/vaddr_list.c",0x21c);
          return 0x40;
        }
        *param_3 = *puVar2;
      }
      return 0;
    }
    nvAssertFailedNoLog("pVaddr != NULL","src/kernel/mem_mgr/vaddr_list.c",0x200);
  }
  return 0x1f;
}


// ===== 0046ae30 vaListGetRefCount =====

undefined8 vaListGetRefCount(int *param_1,long param_2,long *param_3)

{
  long lVar1;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x239);
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/mem_mgr/vaddr_list.c",0x23a);
  }
  else {
    if (param_3 != (long *)0x0) {
      if (*param_1 != 0) {
        if (*param_1 == 1) {
          lVar1 = mapFind_IMPL(param_1 + 2);
          if (lVar1 == 0) {
            return 0x57;
          }
          if (*(long *)(lVar1 + 8) == 0) {
            nvAssertFailedNoLog("pVaInfo->refCnt > 0","src/kernel/mem_mgr/vaddr_list.c",599);
            return 0x40;
          }
          *param_3 = *(long *)(lVar1 + 8);
        }
        return 0;
      }
      if (*(long *)(param_1 + 4) == param_2) {
        lVar1 = *(long *)(param_1 + 8);
        if (lVar1 != 0) goto LAB_0046aebd;
        nvAssertFailedNoLog("pVaList->impl.simple.entries[0].refCnt > 0",
                            "src/kernel/mem_mgr/vaddr_list.c",0x243);
      }
      else {
        if (*(long *)(param_1 + 10) != param_2) {
          return 0x57;
        }
        lVar1 = *(long *)(param_1 + 0xe);
        if (lVar1 != 0) {
LAB_0046aebd:
          *param_3 = lVar1;
          return 0;
        }
        nvAssertFailedNoLog("pVaList->impl.simple.entries[1].refCnt > 0",
                            "src/kernel/mem_mgr/vaddr_list.c",0x248);
      }
      return 0x40;
    }
    nvAssertFailedNoLog("pRefCount != NULL","src/kernel/mem_mgr/vaddr_list.c",0x23b);
  }
  return 0x1f;
}


// ===== 0046afa0 vaListSetRefCount =====

int vaListSetRefCount(int *param_1,long param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("pVaList != NULL","src/kernel/mem_mgr/vaddr_list.c",0x274);
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/mem_mgr/vaddr_list.c",0x275);
  }
  else {
    if (param_3 != 0) {
      iVar1 = *param_1;
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          lVar2 = mapFind_IMPL(param_1 + 2);
          if (lVar2 == 0) {
            return 0x57;
          }
          *(long *)(lVar2 + 8) = param_3;
        }
        return 0;
      }
      if (*(long *)(param_1 + 4) != param_2) {
        if (*(long *)(param_1 + 10) != param_2) {
          return 0x57;
        }
        *(long *)(param_1 + 0xe) = param_3;
        return iVar1;
      }
      *(long *)(param_1 + 8) = param_3;
      return iVar1;
    }
    nvAssertFailedNoLog("refCount != 0","src/kernel/mem_mgr/vaddr_list.c",0x276);
  }
  return 0x1f;
}


// ===== 0046b080 vaspaceIncRefCnt_IMPL =====

void vaspaceIncRefCnt_IMPL(long param_1)

{
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}


// ===== 0046b090 vaspaceDecRefCnt_IMPL =====

void vaspaceDecRefCnt_IMPL(long param_1)

{
  if (*(int *)(param_1 + 0x58) != 0) {
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
    return;
  }
  nvAssertFailedNoLog("pVAS->refCnt != 0","src/kernel/mem_mgr/vaspace.c",0x2f);
  return;
}


// ===== 0046b0c0 vaspaceFillAllocParams_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int vaspaceFillAllocParams_IMPL
              (long *param_1,long param_2,ulong *param_3,undefined8 param_4,ulong *param_5,
              ulong *param_6,undefined8 param_7,byte *param_8)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  ulong uVar14;
  ulong uVar15;
  
  uVar4 = (**(code **)(*param_1 + 0x70))();
  uVar5 = gpumgrGetDefaultPrimaryGpu((int)param_1[9]);
  lVar7 = gpumgrGetGpu(uVar5);
  cVar1 = *(char *)(*(long *)(lVar7 + 0x1bb8) + 0x1c1);
  cVar2 = *(char *)(*(long *)(lVar7 + 0x1bb8) + 0x1c5);
  iVar6 = (**(code **)(*param_1 + 0x48))(param_1,param_2,param_4,param_3,param_7);
  if (iVar6 == 0) {
    *param_8 = *param_8 & 0xdf | (*(byte *)(param_2 + 0x40) & 1) << 5;
    lVar7 = *(long *)(param_2 + 0x90);
    if ((*(uint *)(lVar7 + 8) & 0x10) == 0) {
      if ((*(uint *)(lVar7 + 8) & 0x20000) == 0) {
        uVar8 = (**(code **)(*param_1 + 0x58))(param_1);
        *param_5 = uVar8;
        uVar8 = (**(code **)(*param_1 + 0x60))(param_1);
        *param_6 = uVar8;
        if ((cVar1 != '\0') && ((uVar4 & 0x1000000) == 0)) {
          if (0xffffffffff < uVar8) {
            uVar8 = 0xffffffffff;
          }
          *param_6 = uVar8;
        }
        lVar7 = *(long *)(param_2 + 0x90);
      }
      else {
        uVar8 = *param_6;
      }
      bVar3 = *(byte *)(lVar7 + 4);
    }
    else {
      uVar8 = *(ulong *)(param_2 + 0x38);
      *param_5 = uVar8;
      uVar8 = (uVar8 - 1) + *param_3;
      *param_6 = uVar8;
      lVar7 = *(long *)(param_2 + 0x90);
      bVar3 = *(byte *)(lVar7 + 4);
    }
    if ((bVar3 & 0x40) == 0) {
      uVar9 = *param_3;
      uVar15 = *param_5;
      uVar14 = (uVar8 - uVar15) + 1;
      if (((cVar2 != '\0') && (0x100000000 < uVar14 - uVar9)) &&
         ((*(uint *)(lVar7 + 8) & 0x20010) == 0 && (uVar4 & 0x1000000) == 0)) {
        if (uVar15 < 0x100000000) {
          uVar15 = 0x100000000;
        }
        *param_5 = uVar15;
        uVar8 = *param_6;
        uVar9 = *param_3;
        uVar14 = (uVar8 + 1) - uVar15;
      }
    }
    else {
      if (0xffffffff < uVar8) {
        uVar8 = 0xffffffff;
      }
      *param_6 = uVar8;
      uVar15 = *param_5;
      uVar9 = *param_3;
      uVar14 = (uVar8 - uVar15) + 1;
    }
    if (uVar14 < uVar9) {
      iVar6 = 0x1a;
      nvDbg_Printf("src/kernel/mem_mgr/vaspace.c",0x80,"vaspaceFillAllocParams_IMPL",4,
                   "NVRM: Requested size 0x%llx more than available range. RangeLo=0x%llx, RangeHi=0x%llx\n"
                   ,uVar9,uVar15,uVar8);
      nvAssertFailedNoLog(&DAT_00d86297,"src/kernel/mem_mgr/vaspace.c",0x83);
    }
    else {
      bVar3 = *param_8;
      bVar10 = *(byte *)(*(long *)(param_2 + 0x90) + 8) >> 2 & 1;
      *param_8 = bVar3 & 0xfe | bVar10;
      bVar11 = *(byte *)(*(long *)(param_2 + 0x90) + 0xb) >> 4 & 2;
      *param_8 = bVar3 & 0xfc | bVar10 | bVar11;
      bVar12 = *(byte *)(*(long *)(param_2 + 0x90) + 10) >> 4 & 4;
      *param_8 = bVar3 & 0xf8 | bVar10 | bVar11 | bVar12;
      bVar13 = *(char *)(*(long *)(param_2 + 0x90) + 9) * '\x02' & 8;
      *param_8 = bVar3 & 0xf0 | bVar10 | bVar11 | bVar12 | bVar13;
      *param_8 = bVar3 & 0xe0 | bVar10 | bVar11 | bVar12 | bVar13 |
                 (*(byte *)(*(long *)(param_2 + 0x90) + 0xb) & 4) << 2;
      iVar6 = 0;
    }
    return iVar6;
  }
  nvAssertOkFailedNoLog
            (iVar6,
             "vaspaceApplyDefaultAlignment(pVAS, pAllocInfo, pAlign, pSize, pPageSizeLockMask)",
             "src/kernel/mem_mgr/vaspace.c",0x4a);
  return iVar6;
}


// ===== 0046b3d0 vaspaceGetVaStart_IMPL =====

undefined8 vaspaceGetVaStart_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x60);
}


// ===== 0046b3e0 vaspaceGetVaLimit_IMPL =====

undefined8 vaspaceGetVaLimit_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x68);
}


// ===== 0046b3f0 vaspaceInvalidateTlb_IMPL =====

void vaspaceInvalidateTlb_IMPL(void)

{
  nvAssertFailedNoLog(&DAT_00d86297,"src/kernel/mem_mgr/vaspace.c",0xad);
  return;
}


// ===== 0046b410 vaspaceGetByHandleOrDeviceDefault_IMPL =====

int vaspaceGetByHandleOrDeviceDefault_IMPL
              (long param_1,ulong param_2,int param_3,undefined8 *param_4)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  long local_40;
  long local_38;
  long local_30 [2];
  
  local_40 = 0;
  local_38 = 0;
  if (param_3 == 0) {
    if ((int)param_2 == 0) {
      return 0x33;
    }
    iVar1 = deviceGetByHandle_IMPL(param_1,param_2,&local_40);
    if (iVar1 == 0) {
LAB_0046b45f:
      if (*(int *)(local_40 + 0x1d0) == 2) {
        nvDbg_Printf("src/kernel/mem_mgr/vaspace.c",0xe7,"vaspaceGetByHandleOrDeviceDefault_IMPL",4,
                     "NVRM: VA mode %d (PRIVATE) doesn\'t support allocating an implicit VA space.\n"
                     ,2);
        return 0x40;
      }
      iVar1 = deviceGetDefaultVASpace_IMPL(local_40,param_4);
      return iVar1;
    }
    iVar1 = subdeviceGetByHandle_IMPL(param_1,param_2 & 0xffffffff,local_30);
    if (iVar1 == 0) {
      local_40 = *(long *)(local_30[0] + 0x338);
      goto LAB_0046b45f;
    }
  }
  else {
    iVar1 = serverutilGetResourceRefWithType
                      (*(undefined4 *)(param_1 + 0x48),param_3,"A RTXA6000-4C",&local_38);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/mem_mgr/vaspace.c",0xcc,"vaspaceGetByHandleOrDeviceDefault_IMPL",4,
                   "NVRM: Invalid object handle 0x%x\n",param_3);
      return iVar1;
    }
    if (*(long *)(local_38 + 0x18) == 0) {
      iVar1 = deviceGetByHandle_IMPL(param_1,0,&local_40);
      if (iVar1 == 0) goto LAB_0046b4de;
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(*(long *)(local_38 + 0x18) + 0x10);
      iVar1 = deviceGetByHandle_IMPL(param_1,uVar3,&local_40);
      if (iVar1 == 0) goto LAB_0046b4de;
    }
    iVar1 = subdeviceGetByHandle_IMPL(param_1,uVar3,local_30);
    if (iVar1 == 0) {
      local_40 = *(long *)(local_30[0] + 0x338);
LAB_0046b4de:
      if (*(int *)(local_40 + 0x1d0) == 1) {
        nvDbg_Printf("src/kernel/mem_mgr/vaspace.c",0xf4,"vaspaceGetByHandleOrDeviceDefault_IMPL",4,
                     "NVRM: VA mode %d (GLOBAL) doesn\'t support allocating private VA spaces.\n",1)
        ;
        return 0x40;
      }
      lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_VaSpaceApi);
      *param_4 = *(undefined8 *)(lVar2 + 0x138);
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/mem_mgr/vaspace.c",0xda,"vaspaceGetByHandleOrDeviceDefault_IMPL",4,
               "NVRM: Invalid parent handle!\n");
  return iVar1;
}


// ===== 0046b670 vidmemPmaFree =====

void vidmemPmaFree(undefined8 param_1,long param_2,char *param_3,uint param_4)

{
  int *piVar1;
  undefined8 uVar2;
  uint uVar3;
  
  if (param_3 == (char *)0x0) {
    nvAssertFailedNoLog("NULL != pPmaAllocInfo","src/kernel/mem_mgr/video_mem.c",0x17a);
    return;
  }
  uVar2 = *(undefined8 *)(param_2 + 0x128);
  piVar1 = (int *)(param_3 + 0x10);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    uVar3 = param_4 | 1;
    if ((param_3[0x21] & 4U) == 0) {
      uVar3 = param_4;
    }
    if (*param_3 == '\0') {
      pmaFreePages(uVar2,param_3 + 0x28,*(undefined4 *)(param_3 + 4),*(undefined8 *)(param_3 + 8),
                   uVar3);
      portMemFree(param_3);
      return;
    }
    pmaFreePages(uVar2,param_3 + 0x28,1,*(undefined8 *)(param_3 + 0x18),uVar3);
    portMemFree(param_3);
    return;
  }
  return;
}


// ===== 0046b708 vidmemGetHeap_IMPL.cold =====

void vidmemGetHeap_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046b720 vidmemGetHeap_IMPL =====

long vidmemGetHeap_IMPL(long param_1,long param_2,char param_3,char param_4)

{
  long *plVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long local_20 [2];
  
  lVar5 = *(long *)(param_1 + 0x1b78);
  if (param_3 == '\0') {
    if (*(long *)(param_1 + 0x1bc0) != 0) {
      cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
      if ((param_4 == '\0') && (cVar3 != '\0')) {
        local_20[0] = 0;
        iVar4 = kmigmgrGetMemoryPartitionHeapFromDevice_IMPL
                          (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_2,local_20);
        if (iVar4 != 0) {
          if (param_2 != 0) {
            plVar1 = *(long **)(*(long *)(param_2 + 0x110) + 0x48);
            nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x1bd,"vidmemGetHeap_IMPL",4,
                         "NVRM: failed to get memory partition heap for hClient = 0x%x, hDevice = 0x%x\n"
                         ,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2]);
            return 0;
          }
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        if (local_20[0] != 0) {
          return local_20[0];
        }
      }
    }
    lVar5 = *(long *)(lVar5 + 0x478);
  }
  else {
    lVar5 = memmgrGetDeviceSuballocator_IMPL(lVar5,param_3);
    if ((lVar5 == 0) || (*(int *)(lVar5 + 0x4c) != 1)) {
      nvCheckFailedNoLog(4,"pHeap != NULL && pHeap->heapType == HEAP_TYPE_PHYS_MEM_SUBALLOCATOR",
                         "src/kernel/mem_mgr/video_mem.c",0x1ab);
      return 0;
    }
  }
  return lVar5;
}


// ===== 0046b850 vidmemDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void vidmemDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  undefined8 uVar9;
  code *pcVar10;
  int iVar11;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)invalidInstructionException();
    (*pcVar10)();
  }
  lVar4 = *(long *)(param_1 + 0x248);
  lVar5 = *(long *)(lVar4 + 0xf0);
  lVar6 = *(long *)(lVar4 + 0x118);
  CliUnregisterMemoryFromThirdPartyP2P(lVar4);
  memDestructCommon_IMPL(lVar4);
  (**(code **)(*(long *)(&DAT_00001b90 + lVar5) + 0x330))
            (lVar5,*(long *)(&DAT_00001b90 + lVar5),lVar6,0);
  iVar11 = memdescGetCustomHeap(lVar6);
  if (iVar11 == 0) {
    uVar7 = *(undefined8 *)(lVar5 + 0x1b78);
    uVar1 = *(undefined4 *)(lVar4 + 0x108);
    plVar8 = *(long **)(*(long *)(param_1 + 0x230) + 0x48);
    uVar2 = *(undefined4 *)(plVar8[3] + 0x10);
    uVar3 = *(undefined4 *)(*plVar8 + 0x48);
    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x476,"vidmemDestruct_IMPL",1,
                 "NVRM: Function: FREE\n");
    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x477,"vidmemDestruct_IMPL",1,
                 "NVRM:    Owner: 0x%x\n",uVar1);
    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x478,"vidmemDestruct_IMPL",1,
                 "NVRM:  hMemory: 0x%x\n",
                 *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x230) + 0x48) + 0x10));
    uVar9 = *(undefined8 *)(lVar6 + 0xa0);
    if (*(int *)(lVar6 + 0x8c) != 1) {
      nvAssertFailedNoLog("pMemDesc->_subDeviceAllocCount == 1","src/kernel/mem_mgr/video_mem.c",
                          0x4a5);
    }
    iVar11 = memmgrFree_IMPL(lVar5,uVar7,uVar9,uVar3,uVar2,0,uVar1);
    if (iVar11 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/video_mem.c",0x4ae,lVar6);
      return;
    }
  }
  else if (iVar11 == 2) {
    (**(code **)(*(long *)(lVar5 + 0x1b78) + 0x3e0))(lVar5,*(long *)(lVar5 + 0x1b78),lVar6);
    return;
  }
  return;
}


// ===== 0046ba60 vidmemAllocResources =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int vidmemAllocResources(long param_1,long param_2,long *param_3,long param_4,long param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  bool bVar10;
  bool bVar11;
  int local_8c;
  char local_7a;
  byte local_79;
  undefined4 *local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  lVar2 = *param_3;
  uVar3 = *(undefined8 *)(param_1 + 0x1b70);
  iVar1 = *(int *)(lVar2 + 0x6c);
  local_78 = (undefined4 *)0x0;
  local_70 = (undefined8 *)0x0;
  local_7a = '\0';
  local_79 = 0;
  uVar6 = gpumgrGetSubDeviceInstanceFromGpu();
  lVar8 = kmemsysGetStaticConfig_IMPL(param_1,uVar3);
  if (lVar8 == 0) {
    nvAssertFailedNoLog(&DAT_00d86516,"src/kernel/mem_mgr/video_mem.c",0x4dc);
    local_8c = 0x40;
    goto LAB_0046bec8;
  }
  if ((*(uint *)(lVar2 + 8) & 0x26480400) == 0) {
    uVar4 = (ulong)uVar6;
    lVar8 = param_3[uVar4 + 5];
    if ((((*(uint *)(lVar2 + 8) & 0x10) == 0) || (lVar8 == 0)) ||
       (cVar5 = osNumaOnliningEnabled(*(undefined8 *)(param_1 + 0x4e0)), cVar5 == '\0')) {
      if ((*(uint *)(lVar2 + 0x1c) & 0x40) == 0) {
        if (iVar1 == 0) {
          if ((*(char *)(param_1 + 0x4b2) != '\0') && ((*(uint *)(lVar2 + 0x1c) & 0x400) != 0)) {
            local_68 = CONCAT44(local_68._4_4_,4);
            local_8c = (**(code **)(param_2 + 0x3d0))
                                 (param_1,param_2,*(undefined4 *)(param_4 + 0x98),lVar2,&local_68,
                                  param_3 + 4);
            if (local_8c == 0) {
              local_70 = (undefined8 *)param_3[4];
              local_70[0x14] = *(undefined8 *)(param_2 + 0x428);
              memdescSetCustomHeap(local_70,2);
              memdescSetPteKindForGpu(local_70,*local_70,*(undefined4 *)(param_4 + 0x4c));
              nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x518,"vidmemAllocResources",1,
                           "NVRM: Allocated surface in scanout region\n");
              goto LAB_0046bbd0;
            }
            nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x51c,"vidmemAllocResources",3,
                         "NVRM: Failed to allocate surface in scanout region\n");
            goto LAB_0046bec8;
          }
          uVar6 = *(uint *)(lVar2 + 0x18) & 0x18000000;
          if (uVar6 == 0) {
            bVar10 = *(char *)(param_5 + 0x48) == '\0';
          }
          else {
            bVar10 = uVar6 != 0x8000000;
          }
          local_8c = memUtilsAllocMemDesc(param_1,param_3,param_4,&local_70,param_5,2,bVar10);
          if (local_8c != 0) {
            nvCheckOkFailedNoLog
                      (3,local_8c,
                       "memUtilsAllocMemDesc(pGpu, pAllocRequest, pFbAllocInfo, &pMemDesc, pHeap, ADDR_FBMEM, bContig, &bAllocedMemDesc)"
                       ,"src/kernel/mem_mgr/video_mem.c",0x52e);
            goto LAB_0046bec8;
          }
          if (((bVar10 == false) || (bVar11 = false, (~*(uint *)(lVar2 + 0x18) & 0x18000000) == 0))
             && (bVar11 = false, *(char *)(param_2 + 0x448) != '\0')) {
            bVar11 = (*(uint *)(lVar2 + 0x18) & 0x30000) != 0x10000;
          }
          if (lVar8 == 0) {
            local_79 = bVar10 ^ 1;
            local_60 = 0;
            local_58 = 0;
            local_50 = 0;
            local_40 = 0;
            local_68 = *(undefined8 *)(lVar2 + 0x48);
            local_48 = *(long *)(param_4 + 0x30) + *(long *)(param_4 + 0x18);
            local_8c = heapAlloc_IMPL(param_1,*(undefined4 *)(param_4 + 0x98),param_5,param_3,
                                      (int)param_3[2],&local_68,param_4,&local_78,&local_79,bVar11,
                                      local_7a);
            local_70 = (undefined8 *)param_3[4];
            if (local_8c != 0) goto LAB_0046bec8;
            if ((*(byte *)(lVar2 + 10) & 1) != 0) {
              memdescSetFlag(local_70,0x4000,1);
            }
            if (*(int *)(lVar2 + 4) != 0xf) {
              cVar5 = memdescGetContiguity(local_70,1);
              if (cVar5 == '\0') {
                uVar4 = local_70[3];
                uVar9 = 0;
                if (uVar4 != 0) {
                  do {
                    memdescGetPte(local_70,1,uVar9);
                    uVar9 = (ulong)((int)uVar9 + 1);
                  } while (uVar9 < uVar4);
                }
              }
              else {
                memdescGetPte(local_70,1,0);
              }
            }
          }
          else {
            *(undefined8 *)(param_4 + 0x38) = local_70[0x2e];
            if ((*(char *)(g_pSys + 400) == '\x01') &&
               (cVar5 = memdescGetContiguity(local_70,0,bVar11,&local_7a), cVar5 == '\0')) {
              *(int *)(local_70 + 0x2c) = (int)*(undefined8 *)(param_3[uVar4 + 5] + 8);
            }
            if (bVar10 == false) {
              nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x552,"vidmemAllocResources",1,
                           "NVRM: ---> PMA Path taken discontiguous\n");
              if (!bVar11) {
                nvAssertFailedNoLog("!bContig && bNoncontigAllowed","src/kernel/mem_mgr/video_mem.c"
                                    ,0x553);
              }
              *(uint *)(lVar2 + 0x18) = *(uint *)(lVar2 + 0x18) & 0xe7ffffff | 0x8000000;
              lVar8 = param_3[uVar4 + 5];
              memdescFillPages(param_3[4],0,lVar8 + 0x28,*(undefined4 *)(lVar8 + 4),
                               *(undefined8 *)(lVar8 + 8));
            }
            else {
              nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x547,"vidmemAllocResources",1,
                           "NVRM: ---> PMA Path taken contiguous\n");
              *(uint *)(lVar2 + 0x18) = *(uint *)(lVar2 + 0x18) & 0xe7ffffff | 0x10000000;
              memdescDescribe(param_3[4],2,*(undefined8 *)(param_3[uVar4 + 5] + 0x28),
                              *(undefined8 *)(param_4 + 0x80));
            }
            if ((*(byte *)(lVar2 + 0x1f) & 0x60) != 0) {
              if ((*(char *)(param_2 + 0xd35) == '\0') ||
                 ((*(long *)(param_1 + 0x1bc0) != 0 &&
                  (cVar5 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar5 != '\0')))) {
                nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x566,"vidmemAllocResources",4,
                             "NVRM: Localized memory requested when localized memory not enabled\n")
                ;
                goto LAB_0046bebe;
              }
              memdescSetFlag(param_3[4],0x4000000000000,1);
              *(undefined8 *)(param_3[4] + 0x158) = *(undefined8 *)(param_2 + 0xd38);
            }
          }
          *(undefined4 *)(lVar2 + 0x18) = *(undefined4 *)(param_4 + 0x44);
          *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_4 + 0x48);
          cVar5 = memdescGetContiguity(param_3[4],1);
          uVar7 = *(uint *)(lVar2 + 0x18) & 0xe7ffffff;
          uVar6 = uVar7 | 0x8000000;
          if (cVar5 != '\0') {
            uVar6 = uVar7 | 0x10000000;
          }
          *(uint *)(lVar2 + 0x18) = uVar6;
          if (local_78 != (undefined4 *)0x0) {
            *local_78 = *(undefined4 *)(param_4 + 0x44);
            local_78[1] = *(undefined4 *)(param_4 + 0x48);
            local_78[4] = *(undefined4 *)(param_4 + 4);
            local_78[2] = *(undefined4 *)(param_4 + 0x50);
            local_78[3] = *(undefined4 *)(param_4 + 0xa4);
          }
LAB_0046bbd0:
          *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)(param_4 + 0x38);
          if ((undefined4 *)param_3[3] == (undefined4 *)0x0) {
            return 0;
          }
          *(undefined4 *)param_3[3] = *(undefined4 *)(param_4 + 0x44);
          *(undefined4 *)(param_3[3] + 4) = *(undefined4 *)(param_4 + 0x48);
          *(undefined4 *)(param_3[3] + 0x10) = *(undefined4 *)(param_4 + 4);
          *(undefined4 *)(param_3[3] + 8) = *(undefined4 *)(param_4 + 0x50);
          *(undefined4 *)(param_3[3] + 0xc) = *(undefined4 *)(param_4 + 0xa4);
          *(undefined4 *)(param_3[3] + 0x10) = *(undefined4 *)(param_4 + 4);
          return 0;
        }
        nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x4fe,"vidmemAllocResources",3,
                     "NVRM: VA space handle used with physical allocation\n");
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x4f7,"vidmemAllocResources",3,
                     "NVRM: Virtual-only 32-bit pointer attr used with physical allocation\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x4ef,"vidmemAllocResources",3,
                   "NVRM: NVOS32_ALLOC_FLAGS_FIXED_ADDRESS_ALLOCATE for PMA cannot be accommodated for NUMA systems\n"
                  );
    }
  }
  else {
    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x4e2,"vidmemAllocResources",3,
                 "NVRM: Virtual-only flag used with physical allocation\n");
  }
LAB_0046bebe:
  local_8c = 0x1f;
LAB_0046bec8:
  (**(code **)(param_2 + 0x170))(param_1,param_2,param_4);
  if (local_7a != '\0') {
    memdescDestroy(param_3[4]);
    param_3[4] = 0;
  }
  return local_8c;
}


// ===== 0046c28c vidmemConstruct_IMPL.cold =====

void vidmemConstruct_IMPL_cold(void)

{
  code *pcVar1;
  long lVar2;
  long unaff_RBP;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(unaff_RBP + -0xa8);
  for (lVar2 = 0x1e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046c2b0 vidmemConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Type propagation algorithm not settling */

int vidmemConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  bool bVar7;
  undefined1 uVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  char cVar14;
  bool bVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  long lVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  ulong uVar27;
  long lVar28;
  long lVar29;
  undefined8 uVar30;
  long lVar31;
  long lVar32;
  uint uVar33;
  long lVar34;
  ulong uVar35;
  undefined8 uVar36;
  char *pcVar37;
  undefined4 **ppuVar38;
  byte bVar39;
  byte bVar40;
  bool bVar41;
  long local_198;
  int local_180;
  long local_178;
  long local_140;
  uint local_134;
  undefined4 local_130;
  undefined4 local_12c;
  long local_128;
  long local_120;
  undefined1 local_118 [16];
  undefined8 local_104;
  undefined8 local_fc;
  undefined8 local_f4;
  undefined4 local_ec;
  undefined8 local_e8;
  ulong local_e0;
  ulong local_d8;
  undefined8 local_d0;
  ulong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 *local_b0;
  long local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 *local_98;
  long local_90 [9];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulong uVar22;
  
  if (param_1 == 0) {
    ppuVar38 = &local_b0;
    for (lVar34 = 0x1e; lVar34 != 0; lVar34 = lVar34 + -1) {
      *(undefined4 *)ppuVar38 = 0;
      ppuVar38 = (undefined4 **)((long)ppuVar38 + 4);
    }
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar34 = *(long *)(param_1 + 0x248);
  puVar3 = *(undefined4 **)(param_3 + 0x40);
  lVar25 = *(long *)(param_2 + 8);
  uVar1 = *(undefined4 *)(lVar25 + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x10);
  uVar27 = 0;
  do {
    uVar16 = (int)uVar27 + 0x20;
    uVar22 = (ulong)uVar16;
    *(undefined8 *)((long)&local_b0 + uVar27) = 0;
    *(undefined8 *)((long)&local_a8 + uVar27) = 0;
    *(undefined8 *)((long)&local_a0 + uVar27) = 0;
    *(undefined8 *)((long)&local_98 + uVar27) = 0;
    uVar27 = uVar22;
  } while (uVar16 < 0x60);
  *(undefined8 *)((long)&local_b0 + uVar22) = 0;
  *(undefined8 *)((long)&local_a8 + uVar22) = 0;
  *(undefined8 *)((long)&local_a0 + uVar22) = 0;
  local_104 = 0;
  lVar4 = *(long *)(lVar34 + 0xf0);
  local_fc = 0;
  local_f4 = 0;
  lVar31 = *(long *)(lVar4 + 0x1b78);
  local_ec = 0;
  lVar23 = __nvoc_dynamicCast(lVar25,__nvoc_class_def_RmClient);
  if (lVar23 == 0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/video_mem.c",0x23b);
    return 0x23;
  }
  lVar26 = *(long *)(param_2 + 0x10);
  lVar5 = *(long *)(&DAT_00001b90 + lVar4);
  iVar17 = refFindAncestorOfType(lVar26,&DAT_00e0ac20,&local_128);
  if (iVar17 != 0) {
    nvAssertOkFailedNoLog
              (iVar17,"refFindAncestorOfType(pResourceRef, classId(Device), &pDeviceRef)",
               "src/kernel/mem_mgr/video_mem.c",0x23d);
    return iVar17;
  }
  lVar24 = __nvoc_dynamicCast(*(undefined8 *)(local_128 + 8),__nvoc_class_def_Device);
  if (*(long *)(param_3 + 0x58) == 0) {
    if ((puVar3[6] & 0x18000000) == 0) {
      puVar3[6] = (*(uint *)(lVar24 + 0x1d4) & 3) << 0x1b | puVar3[6] & 0xe7ffffff;
    }
    iVar17 = stdmemValidateParams_IMPL(lVar4,lVar23,puVar3);
    if (iVar17 != 0) {
      nvCheckOkFailedNoLog
                (3,iVar17,"stdmemValidateParams(pGpu, pRmClient, pAllocData)",
                 "src/kernel/mem_mgr/video_mem.c",0x259);
      return iVar17;
    }
    if (((*(byte *)((long)puVar3 + 0x1b) & 6) != 0) || ((*(byte *)((long)puVar3 + 10) & 8) != 0)) {
      nvCheckFailedNoLog(3,
                         "DRF_VAL(OS32, _ATTR, _LOCATION, pAllocData->attr) == NVOS32_ATTR_LOCATION_VIDMEM && !(pAllocData->flags & NVOS32_ALLOC_FLAGS_VIRTUAL)"
                         ,"src/kernel/mem_mgr/video_mem.c",0x25a);
      return 0x1f;
    }
    stdmemDumpInputAllocParams_IMPL(puVar3,param_2);
    if (*(uint *)(param_2 + 0x28) < 2) {
      bVar40 = 0;
    }
    else {
      bVar40 = *(byte *)((long)puVar3 + 0x19) >> 6 & 1;
    }
    uVar16 = puVar3[7] & 0x8000000;
    lVar23 = vidmemGetHeap_IMPL(lVar4,lVar24,uVar16 >> 0x1b,bVar40);
    if (lVar23 == 0) {
      nvCheckFailedNoLog(1,"pHeap != NULL","src/kernel/mem_mgr/video_mem.c",0x268);
      return 0x40;
    }
    uVar18 = puVar3[7];
    cVar14 = gpuIsCCorApmFeatureEnabled_IMPL(lVar4);
    if ((cVar14 == '\0') || ((puVar3[7] & 0x6000000) == 0x4000000)) {
      cVar14 = gpuIsCCFeatureEnabled_IMPL(lVar4);
      if ((cVar14 != '\0') && ((puVar3[7] & 0x6000000) == 0x4000000)) {
        nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x276,"vidmemConstruct_IMPL",4,
                     "NVRM: Non-CPR region not yet created\n");
        nvAssertFailedNoLog(&DAT_00d86516,"src/kernel/mem_mgr/video_mem.c",0x277);
        return 0x1f;
      }
      cVar14 = gpuIsCCorApmFeatureEnabled_IMPL(lVar4);
      if ((cVar14 == '\0') && ((puVar3[7] & 0x6000000) == 0x2000000)) {
        nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x27c,"vidmemConstruct_IMPL",4,
                     "NVRM: Protected memory not enabled but PROTECTED flag is set by client");
        return 0x1f;
      }
    }
    else {
      puVar3[2] = puVar3[2] | 0x1000000;
    }
    local_48 = 0x40;
    local_a0 = *(undefined4 *)(lVar26 + 0x10);
    local_9c = 1;
    local_98 = &local_104;
    bVar39 = (byte)(uVar16 >> 0x1b);
    local_140 = 0;
    local_b0 = puVar3;
    local_a8 = lVar4;
    local_44 = uVar1;
    local_40 = uVar2;
    if (*(char *)(lVar31 + 0x434) == '\0') {
      if (*(char *)(lVar31 + 0x480) == '\0') goto LAB_0046d1d8;
      if (bVar40 == 0 && bVar39 == 0) {
LAB_0046d7f8:
        nvCheckFailedNoLog(3,
                           "!memmgrIsScrubOnFreeEnabled(pMemoryManager) || bIsPmaAlloc || bSubheap || bRsvdHeap"
                           ,"src/kernel/mem_mgr/video_mem.c",0x297);
        return 0x40;
      }
LAB_0046d6a1:
      if ((*(byte *)((long)puVar3 + 0x1f) & 0x60) != 0) goto LAB_0046d6ac;
      bVar41 = false;
      bVar15 = false;
    }
    else {
      if (bVar40 == 0 && bVar39 == 0) {
        if (((((uVar18 & 0x400) == 0) && (uVar18 = puVar3[2], (uVar18 & 0x40000000) == 0)) &&
            (-1 < (int)uVar18)) &&
           (((uVar18 & 0x10) == 0 ||
            (cVar14 = heapIsPmaManaged_IMPL
                                (lVar4,lVar23,*(long *)(puVar3 + 0x14),
                                 *(long *)(puVar3 + 0x10) + -1 + *(long *)(puVar3 + 0x14)),
            cVar14 != '\0')))) {
          local_a8 = lVar4;
          lVar26 = vidmemGetHeap_IMPL(lVar4,lVar24,0,0);
          puVar12 = local_b0;
          uVar30 = *(undefined8 *)(lVar26 + 0x128);
          uVar36 = *(undefined8 *)(local_a8 + 0x1b78);
          local_e8 = 0;
          local_e0 = 0;
          local_d8 = 0;
          local_d0 = 0;
          local_c8 = 0;
          local_c0 = 0;
          local_b8 = 0;
          uVar18 = gpumgrGetSubDeviceInstanceFromGpu();
          local_134 = 4;
          iVar17 = pmaQueryConfigs(uVar30,&local_134);
          if (iVar17 == 0) {
            if ((local_134 & 4) == 0) goto LAB_0046d950;
            bVar41 = (bool)(*(byte *)((long)puVar12 + 0x1b) >> 3 & 1 ^ 1);
          }
          else {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/video_mem.c",0x8d);
LAB_0046d950:
            bVar41 = (puVar12[6] & 0x18000000) != 0x8000000;
          }
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xa4,"_vidmemPmaAllocate",1,
                       "NVRM: PMA input\n");
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xa5,"_vidmemPmaAllocate",1,
                       "NVRM:           Owner: 0x%x\n",*puVar12);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xa6,"_vidmemPmaAllocate",1,
                       "NVRM:         hMemory: 0x%x\n",local_a0);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xa7,"_vidmemPmaAllocate",1,
                       "NVRM:            Type: 0x%x\n",puVar12[1]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xa8,"_vidmemPmaAllocate",1,
                       "NVRM:           Flags: 0x%x\n",puVar12[2]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xa9,"_vidmemPmaAllocate",1,
                       "NVRM:           Begin: 0x%08llx\n",*(undefined8 *)(puVar12 + 0xc));
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xaa,"_vidmemPmaAllocate",1,
                       "NVRM:             End: 0x%08llx\n",*(undefined8 *)(puVar12 + 0xe));
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xab,"_vidmemPmaAllocate",1,
                       "NVRM:          Height: 0x%x\n",puVar12[4]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xac,"_vidmemPmaAllocate",1,
                       "NVRM:           Width: 0x%x\n",puVar12[3]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xad,"_vidmemPmaAllocate",1,
                       "NVRM:           Pitch: 0x%x\n",puVar12[5]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xae,"_vidmemPmaAllocate",1,
                       "NVRM:            Size: 0x%08llx\n",*(undefined8 *)(puVar12 + 0x10));
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xaf,"_vidmemPmaAllocate",1,
                       "NVRM:       Alignment: 0x%08llx\n",*(undefined8 *)(puVar12 + 0x12));
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb1,"_vidmemPmaAllocate",1,
                       "NVRM:          Offset: 0x%08llx\n",*(undefined8 *)(puVar12 + 0x14));
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb2,"_vidmemPmaAllocate",1,
                       "NVRM:            Attr: 0x%x\n",puVar12[6]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb3,"_vidmemPmaAllocate",1,
                       "NVRM:           Attr2: 0x%x\n",puVar12[7]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb4,"_vidmemPmaAllocate",1,
                       "NVRM:          Format: 0x%x\n",puVar12[8]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb5,"_vidmemPmaAllocate",1,
                       "NVRM:       ComprCovg: 0x%x\n",puVar12[9]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb6,"_vidmemPmaAllocate",1,
                       "NVRM:       ZCullCovg: 0x%x\n",puVar12[10]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb7,"_vidmemPmaAllocate",1,
                       "NVRM:      CtagOffset: 0x%x\n",puVar12[0x1a]);
          nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0xb8,"_vidmemPmaAllocate",1,
                       "NVRM:        hVASpace: 0x%x\n",puVar12[0x1b]);
          uVar27 = stdmemQueryPageSize_IMPL(uVar36,local_44,puVar12);
          lVar32 = local_a8;
          puVar13 = local_b0;
          if (uVar27 == 0) {
            nvAssertFailedNoLog("pageSize != 0","src/kernel/mem_mgr/video_mem.c",0xbc);
            portMemFree(0);
            portMemFree(0);
            local_180 = 0x40;
          }
          else {
            uVar22 = 0x10000;
            if (uVar27 != 0x1000) {
              uVar22 = uVar27;
            }
            lVar29 = *(long *)(local_a8 + 0x1b78);
            local_120 = *(long *)(local_b0 + 0x10);
            local_130 = local_b0[6];
            local_12c = local_b0[7];
            local_118._0_8_ = 0x1000;
            if ((local_b0[2] & 0x180) != 0) {
              local_118._0_8_ = *(undefined8 *)(local_b0 + 0x12);
            }
            lVar28 = (**(code **)(lVar29 + 0x168))
                               (lVar29,local_44,local_120,local_b0[8],local_b0[2],&local_130);
            if (lVar28 == 0) {
              nvAssertOkFailedNoLog
                        (0x40,"memmgrDeterminePageSize","src/kernel/mem_mgr/video_mem.c",0x5b);
              if ((*(byte *)((long)puVar12 + 0x1e) & 8) != 0) {
                local_e8 = local_e8 | 0x800;
              }
              local_180 = 0x40;
            }
            else {
              local_180 = (**(code **)(lVar29 + 0x1f8))
                                    (lVar32,lVar29,&local_120,local_118,0,puVar13[2],local_130,
                                     local_12c,0);
              if (local_180 == 0) {
                local_198 = local_120;
                uVar27 = local_118._0_8_ + 1;
                uVar20 = (uint)local_e8;
                if ((*(byte *)((long)puVar12 + 0x1e) & 8) != 0) {
                  uVar20 = (uint)local_e8 | 0x800;
                }
                uVar33 = puVar12[2];
                uVar19 = uVar20 | 0x82;
                if ((uVar33 & 0x10000) == 0) {
                  uVar19 = uVar20 | 2;
                }
                if ((uVar33 & 0x1000000) != 0) {
                  uVar19 = uVar19 | 0x100;
                }
                if ((uVar33 & 0x800) != 0) {
                  uVar19 = uVar19 | 0x2000;
                }
                if ((uVar33 & 0x10) != 0) {
                  uVar35 = uVar27;
                  if (uVar27 <= uVar22) {
                    uVar35 = uVar22;
                  }
                  uVar19 = uVar19 | 8;
                  local_e0 = *(ulong *)(puVar12 + 0x14) & -uVar35;
                  local_d8 = ((uVar35 - 1) + local_120 + local_e0 & -uVar35) - 1;
                  local_198 = (local_d8 - local_e0) + 1;
                  uVar33 = puVar12[2];
                }
                uVar20 = uVar19;
                if ((uVar33 & 0x20000) != 0) {
                  uVar20 = uVar19 | 8;
                  local_e8 = CONCAT44(local_e8._4_4_,uVar19) | 8;
                  local_e0 = (uVar22 - 1) + *(long *)(puVar12 + 0xc) & -uVar22;
                  local_d8 = -uVar22 & *(ulong *)(puVar12 + 0xe);
                  local_d8 = local_d8 - (local_d8 != 0);
                  if (local_d8 < local_e0) {
                    nvAssertFailedNoLog("allocOptions.physBegin <= allocOptions.physEnd",
                                        "src/kernel/mem_mgr/video_mem.c",0xfe);
                    portMemFree(0);
                    portMemFree(0);
                    local_180 = 0x1f;
                    goto LAB_0046d02b;
                  }
                }
                if ((*(byte *)(puVar12 + 0x1c) & 4) != 0) {
                  uVar20 = uVar20 | 0x400;
                }
                local_c8 = uVar27;
                if (uVar27 <= uVar22) {
                  local_c8 = uVar22;
                }
                uVar11 = local_e8._4_4_;
                local_e8 = CONCAT44(local_e8._4_4_,uVar20) | 0x200;
                if ((puVar12[7] & 0x60000000) == 0x20000000) {
                  local_e8 = CONCAT44(uVar11,uVar20) | 0x4200;
                }
                else if ((puVar12[7] & 0x60000000) == 0x40000000) {
                  local_e8 = CONCAT44(uVar11,uVar20) | 0x8200;
                }
                uVar36 = 0x116;
                pcVar37 = "(NV_DIV_AND_CEIL(size, pageSize) <= NV_U32_MAX)";
                uVar27 = ((uVar22 - 1) + local_198) / uVar22;
                if (uVar27 >> 0x20 == 0) {
                  local_180 = (int)uVar27;
                  if (bVar41 == false) goto LAB_0046d8f5;
                  local_e8 = local_e8 | 0x40;
                  iVar17 = 0x30;
                  while( true ) {
                    lVar29 = portMemAllocNonPaged(iVar17);
                    lVar32 = (ulong)uVar18 + 4;
                    (&local_a8)[lVar32] = lVar29;
                    if (lVar29 == 0) break;
                    portMemSet(lVar29,0,iVar17);
                    *(ulong *)((&local_a8)[lVar32] + 8) = uVar22;
                    *(int *)((&local_a8)[lVar32] + 4) = local_180;
                    *(ulong *)((&local_a8)[lVar32] + 0x18) = uVar27 * uVar22;
                    *(bool *)(&local_a8)[lVar32] = bVar41;
                    *(undefined4 *)((&local_a8)[lVar32] + 0x10) = 1;
                    *(uint *)((&local_a8)[lVar32] + 0x20) = (uint)local_e8;
                    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x138,"_vidmemPmaAllocate",1,
                                 "NVRM: \nNVRM:  Size requested: 0x%llx bytes\n",local_198);
                    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x139,"_vidmemPmaAllocate",1,
                                 "NVRM:        PageSize: 0x%llx bytes\n",uVar22);
                    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x13a,"_vidmemPmaAllocate",1,
                                 "NVRM:       PageCount: 0x%x\n",uVar27 & 0xffffffff);
                    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x13b,"_vidmemPmaAllocate",1,
                                 "NVRM:     Actual Size: 0x%llx\n",
                                 *(undefined8 *)((&local_a8)[lVar32] + 0x18));
                    if (bVar41 == false) {
                      nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x13d,"_vidmemPmaAllocate",1,
                                   "NVRM:      Contiguous:  %s\n",&DAT_00d86a7d);
                      iVar17 = pmaAllocatePages(uVar30,uVar27,uVar22,&local_e8,
                                                (&local_a8)[lVar32] + 0x28);
                      if (iVar17 != 0) {
                        portMemFree((&local_a8)[lVar32]);
                        (&local_a8)[lVar32] = 0;
LAB_0046cfe6:
                        nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x155,"_vidmemPmaAllocate",3,
                                     "NVRM: pmaAllocatePages failed (%x)\n",iVar17);
                        local_180 = iVar17;
                        goto LAB_0046d016;
                      }
                      uVar18 = puVar12[6] & 0xe7ffffff | 0x8000000;
LAB_0046d9e0:
                      puVar12[6] = uVar18;
                      bVar15 = true;
                      bVar41 = true;
                      goto LAB_0046d1ed;
                    }
                    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x13d,"_vidmemPmaAllocate",1,
                                 "NVRM:      Contiguous:  %s\n",&DAT_00d86a9c);
                    iVar17 = pmaAllocatePages(uVar30,uVar27,uVar22,&local_e8,
                                              (&local_a8)[lVar32] + 0x28);
                    if (iVar17 == 0) {
                      uVar18 = puVar12[6] & 0xe7ffffff | 0x10000000;
                      goto LAB_0046d9e0;
                    }
                    portMemFree((&local_a8)[lVar32]);
                    (&local_a8)[lVar32] = 0;
                    if (((puVar12[6] & 0x18000000) != 0x18000000) &&
                       (((puVar12[6] & 0x18000000) != 0 || (*(char *)(lVar26 + 0x48) == '\0'))))
                    goto LAB_0046cfe6;
                    local_e8 = local_e8 & 0xffffffffffffffbf;
                    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x14f,"_vidmemPmaAllocate",1,
                                 "NVRM: pmaAllocatePages failed -- retrying as noncontiguous\n");
LAB_0046d8f5:
                    iVar17 = 0x30;
                    uVar20 = local_180 - 1;
                    if (uVar20 == 0) {
                      bVar41 = false;
                    }
                    else {
                      if (uVar20 >> 0x1d != 0) {
                        uVar36 = 0x124;
                        pcVar37 = "portSafeMulU32((pageCount - 1), (sizeof(NvU64)), &pmaInfoSize)";
                        goto LAB_0046da13;
                      }
                      iVar17 = uVar20 * 8 + 0x30;
                      if (0xffffffcf < uVar20 * 8) {
                        uVar36 = 0x127;
                        pcVar37 = 
                        "portSafeAddU32(pmaInfoSize, (sizeof(PMA_ALLOC_INFO)), &pmaInfoSize)";
                        goto LAB_0046da13;
                      }
                      bVar41 = false;
                    }
                  }
                  nvAssertFailedNoLog("NULL != pAllocRequest->pPmaAllocInfo[subdevInst]",
                                      "src/kernel/mem_mgr/video_mem.c",0x12e);
                  portMemFree(0);
                  portMemFree(0);
                }
                else {
LAB_0046da13:
                  nvCheckFailedNoLog(4,pcVar37,"src/kernel/mem_mgr/video_mem.c",uVar36);
                  portMemFree(0);
                  portMemFree(0);
                }
                local_180 = 0x51;
                goto LAB_0046d02b;
              }
              nvAssertOkFailedNoLog
                        (local_180,
                         "memmgrAllocDetermineAlignment_HAL(pGpu, pMemoryManager, &size, &align, 0, pAllocData->flags, retAttr, retAttr2, 0)"
                         ,"src/kernel/mem_mgr/video_mem.c",0x60);
              if ((*(byte *)((long)puVar12 + 0x1e) & 8) != 0) {
                local_e8 = local_e8 | 0x800;
              }
            }
            nvAssertFailedNoLog("NV_OK == status","src/kernel/mem_mgr/video_mem.c",0xd5);
LAB_0046d016:
            portMemFree(0);
            portMemFree(0);
          }
          goto LAB_0046d02b;
        }
        if (*(char *)(lVar31 + 0x480) != '\0') goto LAB_0046d7f8;
      }
      else if (*(char *)(lVar31 + 0x480) != '\0') goto LAB_0046d6a1;
LAB_0046d1d8:
      bVar15 = false;
      if ((*(byte *)((long)puVar3 + 0x1f) & 0x60) != 0) {
LAB_0046d6ac:
        portMemFree(0);
        portMemFree(0);
        return 0x56;
      }
      bVar41 = false;
    }
LAB_0046d1ed:
    cVar14 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar4 + 0x7a4));
    if ((cVar14 == '\0') && (cVar14 = rmGpuLockIsOwner(), cVar14 == '\0')) {
      bVar7 = true;
      local_180 = rmDeviceGpuLocksAcquire(lVar4,0,0x2000);
      if (local_180 == 0) goto LAB_0046d224;
      nvAssertFailedNoLog("NV_OK == rmStatus","src/kernel/mem_mgr/video_mem.c",0x2ba);
      portMemFree(0);
      portMemFree(0);
    }
    else {
      bVar7 = false;
      nvAssertFailedNoLog(&DAT_00d86516,"src/kernel/mem_mgr/video_mem.c",0x2c0);
LAB_0046d224:
      if (*(long *)(lVar4 + 0x1c18) == 0) {
LAB_0046d245:
        if (((*(char *)(lVar4 + 0x44d) == '\0') || ((*(byte *)((long)puVar3 + 0x1d) & 4) != 0)) ||
           (*(char *)(lVar4 + 0x4921) != '\0')) {
          cVar14 = (**(code **)(lVar4 + 0x2d8))(lVar4);
          if (cVar14 == '\0') {
            local_140 = portMemAllocNonPaged(0xc0);
            if (local_140 == 0) {
              lVar26 = 0;
              nvAssertOkFailedNoLog
                        (0x51,"pFbAllocInfo != NULL","src/kernel/mem_mgr/video_mem.c",0x2e5);
              local_180 = 0x51;
            }
            else {
              lVar26 = portMemAllocNonPaged(0x14);
              if (lVar26 == 0) {
                nvAssertOkFailedNoLog
                          (0x51,"pFbAllocPageFormat != NULL","src/kernel/mem_mgr/video_mem.c",0x2e8)
                ;
                local_180 = 0x51;
              }
              else {
                portMemSet(local_140,0,0xc0);
                portMemSet(lVar26,0,0x14);
                *(long *)(local_140 + 0x90) = lVar26;
                memUtilsInitFBAllocInfo(local_b0,local_140,uVar1,uVar2);
                local_180 = memmgrAllocResources_IMPL(lVar4,lVar31,&local_b0,local_140);
                if (local_180 == 0) {
                  local_180 = vidmemAllocResources(lVar4,lVar31,&local_b0,local_140,lVar23);
                  if (local_180 == 0) {
                    local_178 = local_90[0];
                    if (local_90[0] == 0) {
                      nvAssertFailedNoLog("pAllocRequest->pMemDesc","src/kernel/mem_mgr/video_mem.c"
                                          ,0x34f);
                      local_178 = local_90[0];
                    }
                    uVar30 = memdescGetPhysAddr(local_178,1,0);
                    lVar31 = *(long *)(local_178 + 0x30);
                    if (uVar16 != 0) {
                      memdescSetFlag(local_178,0x2000000,1);
                    }
                    *(long *)(puVar3 + 0x16) = lVar31 + -1;
                    if (bVar41) {
                      uVar18 = gpumgrGetSubDeviceInstanceFromGpu(lVar4);
                      lVar32 = memdescGetMemDescFromGpu(local_178,lVar4);
                      *(long *)(lVar32 + 0xb0) = local_90[(ulong)uVar18 + 1];
                    }
                    cVar14 = gpuIsCCorApmFeatureEnabled_IMPL(lVar4);
                    if ((cVar14 != '\0') && ((puVar3[7] & 0x6000000) == 0x4000000)) {
                      uVar36 = memdescGetMemDescFromGpu(local_178,lVar4);
                      memdescSetFlag(uVar36,0x200000000000,1);
                    }
                    cVar14 = memdescGetFlag(local_178,0x8000000000000);
                    uVar18 = puVar3[7];
                    if (cVar14 == '\0') {
                      if ((uVar18 & 0xc) == 0) {
                        puVar3[7] = uVar18 & 0xfffffff3 | 4;
                      }
                      if (*(int *)(local_178 + 0x90) != 1) {
                        uVar18 = puVar3[7];
                        goto LAB_0046d459;
                      }
                      uVar36 = memdescGetMemDescFromGpu(local_178,lVar4);
                      memdescSetGpuCacheAttrib(uVar36,0);
                      uVar18 = puVar3[7];
                      if ((uVar18 & 0x300) != 0x200) goto LAB_0046d459;
                      nvAssertFailedNoLog("SMMU mapping allocation is not supported for ARMv7",
                                          "src/kernel/mem_mgr/video_mem.c",0x399);
                      memdescFree(local_178);
                      memdescDestroy(local_178);
                      local_180 = 0x56;
                    }
                    else {
LAB_0046d459:
                      local_180 = memConstructCommon_IMPL
                                            (lVar34,local_48,puVar3[2],local_178,*puVar3,lVar23,
                                             puVar3[6],uVar18,0,puVar3[1],puVar3[0x1d],&local_104);
                      if (local_180 == 0) {
                        if (*(long *)(lVar34 + 0x118) == 0) {
                          nvAssertFailedNoLog("pMemory->pMemDesc","src/kernel/mem_mgr/video_mem.c",
                                              0x3ae);
                        }
                        if (*(long *)(lVar34 + 0x110) == 0) {
                          nvAssertFailedNoLog("pMemory->pHeap","src/kernel/mem_mgr/video_mem.c",
                                              0x3af);
                        }
                        if (*(char *)(lVar4 + 0x909) == '\0') {
                          *(undefined1 *)(lVar34 + 0x1b0) = 1;
                        }
                        lVar32 = *(long *)(lVar34 + 0xf0);
                        uVar36 = *(undefined8 *)(g_pSys + 0x218);
                        lVar25 = __nvoc_dynamicCast(lVar25,__nvoc_class_def_RmClient);
                        auVar10._8_8_ = local_118._8_8_;
                        auVar10._0_8_ = local_118._0_8_;
                        auVar9._8_8_ = local_118._8_8_;
                        auVar9._0_8_ = local_118._0_8_;
                        if (((*(char *)(lVar32 + 0x497) != '\0') &&
                            (local_118 = auVar9, *(long *)(lVar34 + 0xe8) == 0)) &&
                           (local_118 = auVar10, *(uint *)(param_2 + 0x28) < 2)) {
                          lVar29 = *(long *)(lVar32 + 0x1bc0);
                          if (lVar29 == 0) {
                            local_118 = kmigmgrMakeNoMIGReference_IMPL();
LAB_0046e0d7:
                            local_120 = -1;
                            uVar8 = 1;
                          }
                          else {
                            cVar14 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar32);
                            local_118 = kmigmgrMakeNoMIGReference_IMPL();
                            local_120 = -1;
                            if (cVar14 == '\0') goto LAB_0046e0d7;
                            iVar17 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar32,lVar29,lVar24);
                            uVar8 = 0;
                            if (iVar17 != 0) {
                              nvCheckOkFailedNoLog
                                        (4,iVar17,
                                         "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &partitionRef)"
                                         ,"src/kernel/mem_mgr/video_mem.c",0x3fe);
                              local_180 = iVar17;
                              goto joined_r0x0046e12e;
                            }
                          }
                          portMemSet(&local_e8,0,0x30);
                          gpuFindClientInfoWithPidIterator_IMPL
                                    (lVar32,*(undefined4 *)(lVar25 + 0x118),
                                     *(undefined4 *)(lVar25 + 0x11c),0x4789f2,&local_e8,&local_120,
                                     local_118,uVar8);
                          gpuacctUpdateProcPeakFbUsage_IMPL
                                    (uVar36,*(undefined4 *)(lVar32 + 0x7a4),
                                     *(undefined4 *)(lVar25 + 0x118),*(undefined4 *)(lVar25 + 0x11c)
                                     ,local_e0 + local_e8);
                        }
                        iVar17 = (**(code **)(lVar5 + 0x328))
                                           (lVar4,lVar5,*(undefined8 *)(lVar34 + 0x118),0);
                        if ((iVar17 == 0) || (iVar17 == 0x56)) {
                          *(long *)(puVar3 + 0x10) = lVar31;
                          *(undefined8 *)(puVar3 + 0x14) = uVar30;
                          stdmemDumpOutputAllocParams_IMPL(puVar3);
                          goto LAB_0046c4bf;
                        }
                        if (*(char *)(lVar34 + 0x1b0) != '\0') {
                          lVar25 = gpuGetRpc(lVar4);
                          if (lVar25 == 0) {
                            nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/video_mem.c",
                                                0x428);
                          }
                          else {
                            if ((*(char *)(lVar4 + 0x909) == '\0') &&
                               (*(char *)(lVar4 + 0x90a) == '\0')) {
                              iVar21 = (**(code **)(lVar25 + 0xf0))
                                                 (lVar4,lVar25,uVar1,uVar2,local_a0,
                                                  *(code **)(lVar25 + 0xf0));
                            }
                            else {
                              iVar21 = (**(code **)(lVar4 + 0x3b70))(lVar4 + 0x3b58,uVar1,local_a0);
                            }
                            if (iVar21 == 0) goto LAB_0046d5be;
                          }
                          nvAssertFailedNoLog("status == NV_OK","src/kernel/mem_mgr/video_mem.c",
                                              0x42a);
                        }
LAB_0046d5be:
                        memDestructCommon_IMPL(lVar34);
                        memdescFree(local_178);
                        memdescDestroy(local_178);
                        local_180 = iVar17;
                      }
                      else {
                        memdescFree(local_178);
                        memdescDestroy(local_178);
                      }
                    }
joined_r0x0046e12e:
                    if (uVar16 != 0) {
                      heapRemoveRef_IMPL(lVar23);
                    }
                  }
                }
              }
            }
          }
          else {
            local_180 = 3;
            lVar26 = 0;
          }
        }
        else {
          lVar26 = 0;
          nvAssertFailedNoLog("Video memory requested despite BROKEN FB",
                              "src/kernel/mem_mgr/video_mem.c",0x2d8);
          local_180 = 0x56;
        }
      }
      else {
        cVar14 = krcTestAllowAlloc_IMPL(lVar4,*(long *)(lVar4 + 0x1c18),0x100);
        if (cVar14 != '\0') goto LAB_0046d245;
        local_180 = 0x1a;
        lVar26 = 0;
      }
      portMemFree(lVar26);
      portMemFree(local_140);
      if (bVar7) goto LAB_0046c4e6;
    }
  }
  else {
    cVar14 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar4 + 0x7a4));
    if (cVar14 == '\0') {
      cVar14 = rmGpuLockIsOwner();
      bVar7 = false;
      if (cVar14 == '\0') {
        bVar7 = true;
        iVar17 = rmDeviceGpuLocksAcquire(lVar4,0,0x2000);
        if (iVar17 != 0) {
          nvAssertOkFailedNoLog
                    (iVar17,
                     "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                     "src/kernel/mem_mgr/video_mem.c",0x246);
          portMemFree(0);
          portMemFree(0);
          return iVar17;
        }
      }
    }
    else {
      bVar7 = false;
    }
    lVar25 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                                __nvoc_class_def_Memory);
    lVar34 = *(long *)(lVar25 + 0xf0);
    uVar30 = *(undefined8 *)(lVar25 + 0x118);
    local_180 = (**(code **)(*(long *)(&DAT_00001b90 + lVar34) + 0x328))
                          (lVar34,*(long *)(&DAT_00001b90 + lVar34),uVar30,0);
    if ((local_180 == 0) || (local_180 == 0x56)) {
      iVar17 = memdescGetCustomHeap(uVar30);
      if (iVar17 == 0) {
        lVar31 = memdescGetMemDescFromGpu(*(undefined8 *)(lVar25 + 0x118),lVar34);
        local_180 = heapReference_IMPL(lVar34,*(undefined8 *)(lVar31 + 0xa0),
                                       *(undefined4 *)(lVar25 + 0x108),lVar31);
        if (local_180 != 0) {
          nvAssertOkFailedNoLog(local_180,"status","src/kernel/mem_mgr/video_mem.c",0x1f1);
        }
        goto LAB_0046c4ae;
      }
      if (iVar17 == 2) {
        bVar15 = false;
        lVar26 = 0;
        local_180 = (**(code **)(*(long *)(lVar34 + 0x1b78) + 0x3f8))
                              (lVar34,*(long *)(lVar34 + 0x1b78),uVar30);
        local_140 = 0;
      }
      else {
        bVar15 = false;
        lVar26 = 0;
        nvAssertFailedNoLog(&DAT_00d86516,"src/kernel/mem_mgr/video_mem.c",0x1f5);
        local_180 = 0x1f;
        local_140 = 0;
      }
    }
    else {
LAB_0046c4ae:
      local_140 = 0;
      bVar15 = false;
      lVar26 = 0;
    }
LAB_0046c4bf:
    portMemFree(lVar26);
    portMemFree(local_140);
    if (!bVar7) {
      return local_180;
    }
LAB_0046c4e6:
    rmDeviceGpuLocksRelease(lVar4,0,0);
    bVar15 = (bool)(local_180 != 0 & bVar15);
  }
  if (!bVar15) {
    return local_180;
  }
LAB_0046d02b:
  uVar16 = gpumgrGetSubDeviceInstanceFromGpu(lVar4);
  if (local_90[(ulong)uVar16 + 1] != 0) {
    uVar16 = gpumgrGetSubDeviceInstanceFromGpu(lVar4);
    lVar34 = local_90[(ulong)uVar16 + 1];
    uVar30 = vidmemGetHeap_IMPL(lVar4,lVar24,0,0);
    vidmemPmaFree(lVar4,uVar30,lVar34,0);
  }
  return local_180;
}


// ===== 0046e139 vidmemCheckCopyPermissions_IMPL.cold =====

void vidmemCheckCopyPermissions_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046e143 FUN_0046e143 =====

void FUN_0046e143(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046e150 vidmemCheckCopyPermissions_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong vidmemCheckCopyPermissions_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  long *plVar10;
  undefined8 uVar11;
  ulong uVar12;
  long local_60;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar1 = *(long *)(param_1 + 0x248);
  lVar2 = *(long *)(lVar1 + 0xf0);
  uVar11 = **(undefined8 **)(*(long *)(param_1 + 0x230) + 0x48);
  if (param_3 == 0) {
    uVar12 = FUN_0046e143(uVar11);
    return uVar12;
  }
  uVar3 = **(undefined8 **)(*(long *)(param_3 + 0x110) + 0x48);
  uVar4 = *(undefined8 *)(lVar2 + 0x1bc0);
  uVar5 = *(undefined8 *)(param_2 + 0x1bc0);
  plVar10 = (long *)__nvoc_dynamicCast(uVar11,__nvoc_class_def_RmClient);
  uVar9 = (**(code **)(*plVar10 + 0xd8))(plVar10);
  plVar10 = (long *)__nvoc_dynamicCast(uVar3,__nvoc_class_def_RmClient);
  uVar8 = (**(code **)(*plVar10 + 0xd8))(plVar10);
  if ((1 < uVar8) ||
     (((*(long *)(lVar2 + 0x1bc0) == 0 ||
       (cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), cVar7 == '\0')) &&
      ((*(long *)(param_2 + 0x1bc0) == 0 ||
       (cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_2), cVar7 == '\0')))))) {
    return 0;
  }
  if (1 < uVar9) {
    local_48._0_8_ = 0;
    uVar9 = kmigmgrGetMemoryPartitionHeapFromDevice_IMPL(param_2,uVar5,param_3,local_48);
    if (uVar9 != 0) {
      nvCheckOkFailedNoLog
                (3,uVar9,
                 "kmigmgrGetMemoryPartitionHeapFromDevice(pDstGpu, pDstKernelMIGManager, pDstDevice, &pDstClientHeap)"
                 ,"src/kernel/mem_mgr/video_mem.c",0x628);
      return (ulong)uVar9;
    }
    if (*(long *)(lVar1 + 0x110) == local_48._0_8_) {
      return 0;
    }
    nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x62f,"vidmemCheckCopyPermissions_IMPL",3,
                 "NVRM: Duping outside of GPU instance not allowed with MIG\n");
    return 0x56;
  }
  uVar9 = refFindAncestorOfType
                    (*(undefined8 *)(*(long *)(lVar1 + 0xb8) + 0x48),&DAT_00e0ac20,&local_60);
  if (uVar9 != 0) {
    nvAssertOkFailedNoLog
              (uVar9,"refFindAncestorOfType(RES_GET_REF(pMemory), classId(Device), &pSrcDeviceRef)",
               "src/kernel/mem_mgr/video_mem.c",0x63f);
    return (ulong)uVar9;
  }
  uVar11 = __nvoc_dynamicCast(*(undefined8 *)(local_60 + 8),__nvoc_class_def_Device);
  uVar9 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar2,uVar4,uVar11,local_58);
  if (uVar9 != 0) {
    nvCheckOkFailedNoLog
              (3,uVar9,
               "kmigmgrGetInstanceRefFromDevice(pSrcGpu, pSrcKernelMIGManager, pSrcDevice, &srcInstRef)"
               ,"src/kernel/mem_mgr/video_mem.c",0x645);
    return (ulong)uVar9;
  }
  uVar9 = kmigmgrGetInstanceRefFromDevice_IMPL(param_2,uVar5,param_3,local_48);
  if (uVar9 != 0) {
    nvCheckOkFailedNoLog
              (3,uVar9,
               "kmigmgrGetInstanceRefFromDevice(pDstGpu, pDstKernelMIGManager, pDstDevice, &dstInstRef)"
               ,"src/kernel/mem_mgr/video_mem.c",0x648);
    return (ulong)uVar9;
  }
  local_58 = kmigmgrMakeGIReference_IMPL(local_58._0_8_);
  local_48 = kmigmgrMakeGIReference_IMPL(local_48._0_8_);
  cVar7 = kmigmgrAreMIGReferencesSame_IMPL(local_58,local_48);
  if (cVar7 != '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/mem_mgr/video_mem.c",0x654,"vidmemCheckCopyPermissions_IMPL",3,
               "NVRM: GPU instance subscription differ between Source and Destination clients\n");
  return 0x56;
}


// ===== 0046e440 vmmDestroyVaspace_IMPL =====

void vmmDestroyVaspace_IMPL(undefined8 param_1,long param_2)

{
  vaspaceDecRefCnt_IMPL(param_2);
  if (*(int *)(param_2 + 0x58) != 0) {
    return;
  }
  __nvoc_objDelete(param_2);
  return;
}


// ===== 0046e480 vmmGetVaspaceFromId_IMPL =====

undefined8 vmmGetVaspaceFromId_IMPL(long param_1,int param_2,int param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x38);
  }
  lVar2 = objGetChild_IMPL(uVar4);
  lVar5 = 0;
  if (lVar2 == 0) {
LAB_0046e5b0:
    uVar4 = 0x57;
  }
  else {
    do {
      if (param_3 == 0xf2) {
        while( true ) {
          lVar3 = __nvoc_dynamicCast(lVar2,__nvoc_class_def_OBJIOVASPACE);
          if (lVar3 != 0) {
            lVar5 = *(long *)(lVar3 + 0x88);
          }
          if (lVar5 != 0) break;
          lVar2 = objGetSibling_IMPL(lVar2);
          if (lVar2 == 0) goto LAB_0046e5b0;
          lVar5 = 0;
        }
        iVar1 = *(int *)(lVar5 + 0x5c);
      }
      else {
        while( true ) {
          if (param_3 == 0xfc) {
            lVar3 = __nvoc_dynamicCast(lVar2,__nvoc_class_def_FABRIC_VASPACE);
            if (lVar3 != 0) {
              lVar5 = *(long *)(lVar3 + 0x88);
            }
          }
          else {
            nvAssertFailedNoLog(&DAT_00d8739a,"src/kernel/mem_mgr/virt_mem_mgr.c",0xca);
          }
          if (lVar5 != 0) break;
          lVar2 = objGetSibling_IMPL(lVar2);
          if (lVar2 == 0) goto LAB_0046e5b0;
          lVar5 = 0;
        }
        iVar1 = *(int *)(lVar5 + 0x5c);
      }
      if (iVar1 == param_2) {
        uVar4 = 0;
        goto LAB_0046e58d;
      }
      lVar2 = objGetSibling_IMPL(lVar2);
    } while (lVar2 != 0);
    lVar5 = 0;
    uVar4 = 0x57;
  }
LAB_0046e58d:
  *param_4 = lVar5;
  return uVar4;
}


// ===== 0046e5c0 vmmCreateVaspace_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong vmmCreateVaspace_IMPL
                (undefined8 param_1,int param_2,undefined4 param_3,int param_4,undefined8 param_5,
                undefined8 param_6,undefined8 param_7)

{
  int *piVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined1 *puVar5;
  long *in_stack_00000028;
  undefined8 local_60;
  undefined8 local_40 [2];
  
  if (in_stack_00000028 == (long *)0x0) {
    nvAssertFailedNoLog("ppVAS != NULL","src/kernel/mem_mgr/virt_mem_mgr.c",0x3f);
    return 0x1f;
  }
  if (param_4 == 0) {
    if (param_2 != 0xf2) {
      nvAssertFailedNoLog("IO_VASPACE_A == classId","src/kernel/mem_mgr/virt_mem_mgr.c",0x49);
      return 0x1f;
    }
LAB_0046e615:
    iVar2 = vmmGetVaspaceFromId_IMPL(param_1,param_3,0xf2,in_stack_00000028);
    local_60 = 2;
    puVar5 = __nvoc_class_def_OBJIOVASPACE;
  }
  else {
    if (param_2 != 0xfc) {
      if (param_2 == 0x90f1) {
        local_60 = 1;
        puVar5 = __nvoc_class_def_OBJGVASPACE;
        goto LAB_0046e63f;
      }
      if (param_2 != 0xf2) {
        *in_stack_00000028 = 0;
        return 0x22;
      }
      goto LAB_0046e615;
    }
    iVar2 = vmmGetVaspaceFromId_IMPL(param_1,param_3,0xfc,in_stack_00000028);
    local_60 = 1;
    puVar5 = __nvoc_class_def_FABRIC_VASPACE;
  }
  if (iVar2 == 0) {
    vaspaceIncRefCnt_IMPL(*in_stack_00000028);
    return 0;
  }
LAB_0046e63f:
  uVar3 = __nvoc_objCreateDynamic(local_40,param_1,puVar5,0);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  lVar4 = __nvoc_dynamicCast(local_40[0],__nvoc_class_def_OBJVASPACE);
  *in_stack_00000028 = lVar4;
  *(undefined8 *)(lVar4 + 0x50) = local_60;
  *(undefined4 *)(*in_stack_00000028 + 0x5c) = param_3;
  *(int *)(*in_stack_00000028 + 0x48) = param_4;
  vaspaceIncRefCnt_IMPL(*in_stack_00000028);
  uVar3 = (**(code **)(*(long *)*in_stack_00000028 + 0x30))
                    ((long *)*in_stack_00000028,param_2,param_3,param_5,param_6,param_7);
  if ((int)uVar3 == 0) {
    LOCK();
    piVar1 = (int *)(g_pSys + 0x17c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    *(int *)(*in_stack_00000028 + 0x70) = iVar2 + 1;
    return uVar3;
  }
  lVar4 = *in_stack_00000028;
  vaspaceDecRefCnt_IMPL(lVar4);
  if (*(int *)(lVar4 + 0x58) == 0) {
    __nvoc_objDelete(lVar4);
  }
  *in_stack_00000028 = 0;
  return uVar3 & 0xffffffff;
}


// ===== 0046e870 vmrangeConstruct_IMPL.cold =====

void vmrangeConstruct_IMPL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x20) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046e890 vmrangeConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int vmrangeConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong *puVar8;
  ulong uVar9;
  code *pcVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  undefined8 uVar14;
  ulong uVar15;
  int local_4c;
  long local_48;
  undefined8 local_40 [2];
  
  lVar5 = *(long *)(param_2 + 0x10);
  local_48 = 0;
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(lVar5 + 0x18) + 0x10);
  uVar3 = *(undefined4 *)(lVar5 + 0x10);
  uVar4 = *(undefined4 *)(lVar5 + 0x11c);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)invalidInstructionException();
    (*pcVar10)();
  }
  lVar6 = *(long *)(param_1 + 0x2a0);
  lVar12 = *(long *)(param_1 + 0x2b0);
  local_40[0] = 0;
  lVar7 = *(long *)(lVar6 + 0xf0);
  if (*(long *)(param_3 + 0x58) != 0) {
    return 0;
  }
  puVar8 = *(ulong **)(param_3 + 0x40);
  iVar11 = (int)puVar8[2];
  if (iVar11 == 0) {
    uVar15 = *(ulong *)(*(long *)(lVar7 + 0x1b98) + 0x598);
    if (uVar15 == 0) {
      nvAssertFailedNoLog("kgmmuGetMaxVASize(pKernelGmmu)","src/kernel/mem_mgr/virt_mem_range.c",
                          0x49);
      return 0x40;
    }
  }
  else if (iVar11 == -1) {
    uVar15 = 0x10000000000;
    if (*(long *)(*(long *)(lVar7 + 0x1b98) + 0x598) == 0) {
      nvAssertFailedNoLog("kgmmuGetMaxVASize(pKernelGmmu)","src/kernel/mem_mgr/virt_mem_range.c",
                          0x4e);
      return 0x40;
    }
  }
  else {
    local_4c = clientGetResourceRef_IMPL(*(long *)(param_2 + 8),iVar11,&local_48);
    if (local_4c != 0) {
      uVar14 = 0x56;
      goto LAB_0046ec08;
    }
    lVar13 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_VaSpaceApi);
    if (lVar13 == 0) {
      nvCheckFailedNoLog(1,&DAT_00d8741f,"src/kernel/mem_mgr/virt_mem_range.c",0x58);
      return 0x33;
    }
    if (*(long *)(lVar13 + 0x138) == 0) {
      nvAssertFailedNoLog("pVAS->pVASpace","src/kernel/mem_mgr/virt_mem_range.c",0x59);
      return 0x33;
    }
    uVar15 = *(long *)(*(long *)(lVar13 + 0x138) + 0x68) + 1;
  }
  uVar9 = puVar8[1];
  if (uVar9 != 0) {
    if (uVar15 <= uVar9) {
      nvCheckFailedNoLog(1,"pAllocData->limit < maxVA","src/kernel/mem_mgr/virt_mem_range.c",0x5f);
      return 0x2e;
    }
    uVar15 = uVar9 + 1;
  }
  uVar9 = *puVar8;
  if (uVar15 <= uVar9) {
    nvCheckFailedNoLog(1,"pAllocData->offset < maxVA","src/kernel/mem_mgr/virt_mem_range.c",99);
    return 0x37;
  }
  local_4c = memCreateMemDesc_IMPL(lVar7,local_40,4,uVar9,uVar15 - uVar9,0,0);
  if (local_4c == 0) {
    iVar11 = memConstructCommon_IMPL(lVar6,uVar4,0,local_40[0],0,0,0,0,0,0,0,0);
    if (iVar11 != 0) {
      memdescDestroy(local_40[0]);
      return iVar11;
    }
    *(undefined1 *)(lVar12 + 0x264) = 1;
    *(int *)(lVar12 + 0x260) = (int)puVar8[2];
    if ((*(char *)(lVar7 + 0x908) != '\0') || (*(char *)(lVar7 + 0x909) != '\0')) {
      lVar12 = gpuGetRpc(lVar7);
      if (lVar12 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/virt_mem_range.c",0x7f);
      }
      else {
        if ((*(char *)(lVar7 + 0x909) == '\0') && (*(char *)(lVar7 + 0x90a) == '\0')) {
          iVar11 = (**(code **)(lVar12 + 0x348))(lVar7,lVar12,uVar1,uVar2,uVar3,uVar4,puVar8);
        }
        else {
          iVar11 = (**(code **)(lVar7 + 0x3b60))(lVar7 + 0x3b58,uVar1,uVar2,uVar3,uVar4,puVar8,0x18)
          ;
        }
        if (iVar11 != 0) {
          memdescDestroy(local_40[0]);
          return iVar11;
        }
      }
      *(undefined1 *)(lVar6 + 0x1b0) = 1;
    }
    puVar8[1] = uVar15 - 1;
    if (local_48 != 0) {
      refAddDependant(local_48,lVar5);
      return 0;
    }
    return 0;
  }
  uVar14 = 0x69;
LAB_0046ec08:
  nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/mem_mgr/virt_mem_range.c",uVar14);
  return local_4c;
}


// ===== 0046ed40 _virtmemFreeKernelMapping =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _virtmemFreeKernelMapping(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  
  cVar2 = *(char *)(param_1 + 0x454);
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu();
  lVar1 = param_2 + (ulong)uVar3 * 8;
  if (*(long *)(lVar1 + 8) == 0) {
    lVar5 = *(long *)(lVar1 + 0x90);
    if (cVar2 == '\0') {
      if (lVar5 == 0) {
        return;
      }
LAB_0046edde:
      kbusUnmapFbApertureSingle_IMPL
                (param_1,*(undefined8 *)(&DAT_00001b90 + param_1),*(undefined8 *)(param_2 + 0xd0),
                 *(undefined8 *)(lVar1 + 0x50),lVar5,0x20);
      *(undefined8 *)(lVar1 + 0x50) = 0;
      *(undefined8 *)(lVar1 + 0x90) = 0;
      *(undefined8 *)(param_2 + 0x48) = 0;
      return;
    }
  }
  else if (cVar2 == '\0') {
    osUnmapPciMemoryKernelOld(param_1);
    lVar5 = *(long *)(lVar1 + 0x90);
    *(undefined8 *)(lVar1 + 8) = 0;
    if (lVar5 != 0) goto LAB_0046edde;
  }
  else {
    lVar5 = *(long *)(&DAT_00001b90 + param_1);
    uVar4 = memdescGetMemDescFromGpu(*(undefined8 *)(param_2 + 0xd0),param_1);
    (**(code **)(lVar5 + 0x520))
              (param_1,lVar5,uVar4,*(undefined8 *)(lVar1 + 8),*(undefined8 *)(param_2 + 0x48));
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  return;
}


// ===== 0046ee43 virtmemDestruct_IMPL.cold =====

void virtmemDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046ee50 virtmemDestruct_IMPL =====

void virtmemDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  code *pcVar9;
  int iVar10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)invalidInstructionException();
    (*pcVar9)();
  }
  lVar4 = *(long *)(param_1 + 0x248);
  if (*(char *)(lVar4 + 0xd8) != '\0') {
    lVar5 = *(long *)(lVar4 + 0xf0);
    lVar6 = *(long *)(lVar4 + 0x118);
    iVar10 = *(int *)(lVar4 + 0x108);
    uVar7 = *(undefined8 *)(lVar5 + 0x1b78);
    plVar8 = *(long **)(*(long *)(param_1 + 0x230) + 0x48);
    uVar1 = *(undefined4 *)(plVar8[3] + 0x10);
    uVar2 = *(undefined4 *)(*plVar8 + 0x48);
    uVar3 = *(undefined4 *)(param_1 + 0x260);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pMemDesc","src/kernel/mem_mgr/virtual_mem.c",0x2a5);
    }
    memDestructCommon_IMPL(lVar4);
    if ((*(char *)(lVar4 + 0x1b0) != '\0') || (*(int *)(lVar4 + 0xfc) == 0x70)) {
      if (*(char *)(lVar6 + 100) != '\0') {
        nvAssertFailedNoLog("pMemDesc->Allocated == 0","src/kernel/mem_mgr/virtual_mem.c",0x2b3);
      }
      memdescDestroy(lVar6);
      return;
    }
    if (iVar10 == 0) {
      nvAssertFailedNoLog("heapOwner != 0","src/kernel/mem_mgr/virtual_mem.c",0x2b8);
    }
    iVar10 = memmgrFree_IMPL(lVar5,uVar7,0,uVar2,uVar1,uVar3,iVar10,lVar6);
    if (iVar10 == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x2c5,"virtmemDestruct_IMPL",4,
                 "NVRM: VirtualMemory memmgrFree failed, client: %x, hVASpace: %x, gpu: %x\n",
                 *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x230) + 0x48) + 0x48),uVar3,
                 *(undefined4 *)(lVar5 + 0x7a4));
  }
  return;
}


// ===== 0046f030 virtmemAllocResources =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int virtmemAllocResources(long param_1,long param_2,long *param_3,long param_4,long param_5)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  char local_5b;
  ushort local_5a;
  long local_58;
  long *local_50;
  long local_48;
  long *local_40 [2];
  
  lVar2 = *param_3;
  local_58 = 0;
  uVar1 = *(undefined4 *)(lVar2 + 0x6c);
  local_5b = '\0';
  if (0x3fffffff < *(uint *)(lVar2 + 8)) {
    nvAssertFailedNoLog("!(pVidHeapAlloc->flags & NVOS32_ALLOC_FLAGS_WPR1) && !(pVidHeapAlloc->flags & NVOS32_ALLOC_FLAGS_WPR2)"
                        ,"src/kernel/mem_mgr/virtual_mem.c",0x2e1);
  }
  if (param_5 == 0) {
    nvAssertFailedNoLog("pFbAllocInfoClient != NULL","src/kernel/mem_mgr/virtual_mem.c",0x2e2);
    return 0x23;
  }
  iVar5 = memUtilsAllocMemDesc(param_1,param_3,param_4,&local_58,0,4,1,&local_5b);
  if (iVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar5,
               "memUtilsAllocMemDesc(pGpu, pAllocRequest, pFbAllocInfo, &pMemDesc, NULL, ADDR_VIRTUAL, NV_TRUE, &bAllocedMemDesc)"
               ,"src/kernel/mem_mgr/virtual_mem.c",0x2e4);
    goto LAB_0046f11c;
  }
  if ((*(byte *)(lVar2 + 8) & 0x10) != 0) {
    *(long *)(param_4 + 0x38) = *(long *)(lVar2 + 0x50) - *(long *)(param_4 + 0x28);
  }
  lVar8 = *(long *)(param_5 + 0x100);
  if (*(char *)(param_1 + 0x4913) == '\0') {
    if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) {
LAB_0046f3a0:
      if (*(char *)(param_1 + 0x4922) == '\0') {
        uVar3 = *(undefined8 *)(local_58 + 0x30);
        uVar9 = memdescGetPte(local_58,1,0);
        memdescDescribe(local_58,4,uVar9,uVar3);
        goto LAB_0046f29c;
      }
    }
  }
  else {
    local_40[0] = (long *)0x0;
    if ((lVar8 != 0) &&
       (iVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                          (lVar8,*(undefined4 *)(param_4 + 0x9c),uVar1,local_40), iVar5 != 0))
    goto LAB_0046f11c;
    uVar6 = (**(code **)(*local_40[0] + 0x70))();
    uVar7 = (**(code **)(*local_40[0] + 0x70))();
    if (((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) &&
       ((uVar6 & 0x80) == 0 && (uVar7 & 0x1000000) == 0)) goto LAB_0046f3a0;
  }
  local_50 = (long *)0x0;
  local_5a = 0;
  local_48 = *(long *)(param_4 + 0x20) + 1;
  local_40[0] = (long *)0x0;
  *(undefined4 *)(param_4 + 0x40) = *(undefined4 *)((long)param_3 + 0x14);
  if ((lVar8 == 0) ||
     (iVar5 = vaspaceGetByHandleOrDeviceDefault_IMPL
                        (lVar8,*(undefined4 *)(param_4 + 0x9c),uVar1,&local_50), iVar5 == 0)) {
    lVar8 = __nvoc_dynamicCast(local_50,__nvoc_class_def_OBJGVASPACE);
    if ((lVar8 == 0) ||
       (((*(byte *)(lVar8 + 0xb8) & 0x40) == 0 || ((*(byte *)(lVar2 + 8) & 0x10) != 0)))) {
      iVar5 = vaspaceFillAllocParams_IMPL
                        (local_50,param_4,param_4 + 0x18,&local_48,lVar2 + 0x30,lVar2 + 0x38,
                         local_40,&local_5a);
      if (iVar5 == 0) {
        uVar10 = (ulong)local_5a;
        iVar5 = (**(code **)(*local_50 + 0x38))
                          (local_50,*(undefined8 *)(param_4 + 0x18),local_48,
                           *(undefined8 *)(lVar2 + 0x30),*(undefined8 *)(lVar2 + 0x38),local_40[0],
                           uVar10,param_4 + 0x38);
        if (iVar5 != 0) {
          nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x33e,"virtmemAllocResources",4,
                       "NVRM: VA Space alloc failed! Status Code: 0x%x Size: 0x%llx RangeLo: 0x%llx, RangeHi: 0x%llx, pageSzLockMask: 0x%llx\n"
                       ,iVar5,*(undefined8 *)(param_4 + 0x18),*(undefined8 *)(lVar2 + 0x30),
                       *(undefined8 *)(lVar2 + 0x38),local_40[0]);
          iVar5 = 0x1a;
          goto LAB_0046f11c;
        }
        uVar11 = (ulong)local_40[0] >> 1;
        if (uVar11 == 0) {
          lVar8 = 1;
        }
        else {
          lVar8 = 0x3f;
          if (uVar11 != 0) {
            for (; uVar11 >> lVar8 == 0; lVar8 = lVar8 + -1) {
            }
          }
          uVar6 = (int)lVar8 + 1;
          uVar10 = (ulong)uVar6;
          lVar8 = 1L << ((byte)uVar6 & 0x3f);
        }
        memdescSetPageSize(local_58,3,lVar8,uVar10);
        memdescDescribe(local_58,4,*(undefined8 *)(param_4 + 0x38),*(undefined8 *)(param_4 + 0x18));
        *(long *)(param_4 + 0x20) = local_48 + -1;
        *(long *)(lVar2 + 0x48) = local_48;
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x331,"virtmemAllocResources",4,
                     "NVRM: FillAllocParams failed.\n");
      }
LAB_0046f29c:
      uVar6 = *(uint *)(param_4 + 0x44);
      if ((*(ushort *)(*(long *)(param_4 + 0x90) + 2) & 0x180) == 0) {
        uVar6 = uVar6 & 0xfe7fffff;
        *(uint *)(param_4 + 0x44) = uVar6;
      }
      *(uint *)(lVar2 + 0x18) = uVar6;
      *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_4 + 0x48);
      cVar4 = memdescGetContiguity(param_3[4],1);
      uVar7 = *(uint *)(lVar2 + 0x18) & 0xe7ffffff;
      uVar6 = uVar7 | 0x8000000;
      if (cVar4 != '\0') {
        uVar6 = uVar7 | 0x10000000;
      }
      *(uint *)(lVar2 + 0x18) = uVar6;
      *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)(param_4 + 0x38);
      if ((undefined4 *)param_3[3] == (undefined4 *)0x0) {
        return 0;
      }
      *(undefined4 *)param_3[3] = *(undefined4 *)(param_4 + 0x44);
      *(undefined4 *)(param_3[3] + 4) = *(undefined4 *)(param_4 + 0x48);
      *(undefined4 *)(param_3[3] + 0x10) = *(undefined4 *)(param_4 + 4);
      *(undefined4 *)(param_3[3] + 8) = *(undefined4 *)(param_4 + 0x50);
      *(undefined4 *)(param_3[3] + 0xc) = *(undefined4 *)(param_4 + 0xa4);
      *(undefined4 *)(param_3[3] + 0x10) = *(undefined4 *)(param_4 + 4);
      return 0;
    }
    nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x326,"virtmemAllocResources",4,
                 "NVRM: The VA space requires all allocations to specify a fixed address\n");
    iVar5 = 0x1f;
  }
LAB_0046f11c:
  (**(code **)(param_2 + 0x170))(param_1,param_2,param_4);
  if (local_5b != '\0') {
    memdescDestroy(param_3[4]);
    param_3[4] = 0;
  }
  return iVar5;
}


// ===== 0046f55a virtmemConstruct_IMPL.cold =====

void virtmemConstruct_IMPL_cold(void)

{
  code *pcVar1;
  long lVar2;
  long unaff_RBP;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(unaff_RBP + -0xa8);
  for (lVar2 = 0x1e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0046f5b0 virtmemConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int virtmemConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  long lVar4;
  undefined8 uVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  undefined1 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  long lVar16;
  long lVar17;
  byte extraout_var;
  byte extraout_var_00;
  long lVar18;
  ulong uVar19;
  long lVar20;
  undefined8 uVar21;
  undefined4 *puVar22;
  long lVar23;
  undefined8 uVar24;
  uint uVar25;
  char *pcVar26;
  undefined4 **ppuVar27;
  undefined8 local_168;
  char local_148;
  long local_128;
  undefined4 local_10c;
  long *local_108;
  long local_100;
  undefined8 local_f8;
  ulong local_f0;
  long *local_e8;
  long local_e0;
  undefined8 local_d8;
  long *local_d0 [4];
  undefined4 *local_b0;
  long local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  long **local_98;
  long local_90 [9];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulong uVar15;
  
  if (param_1 == 0) {
    ppuVar27 = &local_b0;
    for (lVar23 = 0x1e; lVar23 != 0; lVar23 = lVar23 + -1) {
      *(undefined4 *)ppuVar27 = 0;
      ppuVar27 = (undefined4 **)((long)ppuVar27 + 4);
    }
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar23 = *(long *)(param_1 + 0x248);
  puVar3 = *(undefined4 **)(param_3 + 0x40);
  uVar19 = 0;
  do {
    uVar11 = (int)uVar19 + 0x20;
    uVar15 = (ulong)uVar11;
    *(undefined8 *)((long)&local_b0 + uVar19) = 0;
    *(undefined8 *)((long)&local_a8 + uVar19) = 0;
    *(undefined8 *)((long)&local_a0 + uVar19) = 0;
    *(undefined8 *)((long)local_90 + (uVar19 - 8)) = 0;
    uVar19 = uVar15;
  } while (uVar11 < 0x60);
  *(undefined8 *)((long)&local_b0 + uVar15) = 0;
  *(undefined8 *)((long)&local_a8 + uVar15) = 0;
  *(undefined8 *)((long)&local_a0 + uVar15) = 0;
  local_108 = (long *)0x0;
  lVar4 = *(long *)(lVar23 + 0xf0);
  lVar20 = *(long *)(lVar4 + 0x1b78);
  uVar21 = *(undefined8 *)(param_2 + 8);
  lVar16 = __nvoc_dynamicCast(uVar21,__nvoc_class_def_RmClient);
  lVar17 = *(long *)(param_2 + 0x10);
  local_100 = 0;
  local_10c = 0;
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(lVar17 + 0x18) + 0x10);
  if (lVar16 == 0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/mem_mgr/virtual_mem.c",0x145);
    return 0x23;
  }
  if (*(long *)(param_3 + 0x58) == 0) {
    *(undefined4 *)(param_1 + 0x260) = 0xffffffff;
    *(undefined2 *)(param_1 + 0x264) = 0;
    *(undefined1 *)(param_1 + 0x266) = 0;
    *(undefined8 *)(param_1 + 0x268) = 0;
    if (*(int *)(param_3 + 0xc) == 0x70) {
      return 0;
    }
    iVar12 = stdmemValidateParams_IMPL(lVar4,lVar16,puVar3);
    if (iVar12 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar12,"stdmemValidateParams(pGpu, pRmClient, pAllocData)",
                 "src/kernel/mem_mgr/virtual_mem.c",0x161);
      return iVar12;
    }
    if ((*(byte *)((long)puVar3 + 10) & 8) == 0) {
      nvCheckFailedNoLog(4,"pAllocData->flags & NVOS32_ALLOC_FLAGS_VIRTUAL",
                         "src/kernel/mem_mgr/virtual_mem.c",0x162);
      return 0x1f;
    }
    stdmemDumpInputAllocParams_IMPL(puVar3,param_2);
    local_48 = 0x50a0;
    local_a0 = *(undefined4 *)(lVar17 + 0x10);
    local_9c = 1;
    local_98 = local_d0;
    local_b0 = puVar3;
    local_a8 = lVar4;
    local_44 = uVar1;
    local_40 = uVar2;
    if ((*(char *)(lVar20 + 0x434) != '\0') && ((*(ushort *)((long)puVar3 + 9) & 0x4004) == 0)) {
      iVar12 = deviceGetByHandle_IMPL(uVar21,uVar2,&local_e0);
      if (iVar12 != 0) {
        nvAssertOkFailedNoLog
                  (iVar12,"deviceGetByHandle(pRsClient, hParent, &pDevice)",
                   "src/kernel/mem_mgr/virtual_mem.c",0x186);
        goto joined_r0x004708a9;
      }
      local_f0 = 0;
      local_e8 = (long *)0x0;
      uVar5 = *(undefined8 *)(lVar4 + 0x1b78);
      local_f8 = 0;
      local_a8 = lVar4;
      lVar18 = portMemAllocNonPaged(0xc0);
      if (lVar18 == 0) {
        nvAssertFailedNoLog(&DAT_00d8770b,"src/kernel/mem_mgr/virtual_mem.c",0x5a);
        portMemFree(0);
        portMemFree(0);
      }
      else {
        puVar22 = (undefined4 *)portMemAllocNonPaged(0x14);
        if (puVar22 != (undefined4 *)0x0) {
          portMemSet(lVar18,0,0xc0);
          portMemSet(puVar22,0,0x14);
          *(undefined4 **)(lVar18 + 0x90) = puVar22;
          *puVar22 = puVar3[6];
          *(undefined4 *)(*(long *)(lVar18 + 0x90) + 4) = puVar3[7];
          *(undefined4 *)(*(long *)(lVar18 + 0x90) + 8) = puVar3[2];
          local_f8 = *(undefined8 *)(puVar3 + 0x10);
          local_f0 = *(ulong *)(puVar3 + 0x12);
          cVar9 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar4 + 0x7a4));
          if (cVar9 == '\0') {
            iVar12 = rmDeviceGpuLocksAcquire(lVar4,0,0x2002);
            uVar24 = 0x73;
            pcVar26 = "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM_PMA)"
            ;
            if (iVar12 == 0) {
              iVar12 = 0x40;
              local_e8 = (long *)stdmemQueryPageSize_IMPL(uVar5,uVar1,puVar3);
              if (local_e8 != (long *)0x0) {
                iVar12 = serverGetClientUnderLock(g_resServ,uVar1,&local_d8);
                if (iVar12 == 0) {
                  bVar8 = true;
                  goto LAB_0047070c;
                }
                nvAssertOkFailedNoLog
                          (iVar12,"serverGetClientUnderLock(&g_resServ, hClient, &pClient)",
                           "src/kernel/mem_mgr/virtual_mem.c",0x80);
              }
LAB_0047029c:
              rmDeviceGpuLocksRelease(lVar4,0,0);
            }
            else {
LAB_00470932:
              nvAssertOkFailedNoLog(iVar12,pcVar26,"src/kernel/mem_mgr/virtual_mem.c",uVar24);
            }
          }
          else {
            local_e8 = (long *)stdmemQueryPageSize_IMPL(uVar5,uVar1,puVar3);
            if (local_e8 == (long *)0x0) {
              iVar12 = 0x40;
              portMemFree(puVar22);
              portMemFree(lVar18);
              goto joined_r0x004708a9;
            }
            iVar12 = serverGetClientUnderLock(g_resServ,uVar1,&local_d8);
            if (iVar12 != 0) {
              uVar24 = 0x80;
              pcVar26 = "serverGetClientUnderLock(&g_resServ, hClient, &pClient)";
              goto LAB_00470932;
            }
            bVar8 = false;
LAB_0047070c:
            iVar12 = vaspaceGetByHandleOrDeviceDefault_IMPL(local_d8,uVar2,puVar3[0x1b],&local_108);
            if (iVar12 == 0) {
              iVar12 = (**(code **)(*local_108 + 0x48))
                                 (local_108,lVar18,&local_f0,&local_f8,&local_e8);
              if (iVar12 == 0) {
                if (bVar8) {
                  rmDeviceGpuLocksRelease(lVar4,0,0);
                }
                portMemFree(puVar22);
                portMemFree(lVar18);
                iVar12 = (**(code **)(*local_108 + 0x88))
                                   (local_108,lVar4,local_e0,local_f8,local_e8,0);
                if (iVar12 == 0) goto LAB_0046f980;
                goto joined_r0x004708a9;
              }
              nvAssertOkFailedNoLog
                        (iVar12,
                         "vaspaceApplyDefaultAlignment(*ppVAS, pFbAllocInfo, pAlign, pSize, pPageSizeLockMask)"
                         ,"src/kernel/mem_mgr/virtual_mem.c",0x88);
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar12,
                         "vaspaceGetByHandleOrDeviceDefault(pClient, hDevice, pAllocData->hVASpace, ppVAS)"
                         ,"src/kernel/mem_mgr/virtual_mem.c",0x84);
            }
            if (bVar8) goto LAB_0047029c;
          }
          portMemFree(puVar22);
          portMemFree(lVar18);
          goto joined_r0x004708a9;
        }
        nvAssertFailedNoLog(&DAT_00d8770b,"src/kernel/mem_mgr/virtual_mem.c",0x61);
        portMemFree(0);
        portMemFree(lVar18);
      }
      iVar12 = 0x51;
      goto joined_r0x004708a9;
    }
LAB_0046f980:
    cVar9 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar4 + 0x7a4));
    if (cVar9 == '\0') {
      cVar9 = rmGpuLockIsOwner();
      bVar8 = false;
      if (cVar9 == '\0') {
        iVar12 = rmDeviceGpuLocksAcquire(lVar4,0,0x2000);
        bVar8 = true;
        if (iVar12 != 0) {
          nvAssertOkFailedNoLog
                    (iVar12,
                     "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                     "src/kernel/mem_mgr/virtual_mem.c",0x1a8);
          goto joined_r0x004708a9;
        }
      }
    }
    else {
      bVar8 = false;
    }
    local_128 = 0;
    if ((*(long *)(lVar4 + 0x1c18) != 0) &&
       (cVar9 = krcTestAllowAlloc_IMPL(lVar4,*(long *)(lVar4 + 0x1c18),0x100), cVar9 == '\0')) {
      if ((local_90[0] == 0) || (*(long *)(lVar23 + 0x118) == 0)) {
        lVar18 = 0;
        local_128 = 0;
        iVar12 = 0x1a;
      }
      else {
        lVar18 = 0;
        iVar12 = 0x1a;
        memDestructCommon_IMPL(lVar23);
        *(undefined8 *)(lVar23 + 0x118) = 0;
      }
      goto LAB_0046fc4c;
    }
    iVar12 = vaspaceGetByHandleOrDeviceDefault_IMPL(uVar21,uVar2,puVar3[0x1b],&local_108);
    if (iVar12 == 0) {
      (**(code **)(*local_108 + 0x70))();
      *(byte *)(param_1 + 0x266) = extraout_var & 1;
      (**(code **)(*local_108 + 0x70))();
      *(byte *)(param_1 + 0x270) = extraout_var_00 >> 3 & 1;
      if ((*(char *)(lVar4 + 0x908) != '\0') || (*(char *)(lVar4 + 0x909) != '\0')) {
        if (*(char *)(lVar4 + 0x4913) == '\0') {
          (**(code **)(*local_108 + 0x70))();
          if (*(char *)(lVar4 + 0x4922) == '\0') goto LAB_0046fd81;
          goto LAB_0046fa44;
        }
        cVar9 = *(char *)(lVar4 + 0x491e);
        uVar19 = (**(code **)(*local_108 + 0x70))();
        if ((*(char *)(lVar4 + 0x4922) != '\0') ||
           ((cVar9 == '\0' && (((uVar19 & 0x80) != 0 || (*(char *)(param_1 + 0x266) != '\0'))))))
        goto LAB_0046fa44;
LAB_0046fd81:
        lVar18 = 0;
        iVar12 = memdescCreate(local_90,lVar4,*(undefined8 *)(local_b0 + 0x10),0,1,4,1);
        local_148 = '\x01';
        bVar7 = false;
        if (iVar12 == 0) {
LAB_0046fb1d:
          if (local_90[0] == 0) {
            nvAssertFailedNoLog("pAllocRequest->pMemDesc != NULL","src/kernel/mem_mgr/virtual_mem.c"
                                ,0x1fb);
          }
          local_168 = memdescGetPhysAddr(local_90[0],1,0);
          lVar16 = *(long *)(local_90[0] + 0x30);
          *(long *)(puVar3 + 0x16) = lVar16 + -1;
          uVar11 = puVar3[7];
          uVar25 = uVar11 & 0xc;
          if (uVar25 == 0) {
            uVar11 = uVar11 & 0xfffffff3 | 8;
            puVar3[7] = uVar11;
          }
          if (local_148 != '\0') {
            uVar5 = *(undefined8 *)(puVar3 + 0x14);
            uVar24 = *(undefined8 *)(local_90[0] + 0x30);
            uVar14 = memdescGetAddressSpace(local_90[0]);
            memdescDescribe(local_90[0],uVar14,uVar5,uVar24);
            local_168 = memdescGetPhysAddr(local_90[0],1,0);
            uVar11 = puVar3[7];
          }
          iVar12 = memConstructCommon_IMPL
                             (lVar23,local_48,puVar3[2],local_90[0],*puVar3,0,puVar3[6],uVar11,0,
                              puVar3[1],0,0);
          iVar13 = iVar12;
          if (iVar12 == 0) {
            *(char *)(lVar23 + 0x1b0) = local_148;
            uVar14 = puVar3[0x1b];
            *(undefined1 *)(param_1 + 0x265) = 1;
            *(undefined4 *)(param_1 + 0x260) = uVar14;
            if (puVar3[0x1b] != 0) {
              iVar13 = clientGetResourceRef_IMPL(uVar21,puVar3[0x1b],&local_100);
              if (iVar13 != 0) goto LAB_004703d8;
              if (local_100 != 0) {
                refAddDependant(local_100,lVar17);
              }
            }
            lVar20 = *(long *)(lVar23 + 0x118);
            if (lVar20 == 0) {
              nvAssertFailedNoLog("pMemory->pMemDesc","src/kernel/mem_mgr/virtual_mem.c",600);
              lVar20 = *(long *)(lVar23 + 0x118);
            }
            iVar13 = memdescGetAddressSpace(lVar20);
            if (iVar13 != 4) {
              nvAssertFailedNoLog("memdescGetAddressSpace(pMemory->pMemDesc) == ADDR_VIRTUAL",
                                  "src/kernel/mem_mgr/virtual_mem.c",0x259);
            }
            memdescSetGpuCacheAttrib(*(undefined8 *)(lVar23 + 0x118),uVar25 != 4);
            *(long *)(puVar3 + 0x10) = lVar16;
            *(undefined8 *)(puVar3 + 0x14) = local_168;
            stdmemDumpOutputAllocParams_IMPL(puVar3);
            goto LAB_0046fc4c;
          }
LAB_004703d8:
          iVar12 = iVar13;
          if (local_90[0] == 0) goto LAB_0046fc4c;
          if (*(long *)(lVar23 + 0x118) != 0) {
            memDestructCommon_IMPL(lVar23);
            *(undefined8 *)(lVar23 + 0x118) = 0;
          }
          if (bVar7) {
            memmgrFree_IMPL(lVar4,lVar20,0,uVar1,uVar2,puVar3[0x1b],*puVar3,local_90[0]);
          }
          if (local_148 == '\0') goto LAB_0046fc4c;
        }
        else {
          if (local_90[0] == 0) goto LAB_00470643;
          if (*(long *)(lVar23 + 0x118) == 0) {
            local_128 = 0;
            lVar18 = 0;
          }
          else {
            lVar18 = 0;
            memDestructCommon_IMPL(lVar23);
            *(undefined8 *)(lVar23 + 0x118) = 0;
          }
        }
        memdescDestroy(local_90[0]);
        goto LAB_0046fc4c;
      }
LAB_0046fa44:
      local_128 = portMemAllocNonPaged(0xc0);
      if (local_128 != 0) {
        lVar18 = portMemAllocNonPaged(0x14);
        if (lVar18 == 0) {
          nvAssertOkFailedNoLog
                    (0x51,"pFbAllocPageFormat != NULL","src/kernel/mem_mgr/virtual_mem.c",0x1e7);
          iVar12 = 0x51;
        }
        else {
          portMemSet(local_128,0,0xc0);
          portMemSet(lVar18,0,0x14);
          *(long *)(local_128 + 0x90) = lVar18;
          memUtilsInitFBAllocInfo(local_b0,local_128,uVar1,uVar2);
          iVar12 = memmgrAllocResources_IMPL(lVar4,lVar20,&local_b0,local_128);
          if (iVar12 == 0) {
            iVar12 = virtmemAllocResources(lVar4,lVar20,&local_b0,local_128,lVar16);
            local_148 = '\0';
            bVar7 = true;
            if (iVar12 == 0) goto LAB_0046fb1d;
          }
        }
        if ((local_90[0] != 0) && (*(long *)(lVar23 + 0x118) != 0)) {
          memDestructCommon_IMPL(lVar23);
          *(undefined8 *)(lVar23 + 0x118) = 0;
        }
        goto LAB_0046fc4c;
      }
      nvAssertOkFailedNoLog(0x51,"pFbAllocInfo != NULL","src/kernel/mem_mgr/virtual_mem.c",0x1e4);
      iVar12 = 0x51;
      lVar18 = 0;
      if (local_90[0] == 0) goto LAB_0046fc4c;
      iVar12 = 0x51;
      lVar18 = 0;
      if (*(long *)(lVar23 + 0x118) == 0) goto LAB_0046fc4c;
    }
    else if ((local_90[0] == 0) || (*(long *)(lVar23 + 0x118) == 0)) {
LAB_00470643:
      lVar18 = 0;
      local_128 = 0;
      goto LAB_0046fc4c;
    }
    lVar18 = 0;
    memDestructCommon_IMPL(lVar23);
    *(undefined8 *)(lVar23 + 0x118) = 0;
LAB_0046fc4c:
    portMemFree(lVar18);
    portMemFree(local_128);
    if (!bVar8) {
      return iVar12;
    }
    rmDeviceGpuLocksRelease(lVar4,0,0);
    return iVar12;
  }
  iVar12 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar4 + 0x7a4),3,2,0x2000,&local_10c);
  if (iVar12 != 0) {
    nvAssertOkFailedNoLog
              (iVar12,
               "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_ALL, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_MEM, &gpuMask)"
               ,"src/kernel/mem_mgr/virtual_mem.c",0x14a);
    return iVar12;
  }
  lVar4 = *(long *)(param_2 + 8);
  uVar21 = *(undefined8 *)(param_3 + 0x50);
  lVar17 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                              __nvoc_class_def_VirtualMemory);
  lVar20 = *(long *)(param_1 + 0x248);
  if (lVar17 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar16 = *(long *)(lVar17 + 0x248);
  lVar18 = *(long *)(lVar16 + 0xf0);
  local_e8 = (long *)0x0;
  if (*(char *)(lVar17 + 0x266) == '\0') {
    if (*(int *)(lVar17 + 0x260) == -1) {
      *(undefined4 *)(param_1 + 0x260) = 0xffffffff;
      uVar10 = *(undefined1 *)(lVar17 + 0x264);
LAB_0046fc91:
      *(undefined1 *)(param_1 + 0x264) = uVar10;
      *(undefined1 *)(param_1 + 0x265) = *(undefined1 *)(lVar17 + 0x265);
      uVar10 = *(undefined1 *)(lVar17 + 0x266);
      *(undefined8 *)(param_1 + 0x268) = 0;
      *(undefined1 *)(param_1 + 0x266) = uVar10;
LAB_0046fcbe:
      rmGpuGroupLockRelease(local_10c,0);
      iVar12 = 0;
      goto LAB_0046f890;
    }
    local_d0[0] = (long *)0x0;
    if (*(long *)(lVar16 + 0xe0) == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)invalidInstructionException();
      (*pcVar6)();
    }
    iVar12 = vaspaceGetByHandleOrDeviceDefault_IMPL
                       (uVar21,*(undefined4 *)
                                (*(long *)(*(long *)(*(long *)(lVar16 + 0xe0) + 0x110) + 0x48) +
                                0x10),*(int *)(lVar17 + 0x260),&local_e8);
    if (iVar12 != 0) {
      rmGpuGroupLockRelease(local_10c,0);
      if ((local_90[0] != 0) && (*(long *)(lVar23 + 0x118) != 0)) {
        memDestructCommon_IMPL(lVar23);
        *(undefined8 *)(lVar23 + 0x118) = 0;
      }
      portMemFree(0);
      portMemFree(0);
      return iVar12;
    }
    lVar20 = *(long *)(lVar20 + 0xe0);
    if (lVar20 == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)invalidInstructionException();
      (*pcVar6)();
    }
    iVar12 = vaspaceGetByHandleOrDeviceDefault_IMPL
                       (lVar4,*(undefined4 *)(*(long *)(*(long *)(lVar20 + 0x110) + 0x48) + 0x10),0,
                        local_d0);
    if (iVar12 == 0) {
      if (local_e8 == local_d0[0]) {
        *(undefined4 *)(param_1 + 0x260) = 0;
        uVar10 = *(undefined1 *)(lVar17 + 0x264);
        if ((*(char *)(lVar17 + 0x265) != '\0') && (*(char *)(lVar16 + 0x1b0) == '\0')) {
          *(undefined1 *)(param_1 + 0x264) = uVar10;
          *(undefined1 *)(param_1 + 0x265) = *(undefined1 *)(lVar17 + 0x265);
          uVar10 = *(undefined1 *)(lVar17 + 0x266);
          *(undefined8 *)(param_1 + 0x268) = 0;
          *(undefined1 *)(param_1 + 0x266) = uVar10;
LAB_0046ffdc:
          uVar21 = memdescGetPhysAddr(*(undefined8 *)(*(long *)(lVar17 + 0x248) + 0x118),3,0);
          iVar12 = (**(code **)(*local_e8 + 0x50))(local_e8,uVar21);
          if (iVar12 == 0) goto LAB_0046fcbe;
          uVar21 = 0x106;
          pcVar26 = "vaspaceIncAllocRefCnt(pVASSrc, vaddr)";
          goto LAB_00470028;
        }
        goto LAB_0046fc91;
      }
      iVar12 = 0x26;
      rmGpuGroupLockRelease(local_10c,0);
    }
    else {
      rmGpuGroupLockRelease(local_10c,0);
    }
  }
  else {
    lVar20 = rmapiGetInterface(4);
    local_f0 = local_f0 & 0xffffffff00000000;
    iVar12 = serverGetClientUnderLock
                       (g_resServ,*(undefined4 *)(*(long *)(&DAT_00001b90 + lVar18) + 0xa810),
                        &local_d8);
    if (iVar12 == 0) {
      if (*(long *)(lVar16 + 0xe0) == 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)invalidInstructionException();
        (*pcVar6)();
      }
      iVar12 = vaspaceGetByHandleOrDeviceDefault_IMPL
                         (local_d8,*(undefined4 *)
                                    (*(long *)(*(long *)(*(long *)(lVar16 + 0xe0) + 0x110) + 0x48) +
                                    0x10),
                          *(undefined4 *)(*(long *)(&DAT_00001b90 + lVar18) + 0xa81c),&local_e8);
      uVar21 = 0xba;
      pcVar26 = 
      "vaspaceGetByHandleOrDeviceDefault(pFlaClient, RES_GET_HANDLE(pSrcMemory->pDevice), GPU_GET_KERNEL_BUS(pSrcGpu)->flaInfo.hFlaVASpace, &pVASSrc)"
      ;
      if (iVar12 != 0) goto LAB_00470028;
      iVar12 = deviceGetByGpu_IMPL(lVar4,lVar18,1,&local_e0,0xba);
      if (iVar12 == 0) {
        if (local_e0 == 0) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)invalidInstructionException();
          (*pcVar6)();
        }
        iVar12 = (**(code **)(lVar20 + 0x50))
                           (lVar20,*(undefined4 *)(lVar4 + 0x48),
                            *(undefined4 *)(*(long *)(*(long *)(local_e0 + 0x110) + 0x48) + 0x10),
                            &local_f0,*(undefined4 *)(*(long *)(&DAT_00001b90 + lVar18) + 0xa810),
                            *(undefined4 *)(*(long *)(&DAT_00001b90 + lVar18) + 0xa81c),0);
        uVar21 = 0xc9;
        pcVar26 = 
        "pRmApi->DupObject(pRmApi, pDstClient->hClient, RES_GET_HANDLE(pDstDevice), &hImportedVASpace, GPU_GET_KERNEL_BUS(pSrcGpu)->flaInfo.hClient, GPU_GET_KERNEL_BUS(pSrcGpu)->flaInfo.hFlaVASpace, 0)"
        ;
        if (iVar12 != 0) goto LAB_00470028;
        iVar12 = clientGetResourceRef_IMPL
                           (lVar4,local_f0 & 0xffffffff,local_d0,"src/kernel/mem_mgr/virtual_mem.c",
                            0xc9);
        if (iVar12 == 0) {
          refAddDependant(local_d0[0],*(undefined8 *)(*(long *)(param_1 + 0x230) + 0x48));
        }
        *(undefined4 *)(param_1 + 0x260) = (undefined4)local_f0;
        cVar9 = *(char *)(lVar16 + 0x1b0);
        *(undefined1 *)(param_1 + 0x264) = *(undefined1 *)(lVar17 + 0x264);
        *(undefined1 *)(param_1 + 0x265) = *(undefined1 *)(lVar17 + 0x265);
        uVar10 = *(undefined1 *)(lVar17 + 0x266);
        *(undefined8 *)(param_1 + 0x268) = 0;
        *(undefined1 *)(param_1 + 0x266) = uVar10;
        if (cVar9 == '\0') goto LAB_0046ffdc;
        goto LAB_0046fcbe;
      }
      nvAssertOkFailedNoLog
                (iVar12,"deviceGetByGpu(pDstClient, pSrcGpu, NV_TRUE, &pDstDevice)",
                 "src/kernel/mem_mgr/virtual_mem.c",199);
    }
    else {
      uVar21 = 0xb7;
      pcVar26 = 
      "serverGetClientUnderLock(&g_resServ, GPU_GET_KERNEL_BUS(pSrcGpu)->flaInfo.hClient, &pFlaClient)"
      ;
LAB_00470028:
      nvCheckOkFailedNoLog(4,iVar12,pcVar26,"src/kernel/mem_mgr/virtual_mem.c",uVar21);
    }
    rmGpuGroupLockRelease(local_10c,0);
  }
joined_r0x004708a9:
  if ((local_90[0] != 0) && (*(long *)(lVar23 + 0x118) != 0)) {
    memDestructCommon_IMPL(lVar23);
    *(undefined8 *)(lVar23 + 0x118) = 0;
  }
LAB_0046f890:
  portMemFree(0);
  portMemFree(0);
  return iVar12;
}


// ===== 004709c5 virtmemReserveMempool_IMPL.cold =====

void virtmemReserveMempool_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004709e0 virtmemReserveMempool_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong virtmemReserveMempool_IMPL
                (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  long *local_30;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  local_30 = (long *)0x0;
  if (*(int *)(param_1 + 0x260) != -1) {
    cVar1 = *(char *)(param_1 + 0x270);
    if (param_3 != 0) {
      uVar3 = vaspaceGetByHandleOrDeviceDefault_IMPL
                        (**(undefined8 **)(*(long *)(param_1 + 0x230) + 0x48),
                         *(undefined4 *)(*(long *)(*(long *)(param_3 + 0x110) + 0x48) + 0x10),
                         *(int *)(param_1 + 0x260),&local_30);
      if (uVar3 == 0) {
        uVar4 = (**(code **)(*local_30 + 0x88))
                          (local_30,param_2,param_3,param_4,param_5,cVar1 != '\0');
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar3,
                   "vaspaceGetByHandleOrDeviceDefault(pClient, RES_GET_HANDLE(pDevice), pVirtualMemory->hVASpace, &pVAS)"
                   ,"src/kernel/mem_mgr/virtual_mem.c",0x3b0,param_5);
        uVar4 = (ulong)uVar3;
      }
      return uVar4;
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  return 0x31;
}


// ===== 00470ae6 virtmemMatchesVASpace_IMPL.cold =====

void virtmemMatchesVASpace_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00470af0 virtmemMatchesVASpace_IMPL =====

bool virtmemMatchesVASpace_IMPL(long param_1,int param_2,int param_3)

{
  code *pcVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (*(int *)(**(long **)(*(long *)(param_1 + 0x230) + 0x48) + 0x48) != param_2) {
    return false;
  }
  return *(int *)(param_1 + 0x260) == param_3;
}


// ===== 00470b22 virtmemMapTo_IMPL.cold =====

void virtmemMapTo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00470b30 virtmemMapTo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int virtmemMapTo_IMPL(long param_1,long *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 *puVar10;
  code *pcVar11;
  bool bVar12;
  long lVar13;
  long lVar14;
  undefined8 *puVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined1 uVar19;
  char cVar20;
  int iVar21;
  uint uVar22;
  undefined4 uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  long lVar27;
  undefined8 uVar28;
  undefined8 *puVar29;
  long lVar30;
  undefined8 uVar31;
  long lVar32;
  undefined8 *extraout_RDX;
  undefined8 *extraout_RDX_00;
  bool bVar33;
  bool bVar34;
  bool bVar35;
  undefined4 local_120;
  int local_118;
  char local_ed;
  long local_b8;
  long *local_a8;
  undefined8 *local_90;
  long local_88;
  long local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  uint local_60;
  uint uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 *local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar11 = (code *)invalidInstructionException();
    (*pcVar11)();
  }
  lVar3 = *param_2;
  lVar30 = param_2[4];
  lVar4 = *(long *)(param_1 + 0x248);
  lVar32 = param_2[1];
  lVar5 = *(long *)(lVar3 + 0x1b78);
  plVar6 = *(long **)(*(long *)(param_1 + 0x230) + 0x48);
  lVar7 = *plVar6;
  lVar13 = plVar6[2];
  uVar1 = *(undefined4 *)(lVar7 + 0x48);
  uVar2 = (undefined4)param_2[6];
  lVar14 = param_2[5];
  local_b8 = param_2[7];
  lVar8 = *(long *)(lVar3 + 0x1bb8);
  local_90 = (undefined8 *)0x0;
  lVar9 = param_2[8];
  puVar10 = (undefined8 *)param_2[0xb];
  uVar25 = *(uint *)(param_2 + 9);
  uVar23 = *(undefined4 *)((long)param_2 + 0x4c);
  local_a8 = (long *)param_2[2];
  local_88 = 0;
  lVar27 = __nvoc_dynamicCast(*(undefined8 *)(lVar30 + 8),__nvoc_class_def_Memory);
  local_ed = *(char *)((long)param_2 + 0x61);
  if ((uVar25 & 0x300000) == 0) {
    bVar33 = false;
  }
  else {
    cVar20 = (**(code **)(*(long *)(&DAT_00001b90 + lVar3) + 0x350))
                       (lVar3,*(long *)(&DAT_00001b90 + lVar3),lVar32,
                        *(undefined8 *)(&DAT_00001b90 + lVar32));
    bVar33 = cVar20 != '\0';
  }
  if (((char)param_2[0xc] != '\0') && (*(char *)(param_1 + 0x264) == '\0')) {
    nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x4c8,"virtmemMapTo_IMPL",4,
                 "NVRM: Unicast mappings into virtual memory object not supported.\n");
    return 0x56;
  }
  iVar21 = vaspaceGetByHandleOrDeviceDefault_IMPL
                     (lVar7,(int)lVar14,*(undefined4 *)(param_1 + 0x260),&local_88);
  if (iVar21 != 0) {
    return iVar21;
  }
  uVar19 = memdescGetFlag(*(undefined8 *)(lVar4 + 0x118),0x800);
  if ((ulong)local_a8[6] < (ulong)(local_b8 + lVar9)) {
    return 0x20;
  }
  iVar21 = intermapCreateDmaMapping(lVar7,param_1,&local_90,uVar25,uVar23);
  uVar18 = uStack_44;
  uVar23 = local_48;
  if (iVar21 != 0) {
    return iVar21;
  }
  uVar22 = uVar25 & 0x20;
  local_48 = (undefined4)lVar9;
  uVar16 = local_48;
  uStack_44 = (undefined4)((ulong)lVar9 >> 0x20);
  uVar17 = uStack_44;
  if (bVar33) {
    uStack_5c = 0;
    local_68 = 0;
    uStack_64 = 0;
    local_80 = local_88;
    local_58 = (undefined4)local_b8;
    uStack_54 = (undefined4)((ulong)local_b8 >> 0x20);
    local_70 = SUB84(local_a8,0);
    uStack_6c = (undefined4)((ulong)local_a8 >> 0x20);
    local_50 = 0;
    uStack_4c = 0;
    local_78 = (undefined4)lVar32;
    uStack_74 = (undefined4)((ulong)lVar32 >> 0x20);
    local_40 = local_90;
    local_60 = uVar25;
    iVar21 = (**(code **)(lVar8 + 0x178))(lVar3,lVar8,&local_80);
    if (iVar21 == 0) {
      local_a8 = (long *)CONCAT44(uStack_64,local_68);
      local_b8 = CONCAT44(uStack_4c,local_50);
      uVar23 = local_48;
      uVar18 = uStack_44;
      uVar25 = uStack_5c;
      goto LAB_00470ddb;
    }
    bVar35 = false;
    cVar20 = '\0';
LAB_00471240:
    if (local_90 == (undefined8 *)0x0) {
      return iVar21;
    }
    lVar30 = local_90[0x1a];
    bVar33 = lVar30 != 0;
    if ((uVar22 != 0) && (bVar33)) goto LAB_0047126e;
  }
  else {
LAB_00470ddb:
    uStack_44 = uVar18;
    local_48 = uVar23;
    uVar28 = memdescGetMemDescFromGpu(local_a8,lVar3);
    local_118 = memdescGetAddressSpace(uVar28);
    if ((lVar3 == lVar32) || (local_118 != 2)) {
      bVar35 = false;
    }
    else {
      cVar20 = gpumgrCheckIndirectPeer_IMPL(lVar3,lVar32);
      local_118 = 1;
      bVar35 = cVar20 != '\0';
    }
    iVar21 = memdescCreateSubMem(local_90 + 0x1a,local_a8,lVar3,local_b8,lVar9);
    cVar20 = '\0';
    if (iVar21 != 0) goto LAB_00471240;
    uVar28 = memdescGetMemDescFromGpu(local_90[0x1a],lVar3);
    memdescSetFlag(uVar28,0x800,uVar19);
    if (((uVar25 & 0x40000000) != 0) && (*local_a8 != 0)) {
      uVar23 = memdescGetPteKindForGpu();
      cVar20 = (**(code **)(lVar5 + 600))(lVar5,uVar23);
      if (cVar20 != '\0') {
        memdescSetFlag(local_a8,0x10000000000000,1);
      }
    }
    if ((uVar25 & 0x80000) != 0) {
      if ((uVar25 & 8) == 0) {
        cVar20 = (**(code **)(lVar5 + 0x2a8))(lVar5,9,(int)param_2[10]);
        local_120 = (undefined4)param_2[10];
        if (cVar20 != '\0') goto LAB_00470f49;
        nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x527,"virtmemMapTo_IMPL",4,
                     "NVRM: PTE kind override of %d is not supported\n",local_120);
        iVar21 = 0x1f;
        cVar20 = '\0';
      }
      else {
        nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x51e,"virtmemMapTo_IMPL",4,
                     "NVRM: FLAGS_PAGE_KIND_VIRTUAL and FLAGS_PAGE_KIND_OVERRIDE_YES cannot both be set\n"
                    );
        iVar21 = 0x1f;
        cVar20 = '\0';
      }
      goto LAB_00471240;
    }
    bVar12 = false;
    if ((uVar25 & 8) != 0) {
      cVar20 = memdescGetFlag(*(undefined8 *)(lVar4 + 0x118),2);
      if (cVar20 == '\0') {
        nvAssertFailedNoLog("memdescGetFlag(pMemory->pMemDesc, MEMDESC_FLAGS_SET_KIND)",
                            "src/kernel/mem_mgr/virtual_mem.c",0x531);
      }
      local_120 = memdescGetPteKindForGpu
                            (*(undefined8 **)(lVar4 + 0x118),**(undefined8 **)(lVar4 + 0x118));
LAB_00470f49:
      cVar20 = memdescGetFlag(local_a8,0x10000000000000);
      if ((cVar20 != '\0') && (cVar20 = (**(code **)(lVar5 + 600))(lVar5,local_120), cVar20 == '\0')
         ) {
        uVar23 = memdescGetPteKindForGpu(local_a8,*local_a8);
        uVar19 = (**(code **)(lVar5 + 0x2a8))(lVar5,10,uVar23);
        local_120 = (**(code **)(lVar5 + 0x298))(lVar5,local_120,uVar19);
      }
      uVar23 = local_120;
      if ((local_118 == 1) && (cVar20 = memmgrComprSupported_IMPL(lVar5,1), cVar20 == '\0')) {
        uVar23 = (**(code **)(lVar5 + 0x290))(lVar3,lVar5,local_120,0);
      }
      puVar29 = (undefined8 *)memdescGetMemDescFromGpu(local_90[0x1a],lVar3);
      memdescSetPteKindForGpu(puVar29,*puVar29,uVar23);
      bVar12 = true;
    }
    if ((local_118 - 6U < 2) || (local_118 == 1)) {
      if ((bVar35) &&
         (iVar21 = memdescMapIommu(local_90[0x1a],*(undefined4 *)(lVar3 + 0x868)), iVar21 != 0)) {
        nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x566,"virtmemMapTo_IMPL",4,
                     "NVRM: DMA map pages failed for requested GPU!\n");
        cVar20 = '\0';
        goto LAB_00471240;
      }
      if ((*(char *)(lVar4 + 0x1b0) == '\0') || (*(char *)(lVar3 + 0x4922) != '\0')) {
        *local_90 = *puVar10;
        iVar21 = dmaAllocMap_IMPL(lVar3,lVar8,local_88,param_1,lVar27,local_90);
        if (iVar21 == 0) {
          iVar21 = intermapRegisterDmaMapping(lVar7,param_1,local_90,*local_90,uVar2);
          puVar15 = local_90;
          if (iVar21 == 0) {
            if (uVar22 != 0) {
              uVar28 = gpumgrGetParentGPU(lVar3);
              uVar26 = gpumgrGetSubDeviceInstanceFromGpu(uVar28);
              puVar29 = puVar15 + 9;
              iVar21 = memdescMapOld(local_90[0x1a],0,*(undefined8 *)(local_90[0x1a] + 0x30),1,3,
                                     puVar15 + (ulong)uVar26 + 1);
              if (iVar21 != 0) goto joined_r0x00471608;
            }
LAB_004710d0:
            bVar34 = local_ed == '\0';
            local_ed = '\x01';
            *puVar10 = *local_90;
            if (bVar34) goto LAB_004710ed;
            goto LAB_0047111c;
          }
LAB_004719f0:
          dmaFreeMap_IMPL(lVar3,lVar8,local_88,param_1,local_90,0);
          cVar20 = '\0';
        }
        else {
LAB_00471670:
          cVar20 = '\0';
        }
      }
      else {
LAB_004714f8:
        if (local_ed == '\0') {
LAB_004710ed:
          if ((bVar33) || ((*(uint *)(local_90 + 0x1b) & 0x300000) == 0x200000)) {
            *(undefined1 *)(local_90 + 0x1c) = 1;
          }
LAB_0047111c:
          if (*(char *)(lVar4 + 0x1b0) == '\0') {
            return 0;
          }
        }
        else {
          local_ed = '\0';
        }
        uStack_54 = 0;
        local_48 = 0;
        uStack_5c = 0;
        local_58 = 0;
        uStack_44 = 0;
        uStack_74 = *(undefined4 *)(lVar30 + 0x10);
        local_80 = CONCAT44((int)lVar14,uVar1);
        local_70 = (undefined4)local_b8;
        uStack_6c = (undefined4)((ulong)local_b8 >> 0x20);
        local_50 = (undefined4)*puVar10;
        uStack_4c = (undefined4)((ulong)*puVar10 >> 0x20);
        if (bVar12) {
          local_58 = local_120;
        }
        local_78 = (int)lVar13;
        local_68 = uVar16;
        uStack_64 = uVar17;
        local_60 = uVar25;
        lVar30 = gpuGetRpc(lVar3);
        cVar20 = local_ed;
        if (lVar30 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/virtual_mem.c",0x5e0);
          iVar21 = 0x1a;
        }
        else if ((*(char *)(lVar3 + 0x4922) != '\0') ||
                (iVar21 = (**(code **)(lVar30 + 0x4a0))
                                    (lVar3,lVar30,&local_80,*(code **)(lVar30 + 0x4a0)), iVar21 == 0
                )) {
          *puVar10 = CONCAT44(uStack_4c,local_50);
          if ((*(char *)(lVar3 + 0x908) == '\0') && (*(char *)(lVar3 + 0x909) == '\0')) {
            return 0;
          }
          if (*(char *)(lVar3 + 0x4922) != '\0') {
            return 0;
          }
          *local_90 = CONCAT44(uStack_4c,local_50);
          lVar30 = param_1;
          iVar21 = intermapRegisterDmaMapping(lVar7,param_1,local_90,*local_90,uVar2);
          puVar29 = local_90;
          if (iVar21 == 0) {
            if (uVar22 == 0) {
              return 0;
            }
            if (local_118 != 1) {
              return 0;
            }
            uVar28 = gpumgrGetParentGPU(lVar3);
            uVar25 = gpumgrGetSubDeviceInstanceFromGpu(uVar28);
            iVar21 = memdescMapOld(local_90[0x1a],0,*(undefined8 *)(local_90[0x1a] + 0x30),1,3,
                                   puVar29 + (ulong)uVar25 + 1,puVar29 + 9,lVar30);
            if (iVar21 == 0) {
              return 0;
            }
            if (local_90 == (undefined8 *)0x0) {
              return iVar21;
            }
            lVar30 = local_90[0x1a];
            puVar29 = extraout_RDX;
            goto joined_r0x00471862;
          }
        }
      }
      goto LAB_00471240;
    }
    if (local_118 != 2) {
      iVar21 = 0x33;
      cVar20 = '\0';
      goto LAB_00471240;
    }
    *local_90 = *puVar10;
    if ((*(char *)(lVar4 + 0x1b0) != '\0') && (*(char *)(lVar3 + 0x4922) == '\0'))
    goto LAB_004714f8;
    puVar29 = local_90;
    iVar21 = dmaAllocMap_IMPL(lVar3,lVar8,local_88,param_1,lVar27);
    if (iVar21 != 0) goto LAB_00471670;
    *puVar10 = *local_90;
    iVar21 = intermapRegisterDmaMapping(lVar7,param_1,local_90,*local_90,uVar2);
    puVar15 = local_90;
    if (iVar21 != 0) goto LAB_004719f0;
    if (uVar22 == 0) goto LAB_004710d0;
    cVar20 = *(char *)(lVar3 + 0x454);
    uVar26 = gpumgrGetSubDeviceInstanceFromGpu(lVar3);
    if (cVar20 == '\0') {
      puVar15[(ulong)uVar26 + 0x12] = *(undefined8 *)(puVar15[0x1a] + 0x30);
      uVar28 = *(undefined8 *)(&DAT_00001b90 + lVar3);
      lVar32 = resservGetTlsCallContext();
      if ((lVar32 != 0) && (*(long *)(lVar32 + 8) != 0)) {
        local_80 = 0;
        iVar21 = refFindAncestorOfType(*(undefined8 *)(lVar32 + 0x10),&DAT_00e0ac20,&local_80);
        if (iVar21 == 0) {
          __nvoc_dynamicCast(*(undefined8 *)(local_80 + 8),__nvoc_class_def_Device);
        }
      }
      iVar21 = kbusMapFbApertureSingle_IMPL
                         (lVar3,uVar28,*(undefined8 *)(lVar27 + 0x118),local_b8,
                          puVar15 + (ulong)uVar26 + 10,puVar15 + (ulong)uVar26 + 0x12);
      if (iVar21 == 0) {
        lVar32 = gpumgrGetGpuPhysFbAddr(lVar3);
        iVar21 = osMapPciMemoryKernelOld
                           (lVar3,lVar32 + puVar15[(ulong)uVar26 + 10],
                            *(undefined8 *)(puVar15[0x1a] + 0x30),3,puVar15 + (ulong)uVar26 + 1,2);
        goto LAB_00471b48;
      }
      puVar15[(ulong)uVar26 + 0x12] = 0;
      puVar15[(ulong)uVar26 + 10] = 0;
    }
    else {
      uVar28 = memdescGetMemDescFromGpu(puVar15[0x1a],lVar3);
      lVar32 = *(long *)(&DAT_00001b90 + lVar3);
      nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x3f8,"_virtmemAllocKernelMapping",1,
                   "NVRM: Allocating coherent link mapping. length=%lld, memDesc->size=%lld\n",lVar9
                   ,*(undefined8 *)(puVar15[0x1a] + 0x30),puVar29);
      if (*(char *)(lVar3 + 0x45b) == '\0') {
        nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                            "src/kernel/mem_mgr/virtual_mem.c",0x3fc);
      }
      iVar21 = (**(code **)(lVar32 + 0x518))
                         (lVar3,lVar32,uVar28,local_b8,lVar9,3,puVar15 + (ulong)uVar26 + 1,
                          puVar15 + 9);
LAB_00471b48:
      if (iVar21 == 0) goto LAB_004710d0;
    }
    _virtmemFreeKernelMapping(lVar3,puVar15);
    puVar29 = extraout_RDX_00;
joined_r0x00471608:
    if (local_90 == (undefined8 *)0x0) {
      return iVar21;
    }
    lVar30 = local_90[0x1a];
joined_r0x00471862:
    cVar20 = '\x01';
    if (lVar30 == 0) {
      (**(code **)(lVar8 + 0x180))(lVar8,local_90,puVar29);
      memdescDestroy(local_90[0x1a]);
      local_90[0x1a] = 0;
      goto LAB_0047132f;
    }
LAB_0047126e:
    if ((local_90[9] == 0) || (iVar24 = memdescGetAddressSpace(), puVar29 = local_90, iVar24 != 1))
    {
      iVar24 = memdescGetAddressSpace(local_90[0x1a]);
      if (iVar24 == 2) {
        _virtmemFreeKernelMapping(lVar3);
        lVar30 = local_90[0x1a];
        bVar33 = lVar30 != 0;
      }
      else {
        lVar30 = local_90[0x1a];
        bVar33 = lVar30 != 0;
      }
    }
    else {
      uVar28 = local_90[9];
      uVar31 = gpumgrGetParentGPU(lVar3);
      uVar25 = gpumgrGetSubDeviceInstanceFromGpu(uVar31);
      memdescUnmapOld(local_90[0x1a],1,puVar29[(ulong)uVar25 + 1],uVar28);
      lVar30 = local_90[0x1a];
      local_90[9] = 0;
      bVar33 = lVar30 != 0;
    }
  }
  if ((bVar35) && (bVar33)) {
    memdescUnmapIommu(lVar30,*(undefined4 *)(lVar3 + 0x868));
  }
  (**(code **)(lVar8 + 0x180))(lVar8,local_90);
  memdescDestroy(local_90[0x1a]);
  local_90[0x1a] = 0;
  if (cVar20 == '\0') {
    intermapFreeDmaMapping();
    return iVar21;
  }
LAB_0047132f:
  iVar24 = intermapDelDmaMapping(lVar7,param_1,*puVar10,uVar2);
  if (iVar24 != 0) {
    nvAssertOkFailedNoLog
              (iVar24,"intermapDelDmaMapping(pClient, pVirtualMemory, *pDmaOffset, gpuMask)",
               "src/kernel/mem_mgr/virtual_mem.c",0x632);
  }
  return iVar21;
}


// ===== 00471d48 virtmemUnmapFrom_IMPL.cold =====

void virtmemUnmapFrom_IMPL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00471d60 virtmemUnmapFrom_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Type propagation algorithm not settling */

int virtmemUnmapFrom_IMPL(long param_1,long *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  ulong *puVar14;
  long *plVar15;
  long lVar16;
  ulong uVar17;
  undefined8 uVar18;
  long lVar19;
  long lVar20;
  char *pcVar21;
  ulong uVar22;
  bool bVar23;
  undefined8 local_88;
  ulong *local_80;
  long *local_78;
  ulong *local_70;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar6 = *param_2;
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)invalidInstructionException();
    (*pcVar9)();
  }
  lVar19 = *(long *)(param_1 + 0x248);
  bVar23 = false;
  iVar1 = (int)param_2[1];
  plVar15 = *(long **)(*(long *)(param_1 + 0x230) + 0x48);
  lVar7 = *plVar15;
  iVar2 = (int)plVar15[2];
  local_88 = 0;
  local_80 = (ulong *)0x0;
  uVar3 = *(undefined4 *)((long)param_2 + 0xc);
  uVar4 = *(undefined4 *)(lVar7 + 0x48);
  local_78 = (long *)0x0;
  uVar5 = *(uint *)(param_2 + 2);
  uVar8 = param_2[3];
  local_70 = (ulong *)0x0;
  if (iVar1 != 0) {
    iVar11 = clientGetResourceRef_IMPL(lVar7,iVar1,&local_68);
    if (iVar11 != 0) {
      return 0x57;
    }
    lVar16 = param_2[6];
    plVar15 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_68 + 8),__nvoc_class_def_RmResource);
    iVar11 = (**(code **)(*plVar15 + 0x108))(plVar15,(char)lVar16,*(code **)(*plVar15 + 0x108));
    if (iVar11 != 0) {
      return iVar11;
    }
    lVar16 = __nvoc_dynamicCast(*(undefined8 *)(local_68 + 8),__nvoc_class_def_Memory);
    if (lVar16 != 0) {
      cVar10 = gpumgrCheckIndirectPeer_IMPL(*(undefined8 *)(lVar16 + 0xf0),lVar6);
      bVar23 = cVar10 != '\0';
    }
  }
  if (((char)param_2[6] != '\0') && (*(char *)(param_1 + 0x264) == '\0')) {
    nvDbg_Printf("src/kernel/mem_mgr/virtual_mem.c",0x675,"virtmemUnmapFrom_IMPL",4,
                 "NVRM: Unicast DMA mappings into virtual memory object not supported.\n");
    return 0x56;
  }
  iVar11 = vaspaceGetByHandleOrDeviceDefault_IMPL
                     (lVar7,uVar3,*(undefined4 *)(param_1 + 0x260),&local_88);
  if (iVar11 != 0) {
    return iVar11;
  }
  puVar14 = (ulong *)intermapGetDmaMapping(param_1,uVar8,uVar5);
  if (puVar14 == (ulong *)0x0) {
    nvAssertFailedNoLog("pDmaMappingInfo != NULL","src/kernel/mem_mgr/virtual_mem.c",0x67f);
    return 0x33;
  }
  uVar17 = *puVar14;
  if (uVar17 == uVar8) {
    uVar22 = puVar14[0x1a];
    lVar16 = param_2[4];
    lVar20 = *(long *)(uVar22 + 0x30);
    if (lVar16 != lVar20) goto LAB_00471ea5;
    if ((puVar14[0x1b] & 0x20) != 0) {
      if (puVar14[9] == 0) {
LAB_004725fc:
        uVar18 = memdescGetMemDescFromGpu(uVar22,lVar6);
        iVar11 = memdescGetAddressSpace(uVar18);
        if (iVar11 == 2) {
          _virtmemFreeKernelMapping(lVar6,puVar14);
          cVar10 = (char)puVar14[0x1c];
        }
        else {
          cVar10 = (char)puVar14[0x1c];
        }
      }
      else {
        iVar11 = memdescGetAddressSpace();
        if (iVar11 != 1) {
          uVar22 = puVar14[0x1a];
          goto LAB_004725fc;
        }
        uVar17 = puVar14[9];
        uVar18 = gpumgrGetParentGPU(lVar6);
        uVar13 = gpumgrGetSubDeviceInstanceFromGpu(uVar18);
        memdescUnmapOld(puVar14[0x1a],1,puVar14[(ulong)uVar13 + 1],uVar17);
        puVar14[9] = 0;
        cVar10 = (char)puVar14[0x1c];
      }
      if (cVar10 != '\0') goto LAB_00472010;
LAB_0047202d:
      uVar17 = *puVar14;
      goto LAB_00472030;
    }
    if ((char)puVar14[0x1c] != '\0') {
LAB_00472010:
      (**(code **)(*(long *)(lVar6 + 0x1bb8) + 0x180))(*(long *)(lVar6 + 0x1bb8),puVar14);
      goto LAB_0047202d;
    }
LAB_0047204c:
    if (lVar16 + uVar8 < lVar20 + uVar17) {
      iVar11 = intermapCreateDmaMapping
                         (lVar7,param_1,&local_78,(int)puVar14[0x1b],
                          *(undefined4 *)((long)puVar14 + 0xdc));
      uVar18 = 0x6b5;
      pcVar21 = 
      "intermapCreateDmaMapping(pClient, pVirtualMemory, &pDmaMappingInfoRight, pDmaMappingInfo->Flags, pDmaMappingInfo->Flags2)"
      ;
      if (iVar11 == 0) {
        *local_78 = uVar8 + param_2[4];
        *(char *)(local_78 + 0x1c) = (char)puVar14[0x1c];
        local_78[0x1f] = puVar14[0x1f];
        local_78[0x1d] = puVar14[0x1d];
        iVar11 = memdescCreateSubMem(local_78 + 0x1a,puVar14[0x1a],lVar6,*local_78 - *puVar14,
                                     (*puVar14 - *local_78) + *(long *)(puVar14[0x1a] + 0x30));
        uVar18 = 0x6be;
        pcVar21 = 
        "memdescCreateSubMem(&pDmaMappingInfoRight->pMemDesc, pDmaMappingInfo->pMemDesc, pGpu, pDmaMappingInfoRight->DmaOffset - pDmaMappingInfo->DmaOffset, pDmaMappingInfo->DmaOffset + pDmaMappingInfo->pMemDesc->Size - pDmaMappingInfoRight->DmaOffset)"
        ;
        if (iVar11 == 0) goto LAB_0047205f;
      }
LAB_00472420:
      nvAssertOkFailedNoLog(iVar11,pcVar21,"src/kernel/mem_mgr/virtual_mem.c",uVar18);
      if ((local_70 == (ulong *)0x0) || (bVar23 = false, puVar14 == local_70)) goto LAB_0047266d;
      goto LAB_0047244e;
    }
LAB_0047205f:
    local_70 = puVar14;
    if ((local_80 != (ulong *)0x0) || (local_78 != (long *)0x0)) {
      iVar11 = intermapCreateDmaMapping
                         (lVar7,param_1,&local_70,(int)puVar14[0x1b],
                          *(undefined4 *)((long)puVar14 + 0xdc));
      if (iVar11 != 0) {
        uVar18 = 0x6c8;
        pcVar21 = 
        "intermapCreateDmaMapping(pClient, pVirtualMemory, &pDmaMappingInfoUnmap, pDmaMappingInfo->Flags, pDmaMappingInfo->Flags2)"
        ;
        goto LAB_00472420;
      }
      *local_70 = uVar8;
      *(char *)(local_70 + 0x1c) = (char)puVar14[0x1c];
      local_70[0x1f] = puVar14[0x1f];
      local_70[0x1d] = puVar14[0x1d];
      *(undefined4 *)((long)local_70 + 0xe4) = *(undefined4 *)((long)puVar14 + 0xe4);
      iVar11 = memdescCreateSubMem(local_70 + 0x1a,puVar14[0x1a],lVar6,*local_70 - *puVar14,
                                   param_2[4]);
      if (iVar11 != 0) {
        uVar18 = 0x6d2;
        pcVar21 = 
        "memdescCreateSubMem(&pDmaMappingInfoUnmap->pMemDesc, pDmaMappingInfo->pMemDesc, pGpu, pDmaMappingInfoUnmap->DmaOffset - pDmaMappingInfo->DmaOffset, pParams->size)"
        ;
        goto LAB_00472643;
      }
    }
    if ((*(char *)(lVar19 + 0x1b0) == '\0') || (*(char *)(lVar6 + 0x4922) != '\0')) {
      dmaFreeMap_IMPL(lVar6,*(undefined8 *)(lVar6 + 0x1bb8),local_88,param_1,local_70,
                      *(undefined4 *)((long)param_2 + 0x14));
      uVar18 = memdescGetMemDescFromGpu(puVar14[0x1a],lVar6);
      iVar11 = memdescGetAddressSpace(uVar18);
      if ((iVar11 == 2) && (bVar23)) {
        memdescUnmapIommu(puVar14[0x1a],*(undefined4 *)(lVar6 + 0x868));
      }
    }
    memdescFree(puVar14[0x1a]);
    memdescDestroy(puVar14[0x1a]);
    puVar14[0x1a] = 0;
    intermapDelDmaMapping(lVar7,param_1,*puVar14,uVar5);
    if (local_80 == (ulong *)0x0) {
      bVar23 = false;
    }
    else {
      bVar23 = true;
      iVar11 = intermapRegisterDmaMapping(lVar7,param_1,local_80,*local_80,uVar5);
      if (iVar11 != 0) {
        nvAssertOkFailedNoLog
                  (iVar11,
                   "intermapRegisterDmaMapping(pClient, pVirtualMemory, pDmaMappingInfoLeft, pDmaMappingInfoLeft->DmaOffset, gpuMask)"
                   ,"src/kernel/mem_mgr/virtual_mem.c",0x6ef);
        goto joined_r0x0047265d;
      }
    }
    iVar11 = 0;
    if (local_78 == (long *)0x0) {
      if ((local_70 == puVar14) || (local_70 == (ulong *)0x0)) goto LAB_00472233;
    }
    else {
      iVar12 = intermapRegisterDmaMapping(lVar7,param_1,local_78,*local_78,uVar5);
      if (iVar12 != 0) {
        nvAssertOkFailedNoLog
                  (iVar12,
                   "intermapRegisterDmaMapping(pClient, pVirtualMemory, pDmaMappingInfoRight, pDmaMappingInfoRight->DmaOffset, gpuMask)"
                   ,"src/kernel/mem_mgr/virtual_mem.c",0x6f8);
        iVar11 = iVar12;
        if ((local_70 != puVar14) && (local_70 != (ulong *)0x0)) goto LAB_0047244e;
        goto LAB_00472473;
      }
      if ((local_70 == puVar14) || (local_70 == (ulong *)0x0)) {
        iVar11 = 0;
        goto LAB_00472233;
      }
    }
    memdescFree(local_70[0x1a]);
    memdescDestroy(local_70[0x1a]);
    intermapFreeDmaMapping(local_70);
    goto LAB_00472233;
  }
LAB_00471ea5:
  if ((uVar5 & uVar5 - 1) != 0) {
    nvAssertFailedNoLog("!bPartialUnmap || (gpuMask & (gpuMask - 1)) == 0",
                        "src/kernel/mem_mgr/virtual_mem.c",0x681);
    return 0x1f;
  }
  if (bVar23) {
    nvAssertFailedNoLog("!bPartialUnmap || !bIsIndirectPeer","src/kernel/mem_mgr/virtual_mem.c",
                        0x682);
    return 0x1f;
  }
  if ((puVar14[0x1b] & 0x20) != 0) {
    nvAssertFailedNoLog("!bPartialUnmap","src/kernel/mem_mgr/virtual_mem.c",0x686);
    return 0x1f;
  }
  if ((char)puVar14[0x1c] != '\0') {
    nvAssertFailedNoLog("!bPartialUnmap","src/kernel/mem_mgr/virtual_mem.c",0x69d);
    return 0x1f;
  }
LAB_00472030:
  if (uVar8 <= uVar17) {
    lVar16 = param_2[4];
    lVar20 = *(long *)(puVar14[0x1a] + 0x30);
    goto LAB_0047204c;
  }
  iVar11 = intermapCreateDmaMapping
                     (lVar7,param_1,&local_80,(int)puVar14[0x1b],
                      *(undefined4 *)((long)puVar14 + 0xdc));
  uVar18 = 0x6a3;
  pcVar21 = 
  "intermapCreateDmaMapping(pClient, pVirtualMemory, &pDmaMappingInfoLeft, pDmaMappingInfo->Flags, pDmaMappingInfo->Flags2)"
  ;
  if (iVar11 == 0) {
    *local_80 = *puVar14;
    *(char *)(local_80 + 0x1c) = (char)puVar14[0x1c];
    local_80[0x1f] = puVar14[0x1f];
    local_80[0x1d] = puVar14[0x1d];
    iVar11 = memdescCreateSubMem(local_80 + 0x1a,puVar14[0x1a],lVar6,*local_80 - *puVar14,
                                 uVar8 - *local_80);
    if (iVar11 == 0) {
      lVar16 = param_2[4];
      uVar17 = *puVar14;
      lVar20 = *(long *)(puVar14[0x1a] + 0x30);
      goto LAB_0047204c;
    }
    uVar18 = 0x6ac;
    pcVar21 = 
    "memdescCreateSubMem(&pDmaMappingInfoLeft->pMemDesc, pDmaMappingInfo->pMemDesc, pGpu, pDmaMappingInfoLeft->DmaOffset - pDmaMappingInfo->DmaOffset, dmaOffset - pDmaMappingInfoLeft->DmaOffset)"
    ;
    goto LAB_00472420;
  }
LAB_00472643:
  nvAssertOkFailedNoLog(iVar11,pcVar21,"src/kernel/mem_mgr/virtual_mem.c",uVar18);
joined_r0x0047265d:
  if ((puVar14 == local_70) || (bVar23 = false, local_70 == (ulong *)0x0)) {
LAB_0047266d:
    if (local_80 != (ulong *)0x0) {
      memdescFree(local_80[0x1a]);
      memdescDestroy(local_80[0x1a]);
LAB_00472699:
      intermapFreeDmaMapping(local_80);
    }
  }
  else {
LAB_0047244e:
    memdescFree(local_70[0x1a]);
    memdescDestroy(local_70[0x1a]);
    intermapFreeDmaMapping(local_70);
LAB_00472473:
    if (local_80 != (ulong *)0x0) {
      memdescFree(local_80[0x1a]);
      memdescDestroy(local_80[0x1a]);
      if (!bVar23) goto LAB_00472699;
      intermapDelDmaMapping(lVar7,param_1,*local_80,uVar5);
    }
  }
  if (local_78 != (long *)0x0) {
    memdescFree(local_78[0x1a]);
    memdescDestroy(local_78[0x1a]);
    intermapFreeDmaMapping(local_78);
  }
LAB_00472233:
  if (((*(char *)(lVar19 + 0x1b0) != '\0') && (iVar1 != 0)) &&
     ((iVar12 = (**(code **)(**(long **)(param_1 + 0x230) + 0xa0))(), iVar12 != 0 ||
      (iVar1 == iVar2)))) {
    local_58 = 0;
    local_48 = 0;
    local_40 = 0;
    local_68 = CONCAT44(uVar3,uVar4);
    local_60 = CONCAT44(iVar1,iVar2);
    local_50 = uVar8;
    lVar19 = gpuGetRpc(lVar6);
    if (lVar19 == 0) {
      iVar11 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/mem_mgr/virtual_mem.c",0x743);
    }
    else if ((iVar11 == 0) && (*(char *)(lVar6 + 0x4922) == '\0')) {
      iVar11 = (**(code **)(lVar19 + 0x4b8))(lVar6,lVar19,&local_68,*(code **)(lVar19 + 0x4b8));
    }
  }
  return iVar11;
}


// ===== 00472898 virtmemGetAddressAndSize_IMPL.cold =====

void virtmemGetAddressAndSize_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004728b0 virtmemGetAddressAndSize_IMPL =====

void virtmemGetAddressAndSize_IMPL(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x248) + 0x118);
    uVar3 = memdescGetPhysAddr(lVar1,3,0);
    *param_2 = uVar3;
    *param_3 = *(undefined8 *)(lVar1 + 0x30);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 00472910 nvErrorLog2 =====

void nvErrorLog2(long param_1,ulong param_2,undefined8 param_3,char param_4,char *param_5,
                undefined8 *param_6)

{
  int iVar1;
  long lVar2;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if ((param_5 != (char *)0x0) && (*param_5 != '\0')) {
    lVar2 = portMemAllocNonPaged(0x200);
    if (lVar2 != 0) {
      local_50 = *param_6;
      local_48 = param_6[1];
      local_40 = param_6[2];
      iVar1 = nvDbgVsnprintf(lVar2,0x200,param_5,&local_50);
      if (iVar1 != 0) {
        if ((param_1 != 0) && (param_4 != '\0')) {
          gpuLogOobXidMessage_KERNEL(param_1,param_2 & 0xffffffff,lVar2,iVar1);
        }
        if (*(long *)(param_1 + 0x1c18) != 0) {
          krcReportXid_IMPL(param_1,*(long *)(param_1 + 0x1c18),param_2,param_3);
        }
      }
    }
    portMemFree(lVar2);
    osErrorLogV(param_1,param_2,param_3,param_5,param_6);
    return;
  }
  return;
}


// ===== 00472a00 constructObjOS =====

undefined8 constructObjOS(void)

{
  osInitObjOS();
  return 0;
}


// ===== 00472a20 osGetMaximumCoreCount =====

undefined4 osGetMaximumCoreCount(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (g_pSys != 0) {
    uVar1 = *(undefined4 *)(g_pSys + 0xe0);
  }
  return uVar1;
}


// ===== 00472a40 osGpuWriteReg032 =====

void osGpuWriteReg032(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  uVar1 = gpuGetDeviceMapping_IMPL(param_1,0,0);
  osDevWriteReg032(param_1,uVar1,param_2,param_3);
  return;
}


// ===== 00472a80 osGpuReadReg008 =====

void osGpuReadReg008(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = gpuGetDeviceMapping_IMPL(param_1,0,0);
  osDevReadReg008(param_1,uVar1,param_2);
  return;
}


// ===== 00472ab0 osGpuReadReg016 =====

void osGpuReadReg016(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = gpuGetDeviceMapping_IMPL(param_1,0,0);
  osDevReadReg016(param_1,uVar1,param_2);
  return;
}


// ===== 00472ae0 osGpuReadReg032 =====

void osGpuReadReg032(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = gpuGetDeviceMapping_IMPL(param_1,0,0);
  osDevReadReg032(param_1,uVar1,param_2);
  return;
}


// ===== 00472b10 vgpuDevWriteReg032 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void vgpuDevWriteReg032(long param_1,uint param_2,undefined4 param_3,undefined1 *param_4)

{
  long lVar1;
  undefined1 uVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  uint local_20;
  int local_1c [3];
  
  local_20 = 0;
  local_1c[0] = 0;
  if ((param_1 != 0) && (lVar4 = *(long *)(param_1 + 7000), lVar4 != 0)) {
    if (*(char *)(param_1 + 0x908) == '\0') {
      lVar1 = *(long *)(g_pSys + 0x238);
      uVar2 = 0;
      if (((lVar1 == 0) || (uVar2 = 0, *(char *)(lVar1 + 0x49) == '\0')) ||
         (uVar2 = 0, *(char *)(lVar1 + 0x4a) == '\0')) goto LAB_00472c40;
    }
    iVar5 = (**(code **)(lVar4 + 0x2a8))(param_1,lVar4,&local_20,local_1c);
    if (iVar5 == 0) {
      iVar5 = 0x30;
      if (*(char *)(param_1 + 0x4913) != '\0') {
        iVar5 = local_1c[0];
      }
      if (((local_20 <= param_2) && ((ulong)param_2 + 4 <= (ulong)(iVar5 + local_20))) &&
         (lVar4 = *(long *)(param_1 + 0x4f8), lVar4 != 0)) {
        iVar5 = param_2 - local_20;
        if (((*(char *)(param_1 + 0x4912) == '\0') || (*(char *)(param_1 + 0x4909) != '\0')) ||
           ((iVar5 != 0x18 || (*(char *)(param_1 + 0x4908) != '\0')))) {
          if (*(char *)(param_1 + 0x4913) != '\0') {
            cVar3 = osIsISR();
            uVar2 = 1;
            if (cVar3 != '\0') {
LAB_00472c40:
              *param_4 = uVar2;
              return;
            }
            lVar4 = *(long *)(param_1 + 0x4f8);
          }
          osPciWriteDword(lVar4,iVar5,param_3);
        }
        else {
          osPciWriteDword(lVar4,0x1c,param_3);
        }
        uVar2 = 1;
        goto LAB_00472c36;
      }
    }
  }
  uVar2 = 0;
LAB_00472c36:
  *param_4 = uVar2;
  return;
}


// ===== 00472cb0 vgpuDevReadReg032 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 vgpuDevReadReg032(long param_1,uint param_2,undefined1 *param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint local_10;
  int local_c;
  
  local_10 = 0;
  local_c = 0;
  if ((((param_1 != 0) && (lVar1 = *(long *)(param_1 + 7000), lVar1 != 0)) &&
      ((*(char *)(param_1 + 0x908) != '\0' ||
       (((lVar2 = *(long *)(g_pSys + 0x238), lVar2 != 0 && (*(char *)(lVar2 + 0x49) != '\0')) &&
        (*(char *)(lVar2 + 0x4a) != '\0')))))) &&
     (iVar5 = (**(code **)(lVar1 + 0x2a8))(param_1,lVar1,&local_10,&local_c), iVar5 == 0)) {
    iVar5 = 0x30;
    if (*(char *)(param_1 + 0x4913) != '\0') {
      iVar5 = local_c;
    }
    if (((local_10 <= param_2) && ((ulong)param_2 + 4 <= (ulong)(iVar5 + local_10))) &&
       (*(long *)(param_1 + 0x4f8) != 0)) {
      iVar5 = param_2 - local_10;
      if (((*(char *)(param_1 + 0x4912) != '\0') && (*(char *)(param_1 + 0x4909) == '\0')) &&
         ((iVar5 == 0x18 && (*(char *)(param_1 + 0x4908) == '\0')))) {
        *param_3 = 1;
        uVar4 = osPciReadDword(*(undefined8 *)(param_1 + 0x4f8),0x1c);
        return uVar4;
      }
      if ((*(char *)(param_1 + 0x4913) != '\0') && (cVar3 = osIsISR(), cVar3 != '\0')) {
        *param_3 = 1;
        return 0;
      }
      *param_3 = 1;
      uVar4 = osPciReadDword(*(undefined8 *)(param_1 + 0x4f8),iVar5);
      return uVar4;
    }
  }
  *param_3 = 0;
  return 0;
}


// ===== 00472e30 osGetCpuVaAddrShift =====

int osGetCpuVaAddrShift(void)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  
  lVar1 = osGetMaxUserVa();
  iVar3 = 1;
  uVar2 = lVar1 - 1;
  if (uVar2 != 0) {
    lVar1 = 0x3f;
    if (uVar2 != 0) {
      for (; uVar2 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    iVar3 = (int)lVar1 + 2;
  }
  return iVar3;
}


// ===== 00472e60 osPagedSegmentAccessCheck =====

void osPagedSegmentAccessCheck(void)

{
  long lVar1;
  char cVar2;
  
  lVar1 = sysGetOs_IMPL(g_pSys);
  cVar2 = portMemExSafeForPagedAlloc();
  if ((cVar2 != '\0') && (*(char *)(lVar1 + 0x4e) == '\0')) {
    return;
  }
  nvAssertFailedNoLog("Paged memory access is prohibited","src/kernel/os/os_init.c",0x1bb);
  return;
}


// ===== 00472ec0 osReadRegistryDword =====

undefined8 osReadRegistryDword(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pRegParmStr != NULL","src/kernel/os/os_init.c",0x1d4);
  }
  else {
    if (param_3 != 0) {
      uVar1 = osReadRegistryDwordBase();
      if ((int)uVar1 == 0) {
        return uVar1;
      }
      uVar1 = nbsiReadRegistryDword(param_1,param_2,param_3);
      return uVar1;
    }
    nvAssertFailedNoLog("pData != NULL","src/kernel/os/os_init.c",0x1d5);
  }
  return 0x1f;
}


// ===== 00472f50 osReadRegistryString =====

undefined8 osReadRegistryString(undefined8 param_1,long param_2,long param_3,int *param_4)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pRegParmStr != NULL","src/kernel/os/os_init.c",0x1f9);
  }
  else if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("pCbLen != NULL","src/kernel/os/os_init.c",0x1fa);
  }
  else {
    if ((*param_4 == 0) || (param_3 != 0)) {
      uVar1 = osReadRegistryStringBase();
      if ((int)uVar1 == 0) {
        return uVar1;
      }
      uVar1 = nbsiReadRegistryString(param_1,param_2,param_3,param_4);
      return uVar1;
    }
    nvAssertFailedNoLog("!(*pCbLen != 0 && pData == NULL)","src/kernel/os/os_init.c",0x1fb);
  }
  return 0x1f;
}


// ===== 00473010 nvErrorLog =====

void nvErrorLog(void)

{
  nvErrorLog2();
  return;
}


// ===== 00473030 nvErrorLog_va =====

void nvErrorLog_va(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6)

{
  undefined4 local_50 [2];
  undefined1 *local_48;
  undefined1 *local_40;
  undefined1 local_38 [24];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_48 = &stack0x00000008;
  local_40 = local_38;
  local_50[0] = 0x18;
  local_20 = param_4;
  local_18 = param_5;
  local_10 = param_6;
  nvErrorLog2(param_1,param_2,0,1,param_3,local_50,0,0);
  return;
}


// ===== 00473090 nvErrorLog2_va =====

void nvErrorLog2_va(void)

{
  nvErrorLog2();
  return;
}


// ===== 004730d0 osSanityTestIsr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 osSanityTestIsr(long param_1)

{
  long lVar1;
  char local_1d;
  int local_1c;
  
  lVar1 = *(long *)(param_1 + 0x1c20);
  (**(code **)(lVar1 + 0x188))(param_1,lVar1,&local_1c,&local_1d);
  if (local_1c == 0) {
    return 0x40;
  }
  if (local_1c == 2) {
    if (local_1d == '\0') {
      return 0x40;
    }
  }
  else {
    nvDbg_Printf("src/kernel/os/os_sanity.c",0x56,"osWaitForInterrupt",4,
                 "NVRM: INTR_EN_0_INTA_SOFTWARE was not set on gpuInstance: 0x%x\n",
                 *(undefined4 *)(param_1 + 0x7a4));
    nvAssertFailedNoLog(&DAT_00d886c9,"src/kernel/os/os_sanity.c",0x59);
  }
  (**(code **)(lVar1 + 0x1f0))(param_1,lVar1);
  nvDbg_Printf("src/kernel/os/os_sanity.c",0x5e,"osWaitForInterrupt",1,
               "NVRM: Triggered for gpuInstance: 0x%x\n",*(undefined4 *)(param_1 + 0x7a4));
  interrupt_triggered = 1;
  return 0;
}


// ===== 004731d0 osVerifySystemEnvironment =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

byte osVerifySystemEnvironment(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  byte bVar3;
  char cVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  uint local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [24];
  undefined1 local_50 [32];
  
  lVar9 = *(long *)(param_1 + 7000);
  if ((*(char *)(param_1 + 0x4910) == '\0') || (*(char *)(lVar9 + 0x3a5) == '\0')) {
    cVar4 = *(char *)(param_1 + 0x45a);
  }
  else {
    cVar4 = kbifIsMSIEnabled_IMPL(param_1,lVar9);
    if (cVar4 != '\0') {
      return 0;
    }
    lVar9 = *(long *)(param_1 + 7000);
    cVar4 = *(char *)(param_1 + 0x45a);
  }
  bVar3 = 0;
  if (cVar4 == '\0') {
    nvDbg_Printf("src/kernel/os/os_sanity.c",0x91,"_osVerifyInterrupts",1,
                 "NVRM: called with gpuInstance: 0x%x\n",*(undefined4 *)(param_1 + 0x7a4));
    gpumgrGetGpuAttachInfo(&local_74,&local_70);
    lVar6 = portMemAllocNonPaged((ulong)local_74 << 2);
    if (lVar6 == 0) {
      nvDbg_Printf("src/kernel/os/os_sanity.c",0x98,"_osVerifyInterrupts",4,
                   "NVRM: pIntrEn0 portMemAllocNonPaged failed!\n");
    }
    else {
      lVar7 = portMemAllocNonPaged((ulong)local_74 << 2);
      if (lVar7 != 0) {
        local_6c = 0;
        uVar11 = 0;
        while (lVar8 = gpumgrGetNextGpu(local_70,&local_6c), lVar8 != 0) {
          if ((*(char *)(lVar8 + 0x45a) == '\0') &&
             (cVar4 = gpuIsGpuFullPower_IMPL(lVar8), cVar4 != '\0')) {
            lVar2 = *(long *)(lVar8 + 0x1c20);
            uVar5 = (**(code **)(lVar2 + 0x170))(lVar8,lVar2,0);
            *(undefined4 *)(lVar7 + (ulong)uVar11 * 4) = uVar5;
            (**(code **)(lVar2 + 0x178))(lVar8,lVar2,0);
            lVar2 = *(long *)(lVar8 + 0x1c20);
            uVar5 = (**(code **)(lVar2 + 0x328))(lVar8,lVar2,0);
            *(undefined4 *)((ulong)uVar11 * 4 + lVar6) = uVar5;
            (**(code **)(lVar2 + 800))(lVar8,lVar2,0);
            (**(code **)(lVar2 + 0x1c8))(lVar8,lVar2,0);
            uVar11 = uVar11 + 1;
          }
        }
        lVar8 = *(long *)(param_1 + 0x1c20);
        (**(code **)(lVar8 + 0x1f0))(param_1,lVar8);
        (**(code **)(lVar8 + 800))(param_1,lVar8,2,0);
        (**(code **)(lVar8 + 0x1f8))(param_1,lVar8);
        if (*(char *)(lVar8 + 0x346) != '\0') {
          intrGetIntrMask_GP100(param_1,lVar8,local_68,0);
          bitVectorSetAll_IMPL(local_50,0xb4);
          (**(code **)(lVar8 + 0x318))(param_1,lVar8,local_50,0);
        }
        *(undefined1 *)(param_1 + 0x8f8) = 1;
        uVar11 = 0;
        interrupt_triggered = 0;
        (**(code **)(lVar8 + 0x1e8))(param_1,lVar8);
        kbifCheckAndRearmMSI_IMPL(param_1,lVar9);
        do {
          if (interrupt_triggered != 0) break;
          uVar11 = uVar11 + 5;
          osDelayUs(5);
        } while (uVar11 <= *(uint *)(param_1 + 0x1af4));
        kbifCheckAndRearmMSI_IMPL(param_1,lVar9);
        *(undefined1 *)(param_1 + 0x8f8) = 0;
        if (*(char *)(lVar8 + 0x346) != '\0') {
          (**(code **)(lVar8 + 0x318))(param_1,lVar8,local_68,0);
        }
        uVar11 = 0;
        (**(code **)(lVar8 + 0x200))(param_1,lVar8);
        local_6c = 0;
        while (lVar9 = gpumgrGetNextGpu(local_70,&local_6c), lVar9 != 0) {
          if ((*(char *)(lVar9 + 0x45a) == '\0') &&
             (cVar4 = gpuIsGpuFullPower_IMPL(lVar9), cVar4 != '\0')) {
            lVar8 = *(long *)(lVar9 + 0x1c20);
            uVar10 = (ulong)uVar11;
            uVar11 = uVar11 + 1;
            (**(code **)(lVar8 + 0x180))
                      (lVar9,lVar8,*(undefined4 *)(lVar7 + uVar10 * 4),0,*(code **)(lVar8 + 0x180));
            puVar1 = (undefined4 *)(lVar6 + uVar10 * 4);
            (**(code **)(lVar8 + 800))(lVar9,lVar8,*puVar1,0,*(code **)(lVar8 + 800));
            (**(code **)(lVar8 + 0x1c8))(lVar9,lVar8,*puVar1);
          }
        }
        portMemFree(lVar6);
        portMemFree(lVar7);
        nvDbg_Printf("src/kernel/os/os_sanity.c",0x122,"_osVerifyInterrupts",1,
                     "NVRM: Finishing with %d\n",interrupt_triggered);
        return -(interrupt_triggered == 0) & 0x45;
      }
      nvDbg_Printf("src/kernel/os/os_sanity.c",0x9e,"_osVerifyInterrupts",4,
                   "NVRM: pIntrEn1 portMemAllocNonPaged failed!\n");
      portMemFree(lVar6);
    }
    bVar3 = 0x51;
  }
  return bVar3;
}


// ===== 004736a0 osQADbgRegistryInit =====

void osQADbgRegistryInit(void)

{
  return;
}


// ===== 004736b0 osNv_rdxcr0 =====

undefined8 osNv_rdxcr0(void)

{
  return 0;
}


// ===== 004736c0 osSimEscapeWrite =====

undefined8 osSimEscapeWrite(void)

{
  return 0xffff;
}


// ===== 004736d0 osSimEscapeRead =====

undefined8 osSimEscapeRead(void)

{
  return 0xffff;
}


// ===== 004736e0 osCallACPI_MXMX =====

undefined8 osCallACPI_MXMX(void)

{
  return 0x56;
}


// ===== 004736f0 osCallACPI_OPTM_GPUON =====

undefined8 osCallACPI_OPTM_GPUON(void)

{
  return 0x56;
}


// ===== 00473700 osCallACPI_NVHG_GPUON =====

undefined8 osCallACPI_NVHG_GPUON(void)

{
  return 0x56;
}


// ===== 00473710 osCallACPI_NVHG_GPUOFF =====

undefined8 osCallACPI_NVHG_GPUOFF(void)

{
  return 0x56;
}


// ===== 00473720 osCallACPI_NVHG_GPUSTA =====

undefined8 osCallACPI_NVHG_GPUSTA(void)

{
  return 0x56;
}


// ===== 00473730 osCallACPI_NVHG_MXDS =====

undefined8 osCallACPI_NVHG_MXDS(void)

{
  return 0x56;
}


// ===== 00473740 osCallACPI_NVHG_MXMX =====

undefined8 osCallACPI_NVHG_MXMX(void)

{
  return 0x56;
}


// ===== 00473750 osCallACPI_NVHG_DOS =====

undefined8 osCallACPI_NVHG_DOS(void)

{
  return 0x56;
}


// ===== 00473760 osCallACPI_NVHG_DCS =====

undefined8 osCallACPI_NVHG_DCS(void)

{
  return 0x56;
}


// ===== 00473770 osCallACPI_MXID =====

undefined8 osCallACPI_MXID(void)

{
  return 0x56;
}


// ===== 00473780 osCallACPI_LRST =====

undefined8 osCallACPI_LRST(void)

{
  return 0x56;
}


// ===== 00473790 osCheckCallback =====

undefined8 osCheckCallback(void)

{
  return 0;
}


// ===== 004737a0 osRCCallback =====

undefined8 osRCCallback(void)

{
  return 0;
}


// ===== 004737b0 osCheckCallback_v2 =====

undefined8 osCheckCallback_v2(void)

{
  return 0;
}


// ===== 004737c0 osRCCallback_v2 =====

undefined8 osRCCallback_v2(void)

{
  return 0;
}


// ===== 004737d0 osPageArrayGetPhysAddr =====

undefined8 osPageArrayGetPhysAddr(void)

{
  nvAssertFailedNoLog(&DAT_00d887bc,"src/kernel/os/os_stubs.c",0xbe);
  return 0;
}


// ===== 00473800 osInternalReserveAllocCallback =====

void osInternalReserveAllocCallback(void)

{
  return;
}


// ===== 00473810 osInternalReserveFreeCallback =====

void osInternalReserveFreeCallback(void)

{
  return;
}


// ===== 00473820 osIsKernelBuffer =====

undefined8 osIsKernelBuffer(void)

{
  return 0;
}


// ===== 00473830 osMapViewToSection =====

undefined8 osMapViewToSection(void)

{
  return 0x56;
}


// ===== 00473840 osUnmapViewFromSection =====

undefined8 osUnmapViewFromSection(void)

{
  return 0x56;
}


// ===== 00473850 osSrPinSysmem =====

undefined8 osSrPinSysmem(void)

{
  return 0x56;
}


// ===== 00473860 osSrUnpinSysmem =====

undefined8 osSrUnpinSysmem(void)

{
  return 0x56;
}


// ===== 00473870 osCreateMemFromOsDescriptorInternal =====

undefined8 osCreateMemFromOsDescriptorInternal(void)

{
  return 0x56;
}


// ===== 00473880 osReserveCpuAddressSpaceUpperBound =====

undefined8 osReserveCpuAddressSpaceUpperBound(void)

{
  return 0x56;
}


// ===== 00473890 osReleaseCpuAddressSpaceUpperBound =====

void osReleaseCpuAddressSpaceUpperBound(void)

{
  return;
}


// ===== 004738a0 osInitOSHwInfo =====

void osInitOSHwInfo(void)

{
  return;
}


// ===== 004738b0 osDestroyOSHwInfo =====

void osDestroyOSHwInfo(void)

{
  return;
}


// ===== 004738c0 osDoFunctionLevelReset =====

undefined8 osDoFunctionLevelReset(void)

{
  return 0x56;
}


// ===== 004738d0 osDispService =====

undefined8 osDispService(void)

{
  return 0;
}


// ===== 004738e0 osDeferredIsr =====

undefined8 osDeferredIsr(void)

{
  return 0;
}


// ===== 004738f0 osGetAcpiTable =====

undefined8 osGetAcpiTable(void)

{
  return 0x56;
}


// ===== 00473900 osInitGetAcpiTable =====

undefined8 osInitGetAcpiTable(void)

{
  return 0x56;
}


// ===== 00473910 osDbgBugCheckOnAssert =====

void osDbgBugCheckOnAssert(void)

{
  return;
}


// ===== 00473920 osQueueDpc =====

undefined8 osQueueDpc(void)

{
  return 0;
}


// ===== 00473930 osBugCheckOnTimeoutEnabled =====

undefined8 osBugCheckOnTimeoutEnabled(void)

{
  return 0;
}


// ===== 00473940 osDbgBreakpointEnabled =====

undefined8 osDbgBreakpointEnabled(void)

{
  return 1;
}


// ===== 00473950 osGetUefiVariable =====

undefined8 osGetUefiVariable(void)

{
  return 0x56;
}


// ===== 00473960 osGetNvGlobalRegistryDword =====

undefined8 osGetNvGlobalRegistryDword(void)

{
  return 0x56;
}


// ===== 00473980 _osRunAll1HzCallbacks =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _osRunAll1HzCallbacks(long param_1)

{
  long lVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  long *plVar6;
  
  lVar1 = *(long *)(param_1 + 0x1b88);
  cVar2 = gpuIsGpuFullPower_IMPL();
  if (cVar2 != '\0') {
    puVar5 = *(undefined8 **)(lVar1 + 0x2038);
    if (puVar5 != (undefined8 *)0x0) {
      plVar6 = (long *)(lVar1 + 0x2038);
      do {
        while( true ) {
          if ((code *)*puVar5 != (code *)0x0) {
            (*(code *)*puVar5)(param_1,puVar5[1]);
          }
          if ((undefined8 *)*plVar6 == puVar5) break;
          puVar3 = *(undefined8 **)(lVar1 + 0x2038);
          if (puVar3 != (undefined8 *)0x0) {
            plVar6 = (long *)(lVar1 + 0x2038);
            do {
              if (puVar5 == puVar3) goto LAB_004739d0;
              plVar6 = puVar3 + 3;
              puVar3 = (undefined8 *)puVar3[3];
            } while (puVar3 != (undefined8 *)0x0);
          }
LAB_00473a52:
          plVar6 = puVar5 + 3;
          puVar5 = (undefined8 *)*plVar6;
          if (puVar5 == (undefined8 *)0x0) goto LAB_00473a63;
        }
LAB_004739d0:
        if ((*(byte *)(puVar5 + 2) & 1) != 0) goto LAB_00473a52;
        *plVar6 = puVar5[3];
        puVar5[3] = *(undefined8 *)(lVar1 + 0x2040);
        *(undefined8 **)(lVar1 + 0x2040) = puVar5;
        puVar5 = (undefined8 *)*plVar6;
      } while (puVar5 != (undefined8 *)0x0);
    }
LAB_00473a63:
    uVar4 = osGetMonotonicTimeNs();
    *(undefined8 *)(param_1 + 0x1b30) = uVar4;
  }
  return;
}


// ===== 00473a80 osInit1HzCallbacks =====

ulong osInit1HzCallbacks(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  
  *(undefined8 *)(param_1 + 0x2038) = 0;
  *(long *)(param_1 + 0x2040) = param_1 + 0x2048;
  *(long *)(param_1 + 0x2060) = param_1 + 0x2068;
  lVar2 = param_1 + 0x2088;
  do {
    *(long *)(lVar2 + -8) = lVar2;
    lVar3 = lVar2 + 0x40;
    *(long *)(lVar2 + 0x18) = lVar2 + 0x20;
    lVar2 = lVar3;
  } while (lVar3 != param_1 + 0x24c8);
  *(undefined8 *)(param_1 + 0x24c0) = 0;
  if (*(char *)(param_1 + 0x21b) == '\0') {
    return 0;
  }
  uVar1 = tmrEventCreate_IMPL(param_1,lVar3,_os1HzCallback,0,1);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "tmrEventCreate(pTmr, &pTmr->pOs1HzEvent, _os1HzCallback, NULL, TMR_FLAG_RECUR)",
             "src/kernel/os/os_timer.c",0x41);
  return uVar1 & 0xffffffff;
}


// ===== 00473b30 osDestroy1HzCallbacks =====

undefined8 osDestroy1HzCallbacks(long param_1)

{
  if (*(long *)(param_1 + 0x24c8) != 0) {
    tmrEventDestroy_IMPL();
    *(undefined8 *)(param_1 + 0x24c8) = 0;
  }
  *(undefined8 *)(param_1 + 0x2038) = 0;
  *(undefined8 *)(param_1 + 0x2040) = 0;
  return 0;
}


// ===== 00473b80 osSchedule1HzCallback =====

undefined8 osSchedule1HzCallback(long param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  
  lVar1 = *(long *)(param_1 + 0x1b88);
  plVar4 = *(long **)(lVar1 + 0x2040);
  if (plVar4 != (long *)0x0) {
    plVar3 = *(long **)(lVar1 + 0x2038);
    if (plVar3 == (long *)0x0) {
      if (*(long *)(lVar1 + 0x24c8) != 0) {
        iVar2 = tmrEventScheduleRel_IMPL(lVar1,*(long *)(lVar1 + 0x24c8),1000000000);
        if (iVar2 == 0) {
          plVar4 = *(long **)(lVar1 + 0x2040);
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar2,"tmrEventScheduleRelSec(pTmr, pTmr->pOs1HzEvent, 1)",
                     "src/kernel/os/os_timer.c",0x82);
          plVar4 = *(long **)(lVar1 + 0x2040);
        }
      }
    }
    else {
      do {
        if (((param_2 == *plVar3) && (param_3 == plVar3[1])) && ((*(byte *)(plVar3 + 2) & 1) != 0))
        goto LAB_00473bde;
        plVar3 = (long *)plVar3[3];
      } while (plVar3 != (long *)0x0);
    }
    *(long *)(lVar1 + 0x2040) = plVar4[3];
    *plVar4 = param_2;
    plVar4[1] = param_3;
    *(undefined4 *)(plVar4 + 2) = param_4;
    plVar4[3] = *(long *)(lVar1 + 0x2038);
    *(long **)(lVar1 + 0x2038) = plVar4;
    return 0;
  }
LAB_00473bde:
  nvDbg_Printf("src/kernel/os/os_timer.c",0x91,"osSchedule1HzCallback",1,
               "NVRM: Callback registration FAILED!\n");
  return 0x3f;
}


// ===== 00473cc0 osRemove1HzCallback =====

void osRemove1HzCallback(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  
  lVar1 = *(long *)(param_1 + 0x1b88);
  plVar3 = *(long **)(lVar1 + 0x2038);
  if (plVar3 != (long *)0x0) {
    plVar4 = (long *)(lVar1 + 0x2038);
    while (((*plVar3 != param_2 || (plVar3[1] != param_3)) || ((*(byte *)(plVar3 + 2) & 1) == 0))) {
      plVar4 = plVar3 + 3;
      plVar3 = (long *)plVar3[3];
      if (plVar3 == (long *)0x0) {
        return;
      }
    }
    *plVar4 = plVar3[3];
    lVar2 = *(long *)(lVar1 + 0x2040);
    plVar3[1] = 0;
    plVar3[3] = lVar2;
    *plVar3 = 0;
    *(undefined4 *)(plVar3 + 2) = 1;
    *(long **)(lVar1 + 0x2040) = plVar3;
    if (*(long *)(lVar1 + 0x2038) != 0) {
      return;
    }
  }
  if (*(long *)(lVar1 + 0x24c8) != 0) {
    tmrEventCancel_IMPL();
    return;
  }
  return;
}


// ===== 00473d80 osRun1HzCallbacksNow =====

undefined8 osRun1HzCallbacksNow(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_ac;
  undefined1 local_a8 [144];
  
  lVar1 = g_pSys;
  local_ac = 0;
  iVar2 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),1,1,0x80004,&local_ac);
  if (iVar2 == 0) {
    iVar2 = osCondAcquireRmSema(*(undefined8 *)(lVar1 + 0x160));
    if (iVar2 == 0) {
      threadStateInitISRAndDeferredIntHandler(local_a8,param_1,4);
      _osRunAll1HzCallbacks(param_1);
      osReleaseRmSema(*(undefined8 *)(lVar1 + 0x160),0);
      rmGpuGroupLockRelease(local_ac,0);
      threadStateFreeISRAndDeferredIntHandler(local_a8,param_1,4);
      return 1;
    }
    rmGpuGroupLockRelease(local_ac,0);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x1b38) = 1;
  UNLOCK();
  return 0;
}


// ===== 00473e80 _os1HzCallback =====

void _os1HzCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  osRun1HzCallbacksNow();
  tmrEventScheduleRel_IMPL(param_2,param_3,1000000000);
  return;
}


// ===== 00473eb0 osRunQueued1HzCallbacksUnderLock =====

ulong osRunQueued1HzCallbacksUnderLock(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if ((char)uVar2 != '\0') {
    uVar2 = portUtilIsInterruptContext();
    if ((char)uVar2 == '\0') {
      uVar2 = (ulong)*(uint *)(param_1 + 0x1b38);
      if (*(uint *)(param_1 + 0x1b38) != 0) {
        _osRunAll1HzCallbacks(param_1);
        LOCK();
        uVar1 = *(uint *)(param_1 + 0x1b38);
        *(uint *)(param_1 + 0x1b38) = 0;
        uVar2 = (ulong)uVar1;
        UNLOCK();
      }
    }
  }
  return uVar2;
}


// ===== 00473f10 cacheDsmSupportedFunction =====

void cacheDsmSupportedFunction(long param_1,uint param_2,int param_3,int *param_4,ulong param_5)

{
  undefined4 uVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_5;
  if ((7 < iVar4 - 1U) || (param_3 != 0)) {
    return;
  }
  if ((short)param_5 == 4) {
    if (*param_4 + 0x7fffffffU < 3) {
      pcVar2 = "UNKNOWN";
      if (param_2 < 0xe) {
        pcVar2 = *(char **)(DSMCalls + (ulong)param_2 * 8);
      }
      nvDbg_Printf("src/kernel/platform/acpi_common.c",0x78,"cacheDsmSupportedFunction",1,
                   "NVRM: %s DSM functions not available.\n",pcVar2);
      return;
    }
    portMemCopy(param_1 + 0x2044 + (ulong)param_2 * 0x1c,4,param_4,4,param_5,param_1,iVar4);
    param_1 = param_1 + (ulong)param_2 * 0x1c;
    *(undefined4 *)(param_1 + 0x204c) = 4;
    if ((*(byte *)(param_1 + 0x2044) & 1) == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x2040);
    }
    else {
      *(undefined4 *)(param_1 + 0x2040) = 2;
      uVar1 = 2;
    }
  }
  else {
    lVar3 = (ulong)param_2 * 0x1c;
    portMemCopy(param_1 + 0x2044 + lVar3,param_5 & 0xffffffff,param_4,param_5 & 0xffffffff);
    param_1 = param_1 + lVar3;
    *(int *)(param_1 + 0x204c) = iVar4;
    if ((*(byte *)(param_1 + 0x2044) & 1) == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x2040);
    }
    else {
      *(undefined4 *)(param_1 + 0x2040) = 2;
      uVar1 = 2;
    }
    if (iVar4 == 8) {
      pcVar2 = "UNKNOWN";
      if (param_2 < 0xe) {
        pcVar2 = *(char **)(DSMCalls + (ulong)param_2 * 8);
      }
      nvDbg_Printf("src/kernel/platform/acpi_common.c",0x8f,"cacheDsmSupportedFunction",1,
                   "NVRM: %s DSM get supported subfunction returned 0x%08x size=%d suppStatus=%d\n",
                   pcVar2,*param_4,8,uVar1);
      return;
    }
  }
  pcVar2 = "UNKNOWN";
  if (param_2 < 0xe) {
    pcVar2 = *(char **)(DSMCalls + (ulong)param_2 * 8);
  }
  nvDbg_Printf("src/kernel/platform/acpi_common.c",0x97,"cacheDsmSupportedFunction",1,
               "NVRM: %s DSM get supported subfunction returned 0x%04x size=%d suppStatus=%d\n",
               pcVar2,*param_4,iVar4,uVar1);
  return;
}


// ===== 00474160 remapDsmFunctionAndSubFunction =====

undefined4 remapDsmFunctionAndSubFunction(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  uint *puVar5;
  char *pcVar6;
  
  if (param_2 == (uint *)0x0) {
    nvAssertFailedNoLog("pAcpiDsmFunction","src/kernel/platform/acpi_common.c",0x1bc);
    return 0x1f;
  }
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pRemappedDsmSubFunction","src/kernel/platform/acpi_common.c",0x1bd);
    return 0x1f;
  }
  nvDbg_Printf("src/kernel/platform/acpi_common.c",0x1bf,"remapDsmFunctionAndSubFunction",1,
               "NVRM: ACPI DSM remapping function = %x Subfunction = %x\n",*param_2,*param_3);
  uVar3 = *param_3;
  if (*param_2 < 0xc) {
    if (uVar3 < 0x200) {
      return 0;
    }
    lVar4 = 0;
    while ((&genDsmSubFuncRemapTable)[lVar4] != uVar3) {
      lVar4 = lVar4 + 0xd;
      if (lVar4 == 0x68) {
        return 0x56;
      }
    }
    uVar3 = (&genDsmSubFuncRemapTable)[*param_2 + 1 + (int)lVar4];
    if (uVar3 == 0) {
      return 0x56;
    }
  }
  else {
    if (uVar3 < 0x200) {
      nvAssertFailedNoLog("isGenericDsmSubFunction(*pRemappedDsmSubFunction)",
                          "src/kernel/platform/acpi_common.c",0x1d4);
      return 0x1f;
    }
    if ((*(uint *)(param_1 + 0x2214) & 1 << ((byte)uVar3 & 0x1f)) == 0) {
      lVar4 = 0;
      puVar5 = &dsmOrderOfPrecedenceList;
      if (uVar3 < 0x200) goto LAB_00474251;
LAB_00474220:
      if (uVar3 != (&genDsmSubFuncRemapTable)[lVar4]) goto code_r0x0047422d;
      uVar3 = *puVar5;
      uVar1 = (&genDsmSubFuncRemapTable)[uVar3 + 1 + (int)lVar4];
      if ((uVar1 != 0) && (iVar2 = testIfDsmSubFunctionEnabled(param_1,uVar3,uVar1), iVar2 == 0)) {
        pcVar6 = "UNKNOWN";
        if (*param_2 < 0xe) {
          pcVar6 = *(char **)(DSMCalls + (ulong)*param_2 * 8);
        }
        nvDbg_Printf("src/kernel/platform/acpi_common.c",0x1e9,"remapDsmFunctionAndSubFunction",1,
                     "NVRM: ACPI DSM remap (func=%s/subfunc=0x%x) remapped to (func=%s/subfunc=0x%x).\n"
                     ,pcVar6,*param_3,*(undefined8 *)(DSMCalls + (ulong)uVar3 * 8),uVar1);
        *param_2 = uVar3;
        *param_3 = uVar1;
        return 0;
      }
      goto LAB_00474237;
    }
    *param_2 = *(uint *)(param_1 + 0x21d4 + (ulong)(uVar3 - 0x200) * 4);
    uVar3 = *(uint *)(param_1 + 0x21f4 + (ulong)(uVar3 - 0x200) * 4);
  }
  *param_3 = uVar3;
  return 0;
code_r0x0047422d:
  lVar4 = lVar4 + 0xd;
  if (lVar4 == 0x68) {
LAB_00474237:
    puVar5 = puVar5 + 1;
    if (puVar5 == (uint *)&DAT_00d89130) {
      return 0x56;
    }
    while( true ) {
      uVar3 = *param_3;
      lVar4 = 0;
      if (0x1ff < uVar3) break;
LAB_00474251:
      puVar5 = puVar5 + 1;
      nvAssertFailedNoLog("isGenericDsmSubFunction(acpiDsmSubFunction)",
                          "src/kernel/platform/acpi_common.c",0x165);
      if (puVar5 == (uint *)&DAT_00d89130) {
        return 0x56;
      }
    }
  }
  goto LAB_00474220;
}


// ===== 00474460 testIfDsmSubFunctionEnabled =====

undefined1  [16] testIfDsmSubFunctionEnabled(long param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulong extraout_RDX;
  ulong uVar3;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  uint local_20;
  uint local_1c [3];
  
  local_20 = param_3;
  local_1c[0] = param_2;
  if ((0xb < param_2) && (param_2 != 0xd)) {
    nvAssertFailedNoLog("(acpiDsmFunction < ACPI_DSM_FUNCTION_COUNT) || (acpiDsmFunction == ACPI_DSM_FUNCTION_CURRENT)"
                        ,"src/kernel/platform/acpi_common.c",0xb9);
    uVar2 = extraout_RDX_00;
LAB_00474568:
    auVar7._8_8_ = uVar2;
    auVar7._0_8_ = 0x1f;
    return auVar7;
  }
  iVar1 = remapDsmFunctionAndSubFunction(param_1,local_1c,&local_20);
  uVar3 = extraout_RDX;
  if (iVar1 == 0) {
    if (0xb < local_1c[0]) {
      nvAssertFailedNoLog("acpiDsmFunction < ACPI_DSM_FUNCTION_COUNT",
                          "src/kernel/platform/acpi_common.c",0xc1);
      uVar2 = extraout_RDX_01;
      goto LAB_00474568;
    }
    uVar3 = (ulong)local_1c[0];
    param_1 = param_1 + uVar3 * 0x1c;
    if ((*(int *)(param_1 + 0x2040) - 2U & 0xfffffffd) != 0) {
      uVar2 = 0x59;
      if (*(int *)(param_1 + 0x2040) != 1) {
        nvDbg_Printf("src/kernel/platform/acpi_common.c",0xe2,"testIfDsmSubFunctionEnabled",4,
                     "NVRM: %s ACPI DSM called before _acpiDsmSupportedFuncCacheInit subfunction = %x.\n"
                     ,*(undefined8 *)(DSMCalls + uVar3 * 8),local_20);
        uVar2 = 0x57;
        uVar3 = 0x474494;
      }
      auVar4._8_8_ = uVar3;
      auVar4._0_8_ = uVar2;
      return auVar4;
    }
    uVar3 = (ulong)(local_20 >> 3);
    if (local_20 >> 3 <= *(uint *)(param_1 + 0x204c)) {
      uVar2 = 0;
      if ((*(byte *)(param_1 + 0x2044 + uVar3) >> (local_20 & 7) & 1) == 0) {
        uVar2 = 0x56;
      }
      auVar6._8_8_ = 0x56;
      auVar6._0_8_ = uVar2;
      return auVar6;
    }
  }
  auVar5._8_8_ = uVar3;
  auVar5._0_8_ = 0x56;
  return auVar5;
}


// ===== 004745a0 getDsmGetObjectSubfunction =====

/* WARNING: Type propagation algorithm not settling */

undefined4
getDsmGetObjectSubfunction(undefined8 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint local_44;
  uint local_40 [4];
  
  nvDbg_Printf("src/kernel/platform/acpi_common.c",0x21d,"getDsmGetObjectSubfunction",1,
               "NVRM: entry *pAcpiDsmFunction = %x\n",*param_2);
  uVar3 = *param_2;
  if (*param_2 == 0xd) {
    local_44 = 0xd;
    local_40[1] = 0x202;
    iVar1 = remapDsmFunctionAndSubFunction(param_1,&local_44,local_40 + 1);
    uVar3 = local_44;
    if (iVar1 == 0) {
      local_40[0] = 0xd;
      *param_2 = local_44;
      local_40[1] = 0x203;
      iVar1 = remapDsmFunctionAndSubFunction(param_1,local_40,local_40 + 1);
      if (iVar1 == 0) {
        puVar2 = &dsmOrderOfPrecedenceList;
        do {
          if (uVar3 == *puVar2) break;
          if (*puVar2 == local_40[0]) goto LAB_0047473e;
          puVar2 = puVar2 + 1;
        } while (puVar2 != (uint *)&DAT_00d89130);
      }
      uVar3 = *param_2;
    }
    else {
      local_40[0] = 0xd;
      local_40[1] = 0x203;
      iVar1 = remapDsmFunctionAndSubFunction(param_1,local_40,local_40 + 1);
      if (iVar1 != 0) {
        return 0x56;
      }
LAB_0047473e:
      *param_2 = local_40[0];
      uVar3 = local_40[0];
    }
  }
  if (uVar3 != 3) {
    if (uVar3 < 4) {
      if (uVar3 == 0) {
        *param_3 = 6;
        *param_4 = 7;
        uVar3 = *param_2;
        uVar4 = 0;
        goto LAB_00474624;
      }
      if (uVar3 != 1) {
        uVar3 = 2;
        uVar4 = 0x56;
        goto LAB_00474624;
      }
    }
    else if (((uVar3 - 6 & 0xfffffffb) != 0) && (uVar3 != 4)) {
      uVar4 = 0x56;
      goto LAB_00474624;
    }
  }
  *param_3 = 0x10;
  uVar4 = 0;
  *param_4 = 0x11;
  uVar3 = *param_2;
LAB_00474624:
  nvDbg_Printf("src/kernel/platform/acpi_common.c",0x276,"getDsmGetObjectSubfunction",1,
               "NVRM: exit *pAcpiDsmFunction = 0x%x *pGetObjByTypeSubFunction=0x%x, status=%x\n",
               uVar3,*param_3,uVar4);
  return uVar4;
}


// ===== 00474780 checkDsmCall =====

int checkDsmCall(long param_1,uint *param_2,uint *param_3,long param_4,ushort *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  
  if (param_2 == (uint *)0x0) {
    nvAssertFailedNoLog("pAcpiDsmFunction","src/kernel/platform/acpi_common.c",0x2c2);
    return 0x1f;
  }
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pAcpiDsmSubFunction","src/kernel/platform/acpi_common.c",0x2c3);
    return 0x1f;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pInOut","src/kernel/platform/acpi_common.c",0x2c4);
    return 0x1f;
  }
  if (param_5 != (ushort *)0x0) {
    if ((((*(long *)(param_1 + 0x1b80) != 0) &&
         (*(char *)(*(long *)(param_1 + 0x1b80) + 0x27b) != '\0')) && (*param_2 == 3)) ||
       (iVar3 = remapDsmFunctionAndSubFunction(param_1,param_2,param_3), iVar3 != 0)) {
      return 0x56;
    }
    uVar1 = *param_2;
    if (0xb < uVar1) {
      nvAssertFailedNoLog("*pAcpiDsmFunction < ACPI_DSM_FUNCTION_COUNT",
                          "src/kernel/platform/acpi_common.c",0x2d8);
      return 0x1f;
    }
    uVar2 = *param_3;
    if (uVar2 < 0x200) {
      uVar5 = (ulong)uVar1;
      lVar4 = uVar5 * 0x1c + param_1;
      if (*(int *)(lVar4 + 0x2040) == 0) {
        if (uVar2 != 0) {
          nvAssertFailedNoLog("*pAcpiDsmSubFunction == NV_ACPI_ALL_FUNC_SUPPORT",
                              "src/kernel/platform/acpi_common.c",0x303);
          return 0x1f;
        }
      }
      else {
        if (uVar2 == 0) {
          uVar1 = *(uint *)(lVar4 + 0x204c);
          if (uVar1 <= *param_5) {
            *param_5 = (ushort)uVar1;
            portMemCopy(param_4,uVar1,param_1 + 0x2044 + (ulong)*param_2 * 0x1c,uVar1);
            return 0;
          }
          return 2;
        }
        iVar3 = testIfDsmSubFunctionEnabled(param_1,uVar1,uVar2);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (*param_3 != 0) {
          return 0x10005;
        }
        uVar5 = (ulong)*param_2;
      }
      *(undefined4 *)(param_1 + 0x2040 + uVar5 * 0x1c) = 1;
      return 0x10005;
    }
    nvAssertFailedNoLog("*pAcpiDsmSubFunction < NV_ACPI_GENERIC_FUNC_START",
                        "src/kernel/platform/acpi_common.c",0x2d9);
    return 0x1f;
  }
  nvAssertFailedNoLog("pSize","src/kernel/platform/acpi_common.c",0x2c5);
  return 0x1f;
}


// ===== 00474a60 acpiDsmInit =====

void acpiDsmInit(long param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  uint *puVar9;
  ulong uVar10;
  undefined4 *puVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  int *piVar15;
  int *piVar16;
  undefined1 *puVar17;
  undefined8 *puVar18;
  ulong *puVar19;
  undefined2 local_5e;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  ulong local_50 [2];
  undefined4 local_40;
  ulong local_3c;
  
  puVar17 = DSMCalls;
  iVar8 = 0;
  piVar15 = (int *)(param_1 + 0x2040);
  portMemSet(local_50,0,8);
LAB_00474ab0:
  cVar3 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(param_1);
  iVar4 = *piVar15;
  if (cVar3 == '\0') goto LAB_00474b40;
LAB_00474ac3:
  if (iVar8 == 3) goto LAB_00474b40;
  if (iVar4 != 0) goto LAB_00474b40;
LAB_00474acd:
  *piVar15 = 1;
LAB_00474ad4:
  iVar8 = iVar8 + 1;
  piVar16 = piVar15;
  puVar18 = (undefined8 *)puVar17;
  if (iVar8 != 0xc) {
    do {
      piVar15 = piVar16 + 7;
      puVar17 = (undefined1 *)(puVar18 + 1);
      if (iVar8 != 10) goto LAB_00474ab0;
      if (*(int *)(param_1 + 0x20e8) == 2) {
        piVar15 = piVar16 + 0xe;
        puVar17 = (undefined1 *)(puVar18 + 2);
        iVar8 = 0xb;
        *(undefined4 *)(param_1 + 0x2158) = 1;
        goto LAB_00474ab0;
      }
      cVar3 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(param_1);
      if (cVar3 == '\0') {
        if ((*piVar15 == 4) || (*piVar15 == 1)) {
          piVar15 = piVar16 + 0xe;
          puVar17 = (undefined1 *)(puVar18 + 2);
          iVar8 = 0xb;
          goto LAB_00474ab0;
        }
      }
      else {
        iVar4 = *piVar15;
        if (iVar4 == 0) {
          *piVar15 = 1;
          piVar15 = piVar16 + 0xe;
          puVar17 = (undefined1 *)(puVar18 + 2);
          iVar8 = 0xb;
          cVar3 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(param_1);
          iVar4 = *piVar15;
          if (cVar3 != '\0') goto LAB_00474ac3;
        }
LAB_00474b40:
        if ((iVar4 == 4) || (iVar4 == 1)) goto LAB_00474ad4;
      }
      *(undefined1 *)(piVar15 + 4) = 0;
      local_54 = CONCAT22(local_54._2_2_,8);
      iVar4 = osCallACPI_DSM(param_1,iVar8,0,local_50,&local_54);
      if (iVar4 != 0) {
        if (iVar4 == 0x1f) {
          *(undefined1 *)(piVar15 + 4) = 1;
          local_54 = CONCAT22(local_54._2_2_,8);
          iVar4 = osCallACPI_DSM(param_1,iVar8,0,local_50,&local_54);
          if (iVar4 == 0) goto LAB_00474bd0;
        }
LAB_00474b76:
        nvDbg_Printf("src/kernel/platform/acpi_common.c",0x35e,"_acpiDsmSupportedFuncCacheInit",1,
                     "NVRM: %s DSM function not present in ASL.\n",*(undefined8 *)puVar17);
        goto LAB_00474acd;
      }
LAB_00474bd0:
      if ((short)local_54 != 4) goto LAB_00474ad4;
      if ((int)local_50[0] + 0x7fffffffU < 3) goto LAB_00474b76;
      iVar8 = iVar8 + 1;
      piVar16 = piVar15;
      puVar18 = (undefined8 *)puVar17;
      if (iVar8 == 0xc) break;
    } while( true );
  }
  *(undefined4 *)(param_1 + 0x2214) = 0;
  puVar9 = (uint *)(param_1 + 0x21d4);
  uVar14 = 0x200;
  do {
    puVar9[8] = uVar14;
    *puVar9 = 0xd;
    iVar8 = remapDsmFunctionAndSubFunction(param_1,puVar9,puVar9 + 8);
    if (iVar8 == 0) {
      uVar1 = *puVar9;
      uVar2 = puVar9[8];
      if (uVar1 == 0xd) {
        nvDbg_Printf("src/kernel/platform/acpi_common.c",0x422,"_acpiGenFuncCacheInit",1,
                     "NVRM: DSM Generic subfunction 0x%x is not supported. Leaving entry at func %s subfunction 0x%x.\n"
                     ,uVar14,"CURRENT",uVar2);
      }
      else {
        *(uint *)(param_1 + 0x2214) = *(uint *)(param_1 + 0x2214) | 1 << ((byte)uVar14 & 0x1f);
        pcVar7 = "UNKNOWN";
        if (uVar1 < 0xe) {
          pcVar7 = *(char **)(DSMCalls + (ulong)uVar1 * 8);
        }
        nvDbg_Printf("src/kernel/platform/acpi_common.c",0x42c,"_acpiGenFuncCacheInit",1,
                     "NVRM: DSM Generic subfunction 0x%x supported. Mapping to func %s subfunction 0x%x\n"
                     ,uVar14,pcVar7,uVar2);
      }
    }
    else {
      nvDbg_Printf("src/kernel/platform/acpi_common.c",0x435,"_acpiGenFuncCacheInit",1,
                   "NVRM: DSM Test generic subfunction 0x%x is not supported. Indicates possible table corruption.\n"
                   ,uVar14);
    }
    uVar14 = uVar14 + 1;
    puVar9 = puVar9 + 1;
  } while (uVar14 != 0x208);
  local_40 = 10;
  puVar19 = local_50;
  local_50[0] = 0x100000003;
  local_50[1] = 0x600000002;
  *(undefined8 *)(param_1 + 0x2190) = 0xc0000000c;
  *(undefined8 *)(param_1 + 0x2198) = 0xc0000000c;
  do {
    uVar14 = (uint)*puVar19;
    uVar10 = (ulong)uVar14;
    local_54 = 0;
    local_58 = CONCAT22(local_58._2_2_,4);
    *(undefined4 *)(param_1 + 0x2054 + uVar10 * 0x1c) = 1;
    if (((uVar14 != 10) || (*(int *)(param_1 + 0x20fc) != 2)) &&
       (iVar8 = testIfDsmSubFunctionEnabled(param_1,uVar10,0x205), iVar8 == 0)) {
      iVar8 = osCallACPI_DSM(param_1,uVar14,0x205,&local_54,&local_58);
      if ((iVar8 == 0) && (((short)local_58 != 4 || (2 < local_54 + 0x7fffffff)))) {
        *(uint *)(param_1 + 0x2058 + uVar10 * 0x1c) = local_54;
        *(undefined4 *)(param_1 + 0x2054 + uVar10 * 0x1c) = 2;
        if ((local_54 & 0x200) != 0) {
          *(uint *)(param_1 + 0x2190) = uVar14;
        }
        if ((local_54 & 0x400) != 0) {
          *(uint *)(param_1 + 0x2194) = uVar14;
        }
        if ((local_54 & 4) != 0) {
          *(uint *)(param_1 + 0x2198) = uVar14;
        }
        if ((local_54 & 0x1000) != 0) {
          *(uint *)(param_1 + 0x219c) = uVar14;
        }
      }
      else {
        pcVar7 = "UNKNOWN";
        if (uVar14 < 0xe) {
          pcVar7 = *(char **)(DSMCalls + uVar10 * 8);
        }
        nvDbg_Printf("src/kernel/platform/acpi_common.c",0x3a6,"_acpiDsmCallbackInit",4,
                     "NVRM: SBIOS suggested %s supports function %d, but the call failed!\n",pcVar7,
                     0x205);
      }
    }
    puVar19 = (ulong *)((long)puVar19 + 4);
  } while (puVar19 != &local_3c);
  iVar8 = testIfDsmSubFunctionEnabled(param_1,3,1);
  if (iVar8 == 0) {
    local_54 = CONCAT22(local_54._2_2_,4);
    iVar8 = osCallACPI_DSM(param_1,3,1,local_50,&local_54);
    if (iVar8 == 0) {
      if (((short)local_54 != 4) || (2 < (int)local_50[0] + 0x7fffffffU)) {
        *(int *)(param_1 + 0x21ac) = (int)local_50[0];
        goto LAB_00474e04;
      }
    }
    nvDbg_Printf("src/kernel/platform/acpi_common.c",0x3ef,"_acpiDsmCapsInit",4,
                 "NVRM: SBIOS suggested %s supports function %d, but the call failed!\n",
                 &DAT_00d88f75,1);
  }
LAB_00474e04:
  if (*(int *)(param_1 + 0x21d0) == 0) {
    iVar8 = testIfDsmSubFunctionEnabled(param_1,0xd,0x201);
    if ((iVar8 == 0) && (iVar8 = testIfDsmSubFunctionEnabled(param_1,0xd,0x200), iVar8 == 0)) {
      *(undefined4 *)(param_1 + 0x21d0) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x21d0) = 1;
    }
  }
  *(undefined1 *)(param_1 + 0x2218) = 1;
  local_5e = 4;
  *(undefined4 *)(param_1 + 0x2220) = 0x40;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50[0] = local_50[0] & 0xffffffff00000000;
  uVar5 = osCallACPI_DOD(param_1,param_1 + 0x2224,param_1 + 0x2220);
  *(undefined4 *)(param_1 + 0x221c) = uVar5;
  uVar5 = osCallACPI_DSM(param_1,7,1,&local_5c,&local_5e);
  *(undefined4 *)(param_1 + 0x2264) = uVar5;
  *(undefined4 *)(param_1 + 0x2268) = local_5c;
  *(ushort *)(param_1 + 0x226c) = (ushort)((uint)local_5c >> 0x14);
  gpuSetGC6SBIOSCapabilities_IMPL(param_1);
  portMemSet((undefined4 *)(param_1 + 0x2274),0,0xc0);
  portMemSet(param_1 + 0x2334,0,0xc0);
  portMemSet(param_1 + 0x23f4,0,0xc0);
  if (*(int *)(param_1 + 0x221c) == 0) {
    uVar14 = *(uint *)(param_1 + 0x2220) >> 2;
    *(uint *)(param_1 + 0x2270) = uVar14;
    if (uVar14 != 0) {
      puVar11 = (undefined4 *)(param_1 + 0x2274);
      lVar12 = param_1;
      do {
        lVar13 = lVar12 + 4;
        uVar6 = osCallACPI_MXDM(param_1,*(undefined4 *)(lVar12 + 0x2224),&local_58);
        uVar5 = *(undefined4 *)(lVar12 + 0x2224);
        puVar11[2] = uVar6;
        *puVar11 = uVar5;
        puVar11[1] = local_58;
        uVar6 = osCallACPI_MXID(param_1,uVar5,&local_54);
        uVar5 = *(undefined4 *)(lVar12 + 0x2224);
        puVar11[0x32] = uVar6;
        puVar11[0x31] = local_54;
        puVar11[0x30] = uVar5;
        uVar6 = osCallACPI_MXDS(param_1,uVar5,local_50);
        uVar5 = *(undefined4 *)(lVar12 + 0x2224);
        local_54 = 0;
        puVar11[0x62] = uVar6;
        puVar11[0x60] = uVar5;
        local_58 = 0;
        puVar11[0x61] = (int)local_50[0];
        local_50[0] = local_50[0] & 0xffffffff00000000;
        puVar11 = puVar11 + 3;
        lVar12 = lVar13;
      } while ((ulong)(uVar14 * 4) + param_1 != lVar13);
    }
  }
  uVar5 = osCallACPI_DSM(param_1,4,0x1a,param_1 + 0x24b8,&local_5e);
  *(undefined4 *)(param_1 + 0x24b4) = uVar5;
  return;
}


// ===== 004751e0 getAcpiDsmObjectData =====

ulong getAcpiDsmObjectData
                (undefined8 param_1,undefined8 *param_2,undefined4 *param_3,uint param_4,
                uint param_5,ulong param_6)

{
  ulong uVar1;
  undefined1 local_23;
  short local_22;
  uint local_20;
  undefined4 local_1c;
  
  if (param_2 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pNbsiObjData","src/kernel/platform/acpi_common.c",0x4d4);
    param_6 = param_6 & 0xffffffff;
  }
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pSzOfpNbsiObjData","src/kernel/platform/acpi_common.c",0x4d5);
    param_6 = param_6 & 0xffffffff;
  }
  local_23 = 0;
  local_22 = 0x10;
  if (param_4 < 0xe) {
    local_22 = (ushort)((0x2009UL >> ((ulong)param_4 & 0x3f) & 1) == 0) << 4;
  }
  uVar1 = getNbsiObjByType(param_1,param_5 & 0xffff,&local_22,&local_23,0,*param_2,param_3,&local_1c
                           ,&local_20,(ulong)param_4,param_6);
  if (((int)uVar1 == 0) && (uVar1 = (ulong)local_20, local_20 != 0)) {
    if (local_20 == 0xfffffffa) {
      nvDbg_Printf("src/kernel/platform/acpi_common.c",0x4f2,"getAcpiDsmObjectData",1,
                   "NVRM: ACPI DSM object (type=0x%x) signature check failed!\n",param_5);
    }
    else if (local_20 == 0xfffffffe) {
      *param_3 = local_1c;
      return 2;
    }
    uVar1 = 0xffff;
  }
  return uVar1;
}


// ===== 00475360 getSubsystemFromPCIECapabilities =====

void getSubsystemFromPCIECapabilities
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
               undefined2 *param_5,undefined2 *param_6)

{
  undefined8 uVar1;
  undefined1 extraout_AL;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 extraout_AH;
  byte extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined6 extraout_var;
  uint uVar5;
  
  osPciInitHandle(param_1,param_2,param_3,param_4,0,0);
  uVar1 = CONCAT62(extraout_var,CONCAT11(extraout_AH,extraout_AL));
  bVar2 = osPciReadByte(CONCAT62(extraout_var,CONCAT11(extraout_AH,extraout_AL)),0x34);
  if (bVar2 == 0) {
    return;
  }
  do {
    uVar5 = (uint)bVar2;
    cVar3 = osPciReadDword(uVar1,uVar5);
    if (extraout_AH_00 == 0) {
      if (cVar3 != '\r') {
        return;
      }
      break;
    }
    bVar2 = extraout_AH_00;
  } while (cVar3 != '\r');
  uVar4 = osPciReadWord(uVar1,uVar5 + 4);
  *param_5 = CONCAT11(extraout_AH_01,uVar4);
  uVar4 = osPciReadWord(uVar1,uVar5 + 6);
  *param_6 = CONCAT11(extraout_AH_02,uVar4);
  return;
}


// ===== 00475410 clDestructHWBC =====

void clDestructHWBC(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x20);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0x20);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar2 + 0x20);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x20) = 0;
      }
      lVar3 = *(long *)(lVar2 + 0x28);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x28) = 0;
      }
      portMemFree(lVar2);
      *(undefined8 *)(lVar1 + 0x20) = 0;
    }
    lVar2 = *(long *)(lVar1 + 0x28);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar2 + 0x20);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x20) = 0;
      }
      lVar3 = *(long *)(lVar2 + 0x28);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x28) = 0;
      }
      portMemFree(lVar2);
      *(undefined8 *)(lVar1 + 0x28) = 0;
    }
    portMemFree(lVar1);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  lVar1 = *(long *)(param_1 + 0x28);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0x20);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar2 + 0x20);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x20) = 0;
      }
      lVar3 = *(long *)(lVar2 + 0x28);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x28) = 0;
      }
      portMemFree(lVar2);
      *(undefined8 *)(lVar1 + 0x20) = 0;
    }
    lVar2 = *(long *)(lVar1 + 0x28);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar2 + 0x20);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x20) = 0;
      }
      lVar3 = *(long *)(lVar2 + 0x28);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x28) = 0;
      }
      portMemFree(lVar2);
      *(undefined8 *)(lVar1 + 0x28) = 0;
    }
    portMemFree(lVar1);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  portMemFree(param_1);
  return;
}


// ===== 00475790 clConstruct_IMPL =====

undefined8 clConstruct_IMPL(long param_1)

{
  *(undefined1 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 004757b0 clInitPropertiesFromRegistry_IMPL =====

void clInitPropertiesFromRegistry_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  int local_1c;
  
  iVar1 = osReadRegistryDword(param_1,"MB_DisableBr03FlowControl",&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    *(undefined1 *)(param_2 + 0x49) = 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RmForceEnableGen2",&local_1c);
  if ((iVar1 == 0) && (local_1c == 1)) {
    *(undefined1 *)(param_2 + 0x5b) = 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RmForceDisableIomapWC",&local_1c);
  if ((iVar1 == 0) && (local_1c == 1)) {
    *(undefined1 *)(param_2 + 0x69) = 1;
    osQADbgRegistryInit();
    return;
  }
  osQADbgRegistryInit();
  return;
}


// ===== 00475860 clDestruct_IMPL =====

void clDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x88);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0x20);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar2 + 0x20);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x20) = 0;
      }
      lVar3 = *(long *)(lVar2 + 0x28);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x28) = 0;
      }
      portMemFree(lVar2);
      *(undefined8 *)(lVar1 + 0x20) = 0;
    }
    lVar2 = *(long *)(lVar1 + 0x28);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar2 + 0x20);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x20) = 0;
      }
      lVar3 = *(long *)(lVar2 + 0x28);
      if (lVar3 != 0) {
        if (*(long *)(lVar3 + 0x20) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x20) = 0;
        }
        if (*(long *)(lVar3 + 0x28) != 0) {
          clDestructHWBC();
          *(undefined8 *)(lVar3 + 0x28) = 0;
        }
        portMemFree(lVar3);
        *(undefined8 *)(lVar2 + 0x28) = 0;
      }
      portMemFree(lVar2);
      *(undefined8 *)(lVar1 + 0x28) = 0;
    }
    portMemFree(lVar1);
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  clFreeBusTopologyCache_IMPL(param_1);
  clFreePcieConfigSpaceBase_IMPL(param_1);
  return;
}


// ===== 00475a50 clInitMappingPciBusDevice_IMPL =====

undefined8 clInitMappingPciBusDevice_IMPL(long param_1)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar6;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  byte bVar7;
  uint uVar8;
  ushort local_4a;
  short local_3c;
  undefined1 local_3a [10];
  
  if (*(char *)(param_1 + 0x880) == '\0') {
    uVar8 = 0;
    do {
      local_4a = 0;
      do {
        bVar7 = 0;
        do {
          lVar3 = osPciInitHandle(uVar8,(undefined1)local_4a,bVar7,0,&local_3c,local_3a);
          if ((lVar3 != 0) && (local_3c == 0x10de)) {
            cVar1 = osPciReadByte(lVar3,0xb);
            if (cVar1 == '\x03') {
              uVar2 = osPciReadDword(lVar3,0x10);
              if ((ulong)(uVar2 & 0xfffffff0) == *(ulong *)(param_1 + 0x848)) {
                *(undefined1 *)(param_1 + 0x880) = 1;
                uVar4 = (ulong)local_4a << 8 | (ulong)uVar8 << 0x20 | (ulong)bVar7;
                *(ulong *)(param_1 + 0x878) = uVar4;
                goto LAB_00475b1a;
              }
            }
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 != 0x20);
        local_4a = local_4a + 1;
      } while (local_4a != 0x100);
      uVar8 = uVar8 + 1;
    } while (uVar8 != 0x10000);
    if (*(char *)(param_1 + 0x880) == '\0') {
      nvDbg_Printf("src/kernel/platform/chipset/chipset.c",0xbf,"clInitMappingPciBusDevice_IMPL",4,
                   "NVRM: NVRM initMappingPciBusDevice: can\'t find a device!\n");
      return 0xffffffff;
    }
    uVar4 = *(ulong *)(param_1 + 0x878);
LAB_00475b1a:
    uVar6 = (undefined1)(uVar4 >> 8);
  }
  else {
    uVar4 = *(ulong *)(param_1 + 0x878);
    uVar6 = (undefined1)(uVar4 >> 8);
  }
  uVar5 = gpuGenerate32BitId(uVar4 >> 0x20,uVar6,uVar4 & 0xff);
  return uVar5;
}


// ===== 00475be0 clFindFHBAndGetChipsetInfoIndex_IMPL =====

undefined8 clFindFHBAndGetChipsetInfoIndex_IMPL(long param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 uVar3;
  bool bVar4;
  char cVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  uint uVar8;
  long *plVar9;
  short *psVar10;
  long lVar11;
  ulong uVar12;
  short sVar13;
  long *plVar14;
  ushort uVar15;
  char cVar16;
  short local_44;
  undefined2 local_42;
  short local_40 [8];
  
  local_40[0] = 0x600;
  local_40[1] = 0x604;
  local_40[2] = 0x302;
  if (*(char *)(param_1 + 0xcf) != '\0') {
    return 0;
  }
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0xffffffffffffffff;
  if (chipsetInfo == 0) {
    uVar7 = 0;
    if (param_2 != (undefined2 *)0x0) goto LAB_00475d7a;
  }
  else {
    plVar14 = *(long **)(param_1 + 0xe8);
    uVar12 = 0;
    plVar9 = plVar14;
    sVar13 = chipsetInfo;
    if (plVar14 == (long *)0x0) {
      do {
        uVar8 = (int)uVar12 + 1;
        uVar12 = (ulong)uVar8;
      } while ((&chipsetInfo)[uVar12 * 0xc] != 0);
    }
    else {
      do {
        do {
          if ((*(short *)((long)plVar9 + 0x12) == sVar13) &&
             ((short)plVar9[2] == (&DAT_0059eec2)[uVar12 * 0xc])) {
            if (param_2 != (undefined2 *)0x0) {
              *param_2 = (short)uVar12;
            }
            if ((*(char *)((long)plVar9 + 0x24) == '\0') ||
               ((((*(byte *)(plVar9 + 4) & 0x3f) == 0 && (*(char *)((long)plVar9 + 0x21) == '\0'))
                && (*(char *)((long)plVar9 + 0x22) == '\0')))) {
              *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)((long)plVar9 + 0x1c);
              *(char *)(param_1 + 0x9c) = (char)plVar9[4];
              *(undefined1 *)(param_1 + 0x9d) = *(undefined1 *)((long)plVar9 + 0x21);
              uVar6 = *(undefined1 *)((long)plVar9 + 0x22);
              *(undefined1 *)(param_1 + 0x9f) = 1;
              *(undefined1 *)(param_1 + 0x9e) = uVar6;
              *(long *)(param_1 + 0xa0) = plVar9[1];
              *(short *)(param_1 + 0xa8) = (short)plVar9[2];
              *(undefined2 *)(param_1 + 0xaa) = *(undefined2 *)((long)plVar9 + 0x12);
              *(undefined2 *)(param_1 + 0xac) = *(undefined2 *)((long)plVar9 + 0x14);
              *(undefined2 *)(param_1 + 0xae) = *(undefined2 *)((long)plVar9 + 0x16);
              *(char *)(param_1 + 0xb0) = (char)plVar9[3];
              *(undefined4 *)(param_1 + 200) = *(undefined4 *)((long)plVar9 + 0x1c);
              *(char *)(param_1 + 0xcc) = (char)plVar9[4];
              *(undefined1 *)(param_1 + 0xcd) = *(undefined1 *)((long)plVar9 + 0x21);
              uVar6 = *(undefined1 *)((long)plVar9 + 0x22);
              *(undefined1 *)(param_1 + 0xcf) = 1;
              *(undefined1 *)(param_1 + 0xce) = uVar6;
              *(long *)(param_1 + 0xd0) = plVar9[1];
              *(short *)(param_1 + 0xd8) = (short)plVar9[2];
              *(undefined2 *)(param_1 + 0xda) = *(undefined2 *)((long)plVar9 + 0x12);
              *(undefined2 *)(param_1 + 0xdc) = *(undefined2 *)((long)plVar9 + 0x14);
              *(undefined2 *)(param_1 + 0xde) = *(undefined2 *)((long)plVar9 + 0x16);
              return 0;
            }
            uVar3 = *(undefined4 *)((long)plVar9 + 0x1c);
            *(undefined4 *)(param_1 + 200) = uVar3;
            lVar11 = plVar9[4];
            *(char *)(param_1 + 0xcc) = (char)lVar11;
            uVar6 = *(undefined1 *)((long)plVar9 + 0x21);
            *(undefined1 *)(param_1 + 0xcd) = uVar6;
            uVar1 = *(undefined1 *)((long)plVar9 + 0x22);
            *(undefined1 *)(param_1 + 0xcf) = 1;
            *(undefined1 *)(param_1 + 0xce) = uVar1;
            *(long *)(param_1 + 0xd0) = plVar9[1];
            *(short *)(param_1 + 0xd8) = (short)plVar9[2];
            *(undefined2 *)(param_1 + 0xda) = *(undefined2 *)((long)plVar9 + 0x12);
            *(undefined2 *)(param_1 + 0xdc) = *(undefined2 *)((long)plVar9 + 0x14);
            sVar13 = *(short *)((long)plVar9 + 0x16);
            *(short *)(param_1 + 0xde) = sVar13;
            if (sVar13 == 0) {
              getSubsystemFromPCIECapabilities
                        (uVar3,(char)lVar11,uVar6,uVar1,param_1 + 0xde,param_1 + 0xdc);
            }
            bVar4 = true;
            plVar14 = *(long **)(param_1 + 0xe8);
            goto LAB_00475d8a;
          }
          plVar9 = (long *)*plVar9;
        } while (plVar9 != (long *)0x0);
        uVar8 = (int)uVar12 + 1;
        uVar12 = (ulong)uVar8;
        sVar13 = (&chipsetInfo)[uVar12 * 0xc];
        plVar9 = plVar14;
      } while (sVar13 != 0);
    }
    uVar7 = (undefined2)uVar8;
    bVar4 = false;
    if (param_2 == (undefined2 *)0x0) goto LAB_00475d8a;
LAB_00475d7a:
    *param_2 = uVar7;
  }
  bVar4 = false;
  plVar14 = *(long **)(param_1 + 0xe8);
LAB_00475d8a:
  psVar10 = local_40;
  if (plVar14 == (long *)0x0) {
    do {
      psVar10 = psVar10 + 1;
    } while (local_40 + 3 != psVar10);
  }
  else {
    do {
      sVar13 = *psVar10;
      plVar9 = plVar14;
      do {
        if (*(short *)((long)plVar9 + 0x24) == sVar13) {
          *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)((long)plVar9 + 0x1c);
          *(char *)(param_1 + 0x9c) = (char)plVar9[4];
          *(undefined1 *)(param_1 + 0x9d) = *(undefined1 *)((long)plVar9 + 0x21);
          uVar6 = *(undefined1 *)((long)plVar9 + 0x22);
          *(undefined1 *)(param_1 + 0x9f) = 1;
          *(undefined1 *)(param_1 + 0x9e) = uVar6;
          *(long *)(param_1 + 0xa0) = plVar9[1];
          *(short *)(param_1 + 0xa8) = (short)plVar9[2];
          *(undefined2 *)(param_1 + 0xaa) = *(undefined2 *)((long)plVar9 + 0x12);
          *(undefined2 *)(param_1 + 0xac) = *(undefined2 *)((long)plVar9 + 0x14);
          *(undefined2 *)(param_1 + 0xae) = *(undefined2 *)((long)plVar9 + 0x16);
          *(char *)(param_1 + 0xb0) = (char)plVar9[3];
          if (!bVar4) {
            uVar3 = *(undefined4 *)((long)plVar9 + 0x1c);
            *(undefined4 *)(param_1 + 200) = uVar3;
            lVar11 = plVar9[4];
            *(char *)(param_1 + 0xcc) = (char)lVar11;
            uVar6 = *(undefined1 *)((long)plVar9 + 0x21);
            *(undefined1 *)(param_1 + 0xcd) = uVar6;
            uVar1 = *(undefined1 *)((long)plVar9 + 0x22);
            *(undefined1 *)(param_1 + 0xcf) = 1;
            *(undefined1 *)(param_1 + 0xce) = uVar1;
            *(long *)(param_1 + 0xd0) = plVar9[1];
            *(short *)(param_1 + 0xd8) = (short)plVar9[2];
            *(undefined2 *)(param_1 + 0xda) = *(undefined2 *)((long)plVar9 + 0x12);
            *(undefined2 *)(param_1 + 0xdc) = *(undefined2 *)((long)plVar9 + 0x14);
            sVar2 = *(short *)((long)plVar9 + 0x16);
            *(short *)(param_1 + 0xde) = sVar2;
            if (sVar2 == 0) {
              getSubsystemFromPCIECapabilities
                        (uVar3,(char)lVar11,uVar6,uVar1,param_1 + 0xde,param_1 + 0xdc);
            }
          }
          nvDbg_Printf("src/kernel/platform/chipset/chipset.c",0x1bb,
                       "clFindFHBAndGetChipsetInfoIndex_IMPL",1,
                       "NVRM: DeviceId[%x] VendorID[%x] BDF[%x:%x:%x] SubClassId[%x] device found.\n"
                       ,(short)plVar9[2],*(undefined2 *)((long)plVar9 + 0x12),(char)plVar9[4],
                       *(undefined1 *)((long)plVar9 + 0x21),*(undefined1 *)((long)plVar9 + 0x22),
                       sVar13);
          return 0;
        }
        plVar9 = (long *)*plVar9;
      } while (plVar9 != (long *)0x0);
      psVar10 = psVar10 + 1;
    } while (local_40 + 3 != psVar10);
  }
  uVar15 = 0;
  nvDbg_Printf("src/kernel/platform/chipset/chipset.c",0x1ca,"clFindFHBAndGetChipsetInfoIndex_IMPL",
               4,"NVRM: NVRM : This is Bad. FHB/P2P/3DCTRL not found in cached bus topology!!!\n");
  nvAssertFailedNoLog(&DAT_00d894de,"src/kernel/platform/chipset/chipset.c",0x1ce);
  do {
    cVar16 = '\0';
    do {
      lVar11 = osPciInitHandle(0,uVar15 & 0xff,cVar16,0,&local_44,&local_42);
      if (((lVar11 != 0) && ((ushort)(local_44 - 1U) < 0xfffe)) &&
         ((cVar5 = osPciReadByte(lVar11,0xb), cVar5 == '\x06' &&
          (cVar5 = osPciReadByte(lVar11,10), cVar5 == '\0')))) {
        uVar7 = osPciReadWord(lVar11,0x2e);
        uVar8 = osPciReadWord(lVar11,0x2c);
        uVar6 = osPciReadByte(lVar11,8);
        *(undefined4 *)(param_1 + 0x98) = 0;
        *(char *)(param_1 + 0x9c) = (char)uVar15;
        *(char *)(param_1 + 0x9d) = cVar16;
        *(long *)(param_1 + 0xa0) = lVar11;
        uVar12 = (ulong)CONCAT24(uVar7,CONCAT22(local_44,local_42)) | (ulong)uVar8 << 0x30;
        *(undefined1 *)(param_1 + 0xb0) = uVar6;
        *(undefined2 *)(param_1 + 0x9e) = 0x100;
        *(ulong *)(param_1 + 0xa8) = uVar12;
        if (bVar4) {
          return 0;
        }
        *(undefined4 *)(param_1 + 200) = 0;
        *(char *)(param_1 + 0xcc) = (char)uVar15;
        *(char *)(param_1 + 0xcd) = cVar16;
        *(undefined2 *)(param_1 + 0xce) = 0x100;
        *(long *)(param_1 + 0xd0) = lVar11;
        *(ulong *)(param_1 + 0xd8) = uVar12;
        return 0;
      }
      cVar16 = cVar16 + '\x01';
    } while (cVar16 != ' ');
    uVar15 = uVar15 + 1;
    if (uVar15 == 0x100) {
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined8 *)(param_1 + 0x98) = 0x100000000000000;
      *(undefined8 *)(param_1 + 0xa8) = 0xffffffffffffffff;
      nvAssertFailedNoLog(&DAT_00d894de,"src/kernel/platform/chipset/chipset.c",0x22d);
      return 0x56;
    }
  } while( true );
}


// ===== 004762f0 clIsL1SupportedForUpstreamPort_IMPL =====

byte clIsL1SupportedForUpstreamPort_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined1 local_c;
  byte local_b;
  
  lVar2 = param_1 + 0x1d58;
  if (*(char *)(param_1 + 0x1d5f) == '\0') {
    if (*(char *)(param_1 + 0x1d8f) == '\0') {
      return 0;
    }
    lVar2 = param_1 + 0x1d88;
  }
  iVar1 = clPcieReadPortConfigReg_IMPL(param_1,param_2,lVar2,0x10c,&local_c);
  if (iVar1 != 0) {
    return 0;
  }
  return local_b >> 3 & 1;
}


// ===== 00476350 clInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 clInit_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  clInitMappingPciBusDevice_IMPL();
  iVar1 = (**(code **)(param_1 + 0x168))(param_1);
  if (iVar1 != 3) {
    return 0;
  }
  uVar2 = clInitPcie_IMPL(param_1,param_2);
  return uVar2;
}


// ===== 004763a0 clTeardown_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong clTeardown_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  
  clFreeBusTopologyCache_IMPL(param_2);
  iVar1 = (**(code **)(param_1 + 0x168))(param_1);
  if (iVar1 != 3) {
    uVar3 = 0;
    if ((iVar1 != 4) && (uVar3 = 0, iVar1 != 1)) {
      uVar3 = 0xffff;
    }
    return (ulong)uVar3;
  }
  uVar2 = clTeardownPcie_IMPL(param_1,param_2);
  return uVar2;
}


// ===== 00476400 clSyncWithGsp_IMPL =====

void clSyncWithGsp_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  
  *(undefined8 *)(param_2 + 0x70) = 0;
  uVar1 = (ulong)(*(char *)(param_1 + 0x48) != '\0');
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x4e) != '\0') * 2 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x49) != '\0') << 2 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x4a) != '\0') << 3 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x4b) != '\0') << 4 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x4c) != '\0') << 5 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x4d) != '\0') << 6 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x4f) != '\0') << 7 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x50) != '\0') << 8 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x51) != '\0') << 9 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x52) != '\0') << 10 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x53) != '\0') << 0xb | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x54) != '\0') << 0xc | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x55) != '\0') << 0xd | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x56) != '\0') << 0xe | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x57) != '\0') << 0xf | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x58) != '\0') << 0x10 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x59) != '\0') << 0x11 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x5a) != '\0') << 0x12 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x5b) != '\0') << 0x13 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x5c) != '\0') << 0x14 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x5d) != '\0') << 0x15 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x5e) != '\0') << 0x16 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x5f) != '\0') << 0x17 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x60) != '\0') << 0x18 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x61) != '\0') << 0x19 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x62) != '\0') << 0x1a | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 99) != '\0') << 0x1b | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 100) != '\0') << 0x1c | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x65) != '\0') << 0x1d | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x66) != '\0') << 0x1e | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x67) != '\0') << 0x1f | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x68) != '\0') << 0x20 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x69) != '\0') << 0x21 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x6b) != '\0') << 0x22 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x6c) != '\0') << 0x23 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  uVar1 = (ulong)(*(char *)(param_1 + 0x6d) != '\0') << 0x24 | uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1;
  *(ulong *)(param_2 + 0x70) = uVar1 | (ulong)(*(char *)(param_1 + 0x6a) != '\0') << 0x25;
  *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined8 *)(param_2 + 0x8a) = *(undefined8 *)(param_1 + 0xa8);
  *(undefined2 *)(param_2 + 0x92) = *(undefined2 *)(param_1 + 0xb0);
  *(undefined8 *)(param_2 + 0x94) = *(undefined8 *)(param_1 + 0xd8);
  *(undefined2 *)(param_2 + 0x9c) = *(undefined2 *)(param_1 + 0xe0);
  return;
}


// ===== 00476740 Intel_A70D_setupFunc =====

undefined8 Intel_A70D_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x52) = 1;
  return 0;
}


// ===== 00476750 Intel_1C4B_setupFunc =====

undefined8 Intel_1C4B_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x4d) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  *(undefined2 *)(param_1 + 0x53) = 0x101;
  *(undefined1 *)(param_1 + 0x51) = 1;
  return 0;
}


// ===== 00476770 Intel_1C46_setupFunc =====

undefined8 Intel_1C46_setupFunc(void)

{
  return 0;
}


// ===== 00476780 Intel_1D40_setupFunc =====

undefined8 Intel_1D40_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x60) = 1;
  if (*(short *)(param_1 + 0xa8) == 0xe00) {
    *(undefined1 *)(param_1 + 0x61) = 1;
  }
  *(undefined1 *)(param_1 + 0x51) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  *(undefined1 *)(param_1 + 0x53) = 1;
  return 0;
}


// ===== 004767b0 Intel_8D47_setupFunc =====

undefined8 Intel_8D47_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x51) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  *(undefined1 *)(param_1 + 0x53) = 1;
  *(undefined1 *)(param_1 + 0x65) = 1;
  return 0;
}


// ===== 004767d0 Intel_8D44_setupFunc =====

undefined8 Intel_8D44_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x51) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  *(undefined1 *)(param_1 + 0x53) = 1;
  return 0;
}


// ===== 004767f0 Intel_8C4B_setupFunc =====

undefined8 Intel_8C4B_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x53) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  return 0;
}


// ===== 00476810 Intel_4381_setupFunc =====

undefined8 Intel_4381_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x6b) = 1;
  if (*(short *)(param_1 + 0xde) == 0x1043) {
    *(undefined1 *)(param_1 + 0x6c) = 1;
  }
  return 0;
}


// ===== 00476830 Intel_7A82_setupFunc =====

undefined8 Intel_7A82_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x6b) = 1;
  return 0;
}


// ===== 00476840 AMD_RS780_setupFunc =====

undefined8 AMD_RS780_setupFunc(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0xffff;
  if (*(char *)(param_1 + 0x9f) != '\0') {
    *(undefined1 *)(param_1 + 0x4f) = 1;
    uVar1 = 0;
    *(undefined1 *)(param_1 + 0x51) = 1;
  }
  return uVar1;
}


// ===== 00476860 AMD_FX790_setupFunc =====

undefined8 AMD_FX790_setupFunc(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0xffff;
  if (*(char *)(param_1 + 0x9f) != '\0') {
    *(undefined2 *)(param_1 + 0x4f) = 0x101;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00476880 ATI_RD890_setupFunc =====

undefined8 ATI_RD890_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x5a) = 1;
  return 0;
}


// ===== 00476890 AMD_FX890_setupFunc =====

undefined8 AMD_FX890_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x4f) = 1;
  return 0;
}


// ===== 004768a0 ATI_FX990_setupFunc =====

undefined8 ATI_FX990_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x62) = 1;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  return 0;
}


// ===== 004768b0 AMD_X370_setupFunc =====

undefined8 AMD_X370_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x6a) = 1;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  return 0;
}


// ===== 004768c0 VIA_VX900_setupFunc =====

undefined8 VIA_VX900_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x56) = 1;
  return 0;
}


// ===== 004768d0 APM_Storm_setupFunc =====

undefined8 APM_Storm_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x66) = 1;
  return 0;
}


// ===== 004768e0 Marvell_ThunderX2_setupFunc =====

undefined8 Marvell_ThunderX2_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 004768f0 Mellanox_BlueField3_setupFunc =====

undefined8 Mellanox_BlueField3_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x69) = 1;
  return 0;
}


// ===== 00476900 Ampere_Altra_setupFunc =====

undefined8 Ampere_Altra_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  if (*(char *)(*(long *)(param_1 + 0xe8) + 0x18) == '\0') {
    *(undefined1 *)(param_1 + 0x69) = 1;
  }
  return 0;
}


// ===== 00476920 Intel_4003_setupFunc =====

undefined8 Intel_4003_setupFunc(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  *(undefined1 *)(param_1 + 0x48) = 0;
  lVar2 = osPciInitHandle(0,0,0x10,0,0,0);
  if (lVar2 == 0) {
    return 0xffff;
  }
  uVar3 = osPciReadDword(lVar2,100);
  if ((int)uVar3 == -1) {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_info.c",0x1d6,"Intel_4003_setupFunc",4,
                 "NVRM: Can\'t read HECBASE register on Intel SkullTrail!\n");
  }
  else {
    iVar1 = clInsertPcieConfigSpaceBase_IMPL(param_1,(uVar3 & 0xfff000) << 0x10,0,0,0xff);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
  }
  iVar1 = clPcieReadDword_IMPL
                    (param_1,*(undefined4 *)(param_1 + 0x98),*(undefined1 *)(param_1 + 0x9c),
                     *(undefined1 *)(param_1 + 0x9d),*(undefined1 *)(param_1 + 0x9e),0);
  if (iVar1 != CONCAT22(*(undefined2 *)(param_1 + 0xa8),*(undefined2 *)(param_1 + 0xaa))) {
    **(undefined8 **)(param_1 + 0xc0) = 0xe0000000;
    iVar1 = clPcieReadDword_IMPL
                      (param_1,*(undefined4 *)(param_1 + 0x98),*(undefined1 *)(param_1 + 0x9c),
                       *(undefined1 *)(param_1 + 0x9d),*(undefined1 *)(param_1 + 0x9e),0);
    if (iVar1 != CONCAT22(*(undefined2 *)(param_1 + 0xa8),*(undefined2 *)(param_1 + 0xaa))) {
      return 0xffff;
    }
  }
  *(undefined1 *)(param_1 + 0x5f) = 1;
  return 0;
}


// ===== 00476a80 ATI_RS480_setupFunc =====

undefined8 ATI_RS480_setupFunc(long param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0xffff;
  }
  cVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),8);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0xb4) = 0x1038;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xb4) = 0x1037;
  return 0;
}


// ===== 00476af0 ATI_RS400_setupFunc =====

undefined8 ATI_RS400_setupFunc(long param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0xffff;
  }
  uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0x9c);
  if ((uVar1 & 1) == 0) {
    *(undefined4 *)(param_1 + 0xb4) = 0x1036;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xb4) = 0x1035;
  return 0;
}


// ===== 00476b60 SiS_656_setupFunc =====

undefined8 SiS_656_setupFunc(long param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0xffff;
  }
  uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0xe0);
  if ((uVar1 & 0xf) != 0) {
    iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,(ulong)(uVar1 & 0xf) << 0x1c,0,0,0xff);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(undefined1 *)(param_1 + 0x5f) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 0x5f) = 1;
  return 0;
}


// ===== 00476be0 Intel_2A40_setupFunc =====

undefined8 Intel_2A40_setupFunc(long param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0x60);
    if ((uVar1 & 0xfff00000) != 0) {
      iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,uVar1 & 0xfff00000,0,0,0xff);
      if ((iVar2 == 0) && (*(undefined1 *)(param_1 + 0x48) = 1, 4 < *(byte *)(param_1 + 0xb0))) {
        *(undefined1 *)(param_1 + 0x4a) = 1;
      }
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    return 0;
  }
  return 0xffff;
}


// ===== 00476c60 Intel_25XX_setupFunc =====

undefined8 Intel_25XX_setupFunc(long param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0xffff;
  }
  uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0x48);
  if ((uVar1 & 0xf0000000) != 0) {
    iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,uVar1 & 0xf0000000,0,0,0xff);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(undefined1 *)(param_1 + 0x5f) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 0x5f) = 1;
  return 0;
}


// ===== 00476ce0 Intel_25E0_setupFunc =====

undefined8 Intel_25E0_setupFunc(long param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    iVar1 = clInsertPcieConfigSpaceBase_IMPL(param_1,0xe0000000,0,0,0xff);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    return 0;
  }
  return 0xffff;
}


// ===== 00476d30 Intel_359E_setupFunc =====

undefined8 Intel_359E_setupFunc(long param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0xffff;
  }
  uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0xcc);
  if ((uVar1 & 0xf0000000) != 0) {
    iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,uVar1 & 0xf0000000,0,0,0xff);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(undefined1 *)(param_1 + 0x5f) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 0x5f) = 1;
  return 0;
}


// ===== 00476db0 Intel_29XX_setupFunc.part.0 =====

undefined8 Intel_29XX_setupFunc_part_0(long param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0x60);
  if ((uVar1 & 0xfff00000) != 0) {
    iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,uVar1 & 0xfff00000,0,0,0xff);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(undefined1 *)(param_1 + 0x5f) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 0x5f) = 1;
  return 0;
}


// ===== 00476e10 Intel_29E0_setupFunc =====

undefined8 Intel_29E0_setupFunc(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar2 = 0xffff;
  if (*(char *)(param_1 + 0x9f) != '\0') {
    Intel_29XX_setupFunc_part_0();
    uVar2 = 0;
  }
  uVar1 = clPcieReadDword_IMPL
                    (param_1,*(undefined4 *)(param_1 + 0x98),*(undefined1 *)(param_1 + 0x9c),
                     *(undefined1 *)(param_1 + 0x9d),*(undefined1 *)(param_1 + 0x9e),0xe8);
  if ((uVar1 & 0x2000000) == 0) {
    *(undefined1 *)(param_1 + 0x57) = 1;
  }
  *(undefined1 *)(param_1 + 0x5c) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  return uVar2;
}


// ===== 00476e80 Intel_29X0_setupFunc =====

undefined8 Intel_29X0_setupFunc(long param_1)

{
  if (*(char *)(param_1 + 0x9f) != '\0') {
    Intel_29XX_setupFunc_part_0();
    *(undefined2 *)(param_1 + 0x4f) = 0x101;
    *(undefined1 *)(param_1 + 0x51) = 1;
    return 0;
  }
  *(undefined1 *)(param_1 + 0x51) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  return 0xffff;
}


// ===== 00476ed0 Nvidia_TH500_setupFunc =====

undefined8 Nvidia_TH500_setupFunc(long param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    iVar1 = clInsertPcieConfigSpaceBase_IMPL(param_1,0,0,0,0xff);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    *(undefined1 *)(param_1 + 0x4d) = 1;
    *(undefined1 *)(param_1 + 0x68) = 1;
    *(undefined1 *)(param_1 + 0x6d) = 1;
    *(undefined1 *)(param_1 + 0x4f) = 1;
    return 0;
  }
  return 0xffff;
}


// ===== 00476f30 Nvidia_T194_setupFunc =====

undefined8 Nvidia_T194_setupFunc(long param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    iVar1 = clInsertPcieConfigSpaceBase_IMPL(param_1,0,0,0,0xff);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    *(undefined1 *)(param_1 + 0x4d) = 1;
    *(undefined1 *)(param_1 + 0x4f) = 1;
    *(undefined1 *)(param_1 + 0x68) = 1;
    return 0;
  }
  return 0xffff;
}


// ===== 00476f90 Intel_2E00_setupFunc =====

undefined8 Intel_2E00_setupFunc(long param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0x60);
    if ((uVar1 & 0xfff00000) != 0) {
      iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,uVar1 & 0xfff00000,0,0,0xff);
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x48) = 1;
      }
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    *(undefined2 *)(param_1 + 0x4f) = 0x101;
    return 0;
  }
  return 0xffff;
}


// ===== 00477010 Intel_1E10_setupFunc =====

undefined8 Intel_1E10_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x4f) = 1;
  if ((*(short *)(param_1 + 0xde) == 0x1458) && (*(ushort *)(param_1 + 0xdc) - 0x5000 < 2)) {
    *(undefined1 *)(param_1 + 100) = 1;
    return 0;
  }
  return 0;
}


// ===== 00477050 Intel_Core_Nehalem_Processor_setupFunc.isra.0 =====

void Intel_Core_Nehalem_Processor_setupFunc_isra_0(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  bool bVar5;
  short local_3c;
  ushort local_3a [5];
  
  uVar4 = 0xff;
  *(undefined1 *)(param_1 + 0x48) = 0;
  do {
    lVar3 = osPciInitHandle(0,uVar4 & 0xff,0,1,&local_3c,local_3a);
    if (((lVar3 != 0) && (local_3c == -0x7f7a)) &&
       (((local_3a[0] & 0xff7f) == 0x2c01 || ((local_3a[0] & 0xffbf) == 0x2d01)))) {
      uVar1 = osPciReadDword(lVar3,0x50);
      lVar3 = osPciReadDword(lVar3,0x54);
      if (((uVar1 & 1) != 0) && ((0xc1UL >> (uVar1 >> 1 & 7) & 1) != 0)) {
        iVar2 = clInsertPcieConfigSpaceBase_IMPL
                          (param_1,(lVar3 << 0x20 | (ulong)uVar1) & 0xfffff00000,0,0,0xff);
        if (iVar2 != 0) {
          return;
        }
        *(undefined1 *)(param_1 + 0x48) = 1;
        return;
      }
    }
    bVar5 = uVar4 == 0;
    uVar4 = uVar4 - 1;
    if (bVar5) {
      return;
    }
  } while( true );
}


// ===== 00477140 Intel_3400_setupFunc =====

undefined8 Intel_3400_setupFunc(long param_1)

{
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  Intel_Core_Nehalem_Processor_setupFunc_isra_0();
  return 0;
}


// ===== 00477160 Intel_3B42_setupFunc =====

undefined8 Intel_3B42_setupFunc(long param_1)

{
  long lVar1;
  short local_1e;
  short local_1c;
  short local_1a [5];
  
  lVar1 = osPciInitHandle(0,0,0x1f,0,0,&local_1e);
  if (lVar1 != 0) {
    if (local_1e == 0x3b08) {
      *(undefined1 *)(param_1 + 0x5e) = 1;
    }
    else if (local_1e != 0x3b06) goto LAB_0047719c;
    lVar1 = osPciInitHandle(0,0,0,0,local_1a,&local_1c);
    if (((lVar1 != 0) && (local_1a[0] == -0x7f7a)) && (local_1c == 0x40)) {
      *(undefined1 *)(param_1 + 0x4f) = 1;
    }
  }
LAB_0047719c:
  Intel_Core_Nehalem_Processor_setupFunc_isra_0(param_1);
  return 0;
}


// ===== 004771f0 Intel_0040_setupFunc =====

undefined8 Intel_0040_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x4d) = 1;
  Intel_Core_Nehalem_Processor_setupFunc_isra_0();
  return 0;
}


// ===== 00477210 Intel_1C10_setupFunc =====

undefined8 Intel_1C10_setupFunc(void)

{
  return 0;
}


// ===== 00477220 Intel_8CC4_setupFunc =====

undefined8 Intel_8CC4_setupFunc(void)

{
  return 0;
}


// ===== 00477230 Intel_A145_setupFunc =====

undefined8 Intel_A145_setupFunc(void)

{
  return 0;
}


// ===== 00477240 Intel_A2C5_setupFunc =====

undefined8 Intel_A2C5_setupFunc(void)

{
  return 0;
}


// ===== 00477250 Intel_A242_setupFunc =====

undefined8 Intel_A242_setupFunc(void)

{
  return 0;
}


// ===== 00477260 Intel_A2D2_setupFunc =====

undefined8 Intel_A2D2_setupFunc(void)

{
  return 0;
}


// ===== 00477270 Intel_A2C9_setupFunc =====

undefined8 Intel_A2C9_setupFunc(void)

{
  return 0;
}


// ===== 00477280 Intel_A301_setupFunc =====

undefined8 Intel_A301_setupFunc(void)

{
  return 0;
}


// ===== 00477290 Intel_0685_setupFunc =====

undefined8 Intel_0685_setupFunc(void)

{
  return 0;
}


// ===== 004772a0 ATI_RD870_setupFunc =====

undefined8 ATI_RD870_setupFunc(void)

{
  return 0;
}


// ===== 004772b0 ARMV8_generic_setupFunc =====

undefined8 ARMV8_generic_setupFunc(void)

{
  return 0;
}


// ===== 004772c0 Qualcomm_Snapdragon_setupFunc =====

undefined8 Qualcomm_Snapdragon_setupFunc(void)

{
  return 0;
}


// ===== 004772d0 PLDA_XpressRichAXI_setupFunc =====

undefined8 PLDA_XpressRichAXI_setupFunc(void)

{
  return 0;
}


// ===== 004772e0 Intel_7A04_setupFunc =====

undefined8 Intel_7A04_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x6b) = 1;
  return 0;
}


// ===== 004772f0 Intel_7D06_setupFunc =====

undefined8 Intel_7D06_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x6b) = 1;
  return 0;
}


// ===== 00477300 ATI_RX780_setupFunc =====

undefined8 ATI_RX780_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x5a) = 1;
  return 0;
}


// ===== 00477310 QEMU_setupFunc =====

undefined8 QEMU_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477320 Ampere_eMag_setupFunc =====

undefined8 Ampere_eMag_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477330 Huawei_Kunpeng920_setupFunc =====

undefined8 Huawei_Kunpeng920_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477340 Mellanox_BlueField_setupFunc =====

undefined8 Mellanox_BlueField_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477350 Amazon_Gravitron2_setupFunc =====

undefined8 Amazon_Gravitron2_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477360 Fujitsu_A64FX_setupFunc =====

undefined8 Fujitsu_A64FX_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477370 Arm_NeoverseN1_setupFunc =====

undefined8 Arm_NeoverseN1_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477380 Ampere_AmpereOne_setupFunc =====

undefined8 Ampere_AmpereOne_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 00477390 Riscv_generic_setupFunc =====

undefined8 Riscv_generic_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x68) = 1;
  return 0;
}


// ===== 004773a0 AMD_14D8_setupFunc =====

undefined8 AMD_14D8_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x52) = 1;
  return 0;
}


// ===== 004773b0 Intel_1C49_setupFunc =====

undefined8 Intel_1C49_setupFunc(long param_1)

{
  *(undefined1 *)(param_1 + 0x4d) = 1;
  *(undefined2 *)(param_1 + 0x4f) = 0x101;
  *(undefined2 *)(param_1 + 0x53) = 0x101;
  *(undefined1 *)(param_1 + 0x51) = 1;
  return 0;
}


// ===== 004773d0 Nvidia_T210_setupFunc =====

undefined8 Nvidia_T210_setupFunc(long param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    iVar1 = clInsertPcieConfigSpaceBase_IMPL(param_1,0,0,0,0xff);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    *(undefined1 *)(param_1 + 0x4d) = 1;
    *(undefined1 *)(param_1 + 0x68) = 0;
    *(undefined1 *)(param_1 + 0x4f) = 1;
    return 0;
  }
  return 0xffff;
}


// ===== 00477430 Intel_4000_setupFunc =====

undefined8 Intel_4000_setupFunc(long param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x9f) != '\0') {
    iVar1 = clInsertPcieConfigSpaceBase_IMPL(param_1,0xe0000000,0,0,0xff);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    *(undefined1 *)(param_1 + 0x5f) = 1;
    return 0;
  }
  return 0xffff;
}


// ===== 00477480 Intel_27XX_setupFunc =====

undefined8 Intel_27XX_setupFunc(long param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0xffff;
  }
  uVar1 = osPciReadDword(*(undefined8 *)(param_1 + 0xa0),0x48);
  if ((uVar1 & 0xf0000000) != 0) {
    iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,uVar1 & 0xf0000000,0,0,0xff);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(undefined1 *)(param_1 + 0x5f) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 0x5f) = 1;
  return 0;
}


// ===== 00477500 csGetInfoStrings =====

void csGetInfoStrings(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined8 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  ulong uVar4;
  uint uVar5;
  
  iVar2 = portStringLength("Unknown");
  iVar2 = iVar2 + 1;
  if (*(char *)(param_1 + 0xcf) == '\0') {
    portStringCopy(param_2,iVar2,"Unknown",iVar2);
    portStringCopy(param_3,iVar2,"Unknown",iVar2);
    portStringCopy(param_4,iVar2,"Unknown",iVar2);
    param_4 = param_5;
  }
  else {
    if (DAT_0059eec4 != 0) {
      psVar3 = &chipsetInfo;
      uVar4 = 0;
      do {
        if ((*(short *)(param_1 + 0xda) == *psVar3) && (*(short *)(param_1 + 0xd8) == psVar3[1])) {
          portStringCopy(param_2,param_6,(&PTR_s_Grantsdale_0059eec8)[uVar4 * 3],param_6);
          if ((&DAT_0059eec4)[uVar4 * 6] != 0) goto LAB_004775d7;
          break;
        }
        piVar1 = (int *)(psVar3 + 0xe);
        psVar3 = psVar3 + 0xc;
        uVar4 = (ulong)((int)uVar4 + 1);
      } while (*piVar1 != 0);
    }
    portStringCopy(param_2,iVar2,"Unknown",iVar2);
LAB_004775d7:
    if (vendorName != 0) {
      uVar4 = 0;
      uVar5 = vendorName;
      do {
        if (*(ushort *)(param_1 + 0xda) == uVar5) {
          portStringCopy(param_3,param_6,(&PTR_s_NVIDIA_0059ece8)[(uVar4 & 0xffffffff) * 2],param_6)
          ;
          if ((&vendorName)[(uVar4 & 0xffffffff) * 4] != 0) goto LAB_00477648;
          break;
        }
        uVar4 = uVar4 + 1;
        uVar5 = (&vendorName)[uVar4 * 4];
      } while (uVar5 != 0);
    }
    portStringCopy(param_3,iVar2,"Unknown",iVar2);
LAB_00477648:
    if (vendorName != 0) {
      uVar4 = 0;
      uVar5 = vendorName;
      do {
        if (*(ushort *)(param_1 + 0xde) == uVar5) {
          portStringCopy(param_5,param_6,(&PTR_s_NVIDIA_0059ece8)[(uVar4 & 0xffffffff) * 2],param_6)
          ;
          if ((&vendorName)[(uVar4 & 0xffffffff) * 4] != 0) goto LAB_004776d2;
          break;
        }
        uVar4 = uVar4 + 1;
        uVar5 = (&vendorName)[uVar4 * 4];
      } while (uVar5 != 0);
    }
    portStringCopy(param_5,iVar2,"Unknown",iVar2);
  }
LAB_004776d2:
  portStringCopy(param_4,iVar2,"Unknown",iVar2);
  return;
}


// ===== 004777a0 _Set_ASPM_L0S_L1 =====

void _Set_ASPM_L0S_L1(long param_1,char param_2,char param_3)

{
  *(undefined1 *)(param_1 + 0x4f) = 1;
  if (param_2 != '\0') {
    *(undefined1 *)(param_1 + 0x50) = 1;
  }
  if (param_3 != '\0') {
    *(undefined1 *)(param_1 + 0x51) = 1;
  }
  return;
}


// ===== 004777c0 gpuDevIdIsMultiGpuBoard =====

char gpuDevIdIsMultiGpuBoard(short param_1,short param_2,short param_3)

{
  short *psVar1;
  char cVar2;
  
  psVar1 = &multiGpuBoards;
  cVar2 = '\0';
  do {
    if ((psVar1[4] == 0) || (psVar1[8] == 0)) {
      if (*psVar1 == 0) {
        return '\0';
      }
      if (param_1 == 0x25b6) {
        return '\x01';
      }
      cVar2 = '\x01';
    }
    else {
      if (*psVar1 == 0) {
        return '\0';
      }
      if (param_1 == 0x25b6) {
        if (cVar2 != '\0') {
          return cVar2;
        }
        if ((param_2 == 0x10de) && (param_3 == 0x14a9)) {
          return '\x01';
        }
      }
    }
    psVar1 = psVar1 + 1;
    if (psVar1 == (short *)&DAT_00d8a9e8) {
      return '\0';
    }
  } while( true );
}


// ===== 00477840 scanForRsdtXsdtTables.isra.0 =====

bool scanForRsdtXsdtTables_isra_0
               (char param_1,undefined8 param_2,ulong param_3,int *param_4,long *param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  ulong uVar4;
  char cVar5;
  
  piVar1 = (int *)osMapKernelSpace(param_2,param_3,param_1 == '\0',3);
  if (piVar1 == (int *)0x0) {
    return false;
  }
  cVar5 = '\0';
  uVar4 = 0;
  piVar2 = piVar1;
  do {
    if ((*piVar2 == 0x20445352) && (piVar2[1] == 0x20525450)) {
      piVar3 = piVar2;
      do {
        cVar5 = cVar5 + (char)*piVar3;
        piVar3 = (int *)((long)piVar3 + 1);
      } while (piVar3 != piVar2 + 5);
      if (cVar5 == '\0') {
        if (*(byte *)((long)piVar1 + uVar4 + 0xf) < 2) {
          *param_4 = *(int *)((long)piVar1 + uVar4 + 0x10);
        }
        else {
          *param_5 = CONCAT44(*(undefined4 *)((long)piVar1 + uVar4 + 0x1c),
                              *(undefined4 *)((long)piVar1 + uVar4 + 0x18));
        }
        goto LAB_004778e0;
      }
    }
    uVar4 = uVar4 + 0x10;
    piVar2 = piVar2 + 4;
    if (param_3 <= uVar4) {
LAB_004778e0:
      osUnmapKernelSpace(piVar1,param_3);
      if (*param_4 != 0) {
        return true;
      }
      return *param_5 != 0;
    }
  } while( true );
}


// ===== 00477940 objClPcieUnmapEnhCfgSpace.isra.0 =====

void objClPcieUnmapEnhCfgSpace_isra_0(long param_1)

{
  long lVar1;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c [3];
  
  lVar1 = sysGetOs_IMPL(g_pSys);
  if (*(char *)(lVar1 + 0x4d) != '\0') {
    nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                        "src/kernel/platform/chipset/chipset_pcie.c",0xbfc);
    return;
  }
  gpumgrGetGpuAttachInfo(local_24,&local_20);
  local_1c[0] = 0;
  while( true ) {
    lVar1 = gpumgrGetNextGpu(local_20,local_1c);
    if (lVar1 == 0) {
      osUnmapKernelSpace(param_1,0x1000);
      return;
    }
    if (*(long *)(lVar1 + 0x1d98) == param_1) break;
    if (param_1 == *(long *)(lVar1 + 0x1ae8)) {
      return;
    }
  }
  return;
}


// ===== 004779d0 objClPcieMapEnhCfgSpace =====

long objClPcieMapEnhCfgSpace(long param_1,int param_2,byte param_3,byte param_4,byte param_5)

{
  undefined8 uVar1;
  long lVar2;
  ulong *puVar3;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar2 = sysGetOs_IMPL(g_pSys);
  if (*(char *)(lVar2 + 0x4d) != '\0') {
    nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                        "src/kernel/platform/chipset/chipset_pcie.c",0xbc7);
    return 0;
  }
  gpumgrGetGpuAttachInfo(local_44,&local_40);
  local_3c[0] = 0;
  while( true ) {
    lVar2 = gpumgrGetNextGpu(local_40,local_3c);
    if (lVar2 == 0) {
      puVar3 = *(ulong **)(param_1 + 0xc0);
      if (puVar3 == (ulong *)0x0) {
        return 0;
      }
      while (((param_2 != (int)puVar3[1] || (param_3 < *(byte *)((long)puVar3 + 0xc))) ||
             (*(byte *)((long)puVar3 + 0xd) < param_3))) {
        puVar3 = (ulong *)puVar3[2];
        if (puVar3 == (ulong *)0x0) {
          return 0;
        }
      }
      if (*puVar3 != 0) {
        lVar2 = osMapKernelSpace((ulong)((uint)param_4 << 0xf | (uint)param_5 << 0xc |
                                        (uint)param_3 << 0x14) | *puVar3,0x1000,1,3);
        return lVar2;
      }
      return 0;
    }
    if ((((*(long *)(lVar2 + 0x1d98) != 0) && (*(int *)(lVar2 + 0x1d88) == param_2)) &&
        (*(byte *)(lVar2 + 0x1d8c) == param_3)) &&
       ((*(byte *)(lVar2 + 0x1d8d) == param_4 && (*(byte *)(lVar2 + 0x1d8e) == param_5)))) break;
    if (((*(long *)(lVar2 + 0x1ae8) != 0) && (*(char *)(lVar2 + 0x880) != '\0')) &&
       ((uVar1 = *(undefined8 *)(lVar2 + 0x878), param_2 == (int)((ulong)uVar1 >> 0x20) &&
        (((byte)((ulong)uVar1 >> 8) == param_3 && param_4 == (byte)uVar1 && (param_5 == 0)))))) {
      return *(long *)(lVar2 + 0x1ae8);
    }
  }
  return *(long *)(lVar2 + 0x1d98);
}


// ===== 00477b90 clTeardownPcie_IMPL =====

undefined8 clTeardownPcie_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = sysGetOs_IMPL(g_pSys);
  if (*(char *)(lVar1 + 0x4d) == '\0') {
    lVar1 = sysGetOs_IMPL(g_pSys);
    if (*(char *)(lVar1 + 0x4d) == '\0') {
      if (*(long *)(param_1 + 0x1d98) != 0) {
        osUnmapKernelSpace(*(long *)(param_1 + 0x1d98),0x1000);
        *(undefined8 *)(param_1 + 0x1d98) = 0;
      }
    }
    else {
      nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                          "src/kernel/platform/chipset/chipset_pcie.c",0x633);
    }
    lVar1 = sysGetOs_IMPL(g_pSys);
    if (*(char *)(lVar1 + 0x4d) == '\0') {
      if (*(long *)(param_1 + 0x1ae8) != 0) {
        osUnmapKernelSpace(*(long *)(param_1 + 0x1ae8),0x1000);
        *(undefined8 *)(param_1 + 0x1ae8) = 0;
        return 0;
      }
    }
    else {
      nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                          "src/kernel/platform/chipset/chipset_pcie.c",0x674);
    }
  }
  return 0;
}


// ===== 00477c70 clSetPortPcieCapOffset_IMPL =====

undefined8 clSetPortPcieCapOffset_IMPL(undefined8 param_1,long param_2,uint *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    return 0xffff;
  }
  uVar3 = osPciReadDword(param_2,4);
  if ((uVar3 & 0x100000) == 0) {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x6a1,"clSetPortPcieCapOffset_IMPL",4,
                 "NVRM: NVPCIE: Upstream port doesn\'t support PCI Express Capability structure. This is a violation of PCIE spec\n"
                );
    nvAssertFailedNoLog(&DAT_00d89d80,"src/kernel/platform/chipset/chipset_pcie.c",0x6a3);
  }
  else {
    bVar1 = osPciReadByte(param_2,0x34);
    while (bVar1 != 0) {
      uVar2 = osPciReadDword(param_2,(uint)bVar1);
      if ((char)uVar2 == '\x10') {
        *param_3 = (uint)bVar1;
        return 0;
      }
      bVar1 = (byte)((ushort)uVar2 >> 8);
    }
  }
  return 0xffff;
}


// ===== 00477d50 clFreeBusTopologyCache_IMPL =====

void clFreeBusTopologyCache_IMPL(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xe8);
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar2;
    portMemFree(puVar2);
    puVar2 = puVar1;
  }
  *(undefined8 *)(param_1 + 0xe8) = 0;
  return;
}


// ===== 00477da0 clStoreBusTopologyCache_IMPL =====

undefined8 clStoreBusTopologyCache_IMPL(long param_1,long param_2,int param_3,ushort param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  long lVar6;
  undefined8 *puVar7;
  char cVar8;
  char cVar9;
  ushort uVar10;
  undefined8 *local_58;
  short local_3c;
  undefined2 local_3a [5];
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x4d8) == 0)) {
    local_58 = *(undefined8 **)(param_2 + 0xe8);
    cVar8 = '\0';
    puVar7 = local_58;
  }
  else {
    local_58 = *(undefined8 **)(param_2 + 0xe8);
    cVar8 = *(char *)(*(long *)(param_1 + 0x4d8) + 0x80);
    puVar7 = local_58;
  }
  while (puVar1 = puVar7, puVar1 != (undefined8 *)0x0) {
    if (*(int *)((long)puVar1 + 0x1c) == param_3) {
      return 0;
    }
    local_58 = puVar1;
    puVar7 = (undefined8 *)*puVar1;
  }
  if (param_4 == 0) {
LAB_00477ffd:
    threadStateResetTimeout(0);
    return 0;
  }
  uVar10 = 0;
LAB_00477e20:
  cVar9 = '\0';
LAB_00477e33:
  cVar3 = '\0';
  do {
    while (lVar6 = osPciInitHandle(param_3,uVar10 & 0xff,cVar9,cVar3,&local_3c,local_3a), lVar6 == 0
          ) {
      if (cVar3 == '\0') goto LAB_00477fc9;
LAB_00477f67:
      if (cVar3 == '\a') goto LAB_00477fc9;
      cVar3 = cVar3 + '\x01';
    }
    if (0xfffd < (ushort)(local_3c - 1U)) break;
    uVar4 = osPciReadWord(lVar6,10);
    puVar7 = (undefined8 *)portMemAllocNonPaged(0x28);
    if (puVar7 == (undefined8 *)0x0) {
      nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0xa61,"clStoreBusTopologyCache_IMPL"
                   ,4,"NVRM: Buffer Allocation for clStoreBusTopologyCache FAILED\n");
      puVar7 = *(undefined8 **)(param_2 + 0xe8);
      while (puVar7 != (undefined8 *)0x0) {
        puVar1 = (undefined8 *)*puVar7;
        portMemFree(puVar7);
        puVar7 = puVar1;
      }
      *(undefined8 *)(param_2 + 0xe8) = 0;
      return 0x1a;
    }
    portMemSet(puVar7,0,0x28);
    if (local_58 == (undefined8 *)0x0) {
      *(undefined8 **)(param_2 + 0xe8) = puVar7;
    }
    else {
      *local_58 = puVar7;
    }
    puVar7[1] = lVar6;
    *puVar7 = 0;
    *(int *)((long)puVar7 + 0x1c) = param_3;
    *(char *)((long)puVar7 + 0x21) = cVar9;
    *(char *)(puVar7 + 4) = (char)uVar10;
    *(char *)((long)puVar7 + 0x22) = cVar3;
    *(ushort *)((long)puVar7 + 0x24) = uVar4;
    *(uint *)(puVar7 + 2) = CONCAT22(local_3c,local_3a[0]);
    uVar5 = osPciReadWord(lVar6,0x2c);
    *(undefined2 *)((long)puVar7 + 0x16) = uVar5;
    uVar5 = osPciReadWord(lVar6,0x2e);
    *(undefined2 *)((long)puVar7 + 0x14) = uVar5;
    uVar2 = osPciReadByte(lVar6,8);
    *(undefined1 *)(puVar7 + 3) = uVar2;
    if (((uVar4 & 0xfffb) == 0x600) || ((cVar8 != '\0' && (uVar4 == 0x302)))) {
      uVar2 = osPciReadByte(lVar6,0x19);
      *(undefined1 *)((long)puVar7 + 0x23) = uVar2;
      *(undefined1 *)((long)puVar7 + 0x26) = 0;
    }
    else {
      *(undefined1 *)((long)puVar7 + 0x26) = 1;
    }
    local_58 = puVar7;
    if (cVar3 != '\0') goto LAB_00477f67;
    cVar3 = osPciReadByte(lVar6,0xe);
    if (-1 < cVar3) break;
    cVar3 = '\x01';
  } while( true );
LAB_00477fc9:
  cVar9 = cVar9 + '\x01';
  if (cVar9 == ' ') goto code_r0x00477fd7;
  goto LAB_00477e33;
code_r0x00477fd7:
  uVar10 = uVar10 + 1;
  if ((int)(uint)param_4 <= (int)(short)uVar10) goto LAB_00477ffd;
  goto LAB_00477e20;
}


// ===== 00478100 clFindP2PBrdg_IMPL =====

undefined8
clFindP2PBrdg_IMPL(long param_1,int param_2,byte param_3,byte *param_4,undefined1 *param_5,
                  undefined1 *param_6,undefined2 *param_7,undefined2 *param_8)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  ushort local_4a;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  gpumgrGetGpuAttachInfo(&local_44,&local_40);
  local_3c[0] = 0;
  lVar4 = gpumgrGetNextGpu(local_40,local_3c);
  if (((lVar4 == 0) || (local_4a = 0x100, *(char *)(lVar4 + 0x490e) != '\0')) &&
     (local_4a = (ushort)param_3, 1 < local_44)) {
    puVar1 = *(undefined8 **)(param_1 + 0xe8);
    while (puVar1 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar1;
      portMemFree(puVar1);
      puVar1 = puVar2;
    }
    *(undefined8 *)(param_1 + 0xe8) = 0;
  }
  iVar3 = clStoreBusTopologyCache_IMPL(lVar4,param_1,param_2,local_4a);
  if (iVar3 == 0) {
    for (puVar1 = *(undefined8 **)(param_1 + 0xe8); puVar1 != (undefined8 *)0x0;
        puVar1 = (undefined8 *)*puVar1) {
      if (((*(byte *)((long)puVar1 + 0x23) == param_3) && (*(int *)((long)puVar1 + 0x1c) == param_2)
          ) && ((*(byte *)(puVar1 + 4) < param_3 && (*(char *)((long)puVar1 + 0x26) == '\0')))) {
        *param_4 = *(byte *)(puVar1 + 4);
        *param_5 = *(undefined1 *)((long)puVar1 + 0x21);
        *param_6 = *(undefined1 *)((long)puVar1 + 0x22);
        *param_7 = *(undefined2 *)((long)puVar1 + 0x12);
        *param_8 = *(undefined2 *)(puVar1 + 2);
        return puVar1[1];
      }
    }
  }
  return 0;
}


// ===== 00478270 clCheckUpstreamLtrSupport_IMPL =====

undefined8 clCheckUpstreamLtrSupport_IMPL(long param_1,long param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined1 uVar7;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40 [2];
  undefined1 local_3e [2];
  int local_3c [3];
  
  uVar1 = *(undefined8 *)(param_1 + 0x878);
  *param_3 = 0;
  if (*(char *)(param_2 + 0x48) == '\0') {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x24c,"clCheckUpstreamLtrSupport_IMPL"
                 ,2,"NVRM: PCIE config space is inaccessible!\n");
  }
  else {
    uVar7 = (char)((ulong)uVar1 >> 8);
    while (lVar6 = clFindP2PBrdg_IMPL(param_2,(int)((ulong)uVar1 >> 0x20),uVar7,&local_43,&local_42,
                                      &local_41,local_40,local_3e), lVar6 != 0) {
      iVar3 = clSetPortPcieCapOffset_IMPL(param_2,lVar6,local_3c);
      iVar2 = local_3c[0];
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x263,
                     "clCheckUpstreamLtrSupport_IMPL",1,"NVRM: Capability pointer not found.\n");
        return 0x56;
      }
      uVar4 = osPciReadDword(lVar6,local_3c[0] + 0x24);
      uVar5 = osPciReadDword(lVar6,iVar2 + 0x28);
      if (((uVar4 & 0x800) == 0) || ((uVar5 & 0x400) == 0)) {
        *param_3 = 0;
        return 0x56;
      }
      uVar4 = osPciReadDword(lVar6,iVar2);
      uVar7 = local_43;
      if ((uVar4 & 0xf00000) == 0x400000) {
        *param_3 = 1;
        return 0;
      }
    }
  }
  return 0x56;
}


// ===== 00478430 clFindBrdgUpstreamPort_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long clFindBrdgUpstreamPort_IMPL
               (long param_1,undefined8 param_2,char param_3,undefined1 *param_4,undefined1 *param_5
               ,undefined1 *param_6,short *param_7,ushort *param_8,undefined1 *param_9)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  short local_3c;
  ushort local_3a [5];
  
  local_3f = 0;
  local_3e = 0;
  local_3d = 0;
  local_3c = 0;
  local_3a[0] = 0;
  iVar2 = (**(code **)(param_1 + 0x168))();
  if ((iVar2 == 3) && (*(char *)(param_1 + 0x1d5f) != '\0')) {
    uVar1 = *(ulong *)(param_1 + 0x878);
    lVar3 = clFindP2PBrdg_IMPL(param_2,uVar1 >> 0x20,uVar1 >> 8 & 0xff,&local_3f,&local_3e,&local_3d
                               ,&local_3c,local_3a);
    if (param_9 != (undefined1 *)0x0) {
      *param_9 = local_3f;
    }
    if (lVar3 != 0) {
      if (local_3c == 0x10de) {
        if ((local_3a[0] >> 4 != 0x5b) && (local_3a[0] != 0x1b3)) {
          return 0;
        }
      }
      else if (local_3c == 0x10b5) {
        if ((local_3a[0] & 0xef00) != 0x8700) {
          return 0;
        }
      }
      else if (local_3c == 0x11f8) {
        if (((local_3a[0] & 0xff00) != 0x8500) && ((local_3a[0] & 0xff00) != 0x4000)) {
          return 0;
        }
      }
      else {
        if (local_3c != 0x15b3) {
          return 0;
        }
        if (local_3a[0] != 0x1976) {
          return 0;
        }
      }
      if ((param_3 == '\0') ||
         (lVar3 = clFindP2PBrdg_IMPL(param_2,(int)(uVar1 >> 0x20),local_3f,&local_3f,&local_3e,
                                     &local_3d,&local_3c,local_3a), lVar3 != 0)) {
        *param_4 = local_3f;
        *param_5 = local_3e;
        *param_6 = local_3d;
        *param_7 = local_3c;
        *param_8 = local_3a[0];
        return lVar3;
      }
    }
  }
  return 0;
}


// ===== 00478600 clFindCommonDownstreamBR_IMPL =====

void clFindCommonDownstreamBR_IMPL(long param_1,long param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  char local_48;
  undefined1 local_47;
  undefined1 local_46;
  char local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  short local_40;
  ushort local_3e;
  short local_3c;
  ushort local_3a [5];
  
  if (param_1 == param_2) {
    nvAssertFailedNoLog("pGpu1 != pGpu2","src/kernel/platform/chipset/chipset_pcie.c",0x93e);
  }
  iVar1 = *(int *)(param_1 + 0x87c);
  iVar2 = *(int *)(param_2 + 0x87c);
  if (iVar2 == iVar1) {
    lVar4 = clFindBrdgUpstreamPort_IMPL
                      (param_1,param_3,1,&local_48,&local_47,&local_46,&local_40,&local_3e,&local_42
                      );
    cVar3 = local_48;
    while (lVar4 != 0) {
      local_48 = cVar3;
      if (local_40 == 0x10de) {
        if ((local_3e >> 4 == 0x5b) || (local_3e == 0x1b3)) goto LAB_00478740;
      }
      else if (local_40 == 0x10b5) {
        if ((local_3e & 0xef00) == 0x8700) goto LAB_00478740;
      }
      else if (local_40 == 0x11f8) {
        if (((local_3e & 0xff00) == 0x8500) || ((local_3e & 0xff00) == 0x4000)) {
LAB_00478740:
          lVar4 = clFindBrdgUpstreamPort_IMPL
                            (param_2,param_3,1,&local_45,&local_44,&local_43,&local_3c,local_3a,
                             &local_41);
          while (lVar4 != 0) {
            if (local_45 == cVar3) {
              if (local_3c == 0x10de) {
                if (((local_3e >> 4 == 0x5b) || (local_3e == 0x1b3)) &&
                   ((local_3a[0] >> 4 == 0x5b || (local_3a[0] == 0x1b3)))) goto LAB_0047881b;
              }
              else if (local_3c == 0x10b5) {
                if (((local_3e & 0xef00) == 0x8700) && ((local_3a[0] & 0xef00) == 0x8700))
                goto LAB_0047881b;
              }
              else if (local_3c == 0x11f8) {
                if ((((local_3e & 0xff00) == 0x8500) || ((local_3e & 0xff00) == 0x4000)) &&
                   (((local_3a[0] & 0xff00) == 0x8500 || ((local_3a[0] & 0xff00) == 0x4000))))
                goto LAB_0047881b;
              }
              else if (((local_3c == 0x15b3) && (local_3e == 0x1976)) && (local_3a[0] == 0x1976)) {
LAB_0047881b:
                if (local_45 != -1) goto LAB_0047864e;
                break;
              }
            }
            lVar4 = clFindP2PBrdg_IMPL(param_3,iVar2,local_45,&local_45,&local_44,&local_43,
                                       &local_3c,local_3a);
          }
        }
      }
      else if ((local_40 == 0x15b3) && (local_3e == 0x1976)) goto LAB_00478740;
      lVar4 = clFindP2PBrdg_IMPL(param_3,iVar1,cVar3,&local_48,&local_47,&local_46,&local_40,
                                 &local_3e);
      cVar3 = local_48;
    }
  }
  local_45 = -1;
LAB_0047864e:
  *param_4 = local_45;
  return;
}


// ===== 00478910 clPcieReadDevCtrlStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint clPcieReadDevCtrlStatus_IMPL(long param_1,long param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 == (uint *)0x0) {
    return 0xffff;
  }
  iVar1 = (**(code **)(param_1 + 0x168))();
  if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) && (*(int *)(param_1 + 0x1da0) != 0))
  {
    uVar2 = osPciReadDword(*(undefined8 *)(param_1 + 0x1d90),*(int *)(param_1 + 0x1da0) + 8);
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar2;
    }
    *param_3 = 0;
    if (*(char *)(param_2 + 0x80) != '\0') {
      *(undefined1 *)(param_2 + 0x80) = 0;
      *param_3 = *param_3 | 0x10;
    }
    if ((uVar2 & 0x10000) != 0) {
      *param_3 = *param_3 | 1;
    }
    if ((uVar2 & 0x20000) != 0) {
      *param_3 = *param_3 | 2;
    }
    if ((uVar2 & 0x40000) != 0) {
      *param_3 = *param_3 | 4;
    }
    uVar3 = uVar2 & 0x80000;
    if ((uVar2 & 0x80000) != 0) {
      *param_3 = *param_3 | 8;
      return 0;
    }
  }
  else {
    uVar3 = 0xffff;
  }
  return uVar3;
}


// ===== 004789f0 clPcieClearDevCtrlStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 clPcieClearDevCtrlStatus_IMPL(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == (int *)0x0) {
    iVar2 = (**(code **)(param_1 + 0x168))();
    if (iVar2 != 3) {
      return 0xffff;
    }
    if (*(char *)(param_1 + 0x1d8f) == '\0') {
      return 0xffff;
    }
    if (*(int *)(param_1 + 0x1da0) == 0) {
      return 0xffff;
    }
    iVar2 = osPciReadDword(*(undefined8 *)(param_1 + 0x1d90),*(int *)(param_1 + 0x1da0) + 8);
  }
  else {
    iVar2 = *param_3;
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(param_1 + 0x168))(param_1);
  if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) && (*(int *)(param_1 + 0x1da0) != 0))
  {
    osPciWriteDword(*(undefined8 *)(param_1 + 0x1d90),*(int *)(param_1 + 0x1da0) + 8,iVar2);
    return 0;
  }
  return 0xffff;
}


// ===== 00478aa0 clPcieReadWord_IMPL =====

ulong clPcieReadWord_IMPL(long param_1,undefined4 param_2,undefined1 param_3,byte param_4,
                         byte param_5,ulong param_6)

{
  ushort uVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  lVar3 = sysGetOs_IMPL(g_pSys);
  uVar4 = (param_6 & 0xffffffff) + 2;
  if (uVar4 < 0x1001) {
    if (param_4 < 0x20) {
      if (7 < param_5) {
LAB_00478c20:
        nvAssertFailedNoLog("func < PCI_MAX_FUNCTIONS","src/kernel/platform/chipset/chipset_pcie.c",
                            0xc1d);
        goto LAB_00478c40;
      }
      if (*(char *)(param_1 + 0x48) == '\0') goto LAB_00478bc7;
    }
    else {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc1c);
      if (7 < param_5) goto LAB_00478c20;
LAB_00478c40:
      if ((*(char *)(param_1 + 0x48) == '\0') || (0x1000 < uVar4)) goto LAB_00478bc7;
    }
    lVar5 = osPciInitHandle(param_2,param_3,param_4,param_5,0,0);
    if ((lVar5 != 0) &&
       (cVar2 = osTestPcieExtendedConfigAccess(lVar5,param_6 & 0xffffffff), cVar2 != '\0')) {
      uVar4 = osPciReadWord(lVar5,param_6 & 0xffffffff);
      return uVar4;
    }
    if (*(char *)(lVar3 + 0x4d) == '\0') {
      lVar3 = objClPcieMapEnhCfgSpace(param_1,param_2,param_3,param_4,param_5);
      if (lVar3 != 0) {
        uVar1 = *(ushort *)(lVar3 + (param_6 >> 1 & 0x7fffffff) * 2);
        objClPcieUnmapEnhCfgSpace_isra_0(lVar3);
        return (ulong)uVar1;
      }
    }
    else {
      nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                          "src/kernel/platform/chipset/chipset_pcie.c",0xc2d);
    }
  }
  else {
    nvAssertFailedNoLog("offset + sizeof(value) <= 0x1000",
                        "src/kernel/platform/chipset/chipset_pcie.c",0xc1b);
    if (0x1f < param_4) {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc1c);
    }
    if (7 < param_5) goto LAB_00478c20;
LAB_00478bc7:
    nvAssertFailedNoLog("clPcieReadWord() failed!","src/kernel/platform/chipset/chipset_pcie.c",
                        0xc22);
  }
  return 0;
}


// ===== 00478cd0 clUpstreamVgaDecodeEnabled_IMPL =====

undefined8 clUpstreamVgaDecodeEnabled_IMPL(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  undefined1 uVar6;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40 [2];
  undefined1 local_3e [2];
  undefined4 local_3c [3];
  
  uVar3 = 0;
  uVar6 = (undefined1)((ulong)*(undefined8 *)(param_1 + 0x878) >> 8);
  uVar1 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x878) >> 0x20);
  do {
    lVar5 = clFindP2PBrdg_IMPL(param_2,uVar1,uVar6,&local_43,&local_42,&local_41,local_40,local_3e);
    uVar6 = local_43;
    if (lVar5 == 0) {
      return 0;
    }
    iVar2 = clSetPortPcieCapOffset_IMPL(param_2,lVar5,local_3c);
    if (iVar2 == 0) {
      uVar3 = osPciReadDword(lVar5,local_3c[0]);
      uVar4 = clPcieReadWord_IMPL(param_2,uVar1,uVar6,local_42,local_41,0x3e);
      if ((uVar4 & 8) == 0) {
        return 0;
      }
    }
  } while ((uVar3 & 0xf00000) != 0x400000);
  return 1;
}


