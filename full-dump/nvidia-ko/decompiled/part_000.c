// ===== 00103140 __pfx_nv_platform_device_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010315b) */

undefined8 __pfx_nv_platform_device_probe(void)

{
  return 0;
}


// ===== 00103150 nv_platform_device_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010315b) */

undefined8 nv_platform_device_probe(void)

{
  return 0;
}


// ===== 00103160 __pfx_nvidia_soc_isr_kthread_bh =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103275) */

undefined4 __pfx_nvidia_soc_isr_kthread_bh(int param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int *piVar6;
  uint uVar7;
  
  lVar1 = *(long *)(param_2 + 8);
  iVar3 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x5150));
  if (iVar3 != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar4 = nvidia_isr_kthread_bh(param_1,param_2);
  os_release_mutex(*(undefined8 *)(lVar1 + 0x5150));
  uVar5 = _raw_spin_lock_irqsave(lVar1 + 0x514c);
  if (*(int *)(param_2 + 0x284) != 0) {
    piVar6 = (int *)(param_2 + 0x1b8);
    uVar7 = 0;
    do {
      while( true ) {
        if (*piVar6 == param_1) {
          *(undefined1 *)(piVar6 + 2) = 0;
        }
        if (piVar6[4] != 0) break;
        piVar6[4] = 1;
        uVar7 = uVar7 + 1;
        piVar6 = piVar6 + 5;
        enable_irq();
        if (*(uint *)(param_2 + 0x284) <= uVar7) goto LAB_00103243;
      }
      uVar7 = uVar7 + 1;
      piVar6 = piVar6 + 5;
    } while (uVar7 < *(uint *)(param_2 + 0x284));
  }
LAB_00103243:
  *(undefined4 *)(param_2 + 0x280) = 0xffffffff;
  _raw_spin_unlock_irqrestore(lVar1 + 0x514c,uVar5);
  return uVar4;
}


// ===== 00103170 nvidia_soc_isr_kthread_bh =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103275) */

undefined4 nvidia_soc_isr_kthread_bh(int param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int *piVar6;
  uint uVar7;
  
  lVar1 = *(long *)(param_2 + 8);
  iVar3 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x5150));
  if (iVar3 != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar4 = nvidia_isr_kthread_bh(param_1,param_2);
  os_release_mutex(*(undefined8 *)(lVar1 + 0x5150));
  uVar5 = _raw_spin_lock_irqsave(lVar1 + 0x514c);
  if (*(int *)(param_2 + 0x284) != 0) {
    piVar6 = (int *)(param_2 + 0x1b8);
    uVar7 = 0;
    do {
      while( true ) {
        if (*piVar6 == param_1) {
          *(undefined1 *)(piVar6 + 2) = 0;
        }
        if (piVar6[4] != 0) break;
        piVar6[4] = 1;
        uVar7 = uVar7 + 1;
        piVar6 = piVar6 + 5;
        enable_irq();
        if (*(uint *)(param_2 + 0x284) <= uVar7) goto LAB_00103243;
      }
      uVar7 = uVar7 + 1;
      piVar6 = piVar6 + 5;
    } while (uVar7 < *(uint *)(param_2 + 0x284));
  }
LAB_00103243:
  *(undefined4 *)(param_2 + 0x280) = 0xffffffff;
  _raw_spin_unlock_irqrestore(lVar1 + 0x514c,uVar5);
  return uVar4;
}


// ===== 00103290 __pfx_nvidia_soc_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103336) */
/* WARNING: Removing unreachable block (ram,0x0010339d) */

int __pfx_nvidia_soc_isr(int param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  int *piVar8;
  
  lVar1 = param_2 + 0x5148;
  lVar2 = param_2 + 0x514c;
  _raw_spin_lock_irqsave(lVar1);
  uVar6 = _raw_spin_lock_irqsave(lVar2);
  if (*(uint *)(param_2 + 0x284) != 0) {
    pcVar7 = (char *)(param_2 + 0x1c0);
    pcVar3 = pcVar7 + (ulong)*(uint *)(param_2 + 0x284) * 0x14;
    do {
      if (*pcVar7 == '\x01') {
        _raw_spin_unlock_irqrestore(lVar2,uVar6);
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        return 0;
      }
      pcVar7 = pcVar7 + 0x14;
    } while (pcVar7 != pcVar3);
  }
  *(int *)(param_2 + 0x280) = param_1;
  _raw_spin_unlock_irqrestore(lVar2,uVar6);
  iVar5 = nvidia_isr(param_1,param_2);
  uVar6 = _raw_spin_lock_irqsave(lVar2);
  if (iVar5 == 2) {
    if (*(uint *)(param_2 + 0x284) != 0) {
      piVar8 = (int *)(param_2 + 0x1b8);
      piVar4 = piVar8 + (ulong)*(uint *)(param_2 + 0x284) * 5;
      do {
        if (*piVar8 == param_1) {
          *(undefined1 *)(piVar8 + 2) = 1;
        }
        piVar8 = piVar8 + 5;
      } while (piVar8 != piVar4);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x280) = 0xffffffff;
  }
  _raw_spin_unlock_irqrestore(lVar2);
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
  return iVar5;
}


// ===== 001032a0 nvidia_soc_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103336) */
/* WARNING: Removing unreachable block (ram,0x0010339d) */

int nvidia_soc_isr(int param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  int *piVar8;
  
  lVar1 = param_2 + 0x5148;
  lVar2 = param_2 + 0x514c;
  _raw_spin_lock_irqsave(lVar1);
  uVar6 = _raw_spin_lock_irqsave(lVar2);
  if (*(uint *)(param_2 + 0x284) != 0) {
    pcVar7 = (char *)(param_2 + 0x1c0);
    pcVar3 = pcVar7 + (ulong)*(uint *)(param_2 + 0x284) * 0x14;
    do {
      if (*pcVar7 == '\x01') {
        _raw_spin_unlock_irqrestore(lVar2,uVar6);
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        return 0;
      }
      pcVar7 = pcVar7 + 0x14;
    } while (pcVar7 != pcVar3);
  }
  *(int *)(param_2 + 0x280) = param_1;
  _raw_spin_unlock_irqrestore(lVar2,uVar6);
  iVar5 = nvidia_isr(param_1,param_2);
  uVar6 = _raw_spin_lock_irqsave(lVar2);
  if (iVar5 == 2) {
    if (*(uint *)(param_2 + 0x284) != 0) {
      piVar8 = (int *)(param_2 + 0x1b8);
      piVar4 = piVar8 + (ulong)*(uint *)(param_2 + 0x284) * 5;
      do {
        if (*piVar8 == param_1) {
          *(undefined1 *)(piVar8 + 2) = 1;
        }
        piVar8 = piVar8 + 5;
      } while (piVar8 != piVar4);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x280) = 0xffffffff;
  }
  _raw_spin_unlock_irqrestore(lVar2);
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
  return iVar5;
}


// ===== 001033e0 __pfx_nv_soc_free_irq_by_type =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010346b) */
/* WARNING: Removing unreachable block (ram,0x00103470) */

void __pfx_nv_soc_free_irq_by_type(long param_1,int param_2)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x284) == 0) {
    return;
  }
  uVar1 = *(undefined8 *)(param_1 + 8);
  puVar2 = (undefined4 *)(param_1 + 0x1b8);
  do {
    if (puVar2[1] != param_2) {
      if (puVar2 + 5 == (undefined4 *)(param_1 + 0x280)) {
        return;
      }
      return;
    }
    puVar3 = puVar2 + 5;
    free_irq(*puVar2,uVar1);
    puVar2[1] = 0;
    *puVar2 = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
    puVar2[4] = 0;
    *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + -1;
    puVar2 = puVar3;
  } while (puVar3 != (undefined4 *)(param_1 + 0x280));
  return;
}


// ===== 001033f0 nv_soc_free_irq_by_type =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010346b) */
/* WARNING: Removing unreachable block (ram,0x00103470) */

void nv_soc_free_irq_by_type(long param_1,int param_2)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x284) == 0) {
    return;
  }
  uVar1 = *(undefined8 *)(param_1 + 8);
  puVar2 = (undefined4 *)(param_1 + 0x1b8);
  do {
    if (puVar2[1] != param_2) {
      if (puVar2 + 5 == (undefined4 *)(param_1 + 0x280)) {
        return;
      }
      return;
    }
    puVar3 = puVar2 + 5;
    free_irq(*puVar2,uVar1);
    puVar2[1] = 0;
    *puVar2 = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
    puVar2[4] = 0;
    *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + -1;
    puVar2 = puVar3;
  } while (puVar3 != (undefined4 *)(param_1 + 0x280));
  return;
}


// ===== 00103480 __pfx_nv_platform_device_shutdown =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001034ae) */

void __pfx_nv_platform_device_shutdown(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x88);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x51a2) == '\0')) {
    nvidia_modeset_remove(*(undefined4 *)(lVar1 + 0x24));
    return;
  }
  return;
}


// ===== 00103490 nv_platform_device_shutdown =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001034ae) */

void nv_platform_device_shutdown(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x88);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x51a2) == '\0')) {
    nvidia_modeset_remove(*(undefined4 *)(lVar1 + 0x24));
    return;
  }
  return;
}


// ===== 001034c0 __pfx_nv_platform_device_remove_wrapper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001034d9) */

void __pfx_nv_platform_device_remove_wrapper(void)

{
  return;
}


// ===== 001034d0 nv_platform_device_remove_wrapper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001034d9) */

void nv_platform_device_remove_wrapper(void)

{
  return;
}


// ===== 001034e0 __pfx_nv_request_soc_irq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001035bb) */
/* WARNING: Removing unreachable block (ram,0x001035fb) */

int __pfx_nv_request_soc_irq
              (long param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
              undefined8 param_6)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  
  if (*(uint *)(param_1 + 0x284) < 10) {
    iVar3 = request_threaded_irq
                      (param_2,nvidia_soc_isr,nvidia_soc_isr_kthread_bh,param_4,param_6,param_1);
    if (iVar3 != 0) {
      nv_printf(4,"nv_request_soc_irq for irq %d failed\n",param_2);
      return iVar3;
    }
    disable_irq_nosync(param_2);
    uVar2 = *(uint *)(param_1 + 0x284);
    lVar1 = param_1 + (ulong)uVar2 * 0x14;
    *(undefined4 *)(lVar1 + 0x1b8) = param_2;
    *(int *)(lVar1 + 0x1bc) = param_3;
    if ((param_3 == 3) || (param_3 == 2)) {
      *(undefined4 *)(lVar1 + 0x1c4) = param_5;
    }
    *(uint *)(param_1 + 0x284) = uVar2 + 1;
    *(undefined4 *)(param_1 + 0x1c8 + (ulong)uVar2 * 0x14) = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = -0x16;
    nv_printf(4,"Exceeds Maximum SOC interrupts\n");
  }
  return iVar3;
}


// ===== 001034f0 nv_request_soc_irq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001035bb) */
/* WARNING: Removing unreachable block (ram,0x001035fb) */

int nv_request_soc_irq(long param_1,undefined4 param_2,int param_3,undefined4 param_4,
                      undefined4 param_5,undefined8 param_6)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  
  if (*(uint *)(param_1 + 0x284) < 10) {
    iVar3 = request_threaded_irq
                      (param_2,nvidia_soc_isr,nvidia_soc_isr_kthread_bh,param_4,param_6,param_1);
    if (iVar3 != 0) {
      nv_printf(4,"nv_request_soc_irq for irq %d failed\n",param_2);
      return iVar3;
    }
    disable_irq_nosync(param_2);
    uVar2 = *(uint *)(param_1 + 0x284);
    lVar1 = param_1 + (ulong)uVar2 * 0x14;
    *(undefined4 *)(lVar1 + 0x1b8) = param_2;
    *(int *)(lVar1 + 0x1bc) = param_3;
    if ((param_3 == 3) || (param_3 == 2)) {
      *(undefined4 *)(lVar1 + 0x1c4) = param_5;
    }
    *(uint *)(param_1 + 0x284) = uVar2 + 1;
    *(undefined4 *)(param_1 + 0x1c8 + (ulong)uVar2 * 0x14) = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = -0x16;
    nv_printf(4,"Exceeds Maximum SOC interrupts\n");
  }
  return iVar3;
}


// ===== 00103620 __pfx_nv_get_current_irq_type =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010367a) */
/* WARNING: Removing unreachable block (ram,0x00103684) */

undefined4 __pfx_nv_get_current_irq_type(long param_1)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  
  if (*(uint *)(param_1 + 0x284) != 0) {
    piVar3 = (int *)(param_1 + 0x1b8);
    uVar2 = 0;
    do {
      if (*piVar3 == *(int *)(param_1 + 0x280)) {
        return *(undefined4 *)(param_1 + 0x1bc + uVar2 * 0x14);
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulong)uVar1;
      piVar3 = piVar3 + 5;
    } while (uVar1 != *(uint *)(param_1 + 0x284));
  }
  return 6;
}


// ===== 00103630 nv_get_current_irq_type =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010367a) */
/* WARNING: Removing unreachable block (ram,0x00103684) */

undefined4 nv_get_current_irq_type(long param_1)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  
  if (*(uint *)(param_1 + 0x284) != 0) {
    piVar3 = (int *)(param_1 + 0x1b8);
    uVar2 = 0;
    do {
      if (*piVar3 == *(int *)(param_1 + 0x280)) {
        return *(undefined4 *)(param_1 + 0x1bc + uVar2 * 0x14);
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulong)uVar1;
      piVar3 = piVar3 + 5;
    } while (uVar1 != *(uint *)(param_1 + 0x284));
  }
  return 6;
}


// ===== 00103690 __pfx_nv_get_current_irq_priv_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103718) */
/* WARNING: Removing unreachable block (ram,0x0010373a) */

undefined4 __pfx_nv_get_current_irq_priv_data(long param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x280);
  if (iVar2 == -1) {
    nv_printf(4,"%s:No SOC interrupt in progress\n","nv_get_current_irq_priv_data");
    return 0xffff;
  }
  if (*(int *)(param_1 + 0x284) != 0) {
    piVar1 = (int *)(param_1 + 0x1b8);
    iVar3 = 0;
    do {
      if ((*piVar1 == iVar2) && ((piVar1[1] == 3 || (piVar1[1] == 2)))) {
        *param_2 = piVar1[3];
        if (*(uint *)(param_1 + 0x284) <= iVar3 + 1U) {
          return 0;
        }
      }
      else if (*(uint *)(param_1 + 0x284) <= iVar3 + 1U) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      iVar2 = *(int *)(param_1 + 0x280);
      piVar1 = piVar1 + 5;
    } while( true );
  }
  return 0;
}


// ===== 001036a0 nv_get_current_irq_priv_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103718) */
/* WARNING: Removing unreachable block (ram,0x0010373a) */

undefined4 nv_get_current_irq_priv_data(long param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x280);
  if (iVar2 == -1) {
    nv_printf(4,"%s:No SOC interrupt in progress\n","nv_get_current_irq_priv_data");
    return 0xffff;
  }
  if (*(int *)(param_1 + 0x284) != 0) {
    piVar1 = (int *)(param_1 + 0x1b8);
    iVar3 = 0;
    do {
      if ((*piVar1 == iVar2) && ((piVar1[1] == 3 || (piVar1[1] == 2)))) {
        *param_2 = piVar1[3];
        if (*(uint *)(param_1 + 0x284) <= iVar3 + 1U) {
          return 0;
        }
      }
      else if (*(uint *)(param_1 + 0x284) <= iVar3 + 1U) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      iVar2 = *(int *)(param_1 + 0x280);
      piVar1 = piVar1 + 5;
    } while( true );
  }
  return 0;
}


// ===== 00103740 __pfx_nv_soc_register_irqs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010395f) */
/* WARNING: Removing unreachable block (ram,0x00103924) */
/* WARNING: Removing unreachable block (ram,0x00103901) */
/* WARNING: Removing unreachable block (ram,0x0010398b) */

int __pfx_nv_soc_register_irqs(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  if (*(char *)(param_1 + 0x2f8) == '\0') {
    uVar1 = *(undefined8 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x280) = 0xffffffff;
    iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x17c),1,
                               (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,0,"nvdisplay");
    if (iVar2 != 0) {
      nv_printf(4,"failed to request display irq (%d)\n",iVar2);
      return iVar2;
    }
    iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x288),4,
                               (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,0,"hdacodec");
    if (iVar2 != 0) {
      nv_printf(4,"failed to request hdacodec irq (%d)\n",iVar2);
      free_irq(*(undefined4 *)(param_1 + 0x17c),uVar1);
      return iVar2;
    }
    if ((*(char *)(param_1 + 0x2a0) != '\0') &&
       (iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x28c),5,
                                   (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,0,
                                   "tcpc2disp"), iVar2 != 0)) {
      nv_printf(4,"failed to request Tcpc2disp irq (%d)\n",iVar2);
      free_irq(*(undefined4 *)(param_1 + 0x17c),uVar1);
      free_irq(*(undefined4 *)(param_1 + 0x288),uVar1);
      return iVar2;
    }
    if (*(int *)(param_1 + 0x178) != 0) {
      uVar3 = 0;
      lVar4 = param_1 + 400;
      do {
        iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x180 + uVar3 * 4),2,
                                   (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,
                                   uVar3 & 0xffffffff,lVar4);
        if (iVar2 != 0) {
          nv_printf(4,"failed to request dpaux irq (%d)\n",iVar2);
          free_irq(*(undefined4 *)(param_1 + 0x17c),uVar1);
          free_irq(*(undefined4 *)(param_1 + 0x288),uVar1);
          if (*(char *)(param_1 + 0x2a0) != '\0') {
            free_irq(*(undefined4 *)(param_1 + 0x28c),uVar1);
            return iVar2;
          }
          return iVar2;
        }
        uVar3 = uVar3 + 1;
        lVar4 = lVar4 + 10;
      } while ((uint)uVar3 < *(uint *)(param_1 + 0x178));
      return 0;
    }
  }
  return 0;
}


// ===== 00103750 nv_soc_register_irqs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010395f) */
/* WARNING: Removing unreachable block (ram,0x00103924) */
/* WARNING: Removing unreachable block (ram,0x00103901) */
/* WARNING: Removing unreachable block (ram,0x0010398b) */

int nv_soc_register_irqs(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  if (*(char *)(param_1 + 0x2f8) == '\0') {
    uVar1 = *(undefined8 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x280) = 0xffffffff;
    iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x17c),1,
                               (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,0,"nvdisplay");
    if (iVar2 != 0) {
      nv_printf(4,"failed to request display irq (%d)\n",iVar2);
      return iVar2;
    }
    iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x288),4,
                               (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,0,"hdacodec");
    if (iVar2 != 0) {
      nv_printf(4,"failed to request hdacodec irq (%d)\n",iVar2);
      free_irq(*(undefined4 *)(param_1 + 0x17c),uVar1);
      return iVar2;
    }
    if ((*(char *)(param_1 + 0x2a0) != '\0') &&
       (iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x28c),5,
                                   (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,0,
                                   "tcpc2disp"), iVar2 != 0)) {
      nv_printf(4,"failed to request Tcpc2disp irq (%d)\n",iVar2);
      free_irq(*(undefined4 *)(param_1 + 0x17c),uVar1);
      free_irq(*(undefined4 *)(param_1 + 0x288),uVar1);
      return iVar2;
    }
    if (*(int *)(param_1 + 0x178) != 0) {
      uVar3 = 0;
      lVar4 = param_1 + 400;
      do {
        iVar2 = nv_request_soc_irq(uVar1,*(undefined4 *)(param_1 + 0x180 + uVar3 * 4),2,
                                   (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,
                                   uVar3 & 0xffffffff,lVar4);
        if (iVar2 != 0) {
          nv_printf(4,"failed to request dpaux irq (%d)\n",iVar2);
          free_irq(*(undefined4 *)(param_1 + 0x17c),uVar1);
          free_irq(*(undefined4 *)(param_1 + 0x288),uVar1);
          if (*(char *)(param_1 + 0x2a0) != '\0') {
            free_irq(*(undefined4 *)(param_1 + 0x28c),uVar1);
            return iVar2;
          }
          return iVar2;
        }
        uVar3 = uVar3 + 1;
        lVar4 = lVar4 + 10;
      } while ((uint)uVar3 < *(uint *)(param_1 + 0x178));
      return 0;
    }
  }
  return 0;
}


// ===== 001039f0 __pfx_nv_soc_free_irqs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103a48) */

void __pfx_nv_soc_free_irqs(long param_1)

{
  nv_soc_free_irq_by_type(param_1,1);
  nv_soc_free_irq_by_type(param_1,4);
  nv_soc_free_irq_by_type(param_1,2);
  nv_soc_free_irq_by_type(param_1,3);
  if (*(char *)(param_1 + 0x2a0) == '\0') {
    return;
  }
  nv_soc_free_irq_by_type(param_1,5);
  return;
}


// ===== 00103a00 nv_soc_free_irqs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103a48) */

void nv_soc_free_irqs(long param_1)

{
  nv_soc_free_irq_by_type(param_1,1);
  nv_soc_free_irq_by_type(param_1,4);
  nv_soc_free_irq_by_type(param_1,2);
  nv_soc_free_irq_by_type(param_1,3);
  if (*(char *)(param_1 + 0x2a0) == '\0') {
    return;
  }
  nv_soc_free_irq_by_type(param_1,5);
  return;
}


// ===== 00103a60 __pfx_nv_soc_device_reset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103a7b) */

undefined8 __pfx_nv_soc_device_reset(void)

{
  return 0;
}


// ===== 00103a70 nv_soc_device_reset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103a7b) */

undefined8 nv_soc_device_reset(void)

{
  return 0;
}


// ===== 00103a80 __pfx_nv_soc_mipi_cal_reset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103a9b) */

undefined8 __pfx_nv_soc_mipi_cal_reset(void)

{
  return 0;
}


// ===== 00103a90 nv_soc_mipi_cal_reset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103a9b) */

undefined8 nv_soc_mipi_cal_reset(void)

{
  return 0;
}


// ===== 00103aa0 __pfx_nv_platform_count_devices =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103abb) */

undefined8 __pfx_nv_platform_count_devices(void)

{
  return 0;
}


// ===== 00103ab0 nv_platform_count_devices =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103abb) */

undefined8 nv_platform_count_devices(void)

{
  return 0;
}


// ===== 00103ac0 __pfx_nv_platform_register_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103ae5) */

undefined8 __pfx_nv_platform_register_driver(void)

{
  undefined8 uVar1;
  
  if (NVreg_RegisterPlatformDeviceDriver == 0) {
    return 0;
  }
  uVar1 = __platform_driver_register(nv_platform_driver,__this_module);
  return uVar1;
}


// ===== 00103ad0 nv_platform_register_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103ae5) */

undefined8 nv_platform_register_driver(void)

{
  undefined8 uVar1;
  
  if (NVreg_RegisterPlatformDeviceDriver == 0) {
    return 0;
  }
  uVar1 = __platform_driver_register(nv_platform_driver,__this_module);
  return uVar1;
}


// ===== 00103b00 __pfx_nv_platform_unregister_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103b23) */

void __pfx_nv_platform_unregister_driver(void)

{
  if (NVreg_RegisterPlatformDeviceDriver == 0) {
    return;
  }
  platform_driver_unregister(nv_platform_driver);
  return;
}


// ===== 00103b10 nv_platform_unregister_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103b23) */

void nv_platform_unregister_driver(void)

{
  if (NVreg_RegisterPlatformDeviceDriver == 0) {
    return;
  }
  platform_driver_unregister(nv_platform_driver);
  return;
}


// ===== 00103b40 __pfx_nv_soc_fuse_register_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103b5b) */

undefined8 __pfx_nv_soc_fuse_register_read(void)

{
  return 0;
}


// ===== 00103b50 nv_soc_fuse_register_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103b5b) */

undefined8 nv_soc_fuse_register_read(void)

{
  return 0;
}


// ===== 00103b60 __pfx_nv_soc_tsec_send_cmd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103b7e) */

undefined8 __pfx_nv_soc_tsec_send_cmd(void)

{
  return 0x56;
}


// ===== 00103b70 nv_soc_tsec_send_cmd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103b7e) */

undefined8 nv_soc_tsec_send_cmd(void)

{
  return 0x56;
}


// ===== 00103b90 __pfx_nv_soc_tsec_event_register =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103bae) */

undefined8 __pfx_nv_soc_tsec_event_register(void)

{
  return 0x56;
}


// ===== 00103ba0 nv_soc_tsec_event_register =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103bae) */

undefined8 nv_soc_tsec_event_register(void)

{
  return 0x56;
}


// ===== 00103bc0 __pfx_nv_soc_tsec_event_unregister =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103bde) */

undefined8 __pfx_nv_soc_tsec_event_unregister(void)

{
  return 0x56;
}


// ===== 00103bd0 nv_soc_tsec_event_unregister =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103bde) */

undefined8 nv_soc_tsec_event_unregister(void)

{
  return 0x56;
}


// ===== 00103bf0 __pfx_nv_soc_tsec_alloc_mem_desc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103c0b) */

undefined8 __pfx_nv_soc_tsec_alloc_mem_desc(void)

{
  return 0;
}


// ===== 00103c00 nv_soc_tsec_alloc_mem_desc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103c0b) */

undefined8 nv_soc_tsec_alloc_mem_desc(void)

{
  return 0;
}


// ===== 00103c10 __pfx_nv_soc_tsec_free_mem_desc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103c29) */

void __pfx_nv_soc_tsec_free_mem_desc(void)

{
  return;
}


// ===== 00103c20 nv_soc_tsec_free_mem_desc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103c29) */

void nv_soc_tsec_free_mem_desc(void)

{
  return;
}


// ===== 00103c30 __pfx_nv_get_valid_window_head_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103c70) */
/* WARNING: Removing unreachable block (ram,0x00103c8b) */

undefined8 __pfx_nv_get_valid_window_head_mask(long param_1,long param_2)

{
  if ((*(long *)(param_1 + 8) != 0) && (param_2 != 0)) {
    nv_printf(4,"NVRM: failed to read device node window-head-mask ret=%d\n",0xffffffda);
    return 0xffff;
  }
  nv_printf(4,"NVRM: Wrong input arguments \n");
  return 0x1f;
}


// ===== 00103c40 nv_get_valid_window_head_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103c70) */
/* WARNING: Removing unreachable block (ram,0x00103c8b) */

undefined8 nv_get_valid_window_head_mask(long param_1,long param_2)

{
  if ((*(long *)(param_1 + 8) != 0) && (param_2 != 0)) {
    nv_printf(4,"NVRM: failed to read device node window-head-mask ret=%d\n",0xffffffda);
    return 0xffff;
  }
  nv_printf(4,"NVRM: Wrong input arguments \n");
  return 0x1f;
}


// ===== 00103c90 __pfx_nv_soc_i2c_hsp_semaphore_acquire =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103cab) */

undefined8 __pfx_nv_soc_i2c_hsp_semaphore_acquire(void)

{
  return 0;
}


// ===== 00103ca0 nv_soc_i2c_hsp_semaphore_acquire =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103cab) */

undefined8 nv_soc_i2c_hsp_semaphore_acquire(void)

{
  return 0;
}


// ===== 00103cb0 __pfx_nv_get_hdcp_enabled =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103ccb) */

undefined8 __pfx_nv_get_hdcp_enabled(void)

{
  return 0;
}


// ===== 00103cc0 nv_get_hdcp_enabled =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103ccb) */

undefined8 nv_get_hdcp_enabled(void)

{
  return 0;
}


// ===== 00103cd0 __pfx_nv_dsi_is_panel_connected =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103ceb) */

undefined8 __pfx_nv_dsi_is_panel_connected(void)

{
  return 0;
}


// ===== 00103ce0 nv_dsi_is_panel_connected =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103ceb) */

undefined8 nv_dsi_is_panel_connected(void)

{
  return 0;
}


// ===== 00103cf0 __pfx_nv_dsi_parse_panel_props =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103d1f) */

undefined8 __pfx_nv_dsi_parse_panel_props(void)

{
  nv_printf(4,"NVRM: None of the dsi panel nodes enabled in DT!\n");
  return 0xffffffea;
}


// ===== 00103d00 nv_dsi_parse_panel_props =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103d1f) */

undefined8 nv_dsi_parse_panel_props(void)

{
  nv_printf(4,"NVRM: None of the dsi panel nodes enabled in DT!\n");
  return 0xffffffea;
}


// ===== 00103d30 __pfx_nv_dsi_panel_enable =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103e16) */

undefined8 __pfx_nv_dsi_panel_enable(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (-1 < *(int *)(param_2 + 0x11c)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x118)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x110)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x108)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return 0;
}


// ===== 00103d40 nv_dsi_panel_enable =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103e16) */

undefined8 nv_dsi_panel_enable(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (-1 < *(int *)(param_2 + 0x11c)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x118)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x110)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x108)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,1);
  }
  lVar2 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return 0;
}


// ===== 00103e20 __pfx_nv_dsi_panel_reset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103f21) */
/* WARNING: Removing unreachable block (ram,0x00103ed0) */
/* WARNING: Removing unreachable block (ram,0x00103ef0) */

int __pfx_nv_dsi_panel_reset(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  iVar1 = *(int *)(param_2 + 0x104);
  if (iVar1 < 0) {
    nv_printf(4,"DSI Panel reset gpio invalid\n");
    return 0;
  }
  uVar3 = gpio_to_desc(iVar1);
  iVar2 = gpiod_direction_output_raw(uVar3,1);
  if (-1 < iVar2) {
    lVar4 = 10;
    do {
      __const_udelay(0x418958);
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    lVar4 = 10;
    uVar3 = gpio_to_desc(iVar1);
    iVar2 = gpiod_direction_output_raw(uVar3,0);
    if (iVar2 < 0) {
      nv_printf(4,"Asserting DSI panel reset gpio failed\n");
    }
    else {
      do {
        __const_udelay(0x418958);
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = gpio_to_desc(iVar1);
      iVar2 = gpiod_direction_output_raw(uVar3,1);
      if (iVar2 < 0) {
        nv_printf(4,"Deasserting Dsi panel reset gpio after asserting failed\n");
      }
    }
    return iVar2;
  }
  nv_printf(4,"Deasserting DSI panel reset gpio failed\n");
  return iVar2;
}


// ===== 00103e30 nv_dsi_panel_reset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00103f21) */
/* WARNING: Removing unreachable block (ram,0x00103ed0) */
/* WARNING: Removing unreachable block (ram,0x00103ef0) */

int nv_dsi_panel_reset(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  iVar1 = *(int *)(param_2 + 0x104);
  if (iVar1 < 0) {
    nv_printf(4,"DSI Panel reset gpio invalid\n");
    return 0;
  }
  uVar3 = gpio_to_desc(iVar1);
  iVar2 = gpiod_direction_output_raw(uVar3,1);
  if (-1 < iVar2) {
    lVar4 = 10;
    do {
      __const_udelay(0x418958);
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    lVar4 = 10;
    uVar3 = gpio_to_desc(iVar1);
    iVar2 = gpiod_direction_output_raw(uVar3,0);
    if (iVar2 < 0) {
      nv_printf(4,"Asserting DSI panel reset gpio failed\n");
    }
    else {
      do {
        __const_udelay(0x418958);
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = gpio_to_desc(iVar1);
      iVar2 = gpiod_direction_output_raw(uVar3,1);
      if (iVar2 < 0) {
        nv_printf(4,"Deasserting Dsi panel reset gpio after asserting failed\n");
      }
    }
    return iVar2;
  }
  nv_printf(4,"Deasserting DSI panel reset gpio failed\n");
  return iVar2;
}


// ===== 00103f50 __pfx_nv_dsi_panel_disable =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010401d) */

void __pfx_nv_dsi_panel_disable(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (-1 < *(int *)(param_2 + 0x110)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x108)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  if (-1 < *(int *)(param_2 + 0x104)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  lVar2 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x118)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (*(int *)(param_2 + 0x11c) < 0) {
    return;
  }
  uVar1 = gpio_to_desc();
  gpiod_direction_output_raw(uVar1,0);
  return;
}


// ===== 00103f60 nv_dsi_panel_disable =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010401d) */

void nv_dsi_panel_disable(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (-1 < *(int *)(param_2 + 0x110)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x108)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  if (-1 < *(int *)(param_2 + 0x104)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  lVar2 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (-1 < *(int *)(param_2 + 0x118)) {
    uVar1 = gpio_to_desc();
    gpiod_direction_output_raw(uVar1,0);
  }
  lVar2 = 10;
  do {
    __const_udelay(0x418958);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (*(int *)(param_2 + 0x11c) < 0) {
    return;
  }
  uVar1 = gpio_to_desc();
  gpiod_direction_output_raw(uVar1,0);
  return;
}


// ===== 00104040 __pfx_nv_dsi_panel_cleanup =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010413b) */

void __pfx_nv_dsi_panel_cleanup(undefined8 param_1,long param_2)

{
  int *piVar1;
  
  if ((*(ulong *)(param_2 + 0x28) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x28) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0x48) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x48) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0x68) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x68) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0x88) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x88) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0xa8) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0xa8) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0xd0) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0xd0) != 0)) {
    kfree();
  }
  if (*(long *)(param_2 + 0x158) != 0) {
    kfree();
  }
  piVar1 = (int *)(param_2 + 0x104);
  do {
    if (-1 < *piVar1) {
      gpio_free();
    }
    piVar1 = piVar1 + 1;
  } while ((int *)(param_2 + 0x130) != piVar1);
  *(undefined1 *)(param_2 + 0x130) = 0;
  return;
}


// ===== 00104050 nv_dsi_panel_cleanup =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010413b) */

void nv_dsi_panel_cleanup(undefined8 param_1,long param_2)

{
  int *piVar1;
  
  if ((*(ulong *)(param_2 + 0x28) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x28) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0x48) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x48) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0x68) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x68) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0x88) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0x88) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0xa8) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0xa8) != 0)) {
    kfree();
  }
  if ((*(ulong *)(param_2 + 0xd0) < 0xfffffffffffff001) && (*(ulong *)(param_2 + 0xd0) != 0)) {
    kfree();
  }
  if (*(long *)(param_2 + 0x158) != 0) {
    kfree();
  }
  piVar1 = (int *)(param_2 + 0x104);
  do {
    if (-1 < *piVar1) {
      gpio_free();
    }
    piVar1 = piVar1 + 1;
  } while ((int *)(param_2 + 0x130) != piVar1);
  *(undefined1 *)(param_2 + 0x130) = 0;
  return;
}


// ===== 00104140 __pfx_nv_bpmp_send_mrq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010415e) */

undefined8 __pfx_nv_bpmp_send_mrq(void)

{
  return 0x56;
}


// ===== 00104150 nv_bpmp_send_mrq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010415e) */

undefined8 nv_bpmp_send_mrq(void)

{
  return 0x56;
}


// ===== 00104170 __pfx_nv_gpio_get_pin_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001041a5) */
/* WARNING: Removing unreachable block (ram,0x001041ca) */

undefined8 __pfx_nv_gpio_get_pin_state(undefined8 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = gpio_to_desc(param_2);
  iVar1 = gpiod_get_raw_value(uVar2);
  if (-1 < iVar1) {
    *param_3 = iVar1;
    return 0;
  }
  nv_printf(4,"NVRM: %s: failed with err: %d\n","nv_gpio_get_pin_state",iVar1);
  return 0xffff;
}


// ===== 00104180 nv_gpio_get_pin_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001041a5) */
/* WARNING: Removing unreachable block (ram,0x001041ca) */

undefined8 nv_gpio_get_pin_state(undefined8 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = gpio_to_desc(param_2);
  iVar1 = gpiod_get_raw_value(uVar2);
  if (-1 < iVar1) {
    *param_3 = iVar1;
    return 0;
  }
  nv_printf(4,"NVRM: %s: failed with err: %d\n","nv_gpio_get_pin_state",iVar1);
  return 0xffff;
}


// ===== 001041d0 __pfx_nv_gpio_set_pin_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_gpio_set_pin_state(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  uVar1 = gpio_to_desc(param_2);
  gpiod_set_raw_value(uVar1,param_3);
  return;
}


// ===== 001041e0 nv_gpio_set_pin_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_gpio_set_pin_state(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  uVar1 = gpio_to_desc(param_2);
  gpiod_set_raw_value(uVar1,param_3);
  return;
}


// ===== 00104200 __pfx_nv_gpio_set_pin_direction =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104234) */
/* WARNING: Removing unreachable block (ram,0x0010426f) */

undefined8
__pfx_nv_gpio_set_pin_direction
          (undefined8 param_1,undefined4 param_2,int param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0x104219;
  if (param_3 == 0) {
    uVar2 = gpio_to_desc(param_2);
    iVar1 = gpiod_direction_output_raw(uVar2,0);
  }
  else {
    uVar2 = gpio_to_desc(param_2);
    iVar1 = gpiod_direction_input(uVar2);
  }
  if (iVar1 == 0) {
    return 0;
  }
  nv_printf(4,"NVRM: %s: failed with err: %d\n","nv_gpio_set_pin_direction",iVar1,param_5,param_6,
            uVar3);
  return 0xffff;
}


// ===== 00104210 nv_gpio_set_pin_direction =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104234) */
/* WARNING: Removing unreachable block (ram,0x0010426f) */

undefined8
nv_gpio_set_pin_direction
          (undefined8 param_1,undefined4 param_2,int param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0x104219;
  if (param_3 == 0) {
    uVar2 = gpio_to_desc(param_2);
    iVar1 = gpiod_direction_output_raw(uVar2,0);
  }
  else {
    uVar2 = gpio_to_desc(param_2);
    iVar1 = gpiod_direction_input(uVar2);
  }
  if (iVar1 == 0) {
    return 0;
  }
  nv_printf(4,"NVRM: %s: failed with err: %d\n","nv_gpio_set_pin_direction",iVar1,param_5,param_6,
            uVar3);
  return 0xffff;
}


// ===== 00104280 __pfx_nv_gpio_get_pin_direction =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010429b) */

undefined8 __pfx_nv_gpio_get_pin_direction(void)

{
  return 0;
}


// ===== 00104290 nv_gpio_get_pin_direction =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010429b) */

undefined8 nv_gpio_get_pin_direction(void)

{
  return 0;
}


// ===== 001042a0 __pfx_nv_gpio_get_pin_number =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001042f4) */

undefined8
__pfx_nv_gpio_get_pin_number
          (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  nv_printf(4,"NVRM: of_get_name_gpio failed for gpio - %s, rc - %d\n",
            *(undefined8 *)(osMapGpioFunc_0 + (ulong)param_2 * 8),
            (-(uint)(*(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2a8) == 0) & 0x24) -
            0x26,param_5,param_6,0x1042b9);
  return 0xffff;
}


// ===== 001042b0 nv_gpio_get_pin_number =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001042f4) */

undefined8
nv_gpio_get_pin_number
          (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  nv_printf(4,"NVRM: of_get_name_gpio failed for gpio - %s, rc - %d\n",
            *(undefined8 *)(osMapGpioFunc_0 + (ulong)param_2 * 8),
            (-(uint)(*(long *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x2a8) == 0) & 0x24) -
            0x26,param_5,param_6,0x1042b9);
  return 0xffff;
}


// ===== 00104300 __pfx_nv_gpio_get_pin_interrupt_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104364) */

bool __pfx_nv_gpio_get_pin_interrupt_status(undefined8 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  bool bVar3;
  int iStack_2c;
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_2c = 0;
  iVar1 = nv_get_current_irq_type();
  if (iVar1 == 3) {
    nv_get_current_irq_priv_data(param_1,&iStack_2c);
    if (iStack_2c == param_2) {
      uVar2 = gpio_to_desc(param_2);
      iVar1 = gpiod_get_raw_value(uVar2);
      bVar3 = iVar1 == param_3;
      goto LAB_0010434c;
    }
  }
  bVar3 = false;
LAB_0010434c:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00104310 nv_gpio_get_pin_interrupt_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104364) */

bool nv_gpio_get_pin_interrupt_status(undefined8 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  bool bVar3;
  int local_2c;
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_2c = 0;
  iVar1 = nv_get_current_irq_type();
  if (iVar1 == 3) {
    nv_get_current_irq_priv_data(param_1,&local_2c);
    if (local_2c == param_2) {
      uVar2 = gpio_to_desc(param_2);
      iVar1 = gpiod_get_raw_value(uVar2);
      bVar3 = iVar1 == param_3;
      goto LAB_0010434c;
    }
  }
  bVar3 = false;
LAB_0010434c:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001043a0 __pfx_nv_gpio_set_pin_interrupt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001043e6) */
/* WARNING: Removing unreachable block (ram,0x00104426) */

undefined4 __pfx_nv_gpio_set_pin_interrupt(long param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar4 = gpio_to_desc(param_2);
  uVar2 = gpiod_to_irq(uVar4);
  uVar5 = 0;
  if (param_3 != 0) {
    iVar3 = nv_request_soc_irq(uVar1,uVar2,3,0x2003,param_2,"hdmi-hotplug");
    if (-1 < iVar3) {
      disable_irq_nosync(uVar2);
      return 0;
    }
    nv_printf(4,"NVRM: IRQ registration failed for gpio - %d, rc - %d\n",param_2,iVar3);
    uVar5 = 0xffff;
  }
  return uVar5;
}


// ===== 001043b0 nv_gpio_set_pin_interrupt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001043e6) */
/* WARNING: Removing unreachable block (ram,0x00104426) */

undefined4 nv_gpio_set_pin_interrupt(long param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar4 = gpio_to_desc(param_2);
  uVar2 = gpiod_to_irq(uVar4);
  uVar5 = 0;
  if (param_3 != 0) {
    iVar3 = nv_request_soc_irq(uVar1,uVar2,3,0x2003,param_2,"hdmi-hotplug");
    if (-1 < iVar3) {
      disable_irq_nosync(uVar2);
      return 0;
    }
    nv_printf(4,"NVRM: IRQ registration failed for gpio - %d, rc - %d\n",param_2,iVar3);
    uVar5 = 0xffff;
  }
  return uVar5;
}


// ===== 00104450 __pfx_nv_get_tegra_brightness_level =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010446e) */

undefined8 __pfx_nv_get_tegra_brightness_level(void)

{
  return 0x56;
}


// ===== 00104460 nv_get_tegra_brightness_level =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010446e) */

undefined8 nv_get_tegra_brightness_level(void)

{
  return 0x56;
}


// ===== 00104480 __pfx_nv_set_tegra_brightness_level =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010449e) */

undefined8 __pfx_nv_set_tegra_brightness_level(void)

{
  return 0x56;
}


// ===== 00104490 nv_set_tegra_brightness_level =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010449e) */

undefined8 nv_set_tegra_brightness_level(void)

{
  return 0x56;
}


// ===== 001044b0 __pfx_nv_imp_get_uefi_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001044da) */

undefined8 __pfx_nv_imp_get_uefi_data(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 0;
  return 0x56;
}


// ===== 001044c0 nv_imp_get_uefi_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001044da) */

undefined8 nv_imp_get_uefi_data(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 0;
  return 0x56;
}


// ===== 001044e0 __pfx_nv_imp_get_import_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001044fe) */

undefined8 __pfx_nv_imp_get_import_data(void)

{
  return 0x56;
}


// ===== 001044f0 nv_imp_get_import_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001044fe) */

undefined8 nv_imp_get_import_data(void)

{
  return 0x56;
}


// ===== 00104510 __pfx_nv_imp_enable_disable_rfl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010452e) */

undefined8 __pfx_nv_imp_enable_disable_rfl(void)

{
  return 0x56;
}


// ===== 00104520 nv_imp_enable_disable_rfl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010452e) */

undefined8 nv_imp_enable_disable_rfl(void)

{
  return 0x56;
}


// ===== 00104540 __pfx_nv_imp_icc_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010455e) */

undefined8 __pfx_nv_imp_icc_get(void)

{
  return 0x56;
}


// ===== 00104550 nv_imp_icc_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010455e) */

undefined8 nv_imp_icc_get(void)

{
  return 0x56;
}


// ===== 00104570 __pfx_nv_imp_icc_put =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104589) */

void __pfx_nv_imp_icc_put(void)

{
  return;
}


// ===== 00104580 nv_imp_icc_put =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104589) */

void nv_imp_icc_put(void)

{
  return;
}


// ===== 00104590 __pfx_nv_imp_icc_set_bw =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001045ae) */

undefined8 __pfx_nv_imp_icc_set_bw(void)

{
  return 0x56;
}


// ===== 001045a0 nv_imp_icc_set_bw =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001045ae) */

undefined8 nv_imp_icc_set_bw(void)

{
  return 0x56;
}


// ===== 001045c0 __pfx_nv_soc_pm_unpowergate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001045de) */

undefined8 __pfx_nv_soc_pm_unpowergate(void)

{
  return 0x56;
}


// ===== 001045d0 nv_soc_pm_unpowergate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001045de) */

undefined8 nv_soc_pm_unpowergate(void)

{
  return 0x56;
}


// ===== 001045f0 __pfx_nv_soc_pm_powergate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010460e) */

undefined8 __pfx_nv_soc_pm_powergate(void)

{
  return 0x56;
}


// ===== 00104600 nv_soc_pm_powergate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010460e) */

undefined8 nv_soc_pm_powergate(void)

{
  return 0x56;
}


// ===== 00104620 __pfx_nv_tegra_get_rm_interface_type =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010463e) */

undefined8 __pfx_nv_tegra_get_rm_interface_type(void)

{
  return 0x56;
}


// ===== 00104630 nv_tegra_get_rm_interface_type =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010463e) */

undefined8 nv_tegra_get_rm_interface_type(void)

{
  return 0x56;
}


// ===== 00104650 __pfx_nv_tegra_dce_register_ipc_client =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010466e) */

undefined8 __pfx_nv_tegra_dce_register_ipc_client(void)

{
  return 0x56;
}


// ===== 00104660 nv_tegra_dce_register_ipc_client =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010466e) */

undefined8 nv_tegra_dce_register_ipc_client(void)

{
  return 0x56;
}


// ===== 00104680 __pfx_nv_tegra_dce_client_ipc_send_recv =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010469e) */

undefined8 __pfx_nv_tegra_dce_client_ipc_send_recv(void)

{
  return 0x56;
}


// ===== 00104690 nv_tegra_dce_client_ipc_send_recv =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010469e) */

undefined8 nv_tegra_dce_client_ipc_send_recv(void)

{
  return 0x56;
}


// ===== 001046b0 __pfx_nv_tegra_dce_unregister_ipc_client =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001046ce) */

undefined8 __pfx_nv_tegra_dce_unregister_ipc_client(void)

{
  return 0x56;
}


// ===== 001046c0 nv_tegra_dce_unregister_ipc_client =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001046ce) */

undefined8 nv_tegra_dce_unregister_ipc_client(void)

{
  return 0x56;
}


// ===== 00104700 __pfx_nv_timer_callback_typed_data =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_nv_timer_callback_typed_data(long param_1)

{
  (**(code **)(param_1 + 0x28))();
  return;
}


// ===== 00104710 nv_timer_callback_typed_data =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nv_timer_callback_typed_data(long param_1)

{
  (**(code **)(param_1 + 0x28))();
  return;
}


// ===== 00104720 __pfx_nv_pmops_thaw =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010473b) */

undefined8 __pfx_nv_pmops_thaw(void)

{
  return 0;
}


// ===== 00104730 nv_pmops_thaw =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010473b) */

undefined8 nv_pmops_thaw(void)

{
  return 0;
}


// ===== 00104740 __pfx_nv_match_dev_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010476a) */
/* WARNING: Removing unreachable block (ram,0x0010478d) */

bool __pfx_nv_match_dev_state(long param_1,long param_2)

{
  long lVar1;
  
  if ((((param_2 != 0) && (*(undefined1 **)(param_2 + 8) == nvidia_fops)) &&
      (*(long *)(param_2 + 0x18) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x80), lVar1 != 0)) {
    return lVar1 == param_1;
  }
  return false;
}


// ===== 00104750 nv_match_dev_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010476a) */
/* WARNING: Removing unreachable block (ram,0x0010478d) */

bool nv_match_dev_state(long param_1,long param_2)

{
  long lVar1;
  
  if ((((param_2 != 0) && (*(undefined1 **)(param_2 + 8) == nvidia_fops)) &&
      (*(long *)(param_2 + 0x18) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x80), lVar1 != 0)) {
    return lVar1 == param_1;
  }
  return false;
}


// ===== 001047a0 __pfx_nvidia_isr_bh_unlocked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvidia_isr_bh_unlocked(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 8);
  iVar3 = os_acquire_mutex(*(undefined8 *)(lVar1 + 2000));
  if (iVar3 != 0) {
    nv_printf(4,"NVRM: %s: Unable to take bottom_half mutex!\n","nvidia_isr_bh_unlocked");
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if ((*(byte *)(param_1 + 0x11) & 0x80) == 0) {
    rm_isr_bh_unlocked(*(undefined8 *)(lVar1 + 0x4c8),param_1);
    os_release_mutex(*(undefined8 *)(lVar1 + 2000));
    return;
  }
  nv_printf(0,"NVRM: GPU is lost, skipping unlocked ISR bottom half\n");
  os_release_mutex(*(undefined8 *)(lVar1 + 2000));
  return;
}


// ===== 001047b0 nvidia_isr_bh_unlocked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvidia_isr_bh_unlocked(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 8);
  iVar3 = os_acquire_mutex(*(undefined8 *)(lVar1 + 2000));
  if (iVar3 != 0) {
    nv_printf(4,"NVRM: %s: Unable to take bottom_half mutex!\n","nvidia_isr_bh_unlocked");
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if ((*(byte *)(param_1 + 0x11) & 0x80) == 0) {
    rm_isr_bh_unlocked(*(undefined8 *)(lVar1 + 0x4c8),param_1);
    os_release_mutex(*(undefined8 *)(lVar1 + 2000));
    return;
  }
  nv_printf(0,"NVRM: GPU is lost, skipping unlocked ISR bottom half\n");
  os_release_mutex(*(undefined8 *)(lVar1 + 2000));
  return;
}


// ===== 00104840 __pfx_find_uuid_candidate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010490a) */

long __pfx_find_uuid_candidate(long *param_1)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  
  down(nv_linux_devices_lock);
  lVar3 = nv_linux_devices;
  if (nv_linux_devices == 0) {
LAB_001048ee:
    up(nv_linux_devices_lock);
    return lVar3;
  }
  bVar2 = false;
  bVar1 = false;
  do {
    down(lVar3 + 0x730);
    if (*(char *)(lVar3 + 0x2c) == '\0') {
      if (bVar1) goto LAB_001048ee;
      bVar2 = true;
    }
    else if ((*(long *)(lVar3 + 0x2d) == *param_1) && (*(long *)(lVar3 + 0x35) == param_1[1]))
    goto LAB_001048ee;
    up(lVar3 + 0x730);
    lVar3 = *(long *)(lVar3 + 0x758);
    if ((lVar3 == 0) &&
       (((!bVar2 || (bVar1)) || (lVar3 = nv_linux_devices, bVar1 = bVar2, nv_linux_devices == 0))))
    goto LAB_001048ee;
  } while( true );
}


// ===== 00104850 find_uuid_candidate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010490a) */

long find_uuid_candidate(long *param_1)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  
  down(nv_linux_devices_lock);
  lVar3 = nv_linux_devices;
  if (nv_linux_devices == 0) {
LAB_001048ee:
    up(nv_linux_devices_lock);
    return lVar3;
  }
  bVar2 = false;
  bVar1 = false;
  do {
    down(lVar3 + 0x730);
    if (*(char *)(lVar3 + 0x2c) == '\0') {
      if (bVar1) goto LAB_001048ee;
      bVar2 = true;
    }
    else if ((*(long *)(lVar3 + 0x2d) == *param_1) && (*(long *)(lVar3 + 0x35) == param_1[1]))
    goto LAB_001048ee;
    up(lVar3 + 0x730);
    lVar3 = *(long *)(lVar3 + 0x758);
    if ((lVar3 == 0) &&
       (((!bVar2 || (bVar1)) || (lVar3 = nv_linux_devices, bVar1 = bVar2, nv_linux_devices == 0))))
    goto LAB_001048ee;
  } while( true );
}


// ===== 00104930 __pfx_nvidia_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104add) */

undefined1 __pfx_nvidia_isr(int param_1,long param_2)

{
  long *plVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  long lVar13;
  long in_GS_OFFSET;
  undefined1 uVar14;
  int iStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  long lStack_30;
  
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_40 = 0;
  iStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  rm_gpu_handle_mmu_faults(*(undefined8 *)(param_2 + 0x4b8),param_2,&iStack_3c);
  iVar4 = iStack_3c;
  lVar10 = param_2 + 0x2d;
  if (*(char *)(param_2 + 0x2c) == '\0') {
    lVar10 = 0;
  }
  iVar7 = nv_uvm_event_interrupt(lVar10);
  cVar5 = rm_isr(*(undefined8 *)(param_2 + 0x4b8),param_2,&iStack_40);
  if (((*(byte *)(param_2 + 0x10) & 0x60) != 0) &&
     (piVar3 = *(int **)(param_2 + 0x5198), piVar3 != (int *)0x0)) {
    uVar2 = *(ushort *)(param_2 + 0x51a0);
    if (uVar2 == 0) {
      uVar8 = 0;
    }
    else {
      uVar6 = 0;
      piVar11 = piVar3;
      do {
        if (*piVar11 == param_1) {
          lVar10 = (ulong)uVar6 * 0x20;
          *(long *)(piVar3 + (ulong)uVar6 * 8 + 4) = *(long *)(piVar3 + (ulong)uVar6 * 8 + 4) + 1;
          if (cVar5 != '\0') goto LAB_00104a4b;
          goto LAB_00104b3c;
        }
        uVar6 = uVar6 + 1;
        piVar11 = piVar11 + 8;
      } while (uVar6 != uVar2);
      uVar8 = (uint)uVar2;
    }
    if (uVar8 < *(uint *)(param_2 + 0x7dc)) {
      lVar10 = (ulong)uVar2 * 0x20;
      piVar3[(ulong)uVar2 * 8] = param_1;
      *(short *)(param_2 + 0x51a0) = *(short *)(param_2 + 0x51a0) + 1;
      plVar1 = (long *)(*(long *)(param_2 + 0x5198) + 0x10 + lVar10);
      *plVar1 = *plVar1 + 1;
      if (cVar5 == '\0') {
LAB_00104b3c:
        os_get_system_time(&uStack_38,&uStack_34);
        lVar13 = 1;
        lVar9 = (ulong)uStack_38 * 1000000 + (ulong)uStack_34;
        lVar12 = *(long *)(param_2 + 0x5198) + lVar10;
        if ((ulong)(lVar9 - *(long *)(lVar12 + 0x18)) < 0x186a1) {
          lVar13 = *(long *)(lVar12 + 8) + 1;
        }
        *(long *)(lVar12 + 8) = lVar13;
        cVar5 = '\x01';
        *(long *)(*(long *)(param_2 + 0x5198) + 0x18 + lVar10) = lVar9;
      }
LAB_00104a4b:
      lVar9 = *(long *)(param_2 + 0x5198) + lVar10;
      if (99999 < *(ulong *)(lVar9 + 0x10)) {
        if (0x1863c < *(ulong *)(lVar9 + 8)) {
          nv_printf(4,"NVRM: Going over RM unhandled interrupt threshold for irq %d\n",param_1);
          lVar9 = *(long *)(param_2 + 0x5198) + lVar10;
        }
        *(undefined8 *)(lVar9 + 0x10) = 0;
        *(undefined8 *)(*(long *)(param_2 + 0x5198) + 8 + lVar10) = 0;
        *(undefined8 *)(*(long *)(param_2 + 0x5198) + 0x18 + lVar10) = 0;
      }
    }
    else {
      nv_printf(4,"NVRM: IRQ number out of valid range\n");
    }
  }
  uVar14 = 2;
  if (iStack_40 == 0) {
    if (iVar4 != 0) {
      nv_kthread_q_schedule_q_item(param_2 + 0x768,param_2 + 0x7b0);
    }
    uVar14 = (iVar4 != 0 || iVar7 == 0) || cVar5 != '\0';
  }
  if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00104940 nvidia_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104add) */

undefined1 nvidia_isr(int param_1,long param_2)

{
  long *plVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  long lVar13;
  long in_GS_OFFSET;
  undefined1 uVar14;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  long local_30;
  
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  rm_gpu_handle_mmu_faults(*(undefined8 *)(param_2 + 0x4b8),param_2,&local_3c);
  iVar4 = local_3c;
  lVar10 = param_2 + 0x2d;
  if (*(char *)(param_2 + 0x2c) == '\0') {
    lVar10 = 0;
  }
  iVar7 = nv_uvm_event_interrupt(lVar10);
  cVar5 = rm_isr(*(undefined8 *)(param_2 + 0x4b8),param_2,&local_40);
  if (((*(byte *)(param_2 + 0x10) & 0x60) != 0) &&
     (piVar3 = *(int **)(param_2 + 0x5198), piVar3 != (int *)0x0)) {
    uVar2 = *(ushort *)(param_2 + 0x51a0);
    if (uVar2 == 0) {
      uVar8 = 0;
    }
    else {
      uVar6 = 0;
      piVar11 = piVar3;
      do {
        if (*piVar11 == param_1) {
          lVar10 = (ulong)uVar6 * 0x20;
          *(long *)(piVar3 + (ulong)uVar6 * 8 + 4) = *(long *)(piVar3 + (ulong)uVar6 * 8 + 4) + 1;
          if (cVar5 != '\0') goto LAB_00104a4b;
          goto LAB_00104b3c;
        }
        uVar6 = uVar6 + 1;
        piVar11 = piVar11 + 8;
      } while (uVar6 != uVar2);
      uVar8 = (uint)uVar2;
    }
    if (uVar8 < *(uint *)(param_2 + 0x7dc)) {
      lVar10 = (ulong)uVar2 * 0x20;
      piVar3[(ulong)uVar2 * 8] = param_1;
      *(short *)(param_2 + 0x51a0) = *(short *)(param_2 + 0x51a0) + 1;
      plVar1 = (long *)(*(long *)(param_2 + 0x5198) + 0x10 + lVar10);
      *plVar1 = *plVar1 + 1;
      if (cVar5 == '\0') {
LAB_00104b3c:
        os_get_system_time(&local_38,&local_34);
        lVar13 = 1;
        lVar9 = (ulong)local_38 * 1000000 + (ulong)local_34;
        lVar12 = *(long *)(param_2 + 0x5198) + lVar10;
        if ((ulong)(lVar9 - *(long *)(lVar12 + 0x18)) < 0x186a1) {
          lVar13 = *(long *)(lVar12 + 8) + 1;
        }
        *(long *)(lVar12 + 8) = lVar13;
        cVar5 = '\x01';
        *(long *)(*(long *)(param_2 + 0x5198) + 0x18 + lVar10) = lVar9;
      }
LAB_00104a4b:
      lVar9 = *(long *)(param_2 + 0x5198) + lVar10;
      if (99999 < *(ulong *)(lVar9 + 0x10)) {
        if (0x1863c < *(ulong *)(lVar9 + 8)) {
          nv_printf(4,"NVRM: Going over RM unhandled interrupt threshold for irq %d\n",param_1);
          lVar9 = *(long *)(param_2 + 0x5198) + lVar10;
        }
        *(undefined8 *)(lVar9 + 0x10) = 0;
        *(undefined8 *)(*(long *)(param_2 + 0x5198) + 8 + lVar10) = 0;
        *(undefined8 *)(*(long *)(param_2 + 0x5198) + 0x18 + lVar10) = 0;
      }
    }
    else {
      nv_printf(4,"NVRM: IRQ number out of valid range\n");
    }
  }
  uVar14 = 2;
  if (local_40 == 0) {
    if (iVar4 != 0) {
      nv_kthread_q_schedule_q_item(param_2 + 0x768,param_2 + 0x7b0);
    }
    uVar14 = (iVar4 != 0 || iVar7 == 0) || cVar5 != '\0';
  }
  if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00104c10 __pfx_snapshot_timer_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_snapshot_timer_callback(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(0x52fce8);
  if (nv_ctl_device._20880_8_ != 0) {
    (*(code *)nv_ctl_device._20880_8_)(nv_ctl_device._776_8_);
    mod_timer(param_1,_jiffies + 10);
  }
  _raw_spin_unlock_irqrestore(0x52fce8,uVar1);
  return;
}


// ===== 00104c20 snapshot_timer_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void snapshot_timer_callback(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(0x52fce8);
  if (nv_ctl_device._20880_8_ != 0) {
    (*(code *)nv_ctl_device._20880_8_)(nv_ctl_device._776_8_);
    mod_timer(param_1,_jiffies + 10);
  }
  _raw_spin_unlock_irqrestore(0x52fce8,uVar1);
  return;
}


// ===== 00104c80 __pfx_nv_add_open_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_add_open_file(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  *(long *)(param_2 + 0x80) = param_1;
  down(param_1 + 0x868);
  lVar3 = *(long *)(param_1 + 0x880);
  lVar1 = param_1 + 0x880;
  lVar2 = param_2 + 0x200;
  if (((lVar1 == *(long *)(lVar3 + 8)) && (lVar1 != lVar2)) && (lVar2 != lVar3)) {
    *(long *)(lVar3 + 8) = lVar2;
    *(long *)(param_2 + 0x200) = lVar3;
    *(long *)(param_2 + 0x208) = lVar1;
    *(long *)(param_1 + 0x880) = lVar2;
  }
  else {
    __list_add_valid_or_report();
  }
  up(param_1 + 0x868);
  return;
}


// ===== 00104c90 nv_add_open_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_add_open_file(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  *(long *)(param_2 + 0x80) = param_1;
  down(param_1 + 0x868);
  lVar3 = *(long *)(param_1 + 0x880);
  lVar1 = param_1 + 0x880;
  lVar2 = param_2 + 0x200;
  if (((lVar1 == *(long *)(lVar3 + 8)) && (lVar1 != lVar2)) && (lVar2 != lVar3)) {
    *(long *)(lVar3 + 8) = lVar2;
    *(long *)(param_2 + 0x200) = lVar3;
    *(long *)(param_2 + 0x208) = lVar1;
    *(long *)(param_1 + 0x880) = lVar2;
  }
  else {
    __list_add_valid_or_report();
  }
  up(param_1 + 0x868);
  return;
}


// ===== 00104d20 __pfx_nvidia_poll =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x00104e53) */
/* WARNING: Removing unreachable block (ram,0x00104db9) */
/* WARNING: Removing unreachable block (ram,0x00104e15) */

undefined4 __pfx_nvidia_poll(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(param_1 + 0x18);
  if ((((*(uint *)(*(long *)(param_1 + 0x20) + 0x4c) & 0xfffff) == 0xff) ||
      (cVar3 = completion_done(lVar1 + 0x1d0), cVar3 != '\0')) &&
     (lVar2 = *(long *)(lVar1 + 0x80), lVar2 != 0)) {
    if ((*(byte *)(lVar2 + 0x11) & 0x80) == 0) {
      if ((((*(byte *)(param_1 + 0x29) & 8) == 0) && (param_2 != (undefined8 *)0x0)) &&
         ((code *)*param_2 != (code *)0x0)) {
        (*(code *)*param_2)(param_1,lVar1 + 0xa0,param_2);
        LOCK();
        UNLOCK();
      }
      uVar5 = _raw_spin_lock_irqsave();
      if ((*(long *)(lVar1 + 0x88) != 0) || (uVar4 = 0, *(char *)(lVar1 + 0x98) != '\0')) {
        *(undefined1 *)(lVar1 + 0x98) = 0;
        uVar4 = 3;
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0x9c,uVar5);
      return uVar4;
    }
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping nvidia_poll\n",
              *(undefined4 *)(lVar2 + 0x14),*(undefined1 *)(lVar2 + 0x18),
              *(undefined1 *)(lVar2 + 0x19),*(undefined1 *)(lVar2 + 0x1a));
    return 0x10;
  }
  return 8;
}


// ===== 00104d30 nvidia_poll =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x00104e53) */
/* WARNING: Removing unreachable block (ram,0x00104db9) */
/* WARNING: Removing unreachable block (ram,0x00104e15) */

undefined4 nvidia_poll(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(param_1 + 0x18);
  if ((((*(uint *)(*(long *)(param_1 + 0x20) + 0x4c) & 0xfffff) == 0xff) ||
      (cVar3 = completion_done(lVar1 + 0x1d0), cVar3 != '\0')) &&
     (lVar2 = *(long *)(lVar1 + 0x80), lVar2 != 0)) {
    if ((*(byte *)(lVar2 + 0x11) & 0x80) == 0) {
      if ((((*(byte *)(param_1 + 0x29) & 8) == 0) && (param_2 != (undefined8 *)0x0)) &&
         ((code *)*param_2 != (code *)0x0)) {
        (*(code *)*param_2)(param_1,lVar1 + 0xa0,param_2);
        LOCK();
        UNLOCK();
      }
      uVar5 = _raw_spin_lock_irqsave();
      if ((*(long *)(lVar1 + 0x88) != 0) || (uVar4 = 0, *(char *)(lVar1 + 0x98) != '\0')) {
        *(undefined1 *)(lVar1 + 0x98) = 0;
        uVar4 = 3;
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0x9c,uVar5);
      return uVar4;
    }
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping nvidia_poll\n",
              *(undefined4 *)(lVar2 + 0x14),*(undefined1 *)(lVar2 + 0x18),
              *(undefined1 *)(lVar2 + 0x19),*(undefined1 *)(lVar2 + 0x1a));
    return 0x10;
  }
  return 8;
}


// ===== 00104e60 __pfx_nv_kmem_cache_free_stack =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104e83) */
/* WARNING: Removing unreachable block (ram,0x00104e88) */

void __pfx_nv_kmem_cache_free_stack(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    return;
  }
  kmem_cache_free(nvidia_stack_t_cache,param_1);
  return;
}


// ===== 00104e70 nv_kmem_cache_free_stack =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104e83) */
/* WARNING: Removing unreachable block (ram,0x00104e88) */

void nv_kmem_cache_free_stack(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    return;
  }
  kmem_cache_free(nvidia_stack_t_cache,param_1);
  return;
}


// ===== 00104ea0 __pfx_nvidia_rc_timer_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104ede) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nvidia_rc_timer_callback(long param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + -0x6ef) & 0x80) != 0) {
    nv_printf(0,"NVRM: GPU is lost, skipping device timer callbacks\n");
    return;
  }
  iVar1 = rm_run_rc_callback(*(undefined8 *)(param_1 + -0x250),param_1 + -0x700);
  if (iVar1 != 0) {
    return;
  }
  mod_timer(param_1,_jiffies + 1000);
  return;
}


// ===== 00104eb0 nvidia_rc_timer_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104ede) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvidia_rc_timer_callback(long param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + -0x6ef) & 0x80) != 0) {
    nv_printf(0,"NVRM: GPU is lost, skipping device timer callbacks\n");
    return;
  }
  iVar1 = rm_run_rc_callback(*(undefined8 *)(param_1 + -0x250),param_1 + -0x700);
  if (iVar1 != 0) {
    return;
  }
  mod_timer(param_1,_jiffies + 1000);
  return;
}


// ===== 00104f10 __pfx_nv_free_file_private =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104fa7) */

void __pfx_nv_free_file_private(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_1 == 0) {
    return;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x88);
  if (puVar2 == (undefined8 *)0x0) goto LAB_00104f91;
  do {
    *(undefined8 *)(param_1 + 0x88) = *puVar2;
    kfree();
    puVar2 = *(undefined8 **)(param_1 + 0x88);
  } while (puVar2 != (undefined8 *)0x0);
  lVar1 = *(long *)(param_1 + 0x1a8);
  while (lVar1 != 0) {
    *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)(lVar1 + 0x60);
    if (*(long *)(lVar1 + 0x10) != 0) {
      os_free_mem();
    }
    if (*(long *)(lVar1 + 0x20) != 0) {
      os_free_mem();
    }
    os_free_mem(lVar1);
LAB_00104f91:
    lVar1 = *(long *)(param_1 + 0x1a8);
  }
  kfree(param_1);
  return;
}


// ===== 00104f20 nv_free_file_private =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00104fa7) */

void nv_free_file_private(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_1 == 0) {
    return;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x88);
  if (puVar2 == (undefined8 *)0x0) goto LAB_00104f91;
  do {
    *(undefined8 *)(param_1 + 0x88) = *puVar2;
    kfree();
    puVar2 = *(undefined8 **)(param_1 + 0x88);
  } while (puVar2 != (undefined8 *)0x0);
  lVar1 = *(long *)(param_1 + 0x1a8);
  while (lVar1 != 0) {
    *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)(lVar1 + 0x60);
    if (*(long *)(lVar1 + 0x10) != 0) {
      os_free_mem();
    }
    if (*(long *)(lVar1 + 0x20) != 0) {
      os_free_mem();
    }
    os_free_mem(lVar1);
LAB_00104f91:
    lVar1 = *(long *)(param_1 + 0x1a8);
  }
  kfree(param_1);
  return;
}


// ===== 00104fb0 __pfx_nvos_create_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010506f) */
/* WARNING: Removing unreachable block (ram,0x001050c6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx_nvos_create_alloc(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  if (param_2 == 0) {
    lVar2 = __kmalloc_cache_noprof(___init_swait_queue_head,0x2dc0,0x70);
    if (lVar2 == 0) goto LAB_001050e0;
    *(undefined4 *)(lVar2 + 0x20) = 0;
  }
  else {
    if (param_2 >> 0x3c != 0) {
      nv_printf(4,"NVRM: Invalid page table allocation - Number of pages exceeds max value.\n");
      return 0;
    }
    lVar2 = __kmalloc_cache_noprof(___init_swait_queue_head,0x2dc0,0x70);
    if (lVar2 == 0) {
LAB_001050e0:
      nv_printf(4,"NVRM: failed to allocate alloc info\n");
      return 0;
    }
    *(int *)(lVar2 + 0x20) = (int)param_2;
    if (param_2 >> 0x20 != 0) {
      nv_printf(4,"NVRM: Invalid page table allocation - requested size overflows.\n");
      kfree(lVar2);
      return 0;
    }
  }
  lVar3 = __kvmalloc_node_noprof(param_2 << 4,0,1,0x2dc0,0xffffffff);
  *(long *)(lVar2 + 0x30) = lVar3;
  if (lVar3 == 0) {
    nv_printf(4,"NVRM: failed to allocate page table\n");
    kfree(lVar2);
    return 0;
  }
  *(undefined8 *)(lVar2 + 0x10) = 0;
  uVar1 = os_get_current_process();
  *(undefined8 *)(lVar2 + 8) = param_1;
  *(undefined4 *)(lVar2 + 0x38) = uVar1;
  return lVar2;
}


// ===== 00104fc0 nvos_create_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010506f) */
/* WARNING: Removing unreachable block (ram,0x001050c6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long nvos_create_alloc(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  if (param_2 == 0) {
    lVar2 = __kmalloc_cache_noprof(___init_swait_queue_head,0x2dc0,0x70);
    if (lVar2 == 0) goto LAB_001050e0;
    *(undefined4 *)(lVar2 + 0x20) = 0;
  }
  else {
    if (param_2 >> 0x3c != 0) {
      nv_printf(4,"NVRM: Invalid page table allocation - Number of pages exceeds max value.\n");
      return 0;
    }
    lVar2 = __kmalloc_cache_noprof(___init_swait_queue_head,0x2dc0,0x70);
    if (lVar2 == 0) {
LAB_001050e0:
      nv_printf(4,"NVRM: failed to allocate alloc info\n");
      return 0;
    }
    *(int *)(lVar2 + 0x20) = (int)param_2;
    if (param_2 >> 0x20 != 0) {
      nv_printf(4,"NVRM: Invalid page table allocation - requested size overflows.\n");
      kfree(lVar2);
      return 0;
    }
  }
  lVar3 = __kvmalloc_node_noprof(param_2 << 4,0,1,0x2dc0,0xffffffff);
  *(long *)(lVar2 + 0x30) = lVar3;
  if (lVar3 == 0) {
    nv_printf(4,"NVRM: failed to allocate page table\n");
    kfree(lVar2);
    return 0;
  }
  *(undefined8 *)(lVar2 + 0x10) = 0;
  uVar1 = os_get_current_process();
  *(undefined8 *)(lVar2 + 8) = param_1;
  *(undefined4 *)(lVar2 + 0x38) = uVar1;
  return lVar2;
}


// ===== 00105120 __pfx_nv_pmops_poweroff =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010513b) */

undefined8 __pfx_nv_pmops_poweroff(void)

{
  return 0;
}


// ===== 00105130 nv_pmops_poweroff =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010513b) */

undefined8 nv_pmops_poweroff(void)

{
  return 0;
}


// ===== 00105140 __pfx_nvidia_isr_kthread_bh =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105174) */
/* WARNING: Removing unreachable block (ram,0x0010518c) */

undefined8 __pfx_nvidia_isr_kthread_bh(undefined8 param_1,long param_2)

{
  if ((*(byte *)(param_2 + 0x11) & 0x80) == 0) {
    rm_isr_bh(*(undefined8 *)(*(long *)(param_2 + 8) + 0x4c0));
    return 1;
  }
  nv_printf(0,"NVRM: GPU is lost, skipping ISR bottom half\n");
  return 1;
}


// ===== 00105150 nvidia_isr_kthread_bh =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105174) */
/* WARNING: Removing unreachable block (ram,0x0010518c) */

undefined8 nvidia_isr_kthread_bh(undefined8 param_1,long param_2)

{
  if ((*(byte *)(param_2 + 0x11) & 0x80) == 0) {
    rm_isr_bh(*(undefined8 *)(*(long *)(param_2 + 8) + 0x4c0));
    return 1;
  }
  nv_printf(0,"NVRM: GPU is lost, skipping ISR bottom half\n");
  return 1;
}


// ===== 001051a0 __pfx_nv_restore_user_channels =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001052fc) */
/* WARNING: Removing unreachable block (ram,0x00105277) */
/* WARNING: Removing unreachable block (ram,0x0010525c) */
/* WARNING: Removing unreachable block (ram,0x001052dd) */

undefined4 __pfx_nv_restore_user_channels(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  
  lVar2 = *(long *)(param_1 + 8);
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 == '\0') {
    lVar1 = lVar2 + 0x730;
    down(lVar1);
    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
      up(lVar1);
      return 0;
    }
    iVar5 = rm_restart_user_channels(0,param_1);
    if (iVar5 != 0) {
LAB_001051fe:
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    down(lVar2 + 0x868);
    nv_set_safe_to_mmap_locked(param_1,1);
    up(lVar2 + 0x868);
    rm_unref_dynamic_power(0,param_1,2);
    up(lVar1);
  }
  else {
    puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar6 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar6 = 0x2ff0;
    lVar1 = lVar2 + 0x730;
    *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
    down(lVar1);
    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
      up(lVar1);
    }
    else {
      iVar5 = rm_restart_user_channels(puVar6,param_1);
      if (iVar5 != 0) goto LAB_001051fe;
      down(lVar2 + 0x868);
      nv_set_safe_to_mmap_locked(param_1,1);
      up(lVar2 + 0x868);
      rm_unref_dynamic_power(puVar6,param_1,2);
      up(lVar1);
    }
    cVar4 = rm_is_altstack_in_use();
    if (cVar4 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar6);
      return 0;
    }
  }
  return 0;
}


// ===== 001051b0 nv_restore_user_channels =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001052fc) */
/* WARNING: Removing unreachable block (ram,0x00105277) */
/* WARNING: Removing unreachable block (ram,0x0010525c) */
/* WARNING: Removing unreachable block (ram,0x001052dd) */

undefined4 nv_restore_user_channels(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  
  lVar2 = *(long *)(param_1 + 8);
  cVar4 = rm_is_altstack_in_use();
  if (cVar4 == '\0') {
    lVar1 = lVar2 + 0x730;
    down(lVar1);
    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
      up(lVar1);
      return 0;
    }
    iVar5 = rm_restart_user_channels(0,param_1);
    if (iVar5 != 0) {
LAB_001051fe:
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    down(lVar2 + 0x868);
    nv_set_safe_to_mmap_locked(param_1,1);
    up(lVar2 + 0x868);
    rm_unref_dynamic_power(0,param_1,2);
    up(lVar1);
  }
  else {
    puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar6 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar6 = 0x2ff0;
    lVar1 = lVar2 + 0x730;
    *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
    down(lVar1);
    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
      up(lVar1);
    }
    else {
      iVar5 = rm_restart_user_channels(puVar6,param_1);
      if (iVar5 != 0) goto LAB_001051fe;
      down(lVar2 + 0x868);
      nv_set_safe_to_mmap_locked(param_1,1);
      up(lVar2 + 0x868);
      rm_unref_dynamic_power(puVar6,param_1,2);
      up(lVar1);
    }
    cVar4 = rm_is_altstack_in_use();
    if (cVar4 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar6);
      return 0;
    }
  }
  return 0;
}


// ===== 001053a0 __pfx_nv_power_management =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105512) */
/* WARNING: Removing unreachable block (ram,0x00105473) */
/* WARNING: Removing unreachable block (ram,0x001054df) */

int __pfx_nv_power_management(long param_1,uint param_2)

{
  byte bVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  
  lVar2 = *(long *)(param_1 + 8);
  puVar5 = (undefined4 *)0x0;
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    bVar1 = *(byte *)(param_1 + 0x11);
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    bVar1 = *(byte *)(param_1 + 0x11);
  }
  if ((bVar1 & 0x80) == 0) {
    if (param_2 < 2) {
      nv_kthread_q_flush(lVar2 + 0x51d8);
      iVar4 = rm_power_management(puVar5,param_1,param_2);
      nv_kthread_q_stop(lVar2 + 0x768);
      nv_disable_pat_support();
    }
    else if (param_2 == 2) {
      nv_enable_pat_support();
      nv_kthread_q_item_init(lVar2 + 0x7b0,nvidia_isr_bh_unlocked,param_1);
      iVar4 = nv_kthread_q_init(lVar2 + 0x768,nv_device_name);
      if (iVar4 == 0) {
        iVar4 = rm_power_management(puVar5,param_1,2);
      }
    }
    else {
      iVar4 = 0x1f;
    }
  }
  else {
    iVar4 = 0xf;
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping PM event\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  if ((puVar5 != (undefined4 *)0x0) && (cVar3 = rm_is_altstack_in_use(), cVar3 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar5);
    return iVar4;
  }
  return iVar4;
}


// ===== 001053b0 nv_power_management =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105512) */
/* WARNING: Removing unreachable block (ram,0x00105473) */
/* WARNING: Removing unreachable block (ram,0x001054df) */

int nv_power_management(long param_1,uint param_2)

{
  byte bVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  
  lVar2 = *(long *)(param_1 + 8);
  puVar5 = (undefined4 *)0x0;
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    bVar1 = *(byte *)(param_1 + 0x11);
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    bVar1 = *(byte *)(param_1 + 0x11);
  }
  if ((bVar1 & 0x80) == 0) {
    if (param_2 < 2) {
      nv_kthread_q_flush(lVar2 + 0x51d8);
      iVar4 = rm_power_management(puVar5,param_1,param_2);
      nv_kthread_q_stop(lVar2 + 0x768);
      nv_disable_pat_support();
    }
    else if (param_2 == 2) {
      nv_enable_pat_support();
      nv_kthread_q_item_init(lVar2 + 0x7b0,nvidia_isr_bh_unlocked,param_1);
      iVar4 = nv_kthread_q_init(lVar2 + 0x768,nv_device_name);
      if (iVar4 == 0) {
        iVar4 = rm_power_management(puVar5,param_1,2);
      }
    }
    else {
      iVar4 = 0x1f;
    }
  }
  else {
    iVar4 = 0xf;
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping PM event\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  if ((puVar5 != (undefined4 *)0x0) && (cVar3 = rm_is_altstack_in_use(), cVar3 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar5);
    return iVar4;
  }
  return iVar4;
}


// ===== 00105530 __pfx_nvidia_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010559c) */

int __pfx_nvidia_resume(long param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(undefined **)(param_1 + 0x60) == &pci_bus_type) && (*(char *)(lVar1 + 0x2b2) != '\0')) {
    lVar2 = *(long *)(param_1 + -0xc0);
    do {
      lVar4 = lVar2;
      lVar2 = *(long *)(lVar4 + 0x10);
    } while (lVar2 != 0);
    lVar2 = *(long *)(*(long *)(lVar4 + 0x110) + 0x40);
    nv_printf(0,"NVRM: restore GPU pm_domain after suspend\n");
    *(undefined8 *)(param_1 + 0x230) = *(undefined8 *)(lVar2 + 0x230);
    dev_pm_genpd_resume(param_1);
    pm_runtime_allow(param_1);
  }
  down(lVar1 + 0x730);
  if ((*(byte *)(lVar1 + 0x11) & 1) != 0) {
    if (*(int *)(lVar1 + 0x3a8) == 0) {
      iVar3 = nv_power_management(lVar1,param_2);
      if (iVar3 == 0) {
        nvidia_modeset_resume(*(undefined4 *)(lVar1 + 0x24));
        *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) & 0xfffffeff;
      }
      goto LAB_00105589;
    }
    *(int *)(lVar1 + 0x3a8) = *(int *)(lVar1 + 0x3a8) + -1;
  }
  iVar3 = 0;
LAB_00105589:
  up(lVar1 + 0x730);
  return iVar3;
}


// ===== 00105540 nvidia_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010559c) */

int nvidia_resume(long param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(undefined **)(param_1 + 0x60) == &pci_bus_type) && (*(char *)(lVar1 + 0x2b2) != '\0')) {
    lVar2 = *(long *)(param_1 + -0xc0);
    do {
      lVar4 = lVar2;
      lVar2 = *(long *)(lVar4 + 0x10);
    } while (lVar2 != 0);
    lVar2 = *(long *)(*(long *)(lVar4 + 0x110) + 0x40);
    nv_printf(0,"NVRM: restore GPU pm_domain after suspend\n");
    *(undefined8 *)(param_1 + 0x230) = *(undefined8 *)(lVar2 + 0x230);
    dev_pm_genpd_resume(param_1);
    pm_runtime_allow(param_1);
  }
  down(lVar1 + 0x730);
  if ((*(byte *)(lVar1 + 0x11) & 1) != 0) {
    if (*(int *)(lVar1 + 0x3a8) == 0) {
      iVar3 = nv_power_management(lVar1,param_2);
      if (iVar3 == 0) {
        nvidia_modeset_resume(*(undefined4 *)(lVar1 + 0x24));
        *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) & 0xfffffeff;
      }
      goto LAB_00105589;
    }
    *(int *)(lVar1 + 0x3a8) = *(int *)(lVar1 + 0x3a8) + -1;
  }
  iVar3 = 0;
LAB_00105589:
  up(lVar1 + 0x730);
  return iVar3;
}


// ===== 00105630 __pfx_nv_pmops_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010565a) */

uint __pfx_nv_pmops_resume(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_resume(param_1,2);
  return -(uint)(iVar1 != 0) & 0xfffffffb;
}


// ===== 00105640 nv_pmops_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010565a) */

uint nv_pmops_resume(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_resume(param_1,2);
  return -(uint)(iVar1 != 0) & 0xfffffffb;
}


// ===== 00105660 __pfx_nv_pmops_restore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010568a) */

uint __pfx_nv_pmops_restore(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_resume(param_1,2);
  return -(uint)(iVar1 != 0) & 0xfffffffb;
}


// ===== 00105670 nv_pmops_restore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010568a) */

uint nv_pmops_restore(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_resume(param_1,2);
  return -(uint)(iVar1 != 0) & 0xfffffffb;
}


// ===== 00105690 __pfx_nvidia_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105750) */

undefined4 __pfx_nvidia_suspend(long param_1,int param_2,byte param_3)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  
  lVar5 = 0;
  lVar3 = *(long *)(param_1 + 0x78);
  if ((*(undefined **)(param_1 + 0x60) == &pci_bus_type) &&
     (lVar5 = param_1 + -0xd0, *(char *)(lVar3 + 0x2b2) != '\0')) {
    pm_runtime_forbid();
    dev_pm_genpd_suspend(param_1);
    nv_printf(0,"NVRM: set GPU pm_domain to NULL before suspend\n");
    dev_pm_domain_set(param_1,0);
  }
  down(lVar3 + 0x730);
  uVar2 = *(uint *)(lVar3 + 0x10);
  if ((uVar2 & 0x801) == 0) {
    uVar4 = 0;
    goto LAB_0010573b;
  }
  if (*(char *)(lVar3 + 0x399) == '\0') {
    if ((uVar2 & 0x100) == 0) {
      if (((*(char *)(lVar3 + 0x2ff) != '\0') && (param_3 == 0 && *(char *)(lVar3 + 0x2b0) == '\0'))
         && ((uVar2 & 0x10) == 0)) {
        nv_printf(4,
                  "NVRM: GPU %04x:%02x:%02x.%x: PreserveVideoMemoryAllocations module parameter is set. System Power Management attempted without driver procfs suspend interface. Please refer to the \'Configuring Power Management Support\' section in the driver README.\n"
                  ,*(undefined4 *)(lVar3 + 0x14),*(undefined1 *)(lVar3 + 0x18),
                  *(undefined1 *)(lVar3 + 0x19),*(undefined1 *)(lVar3 + 0x1a));
        goto LAB_001057ea;
      }
      nvidia_modeset_suspend(*(undefined4 *)(lVar3 + 0x24));
      uVar4 = nv_power_management(lVar3,param_2);
      *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 0x100;
      cVar1 = *(char *)(lVar3 + 0x301);
    }
    else {
      *(int *)(lVar3 + 0x3a8) = *(int *)(lVar3 + 0x3a8) + 1;
      uVar4 = 0;
      cVar1 = *(char *)(lVar3 + 0x301);
    }
    if (((cVar1 != '\0') && (((param_3 ^ 1) & lVar5 != 0) != 0)) && (param_2 == 1)) {
      pci_save_state(lVar5);
    }
  }
  else {
LAB_001057ea:
    uVar4 = 0x56;
  }
LAB_0010573b:
  up(lVar3 + 0x730);
  return uVar4;
}


// ===== 001056a0 nvidia_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105750) */

undefined4 nvidia_suspend(long param_1,int param_2,byte param_3)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  
  lVar5 = 0;
  lVar3 = *(long *)(param_1 + 0x78);
  if ((*(undefined **)(param_1 + 0x60) == &pci_bus_type) &&
     (lVar5 = param_1 + -0xd0, *(char *)(lVar3 + 0x2b2) != '\0')) {
    pm_runtime_forbid();
    dev_pm_genpd_suspend(param_1);
    nv_printf(0,"NVRM: set GPU pm_domain to NULL before suspend\n");
    dev_pm_domain_set(param_1,0);
  }
  down(lVar3 + 0x730);
  uVar2 = *(uint *)(lVar3 + 0x10);
  if ((uVar2 & 0x801) == 0) {
    uVar4 = 0;
    goto LAB_0010573b;
  }
  if (*(char *)(lVar3 + 0x399) == '\0') {
    if ((uVar2 & 0x100) == 0) {
      if (((*(char *)(lVar3 + 0x2ff) != '\0') && (param_3 == 0 && *(char *)(lVar3 + 0x2b0) == '\0'))
         && ((uVar2 & 0x10) == 0)) {
        nv_printf(4,
                  "NVRM: GPU %04x:%02x:%02x.%x: PreserveVideoMemoryAllocations module parameter is set. System Power Management attempted without driver procfs suspend interface. Please refer to the \'Configuring Power Management Support\' section in the driver README.\n"
                  ,*(undefined4 *)(lVar3 + 0x14),*(undefined1 *)(lVar3 + 0x18),
                  *(undefined1 *)(lVar3 + 0x19),*(undefined1 *)(lVar3 + 0x1a));
        goto LAB_001057ea;
      }
      nvidia_modeset_suspend(*(undefined4 *)(lVar3 + 0x24));
      uVar4 = nv_power_management(lVar3,param_2);
      *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 0x100;
      cVar1 = *(char *)(lVar3 + 0x301);
    }
    else {
      *(int *)(lVar3 + 0x3a8) = *(int *)(lVar3 + 0x3a8) + 1;
      uVar4 = 0;
      cVar1 = *(char *)(lVar3 + 0x301);
    }
    if (((cVar1 != '\0') && (((param_3 ^ 1) & lVar5 != 0) != 0)) && (param_2 == 1)) {
      pci_save_state(lVar5);
    }
  }
  else {
LAB_001057ea:
    uVar4 = 0x56;
  }
LAB_0010573b:
  up(lVar3 + 0x730);
  return uVar4;
}


// ===== 00105800 __pfx_nv_pmops_freeze =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010582d) */
/* WARNING: Removing unreachable block (ram,0x00105845) */

undefined8 __pfx_nv_pmops_freeze(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_suspend(param_1,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  nvidia_resume(param_1,2);
  return 0xfffffffb;
}


// ===== 00105810 nv_pmops_freeze =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010582d) */
/* WARNING: Removing unreachable block (ram,0x00105845) */

undefined8 nv_pmops_freeze(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_suspend(param_1,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  nvidia_resume(param_1,2);
  return 0xfffffffb;
}


// ===== 00105850 __pfx_nv_pmops_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105880) */
/* WARNING: Removing unreachable block (ram,0x00105898) */

undefined8 __pfx_nv_pmops_suspend(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_suspend(param_1,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  nvidia_resume(param_1,2);
  return 0xfffffffb;
}


// ===== 00105860 nv_pmops_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105880) */
/* WARNING: Removing unreachable block (ram,0x00105898) */

undefined8 nv_pmops_suspend(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = nvidia_suspend(param_1,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  nvidia_resume(param_1,2);
  return 0xfffffffb;
}


// ===== 001058a0 __pfx_nvidia_transition_dynamic_power.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001058ec) */

uint __pfx_nvidia_transition_dynamic_power_isra_0(long param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  long in_GS_OFFSET;
  char cStack_21;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = 0;
  cStack_21 = '\0';
  if ((*(ushort *)(param_1 + 0x10) & 0x801) != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      iVar2 = rm_transition_dynamic_power(0,param_1,param_2,&cStack_21);
    }
    else {
      puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar4 == (undefined4 *)0x0) {
        uVar3 = 0xfffffff4;
        goto LAB_001058d5;
      }
      *puVar4 = 0x2ff0;
      *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
      iVar2 = rm_transition_dynamic_power(puVar4,param_1,param_2,&cStack_21);
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar4);
      }
    }
    if (cStack_21 == '\0') {
      uVar3 = -(uint)(iVar2 != 0) & 0xfffffffb;
    }
    else {
      uVar3 = 0xfffffff5;
    }
  }
LAB_001058d5:
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001058b0 nvidia_transition_dynamic_power.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001058ec) */

uint nvidia_transition_dynamic_power_isra_0(long param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  long in_GS_OFFSET;
  char local_21;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = 0;
  local_21 = '\0';
  if ((*(ushort *)(param_1 + 0x10) & 0x801) != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      iVar2 = rm_transition_dynamic_power(0,param_1,param_2,&local_21);
    }
    else {
      puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar4 == (undefined4 *)0x0) {
        uVar3 = 0xfffffff4;
        goto LAB_001058d5;
      }
      *puVar4 = 0x2ff0;
      *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
      iVar2 = rm_transition_dynamic_power(puVar4,param_1,param_2,&local_21);
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar4);
      }
    }
    if (local_21 == '\0') {
      uVar3 = -(uint)(iVar2 != 0) & 0xfffffffb;
    }
    else {
      uVar3 = 0xfffffff5;
    }
  }
LAB_001058d5:
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001059d0 __pfx_nv_pmops_runtime_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105a50) */
/* WARNING: Removing unreachable block (ram,0x00105a79) */

int __pfx_nv_pmops_runtime_suspend(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(code **)(lVar1 + 0x5270) != (code *)0x0) &&
     (iVar2 = (**(code **)(lVar1 + 0x5270))(), iVar2 != 0)) {
    return iVar2;
  }
  nv_pci_tegra_boost_clocks(param_1);
  iVar2 = nvidia_transition_dynamic_power_isra_0(*(undefined8 *)(param_1 + 0x78),1);
  if (iVar2 == 0) {
    if (((*(byte *)(lVar1 + 0x11) & 4) != 0) && (*(long *)(lVar1 + 0x3b8) != 0)) {
      os_pci_trigger_flr();
    }
  }
  else if (*(code **)(lVar1 + 0x5278) != (code *)0x0) {
    (**(code **)(lVar1 + 0x5278))(param_1);
    return iVar2;
  }
  return iVar2;
}


// ===== 001059e0 nv_pmops_runtime_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105a50) */
/* WARNING: Removing unreachable block (ram,0x00105a79) */

int nv_pmops_runtime_suspend(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(code **)(lVar1 + 0x5270) != (code *)0x0) &&
     (iVar2 = (**(code **)(lVar1 + 0x5270))(), iVar2 != 0)) {
    return iVar2;
  }
  nv_pci_tegra_boost_clocks(param_1);
  iVar2 = nvidia_transition_dynamic_power_isra_0(*(undefined8 *)(param_1 + 0x78),1);
  if (iVar2 == 0) {
    if (((*(byte *)(lVar1 + 0x11) & 4) != 0) && (*(long *)(lVar1 + 0x3b8) != 0)) {
      os_pci_trigger_flr();
    }
  }
  else if (*(code **)(lVar1 + 0x5278) != (code *)0x0) {
    (**(code **)(lVar1 + 0x5278))(param_1);
    return iVar2;
  }
  return iVar2;
}


// ===== 00105a80 __pfx_nv_pmops_runtime_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105ade) */

int __pfx_nv_pmops_runtime_resume(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x78);
  nv_pci_tegra_boost_clocks();
  iVar3 = nvidia_transition_dynamic_power_isra_0(*(undefined8 *)(param_1 + 0x78),0);
  if ((iVar3 == 0) && (pcVar2 = *(code **)(lVar1 + 0x5278), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(param_1);
    if (iVar3 != 0) {
      nvidia_transition_dynamic_power_isra_0(*(undefined8 *)(param_1 + 0x78),1);
    }
  }
  return iVar3;
}


// ===== 00105a90 nv_pmops_runtime_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105ade) */

int nv_pmops_runtime_resume(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x78);
  nv_pci_tegra_boost_clocks();
  iVar3 = nvidia_transition_dynamic_power_isra_0(*(undefined8 *)(param_1 + 0x78),0);
  if ((iVar3 == 0) && (pcVar2 = *(code **)(lVar1 + 0x5278), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(param_1);
    if (iVar3 != 0) {
      nvidia_transition_dynamic_power_isra_0(*(undefined8 *)(param_1 + 0x78),1);
    }
  }
  return iVar3;
}


// ===== 00105b00 __pfx_nv_set_system_power_state.part.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105b7c) */

undefined8 __pfx_nv_set_system_power_state_part_0(int param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  undefined8 uVar9;
  
  down(nv_system_power_state_lock);
  iVar6 = nv_system_pm_action_depth;
  iVar5 = nv_system_power_state;
  if (nv_system_power_state != param_1) {
    if (param_1 == 2) {
      if (nv_system_pm_action_depth != 1) {
        down(nv_linux_devices_lock);
        if (nv_linux_devices != 0) {
          lVar8 = nv_linux_devices;
          if (iVar6 == 2) {
            do {
              lVar8 = *(long *)(lVar8 + 0x758);
            } while (lVar8 != 0);
          }
          else {
            do {
              if (((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) &&
                 (iVar6 = nvidia_resume(*(undefined8 *)(lVar8 + 0x3b0),2), iVar6 != 0)) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)invalidInstructionException();
                (*pcVar3)();
              }
              lVar8 = *(long *)(lVar8 + 0x758);
            } while (lVar8 != 0);
          }
        }
        up(nv_linux_devices_lock);
        iVar6 = nv_uvm_resume();
        if (iVar6 != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        down(nv_linux_devices_lock);
        for (lVar8 = nv_linux_devices; lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x758)) {
          if (((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) &&
             (iVar6 = nv_restore_user_channels(lVar8), iVar6 != 0)) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
        }
        up(nv_linux_devices_lock);
      }
      nvidia_modeset_resume(0);
      up_write(nv_system_pm_lock);
      iVar5 = param_1;
    }
    else {
      uVar9 = 0x1f;
      if (nv_system_power_state != 2) goto LAB_00105b5a;
      nv_system_pm_action_depth = param_2;
      down_write(nv_system_pm_lock);
      iVar6 = nv_system_pm_action_depth;
      nvidia_modeset_suspend(0);
      iVar5 = param_1;
      if (iVar6 != 1) {
        down(nv_linux_devices_lock);
        lVar8 = nv_linux_devices;
        if (nv_linux_devices == 0) {
          up(nv_linux_devices_lock);
        }
        else {
          do {
            if ((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) {
              lVar2 = *(long *)(lVar8 + 8);
              cVar4 = rm_is_altstack_in_use();
              if (cVar4 == '\0') {
                puVar7 = (undefined4 *)0x0;
                down(lVar2 + 0x730);
                if ((*(byte *)(lVar8 + 0x10) & 1) == 0) {
                  up(lVar2 + 0x730);
                }
                else {
LAB_00105cea:
                  iVar5 = rm_ref_dynamic_power(puVar7,lVar8,2);
                  if (iVar5 != 0) {
                    /* WARNING: Does not return */
                    pcVar3 = (code *)invalidInstructionException();
                    (*pcVar3)();
                  }
                  down(lVar2 + 0x868);
                  nv_set_safe_to_mmap_locked(lVar8,0);
                  nv_revoke_gpu_mappings_locked(lVar8);
                  up(lVar2 + 0x868);
                  iVar5 = rm_stop_user_channels(puVar7,lVar8);
                  if (iVar5 != 0) {
                    /* WARNING: Does not return */
                    pcVar3 = (code *)invalidInstructionException();
                    (*pcVar3)();
                  }
                  up(lVar2 + 0x730);
                  if ((puVar7 != (undefined4 *)0x0) &&
                     (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
                    kmem_cache_free(nvidia_stack_t_cache,puVar7);
                  }
                }
              }
              else {
                puVar7 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
                if (puVar7 == (undefined4 *)0x0) {
                    /* WARNING: Does not return */
                  pcVar3 = (code *)invalidInstructionException();
                  (*pcVar3)();
                }
                *puVar7 = 0x2ff0;
                *(undefined4 **)(puVar7 + 2) = puVar7 + 0xc00;
                down(lVar2 + 0x730);
                if ((*(byte *)(lVar8 + 0x10) & 1) != 0) goto LAB_00105cea;
                up(lVar2 + 0x730);
                cVar4 = rm_is_altstack_in_use();
                if (cVar4 != '\0') {
                  kmem_cache_free(nvidia_stack_t_cache,puVar7);
                }
              }
            }
            plVar1 = (long *)(lVar8 + 0x758);
            lVar8 = *plVar1;
          } while (*plVar1 != 0);
          up(nv_linux_devices_lock);
        }
        iVar5 = nv_uvm_suspend();
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        iVar5 = param_1;
        if (iVar6 != 2) {
          down(nv_linux_devices_lock);
          for (lVar8 = nv_linux_devices; lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x758)) {
            if (((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) &&
               (iVar6 = nvidia_suspend(*(undefined8 *)(lVar8 + 0x3b0),param_1,1), iVar6 != 0)) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
          }
          up(nv_linux_devices_lock);
          iVar5 = param_1;
        }
      }
    }
  }
  nv_system_power_state = iVar5;
  uVar9 = 0;
LAB_00105b5a:
  up(nv_system_power_state_lock);
  return uVar9;
}


// ===== 00105b10 nv_set_system_power_state.part.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00105b7c) */

undefined8 nv_set_system_power_state_part_0(int param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  undefined8 uVar9;
  
  down(nv_system_power_state_lock);
  iVar6 = nv_system_pm_action_depth;
  iVar5 = nv_system_power_state;
  if (nv_system_power_state != param_1) {
    if (param_1 == 2) {
      if (nv_system_pm_action_depth != 1) {
        down(nv_linux_devices_lock);
        if (nv_linux_devices != 0) {
          lVar8 = nv_linux_devices;
          if (iVar6 == 2) {
            do {
              lVar8 = *(long *)(lVar8 + 0x758);
            } while (lVar8 != 0);
          }
          else {
            do {
              if (((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) &&
                 (iVar6 = nvidia_resume(*(undefined8 *)(lVar8 + 0x3b0),2), iVar6 != 0)) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)invalidInstructionException();
                (*pcVar3)();
              }
              lVar8 = *(long *)(lVar8 + 0x758);
            } while (lVar8 != 0);
          }
        }
        up(nv_linux_devices_lock);
        iVar6 = nv_uvm_resume();
        if (iVar6 != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        down(nv_linux_devices_lock);
        for (lVar8 = nv_linux_devices; lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x758)) {
          if (((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) &&
             (iVar6 = nv_restore_user_channels(lVar8), iVar6 != 0)) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
        }
        up(nv_linux_devices_lock);
      }
      nvidia_modeset_resume(0);
      up_write(nv_system_pm_lock);
      iVar5 = param_1;
    }
    else {
      uVar9 = 0x1f;
      if (nv_system_power_state != 2) goto LAB_00105b5a;
      nv_system_pm_action_depth = param_2;
      down_write(nv_system_pm_lock);
      iVar6 = nv_system_pm_action_depth;
      nvidia_modeset_suspend(0);
      iVar5 = param_1;
      if (iVar6 != 1) {
        down(nv_linux_devices_lock);
        lVar8 = nv_linux_devices;
        if (nv_linux_devices == 0) {
          up(nv_linux_devices_lock);
        }
        else {
          do {
            if ((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) {
              lVar2 = *(long *)(lVar8 + 8);
              cVar4 = rm_is_altstack_in_use();
              if (cVar4 == '\0') {
                puVar7 = (undefined4 *)0x0;
                down(lVar2 + 0x730);
                if ((*(byte *)(lVar8 + 0x10) & 1) == 0) {
                  up(lVar2 + 0x730);
                }
                else {
LAB_00105cea:
                  iVar5 = rm_ref_dynamic_power(puVar7,lVar8,2);
                  if (iVar5 != 0) {
                    /* WARNING: Does not return */
                    pcVar3 = (code *)invalidInstructionException();
                    (*pcVar3)();
                  }
                  down(lVar2 + 0x868);
                  nv_set_safe_to_mmap_locked(lVar8,0);
                  nv_revoke_gpu_mappings_locked(lVar8);
                  up(lVar2 + 0x868);
                  iVar5 = rm_stop_user_channels(puVar7,lVar8);
                  if (iVar5 != 0) {
                    /* WARNING: Does not return */
                    pcVar3 = (code *)invalidInstructionException();
                    (*pcVar3)();
                  }
                  up(lVar2 + 0x730);
                  if ((puVar7 != (undefined4 *)0x0) &&
                     (cVar4 = rm_is_altstack_in_use(), cVar4 != '\0')) {
                    kmem_cache_free(nvidia_stack_t_cache,puVar7);
                  }
                }
              }
              else {
                puVar7 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
                if (puVar7 == (undefined4 *)0x0) {
                    /* WARNING: Does not return */
                  pcVar3 = (code *)invalidInstructionException();
                  (*pcVar3)();
                }
                *puVar7 = 0x2ff0;
                *(undefined4 **)(puVar7 + 2) = puVar7 + 0xc00;
                down(lVar2 + 0x730);
                if ((*(byte *)(lVar8 + 0x10) & 1) != 0) goto LAB_00105cea;
                up(lVar2 + 0x730);
                cVar4 = rm_is_altstack_in_use();
                if (cVar4 != '\0') {
                  kmem_cache_free(nvidia_stack_t_cache,puVar7);
                }
              }
            }
            plVar1 = (long *)(lVar8 + 0x758);
            lVar8 = *plVar1;
          } while (*plVar1 != 0);
          up(nv_linux_devices_lock);
        }
        iVar5 = nv_uvm_suspend();
        if (iVar5 != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        iVar5 = param_1;
        if (iVar6 != 2) {
          down(nv_linux_devices_lock);
          for (lVar8 = nv_linux_devices; lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x758)) {
            if (((*(char *)(lVar8 + 0x2b0) == '\0') && ((*(byte *)(lVar8 + 0x10) & 0x10) == 0)) &&
               (iVar6 = nvidia_suspend(*(undefined8 *)(lVar8 + 0x3b0),param_1,1), iVar6 != 0)) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)invalidInstructionException();
              (*pcVar3)();
            }
          }
          up(nv_linux_devices_lock);
          iVar5 = param_1;
        }
      }
    }
  }
  nv_system_power_state = iVar5;
  uVar9 = 0;
LAB_00105b5a:
  up(nv_system_power_state_lock);
  return uVar9;
}


// ===== 00106010 __pfx_nv_pm_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001060b3) */
/* WARNING: Removing unreachable block (ram,0x00106061) */
/* WARNING: Removing unreachable block (ram,0x0010606f) */

undefined8 __pfx_nv_pm_notifier(undefined8 param_1,ulong param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  if (param_2 == 3) {
    pcVar2 = "suspend";
    uVar3 = 1;
  }
  else {
    if (param_2 < 4) {
      if (param_2 == 1) {
        pcVar2 = "hibernate";
        uVar3 = 0;
        goto LAB_00106050;
      }
      if (param_2 != 2) {
        return 0;
      }
    }
    else if (param_2 != 4) {
      return 0;
    }
    pcVar2 = "resume";
    uVar3 = 2;
  }
LAB_00106050:
  iVar1 = nv_set_system_power_state_part_0(uVar3,nv_procfs_pm_action_depth);
  if (iVar1 != 0) {
    nv_printf(4,"NVRM: PM %s notifier failed: 0x%x\n",pcVar2);
    return 0x8002;
  }
  return 1;
}


// ===== 00106020 nv_pm_notifier =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001060b3) */
/* WARNING: Removing unreachable block (ram,0x00106061) */
/* WARNING: Removing unreachable block (ram,0x0010606f) */

undefined8 nv_pm_notifier(undefined8 param_1,ulong param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  if (param_2 == 3) {
    pcVar2 = "suspend";
    uVar3 = 1;
  }
  else {
    if (param_2 < 4) {
      if (param_2 == 1) {
        pcVar2 = "hibernate";
        uVar3 = 0;
        goto LAB_00106050;
      }
      if (param_2 != 2) {
        return 0;
      }
    }
    else if (param_2 != 4) {
      return 0;
    }
    pcVar2 = "resume";
    uVar3 = 2;
  }
LAB_00106050:
  iVar1 = nv_set_system_power_state_part_0(uVar3,nv_procfs_pm_action_depth);
  if (iVar1 != 0) {
    nv_printf(4,"NVRM: PM %s notifier failed: 0x%x\n",pcVar2);
    return 0x8002;
  }
  return 1;
}


// ===== 001060c0 __pfx_find_uuid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106167) */

long __pfx_find_uuid(long *param_1)

{
  long lVar1;
  
  down(nv_linux_devices_lock);
  for (lVar1 = nv_linux_devices; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x758)) {
    down(lVar1 + 0x730);
    if (((*(char *)(lVar1 + 0x2c) != '\0') && (*(long *)(lVar1 + 0x2d) == *param_1)) &&
       (*(long *)(lVar1 + 0x35) == param_1[1])) break;
    up(lVar1 + 0x730);
  }
  up(nv_linux_devices_lock);
  return lVar1;
}


// ===== 001060d0 find_uuid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106167) */

long find_uuid(long *param_1)

{
  long lVar1;
  
  down(nv_linux_devices_lock);
  for (lVar1 = nv_linux_devices; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x758)) {
    down(lVar1 + 0x730);
    if (((*(char *)(lVar1 + 0x2c) != '\0') && (*(long *)(lVar1 + 0x2d) == *param_1)) &&
       (*(long *)(lVar1 + 0x35) == param_1[1])) break;
    up(lVar1 + 0x730);
  }
  up(nv_linux_devices_lock);
  return lVar1;
}


// ===== 00106170 __pfx_nv_dev_free_stacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001061c0) */

void __pfx_nv_dev_free_stacks(long param_1)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_1 + 0x4b0);
  do {
    lVar1 = *plVar3;
    if (lVar1 != 0) {
      cVar2 = rm_is_altstack_in_use();
      if (cVar2 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,lVar1);
      }
      *plVar3 = 0;
    }
    plVar3 = plVar3 + 1;
  } while (plVar3 != (long *)(param_1 + 0x4d8));
  return;
}


// ===== 00106180 nv_dev_free_stacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001061c0) */

void nv_dev_free_stacks(long param_1)

{
  long lVar1;
  char cVar2;
  long *plVar3;
  
  plVar3 = (long *)(param_1 + 0x4b0);
  do {
    lVar1 = *plVar3;
    if (lVar1 != 0) {
      cVar2 = rm_is_altstack_in_use();
      if (cVar2 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,lVar1);
      }
      *plVar3 = 0;
    }
    plVar3 = plVar3 + 1;
  } while (plVar3 != (long *)(param_1 + 0x4d8));
  return;
}


// ===== 001061e0 __pfx_nv_get_num_dpaux_instances =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106203) */

undefined8 __pfx_nv_get_num_dpaux_instances(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x178);
  return 0;
}


// ===== 001061f0 nv_get_num_dpaux_instances =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106203) */

undefined8 nv_get_num_dpaux_instances(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x178);
  return 0;
}


// ===== 00106210 __pfx_nv_schedule_uvm_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_schedule_uvm_isr(long param_1)

{
  long lVar1;
  
  lVar1 = param_1 + 0x2d;
  if (*(char *)(param_1 + 0x2c) == '\0') {
    lVar1 = 0;
  }
  nv_uvm_event_interrupt(lVar1);
  return;
}


// ===== 00106220 nv_schedule_uvm_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_schedule_uvm_isr(long param_1)

{
  long lVar1;
  
  lVar1 = param_1 + 0x2d;
  if (*(char *)(param_1 + 0x2c) == '\0') {
    lVar1 = 0;
  }
  nv_uvm_event_interrupt(lVar1);
  return;
}


// ===== 00106250 __pfx_nv_schedule_uvm_drain_p2p =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_schedule_uvm_drain_p2p(void)

{
  nv_uvm_drain_P2P();
  return;
}


// ===== 00106260 nv_schedule_uvm_drain_p2p =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_schedule_uvm_drain_p2p(void)

{
  nv_uvm_drain_P2P();
  return;
}


// ===== 00106270 __pfx_nv_schedule_uvm_resume_p2p =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_schedule_uvm_resume_p2p(void)

{
  nv_uvm_resume_P2P();
  return;
}


// ===== 00106280 nv_schedule_uvm_resume_p2p =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_schedule_uvm_resume_p2p(void)

{
  nv_uvm_resume_P2P();
  return;
}


// ===== 00106290 __pfx_nv_start_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010631a) */

int __pfx_nv_start_device(long param_1,undefined8 param_2)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  long lVar13;
  long in_GS_OFFSET;
  int iStack_44;
  long lStack_40;
  
  lVar1 = *(long *)(param_1 + 8);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_44 = 0;
  iVar6 = nv_get_rsync_info();
  if (iVar6 != 0) goto LAB_001062ec;
  if ((*(int *)(lVar1 + 0x4a0) == -1) || (*(int *)(lVar1 + 0x4a4) == 0)) {
LAB_00106355:
    if ((*(undefined **)(*(long *)(lVar1 + 0x3b0) + 0x60) == &pci_bus_type) &&
       (*(short *)(param_1 + 0x1e) == 0)) {
      bVar3 = false;
      bVar2 = false;
      iVar6 = -6;
      nv_printf(4,"NVRM: open of non-existent GPU with minor number %d\n",
                *(undefined4 *)(lVar1 + 0x750));
      uVar8 = *(uint *)(param_1 + 0x10);
      bVar4 = false;
      goto LAB_00106419;
    }
    uVar11 = 1;
    if ((*(byte *)(param_1 + 0x11) & 8) != 0) {
      uVar11 = 2;
    }
    iVar7 = rm_ref_dynamic_power(param_2,param_1,uVar11);
    if (iVar7 != 0) goto LAB_00106406;
    uVar8 = *(uint *)(param_1 + 0x10);
    if ((uVar8 & 0x800) == 0) {
      puVar12 = (undefined8 *)(lVar1 + 0x4b0);
      do {
        cVar5 = rm_is_altstack_in_use();
        puVar9 = (undefined4 *)0x0;
        if (cVar5 != '\0') {
          puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
          if (puVar9 == (undefined4 *)0x0) {
            bVar3 = true;
            bVar2 = false;
            iVar6 = -0xc;
            nv_dev_free_stacks(lVar1);
            uVar8 = *(uint *)(param_1 + 0x10);
            bVar4 = false;
            goto LAB_00106419;
          }
          *puVar9 = 0x2ff0;
          *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
        }
        *puVar12 = puVar9;
        puVar12 = puVar12 + 1;
      } while ((undefined8 *)(lVar1 + 0x4d8) != puVar12);
      uVar8 = *(uint *)(param_1 + 0x10);
      if (*(undefined **)(*(long *)(lVar1 + 0x3b0) + 0x60) == &pci_bus_type) {
        if ((uVar8 & 0x800) == 0) {
          rm_read_registry_dword(param_2,param_1,"EnableMSI",&iStack_44);
          if (iStack_44 != 1) {
LAB_0010698f:
            uVar8 = *(uint *)(param_1 + 0x10);
            goto LAB_00106695;
          }
          lVar13 = *(long *)(lVar1 + 0x3b8);
          if (*(char *)(lVar13 + 0x70) != '\0') {
            cVar5 = rm_is_msix_allowed(param_2,param_1);
            if (cVar5 != '\0') {
              nv_init_msix(param_1);
            }
            lVar13 = *(long *)(lVar1 + 0x3b8);
          }
          uVar8 = *(uint *)(param_1 + 0x10);
          if (*(char *)(lVar13 + 0x6f) == '\0') goto LAB_00106695;
          if ((uVar8 & 0x40) == 0) {
            nv_init_msi(param_1);
            goto LAB_0010698f;
          }
LAB_00106896:
          if ((uVar8 & 0x800) != 0) goto LAB_00106501;
          if ((uVar8 & 0x10) == 0) {
LAB_00106958:
            iVar7 = nv_request_msix_irq(lVar1);
          }
          else {
LAB_001068a7:
            iVar7 = nv_soc_register_irqs(param_1);
          }
          goto LAB_001066f2;
        }
        goto LAB_00106395;
      }
LAB_00106695:
      if ((uVar8 & 0x20) != 0) {
        if ((uVar8 & 0x800) != 0) goto LAB_00106501;
        if ((uVar8 & 0x10) != 0) goto LAB_001068a7;
        if ((uVar8 & 0x40) != 0) goto LAB_00106958;
        iVar7 = *(int *)(param_1 + 0x17c);
LAB_001066c4:
        iVar7 = request_threaded_irq
                          (iVar7,nvidia_isr,nvidia_isr_kthread_bh,(uVar8 >> 5 & 1 ^ 1) << 7,
                           nv_device_name,lVar1);
LAB_001066f2:
        if (iVar7 != 0) {
          if ((*(int *)(param_1 + 0x17c) != 0) && (iVar7 == -0x10)) {
            nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Tried to get IRQ %d, but another driver\n",
                      *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                      *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
                      *(int *)(param_1 + 0x17c));
            nv_printf(4,"NVRM: has it and is not sharing it.\n");
            nv_printf(4,"NVRM: You may want to verify that no audio driver");
            nv_printf(4," is using the IRQ.\n");
          }
          bVar2 = false;
          bVar3 = true;
          nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: request_irq() failed (%d)\n",
                    *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),iVar7);
          uVar8 = *(uint *)(param_1 + 0x10);
          bVar4 = false;
          iVar6 = iVar7;
          goto LAB_00106419;
        }
        if ((*(byte *)(param_1 + 0x11) & 8) != 0) goto LAB_00106501;
        iVar7 = os_alloc_mutex(lVar1 + 2000);
        if (iVar7 == 0) {
          nv_kthread_q_item_init(lVar1 + 0x7b0,nvidia_isr_bh_unlocked,param_1);
          iVar7 = nv_kthread_q_init(lVar1 + 0x768,nv_device_name);
          if (iVar7 != 0) goto LAB_001067f7;
          iVar7 = nv_kthread_q_init(lVar1 + 0x820,"nv_queue");
          if (iVar7 != 0) {
            bVar4 = false;
            bVar2 = true;
            iVar6 = iVar7;
            goto LAB_00106801;
          }
          bVar2 = true;
          *(long *)(param_1 + 0x2f0) = lVar1 + 0x820;
          bVar4 = false;
          if (*(char *)(lVar1 + 0x4a8) != '\0') {
            iVar7 = nv_kthread_q_init(lVar1 + 0x458,"nv_remove_numa_memory");
            if (iVar7 != 0) {
              bVar4 = false;
              iVar6 = iVar7;
              goto LAB_00106801;
            }
            bVar4 = true;
          }
          goto LAB_00106508;
        }
LAB_001067f7:
        bVar4 = false;
        bVar2 = false;
        iVar6 = iVar7;
        goto LAB_00106801;
      }
      if ((uVar8 & 0x40) != 0) goto LAB_00106896;
      iVar7 = *(int *)(param_1 + 0x17c);
      if (iVar7 != 0) {
        if ((uVar8 & 0x800) == 0) {
          if ((uVar8 & 0x10) == 0) goto LAB_001066c4;
          goto LAB_001068a7;
        }
        goto LAB_00106501;
      }
      if ((uVar8 & 0x10) != 0) {
        if ((uVar8 & 0x800) == 0) goto LAB_001068a7;
        goto LAB_00106501;
      }
LAB_001063bb:
      bVar2 = false;
      bVar3 = true;
      nv_printf(4,
                "NVRM: GPU %04x:%02x:%02x.%x: No interrupts of any type are available. Cannot use this GPU.\n"
                ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
      uVar8 = *(uint *)(param_1 + 0x10);
      bVar4 = false;
      iVar6 = -5;
      goto LAB_00106419;
    }
LAB_00106395:
    if (((((uVar8 & 0x20) == 0) && ((uVar8 & 0x40) == 0)) && (*(int *)(param_1 + 0x17c) == 0)) &&
       ((uVar8 & 0x10) == 0)) goto LAB_001063bb;
LAB_00106501:
    bVar4 = false;
    bVar2 = false;
LAB_00106508:
    cVar5 = rm_init_adapter(param_2,param_1);
    if (cVar5 != '\0') {
      rm_get_gpu_uuid_raw(param_2,param_1);
      uVar8 = *(uint *)(param_1 + 0x10);
      if ((uVar8 & 0x800) == 0) {
        nv_acpi_register_notifier(lVar1);
        uVar8 = *(uint *)(param_1 + 0x10);
      }
      *(uint *)(param_1 + 0x10) = uVar8 | 1;
      rm_request_dnotifier_state(param_2,param_1);
      rm_unref_dynamic_power(param_2,param_1,2);
      goto LAB_001062ec;
    }
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: rm_init_adapter failed, device minor number %d\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
              *(undefined4 *)(lVar1 + 0x750));
    iVar6 = -5;
LAB_00106801:
    uVar8 = *(uint *)(param_1 + 0x10);
    if ((uVar8 & 0x800) != 0) {
      bVar3 = true;
      goto LAB_00106419;
    }
    if ((uVar8 & 0x40) == 0) {
      if ((uVar8 & 0x10) == 0) {
        bVar3 = true;
        free_irq(*(undefined4 *)(param_1 + 0x17c),lVar1);
        uVar8 = *(uint *)(param_1 + 0x10);
      }
      else {
LAB_0010681e:
        bVar3 = true;
        nv_soc_free_irqs(param_1);
        uVar8 = *(uint *)(param_1 + 0x10);
      }
      goto LAB_00106419;
    }
    if ((uVar8 & 0x10) != 0) goto LAB_0010681e;
    uVar10 = 0;
    if (*(int *)(lVar1 + 0x7dc) != 0) {
      do {
        free_irq(*(undefined4 *)(*(long *)(lVar1 + 0x7f0) + (long)(int)uVar10 * 8),lVar1);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(lVar1 + 0x7dc));
      uVar8 = *(uint *)(param_1 + 0x10);
      bVar3 = true;
      goto LAB_00106419;
    }
    bVar3 = true;
    if ((uVar8 & 0x20) == 0) goto LAB_00106622;
LAB_001065a7:
    *(uint *)(param_1 + 0x10) = uVar8 & 0xffffffdf;
    pci_disable_msi(*(undefined8 *)(lVar1 + 0x3b8));
    lVar13 = *(long *)(lVar1 + 0x5198);
    if (lVar13 != 0) {
LAB_001065c9:
      kfree(lVar13);
    }
  }
  else {
    if (nv_ctl_device._2040_8_ != 0) {
      *(undefined8 *)(lVar1 + 0x7f8) = nv_ctl_device._2040_8_;
      goto LAB_00106355;
    }
    nv_printf(4,"NVRM: numa memblock size of zero found during device start");
LAB_00106406:
    bVar4 = false;
    uVar8 = *(uint *)(param_1 + 0x10);
    bVar3 = false;
    bVar2 = false;
    iVar6 = -0x16;
LAB_00106419:
    if ((uVar8 & 0x20) != 0) goto LAB_001065a7;
    if ((uVar8 & 0x40) != 0) {
LAB_00106622:
      *(uint *)(param_1 + 0x10) = uVar8 & 0xffffffbf;
      pci_disable_msix(*(undefined8 *)(lVar1 + 0x3b8));
      kfree(*(undefined8 *)(lVar1 + 0x5198));
      lVar13 = *(long *)(lVar1 + 0x7f0);
      goto LAB_001065c9;
    }
  }
  if (*(long *)(lVar1 + 0x7e8) != 0) {
    os_free_mutex();
    *(undefined8 *)(lVar1 + 0x7e8) = 0;
  }
  if (*(long *)(param_1 + 0x2f0) == 0) {
LAB_00106579:
    if (bVar2) {
      if ((*(byte *)(param_1 + 0x11) & 8) != 0) goto LAB_0010647a;
      nv_kthread_q_stop(lVar1 + 0x768);
    }
LAB_00106462:
    if ((bVar4) && ((*(byte *)(param_1 + 0x11) & 8) == 0)) {
      nv_kthread_q_stop(lVar1 + 0x458);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
      *(undefined8 *)(param_1 + 0x2f0) = 0;
      nv_kthread_q_stop(lVar1 + 0x820);
      goto LAB_00106579;
    }
    if (!bVar2) goto LAB_00106462;
  }
LAB_0010647a:
  if (*(long *)(lVar1 + 2000) != 0) {
    os_free_mutex();
    *(undefined8 *)(lVar1 + 2000) = 0;
  }
  uVar8 = *(uint *)(param_1 + 0x10);
  if ((uVar8 & 0x400) != 0) {
    if (*(long *)(lVar1 + 0x3b8) != 0) {
      nv_printf(0,"NVRM: Trigger FLR on Failure!\n");
      os_pci_trigger_flr(*(undefined8 *)(lVar1 + 0x3b8));
      uVar8 = *(uint *)(param_1 + 0x10);
    }
    *(uint *)(param_1 + 0x10) = uVar8 & 0xfffffbff;
  }
  nv_dev_free_stacks(lVar1);
  if (bVar3) {
    rm_unref_dynamic_power(param_2,param_1,1);
  }
  nv_put_rsync_info();
LAB_001062ec:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001062a0 nv_start_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010631a) */

int nv_start_device(long param_1,undefined8 param_2)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  long lVar13;
  long in_GS_OFFSET;
  int local_44;
  long local_40;
  
  lVar1 = *(long *)(param_1 + 8);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_44 = 0;
  iVar6 = nv_get_rsync_info();
  if (iVar6 != 0) goto LAB_001062ec;
  if ((*(int *)(lVar1 + 0x4a0) == -1) || (*(int *)(lVar1 + 0x4a4) == 0)) {
LAB_00106355:
    if ((*(undefined **)(*(long *)(lVar1 + 0x3b0) + 0x60) == &pci_bus_type) &&
       (*(short *)(param_1 + 0x1e) == 0)) {
      bVar3 = false;
      bVar2 = false;
      iVar6 = -6;
      nv_printf(4,"NVRM: open of non-existent GPU with minor number %d\n",
                *(undefined4 *)(lVar1 + 0x750));
      uVar8 = *(uint *)(param_1 + 0x10);
      bVar4 = false;
      goto LAB_00106419;
    }
    uVar11 = 1;
    if ((*(byte *)(param_1 + 0x11) & 8) != 0) {
      uVar11 = 2;
    }
    iVar7 = rm_ref_dynamic_power(param_2,param_1,uVar11);
    if (iVar7 != 0) goto LAB_00106406;
    uVar8 = *(uint *)(param_1 + 0x10);
    if ((uVar8 & 0x800) == 0) {
      puVar12 = (undefined8 *)(lVar1 + 0x4b0);
      do {
        cVar5 = rm_is_altstack_in_use();
        puVar9 = (undefined4 *)0x0;
        if (cVar5 != '\0') {
          puVar9 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
          if (puVar9 == (undefined4 *)0x0) {
            bVar3 = true;
            bVar2 = false;
            iVar6 = -0xc;
            nv_dev_free_stacks(lVar1);
            uVar8 = *(uint *)(param_1 + 0x10);
            bVar4 = false;
            goto LAB_00106419;
          }
          *puVar9 = 0x2ff0;
          *(undefined4 **)(puVar9 + 2) = puVar9 + 0xc00;
        }
        *puVar12 = puVar9;
        puVar12 = puVar12 + 1;
      } while ((undefined8 *)(lVar1 + 0x4d8) != puVar12);
      uVar8 = *(uint *)(param_1 + 0x10);
      if (*(undefined **)(*(long *)(lVar1 + 0x3b0) + 0x60) == &pci_bus_type) {
        if ((uVar8 & 0x800) == 0) {
          rm_read_registry_dword(param_2,param_1,"EnableMSI",&local_44);
          if (local_44 != 1) {
LAB_0010698f:
            uVar8 = *(uint *)(param_1 + 0x10);
            goto LAB_00106695;
          }
          lVar13 = *(long *)(lVar1 + 0x3b8);
          if (*(char *)(lVar13 + 0x70) != '\0') {
            cVar5 = rm_is_msix_allowed(param_2,param_1);
            if (cVar5 != '\0') {
              nv_init_msix(param_1);
            }
            lVar13 = *(long *)(lVar1 + 0x3b8);
          }
          uVar8 = *(uint *)(param_1 + 0x10);
          if (*(char *)(lVar13 + 0x6f) == '\0') goto LAB_00106695;
          if ((uVar8 & 0x40) == 0) {
            nv_init_msi(param_1);
            goto LAB_0010698f;
          }
LAB_00106896:
          if ((uVar8 & 0x800) != 0) goto LAB_00106501;
          if ((uVar8 & 0x10) == 0) {
LAB_00106958:
            iVar7 = nv_request_msix_irq(lVar1);
          }
          else {
LAB_001068a7:
            iVar7 = nv_soc_register_irqs(param_1);
          }
          goto LAB_001066f2;
        }
        goto LAB_00106395;
      }
LAB_00106695:
      if ((uVar8 & 0x20) != 0) {
        if ((uVar8 & 0x800) != 0) goto LAB_00106501;
        if ((uVar8 & 0x10) != 0) goto LAB_001068a7;
        if ((uVar8 & 0x40) != 0) goto LAB_00106958;
        iVar7 = *(int *)(param_1 + 0x17c);
LAB_001066c4:
        iVar7 = request_threaded_irq
                          (iVar7,nvidia_isr,nvidia_isr_kthread_bh,(uVar8 >> 5 & 1 ^ 1) << 7,
                           nv_device_name,lVar1);
LAB_001066f2:
        if (iVar7 != 0) {
          if ((*(int *)(param_1 + 0x17c) != 0) && (iVar7 == -0x10)) {
            nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Tried to get IRQ %d, but another driver\n",
                      *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                      *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
                      *(int *)(param_1 + 0x17c));
            nv_printf(4,"NVRM: has it and is not sharing it.\n");
            nv_printf(4,"NVRM: You may want to verify that no audio driver");
            nv_printf(4," is using the IRQ.\n");
          }
          bVar2 = false;
          bVar3 = true;
          nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: request_irq() failed (%d)\n",
                    *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),iVar7);
          uVar8 = *(uint *)(param_1 + 0x10);
          bVar4 = false;
          iVar6 = iVar7;
          goto LAB_00106419;
        }
        if ((*(byte *)(param_1 + 0x11) & 8) != 0) goto LAB_00106501;
        iVar7 = os_alloc_mutex(lVar1 + 2000);
        if (iVar7 == 0) {
          nv_kthread_q_item_init(lVar1 + 0x7b0,nvidia_isr_bh_unlocked,param_1);
          iVar7 = nv_kthread_q_init(lVar1 + 0x768,nv_device_name);
          if (iVar7 != 0) goto LAB_001067f7;
          iVar7 = nv_kthread_q_init(lVar1 + 0x820,"nv_queue");
          if (iVar7 != 0) {
            bVar4 = false;
            bVar2 = true;
            iVar6 = iVar7;
            goto LAB_00106801;
          }
          bVar2 = true;
          *(long *)(param_1 + 0x2f0) = lVar1 + 0x820;
          bVar4 = false;
          if (*(char *)(lVar1 + 0x4a8) != '\0') {
            iVar7 = nv_kthread_q_init(lVar1 + 0x458,"nv_remove_numa_memory");
            if (iVar7 != 0) {
              bVar4 = false;
              iVar6 = iVar7;
              goto LAB_00106801;
            }
            bVar4 = true;
          }
          goto LAB_00106508;
        }
LAB_001067f7:
        bVar4 = false;
        bVar2 = false;
        iVar6 = iVar7;
        goto LAB_00106801;
      }
      if ((uVar8 & 0x40) != 0) goto LAB_00106896;
      iVar7 = *(int *)(param_1 + 0x17c);
      if (iVar7 != 0) {
        if ((uVar8 & 0x800) == 0) {
          if ((uVar8 & 0x10) == 0) goto LAB_001066c4;
          goto LAB_001068a7;
        }
        goto LAB_00106501;
      }
      if ((uVar8 & 0x10) != 0) {
        if ((uVar8 & 0x800) == 0) goto LAB_001068a7;
        goto LAB_00106501;
      }
LAB_001063bb:
      bVar2 = false;
      bVar3 = true;
      nv_printf(4,
                "NVRM: GPU %04x:%02x:%02x.%x: No interrupts of any type are available. Cannot use this GPU.\n"
                ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
      uVar8 = *(uint *)(param_1 + 0x10);
      bVar4 = false;
      iVar6 = -5;
      goto LAB_00106419;
    }
LAB_00106395:
    if (((((uVar8 & 0x20) == 0) && ((uVar8 & 0x40) == 0)) && (*(int *)(param_1 + 0x17c) == 0)) &&
       ((uVar8 & 0x10) == 0)) goto LAB_001063bb;
LAB_00106501:
    bVar4 = false;
    bVar2 = false;
LAB_00106508:
    cVar5 = rm_init_adapter(param_2,param_1);
    if (cVar5 != '\0') {
      rm_get_gpu_uuid_raw(param_2,param_1);
      uVar8 = *(uint *)(param_1 + 0x10);
      if ((uVar8 & 0x800) == 0) {
        nv_acpi_register_notifier(lVar1);
        uVar8 = *(uint *)(param_1 + 0x10);
      }
      *(uint *)(param_1 + 0x10) = uVar8 | 1;
      rm_request_dnotifier_state(param_2,param_1);
      rm_unref_dynamic_power(param_2,param_1,2);
      goto LAB_001062ec;
    }
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: rm_init_adapter failed, device minor number %d\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
              *(undefined4 *)(lVar1 + 0x750));
    iVar6 = -5;
LAB_00106801:
    uVar8 = *(uint *)(param_1 + 0x10);
    if ((uVar8 & 0x800) != 0) {
      bVar3 = true;
      goto LAB_00106419;
    }
    if ((uVar8 & 0x40) == 0) {
      if ((uVar8 & 0x10) == 0) {
        bVar3 = true;
        free_irq(*(undefined4 *)(param_1 + 0x17c),lVar1);
        uVar8 = *(uint *)(param_1 + 0x10);
      }
      else {
LAB_0010681e:
        bVar3 = true;
        nv_soc_free_irqs(param_1);
        uVar8 = *(uint *)(param_1 + 0x10);
      }
      goto LAB_00106419;
    }
    if ((uVar8 & 0x10) != 0) goto LAB_0010681e;
    uVar10 = 0;
    if (*(int *)(lVar1 + 0x7dc) != 0) {
      do {
        free_irq(*(undefined4 *)(*(long *)(lVar1 + 0x7f0) + (long)(int)uVar10 * 8),lVar1);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(lVar1 + 0x7dc));
      uVar8 = *(uint *)(param_1 + 0x10);
      bVar3 = true;
      goto LAB_00106419;
    }
    bVar3 = true;
    if ((uVar8 & 0x20) == 0) goto LAB_00106622;
LAB_001065a7:
    *(uint *)(param_1 + 0x10) = uVar8 & 0xffffffdf;
    pci_disable_msi(*(undefined8 *)(lVar1 + 0x3b8));
    lVar13 = *(long *)(lVar1 + 0x5198);
    if (lVar13 != 0) {
LAB_001065c9:
      kfree(lVar13);
    }
  }
  else {
    if (nv_ctl_device._2040_8_ != 0) {
      *(undefined8 *)(lVar1 + 0x7f8) = nv_ctl_device._2040_8_;
      goto LAB_00106355;
    }
    nv_printf(4,"NVRM: numa memblock size of zero found during device start");
LAB_00106406:
    bVar4 = false;
    uVar8 = *(uint *)(param_1 + 0x10);
    bVar3 = false;
    bVar2 = false;
    iVar6 = -0x16;
LAB_00106419:
    if ((uVar8 & 0x20) != 0) goto LAB_001065a7;
    if ((uVar8 & 0x40) != 0) {
LAB_00106622:
      *(uint *)(param_1 + 0x10) = uVar8 & 0xffffffbf;
      pci_disable_msix(*(undefined8 *)(lVar1 + 0x3b8));
      kfree(*(undefined8 *)(lVar1 + 0x5198));
      lVar13 = *(long *)(lVar1 + 0x7f0);
      goto LAB_001065c9;
    }
  }
  if (*(long *)(lVar1 + 0x7e8) != 0) {
    os_free_mutex();
    *(undefined8 *)(lVar1 + 0x7e8) = 0;
  }
  if (*(long *)(param_1 + 0x2f0) == 0) {
LAB_00106579:
    if (bVar2) {
      if ((*(byte *)(param_1 + 0x11) & 8) != 0) goto LAB_0010647a;
      nv_kthread_q_stop(lVar1 + 0x768);
    }
LAB_00106462:
    if ((bVar4) && ((*(byte *)(param_1 + 0x11) & 8) == 0)) {
      nv_kthread_q_stop(lVar1 + 0x458);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
      *(undefined8 *)(param_1 + 0x2f0) = 0;
      nv_kthread_q_stop(lVar1 + 0x820);
      goto LAB_00106579;
    }
    if (!bVar2) goto LAB_00106462;
  }
LAB_0010647a:
  if (*(long *)(lVar1 + 2000) != 0) {
    os_free_mutex();
    *(undefined8 *)(lVar1 + 2000) = 0;
  }
  uVar8 = *(uint *)(param_1 + 0x10);
  if ((uVar8 & 0x400) != 0) {
    if (*(long *)(lVar1 + 0x3b8) != 0) {
      nv_printf(0,"NVRM: Trigger FLR on Failure!\n");
      os_pci_trigger_flr(*(undefined8 *)(lVar1 + 0x3b8));
      uVar8 = *(uint *)(param_1 + 0x10);
    }
    *(uint *)(param_1 + 0x10) = uVar8 & 0xfffffbff;
  }
  nv_dev_free_stacks(lVar1);
  if (bVar3) {
    rm_unref_dynamic_power(param_2,param_1,1);
  }
  nv_put_rsync_info();
LAB_001062ec:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00106ac0 __pfx_nv_open_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106c2d) */
/* WARNING: Removing unreachable block (ram,0x00106bae) */
/* WARNING: Removing unreachable block (ram,0x00106c1a) */

int __pfx_nv_open_device(long param_1,undefined8 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) {
    lVar5 = rm_get_gpu_uuid(param_2,param_1);
    if (lVar5 == 0) {
      nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: open() not permitted for excluded %s\n",
                *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),&DAT_00daeb57);
    }
    else {
      nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: open() not permitted for excluded %s\n",
                *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),lVar5);
      os_free_mem(lVar5);
    }
    return -1;
  }
  lVar5 = *(long *)(param_1 + 8);
  cVar2 = os_is_vgx_hyper();
  if ((cVar2 == '\0') || ((*(byte *)(param_1 + 0x11) & 0x40) == 0)) {
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Opening GPU with minor number %d\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
              *(undefined4 *)(lVar5 + 0x750));
    if ((*(uint *)(param_1 + 0x10) & 0x8000) == 0) {
      if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
        if (*(char *)(lVar5 + 0x5290) != '\0') {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        if (*(long *)(lVar5 + 0x3a0) != 0) {
          nv_printf(4,
                    "NVRM: GPU %04x:%02x:%02x.%x: Minor device %u is referenced without being open!\n"
                    ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
                    *(undefined4 *)(lVar5 + 0x750));
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        iVar3 = nv_start_device(param_1,param_2);
        if (iVar3 != 0) {
          return iVar3;
        }
      }
      else {
        cVar2 = rm_is_device_sequestered(param_2,param_1);
        if (cVar2 != '\0') {
          nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Device is currently unavailable\n",
                    *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
          return -0x10;
        }
      }
      lVar4 = rm_get_gpu_uuid(param_2,param_1);
      if (lVar4 == 0) {
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Unable to read UUID",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
      }
      else {
        cVar2 = nv_is_uuid_in_gpu_exclusion_list(lVar4);
        if (cVar2 != '\0') {
          nv_printf(3,
                    "NVRM: GPU %04x:%02x:%02x.%x: Could not exclude GPU %s because PBI is not supported\n"
                    ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),lVar4);
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        os_free_mem(lVar4);
      }
      LOCK();
      *(long *)(lVar5 + 0x3a0) = *(long *)(lVar5 + 0x3a0) + 1;
      UNLOCK();
      return 0;
    }
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Device in removal process\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  else {
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Open failed as GPU is locked for unbind operation\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  return -0x13;
}


// ===== 00106ad0 nv_open_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106c2d) */
/* WARNING: Removing unreachable block (ram,0x00106bae) */
/* WARNING: Removing unreachable block (ram,0x00106c1a) */

int nv_open_device(long param_1,undefined8 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) {
    lVar5 = rm_get_gpu_uuid(param_2,param_1);
    if (lVar5 == 0) {
      nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: open() not permitted for excluded %s\n",
                *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),&DAT_00daeb57);
    }
    else {
      nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: open() not permitted for excluded %s\n",
                *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),lVar5);
      os_free_mem(lVar5);
    }
    return -1;
  }
  lVar5 = *(long *)(param_1 + 8);
  cVar2 = os_is_vgx_hyper();
  if ((cVar2 == '\0') || ((*(byte *)(param_1 + 0x11) & 0x40) == 0)) {
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Opening GPU with minor number %d\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
              *(undefined4 *)(lVar5 + 0x750));
    if ((*(uint *)(param_1 + 0x10) & 0x8000) == 0) {
      if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
        if (*(char *)(lVar5 + 0x5290) != '\0') {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        if (*(long *)(lVar5 + 0x3a0) != 0) {
          nv_printf(4,
                    "NVRM: GPU %04x:%02x:%02x.%x: Minor device %u is referenced without being open!\n"
                    ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),
                    *(undefined4 *)(lVar5 + 0x750));
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        iVar3 = nv_start_device(param_1,param_2);
        if (iVar3 != 0) {
          return iVar3;
        }
      }
      else {
        cVar2 = rm_is_device_sequestered(param_2,param_1);
        if (cVar2 != '\0') {
          nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Device is currently unavailable\n",
                    *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
          return -0x10;
        }
      }
      lVar4 = rm_get_gpu_uuid(param_2,param_1);
      if (lVar4 == 0) {
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Unable to read UUID",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
      }
      else {
        cVar2 = nv_is_uuid_in_gpu_exclusion_list(lVar4);
        if (cVar2 != '\0') {
          nv_printf(3,
                    "NVRM: GPU %04x:%02x:%02x.%x: Could not exclude GPU %s because PBI is not supported\n"
                    ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                    *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),lVar4);
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        os_free_mem(lVar4);
      }
      LOCK();
      *(long *)(lVar5 + 0x3a0) = *(long *)(lVar5 + 0x3a0) + 1;
      UNLOCK();
      return 0;
    }
    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Device in removal process\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  else {
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Open failed as GPU is locked for unbind operation\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  return -0x13;
}


// ===== 00106d30 __pfx_nvidia_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106e71) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nvidia_open(long param_1,long param_2)

{
  long lVar1;
  ulong *puVar2;
  long lVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  undefined4 *puVar10;
  long lVar11;
  long in_GS_OFFSET;
  bool bVar12;
  
  nv_printf(0,"NVRM: nvidia_open...\n");
  lVar9 = __kmalloc_cache_noprof(_devm_clk_bulk_get_all,0x2dc0,0x210);
  if (lVar9 == 0) {
    nv_printf(4,"NVRM: failed to allocate file private!\n");
LAB_001071ac:
    iVar7 = -0xc;
  }
  else {
    __init_waitqueue_head(lVar9 + 0xa0,"&nvlfp->waitqueue",&persistence_mode_notice_logged_5);
    *(undefined4 *)(lVar9 + 0x9c) = 0;
    __init_rwsem(lVar9 + 0x188,"&nvlfp->fileVaLock",&persistence_mode_notice_logged_5);
    *(undefined8 *)(lVar9 + 0x1a8) = 0;
    cVar6 = rm_is_altstack_in_use();
    puVar10 = (undefined4 *)0x0;
    if (cVar6 != '\0') {
      puVar10 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar10 == (undefined4 *)0x0) {
        nv_free_file_private(lVar9);
        goto LAB_001071ac;
      }
      *puVar10 = 0x2ff0;
      *(undefined4 **)(puVar10 + 2) = puVar10 + 0xc00;
    }
    *(long *)(param_2 + 0x18) = lVar9;
    puVar2 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    *(undefined4 **)(lVar9 + 0x70) = puVar10;
    if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == 0xff) {
      nv_printf(0,"NVRM: nvidia_ctl_open\n");
      down(0x52b290);
      bVar12 = nv_ctl_device._928_8_ == 0;
      *(undefined1 **)(lVar9 + 0x80) = nv_ctl_device;
      if (bVar12) {
        nv_ctl_device._16_4_ = nv_ctl_device._16_4_ | 5;
      }
      LOCK();
      nv_ctl_device._928_8_ = nv_ctl_device._928_8_ + 1;
      UNLOCK();
      up(0x52b290);
LAB_0010703e:
      iVar7 = 0;
    }
    else {
      while (iVar7 = down_read_trylock(nv_system_pm_lock), iVar7 == 0) {
        if (((*puVar2 & 4) != 0) || ((*puVar2 & 2) != 0)) {
          iVar7 = -4;
          goto LAB_00106e45;
        }
        __SCT__cond_resched();
      }
      *(undefined8 *)(lVar9 + 0x80) = 0;
      *(undefined4 *)(lVar9 + 0x1d0) = 0;
      __init_swait_queue_head(lVar9 + 0x1d8,"&x->wait",&persistence_mode_notice_logged_5);
      down(nv_linux_devices_lock);
      if (nv_linux_devices != 0) {
        lVar11 = nv_linux_devices;
        do {
          if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == *(uint *)(lVar11 + 0x750)) {
            lVar1 = lVar11 + 0x730;
            address_space_init_once(lVar9 + 0xe8);
            lVar3 = *(long *)(param_1 + 0x30);
            *(long *)(lVar9 + 0xe8) = param_1;
            uVar4 = *(undefined8 *)(lVar3 + 0x68);
            *(long *)(param_2 + 0x10) = lVar9 + 0xe8;
            iVar7 = NVreg_EnableNonblockingOpen;
            *(undefined8 *)(lVar9 + 0x150) = uVar4;
            if ((iVar7 == 0) || ((*(byte *)(param_2 + 0x29) & 8) == 0)) {
              down(lVar1);
LAB_00106f59:
              up(nv_linux_devices_lock);
              uVar4 = *(undefined8 *)(lVar9 + 0x70);
              iVar7 = nv_open_device(lVar11,uVar4);
              *(int *)(lVar9 + 0x1f8) = iVar7;
              if (iVar7 == 0) {
                *(undefined4 *)(lVar9 + 0x1fc) = 0;
              }
              else {
                uVar8 = rm_get_adapter_status_external(uVar4,lVar11);
                iVar7 = *(int *)(lVar9 + 0x1f8);
                *(undefined4 *)(lVar9 + 0x1fc) = uVar8;
                if (iVar7 != 0) {
                  up(lVar1);
                  complete_all(lVar9 + 0x1d0);
                  up_read(nv_system_pm_lock);
                  goto LAB_00106e45;
                }
              }
              nv_add_open_file(lVar11,lVar9);
              up(lVar1);
              complete_all(lVar9 + 0x1d0);
              up_read(nv_system_pm_lock);
              goto LAB_0010703e;
            }
            iVar7 = down_trylock(lVar1);
            if (iVar7 == 0) {
              if ((*(byte *)(lVar11 + 0x10) & 1) != 0) goto LAB_00106f59;
              up(lVar1);
            }
            lVar1 = lVar11 + 0x5228;
            down(lVar1);
            if (*(char *)(lVar11 + 0x5220) == '\0') {
              iVar7 = -0x10;
              up(lVar1);
              up(nv_linux_devices_lock);
              up_read(nv_system_pm_lock);
              goto LAB_00106e45;
            }
            *(long *)(lVar9 + 0x1f0) = lVar11;
            nv_kthread_q_item_init(lVar9 + 0x1b0,nvidia_open_deferred,lVar9);
            iVar7 = nv_kthread_q_schedule_q_item(lVar11 + 0x51d8,lVar9 + 0x1b0);
            if (iVar7 == 0) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)invalidInstructionException();
              (*pcVar5)();
            }
            up(lVar1);
            up(nv_linux_devices_lock);
            up_read(nv_system_pm_lock);
            goto LAB_0010703e;
          }
          lVar11 = *(long *)(lVar11 + 0x758);
        } while (lVar11 != 0);
      }
      iVar7 = -0x13;
      up(nv_linux_devices_lock);
      up_read(nv_system_pm_lock);
LAB_00106e45:
      nv_free_file_private(lVar9);
      *(undefined8 *)(param_2 + 0x18) = 0;
    }
  }
  return iVar7;
}


// ===== 00106d40 nvidia_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00106e71) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvidia_open(long param_1,long param_2)

{
  long lVar1;
  ulong *puVar2;
  long lVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  undefined4 *puVar10;
  long lVar11;
  long in_GS_OFFSET;
  bool bVar12;
  
  nv_printf(0,"NVRM: nvidia_open...\n");
  lVar9 = __kmalloc_cache_noprof(_devm_clk_bulk_get_all,0x2dc0,0x210);
  if (lVar9 == 0) {
    nv_printf(4,"NVRM: failed to allocate file private!\n");
LAB_001071ac:
    iVar7 = -0xc;
  }
  else {
    __init_waitqueue_head(lVar9 + 0xa0,"&nvlfp->waitqueue",&persistence_mode_notice_logged_5);
    *(undefined4 *)(lVar9 + 0x9c) = 0;
    __init_rwsem(lVar9 + 0x188,"&nvlfp->fileVaLock",&persistence_mode_notice_logged_5);
    *(undefined8 *)(lVar9 + 0x1a8) = 0;
    cVar6 = rm_is_altstack_in_use();
    puVar10 = (undefined4 *)0x0;
    if (cVar6 != '\0') {
      puVar10 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar10 == (undefined4 *)0x0) {
        nv_free_file_private(lVar9);
        goto LAB_001071ac;
      }
      *puVar10 = 0x2ff0;
      *(undefined4 **)(puVar10 + 2) = puVar10 + 0xc00;
    }
    *(long *)(param_2 + 0x18) = lVar9;
    puVar2 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    *(undefined4 **)(lVar9 + 0x70) = puVar10;
    if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == 0xff) {
      nv_printf(0,"NVRM: nvidia_ctl_open\n");
      down(0x52b290);
      bVar12 = nv_ctl_device._928_8_ == 0;
      *(undefined1 **)(lVar9 + 0x80) = nv_ctl_device;
      if (bVar12) {
        nv_ctl_device._16_4_ = nv_ctl_device._16_4_ | 5;
      }
      LOCK();
      nv_ctl_device._928_8_ = nv_ctl_device._928_8_ + 1;
      UNLOCK();
      up(0x52b290);
LAB_0010703e:
      iVar7 = 0;
    }
    else {
      while (iVar7 = down_read_trylock(nv_system_pm_lock), iVar7 == 0) {
        if (((*puVar2 & 4) != 0) || ((*puVar2 & 2) != 0)) {
          iVar7 = -4;
          goto LAB_00106e45;
        }
        __SCT__cond_resched();
      }
      *(undefined8 *)(lVar9 + 0x80) = 0;
      *(undefined4 *)(lVar9 + 0x1d0) = 0;
      __init_swait_queue_head(lVar9 + 0x1d8,"&x->wait",&persistence_mode_notice_logged_5);
      down(nv_linux_devices_lock);
      if (nv_linux_devices != 0) {
        lVar11 = nv_linux_devices;
        do {
          if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == *(uint *)(lVar11 + 0x750)) {
            lVar1 = lVar11 + 0x730;
            address_space_init_once(lVar9 + 0xe8);
            lVar3 = *(long *)(param_1 + 0x30);
            *(long *)(lVar9 + 0xe8) = param_1;
            uVar4 = *(undefined8 *)(lVar3 + 0x68);
            *(long *)(param_2 + 0x10) = lVar9 + 0xe8;
            iVar7 = NVreg_EnableNonblockingOpen;
            *(undefined8 *)(lVar9 + 0x150) = uVar4;
            if ((iVar7 == 0) || ((*(byte *)(param_2 + 0x29) & 8) == 0)) {
              down(lVar1);
LAB_00106f59:
              up(nv_linux_devices_lock);
              uVar4 = *(undefined8 *)(lVar9 + 0x70);
              iVar7 = nv_open_device(lVar11,uVar4);
              *(int *)(lVar9 + 0x1f8) = iVar7;
              if (iVar7 == 0) {
                *(undefined4 *)(lVar9 + 0x1fc) = 0;
              }
              else {
                uVar8 = rm_get_adapter_status_external(uVar4,lVar11);
                iVar7 = *(int *)(lVar9 + 0x1f8);
                *(undefined4 *)(lVar9 + 0x1fc) = uVar8;
                if (iVar7 != 0) {
                  up(lVar1);
                  complete_all(lVar9 + 0x1d0);
                  up_read(nv_system_pm_lock);
                  goto LAB_00106e45;
                }
              }
              nv_add_open_file(lVar11,lVar9);
              up(lVar1);
              complete_all(lVar9 + 0x1d0);
              up_read(nv_system_pm_lock);
              goto LAB_0010703e;
            }
            iVar7 = down_trylock(lVar1);
            if (iVar7 == 0) {
              if ((*(byte *)(lVar11 + 0x10) & 1) != 0) goto LAB_00106f59;
              up(lVar1);
            }
            lVar1 = lVar11 + 0x5228;
            down(lVar1);
            if (*(char *)(lVar11 + 0x5220) == '\0') {
              iVar7 = -0x10;
              up(lVar1);
              up(nv_linux_devices_lock);
              up_read(nv_system_pm_lock);
              goto LAB_00106e45;
            }
            *(long *)(lVar9 + 0x1f0) = lVar11;
            nv_kthread_q_item_init(lVar9 + 0x1b0,nvidia_open_deferred,lVar9);
            iVar7 = nv_kthread_q_schedule_q_item(lVar11 + 0x51d8,lVar9 + 0x1b0);
            if (iVar7 == 0) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)invalidInstructionException();
              (*pcVar5)();
            }
            up(lVar1);
            up(nv_linux_devices_lock);
            up_read(nv_system_pm_lock);
            goto LAB_0010703e;
          }
          lVar11 = *(long *)(lVar11 + 0x758);
        } while (lVar11 != 0);
      }
      iVar7 = -0x13;
      up(nv_linux_devices_lock);
      up_read(nv_system_pm_lock);
LAB_00106e45:
      nv_free_file_private(lVar9);
      *(undefined8 *)(param_2 + 0x18) = 0;
    }
  }
  return iVar7;
}


// ===== 001071d0 __pfx_nvidia_open_deferred =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvidia_open_deferred(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  lVar1 = *(long *)(param_1 + 0x1f0);
  down(lVar1 + 0x730);
  uVar2 = *(undefined8 *)(param_1 + 0x70);
  iVar3 = nv_open_device(lVar1,uVar2);
  *(int *)(param_1 + 0x1f8) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
  }
  else {
    uVar4 = rm_get_adapter_status_external(uVar2,lVar1);
    *(undefined4 *)(param_1 + 0x1fc) = uVar4;
    if (*(int *)(param_1 + 0x1f8) != 0) goto LAB_0010723f;
  }
  nv_add_open_file(lVar1,param_1);
LAB_0010723f:
  up(lVar1 + 0x730);
  complete_all(param_1 + 0x1d0);
  return;
}


// ===== 001071e0 nvidia_open_deferred =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvidia_open_deferred(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  lVar1 = *(long *)(param_1 + 0x1f0);
  down(lVar1 + 0x730);
  uVar2 = *(undefined8 *)(param_1 + 0x70);
  iVar3 = nv_open_device(lVar1,uVar2);
  *(int *)(param_1 + 0x1f8) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
  }
  else {
    uVar4 = rm_get_adapter_status_external(uVar2,lVar1);
    *(undefined4 *)(param_1 + 0x1fc) = uVar4;
    if (*(int *)(param_1 + 0x1f8) != 0) goto LAB_0010723f;
  }
  nv_add_open_file(lVar1,param_1);
LAB_0010723f:
  up(lVar1 + 0x730);
  complete_all(param_1 + 0x1d0);
  return;
}


// ===== 00107290 __pfx_nv_shutdown_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001073ef) */

void __pfx_nv_shutdown_adapter(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  
  rm_disable_adapter();
  nv_kthread_q_stop(param_3 + 0x768);
  if (*(long *)(param_2 + 0x2f0) != 0) {
    *(undefined8 *)(param_2 + 0x2f0) = 0;
    nv_kthread_q_stop(param_3 + 0x820);
  }
  if (*(long *)(param_3 + 2000) != 0) {
    os_free_mutex();
    *(undefined8 *)(param_3 + 2000) = 0;
  }
  uVar2 = *(uint *)(param_2 + 0x10) & 0x10;
  if ((*(uint *)(param_2 + 0x10) & 0x40) == 0) {
    if (uVar2 == 0) {
      free_irq(*(undefined4 *)(param_2 + 0x17c),param_3);
      if ((*(byte *)(param_2 + 0x10) & 0x20) == 0) goto LAB_00107380;
      pci_disable_msi(*(undefined8 *)(param_3 + 0x3b8));
      lVar1 = *(long *)(param_3 + 0x5198);
      if (lVar1 == 0) goto LAB_00107380;
LAB_0010737b:
      kfree(lVar1);
      goto LAB_00107380;
    }
  }
  else if (uVar2 == 0) {
    uVar2 = 0;
    if (*(int *)(param_3 + 0x7dc) != 0) {
      do {
        lVar1 = (long)(int)uVar2;
        uVar2 = uVar2 + 1;
        free_irq(*(undefined4 *)(*(long *)(param_3 + 0x7f0) + lVar1 * 8),param_3);
      } while (uVar2 < *(uint *)(param_3 + 0x7dc));
    }
    pci_disable_msix(*(undefined8 *)(param_3 + 0x3b8));
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffbf;
    kfree(*(undefined8 *)(param_3 + 0x7f0));
    lVar1 = *(long *)(param_3 + 0x5198);
    goto LAB_0010737b;
  }
  nv_soc_free_irqs(param_2);
LAB_00107380:
  if (*(long *)(param_3 + 0x7e8) != 0) {
    os_free_mutex();
    *(undefined8 *)(param_3 + 0x7e8) = 0;
  }
  rm_shutdown_adapter(param_1,param_2);
  if ((*(byte *)(param_2 + 0x11) & 4) != 0) {
    if (*(long *)(param_3 + 0x3b8) == 0) {
      nv_printf(4,"NVRM: FLR not supported by the device!\n");
    }
    else {
      nv_printf(0,"NVRM: Trigger FLR!\n");
      os_pci_trigger_flr(*(undefined8 *)(param_3 + 0x3b8));
    }
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xfffffbff;
  }
  if (*(char *)(param_3 + 0x4a8) != '\0') {
    nv_kthread_q_stop(param_3 + 0x458);
    return;
  }
  return;
}


// ===== 001072a0 nv_shutdown_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001073ef) */

void nv_shutdown_adapter(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  
  rm_disable_adapter();
  nv_kthread_q_stop(param_3 + 0x768);
  if (*(long *)(param_2 + 0x2f0) != 0) {
    *(undefined8 *)(param_2 + 0x2f0) = 0;
    nv_kthread_q_stop(param_3 + 0x820);
  }
  if (*(long *)(param_3 + 2000) != 0) {
    os_free_mutex();
    *(undefined8 *)(param_3 + 2000) = 0;
  }
  uVar2 = *(uint *)(param_2 + 0x10) & 0x10;
  if ((*(uint *)(param_2 + 0x10) & 0x40) == 0) {
    if (uVar2 == 0) {
      free_irq(*(undefined4 *)(param_2 + 0x17c),param_3);
      if ((*(byte *)(param_2 + 0x10) & 0x20) == 0) goto LAB_00107380;
      pci_disable_msi(*(undefined8 *)(param_3 + 0x3b8));
      lVar1 = *(long *)(param_3 + 0x5198);
      if (lVar1 == 0) goto LAB_00107380;
LAB_0010737b:
      kfree(lVar1);
      goto LAB_00107380;
    }
  }
  else if (uVar2 == 0) {
    uVar2 = 0;
    if (*(int *)(param_3 + 0x7dc) != 0) {
      do {
        lVar1 = (long)(int)uVar2;
        uVar2 = uVar2 + 1;
        free_irq(*(undefined4 *)(*(long *)(param_3 + 0x7f0) + lVar1 * 8),param_3);
      } while (uVar2 < *(uint *)(param_3 + 0x7dc));
    }
    pci_disable_msix(*(undefined8 *)(param_3 + 0x3b8));
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffbf;
    kfree(*(undefined8 *)(param_3 + 0x7f0));
    lVar1 = *(long *)(param_3 + 0x5198);
    goto LAB_0010737b;
  }
  nv_soc_free_irqs(param_2);
LAB_00107380:
  if (*(long *)(param_3 + 0x7e8) != 0) {
    os_free_mutex();
    *(undefined8 *)(param_3 + 0x7e8) = 0;
  }
  rm_shutdown_adapter(param_1,param_2);
  if ((*(byte *)(param_2 + 0x11) & 4) != 0) {
    if (*(long *)(param_3 + 0x3b8) == 0) {
      nv_printf(4,"NVRM: FLR not supported by the device!\n");
    }
    else {
      nv_printf(0,"NVRM: Trigger FLR!\n");
      os_pci_trigger_flr(*(undefined8 *)(param_3 + 0x3b8));
    }
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xfffffbff;
  }
  if (*(char *)(param_3 + 0x4a8) != '\0') {
    nv_kthread_q_stop(param_3 + 0x458);
    return;
  }
  return;
}


// ===== 00107460 __pfx_nv_stop_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_stop_device(long param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  rm_ref_dynamic_power(param_2,param_1,2);
  if (*(char *)(param_1 + 0x2fc) == '\0') {
    if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
      nv_acpi_unregister_notifier(uVar2);
      nv_shutdown_adapter(param_2,param_1,uVar2);
    }
    else {
      rm_disable_adapter(param_2,param_1);
    }
  }
  if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
    nv_dev_free_stacks(uVar2);
    if ((*(uint *)(param_1 + 0x10) & 0x800) == 0) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
      goto LAB_001074f4;
    }
  }
  if (persistence_mode_notice_logged_5 == 0) {
    cVar3 = os_is_vgx_hyper();
    if (cVar3 == '\0') {
      nv_printf(4,
                "NVRM: Persistence mode is deprecated and will be removed in a future release. Please use nvidia-persistenced instead.\n"
               );
      persistence_mode_notice_logged_5 = 1;
    }
    uVar1 = *(uint *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x10) = uVar1 & 0xfffffffe;
    if ((uVar1 & 0x800) == 0) {
LAB_001074f4:
      rm_unref_dynamic_power(param_2,param_1,1);
      nv_put_rsync_info();
      return;
    }
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  }
  rm_unref_dynamic_power(param_2,param_1,2);
  nv_put_rsync_info();
  return;
}


// ===== 00107470 nv_stop_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_stop_device(long param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  rm_ref_dynamic_power(param_2,param_1,2);
  if (*(char *)(param_1 + 0x2fc) == '\0') {
    if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
      nv_acpi_unregister_notifier(uVar2);
      nv_shutdown_adapter(param_2,param_1,uVar2);
    }
    else {
      rm_disable_adapter(param_2,param_1);
    }
  }
  if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
    nv_dev_free_stacks(uVar2);
    if ((*(uint *)(param_1 + 0x10) & 0x800) == 0) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
      goto LAB_001074f4;
    }
  }
  if (persistence_mode_notice_logged_5 == 0) {
    cVar3 = os_is_vgx_hyper();
    if (cVar3 == '\0') {
      nv_printf(4,
                "NVRM: Persistence mode is deprecated and will be removed in a future release. Please use nvidia-persistenced instead.\n"
               );
      persistence_mode_notice_logged_5 = 1;
    }
    uVar1 = *(uint *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x10) = uVar1 & 0xfffffffe;
    if ((uVar1 & 0x800) == 0) {
LAB_001074f4:
      rm_unref_dynamic_power(param_2,param_1,1);
      nv_put_rsync_info();
      return;
    }
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  }
  rm_unref_dynamic_power(param_2,param_1,2);
  nv_put_rsync_info();
  return;
}


// ===== 00107560 __pfx_nv_close_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107596) */

void __pfx_nv_close_device(long param_1)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(param_1 + 8);
  if (*(long *)(lVar2 + 0x3a0) == 0) {
    nv_printf(4,"NVRM: Attempting to close unopened minor device %u!\n",
              *(undefined4 *)(lVar2 + 0x750));
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  LOCK();
  plVar1 = (long *)(lVar2 + 0x3a0);
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if ((*plVar1 == 0) && (*(char *)(lVar2 + 0x5290) == '\0')) {
    nv_stop_device();
    return;
  }
  return;
}


// ===== 00107570 nv_close_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107596) */

void nv_close_device(long param_1)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(param_1 + 8);
  if (*(long *)(lVar2 + 0x3a0) == 0) {
    nv_printf(4,"NVRM: Attempting to close unopened minor device %u!\n",
              *(undefined4 *)(lVar2 + 0x750));
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  LOCK();
  plVar1 = (long *)(lVar2 + 0x3a0);
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if ((*plVar1 == 0) && (*(char *)(lVar2 + 0x5290) == '\0')) {
    nv_stop_device();
    return;
  }
  return;
}


// ===== 001075c0 __pfx_nvidia_close_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001076dc) */

void __pfx_nvidia_close_callback(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  char cVar5;
  
  lVar1 = *(long *)(param_1 + 0x80);
  lVar2 = *(long *)(param_1 + 0x70);
  if (lVar1 == 0) {
    nv_free_file_private();
    if (lVar2 == 0) {
      return;
    }
    cVar5 = rm_is_altstack_in_use();
    goto joined_r0x00107788;
  }
  rm_cleanup_file_private(lVar2,lVar1,param_1);
  down(lVar1 + 0x868);
  plVar3 = *(long **)(param_1 + 0x208);
  lVar4 = *(long *)(param_1 + 0x200);
  if ((param_1 + 0x200 == *plVar3) && (param_1 + 0x200 == *(long *)(lVar4 + 8))) {
    *(long **)(lVar4 + 8) = plVar3;
    *plVar3 = lVar4;
  }
  else {
    __list_del_entry_valid_or_report();
  }
  lVar4 = lVar1 + 0x730;
  *(undefined8 *)(param_1 + 0x200) = 0xdead000000000100;
  *(undefined8 *)(param_1 + 0x208) = 0xdead000000000122;
  up(lVar1 + 0x868);
  down(lVar4);
  nv_close_device(lVar1,lVar2);
  if ((((*(byte *)(lVar1 + 0x11) & 0x80) == 0) && (*(long *)(lVar1 + 0x3a0) == 0)) &&
     (cVar5 = rm_get_device_remove_flag(lVar2,*(undefined4 *)(lVar1 + 0x24)), cVar5 != '\0')) {
    nv_free_file_private(param_1);
    if ((*(long *)(lVar1 + 0x3a0) == 0) && (*(char *)(lVar1 + 0x2fc) != '\0')) {
LAB_0010772b:
      rm_destroy_event_locks(lVar2,lVar1);
      kfree(lVar1);
    }
    else {
      up(lVar4);
      pci_stop_and_remove_bus_device(*(undefined8 *)(lVar1 + 0x3b8));
    }
  }
  else {
    nv_free_file_private(param_1);
    if ((*(long *)(lVar1 + 0x3a0) == 0) && (*(char *)(lVar1 + 0x2fc) != '\0')) goto LAB_0010772b;
    up(lVar4);
  }
  if (lVar2 == 0) {
    return;
  }
  cVar5 = rm_is_altstack_in_use();
joined_r0x00107788:
  if (cVar5 == '\0') {
    return;
  }
  kmem_cache_free(nvidia_stack_t_cache,lVar2);
  return;
}


// ===== 001075d0 nvidia_close_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001076dc) */

void nvidia_close_callback(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  char cVar5;
  
  lVar1 = *(long *)(param_1 + 0x80);
  lVar2 = *(long *)(param_1 + 0x70);
  if (lVar1 == 0) {
    nv_free_file_private();
    if (lVar2 == 0) {
      return;
    }
    cVar5 = rm_is_altstack_in_use();
    goto joined_r0x00107788;
  }
  rm_cleanup_file_private(lVar2,lVar1,param_1);
  down(lVar1 + 0x868);
  plVar3 = *(long **)(param_1 + 0x208);
  lVar4 = *(long *)(param_1 + 0x200);
  if ((param_1 + 0x200 == *plVar3) && (param_1 + 0x200 == *(long *)(lVar4 + 8))) {
    *(long **)(lVar4 + 8) = plVar3;
    *plVar3 = lVar4;
  }
  else {
    __list_del_entry_valid_or_report();
  }
  lVar4 = lVar1 + 0x730;
  *(undefined8 *)(param_1 + 0x200) = 0xdead000000000100;
  *(undefined8 *)(param_1 + 0x208) = 0xdead000000000122;
  up(lVar1 + 0x868);
  down(lVar4);
  nv_close_device(lVar1,lVar2);
  if ((((*(byte *)(lVar1 + 0x11) & 0x80) == 0) && (*(long *)(lVar1 + 0x3a0) == 0)) &&
     (cVar5 = rm_get_device_remove_flag(lVar2,*(undefined4 *)(lVar1 + 0x24)), cVar5 != '\0')) {
    nv_free_file_private(param_1);
    if ((*(long *)(lVar1 + 0x3a0) == 0) && (*(char *)(lVar1 + 0x2fc) != '\0')) {
LAB_0010772b:
      rm_destroy_event_locks(lVar2,lVar1);
      kfree(lVar1);
    }
    else {
      up(lVar4);
      pci_stop_and_remove_bus_device(*(undefined8 *)(lVar1 + 0x3b8));
    }
  }
  else {
    nv_free_file_private(param_1);
    if ((*(long *)(lVar1 + 0x3a0) == 0) && (*(char *)(lVar1 + 0x2fc) != '\0')) goto LAB_0010772b;
    up(lVar4);
  }
  if (lVar2 == 0) {
    return;
  }
  cVar5 = rm_is_altstack_in_use();
joined_r0x00107788:
  if (cVar5 == '\0') {
    return;
  }
  kmem_cache_free(nvidia_stack_t_cache,lVar2);
  return;
}


// ===== 00107790 __pfx_nvidia_close_deferred =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvidia_close_deferred(long param_1)

{
  wait_for_completion(param_1 + 0x1d0);
  down_read(nv_system_pm_lock);
  nvidia_close_callback(param_1);
  up_read(nv_system_pm_lock);
  return;
}


// ===== 001077a0 nvidia_close_deferred =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvidia_close_deferred(long param_1)

{
  wait_for_completion(param_1 + 0x1d0);
  down_read(nv_system_pm_lock);
  nvidia_close_callback(param_1);
  up_read(nv_system_pm_lock);
  return;
}


// ===== 001077e0 __pfx_nvidia_isr_msix =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107831) */

undefined4 __pfx_nvidia_isr_msix(undefined4 param_1,long param_2)

{
  undefined4 uVar1;
  
  _raw_spin_lock(param_2 + 0x7e0);
  uVar1 = nvidia_isr(param_1,param_2);
  _raw_spin_unlock(param_2 + 0x7e0);
  return uVar1;
}


// ===== 001077f0 nvidia_isr_msix =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107831) */

undefined4 nvidia_isr_msix(undefined4 param_1,long param_2)

{
  undefined4 uVar1;
  
  _raw_spin_lock(param_2 + 0x7e0);
  uVar1 = nvidia_isr(param_1,param_2);
  _raw_spin_unlock(param_2 + 0x7e0);
  return uVar1;
}


// ===== 00107840 __pfx_nvidia_isr_msix_kthread_bh =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001078a6) */

undefined8 __pfx_nvidia_isr_msix_kthread_bh(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_2 + 8);
  iVar3 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x7e8));
  if (iVar3 == 0) {
    if ((*(byte *)(param_2 + 0x11) & 0x80) == 0) {
      rm_isr_bh(*(undefined8 *)(*(long *)(param_2 + 8) + 0x4c0));
    }
    else {
      nv_printf(0,"NVRM: GPU is lost, skipping ISR bottom half\n");
    }
    os_release_mutex(*(undefined8 *)(lVar1 + 0x7e8));
    return 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 00107850 nvidia_isr_msix_kthread_bh =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001078a6) */

undefined8 nvidia_isr_msix_kthread_bh(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_2 + 8);
  iVar3 = os_acquire_mutex(*(undefined8 *)(lVar1 + 0x7e8));
  if (iVar3 == 0) {
    if ((*(byte *)(param_2 + 0x11) & 0x80) == 0) {
      rm_isr_bh(*(undefined8 *)(*(long *)(param_2 + 8) + 0x4c0));
    }
    else {
      nv_printf(0,"NVRM: GPU is lost, skipping ISR bottom half\n");
    }
    os_release_mutex(*(undefined8 *)(lVar1 + 0x7e8));
    return 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 001078c0 __pfx_nv_set_dma_address_size =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001078fb) */

void __pfx_nv_set_dma_address_size(long param_1,byte param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 8);
  lVar1 = (1L << (param_2 & 0x3f)) + -1;
  *(long *)(lVar2 + 0x51b0) = lVar1;
  if (*(char *)(lVar2 + 0x7d8) != '\0') {
    return;
  }
  dma_set_mask(*(long *)(lVar2 + 0x3b8) + 0xd0);
  dma_set_coherent_mask(*(long *)(lVar2 + 0x3b8) + 0xd0,lVar1);
  return;
}


// ===== 001078d0 nv_set_dma_address_size =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001078fb) */

void nv_set_dma_address_size(long param_1,byte param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 8);
  lVar1 = (1L << (param_2 & 0x3f)) + -1;
  *(long *)(lVar2 + 0x51b0) = lVar1;
  if (*(char *)(lVar2 + 0x7d8) != '\0') {
    return;
  }
  dma_set_mask(*(long *)(lVar2 + 0x3b8) + 0xd0);
  dma_set_coherent_mask(*(long *)(lVar2 + 0x3b8) + 0xd0,lVar1);
  return;
}


// ===== 00107940 __pfx_nv_alias_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107a93) */
/* WARNING: Removing unreachable block (ram,0x00107aa9) */

undefined1  [16]
__pfx_nv_alias_pages
          (long param_1,undefined4 param_2,long param_3,int param_4,undefined4 param_5,
          undefined8 param_6,byte param_7,long *param_8)

{
  undefined1 auVar1 [16];
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  undefined1 auVar8 [16];
  long *unaff_retaddr;
  
  auVar8 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_2);
  lVar3 = auVar8._0_8_;
  if (lVar3 != 0) {
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    if (param_4 == 0) {
      uVar5 = param_3 - 1U >> 0xc;
      lVar4 = 0x3f;
      if (uVar5 != 0) {
        for (; uVar5 >> lVar4 == 0; lVar4 = lVar4 + -1) {
        }
      }
      iVar2 = (int)lVar4;
    }
    else {
      *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 1;
      uVar5 = (ulong)*(uint *)(lVar3 + 0x20) * 0x1000 - 1 >> 0xc;
      lVar4 = 0x3f;
      if (uVar5 != 0) {
        for (; uVar5 >> lVar4 == 0; lVar4 = lVar4 + -1) {
        }
      }
      iVar2 = (int)lVar4;
    }
    *(int *)(lVar3 + 0x24) = iVar2 + 1;
    *(ushort *)(lVar3 + 0x18) = (param_7 & 1) << 10 | 2 | *(ushort *)(lVar3 + 0x18) & 0xfbfd;
    if (*(uint *)(lVar3 + 0x20) != 0) {
      lVar4 = 0;
      do {
        plVar6 = (long *)(lVar4 * 0x10 + *(long *)(lVar3 + 0x30));
        if (((int)lVar4 == 0) || (param_4 == 0)) {
          lVar7 = unaff_retaddr[lVar4];
        }
        else {
          lVar7 = (ulong)(uint)((int)lVar4 << 0xc) + *unaff_retaddr;
        }
        *plVar6 = lVar7;
        lVar4 = lVar4 + 1;
        plVar6[1] = 0;
      } while ((uint)lVar4 < *(uint *)(lVar3 + 0x20));
    }
    *(undefined8 *)(lVar3 + 0x48) = param_6;
    *param_8 = lVar3;
    LOCK();
    *(long *)(lVar3 + 0x10) = *(long *)(lVar3 + 0x10) + 1;
    UNLOCK();
    uVar5 = *(ulong *)(lVar3 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_alias_pages",0xd3c,lVar3,*(undefined4 *)(lVar3 + 0x20),
              *(undefined8 *)(lVar3 + 0x10));
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar5;
    return auVar1 << 0x40;
  }
  auVar8._0_8_ = 0x51;
  return auVar8;
}


// ===== 00107950 nv_alias_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107a93) */
/* WARNING: Removing unreachable block (ram,0x00107aa9) */

undefined1  [16]
nv_alias_pages(long param_1,undefined4 param_2,long param_3,int param_4,undefined4 param_5,
              undefined8 param_6,byte param_7,long *param_8)

{
  undefined1 auVar1 [16];
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  undefined1 auVar8 [16];
  long *unaff_retaddr;
  
  auVar8 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_2);
  lVar3 = auVar8._0_8_;
  if (lVar3 != 0) {
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    if (param_4 == 0) {
      uVar5 = param_3 - 1U >> 0xc;
      lVar4 = 0x3f;
      if (uVar5 != 0) {
        for (; uVar5 >> lVar4 == 0; lVar4 = lVar4 + -1) {
        }
      }
      iVar2 = (int)lVar4;
    }
    else {
      *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 1;
      uVar5 = (ulong)*(uint *)(lVar3 + 0x20) * 0x1000 - 1 >> 0xc;
      lVar4 = 0x3f;
      if (uVar5 != 0) {
        for (; uVar5 >> lVar4 == 0; lVar4 = lVar4 + -1) {
        }
      }
      iVar2 = (int)lVar4;
    }
    *(int *)(lVar3 + 0x24) = iVar2 + 1;
    *(ushort *)(lVar3 + 0x18) = (param_7 & 1) << 10 | 2 | *(ushort *)(lVar3 + 0x18) & 0xfbfd;
    if (*(uint *)(lVar3 + 0x20) != 0) {
      lVar4 = 0;
      do {
        plVar6 = (long *)(lVar4 * 0x10 + *(long *)(lVar3 + 0x30));
        if (((int)lVar4 == 0) || (param_4 == 0)) {
          lVar7 = unaff_retaddr[lVar4];
        }
        else {
          lVar7 = (ulong)(uint)((int)lVar4 << 0xc) + *unaff_retaddr;
        }
        *plVar6 = lVar7;
        lVar4 = lVar4 + 1;
        plVar6[1] = 0;
      } while ((uint)lVar4 < *(uint *)(lVar3 + 0x20));
    }
    *(undefined8 *)(lVar3 + 0x48) = param_6;
    *param_8 = lVar3;
    LOCK();
    *(long *)(lVar3 + 0x10) = *(long *)(lVar3 + 0x10) + 1;
    UNLOCK();
    uVar5 = *(ulong *)(lVar3 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_alias_pages",0xd3c,lVar3,*(undefined4 *)(lVar3 + 0x20),
              *(undefined8 *)(lVar3 + 0x10));
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar5;
    return auVar1 << 0x40;
  }
  auVar8._0_8_ = 0x51;
  return auVar8;
}


// ===== 00107ab0 __pfx_nv_register_peer_io_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107b99) */
/* WARNING: Removing unreachable block (ram,0x00107ba7) */

undefined1  [16]
__pfx_nv_register_peer_io_mem(long param_1,long *param_2,long param_3,long *param_4)

{
  undefined1 auVar1 [16];
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined1 auVar7 [16];
  
  auVar7 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_3);
  lVar2 = auVar7._0_8_;
  if (lVar2 != 0) {
    *(byte *)(lVar2 + 0x18) = *(byte *)(lVar2 + 0x18) | 0x41;
    *(undefined4 *)(lVar2 + 0x1c) = 1;
    uVar3 = (ulong)*(uint *)(lVar2 + 0x20) * 0x1000 - 1 >> 0xc;
    lVar6 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar6 == 0; lVar6 = lVar6 + -1) {
      }
    }
    *(int *)(lVar2 + 0x24) = (int)lVar6 + 1;
    if (param_3 != 0) {
      lVar6 = *param_2;
      lVar4 = 0;
      do {
        lVar5 = lVar4 + 1;
        *(long *)(lVar4 * 0x10 + *(long *)(lVar2 + 0x30)) = lVar6;
        lVar6 = lVar6 + 0x1000;
        lVar4 = lVar5;
      } while (param_3 != lVar5);
    }
    *(undefined8 *)(lVar2 + 0x40) = 0;
    *param_4 = lVar2;
    uVar3 = *(ulong *)(lVar2 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_register_peer_io_mem",0xd6d,lVar2,*(undefined4 *)(lVar2 + 0x20),
              *(undefined8 *)(lVar2 + 0x10));
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    return auVar1 << 0x40;
  }
  auVar7._0_8_ = 0x51;
  return auVar7;
}


// ===== 00107ac0 nv_register_peer_io_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107b99) */
/* WARNING: Removing unreachable block (ram,0x00107ba7) */

undefined1  [16] nv_register_peer_io_mem(long param_1,long *param_2,long param_3,long *param_4)

{
  undefined1 auVar1 [16];
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined1 auVar7 [16];
  
  auVar7 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_3);
  lVar2 = auVar7._0_8_;
  if (lVar2 != 0) {
    *(byte *)(lVar2 + 0x18) = *(byte *)(lVar2 + 0x18) | 0x41;
    *(undefined4 *)(lVar2 + 0x1c) = 1;
    uVar3 = (ulong)*(uint *)(lVar2 + 0x20) * 0x1000 - 1 >> 0xc;
    lVar6 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar6 == 0; lVar6 = lVar6 + -1) {
      }
    }
    *(int *)(lVar2 + 0x24) = (int)lVar6 + 1;
    if (param_3 != 0) {
      lVar6 = *param_2;
      lVar4 = 0;
      do {
        lVar5 = lVar4 + 1;
        *(long *)(lVar4 * 0x10 + *(long *)(lVar2 + 0x30)) = lVar6;
        lVar6 = lVar6 + 0x1000;
        lVar4 = lVar5;
      } while (param_3 != lVar5);
    }
    *(undefined8 *)(lVar2 + 0x40) = 0;
    *param_4 = lVar2;
    uVar3 = *(ulong *)(lVar2 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_register_peer_io_mem",0xd6d,lVar2,*(undefined4 *)(lVar2 + 0x20),
              *(undefined8 *)(lVar2 + 0x10));
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    return auVar1 << 0x40;
  }
  auVar7._0_8_ = 0x51;
  return auVar7;
}


// ===== 00107bb0 __pfx_nv_unregister_peer_io_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107c03) */

undefined8 __pfx_nv_unregister_peer_io_mem(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_peer_io_mem",0xd79,param_2,*(undefined4 *)(param_2 + 0x20));
  if ((param_2 != 0) && (*(long *)(param_2 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(param_2 + 0x30));
    uVar1 = kfree(param_2);
    return uVar1;
  }
  return uVar1;
}


// ===== 00107bc0 nv_unregister_peer_io_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107c03) */

undefined8 nv_unregister_peer_io_mem(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_peer_io_mem",0xd79,param_2,*(undefined4 *)(param_2 + 0x20));
  if ((param_2 != 0) && (*(long *)(param_2 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(param_2 + 0x30));
    uVar1 = kfree(param_2);
    return uVar1;
  }
  return uVar1;
}


// ===== 00107c20 __pfx_nv_register_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107d77) */
/* WARNING: Removing unreachable block (ram,0x00107d98) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
__pfx_nv_register_user_pages
          (long param_1,long param_2,long param_3,long param_4,long *param_5,char param_6)

{
  long lVar1;
  undefined1 auVar2 [16];
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined1 auVar8 [16];
  
  nv_printf(0,"NVRM: VM: nv_register_user_pages: 0x%llx\n",param_2);
  lVar1 = *param_5;
  auVar8 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_2);
  lVar3 = auVar8._0_8_;
  if (lVar3 != 0) {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 0x10;
    *(undefined4 *)(lVar3 + 0x1c) = 1;
    if (param_6 != '\0') {
      *(byte *)(lVar3 + 0x19) = *(byte *)(lVar3 + 0x19) | 1;
    }
    uVar4 = (ulong)*(uint *)(lVar3 + 0x20) * 0x1000 - 1 >> 0xc;
    lVar7 = 0x3f;
    if (uVar4 != 0) {
      for (; uVar4 >> lVar7 == 0; lVar7 = lVar7 + -1) {
      }
    }
    *(int *)(lVar3 + 0x24) = (int)lVar7 + 1;
    if (param_2 != 0) {
      lVar7 = 0;
      do {
        lVar6 = lVar7 * 0x10;
        lVar5 = (*(long *)(lVar1 + lVar7 * 8) - _vmemmap_base >> 6) << 0xc;
        *(long *)(param_3 + lVar7 * 8) = lVar5;
        lVar7 = lVar7 + 1;
        *(long *)(lVar6 + *(long *)(lVar3 + 0x30)) = lVar5;
      } while (param_2 != lVar7);
    }
    *(long *)(lVar3 + 0x40) = lVar1;
    if (param_4 != 0) {
      *(long *)(lVar3 + 0x58) = param_4;
    }
    *param_5 = lVar3;
    uVar4 = *(ulong *)(lVar3 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_register_user_pages",0xdc1,lVar3,*(undefined4 *)(lVar3 + 0x20),
              *(undefined8 *)(lVar3 + 0x10));
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar4;
    return auVar2 << 0x40;
  }
  auVar8._0_8_ = 0x51;
  return auVar8;
}


// ===== 00107c30 nv_register_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107d77) */
/* WARNING: Removing unreachable block (ram,0x00107d98) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
nv_register_user_pages
          (long param_1,long param_2,long param_3,long param_4,long *param_5,char param_6)

{
  long lVar1;
  undefined1 auVar2 [16];
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined1 auVar8 [16];
  
  nv_printf(0,"NVRM: VM: nv_register_user_pages: 0x%llx\n",param_2);
  lVar1 = *param_5;
  auVar8 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_2);
  lVar3 = auVar8._0_8_;
  if (lVar3 != 0) {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 0x10;
    *(undefined4 *)(lVar3 + 0x1c) = 1;
    if (param_6 != '\0') {
      *(byte *)(lVar3 + 0x19) = *(byte *)(lVar3 + 0x19) | 1;
    }
    uVar4 = (ulong)*(uint *)(lVar3 + 0x20) * 0x1000 - 1 >> 0xc;
    lVar7 = 0x3f;
    if (uVar4 != 0) {
      for (; uVar4 >> lVar7 == 0; lVar7 = lVar7 + -1) {
      }
    }
    *(int *)(lVar3 + 0x24) = (int)lVar7 + 1;
    if (param_2 != 0) {
      lVar7 = 0;
      do {
        lVar6 = lVar7 * 0x10;
        lVar5 = (*(long *)(lVar1 + lVar7 * 8) - _vmemmap_base >> 6) << 0xc;
        *(long *)(param_3 + lVar7 * 8) = lVar5;
        lVar7 = lVar7 + 1;
        *(long *)(lVar6 + *(long *)(lVar3 + 0x30)) = lVar5;
      } while (param_2 != lVar7);
    }
    *(long *)(lVar3 + 0x40) = lVar1;
    if (param_4 != 0) {
      *(long *)(lVar3 + 0x58) = param_4;
    }
    *param_5 = lVar3;
    uVar4 = *(ulong *)(lVar3 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_register_user_pages",0xdc1,lVar3,*(undefined4 *)(lVar3 + 0x20),
              *(undefined8 *)(lVar3 + 0x10));
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar4;
    return auVar2 << 0x40;
  }
  auVar8._0_8_ = 0x51;
  return auVar8;
}


// ===== 00107da0 __pfx_nv_unregister_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107e2d) */

void __pfx_nv_unregister_user_pages
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,long *param_4)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = *param_4;
  nv_printf(0,"NVRM: VM: nv_unregister_user_pages: 0x%llx\n",param_2);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_user_pages",0xdd1,lVar1,*(undefined4 *)(lVar1 + 0x20),
            *(undefined8 *)(lVar1 + 0x10));
  if ((*(byte *)(lVar1 + 0x18) & 0x10) == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  *param_4 = *(long *)(lVar1 + 0x40);
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(lVar1 + 0x58);
  }
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(lVar1 + 0x30));
    kfree(lVar1);
    return;
  }
  return;
}


// ===== 00107db0 nv_unregister_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107e2d) */

void nv_unregister_user_pages
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,long *param_4)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = *param_4;
  nv_printf(0,"NVRM: VM: nv_unregister_user_pages: 0x%llx\n",param_2);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_user_pages",0xdd1,lVar1,*(undefined4 *)(lVar1 + 0x20),
            *(undefined8 *)(lVar1 + 0x10));
  if ((*(byte *)(lVar1 + 0x18) & 0x10) == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  *param_4 = *(long *)(lVar1 + 0x40);
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(lVar1 + 0x58);
  }
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(lVar1 + 0x30));
    kfree(lVar1);
    return;
  }
  return;
}


// ===== 00107e50 __pfx_nv_register_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107f38) */
/* WARNING: Removing unreachable block (ram,0x00107f48) */

undefined1  [16]
__pfx_nv_register_phys_pages
          (long param_1,long param_2,long param_3,undefined4 param_4,long *param_5)

{
  undefined1 auVar1 [16];
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  undefined1 auVar6 [16];
  
  auVar6 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_3);
  lVar2 = auVar6._0_8_;
  if (lVar2 != 0) {
    *(byte *)(lVar2 + 0x18) = *(byte *)(lVar2 + 0x18) | 0x80;
    *(undefined4 *)(lVar2 + 0x1c) = param_4;
    uVar3 = (ulong)*(uint *)(lVar2 + 0x20) * 0x1000 - 1 >> 0xc;
    lVar4 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar4 == 0; lVar4 = lVar4 + -1) {
      }
    }
    *(int *)(lVar2 + 0x24) = (int)lVar4 + 1;
    if (param_3 != 0) {
      lVar4 = 0;
      do {
        lVar5 = lVar4 + 1;
        *(undefined8 *)(lVar4 * 0x10 + *(long *)(lVar2 + 0x30)) =
             *(undefined8 *)(param_2 + lVar4 * 8);
        lVar4 = lVar5;
      } while (param_3 != lVar5);
    }
    *(undefined8 *)(lVar2 + 0x40) = 0;
    *param_5 = lVar2;
    uVar3 = *(ulong *)(lVar2 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_register_phys_pages",0xe0a,lVar2,*(undefined4 *)(lVar2 + 0x20),
              *(undefined8 *)(lVar2 + 0x10));
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    return auVar1 << 0x40;
  }
  auVar6._0_8_ = 0x51;
  return auVar6;
}


// ===== 00107e60 nv_register_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00107f38) */
/* WARNING: Removing unreachable block (ram,0x00107f48) */

undefined1  [16]
nv_register_phys_pages(long param_1,long param_2,long param_3,undefined4 param_4,long *param_5)

{
  undefined1 auVar1 [16];
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  undefined1 auVar6 [16];
  
  auVar6 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_3);
  lVar2 = auVar6._0_8_;
  if (lVar2 != 0) {
    *(byte *)(lVar2 + 0x18) = *(byte *)(lVar2 + 0x18) | 0x80;
    *(undefined4 *)(lVar2 + 0x1c) = param_4;
    uVar3 = (ulong)*(uint *)(lVar2 + 0x20) * 0x1000 - 1 >> 0xc;
    lVar4 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar4 == 0; lVar4 = lVar4 + -1) {
      }
    }
    *(int *)(lVar2 + 0x24) = (int)lVar4 + 1;
    if (param_3 != 0) {
      lVar4 = 0;
      do {
        lVar5 = lVar4 + 1;
        *(undefined8 *)(lVar4 * 0x10 + *(long *)(lVar2 + 0x30)) =
             *(undefined8 *)(param_2 + lVar4 * 8);
        lVar4 = lVar5;
      } while (param_3 != lVar5);
    }
    *(undefined8 *)(lVar2 + 0x40) = 0;
    *param_5 = lVar2;
    uVar3 = *(ulong *)(lVar2 + 0x30);
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_register_phys_pages",0xe0a,lVar2,*(undefined4 *)(lVar2 + 0x20),
              *(undefined8 *)(lVar2 + 0x10));
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    return auVar1 << 0x40;
  }
  auVar6._0_8_ = 0x51;
  return auVar6;
}


// ===== 00107f50 __pfx_nv_register_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010813f) */
/* WARNING: Removing unreachable block (ram,0x00108234) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
__pfx_nv_register_sgt
          (long param_1,long param_2,ulong param_3,undefined4 param_4,long *param_5,
          undefined8 *param_6,byte param_7)

{
  ulong *puVar1;
  long lVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  byte bVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  undefined1 auVar15 [16];
  long unaff_retaddr;
  
  auVar15 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_3);
  lVar6 = auVar15._0_8_;
  if (lVar6 == 0) {
    auVar15._0_8_ = 0x51;
    return auVar15;
  }
  puVar11 = (ulong *)*param_6;
  if ((*puVar11 < 4) || ((*(byte *)(param_1 + 0x10) & 0x10) != 0)) {
    if (*(int *)(param_6 + 1) != 0) {
      uVar13 = 0;
      uVar14 = 0;
      do {
        uVar8 = puVar11[3];
        if ((ulong)(uint)uVar8 != 0) {
          uVar7 = puVar11[2];
          uVar9 = 0;
          do {
            uVar10 = (ulong)uVar13;
            if (param_3 <= uVar10) break;
            lVar12 = uVar7 + uVar9;
            uVar9 = uVar9 + 0x1000;
            uVar13 = uVar13 + 1;
            *(long *)(param_2 + uVar10 * 8) = lVar12;
          } while (uVar9 < (uint)uVar8);
        }
        uVar14 = uVar14 + 1;
        if ((*puVar11 & 2) == 0) {
          puVar1 = puVar11 + 4;
          puVar11 = puVar11 + 4;
          if ((*puVar1 & 1) != 0) {
            puVar11 = (ulong *)(*puVar1 & 0xfffffffffffffffc);
          }
        }
        else {
          puVar11 = (ulong *)0x0;
        }
      } while (uVar14 < *(uint *)(param_6 + 1));
    }
  }
  else {
    uVar8 = 0;
    uVar13 = 0;
    if (*(int *)((long)param_6 + 0xc) == 0) {
      uVar8 = 0;
    }
    else {
      do {
        if ((int)puVar11[1] != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        uVar14 = *(uint *)((long)puVar11 + 0xc);
        uVar7 = *puVar11;
        if ((ulong)uVar14 != 0) {
          uVar9 = 0;
          lVar12 = (uVar7 & 0xfffffffffffffffc) - _vmemmap_base;
          uVar7 = uVar8;
          do {
            uVar8 = uVar7;
            if (param_3 <= uVar7) break;
            lVar2 = (lVar12 >> 6) * 0x1000 + uVar9;
            uVar9 = uVar9 + 0x1000;
            uVar8 = (ulong)((int)uVar7 + 1);
            *(long *)(param_2 + uVar7 * 8) = lVar2;
            *(long *)(uVar7 * 0x10 + *(long *)(lVar6 + 0x30)) = lVar2;
            uVar7 = uVar8;
          } while (uVar9 < uVar14);
          uVar7 = *puVar11;
        }
        uVar13 = uVar13 + 1;
        if ((uVar7 & 2) == 0) {
          puVar1 = puVar11 + 4;
          puVar11 = puVar11 + 4;
          if ((*puVar1 & 1) != 0) {
            puVar11 = (ulong *)(*puVar1 & 0xfffffffffffffffc);
          }
        }
        else {
          puVar11 = (ulong *)0x0;
        }
      } while (uVar13 < *(uint *)((long)param_6 + 0xc));
    }
    if (param_3 != uVar8) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    bVar5 = *(byte *)(lVar6 + 0x18) & 0xbf | (param_7 & 1) << 6;
    *(byte *)(lVar6 + 0x18) = bVar5;
    if (*(int *)((long)param_6 + 0xc) == 1) {
      *(byte *)(lVar6 + 0x18) = bVar5 | 1;
    }
  }
  *(undefined4 *)(lVar6 + 0x1c) = param_4;
  *(undefined8 **)(lVar6 + 0x60) = param_6;
  if (unaff_retaddr != 0) {
    *(long *)(lVar6 + 0x58) = unaff_retaddr;
  }
  uVar8 = (ulong)*(uint *)(lVar6 + 0x20) * 0x1000 - 1 >> 0xc;
  lVar12 = 0x3f;
  if (uVar8 != 0) {
    for (; uVar8 >> lVar12 == 0; lVar12 = lVar12 + -1) {
    }
  }
  *(int *)(lVar6 + 0x24) = (int)lVar12 + 1;
  LOCK();
  *(long *)(lVar6 + 0x10) = *(long *)(lVar6 + 0x10) + 1;
  UNLOCK();
  *param_5 = lVar6;
  uVar8 = *(ulong *)(lVar6 + 0x30);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_register_sgt",0xe77,lVar6,*(undefined4 *)(lVar6 + 0x20),
            *(undefined8 *)(lVar6 + 0x10));
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar8;
  return auVar4 << 0x40;
}


// ===== 00107f60 nv_register_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010813f) */
/* WARNING: Removing unreachable block (ram,0x00108234) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
nv_register_sgt(long param_1,long param_2,ulong param_3,undefined4 param_4,long *param_5,
               undefined8 *param_6,byte param_7)

{
  ulong *puVar1;
  long lVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  byte bVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  undefined1 auVar15 [16];
  long unaff_retaddr;
  
  auVar15 = nvos_create_alloc(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0),param_3);
  lVar6 = auVar15._0_8_;
  if (lVar6 == 0) {
    auVar15._0_8_ = 0x51;
    return auVar15;
  }
  puVar11 = (ulong *)*param_6;
  if ((*puVar11 < 4) || ((*(byte *)(param_1 + 0x10) & 0x10) != 0)) {
    if (*(int *)(param_6 + 1) != 0) {
      uVar13 = 0;
      uVar14 = 0;
      do {
        uVar8 = puVar11[3];
        if ((ulong)(uint)uVar8 != 0) {
          uVar7 = puVar11[2];
          uVar9 = 0;
          do {
            uVar10 = (ulong)uVar13;
            if (param_3 <= uVar10) break;
            lVar12 = uVar7 + uVar9;
            uVar9 = uVar9 + 0x1000;
            uVar13 = uVar13 + 1;
            *(long *)(param_2 + uVar10 * 8) = lVar12;
          } while (uVar9 < (uint)uVar8);
        }
        uVar14 = uVar14 + 1;
        if ((*puVar11 & 2) == 0) {
          puVar1 = puVar11 + 4;
          puVar11 = puVar11 + 4;
          if ((*puVar1 & 1) != 0) {
            puVar11 = (ulong *)(*puVar1 & 0xfffffffffffffffc);
          }
        }
        else {
          puVar11 = (ulong *)0x0;
        }
      } while (uVar14 < *(uint *)(param_6 + 1));
    }
  }
  else {
    uVar8 = 0;
    uVar13 = 0;
    if (*(int *)((long)param_6 + 0xc) == 0) {
      uVar8 = 0;
    }
    else {
      do {
        if ((int)puVar11[1] != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        uVar14 = *(uint *)((long)puVar11 + 0xc);
        uVar7 = *puVar11;
        if ((ulong)uVar14 != 0) {
          uVar9 = 0;
          lVar12 = (uVar7 & 0xfffffffffffffffc) - _vmemmap_base;
          uVar7 = uVar8;
          do {
            uVar8 = uVar7;
            if (param_3 <= uVar7) break;
            lVar2 = (lVar12 >> 6) * 0x1000 + uVar9;
            uVar9 = uVar9 + 0x1000;
            uVar8 = (ulong)((int)uVar7 + 1);
            *(long *)(param_2 + uVar7 * 8) = lVar2;
            *(long *)(uVar7 * 0x10 + *(long *)(lVar6 + 0x30)) = lVar2;
            uVar7 = uVar8;
          } while (uVar9 < uVar14);
          uVar7 = *puVar11;
        }
        uVar13 = uVar13 + 1;
        if ((uVar7 & 2) == 0) {
          puVar1 = puVar11 + 4;
          puVar11 = puVar11 + 4;
          if ((*puVar1 & 1) != 0) {
            puVar11 = (ulong *)(*puVar1 & 0xfffffffffffffffc);
          }
        }
        else {
          puVar11 = (ulong *)0x0;
        }
      } while (uVar13 < *(uint *)((long)param_6 + 0xc));
    }
    if (param_3 != uVar8) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    bVar5 = *(byte *)(lVar6 + 0x18) & 0xbf | (param_7 & 1) << 6;
    *(byte *)(lVar6 + 0x18) = bVar5;
    if (*(int *)((long)param_6 + 0xc) == 1) {
      *(byte *)(lVar6 + 0x18) = bVar5 | 1;
    }
  }
  *(undefined4 *)(lVar6 + 0x1c) = param_4;
  *(undefined8 **)(lVar6 + 0x60) = param_6;
  if (unaff_retaddr != 0) {
    *(long *)(lVar6 + 0x58) = unaff_retaddr;
  }
  uVar8 = (ulong)*(uint *)(lVar6 + 0x20) * 0x1000 - 1 >> 0xc;
  lVar12 = 0x3f;
  if (uVar8 != 0) {
    for (; uVar8 >> lVar12 == 0; lVar12 = lVar12 + -1) {
    }
  }
  *(int *)(lVar6 + 0x24) = (int)lVar12 + 1;
  LOCK();
  *(long *)(lVar6 + 0x10) = *(long *)(lVar6 + 0x10) + 1;
  UNLOCK();
  *param_5 = lVar6;
  uVar8 = *(ulong *)(lVar6 + 0x30);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_register_sgt",0xe77,lVar6,*(undefined4 *)(lVar6 + 0x20),
            *(undefined8 *)(lVar6 + 0x10));
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar8;
  return auVar4 << 0x40;
}


// ===== 00108260 __pfx_nv_unregister_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001082e2) */

undefined8
__pfx_nv_unregister_sgt(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,long param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  nv_printf(0,"NVRM: VM: nv_unregister_sgt\n");
  uVar2 = *(undefined8 *)(param_4 + 0x10);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_sgt",0xe87,param_4,*(undefined4 *)(param_4 + 0x20));
  *param_2 = *(undefined8 *)(param_4 + 0x60);
  if (param_3 != (undefined8 *)0x0) {
    uVar2 = *(undefined8 *)(param_4 + 0x58);
    *param_3 = uVar2;
  }
  LOCK();
  plVar1 = (long *)(param_4 + 0x10);
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (((*plVar1 == 0) && (param_4 != 0)) && (*(long *)(param_4 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(param_4 + 0x30));
    uVar2 = kfree(param_4);
    return uVar2;
  }
  return uVar2;
}


// ===== 00108270 nv_unregister_sgt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001082e2) */

undefined8
nv_unregister_sgt(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,long param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  nv_printf(0,"NVRM: VM: nv_unregister_sgt\n");
  uVar2 = *(undefined8 *)(param_4 + 0x10);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_sgt",0xe87,param_4,*(undefined4 *)(param_4 + 0x20));
  *param_2 = *(undefined8 *)(param_4 + 0x60);
  if (param_3 != (undefined8 *)0x0) {
    uVar2 = *(undefined8 *)(param_4 + 0x58);
    *param_3 = uVar2;
  }
  LOCK();
  plVar1 = (long *)(param_4 + 0x10);
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (((*plVar1 == 0) && (param_4 != 0)) && (*(long *)(param_4 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(param_4 + 0x30));
    uVar2 = kfree(param_4);
    return uVar2;
  }
  return uVar2;
}


// ===== 00108310 __pfx_nv_unregister_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108363) */

undefined8 __pfx_nv_unregister_phys_pages(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_phys_pages",0xe9e,param_2,*(undefined4 *)(param_2 + 0x20));
  if ((param_2 != 0) && (*(long *)(param_2 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(param_2 + 0x30));
    uVar1 = kfree(param_2);
    return uVar1;
  }
  return uVar1;
}


// ===== 00108320 nv_unregister_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108363) */

undefined8 nv_unregister_phys_pages(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
            "nv_unregister_phys_pages",0xe9e,param_2,*(undefined4 *)(param_2 + 0x20));
  if ((param_2 != 0) && (*(long *)(param_2 + 0x10) == 0)) {
    kvfree(*(undefined8 *)(param_2 + 0x30));
    uVar1 = kfree(param_2);
    return uVar1;
  }
  return uVar1;
}


// ===== 00108380 __pfx_nv_get_num_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001083a5) */
/* WARNING: Removing unreachable block (ram,0x001083af) */

undefined8 __pfx_nv_get_num_phys_pages(long param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    return 0;
  }
  return 0x1f;
}


// ===== 00108390 nv_get_num_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001083a5) */
/* WARNING: Removing unreachable block (ram,0x001083af) */

undefined8 nv_get_num_phys_pages(long param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    return 0;
  }
  return 0x1f;
}


// ===== 001083c0 __pfx_nv_get_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108430) */
/* WARNING: Removing unreachable block (ram,0x0010843a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_get_phys_pages(long param_1,long param_2,uint *param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_3 != (uint *)0x0) && (param_2 != 0)) {
    uVar3 = *(uint *)(param_1 + 0x20);
    if (*param_3 < *(uint *)(param_1 + 0x20)) {
      uVar3 = *param_3;
    }
    if (uVar3 != 0) {
      uVar2 = 0;
      do {
        lVar1 = (long)(int)uVar2;
        uVar2 = uVar2 + 1;
        *(ulong *)(param_2 + lVar1 * 8) =
             (*(ulong *)(lVar1 * 0x10 + *(long *)(param_1 + 0x30)) >> 0xc) * 0x40 + _vmemmap_base;
      } while (uVar2 != uVar3);
    }
    *param_3 = uVar3;
    return 0;
  }
  return 0x1f;
}


// ===== 001083d0 nv_get_phys_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108430) */
/* WARNING: Removing unreachable block (ram,0x0010843a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_get_phys_pages(long param_1,long param_2,uint *param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_3 != (uint *)0x0) && (param_2 != 0)) {
    uVar3 = *(uint *)(param_1 + 0x20);
    if (*param_3 < *(uint *)(param_1 + 0x20)) {
      uVar3 = *param_3;
    }
    if (uVar3 != 0) {
      uVar2 = 0;
      do {
        lVar1 = (long)(int)uVar2;
        uVar2 = uVar2 + 1;
        *(ulong *)(param_2 + lVar1 * 8) =
             (*(ulong *)(lVar1 * 0x10 + *(long *)(param_1 + 0x30)) >> 0xc) * 0x40 + _vmemmap_base;
      } while (uVar2 != uVar3);
    }
    *param_3 = uVar3;
    return 0;
  }
  return 0x1f;
}


// ===== 00108440 __pfx_nv_get_disp_smmu_stream_ids =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108469) */

void __pfx_nv_get_disp_smmu_stream_ids(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x334);
  *param_3 = *(undefined4 *)(param_1 + 0x338);
  return;
}


// ===== 00108450 nv_get_disp_smmu_stream_ids =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108469) */

void nv_get_disp_smmu_stream_ids(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x334);
  *param_3 = *(undefined4 *)(param_1 + 0x338);
  return;
}


// ===== 00108470 __pfx_nv_alloc_kernel_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001085f1) */
/* WARNING: Removing unreachable block (ram,0x001086f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx_nv_alloc_kernel_mapping
               (undefined8 param_1,long param_2,long param_3,ulong param_4,long param_5,
               ulong *param_6)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  bool bVar12;
  
  param_4 = param_4 & 0xffffffff;
  bVar1 = *(byte *)(param_2 + 0x18);
  if (((bVar1 & 0x10) == 0) ||
     (plVar5 = (long *)(param_3 * 0x10 + *(long *)(param_2 + 0x30)), plVar5[1] != 0)) {
    bVar12 = false;
    if (0x1000 < param_5 + param_4) goto LAB_0010860f;
LAB_001084d1:
    uVar9 = param_5 + param_4;
    if ((bVar1 & 2) == 0) {
      if (((((bVar1 & 8) == 0) && (!bVar12)) && (-1 < (char)bVar1)) &&
         (*(long *)(param_2 + 0x60) == 0)) {
        *param_6 = 0;
        lVar4 = *(long *)(param_3 * 0x10 + *(long *)(param_2 + 0x30) + 8);
        goto LAB_001085e5;
      }
      uVar8 = uVar9 >> 0xc;
      uVar10 = uVar8 & 0xffffffff;
      if ((uVar9 & 0xfff) == 0) goto LAB_00108632;
      uVar10 = (ulong)((int)uVar8 + 1);
      plVar5 = (long *)__kvmalloc_node_noprof(uVar10 * 8,0,1,0x2cc0,0xffffffff);
      if (plVar5 == (long *)0x0) goto LAB_0010874a;
LAB_00108661:
      lVar4 = _vmemmap_base;
      puVar11 = (ulong *)(param_3 * 0x10 + *(long *)(param_2 + 0x30));
      plVar6 = plVar5;
      do {
        uVar8 = *puVar11;
        plVar7 = plVar6 + 1;
        puVar11 = puVar11 + 2;
        *plVar6 = (uVar8 >> 0xc) * 0x40 + lVar4;
        plVar6 = plVar7;
      } while (plVar5 + uVar10 != plVar7);
      goto LAB_0010869f;
    }
    uVar8 = uVar9 >> 0xc;
    uVar10 = uVar8 & 0xffffffff;
    if ((uVar9 & 0xfff) == 0) {
LAB_00108532:
      lVar3 = __kmalloc_noprof(uVar8 << 3,0x2cc0);
      if (lVar3 != 0) {
        if ((int)uVar10 != 0) goto LAB_00108554;
        goto LAB_001085a4;
      }
LAB_0010878c:
      nv_printf(4,"NVRM: failed to allocate vmap() page descriptor table!\n");
      goto LAB_001086d5;
    }
    uVar10 = (ulong)((int)uVar8 + 1);
    lVar3 = __kmalloc_noprof(uVar10 * 8,0x2cc0);
    if (lVar3 == 0) goto LAB_0010878c;
LAB_00108554:
    lVar2 = _vmemmap_base;
    lVar4 = *(long *)(param_2 + 0x30);
    uVar8 = 0;
    do {
      *(ulong *)(lVar3 + uVar8 * 8) =
           (*(ulong *)(lVar4 + (ulong)(uint)((int)param_3 + (int)uVar8) * 0x10) >> 0xc) * 0x40 +
           lVar2;
      uVar8 = uVar8 + 1;
    } while (uVar10 != uVar8);
LAB_001085a4:
    lVar4 = nv_vm_map_pages(lVar3,uVar10,*(int *)(param_2 + 0x1c) == 0,*(byte *)(param_2 + 0x19) & 1
                           );
    kfree(lVar3);
  }
  else {
    bVar12 = *plVar5 != 0;
    if (param_5 + param_4 < 0x1001) goto LAB_001084d1;
LAB_0010860f:
    uVar8 = (ulong)((uint)((param_5 + param_4 & 0xfff) != 0) + (int)(param_5 + param_4 >> 0xc));
    uVar10 = uVar8;
    if ((bVar1 & 2) != 0) goto LAB_00108532;
LAB_00108632:
    plVar5 = (long *)__kvmalloc_node_noprof(uVar8 << 3,0,1,0x2cc0,0xffffffff);
    if (plVar5 == (long *)0x0) {
LAB_0010874a:
      nv_printf(4,"NVRM: failed to allocate vmap() page descriptor table!\n");
      return 0;
    }
    if ((int)uVar10 != 0) goto LAB_00108661;
LAB_0010869f:
    lVar4 = nv_vm_map_pages(plVar5,uVar10,*(int *)(param_2 + 0x1c) == 0,
                            *(byte *)(param_2 + 0x19) & 1);
    kvfree(plVar5);
  }
  if (lVar4 != 0) {
    *param_6 = uVar10;
LAB_001085e5:
    return param_4 + lVar4;
  }
LAB_001086d5:
  nv_printf(4,"NVRM: failed to map pages!\n");
  return 0;
}


// ===== 00108480 nv_alloc_kernel_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001085f1) */
/* WARNING: Removing unreachable block (ram,0x001086f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long nv_alloc_kernel_mapping
               (undefined8 param_1,long param_2,long param_3,ulong param_4,long param_5,
               ulong *param_6)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  bool bVar12;
  
  param_4 = param_4 & 0xffffffff;
  bVar1 = *(byte *)(param_2 + 0x18);
  if (((bVar1 & 0x10) == 0) ||
     (plVar5 = (long *)(param_3 * 0x10 + *(long *)(param_2 + 0x30)), plVar5[1] != 0)) {
    bVar12 = false;
    if (0x1000 < param_5 + param_4) goto LAB_0010860f;
LAB_001084d1:
    uVar9 = param_5 + param_4;
    if ((bVar1 & 2) == 0) {
      if (((((bVar1 & 8) == 0) && (!bVar12)) && (-1 < (char)bVar1)) &&
         (*(long *)(param_2 + 0x60) == 0)) {
        *param_6 = 0;
        lVar4 = *(long *)(param_3 * 0x10 + *(long *)(param_2 + 0x30) + 8);
        goto LAB_001085e5;
      }
      uVar8 = uVar9 >> 0xc;
      uVar10 = uVar8 & 0xffffffff;
      if ((uVar9 & 0xfff) == 0) goto LAB_00108632;
      uVar10 = (ulong)((int)uVar8 + 1);
      plVar5 = (long *)__kvmalloc_node_noprof(uVar10 * 8,0,1,0x2cc0,0xffffffff);
      if (plVar5 == (long *)0x0) goto LAB_0010874a;
LAB_00108661:
      lVar4 = _vmemmap_base;
      puVar11 = (ulong *)(param_3 * 0x10 + *(long *)(param_2 + 0x30));
      plVar6 = plVar5;
      do {
        uVar8 = *puVar11;
        plVar7 = plVar6 + 1;
        puVar11 = puVar11 + 2;
        *plVar6 = (uVar8 >> 0xc) * 0x40 + lVar4;
        plVar6 = plVar7;
      } while (plVar5 + uVar10 != plVar7);
      goto LAB_0010869f;
    }
    uVar8 = uVar9 >> 0xc;
    uVar10 = uVar8 & 0xffffffff;
    if ((uVar9 & 0xfff) == 0) {
LAB_00108532:
      lVar3 = __kmalloc_noprof(uVar8 << 3,0x2cc0);
      if (lVar3 != 0) {
        if ((int)uVar10 != 0) goto LAB_00108554;
        goto LAB_001085a4;
      }
LAB_0010878c:
      nv_printf(4,"NVRM: failed to allocate vmap() page descriptor table!\n");
      goto LAB_001086d5;
    }
    uVar10 = (ulong)((int)uVar8 + 1);
    lVar3 = __kmalloc_noprof(uVar10 * 8,0x2cc0);
    if (lVar3 == 0) goto LAB_0010878c;
LAB_00108554:
    lVar2 = _vmemmap_base;
    lVar4 = *(long *)(param_2 + 0x30);
    uVar8 = 0;
    do {
      *(ulong *)(lVar3 + uVar8 * 8) =
           (*(ulong *)(lVar4 + (ulong)(uint)((int)param_3 + (int)uVar8) * 0x10) >> 0xc) * 0x40 +
           lVar2;
      uVar8 = uVar8 + 1;
    } while (uVar10 != uVar8);
LAB_001085a4:
    lVar4 = nv_vm_map_pages(lVar3,uVar10,*(int *)(param_2 + 0x1c) == 0,*(byte *)(param_2 + 0x19) & 1
                           );
    kfree(lVar3);
  }
  else {
    bVar12 = *plVar5 != 0;
    if (param_5 + param_4 < 0x1001) goto LAB_001084d1;
LAB_0010860f:
    uVar8 = (ulong)((uint)((param_5 + param_4 & 0xfff) != 0) + (int)(param_5 + param_4 >> 0xc));
    uVar10 = uVar8;
    if ((bVar1 & 2) != 0) goto LAB_00108532;
LAB_00108632:
    plVar5 = (long *)__kvmalloc_node_noprof(uVar8 << 3,0,1,0x2cc0,0xffffffff);
    if (plVar5 == (long *)0x0) {
LAB_0010874a:
      nv_printf(4,"NVRM: failed to allocate vmap() page descriptor table!\n");
      return 0;
    }
    if ((int)uVar10 != 0) goto LAB_00108661;
LAB_0010869f:
    lVar4 = nv_vm_map_pages(plVar5,uVar10,*(int *)(param_2 + 0x1c) == 0,
                            *(byte *)(param_2 + 0x19) & 1);
    kvfree(plVar5);
  }
  if (lVar4 != 0) {
    *param_6 = uVar10;
LAB_001085e5:
    return param_4 + lVar4;
  }
LAB_001086d5:
  nv_printf(4,"NVRM: failed to map pages!\n");
  return 0;
}


// ===== 001087b0 __pfx_nv_free_kernel_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001087e5) */

void __pfx_nv_free_kernel_mapping(undefined8 param_1,long param_2,ulong param_3,long param_4)

{
  if ((*(byte *)(param_2 + 0x18) & 2) != 0) {
    iounmap(param_3 & 0xfffffffffffff000);
    return;
  }
  if (param_4 != 0) {
    nv_vm_unmap_pages(param_3 & 0xfffffffffffff000,(int)param_4);
    return;
  }
  return;
}


// ===== 001087c0 nv_free_kernel_mapping =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001087e5) */

void nv_free_kernel_mapping(undefined8 param_1,long param_2,ulong param_3,long param_4)

{
  if ((*(byte *)(param_2 + 0x18) & 2) != 0) {
    iounmap(param_3 & 0xfffffffffffff000);
    return;
  }
  if (param_4 != 0) {
    nv_vm_unmap_pages(param_3 & 0xfffffffffffff000,(int)param_4);
    return;
  }
  return;
}


// ===== 001087f0 __pfx_nv_alloc_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001089aa) */

int __pfx_nv_alloc_pages
              (long param_1,uint param_2,long param_3,char param_4,undefined4 param_5,char param_6,
              int param_7,long param_8,long *param_9)

{
  long lVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  char unaff_retaddr;
  
  uVar5 = 0;
  uVar4 = (ulong)param_2;
  nv_printf(0,"NVRM: VM: nv_alloc_pages: %d pages, nodeid %d\n",uVar4,param_7);
  nv_printf(0,"NVRM: VM:    contig %d  cache_type %d\n",param_4,param_5);
  if (param_1 != 0) {
    uVar5 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0);
  }
  iVar2 = nv_encode_caching(0,param_5,0);
  if (iVar2 != 0) {
    return 0x56;
  }
  lVar3 = nvos_create_alloc(uVar5,param_2);
  if (lVar3 == 0) {
    return 0x51;
  }
  *(undefined4 *)(lVar3 + 0x1c) = param_5;
  if (param_4 != '\0') {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 1;
  }
  if (param_6 != '\0') {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 4;
  }
  if (unaff_retaddr != '\0') {
    *(byte *)(lVar3 + 0x19) = *(byte *)(lVar3 + 0x19) | 1;
  }
  if (param_7 != -1) {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 0x20;
    *(int *)(lVar3 + 0x50) = param_7;
  }
  if ((*(byte *)(lVar3 + 0x18) & 1) == 0) {
    if (param_3 == 0) {
      iVar2 = 0x1f;
      goto LAB_001089b5;
    }
    uVar6 = param_3 - 1U >> 0xc;
    lVar1 = 0x3f;
    if (uVar6 != 0) {
      for (; uVar6 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    *(int *)(lVar3 + 0x24) = (int)lVar1 + 1;
    iVar2 = nv_alloc_system_pages(param_1,lVar3);
  }
  else {
    iVar2 = nv_alloc_contig_pages(param_1,lVar3);
  }
  if (iVar2 == 0) {
    if (param_4 != '\0') {
      uVar4 = 1;
    }
    if ((int)uVar4 != 0) {
      uVar6 = 0;
      do {
        *(undefined8 *)(param_8 + uVar6 * 8) =
             *(undefined8 *)(uVar6 * 0x10 + *(long *)(lVar3 + 0x30));
        uVar6 = uVar6 + 1;
      } while (uVar6 != uVar4);
    }
    *param_9 = lVar3;
    LOCK();
    *(long *)(lVar3 + 0x10) = *(long *)(lVar3 + 0x10) + 1;
    UNLOCK();
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_alloc_pages",0xfa5,lVar3,*(undefined4 *)(lVar3 + 0x20),
              *(undefined8 *)(lVar3 + 0x10),*(undefined8 *)(lVar3 + 0x30));
    return 0;
  }
LAB_001089b5:
  if (*(long *)(lVar3 + 0x10) == 0) {
    kvfree(*(undefined8 *)(lVar3 + 0x30));
    kfree(lVar3);
  }
  return iVar2;
}


// ===== 00108800 nv_alloc_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001089aa) */

int nv_alloc_pages(long param_1,uint param_2,long param_3,char param_4,undefined4 param_5,
                  char param_6,int param_7,long param_8,long *param_9)

{
  long lVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  char unaff_retaddr;
  
  uVar5 = 0;
  uVar4 = (ulong)param_2;
  nv_printf(0,"NVRM: VM: nv_alloc_pages: %d pages, nodeid %d\n",uVar4,param_7);
  nv_printf(0,"NVRM: VM:    contig %d  cache_type %d\n",param_4,param_5);
  if (param_1 != 0) {
    uVar5 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0);
  }
  iVar2 = nv_encode_caching(0,param_5,0);
  if (iVar2 != 0) {
    return 0x56;
  }
  lVar3 = nvos_create_alloc(uVar5,param_2);
  if (lVar3 == 0) {
    return 0x51;
  }
  *(undefined4 *)(lVar3 + 0x1c) = param_5;
  if (param_4 != '\0') {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 1;
  }
  if (param_6 != '\0') {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 4;
  }
  if (unaff_retaddr != '\0') {
    *(byte *)(lVar3 + 0x19) = *(byte *)(lVar3 + 0x19) | 1;
  }
  if (param_7 != -1) {
    *(byte *)(lVar3 + 0x18) = *(byte *)(lVar3 + 0x18) | 0x20;
    *(int *)(lVar3 + 0x50) = param_7;
  }
  if ((*(byte *)(lVar3 + 0x18) & 1) == 0) {
    if (param_3 == 0) {
      iVar2 = 0x1f;
      goto LAB_001089b5;
    }
    uVar6 = param_3 - 1U >> 0xc;
    lVar1 = 0x3f;
    if (uVar6 != 0) {
      for (; uVar6 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    *(int *)(lVar3 + 0x24) = (int)lVar1 + 1;
    iVar2 = nv_alloc_system_pages(param_1,lVar3);
  }
  else {
    iVar2 = nv_alloc_contig_pages(param_1,lVar3);
  }
  if (iVar2 == 0) {
    if (param_4 != '\0') {
      uVar4 = 1;
    }
    if ((int)uVar4 != 0) {
      uVar6 = 0;
      do {
        *(undefined8 *)(param_8 + uVar6 * 8) =
             *(undefined8 *)(uVar6 * 0x10 + *(long *)(lVar3 + 0x30));
        uVar6 = uVar6 + 1;
      } while (uVar6 != uVar4);
    }
    *param_9 = lVar3;
    LOCK();
    *(long *)(lVar3 + 0x10) = *(long *)(lVar3 + 0x10) + 1;
    UNLOCK();
    nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
              "nv_alloc_pages",0xfa5,lVar3,*(undefined4 *)(lVar3 + 0x20),
              *(undefined8 *)(lVar3 + 0x10),*(undefined8 *)(lVar3 + 0x30));
    return 0;
  }
LAB_001089b5:
  if (*(long *)(lVar3 + 0x10) == 0) {
    kvfree(*(undefined8 *)(lVar3 + 0x30));
    kfree(lVar3);
  }
  return iVar2;
}


// ===== 00108a10 __pfx_nv_free_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108a89) */
/* WARNING: Removing unreachable block (ram,0x00108ab7) */

undefined8
__pfx_nv_free_pages(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                   long param_5)

{
  long *plVar1;
  
  nv_printf(0,"NVRM: VM: nv_free_pages: 0x%x\n",param_2);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n","nv_free_pages"
            ,0xfbc,param_5,*(undefined4 *)(param_5 + 0x20));
  LOCK();
  plVar1 = (long *)(param_5 + 0x10);
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (*plVar1 == 0) {
    if (((*(byte *)(param_5 + 0x18) & 2) == 0) && (*(long *)(param_5 + 0x60) == 0)) {
      if ((*(byte *)(param_5 + 0x18) & 1) == 0) {
        nv_free_system_pages(param_5);
      }
      else {
        nv_free_contig_pages();
      }
    }
    if ((param_5 != 0) && (*(long *)(param_5 + 0x10) == 0)) {
      kvfree(*(undefined8 *)(param_5 + 0x30));
      kfree(param_5);
      return 0;
    }
  }
  return 0;
}


// ===== 00108a20 nv_free_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108a89) */
/* WARNING: Removing unreachable block (ram,0x00108ab7) */

undefined8
nv_free_pages(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
             long param_5)

{
  long *plVar1;
  
  nv_printf(0,"NVRM: VM: nv_free_pages: 0x%x\n",param_2);
  nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n","nv_free_pages"
            ,0xfbc,param_5,*(undefined4 *)(param_5 + 0x20));
  LOCK();
  plVar1 = (long *)(param_5 + 0x10);
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (*plVar1 == 0) {
    if (((*(byte *)(param_5 + 0x18) & 2) == 0) && (*(long *)(param_5 + 0x60) == 0)) {
      if ((*(byte *)(param_5 + 0x18) & 1) == 0) {
        nv_free_system_pages(param_5);
      }
      else {
        nv_free_contig_pages();
      }
    }
    if ((param_5 != 0) && (*(long *)(param_5 + 0x10) == 0)) {
      kvfree(*(undefined8 *)(param_5 + 0x30));
      kfree(param_5);
      return 0;
    }
  }
  return 0;
}


// ===== 00108ad0 __pfx_nv_lock_init_locks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108b63) */

bool __pfx_nv_lock_init_locks(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_2 + 8);
  *(undefined8 *)(lVar1 + 0x730) = 0x100000000;
  *(undefined8 *)(lVar1 + 0x868) = 0x100000000;
  *(undefined8 *)(lVar1 + 0x5228) = 0x100000000;
  *(undefined8 *)(lVar1 + 0x738) = 0;
  *(undefined8 *)(lVar1 + 0x740) = 0;
  *(undefined8 *)(lVar1 + 0x870) = 0;
  *(undefined8 *)(lVar1 + 0x878) = 0;
  *(undefined8 *)(lVar1 + 0x5230) = 0;
  *(undefined8 *)(lVar1 + 0x5238) = 0;
  *(undefined8 *)(lVar1 + 0x3a0) = 0;
  cVar2 = rm_init_event_locks();
  return cVar2 != '\0';
}


// ===== 00108ae0 nv_lock_init_locks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108b63) */

bool nv_lock_init_locks(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_2 + 8);
  *(undefined8 *)(lVar1 + 0x730) = 0x100000000;
  *(undefined8 *)(lVar1 + 0x868) = 0x100000000;
  *(undefined8 *)(lVar1 + 0x5228) = 0x100000000;
  *(undefined8 *)(lVar1 + 0x738) = 0;
  *(undefined8 *)(lVar1 + 0x740) = 0;
  *(undefined8 *)(lVar1 + 0x870) = 0;
  *(undefined8 *)(lVar1 + 0x878) = 0;
  *(undefined8 *)(lVar1 + 0x5230) = 0;
  *(undefined8 *)(lVar1 + 0x5238) = 0;
  *(undefined8 *)(lVar1 + 0x3a0) = 0;
  cVar2 = rm_init_event_locks();
  return cVar2 != '\0';
}


// ===== 00108b70 __pfx_nv_lock_destroy_locks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_lock_destroy_locks(void)

{
  rm_destroy_event_locks();
  return;
}


// ===== 00108b80 nv_lock_destroy_locks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_lock_destroy_locks(void)

{
  rm_destroy_event_locks();
  return;
}


// ===== 00108b90 __pfx_nv_post_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_post_event(undefined8 *param_1,undefined4 param_2,undefined4 param_3,
                        undefined4 param_4,undefined2 param_5,char param_6)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  lVar2 = param_1[3];
  lVar1 = lVar2 + 0x9c;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  if (param_6 == '\0') {
    *(undefined1 *)(lVar2 + 0x98) = 1;
  }
  else {
    puVar5 = (undefined8 *)__kmalloc_cache_noprof(_capable,0x2820,0x40);
    if (puVar5 == (undefined8 *)0x0) {
      _raw_spin_unlock_irqrestore(lVar1,uVar4);
      return;
    }
    if (*(undefined8 **)(lVar2 + 0x90) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar2 + 0x90) = puVar5;
    }
    if (*(long *)(lVar2 + 0x88) == 0) {
      *(undefined8 **)(lVar2 + 0x88) = puVar5;
    }
    *(undefined8 **)(lVar2 + 0x90) = puVar5;
    uVar3 = *param_1;
    *puVar5 = 0;
    puVar5[1] = uVar3;
    uVar3 = param_1[2];
    *(undefined4 *)((long)puVar5 + 0x14) = param_4;
    puVar5[3] = uVar3;
    uVar3 = param_1[3];
    *(undefined4 *)((long)puVar5 + 0xc) = param_2;
    puVar5[4] = uVar3;
    uVar3 = param_1[4];
    *(undefined4 *)(puVar5 + 2) = param_3;
    puVar5[5] = uVar3;
    uVar3 = param_1[5];
    *(undefined2 *)(puVar5 + 3) = param_5;
    puVar5[6] = uVar3;
    puVar5[7] = param_1[6];
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  __wake_up(lVar2 + 0xa0,1,1,0);
  return;
}


// ===== 00108ba0 nv_post_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_post_event(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined2 param_5,char param_6)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  lVar2 = param_1[3];
  lVar1 = lVar2 + 0x9c;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  if (param_6 == '\0') {
    *(undefined1 *)(lVar2 + 0x98) = 1;
  }
  else {
    puVar5 = (undefined8 *)__kmalloc_cache_noprof(_capable,0x2820,0x40);
    if (puVar5 == (undefined8 *)0x0) {
      _raw_spin_unlock_irqrestore(lVar1,uVar4);
      return;
    }
    if (*(undefined8 **)(lVar2 + 0x90) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar2 + 0x90) = puVar5;
    }
    if (*(long *)(lVar2 + 0x88) == 0) {
      *(undefined8 **)(lVar2 + 0x88) = puVar5;
    }
    *(undefined8 **)(lVar2 + 0x90) = puVar5;
    uVar3 = *param_1;
    *puVar5 = 0;
    puVar5[1] = uVar3;
    uVar3 = param_1[2];
    *(undefined4 *)((long)puVar5 + 0x14) = param_4;
    puVar5[3] = uVar3;
    uVar3 = param_1[3];
    *(undefined4 *)((long)puVar5 + 0xc) = param_2;
    puVar5[4] = uVar3;
    uVar3 = param_1[4];
    *(undefined4 *)(puVar5 + 2) = param_3;
    puVar5[5] = uVar3;
    uVar3 = param_1[5];
    *(undefined2 *)(puVar5 + 3) = param_5;
    puVar5[6] = uVar3;
    puVar5[7] = param_1[6];
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  __wake_up(lVar2 + 0xa0,1,1,0);
  return;
}


// ===== 00108cf0 __pfx_nv_is_rm_firmware_active =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108d28) */

undefined8 __pfx_nv_is_rm_firmware_active(void)

{
  int iVar1;
  undefined4 extraout_var;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (rm_firmware_active != (char *)0x0) {
    iVar1 = strcmp(rm_firmware_active,"all");
    uVar2 = CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
  }
  return uVar2;
}


// ===== 00108d00 nv_is_rm_firmware_active =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108d28) */

undefined8 nv_is_rm_firmware_active(void)

{
  int iVar1;
  undefined4 extraout_var;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (rm_firmware_active != (char *)0x0) {
    iVar1 = strcmp(rm_firmware_active,"all");
    uVar2 = CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
  }
  return uVar2;
}


// ===== 00108d30 __pfx_nv_get_firmware =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108df5) */

undefined8 *
__pfx_nv_get_firmware
          (long param_1,int param_2,ulong param_3,undefined8 *param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  uint uVar4;
  char *pcVar5;
  long in_GS_OFFSET;
  undefined8 *puStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puStack_28 = (undefined8 *)0x0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0);
  uVar4 = (uint)param_3;
  if (param_2 == 0) {
    if (uVar4 < 4) {
      pcVar5 = "nvidia/595.71.05/gsp_tu10x.bin";
      if (uVar4 == 0) {
        pcVar5 = "";
      }
      goto LAB_00108dc0;
    }
    if (uVar4 - 4 < 9) {
      pcVar5 = "nvidia/595.71.05/gsp_ga10x.bin";
      if ((0x1b70UL >> (param_3 & 0x3f) & 1) == 0) {
        pcVar5 = "";
      }
      iVar2 = request_firmware(&puStack_28,pcVar5,uVar1);
      goto joined_r0x00108dcd;
    }
LAB_00108db9:
    pcVar5 = "";
  }
  else {
    if (param_2 != 1) goto LAB_00108db9;
    if (uVar4 < 4) {
      pcVar5 = "";
      if (uVar4 != 0) {
        pcVar5 = "nvidia/595.71.05/gsp_log_tu10x.bin";
      }
    }
    else {
      if (8 < uVar4 - 4) goto LAB_00108db9;
      pcVar5 = "nvidia/595.71.05/gsp_log_ga10x.bin";
      if ((0x1b70UL >> (param_3 & 0x3f) & 1) == 0) {
        pcVar5 = "";
      }
    }
  }
LAB_00108dc0:
  iVar2 = request_firmware(&puStack_28,pcVar5,uVar1);
joined_r0x00108dcd:
  if (iVar2 == 0) {
    *param_5 = (int)*puStack_28;
    *param_4 = puStack_28[1];
    puVar3 = puStack_28;
  }
  else {
    puVar3 = (undefined8 *)0x0;
  }
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return puVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00108d40 nv_get_firmware =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108df5) */

undefined8 *
nv_get_firmware(long param_1,int param_2,ulong param_3,undefined8 *param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  uint uVar4;
  char *pcVar5;
  long in_GS_OFFSET;
  undefined8 *local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_28 = (undefined8 *)0x0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x3b0);
  uVar4 = (uint)param_3;
  if (param_2 == 0) {
    if (uVar4 < 4) {
      pcVar5 = "nvidia/595.71.05/gsp_tu10x.bin";
      if (uVar4 == 0) {
        pcVar5 = "";
      }
      goto LAB_00108dc0;
    }
    if (uVar4 - 4 < 9) {
      pcVar5 = "nvidia/595.71.05/gsp_ga10x.bin";
      if ((0x1b70UL >> (param_3 & 0x3f) & 1) == 0) {
        pcVar5 = "";
      }
      iVar2 = request_firmware(&local_28,pcVar5,uVar1);
      goto joined_r0x00108dcd;
    }
LAB_00108db9:
    pcVar5 = "";
  }
  else {
    if (param_2 != 1) goto LAB_00108db9;
    if (uVar4 < 4) {
      pcVar5 = "";
      if (uVar4 != 0) {
        pcVar5 = "nvidia/595.71.05/gsp_log_tu10x.bin";
      }
    }
    else {
      if (8 < uVar4 - 4) goto LAB_00108db9;
      pcVar5 = "nvidia/595.71.05/gsp_log_ga10x.bin";
      if ((0x1b70UL >> (param_3 & 0x3f) & 1) == 0) {
        pcVar5 = "";
      }
    }
  }
LAB_00108dc0:
  iVar2 = request_firmware(&local_28,pcVar5,uVar1);
joined_r0x00108dcd:
  if (iVar2 == 0) {
    *param_5 = (int)*local_28;
    *param_4 = local_28[1];
    puVar3 = local_28;
  }
  else {
    puVar3 = (undefined8 *)0x0;
  }
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return puVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00108e60 __pfx_nv_put_firmware =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_put_firmware(void)

{
  release_firmware();
  return;
}


// ===== 00108e70 nv_put_firmware =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_put_firmware(void)

{
  release_firmware();
  return;
}


// ===== 00108e80 __pfx_nv_get_file_private =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108f2c) */
/* WARNING: Removing unreachable block (ram,0x00108efa) */
/* WARNING: Removing unreachable block (ram,0x00108f1a) */

undefined8 __pfx_nv_get_file_private(undefined8 param_1,char param_2,long *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = fget();
  if (lVar3 == 0) {
    return 0;
  }
  if ((*(long *)(lVar3 + 0x20) != 0) &&
     (uVar1 = *(uint *)(*(long *)(lVar3 + 0x20) + 0x4c), uVar1 >> 0x14 == 0xc3)) {
    if (param_2 == '\0') {
      uVar4 = 0;
      do {
        if ((((byte)(&nv_linux_minor_bitmap)[(long)uVar4 >> 3] >> (uVar4 & 7) & 1) != 0) &&
           ((uVar1 & 0xfffff) == (uint)uVar4)) {
          uVar2 = *(undefined8 *)(lVar3 + 0x18);
          *param_3 = lVar3;
          return uVar2;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 != 0xf8);
    }
    else if ((uVar1 & 0xfffff) == 0xff) {
      uVar2 = *(undefined8 *)(lVar3 + 0x18);
      *param_3 = lVar3;
      return uVar2;
    }
  }
  fput(lVar3);
  return 0;
}


// ===== 00108e90 nv_get_file_private =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00108f2c) */
/* WARNING: Removing unreachable block (ram,0x00108efa) */
/* WARNING: Removing unreachable block (ram,0x00108f1a) */

undefined8 nv_get_file_private(undefined8 param_1,char param_2,long *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = fget();
  if (lVar3 == 0) {
    return 0;
  }
  if ((*(long *)(lVar3 + 0x20) != 0) &&
     (uVar1 = *(uint *)(*(long *)(lVar3 + 0x20) + 0x4c), uVar1 >> 0x14 == 0xc3)) {
    if (param_2 == '\0') {
      uVar4 = 0;
      do {
        if ((((byte)(&nv_linux_minor_bitmap)[(long)uVar4 >> 3] >> (uVar4 & 7) & 1) != 0) &&
           ((uVar1 & 0xfffff) == (uint)uVar4)) {
          uVar2 = *(undefined8 *)(lVar3 + 0x18);
          *param_3 = lVar3;
          return uVar2;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 != 0xf8);
    }
    else if ((uVar1 & 0xfffff) == 0xff) {
      uVar2 = *(undefined8 *)(lVar3 + 0x18);
      *param_3 = lVar3;
      return uVar2;
    }
  }
  fput(lVar3);
  return 0;
}


// ===== 00108f40 __pfx_nv_put_file_private =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_put_file_private(void)

{
  fput();
  return;
}


// ===== 00108f50 nv_put_file_private =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_put_file_private(void)

{
  fput();
  return;
}


// ===== 00108f60 __pfx_nv_get_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010904f) */
/* WARNING: Removing unreachable block (ram,0x00109067) */

undefined8 __pfx_nv_get_event(long param_1,long *param_2,uint *param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0x88) != 0) {
    uVar3 = _raw_spin_lock_irqsave(param_1 + 0x9c);
    plVar1 = *(long **)(param_1 + 0x88);
    if (plVar1 == (long *)0x0) {
      _raw_spin_unlock_irqrestore(param_1 + 0x9c,uVar3);
      uVar3 = 0xffff;
    }
    else {
      *param_2 = plVar1[1];
      param_2[1] = plVar1[2];
      param_2[2] = plVar1[3];
      param_2[3] = plVar1[4];
      param_2[4] = plVar1[5];
      param_2[5] = plVar1[6];
      param_2[6] = plVar1[7];
      if (*(long **)(param_1 + 0x90) == plVar1) {
        *(undefined8 *)(param_1 + 0x90) = 0;
      }
      lVar2 = *plVar1;
      *(long *)(param_1 + 0x88) = lVar2;
      *param_3 = (uint)(lVar2 != 0);
      _raw_spin_unlock_irqrestore(param_1 + 0x9c,uVar3);
      kfree(plVar1);
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0xffff;
}


// ===== 00108f70 nv_get_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010904f) */
/* WARNING: Removing unreachable block (ram,0x00109067) */

undefined8 nv_get_event(long param_1,long *param_2,uint *param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0x88) != 0) {
    uVar3 = _raw_spin_lock_irqsave(param_1 + 0x9c);
    plVar1 = *(long **)(param_1 + 0x88);
    if (plVar1 == (long *)0x0) {
      _raw_spin_unlock_irqrestore(param_1 + 0x9c,uVar3);
      uVar3 = 0xffff;
    }
    else {
      *param_2 = plVar1[1];
      param_2[1] = plVar1[2];
      param_2[2] = plVar1[3];
      param_2[3] = plVar1[4];
      param_2[4] = plVar1[5];
      param_2[5] = plVar1[6];
      param_2[6] = plVar1[7];
      if (*(long **)(param_1 + 0x90) == plVar1) {
        *(undefined8 *)(param_1 + 0x90) = 0;
      }
      lVar2 = *plVar1;
      *(long *)(param_1 + 0x88) = lVar2;
      *param_3 = (uint)(lVar2 != 0);
      _raw_spin_unlock_irqrestore(param_1 + 0x9c,uVar3);
      kfree(plVar1);
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0xffff;
}


// ===== 00109080 __pfx_nv_start_rc_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109111) */
/* WARNING: Removing unreachable block (ram,0x0010911b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_start_rc_timer(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x2c4) == 0) {
    lVar1 = *(long *)(param_1 + 8);
    lVar2 = lVar1 + 0x700;
    nv_printf(0,"NVRM: initializing rc timer\n");
    *(code **)(lVar1 + 0x728) = nvidia_rc_timer_callback;
    timer_init_key(lVar2,nv_timer_callback_typed_data,0,0,0);
    lVar1 = _jiffies;
    *(undefined4 *)(param_1 + 0x2c4) = 1;
    mod_timer(lVar2,lVar1 + 1000);
    nv_printf(0,"NVRM: rc timer initialized\n");
    return 0;
  }
  return 0xffffffff;
}


// ===== 00109090 nv_start_rc_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109111) */
/* WARNING: Removing unreachable block (ram,0x0010911b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_start_rc_timer(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x2c4) == 0) {
    lVar1 = *(long *)(param_1 + 8);
    lVar2 = lVar1 + 0x700;
    nv_printf(0,"NVRM: initializing rc timer\n");
    *(code **)(lVar1 + 0x728) = nvidia_rc_timer_callback;
    timer_init_key(lVar2,nv_timer_callback_typed_data,0,0,0);
    lVar1 = _jiffies;
    *(undefined4 *)(param_1 + 0x2c4) = 1;
    mod_timer(lVar2,lVar1 + 1000);
    nv_printf(0,"NVRM: rc timer initialized\n");
    return 0;
  }
  return 0xffffffff;
}


// ===== 00109120 __pfx_nv_stop_rc_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109182) */
/* WARNING: Removing unreachable block (ram,0x0010918c) */

undefined8 __pfx_nv_stop_rc_timer(long param_1)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x2c4) != 0) {
    lVar1 = *(long *)(param_1 + 8);
    nv_printf(0,"NVRM: stopping rc timer\n");
    *(undefined4 *)(param_1 + 0x2c4) = 0;
    timer_delete_sync(lVar1 + 0x700);
    nv_printf(0,"NVRM: rc timer stopped\n");
    return 0;
  }
  return 0xffffffff;
}


// ===== 00109130 nv_stop_rc_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109182) */
/* WARNING: Removing unreachable block (ram,0x0010918c) */

undefined8 nv_stop_rc_timer(long param_1)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x2c4) != 0) {
    lVar1 = *(long *)(param_1 + 8);
    nv_printf(0,"NVRM: stopping rc timer\n");
    *(undefined4 *)(param_1 + 0x2c4) = 0;
    timer_delete_sync(lVar1 + 0x700);
    nv_printf(0,"NVRM: rc timer stopped\n");
    return 0;
  }
  return 0xffffffff;
}


// ===== 001091a0 __pfx_nv_start_snapshot_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_start_snapshot_timer(undefined8 param_1)

{
  undefined8 in_R9;
  
  nv_ctl_device._20864_8_ = snapshot_timer_callback;
  nv_ctl_device._20880_8_ = param_1;
  timer_init_key(0x52fcb8,nv_timer_callback_typed_data,0,0,0,in_R9,0x1091b9);
  mod_timer(0x52fcb8,_jiffies + 10);
  return;
}


// ===== 001091b0 nv_start_snapshot_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_start_snapshot_timer(undefined8 param_1)

{
  undefined8 in_R9;
  
  nv_ctl_device._20864_8_ = snapshot_timer_callback;
  nv_ctl_device._20880_8_ = param_1;
  timer_init_key(0x52fcb8,nv_timer_callback_typed_data,0,0,0,in_R9,0x1091b9);
  mod_timer(0x52fcb8,_jiffies + 10);
  return;
}


// ===== 00109200 __pfx_nv_stop_snapshot_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010925a) */

void __pfx_nv_stop_snapshot_timer(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(0x52fce8);
  uVar1 = nv_ctl_device._20880_8_;
  nv_ctl_device._20880_8_ = 0;
  _raw_spin_unlock_irqrestore(0x52fce8,uVar2);
  if (uVar1 != 0) {
    timer_delete_sync(0x52fcb8);
    return;
  }
  return;
}


// ===== 00109210 nv_stop_snapshot_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010925a) */

void nv_stop_snapshot_timer(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(0x52fce8);
  uVar1 = nv_ctl_device._20880_8_;
  nv_ctl_device._20880_8_ = 0;
  _raw_spin_unlock_irqrestore(0x52fce8,uVar2);
  if (uVar1 != 0) {
    timer_delete_sync(0x52fcb8);
    return;
  }
  return;
}


// ===== 00109260 __pfx_nv_flush_snapshot_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_nv_flush_snapshot_timer(void)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(0x52fce8);
  if (nv_ctl_device._20880_8_ != 0) {
    (*(code *)nv_ctl_device._20880_8_)(nv_ctl_device._776_8_);
  }
  _raw_spin_unlock_irqrestore(0x52fce8,uVar1);
  return;
}


// ===== 00109270 nv_flush_snapshot_timer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nv_flush_snapshot_timer(void)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(0x52fce8);
  if (nv_ctl_device._20880_8_ != 0) {
    (*(code *)nv_ctl_device._20880_8_)(nv_ctl_device._776_8_);
  }
  _raw_spin_unlock_irqrestore(0x52fce8,uVar1);
  return;
}


// ===== 001092c0 __pfx_nv_set_system_power_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001092e3) */

undefined8 __pfx_nv_set_system_power_state(uint param_1)

{
  undefined8 uVar1;
  
  if (2 < param_1) {
    return 0x1f;
  }
  uVar1 = nv_set_system_power_state_part_0();
  return uVar1;
}


// ===== 001092d0 nv_set_system_power_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001092e3) */

undefined8 nv_set_system_power_state(uint param_1)

{
  undefined8 uVar1;
  
  if (2 < param_1) {
    return 0x1f;
  }
  uVar1 = nv_set_system_power_state_part_0();
  return uVar1;
}


// ===== 001092f0 __pfx_nv_get_adapter_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109389) */

long __pfx_nv_get_adapter_state(int param_1,char param_2,char param_3)

{
  long lVar1;
  
  down(nv_linux_devices_lock);
  lVar1 = nv_linux_devices;
  while( true ) {
    if (lVar1 == 0) {
      up(nv_linux_devices_lock);
      return 0;
    }
    if (((*(int *)(lVar1 + 0x14) == param_1) && (*(char *)(lVar1 + 0x18) == param_2)) &&
       (*(char *)(lVar1 + 0x19) == param_3)) break;
    lVar1 = *(long *)(lVar1 + 0x758);
  }
  up(nv_linux_devices_lock);
  return lVar1;
}


// ===== 00109300 nv_get_adapter_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109389) */

long nv_get_adapter_state(int param_1,char param_2,char param_3)

{
  long lVar1;
  
  down(nv_linux_devices_lock);
  lVar1 = nv_linux_devices;
  while( true ) {
    if (lVar1 == 0) {
      up(nv_linux_devices_lock);
      return 0;
    }
    if (((*(int *)(lVar1 + 0x14) == param_1) && (*(char *)(lVar1 + 0x18) == param_2)) &&
       (*(char *)(lVar1 + 0x19) == param_3)) break;
    lVar1 = *(long *)(lVar1 + 0x758);
  }
  up(nv_linux_devices_lock);
  return lVar1;
}


// ===== 00109390 __pfx_nv_get_ctl_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001093b0) */

undefined1 * __pfx_nv_get_ctl_state(void)

{
  return nv_ctl_device;
}


// ===== 001093a0 nv_get_ctl_state =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001093b0) */

undefined1 * nv_get_ctl_state(void)

{
  return nv_ctl_device;
}


// ===== 001093c0 __pfx_nv_log_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001093eb) */

undefined8 __pfx_nv_log_error(long param_1)

{
  nv_report_error(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b8));
  return 0;
}


// ===== 001093d0 nv_log_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001093eb) */

undefined8 nv_log_error(long param_1)

{
  nv_report_error(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b8));
  return 0;
}


// ===== 001093f0 __pfx_nv_set_primary_vga_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010942d) */

undefined8 __pfx_nv_set_primary_vga_status(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (lVar1 != 0) {
    *(byte *)(param_1 + 700) = *(byte *)(lVar1 + 0x588) >> 1 & 1;
  }
  return 0;
}


// ===== 00109400 nv_set_primary_vga_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010942d) */

undefined8 nv_set_primary_vga_status(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (lVar1 != 0) {
    *(byte *)(param_1 + 700) = *(byte *)(lVar1 + 0x588) >> 1 & 1;
  }
  return 0;
}


// ===== 00109440 __pfx_nv_requires_dma_remap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109463) */

bool __pfx_nv_requires_dma_remap(void)

{
  return os_cc_sme_enabled._4_1_ == '\0';
}


// ===== 00109450 nv_requires_dma_remap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109463) */

bool nv_requires_dma_remap(void)

{
  return os_cc_sme_enabled._4_1_ == '\0';
}


// ===== 00109470 __pfx_nvidia_get_gpuid_list =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109512) */

undefined8 __pfx_nvidia_get_gpuid_list(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  down(nv_linux_devices_lock);
  if (nv_linux_devices == 0) {
    uVar4 = 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    lVar2 = nv_linux_devices;
    do {
      lVar2 = *(long *)(lVar2 + 0x758);
      uVar1 = uVar1 + 1;
    } while (lVar2 != 0);
    uVar4 = 1;
    if ((*param_2 != 0) && (uVar4 = 0, uVar1 <= *param_2)) {
      uVar1 = 0;
      lVar2 = nv_linux_devices;
      do {
        uVar3 = (ulong)uVar1;
        uVar1 = uVar1 + 1;
        *(undefined4 *)(param_1 + uVar3 * 4) = *(undefined4 *)(lVar2 + 0x24);
        lVar2 = *(long *)(lVar2 + 0x758);
      } while (lVar2 != 0);
      uVar4 = 1;
    }
  }
  *param_2 = uVar1;
  up(nv_linux_devices_lock);
  return uVar4;
}


// ===== 00109480 nvidia_get_gpuid_list =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109512) */

undefined8 nvidia_get_gpuid_list(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  down(nv_linux_devices_lock);
  if (nv_linux_devices == 0) {
    uVar4 = 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    lVar2 = nv_linux_devices;
    do {
      lVar2 = *(long *)(lVar2 + 0x758);
      uVar1 = uVar1 + 1;
    } while (lVar2 != 0);
    uVar4 = 1;
    if ((*param_2 != 0) && (uVar4 = 0, uVar1 <= *param_2)) {
      uVar1 = 0;
      lVar2 = nv_linux_devices;
      do {
        uVar3 = (ulong)uVar1;
        uVar1 = uVar1 + 1;
        *(undefined4 *)(param_1 + uVar3 * 4) = *(undefined4 *)(lVar2 + 0x24);
        lVar2 = *(long *)(lVar2 + 0x758);
      } while (lVar2 != 0);
      uVar4 = 1;
    }
  }
  *param_2 = uVar1;
  up(nv_linux_devices_lock);
  return uVar4;
}


// ===== 00109520 __pfx_nvidia_dev_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001095e8) */

int __pfx_nvidia_dev_get(int param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  down(nv_linux_devices_lock);
  lVar1 = nv_linux_devices;
  while( true ) {
    if (lVar1 == 0) {
      up(nv_linux_devices_lock);
      return -0x13;
    }
    if (param_1 == *(int *)(lVar1 + 0x24)) break;
    lVar1 = *(long *)(lVar1 + 0x758);
  }
  down(lVar1 + 0x730);
  up(nv_linux_devices_lock);
  iVar3 = nv_open_device(lVar1,param_2);
  if (((iVar3 == 0) && (param_3 == '\0')) &&
     (iVar4 = rm_set_external_kernel_client_count(param_2,lVar1,1), iVar4 != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  up(lVar1 + 0x730);
  return iVar3;
}


// ===== 00109530 nvidia_dev_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001095e8) */

int nvidia_dev_get(int param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  down(nv_linux_devices_lock);
  lVar1 = nv_linux_devices;
  while( true ) {
    if (lVar1 == 0) {
      up(nv_linux_devices_lock);
      return -0x13;
    }
    if (param_1 == *(int *)(lVar1 + 0x24)) break;
    lVar1 = *(long *)(lVar1 + 0x758);
  }
  down(lVar1 + 0x730);
  up(nv_linux_devices_lock);
  iVar3 = nv_open_device(lVar1,param_2);
  if (((iVar3 == 0) && (param_3 == '\0')) &&
     (iVar4 = rm_set_external_kernel_client_count(param_2,lVar1,1), iVar4 != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  up(lVar1 + 0x730);
  return iVar3;
}


// ===== 00109620 __pfx_nvidia_dev_put =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvidia_dev_put(int param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  down(nv_linux_devices_lock);
  lVar1 = nv_linux_devices;
  while( true ) {
    if (lVar1 == 0) {
      up(nv_linux_devices_lock);
      return;
    }
    if (param_1 == *(int *)(lVar1 + 0x24)) break;
    lVar1 = *(long *)(lVar1 + 0x758);
  }
  down(lVar1 + 0x730);
  up(nv_linux_devices_lock);
  nv_close_device(lVar1,param_2);
  if ((param_3 == '\0') &&
     (iVar3 = rm_set_external_kernel_client_count(param_2,lVar1,0), iVar3 != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  up(lVar1 + 0x730);
  return;
}


// ===== 00109630 nvidia_dev_put =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvidia_dev_put(int param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  down(nv_linux_devices_lock);
  lVar1 = nv_linux_devices;
  while( true ) {
    if (lVar1 == 0) {
      up(nv_linux_devices_lock);
      return;
    }
    if (param_1 == *(int *)(lVar1 + 0x24)) break;
    lVar1 = *(long *)(lVar1 + 0x758);
  }
  down(lVar1 + 0x730);
  up(nv_linux_devices_lock);
  nv_close_device(lVar1,param_2);
  if ((param_3 == '\0') &&
     (iVar3 = rm_set_external_kernel_client_count(param_2,lVar1,0), iVar3 != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  up(lVar1 + 0x730);
  return;
}


// ===== 00109700 __pfx_nvidia_close =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001097c7) */

undefined8 __pfx_nvidia_close(long param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong *puVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  ulong uVar13;
  long in_GS_OFFSET;
  
  lVar3 = *(long *)(param_2 + 0x18);
  nv_printf(0,"NVRM: nvidia_close on GPU with minor number %d\n",*(uint *)(param_1 + 0x4c) & 0xfffff
           );
  if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == 0xff) {
    lVar3 = *(long *)(param_2 + 0x18);
    lVar12 = *(long *)(lVar3 + 0x80);
    lVar5 = *(long *)(lVar3 + 0x70);
    nv_printf(0,"NVRM: nvidia_ctl_close\n");
    down(lVar12 + 0x730);
    LOCK();
    plVar2 = (long *)(lVar12 + 0x3a0);
    *plVar2 = *plVar2 + -1;
    UNLOCK();
    if (*plVar2 == 0) {
      *(uint *)(lVar12 + 0x10) = *(uint *)(lVar12 + 0x10) & 0xfffffffe;
    }
    up(lVar12 + 0x730);
    rm_cleanup_file_private(lVar5,lVar12,lVar3);
    for (plVar2 = *(long **)(lVar3 + 0x1a8); plVar2 != (long *)0x0; plVar2 = (long *)plVar2[0xc]) {
      puVar6 = (undefined8 *)*plVar2;
      if (puVar6 != (undefined8 *)0x0) {
        nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                  "nv_alloc_release",0x668,puVar6,*(undefined4 *)(puVar6 + 4),puVar6[2],puVar6[6]);
        LOCK();
        plVar1 = puVar6 + 2;
        *plVar1 = *plVar1 + -1;
        UNLOCK();
        if (*plVar1 == 0) {
          LOCK();
          puVar6[2] = puVar6[2] + 1;
          UNLOCK();
          *puVar6 = *(undefined8 *)(lVar3 + 0x78);
          *(undefined8 **)(lVar3 + 0x78) = puVar6;
        }
      }
    }
    puVar6 = *(undefined8 **)(lVar3 + 0x78);
    while (puVar6 != (undefined8 *)0x0) {
      puVar7 = (undefined8 *)*puVar6;
      iVar10 = *(int *)(puVar6 + 7);
      iVar11 = os_get_current_process();
      if (iVar10 == iVar11) {
        nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                  "nvidia_ctl_close",0xca6,puVar6,*(undefined4 *)(puVar6 + 4),puVar6[2],puVar6[6]);
      }
      nv_free_pages(lVar12,*(undefined4 *)(puVar6 + 4),*(byte *)(puVar6 + 3) & 1,
                    *(undefined4 *)((long)puVar6 + 0x1c),puVar6);
      puVar6 = puVar7;
    }
    if (*(long *)(lVar3 + 0xe0) != 0) {
      lVar12 = *(long *)(lVar3 + 0xd8);
      uVar13 = 0;
      do {
        iVar10 = *(int *)(lVar12 + uVar13 * 4);
        if (iVar10 != 0) {
          nvidia_dev_put(iVar10,lVar5,0);
          lVar12 = *(long *)(lVar3 + 0xd8);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(ulong *)(lVar3 + 0xe0));
      kfree(lVar12);
      *(undefined8 *)(lVar3 + 0xe0) = 0;
    }
    nv_free_file_private(lVar3);
    *(undefined8 *)(param_2 + 0x18) = 0;
    if ((lVar5 != 0) && (cVar9 = rm_is_altstack_in_use(), cVar9 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar5);
    }
  }
  else {
    *(undefined8 *)(param_2 + 0x18) = 0;
    iVar10 = wait_for_completion_interruptible(lVar3 + 0x1d0);
    puVar4 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar10 == 0) {
      while (iVar10 = down_read_trylock(nv_system_pm_lock), iVar10 == 0) {
        if (((*puVar4 & 4) != 0) || ((*puVar4 & 2) != 0)) goto LAB_00109781;
        __SCT__cond_resched();
      }
      nvidia_close_callback(lVar3);
      up_read(nv_system_pm_lock);
    }
    else {
LAB_00109781:
      nv_kthread_q_item_init(lVar3 + 0xb8,nvidia_close_deferred,lVar3);
      iVar10 = nv_kthread_q_schedule_q_item(nv_deferred_close_kthread_q,lVar3 + 0xb8);
      if (iVar10 == 0) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)invalidInstructionException();
        (*pcVar8)();
      }
    }
  }
  return 0;
}


// ===== 00109710 nvidia_close =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001097c7) */

undefined8 nvidia_close(long param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong *puVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  ulong uVar13;
  long in_GS_OFFSET;
  
  lVar3 = *(long *)(param_2 + 0x18);
  nv_printf(0,"NVRM: nvidia_close on GPU with minor number %d\n",*(uint *)(param_1 + 0x4c) & 0xfffff
           );
  if ((*(uint *)(param_1 + 0x4c) & 0xfffff) == 0xff) {
    lVar3 = *(long *)(param_2 + 0x18);
    lVar12 = *(long *)(lVar3 + 0x80);
    lVar5 = *(long *)(lVar3 + 0x70);
    nv_printf(0,"NVRM: nvidia_ctl_close\n");
    down(lVar12 + 0x730);
    LOCK();
    plVar2 = (long *)(lVar12 + 0x3a0);
    *plVar2 = *plVar2 + -1;
    UNLOCK();
    if (*plVar2 == 0) {
      *(uint *)(lVar12 + 0x10) = *(uint *)(lVar12 + 0x10) & 0xfffffffe;
    }
    up(lVar12 + 0x730);
    rm_cleanup_file_private(lVar5,lVar12,lVar3);
    for (plVar2 = *(long **)(lVar3 + 0x1a8); plVar2 != (long *)0x0; plVar2 = (long *)plVar2[0xc]) {
      puVar6 = (undefined8 *)*plVar2;
      if (puVar6 != (undefined8 *)0x0) {
        nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                  "nv_alloc_release",0x668,puVar6,*(undefined4 *)(puVar6 + 4),puVar6[2],puVar6[6]);
        LOCK();
        plVar1 = puVar6 + 2;
        *plVar1 = *plVar1 + -1;
        UNLOCK();
        if (*plVar1 == 0) {
          LOCK();
          puVar6[2] = puVar6[2] + 1;
          UNLOCK();
          *puVar6 = *(undefined8 *)(lVar3 + 0x78);
          *(undefined8 **)(lVar3 + 0x78) = puVar6;
        }
      }
    }
    puVar6 = *(undefined8 **)(lVar3 + 0x78);
    while (puVar6 != (undefined8 *)0x0) {
      puVar7 = (undefined8 *)*puVar6;
      iVar10 = *(int *)(puVar6 + 7);
      iVar11 = os_get_current_process();
      if (iVar10 == iVar11) {
        nv_printf(0,"NVRM: VM: %s:%d: 0x%p, %d page(s), count = %lld, page_table = 0x%p\n",
                  "nvidia_ctl_close",0xca6,puVar6,*(undefined4 *)(puVar6 + 4),puVar6[2],puVar6[6]);
      }
      nv_free_pages(lVar12,*(undefined4 *)(puVar6 + 4),*(byte *)(puVar6 + 3) & 1,
                    *(undefined4 *)((long)puVar6 + 0x1c),puVar6);
      puVar6 = puVar7;
    }
    if (*(long *)(lVar3 + 0xe0) != 0) {
      lVar12 = *(long *)(lVar3 + 0xd8);
      uVar13 = 0;
      do {
        iVar10 = *(int *)(lVar12 + uVar13 * 4);
        if (iVar10 != 0) {
          nvidia_dev_put(iVar10,lVar5,0);
          lVar12 = *(long *)(lVar3 + 0xd8);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(ulong *)(lVar3 + 0xe0));
      kfree(lVar12);
      *(undefined8 *)(lVar3 + 0xe0) = 0;
    }
    nv_free_file_private(lVar3);
    *(undefined8 *)(param_2 + 0x18) = 0;
    if ((lVar5 != 0) && (cVar9 = rm_is_altstack_in_use(), cVar9 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar5);
    }
  }
  else {
    *(undefined8 *)(param_2 + 0x18) = 0;
    iVar10 = wait_for_completion_interruptible(lVar3 + 0x1d0);
    puVar4 = *(ulong **)(&const_current_task + in_GS_OFFSET);
    if (iVar10 == 0) {
      while (iVar10 = down_read_trylock(nv_system_pm_lock), iVar10 == 0) {
        if (((*puVar4 & 4) != 0) || ((*puVar4 & 2) != 0)) goto LAB_00109781;
        __SCT__cond_resched();
      }
      nvidia_close_callback(lVar3);
      up_read(nv_system_pm_lock);
    }
    else {
LAB_00109781:
      nv_kthread_q_item_init(lVar3 + 0xb8,nvidia_close_deferred,lVar3);
      iVar10 = nv_kthread_q_schedule_q_item(nv_deferred_close_kthread_q,lVar3 + 0xb8);
      if (iVar10 == 0) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)invalidInstructionException();
        (*pcVar8)();
      }
    }
  }
  return 0;
}


// ===== 00109a10 __pfx_nvidia_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109af6) */

long __pfx_nvidia_unlocked_ioctl(long param_1,uint param_2,ulong param_3)

{
  ulong *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long *__src;
  long lVar5;
  undefined4 *puVar6;
  void *__dest;
  uint *puVar7;
  ulong uVar8;
  ulong __n;
  uint uVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  long in_GS_OFFSET;
  ulong uStack_50;
  ulong uStack_48;
  long lStack_40;
  
  uVar11 = param_2 & 0xff;
  __n = (ulong)(param_2 >> 0x10 & 0x3fff);
  uVar9 = param_2 >> 0x10 & 0x3fff;
  lVar10 = *(long *)(param_1 + 0x20);
  lVar5 = *(long *)(param_1 + 0x18);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_50 = 0;
  uStack_48 = 0;
  iVar3 = rm_validate_ioctls(param_2,uVar9);
  if (iVar3 == 0x24) {
    puVar7 = &nv_ioctls_table_23;
    uVar8 = 0;
    do {
      if (uVar11 == *puVar7) {
        uVar12 = *(ulong *)(&UNK_005a3be8 + uVar8 * 0x18);
        if ((&UNK_005a3bf0)[uVar8 * 0x18] == '\0') {
          if (__n == uVar12) goto LAB_00109aff;
        }
        else if ((uVar9 != 0) && (__n % uVar12 == 0)) goto LAB_00109aff;
        nv_printf(4,"NVRM: invalid %d structure size, expected %d, got %d!\n",*puVar7,uVar12,__n);
        goto LAB_00109acb;
      }
      uVar4 = (int)uVar8 + 1;
      uVar8 = (ulong)uVar4;
      puVar7 = puVar7 + 6;
    } while (uVar4 != 10);
    nv_printf(4,"NVRM:unknown NVRM ioctl command: 0x%x\n",uVar11);
  }
  else if (iVar3 == 0) {
LAB_00109aff:
    nv_printf(0,"NVRM: ioctl(0x%x, 0x%x, 0x%x)\n",uVar11,param_3 & 0xffffffff,uVar9);
    if (((*(uint *)(lVar10 + 0x4c) & 0xfffff) != 0xff) &&
       (iVar3 = wait_for_completion_interruptible(lVar5 + 0x1d0), iVar3 != 0)) {
      lVar10 = (long)iVar3;
      goto LAB_00109ad2;
    }
    uVar4 = param_2 & 0xff;
    if (uVar11 == 0xd3) {
      if (uVar9 == 0x10) {
        lVar10 = _copy_from_user(&uStack_50,param_3,0x10);
        if (lVar10 != 0) {
          lVar10 = -0xe;
          nv_printf(4,"NVRM: failed to copy in ioctl XFER data!\n");
          goto LAB_00109ad2;
        }
        __n = uStack_50 >> 0x20;
        if (__n < 0x4001) {
          param_3 = uStack_48;
          uVar4 = (uint)uStack_50;
          goto LAB_00109b4a;
        }
        nv_printf(4,"NVRM: invalid ioctl XFER size!\n");
      }
      else {
        nv_printf(4,"NVRM: invalid ioctl XFER structure size!\n");
      }
      goto LAB_00109acb;
    }
LAB_00109b4a:
    __src = (long *)__kmalloc_noprof(__n,0x2cc0);
    if (__src == (long *)0x0) {
      lVar10 = -0xc;
      nv_printf(4,"NVRM: failed to allocate ioctl memory\n");
      goto LAB_00109ad2;
    }
    __check_object_size(__src,__n,0);
    lVar10 = _copy_from_user(__src,param_3,__n);
    if (lVar10 == 0) {
      if (uVar4 == 0xda) {
        uVar9 = 0xffffffea;
        if (__n == 8) {
          uVar9 = 0;
          *(int *)__src = *(int *)(lVar5 + 0x1f8);
          *(int *)((long)__src + 4) = *(int *)(lVar5 + 0x1fc);
        }
      }
      else {
        lVar10 = *(long *)(lVar5 + 0x80);
        puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
        if (lVar10 == 0) {
          uVar9 = 0xfffffffb;
        }
        else {
          while (iVar3 = down_read_trylock(nv_system_pm_lock), iVar3 == 0) {
            if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
              uVar9 = 0xfffffffc;
              goto code_r0x00109beb;
            }
            __SCT__cond_resched();
          }
          cVar2 = rm_is_altstack_in_use();
          if (cVar2 == '\0') {
            puVar6 = (undefined4 *)0x0;
            uVar9 = *(uint *)(lVar10 + 0x10);
            if ((uVar9 & 0x8000) == 0) {
LAB_00109d3b:
              if (uVar4 == 0xd6) {
                if (((uVar9 & 4) != 0) && (__n == 8)) {
                  if (*(long *)(lVar10 + 0x7f8) == 0) {
                    *(long *)(lVar10 + 0x7f8) = *__src;
LAB_00109ef5:
                    uVar9 = 0;
                  }
                  else {
                    uVar9 = 0;
                    if (*(long *)(lVar10 + 0x7f8) != *__src) {
                      uVar9 = 0xfffffff0;
                    }
                  }
                  goto LAB_00109da0;
                }
LAB_00109e15:
                uVar9 = 0xffffffea;
              }
              else if ((int)uVar4 < 0xd7) {
                if (uVar4 == 0xd4) {
                  if ((((uVar9 & 4) != 0) && (__n >> 2 != 0)) && ((__n & 3) == 0)) {
                    lVar10 = lVar10 + 0x730;
                    down(lVar10);
                    if (*(long *)(lVar5 + 0xe0) == 0) {
                      __dest = (void *)__kmalloc_noprof(__n,0x2cc0);
                      *(void **)(lVar5 + 0xd8) = __dest;
                      if (__dest == (void *)0x0) {
                        uVar9 = 0xfffffff4;
                        up(lVar10);
                      }
                      else {
                        memcpy(__dest,__src,__n);
                        *(ulong *)(lVar5 + 0xe0) = __n >> 2;
                        up(lVar10);
                        uVar8 = 0;
                        if (*(long *)(lVar5 + 0xe0) == 0) goto LAB_00109ef5;
                        do {
                          iVar3 = *(int *)(*(long *)(lVar5 + 0xd8) + uVar8 * 4);
                          if ((iVar3 != 0) && (iVar3 = nvidia_dev_get(iVar3,puVar6,0), iVar3 != 0))
                          goto joined_r0x0010a359;
                          uVar8 = uVar8 + 1;
                        } while (uVar8 < *(ulong *)(lVar5 + 0xe0));
                        uVar9 = 0;
                      }
                      goto LAB_00109da0;
                    }
                    up(lVar10);
                  }
                  goto LAB_00109e15;
                }
                if (uVar4 == 0xd5) {
                  if ((((uVar9 & 4) != 0) || (__n < 8)) ||
                     (lVar10 = *(long *)(*(long *)(lVar10 + 0x108) + 0x18), lVar10 == 0))
                  goto LAB_00109e15;
                  iVar3 = *(int *)(lVar10 + 0x100);
                  uVar9 = 0;
                  *(int *)((long)__src + 4) = 0;
                  *(int *)__src = iVar3;
                }
                else if (uVar4 == 200) {
                  if ((uVar9 & 4) == 0) goto LAB_00109e15;
                  uVar8 = __n / 0x48;
                  if (__n < uVar8 * 0x48) {
                    /* WARNING: Subroutine does not return */
                    __fortify_panic(0xf,__n);
                  }
                  memset(__src,0,uVar8 * 0x48);
                  down(nv_linux_devices_lock);
                  if (uVar8 < num_nv_devices) {
                    uVar9 = 0xffffffea;
                  }
                  else {
                    if ((0x47 < __n) &&
                       (uVar12 = 0, lVar10 = nv_linux_devices, nv_linux_devices != 0)) {
                      do {
                        if ((*(byte *)(lVar10 + 0x10) & 2) == 0) {
                          *(undefined1 *)(__src + uVar12 * 9) = 1;
                          *(undefined4 *)((long)__src + uVar12 * 0x48 + 4) =
                               *(undefined4 *)(lVar10 + 0x14);
                          *(undefined1 *)(__src + uVar12 * 9 + 1) = *(undefined1 *)(lVar10 + 0x18);
                          *(undefined1 *)((long)__src + uVar12 * 0x48 + 9) =
                               *(undefined1 *)(lVar10 + 0x19);
                          *(undefined2 *)((long)__src + uVar12 * 0x48 + 0xc) =
                               *(undefined2 *)(lVar10 + 0x1c);
                          *(undefined2 *)((long)__src + uVar12 * 0x48 + 0xe) =
                               *(undefined2 *)(lVar10 + 0x1e);
                          *(int *)(__src + uVar12 * 9 + 2) = *(int *)(lVar10 + 0x24);
                          *(short *)((long)__src + uVar12 * 0x48 + 0x14) =
                               (short)*(undefined4 *)(lVar10 + 0x17c);
                          __src[uVar12 * 9 + 3] = **(long **)(lVar10 + 0x108);
                          __src[uVar12 * 9 + 4] = *(long *)(*(long *)(lVar10 + 0x108) + 8);
                          *(int *)(__src + uVar12 * 9 + 7) = *(int *)(lVar10 + 0x750);
                          if (*(undefined **)(*(long *)(lVar10 + 0x3b0) + 0x60) == &pci_bus_type) {
                            __src[uVar12 * 9 + 5] = **(long **)(lVar10 + 0x140);
                            __src[uVar12 * 9 + 6] = *(long *)(*(long *)(lVar10 + 0x140) + 8);
                          }
                          uVar12 = uVar12 + 1;
                        }
                        lVar10 = *(long *)(lVar10 + 0x758);
                      } while ((lVar10 != 0) && (uVar12 < uVar8));
                    }
                    uVar9 = 0;
                  }
                  up(nv_linux_devices_lock);
                }
                else {
                  if (uVar4 != 0xd2) goto LAB_0010a10a;
                  if ((uVar9 & 4) == 0) goto LAB_00109e15;
                  iVar3 = rm_perform_version_check(puVar6,__src,__n);
                  uVar9 = -(uint)(iVar3 != 0) & 0xffffffea;
                }
              }
              else if (uVar4 == 0xd8) {
                uVar9 = 0xfffffff3;
                cVar2 = capable(0x15);
                if (cVar2 != '\0') {
                  if (((*(byte *)(lVar10 + 0x10) & 4) != 0) || (__n != 4)) goto LAB_00109e15;
                  down(lVar10 + 0x730);
                  if (*(int *)(lVar10 + 0x4a0) == -1) {
                    uVar9 = 0;
                    if ((int)*__src != 0) {
                      if ((int)*__src == 5) goto LAB_0010a40d;
LAB_0010a3e1:
                      uVar9 = 0xffffffea;
                    }
                  }
                  else {
                    iVar3 = (int)*__src;
                    if (*(int *)(lVar10 + 0x4a4) != iVar3) {
                      if (iVar3 == 5) {
LAB_0010a40d:
                        if ((1 < *(long *)(lVar10 + 0x3a0)) ||
                           (iVar3 = rm_gpu_numa_offline(puVar6,lVar10), iVar3 != 0)) {
                          uVar9 = 0xfffffff0;
                          goto LAB_00109fc2;
                        }
                        iVar3 = (int)*__src;
                        if (*(int *)(lVar10 + 0x4a0) == -1) {
                          if (iVar3 == 5) {
                            rm_gpu_numa_online(puVar6,lVar10);
                          }
                          goto LAB_0010a3e1;
                        }
                      }
                      *(int *)(lVar10 + 0x4a4) = iVar3;
                      if ((int)*__src == 3) {
                        iVar3 = rm_gpu_numa_online(puVar6,lVar10);
                        uVar9 = -(uint)(iVar3 != 0) & 0xfffffff0;
                        goto LAB_00109fc2;
                      }
                    }
                    uVar9 = 0;
                  }
LAB_00109fc2:
                  up(lVar10 + 0x730);
                }
              }
              else if (uVar4 == 0xd9) {
                if ((__n != 0xa30) || ((uVar9 & 4) != 0)) goto LAB_00109e15;
                iVar3 = nv_dma_buf_export(lVar10,__src);
                *(int *)(__src + 0x145) = iVar3;
                uVar9 = 0;
              }
              else if (uVar4 == 0xd7) {
                if (((uVar9 & 4) != 0) || (__n != 0x230)) goto LAB_00109e15;
                uVar9 = 0xfffffff0;
                iVar3 = rm_get_gpu_numa_info(puVar6,lVar10,__src);
                if (iVar3 == 0) {
                  iVar3 = 0;
                  if (*(int *)(lVar10 + 0x4a0) != -1) {
                    iVar3 = *(int *)(lVar10 + 0x4a4);
                  }
                  *(int *)((long)__src + 4) = iVar3;
                  uVar9 = 0;
                  *(undefined1 *)(__src + 4) = *(undefined1 *)(lVar10 + 0x4a8);
                  __src[1] = nv_ctl_device._2040_8_;
                }
              }
              else {
LAB_0010a10a:
                iVar3 = rm_ioctl(puVar6,lVar10,lVar5,uVar4,__src,__n);
                uVar9 = -(uint)(iVar3 != 0) & 0xffffffea;
              }
LAB_00109da0:
              if (puVar6 != (undefined4 *)0x0) goto LAB_00109da5;
            }
            else {
              uVar9 = 0xffffffea;
              nv_printf(0,"NVRM: GPU is lost, skipping nvidia_ioctl\n");
            }
          }
          else {
            puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache);
            if (puVar6 == (undefined4 *)0x0) {
              uVar9 = 0xfffffff4;
              nv_printf(4,"NVRM: Unable to allocate altstack for ioctl\n");
            }
            else {
              *puVar6 = 0x2ff0;
              *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
              uVar9 = *(uint *)(lVar10 + 0x10);
              if ((uVar9 & 0x8000) == 0) goto LAB_00109d3b;
              uVar9 = 0xffffffea;
              nv_printf(0,"NVRM: GPU is lost, skipping nvidia_ioctl\n");
LAB_00109da5:
              cVar2 = rm_is_altstack_in_use();
              if (cVar2 != '\0') {
                kmem_cache_free(nvidia_stack_t_cache,puVar6);
              }
            }
          }
          up_read(nv_system_pm_lock);
        }
      }
code_r0x00109beb:
      __check_object_size(__src,__n,1);
      lVar10 = (long)(int)uVar9;
      lVar5 = _copy_to_user(param_3,__src,__n);
      if (lVar5 != 0) {
        nv_printf(4,"NVRM: failed to copy out ioctl data\n");
        goto LAB_00109cf0;
      }
    }
    else {
      nv_printf(4,"NVRM: failed to copy in ioctl data!\n");
LAB_00109cf0:
      lVar10 = -0xe;
    }
    kfree(__src);
    goto LAB_00109ad2;
  }
LAB_00109acb:
  lVar10 = -0x16;
LAB_00109ad2:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar10;
joined_r0x0010a359:
  while (uVar8 != 0) {
    uVar8 = uVar8 - 1;
    iVar3 = *(int *)(*(long *)(lVar5 + 0xd8) + uVar8 * 4);
    if (iVar3 != 0) {
      nvidia_dev_put(iVar3,puVar6,0);
    }
  }
  down(lVar10);
  kfree(*(undefined8 *)(lVar5 + 0xd8));
  *(undefined8 *)(lVar5 + 0xe0) = 0;
  up(lVar10);
  goto LAB_00109e15;
}


// ===== 00109a20 nvidia_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00109af6) */

long nvidia_unlocked_ioctl(long param_1,uint param_2,ulong param_3)

{
  ulong *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long *__src;
  long lVar5;
  undefined4 *puVar6;
  void *__dest;
  uint *puVar7;
  ulong uVar8;
  ulong __n;
  uint uVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  long in_GS_OFFSET;
  ulong local_50;
  ulong local_48;
  long local_40;
  
  uVar11 = param_2 & 0xff;
  __n = (ulong)(param_2 >> 0x10 & 0x3fff);
  uVar9 = param_2 >> 0x10 & 0x3fff;
  lVar10 = *(long *)(param_1 + 0x20);
  lVar5 = *(long *)(param_1 + 0x18);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_50 = 0;
  local_48 = 0;
  iVar3 = rm_validate_ioctls(param_2,uVar9);
  if (iVar3 == 0x24) {
    puVar7 = &nv_ioctls_table_23;
    uVar8 = 0;
    do {
      if (uVar11 == *puVar7) {
        uVar12 = *(ulong *)(&UNK_005a3be8 + uVar8 * 0x18);
        if ((&UNK_005a3bf0)[uVar8 * 0x18] == '\0') {
          if (__n == uVar12) goto LAB_00109aff;
        }
        else if ((uVar9 != 0) && (__n % uVar12 == 0)) goto LAB_00109aff;
        nv_printf(4,"NVRM: invalid %d structure size, expected %d, got %d!\n",*puVar7,uVar12,__n);
        goto LAB_00109acb;
      }
      uVar4 = (int)uVar8 + 1;
      uVar8 = (ulong)uVar4;
      puVar7 = puVar7 + 6;
    } while (uVar4 != 10);
    nv_printf(4,"NVRM:unknown NVRM ioctl command: 0x%x\n",uVar11);
  }
  else if (iVar3 == 0) {
LAB_00109aff:
    nv_printf(0,"NVRM: ioctl(0x%x, 0x%x, 0x%x)\n",uVar11,param_3 & 0xffffffff,uVar9);
    if (((*(uint *)(lVar10 + 0x4c) & 0xfffff) != 0xff) &&
       (iVar3 = wait_for_completion_interruptible(lVar5 + 0x1d0), iVar3 != 0)) {
      lVar10 = (long)iVar3;
      goto LAB_00109ad2;
    }
    uVar4 = param_2 & 0xff;
    if (uVar11 == 0xd3) {
      if (uVar9 == 0x10) {
        lVar10 = _copy_from_user(&local_50,param_3,0x10);
        if (lVar10 != 0) {
          lVar10 = -0xe;
          nv_printf(4,"NVRM: failed to copy in ioctl XFER data!\n");
          goto LAB_00109ad2;
        }
        __n = local_50 >> 0x20;
        if (__n < 0x4001) {
          param_3 = local_48;
          uVar4 = (uint)local_50;
          goto LAB_00109b4a;
        }
        nv_printf(4,"NVRM: invalid ioctl XFER size!\n");
      }
      else {
        nv_printf(4,"NVRM: invalid ioctl XFER structure size!\n");
      }
      goto LAB_00109acb;
    }
LAB_00109b4a:
    __src = (long *)__kmalloc_noprof(__n,0x2cc0);
    if (__src == (long *)0x0) {
      lVar10 = -0xc;
      nv_printf(4,"NVRM: failed to allocate ioctl memory\n");
      goto LAB_00109ad2;
    }
    __check_object_size(__src,__n,0);
    lVar10 = _copy_from_user(__src,param_3,__n);
    if (lVar10 == 0) {
      if (uVar4 == 0xda) {
        uVar9 = 0xffffffea;
        if (__n == 8) {
          uVar9 = 0;
          *(int *)__src = *(int *)(lVar5 + 0x1f8);
          *(int *)((long)__src + 4) = *(int *)(lVar5 + 0x1fc);
        }
      }
      else {
        lVar10 = *(long *)(lVar5 + 0x80);
        puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
        if (lVar10 == 0) {
          uVar9 = 0xfffffffb;
        }
        else {
          while (iVar3 = down_read_trylock(nv_system_pm_lock), iVar3 == 0) {
            if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) {
              uVar9 = 0xfffffffc;
              goto code_r0x00109beb;
            }
            __SCT__cond_resched();
          }
          cVar2 = rm_is_altstack_in_use();
          if (cVar2 == '\0') {
            puVar6 = (undefined4 *)0x0;
            uVar9 = *(uint *)(lVar10 + 0x10);
            if ((uVar9 & 0x8000) == 0) {
LAB_00109d3b:
              if (uVar4 == 0xd6) {
                if (((uVar9 & 4) != 0) && (__n == 8)) {
                  if (*(long *)(lVar10 + 0x7f8) == 0) {
                    *(long *)(lVar10 + 0x7f8) = *__src;
LAB_00109ef5:
                    uVar9 = 0;
                  }
                  else {
                    uVar9 = 0;
                    if (*(long *)(lVar10 + 0x7f8) != *__src) {
                      uVar9 = 0xfffffff0;
                    }
                  }
                  goto LAB_00109da0;
                }
LAB_00109e15:
                uVar9 = 0xffffffea;
              }
              else if ((int)uVar4 < 0xd7) {
                if (uVar4 == 0xd4) {
                  if ((((uVar9 & 4) != 0) && (__n >> 2 != 0)) && ((__n & 3) == 0)) {
                    lVar10 = lVar10 + 0x730;
                    down(lVar10);
                    if (*(long *)(lVar5 + 0xe0) == 0) {
                      __dest = (void *)__kmalloc_noprof(__n,0x2cc0);
                      *(void **)(lVar5 + 0xd8) = __dest;
                      if (__dest == (void *)0x0) {
                        uVar9 = 0xfffffff4;
                        up(lVar10);
                      }
                      else {
                        memcpy(__dest,__src,__n);
                        *(ulong *)(lVar5 + 0xe0) = __n >> 2;
                        up(lVar10);
                        uVar8 = 0;
                        if (*(long *)(lVar5 + 0xe0) == 0) goto LAB_00109ef5;
                        do {
                          iVar3 = *(int *)(*(long *)(lVar5 + 0xd8) + uVar8 * 4);
                          if ((iVar3 != 0) && (iVar3 = nvidia_dev_get(iVar3,puVar6,0), iVar3 != 0))
                          goto joined_r0x0010a359;
                          uVar8 = uVar8 + 1;
                        } while (uVar8 < *(ulong *)(lVar5 + 0xe0));
                        uVar9 = 0;
                      }
                      goto LAB_00109da0;
                    }
                    up(lVar10);
                  }
                  goto LAB_00109e15;
                }
                if (uVar4 == 0xd5) {
                  if ((((uVar9 & 4) != 0) || (__n < 8)) ||
                     (lVar10 = *(long *)(*(long *)(lVar10 + 0x108) + 0x18), lVar10 == 0))
                  goto LAB_00109e15;
                  iVar3 = *(int *)(lVar10 + 0x100);
                  uVar9 = 0;
                  *(int *)((long)__src + 4) = 0;
                  *(int *)__src = iVar3;
                }
                else if (uVar4 == 200) {
                  if ((uVar9 & 4) == 0) goto LAB_00109e15;
                  uVar8 = __n / 0x48;
                  if (__n < uVar8 * 0x48) {
                    /* WARNING: Subroutine does not return */
                    __fortify_panic(0xf,__n);
                  }
                  memset(__src,0,uVar8 * 0x48);
                  down(nv_linux_devices_lock);
                  if (uVar8 < num_nv_devices) {
                    uVar9 = 0xffffffea;
                  }
                  else {
                    if ((0x47 < __n) &&
                       (uVar12 = 0, lVar10 = nv_linux_devices, nv_linux_devices != 0)) {
                      do {
                        if ((*(byte *)(lVar10 + 0x10) & 2) == 0) {
                          *(undefined1 *)(__src + uVar12 * 9) = 1;
                          *(undefined4 *)((long)__src + uVar12 * 0x48 + 4) =
                               *(undefined4 *)(lVar10 + 0x14);
                          *(undefined1 *)(__src + uVar12 * 9 + 1) = *(undefined1 *)(lVar10 + 0x18);
                          *(undefined1 *)((long)__src + uVar12 * 0x48 + 9) =
                               *(undefined1 *)(lVar10 + 0x19);
                          *(undefined2 *)((long)__src + uVar12 * 0x48 + 0xc) =
                               *(undefined2 *)(lVar10 + 0x1c);
                          *(undefined2 *)((long)__src + uVar12 * 0x48 + 0xe) =
                               *(undefined2 *)(lVar10 + 0x1e);
                          *(int *)(__src + uVar12 * 9 + 2) = *(int *)(lVar10 + 0x24);
                          *(short *)((long)__src + uVar12 * 0x48 + 0x14) =
                               (short)*(undefined4 *)(lVar10 + 0x17c);
                          __src[uVar12 * 9 + 3] = **(long **)(lVar10 + 0x108);
                          __src[uVar12 * 9 + 4] = *(long *)(*(long *)(lVar10 + 0x108) + 8);
                          *(int *)(__src + uVar12 * 9 + 7) = *(int *)(lVar10 + 0x750);
                          if (*(undefined **)(*(long *)(lVar10 + 0x3b0) + 0x60) == &pci_bus_type) {
                            __src[uVar12 * 9 + 5] = **(long **)(lVar10 + 0x140);
                            __src[uVar12 * 9 + 6] = *(long *)(*(long *)(lVar10 + 0x140) + 8);
                          }
                          uVar12 = uVar12 + 1;
                        }
                        lVar10 = *(long *)(lVar10 + 0x758);
                      } while ((lVar10 != 0) && (uVar12 < uVar8));
                    }
                    uVar9 = 0;
                  }
                  up(nv_linux_devices_lock);
                }
                else {
                  if (uVar4 != 0xd2) goto LAB_0010a10a;
                  if ((uVar9 & 4) == 0) goto LAB_00109e15;
                  iVar3 = rm_perform_version_check(puVar6,__src,__n);
                  uVar9 = -(uint)(iVar3 != 0) & 0xffffffea;
                }
              }
              else if (uVar4 == 0xd8) {
                uVar9 = 0xfffffff3;
                cVar2 = capable(0x15);
                if (cVar2 != '\0') {
                  if (((*(byte *)(lVar10 + 0x10) & 4) != 0) || (__n != 4)) goto LAB_00109e15;
                  down(lVar10 + 0x730);
                  if (*(int *)(lVar10 + 0x4a0) == -1) {
                    uVar9 = 0;
                    if ((int)*__src != 0) {
                      if ((int)*__src == 5) goto LAB_0010a40d;
LAB_0010a3e1:
                      uVar9 = 0xffffffea;
                    }
                  }
                  else {
                    iVar3 = (int)*__src;
                    if (*(int *)(lVar10 + 0x4a4) != iVar3) {
                      if (iVar3 == 5) {
LAB_0010a40d:
                        if ((1 < *(long *)(lVar10 + 0x3a0)) ||
                           (iVar3 = rm_gpu_numa_offline(puVar6,lVar10), iVar3 != 0)) {
                          uVar9 = 0xfffffff0;
                          goto LAB_00109fc2;
                        }
                        iVar3 = (int)*__src;
                        if (*(int *)(lVar10 + 0x4a0) == -1) {
                          if (iVar3 == 5) {
                            rm_gpu_numa_online(puVar6,lVar10);
                          }
                          goto LAB_0010a3e1;
                        }
                      }
                      *(int *)(lVar10 + 0x4a4) = iVar3;
                      if ((int)*__src == 3) {
                        iVar3 = rm_gpu_numa_online(puVar6,lVar10);
                        uVar9 = -(uint)(iVar3 != 0) & 0xfffffff0;
                        goto LAB_00109fc2;
                      }
                    }
                    uVar9 = 0;
                  }
LAB_00109fc2:
                  up(lVar10 + 0x730);
                }
              }
              else if (uVar4 == 0xd9) {
                if ((__n != 0xa30) || ((uVar9 & 4) != 0)) goto LAB_00109e15;
                iVar3 = nv_dma_buf_export(lVar10,__src);
                *(int *)(__src + 0x145) = iVar3;
                uVar9 = 0;
              }
              else if (uVar4 == 0xd7) {
                if (((uVar9 & 4) != 0) || (__n != 0x230)) goto LAB_00109e15;
                uVar9 = 0xfffffff0;
                iVar3 = rm_get_gpu_numa_info(puVar6,lVar10,__src);
                if (iVar3 == 0) {
                  iVar3 = 0;
                  if (*(int *)(lVar10 + 0x4a0) != -1) {
                    iVar3 = *(int *)(lVar10 + 0x4a4);
                  }
                  *(int *)((long)__src + 4) = iVar3;
                  uVar9 = 0;
                  *(undefined1 *)(__src + 4) = *(undefined1 *)(lVar10 + 0x4a8);
                  __src[1] = nv_ctl_device._2040_8_;
                }
              }
              else {
LAB_0010a10a:
                iVar3 = rm_ioctl(puVar6,lVar10,lVar5,uVar4,__src,__n);
                uVar9 = -(uint)(iVar3 != 0) & 0xffffffea;
              }
LAB_00109da0:
              if (puVar6 != (undefined4 *)0x0) goto LAB_00109da5;
            }
            else {
              uVar9 = 0xffffffea;
              nv_printf(0,"NVRM: GPU is lost, skipping nvidia_ioctl\n");
            }
          }
          else {
            puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache);
            if (puVar6 == (undefined4 *)0x0) {
              uVar9 = 0xfffffff4;
              nv_printf(4,"NVRM: Unable to allocate altstack for ioctl\n");
            }
            else {
              *puVar6 = 0x2ff0;
              *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
              uVar9 = *(uint *)(lVar10 + 0x10);
              if ((uVar9 & 0x8000) == 0) goto LAB_00109d3b;
              uVar9 = 0xffffffea;
              nv_printf(0,"NVRM: GPU is lost, skipping nvidia_ioctl\n");
LAB_00109da5:
              cVar2 = rm_is_altstack_in_use();
              if (cVar2 != '\0') {
                kmem_cache_free(nvidia_stack_t_cache,puVar6);
              }
            }
          }
          up_read(nv_system_pm_lock);
        }
      }
code_r0x00109beb:
      __check_object_size(__src,__n,1);
      lVar10 = (long)(int)uVar9;
      lVar5 = _copy_to_user(param_3,__src,__n);
      if (lVar5 != 0) {
        nv_printf(4,"NVRM: failed to copy out ioctl data\n");
        goto LAB_00109cf0;
      }
    }
    else {
      nv_printf(4,"NVRM: failed to copy in ioctl data!\n");
LAB_00109cf0:
      lVar10 = -0xe;
    }
    kfree(__src);
    goto LAB_00109ad2;
  }
LAB_00109acb:
  lVar10 = -0x16;
LAB_00109ad2:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar10;
joined_r0x0010a359:
  while (uVar8 != 0) {
    uVar8 = uVar8 - 1;
    iVar3 = *(int *)(*(long *)(lVar5 + 0xd8) + uVar8 * 4);
    if (iVar3 != 0) {
      nvidia_dev_put(iVar3,puVar6,0);
    }
  }
  down(lVar10);
  kfree(*(undefined8 *)(lVar5 + 0xd8));
  *(undefined8 *)(lVar5 + 0xe0) = 0;
  up(lVar10);
  goto LAB_00109e15;
}


// ===== 0010a4c0 __pfx_nvidia_dev_get_uuid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a59b) */

int __pfx_nvidia_dev_get_uuid(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = find_uuid_candidate();
  do {
    if (lVar4 == 0) {
      return -0x13;
    }
    iVar2 = nv_open_device(lVar4,param_2);
    if (iVar2 != 0) {
LAB_0010a575:
      up(lVar4 + 0x730);
      return iVar2;
    }
    if (*(char *)(lVar4 + 0x2c) == '\0') {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if ((*(long *)(lVar4 + 0x2d) == *param_1) && (*(long *)(lVar4 + 0x35) == param_1[1])) {
      iVar3 = rm_set_external_kernel_client_count(param_2,lVar4,1);
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      goto LAB_0010a575;
    }
    nv_close_device(lVar4,param_2);
    up(lVar4 + 0x730);
    lVar4 = find_uuid_candidate(param_1);
  } while( true );
}


// ===== 0010a4d0 nvidia_dev_get_uuid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a59b) */

int nvidia_dev_get_uuid(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = find_uuid_candidate();
  do {
    if (lVar4 == 0) {
      return -0x13;
    }
    iVar2 = nv_open_device(lVar4,param_2);
    if (iVar2 != 0) {
LAB_0010a575:
      up(lVar4 + 0x730);
      return iVar2;
    }
    if (*(char *)(lVar4 + 0x2c) == '\0') {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if ((*(long *)(lVar4 + 0x2d) == *param_1) && (*(long *)(lVar4 + 0x35) == param_1[1])) {
      iVar3 = rm_set_external_kernel_client_count(param_2,lVar4,1);
      if (iVar3 != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      goto LAB_0010a575;
    }
    nv_close_device(lVar4,param_2);
    up(lVar4 + 0x730);
    lVar4 = find_uuid_candidate(param_1);
  } while( true );
}


// ===== 0010a5b0 __pfx_nvidia_dev_put_uuid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a624) */

void __pfx_nvidia_dev_put_uuid(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = find_uuid();
  if (lVar3 == 0) {
    return;
  }
  nv_close_device(lVar3,param_2);
  iVar2 = rm_set_external_kernel_client_count(param_2,lVar3,0);
  if (iVar2 == 0) {
    up(lVar3 + 0x730);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0010a5c0 nvidia_dev_put_uuid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a624) */

void nvidia_dev_put_uuid(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = find_uuid();
  if (lVar3 == 0) {
    return;
  }
  nv_close_device(lVar3,param_2);
  iVar2 = rm_set_external_kernel_client_count(param_2,lVar3,0);
  if (iVar2 == 0) {
    up(lVar3 + 0x730);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0010a630 __pfx_nvidia_dev_block_gc6 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a695) */

undefined8 __pfx_nvidia_dev_block_gc6(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = find_uuid();
  if (lVar2 == 0) {
    uVar3 = 0xffffffed;
  }
  else {
    iVar1 = rm_ref_dynamic_power(param_2,lVar2,2);
    if (iVar1 == 0) {
      up(lVar2 + 0x730);
      uVar3 = 0;
    }
    else {
      up(lVar2 + 0x730);
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}


// ===== 0010a640 nvidia_dev_block_gc6 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a695) */

undefined8 nvidia_dev_block_gc6(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = find_uuid();
  if (lVar2 == 0) {
    uVar3 = 0xffffffed;
  }
  else {
    iVar1 = rm_ref_dynamic_power(param_2,lVar2,2);
    if (iVar1 == 0) {
      up(lVar2 + 0x730);
      uVar3 = 0;
    }
    else {
      up(lVar2 + 0x730);
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}


// ===== 0010a6c0 __pfx_nvidia_dev_unblock_gc6 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a721) */

undefined8 __pfx_nvidia_dev_unblock_gc6(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = find_uuid();
  if (lVar1 == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    rm_unref_dynamic_power(param_2,lVar1,2);
    up(lVar1 + 0x730);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0010a6d0 nvidia_dev_unblock_gc6 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a721) */

undefined8 nvidia_dev_unblock_gc6(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = find_uuid();
  if (lVar1 == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    rm_unref_dynamic_power(param_2,lVar1,2);
    up(lVar1 + 0x730);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0010a730 __pfx_nv_get_device_memory_config =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a74e) */

undefined8 __pfx_nv_get_device_memory_config(void)

{
  return 0x56;
}


// ===== 0010a740 nv_get_device_memory_config =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a74e) */

undefined8 nv_get_device_memory_config(void)

{
  return 0x56;
}


// ===== 0010a760 __pfx_nv_indicate_idle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a83b) */

undefined8 __pfx_nv_indicate_idle(long param_1)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  code *pcVar6;
  int iVar7;
  long in_GS_OFFSET;
  bool bVar8;
  undefined1 uStack_21;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_21 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  lVar4 = *(long *)(*(long *)(param_1 + 8) + 0x818);
  iVar7 = *(int *)(lVar3 + 0x1c8);
  do {
    if (iVar7 == 0) break;
    piVar1 = (int *)(lVar3 + 0x1c8);
    LOCK();
    iVar2 = *piVar1;
    bVar8 = iVar7 == iVar2;
    if (bVar8) {
      *piVar1 = iVar7 + -1;
      iVar2 = iVar7;
    }
    iVar7 = iVar2;
    UNLOCK();
  } while (!bVar8);
  plVar5 = *(long **)(*(long *)(lVar4 + 0x18) + 0x68);
  mutex_lock(plVar5 + 4);
  lVar3 = *plVar5;
  if (lVar3 != 0) {
    iVar7 = *(int *)(lVar3 + 4);
    do {
      if (iVar7 < 0) goto LAB_0010a81c;
      LOCK();
      iVar2 = *(int *)(lVar3 + 4);
      bVar8 = iVar7 == iVar2;
      if (bVar8) {
        *(int *)(lVar3 + 4) = iVar7 + 1;
        iVar2 = iVar7;
      }
      iVar7 = iVar2;
      UNLOCK();
    } while (!bVar8);
    if ((*(long *)(lVar3 + 0x40) != 0) &&
       (pcVar6 = *(code **)(*(long *)(lVar3 + 0x40) + 0x30), pcVar6 != (code *)0x0)) {
      (*pcVar6)(plVar5,&uStack_21,1,0);
    }
    LOCK();
    *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + -1;
    UNLOCK();
  }
LAB_0010a81c:
  mutex_unlock(plVar5 + 4);
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


// ===== 0010a770 nv_indicate_idle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a83b) */

undefined8 nv_indicate_idle(long param_1)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  code *pcVar6;
  int iVar7;
  long in_GS_OFFSET;
  bool bVar8;
  undefined1 local_21;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_21 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  lVar4 = *(long *)(*(long *)(param_1 + 8) + 0x818);
  iVar7 = *(int *)(lVar3 + 0x1c8);
  do {
    if (iVar7 == 0) break;
    piVar1 = (int *)(lVar3 + 0x1c8);
    LOCK();
    iVar2 = *piVar1;
    bVar8 = iVar7 == iVar2;
    if (bVar8) {
      *piVar1 = iVar7 + -1;
      iVar2 = iVar7;
    }
    iVar7 = iVar2;
    UNLOCK();
  } while (!bVar8);
  plVar5 = *(long **)(*(long *)(lVar4 + 0x18) + 0x68);
  mutex_lock(plVar5 + 4);
  lVar3 = *plVar5;
  if (lVar3 != 0) {
    iVar7 = *(int *)(lVar3 + 4);
    do {
      if (iVar7 < 0) goto LAB_0010a81c;
      LOCK();
      iVar2 = *(int *)(lVar3 + 4);
      bVar8 = iVar7 == iVar2;
      if (bVar8) {
        *(int *)(lVar3 + 4) = iVar7 + 1;
        iVar2 = iVar7;
      }
      iVar7 = iVar2;
      UNLOCK();
    } while (!bVar8);
    if ((*(long *)(lVar3 + 0x40) != 0) &&
       (pcVar6 = *(code **)(*(long *)(lVar3 + 0x40) + 0x30), pcVar6 != (code *)0x0)) {
      (*pcVar6)(plVar5,&local_21,1,0);
    }
    LOCK();
    *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + -1;
    UNLOCK();
  }
LAB_0010a81c:
  mutex_unlock(plVar5 + 4);
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


// ===== 0010a850 __pfx_nv_indicate_not_idle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a890) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_indicate_not_idle(long param_1)

{
  int *piVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 8);
  LOCK();
  piVar1 = (int *)(*(long *)(lVar2 + 0x3b0) + 0x1c8);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(undefined1 *)(lVar2 + 0x51a2) = 1;
  (*___x86_return_thunk)();
  return 0;
}


// ===== 0010a860 nv_indicate_not_idle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a890) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_indicate_not_idle(long param_1)

{
  int *piVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 8);
  LOCK();
  piVar1 = (int *)(*(long *)(lVar2 + 0x3b0) + 0x1c8);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(undefined1 *)(lVar2 + 0x51a2) = 1;
  (*___x86_return_thunk)();
  return 0;
}


// ===== 0010a8a0 __pfx_nv_idle_holdoff =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a8cb) */

void __pfx_nv_idle_holdoff(long param_1)

{
  int *piVar1;
  
  LOCK();
  piVar1 = (int *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x1c8);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return;
}


// ===== 0010a8b0 nv_idle_holdoff =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a8cb) */

void nv_idle_holdoff(long param_1)

{
  int *piVar1;
  
  LOCK();
  piVar1 = (int *)(*(long *)(*(long *)(param_1 + 8) + 0x3b0) + 0x1c8);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return;
}


// ===== 0010a8d0 __pfx_nv_dynamic_power_available =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a8f8) */

undefined8 __pfx_nv_dynamic_power_available(long param_1)

{
  return CONCAT71((int7)((ulong)*(long *)(param_1 + 8) >> 8),
                  *(long *)(*(long *)(param_1 + 8) + 0x818) != 0);
}


// ===== 0010a8e0 nv_dynamic_power_available =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a8f8) */

undefined8 nv_dynamic_power_available(long param_1)

{
  return CONCAT71((int7)((ulong)*(long *)(param_1 + 8) >> 8),
                  *(long *)(*(long *)(param_1 + 8) + 0x818) != 0);
}


// ===== 0010a900 __pfx_nv_linux_assign_minor_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a949) */
/* WARNING: Removing unreachable block (ram,0x0010a954) */

undefined8 __pfx_nv_linux_assign_minor_locked(long param_1)

{
  int iVar1;
  
  iVar1 = _find_first_zero_bit(&nv_linux_minor_bitmap,0xf8);
  if (iVar1 < 0xf8) {
    *(int *)(param_1 + 0x750) = iVar1;
    LOCK();
    (&nv_linux_minor_bitmap)[(long)iVar1 >> 3] =
         (&nv_linux_minor_bitmap)[(long)iVar1 >> 3] | '\x01' << ((long)iVar1 & 7U);
    UNLOCK();
    return 0;
  }
  return 0xffffffff;
}


// ===== 0010a910 nv_linux_assign_minor_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a949) */
/* WARNING: Removing unreachable block (ram,0x0010a954) */

undefined8 nv_linux_assign_minor_locked(long param_1)

{
  int iVar1;
  
  iVar1 = _find_first_zero_bit(&nv_linux_minor_bitmap,0xf8);
  if (iVar1 < 0xf8) {
    *(int *)(param_1 + 0x750) = iVar1;
    LOCK();
    (&nv_linux_minor_bitmap)[(long)iVar1 >> 3] =
         (&nv_linux_minor_bitmap)[(long)iVar1 >> 3] | '\x01' << ((long)iVar1 & 7U);
    UNLOCK();
    return 0;
  }
  return 0xffffffff;
}


// ===== 0010a960 __pfx_nv_linux_add_device_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a9a6) */
/* WARNING: Removing unreachable block (ram,0x0010a9b2) */

void __pfx_nv_linux_add_device_locked(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = nv_linux_devices;
  if (nv_linux_devices == 0) {
    nv_linux_devices = param_1;
    return;
  }
  do {
    lVar2 = lVar1;
    lVar1 = *(long *)(lVar2 + 0x758);
  } while (lVar1 != 0);
  *(undefined8 *)(lVar2 + 0x758) = param_1;
  return;
}


// ===== 0010a970 nv_linux_add_device_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a9a6) */
/* WARNING: Removing unreachable block (ram,0x0010a9b2) */

void nv_linux_add_device_locked(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = nv_linux_devices;
  if (nv_linux_devices == 0) {
    nv_linux_devices = param_1;
    return;
  }
  do {
    lVar2 = lVar1;
    lVar1 = *(long *)(lVar2 + 0x758);
  } while (lVar1 != 0);
  *(undefined8 *)(lVar2 + 0x758) = param_1;
  return;
}


// ===== 0010a9c0 __pfx_nv_linux_remove_minor_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a9e8) */

void __pfx_nv_linux_remove_minor_locked(long param_1)

{
  LOCK();
  (&nv_linux_minor_bitmap)[(long)(ulong)*(uint *)(param_1 + 0x750) >> 3] =
       (&nv_linux_minor_bitmap)[(long)(ulong)*(uint *)(param_1 + 0x750) >> 3] &
       ~('\x01' << ((ulong)*(uint *)(param_1 + 0x750) & 7));
  UNLOCK();
  return;
}


// ===== 0010a9d0 nv_linux_remove_minor_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010a9e8) */

void nv_linux_remove_minor_locked(long param_1)

{
  LOCK();
  (&nv_linux_minor_bitmap)[(long)(ulong)*(uint *)(param_1 + 0x750) >> 3] =
       (&nv_linux_minor_bitmap)[(long)(ulong)*(uint *)(param_1 + 0x750) >> 3] &
       ~('\x01' << ((ulong)*(uint *)(param_1 + 0x750) & 7));
  UNLOCK();
  return;
}


// ===== 0010a9f0 __pfx_nv_linux_remove_device_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010aa3d) */
/* WARNING: Removing unreachable block (ram,0x0010aa50) */

void __pfx_nv_linux_remove_device_locked(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = nv_linux_devices;
  if (nv_linux_devices == param_1) {
    nv_linux_devices = *(undefined8 *)(nv_linux_devices + 0x758);
    return;
  }
  do {
    lVar2 = lVar1;
    lVar1 = *(long *)(lVar2 + 0x758);
  } while (lVar1 != param_1);
  *(undefined8 *)(lVar2 + 0x758) = *(undefined8 *)(lVar1 + 0x758);
  return;
}


// ===== 0010aa00 nv_linux_remove_device_locked =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010aa3d) */
/* WARNING: Removing unreachable block (ram,0x0010aa50) */

void nv_linux_remove_device_locked(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = nv_linux_devices;
  if (nv_linux_devices == param_1) {
    nv_linux_devices = *(undefined8 *)(nv_linux_devices + 0x758);
    return;
  }
  do {
    lVar2 = lVar1;
    lVar1 = *(long *)(lVar2 + 0x758);
  } while (lVar1 != param_1);
  *(undefined8 *)(lVar2 + 0x758) = *(undefined8 *)(lVar1 + 0x758);
  return;
}


// ===== 0010aa60 __pfx_nv_linux_init_open_q =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010aac5) */

ulong __pfx_nv_linux_init_open_q(long param_1)

{
  ulong uVar1;
  
  uVar1 = nv_kthread_q_init(param_1 + 0x51d8,"nv_open_q");
  if ((int)uVar1 == 0) {
    down();
    *(undefined1 *)(param_1 + 0x5220) = 1;
    up(param_1 + 0x5228);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}


// ===== 0010aa70 nv_linux_init_open_q =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010aac5) */

ulong nv_linux_init_open_q(long param_1)

{
  ulong uVar1;
  
  uVar1 = nv_kthread_q_init(param_1 + 0x51d8,"nv_open_q");
  if ((int)uVar1 == 0) {
    down();
    *(undefined1 *)(param_1 + 0x5220) = 1;
    up(param_1 + 0x5228);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}


// ===== 0010aad0 __pfx_nv_linux_stop_open_q =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_linux_stop_open_q(long param_1)

{
  long lVar1;
  
  lVar1 = param_1 + 0x5228;
  down(lVar1);
  if (*(char *)(param_1 + 0x5220) == '\0') {
    up(lVar1);
    return;
  }
  *(undefined1 *)(param_1 + 0x5220) = 0;
  up(lVar1);
  nv_kthread_q_stop(param_1 + 0x51d8);
  return;
}


// ===== 0010aae0 nv_linux_stop_open_q =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_linux_stop_open_q(long param_1)

{
  long lVar1;
  
  lVar1 = param_1 + 0x5228;
  down(lVar1);
  if (*(char *)(param_1 + 0x5220) == '\0') {
    up(lVar1);
    return;
  }
  *(undefined1 *)(param_1 + 0x5220) = 0;
  up(lVar1);
  nv_kthread_q_stop(param_1 + 0x51d8);
  return;
}


// ===== 0010ab30 __pfx_nv_control_soc_irqs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_control_soc_irqs(long param_1,char param_2)

{
  long lVar1;
  undefined8 uVar2;
  int *piVar3;
  uint uVar4;
  
  lVar1 = *(long *)(param_1 + 8) + 0x514c;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  if (param_2 == '\0') {
    piVar3 = (int *)(param_1 + 0x1c8);
    uVar4 = 0;
    if (*(int *)(param_1 + 0x284) != 0) {
      do {
        if (*piVar3 == 1) {
          *piVar3 = 0;
          disable_irq_nosync(piVar3[-4]);
        }
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 5;
      } while (uVar4 < *(uint *)(param_1 + 0x284));
    }
  }
  else if (*(int *)(param_1 + 0x284) != 0) {
    piVar3 = (int *)(param_1 + 0x1c8);
    uVar4 = 0;
    do {
      if (*piVar3 == 0) {
        *piVar3 = 1;
        enable_irq(piVar3[-4]);
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 5;
    } while (uVar4 < *(uint *)(param_1 + 0x284));
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar2);
  return;
}


// ===== 0010ab40 nv_control_soc_irqs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_control_soc_irqs(long param_1,char param_2)

{
  long lVar1;
  undefined8 uVar2;
  int *piVar3;
  uint uVar4;
  
  lVar1 = *(long *)(param_1 + 8) + 0x514c;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  if (param_2 == '\0') {
    piVar3 = (int *)(param_1 + 0x1c8);
    uVar4 = 0;
    if (*(int *)(param_1 + 0x284) != 0) {
      do {
        if (*piVar3 == 1) {
          *piVar3 = 0;
          disable_irq_nosync(piVar3[-4]);
        }
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 5;
      } while (uVar4 < *(uint *)(param_1 + 0x284));
    }
  }
  else if (*(int *)(param_1 + 0x284) != 0) {
    piVar3 = (int *)(param_1 + 0x1c8);
    uVar4 = 0;
    do {
      if (*piVar3 == 0) {
        *piVar3 = 1;
        enable_irq(piVar3[-4]);
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 5;
    } while (uVar4 < *(uint *)(param_1 + 0x284));
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar2);
  return;
}


// ===== 0010ac30 __pfx_nv_get_dev_minor =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ac53) */

undefined4 __pfx_nv_get_dev_minor(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 8) + 0x750);
}


// ===== 0010ac40 nv_get_dev_minor =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ac53) */

undefined4 nv_get_dev_minor(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 8) + 0x750);
}


// ===== 0010ac60 __pfx_nv_acquire_fabric_mgmt_cap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ac8d) */

uint __pfx_nv_acquire_fabric_mgmt_cap(undefined8 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = nvlink_cap_acquire(param_1,0);
  *param_2 = iVar1;
  return iVar1 >> 0x1f & 0x1b;
}


// ===== 0010ac70 nv_acquire_fabric_mgmt_cap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ac8d) */

uint nv_acquire_fabric_mgmt_cap(undefined8 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = nvlink_cap_acquire(param_1,0);
  *param_2 = iVar1;
  return iVar1 >> 0x1f & 0x1b;
}


// ===== 0010aca0 __pfx_nv_audio_dynamic_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x0010acf6) */

void __pfx_nv_audio_dynamic_power(long param_1)

{
  long lVar1;
  long lVar2;
  long in_GS_OFFSET;
  undefined4 uStack_14;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x10acb9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  if ((((*(undefined **)(lVar2 + 0x60) == &pci_bus_type) &&
       (lVar2 = os_pci_init_handle(**(undefined4 **)(*(long *)(lVar2 + -0xc0) + 200),
                                   *(undefined1 *)(*(long *)(lVar2 + -0xc0) + 0xd8),
                                   (byte)*(undefined4 *)(lVar2 + -0x98) >> 3,1,0,0), lVar2 != 0)) &&
      ((*(byte *)(lVar2 + 0x1b4) & 0x10) == 0)) && (lVar2 = *(long *)(lVar2 + 0x148), lVar2 != 0)) {
    lVar1 = *(long *)(lVar2 + 0x1a8);
    uStack_14 = 0;
    for (; lVar1 != lVar2 + 0x1a0; lVar1 = *(long *)(lVar1 + 8)) {
      if (*(int *)(lVar1 + 0x1c) == 3) {
        lVar2 = *(long *)(lVar1 + 0x20);
        if (((*(long *)(lVar2 + 0x370) != 0) && (lVar2 != 0)) &&
           ((*(int *)(lVar2 + 0x1dc) == 2 && ((*(byte *)(lVar2 + 0x1d0) & 7) == 0)))) {
          (**(code **)(lVar2 + 0x370))(lVar2,*(int *)(lVar2 + 0x3f8) << 0x1c | 0xf0000,0,&uStack_14)
          ;
        }
        break;
      }
    }
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010acb0 nv_audio_dynamic_power =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Removing unreachable block (ram,0x0010acf6) */

void nv_audio_dynamic_power(long param_1)

{
  long lVar1;
  long lVar2;
  long in_GS_OFFSET;
  undefined4 local_14;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x10acb9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  if ((((*(undefined **)(lVar2 + 0x60) == &pci_bus_type) &&
       (lVar2 = os_pci_init_handle(**(undefined4 **)(*(long *)(lVar2 + -0xc0) + 200),
                                   *(undefined1 *)(*(long *)(lVar2 + -0xc0) + 0xd8),
                                   (byte)*(undefined4 *)(lVar2 + -0x98) >> 3,1,0,0), lVar2 != 0)) &&
      ((*(byte *)(lVar2 + 0x1b4) & 0x10) == 0)) && (lVar2 = *(long *)(lVar2 + 0x148), lVar2 != 0)) {
    lVar1 = *(long *)(lVar2 + 0x1a8);
    local_14 = 0;
    for (; lVar1 != lVar2 + 0x1a0; lVar1 = *(long *)(lVar1 + 8)) {
      if (*(int *)(lVar1 + 0x1c) == 3) {
        lVar2 = *(long *)(lVar1 + 0x20);
        if (((*(long *)(lVar2 + 0x370) != 0) && (lVar2 != 0)) &&
           ((*(int *)(lVar2 + 0x1dc) == 2 && ((*(byte *)(lVar2 + 0x1d0) & 7) == 0)))) {
          (**(code **)(lVar2 + 0x370))(lVar2,*(int *)(lVar2 + 0x3f8) << 0x1c | 0xf0000,0,&local_14);
        }
        break;
      }
    }
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010adf0 __pfx_nv_match_gpu_os_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ae1a) */
/* WARNING: Removing unreachable block (ram,0x0010ae3b) */

undefined8 __pfx_nv_match_gpu_os_info(long param_1,long param_2)

{
  long lVar1;
  
  if ((((param_2 != 0) && (*(undefined1 **)(param_2 + 8) == nvidia_fops)) &&
      (*(long *)(param_2 + 0x18) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x80), lVar1 != 0)) {
    return CONCAT71((int7)((ulong)lVar1 >> 8),*(long *)(param_1 + 8) == lVar1);
  }
  return 0;
}


// ===== 0010ae00 nv_match_gpu_os_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ae1a) */
/* WARNING: Removing unreachable block (ram,0x0010ae3b) */

undefined8 nv_match_gpu_os_info(long param_1,long param_2)

{
  long lVar1;
  
  if ((((param_2 != 0) && (*(undefined1 **)(param_2 + 8) == nvidia_fops)) &&
      (*(long *)(param_2 + 0x18) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x80), lVar1 != 0)) {
    return CONCAT71((int7)((ulong)lVar1 >> 8),*(long *)(param_1 + 8) == lVar1);
  }
  return 0;
}


// ===== 0010ae40 __pfx_nv_is_gpu_accessible =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ae7f) */

bool __pfx_nv_is_gpu_accessible(long param_1)

{
  int iVar1;
  undefined8 in_R8;
  undefined8 in_R9;
  long in_GS_OFFSET;
  
  iVar1 = iterate_fd(*(undefined8 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd90),0,
                     nv_match_dev_state,*(undefined8 *)(param_1 + 8),in_R8,in_R9,0x10ae59);
  return iVar1 != 0;
}


// ===== 0010ae50 nv_is_gpu_accessible =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ae7f) */

bool nv_is_gpu_accessible(long param_1)

{
  int iVar1;
  undefined8 in_R8;
  undefined8 in_R9;
  long in_GS_OFFSET;
  
  iVar1 = iterate_fd(*(undefined8 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd90),0,
                     nv_match_dev_state,*(undefined8 *)(param_1 + 8),in_R8,in_R9,0x10ae59);
  return iVar1 != 0;
}


// ===== 0010ae90 __pfx_nv_platform_supports_s0ix =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010aeb6) */

byte __pfx_nv_platform_supports_s0ix(void)

{
  return DAT_00f79b02 >> 5 & 1;
}


// ===== 0010aea0 nv_platform_supports_s0ix =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010aeb6) */

byte nv_platform_supports_s0ix(void)

{
  return DAT_00f79b02 >> 5 & 1;
}


// ===== 0010aec0 __pfx_nv_s2idle_pm_configured =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010afac) */

undefined8 __pfx_nv_s2idle_pm_configured(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long in_GS_OFFSET;
  long lStack_88;
  long *plStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  long alStack_48 [8];
  undefined8 uStack_8;
  
  uStack_8 = 0x10aed9;
  alStack_48[7] = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  plStack_80 = alStack_48 + 6;
  alStack_48[6] = 0;
  lStack_88 = 0;
  alStack_48[0] = 0;
  alStack_48[1] = 0;
  alStack_48[2] = 0;
  alStack_48[3] = 0;
  alStack_48[4] = 0;
  alStack_48[5] = 0;
  uStack_70 = 0;
  uStack_68 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_78 = 8;
  iVar2 = os_open_readonly_file("/sys/power/mem_sleep",&lStack_88);
  if (iVar2 == 0) {
    alStack_48[1] = 0;
    alStack_48[2] = 0;
    alStack_48[3] = 0;
    alStack_48[5] = 0;
    uVar1 = *(uint *)(lStack_88 + 0x28);
    alStack_48[0] = lStack_88;
    uVar3 = uVar1 >> 6 & 0x10;
    if ((uVar1 & 0x4000) != 0) {
      uVar3 = uVar3 | 0x20000;
    }
    if ((uVar1 & 0x1000) != 0) {
      uVar3 = uVar3 | 2;
    }
    if ((uVar1 & 0x100000) != 0) {
      uVar3 = uVar3 | 4;
    }
    alStack_48[4] = (long)uVar3;
    iov_iter_kvec(&uStack_70,0,&plStack_80,1,8);
    lVar4 = seq_read_iter(alStack_48,&uStack_70);
    os_close_file(lStack_88);
    if (lVar4 == 8) {
      uVar5 = CONCAT71(0x5d656c64693273,alStack_48[6] == 0x5d656c646932735b);
      goto LAB_0010af8f;
    }
  }
  uVar5 = 0;
LAB_0010af8f:
  if (alStack_48[7] == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010aed0 nv_s2idle_pm_configured =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010afac) */

undefined8 nv_s2idle_pm_configured(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long in_GS_OFFSET;
  long local_88;
  long *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48 [8];
  undefined8 uStack_8;
  
  uStack_8 = 0x10aed9;
  local_48[7] = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_80 = local_48 + 6;
  local_48[6] = 0;
  local_88 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_78 = 8;
  iVar2 = os_open_readonly_file("/sys/power/mem_sleep",&local_88);
  if (iVar2 == 0) {
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[5] = 0;
    uVar1 = *(uint *)(local_88 + 0x28);
    local_48[0] = local_88;
    uVar3 = uVar1 >> 6 & 0x10;
    if ((uVar1 & 0x4000) != 0) {
      uVar3 = uVar3 | 0x20000;
    }
    if ((uVar1 & 0x1000) != 0) {
      uVar3 = uVar3 | 2;
    }
    if ((uVar1 & 0x100000) != 0) {
      uVar3 = uVar3 | 4;
    }
    local_48[4] = (long)uVar3;
    iov_iter_kvec(&local_70,0,&local_80,1,8);
    lVar4 = seq_read_iter(local_48,&local_70);
    os_close_file(local_88);
    if (lVar4 == 8) {
      uVar5 = CONCAT71(0x5d656c64693273,local_48[6] == 0x5d656c646932735b);
      goto LAB_0010af8f;
    }
  }
  uVar5 = 0;
LAB_0010af8f:
  if (local_48[7] == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010b080 __pfx_nv_pci_tegra_register_power_domain =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b0ce) */
/* WARNING: Removing unreachable block (ram,0x0010b116) */

undefined8 __pfx_nv_pci_tegra_register_power_domain(long param_1,char param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (param_2 != '\0') {
    if (*(long *)(lVar1 + 0x378) == 0) {
      nv_printf(3,"NVRM: No dt node associated with this device\n");
    }
    else {
      nv_printf(3,"NVRM: No power-domains is defined in the dt node\n");
    }
    return 0;
  }
  nv_printf(0,"NVRM: Detaching device to GPU power domain \n");
  dev_pm_domain_detach(lVar1 + 0xd0,1);
  return 1;
}


// ===== 0010b090 nv_pci_tegra_register_power_domain =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b0ce) */
/* WARNING: Removing unreachable block (ram,0x0010b116) */

undefined8 nv_pci_tegra_register_power_domain(long param_1,char param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (param_2 != '\0') {
    if (*(long *)(lVar1 + 0x378) == 0) {
      nv_printf(3,"NVRM: No dt node associated with this device\n");
    }
    else {
      nv_printf(3,"NVRM: No power-domains is defined in the dt node\n");
    }
    return 0;
  }
  nv_printf(0,"NVRM: Detaching device to GPU power domain \n");
  dev_pm_domain_detach(lVar1 + 0xd0,1);
  return 1;
}


// ===== 0010b120 __pfx_nv_pci_tegra_pm_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b150) */
/* WARNING: Removing unreachable block (ram,0x0010b172) */

undefined8 __pfx_nv_pci_tegra_pm_init(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (*(long *)(lVar1 + 0x300) == 0) {
    if (*(long *)(lVar1 + 0x378) != 0) {
      nv_printf(3,"NVRM: No power-domains is defined in the dt node\n");
      return 0;
    }
    nv_printf(3,"NVRM: No dt node associated with this device\n");
  }
  return 0;
}


// ===== 0010b130 nv_pci_tegra_pm_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b150) */
/* WARNING: Removing unreachable block (ram,0x0010b172) */

undefined8 nv_pci_tegra_pm_init(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (*(long *)(lVar1 + 0x300) == 0) {
    if (*(long *)(lVar1 + 0x378) != 0) {
      nv_printf(3,"NVRM: No power-domains is defined in the dt node\n");
      return 0;
    }
    nv_printf(3,"NVRM: No dt node associated with this device\n");
  }
  return 0;
}


// ===== 0010b190 __pfx_nv_pci_tegra_pm_deinit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b262) */

void __pfx_nv_pci_tegra_pm_deinit(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (*(long *)(lVar3 + 0x300) != 0) {
    lVar1 = *(long *)(lVar3 + 0x10);
    __pm_runtime_use_autosuspend(lVar3 + 0xd0,0);
    do {
      lVar3 = lVar1;
      lVar1 = *(long *)(lVar3 + 0x10);
    } while (lVar1 != 0);
    uVar2 = *(undefined8 *)(*(long *)(lVar3 + 0x110) + 0x40);
    nv_printf(0,"NVRM: Disable runtime PM for PCIe Controller\n");
    __pm_runtime_disable(uVar2,1);
    lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
    nv_printf(0,"NVRM: Detaching device to GPU power domain \n");
    dev_pm_domain_detach(lVar3 + 0xd0,1);
    return;
  }
  return;
}


// ===== 0010b1a0 nv_pci_tegra_pm_deinit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b262) */

void nv_pci_tegra_pm_deinit(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  if (*(long *)(lVar3 + 0x300) != 0) {
    lVar1 = *(long *)(lVar3 + 0x10);
    __pm_runtime_use_autosuspend(lVar3 + 0xd0,0);
    do {
      lVar3 = lVar1;
      lVar1 = *(long *)(lVar3 + 0x10);
    } while (lVar1 != 0);
    uVar2 = *(undefined8 *)(*(long *)(lVar3 + 0x110) + 0x40);
    nv_printf(0,"NVRM: Disable runtime PM for PCIe Controller\n");
    __pm_runtime_disable(uVar2,1);
    lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
    nv_printf(0,"NVRM: Detaching device to GPU power domain \n");
    dev_pm_domain_detach(lVar3 + 0xd0,1);
    return;
  }
  return;
}


// ===== 0010b270 __pfx_nv_is_chassis_notebook =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b2c2) */
/* WARNING: Removing unreachable block (ram,0x0010b2dc) */

undefined8 __pfx_nv_is_chassis_notebook(void)

{
  int iVar1;
  char *__s1;
  undefined8 uVar2;
  undefined4 extraout_var;
  
  __s1 = (char *)dmi_get_system_info(0x13);
  uVar2 = 0;
  if (__s1 != (char *)0x0) {
    iVar1 = strcmp(__s1,"9");
    uVar2 = 1;
    if (iVar1 != 0) {
      iVar1 = strcmp(__s1,"10");
      return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
    }
  }
  return uVar2;
}


// ===== 0010b280 nv_is_chassis_notebook =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b2c2) */
/* WARNING: Removing unreachable block (ram,0x0010b2dc) */

undefined8 nv_is_chassis_notebook(void)

{
  int iVar1;
  char *__s1;
  undefined8 uVar2;
  undefined4 extraout_var;
  
  __s1 = (char *)dmi_get_system_info(0x13);
  uVar2 = 0;
  if (__s1 != (char *)0x0) {
    iVar1 = strcmp(__s1,"9");
    uVar2 = 1;
    if (iVar1 != 0) {
      iVar1 = strcmp(__s1,"10");
      return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
    }
  }
  return uVar2;
}


// ===== 0010b2f0 __pfx_nv_allow_runtime_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_allow_runtime_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  bool bVar4;
  
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  _raw_spin_lock_irq(lVar2 + 0xec);
  if (-1 < (char)*(byte *)(lVar2 + 0x1d0)) {
    *(byte *)(lVar2 + 0x1d0) = *(byte *)(lVar2 + 0x1d0) | 0x80;
    iVar3 = *(int *)(lVar2 + 0x1c8);
    do {
      if (iVar3 == 0) break;
      LOCK();
      iVar1 = *(int *)(lVar2 + 0x1c8);
      bVar4 = iVar3 == iVar1;
      if (bVar4) {
        *(int *)(lVar2 + 0x1c8) = iVar3 + -1;
        iVar1 = iVar3;
      }
      iVar3 = iVar1;
      UNLOCK();
    } while (!bVar4);
  }
  _raw_spin_unlock_irq(lVar2 + 0xec);
  return;
}


// ===== 0010b300 nv_allow_runtime_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_allow_runtime_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  bool bVar4;
  
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  _raw_spin_lock_irq(lVar2 + 0xec);
  if (-1 < (char)*(byte *)(lVar2 + 0x1d0)) {
    *(byte *)(lVar2 + 0x1d0) = *(byte *)(lVar2 + 0x1d0) | 0x80;
    iVar3 = *(int *)(lVar2 + 0x1c8);
    do {
      if (iVar3 == 0) break;
      LOCK();
      iVar1 = *(int *)(lVar2 + 0x1c8);
      bVar4 = iVar3 == iVar1;
      if (bVar4) {
        *(int *)(lVar2 + 0x1c8) = iVar3 + -1;
        iVar1 = iVar3;
      }
      iVar3 = iVar1;
      UNLOCK();
    } while (!bVar4);
  }
  _raw_spin_unlock_irq(lVar2 + 0xec);
  return;
}


// ===== 0010b360 __pfx_nv_disallow_runtime_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_disallow_runtime_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  _raw_spin_lock_irq(lVar1 + 0xec);
  if (*(char *)(lVar1 + 0x1d0) < '\0') {
    *(byte *)(lVar1 + 0x1d0) = *(byte *)(lVar1 + 0x1d0) & 0x7f;
    LOCK();
    *(int *)(lVar1 + 0x1c8) = *(int *)(lVar1 + 0x1c8) + 1;
    UNLOCK();
  }
  _raw_spin_unlock_irq(lVar1 + 0xec);
  return;
}


// ===== 0010b370 nv_disallow_runtime_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_disallow_runtime_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 0x3b0);
  _raw_spin_lock_irq(lVar1 + 0xec);
  if (*(char *)(lVar1 + 0x1d0) < '\0') {
    *(byte *)(lVar1 + 0x1d0) = *(byte *)(lVar1 + 0x1d0) & 0x7f;
    LOCK();
    *(int *)(lVar1 + 0x1c8) = *(int *)(lVar1 + 0x1c8) + 1;
    UNLOCK();
  }
  _raw_spin_unlock_irq(lVar1 + 0xec);
  return;
}


// ===== 0010b3c0 __pfx_nv_flush_coherent_cpu_cache_range =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b3d9) */

void __pfx_nv_flush_coherent_cpu_cache_range(void)

{
  return;
}


// ===== 0010b3d0 nv_flush_coherent_cpu_cache_range =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b3d9) */

void nv_flush_coherent_cpu_cache_range(void)

{
  return;
}


// ===== 0010b3e0 __pfx_nv_get_updated_emu_seg =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b472) */
/* WARNING: Removing unreachable block (ram,0x0010b499) */
/* WARNING: Removing unreachable block (ram,0x0010b435) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_get_updated_emu_seg(uint *param_1,uint *param_2)

{
  ulong *puVar1;
  uint uVar2;
  ulong *puVar3;
  uint uVar4;
  
  uVar2 = *param_2;
  uVar4 = *param_1;
  puVar1 = _memory_failure_queue;
  if (uVar4 < uVar2) {
    while (puVar1 != (ulong *)0x0) {
      while( true ) {
        puVar3 = puVar1;
        if ((ulong)uVar2 < *puVar3) {
          return;
        }
        if (puVar3[1] < (ulong)uVar4) goto LAB_0010b440;
        if (puVar3[1] <= (ulong)uVar2) break;
        puVar1 = (ulong *)puVar3[7];
        if ((ulong *)puVar3[7] == (ulong *)0x0) {
          if ((*(byte *)((long)puVar3 + 0x19) & 2) != 0) goto LAB_0010b47d;
          while (puVar1 = (ulong *)puVar3[6], (ulong *)puVar3[6] == (ulong *)0x0) {
            puVar3 = (ulong *)puVar3[5];
            if (puVar3 == (ulong *)0x0) {
              return;
            }
          }
        }
      }
      if ((*(byte *)((long)puVar3 + 0x19) & 2) != 0) {
LAB_0010b47d:
        if ((ulong)uVar4 < *puVar3) {
          uVar4 = (uint)*puVar3;
        }
        *param_1 = uVar4;
        uVar2 = *param_2;
        if (puVar3[1] < (ulong)uVar2) {
          uVar2 = (uint)puVar3[1];
        }
        *param_2 = uVar2;
        return;
      }
LAB_0010b440:
      puVar1 = (ulong *)puVar3[7];
    }
  }
  return;
}


// ===== 0010b3f0 nv_get_updated_emu_seg =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b472) */
/* WARNING: Removing unreachable block (ram,0x0010b499) */
/* WARNING: Removing unreachable block (ram,0x0010b435) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_get_updated_emu_seg(uint *param_1,uint *param_2)

{
  ulong *puVar1;
  uint uVar2;
  ulong *puVar3;
  uint uVar4;
  
  uVar2 = *param_2;
  uVar4 = *param_1;
  puVar1 = _memory_failure_queue;
  if (uVar4 < uVar2) {
    while (puVar1 != (ulong *)0x0) {
      while( true ) {
        puVar3 = puVar1;
        if ((ulong)uVar2 < *puVar3) {
          return;
        }
        if (puVar3[1] < (ulong)uVar4) goto LAB_0010b440;
        if (puVar3[1] <= (ulong)uVar2) break;
        puVar1 = (ulong *)puVar3[7];
        if ((ulong *)puVar3[7] == (ulong *)0x0) {
          if ((*(byte *)((long)puVar3 + 0x19) & 2) != 0) goto LAB_0010b47d;
          while (puVar1 = (ulong *)puVar3[6], (ulong *)puVar3[6] == (ulong *)0x0) {
            puVar3 = (ulong *)puVar3[5];
            if (puVar3 == (ulong *)0x0) {
              return;
            }
          }
        }
      }
      if ((*(byte *)((long)puVar3 + 0x19) & 2) != 0) {
LAB_0010b47d:
        if ((ulong)uVar4 < *puVar3) {
          uVar4 = (uint)*puVar3;
        }
        *param_1 = uVar4;
        uVar2 = *param_2;
        if (puVar3[1] < (ulong)uVar2) {
          uVar2 = (uint)puVar3[1];
        }
        *param_2 = uVar2;
        return;
      }
LAB_0010b440:
      puVar1 = (ulong *)puVar3[7];
    }
  }
  return;
}


// ===== 0010b4a0 __pfx_nv_get_egm_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b68e) */

undefined8
__pfx_nv_get_egm_info(long param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 uStack_50;
  undefined8 uStack_48;
  ulong uStack_40;
  long lStack_38;
  
  lVar1 = *(long *)(param_1 + 8);
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  iVar2 = device_property_read_u64_array
                    (*(undefined8 *)(lVar1 + 0x3b0),"nvidia,egm-pxm",&uStack_40,1);
  if (iVar2 == 0) {
    iVar2 = device_property_read_u64_array
                      (*(undefined8 *)(lVar1 + 0x3b0),"nvidia,egm-base-pa",&uStack_50,1);
    if (iVar2 == 0) {
      iVar2 = device_property_read_u64_array
                        (*(undefined8 *)(lVar1 + 0x3b0),"nvidia,egm-size",&uStack_48,1);
      if (iVar2 == 0) {
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: DSD properties: \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: \tEGM base PA: 0x%llx \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),uStack_50);
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: \tEGM size: 0x%llx \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),uStack_48);
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: \tEGM _PXM: 0x%llx \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),uStack_40);
        if (param_4 != (undefined4 *)0x0) {
          uVar3 = pxm_to_node(uStack_40 & 0xffffffff);
          *param_4 = uVar3;
          nv_printf(0,"EGM node id: %d\n",uVar3);
        }
        if (param_2 != (undefined8 *)0x0) {
          *param_2 = uStack_50;
          nv_printf(0,"EGM base addr: 0x%llx\n");
        }
        if (param_3 != (undefined8 *)0x0) {
          *param_3 = uStack_48;
          nv_printf(0,"EGM size: 0x%llx\n");
        }
        uVar4 = 0;
        goto LAB_0010b673;
      }
    }
  }
  nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Cannot get EGM info\n",*(undefined4 *)(param_1 + 0x14),
            *(undefined1 *)(param_1 + 0x18),*(undefined1 *)(param_1 + 0x19),
            *(undefined1 *)(param_1 + 0x1a));
  uVar4 = 0x56;
LAB_0010b673:
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010b4b0 nv_get_egm_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b68e) */

undefined8 nv_get_egm_info(long param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  long local_38;
  
  lVar1 = *(long *)(param_1 + 8);
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  iVar2 = device_property_read_u64_array
                    (*(undefined8 *)(lVar1 + 0x3b0),"nvidia,egm-pxm",&local_40,1);
  if (iVar2 == 0) {
    iVar2 = device_property_read_u64_array
                      (*(undefined8 *)(lVar1 + 0x3b0),"nvidia,egm-base-pa",&local_50,1);
    if (iVar2 == 0) {
      iVar2 = device_property_read_u64_array
                        (*(undefined8 *)(lVar1 + 0x3b0),"nvidia,egm-size",&local_48,1);
      if (iVar2 == 0) {
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: DSD properties: \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: \tEGM base PA: 0x%llx \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),local_50);
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: \tEGM size: 0x%llx \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),local_48);
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: \tEGM _PXM: 0x%llx \n",
                  *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
                  *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),local_40);
        if (param_4 != (undefined4 *)0x0) {
          uVar3 = pxm_to_node(local_40 & 0xffffffff);
          *param_4 = uVar3;
          nv_printf(0,"EGM node id: %d\n",uVar3);
        }
        if (param_2 != (undefined8 *)0x0) {
          *param_2 = local_50;
          nv_printf(0,"EGM base addr: 0x%llx\n");
        }
        if (param_3 != (undefined8 *)0x0) {
          *param_3 = local_48;
          nv_printf(0,"EGM size: 0x%llx\n");
        }
        uVar4 = 0;
        goto LAB_0010b673;
      }
    }
  }
  nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Cannot get EGM info\n",*(undefined4 *)(param_1 + 0x14),
            *(undefined1 *)(param_1 + 0x18),*(undefined1 *)(param_1 + 0x19),
            *(undefined1 *)(param_1 + 0x1a));
  uVar4 = 0x56;
LAB_0010b673:
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010b6a0 __pfx_nv_get_screen_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b7a7) */

void __pfx_nv_get_screen_info
               (long param_1,long *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5,undefined4 *param_6)

{
  byte bVar1;
  long lVar2;
  long *plVar3;
  char *__s;
  byte bVar4;
  int iVar5;
  size_t sVar6;
  char cVar7;
  ulong uVar8;
  char cVar9;
  long *unaff_retaddr;
  
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  *param_2 = 0;
  *unaff_retaddr = 0;
  *param_6 = 0;
  *param_5 = 0;
  *param_4 = 0;
  *param_3 = 0;
  if ((lVar2 == 0) || ((*(byte *)(param_1 + 0x11) & 2) != 0)) {
    return;
  }
  cVar9 = '\x01';
  do {
    cVar7 = '\0';
    bVar4 = 0;
    do {
      uVar8 = (ulong)bVar4;
      bVar1 = bVar4 + 2;
      bVar4 = bVar4 + 1;
      if ((*(byte *)(lVar2 + 0x408 + uVar8 * 0x40) & 4) != 0) {
        bVar4 = bVar1;
      }
      cVar7 = cVar7 + '\x01';
    } while (cVar7 != cVar9);
    plVar3 = *(long **)(lVar2 + 0x428 + (ulong)bVar4 * 0x40);
    if ((plVar3 != (long *)0x0) &&
       ((*plVar3 == *(long *)(param_1 + 0xb8) || (*plVar3 == *(long *)(param_1 + 0xe0) + 0x1000000))
       )) {
      __s = (char *)plVar3[2];
      sVar6 = strlen(__s);
      if ((2 < (uint)sVar6) &&
         (iVar5 = strcasecmp(__s + ((sVar6 & 0xffffffff) - 2),"fb"), iVar5 == 0)) {
        lVar2 = *plVar3;
        *param_2 = lVar2;
        *unaff_retaddr = (plVar3[1] + 1) - lVar2;
        return;
      }
    }
    if (cVar9 == '\x02') {
      return;
    }
    cVar9 = '\x02';
  } while( true );
}


// ===== 0010b6b0 nv_get_screen_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b7a7) */

void nv_get_screen_info(long param_1,long *param_2,undefined4 *param_3,undefined4 *param_4,
                       undefined4 *param_5,undefined4 *param_6)

{
  byte bVar1;
  long lVar2;
  long *plVar3;
  char *__s;
  byte bVar4;
  int iVar5;
  size_t sVar6;
  char cVar7;
  ulong uVar8;
  char cVar9;
  long *unaff_retaddr;
  
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0x3b8);
  *param_2 = 0;
  *unaff_retaddr = 0;
  *param_6 = 0;
  *param_5 = 0;
  *param_4 = 0;
  *param_3 = 0;
  if ((lVar2 == 0) || ((*(byte *)(param_1 + 0x11) & 2) != 0)) {
    return;
  }
  cVar9 = '\x01';
  do {
    cVar7 = '\0';
    bVar4 = 0;
    do {
      uVar8 = (ulong)bVar4;
      bVar1 = bVar4 + 2;
      bVar4 = bVar4 + 1;
      if ((*(byte *)(lVar2 + 0x408 + uVar8 * 0x40) & 4) != 0) {
        bVar4 = bVar1;
      }
      cVar7 = cVar7 + '\x01';
    } while (cVar7 != cVar9);
    plVar3 = *(long **)(lVar2 + 0x428 + (ulong)bVar4 * 0x40);
    if ((plVar3 != (long *)0x0) &&
       ((*plVar3 == *(long *)(param_1 + 0xb8) || (*plVar3 == *(long *)(param_1 + 0xe0) + 0x1000000))
       )) {
      __s = (char *)plVar3[2];
      sVar6 = strlen(__s);
      if ((2 < (uint)sVar6) &&
         (iVar5 = strcasecmp(__s + ((sVar6 & 0xffffffff) - 2),"fb"), iVar5 == 0)) {
        lVar2 = *plVar3;
        *param_2 = lVar2;
        *unaff_retaddr = (plVar3[1] + 1) - lVar2;
        return;
      }
    }
    if (cVar9 == '\x02') {
      return;
    }
    cVar9 = '\x02';
  } while( true );
}


// ===== 0010b860 __pfx_nv_set_gpu_pg_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b967) */

void __pfx_nv_set_gpu_pg_mask(long param_1)

{
  int iVar1;
  long in_GS_OFFSET;
  undefined4 uStack_30;
  int iStack_2c;
  undefined8 uStack_28;
  int iStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_20 = 0;
  uStack_28 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  if ((*(char *)(param_1 + 0x2b2) == '\0') || ((*(byte *)(param_1 + 0x11) & 8) != 0)) {
    nv_printf(0,"NVRM: gpu_pg_mask is not supported.\n");
  }
  else {
    if (NVreg_TegraGpuPgMask == -1) {
      iVar1 = *(int *)(param_1 + 0x2b4);
    }
    else {
      *(int *)(param_1 + 0x2b4) = NVreg_TegraGpuPgMask;
      nv_printf(0,"NVRM: overlay gpu_pg_mask with module parameter %u.\n");
      iVar1 = *(int *)(param_1 + 0x2b4);
    }
    if (iVar1 == -1) {
      nv_printf(0,"NVRM: Using default gpu_pg_mask. There\'s no need to send BPMP MRQ.\n");
    }
    else {
      uStack_28 = 0x100000001;
      iStack_20 = iVar1;
      iVar1 = nv_bpmp_send_mrq(param_1,0x44,&uStack_28,0xc,0,0);
      if (iVar1 == 0) {
        if (iStack_2c == 0) {
          nv_printf(0,"NVRM: set gpu_pg_mask %d success\n",*(undefined4 *)(param_1 + 0x2b4));
        }
        else {
          nv_printf(4,"NVRM: BPMP call for gpu_pg_mask %d failed, rv = %d\n",
                    *(undefined4 *)(param_1 + 0x2b4));
        }
      }
      else {
        nv_printf(4,"NVRM: failed to call bpmp_send_mrq\n",&uStack_30,&iStack_2c);
      }
    }
  }
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010b870 nv_set_gpu_pg_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010b967) */

void nv_set_gpu_pg_mask(long param_1)

{
  int iVar1;
  long in_GS_OFFSET;
  undefined4 local_30;
  int local_2c;
  undefined8 local_28;
  int local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  local_28 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((*(char *)(param_1 + 0x2b2) == '\0') || ((*(byte *)(param_1 + 0x11) & 8) != 0)) {
    nv_printf(0,"NVRM: gpu_pg_mask is not supported.\n");
  }
  else {
    if (NVreg_TegraGpuPgMask == -1) {
      iVar1 = *(int *)(param_1 + 0x2b4);
    }
    else {
      *(int *)(param_1 + 0x2b4) = NVreg_TegraGpuPgMask;
      nv_printf(0,"NVRM: overlay gpu_pg_mask with module parameter %u.\n");
      iVar1 = *(int *)(param_1 + 0x2b4);
    }
    if (iVar1 == -1) {
      nv_printf(0,"NVRM: Using default gpu_pg_mask. There\'s no need to send BPMP MRQ.\n");
    }
    else {
      local_28 = 0x100000001;
      local_20 = iVar1;
      iVar1 = nv_bpmp_send_mrq(param_1,0x44,&local_28,0xc,0,0);
      if (iVar1 == 0) {
        if (local_2c == 0) {
          nv_printf(0,"NVRM: set gpu_pg_mask %d success\n",*(undefined4 *)(param_1 + 0x2b4));
        }
        else {
          nv_printf(4,"NVRM: BPMP call for gpu_pg_mask %d failed, rv = %d\n",
                    *(undefined4 *)(param_1 + 0x2b4));
        }
      }
      else {
        nv_printf(4,"NVRM: failed to call bpmp_send_mrq\n",&local_30,&local_2c);
      }
    }
  }
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010ba00 __pfx_nv_trigger_gpu_flr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_trigger_gpu_flr(long param_1)

{
  os_pci_trigger_flr(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b8));
  return;
}


// ===== 0010ba10 nv_trigger_gpu_flr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_trigger_gpu_flr(long param_1)

{
  os_pci_trigger_flr(*(undefined8 *)(*(long *)(param_1 + 8) + 0x3b8));
  return;
}


// ===== 0010ba40 __pfx_nv_pci_gb10b_device_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ba59) */

void __pfx_nv_pci_gb10b_device_release(void)

{
  return;
}


// ===== 0010ba50 nv_pci_gb10b_device_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ba59) */

void nv_pci_gb10b_device_release(void)

{
  return;
}


// ===== 0010ba60 __pfx_nv_pci_devfreq_disable_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ba7d) */

void __pfx_nv_pci_devfreq_disable_boost(long param_1)

{
  *(undefined1 *)(param_1 + -8) = 0;
  return;
}


// ===== 0010ba70 nv_pci_devfreq_disable_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ba7d) */

void nv_pci_devfreq_disable_boost(long param_1)

{
  *(undefined1 *)(param_1 + -8) = 0;
  return;
}


// ===== 0010ba90 __pfx_check_for_bound_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bafc) */

char * __pfx_check_for_bound_driver(long param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (*(long **)(param_1 + 0x138) != (long *)0x0) {
    pcVar1 = (char *)**(long **)(param_1 + 0x138);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "another driver";
    }
    nv_printf(3,"NVRM: GPU %04x:%02x:%02x.%x is already bound to %s.\n",
              **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7,pcVar1,0x10baa5);
  }
  return pcVar1;
}


// ===== 0010baa0 check_for_bound_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bafc) */

char * check_for_bound_driver(long param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (*(long **)(param_1 + 0x138) != (long *)0x0) {
    pcVar1 = (char *)**(long **)(param_1 + 0x138);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "another driver";
    }
    nv_printf(3,"NVRM: GPU %04x:%02x:%02x.%x is already bound to %s.\n",
              **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7,pcVar1,0x10baa5);
  }
  return pcVar1;
}


// ===== 0010bb10 __pfx_nv_pci_validate_bars =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bbb6) */
/* WARNING: Removing unreachable block (ram,0x0010bbcf) */

uint __pfx_nv_pci_validate_bars(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  
  plVar3 = (long *)(param_1 + 0x3f0);
  uVar6 = 0;
  iVar4 = 0;
  uVar7 = 0;
  do {
    lVar1 = *plVar3;
    if (((lVar1 == 0) || (plVar3[1] == 0)) || (plVar3[1] - lVar1 == -1)) {
      if ((char)uVar6 == '\0') {
        lVar2 = *(long *)(param_1 + 0x3f8 + (ulong)uVar7 * 0x40);
        uVar5 = 0;
        if (lVar2 != 0) {
          uVar5 = (ulong)((lVar2 + 1) - lVar1) >> 0x14;
        }
        nv_printf(4,
                  "NVRM: This PCI I/O region assigned to your NVIDIA device is invalid:\nNVRM: BAR%d is %lluM @ 0x%llx (PCI:%04x:%02x:%02x.%x)\n"
                  ,uVar7,uVar5,lVar1,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                  *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                  *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        return uVar6;
      }
      uVar6 = 0;
    }
    else {
      if ((char)param_2 != '\0') {
        return param_2;
      }
      iVar4 = iVar4 + 1;
      uVar6 = uVar6 | (~(uint)plVar3[3] & 0xc) == 0;
    }
    uVar7 = uVar7 + 1;
    plVar3 = plVar3 + 8;
  } while ((uVar7 != 6) && (iVar4 != 3));
  return 1;
}


// ===== 0010bb20 nv_pci_validate_bars =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bbb6) */
/* WARNING: Removing unreachable block (ram,0x0010bbcf) */

uint nv_pci_validate_bars(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  
  plVar3 = (long *)(param_1 + 0x3f0);
  uVar6 = 0;
  iVar4 = 0;
  uVar7 = 0;
  do {
    lVar1 = *plVar3;
    if (((lVar1 == 0) || (plVar3[1] == 0)) || (plVar3[1] - lVar1 == -1)) {
      if ((char)uVar6 == '\0') {
        lVar2 = *(long *)(param_1 + 0x3f8 + (ulong)uVar7 * 0x40);
        uVar5 = 0;
        if (lVar2 != 0) {
          uVar5 = (ulong)((lVar2 + 1) - lVar1) >> 0x14;
        }
        nv_printf(4,
                  "NVRM: This PCI I/O region assigned to your NVIDIA device is invalid:\nNVRM: BAR%d is %lluM @ 0x%llx (PCI:%04x:%02x:%02x.%x)\n"
                  ,uVar7,uVar5,lVar1,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                  *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                  *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        return uVar6;
      }
      uVar6 = 0;
    }
    else {
      if ((char)param_2 != '\0') {
        return param_2;
      }
      iVar4 = iVar4 + 1;
      uVar6 = uVar6 | (~(uint)plVar3[3] & 0xc) == 0;
    }
    uVar7 = uVar7 + 1;
    plVar3 = plVar3 + 8;
  } while ((uVar7 != 6) && (iVar4 != 3));
  return 1;
}


// ===== 0010bc10 __pfx_nv_pci_gb10b_devfreq_disable_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bc75) */
/* WARNING: Removing unreachable block (ram,0x0010bcb0) */

undefined8 __pfx_nv_pci_gb10b_devfreq_disable_boost(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  lVar2 = *(long *)(lVar1 + 0x5250);
  if (((lVar2 != 0) && (*(long *)(lVar2 + 0x358) != 0)) && (*(char *)(lVar2 + 0x360) != '\0')) {
    *(undefined1 *)(lVar2 + 0x360) = 0;
    cancel_delayed_work_sync(lVar2 + 0x368);
  }
  lVar1 = *(long *)(lVar1 + 0x5258);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x358) != 0)) && (*(char *)(lVar1 + 0x360) != '\0')) {
    *(undefined1 *)(lVar1 + 0x360) = 0;
    cancel_delayed_work_sync(lVar1 + 0x368);
    return 0;
  }
  return 0;
}


// ===== 0010bc20 nv_pci_gb10b_devfreq_disable_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bc75) */
/* WARNING: Removing unreachable block (ram,0x0010bcb0) */

undefined8 nv_pci_gb10b_devfreq_disable_boost(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  lVar2 = *(long *)(lVar1 + 0x5250);
  if (((lVar2 != 0) && (*(long *)(lVar2 + 0x358) != 0)) && (*(char *)(lVar2 + 0x360) != '\0')) {
    *(undefined1 *)(lVar2 + 0x360) = 0;
    cancel_delayed_work_sync(lVar2 + 0x368);
  }
  lVar1 = *(long *)(lVar1 + 0x5258);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x358) != 0)) && (*(char *)(lVar1 + 0x360) != '\0')) {
    *(undefined1 *)(lVar1 + 0x360) = 0;
    cancel_delayed_work_sync(lVar1 + 0x368);
    return 0;
  }
  return 0;
}


// ===== 0010bcc0 __pfx_nv_pci_gb10b_resume_devfreq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bdbd) */
/* WARNING: Removing unreachable block (ram,0x0010bdcb) */

int __pfx_nv_pci_gb10b_resume_devfreq(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(long *)(lVar1 + 0x5250) != 0) && (*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) != 0)) {
    iVar2 = devfreq_resume_device();
    if (iVar2 != 0) {
      return iVar2;
    }
    mutex_lock(*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) + 0x10);
    update_devfreq(*(undefined8 *)(*(long *)(lVar1 + 0x5250) + 0x358));
    mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) + 0x10);
  }
  if ((*(long *)(lVar1 + 0x5258) == 0) || (*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = devfreq_resume_device();
    if (iVar2 == 0) {
      mutex_lock(*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) + 0x10);
      update_devfreq(*(undefined8 *)(*(long *)(lVar1 + 0x5258) + 0x358));
      mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) + 0x10);
      return 0;
    }
  }
  return iVar2;
}


// ===== 0010bcd0 nv_pci_gb10b_resume_devfreq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bdbd) */
/* WARNING: Removing unreachable block (ram,0x0010bdcb) */

int nv_pci_gb10b_resume_devfreq(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(long *)(lVar1 + 0x5250) != 0) && (*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) != 0)) {
    iVar2 = devfreq_resume_device();
    if (iVar2 != 0) {
      return iVar2;
    }
    mutex_lock(*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) + 0x10);
    update_devfreq(*(undefined8 *)(*(long *)(lVar1 + 0x5250) + 0x358));
    mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) + 0x10);
  }
  if ((*(long *)(lVar1 + 0x5258) == 0) || (*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = devfreq_resume_device();
    if (iVar2 == 0) {
      mutex_lock(*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) + 0x10);
      update_devfreq(*(undefined8 *)(*(long *)(lVar1 + 0x5258) + 0x358));
      mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) + 0x10);
      return 0;
    }
  }
  return iVar2;
}


// ===== 0010bdd0 __pfx_nv_pci_gb10b_suspend_devfreq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bf23) */
/* WARNING: Removing unreachable block (ram,0x0010bf31) */

int __pfx_nv_pci_gb10b_suspend_devfreq(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(long *)(lVar1 + 0x5250) != 0) &&
     (lVar2 = *(long *)(*(long *)(lVar1 + 0x5250) + 0x358), lVar2 != 0)) {
    mutex_lock(lVar2 + 0x10);
    lVar2 = *(long *)(*(long *)(lVar1 + 0x5250) + 0x358);
    *(undefined8 *)(lVar2 + 0x4b8) = *(undefined8 *)(lVar2 + 0x3d8);
    mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) + 0x10);
    iVar3 = devfreq_suspend_device(*(undefined8 *)(*(long *)(lVar1 + 0x5250) + 0x358));
    if (iVar3 != 0) {
      return iVar3;
    }
    lVar2 = *(long *)(*(long *)(lVar1 + 0x5250) + 0x3c0);
    if (lVar2 != 0) {
      icc_set_bw(lVar2,0,0);
    }
  }
  if ((*(long *)(lVar1 + 0x5258) == 0) ||
     (lVar2 = *(long *)(*(long *)(lVar1 + 0x5258) + 0x358), lVar2 == 0)) {
    iVar3 = 0;
  }
  else {
    mutex_lock(lVar2 + 0x10);
    lVar2 = *(long *)(*(long *)(lVar1 + 0x5258) + 0x358);
    *(undefined8 *)(lVar2 + 0x4b8) = *(undefined8 *)(lVar2 + 0x3d8);
    mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) + 0x10);
    iVar3 = devfreq_suspend_device(*(undefined8 *)(*(long *)(lVar1 + 0x5258) + 0x358));
    if ((iVar3 == 0) && (lVar1 = *(long *)(*(long *)(lVar1 + 0x5258) + 0x3c0), lVar1 != 0)) {
      icc_set_bw(lVar1,0,0);
      return 0;
    }
  }
  return iVar3;
}


// ===== 0010bde0 nv_pci_gb10b_suspend_devfreq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bf23) */
/* WARNING: Removing unreachable block (ram,0x0010bf31) */

int nv_pci_gb10b_suspend_devfreq(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if ((*(long *)(lVar1 + 0x5250) != 0) &&
     (lVar2 = *(long *)(*(long *)(lVar1 + 0x5250) + 0x358), lVar2 != 0)) {
    mutex_lock(lVar2 + 0x10);
    lVar2 = *(long *)(*(long *)(lVar1 + 0x5250) + 0x358);
    *(undefined8 *)(lVar2 + 0x4b8) = *(undefined8 *)(lVar2 + 0x3d8);
    mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5250) + 0x358) + 0x10);
    iVar3 = devfreq_suspend_device(*(undefined8 *)(*(long *)(lVar1 + 0x5250) + 0x358));
    if (iVar3 != 0) {
      return iVar3;
    }
    lVar2 = *(long *)(*(long *)(lVar1 + 0x5250) + 0x3c0);
    if (lVar2 != 0) {
      icc_set_bw(lVar2,0,0);
    }
  }
  if ((*(long *)(lVar1 + 0x5258) == 0) ||
     (lVar2 = *(long *)(*(long *)(lVar1 + 0x5258) + 0x358), lVar2 == 0)) {
    iVar3 = 0;
  }
  else {
    mutex_lock(lVar2 + 0x10);
    lVar2 = *(long *)(*(long *)(lVar1 + 0x5258) + 0x358);
    *(undefined8 *)(lVar2 + 0x4b8) = *(undefined8 *)(lVar2 + 0x3d8);
    mutex_unlock(*(long *)(*(long *)(lVar1 + 0x5258) + 0x358) + 0x10);
    iVar3 = devfreq_suspend_device(*(undefined8 *)(*(long *)(lVar1 + 0x5258) + 0x358));
    if ((iVar3 == 0) && (lVar1 = *(long *)(*(long *)(lVar1 + 0x5258) + 0x3c0), lVar1 != 0)) {
      icc_set_bw(lVar1,0,0);
      return 0;
    }
  }
  return iVar3;
}


// ===== 0010bf40 __pfx_nv_pci_tegra_devfreq_get_cur_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bf91) */
/* WARNING: Removing unreachable block (ram,0x0010bfb0) */

undefined8 __pfx_nv_pci_tegra_devfreq_get_cur_freq(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x40) + 0x1dc);
  if ((iVar1 != 0) && ((*(byte *)(*(long *)(param_1 + 0x40) + 0x1d0) & 7) == 0)) {
    uVar2 = 0;
    if (iVar1 != 2) {
      uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x350) + 0x3d8);
    }
    *param_2 = uVar2;
    return 0;
  }
  uVar2 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
  *param_2 = uVar2;
  return 0;
}


// ===== 0010bf50 nv_pci_tegra_devfreq_get_cur_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010bf91) */
/* WARNING: Removing unreachable block (ram,0x0010bfb0) */

undefined8 nv_pci_tegra_devfreq_get_cur_freq(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x40) + 0x1dc);
  if ((iVar1 != 0) && ((*(byte *)(*(long *)(param_1 + 0x40) + 0x1d0) & 7) == 0)) {
    uVar2 = 0;
    if (iVar1 != 2) {
      uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x350) + 0x3d8);
    }
    *param_2 = uVar2;
    return 0;
  }
  uVar2 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
  *param_2 = uVar2;
  return 0;
}


// ===== 0010bfc0 __pfx_nv_pci_gb10b_devfreq_target =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c1bf) */
/* WARNING: Removing unreachable block (ram,0x0010c1f3) */

undefined8 __pfx_nv_pci_gb10b_devfreq_target(long param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(param_1 + 0x40);
  if ((*(int *)(lVar1 + 0x1dc) == 2) && ((*(byte *)(lVar1 + 0x1d0) & 7) == 0)) {
    return 0;
  }
  lVar1 = *(long *)(lVar1 + 0x78);
  clk_set_rate(*(undefined8 *)(param_1 + 0x348),*param_2);
  lVar3 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
  *param_2 = lVar3;
  if (*(long *)(param_1 + 0x3b8) != 0) {
    uVar5 = 0xffffffff;
    if (*(char *)(param_1 + 0x358) == '\0') {
      uVar5 = (ulong)(lVar3 * 0x19000) / 1000000;
    }
    icc_set_bw(*(long *)(param_1 + 0x3b8),uVar5,0);
  }
  plVar2 = *(long **)(param_1 + 0x318);
  if ((long *)(param_1 + 0x318) != plVar2) {
    uVar5 = 0;
    do {
      if (plVar2[4] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[4] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if (plVar2[5] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[5] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if ((*(char *)(param_1 + 0x358) == '\0') ||
         ((*(long **)(lVar1 + 0x5260) != plVar2 + -100 &&
          (*(long **)(lVar1 + 0x5268) != plVar2 + -100)))) {
        clk_set_rate(plVar2[6],uVar5);
      }
      else {
        clk_set_rate(plVar2[6],0xffffffffffffffff);
      }
      plVar2 = (long *)*plVar2;
    } while ((long *)(param_1 + 0x318) != plVar2);
  }
  plVar2 = *(long **)(param_1 + 0x328);
  if ((long *)(param_1 + 0x328) != plVar2) {
    uVar5 = 0;
    do {
      if (plVar2[2] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[2] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if (plVar2[3] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[3] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if ((*(char *)(param_1 + 0x358) == '\0') ||
         ((*(long **)(lVar1 + 0x5260) != plVar2 + -0x66 &&
          (*(long **)(lVar1 + 0x5268) != plVar2 + -0x66)))) {
        clk_set_rate(plVar2[4],uVar5);
      }
      else {
        clk_set_rate(plVar2[4],0xffffffffffffffff);
      }
      plVar2 = (long *)*plVar2;
    } while ((long *)(param_1 + 0x328) != plVar2);
  }
  return 0;
}


// ===== 0010bfd0 nv_pci_gb10b_devfreq_target =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c1bf) */
/* WARNING: Removing unreachable block (ram,0x0010c1f3) */

undefined8 nv_pci_gb10b_devfreq_target(long param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(param_1 + 0x40);
  if ((*(int *)(lVar1 + 0x1dc) == 2) && ((*(byte *)(lVar1 + 0x1d0) & 7) == 0)) {
    return 0;
  }
  lVar1 = *(long *)(lVar1 + 0x78);
  clk_set_rate(*(undefined8 *)(param_1 + 0x348),*param_2);
  lVar3 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
  *param_2 = lVar3;
  if (*(long *)(param_1 + 0x3b8) != 0) {
    uVar5 = 0xffffffff;
    if (*(char *)(param_1 + 0x358) == '\0') {
      uVar5 = (ulong)(lVar3 * 0x19000) / 1000000;
    }
    icc_set_bw(*(long *)(param_1 + 0x3b8),uVar5,0);
  }
  plVar2 = *(long **)(param_1 + 0x318);
  if ((long *)(param_1 + 0x318) != plVar2) {
    uVar5 = 0;
    do {
      if (plVar2[4] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[4] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if (plVar2[5] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[5] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if ((*(char *)(param_1 + 0x358) == '\0') ||
         ((*(long **)(lVar1 + 0x5260) != plVar2 + -100 &&
          (*(long **)(lVar1 + 0x5268) != plVar2 + -100)))) {
        clk_set_rate(plVar2[6],uVar5);
      }
      else {
        clk_set_rate(plVar2[6],0xffffffffffffffff);
      }
      plVar2 = (long *)*plVar2;
    } while ((long *)(param_1 + 0x318) != plVar2);
  }
  plVar2 = *(long **)(param_1 + 0x328);
  if ((long *)(param_1 + 0x328) != plVar2) {
    uVar5 = 0;
    do {
      if (plVar2[2] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[2] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if (plVar2[3] != 0) {
        uVar4 = clk_get_rate(*(undefined8 *)(plVar2[3] + 0x350));
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
      }
      if ((*(char *)(param_1 + 0x358) == '\0') ||
         ((*(long **)(lVar1 + 0x5260) != plVar2 + -0x66 &&
          (*(long **)(lVar1 + 0x5268) != plVar2 + -0x66)))) {
        clk_set_rate(plVar2[4],uVar5);
      }
      else {
        clk_set_rate(plVar2[4],0xffffffffffffffff);
      }
      plVar2 = (long *)*plVar2;
    } while ((long *)(param_1 + 0x328) != plVar2);
  }
  return 0;
}


// ===== 0010c200 __pfx_nv_pci_gb10b_add_devfreq_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c362) */

ulong __pfx_nv_pci_gb10b_add_devfreq_device(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  long in_GS_OFFSET;
  bool bVar11;
  undefined8 uStack_58;
  ulong uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = clk_round_rate(*(undefined8 *)(param_1 + 0x350),0xffffffffffffffff);
  uVar7 = 0xffffffffffffffff;
  if (-1 < (long)uVar3) {
    uVar7 = uVar3;
  }
  uVar3 = clk_round_rate(*(undefined8 *)(param_1 + 0x350),0);
  if ((long)uVar3 < 0) {
    uVar3 = 0xffffffffffffffff;
    lVar10 = -1;
  }
  else {
    lVar10 = uVar3 + 1;
  }
  uVar4 = clk_round_rate(*(undefined8 *)(param_1 + 0x350),lVar10);
  if (((long)uVar4 < 0) || (uVar4 < uVar3)) {
    bVar11 = false;
    lVar10 = 0;
  }
  else {
    lVar10 = uVar4 - uVar3;
    bVar11 = uVar4 != uVar3;
  }
  lVar1 = param_1 + 8;
  do {
    uStack_58 = 0;
    uStack_48 = 0;
    uStack_50 = uVar3;
    dev_pm_opp_add_dynamic(lVar1,&uStack_58);
    if (uVar7 < uVar3 + lVar10) break;
    uVar3 = uVar3 + lVar10;
  } while (bVar11);
  puVar5 = (undefined8 *)devm_kmalloc(lVar1,0x48,0xdc0);
  if (puVar5 == (undefined8 *)0x0) {
    uVar7 = *(ulong *)(param_1 + 0x358);
    uVar3 = 0xfffffff4;
  }
  else {
    puVar5[2] = nv_pci_gb10b_devfreq_target;
    uVar6 = *(undefined8 *)(param_1 + 0x350);
    uVar3 = 0;
    puVar5[4] = nv_pci_tegra_devfreq_get_cur_freq;
    puVar5[3] = nv_pci_tegra_devfreq_get_dev_status;
    uVar6 = clk_get_rate(uVar6);
    *puVar5 = uVar6;
    *(undefined4 *)(puVar5 + 1) = 0x19;
    uVar7 = devm_devfreq_add_device(lVar1,puVar5,"performance",0);
    *(ulong *)(param_1 + 0x358) = uVar7;
    if (uVar7 < 0xfffffffffffff001) goto LAB_0010c343;
    uVar3 = uVar7 & 0xffffffff;
  }
  iVar2 = *(int *)(uVar7 + 0x3d0);
  if (iVar2 != 0) {
    lVar10 = *(long *)(uVar7 + 0x3c8);
    iVar9 = 0;
    do {
      lVar8 = (long)iVar9;
      iVar9 = iVar9 + 1;
      dev_pm_opp_remove(lVar1,*(undefined8 *)(lVar10 + lVar8 * 8));
    } while (iVar9 != iVar2);
  }
LAB_0010c343:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 0010c210 nv_pci_gb10b_add_devfreq_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c362) */

ulong nv_pci_gb10b_add_devfreq_device(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  long in_GS_OFFSET;
  bool bVar11;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = clk_round_rate(*(undefined8 *)(param_1 + 0x350),0xffffffffffffffff);
  uVar7 = 0xffffffffffffffff;
  if (-1 < (long)uVar3) {
    uVar7 = uVar3;
  }
  uVar3 = clk_round_rate(*(undefined8 *)(param_1 + 0x350),0);
  if ((long)uVar3 < 0) {
    uVar3 = 0xffffffffffffffff;
    lVar10 = -1;
  }
  else {
    lVar10 = uVar3 + 1;
  }
  uVar4 = clk_round_rate(*(undefined8 *)(param_1 + 0x350),lVar10);
  if (((long)uVar4 < 0) || (uVar4 < uVar3)) {
    bVar11 = false;
    lVar10 = 0;
  }
  else {
    lVar10 = uVar4 - uVar3;
    bVar11 = uVar4 != uVar3;
  }
  lVar1 = param_1 + 8;
  do {
    local_58 = 0;
    local_48 = 0;
    local_50 = uVar3;
    dev_pm_opp_add_dynamic(lVar1,&local_58);
    if (uVar7 < uVar3 + lVar10) break;
    uVar3 = uVar3 + lVar10;
  } while (bVar11);
  puVar5 = (undefined8 *)devm_kmalloc(lVar1,0x48,0xdc0);
  if (puVar5 == (undefined8 *)0x0) {
    uVar7 = *(ulong *)(param_1 + 0x358);
    uVar3 = 0xfffffff4;
  }
  else {
    puVar5[2] = nv_pci_gb10b_devfreq_target;
    uVar6 = *(undefined8 *)(param_1 + 0x350);
    uVar3 = 0;
    puVar5[4] = nv_pci_tegra_devfreq_get_cur_freq;
    puVar5[3] = nv_pci_tegra_devfreq_get_dev_status;
    uVar6 = clk_get_rate(uVar6);
    *puVar5 = uVar6;
    *(undefined4 *)(puVar5 + 1) = 0x19;
    uVar7 = devm_devfreq_add_device(lVar1,puVar5,"performance",0);
    *(ulong *)(param_1 + 0x358) = uVar7;
    if (uVar7 < 0xfffffffffffff001) goto LAB_0010c343;
    uVar3 = uVar7 & 0xffffffff;
  }
  iVar2 = *(int *)(uVar7 + 0x3d0);
  if (iVar2 != 0) {
    lVar10 = *(long *)(uVar7 + 0x3c8);
    iVar9 = 0;
    do {
      lVar8 = (long)iVar9;
      iVar9 = iVar9 + 1;
      dev_pm_opp_remove(lVar1,*(undefined8 *)(lVar10 + lVar8 * 8));
    } while (iVar9 != iVar2);
  }
LAB_0010c343:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 0010c3d0 __pfx_nv_pci_gb10b_devfreq_enable_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c563) */
/* WARNING: Removing unreachable block (ram,0x0010c451) */
/* WARNING: Removing unreachable block (ram,0x0010c458) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_nv_pci_gb10b_devfreq_enable_boost(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  lVar1 = *(long *)(param_1 + 0x78);
  uVar3 = __msecs_to_jiffies(param_2 * 1000);
  lVar2 = *(long *)(lVar1 + 0x5250);
  if (((lVar2 == 0) || (*(long *)(lVar2 + 0x358) == 0)) || (*(char *)(lVar2 + 0x360) != '\0')) {
    lVar1 = *(long *)(lVar1 + 0x5258);
  }
  else {
    *(undefined1 *)(lVar2 + 0x360) = 1;
    *(long *)(lVar2 + 0x370) = lVar2 + 0x370;
    *(undefined8 *)(lVar2 + 0x368) = 0xfffffffe00000;
    *(long *)(lVar2 + 0x378) = lVar2 + 0x370;
    *(code **)(lVar2 + 0x380) = nv_pci_devfreq_disable_boost;
    timer_init_key(lVar2 + 0x388,&delayed_work_timer_fn,0x200000,0,0);
    queue_delayed_work_on(0x2000,_system_percpu_wq,lVar2 + 0x368,uVar3);
    lVar1 = *(long *)(lVar1 + 0x5258);
  }
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x358) != 0)) && (*(char *)(lVar1 + 0x360) == '\0')) {
    *(long *)(lVar1 + 0x370) = lVar1 + 0x370;
    *(undefined8 *)(lVar1 + 0x368) = 0xfffffffe00000;
    *(long *)(lVar1 + 0x378) = lVar1 + 0x370;
    *(undefined1 *)(lVar1 + 0x360) = 1;
    *(code **)(lVar1 + 0x380) = nv_pci_devfreq_disable_boost;
    timer_init_key(lVar1 + 0x388,&delayed_work_timer_fn,0x200000,0,0);
    queue_delayed_work_on(0x2000,_system_percpu_wq,lVar1 + 0x368,uVar3);
    return 0;
  }
  return 0;
}


// ===== 0010c3e0 nv_pci_gb10b_devfreq_enable_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c563) */
/* WARNING: Removing unreachable block (ram,0x0010c451) */
/* WARNING: Removing unreachable block (ram,0x0010c458) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nv_pci_gb10b_devfreq_enable_boost(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  lVar1 = *(long *)(param_1 + 0x78);
  uVar3 = __msecs_to_jiffies(param_2 * 1000);
  lVar2 = *(long *)(lVar1 + 0x5250);
  if (((lVar2 == 0) || (*(long *)(lVar2 + 0x358) == 0)) || (*(char *)(lVar2 + 0x360) != '\0')) {
    lVar1 = *(long *)(lVar1 + 0x5258);
  }
  else {
    *(undefined1 *)(lVar2 + 0x360) = 1;
    *(long *)(lVar2 + 0x370) = lVar2 + 0x370;
    *(undefined8 *)(lVar2 + 0x368) = 0xfffffffe00000;
    *(long *)(lVar2 + 0x378) = lVar2 + 0x370;
    *(code **)(lVar2 + 0x380) = nv_pci_devfreq_disable_boost;
    timer_init_key(lVar2 + 0x388,&delayed_work_timer_fn,0x200000,0,0);
    queue_delayed_work_on(0x2000,_system_percpu_wq,lVar2 + 0x368,uVar3);
    lVar1 = *(long *)(lVar1 + 0x5258);
  }
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x358) != 0)) && (*(char *)(lVar1 + 0x360) == '\0')) {
    *(long *)(lVar1 + 0x370) = lVar1 + 0x370;
    *(undefined8 *)(lVar1 + 0x368) = 0xfffffffe00000;
    *(long *)(lVar1 + 0x378) = lVar1 + 0x370;
    *(undefined1 *)(lVar1 + 0x360) = 1;
    *(code **)(lVar1 + 0x380) = nv_pci_devfreq_disable_boost;
    timer_init_key(lVar1 + 0x388,&delayed_work_timer_fn,0x200000,0,0);
    queue_delayed_work_on(0x2000,_system_percpu_wq,lVar1 + 0x368,uVar3);
    return 0;
  }
  return 0;
}


// ===== 0010c570 __pfx_nv_pci_tegra_devfreq_get_dev_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c657) */

undefined8 __pfx_nv_pci_tegra_devfreq_get_dev_status(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  long in_GS_OFFSET;
  uint uStack_3c;
  long lStack_38;
  
  lVar2 = *(long *)(param_1 + 0x40);
  uVar5 = *(undefined8 *)(lVar2 + 0x78);
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_3c = 0;
  if ((*(int *)(lVar2 + 0x1dc) == 0) || ((*(byte *)(lVar2 + 0x1d0) & 7) != 0)) {
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 == '\0') {
      iVar4 = rm_pmu_perfmon_get_load(0,uVar5,&uStack_3c,*(undefined4 *)(param_1 + -8));
      if (iVar4 == 0) {
        *param_2 = 100;
        param_2[1] = (ulong)uStack_3c;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
      }
      else {
        *param_2 = 100;
        param_2[1] = 100;
        uStack_3c = 100;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
      }
    }
    else {
      puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar6 == (undefined4 *)0x0) {
        _dev_warn(lVar2,"fail to nv_kmem_cache_alloc_stack: %d\n",0xfffffff4);
        uVar5 = 0xfffffff4;
        goto LAB_0010c62c;
      }
      *puVar6 = 0x2ff0;
      uVar1 = *(undefined4 *)(param_1 + -8);
      *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
      iVar4 = rm_pmu_perfmon_get_load(puVar6,uVar5,&uStack_3c,uVar1);
      if (iVar4 == 0) {
        *param_2 = 100;
        param_2[1] = (ulong)uStack_3c;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
        cVar3 = rm_is_altstack_in_use();
      }
      else {
        *param_2 = 100;
        param_2[1] = 100;
        uStack_3c = 100;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
        cVar3 = rm_is_altstack_in_use();
      }
      if (cVar3 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
      }
    }
  }
  else {
    *param_2 = 100;
    param_2[1] = 0;
    param_2[2] = *(undefined8 *)(*(long *)(param_1 + 0x350) + 0x3d8);
  }
  uVar5 = 0;
LAB_0010c62c:
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010c580 nv_pci_tegra_devfreq_get_dev_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c657) */

undefined8 nv_pci_tegra_devfreq_get_dev_status(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  long in_GS_OFFSET;
  uint local_3c;
  long local_38;
  
  lVar2 = *(long *)(param_1 + 0x40);
  uVar5 = *(undefined8 *)(lVar2 + 0x78);
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_3c = 0;
  if ((*(int *)(lVar2 + 0x1dc) == 0) || ((*(byte *)(lVar2 + 0x1d0) & 7) != 0)) {
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 == '\0') {
      iVar4 = rm_pmu_perfmon_get_load(0,uVar5,&local_3c,*(undefined4 *)(param_1 + -8));
      if (iVar4 == 0) {
        *param_2 = 100;
        param_2[1] = (ulong)local_3c;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
      }
      else {
        *param_2 = 100;
        param_2[1] = 100;
        local_3c = 100;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
      }
    }
    else {
      puVar6 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar6 == (undefined4 *)0x0) {
        _dev_warn(lVar2,"fail to nv_kmem_cache_alloc_stack: %d\n",0xfffffff4);
        uVar5 = 0xfffffff4;
        goto LAB_0010c62c;
      }
      *puVar6 = 0x2ff0;
      uVar1 = *(undefined4 *)(param_1 + -8);
      *(undefined4 **)(puVar6 + 2) = puVar6 + 0xc00;
      iVar4 = rm_pmu_perfmon_get_load(puVar6,uVar5,&local_3c,uVar1);
      if (iVar4 == 0) {
        *param_2 = 100;
        param_2[1] = (ulong)local_3c;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
        cVar3 = rm_is_altstack_in_use();
      }
      else {
        *param_2 = 100;
        param_2[1] = 100;
        local_3c = 100;
        uVar5 = clk_get_rate(*(undefined8 *)(param_1 + 0x348));
        param_2[2] = uVar5;
        cVar3 = rm_is_altstack_in_use();
      }
      if (cVar3 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar6);
      }
    }
  }
  else {
    *param_2 = 100;
    param_2[1] = 0;
    param_2[2] = *(undefined8 *)(*(long *)(param_1 + 0x350) + 0x3d8);
  }
  uVar5 = 0;
LAB_0010c62c:
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010c770 __pfx_nv_pci_tegra_devfreq_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c9be) */

void __pfx_nv_pci_tegra_devfreq_remove(long *param_1)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  
  if (param_1[0x6b] != 0) {
    devm_devfreq_remove_device(param_1 + 1);
    iVar1 = *(int *)(param_1[0x6b] + 0x3d0);
    if (iVar1 != 0) {
      lVar2 = *(long *)(param_1[0x6b] + 0x3c8);
      iVar5 = 0;
      do {
        lVar4 = (long)iVar5;
        iVar5 = iVar5 + 1;
        dev_pm_opp_remove(param_1 + 1,*(undefined8 *)(lVar2 + lVar4 * 8));
      } while (iVar1 != iVar5);
    }
    param_1[0x6b] = 0;
  }
  if (param_1[0x78] != 0) {
    icc_set_bw(param_1[0x78],0,0);
  }
  plVar6 = (long *)param_1[100] + -100;
  if (param_1 != plVar6) {
    plVar8 = *(long **)param_1[100];
    do {
      plVar7 = plVar8 + -100;
      if (plVar6[0x6a] != 0) {
        devm_clk_put(param_1[9]);
        plVar6[0x6a] = 0;
        device_unregister(plVar6 + 1);
      }
      plVar3 = (long *)plVar6[0x65];
      lVar2 = plVar6[100];
      if ((plVar6 + 100 == (long *)*plVar3) && (plVar6 + 100 == *(long **)(lVar2 + 8))) {
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      plVar6[100] = -0x2152ffffffffff00;
      plVar6[0x65] = -0x2152fffffffffede;
      plVar6[0x68] = 0;
      plVar8 = (long *)*plVar8;
      plVar6 = plVar7;
    } while (param_1 != plVar7);
  }
  plVar6 = (long *)param_1[0x66] + -0x66;
  plVar8 = param_1;
  if (param_1 != plVar6) {
    plVar7 = *(long **)param_1[0x66];
    do {
      plVar8 = plVar7 + -0x66;
      if (plVar6[0x6a] != 0) {
        devm_clk_put(param_1[9]);
        plVar6[0x6a] = 0;
        device_unregister(plVar6 + 1);
      }
      plVar3 = (long *)plVar6[0x67];
      lVar2 = plVar6[0x66];
      if ((plVar6 + 0x66 == (long *)*plVar3) && (plVar6 + 0x66 == *(long **)(lVar2 + 8))) {
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      plVar6[0x66] = -0x2152ffffffffff00;
      plVar6[0x67] = -0x2152fffffffffede;
      plVar6[0x69] = 0;
      plVar7 = (long *)*plVar7;
      plVar6 = plVar8;
    } while (param_1 != plVar8);
  }
  if (param_1[0x6a] == 0) {
    return;
  }
  devm_clk_put(param_1[9],plVar8[0x6a]);
  param_1[0x6a] = 0;
  device_unregister(param_1 + 1);
  return;
}


// ===== 0010c780 nv_pci_tegra_devfreq_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010c9be) */

void nv_pci_tegra_devfreq_remove(long *param_1)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  
  if (param_1[0x6b] != 0) {
    devm_devfreq_remove_device(param_1 + 1);
    iVar1 = *(int *)(param_1[0x6b] + 0x3d0);
    if (iVar1 != 0) {
      lVar2 = *(long *)(param_1[0x6b] + 0x3c8);
      iVar5 = 0;
      do {
        lVar4 = (long)iVar5;
        iVar5 = iVar5 + 1;
        dev_pm_opp_remove(param_1 + 1,*(undefined8 *)(lVar2 + lVar4 * 8));
      } while (iVar1 != iVar5);
    }
    param_1[0x6b] = 0;
  }
  if (param_1[0x78] != 0) {
    icc_set_bw(param_1[0x78],0,0);
  }
  plVar6 = (long *)param_1[100] + -100;
  if (param_1 != plVar6) {
    plVar8 = *(long **)param_1[100];
    do {
      plVar7 = plVar8 + -100;
      if (plVar6[0x6a] != 0) {
        devm_clk_put(param_1[9]);
        plVar6[0x6a] = 0;
        device_unregister(plVar6 + 1);
      }
      plVar3 = (long *)plVar6[0x65];
      lVar2 = plVar6[100];
      if ((plVar6 + 100 == (long *)*plVar3) && (plVar6 + 100 == *(long **)(lVar2 + 8))) {
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      plVar6[100] = -0x2152ffffffffff00;
      plVar6[0x65] = -0x2152fffffffffede;
      plVar6[0x68] = 0;
      plVar8 = (long *)*plVar8;
      plVar6 = plVar7;
    } while (param_1 != plVar7);
  }
  plVar6 = (long *)param_1[0x66] + -0x66;
  plVar8 = param_1;
  if (param_1 != plVar6) {
    plVar7 = *(long **)param_1[0x66];
    do {
      plVar8 = plVar7 + -0x66;
      if (plVar6[0x6a] != 0) {
        devm_clk_put(param_1[9]);
        plVar6[0x6a] = 0;
        device_unregister(plVar6 + 1);
      }
      plVar3 = (long *)plVar6[0x67];
      lVar2 = plVar6[0x66];
      if ((plVar6 + 0x66 == (long *)*plVar3) && (plVar6 + 0x66 == *(long **)(lVar2 + 8))) {
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      plVar6[0x66] = -0x2152ffffffffff00;
      plVar6[0x67] = -0x2152fffffffffede;
      plVar6[0x69] = 0;
      plVar7 = (long *)*plVar7;
      plVar6 = plVar8;
    } while (param_1 != plVar8);
  }
  if (param_1[0x6a] == 0) {
    return;
  }
  devm_clk_put(param_1[9],plVar8[0x6a]);
  param_1[0x6a] = 0;
  device_unregister(param_1 + 1);
  return;
}


// ===== 0010c9d0 __pfx_nv_pci_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010d3ec) */

undefined4 __pfx_nv_pci_probe(long param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  byte *pbVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  undefined4 *puVar16;
  undefined8 uVar17;
  byte bVar18;
  ushort uVar19;
  undefined8 extraout_RDX;
  uint uVar20;
  undefined4 uVar21;
  long lVar22;
  long in_GS_OFFSET;
  bool bVar23;
  long lStack_98;
  byte bStack_8e;
  ushort uStack_82;
  long lStack_80;
  undefined4 uStack_76;
  char acStack_72 [50];
  long lStack_40;
  
  bVar5 = nv_ats_supported;
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  nv_printf(1,"NVRM: probing 0x%x 0x%x, class 0x%x\n",*(undefined2 *)(param_1 + 0x3c),
            *(undefined2 *)(param_1 + 0x3e),*(undefined4 *)(param_1 + 0x44));
  bStack_8e = *(byte *)(param_1 + 0x873) & 1;
  if ((*(byte *)(param_1 + 0x873) & 1) == 0) {
    puVar16 = (undefined4 *)0x0;
    cVar6 = rm_is_altstack_in_use();
    if (cVar6 != '\0') {
      puVar16 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar16 == (undefined4 *)0x0) goto LAB_0010d61e;
      *puVar16 = 0x2ff0;
      *(undefined4 **)(puVar16 + 2) = puVar16 + 0xc00;
    }
    uVar15 = (ulong)*(ushort *)(param_1 + 0x42);
    cVar6 = rm_wait_for_bar_firewall
                      (puVar16,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                       (byte)*(uint *)(param_1 + 0x38) >> 3,*(uint *)(param_1 + 0x38) & 7,
                       *(undefined2 *)(param_1 + 0x3e));
    if (cVar6 == '\0') {
      nv_printf(4,"NVRM: failed to wait for bar firewall to lower\n",extraout_RDX,uVar15);
LAB_0010d19d:
      uStack_76 = 0;
      pci_read_config_word(param_1,4,&uStack_76);
      pci_disable_device(param_1);
      pci_read_config_word(param_1,4,(long)&uStack_76 + 2);
      uVar7 = uStack_76._2_2_ | 2;
      uVar19 = (ushort)uStack_76 & 1;
      uStack_76 = uStack_76 | 0x20000;
      pci_write_config_word(param_1,4,uVar19 | uVar7);
      *(undefined8 *)(param_1 + 0x148) = 0;
    }
    else {
      cVar6 = rm_is_supported_pci_device
                        (*(uint *)(param_1 + 0x44) >> 0x10 & 0xff,
                         *(uint *)(param_1 + 0x44) >> 8 & 0xff,*(undefined2 *)(param_1 + 0x3c),
                         *(undefined2 *)(param_1 + 0x3e),*(undefined2 *)(param_1 + 0x40),
                         *(undefined2 *)(param_1 + 0x42));
      if (cVar6 == '\0') {
        nv_printf(4,"NVRM: ignoring the legacy GPU %04x:%02x:%02x.%x\n",
                  **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                  *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                  *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        goto LAB_0010d19d;
      }
      num_probed_nv_devices = num_probed_nv_devices + 1;
      iVar8 = pci_enable_device(param_1);
      if (iVar8 != 0) {
        nv_printf(4,"NVRM: pci_enable_device failed, aborting\n");
        goto LAB_0010d19d;
      }
      if (((*(int *)(param_1 + 0x3ec) == 0) &&
          (cVar6 = pci_find_capability(param_1,0x11), cVar6 == '\0')) &&
         (iVar8 = nv_get_hypervisor_type(), iVar8 != 2)) {
        nv_printf(4,"NVRM: Can\'t find an IRQ for your NVIDIA card!\n");
        nv_printf(4,"NVRM: Please check your BIOS settings.\n");
        nv_printf(4,"NVRM: [Plug & Play OS] should be set to NO\n");
        nv_printf(4,"NVRM: [Assign IRQ to VGA] should be set to YES \n");
        goto LAB_0010d19d;
      }
      cVar6 = nv_pci_validate_bars(param_1,1);
      if (cVar6 == '\0') goto LAB_0010d19d;
      lVar11 = 0;
      if (*(long *)(param_1 + 0x3f8) != 0) {
        lVar11 = (*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0);
      }
      lVar11 = __request_region(&iomem_resource,*(long *)(param_1 + 0x3f0),lVar11,nv_device_name,0);
      if (lVar11 == 0) {
        uVar15 = 0;
        if (*(long *)(param_1 + 0x3f8) != 0) {
          uVar15 = (ulong)((*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0)) >> 0x14;
        }
        nv_printf(4,
                  "NVRM: request_mem_region failed for %lluM @ 0x%llx. This can\nNVRM: occur when a driver such as rivatv is loaded and claims\nNVRM: ownership of the device\'s registers.\n"
                  ,uVar15);
        goto LAB_0010d19d;
      }
      lVar11 = __kmalloc_large_noprof(0x5298,0x2dc0);
      if (lVar11 == 0) {
        nv_printf(4,"NVRM: failed to allocate memory\n");
        lStack_98 = 0;
      }
      else {
        os_mem_copy(lVar11 + 0x34a,"??.??.??.??.??",0xf);
        plVar12 = (long *)(param_1 + 0x3f0);
        iVar8 = 0;
        do {
          lVar13 = *plVar12;
          if (((lVar13 != 0) && (plVar12[1] != 0)) &&
             ((lVar22 = plVar12[1] - lVar13, lVar22 != -1 && ((*(byte *)(plVar12 + 3) & 1) == 0))))
          {
            *(long *)(lVar11 + 0x90) = lVar13;
            *(int *)(lVar11 + 0xa0) = iVar8 * 4 + 0x10;
            *(long *)(lVar11 + 0x98) = lVar22 + 1;
            break;
          }
          iVar8 = iVar8 + 1;
          plVar12 = plVar12 + 8;
        } while (iVar8 != 6);
        *(long *)(lVar11 + 8) = lVar11;
        *(long *)(lVar11 + 0x108) = lVar11 + 0x90;
        *(undefined8 *)(param_1 + 0x88) = 0xffffffff;
        *(long *)(lVar11 + 0x3b0) = param_1 + 0xd0;
        *(long *)(lVar11 + 0x51b8) = param_1 + 0xd0;
        *(long *)(param_1 + 0x148) = lVar11;
        *(undefined4 *)(lVar11 + 0x1c) = *(undefined4 *)(param_1 + 0x3c);
        uVar2 = *(undefined2 *)(param_1 + 0x42);
        *(long *)(lVar11 + 0x3b8) = param_1;
        *(undefined2 *)(lVar11 + 0x20) = uVar2;
        *(undefined2 *)(lVar11 + 0x22) = *(undefined2 *)(param_1 + 0x40);
        *(long *)(lVar11 + 0x2e0) = lVar11 + 0x51a8;
        lVar13 = *(long *)(param_1 + 0x10);
        *(undefined4 *)(lVar11 + 0x14) = **(undefined4 **)(lVar13 + 200);
        uVar1 = *(undefined1 *)(lVar13 + 0xd8);
        *(long *)(lVar11 + 0x48) = param_1;
        *(undefined1 *)(lVar11 + 0x18) = uVar1;
        *(byte *)(lVar11 + 0x19) = *(byte *)(param_1 + 0x38) >> 3;
        cVar6 = nv_lock_init_locks(puVar16,lVar11);
        lStack_98 = lVar11;
        if ((cVar6 != '\0') && (iVar8 = rm_is_supported_device(puVar16,lVar11), iVar8 == 0)) {
          cVar6 = rm_init_private_state(puVar16,lVar11);
          if (cVar6 == '\0') {
            nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: rm_init_private_state() failed!\n",
                      *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                      *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
          }
          else if ((((*(char *)(lVar11 + 0x2b0) != '\0') ||
                    (sVar3 = *(short *)(param_1 + 0x3e), (ushort)(sVar3 + 0xdcc0U) < 0x40)) ||
                   ((ushort)(sVar3 + 0xd6c0U) < 0x40 || (ushort)(sVar3 + 0xce40U) < 0x40)) ||
                  ((sVar3 == 0x31a1 || (cVar6 = nv_pci_validate_bars(param_1,0), cVar6 != '\0')))) {
            lStack_80 = 0;
            uStack_82 = 0;
            if (NVreg_EnableResizableBar == 0) {
              nv_printf(0,"NVRM: resizable BAR disabled by regkey, skipping\n");
            }
            else {
              lStack_80 = pci_rebar_get_possible_sizes(param_1,1);
              if (lStack_80 != 0) {
                iVar8 = 0x1f;
                if ((uint)lStack_80 != 0) {
                  for (; (uint)lStack_80 >> iVar8 == 0; iVar8 = iVar8 + -1) {
                  }
                }
                lVar13 = 0;
                if (*(long *)(param_1 + 0x438) != 0) {
                  lVar13 = (*(long *)(param_1 + 0x438) + 1) - *(long *)(param_1 + 0x430);
                }
                iVar9 = pci_rebar_bytes_to_size(lVar13);
                if (iVar8 == iVar9) {
                  nv_printf(0,"NVRM: %04x:%02x:%02x.%x: BAR1 already at requested size.\n",
                            **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                            *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                            *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                }
                else {
                  lVar13 = pci_find_host_bridge();
                  if ((*(byte *)(lVar13 + 0x3b9) & 4) == 0) {
                    nv_printf(0,"NVRM: %04x:%02x:%02x.%x: Attempting to resize BAR1.\n",
                              **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                    pci_read_config_word(param_1,4,&uStack_82);
                    pci_write_config_word(param_1,4,uStack_82 & 0xfffd);
                    pci_release_resource(param_1,1);
                    pci_release_resource(param_1,3);
LAB_0010cdf3:
                    do {
                      iVar10 = pci_resize_resource(param_1,1,iVar8,0);
                      if (iVar10 != 0) {
                        if (iVar10 == -0x1c) {
                          if (iVar9 < iVar8) {
                            iVar8 = 0x1f;
                            if ((uint)lStack_80 != 0) {
                              for (; (uint)lStack_80 >> iVar8 == 0; iVar8 = iVar8 + -1) {
                              }
                            }
                            LOCK();
                            pbVar4 = (byte *)((long)&lStack_80 + ((long)iVar8 >> 3));
                            *pbVar4 = *pbVar4 & ~('\x01' << ((long)iVar8 & 7U));
                            UNLOCK();
                            iVar8 = 0x1f;
                            if ((uint)lStack_80 != 0) {
                              for (; (uint)lStack_80 >> iVar8 == 0; iVar8 = iVar8 + -1) {
                              }
                            }
                            goto LAB_0010cdf3;
                          }
                          nv_printf(4,"NVRM: No address space to allocate resized BAR1.\n");
                        }
                        else if (iVar10 == -0x5f) {
                          nv_printf(3,"NVRM: BAR resize resource not supported.\n");
                        }
                        else {
                          nv_printf(3,"NVRM: BAR resizing failed with error `%d`.\n",iVar10);
                        }
                      }
                      pci_assign_unassigned_bus_resources(*(undefined8 *)(param_1 + 0x10));
                      if (((*(byte *)(param_1 + 1099) & 0x20) == 0) &&
                         ((*(byte *)(param_1 + 0x4cb) & 0x20) == 0)) {
                        pci_write_config_word(param_1,4,uStack_82);
                        goto LAB_0010ce44;
                      }
                      bVar23 = iVar9 != iVar8;
                      iVar8 = iVar9;
                    } while (bVar23);
                    nv_printf(4,"NVRM: FATAL: Failed to re-allocate BAR1.\n");
                    pci_write_config_word(param_1,4,uStack_82);
                    nv_printf(4,"NVRM: Fatal Error while attempting to resize PCIe BARs.\n");
                    rm_free_private_state(puVar16,lVar11);
                    goto LAB_0010d43a;
                  }
                  nv_printf(0,
                            "NVRM: Not resizing BAR because the firmware forbids moving windows.\n")
                  ;
                }
              }
            }
LAB_0010ce44:
            *(undefined1 *)(lVar11 + 0x892) = 1;
            *(long *)(lVar11 + 0x880) = lVar11 + 0x880;
            *(undefined2 *)(lVar11 + 0x890) = 0x101;
            *(long *)(lVar11 + 0x888) = lVar11 + 0x880;
            if (*(char *)(lVar11 + 0x2b0) == '\0') {
              iVar8 = 0x10;
              lVar13 = 1;
              uVar15 = 0;
              while (uVar20 = (int)uVar15 + 1, uVar20 != 6) {
                while( true ) {
                  iVar8 = iVar8 + 4;
                  uVar15 = (ulong)uVar20;
                  lVar14 = uVar15 * 0x40 + param_1;
                  lVar22 = *(long *)(lVar14 + 0x3f0);
                  if ((((lVar22 == 0) || (lVar14 = *(long *)(lVar14 + 0x3f8), lVar14 == 0)) ||
                      (lVar14 = lVar14 - lVar22, lVar14 == -1)) ||
                     ((*(byte *)(param_1 + 0x408 + uVar15 * 0x40) & 1) != 0)) break;
                  iVar9 = (int)lVar13;
                  uVar20 = uVar20 + 1;
                  *(int *)(lVar11 + 0xa0 + lVar13 * 0x28) = iVar8;
                  *(long *)(lVar11 + 0x98 + lVar13 * 0x28) = lVar14 + 1;
                  *(long *)(lVar11 + 0x90 + lVar13 * 0x28) = lVar22;
                  lVar13 = 2;
                  if (iVar9 == 2 || uVar20 == 6) goto LAB_0010cf0a;
                }
              }
            }
LAB_0010cf0a:
            *(undefined4 *)(lVar11 + 0x4a4) = 0;
            *(long *)(lVar11 + 0x140) = lVar11 + 0xb8;
            uVar21 = *(undefined4 *)(param_1 + 0x3ec);
            *(undefined4 *)(lVar11 + 0x4a0) = 0xffffffff;
            *(undefined4 *)(lVar11 + 0x17c) = uVar21;
            cVar6 = pci_ats_supported(*(undefined8 *)(lVar11 + 0x3b8));
            bVar18 = 0;
            *(char *)(lVar11 + 0x329) = cVar6;
            if (cVar6 != '\0') {
              nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: ATS supported by this GPU!\n",
                        *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                        *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
              bVar18 = *(byte *)(lVar11 + 0x329);
            }
            nv_ats_supported = nv_ats_supported | bVar18;
            nv_clk_get_handles(lVar11);
            pci_set_master(param_1);
            vga_set_legacy_decoding(param_1,0);
            if ((*(byte *)(lVar11 + 0x11) & 0x80) == 0) {
              uVar21 = *(undefined4 *)(*(long *)(lVar11 + 0x3b0) + 0x2b8);
              *(bool *)(lVar11 + 0x5290) = NVreg_GpuInitOnProbe != 0;
              *(undefined4 *)(lVar11 + 0x32c) = uVar21;
              iVar8 = nv_linux_init_open_q(lVar11);
              if (iVar8 == 0) {
                nv_printf(0,"NVRM: PCI:%04x:%02x:%02x.%x (%04x:%04x): BAR0 @ 0x%llx (%lluMB)\n",
                          *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                          *(undefined1 *)(lVar11 + 0x19),*(uint *)(param_1 + 0x38) & 7,
                          *(undefined2 *)(lVar11 + 0x1c),*(undefined2 *)(lVar11 + 0x1e),
                          **(undefined8 **)(lVar11 + 0x108),
                          (ulong)(*(undefined8 **)(lVar11 + 0x108))[1] >> 0x14);
                nv_printf(0,"NVRM: PCI:%04x:%02x:%02x.%x (%04x:%04x): BAR1 @ 0x%llx (%lluMB)\n",
                          *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                          *(undefined1 *)(lVar11 + 0x19),*(uint *)(param_1 + 0x38) & 7,
                          *(undefined2 *)(lVar11 + 0x1c),*(undefined2 *)(lVar11 + 0x1e),
                          **(undefined8 **)(lVar11 + 0x140),
                          (ulong)(*(undefined8 **)(lVar11 + 0x140))[1] >> 0x14);
                num_nv_devices = num_nv_devices + 1;
                pm_vt_switch_required(*(undefined8 *)(lVar11 + 0x3b0),1);
                rm_init_tegra_dynamic_power_management(puVar16,lVar11);
                lVar13 = *(long *)(param_1 + 0x148);
                acStack_72[0x30] = '\0';
                acStack_72[0x31] = '\0';
                *(undefined8 *)(lVar13 + 0x818) = 0;
                acStack_72[0] = '\0';
                acStack_72[1] = '\0';
                acStack_72[2] = '\0';
                acStack_72[3] = '\0';
                acStack_72[4] = '\0';
                acStack_72[5] = '\0';
                acStack_72[6] = '\0';
                acStack_72[7] = '\0';
                acStack_72[8] = '\0';
                acStack_72[9] = '\0';
                acStack_72[10] = '\0';
                acStack_72[0xb] = '\0';
                acStack_72[0xc] = '\0';
                acStack_72[0xd] = '\0';
                acStack_72[0xe] = '\0';
                acStack_72[0xf] = '\0';
                acStack_72[0x10] = '\0';
                acStack_72[0x11] = '\0';
                acStack_72[0x12] = '\0';
                acStack_72[0x13] = '\0';
                acStack_72[0x14] = '\0';
                acStack_72[0x15] = '\0';
                acStack_72[0x16] = '\0';
                acStack_72[0x17] = '\0';
                acStack_72[0x18] = '\0';
                acStack_72[0x19] = '\0';
                acStack_72[0x1a] = '\0';
                acStack_72[0x1b] = '\0';
                acStack_72[0x1c] = '\0';
                acStack_72[0x1d] = '\0';
                acStack_72[0x1e] = '\0';
                acStack_72[0x1f] = '\0';
                acStack_72[0x20] = '\0';
                acStack_72[0x21] = '\0';
                acStack_72[0x22] = '\0';
                acStack_72[0x23] = '\0';
                acStack_72[0x24] = '\0';
                acStack_72[0x25] = '\0';
                acStack_72[0x26] = '\0';
                acStack_72[0x27] = '\0';
                acStack_72[0x28] = '\0';
                acStack_72[0x29] = '\0';
                acStack_72[0x2a] = '\0';
                acStack_72[0x2b] = '\0';
                acStack_72[0x2c] = '\0';
                acStack_72[0x2d] = '\0';
                acStack_72[0x2e] = '\0';
                acStack_72[0x2f] = '\0';
                iVar8 = snprintf(acStack_72,0x32,"/sys/bus/pci/devices/%04x:%02x:%02x.0/config",
                                 (ulong)**(uint **)(*(long *)(param_1 + 0x10) + 200),
                                 (ulong)*(byte *)(*(long *)(param_1 + 0x10) + 0xd8),
                                 (ulong)(*(uint *)(param_1 + 0x38) >> 3 & 0x1f));
                if (iVar8 - 1U < 0x31) {
                  uVar15 = filp_open(acStack_72,0,0);
                  if (uVar15 < 0xfffffffffffff001) {
                    if (((((*(long *)(uVar15 + 0x20) != 0) &&
                          (lVar22 = *(long *)(*(long *)(uVar15 + 0x20) + 0x28), lVar22 != 0)) &&
                         ((iVar8 = strcmp((char *)(lVar22 + 0x3b0),"sysfs"), iVar8 == 0 &&
                          ((lVar22 = *(long *)(uVar15 + 0x18), lVar22 != 0 &&
                           (uVar15 == *(ulong *)(lVar22 + 0x60))))))) &&
                        (*(long *)(lVar22 + 0x50) == 0)) &&
                       (((lVar14 = *(long *)(lVar22 + 0x68), lVar14 != 0 &&
                         (uVar15 == *(ulong *)(lVar14 + 8))) && (lVar22 == *(long *)(lVar14 + 0x10))
                        ))) {
                      *(ulong *)(lVar13 + 0x818) = uVar15;
                    }
                    if (*(long *)(lVar13 + 0x818) == 0) {
                      filp_close(uVar15,0);
                      goto LAB_0010d100;
                    }
                  }
                  iVar8 = nv_get_hypervisor_type();
                  if (iVar8 == 4) goto LAB_0010d10e;
LAB_0010d208:
                  bStack_8e = nv_acpi_power_resource_method_present(param_1);
                }
                else {
LAB_0010d100:
                  iVar8 = nv_get_hypervisor_type();
                  if (iVar8 != 4) goto LAB_0010d208;
LAB_0010d10e:
                  if ((*(long *)(param_1 + 0x10) != 0) &&
                     (*(long *)(*(long *)(param_1 + 0x10) + 0x38) != 0)) {
                    bStack_8e = nv_acpi_power_resource_method_present();
                  }
                }
                rm_init_dynamic_power_management(puVar16,lVar13,bStack_8e);
                lVar13 = *(long *)(param_1 + 0x148);
                if (*(char *)(lVar13 + 0x2b1) != '\0') {
                  *(undefined4 *)(lVar13 + 0x2b4) = 0xffffffff;
                  nv_set_gpu_pg_mask(lVar13);
                  nv_trigger_gpu_flr(lVar13);
                }
                rm_get_gpu_uuid_raw(puVar16,lVar11);
                nv_parse_per_device_option_string(puVar16);
                rm_set_rm_firmware_requested(puVar16,lVar11);
                if (NVreg_ExcludeAllGpus == 0) {
                  lVar13 = rm_get_gpu_uuid(puVar16,lVar11);
                  if (lVar13 == 0) {
                    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Unable to read UUID",
                              *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                              *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                  }
                  else {
                    cVar6 = nv_is_uuid_in_gpu_exclusion_list(lVar13);
                    if (cVar6 != '\0') {
                      uVar17 = rm_exclude_adapter(puVar16,lVar11);
                      if ((int)uVar17 == 0) {
                        *(uint *)(lVar11 + 0x10) = *(uint *)(lVar11 + 0x10) | 2;
                        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Excluded GPU %s successfully\n",
                                  *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                                  *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                      }
                      else {
                        nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to exclude GPU %s (0x%x)\n"
                                  ,*(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                                  *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a),
                                  lVar13,uVar17);
                      }
                    }
                    os_free_mem(lVar13);
                  }
                }
                else {
                  nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Excluding all GPUs as requested\n",
                            *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                            *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                  *(uint *)(lVar11 + 0x10) = *(uint *)(lVar11 + 0x10) | 2;
                }
                *(undefined4 *)(*(long *)(lVar11 + 0x3b0) + 0xe8) = 1;
                if ((*(short *)(param_1 + 0x3c) == 0x10de) && (*(short *)(param_1 + 0x3e) == 0x2b00)
                   ) {
                  lVar13 = *(long *)(param_1 + 0x148);
                  *(undefined1 **)(lVar13 + 0x5240) = gb10b_tegra_devfreq_table;
                  *(undefined4 *)(lVar13 + 0x5248) = 6;
                  *(code **)(lVar13 + 0x5270) = nv_pci_gb10b_suspend_devfreq;
                  *(code **)(lVar13 + 0x5278) = nv_pci_gb10b_resume_devfreq;
                  *(code **)(lVar13 + 0x5280) = nv_pci_gb10b_devfreq_enable_boost;
                  *(code **)(lVar13 + 0x5288) = nv_pci_gb10b_devfreq_disable_boost;
                  iVar8 = nv_pci_gb10b_register_devfreq(param_1);
                  if (iVar8 == 0) goto LAB_0010d322;
                  lVar13 = *(long *)(param_1 + 0x148);
                  if (*(long *)(lVar13 + 0x5250) != 0) {
                    nv_pci_tegra_devfreq_remove();
                    *(undefined8 *)(lVar13 + 0x5250) = 0;
                  }
                  if (*(long *)(lVar13 + 0x5258) != 0) {
                    nv_pci_tegra_devfreq_remove();
                    *(undefined8 *)(lVar13 + 0x5258) = 0;
                  }
                  nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to register linux devfreq",
                            *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                            *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                }
                else {
LAB_0010d322:
                  down(nv_linux_devices_lock);
                  iVar8 = nv_linux_assign_minor_locked(lVar11);
                  if (iVar8 == 0) {
                    up(nv_linux_devices_lock);
                    if ((*(char *)(lVar11 + 0x5290) != '\0') &&
                       ((*(byte *)(lVar11 + 0x10) & 2) == 0)) {
                      nv_printf(1,"NVRM: Starting device %04x:%02x:%02x.%x\n",
                                **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7)
                      ;
                      uVar17 = nv_start_device(lVar11,puVar16);
                      if ((int)uVar17 != 0) {
                        nv_printf(4,"NVRM: Device start failed for %04x:%02x:%02x.%x (ret=%d)\n",
                                  **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                                  *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                                  *(uint *)(param_1 + 0x38) >> 3 & 0x1f,
                                  *(uint *)(param_1 + 0x38) & 7,uVar17);
                        down(nv_linux_devices_lock);
                        nv_linux_remove_minor_locked(lVar11);
                        up(nv_linux_devices_lock);
                        goto LAB_0010d8bf;
                      }
                    }
                    down(nv_linux_devices_lock);
                    nv_linux_add_device_locked(lVar11);
                    up(nv_linux_devices_lock);
                    nv_procfs_add_gpu(lVar11);
                    rm_notify_gpu_addition(puVar16,lVar11);
                    nvidia_modeset_probe(lVar11);
                    rm_enable_dynamic_power_management(puVar16,lVar11);
                    uVar21 = 0;
                    if ((puVar16 != (undefined4 *)0x0) &&
                       (cVar6 = rm_is_altstack_in_use(), cVar6 != '\0')) {
                      kmem_cache_free(nvidia_stack_t_cache,puVar16);
                    }
                    goto LAB_0010d3c6;
                  }
                  up(nv_linux_devices_lock);
                }
LAB_0010d8bf:
                rm_cleanup_dynamic_power_management(puVar16,lVar11);
                pm_vt_switch_unregister(*(undefined8 *)(lVar11 + 0x3b0));
                nv_linux_stop_open_q(lVar11);
              }
              else {
                nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: nv_linux_init_open_q() failed!\n",
                          *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                          *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
              }
            }
            else {
              nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping nv_pci_probe\n",
                        *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                        *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
            }
            nv_clk_clear_handles(lVar11);
            nv_ats_supported = bVar5;
            rm_free_private_state(puVar16,lVar11);
            goto LAB_0010d43a;
          }
          rm_free_private_state(puVar16,lVar11);
        }
      }
LAB_0010d43a:
      nv_lock_destroy_locks(puVar16,lStack_98);
      lVar13 = 0;
      if (*(long *)(param_1 + 0x3f8) != 0) {
        lVar13 = (*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0);
      }
      __release_region(&iomem_resource,*(long *)(param_1 + 0x3f0),lVar13);
      uStack_76 = 0;
      pci_read_config_word(param_1,4,&uStack_76);
      pci_disable_device(param_1);
      pci_read_config_word(param_1,4,(long)&uStack_76 + 2);
      uVar7 = uStack_76._2_2_ | 2;
      uVar19 = (ushort)uStack_76 & 1;
      uStack_76 = uStack_76 | 0x20000;
      pci_write_config_word(param_1,4,uVar19 | uVar7);
      *(undefined8 *)(param_1 + 0x148) = 0;
      if (lVar11 != 0) {
        kfree(lVar11);
      }
    }
    if ((puVar16 != (undefined4 *)0x0) && (cVar6 = rm_is_altstack_in_use(), cVar6 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar16);
    }
  }
  else {
    nv_printf(4,"NVRM: Ignoring probe for VF %04x:%02x:%02x.%x ",
              **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
  }
LAB_0010d61e:
  uVar21 = 0xffffffff;
LAB_0010d3c6:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar21;
}


// ===== 0010c9e0 nv_pci_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010d3ec) */

undefined4 nv_pci_probe(long param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  byte *pbVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  undefined4 *puVar16;
  undefined8 uVar17;
  byte bVar18;
  ushort uVar19;
  undefined8 extraout_RDX;
  uint uVar20;
  undefined4 uVar21;
  long lVar22;
  long in_GS_OFFSET;
  bool bVar23;
  long local_98;
  byte local_8e;
  ushort local_82;
  long local_80;
  undefined4 local_76;
  char local_72 [50];
  long local_40;
  
  bVar5 = nv_ats_supported;
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  nv_printf(1,"NVRM: probing 0x%x 0x%x, class 0x%x\n",*(undefined2 *)(param_1 + 0x3c),
            *(undefined2 *)(param_1 + 0x3e),*(undefined4 *)(param_1 + 0x44));
  local_8e = *(byte *)(param_1 + 0x873) & 1;
  if ((*(byte *)(param_1 + 0x873) & 1) == 0) {
    puVar16 = (undefined4 *)0x0;
    cVar6 = rm_is_altstack_in_use();
    if (cVar6 != '\0') {
      puVar16 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar16 == (undefined4 *)0x0) goto LAB_0010d61e;
      *puVar16 = 0x2ff0;
      *(undefined4 **)(puVar16 + 2) = puVar16 + 0xc00;
    }
    uVar15 = (ulong)*(ushort *)(param_1 + 0x42);
    cVar6 = rm_wait_for_bar_firewall
                      (puVar16,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                       (byte)*(uint *)(param_1 + 0x38) >> 3,*(uint *)(param_1 + 0x38) & 7,
                       *(undefined2 *)(param_1 + 0x3e));
    if (cVar6 == '\0') {
      nv_printf(4,"NVRM: failed to wait for bar firewall to lower\n",extraout_RDX,uVar15);
LAB_0010d19d:
      local_76 = 0;
      pci_read_config_word(param_1,4,&local_76);
      pci_disable_device(param_1);
      pci_read_config_word(param_1,4,(long)&local_76 + 2);
      uVar7 = local_76._2_2_ | 2;
      uVar19 = (ushort)local_76 & 1;
      local_76 = local_76 | 0x20000;
      pci_write_config_word(param_1,4,uVar19 | uVar7);
      *(undefined8 *)(param_1 + 0x148) = 0;
    }
    else {
      cVar6 = rm_is_supported_pci_device
                        (*(uint *)(param_1 + 0x44) >> 0x10 & 0xff,
                         *(uint *)(param_1 + 0x44) >> 8 & 0xff,*(undefined2 *)(param_1 + 0x3c),
                         *(undefined2 *)(param_1 + 0x3e),*(undefined2 *)(param_1 + 0x40),
                         *(undefined2 *)(param_1 + 0x42));
      if (cVar6 == '\0') {
        nv_printf(4,"NVRM: ignoring the legacy GPU %04x:%02x:%02x.%x\n",
                  **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                  *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                  *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        goto LAB_0010d19d;
      }
      num_probed_nv_devices = num_probed_nv_devices + 1;
      iVar8 = pci_enable_device(param_1);
      if (iVar8 != 0) {
        nv_printf(4,"NVRM: pci_enable_device failed, aborting\n");
        goto LAB_0010d19d;
      }
      if (((*(int *)(param_1 + 0x3ec) == 0) &&
          (cVar6 = pci_find_capability(param_1,0x11), cVar6 == '\0')) &&
         (iVar8 = nv_get_hypervisor_type(), iVar8 != 2)) {
        nv_printf(4,"NVRM: Can\'t find an IRQ for your NVIDIA card!\n");
        nv_printf(4,"NVRM: Please check your BIOS settings.\n");
        nv_printf(4,"NVRM: [Plug & Play OS] should be set to NO\n");
        nv_printf(4,"NVRM: [Assign IRQ to VGA] should be set to YES \n");
        goto LAB_0010d19d;
      }
      cVar6 = nv_pci_validate_bars(param_1,1);
      if (cVar6 == '\0') goto LAB_0010d19d;
      lVar11 = 0;
      if (*(long *)(param_1 + 0x3f8) != 0) {
        lVar11 = (*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0);
      }
      lVar11 = __request_region(&iomem_resource,*(long *)(param_1 + 0x3f0),lVar11,nv_device_name,0);
      if (lVar11 == 0) {
        uVar15 = 0;
        if (*(long *)(param_1 + 0x3f8) != 0) {
          uVar15 = (ulong)((*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0)) >> 0x14;
        }
        nv_printf(4,
                  "NVRM: request_mem_region failed for %lluM @ 0x%llx. This can\nNVRM: occur when a driver such as rivatv is loaded and claims\nNVRM: ownership of the device\'s registers.\n"
                  ,uVar15);
        goto LAB_0010d19d;
      }
      lVar11 = __kmalloc_large_noprof(0x5298,0x2dc0);
      if (lVar11 == 0) {
        nv_printf(4,"NVRM: failed to allocate memory\n");
        local_98 = 0;
      }
      else {
        os_mem_copy(lVar11 + 0x34a,"??.??.??.??.??",0xf);
        plVar12 = (long *)(param_1 + 0x3f0);
        iVar8 = 0;
        do {
          lVar13 = *plVar12;
          if (((lVar13 != 0) && (plVar12[1] != 0)) &&
             ((lVar22 = plVar12[1] - lVar13, lVar22 != -1 && ((*(byte *)(plVar12 + 3) & 1) == 0))))
          {
            *(long *)(lVar11 + 0x90) = lVar13;
            *(int *)(lVar11 + 0xa0) = iVar8 * 4 + 0x10;
            *(long *)(lVar11 + 0x98) = lVar22 + 1;
            break;
          }
          iVar8 = iVar8 + 1;
          plVar12 = plVar12 + 8;
        } while (iVar8 != 6);
        *(long *)(lVar11 + 8) = lVar11;
        *(long *)(lVar11 + 0x108) = lVar11 + 0x90;
        *(undefined8 *)(param_1 + 0x88) = 0xffffffff;
        *(long *)(lVar11 + 0x3b0) = param_1 + 0xd0;
        *(long *)(lVar11 + 0x51b8) = param_1 + 0xd0;
        *(long *)(param_1 + 0x148) = lVar11;
        *(undefined4 *)(lVar11 + 0x1c) = *(undefined4 *)(param_1 + 0x3c);
        uVar2 = *(undefined2 *)(param_1 + 0x42);
        *(long *)(lVar11 + 0x3b8) = param_1;
        *(undefined2 *)(lVar11 + 0x20) = uVar2;
        *(undefined2 *)(lVar11 + 0x22) = *(undefined2 *)(param_1 + 0x40);
        *(long *)(lVar11 + 0x2e0) = lVar11 + 0x51a8;
        lVar13 = *(long *)(param_1 + 0x10);
        *(undefined4 *)(lVar11 + 0x14) = **(undefined4 **)(lVar13 + 200);
        uVar1 = *(undefined1 *)(lVar13 + 0xd8);
        *(long *)(lVar11 + 0x48) = param_1;
        *(undefined1 *)(lVar11 + 0x18) = uVar1;
        *(byte *)(lVar11 + 0x19) = *(byte *)(param_1 + 0x38) >> 3;
        cVar6 = nv_lock_init_locks(puVar16,lVar11);
        local_98 = lVar11;
        if ((cVar6 != '\0') && (iVar8 = rm_is_supported_device(puVar16,lVar11), iVar8 == 0)) {
          cVar6 = rm_init_private_state(puVar16,lVar11);
          if (cVar6 == '\0') {
            nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: rm_init_private_state() failed!\n",
                      *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                      *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
          }
          else if ((((*(char *)(lVar11 + 0x2b0) != '\0') ||
                    (sVar3 = *(short *)(param_1 + 0x3e), (ushort)(sVar3 + 0xdcc0U) < 0x40)) ||
                   ((ushort)(sVar3 + 0xd6c0U) < 0x40 || (ushort)(sVar3 + 0xce40U) < 0x40)) ||
                  ((sVar3 == 0x31a1 || (cVar6 = nv_pci_validate_bars(param_1,0), cVar6 != '\0')))) {
            local_80 = 0;
            local_82 = 0;
            if (NVreg_EnableResizableBar == 0) {
              nv_printf(0,"NVRM: resizable BAR disabled by regkey, skipping\n");
            }
            else {
              local_80 = pci_rebar_get_possible_sizes(param_1,1);
              if (local_80 != 0) {
                iVar8 = 0x1f;
                if ((uint)local_80 != 0) {
                  for (; (uint)local_80 >> iVar8 == 0; iVar8 = iVar8 + -1) {
                  }
                }
                lVar13 = 0;
                if (*(long *)(param_1 + 0x438) != 0) {
                  lVar13 = (*(long *)(param_1 + 0x438) + 1) - *(long *)(param_1 + 0x430);
                }
                iVar9 = pci_rebar_bytes_to_size(lVar13);
                if (iVar8 == iVar9) {
                  nv_printf(0,"NVRM: %04x:%02x:%02x.%x: BAR1 already at requested size.\n",
                            **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                            *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                            *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                }
                else {
                  lVar13 = pci_find_host_bridge();
                  if ((*(byte *)(lVar13 + 0x3b9) & 4) == 0) {
                    nv_printf(0,"NVRM: %04x:%02x:%02x.%x: Attempting to resize BAR1.\n",
                              **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                    pci_read_config_word(param_1,4,&local_82);
                    pci_write_config_word(param_1,4,local_82 & 0xfffd);
                    pci_release_resource(param_1,1);
                    pci_release_resource(param_1,3);
LAB_0010cdf3:
                    do {
                      iVar10 = pci_resize_resource(param_1,1,iVar8,0);
                      if (iVar10 != 0) {
                        if (iVar10 == -0x1c) {
                          if (iVar9 < iVar8) {
                            iVar8 = 0x1f;
                            if ((uint)local_80 != 0) {
                              for (; (uint)local_80 >> iVar8 == 0; iVar8 = iVar8 + -1) {
                              }
                            }
                            LOCK();
                            pbVar4 = (byte *)((long)&local_80 + ((long)iVar8 >> 3));
                            *pbVar4 = *pbVar4 & ~('\x01' << ((long)iVar8 & 7U));
                            UNLOCK();
                            iVar8 = 0x1f;
                            if ((uint)local_80 != 0) {
                              for (; (uint)local_80 >> iVar8 == 0; iVar8 = iVar8 + -1) {
                              }
                            }
                            goto LAB_0010cdf3;
                          }
                          nv_printf(4,"NVRM: No address space to allocate resized BAR1.\n");
                        }
                        else if (iVar10 == -0x5f) {
                          nv_printf(3,"NVRM: BAR resize resource not supported.\n");
                        }
                        else {
                          nv_printf(3,"NVRM: BAR resizing failed with error `%d`.\n",iVar10);
                        }
                      }
                      pci_assign_unassigned_bus_resources(*(undefined8 *)(param_1 + 0x10));
                      if (((*(byte *)(param_1 + 1099) & 0x20) == 0) &&
                         ((*(byte *)(param_1 + 0x4cb) & 0x20) == 0)) {
                        pci_write_config_word(param_1,4,local_82);
                        goto LAB_0010ce44;
                      }
                      bVar23 = iVar9 != iVar8;
                      iVar8 = iVar9;
                    } while (bVar23);
                    nv_printf(4,"NVRM: FATAL: Failed to re-allocate BAR1.\n");
                    pci_write_config_word(param_1,4,local_82);
                    nv_printf(4,"NVRM: Fatal Error while attempting to resize PCIe BARs.\n");
                    rm_free_private_state(puVar16,lVar11);
                    goto LAB_0010d43a;
                  }
                  nv_printf(0,
                            "NVRM: Not resizing BAR because the firmware forbids moving windows.\n")
                  ;
                }
              }
            }
LAB_0010ce44:
            *(undefined1 *)(lVar11 + 0x892) = 1;
            *(long *)(lVar11 + 0x880) = lVar11 + 0x880;
            *(undefined2 *)(lVar11 + 0x890) = 0x101;
            *(long *)(lVar11 + 0x888) = lVar11 + 0x880;
            if (*(char *)(lVar11 + 0x2b0) == '\0') {
              iVar8 = 0x10;
              lVar13 = 1;
              uVar15 = 0;
              while (uVar20 = (int)uVar15 + 1, uVar20 != 6) {
                while( true ) {
                  iVar8 = iVar8 + 4;
                  uVar15 = (ulong)uVar20;
                  lVar14 = uVar15 * 0x40 + param_1;
                  lVar22 = *(long *)(lVar14 + 0x3f0);
                  if ((((lVar22 == 0) || (lVar14 = *(long *)(lVar14 + 0x3f8), lVar14 == 0)) ||
                      (lVar14 = lVar14 - lVar22, lVar14 == -1)) ||
                     ((*(byte *)(param_1 + 0x408 + uVar15 * 0x40) & 1) != 0)) break;
                  iVar9 = (int)lVar13;
                  uVar20 = uVar20 + 1;
                  *(int *)(lVar11 + 0xa0 + lVar13 * 0x28) = iVar8;
                  *(long *)(lVar11 + 0x98 + lVar13 * 0x28) = lVar14 + 1;
                  *(long *)(lVar11 + 0x90 + lVar13 * 0x28) = lVar22;
                  lVar13 = 2;
                  if (iVar9 == 2 || uVar20 == 6) goto LAB_0010cf0a;
                }
              }
            }
LAB_0010cf0a:
            *(undefined4 *)(lVar11 + 0x4a4) = 0;
            *(long *)(lVar11 + 0x140) = lVar11 + 0xb8;
            uVar21 = *(undefined4 *)(param_1 + 0x3ec);
            *(undefined4 *)(lVar11 + 0x4a0) = 0xffffffff;
            *(undefined4 *)(lVar11 + 0x17c) = uVar21;
            cVar6 = pci_ats_supported(*(undefined8 *)(lVar11 + 0x3b8));
            bVar18 = 0;
            *(char *)(lVar11 + 0x329) = cVar6;
            if (cVar6 != '\0') {
              nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: ATS supported by this GPU!\n",
                        *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                        *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
              bVar18 = *(byte *)(lVar11 + 0x329);
            }
            nv_ats_supported = nv_ats_supported | bVar18;
            nv_clk_get_handles(lVar11);
            pci_set_master(param_1);
            vga_set_legacy_decoding(param_1,0);
            if ((*(byte *)(lVar11 + 0x11) & 0x80) == 0) {
              uVar21 = *(undefined4 *)(*(long *)(lVar11 + 0x3b0) + 0x2b8);
              *(bool *)(lVar11 + 0x5290) = NVreg_GpuInitOnProbe != 0;
              *(undefined4 *)(lVar11 + 0x32c) = uVar21;
              iVar8 = nv_linux_init_open_q(lVar11);
              if (iVar8 == 0) {
                nv_printf(0,"NVRM: PCI:%04x:%02x:%02x.%x (%04x:%04x): BAR0 @ 0x%llx (%lluMB)\n",
                          *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                          *(undefined1 *)(lVar11 + 0x19),*(uint *)(param_1 + 0x38) & 7,
                          *(undefined2 *)(lVar11 + 0x1c),*(undefined2 *)(lVar11 + 0x1e),
                          **(undefined8 **)(lVar11 + 0x108),
                          (ulong)(*(undefined8 **)(lVar11 + 0x108))[1] >> 0x14);
                nv_printf(0,"NVRM: PCI:%04x:%02x:%02x.%x (%04x:%04x): BAR1 @ 0x%llx (%lluMB)\n",
                          *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                          *(undefined1 *)(lVar11 + 0x19),*(uint *)(param_1 + 0x38) & 7,
                          *(undefined2 *)(lVar11 + 0x1c),*(undefined2 *)(lVar11 + 0x1e),
                          **(undefined8 **)(lVar11 + 0x140),
                          (ulong)(*(undefined8 **)(lVar11 + 0x140))[1] >> 0x14);
                num_nv_devices = num_nv_devices + 1;
                pm_vt_switch_required(*(undefined8 *)(lVar11 + 0x3b0),1);
                rm_init_tegra_dynamic_power_management(puVar16,lVar11);
                lVar13 = *(long *)(param_1 + 0x148);
                local_72[0x30] = '\0';
                local_72[0x31] = '\0';
                *(undefined8 *)(lVar13 + 0x818) = 0;
                local_72[0] = '\0';
                local_72[1] = '\0';
                local_72[2] = '\0';
                local_72[3] = '\0';
                local_72[4] = '\0';
                local_72[5] = '\0';
                local_72[6] = '\0';
                local_72[7] = '\0';
                local_72[8] = '\0';
                local_72[9] = '\0';
                local_72[10] = '\0';
                local_72[0xb] = '\0';
                local_72[0xc] = '\0';
                local_72[0xd] = '\0';
                local_72[0xe] = '\0';
                local_72[0xf] = '\0';
                local_72[0x10] = '\0';
                local_72[0x11] = '\0';
                local_72[0x12] = '\0';
                local_72[0x13] = '\0';
                local_72[0x14] = '\0';
                local_72[0x15] = '\0';
                local_72[0x16] = '\0';
                local_72[0x17] = '\0';
                local_72[0x18] = '\0';
                local_72[0x19] = '\0';
                local_72[0x1a] = '\0';
                local_72[0x1b] = '\0';
                local_72[0x1c] = '\0';
                local_72[0x1d] = '\0';
                local_72[0x1e] = '\0';
                local_72[0x1f] = '\0';
                local_72[0x20] = '\0';
                local_72[0x21] = '\0';
                local_72[0x22] = '\0';
                local_72[0x23] = '\0';
                local_72[0x24] = '\0';
                local_72[0x25] = '\0';
                local_72[0x26] = '\0';
                local_72[0x27] = '\0';
                local_72[0x28] = '\0';
                local_72[0x29] = '\0';
                local_72[0x2a] = '\0';
                local_72[0x2b] = '\0';
                local_72[0x2c] = '\0';
                local_72[0x2d] = '\0';
                local_72[0x2e] = '\0';
                local_72[0x2f] = '\0';
                iVar8 = snprintf(local_72,0x32,"/sys/bus/pci/devices/%04x:%02x:%02x.0/config",
                                 (ulong)**(uint **)(*(long *)(param_1 + 0x10) + 200),
                                 (ulong)*(byte *)(*(long *)(param_1 + 0x10) + 0xd8),
                                 (ulong)(*(uint *)(param_1 + 0x38) >> 3 & 0x1f));
                if (iVar8 - 1U < 0x31) {
                  uVar15 = filp_open(local_72,0,0);
                  if (uVar15 < 0xfffffffffffff001) {
                    if (((((*(long *)(uVar15 + 0x20) != 0) &&
                          (lVar22 = *(long *)(*(long *)(uVar15 + 0x20) + 0x28), lVar22 != 0)) &&
                         ((iVar8 = strcmp((char *)(lVar22 + 0x3b0),"sysfs"), iVar8 == 0 &&
                          ((lVar22 = *(long *)(uVar15 + 0x18), lVar22 != 0 &&
                           (uVar15 == *(ulong *)(lVar22 + 0x60))))))) &&
                        (*(long *)(lVar22 + 0x50) == 0)) &&
                       (((lVar14 = *(long *)(lVar22 + 0x68), lVar14 != 0 &&
                         (uVar15 == *(ulong *)(lVar14 + 8))) && (lVar22 == *(long *)(lVar14 + 0x10))
                        ))) {
                      *(ulong *)(lVar13 + 0x818) = uVar15;
                    }
                    if (*(long *)(lVar13 + 0x818) == 0) {
                      filp_close(uVar15,0);
                      goto LAB_0010d100;
                    }
                  }
                  iVar8 = nv_get_hypervisor_type();
                  if (iVar8 == 4) goto LAB_0010d10e;
LAB_0010d208:
                  local_8e = nv_acpi_power_resource_method_present(param_1);
                }
                else {
LAB_0010d100:
                  iVar8 = nv_get_hypervisor_type();
                  if (iVar8 != 4) goto LAB_0010d208;
LAB_0010d10e:
                  if ((*(long *)(param_1 + 0x10) != 0) &&
                     (*(long *)(*(long *)(param_1 + 0x10) + 0x38) != 0)) {
                    local_8e = nv_acpi_power_resource_method_present();
                  }
                }
                rm_init_dynamic_power_management(puVar16,lVar13,local_8e);
                lVar13 = *(long *)(param_1 + 0x148);
                if (*(char *)(lVar13 + 0x2b1) != '\0') {
                  *(undefined4 *)(lVar13 + 0x2b4) = 0xffffffff;
                  nv_set_gpu_pg_mask(lVar13);
                  nv_trigger_gpu_flr(lVar13);
                }
                rm_get_gpu_uuid_raw(puVar16,lVar11);
                nv_parse_per_device_option_string(puVar16);
                rm_set_rm_firmware_requested(puVar16,lVar11);
                if (NVreg_ExcludeAllGpus == 0) {
                  lVar13 = rm_get_gpu_uuid(puVar16,lVar11);
                  if (lVar13 == 0) {
                    nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Unable to read UUID",
                              *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                              *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                  }
                  else {
                    cVar6 = nv_is_uuid_in_gpu_exclusion_list(lVar13);
                    if (cVar6 != '\0') {
                      uVar17 = rm_exclude_adapter(puVar16,lVar11);
                      if ((int)uVar17 == 0) {
                        *(uint *)(lVar11 + 0x10) = *(uint *)(lVar11 + 0x10) | 2;
                        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Excluded GPU %s successfully\n",
                                  *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                                  *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                      }
                      else {
                        nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to exclude GPU %s (0x%x)\n"
                                  ,*(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                                  *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a),
                                  lVar13,uVar17);
                      }
                    }
                    os_free_mem(lVar13);
                  }
                }
                else {
                  nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: Excluding all GPUs as requested\n",
                            *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                            *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                  *(uint *)(lVar11 + 0x10) = *(uint *)(lVar11 + 0x10) | 2;
                }
                *(undefined4 *)(*(long *)(lVar11 + 0x3b0) + 0xe8) = 1;
                if ((*(short *)(param_1 + 0x3c) == 0x10de) && (*(short *)(param_1 + 0x3e) == 0x2b00)
                   ) {
                  lVar13 = *(long *)(param_1 + 0x148);
                  *(undefined1 **)(lVar13 + 0x5240) = gb10b_tegra_devfreq_table;
                  *(undefined4 *)(lVar13 + 0x5248) = 6;
                  *(code **)(lVar13 + 0x5270) = nv_pci_gb10b_suspend_devfreq;
                  *(code **)(lVar13 + 0x5278) = nv_pci_gb10b_resume_devfreq;
                  *(code **)(lVar13 + 0x5280) = nv_pci_gb10b_devfreq_enable_boost;
                  *(code **)(lVar13 + 0x5288) = nv_pci_gb10b_devfreq_disable_boost;
                  iVar8 = nv_pci_gb10b_register_devfreq(param_1);
                  if (iVar8 == 0) goto LAB_0010d322;
                  lVar13 = *(long *)(param_1 + 0x148);
                  if (*(long *)(lVar13 + 0x5250) != 0) {
                    nv_pci_tegra_devfreq_remove();
                    *(undefined8 *)(lVar13 + 0x5250) = 0;
                  }
                  if (*(long *)(lVar13 + 0x5258) != 0) {
                    nv_pci_tegra_devfreq_remove();
                    *(undefined8 *)(lVar13 + 0x5258) = 0;
                  }
                  nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to register linux devfreq",
                            *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                            *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
                }
                else {
LAB_0010d322:
                  down(nv_linux_devices_lock);
                  iVar8 = nv_linux_assign_minor_locked(lVar11);
                  if (iVar8 == 0) {
                    up(nv_linux_devices_lock);
                    if ((*(char *)(lVar11 + 0x5290) != '\0') &&
                       ((*(byte *)(lVar11 + 0x10) & 2) == 0)) {
                      nv_printf(1,"NVRM: Starting device %04x:%02x:%02x.%x\n",
                                **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7)
                      ;
                      uVar17 = nv_start_device(lVar11,puVar16);
                      if ((int)uVar17 != 0) {
                        nv_printf(4,"NVRM: Device start failed for %04x:%02x:%02x.%x (ret=%d)\n",
                                  **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                                  *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                                  *(uint *)(param_1 + 0x38) >> 3 & 0x1f,
                                  *(uint *)(param_1 + 0x38) & 7,uVar17);
                        down(nv_linux_devices_lock);
                        nv_linux_remove_minor_locked(lVar11);
                        up(nv_linux_devices_lock);
                        goto LAB_0010d8bf;
                      }
                    }
                    down(nv_linux_devices_lock);
                    nv_linux_add_device_locked(lVar11);
                    up(nv_linux_devices_lock);
                    nv_procfs_add_gpu(lVar11);
                    rm_notify_gpu_addition(puVar16,lVar11);
                    nvidia_modeset_probe(lVar11);
                    rm_enable_dynamic_power_management(puVar16,lVar11);
                    uVar21 = 0;
                    if ((puVar16 != (undefined4 *)0x0) &&
                       (cVar6 = rm_is_altstack_in_use(), cVar6 != '\0')) {
                      kmem_cache_free(nvidia_stack_t_cache,puVar16);
                    }
                    goto LAB_0010d3c6;
                  }
                  up(nv_linux_devices_lock);
                }
LAB_0010d8bf:
                rm_cleanup_dynamic_power_management(puVar16,lVar11);
                pm_vt_switch_unregister(*(undefined8 *)(lVar11 + 0x3b0));
                nv_linux_stop_open_q(lVar11);
              }
              else {
                nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: nv_linux_init_open_q() failed!\n",
                          *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                          *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
              }
            }
            else {
              nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: GPU is lost, skipping nv_pci_probe\n",
                        *(undefined4 *)(lVar11 + 0x14),*(undefined1 *)(lVar11 + 0x18),
                        *(undefined1 *)(lVar11 + 0x19),*(undefined1 *)(lVar11 + 0x1a));
            }
            nv_clk_clear_handles(lVar11);
            nv_ats_supported = bVar5;
            rm_free_private_state(puVar16,lVar11);
            goto LAB_0010d43a;
          }
          rm_free_private_state(puVar16,lVar11);
        }
      }
LAB_0010d43a:
      nv_lock_destroy_locks(puVar16,local_98);
      lVar13 = 0;
      if (*(long *)(param_1 + 0x3f8) != 0) {
        lVar13 = (*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0);
      }
      __release_region(&iomem_resource,*(long *)(param_1 + 0x3f0),lVar13);
      local_76 = 0;
      pci_read_config_word(param_1,4,&local_76);
      pci_disable_device(param_1);
      pci_read_config_word(param_1,4,(long)&local_76 + 2);
      uVar7 = local_76._2_2_ | 2;
      uVar19 = (ushort)local_76 & 1;
      local_76 = local_76 | 0x20000;
      pci_write_config_word(param_1,4,uVar19 | uVar7);
      *(undefined8 *)(param_1 + 0x148) = 0;
      if (lVar11 != 0) {
        kfree(lVar11);
      }
    }
    if ((puVar16 != (undefined4 *)0x0) && (cVar6 = rm_is_altstack_in_use(), cVar6 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,puVar16);
    }
  }
  else {
    nv_printf(4,"NVRM: Ignoring probe for VF %04x:%02x:%02x.%x ",
              **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
  }
LAB_0010d61e:
  uVar21 = 0xffffffff;
LAB_0010d3c6:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar21;
}


// ===== 0010db30 __pfx_nv_pci_gb10b_register_devfreq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010de3c) */

int __pfx_nv_pci_gb10b_register_devfreq(long param_1)

{
  undefined4 *puVar1;
  long *plVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  uint uVar15;
  undefined8 *puVar16;
  ulong uStack_50;
  uint uStack_40;
  
  lVar5 = *(long *)(param_1 + 0x148);
  lVar11 = *(long *)(param_1 + 0x10);
  do {
    lVar10 = lVar11;
    lVar11 = *(long *)(lVar10 + 0x10);
  } while (lVar11 != 0);
  param_1 = param_1 + 0xd0;
  iVar9 = *(int *)(*(long *)(*(long *)(lVar10 + 0x110) + 0x40) + 0x2b8);
  lVar11 = devm_ioremap(param_1,*(undefined8 *)(lVar5 + 0x90),*(undefined8 *)(lVar5 + 0x98));
  uStack_40 = 0;
  if (lVar11 != 0) {
    uStack_40 = *(uint *)(lVar11 + (ulong)*(uint *)(lVar5 + 0x2b8));
  }
  nv_printf(0,"NVRM: devfreq registration detects gpc_fuse_mask = %u\n",uStack_40);
  if (*(int *)(lVar5 + 0x5248) != 0) {
    iVar8 = 0;
    if (-1 < iVar9) {
      iVar8 = iVar9;
    }
    uStack_50 = 0;
    uVar15 = 0;
    do {
      puVar16 = (undefined8 *)(*(long *)(lVar5 + 0x5240) + (long)(int)uVar15 * 0x18);
      if (uStack_40 != 0) {
        uVar4 = *(uint *)(puVar16 + 2);
        while ((uVar4 & uStack_40) != 0) {
          uVar15 = uVar15 + 1;
          if (*(uint *)(lVar5 + 0x5248) <= uVar15) goto LAB_0010de8b;
          puVar16 = (undefined8 *)(*(long *)(lVar5 + 0x5240) + (long)(int)uVar15 * 0x18);
          uVar4 = *(uint *)(puVar16 + 2);
        }
      }
      if ((puVar16[1] != 0) &&
         ((uStack_50 = devm_of_icc_get(param_1), 0xfffffffffffff000 < uStack_50 || (uStack_50 == 0))
         )) {
        uStack_50 = 0;
      }
      uVar12 = devm_clk_get(param_1,*puVar16);
      if ((uVar12 != 0) && (uVar12 < 0xfffffffffffff001)) {
        puVar13 = (undefined4 *)devm_kmalloc(param_1,0x3c8,0xdc0);
        if (puVar13 == (undefined4 *)0x0) {
          return -0xc;
        }
        plVar2 = (long *)(puVar13 + 200);
        *(long **)(puVar13 + 200) = plVar2;
        *(long **)(puVar13 + 0xca) = plVar2;
        *(undefined4 **)(puVar13 + 0xcc) = puVar13 + 0xcc;
        *(undefined4 **)(puVar13 + 0xce) = puVar13 + 0xcc;
        *(ulong *)(puVar13 + 0xd4) = uVar12;
        puVar1 = puVar13 + 2;
        *(ulong *)(puVar13 + 0xf0) = uStack_50;
        puVar13[1] = iVar8;
        uVar3 = *(undefined4 *)((long)puVar16 + 0x14);
        *(long *)(puVar13 + 0x12) = param_1;
        *puVar13 = uVar3;
        *(code **)(puVar13 + 0xbc) = nv_pci_gb10b_device_release;
        dev_set_name(puVar1,"%s-%d",*puVar16);
        pcVar14 = strstr((char *)*puVar16,"gpc");
        if (pcVar14 == (char *)0x0) {
          pcVar14 = strstr((char *)*puVar16,"nvd");
          if (pcVar14 == (char *)0x0) {
            pcVar14 = strstr((char *)*puVar16,"sys");
            if (pcVar14 == (char *)0x0) {
              pcVar14 = strstr((char *)*puVar16,"uproc");
              if (pcVar14 != (char *)0x0) {
                *(undefined4 **)(lVar5 + 0x5268) = puVar13;
                dev_set_name(puVar1,"gpu-pwr-%d",iVar8);
              }
            }
            else {
              *(undefined4 **)(lVar5 + 0x5260) = puVar13;
              dev_set_name(puVar1,"gpu-sys-%d",iVar8);
            }
          }
          else {
            *(undefined4 **)(lVar5 + 0x5258) = puVar13;
            dev_set_name(puVar1,"gpu-nvd-%d",iVar8);
          }
LAB_0010dd70:
          iVar9 = device_register(puVar1);
        }
        else {
          lVar11 = *(long *)(lVar5 + 0x5250);
          if (lVar11 != 0) {
            plVar6 = *(long **)(lVar11 + 0x328);
            lVar10 = lVar11 + 800;
            if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && (plVar2 != (long *)lVar10)) {
              *(long **)(lVar11 + 0x328) = plVar2;
              *(long *)(puVar13 + 200) = lVar10;
              *(long **)(puVar13 + 0xca) = plVar6;
              *plVar6 = (long)plVar2;
            }
            else {
              __list_add_valid_or_report(plVar2);
            }
            *(undefined8 *)(puVar13 + 0xd0) = *(undefined8 *)(lVar5 + 0x5250);
            goto LAB_0010dd70;
          }
          *(undefined4 **)(lVar5 + 0x5250) = puVar13;
          dev_set_name(puVar1,"gpu-gpc-%d",iVar8);
          iVar9 = device_register(puVar1);
        }
        if (iVar9 != 0) {
          return iVar9;
        }
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < *(uint *)(lVar5 + 0x5248));
  }
LAB_0010de8b:
  if (*(long *)(lVar5 + 0x5250) != 0) {
    iVar9 = nv_pci_gb10b_add_devfreq_device();
    if (iVar9 != 0) {
      *(undefined8 *)(*(long *)(lVar5 + 0x5250) + 0x358) = 0;
      goto LAB_0010e115;
    }
    lVar11 = *(long *)(lVar5 + 0x5260);
    if (lVar11 != 0) {
      lVar7 = *(long *)(lVar5 + 0x5250);
      plVar2 = (long *)(lVar11 + 800);
      plVar6 = *(long **)(lVar7 + 0x328);
      lVar10 = lVar7 + 800;
      if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
        *(long **)(lVar7 + 0x328) = plVar2;
        *(long *)(lVar11 + 800) = lVar10;
        *(long **)(lVar11 + 0x328) = plVar6;
        *plVar6 = (long)plVar2;
      }
      else {
        __list_add_valid_or_report();
      }
      *(undefined8 *)(*(long *)(lVar5 + 0x5260) + 0x340) = *(undefined8 *)(lVar5 + 0x5250);
    }
    lVar11 = *(long *)(lVar5 + 0x5268);
    if (lVar11 != 0) {
      lVar7 = *(long *)(lVar5 + 0x5250);
      plVar2 = (long *)(lVar11 + 800);
      plVar6 = *(long **)(lVar7 + 0x328);
      lVar10 = lVar7 + 800;
      if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
        *(long **)(lVar7 + 0x328) = plVar2;
        *(long *)(lVar11 + 800) = lVar10;
        *(long **)(lVar11 + 0x328) = plVar6;
        *plVar6 = (long)plVar2;
      }
      else {
        __list_add_valid_or_report();
      }
      *(undefined8 *)(*(long *)(lVar5 + 0x5268) + 0x340) = *(undefined8 *)(lVar5 + 0x5250);
    }
  }
  if (*(long *)(lVar5 + 0x5258) == 0) {
    return 0;
  }
  iVar9 = nv_pci_gb10b_add_devfreq_device();
  if (iVar9 == 0) {
    lVar11 = *(long *)(lVar5 + 0x5260);
    if (lVar11 != 0) {
      lVar7 = *(long *)(lVar5 + 0x5258);
      plVar2 = (long *)(lVar11 + 0x330);
      plVar6 = *(long **)(lVar7 + 0x338);
      lVar10 = lVar7 + 0x330;
      if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
        *(long **)(lVar7 + 0x338) = plVar2;
        *(long *)(lVar11 + 0x330) = lVar10;
        *(long **)(lVar11 + 0x338) = plVar6;
        *plVar6 = (long)plVar2;
      }
      else {
        __list_add_valid_or_report();
      }
      *(undefined8 *)(*(long *)(lVar5 + 0x5260) + 0x348) = *(undefined8 *)(lVar5 + 0x5258);
    }
    lVar11 = *(long *)(lVar5 + 0x5268);
    if (lVar11 == 0) {
      return 0;
    }
    lVar7 = *(long *)(lVar5 + 0x5258);
    plVar2 = (long *)(lVar11 + 0x330);
    plVar6 = *(long **)(lVar7 + 0x338);
    lVar10 = lVar7 + 0x330;
    if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
      *(long **)(lVar7 + 0x338) = plVar2;
      *(long *)(lVar11 + 0x330) = lVar10;
      *(long **)(lVar11 + 0x338) = plVar6;
      *plVar6 = (long)plVar2;
    }
    else {
      __list_add_valid_or_report();
    }
    *(undefined8 *)(*(long *)(lVar5 + 0x5268) + 0x348) = *(undefined8 *)(lVar5 + 0x5258);
    return 0;
  }
  *(undefined8 *)(*(long *)(lVar5 + 0x5258) + 0x358) = 0;
LAB_0010e115:
  lVar11 = *(long *)(lVar5 + 0x5260);
  if (lVar11 != 0) {
    if (*(long *)(lVar11 + 0x340) != 0) {
      plVar2 = *(long **)(lVar11 + 0x328);
      lVar10 = *(long *)(lVar11 + 800);
      if ((lVar11 + 800 == *plVar2) && (lVar11 + 800 == *(long *)(lVar10 + 8))) {
        *(long **)(lVar10 + 8) = plVar2;
        *plVar2 = lVar10;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      *(undefined8 *)(lVar11 + 800) = 0xdead000000000100;
      *(undefined8 *)(lVar11 + 0x328) = 0xdead000000000122;
      *(undefined8 *)(*(long *)(lVar5 + 0x5260) + 0x340) = 0;
      lVar11 = *(long *)(lVar5 + 0x5260);
    }
    device_unregister(lVar11 + 8);
    *(undefined8 *)(lVar5 + 0x5260) = 0;
  }
  lVar11 = *(long *)(lVar5 + 0x5268);
  if (lVar11 != 0) {
    if (*(long *)(lVar11 + 0x340) != 0) {
      plVar2 = *(long **)(lVar11 + 0x328);
      lVar10 = *(long *)(lVar11 + 800);
      if ((lVar11 + 800 == *plVar2) && (lVar11 + 800 == *(long *)(lVar10 + 8))) {
        *(long **)(lVar10 + 8) = plVar2;
        *plVar2 = lVar10;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      *(undefined8 *)(lVar11 + 800) = 0xdead000000000100;
      *(undefined8 *)(lVar11 + 0x328) = 0xdead000000000122;
      *(undefined8 *)(*(long *)(lVar5 + 0x5268) + 0x340) = 0;
      lVar11 = *(long *)(lVar5 + 0x5268);
    }
    device_unregister(lVar11 + 8);
    *(undefined8 *)(lVar5 + 0x5268) = 0;
  }
  return iVar9;
}


// ===== 0010db40 nv_pci_gb10b_register_devfreq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010de3c) */

int nv_pci_gb10b_register_devfreq(long param_1)

{
  undefined4 *puVar1;
  long *plVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  uint uVar15;
  undefined8 *puVar16;
  ulong local_50;
  uint local_40;
  
  lVar5 = *(long *)(param_1 + 0x148);
  lVar11 = *(long *)(param_1 + 0x10);
  do {
    lVar10 = lVar11;
    lVar11 = *(long *)(lVar10 + 0x10);
  } while (lVar11 != 0);
  param_1 = param_1 + 0xd0;
  iVar9 = *(int *)(*(long *)(*(long *)(lVar10 + 0x110) + 0x40) + 0x2b8);
  lVar11 = devm_ioremap(param_1,*(undefined8 *)(lVar5 + 0x90),*(undefined8 *)(lVar5 + 0x98));
  local_40 = 0;
  if (lVar11 != 0) {
    local_40 = *(uint *)(lVar11 + (ulong)*(uint *)(lVar5 + 0x2b8));
  }
  nv_printf(0,"NVRM: devfreq registration detects gpc_fuse_mask = %u\n",local_40);
  if (*(int *)(lVar5 + 0x5248) != 0) {
    iVar8 = 0;
    if (-1 < iVar9) {
      iVar8 = iVar9;
    }
    local_50 = 0;
    uVar15 = 0;
    do {
      puVar16 = (undefined8 *)(*(long *)(lVar5 + 0x5240) + (long)(int)uVar15 * 0x18);
      if (local_40 != 0) {
        uVar4 = *(uint *)(puVar16 + 2);
        while ((uVar4 & local_40) != 0) {
          uVar15 = uVar15 + 1;
          if (*(uint *)(lVar5 + 0x5248) <= uVar15) goto LAB_0010de8b;
          puVar16 = (undefined8 *)(*(long *)(lVar5 + 0x5240) + (long)(int)uVar15 * 0x18);
          uVar4 = *(uint *)(puVar16 + 2);
        }
      }
      if ((puVar16[1] != 0) &&
         ((local_50 = devm_of_icc_get(param_1), 0xfffffffffffff000 < local_50 || (local_50 == 0))))
      {
        local_50 = 0;
      }
      uVar12 = devm_clk_get(param_1,*puVar16);
      if ((uVar12 != 0) && (uVar12 < 0xfffffffffffff001)) {
        puVar13 = (undefined4 *)devm_kmalloc(param_1,0x3c8,0xdc0);
        if (puVar13 == (undefined4 *)0x0) {
          return -0xc;
        }
        plVar2 = (long *)(puVar13 + 200);
        *(long **)(puVar13 + 200) = plVar2;
        *(long **)(puVar13 + 0xca) = plVar2;
        *(undefined4 **)(puVar13 + 0xcc) = puVar13 + 0xcc;
        *(undefined4 **)(puVar13 + 0xce) = puVar13 + 0xcc;
        *(ulong *)(puVar13 + 0xd4) = uVar12;
        puVar1 = puVar13 + 2;
        *(ulong *)(puVar13 + 0xf0) = local_50;
        puVar13[1] = iVar8;
        uVar3 = *(undefined4 *)((long)puVar16 + 0x14);
        *(long *)(puVar13 + 0x12) = param_1;
        *puVar13 = uVar3;
        *(code **)(puVar13 + 0xbc) = nv_pci_gb10b_device_release;
        dev_set_name(puVar1,"%s-%d",*puVar16);
        pcVar14 = strstr((char *)*puVar16,"gpc");
        if (pcVar14 == (char *)0x0) {
          pcVar14 = strstr((char *)*puVar16,"nvd");
          if (pcVar14 == (char *)0x0) {
            pcVar14 = strstr((char *)*puVar16,"sys");
            if (pcVar14 == (char *)0x0) {
              pcVar14 = strstr((char *)*puVar16,"uproc");
              if (pcVar14 != (char *)0x0) {
                *(undefined4 **)(lVar5 + 0x5268) = puVar13;
                dev_set_name(puVar1,"gpu-pwr-%d",iVar8);
              }
            }
            else {
              *(undefined4 **)(lVar5 + 0x5260) = puVar13;
              dev_set_name(puVar1,"gpu-sys-%d",iVar8);
            }
          }
          else {
            *(undefined4 **)(lVar5 + 0x5258) = puVar13;
            dev_set_name(puVar1,"gpu-nvd-%d",iVar8);
          }
LAB_0010dd70:
          iVar9 = device_register(puVar1);
        }
        else {
          lVar11 = *(long *)(lVar5 + 0x5250);
          if (lVar11 != 0) {
            plVar6 = *(long **)(lVar11 + 0x328);
            lVar10 = lVar11 + 800;
            if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && (plVar2 != (long *)lVar10)) {
              *(long **)(lVar11 + 0x328) = plVar2;
              *(long *)(puVar13 + 200) = lVar10;
              *(long **)(puVar13 + 0xca) = plVar6;
              *plVar6 = (long)plVar2;
            }
            else {
              __list_add_valid_or_report(plVar2);
            }
            *(undefined8 *)(puVar13 + 0xd0) = *(undefined8 *)(lVar5 + 0x5250);
            goto LAB_0010dd70;
          }
          *(undefined4 **)(lVar5 + 0x5250) = puVar13;
          dev_set_name(puVar1,"gpu-gpc-%d",iVar8);
          iVar9 = device_register(puVar1);
        }
        if (iVar9 != 0) {
          return iVar9;
        }
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < *(uint *)(lVar5 + 0x5248));
  }
LAB_0010de8b:
  if (*(long *)(lVar5 + 0x5250) != 0) {
    iVar9 = nv_pci_gb10b_add_devfreq_device();
    if (iVar9 != 0) {
      *(undefined8 *)(*(long *)(lVar5 + 0x5250) + 0x358) = 0;
      goto LAB_0010e115;
    }
    lVar11 = *(long *)(lVar5 + 0x5260);
    if (lVar11 != 0) {
      lVar7 = *(long *)(lVar5 + 0x5250);
      plVar2 = (long *)(lVar11 + 800);
      plVar6 = *(long **)(lVar7 + 0x328);
      lVar10 = lVar7 + 800;
      if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
        *(long **)(lVar7 + 0x328) = plVar2;
        *(long *)(lVar11 + 800) = lVar10;
        *(long **)(lVar11 + 0x328) = plVar6;
        *plVar6 = (long)plVar2;
      }
      else {
        __list_add_valid_or_report();
      }
      *(undefined8 *)(*(long *)(lVar5 + 0x5260) + 0x340) = *(undefined8 *)(lVar5 + 0x5250);
    }
    lVar11 = *(long *)(lVar5 + 0x5268);
    if (lVar11 != 0) {
      lVar7 = *(long *)(lVar5 + 0x5250);
      plVar2 = (long *)(lVar11 + 800);
      plVar6 = *(long **)(lVar7 + 0x328);
      lVar10 = lVar7 + 800;
      if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
        *(long **)(lVar7 + 0x328) = plVar2;
        *(long *)(lVar11 + 800) = lVar10;
        *(long **)(lVar11 + 0x328) = plVar6;
        *plVar6 = (long)plVar2;
      }
      else {
        __list_add_valid_or_report();
      }
      *(undefined8 *)(*(long *)(lVar5 + 0x5268) + 0x340) = *(undefined8 *)(lVar5 + 0x5250);
    }
  }
  if (*(long *)(lVar5 + 0x5258) == 0) {
    return 0;
  }
  iVar9 = nv_pci_gb10b_add_devfreq_device();
  if (iVar9 == 0) {
    lVar11 = *(long *)(lVar5 + 0x5260);
    if (lVar11 != 0) {
      lVar7 = *(long *)(lVar5 + 0x5258);
      plVar2 = (long *)(lVar11 + 0x330);
      plVar6 = *(long **)(lVar7 + 0x338);
      lVar10 = lVar7 + 0x330;
      if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
        *(long **)(lVar7 + 0x338) = plVar2;
        *(long *)(lVar11 + 0x330) = lVar10;
        *(long **)(lVar11 + 0x338) = plVar6;
        *plVar6 = (long)plVar2;
      }
      else {
        __list_add_valid_or_report();
      }
      *(undefined8 *)(*(long *)(lVar5 + 0x5260) + 0x348) = *(undefined8 *)(lVar5 + 0x5258);
    }
    lVar11 = *(long *)(lVar5 + 0x5268);
    if (lVar11 == 0) {
      return 0;
    }
    lVar7 = *(long *)(lVar5 + 0x5258);
    plVar2 = (long *)(lVar11 + 0x330);
    plVar6 = *(long **)(lVar7 + 0x338);
    lVar10 = lVar7 + 0x330;
    if (((lVar10 == *plVar6) && (plVar2 != plVar6)) && ((long *)lVar10 != plVar2)) {
      *(long **)(lVar7 + 0x338) = plVar2;
      *(long *)(lVar11 + 0x330) = lVar10;
      *(long **)(lVar11 + 0x338) = plVar6;
      *plVar6 = (long)plVar2;
    }
    else {
      __list_add_valid_or_report();
    }
    *(undefined8 *)(*(long *)(lVar5 + 0x5268) + 0x348) = *(undefined8 *)(lVar5 + 0x5258);
    return 0;
  }
  *(undefined8 *)(*(long *)(lVar5 + 0x5258) + 0x358) = 0;
LAB_0010e115:
  lVar11 = *(long *)(lVar5 + 0x5260);
  if (lVar11 != 0) {
    if (*(long *)(lVar11 + 0x340) != 0) {
      plVar2 = *(long **)(lVar11 + 0x328);
      lVar10 = *(long *)(lVar11 + 800);
      if ((lVar11 + 800 == *plVar2) && (lVar11 + 800 == *(long *)(lVar10 + 8))) {
        *(long **)(lVar10 + 8) = plVar2;
        *plVar2 = lVar10;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      *(undefined8 *)(lVar11 + 800) = 0xdead000000000100;
      *(undefined8 *)(lVar11 + 0x328) = 0xdead000000000122;
      *(undefined8 *)(*(long *)(lVar5 + 0x5260) + 0x340) = 0;
      lVar11 = *(long *)(lVar5 + 0x5260);
    }
    device_unregister(lVar11 + 8);
    *(undefined8 *)(lVar5 + 0x5260) = 0;
  }
  lVar11 = *(long *)(lVar5 + 0x5268);
  if (lVar11 != 0) {
    if (*(long *)(lVar11 + 0x340) != 0) {
      plVar2 = *(long **)(lVar11 + 0x328);
      lVar10 = *(long *)(lVar11 + 800);
      if ((lVar11 + 800 == *plVar2) && (lVar11 + 800 == *(long *)(lVar10 + 8))) {
        *(long **)(lVar10 + 8) = plVar2;
        *plVar2 = lVar10;
      }
      else {
        __list_del_entry_valid_or_report();
      }
      *(undefined8 *)(lVar11 + 800) = 0xdead000000000100;
      *(undefined8 *)(lVar11 + 0x328) = 0xdead000000000122;
      *(undefined8 *)(*(long *)(lVar5 + 0x5268) + 0x340) = 0;
      lVar11 = *(long *)(lVar5 + 0x5268);
    }
    device_unregister(lVar11 + 8);
    *(undefined8 *)(lVar5 + 0x5268) = 0;
  }
  return iVar9;
}


// ===== 0010e270 __pfx_nv_pci_remove_helper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010e2e4) */

void __pfx_nv_pci_remove_helper(long param_1,char param_2)

{
  code *pcVar1;
  char cVar2;
  ushort uVar3;
  undefined4 *puVar4;
  ushort uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long in_GS_OFFSET;
  undefined4 uStack_34;
  long lStack_30;
  
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((((*(byte *)(param_1 + 0x873) & 1) == 0) && (lVar7 = *(long *)(param_1 + 0x148), lVar7 != 0))
     && (*(long *)(lVar7 + 0x3b8) == param_1)) {
    lVar8 = lVar7 + 0x730;
    nv_linux_stop_open_q(lVar7);
    nvidia_modeset_remove(*(undefined4 *)(lVar7 + 0x24));
    down(nv_linux_devices_lock);
    down(lVar7 + 0x730);
    if ((param_2 == '\0') && (*(long *)(lVar7 + 0x3a0) != 0)) {
      up(lVar8);
      if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        up(nv_linux_devices_lock);
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    puVar4 = (undefined4 *)0x0;
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar4 == (undefined4 *)0x0) {
        up(lVar8);
        if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
          up(nv_linux_devices_lock);
          return;
        }
        goto LAB_0010e7fb;
      }
      *puVar4 = 0x2ff0;
      *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    }
    nv_linux_remove_device_locked(lVar7);
    rm_notify_gpu_removal(puVar4,lVar7);
    if ((*(long *)(lVar7 + 0x3a0) != 0) && (*(char *)(lVar7 + 0x2fe) == '\0')) {
      nv_printf(4,"NVRM: Attempting to remove device %04x:%02x:%02x.%x with non-zero usage count!\n"
                ,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      lVar6 = *(long *)(lVar7 + 0x3a0);
      while (lVar6 != 0) {
        up(lVar8);
        up(nv_linux_devices_lock);
        os_delay(500);
        down(nv_linux_devices_lock);
        lVar7 = *(long *)(param_1 + 0x148);
        if (lVar7 == 0) {
          nv_printf(4,"NVRM: Failed removal of device %04x:%02x:%02x.%x!\n",
                    **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                    *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                    *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar8 = lVar7 + 0x730;
        down(lVar7 + 0x730);
        lVar6 = *(long *)(lVar7 + 0x3a0);
      }
      nv_printf(4,"NVRM: Continuing with GPU removal for device %04x:%02x:%02x.%x\n",
                **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
    }
    rm_check_for_gpu_surprise_removal(puVar4,lVar7);
    nv_procfs_remove_gpu(lVar7);
    lVar6 = *(long *)(param_1 + 0x148);
    if (*(long *)(lVar6 + 0x5250) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar6 + 0x5250) = 0;
    }
    if (*(long *)(lVar6 + 0x5258) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar6 + 0x5258) = 0;
    }
    nv_clk_clear_handles(lVar7);
    rm_cleanup_dynamic_power_management(puVar4,lVar7);
    if ((*(char *)(lVar7 + 0x5290) != '\0') && ((*(byte *)(lVar7 + 0x10) & 2) == 0)) {
      nv_printf(1,"NVRM: Stopping device %04x:%02x:%02x.%x\n",
                **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      nv_stop_device(lVar7,puVar4);
    }
    nv_linux_remove_minor_locked(lVar7);
    *(undefined1 *)(lVar7 + 0x2fc) = 1;
    up(nv_linux_devices_lock);
    pm_vt_switch_unregister(param_1 + 0xd0);
    if ((*(ushort *)(lVar7 + 0x10) & 0x801) != 0) {
      nv_acpi_unregister_notifier(lVar7);
      if ((*(byte *)(lVar7 + 0x11) & 8) != 0) {
        rm_disable_gpu_state_persistence(puVar4,lVar7);
      }
      nv_shutdown_adapter(puVar4,lVar7,lVar7);
      nv_dev_free_stacks(lVar7);
    }
    if (*(long *)(lVar7 + 0x818) != 0) {
      filp_close(*(long *)(lVar7 + 0x818),0);
      *(undefined8 *)(lVar7 + 0x818) = 0;
    }
    if (*(long *)(lVar7 + 0x3a0) == 0) {
      nv_lock_destroy_locks(puVar4,lVar7);
    }
    *(undefined8 *)(param_1 + 0x148) = 0;
    num_probed_nv_devices = num_probed_nv_devices + -1;
    rm_i2c_remove_adapters(puVar4,lVar7);
    rm_free_private_state(puVar4,lVar7);
    lVar6 = 0;
    if (*(long *)(param_1 + 0x3f8) != 0) {
      lVar6 = (*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0);
    }
    __release_region(&iomem_resource,*(long *)(param_1 + 0x3f0),lVar6);
    num_nv_devices = num_nv_devices + -1;
    if (*(long *)(lVar7 + 0x3a0) == 0) {
      uStack_34 = 0;
      pci_read_config_word(param_1,4,&uStack_34);
      pci_disable_device(param_1);
      pci_read_config_word(param_1,4,(long)&uStack_34 + 2);
      uVar3 = uStack_34._2_2_ | 2;
      uVar5 = (ushort)uStack_34 & 1;
      uStack_34 = uStack_34 | 0x20000;
      pci_write_config_word(param_1,4,uVar5 | uVar3);
      kfree(lVar7);
    }
    else {
      up(lVar8);
    }
    if ((puVar4 != (undefined4 *)0x0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        kmem_cache_free(nvidia_stack_t_cache,puVar4);
        return;
      }
      goto LAB_0010e7fb;
    }
  }
  if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
LAB_0010e7fb:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010e280 nv_pci_remove_helper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010e2e4) */

void nv_pci_remove_helper(long param_1,char param_2)

{
  code *pcVar1;
  char cVar2;
  ushort uVar3;
  undefined4 *puVar4;
  ushort uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long in_GS_OFFSET;
  undefined4 local_34;
  long local_30;
  
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((((*(byte *)(param_1 + 0x873) & 1) == 0) && (lVar7 = *(long *)(param_1 + 0x148), lVar7 != 0))
     && (*(long *)(lVar7 + 0x3b8) == param_1)) {
    lVar8 = lVar7 + 0x730;
    nv_linux_stop_open_q(lVar7);
    nvidia_modeset_remove(*(undefined4 *)(lVar7 + 0x24));
    down(nv_linux_devices_lock);
    down(lVar7 + 0x730);
    if ((param_2 == '\0') && (*(long *)(lVar7 + 0x3a0) != 0)) {
      up(lVar8);
      if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        up(nv_linux_devices_lock);
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    puVar4 = (undefined4 *)0x0;
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar4 == (undefined4 *)0x0) {
        up(lVar8);
        if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
          up(nv_linux_devices_lock);
          return;
        }
        goto LAB_0010e7fb;
      }
      *puVar4 = 0x2ff0;
      *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    }
    nv_linux_remove_device_locked(lVar7);
    rm_notify_gpu_removal(puVar4,lVar7);
    if ((*(long *)(lVar7 + 0x3a0) != 0) && (*(char *)(lVar7 + 0x2fe) == '\0')) {
      nv_printf(4,"NVRM: Attempting to remove device %04x:%02x:%02x.%x with non-zero usage count!\n"
                ,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      lVar6 = *(long *)(lVar7 + 0x3a0);
      while (lVar6 != 0) {
        up(lVar8);
        up(nv_linux_devices_lock);
        os_delay(500);
        down(nv_linux_devices_lock);
        lVar7 = *(long *)(param_1 + 0x148);
        if (lVar7 == 0) {
          nv_printf(4,"NVRM: Failed removal of device %04x:%02x:%02x.%x!\n",
                    **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                    *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                    *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        lVar8 = lVar7 + 0x730;
        down(lVar7 + 0x730);
        lVar6 = *(long *)(lVar7 + 0x3a0);
      }
      nv_printf(4,"NVRM: Continuing with GPU removal for device %04x:%02x:%02x.%x\n",
                **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
    }
    rm_check_for_gpu_surprise_removal(puVar4,lVar7);
    nv_procfs_remove_gpu(lVar7);
    lVar6 = *(long *)(param_1 + 0x148);
    if (*(long *)(lVar6 + 0x5250) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar6 + 0x5250) = 0;
    }
    if (*(long *)(lVar6 + 0x5258) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar6 + 0x5258) = 0;
    }
    nv_clk_clear_handles(lVar7);
    rm_cleanup_dynamic_power_management(puVar4,lVar7);
    if ((*(char *)(lVar7 + 0x5290) != '\0') && ((*(byte *)(lVar7 + 0x10) & 2) == 0)) {
      nv_printf(1,"NVRM: Stopping device %04x:%02x:%02x.%x\n",
                **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
                *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),
                *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      nv_stop_device(lVar7,puVar4);
    }
    nv_linux_remove_minor_locked(lVar7);
    *(undefined1 *)(lVar7 + 0x2fc) = 1;
    up(nv_linux_devices_lock);
    pm_vt_switch_unregister(param_1 + 0xd0);
    if ((*(ushort *)(lVar7 + 0x10) & 0x801) != 0) {
      nv_acpi_unregister_notifier(lVar7);
      if ((*(byte *)(lVar7 + 0x11) & 8) != 0) {
        rm_disable_gpu_state_persistence(puVar4,lVar7);
      }
      nv_shutdown_adapter(puVar4,lVar7,lVar7);
      nv_dev_free_stacks(lVar7);
    }
    if (*(long *)(lVar7 + 0x818) != 0) {
      filp_close(*(long *)(lVar7 + 0x818),0);
      *(undefined8 *)(lVar7 + 0x818) = 0;
    }
    if (*(long *)(lVar7 + 0x3a0) == 0) {
      nv_lock_destroy_locks(puVar4,lVar7);
    }
    *(undefined8 *)(param_1 + 0x148) = 0;
    num_probed_nv_devices = num_probed_nv_devices + -1;
    rm_i2c_remove_adapters(puVar4,lVar7);
    rm_free_private_state(puVar4,lVar7);
    lVar6 = 0;
    if (*(long *)(param_1 + 0x3f8) != 0) {
      lVar6 = (*(long *)(param_1 + 0x3f8) + 1) - *(long *)(param_1 + 0x3f0);
    }
    __release_region(&iomem_resource,*(long *)(param_1 + 0x3f0),lVar6);
    num_nv_devices = num_nv_devices + -1;
    if (*(long *)(lVar7 + 0x3a0) == 0) {
      local_34 = 0;
      pci_read_config_word(param_1,4,&local_34);
      pci_disable_device(param_1);
      pci_read_config_word(param_1,4,(long)&local_34 + 2);
      uVar3 = local_34._2_2_ | 2;
      uVar5 = (ushort)local_34 & 1;
      local_34 = local_34 | 0x20000;
      pci_write_config_word(param_1,4,uVar5 | uVar3);
      kfree(lVar7);
    }
    else {
      up(lVar8);
    }
    if ((puVar4 != (undefined4 *)0x0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
        kmem_cache_free(nvidia_stack_t_cache,puVar4);
        return;
      }
      goto LAB_0010e7fb;
    }
  }
  if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
LAB_0010e7fb:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0010e810 __pfx_nv_pci_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_pci_remove(long param_1)

{
  nv_printf(1,"NVRM: removing GPU %04x:%02x:%02x.%x\n",
            **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
            *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),*(uint *)(param_1 + 0x38) >> 3 & 0x1f,
            *(uint *)(param_1 + 0x38) & 7);
  nv_pci_remove_helper(param_1,1);
  return;
}


// ===== 0010e820 nv_pci_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_pci_remove(long param_1)

{
  nv_printf(1,"NVRM: removing GPU %04x:%02x:%02x.%x\n",
            **(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
            *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),*(uint *)(param_1 + 0x38) >> 3 & 0x1f,
            *(uint *)(param_1 + 0x38) & 7);
  nv_pci_remove_helper(param_1,1);
  return;
}


// ===== 0010e880 __pfx_nv_pci_shutdown =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010e8ae) */
/* WARNING: Removing unreachable block (ram,0x0010e8c3) */

void __pfx_nv_pci_shutdown(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x148);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x3b8) == param_1)) {
    if (*(char *)(lVar1 + 0x51a2) != '\0') {
      *(undefined1 *)(lVar1 + 0x51a2) = 0;
      return;
    }
    if (*(long *)(lVar1 + 0x5250) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar1 + 0x5250) = 0;
    }
    if (*(long *)(lVar1 + 0x5258) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar1 + 0x5258) = 0;
    }
    nv_pci_remove_helper(param_1,0);
    if (*(long *)(param_1 + 0x148) != 0) {
      *(undefined1 *)(lVar1 + 0x325) = 1;
    }
    pci_clear_master(param_1);
    __const_udelay(0x10c7);
    return;
  }
  return;
}


// ===== 0010e890 nv_pci_shutdown =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010e8ae) */
/* WARNING: Removing unreachable block (ram,0x0010e8c3) */

void nv_pci_shutdown(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x148);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x3b8) == param_1)) {
    if (*(char *)(lVar1 + 0x51a2) != '\0') {
      *(undefined1 *)(lVar1 + 0x51a2) = 0;
      return;
    }
    if (*(long *)(lVar1 + 0x5250) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar1 + 0x5250) = 0;
    }
    if (*(long *)(lVar1 + 0x5258) != 0) {
      nv_pci_tegra_devfreq_remove();
      *(undefined8 *)(lVar1 + 0x5258) = 0;
    }
    nv_pci_remove_helper(param_1,0);
    if (*(long *)(param_1 + 0x148) != 0) {
      *(undefined1 *)(lVar1 + 0x325) = 1;
    }
    pci_clear_master(param_1);
    __const_udelay(0x10c7);
    return;
  }
  return;
}


// ===== 0010e960 __pfx_nv_pci_tegra_boost_clocks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ea42) */

void __pfx_nv_pci_tegra_boost_clocks(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  
  lVar2 = *(long *)(param_1 + 0x78);
  if (*(int *)(lVar2 + 0x5248) != 0) {
    uVar6 = 0;
    do {
      while( true ) {
        puVar1 = (undefined8 *)(*(long *)(lVar2 + 0x5240) + (long)(int)uVar6 * 0x18);
        pcVar5 = strstr((char *)*puVar1,"uproc");
        if ((pcVar5 == (char *)0x0) &&
           (pcVar5 = strstr((char *)*puVar1,"sys"), pcVar5 == (char *)0x0)) break;
        uVar6 = uVar6 + 1;
        uVar3 = devm_clk_get(param_1,*puVar1);
        uVar4 = clk_round_rate(uVar3,0xffffffffffffffff);
        clk_set_rate(uVar3,uVar4);
        if (*(uint *)(lVar2 + 0x5248) <= uVar6) {
          return;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(lVar2 + 0x5248));
  }
  return;
}


// ===== 0010e970 nv_pci_tegra_boost_clocks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ea42) */

void nv_pci_tegra_boost_clocks(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  
  lVar2 = *(long *)(param_1 + 0x78);
  if (*(int *)(lVar2 + 0x5248) != 0) {
    uVar6 = 0;
    do {
      while( true ) {
        puVar1 = (undefined8 *)(*(long *)(lVar2 + 0x5240) + (long)(int)uVar6 * 0x18);
        pcVar5 = strstr((char *)*puVar1,"uproc");
        if ((pcVar5 == (char *)0x0) &&
           (pcVar5 = strstr((char *)*puVar1,"sys"), pcVar5 == (char *)0x0)) break;
        uVar6 = uVar6 + 1;
        uVar3 = devm_clk_get(param_1,*puVar1);
        uVar4 = clk_round_rate(uVar3,0xffffffffffffffff);
        clk_set_rate(uVar3,uVar4);
        if (*(uint *)(lVar2 + 0x5248) <= uVar6) {
          return;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(lVar2 + 0x5248));
  }
  return;
}


// ===== 0010ea50 __pfx_find_pci =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eada) */

long __pfx_find_pci(int param_1,char param_2,char param_3,char param_4)

{
  long lVar1;
  
  down(nv_linux_devices_lock);
  for (lVar1 = nv_linux_devices;
      (lVar1 != 0 &&
      ((((*(int *)(lVar1 + 0x14) != param_1 || (*(char *)(lVar1 + 0x18) != param_2)) ||
        (*(char *)(lVar1 + 0x19) != param_3)) || (*(char *)(lVar1 + 0x1a) != param_4))));
      lVar1 = *(long *)(lVar1 + 0x758)) {
  }
  up(nv_linux_devices_lock);
  return lVar1;
}


// ===== 0010ea60 find_pci =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eada) */

long find_pci(int param_1,char param_2,char param_3,char param_4)

{
  long lVar1;
  
  down(nv_linux_devices_lock);
  for (lVar1 = nv_linux_devices;
      (lVar1 != 0 &&
      ((((*(int *)(lVar1 + 0x14) != param_1 || (*(char *)(lVar1 + 0x18) != param_2)) ||
        (*(char *)(lVar1 + 0x19) != param_3)) || (*(char *)(lVar1 + 0x1a) != param_4))));
      lVar1 = *(long *)(lVar1 + 0x758)) {
  }
  up(nv_linux_devices_lock);
  return lVar1;
}


// ===== 0010eae0 __pfx_nvidia_dev_get_pci_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eb42) */

undefined8
__pfx_nvidia_dev_get_pci_info
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = find_uuid();
  if (lVar1 == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    *param_2 = *(undefined8 *)(lVar1 + 0x3b8);
    *param_3 = *(undefined8 *)(lVar1 + 0x51a8);
    *param_4 = *(undefined8 *)(lVar1 + 0x51b0);
    up(lVar1 + 0x730);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0010eaf0 nvidia_dev_get_pci_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010eb42) */

undefined8
nvidia_dev_get_pci_info
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = find_uuid();
  if (lVar1 == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    *param_2 = *(undefined8 *)(lVar1 + 0x3b8);
    *param_3 = *(undefined8 *)(lVar1 + 0x51a8);
    *param_4 = *(undefined8 *)(lVar1 + 0x51b0);
    up(lVar1 + 0x730);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0010eb50 __pfx_nv_find_pci_capability =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ebc8) */

byte __pfx_nv_find_pci_capability(long param_1,char param_2)

{
  byte bVar1;
  long in_GS_OFFSET;
  byte bStack_24;
  char cStack_23;
  ushort uStack_22;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  bStack_24 = 0;
  uStack_22 = 0;
  cStack_23 = -1;
  pci_read_config_word(param_1,6,&uStack_22);
  uStack_22 = uStack_22 & 0x10;
  if ((uStack_22 != 0) && (*(byte *)(param_1 + 0x49) < 2)) {
    pci_read_config_byte(param_1,0x34,&bStack_24);
    do {
      bStack_24 = bStack_24 & 0xfc;
      pci_read_config_byte(param_1,bStack_24,&cStack_23);
      bVar1 = bStack_24;
      if ((cStack_23 == param_2) ||
         (pci_read_config_byte(param_1,bStack_24 + 1,&bStack_24), bVar1 = 0, bStack_24 == 0))
      goto LAB_0010ebb3;
    } while (cStack_23 != -1);
  }
  bVar1 = 0;
LAB_0010ebb3:
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar1;
}


// ===== 0010eb60 nv_find_pci_capability =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ebc8) */

byte nv_find_pci_capability(long param_1,char param_2)

{
  byte bVar1;
  long in_GS_OFFSET;
  byte local_24;
  char local_23;
  ushort local_22;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_24 = 0;
  local_22 = 0;
  local_23 = -1;
  pci_read_config_word(param_1,6,&local_22);
  local_22 = local_22 & 0x10;
  if ((local_22 != 0) && (*(byte *)(param_1 + 0x49) < 2)) {
    pci_read_config_byte(param_1,0x34,&local_24);
    do {
      local_24 = local_24 & 0xfc;
      pci_read_config_byte(param_1,local_24,&local_23);
      bVar1 = local_24;
      if ((local_23 == param_2) ||
         (pci_read_config_byte(param_1,local_24 + 1,&local_24), bVar1 = 0, local_24 == 0))
      goto LAB_0010ebb3;
    } while (local_23 != -1);
  }
  bVar1 = 0;
LAB_0010ebb3:
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar1;
}


// ===== 0010ec30 __pfx_nv_pci_count_devices =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ec69) */
/* WARNING: Removing unreachable block (ram,0x0010ed1c) */

int __pfx_nv_pci_count_devices(void)

{
  char cVar1;
  long lVar2;
  undefined8 extraout_RDX;
  int iVar3;
  undefined1 auVar4 [16];
  undefined8 uStack_20;
  
  iVar3 = 0;
  if (NVreg_RegisterPCIDriver != 0) {
    lVar2 = 0;
    while( true ) {
      auVar4 = pci_get_class(0x30000,lVar2);
      uStack_20 = auVar4._8_8_;
      lVar2 = auVar4._0_8_;
      if (lVar2 == 0) break;
      cVar1 = rm_is_supported_pci_device
                        (3,0,*(undefined2 *)(lVar2 + 0x3c),*(undefined2 *)(lVar2 + 0x3e),
                         *(undefined2 *)(lVar2 + 0x40),*(undefined2 *)(lVar2 + 0x42));
      if (cVar1 != '\0') {
        iVar3 = iVar3 + 1;
        check_for_bound_driver(lVar2);
      }
    }
    lVar2 = 0;
    while (lVar2 = pci_get_class(0x30200,lVar2,uStack_20), lVar2 != 0) {
      uStack_20 = 1;
      cVar1 = rm_is_supported_pci_device
                        (*(uint *)(lVar2 + 0x44) >> 0x10 & 0xff,*(uint *)(lVar2 + 0x44) >> 8 & 0xff,
                         *(undefined2 *)(lVar2 + 0x3c),*(undefined2 *)(lVar2 + 0x3e),
                         *(undefined2 *)(lVar2 + 0x40),*(undefined2 *)(lVar2 + 0x42));
      if (cVar1 != '\0') {
        iVar3 = iVar3 + 1;
        check_for_bound_driver(lVar2);
        uStack_20 = extraout_RDX;
      }
    }
    return iVar3;
  }
  return 0;
}


// ===== 0010ec40 nv_pci_count_devices =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ec69) */
/* WARNING: Removing unreachable block (ram,0x0010ed1c) */

int nv_pci_count_devices(void)

{
  char cVar1;
  long lVar2;
  undefined8 extraout_RDX;
  int iVar3;
  undefined1 auVar4 [16];
  undefined8 uStack_20;
  
  iVar3 = 0;
  if (NVreg_RegisterPCIDriver != 0) {
    lVar2 = 0;
    while( true ) {
      auVar4 = pci_get_class(0x30000,lVar2);
      uStack_20 = auVar4._8_8_;
      lVar2 = auVar4._0_8_;
      if (lVar2 == 0) break;
      cVar1 = rm_is_supported_pci_device
                        (3,0,*(undefined2 *)(lVar2 + 0x3c),*(undefined2 *)(lVar2 + 0x3e),
                         *(undefined2 *)(lVar2 + 0x40),*(undefined2 *)(lVar2 + 0x42));
      if (cVar1 != '\0') {
        iVar3 = iVar3 + 1;
        check_for_bound_driver(lVar2);
      }
    }
    lVar2 = 0;
    while (lVar2 = pci_get_class(0x30200,lVar2,uStack_20), lVar2 != 0) {
      uStack_20 = 1;
      cVar1 = rm_is_supported_pci_device
                        (*(uint *)(lVar2 + 0x44) >> 0x10 & 0xff,*(uint *)(lVar2 + 0x44) >> 8 & 0xff,
                         *(undefined2 *)(lVar2 + 0x3c),*(undefined2 *)(lVar2 + 0x3e),
                         *(undefined2 *)(lVar2 + 0x40),*(undefined2 *)(lVar2 + 0x42));
      if (cVar1 != '\0') {
        iVar3 = iVar3 + 1;
        check_for_bound_driver(lVar2);
        uStack_20 = extraout_RDX;
      }
    }
    return iVar3;
  }
  return 0;
}


// ===== 0010ed30 __pfx_nv_pci_is_valid_topology_for_direct_pci =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ed70) */

ulong __pfx_nv_pci_is_valid_topology_for_direct_pci(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (ulong)*(byte *)(param_1 + 0x326);
  if (*(byte *)(param_1 + 0x326) != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x2e0) + 0x10);
    uVar2 = CONCAT71((int7)((ulong)lVar1 >> 8),
                     *(long *)(lVar1 + 0x2f0) == *(long *)(param_2 + 0x3c0));
  }
  return uVar2;
}


// ===== 0010ed40 nv_pci_is_valid_topology_for_direct_pci =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ed70) */

ulong nv_pci_is_valid_topology_for_direct_pci(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (ulong)*(byte *)(param_1 + 0x326);
  if (*(byte *)(param_1 + 0x326) != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x2e0) + 0x10);
    uVar2 = CONCAT71((int7)((ulong)lVar1 >> 8),
                     *(long *)(lVar1 + 0x2f0) == *(long *)(param_2 + 0x3c0));
  }
  return uVar2;
}


// ===== 0010ed80 __pfx_nv_pci_has_common_pci_switch =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ee36) */
/* WARNING: Removing unreachable block (ram,0x0010ee40) */

undefined8 __pfx_nv_pci_has_common_pci_switch(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x2e0) + 0x10);
  if ((*(byte *)(lVar1 + 0x7a3) & 1) == 0) {
    lVar1 = lVar1 + -0xd0;
  }
  else {
    lVar1 = *(long *)(lVar1 + 0x958);
  }
  if ((*(long *)(*(long *)(lVar1 + 0x10) + 0x10) != 0) &&
     (lVar1 = *(long *)(*(long *)(lVar1 + 0x10) + 0x38), lVar1 != 0)) {
    do {
      lVar2 = param_2;
      if ((*(byte *)(param_2 + 0x873) & 1) != 0) {
        lVar2 = *(long *)(param_2 + 0xa28);
      }
      while (lVar2 = *(long *)(lVar2 + 0x10), *(long *)(lVar2 + 0x10) != 0) {
        while( true ) {
          lVar2 = *(long *)(lVar2 + 0x38);
          if (lVar2 == 0) goto LAB_0010ee17;
          if (lVar1 == lVar2) {
            return 1;
          }
          if ((*(byte *)(lVar2 + 0x873) & 1) == 0) break;
          lVar2 = *(long *)(*(long *)(lVar2 + 0xa28) + 0x10);
          if (*(long *)(lVar2 + 0x10) == 0) goto LAB_0010ee17;
        }
      }
LAB_0010ee17:
      if ((*(byte *)(lVar1 + 0x873) & 1) != 0) {
        lVar1 = *(long *)(lVar1 + 0xa28);
      }
    } while ((*(long *)(*(long *)(lVar1 + 0x10) + 0x10) != 0) &&
            (lVar1 = *(long *)(*(long *)(lVar1 + 0x10) + 0x38), lVar1 != 0));
  }
  return 0;
}


// ===== 0010ed90 nv_pci_has_common_pci_switch =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0010ee36) */
/* WARNING: Removing unreachable block (ram,0x0010ee40) */

undefined8 nv_pci_has_common_pci_switch(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x2e0) + 0x10);
  if ((*(byte *)(lVar1 + 0x7a3) & 1) == 0) {
    lVar1 = lVar1 + -0xd0;
  }
  else {
    lVar1 = *(long *)(lVar1 + 0x958);
  }
  if ((*(long *)(*(long *)(lVar1 + 0x10) + 0x10) != 0) &&
     (lVar1 = *(long *)(*(long *)(lVar1 + 0x10) + 0x38), lVar1 != 0)) {
    do {
      lVar2 = param_2;
      if ((*(byte *)(param_2 + 0x873) & 1) != 0) {
        lVar2 = *(long *)(param_2 + 0xa28);
      }
      while (lVar2 = *(long *)(lVar2 + 0x10), *(long *)(lVar2 + 0x10) != 0) {
        while( true ) {
          lVar2 = *(long *)(lVar2 + 0x38);
          if (lVar2 == 0) goto LAB_0010ee17;
          if (lVar1 == lVar2) {
            return 1;
          }
          if ((*(byte *)(lVar2 + 0x873) & 1) == 0) break;
          lVar2 = *(long *)(*(long *)(lVar2 + 0xa28) + 0x10);
          if (*(long *)(lVar2 + 0x10) == 0) goto LAB_0010ee17;
        }
      }
LAB_0010ee17:
      if ((*(byte *)(lVar1 + 0x873) & 1) != 0) {
        lVar1 = *(long *)(lVar1 + 0xa28);
      }
    } while ((*(long *)(*(long *)(lVar1 + 0x10) + 0x10) != 0) &&
            (lVar1 = *(long *)(*(long *)(lVar1 + 0x10) + 0x38), lVar1 != 0));
  }
  return 0;
}


