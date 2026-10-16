// ===== 0026e270 rm_set_rm_firmware_requested =====

void rm_set_rm_firmware_requested(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  char cVar4;
  long lVar5;
  undefined4 local_b8 [38];
  
  lVar5 = g_pSys;
  *(undefined1 *)(param_2 + 0x2f8) = 1;
  *(undefined1 *)(param_2 + 0x2fa) = 0;
  lVar5 = *(long *)(lVar5 + 0x238);
  threadStateInit(local_b8,0);
  if (((lVar5 != 0) && (*(char *)(lVar5 + 0x4a) != '\0')) &&
     (lVar5 = osMapKernelSpace(**(undefined8 **)(param_2 + 0x108),os_page_size,1,1), lVar5 != 0)) {
    uVar1 = *(uint *)(lVar5 + 4);
    uVar2 = *(undefined4 *)(lVar5 + 0xa00);
    osUnmapKernelSpace(lVar5,os_page_size);
    if (((uVar1 & 0x30000) == 0x20000) &&
       (cVar4 = gpumgrIsVgxRmFirmwareCapableChip(uVar2), cVar4 != '\0')) {
      threadStateFree(local_b8,0);
      *(undefined1 *)(param_2 + 0x2f8) = 0;
      return;
    }
  }
  threadStateFree(local_b8,0);
  if (*(char *)(param_2 + 0x2f8) != '\0') {
    local_b8[0] = 2;
    RmReadRegistryDword(param_2,"EnableGpuFirmwareLogs",local_b8);
    uVar3 = gpumgrGetRmFirmwareLogsEnabled(local_b8[0]);
    *(undefined1 *)(param_2 + 0x2fb) = uVar3;
  }
  return;
}


// ===== 0026e3a7 rm_disable_gpu_state_persistence.cold =====

void rm_disable_gpu_state_persistence_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  
  threadStateInit(unaff_RBP + -0x90,0);
  DAT_00000453 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026e3c0 rm_disable_gpu_state_persistence =====

void rm_disable_gpu_state_persistence(undefined8 param_1,long *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined1 local_98 [144];
  
  if ((param_2 != (long *)0x0) && ((long *)*param_2 != (long *)0x0)) {
    lVar1 = *(long *)*param_2;
    threadStateInit(local_98,0);
    *(undefined1 *)(lVar1 + 0x453) = 0;
    osModifyGpuSwStatePersistence(*(undefined8 *)(lVar1 + 0x4e0),0);
    threadStateFree(local_98,0);
    return;
  }
  threadStateInit(local_98,0);
  DAT_00000453 = 0;
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0026e430 rm_kernel_rmapi_op =====

void rm_kernel_rmapi_op(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  uVar1 = *param_2;
  if (uVar1 == 0x2e) {
    Nv04MapMemoryDmaKernel(param_2 + 2);
    return;
  }
  if (0x2e < uVar1) {
    if (uVar1 == 0x37) {
      Nv04DupObjectKernel(param_2 + 2);
      return;
    }
    if (0x37 < uVar1) {
      if (uVar1 == 0x3d) {
        Nv04AddVblankCallbackKernel(param_2 + 2);
        return;
      }
      if (uVar1 == 0x3e) {
        Nv04ShareKernel(param_2 + 2);
        return;
      }
      return;
    }
    if (uVar1 == 0x31) {
      Nv04BindContextDmaKernel(param_2 + 2);
      return;
    }
    if (uVar1 != 0x36) {
      if (uVar1 == 0x2f) {
        Nv04UnmapMemoryDmaKernel(param_2 + 2);
        return;
      }
      return;
    }
    Nv04ControlKernel(param_2 + 2);
    return;
  }
  if (uVar1 == 0x20) {
    Nv04VidHeapControlKernel(*(undefined8 *)(param_2 + 2));
    return;
  }
  if (uVar1 < 0x21) {
    if (uVar1 == 2) {
      Nv01AllocMemoryKernel(param_2 + 2);
      return;
    }
    if (uVar1 != 0x15) {
      if (uVar1 == 0) {
        Nv01FreeKernel(param_2 + 2);
        return;
      }
      return;
    }
    Nv04AllocWithAccessKernel(param_2 + 2);
    return;
  }
  if (uVar1 == 0x22) {
    Nv04UnmapMemoryKernel(param_2 + 2);
    return;
  }
  if (uVar1 == 0x27) {
    Nv04AllocContextDmaKernel(param_2 + 2);
    return;
  }
  if (uVar1 != 0x21) {
    return;
  }
  Nv04MapMemoryKernel(param_2 + 2);
  lVar3 = tlsEntryGet(2);
  if (lVar3 != 0) {
    iVar2 = tlsEntryRelease(2);
    if (iVar2 != 0) {
      nvAssertFailedNoLog("tlsEntryRelease(TLS_ENTRY_ID_MAPPING_CONTEXT) == 0",
                          "arch/nvalloc/unix/src/osapi.c",0x13f4);
    }
    os_free_mem(*(undefined8 *)(lVar3 + 0x28));
    os_free_mem(lVar3);
    return;
  }
  return;
}


// ===== 0026e620 RmInitAcpiMethods =====

void RmInitAcpiMethods(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined1 local_1c [12];
  
  if (*(char *)(param_2 + 0x62) != '\0') {
    return;
  }
  nv_acpi_methods_init(local_1c);
  acpiDsmInit(param_3);
  return;
}


// ===== 0026e660 RmUnInitAcpiMethods =====

void RmUnInitAcpiMethods(long param_1)

{
  *(undefined1 *)(param_1 + 0x62) = 0;
  nv_acpi_methods_uninit();
  return;
}


// ===== 0026e670 RmInflateOsToRmPageArray =====

void RmInflateOsToRmPageArray(undefined8 param_1,ulong param_2)

{
  RmInflatePageArray(param_1,(ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & param_2)
                                    != 0) + (param_2 >> (os_page_shift - 0xcU & 0x3f)),os_page_size,
                     param_2,0x1000);
  return;
}


// ===== 0026e6c0 RmDeflateRmToOsPageArray =====

void RmDeflateRmToOsPageArray(undefined8 param_1,ulong param_2)

{
  RmDeflatePageArray(param_1,param_2,0x1000,
                     (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & param_2) != 0) +
                     (param_2 >> (os_page_shift - 0xcU & 0x3f)),os_page_size);
  return;
}


// ===== 0026e700 rm_get_device_remove_flag =====

undefined1 rm_get_device_remove_flag(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_a9;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  iVar1 = gpumgrQueryGpuDrainState(param_2,0,&local_a9);
  if (iVar1 != 0) {
    local_a9 = 0;
  }
  threadStateFree(local_a8,0);
  return local_a9;
}


// ===== 0026e760 rm_get_gpu_numa_info =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int rm_get_gpu_numa_info(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  long lVar4;
  undefined1 local_b8 [152];
  
  if ((param_3 != (undefined4 *)0x0) && ((uint)param_3[0x8a] < 0x41)) {
    if ((*(byte *)(param_2 + 0x10) & 0x10) != 0) {
      *param_3 = 0xffffffff;
      *(undefined8 *)(param_3 + 4) = 0;
      *(undefined8 *)(param_3 + 6) = 0;
      param_3[0x8a] = 0;
      return 0;
    }
    puVar3 = (undefined4 *)portMemAllocNonPaged(0x220);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = 0x51;
    }
    else {
      portMemSet(puVar3,0,0x220);
      puVar3[6] = param_3[0x8a];
      lVar4 = RmUnixRmApiPrologue(param_2,local_b8,0x2000);
      if (lVar4 == 0) {
        iVar2 = 0x40;
      }
      else {
        iVar2 = (**(code **)(lVar4 + 0x38))
                          (lVar4,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x318),
                           0x20801351,puVar3,0x220);
        os_unref_dynamic_power(param_2,2);
        rmapiLockRelease();
        threadStateFree(local_b8,0);
        if (iVar2 == 0) {
          *param_3 = *puVar3;
          *(undefined8 *)(param_3 + 4) = *(undefined8 *)(puVar3 + 2);
          *(undefined8 *)(param_3 + 6) = *(undefined8 *)(puVar3 + 4);
          iVar1 = puVar3[6];
          param_3[0x8a] = iVar1;
          if (iVar1 != 0) {
            lVar4 = 0;
            do {
              *(undefined8 *)(param_3 + lVar4 * 2 + 10) = *(undefined8 *)(puVar3 + lVar4 * 2 + 8);
              lVar4 = lVar4 + 1;
            } while ((uint)lVar4 < (uint)puVar3[6]);
          }
        }
      }
      portMemFree(puVar3);
    }
    return iVar2;
  }
  return 0x1f;
}


// ===== 0026e910 rm_gpu_numa_online =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined4 rm_gpu_numa_online(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 local_a9;
  undefined1 local_a8 [144];
  
  local_a9 = 0;
  lVar2 = RmUnixRmApiPrologue(param_2,local_a8,0x2000);
  if (lVar2 != 0) {
    local_a9 = 1;
    uVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x318),
                       0x20801350,&local_a9,1);
    os_unref_dynamic_power(param_2,2);
    rmapiLockRelease();
    threadStateFree(local_a8,0);
    return uVar1;
  }
  return 0x40;
}


// ===== 0026e9d0 rm_gpu_numa_offline =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined4 rm_gpu_numa_offline(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 local_a9;
  undefined1 local_a8 [144];
  
  local_a9 = 0;
  lVar2 = RmUnixRmApiPrologue(param_2,local_a8,0x2000);
  if (lVar2 != 0) {
    local_a9 = 0;
    uVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x318),
                       0x20801350,&local_a9,1);
    os_unref_dynamic_power(param_2,2);
    rmapiLockRelease();
    threadStateFree(local_a8,0);
    return uVar1;
  }
  return 0x40;
}


// ===== 0026ea90 rm_is_device_sequestered =====

undefined1 rm_is_device_sequestered(undefined8 param_1,long param_2)

{
  undefined1 local_a9;
  undefined1 local_a8 [152];
  
  local_a9 = 0;
  threadStateInit(local_a8,0);
  gpumgrQueryGpuDrainState(*(undefined4 *)(param_2 + 0x24),&local_a9,0);
  threadStateFree(local_a8,0);
  return local_a9;
}


// ===== 0026eaf0 rm_check_for_gpu_surprise_removal =====

void rm_check_for_gpu_surprise_removal(undefined8 param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  iVar1 = rmapiLockAcquire(2,0x80000);
  if (iVar1 == 0) {
    uVar2 = 0;
    if ((param_2 != (long *)0x0) && (uVar2 = 0, (undefined8 *)*param_2 != (undefined8 *)0x0)) {
      uVar2 = *(undefined8 *)*param_2;
    }
    iVar1 = rmDeviceGpuLocksAcquire(uVar2,0,0x80000);
    if (iVar1 == 0) {
      osHandleGpuLost(uVar2,1);
      rmDeviceGpuLocksRelease(uVar2,0,0);
    }
    rmapiLockRelease();
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 0026eb80 rm_set_external_kernel_client_count =====

int rm_set_external_kernel_client_count(undefined8 param_1,long *param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  if (((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) ||
     (lVar1 = *(long *)*param_2, lVar1 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = rmDeviceGpuLocksAcquire(lVar1,0,0x80000);
    if (iVar2 == 0) {
      iVar2 = gpuSetExternalKernelClientCount_IMPL(lVar1,param_3);
      rmDeviceGpuLocksRelease(lVar1,0,0);
    }
  }
  threadStateFree(local_a8,0);
  return iVar2;
}


// ===== 0026ec20 rm_get_uefi_console_status =====

/* WARNING: Type propagation algorithm not settling */

undefined1  [16] rm_get_uefi_console_status(undefined8 param_1)

{
  undefined1 auVar1 [16];
  long *plVar2;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  long local_18 [2];
  
  plVar2 = local_18;
  local_18[1] = 0;
  nv_get_screen_info(param_1,local_18 + 1,local_28,local_24,local_20,local_1c,plVar2);
  auVar1._1_7_ = (undefined7)((ulong)plVar2 >> 8);
  auVar1[0] = local_18[0] != 0;
  auVar1._8_8_ = uStack_30;
  return auVar1;
}


// ===== 0026ec60 rm_get_uefi_console_size =====

undefined8 rm_get_uefi_console_size(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_10 = 0;
  nv_get_screen_info(param_1,param_2,&local_20,&local_1c,&local_18,&local_14,&local_10);
  return local_10;
}


// ===== 0026ecb0 rm_disable_iomap_wc =====

undefined8 rm_disable_iomap_wc(void)

{
  return CONCAT71((int7)((ulong)*(long *)(g_pSys + 0x208) >> 8),
                  *(char *)(*(long *)(g_pSys + 0x208) + 0x69) == '\x01');
}


// ===== 0026ecd0 rm_dma_buf_dup_mem_handle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int rm_dma_buf_dup_mem_handle
              (undefined8 param_1,long *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,long param_7,undefined4 param_8,ulong param_9,
              ulong param_10,undefined4 *param_11,long *param_12,undefined1 *param_13,
              undefined4 *param_14,undefined1 *param_15,int *param_16)

{
  long *plVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_d8;
  ulong local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  lVar7 = 0;
  if (param_2 != (long *)0x0) {
    lVar7 = 0;
    if ((long *)*param_2 != (long *)0x0) {
      lVar7 = *(long *)*param_2;
    }
  }
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","arch/nvalloc/unix/src/osapi.c",0x15c0);
    cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar7 + 0x7a4));
  }
  else {
    cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar7 + 0x7a4));
  }
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "arch/nvalloc/unix/src/osapi.c",0x15c2);
  }
  local_d8 = 0;
  local_d0 = 0;
  iVar4 = serverGetClientUnderLock(g_resServ,param_3,&local_d8);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"serverGetClientUnderLock(&g_resServ, hSrcClient, &pClient)",
               "arch/nvalloc/unix/src/osapi.c",0x553);
    goto LAB_0026ef35;
  }
  iVar4 = clientGetResourceRef_IMPL(local_d8,param_8,&local_d0);
  if (iVar4 != 0) goto LAB_0026ef35;
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_d0 + 8),__nvoc_class_def_Memory);
  if (lVar6 == 0) {
    iVar4 = 0x31;
    goto LAB_0026ef35;
  }
  plVar1 = *(long **)(lVar6 + 0x118);
  if ((((param_7 != 0) && (iVar4 = memdescGetAddressSpace(plVar1), iVar4 != 1)) &&
      (*(long *)(param_7 + 0x980) != *(long *)(lVar6 + 0x110))) ||
     ((lVar7 != *plVar1 || (lVar7 != *(long *)(lVar6 + 0xf0))))) {
    iVar4 = 0x36;
    goto LAB_0026ef35;
  }
  if (((((os_page_size - 1U & (param_9 | param_10)) != 0) ||
       ((iVar4 = memdescGetAddressSpace(plVar1), iVar4 != 2 &&
        (*(char *)(*(long *)(lVar7 + 0x4d8) + 0x80) == '\0')))) || (param_10 == 0)) ||
     (((ulong)plVar1[6] < param_10 || (plVar1[6] - param_10 < param_9)))) {
    iVar4 = 0x1f;
    goto LAB_0026ef35;
  }
  lVar6 = rmapiGetInterface(4);
  local_d0 = local_d0 & 0xffffffff00000000;
  iVar4 = (**(code **)(lVar6 + 0x50))(lVar6,param_4,param_5,&local_d0,param_3,param_8,0);
  if (iVar4 == 0) {
LAB_0026f040:
    *param_11 = (undefined4)local_d0;
  }
  else if (iVar4 == 0x36) {
    local_d0 = local_d0 & 0xffffffff00000000;
    iVar4 = (**(code **)(lVar6 + 0x50))(lVar6,param_4,param_6,&local_d0,param_3,param_8,0);
    if (iVar4 == 0) goto LAB_0026f040;
  }
  *param_12 = (long)plVar1;
  *param_14 = *(undefined4 *)((long)plVar1 + 0x74);
  uVar3 = memdescGetFlag(plVar1,0x100000000);
  *param_15 = uVar3;
  cVar2 = memdescGetFlag(plVar1,0x80000000);
  iVar5 = 3;
  if (cVar2 == '\0') {
    iVar5 = memdescGetAddressSpace(plVar1);
    iVar5 = (uint)(iVar5 != 1) * 2;
  }
  *param_16 = iVar5;
  *param_13 = *(undefined1 *)(*(long *)(lVar7 + 0x4d8) + 0x80);
LAB_0026ef35:
  threadStateFree(local_c8,0);
  return iVar4;
}


// ===== 0026f070 rm_dma_buf_undup_mem_handle =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void rm_dma_buf_undup_mem_handle
               (undefined8 param_1,long *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  long lVar2;
  undefined1 local_b8 [152];
  
  threadStateInit(local_b8,0);
  lVar2 = 0;
  if ((param_2 != (long *)0x0) && (lVar2 = 0, (long *)*param_2 != (long *)0x0)) {
    lVar2 = *(long *)*param_2;
  }
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","arch/nvalloc/unix/src/osapi.c",0x161b);
  }
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "arch/nvalloc/unix/src/osapi.c",0x161d);
  }
  lVar2 = rmapiGetInterface(4);
  (**(code **)(lVar2 + 0x18))(lVar2,param_3,param_4,*(code **)(lVar2 + 0x18));
  threadStateFree(local_b8,0);
  return;
}


// ===== 0026f13d rm_dma_buf_map_mem_handle.cold =====

void rm_dma_buf_map_mem_handle_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026f160 rm_dma_buf_map_mem_handle =====

ulong rm_dma_buf_map_mem_handle
                (undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4,
                ulong param_5,long param_6,char param_7,long param_8,char param_9,long *param_10)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  long *plVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 local_e0;
  undefined8 local_d8;
  long local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  if ((param_8 == 0 || param_6 == 0) || (param_10 == (long *)0x0)) {
    uVar16 = 0x1f;
    nvAssertFailedNoLog("((pMemArea != NULL) && (pMemInfo != NULL)) && (memRange.size != 0)",
                        "arch/nvalloc/unix/src/osapi.c",0x1643);
  }
  else {
    if (param_2 == (long *)0x0) {
      uVar16 = rm_dma_buf_map_mem_handle_cold();
      return uVar16;
    }
    if ((long *)*param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar1 = *(long *)*param_2;
    if (((*(char *)(lVar1 + 0x454) == '\0') && (*(char *)(*(long *)(lVar1 + 0x4d8) + 0x80) == '\0'))
       || (param_7 != '\0')) {
      local_e0 = 0;
      uVar2 = *(undefined8 *)(&DAT_00001b90 + lVar1);
      if (param_9 == '\0') {
        cVar4 = rmapiLockIsOwner();
        if (cVar4 == '\0') {
          nvAssertFailedNoLog("rmapiLockIsOwner()","arch/nvalloc/unix/src/osapi.c",0x168f);
        }
        cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
        if (cVar4 == '\0') {
          nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                              "arch/nvalloc/unix/src/osapi.c",0x1690);
        }
        uVar7 = serverGetClientUnderLock(g_resServ,param_3,&local_d8);
        uVar16 = (ulong)uVar7;
        if (uVar7 != 0) {
          nvAssertOkFailedNoLog
                    (uVar7,"serverGetClientUnderLock(&g_resServ, hClient, &pClient)",
                     "arch/nvalloc/unix/src/osapi.c",0x1692);
          goto LAB_0026f2c2;
        }
        uVar7 = deviceGetByGpu_IMPL(local_d8,lVar1,1,&local_e0);
        uVar16 = (ulong)uVar7;
        if (uVar7 != 0) {
          nvAssertOkFailedNoLog
                    (uVar7,"deviceGetByGpu(pClient, pGpu, NV_TRUE, &pDevice)",
                     "arch/nvalloc/unix/src/osapi.c",0x1696);
          goto LAB_0026f2c2;
        }
      }
      else {
        uVar16 = 0x1f;
      }
      iVar6 = memdescGetAddressSpace(param_8);
      if (iVar6 == 2) {
        uVar7 = kbusMapFbAperture_GM107(lVar1,uVar2,param_8,param_5,param_6,param_10,0x120,local_e0)
        ;
        uVar16 = (ulong)uVar7;
        if (uVar7 == 0) {
          uVar7 = kbusGetGpuFbPhysAddressForRdma_IMPL(lVar1,uVar2,param_7 == '\x01',&local_d0);
          uVar16 = (ulong)uVar7;
          if (uVar7 == 0) {
            uVar10 = 0;
            if (param_10[1] != 0) {
              do {
                uVar12 = uVar10 + 1;
                plVar8 = (long *)(uVar10 * 0x10 + *param_10);
                *plVar8 = *plVar8 + local_d0;
                uVar10 = uVar12;
              } while (uVar12 < (ulong)param_10[1]);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (uVar7,
                       "kbusGetGpuFbPhysAddressForRdma(pGpu, pKernelBus, bForcePcie, &barOffset)",
                       "arch/nvalloc/unix/src/osapi.c",0x16ac);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar16,
                     "kbusMapFbAperture_HAL(pGpu, pKernelBus, pMemDesc, memRange, pMemArea, (BUS_MAP_FB_FLAGS_MAP_UNICAST | BUS_MAP_FB_FLAGS_ALLOW_DISCONTIG), pDevice)"
                     ,"arch/nvalloc/unix/src/osapi.c",0x16a4);
        }
      }
      else {
        nvCheckFailedNoLog(4,"memdescGetAddressSpace(pMemDesc) == ADDR_FBMEM",
                           "arch/nvalloc/unix/src/osapi.c",0x169b);
      }
    }
    else {
      lVar1 = *(long *)(lVar1 + 0x1b70);
      cVar4 = memdescCheckContiguity(param_8,0);
      cVar5 = memdescGetFlag(param_8,0x4000000000000);
      if (cVar5 == '\0') {
        if (cVar4 == '\0') {
          uVar10 = memdescGetPageSize(param_8,0);
          uVar11 = param_5 & -uVar10;
          uVar13 = (uVar10 - 1) + param_6 + param_5 & -uVar10;
          uVar15 = uVar13 - uVar11;
          uVar12 = uVar15 / uVar10;
          uVar7 = os_alloc_mem(param_10,uVar12 << 4,uVar15 % uVar10);
          uVar16 = (ulong)uVar7;
          if (uVar7 == 0) {
            if (uVar10 <= uVar15) {
              uVar15 = 0;
              uVar16 = uVar11;
              do {
                lVar9 = memdescGetPhysAddr(param_8,0,uVar16);
                lVar14 = uVar15 * 0x10;
                uVar15 = uVar15 + 1;
                *(long *)(*param_10 + lVar14) = lVar9 + *(long *)(lVar1 + 0x478);
                *(ulong *)(*param_10 + 8 + lVar14) = uVar10;
                uVar16 = uVar16 + uVar10;
              } while (uVar15 < uVar12);
              uVar16 = 0;
            }
            *(long *)*param_10 = *(long *)*param_10 + (param_5 - uVar11);
            *(ulong *)(*param_10 + 8) = (uVar11 + *(long *)(*param_10 + 8)) - param_5;
            plVar8 = (long *)((uVar12 - 1) * 0x10 + *param_10 + 8);
            *plVar8 = *plVar8 + ((param_6 + param_5) - uVar13);
            param_10[1] = uVar12;
          }
          else {
            nvAssertOkFailedNoLog
                      (uVar7,
                       "os_alloc_mem((void **) &pMemArea->pRanges, pageCount * sizeof(MemoryRange))"
                       ,"arch/nvalloc/unix/src/osapi.c",0x166f);
          }
        }
        else {
          lVar9 = memdescGetPhysAddr(param_8,0,param_5);
          uVar7 = os_alloc_mem(param_10,0x10);
          uVar16 = (ulong)uVar7;
          if (uVar7 == 0) {
            *(long *)*param_10 = *(long *)(lVar1 + 0x478) + lVar9;
            *(long *)(*param_10 + 8) = param_6;
            param_10[1] = 1;
          }
          else {
            nvAssertOkFailedNoLog
                      (uVar7,"os_alloc_mem((void **) &pMemArea->pRanges, sizeof(MemoryRange))",
                       "arch/nvalloc/unix/src/osapi.c",0x165e);
          }
        }
      }
      else {
        uVar16 = 0x56;
        nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x1654,"rm_dma_buf_map_mem_handle",4,
                     "NVRM: RDMA is not supported for localized memory over coherent mappings\n");
      }
    }
  }
LAB_0026f2c2:
  threadStateFree(local_c8,0);
  return uVar16;
}


// ===== 0026f6ff rm_dma_buf_unmap_mem_handle.cold =====

void rm_dma_buf_unmap_mem_handle_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026f710 rm_dma_buf_unmap_mem_handle =====

void rm_dma_buf_unmap_mem_handle
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4,char param_5,
               undefined8 param_6,char param_7,long *param_8,long param_9)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  long *plVar6;
  long local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  if ((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)*param_2;
  if (((*(char *)(lVar1 + 0x454) != '\0') || (*(char *)(*(long *)(lVar1 + 0x4d8) + 0x80) != '\0'))
     && (param_5 == '\0')) {
    os_free_mem(param_8);
    goto LAB_0026f80c;
  }
  uVar2 = *(undefined8 *)(&DAT_00001b90 + lVar1);
  iVar5 = kbusGetGpuFbPhysAddressForRdma_IMPL(lVar1,uVar2,param_5 == '\x01',&local_d0);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"kbusGetGpuFbPhysAddressForRdma(pGpu, pKernelBus, bForcePcie, &barOffset)",
               "arch/nvalloc/unix/src/osapi.c",0x16e6);
  }
  if (param_9 != 0) {
    plVar6 = param_8;
    if ((param_9 * 0x10 & 0x10U) != 0) {
      plVar6 = param_8 + 2;
      *param_8 = *param_8 - local_d0;
      if (param_8 + param_9 * 2 == plVar6) goto LAB_0026f7e0;
    }
    do {
      *plVar6 = *plVar6 - local_d0;
      plVar6[2] = plVar6[2] - local_d0;
      plVar6 = plVar6 + 4;
    } while (param_8 + param_9 * 2 != plVar6);
  }
LAB_0026f7e0:
  if (param_7 == '\0') {
    cVar4 = rmapiLockIsOwner();
    if (cVar4 == '\0') {
      nvAssertFailedNoLog("rmapiLockIsOwner()","arch/nvalloc/unix/src/osapi.c",0x16f1);
    }
    cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar4 == '\0') {
      nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                          "arch/nvalloc/unix/src/osapi.c",0x16f2);
    }
  }
  iVar5 = kbusUnmapFbAperture_GM107(lVar1,uVar2,param_6,param_8,param_9,0x20);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,
               "kbusUnmapFbAperture_HAL(pGpu, pKernelBus, pMemDesc, memArea, BUS_MAP_FB_FLAGS_MAP_UNICAST)"
               ,"arch/nvalloc/unix/src/osapi.c",0x16fa);
  }
LAB_0026f80c:
  threadStateFree(local_c8,0);
  return;
}


// ===== 0026f900 rm_dma_buf_get_client_and_device =====

int rm_dma_buf_get_client_and_device
              (undefined8 param_1,long *param_2,undefined4 param_3,undefined4 param_4,char param_5,
              undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,long *param_9,
              undefined1 *param_10,undefined1 *param_11)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined8 uVar7;
  long lVar8;
  bool bVar9;
  undefined8 local_e8;
  long local_e0;
  long local_d8 [2];
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar4 = rmapiLockAcquire(0,0x1000);
  if (iVar4 != 0) goto LAB_0026f976;
  lVar8 = 0;
  if (param_2 != (long *)0x0) {
    lVar8 = 0;
    if ((long *)*param_2 != (long *)0x0) {
      lVar8 = *(long *)*param_2;
    }
  }
  iVar4 = rmDeviceGpuLocksAcquire(lVar8,0,0x1000);
  if (iVar4 == 0) {
    lVar1 = *(long *)(lVar8 + 0x1b78);
    if (param_5 == '\x01') {
      if ((*(char *)(lVar8 + 0x454) != '\0') &&
         (*(char *)(*(long *)(&DAT_00001b90 + lVar8) + 0xad45) == '\0')) {
        if (*(long *)(lVar8 + 0x1bc0) == 0) goto LAB_0026f9dd;
        cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar8);
        if (cVar3 == '\0') goto LAB_0026f9b2;
      }
      iVar4 = 0x56;
    }
    else {
LAB_0026f9b2:
      if ((*(long *)(lVar8 + 0x1bc0) == 0) ||
         (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar8), cVar3 == '\0')) {
LAB_0026f9dd:
        *param_6 = *(undefined4 *)(lVar1 + 0xd10);
        *param_7 = *(undefined4 *)(lVar1 + 0xd14);
        *param_8 = *(undefined4 *)(lVar1 + 0xd18);
        *param_9 = 0;
LAB_0026fa09:
        if (((*(char *)(lVar8 + 0x454) == '\0') &&
            (*(char *)(*(long *)(lVar8 + 0x4d8) + 0x80) == '\0')) || (bVar9 = true, param_5 != '\0')
           ) {
          cVar3 = kbusIsStaticBar1Enabled_IMPL(lVar8,*(undefined8 *)(&DAT_00001b90 + lVar8));
          bVar9 = cVar3 != '\0';
        }
        *param_10 = bVar9;
      }
      else {
        uVar2 = *(undefined8 *)(lVar8 + 0x1bc0);
        iVar5 = serverGetClientUnderLock(g_resServ,param_3,&local_e8);
        uVar7 = 0x5bf;
        pcVar6 = "serverGetClientUnderLock(&g_resServ, hClient, &pClient)";
        if (iVar5 == 0) {
          iVar5 = memGetByHandle_IMPL(local_e8,param_4,&local_e0,"arch/nvalloc/unix/src/osapi.c",
                                      0x5bf);
          uVar7 = 0x5c2;
          pcVar6 = "memGetByHandle(pClient, hMemory, &pMemory)";
          if (iVar5 == 0) {
            iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL
                              (lVar8,uVar2,*(undefined8 *)(local_e0 + 0xe0),local_d8,0x5c2);
            uVar7 = 0x5c5;
            pcVar6 = 
            "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pMemory->pDevice, &ref)";
            if (iVar5 == 0) {
              iVar5 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(local_d8[0] + 0x978));
              if (iVar5 == 0) {
                *param_6 = *(undefined4 *)(local_d8[0] + 0x9c0);
                *param_7 = *(undefined4 *)(local_d8[0] + 0x9c4);
                *param_8 = *(undefined4 *)(local_d8[0] + 0x9c8);
                *param_9 = local_d8[0];
                goto LAB_0026fa09;
              }
              uVar7 = 0x5c9;
              pcVar6 = "kmigmgrIncRefCount(ref.pKernelMIGGpuInstance->pShare)";
            }
          }
        }
        nvCheckOkFailedNoLog(4,iVar5,pcVar6,"arch/nvalloc/unix/src/osapi.c",uVar7);
        iVar4 = iVar5;
      }
    }
    *param_11 = *(undefined1 *)(*(long *)(lVar8 + 0x4d8) + 0x80);
    rmDeviceGpuLocksRelease(lVar8,0,0);
  }
  rmapiLockRelease();
LAB_0026f976:
  threadStateFree(local_c8,0);
  return iVar4;
}


// ===== 0026fc10 rm_dma_buf_put_client_and_device =====

void rm_dma_buf_put_client_and_device(undefined8 param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long in_R9;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  iVar1 = rmapiLockAcquire(0,0x1000);
  if (iVar1 == 0) {
    uVar2 = 0;
    if ((param_2 != (long *)0x0) && (uVar2 = 0, (undefined8 *)*param_2 != (undefined8 *)0x0)) {
      uVar2 = *(undefined8 *)*param_2;
    }
    iVar1 = rmDeviceGpuLocksAcquire(uVar2,0,0x1000);
    if (iVar1 == 0) {
      if (in_R9 != 0) {
        iVar1 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(in_R9 + 0x978));
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,"kmigmgrDecRefCount(pKernelMIGGpuInstance->pShare)",
                     "arch/nvalloc/unix/src/osapi.c",0x5ee);
        }
      }
      rmDeviceGpuLocksRelease(uVar2,0,0);
      rmapiLockRelease();
      goto LAB_0026fc94;
    }
    rmapiLockRelease();
  }
  nvAssertOkFailedNoLog(iVar1,"rmStatus","arch/nvalloc/unix/src/osapi.c",0x175c);
LAB_0026fc94:
  threadStateFree(local_a8,0);
  return;
}


// ===== 0026fd00 rm_vgpu_vfio_set_driver_vm =====

void rm_vgpu_vfio_set_driver_vm(undefined8 param_1,undefined1 param_2)

{
  *(undefined1 *)(*(long *)(g_pSys + 0x238) + 0x48) = param_2;
  return;
}


// ===== 0026fd20 rm_is_altstack_in_use =====

undefined8 rm_is_altstack_in_use(void)

{
  return 0;
}


// ===== 0026fd30 rm_acpi_nvpcf_notify =====

void rm_acpi_nvpcf_notify(void)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  iVar2 = rmapiLockAcquire(0,0x1002);
  if (iVar2 != 0) {
    threadStateFree(local_a8,0);
    return;
  }
  lVar3 = gpumgrGetGpu(0);
  if (lVar3 != 0) {
    uVar1 = *(undefined8 *)(lVar3 + 0x4e0);
    iVar2 = os_ref_dynamic_power(uVar1,2);
    if (iVar2 == 0) {
      gpuNotifySubDeviceEvent_IMPL(lVar3,0xb1,0,0,0,0);
    }
    os_unref_dynamic_power(uVar1,2);
  }
  rmapiLockRelease();
  threadStateFree(local_a8,0);
  return;
}


// ===== 0026fdf0 rm_notify_gpu_addition =====

void rm_notify_gpu_addition(undefined8 param_1,undefined8 param_2)

{
  rm_notify_gpu_addition_removal_helper(param_2,1);
  return;
}


// ===== 0026fe10 rm_notify_gpu_removal =====

void rm_notify_gpu_removal(undefined8 param_1,undefined8 param_2)

{
  rm_notify_gpu_addition_removal_helper(param_2,0);
  return;
}


// ===== 0026fe20 rm_wait_for_bar_firewall =====

void rm_wait_for_bar_firewall
               (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5,undefined2 param_6,undefined2 param_7)

{
  gpumgrWaitForBarFirewall(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 0026fe50 rm_pmu_perfmon_get_load =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int rm_pmu_perfmon_get_load(undefined8 param_1,long *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  undefined4 uVar4;
  undefined8 local_30;
  
  local_30 = 0;
  if (param_4 == 0) {
    if (param_2 != (long *)0x0) {
      uVar4 = 1;
      iVar1 = *(int *)(*param_2 + 0x1f8);
      goto joined_r0x0026fee4;
    }
    piVar2 = (int *)&DAT_000001f8;
    uVar4 = 1;
  }
  else {
    if (param_4 != 1) {
      return 0x1f;
    }
    if (param_2 == (long *)0x0) {
      piVar2 = (int *)&DAT_000001f8;
      uVar4 = 2;
    }
    else {
      uVar4 = 2;
      piVar2 = (int *)(*param_2 + 0x1f8);
    }
  }
  iVar1 = *piVar2;
joined_r0x0026fee4:
  if (iVar1 == 4) {
    *param_3 = 0;
    return 0;
  }
  iVar1 = rmapiLockAcquire(0,0x1000);
  if (iVar1 == 0) {
    lVar3 = rmapiGetInterface(3);
    if (lVar3 != 0) {
      local_30._0_4_ = uVar4;
      iVar1 = (**(code **)(lVar3 + 0x38))
                        (lVar3,(int)param_2[0x62],(int)param_2[99],0x20802069,&local_30,8);
      if (iVar1 == 0) {
        *param_3 = local_30._4_4_;
      }
      rmapiLockRelease();
      return iVar1;
    }
    rmapiLockRelease();
  }
  return 0x40;
}


// ===== 0026ff90 RmUnixFreeRmApi =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void RmUnixFreeRmApi(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = rmGpuLocksAcquire(0,0x800001);
  if (iVar1 != 0) {
    return;
  }
  lVar2 = rmapiGetInterface(4);
  iVar1 = *(int *)(param_1 + 0x310);
  if (iVar1 != 0) {
    (**(code **)(lVar2 + 0x18))(lVar2,iVar1,iVar1,*(code **)(lVar2 + 0x18));
  }
  portMemSet(param_1 + 0x310,0,0x14);
  rmGpuLocksRelease(0,0);
  return;
}


// ===== 00270000 osRmInitRm =====

int osRmInitRm(void)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int local_1c [3];
  
  lVar1 = g_pSys;
  cVar2 = os_is_efi_enabled();
  if (cVar2 != '\0') {
    *(undefined1 *)(lVar1 + 0x67) = 1;
  }
  RmInitRegistry();
  local_1c[0] = 0;
  iVar3 = osReadRegistryDword(0,"EnablePCIeGen3",local_1c);
  if ((iVar3 == 0) && (local_1c[0] != 0)) {
    local_1c[0] = 4;
    osWriteRegistryDword(0,"RMPcieLinkSpeed",4);
  }
  iVar3 = osReadRegistryDword(0,"InitializeSystemMemoryAllocations",local_1c);
  if (iVar3 != 0 || local_1c[0] != 0) {
    *(undefined1 *)(lVar1 + 0x65) = 1;
  }
  iVar3 = osReadRegistryDword(0,"EnableStreamMemOPs",local_1c);
  if ((iVar3 == 0) && (local_1c[0] != 0)) {
    local_1c[0] = 1;
    osWriteRegistryDword(0,"RmStreamMemOps",1);
  }
  iVar3 = osReadRegistryDword(0,"RMForceBarPath",local_1c);
  if ((iVar3 == 0) && (local_1c[0] == 1)) {
    osWriteRegistryDword(0,"EnableUserNUMAManagement",0);
  }
  iVar3 = osReadRegistryDword(0,"NvLinkDisable",local_1c);
  if ((iVar3 == 0) && (local_1c[0] == 1)) {
    osWriteRegistryDword(0,"RMNvLinkControl",1);
  }
  iVar3 = osReadRegistryDword(0,"EnablePCIERelaxedOrderingMode",local_1c);
  if ((iVar3 == 0) && (local_1c[0] == 1)) {
    osWriteRegistryDword(0,"RmSetPCIERelaxedOrdering",1);
  }
  os_dbg_init();
  nvDbgInitRmMsg(0);
  if (nvlogInitCount == 1) {
    nvlogUpdate();
  }
  iVar3 = registerHalModule_TU102();
  if (iVar3 == 0) {
    iVar3 = registerHalModule_TU104();
    if (iVar3 == 0) {
      iVar3 = registerHalModule_TU106();
      if (iVar3 == 0) {
        iVar3 = registerHalModule_TU116();
        if (iVar3 == 0) {
          iVar3 = registerHalModule_TU117();
          if (iVar3 == 0) {
            iVar3 = registerHalModule_GA100();
            if (iVar3 == 0) {
              iVar3 = registerHalModule_GA102();
              if (iVar3 == 0) {
                iVar3 = registerHalModule_GA103();
                if (iVar3 == 0) {
                  iVar3 = registerHalModule_GA104();
                  if (iVar3 == 0) {
                    iVar3 = registerHalModule_GA106();
                    if (iVar3 == 0) {
                      iVar3 = registerHalModule_GA107();
                      if (iVar3 == 0) {
                        iVar3 = registerHalModule_AD102();
                        if (iVar3 == 0) {
                          iVar3 = registerHalModule_AD103();
                          if (iVar3 == 0) {
                            iVar3 = registerHalModule_AD104();
                            if (iVar3 == 0) {
                              iVar3 = registerHalModule_AD106();
                              if (iVar3 == 0) {
                                iVar3 = registerHalModule_AD107();
                                if (iVar3 == 0) {
                                  iVar3 = registerHalModule_GH100();
                                  if (iVar3 == 0) {
                                    iVar3 = registerHalModule_GB100();
                                    if (iVar3 == 0) {
                                      iVar3 = registerHalModule_GB102();
                                      if (iVar3 == 0) {
                                        iVar3 = registerHalModule_GB10B();
                                        if (iVar3 == 0) {
                                          iVar3 = registerHalModule_GB110();
                                          if (iVar3 == 0) {
                                            iVar3 = registerHalModule_GB112();
                                            if (iVar3 == 0) {
                                              iVar3 = registerHalModule_GB202();
                                              if (iVar3 == 0) {
                                                iVar3 = registerHalModule_GB203();
                                                if (iVar3 == 0) {
                                                  iVar3 = registerHalModule_GB205();
                                                  if (iVar3 == 0) {
                                                    iVar3 = registerHalModule_GB206();
                                                    if (iVar3 == 0) {
                                                      iVar3 = registerHalModule_GB207();
                                                      if (iVar3 == 0) {
                                                        iVar3 = registerHalModule_GB20B();
                                                        if (iVar3 == 0) {
                                                          iVar3 = registerHalModule_GB20C();
                                                          if (iVar3 == 0) {
                                                            iVar3 = registerHalModule_T234D();
                                                            if (iVar3 == 0) {
                                                              iVar3 = registerHalModule_T264D();
                                                              if (iVar3 == 0) {
                                                                                                                                
                                                  rm_check_s0ix_regkey_and_platform_support();
                                                  threadStateInitSetupFlags(0x87);
                                                  return 0;
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
          }
        }
      }
    }
  }
  RmDestroyRegistry(0);
  return iVar3;
}


// ===== 00270380 RmShutdownRm =====

void RmShutdownRm(void)

{
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x11d,"RmShutdownRm",1,"NVRM: shutdown rm\n");
  RmDestroyRegistry(0);
  RmDestroyRm();
  return;
}


// ===== 002703bb osAttachGpu.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void osAttachGpu_cold(undefined8 param_1)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  _DAT_00000000 = param_1;
  (*pcVar1)();
}


// ===== 002703d0 osAttachGpu =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 osAttachGpu(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  char cVar2;
  
  if (param_2 == (undefined8 *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    _DAT_00000000 = param_1;
    (*pcVar1)();
  }
  *(long *)*param_2 = param_1;
  *(undefined8 **)(param_1 + 0x4e0) = param_2;
  osWriteRegistryDword(param_1,"RMSecBusResetEnable",1);
  osWriteRegistryDword(param_1,"RMForcePcieConfigSave",1);
  cVar2 = os_is_vgx_hyper();
  if (cVar2 == '\0') {
    return 0;
  }
  initVGXSpecificRegistry(param_1);
  return 0;
}


// ===== 00270440 osDpcAttachGpu =====

undefined8 osDpcAttachGpu(void)

{
  return 0;
}


// ===== 00270450 osDpcDetachGpu =====

void osDpcDetachGpu(void)

{
  return;
}


// ===== 00270460 osHandleGpuLost =====

undefined8 osHandleGpuLost(long param_1,char param_2)

{
  long lVar1;
  long *plVar2;
  
  if (param_1 == 0) {
    plVar2 = (long *)0x0;
    lVar1 = 0;
  }
  else {
    plVar2 = *(long **)(param_1 + 0x4e0);
    lVar1 = 0;
    if (plVar2 != (long *)0x0) {
      lVar1 = *plVar2;
    }
  }
  if ((*(char *)(param_1 + 0x44c) != '\0') &&
     (*(int *)(lVar1 + 8) != **(int **)(plVar2[0x21] + 0x20))) {
    if (param_2 != '\0') {
      nvErrorLog_va(param_1,0x4f,"GPU has fallen off the bus.");
    }
    gpuNotifySubDeviceEvent_IMPL(param_1,0xbf,0,0,0x4f,0);
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: GPU has fallen off the bus.\n",
              *(undefined4 *)((long)plVar2 + 0x14),(char)plVar2[3],
              *(undefined1 *)((long)plVar2 + 0x19),*(undefined1 *)((long)plVar2 + 0x1a));
    lVar1 = *(long *)(param_1 + 0x3c60);
    if ((lVar1 != 0) && (*(char *)(lVar1 + 0x1c) != '\0')) {
      nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: GPU serial number is %s.\n",
                *(undefined4 *)((long)plVar2 + 0x14),(char)plVar2[3],
                *(undefined1 *)((long)plVar2 + 0x19),*(undefined1 *)((long)plVar2 + 0x1a),
                lVar1 + 0x1c);
    }
    gpuSetDisconnectedProperties_IMPL(param_1);
    if ((*(char *)(param_1 + 0x909) != '\0') && (*(long *)(param_1 + 0x1c18) != 0)) {
      krcRcAndNotifyAllChannels_IMPL(param_1,*(long *)(param_1 + 0x1c18),0x4f,0);
    }
    RmLogGpuCrash(param_1);
    if (*(char *)(param_1 + 0x486) == '\0') {
      return 0;
    }
    *(uint *)(plVar2 + 2) = *(uint *)(plVar2 + 2) | 0x8000;
  }
  return 0;
}


// ===== 002705f0 RmCheckForExternalGpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte RmCheckForExternalGpu(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar6;
  ulong uVar4;
  long lVar5;
  byte bVar7;
  byte local_59;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  short local_48;
  undefined2 local_46;
  int local_44;
  undefined4 local_3e;
  undefined2 local_3a;
  
  bVar7 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x878);
  local_59 = 0;
  uVar6 = (undefined1)((ulong)uVar1 >> 8);
  while( true ) {
    lVar5 = clFindP2PBrdg_IMPL(param_2,(int)((ulong)uVar1 >> 0x20),uVar6,&local_4b,&local_4a,
                               &local_49,&local_48,&local_46);
    if (lVar5 == 0) {
      return 0;
    }
    if (local_48 == -0x7f7a) {
      local_3e = 0;
      local_3a = 0;
      iVar3 = rmGpuLocksAcquire(0,0x400000);
      if (iVar3 != 0) {
        return 0;
      }
      local_3e = CONCAT22(local_3e._2_2_,local_46);
      iVar3 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800a55,&local_3e,6);
      rmGpuLocksRelease(0,0);
      if (iVar3 != 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x1e0,"RmCheckForExternalGpu",4,
                     "NVRM: Error 0x%08x on eGPU Approval for Bridge ID: 0x%08x\n",iVar3,local_46);
        return 0;
      }
      if ((char)local_3a != '\0') {
        local_59 = local_59 | local_3a._1_1_ == '\x03';
      }
    }
    iVar3 = clSetPortPcieCapOffset_IMPL(param_2,lVar5,&local_44);
    if (iVar3 != 0) {
      return 0;
    }
    uVar4 = osPciReadDword(lVar5,local_44);
    uVar6 = local_4b;
    if ((uVar4 & 0x1000000) != 0) {
      uVar2 = osPciReadDword(lVar5,local_44 + 0x14);
      bVar7 = bVar7 | (~uVar2 & 0x60) == 0;
      uVar6 = local_4b;
    }
    if ((local_59 & bVar7) != 0) break;
    local_4b = uVar6;
    uVar2 = osPciReadDword(lVar5,local_44);
    if ((uVar2 & 0xf00000) == 0x400000) {
      return 0;
    }
  }
  return local_59 & bVar7;
}


// ===== 002707f0 osInitMapping =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 osInitMapping(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  char cVar4;
  long lVar5;
  
  lVar5 = 0;
  lVar1 = *(long *)(g_pSys + 0x208);
  if ((param_1 != 0) && (lVar5 = 0, *(long **)(param_1 + 0x4e0) != (long *)0x0)) {
    lVar5 = **(long **)(param_1 + 0x4e0);
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x571,"osInitMapping",1,"NVRM: osInitMapping:\n");
  (**(code **)(param_1 + 0x170))(param_1,0x30,0);
  (**(code **)(param_1 + 0x170))(param_1,0xc,0xf800);
  lVar3 = g_pSys;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(g_pSys + 0x208);
    cVar4 = os_pat_supported();
    if (cVar4 == '\0') {
      *(undefined1 *)(lVar3 + 0x88) = 1;
    }
    clInit_IMPL(param_1,uVar2);
  }
  *(uint *)(lVar5 + 0x48) = *(uint *)(lVar5 + 0x48) | 0x20;
  return 0;
}


// ===== 002708d0 RmInitPrivateState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 RmInitPrivateState(long *param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined4 uVar11;
  bool bVar12;
  undefined4 local_4c;
  long local_40 [2];
  
  *param_1 = 0;
  if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
    puVar1 = (undefined8 *)param_1[0x21];
    uVar8 = os_map_kernel_space(*puVar1,os_page_size,1);
    puVar1[4] = uVar8;
    puVar2 = *(undefined4 **)(param_1[0x21] + 0x20);
    if (puVar2 == (undefined4 *)0x0) {
      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x640,"RmInitPrivateState",4,
                   "NVRM: failed to map GPU registers (DISABLE_INTERRUPTS).\n");
      return 0;
    }
    uVar11 = *puVar2;
    uVar10 = CONCAT44(puVar2[0x280],puVar2[1]);
    os_unmap_kernel_space(puVar2,os_page_size);
    local_4c = 0;
    *(undefined8 *)(param_1[0x21] + 0x20) = 0;
  }
  else {
    local_4c = *(undefined4 *)((long)param_1 + 0x29c);
    uVar10 = 0;
    uVar11 = 0;
  }
  iVar4 = os_alloc_mem(local_40,0x260);
  if (iVar4 == 0) {
    uVar9 = 0;
    uVar6 = 0xfffffffe;
    if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
      uVar6 = gpuGenerate32BitId(*(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
                                 *(undefined1 *)((long)param_1 + 0x19));
      uVar9 = (ulong)*(uint *)((long)param_1 + 0x14) << 0x20 | (ulong)*(byte *)(param_1 + 3) << 8 |
              (ulong)*(byte *)((long)param_1 + 0x19);
    }
    iVar4 = gpumgrRegisterGpuId(uVar6,uVar9);
    if (iVar4 == 0) {
      *(undefined4 *)((long)param_1 + 0x24) = uVar6;
      gpumgrSetProbedFlags(uVar6,*(byte *)(param_1 + 2) >> 4 & 1);
      cVar3 = nv_requires_dma_remap(param_1);
      *(undefined4 *)((long)param_1 + 0x32c) = 0xffffffff;
      uVar5 = 0xffffffff;
      if (cVar3 != '\0') {
        uVar5 = uVar6;
      }
      *(undefined4 *)(param_1 + 5) = uVar5;
      lVar7 = gpumgrGetGpuArch_IMPL(uVar10 >> 0x20,local_4c,0);
      if (lVar7 != 0) {
        iVar4 = (**(code **)(lVar7 + 0x70))(lVar7);
        if (iVar4 == 0) {
          iVar4 = (**(code **)(lVar7 + 0x68))(lVar7,0);
        }
        nv_set_dma_address_size(param_1,iVar4);
        if (((*(byte *)(param_1 + 2) & 0x10) == 0) && (*(char *)(lVar7 + 0x80) != '\0')) {
          *(undefined1 *)(param_1 + 0x56) = 1;
          bVar12 = *(char *)(lVar7 + 0x81) != '\0';
        }
        else {
          *(undefined1 *)(param_1 + 0x56) = 0;
          bVar12 = false;
        }
        *(bool *)((long)param_1 + 0x2b1) = bVar12;
        uVar6 = (**(code **)(lVar7 + 0x78))(lVar7);
        *(undefined4 *)(param_1 + 0x57) = uVar6;
        *(undefined1 *)((long)param_1 + 0x349) = *(undefined1 *)(lVar7 + 0x80);
        kvgpumgrAttachGpu(*(undefined4 *)((long)param_1 + 0x24));
        os_mem_set(local_40[0],0,0x260);
        *(undefined4 *)(local_40[0] + 0x4c) = 0x40;
        *(undefined4 *)(local_40[0] + 8) = uVar11;
        *(ulong *)(local_40[0] + 0x250) = uVar10;
        *(undefined4 *)(local_40[0] + 0x244) = 0xffffffff;
        *param_1 = local_40[0];
        return 1;
      }
      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x673,"RmInitPrivateState",4,
                   "NVRM: failed to get GpuArch for 0x%x/0x%x.\n",uVar10 >> 0x20,local_4c);
      gpumgrUnregisterGpuId(uVar6);
      os_free_mem(local_40[0]);
    }
    else {
      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x661,"RmInitPrivateState",4,
                   "NVRM: failed to register GPU with GPU manager.\n");
      os_free_mem(local_40[0]);
    }
  }
  else {
    nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x64f,"RmInitPrivateState",4,
                 "NVRM: failed to allocate private device state.\n");
  }
  return 0;
}


// ===== 00270c40 RmClearPrivateState =====

void RmClearPrivateState(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  long lVar21;
  undefined8 *puVar22;
  undefined8 local_1b8 [49];
  
  puVar22 = (undefined8 *)0x0;
  if (param_1 != (undefined8 *)0x0) {
    puVar22 = (undefined8 *)*param_1;
  }
  if ((*(byte *)((long)param_1 + 0x11) & 0x10) != 0) {
    *puVar22 = 0;
  }
  uVar11 = puVar22[0x40];
  uVar6 = *(undefined4 *)((long)puVar22 + 0x4c);
  uVar12 = puVar22[0x3a];
  uVar7 = *(undefined4 *)(puVar22 + 0x3b);
  uVar13 = puVar22[0x41];
  uVar14 = puVar22[0x3d];
  uVar8 = *(undefined4 *)(puVar22 + 0x3e);
  uVar15 = puVar22[0x42];
  uVar1 = *(undefined1 *)((long)puVar22 + 500);
  uVar16 = puVar22[0x4a];
  uVar2 = *(undefined1 *)(puVar22 + 0x43);
  uVar3 = *(undefined1 *)((long)puVar22 + 0x259);
  uVar9 = *(undefined4 *)((long)puVar22 + 0x244);
  uVar17 = puVar22[0x3f];
  uVar18 = puVar22[0x44];
  uVar5 = *(undefined2 *)(puVar22 + 0x45);
  uVar4 = *(undefined1 *)((long)puVar22 + 0x22a);
  uVar19 = *(undefined8 *)((long)puVar22 + 0x22c);
  uVar20 = *(undefined8 *)((long)puVar22 + 0x234);
  uVar10 = *(undefined4 *)(puVar22 + 1);
  lVar21 = 0;
  do {
    *(undefined8 *)((long)local_1b8 + lVar21) = *(undefined8 *)((long)puVar22 + lVar21 + 0x50);
    *(undefined8 *)((long)local_1b8 + lVar21 + 8) = *(undefined8 *)((long)puVar22 + lVar21 + 0x58);
    *(undefined8 *)((long)local_1b8 + lVar21 + 0x10) =
         *(undefined8 *)((long)puVar22 + lVar21 + 0x60);
    lVar21 = lVar21 + 0x18;
  } while (lVar21 != 0x180);
  portMemSet(puVar22,0,0x260);
  puVar22[0x3f] = uVar17;
  *(undefined4 *)((long)puVar22 + 0x4c) = uVar6;
  puVar22[0x40] = uVar11;
  puVar22[0x3a] = uVar12;
  puVar22[0x41] = uVar13;
  *(undefined4 *)(puVar22 + 0x3b) = uVar7;
  puVar22[0x42] = uVar15;
  puVar22[0x3d] = uVar14;
  *(undefined1 *)(puVar22 + 0x43) = uVar2;
  *(undefined4 *)(puVar22 + 0x3e) = uVar8;
  puVar22[0x44] = uVar18;
  *(undefined1 *)((long)puVar22 + 500) = uVar1;
  *(undefined2 *)(puVar22 + 0x45) = uVar5;
  *(undefined1 *)((long)puVar22 + 0x22a) = uVar4;
  *(undefined8 *)((long)puVar22 + 0x22c) = uVar19;
  *(undefined8 *)((long)puVar22 + 0x234) = uVar20;
  puVar22[0x4a] = uVar16;
  *(undefined1 *)((long)puVar22 + 0x259) = uVar3;
  *(undefined4 *)((long)puVar22 + 0x244) = uVar9;
  *(undefined4 *)(puVar22 + 1) = uVar10;
  lVar21 = 0;
  do {
    *(undefined8 *)((long)puVar22 + lVar21 + 0x50) = *(undefined8 *)((long)local_1b8 + lVar21);
    *(undefined8 *)((long)puVar22 + lVar21 + 0x58) = *(undefined8 *)((long)local_1b8 + lVar21 + 8);
    *(undefined8 *)((long)puVar22 + lVar21 + 0x60) =
         *(undefined8 *)((long)local_1b8 + lVar21 + 0x10);
    lVar21 = lVar21 + 0x18;
  } while (lVar21 != 0x180);
  *(uint *)(puVar22 + 9) = *(uint *)(puVar22 + 9) | 0x80;
  return;
}


// ===== 00270f50 RmFreePrivateState =====

void RmFreePrivateState(long *param_1)

{
  long lVar1;
  
  lVar1 = *param_1;
  gpumgrUnregisterGpuId(*(undefined4 *)((long)param_1 + 0x24));
  kvgpumgrDetachGpu(*(undefined4 *)((long)param_1 + 0x24));
  RmDestroyRegistry(param_1);
  if (lVar1 != 0) {
    portMemFree(*(undefined8 *)(lVar1 + 0x1d0));
    os_free_mem(lVar1);
  }
  *param_1 = 0;
  return;
}


// ===== 00270fa0 RmPartiallyInitAdapter =====

undefined8 RmPartiallyInitAdapter(long param_1)

{
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x6f0,"RmPartiallyInitAdapter",1,
               "NVRM: %s: %04x:%02x:%02x.0\n","RmPartiallyInitAdapter",
               *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
               *(undefined1 *)(param_1 + 0x19));
  nv_start_rc_timer(param_1);
  return 1;
}


// ===== 00271000 RmShutdownAdapter =====

void RmShutdownAdapter(long *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 local_30;
  
  lVar5 = g_pSys;
  if ((((param_1 == (long *)0x0) || (plVar3 = (long *)*param_1, plVar3 == (long *)0x0)) ||
      (lVar4 = *plVar3, lVar4 == 0)) || ((*(byte *)(plVar3 + 9) & 0x40) == 0)) {
    RmClearPrivateState(param_1);
  }
  else {
    uVar1 = *(undefined4 *)(lVar4 + 0x7b4);
    uVar2 = *(undefined4 *)(lVar4 + 0x7a4);
    RmUnixFreeRmApi();
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    if ((*(char *)((long)param_1 + 0x2fe) == '\0') ||
       (iVar7 = serverLockAllClients(g_resServ), iVar7 == 0)) {
      iVar7 = rmGpuLocksAcquire(0,0x800001);
      if (iVar7 == 0) {
        iVar7 = gpumgrThreadEnableExpandedGpuVisibility();
        if (iVar7 != 0) {
          nvAssertOkFailedNoLog
                    (iVar7,"gpumgrThreadEnableExpandedGpuVisibility()",
                     "arch/nvalloc/unix/src/osinit.c",0x99f);
        }
        RmDestroyPowerManagement(param_1);
        freeNbsiTable(lVar4);
        uVar8 = *(uint *)(plVar3 + 9);
        if (*(long *)(lVar5 + 0x208) != 0) {
          if ((uVar8 & 0x20) == 0) {
            if ((uVar8 & 0x100) != 0) {
              clTeardownPcie_IMPL(lVar4,*(undefined8 *)(g_pSys + 0x208));
              uVar8 = *(uint *)(plVar3 + 9);
            }
          }
          else {
            clTeardown_IMPL(lVar4,*(undefined8 *)(g_pSys + 0x208));
            uVar8 = *(uint *)(plVar3 + 9);
          }
        }
        if ((uVar8 & 0x10) != 0) {
          krcWatchdogShutdown_IMPL(lVar4,*(undefined8 *)(lVar4 + 0x1c18),0);
          *(uint *)(plVar3 + 9) = *(uint *)(plVar3 + 9) & 0xffffffef;
        }
        rmapiSetDelPendingClientResourcesFromGpuMask();
        rmapiDelPendingDevices(1 << ((byte)uVar2 & 0x1f));
        uVar8 = *(uint *)(plVar3 + 9);
        if ((uVar8 & 8) != 0) {
          iVar7 = gpuStateUnload_IMPL(lVar4,0);
          if (iVar7 == 0) {
            uVar8 = *(uint *)(plVar3 + 9);
          }
          else {
            nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/osinit.c",0x9bf);
            uVar8 = *(uint *)(plVar3 + 9);
          }
        }
        if (((uVar8 & 4) != 0) && (iVar7 = gpuStateDestroy_IMPL(lVar4), iVar7 != 0)) {
          nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/osinit.c",0x9c5);
        }
        if ((*(char *)(lVar4 + 0x90a) != '\0') &&
           (iVar7 = dceclientDceRmInit_IMPL(lVar4,*(undefined8 *)(lVar4 + 0x1bb0),0), iVar7 != 0)) {
          nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x9cd,"RmShutdownAdapter",4,
                       "NVRM: DCE firmware RM Shutdown failure\n");
        }
        if (*(char *)(lVar4 + 0x45f) != '\0') {
          nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x9d3,"RmShutdownAdapter",1,
                       "NVRM: Disable Clocks\n");
          iVar7 = 0x80;
          do {
            nv_disable_clk(param_1,iVar7);
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x86);
        }
        RmFreeX86EmuState(lVar4);
        gpumgrDetachGpu(uVar2);
        gpumgrDestroyDevice(uVar1);
        gpumgrThreadDisableExpandedGpuVisibility();
        if (((*(byte *)((long)plVar3 + 0x49) & 2) != 0) && ((int)param_1[5] != -1)) {
          uVar6 = *(undefined8 *)(g_pSys + 0x230);
          iVar7 = vmmGetVaspaceFromId_IMPL(uVar6,(int)param_1[5],0xf2,&local_30);
          if (iVar7 == 0) {
            vmmDestroyVaspace_IMPL(uVar6,local_30);
          }
        }
        RmClearPrivateState(param_1);
        RmUnInitAcpiMethods(lVar5);
        rmGpuLocksRelease(0,0);
        rmGpuLockFree(uVar1);
      }
      if (*(char *)((long)param_1 + 0x2fe) != '\0') {
        serverUnlockAllClients(g_resServ);
      }
    }
  }
  nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: Tearing down registers\n",
            *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
            *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
  lVar5 = param_1[0x21];
  if ((lVar5 != 0) && (*(long *)(lVar5 + 0x18) != 0)) {
    osUnmapKernelSpace(*(long *)(lVar5 + 0x18),*(undefined8 *)(lVar5 + 8));
    *(undefined8 *)(param_1[0x21] + 0x18) = 0;
    *(undefined8 *)(param_1[0x21] + 0x20) = 0;
  }
  return;
}


// ===== 00271500 RmInitAdapter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8 RmInitAdapter(long *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  short sVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  char cVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  undefined1 *puVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  undefined1 uVar23;
  char *pcVar24;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  undefined8 extraout_RDX_05;
  undefined8 extraout_RDX_06;
  undefined8 extraout_RDX_07;
  undefined8 *puVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  uint uVar28;
  bool bVar29;
  undefined1 auVar30 [16];
  char *pcVar31;
  undefined8 uVar32;
  long *local_108;
  long local_100;
  long local_f8;
  undefined4 local_d0;
  undefined4 local_cc;
  uint local_c8;
  int local_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
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
  
  local_d0 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: RmInitAdapter\n",*(undefined4 *)((long)param_1 + 0x14),
            (char)param_1[3],*(undefined1 *)((long)param_1 + 0x19),
            *(undefined1 *)((long)param_1 + 0x1a));
  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffffff77;
  nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: RmSetupRegisters for 0x%x:0x%x\n",
            *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
            *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a),
            *(undefined2 *)((long)param_1 + 0x1c),*(undefined2 *)((long)param_1 + 0x1e));
  nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: pci config info:\n",
            *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
            *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
  nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x:    registers look  like: 0x%llx 0x%llx",
            *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
            *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a),
            *(undefined8 *)param_1[0x21],((undefined8 *)param_1[0x21])[1]);
  puVar14 = (undefined8 *)param_1[0x28];
  if (puVar14 != (undefined8 *)0x0) {
    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x:    fb        looks like: 0x%llx 0x%llx\n",
              *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
              *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a),*puVar14,
              puVar14[1]);
  }
  puVar14 = (undefined8 *)param_1[0x21];
  if (puVar14[3] != 0) {
    nvAssertFailedNoLog("aperture->map == NULL","arch/nvalloc/unix/src/osinit.c",0xa8);
  }
  uVar13 = osMapKernelSpace(*puVar14,puVar14[1],1,3);
  puVar14[3] = uVar13;
  puVar14[4] = uVar13;
  if (*(long *)(param_1[0x21] + 0x18) == 0) {
    lVar20 = 0;
    iVar9 = 0x59;
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to map regs registers!!\n",
              *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
              *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
    uVar27 = 0x600;
    uVar26 = 0x10;
    lVar19 = 0;
  }
  else {
    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: Successfully mapped framebuffer and registers\n",
              *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
              *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: final mappings:\n",
              *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
              *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
    puVar14 = (undefined8 *)param_1[0x21];
    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x:     regs: 0x%llx 0x%llx 0x%p\n",
              *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
              *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a),*puVar14,
              puVar14[1],puVar14[3]);
    lVar4 = *param_1;
    *(undefined4 *)(lVar4 + 0x4c) = 0x59;
    if (((int)param_1[5] == -1) ||
       (iVar9 = vmmCreateVaspace_IMPL
                          (*(undefined8 *)(g_pSys + 0x230),0xf2,(int)param_1[5],0,0,
                           0xffffffffffffffff,0,0,0,0x4000000,&local_80), iVar9 == 0)) {
      *(uint *)(lVar4 + 0x48) = *(uint *)(lVar4 + 0x48) | 0x200;
      lVar22 = g_pSys;
      if ((char)param_1[0x5f] == '\0') {
LAB_00271789:
        lVar20 = 0;
        lVar19 = 0;
      }
      else {
        if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
          *(undefined1 *)((long)param_1 + 0x2f9) = 1;
          goto LAB_00271789;
        }
        uVar12 = *(uint *)(*param_1 + 0x254) >> 0x14 & 0x3f0;
        if (uVar12 == 400) {
          iVar9 = 5;
        }
        else {
          uVar28 = *(uint *)(*param_1 + 0x254) >> 0x14 & 0xf;
          if (uVar12 < 0x191) {
            if (uVar12 == 0x170) {
              iVar9 = 4 - (uint)(uVar28 == 0);
            }
            else if (uVar12 == 0x180) {
              iVar9 = 6;
            }
            else {
              if (uVar12 != 0x160) goto LAB_00272b90;
              iVar9 = (6 < uVar28) + 1;
            }
          }
          else if (uVar12 == 0x1a0) {
            iVar9 = (uint)(uVar28 == 0xb) * 3 + 8;
          }
          else if (uVar12 == 0x1b0) {
            iVar9 = (-(uint)(uVar28 < 0xb) & 0xfffffffd) + 0xc;
          }
          else {
LAB_00272b90:
            iVar9 = 0;
          }
        }
        portMemSet(&local_c0,0,0x40);
        lVar19 = nv_get_firmware(param_1,0,iVar9,&local_c0,&local_b8);
        if (lVar19 == 0) {
          if (*(char *)((long)param_1 + 0x2fa) == '\0') {
            lVar20 = 0;
            iVar9 = 0x56;
            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x7b9,"RmFetchGspRmImages",4,
                         "NVRM: No firmware image found\n");
            uVar27 = 0x81a;
            uVar26 = 0x61;
            goto LAB_002717aa;
          }
          *(undefined1 *)((long)param_1 + 0x2f9) = 0;
          lVar20 = 0;
        }
        else {
          lVar20 = 0;
          if ((*(char *)((long)param_1 + 0x2fb) != '\0') &&
             (lVar20 = nv_get_firmware(param_1,1,iVar9,&local_90,&local_88), lVar20 == 0)) {
            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x7c7,"RmFetchGspRmImages",4,
                         "NVRM: Failed to load gsp_log_*.bin, no GSP-RM logs will be printed (non-fatal)\n"
                        );
          }
          *(undefined1 *)((long)param_1 + 0x2f9) = 1;
        }
      }
      iVar9 = gpumgrThreadEnableExpandedGpuVisibility();
      lVar16 = g_pSys;
      if (iVar9 == 0) {
        local_c8 = 0;
        lVar15 = *param_1;
        nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x316,"osInitNvMapping",1,
                     "NVRM: osInitNvMapping:\n");
        iVar9 = gpumgrAllocGpuInstance(&local_d0);
        if (iVar9 == 0) {
          iVar9 = rmGpuLockAlloc(local_d0);
          if (iVar9 != 0) {
            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x325,"osInitNvMapping",4,
                         "NVRM: *** cannot allocate GPU lock\n");
            uVar27 = 0x326;
            uVar26 = 0x20;
            goto LAB_002725a2;
          }
          iVar9 = gpumgrCreateDevice(&local_cc,1 << ((byte)local_d0 & 0x1f),0);
          if (iVar9 != 0) {
            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x32e,"osInitNvMapping",4,
                         "NVRM: *** Cannot attach bc gpu\n");
            rmGpuLockFree(local_d0);
            uVar27 = 0x32f;
            uVar26 = 0x21;
            goto LAB_002725a2;
          }
          puVar14 = (undefined8 *)portMemAllocNonPaged(0x1518);
          if (puVar14 != (undefined8 *)0x0) {
            portMemSet(puVar14,0,0x1518);
            if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
              uVar13 = *(undefined8 *)param_1[0x28];
              puVar14[1] = 0;
              puVar14[4] = uVar13;
              puVar14[3] = *(undefined8 *)param_1[0x21];
              uVar13 = *(undefined8 *)(param_1[0x21] + 0x18);
              *(undefined4 *)((long)puVar14 + 0x54) = 0;
              *puVar14 = uVar13;
              lVar21 = param_1[0x1c];
              puVar14[2] = 0;
              puVar14[5] = lVar21;
              puVar14[8] = *(undefined8 *)(param_1[0x21] + 8);
              puVar14[9] = *(undefined8 *)(param_1[0x28] + 8);
              *(int *)(puVar14 + 10) = (int)param_1[0x1d];
              *(int *)((long)puVar14 + 0x1154) = (int)param_1[5];
              *(undefined4 *)((long)puVar14 + 0x115c) = *(undefined4 *)((long)param_1 + 0x32c);
              if ((int)param_1[5] != -1) {
                *(undefined2 *)(param_1 + 0x66) = 0x100;
              }
            }
            else {
              *(undefined1 *)(puVar14 + 0x22c) = 1;
              puVar14[0x22d] = *(undefined8 *)(param_1[0x21] + 0x18);
              puVar14[0x22e] = *(undefined8 *)param_1[0x21];
              puVar14[0x22f] = (ulong)*(uint *)(param_1[0x21] + 8);
              *(undefined4 *)(puVar14 + 0x2a2) = *(undefined4 *)((long)param_1 + 0x29c);
              *(int *)((long)puVar14 + 0x1514) = (int)param_1[5];
            }
            if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
              puVar14[7] = (ulong)*(uint *)((long)param_1 + 0x14) << 0x20 |
                           (ulong)*(byte *)(param_1 + 3) << 8 |
                           (ulong)*(byte *)((long)param_1 + 0x19);
            }
            uVar8 = *(undefined1 *)((long)param_1 + 0x2f9);
            puVar14[0xb] = param_1;
            *(undefined1 *)(puVar14 + 0x22b) = uVar8;
            iVar9 = gpumgrAttachGpu(local_d0,puVar14);
            portMemFree(puVar14);
            if (iVar9 == 0) {
              *(uint *)(lVar15 + 0x48) = *(uint *)(lVar15 + 0x48) | 0x40;
              lVar15 = gpumgrGetGpu(local_d0);
              sysInitRegistryOverrides_IMPL(lVar16);
              sysApplyLockingPolicy_IMPL(lVar16);
              *(undefined4 *)(lVar15 + 0x86c) = *(undefined4 *)((long)param_1 + 0x17c);
              if (param_1[0x28] != 0) {
                *(undefined8 *)(lVar15 + 0x3a20) = *(undefined8 *)(param_1[0x28] + 0x18);
                *(undefined8 *)(lVar15 + 0x850) = *(undefined8 *)param_1[0x28];
              }
              gpumgrSetParentGPU(lVar15,lVar15);
              nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x397,"osInitNvMapping",1,
                           "NVRM: device instance          : %d\n",local_d0);
              nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x398,"osInitNvMapping",1,
                           "NVRM: NV regs using linear address  : 0x%p\n",
                           *(undefined8 *)(lVar15 + 0x938));
              nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x39a,"osInitNvMapping",1,
                           "NVRM: NV fb using linear address  : 0x%p\n",
                           *(undefined8 *)(lVar15 + 0x3a20));
              *(undefined1 *)(lVar15 + 0x449) = 1;
              iVar9 = osReadRegistryDword(lVar15,"RMProcessNonStallIntrInLocklessIsr",&local_c8);
              if (iVar9 == 0 && local_c8 == 0) {
                *(undefined1 *)(lVar15 + 0x449) = 0;
              }
              os_is_vgx_hyper();
              *(undefined1 *)(lVar15 + 0x457) = 1;
              iVar9 = osReadRegistryDword(0,"PreserveVideoMemoryAllocations",&local_c8);
              if ((iVar9 == 0) && (local_c8 != 0)) {
                if (local_c8 == 1) {
                  *(undefined1 *)((long)param_1 + 0x2ff) = 1;
                }
                else {
                  if (local_c8 == 2) {
                    uVar8 = os_supports_kernel_suspend_notifiers();
                    *(undefined1 *)((long)param_1 + 0x2ff) = uVar8;
                  }
                  if (*(char *)((long)param_1 + 0x2ff) == '\0') goto LAB_00271bd0;
                }
                if (((char)param_1[0x56] == '\0') && ((*(byte *)(param_1 + 2) & 0x10) == 0)) {
                  lVar16 = *(long *)(lVar15 + 0x1b78);
                  lVar21 = *(long *)(lVar15 + 0x1b70);
                  *(undefined1 *)(lVar16 + 0x435) = 1;
                  if (*(char *)(lVar16 + 0xd34) == '\0') {
                    *(undefined1 *)(lVar21 + 0x2a0) = 1;
                  }
                }
              }
LAB_00271bd0:
              nv_get_disp_smmu_stream_ids(param_1,&local_c4,&local_80);
              *(bool *)(lVar15 + 0x4b3) = (uint)local_80 == -1;
              if (*(char *)(lVar15 + 0x45e) != '\0') {
                *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x400;
              }
              if (*(char *)(lVar15 + 0x4b2) != '\0') {
                *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x200;
              }
              iVar9 = 0x56;
              lVar16 = gpumgrGetGpu(local_d0);
              gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar16 + 0x7a4));
              uVar13 = sysGetOs_IMPL(lVar22);
              if (*(long *)(g_pSys + 0x208) != 0) {
                iVar9 = clInitPcie_IMPL(lVar16);
                if (iVar9 == 0) {
                  *(uint *)(lVar4 + 0x48) = *(uint *)(lVar4 + 0x48) | 0x100;
                }
                else {
                  uVar27 = 0x84f;
                  uVar26 = 0x40;
                  if (iVar9 != 0x56) goto LAB_002717aa;
                }
              }
              if (((*(char *)(lVar16 + 0x909) == '\0') && (*(char *)(lVar16 + 0x908) == '\0')) &&
                 (iVar9 = gpuBootGspRmProxy_IMPL(lVar16), iVar9 != 0)) {
                nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x859,"RmInitAdapter",4,
                             "NVRM: GSP-RM proxy boot command failed.\n");
                uVar27 = 0x85a;
                uVar26 = 0x62;
              }
              else {
                lVar15 = *(long *)(lVar16 + 0x4e0);
                if ((*(byte *)(lVar15 + 0x11) & 0x10) == 0) {
                  *(undefined1 *)(lVar15 + 700) = 0;
                  if ((*(char *)(lVar16 + 0x4912) == '\0') && (*(char *)(lVar16 + 0x908) == '\0')) {
                    pcVar24 = "not primary";
                    if (*(char *)(lVar16 + 0x45a) == '\0') {
                      iVar10 = nv_set_primary_vga_status(lVar15);
                      if (iVar10 == 0) {
                        uVar8 = *(undefined1 *)(lVar15 + 0x1a);
                        pcVar24 = "primary";
                        if (*(char *)(lVar15 + 700) == '\0') {
                          pcVar24 = "not primary";
                        }
                        uVar23 = *(undefined1 *)(lVar15 + 0x19);
                        uVar2 = *(undefined1 *)(lVar15 + 0x18);
                        uVar26 = *(undefined4 *)(lVar15 + 0x14);
                        pcVar31 = "OS";
                      }
                      else {
                        lVar21 = *(long *)(lVar16 + 7000);
                        lVar5 = *(long *)(g_pSys + 0x208);
                        cVar7 = (**(code **)(lVar21 + 0x218))();
                        uVar23 = 0;
                        if (((cVar7 == '\0') ||
                            (cVar7 = (**(code **)(lVar21 + 0x220))(lVar16), cVar7 != '\0')) ||
                           (lVar5 == 0)) {
                          pcVar24 = "not primary";
                        }
                        else {
                          cVar7 = clUpstreamVgaDecodeEnabled_IMPL(lVar16,lVar5);
                          if (cVar7 == '\0') {
                            pcVar24 = "not primary";
                          }
                          else {
                            uVar23 = 1;
                            pcVar24 = "primary";
                          }
                        }
                        uVar8 = *(undefined1 *)(lVar15 + 0x1a);
                        uVar26 = *(undefined4 *)(lVar15 + 0x14);
                        *(undefined1 *)(lVar15 + 700) = uVar23;
                        uVar23 = *(undefined1 *)(lVar15 + 0x19);
                        uVar2 = *(undefined1 *)(lVar15 + 0x18);
                        pcVar31 = "PCI config space";
                      }
                      nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: %s reports GPU is %s VGA\n",uVar26,
                                uVar2,uVar23,uVar8,pcVar31,pcVar24);
                      if (*(char *)(lVar15 + 700) == '\0') {
                        pcVar24 = "not primary";
                      }
                      else {
                        pcVar24 = "primary";
                      }
                    }
                    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x:  is %s VGA\n",
                              *(undefined4 *)(lVar15 + 0x14),*(undefined1 *)(lVar15 + 0x18),
                              *(undefined1 *)(lVar15 + 0x19),*(undefined1 *)(lVar15 + 0x1a),pcVar24)
                    ;
                    cVar7 = rm_get_uefi_console_status(lVar15);
                    *(char *)(lVar15 + 0x348) = cVar7;
                    pcVar24 = "not primary";
                    if (cVar7 != '\0') {
                      pcVar24 = "primary";
                    }
                    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x:  is %s UEFI console device\n",
                              *(undefined4 *)(lVar15 + 0x14),*(undefined1 *)(lVar15 + 0x18),
                              *(undefined1 *)(lVar15 + 0x19),*(undefined1 *)(lVar15 + 0x1a),pcVar24)
                    ;
                    bVar29 = true;
                    if (*(char *)(lVar15 + 0x348) == '\0') {
                      bVar29 = *(char *)(lVar15 + 700) != '\0';
                    }
                    *(bool *)(lVar16 + 0x447) = bVar29;
                    lVar15 = *(long *)(lVar16 + 0x4e0);
                  }
                  else {
                    lVar15 = *(long *)(lVar16 + 0x4e0);
                  }
                }
                local_80 = 0;
                lVar21 = *(long *)(lVar16 + 0x1b78);
                lVar5 = *(long *)(&DAT_00001b90 + lVar16);
                cVar7 = os_is_vgx_hyper();
                if ((((cVar7 == '\0') && (*(char *)(lVar16 + 0x908) == '\0')) &&
                    (cVar7 = (**(code **)(lVar16 + 0x2b8))(), cVar7 != '\0')) &&
                   ((*(byte *)(lVar15 + 0x11) & 2) == 0)) {
                  uVar17 = rm_get_uefi_console_size(lVar15,&local_80);
                  if (uVar17 == 0) {
                    uVar17 = (ulong)(*(char *)(lVar15 + 700) != '\0') << 0x12;
                  }
                  else if ((local_80 != 0) && (lVar5 != 0)) {
                    *(bool *)(lVar5 + 0xad0a) = **(ulong **)(lVar15 + 0x140) == local_80;
                  }
                  if (*(char *)(lVar16 + 0x45a) == '\0') {
                    uVar17 = uVar17 + 0xffff & 0xffffffffffff0000;
                  }
                  else {
                    *(ulong *)(lVar21 + 0xb40) = local_80;
                  }
                  *(ulong *)(lVar21 + 0xb38) = uVar17;
                }
                RmInitAcpiMethods(uVar13,lVar22,lVar16);
                uVar13 = extraout_RDX;
                if (*(char *)(lVar16 + 0x45f) != '\0') {
                  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x868,"RmInitAdapter",1,
                               "NVRM: Enable Clocks to Max\n");
                  iVar10 = 0x80;
                  local_80 = local_80 & 0xffffffff00000000;
                  do {
                    iVar11 = nv_get_max_freq(param_1,iVar10,&local_80);
                    if (iVar11 == 0) {
                      iVar11 = nv_enable_clk(param_1,iVar10);
                      if (iVar11 == 0) {
                        uVar13 = 0x272901;
                        iVar11 = nv_set_freq(param_1,iVar10,local_80 & 0xffffffff);
                        if (iVar11 == 0) {
                          nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x50b,"RmEnableDeviceClks",1
                                       ,"NVRM: NVRM: Set Freq:%d for Clk:%d\n",local_80 & 0xffffffff
                                       ,iVar10);
                        }
                        else {
                          nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x507,"RmEnableDeviceClks",1
                                       ,"NVRM: NVRM: Set Freq failed for Clk:%d\n",iVar10);
                          uVar13 = extraout_RDX_02;
                        }
                      }
                      else {
                        nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x500,"RmEnableDeviceClks",1,
                                     "NVRM: NVRM: Clk prepare enable failed for Clk:%d\n",iVar10);
                        uVar13 = extraout_RDX_04;
                      }
                    }
                    else {
                      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x4f9,"RmEnableDeviceClks",1,
                                   "NVRM: NVRM: Max Freq fetch failed for Clk:%d\n",iVar10);
                      uVar13 = extraout_RDX_03;
                    }
                    iVar10 = iVar10 + 1;
                  } while (iVar10 != 0x86);
                }
                if (*(char *)(lVar16 + 0x909) == '\0') {
                  if (*(char *)(lVar16 + 0x90a) == '\0') {
                    if (*(char *)((long)param_1 + 0x2f9) != '\0') {
                      if (*(char *)((long)param_1 + 0x2fa) == '\0') {
                        uVar27 = 0x88b;
                        uVar26 = 0x60;
                        goto LAB_002717aa;
                      }
                      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x890,"RmInitAdapter",2,
                                   "NVRM: Falling back to monolithic RM\n");
                      uVar13 = extraout_RDX_00;
                    }
                  }
                  else {
                    iVar9 = dceclientDceRmInit_IMPL(lVar16,*(undefined8 *)(lVar16 + 0x1bb0),1);
                    uVar13 = extraout_RDX_05;
                    if (iVar9 != 0) {
                      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x881,"RmInitAdapter",4,
                                   "NVRM: Cannot initialize DCE firmware RM\n");
                      uVar27 = 0x882;
                      uVar26 = 0x62;
                      goto LAB_002717aa;
                    }
                  }
                }
                else {
                  iVar9 = kgspInitRm_IMPL(lVar16,*(undefined8 *)(lVar16 + 0x1ba8),&local_c0);
                  uVar13 = extraout_RDX_01;
                  if (iVar9 != 0) {
                    nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x877,"RmInitAdapter",4,
                                 "NVRM: Cannot initialize GSP firmware RM\n");
                    uVar27 = 0x878;
                    uVar26 = 0x62;
                    goto LAB_002717aa;
                  }
                }
                if (*(long *)(lVar16 + 0x1b80) != 0) {
                  kdispSetWarPurgeSatellitesOnCoreFree_IMPL(*(long *)(lVar16 + 0x1b80),1,uVar13);
                }
                if (*(char *)(lVar16 + 0x4912) == '\0') {
                  gpumgrGetGpu(local_d0);
                }
                else {
                  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x80;
                  gpumgrGetGpu(local_d0);
                }
                *(uint *)(*param_1 + 0x48) = *(uint *)(*param_1 + 0x48) | 3;
                iVar9 = RmInitX86EmuState(lVar16);
                if (iVar9 == 0) {
                  if (*(char *)(lVar16 + 0x7a0) == '\0') {
                    sVar3 = *(short *)((long)param_1 + 0x1e);
                    iVar9 = (**(code **)(lVar16 + 0x178))(lVar16,0x2c,&local_80);
                    if (iVar9 == 0) {
                      puVar18 = nb_id_table;
                      do {
                        if (((uint)local_80 & 0xffff) == 0x174b) {
                          goto LAB_00272d51;
                        }
                        piVar1 = (int *)(puVar18 + 0xc);
                        puVar18 = puVar18 + 0xc;
                      } while (*piVar1 != 0);
                    }
                    else {
                      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0xa9a,
                                   "initVendorSpecificRegistry",4,
                                   "NVRM: %s: Cannot read NV_CONFIG_PCI_NV_11\n");
                    }
                  }
                  goto LAB_00272199;
                }
                nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x8a9,"RmInitAdapter",4,
                             "NVRM: RmInitX86Emu failed, bailing out of RmInitAdapter\n");
                uVar27 = 0x8a8;
                uVar26 = 0x32;
              }
              goto LAB_002717aa;
            }
            gpumgrDestroyDevice(local_cc);
            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x37f,"osInitNvMapping",4,
                         "NVRM: *** Cannot attach gpu\n");
            rmGpuLockFree(local_d0);
            uVar27 = 0x37e;
            uVar26 = 0x22;
            goto LAB_002725a2;
          }
          nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x339,"osInitNvMapping",4,
                       "NVRM: *** Cannot allocate gpuAttachArg\n");
          rmGpuLockFree(local_d0);
          uVar26 = 0x20;
          uVar27 = 0x33a;
        }
        else {
          nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x31c,"osInitNvMapping",4,
                       "NVRM: *** Cannot get valid gpu instance\n");
          uVar27 = 0x31d;
          uVar26 = 0x20;
LAB_002725a2:
          if (iVar9 == 0x56) {
            *(undefined4 *)(lVar4 + 0x4c) = 0x56;
          }
        }
        nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x83a,"RmInitAdapter",4,
                     "NVRM: osInitNvMapping failed, bailing out of RmInitAdapter\n");
      }
      else {
        uVar27 = 0x82b;
        uVar26 = 0x27;
      }
    }
    else {
      lVar19 = 0;
      lVar20 = 0;
      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x806,"RmInitAdapter",4,
                   "NVRM: Cannot configure the device for DMA\n");
      uVar27 = 0x807;
      uVar26 = 0x26;
    }
LAB_002717aa:
    *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffffefff;
    gpumgrThreadDisableExpandedGpuVisibility();
    RmShutdownAdapter(param_1);
  }
  uVar13 = 0;
  nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: RmInitAdapter failed! (0x%x:0x%x:%d)\n",
            *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
            *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a),uVar26,iVar9
            ,uVar27);
LAB_00271812:
  nv_put_firmware(lVar19);
  nv_put_firmware(lVar20);
  gpumgrSetCurrentGpuInstance(0xffffffff);
  return uVar13;
  while (piVar1 = (int *)(puVar18 + 0xc), puVar18 = puVar18 + 0xc, *piVar1 != 0) {
LAB_00272d51:
    if (((uint)local_80 >> 0x10 == *(uint *)(puVar18 + 4)) && (sVar3 == *(short *)(puVar18 + 8))) {
      osWriteRegistryDword(lVar16,"RmOverrideSupportChipsetAspm",2);
      break;
    }
  }
LAB_00272199:
  if ((*(char *)(lVar16 + 0x908) == '\0') && ((*(byte *)(param_1 + 2) & 0x10) == 0)) {
    initNbsiTable(lVar16);
  }
  uVar26 = local_d0;
  lVar15 = gpumgrGetGpu(local_d0);
  uVar13 = *(undefined8 *)(g_pSys + 0x208);
  if (lVar15 == 0) {
    local_108 = (long *)0x0;
    local_f8 = 0;
  }
  else {
    local_108 = *(long **)(lVar15 + 0x4e0);
    local_f8 = 0;
    if (local_108 != (long *)0x0) {
      local_f8 = *local_108;
    }
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x528,"RmInitNvDevice",1,"NVRM: RmInitNvDevice:\n");
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x52a,"RmInitNvDevice",1,
               "NVRM: device instance          : 0x%08x\n",uVar26);
  iVar9 = gpumgrStatePreInitGpu(lVar15);
  if (iVar9 == 0) {
    cVar7 = RmCheckForExternalGpu(lVar15,uVar13);
    if (cVar7 != '\0') {
      *(undefined1 *)(lVar15 + 0x486) = 1;
      *(undefined1 *)((long)local_108 + 0x2fe) = 1;
    }
    iVar9 = gpumgrStateInitGpu(lVar15);
    if (iVar9 == 0) {
      *(uint *)(local_f8 + 0x48) = *(uint *)(local_f8 + 0x48) | 4;
      if (*(long *)(lVar15 + 7000) != 0) {
        kbifCheckAndRearmMSI_IMPL();
      }
      if (*(long *)(lVar15 + 0x1c20) != 0) {
        intrSetIntrEn_IMPL(*(long *)(lVar15 + 0x1c20),0);
      }
      iVar9 = gpumgrStateLoadGpu(lVar15,0);
      if (iVar9 == 0) {
        *(uint *)(local_f8 + 0x48) = *(uint *)(local_f8 + 0x48) | 8;
        RmInitScalability(lVar15);
        gpumgrThreadDisableExpandedGpuVisibility();
        iVar9 = rmGpuLocksAcquire(0,0x400000);
        uVar13 = 0;
        uVar27 = 0;
        uVar26 = 0;
        if (iVar9 == 0) {
          iVar9 = osVerifySystemEnvironment(lVar16);
          rmGpuLocksRelease(0,0);
          if (iVar9 == 0) {
            if (*(long *)(lVar16 + 0x1c20) != 0) {
              intrSetIntrEn_IMPL(*(long *)(lVar16 + 0x1c20),1);
            }
            iVar9 = rmGpuLocksAcquire(0,0x400000);
            if (iVar9 == 0) {
              lVar15 = *(long *)(lVar16 + 0x1c18);
              if (lVar15 == 0) {
LAB_00272f03:
                nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x900,"RmInitAdapter",1,
                             "NVRM: krcWatchdogInit returned _NOT_SUPPORTED. For Kepler GPUs in PGOB mode, this is normal\n"
                            );
              }
              else {
                iVar9 = (**(code **)(lVar15 + 0x168))(lVar16,lVar15,0);
                if (iVar9 != 0) {
                  if (iVar9 != 0x56) {
                    nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x906,"RmInitAdapter",4,
                                 "NVRM: krcWatchdogInit failed, bailing out of RmInitAdapter\n");
                    rmGpuLocksRelease(0,0);
                    uVar27 = 0x905;
                    uVar26 = 0x41;
                    goto LAB_002717aa;
                  }
                  goto LAB_00272f03;
                }
                krcWatchdogDisable_IMPL(lVar15,0);
                *(uint *)(lVar4 + 0x48) = *(uint *)(lVar4 + 0x48) | 0x10;
              }
              rmGpuLocksRelease(0,0);
              nv_start_rc_timer(param_1);
              uVar26 = local_d0;
              *(undefined4 *)(lVar4 + 0x4c) = 0;
              local_80 = 0;
              local_78 = 0;
              local_70 = 0;
              local_68 = 0;
              local_60 = 0;
              local_58 = 0;
              local_50 = 0;
              local_c4 = 0;
              puVar14 = (undefined8 *)rmapiGetInterface(4);
              portMemSet(param_1 + 0x62,0,0x14);
              iVar9 = rmGpuLocksAcquire(0,0x400000);
              if (iVar9 == 0) {
                iVar9 = (*(code *)puVar14[1])(puVar14,0,0,0,0,param_1 + 0x62,4);
                uVar32 = extraout_RDX_06;
                if (iVar9 == 0) {
                  local_80 = CONCAT44(local_80._4_4_,uVar26);
                  iVar9 = (*(code *)*puVar14)(puVar14,(int)param_1[0x62],(int)param_1[0x62],
                                              (long)param_1 + 0x314,0x80,&local_80,0x38);
                  uVar32 = extraout_RDX_07;
                  if (iVar9 == 0) {
                    local_c4 = 0;
                    uVar32 = 4;
                    puVar25 = puVar14;
                    iVar9 = (*(code *)*puVar14)(puVar14,(int)param_1[0x62],
                                                *(undefined4 *)((long)param_1 + 0x314),param_1 + 99,
                                                0x2080,&local_c4,4,uVar13);
                    if (iVar9 == 0) {
                      uVar13 = (*(code *)*puVar14)(puVar14,(int)param_1[0x62],(int)param_1[99],
                                                   (long)param_1 + 0x31c,0x402c,0,0,puVar25);
                      if ((int)uVar13 != 0) {
                        *(undefined4 *)((long)param_1 + 0x31c) = 0;
                      }
                      uVar32 = 0;
                      iVar9 = (*(code *)*puVar14)(puVar14,(int)param_1[0x62],
                                                  *(undefined4 *)((long)param_1 + 0x314),
                                                  param_1 + 100,0x73,0);
                      if (iVar9 != 0) {
                        *(undefined4 *)(param_1 + 100) = 0;
                      }
                      rmGpuLocksRelease(0,0,uVar32,uVar13);
                      goto LAB_00273101;
                    }
                  }
                }
                iVar9 = 0xffff;
                rmGpuLocksRelease(0,0,uVar32);
                RmUnixFreeRmApi(param_1);
                uVar27 = 0x914;
                uVar26 = 0x44;
              }
              else if ((char)iVar9 == '\0') {
                uVar27 = 0x914;
                iVar9 = 0xffff;
                uVar26 = 0x44;
              }
              else {
LAB_00273101:
                if ((*(byte *)(param_1 + 2) & 0x10) == 0) {
                  lVar15 = rmapiGetInterface(4);
                  plVar6 = *(long **)(lVar16 + 0x4e0);
                  if (plVar6 == (long *)0x0) {
                    local_100 = 0;
                  }
                  else {
                    local_100 = *plVar6;
                  }
                  iVar9 = rmGpuLocksAcquire(0,0x400000);
                  if (iVar9 == 0) {
                    puVar14 = (undefined8 *)portMemAllocNonPaged(0x234);
                    if (puVar14 == (undefined8 *)0x0) {
                      iVar9 = 0x51;
                      rmGpuLocksRelease(0,0);
                      uVar27 = 0x91e;
                      uVar26 = 0x45;
                    }
                    else {
                      portMemSet(puVar14,0,0x234);
                      *puVar14 = 0x3500000003;
                      *(undefined4 *)((long)puVar14 + 0xc) = 0x3d;
                      *(undefined4 *)((long)puVar14 + 0x14) = 0x44;
                      iVar9 = (**(code **)(lVar15 + 0x38))
                                        (lVar15,(int)plVar6[0x62],(int)plVar6[99],0x20800102,puVar14
                                         ,0x234);
                      if (iVar9 == 0) {
                        *(bool *)(local_100 + 0x240) = *(int *)(puVar14 + 1) == 1;
                        *(bool *)((long)plVar6 + 0x324) = *(int *)(puVar14 + 2) == 1;
                      }
                      bVar29 = true;
                      if (*(char *)(lVar16 + 0x454) == '\0') {
                        bVar29 = *(char *)(*(long *)(lVar16 + 0x4d8) + 0x80) != '\0';
                      }
                      *(bool *)((long)plVar6 + 0x326) = bVar29;
                      if (*(int *)(puVar14 + 3) != 0) {
                        bVar29 = *(char *)(*(long *)(lVar16 + 0x4d8) + 0x80) != '\0' ||
                                 *(int *)(puVar14 + 3) == 1;
                      }
                      *(bool *)((long)plVar6 + 0x327) = bVar29;
                      iVar10 = *(int *)(puVar14 + 3);
                      if (iVar10 == 1) {
                        *(undefined1 *)(plVar6 + 0x65) = 1;
                      }
                      else if (iVar10 == 2) {
                        *(undefined1 *)(plVar6 + 0x65) = 2;
                      }
                      else if (iVar10 == 0) {
                        *(undefined1 *)(plVar6 + 0x65) = 0;
                      }
                      portMemFree(puVar14);
                      if (iVar9 == 0) {
                        lVar21 = RmGetGpuUuidRaw(plVar6);
                        if (lVar21 == 0) {
                          iVar9 = 0x12;
                        }
                        else {
                          *(undefined1 *)((long)plVar6 + 0x359) = 0;
                          uVar13 = 0x48;
                          iVar9 = (**(code **)(lVar15 + 0x38))
                                            (lVar15,(int)plVar6[0x62],(int)plVar6[99],0x20803601,
                                             &local_80);
                          if (iVar9 == 0) {
                            portMemCopy((long)plVar6 + 0x359,0x40,(long)&local_80 + 6,0x40);
                          }
                          else {
                            if ((char)plVar6[0x5f] != '\0') {
                              lVar21 = portStringLength(&DAT_00cdd733);
                              portStringCopy((long)plVar6 + 0x359,0x40,&DAT_00cdd733,lVar21 + 1);
                            }
                            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x22b,
                                         "RmGetFirmwareVersion",1,
                                         "NVRM: %s: Failed to query gpu firmware version, status=0x%x\n"
                                         ,"RmGetFirmwareVersion",iVar9,uVar13);
                          }
                          puVar14 = (undefined8 *)portMemAllocNonPaged(0x7c);
                          if (puVar14 != (undefined8 *)0x0) {
                            portMemSet(puVar14,0,0x7c);
                            *(undefined4 *)((long)puVar14 + 0xc) = 1;
                            *puVar14 = 2;
                            auVar30 = (**(code **)(lVar15 + 0x38))
                                                (lVar15,(int)plVar6[0x62],(int)plVar6[99],0x20800810
                                                 ,puVar14,0x7c);
                            if (auVar30._0_4_ == 0) {
                              uVar12 = *(uint *)(puVar14 + 1);
                              os_snprintf((long)plVar6 + 0x34a,0xf,"%02x.%02x.%02x.%02x.%02x",
                                          uVar12 >> 0x18,uVar12 >> 0x10 & 0xff,uVar12 >> 8 & 0xff,
                                          uVar12 & 0xff,*(undefined4 *)(puVar14 + 2));
                            }
                            else {
                              nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x263,
                                           "RmGetVbiosVersion",1,
                                           "NVRM: %s: Failed to query vbios version, status=0x%x\n",
                                           "RmGetVbiosVersion",auVar30);
                            }
                            portMemFree(puVar14);
                            rmGpuLocksRelease(0,0);
                            goto LAB_00273426;
                          }
                          iVar9 = 0x51;
                        }
                      }
                      rmGpuLocksRelease(0,0);
                      uVar27 = 0x91e;
                      uVar26 = 0x45;
                    }
                  }
                  else {
                    uVar27 = 0x91e;
                    uVar26 = 0x45;
                  }
                }
                else {
LAB_00273426:
                  RmI2cAddGpuPorts(param_1);
                  *(uint *)(lVar4 + 0x48) = *(uint *)(lVar4 + 0x48) | 0x80;
                  lVar15 = gpuGetKernelFifoShared_IMPL(lVar16);
                  local_80 = 0;
                  local_c8 = 0;
                  if (lVar15 != 0) {
                    iVar9 = (**(code **)(lVar15 + 0x298))
                                      (lVar16,lVar15,&local_80,&local_c8,*(code **)(lVar15 + 0x298))
                    ;
                    if (iVar9 == 0) {
                      param_1[0x29] = local_80 + *(long *)param_1[0x28];
                      param_1[0x2a] = (ulong)local_c8;
                    }
                    else if (iVar9 != 0x56) {
                      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x937,"RmInitAdapter",4,
                                   "NVRM: kfifoGetUserdBar1MapInfo failed, bailing out of RmInitAdapter\n"
                                  );
                      uVar27 = 0x936;
                      uVar26 = 0x42;
                      goto LAB_002717aa;
                    }
                  }
                  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffffefff;
                  *(undefined1 *)(lVar22 + 0x89) = 1;
                  RmInitPowerManagement(param_1);
                  if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
LAB_00273510:
                    if (*(char *)(lVar4 + 0x240) != '\0') {
                      local_c4 = 0;
                      iVar9 = nv_acpi_get_powersource(&local_c4);
                      if ((iVar9 == 0) && (iVar9 = rmGpuLocksAcquire(0,0), iVar9 == 0)) {
                        RmPowerSourceChangeEvent(param_1,local_c4 == 0);
                        rmGpuLocksRelease(0,0);
                      }
                    }
                    uVar12 = *(int *)(*(long *)(g_pSys + 0x208) + 0xb4) - 0x104d;
                    if ((uVar12 < 0x1b) && ((0x4000201UL >> ((ulong)uVar12 & 0x3f) & 1) != 0)) {
                      *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 8;
                    }
                    uVar13 = 1;
                    nv_printf(1,"NVRM: GPU %04x:%02x:%02x.%x: RmInitAdapter succeeded!\n",
                              *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
                              *(undefined1 *)((long)param_1 + 0x19),
                              *(undefined1 *)((long)param_1 + 0x1a));
                    goto LAB_00271812;
                  }
                  lVar22 = RmGetGpuUuidRaw(*(undefined8 *)(lVar16 + 0x4e0));
                  if (lVar22 == 0) {
                    iVar9 = 0x59;
                    nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x716,"RmRegisterGpudb",4,
                                 "NVRM: Failed to get UUID\n");
                    uVar27 = 0x948;
                    uVar26 = 0x43;
                  }
                  else {
                    iVar9 = gpudbRegisterGpu(lVar22,lVar16 + 0x1d58,*(undefined8 *)(lVar16 + 0x878))
                    ;
                    if (iVar9 == 0) goto LAB_00273510;
                    nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x71e,"RmRegisterGpudb",4,
                                 "NVRM: Failed to register GPU with GPU data base\n");
                    uVar27 = 0x948;
                    uVar26 = 0x43;
                  }
                }
              }
            }
            else {
              uVar27 = 0;
              uVar26 = 0;
            }
          }
          else {
            if (iVar9 == 0x45) {
              *(undefined4 *)(lVar4 + 0x4c) = 0x45;
            }
            nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x8e3,"RmInitAdapter",4,
                         "NVRM: osVerifySystemEnvironment failed, bailing!\n");
            uVar27 = 0x8dc;
            uVar26 = 0x11;
          }
        }
        goto LAB_002717aa;
      }
      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x55b,"RmInitNvDevice",4,
                   "NVRM: *** Cannot load state into the device\n");
      uVar26 = 0x25;
      uVar27 = 0x55d;
    }
    else {
      nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x53f,"RmInitNvDevice",4,
                   "NVRM: *** Cannot initialize the device\n");
      uVar26 = 0x24;
      uVar27 = 0x540;
    }
  }
  else {
    nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x531,"RmInitNvDevice",4,
                 "NVRM: *** Cannot pre-initialize the device\n");
    uVar26 = 0x23;
    uVar27 = 0x532;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0x8ba,"RmInitAdapter",4,
               "NVRM: RmInitNvDevice failed, bailing out of RmInitAdapter\n");
  if (iVar9 == 0x1c) {
    *(undefined4 *)(lVar4 + 0x4c) = 0x1c;
    nv_printf(4,
              "NVRM: GPU %04x:%02x:%02x.%x: GPU does not have the necessary power cables connected.\n"
              ,*(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
              *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
  }
  goto LAB_002717aa;
}


// ===== 00273820 RmPartiallyDisableAdapter =====

void RmPartiallyDisableAdapter(undefined8 param_1)

{
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0xa08,"RmPartiallyDisableAdapter",1,
               "NVRM: %s: RM is in SW Persistence mode\n");
  nv_stop_rc_timer(param_1);
  return;
}


// ===== 00273870 RmDisableAdapter =====

void RmDisableAdapter(long *param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  plVar1 = (long *)*param_1;
  if ((plVar1 != (long *)0x0) && (lVar2 = *plVar1, lVar2 != 0)) {
    gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar2 + 0x7a4));
    if (*(long *)(lVar2 + 0x1c20) != 0) {
      intrSetIntrEn_IMPL(*(long *)(lVar2 + 0x1c20),0);
    }
    if ((*(char *)(lVar2 + 0x450) != '\0') || (*(char *)(lVar2 + 0x44f) != '\0')) {
      *(undefined1 *)(lVar2 + 0x456) = 1;
      *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x1000;
    }
    if ((*(char *)((long)param_1 + 0x2fe) == '\0') ||
       (iVar4 = serverLockAllClients(g_resServ), iVar4 == 0)) {
      iVar4 = rmGpuLocksAcquire(0,0x800001);
      if (iVar4 == 0) {
        uVar5 = gpumgrGetGpuMask(lVar2);
        rmapiSetDelPendingClientResourcesFromGpuMask(uVar5);
        rmapiDelPendingDevices(uVar5);
        nv_stop_rc_timer(param_1);
        lVar3 = *(long *)(g_pSys + 0x208);
        sysGetOs_IMPL();
        if (lVar3 == 0) {
          uVar6 = *(uint *)(plVar1 + 9);
        }
        else {
          clTeardown_IMPL(lVar2,*(undefined8 *)(g_pSys + 0x208));
          uVar6 = *(uint *)(plVar1 + 9) & 0xffffffdf;
          *(uint *)(plVar1 + 9) = uVar6;
        }
        if ((uVar6 & 0x10) != 0) {
          krcWatchdogShutdown_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1c18),0);
          uVar6 = *(uint *)(plVar1 + 9) & 0xffffffef;
          *(uint *)(plVar1 + 9) = uVar6;
        }
        if ((uVar6 & 8) != 0) {
          iVar4 = gpuStateUnload_IMPL(lVar2,0);
          if (iVar4 != 0) {
            nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/osinit.c",0xa5d);
          }
          *(uint *)(plVar1 + 9) = *(uint *)(plVar1 + 9) & 0xfffffff7;
        }
        rmGpuLocksRelease(0,0);
      }
      if (*(char *)((long)param_1 + 0x2fe) != '\0') {
        serverUnlockAllClients(g_resServ);
      }
    }
    gpumgrSetCurrentGpuInstance(0xffffffff);
    return;
  }
  return;
}


// ===== 00273a50 RmGetAdapterStatus =====

undefined8 RmGetAdapterStatus(long *param_1,undefined4 *param_2)

{
  if ((param_1 != (long *)0x0) && (*param_1 != 0)) {
    *param_2 = *(undefined4 *)(*param_1 + 0x4c);
    return 0;
  }
  return 0x40;
}


// ===== 00273a80 osRemoveGpu =====

void osRemoveGpu(undefined8 param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  
  lVar1 = os_pci_init_handle(param_1,param_2,param_3,0,0,0);
  if (lVar1 != 0) {
    os_pci_remove(lVar1);
    return;
  }
  return;
}


// ===== 00273ac0 RmExcludeAdapter =====

int RmExcludeAdapter(long param_1)

{
  int iVar1;
  uint local_1c [3];
  
  local_1c[0] = 0;
  if (*(short *)(param_1 + 0x1e) != 0x1db8) {
    iVar1 = pciPbiGetFeature(*(undefined8 *)(param_1 + 0x48),local_1c);
    if ((iVar1 != 0) || ((local_1c[0] & 0x3f) != 2)) {
      return 0x56;
    }
  }
  iVar1 = gpumgrExcludeGpuId(*(undefined4 *)(param_1 + 0x24));
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osinit.c",0xaf6,"RmExcludeAdapter",4,
               "NVRM: failed to exclude GPU: 0x%x\n",iVar1);
  return iVar1;
}


// ===== 00273b60 osDestroyOsDescriptorFromPhysAddr =====

void osDestroyOsDescriptorFromPhysAddr(long *param_1)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar1 = *param_1;
  lVar3 = memdescGetMemData();
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pPrivate != NULL","arch/nvalloc/unix/src/osmemdesc.c",0x47c);
  }
  cVar2 = memdescGetFlag(param_1,0x800000000000);
  if (cVar2 == '\0') {
    memdescUnmapIommu(param_1,*(undefined4 *)(lVar1 + 0x868));
  }
  else {
    uVar4 = 0;
    if (lVar1 == 0) goto LAB_00273ba6;
  }
  uVar4 = *(undefined8 *)(lVar1 + 0x4e0);
LAB_00273ba6:
  nv_unregister_phys_pages(uVar4,lVar3);
  return;
}


// ===== 00273bf0 osDestroyOsDescriptorFromIoMemory =====

void osDestroyOsDescriptorFromIoMemory(long *param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *param_1;
  lVar2 = memdescGetMemData();
  if (lVar2 != 0) {
    uVar3 = 0;
    if (lVar1 != 0) {
      uVar3 = *(undefined8 *)(lVar1 + 0x4e0);
    }
    nv_unregister_peer_io_mem(uVar3,lVar2);
    return;
  }
  return;
}


// ===== 00273c40 osDestroyOsDescriptorPageArray =====

void osDestroyOsDescriptorPageArray(long *param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long local_30;
  
  lVar1 = *param_1;
  local_30 = memdescGetMemData();
  if (local_30 == 0) {
    nvAssertFailedNoLog("pPrivate != NULL","arch/nvalloc/unix/src/osmemdesc.c",0x4a2);
  }
  if ((*(char *)(g_pSys + 400) == '\0') || (cVar3 = memdescGetContiguity(param_1,0), cVar3 != '\0'))
  {
    lVar6 = (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & param_1[3]) != 0) +
            ((ulong)param_1[3] >> (os_page_shift - 0xcU & 0x3f));
    if ((0x1000 < os_page_size) && (cVar3 = memdescGetContiguity(param_1,0), cVar3 == '\0')) {
      lVar2 = param_1[3];
      uVar5 = memdescGetPteArrayForGpu(param_1,*param_1,0);
      RmDeflateRmToOsPageArray(uVar5,lVar2);
    }
  }
  else {
    if (*(uint *)(param_1 + 0x2c) != os_page_size) {
      nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                          "arch/nvalloc/unix/src/osmemdesc.c",0x4b0);
      return;
    }
    lVar6 = param_1[3];
  }
  uVar5 = 0;
  if (lVar1 != 0) {
    uVar5 = *(undefined8 *)(lVar1 + 0x4e0);
  }
  nv_unregister_user_pages(uVar5,lVar6,0,&local_30);
  cVar3 = memdescGetFlag(param_1,0x4000000);
  if (cVar3 == '\0') {
    cVar3 = memdescGetFlag(param_1,0x100000000);
    iVar4 = os_unlock_user_pages(lVar6,local_30,cVar3 == '\0');
    if (iVar4 != 0) {
      nvAssertFailedNoLog("status == NV_OK","arch/nvalloc/unix/src/osmemdesc.c",0x4d0);
    }
    return;
  }
  os_free_mem(local_30);
  return;
}


// ===== 00273e20 osDestroyOsDescriptorFromDmaBuf =====

void osDestroyOsDescriptorFromDmaBuf(long *param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 local_38 [8];
  undefined8 local_30;
  
  lVar1 = *param_1;
  uVar4 = memdescGetMemData();
  memdescUnmapIommu(param_1,*(undefined4 *)(lVar1 + 0x868));
  if (*(char *)(g_pSys + 400) != '\0') {
    cVar3 = memdescGetContiguity(param_1,0);
    if (cVar3 == '\0') {
      if (*(uint *)(param_1 + 0x2c) != os_page_size) {
        nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                            "arch/nvalloc/unix/src/osmemdesc.c",0x4e9);
        return;
      }
      goto LAB_00273e73;
    }
  }
  if (0x1000 < os_page_size) {
    cVar3 = memdescGetContiguity(param_1,0);
    if (cVar3 == '\0') {
      lVar2 = param_1[3];
      uVar5 = memdescGetPteArrayForGpu(param_1,*param_1,0);
      RmDeflateRmToOsPageArray(uVar5,lVar2);
    }
  }
LAB_00273e73:
  nv_unregister_sgt(*(undefined8 *)(lVar1 + 0x4e0),local_38,&local_30,uVar4);
  nv_dma_release_dma_buf(local_30);
  return;
}


// ===== 00273f30 osDestroyOsDescriptorFromSgt =====

void osDestroyOsDescriptorFromSgt(long *param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *param_1;
  lVar4 = memdescGetMemData();
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pPrivate != NULL","arch/nvalloc/unix/src/osmemdesc.c",0x50a);
  }
  memdescUnmapIommu(param_1,*(undefined4 *)(lVar1 + 0x868));
  if (*(char *)(g_pSys + 400) != '\0') {
    cVar3 = memdescGetContiguity(param_1,0);
    if (cVar3 == '\0') {
      if (*(uint *)(param_1 + 0x2c) != os_page_size) {
        nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                            "arch/nvalloc/unix/src/osmemdesc.c",0x515);
        return;
      }
      goto LAB_00273f8b;
    }
  }
  if (0x1000 < os_page_size) {
    cVar3 = memdescGetContiguity(param_1,0);
    if (cVar3 == '\0') {
      lVar2 = param_1[3];
      uVar5 = memdescGetPteArrayForGpu(param_1,*param_1,0);
      RmDeflateRmToOsPageArray(uVar5,lVar2);
    }
  }
LAB_00273f8b:
  nv_unregister_sgt(*(undefined8 *)(lVar1 + 0x4e0),&local_38,&local_30,lVar4);
  nv_dma_release_sgt(local_38,local_30);
  return;
}


// ===== 00274070 _createMemdescFromDmaBufSgtHelper =====

int _createMemdescFromDmaBufSgtHelper
              (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,int param_5,
              long *param_6,long *param_7,code *param_8)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  byte bVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined1 uVar13;
  undefined1 local_54;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  uVar6 = os_page_size;
  bVar9 = os_page_shift;
  local_48 = param_4;
  local_40[0] = param_3;
  if ((param_8 != osDestroyOsDescriptorFromDmaBuf) && (param_8 != osDestroyOsDescriptorFromSgt)) {
    nvAssertFailedNoLog("(pMemDataReleaseCallback == osDestroyOsDescriptorFromDmaBuf) || (pMemDataReleaseCallback == osDestroyOsDescriptorFromSgt)"
                        ,"arch/nvalloc/unix/src/osmemdesc.c",0x311);
  }
  uVar4 = param_2 & 0xf000;
  uVar11 = param_2 & 0x1000000;
  if (uVar4 == 0x2000) {
    if ((param_2 & 0x40000) != 0) {
      uVar13 = 2;
      goto joined_r0x002744c8;
    }
    if (uVar11 != 0) goto LAB_00274488;
    local_54 = 0;
    uVar13 = 2;
    uVar12 = 1;
  }
  else {
    uVar13 = uVar4 == 0;
    if ((param_2 & 0x40000) == 0) {
      if (uVar11 != 0) {
        if (uVar4 != 0) goto LAB_00274488;
        nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x334,"_createMemdescFromDmaBufSgtHelper",1
                     ,"NVRM: %s(): Syncpoint type sgt!\n");
        local_54 = 1;
        uVar13 = 1;
        uVar12 = 1;
        goto LAB_002740fc;
      }
      uVar12 = 1;
    }
    else {
joined_r0x002744c8:
      uVar12 = 0;
      if (uVar11 != 0) {
LAB_00274488:
        nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x32c,"_createMemdescFromDmaBufSgtHelper",4
                     ,"NVRM: %s(): Error: Syncpoint memory region should be uncached!!!\n");
        return 0x29;
      }
    }
    local_54 = 0;
  }
LAB_002740fc:
  uVar4 = -(int)uVar6 & param_5 + -1 + (int)uVar6;
  uVar6 = (ulong)(param_2 >> 0x14 & 1) << 0x26;
  if ((param_2 & 0x200000) != 0) {
    uVar6 = uVar6 | 0x100000000;
  }
  if ((param_2 & 0x400000) != 0) {
    uVar6 = uVar6 | 0x200000000;
  }
  iVar5 = memdescCreate(param_6,param_1,(ulong)uVar4,0,0,1,uVar13,uVar6);
  if (iVar5 != 0) {
    return iVar5;
  }
  puVar1 = (undefined8 *)*param_6;
  memdescSetGpuCacheAttrib(puVar1,uVar12);
  memdescSetMemData(puVar1,0,0);
  memdescSetFlag(puVar1,0x200,0);
  memdescSetFlag(puVar1,0x800000,1);
  uVar2 = local_40[0];
  uVar8 = local_48;
  *param_7 = 0;
  uVar12 = *(undefined4 *)((long)puVar1 + 0x74);
  uVar7 = memdescGetPteArrayForGpu(puVar1,*puVar1,0);
  uVar10 = 0;
  if (param_1 != 0) {
    uVar10 = *(undefined8 *)(param_1 + 0x4e0);
  }
  iVar5 = nv_register_sgt(uVar10,uVar7,uVar4 >> (bVar9 & 0x1f),uVar12,param_7,uVar8,uVar2,local_54);
  if (iVar5 != 0) goto LAB_00274474;
  if ((*(char *)(g_pSys + 400) == '\0') ||
     (cVar3 = memdescGetContiguity(puVar1,0), uVar6 = os_page_size, cVar3 != '\0')) {
    uVar6 = (ulong)(uVar4 >> 0xc);
    if (((*(byte *)((long)puVar1 + 9) & 4) == 0) && ((ulong)puVar1[4] < uVar6)) {
      nvAssertOkFailedNoLog
                (2,"memdescSetAllocSizeFields(pMemDesc, size, NV_RM_PAGE_SIZE)",
                 "arch/nvalloc/unix/src/osmemdesc.c",0x36b);
      goto LAB_00274507;
    }
    uVar11 = 0x1000;
LAB_00274307:
    puVar1[3] = uVar6;
    puVar1[7] = (ulong)uVar4;
    *(uint *)(puVar1 + 0x2c) = uVar11;
    uVar6 = memdescGetPhysAddr(puVar1,0,0);
    if ((os_page_size - 1 & uVar6) == 0) {
      if ((*(char *)(g_pSys + 400) == '\0') ||
         (cVar3 = memdescGetContiguity(puVar1,0), cVar3 != '\0')) {
        if ((0x1000 < os_page_size) && (cVar3 = memdescGetContiguity(puVar1,0), cVar3 == '\0')) {
          uVar10 = puVar1[3];
          uVar8 = memdescGetPteArrayForGpu(puVar1,*puVar1,0);
          RmInflateOsToRmPageArray(uVar8,uVar10);
        }
      }
      else if (*(uint *)(puVar1 + 0x2c) != os_page_size) {
        nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                            "arch/nvalloc/unix/src/osmemdesc.c",0x37b);
        goto LAB_00274420;
      }
      memdescSetMemData(*param_6,*param_7,0);
      iVar5 = memdescMapIommu(*param_6,*(undefined4 *)(param_1 + 0x868));
      if (iVar5 == 0) {
        memdescSetMemData(*param_6,*param_7,param_8);
        return 0;
      }
    }
    else {
      nvAssertFailedNoLog(&DAT_00cde643,"arch/nvalloc/unix/src/osmemdesc.c",0x371);
LAB_00274420:
      iVar5 = 0x1f;
    }
  }
  else {
    bVar9 = 0xc;
    uVar11 = (uint)os_page_size;
    if (uVar11 != 0x1000) {
      cVar3 = memdescGetContiguity(puVar1,0);
      bVar9 = 0xc;
      if (cVar3 == '\0') {
        bVar9 = (0xffff < uVar11) << 4 | (uVar6 & 0xaaaaaaaa) != 0 |
                ((uVar6 & 0xff00ff00) != 0) << 3 | ((uVar6 & 0xf0f0f0f0) != 0) << 2 |
                ((uVar6 & 0xcccccccc) != 0) * '\x02';
      }
      else {
        uVar11 = 0x1000;
      }
    }
    uVar6 = (ulong)(uVar4 >> bVar9);
    if (((*(byte *)((long)puVar1 + 9) & 4) != 0) || (uVar6 <= (ulong)puVar1[4])) goto LAB_00274307;
    nvAssertOkFailedNoLog
              (2,"memdescSetAllocSizeFields(pMemDesc, size, os_page_size)",
               "arch/nvalloc/unix/src/osmemdesc.c",0x367);
LAB_00274507:
    iVar5 = 2;
  }
  if ((*(char *)(g_pSys + 400) == '\0') || (cVar3 = memdescGetContiguity(puVar1,0), cVar3 != '\0'))
  {
    if ((0x1000 < os_page_size) && (cVar3 = memdescGetContiguity(puVar1,0), cVar3 == '\0')) {
      uVar10 = puVar1[3];
      uVar8 = memdescGetPteArrayForGpu(puVar1,*puVar1,0);
      RmDeflateRmToOsPageArray(uVar8,uVar10);
    }
  }
  else if (*(uint *)(puVar1 + 0x2c) != os_page_size) {
    nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                        "arch/nvalloc/unix/src/osmemdesc.c",0x394);
  }
  if (*param_7 != 0) {
    uVar10 = 0;
    if (param_1 != 0) {
      uVar10 = *(undefined8 *)(param_1 + 0x4e0);
    }
    nv_unregister_sgt(uVar10,&local_48,local_40);
  }
LAB_00274474:
  memdescDestroy(puVar1);
  return iVar5;
}


// ===== 00274683 osCreateMemFromOsDescriptor.cold =====

void osCreateMemFromOsDescriptor_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002746a0 osCreateMemFromOsDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint osCreateMemFromOsDescriptor
               (long param_1,ulong *param_2,undefined4 param_3,ulong param_4,long *param_5,
               long *param_6,uint param_7,uint param_8)

{
  char cVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong *puVar11;
  uint uVar12;
  byte bVar13;
  uint uVar14;
  byte bVar15;
  undefined4 uVar16;
  ulong uVar17;
  ulong uVar18;
  undefined8 uVar19;
  char *pcVar20;
  char *pcVar21;
  undefined8 *puVar22;
  bool bVar23;
  code *pcVar24;
  uint local_60;
  undefined4 local_54;
  ulong *local_50;
  undefined8 local_48;
  ulong local_40 [2];
  
  uVar5 = param_4 & 0xffffffff;
  plVar3 = (long *)serverutilGetClientUnderLock(param_3);
  if (((param_2 == (ulong *)0x0) || (*param_5 == 0)) || (plVar3 == (long *)0x0)) {
    return 0x3a;
  }
  if (os_page_size != 0x1000) {
    return 0x56;
  }
  uVar2 = (**(code **)(*plVar3 + 0xd8))();
  uVar12 = (uint)param_4;
  if (uVar2 < 2) {
    uVar2 = (**(code **)(*plVar3 + 0xd8))();
    bVar15 = os_page_shift;
    if (uVar2 < 2) {
      if (param_7 - 5 < 2) {
        return 0x56;
      }
      if (param_7 != 3) {
        if (3 < param_7) {
LAB_00274acf:
          if (param_7 != 6) {
            if (param_7 != 4) {
              return 0x1f;
            }
            goto LAB_00275000;
          }
          goto LAB_00274762;
        }
LAB_002747fc:
        if (param_7 != 1) {
          if (param_7 != 2) {
            return 0x56;
          }
          if ((param_4 & 0xf0f0) != 0) {
            return 0x29;
          }
          if ((((param_4 & 0x800000) != 0) &&
              (lVar8 = *(long *)(param_1 + 7000), *(char *)(lVar8 + 0x3cc) == '\0')) &&
             (cVar1 = osIsAdministrator(), cVar1 == '\0')) {
            nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x1eb,
                         "osCreateOsDescriptorFromIoMemory",4,
                         "NVRM: %s(): permission denied, allowPeermapping=%d\n",
                         "osCreateOsDescriptorFromIoMemory",*(undefined1 *)(lVar8 + 0x3cc),param_1);
            return 0x1b;
          }
          lVar8 = *param_5;
          uVar18 = *param_2;
          uVar2 = gpumgrGetGpuAttachInfo(0,local_40);
          if (uVar2 != 0) {
            nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/osmemdesc.c",0x17f);
            return uVar2;
          }
          local_48 = (ulong)local_48._4_4_ << 0x20;
          uVar17 = lVar8 + uVar18;
          do {
            do {
              lVar8 = gpumgrGetNextGpu(local_40[0] & 0xffffffff,&local_48);
              if (lVar8 == 0) {
                uVar18 = *param_2;
                if ((*(char *)(param_1 + 0x491b) != '\0') &&
                   ((uVar18 & 0xffffffff00000000) == 0x7fff00000000)) {
                  uVar18 = uVar18 & 0xffffffff;
                }
                *param_2 = uVar18;
                uVar18 = *param_5 + os_page_size & -os_page_size;
                uVar4 = memdescCreate(param_6,param_1,uVar18,0,1,1,1);
                local_60 = (uint)uVar4;
                if (local_60 != 0) {
                  uVar19 = 0x215;
                  pcVar21 = "osCreateOsDescriptorFromIoMemory";
                  pcVar20 = "NVRM: %s(): error %d while attempting to create the MMIO mapping\n";
                  goto LAB_002752e3;
                }
                puVar22 = (undefined8 *)*param_6;
                memdescSetGpuCacheAttrib(puVar22,(uint)(uVar5 >> 0x12) & 1 ^ 1);
                memdescSetMemData(puVar22,0,0);
                memdescSetFlag(puVar22,0x200,0);
                memdescSetFlag(puVar22,0x80000000,1);
                puVar11 = (ulong *)memdescGetPteArrayForGpu(puVar22,*puVar22,0);
                *puVar11 = *param_2;
                local_50 = (ulong *)0x0;
                if ((*puVar11 & os_page_size - 1) != 0) {
                  nvAssertFailedNoLog(&DAT_00cde643,"arch/nvalloc/unix/src/osmemdesc.c",0x22f);
                  uVar2 = 0x1f;
                  goto LAB_002754ce;
                }
                if ((*(char *)(g_pSys + 400) == '\0') ||
                   (cVar1 = memdescGetContiguity(puVar22,0), uVar5 = os_page_size, cVar1 != '\0')) {
                  bVar15 = os_page_shift;
                  uVar5 = uVar18 >> 0xc;
                  if (((*(byte *)((long)puVar22 + 9) & 4) == 0) && ((ulong)puVar22[4] < uVar5)) {
                    nvAssertOkFailedNoLog
                              (2,"memdescSetAllocSizeFields(pMemDesc, size, NV_RM_PAGE_SIZE)",
                               "arch/nvalloc/unix/src/osmemdesc.c",0x239);
                    goto LAB_0027596d;
                  }
                  puVar22[7] = uVar18;
                  *(undefined4 *)(puVar22 + 0x2c) = 0x1000;
                  puVar22[3] = uVar5;
                  uVar5 = (uVar5 >> (bVar15 - 0xc & 0x3f)) +
                          (ulong)(((long)((1 << (bVar15 - 0xc & 0x1f)) + -1) & uVar5) != 0);
                }
                else {
                  bVar15 = 0xc;
                  uVar14 = (uint)os_page_size;
                  uVar2 = uVar14;
                  if (uVar14 != 0x1000) {
                    cVar1 = memdescGetContiguity(puVar22,0);
                    uVar2 = 0x1000;
                    if (cVar1 == '\0') {
                      bVar15 = (0xffff < uVar14) << 4 | (uVar5 & 0xaaaaaaaa) != 0 |
                               ((uVar5 & 0xff00ff00) != 0) << 3 | ((uVar5 & 0xf0f0f0f0) != 0) << 2 |
                               ((uVar5 & 0xcccccccc) != 0) * '\x02';
                      uVar2 = uVar14;
                    }
                  }
                  uVar5 = uVar18 >> bVar15;
                  if (((*(byte *)((long)puVar22 + 9) & 4) == 0) && ((ulong)puVar22[4] < uVar5)) {
                    nvAssertOkFailedNoLog
                              (2,"memdescSetAllocSizeFields(pMemDesc, size, os_page_size)",
                               "arch/nvalloc/unix/src/osmemdesc.c",0x234);
LAB_0027596d:
                    uVar2 = 2;
                    goto LAB_002754ce;
                  }
                  puVar22[3] = uVar5;
                  puVar22[7] = uVar18;
                  *(uint *)(puVar22 + 0x2c) = uVar2;
                }
                if ((uVar12 >> 0x1e == 2) ||
                   (uVar2 = nv_register_peer_io_mem
                                      (*(undefined8 *)(param_1 + 0x4e0),puVar11,uVar5,&local_50),
                   uVar2 == 0)) {
                  memdescSetMemData(puVar22,local_50,0);
                  uVar2 = memdescMapIommu(puVar22,*(undefined4 *)(param_1 + 0x868));
                  if (uVar2 == 0) {
                    uVar19 = memdescGetMemData(puVar22);
                    memdescSetMemData(puVar22,uVar19,osDestroyOsDescriptorFromIoMemory);
                    return 0;
                  }
LAB_002754ce:
                  if (local_50 != (ulong *)0x0) {
                    nv_unregister_peer_io_mem(*(undefined8 *)(param_1 + 0x4e0));
                  }
                  memdescDestroy(puVar22);
                  return uVar2;
                }
                goto LAB_00275619;
              }
              uVar9 = *(ulong *)(lVar8 + 0x848);
              uVar4 = *(long *)(lVar8 + 0x948) + -1 + uVar9;
              if (((uVar9 <= uVar18) && (uVar18 <= uVar4)) ||
                 ((uVar9 <= uVar17 && (uVar17 <= uVar4)))) {
                nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x189,
                             "osCheckGpuBarsOverlapAddrRange",4,
                             "NVRM: %s(): phys range 0x%016llx-0x%016llx overlaps with GPU BAR0\n",
                             "osCheckGpuBarsOverlapAddrRange",uVar18,uVar17);
                return 0x1e;
              }
            } while ((*(char *)(*(long *)(lVar8 + 0x4d8) + 0x80) != '\0') ||
                    (*(char *)(lVar8 + 0x45a) != '\0'));
            uVar9 = gpumgrGetGpuPhysFbAddr(lVar8);
            lVar7 = gpumgrGetGpuPhysFbAddr(lVar8);
            uVar4 = *(long *)(lVar8 + 0x910) + -1 + lVar7;
            if (((uVar9 <= uVar18) && (uVar18 <= uVar4)) || ((uVar9 <= uVar17 && (uVar17 <= uVar4)))
               ) {
LAB_00274c2b:
              nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x19f,
                           "osCheckGpuBarsOverlapAddrRange",4,
                           "NVRM: %s(): phys range 0x%016llx-0x%016llx overlaps with FB or GPU BAR2\n"
                           ,"osCheckGpuBarsOverlapAddrRange",uVar18,uVar17);
              return 0x1e;
            }
            uVar9 = *(ulong *)(lVar8 + 0x858);
            uVar4 = (uVar9 - 1) + (ulong)*(uint *)(lVar8 + 0x918);
            if (((uVar9 <= uVar18) && (uVar18 <= uVar4)) || ((uVar17 <= uVar4 && (uVar9 <= uVar17)))
               ) goto LAB_00274c2b;
          } while( true );
        }
        if ((uVar12 & 0xb000) != 0x1000) {
          return 0x29;
        }
        if ((param_4 & 0xf0) == 0) {
          return 0x29;
        }
        uVar18 = *param_5 + os_page_size & -os_page_size;
        uVar5 = (ulong)((uint)(uVar5 >> 0x14) & 1) << 0x26;
        bVar23 = (uVar12 & 0x6000000) == 0x4000000;
        if (bVar23) {
          uVar5 = uVar5 | 0x200000000000;
        }
        local_50 = param_2;
        uVar2 = memdescCreate(param_6,param_1,uVar18,0,0,1,0,uVar5);
        if (uVar2 != 0) {
          return uVar2;
        }
        uVar5 = uVar18 >> (bVar15 & 0x3f);
        puVar22 = (undefined8 *)*param_6;
        uVar10 = memdescGetPteArrayForGpu(puVar22,*puVar22,0);
        uVar19 = 0;
        if (param_1 != 0) {
          uVar19 = *(undefined8 *)(param_1 + 0x4e0);
        }
        uVar2 = nv_register_user_pages(uVar19,uVar5,uVar10,0,&local_50,bVar23);
        if (uVar2 != 0) {
LAB_00275619:
          memdescDestroy(puVar22);
          return uVar2;
        }
        memdescSetGpuCacheAttrib(puVar22,uVar12 >> 0x12 & 1 ^ 1);
        memdescSetFlag(puVar22,0x200,0);
        memdescSetFlag(puVar22,0x800000,1);
        if ((*(char *)(g_pSys + 400) == '\0') ||
           (cVar1 = memdescGetContiguity(puVar22,0), uVar17 = os_page_size, cVar1 != '\0')) {
          uVar17 = uVar18 >> 0xc;
          uVar2 = 0x1000;
          if (((*(byte *)((long)puVar22 + 9) & 4) == 0) && ((ulong)puVar22[4] < uVar17)) {
            nvAssertOkFailedNoLog
                      (2,"memdescSetAllocSizeFields(pMemDesc, size, NV_RM_PAGE_SIZE)",
                       "arch/nvalloc/unix/src/osmemdesc.c",0xfa);
            goto LAB_0027544e;
          }
LAB_00274f3e:
          puVar22[3] = uVar17;
          *(uint *)(puVar22 + 0x2c) = uVar2;
          puVar22[7] = uVar18;
          uVar18 = memdescGetPhysAddr(puVar22,0,0);
          if ((os_page_size - 1 & uVar18) != 0) {
            nvAssertFailedNoLog(&DAT_00cde643,"arch/nvalloc/unix/src/osmemdesc.c",0x100);
LAB_0027574b:
            uVar2 = 0x1f;
            goto LAB_00275454;
          }
          if ((*(char *)(g_pSys + 400) == '\0') ||
             (cVar1 = memdescGetContiguity(puVar22,0), cVar1 != '\0')) {
            if ((0x1000 < os_page_size) && (cVar1 = memdescGetContiguity(puVar22,0), cVar1 == '\0'))
            {
              uVar19 = puVar22[3];
              uVar10 = memdescGetPteArrayForGpu(puVar22,*puVar22,0);
              RmInflateOsToRmPageArray(uVar10,uVar19);
            }
          }
          else if (*(uint *)(puVar22 + 0x2c) != os_page_size) {
            nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                                "arch/nvalloc/unix/src/osmemdesc.c",0x10b);
            goto LAB_0027574b;
          }
          memdescSetMemData(puVar22,local_50,0);
          uVar2 = memdescMapIommu(puVar22,*(undefined4 *)(param_1 + 0x868));
          if (uVar2 == 0) {
LAB_00274fcc:
            uVar19 = memdescGetMemData(*param_6);
            memdescSetMemData(*param_6,uVar19,osDestroyOsDescriptorPageArray);
            return 0;
          }
          if (*(char *)(g_pSys + 400) != '\0') goto LAB_002758f7;
          if ((0x1000 < os_page_size) && (cVar1 = memdescGetContiguity(puVar22,0), cVar1 == '\0'))
          goto LAB_002759f9;
        }
        else {
          if (((ulong)*(uint *)(puVar22 + 0x2c) - 1 & os_page_size) != 0) {
            nvAssertFailedNoLog("(os_page_size & (pMemDesc->pageArrayGranularity - 1ULL)) == 0",
                                "arch/nvalloc/unix/src/osmemdesc.c",0xf5);
            goto LAB_00274fcc;
          }
          uVar2 = (uint)os_page_size;
          bVar15 = 0xc;
          if (uVar2 != 0x1000) {
            cVar1 = memdescGetContiguity(puVar22,0);
            if (cVar1 == '\0') {
              bVar15 = (0xffff < uVar2) << 4 | (uVar17 & 0xaaaaaaaa) != 0 |
                       ((uVar17 & 0xff00ff00) != 0) << 3 | ((uVar17 & 0xf0f0f0f0) != 0) << 2 |
                       ((uVar17 & 0xcccccccc) != 0) * '\x02';
            }
            else {
              uVar2 = 0x1000;
            }
          }
          uVar17 = uVar18 >> bVar15;
          if (((*(byte *)((long)puVar22 + 9) & 4) != 0) || (uVar17 <= (ulong)puVar22[4]))
          goto LAB_00274f3e;
          nvAssertOkFailedNoLog
                    (2,"memdescSetAllocSizeFields(pMemDesc, size, os_page_size)",
                     "arch/nvalloc/unix/src/osmemdesc.c",0xf6);
LAB_0027544e:
          uVar2 = 2;
LAB_00275454:
          if (*(char *)(g_pSys + 400) == '\0') {
LAB_00275468:
            if ((0x1000 < os_page_size) && (cVar1 = memdescGetContiguity(puVar22,0), cVar1 == '\0'))
            {
LAB_002759f9:
              uVar19 = puVar22[3];
              uVar10 = memdescGetPteArrayForGpu(puVar22,*puVar22,0);
              RmDeflateRmToOsPageArray(uVar10,uVar19);
            }
          }
          else {
LAB_002758f7:
            cVar1 = memdescGetContiguity(puVar22,0);
            if (cVar1 != '\0') goto LAB_00275468;
            if (*(uint *)(puVar22 + 0x2c) != os_page_size) {
              nvAssertFailedNoLog("os_page_size == pMemDesc->pageArrayGranularity",
                                  "arch/nvalloc/unix/src/osmemdesc.c",0x124);
            }
          }
          uVar19 = 0;
          if (param_1 == 0) goto LAB_00275486;
        }
        uVar19 = *(undefined8 *)(param_1 + 0x4e0);
LAB_00275486:
        nv_unregister_user_pages(uVar19,uVar5,0,&local_50);
        memdescDestroy(puVar22);
        return uVar2;
      }
    }
    else if (param_7 != 3) {
      if (3 < param_7) {
        if (param_7 == 5) goto LAB_00274c80;
        goto LAB_00274acf;
      }
      goto LAB_002747fc;
    }
  }
  else {
    if (1 < param_7 - 3) {
      if (1 < param_7 - 5) {
        return 0x56;
      }
      uVar2 = (**(code **)(*plVar3 + 0xd8))();
      if (uVar2 < 2) {
        return 0x56;
      }
      if (param_7 == 5) {
LAB_00274c80:
        lVar8 = 0;
        if (param_1 != 0) {
          lVar8 = *(long *)(param_1 + 0x4e0);
        }
        local_54 = 0;
        local_48 = 0;
        local_40[0] = 0;
        if (((param_4 & 0x100000) == 0) || (lVar7 = *(long *)(lVar8 + 0x2e8), lVar7 == 0)) {
          lVar7 = *(long *)(lVar8 + 0x2e0);
        }
        bVar23 = (param_4 & 0x400000) != 0;
        if (bVar23) {
          nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x45f,"osCreateOsDescriptorFromDmaBufPtr"
                       ,1,"NVRM: %s(): RO DMA Mapping - flags [%x]!\n",
                       "osCreateOsDescriptorFromDmaBufPtr",uVar5);
        }
        uVar2 = nv_dma_import_dma_buf(lVar7,param_2,bVar23,&local_54,local_40,&local_48);
        if (uVar2 != 0) {
          if (uVar2 == 0x56) {
            uVar12 = 0x56;
            uVar19 = 1;
          }
          else {
            uVar19 = 4;
            uVar12 = uVar2;
          }
          nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x468,"osCreateOsDescriptorFromDmaBufPtr"
                       ,uVar19,"NVRM: Error (%d) while trying to import dma_buf!\n",uVar12);
          return uVar2;
        }
        goto LAB_00274d30;
      }
LAB_00274762:
      if (param_1 == 0) {
                    /* WARNING: Does not return */
        pcVar24 = (code *)invalidInstructionException();
        (*pcVar24)();
      }
      uVar18 = *param_2;
      uVar17 = param_2[1];
      uVar4 = nv_dma_import_sgt(*(undefined8 *)(*(long *)(param_1 + 0x4e0) + 0x2e0),uVar18,uVar17);
      local_60 = (uint)uVar4;
      if (local_60 == 0) {
        pcVar24 = osDestroyOsDescriptorFromSgt;
        uVar2 = _createMemdescFromDmaBufSgtHelper
                          (param_1,uVar5,uVar17,uVar18,(int)*param_5 + 1,param_6,&local_50);
        if (uVar2 != 0) {
          nv_dma_release_sgt(uVar18,uVar17,pcVar24);
          return uVar2;
        }
        return 0;
      }
      uVar19 = 0x43b;
      pcVar21 = "osCreateOsDescriptorFromSgtPtr";
      pcVar20 = "NVRM: %s(): Error (%d) while trying to import sgt!\n";
      goto LAB_002752e3;
    }
    (**(code **)(*plVar3 + 0xd8))();
    if (param_7 != 3) {
LAB_00275000:
      lVar8 = 0;
      if (param_1 != 0) {
        lVar8 = *(long *)(param_1 + 0x4e0);
      }
      local_54 = 0;
      local_48 = 0;
      local_40[0] = 0;
      if (param_2 != (ulong *)(long)(int)param_2) {
        nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x405,"osCreateOsDescriptorFromFileHandle",
                     4,"NVRM: %s(): fd must fit within a signed 32-bit integer!\n");
        return 0x1f;
      }
      if (((param_4 & 0x100000) == 0) || (lVar7 = *(long *)(lVar8 + 0x2e8), lVar7 == 0)) {
        lVar7 = *(long *)(lVar8 + 0x2e0);
      }
      bVar23 = (param_4 & 0x400000) != 0;
      if (bVar23) {
        nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x410,"osCreateOsDescriptorFromFileHandle",
                     1,"NVRM: %s(): RO DMA Mapping - flags [%x]!\n",
                     "osCreateOsDescriptorFromFileHandle",uVar5);
      }
      uVar19 = nv_dma_import_from_fd
                         (lVar7,(ulong)param_2 & 0xffffffff,bVar23,&local_54,local_40,&local_48);
      if ((uint)uVar19 != 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",0x419,"osCreateOsDescriptorFromFileHandle",
                     4,"NVRM: %s(): Error (%d) while trying to import fd!\n",
                     "osCreateOsDescriptorFromFileHandle",uVar19);
        return (uint)uVar19;
      }
LAB_00274d30:
      uVar19 = local_48;
      uVar2 = _createMemdescFromDmaBufSgtHelper
                        (param_1,uVar5,local_48,local_40[0],local_54,param_6,&local_50);
      if (uVar2 != 0) {
        nv_dma_release_dma_buf(uVar19);
        return uVar2;
      }
      return 0;
    }
  }
  if (param_8 < 2) {
    return 0x56;
  }
  lVar8 = 0;
  if (param_1 != 0) {
    lVar8 = *(long *)(param_1 + 0x4e0);
  }
  if ((param_4 & 0xf0) != 0) {
    return 0x29;
  }
  uVar5 = 0;
  uVar12 = uVar12 & 0x1000000;
  if ((param_4 & 0x1000000) != 0) {
    uVar12 = 1;
    uVar5 = (ulong)(*(char *)(lVar8 + 0x331) == '\0') << 0x2f;
  }
  if ((param_4 & 0x100000) != 0) {
    uVar5 = uVar5 | 0x4000000000;
  }
  if ((os_page_size - 1 & (ulong)param_2) != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED64(base, os_page_size)","arch/nvalloc/unix/src/osmemdesc.c",
                        0x29b);
    return 0x1f;
  }
  uVar18 = *param_5 + os_page_size & -os_page_size;
  local_60 = memdescCreate(param_6,param_1,uVar18,0,1,1,uVar12,uVar5);
  uVar4 = (ulong)local_60;
  if (local_60 != 0) {
    uVar19 = 0x2a2;
    pcVar21 = "osCreateOsDescriptorFromPhysAddr";
    pcVar20 = "NVRM: %s(): error %d while creating memdesc for kernel memory\n";
LAB_002752e3:
    nvDbg_Printf("arch/nvalloc/unix/src/osmemdesc.c",uVar19,pcVar21,4,pcVar20,pcVar21,uVar4);
    return local_60;
  }
  puVar22 = (undefined8 *)*param_6;
  memdescSetMemData(puVar22,0,0);
  memdescSetFlag(puVar22,0x800000,1);
  puVar6 = (undefined8 *)memdescGetPteArrayForGpu(puVar22,*puVar22,0);
  bVar15 = os_page_shift;
  *puVar6 = param_2;
  uVar5 = uVar18 >> (bVar15 & 0x3f);
  lVar7 = portMemAllocNonPaged(uVar5 * 8);
  uVar17 = 0;
  uVar2 = 0;
  if (lVar7 == 0) goto LAB_002755f3;
  if (uVar5 != 0) {
    do {
      *(ulong **)(lVar7 + uVar17 * 8) = (ulong *)(os_page_size * uVar17 + (long)param_2);
      uVar17 = (ulong)((int)uVar17 + 1);
    } while (uVar17 < uVar5);
  }
  local_50 = (ulong *)0x0;
  uVar2 = nv_register_phys_pages(lVar8,lVar7,uVar5,*(undefined4 *)((long)puVar22 + 0x74),&local_50);
  if (uVar2 != 0) goto LAB_002755f3;
  if ((*(char *)(g_pSys + 400) == '\0') ||
     (cVar1 = memdescGetContiguity(puVar22,0), uVar5 = os_page_size, cVar1 != '\0')) {
    uVar5 = uVar18 >> 0xc;
    if (((*(byte *)((long)puVar22 + 9) & 4) == 0) && ((ulong)puVar22[4] < uVar5)) {
      nvAssertOkFailedNoLog
                (2,"memdescSetAllocSizeFields(pMemDesc, size, NV_RM_PAGE_SIZE)",
                 "arch/nvalloc/unix/src/osmemdesc.c",0x2c7);
      goto LAB_002755c3;
    }
    uVar16 = 0x1000;
LAB_00274a1b:
    puVar22[3] = uVar5;
    puVar22[7] = uVar18;
    *(undefined4 *)(puVar22 + 0x2c) = uVar16;
    cVar1 = memdescGetFlag(puVar22,0x800000000000);
    if (cVar1 != '\0') {
LAB_00274a7e:
      memdescSetMemData(puVar22,local_50,osDestroyOsDescriptorFromPhysAddr);
      portMemFree(lVar7);
      return 0;
    }
    memdescSetMemData(puVar22,local_50,0);
    uVar2 = memdescMapIommu(puVar22,*(undefined4 *)(param_1 + 0x868));
    if (uVar2 == 0) goto LAB_00274a7e;
    if (local_50 == (ulong *)0x0) goto LAB_002755f3;
LAB_00275988:
    uVar19 = *(undefined8 *)(param_1 + 0x4e0);
  }
  else {
    uVar2 = (uint)os_page_size;
    uVar17 = os_page_size & 0xffffffff;
    if (uVar2 == 0x1000) {
      bVar13 = 0;
      bVar15 = 8;
LAB_00275554:
      bVar15 = bVar15 | bVar13;
      bVar13 = ((uVar5 & 0xf0f0f0f0) != 0) << 2;
    }
    else {
      cVar1 = memdescGetContiguity(puVar22,0);
      if (cVar1 == '\0') {
        bVar13 = (0xffff < uVar2) << 4;
        bVar15 = ((uVar5 & 0xff00ff00) != 0) << 3;
        goto LAB_00275554;
      }
      bVar15 = 8;
      uVar17 = 0x1000;
      bVar13 = 4;
    }
    uVar16 = (undefined4)uVar17;
    uVar5 = uVar18 >> ((uVar17 & 0xaaaaaaaa) != 0 | bVar13 | bVar15 |
                      ((uVar17 & 0xcccccccc) != 0) * '\x02');
    if (((*(byte *)((long)puVar22 + 9) & 4) != 0) || (uVar5 <= (ulong)puVar22[4]))
    goto LAB_00274a1b;
    nvAssertOkFailedNoLog
              (2,"memdescSetAllocSizeFields(pMemDesc, size, os_page_size)",
               "arch/nvalloc/unix/src/osmemdesc.c",0x2c3);
LAB_002755c3:
    uVar2 = 2;
    if (local_50 == (ulong *)0x0) goto LAB_002755f3;
    uVar19 = 0;
    if (param_1 != 0) {
      uVar2 = 2;
      goto LAB_00275988;
    }
  }
  nv_unregister_phys_pages(uVar19);
LAB_002755f3:
  memdescDestroy(puVar22);
  portMemFree(lVar7);
  return uVar2;
}


// ===== 00275ad0 rm_nvlink_ops_get_cci_link_mode =====

undefined8 rm_nvlink_ops_get_cci_link_mode(void)

{
  return 0;
}


// ===== 00275ae0 rm_nvlink_ops_ali_training =====

undefined4 rm_nvlink_ops_ali_training(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [19];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreAliTrainingCallback(param_1);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00275b80 rm_nvlink_get_uphy_load =====

void rm_nvlink_get_uphy_load(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_a8 [18];
  ulong uVar3;
  
  uVar2 = 0;
  do {
    uVar1 = (int)uVar2 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar2) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 0x18) = 0;
    uVar2 = uVar3;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar3) = 0;
  *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
  threadStateInit(local_a8,0);
  knvlinkCoreGetUphyLoadCallback(param_1,param_2);
  threadStateFree(local_a8,0);
  return;
}


// ===== 00275c30 rm_nvlink_ops_training_complete =====

void rm_nvlink_ops_training_complete(undefined8 param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_a8 [19];
  ulong uVar3;
  
  uVar2 = 0;
  do {
    uVar1 = (int)uVar2 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar2) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 0x18) = 0;
    uVar2 = uVar3;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar3) = 0;
  *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
  threadStateInit(local_a8,0);
  knvlinkCoreTrainingCompleteCallback(param_1);
  threadStateFree(local_a8,0);
  return;
}


// ===== 00275cd0 rm_nvlink_ops_read_link_discovery_token =====

undefined4 rm_nvlink_ops_read_link_discovery_token(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreReadDiscoveryTokenCallback(param_1,param_2);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00275d80 rm_nvlink_ops_write_link_discovery_token =====

undefined4 rm_nvlink_ops_write_link_discovery_token(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreWriteDiscoveryTokenCallback(param_1,param_2);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00275e30 rm_nvlink_ops_get_link_rx_detect =====

undefined4 rm_nvlink_ops_get_link_rx_detect(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [19];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreGetRxSublinkDetectCallback(param_1);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00275ed0 rm_nvlink_ops_set_link_rx_detect =====

undefined4 rm_nvlink_ops_set_link_rx_detect(undefined8 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreSetRxSublinkDetectCallback(param_1,param_2);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00275f80 rm_nvlink_ops_get_link_rx_mode =====

undefined4 rm_nvlink_ops_get_link_rx_mode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreGetRxSublinkModeCallback(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276040 rm_nvlink_ops_set_link_rx_mode =====

undefined4 rm_nvlink_ops_set_link_rx_mode(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreSetRxSublinkModeCallback(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276100 rm_nvlink_ops_get_link_tx_mode =====

undefined4 rm_nvlink_ops_get_link_tx_mode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreGetTxSublinkModeCallback(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 002761c0 rm_nvlink_ops_set_link_tx_mode =====

undefined4 rm_nvlink_ops_set_link_tx_mode(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreSetTxSublinkModeCallback(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276280 rm_nvlink_ops_get_tl_link_mode =====

undefined4 rm_nvlink_ops_get_tl_link_mode(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreGetTlLinkModeCallback(param_1,param_2);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276330 rm_nvlink_ops_set_tl_link_mode =====

undefined4 rm_nvlink_ops_set_tl_link_mode(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreSetTlLinkModeCallback(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 002763f0 rm_nvlink_ops_get_dl_link_mode =====

undefined4 rm_nvlink_ops_get_dl_link_mode(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreGetDlLinkModeCallback(param_1,param_2);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 002764a0 rm_nvlink_ops_set_dl_link_mode =====

undefined4 rm_nvlink_ops_set_dl_link_mode(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [18];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreSetDlLinkModeCallback(param_1,param_2,param_3);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276560 rm_nvlink_ops_queue_link_change =====

undefined4 rm_nvlink_ops_queue_link_change(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [19];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreQueueLinkChangeCallback(param_1);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276600 rm_nvlink_ops_unlock_link =====

void rm_nvlink_ops_unlock_link(undefined8 param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_a8 [19];
  ulong uVar3;
  
  uVar2 = 0;
  do {
    uVar1 = (int)uVar2 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar2) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar2 + 0x18) = 0;
    uVar2 = uVar3;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar3) = 0;
  *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
  threadStateInit(local_a8,0);
  knvlinkCoreUnlockLinkCallback(param_1);
  threadStateFree(local_a8,0);
  return;
}


// ===== 002766a0 rm_nvlink_ops_lock_link =====

undefined4 rm_nvlink_ops_lock_link(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_a8 [19];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a8 + uVar4) = 0;
  *(undefined8 *)((long)local_a8 + uVar4 + 8) = 0;
  threadStateInit(local_a8,0);
  uVar2 = knvlinkCoreLockLinkCallback(param_1);
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00276740 rm_nvlink_ops_remove_link =====

void rm_nvlink_ops_remove_link(void)

{
  knvlinkCoreRemoveLinkCallback();
  return;
}


// ===== 00276750 rm_nvlink_ops_add_link =====

void rm_nvlink_ops_add_link(void)

{
  knvlinkCoreAddLinkCallback();
  return;
}


// ===== 00276760 osGetNvlinkLinkCallbacks =====

undefined1 * osGetNvlinkLinkCallbacks(void)

{
  return rm_nvlink_link_ops_1;
}


// ===== 00276770 osGetForcedNVLinkConnection =====

ulong osGetForcedNVLinkConnection(long param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  undefined1 local_78 [72];
  
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("(pLinkConnection != NULL)","arch/nvalloc/unix/src/osnvlink.c",0x2e2);
    return 0x3d;
  }
  if (param_2 != 0) {
    iVar4 = 0;
    if (param_1 == 0) {
      uVar5 = 0x1f;
      nvAssertFailedNoLog("(pGpu != NULL)","arch/nvalloc/unix/src/osnvlink.c",0x2e4);
    }
    else {
      do {
        iVar2 = os_snprintf(local_78,0x40,"CPU_MODEL|CM_ATS_ADDRESS|NVLink%u",iVar4);
        if (0x3d < iVar2 - 1U) {
          nvAssertFailedNoLog("(ret > 0) && (ret < (sizeof(path) - 1))",
                              "arch/nvalloc/unix/src/osnvlink.c",0x2e9);
        }
        uVar3 = gpuSimEscapeRead(param_1,local_78,0,4,param_3);
        uVar5 = uVar3 & 0xffffffff;
        if ((int)uVar3 != 0) {
          nvDbg_Printf("arch/nvalloc/unix/src/osnvlink.c",0x2f3,"osGetForcedNVLinkConnection",1,
                       "NVRM: %s: gpuSimEscapeRead for \'%s\' failed (%u)\n",
                       "osGetForcedNVLinkConnection",local_78,uVar3);
          return 0x56;
        }
        uVar1 = *param_3;
        iVar4 = iVar4 + 1;
        param_3 = param_3 + 1;
        nvDbg_Printf("arch/nvalloc/unix/src/osnvlink.c",0x2ee,"osGetForcedNVLinkConnection",1,
                     "NVRM: %s: %s=0x%X\n","osGetForcedNVLinkConnection",local_78,uVar1);
      } while (param_2 != iVar4);
    }
    return uVar5;
  }
  nvAssertFailedNoLog("(maxLinks > 0)","arch/nvalloc/unix/src/osnvlink.c",0x2e3);
  return 0x56;
}


// ===== 00276960 osGetPlatformNvlinkLinerate =====

undefined8 osGetPlatformNvlinkLinerate(void)

{
  return 0x56;
}


// ===== 00276970 osInitObjOS =====

void osInitObjOS(long param_1)

{
  *(undefined1 *)(g_pSys + 0x8a) = 1;
  *(undefined2 *)(param_1 + 0x4a) = 0x101;
  return;
}


// ===== 00276990 RmPowerManagementTegra =====

undefined8 RmPowerManagementTegra(long param_1,int param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar2 = 0;
  if (*(long **)(param_1 + 0x4e0) != (long *)0x0) {
    lVar2 = **(long **)(param_1 + 0x4e0);
  }
  if (param_2 == 1) {
    *(undefined1 *)(lVar2 + 0x1e0) = 0;
    *(undefined1 *)(param_1 + 0x443) = 1;
    uVar1 = gpuStateUnload_IMPL(param_1,0xd);
    *(undefined1 *)(param_1 + 0x441) = 1;
    *(undefined1 *)(param_1 + 0x490d) = 1;
    return uVar1;
  }
  if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0x444) = 1;
    if (*(char *)(lVar2 + 0x1e0) == '\0') {
      uVar1 = gpuStateLoad_IMPL(param_1,0xd);
      *(undefined1 *)(param_1 + 0x441) = 0;
      *(undefined1 *)(param_1 + 0x490d) = 0;
    }
    else {
      uVar1 = gpuStateLoad_IMPL(param_1,0x15);
      *(undefined1 *)(param_1 + 0x442) = 0;
    }
    *(undefined2 *)(param_1 + 0x443) = 0;
    return uVar1;
  }
  if (param_2 != 0) {
    return 0x1f;
  }
  *(undefined1 *)(lVar2 + 0x1e0) = 1;
  *(undefined1 *)(param_1 + 0x443) = 1;
  uVar1 = gpuStateUnload_IMPL(param_1,0x15);
  *(undefined1 *)(param_1 + 0x442) = 1;
  return uVar1;
}


// ===== 00276aa0 regCreateNewRegistryKey =====

long * regCreateNewRegistryKey(long *param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = 0;
  if (param_1 != (long *)0x0) {
    lVar7 = *param_1;
  }
  if (param_2 == 0) {
    return (long *)0x0;
  }
  plVar3 = (long *)portMemAllocNonPaged(0x28);
  if (plVar3 == (long *)0x0) {
    nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x4d,"regCreateNewRegistryKey",4,
                 "NVRM: failed to grow registry\n");
  }
  else {
    portMemSet(plVar3,0,0x28);
    iVar2 = portStringLength(param_2);
    uVar6 = iVar2 + 1;
    lVar4 = portMemAllocNonPaged();
    if (lVar4 == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x59,"regCreateNewRegistryKey",4,
                   "NVRM: failed to allocate registry param string\n");
    }
    else {
      if (0x100 < uVar6) {
        nvAssertFailedNoLog("parm_size <= NVOS38_MAX_REGISTRY_STRING_LENGTH",
                            "arch/nvalloc/unix/src/registry.c",0x5e);
      }
      lVar5 = portMemCopy(lVar4,uVar6,param_2,uVar6);
      if (lVar5 != 0) {
        *plVar3 = lVar4;
        *(undefined4 *)(plVar3 + 1) = 0;
        if (lVar7 != 0) {
          plVar3[4] = *(long *)(lVar7 + 0x1e8);
          *(long **)(lVar7 + 0x1e8) = plVar3;
          return plVar3;
        }
        plVar1 = plVar3;
        plVar3[4] = (long)the_registry;
        the_registry = plVar1;
        return plVar3;
      }
      nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x62,"regCreateNewRegistryKey",4,
                   "NVRM: failed to copy registry param string\n");
      portMemFree(lVar4);
    }
    portMemFree(plVar3);
  }
  return (long *)0x0;
}


// ===== 00276c70 regCopyEntriesToPackedBuffer =====

undefined8 regCopyEntriesToPackedBuffer(uint *param_1,long *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  
  uVar2 = 0;
  uVar4 = *param_3;
  uVar6 = *param_4;
  uVar7 = (ulong)uVar6;
  if (param_2 != (long *)0x0) {
    do {
      while( true ) {
        uVar6 = (uint)uVar7;
        if (*param_2 == 0) goto LAB_00276df0;
        iVar1 = portStringLength();
        uVar3 = uVar6 + 1 + iVar1;
        if ((*param_1 < (int)param_2[3] + uVar3) || (param_1[1] <= uVar4)) {
          nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x23d,"regCopyEntriesToPackedBuffer",4,
                       "NVRM: Registry entry record is full\n");
          uVar2 = 0x40;
          goto LAB_00276dfe;
        }
        param_1[(ulong)uVar4 * 4 + 2] = uVar6;
        portMemCopy(uVar7 + (long)param_1,iVar1 + 1,*param_2,iVar1 + 1);
        if ((int)param_2[1] != 1) break;
        *(undefined1 *)(param_1 + (ulong)uVar4 * 4 + 3) = 1;
        param_1[(ulong)uVar4 * 4 + 5] = 4;
        param_1[(ulong)uVar4 * 4 + 4] = *(uint *)((long)param_2 + 0xc);
LAB_00276d08:
        param_2 = (long *)param_2[4];
        uVar7 = (ulong)uVar3;
        uVar4 = uVar4 + 1;
        uVar6 = uVar3;
        if (param_2 == (long *)0x0) goto LAB_00276df0;
      }
      if (1 < (int)param_2[1] - 2U) {
        *(undefined1 *)(param_1 + (ulong)uVar4 * 4 + 3) = 0;
        (param_1 + (ulong)uVar4 * 4 + 4)[0] = 0;
        (param_1 + (ulong)uVar4 * 4 + 4)[1] = 0;
        goto LAB_00276d08;
      }
      *(undefined1 *)(param_1 + (ulong)uVar4 * 4 + 3) = 3;
      *(char *)(param_1 + (ulong)uVar4 * 4 + 3) = ((int)param_2[1] != 2) + '\x02';
      uVar6 = *(uint *)(param_2 + 3);
      if (uVar6 == 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/registry.c",599,"regCopyEntriesToPackedBuffer",3,
                     "NVRM: Registry Key not sent to GSP-RM because it has 0 DataLength\n");
        goto LAB_00276d08;
      }
      param_1[(ulong)uVar4 * 4 + 5] = uVar6;
      uVar5 = uVar4 + 1;
      param_1[(ulong)uVar4 * 4 + 4] = uVar3;
      portMemCopy((ulong)uVar3 + (long)param_1,uVar6,param_2[2],(int)param_2[3]);
      uVar6 = uVar3 + (int)param_2[3];
      uVar7 = (ulong)uVar6;
      param_2 = (long *)param_2[4];
      uVar4 = uVar5;
    } while (param_2 != (long *)0x0);
LAB_00276df0:
    uVar2 = 0;
  }
LAB_00276dfe:
  *param_3 = uVar4;
  *param_4 = uVar6;
  return uVar2;
}


// ===== 00276e60 regFindRegistryEntry =====

long * regFindRegistryEntry(long *param_1,long param_2,int param_3,undefined1 *param_4)

{
  char cVar1;
  long *plVar2;
  long *plVar3;
  char cVar4;
  long lVar5;
  char cVar6;
  
  plVar3 = the_registry;
  if ((param_1 != (long *)0x0) && (*param_1 != 0)) {
    for (plVar2 = *(long **)(*param_1 + 0x1e8); (plVar2 != (long *)0x0 && (*plVar2 != 0));
        plVar2 = (long *)plVar2[4]) {
      lVar5 = 0;
      do {
        cVar1 = *(char *)(*plVar2 + lVar5);
        cVar4 = *(char *)(param_2 + lVar5);
        cVar6 = cVar1;
        if ((byte)(cVar1 + 0xbfU) < 0x1a) {
          cVar6 = cVar1 + ' ';
        }
        if ((byte)(cVar4 + 0xbfU) < 0x1a) {
          cVar4 = cVar4 + ' ';
        }
        lVar5 = lVar5 + 1;
        if (cVar6 != cVar4) goto LAB_00276eee;
      } while ((byte)(cVar1 + 0xbfU) < 0x1a || cVar1 != '\0');
      if ((cVar6 == cVar4) && ((int)plVar2[1] == param_3)) {
        if (param_4 == (undefined1 *)0x0) {
          return plVar2;
        }
        *param_4 = 0;
        return plVar2;
      }
LAB_00276eee:
    }
  }
  do {
    if (plVar3 == (long *)0x0) {
      return (long *)0x0;
    }
    if (*plVar3 == 0) {
      return (long *)0x0;
    }
    lVar5 = 0;
    do {
      cVar1 = *(char *)(*plVar3 + lVar5);
      cVar4 = *(char *)(param_2 + lVar5);
      cVar6 = cVar1;
      if ((byte)(cVar1 + 0xbfU) < 0x1a) {
        cVar6 = cVar1 + ' ';
      }
      if ((byte)(cVar4 + 0xbfU) < 0x1a) {
        cVar4 = cVar4 + ' ';
      }
      lVar5 = lVar5 + 1;
      if (cVar6 != cVar4) goto LAB_00276f6a;
    } while ((byte)(cVar1 + 0xbfU) < 0x1a || cVar1 != '\0');
    if ((cVar6 == cVar4) && ((int)plVar3[1] == param_3)) {
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = 1;
      }
      return plVar3;
    }
LAB_00276f6a:
    plVar3 = (long *)plVar3[4];
  } while( true );
}


// ===== 00276fa0 RmWriteRegistryDword =====

undefined8 RmWriteRegistryDword(long param_1,long param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  long lVar4;
  char cVar5;
  char local_29;
  
  if (param_2 == 0) {
    return 0x1f;
  }
  lVar4 = regFindRegistryEntry(param_1,param_2,1);
  if (lVar4 == 0) {
LAB_00276fe1:
    lVar4 = regCreateNewRegistryKey(param_1,param_2);
    if (lVar4 == 0) {
      return 0xffff;
    }
    *(ulong *)(lVar4 + 8) = (ulong)param_3 << 0x20 | 1;
  }
  else {
    if (param_1 == 0) {
      if (local_29 == '\0') goto LAB_00276fe1;
    }
    else if (local_29 != '\0') goto LAB_00276fe1;
    *(uint *)(lVar4 + 0xc) = param_3;
    lVar4 = 0;
    do {
      cVar1 = *(char *)(param_2 + lVar4);
      cVar3 = "ResmanDebugLevel"[lVar4];
      bVar2 = (byte)(cVar1 + 0xbfU) < 0x1a;
      cVar5 = cVar1;
      if (bVar2) {
        cVar5 = cVar1 + ' ';
      }
      if ((byte)(cVar3 + 0xbfU) < 0x1a) {
        cVar3 = cVar3 + ' ';
      }
      lVar4 = lVar4 + 1;
      if (cVar5 != cVar3) {
        return 0;
      }
    } while (bVar2 || cVar1 != '\0');
    if (cVar5 == cVar3) {
      os_dbg_set_level(param_3);
    }
  }
  return 0;
}


// ===== 00277090 RmReadRegistryDword =====

undefined8 RmReadRegistryDword(undefined8 param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  
  if ((param_2 == 0) || (param_3 == (undefined4 *)0x0)) {
    return 0x1f;
  }
  lVar1 = regFindRegistryEntry(param_1,param_2,1,0);
  if (lVar1 == 0) {
    lVar1 = regFindRegistryEntry(param_1,param_2,2,0);
    if ((lVar1 == 0) || (*(uint *)(lVar1 + 0x18) < 4)) {
      return 0xffff;
    }
    *param_3 = **(undefined4 **)(lVar1 + 0x10);
  }
  else {
    *param_3 = *(undefined4 *)(lVar1 + 0xc);
  }
  return 0;
}


// ===== 00277130 RmReadRegistryBinary =====

undefined8 RmReadRegistryBinary(undefined8 param_1,long param_2,long param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  
  if ((param_3 != 0 && param_4 != (uint *)0x0) && (param_2 != 0)) {
    lVar2 = regFindRegistryEntry(param_1,param_2,2,0);
    if (lVar2 != 0) {
      uVar1 = *param_4;
      if (*(uint *)(lVar2 + 0x18) <= uVar1) {
        portMemCopy(param_3,uVar1,*(undefined8 *)(lVar2 + 0x10));
        *param_4 = *(uint *)(lVar2 + 0x18);
        return 0;
      }
      nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x13b,"RmReadRegistryBinary",4,
                   "NVRM: buffer (length: %u) is too small (data length: %u)\n",uVar1,
                   *(uint *)(lVar2 + 0x18));
    }
    return 0xffff;
  }
  return 0x1f;
}


// ===== 002771f0 RmWriteRegistryBinary =====

undefined8 RmWriteRegistryBinary(long param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  long lVar2;
  char local_29 [9];
  
  if ((param_2 == 0) || (param_3 == 0)) {
    return 0x1f;
  }
  lVar1 = regFindRegistryEntry(param_1,param_2,2,local_29);
  if (lVar1 == 0) {
LAB_0027724c:
    lVar1 = regCreateNewRegistryKey();
    if (lVar1 == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x16b,"RmWriteRegistryBinary",4,
                   "NVRM: failed to create binary registry entry\n");
      return 0xffff;
    }
  }
  else {
    if (param_1 == 0) {
      if (local_29[0] == '\0') goto LAB_0027724c;
    }
    else if (local_29[0] != '\0') goto LAB_0027724c;
    if (*(long *)(lVar1 + 0x10) != 0) {
      portMemFree(*(long *)(lVar1 + 0x10),param_2);
      *(undefined8 *)(lVar1 + 0x10) = 0;
      *(undefined4 *)(lVar1 + 0x18) = 0;
    }
  }
  lVar2 = portMemAllocNonPaged(param_4);
  *(long *)(lVar1 + 0x10) = lVar2;
  if (lVar2 == 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x173,"RmWriteRegistryBinary",4,
                 "NVRM: failed to write binary registry entry\n");
    return 0xffff;
  }
  *(undefined4 *)(lVar1 + 8) = 2;
  *(undefined4 *)(lVar1 + 0x18) = param_4;
  portMemCopy(lVar2,param_4,param_3,param_4);
  return 0;
}


// ===== 00277330 RmWriteRegistryString =====

undefined8 RmWriteRegistryString(long param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  char local_29 [9];
  
  if ((param_2 == 0) || (param_3 == 0)) {
    return 0x1f;
  }
  lVar1 = regFindRegistryEntry(param_1,param_2,3,local_29);
  if (lVar1 == 0) {
LAB_0027738c:
    lVar1 = regCreateNewRegistryKey();
    if (lVar1 == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x1a5,"RmWriteRegistryString",4,
                   "NVRM: failed to allocate a string registry entry!\n");
      return 0x1a;
    }
  }
  else {
    if (param_1 == 0) {
      if (local_29[0] == '\0') goto LAB_0027738c;
    }
    else if (local_29[0] != '\0') goto LAB_0027738c;
    if (*(long *)(lVar1 + 0x10) != 0) {
      portMemFree(*(long *)(lVar1 + 0x10),param_2);
      *(undefined4 *)(lVar1 + 0x18) = 0;
      *(undefined8 *)(lVar1 + 0x10) = 0;
    }
  }
  lVar2 = portMemAllocNonPaged(param_4);
  *(long *)(lVar1 + 0x10) = lVar2;
  if (lVar2 == 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x1ae,"RmWriteRegistryString",4,
                 "NVRM: failed to write a string registry entry!\n");
    uVar3 = 0x51;
  }
  else {
    *(int *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 8) = 3;
    portMemCopy(lVar2,param_4,param_3,(ulong)(param_4 - 1));
    *(undefined1 *)(*(long *)(lVar1 + 0x10) + (ulong)(param_4 - 1)) = 0;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00277480 RmReadRegistryString =====

undefined8 RmReadRegistryString(undefined8 param_1,long param_2,undefined1 *param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((param_3 != (undefined1 *)0x0 && param_4 != (uint *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    *param_4 = 0;
    *param_3 = 0;
    lVar2 = regFindRegistryEntry(param_1,param_2,3,0);
    if (lVar2 == 0) {
      uVar3 = 0xffff;
    }
    else {
      if (uVar1 < *(uint *)(lVar2 + 0x18)) {
        nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x1dd,"RmReadRegistryString",4,
                     "NVRM: buffer (length: %u) is too small (data length: %u)\n",uVar1,
                     *(uint *)(lVar2 + 0x18));
        return 2;
      }
      portMemCopy(param_3,uVar1,*(undefined8 *)(lVar2 + 0x10));
      *param_4 = *(uint *)(lVar2 + 0x18);
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x1f;
}


// ===== 00277560 RmInitRegistry =====

int RmInitRegistry(void)

{
  int iVar1;
  
  iVar1 = os_registry_init();
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x1ee,"RmInitRegistry",4,
               "NVRM: failed to initialize the OS registry!\n");
  return iVar1;
}


// ===== 002775c0 RmDestroyRegistry =====

undefined8 RmDestroyRegistry(long *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = the_registry;
  if ((param_1 == (long *)0x0) || (lVar1 = *param_1, lVar1 == 0)) {
    the_registry = (undefined8 *)0x0;
  }
  else {
    puVar2 = *(undefined8 **)(lVar1 + 0x1e8);
    *(undefined8 *)(lVar1 + 0x1e8) = 0;
  }
  while (puVar2 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)puVar2[4];
    portMemFree(*puVar2);
    *puVar2 = 0;
    portMemFree(puVar2[2]);
    puVar2[2] = 0;
    *(undefined4 *)(puVar2 + 3) = 0;
    portMemFree(puVar2);
    puVar2 = puVar3;
  }
  return 0;
}


// ===== 00277670 RmPackageRegistry =====

undefined8 RmPackageRegistry(long *param_1,uint *param_2,uint *param_3)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  uint local_40;
  uint local_3c [3];
  
  if (param_1 == (long *)0x0) {
    if (param_3 == (uint *)0x0) {
      return 0x1f;
    }
LAB_002777e8:
    plVar7 = (long *)0x0;
    if (the_registry != (long *)0x0) {
LAB_002776c6:
      uVar6 = 0;
      iVar3 = 8;
      plVar9 = the_registry;
      do {
        plVar8 = plVar7;
        if (*plVar9 == 0) goto joined_r0x002776f5;
        iVar2 = portStringLength();
        plVar1 = plVar9 + 3;
        plVar9 = (long *)plVar9[4];
        uVar6 = uVar6 + 1;
        iVar3 = iVar3 + (int)*plVar1 + 1 + iVar2;
        if (plVar9 == (long *)0x0) goto joined_r0x002776f5;
      } while( true );
    }
  }
  else {
    if (param_3 == (uint *)0x0) {
      return 0x1f;
    }
    if (*param_1 == 0) goto LAB_002777e8;
    plVar7 = *(long **)(*param_1 + 0x1e8);
    if (the_registry != (long *)0x0) goto LAB_002776c6;
    if (plVar7 != (long *)0x0) {
      uVar6 = 0;
      iVar3 = 8;
      plVar8 = plVar7;
      do {
        if (*plVar7 == 0) break;
        iVar2 = portStringLength();
        plVar9 = plVar7 + 3;
        plVar7 = (long *)plVar7[4];
        uVar6 = uVar6 + 1;
        iVar3 = iVar3 + (int)*plVar9 + 1 + iVar2;
joined_r0x002776f5:
      } while (plVar7 != (long *)0x0);
      uVar5 = iVar3 + uVar6 * 0x10;
      if (param_2 != (uint *)0x0) {
        if (uVar6 == 0) {
          return 0x10006;
        }
        if (uVar5 <= *param_3) {
          *param_2 = uVar5;
          local_40 = uVar6 * 0x10 + 8;
          *param_3 = uVar5;
          plVar7 = the_registry;
          param_2[1] = uVar6;
          local_3c[0] = 0;
          iVar3 = regCopyEntriesToPackedBuffer(param_2,plVar7,local_3c,&local_40);
          uVar4 = 0x40;
          if (iVar3 == 0) {
            uVar4 = regCopyEntriesToPackedBuffer(param_2,plVar8,local_3c,&local_40);
          }
          if ((param_2[1] != local_3c[0]) || (*param_2 != local_40)) {
            nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x2c2,"RmPackageRegistry",4,
                         "NVRM: First/second pass mismatch\n");
            uVar4 = 0x40;
          }
          return uVar4;
        }
        nvDbg_Printf("arch/nvalloc/unix/src/registry.c",0x2a4,"RmPackageRegistry",4,
                     "NVRM: Registry entries overflow RPC record\n");
        return 2;
      }
      goto LAB_00277850;
    }
  }
  uVar5 = 8;
  if (param_2 != (uint *)0x0) {
    return 0x10006;
  }
LAB_00277850:
  *param_3 = uVar5;
  return 0;
}


// ===== 002778c0 rm_gpu_ops_create_session =====

void rm_gpu_ops_create_session(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsCreateSession(param_2);
  return;
}


// ===== 002778d0 rm_gpu_ops_destroy_session =====

void rm_gpu_ops_destroy_session(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsDestroySession(param_2);
  return;
}


// ===== 002778e0 rm_gpu_ops_device_create =====

void rm_gpu_ops_device_create
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6)

{
  nvGpuOpsDeviceCreate(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277900 rm_gpu_ops_device_destroy =====

void rm_gpu_ops_device_destroy(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsDeviceDestroy(param_2);
  return;
}


// ===== 00277910 rm_gpu_ops_address_space_create =====

void rm_gpu_ops_address_space_create
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  nvGpuOpsAddressSpaceCreate(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 00277940 rm_gpu_ops_dup_address_space =====

void rm_gpu_ops_dup_address_space
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsDupAddressSpace(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277960 rm_gpu_ops_address_space_destroy =====

undefined8 rm_gpu_ops_address_space_destroy(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsAddressSpaceDestroy(param_2);
  return 0;
}


// ===== 00277980 rm_gpu_ops_memory_alloc_fb =====

void rm_gpu_ops_memory_alloc_fb
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsMemoryAllocFb(param_2,param_3,param_4,param_5);
  return;
}


// ===== 002779a0 rm_gpu_ops_get_p2p_caps =====

void rm_gpu_ops_get_p2p_caps
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsGetP2PCaps(param_2,param_3,param_4);
  return;
}


// ===== 002779c0 rm_gpu_ops_memory_alloc_sys =====

void rm_gpu_ops_memory_alloc_sys
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsMemoryAllocSys(param_2,param_3,param_4,param_5);
  return;
}


// ===== 002779e0 rm_gpu_ops_pma_register_callbacks =====

undefined4
rm_gpu_ops_pma_register_callbacks
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  undefined4 uVar1;
  undefined1 local_b8 [144];
  
  threadStateInit(local_b8,0);
  uVar1 = pmaRegisterEvictionCb(param_2,param_3,param_4,param_5);
  threadStateFree(local_b8,0);
  return uVar1;
}


// ===== 00277a50 rm_gpu_ops_pma_unregister_callbacks =====

void rm_gpu_ops_pma_unregister_callbacks(undefined8 param_1,undefined8 param_2)

{
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  pmaUnregisterEvictionCb(param_2);
  threadStateFree(local_a8,0);
  return;
}


// ===== 00277a90 rm_gpu_ops_get_pma_object =====

void rm_gpu_ops_get_pma_object
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsGetPmaObject(param_2,param_3,param_4);
  return;
}


// ===== 00277ab0 rm_gpu_ops_pma_alloc_pages =====

void rm_gpu_ops_pma_alloc_pages
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsPmaAllocPages(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277ad0 rm_gpu_ops_pma_pin_pages =====

void rm_gpu_ops_pma_pin_pages
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

{
  nvGpuOpsPmaPinPages(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277af0 rm_gpu_ops_memory_cpu_map =====

void rm_gpu_ops_memory_cpu_map
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsMemoryCpuMap(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277b10 rm_gpu_ops_memory_cpu_ummap =====

undefined8 rm_gpu_ops_memory_cpu_ummap(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsMemoryCpuUnMap(param_2,param_3);
  return 0;
}


// ===== 00277b30 rm_gpu_ops_tsg_allocate =====

void rm_gpu_ops_tsg_allocate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsTsgAllocate(param_2,param_3,param_4);
  return;
}


// ===== 00277b50 rm_gpu_ops_tsg_destroy =====

undefined8 rm_gpu_ops_tsg_destroy(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsTsgDestroy(param_2);
  return 0;
}


// ===== 00277b70 rm_gpu_ops_channel_allocate =====

void rm_gpu_ops_channel_allocate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsChannelAllocate(param_2,param_3,param_4,param_5);
  return;
}


// ===== 00277b90 rm_gpu_ops_channel_destroy =====

undefined8 rm_gpu_ops_channel_destroy(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsChannelDestroy(param_2);
  return 0;
}


// ===== 00277bb0 rm_gpu_ops_pma_free_pages =====

undefined8
rm_gpu_ops_pma_free_pages
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  nvGpuOpsPmaFreePages(param_2,param_3,param_4,param_5,param_6);
  return 0;
}


// ===== 00277bd0 rm_gpu_ops_memory_free =====

undefined8 rm_gpu_ops_memory_free(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsMemoryFree(param_2,param_3);
  return 0;
}


// ===== 00277bf0 rm_gpu_ops_query_caps =====

void rm_gpu_ops_query_caps(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsQueryCaps(param_2,param_3);
  return;
}


// ===== 00277c00 rm_gpu_ops_query_ces_caps =====

void rm_gpu_ops_query_ces_caps(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsQueryCesCaps(param_2,param_3);
  return;
}


// ===== 00277c10 rm_gpu_ops_get_gpu_info =====

void rm_gpu_ops_get_gpu_info
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsGetGpuInfo(param_2,param_3,param_4);
  return;
}


// ===== 00277c30 rm_gpu_ops_service_device_interrupts_rm =====

void rm_gpu_ops_service_device_interrupts_rm(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsServiceDeviceInterruptsRM(param_2);
  return;
}


// ===== 00277c40 rm_gpu_ops_set_page_directory =====

void rm_gpu_ops_set_page_directory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined4 param_6,undefined8 param_7)

{
  nvGpuOpsSetPageDirectory(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 00277c70 rm_gpu_ops_unset_page_directory =====

void rm_gpu_ops_unset_page_directory(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsUnsetPageDirectory(param_2);
  return;
}


// ===== 00277c80 rm_gpu_ops_dup_allocation =====

void rm_gpu_ops_dup_allocation
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsDupAllocation(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277ca0 rm_gpu_ops_dup_memory =====

void rm_gpu_ops_dup_memory
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsDupMemory(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277cc0 rm_gpu_ops_free_duped_handle =====

void rm_gpu_ops_free_duped_handle(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  nvGpuOpsFreeDupedHandle(param_2,param_3);
  return;
}


// ===== 00277cd0 rm_gpu_ops_get_fb_info =====

void rm_gpu_ops_get_fb_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsGetFbInfo(param_2,param_3);
  return;
}


// ===== 00277ce0 rm_gpu_ops_get_ecc_info =====

void rm_gpu_ops_get_ecc_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsGetEccInfo(param_2,param_3);
  return;
}


// ===== 00277cf0 rm_gpu_ops_own_page_fault_intr =====

void rm_gpu_ops_own_page_fault_intr(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  nvGpuOpsOwnPageFaultIntr(param_2,param_3);
  return;
}


// ===== 00277d00 rm_gpu_ops_init_fault_info =====

void rm_gpu_ops_init_fault_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsInitFaultInfo(param_2,param_3);
  return;
}


// ===== 00277d10 rm_gpu_ops_destroy_fault_info =====

void rm_gpu_ops_destroy_fault_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsDestroyFaultInfo(param_2,param_3);
  return;
}


// ===== 00277d20 rm_gpu_ops_has_pending_non_replayable_faults =====

void rm_gpu_ops_has_pending_non_replayable_faults
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsHasPendingNonReplayableFaults(param_2,param_3);
  return;
}


// ===== 00277d30 rm_gpu_ops_get_non_replayable_faults =====

void rm_gpu_ops_get_non_replayable_faults
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsGetNonReplayableFaults(param_2,param_3,param_4);
  return;
}


// ===== 00277d50 rm_gpu_ops_flush_replayable_fault_buffer =====

void rm_gpu_ops_flush_replayable_fault_buffer
               (undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  nvGpuOpsFlushReplayableFaultBuffer(param_2,param_3);
  return;
}


// ===== 00277d60 rm_gpu_ops_toggle_prefetch_faults =====

void rm_gpu_ops_toggle_prefetch_faults(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  nvGpuOpsTogglePrefetchFaults(param_2,param_3);
  return;
}


// ===== 00277d70 rm_gpu_ops_access_bits_buffer_alloc =====

void rm_gpu_ops_access_bits_buffer_alloc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsAccessBitsBufAlloc(param_2,param_3);
  return;
}


// ===== 00277d80 rm_gpu_ops_access_bits_buffer_free =====

void rm_gpu_ops_access_bits_buffer_free(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsAccessBitsBufFree(param_2,param_3);
  return;
}


// ===== 00277d90 rm_gpu_ops_access_bits_dump =====

void rm_gpu_ops_access_bits_dump
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  nvGpuOpsAccessBitsDump(param_2,param_3,param_4);
  return;
}


// ===== 00277db0 rm_gpu_ops_init_access_cntr_info =====

void rm_gpu_ops_init_access_cntr_info
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  nvGpuOpsInitAccessCntrInfo(param_2,param_3,param_4);
  return;
}


// ===== 00277dd0 rm_gpu_ops_destroy_access_cntr_info =====

void rm_gpu_ops_destroy_access_cntr_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsDestroyAccessCntrInfo(param_2,param_3);
  return;
}


// ===== 00277de0 rm_gpu_ops_enable_access_cntr =====

void rm_gpu_ops_enable_access_cntr
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsEnableAccessCntr(param_2,param_3,param_4);
  return;
}


// ===== 00277e00 rm_gpu_ops_disable_access_cntr =====

void rm_gpu_ops_disable_access_cntr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsDisableAccessCntr(param_2,param_3);
  return;
}


// ===== 00277e10 rm_gpu_ops_get_nvlink_info =====

void rm_gpu_ops_get_nvlink_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsGetNvlinkInfo(param_2,param_3);
  return;
}


// ===== 00277e20 rm_gpu_ops_p2p_object_create =====

void rm_gpu_ops_p2p_object_create
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsP2pObjectCreate(param_2,param_3,param_4);
  return;
}


// ===== 00277e40 rm_gpu_ops_p2p_object_destroy =====

void rm_gpu_ops_p2p_object_destroy(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  nvGpuOpsP2pObjectDestroy(param_2,param_3);
  return;
}


// ===== 00277e50 rm_gpu_ops_get_external_alloc_ptes =====

void rm_gpu_ops_get_external_alloc_ptes
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsGetExternalAllocPtes(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277e70 rm_gpu_ops_get_external_alloc_phys_addrs =====

void rm_gpu_ops_get_external_alloc_phys_addrs
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsGetExternalAllocPhysAddrs(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277e90 rm_gpu_ops_retain_channel =====

void rm_gpu_ops_retain_channel
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsRetainChannel(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277eb0 rm_gpu_ops_bind_channel_resources =====

void rm_gpu_ops_bind_channel_resources(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsBindChannelResources(param_2,param_3);
  return;
}


// ===== 00277ec0 rm_gpu_ops_release_channel =====

void rm_gpu_ops_release_channel(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsReleaseChannel(param_2);
  return;
}


// ===== 00277ed0 rm_gpu_ops_stop_channel =====

void rm_gpu_ops_stop_channel(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  nvGpuOpsStopChannel(param_2,param_3);
  return;
}


// ===== 00277ee0 rm_gpu_ops_get_channel_resource_ptes =====

void rm_gpu_ops_get_channel_resource_ptes
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsGetChannelResourcePtes(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00277f00 rm_gpu_ops_report_non_replayable_fault =====

void rm_gpu_ops_report_non_replayable_fault
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsReportNonReplayableFault(param_2,param_3);
  return;
}


// ===== 00277f10 rm_gpu_ops_paging_channel_allocate =====

void rm_gpu_ops_paging_channel_allocate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsPagingChannelAllocate(param_2,param_3,param_4,param_5);
  return;
}


// ===== 00277f30 rm_gpu_ops_paging_channel_destroy =====

void rm_gpu_ops_paging_channel_destroy(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsPagingChannelDestroy(param_2);
  return;
}


// ===== 00277f40 rm_gpu_ops_paging_channels_map =====

void rm_gpu_ops_paging_channels_map
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsPagingChannelsMap(param_2,param_3,param_4,param_5);
  return;
}


// ===== 00277f60 rm_gpu_ops_paging_channels_unmap =====

void rm_gpu_ops_paging_channels_unmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  nvGpuOpsPagingChannelsUnmap(param_2,param_3,param_4);
  return;
}


// ===== 00277f80 rm_gpu_ops_paging_channel_push_stream =====

void rm_gpu_ops_paging_channel_push_stream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  nvGpuOpsPagingChannelPushStream(param_2,param_3,param_4);
  return;
}


// ===== 00277fa0 rm_gpu_ops_report_fatal_error =====

void rm_gpu_ops_report_fatal_error(undefined8 param_1,undefined4 param_2)

{
  nvGpuOpsReportFatalError(param_2);
  return;
}


// ===== 00277fb0 rm_gpu_ops_ccsl_context_init =====

void rm_gpu_ops_ccsl_context_init(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  nvGpuOpsCcslContextInit(param_2,param_3);
  return;
}


// ===== 00277fc0 rm_gpu_ops_ccsl_context_clear =====

void rm_gpu_ops_ccsl_context_clear(undefined8 param_1,undefined8 param_2)

{
  nvGpuOpsCcslContextClear(param_2);
  return;
}


// ===== 00277fd0 rm_gpu_ops_ccsl_rotate_key =====

void rm_gpu_ops_ccsl_rotate_key(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  nvGpuOpsCcslRotateKey(param_2,param_3);
  return;
}


// ===== 00277fe0 rm_gpu_ops_ccsl_rotate_iv =====

void rm_gpu_ops_ccsl_rotate_iv(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  nvGpuOpsCcslRotateIv(param_2,param_3);
  return;
}


// ===== 00277ff0 rm_gpu_ops_ccsl_encrypt_with_iv =====

void rm_gpu_ops_ccsl_encrypt_with_iv
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  nvGpuOpsCcslEncryptWithIv(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 00278010 rm_gpu_ops_ccsl_encrypt =====

void rm_gpu_ops_ccsl_encrypt
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  nvGpuOpsCcslEncrypt(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00278030 rm_gpu_ops_ccsl_decrypt =====

void rm_gpu_ops_ccsl_decrypt
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined8 param_7)

{
  nvGpuOpsCcslDecrypt(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 00278070 rm_gpu_ops_ccsl_sign =====

void rm_gpu_ops_ccsl_sign
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsCcslSign(param_2,param_3,param_4,param_5);
  return;
}


// ===== 00278090 rm_gpu_ops_ccsl_query_message_pool =====

void rm_gpu_ops_ccsl_query_message_pool
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4)

{
  nvGpuOpsQueryMessagePool(param_2,param_3,param_4);
  return;
}


// ===== 002780b0 rm_gpu_ops_ccsl_increment_iv =====

void rm_gpu_ops_ccsl_increment_iv
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nvGpuOpsIncrementIv(param_2,param_3,param_4,param_5);
  return;
}


// ===== 002780d0 rm_gpu_ops_ccsl_log_encryption =====

void rm_gpu_ops_ccsl_log_encryption
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined4 param_4)

{
  nvGpuOpsLogEncryption(param_2,param_3,param_4);
  return;
}


// ===== 002780f0 RmGenerateObjExportHandle =====

int RmGenerateObjExportHandle(void)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar1 = hObjExportHandleNext_3;
  iVar3 = hObjExportHandleNext_3;
  while( true ) {
    hObjExportHandleNext_3 = iVar3 + 1;
    if (iVar3 == 0x7ffff) {
      hObjExportHandleNext_3 = 1;
    }
    lVar2 = mapFind_IMPL(objExportHandleMap,iVar3);
    if ((hObjExportRmClient != iVar3) && (lVar2 == 0)) break;
    iVar3 = hObjExportHandleNext_3;
    if (hObjExportHandleNext_3 == iVar1) {
      return 0;
    }
  }
  if (iVar3 == 0) {
    return 0;
  }
  lVar2 = mapInsertNew_IMPL(objExportHandleMap,iVar3);
  if (lVar2 == 0) {
    iVar3 = 0;
  }
  return iVar3;
}


// ===== 002781a0 RmUnrefObjExportImport =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmUnrefObjExportImport(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(3);
  objExportImportRefCount = objExportImportRefCount + -1;
  if (objExportImportRefCount == 0) {
    if (pMemAllocator != 0) {
      mapDestroy_IMPL(objExportDeviceMap);
      mapDestroy_IMPL(objExportHandleMap);
      portMemAllocatorRelease(pMemAllocator);
      pMemAllocator = 0;
    }
    if (hObjExportRmClient != 0) {
      iVar1 = (**(code **)(lVar2 + 0x18))(lVar2,hObjExportRmClient,hObjExportRmClient);
      if (iVar1 != 0) {
        nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/rmobjexportimport.c",0x13f);
      }
      hObjExportRmClient = 0;
    }
  }
  return;
}


// ===== 00278250 RmValidateHandleAgainstInternalHandles.part.0 =====

undefined8 RmValidateHandleAgainstInternalHandles_part_0(int param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar2 = mapFindLEQ_IMPL(objExportDeviceMap,0xffffffffffffffff);
  uVar3 = mapFindGEQ_IMPL(objExportDeviceMap,0);
  mapIterRange_IMPL(&local_58,objExportDeviceMap,uVar3,uVar2);
  local_38 = local_58;
  local_30 = local_50;
  local_28 = local_48;
  local_20 = local_40;
  do {
    cVar1 = mapIterNext_IMPL(&local_38);
    if (cVar1 == '\0') {
      return 1;
    }
  } while ((*local_38 == 0) ||
          (((*local_38 != param_1 && (param_1 != local_38[1])) && (param_1 != local_38[2]))));
  return 0;
}


// ===== 00278300 RmUnrefObjExportHandle.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

void RmUnrefObjExportHandle_isra_0(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = rmapiGetInterface(3);
  lVar5 = mapFind_IMPL(objExportHandleMap,param_1);
  if (lVar5 != 0) {
    pcVar1 = *(code **)(lVar4 + 0x18);
    uVar2 = mapKey_IMPL(objExportHandleMap,lVar5);
    iVar3 = (*pcVar1)(lVar4,hObjExportRmClient,uVar2);
    if (iVar3 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x8a,"RmUnrefObjExportHandle",3,
                   "NVRM: Exported object trying to free was zombie in %s\n");
    }
    mapRemove_IMPL(objExportHandleMap,lVar5);
    return;
  }
  return;
}


// ===== 002783c0 RmExportObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int RmExportObject(undefined4 param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  int *piVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulong local_c8;
  uint local_bc;
  int local_ac;
  undefined4 local_a4;
  undefined8 local_a0;
  long local_98;
  undefined1 local_90 [16];
  undefined1 local_80 [8];
  undefined4 local_78;
  ulong local_70 [8];
  
  lVar5 = rmapiGetInterface(3);
  local_90 = kmigmgrMakeNoMIGReference_IMPL();
  if (param_3 == (undefined4 *)0x0) {
    return 0x1f;
  }
  iVar4 = serverutilGetResourceRef(param_1,param_2,&local_a0);
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,"serverutilGetResourceRef(hSrcClient, hSrcObject, &pSrcResourceRef)",
               "arch/nvalloc/unix/src/rmobjexportimport.c",0x15a);
    return iVar4;
  }
  iVar4 = refFindAncestorOfType(local_a0,&DAT_00e0ac20,&local_98);
  if (iVar4 == 0) {
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_98 + 8),__nvoc_class_def_Device);
    lVar1 = *(long *)(*(long *)(lVar6 + 0x128) + 0xe0);
    if ((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) {
LAB_0027866a:
      local_c8 = 0xf00000000;
    }
    else {
      cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
      if (cVar3 == '\0') goto LAB_0027866a;
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL
                        (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),lVar6,local_90);
      if (iVar4 != 0) goto LAB_0027866a;
      local_c8 = (ulong)*(uint *)(local_90._0_8_ + 0x968) << 0x20;
    }
    local_bc = *(uint *)(lVar6 + 0x180);
    bVar2 = false;
    local_c8 = local_bc | local_c8;
    piVar8 = (int *)mapFind_IMPL(objExportDeviceMap,local_c8);
  }
  else {
    local_c8 = 0;
    piVar8 = (int *)0x0;
    bVar2 = true;
    local_bc = 0x20;
  }
  lVar6 = rmapiGetInterface(3);
  lVar1 = objExportImportRefCount + 1;
  if (objExportImportRefCount == 0) {
    objExportImportRefCount = lVar1;
    iVar4 = (**(code **)(lVar6 + 8))(lVar6,0,0,0,0,&hObjExportRmClient,4);
    if (iVar4 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x10a,"RmRefObjExportImport",4,
                   "NVRM: Unable to alloc root in %s\n");
      RmUnrefObjExportImport();
      return iVar4;
    }
    pMemAllocator = portMemAllocatorCreateNonPaged();
    if (pMemAllocator == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x112,"RmRefObjExportImport",4,
                   "NVRM: Failed to alloc memory allocator in %s\n");
      RmUnrefObjExportImport();
    }
    else {
      mapInit_IMPL(objExportHandleMap,pMemAllocator,1);
      mapInit_IMPL(objExportDeviceMap,pMemAllocator,0xc);
    }
  }
  else {
    objExportImportRefCount = lVar1;
    if (hObjExportRmClient == 0) {
      nvAssertFailedNoLog("hObjExportRmClient != 0","arch/nvalloc/unix/src/rmobjexportimport.c",0xfc
                         );
    }
    if (pMemAllocator == 0) {
      nvAssertFailedNoLog("pMemAllocator != NULL","arch/nvalloc/unix/src/rmobjexportimport.c",0xfd);
    }
  }
  if (bVar2) {
    iVar4 = RmGenerateObjExportHandle();
    local_70[0] = CONCAT44(local_70[0]._4_4_,iVar4);
    if (iVar4 == 0) {
LAB_00278940:
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x1ec,"RmExportObject",4,
                   "NVRM: Failed to allocate object handle in %s\n");
      goto LAB_00278969;
    }
    local_ac = (**(code **)(lVar5 + 0x50))
                         (lVar5,hObjExportRmClient,hObjExportRmClient,local_70,param_1,param_2,0);
    if (local_ac == 0) goto LAB_002785f3;
  }
  else {
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)mapInsertNew_IMPL(objExportDeviceMap,local_c8);
      iVar4 = RmGenerateObjExportHandle();
      *piVar8 = iVar4;
      iVar4 = RmGenerateObjExportHandle();
      piVar8[2] = 0;
      piVar8[1] = iVar4;
      if ((*piVar8 != 0) && (iVar4 != 0)) goto LAB_0027874f;
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x198,"RmExportObject",4,
                   "NVRM: Failed to allocate object handles in %s\n");
      mapRemove_IMPL(objExportDeviceMap,piVar8);
LAB_00278969:
      local_ac = 0x51;
      goto LAB_0027896e;
    }
    cVar3 = serverutilValidateNewResourceHandle(hObjExportRmClient,*piVar8);
    if (cVar3 == '\0') {
      iVar4 = RmGenerateObjExportHandle();
      local_70[0] = CONCAT44(local_70[0]._4_4_,iVar4);
      if (iVar4 == 0) goto LAB_00278940;
      pcVar7 = *(code **)(lVar5 + 0x50);
    }
    else {
LAB_0027874f:
      portMemSet(local_70,0,0x38);
      local_70[0] = CONCAT44(hObjExportRmClient,local_bc);
      local_ac = (**(code **)(lVar5 + 8))
                           (lVar5,hObjExportRmClient,hObjExportRmClient,*piVar8,0x80,local_70);
      if (local_ac != 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x1b0,"RmExportObject",4,
                     "NVRM: Unable to alloc device in %s\n");
        goto LAB_0027896e;
      }
      portMemSet(&local_a4,0,4);
      local_a4 = 0;
      local_ac = (**(code **)(lVar5 + 8))
                           (lVar5,hObjExportRmClient,*piVar8,piVar8[1],0x2080,&local_a4,4);
      if (local_ac != 0) {
        uVar9 = 0x1c2;
        pcVar10 = "NVRM: Unable to alloc subdevice in %s\n";
LAB_00278af0:
        nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",uVar9,"RmExportObject",4,pcVar10);
        (**(code **)(lVar5 + 0x18))(lVar5,hObjExportRmClient,*piVar8);
        goto LAB_0027896e;
      }
      if ((local_90._0_8_ != 0) && (*(uint *)(local_90._0_8_ + 0x968) < 0xf)) {
        portMemSet(local_80,0,0x10);
        local_78 = *(undefined4 *)(local_90._0_8_ + 0x968);
        iVar4 = RmGenerateObjExportHandle();
        piVar8[2] = iVar4;
        local_ac = (**(code **)(lVar5 + 8))
                             (lVar5,hObjExportRmClient,piVar8[1],iVar4,0xc637,local_80);
        if (local_ac != 0) {
          uVar9 = 0x1de;
          pcVar10 = "NVRM: Unable to alloc gpu instance subscription in %s\n";
          goto LAB_00278af0;
        }
      }
      iVar4 = RmGenerateObjExportHandle();
      local_70[0] = CONCAT44(local_70[0]._4_4_,iVar4);
      if (iVar4 == 0) goto LAB_00278940;
      pcVar7 = *(code **)(lVar5 + 0x50);
    }
    local_ac = (*pcVar7)(lVar5,hObjExportRmClient,*piVar8,local_70,param_1,param_2,0);
    if (local_ac == 0) {
LAB_002785f3:
      if (param_4 != (uint *)0x0) {
        *param_4 = local_bc;
      }
      *param_3 = (undefined4)local_70[0];
      return 0;
    }
    if (local_ac == 0x36) {
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x1ff,"RmExportObject",1,
                   "NVRM: pRmApi->DupObject(Dev, failed due to invalid parent in %s. Now attempting DupObject with Subdev handle.\n"
                  );
      local_ac = (**(code **)(lVar5 + 0x50))
                           (lVar5,hObjExportRmClient,piVar8[1],local_70,param_1,param_2,0);
      if (local_ac == 0) goto LAB_002785f3;
      RmUnrefObjExportHandle_isra_0(local_70[0] & 0xffffffff);
      nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x20f,"RmExportObject",4,
                   "NVRM: pRmApi->DupObject(Subdev, failed with error code 0x%x in %s\n",local_ac,
                   "RmExportObject");
      goto LAB_0027896e;
    }
  }
  RmUnrefObjExportHandle_isra_0(local_70[0] & 0xffffffff);
  nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x219,"RmExportObject",4,
               "NVRM: pRmApi->DupObject(Dev, failed with error code 0x%x in %s\n",local_ac,
               "RmExportObject");
LAB_0027896e:
  RmUnrefObjExportImport();
  return local_ac;
}


// ===== 00278bb0 RmFreeObjExportHandle =====

void RmFreeObjExportHandle(int param_1)

{
  char cVar1;
  
  if (((objExportImportRefCount != 0) && (hObjExportRmClient != 0)) &&
     (param_1 != hObjExportRmClient)) {
    cVar1 = RmValidateHandleAgainstInternalHandles_part_0();
    if (cVar1 != '\0') {
      RmUnrefObjExportHandle_isra_0(param_1);
      RmUnrefObjExportImport();
      return;
    }
  }
  nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",0x234,"RmFreeObjExportHandle",4,
               "NVRM: Invalid handle to exported object in %s\n");
  return;
}


// ===== 00278c20 RmImportObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int RmImportObject(undefined4 param_1,undefined4 param_2,undefined8 param_3,uint param_4,
                  undefined1 *param_5)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong local_48;
  uint local_40;
  
  lVar3 = rmapiGetInterface(3);
  if (objExportImportRefCount == 0) {
    return 0x1f;
  }
  if (hObjExportRmClient == 0) {
    return 0x1f;
  }
  if (param_4 == hObjExportRmClient) {
    return 0x1f;
  }
  cVar1 = RmValidateHandleAgainstInternalHandles_part_0(param_4);
  if (cVar1 == '\0') {
    return 0x1f;
  }
  lVar4 = mapFind_IMPL(objExportHandleMap,(ulong)param_4);
  if (lVar4 == 0) {
    return 0x1f;
  }
  if (param_5 != (undefined1 *)0x0) {
    local_48 = (ulong)param_4 | 0x800000000000;
    local_40 = 0;
    iVar2 = (**(code **)(lVar3 + 0x38))
                      (lVar3,hObjExportRmClient,hObjExportRmClient,0xd01,&local_48,0xc);
    if (iVar2 != 0) {
      pcVar6 = "NVRM: GET_ADDR_SPACE_TYPE failed with error code 0x%x in %s\n";
      uVar5 = 0x261;
      goto LAB_00278db4;
    }
    if (local_40 == 4) {
      *param_5 = 3;
    }
    else if (local_40 < 5) {
      if (local_40 == 1) {
        *param_5 = 2;
      }
      else {
        if (local_40 != 2) goto LAB_00278e10;
        *param_5 = 1;
      }
    }
    else {
      if (local_40 != 5) {
LAB_00278e10:
        nvAssertOkFailedNoLog
                  (0x1f,"NV_ERR_INVALID_ARGUMENT","arch/nvalloc/unix/src/rmobjexportimport.c",0x279)
        ;
        return 0x1f;
      }
      *param_5 = 4;
    }
  }
  iVar2 = (**(code **)(lVar3 + 0x50))(lVar3,param_1,param_2,param_3,hObjExportRmClient,param_4,0);
  if (iVar2 == 0) {
    return 0;
  }
  pcVar6 = "NVRM: pRmApi->DupObject(pRmApi,  failed with error code 0x%x in %s\n";
  uVar5 = 0x283;
LAB_00278db4:
  nvDbg_Printf("arch/nvalloc/unix/src/rmobjexportimport.c",uVar5,"RmImportObject",4,pcVar6,iVar2,
               "RmImportObject");
  return iVar2;
}


// ===== 00278e4a subdeviceCtrlCmdOsUnixVidmemPersistenceStatus_IMPL.cold =====

void subdeviceCtrlCmdOsUnixVidmemPersistenceStatus_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00278e60 subdeviceCtrlCmdOsUnixVidmemPersistenceStatus_IMPL =====

undefined8 subdeviceCtrlCmdOsUnixVidmemPersistenceStatus_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 == 0) || (plVar2 = *(long **)(lVar1 + 0x4e0), plVar2 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  if ((*(char *)((long)plVar2 + 0x2ff) == '\0') && (*(char *)(*plVar2 + 0x241) == '\0')) {
    *param_2 = *(char *)((long)plVar2 + 0x2b1) != '\0';
    return 0;
  }
  *param_2 = 1;
  return 0;
}


// ===== 00278ec0 subdeviceCtrlCmdOsUnixUpdateTgpStatus_IMPL =====

undefined8 subdeviceCtrlCmdOsUnixUpdateTgpStatus_IMPL(long param_1,undefined1 *param_2)

{
  *(undefined1 *)(param_1 + 0x6b6) = *param_2;
  return 0;
}


// ===== 00278ed0 unixCallVideoBIOS =====

undefined8 unixCallVideoBIOS(long param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x464) != '\0') {
    return 0x56;
  }
  iVar1 = *param_2;
  uVar2 = *param_3;
  nvDbg_Printf("arch/nvalloc/unix/src/unix_console.c",0x39,"unixCallVideoBIOS",1,
               "NVRM: unixCallVideoBIOS: 0x%x 0x%x, vga_satus = %d\n",iVar1,uVar2,
               *(undefined1 *)(*(long *)(param_1 + 0x4e0) + 700));
  uVar3 = nv_vbios_call(param_1,param_2,param_3);
  if (*param_2 == 0x4f) {
    return uVar3;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/unix_console.c",0x40,"unixCallVideoBIOS",4,
               "NVRM: int10h(%04x, %04x) vesa call failed! (%04x, %04x)\n",iVar1,uVar2,*param_2,
               *param_3);
  return 0xffff;
}


// ===== 00278fb1 RmSaveDisplayState.cold =====

void RmSaveDisplayState_cold(void)

{
  code *pcVar1;
  
  rmapiGetInterface(4);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00278fd0 RmSaveDisplayState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmSaveDisplayState(long param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  bool bVar8;
  undefined2 local_36;
  char local_34;
  undefined2 local_33;
  undefined1 local_31;
  undefined4 local_30;
  uint local_2c;
  
  if ((param_1 != 0) && (plVar1 = *(long **)(param_1 + 0x4e0), plVar1 != (long *)0x0)) {
    lVar2 = *plVar1;
    lVar7 = rmapiGetInterface(4);
    lVar3 = *(long *)(param_1 + 0x1b80);
    bVar8 = false;
    if (*(char *)((long)plVar1 + 700) != '\0') {
      cVar5 = RmGpuHasIOSpaceEnabled(plVar1);
      bVar8 = cVar5 != '\0';
    }
    local_34 = '\0';
    local_36 = 0;
    local_33 = 0;
    local_31 = 0;
    if (((*(char *)(param_1 + 0x908) == '\0') && (lVar3 != 0)) && ((char)plVar1[0x69] == '\0')) {
      if (*(char *)(param_1 + 0x464) == '\0') {
        local_36 = CONCAT11(bVar8,1);
        iVar6 = (**(code **)(lVar7 + 0x38))
                          (lVar7,(int)plVar1[0x62],(int)plVar1[99],0x20800a76,&local_36,3);
        if (iVar6 == 0) {
          if (local_34 == '\0') {
            if (bVar8) {
              local_30 = 0x4f03;
              local_2c = 0;
              iVar6 = unixCallVideoBIOS(param_1,&local_30,&local_2c);
              if (iVar6 == 0) {
                *(uint *)(lVar2 + 0x40) = local_2c & 0x3fff;
              }
              else {
                *(undefined4 *)(lVar2 + 0x40) = 3;
              }
            }
            local_33 = CONCAT11(bVar8,1);
            iVar6 = (**(code **)(lVar7 + 0x38))
                              (lVar7,(int)plVar1[0x62],(int)plVar1[99],0x20800a77,&local_33,3);
            if (iVar6 != 0) {
              nvCheckOkFailedNoLog
                        (4,iVar6,
                         "pRmApi->Control(pRmApi, nv->rmapi.hClient,nv->rmapi.hSubDevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_POST_UNIX_CONSOLE, &postUnixConsoleParams, sizeof(postUnixConsoleParams))"
                         ,"arch/nvalloc/unix/src/unix_console.c",0x86);
            }
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar6,
                     "pRmApi->Control(pRmApi, nv->rmapi.hClient, nv->rmapi.hSubDevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_PRE_UNIX_CONSOLE, &preUnixConsoleParams, sizeof(preUnixConsoleParams))"
                     ,"arch/nvalloc/unix/src/unix_console.c",0x68);
        }
      }
      else {
        nvDbg_Printf("arch/nvalloc/unix/src/unix_console.c",0x61,"RmSaveDisplayState",1,
                     "NVRM: RM fallback doesn\'t support saving of efifb console\n");
      }
    }
    return;
  }
  rmapiGetInterface(4);
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 00279200 rm_save_low_res_mode =====

undefined8 rm_save_low_res_mode(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  undefined1 local_a8 [152];
  
  uVar1 = 0;
  if ((param_2 != (long *)0x0) && (uVar1 = 0, (undefined8 *)*param_2 != (undefined8 *)0x0)) {
    uVar1 = *(undefined8 *)*param_2;
  }
  threadStateInit(local_a8,0);
  RmSaveDisplayState(uVar1);
  threadStateFree(local_a8,0);
  return 0;
}


// ===== 0027924f deviceCtrlCmdOsUnixVTSwitch_IMPL.cold =====

void deviceCtrlCmdOsUnixVTSwitch_IMPL_cold(void)

{
  code *pcVar1;
  
  rmapiGetInterface(4);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00279270 deviceCtrlCmdOsUnixVTSwitch_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 deviceCtrlCmdOsUnixVTSwitch_IMPL(long param_1,int *param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  byte bVar9;
  bool bVar10;
  long *plVar11;
  long *plVar12;
  short local_36;
  char local_34;
  short local_33;
  undefined1 local_31;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar7 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar1 != 0) {
    uVar7 = *(undefined8 *)(lVar1 + 0x4e0);
  }
  iVar4 = *param_2;
  if (iVar4 != 2) {
    if (iVar4 == 3) {
      RmUpdateGc6ConsoleRefCount(uVar7,1);
      return 0;
    }
    if (iVar4 != 1) {
      return 0x1f;
    }
    RmUpdateGc6ConsoleRefCount(uVar7,0);
    iVar4 = rmGpuLocksAcquire(0,0x80002);
    if (iVar4 != 0) {
LAB_00279470:
      nvDbg_Printf("arch/nvalloc/unix/src/unix_console.c",0x13d,"deviceCtrlCmdOsUnixVTSwitch_IMPL",1
                   ,"NVRM: %s: Failed to acquire GPU lock");
      return 0;
    }
    RmSaveDisplayState(lVar1);
    goto LAB_002792d5;
  }
  RmUpdateGc6ConsoleRefCount(uVar7,1);
  iVar4 = rmGpuLocksAcquire(0,0x80002);
  if (iVar4 != 0) goto LAB_00279470;
  if ((lVar1 == 0) || (plVar8 = *(long **)(lVar1 + 0x4e0), plVar8 == (long *)0x0)) {
    rmapiGetInterface(4);
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar6 = *plVar8;
  lVar5 = rmapiGetInterface(4);
  bVar10 = false;
  if (*(char *)((long)plVar8 + 700) != '\0') {
    cVar3 = RmGpuHasIOSpaceEnabled(plVar8);
    bVar10 = cVar3 != '\0';
  }
  local_34 = '\0';
  local_36 = 0;
  cVar3 = *(char *)(lVar1 + 0x908);
  local_33 = 0;
  local_31 = 0;
  if (*(long *)(lVar1 + 0x1b80) == 0) {
LAB_00279453:
    if (cVar3 == '\0') goto LAB_002792d5;
  }
  else if (cVar3 == '\0') {
    if ((char)plVar8[0x69] != '\0') goto LAB_002792d5;
    if (*(char *)(lVar1 + 0x464) == '\0') {
      local_36 = (ushort)bVar10 << 8;
      plVar11 = (long *)(ulong)bVar10;
      iVar4 = (**(code **)(lVar5 + 0x38))
                        (lVar5,(int)plVar8[0x62],(int)plVar8[99],0x20800a76,&local_36,3,plVar11);
      bVar9 = (byte)plVar11;
      if (iVar4 == 0) {
        if (local_34 == '\0') {
          plVar12 = plVar8;
          if (bVar10) {
            local_2c = *(undefined4 *)(lVar6 + 0x40);
            plVar12 = (long *)((ulong)plVar11 & 0xff);
            local_30 = 0x4f02;
            iVar4 = unixCallVideoBIOS(lVar1,&local_30,&local_2c);
            bVar9 = (byte)plVar12;
            plVar11 = plVar8;
            if (iVar4 == 0) {
              local_31 = 1;
            }
          }
          local_33 = (ushort)bVar9 << 8;
          iVar4 = (**(code **)(lVar5 + 0x38))
                            (lVar5,(int)plVar8[0x62],(int)plVar8[99],0x20800a77,&local_33,3,plVar11,
                             plVar12);
          if (iVar4 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar4,
                       "pRmApi->Control(pRmApi, nv->rmapi.hClient, nv->rmapi.hSubDevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_POST_UNIX_CONSOLE, &postUnixConsoleParams, sizeof(postUnixConsoleParams))"
                       ,"arch/nvalloc/unix/src/unix_console.c",0xcf);
          }
        }
        cVar3 = *(char *)(lVar1 + 0x908);
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "pRmApi->Control(pRmApi, nv->rmapi.hClient, nv->rmapi.hSubDevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_PRE_UNIX_CONSOLE, &preUnixConsoleParams, sizeof(preUnixConsoleParams))"
                   ,"arch/nvalloc/unix/src/unix_console.c",0xb7);
        cVar3 = *(char *)(lVar1 + 0x908);
      }
    }
    else {
      nvDbg_Printf("arch/nvalloc/unix/src/unix_console.c",0xb0,"RmRestoreDisplayState",1,
                   "NVRM: RM fallback doesn\'t support efifb console restore\n");
      cVar3 = *(char *)(lVar1 + 0x908);
    }
    goto LAB_00279453;
  }
  lVar6 = gpuGetRpc(lVar1);
  if (lVar6 != 0) {
    (**(code **)(lVar6 + 0x298))(lVar1,lVar6,*(code **)(lVar6 + 0x298));
  }
LAB_002792d5:
  rmGpuLocksRelease(0,0);
  return 0;
}


// ===== 002795b0 deviceCtrlCmdOsUnixVTGetFBInfo_IMPL =====

undefined8 deviceCtrlCmdOsUnixVTGetFBInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  undefined2 local_48 [2];
  undefined2 local_44 [2];
  undefined2 local_40 [2];
  undefined2 local_3c [2];
  undefined8 local_38;
  undefined8 local_30 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  iVar3 = rmGpuLocksAcquire(0,0x80002);
  if (iVar3 == 0) {
    portMemSet(param_2,0,0x20);
    uVar2 = *(undefined8 *)(lVar1 + 0x4e0);
    auVar6 = memmgrGetReservedConsoleMemDesc_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1b78));
    uVar5 = auVar6._8_8_;
    if (auVar6._0_8_ != 0) {
      if (*(short *)(param_2 + 1) != 0) {
        nvAssertFailedNoLog("pParams->width == 0","arch/nvalloc/unix/src/unix_console.c",0x15b);
      }
      uVar4 = gpumgrGetSubDeviceInstanceFromGpu(lVar1);
      *param_2 = uVar4;
      nv_get_screen_info(uVar2,&local_38,local_48,local_44,local_40,local_3c,local_30);
      *(undefined8 *)(param_2 + 4) = local_38;
      *(undefined8 *)(param_2 + 6) = local_30[0];
      *(undefined2 *)(param_2 + 1) = local_48[0];
      *(undefined2 *)((long)param_2 + 6) = local_44[0];
      *(undefined2 *)(param_2 + 2) = local_40[0];
      *(undefined2 *)((long)param_2 + 10) = local_3c[0];
      uVar5 = 0x27962c;
    }
    rmGpuLocksRelease(0,0,uVar5);
    return 0;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/unix_console.c",0x176,"deviceCtrlCmdOsUnixVTGetFBInfo_IMPL",1,
               "NVRM: %s: Failed to acquire GPU lock");
  return 0;
}


// ===== 00279700 RmIsrBottomHalf =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmIsrBottomHalf(long *param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 local_24c;
  undefined8 local_248;
  undefined1 local_240 [24];
  undefined1 local_228 [512];
  
  uVar6 = 0;
  if ((param_1 != (long *)0x0) && (uVar6 = 0, (undefined8 *)*param_1 != (undefined8 *)0x0)) {
    uVar6 = *(undefined8 *)*param_1;
  }
  uVar4 = portMemAllocatorCreateOnExistingBlock(local_228,0x200);
  tlsIsrInit(uVar4);
  osGetCurrentThread(&local_248);
  rmDeviceGpuLockSetOwner(uVar6,local_248);
  uVar2 = gpumgrGetGpuMask(uVar6);
  local_24c = 0;
  while( true ) {
    lVar5 = gpumgrGetNextGpu(uVar2,&local_24c);
    if (lVar5 == 0) break;
    threadStateInitISRAndDeferredIntHandler(*(undefined8 *)(lVar5 + 0x4a10),lVar5,2);
  }
  local_24c = 0;
  while( true ) {
    lVar5 = gpumgrGetNextGpu(uVar2,&local_24c);
    if (lVar5 == 0) break;
    gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar5 + 0x7a4));
    lVar1 = *(long *)(lVar5 + 0x1c20);
    if (lVar1 != 0) {
      iVar3 = intrGetIntrEn_IMPL(lVar1);
      if (iVar3 == 1) {
        (**(code **)(lVar1 + 0x2f8))(lVar5,lVar1);
        if (*(char *)(lVar5 + 0x449) == '\0') {
          (**(code **)(lVar1 + 0x168))(lVar5,lVar1,local_240,*(undefined8 *)(lVar5 + 0x4a10));
        }
      }
    }
    gpumgrSetCurrentGpuInstance(0xffffffff);
  }
  local_24c = 0;
  uVar6 = gpumgrGetNextGpu(uVar2,&local_24c);
  rmDeviceGpuLocksReleaseAndThreadStateFreeDeferredIntHandlerOptimized(uVar6,0,0);
  tlsIsrDestroy(uVar4);
  portMemAllocatorRelease(uVar4);
  return;
}


// ===== 00279890 osInterruptPending.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte osInterruptPending_constprop_0(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  byte bVar13;
  byte bVar14;
  undefined1 *local_370;
  byte local_368;
  uint local_358;
  uint local_354;
  uint local_348;
  byte local_341;
  undefined4 local_330;
  uint local_32c;
  undefined1 local_328 [24];
  undefined1 local_310 [24];
  undefined1 local_2f8 [24];
  undefined1 local_2e0 [24];
  undefined1 local_2c8 [144];
  undefined1 local_238 [520];
  
  *param_2 = 0;
  uVar9 = portMemAllocatorCreateOnExistingBlock(local_238,0x200);
  tlsIsrInit(uVar9);
  if (*(char *)(param_1 + 0x449) == '\0') {
    local_348 = 0;
    bVar13 = 1;
    local_358 = 0;
    local_354 = 0;
    local_341 = 0;
  }
  else {
    bVar13 = 0;
    threadStateInitISRLockless(local_2c8,param_1,8);
    uVar5 = gpumgrGetGpuMask(param_1);
    local_341 = 0;
    local_330 = 0;
    local_348 = 0;
    local_358 = 0;
    local_354 = 0;
    while (lVar10 = gpumgrGetNextGpu(uVar5,&local_330), lVar10 != 0) {
      lVar1 = *(long *)(lVar10 + 0x1c20);
      if (lVar1 != 0) {
        lVar2 = *(long *)(lVar10 + 0x1b80);
        iVar6 = intrGetIntrEn_IMPL(lVar1);
        if (iVar6 == 1) {
          local_2e0[0] = 0;
          intrGetPendingNonStall_TU102(lVar10,lVar1,local_310,local_2c8);
          intrCheckFecsEventbufferPending_IMPL(lVar10,lVar1,local_310,local_2e0);
          cVar3 = bitVectorTestAllCleared_IMPL(local_310,0xb4);
          if (cVar3 == '\0') {
            (**(code **)(lVar1 + 0x168))(lVar10,lVar1,local_310,local_2c8);
            *param_2 = 1;
          }
          (**(code **)(lVar1 + 0x330))(lVar10,lVar1,local_328,local_2c8);
          cVar3 = bitVectorTestAllCleared_IMPL(local_328,0xb4);
          if (cVar3 == '\0') {
            if ((lVar2 == 0) || (*(char *)(lVar2 + 0x27a) == '\0')) {
              cVar3 = bitVectorTest_IMPL(local_328,0xb4,2);
              if (cVar3 != '\0') {
                local_354 = local_354 | 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f);
                bitVectorClr_IMPL(local_328,0xb4,2);
              }
            }
            else {
              cVar3 = bitVectorTest_IMPL(local_328,0xb4,0xb1);
              if (cVar3 != '\0') {
                local_358 = local_358 | 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f);
                bitVectorClr_IMPL(local_328,0xb4,0xb1);
              }
            }
            if (((*(char *)(lVar10 + 0x4a4e) != '\0') && (*(char *)(lVar10 + 0x908) == '\0')) &&
               (cVar3 = bitVectorTest_IMPL(local_328,0xb4,1), cVar3 != '\0')) {
              local_348 = local_348 | 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f);
              bitVectorClr_IMPL(local_328,0xb4,1);
            }
            bVar13 = 1;
            cVar3 = bitVectorTestAllCleared_IMPL(local_328,0xb4);
            local_341 = local_341 | cVar3 == '\0';
          }
        }
      }
    }
    threadStateFreeISRLockless(local_2c8,param_1,8);
  }
  threadStateInitISRLockless(local_2c8,param_1,8);
  uVar5 = gpumgrGetGpuMask(param_1);
  local_330 = 0;
  do {
    lVar10 = gpumgrGetNextGpu(uVar5,&local_330);
  } while (lVar10 != 0);
  threadStateFreeISRLockless(local_2c8,param_1,8);
  bVar14 = 0;
  if (bVar13 == 0) goto LAB_00279969;
  iVar6 = rmDeviceGpuLocksAcquire(param_1,1,0x200000);
  if (iVar6 == 0) {
    threadStateInitISRAndDeferredIntHandler(local_2c8,param_1,1);
    uVar5 = gpumgrGetGpuMask(param_1);
    local_330 = 0;
    local_368 = bVar13;
    bVar14 = 0;
    while (lVar10 = gpumgrGetNextGpu(uVar5,&local_330), lVar10 != 0) {
      lVar1 = *(long *)(lVar10 + 0x1c20);
      if (lVar1 != 0) {
        lVar2 = *(long *)(lVar10 + 0x1b80);
        iVar6 = intrGetIntrEn_IMPL(lVar1);
        if ((iVar6 == 1) &&
           (uVar7 = (**(code **)(lVar1 + 0x328))(lVar10,lVar1,local_2c8), uVar7 < 4)) {
          if (*(char *)(param_1 + 0x449) == '\0') {
            (**(code **)(lVar1 + 0x330))(lVar10,lVar1,local_328,local_2c8);
            if (lVar2 != 0) goto LAB_00279f4f;
          }
          else {
            bitVectorClrAll_IMPL(local_328,0xb4);
            uVar7 = 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f);
            if (lVar2 == 0) {
              if ((local_354 & uVar7) != 0) {
                bitVectorSet_IMPL(local_328,0xb4,2);
                uVar7 = 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f);
              }
              if ((local_348 & uVar7) != 0) {
                bitVectorSet_IMPL(local_328,0xb4,1);
              }
            }
            else {
              if (*(char *)(lVar2 + 0x27a) == '\0') {
                if ((local_354 & uVar7) != 0) {
                  bitVectorSet_IMPL(local_328,0xb4,2);
                  if ((local_348 & 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f)) == 0)
                  goto LAB_00279f4f;
LAB_0027a608:
                  bitVectorSet_IMPL(local_328,0xb4,1);
                  goto LAB_00279f4f;
                }
                if ((local_348 & uVar7) != 0) goto LAB_0027a608;
LAB_00279f63:
                local_370 = local_328;
                cVar3 = bitVectorTest_IMPL(local_370,0xb4,2);
                if (cVar3 == '\0') goto LAB_0027a128;
              }
              else {
                if ((local_358 & uVar7) == 0) {
                  if ((local_348 & uVar7) != 0) goto LAB_0027a608;
                }
                else {
                  bitVectorSet_IMPL(local_328,0xb4,0xb1);
                  if ((local_348 & 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f)) != 0)
                  goto LAB_0027a608;
LAB_00279f4f:
                  if (*(char *)(lVar2 + 0x27a) == '\0') goto LAB_00279f63;
                }
                local_370 = local_328;
                cVar3 = bitVectorTest_IMPL(local_370,0xb4,0xb1);
                if (cVar3 == '\0') {
                  if (*(char *)(lVar2 + 0x27a) != '\0') goto LAB_0027a128;
                  goto LAB_00279f63;
                }
              }
              local_370 = local_328;
              cVar3 = *(char *)(lVar2 + 0x27a);
              cVar4 = kdispAcquireLowLatencyLockConditional(lVar2 + 0x38c);
              if (cVar4 != '\0') {
                if (*(char *)(lVar2 + 0x27d) == '\0') {
                  kdispServiceLowLatencyIntrs_KERNEL(lVar10,lVar2,0,0x12,local_2c8,0,local_370);
                }
                else {
                  kdispHandleAggressiveVblank_IMPL(lVar10,lVar2,0,local_370);
                }
                *param_2 = 1;
                kdispReleaseLowLatencyLock(lVar2 + 0x38c);
              }
              if (cVar3 == '\0') {
                bitVectorClr_IMPL(local_370,0xb4,2);
              }
              else {
                bitVectorClr_IMPL(local_370,0xb4,0xb1);
              }
              (**(code **)(lVar1 + 0x228))(lVar10,lVar1,local_2e0,local_2c8);
              if (*(int *)(lVar2 + 0x364) != 0) {
                bitVectorSet_IMPL(local_2e0,0xb4,2);
              }
              bitVectorOr_IMPL(local_370,0xb4,local_370,0xb4,local_2e0);
            }
          }
LAB_0027a128:
          local_370 = local_328;
          if (((*(char *)(lVar10 + 0x4a4e) != '\0') && (*(char *)(lVar10 + 0x908) == '\0')) &&
             (cVar3 = bitVectorTest_IMPL(local_370,0xb4,1), cVar3 != '\0')) {
            uVar8 = intrGetVectorFromEngineId_IMPL(lVar10,lVar1,1,0);
            (**(code **)(lVar1 + 0x1d0))(lVar10,lVar1,uVar8,local_2c8);
            bitVectorClr_IMPL(local_370,0xb4,1);
            iVar6 = (**(code **)(lVar1 + 0x208))(lVar10,lVar1,3);
            if (iVar6 != 0) {
              nvAssertOkFailedNoLog
                        (iVar6,
                         "intrTriggerPrivDoorbell_HAL(pGpu, pIntr, NV_DOORBELL_NOTIFY_LEAF_SERVICE_TMR_HANDLE)"
                         ,"arch/nvalloc/unix/src/unix_intr.c",0x1f0);
            }
          }
          if (*(char *)(lVar10 + 0x449) == '\0') {
            lVar1 = *(long *)(lVar10 + 0x1c20);
            if (lVar1 != 0) {
              local_2e0[0] = 0;
              intrGetPendingNonStall_TU102(lVar10,lVar1,local_310,local_2c8);
              intrCheckFecsEventbufferPending_IMPL(lVar10,lVar1,local_310,local_2e0);
            }
          }
          else {
            bitVectorClrAll_IMPL(local_310,0xb4);
          }
          if (local_341 == 0) {
            cVar3 = bitVectorTestAllCleared_IMPL(local_370,0xb4);
            if (cVar3 == '\0') {
              local_368 = 0;
              bVar14 = bVar13;
            }
            else {
              cVar3 = bitVectorTestAllCleared_IMPL(local_310,0xb4);
              if (cVar3 == '\0') {
                local_368 = 0;
                bVar14 = bVar13;
              }
            }
          }
          else {
            local_368 = 0;
            bVar14 = local_341;
          }
        }
      }
    }
    if (local_368 == 0) {
      rmDeviceGpuLockSetOwner(param_1,0xffffffffffffffff);
    }
    else {
      if (bVar14 != 0) {
        nvAssertFailedNoLog("!pending","arch/nvalloc/unix/src/unix_intr.c",0x20e);
      }
      rmDeviceGpuLocksRelease(param_1,0,0);
    }
    threadStateFreeISRAndDeferredIntHandler(local_2c8,param_1,1);
    goto LAB_00279969;
  }
  if (*(long *)(param_1 + 0x1c20) != 0) {
    bVar14 = 0;
    if (*(char *)(*(long *)(param_1 + 0x1c20) + 0x346) == '\0') goto LAB_00279969;
    threadStateInitISRLockless(local_2c8,param_1,8);
    local_32c = 0;
    lVar10 = *(long *)(param_1 + 0x1c20);
    lVar1 = *(long *)(param_1 + 0x1b80);
    cVar3 = gpuIsGpuFullPower_IMPL(param_1);
    if ((cVar3 != '\0') &&
       ((**(code **)(lVar10 + 0x228))(param_1,lVar10,local_2f8,local_2c8), lVar1 != 0)) {
      if (*(char *)(lVar1 + 0x27a) == '\0') {
LAB_00279ad9:
        cVar3 = bitVectorTest_IMPL(local_2f8,0xb4,2);
        if (cVar3 == '\0') goto LAB_00279c0a;
      }
      else {
        cVar3 = bitVectorTest_IMPL(local_2f8,0xb4,0xb1);
        if (cVar3 == '\0') {
          if (*(char *)(lVar1 + 0x27a) != '\0') goto LAB_00279c0a;
          goto LAB_00279ad9;
        }
      }
      cVar3 = kdispAcquireLowLatencyLockConditional(lVar1 + 0x38c);
      if (cVar3 == '\0') {
        if (*(char *)(lVar10 + 0x346) != '\0') {
          (**(code **)(lVar10 + 0x228))(param_1,lVar10,local_2f8,local_2c8);
          if (*(char *)(lVar1 + 0x27a) == '\0') {
LAB_0027a357:
            iVar6 = 0;
            goto LAB_00279ba8;
          }
          cVar3 = bitVectorTest_IMPL(local_2f8,0xb4,0xb1);
          if (cVar3 == '\0') {
            if (*(char *)(lVar1 + 0x27a) != '\0') goto LAB_00279c00;
            goto LAB_0027a357;
          }
          iVar6 = 0;
          goto LAB_00279bc2;
        }
      }
      else {
        if (*(char *)(lVar1 + 0x27d) == '\0') {
          kdispServiceLowLatencyIntrs_KERNEL(param_1,lVar1,0,0x12,local_2c8,&local_32c,local_2f8);
        }
        else {
          iVar6 = kdispOptimizePerFrameOsCallbacks_IMPL
                            (param_1,lVar1,1,local_2c8,&local_32c,local_2f8);
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,
                       "kdispOptimizePerFrameOsCallbacks(pGpu, pKernelDisplay, NV_TRUE, pThreadState, &vblankIntrServicedHeadMask, &intrPending)"
                       ,"arch/nvalloc/unix/src/unix_intr.c",0x48);
          }
          if (local_32c != 0) {
            local_32c = local_32c | *(uint *)(lVar1 + 0x364);
            *(uint *)(lVar1 + 0x364) = local_32c;
          }
        }
        kdispReleaseLowLatencyLock(lVar1 + 0x38c);
        if ((*(char *)(lVar10 + 0x346) == '\0') ||
           (((**(code **)(lVar10 + 0x228))(param_1,lVar10,local_2f8,local_2c8),
            *(char *)(lVar1 + 0x27a) != '\0' &&
            (bitVectorTest_IMPL(local_2f8,0xb4,0xb1), *(char *)(lVar1 + 0x27a) != '\0')))) {
          if (local_32c != 0) goto LAB_00279c00;
          goto LAB_00279c0a;
        }
        iVar6 = 0x50;
LAB_00279ba8:
        cVar3 = bitVectorTest_IMPL(local_2f8,0xb4,2);
        if (cVar3 != '\0') {
LAB_00279bc2:
          uVar11 = rmIntrMaskLockAcquire(param_1);
          uVar12 = intrGetIntrMaskFlags_IMPL(lVar10);
          if (((uVar12 & 1) == 0) && (*(char *)(lVar10 + 0x346) != '\0')) {
            intrGetIntrMask_GP100(param_1,lVar10,local_2e0,local_2c8);
            bitVectorClr_IMPL(local_2e0,0xb4,2);
            if (*(char *)(lVar10 + 0x344) == '\0') {
              (**(code **)(lVar10 + 0x318))(param_1,lVar10,local_2e0,local_2c8);
            }
            else {
              (**(code **)(lVar10 + 0x230))(param_1,lVar10,0,local_2c8);
            }
          }
          rmIntrMaskLockRelease(param_1,uVar11);
        }
        if ((local_32c == 0) && (iVar6 != 0)) goto LAB_00279c0a;
      }
LAB_00279c00:
      *param_2 = 1;
    }
LAB_00279c0a:
    threadStateFreeISRLockless(local_2c8,param_1,8);
  }
  bVar14 = 0;
LAB_00279969:
  tlsIsrDestroy(uVar9);
  portMemAllocatorRelease(uVar9);
  return bVar14;
}


// ===== 0027a930 osIsr =====

undefined8 osIsr(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  char local_19 [9];
  
  lVar4 = 0;
  if (param_1 != 0) {
    lVar4 = 0;
    if (*(long **)(param_1 + 0x4e0) != (long *)0x0) {
      lVar4 = **(long **)(param_1 + 0x4e0);
    }
  }
  if (*(char *)(param_1 + 0x90a) != '\0') {
    return 0;
  }
  if ((*(byte *)(lVar4 + 0x48) & 8) == 0) {
    return 0x50;
  }
  if (*(char *)(param_1 + 0x45a) == '\0') {
    iVar3 = intrGetIntrEn_IMPL(*(undefined8 *)(param_1 + 0x1c20));
    if (iVar3 != 1) {
      return 0x50;
    }
    uVar1 = *(undefined8 *)(param_1 + 7000);
    cVar2 = osInterruptPending_constprop_0(param_1,local_19);
    kbifCheckAndRearmMSI_IMPL(param_1,uVar1);
  }
  else {
    cVar2 = osInterruptPending_constprop_0(param_1,local_19);
  }
  if (cVar2 == '\0') {
    if ((*(char *)(param_1 + 0x908) == '\0') && (local_19[0] != '\0')) {
      return 0;
    }
    return 0x50;
  }
  return 0x10005;
}


// ===== 0027aa20 osLockShouldToggleInterrupts =====

bool osLockShouldToggleInterrupts(long param_1)

{
  bool bVar1;
  
  if (*(char *)(param_1 + 0x90a) == '\0') {
    bVar1 = false;
    if (*(char *)(param_1 + 0x443) == '\0') {
      return *(char *)(param_1 + 0x4918) != '\0';
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


// ===== 0027aa50 osEnableInterrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void osEnableInterrupts(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x45a) == '\0') {
    lVar1 = *(long *)(param_1 + 0x1c20);
    if (*(char *)(lVar1 + 0x346) == '\0') {
      iVar2 = (**(code **)(lVar1 + 0x328))(param_1,lVar1,0);
      if (iVar2 != 0) {
        nvAssertFailedNoLog("intrGetIntrEnFromHw_HAL(pGpu, pIntr, NULL) == INTERRUPT_TYPE_DISABLED",
                            "arch/nvalloc/unix/src/unix_intr.c",0x282);
      }
    }
    uVar3 = intrGetIntrEn_IMPL(lVar1);
    (**(code **)(lVar1 + 800))(param_1,lVar1,uVar3,0);
    (**(code **)(lVar1 + 0x1c8))(param_1,lVar1,uVar3,0);
    uVar3 = intrGetIntrEn_IMPL(lVar1);
    (**(code **)(lVar1 + 0x180))(param_1,lVar1,uVar3,0);
    return;
  }
  nv_control_soc_irqs(*(undefined8 *)(param_1 + 0x4e0),1);
  return;
}


// ===== 0027ab40 osDisableInterrupts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void osDisableInterrupts(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x45a) != '\0') {
    nv_control_soc_irqs(*(undefined8 *)(param_1 + 0x4e0),0);
    return;
  }
  lVar1 = *(long *)(param_1 + 0x1c20);
  (**(code **)(lVar1 + 800))(param_1,lVar1,0,0);
  (**(code **)(lVar1 + 0x1c8))(param_1,lVar1,0,0);
  if (*(char *)(param_1 + 0x449) == '\0') {
    (**(code **)(lVar1 + 0x180))(param_1,lVar1,0,0);
    return;
  }
  uVar2 = intrGetIntrEn_IMPL(lVar1);
  (**(code **)(lVar1 + 0x180))(param_1,lVar1,uVar2,0);
  return;
}


// ===== 0027abf0 rm_isr =====

undefined8 rm_isr(undefined8 param_1,long *param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  
  if (((param_2 != (long *)0x0) && ((*(byte *)((long *)*param_2 + 9) & 8) != 0)) &&
     (lVar1 = *(long *)*param_2, lVar1 != 0)) {
    if (*(char *)(lVar1 + 0x90a) != '\0') {
      *param_3 = 0;
      return 1;
    }
    if (*(char *)(lVar1 + 0x8f8) == '\0') {
      iVar2 = osIsr();
    }
    else {
      iVar2 = osSanityTestIsr();
    }
    if (iVar2 == 0) {
      *param_3 = 0;
    }
    else {
      if (iVar2 != 0x10005) {
        *param_3 = 0;
        return 0;
      }
      *param_3 = 1;
    }
    return 1;
  }
  return 0;
}


// ===== 0027aca0 rm_isr_bh =====

void rm_isr_bh(undefined8 param_1,long *param_2)

{
  long lVar1;
  
  if ((((param_2 != (long *)0x0) && ((long *)*param_2 != (long *)0x0)) &&
      (lVar1 = *(long *)*param_2, lVar1 != 0)) && (*(char *)(lVar1 + 0x90a) != '\0')) {
    return;
  }
  RmIsrBottomHalf(param_2);
  return;
}


// ===== 0027acd1 rm_isr_bh_unlocked.cold =====

void rm_isr_bh_unlocked_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0027ace0 rm_isr_bh_unlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rm_isr_bh_unlocked(undefined8 param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined1 local_c0 [24];
  undefined1 local_a8 [152];
  
  if ((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)*param_2;
  if (((lVar1 == 0) || (*(char *)(lVar1 + 0x90a) == '\0')) && (*(char *)(lVar1 + 0x909) == '\0')) {
    threadStateInit(local_a8,0);
    iVar5 = rmDeviceGpuLocksAcquire(lVar1,0,0x200001);
    if (iVar5 == 0) {
      cVar4 = gpuIsGpuFullPower_IMPL(lVar1);
      if ((((cVar4 != '\0') && (*(char *)(lVar1 + 0x44c) != '\0')) &&
          ((*(char *)(lVar1 + 0x44f) == '\0' &&
           ((*(char *)(lVar1 + 0x450) == '\0' && (*(char *)(lVar1 + 0x451) == '\0')))))) &&
         (*(char *)(lVar1 + 0x455) == '\0')) {
        cVar4 = gpuCheckSysmemAccess_IMPL(lVar1);
        if (cVar4 != '\0') {
          lVar2 = *(long *)(lVar1 + 0x1c20);
          iVar5 = intrGetIntrEn_IMPL(lVar2);
          if (iVar5 != 0) {
            (**(code **)(lVar2 + 0x330))(lVar1,lVar2,local_c0,local_a8);
            intrServiceNonStallBottomHalf_IMPL(lVar1,lVar2,local_c0,local_a8);
          }
        }
      }
      rmDeviceGpuLocksRelease(lVar1,0,0);
    }
    threadStateFree(local_a8,0);
    return;
  }
  return;
}


// ===== 0027ae30 rm_gpu_copy_mmu_faults =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 rm_gpu_copy_mmu_faults(undefined8 param_1,long *param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 local_2a8 [144];
  undefined1 local_218 [512];
  
  if ((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) {
    return 0x57;
  }
  lVar1 = *(long *)*param_2;
  if ((lVar1 != 0) && (param_3 != 0)) {
    uVar3 = 0;
    if (*(char *)(lVar1 + 0x909) == '\0') {
      lVar2 = *(long *)(lVar1 + 0x1b98);
      if (lVar2 == 0) {
        return 0x57;
      }
      if (*(char *)(lVar1 + 0x4a7a) != '\0') {
        uVar4 = portMemAllocatorCreateOnExistingBlock(local_218,0x200);
        tlsIsrInit(uVar4);
        threadStateInitISRAndDeferredIntHandler(local_2a8,lVar1,1);
        uVar3 = (**(code **)(lVar2 + 0x390))(lVar1,lVar2,local_2a8,param_3,0,0);
        threadStateFreeISRAndDeferredIntHandler(local_2a8,lVar1,1);
        tlsIsrDestroy(uVar4);
        portMemAllocatorRelease(uVar4);
      }
    }
    return uVar3;
  }
  return 0x57;
}


// ===== 0027af60 rm_gpu_handle_mmu_faults =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 rm_gpu_handle_mmu_faults(undefined8 param_1,long *param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined1 local_2b8 [144];
  undefined1 local_228 [520];
  
  *param_3 = 0;
  if ((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) {
    return 0x57;
  }
  lVar1 = *(long *)*param_2;
  if (lVar1 == 0) {
    return 0x57;
  }
  uVar5 = portMemAllocatorCreateOnExistingBlock(local_228,0x200);
  tlsIsrInit(uVar5);
  threadStateInitISRLockless(local_2b8,lVar1,8);
  lVar6 = *(long *)(lVar1 + 0x1b98);
  if ((*(char *)(lVar1 + 0x4a4e) == '\0') || (*(char *)(lVar1 + 0x908) != '\0')) {
    if (*(char *)(lVar1 + 0x4913) == '\0') {
      if (*(char *)(lVar1 + 0x909) == '\0') goto LAB_0027b0dd;
    }
    else {
      cVar3 = (**(code **)(lVar6 + 0x308))(lVar1,lVar6,local_2b8);
      if (cVar3 != '\0') {
        lVar6 = *(long *)(lVar1 + 0x1b98);
LAB_0027b0dd:
        uVar4 = 0x57;
        if (lVar6 == 0) goto LAB_0027b012;
        if (*(char *)(lVar1 + 0x4a7a) != '\0') {
          uVar4 = (**(code **)(lVar6 + 0x390))(lVar1,lVar6,local_2b8,param_3,0,0);
          goto LAB_0027b012;
        }
      }
    }
  }
  else {
    lVar2 = *(long *)(lVar1 + 0x1c20);
    cVar3 = (**(code **)(lVar6 + 0x308))(lVar1,lVar6,local_2b8);
    if (cVar3 != '\0') {
      (**(code **)(lVar6 + 0x358))(lVar1,lVar6,local_2b8);
      uVar4 = (**(code **)(lVar2 + 0x208))(lVar1,lVar2,0x10);
      goto LAB_0027b012;
    }
  }
  uVar4 = 0;
LAB_0027b012:
  threadStateFreeISRLockless(local_2b8,lVar1,8);
  tlsIsrDestroy(uVar5);
  portMemAllocatorRelease(uVar5);
  return uVar4;
}


// ===== 0027b140 rm_is_msix_allowed =====

undefined4 rm_is_msix_allowed(undefined8 param_1,long *param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined1 local_b8 [152];
  
  lVar3 = 0;
  if (param_2 != (long *)0x0) {
    lVar3 = *param_2;
  }
  uVar2 = 0;
  threadStateInit(local_b8,0);
  iVar1 = rmapiLockAcquire(0,0x400000);
  if (iVar1 == 0) {
    uVar2 = gpumgrIsDeviceMsixAllowed
                      (*(undefined8 *)param_2[0x21],*(undefined4 *)(lVar3 + 0x250),
                       *(undefined4 *)(lVar3 + 0x254));
    rmapiLockRelease();
  }
  threadStateFree(local_b8,0);
  return uVar2;
}


// ===== 0027b1d0 x86emu_do_int =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emu_do_int(int param_1)

{
  if ((param_1 == 0x15) && (DAT_005483d8 == 0x5f80)) {
    _DAT_005483d8 = _DAT_005483d8 & 0xffff0000;
    return;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/vbioscall.c",0x104,"x86emu_do_int",4,
               "NVRM: x86emu: int $%d (eax = %08x)\n",param_1,_DAT_005483d8);
  X86EMU_halt_sys();
  return;
}


// ===== 0027b240 Mem_addr_xlat =====

long Mem_addr_xlat(uint param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = &x86emu_mem_map;
  while (((*(long *)(puVar1 + 2) == 0 || (param_1 < *puVar1)) ||
         (puVar1[1] < (param_1 - 1) + param_2))) {
    puVar1 = puVar1 + 4;
    if (puVar1 == (uint *)x86emu_optab) {
      X86EMU_halt_sys();
      return 0;
    }
  }
  return *(long *)(puVar1 + 2) + ((ulong)param_1 - (ulong)*puVar1);
}


// ===== 0027b290 Mem_wl =====

void Mem_wl(undefined8 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)Mem_addr_xlat(param_1,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return;
}


// ===== 0027b2c0 Mem_ww =====

void Mem_ww(undefined8 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)Mem_addr_xlat(param_1,2);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = param_2;
  }
  return;
}


// ===== 0027b2f0 Mem_wb =====

void Mem_wb(undefined8 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)Mem_addr_xlat(param_1,1);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_2;
  }
  return;
}


// ===== 0027b320 Mem_rl =====

undefined4 Mem_rl(undefined8 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)Mem_addr_xlat(param_1,4);
  uVar1 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *puVar2;
  }
  return uVar1;
}


// ===== 0027b340 Mem_rw =====

undefined2 Mem_rw(undefined8 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)Mem_addr_xlat(param_1,2);
  uVar1 = 0;
  if (puVar2 != (undefined2 *)0x0) {
    uVar1 = *puVar2;
  }
  return uVar1;
}


// ===== 0027b370 Mem_rb =====

undefined1 Mem_rb(undefined8 param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)Mem_addr_xlat(param_1,1);
  uVar1 = 0;
  if (puVar2 != (undefined1 *)0x0) {
    uVar1 = *puVar2;
  }
  return uVar1;
}


// ===== 0027b3a0 x_outl =====

void x_outl(undefined2 param_1)

{
  os_io_write_dword(param_1);
  return;
}


// ===== 0027b3b0 x_outw =====

void x_outw(undefined2 param_1,undefined2 param_2)

{
  os_io_write_word(param_1,param_2);
  return;
}


// ===== 0027b3c0 x_outb =====

void x_outb(undefined2 param_1,undefined1 param_2)

{
  os_io_write_byte(param_1,param_2);
  return;
}


// ===== 0027b3d0 x_inl =====

void x_inl(undefined2 param_1)

{
  os_io_read_dword(param_1);
  return;
}


// ===== 0027b3e0 x_inw =====

void x_inw(undefined2 param_1)

{
  os_io_read_word(param_1);
  return;
}


// ===== 0027b3f0 x_inb =====

void x_inb(undefined2 param_1)

{
  os_io_read_byte(param_1);
  return;
}


// ===== 0027b3fc RmInitX86EmuState.cold =====

void RmInitX86EmuState_cold(void)

{
  code *pcVar1;
  undefined8 unaff_RBX;
  long unaff_RBP;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_RBX;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R13;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0027b420 RmInitX86EmuState =====

undefined8 RmInitX86EmuState(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  bool bVar10;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  int iVar9;
  
  local_88 = x_inb;
  local_80 = x_inw;
  local_78 = x_inl;
  local_70 = x_outb;
  local_68 = x_outw;
  local_60 = x_outl;
  local_58 = Mem_rb;
  local_50 = Mem_rw;
  local_48 = Mem_rl;
  local_40 = Mem_wb;
  local_38 = Mem_ww;
  local_30 = Mem_wl;
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (*(char *)(*(long *)(param_1 + 0x4e0) + 700) != '\0') {
    if (x86emuReady != '\0') {
      nvAssertFailedNoLog("!x86emuReady","arch/nvalloc/unix/src/vbioscall.c",0x126);
    }
    lVar2 = portMemAllocNonPaged(0x1800);
    x86emuStack = lVar2;
    if (lVar2 != 0) {
      iVar8 = 0;
      piVar6 = &x86emu_mem_map;
      iVar9 = -5;
      bVar10 = false;
      do {
        if (bVar10 || SBORROW4(iVar8,5) != iVar9 < 0) {
          if (iVar8 != 1) {
            if (2 < iVar8 - 2U) {
              piVar6[2] = 0;
              piVar6[3] = 0;
              piVar7 = piVar6;
              iVar9 = iVar8;
              goto LAB_0027b534;
            }
            nv_get_updated_emu_seg(piVar6,piVar6 + 1);
          }
        }
        else if (iVar8 != 6) {
          piVar6[2] = 0;
          piVar6[3] = 0;
          X86EMU_setupMemFuncs(&local_58);
          _X86EMU_env = 0;
          DAT_005483c8 = 0x100000;
          X86EMU_setupPioFuncs(&local_88);
          puVar4 = (undefined8 *)(lVar2 + 0x1000);
          do {
            *puVar4 = x86emu_do_int;
            puVar5 = puVar4 + 2;
            puVar4[1] = x86emu_do_int;
            puVar4 = puVar5;
          } while (puVar5 != (undefined8 *)(lVar2 + 0x1800));
          X86EMU_setupIntrFuncs(lVar2 + 0x1000);
          x86emuReady = 1;
          return 0;
        }
        while( true ) {
          lVar3 = os_map_kernel_space(*piVar6,(piVar6[1] + 1) - *piVar6,0);
          *(long *)(piVar6 + 2) = lVar3;
          piVar7 = piVar6;
          iVar9 = iVar8;
          if (lVar3 == 0) {
            nvDbg_Printf("arch/nvalloc/unix/src/vbioscall.c",0x142,"RmInitX86EmuState",4,
                         "NVRM: x86emu can\'t map phys addr 0x%05x\n",*piVar6);
            return 0xffff;
          }
LAB_0027b534:
          iVar8 = iVar9 + 1;
          piVar6 = piVar7 + 4;
          iVar9 = iVar9 + -4;
          bVar10 = iVar9 == 0;
          if (!bVar10) break;
          piVar6 = piVar7 + 8;
          iVar8 = 6;
          *(long *)(piVar7 + 6) = x86emuStack;
        }
      } while( true );
    }
    return 0x51;
  }
  return 0;
}


// ===== 0027b66c RmFreeX86EmuState.cold =====

void RmFreeX86EmuState_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0027b680 RmFreeX86EmuState =====

void RmFreeX86EmuState(long param_1)

{
  code *pcVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  
  if (x86emuReady != '\0') {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if (*(char *)(*(long *)(param_1 + 0x4e0) + 700) != '\0') {
      iVar4 = 0;
      piVar2 = &x86emu_mem_map;
      portMemFree(x86emuStack);
      x86emuStack = 0;
      do {
        lVar3 = *(long *)(piVar2 + 2);
        if (lVar3 == 0) goto LAB_0027b6f4;
        while( true ) {
          os_unmap_kernel_space(lVar3,(piVar2[1] + 1) - *piVar2);
LAB_0027b6f4:
          iVar4 = iVar4 + 1;
          piVar2[2] = 0;
          piVar2[3] = 0;
          piVar2 = piVar2 + 4;
          if (iVar4 < 5) break;
          if (iVar4 != 6) goto LAB_0027b735;
          for (; lVar3 = *(long *)(piVar2 + 2), lVar3 == 0; piVar2 = piVar2 + 4) {
            piVar2 = piVar2 + 4;
            iVar4 = 7;
LAB_0027b735:
            piVar2[2] = 0;
            piVar2[3] = 0;
            if (iVar4 == 7) {
              x86emuReady = 0;
              return;
            }
            iVar4 = 6;
          }
        }
      } while( true );
    }
  }
  return;
}


// ===== 0027b74f nv_vbios_call.cold =====

void nv_vbios_call_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0027b760 nv_vbios_call =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_vbios_call(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  uint *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  ushort uVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (*(char *)(*(long *)(param_1 + 0x4e0) + 700) == '\0') {
    return 0xffff;
  }
  puVar5 = &x86emu_mem_map;
  puVar2 = &x86emu_mem_map;
  do {
    if (((*(long *)(puVar2 + 2) != 0) && (*puVar2 < 0x43)) && (0x42 < puVar2[1])) {
      uVar7 = *(ushort *)((*(long *)(puVar2 + 2) - (ulong)*puVar2) + 0x42);
      uVar6 = (uint)uVar7;
      goto LAB_0027b7dd;
    }
    puVar2 = puVar2 + 4;
  } while (puVar2 != (uint *)x86emu_optab);
  X86EMU_halt_sys();
  uVar7 = 0;
  uVar6 = 0;
LAB_0027b7dd:
  puVar2 = &x86emu_mem_map;
  do {
    if (((*(long *)(puVar2 + 2) != 0) && (*puVar2 < 0x41)) && (0x40 < puVar2[1])) {
      uVar4 = (uint)*(ushort *)((*(long *)(puVar2 + 2) - (ulong)*puVar2) + 0x40);
      goto LAB_0027b820;
    }
    puVar2 = puVar2 + 4;
  } while (puVar2 != (uint *)x86emu_optab);
  X86EMU_halt_sys();
  uVar4 = 0;
LAB_0027b820:
  if (uVar6 < DAT_00593850 >> 4) {
    if (uVar6 < x86emu_mem_map >> 4) {
      nvDbg_Printf("arch/nvalloc/unix/src/vbioscall.c",0x194,"nv_vbios_call",4,
                   "NVRM: cannot call the VBIOS. INT10 vector not in ROM: %04x:%04x\n",uVar7,uVar4);
      return 0xffff;
    }
    if ((DAT_00593848 == 0) &&
       (DAT_00593848 = os_map_kernel_space(x86emu_mem_map,(DAT_00593844 + 1) - x86emu_mem_map,0),
       DAT_00593848 == 0)) {
      nvDbg_Printf("arch/nvalloc/unix/src/vbioscall.c",0x1a0,"nv_vbios_call",4,
                   "NVRM: x86emu can\'t map phys addr 0x%05x\n",x86emu_mem_map);
      return 0xffff;
    }
  }
  portMemSet(&_X86EMU_env,0,0x60);
  DAT_005483e8 = 0x1000;
  DAT_00548404 = 0x1000;
  DAT_005483fc = 0x200;
  _DAT_005483d8 = *param_2;
  _DAT_005483dc = *param_3;
  _DAT_005483e0 = 0;
  DAT_00548406 = 0x2000;
  _DAT_005483f8 = uVar4;
  DAT_00548400 = uVar7;
  X86EMU_trace_on();
  _DAT_005938b8 = 0;
  while (((*(long *)(puVar5 + 2) == 0 || (0x10000 < *puVar5)) || (puVar5[1] < 0x10000))) {
    puVar5 = puVar5 + 4;
    if (puVar5 == (uint *)x86emu_optab) {
      X86EMU_halt_sys();
LAB_0027b90e:
      DAT_005483e8 = DAT_005483e8 + -2;
      puVar3 = (undefined2 *)Mem_addr_xlat((uint)DAT_00548404 * 0x10 + DAT_005483e8,2);
      if (puVar3 != (undefined2 *)0x0) {
        *puVar3 = 0x200;
      }
      DAT_005483e8 = DAT_005483e8 + -2;
      puVar3 = (undefined2 *)Mem_addr_xlat((uint)DAT_00548404 * 0x10 + DAT_005483e8,2);
      if (puVar3 != (undefined2 *)0x0) {
        *puVar3 = 0x1000;
      }
      DAT_005483e8 = DAT_005483e8 + -2;
      puVar3 = (undefined2 *)Mem_addr_xlat((uint)DAT_00548404 * 0x10 + DAT_005483e8,2);
      if (puVar3 != (undefined2 *)0x0) {
        *puVar3 = 0;
      }
      X86EMU_exec();
      *param_2 = _DAT_005483d8;
      *param_3 = _DAT_005483dc;
      return 0;
    }
  }
  *(undefined1 *)((*(long *)(puVar5 + 2) - (ulong)*puVar5) + 0x10000) = 0xf4;
  goto LAB_0027b90e;
}


// ===== 0027bac0 X86EMU_trace_on =====

undefined8 X86EMU_trace_on(void)

{
  return 0;
}


// ===== 0027bad0 get_data_segment =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 get_data_segment(void)

{
  uint uVar1;
  
  uVar1 = DAT_0054840c & 0x7f;
  if (9 < uVar1) {
    if (uVar1 < 0x22) {
      if ((DAT_0054840c & 0x60) != 0) {
        return _DAT_0054840a;
      }
      if (uVar1 - 0x10 < 2) {
        return _DAT_00548408;
      }
    }
    else if (uVar1 - 0x40 < 2) {
      return DAT_00548404;
    }
LAB_0027bb58:
    _DAT_00548410 = _DAT_00548410 | 4;
    return 0;
  }
  if ((DAT_0054840c & 0x78) != 0) {
    return DAT_00548406;
  }
  if ((DAT_0054840c & 0x7c) == 0) {
    if ((DAT_0054840c & 0x7e) != 0) {
      return DAT_00548400;
    }
    if (uVar1 != 0) {
      return DAT_00548404;
    }
  }
  else if (1 < uVar1 - 4) goto LAB_0027bb58;
  return DAT_00548402;
}


// ===== 0027bb70 x86emu_intr_raise =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emu_intr_raise(undefined1 param_1)

{
  _DAT_00548410 = _DAT_00548410 | 1;
  DAT_00548418 = param_1;
  return;
}


// ===== 0027bb90 X86EMU_exec =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void X86EMU_exec(void)

{
  byte bVar1;
  uint uVar2;
  
  _DAT_00548410 = 0;
  do {
    if (_DAT_00548410 != 0) {
      if ((_DAT_00548410 & 4) != 0) {
        return;
      }
      if (((((_DAT_00548410 & 1) != 0) && ((DAT_00548418 & 0xfd) == 0)) ||
          ((DAT_005483fc & 0x200) == 0)) && ((_DAT_00548410 & 1) != 0)) {
        uVar2 = (uint)DAT_00548418;
        if ((code *)(&_X86EMU_intrTab)[uVar2] == (code *)0x0) {
          push_word(DAT_005483fc & 0xffff);
          DAT_005483fc = DAT_005483fc & 0xfffffcff;
          push_word(DAT_00548400);
          DAT_00548400 = mem_access_word(uVar2 * 4 + 2);
          push_word(DAT_005483f8);
          DAT_005483f8 = mem_access_word(uVar2 * 4);
          _DAT_00548410 = 0;
        }
        else {
          (*(code *)(&_X86EMU_intrTab)[uVar2])((ulong)uVar2);
        }
      }
    }
    uVar2 = (uint)DAT_005483f8;
    DAT_005483f8 = DAT_005483f8 + 1;
    bVar1 = (*(code *)sys_rdb)(uVar2 + (uint)DAT_00548400 * 0x10);
    (**(code **)(x86emu_optab + (ulong)bVar1 * 8))(bVar1);
  } while ((_DAT_00548414 & 0x10000) == 0);
  _DAT_00548414 = _DAT_00548414 & 0xfffeffff;
  return;
}


// ===== 0027bcf0 X86EMU_halt_sys =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void X86EMU_halt_sys(void)

{
  _DAT_00548410 = _DAT_00548410 | 4;
  return;
}


// ===== 0027bd00 fetch_decode_modrm =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_decode_modrm(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_005483f8;
  DAT_005483f8 = DAT_005483f8 + 1;
  uVar1 = (*(code *)sys_rdb)(uVar1 + (uint)DAT_00548400 * 0x10);
  *param_1 = (int)(uVar1 & 0xff) >> 6;
  *param_2 = (int)(uVar1 & 0xff) >> 3 & 7;
  *param_3 = uVar1 & 7;
  return;
}


// ===== 0027bd70 fetch_byte_imm =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_byte_imm(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_005483f8;
  DAT_005483f8 = DAT_005483f8 + 1;
  (*(code *)sys_rdb)(uVar1 + (uint)DAT_00548400 * 0x10);
  return;
}


// ===== 0027bda0 fetch_word_imm =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_word_imm(void)

{
  (*(code *)sys_rdw)((uint)DAT_00548400 * 0x10 + (uint)DAT_005483f8);
  DAT_005483f8 = DAT_005483f8 + 2;
  return;
}


// ===== 0027bde0 fetch_long_imm =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_long_imm(void)

{
  (*(code *)sys_rdl)((uint)DAT_00548400 * 0x10 + (uint)DAT_005483f8);
  DAT_005483f8 = DAT_005483f8 + 4;
  return;
}


// ===== 0027be20 fetch_data_byte =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void fetch_data_byte(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)sys_rdb;
  iVar1 = get_data_segment();
  (*pcVar2)(param_1 + iVar1 * 0x10);
  return;
}


// ===== 0027be40 fetch_data_word =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void fetch_data_word(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)sys_rdw;
  iVar1 = get_data_segment();
  (*pcVar2)(param_1 + iVar1 * 0x10);
  return;
}


// ===== 0027be60 fetch_data_long =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void fetch_data_long(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)sys_rdl;
  iVar1 = get_data_segment();
  (*pcVar2)(param_1 + iVar1 * 0x10);
  return;
}


// ===== 0027be80 fetch_data_byte_abs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_data_byte_abs(int param_1,int param_2)

{
  (*(code *)sys_rdb)(param_1 * 0x10 + param_2);
  return;
}


// ===== 0027bea0 fetch_data_word_abs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_data_word_abs(int param_1,int param_2)

{
  (*(code *)sys_rdw)(param_1 * 0x10 + param_2);
  return;
}


// ===== 0027bec0 fetch_data_long_abs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fetch_data_long_abs(int param_1,int param_2)

{
  (*(code *)sys_rdl)(param_1 * 0x10 + param_2);
  return;
}


// ===== 0027bee0 store_data_byte =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void store_data_byte(undefined8 param_1,undefined1 param_2)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)sys_wrb;
  iVar1 = get_data_segment(param_1,param_2);
  (*pcVar2)((int)param_1 + iVar1 * 0x10);
  return;
}


// ===== 0027bf10 store_data_word =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void store_data_word(undefined8 param_1,undefined2 param_2)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)sys_wrw;
  iVar1 = get_data_segment(param_1,param_2);
  (*pcVar2)((int)param_1 + iVar1 * 0x10);
  return;
}


// ===== 0027bf40 store_data_long =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void store_data_long(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = (code *)sys_wrl;
  iVar1 = get_data_segment();
  (*pcVar2)(param_1 + iVar1 * 0x10);
  return;
}


// ===== 0027bf60 store_data_byte_abs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void store_data_byte_abs(int param_1,int param_2,undefined1 param_3)

{
  (*(code *)sys_wrb)(param_1 * 0x10 + param_2,param_3);
  return;
}


// ===== 0027bf80 store_data_word_abs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void store_data_word_abs(int param_1,int param_2,undefined2 param_3)

{
  (*(code *)sys_wrw)(param_1 * 0x10 + param_2,param_3);
  return;
}


// ===== 0027bfa0 store_data_long_abs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void store_data_long_abs(int param_1,int param_2,undefined4 param_3)

{
  (*(code *)sys_wrl)(param_1 * 0x10 + param_2,param_3);
  return;
}


// ===== 0027bfc0 decode_rm_byte_register =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

pointer_____offset_0x18___ decode_rm_byte_register(uint param_1)

{
  if (param_1 < 8) {
    return (&CSWTCH_47)[param_1];
  }
  _DAT_00548410 = _DAT_00548410 | 4;
  return (pointer_____offset_0x18___)0x0;
}


// ===== 0027bff0 decode_rm_word_register =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

pointer_____offset_0x18___ decode_rm_word_register(uint param_1)

{
  if (param_1 < 8) {
    return (&CSWTCH_49)[param_1];
  }
  _DAT_00548410 = _DAT_00548410 | 4;
  return (pointer_____offset_0x18___)0x0;
}


// ===== 0027c020 decode_rm_long_register =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

pointer_____offset_0x18___ decode_rm_long_register(uint param_1)

{
  if (param_1 < 8) {
    return (&CSWTCH_51)[param_1];
  }
  _DAT_00548410 = _DAT_00548410 | 4;
  return (pointer_____offset_0x18___)0x0;
}


// ===== 0027c050 decode_rm_seg_register =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

pointer_____offset_0x46___ decode_rm_seg_register(uint param_1)

{
  if (param_1 < 6) {
    return (&CSWTCH_53)[param_1];
  }
  _DAT_00548410 = _DAT_00548410 | 4;
  return (pointer_____offset_0x46___)0x0;
}


// ===== 0027c080 decode_sib_address =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int decode_sib_address(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1 & 7;
  if (uVar2 != 4) {
    if (uVar2 < 5) {
      iVar3 = DAT_005483e4;
      if (((uVar2 != 2) && (iVar3 = _DAT_005483dc, uVar2 != 3)) &&
         (iVar3 = _DAT_005483d8, uVar2 == 1)) {
        iVar3 = DAT_005483e0;
      }
      goto LAB_0027c0c2;
    }
    iVar3 = _DAT_005483f0;
    if ((uVar2 == 6) || (iVar3 = _DAT_005483f4, uVar2 == 7)) goto LAB_0027c0c2;
    if (param_2 == 0) {
      iVar3 = (*(code *)sys_rdl)((uint)DAT_00548400 * 0x10 + (uint)DAT_005483f8);
      DAT_005483f8 = DAT_005483f8 + 4;
      goto LAB_0027c0c2;
    }
  }
  DAT_0054840c = DAT_0054840c | 1;
  iVar3 = DAT_005483e8;
LAB_0027c0c2:
  uVar2 = (int)param_1 >> 3 & 7;
  bVar1 = (byte)((int)param_1 >> 6);
  if (uVar2 == 3) {
    return iVar3 + (_DAT_005483dc << (bVar1 & 3));
  }
  if ((param_1 & 0x20) != 0) {
    if (uVar2 == 6) {
      return iVar3 + (_DAT_005483f0 << (bVar1 & 3));
    }
    if (uVar2 == 7) {
      return iVar3 + (_DAT_005483f4 << (bVar1 & 3));
    }
    if (uVar2 == 5) {
      iVar3 = iVar3 + (DAT_005483ec << (bVar1 & 3));
    }
    return iVar3;
  }
  if (uVar2 == 1) {
    return iVar3 + (DAT_005483e0 << (bVar1 & 3));
  }
  if (uVar2 == 2) {
    return iVar3 + (DAT_005483e4 << (bVar1 & 3));
  }
  return iVar3 + (_DAT_005483d8 << (bVar1 & 3));
}


// ===== 0027c200 decode_rm00_address =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong decode_rm00_address(int param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  ulong uVar4;
  
  if ((DAT_0054840c & 0x400) == 0) {
    if (param_1 == 4) {
      return (ulong)(_DAT_005483f0 & 0xffff);
    }
    if (param_1 < 5) {
      if (param_1 == 2) {
        DAT_0054840c = DAT_0054840c | 1;
        return (ulong)(ushort)((short)_DAT_005483f0 + (short)DAT_005483ec);
      }
      if (param_1 == 3) {
        DAT_0054840c = DAT_0054840c | 1;
        return (ulong)(ushort)((short)_DAT_005483f4 + (short)DAT_005483ec);
      }
      if (param_1 == 0) {
        uVar2 = (short)_DAT_005483f0 + DAT_005483dc;
        return (ulong)uVar2;
      }
      if (param_1 == 1) {
        uVar2 = (short)_DAT_005483f4 + DAT_005483dc;
        return (ulong)uVar2;
      }
    }
    else {
      if (param_1 == 6) {
        uVar2 = (*(code *)sys_rdw)((uint)DAT_00548400 * 0x10 + (uint)DAT_005483f8);
        DAT_005483f8 = DAT_005483f8 + 2;
        return (ulong)uVar2;
      }
      if (param_1 == 7) {
        return (ulong)(_DAT_005483dc & 0xffff);
      }
      if (param_1 == 5) {
        return (ulong)(_DAT_005483f4 & 0xffff);
      }
    }
    _DAT_00548410 = _DAT_00548410 | 4;
    return 0;
  }
  if (param_1 == 4) {
    uVar3 = (uint)DAT_005483f8;
    DAT_005483f8 = DAT_005483f8 + 1;
    uVar1 = (*(code *)sys_rdb)(uVar3 + (uint)DAT_00548400 * 0x10);
    uVar4 = decode_sib_address(uVar1,0);
    return uVar4;
  }
  if (param_1 < 5) {
    if (param_1 == 2) {
      return (ulong)DAT_005483e4;
    }
    uVar4 = (ulong)_DAT_005483dc;
    if (((param_1 != 3) && (uVar4 = (ulong)_DAT_005483d8, param_1 != 0)) &&
       (uVar4 = (ulong)DAT_005483e0, param_1 != 1)) {
LAB_0027c310:
      _DAT_00548410 = _DAT_00548410 | 4;
      return 0;
    }
  }
  else {
    if (param_1 == 6) {
      return (ulong)_DAT_005483f0;
    }
    uVar4 = (ulong)_DAT_005483f4;
    if (param_1 != 7) {
      if (param_1 == 5) {
        uVar4 = (*(code *)sys_rdl)((uint)DAT_00548400 * 0x10 + (uint)DAT_005483f8);
        DAT_005483f8 = DAT_005483f8 + 4;
        return uVar4;
      }
      goto LAB_0027c310;
    }
  }
  return uVar4;
}


// ===== 0027c420 decode_rm01_address =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint decode_rm01_address(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  if (((DAT_0054840c & 0x400) == 0) || (param_1 != 4)) {
    uVar5 = (uint)DAT_005483f8;
    DAT_005483f8 = DAT_005483f8 + 1;
    cVar1 = (*(code *)sys_rdb)((uint)DAT_00548400 * 0x10 + uVar5);
    iVar4 = (int)cVar1;
    if ((DAT_0054840c & 0x400) == 0) {
      if (param_1 == 3) {
        DAT_0054840c = DAT_0054840c | 1;
        return (DAT_005483ec & 0xffff) + (_DAT_005483f4 & 0xffff) + iVar4 & 0xffff;
      }
      if (param_1 < 4) {
        if (param_1 == 1) {
          return (_DAT_005483dc & 0xffff) + (_DAT_005483f4 & 0xffff) + iVar4 & 0xffff;
        }
        if (param_1 == 2) {
          DAT_0054840c = DAT_0054840c | 1;
          return (DAT_005483ec & 0xffff) + (_DAT_005483f0 & 0xffff) + iVar4 & 0xffff;
        }
        if (param_1 == 0) {
          return (_DAT_005483dc & 0xffff) + (_DAT_005483f0 & 0xffff) + iVar4 & 0xffff;
        }
      }
      else {
        if (param_1 == 6) {
          DAT_0054840c = DAT_0054840c | 1;
          return (DAT_005483ec & 0xffff) + iVar4 & 0xffff;
        }
        if (param_1 < 7) {
          if (param_1 != 4) {
            return (_DAT_005483f4 & 0xffff) + iVar4 & 0xffff;
          }
          return (_DAT_005483f0 & 0xffff) + iVar4 & 0xffff;
        }
        if (param_1 == 7) {
          uVar3 = cVar1 + DAT_005483dc;
          return (uint)uVar3;
        }
      }
      _DAT_00548410 = _DAT_00548410 | 4;
      return 0;
    }
    if (param_1 == 3) {
      return (int)cVar1 + _DAT_005483dc;
    }
    if (param_1 < 4) {
      if (param_1 == 1) {
        return cVar1 + DAT_005483e0;
      }
      if (param_1 == 2) {
        return cVar1 + DAT_005483e4;
      }
      if (param_1 == 0) {
        return cVar1 + _DAT_005483d8;
      }
    }
    else {
      if (param_1 == 6) {
        return (int)cVar1 + _DAT_005483f0;
      }
      if (param_1 < 7) {
        if (param_1 != 4) {
          return (int)cVar1 + DAT_005483ec;
        }
        goto LAB_0027c4f0;
      }
      if (param_1 == 7) {
        return (int)cVar1 + _DAT_005483f4;
      }
    }
    _DAT_00548410 = _DAT_00548410 | 4;
    uVar5 = 0;
  }
  else {
LAB_0027c4f0:
    uVar5 = (uint)DAT_005483f8;
    DAT_005483f8 = DAT_005483f8 + 1;
    uVar2 = (*(code *)sys_rdb)(uVar5 + (uint)DAT_00548400 * 0x10);
    uVar5 = (uint)DAT_005483f8;
    DAT_005483f8 = DAT_005483f8 + 1;
    cVar1 = (*(code *)sys_rdb)(uVar5 + (uint)DAT_00548400 * 0x10);
    iVar4 = decode_sib_address(uVar2,1);
    uVar5 = cVar1 + iVar4;
  }
  return uVar5;
}


// ===== 0027c710 decode_rm10_address =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint decode_rm10_address(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar2 = (uint)DAT_00548400;
  if ((DAT_0054840c & 0x400) == 0) {
    uVar5 = (*(code *)sys_rdw)(uVar2 * 0x10 + (uint)DAT_005483f8);
    uVar2 = (uint)uVar5;
    DAT_005483f8 = DAT_005483f8 + 2;
LAB_0027c7d8:
    if ((DAT_0054840c & 0x400) == 0) {
      if (param_1 == 3) {
        DAT_0054840c = DAT_0054840c | 1;
        return (DAT_005483ec & 0xffff) + (_DAT_005483f4 & 0xffff) + uVar2 & 0xffff;
      }
      if (param_1 < 4) {
        if (param_1 == 1) {
          return (_DAT_005483dc & 0xffff) + (_DAT_005483f4 & 0xffff) + uVar2 & 0xffff;
        }
        if (param_1 == 2) {
          DAT_0054840c = DAT_0054840c | 1;
          return (DAT_005483ec & 0xffff) + (_DAT_005483f0 & 0xffff) + uVar2 & 0xffff;
        }
        if (param_1 == 0) {
          return (_DAT_005483dc & 0xffff) + (_DAT_005483f0 & 0xffff) + uVar2 & 0xffff;
        }
      }
      else {
        if (param_1 == 6) {
          DAT_0054840c = DAT_0054840c | 1;
          return (DAT_005483ec & 0xffff) + uVar2 & 0xffff;
        }
        if (param_1 < 7) {
          if (param_1 != 4) {
            return (_DAT_005483f4 & 0xffff) + uVar2 & 0xffff;
          }
          return (_DAT_005483f0 & 0xffff) + uVar2 & 0xffff;
        }
        if (param_1 == 7) {
          uVar5 = (short)uVar2 + DAT_005483dc;
          return (uint)uVar5;
        }
      }
      _DAT_00548410 = _DAT_00548410 | 4;
      return 0;
    }
    if (param_1 == 3) {
      return _DAT_005483dc + uVar2;
    }
    if (param_1 < 4) {
      if (param_1 == 1) {
        return DAT_005483e0 + uVar2;
      }
      if (param_1 == 2) {
        DAT_0054840c = DAT_0054840c | 1;
        return DAT_005483e4 + uVar2;
      }
      if (param_1 == 0) {
        return _DAT_005483d8 + uVar2;
      }
    }
    else {
      if (param_1 == 6) {
        return _DAT_005483f0 + uVar2;
      }
      if (param_1 < 7) {
        if (param_1 != 4) {
          return DAT_005483ec + uVar2;
        }
        uVar2 = (uint)DAT_00548400;
        goto LAB_0027c74d;
      }
      if (param_1 == 7) {
        return _DAT_005483f4 + uVar2;
      }
    }
    _DAT_00548410 = _DAT_00548410 | 4;
    uVar2 = 0;
  }
  else {
    if (param_1 != 4) {
      uVar2 = (*(code *)sys_rdl)();
      DAT_005483f8 = DAT_005483f8 + 4;
      goto LAB_0027c7d8;
    }
LAB_0027c74d:
    uVar6 = (uint)DAT_005483f8;
    DAT_005483f8 = DAT_005483f8 + 1;
    uVar1 = (*(code *)sys_rdb)(uVar6 + uVar2 * 0x10);
    iVar3 = (*(code *)sys_rdl)((uint)DAT_00548400 * 0x10 + (uint)DAT_005483f8);
    DAT_005483f8 = DAT_005483f8 + 4;
    iVar4 = decode_sib_address(uVar1,2);
    uVar2 = iVar4 + iVar3;
  }
  return uVar2;
}


// ===== 0027ca20 x86emuOp_esc_coprocess_d8 =====

void x86emuOp_esc_coprocess_d8(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027ca30 x86emuOp_esc_coprocess_d9 =====

void x86emuOp_esc_coprocess_d9(void)

{
  int local_14;
  undefined4 local_10;
  undefined1 local_c [4];
  
  fetch_decode_modrm(&local_14,local_c,&local_10);
  if (local_14 == 1) {
    decode_rm01_address(local_10);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_14 != 2) {
    if (local_14 == 0) {
      decode_rm00_address(local_10);
    }
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  decode_rm10_address(local_10);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027cab0 x86emuOp_esc_coprocess_da =====

void x86emuOp_esc_coprocess_da(undefined1 param_1)

{
  x86emuOp_esc_coprocess_d9(param_1);
  return;
}


// ===== 0027cac0 x86emuOp_esc_coprocess_db =====

void x86emuOp_esc_coprocess_db(undefined1 param_1)

{
  x86emuOp_esc_coprocess_d9(param_1);
  return;
}


// ===== 0027cad0 x86emuOp_esc_coprocess_dc =====

void x86emuOp_esc_coprocess_dc(undefined1 param_1)

{
  x86emuOp_esc_coprocess_d9(param_1);
  return;
}


// ===== 0027cae0 x86emuOp_esc_coprocess_dd =====

void x86emuOp_esc_coprocess_dd(undefined1 param_1)

{
  x86emuOp_esc_coprocess_d9(param_1);
  return;
}


// ===== 0027caf0 x86emuOp_esc_coprocess_de =====

void x86emuOp_esc_coprocess_de(undefined1 param_1)

{
  x86emuOp_esc_coprocess_d9(param_1);
  return;
}


// ===== 0027cb00 x86emuOp_esc_coprocess_df =====

void x86emuOp_esc_coprocess_df(undefined1 param_1)

{
  x86emuOp_esc_coprocess_d9(param_1);
  return;
}


// ===== 0027cb10 x86emuOp_two_byte =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_two_byte(void)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_005483f8;
  DAT_005483f8 = DAT_005483f8 + 1;
  bVar1 = (*(code *)sys_rdb)(uVar2 + (uint)DAT_00548400 * 0x10);
  (**(code **)(x86emu_optab2 + (ulong)bVar1 * 8))(bVar1);
  return;
}


// ===== 0027cb60 x86emuOp_segovr_ES =====

void x86emuOp_segovr_ES(void)

{
  DAT_0054840c = DAT_0054840c | 8;
  return;
}


// ===== 0027cb70 x86emuOp_segovr_CS =====

void x86emuOp_segovr_CS(void)

{
  DAT_0054840c = DAT_0054840c | 2;
  return;
}


// ===== 0027cb80 x86emuOp_segovr_SS =====

void x86emuOp_segovr_SS(void)

{
  DAT_0054840c = DAT_0054840c | 0x40;
  return;
}


// ===== 0027cb90 x86emuOp_segovr_DS =====

void x86emuOp_segovr_DS(void)

{
  DAT_0054840c = DAT_0054840c | 4;
  return;
}


// ===== 0027cba0 x86emuOp_segovr_FS =====

void x86emuOp_segovr_FS(void)

{
  DAT_0054840c = DAT_0054840c | 0x10;
  return;
}


// ===== 0027cbb0 x86emuOp_segovr_GS =====

void x86emuOp_segovr_GS(void)

{
  DAT_0054840c = DAT_0054840c | 0x20;
  return;
}


// ===== 0027cbc0 x86emuOp_prefix_data =====

void x86emuOp_prefix_data(void)

{
  DAT_0054840c = DAT_0054840c | 0x200;
  return;
}


// ===== 0027cbd0 x86emuOp_prefix_addr =====

void x86emuOp_prefix_addr(void)

{
  DAT_0054840c = DAT_0054840c | 0x400;
  return;
}


// ===== 0027cbe0 x86emuOp_nop =====

void x86emuOp_nop(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027cbf0 x86emuOp_xchg_word_AX_CX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_CX(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = DAT_005483e0;
    DAT_005483e0 = uVar2;
    return;
  }
  uVar1 = (undefined2)_DAT_005483d8;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,(short)DAT_005483e0);
  DAT_005483e0 = CONCAT22(DAT_005483e0._2_2_,uVar1);
  return;
}


// ===== 0027cc50 x86emuOp_xchg_word_AX_DX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_DX(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = DAT_005483e4;
    DAT_005483e4 = uVar2;
    return;
  }
  uVar1 = (undefined2)_DAT_005483d8;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,(short)DAT_005483e4);
  DAT_005483e4 = CONCAT22(DAT_005483e4._2_2_,uVar1);
  return;
}


// ===== 0027ccb0 x86emuOp_xchg_word_AX_BX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_BX(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = CONCAT44(_DAT_005483d8,_DAT_005483dc);
    return;
  }
  uVar1 = DAT_005483d8;
  uVar4 = DAT_005483dc;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT62(DAT_005483d8_2,uVar4);
  uVar3 = _DAT_005483d8;
  DAT_005483d8_2._4_2_ = SUB82(uVar2,6);
  _DAT_005483d8 = (undefined4)uVar3;
  _DAT_005483d8 = CONCAT24(uVar1,_DAT_005483d8);
  return;
}


// ===== 0027cd10 x86emuOp_xchg_word_AX_SP =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_SP(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = DAT_005483e8;
    DAT_005483e8 = uVar2;
    return;
  }
  uVar1 = (undefined2)_DAT_005483d8;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,(short)DAT_005483e8);
  DAT_005483e8 = CONCAT22(DAT_005483e8._2_2_,uVar1);
  return;
}


// ===== 0027cd70 x86emuOp_xchg_word_AX_BP =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_BP(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = DAT_005483ec;
    DAT_005483ec = uVar2;
    return;
  }
  uVar1 = (undefined2)_DAT_005483d8;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,(short)DAT_005483ec);
  DAT_005483ec = CONCAT22(DAT_005483ec._2_2_,uVar1);
  return;
}


// ===== 0027cdd0 x86emuOp_xchg_word_AX_SI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_SI(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = _DAT_005483f0;
    _DAT_005483f0 = uVar2;
    return;
  }
  uVar1 = (undefined2)_DAT_005483d8;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,(short)_DAT_005483f0);
  _DAT_005483f0 = CONCAT22(DAT_005483f0_2,uVar1);
  return;
}


// ===== 0027ce30 x86emuOp_xchg_word_AX_DI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xchg_word_AX_DI(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_005483d8;
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = _DAT_005483f4;
    _DAT_005483f4 = uVar2;
    return;
  }
  uVar1 = (undefined2)_DAT_005483d8;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,(short)_DAT_005483f4);
  _DAT_005483f4 = CONCAT22(DAT_005483f4_2,uVar1);
  return;
}


// ===== 0027ce90 x86emuOp_cbw =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_cbw(void)

{
  uint uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    uVar1 = _DAT_005483d8 | 0xffff0000;
    if (-1 < DAT_005483d8) {
      uVar1 = _DAT_005483d8 & 0xffff;
    }
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    _DAT_005483d8 = uVar1;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483d8 = (short)(char)DAT_005483d8;
  return;
}


// ===== 0027cef0 x86emuOp_cwd =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_cwd(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    DAT_005483e4 = _DAT_005483d8 >> 0x1f;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e4 = CONCAT22(DAT_005483e4._2_2_,(short)_DAT_005483d8 >> 0xf);
  return;
}


// ===== 0027cf40 x86emuOp_sahf =====

void x86emuOp_sahf(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483fc._0_1_ = DAT_005483d8._1_1_;
  return;
}


// ===== 0027cf60 x86emuOp_lahf =====

void x86emuOp_lahf(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483d8._1_1_ = (byte)DAT_005483fc | 2;
  return;
}


// ===== 0027cf80 x86emuOp_in_byte_AL_DX =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_in_byte_AL_DX(void)

{
  DAT_005483d8._0_1_ = (*(code *)sys_inb)((undefined2)DAT_005483e4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027cfb0 x86emuOp_in_word_AX_DX =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_in_word_AX_DX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = (*(code *)sys_inl)();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = (*(code *)sys_inw)((undefined2)DAT_005483e4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 0027d010 x86emuOp_out_byte_DX_AL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_out_byte_DX_AL(void)

{
  (*(code *)sys_outb)((undefined2)DAT_005483e4,(undefined1)DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d040 x86emuOp_out_word_DX_AX =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_out_word_DX_AX(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    (*(code *)sys_outl)((undefined2)DAT_005483e4,_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  (*(code *)sys_outw)((undefined2)DAT_005483e4,_DAT_005483d8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d0a0 x86emuOp_repne =====

void x86emuOp_repne(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980 | 0x100;
  return;
}


// ===== 0027d0c0 x86emuOp_repe =====

void x86emuOp_repe(void)

{
  DAT_0054840c = (int)CONCAT71((uint7)((uint3)((uint)DAT_0054840c >> 8) & 0xfffff9),0x80);
  return;
}


// ===== 0027d0e0 x86emuOp_cmc =====

void x86emuOp_cmc(void)

{
  DAT_005483fc = DAT_005483fc ^ 1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d100 x86emuOp_clc =====

void x86emuOp_clc(void)

{
  DAT_005483fc = DAT_005483fc & 0xfffffffe;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d120 x86emuOp_stc =====

void x86emuOp_stc(void)

{
  DAT_005483fc = DAT_005483fc | 1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d140 x86emuOp_cli =====

void x86emuOp_cli(void)

{
  DAT_005483fc = DAT_005483fc & 0xfffffdff;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d160 x86emuOp_sti =====

void x86emuOp_sti(void)

{
  DAT_005483fc = DAT_005483fc | 0x200;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d180 x86emuOp_cld =====

void x86emuOp_cld(void)

{
  DAT_005483fc = DAT_005483fc & 0xfffffbff;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d1a0 x86emuOp_std =====

void x86emuOp_std(void)

{
  DAT_005483fc = DAT_005483fc | 0x400;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d1c0 x86emuOp_lods_word =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_lods_word(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  
  uVar1 = -(ushort)((DAT_005483fc & 0x400) == 0);
  if ((DAT_0054840c & 0x200) == 0) {
    sVar5 = (uVar1 & 4) - 2;
  }
  else {
    sVar5 = (uVar1 & 8) - 4;
  }
  iVar4 = 0;
  if ((DAT_0054840c & 0x180) != 0) {
    uVar3 = (uint)(ushort)DAT_005483e0;
    DAT_0054840c = DAT_0054840c & 0xfffffe7f;
    DAT_005483e0._0_2_ = 0;
    if (uVar3 == 0) goto LAB_0027d270;
    iVar4 = uVar3 - 1;
  }
  do {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = fetch_data_word();
      _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar2);
    }
    else {
      _DAT_005483d8 = fetch_data_long(DAT_005483f0);
    }
    iVar4 = iVar4 + -1;
    DAT_005483f0 = DAT_005483f0 + sVar5;
  } while (iVar4 != -1);
LAB_0027d270:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d290 x86emuOp_inc_DI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_inc_DI(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f4 = inc_long(_DAT_005483f4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(_DAT_005483f4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483f4 = CONCAT22(DAT_005483f4_2,uVar1);
  return;
}


// ===== 0027d2e0 x86emuOp_inc_SI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_inc_SI(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f0 = inc_long(_DAT_005483f0);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(_DAT_005483f0 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483f0 = CONCAT22(DAT_005483f0_2,uVar1);
  return;
}


// ===== 0027d330 x86emuOp_inc_BP =====

void x86emuOp_inc_BP(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483ec = inc_long(DAT_005483ec);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(DAT_005483ec & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483ec = CONCAT22(DAT_005483ec._2_2_,uVar1);
  return;
}


// ===== 0027d380 x86emuOp_inc_SP =====

void x86emuOp_inc_SP(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e8 = inc_long(DAT_005483e8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(DAT_005483e8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e8 = CONCAT22(DAT_005483e8._2_2_,uVar1);
  return;
}


// ===== 0027d3d0 x86emuOp_inc_BX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_inc_BX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483dc = inc_long(_DAT_005483dc);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(_DAT_005483dc & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483dc = CONCAT22(DAT_005483dc_2,uVar1);
  return;
}


// ===== 0027d420 x86emuOp_inc_DX =====

void x86emuOp_inc_DX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e4 = inc_long(DAT_005483e4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(DAT_005483e4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e4 = CONCAT22(DAT_005483e4._2_2_,uVar1);
  return;
}


// ===== 0027d470 x86emuOp_inc_CX =====

void x86emuOp_inc_CX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e0 = inc_long(DAT_005483e0);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(DAT_005483e0 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e0 = CONCAT22(DAT_005483e0._2_2_,uVar1);
  return;
}


// ===== 0027d4c0 x86emuOp_inc_AX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_inc_AX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = inc_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = inc_word(_DAT_005483d8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 0027d510 x86emuOp_dec_DI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_dec_DI(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f4 = dec_long(_DAT_005483f4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(_DAT_005483f4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483f4 = CONCAT22(DAT_005483f4_2,uVar1);
  return;
}


// ===== 0027d560 x86emuOp_dec_SI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_dec_SI(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f0 = dec_long(_DAT_005483f0);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(_DAT_005483f0 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483f0 = CONCAT22(DAT_005483f0_2,uVar1);
  return;
}


// ===== 0027d5b0 x86emuOp_dec_BP =====

void x86emuOp_dec_BP(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483ec = dec_long(DAT_005483ec);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(DAT_005483ec & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483ec = CONCAT22(DAT_005483ec._2_2_,uVar1);
  return;
}


// ===== 0027d600 x86emuOp_dec_SP =====

void x86emuOp_dec_SP(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e8 = dec_long(DAT_005483e8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(DAT_005483e8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e8 = CONCAT22(DAT_005483e8._2_2_,uVar1);
  return;
}


// ===== 0027d650 x86emuOp_dec_BX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_dec_BX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483dc = dec_long(_DAT_005483dc);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(_DAT_005483dc & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483dc = CONCAT22(DAT_005483dc_2,uVar1);
  return;
}


// ===== 0027d6a0 x86emuOp_dec_DX =====

void x86emuOp_dec_DX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e4 = dec_long(DAT_005483e4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(DAT_005483e4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e4 = CONCAT22(DAT_005483e4._2_2_,uVar1);
  return;
}


// ===== 0027d6f0 x86emuOp_dec_CX =====

void x86emuOp_dec_CX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e0 = dec_long(DAT_005483e0);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(DAT_005483e0 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e0 = CONCAT22(DAT_005483e0._2_2_,uVar1);
  return;
}


// ===== 0027d740 x86emuOp_dec_AX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_dec_AX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = dec_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = dec_word(_DAT_005483d8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 0027d790 x86emuOp_push_DS =====

void x86emuOp_push_DS(void)

{
  push_word(DAT_00548402);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d7b0 x86emuOp_push_SS =====

void x86emuOp_push_SS(void)

{
  push_word(DAT_00548404);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d7d0 x86emuOp_push_CS =====

void x86emuOp_push_CS(void)

{
  push_word(DAT_00548400);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d7f0 x86emuOp_push_ES =====

void x86emuOp_push_ES(void)

{
  push_word(DAT_00548406);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d810 x86emuOp_pushf_word =====

void x86emuOp_pushf_word(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word((ushort)DAT_005483fc & 0xfd5 | 2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d860 x86emuOp_push_all =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_push_all(void)

{
  uint uVar1;
  
  uVar1 = DAT_005483e8;
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(_DAT_005483d8);
    push_long(DAT_005483e0);
    push_long(DAT_005483e4);
    push_long(_DAT_005483dc);
    push_long(uVar1);
    push_long(DAT_005483ec);
    push_long(_DAT_005483f0);
    push_long(_DAT_005483f4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = DAT_005483e8 & 0xffff;
  push_word(_DAT_005483d8 & 0xffff);
  push_word(DAT_005483e0 & 0xffff);
  push_word(DAT_005483e4 & 0xffff);
  push_word(_DAT_005483dc & 0xffff);
  push_word(uVar1);
  push_word(DAT_005483ec & 0xffff);
  push_word(_DAT_005483f0 & 0xffff);
  push_word(_DAT_005483f4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d960 x86emuOp_push_DI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_push_DI(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(_DAT_005483f4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(_DAT_005483f4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027d9b0 x86emuOp_push_SI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_push_SI(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(_DAT_005483f0);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(_DAT_005483f0 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027da00 x86emuOp_push_BP =====

void x86emuOp_push_BP(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(DAT_005483ec);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(DAT_005483ec & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027da50 x86emuOp_push_SP =====

void x86emuOp_push_SP(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(DAT_005483e8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(DAT_005483e8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027daa0 x86emuOp_push_BX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_push_BX(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(_DAT_005483dc);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(_DAT_005483dc & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027daf0 x86emuOp_push_DX =====

void x86emuOp_push_DX(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(DAT_005483e4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(DAT_005483e4 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027db40 x86emuOp_push_CX =====

void x86emuOp_push_CX(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(DAT_005483e0);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(DAT_005483e0 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027db90 x86emuOp_push_AX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_push_AX(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    push_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(_DAT_005483d8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027dbe0 x86emuOp_opcD3_word_RM_CL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opcD3_word_RM_CL(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  int local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  uVar1 = (undefined1)DAT_005483e0;
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_0027dce5;
    }
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          uVar2 = (**(code **)(opcD1_word_operation + (long)local_1c[0] * 8))(*puVar6,uVar1);
          *puVar6 = uVar2;
        }
        else {
          puVar5 = (undefined4 *)decode_rm_long_register();
          uVar3 = (**(code **)(opcD1_long_operation + (long)local_1c[0] * 8))(*puVar5,uVar1);
          *puVar5 = uVar3;
        }
      }
      goto LAB_0027dc74;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_0027dce5:
        uVar2 = fetch_data_word(uVar3);
        uVar2 = (**(code **)(opcD1_word_operation + (long)local_1c[0] * 8))(uVar2,uVar1);
        store_data_word(uVar3,uVar2);
        goto LAB_0027dc74;
      }
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027dc74;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_0027dce5;
      }
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar4 = fetch_data_long(uVar3);
  uVar4 = (**(code **)(opcD1_long_operation + (long)local_1c[0] * 8))(uVar4,uVar1);
  store_data_long(uVar3,uVar4);
LAB_0027dc74:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027dd80 x86emuOp_opcD1_word_RM_1 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opcD1_word_RM_1(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int local_14;
  undefined4 local_10;
  int local_c;
  
  fetch_decode_modrm(&local_14,&local_c,&local_10);
  if (local_14 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_10);
      goto LAB_0027de8d;
    }
    uVar2 = decode_rm10_address(local_10);
  }
  else {
    if (2 < local_14) {
      if (local_14 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar5 = (undefined2 *)decode_rm_word_register(local_10);
          uVar1 = (**(code **)(opcD1_word_operation + (long)local_c * 8))(*puVar5,1);
          *puVar5 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar4 = (undefined4 *)decode_rm_long_register();
        uVar2 = (**(code **)(opcD1_long_operation + (long)local_c * 8))(*puVar4,1);
        *puVar4 = uVar2;
      }
LAB_0027de0e:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_14 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_10);
LAB_0027de8d:
        uVar1 = fetch_data_word(uVar2);
        uVar1 = (**(code **)(opcD1_word_operation + (long)local_c * 8))(uVar1,1);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_10);
    }
    else {
      if (local_14 != 1) goto LAB_0027de0e;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_10);
        goto LAB_0027de8d;
      }
      uVar2 = decode_rm01_address(local_10);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  uVar3 = (**(code **)(opcD1_long_operation + (long)local_c * 8))(uVar3,1);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027df30 x86emuOp_lds_R_IMM =====

void x86emuOp_lds_R_IMM(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,&local_20,local_1c);
  if (local_24 == 1) {
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm01_address(local_1c[0]);
  }
  else if (local_24 == 2) {
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm10_address(local_1c[0]);
  }
  else {
    if (local_24 != 0) goto LAB_0027df98;
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm00_address(local_1c[0]);
  }
  uVar1 = fetch_data_word(iVar2);
  *puVar3 = uVar1;
  DAT_00548402 = fetch_data_word(iVar2 + 2);
LAB_0027df98:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027dff0 x86emuOp_les_R_IMM =====

void x86emuOp_les_R_IMM(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,&local_20,local_1c);
  if (local_24 == 1) {
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm01_address(local_1c[0]);
  }
  else if (local_24 == 2) {
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm10_address(local_1c[0]);
  }
  else {
    if (local_24 != 0) goto LAB_0027e058;
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm00_address(local_1c[0]);
  }
  uVar1 = fetch_data_word(iVar2);
  *puVar3 = uVar1;
  DAT_00548406 = fetch_data_word(iVar2 + 2);
LAB_0027e058:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027e0b0 x86emuOp_lea_word_R_M =====

void x86emuOp_lea_word_R_M(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 1) {
    if ((DAT_0054840c & 0x400) != 0) {
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
      *puVar3 = uVar2;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    puVar4 = (undefined2 *)decode_rm_word_register(local_1c[0]);
    uVar1 = decode_rm01_address(local_20);
    *puVar4 = uVar1;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_24 != 2) {
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x400) == 0) {
        puVar4 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = decode_rm00_address(local_20);
        *puVar4 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
      *puVar3 = uVar2;
    }
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if ((DAT_0054840c & 0x400) != 0) {
    puVar3 = (undefined4 *)decode_rm_long_register();
    uVar2 = decode_rm10_address(local_20);
    *puVar3 = uVar2;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  puVar4 = (undefined2 *)decode_rm_word_register(local_1c[0]);
  uVar1 = decode_rm10_address(local_20);
  *puVar4 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027e230 x86emuOp_mov_word_R_RM =====

void x86emuOp_mov_word_R_RM(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
      uVar2 = decode_rm10_address(local_20);
      goto LAB_0027e348;
    }
    puVar3 = (undefined4 *)decode_rm_long_register();
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          *puVar5 = *puVar6;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        *puVar3 = *puVar4;
      }
LAB_0027e2c3:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
LAB_0027e348:
        uVar1 = fetch_data_word(uVar2);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027e2c3;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        goto LAB_0027e348;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027e3d0 x86emuOp_mov_word_RM_R =====

void x86emuOp_mov_word_RM_R(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar1 = decode_rm10_address(local_20);
      goto LAB_0027e4c5;
    }
    uVar1 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar4 = (undefined2 *)decode_rm_word_register(local_20);
          puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          *puVar4 = *puVar5;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar2 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        *puVar3 = *puVar2;
      }
LAB_0027e453:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar1 = decode_rm00_address(local_20);
LAB_0027e4c5:
        puVar4 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        store_data_word(uVar1,*puVar4);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar1 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027e453;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar1 = decode_rm01_address(local_20);
        goto LAB_0027e4c5;
      }
      uVar1 = decode_rm01_address(local_20);
    }
  }
  puVar3 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  store_data_long(uVar1,*puVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027e540 x86emuOp_xchg_word_RM_R =====

void x86emuOp_xchg_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar4 = decode_rm10_address(local_20);
      goto LAB_0027e645;
    }
    uVar4 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar8 = (undefined2 *)decode_rm_word_register(local_20);
          puVar9 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = *puVar9;
          *puVar9 = *puVar8;
          *puVar8 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar7 = (undefined4 *)decode_rm_long_register();
        puVar6 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar4 = *puVar6;
        *puVar6 = *puVar7;
        *puVar7 = uVar4;
      }
LAB_0027e5c4:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar4 = decode_rm00_address(local_20);
LAB_0027e645:
        uVar3 = fetch_data_word(uVar4);
        puVar8 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = *puVar8;
        *puVar8 = uVar3;
        store_data_word(uVar4,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar4 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027e5c4;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar4 = decode_rm01_address(local_20);
        goto LAB_0027e645;
      }
      uVar4 = decode_rm01_address(local_20);
    }
  }
  uVar5 = fetch_data_long(uVar4);
  puVar7 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar2 = *puVar7;
  *puVar7 = uVar5;
  store_data_long(uVar4,uVar2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027e6e0 x86emuOp_opcFF_word_RM =====

void x86emuOp_opcFF_word_RM(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_24;
  uint local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,&local_20,local_1c);
  if (local_24 == 2) {
    iVar3 = decode_rm10_address(local_1c[0]);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if (local_20 == 4) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          DAT_005483f8 = *puVar6;
        }
        else {
          if ((int)local_20 < 5) {
            if (local_20 == 2) {
              puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
              push_word(DAT_005483f8);
              DAT_005483f8 = *puVar6;
              goto LAB_0027e772;
            }
            if (local_20 != 3) {
              if (local_20 == 0) {
                if ((DAT_0054840c & 0x200) == 0) {
                  puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
                  uVar2 = inc_word(*puVar6);
                  *puVar6 = uVar2;
                }
                else {
                  puVar5 = (undefined4 *)decode_rm_long_register();
                  uVar4 = inc_long(*puVar5);
                  *puVar5 = uVar4;
                }
              }
              else if (local_20 == 1) {
                if ((DAT_0054840c & 0x200) == 0) {
                  puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
                  uVar2 = dec_word(*puVar6);
                  *puVar6 = uVar2;
                }
                else {
                  puVar5 = (undefined4 *)decode_rm_long_register();
                  uVar4 = dec_long(*puVar5);
                  *puVar5 = uVar4;
                }
              }
              goto LAB_0027e772;
            }
          }
          else {
            if (local_20 == 6) {
              if ((DAT_0054840c & 0x200) == 0) {
                puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
                push_word(*puVar6);
              }
              else {
                puVar5 = (undefined4 *)decode_rm_long_register();
                push_long(*puVar5);
              }
              goto LAB_0027e772;
            }
            if ((local_20 & 0xfffffffd) != 5) goto LAB_0027e772;
          }
          X86EMU_halt_sys();
        }
      }
      goto LAB_0027e772;
    }
    if (local_24 == 0) {
      iVar3 = decode_rm00_address(local_1c[0]);
    }
    else {
      if (local_24 != 1) goto LAB_0027e772;
      iVar3 = decode_rm01_address(local_1c[0]);
    }
  }
  if (local_20 == 3) {
    uVar2 = fetch_data_word(iVar3);
    uVar1 = fetch_data_word(iVar3 + 2);
    push_word(DAT_00548400);
    DAT_00548400 = uVar1;
    push_word(DAT_005483f8);
    DAT_005483f8 = uVar2;
  }
  else if ((int)local_20 < 3) {
    if (local_20 == 1) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = fetch_data_word(iVar3);
        uVar2 = dec_word(uVar2);
        store_data_word(iVar3,uVar2);
      }
      else {
        uVar4 = fetch_data_long();
        uVar4 = dec_long(uVar4);
        store_data_long(iVar3,uVar4);
      }
    }
    else if (local_20 == 2) {
      uVar2 = fetch_data_word(iVar3);
      push_word(DAT_005483f8);
      DAT_005483f8 = uVar2;
    }
    else if (local_20 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = fetch_data_word(iVar3);
        uVar2 = inc_word(uVar2);
        store_data_word(iVar3,uVar2);
      }
      else {
        uVar4 = fetch_data_long();
        uVar4 = inc_long(uVar4);
        store_data_long(iVar3,uVar4);
      }
    }
  }
  else if (local_20 == 5) {
    uVar2 = fetch_data_word(iVar3);
    DAT_00548400 = fetch_data_word(iVar3 + 2);
    DAT_005483f8 = uVar2;
  }
  else if (local_20 == 6) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = fetch_data_word(iVar3);
      push_word(uVar2);
    }
    else {
      uVar4 = fetch_data_long();
      push_long(uVar4);
    }
  }
  else if (local_20 == 4) {
    DAT_005483f8 = fetch_data_word(iVar3);
  }
LAB_0027e772:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027ead0 x86emuOp_halt =====

void x86emuOp_halt(void)

{
  X86EMU_halt_sys();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027eaf0 x86emuOp_illegal_op =====

void x86emuOp_illegal_op(void)

{
  X86EMU_halt_sys();
  return;
}


// ===== 0027eb00 x86emuOp_xlat =====

void x86emuOp_xlat(void)

{
  DAT_005483d8._0_1_ = fetch_data_byte((ushort)(byte)DAT_005483d8 + DAT_005483dc);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027eb30 x86emuOp_lods_byte =====

void x86emuOp_lods_byte(void)

{
  ushort uVar1;
  
  uVar1 = -(ushort)((DAT_005483fc & 0x400) != 0) | 1;
  if ((DAT_0054840c & 0x180) == 0) {
    DAT_005483d8._0_1_ = fetch_data_byte(DAT_005483f0);
    DAT_005483f0 = DAT_005483f0 + uVar1;
  }
  else {
    if ((short)DAT_005483e0 != 0) {
      do {
        DAT_005483d8._0_1_ = fetch_data_byte(DAT_005483f0);
        DAT_005483f0 = DAT_005483f0 + uVar1;
        DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
      } while ((short)DAT_005483e0 != 0);
      DAT_005483e0._0_2_ = 0;
    }
    DAT_0054840c = DAT_0054840c & 0xfffffe7f;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027ebf0 x86emuOp_opcFE_byte_RM =====

void x86emuOp_opcFE_byte_RM(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  fetch_decode_modrm(&local_14,&local_10,&local_c);
  if (local_14 == 2) {
    uVar2 = decode_rm10_address(local_c);
  }
  else {
    if (2 < local_14) {
      if (local_14 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_c);
        if (local_10 == 0) {
          uVar1 = inc_byte(*puVar3);
          *puVar3 = uVar1;
        }
        else if (local_10 == 1) {
          uVar1 = dec_byte(*puVar3);
          *puVar3 = uVar1;
        }
      }
      goto LAB_0027ec5b;
    }
    if (local_14 == 0) {
      uVar2 = decode_rm00_address(local_c);
    }
    else {
      if (local_14 != 1) goto LAB_0027ec5b;
      uVar2 = decode_rm01_address(local_c);
    }
  }
  if (local_10 == 0) {
    uVar1 = fetch_data_byte(uVar2);
    uVar1 = inc_byte(uVar1);
    store_data_byte(uVar2,uVar1);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_10 == 1) {
    uVar1 = fetch_data_byte(uVar2);
    uVar1 = dec_byte(uVar1);
    store_data_byte(uVar2,uVar1);
  }
LAB_0027ec5b:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027ed20 x86emuOp_opcD2_byte_RM_CL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opcD2_byte_RM_CL(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int local_24;
  undefined4 local_20;
  int local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  uVar2 = (undefined1)DAT_005483e0;
  if (local_24 == 2) {
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar2 = (**(code **)(opcD0_byte_operation + (long)local_1c[0] * 8))(*puVar4,uVar2);
        *puVar4 = uVar2;
      }
LAB_0027edd6:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027edd6;
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar3);
  uVar2 = (**(code **)(opcD0_byte_operation + (long)local_1c[0] * 8))(uVar1,uVar2);
  store_data_byte(uVar3,uVar2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027ee10 x86emuOp_opcD0_byte_RM_1 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opcD0_byte_RM_1(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int local_14;
  undefined4 local_10;
  int local_c;
  
  fetch_decode_modrm(&local_14,&local_c,&local_10);
  if (local_14 == 2) {
    uVar2 = decode_rm10_address(local_10);
  }
  else {
    if (2 < local_14) {
      if (local_14 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_10);
        uVar1 = (**(code **)(opcD0_byte_operation + (long)local_c * 8))(*puVar3,1);
        *puVar3 = uVar1;
      }
LAB_0027eec0:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_14 == 0) {
      uVar2 = decode_rm00_address(local_10);
    }
    else {
      if (local_14 != 1) goto LAB_0027eec0;
      uVar2 = decode_rm01_address(local_10);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = (**(code **)(opcD0_byte_operation + (long)local_c * 8))(uVar1,1);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027eef0 x86emuOp_mov_byte_R_RM =====

void x86emuOp_mov_byte_R_RM(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
    uVar2 = decode_rm10_address(local_20);
    uVar1 = fetch_data_byte(uVar2);
    *puVar3 = uVar1;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_24 < 3) {
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
      uVar1 = fetch_data_byte(uVar2);
      *puVar3 = uVar1;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 1) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
      uVar1 = fetch_data_byte(uVar2);
      *puVar3 = uVar1;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
  }
  else if (local_24 == 3) {
    puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
    puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
    *puVar3 = *puVar4;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027eff0 x86emuOp_mov_byte_RM_R =====

void x86emuOp_mov_byte_RM_R(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    uVar1 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar2 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        *puVar2 = *puVar3;
      }
LAB_0027f07d:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar1 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027f07d;
      uVar1 = decode_rm01_address(local_20);
    }
  }
  puVar2 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  store_data_byte(uVar1,*puVar2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f0b0 x86emuOp_xchg_byte_RM_R =====

void x86emuOp_xchg_byte_RM_R(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar5 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = *puVar5;
        *puVar5 = *puVar4;
        *puVar4 = uVar1;
      }
LAB_0027f150:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027f150;
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_byte(uVar3);
  puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = *puVar4;
  *puVar4 = uVar2;
  store_data_byte(uVar3,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f190 x86emuOp_jump_far_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_jump_far_IMM(void)

{
  ushort uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  DAT_00548400 = fetch_word_imm();
  _DAT_005483f8 = (uint)uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f1e0 x86emuOp_jump_near_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_jump_near_IMM(void)

{
  short sVar1;
  int iVar2;
  
  if ((DAT_0054840c & 0x200) != 0) {
    iVar2 = fetch_long_imm();
    _DAT_005483f8 = _DAT_005483f8 + iVar2;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  sVar1 = fetch_word_imm();
  DAT_005483f8 = DAT_005483f8 + sVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f230 x86emuOp_call_near_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_call_near_IMM(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    sVar1 = fetch_word_imm();
    uVar3 = 0;
    sVar1 = sVar1 + DAT_005483f8;
  }
  else {
    iVar2 = fetch_long_imm();
    uVar3 = DAT_005483f8 + iVar2;
    sVar1 = 0;
  }
  if ((DAT_0054840c & 0x200) == 0) {
    push_word(_DAT_005483f8 & 0xffff);
    _DAT_005483f8 = (uint)sVar1;
  }
  else {
    push_long(_DAT_005483f8);
    _DAT_005483f8 = uVar3 & 0xffff;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f2c0 x86emuOp_mov_word_RM_IMM =====

void x86emuOp_mov_word_RM_IMM(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  int local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_1c[0] == 0) {
    iVar1 = local_24 + -2;
    if (local_24 == 2) {
LAB_0027f377:
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm10_address(local_20);
        goto LAB_0027f3cd;
      }
      uVar3 = decode_rm10_address(local_20);
      goto LAB_0027f388;
    }
  }
  else {
    X86EMU_halt_sys();
    iVar1 = local_24 + -2;
    if (iVar1 == 0) goto LAB_0027f377;
  }
  if (SBORROW4(local_24,2) != iVar1 < 0) {
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_0027f3cd:
        uVar2 = fetch_word_imm();
        store_data_word(uVar3,uVar2);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027f34e;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_0027f3cd;
      }
      uVar3 = decode_rm01_address(local_20);
    }
LAB_0027f388:
    uVar4 = fetch_long_imm();
    store_data_long(uVar3,uVar4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_24 == 3) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar6 = (undefined2 *)decode_rm_word_register(local_20);
      uVar2 = fetch_word_imm();
      *puVar6 = uVar2;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    puVar5 = (undefined4 *)decode_rm_long_register();
    uVar3 = fetch_long_imm();
    *puVar5 = uVar3;
  }
LAB_0027f34e:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f440 x86emuOp_mov_word_DI_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_mov_word_DI_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f4 = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = _DAT_005483f4 >> 0x10;
  _DAT_005483f4 = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f4a0 x86emuOp_mov_word_SI_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_mov_word_SI_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f0 = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = _DAT_005483f0 >> 0x10;
  _DAT_005483f0 = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f500 x86emuOp_mov_word_BP_IMM =====

void x86emuOp_mov_word_BP_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483ec = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = DAT_005483ec >> 0x10;
  DAT_005483ec = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f560 x86emuOp_mov_word_SP_IMM =====

void x86emuOp_mov_word_SP_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e8 = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = DAT_005483e8 >> 0x10;
  DAT_005483e8 = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f5c0 x86emuOp_mov_word_BX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_mov_word_BX_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483dc = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = _DAT_005483dc >> 0x10;
  _DAT_005483dc = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f620 x86emuOp_mov_word_DX_IMM =====

void x86emuOp_mov_word_DX_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e4 = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = DAT_005483e4 >> 0x10;
  DAT_005483e4 = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f680 x86emuOp_mov_word_CX_IMM =====

void x86emuOp_mov_word_CX_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e0 = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = DAT_005483e0 >> 0x10;
  DAT_005483e0 = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f6e0 x86emuOp_mov_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_mov_word_AX_IMM(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar3 = (uint)uVar2;
  }
  else {
    uVar3 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = uVar3;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = _DAT_005483d8 >> 0x10;
  _DAT_005483d8 = CONCAT22((short)uVar1,(short)uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f740 x86emuOp_mov_M_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_mov_M_AX_IMM(void)

{
  undefined2 uVar1;
  
  uVar1 = fetch_word_imm();
  if ((DAT_0054840c & 0x200) != 0) {
    store_data_long(uVar1,_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  store_data_word(uVar1,_DAT_005483d8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f790 x86emuOp_mov_M_AL_IMM =====

void x86emuOp_mov_M_AL_IMM(void)

{
  undefined2 uVar1;
  
  uVar1 = fetch_word_imm();
  store_data_byte(uVar1,(undefined1)DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f7c0 x86emuOp_mov_AX_M_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_mov_AX_M_IMM(void)

{
  undefined2 uVar1;
  
  uVar1 = fetch_word_imm();
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = fetch_data_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = fetch_data_word(uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 0027f810 x86emuOp_mov_AL_M_IMM =====

void x86emuOp_mov_AL_M_IMM(void)

{
  undefined2 uVar1;
  
  uVar1 = fetch_word_imm();
  DAT_005483d8._0_1_ = fetch_data_byte(uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f840 x86emuOp_call_far_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_call_far_IMM(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar2 = fetch_word_imm();
    uVar1 = fetch_word_imm();
  }
  else {
    uVar2 = fetch_long_imm();
    uVar1 = fetch_word_imm();
  }
  push_word(DAT_00548400);
  DAT_00548400 = uVar1;
  if ((DAT_0054840c & 0x200) == 0) {
    push_word(_DAT_005483f8 & 0xffff);
  }
  else {
    push_long(_DAT_005483f8);
  }
  _DAT_005483f8 = uVar2 & 0xffff;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027f8d0 x86emuOp_opc81_word_RM_IMM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opc81_word_RM_IMM(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_0027fa35;
    }
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar7 = (undefined2 *)decode_rm_word_register(local_20);
          uVar1 = fetch_word_imm();
          uVar1 = (**(code **)(opc83_word_operation + (long)local_1c * 8))(*puVar7,uVar1);
          if (local_1c != 7) {
            *puVar7 = uVar1;
          }
        }
        else {
          puVar6 = (undefined4 *)decode_rm_long_register();
          uVar3 = fetch_long_imm();
          uVar3 = (**(code **)(opc83_long_operation + (long)local_1c * 8))(*puVar6,uVar3);
          if (local_1c != 7) {
            *puVar6 = uVar3;
          }
        }
      }
LAB_0027f985:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_0027fa35:
        uVar1 = fetch_data_word(uVar3);
        uVar2 = fetch_word_imm();
        uVar1 = (**(code **)(opc83_word_operation + (long)local_1c * 8))(uVar1,uVar2);
        if (local_1c != 7) {
          store_data_word(uVar3,uVar1);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        goto LAB_0027faf8;
      }
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027f985;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_0027fa35;
      }
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar4 = fetch_data_long(uVar3);
  uVar5 = fetch_long_imm();
  uVar4 = (**(code **)(opc83_long_operation + (long)local_1c * 8))(uVar4,uVar5);
  if (local_1c != 7) {
    store_data_long(uVar3,uVar4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
LAB_0027faf8:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027fb20 x86emuOp_push_word_IMM =====

void x86emuOp_push_word_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    push_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027fb80 x86emuOp_test_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_test_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    test_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  test_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027fbf0 x86emuOp_test_word_RM_R =====

void x86emuOp_test_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_0027fced;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar5 = (undefined2 *)decode_rm_word_register(local_20);
          puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          test_word(*puVar5,*puVar6);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar4 = (undefined4 *)decode_rm_long_register();
        puVar3 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        test_long(*puVar4,*puVar3);
      }
LAB_0027fc78:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_0027fced:
        uVar1 = fetch_data_word(uVar2);
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        test_word(uVar1,*puVar5);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0027fc78;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_0027fced;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  test_long(uVar2,*puVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 0027fd80 x86emuOp_opcF7_word_RM =====

void x86emuOp_opcF7_word_RM(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    if (local_1c == 4) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm10_address(local_20);
        uVar1 = fetch_data_word(uVar3);
        mul_word(uVar1);
      }
      else {
        uVar3 = decode_rm10_address(local_20);
        uVar3 = fetch_data_long(uVar3);
        mul_long(uVar3);
      }
      goto LAB_0027fe24;
    }
    if (4 < local_1c) {
      if (local_1c == 6) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm10_address(local_20);
          uVar1 = fetch_data_word(uVar3);
          div_word(uVar1);
        }
        else {
          uVar3 = decode_rm10_address(local_20);
          uVar3 = fetch_data_long(uVar3);
          div_long(uVar3);
        }
      }
      else if (local_1c == 7) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm10_address(local_20);
          uVar1 = fetch_data_word(uVar3);
          idiv_word(uVar1);
        }
        else {
          uVar3 = decode_rm10_address(local_20);
          uVar3 = fetch_data_long(uVar3);
          idiv_long(uVar3);
        }
      }
      else if (local_1c == 5) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm10_address(local_20);
          uVar1 = fetch_data_word(uVar3);
          imul_word(uVar1);
        }
        else {
          uVar3 = decode_rm10_address(local_20);
          uVar3 = fetch_data_long(uVar3);
          imul_long(uVar3);
        }
      }
      goto LAB_0027fe24;
    }
    if (local_1c == 2) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm10_address(local_20);
        goto LAB_002804c5;
      }
      uVar3 = decode_rm10_address(local_20);
      goto LAB_002802bd;
    }
    if (local_1c == 3) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm10_address(local_20);
        goto LAB_00280475;
      }
      uVar3 = decode_rm10_address(local_20);
      goto LAB_0028003d;
    }
    if (local_1c == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm10_address(local_20);
        goto LAB_00280445;
      }
      uVar3 = decode_rm10_address(local_20);
      goto LAB_0027fe01;
    }
  }
  else if (local_24 < 3) {
    if (local_24 == 0) {
      if (local_1c == 4) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm00_address(local_20);
          uVar1 = fetch_data_word(uVar3);
          mul_word(uVar1);
        }
        else {
          uVar3 = decode_rm00_address(local_20);
          uVar3 = fetch_data_long(uVar3);
          mul_long(uVar3);
        }
        goto LAB_0027fe24;
      }
      if (4 < local_1c) {
        if (local_1c == 6) {
          if ((DAT_0054840c & 0x200) == 0) {
            uVar3 = decode_rm00_address(local_20);
            uVar1 = fetch_data_word(uVar3);
            div_word(uVar1);
          }
          else {
            uVar3 = decode_rm00_address(local_20);
            uVar3 = fetch_data_long(uVar3);
            div_long(uVar3);
          }
        }
        else if (local_1c == 7) {
          if ((DAT_0054840c & 0x200) == 0) {
            uVar3 = decode_rm00_address(local_20);
            uVar1 = fetch_data_word(uVar3);
            idiv_word(uVar1);
          }
          else {
            uVar3 = decode_rm00_address(local_20);
            uVar3 = fetch_data_long(uVar3);
            idiv_long(uVar3);
          }
        }
        else if (local_1c == 5) {
          if ((DAT_0054840c & 0x200) == 0) {
            uVar3 = decode_rm00_address(local_20);
            uVar1 = fetch_data_word(uVar3);
            imul_word(uVar1);
          }
          else {
            uVar3 = decode_rm00_address(local_20);
            uVar3 = fetch_data_long(uVar3);
            imul_long(uVar3);
          }
        }
        goto LAB_0027fe24;
      }
      if (local_1c == 2) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm00_address(local_20);
LAB_002804c5:
          uVar1 = fetch_data_word(uVar3);
          uVar1 = not_word(uVar1);
          store_data_word(uVar3,uVar1);
          goto LAB_0027fe24;
        }
        uVar3 = decode_rm00_address(local_20);
LAB_002802bd:
        uVar4 = fetch_data_long(uVar3);
        uVar4 = not_long(uVar4);
        store_data_long(uVar3,uVar4);
        goto LAB_0027fe24;
      }
      if (local_1c == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm00_address(local_20);
LAB_00280475:
          uVar1 = fetch_data_word(uVar3);
          uVar1 = neg_word(uVar1);
          store_data_word(uVar3,uVar1);
          goto LAB_0027fe24;
        }
        uVar3 = decode_rm00_address(local_20);
LAB_0028003d:
        uVar4 = fetch_data_long(uVar3);
        uVar4 = neg_long(uVar4);
        store_data_long(uVar3,uVar4);
        goto LAB_0027fe24;
      }
      if (local_1c == 0) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm00_address(local_20);
LAB_00280445:
          uVar1 = fetch_word_imm();
          uVar2 = fetch_data_word(uVar3);
          test_word(uVar2,uVar1);
          goto LAB_0027fe24;
        }
        uVar3 = decode_rm00_address(local_20);
LAB_0027fe01:
        uVar4 = fetch_long_imm();
        uVar3 = fetch_data_long(uVar3);
        test_long(uVar3,uVar4);
        goto LAB_0027fe24;
      }
    }
    else {
      if (local_24 != 1) goto LAB_0027fe24;
      if (local_1c == 4) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm01_address(local_20);
          uVar1 = fetch_data_word(uVar3);
          mul_word(uVar1);
        }
        else {
          uVar3 = decode_rm01_address(local_20);
          uVar3 = fetch_data_long(uVar3);
          mul_long(uVar3);
        }
        goto LAB_0027fe24;
      }
      if (4 < local_1c) {
        if (local_1c == 6) {
          if ((DAT_0054840c & 0x200) == 0) {
            uVar3 = decode_rm01_address(local_20);
            uVar1 = fetch_data_word(uVar3);
            div_word(uVar1);
          }
          else {
            uVar3 = decode_rm01_address(local_20);
            uVar3 = fetch_data_long(uVar3);
            div_long(uVar3);
          }
        }
        else if (local_1c == 7) {
          if ((DAT_0054840c & 0x200) == 0) {
            uVar3 = decode_rm01_address(local_20);
            uVar1 = fetch_data_word(uVar3);
            idiv_word(uVar1);
          }
          else {
            uVar3 = decode_rm01_address(local_20);
            uVar3 = fetch_data_long(uVar3);
            idiv_long(uVar3);
          }
        }
        else if (local_1c == 5) {
          if ((DAT_0054840c & 0x200) == 0) {
            uVar3 = decode_rm01_address(local_20);
            uVar1 = fetch_data_word(uVar3);
            imul_word(uVar1);
          }
          else {
            uVar3 = decode_rm01_address(local_20);
            uVar3 = fetch_data_long(uVar3);
            imul_long(uVar3);
          }
        }
        goto LAB_0027fe24;
      }
      if (local_1c == 2) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm01_address(local_20);
          goto LAB_002804c5;
        }
        uVar3 = decode_rm01_address(local_20);
        goto LAB_002802bd;
      }
      if (local_1c == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm01_address(local_20);
          goto LAB_00280475;
        }
        uVar3 = decode_rm01_address(local_20);
        goto LAB_0028003d;
      }
      if (local_1c == 0) {
        if ((DAT_0054840c & 0x200) == 0) {
          uVar3 = decode_rm01_address(local_20);
          goto LAB_00280445;
        }
        uVar3 = decode_rm01_address(local_20);
        goto LAB_0027fe01;
      }
    }
  }
  else {
    if (local_24 != 3) goto LAB_0027fe24;
    if (local_1c == 4) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar6 = (undefined2 *)decode_rm_word_register(local_20);
        mul_word(*puVar6);
      }
      else {
        puVar5 = (undefined4 *)decode_rm_long_register();
        mul_long(*puVar5);
      }
      goto LAB_0027fe24;
    }
    if (4 < local_1c) {
      if (local_1c == 6) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          div_word(*puVar6);
        }
        else {
          puVar5 = (undefined4 *)decode_rm_long_register();
          div_long(*puVar5);
        }
      }
      else if (local_1c == 7) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          idiv_word(*puVar6);
        }
        else {
          puVar5 = (undefined4 *)decode_rm_long_register();
          idiv_long(*puVar5);
        }
      }
      else if (local_1c == 5) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          imul_word(*puVar6);
        }
        else {
          puVar5 = (undefined4 *)decode_rm_long_register();
          imul_long(*puVar5);
        }
      }
      goto LAB_0027fe24;
    }
    if (local_1c == 2) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar6 = (undefined2 *)decode_rm_word_register(local_20);
        uVar1 = not_word(*puVar6);
        *puVar6 = uVar1;
      }
      else {
        puVar5 = (undefined4 *)decode_rm_long_register();
        uVar3 = not_long(*puVar5);
        *puVar5 = uVar3;
      }
      goto LAB_0027fe24;
    }
    if (local_1c == 3) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar6 = (undefined2 *)decode_rm_word_register(local_20);
        uVar1 = neg_word(*puVar6);
        *puVar6 = uVar1;
      }
      else {
        puVar5 = (undefined4 *)decode_rm_long_register();
        uVar3 = neg_long(*puVar5);
        *puVar5 = uVar3;
      }
      goto LAB_0027fe24;
    }
    if (local_1c == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar6 = (undefined2 *)decode_rm_word_register(local_20);
        uVar1 = fetch_word_imm();
        test_word(*puVar6,uVar1);
      }
      else {
        puVar5 = (undefined4 *)decode_rm_long_register();
        uVar3 = fetch_long_imm();
        test_long(*puVar5,uVar3);
      }
      goto LAB_0027fe24;
    }
  }
  if (local_1c == 1) {
    X86EMU_halt_sys();
  }
LAB_0027fe24:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280700 x86emuOp_jump_byte_IMM =====

void x86emuOp_jump_byte_IMM(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483f8 = DAT_005483f8 + cVar1;
  return;
}


// ===== 00280730 x86emuOp_out_word_IMM_AX =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_out_word_IMM_AX(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  if ((DAT_0054840c & 0x200) != 0) {
    (*(code *)sys_outl)(uVar1,_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  (*(code *)sys_outw)(uVar1,_DAT_005483d8 & 0xffff);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002807a0 x86emuOp_out_byte_IMM_AL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_out_byte_IMM_AL(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  (*(code *)sys_outb)(uVar1,(undefined1)DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002807d0 x86emuOp_in_word_AX_IMM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_in_word_AX_IMM(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  
  uVar1 = fetch_byte_imm();
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = (*(code *)sys_inl)();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar2 = (*(code *)sys_inw)(uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar2);
  return;
}


// ===== 00280830 x86emuOp_in_byte_AL_IMM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_in_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = (*(code *)sys_inb)(uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280860 x86emuOp_jcxz =====

void x86emuOp_jcxz(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if ((short)DAT_005483e0 == 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280890 x86emuOp_loop =====

void x86emuOp_loop(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
  if ((short)DAT_005483e0 != 0) {
    DAT_005483f8 = cVar1 + DAT_005483f8;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002808d0 x86emuOp_loope =====

void x86emuOp_loope(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
  if (((short)DAT_005483e0 != 0) && (((byte)DAT_005483fc & 0x40) != 0)) {
    DAT_005483f8 = cVar1 + DAT_005483f8;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280910 x86emuOp_loopne =====

void x86emuOp_loopne(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
  if (((short)DAT_005483e0 != 0) && (((byte)DAT_005483fc & 0x40) == 0)) {
    DAT_005483f8 = cVar1 + DAT_005483f8;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280950 x86emuOp_mov_byte_RM_IMM =====

void x86emuOp_mov_byte_RM_IMM(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int local_24;
  undefined4 local_20;
  int local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_1c[0] == 0) {
    iVar1 = local_24 + -2;
    if (local_24 == 2) {
LAB_00280a01:
      uVar3 = decode_rm10_address(local_20);
      goto LAB_0028099b;
    }
  }
  else {
    X86EMU_halt_sys();
    iVar1 = local_24 + -2;
    if (iVar1 == 0) goto LAB_00280a01;
  }
  if (SBORROW4(local_24,2) != iVar1 < 0) {
    if (local_24 == 0) {
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002809df;
      uVar3 = decode_rm01_address(local_20);
    }
LAB_0028099b:
    uVar2 = fetch_byte_imm();
    store_data_byte(uVar3,uVar2);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_24 == 3) {
    puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
    uVar2 = fetch_byte_imm();
    *puVar4 = uVar2;
  }
LAB_002809df:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280a30 x86emuOp_opcC1_word_RM_MEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opcC1_word_RM_MEM(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_00280b75;
    }
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          uVar1 = fetch_byte_imm();
          uVar2 = (**(code **)(opcD1_word_operation + (long)local_1c * 8))(*puVar6,uVar1);
          *puVar6 = uVar2;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        uVar1 = fetch_byte_imm();
        uVar3 = (**(code **)(opcD1_long_operation + (long)local_1c * 8))(*puVar5,uVar1);
        *puVar5 = uVar3;
      }
LAB_00280ad4:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_00280b75:
        uVar1 = fetch_byte_imm();
        uVar2 = fetch_data_word(uVar3);
        uVar2 = (**(code **)(opcD1_word_operation + (long)local_1c * 8))(uVar2,uVar1);
        store_data_word(uVar3,uVar2);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00280ad4;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_00280b75;
      }
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_byte_imm();
  uVar4 = fetch_data_long(uVar3);
  uVar4 = (**(code **)(opcD1_long_operation + (long)local_1c * 8))(uVar4,uVar1);
  store_data_long(uVar3,uVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280c20 x86emuOp_opcC0_byte_RM_MEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opcC0_byte_RM_MEM(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = fetch_byte_imm();
        uVar1 = (**(code **)(opcD0_byte_operation + (long)local_1c * 8))(*puVar4,uVar1);
        *puVar4 = uVar1;
      }
LAB_00280cee:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00280cee;
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_byte_imm();
  uVar2 = fetch_data_byte(uVar3);
  uVar1 = (**(code **)(opcD0_byte_operation + (long)local_1c * 8))(uVar2,uVar1);
  store_data_byte(uVar3,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280d30 x86emuOp_mov_byte_BH_IMM =====

void x86emuOp_mov_byte_BH_IMM(void)

{
  DAT_005483dc._1_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280d50 x86emuOp_mov_byte_DH_IMM =====

void x86emuOp_mov_byte_DH_IMM(void)

{
  DAT_005483e4._1_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280d70 x86emuOp_mov_byte_CH_IMM =====

void x86emuOp_mov_byte_CH_IMM(void)

{
  DAT_005483e0._1_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280d90 x86emuOp_mov_byte_AH_IMM =====

void x86emuOp_mov_byte_AH_IMM(void)

{
  DAT_005483d8._1_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280db0 x86emuOp_mov_byte_BL_IMM =====

void x86emuOp_mov_byte_BL_IMM(void)

{
  DAT_005483dc._0_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280dd0 x86emuOp_mov_byte_DL_IMM =====

void x86emuOp_mov_byte_DL_IMM(void)

{
  DAT_005483e4._0_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280df0 x86emuOp_mov_byte_CL_IMM =====

void x86emuOp_mov_byte_CL_IMM(void)

{
  DAT_005483e0._0_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280e10 x86emuOp_mov_byte_AL_IMM =====

void x86emuOp_mov_byte_AL_IMM(void)

{
  DAT_005483d8._0_1_ = fetch_byte_imm();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00280e30 x86emuOp_opc83_word_RM_IMM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opc83_word_RM_IMM(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_00280f95;
    }
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          cVar1 = fetch_byte_imm();
          uVar2 = (**(code **)(opc83_word_operation + (long)local_1c * 8))(*puVar6,(short)cVar1);
          if (local_1c != 7) {
            *puVar6 = uVar2;
          }
        }
        else {
          puVar5 = (undefined4 *)decode_rm_long_register();
          cVar1 = fetch_byte_imm();
          uVar3 = (**(code **)(opc83_long_operation + (long)local_1c * 8))(*puVar5,(int)cVar1);
          if (local_1c != 7) {
            *puVar5 = uVar3;
          }
        }
      }
LAB_00280ee6:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_00280f95:
        uVar2 = fetch_data_word(uVar3);
        cVar1 = fetch_byte_imm();
        uVar2 = (**(code **)(opc83_word_operation + (long)local_1c * 8))(uVar2,(short)cVar1);
        if (local_1c != 7) {
          store_data_word(uVar3,uVar2);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        goto LAB_00281070;
      }
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00280ee6;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_00280f95;
      }
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar4 = fetch_data_long(uVar3);
  cVar1 = fetch_byte_imm();
  uVar4 = (**(code **)(opc83_long_operation + (long)local_1c * 8))(uVar4,(int)cVar1);
  if (local_1c != 7) {
    store_data_long(uVar3,uVar4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
LAB_00281070:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002810a0 x86emuOp_opc80_byte_RM_IMM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_opc80_byte_RM_IMM(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    uVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = fetch_byte_imm();
        uVar1 = (**(code **)(opc80_byte_operation + (long)local_1c * 8))(*puVar4,uVar1);
        if (local_1c != 7) {
          *puVar4 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
      }
      goto LAB_00281129;
    }
    if (local_24 == 0) {
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00281129;
      uVar3 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar3);
  uVar2 = fetch_byte_imm();
  uVar1 = (**(code **)(opc80_byte_operation + (long)local_1c * 8))(uVar1,uVar2);
  if (local_1c == 7) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  store_data_byte(uVar3,uVar1);
LAB_00281129:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002811e0 x86emuOp_opc82_byte_RM_IMM =====

void x86emuOp_opc82_byte_RM_IMM(undefined1 param_1)

{
  x86emuOp_opc80_byte_RM_IMM(param_1);
  return;
}


// ===== 002811f0 x86emuOp_jump_near_NLE =====

void x86emuOp_jump_near_NLE(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)((byte)DAT_005483fc >> 7) == ((byte)(DAT_005483fc >> 0xb) & 1)) &&
     ((DAT_005483fc & 0x40) == 0)) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281250 x86emuOp_jump_near_LE =====

void x86emuOp_jump_near_LE(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)((byte)DAT_005483fc >> 7) == ((byte)(DAT_005483fc >> 0xb) & 1)) &&
     ((DAT_005483fc & 0x40) == 0)) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  DAT_005483f8 = DAT_005483f8 + cVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002812b0 x86emuOp_jump_near_NL =====

void x86emuOp_jump_near_NL(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if ((byte)((byte)DAT_005483fc >> 7) == ((byte)(DAT_005483fc >> 0xb) & 1)) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002812f0 x86emuOp_jump_near_L =====

void x86emuOp_jump_near_L(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if ((byte)((byte)DAT_005483fc >> 7) != ((byte)(DAT_005483fc >> 0xb) & 1)) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281330 x86emuOp_jump_near_NP =====

void x86emuOp_jump_near_NP(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 4) == 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281360 x86emuOp_jump_near_P =====

void x86emuOp_jump_near_P(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 4) != 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281390 x86emuOp_jump_near_NS =====

void x86emuOp_jump_near_NS(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 0x80) == 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002813c0 x86emuOp_jump_near_S =====

void x86emuOp_jump_near_S(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 0x80) != 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


