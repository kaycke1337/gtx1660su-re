// ===== 0010ee60 __pfx_nv_grdma_pci_topology_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eea7) */
/* WARNING: Removing unreachable block (ram,0x0010eeb1) */

undefined8 __pfx_nv_grdma_pci_topology_supported(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x326) == '\0') && (NVreg_GrdmaPciTopoCheckOverride != 1)) {
    uVar1 = 0;
    if (NVreg_GrdmaPciTopoCheckOverride != 2) {
      uVar1 = 1;
      if ((*(uint *)(param_1 + 0x10) & 0x88) == 8) {
        uVar1 = nv_pci_has_common_pci_switch(param_1,*(long *)(param_2 + 0x10) + -0xd0);
        return uVar1;
      }
    }
    return uVar1;
  }
  return 1;
}


// ===== 0010ee70 nv_grdma_pci_topology_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eea7) */
/* WARNING: Removing unreachable block (ram,0x0010eeb1) */

undefined8 nv_grdma_pci_topology_supported(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x326) == '\0') && (NVreg_GrdmaPciTopoCheckOverride != 1)) {
    uVar1 = 0;
    if (NVreg_GrdmaPciTopoCheckOverride != 2) {
      uVar1 = 1;
      if ((*(uint *)(param_1 + 0x10) & 0x88) == 8) {
        uVar1 = nv_pci_has_common_pci_switch(param_1,*(long *)(param_2 + 0x10) + -0xd0);
        return uVar1;
      }
    }
    return uVar1;
  }
  return 1;
}


// ===== 0010eed0 __pfx_nv_pci_unregister_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eef3) */

void __pfx_nv_pci_unregister_driver(void)

{
  if (NVreg_RegisterPCIDriver == 0) {
    return;
  }
  pci_unregister_driver(nv_pci_driver);
  return;
}


// ===== 0010eee0 nv_pci_unregister_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eef3) */

void nv_pci_unregister_driver(void)

{
  if (NVreg_RegisterPCIDriver == 0) {
    return;
  }
  pci_unregister_driver(nv_pci_driver);
  return;
}


// ===== 0010ef10 __pfx_nv_pci_register_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ef35) */

undefined8 __pfx_nv_pci_register_driver(void)

{
  undefined8 uVar1;
  
  if (NVreg_RegisterPCIDriver == 0) {
    return 0;
  }
  uVar1 = __pci_register_driver(nv_pci_driver,__this_module,"nvidia");
  return uVar1;
}


// ===== 0010ef20 nv_pci_register_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ef35) */

undefined8 nv_pci_register_driver(void)

{
  undefined8 uVar1;
  
  if (NVreg_RegisterPCIDriver == 0) {
    return 0;
  }
  uVar1 = __pci_register_driver(nv_pci_driver,__this_module,"nvidia");
  return uVar1;
}


// ===== 0010ef80 __pfx_nv_dma_buf_attach =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f03c) */

undefined8 __pfx_nv_dma_buf_attach(long param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  long lStack_38;
  
  plVar1 = *(long **)(param_1 + 0x70);
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  mutex_lock(plVar1 + 6);
  lVar2 = *(long *)(param_2 + 8);
  if (*(char *)((long)plVar1 + 0x59) == '\x01') {
    cVar3 = nv_pci_is_valid_topology_for_direct_pci(*plVar1,lVar2 + -0xd0);
    if (cVar3 != '\0') {
      *(undefined1 *)((long)plVar1 + 0x5a) = 1;
      goto LAB_0010f007;
    }
    nv_printf(4,"NVRM: dma-buf attach failed: topology not supported for mapping type FORCE_PCIE\n")
    ;
  }
  else {
    uStack_50 = 0;
    uStack_48 = *(undefined8 *)(lVar2 + -0x48);
    lStack_40 = lVar2;
    cVar3 = nv_grdma_pci_topology_supported(*plVar1,&uStack_50);
    if (cVar3 == '\0') {
      nv_printf(4,"NVRM: dma-buf attach failed: PCI topology not supported for dma-buf\n");
    }
    else {
LAB_0010f007:
      if (((*(long *)(param_2 + 0x28) == 0) || (*(char *)(param_2 + 0x20) != '\0')) ||
         (*(char *)(*plVar1 + 0x327) != '\0')) {
        uVar4 = 0;
        goto LAB_0010f019;
      }
      nv_printf(4,
                "NVRM: dma-buf attach failed: importer unable to handle MMIO without struct page\n")
      ;
    }
  }
  uVar4 = 0xfffffdf4;
LAB_0010f019:
  mutex_unlock(plVar1 + 6);
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010ef90 nv_dma_buf_attach =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f03c) */

undefined8 nv_dma_buf_attach(long param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  long local_38;
  
  plVar1 = *(long **)(param_1 + 0x70);
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  mutex_lock(plVar1 + 6);
  lVar2 = *(long *)(param_2 + 8);
  if (*(char *)((long)plVar1 + 0x59) == '\x01') {
    cVar3 = nv_pci_is_valid_topology_for_direct_pci(*plVar1,lVar2 + -0xd0);
    if (cVar3 != '\0') {
      *(undefined1 *)((long)plVar1 + 0x5a) = 1;
      goto LAB_0010f007;
    }
    nv_printf(4,"NVRM: dma-buf attach failed: topology not supported for mapping type FORCE_PCIE\n")
    ;
  }
  else {
    local_50 = 0;
    local_48 = *(undefined8 *)(lVar2 + -0x48);
    local_40 = lVar2;
    cVar3 = nv_grdma_pci_topology_supported(*plVar1,&local_50);
    if (cVar3 == '\0') {
      nv_printf(4,"NVRM: dma-buf attach failed: PCI topology not supported for dma-buf\n");
    }
    else {
LAB_0010f007:
      if (((*(long *)(param_2 + 0x28) == 0) || (*(char *)(param_2 + 0x20) != '\0')) ||
         (*(char *)(*plVar1 + 0x327) != '\0')) {
        uVar4 = 0;
        goto LAB_0010f019;
      }
      nv_printf(4,
                "NVRM: dma-buf attach failed: importer unable to handle MMIO without struct page\n")
      ;
    }
  }
  uVar4 = 0xfffffdf4;
LAB_0010f019:
  mutex_unlock(plVar1 + 6);
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010f0b0 __pfx_nv_dma_buf_undup_mem_handles_unlocked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f142) */
/* WARNING: Removing unreachable block (ram,0x0010f147) */

void __pfx_nv_dma_buf_undup_mem_handles_unlocked
               (undefined8 param_1,uint param_2,int param_3,undefined8 *param_4)

{
  uint uVar1;
  long lVar2;
  
  if (param_3 != 0) {
    uVar1 = param_3 + param_2;
    do {
      lVar2 = (ulong)param_2 * 0x38;
      if (*(int *)(param_4[9] + lVar2) != 0) {
        rm_dma_buf_undup_mem_handle(param_1,*param_4,*(undefined4 *)(param_4 + 1));
        param_4[5] = param_4[5] - *(long *)((undefined4 *)(param_4[9] + lVar2) + 4);
        *(undefined4 *)(param_4[9] + lVar2) = 0;
        *(undefined8 *)(param_4[9] + 8 + lVar2) = 0;
        *(undefined8 *)(param_4[9] + 0x10 + lVar2) = 0;
        *(int *)(param_4 + 3) = *(int *)(param_4 + 3) + -1;
      }
      param_2 = param_2 + 1;
    } while (uVar1 != param_2);
    return;
  }
  return;
}


// ===== 0010f0c0 nv_dma_buf_undup_mem_handles_unlocked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f142) */
/* WARNING: Removing unreachable block (ram,0x0010f147) */

void nv_dma_buf_undup_mem_handles_unlocked
               (undefined8 param_1,uint param_2,int param_3,undefined8 *param_4)

{
  uint uVar1;
  long lVar2;
  
  if (param_3 != 0) {
    uVar1 = param_3 + param_2;
    do {
      lVar2 = (ulong)param_2 * 0x38;
      if (*(int *)(param_4[9] + lVar2) != 0) {
        rm_dma_buf_undup_mem_handle(param_1,*param_4,*(undefined4 *)(param_4 + 1));
        param_4[5] = param_4[5] - *(long *)((undefined4 *)(param_4[9] + lVar2) + 4);
        *(undefined4 *)(param_4[9] + lVar2) = 0;
        *(undefined8 *)(param_4[9] + 8 + lVar2) = 0;
        *(undefined8 *)(param_4[9] + 0x10 + lVar2) = 0;
        *(int *)(param_4 + 3) = *(int *)(param_4 + 3) + -1;
      }
      param_2 = param_2 + 1;
    } while (uVar1 != param_2);
    return;
  }
  return;
}


// ===== 0010f150 __pfx_nv_put_phys_addresses =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f1d8) */
/* WARNING: Removing unreachable block (ram,0x0010f1dd) */

void __pfx_nv_put_phys_addresses(undefined8 param_1,undefined8 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 != 0) {
    uVar1 = param_4 + param_3;
    do {
      puVar2 = (undefined4 *)(param_2[9] + (ulong)param_3 * 0x38);
      if (*(long *)(puVar2 + 8) == 0) {
        rm_dma_buf_unmap_mem_handle
                  (param_1,*param_2,*(undefined4 *)(param_2 + 1),*puVar2,
                   *(undefined1 *)((long)param_2 + 0x59),*(undefined8 *)(puVar2 + 6),
                   *(undefined1 *)(param_2 + 0xb),*(undefined8 *)(puVar2 + 10),
                   *(undefined8 *)(puVar2 + 0xc));
        *(undefined8 *)(param_2[9] + 0x30 + (ulong)param_3 * 0x38) = 0;
      }
      param_3 = param_3 + 1;
    } while (uVar1 != param_3);
    return;
  }
  return;
}


// ===== 0010f160 nv_put_phys_addresses =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f1d8) */
/* WARNING: Removing unreachable block (ram,0x0010f1dd) */

void nv_put_phys_addresses(undefined8 param_1,undefined8 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 != 0) {
    uVar1 = param_4 + param_3;
    do {
      puVar2 = (undefined4 *)(param_2[9] + (ulong)param_3 * 0x38);
      if (*(long *)(puVar2 + 8) == 0) {
        rm_dma_buf_unmap_mem_handle
                  (param_1,*param_2,*(undefined4 *)(param_2 + 1),*puVar2,
                   *(undefined1 *)((long)param_2 + 0x59),*(undefined8 *)(puVar2 + 6),
                   *(undefined1 *)(param_2 + 0xb),*(undefined8 *)(puVar2 + 10),
                   *(undefined8 *)(puVar2 + 0xc));
        *(undefined8 *)(param_2[9] + 0x30 + (ulong)param_3 * 0x38) = 0;
      }
      param_3 = param_3 + 1;
    } while (uVar1 != param_3);
    return;
  }
  return;
}


// ===== 0010f1f0 __pfx_nv_dma_buf_get_sg_count.constprop.0.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f286) */
/* WARNING: Removing unreachable block (ram,0x0010f29f) */

int __pfx_nv_dma_buf_get_sg_count_constprop_0_isra_0(uint *param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  
  if ((param_1 == (uint *)0x0) || (*param_1 == 0)) {
    uVar6 = 0x10000;
  }
  else {
    uVar5 = *param_1 & 0xfffff000;
    uVar6 = (ulong)uVar5;
    if (uVar5 < 0x1000) {
      return 0;
    }
  }
  iVar7 = 0;
  if (*(uint *)(param_2 + 0x18) != 0) {
    lVar8 = *(long *)(param_2 + 0x48);
    iVar7 = 0;
    lVar1 = (ulong)*(uint *)(param_2 + 0x18) * 0x38 + lVar8;
    do {
      iVar3 = (int)*(undefined8 *)(lVar8 + 0x30);
      if (iVar3 != 0) {
        plVar4 = (long *)(*(long *)(lVar8 + 0x28) + 8);
        do {
          lVar2 = *plVar4;
          plVar4 = plVar4 + 2;
          iVar7 = iVar7 + (int)((lVar2 + (uVar6 - 1)) / uVar6);
        } while ((long *)(*(long *)(lVar8 + 0x28) + 0x18 + (ulong)(iVar3 - 1) * 0x10) != plVar4);
      }
      lVar8 = lVar8 + 0x38;
    } while (lVar8 != lVar1);
  }
  *param_3 = (int)uVar6;
  return iVar7;
}


// ===== 0010f200 nv_dma_buf_get_sg_count.constprop.0.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f286) */
/* WARNING: Removing unreachable block (ram,0x0010f29f) */

int nv_dma_buf_get_sg_count_constprop_0_isra_0(uint *param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  
  if ((param_1 == (uint *)0x0) || (*param_1 == 0)) {
    uVar6 = 0x10000;
  }
  else {
    uVar5 = *param_1 & 0xfffff000;
    uVar6 = (ulong)uVar5;
    if (uVar5 < 0x1000) {
      return 0;
    }
  }
  iVar7 = 0;
  if (*(uint *)(param_2 + 0x18) != 0) {
    lVar8 = *(long *)(param_2 + 0x48);
    iVar7 = 0;
    lVar1 = (ulong)*(uint *)(param_2 + 0x18) * 0x38 + lVar8;
    do {
      iVar3 = (int)*(undefined8 *)(lVar8 + 0x30);
      if (iVar3 != 0) {
        plVar4 = (long *)(*(long *)(lVar8 + 0x28) + 8);
        do {
          lVar2 = *plVar4;
          plVar4 = plVar4 + 2;
          iVar7 = iVar7 + (int)((lVar2 + (uVar6 - 1)) / uVar6);
        } while ((long *)(*(long *)(lVar8 + 0x28) + 0x18 + (ulong)(iVar3 - 1) * 0x10) != plVar4);
      }
      lVar8 = lVar8 + 0x38;
    } while (lVar8 != lVar1);
  }
  *param_3 = (int)uVar6;
  return iVar7;
}


// ===== 0010f2b0 __pfx_nv_dma_buf_unmap_pfns.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f36d) */

void __pfx_nv_dma_buf_unmap_pfns_isra_0(long param_1,undefined8 *param_2,char param_3)

{
  ulong *puVar1;
  byte *pbVar2;
  uint uVar3;
  long in_GS_OFFSET;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_50 = 0;
  if (param_3 == '\0') {
    uStack_48 = *(undefined8 *)(param_1 + 0x260);
    lStack_40 = param_1;
    if (*(int *)(param_2 + 1) != 0) {
      pbVar2 = (byte *)*param_2;
      uVar3 = 0;
      do {
        while( true ) {
          uVar3 = uVar3 + 1;
          nv_dma_unmap_peer(&uStack_50,*(uint *)(pbVar2 + 0x18) >> 0xc,
                            *(undefined8 *)(pbVar2 + 0x10));
          if ((*pbVar2 & 2) == 0) break;
          pbVar2 = (byte *)0x0;
          if (*(uint *)(param_2 + 1) <= uVar3) goto LAB_0010f354;
        }
        puVar1 = (ulong *)(pbVar2 + 0x20);
        pbVar2 = pbVar2 + 0x20;
        if ((*puVar1 & 1) != 0) {
          pbVar2 = (byte *)(*puVar1 & 0xfffffffffffffffc);
        }
      } while (uVar3 < *(uint *)(param_2 + 1));
    }
  }
LAB_0010f354:
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010f2c0 nv_dma_buf_unmap_pfns.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f36d) */

void nv_dma_buf_unmap_pfns_isra_0(long param_1,undefined8 *param_2,char param_3)

{
  ulong *puVar1;
  byte *pbVar2;
  uint uVar3;
  long in_GS_OFFSET;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_50 = 0;
  if (param_3 == '\0') {
    local_48 = *(undefined8 *)(param_1 + 0x260);
    local_40 = param_1;
    if (*(int *)(param_2 + 1) != 0) {
      pbVar2 = (byte *)*param_2;
      uVar3 = 0;
      do {
        while( true ) {
          uVar3 = uVar3 + 1;
          nv_dma_unmap_peer(&local_50,*(uint *)(pbVar2 + 0x18) >> 0xc,*(undefined8 *)(pbVar2 + 0x10)
                           );
          if ((*pbVar2 & 2) == 0) break;
          pbVar2 = (byte *)0x0;
          if (*(uint *)(param_2 + 1) <= uVar3) goto LAB_0010f354;
        }
        puVar1 = (ulong *)(pbVar2 + 0x20);
        pbVar2 = pbVar2 + 0x20;
        if ((*puVar1 & 1) != 0) {
          pbVar2 = (byte *)(*puVar1 & 0xfffffffffffffffc);
        }
      } while (uVar3 < *(uint *)(param_2 + 1));
    }
  }
LAB_0010f354:
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010f380 __pfx_nv_dma_buf_undup_mem_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_dma_buf_undup_mem_handles
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = rm_acquire_api_lock();
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = rm_acquire_all_gpus_lock(param_1);
  if (iVar2 == 0) {
    nv_dma_buf_undup_mem_handles_unlocked(param_1,param_2,param_3,param_4);
    rm_release_all_gpus_lock(param_1);
    rm_release_api_lock(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0010f390 nv_dma_buf_undup_mem_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_dma_buf_undup_mem_handles
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = rm_acquire_api_lock();
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = rm_acquire_all_gpus_lock(param_1);
  if (iVar2 == 0) {
    nv_dma_buf_undup_mem_handles_unlocked(param_1,param_2,param_3,param_4);
    rm_release_all_gpus_lock(param_1);
    rm_release_api_lock(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0010f400 __pfx_nv_dma_buf_dup_mem_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f483) */

int __pfx_nv_dma_buf_dup_mem_handles(undefined8 param_1,undefined8 *param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long in_GS_OFFSET;
  int iStack_5c;
  char cStack_56;
  char cStack_55;
  undefined4 uStack_54;
  int iStack_50;
  int iStack_4c;
  undefined8 uStack_48;
  long lStack_40;
  
  iVar7 = *(int *)(param_3 + 0x10);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iVar5 = rm_acquire_api_lock();
  if (iVar5 == 0) {
    if (*(char *)(param_2 + 0x10) == '\0') {
      iVar5 = rm_acquire_gpu_lock(param_1,*param_2);
    }
    else {
      iVar5 = rm_acquire_all_gpus_lock(param_1);
    }
    if (iVar5 == 0) {
      if (*(int *)(param_3 + 0xc) == 0) {
        iVar6 = *(int *)(param_2 + 3);
        iStack_5c = 0;
      }
      else {
        lVar8 = 0;
        do {
          uStack_54 = 0;
          uStack_48 = 0;
          iStack_5c = (int)lVar8;
          iStack_50 = 0;
          lVar9 = (ulong)(uint)(iVar7 + iStack_5c) * 0x38;
          iStack_4c = 0;
          cStack_56 = '\0';
          cStack_55 = '\0';
          if (*(int *)(param_2[9] + lVar9) != 0) {
            iVar6 = 0x17;
            goto LAB_0010f655;
          }
          uVar3 = *(ulong *)(param_3 + 0x628 + lVar8 * 8);
          if ((ulong)(param_2[4] - param_2[5]) < uVar3) {
LAB_0010f64a:
            iVar6 = 0x1f;
            goto LAB_0010f655;
          }
          iVar6 = rm_dma_buf_dup_mem_handle
                            (param_1,*param_2,*(undefined4 *)(param_3 + 4),
                             *(undefined4 *)(param_2 + 1),*(undefined4 *)((long)param_2 + 0xc),
                             *(undefined4 *)(param_2 + 2),param_2[10],
                             *(undefined4 *)(param_3 + 0x24 + lVar8 * 4),
                             *(undefined8 *)(param_3 + 0x228 + lVar8 * 8),uVar3,&uStack_54,
                             &uStack_48,&cStack_56,&iStack_4c,&cStack_55,&iStack_50);
          if (iVar6 != 0) goto LAB_0010f655;
          if (*(char *)(param_2 + 0xc) == '\0') {
            *(char *)((long)param_2 + 0x61) = cStack_56;
            *(undefined1 *)(param_2 + 0xc) = 1;
            *(int *)(param_2 + 0xe) = iStack_4c;
            *(char *)((long)param_2 + 0x74) = cStack_55;
            *(int *)(param_2 + 0xf) = iStack_50;
          }
          else if ((((*(char *)((long)param_2 + 0x61) != cStack_56) ||
                    (*(int *)(param_2 + 0xe) != iStack_4c)) ||
                   (*(char *)((long)param_2 + 0x74) != cStack_55)) ||
                  (*(int *)(param_2 + 0xf) != iStack_50)) goto LAB_0010f64a;
          param_2[5] = param_2[5] + *(long *)(param_3 + 0x628 + lVar8 * 8);
          *(undefined4 *)(param_2[9] + lVar9) = uStack_54;
          *(undefined8 *)(param_2[9] + 8 + lVar9) = *(undefined8 *)(param_3 + 0x228 + lVar8 * 8);
          lVar1 = lVar8 * 8;
          lVar8 = lVar8 + 1;
          *(undefined8 *)(param_2[9] + 0x10 + lVar9) = *(undefined8 *)(param_3 + 0x628 + lVar1);
          *(undefined8 *)(param_2[9] + 0x18 + lVar9) = uStack_48;
          iVar6 = *(int *)(param_2 + 3) + 1;
          *(int *)(param_2 + 3) = iVar6;
        } while ((uint)lVar8 < *(uint *)(param_3 + 0xc));
        iStack_5c = iStack_5c + 1;
      }
      if ((*(int *)((long)param_2 + 0x14) != iVar6) || (param_2[5] == param_2[4])) {
        if (*(char *)(param_2 + 0x10) == '\0') {
          rm_release_gpu_lock(param_1,*param_2);
        }
        else {
          rm_release_all_gpus_lock(param_1);
        }
        rm_release_api_lock(param_1);
        goto LAB_0010f455;
      }
      iVar6 = 0x1f;
LAB_0010f655:
      iVar5 = iVar6;
      if (*(char *)(param_2 + 0x10) == '\0') {
        rm_release_gpu_lock(param_1,*param_2);
        uVar2 = *(undefined4 *)(param_3 + 0x10);
        iVar7 = rm_acquire_all_gpus_lock(param_1);
        if (iVar7 != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        nv_dma_buf_undup_mem_handles_unlocked(param_1,uVar2,iStack_5c,param_2);
        rm_release_all_gpus_lock(param_1);
      }
      else {
        nv_dma_buf_undup_mem_handles_unlocked
                  (param_1,*(undefined4 *)(param_3 + 0x10),iStack_5c,param_2);
        if (*(char *)(param_2 + 0x10) == '\0') {
          rm_release_gpu_lock(param_1,*param_2);
        }
        else {
          rm_release_all_gpus_lock(param_1);
        }
      }
    }
    rm_release_api_lock(param_1);
  }
LAB_0010f455:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}


// ===== 0010f410 nv_dma_buf_dup_mem_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f483) */

int nv_dma_buf_dup_mem_handles(undefined8 param_1,undefined8 *param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long in_GS_OFFSET;
  int local_5c;
  char local_56;
  char local_55;
  undefined4 local_54;
  int local_50;
  int local_4c;
  undefined8 local_48;
  long local_40;
  
  iVar7 = *(int *)(param_3 + 0x10);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iVar5 = rm_acquire_api_lock();
  if (iVar5 == 0) {
    if (*(char *)(param_2 + 0x10) == '\0') {
      iVar5 = rm_acquire_gpu_lock(param_1,*param_2);
    }
    else {
      iVar5 = rm_acquire_all_gpus_lock(param_1);
    }
    if (iVar5 == 0) {
      if (*(int *)(param_3 + 0xc) == 0) {
        iVar6 = *(int *)(param_2 + 3);
        local_5c = 0;
      }
      else {
        lVar8 = 0;
        do {
          local_54 = 0;
          local_48 = 0;
          local_5c = (int)lVar8;
          local_50 = 0;
          lVar9 = (ulong)(uint)(iVar7 + local_5c) * 0x38;
          local_4c = 0;
          local_56 = '\0';
          local_55 = '\0';
          if (*(int *)(param_2[9] + lVar9) != 0) {
            iVar6 = 0x17;
            goto LAB_0010f655;
          }
          uVar3 = *(ulong *)(param_3 + 0x628 + lVar8 * 8);
          if ((ulong)(param_2[4] - param_2[5]) < uVar3) {
LAB_0010f64a:
            iVar6 = 0x1f;
            goto LAB_0010f655;
          }
          iVar6 = rm_dma_buf_dup_mem_handle
                            (param_1,*param_2,*(undefined4 *)(param_3 + 4),
                             *(undefined4 *)(param_2 + 1),*(undefined4 *)((long)param_2 + 0xc),
                             *(undefined4 *)(param_2 + 2),param_2[10],
                             *(undefined4 *)(param_3 + 0x24 + lVar8 * 4),
                             *(undefined8 *)(param_3 + 0x228 + lVar8 * 8),uVar3,&local_54,&local_48,
                             &local_56,&local_4c,&local_55,&local_50);
          if (iVar6 != 0) goto LAB_0010f655;
          if (*(char *)(param_2 + 0xc) == '\0') {
            *(char *)((long)param_2 + 0x61) = local_56;
            *(undefined1 *)(param_2 + 0xc) = 1;
            *(int *)(param_2 + 0xe) = local_4c;
            *(char *)((long)param_2 + 0x74) = local_55;
            *(int *)(param_2 + 0xf) = local_50;
          }
          else if ((((*(char *)((long)param_2 + 0x61) != local_56) ||
                    (*(int *)(param_2 + 0xe) != local_4c)) ||
                   (*(char *)((long)param_2 + 0x74) != local_55)) ||
                  (*(int *)(param_2 + 0xf) != local_50)) goto LAB_0010f64a;
          param_2[5] = param_2[5] + *(long *)(param_3 + 0x628 + lVar8 * 8);
          *(undefined4 *)(param_2[9] + lVar9) = local_54;
          *(undefined8 *)(param_2[9] + 8 + lVar9) = *(undefined8 *)(param_3 + 0x228 + lVar8 * 8);
          lVar1 = lVar8 * 8;
          lVar8 = lVar8 + 1;
          *(undefined8 *)(param_2[9] + 0x10 + lVar9) = *(undefined8 *)(param_3 + 0x628 + lVar1);
          *(undefined8 *)(param_2[9] + 0x18 + lVar9) = local_48;
          iVar6 = *(int *)(param_2 + 3) + 1;
          *(int *)(param_2 + 3) = iVar6;
        } while ((uint)lVar8 < *(uint *)(param_3 + 0xc));
        local_5c = local_5c + 1;
      }
      if ((*(int *)((long)param_2 + 0x14) != iVar6) || (param_2[5] == param_2[4])) {
        if (*(char *)(param_2 + 0x10) == '\0') {
          rm_release_gpu_lock(param_1,*param_2);
        }
        else {
          rm_release_all_gpus_lock(param_1);
        }
        rm_release_api_lock(param_1);
        goto LAB_0010f455;
      }
      iVar6 = 0x1f;
LAB_0010f655:
      iVar5 = iVar6;
      if (*(char *)(param_2 + 0x10) == '\0') {
        rm_release_gpu_lock(param_1,*param_2);
        uVar2 = *(undefined4 *)(param_3 + 0x10);
        iVar7 = rm_acquire_all_gpus_lock(param_1);
        if (iVar7 != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        nv_dma_buf_undup_mem_handles_unlocked(param_1,uVar2,local_5c,param_2);
        rm_release_all_gpus_lock(param_1);
      }
      else {
        nv_dma_buf_undup_mem_handles_unlocked
                  (param_1,*(undefined4 *)(param_3 + 0x10),local_5c,param_2);
        if (*(char *)(param_2 + 0x10) == '\0') {
          rm_release_gpu_lock(param_1,*param_2);
        }
        else {
          rm_release_all_gpus_lock(param_1);
        }
      }
    }
    rm_release_api_lock(param_1);
  }
LAB_0010f455:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}


// ===== 0010f790 __pfx_nv_dma_buf_put_phys_addresses =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f85e) */
/* WARNING: Removing unreachable block (ram,0x0010f863) */

void __pfx_nv_dma_buf_put_phys_addresses(undefined8 *param_1,uint param_2,int param_3)

{
  long *plVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  
  if (param_3 != 0) {
    lVar7 = param_1[9];
    bVar3 = false;
    uVar8 = param_2;
    do {
      uVar9 = (ulong)uVar8;
      plVar1 = (long *)(lVar7 + 0x20 + uVar9 * 0x38);
      *plVar1 = *plVar1 + -1;
      lVar7 = param_1[9];
      uVar8 = uVar8 + 1;
      bVar3 = (bool)(bVar3 | *(long *)(lVar7 + 0x20 + uVar9 * 0x38) == 0);
    } while (param_2 + param_3 != uVar8);
    if (bVar3) {
      puVar6 = (undefined4 *)0x0;
      cVar4 = rm_is_altstack_in_use();
      if (cVar4 != '\0') {
        puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar6 == (undefined4 *)0x0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        *puVar6 = 0x2ff0;
        *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
      }
      if (*(char *)(param_1 + 0xb) == '\0') {
        iVar5 = rm_acquire_api_lock(puVar6);
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        iVar5 = rm_acquire_gpu_lock(puVar6,*param_1);
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        nv_put_phys_addresses(puVar6,param_1,param_2,param_3);
        rm_release_gpu_lock(puVar6,*param_1);
        rm_release_api_lock(puVar6);
      }
      else {
        nv_put_phys_addresses(puVar6,param_1,param_2,param_3);
      }
      if ((puVar6 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
        return;
      }
      return;
    }
  }
  return;
}


// ===== 0010f7a0 nv_dma_buf_put_phys_addresses =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010f85e) */
/* WARNING: Removing unreachable block (ram,0x0010f863) */

void nv_dma_buf_put_phys_addresses(undefined8 *param_1,uint param_2,int param_3)

{
  long *plVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  
  if (param_3 != 0) {
    lVar7 = param_1[9];
    bVar3 = false;
    uVar8 = param_2;
    do {
      uVar9 = (ulong)uVar8;
      plVar1 = (long *)(lVar7 + 0x20 + uVar9 * 0x38);
      *plVar1 = *plVar1 + -1;
      lVar7 = param_1[9];
      uVar8 = uVar8 + 1;
      bVar3 = (bool)(bVar3 | *(long *)(lVar7 + 0x20 + uVar9 * 0x38) == 0);
    } while (param_2 + param_3 != uVar8);
    if (bVar3) {
      puVar6 = (undefined4 *)0x0;
      cVar4 = rm_is_altstack_in_use();
      if (cVar4 != '\0') {
        puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar6 == (undefined4 *)0x0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        *puVar6 = 0x2ff0;
        *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
      }
      if (*(char *)(param_1 + 0xb) == '\0') {
        iVar5 = rm_acquire_api_lock(puVar6);
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        iVar5 = rm_acquire_gpu_lock(puVar6,*param_1);
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        nv_put_phys_addresses(puVar6,param_1,param_2,param_3);
        rm_release_gpu_lock(puVar6,*param_1);
        rm_release_api_lock(puVar6);
      }
      else {
        nv_put_phys_addresses(puVar6,param_1,param_2,param_3);
      }
      if ((puVar6 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
        return;
      }
      return;
    }
  }
  return;
}


// ===== 0010f8e0 __pfx_nv_dma_buf_unmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_dma_buf_unmap(long *param_1,undefined8 *param_2)

{
  char cVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*param_1 + 0x70);
  mutex_lock(plVar2 + 6);
  if ((*(char *)(*plVar2 + 0x326) == '\0') || (*(char *)((long)plVar2 + 0x59) != '\0')) {
    nv_dma_buf_unmap_pfns_isra_0(param_1[1],param_2);
  }
  else if (*(char *)((long)plVar2 + 0x5a) == '\0') {
    dma_unmap_sg_attrs(param_1[1],*param_2,*(undefined4 *)(param_2 + 1),0,0x20);
    cVar1 = (char)plVar2[0xb];
    goto joined_r0x0010f990;
  }
  cVar1 = (char)plVar2[0xb];
joined_r0x0010f990:
  if (cVar1 == '\0') {
    nv_dma_buf_put_phys_addresses(plVar2,0,(int)plVar2[3]);
  }
  sg_free_table(param_2);
  kfree(param_2);
  mutex_unlock(plVar2 + 6);
  return;
}


// ===== 0010f8f0 nv_dma_buf_unmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_dma_buf_unmap(long *param_1,undefined8 *param_2)

{
  char cVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*param_1 + 0x70);
  mutex_lock(plVar2 + 6);
  if ((*(char *)(*plVar2 + 0x326) == '\0') || (*(char *)((long)plVar2 + 0x59) != '\0')) {
    nv_dma_buf_unmap_pfns_isra_0(param_1[1],param_2);
  }
  else if (*(char *)((long)plVar2 + 0x5a) == '\0') {
    dma_unmap_sg_attrs(param_1[1],*param_2,*(undefined4 *)(param_2 + 1),0,0x20);
    cVar1 = (char)plVar2[0xb];
    goto joined_r0x0010f990;
  }
  cVar1 = (char)plVar2[0xb];
joined_r0x0010f990:
  if (cVar1 == '\0') {
    nv_dma_buf_put_phys_addresses(plVar2,0,(int)plVar2[3]);
  }
  sg_free_table(param_2);
  kfree(param_2);
  mutex_unlock(plVar2 + 6);
  return;
}


// ===== 0010f9b0 __pfx_nv_dma_buf_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010facc) */

void __pfx_nv_dma_buf_release(long param_1)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  long lVar6;
  undefined4 *puVar7;
  long lVar8;
  
  plVar2 = *(long **)(param_1 + 0x70);
  if (plVar2 != (long *)0x0) {
    lVar3 = *plVar2;
    if ((char)plVar2[0xb] != '\0') {
      nv_dma_buf_put_phys_addresses(plVar2,0,(int)plVar2[3]);
    }
    cVar5 = rm_is_altstack_in_use();
    puVar7 = (undefined4 *)0x0;
    if (cVar5 != '\0') {
      puVar7 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar7 == (undefined4 *)0x0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      *puVar7 = 0x2ff0;
      *(undefined4 **)(puVar7 + 2) = puVar7 + 0xc00;
    }
    uVar1 = *(uint *)(plVar2 + 3);
    if (uVar1 != 0) {
      lVar6 = plVar2[9];
      lVar8 = (ulong)uVar1 * 0x38 + lVar6;
      do {
        if (*(long *)(lVar6 + 0x20) != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        lVar6 = lVar6 + 0x38;
      } while (lVar8 != lVar6);
    }
    nv_dma_buf_undup_mem_handles(puVar7,0,uVar1,plVar2);
    rm_dma_buf_put_client_and_device
              (puVar7,*plVar2,(int)plVar2[1],*(undefined4 *)((long)plVar2 + 0xc),(int)plVar2[2],
               plVar2[10]);
    if (plVar2[5] != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    if ((int)plVar2[3] != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    if (plVar2[9] != 0) {
      os_free_mem();
      plVar2[9] = 0;
    }
    kfree(plVar2);
    *(undefined8 *)(param_1 + 0x70) = 0;
    nvidia_dev_put(*(undefined4 *)(lVar3 + 0x24),puVar7,0);
    if ((puVar7 != (undefined4 *)0x0) && (cVar5 = rm_is_altstack_in_use(), cVar5 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar7);
      return;
    }
  }
  return;
}


// ===== 0010f9c0 nv_dma_buf_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010facc) */

void nv_dma_buf_release(long param_1)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  long lVar6;
  undefined4 *puVar7;
  long lVar8;
  
  plVar2 = *(long **)(param_1 + 0x70);
  if (plVar2 != (long *)0x0) {
    lVar3 = *plVar2;
    if ((char)plVar2[0xb] != '\0') {
      nv_dma_buf_put_phys_addresses(plVar2,0,(int)plVar2[3]);
    }
    cVar5 = rm_is_altstack_in_use();
    puVar7 = (undefined4 *)0x0;
    if (cVar5 != '\0') {
      puVar7 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar7 == (undefined4 *)0x0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      *puVar7 = 0x2ff0;
      *(undefined4 **)(puVar7 + 2) = puVar7 + 0xc00;
    }
    uVar1 = *(uint *)(plVar2 + 3);
    if (uVar1 != 0) {
      lVar6 = plVar2[9];
      lVar8 = (ulong)uVar1 * 0x38 + lVar6;
      do {
        if (*(long *)(lVar6 + 0x20) != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        lVar6 = lVar6 + 0x38;
      } while (lVar8 != lVar6);
    }
    nv_dma_buf_undup_mem_handles(puVar7,0,uVar1,plVar2);
    rm_dma_buf_put_client_and_device
              (puVar7,*plVar2,(int)plVar2[1],*(undefined4 *)((long)plVar2 + 0xc),(int)plVar2[2],
               plVar2[10]);
    if (plVar2[5] != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    if ((int)plVar2[3] != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    if (plVar2[9] != 0) {
      os_free_mem();
      plVar2[9] = 0;
    }
    kfree(plVar2);
    *(undefined8 *)(param_1 + 0x70) = 0;
    nvidia_dev_put(*(undefined4 *)(lVar3 + 0x24),puVar7,0);
    if ((puVar7 != (undefined4 *)0x0) && (cVar5 = rm_is_altstack_in_use(), cVar5 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar7);
      return;
    }
  }
  return;
}


// ===== 0010fb70 __pfx_nv_dma_buf_mmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010fe99) */
/* WARNING: Removing unreachable block (ram,0x0010fe67) */

ulong __pfx_nv_dma_buf_mmap(long param_1,ulong *param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  int *piVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  
  lVar20 = *(long *)(param_1 + 0x70);
  if (lVar20 == 0) {
    nv_printf(4,"NVRM: nv_dma_buf_mmap: priv == NULL.\n");
    return 0xffffffea;
  }
  lVar1 = lVar20 + 0x30;
  uVar17 = *param_2;
  uVar16 = param_2[1];
  mutex_lock(lVar1);
  if (*(char *)(lVar20 + 0x61) == '\0') {
    nv_printf(4,"NVRM: nv_dma_buf_mmap: mmap is not allowed can_mmap[%d] \n",0);
    uVar4 = 0xfffffdf4;
  }
  else {
    uVar14 = param_2[10] * 0x1000;
    uVar6 = (uVar14 - *param_2) + param_2[1];
    if (uVar6 < uVar14) {
      uVar4 = 0xffffffb5;
    }
    else {
      if (*(ulong *)(lVar20 + 0x20) < uVar6) {
        nv_printf(4,
                  "NVRM: nv_dma_buf_mmap: Vaddr_start[%llx] Vaddr_end[%llx] vm_pgoff[%llx] page_offset[%llx] page_prot[%x] total_size[%llx] \n"
                 );
      }
      else {
        uVar16 = uVar16 - uVar17;
        nv_printf(0,
                  "NVRM: nv_dma_buf_mmap: Vaddr_start[%llx] Vaddr_end[%llx] os_page_size[%llx] vm_pgoff[%llx] page_offset[%llx] page_prot[%x] total_size[%llx] total_map_len[%llx] \n"
                  ,*param_2,param_2[1],0x1000,param_2[10],uVar14,param_2[3],
                  *(ulong *)(lVar20 + 0x20),uVar16);
        if (*(uint *)(lVar20 + 0x18) != 0) {
          uVar6 = 0;
          plVar10 = (long *)(*(long *)(lVar20 + 0x48) + 0x28);
          uVar4 = 0;
          do {
            if ((uint)plVar10[1] != 0) {
              uVar14 = 0;
              uVar8 = param_2[10] << 0xc;
              piVar11 = (int *)(*plVar10 + 8);
              uVar3 = uVar4;
              do {
                uVar4 = uVar3 + *piVar11;
                if (uVar8 < uVar4) {
                  iVar5 = nv_encode_caching(param_2 + 3,*(undefined4 *)(lVar20 + 0x70),
                                            *(undefined4 *)(lVar20 + 0x78));
                  iVar19 = (int)uVar6;
                  if (iVar5 != 0) {
                    nv_printf(4,
                              "NVRM: [nv_dma_buf_mmap-failed] i[%u] cache_type[%llx] memory_type[%d] page_prot[%x] \n"
                              ,uVar6 & 0xffffffff,*(undefined4 *)(lVar20 + 0x70),
                              *(undefined4 *)(lVar20 + 0x78),param_2[3]);
                    uVar4 = 0xfffffffa;
                    goto LAB_0010fe71;
                  }
                  iVar5 = (int)param_2[5];
                  uVar6 = param_2[2];
                  if (*(char *)(lVar20 + 0x74) != '\0') {
                    param_2[3] = param_2[3] & 0xfffffffffffffffd;
                    if ((*(ulong *)(uVar6 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    if (*(int *)(uVar6 + 0x1c8) != iVar5) {
                      __vma_start_write(param_2,2);
                      iVar5 = (int)param_2[5];
                      uVar6 = param_2[2];
                    }
                    uVar13 = param_2[4] & 0xfffffffffffffffd;
                    param_2[4] = uVar13;
                    if ((*(ulong *)(uVar6 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    if (iVar5 != *(int *)(uVar6 + 0x1c8)) {
                      __vma_start_write(param_2,2);
                      uVar13 = param_2[4];
                      iVar5 = (int)param_2[5];
                      uVar6 = param_2[2];
                    }
                    param_2[4] = uVar13 & 0xffffffffffffffdf;
                  }
                  if ((*(ulong *)(uVar6 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  if (*(int *)(uVar6 + 0x1c8) != iVar5) {
                    __vma_start_write(param_2,2);
                  }
                  param_2[4] = param_2[4] | 0x4040008;
                  if (((*(int *)(lVar20 + 0x18) == 0) || (param_2[1] <= uVar17)) || (iVar19 != 0))
                  goto LAB_0010fe39;
                  lVar12 = *(long *)(lVar20 + 0x48);
                  uVar6 = *(ulong *)(lVar12 + 0x30);
                  uVar18 = (uint)uVar6;
                  if (uVar18 <= (uint)uVar14) goto LAB_0010fe39;
                  lVar9 = uVar14 << 4;
                  lVar7 = uVar8 - uVar3;
                  goto LAB_0010fda1;
                }
                uVar18 = (uint)uVar14 + 1;
                uVar14 = (ulong)uVar18;
                piVar11 = piVar11 + 4;
                uVar3 = uVar4;
              } while ((uint)plVar10[1] != uVar18);
            }
            uVar3 = (int)uVar6 + 1;
            uVar6 = (ulong)uVar3;
            plVar10 = plVar10 + 7;
          } while (uVar3 != *(uint *)(lVar20 + 0x18));
        }
        nv_printf(4,"NVRM: [nv_dma_buf_mmap-failed] Could not find first map page \n");
      }
      uVar4 = 0xffffffea;
    }
  }
LAB_0010fe71:
  uVar17 = (ulong)uVar4;
  mutex_unlock(lVar1);
  return uVar17 & 0xffffffff;
LAB_0010fda1:
  plVar10 = (long *)(lVar9 + *(long *)(lVar12 + 0x28));
  uVar13 = plVar10[1] - lVar7;
  uVar15 = *plVar10 + lVar7;
  uVar8 = uVar13;
  if (uVar16 <= uVar13) {
    uVar8 = uVar16;
  }
  uVar4 = remap_pfn_range(param_2,uVar17,uVar15 >> 0xc,uVar8,param_2[3],uVar15,lVar9,uVar15);
  if (uVar4 != 0) {
    nv_printf(4,"NVRM: nv_dma_buf_mmap: remap_pfn_range - failed\n",uVar4);
    goto LAB_0010fe71;
  }
  uVar4 = (int)uVar14 + 1;
  nv_printf(0,
            "NVRM: nv_dma_buf_mmap: index[%u] range_count[%u] Vaddr[%llx] page_prot[%x] phyAddr[%llx] mapLen[%llx] len[%llx] total_map_len[%llx] \n"
            ,uVar14,uVar6 & 0xffffffff,uVar17,param_2[3],uVar15,uVar8,uVar13,uVar16);
  if (uVar18 == uVar4) {
LAB_0010fe39:
    mutex_unlock(lVar1);
    return 0;
  }
  lVar9 = lVar9 + 0x10;
  uVar16 = uVar16 - uVar8;
  uVar17 = uVar17 + uVar8;
  lVar7 = 0;
  if (param_2[1] <= uVar17) goto LAB_0010fe39;
  lVar12 = *(long *)(lVar20 + 0x48);
  uVar14 = (ulong)uVar4;
  goto LAB_0010fda1;
}


// ===== 0010fb80 nv_dma_buf_mmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010fe99) */
/* WARNING: Removing unreachable block (ram,0x0010fe67) */

ulong nv_dma_buf_mmap(long param_1,ulong *param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  int *piVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  
  lVar20 = *(long *)(param_1 + 0x70);
  if (lVar20 == 0) {
    nv_printf(4,"NVRM: nv_dma_buf_mmap: priv == NULL.\n");
    return 0xffffffea;
  }
  lVar1 = lVar20 + 0x30;
  uVar17 = *param_2;
  uVar16 = param_2[1];
  mutex_lock(lVar1);
  if (*(char *)(lVar20 + 0x61) == '\0') {
    nv_printf(4,"NVRM: nv_dma_buf_mmap: mmap is not allowed can_mmap[%d] \n",0);
    uVar4 = 0xfffffdf4;
  }
  else {
    uVar14 = param_2[10] * 0x1000;
    uVar6 = (uVar14 - *param_2) + param_2[1];
    if (uVar6 < uVar14) {
      uVar4 = 0xffffffb5;
    }
    else {
      if (*(ulong *)(lVar20 + 0x20) < uVar6) {
        nv_printf(4,
                  "NVRM: nv_dma_buf_mmap: Vaddr_start[%llx] Vaddr_end[%llx] vm_pgoff[%llx] page_offset[%llx] page_prot[%x] total_size[%llx] \n"
                 );
      }
      else {
        uVar16 = uVar16 - uVar17;
        nv_printf(0,
                  "NVRM: nv_dma_buf_mmap: Vaddr_start[%llx] Vaddr_end[%llx] os_page_size[%llx] vm_pgoff[%llx] page_offset[%llx] page_prot[%x] total_size[%llx] total_map_len[%llx] \n"
                  ,*param_2,param_2[1],0x1000,param_2[10],uVar14,param_2[3],
                  *(ulong *)(lVar20 + 0x20),uVar16);
        if (*(uint *)(lVar20 + 0x18) != 0) {
          uVar6 = 0;
          plVar10 = (long *)(*(long *)(lVar20 + 0x48) + 0x28);
          uVar4 = 0;
          do {
            if ((uint)plVar10[1] != 0) {
              uVar14 = 0;
              uVar8 = param_2[10] << 0xc;
              piVar11 = (int *)(*plVar10 + 8);
              uVar3 = uVar4;
              do {
                uVar4 = uVar3 + *piVar11;
                if (uVar8 < uVar4) {
                  iVar5 = nv_encode_caching(param_2 + 3,*(undefined4 *)(lVar20 + 0x70),
                                            *(undefined4 *)(lVar20 + 0x78));
                  iVar19 = (int)uVar6;
                  if (iVar5 != 0) {
                    nv_printf(4,
                              "NVRM: [nv_dma_buf_mmap-failed] i[%u] cache_type[%llx] memory_type[%d] page_prot[%x] \n"
                              ,uVar6 & 0xffffffff,*(undefined4 *)(lVar20 + 0x70),
                              *(undefined4 *)(lVar20 + 0x78),param_2[3]);
                    uVar4 = 0xfffffffa;
                    goto LAB_0010fe71;
                  }
                  iVar5 = (int)param_2[5];
                  uVar6 = param_2[2];
                  if (*(char *)(lVar20 + 0x74) != '\0') {
                    param_2[3] = param_2[3] & 0xfffffffffffffffd;
                    if ((*(ulong *)(uVar6 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    if (*(int *)(uVar6 + 0x1c8) != iVar5) {
                      __vma_start_write(param_2,2);
                      iVar5 = (int)param_2[5];
                      uVar6 = param_2[2];
                    }
                    uVar13 = param_2[4] & 0xfffffffffffffffd;
                    param_2[4] = uVar13;
                    if ((*(ulong *)(uVar6 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                    if (iVar5 != *(int *)(uVar6 + 0x1c8)) {
                      __vma_start_write(param_2,2);
                      uVar13 = param_2[4];
                      iVar5 = (int)param_2[5];
                      uVar6 = param_2[2];
                    }
                    param_2[4] = uVar13 & 0xffffffffffffffdf;
                  }
                  if ((*(ulong *)(uVar6 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)invalidInstructionException();
                    (*pcVar2)();
                  }
                  if (*(int *)(uVar6 + 0x1c8) != iVar5) {
                    __vma_start_write(param_2,2);
                  }
                  param_2[4] = param_2[4] | 0x4040008;
                  if (((*(int *)(lVar20 + 0x18) == 0) || (param_2[1] <= uVar17)) || (iVar19 != 0))
                  goto LAB_0010fe39;
                  lVar12 = *(long *)(lVar20 + 0x48);
                  uVar6 = *(ulong *)(lVar12 + 0x30);
                  uVar18 = (uint)uVar6;
                  if (uVar18 <= (uint)uVar14) goto LAB_0010fe39;
                  lVar9 = uVar14 << 4;
                  lVar7 = uVar8 - uVar3;
                  goto LAB_0010fda1;
                }
                uVar18 = (uint)uVar14 + 1;
                uVar14 = (ulong)uVar18;
                piVar11 = piVar11 + 4;
                uVar3 = uVar4;
              } while ((uint)plVar10[1] != uVar18);
            }
            uVar3 = (int)uVar6 + 1;
            uVar6 = (ulong)uVar3;
            plVar10 = plVar10 + 7;
          } while (uVar3 != *(uint *)(lVar20 + 0x18));
        }
        nv_printf(4,"NVRM: [nv_dma_buf_mmap-failed] Could not find first map page \n");
      }
      uVar4 = 0xffffffea;
    }
  }
LAB_0010fe71:
  uVar17 = (ulong)uVar4;
  mutex_unlock(lVar1);
  return uVar17 & 0xffffffff;
LAB_0010fda1:
  plVar10 = (long *)(lVar9 + *(long *)(lVar12 + 0x28));
  uVar13 = plVar10[1] - lVar7;
  uVar15 = *plVar10 + lVar7;
  uVar8 = uVar13;
  if (uVar16 <= uVar13) {
    uVar8 = uVar16;
  }
  uVar4 = remap_pfn_range(param_2,uVar17,uVar15 >> 0xc,uVar8,param_2[3],uVar15,lVar9,uVar15);
  if (uVar4 != 0) {
    nv_printf(4,"NVRM: nv_dma_buf_mmap: remap_pfn_range - failed\n",uVar4);
    goto LAB_0010fe71;
  }
  uVar4 = (int)uVar14 + 1;
  nv_printf(0,
            "NVRM: nv_dma_buf_mmap: index[%u] range_count[%u] Vaddr[%llx] page_prot[%x] phyAddr[%llx] mapLen[%llx] len[%llx] total_map_len[%llx] \n"
            ,uVar14,uVar6 & 0xffffffff,uVar17,param_2[3],uVar15,uVar8,uVar13,uVar16);
  if (uVar18 == uVar4) {
LAB_0010fe39:
    mutex_unlock(lVar1);
    return 0;
  }
  lVar9 = lVar9 + 0x10;
  uVar16 = uVar16 - uVar8;
  uVar17 = uVar17 + uVar8;
  lVar7 = 0;
  if (param_2[1] <= uVar17) goto LAB_0010fe39;
  lVar12 = *(long *)(lVar20 + 0x48);
  uVar14 = (ulong)uVar4;
  goto LAB_0010fda1;
}


// ===== 00110010 __pfx_nv_dma_buf_get_phys_addresses =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001101f0) */
/* WARNING: Removing unreachable block (ram,0x0011034c) */
/* WARNING: Removing unreachable block (ram,0x00110253) */

int __pfx_nv_dma_buf_get_phys_addresses(undefined8 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  long *plVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  undefined4 *puStack_50;
  
  if (param_3 == 0) {
    return 0;
  }
  bVar3 = false;
  uVar1 = param_2 + param_3;
  lVar9 = param_1[9];
  uVar8 = param_2;
  do {
    uVar7 = (ulong)uVar8;
    plVar2 = (long *)(lVar9 + 0x20 + uVar7 * 0x38);
    *plVar2 = *plVar2 + 1;
    lVar9 = param_1[9];
    uVar8 = uVar8 + 1;
    bVar3 = (bool)(bVar3 | *(long *)(lVar9 + 0x20 + uVar7 * 0x38) == 1);
  } while (uVar1 != uVar8);
  if (!bVar3) {
    return 0;
  }
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 == '\0') {
    if (*(char *)(param_1 + 0xb) == '\0') {
      iVar5 = rm_acquire_api_lock(0);
      if (iVar5 != 0) goto LAB_00110320;
      puStack_50 = (undefined4 *)0x0;
LAB_00110281:
      iVar5 = rm_acquire_gpu_lock(puStack_50,*param_1);
      if (iVar5 == 0) goto LAB_001100eb;
LAB_001102d7:
      rm_release_api_lock(puStack_50);
    }
    else {
      puStack_50 = (undefined4 *)0x0;
      bVar3 = false;
LAB_001100eb:
      iVar10 = 0;
      while ((puVar6 = (undefined4 *)((ulong)(param_2 + iVar10) * 0x38 + param_1[9]),
             1 < *(ulong *)(puVar6 + 8) ||
             (iVar5 = rm_dma_buf_map_mem_handle
                                (puStack_50,*param_1,*(undefined4 *)(param_1 + 1),*puVar6,
                                 *(undefined8 *)(puVar6 + 2),*(undefined8 *)(puVar6 + 4),
                                 *(undefined1 *)((long)param_1 + 0x59),*(undefined8 *)(puVar6 + 6),
                                 *(undefined1 *)(param_1 + 0xb),puVar6 + 10), iVar5 == 0))) {
        iVar10 = iVar10 + 1;
        if (param_3 == iVar10) {
          if (bVar3) {
            rm_release_gpu_lock(puStack_50,*param_1);
            rm_release_api_lock(puStack_50);
          }
          if ((puStack_50 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0'))
          {
            kmem_cache_free(nvidia_stack_t_cache,puStack_50);
          }
          return 0;
        }
      }
      nv_put_phys_addresses(puStack_50,param_1,param_2,iVar10);
      if (bVar3) {
        rm_release_gpu_lock(puStack_50,*param_1);
        goto LAB_001102d7;
      }
    }
    if (puStack_50 == (undefined4 *)0x0) goto LAB_00110320;
  }
  else {
    puStack_50 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puStack_50 == (undefined4 *)0x0) {
      iVar5 = 0x51;
      goto LAB_00110320;
    }
    *puStack_50 = 0x2ff0;
    cVar4 = *(char *)(param_1 + 0xb);
    *(undefined4 **)(puStack_50 + 2) = puStack_50 + 0xc00;
    if (cVar4 != '\0') {
      bVar3 = false;
      goto LAB_001100eb;
    }
    iVar5 = rm_acquire_api_lock(puStack_50);
    if (iVar5 == 0) goto LAB_00110281;
  }
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 != '\0') {
    kmem_cache_free(nvidia_stack_t_cache,puStack_50);
  }
LAB_00110320:
  do {
    uVar7 = (ulong)param_2;
    param_2 = param_2 + 1;
    *(undefined8 *)(uVar7 * 0x38 + param_1[9] + 0x20) = 0;
  } while (uVar1 != param_2);
  return iVar5;
}


// ===== 00110020 nv_dma_buf_get_phys_addresses =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001101f0) */
/* WARNING: Removing unreachable block (ram,0x0011034c) */
/* WARNING: Removing unreachable block (ram,0x00110253) */

int nv_dma_buf_get_phys_addresses(undefined8 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  long *plVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  undefined4 *local_50;
  
  if (param_3 == 0) {
    return 0;
  }
  bVar3 = false;
  uVar1 = param_2 + param_3;
  lVar9 = param_1[9];
  uVar8 = param_2;
  do {
    uVar7 = (ulong)uVar8;
    plVar2 = (long *)(lVar9 + 0x20 + uVar7 * 0x38);
    *plVar2 = *plVar2 + 1;
    lVar9 = param_1[9];
    uVar8 = uVar8 + 1;
    bVar3 = (bool)(bVar3 | *(long *)(lVar9 + 0x20 + uVar7 * 0x38) == 1);
  } while (uVar1 != uVar8);
  if (!bVar3) {
    return 0;
  }
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 == '\0') {
    if (*(char *)(param_1 + 0xb) == '\0') {
      iVar5 = rm_acquire_api_lock(0);
      if (iVar5 != 0) goto LAB_00110320;
      local_50 = (undefined4 *)0x0;
LAB_00110281:
      iVar5 = rm_acquire_gpu_lock(local_50,*param_1);
      if (iVar5 == 0) goto LAB_001100eb;
LAB_001102d7:
      rm_release_api_lock(local_50);
    }
    else {
      local_50 = (undefined4 *)0x0;
      bVar3 = false;
LAB_001100eb:
      iVar10 = 0;
      while ((puVar6 = (undefined4 *)((ulong)(param_2 + iVar10) * 0x38 + param_1[9]),
             1 < *(ulong *)(puVar6 + 8) ||
             (iVar5 = rm_dma_buf_map_mem_handle
                                (local_50,*param_1,*(undefined4 *)(param_1 + 1),*puVar6,
                                 *(undefined8 *)(puVar6 + 2),*(undefined8 *)(puVar6 + 4),
                                 *(undefined1 *)((long)param_1 + 0x59),*(undefined8 *)(puVar6 + 6),
                                 *(undefined1 *)(param_1 + 0xb),puVar6 + 10), iVar5 == 0))) {
        iVar10 = iVar10 + 1;
        if (param_3 == iVar10) {
          if (bVar3) {
            rm_release_gpu_lock(local_50,*param_1);
            rm_release_api_lock(local_50);
          }
          if ((local_50 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
            kmem_cache_free(nvidia_stack_t_cache,local_50);
          }
          return 0;
        }
      }
      nv_put_phys_addresses(local_50,param_1,param_2,iVar10);
      if (bVar3) {
        rm_release_gpu_lock(local_50,*param_1);
        goto LAB_001102d7;
      }
    }
    if (local_50 == (undefined4 *)0x0) goto LAB_00110320;
  }
  else {
    local_50 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (local_50 == (undefined4 *)0x0) {
      iVar5 = 0x51;
      goto LAB_00110320;
    }
    *local_50 = 0x2ff0;
    cVar4 = *(char *)(param_1 + 0xb);
    *(undefined4 **)(local_50 + 2) = local_50 + 0xc00;
    if (cVar4 != '\0') {
      bVar3 = false;
      goto LAB_001100eb;
    }
    iVar5 = rm_acquire_api_lock(local_50);
    if (iVar5 == 0) goto LAB_00110281;
  }
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 != '\0') {
    kmem_cache_free(nvidia_stack_t_cache,local_50);
  }
LAB_00110320:
  do {
    uVar7 = (ulong)param_2;
    param_2 = param_2 + 1;
    *(undefined8 *)(uVar7 * 0x38 + param_1[9] + 0x20) = 0;
  } while (uVar1 != param_2);
  return iVar5;
}


// ===== 001103c0 __pfx_nv_dma_buf_map =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011067d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * __pfx_nv_dma_buf_map(long *param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  code *pcVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined8 *puVar12;
  ulong *puVar13;
  long lVar14;
  ulong uVar15;
  ulong *puVar16;
  long lVar17;
  long lVar18;
  int iVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  long in_GS_OFFSET;
  long lStack_a0;
  uint uStack_6c;
  ulong uStack_68;
  ulong uStack_60;
  undefined8 uStack_58;
  long lStack_50;
  long lStack_48;
  
  lStack_48 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  plVar2 = *(long **)(*param_1 + 0x70);
  plVar1 = plVar2 + 6;
  mutex_lock(plVar1);
  if (((int)plVar2[3] == *(int *)((long)plVar2 + 0x14)) &&
     (((char)plVar2[0xb] != '\0' || (iVar9 = nv_dma_buf_get_phys_addresses(plVar2,0), iVar9 == 0))))
  {
    uVar7 = _nr_cpu_ids;
    lVar3 = param_1[1];
    if ((*(char *)(*plVar2 + 0x326) == '\0') || (*(char *)((long)plVar2 + 0x59) != '\0')) {
      uStack_60 = 0;
      uStack_58 = *(undefined8 *)(lVar3 + 0x260);
      uStack_6c = 0;
      lStack_50 = lVar3;
      uVar8 = nv_dma_buf_get_sg_count_constprop_0_isra_0
                        (*(undefined8 *)(lVar3 + 0x280),plVar2,&uStack_6c);
      puVar12 = (undefined8 *)__kmalloc_cache_noprof(uVar7,0x2dc0,0x10);
      if (puVar12 == (undefined8 *)0x0) goto LAB_00110643;
      iVar9 = sg_alloc_table(puVar12,uVar8,0xcc0);
      if (iVar9 != 0) goto LAB_0011063b;
      puVar16 = (ulong *)*puVar12;
      iVar9 = 0;
      if ((int)plVar2[3] != 0) {
        lVar17 = 0;
        iVar9 = 0;
        uVar11 = 0;
        do {
          lVar18 = plVar2[9];
          iVar19 = (int)*(undefined8 *)(lVar18 + 0x30 + lVar17);
          if (iVar19 != 0) {
            lStack_a0 = 0;
            do {
              puVar13 = (ulong *)(lStack_a0 + *(long *)(lVar18 + 0x28 + lVar17));
              uVar23 = puVar13[1];
              if (uVar23 != 0) {
                uVar22 = *puVar13;
                uVar15 = (ulong)uStack_6c;
                do {
                  uStack_68 = uVar22;
                  if (puVar16 == (ulong *)0x0) {
LAB_0011061e:
                    *(int *)(puVar12 + 1) = iVar9;
                    nv_dma_buf_unmap_pfns_isra_0(lVar3,puVar12,*(undefined1 *)((long)plVar2 + 0x5a))
                    ;
                    goto LAB_00110633;
                  }
                  uVar20 = uVar15;
                  if (uVar23 <= uVar15) {
                    uVar20 = uVar23;
                  }
                  if ((*(char *)((long)plVar2 + 0x5a) == '\0') &&
                     (iVar10 = nv_dma_map_peer(&uStack_60,*(undefined8 *)(*plVar2 + 0x2e0),1,
                                               uVar20 >> 0xc & 0xfffff,&uStack_68), iVar10 != 0))
                  goto LAB_0011061e;
                  uVar4 = *puVar16;
                  *(int *)((long)puVar16 + 0xc) = (int)uVar20;
                  uVar23 = uVar23 - uVar20;
                  iVar9 = iVar9 + 1;
                  *(undefined4 *)(puVar16 + 1) = 0;
                  *(int *)(puVar16 + 3) = (int)uVar20;
                  *puVar16 = (ulong)((uint)uVar4 & 3);
                  puVar16[2] = uStack_68;
                  if ((uVar4 & 2) != 0) {
                    if (uVar23 != 0) goto LAB_0011061e;
                    puVar16 = (ulong *)0x0;
                    break;
                  }
                  puVar13 = puVar16 + 4;
                  uVar22 = uVar22 + uVar20;
                  puVar16 = puVar16 + 4;
                  if ((*puVar13 & 1) != 0) {
                    puVar16 = (ulong *)(*puVar13 & 0xfffffffffffffffc);
                  }
                } while (uVar23 != 0);
              }
              if (lStack_a0 == (ulong)(iVar19 - 1) << 4) break;
              lStack_a0 = lStack_a0 + 0x10;
              lVar18 = plVar2[9];
            } while( true );
          }
          uVar11 = uVar11 + 1;
          lVar17 = lVar17 + 0x38;
        } while (uVar11 < *(uint *)(plVar2 + 3));
      }
      if (puVar16 != (ulong *)0x0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      *(int *)(puVar12 + 1) = iVar9;
      if (iVar9 != *(int *)((long)puVar12 + 0xc)) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
LAB_00110889:
      mutex_unlock(plVar1);
      goto LAB_00110659;
    }
    uStack_60 = uStack_60 & 0xffffffff00000000;
    uVar8 = nv_dma_buf_get_sg_count_constprop_0_isra_0
                      (*(undefined8 *)(lVar3 + 0x280),plVar2,&uStack_60);
    puVar12 = (undefined8 *)__kmalloc_cache_noprof(uVar7,0x2dc0,0x10);
    if (puVar12 != (undefined8 *)0x0) {
      iVar9 = sg_alloc_table(puVar12,uVar8,0xcc0);
      if (iVar9 == 0) {
        lVar17 = 0;
        bVar6 = false;
        if (*(char *)(*plVar2 + 0x328) == '\x02') {
          lVar17 = nv_dma_get_dev_pagemap();
          bVar6 = true;
          if (lVar17 != 0) goto LAB_0011072a;
          nv_printf(4,"NVRM: Failed to get a reference on dev_pagemap in CDMM(driver) mode\n");
        }
        else {
LAB_0011072a:
          puVar16 = (ulong *)*puVar12;
          puVar13 = puVar16;
          if ((int)plVar2[3] != 0) {
            uVar11 = 0;
            lVar18 = 0;
            do {
              lVar14 = plVar2[9];
              iVar9 = (int)*(undefined8 *)(lVar14 + 0x30 + lVar18);
              if (iVar9 != 0) {
                lVar21 = 0;
                while( true ) {
                  puVar13 = (ulong *)(*(long *)(lVar14 + 0x28 + lVar18) + lVar21);
                  uVar23 = puVar13[1];
                  if (uVar23 != 0) {
                    uVar22 = *puVar13;
                    do {
                      uVar15 = (uVar22 >> 0xc) * 0x40 + _vmemmap_base;
                      if ((uVar15 == 0) || (puVar16 == (ulong *)0x0)) goto LAB_00110813;
                      if ((uVar15 & 3) != 0) {
                    /* WARNING: Does not return */
                        pcVar5 = (code *)invalidInstructionException();
                        (*pcVar5)();
                      }
                      uVar20 = uVar23;
                      if ((uStack_60 & 0xffffffff) <= uVar23) {
                        uVar20 = uStack_60 & 0xffffffff;
                      }
                      uVar15 = uVar15 | (uint)*puVar16 & 3;
                      *(int *)((long)puVar16 + 0xc) = (int)uVar20;
                      *puVar16 = uVar15;
                      uVar23 = uVar23 - uVar20;
                      *(uint *)(puVar16 + 1) = (uint)uVar22 & 0xfff;
                      if ((uVar15 & 2) == 0) {
                        puVar13 = puVar16 + 4;
                        puVar16 = puVar16 + 4;
                        if ((*puVar13 & 1) != 0) {
                          puVar16 = (ulong *)(*puVar13 & 0xfffffffffffffffc);
                        }
                      }
                      else {
                        puVar16 = (ulong *)0x0;
                      }
                      uVar22 = uVar22 + uVar20;
                    } while (uVar23 != 0);
                  }
                  if (lVar21 == (ulong)(iVar9 - 1) << 4) break;
                  lVar14 = plVar2[9];
                  lVar21 = lVar21 + 0x10;
                }
              }
              uVar11 = uVar11 + 1;
              lVar18 = lVar18 + 0x38;
            } while (uVar11 < *(uint *)(plVar2 + 3));
            puVar13 = (ulong *)*puVar12;
          }
          if (puVar16 != (ulong *)0x0) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          iVar9 = dma_map_sg_attrs(lVar3,puVar13,*(undefined4 *)((long)puVar12 + 0xc),0,0x20);
          if (0 < iVar9) {
            *(int *)(puVar12 + 1) = iVar9;
            if (bVar6) {
              puVar16 = (ulong *)*puVar12;
              uVar11 = 0;
              do {
                uVar23 = *puVar16;
                uVar11 = uVar11 + 1;
                *puVar16 = (ulong)((uint)uVar23 & 3);
                if ((uVar23 & 2) == 0) {
                  puVar13 = puVar16 + 4;
                  puVar16 = puVar16 + 4;
                  if ((*puVar13 & 1) != 0) {
                    puVar16 = (ulong *)(*puVar13 & 0xfffffffffffffffc);
                  }
                }
                else {
                  puVar16 = (ulong *)0x0;
                }
              } while (uVar11 < *(uint *)(puVar12 + 1));
              nv_dma_put_dev_pagemap(lVar17);
            }
            goto LAB_00110889;
          }
LAB_00110813:
          if (bVar6) {
            nv_dma_put_dev_pagemap(lVar17);
          }
        }
LAB_00110633:
        sg_free_table(puVar12);
      }
LAB_0011063b:
      kfree(puVar12);
    }
LAB_00110643:
    if ((char)plVar2[0xb] == '\0') {
      nv_dma_buf_put_phys_addresses(plVar2,0,(int)plVar2[3]);
    }
  }
  puVar12 = (undefined8 *)0x0;
  mutex_unlock(plVar1);
LAB_00110659:
  if (lStack_48 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar12;
}


// ===== 001103d0 nv_dma_buf_map =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011067d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * nv_dma_buf_map(long *param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  code *pcVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined8 *puVar12;
  ulong *puVar13;
  long lVar14;
  ulong uVar15;
  ulong *puVar16;
  long lVar17;
  long lVar18;
  int iVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  long in_GS_OFFSET;
  long local_a0;
  uint local_6c;
  ulong local_68;
  ulong local_60;
  undefined8 local_58;
  long local_50;
  long local_48;
  
  local_48 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  plVar2 = *(long **)(*param_1 + 0x70);
  plVar1 = plVar2 + 6;
  mutex_lock(plVar1);
  if (((int)plVar2[3] == *(int *)((long)plVar2 + 0x14)) &&
     (((char)plVar2[0xb] != '\0' || (iVar9 = nv_dma_buf_get_phys_addresses(plVar2,0), iVar9 == 0))))
  {
    uVar7 = _nr_cpu_ids;
    lVar3 = param_1[1];
    if ((*(char *)(*plVar2 + 0x326) == '\0') || (*(char *)((long)plVar2 + 0x59) != '\0')) {
      local_60 = 0;
      local_58 = *(undefined8 *)(lVar3 + 0x260);
      local_6c = 0;
      local_50 = lVar3;
      uVar8 = nv_dma_buf_get_sg_count_constprop_0_isra_0
                        (*(undefined8 *)(lVar3 + 0x280),plVar2,&local_6c);
      puVar12 = (undefined8 *)__kmalloc_cache_noprof(uVar7,0x2dc0,0x10);
      if (puVar12 == (undefined8 *)0x0) goto LAB_00110643;
      iVar9 = sg_alloc_table(puVar12,uVar8,0xcc0);
      if (iVar9 != 0) goto LAB_0011063b;
      puVar16 = (ulong *)*puVar12;
      iVar9 = 0;
      if ((int)plVar2[3] != 0) {
        lVar17 = 0;
        iVar9 = 0;
        uVar11 = 0;
        do {
          lVar18 = plVar2[9];
          iVar19 = (int)*(undefined8 *)(lVar18 + 0x30 + lVar17);
          if (iVar19 != 0) {
            local_a0 = 0;
            do {
              puVar13 = (ulong *)(local_a0 + *(long *)(lVar18 + 0x28 + lVar17));
              uVar23 = puVar13[1];
              if (uVar23 != 0) {
                uVar22 = *puVar13;
                uVar15 = (ulong)local_6c;
                do {
                  local_68 = uVar22;
                  if (puVar16 == (ulong *)0x0) {
LAB_0011061e:
                    *(int *)(puVar12 + 1) = iVar9;
                    nv_dma_buf_unmap_pfns_isra_0(lVar3,puVar12,*(undefined1 *)((long)plVar2 + 0x5a))
                    ;
                    goto LAB_00110633;
                  }
                  uVar20 = uVar15;
                  if (uVar23 <= uVar15) {
                    uVar20 = uVar23;
                  }
                  if ((*(char *)((long)plVar2 + 0x5a) == '\0') &&
                     (iVar10 = nv_dma_map_peer(&local_60,*(undefined8 *)(*plVar2 + 0x2e0),1,
                                               uVar20 >> 0xc & 0xfffff,&local_68), iVar10 != 0))
                  goto LAB_0011061e;
                  uVar4 = *puVar16;
                  *(int *)((long)puVar16 + 0xc) = (int)uVar20;
                  uVar23 = uVar23 - uVar20;
                  iVar9 = iVar9 + 1;
                  *(undefined4 *)(puVar16 + 1) = 0;
                  *(int *)(puVar16 + 3) = (int)uVar20;
                  *puVar16 = (ulong)((uint)uVar4 & 3);
                  puVar16[2] = local_68;
                  if ((uVar4 & 2) != 0) {
                    if (uVar23 != 0) goto LAB_0011061e;
                    puVar16 = (ulong *)0x0;
                    break;
                  }
                  puVar13 = puVar16 + 4;
                  uVar22 = uVar22 + uVar20;
                  puVar16 = puVar16 + 4;
                  if ((*puVar13 & 1) != 0) {
                    puVar16 = (ulong *)(*puVar13 & 0xfffffffffffffffc);
                  }
                } while (uVar23 != 0);
              }
              if (local_a0 == (ulong)(iVar19 - 1) << 4) break;
              local_a0 = local_a0 + 0x10;
              lVar18 = plVar2[9];
            } while( true );
          }
          uVar11 = uVar11 + 1;
          lVar17 = lVar17 + 0x38;
        } while (uVar11 < *(uint *)(plVar2 + 3));
      }
      if (puVar16 != (ulong *)0x0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
      *(int *)(puVar12 + 1) = iVar9;
      if (iVar9 != *(int *)((long)puVar12 + 0xc)) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)invalidInstructionException();
        (*pcVar5)();
      }
LAB_00110889:
      mutex_unlock(plVar1);
      goto LAB_00110659;
    }
    local_60 = local_60 & 0xffffffff00000000;
    uVar8 = nv_dma_buf_get_sg_count_constprop_0_isra_0
                      (*(undefined8 *)(lVar3 + 0x280),plVar2,&local_60);
    puVar12 = (undefined8 *)__kmalloc_cache_noprof(uVar7,0x2dc0,0x10);
    if (puVar12 != (undefined8 *)0x0) {
      iVar9 = sg_alloc_table(puVar12,uVar8,0xcc0);
      if (iVar9 == 0) {
        lVar17 = 0;
        bVar6 = false;
        if (*(char *)(*plVar2 + 0x328) == '\x02') {
          lVar17 = nv_dma_get_dev_pagemap();
          bVar6 = true;
          if (lVar17 != 0) goto LAB_0011072a;
          nv_printf(4,"NVRM: Failed to get a reference on dev_pagemap in CDMM(driver) mode\n");
        }
        else {
LAB_0011072a:
          puVar16 = (ulong *)*puVar12;
          puVar13 = puVar16;
          if ((int)plVar2[3] != 0) {
            uVar11 = 0;
            lVar18 = 0;
            do {
              lVar14 = plVar2[9];
              iVar9 = (int)*(undefined8 *)(lVar14 + 0x30 + lVar18);
              if (iVar9 != 0) {
                lVar21 = 0;
                while( true ) {
                  puVar13 = (ulong *)(*(long *)(lVar14 + 0x28 + lVar18) + lVar21);
                  uVar23 = puVar13[1];
                  if (uVar23 != 0) {
                    uVar22 = *puVar13;
                    do {
                      uVar15 = (uVar22 >> 0xc) * 0x40 + _vmemmap_base;
                      if ((uVar15 == 0) || (puVar16 == (ulong *)0x0)) goto LAB_00110813;
                      if ((uVar15 & 3) != 0) {
                    /* WARNING: Does not return */
                        pcVar5 = (code *)invalidInstructionException();
                        (*pcVar5)();
                      }
                      uVar20 = uVar23;
                      if ((local_60 & 0xffffffff) <= uVar23) {
                        uVar20 = local_60 & 0xffffffff;
                      }
                      uVar15 = uVar15 | (uint)*puVar16 & 3;
                      *(int *)((long)puVar16 + 0xc) = (int)uVar20;
                      *puVar16 = uVar15;
                      uVar23 = uVar23 - uVar20;
                      *(uint *)(puVar16 + 1) = (uint)uVar22 & 0xfff;
                      if ((uVar15 & 2) == 0) {
                        puVar13 = puVar16 + 4;
                        puVar16 = puVar16 + 4;
                        if ((*puVar13 & 1) != 0) {
                          puVar16 = (ulong *)(*puVar13 & 0xfffffffffffffffc);
                        }
                      }
                      else {
                        puVar16 = (ulong *)0x0;
                      }
                      uVar22 = uVar22 + uVar20;
                    } while (uVar23 != 0);
                  }
                  if (lVar21 == (ulong)(iVar9 - 1) << 4) break;
                  lVar14 = plVar2[9];
                  lVar21 = lVar21 + 0x10;
                }
              }
              uVar11 = uVar11 + 1;
              lVar18 = lVar18 + 0x38;
            } while (uVar11 < *(uint *)(plVar2 + 3));
            puVar13 = (ulong *)*puVar12;
          }
          if (puVar16 != (ulong *)0x0) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          iVar9 = dma_map_sg_attrs(lVar3,puVar13,*(undefined4 *)((long)puVar12 + 0xc),0,0x20);
          if (0 < iVar9) {
            *(int *)(puVar12 + 1) = iVar9;
            if (bVar6) {
              puVar16 = (ulong *)*puVar12;
              uVar11 = 0;
              do {
                uVar23 = *puVar16;
                uVar11 = uVar11 + 1;
                *puVar16 = (ulong)((uint)uVar23 & 3);
                if ((uVar23 & 2) == 0) {
                  puVar13 = puVar16 + 4;
                  puVar16 = puVar16 + 4;
                  if ((*puVar13 & 1) != 0) {
                    puVar16 = (ulong *)(*puVar13 & 0xfffffffffffffffc);
                  }
                }
                else {
                  puVar16 = (ulong *)0x0;
                }
              } while (uVar11 < *(uint *)(puVar12 + 1));
              nv_dma_put_dev_pagemap(lVar17);
            }
            goto LAB_00110889;
          }
LAB_00110813:
          if (bVar6) {
            nv_dma_put_dev_pagemap(lVar17);
          }
        }
LAB_00110633:
        sg_free_table(puVar12);
      }
LAB_0011063b:
      kfree(puVar12);
    }
LAB_00110643:
    if ((char)plVar2[0xb] == '\0') {
      nv_dma_buf_put_phys_addresses(plVar2,0,(int)plVar2[3]);
    }
  }
  puVar12 = (undefined8 *)0x0;
  mutex_unlock(plVar1);
LAB_00110659:
  if (local_48 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar12;
}


// ===== 001109a0 __pfx_nv_dma_buf_export =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00110b22) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nv_dma_buf_export(long param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long *plVar8;
  undefined4 *puVar9;
  long lVar10;
  undefined4 *puVar11;
  long in_GS_OFFSET;
  byte bVar12;
  char *pcStack_68;
  undefined1 *puStack_60;
  undefined1 *puStack_58;
  undefined8 uStack_50;
  undefined4 uStack_48;
  undefined4 auStack_44 [3];
  long *plStack_38;
  long lStack_30;
  
  bVar12 = 0;
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (((((param_2 == (int *)0x0) || (*(long *)(param_2 + 6) == 0)) ||
       (uVar1 = param_2[3], uVar1 == 0)) ||
      ((uVar2 = param_2[2], 0x80 < uVar1 || uVar2 == 0 || (uVar2 < uVar1)))) ||
     (1 < *(byte *)(param_2 + 8))) {
LAB_00110b02:
    iVar5 = 0x1f;
    goto LAB_00110b08;
  }
  if (*param_2 != -1) {
    if (*param_2 < 0) goto LAB_00110b02;
    uVar7 = dma_buf_get();
    if (uVar7 < 0xfffffffffffff001) {
      if (*(undefined1 **)(uVar7 + 0x20) == nv_dma_buf_ops) {
        lVar10 = *(long *)(uVar7 + 0x70);
        if (lVar10 != 0) {
          iVar5 = mutex_lock_interruptible(lVar10 + 0x30);
          if (iVar5 == 0) {
            if (((*(uint *)(lVar10 + 0x14) < (uint)param_2[3]) ||
                (*(uint *)(lVar10 + 0x14) - param_2[3] < (uint)param_2[4])) ||
               (((char)param_2[8] != *(char *)(lVar10 + 0x59) ||
                ((ulong)*(byte *)((long)param_2 + 0x21) != *(ulong *)(lVar10 + 0x68))))) {
              iVar5 = 0x1f;
            }
            else {
              cVar4 = rm_is_altstack_in_use();
              if (cVar4 == '\0') {
                iVar5 = nv_dma_buf_dup_mem_handles(0,lVar10,param_2);
                if (iVar5 == 0) {
                  if (*(char *)(lVar10 + 0x58) != '\0') {
                    puVar9 = (undefined4 *)0x0;
LAB_00111053:
                    iVar5 = nv_dma_buf_get_phys_addresses(lVar10,param_2[4],param_2[3]);
                    if (iVar5 != 0) {
                      nv_dma_buf_undup_mem_handles(puVar9,param_2[4],param_2[3],lVar10);
                      if (puVar9 != (undefined4 *)0x0) goto LAB_001111c6;
                      goto LAB_00110ad1;
                    }
                    if (puVar9 != (undefined4 *)0x0) goto LAB_00111141;
                  }
LAB_0011109a:
                  mutex_unlock(lVar10 + 0x30);
                  dma_buf_put(uVar7);
                  iVar5 = 0;
                  goto LAB_00110b08;
                }
              }
              else {
                puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
                if (puVar9 == (undefined4 *)0x0) {
                  iVar5 = 0x51;
                }
                else {
                  *puVar9 = 0x2ff0;
                  *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
                  iVar5 = nv_dma_buf_dup_mem_handles(puVar9,lVar10,param_2);
                  if (iVar5 == 0) {
                    if (*(char *)(lVar10 + 0x58) != '\0') goto LAB_00111053;
LAB_00111141:
                    cVar4 = rm_is_altstack_in_use();
                    if (cVar4 != '\0') {
                      kmem_cache_free(nvidia_stack_t_cache,puVar9);
                    }
                    goto LAB_0011109a;
                  }
LAB_001111c6:
                  cVar4 = rm_is_altstack_in_use();
                  if (cVar4 != '\0') {
                    kmem_cache_free(nvidia_stack_t_cache,puVar9);
                  }
                }
              }
            }
LAB_00110ad1:
            mutex_unlock(lVar10 + 0x30);
            goto LAB_00110af0;
          }
        }
        iVar5 = 0x59;
      }
      else {
        nv_printf(4,"NVRM: Invalid dma-buf fd\n");
        iVar5 = 0x1f;
      }
LAB_00110af0:
      dma_buf_put(uVar7);
      goto LAB_00110b08;
    }
    nv_printf(4,"NVRM: failed to get dma-buf\n");
LAB_00110d09:
    iVar5 = 0x59;
    goto LAB_00110b08;
  }
  iVar5 = 0x56;
  if (*(char *)(param_1 + 0x324) == '\0') goto LAB_00110b08;
  if (uVar2 - uVar1 < (uint)param_2[4]) goto LAB_00110b02;
  uVar3 = *(undefined4 *)(param_1 + 0x24);
  plVar8 = (long *)__kmalloc_cache_noprof(_strcasecmp,0x2dc0,0x88);
  if (plVar8 != (long *)0x0) {
    mutex_init_generic(plVar8 + 6);
    iVar5 = os_alloc_mem(plVar8 + 9,(ulong)uVar2 * 0x38);
    if (iVar5 == 0) {
      os_mem_set(plVar8[9],0,(ulong)uVar2 * 0x38 & 0xffffffff);
      *(undefined1 *)((long)plVar8 + 0x5a) = 0;
      iVar5 = param_2[2];
      *plVar8 = param_1;
      *(int *)((long)plVar8 + 0x14) = iVar5;
      plVar8[4] = *(long *)(param_2 + 6);
      *(char *)((long)plVar8 + 0x59) = (char)param_2[8];
      plVar8[0xd] = (ulong)*(byte *)((long)param_2 + 0x21);
      cVar4 = rm_is_altstack_in_use();
      if (cVar4 == '\0') {
        iVar6 = nvidia_dev_get(uVar3,0,0);
        iVar5 = 0x59;
        if (iVar6 == 0) {
          iVar5 = rm_dma_buf_get_client_and_device
                            (0,*plVar8,param_2[1],param_2[9],*(undefined1 *)((long)plVar8 + 0x59),
                             plVar8 + 1,(long)plVar8 + 0xc,plVar8 + 2,plVar8 + 10,plVar8 + 0xb,
                             plVar8 + 0x10);
          if (iVar5 == 0) {
            puVar9 = (undefined4 *)0x0;
LAB_00110db3:
            iVar5 = nv_dma_buf_dup_mem_handles(puVar9,plVar8,param_2);
            if (iVar5 == 0) {
              if (plVar8[0xd] == 0) {
                *(undefined1 *)((long)plVar8 + 0x61) = 0;
LAB_00110de4:
                if (((char)plVar8[0xb] == '\0') ||
                   (iVar6 = nv_dma_buf_get_phys_addresses(plVar8,param_2[4],param_2[3]), iVar6 == 0)
                   ) {
                  puVar11 = auStack_44;
                  for (lVar10 = 3; lVar10 != 0; lVar10 = lVar10 + -1) {
                    *puVar11 = 0;
                    puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
                  }
                  uStack_50 = *(undefined8 *)(param_2 + 6);
                  puStack_60 = __this_module;
                  puStack_58 = nv_dma_buf_ops;
                  uStack_48 = 0x80002;
                  pcStack_68 = "nv_dmabuf";
                  plStack_38 = plVar8;
                  uVar7 = dma_buf_export(&pcStack_68);
                  if (uVar7 < 0xfffffffffffff001) {
                    if ((puVar9 != (undefined4 *)0x0) &&
                       (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
                      kmem_cache_free(nvidia_stack_t_cache,puVar9);
                    }
                    iVar6 = dma_buf_fd(uVar7,0x80002);
                    if (-1 < iVar6) {
                      *param_2 = iVar6;
                      goto LAB_00110b08;
                    }
                    nv_printf(4,"NVRM: failed to get dma-buf file descriptor\n");
                    dma_buf_put(uVar7);
                    goto LAB_00110d09;
                  }
                  nv_printf(4,"NVRM: failed to create dma-buf\n");
                  if ((char)plVar8[0xb] != '\0') {
                    nv_dma_buf_put_phys_addresses(plVar8,param_2[4],param_2[3]);
                  }
                  iVar6 = 0x59;
                }
              }
              else {
                if (*(char *)((long)plVar8 + 0x61) != '\0') goto LAB_00110de4;
                nv_printf(4,"NVRM: mmap is not allowed for the specific handles\n");
                iVar6 = 0x56;
              }
              nv_dma_buf_undup_mem_handles(puVar9,param_2[4],param_2[3],plVar8);
              iVar5 = iVar6;
            }
            rm_dma_buf_put_client_and_device
                      (puVar9,*plVar8,(int)plVar8[1],*(undefined4 *)((long)plVar8 + 0xc),
                       (int)plVar8[2],plVar8[10]);
            nvidia_dev_put(uVar3,puVar9,0);
            if (puVar9 != (undefined4 *)0x0) goto LAB_00110efa;
          }
          else {
            nvidia_dev_put(uVar3,0,0);
          }
        }
      }
      else {
        puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar9 == (undefined4 *)0x0) {
          iVar5 = 0x51;
          goto LAB_00110ca1;
        }
        *puVar9 = 0x2ff0;
        *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
        iVar6 = nvidia_dev_get(uVar3,puVar9,0);
        iVar5 = 0x59;
        if (iVar6 == 0) {
          iVar5 = rm_dma_buf_get_client_and_device
                            (puVar9,*plVar8,param_2[1],param_2[9],
                             *(undefined1 *)((long)plVar8 + 0x59),plVar8 + 1,(long)plVar8 + 0xc,
                             plVar8 + 2,plVar8 + 10,plVar8 + 0xb,plVar8 + 0x10);
          if (iVar5 == 0) goto LAB_00110db3;
          nvidia_dev_put(uVar3,puVar9,0);
        }
LAB_00110efa:
        cVar4 = rm_is_altstack_in_use();
        if (cVar4 != '\0') {
          kmem_cache_free(nvidia_stack_t_cache,puVar9);
        }
      }
LAB_00110ca1:
      if (plVar8[9] != 0) {
        os_free_mem();
        plVar8[9] = 0;
      }
      kfree(plVar8);
      goto LAB_00110b08;
    }
    if (plVar8[9] != 0) {
      os_free_mem();
      plVar8[9] = 0;
    }
    kfree(plVar8);
  }
  nv_printf(4,"NVRM: failed to allocate dma-buf private\n");
  iVar5 = 0x51;
LAB_00110b08:
  if (lStack_30 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}


// ===== 001109b0 nv_dma_buf_export =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00110b22) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nv_dma_buf_export(long param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long *plVar8;
  undefined4 *puVar9;
  long lVar10;
  undefined4 *puVar11;
  long in_GS_OFFSET;
  byte bVar12;
  char *local_68;
  undefined1 *local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44 [3];
  long *local_38;
  long local_30;
  
  bVar12 = 0;
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (((((param_2 == (int *)0x0) || (*(long *)(param_2 + 6) == 0)) ||
       (uVar1 = param_2[3], uVar1 == 0)) ||
      ((uVar2 = param_2[2], 0x80 < uVar1 || uVar2 == 0 || (uVar2 < uVar1)))) ||
     (1 < *(byte *)(param_2 + 8))) {
LAB_00110b02:
    iVar5 = 0x1f;
    goto LAB_00110b08;
  }
  if (*param_2 != -1) {
    if (*param_2 < 0) goto LAB_00110b02;
    uVar7 = dma_buf_get();
    if (uVar7 < 0xfffffffffffff001) {
      if (*(undefined1 **)(uVar7 + 0x20) == nv_dma_buf_ops) {
        lVar10 = *(long *)(uVar7 + 0x70);
        if (lVar10 != 0) {
          iVar5 = mutex_lock_interruptible(lVar10 + 0x30);
          if (iVar5 == 0) {
            if (((*(uint *)(lVar10 + 0x14) < (uint)param_2[3]) ||
                (*(uint *)(lVar10 + 0x14) - param_2[3] < (uint)param_2[4])) ||
               (((char)param_2[8] != *(char *)(lVar10 + 0x59) ||
                ((ulong)*(byte *)((long)param_2 + 0x21) != *(ulong *)(lVar10 + 0x68))))) {
              iVar5 = 0x1f;
            }
            else {
              cVar4 = rm_is_altstack_in_use();
              if (cVar4 == '\0') {
                iVar5 = nv_dma_buf_dup_mem_handles(0,lVar10,param_2);
                if (iVar5 == 0) {
                  if (*(char *)(lVar10 + 0x58) != '\0') {
                    puVar9 = (undefined4 *)0x0;
LAB_00111053:
                    iVar5 = nv_dma_buf_get_phys_addresses(lVar10,param_2[4],param_2[3]);
                    if (iVar5 != 0) {
                      nv_dma_buf_undup_mem_handles(puVar9,param_2[4],param_2[3],lVar10);
                      if (puVar9 != (undefined4 *)0x0) goto LAB_001111c6;
                      goto LAB_00110ad1;
                    }
                    if (puVar9 != (undefined4 *)0x0) goto LAB_00111141;
                  }
LAB_0011109a:
                  mutex_unlock(lVar10 + 0x30);
                  dma_buf_put(uVar7);
                  iVar5 = 0;
                  goto LAB_00110b08;
                }
              }
              else {
                puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
                if (puVar9 == (undefined4 *)0x0) {
                  iVar5 = 0x51;
                }
                else {
                  *puVar9 = 0x2ff0;
                  *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
                  iVar5 = nv_dma_buf_dup_mem_handles(puVar9,lVar10,param_2);
                  if (iVar5 == 0) {
                    if (*(char *)(lVar10 + 0x58) != '\0') goto LAB_00111053;
LAB_00111141:
                    cVar4 = rm_is_altstack_in_use();
                    if (cVar4 != '\0') {
                      kmem_cache_free(nvidia_stack_t_cache,puVar9);
                    }
                    goto LAB_0011109a;
                  }
LAB_001111c6:
                  cVar4 = rm_is_altstack_in_use();
                  if (cVar4 != '\0') {
                    kmem_cache_free(nvidia_stack_t_cache,puVar9);
                  }
                }
              }
            }
LAB_00110ad1:
            mutex_unlock(lVar10 + 0x30);
            goto LAB_00110af0;
          }
        }
        iVar5 = 0x59;
      }
      else {
        nv_printf(4,"NVRM: Invalid dma-buf fd\n");
        iVar5 = 0x1f;
      }
LAB_00110af0:
      dma_buf_put(uVar7);
      goto LAB_00110b08;
    }
    nv_printf(4,"NVRM: failed to get dma-buf\n");
LAB_00110d09:
    iVar5 = 0x59;
    goto LAB_00110b08;
  }
  iVar5 = 0x56;
  if (*(char *)(param_1 + 0x324) == '\0') goto LAB_00110b08;
  if (uVar2 - uVar1 < (uint)param_2[4]) goto LAB_00110b02;
  uVar3 = *(undefined4 *)(param_1 + 0x24);
  plVar8 = (long *)__kmalloc_cache_noprof(_strcasecmp,0x2dc0,0x88);
  if (plVar8 != (long *)0x0) {
    mutex_init_generic(plVar8 + 6);
    iVar5 = os_alloc_mem(plVar8 + 9,(ulong)uVar2 * 0x38);
    if (iVar5 == 0) {
      os_mem_set(plVar8[9],0,(ulong)uVar2 * 0x38 & 0xffffffff);
      *(undefined1 *)((long)plVar8 + 0x5a) = 0;
      iVar5 = param_2[2];
      *plVar8 = param_1;
      *(int *)((long)plVar8 + 0x14) = iVar5;
      plVar8[4] = *(long *)(param_2 + 6);
      *(char *)((long)plVar8 + 0x59) = (char)param_2[8];
      plVar8[0xd] = (ulong)*(byte *)((long)param_2 + 0x21);
      cVar4 = rm_is_altstack_in_use();
      if (cVar4 == '\0') {
        iVar6 = nvidia_dev_get(uVar3,0,0);
        iVar5 = 0x59;
        if (iVar6 == 0) {
          iVar5 = rm_dma_buf_get_client_and_device
                            (0,*plVar8,param_2[1],param_2[9],*(undefined1 *)((long)plVar8 + 0x59),
                             plVar8 + 1,(long)plVar8 + 0xc,plVar8 + 2,plVar8 + 10,plVar8 + 0xb,
                             plVar8 + 0x10);
          if (iVar5 == 0) {
            puVar9 = (undefined4 *)0x0;
LAB_00110db3:
            iVar5 = nv_dma_buf_dup_mem_handles(puVar9,plVar8,param_2);
            if (iVar5 == 0) {
              if (plVar8[0xd] == 0) {
                *(undefined1 *)((long)plVar8 + 0x61) = 0;
LAB_00110de4:
                if (((char)plVar8[0xb] == '\0') ||
                   (iVar6 = nv_dma_buf_get_phys_addresses(plVar8,param_2[4],param_2[3]), iVar6 == 0)
                   ) {
                  puVar11 = local_44;
                  for (lVar10 = 3; lVar10 != 0; lVar10 = lVar10 + -1) {
                    *puVar11 = 0;
                    puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
                  }
                  local_50 = *(undefined8 *)(param_2 + 6);
                  local_60 = __this_module;
                  local_58 = nv_dma_buf_ops;
                  local_48 = 0x80002;
                  local_68 = "nv_dmabuf";
                  local_38 = plVar8;
                  uVar7 = dma_buf_export(&local_68);
                  if (uVar7 < 0xfffffffffffff001) {
                    if ((puVar9 != (undefined4 *)0x0) &&
                       (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
                      kmem_cache_free(nvidia_stack_t_cache,puVar9);
                    }
                    iVar6 = dma_buf_fd(uVar7,0x80002);
                    if (-1 < iVar6) {
                      *param_2 = iVar6;
                      goto LAB_00110b08;
                    }
                    nv_printf(4,"NVRM: failed to get dma-buf file descriptor\n");
                    dma_buf_put(uVar7);
                    goto LAB_00110d09;
                  }
                  nv_printf(4,"NVRM: failed to create dma-buf\n");
                  if ((char)plVar8[0xb] != '\0') {
                    nv_dma_buf_put_phys_addresses(plVar8,param_2[4],param_2[3]);
                  }
                  iVar6 = 0x59;
                }
              }
              else {
                if (*(char *)((long)plVar8 + 0x61) != '\0') goto LAB_00110de4;
                nv_printf(4,"NVRM: mmap is not allowed for the specific handles\n");
                iVar6 = 0x56;
              }
              nv_dma_buf_undup_mem_handles(puVar9,param_2[4],param_2[3],plVar8);
              iVar5 = iVar6;
            }
            rm_dma_buf_put_client_and_device
                      (puVar9,*plVar8,(int)plVar8[1],*(undefined4 *)((long)plVar8 + 0xc),
                       (int)plVar8[2],plVar8[10]);
            nvidia_dev_put(uVar3,puVar9,0);
            if (puVar9 != (undefined4 *)0x0) goto LAB_00110efa;
          }
          else {
            nvidia_dev_put(uVar3,0,0);
          }
        }
      }
      else {
        puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar9 == (undefined4 *)0x0) {
          iVar5 = 0x51;
          goto LAB_00110ca1;
        }
        *puVar9 = 0x2ff0;
        *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
        iVar6 = nvidia_dev_get(uVar3,puVar9,0);
        iVar5 = 0x59;
        if (iVar6 == 0) {
          iVar5 = rm_dma_buf_get_client_and_device
                            (puVar9,*plVar8,param_2[1],param_2[9],
                             *(undefined1 *)((long)plVar8 + 0x59),plVar8 + 1,(long)plVar8 + 0xc,
                             plVar8 + 2,plVar8 + 10,plVar8 + 0xb,plVar8 + 0x10);
          if (iVar5 == 0) goto LAB_00110db3;
          nvidia_dev_put(uVar3,puVar9,0);
        }
LAB_00110efa:
        cVar4 = rm_is_altstack_in_use();
        if (cVar4 != '\0') {
          kmem_cache_free(nvidia_stack_t_cache,puVar9);
        }
      }
LAB_00110ca1:
      if (plVar8[9] != 0) {
        os_free_mem();
        plVar8[9] = 0;
      }
      kfree(plVar8);
      goto LAB_00110b08;
    }
    if (plVar8[9] != 0) {
      os_free_mem();
      plVar8[9] = 0;
    }
    kfree(plVar8);
  }
  nv_printf(4,"NVRM: failed to allocate dma-buf private\n");
  iVar5 = 0x51;
LAB_00110b08:
  if (local_30 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}


// ===== 001112c0 __pfx_nv_dma_import_dma_buf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111465) */

int __pfx_nv_dma_import_dma_buf
              (long param_1,undefined8 *param_2,char param_3,undefined4 *param_4,ulong *param_5,
              undefined8 *param_6)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 uVar6;
  long in_GS_OFFSET;
  undefined8 *puStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puStack_48 = (undefined8 *)0x0;
  if ((((param_1 == 0) || (param_2 == (undefined8 *)0x0)) ||
      (param_4 == (undefined4 *)0x0 || param_5 == (ulong *)0x0)) || (param_6 == (undefined8 *)0x0))
  {
    iVar3 = 0x1f;
    nv_printf(4,"Import arguments are NULL!\n");
  }
  else {
    iVar3 = os_alloc_mem(&puStack_48,0x20);
    if (iVar3 == 0) {
      LOCK();
      plVar1 = (long *)(param_2[1] + 0xa8);
      lVar2 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      if (lVar2 < 0) {
        __SCT__WARN_trap(&DAT_00100bd0);
      }
      uVar4 = dma_buf_attach(param_2,*(undefined8 *)(param_1 + 0x10));
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        nv_printf(4,"Can\'t attach dma_buf!\n");
      }
      else {
        if (param_3 == '\0') {
          *(undefined4 *)(puStack_48 + 3) = 0;
          uVar6 = 0;
        }
        else {
          *(undefined4 *)(puStack_48 + 3) = 1;
          nv_printf(0,"NVRM: nv_dma_import_dma_buf -Try RO [DMA_TO_DEVICE] only mapping \n");
          uVar6 = *(undefined4 *)(puStack_48 + 3);
        }
        uVar5 = dma_buf_map_attachment(uVar4,uVar6);
        if ((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) {
          *puStack_48 = param_2;
          puStack_48[1] = uVar4;
          puStack_48[2] = uVar5;
          *param_4 = (int)*param_2;
          *param_6 = puStack_48;
          *param_5 = uVar5;
          goto LAB_00111447;
        }
        nv_printf(4,"Can\'t map dma attachment!\n");
        dma_buf_detach(param_2,uVar4);
      }
      iVar3 = 0x59;
      os_free_mem(puStack_48);
      dma_buf_put(param_2);
    }
    else {
      nv_printf(4,"Can\'t allocate mem for nv_buf!\n");
    }
  }
LAB_00111447:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 001112d0 nv_dma_import_dma_buf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111465) */

int nv_dma_import_dma_buf
              (long param_1,undefined8 *param_2,char param_3,undefined4 *param_4,ulong *param_5,
              undefined8 *param_6)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 uVar6;
  long in_GS_OFFSET;
  undefined8 *local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_48 = (undefined8 *)0x0;
  if ((((param_1 == 0) || (param_2 == (undefined8 *)0x0)) ||
      (param_4 == (undefined4 *)0x0 || param_5 == (ulong *)0x0)) || (param_6 == (undefined8 *)0x0))
  {
    iVar3 = 0x1f;
    nv_printf(4,"Import arguments are NULL!\n");
  }
  else {
    iVar3 = os_alloc_mem(&local_48,0x20);
    if (iVar3 == 0) {
      LOCK();
      plVar1 = (long *)(param_2[1] + 0xa8);
      lVar2 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      if (lVar2 < 0) {
        __SCT__WARN_trap(&DAT_00100bd0);
      }
      uVar4 = dma_buf_attach(param_2,*(undefined8 *)(param_1 + 0x10));
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        nv_printf(4,"Can\'t attach dma_buf!\n");
      }
      else {
        if (param_3 == '\0') {
          *(undefined4 *)(local_48 + 3) = 0;
          uVar6 = 0;
        }
        else {
          *(undefined4 *)(local_48 + 3) = 1;
          nv_printf(0,"NVRM: nv_dma_import_dma_buf -Try RO [DMA_TO_DEVICE] only mapping \n");
          uVar6 = *(undefined4 *)(local_48 + 3);
        }
        uVar5 = dma_buf_map_attachment(uVar4,uVar6);
        if ((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) {
          *local_48 = param_2;
          local_48[1] = uVar4;
          local_48[2] = uVar5;
          *param_4 = (int)*param_2;
          *param_6 = local_48;
          *param_5 = uVar5;
          goto LAB_00111447;
        }
        nv_printf(4,"Can\'t map dma attachment!\n");
        dma_buf_detach(param_2,uVar4);
      }
      iVar3 = 0x59;
      os_free_mem(local_48);
      dma_buf_put(param_2);
    }
    else {
      nv_printf(4,"Can\'t allocate mem for nv_buf!\n");
    }
  }
LAB_00111447:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 00111540 __pfx_nv_dma_import_from_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001115d2) */

undefined4
__pfx_nv_dma_import_from_fd
          (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = dma_buf_get(param_2);
  if ((uVar2 < 0xfffffffffffff001) && (uVar2 != 0)) {
    uVar1 = nv_dma_import_dma_buf(param_1,uVar2,param_3,param_4,param_5,param_6);
    dma_buf_put(uVar2);
  }
  else {
    uVar1 = 0x59;
    nv_printf(4,"Can\'t get dma_buf from fd!\n");
  }
  return uVar1;
}


// ===== 00111550 nv_dma_import_from_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001115d2) */

undefined4
nv_dma_import_from_fd
          (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = dma_buf_get(param_2);
  if ((uVar2 < 0xfffffffffffff001) && (uVar2 != 0)) {
    uVar1 = nv_dma_import_dma_buf(param_1,uVar2,param_3,param_4,param_5,param_6);
    dma_buf_put(uVar2);
  }
  else {
    uVar1 = 0x59;
    nv_printf(4,"Can\'t get dma_buf from fd!\n");
  }
  return uVar1;
}


// ===== 00111600 __pfx_nv_dma_release_dma_buf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011164f) */

void __pfx_nv_dma_release_dma_buf(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    dma_buf_unmap_attachment(param_1[1],param_1[2],*(undefined4 *)(param_1 + 3));
    dma_buf_detach(*param_1,param_1[1]);
    dma_buf_put(*param_1);
    os_free_mem(param_1);
    return;
  }
  return;
}


// ===== 00111610 nv_dma_release_dma_buf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011164f) */

void nv_dma_release_dma_buf(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    dma_buf_unmap_attachment(param_1[1],param_1[2],*(undefined4 *)(param_1 + 3));
    dma_buf_detach(*param_1,param_1[1]);
    dma_buf_put(*param_1);
    os_free_mem(param_1);
    return;
  }
  return;
}


// ===== 00111660 __pfx_nv_nano_timer_callback_typed_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111684) */

undefined8 __pfx_nv_nano_timer_callback_typed_data(long param_1)

{
  (**(code **)(param_1 + 0x58))();
  return 0;
}


// ===== 00111670 nv_nano_timer_callback_typed_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111684) */

undefined8 nv_nano_timer_callback_typed_data(long param_1)

{
  (**(code **)(param_1 + 0x58))();
  return 0;
}


// ===== 00111690 __pfx_nvidia_nano_timer_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111753) */

void __pfx_nvidia_nano_timer_callback(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar1 = *(undefined8 *)(param_1 + 0x50);
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    iVar4 = rm_run_nano_timer_callback(0,uVar1,*(undefined8 *)(param_1 + 0x60));
    if (iVar4 != 0) {
      nv_printf(4,"NVRM: Error in service of callback \n");
      return;
    }
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0x820);
    if (puVar5 == (undefined4 *)0x0) {
      nv_printf(4,"NVRM: no cache memory \n");
      return;
    }
    *puVar5 = 0x2ff0;
    uVar2 = *(undefined8 *)(param_1 + 0x60);
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    iVar4 = rm_run_nano_timer_callback(puVar5,uVar1,uVar2);
    if (iVar4 != 0) {
      nv_printf(4,"NVRM: Error in service of callback \n");
    }
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar5);
      return;
    }
  }
  return;
}


// ===== 001116a0 nvidia_nano_timer_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111753) */

void nvidia_nano_timer_callback(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar1 = *(undefined8 *)(param_1 + 0x50);
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    iVar4 = rm_run_nano_timer_callback(0,uVar1,*(undefined8 *)(param_1 + 0x60));
    if (iVar4 != 0) {
      nv_printf(4,"NVRM: Error in service of callback \n");
      return;
    }
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0x820);
    if (puVar5 == (undefined4 *)0x0) {
      nv_printf(4,"NVRM: no cache memory \n");
      return;
    }
    *puVar5 = 0x2ff0;
    uVar2 = *(undefined8 *)(param_1 + 0x60);
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    iVar4 = rm_run_nano_timer_callback(puVar5,uVar1,uVar2);
    if (iVar4 != 0) {
      nv_printf(4,"NVRM: Error in service of callback \n");
    }
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar5);
      return;
    }
  }
  return;
}


// ===== 001117b0 __pfx_nv_create_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011186c) */
/* WARNING: Removing unreachable block (ram,0x00111895) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_create_nano_timer(long param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  lVar3 = __kmalloc_cache_noprof(___init_swait_queue_head,0x2cc0,0x68);
  if (lVar3 != 0) {
    uVar4 = 0;
    do {
      uVar2 = (int)uVar4 + 0x20;
      *(undefined8 *)(lVar3 + uVar4) = 0;
      *(undefined8 *)(lVar3 + 8 + uVar4) = 0;
      *(undefined8 *)(lVar3 + 0x10 + uVar4) = 0;
      *(undefined8 *)(lVar3 + 0x18 + uVar4) = 0;
      uVar4 = (ulong)uVar2;
    } while (uVar2 < 0x60);
    *(undefined8 *)(lVar3 + (ulong)uVar2) = 0;
    *(undefined8 *)(lVar3 + 0x50) = uVar1;
    *(undefined8 *)(lVar3 + 0x60) = param_2;
    *(code **)(lVar3 + 0x58) = nvidia_nano_timer_callback;
    hrtimer_setup(lVar3,nv_nano_timer_callback_typed_data,1,1);
    *param_3 = lVar3;
    return;
  }
  nv_printf(4,"NVRM: Not able to create timer object \n");
  *param_3 = 0;
  return;
}


// ===== 001117c0 nv_create_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011186c) */
/* WARNING: Removing unreachable block (ram,0x00111895) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_create_nano_timer(long param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  lVar3 = __kmalloc_cache_noprof(___init_swait_queue_head,0x2cc0,0x68);
  if (lVar3 != 0) {
    uVar4 = 0;
    do {
      uVar2 = (int)uVar4 + 0x20;
      *(undefined8 *)(lVar3 + uVar4) = 0;
      *(undefined8 *)(lVar3 + 8 + uVar4) = 0;
      *(undefined8 *)(lVar3 + 0x10 + uVar4) = 0;
      *(undefined8 *)(lVar3 + 0x18 + uVar4) = 0;
      uVar4 = (ulong)uVar2;
    } while (uVar2 < 0x60);
    *(undefined8 *)(lVar3 + (ulong)uVar2) = 0;
    *(undefined8 *)(lVar3 + 0x50) = uVar1;
    *(undefined8 *)(lVar3 + 0x60) = param_2;
    *(code **)(lVar3 + 0x58) = nvidia_nano_timer_callback;
    hrtimer_setup(lVar3,nv_nano_timer_callback_typed_data,1,1);
    *param_3 = lVar3;
    return;
  }
  nv_printf(4,"NVRM: Not able to create timer object \n");
  *param_3 = 0;
  return;
}


// ===== 001118a0 __pfx_nv_start_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_start_nano_timer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  hrtimer_start_range_ns(param_2,param_3,0,1);
  return;
}


// ===== 001118b0 nv_start_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_start_nano_timer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  hrtimer_start_range_ns(param_2,param_3,0,1);
  return;
}


// ===== 001118d0 __pfx_nv_cancel_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_cancel_nano_timer(undefined8 param_1,undefined8 param_2)

{
  hrtimer_cancel(param_2);
  return;
}


// ===== 001118e0 nv_cancel_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_cancel_nano_timer(undefined8 param_1,undefined8 param_2)

{
  hrtimer_cancel(param_2);
  return;
}


// ===== 00111900 __pfx_nv_destroy_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_destroy_nano_timer(undefined8 param_1,undefined8 param_2)

{
  hrtimer_cancel(param_2);
  kfree(param_2);
  return;
}


// ===== 00111910 nv_destroy_nano_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_destroy_nano_timer(undefined8 param_1,undefined8 param_2)

{
  hrtimer_cancel(param_2);
  kfree(param_2);
  return;
}


// ===== 00111940 __pfx_nv_acpi_notifier_call_chain_handler =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111986) */

undefined8
__pfx_nv_acpi_notifier_call_chain_handler(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = strcmp((char *)(param_3 + 0x10),"video");
  uVar2 = 0;
  if ((iVar1 == 0) && (uVar2 = 0, *(int *)(param_3 + 0x2c) == 0x81)) {
    uVar2 = 0x8002;
  }
  return uVar2;
}


// ===== 00111950 nv_acpi_notifier_call_chain_handler =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111986) */

undefined8 nv_acpi_notifier_call_chain_handler(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = strcmp((char *)(param_3 + 0x10),"video");
  uVar2 = 0;
  if ((iVar1 == 0) && (uVar2 = 0, *(int *)(param_3 + 0x2c) == 0x81)) {
    uVar2 = 0x8002;
  }
  return uVar2;
}


// ===== 00111990 __pfx_nv_acpi_notify_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_acpi_notify_event(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  rm_acpi_notify(*param_3,param_3[3],param_2);
  return;
}


// ===== 001119a0 nv_acpi_notify_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_acpi_notify_event(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  rm_acpi_notify(*param_3,param_3[3],param_2);
  return;
}


// ===== 001119c0 __pfx_nv_acpi_find_methods =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111a9b) */

undefined8 __pfx_nv_acpi_find_methods(undefined8 param_1)

{
  int iVar1;
  long in_GS_OFFSET;
  undefined8 uStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_20 = 0;
  iVar1 = acpi_get_handle(param_1,&DAT_00daf088,&uStack_20);
  if (iVar1 == 0) {
    nvif_handle = uStack_20;
  }
  iVar1 = acpi_get_handle(param_1,&DAT_00daf08d,&uStack_20);
  if (iVar1 == 0) {
    wmmx_handle = uStack_20;
  }
  iVar1 = acpi_get_handle(param_1,&DAT_00daf092,&uStack_20);
  if (iVar1 == 0) {
    psr_handle = uStack_20;
    psr_device_handle = param_1;
  }
  iVar1 = acpi_get_handle(param_1,&DAT_00daf097,&uStack_20);
  if (iVar1 == 0) {
    nvpcf_handle = uStack_20;
    nvpcf_device_handle = param_1;
  }
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001119d0 nv_acpi_find_methods =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111a9b) */

undefined8 nv_acpi_find_methods(undefined8 param_1)

{
  int iVar1;
  long in_GS_OFFSET;
  undefined8 local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  iVar1 = acpi_get_handle(param_1,&DAT_00daf088,&local_20);
  if (iVar1 == 0) {
    nvif_handle = local_20;
  }
  iVar1 = acpi_get_handle(param_1,&DAT_00daf08d,&local_20);
  if (iVar1 == 0) {
    wmmx_handle = local_20;
  }
  iVar1 = acpi_get_handle(param_1,&DAT_00daf092,&local_20);
  if (iVar1 == 0) {
    psr_handle = local_20;
    psr_device_handle = param_1;
  }
  iVar1 = acpi_get_handle(param_1,&DAT_00daf097,&local_20);
  if (iVar1 == 0) {
    nvpcf_handle = local_20;
    nvpcf_device_handle = param_1;
  }
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111ab0 __pfx_nv_acpi_find_battery_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111b4a) */

undefined8 __pfx_nv_acpi_find_battery_info(undefined8 param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  undefined8 uStack_30;
  int *piStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_30 = 0xffffffffffffffff;
  piStack_28 = (int *)0x0;
  iVar1 = acpi_evaluate_object(param_1,0,0,&uStack_30);
  if (iVar1 == 0) {
    uVar3 = 0;
    if (piStack_28 == (int *)0x0) {
      nv_printf(0,"NVRM: Battery object output buffer is null\n");
    }
    else if (*piStack_28 == 4) {
      uVar2 = (ulong)(param_2 + 3U & 0xff);
      if ((*(int *)(*(long *)(piStack_28 + 2) + uVar2 * 0x18) == 1) &&
         (*(long *)(*(long *)(piStack_28 + 2) + 8 + uVar2 * 0x18) == 1)) {
        battery_present = 1;
        uVar3 = 0x4003;
        kfree();
      }
      else {
        kfree();
      }
    }
    else {
      nv_printf(0,"NVRM: Battery method output is not package\n");
      kfree(piStack_28);
    }
  }
  else {
    uVar3 = 0;
    nv_printf(0,"NVRM: Failed to evaluate battery\'s object\n");
  }
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111ac0 nv_acpi_find_battery_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111b4a) */

undefined8 nv_acpi_find_battery_info(undefined8 param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  undefined8 local_30;
  int *local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_30 = 0xffffffffffffffff;
  local_28 = (int *)0x0;
  iVar1 = acpi_evaluate_object(param_1,0,0,&local_30);
  if (iVar1 == 0) {
    uVar3 = 0;
    if (local_28 == (int *)0x0) {
      nv_printf(0,"NVRM: Battery object output buffer is null\n");
    }
    else if (*local_28 == 4) {
      uVar2 = (ulong)(param_2 + 3U & 0xff);
      if ((*(int *)(*(long *)(local_28 + 2) + uVar2 * 0x18) == 1) &&
         (*(long *)(*(long *)(local_28 + 2) + 8 + uVar2 * 0x18) == 1)) {
        battery_present = 1;
        uVar3 = 0x4003;
        kfree();
      }
      else {
        kfree();
      }
    }
    else {
      nv_printf(0,"NVRM: Battery method output is not package\n");
      kfree(local_28);
    }
  }
  else {
    uVar3 = 0;
    nv_printf(0,"NVRM: Failed to evaluate battery\'s object\n");
  }
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111bb0 __pfx_nv_acpi_find_battery_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111c26) */

undefined4 __pfx_nv_acpi_find_battery_device(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  long in_GS_OFFSET;
  undefined8 uStack_28;
  undefined8 uStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_28 = 0;
  uStack_20 = 0;
  iVar1 = acpi_get_handle(param_1,&DAT_00daf09c,&uStack_20);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = nv_acpi_find_battery_info(uStack_20,1);
  }
  if ((battery_present == '\0') &&
     (iVar1 = acpi_get_handle(param_1,&DAT_00daf0a1,&uStack_28), iVar1 == 0)) {
    uVar2 = nv_acpi_find_battery_info(uStack_28,0);
  }
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111bc0 nv_acpi_find_battery_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111c26) */

undefined4 nv_acpi_find_battery_device(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  long in_GS_OFFSET;
  undefined8 local_28;
  undefined8 local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_28 = 0;
  local_20 = 0;
  iVar1 = acpi_get_handle(param_1,&DAT_00daf09c,&local_20);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = nv_acpi_find_battery_info(local_20,1);
  }
  if ((battery_present == '\0') &&
     (iVar1 = acpi_get_handle(param_1,&DAT_00daf0a1,&local_28), iVar1 == 0)) {
    uVar2 = nv_acpi_find_battery_info(local_28,0);
  }
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111c80 __pfx_nv_acpi_nvif_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111ec6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
__pfx_nv_acpi_nvif_method
          (ulong param_1,ulong param_2,undefined8 param_3,uint param_4,undefined4 *param_5,
          void *param_6)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  long in_GS_OFFSET;
  undefined1 auVar6 [16];
  ushort *unaff_retaddr;
  undefined8 uStack_90;
  undefined8 *puStack_88;
  undefined8 uStack_80;
  int *piStack_78;
  undefined8 uStack_70;
  ulong uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  ulong uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 *puStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_90 = 0;
  puStack_88 = (undefined8 *)0x0;
  uStack_80 = 0xffffffffffffffff;
  piStack_78 = (int *)0x0;
  uStack_70 = 0;
  uStack_68 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  puStack_38 = (undefined8 *)0x0;
  uStack_30 = 0;
  uStack_28 = 0;
  if (nvif_handle != 0) {
    auVar6 = (*_mpi_powm)();
    puVar4 = auVar6._8_8_;
    if (((auVar6._0_8_ & 0x200) != 0) &&
       ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
      uStack_68 = param_1 & 0xffffffff;
      uStack_50 = param_2 & 0xffffffff;
      uStack_70 = CONCAT44(uStack_70._4_4_,1);
      uStack_58 = CONCAT44(uStack_58._4_4_,1);
      if ((puVar4 == (undefined8 *)0x0) || ((short)param_4 == 0)) {
        param_4 = 8;
        puVar4 = &uStack_28;
        uStack_28 = 0;
      }
      else {
        param_4 = param_4 & 0xffff;
      }
      uStack_40 = CONCAT44(param_4,3);
      puStack_88 = &uStack_70;
      uStack_90 = CONCAT44(uStack_90._4_4_,3);
      puStack_38 = puVar4;
      iVar2 = acpi_evaluate_object(nvif_handle,0,&uStack_90,&uStack_80);
      if (iVar2 == 0) {
        if (((piStack_78 != (int *)0x0) && (*piStack_78 == 3)) && (3 < (uint)piStack_78[1])) {
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = **(undefined4 **)(piStack_78 + 2);
          }
          if ((param_6 != (void *)0x0) && (unaff_retaddr != (ushort *)0x0)) {
            uVar3 = (short)piStack_78[1] - 4;
            uVar1 = *unaff_retaddr;
            *unaff_retaddr = uVar3;
            if (uVar1 < uVar3) {
              kfree();
              uVar5 = 2;
              goto LAB_00111e9e;
            }
            memcpy(param_6,(void *)(*(long *)(piStack_78 + 2) + 4),(ulong)uVar3);
          }
          kfree(piStack_78);
          uVar5 = 0;
          goto LAB_00111e9e;
        }
        nv_printf(0,
                  "NVRM: nv_acpi_nvif_method: NVIF data invalid, function 0x%x, subFunction 0x%x!\n"
                  ,param_1 & 0xffffffff,param_2 & 0xffffffff);
        kfree(piStack_78);
      }
      else {
        nv_printf(0,
                  "NVRM: nv_acpi_nvif_method: failed to get NVIF data, status 0x%x, function 0x%x, subFunction 0x%x!\n"
                  ,iVar2,param_1 & 0xffffffff,param_2 & 0xffffffff);
      }
      uVar5 = 0xffff;
      goto LAB_00111e9e;
    }
  }
  uVar5 = 0x56;
LAB_00111e9e:
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111c90 nv_acpi_nvif_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00111ec6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
nv_acpi_nvif_method(ulong param_1,ulong param_2,undefined8 param_3,uint param_4,undefined4 *param_5,
                   void *param_6)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  long in_GS_OFFSET;
  undefined1 auVar6 [16];
  ushort *unaff_retaddr;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  int *local_78;
  undefined8 local_70;
  ulong local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_90 = 0;
  local_88 = (undefined8 *)0x0;
  local_80 = 0xffffffffffffffff;
  local_78 = (int *)0x0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = (undefined8 *)0x0;
  local_30 = 0;
  local_28 = 0;
  if (nvif_handle != 0) {
    auVar6 = (*_mpi_powm)();
    puVar4 = auVar6._8_8_;
    if (((auVar6._0_8_ & 0x200) != 0) &&
       ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
      local_68 = param_1 & 0xffffffff;
      local_50 = param_2 & 0xffffffff;
      local_70 = CONCAT44(local_70._4_4_,1);
      local_58 = CONCAT44(local_58._4_4_,1);
      if ((puVar4 == (undefined8 *)0x0) || ((short)param_4 == 0)) {
        param_4 = 8;
        puVar4 = &local_28;
        local_28 = 0;
      }
      else {
        param_4 = param_4 & 0xffff;
      }
      local_40 = CONCAT44(param_4,3);
      local_88 = &local_70;
      local_90 = CONCAT44(local_90._4_4_,3);
      local_38 = puVar4;
      iVar2 = acpi_evaluate_object(nvif_handle,0,&local_90,&local_80);
      if (iVar2 == 0) {
        if (((local_78 != (int *)0x0) && (*local_78 == 3)) && (3 < (uint)local_78[1])) {
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = **(undefined4 **)(local_78 + 2);
          }
          if ((param_6 != (void *)0x0) && (unaff_retaddr != (ushort *)0x0)) {
            uVar3 = (short)local_78[1] - 4;
            uVar1 = *unaff_retaddr;
            *unaff_retaddr = uVar3;
            if (uVar1 < uVar3) {
              kfree();
              uVar5 = 2;
              goto LAB_00111e9e;
            }
            memcpy(param_6,(void *)(*(long *)(local_78 + 2) + 4),(ulong)uVar3);
          }
          kfree(local_78);
          uVar5 = 0;
          goto LAB_00111e9e;
        }
        nv_printf(0,
                  "NVRM: nv_acpi_nvif_method: NVIF data invalid, function 0x%x, subFunction 0x%x!\n"
                  ,param_1 & 0xffffffff,param_2 & 0xffffffff);
        kfree(local_78);
      }
      else {
        nv_printf(0,
                  "NVRM: nv_acpi_nvif_method: failed to get NVIF data, status 0x%x, function 0x%x, subFunction 0x%x!\n"
                  ,iVar2,param_1 & 0xffffffff,param_2 & 0xffffffff);
      }
      uVar5 = 0xffff;
      goto LAB_00111e9e;
    }
  }
  uVar5 = 0x56;
LAB_00111e9e:
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111f60 __pfx_nv_acpi_wmmx_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112123) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_acpi_wmmx_method(ulong param_1,void *param_2,ushort *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long in_GS_OFFSET;
  undefined1 auVar6 [16];
  undefined8 uStack_78;
  undefined8 *puStack_70;
  undefined8 uStack_68;
  int *piStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  ulong uStack_20;
  undefined8 uStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x111f75;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_78 = 0;
  puStack_70 = (undefined8 *)0x0;
  uStack_68 = 0xffffffffffffffff;
  piStack_60 = (int *)0x0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  if (wmmx_handle == 0) {
    *param_3 = 0;
  }
  else {
    puVar4 = &uStack_58;
    auVar6 = (*_mpi_powm)(param_1,param_2,&uStack_78);
    if (((auVar6._0_8_ & 0x200) != 0) &&
       ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
      uStack_20 = param_1 & 0xffffffff;
      uStack_58 = CONCAT44(uStack_58._4_4_,1);
      uStack_50 = 0;
      uStack_40 = CONCAT44(uStack_40._4_4_,1);
      uStack_38 = 0;
      uStack_28 = CONCAT44(uStack_28._4_4_,1);
      uStack_78 = CONCAT44(uStack_78._4_4_,3);
      puStack_70 = puVar4;
      iVar3 = acpi_evaluate_object(wmmx_handle,0,auVar6._8_8_,&uStack_68);
      piVar2 = piStack_60;
      if (iVar3 == 0) {
        if ((piStack_60 != (int *)0x0) && (*piStack_60 == 3)) {
          uVar1 = piStack_60[1];
          if (uVar1 != 0) {
            if ((param_2 != (void *)0x0) && (param_3 != (ushort *)0x0)) {
              if (*param_3 < uVar1) {
                kfree(piStack_60);
                uVar5 = 2;
                goto LAB_0011210e;
              }
              *param_3 = (ushort)uVar1;
              memcpy(param_2,*(void **)(piStack_60 + 2),(ulong)uVar1);
            }
            kfree(piVar2);
            uVar5 = 0;
            goto LAB_0011210e;
          }
        }
        nv_printf(4,"NVRM: nv_acpi_wmmx_method: WMMX data invalid.\n");
        kfree(piStack_60);
      }
      else {
        nv_printf(0,"NVRM: nv_acpi_wmmx_method: failed to get WMMX data, status 0x%x!\n",iVar3);
      }
      uVar5 = 0xffff;
      goto LAB_0011210e;
    }
  }
  uVar5 = 0x56;
LAB_0011210e:
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00111f70 nv_acpi_wmmx_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112123) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_acpi_wmmx_method(ulong param_1,void *param_2,ushort *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long in_GS_OFFSET;
  undefined1 auVar6 [16];
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  int *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulong local_20;
  undefined8 local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x111f75;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_78 = 0;
  local_70 = (undefined8 *)0x0;
  local_68 = 0xffffffffffffffff;
  local_60 = (int *)0x0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  if (wmmx_handle == 0) {
    *param_3 = 0;
  }
  else {
    puVar4 = &local_58;
    auVar6 = (*_mpi_powm)(param_1,param_2,&local_78);
    if (((auVar6._0_8_ & 0x200) != 0) &&
       ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
      local_20 = param_1 & 0xffffffff;
      local_58 = CONCAT44(local_58._4_4_,1);
      local_50 = 0;
      local_40 = CONCAT44(local_40._4_4_,1);
      local_38 = 0;
      local_28 = CONCAT44(local_28._4_4_,1);
      local_78 = CONCAT44(local_78._4_4_,3);
      local_70 = puVar4;
      iVar3 = acpi_evaluate_object(wmmx_handle,0,auVar6._8_8_,&local_68);
      piVar2 = local_60;
      if (iVar3 == 0) {
        if ((local_60 != (int *)0x0) && (*local_60 == 3)) {
          uVar1 = local_60[1];
          if (uVar1 != 0) {
            if ((param_2 != (void *)0x0) && (param_3 != (ushort *)0x0)) {
              if (*param_3 < uVar1) {
                kfree(local_60);
                uVar5 = 2;
                goto LAB_0011210e;
              }
              *param_3 = (ushort)uVar1;
              memcpy(param_2,*(void **)(local_60 + 2),(ulong)uVar1);
            }
            kfree(piVar2);
            uVar5 = 0;
            goto LAB_0011210e;
          }
        }
        nv_printf(4,"NVRM: nv_acpi_wmmx_method: WMMX data invalid.\n");
        kfree(local_60);
      }
      else {
        nv_printf(0,"NVRM: nv_acpi_wmmx_method: failed to get WMMX data, status 0x%x!\n",iVar3);
      }
      uVar5 = 0xffff;
      goto LAB_0011210e;
    }
  }
  uVar5 = 0x56;
LAB_0011210e:
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00112170 __pfx_nv_acpi_extract_object =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001122a0) */

ulong __pfx_nv_acpi_extract_object(uint *param_1,void *param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  long in_GS_OFFSET;
  uint uStack_3c;
  long lStack_38;
  
  uVar2 = *param_1;
  uVar1 = (ulong)uVar2;
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (uVar2 == 3) {
    uVar2 = param_1[1];
    *param_4 = uVar2;
    if (uVar2 <= param_3) {
      memcpy(param_2,*(void **)(param_1 + 2),(ulong)uVar2);
      uVar1 = 0;
      goto LAB_00112279;
    }
LAB_001122a5:
    uVar1 = 2;
  }
  else {
    if (uVar2 < 4) {
      if (uVar2 == 0) goto LAB_00112279;
      if (uVar2 == 1) {
        uVar2 = (-(uint)(0xffffffff < *(ulong *)(param_1 + 2)) & 4) + 4;
        *param_4 = uVar2;
        if ((3 < param_3) && ((7 < param_3 || (*(ulong *)(param_1 + 2) < 0x100000000)))) {
          memcpy(param_2,param_1 + 2,(ulong)uVar2);
          uVar1 = 0;
          goto LAB_00112279;
        }
        goto LAB_001122a5;
      }
    }
    else if (uVar2 == 4) {
      *param_4 = 0;
      uVar1 = (ulong)param_1[1];
      uStack_3c = 0;
      if (param_1[1] != 0) {
        lVar3 = 0;
        do {
          param_3 = param_3 - uStack_3c;
          param_2 = (void *)((long)param_2 + (ulong)uStack_3c);
          uVar1 = nv_acpi_extract_object
                            (*(long *)(param_1 + 2) + lVar3 * 0x18,param_2,param_3,&uStack_3c);
          if ((int)uVar1 != 0) break;
          lVar3 = lVar3 + 1;
          *param_4 = *param_4 + uStack_3c;
        } while ((uint)lVar3 < param_1[1]);
      }
      goto LAB_00112279;
    }
    uVar1 = 0x56;
  }
LAB_00112279:
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}


// ===== 00112180 nv_acpi_extract_object =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001122a0) */

ulong nv_acpi_extract_object(uint *param_1,void *param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  long in_GS_OFFSET;
  uint local_3c;
  long local_38;
  
  uVar2 = *param_1;
  uVar1 = (ulong)uVar2;
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (uVar2 == 3) {
    uVar2 = param_1[1];
    *param_4 = uVar2;
    if (uVar2 <= param_3) {
      memcpy(param_2,*(void **)(param_1 + 2),(ulong)uVar2);
      uVar1 = 0;
      goto LAB_00112279;
    }
LAB_001122a5:
    uVar1 = 2;
  }
  else {
    if (uVar2 < 4) {
      if (uVar2 == 0) goto LAB_00112279;
      if (uVar2 == 1) {
        uVar2 = (-(uint)(0xffffffff < *(ulong *)(param_1 + 2)) & 4) + 4;
        *param_4 = uVar2;
        if ((3 < param_3) && ((7 < param_3 || (*(ulong *)(param_1 + 2) < 0x100000000)))) {
          memcpy(param_2,param_1 + 2,(ulong)uVar2);
          uVar1 = 0;
          goto LAB_00112279;
        }
        goto LAB_001122a5;
      }
    }
    else if (uVar2 == 4) {
      *param_4 = 0;
      uVar1 = (ulong)param_1[1];
      local_3c = 0;
      if (param_1[1] != 0) {
        lVar3 = 0;
        do {
          param_3 = param_3 - local_3c;
          param_2 = (void *)((long)param_2 + (ulong)local_3c);
          uVar1 = nv_acpi_extract_object
                            (*(long *)(param_1 + 2) + lVar3 * 0x18,param_2,param_3,&local_3c);
          if ((int)uVar1 != 0) break;
          lVar3 = lVar3 + 1;
          *param_4 = *param_4 + local_3c;
        } while ((uint)lVar3 < param_1[1]);
      }
      goto LAB_00112279;
    }
    uVar1 = 0x56;
  }
LAB_00112279:
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}


// ===== 001122d0 __pfx_nv_acpi_nvpcf_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_acpi_nvpcf_event(undefined8 param_1,int param_2,undefined8 *param_3)

{
  if (param_2 != 0xc0) {
    nv_printf(0,"NVRM: %s: NVPCF event 0x%x is not supported\n","nv_acpi_nvpcf_event",param_2);
    return;
  }
  rm_acpi_nvpcf_notify(*param_3);
  return;
}


// ===== 001122e0 nv_acpi_nvpcf_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_acpi_nvpcf_event(undefined8 param_1,int param_2,undefined8 *param_3)

{
  if (param_2 != 0xc0) {
    nv_printf(0,"NVRM: %s: NVPCF event 0x%x is not supported\n","nv_acpi_nvpcf_event",param_2);
    return;
  }
  rm_acpi_nvpcf_notify(*param_3);
  return;
}


// ===== 00112310 __pfx_nv_acpi_evaluate_dsm_method.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001124b4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nv_acpi_evaluate_dsm_method_constprop_0
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4,uint param_5,
              uint *param_6,char param_7,undefined8 param_8,undefined2 *param_9)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long in_GS_OFFSET;
  undefined1 auVar5 [16];
  ushort unaff_retaddr;
  undefined4 uStack_a4;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  long lStack_88;
  undefined8 auStack_80 [3];
  ulong auStack_68 [3];
  undefined4 uStack_50;
  ulong uStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  uint *puStack_30;
  long lStack_20;
  
  uVar4 = (ulong)param_4;
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar1 = 0;
  uStack_a0 = 0;
  uStack_98 = 0;
  uStack_90 = 0xffffffffffffffff;
  lStack_88 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)auStack_80 + uVar3) = 0;
    *(undefined8 *)((long)auStack_80 + uVar3 + 8) = 0;
    *(undefined8 *)((long)auStack_68 + (uVar3 - 8)) = 0;
    *(undefined8 *)((long)auStack_68 + uVar3) = 0;
  } while (uVar1 < 0x60);
  uStack_a4 = 0;
  auVar5 = (*_mpi_powm)();
  if (((auVar5._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    iVar2 = 0x56;
  }
  else {
    auStack_80[0] = 0x1000000003;
    auStack_68[1] = uVar4 & 0xffffffff;
    uStack_48 = (ulong)param_5;
    auStack_68[0]._0_4_ = 1;
    uStack_50 = 1;
    if (param_7 == '\0') {
      uStack_38 = 3;
      uStack_34 = (uint)unaff_retaddr;
      puStack_30 = param_6;
    }
    else {
      puStack_30 = (uint *)(ulong)*param_6;
      uStack_38 = 1;
    }
    uStack_a0 = CONCAT44(uStack_a0._4_4_,4);
    uStack_98 = auVar5._8_8_;
    auStack_80[1] = param_3;
    iVar2 = acpi_evaluate_object();
    if (iVar2 == 0) {
      if (lStack_88 == 0) {
        *param_9 = 0;
        iVar2 = 0;
      }
      else {
        iVar2 = nv_acpi_extract_object(lStack_88,param_8,*param_9,&uStack_a4);
        *param_9 = (short)uStack_a4;
        if (iVar2 != 0) {
          nv_printf(4,"NVRM: %s: DSM data invalid!\n","nv_acpi_evaluate_dsm_method");
        }
      }
      kfree(lStack_88);
    }
    else {
      nv_printf(0,"NVRM: %s: failed to evaluate _DSM method!\n","nv_acpi_evaluate_dsm_method");
      iVar2 = 0x59;
    }
  }
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// ===== 00112320 nv_acpi_evaluate_dsm_method.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001124b4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nv_acpi_evaluate_dsm_method_constprop_0
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4,uint param_5,
              uint *param_6,char param_7,undefined8 param_8,undefined2 *param_9)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long in_GS_OFFSET;
  undefined1 auVar5 [16];
  ushort unaff_retaddr;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  long local_88;
  undefined8 local_80 [3];
  ulong local_68 [3];
  undefined4 local_50;
  ulong local_48;
  undefined4 local_38;
  uint local_34;
  uint *local_30;
  long local_20;
  
  uVar4 = (ulong)param_4;
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar1 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0xffffffffffffffff;
  local_88 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_80 + uVar3) = 0;
    *(undefined8 *)((long)local_80 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_68 + (uVar3 - 8)) = 0;
    *(undefined8 *)((long)local_68 + uVar3) = 0;
  } while (uVar1 < 0x60);
  local_a4 = 0;
  auVar5 = (*_mpi_powm)();
  if (((auVar5._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    iVar2 = 0x56;
  }
  else {
    local_80[0] = 0x1000000003;
    local_68[1] = uVar4 & 0xffffffff;
    local_48 = (ulong)param_5;
    local_68[0]._0_4_ = 1;
    local_50 = 1;
    if (param_7 == '\0') {
      local_38 = 3;
      local_34 = (uint)unaff_retaddr;
      local_30 = param_6;
    }
    else {
      local_30 = (uint *)(ulong)*param_6;
      local_38 = 1;
    }
    local_a0 = CONCAT44(local_a0._4_4_,4);
    local_98 = auVar5._8_8_;
    local_80[1] = param_3;
    iVar2 = acpi_evaluate_object();
    if (iVar2 == 0) {
      if (local_88 == 0) {
        *param_9 = 0;
        iVar2 = 0;
      }
      else {
        iVar2 = nv_acpi_extract_object(local_88,param_8,*param_9,&local_a4);
        *param_9 = (short)local_a4;
        if (iVar2 != 0) {
          nv_printf(4,"NVRM: %s: DSM data invalid!\n","nv_acpi_evaluate_dsm_method");
        }
      }
      kfree(local_88);
    }
    else {
      nv_printf(0,"NVRM: %s: failed to evaluate _DSM method!\n","nv_acpi_evaluate_dsm_method");
      iVar2 = 0x59;
    }
  }
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// ===== 00112540 __pfx_nv_install_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001125fb) */

undefined8 * __pfx_nv_install_notifier(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  long in_GS_OFFSET;
  bool bVar5;
  undefined8 *puStack_38;
  long lStack_30;
  
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puStack_38 = (undefined8 *)0x0;
  if (param_1 == 0) {
    puVar4 = (undefined8 *)0x0;
    goto LAB_001125dc;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    puVar3 = (undefined4 *)0x0;
    iVar2 = os_alloc_mem(&puStack_38,0x28);
    if (iVar2 == 0) {
LAB_0011263f:
      os_mem_set(puStack_38,0,0x28);
      bVar5 = psr_device_handle == param_1;
      *puStack_38 = puVar3;
      puStack_38[2] = param_1;
      puStack_38[3] = param_3;
      if (bVar5) {
        iVar2 = acpi_install_notify_handler(param_1,3,param_2);
      }
      else {
        iVar2 = acpi_install_notify_handler(param_1,2,param_2);
      }
      if (iVar2 == 0) {
        *(undefined4 *)(puStack_38 + 4) = 1;
        puVar4 = puStack_38;
        goto LAB_001125dc;
      }
      if (puVar3 != (undefined4 *)0x0) goto LAB_00112688;
    }
LAB_001125b6:
    if (puStack_38 != (undefined8 *)0x0) {
      os_free_mem(puStack_38);
      puVar4 = (undefined8 *)0x0;
      goto LAB_001125dc;
    }
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      iVar2 = os_alloc_mem(&puStack_38,0x28);
      if (iVar2 == 0) goto LAB_0011263f;
LAB_00112688:
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3);
      }
      goto LAB_001125b6;
    }
  }
  puVar4 = (undefined8 *)0x0;
LAB_001125dc:
  if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return puVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00112550 nv_install_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001125fb) */

undefined8 * nv_install_notifier(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  long in_GS_OFFSET;
  bool bVar5;
  undefined8 *local_38;
  long local_30;
  
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_38 = (undefined8 *)0x0;
  if (param_1 == 0) {
    puVar4 = (undefined8 *)0x0;
    goto LAB_001125dc;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    puVar3 = (undefined4 *)0x0;
    iVar2 = os_alloc_mem(&local_38,0x28);
    if (iVar2 == 0) {
LAB_0011263f:
      os_mem_set(local_38,0,0x28);
      bVar5 = psr_device_handle == param_1;
      *local_38 = puVar3;
      local_38[2] = param_1;
      local_38[3] = param_3;
      if (bVar5) {
        iVar2 = acpi_install_notify_handler(param_1,3,param_2);
      }
      else {
        iVar2 = acpi_install_notify_handler(param_1,2,param_2);
      }
      if (iVar2 == 0) {
        *(undefined4 *)(local_38 + 4) = 1;
        puVar4 = local_38;
        goto LAB_001125dc;
      }
      if (puVar3 != (undefined4 *)0x0) goto LAB_00112688;
    }
LAB_001125b6:
    if (local_38 != (undefined8 *)0x0) {
      os_free_mem(local_38);
      puVar4 = (undefined8 *)0x0;
      goto LAB_001125dc;
    }
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      iVar2 = os_alloc_mem(&local_38,0x28);
      if (iVar2 == 0) goto LAB_0011263f;
LAB_00112688:
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3);
      }
      goto LAB_001125b6;
    }
  }
  puVar4 = (undefined8 *)0x0;
LAB_001125dc:
  if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return puVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00112710 __pfx_nv_uninstall_notifier.part.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_uninstall_notifier_part_0(long *param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  lVar1 = param_1[2];
  if (lVar1 == psr_device_handle) {
    iVar3 = acpi_remove_notify_handler(lVar1,3,param_2);
  }
  else {
    iVar3 = acpi_remove_notify_handler(lVar1,2,param_2);
  }
  if (iVar3 != 0) {
    nv_printf(0,"NVRM: nv_acpi_methods_uninit: failed to remove event notification handler (%d)!\n",
              iVar3);
    return;
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  os_free_mem(param_1);
  return;
}


// ===== 00112720 nv_uninstall_notifier.part.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_uninstall_notifier_part_0(long *param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  lVar1 = param_1[2];
  if (lVar1 == psr_device_handle) {
    iVar3 = acpi_remove_notify_handler(lVar1,3,param_2);
  }
  else {
    iVar3 = acpi_remove_notify_handler(lVar1,2,param_2);
  }
  if (iVar3 != 0) {
    nv_printf(0,"NVRM: nv_acpi_methods_uninit: failed to remove event notification handler (%d)!\n",
              iVar3);
    return;
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  os_free_mem(param_1);
  return;
}


// ===== 001127a0 __pfx_nv_acpi_powersource_hotplug_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001127e7) */

void __pfx_nv_acpi_powersource_hotplug_event(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  int iVar1;
  long in_GS_OFFSET;
  long lStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1127b9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((param_2 & 0xffffff7f) == 0) {
    lStack_18 = 0;
    if (psr_device_handle != 0) {
      iVar1 = acpi_evaluate_integer(psr_device_handle,&DAT_00daf092,0,&lStack_18);
      if (iVar1 == 0) {
        if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
          rm_power_source_change_event(*param_3,lStack_18 != 1);
          return;
        }
        goto LAB_00112847;
      }
    }
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
LAB_00112847:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001127b0 nv_acpi_powersource_hotplug_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001127e7) */

void nv_acpi_powersource_hotplug_event(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  int iVar1;
  long in_GS_OFFSET;
  long local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1127b9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((param_2 & 0xffffff7f) == 0) {
    local_18 = 0;
    if (psr_device_handle != 0) {
      iVar1 = acpi_evaluate_integer(psr_device_handle,&DAT_00daf092,0,&local_18);
      if (iVar1 == 0) {
        if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
          rm_power_source_change_event(*param_3,local_18 != 1);
          return;
        }
        goto LAB_00112847;
      }
    }
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
LAB_00112847:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00112850 __pfx_nv_acpi_get_powersource =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001128d6) */

undefined8 __pfx_nv_acpi_get_powersource(uint *param_1)

{
  undefined8 uVar1;
  long in_GS_OFFSET;
  long lStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_20 = 0;
  if ((param_1 == (uint *)0x0) || (psr_device_handle == 0)) {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = acpi_evaluate_integer(psr_device_handle,&DAT_00daf092,0,&lStack_20);
    if ((int)uVar1 == 0) {
      *param_1 = (uint)(lStack_20 == 1);
    }
    else {
      uVar1 = 0xffff;
    }
  }
  if (lStack_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}


// ===== 00112860 nv_acpi_get_powersource =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001128d6) */

undefined8 nv_acpi_get_powersource(uint *param_1)

{
  undefined8 uVar1;
  long in_GS_OFFSET;
  long local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  if ((param_1 == (uint *)0x0) || (psr_device_handle == 0)) {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = acpi_evaluate_integer(psr_device_handle,&DAT_00daf092,0,&local_20);
    if ((int)uVar1 == 0) {
      *param_1 = (uint)(local_20 == 1);
    }
    else {
      uVar1 = 0xffff;
    }
  }
  if (local_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}


// ===== 00112900 __pfx_nv_acpi_register_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_acpi_register_notifier(long param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x2b0);
  cVar1 = is_acpi_device_node(lVar2);
  if ((((cVar1 != '\0') && (lVar2 != 0x10)) && (*(long *)(param_1 + 0x8b0) == 0)) &&
     (*(long *)(lVar2 + -8) != 0)) {
    lVar2 = nv_install_notifier(*(long *)(lVar2 + -8),nv_acpi_notify_event,param_1);
    *(long *)(param_1 + 0x8b0) = lVar2;
    if (lVar2 == 0) {
      nv_printf(4,"NVRM: nv_acpi_register_notifier: failed to install notifier\n");
    }
  }
  *(code **)(param_1 + 0x898) = nv_acpi_notifier_call_chain_handler;
  register_acpi_notifier(param_1 + 0x898);
  return;
}


// ===== 00112910 nv_acpi_register_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_acpi_register_notifier(long param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x2b0);
  cVar1 = is_acpi_device_node(lVar2);
  if ((((cVar1 != '\0') && (lVar2 != 0x10)) && (*(long *)(param_1 + 0x8b0) == 0)) &&
     (*(long *)(lVar2 + -8) != 0)) {
    lVar2 = nv_install_notifier(*(long *)(lVar2 + -8),nv_acpi_notify_event,param_1);
    *(long *)(param_1 + 0x8b0) = lVar2;
    if (lVar2 == 0) {
      nv_printf(4,"NVRM: nv_acpi_register_notifier: failed to install notifier\n");
    }
  }
  *(code **)(param_1 + 0x898) = nv_acpi_notifier_call_chain_handler;
  register_acpi_notifier(param_1 + 0x898);
  return;
}


// ===== 001129a0 __pfx_nv_acpi_unregister_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001129f4) */

void __pfx_nv_acpi_unregister_notifier(long param_1)

{
  long lVar1;
  
  unregister_acpi_notifier(param_1 + 0x898);
  lVar1 = *(long *)(param_1 + 0x8b0);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 0x20) != 0) {
      nv_uninstall_notifier_part_0(lVar1,nv_acpi_notify_event);
    }
    *(undefined8 *)(param_1 + 0x8b0) = 0;
  }
  return;
}


// ===== 001129b0 nv_acpi_unregister_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001129f4) */

void nv_acpi_unregister_notifier(long param_1)

{
  long lVar1;
  
  unregister_acpi_notifier(param_1 + 0x898);
  lVar1 = *(long *)(param_1 + 0x8b0);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 0x20) != 0) {
      nv_uninstall_notifier_part_0(lVar1,nv_acpi_notify_event);
    }
    *(undefined8 *)(param_1 + 0x8b0) = 0;
  }
  return;
}


// ===== 00112a00 __pfx_nv_acpi_methods_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112ad9) */
/* WARNING: Removing unreachable block (ram,0x00112a94) */
/* WARNING: Removing unreachable block (ram,0x00112a99) */

long __pfx_nv_acpi_methods_init(uint *param_1)

{
  long in_RAX;
  long lVar1;
  
  if (param_1 == (uint *)0x0) {
    return in_RAX;
  }
  *param_1 = 0;
  acpi_walk_namespace(6,0xffffffffffffffff,0xffffffff,nv_acpi_find_methods,0,0);
  lVar1 = 0;
  if (nvif_handle != 0) {
    *param_1 = 1;
  }
  if (wmmx_handle != 0) {
    *param_1 = *param_1 | 4;
  }
  if ((psr_handle != 0) && (psr_nv_acpi_object == 0)) {
    lVar1 = nv_install_notifier(psr_device_handle,nv_acpi_powersource_hotplug_event,0);
    psr_nv_acpi_object = lVar1;
  }
  if ((nvpcf_handle != 0) && (nvpcf_nv_acpi_object == 0)) {
    nvpcf_nv_acpi_object = nv_install_notifier(nvpcf_device_handle,nv_acpi_nvpcf_event,0);
    return nvpcf_nv_acpi_object;
  }
  return lVar1;
}


// ===== 00112a10 nv_acpi_methods_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112ad9) */
/* WARNING: Removing unreachable block (ram,0x00112a94) */
/* WARNING: Removing unreachable block (ram,0x00112a99) */

long nv_acpi_methods_init(uint *param_1)

{
  long in_RAX;
  long lVar1;
  
  if (param_1 == (uint *)0x0) {
    return in_RAX;
  }
  *param_1 = 0;
  acpi_walk_namespace(6,0xffffffffffffffff,0xffffffff,nv_acpi_find_methods,0,0);
  lVar1 = 0;
  if (nvif_handle != 0) {
    *param_1 = 1;
  }
  if (wmmx_handle != 0) {
    *param_1 = *param_1 | 4;
  }
  if ((psr_handle != 0) && (psr_nv_acpi_object == 0)) {
    lVar1 = nv_install_notifier(psr_device_handle,nv_acpi_powersource_hotplug_event,0);
    psr_nv_acpi_object = lVar1;
  }
  if ((nvpcf_handle != 0) && (nvpcf_nv_acpi_object == 0)) {
    nvpcf_nv_acpi_object = nv_install_notifier(nvpcf_device_handle,nv_acpi_nvpcf_event,0);
    return nvpcf_nv_acpi_object;
  }
  return lVar1;
}


// ===== 00112ae0 __pfx_nv_acpi_methods_uninit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112b83) */

void __pfx_nv_acpi_methods_uninit(void)

{
  nvif_handle = 0;
  wmmx_handle = 0;
  if (psr_nv_acpi_object != 0) {
    if (*(int *)(psr_nv_acpi_object + 0x20) != 0) {
      nv_uninstall_notifier_part_0(psr_nv_acpi_object,nv_acpi_powersource_hotplug_event);
    }
    psr_handle = 0;
    psr_device_handle = 0;
    psr_nv_acpi_object = 0;
  }
  if (nvpcf_nv_acpi_object != 0) {
    if (*(int *)(nvpcf_nv_acpi_object + 0x20) != 0) {
      nv_uninstall_notifier_part_0(nvpcf_nv_acpi_object,nv_acpi_nvpcf_event);
    }
    nvpcf_handle = 0;
    nvpcf_device_handle = 0;
    nvpcf_nv_acpi_object = 0;
  }
  return;
}


// ===== 00112af0 nv_acpi_methods_uninit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112b83) */

void nv_acpi_methods_uninit(void)

{
  nvif_handle = 0;
  wmmx_handle = 0;
  if (psr_nv_acpi_object != 0) {
    if (*(int *)(psr_nv_acpi_object + 0x20) != 0) {
      nv_uninstall_notifier_part_0(psr_nv_acpi_object,nv_acpi_powersource_hotplug_event);
    }
    psr_handle = 0;
    psr_device_handle = 0;
    psr_nv_acpi_object = 0;
  }
  if (nvpcf_nv_acpi_object != 0) {
    if (*(int *)(nvpcf_nv_acpi_object + 0x20) != 0) {
      nv_uninstall_notifier_part_0(nvpcf_nv_acpi_object,nv_acpi_nvpcf_event);
    }
    nvpcf_handle = 0;
    nvpcf_device_handle = 0;
    nvpcf_nv_acpi_object = 0;
  }
  return;
}


// ===== 00112ba0 __pfx_nv_acpi_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112bdc) */

undefined8
__pfx_nv_acpi_method
          (int param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,undefined2 param_5,
          undefined8 param_6)

{
  undefined8 uVar1;
  undefined8 unaff_retaddr;
  
  if (param_1 == 1) {
    uVar1 = nv_acpi_nvif_method(param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  if (param_1 != 2) {
    return 0x56;
  }
  uVar1 = nv_acpi_wmmx_method(param_2,unaff_retaddr);
  return uVar1;
}


// ===== 00112bb0 nv_acpi_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112bdc) */

undefined8
nv_acpi_method(int param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
              undefined2 param_5,undefined8 param_6)

{
  undefined8 uVar1;
  undefined8 unaff_retaddr;
  
  if (param_1 == 1) {
    uVar1 = nv_acpi_nvif_method(param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  if (param_1 != 2) {
    return 0x56;
  }
  uVar1 = nv_acpi_wmmx_method(param_2,unaff_retaddr);
  return uVar1;
}


// ===== 00112c10 __pfx_nv_acpi_dsm_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112d8d) */

ulong __pfx_nv_acpi_dsm_method
                (long param_1,undefined8 param_2,undefined4 param_3,char param_4,undefined4 param_5,
                void *param_6,undefined8 param_7,long param_8,long param_9)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  long in_GS_OFFSET;
  ushort unaff_retaddr;
  void *pvStack_48;
  long lStack_40;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar6 = 0;
  pvStack_48 = (void *)0x0;
  cVar2 = is_acpi_device_node(lVar1);
  if (((cVar2 != '\0') && (lVar1 != 0x10)) && (lVar1 = *(long *)(lVar1 + -8), lVar1 != 0)) {
    if (((param_6 != (void *)0x0) && (unaff_retaddr < 0x401)) && ((param_8 != 0 && (param_9 != 0))))
    {
      uVar4 = os_alloc_mem(&pvStack_48,(ulong)unaff_retaddr);
      if ((int)uVar4 == 0) {
        memcpy(pvStack_48,param_6,(ulong)unaff_retaddr);
        pcVar5 = "\\_SB.NPCF._DSM";
        if (param_4 == '\0') {
          pcVar5 = "_DSM";
          lVar6 = lVar1;
        }
        uVar3 = nv_acpi_evaluate_dsm_method_constprop_0
                          (lVar6,pcVar5,param_2,param_3,param_5,pvStack_48,unaff_retaddr,0,param_8,
                           param_9);
        os_free_mem(pvStack_48);
        uVar4 = (ulong)uVar3;
      }
      goto LAB_00112d70;
    }
    nv_printf(0,"NVRM: %s: invalid argument(s)!\n","nv_acpi_dsm_method");
  }
  uVar4 = 0x1f;
LAB_00112d70:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00112c20 nv_acpi_dsm_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112d8d) */

ulong nv_acpi_dsm_method(long param_1,undefined8 param_2,undefined4 param_3,char param_4,
                        undefined4 param_5,void *param_6,undefined8 param_7,long param_8,
                        long param_9)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  long in_GS_OFFSET;
  ushort unaff_retaddr;
  void *local_48;
  long local_40;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar6 = 0;
  local_48 = (void *)0x0;
  cVar2 = is_acpi_device_node(lVar1);
  if (((cVar2 != '\0') && (lVar1 != 0x10)) && (lVar1 = *(long *)(lVar1 + -8), lVar1 != 0)) {
    if (((param_6 != (void *)0x0) && (unaff_retaddr < 0x401)) && ((param_8 != 0 && (param_9 != 0))))
    {
      uVar4 = os_alloc_mem(&local_48,(ulong)unaff_retaddr);
      if ((int)uVar4 == 0) {
        memcpy(local_48,param_6,(ulong)unaff_retaddr);
        pcVar5 = "\\_SB.NPCF._DSM";
        if (param_4 == '\0') {
          pcVar5 = "_DSM";
          lVar6 = lVar1;
        }
        uVar3 = nv_acpi_evaluate_dsm_method_constprop_0
                          (lVar6,pcVar5,param_2,param_3,param_5,local_48,unaff_retaddr,0,param_8,
                           param_9);
        os_free_mem(local_48);
        uVar4 = (ulong)uVar3;
      }
      goto LAB_00112d70;
    }
    nv_printf(0,"NVRM: %s: invalid argument(s)!\n","nv_acpi_dsm_method");
  }
  uVar4 = 0x1f;
LAB_00112d70:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00112da0 __pfx_nv_acpi_ddc_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112fc3) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_nv_acpi_ddc_method(long param_1,void *param_2,uint *param_3,char param_4)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined4 uVar9;
  long in_GS_OFFSET;
  long alStack_80 [2];
  int *piStack_70;
  undefined8 uStack_68;
  uint *puStack_60;
  uint auStack_58 [3];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  cVar4 = is_acpi_device_node(lVar1);
  if ((cVar4 != '\0') && (lVar1 != 0x10)) {
    lVar1 = *(long *)(lVar1 + -8);
    alStack_80[0] = 0;
    if (lVar1 != 0) {
      uVar8 = (*_mpi_powm)();
      if (((uVar8 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)
         ) {
        uVar9 = 0x56;
      }
      else {
LAB_00112e58:
        do {
          do {
            auStack_58[0] = 0;
            auStack_58[1] = 0;
            iVar5 = acpi_get_next_object(6,lVar1,alStack_80[0],alStack_80);
            if ((iVar5 != 0) || (alStack_80[0] == 0)) {
              nv_printf(0,"NVRM: %s LCD not found\n","nv_acpi_ddc_method");
              goto LAB_00112ffa;
            }
            iVar5 = acpi_evaluate_integer(alStack_80[0],&DAT_00daf0d7,0,auStack_58);
            lVar2 = alStack_80[0];
          } while (iVar5 != 0);
          uVar6 = auStack_58[0] & 0xffff;
          if (uVar6 != 0x400) {
            if (uVar6 < 0x401) {
              if ((auStack_58[0] & 0xfff7) != 0x110) goto LAB_00112e58;
            }
            else if (uVar6 != 0xa420) goto LAB_00112e58;
          }
          nv_printf(0,"NVRM: %s Found LCD: %llx\n","nv_acpi_ddc_method");
        } while (lVar2 == 0);
        iVar5 = 2 - (uint)(param_4 == '\0');
        while( true ) {
          auStack_58[1] = 0;
          uStack_48 = 0;
          uStack_44 = 0;
          auStack_58[0] = 1;
          uStack_4c = 0;
          alStack_80[1] = 0xffffffffffffffff;
          piStack_70 = (int *)0x0;
          uStack_68 = 1;
          puStack_60 = auStack_58;
          auStack_58[2] = iVar5;
          iVar7 = acpi_evaluate_object(lVar2,&DAT_00daf10e,&uStack_68,alStack_80 + 1);
          piVar3 = piStack_70;
          if (iVar7 == 0) break;
          if (iVar5 == 1) {
            nv_printf(0,"NVRM: %s: failed status: %08x \n","nv_acpi_ddc_method");
LAB_00112ffa:
            uVar9 = 0xffff;
            goto LAB_00112f96;
          }
          iVar5 = 1;
        }
        if (((piStack_70 != (int *)0x0) && (*piStack_70 == 3)) &&
           (uVar6 = piStack_70[1], uVar6 != 0)) {
          if (*param_3 < uVar6) {
            kfree(piStack_70);
            uVar9 = 2;
            goto LAB_00112f96;
          }
          *param_3 = uVar6;
          memcpy(param_2,*(void **)(piStack_70 + 2),(ulong)uVar6);
        }
        kfree(piVar3);
        uVar9 = 0;
      }
      goto LAB_00112f96;
    }
  }
  uVar9 = 0x1f;
LAB_00112f96:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}


// ===== 00112db0 nv_acpi_ddc_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00112fc3) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nv_acpi_ddc_method(long param_1,void *param_2,uint *param_3,char param_4)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined4 uVar9;
  long in_GS_OFFSET;
  long local_80 [2];
  int *local_70;
  undefined8 local_68;
  uint *local_60;
  uint local_58 [3];
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  cVar4 = is_acpi_device_node(lVar1);
  if ((cVar4 != '\0') && (lVar1 != 0x10)) {
    lVar1 = *(long *)(lVar1 + -8);
    local_80[0] = 0;
    if (lVar1 != 0) {
      uVar8 = (*_mpi_powm)();
      if (((uVar8 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)
         ) {
        uVar9 = 0x56;
      }
      else {
LAB_00112e58:
        do {
          do {
            local_58[0] = 0;
            local_58[1] = 0;
            iVar5 = acpi_get_next_object(6,lVar1,local_80[0],local_80);
            if ((iVar5 != 0) || (local_80[0] == 0)) {
              nv_printf(0,"NVRM: %s LCD not found\n","nv_acpi_ddc_method");
              goto LAB_00112ffa;
            }
            iVar5 = acpi_evaluate_integer(local_80[0],&DAT_00daf0d7,0,local_58);
            lVar2 = local_80[0];
          } while (iVar5 != 0);
          uVar6 = local_58[0] & 0xffff;
          if (uVar6 != 0x400) {
            if (uVar6 < 0x401) {
              if ((local_58[0] & 0xfff7) != 0x110) goto LAB_00112e58;
            }
            else if (uVar6 != 0xa420) goto LAB_00112e58;
          }
          nv_printf(0,"NVRM: %s Found LCD: %llx\n","nv_acpi_ddc_method");
        } while (lVar2 == 0);
        iVar5 = 2 - (uint)(param_4 == '\0');
        while( true ) {
          local_58[1] = 0;
          uStack_48 = 0;
          local_44 = 0;
          local_58[0] = 1;
          local_4c = 0;
          local_80[1] = 0xffffffffffffffff;
          local_70 = (int *)0x0;
          local_68 = 1;
          local_60 = local_58;
          local_58[2] = iVar5;
          iVar7 = acpi_evaluate_object(lVar2,&DAT_00daf10e,&local_68,local_80 + 1);
          piVar3 = local_70;
          if (iVar7 == 0) break;
          if (iVar5 == 1) {
            nv_printf(0,"NVRM: %s: failed status: %08x \n","nv_acpi_ddc_method");
LAB_00112ffa:
            uVar9 = 0xffff;
            goto LAB_00112f96;
          }
          iVar5 = 1;
        }
        if (((local_70 != (int *)0x0) && (*local_70 == 3)) && (uVar6 = local_70[1], uVar6 != 0)) {
          if (*param_3 < uVar6) {
            kfree(local_70);
            uVar9 = 2;
            goto LAB_00112f96;
          }
          *param_3 = uVar6;
          memcpy(param_2,*(void **)(local_70 + 2),(ulong)uVar6);
        }
        kfree(piVar3);
        uVar9 = 0;
      }
      goto LAB_00112f96;
    }
  }
  uVar9 = 0x1f;
LAB_00112f96:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}


// ===== 00113090 __pfx_nv_acpi_rom_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113214) */
/* WARNING: Removing unreachable block (ram,0x001131c9) */
/* WARNING: Removing unreachable block (ram,0x001131cf) */
/* WARNING: Removing unreachable block (ram,0x001131d5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_nv_acpi_rom_method(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  undefined4 uVar6;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  cVar3 = is_acpi_device_node(lVar2);
  if (((cVar3 == '\0') || (lVar2 == 0x10)) || (*(long *)(lVar2 + -8) == 0)) {
    uVar6 = 0x1f;
  }
  else {
    uVar5 = (*_mpi_powm)();
    if (((uVar5 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0))
    {
      uVar6 = 0x56;
    }
    else {
      iVar4 = acpi_evaluate_object();
      if (iVar4 == 0) {
        nv_printf(0,"NVRM: %s: Invalid _ROM data\n","nv_acpi_rom_method");
        kfree(0);
      }
      else {
        nv_printf(0,"NVRM: %s: failed to evaluate _ROM method!\n","nv_acpi_rom_method");
      }
      uVar6 = 0xffff;
    }
  }
  if (lVar1 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}


// ===== 001130a0 nv_acpi_rom_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113214) */
/* WARNING: Removing unreachable block (ram,0x001131c9) */
/* WARNING: Removing unreachable block (ram,0x001131cf) */
/* WARNING: Removing unreachable block (ram,0x001131d5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nv_acpi_rom_method(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  undefined4 uVar6;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  cVar3 = is_acpi_device_node(lVar2);
  if (((cVar3 == '\0') || (lVar2 == 0x10)) || (*(long *)(lVar2 + -8) == 0)) {
    uVar6 = 0x1f;
  }
  else {
    uVar5 = (*_mpi_powm)();
    if (((uVar5 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0))
    {
      uVar6 = 0x56;
    }
    else {
      iVar4 = acpi_evaluate_object();
      if (iVar4 == 0) {
        nv_printf(0,"NVRM: %s: Invalid _ROM data\n","nv_acpi_rom_method");
        kfree(0);
      }
      else {
        nv_printf(0,"NVRM: %s: failed to evaluate _ROM method!\n","nv_acpi_rom_method");
      }
      uVar6 = 0xffff;
    }
  }
  if (lVar1 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}


// ===== 00113270 __pfx_nv_acpi_dod_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001133e1) */
/* WARNING: Removing unreachable block (ram,0x00113342) */
/* WARNING: Removing unreachable block (ram,0x0011334b) */
/* WARNING: Removing unreachable block (ram,0x0011335b) */
/* WARNING: Removing unreachable block (ram,0x00113363) */
/* WARNING: Removing unreachable block (ram,0x00113398) */
/* WARNING: Removing unreachable block (ram,0x001133a4) */
/* WARNING: Removing unreachable block (ram,0x00113380) */
/* WARNING: Removing unreachable block (ram,0x00113413) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_nv_acpi_dod_method(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  cVar3 = is_acpi_device_node(lVar2);
  if (((cVar3 == '\0') || (lVar2 == 0x10)) || (*(long *)(lVar2 + -8) == 0)) {
    uVar5 = 0x1f;
  }
  else {
    uVar6 = (*_mpi_powm)();
    if (((uVar6 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0))
    {
      uVar5 = 0x56;
    }
    else {
      iVar4 = acpi_evaluate_object();
      if (iVar4 == 0) {
        *param_3 = 0;
        nv_printf(0,"NVRM: %s: _DOD data too large!\n","nv_acpi_dod_method");
        kfree(0);
      }
      else {
        nv_printf(0,"NVRM: %s: failed to evaluate _DOD method!\n","nv_acpi_dod_method");
      }
      uVar5 = 0xffff;
    }
  }
  if (lVar1 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00113280 nv_acpi_dod_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001133e1) */
/* WARNING: Removing unreachable block (ram,0x00113342) */
/* WARNING: Removing unreachable block (ram,0x0011334b) */
/* WARNING: Removing unreachable block (ram,0x0011335b) */
/* WARNING: Removing unreachable block (ram,0x00113363) */
/* WARNING: Removing unreachable block (ram,0x00113398) */
/* WARNING: Removing unreachable block (ram,0x001133a4) */
/* WARNING: Removing unreachable block (ram,0x00113380) */
/* WARNING: Removing unreachable block (ram,0x00113413) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nv_acpi_dod_method(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  cVar3 = is_acpi_device_node(lVar2);
  if (((cVar3 == '\0') || (lVar2 == 0x10)) || (*(long *)(lVar2 + -8) == 0)) {
    uVar5 = 0x1f;
  }
  else {
    uVar6 = (*_mpi_powm)();
    if (((uVar6 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0))
    {
      uVar5 = 0x56;
    }
    else {
      iVar4 = acpi_evaluate_object();
      if (iVar4 == 0) {
        *param_3 = 0;
        nv_printf(0,"NVRM: %s: _DOD data too large!\n","nv_acpi_dod_method");
        kfree(0);
      }
      else {
        nv_printf(0,"NVRM: %s: failed to evaluate _DOD method!\n","nv_acpi_dod_method");
      }
      uVar5 = 0xffff;
    }
  }
  if (lVar1 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00113440 __pfx_nv_acpi_power_resource_method_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011350b) */

undefined8 __pfx_nv_acpi_power_resource_method_present(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 uStack_28;
  int *piStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 0x380);
  cVar2 = is_acpi_device_node(lVar1);
  if ((cVar2 != '\0') && (lVar1 != 0x10)) {
    uStack_28 = 0xffffffffffffffff;
    piStack_20 = (int *)0x0;
    if (*(long *)(lVar1 + -8) != 0) {
      iVar3 = acpi_evaluate_object(*(long *)(lVar1 + -8),&DAT_00daf13a,0,&uStack_28);
      if (iVar3 == 0) {
        if (piStack_20 == (int *)0x0) {
          nv_printf(0,"NVRM: output buffer pointer is null for _PR3 method\n");
        }
        else if ((*piStack_20 == 4) || (piStack_20[1] == 1)) {
          if (((*(int **)(piStack_20 + 2))[1] == 0xb) || (**(int **)(piStack_20 + 2) == 0x14)) {
            kfree();
            uVar4 = 1;
            goto LAB_001134f7;
          }
          nv_printf(4,"NVRM: _PR3 object does not contain POWER Reference\n");
          kfree(piStack_20);
        }
        else {
          nv_printf(4,"NVRM: _PR3 object is not a type \'package\'\n");
          kfree(piStack_20);
        }
      }
      else {
        nv_printf(0,"NVRM: Failed to evaluate _PR3 object\n");
      }
    }
  }
  uVar4 = 0;
LAB_001134f7:
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00113450 nv_acpi_power_resource_method_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011350b) */

undefined8 nv_acpi_power_resource_method_present(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 local_28;
  int *local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 0x380);
  cVar2 = is_acpi_device_node(lVar1);
  if ((cVar2 != '\0') && (lVar1 != 0x10)) {
    local_28 = 0xffffffffffffffff;
    local_20 = (int *)0x0;
    if (*(long *)(lVar1 + -8) != 0) {
      iVar3 = acpi_evaluate_object(*(long *)(lVar1 + -8),&DAT_00daf13a,0,&local_28);
      if (iVar3 == 0) {
        if (local_20 == (int *)0x0) {
          nv_printf(0,"NVRM: output buffer pointer is null for _PR3 method\n");
        }
        else if ((*local_20 == 4) || (local_20[1] == 1)) {
          if (((*(int **)(local_20 + 2))[1] == 0xb) || (**(int **)(local_20 + 2) == 0x14)) {
            kfree();
            uVar4 = 1;
            goto LAB_001134f7;
          }
          nv_printf(4,"NVRM: _PR3 object does not contain POWER Reference\n");
          kfree(local_20);
        }
        else {
          nv_printf(4,"NVRM: _PR3 object is not a type \'package\'\n");
          kfree(local_20);
        }
      }
      else {
        nv_printf(0,"NVRM: Failed to evaluate _PR3 object\n");
      }
    }
  }
  uVar4 = 0;
LAB_001134f7:
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00113560 __pfx_nv_acpi_mux_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001137ae) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_nv_acpi_mux_method(long param_1,undefined4 *param_2,ulong param_3,char *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  long lStack_78;
  ulong auStack_70 [2];
  int *piStack_60;
  undefined8 uStack_58;
  undefined4 *puStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  long lStack_30;
  
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puStack_50 = &uStack_48;
  auStack_70[1] = 0xffffffffffffffff;
  piStack_60 = (int *)0x0;
  uStack_34 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_48 = 1;
  uStack_58 = 1;
  cVar2 = is_acpi_device_node(lVar1);
  if ((cVar2 == '\0') || (lVar1 == 0x10)) {
    lStack_78 = 0;
    auStack_70[0] = 0;
    iVar3 = strcmp(param_4,"MXDS");
    if ((iVar3 == 0) || (iVar3 = strcmp(param_4,"MXDM"), iVar3 == 0)) {
      nv_printf(0,"NVRM: %s: Call for %s ACPI method \n","nv_acpi_mux_method",param_4);
LAB_001137e2:
      uVar4 = 0x1f;
      goto LAB_00113791;
    }
LAB_00113771:
    nv_printf(4,"NVRM: %s: Unsupported ACPI method %s\n","nv_acpi_mux_method",param_4);
  }
  else {
    lVar1 = *(long *)(lVar1 + -8);
    lStack_78 = 0;
    auStack_70[0] = 0;
    iVar3 = strcmp(param_4,"MXDS");
    if ((iVar3 != 0) && (iVar3 = strcmp(param_4,"MXDM"), iVar3 != 0)) goto LAB_00113771;
    nv_printf(0,"NVRM: %s: Call for %s ACPI method \n","nv_acpi_mux_method",param_4);
    if (lVar1 == 0) goto LAB_001137e2;
    uVar5 = (*_mpi_powm)();
    if (((uVar5 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0))
    {
      do {
        iVar3 = acpi_get_next_object(6,lVar1,lStack_78,&lStack_78);
        if ((iVar3 != 0) || (lStack_78 == 0)) {
          nv_printf(0,"NVRM: %s Mux device handle not found\n","nv_acpi_mux_method");
          goto LAB_00113732;
        }
        iVar3 = acpi_evaluate_integer(lStack_78,&DAT_00daf0d7,0,auStack_70);
      } while (((iVar3 != 0) || ((param_3 & 0xffffffff) != auStack_70[0])) || (lStack_78 == 0));
      uStack_40 = *param_2;
      uStack_48 = 1;
      uStack_3c = 0;
      iVar3 = acpi_evaluate_object(lStack_78,param_4,&uStack_58,auStack_70 + 1);
      if (iVar3 == 0) {
        if ((piStack_60 != (int *)0x0) && (*piStack_60 == 1)) {
          *param_2 = (int)*(undefined8 *)(piStack_60 + 2);
          kfree();
          uVar4 = 0;
          goto LAB_00113791;
        }
        nv_printf(0,"NVRM: %s: Invalid MUX data\n","nv_acpi_mux_method");
        kfree(piStack_60);
      }
      else {
        nv_printf(0,"NVRM: %s: Failed to evaluate %s method!\n","nv_acpi_mux_method",param_4);
      }
LAB_00113732:
      uVar4 = 0xffff;
      goto LAB_00113791;
    }
  }
  uVar4 = 0x56;
LAB_00113791:
  if (lStack_30 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00113570 nv_acpi_mux_method =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001137ae) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nv_acpi_mux_method(long param_1,undefined4 *param_2,ulong param_3,char *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  long local_78;
  ulong local_70 [2];
  int *local_60;
  undefined8 local_58;
  undefined4 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  long local_30;
  
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_50 = &local_48;
  local_70[1] = 0xffffffffffffffff;
  local_60 = (int *)0x0;
  local_34 = 0;
  local_44 = 0;
  uStack_40 = 0;
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2b0);
  local_3c = 0;
  uStack_38 = 0;
  local_48 = 1;
  local_58 = 1;
  cVar2 = is_acpi_device_node(lVar1);
  if ((cVar2 == '\0') || (lVar1 == 0x10)) {
    local_78 = 0;
    local_70[0] = 0;
    iVar3 = strcmp(param_4,"MXDS");
    if ((iVar3 == 0) || (iVar3 = strcmp(param_4,"MXDM"), iVar3 == 0)) {
      nv_printf(0,"NVRM: %s: Call for %s ACPI method \n","nv_acpi_mux_method",param_4);
LAB_001137e2:
      uVar4 = 0x1f;
      goto LAB_00113791;
    }
LAB_00113771:
    nv_printf(4,"NVRM: %s: Unsupported ACPI method %s\n","nv_acpi_mux_method",param_4);
  }
  else {
    lVar1 = *(long *)(lVar1 + -8);
    local_78 = 0;
    local_70[0] = 0;
    iVar3 = strcmp(param_4,"MXDS");
    if ((iVar3 != 0) && (iVar3 = strcmp(param_4,"MXDM"), iVar3 != 0)) goto LAB_00113771;
    nv_printf(0,"NVRM: %s: Call for %s ACPI method \n","nv_acpi_mux_method",param_4);
    if (lVar1 == 0) goto LAB_001137e2;
    uVar5 = (*_mpi_powm)();
    if (((uVar5 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0))
    {
      do {
        iVar3 = acpi_get_next_object(6,lVar1,local_78,&local_78);
        if ((iVar3 != 0) || (local_78 == 0)) {
          nv_printf(0,"NVRM: %s Mux device handle not found\n","nv_acpi_mux_method");
          goto LAB_00113732;
        }
        iVar3 = acpi_evaluate_integer(local_78,&DAT_00daf0d7,0,local_70);
      } while (((iVar3 != 0) || ((param_3 & 0xffffffff) != local_70[0])) || (local_78 == 0));
      uStack_40 = *param_2;
      local_48 = 1;
      local_3c = 0;
      iVar3 = acpi_evaluate_object(local_78,param_4,&local_58,local_70 + 1);
      if (iVar3 == 0) {
        if ((local_60 != (int *)0x0) && (*local_60 == 1)) {
          *param_2 = (int)*(undefined8 *)(local_60 + 2);
          kfree();
          uVar4 = 0;
          goto LAB_00113791;
        }
        nv_printf(0,"NVRM: %s: Invalid MUX data\n","nv_acpi_mux_method");
        kfree(local_60);
      }
      else {
        nv_printf(0,"NVRM: %s: Failed to evaluate %s method!\n","nv_acpi_mux_method",param_4);
      }
LAB_00113732:
      uVar4 = 0xffff;
      goto LAB_00113791;
    }
  }
  uVar4 = 0x56;
LAB_00113791:
  if (local_30 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00113850 __pfx_nv_acpi_is_battery_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113899) */

bool __pfx_nv_acpi_is_battery_present(void)

{
  acpi_walk_namespace(6,0xffffffffffffffff,0xffffffff,nv_acpi_find_battery_device,0,0,0,0x113869);
  return battery_present == '\x01';
}


// ===== 00113860 nv_acpi_is_battery_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113899) */

bool nv_acpi_is_battery_present(void)

{
  acpi_walk_namespace(6,0xffffffffffffffff,0xffffffff,nv_acpi_find_battery_device,0,0,0,0x113869);
  return battery_present == '\x01';
}


// ===== 001138a0 __pfx_nv_acpi_d3cold_dsm_for_upstream_port =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011397a) */

undefined8
__pfx_nv_acpi_d3cold_dsm_for_upstream_port
          (long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x40) + 0x2b0);
  cVar2 = is_acpi_device_node(lVar1);
  if ((cVar2 != '\0') && (lVar1 != 0x10)) {
    uStack_3c = 0;
    uStack_3e = 4;
    if (*(long *)(lVar1 + -8) != 0) {
      uVar3 = nv_acpi_evaluate_dsm_method_constprop_0
                        (*(long *)(lVar1 + -8),&DAT_00daf0c3,param_2,param_3,param_4,param_5,4,1,
                         &uStack_3c,&uStack_3e);
      if ((int)uVar3 == 0) {
        *param_5 = uStack_3c;
      }
      goto LAB_0011395f;
    }
  }
  uVar3 = 0x1f;
LAB_0011395f:
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001138b0 nv_acpi_d3cold_dsm_for_upstream_port =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011397a) */

undefined8
nv_acpi_d3cold_dsm_for_upstream_port
          (long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  undefined2 local_3e;
  undefined4 local_3c;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x40) + 0x2b0);
  cVar2 = is_acpi_device_node(lVar1);
  if ((cVar2 != '\0') && (lVar1 != 0x10)) {
    local_3c = 0;
    local_3e = 4;
    if (*(long *)(lVar1 + -8) != 0) {
      uVar3 = nv_acpi_evaluate_dsm_method_constprop_0
                        (*(long *)(lVar1 + -8),&DAT_00daf0c3,param_2,param_3,param_4,param_5,4,1,
                         &local_3c,&local_3e);
      if ((int)uVar3 == 0) {
        *param_5 = local_3c;
      }
      goto LAB_0011395f;
    }
  }
  uVar3 = 0x1f;
LAB_0011395f:
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001139c0 __pfx_nv_unmap_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113a2e) */
/* WARNING: Removing unreachable block (ram,0x00113a33) */

long __pfx_nv_unmap_dma_map_scatterlist(long param_1)

{
  long in_RAX;
  long lVar1;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return in_RAX;
  }
  lVar1 = *(long *)(param_1 + 0x28);
  if (*(int *)(lVar1 + 4) != 0) {
    if (*(char *)(lVar1 + 0x18) == '\0') {
      dma_unmap_sg_attrs(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(lVar1 + 8),
                         *(undefined4 *)(lVar1 + 0x14),0,0);
      lVar1 = *(long *)(param_1 + 0x28);
    }
    lVar1 = lVar1 + 0x20;
    if (1 < *(uint *)(param_1 + 0x20)) {
      return lVar1;
    }
  }
  return lVar1;
}


// ===== 001139d0 nv_unmap_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113a2e) */
/* WARNING: Removing unreachable block (ram,0x00113a33) */

long nv_unmap_dma_map_scatterlist(long param_1)

{
  long in_RAX;
  long lVar1;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return in_RAX;
  }
  lVar1 = *(long *)(param_1 + 0x28);
  if (*(int *)(lVar1 + 4) != 0) {
    if (*(char *)(lVar1 + 0x18) == '\0') {
      dma_unmap_sg_attrs(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(lVar1 + 8),
                         *(undefined4 *)(lVar1 + 0x14),0,0);
      lVar1 = *(long *)(param_1 + 0x28);
    }
    lVar1 = lVar1 + 0x20;
    if (1 < *(uint *)(param_1 + 0x20)) {
      return lVar1;
    }
  }
  return lVar1;
}


// ===== 00113a40 __pfx_nv_map_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113ad1) */
/* WARNING: Removing unreachable block (ram,0x00113ac6) */
/* WARNING: Removing unreachable block (ram,0x00113ad6) */

ulong __pfx_nv_map_dma_map_scatterlist(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  uVar2 = (ulong)*(uint *)(param_1 + 0x20);
  if (*(uint *)(param_1 + 0x20) != 0) {
    uVar4 = 0;
    lVar3 = *(long *)(param_1 + 0x28);
    while( true ) {
      iVar1 = *(int *)(lVar3 + 0x14);
      if (*(char *)(lVar3 + 0x18) != '\0') break;
      iVar1 = dma_map_sg_attrs(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(lVar3 + 8),iVar1,0,0)
      ;
      *(int *)(lVar3 + 4) = iVar1;
      if (iVar1 == 0) goto LAB_00113ab5;
      uVar4 = uVar4 + 1;
      uVar2 = (ulong)*(uint *)(param_1 + 0x20);
      lVar3 = uVar4 * 0x20 + *(long *)(param_1 + 0x28);
      if (uVar2 <= uVar4) {
        return 0;
      }
    }
    *(int *)(lVar3 + 4) = iVar1;
    if (iVar1 == 0) {
LAB_00113ab5:
      nv_unmap_dma_map_scatterlist(param_1);
      return 0x59;
    }
  }
  return uVar2;
}


// ===== 00113a50 nv_map_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113ad1) */
/* WARNING: Removing unreachable block (ram,0x00113ac6) */
/* WARNING: Removing unreachable block (ram,0x00113ad6) */

ulong nv_map_dma_map_scatterlist(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  uVar2 = (ulong)*(uint *)(param_1 + 0x20);
  if (*(uint *)(param_1 + 0x20) != 0) {
    uVar4 = 0;
    lVar3 = *(long *)(param_1 + 0x28);
    while( true ) {
      iVar1 = *(int *)(lVar3 + 0x14);
      if (*(char *)(lVar3 + 0x18) != '\0') break;
      iVar1 = dma_map_sg_attrs(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(lVar3 + 8),iVar1,0,0)
      ;
      *(int *)(lVar3 + 4) = iVar1;
      if (iVar1 == 0) goto LAB_00113ab5;
      uVar4 = uVar4 + 1;
      uVar2 = (ulong)*(uint *)(param_1 + 0x20);
      lVar3 = uVar4 * 0x20 + *(long *)(param_1 + 0x28);
      if (uVar2 <= uVar4) {
        return 0;
      }
    }
    *(int *)(lVar3 + 4) = iVar1;
    if (iVar1 == 0) {
LAB_00113ab5:
      nv_unmap_dma_map_scatterlist(param_1);
      return 0x59;
    }
  }
  return uVar2;
}


// ===== 00113ae0 __pfx_nv_destroy_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_destroy_dma_map_scatterlist(long param_1)

{
  int *piVar1;
  ulong uVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar2 = 0;
    piVar3 = piVar1;
    do {
      if ((*piVar3 == 0) || ((char)piVar3[6] != '\0')) break;
      uVar2 = uVar2 + 1;
      sg_free_table(piVar3 + 2);
      piVar1 = *(int **)(param_1 + 0x28);
      piVar3 = piVar1 + uVar2 * 8;
    } while (uVar2 < *(uint *)(param_1 + 0x20));
  }
  os_free_mem(piVar1);
  return;
}


// ===== 00113af0 nv_destroy_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_destroy_dma_map_scatterlist(long param_1)

{
  int *piVar1;
  ulong uVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar2 = 0;
    piVar3 = piVar1;
    do {
      if ((*piVar3 == 0) || ((char)piVar3[6] != '\0')) break;
      uVar2 = uVar2 + 1;
      sg_free_table(piVar3 + 2);
      piVar1 = *(int **)(param_1 + 0x28);
      piVar3 = piVar1 + uVar2 * 8;
    } while (uVar2 < *(uint *)(param_1 + 0x20));
  }
  os_free_mem(piVar1);
  return;
}


// ===== 00113b60 __pfx_nv_create_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113c56) */
/* WARNING: Removing unreachable block (ram,0x00113bfa) */
/* WARNING: Removing unreachable block (ram,0x00113c75) */

int __pfx_nv_create_dma_map_scatterlist(long *param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  undefined4 *puVar10;
  long lVar11;
  
  lVar11 = param_1[1];
  uVar7 = lVar11 + 0xffffe;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar7;
  lVar6 = SUB168(ZEXT816(0x100001000011) * auVar2,8);
  uVar7 = lVar6 + (uVar7 - lVar6 >> 1);
  uVar8 = uVar7 >> 0x13;
  if (uVar7 >> 0x33 != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  if ((param_1[3] != 0) && (uVar8 != 1)) {
    return -0x16;
  }
  *(int *)(param_1 + 4) = (int)uVar8;
  iVar4 = os_alloc_mem(param_1 + 5,(uVar8 & 0xffffffff) << 5);
  if (iVar4 == 0) {
    os_mem_set(param_1[5],0,(int)param_1[4] << 5);
    puVar10 = (undefined4 *)param_1[5];
    if (param_1[3] != 0) {
      *puVar10 = (int)param_1[1];
      lVar11 = param_1[5];
      uVar1 = ((undefined8 *)param_1[3])[1];
      *(undefined8 *)(lVar11 + 8) = *(undefined8 *)param_1[3];
      *(undefined8 *)(lVar11 + 0x10) = uVar1;
      *(undefined1 *)(param_1[5] + 0x18) = 1;
      return 0;
    }
    lVar11 = lVar11 * 0x1000;
    if ((int)param_1[4] == 0) {
      lVar6 = 0;
    }
    else {
      lVar6 = 0;
      uVar7 = 0;
      do {
        uVar8 = lVar11 - lVar6;
        if (0xfffff000 < uVar8) {
          uVar8 = 0xfffff000;
        }
        *puVar10 = (int)(uVar8 >> 0xc);
        iVar5 = sg_alloc_table_from_pages_segment
                          (puVar10 + 2,*param_1 + (ulong)(uint)((int)uVar7 * 0xfffff) * 8,
                           uVar8 >> 0xc & 0xffffffff,0,uVar8,0xffffffff);
        if (iVar5 != 0) {
          *puVar10 = 0;
          if (lVar11 == lVar6) {
            nv_destroy_dma_map_scatterlist(param_1);
            return 0x59;
          }
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        uVar9 = (int)uVar7 + 1;
        uVar7 = (ulong)uVar9;
        lVar6 = lVar6 + uVar8;
        puVar10 = (undefined4 *)(uVar7 * 0x20 + param_1[5]);
      } while (uVar9 < *(uint *)(param_1 + 4));
    }
    if (lVar11 != lVar6) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
  }
  return iVar4;
}


// ===== 00113b70 nv_create_dma_map_scatterlist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113c56) */
/* WARNING: Removing unreachable block (ram,0x00113bfa) */
/* WARNING: Removing unreachable block (ram,0x00113c75) */

int nv_create_dma_map_scatterlist(long *param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  undefined4 *puVar10;
  long lVar11;
  
  lVar11 = param_1[1];
  uVar7 = lVar11 + 0xffffe;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar7;
  lVar6 = SUB168(ZEXT816(0x100001000011) * auVar2,8);
  uVar7 = lVar6 + (uVar7 - lVar6 >> 1);
  uVar8 = uVar7 >> 0x13;
  if (uVar7 >> 0x33 != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  if ((param_1[3] != 0) && (uVar8 != 1)) {
    return -0x16;
  }
  *(int *)(param_1 + 4) = (int)uVar8;
  iVar4 = os_alloc_mem(param_1 + 5,(uVar8 & 0xffffffff) << 5);
  if (iVar4 == 0) {
    os_mem_set(param_1[5],0,(int)param_1[4] << 5);
    puVar10 = (undefined4 *)param_1[5];
    if (param_1[3] != 0) {
      *puVar10 = (int)param_1[1];
      lVar11 = param_1[5];
      uVar1 = ((undefined8 *)param_1[3])[1];
      *(undefined8 *)(lVar11 + 8) = *(undefined8 *)param_1[3];
      *(undefined8 *)(lVar11 + 0x10) = uVar1;
      *(undefined1 *)(param_1[5] + 0x18) = 1;
      return 0;
    }
    lVar11 = lVar11 * 0x1000;
    if ((int)param_1[4] == 0) {
      lVar6 = 0;
    }
    else {
      lVar6 = 0;
      uVar7 = 0;
      do {
        uVar8 = lVar11 - lVar6;
        if (0xfffff000 < uVar8) {
          uVar8 = 0xfffff000;
        }
        *puVar10 = (int)(uVar8 >> 0xc);
        iVar5 = sg_alloc_table_from_pages_segment
                          (puVar10 + 2,*param_1 + (ulong)(uint)((int)uVar7 * 0xfffff) * 8,
                           uVar8 >> 0xc & 0xffffffff,0,uVar8,0xffffffff);
        if (iVar5 != 0) {
          *puVar10 = 0;
          if (lVar11 == lVar6) {
            nv_destroy_dma_map_scatterlist(param_1);
            return 0x59;
          }
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        uVar9 = (int)uVar7 + 1;
        uVar7 = (ulong)uVar9;
        lVar6 = lVar6 + uVar8;
        puVar10 = (undefined4 *)(uVar7 * 0x20 + param_1[5]);
      } while (uVar9 < *(uint *)(param_1 + 4));
    }
    if (lVar11 != lVar6) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
  }
  return iVar4;
}


// ===== 00113d70 __pfx_nv_dma_map_scatterlist.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113e01) */

int __pfx_nv_dma_map_scatterlist_constprop_0(ulong *param_1,long param_2,long param_3)

{
  ulong *puVar1;
  long lVar2;
  uint uVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  uint *puVar9;
  uint *puVar10;
  ulong uVar11;
  byte *pbVar12;
  uint uVar13;
  
  iVar5 = nv_create_dma_map_scatterlist(param_2);
  if (iVar5 == 0) {
    iVar5 = nv_map_dma_map_scatterlist(param_2);
    if (iVar5 == 0) {
      if (*(int *)(param_2 + 0x20) != 0) {
        puVar9 = *(uint **)(param_2 + 0x28);
        uVar11 = 0;
        lVar6 = 0;
        puVar10 = puVar9;
        do {
          if (puVar10[1] != 0) {
            pbVar12 = *(byte **)(puVar10 + 2);
            uVar13 = 0;
            do {
              uVar3 = *(uint *)(pbVar12 + 0x18);
              if ((ulong)uVar3 != 0) {
                lVar7 = *(long *)(pbVar12 + 0x10);
                lVar2 = lVar6 + 1;
                uVar8 = 0;
                do {
                  if (*puVar10 <= uVar8) break;
                  *(long *)(param_3 + lVar6 * 8) = lVar7;
                  lVar6 = lVar6 + 1;
                  uVar8 = uVar8 + 1;
                  lVar7 = lVar7 + 0x1000;
                } while (lVar6 != lVar2 + ((ulong)uVar3 - 1 >> 0xc));
              }
              uVar13 = uVar13 + 1;
              if ((*pbVar12 & 2) == 0) {
                puVar1 = (ulong *)(pbVar12 + 0x20);
                pbVar12 = pbVar12 + 0x20;
                if ((*puVar1 & 1) != 0) {
                  pbVar12 = (byte *)(*puVar1 & 0xfffffffffffffffc);
                }
              }
              else {
                pbVar12 = (byte *)0x0;
              }
            } while (uVar13 < puVar10[1]);
            puVar9 = *(uint **)(param_2 + 0x28);
          }
          uVar13 = (int)uVar11 + 1;
          uVar11 = (ulong)uVar13;
          puVar10 = puVar9 + uVar11 * 8;
        } while (uVar13 < *(uint *)(param_2 + 0x20));
      }
      iVar5 = 0;
      if (*(long *)(param_2 + 8) != 0) {
        lVar6 = 0;
        do {
          uVar11 = *(ulong *)(param_3 + lVar6 * 8);
          if (((uVar11 < *param_1) || (param_1[1] < uVar11 + 0xfff)) ||
             (0xfffffffffffff000 < uVar11)) {
            lVar6 = 0;
            if (param_1 != (ulong *)0x0) {
              plVar4 = (long *)param_1[2];
              lVar6 = 0;
              if ((plVar4 != (long *)0x0) && (lVar6 = plVar4[10], lVar6 == 0)) {
                lVar6 = *plVar4;
              }
            }
            nv_printf(4,
                      "NVRM: %s: DMA address not in addressable range of device (0x%llx, 0x%llx-0x%llx)\n"
                      ,lVar6);
            nv_unmap_dma_map_scatterlist(param_2);
            nv_destroy_dma_map_scatterlist(param_2);
            return 0x1e;
          }
          lVar6 = lVar6 + 1;
        } while (lVar6 != *(long *)(param_2 + 8));
      }
    }
    else {
      lVar6 = 0;
      if (param_1 != (ulong *)0x0) {
        plVar4 = (long *)param_1[2];
        lVar6 = 0;
        if ((plVar4 != (long *)0x0) && (lVar6 = plVar4[10], lVar6 == 0)) {
          lVar6 = *plVar4;
        }
      }
      nv_printf(4,"NVRM: %s: Failed to create a DMA mapping!\n",lVar6);
      nv_destroy_dma_map_scatterlist(param_2);
      iVar5 = 0x59;
    }
  }
  else {
    lVar6 = 0;
    if (param_1 != (ulong *)0x0) {
      plVar4 = (long *)param_1[2];
      lVar6 = 0;
      if ((plVar4 != (long *)0x0) && (lVar6 = plVar4[10], lVar6 == 0)) {
        lVar6 = *plVar4;
      }
    }
    nv_printf(4,"NVRM: %s: Failed to allocate DMA mapping scatterlist!\n",lVar6);
  }
  return iVar5;
}


// ===== 00113d80 nv_dma_map_scatterlist.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00113e01) */

int nv_dma_map_scatterlist_constprop_0(ulong *param_1,long param_2,long param_3)

{
  ulong *puVar1;
  long lVar2;
  uint uVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  uint *puVar9;
  uint *puVar10;
  ulong uVar11;
  byte *pbVar12;
  uint uVar13;
  
  iVar5 = nv_create_dma_map_scatterlist(param_2);
  if (iVar5 == 0) {
    iVar5 = nv_map_dma_map_scatterlist(param_2);
    if (iVar5 == 0) {
      if (*(int *)(param_2 + 0x20) != 0) {
        puVar9 = *(uint **)(param_2 + 0x28);
        uVar11 = 0;
        lVar6 = 0;
        puVar10 = puVar9;
        do {
          if (puVar10[1] != 0) {
            pbVar12 = *(byte **)(puVar10 + 2);
            uVar13 = 0;
            do {
              uVar3 = *(uint *)(pbVar12 + 0x18);
              if ((ulong)uVar3 != 0) {
                lVar7 = *(long *)(pbVar12 + 0x10);
                lVar2 = lVar6 + 1;
                uVar8 = 0;
                do {
                  if (*puVar10 <= uVar8) break;
                  *(long *)(param_3 + lVar6 * 8) = lVar7;
                  lVar6 = lVar6 + 1;
                  uVar8 = uVar8 + 1;
                  lVar7 = lVar7 + 0x1000;
                } while (lVar6 != lVar2 + ((ulong)uVar3 - 1 >> 0xc));
              }
              uVar13 = uVar13 + 1;
              if ((*pbVar12 & 2) == 0) {
                puVar1 = (ulong *)(pbVar12 + 0x20);
                pbVar12 = pbVar12 + 0x20;
                if ((*puVar1 & 1) != 0) {
                  pbVar12 = (byte *)(*puVar1 & 0xfffffffffffffffc);
                }
              }
              else {
                pbVar12 = (byte *)0x0;
              }
            } while (uVar13 < puVar10[1]);
            puVar9 = *(uint **)(param_2 + 0x28);
          }
          uVar13 = (int)uVar11 + 1;
          uVar11 = (ulong)uVar13;
          puVar10 = puVar9 + uVar11 * 8;
        } while (uVar13 < *(uint *)(param_2 + 0x20));
      }
      iVar5 = 0;
      if (*(long *)(param_2 + 8) != 0) {
        lVar6 = 0;
        do {
          uVar11 = *(ulong *)(param_3 + lVar6 * 8);
          if (((uVar11 < *param_1) || (param_1[1] < uVar11 + 0xfff)) ||
             (0xfffffffffffff000 < uVar11)) {
            lVar6 = 0;
            if (param_1 != (ulong *)0x0) {
              plVar4 = (long *)param_1[2];
              lVar6 = 0;
              if ((plVar4 != (long *)0x0) && (lVar6 = plVar4[10], lVar6 == 0)) {
                lVar6 = *plVar4;
              }
            }
            nv_printf(4,
                      "NVRM: %s: DMA address not in addressable range of device (0x%llx, 0x%llx-0x%llx)\n"
                      ,lVar6);
            nv_unmap_dma_map_scatterlist(param_2);
            nv_destroy_dma_map_scatterlist(param_2);
            return 0x1e;
          }
          lVar6 = lVar6 + 1;
        } while (lVar6 != *(long *)(param_2 + 8));
      }
    }
    else {
      lVar6 = 0;
      if (param_1 != (ulong *)0x0) {
        plVar4 = (long *)param_1[2];
        lVar6 = 0;
        if ((plVar4 != (long *)0x0) && (lVar6 = plVar4[10], lVar6 == 0)) {
          lVar6 = *plVar4;
        }
      }
      nv_printf(4,"NVRM: %s: Failed to create a DMA mapping!\n",lVar6);
      nv_destroy_dma_map_scatterlist(param_2);
      iVar5 = 0x59;
    }
  }
  else {
    lVar6 = 0;
    if (param_1 != (ulong *)0x0) {
      plVar4 = (long *)param_1[2];
      lVar6 = 0;
      if ((plVar4 != (long *)0x0) && (lVar6 = plVar4[10], lVar6 == 0)) {
        lVar6 = *plVar4;
      }
    }
    nv_printf(4,"NVRM: %s: Failed to allocate DMA mapping scatterlist!\n",lVar6);
  }
  return iVar5;
}


// ===== 00113fe0 __pfx_nv_dma_map_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114138) */

int __pfx_nv_dma_map_sgt
              (long param_1,ulong param_2,undefined8 param_3,undefined4 param_4,undefined8 *param_5)

{
  long *plVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  undefined8 *puStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puStack_48 = (undefined8 *)0x0;
  if (param_5 == (undefined8 *)0x0) {
    iVar3 = 0x56;
  }
  else {
    uVar4 = _find_first_bit(__release_region,0x400);
    if (uVar4 < 0x400) {
      if (0x400 < uVar4) {
        uVar4 = 0x400;
      }
      uVar7 = 0;
      do {
        uVar7 = uVar7 + *(long *)(*(long *)(&node_data + (uVar4 & 0xffffffff) * 8) + 0x2a470);
        uVar5 = _find_next_bit(__release_region,0x400,(int)uVar4 + 1);
        uVar4 = 0x400;
        if (uVar5 < 0x401) {
          uVar4 = uVar5;
        }
      } while (uVar5 < 0x400);
    }
    else {
      uVar7 = 0;
    }
    if (uVar7 < param_2) {
      lVar6 = 0;
      if (param_1 != 0) {
        plVar1 = *(long **)(param_1 + 0x10);
        lVar6 = 0;
        if ((plVar1 != (long *)0x0) && (lVar6 = plVar1[10], lVar6 == 0)) {
          lVar6 = *plVar1;
        }
      }
      iVar3 = 0x3f;
      nv_printf(4,"NVRM: %s: DMA mapping request too large!\n",lVar6);
    }
    else {
      iVar3 = os_alloc_mem(&puStack_48,0x38);
      if (iVar3 == 0) {
        puStack_48[6] = *(undefined8 *)(param_1 + 0x10);
        *puStack_48 = 0;
        uVar2 = *param_5;
        puStack_48[1] = param_2;
        puStack_48[3] = uVar2;
        *(undefined1 *)(puStack_48 + 2) = 0;
        *(undefined4 *)((long)puStack_48 + 0x14) = param_4;
        *(undefined4 *)(puStack_48 + 4) = 0;
        iVar3 = nv_dma_map_scatterlist_constprop_0(param_1,puStack_48,param_3);
        if (iVar3 == 0) {
          *param_5 = puStack_48;
        }
        else {
          os_free_mem();
        }
      }
      else {
        lVar6 = 0;
        if (param_1 != 0) {
          plVar1 = *(long **)(param_1 + 0x10);
          lVar6 = 0;
          if ((plVar1 != (long *)0x0) && (lVar6 = plVar1[10], lVar6 == 0)) {
            lVar6 = *plVar1;
          }
        }
        nv_printf(4,"NVRM: %s: Failed to allocate nv_dma_map_t!\n",lVar6);
      }
    }
  }
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 00113ff0 nv_dma_map_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114138) */

int nv_dma_map_sgt(long param_1,ulong param_2,undefined8 param_3,undefined4 param_4,
                  undefined8 *param_5)

{
  long *plVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  undefined8 *local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_48 = (undefined8 *)0x0;
  if (param_5 == (undefined8 *)0x0) {
    iVar3 = 0x56;
  }
  else {
    uVar4 = _find_first_bit(__release_region,0x400);
    if (uVar4 < 0x400) {
      if (0x400 < uVar4) {
        uVar4 = 0x400;
      }
      uVar7 = 0;
      do {
        uVar7 = uVar7 + *(long *)(*(long *)(&node_data + (uVar4 & 0xffffffff) * 8) + 0x2a470);
        uVar5 = _find_next_bit(__release_region,0x400,(int)uVar4 + 1);
        uVar4 = 0x400;
        if (uVar5 < 0x401) {
          uVar4 = uVar5;
        }
      } while (uVar5 < 0x400);
    }
    else {
      uVar7 = 0;
    }
    if (uVar7 < param_2) {
      lVar6 = 0;
      if (param_1 != 0) {
        plVar1 = *(long **)(param_1 + 0x10);
        lVar6 = 0;
        if ((plVar1 != (long *)0x0) && (lVar6 = plVar1[10], lVar6 == 0)) {
          lVar6 = *plVar1;
        }
      }
      iVar3 = 0x3f;
      nv_printf(4,"NVRM: %s: DMA mapping request too large!\n",lVar6);
    }
    else {
      iVar3 = os_alloc_mem(&local_48,0x38);
      if (iVar3 == 0) {
        local_48[6] = *(undefined8 *)(param_1 + 0x10);
        *local_48 = 0;
        uVar2 = *param_5;
        local_48[1] = param_2;
        local_48[3] = uVar2;
        *(undefined1 *)(local_48 + 2) = 0;
        *(undefined4 *)((long)local_48 + 0x14) = param_4;
        *(undefined4 *)(local_48 + 4) = 0;
        iVar3 = nv_dma_map_scatterlist_constprop_0(param_1,local_48,param_3);
        if (iVar3 == 0) {
          *param_5 = local_48;
        }
        else {
          os_free_mem();
        }
      }
      else {
        lVar6 = 0;
        if (param_1 != 0) {
          plVar1 = *(long **)(param_1 + 0x10);
          lVar6 = 0;
          if ((plVar1 != (long *)0x0) && (lVar6 = plVar1[10], lVar6 == 0)) {
            lVar6 = *plVar1;
          }
        }
        nv_printf(4,"NVRM: %s: Failed to allocate nv_dma_map_t!\n",lVar6);
      }
    }
  }
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 00114210 __pfx_nv_dma_map_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114314) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nv_dma_map_alloc(ulong *param_1,ulong param_2,ulong *param_3,char param_4,long *param_5)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long in_GS_OFFSET;
  long *plStack_50;
  long *plStack_48;
  long lStack_40;
  
  lVar2 = *param_5;
  lVar9 = param_2 * 8;
  if (param_4 != '\0') {
    lVar9 = 8;
  }
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  plStack_50 = (long *)0x0;
  if (lVar2 == 0) {
    iVar6 = os_alloc_mem(&plStack_50,lVar9);
    if (iVar6 != 0) {
LAB_001142b2:
      lVar9 = 0;
      if (param_1 != (ulong *)0x0) {
        plVar3 = (long *)param_1[2];
        lVar9 = 0;
        if ((plVar3 != (long *)0x0) && (lVar9 = plVar3[10], lVar9 == 0)) {
          lVar9 = *plVar3;
        }
      }
      nv_printf(4,"NVRM: %s: Failed to allocate page array for DMA mapping!\n",lVar9);
      goto LAB_001142e2;
    }
    os_mem_set(plStack_50,0,lVar9);
    lVar9 = *plStack_50;
    iVar1 = 0;
  }
  else {
    if (*(long *)(lVar2 + 0x60) != 0) {
      *param_5 = *(long *)(lVar2 + 0x60);
      iVar6 = nv_dma_map_sgt(param_1,param_2,param_3,*(undefined4 *)(lVar2 + 0x1c),param_5);
      if (iVar6 != 0) {
        *param_5 = lVar2;
      }
      goto LAB_001142e2;
    }
    iVar6 = os_alloc_mem(&plStack_50,lVar9);
    if (iVar6 != 0) goto LAB_001142b2;
    os_mem_set(plStack_50,0,lVar9);
    if (*(uint *)(lVar2 + 0x20) != param_2) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    if ((*(byte *)(lVar2 + 0x18) & 0x10) == 0) {
      if (((char)*(byte *)(lVar2 + 0x18) < '\0') && (param_4 != '\0')) {
        *plStack_50 = (*param_3 >> 0xc) * 0x40 + _vmemmap_base;
      }
    }
    else {
      *plStack_50 = **(long **)(lVar2 + 0x40);
      if ((param_4 == '\0') && (1 < param_2)) {
        uVar7 = 1;
        do {
          plStack_50[uVar7] = *(long *)(*(long *)(lVar2 + 0x40) + uVar7 * 8);
          uVar7 = uVar7 + 1;
        } while (param_2 != uVar7);
      }
    }
    iVar1 = *(int *)(lVar2 + 0x1c);
    lVar9 = *plStack_50;
  }
  if (((lVar9 == 0) && (*plStack_50 = (*param_3 >> 0xc) * 0x40 + _vmemmap_base, param_4 == '\0')) &&
     (1 < param_2)) {
    lVar9 = 8;
    do {
      *(ulong *)((long)plStack_50 + lVar9) =
           (*(ulong *)((long)param_3 + lVar9) >> 0xc) * 0x40 + _vmemmap_base;
      lVar9 = lVar9 + 8;
    } while (lVar9 != param_2 * 8);
  }
  *param_5 = (long)plStack_50;
  plStack_48 = (long *)0x0;
  if (param_5 == (long *)0x0) {
    iVar6 = 0x56;
  }
  else {
    uVar7 = _find_first_bit(__release_region,0x400);
    if (uVar7 < 0x400) {
      if (0x400 < uVar7) {
        uVar7 = 0x400;
      }
      uVar10 = 0;
      do {
        uVar10 = uVar10 + *(long *)(*(long *)(&node_data + (uVar7 & 0xffffffff) * 8) + 0x2a470);
        uVar8 = _find_next_bit(__release_region,0x400,(int)uVar7 + 1);
        uVar7 = 0x400;
        if (uVar8 < 0x401) {
          uVar7 = uVar8;
        }
      } while (uVar8 < 0x400);
    }
    else {
      uVar10 = 0;
    }
    if (uVar10 < param_2) {
      lVar9 = 0;
      if (param_1 != (ulong *)0x0) {
        plVar3 = (long *)param_1[2];
        lVar9 = 0;
        if ((plVar3 != (long *)0x0) && (lVar9 = plVar3[10], lVar9 == 0)) {
          lVar9 = *plVar3;
        }
      }
      iVar6 = 0x3f;
      nv_printf(4,"NVRM: %s: DMA mapping request too large!\n",lVar9);
    }
    else {
      iVar6 = os_alloc_mem(&plStack_48,0x38);
      plVar3 = plStack_48;
      if (iVar6 == 0) {
        plStack_48[6] = param_1[2];
        *plStack_48 = *param_5;
        plStack_48[3] = 0;
        plStack_48[1] = param_2;
        *(char *)(plStack_48 + 2) = param_4;
        *(int *)((long)plStack_48 + 0x14) = iVar1;
        if ((param_4 == '\0') && (1 < param_2)) {
          *(undefined4 *)(plStack_48 + 4) = 0;
          iVar6 = nv_dma_map_scatterlist_constprop_0(param_1,plStack_48,param_3);
          if (iVar6 == 0) {
LAB_0011450d:
            iVar6 = 0;
            *param_5 = (long)plStack_48;
            goto LAB_001142e2;
          }
        }
        else {
          *(undefined1 *)(plStack_48 + 2) = 1;
          uVar7 = dma_map_page_attrs(plStack_48[6],*(undefined8 *)*plStack_48,0,param_2 << 0xc,0,
                                     (ulong)(iVar1 == 1) << 5);
          *param_3 = uVar7;
          if (uVar7 == 0xffffffffffffffff) {
            iVar6 = 0x59;
          }
          else {
            plVar3[4] = uVar7;
            uVar10 = plVar3[1] * 0x1000 - 1;
            uVar8 = uVar10 + uVar7;
            if (((*param_1 <= uVar7) && (uVar8 <= param_1[1])) && (!CARRY8(uVar10,uVar7)))
            goto LAB_0011450d;
            lVar9 = 0;
            if (param_1 != (ulong *)0x0) {
              plVar4 = (long *)param_1[2];
              lVar9 = 0;
              if ((plVar4 != (long *)0x0) && (lVar9 = plVar4[10], lVar9 == 0)) {
                lVar9 = *plVar4;
              }
            }
            iVar6 = 0x1e;
            nv_printf(4,
                      "NVRM: %s: DMA address not in addressable range of device (0x%llx-0x%llx, 0x%llx-0x%llx)\n"
                      ,lVar9,uVar7,uVar8,*param_1,param_1[1]);
            dma_unmap_page_attrs
                      (plVar3[6],plVar3[4],plVar3[1] << 0xc,0,
                       (ulong)(*(int *)((long)plVar3 + 0x14) == 1) << 5);
          }
        }
        os_free_mem(plStack_48);
      }
      else {
        lVar9 = 0;
        if (param_1 != (ulong *)0x0) {
          plVar3 = (long *)param_1[2];
          lVar9 = 0;
          if ((plVar3 != (long *)0x0) && (lVar9 = plVar3[10], lVar9 == 0)) {
            lVar9 = *plVar3;
          }
        }
        nv_printf(4,"NVRM: %s: Failed to allocate nv_dma_map_t!\n",lVar9);
      }
    }
  }
  *param_5 = lVar2;
  os_free_mem(plStack_50);
LAB_001142e2:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00114220 nv_dma_map_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114314) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nv_dma_map_alloc(ulong *param_1,ulong param_2,ulong *param_3,char param_4,long *param_5)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long in_GS_OFFSET;
  long *local_50;
  long *local_48;
  long local_40;
  
  lVar2 = *param_5;
  lVar9 = param_2 * 8;
  if (param_4 != '\0') {
    lVar9 = 8;
  }
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_50 = (long *)0x0;
  if (lVar2 == 0) {
    iVar6 = os_alloc_mem(&local_50,lVar9);
    if (iVar6 != 0) {
LAB_001142b2:
      lVar9 = 0;
      if (param_1 != (ulong *)0x0) {
        plVar3 = (long *)param_1[2];
        lVar9 = 0;
        if ((plVar3 != (long *)0x0) && (lVar9 = plVar3[10], lVar9 == 0)) {
          lVar9 = *plVar3;
        }
      }
      nv_printf(4,"NVRM: %s: Failed to allocate page array for DMA mapping!\n",lVar9);
      goto LAB_001142e2;
    }
    os_mem_set(local_50,0,lVar9);
    lVar9 = *local_50;
    iVar1 = 0;
  }
  else {
    if (*(long *)(lVar2 + 0x60) != 0) {
      *param_5 = *(long *)(lVar2 + 0x60);
      iVar6 = nv_dma_map_sgt(param_1,param_2,param_3,*(undefined4 *)(lVar2 + 0x1c),param_5);
      if (iVar6 != 0) {
        *param_5 = lVar2;
      }
      goto LAB_001142e2;
    }
    iVar6 = os_alloc_mem(&local_50,lVar9);
    if (iVar6 != 0) goto LAB_001142b2;
    os_mem_set(local_50,0,lVar9);
    if (*(uint *)(lVar2 + 0x20) != param_2) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    if ((*(byte *)(lVar2 + 0x18) & 0x10) == 0) {
      if (((char)*(byte *)(lVar2 + 0x18) < '\0') && (param_4 != '\0')) {
        *local_50 = (*param_3 >> 0xc) * 0x40 + _vmemmap_base;
      }
    }
    else {
      *local_50 = **(long **)(lVar2 + 0x40);
      if ((param_4 == '\0') && (1 < param_2)) {
        uVar7 = 1;
        do {
          local_50[uVar7] = *(long *)(*(long *)(lVar2 + 0x40) + uVar7 * 8);
          uVar7 = uVar7 + 1;
        } while (param_2 != uVar7);
      }
    }
    iVar1 = *(int *)(lVar2 + 0x1c);
    lVar9 = *local_50;
  }
  if (((lVar9 == 0) && (*local_50 = (*param_3 >> 0xc) * 0x40 + _vmemmap_base, param_4 == '\0')) &&
     (1 < param_2)) {
    lVar9 = 8;
    do {
      *(ulong *)((long)local_50 + lVar9) =
           (*(ulong *)((long)param_3 + lVar9) >> 0xc) * 0x40 + _vmemmap_base;
      lVar9 = lVar9 + 8;
    } while (lVar9 != param_2 * 8);
  }
  *param_5 = (long)local_50;
  local_48 = (long *)0x0;
  if (param_5 == (long *)0x0) {
    iVar6 = 0x56;
  }
  else {
    uVar7 = _find_first_bit(__release_region,0x400);
    if (uVar7 < 0x400) {
      if (0x400 < uVar7) {
        uVar7 = 0x400;
      }
      uVar10 = 0;
      do {
        uVar10 = uVar10 + *(long *)(*(long *)(&node_data + (uVar7 & 0xffffffff) * 8) + 0x2a470);
        uVar8 = _find_next_bit(__release_region,0x400,(int)uVar7 + 1);
        uVar7 = 0x400;
        if (uVar8 < 0x401) {
          uVar7 = uVar8;
        }
      } while (uVar8 < 0x400);
    }
    else {
      uVar10 = 0;
    }
    if (uVar10 < param_2) {
      lVar9 = 0;
      if (param_1 != (ulong *)0x0) {
        plVar3 = (long *)param_1[2];
        lVar9 = 0;
        if ((plVar3 != (long *)0x0) && (lVar9 = plVar3[10], lVar9 == 0)) {
          lVar9 = *plVar3;
        }
      }
      iVar6 = 0x3f;
      nv_printf(4,"NVRM: %s: DMA mapping request too large!\n",lVar9);
    }
    else {
      iVar6 = os_alloc_mem(&local_48,0x38);
      plVar3 = local_48;
      if (iVar6 == 0) {
        local_48[6] = param_1[2];
        *local_48 = *param_5;
        local_48[3] = 0;
        local_48[1] = param_2;
        *(char *)(local_48 + 2) = param_4;
        *(int *)((long)local_48 + 0x14) = iVar1;
        if ((param_4 == '\0') && (1 < param_2)) {
          *(undefined4 *)(local_48 + 4) = 0;
          iVar6 = nv_dma_map_scatterlist_constprop_0(param_1,local_48,param_3);
          if (iVar6 == 0) {
LAB_0011450d:
            iVar6 = 0;
            *param_5 = (long)local_48;
            goto LAB_001142e2;
          }
        }
        else {
          *(undefined1 *)(local_48 + 2) = 1;
          uVar7 = dma_map_page_attrs(local_48[6],*(undefined8 *)*local_48,0,param_2 << 0xc,0,
                                     (ulong)(iVar1 == 1) << 5);
          *param_3 = uVar7;
          if (uVar7 == 0xffffffffffffffff) {
            iVar6 = 0x59;
          }
          else {
            plVar3[4] = uVar7;
            uVar10 = plVar3[1] * 0x1000 - 1;
            uVar8 = uVar10 + uVar7;
            if (((*param_1 <= uVar7) && (uVar8 <= param_1[1])) && (!CARRY8(uVar10,uVar7)))
            goto LAB_0011450d;
            lVar9 = 0;
            if (param_1 != (ulong *)0x0) {
              plVar4 = (long *)param_1[2];
              lVar9 = 0;
              if ((plVar4 != (long *)0x0) && (lVar9 = plVar4[10], lVar9 == 0)) {
                lVar9 = *plVar4;
              }
            }
            iVar6 = 0x1e;
            nv_printf(4,
                      "NVRM: %s: DMA address not in addressable range of device (0x%llx-0x%llx, 0x%llx-0x%llx)\n"
                      ,lVar9,uVar7,uVar8,*param_1,param_1[1]);
            dma_unmap_page_attrs
                      (plVar3[6],plVar3[4],plVar3[1] << 0xc,0,
                       (ulong)(*(int *)((long)plVar3 + 0x14) == 1) << 5);
          }
        }
        os_free_mem(local_48);
      }
      else {
        lVar9 = 0;
        if (param_1 != (ulong *)0x0) {
          plVar3 = (long *)param_1[2];
          lVar9 = 0;
          if ((plVar3 != (long *)0x0) && (lVar9 = plVar3[10], lVar9 == 0)) {
            lVar9 = *plVar3;
          }
        }
        nv_printf(4,"NVRM: %s: Failed to allocate nv_dma_map_t!\n",lVar9);
      }
    }
  }
  *param_5 = lVar2;
  os_free_mem(local_50);
LAB_001142e2:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001147e0 __pfx_nv_dma_unmap_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114857) */
/* WARNING: Removing unreachable block (ram,0x0011493f) */

undefined8 __pfx_nv_dma_unmap_alloc(long param_1,ulong param_2,undefined8 param_3,long *param_4)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  
  if (param_4 == (long *)0x0) {
    return 0x56;
  }
  plVar1 = (long *)*param_4;
  if (plVar1[3] == 0) {
    uVar2 = _find_first_bit(__release_region,0x400);
    if (uVar2 < 0x400) {
      if (0x400 < uVar2) {
        uVar2 = 0x400;
      }
      uVar6 = 0;
      do {
        uVar6 = uVar6 + *(long *)(*(long *)(&node_data + (uVar2 & 0xffffffff) * 8) + 0x2a470);
        uVar3 = _find_next_bit(__release_region,0x400,(int)uVar2 + 1);
        uVar2 = 0x400;
        if (uVar3 < 0x401) {
          uVar2 = uVar3;
        }
      } while (uVar3 < 0x400);
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 < param_2) {
      lVar5 = 0;
      if (param_1 != 0) {
        plVar1 = *(long **)(param_1 + 0x10);
        lVar5 = 0;
        if ((plVar1 != (long *)0x0) && (lVar5 = plVar1[10], lVar5 == 0)) {
          lVar5 = *plVar1;
        }
      }
      nv_printf(4,"NVRM: %s: DMA unmapping request too large!\n",lVar5);
    }
    else {
      if (param_2 == plVar1[1]) {
        *param_4 = *plVar1;
        if (*(char *)(plVar1 + 2) == '\0') {
          nv_unmap_dma_map_scatterlist(plVar1);
          nv_destroy_dma_map_scatterlist(plVar1);
        }
        else {
          dma_unmap_page_attrs
                    (plVar1[6],plVar1[4],plVar1[1] << 0xc,0,
                     (ulong)(*(int *)((long)plVar1 + 0x14) == 1) << 5);
        }
        os_free_mem(plVar1);
        os_free_mem(*param_4);
        goto LAB_00114843;
      }
      lVar5 = 0;
      if (param_1 != 0) {
        plVar1 = *(long **)(param_1 + 0x10);
        lVar5 = 0;
        if ((plVar1 != (long *)0x0) && (lVar5 = plVar1[10], lVar5 == 0)) {
          lVar5 = *plVar1;
        }
      }
      nv_printf(3,"NVRM: %s: Requested to DMA unmap %llu pages, but there are %llu in the mapping\n"
                ,lVar5,param_2);
    }
    uVar4 = 0x3f;
  }
  else {
    *param_4 = 0;
    nv_unmap_dma_map_scatterlist(plVar1);
    nv_destroy_dma_map_scatterlist(plVar1);
    os_free_mem(plVar1);
LAB_00114843:
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 001147f0 nv_dma_unmap_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114857) */
/* WARNING: Removing unreachable block (ram,0x0011493f) */

undefined8 nv_dma_unmap_alloc(long param_1,ulong param_2,undefined8 param_3,long *param_4)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  
  if (param_4 == (long *)0x0) {
    return 0x56;
  }
  plVar1 = (long *)*param_4;
  if (plVar1[3] == 0) {
    uVar2 = _find_first_bit(__release_region,0x400);
    if (uVar2 < 0x400) {
      if (0x400 < uVar2) {
        uVar2 = 0x400;
      }
      uVar6 = 0;
      do {
        uVar6 = uVar6 + *(long *)(*(long *)(&node_data + (uVar2 & 0xffffffff) * 8) + 0x2a470);
        uVar3 = _find_next_bit(__release_region,0x400,(int)uVar2 + 1);
        uVar2 = 0x400;
        if (uVar3 < 0x401) {
          uVar2 = uVar3;
        }
      } while (uVar3 < 0x400);
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 < param_2) {
      lVar5 = 0;
      if (param_1 != 0) {
        plVar1 = *(long **)(param_1 + 0x10);
        lVar5 = 0;
        if ((plVar1 != (long *)0x0) && (lVar5 = plVar1[10], lVar5 == 0)) {
          lVar5 = *plVar1;
        }
      }
      nv_printf(4,"NVRM: %s: DMA unmapping request too large!\n",lVar5);
    }
    else {
      if (param_2 == plVar1[1]) {
        *param_4 = *plVar1;
        if (*(char *)(plVar1 + 2) == '\0') {
          nv_unmap_dma_map_scatterlist(plVar1);
          nv_destroy_dma_map_scatterlist(plVar1);
        }
        else {
          dma_unmap_page_attrs
                    (plVar1[6],plVar1[4],plVar1[1] << 0xc,0,
                     (ulong)(*(int *)((long)plVar1 + 0x14) == 1) << 5);
        }
        os_free_mem(plVar1);
        os_free_mem(*param_4);
        goto LAB_00114843;
      }
      lVar5 = 0;
      if (param_1 != 0) {
        plVar1 = *(long **)(param_1 + 0x10);
        lVar5 = 0;
        if ((plVar1 != (long *)0x0) && (lVar5 = plVar1[10], lVar5 == 0)) {
          lVar5 = *plVar1;
        }
      }
      nv_printf(3,"NVRM: %s: Requested to DMA unmap %llu pages, but there are %llu in the mapping\n"
                ,lVar5,param_2);
    }
    uVar4 = 0x3f;
  }
  else {
    *param_4 = 0;
    nv_unmap_dma_map_scatterlist(plVar1);
    nv_destroy_dma_map_scatterlist(plVar1);
    os_free_mem(plVar1);
LAB_00114843:
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 001149e0 __pfx_nv_dma_unmap_peer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114a1d) */
/* WARNING: Removing unreachable block (ram,0x00114a4f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_dma_unmap_peer(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 600);
  if (lVar1 == 0) {
    if (nv_dma_remap_peer_mmio == 0) {
      return;
    }
    if (_dma_ops == 0) {
      return;
    }
    lVar1 = *(long *)(_dma_ops + 0x30);
  }
  else {
    if (nv_dma_remap_peer_mmio == 0) {
      return;
    }
    lVar1 = *(long *)(lVar1 + 0x30);
  }
  if (lVar1 == 0) {
    return;
  }
  dma_unmap_resource(*(long *)(param_1 + 0x10),param_3,param_2 << 0xc,0,0);
  return;
}


// ===== 001149f0 nv_dma_unmap_peer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114a1d) */
/* WARNING: Removing unreachable block (ram,0x00114a4f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_dma_unmap_peer(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 600);
  if (lVar1 == 0) {
    if (nv_dma_remap_peer_mmio == 0) {
      return;
    }
    if (_dma_ops == 0) {
      return;
    }
    lVar1 = *(long *)(_dma_ops + 0x30);
  }
  else {
    if (nv_dma_remap_peer_mmio == 0) {
      return;
    }
    lVar1 = *(long *)(lVar1 + 0x30);
  }
  if (lVar1 == 0) {
    return;
  }
  dma_unmap_resource(*(long *)(param_1 + 0x10),param_3,param_2 << 0xc,0,0);
  return;
}


// ===== 00114a60 __pfx_nv_dma_map_mmio =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114af1) */
/* WARNING: Removing unreachable block (ram,0x00114b0e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_dma_map_mmio(long *param_1,long param_2,long *param_3)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_3 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar3 = *(long *)(param_1[2] + 600);
  if (lVar3 == 0) {
    if ((nv_dma_remap_peer_mmio == 0) || (lVar3 = _dma_ops, _dma_ops == 0)) goto LAB_00114b06;
  }
  else if (nv_dma_remap_peer_mmio == 0) goto LAB_00114b06;
  if (*(long *)(lVar3 + 0x30) != 0) {
    lVar3 = *param_3;
    lVar4 = dma_map_resource(param_1[2],lVar3,param_2 * 0x1000,0,0);
    *param_3 = lVar4;
    if (lVar4 == -1) {
      lVar4 = 0;
      if (param_1 != (long *)0x0) {
        plVar1 = (long *)param_1[2];
        lVar4 = 0;
        if ((plVar1 != (long *)0x0) && (lVar4 = plVar1[10], lVar4 == 0)) {
          lVar4 = *plVar1;
        }
      }
      nv_printf(4,"NVRM: %s: Failed to DMA map MMIO range [0x%llx-0x%llx]\n",lVar4,lVar3,
                lVar3 + -1 + param_2 * 0x1000);
      uVar5 = 0x59;
    }
    else {
      uVar5 = 0;
    }
    return uVar5;
  }
LAB_00114b06:
  *param_3 = *param_3 + *param_1;
  return 0;
}


// ===== 00114a70 nv_dma_map_mmio =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114af1) */
/* WARNING: Removing unreachable block (ram,0x00114b0e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_dma_map_mmio(long *param_1,long param_2,long *param_3)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_3 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar3 = *(long *)(param_1[2] + 600);
  if (lVar3 == 0) {
    if ((nv_dma_remap_peer_mmio == 0) || (lVar3 = _dma_ops, _dma_ops == 0)) goto LAB_00114b06;
  }
  else if (nv_dma_remap_peer_mmio == 0) goto LAB_00114b06;
  if (*(long *)(lVar3 + 0x30) != 0) {
    lVar3 = *param_3;
    lVar4 = dma_map_resource(param_1[2],lVar3,param_2 * 0x1000,0,0);
    *param_3 = lVar4;
    if (lVar4 == -1) {
      lVar4 = 0;
      if (param_1 != (long *)0x0) {
        plVar1 = (long *)param_1[2];
        lVar4 = 0;
        if ((plVar1 != (long *)0x0) && (lVar4 = plVar1[10], lVar4 == 0)) {
          lVar4 = *plVar1;
        }
      }
      nv_printf(4,"NVRM: %s: Failed to DMA map MMIO range [0x%llx-0x%llx]\n",lVar4,lVar3,
                lVar3 + -1 + param_2 * 0x1000);
      uVar5 = 0x59;
    }
    else {
      uVar5 = 0;
    }
    return uVar5;
  }
LAB_00114b06:
  *param_3 = *param_3 + *param_1;
  return 0;
}


// ===== 00114b60 __pfx_nv_dma_map_peer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114d3b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_dma_map_peer(long param_1,long param_2,byte param_3,long param_4,ulong *param_5)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  long in_GS_OFFSET;
  bool bVar9;
  long alStack_30 [3];
  
  alStack_30[2] = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  plVar1 = *(long **)(param_2 + 0x10);
  if (plVar1 == (long *)&DAT_000000d0) {
    lVar8 = 0;
    if ((param_2 != 0) && (lVar8 = _DAT_00000120, _DAT_00000120 == 0)) {
      lVar8 = _DAT_000000d0;
    }
    nv_printf(4,"NVRM: %s: Not a PCI device",lVar8);
LAB_00114d68:
    uVar5 = 0x3f;
  }
  else {
    if (2 < param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    uVar7 = 0;
    if (param_3 != 0) {
      bVar9 = (*(byte *)(plVar1 + 0x67) & 4) != 0;
      uVar6 = bVar9 + 1;
      if (param_3 == 2) {
        uVar6 = bVar9 + 3;
        if ((*(byte *)(plVar1 + (ulong)(bVar9 + 1) * 8 + 0x67) & 4) == 0) {
          uVar6 = bVar9 + 2;
        }
      }
      uVar7 = (ulong)uVar6;
    }
    uVar2 = plVar1[uVar7 * 8 + 100];
    if (uVar2 == 0) {
      if ((plVar1 == (long *)0x0) || (param_2 == 0)) {
        lVar8 = 0;
      }
      else {
        lVar8 = plVar1[10];
        if (lVar8 == 0) {
          lVar8 = *plVar1;
        }
      }
      nv_printf(4,"NVRM: %s: Resource %u not valid",lVar8,uVar7);
      goto LAB_00114d68;
    }
    uVar3 = *param_5;
    if ((uVar3 < uVar2) || ((ulong)plVar1[uVar7 * 8 + 0x65] < param_4 * 0x1000 + uVar3)) {
      if ((param_2 == 0) || (plVar1 == (long *)0x0)) {
        lVar8 = 0;
      }
      else {
        lVar8 = plVar1[10];
        if (lVar8 == 0) {
          lVar8 = *plVar1;
        }
      }
      nv_printf(4,
                "NVRM: %s: Mapping requested (start = 0x%llx, page_count = 0x%llx) outside of resource bounds (start = 0x%llx, end = 0x%llx)\n"
                ,lVar8,uVar3,param_4,uVar2,plVar1[uVar7 * 8 + 0x65]);
      goto LAB_00114d68;
    }
    lVar8 = *(long *)(*(long *)(param_1 + 0x10) + 600);
    if ((((lVar8 != 0) || (lVar8 = _dma_ops, _dma_ops != 0)) && (nv_dma_remap_peer_mmio != 0)) &&
       (*(long *)(lVar8 + 0x30) != 0)) {
      if (alStack_30[2] == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        uVar5 = nv_dma_map_mmio(param_1,param_4,param_5);
        return uVar5;
      }
      goto LAB_00114de9;
    }
    alStack_30[0] = 0;
    alStack_30[1] = 0;
    pcibios_resource_to_bus(plVar1[-0x18],alStack_30,plVar1 + uVar7 * 8 + 100);
    uVar5 = 0;
    *param_5 = (uVar3 + alStack_30[0]) - uVar2;
  }
  if (alStack_30[2] == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
LAB_00114de9:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00114b70 nv_dma_map_peer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114d3b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_dma_map_peer(long param_1,long param_2,byte param_3,long param_4,ulong *param_5)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  long in_GS_OFFSET;
  bool bVar9;
  long local_30 [3];
  
  local_30[2] = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  plVar1 = *(long **)(param_2 + 0x10);
  if (plVar1 == (long *)&DAT_000000d0) {
    lVar8 = 0;
    if ((param_2 != 0) && (lVar8 = _DAT_00000120, _DAT_00000120 == 0)) {
      lVar8 = _DAT_000000d0;
    }
    nv_printf(4,"NVRM: %s: Not a PCI device",lVar8);
LAB_00114d68:
    uVar5 = 0x3f;
  }
  else {
    if (2 < param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    uVar7 = 0;
    if (param_3 != 0) {
      bVar9 = (*(byte *)(plVar1 + 0x67) & 4) != 0;
      uVar6 = bVar9 + 1;
      if (param_3 == 2) {
        uVar6 = bVar9 + 3;
        if ((*(byte *)(plVar1 + (ulong)(bVar9 + 1) * 8 + 0x67) & 4) == 0) {
          uVar6 = bVar9 + 2;
        }
      }
      uVar7 = (ulong)uVar6;
    }
    uVar2 = plVar1[uVar7 * 8 + 100];
    if (uVar2 == 0) {
      if ((plVar1 == (long *)0x0) || (param_2 == 0)) {
        lVar8 = 0;
      }
      else {
        lVar8 = plVar1[10];
        if (lVar8 == 0) {
          lVar8 = *plVar1;
        }
      }
      nv_printf(4,"NVRM: %s: Resource %u not valid",lVar8,uVar7);
      goto LAB_00114d68;
    }
    uVar3 = *param_5;
    if ((uVar3 < uVar2) || ((ulong)plVar1[uVar7 * 8 + 0x65] < param_4 * 0x1000 + uVar3)) {
      if ((param_2 == 0) || (plVar1 == (long *)0x0)) {
        lVar8 = 0;
      }
      else {
        lVar8 = plVar1[10];
        if (lVar8 == 0) {
          lVar8 = *plVar1;
        }
      }
      nv_printf(4,
                "NVRM: %s: Mapping requested (start = 0x%llx, page_count = 0x%llx) outside of resource bounds (start = 0x%llx, end = 0x%llx)\n"
                ,lVar8,uVar3,param_4,uVar2,plVar1[uVar7 * 8 + 0x65]);
      goto LAB_00114d68;
    }
    lVar8 = *(long *)(*(long *)(param_1 + 0x10) + 600);
    if ((((lVar8 != 0) || (lVar8 = _dma_ops, _dma_ops != 0)) && (nv_dma_remap_peer_mmio != 0)) &&
       (*(long *)(lVar8 + 0x30) != 0)) {
      if (local_30[2] == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        uVar5 = nv_dma_map_mmio(param_1,param_4,param_5);
        return uVar5;
      }
      goto LAB_00114de9;
    }
    local_30[0] = 0;
    local_30[1] = 0;
    pcibios_resource_to_bus(plVar1[-0x18],local_30,plVar1 + uVar7 * 8 + 100);
    uVar5 = 0;
    *param_5 = (uVar3 + local_30[0]) - uVar2;
  }
  if (local_30[2] == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
LAB_00114de9:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00114df0 __pfx_nv_dma_unmap_mmio =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114e51) */
/* WARNING: Removing unreachable block (ram,0x00114e56) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_dma_unmap_mmio(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 600);
  if (lVar1 == 0) {
    if (_dma_ops == 0) {
      return;
    }
    lVar1 = _dma_ops;
    if (nv_dma_remap_peer_mmio == 0) {
      return;
    }
  }
  else if (nv_dma_remap_peer_mmio == 0) {
    return;
  }
  if (*(long *)(lVar1 + 0x30) == 0) {
    return;
  }
  dma_unmap_resource(*(long *)(param_1 + 0x10),param_3,param_2 << 0xc,0,0);
  return;
}


// ===== 00114e00 nv_dma_unmap_mmio =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114e51) */
/* WARNING: Removing unreachable block (ram,0x00114e56) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_dma_unmap_mmio(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x10) + 600);
  if (lVar1 == 0) {
    if (_dma_ops == 0) {
      return;
    }
    lVar1 = _dma_ops;
    if (nv_dma_remap_peer_mmio == 0) {
      return;
    }
  }
  else if (nv_dma_remap_peer_mmio == 0) {
    return;
  }
  if (*(long *)(lVar1 + 0x30) == 0) {
    return;
  }
  dma_unmap_resource(*(long *)(param_1 + 0x10),param_3,param_2 << 0xc,0,0);
  return;
}


// ===== 00114e60 __pfx_nv_dma_cache_invalidate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114e79) */

void __pfx_nv_dma_cache_invalidate(void)

{
  return;
}


// ===== 00114e70 nv_dma_cache_invalidate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114e79) */

void nv_dma_cache_invalidate(void)

{
  return;
}


// ===== 00114e80 __pfx_nv_dma_get_dev_pagemap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_dma_get_dev_pagemap(ulong param_1)

{
  get_dev_pagemap(param_1 >> 0xc);
  return;
}


// ===== 00114e90 nv_dma_get_dev_pagemap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_dma_get_dev_pagemap(ulong param_1)

{
  get_dev_pagemap(param_1 >> 0xc);
  return;
}


// ===== 00114eb0 __pfx_nv_dma_put_dev_pagemap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114ef4) */

void __pfx_nv_dma_put_dev_pagemap(long param_1)

{
  long *plVar1;
  long in_GS_OFFSET;
  
  if (param_1 != 0) {
    __rcu_read_lock();
    if ((*(ulong *)(param_1 + 0x30) & 3) == 0) {
      plVar1 = (long *)(in_GS_OFFSET + *(ulong *)(param_1 + 0x30));
      *plVar1 = *plVar1 + -1;
    }
    else {
      plVar1 = *(long **)(param_1 + 0x38);
      LOCK();
      *plVar1 = *plVar1 + -1;
      UNLOCK();
      if (*plVar1 == 0) {
        (**(code **)(*(long *)(param_1 + 0x38) + 8))(param_1 + 0x30);
      }
    }
    __rcu_read_unlock();
    return;
  }
  return;
}


// ===== 00114ec0 nv_dma_put_dev_pagemap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114ef4) */

void nv_dma_put_dev_pagemap(long param_1)

{
  long *plVar1;
  long in_GS_OFFSET;
  
  if (param_1 != 0) {
    __rcu_read_lock();
    if ((*(ulong *)(param_1 + 0x30) & 3) == 0) {
      plVar1 = (long *)(in_GS_OFFSET + *(ulong *)(param_1 + 0x30));
      *plVar1 = *plVar1 + -1;
    }
    else {
      plVar1 = *(long **)(param_1 + 0x38);
      LOCK();
      *plVar1 = *plVar1 + -1;
      UNLOCK();
      if (*plVar1 == 0) {
        (**(code **)(*(long *)(param_1 + 0x38) + 8))(param_1 + 0x30);
      }
    }
    __rcu_read_unlock();
    return;
  }
  return;
}


// ===== 00114f20 __pfx_nv_dma_import_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114fec) */
/* WARNING: Removing unreachable block (ram,0x00114fad) */
/* WARNING: Removing unreachable block (ram,0x0011502e) */

undefined8 __pfx_nv_dma_import_sgt(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  long *plVar2;
  char cVar3;
  long lVar4;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      if (param_1 == 0) goto LAB_0011500c;
    }
    else if (param_3 != (uint *)0x0) {
      cVar3 = try_module_get(**(undefined8 **)(*(long *)(*(long *)(param_3 + 2) + 0x38) + 0xc0));
      if (cVar3 == '\0') {
        plVar2 = *(long **)(param_1 + 0x10);
        lVar4 = 0;
        if ((plVar2 != (long *)0x0) && (lVar4 = plVar2[10], lVar4 == 0)) {
          lVar4 = *plVar2;
        }
        nv_printf(4,"NVRM: %s: Couldn\'t reference the GEM object\'s owner!\n",lVar4);
        return 0x26;
      }
      LOCK();
      uVar1 = *param_3;
      *param_3 = *param_3 + 1;
      UNLOCK();
      if (uVar1 == 0) {
        refcount_warn_saturate(param_3,2);
      }
      else if ((int)(uVar1 + 1 | uVar1) < 0) {
        refcount_warn_saturate(param_3,1);
      }
      return 0;
    }
    plVar2 = *(long **)(param_1 + 0x10);
    param_1 = 0;
    if ((plVar2 != (long *)0x0) && (param_1 = plVar2[10], param_1 == 0)) {
      param_1 = *plVar2;
    }
  }
LAB_0011500c:
  nv_printf(4,"NVRM: %s: Import arguments are NULL!\n",param_1);
  return 0x1f;
}


// ===== 00114f30 nv_dma_import_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00114fec) */
/* WARNING: Removing unreachable block (ram,0x00114fad) */
/* WARNING: Removing unreachable block (ram,0x0011502e) */

undefined8 nv_dma_import_sgt(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  long *plVar2;
  char cVar3;
  long lVar4;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      if (param_1 == 0) goto LAB_0011500c;
    }
    else if (param_3 != (uint *)0x0) {
      cVar3 = try_module_get(**(undefined8 **)(*(long *)(*(long *)(param_3 + 2) + 0x38) + 0xc0));
      if (cVar3 == '\0') {
        plVar2 = *(long **)(param_1 + 0x10);
        lVar4 = 0;
        if ((plVar2 != (long *)0x0) && (lVar4 = plVar2[10], lVar4 == 0)) {
          lVar4 = *plVar2;
        }
        nv_printf(4,"NVRM: %s: Couldn\'t reference the GEM object\'s owner!\n",lVar4);
        return 0x26;
      }
      LOCK();
      uVar1 = *param_3;
      *param_3 = *param_3 + 1;
      UNLOCK();
      if (uVar1 == 0) {
        refcount_warn_saturate(param_3,2);
      }
      else if ((int)(uVar1 + 1 | uVar1) < 0) {
        refcount_warn_saturate(param_3,1);
      }
      return 0;
    }
    plVar2 = *(long **)(param_1 + 0x10);
    param_1 = 0;
    if ((plVar2 != (long *)0x0) && (param_1 = plVar2[10], param_1 == 0)) {
      param_1 = *plVar2;
    }
  }
LAB_0011500c:
  nv_printf(4,"NVRM: %s: Import arguments are NULL!\n",param_1);
  return 0x1f;
}


// ===== 00115060 __pfx_nv_dma_release_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001150e0) */

void __pfx_nv_dma_release_sgt(long param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_1 != 0) {
    LOCK();
    iVar1 = *param_2;
    *param_2 = *param_2 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      drm_gem_object_free(param_2);
    }
    else if (iVar1 < 1) {
      refcount_warn_saturate(param_2,3);
    }
    module_put(**(undefined8 **)(*(long *)(*(long *)(param_2 + 2) + 0x38) + 0xc0));
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 00115070 nv_dma_release_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001150e0) */

void nv_dma_release_sgt(long param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_1 != 0) {
    LOCK();
    iVar1 = *param_2;
    *param_2 = *param_2 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      drm_gem_object_free(param_2);
    }
    else if (iVar1 < 1) {
      refcount_warn_saturate(param_2,3);
    }
    module_put(**(undefined8 **)(*(long *)(*(long *)(param_2 + 2) + 0x38) + 0xc0));
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 001150f0 __pfx_nv_i2c_algo_smbus_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115213) */

uint __pfx_nv_i2c_algo_smbus_xfer
               (long param_1,ushort param_2,undefined8 param_3,char param_4,undefined1 param_5,
               int param_6)

{
  undefined8 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  long in_GS_OFFSET;
  undefined2 *unaff_retaddr;
  undefined1 uVar7;
  
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  lVar2 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    puVar6 = (undefined4 *)0x0;
    if (param_6 == 3) goto LAB_001152d2;
    if (param_6 < 4) {
      if (param_6 == 1) {
LAB_00115308:
        if (param_4 == '\x01') {
          param_5 = 0;
          cVar3 = '\x01';
          uVar7 = 1;
        }
        else {
          param_5 = 0;
          cVar3 = '\x02';
          uVar7 = 1;
        }
      }
      else if (param_6 == 2) {
LAB_00115294:
        uVar7 = 1;
        cVar3 = (param_4 != '\x01') + '\x03';
      }
      else {
        if (param_6 != 0) goto LAB_00115278;
LAB_00115177:
        uVar7 = 0;
        param_5 = 0;
        cVar3 = (param_4 == '\x01') + '\x05';
      }
    }
    else if (param_6 == 5) {
LAB_001152a9:
      uVar7 = 0x22;
      cVar3 = (param_4 != '\x01') + '\a';
    }
    else {
      if (param_6 != 8) {
LAB_00115278:
        uVar5 = 0xffffffea;
        goto LAB_001151f2;
      }
LAB_001151a0:
      uVar7 = *(undefined1 *)unaff_retaddr;
      cVar3 = (param_4 != '\x01') + '\t';
    }
LAB_001151c7:
    iVar4 = rm_i2c_transfer(puVar6,uVar1,param_1,cVar3,param_2 & 0x7f,param_5,uVar7);
  }
  else {
    puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar6 == (undefined4 *)0x0) {
      uVar5 = 0xfffffff4;
      goto LAB_001151f2;
    }
    *puVar6 = 0x2ff0;
    *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
    if (param_6 != 3) {
      if (param_6 < 4) {
        if (param_6 == 1) goto LAB_00115308;
        if (param_6 == 2) goto LAB_00115294;
        if (param_6 == 0) goto LAB_00115177;
      }
      else {
        if (param_6 == 5) goto LAB_001152a9;
        if (param_6 == 8) goto LAB_001151a0;
      }
      cVar3 = rm_is_altstack_in_use();
      if (cVar3 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
      }
      goto LAB_00115278;
    }
LAB_001152d2:
    if (param_4 != '\x01') {
      cVar3 = '\x04';
      *(undefined2 *)((long)unaff_retaddr + 1) = *unaff_retaddr;
      uVar7 = 2;
      goto LAB_001151c7;
    }
    iVar4 = rm_i2c_transfer(puVar6,uVar1,param_1,3,param_2 & 0x7f,param_5,2,
                            (undefined1 *)((long)unaff_retaddr + 1));
    *unaff_retaddr = *(undefined2 *)((long)unaff_retaddr + 1);
  }
  if ((puVar6 != (undefined4 *)0x0) && (cVar3 = rm_is_altstack_in_use(), cVar3 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar6);
  }
  uVar5 = -(uint)(iVar4 != 0) & 0xfffffffb;
LAB_001151f2:
  if (lVar2 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00115100 nv_i2c_algo_smbus_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115213) */

uint nv_i2c_algo_smbus_xfer
               (long param_1,ushort param_2,undefined8 param_3,char param_4,undefined1 param_5,
               int param_6)

{
  undefined8 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  long in_GS_OFFSET;
  undefined2 *unaff_retaddr;
  undefined1 uVar7;
  
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  lVar2 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    puVar6 = (undefined4 *)0x0;
    if (param_6 == 3) goto LAB_001152d2;
    if (param_6 < 4) {
      if (param_6 == 1) {
LAB_00115308:
        if (param_4 == '\x01') {
          param_5 = 0;
          cVar3 = '\x01';
          uVar7 = 1;
        }
        else {
          param_5 = 0;
          cVar3 = '\x02';
          uVar7 = 1;
        }
      }
      else if (param_6 == 2) {
LAB_00115294:
        uVar7 = 1;
        cVar3 = (param_4 != '\x01') + '\x03';
      }
      else {
        if (param_6 != 0) goto LAB_00115278;
LAB_00115177:
        uVar7 = 0;
        param_5 = 0;
        cVar3 = (param_4 == '\x01') + '\x05';
      }
    }
    else if (param_6 == 5) {
LAB_001152a9:
      uVar7 = 0x22;
      cVar3 = (param_4 != '\x01') + '\a';
    }
    else {
      if (param_6 != 8) {
LAB_00115278:
        uVar5 = 0xffffffea;
        goto LAB_001151f2;
      }
LAB_001151a0:
      uVar7 = *(undefined1 *)unaff_retaddr;
      cVar3 = (param_4 != '\x01') + '\t';
    }
LAB_001151c7:
    iVar4 = rm_i2c_transfer(puVar6,uVar1,param_1,cVar3,param_2 & 0x7f,param_5,uVar7);
  }
  else {
    puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar6 == (undefined4 *)0x0) {
      uVar5 = 0xfffffff4;
      goto LAB_001151f2;
    }
    *puVar6 = 0x2ff0;
    *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
    if (param_6 != 3) {
      if (param_6 < 4) {
        if (param_6 == 1) goto LAB_00115308;
        if (param_6 == 2) goto LAB_00115294;
        if (param_6 == 0) goto LAB_00115177;
      }
      else {
        if (param_6 == 5) goto LAB_001152a9;
        if (param_6 == 8) goto LAB_001151a0;
      }
      cVar3 = rm_is_altstack_in_use();
      if (cVar3 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
      }
      goto LAB_00115278;
    }
LAB_001152d2:
    if (param_4 != '\x01') {
      cVar3 = '\x04';
      *(undefined2 *)((long)unaff_retaddr + 1) = *unaff_retaddr;
      uVar7 = 2;
      goto LAB_001151c7;
    }
    iVar4 = rm_i2c_transfer(puVar6,uVar1,param_1,3,param_2 & 0x7f,param_5,2,
                            (undefined1 *)((long)unaff_retaddr + 1));
    *unaff_retaddr = *(undefined2 *)((long)unaff_retaddr + 1);
  }
  if ((puVar6 != (undefined4 *)0x0) && (cVar3 = rm_is_altstack_in_use(), cVar3 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar6);
  }
  uVar5 = -(uint)(iVar4 != 0) & 0xfffffffb;
LAB_001151f2:
  if (lVar2 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 001153b0 __pfx_nv_i2c_algo_functionality =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115404) */
/* WARNING: Removing unreachable block (ram,0x0011547a) */

int __pfx_nv_i2c_algo_functionality(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    cVar2 = rm_i2c_is_smbus_capable(0,uVar1,param_1);
    iVar4 = (-(uint)(cVar2 == '\0') & 0xf0810000) + 0xf7f0001;
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    cVar2 = rm_i2c_is_smbus_capable(puVar3,uVar1,param_1);
    iVar4 = (-(uint)(cVar2 == '\0') & 0xf0810000) + 0xf7f0001;
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
    }
  }
  return iVar4;
}


// ===== 001153c0 nv_i2c_algo_functionality =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115404) */
/* WARNING: Removing unreachable block (ram,0x0011547a) */

int nv_i2c_algo_functionality(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    cVar2 = rm_i2c_is_smbus_capable(0,uVar1,param_1);
    iVar4 = (-(uint)(cVar2 == '\0') & 0xf0810000) + 0xf7f0001;
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    cVar2 = rm_i2c_is_smbus_capable(puVar3,uVar1,param_1);
    iVar4 = (-(uint)(cVar2 == '\0') & 0xf0810000) + 0xf7f0001;
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
    }
  }
  return iVar4;
}


// ===== 00115480 __pfx_nv_i2c_algo_master_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001155aa) */

uint __pfx_nv_i2c_algo_master_xfer(long param_1,ushort *param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  cVar5 = rm_is_altstack_in_use();
  if (cVar5 == '\0') {
    puVar7 = (undefined4 *)0x0;
    if (param_3 == 0) {
      return 0;
    }
  }
  else {
    puVar7 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar7 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar7 = 0x2ff0;
    *(undefined4 **)(puVar7 + 2) = puVar7 + 0xc00;
    if (param_3 == 0) {
      cVar5 = rm_is_altstack_in_use();
      if (cVar5 == '\0') {
        return 0;
      }
      kmem_cache_free(nvidia_stack_t_cache,puVar7);
      return 0;
    }
  }
  uVar8 = 0;
  do {
    puVar1 = param_2 + 1;
    if ((*puVar1 & 0xfdfe) != 0) {
      nv_printf(4,"NVRM: Unsupported I2C flags used. (flags:0x%08x)\n");
      if ((puVar7 != (undefined4 *)0x0) && (cVar5 = rm_is_altstack_in_use(), cVar5 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar7);
      }
      return 0xffffffea;
    }
    uVar3 = *param_2;
    puVar2 = param_2 + 2;
    uVar8 = uVar8 + 1;
    param_2 = param_2 + 8;
    iVar6 = rm_i2c_transfer(puVar7,uVar4,param_1,2 - (*puVar1 & 1),uVar3 & 0x7f,0,*puVar2);
  } while ((uVar8 < param_3) && (iVar6 == 0));
  if ((puVar7 != (undefined4 *)0x0) && (cVar5 = rm_is_altstack_in_use(), cVar5 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar7);
  }
  uVar8 = 0xfffffffb;
  if (iVar6 == 0) {
    uVar8 = param_3;
  }
  return uVar8;
}


// ===== 00115490 nv_i2c_algo_master_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001155aa) */

uint nv_i2c_algo_master_xfer(long param_1,ushort *param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  cVar5 = rm_is_altstack_in_use();
  if (cVar5 == '\0') {
    puVar7 = (undefined4 *)0x0;
    if (param_3 == 0) {
      return 0;
    }
  }
  else {
    puVar7 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar7 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar7 = 0x2ff0;
    *(undefined4 **)(puVar7 + 2) = puVar7 + 0xc00;
    if (param_3 == 0) {
      cVar5 = rm_is_altstack_in_use();
      if (cVar5 == '\0') {
        return 0;
      }
      kmem_cache_free(nvidia_stack_t_cache,puVar7);
      return 0;
    }
  }
  uVar8 = 0;
  do {
    puVar1 = param_2 + 1;
    if ((*puVar1 & 0xfdfe) != 0) {
      nv_printf(4,"NVRM: Unsupported I2C flags used. (flags:0x%08x)\n");
      if ((puVar7 != (undefined4 *)0x0) && (cVar5 = rm_is_altstack_in_use(), cVar5 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar7);
      }
      return 0xffffffea;
    }
    uVar3 = *param_2;
    puVar2 = param_2 + 2;
    uVar8 = uVar8 + 1;
    param_2 = param_2 + 8;
    iVar6 = rm_i2c_transfer(puVar7,uVar4,param_1,2 - (*puVar1 & 1),uVar3 & 0x7f,0,*puVar2);
  } while ((uVar8 < param_3) && (iVar6 == 0));
  if ((puVar7 != (undefined4 *)0x0) && (cVar5 = rm_is_altstack_in_use(), cVar5 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar7);
  }
  uVar8 = 0xfffffffb;
  if (iVar6 == 0) {
    uVar8 = param_3;
  }
  return uVar8;
}


// ===== 00115620 __pfx_nv_i2c_add_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115707) */

long __pfx_nv_i2c_add_adapter(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  long in_GS_OFFSET;
  long lStack_30;
  long lStack_28;
  
  lVar2 = *(long *)(param_1 + 8);
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_30 = 0;
  iVar1 = os_alloc_mem(&lStack_30,0x448);
  if (iVar1 == 0) {
    os_mem_copy(lStack_30,nv_i2c_adapter_prototype,0x448);
    *(undefined8 *)(lStack_30 + 0xb0) = *(undefined8 *)(lVar2 + 0x3b0);
    lVar2 = *(long *)(lVar2 + 0x3b8);
    if (lVar2 == 0) {
      snprintf((char *)(lStack_30 + 0x394),0x30,"NVIDIA SOC i2c adapter %u\n",(ulong)param_2);
    }
    else {
      snprintf((char *)(lStack_30 + 0x394),0x30,"NVIDIA i2c adapter %u at %x:%02x.%u\n",
               (ulong)param_2,(ulong)*(byte *)(param_1 + 0x18),(ulong)*(byte *)(param_1 + 0x19),
               (ulong)(*(uint *)(lVar2 + 0x38) & 7));
    }
    *(long *)(lStack_30 + 0x18) = param_1;
    iVar1 = i2c_add_adapter();
    lVar2 = lStack_30;
    if (iVar1 == 0) goto LAB_001156f0;
    os_free_mem(lStack_30);
  }
  lVar2 = 0;
LAB_001156f0:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00115630 nv_i2c_add_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115707) */

long nv_i2c_add_adapter(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  long in_GS_OFFSET;
  long local_30;
  long local_28;
  
  lVar2 = *(long *)(param_1 + 8);
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_30 = 0;
  iVar1 = os_alloc_mem(&local_30,0x448);
  if (iVar1 == 0) {
    os_mem_copy(local_30,nv_i2c_adapter_prototype,0x448);
    *(undefined8 *)(local_30 + 0xb0) = *(undefined8 *)(lVar2 + 0x3b0);
    lVar2 = *(long *)(lVar2 + 0x3b8);
    if (lVar2 == 0) {
      snprintf((char *)(local_30 + 0x394),0x30,"NVIDIA SOC i2c adapter %u\n",(ulong)param_2);
    }
    else {
      snprintf((char *)(local_30 + 0x394),0x30,"NVIDIA i2c adapter %u at %x:%02x.%u\n",
               (ulong)param_2,(ulong)*(byte *)(param_1 + 0x18),(ulong)*(byte *)(param_1 + 0x19),
               (ulong)(*(uint *)(lVar2 + 0x38) & 7));
    }
    *(long *)(local_30 + 0x18) = param_1;
    iVar1 = i2c_add_adapter();
    lVar2 = local_30;
    if (iVar1 == 0) goto LAB_001156f0;
    os_free_mem(local_30);
  }
  lVar2 = 0;
LAB_001156f0:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00115730 __pfx_nv_i2c_del_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011576b) */

void __pfx_nv_i2c_del_adapter(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    i2c_del_adapter(param_2);
    os_free_mem(param_2);
    return;
  }
  return;
}


// ===== 00115740 nv_i2c_del_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011576b) */

void nv_i2c_del_adapter(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    i2c_del_adapter(param_2);
    os_free_mem(param_2);
    return;
  }
  return;
}


// ===== 00115770 __pfx_nv_i2c_transfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011578b) */

undefined8 __pfx_nv_i2c_transfer(void)

{
  return 0;
}


// ===== 00115780 nv_i2c_transfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011578b) */

undefined8 nv_i2c_transfer(void)

{
  return 0;
}


// ===== 00115790 __pfx_nv_i2c_unregister_clients =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001157a9) */

void __pfx_nv_i2c_unregister_clients(void)

{
  return;
}


// ===== 001157a0 nv_i2c_unregister_clients =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001157a9) */

void nv_i2c_unregister_clients(void)

{
  return;
}


// ===== 001157b0 __pfx_nv_i2c_bus_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001157ce) */

undefined8 __pfx_nv_i2c_bus_status(void)

{
  return 0xffff;
}


// ===== 001157c0 nv_i2c_bus_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001157ce) */

undefined8 nv_i2c_bus_status(void)

{
  return 0xffff;
}


// ===== 001157e0 __pfx_nvidia_vma_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011586d) */

undefined8 __pfx_nvidia_vma_open(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = param_1[0xc];
  uVar2 = nv_printf(0,"NVRM: VM: %s:%d: 0x%lx - 0x%lx, 0x%08lx bytes @ 0x%016llx, 0x%p, 0x%p\n",
                    "nvidia_vma_open",0x47,*param_1,param_1[1],param_1[1] - *param_1,
                    param_1[10] << 0xc,lVar1,param_1[0xb]);
  if (lVar1 != 0) {
    LOCK();
    *(long *)(lVar1 + 0x10) = *(long *)(lVar1 + 0x10) + 1;
    UNLOCK();
    uVar2 = *(undefined8 *)(lVar1 + 0x10);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nvidia_vma_open",0x4d,lVar1,*(undefined4 *)(lVar1 + 0x20),uVar2,
              *(undefined8 *)(lVar1 + 0x30));
  }
  return uVar2;
}


// ===== 001157f0 nvidia_vma_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011586d) */

undefined8 nvidia_vma_open(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = param_1[0xc];
  uVar2 = nv_printf(0,"NVRM: VM: %s:%d: 0x%lx - 0x%lx, 0x%08lx bytes @ 0x%016llx, 0x%p, 0x%p\n",
                    "nvidia_vma_open",0x47,*param_1,param_1[1],param_1[1] - *param_1,
                    param_1[10] << 0xc,lVar1,param_1[0xb]);
  if (lVar1 != 0) {
    LOCK();
    *(long *)(lVar1 + 0x10) = *(long *)(lVar1 + 0x10) + 1;
    UNLOCK();
    uVar2 = *(undefined8 *)(lVar1 + 0x10);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nvidia_vma_open",0x4d,lVar1,*(undefined4 *)(lVar1 + 0x20),uVar2,
              *(undefined8 *)(lVar1 + 0x30));
  }
  return uVar2;
}


// ===== 00115880 __pfx_nvidia_vma_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011591c) */

void __pfx_nvidia_vma_release(long *param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  bool bVar5;
  int iVar6;
  long in_GS_OFFSET;
  
  puVar3 = (undefined8 *)param_1[0xc];
  lVar4 = *(long *)(param_1[0xb] + 0x18);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%lx - 0x%lx, 0x%08lx bytes @ 0x%016llx, 0x%p, 0x%p\n",
            "nvidia_vma_release",0x65,*param_1,param_1[1],param_1[1] - *param_1,param_1[10] << 0xc,
            puVar3,param_1[0xb]);
  if (puVar3 != (undefined8 *)0x0) {
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_alloc_release",0x668,puVar3,*(undefined4 *)(puVar3 + 4));
    LOCK();
    plVar1 = puVar3 + 2;
    *plVar1 = *plVar1 + -1;
    UNLOCK();
    if (*plVar1 == 0) {
      LOCK();
      puVar3[2] = puVar3[2] + 1;
      UNLOCK();
      *puVar3 = *(undefined8 *)(lVar4 + 0x78);
      *(undefined8 **)(lVar4 + 0x78) = puVar3;
      iVar2 = *(int *)(puVar3 + 7);
      iVar6 = os_get_current_process();
      if ((iVar2 == iVar6) && (iVar2 = count_2 + 1, bVar5 = count_2 < 10, count_2 = iVar2, bVar5)) {
        nv_printf(0,"NVRM: VM: %s: late unmap, comm: %s, 0x%p\n","nvidia_vma_release",
                  *(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,puVar3);
        return;
      }
    }
  }
  return;
}


// ===== 00115890 nvidia_vma_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011591c) */

void nvidia_vma_release(long *param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  bool bVar5;
  int iVar6;
  long in_GS_OFFSET;
  
  puVar3 = (undefined8 *)param_1[0xc];
  lVar4 = *(long *)(param_1[0xb] + 0x18);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%lx - 0x%lx, 0x%08lx bytes @ 0x%016llx, 0x%p, 0x%p\n",
            "nvidia_vma_release",0x65,*param_1,param_1[1],param_1[1] - *param_1,param_1[10] << 0xc,
            puVar3,param_1[0xb]);
  if (puVar3 != (undefined8 *)0x0) {
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_alloc_release",0x668,puVar3,*(undefined4 *)(puVar3 + 4));
    LOCK();
    plVar1 = puVar3 + 2;
    *plVar1 = *plVar1 + -1;
    UNLOCK();
    if (*plVar1 == 0) {
      LOCK();
      puVar3[2] = puVar3[2] + 1;
      UNLOCK();
      *puVar3 = *(undefined8 *)(lVar4 + 0x78);
      *(undefined8 **)(lVar4 + 0x78) = puVar3;
      iVar2 = *(int *)(puVar3 + 7);
      iVar6 = os_get_current_process();
      if ((iVar2 == iVar6) && (iVar2 = count_2 + 1, bVar5 = count_2 < 10, count_2 = iVar2, bVar5)) {
        nv_printf(0,"NVRM: VM: %s: late unmap, comm: %s, 0x%p\n","nvidia_vma_release",
                  *(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,puVar3);
        return;
      }
    }
  }
  return;
}


// ===== 00115980 __pfx_nvidia_vma_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115aeb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __pfx_nvidia_vma_access(long *param_1,long param_2,void *param_3,uint param_4,int param_5)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  void *__src;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  
  if ((int)param_4 < 0) {
    return 0xffffffea;
  }
  lVar5 = *param_1;
  lVar2 = *(long *)(param_1[0xb] + 0x18);
  lVar3 = *(long *)(lVar2 + 0x80);
  down_read(lVar2 + 0x188);
  lVar4 = *(long *)(lVar2 + 0x1a8);
  if (lVar4 == 0) {
    nv_printf(4,"NVRM: VM: invalid mmap context\n");
    goto LAB_00115b92;
  }
  if ((param_5 != 0) && (uVar9 = 0xfffffff3, (*(byte *)(lVar4 + 0x40) & 2) == 0)) goto LAB_00115abf;
  uVar7 = param_2 - lVar5;
  uVar10 = *(ulong *)(lVar4 + 0x18);
  uVar9 = uVar7 >> 0xc;
  uVar8 = (uint)uVar7 & 0xfff;
  if ((*(byte *)(lVar3 + 0x10) & 4) == 0) {
    if (uVar10 == 0) {
      if (*(long *)(lVar4 + 0x28) != 0) {
        plVar6 = *(long **)(lVar4 + 0x20);
        lVar5 = 0;
        uVar9 = 0;
        do {
          plVar1 = plVar6 + 1;
          if ((uVar9 <= uVar7) && (uVar7 < uVar9 + *plVar1)) {
            lVar5 = os_map_kernel_space((uVar7 - uVar9) + *plVar6 & 0xfffffffffffff000,0x1000,1);
            __src = (void *)(lVar5 + (ulong)uVar8);
            if (lVar5 != 0) goto LAB_00115a82;
            uVar9 = 0xfffffff4;
            goto LAB_00115abf;
          }
          lVar5 = lVar5 + 1;
          plVar6 = plVar6 + 2;
          uVar9 = uVar9 + *plVar1;
        } while (lVar5 != *(long *)(lVar4 + 0x28));
      }
      goto LAB_00115b92;
    }
    __src = (void *)((*(ulong *)(*(long *)(lVar4 + 0x10) + (uVar9 & 0xffffffff) * 8) &
                     0xfffffffffffff000) + _page_offset_base + (ulong)uVar8);
  }
  else {
    uVar7 = param_1[0xc];
    if ((uVar7 == 0) || (*(uint *)(uVar7 + 0x20) <= (uint)uVar9)) {
LAB_00115b92:
      uVar9 = 0xffffffea;
      goto LAB_00115abf;
    }
    uVar10 = uVar10 | uVar7;
    __src = (void *)(*(long *)((uVar9 & 0xffffffff &
                               -(ulong)((uVar9 & 0xffffffff) < (ulong)*(uint *)(uVar7 + 0x20))) *
                               0x10 + *(long *)(uVar7 + 0x30) + 8) + (ulong)uVar8);
  }
LAB_00115a82:
  if ((int)(0x1000 - uVar8) <= (int)param_4) {
    param_4 = 0x1000 - uVar8;
  }
  uVar9 = (ulong)param_4;
  if (param_5 == 0) {
    memcpy(param_3,__src,uVar9);
  }
  else {
    memcpy(__src,param_3,uVar9);
  }
  if (uVar10 == 0) {
    os_unmap_kernel_space((long)__src - (ulong)uVar8,0x1000);
  }
LAB_00115abf:
  up_read(lVar2 + 0x188);
  return uVar9;
}


// ===== 00115990 nvidia_vma_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115aeb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong nvidia_vma_access(long *param_1,long param_2,void *param_3,uint param_4,int param_5)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  void *__src;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  
  if ((int)param_4 < 0) {
    return 0xffffffea;
  }
  lVar5 = *param_1;
  lVar2 = *(long *)(param_1[0xb] + 0x18);
  lVar3 = *(long *)(lVar2 + 0x80);
  down_read(lVar2 + 0x188);
  lVar4 = *(long *)(lVar2 + 0x1a8);
  if (lVar4 == 0) {
    nv_printf(4,"NVRM: VM: invalid mmap context\n");
    goto LAB_00115b92;
  }
  if ((param_5 != 0) && (uVar9 = 0xfffffff3, (*(byte *)(lVar4 + 0x40) & 2) == 0)) goto LAB_00115abf;
  uVar7 = param_2 - lVar5;
  uVar10 = *(ulong *)(lVar4 + 0x18);
  uVar9 = uVar7 >> 0xc;
  uVar8 = (uint)uVar7 & 0xfff;
  if ((*(byte *)(lVar3 + 0x10) & 4) == 0) {
    if (uVar10 == 0) {
      if (*(long *)(lVar4 + 0x28) != 0) {
        plVar6 = *(long **)(lVar4 + 0x20);
        lVar5 = 0;
        uVar9 = 0;
        do {
          plVar1 = plVar6 + 1;
          if ((uVar9 <= uVar7) && (uVar7 < uVar9 + *plVar1)) {
            lVar5 = os_map_kernel_space((uVar7 - uVar9) + *plVar6 & 0xfffffffffffff000,0x1000,1);
            __src = (void *)(lVar5 + (ulong)uVar8);
            if (lVar5 != 0) goto LAB_00115a82;
            uVar9 = 0xfffffff4;
            goto LAB_00115abf;
          }
          lVar5 = lVar5 + 1;
          plVar6 = plVar6 + 2;
          uVar9 = uVar9 + *plVar1;
        } while (lVar5 != *(long *)(lVar4 + 0x28));
      }
      goto LAB_00115b92;
    }
    __src = (void *)((*(ulong *)(*(long *)(lVar4 + 0x10) + (uVar9 & 0xffffffff) * 8) &
                     0xfffffffffffff000) + _page_offset_base + (ulong)uVar8);
  }
  else {
    uVar7 = param_1[0xc];
    if ((uVar7 == 0) || (*(uint *)(uVar7 + 0x20) <= (uint)uVar9)) {
LAB_00115b92:
      uVar9 = 0xffffffea;
      goto LAB_00115abf;
    }
    uVar10 = uVar10 | uVar7;
    __src = (void *)(*(long *)((uVar9 & 0xffffffff &
                               -(ulong)((uVar9 & 0xffffffff) < (ulong)*(uint *)(uVar7 + 0x20))) *
                               0x10 + *(long *)(uVar7 + 0x30) + 8) + (ulong)uVar8);
  }
LAB_00115a82:
  if ((int)(0x1000 - uVar8) <= (int)param_4) {
    param_4 = 0x1000 - uVar8;
  }
  uVar9 = (ulong)param_4;
  if (param_5 == 0) {
    memcpy(param_3,__src,uVar9);
  }
  else {
    memcpy(__src,param_3,uVar9);
  }
  if (uVar10 == 0) {
    os_unmap_kernel_space((long)__src - (ulong)uVar8,0x1000);
  }
LAB_00115abf:
  up_read(lVar2 + 0x188);
  return uVar9;
}


// ===== 00115be0 __pfx_nvidia_fault =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115d1c) */
/* WARNING: Removing unreachable block (ram,0x00115cd9) */
/* WARNING: Removing unreachable block (ram,0x00115e3a) */

int __pfx_nvidia_fault(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  ulong *puVar7;
  ulong uVar8;
  long lVar9;
  byte bVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  
  param_1 = (long *)*param_1;
  if (param_1[10] == 0) {
    lVar2 = *(long *)(param_1[0xb] + 0x18);
    lVar3 = *(long *)(lVar2 + 0x80);
    if ((*(byte *)(lVar3 + 0x10) & 4) == 0) {
      iVar6 = down_read_trylock(nv_system_pm_lock);
      if (iVar6 != 0) {
        lVar1 = lVar3 + 0x868;
        down(lVar1);
        if (*(char *)(lVar3 + 0x891) != '\0') {
          down_read(lVar2 + 0x188);
          lVar4 = *(long *)(lVar2 + 0x1a8);
          if (*(long *)(lVar4 + 0x28) == 0) {
            bVar10 = 1;
            iVar6 = 0x100;
          }
          else {
            uVar8 = 0;
            bVar10 = 1;
            lVar9 = 0;
            do {
              puVar7 = (ulong *)(uVar8 * 0x10 + *(long *)(lVar4 + 0x20));
              uVar5 = puVar7[1];
              uVar12 = uVar5 >> 0xc;
              if (uVar12 != 0) {
                uVar13 = *puVar7 >> 0xc;
                lVar11 = lVar9;
                do {
                  iVar6 = vmf_insert_pfn_prot(param_1,*param_1 + lVar11,uVar13,param_1[3]);
                  if (iVar6 != 0x100) goto LAB_00115df2;
                  lVar11 = lVar11 + 0x1000;
                  uVar13 = uVar13 + 1;
                  bVar10 = 0;
                } while (uVar12 * 0x1000 + lVar9 != lVar11);
              }
              lVar9 = lVar9 + uVar5;
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(ulong *)(lVar4 + 0x28));
            iVar6 = 0x100;
          }
LAB_00115df2:
          up_read(lVar2 + 0x188);
          *(byte *)(lVar3 + 0x890) = *(byte *)(lVar3 + 0x890) & bVar10;
          up(lVar1);
          up_read(nv_system_pm_lock);
          return iVar6;
        }
        if (*(char *)(lVar3 + 0x892) != '\0') {
          iVar6 = rm_schedule_gpu_wakeup(*(undefined8 *)(lVar3 + 0x4d0),lVar3);
          if (iVar6 != 0) {
            nv_printf(4,"NVRM: VM: rm_schedule_gpu_wakeup failed: %x\n",iVar6);
            up(lVar1);
            up_read(nv_system_pm_lock);
            return 2;
          }
          *(undefined1 *)(lVar3 + 0x892) = 0;
        }
        up(lVar1);
        up_read(nv_system_pm_lock);
      }
      return 0x100;
    }
  }
  return 2;
}


// ===== 00115bf0 nvidia_fault =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115d1c) */
/* WARNING: Removing unreachable block (ram,0x00115cd9) */
/* WARNING: Removing unreachable block (ram,0x00115e3a) */

int nvidia_fault(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  ulong *puVar7;
  ulong uVar8;
  long lVar9;
  byte bVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  
  param_1 = (long *)*param_1;
  if (param_1[10] == 0) {
    lVar2 = *(long *)(param_1[0xb] + 0x18);
    lVar3 = *(long *)(lVar2 + 0x80);
    if ((*(byte *)(lVar3 + 0x10) & 4) == 0) {
      iVar6 = down_read_trylock(nv_system_pm_lock);
      if (iVar6 != 0) {
        lVar1 = lVar3 + 0x868;
        down(lVar1);
        if (*(char *)(lVar3 + 0x891) != '\0') {
          down_read(lVar2 + 0x188);
          lVar4 = *(long *)(lVar2 + 0x1a8);
          if (*(long *)(lVar4 + 0x28) == 0) {
            bVar10 = 1;
            iVar6 = 0x100;
          }
          else {
            uVar8 = 0;
            bVar10 = 1;
            lVar9 = 0;
            do {
              puVar7 = (ulong *)(uVar8 * 0x10 + *(long *)(lVar4 + 0x20));
              uVar5 = puVar7[1];
              uVar12 = uVar5 >> 0xc;
              if (uVar12 != 0) {
                uVar13 = *puVar7 >> 0xc;
                lVar11 = lVar9;
                do {
                  iVar6 = vmf_insert_pfn_prot(param_1,*param_1 + lVar11,uVar13,param_1[3]);
                  if (iVar6 != 0x100) goto LAB_00115df2;
                  lVar11 = lVar11 + 0x1000;
                  uVar13 = uVar13 + 1;
                  bVar10 = 0;
                } while (uVar12 * 0x1000 + lVar9 != lVar11);
              }
              lVar9 = lVar9 + uVar5;
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(ulong *)(lVar4 + 0x28));
            iVar6 = 0x100;
          }
LAB_00115df2:
          up_read(lVar2 + 0x188);
          *(byte *)(lVar3 + 0x890) = *(byte *)(lVar3 + 0x890) & bVar10;
          up(lVar1);
          up_read(nv_system_pm_lock);
          return iVar6;
        }
        if (*(char *)(lVar3 + 0x892) != '\0') {
          iVar6 = rm_schedule_gpu_wakeup(*(undefined8 *)(lVar3 + 0x4d0),lVar3);
          if (iVar6 != 0) {
            nv_printf(4,"NVRM: VM: rm_schedule_gpu_wakeup failed: %x\n",iVar6);
            up(lVar1);
            up_read(nv_system_pm_lock);
            return 2;
          }
          *(undefined1 *)(lVar3 + 0x892) = 0;
        }
        up(lVar1);
        up_read(nv_system_pm_lock);
      }
      return 0x100;
    }
  }
  return 2;
}


// ===== 00115e90 __pfx_nv_encode_caching =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115f02) */

undefined8 __pfx_nv_encode_caching(ulong *param_1,uint param_2,int param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  ulong uStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (param_1 == (ulong *)0x0) {
    uStack_20 = 0;
    param_1 = &uStack_20;
    if (param_2 != 2) goto LAB_00115ed2;
LAB_00115f3e:
    uStack_20 = 0;
    if ((nv_pat_mode == 0) || (param_3 == 1)) {
LAB_00115f70:
      uVar2 = 1;
      goto LAB_00115eeb;
    }
    *param_1 = *param_1 & 0xffffffffffffff67 | 8;
  }
  else {
    uStack_20 = 0;
    if (param_2 == 2) goto LAB_00115f3e;
LAB_00115ed2:
    uStack_20 = 0;
    if (param_2 < 3) {
      if (param_2 != 0) {
        if (3 < DAT_00f79091) {
          uVar1 = *param_1;
          uVar3 = cachemode2protval(2);
          *param_1 = uVar3 | uVar1;
        }
        goto LAB_00115ee9;
      }
      if (param_3 == 0) goto LAB_00115ee9;
      nv_printf(4,"NVRM: VM: memory type %d does not allow caching!\n");
      goto LAB_00115f70;
    }
    if (param_2 == 6) goto LAB_00115f3e;
    if (param_2 != 7) {
      nv_printf(4,"NVRM: VM: cache type %d not supported for memory type %d!\n",param_2,param_3);
      goto LAB_00115f70;
    }
    uVar1 = *param_1;
    if (3 < DAT_00f79091) {
      uVar1 = *param_1 | 0x10;
    }
    *param_1 = uVar1;
  }
LAB_00115ee9:
  uVar2 = 0;
LAB_00115eeb:
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00115ea0 nv_encode_caching =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00115f02) */

undefined8 nv_encode_caching(ulong *param_1,uint param_2,int param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  ulong local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (param_1 == (ulong *)0x0) {
    local_20 = 0;
    param_1 = &local_20;
    if (param_2 != 2) goto LAB_00115ed2;
LAB_00115f3e:
    local_20 = 0;
    if ((nv_pat_mode == 0) || (param_3 == 1)) {
LAB_00115f70:
      uVar2 = 1;
      goto LAB_00115eeb;
    }
    *param_1 = *param_1 & 0xffffffffffffff67 | 8;
  }
  else {
    local_20 = 0;
    if (param_2 == 2) goto LAB_00115f3e;
LAB_00115ed2:
    local_20 = 0;
    if (param_2 < 3) {
      if (param_2 != 0) {
        if (3 < DAT_00f79091) {
          uVar1 = *param_1;
          uVar3 = cachemode2protval(2);
          *param_1 = uVar3 | uVar1;
        }
        goto LAB_00115ee9;
      }
      if (param_3 == 0) goto LAB_00115ee9;
      nv_printf(4,"NVRM: VM: memory type %d does not allow caching!\n");
      goto LAB_00115f70;
    }
    if (param_2 == 6) goto LAB_00115f3e;
    if (param_2 != 7) {
      nv_printf(4,"NVRM: VM: cache type %d not supported for memory type %d!\n",param_2,param_3);
      goto LAB_00115f70;
    }
    uVar1 = *param_1;
    if (3 < DAT_00f79091) {
      uVar1 = *param_1 | 0x10;
    }
    *param_1 = uVar1;
  }
LAB_00115ee9:
  uVar2 = 0;
LAB_00115eeb:
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00115fd0 __pfx_nvidia_mmap_helper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001160a7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nvidia_mmap_helper
              (long param_1,long param_2,undefined8 param_3,long *param_4,long param_5)

{
  uint uVar1;
  long *plVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong *puVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined4 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long in_GS_OFFSET;
  ulong *puStack_70;
  ulong uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (param_2 == 0) {
    iVar5 = 0x1f;
    goto LAB_00116088;
  }
  lVar14 = *(long *)(param_1 + 8);
  down_read(param_2 + 0x188);
  plVar2 = *(long **)(param_2 + 0x1a8);
  if (plVar2 == (long *)0x0) {
    nv_printf(4,"NVRM: VM: invalid mmap context\n");
LAB_00116066:
    iVar5 = -0x16;
  }
  else {
    if (param_4[10] != 0) goto LAB_00116066;
    nv_printf(0,"NVRM: VM: %s:%d: 0x%lx - 0x%lx, 0x%08lx bytes @ 0x%016llx, 0x%p, 0x%p\n",
              "nvidia_mmap_helper",0x240,*param_4,param_4[1],param_4[1] - *param_4,0,param_4[0xc],
              param_4[0xb]);
    if ((*(uint *)(param_1 + 0x10) & 0x8000) != 0) {
      nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping nvidia_mmap_helper\n",
                *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
      goto LAB_00116066;
    }
    param_4[0xc] = param_5;
    uVar1 = *(uint *)(plVar2 + 8);
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      uVar10 = 0;
      if (plVar2[5] != 0) {
        lVar6 = plVar2[4];
        lVar13 = plVar2[5] * 0x10 + lVar6;
        uVar10 = 0;
        do {
          uVar10 = uVar10 + *(long *)(lVar6 + 8);
          lVar6 = lVar6 + 0x10;
        } while (lVar13 != lVar6);
      }
      if (uVar10 != param_4[1] - *param_4) goto LAB_00116506;
      lVar13 = plVar2[7];
      uVar10 = plVar2[6];
      uVar11 = **(ulong **)(param_1 + 0x108);
      if (((uVar10 < uVar11) || (uVar7 = (uVar10 - 1) + lVar13, uVar7 < uVar10)) ||
         ((uVar11 + (*(ulong **)(param_1 + 0x108))[1]) - 1 < uVar7)) {
        puVar8 = *(ulong **)(param_1 + 0x140);
        if (((puVar8 != (ulong *)0x0) && (puVar8[1] != 0)) &&
           ((*puVar8 <= uVar10 &&
            ((uVar11 = (uVar10 - 1) + lVar13, uVar10 <= uVar11 &&
             (uVar11 <= (puVar8[1] - 1) + *puVar8)))))) {
          uVar7 = *(ulong *)(param_1 + 0x148);
          puStack_70 = (ulong *)(param_4 + 3);
          if ((uVar7 == 0) ||
             (((*(long *)(param_1 + 0x150) == 0 || (uVar10 < uVar7)) ||
              ((uVar7 - 1) + *(long *)(param_1 + 0x150) < uVar11)))) {
            cVar4 = rm_disable_iomap_wc();
            uVar12 = 1;
            if (cVar4 == '\0') {
              uVar12 = (undefined4)plVar2[9];
            }
            iVar5 = nv_encode_caching(puStack_70,uVar12,2);
            if (iVar5 != 0) {
              uStack_48 = 0;
              if (puStack_70 == (ulong *)0x0) {
                puStack_70 = &uStack_48;
                uVar11 = 0;
              }
              else {
                uVar11 = param_4[3];
              }
              if (3 < DAT_00f79091) {
                uVar11 = uVar11 | 0x10;
              }
              *puStack_70 = uVar11;
            }
          }
          else {
            uStack_48 = 0;
            if (puStack_70 == (ulong *)0x0) {
              puStack_70 = &uStack_48;
            }
            if (3 < DAT_00f79091) {
              uVar11 = *puStack_70;
              uVar7 = cachemode2protval(2);
              *puStack_70 = uVar7 | uVar11;
            }
          }
        }
      }
      else {
        uStack_48 = 0;
        puVar8 = (ulong *)(param_4 + 3);
        if (puVar8 == (ulong *)0x0) {
          puVar8 = &uStack_48;
        }
        if (3 < DAT_00f79091) {
          uVar11 = *puVar8;
          uVar7 = cachemode2protval(2);
          *puVar8 = uVar7 | uVar11;
        }
      }
      lVar6 = lVar14 + 0x868;
      down(lVar6);
      if (*(char *)(lVar14 + 0x891) != '\0') {
        *(undefined1 *)(lVar14 + 0x890) = 0;
        if (((*(int *)(lVar14 + 0x4a0) == -1) || (*(int *)(lVar14 + 0x4a4) != 3)) ||
           (((uVar10 >> 0xc) * 0x40 + _vmemmap_base == 0 ||
            ((((uVar10 - 1) + lVar13 >> 0xc) * 0x40 + _vmemmap_base == 0 || (plVar2[3] == 0)))))) {
          uVar10 = 0;
          lVar14 = 0;
          if (plVar2[5] != 0) {
LAB_00116236:
            lVar13 = *param_4;
            puVar8 = (ulong *)(uVar10 * 0x10 + plVar2[4]);
            uVar11 = puVar8[1];
            uVar7 = *puVar8;
            uVar9 = cc_mkdec(param_4[3]);
            iVar5 = remap_pfn_range(param_4,lVar13 + lVar14,uVar7 >> 0xc,uVar11,uVar9);
            if (iVar5 == 0) goto LAB_00116224;
            up(lVar6);
LAB_00116290:
            iVar5 = -0xb;
            goto LAB_0011606c;
          }
        }
        else {
          lVar14 = *param_4;
          uVar10 = (ulong)(param_4[1] - lVar14) >> 0xc;
          if ((ulong)plVar2[3] < uVar10) {
            iVar5 = -0x16;
LAB_001167e7:
            up(lVar6);
            goto LAB_0011606c;
          }
          if ((*(ulong *)(param_4[2] + 400) & 1) == 0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          if ((int)param_4[5] != *(int *)(param_4[2] + 0x1c8)) {
            __vma_start_write(param_4,2);
          }
          param_4[4] = param_4[4] | 0x10000000;
          if (uVar10 != 0) {
            lVar13 = uVar10 * 0x1000 + lVar14;
            lVar15 = 8;
            uVar10 = *(ulong *)plVar2[2];
            do {
              iVar5 = vm_insert_page(param_4,lVar14,(uVar10 >> 0xc) * 0x40 + _vmemmap_base);
              if (iVar5 != 0) {
                iVar5 = -0xb;
                goto LAB_001167e7;
              }
              lVar14 = lVar14 + 0x1000;
              uVar10 = *(ulong *)(plVar2[2] + lVar15);
              lVar15 = lVar15 + 8;
            } while (lVar14 != lVar13);
          }
        }
      }
LAB_00116610:
      up(lVar6);
      if ((*(ulong *)(param_4[2] + 400) & 1) == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      if ((int)param_4[5] != *(int *)(param_4[2] + 0x1c8)) {
        __vma_start_write(param_4,2);
      }
      uVar10 = param_4[4] | 0x44400;
LAB_001163f6:
      param_4[4] = uVar10;
      if ((uVar1 & 2) == 0) {
        lVar14 = param_4[2];
        param_4[3] = param_4[3] & 0xfffffffffffffffd;
        if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        iVar5 = *(int *)(lVar14 + 0x1c8);
        if ((int)param_4[5] != iVar5) {
          __vma_start_write(param_4,2);
          iVar5 = (int)param_4[5];
          lVar14 = param_4[2];
        }
        uVar10 = param_4[4] & 0xfffffffffffffffd;
        param_4[4] = uVar10;
        if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        if (iVar5 != *(int *)(lVar14 + 0x1c8)) {
          __vma_start_write(param_4,2);
          uVar10 = param_4[4];
        }
        param_4[4] = uVar10 & 0xffffffffffffffdf;
      }
      param_4[9] = (long)nv_vm_ops;
      iVar5 = 0;
    }
    else {
      lVar14 = *plVar2;
      uVar11 = plVar2[1];
      uVar7 = (ulong)(param_4[1] - *param_4) >> 0xc;
      uVar10 = uVar11 + uVar7;
      if (*(uint *)(lVar14 + 0x20) < uVar10) {
        iVar5 = -0x22;
      }
      else {
        if (param_5 != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        if ((*(byte *)(lVar14 + 0x18) & 0x40) == 0) {
          iVar5 = nv_encode_caching(param_4 + 3,*(undefined4 *)(lVar14 + 0x1c),0);
          if (iVar5 == 0) {
            param_4[0xc] = lVar14;
            LOCK();
            *(long *)(lVar14 + 0x10) = *(long *)(lVar14 + 0x10) + 1;
            UNLOCK();
            if (uVar11 < uVar10) {
              lVar13 = *param_4;
              do {
                uVar11 = uVar11 & -(ulong)(uVar11 < uVar10);
                if (((*(byte *)(lVar14 + 0x19) & 4) == 0) && (*(long *)(lVar14 + 0x60) == 0)) {
                  if ((*(byte *)(lVar14 + 0x19) & 1) != 0) {
                    lVar6 = cc_mkdec(param_4[3]);
                    param_4[3] = lVar6;
                  }
                  iVar5 = vm_insert_page(param_4,lVar13,
                                         (*(ulong *)(uVar11 * 0x10 + *(long *)(lVar14 + 0x30)) >>
                                         0xc) * 0x40 + _vmemmap_base);
                }
                else {
                  iVar5 = remap_pfn_range(param_4,lVar13,
                                          *(ulong *)(uVar11 * 0x10 + *(long *)(lVar14 + 0x30)) >>
                                          0xc,0x1000,param_4[3]);
                }
                if (iVar5 != 0) {
                  LOCK();
                  *(long *)(lVar14 + 0x10) = *(long *)(lVar14 + 0x10) + -1;
                  UNLOCK();
                  nv_printf(4,"NVRM: Userspace mapping creation failed [%d]!\n",iVar5);
                  goto LAB_00116290;
                }
                uVar11 = uVar11 + 1;
                lVar13 = lVar13 + 0x1000;
              } while (uVar11 < uVar10);
            }
            nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                      "nvidia_mmap_helper",0x2fa,lVar14,*(undefined4 *)(lVar14 + 0x20),
                      *(undefined8 *)(lVar14 + 0x10),*(undefined8 *)(lVar14 + 0x30));
            lVar14 = param_4[2];
            if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            iVar5 = *(int *)(lVar14 + 0x1c8);
            if ((int)param_4[5] != iVar5) {
              __vma_start_write(param_4,2);
              iVar5 = (int)param_4[5];
              lVar14 = param_4[2];
            }
            uVar10 = param_4[4] | 8;
            param_4[4] = uVar10;
            uVar11 = *(ulong *)(lVar14 + 400);
joined_r0x0011688e:
            if ((uVar11 & 1) == 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            if (iVar5 != *(int *)(lVar14 + 0x1c8)) {
              __vma_start_write(param_4,2);
              uVar10 = param_4[4];
            }
            uVar10 = uVar10 | 0x4040000;
            goto LAB_001163f6;
          }
        }
        else {
          iVar5 = nv_encode_caching(param_4 + 3,*(undefined4 *)(lVar14 + 0x1c),3);
          if (iVar5 == 0) {
            param_4[0xc] = 0;
            if ((*(byte *)(lVar14 + 0x18) & 1) == 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            uVar10 = *(ulong *)(uVar11 * 0x10 + *(long *)(lVar14 + 0x30));
            lVar13 = *param_4;
            uVar9 = cc_mkdec(param_4[3]);
            iVar5 = remap_pfn_range(param_4,lVar13,uVar10 >> 0xc,uVar7 << 0xc,uVar9);
            if (param_4[0xc] != 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            if (iVar5 == 0) {
              uVar9 = *(undefined8 *)(lVar14 + 0x30);
              nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                        "nvidia_mmap_helper",0x2e2,lVar14,*(undefined4 *)(lVar14 + 0x20),
                        *(undefined8 *)(lVar14 + 0x10));
              lVar14 = param_4[2];
              if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)invalidInstructionException();
                (*pcVar3)();
              }
              iVar5 = *(int *)(lVar14 + 0x1c8);
              if ((int)param_4[5] != iVar5) {
                __vma_start_write(param_4,2,lVar14,iVar5,uVar9);
                iVar5 = (int)param_4[5];
                lVar14 = param_4[2];
              }
              uVar10 = param_4[4] | 0x4000;
              param_4[4] = uVar10;
              uVar11 = *(ulong *)(lVar14 + 400);
              goto joined_r0x0011688e;
            }
            goto LAB_0011606c;
          }
        }
LAB_00116506:
        iVar5 = -6;
      }
    }
  }
LAB_0011606c:
  up_read(param_2 + 0x188);
LAB_00116088:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00116224:
  lVar14 = lVar14 + uVar11;
  uVar10 = uVar10 + 1;
  if ((ulong)plVar2[5] <= uVar10) goto LAB_00116610;
  goto LAB_00116236;
}


// ===== 00115fe0 nvidia_mmap_helper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001160a7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvidia_mmap_helper(long param_1,long param_2,undefined8 param_3,long *param_4,long param_5)

{
  uint uVar1;
  long *plVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong *puVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined4 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long in_GS_OFFSET;
  ulong *local_70;
  ulong local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (param_2 == 0) {
    iVar5 = 0x1f;
    goto LAB_00116088;
  }
  lVar14 = *(long *)(param_1 + 8);
  down_read(param_2 + 0x188);
  plVar2 = *(long **)(param_2 + 0x1a8);
  if (plVar2 == (long *)0x0) {
    nv_printf(4,"NVRM: VM: invalid mmap context\n");
LAB_00116066:
    iVar5 = -0x16;
  }
  else {
    if (param_4[10] != 0) goto LAB_00116066;
    nv_printf(0,"NVRM: VM: %s:%d: 0x%lx - 0x%lx, 0x%08lx bytes @ 0x%016llx, 0x%p, 0x%p\n",
              "nvidia_mmap_helper",0x240,*param_4,param_4[1],param_4[1] - *param_4,0,param_4[0xc],
              param_4[0xb]);
    if ((*(uint *)(param_1 + 0x10) & 0x8000) != 0) {
      nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping nvidia_mmap_helper\n",
                *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
      goto LAB_00116066;
    }
    param_4[0xc] = param_5;
    uVar1 = *(uint *)(plVar2 + 8);
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      uVar10 = 0;
      if (plVar2[5] != 0) {
        lVar6 = plVar2[4];
        lVar13 = plVar2[5] * 0x10 + lVar6;
        uVar10 = 0;
        do {
          uVar10 = uVar10 + *(long *)(lVar6 + 8);
          lVar6 = lVar6 + 0x10;
        } while (lVar13 != lVar6);
      }
      if (uVar10 != param_4[1] - *param_4) goto LAB_00116506;
      lVar13 = plVar2[7];
      uVar10 = plVar2[6];
      uVar11 = **(ulong **)(param_1 + 0x108);
      if (((uVar10 < uVar11) || (uVar7 = (uVar10 - 1) + lVar13, uVar7 < uVar10)) ||
         ((uVar11 + (*(ulong **)(param_1 + 0x108))[1]) - 1 < uVar7)) {
        puVar8 = *(ulong **)(param_1 + 0x140);
        if (((puVar8 != (ulong *)0x0) && (puVar8[1] != 0)) &&
           ((*puVar8 <= uVar10 &&
            ((uVar11 = (uVar10 - 1) + lVar13, uVar10 <= uVar11 &&
             (uVar11 <= (puVar8[1] - 1) + *puVar8)))))) {
          uVar7 = *(ulong *)(param_1 + 0x148);
          local_70 = (ulong *)(param_4 + 3);
          if ((uVar7 == 0) ||
             (((*(long *)(param_1 + 0x150) == 0 || (uVar10 < uVar7)) ||
              ((uVar7 - 1) + *(long *)(param_1 + 0x150) < uVar11)))) {
            cVar4 = rm_disable_iomap_wc();
            uVar12 = 1;
            if (cVar4 == '\0') {
              uVar12 = (undefined4)plVar2[9];
            }
            iVar5 = nv_encode_caching(local_70,uVar12,2);
            if (iVar5 != 0) {
              local_48 = 0;
              if (local_70 == (ulong *)0x0) {
                local_70 = &local_48;
                uVar11 = 0;
              }
              else {
                uVar11 = param_4[3];
              }
              if (3 < DAT_00f79091) {
                uVar11 = uVar11 | 0x10;
              }
              *local_70 = uVar11;
            }
          }
          else {
            local_48 = 0;
            if (local_70 == (ulong *)0x0) {
              local_70 = &local_48;
            }
            if (3 < DAT_00f79091) {
              uVar11 = *local_70;
              uVar7 = cachemode2protval(2);
              *local_70 = uVar7 | uVar11;
            }
          }
        }
      }
      else {
        local_48 = 0;
        puVar8 = (ulong *)(param_4 + 3);
        if (puVar8 == (ulong *)0x0) {
          puVar8 = &local_48;
        }
        if (3 < DAT_00f79091) {
          uVar11 = *puVar8;
          uVar7 = cachemode2protval(2);
          *puVar8 = uVar7 | uVar11;
        }
      }
      lVar6 = lVar14 + 0x868;
      down(lVar6);
      if (*(char *)(lVar14 + 0x891) != '\0') {
        *(undefined1 *)(lVar14 + 0x890) = 0;
        if (((*(int *)(lVar14 + 0x4a0) == -1) || (*(int *)(lVar14 + 0x4a4) != 3)) ||
           (((uVar10 >> 0xc) * 0x40 + _vmemmap_base == 0 ||
            ((((uVar10 - 1) + lVar13 >> 0xc) * 0x40 + _vmemmap_base == 0 || (plVar2[3] == 0)))))) {
          uVar10 = 0;
          lVar14 = 0;
          if (plVar2[5] != 0) {
LAB_00116236:
            lVar13 = *param_4;
            puVar8 = (ulong *)(uVar10 * 0x10 + plVar2[4]);
            uVar11 = puVar8[1];
            uVar7 = *puVar8;
            uVar9 = cc_mkdec(param_4[3]);
            iVar5 = remap_pfn_range(param_4,lVar13 + lVar14,uVar7 >> 0xc,uVar11,uVar9);
            if (iVar5 == 0) goto LAB_00116224;
            up(lVar6);
LAB_00116290:
            iVar5 = -0xb;
            goto LAB_0011606c;
          }
        }
        else {
          lVar14 = *param_4;
          uVar10 = (ulong)(param_4[1] - lVar14) >> 0xc;
          if ((ulong)plVar2[3] < uVar10) {
            iVar5 = -0x16;
LAB_001167e7:
            up(lVar6);
            goto LAB_0011606c;
          }
          if ((*(ulong *)(param_4[2] + 400) & 1) == 0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          if ((int)param_4[5] != *(int *)(param_4[2] + 0x1c8)) {
            __vma_start_write(param_4,2);
          }
          param_4[4] = param_4[4] | 0x10000000;
          if (uVar10 != 0) {
            lVar13 = uVar10 * 0x1000 + lVar14;
            lVar15 = 8;
            uVar10 = *(ulong *)plVar2[2];
            do {
              iVar5 = vm_insert_page(param_4,lVar14,(uVar10 >> 0xc) * 0x40 + _vmemmap_base);
              if (iVar5 != 0) {
                iVar5 = -0xb;
                goto LAB_001167e7;
              }
              lVar14 = lVar14 + 0x1000;
              uVar10 = *(ulong *)(plVar2[2] + lVar15);
              lVar15 = lVar15 + 8;
            } while (lVar14 != lVar13);
          }
        }
      }
LAB_00116610:
      up(lVar6);
      if ((*(ulong *)(param_4[2] + 400) & 1) == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      if ((int)param_4[5] != *(int *)(param_4[2] + 0x1c8)) {
        __vma_start_write(param_4,2);
      }
      uVar10 = param_4[4] | 0x44400;
LAB_001163f6:
      param_4[4] = uVar10;
      if ((uVar1 & 2) == 0) {
        lVar14 = param_4[2];
        param_4[3] = param_4[3] & 0xfffffffffffffffd;
        if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        iVar5 = *(int *)(lVar14 + 0x1c8);
        if ((int)param_4[5] != iVar5) {
          __vma_start_write(param_4,2);
          iVar5 = (int)param_4[5];
          lVar14 = param_4[2];
        }
        uVar10 = param_4[4] & 0xfffffffffffffffd;
        param_4[4] = uVar10;
        if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        if (iVar5 != *(int *)(lVar14 + 0x1c8)) {
          __vma_start_write(param_4,2);
          uVar10 = param_4[4];
        }
        param_4[4] = uVar10 & 0xffffffffffffffdf;
      }
      param_4[9] = (long)nv_vm_ops;
      iVar5 = 0;
    }
    else {
      lVar14 = *plVar2;
      uVar11 = plVar2[1];
      uVar7 = (ulong)(param_4[1] - *param_4) >> 0xc;
      uVar10 = uVar11 + uVar7;
      if (*(uint *)(lVar14 + 0x20) < uVar10) {
        iVar5 = -0x22;
      }
      else {
        if (param_5 != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        if ((*(byte *)(lVar14 + 0x18) & 0x40) == 0) {
          iVar5 = nv_encode_caching(param_4 + 3,*(undefined4 *)(lVar14 + 0x1c),0);
          if (iVar5 == 0) {
            param_4[0xc] = lVar14;
            LOCK();
            *(long *)(lVar14 + 0x10) = *(long *)(lVar14 + 0x10) + 1;
            UNLOCK();
            if (uVar11 < uVar10) {
              lVar13 = *param_4;
              do {
                uVar11 = uVar11 & -(ulong)(uVar11 < uVar10);
                if (((*(byte *)(lVar14 + 0x19) & 4) == 0) && (*(long *)(lVar14 + 0x60) == 0)) {
                  if ((*(byte *)(lVar14 + 0x19) & 1) != 0) {
                    lVar6 = cc_mkdec(param_4[3]);
                    param_4[3] = lVar6;
                  }
                  iVar5 = vm_insert_page(param_4,lVar13,
                                         (*(ulong *)(uVar11 * 0x10 + *(long *)(lVar14 + 0x30)) >>
                                         0xc) * 0x40 + _vmemmap_base);
                }
                else {
                  iVar5 = remap_pfn_range(param_4,lVar13,
                                          *(ulong *)(uVar11 * 0x10 + *(long *)(lVar14 + 0x30)) >>
                                          0xc,0x1000,param_4[3]);
                }
                if (iVar5 != 0) {
                  LOCK();
                  *(long *)(lVar14 + 0x10) = *(long *)(lVar14 + 0x10) + -1;
                  UNLOCK();
                  nv_printf(4,"NVRM: Userspace mapping creation failed [%d]!\n",iVar5);
                  goto LAB_00116290;
                }
                uVar11 = uVar11 + 1;
                lVar13 = lVar13 + 0x1000;
              } while (uVar11 < uVar10);
            }
            nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                      "nvidia_mmap_helper",0x2fa,lVar14,*(undefined4 *)(lVar14 + 0x20),
                      *(undefined8 *)(lVar14 + 0x10),*(undefined8 *)(lVar14 + 0x30));
            lVar14 = param_4[2];
            if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            iVar5 = *(int *)(lVar14 + 0x1c8);
            if ((int)param_4[5] != iVar5) {
              __vma_start_write(param_4,2);
              iVar5 = (int)param_4[5];
              lVar14 = param_4[2];
            }
            uVar10 = param_4[4] | 8;
            param_4[4] = uVar10;
            uVar11 = *(ulong *)(lVar14 + 400);
joined_r0x0011688e:
            if ((uVar11 & 1) == 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            if (iVar5 != *(int *)(lVar14 + 0x1c8)) {
              __vma_start_write(param_4,2);
              uVar10 = param_4[4];
            }
            uVar10 = uVar10 | 0x4040000;
            goto LAB_001163f6;
          }
        }
        else {
          iVar5 = nv_encode_caching(param_4 + 3,*(undefined4 *)(lVar14 + 0x1c),3);
          if (iVar5 == 0) {
            param_4[0xc] = 0;
            if ((*(byte *)(lVar14 + 0x18) & 1) == 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            uVar10 = *(ulong *)(uVar11 * 0x10 + *(long *)(lVar14 + 0x30));
            lVar13 = *param_4;
            uVar9 = cc_mkdec(param_4[3]);
            iVar5 = remap_pfn_range(param_4,lVar13,uVar10 >> 0xc,uVar7 << 0xc,uVar9);
            if (param_4[0xc] != 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
            if (iVar5 == 0) {
              uVar9 = *(undefined8 *)(lVar14 + 0x30);
              nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                        "nvidia_mmap_helper",0x2e2,lVar14,*(undefined4 *)(lVar14 + 0x20),
                        *(undefined8 *)(lVar14 + 0x10));
              lVar14 = param_4[2];
              if ((*(ulong *)(lVar14 + 400) & 1) == 0) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)invalidInstructionException();
                (*pcVar3)();
              }
              iVar5 = *(int *)(lVar14 + 0x1c8);
              if ((int)param_4[5] != iVar5) {
                __vma_start_write(param_4,2,lVar14,iVar5,uVar9);
                iVar5 = (int)param_4[5];
                lVar14 = param_4[2];
              }
              uVar10 = param_4[4] | 0x4000;
              param_4[4] = uVar10;
              uVar11 = *(ulong *)(lVar14 + 400);
              goto joined_r0x0011688e;
            }
            goto LAB_0011606c;
          }
        }
LAB_00116506:
        iVar5 = -6;
      }
    }
  }
LAB_0011606c:
  up_read(param_2 + 0x188);
LAB_00116088:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00116224:
  lVar14 = lVar14 + uVar11;
  uVar10 = uVar10 + 1;
  if ((ulong)plVar2[5] <= uVar10) goto LAB_00116610;
  goto LAB_00116236;
}


// ===== 001169a0 __pfx_nvidia_mmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116a58) */

ulong __pfx_nvidia_mmap(long param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  
  plVar1 = *(long **)(param_1 + 0x18);
  if (*plVar1 == 0) {
    if ((*(uint *)(*(long *)(param_1 + 0x20) + 0x4c) & 0xfffff) != 0xff) {
      uVar4 = wait_for_completion_interruptible(plVar1 + 0x3a);
      if (uVar4 != 0) {
        return (ulong)uVar4;
      }
    }
    lVar2 = plVar1[0x10];
    if (lVar2 == 0) {
      uVar5 = 0xfffffffb;
    }
    else {
      cVar3 = rm_is_altstack_in_use();
      if (cVar3 == '\0') {
        uVar5 = nvidia_mmap_helper(lVar2,plVar1,0,param_2,0);
        return uVar5;
      }
      puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar6 == (undefined4 *)0x0) {
        uVar5 = 0xfffffff4;
        nv_printf(4,"NVRM: Unable to allocate altstack for mmap\n");
      }
      else {
        *puVar6 = 0x2ff0;
        *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
        uVar4 = nvidia_mmap_helper(lVar2,plVar1,puVar6,param_2,0);
        uVar5 = (ulong)uVar4;
        cVar3 = rm_is_altstack_in_use();
        if (cVar3 != '\0') {
          kmem_cache_free(nvidia_stack_t_cache,puVar6);
        }
      }
    }
  }
  else {
    uVar5 = 0xffffffea;
  }
  return uVar5;
}


// ===== 001169b0 nvidia_mmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116a58) */

ulong nvidia_mmap(long param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  
  plVar1 = *(long **)(param_1 + 0x18);
  if (*plVar1 == 0) {
    if ((*(uint *)(*(long *)(param_1 + 0x20) + 0x4c) & 0xfffff) != 0xff) {
      uVar4 = wait_for_completion_interruptible(plVar1 + 0x3a);
      if (uVar4 != 0) {
        return (ulong)uVar4;
      }
    }
    lVar2 = plVar1[0x10];
    if (lVar2 == 0) {
      uVar5 = 0xfffffffb;
    }
    else {
      cVar3 = rm_is_altstack_in_use();
      if (cVar3 == '\0') {
        uVar5 = nvidia_mmap_helper(lVar2,plVar1,0,param_2,0);
        return uVar5;
      }
      puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar6 == (undefined4 *)0x0) {
        uVar5 = 0xfffffff4;
        nv_printf(4,"NVRM: Unable to allocate altstack for mmap\n");
      }
      else {
        *puVar6 = 0x2ff0;
        *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
        uVar4 = nvidia_mmap_helper(lVar2,plVar1,puVar6,param_2,0);
        uVar5 = (ulong)uVar4;
        cVar3 = rm_is_altstack_in_use();
        if (cVar3 != '\0') {
          kmem_cache_free(nvidia_stack_t_cache,puVar6);
        }
      }
    }
  }
  else {
    uVar5 = 0xffffffea;
  }
  return uVar5;
}


// ===== 00116b00 __pfx_nv_revoke_gpu_mappings_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116b93) */

void __pfx_nv_revoke_gpu_mappings_locked(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  for (puVar2 = *(undefined8 **)(lVar1 + 0x880); (undefined8 *)(lVar1 + 0x880) != puVar2;
      puVar2 = (undefined8 *)*puVar2) {
    unmap_mapping_range(puVar2 + -0x23,0,0xffffffffffffffff,1);
  }
  *(undefined1 *)(lVar1 + 0x890) = 1;
  return;
}


// ===== 00116b10 nv_revoke_gpu_mappings_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116b93) */

void nv_revoke_gpu_mappings_locked(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  for (puVar2 = *(undefined8 **)(lVar1 + 0x880); (undefined8 *)(lVar1 + 0x880) != puVar2;
      puVar2 = (undefined8 *)*puVar2) {
    unmap_mapping_range(puVar2 + -0x23,0,0xffffffffffffffff,1);
  }
  *(undefined1 *)(lVar1 + 0x890) = 1;
  return;
}


// ===== 00116ba0 __pfx_nv_revoke_gpu_mappings =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116c42) */
/* WARNING: Removing unreachable block (ram,0x00116c4c) */

undefined8 __pfx_nv_revoke_gpu_mappings(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  
  if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
    lVar1 = *(long *)(param_1 + 8) + 0x868;
    down(lVar1);
    lVar2 = *(long *)(param_1 + 8);
    for (puVar3 = *(undefined8 **)(lVar2 + 0x880); (undefined8 *)(lVar2 + 0x880) != puVar3;
        puVar3 = (undefined8 *)*puVar3) {
      unmap_mapping_range(puVar3 + -0x23,0,0xffffffffffffffff,1);
    }
    *(undefined1 *)(lVar2 + 0x890) = 1;
    up(lVar1);
    return 0;
  }
  return 0x56;
}


// ===== 00116bb0 nv_revoke_gpu_mappings =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116c42) */
/* WARNING: Removing unreachable block (ram,0x00116c4c) */

undefined8 nv_revoke_gpu_mappings(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  
  if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
    lVar1 = *(long *)(param_1 + 8) + 0x868;
    down(lVar1);
    lVar2 = *(long *)(param_1 + 8);
    for (puVar3 = *(undefined8 **)(lVar2 + 0x880); (undefined8 *)(lVar2 + 0x880) != puVar3;
        puVar3 = (undefined8 *)*puVar3) {
      unmap_mapping_range(puVar3 + -0x23,0,0xffffffffffffffff,1);
    }
    *(undefined1 *)(lVar2 + 0x890) = 1;
    up(lVar1);
    return 0;
  }
  return 0x56;
}


// ===== 00116c60 __pfx_nv_acquire_file_va =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116c96) */
/* WARNING: Removing unreachable block (ram,0x00116ca8) */

long __pfx_nv_acquire_file_va(long param_1,char param_2)

{
  if (param_2 != '\0') {
    down_write();
    return param_1 + 0x1a8;
  }
  down_read(param_1 + 0x188);
  return param_1 + 0x1a8;
}


// ===== 00116c70 nv_acquire_file_va =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116c96) */
/* WARNING: Removing unreachable block (ram,0x00116ca8) */

long nv_acquire_file_va(long param_1,char param_2)

{
  if (param_2 != '\0') {
    down_write();
    return param_1 + 0x1a8;
  }
  down_read(param_1 + 0x188);
  return param_1 + 0x1a8;
}


// ===== 00116cb0 __pfx_nv_release_file_va =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_release_file_va(long param_1,char param_2)

{
  if (param_2 != '\0') {
    up_write();
    return;
  }
  up_read(param_1 + 0x188);
  return;
}


// ===== 00116cc0 nv_release_file_va =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_release_file_va(long param_1,char param_2)

{
  if (param_2 != '\0') {
    up_write();
    return;
  }
  up_read(param_1 + 0x188);
  return;
}


// ===== 00116ce0 __pfx_nv_acquire_mmap_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_acquire_mmap_lock(long param_1)

{
  down(*(long *)(param_1 + 8) + 0x868);
  return;
}


// ===== 00116cf0 nv_acquire_mmap_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_acquire_mmap_lock(long param_1)

{
  down(*(long *)(param_1 + 8) + 0x868);
  return;
}


// ===== 00116d10 __pfx_nv_release_mmap_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_release_mmap_lock(long param_1)

{
  up(*(long *)(param_1 + 8) + 0x868);
  return;
}


// ===== 00116d20 nv_release_mmap_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_release_mmap_lock(long param_1)

{
  up(*(long *)(param_1 + 8) + 0x868);
  return;
}


// ===== 00116d40 __pfx_nv_get_all_mappings_revoked_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116d64) */

undefined1 __pfx_nv_get_all_mappings_revoked_locked(long param_1)

{
  return *(undefined1 *)(*(long *)(param_1 + 8) + 0x890);
}


// ===== 00116d50 nv_get_all_mappings_revoked_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116d64) */

undefined1 nv_get_all_mappings_revoked_locked(long param_1)

{
  return *(undefined1 *)(*(long *)(param_1 + 8) + 0x890);
}


// ===== 00116d70 __pfx_nv_set_safe_to_mmap_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116da9) */

void __pfx_nv_set_safe_to_mmap_locked(long param_1,char param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 8);
  if ((param_2 == '\0') && (*(char *)(lVar1 + 0x891) != '\0')) {
    *(undefined1 *)(lVar1 + 0x892) = 1;
  }
  *(char *)(lVar1 + 0x891) = param_2;
  return;
}


// ===== 00116d80 nv_set_safe_to_mmap_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116da9) */

void nv_set_safe_to_mmap_locked(long param_1,char param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 8);
  if ((param_2 == '\0') && (*(char *)(lVar1 + 0x891) != '\0')) {
    *(undefined1 *)(lVar1 + 0x892) = 1;
  }
  *(char *)(lVar1 + 0x891) = param_2;
  return;
}


// ===== 00116dc0 __pfx_nvidia_p2p_init_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116dde) */

undefined8 __pfx_nvidia_p2p_init_mapping(void)

{
  return 0xfffffdf4;
}


// ===== 00116dd0 nvidia_p2p_init_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116dde) */

undefined8 nvidia_p2p_init_mapping(void)

{
  return 0xfffffdf4;
}


// ===== 00116df0 __pfx_nvidia_p2p_destroy_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e0e) */

undefined8 __pfx_nvidia_p2p_destroy_mapping(void)

{
  return 0xfffffdf4;
}


// ===== 00116e00 nvidia_p2p_destroy_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e0e) */

undefined8 nvidia_p2p_destroy_mapping(void)

{
  return 0xfffffdf4;
}


// ===== 00116e20 __pfx_nvidia_p2p_free_page_table =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e3b) */

undefined8 __pfx_nvidia_p2p_free_page_table(void)

{
  return 0;
}


// ===== 00116e30 nvidia_p2p_free_page_table =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e3b) */

undefined8 nvidia_p2p_free_page_table(void)

{
  return 0;
}


// ===== 00116e40 __pfx_nvidia_p2p_get_rsync_registers =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e5e) */

undefined8 __pfx_nvidia_p2p_get_rsync_registers(void)

{
  return 0xffffffed;
}


// ===== 00116e50 nvidia_p2p_get_rsync_registers =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e5e) */

undefined8 nvidia_p2p_get_rsync_registers(void)

{
  return 0xffffffed;
}


// ===== 00116e70 __pfx_nvidia_p2p_put_rsync_registers =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e89) */

void __pfx_nvidia_p2p_put_rsync_registers(void)

{
  return;
}


// ===== 00116e80 nvidia_p2p_put_rsync_registers =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116e89) */

void nvidia_p2p_put_rsync_registers(void)

{
  return;
}


// ===== 00116e90 __pfx_nv_p2p_free_dma_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116f59) */
/* WARNING: Type propagation algorithm not settling */

void __pfx_nv_p2p_free_dma_mapping(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long in_GS_OFFSET;
  long alStack_58 [3];
  long lStack_40;
  long lStack_38;
  
  iVar4 = *(int *)(param_1 + 8);
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  alStack_58[1] = 0;
  lStack_40 = *(long *)(param_1 + 0x20) + 0xd0;
  alStack_58[2] = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x88);
  uVar9 = *(uint *)(nvidia_p2p_page_size_mappings + (ulong)*(uint *)(param_1 + 4) * 4);
  if (*(long *)(param_1 + 0x18) == 0) {
    if (iVar4 != 0) {
      lVar11 = 0;
      do {
        lVar2 = lVar11 * 8;
        lVar11 = lVar11 + 1;
        nv_dma_unmap_peer(alStack_58 + 1,uVar9 >> 0xc,
                          *(undefined8 *)(*(long *)(param_1 + 0x10) + lVar2));
      } while ((uint)lVar11 < *(uint *)(param_1 + 8));
    }
  }
  else if (uVar9 == 0x1000) {
    iVar4 = nv_dma_unmap_alloc(alStack_58 + 1,iVar4,*(undefined8 *)(param_1 + 0x10),param_1 + 0x18);
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
  }
  else {
    uVar9 = uVar9 >> 0xc;
    alStack_58[0] = 0;
    iVar5 = os_alloc_mem(alStack_58,(ulong)(iVar4 * uVar9) * 8);
    if (iVar5 != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar11 = 0;
    uVar10 = 0;
    uVar8 = uVar9;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        *(undefined8 *)(alStack_58[0] + (ulong)uVar10 * 8) =
             *(undefined8 *)(*(long *)(param_1 + 0x10) + lVar11 * 8);
        uVar6 = uVar10 + 1;
        do {
          uVar1 = uVar6 - 1;
          uVar7 = (ulong)uVar6;
          uVar6 = uVar6 + 1;
          *(long *)(alStack_58[0] + uVar7 * 8) =
               *(long *)(alStack_58[0] + (ulong)uVar1 * 8) + 0x1000;
        } while (uVar6 != uVar8);
        uVar10 = uVar10 + uVar9;
        lVar11 = lVar11 + 1;
        uVar8 = uVar8 + uVar9;
      } while ((uint)lVar11 < *(uint *)(param_1 + 8));
    }
    iVar4 = nv_dma_unmap_alloc(alStack_58 + 1,(ulong)(iVar4 * uVar9),alStack_58[0],param_1 + 0x18);
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    os_free_mem(alStack_58[0]);
  }
  os_free_mem(*(undefined8 *)(param_1 + 0x10));
  os_free_mem(param_1);
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 00116ea0 nv_p2p_free_dma_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00116f59) */
/* WARNING: Type propagation algorithm not settling */

void nv_p2p_free_dma_mapping(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long in_GS_OFFSET;
  long local_58 [3];
  long local_40;
  long local_38;
  
  iVar4 = *(int *)(param_1 + 8);
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_58[1] = 0;
  local_40 = *(long *)(param_1 + 0x20) + 0xd0;
  local_58[2] = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x88);
  uVar9 = *(uint *)(nvidia_p2p_page_size_mappings + (ulong)*(uint *)(param_1 + 4) * 4);
  if (*(long *)(param_1 + 0x18) == 0) {
    if (iVar4 != 0) {
      lVar11 = 0;
      do {
        lVar2 = lVar11 * 8;
        lVar11 = lVar11 + 1;
        nv_dma_unmap_peer(local_58 + 1,uVar9 >> 0xc,
                          *(undefined8 *)(*(long *)(param_1 + 0x10) + lVar2));
      } while ((uint)lVar11 < *(uint *)(param_1 + 8));
    }
  }
  else if (uVar9 == 0x1000) {
    iVar4 = nv_dma_unmap_alloc(local_58 + 1,iVar4,*(undefined8 *)(param_1 + 0x10),param_1 + 0x18);
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
  }
  else {
    uVar9 = uVar9 >> 0xc;
    local_58[0] = 0;
    iVar5 = os_alloc_mem(local_58,(ulong)(iVar4 * uVar9) * 8);
    if (iVar5 != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar11 = 0;
    uVar10 = 0;
    uVar8 = uVar9;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        *(undefined8 *)(local_58[0] + (ulong)uVar10 * 8) =
             *(undefined8 *)(*(long *)(param_1 + 0x10) + lVar11 * 8);
        uVar6 = uVar10 + 1;
        do {
          uVar1 = uVar6 - 1;
          uVar7 = (ulong)uVar6;
          uVar6 = uVar6 + 1;
          *(long *)(local_58[0] + uVar7 * 8) = *(long *)(local_58[0] + (ulong)uVar1 * 8) + 0x1000;
        } while (uVar6 != uVar8);
        uVar10 = uVar10 + uVar9;
        lVar11 = lVar11 + 1;
        uVar8 = uVar8 + uVar9;
      } while ((uint)lVar11 < *(uint *)(param_1 + 8));
    }
    iVar4 = nv_dma_unmap_alloc(local_58 + 1,(ulong)(iVar4 * uVar9),local_58[0],param_1 + 0x18);
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    os_free_mem(local_58[0]);
  }
  os_free_mem(*(undefined8 *)(param_1 + 0x10));
  os_free_mem(param_1);
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 00117070 __pfx_nv_p2p_remove_dma_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117123) */

long __pfx_nv_p2p_remove_dma_mapping(long param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  
  down(param_1 + 0x48);
  plVar4 = *(long **)(param_1 + 0x38);
  if ((long *)(param_1 + 0x38) == plVar4) {
LAB_001170ce:
    lVar3 = 0;
  }
  else {
    lVar3 = plVar4[2];
    lVar2 = lVar3;
    if (param_2 != 0) {
      while (param_2 != lVar2) {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(param_1 + 0x38)) goto LAB_001170ce;
        lVar3 = param_2;
        lVar2 = plVar4[2];
      }
    }
    plVar1 = (long *)plVar4[1];
    lVar2 = *plVar4;
    if (((long *)*plVar1 == plVar4) && (plVar4 == *(long **)(lVar2 + 8))) {
      *(long **)(lVar2 + 8) = plVar1;
      *plVar1 = lVar2;
    }
    else {
      __list_del_entry_valid_or_report();
    }
    *plVar4 = -0x2152ffffffffff00;
    plVar4[1] = -0x2152fffffffffede;
    os_free_mem();
  }
  up(param_1 + 0x48);
  return lVar3;
}


// ===== 00117080 nv_p2p_remove_dma_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117123) */

long nv_p2p_remove_dma_mapping(long param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  
  down(param_1 + 0x48);
  plVar4 = *(long **)(param_1 + 0x38);
  if ((long *)(param_1 + 0x38) == plVar4) {
LAB_001170ce:
    lVar3 = 0;
  }
  else {
    lVar3 = plVar4[2];
    lVar2 = lVar3;
    if (param_2 != 0) {
      while (param_2 != lVar2) {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(param_1 + 0x38)) goto LAB_001170ce;
        lVar3 = param_2;
        lVar2 = plVar4[2];
      }
    }
    plVar1 = (long *)plVar4[1];
    lVar2 = *plVar4;
    if (((long *)*plVar1 == plVar4) && (plVar4 == *(long **)(lVar2 + 8))) {
      *(long **)(lVar2 + 8) = plVar1;
      *plVar1 = lVar2;
    }
    else {
      __list_del_entry_valid_or_report();
    }
    *plVar4 = -0x2152ffffffffff00;
    plVar4[1] = -0x2152fffffffffede;
    os_free_mem();
  }
  up(param_1 + 0x48);
  return lVar3;
}


// ===== 00117130 __pfx_nv_p2p_free_page_table =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_p2p_free_page_table(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = nv_p2p_remove_dma_mapping(param_1 + -0x10,0);
  while (lVar2 != 0) {
    nv_p2p_free_dma_mapping(lVar2);
    lVar2 = nv_p2p_remove_dma_mapping(param_1 + -0x10,0);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    lVar2 = 0;
    do {
      lVar1 = lVar2 * 8;
      lVar2 = lVar2 + 1;
      kmem_cache_free(nvidia_p2p_page_t_cache,*(undefined8 *)(*(long *)(param_1 + 8) + lVar1));
    } while ((uint)lVar2 < *(uint *)(param_1 + 0x10));
  }
  if (*(long *)(param_1 + 0x18) != 0) {
    os_free_mem();
  }
  if (*(long *)(param_1 + 8) != 0) {
    os_free_mem();
  }
  os_free_mem(param_1 + -0x10);
  return;
}


// ===== 00117140 nv_p2p_free_page_table =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_p2p_free_page_table(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = nv_p2p_remove_dma_mapping(param_1 + -0x10,0);
  while (lVar2 != 0) {
    nv_p2p_free_dma_mapping(lVar2);
    lVar2 = nv_p2p_remove_dma_mapping(param_1 + -0x10,0);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    lVar2 = 0;
    do {
      lVar1 = lVar2 * 8;
      lVar2 = lVar2 + 1;
      kmem_cache_free(nvidia_p2p_page_t_cache,*(undefined8 *)(*(long *)(param_1 + 8) + lVar1));
    } while ((uint)lVar2 < *(uint *)(param_1 + 0x10));
  }
  if (*(long *)(param_1 + 0x18) != 0) {
    os_free_mem();
  }
  if (*(long *)(param_1 + 8) != 0) {
    os_free_mem();
  }
  os_free_mem(param_1 + -0x10);
  return;
}


// ===== 001171e0 __pfx_nv_p2p_mem_info_free_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_nv_p2p_mem_info_free_callback(undefined8 *param_1)

{
  code *pcVar1;
  
  (*(code *)*param_1)(param_1[1]);
  if (param_1 + 2 != (undefined8 *)0x0) {
    nv_p2p_free_page_table(param_1 + 2);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001171f0 nv_p2p_mem_info_free_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nv_p2p_mem_info_free_callback(undefined8 *param_1)

{
  code *pcVar1;
  
  (*(code *)*param_1)(param_1[1]);
  if (param_1 + 2 != (undefined8 *)0x0) {
    nv_p2p_free_page_table(param_1 + 2);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00117220 __pfx_nvidia_p2p_dma_unmap_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117284) */
/* WARNING: Removing unreachable block (ram,0x00117294) */

undefined8 __pfx_nvidia_p2p_dma_unmap_pages(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  long lVar2;
  
  if ((param_3 == 0 || param_2 == 0) || (param_1 == 0)) {
    return 0xffffffea;
  }
  lVar2 = nv_p2p_remove_dma_mapping(param_2 + -0x10,param_3);
  if (lVar2 != 0) {
    if (*(long *)(param_3 + 0x20) != param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if (1 < *(int *)(param_3 + 4) - 1U) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    nv_p2p_free_dma_mapping(param_3);
  }
  return 0;
}


// ===== 00117230 nvidia_p2p_dma_unmap_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117284) */
/* WARNING: Removing unreachable block (ram,0x00117294) */

undefined8 nvidia_p2p_dma_unmap_pages(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  long lVar2;
  
  if ((param_3 == 0 || param_2 == 0) || (param_1 == 0)) {
    return 0xffffffea;
  }
  lVar2 = nv_p2p_remove_dma_mapping(param_2 + -0x10,param_3);
  if (lVar2 != 0) {
    if (*(long *)(param_3 + 0x20) != param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if (1 < *(int *)(param_3 + 4) - 1U) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    nv_p2p_free_dma_mapping(param_3);
  }
  return 0;
}


// ===== 001172a0 __pfx_nvidia_p2p_register_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001172fa) */

undefined8 __pfx_nvidia_p2p_register_rsync_driver(uint *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != (uint *)0x0) && (*param_1 >> 0x10 == 1)) && ((short)*param_1 != 0)) &&
     (((*(long *)(param_1 + 2) != 0 && (*(long *)(param_1 + 4) != 0)) &&
      (*(long *)(param_1 + 6) != 0)))) {
    uVar1 = nv_register_rsync_driver
                      (*(long *)(param_1 + 2),*(long *)(param_1 + 4),*(long *)(param_1 + 6),param_2)
    ;
    return uVar1;
  }
  return 0xffffffea;
}


// ===== 001172b0 nvidia_p2p_register_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001172fa) */

undefined8 nvidia_p2p_register_rsync_driver(uint *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != (uint *)0x0) && (*param_1 >> 0x10 == 1)) && ((short)*param_1 != 0)) &&
     (((*(long *)(param_1 + 2) != 0 && (*(long *)(param_1 + 4) != 0)) &&
      (*(long *)(param_1 + 6) != 0)))) {
    uVar1 = nv_register_rsync_driver
                      (*(long *)(param_1 + 2),*(long *)(param_1 + 4),*(long *)(param_1 + 6),param_2)
    ;
    return uVar1;
  }
  return 0xffffffea;
}


// ===== 00117300 __pfx_nvidia_p2p_unregister_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvidia_p2p_unregister_rsync_driver(uint *param_1,undefined8 param_2)

{
  code *pcVar1;
  
  if (param_1 == (uint *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if ((*param_1 >> 0x10 == 1) && ((short)*param_1 != 0)) {
    if (((*(long *)(param_1 + 2) != 0) && (*(long *)(param_1 + 4) != 0)) &&
       (*(long *)(param_1 + 6) != 0)) {
      nv_unregister_rsync_driver
                (*(long *)(param_1 + 2),*(long *)(param_1 + 4),*(long *)(param_1 + 6),param_2);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00117310 nvidia_p2p_unregister_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvidia_p2p_unregister_rsync_driver(uint *param_1,undefined8 param_2)

{
  code *pcVar1;
  
  if (param_1 == (uint *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if ((*param_1 >> 0x10 == 1) && ((short)*param_1 != 0)) {
    if (((*(long *)(param_1 + 2) != 0) && (*(long *)(param_1 + 4) != 0)) &&
       (*(long *)(param_1 + 6) != 0)) {
      nv_unregister_rsync_driver
                (*(long *)(param_1 + 2),*(long *)(param_1 + 4),*(long *)(param_1 + 6),param_2);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00117370 __pfx_nvidia_p2p_free_dma_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011738b) */

undefined8 __pfx_nvidia_p2p_free_dma_mapping(void)

{
  return 0;
}


// ===== 00117380 nvidia_p2p_free_dma_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011738b) */

undefined8 nvidia_p2p_free_dma_mapping(void)

{
  return 0;
}


// ===== 00117390 __pfx_nvidia_p2p_put_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117497) */
/* WARNING: Removing unreachable block (ram,0x00117440) */
/* WARNING: Removing unreachable block (ram,0x00117481) */

undefined4
__pfx_nvidia_p2p_put_pages(undefined8 param_1,undefined4 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined4 *puVar5;
  
  if (param_4 == 0) {
    return 0;
  }
  puVar5 = (undefined4 *)0x0;
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 != '\0') {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
  }
  iVar3 = rm_p2p_put_pages(puVar5,param_1,param_2,param_3,param_4);
  if (iVar3 == 0) {
    nv_p2p_free_page_table(param_4);
  }
  else if (iVar3 != 0x57) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if ((puVar5 != (undefined4 *)0x0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar5);
  }
  uVar4 = 0;
  do {
    if ((&nvidia_status_mappings)[uVar4 * 2] == 0) {
      return *(undefined4 *)(&DAT_005a4184 + (uVar4 & 0xffffffff) * 8);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0xb);
  return 0xfffffffb;
}


// ===== 001173a0 nvidia_p2p_put_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117497) */
/* WARNING: Removing unreachable block (ram,0x00117440) */
/* WARNING: Removing unreachable block (ram,0x00117481) */

undefined4
nvidia_p2p_put_pages(undefined8 param_1,undefined4 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined4 *puVar5;
  
  if (param_4 == 0) {
    return 0;
  }
  puVar5 = (undefined4 *)0x0;
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 != '\0') {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
  }
  iVar3 = rm_p2p_put_pages(puVar5,param_1,param_2,param_3,param_4);
  if (iVar3 == 0) {
    nv_p2p_free_page_table(param_4);
  }
  else if (iVar3 != 0x57) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if ((puVar5 != (undefined4 *)0x0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar5);
  }
  uVar4 = 0;
  do {
    if ((&nvidia_status_mappings)[uVar4 * 2] == 0) {
      return *(undefined4 *)(&DAT_005a4184 + (uVar4 & 0xffffffff) * 8);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0xb);
  return 0xfffffffb;
}


// ===== 001174d0 __pfx_nvidia_p2p_put_pages_persistent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001175de) */

undefined4 __pfx_nvidia_p2p_put_pages_persistent(undefined8 param_1,long param_2,int param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  long in_GS_OFFSET;
  undefined8 uStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  if (param_3 == 0) {
    if (param_2 != 0) {
      puVar6 = (undefined4 *)0x0;
      cVar2 = rm_is_altstack_in_use();
      if (cVar2 != '\0') {
        puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar6 == (undefined4 *)0x0) {
          uVar4 = 0xfffffff4;
          goto LAB_001175c7;
        }
        *puVar6 = 0x2ff0;
        *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
      }
      os_mem_copy(&uStack_38,*(undefined8 *)(param_2 + 0x18),0x10);
      iVar3 = rm_p2p_put_pages_persistent
                        (puVar6,*(undefined8 *)(param_2 + 0x50),param_2,
                         *(undefined8 *)(param_2 + 0x58));
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      nv_p2p_free_page_table(param_2);
      nvidia_dev_put_uuid(&uStack_38,puVar6);
      if ((puVar6 != (undefined4 *)0x0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
      }
      uVar5 = 0;
      do {
        if ((&nvidia_status_mappings)[uVar5 * 2] == 0) {
          uVar4 = *(undefined4 *)(&DAT_005a4184 + (uVar5 & 0xffffffff) * 8);
          goto LAB_001175c7;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0xb);
      uVar4 = 0xfffffffb;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
LAB_001175c7:
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 001174e0 nvidia_p2p_put_pages_persistent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001175de) */

undefined4 nvidia_p2p_put_pages_persistent(undefined8 param_1,long param_2,int param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  long in_GS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = 0;
  local_38 = 0;
  local_30 = 0;
  if (param_3 == 0) {
    if (param_2 != 0) {
      puVar6 = (undefined4 *)0x0;
      cVar2 = rm_is_altstack_in_use();
      if (cVar2 != '\0') {
        puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar6 == (undefined4 *)0x0) {
          uVar4 = 0xfffffff4;
          goto LAB_001175c7;
        }
        *puVar6 = 0x2ff0;
        *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
      }
      os_mem_copy(&local_38,*(undefined8 *)(param_2 + 0x18),0x10);
      iVar3 = rm_p2p_put_pages_persistent
                        (puVar6,*(undefined8 *)(param_2 + 0x50),param_2,
                         *(undefined8 *)(param_2 + 0x58));
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      nv_p2p_free_page_table(param_2);
      nvidia_dev_put_uuid(&local_38,puVar6);
      if ((puVar6 != (undefined4 *)0x0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
      }
      uVar5 = 0;
      do {
        if ((&nvidia_status_mappings)[uVar5 * 2] == 0) {
          uVar4 = *(undefined4 *)(&DAT_005a4184 + (uVar5 & 0xffffffff) * 8);
          goto LAB_001175c7;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0xb);
      uVar4 = 0xfffffffb;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
LAB_001175c7:
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00117690 __pfx_nv_p2p_get_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117967) */

undefined4
__pfx_nv_p2p_get_pages
          (int param_1,long param_2,int param_3,undefined8 param_4,ulong param_5,byte param_6,
          long param_7,long param_8)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long in_GS_OFFSET;
  long *unaff_retaddr;
  char cStack_85;
  uint uStack_84;
  long *plStack_80;
  long lStack_78;
  long lStack_70;
  long lStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_84 = 0;
  plStack_80 = (long *)0x0;
  lStack_78 = 0;
  lStack_70 = 0;
  lStack_68 = 0;
  uStack_60 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  cStack_85 = '\0';
  if ((((uint)param_4 | (uint)param_5) & 0xffff) != 0) {
    nv_printf(4,
              "NVRM: Invalid argument in nv_p2p_get_pages,address or length are not aligned address=0x%llx, length=0x%llx\n"
              ,param_4,param_5);
    uVar6 = 0xffffffea;
    goto LAB_0011793d;
  }
  if ((param_7 != 0) && ((param_6 & 1) != 0)) {
    uVar6 = 0xfffffdf4;
    goto LAB_0011793d;
  }
  puVar9 = (undefined4 *)0x0;
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 != '\0') {
    puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar9 == (undefined4 *)0x0) {
      uVar6 = 0xfffffff4;
      goto LAB_0011793d;
    }
    *puVar9 = 0x2ff0;
    *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
  }
  *unaff_retaddr = 0;
  iVar5 = os_alloc_mem(&plStack_80,0x78);
  uVar12 = 0;
  if (iVar5 == 0) {
    plStack_80[0xb] = 0;
    plStack_80[0xc] = 0;
    plStack_80[0xd] = 0;
    plStack_80[0xe] = 0;
    uVar11 = 0;
    do {
      uVar10 = (int)uVar11 + 0x20;
      *(undefined8 *)((long)plStack_80 + uVar11) = 0;
      *(undefined8 *)((long)plStack_80 + uVar11 + 8) = 0;
      *(undefined8 *)((long)plStack_80 + uVar11 + 0x10) = 0;
      *(undefined8 *)((long)plStack_80 + uVar11 + 0x18) = 0;
      uVar11 = (ulong)uVar10;
    } while (uVar10 < 0x60);
    plStack_80[9] = 0x100000000;
    plStack_80[7] = (long)(plStack_80 + 7);
    *(byte *)(plStack_80 + 0xe) = param_6 & 1;
    uVar11 = param_5 >> 0x10 & 0xffffffff;
    plStack_80[8] = (long)(plStack_80 + 7);
    plStack_80[10] = 0;
    plStack_80[0xb] = 0;
    *unaff_retaddr = (long)(plStack_80 + 2);
    iVar5 = os_alloc_mem(&lStack_68,uVar11 * 8);
    if (iVar5 != 0) goto LAB_0011788a;
    lVar13 = uVar11 << 2;
    iVar5 = os_alloc_mem(&lStack_78,lVar13);
    if ((iVar5 != 0) || (iVar5 = os_alloc_mem(&lStack_70,lVar13), iVar5 != 0)) goto LAB_0011788a;
    if (param_1 == 1) {
      uStack_58 = 0;
      if ((param_2 == 0) && (param_3 == 0)) {
        bVar3 = false;
        iVar5 = rm_p2p_get_gpu_info(puVar9,param_4,param_5,&uStack_60,&uStack_58);
        if (iVar5 == 0) {
          iVar5 = 0x12;
          *(undefined8 *)(*unaff_retaddr + 0x18) = uStack_60;
          iVar7 = nvidia_dev_get_uuid(uStack_60,puVar9);
          if (iVar7 == 0) {
            bVar3 = true;
            os_mem_copy(&uStack_50,uStack_60,0x10);
            iVar5 = rm_p2p_get_pages_persistent
                              (puVar9,param_4,param_5,plStack_80 + 0xc,lStack_68,&uStack_84,
                               param_6 & 1,*unaff_retaddr,uStack_58,plStack_80 + 0xd,&cStack_85);
            if (iVar5 == 0) goto LAB_00117ae5;
          }
        }
      }
      else {
        bVar3 = false;
        iVar5 = -0x20c;
      }
      goto LAB_0011788d;
    }
    iVar5 = rm_p2p_get_pages(puVar9,param_2,param_3,param_4,param_5,lStack_68,lStack_78,lStack_70,
                             &uStack_84,&uStack_60,*unaff_retaddr,&cStack_85);
    if (iVar5 != 0) goto LAB_0011788a;
    bVar3 = false;
    *(undefined8 *)(*unaff_retaddr + 0x18) = uStack_60;
LAB_00117ae5:
    iVar5 = os_alloc_mem(*unaff_retaddr + 8,(ulong)uStack_84 << 3);
    if (iVar5 != 0) {
LAB_00117dd8:
      bVar2 = true;
      goto LAB_00117890;
    }
    *(undefined4 *)*unaff_retaddr = 0x20000;
    if (uStack_84 != 0) {
      lVar13 = 0;
      do {
        puVar8 = (undefined8 *)kmem_cache_alloc_noprof(nvidia_p2p_page_t_cache,0xcc0);
        if (puVar8 == (undefined8 *)0x0) {
          bVar2 = true;
          iVar5 = 0x51;
          goto LAB_00117890;
        }
        *puVar8 = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        puVar8[3] = 0;
        *puVar8 = *(undefined8 *)(lStack_68 + lVar13 * 8);
        *(undefined4 *)(puVar8 + 1) = *(undefined4 *)(lStack_78 + lVar13 * 4);
        *(undefined4 *)((long)puVar8 + 0xc) = *(undefined4 *)(lStack_70 + lVar13 * 4);
        *(undefined8 **)(*(long *)(*unaff_retaddr + 8) + lVar13 * 8) = puVar8;
        lVar13 = lVar13 + 1;
        *(int *)(*unaff_retaddr + 0x10) = *(int *)(*unaff_retaddr + 0x10) + 1;
      } while ((uint)lVar13 < uStack_84);
    }
    *(undefined4 *)(*unaff_retaddr + 4) = 1;
    if (cStack_85 != '\0') {
      *(uint *)(*unaff_retaddr + 0x20) = *(uint *)(*unaff_retaddr + 0x20) | 1;
    }
    os_free_mem(lStack_68);
    lStack_68 = 0;
    os_free_mem(lStack_78);
    lStack_78 = 0;
    os_free_mem(lStack_70);
    lStack_70 = 0;
    if (param_7 != 0) {
      *plStack_80 = param_7;
      plStack_80[1] = param_8;
      iVar5 = rm_p2p_register_callback
                        (puVar9,param_2,param_4,param_5,*unaff_retaddr,nv_p2p_mem_info_free_callback
                        );
      if (iVar5 != 0) goto LAB_00117dd8;
    }
    if ((puVar9 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar9);
    }
    do {
      if ((&nvidia_status_mappings)[uVar12 * 2] == 0) goto LAB_00117c7b;
      uVar12 = uVar12 + 1;
    } while (uVar12 != 0xb);
  }
  else {
LAB_0011788a:
    bVar3 = false;
LAB_0011788d:
    bVar2 = false;
LAB_00117890:
    if (lStack_68 != 0) {
      os_free_mem();
    }
    if (lStack_78 != 0) {
      os_free_mem();
    }
    if (lStack_70 != 0) {
      os_free_mem();
    }
    if (bVar2) {
      lVar13 = *unaff_retaddr;
      if (param_1 == 1) {
        iVar7 = rm_p2p_put_pages_persistent
                          (puVar9,*(undefined8 *)(lVar13 + 0x50),lVar13,
                           *(undefined8 *)(lVar13 + 0x58));
        if (iVar7 != 0) {
LAB_00117d23:
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
LAB_00117cfe:
        nv_p2p_free_page_table(*unaff_retaddr);
      }
      else {
        iVar7 = rm_p2p_put_pages(puVar9,param_2,param_3,param_4);
        if (iVar7 == 0) goto LAB_00117cfe;
        if (iVar7 != 0x57) goto LAB_00117d23;
      }
      *unaff_retaddr = 0;
      if (bVar3) goto LAB_001179b3;
    }
    else {
      if (bVar3) {
LAB_001179b3:
        nvidia_dev_put_uuid(&uStack_50,puVar9);
        lVar13 = *unaff_retaddr;
      }
      else {
        lVar13 = *unaff_retaddr;
      }
      if (lVar13 != 0) {
        nv_p2p_free_page_table();
      }
    }
    if ((puVar9 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar9);
    }
    do {
      if (iVar5 == (&nvidia_status_mappings)[uVar12 * 2]) goto LAB_00117c7b;
      uVar12 = uVar12 + 1;
    } while (uVar12 != 0xb);
  }
  uVar6 = 0xfffffffb;
LAB_0011793d:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00117c7b:
  uVar6 = *(undefined4 *)(&DAT_005a4184 + (uVar12 & 0xffffffff) * 8);
  goto LAB_0011793d;
}


// ===== 001176a0 nv_p2p_get_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117967) */

undefined4
nv_p2p_get_pages(int param_1,long param_2,int param_3,undefined8 param_4,ulong param_5,byte param_6,
                long param_7,long param_8)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long in_GS_OFFSET;
  long *unaff_retaddr;
  char local_85;
  uint local_84;
  long *local_80;
  long local_78;
  long local_70;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_84 = 0;
  local_80 = (long *)0x0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_50 = 0;
  local_48 = 0;
  local_85 = '\0';
  if ((((uint)param_4 | (uint)param_5) & 0xffff) != 0) {
    nv_printf(4,
              "NVRM: Invalid argument in nv_p2p_get_pages,address or length are not aligned address=0x%llx, length=0x%llx\n"
              ,param_4,param_5);
    uVar6 = 0xffffffea;
    goto LAB_0011793d;
  }
  if ((param_7 != 0) && ((param_6 & 1) != 0)) {
    uVar6 = 0xfffffdf4;
    goto LAB_0011793d;
  }
  puVar9 = (undefined4 *)0x0;
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 != '\0') {
    puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar9 == (undefined4 *)0x0) {
      uVar6 = 0xfffffff4;
      goto LAB_0011793d;
    }
    *puVar9 = 0x2ff0;
    *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
  }
  *unaff_retaddr = 0;
  iVar5 = os_alloc_mem(&local_80,0x78);
  uVar12 = 0;
  if (iVar5 == 0) {
    local_80[0xb] = 0;
    local_80[0xc] = 0;
    local_80[0xd] = 0;
    local_80[0xe] = 0;
    uVar11 = 0;
    do {
      uVar10 = (int)uVar11 + 0x20;
      *(undefined8 *)((long)local_80 + uVar11) = 0;
      *(undefined8 *)((long)local_80 + uVar11 + 8) = 0;
      *(undefined8 *)((long)local_80 + uVar11 + 0x10) = 0;
      *(undefined8 *)((long)local_80 + uVar11 + 0x18) = 0;
      uVar11 = (ulong)uVar10;
    } while (uVar10 < 0x60);
    local_80[9] = 0x100000000;
    local_80[7] = (long)(local_80 + 7);
    *(byte *)(local_80 + 0xe) = param_6 & 1;
    uVar11 = param_5 >> 0x10 & 0xffffffff;
    local_80[8] = (long)(local_80 + 7);
    local_80[10] = 0;
    local_80[0xb] = 0;
    *unaff_retaddr = (long)(local_80 + 2);
    iVar5 = os_alloc_mem(&local_68,uVar11 * 8);
    if (iVar5 != 0) goto LAB_0011788a;
    lVar13 = uVar11 << 2;
    iVar5 = os_alloc_mem(&local_78,lVar13);
    if ((iVar5 != 0) || (iVar5 = os_alloc_mem(&local_70,lVar13), iVar5 != 0)) goto LAB_0011788a;
    if (param_1 == 1) {
      local_58 = 0;
      if ((param_2 == 0) && (param_3 == 0)) {
        bVar3 = false;
        iVar5 = rm_p2p_get_gpu_info(puVar9,param_4,param_5,&local_60,&local_58);
        if (iVar5 == 0) {
          iVar5 = 0x12;
          *(undefined8 *)(*unaff_retaddr + 0x18) = local_60;
          iVar7 = nvidia_dev_get_uuid(local_60,puVar9);
          if (iVar7 == 0) {
            bVar3 = true;
            os_mem_copy(&local_50,local_60,0x10);
            iVar5 = rm_p2p_get_pages_persistent
                              (puVar9,param_4,param_5,local_80 + 0xc,local_68,&local_84,param_6 & 1,
                               *unaff_retaddr,local_58,local_80 + 0xd,&local_85);
            if (iVar5 == 0) goto LAB_00117ae5;
          }
        }
      }
      else {
        bVar3 = false;
        iVar5 = -0x20c;
      }
      goto LAB_0011788d;
    }
    iVar5 = rm_p2p_get_pages(puVar9,param_2,param_3,param_4,param_5,local_68,local_78,local_70,
                             &local_84,&local_60,*unaff_retaddr,&local_85);
    if (iVar5 != 0) goto LAB_0011788a;
    bVar3 = false;
    *(undefined8 *)(*unaff_retaddr + 0x18) = local_60;
LAB_00117ae5:
    iVar5 = os_alloc_mem(*unaff_retaddr + 8,(ulong)local_84 << 3);
    if (iVar5 != 0) {
LAB_00117dd8:
      bVar2 = true;
      goto LAB_00117890;
    }
    *(undefined4 *)*unaff_retaddr = 0x20000;
    if (local_84 != 0) {
      lVar13 = 0;
      do {
        puVar8 = (undefined8 *)kmem_cache_alloc_noprof(nvidia_p2p_page_t_cache,0xcc0);
        if (puVar8 == (undefined8 *)0x0) {
          bVar2 = true;
          iVar5 = 0x51;
          goto LAB_00117890;
        }
        *puVar8 = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        puVar8[3] = 0;
        *puVar8 = *(undefined8 *)(local_68 + lVar13 * 8);
        *(undefined4 *)(puVar8 + 1) = *(undefined4 *)(local_78 + lVar13 * 4);
        *(undefined4 *)((long)puVar8 + 0xc) = *(undefined4 *)(local_70 + lVar13 * 4);
        *(undefined8 **)(*(long *)(*unaff_retaddr + 8) + lVar13 * 8) = puVar8;
        lVar13 = lVar13 + 1;
        *(int *)(*unaff_retaddr + 0x10) = *(int *)(*unaff_retaddr + 0x10) + 1;
      } while ((uint)lVar13 < local_84);
    }
    *(undefined4 *)(*unaff_retaddr + 4) = 1;
    if (local_85 != '\0') {
      *(uint *)(*unaff_retaddr + 0x20) = *(uint *)(*unaff_retaddr + 0x20) | 1;
    }
    os_free_mem(local_68);
    local_68 = 0;
    os_free_mem(local_78);
    local_78 = 0;
    os_free_mem(local_70);
    local_70 = 0;
    if (param_7 != 0) {
      *local_80 = param_7;
      local_80[1] = param_8;
      iVar5 = rm_p2p_register_callback
                        (puVar9,param_2,param_4,param_5,*unaff_retaddr,nv_p2p_mem_info_free_callback
                        );
      if (iVar5 != 0) goto LAB_00117dd8;
    }
    if ((puVar9 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar9);
    }
    do {
      if ((&nvidia_status_mappings)[uVar12 * 2] == 0) goto LAB_00117c7b;
      uVar12 = uVar12 + 1;
    } while (uVar12 != 0xb);
  }
  else {
LAB_0011788a:
    bVar3 = false;
LAB_0011788d:
    bVar2 = false;
LAB_00117890:
    if (local_68 != 0) {
      os_free_mem();
    }
    if (local_78 != 0) {
      os_free_mem();
    }
    if (local_70 != 0) {
      os_free_mem();
    }
    if (bVar2) {
      lVar13 = *unaff_retaddr;
      if (param_1 == 1) {
        iVar7 = rm_p2p_put_pages_persistent
                          (puVar9,*(undefined8 *)(lVar13 + 0x50),lVar13,
                           *(undefined8 *)(lVar13 + 0x58));
        if (iVar7 != 0) {
LAB_00117d23:
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
LAB_00117cfe:
        nv_p2p_free_page_table(*unaff_retaddr);
      }
      else {
        iVar7 = rm_p2p_put_pages(puVar9,param_2,param_3,param_4);
        if (iVar7 == 0) goto LAB_00117cfe;
        if (iVar7 != 0x57) goto LAB_00117d23;
      }
      *unaff_retaddr = 0;
      if (bVar3) goto LAB_001179b3;
    }
    else {
      if (bVar3) {
LAB_001179b3:
        nvidia_dev_put_uuid(&local_50,puVar9);
        lVar13 = *unaff_retaddr;
      }
      else {
        lVar13 = *unaff_retaddr;
      }
      if (lVar13 != 0) {
        nv_p2p_free_page_table();
      }
    }
    if ((puVar9 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar9);
    }
    do {
      if (iVar5 == (&nvidia_status_mappings)[uVar12 * 2]) goto LAB_00117c7b;
      uVar12 = uVar12 + 1;
    } while (uVar12 != 0xb);
  }
  uVar6 = 0xfffffffb;
LAB_0011793d:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00117c7b:
  uVar6 = *(undefined4 *)(&DAT_005a4184 + (uVar12 & 0xffffffff) * 8);
  goto LAB_0011793d;
}


// ===== 00117e50 __pfx_nvidia_p2p_get_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117e91) */
/* WARNING: Removing unreachable block (ram,0x00117e9b) */

undefined8
__pfx_nvidia_p2p_get_pages
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,long param_6)

{
  undefined8 uVar1;
  
  if (param_6 != 0) {
    uVar1 = nv_p2p_get_pages(0,param_1,param_2,param_3,param_4,0,param_5,param_6);
    return uVar1;
  }
  return 0xffffffea;
}


// ===== 00117e60 nvidia_p2p_get_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117e91) */
/* WARNING: Removing unreachable block (ram,0x00117e9b) */

undefined8
nvidia_p2p_get_pages
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,long param_6)

{
  undefined8 uVar1;
  
  if (param_6 != 0) {
    uVar1 = nv_p2p_get_pages(0,param_1,param_2,param_3,param_4,0,param_5,param_6);
    return uVar1;
  }
  return 0xffffffea;
}


// ===== 00117ea0 __pfx_nvidia_p2p_get_pages_persistent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117eda) */

void __pfx_nvidia_p2p_get_pages_persistent
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  nv_p2p_get_pages(1,0,0,param_1,param_2,param_4,param_3,0,0,0x117eb9);
  return;
}


// ===== 00117eb0 nvidia_p2p_get_pages_persistent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00117eda) */

void nvidia_p2p_get_pages_persistent
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  nv_p2p_get_pages(1,0,0,param_1,param_2,param_4,param_3,0,0,0x117eb9);
  return;
}


// ===== 00117ee0 __pfx_nvidia_p2p_dma_map_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011813f) */

undefined4 __pfx_nvidia_p2p_dma_map_pages(long param_1,long param_2,long *param_3)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  long *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  undefined4 *puVar12;
  long in_GS_OFFSET;
  long lStack_88;
  undefined8 uStack_80;
  long *plStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long lStack_60;
  long lStack_58;
  
  lStack_58 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_70 = 0;
  uStack_68 = 0;
  lStack_60 = 0;
  lStack_88 = 0;
  uStack_80 = 0;
  if (((param_2 == 0 || param_3 == (long *)0x0) || (param_1 == 0)) ||
     (*(long *)(param_2 + 0x18) == 0)) {
    uVar9 = 0xffffffea;
    goto LAB_00118119;
  }
  if (*(char *)(param_2 + 0x60) != '\0') {
    uVar9 = 0xfffffdf4;
    goto LAB_00118119;
  }
  cVar7 = rm_is_altstack_in_use();
  puVar12 = (undefined4 *)0x0;
  if (cVar7 != '\0') {
    puVar12 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar12 == (undefined4 *)0x0) {
      uVar9 = 0xfffffff4;
      goto LAB_00118119;
    }
    *puVar12 = 0x2ff0;
    *(undefined4 **)(puVar12 + 2) = puVar12 + 0xc00;
  }
  *param_3 = 0;
  iVar8 = os_alloc_mem(param_3,0x28);
  if (iVar8 == 0) {
    puVar4 = (undefined8 *)*param_3;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    uVar2 = *(uint *)(param_2 + 0x10);
    iVar8 = os_alloc_mem(&lStack_88,(ulong)uVar2 << 3);
    if (iVar8 != 0) goto LAB_001180aa;
    uVar3 = *(uint *)(param_2 + 4);
    if (1 < uVar3 - 1) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)invalidInstructionException();
      (*pcVar6)();
    }
    lStack_60 = param_1 + 0xd0;
    uStack_68 = *(undefined8 *)(param_1 + 0x88);
    uVar9 = *(undefined4 *)(nvidia_p2p_page_size_mappings + (ulong)uVar3 * 4);
    if (uVar2 != 0) {
      lVar10 = 0;
      do {
        *(undefined8 *)(lStack_88 + lVar10) = **(undefined8 **)(*(long *)(param_2 + 8) + lVar10);
        lVar10 = lVar10 + 8;
      } while ((ulong)uVar2 << 3 != lVar10);
    }
    iVar8 = rm_p2p_dma_map_pages
                      (puVar12,&uStack_70,*(undefined8 *)(param_2 + 0x18),uVar9,uVar2,lStack_88,
                       &uStack_80);
    if (iVar8 != 0) goto LAB_001180aa;
    *(undefined4 *)*param_3 = 0x20003;
    *(uint *)(*param_3 + 4) = uVar3;
    *(uint *)(*param_3 + 8) = uVar2;
    *(long *)(*param_3 + 0x10) = lStack_88;
    *(undefined8 *)(*param_3 + 0x18) = uStack_80;
    *(long *)(*param_3 + 0x20) = param_1;
    lVar10 = *param_3;
    plStack_78 = (long *)0x0;
    iVar8 = os_alloc_mem(&plStack_78,0x18);
    if (iVar8 == 0) {
      down(param_2 + 0x38);
      plVar1 = (long *)(param_2 + 0x28);
      plStack_78[2] = lVar10;
      plVar5 = *(long **)(param_2 + 0x30);
      if (((plVar1 == (long *)*plVar5) && (plStack_78 != plVar5)) && (plVar1 != plStack_78)) {
        *(long **)(param_2 + 0x30) = plStack_78;
        *plStack_78 = (long)plVar1;
        plStack_78[1] = (long)plVar5;
        *plVar5 = (long)plStack_78;
      }
      else {
        __list_add_valid_or_report();
      }
      up(param_2 + 0x38);
      if (puVar12 != (undefined4 *)0x0) {
        cVar7 = rm_is_altstack_in_use();
        if (cVar7 != '\0') {
          kmem_cache_free(nvidia_stack_t_cache,puVar12);
          uVar9 = 0;
          goto LAB_00118119;
        }
      }
      uVar9 = 0;
      goto LAB_00118119;
    }
    nv_p2p_free_dma_mapping(*param_3);
    lStack_88 = 0;
    *param_3 = 0;
  }
  else {
LAB_001180aa:
    if (lStack_88 != 0) {
      os_free_mem();
    }
    if (*param_3 != 0) {
      os_free_mem();
      *param_3 = 0;
    }
  }
  if (puVar12 != (undefined4 *)0x0) {
    cVar7 = rm_is_altstack_in_use();
    if (cVar7 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar12);
    }
  }
  uVar11 = 0;
  do {
    if ((&nvidia_status_mappings)[uVar11 * 2] == iVar8) {
      uVar9 = *(undefined4 *)(&DAT_005a4184 + (uVar11 & 0xffffffff) * 8);
      goto LAB_00118119;
    }
    uVar11 = uVar11 + 1;
  } while (uVar11 != 0xb);
  uVar9 = 0xfffffffb;
LAB_00118119:
  if (lStack_58 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00117ef0 nvidia_p2p_dma_map_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011813f) */

undefined4 nvidia_p2p_dma_map_pages(long param_1,long param_2,long *param_3)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  long *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  undefined4 *puVar12;
  long in_GS_OFFSET;
  long local_88;
  undefined8 local_80;
  long *local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  long local_58;
  
  local_58 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_88 = 0;
  local_80 = 0;
  if (((param_2 == 0 || param_3 == (long *)0x0) || (param_1 == 0)) ||
     (*(long *)(param_2 + 0x18) == 0)) {
    uVar9 = 0xffffffea;
    goto LAB_00118119;
  }
  if (*(char *)(param_2 + 0x60) != '\0') {
    uVar9 = 0xfffffdf4;
    goto LAB_00118119;
  }
  cVar7 = rm_is_altstack_in_use();
  puVar12 = (undefined4 *)0x0;
  if (cVar7 != '\0') {
    puVar12 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar12 == (undefined4 *)0x0) {
      uVar9 = 0xfffffff4;
      goto LAB_00118119;
    }
    *puVar12 = 0x2ff0;
    *(undefined4 **)(puVar12 + 2) = puVar12 + 0xc00;
  }
  *param_3 = 0;
  iVar8 = os_alloc_mem(param_3,0x28);
  if (iVar8 == 0) {
    puVar4 = (undefined8 *)*param_3;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    uVar2 = *(uint *)(param_2 + 0x10);
    iVar8 = os_alloc_mem(&local_88,(ulong)uVar2 << 3);
    if (iVar8 != 0) goto LAB_001180aa;
    uVar3 = *(uint *)(param_2 + 4);
    if (1 < uVar3 - 1) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)invalidInstructionException();
      (*pcVar6)();
    }
    local_60 = param_1 + 0xd0;
    local_68 = *(undefined8 *)(param_1 + 0x88);
    uVar9 = *(undefined4 *)(nvidia_p2p_page_size_mappings + (ulong)uVar3 * 4);
    if (uVar2 != 0) {
      lVar10 = 0;
      do {
        *(undefined8 *)(local_88 + lVar10) = **(undefined8 **)(*(long *)(param_2 + 8) + lVar10);
        lVar10 = lVar10 + 8;
      } while ((ulong)uVar2 << 3 != lVar10);
    }
    iVar8 = rm_p2p_dma_map_pages
                      (puVar12,&local_70,*(undefined8 *)(param_2 + 0x18),uVar9,uVar2,local_88,
                       &local_80);
    if (iVar8 != 0) goto LAB_001180aa;
    *(undefined4 *)*param_3 = 0x20003;
    *(uint *)(*param_3 + 4) = uVar3;
    *(uint *)(*param_3 + 8) = uVar2;
    *(long *)(*param_3 + 0x10) = local_88;
    *(undefined8 *)(*param_3 + 0x18) = local_80;
    *(long *)(*param_3 + 0x20) = param_1;
    lVar10 = *param_3;
    local_78 = (long *)0x0;
    iVar8 = os_alloc_mem(&local_78,0x18);
    if (iVar8 == 0) {
      down(param_2 + 0x38);
      plVar1 = (long *)(param_2 + 0x28);
      local_78[2] = lVar10;
      plVar5 = *(long **)(param_2 + 0x30);
      if (((plVar1 == (long *)*plVar5) && (local_78 != plVar5)) && (plVar1 != local_78)) {
        *(long **)(param_2 + 0x30) = local_78;
        *local_78 = (long)plVar1;
        local_78[1] = (long)plVar5;
        *plVar5 = (long)local_78;
      }
      else {
        __list_add_valid_or_report();
      }
      up(param_2 + 0x38);
      if (puVar12 != (undefined4 *)0x0) {
        cVar7 = rm_is_altstack_in_use();
        if (cVar7 != '\0') {
          kmem_cache_free(nvidia_stack_t_cache,puVar12);
          uVar9 = 0;
          goto LAB_00118119;
        }
      }
      uVar9 = 0;
      goto LAB_00118119;
    }
    nv_p2p_free_dma_mapping(*param_3);
    local_88 = 0;
    *param_3 = 0;
  }
  else {
LAB_001180aa:
    if (local_88 != 0) {
      os_free_mem();
    }
    if (*param_3 != 0) {
      os_free_mem();
      *param_3 = 0;
    }
  }
  if (puVar12 != (undefined4 *)0x0) {
    cVar7 = rm_is_altstack_in_use();
    if (cVar7 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar12);
    }
  }
  uVar11 = 0;
  do {
    if ((&nvidia_status_mappings)[uVar11 * 2] == iVar8) {
      uVar9 = *(undefined4 *)(&DAT_005a4184 + (uVar11 & 0xffffffff) * 8);
      goto LAB_00118119;
    }
    uVar11 = uVar11 + 1;
  } while (uVar11 != 0xb);
  uVar9 = 0xfffffffb;
LAB_00118119:
  if (local_58 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001182b0 __pfx_nv_p2p_free_platform_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_p2p_free_platform_data(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    nv_p2p_free_page_table();
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001182c0 nv_p2p_free_platform_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_p2p_free_platform_data(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    nv_p2p_free_page_table();
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001182e0 __pfx_nv_determine_pat_mode =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118399) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_determine_pat_mode(void)

{
  undefined8 uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1182f5;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((_vmemmap_base & 0x10000) == 0) {
    if ((DAT_00f79092 == '\0') && (0 < _register_chrdev_region)) {
      uStack_1c = 0;
      uStack_14 = 0;
      uStack_20 = 1;
      uStack_18 = 0;
      (*_wait_for_completion)(&uStack_20,&uStack_1c,&uStack_18,&uStack_14);
      if (((uStack_14 & 0x10000) != 0) && ((DAT_00f79091 == '\x06' && (boot_cpu_data < 0xf))))
      goto LAB_001183a7;
    }
    nv_printf(4,"NVRM: CPU does not support the PAT.\n");
  }
  else {
LAB_001183a7:
    uVar1 = (*_trace_event_printf)(0x277);
    iVar4 = 0;
    do {
      bVar2 = (char)iVar4 * '\b';
      uVar3 = 0xff << (bVar2 & 0x1f);
      if ((uVar3 & (uint)uVar1) >> (bVar2 & 0x1f) == 1) {
        uVar1 = 1;
        if (iVar4 == 1) goto LAB_00118386;
LAB_001183f5:
        nv_printf(4,"NVRM: PAT configuration unsupported.\n");
        break;
      }
      if ((uVar3 & (uint)((ulong)uVar1 >> 0x20)) >> (bVar2 & 0x1f) == 1) goto LAB_001183f5;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 4);
  }
  uVar1 = 0;
LAB_00118386:
  if (lStack_10 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}


// ===== 001182f0 nv_determine_pat_mode =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118399) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_determine_pat_mode(void)

{
  undefined8 uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1182f5;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((_vmemmap_base & 0x10000) == 0) {
    if ((DAT_00f79092 == '\0') && (0 < _register_chrdev_region)) {
      local_1c = 0;
      local_14 = 0;
      local_20 = 1;
      local_18 = 0;
      (*_wait_for_completion)(&local_20,&local_1c,&local_18,&local_14);
      if (((local_14 & 0x10000) != 0) && ((DAT_00f79091 == '\x06' && (boot_cpu_data < 0xf))))
      goto LAB_001183a7;
    }
    nv_printf(4,"NVRM: CPU does not support the PAT.\n");
  }
  else {
LAB_001183a7:
    uVar1 = (*_trace_event_printf)(0x277);
    iVar4 = 0;
    do {
      bVar2 = (char)iVar4 * '\b';
      uVar3 = 0xff << (bVar2 & 0x1f);
      if ((uVar3 & (uint)uVar1) >> (bVar2 & 0x1f) == 1) {
        uVar1 = 1;
        if (iVar4 == 1) goto LAB_00118386;
LAB_001183f5:
        nv_printf(4,"NVRM: PAT configuration unsupported.\n");
        break;
      }
      if ((uVar3 & (uint)((ulong)uVar1 >> 0x20)) >> (bVar2 & 0x1f) == 1) goto LAB_001183f5;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 4);
  }
  uVar1 = 0;
LAB_00118386:
  if (local_10 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}


// ===== 00118410 __pfx_nv_enable_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118438) */
/* WARNING: Removing unreachable block (ram,0x00118448) */

undefined8 __pfx_nv_enable_pat_support(void)

{
  undefined8 uVar1;
  
  if (nv_pat_mode != 0) {
    return 1;
  }
  uVar1 = nv_determine_pat_mode();
  nv_pat_mode = (int)uVar1;
  return uVar1;
}


// ===== 00118420 nv_enable_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118438) */
/* WARNING: Removing unreachable block (ram,0x00118448) */

undefined8 nv_enable_pat_support(void)

{
  undefined8 uVar1;
  
  if (nv_pat_mode != 0) {
    return 1;
  }
  uVar1 = nv_determine_pat_mode();
  nv_pat_mode = (int)uVar1;
  return uVar1;
}


// ===== 00118450 __pfx_nv_disable_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118469) */

void __pfx_nv_disable_pat_support(void)

{
  return;
}


// ===== 00118460 nv_disable_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118469) */

void nv_disable_pat_support(void)

{
  return;
}


// ===== 00118470 __pfx_nv_init_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001184ea) */

undefined8 __pfx_nv_init_pat_support(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  int iStack_14;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x118489;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_14 = 0;
  iVar1 = rm_read_registry_dword(param_1,0,"UsePageAttributeTable",&iStack_14);
  if (iVar1 == 0 && iStack_14 == 0) {
    nv_printf(4,"NVRM: builtin PAT support disabled.\n");
    uVar2 = 0;
  }
  else if (nv_pat_mode == 0) {
    nv_pat_mode = nv_determine_pat_mode();
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (nv_pat_mode == 2) {
      uVar2 = 0xfffffffb;
    }
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00118480 nv_init_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001184ea) */

undefined8 nv_init_pat_support(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  int local_14;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x118489;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_14 = 0;
  iVar1 = rm_read_registry_dword(param_1,0,"UsePageAttributeTable",&local_14);
  if (iVar1 == 0 && local_14 == 0) {
    nv_printf(4,"NVRM: builtin PAT support disabled.\n");
    uVar2 = 0;
  }
  else if (nv_pat_mode == 0) {
    nv_pat_mode = nv_determine_pat_mode();
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (nv_pat_mode == 2) {
      uVar2 = 0xfffffffb;
    }
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00118520 __pfx_nv_teardown_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118539) */

void __pfx_nv_teardown_pat_support(void)

{
  return;
}


// ===== 00118530 nv_teardown_pat_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118539) */

void nv_teardown_pat_support(void)

{
  return;
}


// ===== 00118540 __pfx_nv_procfs_release_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_gpu_info(void)

{
  single_release();
  return;
}


// ===== 00118550 nv_procfs_release_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_gpu_info(void)

{
  single_release();
  return;
}


// ===== 00118560 __pfx_nv_procfs_open_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_text_file(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_text_file,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00118570 nv_procfs_open_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_text_file(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_text_file,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001185a0 __pfx_nv_procfs_open_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_version(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_version,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001185b0 nv_procfs_open_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_version(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_version,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001185e0 __pfx_nv_procfs_open_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_suspend(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_show_suspend,0);
  return;
}


// ===== 001185f0 nv_procfs_open_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_suspend(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_show_suspend,0);
  return;
}


// ===== 00118610 __pfx_nv_procfs_open_suspend_depth =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_suspend_depth(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_show_suspend_depth,0);
  return;
}


// ===== 00118620 nv_procfs_open_suspend_depth =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_suspend_depth(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_show_suspend_depth,0);
  return;
}


// ===== 00118640 __pfx_nv_procfs_open_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_params(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_params,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00118650 nv_procfs_open_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_params(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_params,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00118680 __pfx_nv_procfs_open_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_power(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_power,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00118690 nv_procfs_open_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_power(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_power,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001186c0 __pfx_nv_procfs_open_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_gpu_info(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_gpu_info,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001186d0 nv_procfs_open_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_gpu_info(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_gpu_info,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00118700 __pfx_nv_procfs_read_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118724) */

undefined8 __pfx_nv_procfs_read_text_file(long param_1)

{
  __seq_puts(param_1,*(undefined8 *)(param_1 + 0x68));
  return 0;
}


// ===== 00118710 nv_procfs_read_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118724) */

undefined8 nv_procfs_read_text_file(long param_1)

{
  __seq_puts(param_1,*(undefined8 *)(param_1 + 0x68));
  return 0;
}


// ===== 00118730 __pfx_nv_procfs_read_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118781) */

undefined8 __pfx_nv_procfs_read_version(undefined8 param_1)

{
  seq_printf(param_1,"NVRM version: %s\n",pNVRM_ID);
  seq_printf(param_1,"GCC version:  %s\n","gcc version 16.2.1 20260810 (GCC) ");
  return 0;
}


// ===== 00118740 nv_procfs_read_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118781) */

undefined8 nv_procfs_read_version(undefined8 param_1)

{
  seq_printf(param_1,"NVRM version: %s\n",pNVRM_ID);
  seq_printf(param_1,"GCC version:  %s\n","gcc version 16.2.1 20260810 (GCC) ");
  return 0;
}


// ===== 00118790 __pfx_nv_procfs_show_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001187b7) */

undefined8 __pfx_nv_procfs_show_suspend(undefined8 param_1)

{
  seq_printf(param_1,"suspend hibernate resume\n");
  return 0;
}


// ===== 001187a0 nv_procfs_show_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001187b7) */

undefined8 nv_procfs_show_suspend(undefined8 param_1)

{
  seq_printf(param_1,"suspend hibernate resume\n");
  return 0;
}


// ===== 001187c0 __pfx_nv_procfs_show_suspend_depth =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001187e7) */

undefined8 __pfx_nv_procfs_show_suspend_depth(undefined8 param_1)

{
  seq_printf(param_1,"default modeset uvm\n");
  return 0;
}


// ===== 001187d0 nv_procfs_show_suspend_depth =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001187e7) */

undefined8 nv_procfs_show_suspend_depth(undefined8 param_1)

{
  seq_printf(param_1,"default modeset uvm\n");
  return 0;
}


// ===== 001187f0 __pfx_nv_procfs_read_registry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118834) */
/* WARNING: Removing unreachable block (ram,0x0011884e) */

undefined8 __pfx_nv_procfs_read_registry(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x68) + 0x20);
  if ((lVar1 != 0) && (lVar1 = *(long *)(lVar1 + 8), lVar1 != 0)) {
    seq_printf(param_1,"Binary: \"%s\"\n",lVar1 + 0x4d8);
    return 0;
  }
  seq_printf(param_1,"Binary: \"%s\"\n",nv_registry_keys);
  return 0;
}


// ===== 00118800 nv_procfs_read_registry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118834) */
/* WARNING: Removing unreachable block (ram,0x0011884e) */

undefined8 nv_procfs_read_registry(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x68) + 0x20);
  if ((lVar1 != 0) && (lVar1 = *(long *)(lVar1 + 8), lVar1 != 0)) {
    seq_printf(param_1,"Binary: \"%s\"\n",lVar1 + 0x4d8);
    return 0;
  }
  seq_printf(param_1,"Binary: \"%s\"\n",nv_registry_keys);
  return 0;
}


// ===== 00118860 __pfx_nv_procfs_read_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118999) */

undefined8 __pfx_nv_procfs_read_params(undefined8 param_1)

{
  ulong uVar1;
  undefined *puVar2;
  
  if (nv_parms != (undefined *)0x0) {
    uVar1 = 0;
    puVar2 = nv_parms;
    do {
      seq_printf(param_1,"%s: %u\n",puVar2,
                 *(undefined4 *)(&PTR_NVreg_ResmanDebugLevel_005702e8)[uVar1 * 2]);
      uVar1 = (ulong)((int)uVar1 + 1);
      puVar2 = (&nv_parms)[uVar1 * 2];
    } while (puVar2 != (undefined *)0x0);
  }
  puVar2 = NVreg_CoherentGPUMemoryMode;
  if (NVreg_CoherentGPUMemoryMode == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"CoherentGPUMemoryMode: \"%s\"\n",puVar2);
  puVar2 = NVreg_RegistryDwords;
  if (NVreg_RegistryDwords == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"RegistryDwords: \"%s\"\n",puVar2);
  puVar2 = NVreg_RegistryDwordsPerDevice;
  if (NVreg_RegistryDwordsPerDevice == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"RegistryDwordsPerDevice: \"%s\"\n",puVar2);
  puVar2 = NVreg_RmMsg;
  if (NVreg_RmMsg == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"RmMsg: \"%s\"\n",puVar2);
  puVar2 = NVreg_GpuBlacklist;
  if (NVreg_GpuBlacklist == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"GpuBlacklist: \"%s\"\n",puVar2);
  puVar2 = NVreg_TemporaryFilePath;
  if (NVreg_TemporaryFilePath == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"TemporaryFilePath: \"%s\"\n",puVar2);
  puVar2 = NVreg_ExcludedGpus;
  if (NVreg_ExcludedGpus == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"ExcludedGpus: \"%s\"\n",puVar2);
  return 0;
}


// ===== 00118870 nv_procfs_read_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118999) */

undefined8 nv_procfs_read_params(undefined8 param_1)

{
  ulong uVar1;
  undefined *puVar2;
  
  if (nv_parms != (undefined *)0x0) {
    uVar1 = 0;
    puVar2 = nv_parms;
    do {
      seq_printf(param_1,"%s: %u\n",puVar2,
                 *(undefined4 *)(&PTR_NVreg_ResmanDebugLevel_005702e8)[uVar1 * 2]);
      uVar1 = (ulong)((int)uVar1 + 1);
      puVar2 = (&nv_parms)[uVar1 * 2];
    } while (puVar2 != (undefined *)0x0);
  }
  puVar2 = NVreg_CoherentGPUMemoryMode;
  if (NVreg_CoherentGPUMemoryMode == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"CoherentGPUMemoryMode: \"%s\"\n",puVar2);
  puVar2 = NVreg_RegistryDwords;
  if (NVreg_RegistryDwords == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"RegistryDwords: \"%s\"\n",puVar2);
  puVar2 = NVreg_RegistryDwordsPerDevice;
  if (NVreg_RegistryDwordsPerDevice == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"RegistryDwordsPerDevice: \"%s\"\n",puVar2);
  puVar2 = NVreg_RmMsg;
  if (NVreg_RmMsg == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"RmMsg: \"%s\"\n",puVar2);
  puVar2 = NVreg_GpuBlacklist;
  if (NVreg_GpuBlacklist == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"GpuBlacklist: \"%s\"\n",puVar2);
  puVar2 = NVreg_TemporaryFilePath;
  if (NVreg_TemporaryFilePath == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"TemporaryFilePath: \"%s\"\n",puVar2);
  puVar2 = NVreg_ExcludedGpus;
  if (NVreg_ExcludedGpus == (undefined *)0x0) {
    puVar2 = &DAT_00daf2fe;
  }
  seq_printf(param_1,"ExcludedGpus: \"%s\"\n",puVar2);
  return 0;
}


// ===== 001189a0 __pfx_nv_procfs_write_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118ae2) */

ulong __pfx_nv_procfs_write_suspend(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  byte *pbVar6;
  undefined8 uVar7;
  long in_GS_OFFSET;
  byte abStack_33 [11];
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  abStack_33[0] = 0;
  abStack_33[1] = 0;
  abStack_33[2] = 0;
  abStack_33[3] = 0;
  abStack_33[4] = 0;
  abStack_33[5] = 0;
  abStack_33[6] = 0;
  abStack_33[7] = 0;
  abStack_33[8] = 0;
  abStack_33[9] = 0;
  abStack_33[10] = 0;
  cVar1 = capable(0x15);
  if (cVar1 == '\0') {
    uVar5 = 0xffffffffffffffff;
    goto LAB_00118ac5;
  }
  if (param_3 - 6 < 6) {
    __check_object_size(abStack_33,param_3,0);
    lVar4 = _copy_from_user(abStack_33,param_2,param_3);
    if (lVar4 != 0) {
      uVar5 = 0xfffffffffffffff2;
      goto LAB_00118ac5;
    }
    if (10 < param_3) {
      param_3 = 10;
    }
    uVar2 = 0;
    uVar5 = param_3 & 0xffffffff;
    pbVar6 = abStack_33;
    do {
      if (((&_ctype)[*pbVar6] & 3) == 0) {
        uVar5 = (ulong)uVar2;
        break;
      }
      uVar2 = uVar2 + 1;
      pbVar6 = pbVar6 + 1;
    } while (uVar2 != (uint)param_3);
    abStack_33[uVar5] = 0;
    iVar3 = strcasecmp((char *)abStack_33,"suspend");
    if (iVar3 == 0) {
      uVar7 = 1;
    }
    else {
      iVar3 = strcasecmp((char *)abStack_33,"hibernate");
      uVar7 = 0;
      if (iVar3 != 0) {
        iVar3 = strcasecmp((char *)abStack_33,"resume");
        if (iVar3 != 0) goto LAB_00118b1e;
        uVar7 = 2;
      }
    }
    iVar3 = nv_set_system_power_state(uVar7,nv_procfs_pm_action_depth);
    uVar5 = 0xfffffffffffffffb;
    if (iVar3 == 0) {
      uVar5 = param_3;
    }
  }
  else {
LAB_00118b1e:
    uVar5 = 0xffffffffffffffea;
  }
LAB_00118ac5:
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 001189b0 nv_procfs_write_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118ae2) */

ulong nv_procfs_write_suspend(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  byte *pbVar6;
  undefined8 uVar7;
  long in_GS_OFFSET;
  byte local_33 [11];
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_33[0] = 0;
  local_33[1] = 0;
  local_33[2] = 0;
  local_33[3] = 0;
  local_33[4] = 0;
  local_33[5] = 0;
  local_33[6] = 0;
  local_33[7] = 0;
  local_33[8] = 0;
  local_33[9] = 0;
  local_33[10] = 0;
  cVar1 = capable(0x15);
  if (cVar1 == '\0') {
    uVar5 = 0xffffffffffffffff;
    goto LAB_00118ac5;
  }
  if (param_3 - 6 < 6) {
    __check_object_size(local_33,param_3,0);
    lVar4 = _copy_from_user(local_33,param_2,param_3);
    if (lVar4 != 0) {
      uVar5 = 0xfffffffffffffff2;
      goto LAB_00118ac5;
    }
    if (10 < param_3) {
      param_3 = 10;
    }
    uVar2 = 0;
    uVar5 = param_3 & 0xffffffff;
    pbVar6 = local_33;
    do {
      if (((&_ctype)[*pbVar6] & 3) == 0) {
        uVar5 = (ulong)uVar2;
        break;
      }
      uVar2 = uVar2 + 1;
      pbVar6 = pbVar6 + 1;
    } while (uVar2 != (uint)param_3);
    local_33[uVar5] = 0;
    iVar3 = strcasecmp((char *)local_33,"suspend");
    if (iVar3 == 0) {
      uVar7 = 1;
    }
    else {
      iVar3 = strcasecmp((char *)local_33,"hibernate");
      uVar7 = 0;
      if (iVar3 != 0) {
        iVar3 = strcasecmp((char *)local_33,"resume");
        if (iVar3 != 0) goto LAB_00118b1e;
        uVar7 = 2;
      }
    }
    iVar3 = nv_set_system_power_state(uVar7,nv_procfs_pm_action_depth);
    uVar5 = 0xfffffffffffffffb;
    if (iVar3 == 0) {
      uVar5 = param_3;
    }
  }
  else {
LAB_00118b1e:
    uVar5 = 0xffffffffffffffea;
  }
LAB_00118ac5:
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00118b50 __pfx_nv_procfs_write_suspend_depth =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118c5f) */

ulong __pfx_nv_procfs_write_suspend_depth(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  byte *pbVar5;
  uint uVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  byte abStack_31 [9];
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  abStack_31[8] = 0;
  abStack_31[0] = 0;
  abStack_31[1] = 0;
  abStack_31[2] = 0;
  abStack_31[3] = 0;
  abStack_31[4] = 0;
  abStack_31[5] = 0;
  abStack_31[6] = 0;
  abStack_31[7] = 0;
  cVar2 = capable(0x15);
  if (cVar2 == '\0') {
    param_3 = 0xffffffffffffffff;
    uVar1 = nv_procfs_pm_action_depth;
    goto LAB_00118c42;
  }
  if (param_3 - 3 < 7) {
    __check_object_size(abStack_31,param_3,0);
    lVar4 = _copy_from_user(abStack_31,param_2,param_3);
    if (lVar4 != 0) {
      param_3 = 0xfffffffffffffff2;
      uVar1 = nv_procfs_pm_action_depth;
      goto LAB_00118c42;
    }
    if (8 < param_3) {
      param_3 = 8;
    }
    uVar6 = 0;
    uVar7 = param_3 & 0xffffffff;
    pbVar5 = abStack_31;
    do {
      if (((&_ctype)[*pbVar5] & 3) == 0) {
        uVar7 = (ulong)uVar6;
        break;
      }
      uVar6 = uVar6 + 1;
      pbVar5 = pbVar5 + 1;
    } while (uVar6 != (uint)param_3);
    abStack_31[uVar7] = 0;
    iVar3 = strcasecmp((char *)abStack_31,"uvm");
    uVar1 = 2;
    if (iVar3 == 0) goto LAB_00118c42;
    iVar3 = strcasecmp((char *)abStack_31,"modeset");
    uVar1 = 1;
    if (iVar3 == 0) goto LAB_00118c42;
    iVar3 = strcasecmp((char *)abStack_31,"default");
    if (iVar3 == 0) {
      uVar1 = 0;
      goto LAB_00118c42;
    }
  }
  param_3 = 0xffffffffffffffea;
  uVar1 = nv_procfs_pm_action_depth;
LAB_00118c42:
  nv_procfs_pm_action_depth = uVar1;
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}


// ===== 00118b60 nv_procfs_write_suspend_depth =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118c5f) */

ulong nv_procfs_write_suspend_depth(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  byte *pbVar5;
  uint uVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  byte local_31 [9];
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_31[8] = 0;
  local_31[0] = 0;
  local_31[1] = 0;
  local_31[2] = 0;
  local_31[3] = 0;
  local_31[4] = 0;
  local_31[5] = 0;
  local_31[6] = 0;
  local_31[7] = 0;
  cVar2 = capable(0x15);
  if (cVar2 == '\0') {
    param_3 = 0xffffffffffffffff;
    uVar1 = nv_procfs_pm_action_depth;
    goto LAB_00118c42;
  }
  if (param_3 - 3 < 7) {
    __check_object_size(local_31,param_3,0);
    lVar4 = _copy_from_user(local_31,param_2,param_3);
    if (lVar4 != 0) {
      param_3 = 0xfffffffffffffff2;
      uVar1 = nv_procfs_pm_action_depth;
      goto LAB_00118c42;
    }
    if (8 < param_3) {
      param_3 = 8;
    }
    uVar6 = 0;
    uVar7 = param_3 & 0xffffffff;
    pbVar5 = local_31;
    do {
      if (((&_ctype)[*pbVar5] & 3) == 0) {
        uVar7 = (ulong)uVar6;
        break;
      }
      uVar6 = uVar6 + 1;
      pbVar5 = pbVar5 + 1;
    } while (uVar6 != (uint)param_3);
    local_31[uVar7] = 0;
    iVar3 = strcasecmp((char *)local_31,"uvm");
    uVar1 = 2;
    if (iVar3 == 0) goto LAB_00118c42;
    iVar3 = strcasecmp((char *)local_31,"modeset");
    uVar1 = 1;
    if (iVar3 == 0) goto LAB_00118c42;
    iVar3 = strcasecmp((char *)local_31,"default");
    if (iVar3 == 0) {
      uVar1 = 0;
      goto LAB_00118c42;
    }
  }
  param_3 = 0xffffffffffffffea;
  uVar1 = nv_procfs_pm_action_depth;
LAB_00118c42:
  nv_procfs_pm_action_depth = uVar1;
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}


// ===== 00118ce0 __pfx_nv_procfs_write_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118dd6) */

ulong __pfx_nv_procfs_write_file(long param_1,undefined8 param_2,ulong param_3,long *param_4)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x68);
  down(lVar1 + 8);
  if (param_3 == 0) {
    up(lVar1 + 8);
    param_3 = 0xffffffffffffffea;
  }
  else {
    lVar3 = *(long *)(lVar1 + 0x30);
    if ((0x1fffffU - lVar3 < param_3) || (lVar3 == 0x1fffff)) {
      up(lVar1 + 8);
      param_3 = 0xffffffffffffffe4;
    }
    else {
      if (0x7fffffff < param_3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = lVar3 + *(long *)(lVar1 + 0x28);
      __check_object_size(lVar3,param_3,0);
      lVar3 = _copy_from_user(lVar3,param_2,param_3);
      if (lVar3 == 0) {
        lVar3 = *(long *)(lVar1 + 0x30) + param_3;
        *(long *)(lVar1 + 0x30) = lVar3;
        *param_4 = lVar3;
        up(lVar1 + 8);
      }
      else {
        nv_printf(4,"NVRM: failed to copy in proc data!\n");
        *param_4 = *(long *)(lVar1 + 0x30);
        up(lVar1 + 8);
        param_3 = 0xfffffffffffffff2;
      }
    }
  }
  return param_3;
}


// ===== 00118cf0 nv_procfs_write_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118dd6) */

ulong nv_procfs_write_file(long param_1,undefined8 param_2,ulong param_3,long *param_4)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x68);
  down(lVar1 + 8);
  if (param_3 == 0) {
    up(lVar1 + 8);
    param_3 = 0xffffffffffffffea;
  }
  else {
    lVar3 = *(long *)(lVar1 + 0x30);
    if ((0x1fffffU - lVar3 < param_3) || (lVar3 == 0x1fffff)) {
      up(lVar1 + 8);
      param_3 = 0xffffffffffffffe4;
    }
    else {
      if (0x7fffffff < param_3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar3 = lVar3 + *(long *)(lVar1 + 0x28);
      __check_object_size(lVar3,param_3,0);
      lVar3 = _copy_from_user(lVar3,param_2,param_3);
      if (lVar3 == 0) {
        lVar3 = *(long *)(lVar1 + 0x30) + param_3;
        *(long *)(lVar1 + 0x30) = lVar3;
        *param_4 = lVar3;
        up(lVar1 + 8);
      }
      else {
        nv_printf(4,"NVRM: failed to copy in proc data!\n");
        *param_4 = *(long *)(lVar1 + 0x30);
        up(lVar1 + 8);
        param_3 = 0xfffffffffffffff2;
      }
    }
  }
  return param_3;
}


// ===== 00118e20 __pfx_nv_procfs_read_unbind_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118e81) */
/* WARNING: Removing unreachable block (ram,0x00118ea3) */

undefined8 __pfx_nv_procfs_read_unbind_lock(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x68) + 0x20);
  lVar1 = *(long *)(lVar2 + 8) + 0x730;
  down(lVar1);
  if ((*(byte *)(lVar2 + 0x11) & 0x40) != 0) {
    seq_printf(param_1,&DAT_00daf3c5);
    up(lVar1);
    return 0;
  }
  seq_printf(param_1,&DAT_00daf3c8);
  up(lVar1);
  return 0;
}


// ===== 00118e30 nv_procfs_read_unbind_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118e81) */
/* WARNING: Removing unreachable block (ram,0x00118ea3) */

undefined8 nv_procfs_read_unbind_lock(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x68) + 0x20);
  lVar1 = *(long *)(lVar2 + 8) + 0x730;
  down(lVar1);
  if ((*(byte *)(lVar2 + 0x11) & 0x40) != 0) {
    seq_printf(param_1,&DAT_00daf3c5);
    up(lVar1);
    return 0;
  }
  seq_printf(param_1,&DAT_00daf3c8);
  up(lVar1);
  return 0;
}


// ===== 00118eb0 __pfx_numa_status_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118f63) */

int __pfx_numa_status_read(long param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 8);
  down(lVar1 + 0x730);
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    if (*(int *)(lVar1 + 0x4a0) != -1) {
      memset(param_3,0,0x230);
      iVar2 = *(int *)(lVar1 + 0x4a0);
      *param_3 = iVar2;
      iVar3 = 0;
      if (iVar2 != -1) {
        iVar3 = *(int *)(lVar1 + 0x4a4);
      }
      param_3[1] = iVar3;
    }
    iVar2 = 0x55;
  }
  else {
    iVar2 = rm_get_gpu_numa_info(param_2,param_1,param_3);
    if ((iVar2 == 0) && (*param_3 == -1)) {
      iVar2 = 0x56;
    }
    iVar3 = 0;
    if (*(int *)(lVar1 + 0x4a0) != -1) {
      iVar3 = *(int *)(lVar1 + 0x4a4);
    }
    param_3[1] = iVar3;
  }
  up(lVar1 + 0x730);
  return iVar2;
}


// ===== 00118ec0 numa_status_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00118f63) */

int numa_status_read(long param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 8);
  down(lVar1 + 0x730);
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    if (*(int *)(lVar1 + 0x4a0) != -1) {
      memset(param_3,0,0x230);
      iVar2 = *(int *)(lVar1 + 0x4a0);
      *param_3 = iVar2;
      iVar3 = 0;
      if (iVar2 != -1) {
        iVar3 = *(int *)(lVar1 + 0x4a4);
      }
      param_3[1] = iVar3;
    }
    iVar2 = 0x55;
  }
  else {
    iVar2 = rm_get_gpu_numa_info(param_2,param_1,param_3);
    if ((iVar2 == 0) && (*param_3 == -1)) {
      iVar2 = 0x56;
    }
    iVar3 = 0;
    if (*(int *)(lVar1 + 0x4a0) != -1) {
      iVar3 = *(int *)(lVar1 + 0x4a4);
    }
    param_3[1] = iVar3;
  }
  up(lVar1 + 0x730);
  return iVar2;
}


// ===== 00118fb0 __pfx_nv_procfs_read_offline_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011907d) */

undefined8 __pfx_nv_procfs_read_offline_pages(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long in_GS_OFFSET;
  undefined1 auStack_250 [40];
  undefined8 auStack_228 [64];
  uint uStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  memset(auStack_250,0,0x230);
  uStack_28 = 0x40;
  iVar2 = numa_status_read((*(undefined8 **)(param_1 + 0x68))[4],**(undefined8 **)(param_1 + 0x68),
                           auStack_250);
  if (iVar2 == 0) {
    lVar4 = 0;
    if (uStack_28 != 0) {
      do {
        puVar1 = auStack_228 + lVar4;
        lVar4 = lVar4 + 1;
        seq_printf(param_1,&DAT_00daf3cb,*puVar1);
      } while ((uint)lVar4 < uStack_28);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffffb;
  }
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00118fc0 nv_procfs_read_offline_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011907d) */

undefined8 nv_procfs_read_offline_pages(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long in_GS_OFFSET;
  undefined1 auStack_250 [40];
  undefined8 auStack_228 [64];
  uint local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  memset(auStack_250,0,0x230);
  local_28 = 0x40;
  iVar2 = numa_status_read((*(undefined8 **)(param_1 + 0x68))[4],**(undefined8 **)(param_1 + 0x68),
                           auStack_250);
  if (iVar2 == 0) {
    lVar4 = 0;
    if (local_28 != 0) {
      do {
        puVar1 = auStack_228 + lVar4;
        lVar4 = lVar4 + 1;
        seq_printf(param_1,&DAT_00daf3cb,*puVar1);
      } while ((uint)lVar4 < local_28);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffffb;
  }
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001190a0 __pfx_nv_procfs_read_numa_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119160) */

undefined8 __pfx_nv_procfs_read_numa_status(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long in_GS_OFFSET;
  undefined4 uStack_250;
  uint uStack_24c;
  undefined8 uStack_240;
  undefined8 uStack_238;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  memset(&uStack_250,0,0x230);
  iVar1 = numa_status_read((*(undefined8 **)(param_1 + 0x68))[4],**(undefined8 **)(param_1 + 0x68),
                           &uStack_250);
  if ((iVar1 == 0) || (iVar1 == 0x55)) {
    seq_printf(param_1,"Node:      %d\n",uStack_250);
    pcVar3 = "invalid";
    if (uStack_24c < 7) {
      pcVar3 = (&nv_numa_status_messages)[uStack_24c];
    }
    seq_printf(param_1,"Status:    %s\n",pcVar3);
    if (iVar1 == 0) {
      seq_printf(param_1,"Address:   %llx\n",uStack_240);
      seq_printf(param_1,"Size:      %llx\n",uStack_238);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffb;
  }
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001190b0 nv_procfs_read_numa_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119160) */

undefined8 nv_procfs_read_numa_status(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long in_GS_OFFSET;
  undefined4 local_250;
  uint local_24c;
  undefined8 local_240;
  undefined8 local_238;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  memset(&local_250,0,0x230);
  iVar1 = numa_status_read((*(undefined8 **)(param_1 + 0x68))[4],**(undefined8 **)(param_1 + 0x68),
                           &local_250);
  if ((iVar1 == 0) || (iVar1 == 0x55)) {
    seq_printf(param_1,"Node:      %d\n",local_250);
    pcVar3 = "invalid";
    if (local_24c < 7) {
      pcVar3 = (&nv_numa_status_messages)[local_24c];
    }
    seq_printf(param_1,"Status:    %s\n",pcVar3);
    if (iVar1 == 0) {
      seq_printf(param_1,"Address:   %llx\n",local_240);
      seq_printf(param_1,"Size:      %llx\n",local_238);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffb;
  }
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001191a0 __pfx_nv_procfs_read_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001193d9) */

undefined8 __pfx_nv_procfs_read_gpu_info(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  
  puVar8 = (undefined4 *)0x0;
  lVar1 = *(long *)(param_1 + 0x68);
  lVar2 = *(long *)(lVar1 + 8);
  lVar3 = *(long *)(lVar2 + 0x3b8);
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 != '\0') {
    puVar8 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar8 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar8 = 0x2ff0;
    *(undefined4 **)(puVar8 + 2) = puVar8 + 0xc00;
  }
  uVar5 = rm_get_device_name(*(undefined2 *)(lVar3 + 0x3e),*(undefined2 *)(lVar3 + 0x40),
                             *(undefined2 *)(lVar3 + 0x42));
  seq_printf(param_1,"Model: \t\t %s\n",uVar5);
  seq_printf(param_1,"IRQ:   \t\t %d\n",*(undefined4 *)(lVar1 + 0x17c));
  if (*(char *)(lVar1 + 0x2c) == '\0') {
    nv_printf(4,"GPU UUID cache not valid!\n");
  }
  else {
    lVar7 = rm_get_gpu_uuid(puVar8,lVar1);
    if (lVar7 != 0) {
      seq_printf(param_1,"GPU UUID: \t %s\n",lVar7);
      os_free_mem(lVar7);
    }
  }
  seq_printf(param_1,"Video BIOS: \t %s\n",lVar1 + 0x34a);
  cVar4 = nv_find_pci_capability(lVar3,0x10);
  puVar9 = &DAT_00daf41c;
  if (cVar4 != '\0') {
    puVar9 = &DAT_00daf417;
  }
  seq_printf(param_1,"Bus Type: \t %s\n",puVar9);
  uVar6 = (*(ulong *)(lVar3 + 0x88) >> 1 & 0x5555555555555555) +
          (*(ulong *)(lVar3 + 0x88) & 0x5555555555555555);
  uVar6 = (uVar6 >> 2 & 0x3333333333333333) + (uVar6 & 0x3333333333333333);
  uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f) + (uVar6 >> 4 & 0xf0f0f0f0f0f0f0f);
  uVar6 = (uVar6 & 0xff00ff00ff00ff) + (uVar6 >> 8 & 0xff00ff00ff00ff);
  lVar7 = (uVar6 >> 0x10 & 0xffff0000ffff) + (uVar6 & 0xffff0000ffff);
  seq_printf(param_1,"DMA Size: \t %d bits\n",(int)((ulong)lVar7 >> 0x20) + (int)lVar7);
  seq_printf(param_1,"DMA Mask: \t 0x%llx\n",*(undefined8 *)(lVar3 + 0x88));
  seq_printf(param_1,"Bus Location: \t %04x:%02x:%02x.%x\n",*(undefined4 *)(lVar1 + 0x14),
             *(undefined1 *)(lVar1 + 0x18),*(undefined1 *)(lVar1 + 0x19),*(uint *)(lVar3 + 0x38) & 7
            );
  seq_printf(param_1,"Device Minor: \t %u\n",*(undefined4 *)(lVar2 + 0x750));
  if (*(char *)(lVar1 + 0x359) == '\0') {
    seq_printf(param_1,"GPU Firmware: \t N/A\n");
  }
  else {
    seq_printf(param_1,"GPU Firmware: \t %s\n",lVar1 + 0x359);
  }
  puVar9 = &DAT_00daf424;
  if ((*(byte *)(lVar1 + 0x10) & 2) != 0) {
    puVar9 = &DAT_00daf420;
  }
  seq_printf(param_1,"GPU Excluded:\t %s\n",puVar9);
  if ((puVar8 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar8);
  }
  return 0;
}


// ===== 001191b0 nv_procfs_read_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001193d9) */

undefined8 nv_procfs_read_gpu_info(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  
  puVar8 = (undefined4 *)0x0;
  lVar1 = *(long *)(param_1 + 0x68);
  lVar2 = *(long *)(lVar1 + 8);
  lVar3 = *(long *)(lVar2 + 0x3b8);
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 != '\0') {
    puVar8 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar8 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar8 = 0x2ff0;
    *(undefined4 **)(puVar8 + 2) = puVar8 + 0xc00;
  }
  uVar5 = rm_get_device_name(*(undefined2 *)(lVar3 + 0x3e),*(undefined2 *)(lVar3 + 0x40),
                             *(undefined2 *)(lVar3 + 0x42));
  seq_printf(param_1,"Model: \t\t %s\n",uVar5);
  seq_printf(param_1,"IRQ:   \t\t %d\n",*(undefined4 *)(lVar1 + 0x17c));
  if (*(char *)(lVar1 + 0x2c) == '\0') {
    nv_printf(4,"GPU UUID cache not valid!\n");
  }
  else {
    lVar7 = rm_get_gpu_uuid(puVar8,lVar1);
    if (lVar7 != 0) {
      seq_printf(param_1,"GPU UUID: \t %s\n",lVar7);
      os_free_mem(lVar7);
    }
  }
  seq_printf(param_1,"Video BIOS: \t %s\n",lVar1 + 0x34a);
  cVar4 = nv_find_pci_capability(lVar3,0x10);
  puVar9 = &DAT_00daf41c;
  if (cVar4 != '\0') {
    puVar9 = &DAT_00daf417;
  }
  seq_printf(param_1,"Bus Type: \t %s\n",puVar9);
  uVar6 = (*(ulong *)(lVar3 + 0x88) >> 1 & 0x5555555555555555) +
          (*(ulong *)(lVar3 + 0x88) & 0x5555555555555555);
  uVar6 = (uVar6 >> 2 & 0x3333333333333333) + (uVar6 & 0x3333333333333333);
  uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f) + (uVar6 >> 4 & 0xf0f0f0f0f0f0f0f);
  uVar6 = (uVar6 & 0xff00ff00ff00ff) + (uVar6 >> 8 & 0xff00ff00ff00ff);
  lVar7 = (uVar6 >> 0x10 & 0xffff0000ffff) + (uVar6 & 0xffff0000ffff);
  seq_printf(param_1,"DMA Size: \t %d bits\n",(int)((ulong)lVar7 >> 0x20) + (int)lVar7);
  seq_printf(param_1,"DMA Mask: \t 0x%llx\n",*(undefined8 *)(lVar3 + 0x88));
  seq_printf(param_1,"Bus Location: \t %04x:%02x:%02x.%x\n",*(undefined4 *)(lVar1 + 0x14),
             *(undefined1 *)(lVar1 + 0x18),*(undefined1 *)(lVar1 + 0x19),*(uint *)(lVar3 + 0x38) & 7
            );
  seq_printf(param_1,"Device Minor: \t %u\n",*(undefined4 *)(lVar2 + 0x750));
  if (*(char *)(lVar1 + 0x359) == '\0') {
    seq_printf(param_1,"GPU Firmware: \t N/A\n");
  }
  else {
    seq_printf(param_1,"GPU Firmware: \t %s\n",lVar1 + 0x359);
  }
  puVar9 = &DAT_00daf424;
  if ((*(byte *)(lVar1 + 0x10) & 2) != 0) {
    puVar9 = &DAT_00daf420;
  }
  seq_printf(param_1,"GPU Excluded:\t %s\n",puVar9);
  if ((puVar8 != (undefined4 *)0x0) && (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar8);
  }
  return 0;
}


// ===== 00119480 __pfx_nv_procfs_release_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_power(void)

{
  single_release();
  return;
}


// ===== 00119490 nv_procfs_release_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_power(void)

{
  single_release();
  return;
}


// ===== 001194a0 __pfx_nv_procfs_release_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_version(void)

{
  single_release();
  return;
}


// ===== 001194b0 nv_procfs_release_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_version(void)

{
  single_release();
  return;
}


// ===== 001194c0 __pfx_nv_procfs_release_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_params(void)

{
  single_release();
  return;
}


// ===== 001194d0 nv_procfs_release_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_params(void)

{
  single_release();
  return;
}


// ===== 001194e0 __pfx_nv_procfs_release_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_text_file(void)

{
  single_release();
  return;
}


// ===== 001194f0 nv_procfs_release_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_text_file(void)

{
  single_release();
  return;
}


// ===== 00119500 __pfx_nv_procfs_close_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_close_file(long *param_1)

{
  long lVar1;
  char cVar2;
  
  if (param_1[5] != 0) {
    os_free_mem();
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  kfree(param_1);
  return;
}


// ===== 00119510 nv_procfs_close_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_close_file(long *param_1)

{
  long lVar1;
  char cVar2;
  
  if (param_1[5] != 0) {
    os_free_mem();
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  kfree(param_1);
  return;
}


// ===== 00119560 __pfx_nv_procfs_close_registry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001196ca) */

undefined8 __pfx_nv_procfs_close_registry(undefined8 param_1,long param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  long lVar3;
  int iVar4;
  char *__s;
  size_t sVar5;
  char *pcVar6;
  size_t sVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined1 *__haystack;
  long lVar11;
  long in_GS_OFFSET;
  char *pcStack_48;
  long lStack_40;
  
  puVar2 = *(undefined8 **)(*(long *)(param_2 + 0x18) + 0x68);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (puVar2[6] == 0) {
    pcStack_48 = (char *)0x0;
  }
  else {
    lVar11 = 0;
    uVar10 = *puVar2;
    lVar3 = puVar2[4];
    if (lVar3 != 0) {
      lVar11 = *(long *)(lVar3 + 8);
    }
    pcStack_48 = (char *)puVar2[5];
    __s = strsep(&pcStack_48,"=");
    if (((__s == (char *)0x0) || (pcStack_48 == (char *)0x0)) ||
       (sVar5 = strlen(__s), (long)(~sVar5 + puVar2[6]) < 1)) {
      uVar10 = 0xffffffea;
      goto LAB_0011967e;
    }
    iVar4 = rm_write_registry_binary(uVar10,lVar3,__s);
    if (iVar4 != 0) {
      uVar10 = 0xfffffff2;
      goto LAB_0011967e;
    }
    __haystack = (undefined1 *)(lVar11 + 0x4d8);
    if (lVar11 == 0) {
      __haystack = nv_registry_keys;
    }
    pcVar6 = strstr(__haystack,__s);
    if (pcVar6 == (char *)0x0) {
      sVar7 = strnlen(__haystack,0x200);
      if (0x200 < sVar7) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(2,0x200,sVar7 + 1);
      }
      if (sVar7 == 0x200) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(4,0x200,0x201);
      }
      if (sVar5 + 3 + sVar7 < 0x201) {
        if (sVar7 != 0) {
          sVar5 = strnlen(__haystack,0x200);
          if (0x200 < sVar5) {
                    /* WARNING: Subroutine does not return */
            __fortify_panic(2,0x200,sVar5 + 1);
          }
          if (sVar5 == 0x200) {
LAB_00119819:
                    /* WARNING: Subroutine does not return */
            __fortify_panic(0xb,0x200,sVar5 + 3);
          }
          pcVar6 = __haystack + sVar5;
          if (0x1ff < sVar5 + 2) {
            if (-(int)sVar5 != -0x1ff) {
              uVar8 = 0;
              do {
                uVar9 = uVar8 + 1;
                pcVar6[uVar8] = (&DAT_00daf50b)[uVar8];
                uVar8 = uVar9;
              } while (uVar9 < -(int)sVar5 + 0x1ffU);
            }
            __haystack[0x1ff] = '\0';
            goto LAB_00119819;
          }
          pcVar6[0] = ',';
          pcVar6[1] = ' ';
          __haystack[sVar5 + 2] = '\0';
        }
        sVar5 = strnlen(__haystack,0x200);
        if (0x200 < sVar5) {
                    /* WARNING: Subroutine does not return */
          __fortify_panic(2,0x200,sVar5 + 1);
        }
        sVar7 = strlen(__s);
        uVar1 = sVar5 + sVar7;
        if (sVar5 == 0x200) {
LAB_001197b7:
                    /* WARNING: Subroutine does not return */
          __fortify_panic(0xb,0x200,uVar1 + 1);
        }
        if (0x1ff < uVar1) {
          memcpy(__haystack + sVar5,__s,0x1ff - sVar5);
          __haystack[0x1ff] = '\0';
          goto LAB_001197b7;
        }
        memcpy(__haystack + sVar5,__s,sVar7);
        __haystack[uVar1] = '\0';
      }
    }
  }
  uVar10 = 0;
LAB_0011967e:
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(puVar2);
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// ===== 00119570 nv_procfs_close_registry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001196ca) */

undefined8 nv_procfs_close_registry(undefined8 param_1,long param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  long lVar3;
  int iVar4;
  char *__s;
  size_t sVar5;
  char *pcVar6;
  size_t sVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined1 *__haystack;
  long lVar11;
  long in_GS_OFFSET;
  char *local_48;
  long local_40;
  
  puVar2 = *(undefined8 **)(*(long *)(param_2 + 0x18) + 0x68);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (puVar2[6] == 0) {
    local_48 = (char *)0x0;
  }
  else {
    lVar11 = 0;
    uVar10 = *puVar2;
    lVar3 = puVar2[4];
    if (lVar3 != 0) {
      lVar11 = *(long *)(lVar3 + 8);
    }
    local_48 = (char *)puVar2[5];
    __s = strsep(&local_48,"=");
    if (((__s == (char *)0x0) || (local_48 == (char *)0x0)) ||
       (sVar5 = strlen(__s), (long)(~sVar5 + puVar2[6]) < 1)) {
      uVar10 = 0xffffffea;
      goto LAB_0011967e;
    }
    iVar4 = rm_write_registry_binary(uVar10,lVar3,__s);
    if (iVar4 != 0) {
      uVar10 = 0xfffffff2;
      goto LAB_0011967e;
    }
    __haystack = (undefined1 *)(lVar11 + 0x4d8);
    if (lVar11 == 0) {
      __haystack = nv_registry_keys;
    }
    pcVar6 = strstr(__haystack,__s);
    if (pcVar6 == (char *)0x0) {
      sVar7 = strnlen(__haystack,0x200);
      if (0x200 < sVar7) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(2,0x200,sVar7 + 1);
      }
      if (sVar7 == 0x200) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(4,0x200,0x201);
      }
      if (sVar5 + 3 + sVar7 < 0x201) {
        if (sVar7 != 0) {
          sVar5 = strnlen(__haystack,0x200);
          if (0x200 < sVar5) {
                    /* WARNING: Subroutine does not return */
            __fortify_panic(2,0x200,sVar5 + 1);
          }
          if (sVar5 == 0x200) {
LAB_00119819:
                    /* WARNING: Subroutine does not return */
            __fortify_panic(0xb,0x200,sVar5 + 3);
          }
          pcVar6 = __haystack + sVar5;
          if (0x1ff < sVar5 + 2) {
            if (-(int)sVar5 != -0x1ff) {
              uVar8 = 0;
              do {
                uVar9 = uVar8 + 1;
                pcVar6[uVar8] = (&DAT_00daf50b)[uVar8];
                uVar8 = uVar9;
              } while (uVar9 < -(int)sVar5 + 0x1ffU);
            }
            __haystack[0x1ff] = '\0';
            goto LAB_00119819;
          }
          pcVar6[0] = ',';
          pcVar6[1] = ' ';
          __haystack[sVar5 + 2] = '\0';
        }
        sVar5 = strnlen(__haystack,0x200);
        if (0x200 < sVar5) {
                    /* WARNING: Subroutine does not return */
          __fortify_panic(2,0x200,sVar5 + 1);
        }
        sVar7 = strlen(__s);
        uVar1 = sVar5 + sVar7;
        if (sVar5 == 0x200) {
LAB_001197b7:
                    /* WARNING: Subroutine does not return */
          __fortify_panic(0xb,0x200,uVar1 + 1);
        }
        if (0x1ff < uVar1) {
          memcpy(__haystack + sVar5,__s,0x1ff - sVar5);
          __haystack[0x1ff] = '\0';
          goto LAB_001197b7;
        }
        memcpy(__haystack + sVar5,__s,sVar7);
        __haystack[uVar1] = '\0';
      }
    }
  }
  uVar10 = 0;
LAB_0011967e:
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(puVar2);
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// ===== 00119870 __pfx_nv_procfs_close_offline_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001198c6) */

undefined8 __pfx_nv_procfs_close_offline_pages(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(*(long *)(param_2 + 0x18) + 0x68);
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(uVar1);
  return 0;
}


// ===== 00119880 nv_procfs_close_offline_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001198c6) */

undefined8 nv_procfs_close_offline_pages(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(*(long *)(param_2 + 0x18) + 0x68);
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(uVar1);
  return 0;
}


// ===== 001198d0 __pfx_nv_procfs_close_numa_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001199e7) */

uint __pfx_nv_procfs_close_numa_status(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  char *__s2;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  
  uVar7 = 0;
  puVar1 = *(undefined8 **)(*(long *)(param_2 + 0x18) + 0x68);
  uVar2 = *puVar1;
  lVar3 = puVar1[4];
  lVar4 = *(long *)(lVar3 + 8);
  if (*(int *)(lVar4 + 0x4a0) != -1) {
    uVar7 = *(uint *)(lVar4 + 0x4a4);
  }
  __s2 = (char *)puVar1[5];
  down(lVar4 + 0x730);
  uVar6 = 0;
  if (puVar1[6] != 0) {
    lVar9 = 0;
    do {
      iVar5 = strncmp((&nv_numa_status_messages)[lVar9],__s2,0x20);
      if (iVar5 == 0) {
        uVar8 = (uint)lVar9;
        uVar6 = 0;
        if (uVar8 == uVar7) goto LAB_00119998;
        if (uVar8 == 4) {
          if ((uVar7 - 2 < 2) && (*(int *)(lVar4 + 0x4a0) != -1)) {
            *(undefined4 *)(lVar4 + 0x4a4) = 4;
            goto LAB_00119998;
          }
        }
        else if (uVar8 < 5) {
          if (uVar8 == 2) {
            if ((uVar7 == 1) && (*(int *)(lVar4 + 0x4a0) != -1)) {
              *(undefined4 *)(lVar4 + 0x4a4) = 2;
              goto LAB_00119998;
            }
          }
          else if (uVar8 == 3) {
            if ((uVar7 == 2) && (*(int *)(lVar4 + 0x4a0) != -1)) {
              *(undefined4 *)(lVar4 + 0x4a4) = 3;
              iVar5 = rm_gpu_numa_online(uVar2,lVar3);
              if (iVar5 != 0) {
                uVar6 = 0xfffffff0;
              }
              goto LAB_00119998;
            }
          }
          else if (uVar8 == 1) goto LAB_00119a67;
        }
        else if (uVar8 == 5) {
          if (uVar7 != 1) {
            iVar5 = rm_gpu_numa_offline(uVar2,lVar3);
            if (iVar5 != 0) {
              uVar6 = 0xfffffff0;
              goto LAB_00119998;
            }
            if (*(int *)(lVar4 + 0x4a0) != -1) {
              *(undefined4 *)(lVar4 + 0x4a4) = 5;
              goto LAB_00119998;
            }
          }
        }
        else {
LAB_00119a67:
          if ((uVar7 == 5) && (*(int *)(lVar4 + 0x4a0) != -1)) {
            *(uint *)(lVar4 + 0x4a4) = uVar8;
            goto LAB_00119998;
          }
        }
        uVar6 = 0xffffffea;
        goto LAB_00119998;
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 != 7);
    uVar6 = -(uint)(uVar7 != 0) & 0xffffffea;
  }
LAB_00119998:
  up(lVar4 + 0x730);
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(puVar1);
  return uVar6;
}


// ===== 001198e0 nv_procfs_close_numa_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001199e7) */

uint nv_procfs_close_numa_status(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  char *__s2;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  
  uVar7 = 0;
  puVar1 = *(undefined8 **)(*(long *)(param_2 + 0x18) + 0x68);
  uVar2 = *puVar1;
  lVar3 = puVar1[4];
  lVar4 = *(long *)(lVar3 + 8);
  if (*(int *)(lVar4 + 0x4a0) != -1) {
    uVar7 = *(uint *)(lVar4 + 0x4a4);
  }
  __s2 = (char *)puVar1[5];
  down(lVar4 + 0x730);
  uVar6 = 0;
  if (puVar1[6] != 0) {
    lVar9 = 0;
    do {
      iVar5 = strncmp((&nv_numa_status_messages)[lVar9],__s2,0x20);
      if (iVar5 == 0) {
        uVar8 = (uint)lVar9;
        uVar6 = 0;
        if (uVar8 == uVar7) goto LAB_00119998;
        if (uVar8 == 4) {
          if ((uVar7 - 2 < 2) && (*(int *)(lVar4 + 0x4a0) != -1)) {
            *(undefined4 *)(lVar4 + 0x4a4) = 4;
            goto LAB_00119998;
          }
        }
        else if (uVar8 < 5) {
          if (uVar8 == 2) {
            if ((uVar7 == 1) && (*(int *)(lVar4 + 0x4a0) != -1)) {
              *(undefined4 *)(lVar4 + 0x4a4) = 2;
              goto LAB_00119998;
            }
          }
          else if (uVar8 == 3) {
            if ((uVar7 == 2) && (*(int *)(lVar4 + 0x4a0) != -1)) {
              *(undefined4 *)(lVar4 + 0x4a4) = 3;
              iVar5 = rm_gpu_numa_online(uVar2,lVar3);
              if (iVar5 != 0) {
                uVar6 = 0xfffffff0;
              }
              goto LAB_00119998;
            }
          }
          else if (uVar8 == 1) goto LAB_00119a67;
        }
        else if (uVar8 == 5) {
          if (uVar7 != 1) {
            iVar5 = rm_gpu_numa_offline(uVar2,lVar3);
            if (iVar5 != 0) {
              uVar6 = 0xfffffff0;
              goto LAB_00119998;
            }
            if (*(int *)(lVar4 + 0x4a0) != -1) {
              *(undefined4 *)(lVar4 + 0x4a4) = 5;
              goto LAB_00119998;
            }
          }
        }
        else {
LAB_00119a67:
          if ((uVar7 == 5) && (*(int *)(lVar4 + 0x4a0) != -1)) {
            *(uint *)(lVar4 + 0x4a4) = uVar8;
            goto LAB_00119998;
          }
        }
        uVar6 = 0xffffffea;
        goto LAB_00119998;
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 != 7);
    uVar6 = -(uint)(uVar7 != 0) & 0xffffffea;
  }
LAB_00119998:
  up(lVar4 + 0x730);
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(puVar1);
  return uVar6;
}


// ===== 00119b50 __pfx_nv_procfs_close_unbind_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119cb4) */

undefined8 __pfx_nv_procfs_close_unbind_lock(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined8 uVar10;
  long in_GS_OFFSET;
  int iStack_44;
  long lStack_40;
  
  puVar2 = *(undefined8 **)(*(long *)(param_2 + 0x18) + 0x68);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_44 = 0;
  uVar10 = *puVar2;
  if (puVar2[6] == 0) {
LAB_00119c64:
    uVar10 = 0;
  }
  else {
    lVar3 = puVar2[4];
    if ((lVar3 != 0) && ((char *)puVar2[5] != (char *)0x0)) {
      lVar4 = *(long *)(lVar3 + 8);
      iVar5 = sscanf((char *)puVar2[5],"%u\n",&iStack_44);
      if (iVar5 == 1) {
        lVar1 = lVar4 + 0x730;
        down(lVar1);
        if (iStack_44 == 1) {
          if ((*(byte *)(lVar3 + 0x11) & 0x40) == 0) {
            if (*(long *)(lVar4 + 0x3a0) == 0) {
              rm_unbind_lock(uVar10,lVar3);
              uVar9 = *(undefined1 *)(lVar3 + 0x1a);
              uVar8 = *(undefined1 *)(lVar3 + 0x19);
              uVar6 = *(undefined1 *)(lVar3 + 0x18);
              uVar7 = *(undefined4 *)(lVar3 + 0x14);
              if ((*(byte *)(lVar3 + 0x11) & 0x40) != 0) {
                nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: UnbindLock acquired\n",uVar7,uVar6,uVar8,
                          uVar9);
                goto LAB_00119c52;
              }
            }
            else {
              uVar9 = *(undefined1 *)(lVar3 + 0x1a);
              uVar8 = *(undefined1 *)(lVar3 + 0x19);
              uVar6 = *(undefined1 *)(lVar3 + 0x18);
              uVar7 = *(undefined4 *)(lVar3 + 0x14);
            }
            nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Could not acquire UnbindLock\n",uVar7,uVar6,
                      uVar8,uVar9);
          }
        }
        else if ((iStack_44 == 0) && ((*(uint *)(lVar3 + 0x10) & 0x4000) != 0)) {
          *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) & 0xffffbfff;
          nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: UnbindLock released\n",
                    *(undefined4 *)(lVar3 + 0x14),*(undefined1 *)(lVar3 + 0x18),
                    *(undefined1 *)(lVar3 + 0x19),*(undefined1 *)(lVar3 + 0x1a));
        }
LAB_00119c52:
        up(lVar1);
        goto LAB_00119c64;
      }
    }
    uVar10 = 0xffffffea;
  }
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(puVar2);
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// ===== 00119b60 nv_procfs_close_unbind_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119cb4) */

undefined8 nv_procfs_close_unbind_lock(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined8 uVar10;
  long in_GS_OFFSET;
  int local_44;
  long local_40;
  
  puVar2 = *(undefined8 **)(*(long *)(param_2 + 0x18) + 0x68);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_44 = 0;
  uVar10 = *puVar2;
  if (puVar2[6] == 0) {
LAB_00119c64:
    uVar10 = 0;
  }
  else {
    lVar3 = puVar2[4];
    if ((lVar3 != 0) && ((char *)puVar2[5] != (char *)0x0)) {
      lVar4 = *(long *)(lVar3 + 8);
      iVar5 = sscanf((char *)puVar2[5],"%u\n",&local_44);
      if (iVar5 == 1) {
        lVar1 = lVar4 + 0x730;
        down(lVar1);
        if (local_44 == 1) {
          if ((*(byte *)(lVar3 + 0x11) & 0x40) == 0) {
            if (*(long *)(lVar4 + 0x3a0) == 0) {
              rm_unbind_lock(uVar10,lVar3);
              uVar9 = *(undefined1 *)(lVar3 + 0x1a);
              uVar8 = *(undefined1 *)(lVar3 + 0x19);
              uVar6 = *(undefined1 *)(lVar3 + 0x18);
              uVar7 = *(undefined4 *)(lVar3 + 0x14);
              if ((*(byte *)(lVar3 + 0x11) & 0x40) != 0) {
                nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: UnbindLock acquired\n",uVar7,uVar6,uVar8,
                          uVar9);
                goto LAB_00119c52;
              }
            }
            else {
              uVar9 = *(undefined1 *)(lVar3 + 0x1a);
              uVar8 = *(undefined1 *)(lVar3 + 0x19);
              uVar6 = *(undefined1 *)(lVar3 + 0x18);
              uVar7 = *(undefined4 *)(lVar3 + 0x14);
            }
            nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Could not acquire UnbindLock\n",uVar7,uVar6,
                      uVar8,uVar9);
          }
        }
        else if ((local_44 == 0) && ((*(uint *)(lVar3 + 0x10) & 0x4000) != 0)) {
          *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) & 0xffffbfff;
          nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: UnbindLock released\n",
                    *(undefined4 *)(lVar3 + 0x14),*(undefined1 *)(lVar3 + 0x18),
                    *(undefined1 *)(lVar3 + 0x19),*(undefined1 *)(lVar3 + 0x1a));
        }
LAB_00119c52:
        up(lVar1);
        goto LAB_00119c64;
      }
    }
    uVar10 = 0xffffffea;
  }
  up_read(nv_system_pm_lock);
  single_release(param_1,param_2);
  nv_procfs_close_file(puVar2);
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// ===== 00119d60 __pfx_nv_procfs_read_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119ef5) */

undefined8 __pfx_nv_procfs_read_power(long param_1)

{
  long lVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  long in_GS_OFFSET;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  puVar3 = (undefined4 *)0x0;
  lVar1 = *(long *)(param_1 + 0x68);
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 != '\0') {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00119edc;
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
  }
  rm_get_power_info(puVar3,lVar1,&uStack_58);
  seq_printf(param_1,"Runtime D3 status:          %s\n",uStack_50);
  pcVar4 = "Disabled";
  if (*(char *)(lVar1 + 0x2b2) != '\0') {
    pcVar4 = "Enabled";
  }
  seq_printf(param_1,"Tegra iGPU Rail-Gating:     %s\n",pcVar4);
  seq_printf(param_1,"Video Memory:               %s\n\n",uStack_58);
  seq_printf(param_1,"GPU Hardware Support:\n");
  seq_printf(param_1," Video Memory Self Refresh: %s\n",uStack_48);
  seq_printf(param_1," Video Memory Off:          %s\n\n",uStack_40);
  seq_printf(param_1,"S0ix Power Management:\n");
  cVar2 = nv_platform_supports_s0ix();
  pcVar4 = "Not Supported";
  if (cVar2 != '\0') {
    pcVar4 = "Supported";
  }
  seq_printf(param_1," Platform Support:          %s\n",pcVar4);
  seq_printf(param_1," Status:                    %s\n\n",uStack_38);
  seq_printf(param_1,"Notebook Dynamic Boost:     %s\n",uStack_30);
  if (puVar3 != (undefined4 *)0x0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
    }
  }
LAB_00119edc:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00119d70 nv_procfs_read_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119ef5) */

undefined8 nv_procfs_read_power(long param_1)

{
  long lVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  long in_GS_OFFSET;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  puVar3 = (undefined4 *)0x0;
  lVar1 = *(long *)(param_1 + 0x68);
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 != '\0') {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00119edc;
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
  }
  rm_get_power_info(puVar3,lVar1,&local_58);
  seq_printf(param_1,"Runtime D3 status:          %s\n",local_50);
  pcVar4 = "Disabled";
  if (*(char *)(lVar1 + 0x2b2) != '\0') {
    pcVar4 = "Enabled";
  }
  seq_printf(param_1,"Tegra iGPU Rail-Gating:     %s\n",pcVar4);
  seq_printf(param_1,"Video Memory:               %s\n\n",local_58);
  seq_printf(param_1,"GPU Hardware Support:\n");
  seq_printf(param_1," Video Memory Self Refresh: %s\n",local_48);
  seq_printf(param_1," Video Memory Off:          %s\n\n",local_40);
  seq_printf(param_1,"S0ix Power Management:\n");
  cVar2 = nv_platform_supports_s0ix();
  pcVar4 = "Not Supported";
  if (cVar2 != '\0') {
    pcVar4 = "Supported";
  }
  seq_printf(param_1," Platform Support:          %s\n",pcVar4);
  seq_printf(param_1," Status:                    %s\n\n",local_38);
  seq_printf(param_1,"Notebook Dynamic Boost:     %s\n",local_30);
  if (puVar3 != (undefined4 *)0x0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
    }
  }
LAB_00119edc:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00119f40 __pfx_nv_procfs_open_file.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119fe4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_procfs_open_file_constprop_0(long param_1,long param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined8 *)__kmalloc_cache_noprof(_capable,0x2dc0,0x38);
  if (puVar4 == (undefined8 *)0x0) {
    nv_printf(4,"NVRM: failed to allocate procfs private!\n");
    return 0xfffffff4;
  }
  puVar4[1] = 0x100000000;
  uVar1 = *(undefined8 *)(param_1 + 0x230);
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = uVar1;
  if ((*(byte *)(param_2 + 4) & 2) != 0) {
    cVar2 = rm_is_altstack_in_use();
    puVar5 = (undefined4 *)0x0;
    if (cVar2 != '\0') {
      puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar5 == (undefined4 *)0x0) goto LAB_0011a047;
      *puVar5 = 0x2ff0;
      *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    }
    iVar3 = os_alloc_mem(puVar4 + 5,0x200000);
    if (iVar3 != 0) {
LAB_0011a047:
      nv_procfs_close_file(puVar4);
      return 0xfffffff4;
    }
    os_mem_set(puVar4[5],0,0x200000);
    *puVar4 = puVar5;
  }
  *param_3 = puVar4;
  return 0;
}


// ===== 00119f50 nv_procfs_open_file.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00119fe4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_procfs_open_file_constprop_0(long param_1,long param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined8 *)__kmalloc_cache_noprof(_capable,0x2dc0,0x38);
  if (puVar4 == (undefined8 *)0x0) {
    nv_printf(4,"NVRM: failed to allocate procfs private!\n");
    return 0xfffffff4;
  }
  puVar4[1] = 0x100000000;
  uVar1 = *(undefined8 *)(param_1 + 0x230);
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = uVar1;
  if ((*(byte *)(param_2 + 4) & 2) != 0) {
    cVar2 = rm_is_altstack_in_use();
    puVar5 = (undefined4 *)0x0;
    if (cVar2 != '\0') {
      puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar5 == (undefined4 *)0x0) goto LAB_0011a047;
      *puVar5 = 0x2ff0;
      *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    }
    iVar3 = os_alloc_mem(puVar4 + 5,0x200000);
    if (iVar3 != 0) {
LAB_0011a047:
      nv_procfs_close_file(puVar4);
      return 0xfffffff4;
    }
    os_mem_set(puVar4[5],0,0x200000);
    *puVar4 = puVar5;
  }
  *param_3 = puVar4;
  return 0;
}


// ===== 0011a070 __pfx_nv_procfs_open_unbind_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a168) */

int __pfx_nv_procfs_open_unbind_lock(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&uStack_40);
  uVar2 = uStack_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_unbind_lock,uStack_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a080 nv_procfs_open_unbind_lock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a168) */

int nv_procfs_open_unbind_lock(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&local_40);
  uVar2 = local_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_unbind_lock,local_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a1a0 __pfx_nv_procfs_read_lock_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a210) */
/* WARNING: Removing unreachable block (ram,0x0011a240) */

undefined8
__pfx_nv_procfs_read_lock_gpu_info
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a1b0 nv_procfs_read_lock_gpu_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a210) */
/* WARNING: Removing unreachable block (ram,0x0011a240) */

undefined8
nv_procfs_read_lock_gpu_info
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a250 __pfx_nv_procfs_read_lock_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a2c0) */
/* WARNING: Removing unreachable block (ram,0x0011a2f0) */

undefined8
__pfx_nv_procfs_read_lock_power
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a260 nv_procfs_read_lock_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a2c0) */
/* WARNING: Removing unreachable block (ram,0x0011a2f0) */

undefined8
nv_procfs_read_lock_power
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a300 __pfx_nv_procfs_read_lock_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a370) */
/* WARNING: Removing unreachable block (ram,0x0011a3a0) */

undefined8
__pfx_nv_procfs_read_lock_version
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a310 nv_procfs_read_lock_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a370) */
/* WARNING: Removing unreachable block (ram,0x0011a3a0) */

undefined8
nv_procfs_read_lock_version
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a3b0 __pfx_nv_procfs_read_lock_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a420) */
/* WARNING: Removing unreachable block (ram,0x0011a450) */

undefined8
__pfx_nv_procfs_read_lock_params
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a3c0 nv_procfs_read_lock_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a420) */
/* WARNING: Removing unreachable block (ram,0x0011a450) */

undefined8
nv_procfs_read_lock_params
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a460 __pfx_nv_procfs_read_lock_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a4d0) */
/* WARNING: Removing unreachable block (ram,0x0011a500) */

undefined8
__pfx_nv_procfs_read_lock_text_file
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a470 nv_procfs_read_lock_text_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a4d0) */
/* WARNING: Removing unreachable block (ram,0x0011a500) */

undefined8
nv_procfs_read_lock_text_file
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0011a510 __pfx_nv_procfs_open_registry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a608) */

int __pfx_nv_procfs_open_registry(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&uStack_40);
  uVar2 = uStack_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_registry,uStack_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a520 nv_procfs_open_registry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a608) */

int nv_procfs_open_registry(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&local_40);
  uVar2 = local_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_registry,local_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a640 __pfx_nv_procfs_open_offline_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a738) */

int __pfx_nv_procfs_open_offline_pages(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&uStack_40);
  uVar2 = uStack_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_offline_pages,uStack_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a650 nv_procfs_open_offline_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a738) */

int nv_procfs_open_offline_pages(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&local_40);
  uVar2 = local_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_offline_pages,local_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a770 __pfx_nv_procfs_open_numa_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a868) */

int __pfx_nv_procfs_open_numa_status(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&uStack_40);
  uVar2 = uStack_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_numa_status,uStack_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a780 nv_procfs_open_numa_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011a868) */

int nv_procfs_open_numa_status(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = 0;
  iVar3 = nv_procfs_open_file_constprop_0(param_1,param_2,&local_40);
  uVar2 = local_40;
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar4 = single_open(param_2,nv_procfs_read_numa_status,local_40);
    puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar4 < 0) {
      nv_procfs_close_file(uVar2);
      iVar3 = iVar4;
    }
    else {
      while (iVar4 = down_read_trylock(nv_system_pm_lock), iVar4 == 0) {
        if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
          iVar3 = -4;
          single_release(param_1,param_2);
          nv_procfs_close_file(uVar2);
          break;
        }
        __SCT__cond_resched();
      }
    }
  }
  else {
    iVar3 = -0xc;
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0011a8a0 __pfx_nv_procfs_add_warning =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_add_warning(undefined8 param_1,undefined8 param_2)

{
  proc_create_data(param_1,0x8124,proc_nvidia_warnings,nv_procfs_text_file_fops,param_2);
  return;
}


// ===== 0011a8b0 nv_procfs_add_warning =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_add_warning(undefined8 param_1,undefined8 param_2)

{
  proc_create_data(param_1,0x8124,proc_nvidia_warnings,nv_procfs_text_file_fops,param_2);
  return;
}


// ===== 0011a8e0 __pfx_nv_procfs_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ab45) */

undefined8 __pfx_nv_procfs_init(void)

{
  long lVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  char acStack_24 [16];
  uint uStack_14;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11a8f9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  acStack_24[0] = '\0';
  acStack_24[1] = '\0';
  acStack_24[2] = '\0';
  acStack_24[3] = '\0';
  acStack_24[4] = '\0';
  acStack_24[5] = '\0';
  acStack_24[6] = '\0';
  acStack_24[7] = '\0';
  acStack_24[8] = '\0';
  acStack_24[9] = '\0';
  acStack_24[10] = '\0';
  acStack_24[0xb] = '\0';
  acStack_24[0xc] = '\0';
  acStack_24[0xd] = '\0';
  acStack_24[0xe] = '\0';
  acStack_24[0xf] = '\0';
  uStack_14 = 0;
  snprintf(acStack_24,0x14,"driver/%s",nv_device_name);
  uStack_14 = uStack_14 & 0xffffff;
  proc_nvidia = proc_mkdir_mode(acStack_24,0x416d,0);
  if (((((proc_nvidia != 0) &&
        (lVar1 = proc_create_data("params",0x8124,proc_nvidia,nv_procfs_params_fops,0), lVar1 != 0))
       && (lVar1 = proc_create_data("registry",
                                    (-(ushort)(nv_procfs_registry_fops._32_8_ == 0) & 0xff80) +
                                    0x81a4,proc_nvidia,nv_procfs_registry_fops,0), lVar1 != 0)) &&
      (lVar1 = proc_create_data("suspend_depth",
                                (-(ushort)(nv_procfs_suspend_depth_fops._32_8_ == 0) & 0xff80) +
                                0x81a4,proc_nvidia,nv_procfs_suspend_depth_fops,0), lVar1 != 0)) &&
     (((NVreg_UseKernelSuspendNotifiers != 0 ||
       (lVar1 = proc_create_data("suspend",
                                 (-(ushort)(nv_procfs_suspend_fops._32_8_ == 0) & 0xff80) + 0x81a4,
                                 proc_nvidia,nv_procfs_suspend_fops,0), lVar1 != 0)) &&
      (proc_nvidia_warnings = proc_mkdir_mode("warnings",0x416d,proc_nvidia),
      proc_nvidia_warnings != 0)))) {
    proc_create_data("README",0x8124,proc_nvidia_warnings,nv_procfs_text_file_fops,
                     "The NVIDIA graphics driver tries to detect potential problems\nwith the host system and warns about them using the system\'s\nlogging mechanisms. Important warning message are also logged\nto dedicated text files in this directory.\n"
                    );
    proc_nvidia_patches = proc_mkdir_mode("patches",0x416d,proc_nvidia);
    if (proc_nvidia_patches != 0) {
      proc_create_data("README",0x8124,proc_nvidia_patches,nv_procfs_text_file_fops,
                       "The NVIDIA graphics driver\'s kernel interface files can be\npatched to improve compatibility with new Linux kernels or to\nfix bugs in these files. When applied, each official patch\nprovides a short text file with a short description of itself\nin this directory.\n"
                      );
      lVar1 = proc_create_data("version",0x8124,proc_nvidia,nv_procfs_version_fops,0);
      if ((lVar1 != 0) &&
         (proc_nvidia_gpus = proc_mkdir_mode(&DAT_00daf5b2,0x416d), proc_nvidia_gpus != 0)) {
        uVar2 = 0;
        goto LAB_0011ab32;
      }
    }
  }
  proc_remove(proc_nvidia);
  uVar2 = 0xfffffff4;
LAB_0011ab32:
  if (lStack_10 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}


// ===== 0011a8f0 nv_procfs_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ab45) */

undefined8 nv_procfs_init(void)

{
  long lVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  char local_24 [16];
  uint local_14;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11a8f9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_24[0] = '\0';
  local_24[1] = '\0';
  local_24[2] = '\0';
  local_24[3] = '\0';
  local_24[4] = '\0';
  local_24[5] = '\0';
  local_24[6] = '\0';
  local_24[7] = '\0';
  local_24[8] = '\0';
  local_24[9] = '\0';
  local_24[10] = '\0';
  local_24[0xb] = '\0';
  local_24[0xc] = '\0';
  local_24[0xd] = '\0';
  local_24[0xe] = '\0';
  local_24[0xf] = '\0';
  local_14 = 0;
  snprintf(local_24,0x14,"driver/%s",nv_device_name);
  local_14 = local_14 & 0xffffff;
  proc_nvidia = proc_mkdir_mode(local_24,0x416d,0);
  if (((((proc_nvidia != 0) &&
        (lVar1 = proc_create_data("params",0x8124,proc_nvidia,nv_procfs_params_fops,0), lVar1 != 0))
       && (lVar1 = proc_create_data("registry",
                                    (-(ushort)(nv_procfs_registry_fops._32_8_ == 0) & 0xff80) +
                                    0x81a4,proc_nvidia,nv_procfs_registry_fops,0), lVar1 != 0)) &&
      (lVar1 = proc_create_data("suspend_depth",
                                (-(ushort)(nv_procfs_suspend_depth_fops._32_8_ == 0) & 0xff80) +
                                0x81a4,proc_nvidia,nv_procfs_suspend_depth_fops,0), lVar1 != 0)) &&
     (((NVreg_UseKernelSuspendNotifiers != 0 ||
       (lVar1 = proc_create_data("suspend",
                                 (-(ushort)(nv_procfs_suspend_fops._32_8_ == 0) & 0xff80) + 0x81a4,
                                 proc_nvidia,nv_procfs_suspend_fops,0), lVar1 != 0)) &&
      (proc_nvidia_warnings = proc_mkdir_mode("warnings",0x416d,proc_nvidia),
      proc_nvidia_warnings != 0)))) {
    proc_create_data("README",0x8124,proc_nvidia_warnings,nv_procfs_text_file_fops,
                     "The NVIDIA graphics driver tries to detect potential problems\nwith the host system and warns about them using the system\'s\nlogging mechanisms. Important warning message are also logged\nto dedicated text files in this directory.\n"
                    );
    proc_nvidia_patches = proc_mkdir_mode("patches",0x416d,proc_nvidia);
    if (proc_nvidia_patches != 0) {
      proc_create_data("README",0x8124,proc_nvidia_patches,nv_procfs_text_file_fops,
                       "The NVIDIA graphics driver\'s kernel interface files can be\npatched to improve compatibility with new Linux kernels or to\nfix bugs in these files. When applied, each official patch\nprovides a short text file with a short description of itself\nin this directory.\n"
                      );
      lVar1 = proc_create_data("version",0x8124,proc_nvidia,nv_procfs_version_fops,0);
      if ((lVar1 != 0) &&
         (proc_nvidia_gpus = proc_mkdir_mode(&DAT_00daf5b2,0x416d), proc_nvidia_gpus != 0)) {
        uVar2 = 0;
        goto LAB_0011ab32;
      }
    }
  }
  proc_remove(proc_nvidia);
  uVar2 = 0xfffffff4;
LAB_0011ab32:
  if (local_10 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}


// ===== 0011ab70 __pfx_nv_procfs_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_exit(void)

{
  proc_remove(proc_nvidia);
  return;
}


// ===== 0011ab80 nv_procfs_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_exit(void)

{
  proc_remove(proc_nvidia);
  return;
}


// ===== 0011aba0 __pfx_nv_procfs_add_gpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ad15) */

undefined8 __pfx_nv_procfs_add_gpu(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  char acStack_40 [32];
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  acStack_40[0] = '\0';
  acStack_40[1] = '\0';
  acStack_40[2] = '\0';
  acStack_40[3] = '\0';
  acStack_40[4] = '\0';
  acStack_40[5] = '\0';
  acStack_40[6] = '\0';
  acStack_40[7] = '\0';
  acStack_40[8] = '\0';
  acStack_40[9] = '\0';
  acStack_40[10] = '\0';
  acStack_40[0xb] = '\0';
  acStack_40[0xc] = '\0';
  acStack_40[0xd] = '\0';
  acStack_40[0xe] = '\0';
  acStack_40[0xf] = '\0';
  acStack_40[0x10] = '\0';
  acStack_40[0x11] = '\0';
  acStack_40[0x12] = '\0';
  acStack_40[0x13] = '\0';
  acStack_40[0x14] = '\0';
  acStack_40[0x15] = '\0';
  acStack_40[0x16] = '\0';
  acStack_40[0x17] = '\0';
  acStack_40[0x18] = '\0';
  acStack_40[0x19] = '\0';
  acStack_40[0x1a] = '\0';
  acStack_40[0x1b] = '\0';
  acStack_40[0x1c] = '\0';
  acStack_40[0x1d] = '\0';
  acStack_40[0x1e] = '\0';
  acStack_40[0x1f] = '\0';
  snprintf(acStack_40,0x20,"%04x:%02x:%02x.%1x",(ulong)*(uint *)(param_1 + 0x14),
           (ulong)*(byte *)(param_1 + 0x18),(ulong)*(byte *)(param_1 + 0x19),
           (ulong)(*(uint *)(*(long *)(param_1 + 0x3b8) + 0x38) & 7));
  lVar2 = proc_mkdir_mode(acStack_40,0x416d,proc_nvidia_gpus);
  if (lVar2 != 0) {
    lVar3 = proc_create_data("information",0x8124,lVar2,nv_procfs_gpu_info_fops,param_1);
    if (((((lVar3 != 0) &&
          (lVar3 = proc_create_data("registry",
                                    (-(ushort)(nv_procfs_registry_fops._32_8_ == 0) & 0xff80) +
                                    0x81a4,lVar2,nv_procfs_registry_fops,param_1), lVar3 != 0)) &&
         (lVar3 = proc_create_data("power",0x8124,lVar2,nv_procfs_power_fops,param_1), lVar3 != 0))
        && ((cVar1 = os_is_vgx_hyper(), cVar1 == '\0' ||
            (lVar3 = proc_create_data("unbindLock",
                                      (-(ushort)(nv_procfs_unbind_lock_fops._32_8_ == 0) & 0xff80) +
                                      0x81a4,lVar2,nv_procfs_unbind_lock_fops,param_1), lVar3 != 0))
           )) && (((*(int *)(param_1 + 0x4a0) == -1 || (*(int *)(param_1 + 0x4a4) == 0)) ||
                  ((lVar3 = proc_create_data("numa_status",0x81a4,lVar2,nv_procfs_numa_status_fops,
                                             param_1), lVar3 != 0 &&
                   (lVar3 = proc_create_data("offline_pages",0x8124,lVar2,
                                             nv_procfs_offline_pages_fops,param_1), lVar3 != 0))))))
    {
      *(long *)(param_1 + 0x748) = lVar2;
      uVar4 = 0;
      goto LAB_0011acf9;
    }
    proc_remove(lVar2);
  }
  uVar4 = 0xffffffff;
LAB_0011acf9:
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 0011abb0 nv_procfs_add_gpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ad15) */

undefined8 nv_procfs_add_gpu(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  char local_40 [32];
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  local_40[0x10] = '\0';
  local_40[0x11] = '\0';
  local_40[0x12] = '\0';
  local_40[0x13] = '\0';
  local_40[0x14] = '\0';
  local_40[0x15] = '\0';
  local_40[0x16] = '\0';
  local_40[0x17] = '\0';
  local_40[0x18] = '\0';
  local_40[0x19] = '\0';
  local_40[0x1a] = '\0';
  local_40[0x1b] = '\0';
  local_40[0x1c] = '\0';
  local_40[0x1d] = '\0';
  local_40[0x1e] = '\0';
  local_40[0x1f] = '\0';
  snprintf(local_40,0x20,"%04x:%02x:%02x.%1x",(ulong)*(uint *)(param_1 + 0x14),
           (ulong)*(byte *)(param_1 + 0x18),(ulong)*(byte *)(param_1 + 0x19),
           (ulong)(*(uint *)(*(long *)(param_1 + 0x3b8) + 0x38) & 7));
  lVar2 = proc_mkdir_mode(local_40,0x416d,proc_nvidia_gpus);
  if (lVar2 != 0) {
    lVar3 = proc_create_data("information",0x8124,lVar2,nv_procfs_gpu_info_fops,param_1);
    if (((((lVar3 != 0) &&
          (lVar3 = proc_create_data("registry",
                                    (-(ushort)(nv_procfs_registry_fops._32_8_ == 0) & 0xff80) +
                                    0x81a4,lVar2,nv_procfs_registry_fops,param_1), lVar3 != 0)) &&
         (lVar3 = proc_create_data("power",0x8124,lVar2,nv_procfs_power_fops,param_1), lVar3 != 0))
        && ((cVar1 = os_is_vgx_hyper(), cVar1 == '\0' ||
            (lVar3 = proc_create_data("unbindLock",
                                      (-(ushort)(nv_procfs_unbind_lock_fops._32_8_ == 0) & 0xff80) +
                                      0x81a4,lVar2,nv_procfs_unbind_lock_fops,param_1), lVar3 != 0))
           )) && (((*(int *)(param_1 + 0x4a0) == -1 || (*(int *)(param_1 + 0x4a4) == 0)) ||
                  ((lVar3 = proc_create_data("numa_status",0x81a4,lVar2,nv_procfs_numa_status_fops,
                                             param_1), lVar3 != 0 &&
                   (lVar3 = proc_create_data("offline_pages",0x8124,lVar2,
                                             nv_procfs_offline_pages_fops,param_1), lVar3 != 0))))))
    {
      *(long *)(param_1 + 0x748) = lVar2;
      uVar4 = 0;
      goto LAB_0011acf9;
    }
    proc_remove(lVar2);
  }
  uVar4 = 0xffffffff;
LAB_0011acf9:
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 0011adc0 __pfx_nv_procfs_remove_gpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_remove_gpu(long param_1)

{
  proc_remove(*(undefined8 *)(param_1 + 0x748));
  return;
}


// ===== 0011add0 nv_procfs_remove_gpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_remove_gpu(long param_1)

{
  proc_remove(*(undefined8 *)(param_1 + 0x748));
  return;
}


// ===== 0011adf0 __pfx_nv_add_mapping_context_to_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011aed2) */

int __pfx_nv_add_mapping_context_to_file
              (long param_1,long param_2,undefined4 param_3,long param_4,long param_5,
              undefined4 param_6)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long in_GS_OFFSET;
  long *plStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 8);
  plStack_50 = (long *)0x0;
  uStack_48 = 0;
  lVar6 = nv_get_file_private(param_6,*(uint *)(param_1 + 0x10) & 4,&uStack_48);
  if (lVar6 == 0) {
    iVar5 = 0x1f;
    goto LAB_0011aea5;
  }
  iVar4 = os_alloc_mem(&plStack_50,0x70);
  plVar3 = plStack_50;
  iVar5 = iVar4;
  if (iVar4 == 0) {
    os_mem_set(plStack_50,0,0x70);
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      if (*(long *)(lVar6 + 0x80) == param_1) {
        iVar5 = os_alloc_mem(plVar3 + 4,*(long *)(param_2 + 0x30) << 4);
        if (iVar5 == 0) {
          lVar2 = *(long *)(param_2 + 0x30);
          plVar3[5] = lVar2;
          os_mem_copy(plVar3[4],*(undefined8 *)(param_2 + 0x28),(int)lVar2 << 4);
          if ((*(int *)(lVar1 + 0x4a0) != -1) && (*(int *)(lVar1 + 0x4a4) == 3)) {
            plVar3[2] = *(long *)(param_2 + 0x18);
            plVar3[3] = *(long *)(param_2 + 0x20);
          }
          plVar3[6] = *(long *)(param_2 + 0x38);
          plVar3[7] = *(long *)(param_2 + 0x40);
          goto LAB_0011af02;
        }
        os_free_mem(plStack_50);
        plVar3[4] = 0;
      }
      else {
        iVar5 = 0x1f;
      }
    }
    else {
      *plVar3 = param_4;
      plVar3[1] = param_5;
LAB_0011af02:
      *(undefined1 *)((long)plVar3 + 0x44) = 1;
      *(undefined4 *)(plVar3 + 8) = param_3;
      *(undefined4 *)(plVar3 + 9) = *(undefined4 *)(param_2 + 0x4c);
      plVar7 = (long *)nv_acquire_file_va(lVar6,1);
      if (*plVar7 == 0) {
        *plVar7 = (long)plStack_50;
        iVar5 = iVar4;
        if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
          LOCK();
          *(long *)(*plVar3 + 0x10) = *(long *)(*plVar3 + 0x10) + 1;
          UNLOCK();
        }
      }
      else {
        if (plVar3[4] != 0) {
          os_free_mem();
        }
        os_free_mem(plStack_50);
        iVar5 = 99;
      }
      nv_release_file_va(lVar6,1);
    }
  }
  nv_put_file_private(uStack_48);
LAB_0011aea5:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011ae00 nv_add_mapping_context_to_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011aed2) */

int nv_add_mapping_context_to_file
              (long param_1,long param_2,undefined4 param_3,long param_4,long param_5,
              undefined4 param_6)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long in_GS_OFFSET;
  long *local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 8);
  local_50 = (long *)0x0;
  local_48 = 0;
  lVar6 = nv_get_file_private(param_6,*(uint *)(param_1 + 0x10) & 4,&local_48);
  if (lVar6 == 0) {
    iVar5 = 0x1f;
    goto LAB_0011aea5;
  }
  iVar4 = os_alloc_mem(&local_50,0x70);
  plVar3 = local_50;
  iVar5 = iVar4;
  if (iVar4 == 0) {
    os_mem_set(local_50,0,0x70);
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      if (*(long *)(lVar6 + 0x80) == param_1) {
        iVar5 = os_alloc_mem(plVar3 + 4,*(long *)(param_2 + 0x30) << 4);
        if (iVar5 == 0) {
          lVar2 = *(long *)(param_2 + 0x30);
          plVar3[5] = lVar2;
          os_mem_copy(plVar3[4],*(undefined8 *)(param_2 + 0x28),(int)lVar2 << 4);
          if ((*(int *)(lVar1 + 0x4a0) != -1) && (*(int *)(lVar1 + 0x4a4) == 3)) {
            plVar3[2] = *(long *)(param_2 + 0x18);
            plVar3[3] = *(long *)(param_2 + 0x20);
          }
          plVar3[6] = *(long *)(param_2 + 0x38);
          plVar3[7] = *(long *)(param_2 + 0x40);
          goto LAB_0011af02;
        }
        os_free_mem(local_50);
        plVar3[4] = 0;
      }
      else {
        iVar5 = 0x1f;
      }
    }
    else {
      *plVar3 = param_4;
      plVar3[1] = param_5;
LAB_0011af02:
      *(undefined1 *)((long)plVar3 + 0x44) = 1;
      *(undefined4 *)(plVar3 + 8) = param_3;
      *(undefined4 *)(plVar3 + 9) = *(undefined4 *)(param_2 + 0x4c);
      plVar7 = (long *)nv_acquire_file_va(lVar6,1);
      if (*plVar7 == 0) {
        *plVar7 = (long)local_50;
        iVar5 = iVar4;
        if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
          LOCK();
          *(long *)(*plVar3 + 0x10) = *(long *)(*plVar3 + 0x10) + 1;
          UNLOCK();
        }
      }
      else {
        if (plVar3[4] != 0) {
          os_free_mem();
        }
        os_free_mem(local_50);
        iVar5 = 99;
      }
      nv_release_file_va(lVar6,1);
    }
  }
  nv_put_file_private(local_48);
LAB_0011aea5:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011b040 __pfx_nv_alloc_user_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b079) */
/* WARNING: Removing unreachable block (ram,0x0011b090) */

undefined8 __pfx_nv_alloc_user_mapping(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  long *unaff_retaddr;
  
  if ((*(byte *)(param_2 + 0x18) & 1) != 0) {
    *unaff_retaddr = (ulong)param_4 + param_3 * 0x1000 + **(long **)(param_2 + 0x30);
    return 0;
  }
  *unaff_retaddr = (ulong)param_4 + (*(long **)(param_2 + 0x30))[param_3 * 2];
  return 0;
}


// ===== 0011b050 nv_alloc_user_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b079) */
/* WARNING: Removing unreachable block (ram,0x0011b090) */

undefined8 nv_alloc_user_mapping(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  long *unaff_retaddr;
  
  if ((*(byte *)(param_2 + 0x18) & 1) != 0) {
    *unaff_retaddr = (ulong)param_4 + param_3 * 0x1000 + **(long **)(param_2 + 0x30);
    return 0;
  }
  *unaff_retaddr = (ulong)param_4 + (*(long **)(param_2 + 0x30))[param_3 * 2];
  return 0;
}


// ===== 0011b0a0 __pfx_nv_free_user_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b0b9) */

void __pfx_nv_free_user_mapping(void)

{
  return;
}


// ===== 0011b0b0 nv_free_user_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b0b9) */

void nv_free_user_mapping(void)

{
  return;
}


// ===== 0011b0c0 __pfx_nv_mem_pool_shrinker_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b0fc) */
/* WARNING: Removing unreachable block (ram,0x0011b16b) */

long __pfx_nv_mem_pool_shrinker_count(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = -2;
  lVar1 = *(long *)(param_1 + 0x58);
  if (*(int *)(param_2 + 4) == *(int *)(lVar1 + 0x88)) {
    iVar2 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x98));
    lVar3 = 0;
    if (iVar2 == 0) {
      lVar3 = *(long *)(lVar1 + 0x90);
      os_release_mutex(*(undefined8 *)(lVar1 + 0x98));
      nv_printf(0,"NVRM: VM: %s: node=%d order=%u: %lu pages in pool\n","nv_mem_pool_shrinker_count"
                ,*(undefined4 *)(lVar1 + 0x88),*(undefined4 *)(lVar1 + 0x8c),lVar3);
      if (lVar3 == 0) {
        lVar3 = -2;
      }
      return lVar3;
    }
  }
  return lVar3;
}


// ===== 0011b0d0 nv_mem_pool_shrinker_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b0fc) */
/* WARNING: Removing unreachable block (ram,0x0011b16b) */

long nv_mem_pool_shrinker_count(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = -2;
  lVar1 = *(long *)(param_1 + 0x58);
  if (*(int *)(param_2 + 4) == *(int *)(lVar1 + 0x88)) {
    iVar2 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x98));
    lVar3 = 0;
    if (iVar2 == 0) {
      lVar3 = *(long *)(lVar1 + 0x90);
      os_release_mutex(*(undefined8 *)(lVar1 + 0x98));
      nv_printf(0,"NVRM: VM: %s: node=%d order=%u: %lu pages in pool\n","nv_mem_pool_shrinker_count"
                ,*(undefined4 *)(lVar1 + 0x88),*(undefined4 *)(lVar1 + 0x8c),lVar3);
      if (lVar3 == 0) {
        lVar3 = -2;
      }
      return lVar3;
    }
  }
  return lVar3;
}


// ===== 0011b170 __pfx_nv_alloc_set_page =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b22f) */

void __pfx_nv_alloc_set_page(long param_1,int param_2,long param_3)

{
  long lVar1;
  long lVar2;
  byte bVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  
  lVar2 = nv_get_kern_phys_address(param_3);
  bVar3 = (byte)*(undefined4 *)(param_1 + 0x24);
  uVar5 = param_2 << (bVar3 & 0x1f);
  uVar8 = 1 << (bVar3 & 0x1f);
  uVar6 = *(int *)(param_1 + 0x20) - uVar5;
  if (uVar8 < uVar6) {
    uVar6 = uVar8;
  }
  if (uVar6 != 0) {
    lVar7 = (ulong)uVar6 * 0x1000 + param_3;
    lVar2 = lVar2 - param_3;
    do {
      uVar4 = (ulong)uVar5;
      lVar1 = lVar2 + param_3;
      uVar5 = uVar5 + 1;
      *(long *)(*(long *)(param_1 + 0x30) + 8 + uVar4 * 0x10) = param_3;
      param_3 = param_3 + 0x1000;
      *(long *)(*(long *)(param_1 + 0x30) + uVar4 * 0x10) = lVar1;
    } while (lVar7 != param_3);
  }
  return;
}


// ===== 0011b180 nv_alloc_set_page =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b22f) */

void nv_alloc_set_page(long param_1,int param_2,long param_3)

{
  long lVar1;
  long lVar2;
  byte bVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  
  lVar2 = nv_get_kern_phys_address(param_3);
  bVar3 = (byte)*(undefined4 *)(param_1 + 0x24);
  uVar5 = param_2 << (bVar3 & 0x1f);
  uVar8 = 1 << (bVar3 & 0x1f);
  uVar6 = *(int *)(param_1 + 0x20) - uVar5;
  if (uVar8 < uVar6) {
    uVar6 = uVar8;
  }
  if (uVar6 != 0) {
    lVar7 = (ulong)uVar6 * 0x1000 + param_3;
    lVar2 = lVar2 - param_3;
    do {
      uVar4 = (ulong)uVar5;
      lVar1 = lVar2 + param_3;
      uVar5 = uVar5 + 1;
      *(long *)(*(long *)(param_1 + 0x30) + 8 + uVar4 * 0x10) = param_3;
      param_3 = param_3 + 0x1000;
      *(long *)(*(long *)(param_1 + 0x30) + uVar4 * 0x10) = lVar1;
    } while (lVar7 != param_3);
  }
  return;
}


// ===== 0011b240 __pfx_nv_compute_gfp_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b394) */

uint __pfx_nv_compute_gfp_mask(long param_1,long param_2)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  
  lVar1 = *(long *)(param_2 + 8);
  if (param_1 == 0) {
LAB_0011b283:
    uVar5 = _find_first_bit(__release_region,0x400);
    if (uVar5 < 0x400) {
      if (0x400 < uVar5) {
        uVar5 = 0x400;
      }
      uVar8 = 0;
      do {
        uVar7 = *(long *)(*(long *)(&node_data + (uVar5 & 0xffffffff) * 8) + 0x2a478) +
                *(long *)(*(long *)(&node_data + (uVar5 & 0xffffffff) * 8) + 0x2a468);
        if (uVar8 < uVar7) {
          uVar8 = uVar7;
        }
        uVar7 = _find_next_bit(__release_region,0x400,(int)uVar5 + 1);
        uVar5 = 0x400;
        if (uVar7 < 0x401) {
          uVar5 = uVar7;
        }
      } while (uVar7 < 0x400);
      uVar5 = uVar8 * 0x1000 + 0xfff;
    }
    else {
      uVar5 = 0xfff;
    }
    if ((((lVar1 != 0) && (puVar2 = *(ulong **)(lVar1 + 0x260), puVar2 != (ulong *)0x0)) &&
        (*puVar2 < uVar5)) || ((param_1 != 0 && (*(char *)(param_1 + 0x300) != '\0')))) {
      uVar4 = 0x6cc4;
      uVar6 = 0x2cc4;
      goto LAB_0011b357;
    }
  }
  else {
    cVar3 = nv_requires_dma_remap();
    if ((cVar3 == '\0') || (*(char *)(param_1 + 0x300) != '\0')) goto LAB_0011b283;
  }
  uVar4 = 0x6cc0;
  uVar6 = 0x2cc0;
LAB_0011b357:
  if ((*(byte *)(param_2 + 0x18) & 4) != 0) {
    uVar4 = uVar6 | 0x4100;
  }
  if ((*(byte *)(param_2 + 0x18) & 0x20) != 0) {
    uVar4 = uVar4 | 0x200000;
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    uVar4 = uVar4 | 0x40000;
  }
  return uVar4;
}


// ===== 0011b250 nv_compute_gfp_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b394) */

uint nv_compute_gfp_mask(long param_1,long param_2)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  
  lVar1 = *(long *)(param_2 + 8);
  if (param_1 == 0) {
LAB_0011b283:
    uVar5 = _find_first_bit(__release_region,0x400);
    if (uVar5 < 0x400) {
      if (0x400 < uVar5) {
        uVar5 = 0x400;
      }
      uVar8 = 0;
      do {
        uVar7 = *(long *)(*(long *)(&node_data + (uVar5 & 0xffffffff) * 8) + 0x2a478) +
                *(long *)(*(long *)(&node_data + (uVar5 & 0xffffffff) * 8) + 0x2a468);
        if (uVar8 < uVar7) {
          uVar8 = uVar7;
        }
        uVar7 = _find_next_bit(__release_region,0x400,(int)uVar5 + 1);
        uVar5 = 0x400;
        if (uVar7 < 0x401) {
          uVar5 = uVar7;
        }
      } while (uVar7 < 0x400);
      uVar5 = uVar8 * 0x1000 + 0xfff;
    }
    else {
      uVar5 = 0xfff;
    }
    if ((((lVar1 != 0) && (puVar2 = *(ulong **)(lVar1 + 0x260), puVar2 != (ulong *)0x0)) &&
        (*puVar2 < uVar5)) || ((param_1 != 0 && (*(char *)(param_1 + 0x300) != '\0')))) {
      uVar4 = 0x6cc4;
      uVar6 = 0x2cc4;
      goto LAB_0011b357;
    }
  }
  else {
    cVar3 = nv_requires_dma_remap();
    if ((cVar3 == '\0') || (*(char *)(param_1 + 0x300) != '\0')) goto LAB_0011b283;
  }
  uVar4 = 0x6cc0;
  uVar6 = 0x2cc0;
LAB_0011b357:
  if ((*(byte *)(param_2 + 0x18) & 4) != 0) {
    uVar4 = uVar6 | 0x4100;
  }
  if ((*(byte *)(param_2 + 0x18) & 0x20) != 0) {
    uVar4 = uVar4 | 0x200000;
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    uVar4 = uVar4 | 0x40000;
  }
  return uVar4;
}


// ===== 0011b3b0 __pfx_nv_mem_pool_free_page_list =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b453) */
/* WARNING: Removing unreachable block (ram,0x0011b458) */

void __pfx_nv_mem_pool_free_page_list(undefined8 *param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_1 == (undefined8 *)*param_1) {
    return;
  }
  do {
    puVar4 = (undefined8 *)*param_1;
    puVar3 = puVar4 + -1;
    if (param_1 == puVar4) {
      puVar4 = (undefined8 *)&DAT_00000008;
      puVar3 = (undefined8 *)0x0;
    }
    plVar1 = (long *)puVar3[2];
    lVar2 = puVar3[1];
    if (((undefined8 *)*plVar1 == puVar4) && (puVar4 == *(undefined8 **)(lVar2 + 8))) {
      *(long **)(lVar2 + 8) = plVar1;
      *plVar1 = lVar2;
    }
    else {
      __list_del_entry_valid_or_report();
    }
    puVar3[1] = 0xdead000000000100;
    puVar3[2] = 0xdead000000000122;
    free_pages(*puVar3,param_2);
    kfree(puVar3);
  } while (param_1 != (undefined8 *)*param_1);
  return;
}


// ===== 0011b3c0 nv_mem_pool_free_page_list =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b453) */
/* WARNING: Removing unreachable block (ram,0x0011b458) */

void nv_mem_pool_free_page_list(undefined8 *param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_1 == (undefined8 *)*param_1) {
    return;
  }
  do {
    puVar4 = (undefined8 *)*param_1;
    puVar3 = puVar4 + -1;
    if (param_1 == puVar4) {
      puVar4 = (undefined8 *)&DAT_00000008;
      puVar3 = (undefined8 *)0x0;
    }
    plVar1 = (long *)puVar3[2];
    lVar2 = puVar3[1];
    if (((undefined8 *)*plVar1 == puVar4) && (puVar4 == *(undefined8 **)(lVar2 + 8))) {
      *(long **)(lVar2 + 8) = plVar1;
      *plVar1 = lVar2;
    }
    else {
      __list_del_entry_valid_or_report();
    }
    puVar3[1] = 0xdead000000000100;
    puVar3[2] = 0xdead000000000122;
    free_pages(*puVar3,param_2);
    kfree(puVar3);
  } while (param_1 != (undefined8 *)*param_1);
  return;
}


// ===== 0011b460 __pfx_nv_mem_pool_move_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b53a) */
/* WARNING: Removing unreachable block (ram,0x0011b532) */
/* WARNING: Removing unreachable block (ram,0x0011b527) */
/* WARNING: Removing unreachable block (ram,0x0011b541) */

long __pfx_nv_mem_pool_move_pages(long *param_1,long *param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  if (param_3 == 0) {
    return 0;
  }
  plVar3 = (long *)*param_2;
  if ((param_2 != plVar3) && (plVar3 != (long *)&DAT_00000008)) {
    while( true ) {
      plVar1 = (long *)plVar3[1];
      lVar2 = *plVar3;
      if ((plVar3 == (long *)*plVar1) && (plVar3 == *(long **)(lVar2 + 8))) {
        *(long **)(lVar2 + 8) = plVar1;
        *plVar1 = lVar2;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      *plVar3 = -0x2152ffffffffff00;
      plVar3[1] = -0x2152fffffffffede;
      plVar1 = (long *)*param_1;
      if (((param_1 == (long *)plVar1[1]) && (plVar3 != param_1)) && (plVar3 != plVar1)) {
        plVar1[1] = (long)plVar3;
        *plVar3 = (long)plVar1;
        plVar3[1] = (long)param_1;
        *param_1 = (long)plVar3;
      }
      else {
        __list_add_valid_or_report(plVar3,param_1);
      }
      param_3 = param_3 + -1;
      if (param_3 == 0) break;
      plVar3 = (long *)*param_2;
      if ((param_2 == plVar3) || (plVar3 == (long *)&DAT_00000008)) {
        return param_3;
      }
    }
    return 0;
  }
  return param_3;
}


// ===== 0011b470 nv_mem_pool_move_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b53a) */
/* WARNING: Removing unreachable block (ram,0x0011b532) */
/* WARNING: Removing unreachable block (ram,0x0011b527) */
/* WARNING: Removing unreachable block (ram,0x0011b541) */

long nv_mem_pool_move_pages(long *param_1,long *param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  if (param_3 == 0) {
    return 0;
  }
  plVar3 = (long *)*param_2;
  if ((param_2 != plVar3) && (plVar3 != (long *)&DAT_00000008)) {
    while( true ) {
      plVar1 = (long *)plVar3[1];
      lVar2 = *plVar3;
      if ((plVar3 == (long *)*plVar1) && (plVar3 == *(long **)(lVar2 + 8))) {
        *(long **)(lVar2 + 8) = plVar1;
        *plVar1 = lVar2;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      *plVar3 = -0x2152ffffffffff00;
      plVar3[1] = -0x2152fffffffffede;
      plVar1 = (long *)*param_1;
      if (((param_1 == (long *)plVar1[1]) && (plVar3 != param_1)) && (plVar3 != plVar1)) {
        plVar1[1] = (long)plVar3;
        *plVar3 = (long)plVar1;
        plVar3[1] = (long)param_1;
        *param_1 = (long)plVar3;
      }
      else {
        __list_add_valid_or_report(plVar3,param_1);
      }
      param_3 = param_3 + -1;
      if (param_3 == 0) break;
      plVar3 = (long *)*param_2;
      if ((param_2 == plVar3) || (plVar3 == (long *)&DAT_00000008)) {
        return param_3;
      }
    }
    return 0;
  }
  return param_3;
}


// ===== 0011b550 __pfx_nv_mem_pool_shrinker_scan =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b5c6) */

long __pfx_nv_mem_pool_shrinker_scan(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long in_GS_OFFSET;
  undefined8 ***pppuStack_30;
  undefined8 ***pppuStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 0x58);
  pppuStack_30 = (undefined8 ****)0x0;
  pppuStack_28 = (undefined8 ****)0x0;
  if (*(int *)(param_2 + 4) == *(int *)(lVar1 + 0x88)) {
    pppuStack_30 = &pppuStack_30;
    pppuStack_28 = pppuStack_30;
    iVar2 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x98));
    if (iVar2 == 0) {
      uVar3 = nv_mem_pool_move_pages(&pppuStack_30,lVar1 + 0x10,*(undefined8 *)(param_2 + 8));
      lVar4 = nv_mem_pool_move_pages(&pppuStack_30,lVar1,uVar3);
      lVar5 = *(long *)(param_2 + 8) - lVar4;
      *(long *)(lVar1 + 0x90) = (*(long *)(lVar1 + 0x90) - *(long *)(param_2 + 8)) + lVar4;
      os_release_mutex(*(undefined8 *)(lVar1 + 0x98));
      nv_mem_pool_free_page_list(&pppuStack_30,*(undefined4 *)(lVar1 + 0x8c));
      nv_printf(0,"NVRM: VM: %s: node=%d order=%u: %lu/%lu pages freed\n",
                "nv_mem_pool_shrinker_scan",*(undefined4 *)(lVar1 + 0x88),
                *(undefined4 *)(lVar1 + 0x8c),lVar5,*(undefined8 *)(param_2 + 8));
      if (lVar5 == 0) {
        lVar5 = -1;
      }
      goto LAB_0011b5a7;
    }
  }
  lVar5 = -1;
LAB_0011b5a7:
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}


// ===== 0011b560 nv_mem_pool_shrinker_scan =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b5c6) */

long nv_mem_pool_shrinker_scan(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long in_GS_OFFSET;
  undefined8 ***local_30;
  undefined8 ***local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 0x58);
  local_30 = (undefined8 ****)0x0;
  local_28 = (undefined8 ****)0x0;
  if (*(int *)(param_2 + 4) == *(int *)(lVar1 + 0x88)) {
    local_30 = &local_30;
    local_28 = local_30;
    iVar2 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x98));
    if (iVar2 == 0) {
      uVar3 = nv_mem_pool_move_pages(&local_30,lVar1 + 0x10,*(undefined8 *)(param_2 + 8));
      lVar4 = nv_mem_pool_move_pages(&local_30,lVar1,uVar3);
      lVar5 = *(long *)(param_2 + 8) - lVar4;
      *(long *)(lVar1 + 0x90) = (*(long *)(lVar1 + 0x90) - *(long *)(param_2 + 8)) + lVar4;
      os_release_mutex(*(undefined8 *)(lVar1 + 0x98));
      nv_mem_pool_free_page_list(&local_30,*(undefined4 *)(lVar1 + 0x8c));
      nv_printf(0,"NVRM: VM: %s: node=%d order=%u: %lu/%lu pages freed\n",
                "nv_mem_pool_shrinker_scan",*(undefined4 *)(lVar1 + 0x88),
                *(undefined4 *)(lVar1 + 0x8c),lVar5,*(undefined8 *)(param_2 + 8));
      if (lVar5 == 0) {
        lVar5 = -1;
      }
      goto LAB_0011b5a7;
    }
  }
  lVar5 = -1;
LAB_0011b5a7:
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}


// ===== 0011b6c0 __pfx_nv_mem_pool_worker =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_mem_pool_worker(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long extraout_RDX;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  iVar3 = os_acquire_mutex(param_1[0x13]);
  if (iVar3 != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  while (plVar6 = (long *)param_1[2], plVar6 != param_1 + 2) {
    while( true ) {
      if (plVar6 == (long *)&DAT_00000008) goto LAB_0011b7ff;
      plVar1 = (long *)plVar6[1];
      lVar5 = *plVar6;
      if ((plVar6 == (long *)*plVar1) && (plVar6 == *(long **)(lVar5 + 8))) {
        *(long **)(lVar5 + 8) = plVar1;
        *plVar1 = lVar5;
      }
      else {
        __list_del_entry_valid_or_report(plVar6);
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      os_release_mutex(param_1[0x13]);
      iVar3 = 1 << ((byte)*(undefined4 *)((long)param_1 + 0x8c) & 0x1f);
      if (iVar3 != 0) {
        lVar5 = plVar6[-1];
        lVar4 = (ulong)(iVar3 - 1) * 0x1000 + lVar5 + 0x1000;
        do {
          __clear_pages_unrolled(lVar5);
          lVar5 = extraout_RDX;
        } while (lVar4 != extraout_RDX);
      }
      iVar3 = os_acquire_mutex(param_1[0x13]);
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      plVar1 = (long *)*param_1;
      if (((param_1 != (long *)plVar1[1]) || (param_1 == plVar6)) || (plVar6 == plVar1)) break;
      plVar1[1] = (long)plVar6;
      *plVar6 = (long)plVar1;
      plVar6[1] = (long)param_1;
      *param_1 = (long)plVar6;
      plVar6 = (long *)param_1[2];
      if (plVar6 == param_1 + 2) goto LAB_0011b7ff;
    }
    __list_add_valid_or_report(plVar6,param_1);
  }
LAB_0011b7ff:
  os_release_mutex(param_1[0x13]);
  return;
}


// ===== 0011b6d0 nv_mem_pool_worker =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_mem_pool_worker(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long extraout_RDX;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  iVar3 = os_acquire_mutex(param_1[0x13]);
  if (iVar3 != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  while (plVar6 = (long *)param_1[2], plVar6 != param_1 + 2) {
    while( true ) {
      if (plVar6 == (long *)&DAT_00000008) goto LAB_0011b7ff;
      plVar1 = (long *)plVar6[1];
      lVar5 = *plVar6;
      if ((plVar6 == (long *)*plVar1) && (plVar6 == *(long **)(lVar5 + 8))) {
        *(long **)(lVar5 + 8) = plVar1;
        *plVar1 = lVar5;
      }
      else {
        __list_del_entry_valid_or_report(plVar6);
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      os_release_mutex(param_1[0x13]);
      iVar3 = 1 << ((byte)*(undefined4 *)((long)param_1 + 0x8c) & 0x1f);
      if (iVar3 != 0) {
        lVar5 = plVar6[-1];
        lVar4 = (ulong)(iVar3 - 1) * 0x1000 + lVar5 + 0x1000;
        do {
          __clear_pages_unrolled(lVar5);
          lVar5 = extraout_RDX;
        } while (lVar4 != extraout_RDX);
      }
      iVar3 = os_acquire_mutex(param_1[0x13]);
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      plVar1 = (long *)*param_1;
      if (((param_1 != (long *)plVar1[1]) || (param_1 == plVar6)) || (plVar6 == plVar1)) break;
      plVar1[1] = (long)plVar6;
      *plVar6 = (long)plVar1;
      plVar6[1] = (long)param_1;
      *param_1 = (long)plVar6;
      plVar6 = (long *)param_1[2];
      if (plVar6 == param_1 + 2) goto LAB_0011b7ff;
    }
    __list_add_valid_or_report(plVar6,param_1);
  }
LAB_0011b7ff:
  os_release_mutex(param_1[0x13]);
  return;
}


// ===== 0011b840 __pfx_nv_alloc_coherent_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b937) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_alloc_coherent_pages(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  long in_GS_OFFSET;
  long lStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (param_1 == 0) {
    nv_printf(0,"NVRM: VM: %s: coherent page alloc on nvidiactl not supported\n",
              "nv_alloc_coherent_pages");
    uVar4 = 0x56;
    goto LAB_0011b920;
  }
  uVar4 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0);
  uVar1 = nv_compute_gfp_mask();
  uVar3 = dma_alloc_attrs(uVar4,(ulong)*(uint *)(param_2 + 0x20) << 0xc,param_2 + 0x68,uVar1,0x100);
  if (uVar3 == 0) {
    nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_coherent_pages");
    uVar4 = 0x51;
    goto LAB_0011b920;
  }
  lVar9 = 0;
  uVar8 = uVar3 + 0x80000000;
  uVar7 = 0;
  if (*(int *)(param_2 + 0x20) != 0) {
    do {
      plVar5 = (long *)(lVar9 * 0x10 + *(long *)(param_2 + 0x30));
      lVar6 = -0x80000000 - _page_offset_base;
      if (uVar8 < uVar3) {
        lVar6 = _phys_base;
      }
      plVar5[1] = uVar3;
      lVar9 = lVar9 + 1;
      uVar3 = uVar3 + 0x1000;
      lVar6 = lVar6 + uVar8;
      uVar8 = uVar8 + 0x1000;
      *plVar5 = lVar6;
      uVar7 = *(uint *)(param_2 + 0x20);
    } while ((uint)lVar9 < uVar7);
  }
  if (*(int *)(param_2 + 0x1c) != 0) {
    lStack_28 = 0;
    if ((*(byte *)(param_2 + 0x18) & 1) == 0) {
      iVar2 = os_alloc_mem(&lStack_28,(ulong)uVar7 << 3);
      if (iVar2 == 0) {
        if (lStack_28 != 0) {
          if (*(int *)(param_2 + 0x20) == 0) {
            uVar7 = 0;
          }
          else {
            lVar9 = 0;
            do {
              *(ulong *)(lStack_28 + lVar9 * 8) =
                   (*(ulong *)(lVar9 * 0x10 + *(long *)(param_2 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar7 = *(uint *)(param_2 + 0x20);
              lVar9 = lVar9 + 1;
            } while ((uint)lVar9 < uVar7);
          }
          set_pages_array_uc(lStack_28,uVar7);
          os_free_mem(lStack_28);
          goto LAB_0011b910;
        }
      }
      else {
        lStack_28 = 0;
      }
      lVar9 = 0;
      if (*(int *)(param_2 + 0x20) != 0) {
        do {
          lVar6 = lVar9 + 1;
          set_memory_uc((*(ulong *)(lVar9 * 0x10 + *(long *)(param_2 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          lVar9 = lVar6;
        } while ((uint)lVar6 < *(uint *)(param_2 + 0x20));
      }
    }
    else {
      set_memory_uc((**(ulong **)(param_2 + 0x30) & 0xfffffffffffff000) + _page_offset_base,
                    (ulong)uVar7);
    }
  }
LAB_0011b910:
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 2;
  uVar4 = 0;
LAB_0011b920:
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 0011b850 nv_alloc_coherent_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011b937) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_alloc_coherent_pages(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  long in_GS_OFFSET;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (param_1 == 0) {
    nv_printf(0,"NVRM: VM: %s: coherent page alloc on nvidiactl not supported\n",
              "nv_alloc_coherent_pages");
    uVar4 = 0x56;
    goto LAB_0011b920;
  }
  uVar4 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0);
  uVar1 = nv_compute_gfp_mask();
  uVar3 = dma_alloc_attrs(uVar4,(ulong)*(uint *)(param_2 + 0x20) << 0xc,param_2 + 0x68,uVar1,0x100);
  if (uVar3 == 0) {
    nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_coherent_pages");
    uVar4 = 0x51;
    goto LAB_0011b920;
  }
  lVar9 = 0;
  uVar8 = uVar3 + 0x80000000;
  uVar7 = 0;
  if (*(int *)(param_2 + 0x20) != 0) {
    do {
      plVar5 = (long *)(lVar9 * 0x10 + *(long *)(param_2 + 0x30));
      lVar6 = -0x80000000 - _page_offset_base;
      if (uVar8 < uVar3) {
        lVar6 = _phys_base;
      }
      plVar5[1] = uVar3;
      lVar9 = lVar9 + 1;
      uVar3 = uVar3 + 0x1000;
      lVar6 = lVar6 + uVar8;
      uVar8 = uVar8 + 0x1000;
      *plVar5 = lVar6;
      uVar7 = *(uint *)(param_2 + 0x20);
    } while ((uint)lVar9 < uVar7);
  }
  if (*(int *)(param_2 + 0x1c) != 0) {
    local_28 = 0;
    if ((*(byte *)(param_2 + 0x18) & 1) == 0) {
      iVar2 = os_alloc_mem(&local_28,(ulong)uVar7 << 3);
      if (iVar2 == 0) {
        if (local_28 != 0) {
          if (*(int *)(param_2 + 0x20) == 0) {
            uVar7 = 0;
          }
          else {
            lVar9 = 0;
            do {
              *(ulong *)(local_28 + lVar9 * 8) =
                   (*(ulong *)(lVar9 * 0x10 + *(long *)(param_2 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar7 = *(uint *)(param_2 + 0x20);
              lVar9 = lVar9 + 1;
            } while ((uint)lVar9 < uVar7);
          }
          set_pages_array_uc(local_28,uVar7);
          os_free_mem(local_28);
          goto LAB_0011b910;
        }
      }
      else {
        local_28 = 0;
      }
      lVar9 = 0;
      if (*(int *)(param_2 + 0x20) != 0) {
        do {
          lVar6 = lVar9 + 1;
          set_memory_uc((*(ulong *)(lVar9 * 0x10 + *(long *)(param_2 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          lVar9 = lVar6;
        } while ((uint)lVar6 < *(uint *)(param_2 + 0x20));
      }
    }
    else {
      set_memory_uc((**(ulong **)(param_2 + 0x30) & 0xfffffffffffff000) + _page_offset_base,
                    (ulong)uVar7);
    }
  }
LAB_0011b910:
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 2;
  uVar4 = 0;
LAB_0011b920:
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 0011ba90 __pfx_nv_mem_pool_alloc_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011bb2e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __pfx_nv_mem_pool_alloc_pages(long param_1,long param_2)

{
  long ****pppplVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  long extraout_RDX;
  long ****pppplVar8;
  long extraout_RDX_00;
  long extraout_RDX_01;
  uint uVar9;
  long lVar10;
  long ****pppplVar11;
  long *****ppppplVar12;
  long in_GS_OFFSET;
  undefined1 auVar13 [12];
  uint uStack_7c;
  long ****pppplStack_60;
  long ****pppplStack_58;
  long ****pppplStack_50;
  long ****pppplStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  bVar7 = (byte)*(undefined4 *)(param_2 + 0x24);
  pppplStack_60 = (long ****)0x0;
  pppplStack_58 = (long ****)0x0;
  pppplStack_50 = (long ****)0x0;
  pppplStack_48 = (long ****)0x0;
  auVar13 = (*_mpi_powm)(param_1,param_2,*(undefined4 *)(param_2 + 0x20));
  if (((auVar13._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    uStack_7c = 0;
  }
  else {
    uVar3 = (uint)(auVar13._8_4_ + -1 + (1 << (bVar7 & 0x1f))) >> (bVar7 & 0x1f);
    pppplStack_50 = (long ****)&pppplStack_50;
    pppplStack_60 = (long ****)&pppplStack_60;
    pppplStack_58 = (long ****)&pppplStack_60;
    pppplStack_48 = pppplStack_50;
    iVar4 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    iVar4 = nv_mem_pool_move_pages(&pppplStack_60,param_1);
    iVar5 = nv_mem_pool_move_pages(&pppplStack_50,param_1 + 0x10,iVar4);
    uStack_7c = uVar3 - iVar5;
    lVar10 = *(long *)(param_1 + 0x90) - (ulong)uStack_7c;
    *(long *)(param_1 + 0x90) = lVar10;
    uVar9 = 0;
    os_release_mutex(*(undefined8 *)(param_1 + 0x98));
    ppppplVar12 = (long *****)pppplStack_60;
    while ((pppplStack_60 = (long ****)ppppplVar12, ppppplVar12 != &pppplStack_60 &&
           (ppppplVar12 + -1 != (long *****)0x0))) {
      nv_alloc_set_page(param_2,uVar9,ppppplVar12[-1]);
      pppplVar1 = ppppplVar12[1];
      pppplVar8 = *ppppplVar12;
      if ((ppppplVar12 == (long *****)*pppplVar1) && (ppppplVar12 == (long *****)pppplVar8[1])) {
        pppplVar8[1] = (long ***)pppplVar1;
        *pppplVar1 = (long ***)pppplVar8;
      }
      else {
        __list_del_entry_valid_or_report(ppppplVar12);
      }
      *ppppplVar12 = (long ****)0xdead000000000100;
      uVar9 = uVar9 + 1;
      ppppplVar12[1] = (long ****)0xdead000000000122;
      kfree(ppppplVar12 + -1);
      ppppplVar12 = (long *****)pppplStack_60;
    }
    if ((long *****)pppplStack_50 != &pppplStack_50) {
      do {
        pppplVar1 = pppplStack_50;
        ppppplVar12 = (long *****)(pppplStack_50 + -1);
        if (ppppplVar12 == (long *****)0x0) break;
        pppplVar8 = (long ****)pppplStack_50[-1];
        uVar6 = 1 << ((byte)*(undefined4 *)(param_1 + 0x8c) & 0x1f);
        if (uVar6 != 0) {
          pppplVar11 = pppplVar8 + (ulong)uVar6 * 0x200;
          if (((ulong)uVar6 * 0x1000 & 0x1000) == 0) {
LAB_0011bcca:
            do {
              __clear_pages_unrolled(pppplVar8);
              __clear_pages_unrolled(extraout_RDX_00 + 0x1000);
              pppplVar8 = (long ****)(extraout_RDX_01 + 0x2000);
            } while (pppplVar11 != pppplVar8);
          }
          else {
            __clear_pages_unrolled(pppplVar8);
            pppplVar8 = (long ****)(extraout_RDX + 0x1000);
            if (pppplVar11 != pppplVar8) goto LAB_0011bcca;
          }
          pppplVar8 = (long ****)pppplVar1[-1];
        }
        nv_alloc_set_page(param_2,uVar9,pppplVar8);
        pppplVar8 = (long ****)pppplVar1[1];
        pppplVar11 = (long ****)*pppplVar1;
        if ((pppplVar1 == (long ****)*pppplVar8) && (pppplVar1 == (long ****)pppplVar11[1])) {
          pppplVar11[1] = (long ***)pppplVar8;
          *pppplVar8 = (long ***)pppplVar11;
        }
        else {
          __list_del_entry_valid_or_report(pppplVar1);
        }
        uVar9 = uVar9 + 1;
        *pppplVar1 = (long ***)0xdead000000000100;
        pppplVar1[1] = (long ***)0xdead000000000122;
        kfree(ppppplVar12);
      } while ((long *****)pppplStack_50 != &pppplStack_50);
    }
    if (uVar9 != uStack_7c) {
      os_dbg_breakpoint();
    }
    nv_printf(0,
              "NVRM: VM: %s: node=%d order=%u: %lu/%lu pages allocated (%lu already cleared, %lu left in pool)\n"
              ,"nv_mem_pool_alloc_pages",*(undefined4 *)(param_1 + 0x88),
              *(undefined4 *)(param_1 + 0x8c),uStack_7c,uVar3,uVar3 - iVar4,lVar10);
  }
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uStack_7c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011baa0 nv_mem_pool_alloc_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011bb2e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint nv_mem_pool_alloc_pages(long param_1,long param_2)

{
  long ****pppplVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  long extraout_RDX;
  long ****pppplVar8;
  long extraout_RDX_00;
  long extraout_RDX_01;
  uint uVar9;
  long lVar10;
  long ****pppplVar11;
  long *****ppppplVar12;
  long in_GS_OFFSET;
  undefined1 auVar13 [12];
  uint local_7c;
  long ****local_60;
  long ****local_58;
  long ****local_50;
  long ****local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  bVar7 = (byte)*(undefined4 *)(param_2 + 0x24);
  local_60 = (long ****)0x0;
  local_58 = (long ****)0x0;
  local_50 = (long ****)0x0;
  local_48 = (long ****)0x0;
  auVar13 = (*_mpi_powm)(param_1,param_2,*(undefined4 *)(param_2 + 0x20));
  if (((auVar13._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    local_7c = 0;
  }
  else {
    uVar3 = (uint)(auVar13._8_4_ + -1 + (1 << (bVar7 & 0x1f))) >> (bVar7 & 0x1f);
    local_50 = (long ****)&local_50;
    local_60 = (long ****)&local_60;
    local_58 = (long ****)&local_60;
    local_48 = local_50;
    iVar4 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    iVar4 = nv_mem_pool_move_pages(&local_60,param_1);
    iVar5 = nv_mem_pool_move_pages(&local_50,param_1 + 0x10,iVar4);
    local_7c = uVar3 - iVar5;
    lVar10 = *(long *)(param_1 + 0x90) - (ulong)local_7c;
    *(long *)(param_1 + 0x90) = lVar10;
    uVar9 = 0;
    os_release_mutex(*(undefined8 *)(param_1 + 0x98));
    ppppplVar12 = (long *****)local_60;
    while ((local_60 = (long ****)ppppplVar12, ppppplVar12 != &local_60 &&
           (ppppplVar12 + -1 != (long *****)0x0))) {
      nv_alloc_set_page(param_2,uVar9,ppppplVar12[-1]);
      pppplVar1 = ppppplVar12[1];
      pppplVar8 = *ppppplVar12;
      if ((ppppplVar12 == (long *****)*pppplVar1) && (ppppplVar12 == (long *****)pppplVar8[1])) {
        pppplVar8[1] = (long ***)pppplVar1;
        *pppplVar1 = (long ***)pppplVar8;
      }
      else {
        __list_del_entry_valid_or_report(ppppplVar12);
      }
      *ppppplVar12 = (long ****)0xdead000000000100;
      uVar9 = uVar9 + 1;
      ppppplVar12[1] = (long ****)0xdead000000000122;
      kfree(ppppplVar12 + -1);
      ppppplVar12 = (long *****)local_60;
    }
    if ((long *****)local_50 != &local_50) {
      do {
        pppplVar1 = local_50;
        ppppplVar12 = (long *****)(local_50 + -1);
        if (ppppplVar12 == (long *****)0x0) break;
        pppplVar8 = (long ****)local_50[-1];
        uVar6 = 1 << ((byte)*(undefined4 *)(param_1 + 0x8c) & 0x1f);
        if (uVar6 != 0) {
          pppplVar11 = pppplVar8 + (ulong)uVar6 * 0x200;
          if (((ulong)uVar6 * 0x1000 & 0x1000) == 0) {
LAB_0011bcca:
            do {
              __clear_pages_unrolled(pppplVar8);
              __clear_pages_unrolled(extraout_RDX_00 + 0x1000);
              pppplVar8 = (long ****)(extraout_RDX_01 + 0x2000);
            } while (pppplVar11 != pppplVar8);
          }
          else {
            __clear_pages_unrolled(pppplVar8);
            pppplVar8 = (long ****)(extraout_RDX + 0x1000);
            if (pppplVar11 != pppplVar8) goto LAB_0011bcca;
          }
          pppplVar8 = (long ****)pppplVar1[-1];
        }
        nv_alloc_set_page(param_2,uVar9,pppplVar8);
        pppplVar8 = (long ****)pppplVar1[1];
        pppplVar11 = (long ****)*pppplVar1;
        if ((pppplVar1 == (long ****)*pppplVar8) && (pppplVar1 == (long ****)pppplVar11[1])) {
          pppplVar11[1] = (long ***)pppplVar8;
          *pppplVar8 = (long ***)pppplVar11;
        }
        else {
          __list_del_entry_valid_or_report(pppplVar1);
        }
        uVar9 = uVar9 + 1;
        *pppplVar1 = (long ***)0xdead000000000100;
        pppplVar1[1] = (long ***)0xdead000000000122;
        kfree(ppppplVar12);
      } while ((long *****)local_50 != &local_50);
    }
    if (uVar9 != local_7c) {
      os_dbg_breakpoint();
    }
    nv_printf(0,
              "NVRM: VM: %s: node=%d order=%u: %lu/%lu pages allocated (%lu already cleared, %lu left in pool)\n"
              ,"nv_mem_pool_alloc_pages",*(undefined4 *)(param_1 + 0x88),
              *(undefined4 *)(param_1 + 0x8c),local_7c,uVar3,uVar3 - iVar4,lVar10);
  }
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return local_7c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011bdf0 __pfx_nv_mem_pool_destroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_mem_pool_destroy(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  nv_mem_pool_free_page_list(param_1 + 0x10,*(undefined4 *)(param_1 + 0x8c));
  os_release_mutex(*(undefined8 *)(param_1 + 0x98));
  nv_kthread_q_stop(param_1 + 0x20);
  iVar2 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
  if (iVar2 == 0) {
    nv_mem_pool_free_page_list(param_1,*(undefined4 *)(param_1 + 0x8c));
    os_release_mutex(*(undefined8 *)(param_1 + 0x98));
    if (*(long *)(param_1 + 0xa0) != 0) {
      shrinker_free();
    }
    os_free_mutex(*(undefined8 *)(param_1 + 0x98));
    kfree(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011be00 nv_mem_pool_destroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_mem_pool_destroy(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  nv_mem_pool_free_page_list(param_1 + 0x10,*(undefined4 *)(param_1 + 0x8c));
  os_release_mutex(*(undefined8 *)(param_1 + 0x98));
  nv_kthread_q_stop(param_1 + 0x20);
  iVar2 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
  if (iVar2 == 0) {
    nv_mem_pool_free_page_list(param_1,*(undefined4 *)(param_1 + 0x8c));
    os_release_mutex(*(undefined8 *)(param_1 + 0x98));
    if (*(long *)(param_1 + 0xa0) != 0) {
      shrinker_free();
    }
    os_free_mutex(*(undefined8 *)(param_1 + 0x98));
    kfree(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011bea0 __pfx_nv_mem_pool_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011bf9a) */
/* WARNING: Removing unreachable block (ram,0x0011bfc8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx_nv_mem_pool_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = __kmalloc_cache_noprof(_strcasecmp,0x2dc0,0xa8);
  if (lVar2 == 0) {
    nv_printf(1,"NVRM: %s: failed allocating memory\n","nv_mem_pool_init");
    return 0;
  }
  *(undefined4 *)(lVar2 + 0x88) = param_1;
  *(undefined4 *)(lVar2 + 0x8c) = param_2;
  *(long *)lVar2 = lVar2;
  *(long *)(lVar2 + 8) = lVar2;
  *(long *)(lVar2 + 0x10) = lVar2 + 0x10;
  *(long *)(lVar2 + 0x18) = lVar2 + 0x10;
  iVar1 = os_alloc_mutex(lVar2 + 0x98);
  if (iVar1 == 0) {
    iVar1 = nv_kthread_q_init_on_node(lVar2 + 0x20,"nv_mem_pool_scrubber_queue",param_1);
    if (iVar1 == 0) {
      nv_kthread_q_item_init(lVar2 + 0x68,nv_mem_pool_worker,lVar2);
      puVar3 = (undefined8 *)
               shrinker_alloc(4,"nv-sysmem-alloc-node-%d-order-%u",*(undefined4 *)(lVar2 + 0x88),
                              *(undefined4 *)(lVar2 + 0x8c));
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = nv_mem_pool_shrinker_count;
        puVar3[1] = nv_mem_pool_shrinker_scan;
        *(undefined4 *)(puVar3 + 3) = 1;
        puVar3[0xb] = lVar2;
        shrinker_register(puVar3);
        *(undefined8 **)(lVar2 + 0xa0) = puVar3;
        return lVar2;
      }
      nv_printf(1,"NVRM: %s: failed allocating shrinker\n","nv_mem_pool_init");
    }
    else {
      nv_printf(1,"NVRM: %s: failed allocating worker thread\n","nv_mem_pool_init");
    }
  }
  else {
    nv_printf(1,"NVRM: %s: failed allocating mutex for worker thread\n","nv_mem_pool_init");
  }
  nv_mem_pool_destroy(lVar2);
  return 0;
}


// ===== 0011beb0 nv_mem_pool_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011bf9a) */
/* WARNING: Removing unreachable block (ram,0x0011bfc8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long nv_mem_pool_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = __kmalloc_cache_noprof(_strcasecmp,0x2dc0,0xa8);
  if (lVar2 == 0) {
    nv_printf(1,"NVRM: %s: failed allocating memory\n","nv_mem_pool_init");
    return 0;
  }
  *(undefined4 *)(lVar2 + 0x88) = param_1;
  *(undefined4 *)(lVar2 + 0x8c) = param_2;
  *(long *)lVar2 = lVar2;
  *(long *)(lVar2 + 8) = lVar2;
  *(long *)(lVar2 + 0x10) = lVar2 + 0x10;
  *(long *)(lVar2 + 0x18) = lVar2 + 0x10;
  iVar1 = os_alloc_mutex(lVar2 + 0x98);
  if (iVar1 == 0) {
    iVar1 = nv_kthread_q_init_on_node(lVar2 + 0x20,"nv_mem_pool_scrubber_queue",param_1);
    if (iVar1 == 0) {
      nv_kthread_q_item_init(lVar2 + 0x68,nv_mem_pool_worker,lVar2);
      puVar3 = (undefined8 *)
               shrinker_alloc(4,"nv-sysmem-alloc-node-%d-order-%u",*(undefined4 *)(lVar2 + 0x88),
                              *(undefined4 *)(lVar2 + 0x8c));
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = nv_mem_pool_shrinker_count;
        puVar3[1] = nv_mem_pool_shrinker_scan;
        *(undefined4 *)(puVar3 + 3) = 1;
        puVar3[0xb] = lVar2;
        shrinker_register(puVar3);
        *(undefined8 **)(lVar2 + 0xa0) = puVar3;
        return lVar2;
      }
      nv_printf(1,"NVRM: %s: failed allocating shrinker\n","nv_mem_pool_init");
    }
    else {
      nv_printf(1,"NVRM: %s: failed allocating worker thread\n","nv_mem_pool_init");
    }
  }
  else {
    nv_printf(1,"NVRM: %s: failed allocating mutex for worker thread\n","nv_mem_pool_init");
  }
  nv_mem_pool_destroy(lVar2);
  return 0;
}


// ===== 0011c020 __pfx_nv_mem_pool_free_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c277) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_nv_mem_pool_free_pages(long param_1,long param_2)

{
  ulong ****ppppuVar1;
  ulong ***pppuVar2;
  ulong ***pppuVar3;
  code *pcVar4;
  int iVar5;
  ulong *puVar6;
  ulong *puVar7;
  long lVar8;
  uint uVar9;
  undefined4 uVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  long in_GS_OFFSET;
  undefined1 auVar14 [12];
  byte bStack_60;
  ulong ***pppuStack_50;
  ulong ***pppuStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar10 = *(undefined4 *)(param_2 + 0x24);
  pppuStack_50 = (ulong ***)0x0;
  pppuStack_48 = (ulong ***)0x0;
  auVar14 = (*_mpi_powm)(param_1,param_2,*(undefined4 *)(param_2 + 0x20));
  if (((auVar14._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    uVar10 = 0x1f;
  }
  else {
    bStack_60 = (byte)uVar10;
    uVar13 = (uint)(auVar14._8_4_ + -1 + (1 << (bStack_60 & 0x1f))) >> (bStack_60 & 0x1f);
    pppuStack_50 = (ulong ***)&pppuStack_50;
    pppuStack_48 = (ulong ***)&pppuStack_50;
    if (uVar13 == 0) {
      uVar10 = 0;
    }
    else {
      uVar9 = 0;
      uVar12 = 0;
      do {
        while( true ) {
          puVar7 = (ulong *)((ulong)(uVar12 << (bStack_60 & 0x1f)) * 0x10 +
                            *(long *)(param_2 + 0x30));
          uVar11 = puVar7[1];
          if (uVar11 == 0) goto LAB_0011c198;
          if (*(uint *)(param_1 + 0x88) ==
              (uint)((ulong)*(undefined8 *)((*puVar7 >> 0xc) * 0x40 + _vmemmap_base) >> 0x36))
          break;
LAB_0011c183:
          uVar12 = uVar12 + 1;
          free_pages(uVar11,*(undefined4 *)(param_1 + 0x8c));
          if (uVar13 == uVar12) goto LAB_0011c198;
        }
        puVar6 = (ulong *)__kmalloc_cache_noprof(___alloc_pages_noprof,0x2dc0,0x18);
        uVar11 = puVar7[1];
        if (puVar6 == (ulong *)0x0) goto LAB_0011c183;
        *puVar6 = uVar11;
        ppppuVar1 = (ulong ****)(puVar6 + 1);
        if (((ulong ****)pppuStack_50[1] == &pppuStack_50) &&
           (ppppuVar1 != (ulong ****)pppuStack_50)) {
          pppuStack_50[1] = (ulong **)ppppuVar1;
          puVar6[1] = (ulong)pppuStack_50;
          puVar6[2] = (ulong)&pppuStack_50;
          pppuStack_50 = (ulong ***)ppppuVar1;
        }
        else {
          __list_add_valid_or_report(ppppuVar1,&pppuStack_50);
        }
        uVar12 = uVar12 + 1;
        uVar9 = uVar9 + 1;
      } while (uVar13 != uVar12);
LAB_0011c198:
      if (uVar9 == 0) {
        uVar10 = 0;
      }
      else {
        iVar5 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        pppuVar2 = *(ulong ****)(param_1 + 0x10);
        if ((ulong ****)pppuStack_50 != &pppuStack_50) {
          pppuVar3 = *(ulong ****)(param_1 + 0x10);
          pppuStack_50[1] = (ulong **)(param_1 + 0x10U);
          *(ulong ****)(param_1 + 0x10) = pppuStack_50;
          *pppuStack_48 = (ulong **)pppuVar3;
          pppuVar3[1] = (ulong **)pppuStack_48;
          pppuStack_50 = (ulong ***)&pppuStack_50;
          pppuStack_48 = (ulong ***)&pppuStack_50;
        }
        lVar8 = (ulong)uVar9 + *(long *)(param_1 + 0x90);
        *(long *)(param_1 + 0x90) = lVar8;
        os_release_mutex(*(undefined8 *)(param_1 + 0x98));
        nv_printf(0,
                  "NVRM: VM: %s: node=%d order=%u: %lu/%lu pages added to pool (%lu now in pool)\n",
                  "nv_mem_pool_free_pages",*(undefined4 *)(param_1 + 0x88),
                  *(undefined4 *)(param_1 + 0x8c),uVar9,uVar13);
        if ((ulong ***)(param_1 + 0x10U) == pppuVar2) {
          nv_kthread_q_schedule_q_item(param_1 + 0x20,param_1 + 0x68,lVar8);
        }
        uVar10 = 0;
      }
    }
  }
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011c030 nv_mem_pool_free_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c277) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nv_mem_pool_free_pages(long param_1,long param_2)

{
  ulong ****ppppuVar1;
  ulong ***pppuVar2;
  ulong ***pppuVar3;
  code *pcVar4;
  int iVar5;
  ulong *puVar6;
  ulong *puVar7;
  long lVar8;
  uint uVar9;
  undefined4 uVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  long in_GS_OFFSET;
  undefined1 auVar14 [12];
  byte local_60;
  ulong ***local_50;
  ulong ***local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar10 = *(undefined4 *)(param_2 + 0x24);
  local_50 = (ulong ***)0x0;
  local_48 = (ulong ***)0x0;
  auVar14 = (*_mpi_powm)(param_1,param_2,*(undefined4 *)(param_2 + 0x20));
  if (((auVar14._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    uVar10 = 0x1f;
  }
  else {
    local_60 = (byte)uVar10;
    uVar13 = (uint)(auVar14._8_4_ + -1 + (1 << (local_60 & 0x1f))) >> (local_60 & 0x1f);
    local_50 = (ulong ***)&local_50;
    local_48 = (ulong ***)&local_50;
    if (uVar13 == 0) {
      uVar10 = 0;
    }
    else {
      uVar9 = 0;
      uVar12 = 0;
      do {
        while( true ) {
          puVar7 = (ulong *)((ulong)(uVar12 << (local_60 & 0x1f)) * 0x10 + *(long *)(param_2 + 0x30)
                            );
          uVar11 = puVar7[1];
          if (uVar11 == 0) goto LAB_0011c198;
          if (*(uint *)(param_1 + 0x88) ==
              (uint)((ulong)*(undefined8 *)((*puVar7 >> 0xc) * 0x40 + _vmemmap_base) >> 0x36))
          break;
LAB_0011c183:
          uVar12 = uVar12 + 1;
          free_pages(uVar11,*(undefined4 *)(param_1 + 0x8c));
          if (uVar13 == uVar12) goto LAB_0011c198;
        }
        puVar6 = (ulong *)__kmalloc_cache_noprof(___alloc_pages_noprof,0x2dc0,0x18);
        uVar11 = puVar7[1];
        if (puVar6 == (ulong *)0x0) goto LAB_0011c183;
        *puVar6 = uVar11;
        ppppuVar1 = (ulong ****)(puVar6 + 1);
        if (((ulong ****)local_50[1] == &local_50) && (ppppuVar1 != (ulong ****)local_50)) {
          local_50[1] = (ulong **)ppppuVar1;
          puVar6[1] = (ulong)local_50;
          puVar6[2] = (ulong)&local_50;
          local_50 = (ulong ***)ppppuVar1;
        }
        else {
          __list_add_valid_or_report(ppppuVar1,&local_50);
        }
        uVar12 = uVar12 + 1;
        uVar9 = uVar9 + 1;
      } while (uVar13 != uVar12);
LAB_0011c198:
      if (uVar9 == 0) {
        uVar10 = 0;
      }
      else {
        iVar5 = os_acquire_mutex(*(undefined8 *)(param_1 + 0x98));
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        pppuVar2 = *(ulong ****)(param_1 + 0x10);
        if ((ulong ****)local_50 != &local_50) {
          pppuVar3 = *(ulong ****)(param_1 + 0x10);
          local_50[1] = (ulong **)(param_1 + 0x10U);
          *(ulong ****)(param_1 + 0x10) = local_50;
          *local_48 = (ulong **)pppuVar3;
          pppuVar3[1] = (ulong **)local_48;
          local_50 = (ulong ***)&local_50;
          local_48 = (ulong ***)&local_50;
        }
        lVar8 = (ulong)uVar9 + *(long *)(param_1 + 0x90);
        *(long *)(param_1 + 0x90) = lVar8;
        os_release_mutex(*(undefined8 *)(param_1 + 0x98));
        nv_printf(0,
                  "NVRM: VM: %s: node=%d order=%u: %lu/%lu pages added to pool (%lu now in pool)\n",
                  "nv_mem_pool_free_pages",*(undefined4 *)(param_1 + 0x88),
                  *(undefined4 *)(param_1 + 0x8c),uVar9,uVar13);
        if ((ulong ***)(param_1 + 0x10U) == pppuVar2) {
          nv_kthread_q_schedule_q_item(param_1 + 0x20,param_1 + 0x68,lVar8);
        }
        uVar10 = 0;
      }
    }
  }
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011c2d0 __pfx_nv_init_page_pools =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c3a2) */
/* WARNING: Removing unreachable block (ram,0x0011c3be) */

undefined8 __pfx_nv_init_page_pools(void)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  
  uVar1 = _find_first_bit(&node_states,0x400);
  if (uVar1 < 0x400) {
    uVar3 = 0x400;
    if (uVar1 < 0x401) {
      uVar3 = uVar1;
    }
    do {
      uVar1 = 0;
      do {
        if ((NVreg_EnableSystemMemoryPools & (uint)((ulong)(0x1000L << ((byte)uVar1 & 0x3f)) >> 0xc)
            ) != 0) {
          lVar2 = nv_mem_pool_init(uVar3 & 0xffffffff,uVar1 & 0xffffffff);
          *(long *)(sysmem_page_pools + uVar1 * 8 + (uVar3 & 0xffffffff) * 0x58) = lVar2;
          if (lVar2 == 0) {
            return 0x51;
          }
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 != 0xb);
      uVar1 = _find_next_bit(&node_states,0x400,(int)uVar3 + 1);
      uVar3 = 0x400;
      if (uVar1 < 0x401) {
        uVar3 = uVar1;
      }
    } while (uVar1 < 0x400);
  }
  return 0;
}


// ===== 0011c2e0 nv_init_page_pools =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c3a2) */
/* WARNING: Removing unreachable block (ram,0x0011c3be) */

undefined8 nv_init_page_pools(void)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  
  uVar1 = _find_first_bit(&node_states,0x400);
  if (uVar1 < 0x400) {
    uVar3 = 0x400;
    if (uVar1 < 0x401) {
      uVar3 = uVar1;
    }
    do {
      uVar1 = 0;
      do {
        if ((NVreg_EnableSystemMemoryPools & (uint)((ulong)(0x1000L << ((byte)uVar1 & 0x3f)) >> 0xc)
            ) != 0) {
          lVar2 = nv_mem_pool_init(uVar3 & 0xffffffff,uVar1 & 0xffffffff);
          *(long *)(sysmem_page_pools + uVar1 * 8 + (uVar3 & 0xffffffff) * 0x58) = lVar2;
          if (lVar2 == 0) {
            return 0x51;
          }
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 != 0xb);
      uVar1 = _find_next_bit(&node_states,0x400,(int)uVar3 + 1);
      uVar3 = 0x400;
      if (uVar1 < 0x401) {
        uVar3 = uVar1;
      }
    } while (uVar1 < 0x400);
  }
  return 0;
}


// ===== 0011c3d0 __pfx_nv_destroy_page_pools =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c48f) */

void __pfx_nv_destroy_page_pools(void)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = _find_first_bit(&node_states,0x400);
  if (uVar1 < 0x400) {
    uVar4 = 0x400;
    if (uVar1 < 0x401) {
      uVar4 = uVar1;
    }
    do {
      lVar3 = (uVar4 & 0xffffffff) * 0x58;
      plVar2 = (long *)(sysmem_page_pools + lVar3);
      do {
        if (*plVar2 != 0) {
          nv_mem_pool_destroy();
        }
        plVar2 = plVar2 + 1;
      } while (plVar2 != (long *)(sysmem_page_pools + lVar3 + 0x58));
      uVar1 = _find_next_bit(&node_states,0x400,(int)uVar4 + 1);
      uVar4 = 0x400;
      if (uVar1 < 0x401) {
        uVar4 = uVar1;
      }
    } while (uVar1 < 0x400);
  }
  return;
}


// ===== 0011c3e0 nv_destroy_page_pools =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c48f) */

void nv_destroy_page_pools(void)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = _find_first_bit(&node_states,0x400);
  if (uVar1 < 0x400) {
    uVar4 = 0x400;
    if (uVar1 < 0x401) {
      uVar4 = uVar1;
    }
    do {
      lVar3 = (uVar4 & 0xffffffff) * 0x58;
      plVar2 = (long *)(sysmem_page_pools + lVar3);
      do {
        if (*plVar2 != 0) {
          nv_mem_pool_destroy();
        }
        plVar2 = plVar2 + 1;
      } while (plVar2 != (long *)(sysmem_page_pools + lVar3 + 0x58));
      uVar1 = _find_next_bit(&node_states,0x400,(int)uVar4 + 1);
      uVar4 = 0x400;
      if (uVar1 < 0x401) {
        uVar4 = uVar1;
      }
    } while (uVar1 < 0x400);
  }
  return;
}


// ===== 0011c4a0 __pfx_nv_free_system_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_free_system_pages(long param_1)

{
  ulong *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  long lVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  long in_GS_OFFSET;
  bool bVar11;
  long lStack_48;
  long lStack_40;
  
  uVar3 = *(uint *)(param_1 + 0x24);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puVar1 = *(ulong **)(param_1 + 0x30);
  bVar4 = (byte)uVar3;
  uVar8 = (*(uint *)(param_1 + 0x20) - 1) + (1 << (bVar4 & 0x1f));
  uVar9 = uVar8 >> (bVar4 & 0x1f);
  if ((puVar1[1] == 0) || (10 < uVar3)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    bVar11 = true;
    lVar10 = 0;
  }
  else {
    lVar10 = *(long *)(sysmem_page_pools +
                      ((*(ulong *)((*puVar1 >> 0xc) * 0x40 + _vmemmap_base) >> 0x36) * 0xb +
                      (ulong)uVar3) * 8);
    iVar2 = *(int *)(param_1 + 0x1c);
    bVar11 = lVar10 == 0;
  }
  if (iVar2 != 0) {
    lStack_48 = 0;
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      iVar2 = os_alloc_mem(&lStack_48,(ulong)*(uint *)(param_1 + 0x20) << 3);
      if (iVar2 == 0) {
        if (lStack_48 != 0) {
          if (*(int *)(param_1 + 0x20) == 0) {
            uVar3 = 0;
          }
          else {
            lVar5 = 0;
            do {
              *(ulong *)(lStack_48 + lVar5 * 8) =
                   (*(ulong *)(lVar5 * 0x10 + *(long *)(param_1 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar3 = *(uint *)(param_1 + 0x20);
              lVar5 = lVar5 + 1;
            } while ((uint)lVar5 < uVar3);
          }
          set_pages_array_wb(lStack_48,uVar3);
          os_free_mem(lStack_48);
          goto LAB_0011c614;
        }
      }
      else {
        lStack_48 = 0;
      }
      lVar5 = 0;
      if (*(int *)(param_1 + 0x20) != 0) {
        do {
          lVar6 = lVar5 + 1;
          set_memory_wb((*(ulong *)(lVar5 * 0x10 + *(long *)(param_1 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          lVar5 = lVar6;
        } while ((uint)lVar6 < *(uint *)(param_1 + 0x20));
      }
    }
    else {
      set_memory_wb((*puVar1 & 0xfffffffffffff000) + _page_offset_base);
    }
  }
LAB_0011c614:
  if (uVar8 >> (bVar4 & 0x1f) == 0) {
    if (((*(byte *)(param_1 + 0x19) & 8) == 0) || (bVar11)) {
      uVar3 = 0;
      goto LAB_0011c6a8;
    }
    iVar2 = nv_mem_pool_free_pages(lVar10,param_1);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      goto LAB_0011c6a8;
    }
LAB_0011c6ff:
    uVar3 = uVar3 << (bVar4 & 0x1f);
  }
  else {
    bVar7 = *(byte *)(param_1 + 0x19);
    uVar8 = 0;
    do {
      while( true ) {
        uVar3 = uVar8;
        lVar6 = *(long *)(param_1 + 0x30);
        lVar5 = *(long *)(lVar6 + 8 + (ulong)(uVar3 << (bVar4 & 0x1f)) * 0x10);
        if (lVar5 == 0) {
          if (((bVar7 & 8) == 0) || (bVar11)) goto LAB_0011c679;
          goto LAB_0011c6ec;
        }
        if ((bVar7 & 1) == 0) break;
        set_memory_encrypted(lVar5,1 << ((byte)*(undefined4 *)(param_1 + 0x24) & 0x1f));
        bVar7 = *(byte *)(param_1 + 0x19);
        uVar8 = uVar3 + 1;
        if (uVar9 == uVar3 + 1) goto LAB_0011c66b;
      }
      uVar8 = uVar3 + 1;
    } while (uVar9 != uVar3 + 1);
LAB_0011c66b:
    uVar3 = uVar3 + 1;
    if (((bVar7 & 8) != 0) && (!bVar11)) {
LAB_0011c6ec:
      iVar2 = nv_mem_pool_free_pages(lVar10,param_1);
      if (iVar2 == 0) goto LAB_0011c6ff;
    }
    lVar6 = *(long *)(param_1 + 0x30);
LAB_0011c679:
    uVar8 = 0;
    while( true ) {
      uVar3 = uVar8 << (bVar4 & 0x1f);
      lVar10 = *(long *)(lVar6 + 8 + (ulong)uVar3 * 0x10);
      if (lVar10 == 0) break;
      uVar8 = uVar8 + 1;
      free_pages(lVar10,*(undefined4 *)(param_1 + 0x24),lVar6,uVar3);
      if (uVar9 == uVar8) {
        uVar3 = uVar9 << (bVar4 & 0x1f);
        break;
      }
      lVar6 = *(long *)(param_1 + 0x30);
    }
  }
LAB_0011c6a8:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    nv_printf(0,"NVRM: VM: %s: %u/%u order0 pages\n","nv_free_system_pages",uVar3,
              *(undefined4 *)(param_1 + 0x20));
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011c4b0 nv_free_system_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_free_system_pages(long param_1)

{
  ulong *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  long lVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  long in_GS_OFFSET;
  bool bVar11;
  long local_48;
  long local_40;
  
  uVar3 = *(uint *)(param_1 + 0x24);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puVar1 = *(ulong **)(param_1 + 0x30);
  bVar4 = (byte)uVar3;
  uVar8 = (*(uint *)(param_1 + 0x20) - 1) + (1 << (bVar4 & 0x1f));
  uVar9 = uVar8 >> (bVar4 & 0x1f);
  if ((puVar1[1] == 0) || (10 < uVar3)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    bVar11 = true;
    lVar10 = 0;
  }
  else {
    lVar10 = *(long *)(sysmem_page_pools +
                      ((*(ulong *)((*puVar1 >> 0xc) * 0x40 + _vmemmap_base) >> 0x36) * 0xb +
                      (ulong)uVar3) * 8);
    iVar2 = *(int *)(param_1 + 0x1c);
    bVar11 = lVar10 == 0;
  }
  if (iVar2 != 0) {
    local_48 = 0;
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      iVar2 = os_alloc_mem(&local_48,(ulong)*(uint *)(param_1 + 0x20) << 3);
      if (iVar2 == 0) {
        if (local_48 != 0) {
          if (*(int *)(param_1 + 0x20) == 0) {
            uVar3 = 0;
          }
          else {
            lVar5 = 0;
            do {
              *(ulong *)(local_48 + lVar5 * 8) =
                   (*(ulong *)(lVar5 * 0x10 + *(long *)(param_1 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar3 = *(uint *)(param_1 + 0x20);
              lVar5 = lVar5 + 1;
            } while ((uint)lVar5 < uVar3);
          }
          set_pages_array_wb(local_48,uVar3);
          os_free_mem(local_48);
          goto LAB_0011c614;
        }
      }
      else {
        local_48 = 0;
      }
      lVar5 = 0;
      if (*(int *)(param_1 + 0x20) != 0) {
        do {
          lVar6 = lVar5 + 1;
          set_memory_wb((*(ulong *)(lVar5 * 0x10 + *(long *)(param_1 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          lVar5 = lVar6;
        } while ((uint)lVar6 < *(uint *)(param_1 + 0x20));
      }
    }
    else {
      set_memory_wb((*puVar1 & 0xfffffffffffff000) + _page_offset_base);
    }
  }
LAB_0011c614:
  if (uVar8 >> (bVar4 & 0x1f) == 0) {
    if (((*(byte *)(param_1 + 0x19) & 8) == 0) || (bVar11)) {
      uVar3 = 0;
      goto LAB_0011c6a8;
    }
    iVar2 = nv_mem_pool_free_pages(lVar10,param_1);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      goto LAB_0011c6a8;
    }
LAB_0011c6ff:
    uVar3 = uVar3 << (bVar4 & 0x1f);
  }
  else {
    bVar7 = *(byte *)(param_1 + 0x19);
    uVar8 = 0;
    do {
      while( true ) {
        uVar3 = uVar8;
        lVar6 = *(long *)(param_1 + 0x30);
        lVar5 = *(long *)(lVar6 + 8 + (ulong)(uVar3 << (bVar4 & 0x1f)) * 0x10);
        if (lVar5 == 0) {
          if (((bVar7 & 8) == 0) || (bVar11)) goto LAB_0011c679;
          goto LAB_0011c6ec;
        }
        if ((bVar7 & 1) == 0) break;
        set_memory_encrypted(lVar5,1 << ((byte)*(undefined4 *)(param_1 + 0x24) & 0x1f));
        bVar7 = *(byte *)(param_1 + 0x19);
        uVar8 = uVar3 + 1;
        if (uVar9 == uVar3 + 1) goto LAB_0011c66b;
      }
      uVar8 = uVar3 + 1;
    } while (uVar9 != uVar3 + 1);
LAB_0011c66b:
    uVar3 = uVar3 + 1;
    if (((bVar7 & 8) != 0) && (!bVar11)) {
LAB_0011c6ec:
      iVar2 = nv_mem_pool_free_pages(lVar10,param_1);
      if (iVar2 == 0) goto LAB_0011c6ff;
    }
    lVar6 = *(long *)(param_1 + 0x30);
LAB_0011c679:
    uVar8 = 0;
    while( true ) {
      uVar3 = uVar8 << (bVar4 & 0x1f);
      lVar10 = *(long *)(lVar6 + 8 + (ulong)uVar3 * 0x10);
      if (lVar10 == 0) break;
      uVar8 = uVar8 + 1;
      free_pages(lVar10,*(undefined4 *)(param_1 + 0x24),lVar6,uVar3);
      if (uVar9 == uVar8) {
        uVar3 = uVar9 << (bVar4 & 0x1f);
        break;
      }
      lVar6 = *(long *)(param_1 + 0x30);
    }
  }
LAB_0011c6a8:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    nv_printf(0,"NVRM: VM: %s: %u/%u order0 pages\n","nv_free_system_pages",uVar3,
              *(undefined4 *)(param_1 + 0x20));
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011c7b0 __pfx_nv_alloc_system_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c970) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __pfx_nv_alloc_system_pages(undefined8 param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  void *__s;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  byte bVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  uint uVar15;
  long in_GS_OFFSET;
  long lStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = nv_compute_gfp_mask();
  uVar12 = *(uint *)(param_2 + 0x24);
  iVar7 = *(int *)(param_2 + 0x20);
  bVar1 = *(byte *)(param_2 + 0x18);
  bVar10 = (byte)uVar12;
  uVar5 = 1 << (bVar10 & 0x1f);
  uVar13 = iVar7 + -1 + uVar5;
  uVar2 = *(uint *)(&numa_node + in_GS_OFFSET);
  bVar3 = bVar10 & 0x1f;
  uVar15 = uVar13 >> bVar3;
  if ((bVar1 & 0x20) != 0) {
    uVar2 = *(uint *)(param_2 + 0x50);
  }
  uVar9 = (ulong)CONCAT31((int3)(uVar12 >> 8),10 < uVar12);
  if (0x3ff < uVar2 || 10 < uVar12) {
    if (((uVar4 & 4) == 0) && ((bVar1 & 4) != 0)) {
      lVar8 = 0;
      goto LAB_0011c994;
    }
    *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xf7;
    nv_printf(0,"NVRM: VM: %s: %u order0 pages, %u order\n","nv_alloc_system_pages",iVar7,uVar12);
LAB_0011c894:
    if (uVar13 >> bVar3 != 0) {
      uVar12 = 0;
LAB_0011c89f:
      do {
        if ((*(byte *)(param_2 + 0x18) & 0x20) != 0) {
          iVar7 = *(int *)(param_2 + 0x50);
          if (*(int *)(param_2 + 0x50) == -1) {
            iVar7 = *(int *)(&numa_node + in_GS_OFFSET);
          }
          lStack_48 = CONCAT44(lStack_48._4_4_,uVar4);
          if (((uVar4 & 0x202000) == 0x202000) &&
             (((byte)__release_region[(long)iVar7 >> 3] >> ((long)iVar7 & 7U) & 1) == 0)) {
            uVar9 = nv_alloc_system_pages_cold();
            return uVar9;
          }
          lVar8 = __alloc_pages_noprof(uVar4,*(undefined4 *)(param_2 + 0x24),iVar7,0);
          if (lVar8 != 0) {
            lVar8 = (lVar8 - _vmemmap_base >> 6) * 0x1000 + _page_offset_base;
            goto joined_r0x0011c8f8;
          }
LAB_0011c92d:
          nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_system_pages");
          nv_free_system_pages(param_2);
          uVar9 = 0x51;
          goto LAB_0011c94f;
        }
        lVar8 = get_free_pages_noprof(uVar4,*(undefined4 *)(param_2 + 0x24));
joined_r0x0011c8f8:
        if (lVar8 == 0) goto LAB_0011c92d;
        uVar13 = uVar12 + 1;
        nv_alloc_set_page(param_2,uVar12);
        uVar12 = uVar13;
      } while (uVar13 < uVar15);
      goto LAB_0011ca6f;
    }
LAB_0011c9eb:
    uVar13 = *(uint *)(param_2 + 0x1c);
  }
  else {
    uVar9 = (ulong)uVar12;
    lVar8 = *(long *)(sysmem_page_pools + ((ulong)uVar2 * 0xb + uVar9) * 8);
    if (((uVar4 & 4) == 0) && ((bVar1 & 4) != 0)) {
LAB_0011c994:
      bVar11 = true;
      if (*(int *)(param_2 + 0x1c) != 0) {
        iVar6 = __bitmap_weight(__release_region,0x400,1,uVar9,uVar12);
        uVar12 = *(uint *)(param_2 + 0x24);
        iVar7 = *(int *)(param_2 + 0x20);
        bVar11 = iVar6 < 2;
      }
    }
    else {
      bVar11 = false;
    }
    *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xf7 | bVar11 << 3;
    nv_printf(0,"NVRM: VM: %s: %u order0 pages, %u order\n","nv_alloc_system_pages",iVar7,uVar12);
    if ((lVar8 == 0) || ((*(byte *)(param_2 + 0x19) & 8) == 0)) goto LAB_0011c894;
    uVar12 = nv_mem_pool_alloc_pages(lVar8,param_2);
    if (uVar12 < uVar15) goto LAB_0011c89f;
    if (uVar13 >> bVar3 == 0) goto LAB_0011c9eb;
LAB_0011ca6f:
    uVar13 = 0;
    do {
      uVar12 = uVar13 << (bVar10 & 0x1f);
      __s = *(void **)((ulong)uVar12 * 0x10 + *(long *)(param_2 + 0x30) + 8);
      if (((*(byte *)(param_2 + 0x19) & 1) != 0) && (__s != (void *)0x0)) {
        uVar12 = *(int *)(param_2 + 0x20) - uVar12;
        if (uVar5 < uVar12) {
          uVar12 = uVar5;
        }
        set_memory_decrypted(__s);
        memset(__s,0,(ulong)uVar12 << 0xc);
      }
      uVar13 = uVar13 + 1;
    } while (uVar15 != uVar13);
    uVar13 = *(uint *)(param_2 + 0x1c);
  }
  uVar9 = (ulong)uVar13;
  if (uVar13 != 0) {
    lStack_48 = 0;
    if ((*(byte *)(param_2 + 0x18) & 1) == 0) {
      iVar7 = os_alloc_mem(&lStack_48,(ulong)*(uint *)(param_2 + 0x20) << 3);
      if (iVar7 == 0) {
        if (lStack_48 != 0) {
          if (*(int *)(param_2 + 0x20) == 0) {
            uVar13 = 0;
          }
          else {
            lVar8 = 0;
            do {
              *(ulong *)(lStack_48 + lVar8 * 8) =
                   (*(ulong *)(lVar8 * 0x10 + *(long *)(param_2 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar13 = *(uint *)(param_2 + 0x20);
              lVar8 = lVar8 + 1;
            } while ((uint)lVar8 < uVar13);
          }
          set_pages_array_uc(lStack_48,uVar13);
          os_free_mem(lStack_48);
          uVar9 = 0;
          goto LAB_0011c94f;
        }
      }
      else {
        lStack_48 = 0;
      }
      lVar8 = 0;
      if (*(int *)(param_2 + 0x20) != 0) {
        do {
          lVar14 = lVar8 + 1;
          set_memory_uc((*(ulong *)(lVar8 * 0x10 + *(long *)(param_2 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          lVar8 = lVar14;
        } while ((uint)lVar14 < *(uint *)(param_2 + 0x20));
      }
      uVar9 = 0;
    }
    else {
      set_memory_uc((**(ulong **)(param_2 + 0x30) & 0xfffffffffffff000) + _page_offset_base);
      uVar9 = 0;
    }
  }
LAB_0011c94f:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}


// ===== 0011c7c0 nv_alloc_system_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011c970) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong nv_alloc_system_pages(undefined8 param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  void *__s;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  byte bVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  uint uVar15;
  long in_GS_OFFSET;
  long local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = nv_compute_gfp_mask();
  uVar12 = *(uint *)(param_2 + 0x24);
  iVar7 = *(int *)(param_2 + 0x20);
  bVar1 = *(byte *)(param_2 + 0x18);
  bVar10 = (byte)uVar12;
  uVar5 = 1 << (bVar10 & 0x1f);
  uVar13 = iVar7 + -1 + uVar5;
  uVar2 = *(uint *)(&numa_node + in_GS_OFFSET);
  bVar3 = bVar10 & 0x1f;
  uVar15 = uVar13 >> bVar3;
  if ((bVar1 & 0x20) != 0) {
    uVar2 = *(uint *)(param_2 + 0x50);
  }
  uVar9 = (ulong)CONCAT31((int3)(uVar12 >> 8),10 < uVar12);
  if (0x3ff < uVar2 || 10 < uVar12) {
    if (((uVar4 & 4) == 0) && ((bVar1 & 4) != 0)) {
      lVar8 = 0;
      goto LAB_0011c994;
    }
    *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xf7;
    nv_printf(0,"NVRM: VM: %s: %u order0 pages, %u order\n","nv_alloc_system_pages",iVar7,uVar12);
LAB_0011c894:
    if (uVar13 >> bVar3 != 0) {
      uVar12 = 0;
LAB_0011c89f:
      do {
        if ((*(byte *)(param_2 + 0x18) & 0x20) != 0) {
          iVar7 = *(int *)(param_2 + 0x50);
          if (*(int *)(param_2 + 0x50) == -1) {
            iVar7 = *(int *)(&numa_node + in_GS_OFFSET);
          }
          local_48 = CONCAT44(local_48._4_4_,uVar4);
          if (((uVar4 & 0x202000) == 0x202000) &&
             (((byte)__release_region[(long)iVar7 >> 3] >> ((long)iVar7 & 7U) & 1) == 0)) {
            uVar9 = nv_alloc_system_pages_cold();
            return uVar9;
          }
          lVar8 = __alloc_pages_noprof(uVar4,*(undefined4 *)(param_2 + 0x24),iVar7,0);
          if (lVar8 != 0) {
            lVar8 = (lVar8 - _vmemmap_base >> 6) * 0x1000 + _page_offset_base;
            goto joined_r0x0011c8f8;
          }
LAB_0011c92d:
          nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_system_pages");
          nv_free_system_pages(param_2);
          uVar9 = 0x51;
          goto LAB_0011c94f;
        }
        lVar8 = get_free_pages_noprof(uVar4,*(undefined4 *)(param_2 + 0x24));
joined_r0x0011c8f8:
        if (lVar8 == 0) goto LAB_0011c92d;
        uVar13 = uVar12 + 1;
        nv_alloc_set_page(param_2,uVar12);
        uVar12 = uVar13;
      } while (uVar13 < uVar15);
      goto LAB_0011ca6f;
    }
LAB_0011c9eb:
    uVar13 = *(uint *)(param_2 + 0x1c);
  }
  else {
    uVar9 = (ulong)uVar12;
    lVar8 = *(long *)(sysmem_page_pools + ((ulong)uVar2 * 0xb + uVar9) * 8);
    if (((uVar4 & 4) == 0) && ((bVar1 & 4) != 0)) {
LAB_0011c994:
      bVar11 = true;
      if (*(int *)(param_2 + 0x1c) != 0) {
        iVar6 = __bitmap_weight(__release_region,0x400,1,uVar9,uVar12);
        uVar12 = *(uint *)(param_2 + 0x24);
        iVar7 = *(int *)(param_2 + 0x20);
        bVar11 = iVar6 < 2;
      }
    }
    else {
      bVar11 = false;
    }
    *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xf7 | bVar11 << 3;
    nv_printf(0,"NVRM: VM: %s: %u order0 pages, %u order\n","nv_alloc_system_pages",iVar7,uVar12);
    if ((lVar8 == 0) || ((*(byte *)(param_2 + 0x19) & 8) == 0)) goto LAB_0011c894;
    uVar12 = nv_mem_pool_alloc_pages(lVar8,param_2);
    if (uVar12 < uVar15) goto LAB_0011c89f;
    if (uVar13 >> bVar3 == 0) goto LAB_0011c9eb;
LAB_0011ca6f:
    uVar13 = 0;
    do {
      uVar12 = uVar13 << (bVar10 & 0x1f);
      __s = *(void **)((ulong)uVar12 * 0x10 + *(long *)(param_2 + 0x30) + 8);
      if (((*(byte *)(param_2 + 0x19) & 1) != 0) && (__s != (void *)0x0)) {
        uVar12 = *(int *)(param_2 + 0x20) - uVar12;
        if (uVar5 < uVar12) {
          uVar12 = uVar5;
        }
        set_memory_decrypted(__s);
        memset(__s,0,(ulong)uVar12 << 0xc);
      }
      uVar13 = uVar13 + 1;
    } while (uVar15 != uVar13);
    uVar13 = *(uint *)(param_2 + 0x1c);
  }
  uVar9 = (ulong)uVar13;
  if (uVar13 != 0) {
    local_48 = 0;
    if ((*(byte *)(param_2 + 0x18) & 1) == 0) {
      iVar7 = os_alloc_mem(&local_48,(ulong)*(uint *)(param_2 + 0x20) << 3);
      if (iVar7 == 0) {
        if (local_48 != 0) {
          if (*(int *)(param_2 + 0x20) == 0) {
            uVar13 = 0;
          }
          else {
            lVar8 = 0;
            do {
              *(ulong *)(local_48 + lVar8 * 8) =
                   (*(ulong *)(lVar8 * 0x10 + *(long *)(param_2 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar13 = *(uint *)(param_2 + 0x20);
              lVar8 = lVar8 + 1;
            } while ((uint)lVar8 < uVar13);
          }
          set_pages_array_uc(local_48,uVar13);
          os_free_mem(local_48);
          uVar9 = 0;
          goto LAB_0011c94f;
        }
      }
      else {
        local_48 = 0;
      }
      lVar8 = 0;
      if (*(int *)(param_2 + 0x20) != 0) {
        do {
          lVar14 = lVar8 + 1;
          set_memory_uc((*(ulong *)(lVar8 * 0x10 + *(long *)(param_2 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          lVar8 = lVar14;
        } while ((uint)lVar14 < *(uint *)(param_2 + 0x20));
      }
      uVar9 = 0;
    }
    else {
      set_memory_uc((**(ulong **)(param_2 + 0x30) & 0xfffffffffffff000) + _page_offset_base);
      uVar9 = 0;
    }
  }
LAB_0011c94f:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}


// ===== 0011cbc0 __pfx_nv_alloc_contig_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011cc31) */

undefined8 __pfx_nv_alloc_contig_pages(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  nv_printf(0,"NVRM: VM: %s: %u pages\n","nv_alloc_contig_pages",*(undefined4 *)(param_2 + 0x20));
  cVar2 = os_is_xen_dom0();
  if (cVar2 != '\0') {
LAB_0011cc54:
    uVar4 = nv_alloc_coherent_pages(param_1,param_2);
    return uVar4;
  }
  uVar3 = (ulong)*(uint *)(param_2 + 0x20) * 0x1000 - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar3 != 0) {
    for (; uVar3 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  *(int *)(param_2 + 0x24) = (int)lVar1 + 1;
  uVar4 = nv_alloc_system_pages(param_1,param_2);
  if ((int)uVar4 != 0) {
    cVar2 = os_is_vgx_hyper();
    if (cVar2 != '\0') {
      nv_printf(0,"NVRM: VM: %s: failed to allocate memory, trying coherent memory \n",
                "nv_alloc_contig_pages");
      goto LAB_0011cc54;
    }
    nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_contig_pages");
    uVar4 = 0x51;
  }
  return uVar4;
}


// ===== 0011cbd0 nv_alloc_contig_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011cc31) */

undefined8 nv_alloc_contig_pages(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  nv_printf(0,"NVRM: VM: %s: %u pages\n","nv_alloc_contig_pages",*(undefined4 *)(param_2 + 0x20));
  cVar2 = os_is_xen_dom0();
  if (cVar2 != '\0') {
LAB_0011cc54:
    uVar4 = nv_alloc_coherent_pages(param_1,param_2);
    return uVar4;
  }
  uVar3 = (ulong)*(uint *)(param_2 + 0x20) * 0x1000 - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar3 != 0) {
    for (; uVar3 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  *(int *)(param_2 + 0x24) = (int)lVar1 + 1;
  uVar4 = nv_alloc_system_pages(param_1,param_2);
  if ((int)uVar4 != 0) {
    cVar2 = os_is_vgx_hyper();
    if (cVar2 != '\0') {
      nv_printf(0,"NVRM: VM: %s: failed to allocate memory, trying coherent memory \n",
                "nv_alloc_contig_pages");
      goto LAB_0011cc54;
    }
    nv_printf(0,"NVRM: VM: %s: failed to allocate memory\n","nv_alloc_contig_pages");
    uVar4 = 0x51;
  }
  return uVar4;
}


// ===== 0011cc80 __pfx_nv_free_contig_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_free_contig_pages(long param_1)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  long in_GS_OFFSET;
  long lStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  nv_printf(0,"NVRM: VM: %s: %u pages\n","nv_free_contig_pages",*(undefined4 *)(param_1 + 0x20));
  if ((*(byte *)(param_1 + 0x19) & 2) == 0) {
    if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
      nv_free_system_pages(param_1);
      return;
    }
    goto LAB_0011ce8f;
  }
  puVar1 = *(ulong **)(param_1 + 0x30);
  uVar2 = *(undefined8 *)(param_1 + 8);
  uVar6 = (ulong)*(uint *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x1c) != 0) {
    lStack_30 = 0;
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      iVar3 = os_alloc_mem(&lStack_30,uVar6 << 3);
      uVar5 = *(uint *)(param_1 + 0x20);
      uVar6 = (ulong)uVar5;
      if (iVar3 == 0) {
        if (lStack_30 != 0) {
          if (uVar5 == 0) {
            uVar5 = 0;
          }
          else {
            lVar4 = 0;
            do {
              *(ulong *)(lStack_30 + lVar4 * 8) =
                   (*(ulong *)(lVar4 * 0x10 + *(long *)(param_1 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar5 = *(uint *)(param_1 + 0x20);
              lVar4 = lVar4 + 1;
            } while ((uint)lVar4 < uVar5);
          }
          set_pages_array_wb(lStack_30,uVar5);
          os_free_mem(lStack_30);
          uVar6 = (ulong)*(uint *)(param_1 + 0x20);
          goto LAB_0011cd13;
        }
      }
      else {
        lStack_30 = 0;
      }
      lVar4 = 0;
      if (uVar5 != 0) {
        do {
          set_memory_wb((*(ulong *)(lVar4 * 0x10 + *(long *)(param_1 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          uVar6 = (ulong)*(uint *)(param_1 + 0x20);
          lVar4 = lVar4 + 1;
        } while ((uint)lVar4 < *(uint *)(param_1 + 0x20));
      }
    }
    else {
      set_memory_wb((*puVar1 & 0xfffffffffffff000) + _page_offset_base);
      uVar6 = (ulong)*(uint *)(param_1 + 0x20);
    }
  }
LAB_0011cd13:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    dma_free_attrs(uVar2,uVar6 << 0xc,puVar1[1],*(undefined8 *)(param_1 + 0x68),0);
    return;
  }
LAB_0011ce8f:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011cc90 nv_free_contig_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_free_contig_pages(long param_1)

{
  ulong *puVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  long in_GS_OFFSET;
  long local_30;
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  nv_printf(0,"NVRM: VM: %s: %u pages\n","nv_free_contig_pages",*(undefined4 *)(param_1 + 0x20));
  if ((*(byte *)(param_1 + 0x19) & 2) == 0) {
    if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
      nv_free_system_pages(param_1);
      return;
    }
    goto LAB_0011ce8f;
  }
  puVar1 = *(ulong **)(param_1 + 0x30);
  uVar2 = *(undefined8 *)(param_1 + 8);
  uVar6 = (ulong)*(uint *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x1c) != 0) {
    local_30 = 0;
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      iVar3 = os_alloc_mem(&local_30,uVar6 << 3);
      uVar5 = *(uint *)(param_1 + 0x20);
      uVar6 = (ulong)uVar5;
      if (iVar3 == 0) {
        if (local_30 != 0) {
          if (uVar5 == 0) {
            uVar5 = 0;
          }
          else {
            lVar4 = 0;
            do {
              *(ulong *)(local_30 + lVar4 * 8) =
                   (*(ulong *)(lVar4 * 0x10 + *(long *)(param_1 + 0x30)) >> 0xc) * 0x40 +
                   _vmemmap_base;
              uVar5 = *(uint *)(param_1 + 0x20);
              lVar4 = lVar4 + 1;
            } while ((uint)lVar4 < uVar5);
          }
          set_pages_array_wb(local_30,uVar5);
          os_free_mem(local_30);
          uVar6 = (ulong)*(uint *)(param_1 + 0x20);
          goto LAB_0011cd13;
        }
      }
      else {
        local_30 = 0;
      }
      lVar4 = 0;
      if (uVar5 != 0) {
        do {
          set_memory_wb((*(ulong *)(lVar4 * 0x10 + *(long *)(param_1 + 0x30)) & 0xfffffffffffff000)
                        + _page_offset_base,1);
          uVar6 = (ulong)*(uint *)(param_1 + 0x20);
          lVar4 = lVar4 + 1;
        } while ((uint)lVar4 < *(uint *)(param_1 + 0x20));
      }
    }
    else {
      set_memory_wb((*puVar1 & 0xfffffffffffff000) + _page_offset_base);
      uVar6 = (ulong)*(uint *)(param_1 + 0x20);
    }
  }
LAB_0011cd13:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    dma_free_attrs(uVar2,uVar6 << 0xc,puVar1[1],*(undefined8 *)(param_1 + 0x68),0);
    return;
  }
LAB_0011ce8f:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011cea0 __pfx_nv_vm_map_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011cefa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_vm_map_pages(undefined8 param_1,ulong param_2,undefined8 param_3,char param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  char extraout_DL;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    if (param_4 == '\0') {
      if (extraout_DL == '\0') {
        cachemode2protval(3);
      }
    }
    else if (extraout_DL == '\0') {
      uVar1 = cachemode2protval(3);
      cc_mkdec(___default_kernel_pte_mask & (uVar1 | 0x8000000000000163));
    }
    else {
      cc_mkdec(___default_kernel_pte_mask & 0x8000000000000163);
    }
    uVar2 = vmap(param_1);
    return uVar2;
  }
  nv_printf(4,"NVRM: %s: can\'t map %d pages, invalid context!\n","nv_vm_map_pages",
            param_2 & 0xffffffff);
  os_dbg_breakpoint();
  return 0;
}


// ===== 0011ceb0 nv_vm_map_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011cefa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_vm_map_pages(undefined8 param_1,ulong param_2,undefined8 param_3,char param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  char extraout_DL;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    if (param_4 == '\0') {
      if (extraout_DL == '\0') {
        cachemode2protval(3);
      }
    }
    else if (extraout_DL == '\0') {
      uVar1 = cachemode2protval(3);
      cc_mkdec(___default_kernel_pte_mask & (uVar1 | 0x8000000000000163));
    }
    else {
      cc_mkdec(___default_kernel_pte_mask & 0x8000000000000163);
    }
    uVar2 = vmap(param_1);
    return uVar2;
  }
  nv_printf(4,"NVRM: %s: can\'t map %d pages, invalid context!\n","nv_vm_map_pages",
            param_2 & 0xffffffff);
  os_dbg_breakpoint();
  return 0;
}


// ===== 0011cfd0 __pfx_nv_vm_unmap_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_vm_unmap_pages(undefined8 param_1,ulong param_2)

{
  byte extraout_AH;
  undefined8 in_R9;
  long in_GS_OFFSET;
  undefined8 uVar1;
  
  uVar1 = 0x11cfe9;
  (*_mpi_powm)();
  if (((extraout_AH & 2) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0))
  {
    vunmap();
    return;
  }
  nv_printf(4,"NVRM: %s: can\'t unmap %d pages at 0x%0llx, invalid context!\n","nv_vm_unmap_pages",
            param_2 & 0xffffffff,param_1,in_R9,uVar1);
  os_dbg_breakpoint();
  return;
}


// ===== 0011cfe0 nv_vm_unmap_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_vm_unmap_pages(undefined8 param_1,ulong param_2)

{
  byte extraout_AH;
  undefined8 in_R9;
  long in_GS_OFFSET;
  undefined8 uVar1;
  
  uVar1 = 0x11cfe9;
  (*_mpi_powm)();
  if (((extraout_AH & 2) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0))
  {
    vunmap();
    return;
  }
  nv_printf(4,"NVRM: %s: can\'t unmap %d pages at 0x%0llx, invalid context!\n","nv_vm_unmap_pages",
            param_2 & 0xffffffff,param_1,in_R9,uVar1);
  os_dbg_breakpoint();
  return;
}


// ===== 0011d030 __pfx_nv_get_kern_phys_address =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d072) */
/* WARNING: Removing unreachable block (ram,0x0011d092) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx_nv_get_kern_phys_address(ulong param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = __virt_addr_valid();
  if (cVar1 == '\0') {
    nv_printf(4,"NVRM: can\'t translate address in %s()!\n","nv_get_kern_phys_address");
    return 0;
  }
  lVar2 = _phys_base;
  if (param_1 < 0xffffffff80000000) {
    lVar2 = -0x80000000 - _page_offset_base;
  }
  return lVar2 + param_1 + 0x80000000;
}


// ===== 0011d040 nv_get_kern_phys_address =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d072) */
/* WARNING: Removing unreachable block (ram,0x0011d092) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long nv_get_kern_phys_address(ulong param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = __virt_addr_valid();
  if (cVar1 == '\0') {
    nv_printf(4,"NVRM: can\'t translate address in %s()!\n","nv_get_kern_phys_address");
    return 0;
  }
  lVar2 = _phys_base;
  if (param_1 < 0xffffffff80000000) {
    lVar2 = -0x80000000 - _page_offset_base;
  }
  return lVar2 + param_1 + 0x80000000;
}


// ===== 0011d0a0 __pfx_os_execute_work_item =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d126) */

void __pfx_os_execute_work_item(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  kfree();
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    rm_execute_work_item(0,uVar1);
    return;
  }
  puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    rm_execute_work_item(puVar3,uVar1);
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
      return;
    }
  }
  return;
}


// ===== 0011d0b0 os_execute_work_item =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d126) */

void os_execute_work_item(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  kfree();
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    rm_execute_work_item(0,uVar1);
    return;
  }
  puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    rm_execute_work_item(puVar3,uVar1);
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
      return;
    }
  }
  return;
}


// ===== 0011d140 __pfx_os_disable_console_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_disable_console_access(void)

{
  console_lock();
  return;
}


// ===== 0011d150 os_disable_console_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_disable_console_access(void)

{
  console_lock();
  return;
}


// ===== 0011d160 __pfx_os_enable_console_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_enable_console_access(void)

{
  console_unlock();
  return;
}


// ===== 0011d170 os_enable_console_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_enable_console_access(void)

{
  console_unlock();
  return;
}


// ===== 0011d180 __pfx_os_free_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d1b2) */

void __pfx_os_free_mutex(long param_1)

{
  if (param_1 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d190 os_free_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d1b2) */

void os_free_mutex(long param_1)

{
  if (param_1 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d1c0 __pfx_os_acquire_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d1f8) */
/* WARNING: Removing unreachable block (ram,0x0011d202) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_acquire_mutex(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    down();
    return 0;
  }
  return 0x3f;
}


// ===== 0011d1d0 os_acquire_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d1f8) */
/* WARNING: Removing unreachable block (ram,0x0011d202) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_acquire_mutex(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    down();
    return 0;
  }
  return 0x3f;
}


// ===== 0011d210 __pfx_os_cond_acquire_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d24d) */
/* WARNING: Removing unreachable block (ram,0x0011d257) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __pfx_os_cond_acquire_mutex(void)

{
  int iVar1;
  ulong uVar2;
  long in_GS_OFFSET;
  
  uVar2 = (*_mpi_powm)();
  if (((uVar2 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    iVar1 = down_trylock();
    return -(iVar1 != 0) & 0x66;
  }
  return 0x3f;
}


// ===== 0011d220 os_cond_acquire_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d24d) */
/* WARNING: Removing unreachable block (ram,0x0011d257) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte os_cond_acquire_mutex(void)

{
  int iVar1;
  ulong uVar2;
  long in_GS_OFFSET;
  
  uVar2 = (*_mpi_powm)();
  if (((uVar2 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    iVar1 = down_trylock();
    return -(iVar1 != 0) & 0x66;
  }
  return 0x3f;
}


// ===== 0011d260 __pfx_os_release_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_release_mutex(void)

{
  up();
  return;
}


// ===== 0011d270 os_release_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_release_mutex(void)

{
  up();
  return;
}


// ===== 0011d280 __pfx_os_free_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_free_semaphore(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d290 os_free_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_free_semaphore(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d2b0 __pfx_os_acquire_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_acquire_semaphore(void)

{
  os_acquire_mutex();
  return;
}


// ===== 0011d2c0 os_acquire_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_acquire_semaphore(void)

{
  os_acquire_mutex();
  return;
}


// ===== 0011d2d0 __pfx_os_cond_acquire_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d2f5) */

byte __pfx_os_cond_acquire_semaphore(void)

{
  int iVar1;
  
  iVar1 = down_trylock();
  return -(iVar1 != 0) & 0x66;
}


// ===== 0011d2e0 os_cond_acquire_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d2f5) */

byte os_cond_acquire_semaphore(void)

{
  int iVar1;
  
  iVar1 = down_trylock();
  return -(iVar1 != 0) & 0x66;
}


// ===== 0011d300 __pfx_os_release_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d320) */

undefined8 __pfx_os_release_semaphore(void)

{
  up();
  return 0;
}


// ===== 0011d310 os_release_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d320) */

undefined8 os_release_semaphore(void)

{
  up();
  return 0;
}


