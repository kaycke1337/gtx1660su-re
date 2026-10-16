// ===== 002813f0 x86emuOp_jump_near_NBE =====

void x86emuOp_jump_near_NBE(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 0x41) != 0) {
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483f8 = DAT_005483f8 + cVar1;
  return;
}


// ===== 00281430 x86emuOp_jump_near_BE =====

void x86emuOp_jump_near_BE(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 0x41) != 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281460 x86emuOp_jump_near_NZ =====

void x86emuOp_jump_near_NZ(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 0x40) == 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281490 x86emuOp_jump_near_Z =====

void x86emuOp_jump_near_Z(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 0x40) != 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002814c0 x86emuOp_jump_near_NB =====

void x86emuOp_jump_near_NB(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 1) == 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002814f0 x86emuOp_jump_near_B =====

void x86emuOp_jump_near_B(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (((byte)DAT_005483fc & 1) != 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281520 x86emuOp_jump_near_NO =====

void x86emuOp_jump_near_NO(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if ((DAT_005483fc._1_1_ & 8) == 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281550 x86emuOp_jump_near_O =====

void x86emuOp_jump_near_O(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if ((DAT_005483fc._1_1_ & 8) != 0) {
    DAT_005483f8 = DAT_005483f8 + cVar1;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281580 x86emuOp_push_byte_IMM =====

void x86emuOp_push_byte_IMM(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if ((DAT_0054840c & 0x200) != 0) {
    push_long((int)cVar1);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word((short)cVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002815d0 x86emuOp_test_AL_IMM =====

void x86emuOp_test_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  test_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281600 x86emuOp_test_byte_RM_R =====

void x86emuOp_test_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        test_byte(*puVar3,*puVar4);
      }
LAB_0028169b:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0028169b;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  test_byte(uVar1,*puVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002816e0 x86emuOp_opcF6_byte_RM =====

void x86emuOp_opcF6_byte_RM(void)

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
    if (local_1c == 4) {
      uVar3 = decode_rm10_address(local_20);
      uVar1 = fetch_data_byte(uVar3);
      mul_byte(uVar1);
      goto LAB_00281775;
    }
    if (4 < local_1c) {
      if (local_1c == 6) {
        uVar3 = decode_rm10_address(local_20);
        uVar1 = fetch_data_byte(uVar3);
        div_byte(uVar1);
      }
      else if (local_1c == 7) {
        uVar3 = decode_rm10_address(local_20);
        uVar1 = fetch_data_byte(uVar3);
        idiv_byte(uVar1);
      }
      else if (local_1c == 5) {
        uVar3 = decode_rm10_address(local_20);
        uVar1 = fetch_data_byte(uVar3);
        imul_byte(uVar1);
      }
      goto LAB_00281775;
    }
    if (local_1c == 2) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_00281ab8;
    }
    if (local_1c == 3) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_00281938;
    }
    if (local_1c == 0) {
      uVar3 = decode_rm10_address(local_20);
      goto LAB_00281750;
    }
  }
  else if (local_24 < 3) {
    if (local_24 == 0) {
      if (local_1c == 4) {
        uVar3 = decode_rm00_address(local_20);
        uVar1 = fetch_data_byte(uVar3);
        mul_byte(uVar1);
        goto LAB_00281775;
      }
      if (4 < local_1c) {
        if (local_1c == 6) {
          uVar3 = decode_rm00_address(local_20);
          uVar1 = fetch_data_byte(uVar3);
          div_byte(uVar1);
        }
        else if (local_1c == 7) {
          uVar3 = decode_rm00_address(local_20);
          uVar1 = fetch_data_byte(uVar3);
          idiv_byte(uVar1);
        }
        else if (local_1c == 5) {
          uVar3 = decode_rm00_address(local_20);
          uVar1 = fetch_data_byte(uVar3);
          imul_byte(uVar1);
        }
        goto LAB_00281775;
      }
      if (local_1c == 2) {
        uVar3 = decode_rm00_address(local_20);
LAB_00281ab8:
        uVar1 = fetch_data_byte(uVar3);
        uVar1 = not_byte(uVar1);
        store_data_byte(uVar3,uVar1);
        goto LAB_00281775;
      }
      if (local_1c == 3) {
        uVar3 = decode_rm00_address(local_20);
LAB_00281938:
        uVar1 = fetch_data_byte(uVar3);
        uVar1 = neg_byte(uVar1);
        store_data_byte(uVar3,uVar1);
        goto LAB_00281775;
      }
      if (local_1c == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_00281750:
        uVar1 = fetch_byte_imm();
        uVar2 = fetch_data_byte(uVar3);
        test_byte(uVar2,uVar1);
        goto LAB_00281775;
      }
    }
    else {
      if (local_24 != 1) goto LAB_00281775;
      if (local_1c == 4) {
        uVar3 = decode_rm01_address(local_20);
        uVar1 = fetch_data_byte(uVar3);
        mul_byte(uVar1);
        goto LAB_00281775;
      }
      if (4 < local_1c) {
        if (local_1c == 6) {
          uVar3 = decode_rm01_address(local_20);
          uVar1 = fetch_data_byte(uVar3);
          div_byte(uVar1);
        }
        else if (local_1c == 7) {
          uVar3 = decode_rm01_address(local_20);
          uVar1 = fetch_data_byte(uVar3);
          idiv_byte(uVar1);
        }
        else if (local_1c == 5) {
          uVar3 = decode_rm01_address(local_20);
          uVar1 = fetch_data_byte(uVar3);
          imul_byte(uVar1);
        }
        goto LAB_00281775;
      }
      if (local_1c == 2) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_00281ab8;
      }
      if (local_1c == 3) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_00281938;
      }
      if (local_1c == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_00281750;
      }
    }
  }
  else {
    if (local_24 != 3) goto LAB_00281775;
    if (local_1c == 4) {
      puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
      mul_byte(*puVar4);
      goto LAB_00281775;
    }
    if (4 < local_1c) {
      if (local_1c == 6) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        div_byte(*puVar4);
      }
      else if (local_1c == 7) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        idiv_byte(*puVar4);
      }
      else if (local_1c == 5) {
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        imul_byte(*puVar4);
      }
      goto LAB_00281775;
    }
    if (local_1c == 2) {
      puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
      uVar1 = not_byte(*puVar4);
      *puVar4 = uVar1;
      goto LAB_00281775;
    }
    if (local_1c == 3) {
      puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
      uVar1 = neg_byte(*puVar4);
      *puVar4 = uVar1;
      goto LAB_00281775;
    }
    if (local_1c == 0) {
      puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
      uVar1 = fetch_byte_imm();
      test_byte(*puVar4,uVar1);
      goto LAB_00281775;
    }
  }
  if (local_1c == 1) {
    X86EMU_halt_sys();
  }
LAB_00281775:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281bb0 x86emuOp_aad =====

void x86emuOp_aad(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (cVar1 != '\n') {
    X86EMU_halt_sys();
  }
  DAT_005483d8 = aad_word(DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281bf0 x86emuOp_aam =====

void x86emuOp_aam(void)

{
  char cVar1;
  
  cVar1 = fetch_byte_imm();
  if (cVar1 != '\n') {
    X86EMU_halt_sys();
  }
  DAT_005483d8 = aam_word((undefined1)DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281c30 x86emuOp_iret =====

void x86emuOp_iret(void)

{
  ushort uVar1;
  
  DAT_005483f8 = pop_word();
  DAT_00548400 = pop_word();
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483fc = (uint)uVar1;
  return;
}


// ===== 00281c70 x86emuOp_ret_far =====

void x86emuOp_ret_far(void)

{
  DAT_005483f8 = pop_word();
  DAT_00548400 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281ca0 x86emuOp_ret_far_IMM =====

void x86emuOp_ret_far_IMM(void)

{
  short sVar1;
  
  sVar1 = fetch_word_imm();
  DAT_005483f8 = pop_word();
  DAT_00548400 = pop_word();
  DAT_005483e8._0_2_ = (short)DAT_005483e8 + sVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281cf0 x86emuOp_leave =====

void x86emuOp_leave(void)

{
  DAT_005483e8._0_2_ = (undefined2)DAT_005483ec;
  DAT_005483ec._0_2_ = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281d20 x86emuOp_ret_near =====

void x86emuOp_ret_near(void)

{
  DAT_005483f8 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281d40 x86emuOp_ret_near_IMM =====

void x86emuOp_ret_near_IMM(void)

{
  short sVar1;
  
  sVar1 = fetch_word_imm();
  DAT_005483f8 = pop_word();
  DAT_005483e8._0_2_ = (short)DAT_005483e8 + sVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281d80 x86emuOp_pop_DS =====

void x86emuOp_pop_DS(void)

{
  DAT_00548402 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281da0 x86emuOp_pop_SS =====

void x86emuOp_pop_SS(void)

{
  DAT_00548404 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281dc0 x86emuOp_pop_ES =====

void x86emuOp_pop_ES(void)

{
  DAT_00548406 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281de0 x86emuOp_into =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_into(void)

{
  if ((DAT_005483fc & 0x800) != 0) {
    if (_DAT_00547be0 == (code *)0x0) {
      push_word(DAT_005483fc & 0xffff);
      DAT_005483fc = DAT_005483fc & 0xfffffcff;
      push_word(DAT_00548400);
      DAT_00548400 = mem_access_word(0x12);
      push_word(DAT_005483f8);
      DAT_005483f8 = mem_access_word(0x10);
    }
    else {
      (*_DAT_00547be0)(4);
    }
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281e80 x86emuOp_int_IMM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_int_IMM(void)

{
  byte bVar1;
  
  bVar1 = fetch_byte_imm();
  if ((code *)(&_X86EMU_intrTab)[bVar1] != (code *)0x0) {
    (*(code *)(&_X86EMU_intrTab)[bVar1])(bVar1);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(DAT_005483fc & 0xffff);
  DAT_005483fc = DAT_005483fc & 0xfffffcff;
  push_word(DAT_00548400);
  DAT_00548400 = mem_access_word((uint)bVar1 * 4 + 2);
  push_word(DAT_005483f8);
  DAT_005483f8 = mem_access_word((uint)bVar1 * 4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281f30 x86emuOp_int3 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void x86emuOp_int3(void)

{
  if (DAT_00547bd8 != (code *)0x0) {
    (*DAT_00547bd8)(3);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  push_word(DAT_005483fc & 0xffff);
  DAT_005483fc = DAT_005483fc & 0xfffffcff;
  push_word(DAT_00548400);
  DAT_00548400 = mem_access_word(0xe);
  push_word(DAT_005483f8);
  DAT_005483f8 = mem_access_word(0xc);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00281fc0 x86emuOp_enter =====

void x86emuOp_enter(void)

{
  short sVar1;
  byte bVar2;
  short sVar3;
  undefined2 uVar4;
  short sVar5;
  uint uVar6;
  
  sVar3 = fetch_word_imm();
  bVar2 = fetch_byte_imm();
  push_word((short)DAT_005483ec);
  sVar1 = (short)DAT_005483e8;
  if (bVar2 != 0) {
    if (bVar2 != 1) {
      uVar6 = 1;
      do {
        uVar6 = uVar6 + 1;
        sVar5 = (short)DAT_005483ec + -2;
        DAT_005483ec._0_2_ = (short)DAT_005483ec + -2;
        uVar4 = fetch_data_word_abs(DAT_00548404,sVar5);
        push_word(uVar4);
      } while (uVar6 != bVar2);
    }
    push_word(sVar1);
  }
  DAT_005483ec._0_2_ = sVar1;
  DAT_005483e8._0_2_ = (short)DAT_005483e8 - sVar3;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282090 x86emuOp_scas_word =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_scas_word(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  short sVar4;
  
  uVar3 = DAT_0054840c & 0x80;
  if ((DAT_0054840c & 0x200) == 0) {
    if ((DAT_005483fc & 0x400) == 0) {
      if (uVar3 != 0) {
        sVar4 = 2;
        goto LAB_00282219;
      }
      sVar4 = 2;
      if ((DAT_0054840c & 0x100) == 0) goto LAB_002822a0;
      sVar4 = 2;
    }
    else {
      if (uVar3 != 0) {
        sVar4 = -2;
        goto LAB_00282219;
      }
      sVar4 = -2;
      if ((DAT_0054840c & 0x100) == 0) {
LAB_002822a0:
        uVar1 = fetch_data_word_abs(DAT_00548406,DAT_005483f4);
        cmp_word(_DAT_005483d8 & 0xffff,uVar1);
        goto LAB_002822c2;
      }
      sVar4 = -2;
    }
  }
  else if ((DAT_005483fc & 0x400) == 0) {
    if (uVar3 != 0) {
      sVar4 = 4;
      goto LAB_00282219;
    }
    sVar4 = 4;
    if ((DAT_0054840c & 0x100) == 0) goto LAB_002822d8;
    sVar4 = 4;
  }
  else {
    if (uVar3 != 0) {
      sVar4 = -4;
LAB_00282219:
      do {
        if ((short)DAT_005483e0 == 0) break;
        if ((DAT_0054840c & 0x200) == 0) {
          uVar1 = fetch_data_word_abs();
          cmp_word(_DAT_005483d8 & 0xffff,uVar1);
        }
        else {
          uVar2 = fetch_data_long_abs(DAT_00548406,DAT_005483f4);
          cmp_long(_DAT_005483d8,uVar2);
        }
        DAT_005483f4 = DAT_005483f4 + sVar4;
        DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
      } while ((DAT_005483fc & 0x40) != 0);
      DAT_0054840c = DAT_0054840c & 0xffffff00;
      goto LAB_00282283;
    }
    sVar4 = -4;
    if ((DAT_0054840c & 0x100) == 0) {
LAB_002822d8:
      uVar2 = fetch_data_long_abs(DAT_00548406,DAT_005483f4);
      cmp_long(_DAT_005483d8,uVar2);
LAB_002822c2:
      DAT_005483f4 = DAT_005483f4 + sVar4;
      goto LAB_00282283;
    }
    sVar4 = -4;
  }
  do {
    if ((short)DAT_005483e0 == 0) break;
    if ((DAT_0054840c & 0x200) == 0) {
      uVar1 = fetch_data_word_abs();
      cmp_word(_DAT_005483d8 & 0xffff,uVar1);
    }
    else {
      uVar2 = fetch_data_long_abs(DAT_00548406,DAT_005483f4);
      cmp_long(_DAT_005483d8,uVar2);
    }
    DAT_005483f4 = DAT_005483f4 + sVar4;
    DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
  } while ((DAT_005483fc & 0x40) == 0);
  DAT_0054840c = DAT_0054840c & 0xfffffeff;
LAB_00282283:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282300 x86emuOp_cmps_word =====

void x86emuOp_cmps_word(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  short sVar6;
  
  uVar5 = DAT_0054840c & 0x80;
  if ((DAT_0054840c & 0x200) == 0) {
    if ((DAT_005483fc & 0x400) == 0) {
      if (uVar5 != 0) {
        sVar6 = 2;
        goto LAB_002824c3;
      }
      sVar6 = 2;
      if ((DAT_0054840c & 0x100) == 0) goto LAB_00282550;
      sVar6 = 2;
    }
    else {
      if (uVar5 != 0) {
        sVar6 = -2;
        goto LAB_002824c3;
      }
      sVar6 = -2;
      if ((DAT_0054840c & 0x100) == 0) {
LAB_00282550:
        uVar1 = fetch_data_word(DAT_005483f0);
        uVar2 = fetch_data_word_abs(DAT_00548406,DAT_005483f4);
        cmp_word(uVar1,uVar2);
        goto LAB_0028257e;
      }
      sVar6 = -2;
    }
  }
  else if ((DAT_005483fc & 0x400) == 0) {
    if (uVar5 != 0) {
      sVar6 = 4;
      goto LAB_002824c3;
    }
    sVar6 = 4;
    if ((DAT_0054840c & 0x100) == 0) goto LAB_00282598;
    sVar6 = 4;
  }
  else {
    if (uVar5 != 0) {
      sVar6 = -4;
LAB_002824c3:
      do {
        if ((short)DAT_005483e0 == 0) break;
        if ((DAT_0054840c & 0x200) == 0) {
          uVar1 = fetch_data_word();
          uVar2 = fetch_data_word_abs(DAT_00548406,DAT_005483f4);
          cmp_word(uVar1,uVar2);
        }
        else {
          uVar3 = fetch_data_long(DAT_005483f0);
          uVar4 = fetch_data_long_abs(DAT_00548406,DAT_005483f4);
          cmp_long(uVar3,uVar4);
        }
        DAT_005483f0 = DAT_005483f0 + sVar6;
        DAT_005483f4 = DAT_005483f4 + sVar6;
        DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
      } while ((DAT_005483fc & 0x40) != 0);
      DAT_0054840c = DAT_0054840c & 0xffffff00;
      goto LAB_00282533;
    }
    sVar6 = -4;
    if ((DAT_0054840c & 0x100) == 0) {
LAB_00282598:
      uVar3 = fetch_data_long(DAT_005483f0);
      uVar4 = fetch_data_long_abs(DAT_00548406,DAT_005483f4);
      cmp_long(uVar3,uVar4);
LAB_0028257e:
      DAT_005483f0 = DAT_005483f0 + sVar6;
      DAT_005483f4 = DAT_005483f4 + sVar6;
      goto LAB_00282533;
    }
    sVar6 = -4;
  }
  do {
    if ((short)DAT_005483e0 == 0) break;
    if ((DAT_0054840c & 0x200) == 0) {
      uVar1 = fetch_data_word();
      uVar2 = fetch_data_word_abs(DAT_00548406,DAT_005483f4);
      cmp_word(uVar1,uVar2);
    }
    else {
      uVar3 = fetch_data_long(DAT_005483f0);
      uVar4 = fetch_data_long_abs(DAT_00548406,DAT_005483f4);
      cmp_long(uVar3,uVar4);
    }
    DAT_005483f0 = DAT_005483f0 + sVar6;
    DAT_005483f4 = DAT_005483f4 + sVar6;
    DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
  } while ((DAT_005483fc & 0x40) == 0);
  DAT_0054840c = DAT_0054840c & 0xfffffeff;
LAB_00282533:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002825d0 x86emuOp_cmp_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_cmp_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    cmp_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  cmp_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282640 x86emuOp_cmp_word_R_RM =====

void x86emuOp_cmp_word_R_RM(void)

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
      goto LAB_00282768;
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
          cmp_word(*puVar5,*puVar6);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        cmp_long(*puVar3,*puVar4);
      }
LAB_002826d8:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
LAB_00282768:
        uVar1 = fetch_data_word(uVar2);
        cmp_word(*puVar5,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002826d8;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00282768;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  cmp_long(*puVar3,uVar2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282800 x86emuOp_cmp_word_RM_R =====

void x86emuOp_cmp_word_RM_R(void)

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
      goto LAB_002828fd;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar5 = (undefined2 *)decode_rm_word_register(local_20);
          puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          cmp_word(*puVar5,*puVar6);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar4 = (undefined4 *)decode_rm_long_register();
        puVar3 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        cmp_long(*puVar4,*puVar3);
      }
LAB_00282888:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_002828fd:
        uVar1 = fetch_data_word(uVar2);
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        cmp_word(uVar1,*puVar5);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00282888;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_002828fd;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  cmp_long(uVar2,*puVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282990 x86emuOp_scas_byte =====

void x86emuOp_scas_byte(void)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar2 = -(ushort)((DAT_005483fc & 0x400) != 0) | 1;
  if ((DAT_0054840c & 0x80) == 0) {
    if ((DAT_0054840c & 0x100) == 0) {
      uVar1 = fetch_data_byte_abs(DAT_00548406,DAT_005483f4);
      cmp_byte((undefined1)DAT_005483d8,uVar1);
      DAT_005483f4 = DAT_005483f4 + uVar2;
    }
    else {
      do {
        if ((short)DAT_005483e0 == 0) break;
        uVar1 = fetch_data_byte_abs(DAT_00548406,DAT_005483f4);
        cmp_byte((undefined1)DAT_005483d8,uVar1);
        DAT_005483f4 = DAT_005483f4 + uVar2;
        DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
      } while ((DAT_005483fc & 0x40) == 0);
      DAT_0054840c = DAT_0054840c & 0xfffffeff;
    }
  }
  else {
    do {
      if ((short)DAT_005483e0 == 0) break;
      uVar1 = fetch_data_byte_abs(DAT_00548406,DAT_005483f4);
      cmp_byte((undefined1)DAT_005483d8,uVar1);
      DAT_005483f4 = DAT_005483f4 + uVar2;
      DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
    } while ((DAT_005483fc & 0x40) != 0);
    DAT_0054840c = DAT_0054840c & 0xffffff00;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282ad0 x86emuOp_cmps_byte =====

void x86emuOp_cmps_byte(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  
  uVar3 = -(ushort)((DAT_005483fc & 0x400) != 0) | 1;
  if ((DAT_0054840c & 0x80) == 0) {
    if ((DAT_0054840c & 0x100) == 0) {
      uVar1 = fetch_data_byte(DAT_005483f0);
      uVar2 = fetch_data_byte_abs(DAT_00548406,DAT_005483f4);
      cmp_byte(uVar1,uVar2);
      DAT_005483f0 = DAT_005483f0 + uVar3;
      DAT_005483f4 = DAT_005483f4 + uVar3;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    do {
      if ((short)DAT_005483e0 == 0) break;
      uVar1 = fetch_data_byte(DAT_005483f0);
      uVar2 = fetch_data_byte_abs(DAT_00548406,DAT_005483f4);
      cmp_byte(uVar1,uVar2);
      DAT_005483f0 = DAT_005483f0 + uVar3;
      DAT_005483f4 = DAT_005483f4 + uVar3;
      DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
    } while ((DAT_005483fc & 0x40) == 0);
    DAT_0054840c = DAT_0054840c & 0xfffff880;
    return;
  }
  do {
    if ((short)DAT_005483e0 == 0) break;
    uVar1 = fetch_data_byte(DAT_005483f0);
    uVar2 = fetch_data_byte_abs(DAT_00548406,DAT_005483f4);
    cmp_byte(uVar1,uVar2);
    DAT_005483f0 = DAT_005483f0 + uVar3;
    DAT_005483f4 = DAT_005483f4 + uVar3;
    DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
  } while ((DAT_005483fc & 0x40) != 0);
  DAT_0054840c = (DAT_0054840c >> 8 & 0xfffff9) << 8;
  return;
}


// ===== 00282c70 x86emuOp_cmp_byte_AL_IMM =====

void x86emuOp_cmp_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  cmp_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282ca0 x86emuOp_cmp_byte_R_RM =====

void x86emuOp_cmp_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        cmp_byte(*puVar3,*puVar4);
      }
LAB_00282d43:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00282d43;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  cmp_byte(*puVar3,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282d90 x86emuOp_cmp_byte_RM_R =====

void x86emuOp_cmp_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        cmp_byte(*puVar3,*puVar4);
      }
LAB_00282e2b:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00282e2b;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  cmp_byte(uVar1,*puVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282e70 x86emuOp_stos_word =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_stos_word(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  
  uVar1 = -(ushort)((DAT_005483fc & 0x400) == 0);
  if ((DAT_0054840c & 0x200) == 0) {
    sVar4 = (uVar1 & 4) - 2;
  }
  else {
    sVar4 = (uVar1 & 8) - 4;
  }
  iVar3 = 0;
  if ((DAT_0054840c & 0x180) != 0) {
    uVar2 = (uint)(ushort)DAT_005483e0;
    DAT_0054840c = DAT_0054840c & 0xfffffe7f;
    DAT_005483e0._0_2_ = 0;
    if (uVar2 == 0) goto LAB_00282f30;
    iVar3 = uVar2 - 1;
  }
  do {
    if ((DAT_0054840c & 0x200) == 0) {
      store_data_word_abs(DAT_00548406,DAT_005483f4,_DAT_005483d8 & 0xffff);
    }
    else {
      store_data_long_abs(DAT_00548406,DAT_005483f4,_DAT_005483d8);
    }
    iVar3 = iVar3 + -1;
    DAT_005483f4 = DAT_005483f4 + sVar4;
  } while (iVar3 != -1);
LAB_00282f30:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00282f50 x86emuOp_movs_word =====

void x86emuOp_movs_word(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  
  uVar1 = -(ushort)((DAT_005483fc & 0x400) == 0);
  if ((DAT_0054840c & 0x200) == 0) {
    sVar6 = (uVar1 & 4) - 2;
  }
  else {
    sVar6 = (uVar1 & 8) - 4;
  }
  iVar5 = 0;
  if ((DAT_0054840c & 0x180) != 0) {
    uVar4 = (uint)(ushort)DAT_005483e0;
    DAT_0054840c = DAT_0054840c & 0xfffffe7f;
    DAT_005483e0._0_2_ = 0;
    if (uVar4 == 0) goto LAB_00283030;
    iVar5 = uVar4 - 1;
  }
  do {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = fetch_data_word();
      store_data_word_abs(DAT_00548406,DAT_005483f4,uVar2);
    }
    else {
      uVar3 = fetch_data_long(DAT_005483f0);
      store_data_long_abs(DAT_00548406,DAT_005483f4,uVar3);
    }
    iVar5 = iVar5 + -1;
    DAT_005483f4 = DAT_005483f4 + sVar6;
    DAT_005483f0 = DAT_005483f0 + sVar6;
  } while (iVar5 != -1);
LAB_00283030:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283050 x86emuOp_stos_byte =====

void x86emuOp_stos_byte(void)

{
  ushort uVar1;
  
  uVar1 = -(ushort)((DAT_005483fc & 0x400) != 0) | 1;
  if ((DAT_0054840c & 0x180) == 0) {
    store_data_byte_abs(DAT_00548406,DAT_005483f4,(undefined1)DAT_005483d8);
    DAT_005483f4 = DAT_005483f4 + uVar1;
  }
  else {
    if ((short)DAT_005483e0 != 0) {
      do {
        store_data_byte_abs(DAT_00548406,DAT_005483f4,(undefined1)DAT_005483d8);
        DAT_005483e0._0_2_ = (short)DAT_005483e0 + -1;
        DAT_005483f4 = DAT_005483f4 + uVar1;
      } while ((short)DAT_005483e0 != 0);
      DAT_005483e0._0_2_ = 0;
    }
    DAT_0054840c = DAT_0054840c & 0xfffffe7f;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283120 x86emuOp_movs_byte =====

void x86emuOp_movs_byte(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  bool bVar5;
  
  uVar4 = -(ushort)((DAT_005483fc & 0x400) != 0) | 1;
  iVar3 = 0;
  if ((DAT_0054840c & 0x180) != 0) {
    uVar2 = (uint)(ushort)DAT_005483e0;
    DAT_0054840c = DAT_0054840c & 0xfffffe7f;
    DAT_005483e0._0_2_ = 0;
    if (uVar2 == 0) goto LAB_002831c2;
    iVar3 = uVar2 - 1;
  }
  do {
    uVar1 = fetch_data_byte(DAT_005483f0);
    store_data_byte_abs(DAT_00548406,DAT_005483f4,uVar1);
    DAT_005483f4 = DAT_005483f4 + uVar4;
    DAT_005483f0 = DAT_005483f0 + uVar4;
    bVar5 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar5);
LAB_002831c2:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002831e0 x86emuOp_popf_word =====

void x86emuOp_popf_word(void)

{
  ushort uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = pop_word();
    DAT_005483fc = (uint)uVar1;
  }
  else {
    DAT_005483fc = pop_long();
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283220 x86emuOp_pop_RM =====

void x86emuOp_pop_RM(void)

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
LAB_002832d7:
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm10_address(local_20);
        goto LAB_0028332d;
      }
      uVar3 = decode_rm10_address(local_20);
      goto LAB_002832e8;
    }
  }
  else {
    X86EMU_halt_sys();
    iVar1 = local_24 + -2;
    if (iVar1 == 0) goto LAB_002832d7;
  }
  if (SBORROW4(local_24,2) != iVar1 < 0) {
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
LAB_0028332d:
        uVar2 = pop_word();
        store_data_word(uVar3,uVar2);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar3 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002832ae;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        goto LAB_0028332d;
      }
      uVar3 = decode_rm01_address(local_20);
    }
LAB_002832e8:
    uVar4 = pop_long();
    store_data_long(uVar3,uVar4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_24 == 3) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar6 = (undefined2 *)decode_rm_word_register(local_20);
      uVar2 = pop_word();
      *puVar6 = uVar2;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    puVar5 = (undefined4 *)decode_rm_long_register();
    uVar3 = pop_long();
    *puVar5 = uVar3;
  }
LAB_002832ae:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002833a0 x86emuOp_pop_all =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_pop_all(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f4 = pop_long();
    _DAT_005483f0 = pop_long();
    DAT_005483ec = pop_long();
    DAT_005483e8 = DAT_005483e8 + 4;
    _DAT_005483dc = pop_long();
    DAT_005483e4 = pop_long();
    DAT_005483e0 = pop_long();
    _DAT_005483d8 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  _DAT_005483f4 = CONCAT22(DAT_005483f4_2,uVar1);
  uVar1 = pop_word();
  _DAT_005483f0 = CONCAT22(DAT_005483f0_2,uVar1);
  uVar1 = pop_word();
  DAT_005483e8._0_2_ = (short)DAT_005483e8 + 2;
  DAT_005483ec = CONCAT22(DAT_005483ec._2_2_,uVar1);
  uVar1 = pop_word();
  _DAT_005483dc = CONCAT22(DAT_005483dc_2,uVar1);
  uVar1 = pop_word();
  DAT_005483e4 = CONCAT22(DAT_005483e4._2_2_,uVar1);
  uVar1 = pop_word();
  DAT_005483e0 = CONCAT22(DAT_005483e0._2_2_,uVar1);
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00283480 x86emuOp_pop_DI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_pop_DI(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f4 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483f4 = CONCAT22(DAT_005483f4_2,uVar1);
  return;
}


// ===== 002834d0 x86emuOp_pop_SI =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_pop_SI(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483f0 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483f0 = CONCAT22(DAT_005483f0_2,uVar1);
  return;
}


// ===== 00283520 x86emuOp_pop_BP =====

void x86emuOp_pop_BP(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483ec = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483ec = CONCAT22(DAT_005483ec._2_2_,uVar1);
  return;
}


// ===== 00283570 x86emuOp_pop_SP =====

void x86emuOp_pop_SP(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e8 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e8 = CONCAT22(DAT_005483e8._2_2_,uVar1);
  return;
}


// ===== 002835c0 x86emuOp_pop_BX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_pop_BX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483dc = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483dc = CONCAT22(DAT_005483dc_2,uVar1);
  return;
}


// ===== 00283610 x86emuOp_pop_DX =====

void x86emuOp_pop_DX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e4 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e4 = CONCAT22(DAT_005483e4._2_2_,uVar1);
  return;
}


// ===== 00283660 x86emuOp_pop_CX =====

void x86emuOp_pop_CX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    DAT_005483e0 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  DAT_005483e0 = CONCAT22(DAT_005483e0._2_2_,uVar1);
  return;
}


// ===== 002836b0 x86emuOp_pop_AX =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_pop_AX(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = pop_long();
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00283700 x86emuOp_mov_word_SR_RM =====

void x86emuOp_mov_word_SR_RM(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    puVar3 = (undefined2 *)decode_rm_seg_register(local_1c[0]);
    uVar2 = decode_rm10_address(local_20);
    uVar1 = fetch_data_word(uVar2);
    *puVar3 = uVar1;
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  if (local_24 < 3) {
    if (local_24 == 0) {
      puVar3 = (undefined2 *)decode_rm_seg_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
      uVar1 = fetch_data_word(uVar2);
      *puVar3 = uVar1;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 1) {
      puVar3 = (undefined2 *)decode_rm_seg_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
      uVar1 = fetch_data_word(uVar2);
      *puVar3 = uVar1;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
  }
  else if (local_24 == 3) {
    puVar3 = (undefined2 *)decode_rm_seg_register(local_1c[0]);
    puVar4 = (undefined2 *)decode_rm_word_register(local_20);
    *puVar3 = *puVar4;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283810 x86emuOp_mov_word_RM_SR =====

void x86emuOp_mov_word_RM_SR(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
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
        puVar2 = (undefined2 *)decode_rm_word_register(local_20);
        puVar3 = (undefined2 *)decode_rm_seg_register(local_1c[0]);
        *puVar2 = *puVar3;
      }
LAB_0028389e:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar1 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0028389e;
      uVar1 = decode_rm01_address(local_20);
    }
  }
  puVar2 = (undefined2 *)decode_rm_seg_register(local_1c[0]);
  store_data_word(uVar1,*puVar2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002838d0 x86emuOp_add_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_add_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = add_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = add_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00283950 x86emuOp_add_word_R_RM =====

void x86emuOp_add_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_00283a8a;
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
          uVar1 = *puVar6;
          goto LAB_00283a8a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = add_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_002839f2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_00283a8a:
        uVar1 = add_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002839f2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_00283a8a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = add_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283b10 x86emuOp_add_word_RM_R =====

void x86emuOp_add_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00283c25;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = add_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = add_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_00283ba2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00283c25:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = add_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00283ba2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00283c25;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = add_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283cd0 x86emuOp_or_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_or_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = or_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = or_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00283d50 x86emuOp_or_word_R_RM =====

void x86emuOp_or_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_00283e8a;
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
          uVar1 = *puVar6;
          goto LAB_00283e8a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = or_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_00283df2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_00283e8a:
        uVar1 = or_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00283df2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_00283e8a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = or_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00283f10 x86emuOp_or_word_RM_R =====

void x86emuOp_or_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00284025;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = or_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = or_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_00283fa2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00284025:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = or_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00283fa2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00284025;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = or_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002840d0 x86emuOp_adc_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_adc_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = adc_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = adc_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00284150 x86emuOp_adc_word_R_RM =====

void x86emuOp_adc_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_0028428a;
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
          uVar1 = *puVar6;
          goto LAB_0028428a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = adc_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_002841f2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_0028428a:
        uVar1 = adc_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002841f2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_0028428a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = adc_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00284310 x86emuOp_adc_word_RM_R =====

void x86emuOp_adc_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00284425;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = adc_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = adc_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_002843a2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00284425:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = adc_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002843a2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00284425;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = adc_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002844d0 x86emuOp_sbb_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_sbb_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = sbb_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = sbb_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00284550 x86emuOp_sbb_word_R_RM =====

void x86emuOp_sbb_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_0028468a;
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
          uVar1 = *puVar6;
          goto LAB_0028468a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = sbb_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_002845f2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_0028468a:
        uVar1 = sbb_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002845f2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_0028468a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = sbb_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00284710 x86emuOp_sbb_word_RM_R =====

void x86emuOp_sbb_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00284825;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = sbb_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = sbb_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_002847a2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00284825:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = sbb_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002847a2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00284825;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = sbb_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002848d0 x86emuOp_and_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_and_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = and_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = and_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00284950 x86emuOp_and_word_R_RM =====

void x86emuOp_and_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_00284a8a;
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
          uVar1 = *puVar6;
          goto LAB_00284a8a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = and_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_002849f2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_00284a8a:
        uVar1 = and_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002849f2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_00284a8a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = and_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00284b10 x86emuOp_and_word_RM_R =====

void x86emuOp_and_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00284c25;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = and_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = and_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_00284ba2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00284c25:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = and_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00284ba2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00284c25;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = and_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00284cd0 x86emuOp_sub_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_sub_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = sub_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = sub_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00284d50 x86emuOp_sub_word_R_RM =====

void x86emuOp_sub_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_00284e8a;
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
          uVar1 = *puVar6;
          goto LAB_00284e8a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = sub_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_00284df2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_00284e8a:
        uVar1 = sub_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00284df2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_00284e8a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = sub_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00284f10 x86emuOp_sub_word_RM_R =====

void x86emuOp_sub_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00285025;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = sub_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = sub_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_00284fa2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00285025:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = sub_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00284fa2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00285025;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = sub_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002850d0 x86emuOp_xor_word_AX_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp_xor_word_AX_IMM(void)

{
  undefined2 uVar1;
  
  if ((DAT_0054840c & 0x200) == 0) {
    uVar1 = fetch_word_imm();
  }
  else {
    uVar1 = fetch_long_imm();
  }
  if ((DAT_0054840c & 0x200) != 0) {
    _DAT_005483d8 = xor_long(_DAT_005483d8);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  uVar1 = xor_word(_DAT_005483d8 & 0xffff,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  _DAT_005483d8 = CONCAT22(DAT_005483d8_2,uVar1);
  return;
}


// ===== 00285150 x86emuOp_xor_word_R_RM =====

void x86emuOp_xor_word_R_RM(void)

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
      uVar1 = fetch_data_word(uVar2);
      goto LAB_0028528a;
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
          uVar1 = *puVar6;
          goto LAB_0028528a;
        }
        puVar3 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_20);
        uVar2 = xor_long(*puVar3,*puVar4);
        *puVar3 = uVar2;
      }
LAB_002851f2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
        uVar1 = fetch_data_word(uVar2);
LAB_0028528a:
        uVar1 = xor_word(*puVar5,uVar1);
        *puVar5 = uVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002851f2;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        uVar1 = fetch_data_word(uVar2);
        goto LAB_0028528a;
      }
      puVar3 = (undefined4 *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar2 = fetch_data_long(uVar2);
  uVar2 = xor_long(*puVar3,uVar2);
  *puVar3 = uVar2;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285310 x86emuOp_xor_word_RM_R =====

void x86emuOp_xor_word_RM_R(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00285425;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar1 = xor_word(*puVar6,*puVar7);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar2 = xor_long(*puVar5,*puVar4);
        *puVar5 = uVar2;
      }
LAB_002853a2:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00285425:
        uVar1 = fetch_data_word(uVar2);
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c[0]);
        uVar1 = xor_word(uVar1,*puVar6);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002853a2;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00285425;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar3 = fetch_data_long(uVar2);
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar3 = xor_long(uVar3,*puVar5);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002854d0 x86emuOp_add_byte_AL_IMM =====

void x86emuOp_add_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = add_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285500 x86emuOp_add_byte_R_RM =====

void x86emuOp_add_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = add_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_002855a5:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002855a5;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = add_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285600 x86emuOp_add_byte_RM_R =====

void x86emuOp_add_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = add_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_002856ad:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002856ad;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = add_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002856f0 x86emuOp_or_byte_AL_IMM =====

void x86emuOp_or_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = or_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285720 x86emuOp_or_byte_R_RM =====

void x86emuOp_or_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = or_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_002857c5:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002857c5;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = or_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285820 x86emuOp_or_byte_RM_R =====

void x86emuOp_or_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = or_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_002858cd:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002858cd;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = or_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285910 x86emuOp_adc_byte_AL_IMM =====

void x86emuOp_adc_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = adc_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285940 x86emuOp_adc_byte_R_RM =====

void x86emuOp_adc_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = adc_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_002859e5:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002859e5;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = adc_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285a40 x86emuOp_adc_byte_RM_R =====

void x86emuOp_adc_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = adc_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00285aed:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00285aed;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = adc_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285b30 x86emuOp_sbb_byte_AL_IMM =====

void x86emuOp_sbb_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = sbb_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285b60 x86emuOp_sbb_byte_R_RM =====

void x86emuOp_sbb_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = sbb_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00285c05:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00285c05;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = sbb_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285c60 x86emuOp_sbb_byte_RM_R =====

void x86emuOp_sbb_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = sbb_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00285d0d:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00285d0d;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = sbb_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285d50 x86emuOp_and_byte_AL_IMM =====

void x86emuOp_and_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = and_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285d80 x86emuOp_and_byte_R_RM =====

void x86emuOp_and_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = and_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00285e25:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00285e25;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = and_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285e80 x86emuOp_and_byte_RM_R =====

void x86emuOp_and_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = and_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00285f2d:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00285f2d;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = and_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285f70 x86emuOp_sub_byte_AL_IMM =====

void x86emuOp_sub_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = sub_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00285fa0 x86emuOp_sub_byte_R_RM =====

void x86emuOp_sub_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = sub_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00286045:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00286045;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = sub_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002860a0 x86emuOp_sub_byte_RM_R =====

void x86emuOp_sub_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = sub_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_0028614d:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0028614d;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = sub_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286190 x86emuOp_xor_byte_AL_IMM =====

void x86emuOp_xor_byte_AL_IMM(void)

{
  undefined1 uVar1;
  
  uVar1 = fetch_byte_imm();
  DAT_005483d8._0_1_ = xor_byte((undefined1)DAT_005483d8,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002861c0 x86emuOp_xor_byte_R_RM =====

void x86emuOp_xor_byte_R_RM(void)

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
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_20);
        uVar1 = xor_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_00286265:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00286265;
      puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  uVar1 = xor_byte(*puVar3,uVar1);
  *puVar3 = uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002862c0 x86emuOp_xor_byte_RM_R =====

void x86emuOp_xor_byte_RM_R(void)

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
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (undefined1 *)decode_rm_byte_register(local_20);
        puVar4 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
        uVar1 = xor_byte(*puVar3,*puVar4);
        *puVar3 = uVar1;
      }
LAB_0028636d:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_0028636d;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_byte(uVar2);
  puVar3 = (undefined1 *)decode_rm_byte_register(local_1c[0]);
  uVar1 = xor_byte(uVar1,*puVar3);
  store_data_byte(uVar2,uVar1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002863b0 x86emuOp_outs_word =====

void x86emuOp_outs_word(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    outs(4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  outs(2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286400 x86emuOp_outs_byte =====

void x86emuOp_outs_byte(void)

{
  outs(1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286420 x86emuOp_ins_word =====

void x86emuOp_ins_word(void)

{
  if ((DAT_0054840c & 0x200) != 0) {
    ins(4);
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  ins(2);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286470 x86emuOp_ins_byte =====

void x86emuOp_ins_byte(void)

{
  ins(1);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286490 x86emuOp_imul_byte_IMM =====

void x86emuOp_imul_byte_IMM(void)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  short *psVar7;
  uint uVar8;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_2c,&local_24,&local_28);
  if (local_2c == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar6 = (undefined2 *)decode_rm_word_register(local_24);
      uVar3 = decode_rm10_address(local_28);
      goto LAB_00286648;
    }
    puVar4 = (undefined4 *)decode_rm_long_register();
    uVar3 = decode_rm10_address(local_28);
  }
  else {
    if (2 < local_2c) {
      if (local_2c == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_24);
          psVar7 = (short *)decode_rm_word_register(local_28);
          cVar1 = fetch_byte_imm();
          uVar8 = DAT_005483fc | 0x801;
          DAT_005483fc = DAT_005483fc & 0xfffff7fe;
          if (0xffff < (uint)((int)*psVar7 * (int)cVar1)) {
            DAT_005483fc = uVar8;
          }
          *puVar6 = (short)((int)*psVar7 * (int)cVar1);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar4 = (undefined4 *)decode_rm_long_register();
        puVar5 = (undefined4 *)decode_rm_long_register(local_28);
        cVar1 = fetch_byte_imm();
        imul_long_direct(&local_20,&local_1c,*puVar5,(int)cVar1);
        uVar8 = DAT_005483fc | 0x801;
        DAT_005483fc = DAT_005483fc & 0xfffff7fe;
        if (local_1c != 0) {
          DAT_005483fc = uVar8;
        }
        *puVar4 = local_20;
      }
LAB_00286578:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_2c == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar6 = (undefined2 *)decode_rm_word_register(local_24);
        uVar3 = decode_rm00_address(local_28);
LAB_00286648:
        sVar2 = fetch_data_word(uVar3);
        cVar1 = fetch_byte_imm();
        uVar8 = DAT_005483fc | 0x801;
        DAT_005483fc = DAT_005483fc & 0xfffff7fe;
        if (0xffff < (uint)((int)sVar2 * (int)cVar1)) {
          DAT_005483fc = uVar8;
        }
        *puVar6 = (short)((int)sVar2 * (int)cVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar4 = (undefined4 *)decode_rm_long_register();
      uVar3 = decode_rm00_address(local_28);
    }
    else {
      if (local_2c != 1) goto LAB_00286578;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar6 = (undefined2 *)decode_rm_word_register(local_24);
        uVar3 = decode_rm01_address(local_28);
        goto LAB_00286648;
      }
      puVar4 = (undefined4 *)decode_rm_long_register();
      uVar3 = decode_rm01_address(local_28);
    }
  }
  uVar3 = fetch_data_long(uVar3);
  cVar1 = fetch_byte_imm();
  imul_long_direct(&local_20,&local_1c,uVar3,(int)cVar1);
  uVar8 = DAT_005483fc | 0x801;
  DAT_005483fc = DAT_005483fc & 0xfffff7fe;
  if (local_1c != 0) {
    DAT_005483fc = uVar8;
  }
  *puVar4 = local_20;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286740 x86emuOp_imul_word_IMM =====

void x86emuOp_imul_word_IMM(void)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  short *psVar8;
  uint uVar9;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_2c,&local_24,&local_28);
  if (local_2c == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar7 = (undefined2 *)decode_rm_word_register(local_24);
      uVar3 = decode_rm10_address(local_28);
      goto LAB_002868f8;
    }
    puVar5 = (undefined4 *)decode_rm_long_register();
    uVar3 = decode_rm10_address(local_28);
  }
  else {
    if (2 < local_2c) {
      if (local_2c == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar7 = (undefined2 *)decode_rm_word_register(local_24);
          psVar8 = (short *)decode_rm_word_register(local_28);
          sVar1 = fetch_word_imm();
          uVar9 = DAT_005483fc | 0x801;
          DAT_005483fc = DAT_005483fc & 0xfffff7fe;
          if (0xffff < (uint)((int)*psVar8 * (int)sVar1)) {
            DAT_005483fc = uVar9;
          }
          *puVar7 = (short)((int)*psVar8 * (int)sVar1);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar6 = (undefined4 *)decode_rm_long_register(local_28);
        uVar3 = fetch_long_imm();
        imul_long_direct(&local_20,&local_1c,*puVar6,uVar3);
        uVar9 = DAT_005483fc | 0x801;
        DAT_005483fc = DAT_005483fc & 0xfffff7fe;
        if (local_1c != 0) {
          DAT_005483fc = uVar9;
        }
        *puVar5 = local_20;
      }
LAB_00286827:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_2c == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar7 = (undefined2 *)decode_rm_word_register(local_24);
        uVar3 = decode_rm00_address(local_28);
LAB_002868f8:
        sVar1 = fetch_data_word(uVar3);
        sVar2 = fetch_word_imm();
        uVar9 = DAT_005483fc | 0x801;
        DAT_005483fc = DAT_005483fc & 0xfffff7fe;
        if (0xffff < (uint)((int)sVar1 * (int)sVar2)) {
          DAT_005483fc = uVar9;
        }
        *puVar7 = (short)((int)sVar1 * (int)sVar2);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar5 = (undefined4 *)decode_rm_long_register();
      uVar3 = decode_rm00_address(local_28);
    }
    else {
      if (local_2c != 1) goto LAB_00286827;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar7 = (undefined2 *)decode_rm_word_register(local_24);
        uVar3 = decode_rm01_address(local_28);
        goto LAB_002868f8;
      }
      puVar5 = (undefined4 *)decode_rm_long_register();
      uVar3 = decode_rm01_address(local_28);
    }
  }
  uVar3 = fetch_data_long(uVar3);
  uVar4 = fetch_long_imm();
  imul_long_direct(&local_20,&local_1c,uVar3,uVar4);
  uVar9 = DAT_005483fc | 0x801;
  DAT_005483fc = DAT_005483fc & 0xfffff7fe;
  if (local_1c != 0) {
    DAT_005483fc = uVar9;
  }
  *puVar5 = local_20;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002869e0 x86emuOp_aas =====

void x86emuOp_aas(void)

{
  DAT_005483d8 = aas_word(DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286a10 x86emuOp_aaa =====

void x86emuOp_aaa(void)

{
  DAT_005483d8 = aaa_word(DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286a40 x86emuOp_das =====

void x86emuOp_das(void)

{
  DAT_005483d8._0_1_ = das_byte((undefined1)DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286a70 x86emuOp_daa =====

void x86emuOp_daa(void)

{
  DAT_005483d8._0_1_ = daa_byte((undefined1)DAT_005483d8);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286aa0 x86emuOp_wait =====

void x86emuOp_wait(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286ab0 x86emuOp_lock =====

void x86emuOp_lock(void)

{
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286ac0 x86emuOp2_movsx_word_R_RM =====

void x86emuOp2_movsx_word_R_RM(void)

{
  short sVar1;
  undefined4 uVar2;
  int *piVar3;
  short *psVar4;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    piVar3 = (int *)decode_rm_long_register(local_1c[0]);
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        piVar3 = (int *)decode_rm_long_register(local_1c[0]);
        psVar4 = (short *)decode_rm_word_register(local_20);
        *piVar3 = (int)*psVar4;
      }
LAB_00286b4d:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      piVar3 = (int *)decode_rm_long_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00286b4d;
      piVar3 = (int *)decode_rm_long_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  sVar1 = fetch_data_word(uVar2);
  *piVar3 = (int)sVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286ba0 x86emuOp2_movzx_word_R_RM =====

void x86emuOp2_movzx_word_R_RM(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint *puVar3;
  ushort *puVar4;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    puVar3 = (uint *)decode_rm_long_register(local_1c[0]);
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        puVar3 = (uint *)decode_rm_long_register(local_1c[0]);
        puVar4 = (ushort *)decode_rm_word_register(local_20);
        *puVar3 = (uint)*puVar4;
      }
LAB_00286c35:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      puVar3 = (uint *)decode_rm_long_register(local_1c[0]);
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00286c35;
      puVar3 = (uint *)decode_rm_long_register(local_1c[0]);
      uVar2 = decode_rm01_address(local_20);
    }
  }
  uVar1 = fetch_data_word(uVar2);
  *puVar3 = (uint)uVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286c90 x86emuOp2_lgs_R_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp2_lgs_R_IMM(void)

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
    if (local_24 != 0) goto LAB_00286cf8;
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm00_address(local_1c[0]);
  }
  uVar1 = fetch_data_word(iVar2);
  *puVar3 = uVar1;
  _DAT_0054840a = fetch_data_word(iVar2 + 2);
LAB_00286cf8:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286d50 x86emuOp2_lfs_R_IMM =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp2_lfs_R_IMM(void)

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
    if (local_24 != 0) goto LAB_00286db8;
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm00_address(local_1c[0]);
  }
  uVar1 = fetch_data_word(iVar2);
  *puVar3 = uVar1;
  _DAT_00548408 = fetch_data_word(iVar2 + 2);
LAB_00286db8:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286e10 x86emuOp2_lss_R_IMM =====

void x86emuOp2_lss_R_IMM(void)

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
    if (local_24 != 0) goto LAB_00286e78;
    puVar3 = (undefined2 *)decode_rm_word_register(local_20);
    iVar2 = decode_rm00_address(local_1c[0]);
  }
  uVar1 = fetch_data_word(iVar2);
  *puVar3 = uVar1;
  DAT_00548404 = fetch_data_word(iVar2 + 2);
LAB_00286e78:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00286ed0 x86emuOp2_movsx_byte_R_RM =====

void x86emuOp2_movsx_byte_R_RM(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  short *psVar5;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      psVar5 = (short *)decode_rm_word_register(local_1c[0]);
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00286ff0;
    }
    piVar3 = (int *)decode_rm_long_register();
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          psVar5 = (short *)decode_rm_word_register(local_1c[0]);
          pcVar4 = (char *)decode_rm_byte_register(local_20);
          *psVar5 = (short)*pcVar4;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        piVar3 = (int *)decode_rm_long_register();
        pcVar4 = (char *)decode_rm_byte_register(local_20);
        *piVar3 = (int)*pcVar4;
      }
LAB_00286f64:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        psVar5 = (short *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
LAB_00286ff0:
        cVar1 = fetch_data_byte(uVar2);
        *psVar5 = (short)cVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      piVar3 = (int *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00286f64;
      if ((DAT_0054840c & 0x200) == 0) {
        psVar5 = (short *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00286ff0;
      }
      piVar3 = (int *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  cVar1 = fetch_data_byte(uVar2);
  *piVar3 = (int)cVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00287080 x86emuOp2_movzx_byte_R_RM =====

void x86emuOp2_movzx_byte_R_RM(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint *puVar3;
  byte *pbVar4;
  ushort *puVar5;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar5 = (ushort *)decode_rm_word_register(local_1c[0]);
      uVar2 = decode_rm10_address(local_20);
      goto LAB_002871a0;
    }
    puVar3 = (uint *)decode_rm_long_register();
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar5 = (ushort *)decode_rm_word_register(local_1c[0]);
          pbVar4 = (byte *)decode_rm_byte_register(local_20);
          *puVar5 = (ushort)*pbVar4;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar3 = (uint *)decode_rm_long_register();
        pbVar4 = (byte *)decode_rm_byte_register(local_20);
        *puVar3 = (uint)*pbVar4;
      }
LAB_00287114:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (ushort *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm00_address(local_20);
LAB_002871a0:
        bVar1 = fetch_data_byte(uVar2);
        *puVar5 = (ushort)bVar1;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      puVar3 = (uint *)decode_rm_long_register();
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00287114;
      if ((DAT_0054840c & 0x200) == 0) {
        puVar5 = (ushort *)decode_rm_word_register(local_1c[0]);
        uVar2 = decode_rm01_address(local_20);
        goto LAB_002871a0;
      }
      puVar3 = (uint *)decode_rm_long_register();
      uVar2 = decode_rm01_address(local_20);
    }
  }
  bVar1 = fetch_data_byte(uVar2);
  *puVar3 = (uint)bVar1;
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00287230 x86emuOp2_bsr =====

void x86emuOp2_bsr(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  short *psVar5;
  ushort *puVar6;
  uint uVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      psVar5 = (short *)decode_rm_word_register(local_1c[0]);
      uVar1 = fetch_data_word(uVar2);
      uVar3 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar1 == 0) {
        DAT_005483fc = uVar3;
      }
      *psVar5 = 0xf;
      uVar3 = 0xf;
      do {
        if ((uVar1 >> (uVar3 & 0x1f) & 1) != 0) break;
        *psVar5 = (short)uVar3 + -1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    else {
      uVar2 = decode_rm10_address(local_20);
      puVar4 = (uint *)decode_rm_long_register(local_1c[0]);
      uVar3 = fetch_data_long(uVar2);
      uVar7 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar3 == 0) {
        DAT_005483fc = uVar7;
      }
      uVar7 = 0x1f;
      *puVar4 = 0x1f;
      do {
        if ((uVar3 >> (uVar7 & 0x1f) & 1) != 0) break;
        uVar7 = uVar7 - 1;
        *puVar4 = uVar7;
      } while (uVar7 != 0);
    }
  }
  else if (local_24 < 3) {
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
        psVar5 = (short *)decode_rm_word_register(local_1c[0]);
        uVar1 = fetch_data_word(uVar2);
        uVar3 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar1 == 0) {
          DAT_005483fc = uVar3;
        }
        uVar3 = 0xf;
        *psVar5 = 0xf;
        do {
          if ((uVar1 >> (uVar3 & 0x1f) & 1) != 0) break;
          *psVar5 = (short)uVar3 + -1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      else {
        uVar2 = decode_rm00_address(local_20);
        puVar4 = (uint *)decode_rm_long_register(local_1c[0]);
        uVar3 = fetch_data_long(uVar2);
        uVar7 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar3 == 0) {
          DAT_005483fc = uVar7;
        }
        uVar7 = 0x1f;
        *puVar4 = 0x1f;
        do {
          if ((uVar3 >> (uVar7 & 0x1f) & 1) != 0) break;
          uVar7 = uVar7 - 1;
          *puVar4 = uVar7;
        } while (uVar7 != 0);
      }
    }
    else if (local_24 == 1) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        psVar5 = (short *)decode_rm_word_register(local_1c[0]);
        uVar1 = fetch_data_word(uVar2);
        uVar3 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar1 == 0) {
          DAT_005483fc = uVar3;
        }
        uVar3 = 0xf;
        *psVar5 = 0xf;
        do {
          if ((uVar1 >> (uVar3 & 0x1f) & 1) != 0) break;
          *psVar5 = (short)uVar3 + -1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      else {
        uVar2 = decode_rm01_address(local_20);
        puVar4 = (uint *)decode_rm_long_register(local_1c[0]);
        uVar3 = fetch_data_long(uVar2);
        uVar7 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar3 == 0) {
          DAT_005483fc = uVar7;
        }
        uVar7 = 0x1f;
        *puVar4 = 0x1f;
        do {
          if ((uVar3 >> (uVar7 & 0x1f) & 1) != 0) break;
          uVar7 = uVar7 - 1;
          *puVar4 = uVar7;
        } while (uVar7 != 0);
      }
    }
  }
  else if (local_24 == 3) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar6 = (ushort *)decode_rm_word_register(local_20);
      uVar1 = *puVar6;
      psVar5 = (short *)decode_rm_word_register(local_1c[0]);
      uVar3 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar1 == 0) {
        DAT_005483fc = uVar3;
      }
      *psVar5 = 0xf;
      uVar3 = 0xf;
      do {
        if ((uVar1 >> (uVar3 & 0x1f) & 1) != 0) break;
        *psVar5 = (short)uVar3 + -1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    else {
      puVar4 = (uint *)decode_rm_long_register();
      uVar3 = *puVar4;
      puVar4 = (uint *)decode_rm_long_register(local_1c[0]);
      uVar7 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar3 == 0) {
        DAT_005483fc = uVar7;
      }
      uVar7 = 0x1f;
      *puVar4 = 0x1f;
      do {
        if ((uVar3 >> (uVar7 & 0x1f) & 1) != 0) break;
        uVar7 = uVar7 - 1;
        *puVar4 = uVar7;
      } while (uVar7 != 0);
    }
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00287620 x86emuOp2_bsf =====

void x86emuOp2_bsf(void)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  short *psVar6;
  ushort *puVar7;
  uint uVar8;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_20);
      psVar6 = (short *)decode_rm_word_register(local_1c[0]);
      uVar2 = fetch_data_word(uVar3);
      uVar4 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar2 == 0) {
        DAT_005483fc = uVar4;
      }
      *psVar6 = 0;
      uVar4 = 0;
      do {
        if ((uVar2 >> (uVar4 & 0x1f) & 1) != 0) break;
        sVar1 = (short)uVar4;
        uVar4 = uVar4 + 1;
        *psVar6 = sVar1 + 1;
      } while (uVar4 != 0x10);
    }
    else {
      uVar3 = decode_rm10_address(local_20);
      puVar5 = (uint *)decode_rm_long_register(local_1c[0]);
      uVar4 = fetch_data_long(uVar3);
      uVar8 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar4 == 0) {
        DAT_005483fc = uVar8;
      }
      uVar8 = 0;
      *puVar5 = 0;
      do {
        if ((uVar4 >> (uVar8 & 0x1f) & 1) != 0) break;
        uVar8 = uVar8 + 1;
        *puVar5 = uVar8;
      } while (uVar8 != 0x20);
    }
  }
  else if (local_24 < 3) {
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
        psVar6 = (short *)decode_rm_word_register(local_1c[0]);
        uVar2 = fetch_data_word(uVar3);
        uVar4 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar2 == 0) {
          DAT_005483fc = uVar4;
        }
        *psVar6 = 0;
        uVar4 = 0;
        do {
          if ((uVar2 >> (uVar4 & 0x1f) & 1) != 0) break;
          sVar1 = (short)uVar4;
          uVar4 = uVar4 + 1;
          *psVar6 = sVar1 + 1;
        } while (uVar4 != 0x10);
      }
      else {
        uVar3 = decode_rm00_address(local_20);
        puVar5 = (uint *)decode_rm_long_register(local_1c[0]);
        uVar4 = fetch_data_long(uVar3);
        uVar8 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar4 == 0) {
          DAT_005483fc = uVar8;
        }
        uVar8 = 0;
        *puVar5 = 0;
        do {
          if ((uVar4 >> (uVar8 & 0x1f) & 1) != 0) break;
          uVar8 = uVar8 + 1;
          *puVar5 = uVar8;
        } while (uVar8 != 0x20);
      }
    }
    else if (local_24 == 1) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_20);
        psVar6 = (short *)decode_rm_word_register(local_1c[0]);
        uVar2 = fetch_data_word(uVar3);
        uVar4 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar2 == 0) {
          DAT_005483fc = uVar4;
        }
        *psVar6 = 0;
        uVar4 = 0;
        do {
          if ((uVar2 >> (uVar4 & 0x1f) & 1) != 0) break;
          sVar1 = (short)uVar4;
          uVar4 = uVar4 + 1;
          *psVar6 = sVar1 + 1;
        } while (uVar4 != 0x10);
      }
      else {
        uVar3 = decode_rm01_address(local_20);
        puVar5 = (uint *)decode_rm_long_register(local_1c[0]);
        uVar4 = fetch_data_long(uVar3);
        uVar8 = DAT_005483fc | 0x40;
        DAT_005483fc = DAT_005483fc & 0xffffffbf;
        if (uVar4 == 0) {
          DAT_005483fc = uVar8;
        }
        uVar8 = 0;
        *puVar5 = 0;
        do {
          if ((uVar4 >> (uVar8 & 0x1f) & 1) != 0) break;
          uVar8 = uVar8 + 1;
          *puVar5 = uVar8;
        } while (uVar8 != 0x20);
      }
    }
  }
  else if (local_24 == 3) {
    if ((DAT_0054840c & 0x200) == 0) {
      puVar7 = (ushort *)decode_rm_word_register(local_20);
      uVar2 = *puVar7;
      psVar6 = (short *)decode_rm_word_register(local_1c[0]);
      uVar4 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar2 == 0) {
        DAT_005483fc = uVar4;
      }
      *psVar6 = 0;
      uVar4 = 0;
      do {
        if ((uVar2 >> (uVar4 & 0x1f) & 1) != 0) break;
        sVar1 = (short)uVar4;
        uVar4 = uVar4 + 1;
        *psVar6 = sVar1 + 1;
      } while (uVar4 != 0x10);
    }
    else {
      puVar5 = (uint *)decode_rm_long_register();
      uVar4 = *puVar5;
      puVar5 = (uint *)decode_rm_long_register(local_1c[0]);
      uVar8 = DAT_005483fc | 0x40;
      DAT_005483fc = DAT_005483fc & 0xffffffbf;
      if (uVar4 == 0) {
        DAT_005483fc = uVar8;
      }
      uVar8 = 0;
      *puVar5 = 0;
      do {
        if ((uVar4 >> (uVar8 & 0x1f) & 1) != 0) break;
        uVar8 = uVar8 + 1;
        *puVar5 = uVar8;
      } while (uVar8 != 0x20);
    }
    DAT_0054840c = DAT_0054840c & 0xfffff980;
    return;
  }
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00287a60 x86emuOp2_bt_R =====

void x86emuOp2_bt_R(void)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      iVar4 = decode_rm10_address(local_20);
      goto LAB_00287bdd;
    }
    iVar4 = decode_rm10_address(local_20);
LAB_00287b81:
    puVar8 = (uint *)decode_rm_long_register(local_1c[0]);
    uVar5 = *puVar8;
    uVar6 = fetch_data_long((short)((short)uVar5 >> 5) + iVar4);
    uVar5 = uVar6 >> (uVar5 & 0x1f) & 1;
joined_r0x00287bae:
    if (uVar5 != 0) {
LAB_00287bb4:
      DAT_005483fc = DAT_005483fc | 1;
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
  }
  else {
    if (local_24 < 3) {
      if (local_24 == 0) {
        if ((DAT_0054840c & 0x200) == 0) {
          iVar4 = decode_rm00_address(local_20);
LAB_00287bdd:
          puVar9 = (ushort *)decode_rm_word_register(local_1c[0]);
          uVar1 = *puVar9;
          uVar3 = fetch_data_word(((short)uVar1 >> 4) + iVar4);
          if ((uVar3 >> (uVar1 & 0xf) & 1) != 0) {
            DAT_005483fc = DAT_005483fc | 1;
            DAT_0054840c = DAT_0054840c & 0xfffff980;
            return;
          }
          DAT_005483fc = DAT_005483fc & 0xfffffffe;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        iVar4 = decode_rm00_address(local_20);
        goto LAB_00287b81;
      }
      if (local_24 != 1) goto LAB_00287b00;
      if ((DAT_0054840c & 0x200) == 0) {
        iVar4 = decode_rm01_address(local_20);
        goto LAB_00287bdd;
      }
      iVar4 = decode_rm01_address(local_20);
      puVar7 = (undefined4 *)decode_rm_long_register(local_1c[0]);
      uVar2 = *puVar7;
      uVar5 = fetch_data_long((short)((short)uVar2 >> 5) + iVar4);
      uVar5 = 1 << ((byte)uVar2 & 0x1f) & uVar5;
      goto joined_r0x00287bae;
    }
    if (local_24 != 3) goto LAB_00287b00;
    if ((DAT_0054840c & 0x200) != 0) {
      puVar8 = (uint *)decode_rm_long_register();
      puVar7 = (undefined4 *)decode_rm_long_register(local_1c[0]);
      uVar5 = *puVar8 & 1 << ((byte)*puVar7 & 0x1f);
      goto joined_r0x00287bae;
    }
    puVar9 = (ushort *)decode_rm_word_register(local_20);
    puVar10 = (ushort *)decode_rm_word_register(local_1c[0]);
    if ((*puVar9 >> (*puVar10 & 0xf) & 1) != 0) goto LAB_00287bb4;
  }
  DAT_005483fc = DAT_005483fc & 0xfffffffe;
LAB_00287b00:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00287ca0 x86emuOp2_btc_R =====

void x86emuOp2_btc_R(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  short *psVar7;
  ushort *puVar8;
  undefined2 *puVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      iVar3 = decode_rm10_address(local_20);
LAB_00287e55:
      psVar7 = (short *)decode_rm_word_register(local_1c[0]);
      sVar1 = *psVar7;
      iVar3 = (sVar1 >> 4) + iVar3;
      uVar4 = fetch_data_word();
      uVar10 = 1 << ((byte)sVar1 & 0xf);
      uVar12 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((ushort)((ushort)uVar4 & (ushort)uVar10) != 0) {
        DAT_005483fc = uVar12;
      }
      uVar4 = uVar4 ^ uVar10;
LAB_00287ea3:
      store_data_word(iVar3,uVar4 & 0xffff);
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    iVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar8 = (ushort *)decode_rm_word_register(local_20);
          puVar9 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar4 = DAT_005483fc | 1;
          uVar11 = (ushort)(1 << ((byte)*puVar9 & 0xf));
          DAT_005483fc = DAT_005483fc & 0xfffffffe;
          if ((*puVar8 & uVar11) != 0) {
            DAT_005483fc = uVar4;
          }
          *puVar8 = *puVar8 ^ uVar11;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar6 = (uint *)decode_rm_long_register();
        puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar10 = 1 << ((byte)*puVar5 & 0x1f);
        uVar4 = DAT_005483fc | 1;
        DAT_005483fc = DAT_005483fc & 0xfffffffe;
        if ((*puVar6 & uVar10) != 0) {
          DAT_005483fc = uVar4;
        }
        *puVar6 = *puVar6 ^ uVar10;
      }
LAB_00287da1:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 != 0) {
      if (local_24 != 1) goto LAB_00287da1;
      if ((DAT_0054840c & 0x200) == 0) {
        iVar3 = decode_rm01_address(local_20);
        psVar7 = (short *)decode_rm_word_register(local_1c[0]);
        sVar1 = *psVar7;
        iVar3 = (sVar1 >> 4) + iVar3;
        uVar4 = fetch_data_word();
        uVar12 = 1 << ((byte)sVar1 & 0xf);
        uVar10 = DAT_005483fc | 1;
        DAT_005483fc = DAT_005483fc & 0xfffffffe;
        if ((ushort)((ushort)uVar4 & (ushort)uVar12) != 0) {
          DAT_005483fc = uVar10;
        }
        uVar4 = uVar4 ^ uVar12;
        goto LAB_00287ea3;
      }
      iVar3 = decode_rm01_address(local_20);
      puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
      uVar2 = *puVar5;
      iVar3 = (short)((short)uVar2 >> 5) + iVar3;
      uVar4 = fetch_data_long();
      uVar12 = 1 << ((byte)uVar2 & 0x1f);
      uVar10 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((uVar4 & uVar12) != 0) {
        DAT_005483fc = uVar10;
      }
      uVar4 = uVar4 ^ uVar12;
      goto LAB_00287e2a;
    }
    if ((DAT_0054840c & 0x200) == 0) {
      iVar3 = decode_rm00_address(local_20);
      goto LAB_00287e55;
    }
    iVar3 = decode_rm00_address(local_20);
  }
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar2 = *puVar5;
  iVar3 = (short)((short)uVar2 >> 5) + iVar3;
  uVar4 = fetch_data_long();
  uVar10 = 1 << ((byte)uVar2 & 0x1f);
  uVar12 = DAT_005483fc | 1;
  DAT_005483fc = DAT_005483fc & 0xfffffffe;
  if ((uVar4 & uVar10) != 0) {
    DAT_005483fc = uVar12;
  }
  uVar4 = uVar4 ^ uVar10;
LAB_00287e2a:
  store_data_long(iVar3,uVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00287fa0 x86emuOp2_btr_R =====

void x86emuOp2_btr_R(void)

{
  short sVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  short *psVar8;
  ushort *puVar9;
  undefined2 *puVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      iVar4 = decode_rm10_address(local_20);
LAB_00288135:
      psVar8 = (short *)decode_rm_word_register(local_1c[0]);
      sVar1 = *psVar8;
      iVar4 = (sVar1 >> 4) + iVar4;
      uVar5 = fetch_data_word();
      bVar11 = (byte)sVar1;
LAB_00288165:
      uVar13 = 1 << (bVar11 & 0xf);
      uVar12 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((ushort)((ushort)uVar5 & (ushort)uVar13) != 0) {
        DAT_005483fc = uVar12;
      }
      store_data_word(iVar4,~uVar13 & uVar5 & 0xffff);
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    iVar4 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar9 = (ushort *)decode_rm_word_register(local_20);
          puVar10 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar5 = DAT_005483fc | 1;
          uVar3 = (ushort)(1 << ((byte)*puVar10 & 0xf));
          DAT_005483fc = DAT_005483fc & 0xfffffffe;
          if ((*puVar9 & uVar3) != 0) {
            DAT_005483fc = uVar5;
          }
          *puVar9 = *puVar9 & ~uVar3;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar7 = (uint *)decode_rm_long_register();
        puVar6 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar5 = 1 << ((byte)*puVar6 & 0x1f);
        uVar12 = DAT_005483fc | 1;
        DAT_005483fc = DAT_005483fc & 0xfffffffe;
        if ((*puVar7 & uVar5) != 0) {
          DAT_005483fc = uVar12;
        }
        *puVar7 = *puVar7 & ~uVar5;
      }
LAB_00288082:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 != 0) {
      if (local_24 != 1) goto LAB_00288082;
      if ((DAT_0054840c & 0x200) == 0) {
        iVar4 = decode_rm01_address(local_20);
        psVar8 = (short *)decode_rm_word_register(local_1c[0]);
        sVar1 = *psVar8;
        iVar4 = (sVar1 >> 4) + iVar4;
        uVar5 = fetch_data_word();
        bVar11 = (byte)sVar1;
        goto LAB_00288165;
      }
      iVar4 = decode_rm01_address(local_20);
      puVar6 = (undefined4 *)decode_rm_long_register(local_1c[0]);
      uVar2 = *puVar6;
      iVar4 = (short)((short)uVar2 >> 5) + iVar4;
      uVar5 = fetch_data_long();
      bVar11 = (byte)uVar2;
      goto LAB_002880ed;
    }
    if ((DAT_0054840c & 0x200) == 0) {
      iVar4 = decode_rm00_address(local_20);
      goto LAB_00288135;
    }
    iVar4 = decode_rm00_address(local_20);
  }
  puVar6 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar2 = *puVar6;
  iVar4 = (short)((short)uVar2 >> 5) + iVar4;
  uVar5 = fetch_data_long();
  bVar11 = (byte)uVar2;
LAB_002880ed:
  uVar13 = 1 << (bVar11 & 0x1f);
  uVar12 = DAT_005483fc | 1;
  DAT_005483fc = DAT_005483fc & 0xfffffffe;
  if ((uVar5 & uVar13) != 0) {
    DAT_005483fc = uVar12;
  }
  store_data_long(iVar4,~uVar13 & uVar5);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00288260 x86emuOp2_bts_R =====

void x86emuOp2_bts_R(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  short *psVar7;
  ushort *puVar8;
  undefined2 *puVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      iVar3 = decode_rm10_address(local_20);
LAB_00288415:
      psVar7 = (short *)decode_rm_word_register(local_1c[0]);
      sVar1 = *psVar7;
      iVar3 = (sVar1 >> 4) + iVar3;
      uVar4 = fetch_data_word();
      uVar10 = 1 << ((byte)sVar1 & 0xf);
      uVar12 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((ushort)((ushort)uVar4 & (ushort)uVar10) != 0) {
        DAT_005483fc = uVar12;
      }
      uVar4 = uVar4 | uVar10;
LAB_00288463:
      store_data_word(iVar3,uVar4 & 0xffff);
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    iVar3 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar8 = (ushort *)decode_rm_word_register(local_20);
          puVar9 = (undefined2 *)decode_rm_word_register(local_1c[0]);
          uVar4 = DAT_005483fc | 1;
          uVar11 = (ushort)(1 << ((byte)*puVar9 & 0xf));
          DAT_005483fc = DAT_005483fc & 0xfffffffe;
          if ((*puVar8 & uVar11) != 0) {
            DAT_005483fc = uVar4;
          }
          *puVar8 = *puVar8 | uVar11;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar6 = (uint *)decode_rm_long_register();
        puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
        uVar10 = 1 << ((byte)*puVar5 & 0x1f);
        uVar4 = DAT_005483fc | 1;
        DAT_005483fc = DAT_005483fc & 0xfffffffe;
        if ((*puVar6 & uVar10) != 0) {
          DAT_005483fc = uVar4;
        }
        *puVar6 = *puVar6 | uVar10;
      }
LAB_00288361:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 != 0) {
      if (local_24 != 1) goto LAB_00288361;
      if ((DAT_0054840c & 0x200) == 0) {
        iVar3 = decode_rm01_address(local_20);
        psVar7 = (short *)decode_rm_word_register(local_1c[0]);
        sVar1 = *psVar7;
        iVar3 = (sVar1 >> 4) + iVar3;
        uVar4 = fetch_data_word();
        uVar12 = 1 << ((byte)sVar1 & 0xf);
        uVar10 = DAT_005483fc | 1;
        DAT_005483fc = DAT_005483fc & 0xfffffffe;
        if ((ushort)((ushort)uVar4 & (ushort)uVar12) != 0) {
          DAT_005483fc = uVar10;
        }
        uVar4 = uVar4 | uVar12;
        goto LAB_00288463;
      }
      iVar3 = decode_rm01_address(local_20);
      puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
      uVar2 = *puVar5;
      iVar3 = (short)((short)uVar2 >> 5) + iVar3;
      uVar4 = fetch_data_long();
      uVar12 = 1 << ((byte)uVar2 & 0x1f);
      uVar10 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((uVar4 & uVar12) != 0) {
        DAT_005483fc = uVar10;
      }
      uVar4 = uVar4 | uVar12;
      goto LAB_002883ea;
    }
    if ((DAT_0054840c & 0x200) == 0) {
      iVar3 = decode_rm00_address(local_20);
      goto LAB_00288415;
    }
    iVar3 = decode_rm00_address(local_20);
  }
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c[0]);
  uVar2 = *puVar5;
  iVar3 = (short)((short)uVar2 >> 5) + iVar3;
  uVar4 = fetch_data_long();
  uVar10 = 1 << ((byte)uVar2 & 0x1f);
  uVar12 = DAT_005483fc | 1;
  DAT_005483fc = DAT_005483fc & 0xfffffffe;
  if ((uVar4 & uVar10) != 0) {
    DAT_005483fc = uVar12;
  }
  uVar4 = uVar4 | uVar10;
LAB_002883ea:
  store_data_long(iVar3,uVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00288560 x86emuOp2_illegal_op =====

void x86emuOp2_illegal_op(void)

{
  X86EMU_halt_sys();
  return;
}


// ===== 00288570 x86emuOp2_btX_I =====

void x86emuOp2_btX_I(void)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  ushort *puVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_1c - 4U < 4) {
    iVar1 = local_24 + -2;
    bVar10 = local_24 == 2;
    if (!bVar10) goto LAB_002885ae;
LAB_002886cf:
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_20);
LAB_00288785:
      bVar2 = fetch_byte_imm();
      uVar8 = fetch_data_word(uVar3);
      uVar4 = 1 << (bVar2 & 0xf);
      uVar9 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((ushort)((ushort)uVar8 & (ushort)uVar4) != 0) {
        DAT_005483fc = uVar9;
      }
      if (local_1c == 6) {
        uVar8 = ~uVar4 & uVar8;
LAB_002888f4:
        store_data_word(uVar3,uVar8 & 0xffff);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      if (local_1c == 7) {
        uVar8 = uVar8 ^ uVar4;
LAB_002887df:
        store_data_word(uVar3,uVar8 & 0xffff);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar8 = uVar8 | uVar4;
      if (local_1c == 5) goto LAB_002887df;
      goto LAB_00288869;
    }
    uVar3 = decode_rm10_address(local_20);
LAB_002886e8:
    bVar2 = fetch_byte_imm();
    uVar8 = fetch_data_long(uVar3);
    uVar4 = 1 << (bVar2 & 0x1f);
    uVar9 = DAT_005483fc | 1;
    DAT_005483fc = DAT_005483fc & 0xfffffffe;
    if ((uVar8 & uVar4) != 0) {
      DAT_005483fc = uVar9;
    }
    if (local_1c != 6) {
      if (local_1c == 7) {
        store_data_long(uVar3,uVar8 ^ uVar4);
      }
      else {
        if (local_1c != 5) {
LAB_00288869:
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        store_data_long(uVar3,uVar8 | uVar4);
      }
      goto LAB_00288640;
    }
    uVar4 = ~uVar4;
  }
  else {
    X86EMU_halt_sys();
    iVar1 = local_24 + -2;
    bVar10 = false;
    if (iVar1 == 0) goto LAB_002886cf;
LAB_002885ae:
    if (!bVar10 && SBORROW4(local_24,2) == iVar1 < 0) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (ushort *)decode_rm_word_register(local_20);
          bVar2 = fetch_byte_imm();
          uVar4 = DAT_005483fc | 1;
          uVar7 = (ushort)(1 << (bVar2 & 0xf));
          DAT_005483fc = DAT_005483fc & 0xfffffffe;
          if ((*puVar6 & uVar7) != 0) {
            DAT_005483fc = uVar4;
          }
          if (local_1c == 6) {
            *puVar6 = *puVar6 & ~uVar7;
          }
          else if (local_1c == 7) {
            *puVar6 = *puVar6 ^ uVar7;
          }
          else if (local_1c == 5) {
            *puVar6 = *puVar6 | uVar7;
          }
        }
        else {
          puVar5 = (uint *)decode_rm_long_register();
          bVar2 = fetch_byte_imm();
          uVar8 = 1 << (bVar2 & 0x1f);
          uVar4 = DAT_005483fc | 1;
          DAT_005483fc = DAT_005483fc & 0xfffffffe;
          if ((*puVar5 & uVar8) != 0) {
            DAT_005483fc = uVar4;
          }
          if (local_1c == 6) {
            *puVar5 = *puVar5 & ~uVar8;
          }
          else if (local_1c == 7) {
            *puVar5 = *puVar5 ^ uVar8;
          }
          else if (local_1c == 5) {
            *puVar5 = *puVar5 | uVar8;
          }
        }
      }
      goto LAB_00288640;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_20);
        goto LAB_00288785;
      }
      uVar3 = decode_rm00_address(local_20);
      goto LAB_002886e8;
    }
    if (local_24 != 1) goto LAB_00288640;
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm01_address(local_20);
      bVar2 = fetch_byte_imm();
      uVar8 = fetch_data_word(uVar3);
      uVar4 = 1 << (bVar2 & 0xf);
      uVar9 = DAT_005483fc | 1;
      DAT_005483fc = DAT_005483fc & 0xfffffffe;
      if ((ushort)((ushort)uVar8 & (ushort)uVar4) != 0) {
        DAT_005483fc = uVar9;
      }
      if (local_1c == 6) {
        store_data_word(uVar3,(short)(~uVar4 & uVar8),~uVar4 & uVar8);
        goto LAB_00288640;
      }
      if (local_1c == 7) {
        uVar8 = uVar8 ^ uVar4;
      }
      else {
        if (local_1c != 5) goto LAB_00288869;
        uVar8 = uVar8 | uVar4;
      }
      goto LAB_002888f4;
    }
    uVar3 = decode_rm01_address(local_20);
    bVar2 = fetch_byte_imm();
    uVar4 = fetch_data_long(uVar3);
    uVar8 = 1 << (bVar2 & 0x1f);
    uVar9 = DAT_005483fc | 1;
    DAT_005483fc = DAT_005483fc & 0xfffffffe;
    if ((uVar4 & uVar8) != 0) {
      DAT_005483fc = uVar9;
    }
    if (local_1c != 6) {
      if (local_1c == 7) {
        uVar4 = uVar4 ^ uVar8;
      }
      else {
        uVar4 = uVar4 | uVar8;
        if (local_1c != 5) goto LAB_00288869;
      }
      store_data_long(uVar3,uVar4);
      goto LAB_00288640;
    }
    uVar8 = ~uVar8;
  }
  store_data_long(uVar3,uVar8 & uVar4);
LAB_00288640:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002889d0 x86emuOp2_imul_R_RM =====

void x86emuOp2_imul_R_RM(void)

{
  short sVar1;
  undefined4 uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  short *psVar7;
  uint uVar8;
  short *local_40;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c [3];
  
  fetch_decode_modrm(&local_2c,&local_24,&local_28);
  if (local_2c == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      local_40 = (short *)decode_rm_word_register(local_24);
      uVar4 = decode_rm10_address(local_28);
      goto LAB_00288b21;
    }
    puVar5 = (undefined4 *)decode_rm_long_register();
    uVar4 = decode_rm10_address(local_28);
LAB_00288a90:
    uVar4 = fetch_data_long(uVar4);
    uVar2 = *puVar5;
  }
  else {
    if (local_2c < 3) {
      if (local_2c == 0) {
        if ((DAT_0054840c & 0x200) == 0) {
          local_40 = (short *)decode_rm_word_register(local_24);
          uVar4 = decode_rm00_address(local_28);
LAB_00288b21:
          sVar3 = fetch_data_word(uVar4);
          sVar1 = *local_40;
LAB_00288b30:
          uVar8 = DAT_005483fc | 0x801;
          DAT_005483fc = DAT_005483fc & 0xfffff7fe;
          if (0xffff < (uint)((int)sVar1 * (int)sVar3)) {
            DAT_005483fc = uVar8;
          }
          *local_40 = (short)((int)sVar1 * (int)sVar3);
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        uVar4 = decode_rm00_address(local_28);
      }
      else {
        if (local_2c != 1) goto LAB_00288ad8;
        if ((DAT_0054840c & 0x200) == 0) {
          local_40 = (short *)decode_rm_word_register(local_24);
          uVar4 = decode_rm01_address(local_28);
          goto LAB_00288b21;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        uVar4 = decode_rm01_address(local_28);
      }
      goto LAB_00288a90;
    }
    if (local_2c != 3) goto LAB_00288ad8;
    if ((DAT_0054840c & 0x200) == 0) {
      local_40 = (short *)decode_rm_word_register(local_24);
      psVar7 = (short *)decode_rm_word_register(local_28);
      sVar3 = *psVar7;
      sVar1 = *local_40;
      goto LAB_00288b30;
    }
    puVar5 = (undefined4 *)decode_rm_long_register();
    puVar6 = (undefined4 *)decode_rm_long_register(local_28);
    uVar2 = *puVar5;
    uVar4 = *puVar6;
  }
  imul_long_direct(&local_20,local_1c,uVar2,uVar4);
  uVar8 = DAT_005483fc | 0x801;
  DAT_005483fc = DAT_005483fc & 0xfffff7fe;
  if (local_1c[0] != 0) {
    DAT_005483fc = uVar8;
  }
  *puVar5 = local_20;
LAB_00288ad8:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00288bc0 x86emuOp2_shrd_CL =====

void x86emuOp2_shrd_CL(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00288cf5;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c);
          uVar1 = shrd_word(*puVar6,*puVar7,(undefined1)DAT_005483e0);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c);
        uVar2 = shrd_long(*puVar5,*puVar4,(undefined1)DAT_005483e0);
        *puVar5 = uVar2;
      }
LAB_00288c61:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00288cf5:
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c);
        uVar1 = fetch_data_word(uVar2);
        uVar1 = shrd_word(uVar1,*puVar6,(undefined1)DAT_005483e0);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00288c61;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00288cf5;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c);
  uVar3 = fetch_data_long(uVar2);
  uVar3 = shrd_long(uVar3,*puVar5,(undefined1)DAT_005483e0);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00288da0 x86emuOp2_shrd_IMM =====

void x86emuOp2_shrd_IMM(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  fetch_decode_modrm(&local_34,local_2c,&local_30);
  if (local_34 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_30);
      goto LAB_00288ef5;
    }
    uVar3 = decode_rm10_address(local_30);
  }
  else {
    if (2 < local_34) {
      if (local_34 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar7 = (undefined2 *)decode_rm_word_register(local_30);
          puVar8 = (undefined2 *)decode_rm_word_register(local_2c[0]);
          uVar1 = fetch_byte_imm();
          uVar2 = shrd_word(*puVar7,*puVar8,uVar1);
          *puVar7 = uVar2;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar6 = (undefined4 *)decode_rm_long_register();
        puVar5 = (undefined4 *)decode_rm_long_register(local_2c[0]);
        uVar1 = fetch_byte_imm();
        uVar3 = shrd_long(*puVar6,*puVar5,uVar1);
        *puVar6 = uVar3;
      }
LAB_00288e4e:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_34 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_30);
LAB_00288ef5:
        puVar7 = (undefined2 *)decode_rm_word_register(local_2c[0]);
        uVar1 = fetch_byte_imm();
        uVar2 = fetch_data_word(uVar3);
        uVar2 = shrd_word(uVar2,*puVar7,uVar1);
        store_data_word(uVar3,uVar2);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar3 = decode_rm00_address(local_30);
    }
    else {
      if (local_34 != 1) goto LAB_00288e4e;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_30);
        goto LAB_00288ef5;
      }
      uVar3 = decode_rm01_address(local_30);
    }
  }
  puVar6 = (undefined4 *)decode_rm_long_register(local_2c[0]);
  uVar1 = fetch_byte_imm();
  uVar4 = fetch_data_long(uVar3);
  uVar4 = shrd_long(uVar4,*puVar6,uVar1);
  store_data_long(uVar3,uVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00288fc0 x86emuOp2_pop_GS =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp2_pop_GS(void)

{
  _DAT_0054840a = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00288fe0 x86emuOp2_pop_FS =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp2_pop_FS(void)

{
  _DAT_00548408 = pop_word();
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00289000 x86emuOp2_push_GS =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp2_push_GS(void)

{
  push_word(_DAT_0054840a);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00289020 x86emuOp2_push_FS =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x86emuOp2_push_FS(void)

{
  push_word(_DAT_00548408);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00289040 x86emuOp2_shld_CL =====

void x86emuOp2_shld_CL(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  fetch_decode_modrm(&local_24,&local_1c,&local_20);
  if (local_24 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar2 = decode_rm10_address(local_20);
      goto LAB_00289175;
    }
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar6 = (undefined2 *)decode_rm_word_register(local_20);
          puVar7 = (undefined2 *)decode_rm_word_register(local_1c);
          uVar1 = shld_word(*puVar6,*puVar7,(undefined1)DAT_005483e0);
          *puVar6 = uVar1;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar5 = (undefined4 *)decode_rm_long_register();
        puVar4 = (undefined4 *)decode_rm_long_register(local_1c);
        uVar2 = shld_long(*puVar5,*puVar4,(undefined1)DAT_005483e0);
        *puVar5 = uVar2;
      }
LAB_002890e1:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_24 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm00_address(local_20);
LAB_00289175:
        puVar6 = (undefined2 *)decode_rm_word_register(local_1c);
        uVar1 = fetch_data_word(uVar2);
        uVar1 = shld_word(uVar1,*puVar6,(undefined1)DAT_005483e0);
        store_data_word(uVar2,uVar1);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_002890e1;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar2 = decode_rm01_address(local_20);
        goto LAB_00289175;
      }
      uVar2 = decode_rm01_address(local_20);
    }
  }
  puVar5 = (undefined4 *)decode_rm_long_register(local_1c);
  uVar3 = fetch_data_long(uVar2);
  uVar3 = shld_long(uVar3,*puVar5,(undefined1)DAT_005483e0);
  store_data_long(uVar2,uVar3);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00289220 x86emuOp2_shld_IMM =====

void x86emuOp2_shld_IMM(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  fetch_decode_modrm(&local_34,local_2c,&local_30);
  if (local_34 == 2) {
    if ((DAT_0054840c & 0x200) == 0) {
      uVar3 = decode_rm10_address(local_30);
      goto LAB_00289375;
    }
    uVar3 = decode_rm10_address(local_30);
  }
  else {
    if (2 < local_34) {
      if (local_34 == 3) {
        if ((DAT_0054840c & 0x200) == 0) {
          puVar7 = (undefined2 *)decode_rm_word_register(local_30);
          puVar8 = (undefined2 *)decode_rm_word_register(local_2c[0]);
          uVar1 = fetch_byte_imm();
          uVar2 = shld_word(*puVar7,*puVar8,uVar1);
          *puVar7 = uVar2;
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
        puVar6 = (undefined4 *)decode_rm_long_register();
        puVar5 = (undefined4 *)decode_rm_long_register(local_2c[0]);
        uVar1 = fetch_byte_imm();
        uVar3 = shld_long(*puVar6,*puVar5,uVar1);
        *puVar6 = uVar3;
      }
LAB_002892ce:
      DAT_0054840c = DAT_0054840c & 0xfffff980;
      return;
    }
    if (local_34 == 0) {
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm00_address(local_30);
LAB_00289375:
        puVar7 = (undefined2 *)decode_rm_word_register(local_2c[0]);
        uVar1 = fetch_byte_imm();
        uVar2 = fetch_data_word(uVar3);
        uVar2 = shld_word(uVar2,*puVar7,uVar1);
        store_data_word(uVar3,uVar2);
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      uVar3 = decode_rm00_address(local_30);
    }
    else {
      if (local_34 != 1) goto LAB_002892ce;
      if ((DAT_0054840c & 0x200) == 0) {
        uVar3 = decode_rm01_address(local_30);
        goto LAB_00289375;
      }
      uVar3 = decode_rm01_address(local_30);
    }
  }
  puVar6 = (undefined4 *)decode_rm_long_register(local_2c[0]);
  uVar1 = fetch_byte_imm();
  uVar4 = fetch_data_long(uVar3);
  uVar4 = shld_long(uVar4,*puVar6,uVar1);
  store_data_long(uVar3,uVar4);
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00289440 x86emuOp2_set_byte =====

void x86emuOp2_set_byte(byte param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int local_24;
  undefined4 local_20;
  undefined1 local_1c [12];
  
  if (param_1 == 0x98) {
    uVar4 = DAT_005483fc & 0x80;
  }
  else if (param_1 < 0x99) {
    if (param_1 == 0x94) {
      uVar4 = DAT_005483fc & 0x40;
    }
    else if (param_1 < 0x95) {
      if (param_1 == 0x92) {
        uVar4 = DAT_005483fc & 1;
      }
      else if (param_1 == 0x93) {
        uVar4 = ~DAT_005483fc & 1;
      }
      else if (param_1 == 0x90) {
        uVar4 = DAT_005483fc & 0x800;
      }
      else {
        if (param_1 != 0x91) goto LAB_00289705;
        uVar4 = (DAT_005483fc >> 8 & 0xff) >> 3 & 1 ^ 1;
      }
    }
    else if (param_1 == 0x96) {
      uVar4 = (uint)((DAT_005483fc & 0x41) != 0);
    }
    else if (param_1 == 0x97) {
      uVar4 = (uint)((DAT_005483fc & 0x41) == 0);
    }
    else {
      uVar4 = (DAT_005483fc & 0xff) >> 6 & 1 ^ 1;
    }
  }
  else if (param_1 == 0x9c) {
LAB_002894d2:
    uVar1 = (DAT_005483fc & 0x800) >> 0xb;
    uVar4 = uVar1 ^ 1;
    if ((DAT_005483fc & 0x80) == 0) {
      uVar4 = uVar1;
    }
  }
  else if (param_1 < 0x9d) {
    if (param_1 == 0x9a) {
      uVar4 = DAT_005483fc & 4;
    }
    else if (param_1 == 0x9b) {
      uVar4 = (DAT_005483fc & 0xff) >> 2 & 1 ^ 1;
    }
    else {
      uVar4 = (DAT_005483fc & 0xff) >> 7 ^ 1;
    }
  }
  else if (param_1 == 0x9e) {
    if ((DAT_005483fc & 0x80) == 0) {
      if ((DAT_005483fc & 0x800) == 0) goto LAB_002896f5;
    }
    else if ((DAT_005483fc & 0x800) != 0) {
LAB_002896f5:
      uVar4 = DAT_005483fc >> 6 & 1;
      goto LAB_002894f0;
    }
    uVar4 = 1;
  }
  else {
    if (param_1 == 0x9f) {
      if ((DAT_005483fc & 0x80) == 0) {
        if ((DAT_005483fc & 0x800) == 0) goto LAB_00289690;
      }
      else if ((DAT_005483fc & 0x800) != 0) {
LAB_00289690:
        uVar4 = DAT_005483fc >> 6 & 1 ^ 1;
        goto LAB_002894f0;
      }
    }
    else if (param_1 == 0x9d) goto LAB_002894d2;
LAB_00289705:
    uVar4 = 0;
  }
LAB_002894f0:
  fetch_decode_modrm(&local_24,local_1c,&local_20);
  if (local_24 == 2) {
    uVar2 = decode_rm10_address(local_20);
  }
  else {
    if (2 < local_24) {
      if (local_24 == 3) {
        uVar3 = decode_rm_byte_register(local_20);
        *(bool *)uVar3 = uVar4 != 0;
        DAT_0054840c = DAT_0054840c & 0xfffff980;
        return;
      }
      goto LAB_00289537;
    }
    if (local_24 == 0) {
      uVar2 = decode_rm00_address(local_20);
    }
    else {
      if (local_24 != 1) goto LAB_00289537;
      uVar2 = decode_rm01_address(local_20);
    }
  }
  store_data_byte(uVar2,uVar4 != 0);
LAB_00289537:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 00289710 x86emuOp2_long_jump =====

void x86emuOp2_long_jump(byte param_1)

{
  short sVar1;
  uint uVar2;
  
  if (param_1 == 0x88) {
    uVar2 = DAT_005483fc & 0x80;
  }
  else {
    if (0x88 < param_1) {
      if (param_1 == 0x8c) {
        if ((DAT_005483fc & 0x80) != 0) {
          uVar2 = DAT_005483fc & 0x800;
joined_r0x002898e1:
          if (uVar2 != 0) goto LAB_00289849;
          goto LAB_0028980c;
        }
        uVar2 = DAT_005483fc & 0x800;
joined_r0x00289909:
        if (uVar2 == 0) {
LAB_00289849:
          fetch_word_imm();
          DAT_0054840c = DAT_0054840c & 0xfffff980;
          return;
        }
      }
      else {
        if (param_1 < 0x8d) {
          if (param_1 == 0x8a) {
            uVar2 = DAT_005483fc & 4;
          }
          else if (param_1 == 0x8b) {
            uVar2 = (DAT_005483fc & 0xff) >> 2 & 1 ^ 1;
          }
          else {
            uVar2 = (DAT_005483fc & 0xff) >> 7 ^ 1;
          }
          goto LAB_002897b0;
        }
        if (param_1 == 0x8e) {
          if ((DAT_005483fc & 0x80) == 0) {
            if ((DAT_005483fc & 0x800) == 0) goto LAB_00289907;
          }
          else if ((DAT_005483fc & 0x800) != 0) {
LAB_00289907:
            uVar2 = DAT_005483fc & 0x40;
            goto joined_r0x00289909;
          }
        }
        else {
          if (param_1 == 0x8f) {
            if ((DAT_005483fc & 0x80) == 0) {
              if ((DAT_005483fc & 0x800) != 0) goto LAB_00289849;
            }
            else if ((DAT_005483fc & 0x800) == 0) goto LAB_00289849;
            uVar2 = DAT_005483fc & 0x40;
            goto joined_r0x002898e1;
          }
          if ((param_1 != 0x8d) || ((DAT_005483fc & 0x880) == 0x80)) goto LAB_00289849;
        }
      }
LAB_0028980c:
      sVar1 = fetch_word_imm();
      DAT_005483f8 = DAT_005483f8 + sVar1;
      goto LAB_002897cc;
    }
    if (param_1 == 0x84) {
      uVar2 = DAT_005483fc & 0x40;
    }
    else if (param_1 < 0x85) {
      if (param_1 == 0x82) {
        uVar2 = DAT_005483fc & 1;
      }
      else if (param_1 == 0x83) {
        uVar2 = ~DAT_005483fc & 1;
      }
      else if (param_1 == 0x80) {
        uVar2 = DAT_005483fc & 0x800;
      }
      else {
        if (param_1 != 0x81) goto LAB_00289849;
        uVar2 = (DAT_005483fc >> 8 & 0xff) >> 3 & 1 ^ 1;
      }
    }
    else {
      if (param_1 == 0x86) {
        uVar2 = DAT_005483fc & 0x41;
        goto joined_r0x00289909;
      }
      if (param_1 == 0x87) {
        uVar2 = DAT_005483fc & 0x41;
        goto joined_r0x002898e1;
      }
      uVar2 = (DAT_005483fc & 0xff) >> 6 & 1 ^ 1;
    }
  }
LAB_002897b0:
  sVar1 = fetch_word_imm();
  if (uVar2 != 0) {
    DAT_005483f8 = DAT_005483f8 + sVar1;
  }
LAB_002897cc:
  DAT_0054840c = DAT_0054840c & 0xfffff980;
  return;
}


// ===== 002899c0 aaa_word =====

ulong aaa_word(ulong param_1)

{
  uint uVar1;
  ulong uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1;
  if ((((ushort)param_1 & 0xf) < 10) &&
     (uVar1 = DAT_005483fc & 0xffffffee, (DAT_005483fc & 0x10) == 0)) {
    uVar2 = param_1 & 0xffffff0f;
    if ((param_1 & 0xff0f) != 0) {
LAB_00289a13:
      if ((0x96696996U >> (uVar4 & 0xf) & 1) != 0) {
        DAT_005483fc = uVar1 & 0xffffff3b;
        return uVar2;
      }
      uVar1 = uVar1 & 0xffffff3f;
      goto LAB_002899ed;
    }
  }
  else {
    uVar3 = (ushort)param_1 + 0x106;
    uVar2 = CONCAT62((int6)(param_1 >> 0x10),uVar3);
    uVar4 = (uint)uVar2;
    uVar1 = DAT_005483fc | 0x11;
    uVar2 = uVar2 & 0xffffff0f;
    if ((uVar3 & 0xff0f) != 0) goto LAB_00289a13;
  }
  uVar1 = uVar1 & 0xffffff7f | 0x40;
LAB_002899ed:
  DAT_005483fc = uVar1 | 4;
  return uVar2;
}


// ===== 00289a30 aas_word =====

ulong aas_word(ulong param_1)

{
  uint uVar1;
  ulong uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1;
  if ((((ushort)param_1 & 0xf) < 10) &&
     (uVar1 = DAT_005483fc & 0xffffffee, (DAT_005483fc & 0x10) == 0)) {
    uVar2 = param_1 & 0xffffff0f;
    if ((param_1 & 0xff0f) != 0) {
LAB_00289a83:
      if ((0x96696996U >> (uVar4 & 0xf) & 1) != 0) {
        DAT_005483fc = uVar1 & 0xffffff3b;
        return uVar2;
      }
      uVar1 = uVar1 & 0xffffff3f;
      goto LAB_00289a5d;
    }
  }
  else {
    uVar3 = (ushort)param_1 - 0x106;
    uVar2 = CONCAT62((int6)(param_1 >> 0x10),uVar3);
    uVar4 = (uint)uVar2;
    uVar1 = DAT_005483fc | 0x11;
    uVar2 = uVar2 & 0xffffff0f;
    if ((uVar3 & 0xff0f) != 0) goto LAB_00289a83;
  }
  uVar1 = uVar1 & 0xffffff7f | 0x40;
LAB_00289a5d:
  DAT_005483fc = uVar1 | 4;
  return uVar2;
}


// ===== 00289aa0 aad_word =====

byte aad_word(uint param_1)

{
  uint uVar1;
  byte bVar2;
  
  param_1 = param_1 + (param_1 >> 8 & 0xff) * 10;
  bVar2 = (byte)param_1;
  if ((param_1 & 0x80) == 0) {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (bVar2 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_00289ac8;
    }
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_00289ac8:
  DAT_005483fc = uVar1 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(bVar2 >> 5) * 4) >> (param_1 & 0x1f) & 1) == 0) {
    DAT_005483fc = uVar1 | 4;
  }
  return bVar2;
}


// ===== 00289b10 aam_word =====

void aam_word(ushort param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = (param_1 & 0xff) / 10;
  uVar1 = uVar1 << 8 | param_1 + uVar1 * -10 & 0xff;
  if (uVar1 == 0) {
    uVar2 = DAT_005483fc & 0xfffff76e | 0x40;
  }
  else {
    if ((0x96696996U >> (uVar1 & 0x1f) & 1) != 0) {
      DAT_005483fc = DAT_005483fc & 0xfffff72a;
      return;
    }
    uVar2 = DAT_005483fc & 0xfffff72e;
  }
  DAT_005483fc = uVar2 | 4;
  return;
}


// ===== 00289b70 adc_byte =====

void adc_byte(byte param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((DAT_005483fc & 1) == 0) {
    uVar2 = (uint)param_1 + (uint)param_2;
    uVar3 = DAT_005483fc & 0xfffffffe;
    if ((char)(uVar2 >> 8) != '\0') goto LAB_00289b98;
LAB_00289b9d:
    if ((char)uVar2 != '\0') goto LAB_00289c25;
    uVar3 = uVar3 | 0x40;
  }
  else {
    uVar2 = param_1 + 1 + (uint)param_2;
    if ((uVar2 & 0x100) != 0) {
LAB_00289b98:
      uVar3 = DAT_005483fc | 1;
      goto LAB_00289b9d;
    }
    uVar3 = DAT_005483fc & 0xfffffffe;
LAB_00289c25:
    uVar3 = uVar3 & 0xffffffbf;
    if ((uVar2 & 0x80) != 0) {
      uVar3 = uVar3 | 0x80;
      goto LAB_00289bab;
    }
  }
  uVar3 = uVar3 & 0xffffff7f;
LAB_00289bab:
  uVar1 = uVar3 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar2 >> 5 & 7) * 4) >> (uVar2 & 0x1f) & 1) == 0) {
    uVar1 = uVar3 | 4;
  }
  uVar3 = ~uVar2 & (uint)(param_1 | param_2) | (uint)(param_1 & param_2);
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar3 >> 6 ^ uVar3 >> 7) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return;
}


// ===== 00289c60 adc_word =====

void adc_word(ushort param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((DAT_005483fc & 1) == 0) {
    uVar2 = (uint)param_1 + (uint)param_2;
    uVar3 = DAT_005483fc & 0xfffffffe;
    if ((uVar2 & 0x10000) != 0) goto LAB_00289c88;
LAB_00289c8d:
    if ((short)uVar2 != 0) goto LAB_00289d15;
    uVar3 = uVar3 | 0x40;
  }
  else {
    uVar2 = param_1 + 1 + (uint)param_2;
    if ((uVar2 & 0x10000) != 0) {
LAB_00289c88:
      uVar3 = DAT_005483fc | 1;
      goto LAB_00289c8d;
    }
    uVar3 = DAT_005483fc & 0xfffffffe;
LAB_00289d15:
    uVar3 = uVar3 & 0xffffffbf;
    if ((uVar2 & 0x8000) != 0) {
      uVar3 = uVar3 | 0x80;
      goto LAB_00289c9c;
    }
  }
  uVar3 = uVar3 & 0xffffff7f;
LAB_00289c9c:
  uVar1 = uVar3 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar2 >> 5 & 7) * 4) >> (uVar2 & 0x1f) & 1) == 0) {
    uVar1 = uVar3 | 4;
  }
  uVar3 = ~uVar2 & (uint)(param_1 | param_2) | (uint)(param_1 & param_2);
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar3 >> 0xe ^ uVar3 >> 0xf) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return;
}


// ===== 00289d50 adc_long =====

uint adc_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0xffff;
  uVar2 = param_1;
  if ((DAT_005483fc & 1) != 0) {
    uVar4 = uVar4 + 1;
    uVar2 = param_1 + 1;
  }
  uVar2 = uVar2 + param_2;
  uVar1 = DAT_005483fc & 0xfffffffe;
  if (((param_1 >> 0x10) + (param_2 >> 0x10) + (uVar4 + (param_2 & 0xffff) >> 0x10) & 0x10000) != 0)
  {
    uVar1 = DAT_005483fc | 1;
  }
  if (uVar2 == 0) {
    uVar1 = uVar1 | 0x40;
  }
  else {
    uVar1 = uVar1 & 0xffffffbf;
    if ((int)uVar2 < 0) {
      uVar1 = uVar1 | 0x80;
      goto LAB_00289da5;
    }
  }
  uVar1 = uVar1 & 0xffffff7f;
LAB_00289da5:
  uVar4 = uVar1 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar2 >> 5 & 7) * 4) >> (uVar2 & 0x1f) & 1) == 0) {
    uVar4 = uVar1 | 4;
  }
  uVar3 = ~uVar2 & (param_1 | param_2) | param_1 & param_2;
  uVar1 = uVar4 & 0xfffff7ff;
  if (((uVar3 >> 0x1e ^ uVar3 >> 0x1f) & 1) != 0) {
    uVar1 = uVar4 | 0x800;
  }
  DAT_005483fc = uVar1 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar1 | 0x10;
  }
  return uVar2;
}


// ===== 00289e40 add_byte =====

int add_byte(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_2;
  uVar4 = (param_1 & 0xff) + uVar2;
  uVar3 = DAT_005483fc | 1;
  if ((char)(uVar4 >> 8) == '\0') {
    uVar3 = DAT_005483fc & 0xfffffffe;
  }
  if ((char)uVar4 == '\0') {
    uVar3 = uVar3 | 0x40;
  }
  else {
    uVar3 = uVar3 & 0xffffffbf;
    if ((uVar4 & 0x80) != 0) {
      uVar3 = uVar3 | 0x80;
      goto LAB_00289e72;
    }
  }
  uVar3 = uVar3 & 0xffffff7f;
LAB_00289e72:
  uVar1 = uVar3 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar4 >> 5 & 7) * 4) >> (uVar4 & 0x1f) & 1) == 0) {
    uVar1 = uVar3 | 4;
  }
  uVar4 = ~uVar4 & (param_1 & 0xff | uVar2) | param_1 & uVar2;
  uVar3 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 6 ^ uVar4 >> 7) & 1) != 0) {
    uVar3 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return uVar2 + param_1;
}


// ===== 00289f10 add_word =====

int add_word(uint param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_2;
  uVar4 = (param_1 & 0xffff) + uVar2;
  uVar3 = DAT_005483fc | 1;
  if ((uVar4 & 0x10000) == 0) {
    uVar3 = DAT_005483fc & 0xfffffffe;
  }
  if ((short)uVar4 == 0) {
    uVar3 = uVar3 | 0x40;
  }
  else {
    uVar3 = uVar3 & 0xffffffbf;
    if ((uVar4 & 0x8000) != 0) {
      uVar3 = uVar3 | 0x80;
      goto LAB_00289f44;
    }
  }
  uVar3 = uVar3 & 0xffffff7f;
LAB_00289f44:
  uVar1 = uVar3 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar4 >> 5 & 7) * 4) >> (uVar4 & 0x1f) & 1) == 0) {
    uVar1 = uVar3 | 4;
  }
  uVar4 = ~uVar4 & (param_1 & 0xffff | uVar2) | param_1 & uVar2;
  uVar3 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 0xe ^ uVar4 >> 0xf) & 1) != 0) {
    uVar3 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return uVar2 + param_1;
}


// ===== 00289fe0 add_long =====

uint add_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = DAT_005483fc | 1;
  if ((((param_1 & 0xffff) + (param_2 & 0xffff) >> 0x10) + (param_1 >> 0x10) + (param_2 >> 0x10) &
      0x10000) == 0) {
    uVar2 = DAT_005483fc & 0xfffffffe;
  }
  uVar3 = param_1 + param_2;
  if (uVar3 == 0) {
    uVar2 = uVar2 | 0x40;
  }
  else {
    uVar2 = uVar2 & 0xffffffbf;
    if ((int)uVar3 < 0) {
      uVar2 = uVar2 | 0x80;
      goto LAB_0028a023;
    }
  }
  uVar2 = uVar2 & 0xffffff7f;
LAB_0028a023:
  uVar1 = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
    uVar1 = uVar2 | 4;
  }
  uVar4 = ~uVar3 & (param_1 | param_2) | param_1 & param_2;
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 0x1e ^ uVar4 >> 0x1f) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar3;
}


// ===== 0028a0a0 and_byte =====

void and_byte(byte param_1,byte param_2)

{
  uint uVar1;
  
  param_1 = param_1 & param_2;
  if ((char)param_1 < '\0') {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028a0be;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffbb;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028a0be:
  DAT_005483fc = uVar1 | 4;
  return;
}


// ===== 0028a100 and_word =====

void and_word(ushort param_1,ushort param_2)

{
  uint uVar1;
  
  param_1 = param_1 & param_2;
  if ((short)param_1 < 0) {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028a11f;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)((param_1 & 0xe0) >> 5) * 4) >> (param_1 & 0x1f) & 1) !=
      0) {
    DAT_005483fc = uVar1 & 0xffffffbb;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028a11f:
  DAT_005483fc = uVar1 | 4;
  return;
}


// ===== 0028a160 and_long =====

void and_long(uint param_1,uint param_2)

{
  uint uVar1;
  
  param_1 = param_1 & param_2;
  if ((int)param_1 < 0) {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028a17d;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffbb;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028a17d:
  DAT_005483fc = uVar1 | 4;
  return;
}


// ===== 0028a1c0 cmp_byte =====

uint cmp_byte(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = (char)param_1 - param_2;
  if ((char)bVar4 < '\0') {
    uVar1 = DAT_005483fc & 0xfffffffe | 0x80;
LAB_0028a245:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(bVar4 >> 5) * 4) >> (bVar4 & 0x1f) & 1) != 0) {
      uVar1 = uVar1 & 0xffffffbb;
      goto LAB_0028a1ed;
    }
    uVar1 = uVar1 & 0xffffffbf;
  }
  else {
    uVar1 = DAT_005483fc & 0xffffff7e;
    if (bVar4 != 0) goto LAB_0028a245;
    uVar1 = uVar1 | 0x40;
  }
  uVar1 = uVar1 | 4;
LAB_0028a1ed:
  uVar3 = ~(param_1 & 0xff);
  uVar3 = (param_2 | uVar3) & (param_1 & 0xff) - (uint)param_2 | param_2 & uVar3;
  if ((uVar3 & 0x80) != 0) {
    uVar1 = uVar1 | 1;
  }
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar3 >> 6 ^ uVar3 >> 7) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return param_1;
}


// ===== 0028a270 cmp_word =====

uint cmp_word(uint param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = (short)param_1 - param_2;
  if ((short)uVar4 < 0) {
    uVar1 = DAT_005483fc | 0x80;
LAB_0028a2f2:
    if ((*(uint *)(x86emu_parity_tab + (ulong)((uVar4 & 0xe0) >> 5) * 4) >> (uVar4 & 0x1f) & 1) != 0
       ) {
      uVar1 = uVar1 & 0xffffffbb;
      goto LAB_0028a29d;
    }
    uVar1 = uVar1 & 0xffffffbf;
  }
  else {
    uVar1 = DAT_005483fc & 0xffffff7f;
    if (uVar4 != 0) goto LAB_0028a2f2;
    uVar1 = uVar1 | 0x40;
  }
  uVar1 = uVar1 | 4;
LAB_0028a29d:
  uVar2 = ~(param_1 & 0xffff);
  uVar3 = (param_2 | uVar2) & (param_1 & 0xffff) - (uint)param_2 | param_2 & uVar2;
  uVar2 = uVar1 & 0xfffffffe;
  if ((uVar3 & 0x8000) != 0) {
    uVar2 = uVar1 | 1;
  }
  uVar1 = uVar2 & 0xfffff7ff;
  if (((uVar3 >> 0xe ^ uVar3 >> 0xf) & 1) != 0) {
    uVar1 = uVar2 | 0x800;
  }
  DAT_005483fc = uVar1 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar1 | 0x10;
  }
  return param_1;
}


// ===== 0028a320 cmp_long =====

uint cmp_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 - param_2;
  if ((int)uVar3 < 0) {
    uVar1 = DAT_005483fc | 0x80;
LAB_0028a392:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) != 0) {
      uVar1 = uVar1 & 0xffffffbb;
      goto LAB_0028a33f;
    }
    uVar1 = uVar1 & 0xffffffbf;
  }
  else {
    uVar1 = DAT_005483fc & 0xffffff7f;
    if (uVar3 != 0) goto LAB_0028a392;
    uVar1 = uVar1 | 0x40;
  }
  uVar1 = uVar1 | 4;
LAB_0028a33f:
  uVar2 = (~param_1 | param_2) & uVar3 | ~param_1 & param_2;
  uVar3 = uVar1 & 0xfffffffe;
  if ((int)uVar2 < 0) {
    uVar3 = uVar1 | 1;
  }
  uVar1 = uVar3 & 0xfffff7ff;
  if (((uVar2 >> 0x1e ^ uVar2 >> 0x1f) & 1) != 0) {
    uVar1 = uVar3 | 0x800;
  }
  DAT_005483fc = uVar1 & 0xffffffef;
  if ((uVar2 & 8) != 0) {
    DAT_005483fc = uVar1 | 0x10;
  }
  return param_1;
}


// ===== 0028a3c0 daa_byte =====

void daa_byte(byte param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)param_1;
  if (((param_1 & 0xf) < 10) && ((DAT_005483fc & 0x10) == 0)) {
    if (0x9f < param_1) goto LAB_0028a3e3;
LAB_0028a42d:
    if ((DAT_005483fc & 1) == 0) {
      if ((uVar1 & 0x80) != 0) {
        uVar2 = DAT_005483fc & 0xffffffbf | 0x80;
        goto LAB_0028a3f3;
      }
      goto LAB_0028a3e9;
    }
    uVar1 = uVar1 + 0x60;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = DAT_005483fc & 0xffffff7f | 1;
    }
    else {
      uVar2 = DAT_005483fc | 0x81;
    }
  }
  else {
    uVar1 = uVar1 + 6;
    DAT_005483fc = DAT_005483fc | 0x10;
    if (uVar1 < 0xa0) goto LAB_0028a42d;
LAB_0028a3e3:
    uVar1 = uVar1 + 0x60;
    DAT_005483fc = DAT_005483fc | 1;
LAB_0028a3e9:
    uVar2 = DAT_005483fc & 0xffffff7f;
    if ((char)uVar1 == '\0') {
      uVar2 = uVar2 | 0x40;
      goto LAB_0028a3f3;
    }
  }
  uVar2 = uVar2 & 0xffffffbf;
LAB_0028a3f3:
  DAT_005483fc = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar1 >> 5 & 7) * 4) >> (uVar1 & 0x1f) & 1) == 0) {
    DAT_005483fc = uVar2 | 4;
  }
  return;
}


// ===== 0028a460 das_byte =====

void das_byte(uint param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = (byte)param_1;
  if (((bVar1 & 0xf) < 10) && ((DAT_005483fc & 0x10) == 0)) {
    if (0x9f < bVar1) goto LAB_0028a47e;
LAB_0028a4ba:
    if ((DAT_005483fc & 1) != 0) {
      param_1 = param_1 - 0x60;
    }
    uVar2 = DAT_005483fc | DAT_005483fc & 1;
    if ((char)param_1 < '\0') goto LAB_0028a4eb;
    uVar2 = DAT_005483fc & 0xffffff7f;
    if ((char)param_1 == '\0') {
      uVar2 = uVar2 | 0x40;
      goto LAB_0028a4d7;
    }
  }
  else {
    param_1 = param_1 - 6;
    DAT_005483fc = DAT_005483fc | 0x10;
    bVar1 = (byte)param_1;
    if (bVar1 < 0xa0) goto LAB_0028a4ba;
LAB_0028a47e:
    uVar2 = DAT_005483fc & 0xffffff7f | 1;
    param_1 = (uint)(byte)(bVar1 + 0xa0);
    if ((char)(bVar1 + 0xa0) < '\0') {
      uVar2 = DAT_005483fc | 1;
LAB_0028a4eb:
      uVar2 = uVar2 | 0x80;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar2 & 0xffffffbb;
    return;
  }
  uVar2 = uVar2 & 0xffffffbf;
LAB_0028a4d7:
  DAT_005483fc = uVar2 | 4;
  return;
}


// ===== 0028a500 dec_byte =====

int dec_byte(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (param_1 & 0xff) - 1;
  if ((uVar1 & 0x80) == 0) {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if (uVar1 != 0) goto LAB_0028a518;
    uVar2 = uVar2 | 0x40;
  }
  else {
    uVar2 = DAT_005483fc | 0x80;
LAB_0028a518:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar1 >> 5 & 7) * 4) >> (uVar1 & 0x1f) & 1) != 0) {
      uVar2 = uVar2 & 0xffffffbb;
      goto LAB_0028a52f;
    }
    uVar2 = uVar2 & 0xffffffbf;
  }
  uVar2 = uVar2 | 4;
LAB_0028a52f:
  uVar1 = ~(param_1 & 0xff) & uVar1;
  uVar3 = uVar2 & 0xfffff7ff;
  if (((uVar1 >> 6 ^ uVar1 >> 7) & 1) != 0) {
    uVar3 = uVar2 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar1 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return param_1 - 1;
}


// ===== 0028a590 dec_word =====

int dec_word(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (param_1 & 0xffff) - 1;
  if ((uVar1 & 0x8000) == 0) {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if (uVar1 != 0) goto LAB_0028a5a8;
    uVar2 = uVar2 | 0x40;
  }
  else {
    uVar2 = DAT_005483fc | 0x80;
LAB_0028a5a8:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar1 >> 5 & 7) * 4) >> (uVar1 & 0x1f) & 1) != 0) {
      uVar2 = uVar2 & 0xffffffbb;
      goto LAB_0028a5bf;
    }
    uVar2 = uVar2 & 0xffffffbf;
  }
  uVar2 = uVar2 | 4;
LAB_0028a5bf:
  uVar1 = ~(param_1 & 0xffff) & uVar1;
  uVar3 = uVar2 & 0xfffff7ff;
  if (((uVar1 >> 0xe ^ uVar1 >> 0xf) & 1) != 0) {
    uVar3 = uVar2 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar1 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return param_1 - 1;
}


// ===== 0028a620 dec_long =====

uint dec_long(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 - 1;
  if ((int)uVar3 < 0) {
    uVar1 = DAT_005483fc | 0x80;
LAB_0028a682:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) != 0) {
      uVar1 = uVar1 & 0xffffffbb;
      goto LAB_0028a63d;
    }
    uVar1 = uVar1 & 0xffffffbf;
  }
  else {
    uVar1 = DAT_005483fc & 0xffffff7f;
    if (uVar3 != 0) goto LAB_0028a682;
    uVar1 = uVar1 | 0x40;
  }
  uVar1 = uVar1 | 4;
LAB_0028a63d:
  uVar4 = ~param_1 & uVar3;
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 0x1e ^ uVar4 >> 0x1f) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar3;
}


// ===== 0028a6a0 inc_byte =====

int inc_byte(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_1 & 0xff) + 1;
  if ((char)param_1 == -1) {
    uVar2 = DAT_005483fc | 0x40;
  }
  else {
    uVar2 = DAT_005483fc & 0xffffffbf;
    if ((uVar3 & 0x80) != 0) {
      uVar2 = uVar2 | 0x80;
      goto LAB_0028a6bc;
    }
  }
  uVar2 = uVar2 & 0xffffff7f;
LAB_0028a6bc:
  uVar1 = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
    uVar1 = uVar2 | 4;
  }
  uVar2 = ~uVar3 & param_1 & 0xff;
  uVar3 = uVar1 & 0xfffff7ff;
  if (((uVar2 >> 6 ^ uVar2 >> 7) & 1) != 0) {
    uVar3 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar2 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return param_1 + 1;
}


// ===== 0028a740 inc_word =====

int inc_word(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_1 & 0xffff) + 1;
  if ((short)param_1 == -1) {
    uVar3 = DAT_005483fc | 0x40;
  }
  else {
    uVar3 = DAT_005483fc & 0xffffffbf;
    if ((uVar2 & 0x8000) != 0) {
      uVar3 = uVar3 | 0x80;
      goto LAB_0028a75c;
    }
  }
  uVar3 = uVar3 & 0xffffff7f;
LAB_0028a75c:
  uVar1 = uVar3 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar2 >> 5 & 7) * 4) >> (uVar2 & 0x1f) & 1) == 0) {
    uVar1 = uVar3 | 4;
  }
  uVar3 = ~uVar2 & param_1 & 0xffff;
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar3 >> 0xe ^ uVar3 >> 0xf) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return param_1 + 1;
}


// ===== 0028a7e0 inc_long =====

uint inc_long(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 1;
  if (uVar3 == 0) {
    uVar2 = DAT_005483fc | 0x40;
  }
  else {
    uVar2 = DAT_005483fc & 0xffffffbf;
    if ((int)uVar3 < 0) {
      uVar2 = uVar2 | 0x80;
      goto LAB_0028a7f8;
    }
  }
  uVar2 = uVar2 & 0xffffff7f;
LAB_0028a7f8:
  uVar1 = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
    uVar1 = uVar2 | 4;
  }
  param_1 = ~uVar3 & param_1;
  uVar2 = uVar1 & 0xfffff7ff;
  if (((param_1 >> 0x1e ^ param_1 >> 0x1f) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((param_1 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar3;
}


// ===== 0028a870 or_byte =====

void or_byte(byte param_1,byte param_2)

{
  uint uVar1;
  
  param_1 = param_1 | param_2;
  if ((char)param_1 < '\0') {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028a88e;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffbb;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028a88e:
  DAT_005483fc = uVar1 | 4;
  return;
}


// ===== 0028a8d0 or_word =====

void or_word(ushort param_1,ushort param_2)

{
  uint uVar1;
  
  param_1 = param_1 | param_2;
  if ((short)param_1 < 0) {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028a8ef;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)((param_1 & 0xe0) >> 5) * 4) >> (param_1 & 0x1f) & 1) !=
      0) {
    DAT_005483fc = uVar1 & 0xffffffbb;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028a8ef:
  DAT_005483fc = uVar1 | 4;
  return;
}


// ===== 0028a930 or_long =====

void or_long(uint param_1,uint param_2)

{
  uint uVar1;
  
  param_1 = param_1 | param_2;
  if ((int)param_1 < 0) {
    uVar1 = DAT_005483fc & 0xfffff7ee | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff76e;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028a94d;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffbb;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028a94d:
  DAT_005483fc = uVar1 | 4;
  return;
}


// ===== 0028a990 neg_byte =====

uint neg_byte(uint param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if ((char)param_1 == '\0') {
    uVar1 = 0;
    uVar4 = DAT_005483fc & 0xffffff7e | 0x44;
  }
  else {
    uVar1 = -param_1;
    param_1 = param_1 | uVar1;
    bVar2 = (byte)uVar1;
    uVar3 = DAT_005483fc & 0xffffffbf | 0x81;
    if (-1 < (char)bVar2) {
      uVar3 = DAT_005483fc & 0xffffff3f | 1;
    }
    uVar4 = uVar3 & 0xfffffffb;
    if ((*(uint *)(x86emu_parity_tab + (ulong)(bVar2 >> 5) * 4) >> (bVar2 & 0x1f) & 1) == 0) {
      uVar4 = uVar3 | 4;
    }
    if ((byte)((byte)param_1 >> 6) != 3) {
      uVar4 = uVar4 | 0x800;
      goto LAB_0028a9e8;
    }
  }
  uVar4 = uVar4 & 0xfffff7ff;
LAB_0028a9e8:
  DAT_005483fc = uVar4 & 0xffffffef;
  if ((param_1 & 8) != 0) {
    DAT_005483fc = uVar4 | 0x10;
  }
  return uVar1;
}


// ===== 0028aa10 neg_word =====

uint neg_word(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((short)param_1 == 0) {
    uVar3 = 0;
    uVar2 = DAT_005483fc & 0xffffff7e | 0x44;
  }
  else {
    uVar3 = -param_1;
    param_1 = param_1 | uVar3;
    uVar1 = DAT_005483fc & 0xffffffbf | 0x81;
    if (-1 < (short)uVar3) {
      uVar1 = DAT_005483fc & 0xffffff3f | 1;
    }
    uVar2 = uVar1 & 0xfffffffb;
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
      uVar2 = uVar1 | 4;
    }
    if ((ushort)((ushort)param_1 >> 0xe) != 3) {
      uVar2 = uVar2 | 0x800;
      goto LAB_0028aa73;
    }
  }
  uVar2 = uVar2 & 0xfffff7ff;
LAB_0028aa73:
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((param_1 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar3;
}


// ===== 0028aaa0 neg_long =====

uint neg_long(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0;
    uVar2 = DAT_005483fc & 0xffffff7e | 0x44;
    param_1 = 0;
  }
  else {
    uVar3 = -param_1;
    param_1 = param_1 | uVar3;
    uVar1 = DAT_005483fc & 0xffffffbf | 0x81;
    if (-1 < (int)uVar3) {
      uVar1 = DAT_005483fc & 0xffffff3f | 1;
    }
    uVar2 = uVar1 & 0xfffffffb;
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
      uVar2 = uVar1 | 4;
    }
    if (param_1 >> 0x1e != 3) {
      uVar2 = uVar2 | 0x800;
      goto LAB_0028aafd;
    }
  }
  uVar2 = uVar2 & 0xfffff7ff;
LAB_0028aafd:
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((param_1 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar3;
}


// ===== 0028ab30 not_byte =====

uint not_byte(uint param_1)

{
  return ~param_1;
}


// ===== 0028ab40 not_word =====

uint not_word(uint param_1)

{
  return ~param_1;
}


// ===== 0028ab50 not_long =====

uint not_long(uint param_1)

{
  return ~param_1;
}


// ===== 0028ab60 rcl_byte =====

uint rcl_byte(byte param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_1;
  param_2 = param_2 % 9;
  if (param_2 != 0) {
    uVar2 = (1 << (param_2 - 1 & 0x1f)) - 1U & (int)(uint)param_1 >> (9 - param_2 & 0x1f) |
            (uint)param_1 << param_2 & 0xff | (DAT_005483fc & 1) << (param_2 - 1 & 0x1f);
    uVar3 = (int)(uint)param_1 >> (8 - param_2 & 0x1f) & 1;
    uVar1 = DAT_005483fc & 0xfffffffe;
    if (uVar3 != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    if ((param_2 == 1) && (uVar3 != (uVar2 >> 6 & 2) >> 1)) {
      DAT_005483fc = uVar1 | 0x800;
    }
    else {
      DAT_005483fc = uVar1 & 0xfffff7ff;
    }
  }
  return uVar2;
}


// ===== 0028ac10 rcl_word =====

uint rcl_word(ushort param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_1;
  param_2 = param_2 - ((char)((int)CONCAT62(0xffff,param_2 / 0x11) << 4) + param_2 / 0x11);
  if (param_2 != 0) {
    uVar2 = (1 << (param_2 - 1 & 0x1f)) - 1U & (int)(uint)param_1 >> (0x11 - param_2 & 0x1f) |
            (uint)param_1 << (param_2 & 0x1f) & 0xffff | (DAT_005483fc & 1) << (param_2 - 1 & 0x1f);
    uVar3 = (int)(uint)param_1 >> (0x10 - param_2 & 0x1f) & 1;
    uVar1 = DAT_005483fc & 0xfffffffe;
    if (uVar3 != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    if ((param_2 == 1) && (uVar3 != (uVar2 >> 0xe & 2) >> 1)) {
      DAT_005483fc = uVar1 | 0x800;
    }
    else {
      DAT_005483fc = uVar1 & 0xfffff7ff;
    }
  }
  return uVar2;
}


// ===== 0028acd0 rcl_long =====

uint rcl_long(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  param_2 = param_2 - ((char)((int)CONCAT62(0xffff,param_2 / 0x21) << 5) + param_2 / 0x21);
  if (param_2 != 0) {
    uVar3 = param_1 >> (-param_2 & 0x1f);
    uVar2 = 1 << (param_2 - 1 & 0x1f);
    uVar1 = uVar2;
    if ((DAT_005483fc & 1) == 0) {
      uVar1 = 0;
    }
    param_1 = param_1 >> (0x21 - param_2 & 0x1f) & uVar2 - 1 | param_1 << (param_2 & 0x1f) | uVar1;
    uVar3 = uVar3 & 1;
    uVar1 = DAT_005483fc & 0xfffffffe;
    if (uVar3 != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    if ((param_2 == 1) && (uVar3 != param_1 >> 0x1f)) {
      DAT_005483fc = uVar1 | 0x800;
    }
    else {
      DAT_005483fc = uVar1 & 0xfffff7ff;
    }
  }
  return param_1;
}


// ===== 0028ad70 rcr_byte =====

uint rcr_byte(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_2 = param_2 % 9;
  if (param_2 == 0) {
    return param_1;
  }
  uVar4 = param_1 & 0xff;
  uVar3 = DAT_005483fc & 1;
  uVar5 = uVar3;
  uVar2 = param_1;
  if (param_2 != 1) {
    uVar5 = 0;
    uVar2 = (int)uVar4 >> (param_2 - 1 & 0x1f);
  }
  uVar1 = DAT_005483fc & 0xfffffffe;
  if ((uVar2 & 1) != 0) {
    uVar1 = DAT_005483fc | 1;
  }
  DAT_005483fc = uVar1;
  if (param_2 == 1) {
    DAT_005483fc = uVar1 | 0x800;
    if (uVar5 == (param_1 >> 6 & 2) >> 1) {
      DAT_005483fc = uVar1 & 0xfffff7ff;
    }
  }
  return (1 << (8 - param_2 & 0x1f)) - 1U & (int)uVar4 >> param_2 | uVar4 << (9 - param_2 & 0x1f) |
         uVar3 << (8 - param_2 & 0x1f);
}


// ===== 0028ae60 rcr_word =====

uint rcr_word(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_2 = param_2 - ((char)((int)CONCAT62(0xffff,param_2 / 0x11) << 4) + param_2 / 0x11);
  if (param_2 == 0) {
    return param_1;
  }
  uVar4 = param_1 & 0xffff;
  uVar3 = DAT_005483fc & 1;
  uVar5 = uVar3;
  uVar2 = param_1;
  if (param_2 != 1) {
    uVar5 = 0;
    uVar2 = (int)uVar4 >> (param_2 - 1 & 0x1f);
  }
  uVar1 = DAT_005483fc & 0xfffffffe;
  if ((uVar2 & 1) != 0) {
    uVar1 = DAT_005483fc | 1;
  }
  DAT_005483fc = uVar1;
  if (param_2 == 1) {
    DAT_005483fc = uVar1 | 0x800;
    if (uVar5 == (param_1 >> 0xe & 2) >> 1) {
      DAT_005483fc = uVar1 & 0xfffff7ff;
    }
  }
  return (1 << (0x10 - param_2 & 0x1f)) - 1U & (int)uVar4 >> (param_2 & 0x1f) |
         uVar4 << (0x11 - param_2 & 0x1f) | uVar3 << (0x10 - param_2 & 0x1f);
}


// ===== 0028af50 rcr_long =====

uint rcr_long(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_2 = param_2 - ((char)((int)CONCAT62(0xffff,param_2 / 0x21) << 5) + param_2 / 0x21);
  if (param_2 == 0) {
    return param_1;
  }
  uVar4 = DAT_005483fc & 1;
  if (param_2 != 1) {
    uVar2 = 1 << (-param_2 & 0x1f);
    uVar3 = param_1 << (0x21 - param_2 & 0x1f) | param_1 >> (param_2 & 0x1f) & uVar2 - 1;
    if (uVar4 != 0) {
      uVar3 = uVar3 | uVar2;
    }
    uVar4 = DAT_005483fc & 0xfffffffe;
    if ((param_1 >> (param_2 - 1 & 0x1f) & 1) != 0) {
      uVar4 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar4;
    return uVar3;
  }
  uVar3 = param_1 >> 1;
  uVar2 = param_1 & 1;
  if (uVar4 == 0) {
    uVar1 = DAT_005483fc & 0xfffffffe;
    if (uVar2 != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    uVar4 = 0;
  }
  else {
    uVar3 = uVar3 | 0x80000000;
    if (uVar2 == 0) {
      uVar1 = DAT_005483fc & 0xfffffffe;
    }
    else {
      uVar1 = DAT_005483fc | 1;
      uVar4 = uVar2;
    }
  }
  DAT_005483fc = uVar1 | 0x800;
  if (uVar4 == param_1 >> 0x1f) {
    DAT_005483fc = uVar1 & 0xfffff7ff;
  }
  return uVar3;
}


// ===== 0028b050 rol_byte =====

uint rol_byte(byte param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = param_2 & 7;
  if (bVar2 == 0) {
    if (param_2 == 0) {
      return (uint)param_1;
    }
    uVar1 = (uint)param_1;
  }
  else {
    uVar1 = (1 << bVar2) - 1U & (int)(uint)param_1 >> (8 - bVar2 & 0x1f) | (uint)param_1 << bVar2;
    if ((uVar1 & 1) == 0) {
      uVar3 = DAT_005483fc & 0xfffffffe;
      DAT_005483fc = DAT_005483fc & 0xfffff7fe;
      if (param_2 != 1) goto LAB_0028b0d3;
    }
    else {
      if (param_2 != 1) {
        DAT_005483fc = DAT_005483fc & 0xfffff7ff | 1;
        goto LAB_0028b0a8;
      }
      uVar3 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar3 | 0x800;
    if ((uVar1 & 1) == (uVar1 >> 6 & 2) >> 1) {
      DAT_005483fc = uVar3 & 0xfffff7ff;
    }
  }
  if ((uVar1 & 1) == 0) {
LAB_0028b0d3:
    DAT_005483fc = DAT_005483fc & 0xfffffffe;
    return uVar1;
  }
LAB_0028b0a8:
  DAT_005483fc = DAT_005483fc | 1;
  return uVar1;
}


// ===== 0028b120 rol_word =====

uint rol_word(ushort param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = param_2 & 0xf;
  if (bVar2 == 0) {
    if (param_2 == 0) {
      return (uint)param_1;
    }
    uVar1 = (uint)param_1;
  }
  else {
    uVar1 = (1 << bVar2) - 1U & (int)(uint)param_1 >> (0x10 - bVar2 & 0x1f) | (uint)param_1 << bVar2
    ;
    if ((uVar1 & 1) == 0) {
      uVar3 = DAT_005483fc & 0xfffffffe;
      DAT_005483fc = DAT_005483fc & 0xfffff7fe;
      if (param_2 != 1) goto LAB_0028b1a3;
    }
    else {
      if (param_2 != 1) {
        DAT_005483fc = DAT_005483fc & 0xfffff7ff | 1;
        goto LAB_0028b177;
      }
      uVar3 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar3 | 0x800;
    if ((uVar1 & 1) == (uVar1 >> 0xe & 2) >> 1) {
      DAT_005483fc = uVar3 & 0xfffff7ff;
    }
  }
  if ((uVar1 & 1) == 0) {
LAB_0028b1a3:
    DAT_005483fc = DAT_005483fc & 0xfffffffe;
    return uVar1;
  }
LAB_0028b177:
  DAT_005483fc = DAT_005483fc | 1;
  return uVar1;
}


// ===== 0028b1f0 rol_long =====

void rol_long(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = param_2 & 0x1f;
  if (bVar3 == 0) {
    if (param_2 == 0) {
      return;
    }
    param_1 = param_1 & 1;
  }
  else {
    uVar1 = param_1 >> (-bVar3 & 0x1f) & (1 << bVar3) - 1U | param_1 << bVar3;
    param_1 = uVar1 & 1;
    if (param_1 == 0) {
      uVar2 = DAT_005483fc & 0xfffffffe;
      if (param_2 != 1) {
        DAT_005483fc = DAT_005483fc & 0xfffff7fe;
        return;
      }
    }
    else {
      if (param_2 != 1) {
        DAT_005483fc = DAT_005483fc & 0xfffff7ff;
        goto LAB_0028b233;
      }
      uVar2 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar2 | 0x800;
    if (param_1 == uVar1 >> 0x1f) {
      DAT_005483fc = uVar2 & 0xfffff7ff;
    }
  }
  if (param_1 == 0) {
    DAT_005483fc = DAT_005483fc & 0xfffffffe;
    return;
  }
LAB_0028b233:
  DAT_005483fc = DAT_005483fc | 1;
  return;
}


// ===== 0028b2b0 ror_byte =====

uint ror_byte(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = param_2 & 7;
  if (bVar3 == 0) {
    if (param_2 != 0) {
      uVar2 = DAT_005483fc & 0xfffffffe;
      DAT_005483fc = DAT_005483fc | 1;
      if (-1 < (char)param_1) {
        DAT_005483fc = uVar2;
      }
    }
    return param_1;
  }
  uVar1 = (1 << (8 - bVar3 & 0x1f)) - 1U & (int)(param_1 & 0xff) >> bVar3 |
          (param_1 & 0xff) << (8 - bVar3 & 0x1f);
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((uVar1 & 0x80) != 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if ((param_2 == 1) && (((uVar1 >> 6 ^ uVar1 >> 7) & 1) != 0)) {
    DAT_005483fc = uVar2 | 0x800;
    return uVar1;
  }
  DAT_005483fc = uVar2 & 0xfffff7ff;
  return uVar1;
}


// ===== 0028b360 ror_word =====

uint ror_word(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = param_2 & 0xf;
  if (bVar3 == 0) {
    if (param_2 != 0) {
      uVar2 = DAT_005483fc & 0xfffffffe;
      DAT_005483fc = DAT_005483fc | 1;
      if (-1 < (short)param_1) {
        DAT_005483fc = uVar2;
      }
    }
    return param_1;
  }
  uVar1 = (1 << (0x10 - bVar3 & 0x1f)) - 1U & (int)(param_1 & 0xffff) >> bVar3 |
          (param_1 & 0xffff) << (0x10 - bVar3 & 0x1f);
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((uVar1 & 0x8000) != 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if ((param_2 == 1) && (((uVar1 >> 0xe ^ uVar1 >> 0xf) & 1) != 0)) {
    DAT_005483fc = uVar2 | 0x800;
    return uVar1;
  }
  DAT_005483fc = uVar2 & 0xfffff7ff;
  return uVar1;
}


// ===== 0028b410 ror_long =====

uint ror_long(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = param_2 & 0x1f;
  if (bVar3 == 0) {
    if (param_2 != 0) {
      uVar2 = DAT_005483fc & 0xfffffffe;
      DAT_005483fc = DAT_005483fc | 1;
      if (-1 < (int)param_1) {
        DAT_005483fc = uVar2;
      }
    }
    return param_1;
  }
  uVar1 = param_1 >> bVar3 & (1 << (0x20 - bVar3 & 0x1f)) - 1U | param_1 << (0x20 - bVar3 & 0x1f);
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((int)uVar1 < 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if ((param_2 == 1) && (((uVar1 >> 0x1e ^ uVar1 >> 0x1f) & 1) != 0)) {
    DAT_005483fc = uVar2 | 0x800;
    return uVar1;
  }
  DAT_005483fc = uVar2 & 0xfffff7ff;
  return uVar1;
}


// ===== 0028b4b0 shl_byte =====

uint shl_byte(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = (byte)param_2;
  if (7 < bVar3) {
    uVar2 = DAT_005483fc & 0xfffffffe;
    if (((param_1 & 0xff) << (bVar3 - 1 & 0x1f) & 0x80) != 0) {
      uVar2 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar2 & 0xfffff77f | 0x44;
    return 0;
  }
  if (bVar3 == 0) goto LAB_0028b580;
  uVar4 = param_1 & 0xff;
  param_1 = uVar4 << (bVar3 & 0x1f);
  uVar2 = DAT_005483fc | 1;
  if ((uVar4 >> (8U - param_2 & 0x1f) & 1) == 0) {
    uVar2 = DAT_005483fc & 0xfffffffe;
  }
  if ((char)param_1 == '\0') {
    uVar2 = uVar2 | 0x40;
LAB_0028b593:
    uVar2 = uVar2 & 0xffffff7f;
    bVar1 = 0;
  }
  else {
    uVar2 = uVar2 & 0xffffffbf;
    if ((param_1 & 0x80) == 0) goto LAB_0028b593;
    uVar2 = uVar2 | 0x80;
    bVar1 = 1;
  }
  DAT_005483fc = uVar2 | 4;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar2 & 0xfffffffb;
  }
  if (bVar3 == 1) {
    if (((byte)DAT_005483fc & 1) == bVar1) {
      DAT_005483fc = DAT_005483fc & 0xfffff7ff;
    }
    else {
      DAT_005483fc = DAT_005483fc | 0x800;
    }
    return param_1;
  }
LAB_0028b580:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028b5b0 shl_word =====

uint shl_word(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = (byte)param_2;
  if (0xf < bVar3) {
    uVar2 = DAT_005483fc & 0xfffffffe;
    if (((param_1 & 0xffff) << (bVar3 - 1 & 0x1f) & 0x8000) != 0) {
      uVar2 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar2 & 0xfffff77f | 0x44;
    return 0;
  }
  if (bVar3 == 0) goto LAB_0028b680;
  uVar4 = param_1 & 0xffff;
  param_1 = uVar4 << (bVar3 & 0x1f);
  uVar2 = DAT_005483fc | 1;
  if ((uVar4 >> (0x10U - param_2 & 0x1f) & 1) == 0) {
    uVar2 = DAT_005483fc & 0xfffffffe;
  }
  if ((short)param_1 == 0) {
    uVar2 = uVar2 | 0x40;
LAB_0028b693:
    uVar2 = uVar2 & 0xffffff7f;
    bVar1 = 0;
  }
  else {
    uVar2 = uVar2 & 0xffffffbf;
    if ((param_1 & 0x8000) == 0) goto LAB_0028b693;
    uVar2 = uVar2 | 0x80;
    bVar1 = 1;
  }
  DAT_005483fc = uVar2 | 4;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar2 & 0xfffffffb;
  }
  if (bVar3 == 1) {
    if (((byte)DAT_005483fc & 1) == bVar1) {
      DAT_005483fc = DAT_005483fc & 0xfffff7ff;
    }
    else {
      DAT_005483fc = DAT_005483fc | 0x800;
    }
    return param_1;
  }
LAB_0028b680:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028b6b0 shl_long =====

uint shl_long(uint param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (0x1f < param_2) {
    uVar3 = DAT_005483fc & 0xfffffffe;
    if (param_1 << (param_2 - 1 & 0x1f) != 0) {
      uVar3 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar3 & 0xfffff77f | 0x44;
    return 0;
  }
  uVar3 = param_1;
  if (param_2 == 0) goto LAB_0028b778;
  bVar1 = param_2 & 0x1f;
  uVar3 = param_1 << bVar1;
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((1 << (-param_2 & 0x1f) & param_1) != 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if (param_1 << bVar1 == 0) {
    uVar2 = uVar2 | 0x40;
    uVar4 = 0;
LAB_0028b796:
    uVar2 = uVar2 & 0xffffff7f;
  }
  else {
    uVar2 = uVar2 & 0xffffffbf;
    uVar4 = uVar3;
    if (-1 < (int)(param_1 << bVar1)) goto LAB_0028b796;
    uVar2 = uVar2 | 0x80;
  }
  DAT_005483fc = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
    DAT_005483fc = uVar2 | 4;
  }
  if (param_2 == 1) {
    uVar2 = DAT_005483fc & 0xfffff7ff;
    if ((byte)((byte)DAT_005483fc & 1) != (byte)-(char)((int)uVar4 >> 0x1f)) {
      uVar2 = DAT_005483fc | 0x800;
    }
    DAT_005483fc = uVar2;
    return uVar3;
  }
LAB_0028b778:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return uVar3;
}


// ===== 0028b7a0 shr_byte =====

uint shr_byte(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = (byte)param_2;
  if (7 < bVar3) {
    uVar1 = DAT_005483fc & 0xfffffffe;
    if ((int)(param_1 & 0xff) >> (bVar3 - 1 & 0x1f) != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar1 & 0xfffff77f | 0x44;
    return 0;
  }
  if (bVar3 != 0) {
    uVar2 = param_1 & 0xff;
    param_1 = (int)uVar2 >> (bVar3 & 0x1f);
    uVar1 = DAT_005483fc & 0xfffffffe;
    if ((uVar2 >> (param_2 - 1U & 0x1f) & 1) != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    if (param_1 == 0) {
      DAT_005483fc = uVar1 & 0xffffff7f | 0x44;
    }
    else {
      if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5) * 4) >> (param_1 & 0x1f) & 1) == 0) {
        DAT_005483fc = uVar1 & 0xffffff3f | 4;
      }
      else {
        DAT_005483fc = uVar1 & 0xffffff3b;
      }
      if ((bVar3 == 1) && (param_1 >> 6 != 0)) {
        DAT_005483fc = DAT_005483fc | 0x800;
        return param_1;
      }
    }
  }
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028b860 shr_word =====

uint shr_word(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = (byte)param_2;
  if (0xf < bVar3) {
    DAT_005483fc = DAT_005483fc & 0xfffff77a | 0x40;
    return 0;
  }
  if (bVar3 != 0) {
    uVar2 = param_1 & 0xffff;
    param_1 = (int)uVar2 >> (bVar3 & 0x1f);
    uVar1 = DAT_005483fc & 0xfffffffe;
    if ((uVar2 >> (param_2 - 1U & 0x1f) & 1) != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    if (param_1 == 0) {
      DAT_005483fc = uVar1 & 0xffffff7f | 0x44;
    }
    else {
      if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) ==
          0) {
        DAT_005483fc = uVar1 & 0xffffff3f | 4;
      }
      else {
        DAT_005483fc = uVar1 & 0xffffff3b;
      }
      if ((bVar3 == 1) && (param_1 >> 0xe != 0)) {
        DAT_005483fc = DAT_005483fc | 0x800;
        return param_1;
      }
    }
  }
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028b900 shr_long =====

uint shr_long(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (0x1f < param_2) {
    DAT_005483fc = DAT_005483fc & 0xfffff77a | 0x40;
    return 0;
  }
  if (param_2 != 0) {
    uVar2 = 1 << (param_2 - 1 & 0x1f) & param_1;
    param_1 = param_1 >> (param_2 & 0x1f);
    uVar1 = DAT_005483fc & 0xfffffffe;
    if (uVar2 != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    if (param_1 == 0) {
      DAT_005483fc = uVar1 & 0xffffff7f | 0x44;
    }
    else {
      if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) ==
          0) {
        DAT_005483fc = uVar1 & 0xffffff3f | 4;
      }
      else {
        DAT_005483fc = uVar1 & 0xffffff3b;
      }
      if ((param_2 == 1) && (param_1 >> 0x1e != 0)) {
        DAT_005483fc = DAT_005483fc | 0x800;
        return param_1;
      }
    }
  }
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028b9a0 sar_byte =====

uint sar_byte(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (param_2 & 7) - 1;
  if (6 < uVar1) {
    return param_1;
  }
  iVar3 = 1 << (8U - (char)(param_2 & 7) & 0x1f);
  uVar4 = iVar3 - 1U & (int)(param_1 & 0xff) >> ((byte)param_2 & 7);
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((1 << ((byte)uVar1 & 0x1f) & param_1 & 0xff) != 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if ((char)param_1 < '\0') {
    uVar4 = -iVar3 | uVar4;
  }
  else if (uVar4 == 0) {
    uVar2 = uVar2 | 0x44;
    uVar4 = 0;
    goto LAB_0028ba02;
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar4 >> 5 & 7) * 4) >> (uVar4 & 0x1f) & 1) == 0) {
    uVar2 = uVar2 & 0xffffffbf | 4;
  }
  else {
    uVar2 = uVar2 & 0xffffffbb;
  }
  if ((uVar4 & 0x80) != 0) {
    DAT_005483fc = uVar2 | 0x80;
    return uVar4;
  }
LAB_0028ba02:
  DAT_005483fc = uVar2 & 0xffffff7f;
  return uVar4;
}


// ===== 0028ba60 sar_word =====

uint sar_word(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (param_2 & 0xf) - 1;
  if (0xe < uVar1) {
    return param_1;
  }
  iVar3 = 1 << (0x10U - (char)(param_2 & 0xf) & 0x1f);
  uVar4 = iVar3 - 1U & (int)(param_1 & 0xffff) >> ((byte)param_2 & 0xf);
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((1 << ((byte)uVar1 & 0x1f) & param_1 & 0xffff) != 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if ((short)param_1 < 0) {
    uVar4 = -iVar3 | uVar4;
    uVar2 = uVar2 & 0xffffffbf | 0x80;
    uVar1 = *(uint *)(x86emu_parity_tab + (ulong)(uVar4 >> 5 & 7) * 4) >> (uVar4 & 0x1f);
  }
  else {
    if (uVar4 == 0) {
      uVar4 = 0;
      uVar2 = uVar2 & 0xffffff7f | 0x40;
      goto LAB_0028bac5;
    }
    uVar1 = *(uint *)(x86emu_parity_tab + (ulong)(uVar4 >> 5 & 7) * 4) >> (uVar4 & 0x1f);
    uVar2 = uVar2 & 0xffffff3f;
  }
  if ((uVar1 & 1) != 0) {
    DAT_005483fc = uVar2 & 0xfffffffb;
    return uVar4;
  }
LAB_0028bac5:
  DAT_005483fc = uVar2 | 4;
  return uVar4;
}


// ===== 0028bb30 sar_long =====

uint sar_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar1 = (param_2 & 0x1f) - 1;
  if (0x1e < uVar1) {
    return param_1;
  }
  iVar4 = 1 << (-(char)(param_2 & 0x1f) & 0x1fU);
  uVar3 = param_1 >> ((byte)param_2 & 0x1f) & iVar4 - 1U;
  uVar2 = DAT_005483fc & 0xfffffffe;
  if ((1 << ((byte)uVar1 & 0x1f) & param_1) != 0) {
    uVar2 = DAT_005483fc | 1;
  }
  if ((int)param_1 < 0) {
    uVar3 = uVar3 | -iVar4;
    if (uVar3 == 0) goto LAB_0028bb7f;
    bVar5 = (*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) != 0;
    if (-1 < (int)uVar3) goto LAB_0028bbf3;
    uVar2 = uVar2 & 0xffffffbf | 0x80;
  }
  else {
    if (uVar3 == 0) {
LAB_0028bb7f:
      uVar3 = 0;
      uVar2 = uVar2 & 0xffffff7f | 0x40;
      goto LAB_0028bb86;
    }
    bVar5 = (*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) != 0;
LAB_0028bbf3:
    uVar2 = uVar2 & 0xffffff3f;
  }
  if (bVar5) {
    DAT_005483fc = uVar2 & 0xfffffffb;
    return uVar3;
  }
LAB_0028bb86:
  DAT_005483fc = uVar2 | 4;
  return uVar3;
}


// ===== 0028bc00 shld_word =====

uint shld_word(uint param_1,ushort param_2,byte param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  if (0xf < param_3) {
    uVar2 = DAT_005483fc & 0xfffffffe;
    if (((param_1 & 0xffff) << (param_3 - 1 & 0x1f) & 0x8000) != 0) {
      uVar2 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar2 & 0xfffff77f | 0x44;
    return 0;
  }
  if (param_3 == 0) goto LAB_0028bcf8;
  uVar3 = param_1 & 0xffff;
  param_1 = (int)(uint)param_2 >> ((byte)(0x10 - param_3) & 0x1f) | uVar3 << (param_3 & 0x1f);
  uVar2 = DAT_005483fc | 1;
  if ((uVar3 >> (0x10 - param_3 & 0x1f) & 1) == 0) {
    uVar2 = DAT_005483fc & 0xfffffffe;
  }
  if ((short)param_1 == 0) {
    uVar2 = uVar2 | 0x40;
LAB_0028bd13:
    uVar2 = uVar2 & 0xffffff7f;
    bVar1 = 0;
  }
  else {
    uVar2 = uVar2 & 0xffffffbf;
    if ((param_1 & 0x8000) == 0) goto LAB_0028bd13;
    uVar2 = uVar2 | 0x80;
    bVar1 = 1;
  }
  DAT_005483fc = uVar2 | 4;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar2 & 0xfffffffb;
  }
  if (param_3 == 1) {
    if (((byte)DAT_005483fc & 1) == bVar1) {
      DAT_005483fc = DAT_005483fc & 0xfffff7ff;
    }
    else {
      DAT_005483fc = DAT_005483fc | 0x800;
    }
    return param_1;
  }
LAB_0028bcf8:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028bd30 shld_long =====

uint shld_long(uint param_1,uint param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (0x1f < param_3) {
    uVar1 = DAT_005483fc & 0xfffffffe;
    if (param_1 << (param_3 - 1 & 0x1f) != 0) {
      uVar1 = DAT_005483fc | 1;
    }
    DAT_005483fc = uVar1 & 0xfffff77f | 0x44;
    return 0;
  }
  if (param_3 == 0) goto LAB_0028be00;
  uVar1 = DAT_005483fc | 1;
  if ((param_1 >> (0x20 - param_3 & 0x1f) & 1) == 0) {
    uVar1 = DAT_005483fc & 0xfffffffe;
  }
  param_1 = param_2 >> ((byte)(0x20 - param_3) & 0x1f) | param_1 << (param_3 & 0x1f);
  if (param_1 == 0) {
    uVar1 = uVar1 | 0x40;
    uVar2 = 0;
LAB_0028be16:
    uVar1 = uVar1 & 0xffffff7f;
  }
  else {
    uVar1 = uVar1 & 0xffffffbf;
    uVar2 = param_1;
    if (-1 < (int)param_1) goto LAB_0028be16;
    uVar1 = uVar1 | 0x80;
  }
  DAT_005483fc = uVar1 | 4;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xfffffffb;
  }
  if (param_3 == 1) {
    uVar1 = DAT_005483fc & 0xfffff7ff;
    if ((byte)((byte)DAT_005483fc & 1) != (byte)-(char)((int)uVar2 >> 0x1f)) {
      uVar1 = DAT_005483fc | 0x800;
    }
    DAT_005483fc = uVar1;
    return param_1;
  }
LAB_0028be00:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028be20 shrd_word =====

uint shrd_word(uint param_1,ushort param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (0xf < param_3) {
    DAT_005483fc = DAT_005483fc & 0xfffff77a | 0x40;
    return 0;
  }
  if (param_3 == 0) goto LAB_0028bef0;
  uVar2 = param_1 & 0xffff;
  param_1 = (uint)param_2 << (0x10 - param_3 & 0x1f) | (int)uVar2 >> (param_3 & 0x1f);
  uVar1 = DAT_005483fc | 1;
  if ((uVar2 >> (param_3 - 1 & 0x1f) & 1) == 0) {
    uVar1 = DAT_005483fc & 0xfffffffe;
  }
  if ((short)param_1 == 0) {
    uVar1 = uVar1 | 0x40;
LAB_0028bf0b:
    uVar1 = uVar1 & 0xffffff7f;
  }
  else {
    uVar1 = uVar1 & 0xffffffbf;
    if ((param_1 & 0x8000) == 0) goto LAB_0028bf0b;
    uVar1 = uVar1 | 0x80;
  }
  DAT_005483fc = uVar1 | 4;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xfffffffb;
  }
  if (param_3 == 1) {
    if (((param_1 >> 0xe ^ param_1 >> 0xf) & 1) == 0) {
      DAT_005483fc = DAT_005483fc & 0xfffff7ff;
    }
    else {
      DAT_005483fc = DAT_005483fc | 0x800;
    }
    return param_1;
  }
LAB_0028bef0:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028bf30 shrd_long =====

uint shrd_long(uint param_1,int param_2,byte param_3)

{
  uint uVar1;
  
  if (0x1f < param_3) {
    DAT_005483fc = DAT_005483fc & 0xfffff77a | 0x40;
    return 0;
  }
  if (param_3 == 0) goto LAB_0028bff0;
  uVar1 = DAT_005483fc & 0xfffffffe;
  if ((1 << (param_3 - 1 & 0x1f) & param_1) != 0) {
    uVar1 = DAT_005483fc | 1;
  }
  param_1 = param_2 << (-param_3 & 0x1f) | param_1 >> (param_3 & 0x1f);
  if (param_1 == 0) {
    uVar1 = uVar1 | 0x40;
LAB_0028c003:
    uVar1 = uVar1 & 0xffffff7f;
  }
  else {
    uVar1 = uVar1 & 0xffffffbf;
    if (-1 < (int)param_1) goto LAB_0028c003;
    uVar1 = uVar1 | 0x80;
  }
  DAT_005483fc = uVar1 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) == 0) {
    DAT_005483fc = uVar1 | 4;
  }
  if ((param_3 == 1) && (((param_1 >> 0x1e ^ param_1 >> 0x1f) & 1) != 0)) {
    DAT_005483fc = DAT_005483fc | 0x800;
    return param_1;
  }
LAB_0028bff0:
  DAT_005483fc = DAT_005483fc & 0xfffff7ff;
  return param_1;
}


// ===== 0028c010 sbb_byte =====

void sbb_byte(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = ((param_1 & 0xff) - (uint)param_2) - (DAT_005483fc & 1);
  if ((uVar1 & 0x80) == 0) {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if ((char)uVar1 == '\0') {
      uVar2 = uVar2 | 0x40;
      goto LAB_0028c038;
    }
  }
  else {
    uVar2 = DAT_005483fc | 0x80;
  }
  uVar2 = uVar2 & 0xffffffbf;
LAB_0028c038:
  uVar4 = ~(param_1 & 0xff);
  uVar3 = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar1 >> 5 & 7) * 4) >> (uVar1 & 0x1f) & 1) == 0) {
    uVar3 = uVar2 | 4;
  }
  uVar2 = (uVar4 | param_2) & uVar1 | uVar4 & param_2;
  uVar1 = uVar3 & 0xfffffffe;
  if ((uVar2 & 0x80) != 0) {
    uVar1 = uVar3 | 1;
  }
  uVar3 = uVar1 & 0xfffff7ff;
  if (((uVar2 >> 6 ^ uVar2 >> 7) & 1) != 0) {
    uVar3 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar2 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return;
}


// ===== 0028c0d0 sbb_word =====

void sbb_word(uint param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = ((param_1 & 0xffff) - (uint)param_2) - (DAT_005483fc & 1);
  if ((uVar1 & 0x8000) == 0) {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if ((short)uVar1 == 0) {
      uVar2 = uVar2 | 0x40;
      goto LAB_0028c0f8;
    }
  }
  else {
    uVar2 = DAT_005483fc | 0x80;
  }
  uVar2 = uVar2 & 0xffffffbf;
LAB_0028c0f8:
  uVar4 = ~(param_1 & 0xffff);
  uVar3 = uVar2 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar1 >> 5 & 7) * 4) >> (uVar1 & 0x1f) & 1) == 0) {
    uVar3 = uVar2 | 4;
  }
  uVar2 = (uVar4 | param_2) & uVar1 | uVar4 & param_2;
  uVar1 = uVar3 & 0xfffffffe;
  if ((uVar2 & 0x8000) != 0) {
    uVar1 = uVar3 | 1;
  }
  uVar3 = uVar1 & 0xfffff7ff;
  if (((uVar2 >> 0xe ^ uVar2 >> 0xf) & 1) != 0) {
    uVar3 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar3 & 0xffffffef;
  if ((uVar2 & 8) != 0) {
    DAT_005483fc = uVar3 | 0x10;
  }
  return;
}


// ===== 0028c190 sbb_long =====

uint sbb_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 - param_2;
  if ((DAT_005483fc & 1) != 0) {
    uVar3 = (param_1 - param_2) - 1;
  }
  if ((int)uVar3 < 0) {
    uVar2 = DAT_005483fc | 0x80;
LAB_0028c20a:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) != 0) {
      uVar2 = uVar2 & 0xffffffbb;
      goto LAB_0028c1b6;
    }
    uVar2 = uVar2 & 0xffffffbf;
  }
  else {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if (uVar3 != 0) goto LAB_0028c20a;
    uVar2 = uVar2 | 0x40;
  }
  uVar2 = uVar2 | 4;
LAB_0028c1b6:
  uVar4 = (~param_1 | param_2) & uVar3 | ~param_1 & param_2;
  uVar1 = uVar2 & 0xfffffffe;
  if ((int)uVar4 < 0) {
    uVar1 = uVar2 | 1;
  }
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 0x1e ^ uVar4 >> 0x1f) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar3;
}


// ===== 0028c230 sub_byte =====

uint sub_byte(byte param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = param_1 - param_2;
  if ((char)bVar3 < '\0') {
    uVar2 = DAT_005483fc | 0x80;
LAB_0028c2b2:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(bVar3 >> 5) * 4) >> (bVar3 & 0x1f) & 1) != 0) {
      uVar2 = uVar2 & 0xffffffbb;
      goto LAB_0028c25b;
    }
    uVar2 = uVar2 & 0xffffffbf;
  }
  else {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if (bVar3 != 0) goto LAB_0028c2b2;
    uVar2 = uVar2 | 0x40;
  }
  uVar2 = uVar2 | 4;
LAB_0028c25b:
  uVar4 = ((uint)param_2 | ~(uint)param_1) & (uint)param_1 - (uint)param_2 |
          (uint)param_2 & ~(uint)param_1;
  uVar1 = uVar2 & 0xfffffffe;
  if ((uVar4 & 0x80) != 0) {
    uVar1 = uVar2 | 1;
  }
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 6 ^ uVar4 >> 7) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return (uint)bVar3;
}


// ===== 0028c2e0 sub_word =====

uint sub_word(ushort param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar3 = param_1 - param_2;
  if ((short)uVar3 < 0) {
    uVar2 = DAT_005483fc | 0x80;
LAB_0028c362:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) != 0) {
      uVar2 = uVar2 & 0xffffffbb;
      goto LAB_0028c30a;
    }
    uVar2 = uVar2 & 0xffffffbf;
  }
  else {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if (uVar3 != 0) goto LAB_0028c362;
    uVar2 = uVar2 | 0x40;
  }
  uVar2 = uVar2 | 4;
LAB_0028c30a:
  uVar4 = ((uint)param_2 | ~(uint)param_1) & (uint)param_1 - (uint)param_2 |
          (uint)param_2 & ~(uint)param_1;
  uVar1 = uVar2 & 0xfffffffe;
  if ((uVar4 & 0x8000) != 0) {
    uVar1 = uVar2 | 1;
  }
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar4 >> 0xe ^ uVar4 >> 0xf) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar4 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return (uint)uVar3;
}


// ===== 0028c390 sub_long =====

uint sub_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 - param_2;
  if ((int)uVar4 < 0) {
    uVar2 = DAT_005483fc | 0x80;
LAB_0028c402:
    if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar4 >> 5 & 7) * 4) >> (uVar4 & 0x1f) & 1) != 0) {
      uVar2 = uVar2 & 0xffffffbb;
      goto LAB_0028c3ac;
    }
    uVar2 = uVar2 & 0xffffffbf;
  }
  else {
    uVar2 = DAT_005483fc & 0xffffff7f;
    if (uVar4 != 0) goto LAB_0028c402;
    uVar2 = uVar2 | 0x40;
  }
  uVar2 = uVar2 | 4;
LAB_0028c3ac:
  uVar3 = (~param_1 | param_2) & uVar4 | ~param_1 & param_2;
  uVar1 = uVar2 & 0xfffffffe;
  if ((int)uVar3 < 0) {
    uVar1 = uVar2 | 1;
  }
  uVar2 = uVar1 & 0xfffff7ff;
  if (((uVar3 >> 0x1e ^ uVar3 >> 0x1f) & 1) != 0) {
    uVar2 = uVar1 | 0x800;
  }
  DAT_005483fc = uVar2 & 0xffffffef;
  if ((uVar3 & 8) != 0) {
    DAT_005483fc = uVar2 | 0x10;
  }
  return uVar4;
}


// ===== 0028c420 test_byte =====

void test_byte(byte param_1,byte param_2)

{
  uint uVar1;
  
  param_1 = param_1 & param_2;
  if ((char)param_1 < '\0') {
    uVar1 = DAT_005483fc & 0xfffff7ff | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff77f;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028c43f;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffba;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028c43f:
  DAT_005483fc = uVar1 & 0xfffffffe | 4;
  return;
}


// ===== 0028c480 test_word =====

void test_word(ushort param_1,ushort param_2)

{
  uint uVar1;
  
  param_1 = param_1 & param_2;
  if ((short)param_1 < 0) {
    uVar1 = DAT_005483fc & 0xfffff7ff | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff77f;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028c49c;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffba;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028c49c:
  DAT_005483fc = uVar1 & 0xfffffffe | 4;
  return;
}


// ===== 0028c4e0 test_long =====

void test_long(uint param_1,uint param_2)

{
  uint uVar1;
  
  param_1 = param_1 & param_2;
  if ((int)param_1 < 0) {
    uVar1 = DAT_005483fc & 0xfffff7ff | 0x80;
  }
  else {
    uVar1 = DAT_005483fc & 0xfffff77f;
    if (param_1 == 0) {
      uVar1 = uVar1 | 0x40;
      goto LAB_0028c4fa;
    }
  }
  if ((*(uint *)(x86emu_parity_tab + (ulong)(param_1 >> 5 & 7) * 4) >> (param_1 & 0x1f) & 1) != 0) {
    DAT_005483fc = uVar1 & 0xffffffba;
    return;
  }
  uVar1 = uVar1 & 0xffffffbf;
LAB_0028c4fa:
  DAT_005483fc = uVar1 & 0xfffffffe | 4;
  return;
}


// ===== 0028c540 xor_byte =====

void xor_byte(byte param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = param_1 ^ param_2;
  uVar3 = DAT_005483fc & 0xfffff77f;
  if ((char)bVar2 < '\0') {
    uVar3 = DAT_005483fc & 0xfffff7ff | 0x80;
  }
  uVar1 = uVar3 & 0xffffffbf;
  if (param_1 == param_2) {
    uVar1 = uVar3 | 0x40;
  }
  uVar3 = uVar1 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(bVar2 >> 5) * 4) >> (bVar2 & 0x1f) & 1) == 0) {
    uVar3 = uVar1 | 4;
  }
  DAT_005483fc = uVar3 & 0xffffffee;
  return;
}


// ===== 0028c5a0 xor_word =====

ushort xor_word(ushort param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  
  uVar3 = param_1 ^ param_2;
  uVar2 = DAT_005483fc & 0xfffff77f;
  if ((short)uVar3 < 0) {
    uVar2 = DAT_005483fc & 0xfffff7ff | 0x80;
  }
  uVar1 = uVar2 & 0xffffffbf;
  if (param_1 == param_2) {
    uVar1 = uVar2 | 0x40;
  }
  uVar2 = uVar1 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)((uVar3 & 0xe0) >> 5) * 4) >> (uVar3 & 0x1f) & 1) == 0)
  {
    uVar2 = uVar1 | 4;
  }
  DAT_005483fc = uVar2 & 0xffffffee;
  return uVar3;
}


// ===== 0028c600 xor_long =====

uint xor_long(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 ^ param_2;
  uVar2 = DAT_005483fc & 0xfffff77f;
  if ((int)uVar3 < 0) {
    uVar2 = DAT_005483fc & 0xfffff7ff | 0x80;
  }
  uVar1 = uVar2 & 0xffffffbf;
  if (param_1 == param_2) {
    uVar1 = uVar2 | 0x40;
  }
  uVar2 = uVar1 & 0xfffffffb;
  if ((*(uint *)(x86emu_parity_tab + (ulong)(uVar3 >> 5 & 7) * 4) >> (uVar3 & 0x1f) & 1) == 0) {
    uVar2 = uVar1 | 4;
  }
  DAT_005483fc = uVar2 & 0xffffffee;
  return uVar3;
}


// ===== 0028c660 imul_byte =====

void imul_byte(char param_1)

{
  char cVar1;
  
  DAT_005483d8 = (short)param_1 * (short)(char)DAT_005483d8;
  cVar1 = (char)((ushort)DAT_005483d8 >> 8);
  if ((char)DAT_005483d8 < '\0') {
    if (cVar1 == -1) goto LAB_0028c695;
  }
  else if (cVar1 == '\0') {
LAB_0028c695:
    DAT_005483fc = DAT_005483fc & 0xfffff7fe;
    return;
  }
  DAT_005483fc = DAT_005483fc | 0x801;
  return;
}


// ===== 0028c6b0 imul_word =====

void imul_word(short param_1)

{
  int iVar1;
  
  iVar1 = (int)DAT_005483d8;
  DAT_005483d8 = (short)(iVar1 * param_1);
  DAT_005483e4._0_2_ = (short)((uint)(iVar1 * param_1) >> 0x10);
  if (DAT_005483d8 < 0) {
    if ((short)DAT_005483e4 == 0xff) goto LAB_0028c6f6;
  }
  else if ((short)DAT_005483e4 == 0) {
LAB_0028c6f6:
    DAT_005483fc = DAT_005483fc & 0xfffff7fe;
    return;
  }
  DAT_005483fc = DAT_005483fc | 0x801;
  return;
}


// ===== 0028c710 imul_long_direct =====

void imul_long_direct(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  *param_1 = (int)((long)param_3 * (long)param_4);
  *param_2 = (int)((ulong)((long)param_3 * (long)param_4) >> 0x20);
  return;
}


// ===== 0028c730 imul_long =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void imul_long(int param_1)

{
  long lVar1;
  
  lVar1 = (long)_DAT_005483d8;
  _DAT_005483d8 = (int)(lVar1 * param_1);
  DAT_005483e4 = (int)((ulong)(lVar1 * param_1) >> 0x20);
  if (_DAT_005483d8 < 0) {
    if (DAT_005483e4 == 0xff) goto LAB_0028c777;
  }
  else if (DAT_005483e4 == 0) {
LAB_0028c777:
    DAT_005483fc = DAT_005483fc & 0xfffff7fe;
    return;
  }
  DAT_005483fc = DAT_005483fc | 0x801;
  return;
}


// ===== 0028c790 mul_byte =====

void mul_byte(byte param_1)

{
  uint uVar1;
  
  DAT_005483d8 = (ushort)param_1 * (DAT_005483d8 & 0xff);
  uVar1 = DAT_005483fc | 0x801;
  if (DAT_005483d8 >> 8 == 0) {
    uVar1 = DAT_005483fc & 0xfffff7fe;
  }
  DAT_005483fc = uVar1;
  return;
}


// ===== 0028c7d0 mul_word =====

void mul_word(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_005483d8 * (uint)param_1;
  DAT_005483d8 = (short)uVar2;
  DAT_005483e4._0_2_ = (short)(uVar2 >> 0x10);
  uVar1 = DAT_005483fc | 0x801;
  if (uVar2 >> 0x10 == 0) {
    uVar1 = DAT_005483fc & 0xfffff7fe;
  }
  DAT_005483fc = uVar1;
  return;
}


// ===== 0028c820 mul_long =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mul_long(ulong param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = (ulong)_DAT_005483d8 * (param_1 & 0xffffffff);
  _DAT_005483d8 = (int)uVar2;
  DAT_005483e4 = (int)(uVar2 >> 0x20);
  uVar1 = DAT_005483fc | 0x801;
  if (uVar2 >> 0x20 == 0) {
    uVar1 = DAT_005483fc & 0xfffff7fe;
  }
  DAT_005483fc = uVar1;
  return;
}


// ===== 0028c860 idiv_byte =====

void idiv_byte(char param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != '\0') {
    lVar1 = (long)(int)DAT_005483d8 / (long)(int)param_1;
    iVar2 = (int)lVar1;
    iVar3 = -iVar2;
    if (iVar3 < 0) {
      iVar3 = iVar2;
    }
    if (iVar3 < 0x80) {
      DAT_005483d8 = CONCAT11((char)((int)DAT_005483d8 % (int)param_1),(char)lVar1);
      return;
    }
  }
  x86emu_intr_raise(0);
  return;
}


// ===== 0028c8a0 idiv_word =====

void idiv_word(short param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 != 0) {
    lVar1 = (long)CONCAT22((undefined2)DAT_005483e4,DAT_005483d8) / (long)(int)param_1;
    lVar2 = (long)CONCAT22((undefined2)DAT_005483e4,DAT_005483d8) % (long)(int)param_1;
    iVar3 = (int)lVar1;
    iVar4 = -iVar3;
    if (-iVar3 < 0) {
      iVar4 = iVar3;
    }
    if (iVar4 < 0x8000) {
      DAT_005483d8 = (short)lVar1;
      DAT_005483e4._0_2_ = (short)lVar2;
      uVar5 = DAT_005483fc & 0xffffff3e;
      if (iVar3 == 0) {
        uVar5 = DAT_005483fc & 0xffffff7e | 0x40;
      }
      uVar6 = (uint)lVar2;
      DAT_005483fc = uVar5 & 0xfffffffb;
      if ((*(uint *)(x86emu_parity_tab + (ulong)((int)uVar6 >> 5 & 7) * 4) >> (uVar6 & 0x1f) & 1) ==
          0) {
        DAT_005483fc = uVar5 | 4;
      }
      return;
    }
  }
  x86emu_intr_raise(0);
  return;
}


// ===== 0028c930 idiv_long =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void idiv_long(int param_1)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  
  if (param_1 != 0) {
    uVar1 = CONCAT44(DAT_005483e4,_DAT_005483d8) / (long)param_1;
    lVar4 = CONCAT44(DAT_005483e4,_DAT_005483d8) % (long)param_1;
    uVar3 = uVar1 >> 0x20;
    if ((uVar3 == 0) || (uVar3 == 0xffffffff)) {
      _DAT_005483d8 = (int)uVar1;
      DAT_005483e4 = (uint)lVar4;
      uVar2 = DAT_005483fc & 0xffffff6a | 0x40;
      if ((*(uint *)(x86emu_parity_tab + (ulong)((uint)(lVar4 >> 5) & 7) * 4) >>
           (DAT_005483e4 & 0x1f) & 1) == 0) {
        uVar2 = DAT_005483fc & 0xffffff6e | 0x44;
      }
      DAT_005483fc = uVar2;
      return;
    }
  }
  x86emu_intr_raise(0);
  return;
}


// ===== 0028c9c0 div_byte =====

void div_byte(byte param_1)

{
  ulong uVar1;
  
  if (param_1 != 0) {
    uVar1 = (ulong)DAT_005483d8 / (ulong)param_1;
    if ((uint)uVar1 < 0x100) {
      DAT_005483d8 = CONCAT11((char)((ulong)DAT_005483d8 % (ulong)param_1),(char)uVar1);
      return;
    }
  }
  x86emu_intr_raise(0);
  return;
}


// ===== 0028ca00 div_word =====

void div_word(ushort param_1)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    uVar4 = CONCAT22((undefined2)DAT_005483e4,DAT_005483d8);
    uVar1 = (ulong)uVar4 / (ulong)param_1;
    uVar2 = (ulong)uVar4 % (ulong)param_1;
    if ((uint)uVar1 < 0x10000) {
      DAT_005483d8 = (short)uVar1;
      DAT_005483e4._0_2_ = (short)uVar2;
      uVar3 = DAT_005483fc & 0xffffff3e;
      if (uVar4 < param_1) {
        uVar3 = DAT_005483fc & 0xffffff7e | 0x40;
      }
      DAT_005483fc = uVar3 & 0xfffffffb;
      if ((*(uint *)(x86emu_parity_tab + (ulong)((uint)(uVar2 >> 5) & 7) * 4) >>
           ((uint)uVar2 & 0x1f) & 1) == 0) {
        DAT_005483fc = uVar3 | 4;
      }
      return;
    }
  }
  x86emu_intr_raise(0);
  return;
}


// ===== 0028ca90 div_long =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void div_long(uint param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  uint uVar3;
  
  if (param_1 != 0) {
    auVar1._4_4_ = DAT_005483e4;
    auVar1._0_4_ = _DAT_005483d8;
    auVar1._8_8_ = 0;
    auVar2 = auVar1 / ZEXT416(param_1);
    auVar1 = auVar1 % ZEXT416(param_1);
    if (auVar2._0_8_ >> 0x20 == 0) {
      _DAT_005483d8 = auVar2._0_4_;
      DAT_005483e4 = auVar1._0_4_;
      uVar3 = DAT_005483fc & 0xffffff6a | 0x40;
      if ((*(uint *)(x86emu_parity_tab + (ulong)((uint)(auVar1._0_8_ >> 5) & 7) * 4) >>
           (DAT_005483e4 & 0x1f) & 1) == 0) {
        uVar3 = DAT_005483fc & 0xffffff6e | 0x44;
      }
      DAT_005483fc = uVar3;
      return;
    }
  }
  x86emu_intr_raise(0);
  return;
}


// ===== 0028cb10 ins =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void ins(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  short sVar6;
  
  iVar1 = -param_1;
  if ((DAT_005483fc._1_1_ & 4) == 0) {
    iVar1 = param_1;
  }
  sVar6 = (short)iVar1;
  if ((DAT_0054840c & 0x180) == 0) {
    if (param_1 == 2) {
      uVar3 = (*(code *)sys_inw)((undefined2)DAT_005483e4);
      store_data_word_abs(DAT_00548406,DAT_005483f4,uVar3);
    }
    else if (param_1 == 4) {
      uVar4 = (*(code *)sys_inl)((undefined2)DAT_005483e4);
      store_data_long_abs(DAT_00548406,DAT_005483f4,uVar4);
    }
    else if (param_1 == 1) {
      uVar2 = (*(code *)sys_inb)((undefined2)DAT_005483e4);
      store_data_byte_abs(DAT_00548406,DAT_005483f4,uVar2);
    }
    DAT_005483f4 = DAT_005483f4 + sVar6;
    return;
  }
  if ((DAT_0054840c & 0x200) == 0) {
    uVar5 = DAT_005483e0 & 0xffff;
    if (param_1 == 2) {
      if (uVar5 != 0) goto LAB_0028ccc0;
    }
    else if (param_1 == 4) {
      if (uVar5 != 0) goto LAB_0028cd48;
    }
    else if ((param_1 == 1) && (uVar5 != 0)) goto LAB_0028cb80;
LAB_0028cc40:
    DAT_005483e0 = DAT_005483e0 & 0xffff0000;
  }
  else {
    uVar5 = DAT_005483e0;
    if (param_1 == 2) {
      if (DAT_005483e0 != 0) {
LAB_0028ccc0:
        do {
          uVar5 = uVar5 - 1;
          uVar3 = (*(code *)sys_inw)((undefined2)DAT_005483e4);
          store_data_word_abs(DAT_00548406,DAT_005483f4,uVar3);
          DAT_005483f4 = DAT_005483f4 + sVar6;
        } while (uVar5 != 0);
        goto LAB_0028cbb6;
      }
    }
    else if (param_1 == 4) {
      if (DAT_005483e0 != 0) {
LAB_0028cd48:
        uVar4 = (*(code *)sys_inl)((undefined2)DAT_005483e4);
        store_data_long_abs(DAT_00548406,DAT_005483f4,uVar4);
        DAT_005483f4 = DAT_005483f4 + sVar6;
        goto LAB_0028cbb6;
      }
    }
    else if ((param_1 == 1) && (DAT_005483e0 != 0)) {
LAB_0028cb80:
      do {
        uVar5 = uVar5 - 1;
        uVar2 = (*(code *)sys_inb)((undefined2)DAT_005483e4);
        store_data_byte_abs(DAT_00548406,DAT_005483f4,uVar2);
        DAT_005483f4 = DAT_005483f4 + sVar6;
      } while (uVar5 != 0);
LAB_0028cbb6:
      if ((DAT_0054840c & 0x200) == 0) goto LAB_0028cc40;
    }
    DAT_005483e0 = 0;
  }
  DAT_0054840c = DAT_0054840c & 0xfffffe7f;
  return;
}


// ===== 0028cd90 outs =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */

void outs(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar4 = sys_outb;
  puVar3 = sys_outw;
  puVar2 = sys_outl;
  iVar1 = -param_1;
  if ((DAT_005483fc._1_1_ & 4) == 0) {
    iVar1 = param_1;
  }
  if ((DAT_0054840c & 0x180) == 0) {
    if (param_1 == 2) {
      uVar6 = fetch_data_word_abs(DAT_00548406);
      (*(code *)puVar3)((undefined2)DAT_005483e4,uVar6);
    }
    else if (param_1 == 4) {
      uVar7 = fetch_data_long_abs(DAT_00548406);
      (*(code *)puVar2)((undefined2)DAT_005483e4,uVar7);
    }
    else if (param_1 == 1) {
      uVar5 = fetch_data_byte_abs(DAT_00548406);
      (*(code *)puVar4)((undefined2)DAT_005483e4,uVar5);
    }
    DAT_005483f0 = DAT_005483f0 + (short)iVar1;
    return;
  }
  if ((DAT_0054840c & 0x200) == 0) {
    uVar8 = DAT_005483e0 & 0xffff;
    if (param_1 == 2) {
      if (uVar8 != 0) goto LAB_0028cf64;
    }
    else if (param_1 == 4) {
      if (uVar8 != 0) goto LAB_0028d030;
    }
    else if ((param_1 == 1) && (uVar8 != 0)) goto LAB_0028cdf8;
LAB_0028ce65:
    DAT_005483e0 = DAT_005483e0 & 0xffff0000;
  }
  else {
    uVar8 = DAT_005483e0;
    if (param_1 == 2) {
      if (DAT_005483e0 != 0) {
LAB_0028cf64:
        uVar9 = (uint)DAT_005483f0;
        do {
          puVar2 = sys_outw;
          uVar8 = uVar8 - 1;
          uVar6 = fetch_data_word_abs(DAT_00548406,uVar9 & 0xffff);
          (*(code *)puVar2)((undefined2)DAT_005483e4,uVar6);
          uVar9 = (uint)DAT_005483f0 + iVar1;
          DAT_005483f0 = (ushort)uVar9;
        } while (uVar8 != 0);
        goto LAB_0028ce5d;
      }
    }
    else if (param_1 == 4) {
      if (DAT_005483e0 != 0) {
LAB_0028d030:
        uVar7 = fetch_data_long_abs(DAT_00548406,DAT_005483f0);
        (*(code *)puVar2)((undefined2)DAT_005483e4,uVar7);
        DAT_005483f0 = DAT_005483f0 + (short)iVar1;
        goto LAB_0028ce5d;
      }
    }
    else if ((param_1 == 1) && (DAT_005483e0 != 0)) {
LAB_0028cdf8:
      uVar9 = (uint)DAT_005483f0;
      do {
        puVar2 = sys_outb;
        uVar8 = uVar8 - 1;
        uVar5 = fetch_data_byte_abs(DAT_00548406,uVar9 & 0xffff);
        (*(code *)puVar2)((undefined2)DAT_005483e4,uVar5);
        uVar9 = (uint)DAT_005483f0 + iVar1;
        DAT_005483f0 = (ushort)uVar9;
      } while (uVar8 != 0);
LAB_0028ce5d:
      if ((DAT_0054840c & 0x200) == 0) goto LAB_0028ce65;
    }
    DAT_005483e0 = 0;
  }
  DAT_0054840c = DAT_0054840c & 0xfffffe7f;
  return;
}


// ===== 0028d080 mem_access_word =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void mem_access_word(void)

{
  (*(code *)sys_rdw)();
  return;
}


// ===== 0028d090 push_word =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void push_word(undefined2 param_1)

{
  DAT_005483e8._0_2_ = (ushort)DAT_005483e8 - 2;
  (*(code *)sys_wrw)((uint)DAT_00548404 * 0x10 + (uint)(ushort)DAT_005483e8,param_1);
  return;
}


// ===== 0028d0d0 push_long =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void push_long(undefined4 param_1)

{
  DAT_005483e8._0_2_ = (ushort)DAT_005483e8 - 4;
  (*(code *)sys_wrl)((uint)DAT_00548404 * 0x10 + (uint)(ushort)DAT_005483e8,param_1);
  return;
}


// ===== 0028d110 pop_word =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pop_word(void)

{
  (*(code *)sys_rdw)((uint)DAT_00548404 * 0x10 + (uint)(ushort)DAT_005483e8);
  DAT_005483e8._0_2_ = (ushort)DAT_005483e8 + 2;
  return;
}


// ===== 0028d150 pop_long =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pop_long(void)

{
  (*(code *)sys_rdl)((uint)DAT_00548404 * 0x10 + (uint)(ushort)DAT_005483e8);
  DAT_005483e8._0_2_ = (ushort)DAT_005483e8 + 4;
  return;
}


// ===== 0028d190 p_inb =====

undefined8 p_inb(void)

{
  return 0;
}


// ===== 0028d1a0 p_inw =====

undefined8 p_inw(void)

{
  return 0;
}


// ===== 0028d1b0 p_inl =====

undefined8 p_inl(void)

{
  return 0;
}


// ===== 0028d1c0 p_outb =====

void p_outb(void)

{
  return;
}


// ===== 0028d1d0 p_outw =====

void p_outw(void)

{
  return;
}


// ===== 0028d1e0 p_outl =====

void p_outl(void)

{
  return;
}


// ===== 0028d1f0 rdb =====

undefined1 rdb(uint param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1;
  if (uVar1 <= DAT_005483c8 - 1U) {
    return *(undefined1 *)(_X86EMU_env + uVar1);
  }
  X86EMU_halt_sys();
  return *(undefined1 *)(_X86EMU_env + uVar1);
}


// ===== 0028d240 rdw =====

undefined2 rdw(uint param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1;
  if (uVar1 <= DAT_005483c8 - 2U) {
    return *(undefined2 *)(_X86EMU_env + uVar1);
  }
  X86EMU_halt_sys();
  return *(undefined2 *)(_X86EMU_env + uVar1);
}


// ===== 0028d290 rdl =====

undefined4 rdl(uint param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1;
  if (uVar1 <= DAT_005483c8 - 4U) {
    return *(undefined4 *)(_X86EMU_env + uVar1);
  }
  X86EMU_halt_sys();
  return *(undefined4 *)(_X86EMU_env + uVar1);
}


// ===== 0028d2e0 wrb =====

void wrb(uint param_1,undefined1 param_2)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1;
  if (uVar1 <= DAT_005483c8 - 1U) {
    *(undefined1 *)(_X86EMU_env + uVar1) = param_2;
    return;
  }
  X86EMU_halt_sys();
  *(undefined1 *)(_X86EMU_env + uVar1) = param_2;
  return;
}


// ===== 0028d340 wrw =====

void wrw(uint param_1,undefined2 param_2)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1;
  if (uVar1 <= DAT_005483c8 - 2U) {
    *(undefined2 *)(_X86EMU_env + uVar1) = param_2;
    return;
  }
  X86EMU_halt_sys();
  *(undefined2 *)(_X86EMU_env + uVar1) = param_2;
  return;
}


// ===== 0028d390 wrl =====

void wrl(uint param_1,undefined4 param_2)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1;
  if (uVar1 <= DAT_005483c8 - 4U) {
    *(undefined4 *)(_X86EMU_env + uVar1) = param_2;
    return;
  }
  X86EMU_halt_sys();
  *(undefined4 *)(_X86EMU_env + uVar1) = param_2;
  return;
}


// ===== 0028d3e0 X86EMU_setupMemFuncs =====

void X86EMU_setupMemFuncs(undefined8 *param_1)

{
  sys_rdb = (undefined *)*param_1;
  sys_rdw = (undefined *)param_1[1];
  sys_rdl = (undefined *)param_1[2];
  sys_wrb = (undefined *)param_1[3];
  sys_wrw = (undefined *)param_1[4];
  sys_wrl = (undefined *)param_1[5];
  return;
}


// ===== 0028d430 X86EMU_setupPioFuncs =====

void X86EMU_setupPioFuncs(undefined8 *param_1)

{
  sys_inb = (undefined *)*param_1;
  sys_inw = (undefined *)param_1[1];
  sys_inl = (undefined *)param_1[2];
  sys_outb = (undefined *)param_1[3];
  sys_outw = (undefined *)param_1[4];
  sys_outl = (undefined *)param_1[5];
  return;
}


// ===== 0028d480 X86EMU_setupIntrFuncs =====

void X86EMU_setupIntrFuncs(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  
  puVar1 = &_X86EMU_intrTab;
  do {
    *puVar1 = 0;
    puVar2 = puVar1 + 2;
    puVar1[1] = 0;
    puVar1 = puVar2;
  } while (puVar2 != &_X86EMU_env);
  if (param_1 != 0) {
    lVar3 = 0;
    do {
      *(undefined8 *)((long)&_X86EMU_intrTab + lVar3) = *(undefined8 *)(param_1 + lVar3);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x800);
  }
  return;
}


// ===== 0028d500 _rmAllocMemorySystemDynamic =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _rmAllocMemorySystemDynamic(undefined8 *param_1)

{
  undefined8 *in_stack_00000010;
  
  (*(code *)*param_1)();
  *in_stack_00000010 = 0;
  return;
}


// ===== 0028d560 _rmAllocMemoryLocalPrivileged =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16]
_rmAllocMemoryLocalPrivileged
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,uint param_6,undefined8 param_7,undefined8 *param_8)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  uVar1 = 0x29;
  if ((param_6 & 0x30000) == 0x10000) {
    *param_8 = 0xffffffff;
    uVar1 = (*(code *)*param_1)();
    param_3 = 0;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = uVar1;
  return auVar2;
}


// ===== 0028d5b0 _rmAllocMemoryList =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _rmAllocMemoryList(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,long *param_7,undefined8 *param_8)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar5;
  int iVar6;
  long lVar7;
  undefined4 local_ec [3];
  undefined8 *local_e0;
  long local_d8;
  undefined8 local_d0 [3];
  undefined4 local_b8 [2];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  undefined4 local_40;
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_d0 + uVar3) = 0;
    *(undefined8 *)((long)local_d0 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_d0 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_b8 + uVar3) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  local_e0 = (undefined8 *)0x0;
  *(undefined8 *)((long)local_d0 + uVar4) = 0;
  *(undefined8 *)((long)local_d0 + uVar4 + 8) = 0;
  *(undefined8 *)((long)local_d0 + uVar4 + 0x10) = 0;
  local_d8 = 0;
  local_ec[0] = param_4;
  iVar2 = (*(code *)param_1[4])(param_1,0,1,*param_7,0x88,&local_e0);
  if (iVar2 == 0) {
    lVar5 = *param_7;
    lVar7 = lVar5 + 0x80;
    if (*(uint *)(local_e0 + 8) < 0x20000000) {
      iVar6 = *(uint *)(local_e0 + 8) << 3;
      iVar2 = (*(code *)param_1[4])(param_1,0,1,lVar7,iVar6,&local_d8);
      if (iVar2 == 0) {
        local_50 = local_d8;
        local_48 = *param_8;
        local_d0[2] = local_e0[2];
        local_d0[0] = *local_e0;
        local_d0[1] = local_e0[1];
        local_b8[0] = *(undefined4 *)(local_e0 + 3);
        local_b0 = *(undefined4 *)((long)local_e0 + 0x1c);
        local_ac = *(undefined4 *)(local_e0 + 4);
        local_a8 = *(undefined4 *)((long)local_e0 + 0x24);
        local_a4 = *(undefined4 *)(local_e0 + 5);
        local_a0 = *(undefined4 *)((long)local_e0 + 0x2c);
        local_9c = *(undefined4 *)(local_e0 + 6);
        local_98 = *(undefined4 *)((long)local_e0 + 0x34);
        local_94 = *(undefined4 *)(local_e0 + 7);
        local_90 = *(undefined4 *)((long)local_e0 + 0x3c);
        local_8c = *(undefined4 *)(local_e0 + 8);
        local_88 = *(undefined4 *)((long)local_e0 + 0x44);
        local_80 = local_e0[10];
        local_78 = local_e0[0xb];
        local_70 = local_e0[0xc];
        local_68 = local_e0[0xd];
        local_60 = local_e0[0xe];
        local_58 = local_e0[0xf];
        local_40 = param_6;
        iVar2 = (*(code *)*param_1)(param_1,param_2,param_3,local_ec,param_5,local_d0,0x98);
      }
      goto LAB_0028d7fa;
    }
    iVar6 = 0;
    iVar2 = 0x1f;
    if (local_d8 == 0) goto LAB_0028d838;
LAB_0028d804:
    (*(code *)param_1[4])(param_1,2,1,lVar7,iVar6,&local_d8);
  }
  else {
    iVar6 = 0;
    lVar7 = 0;
LAB_0028d7fa:
    if (local_d8 != 0) goto LAB_0028d804;
  }
  if (local_e0 == (undefined8 *)0x0) {
    return iVar2;
  }
  lVar5 = *param_7;
LAB_0028d838:
  (*(code *)param_1[4])(param_1,2,1,lVar5,0x88,&local_e0);
  return iVar2;
}


// ===== 0028d8a0 _rmAllocMemoryFramebufferConsole =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _rmAllocMemoryFramebufferConsole(undefined8 *param_1)

{
  (*(code *)*param_1)();
  return;
}


// ===== 0028d8d0 _rmAllocGetHeapSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _rmAllocGetHeapSize(long param_1,undefined4 param_2,undefined4 param_3,long *param_4)

{
  int iVar1;
  char local_435;
  undefined4 local_434;
  undefined8 local_430;
  uint local_428;
  
  memset(&local_430,0,0x404);
  iVar1 = RmDeprecatedFindOrCreateSubDeviceHandle(param_1,param_2,param_3,&local_434,&local_435);
  if (iVar1 == 0) {
    local_430 = 0x800000001;
    iVar1 = (**(code **)(param_1 + 8))(param_1,param_2,local_434,0x20801303,&local_430,0x404);
    *param_4 = (ulong)local_428 << 10;
    if (local_435 != '\0') {
      (**(code **)(param_1 + 0x10))(param_1,param_2,local_434);
    }
  }
  return iVar1;
}


// ===== 0028d9a0 _rmAllocMemoryLocalUser =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _rmAllocMemoryLocalUser
               (undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  long *in_stack_00000010;
  undefined4 local_6c [3];
  long local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_6c[0] = param_4;
  iVar1 = (*(code *)*param_1)();
  if (iVar1 != 0) {
    if (iVar1 == 0x1b) {
      local_40 = 0;
      local_38 = 0;
      local_30 = 0xffffffff;
      iVar1 = _rmAllocGetHeapSize(param_1,param_2,param_3,&local_60);
      if (iVar1 == 0) {
        *in_stack_00000010 = local_60 + -1;
        (*(code *)*param_1)(param_1,param_2,param_3,local_6c,0x70,&local_40,0x18);
      }
    }
    return;
  }
  *in_stack_00000010 = local_58 + -1;
  return;
}


// ===== 0028daa0 _rmAllocMemorySystemOsDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_rmAllocMemorySystemOsDescriptor
          (undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,uint param_6,undefined8 *param_7,undefined8 *param_8)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_4c [3];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_40 = 0;
  local_38 = 0;
  local_20 = 0;
  if ((param_6 & 0xc0000f00) == 0x40000000) {
    local_30 = *param_7;
    local_28 = *param_8;
    local_4c[0] = param_4;
    iVar1 = RmDeprecatedConvertOs02ToOs32Flags
                      (param_6,&local_38,(long)&local_38 + 4,(long)&local_40 + 4);
    if (iVar1 == 0) {
      uVar2 = (*(code *)*param_1)(param_1,param_2,param_3,local_4c,param_5,&local_40,0x28);
      return uVar2;
    }
  }
  return 0x29;
}


// ===== 0028db70 _rmAllocMemorySystem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int _rmAllocMemorySystem
              (undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,uint param_6,undefined8 *param_7,long *param_8)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 local_a0 [2];
  undefined1 local_8c [36];
  long local_68;
  
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)&local_a8 + uVar3) = 0;
    *(undefined8 *)((long)local_a0 + uVar3) = 0;
    *(undefined8 *)((long)local_a0 + uVar3 + 8) = 0;
    *(undefined8 *)((long)&stack0xffffffffffffff70 + uVar3) = 0;
  } while (uVar1 < 0x80);
  if (((param_6 & 0xf00) == 0) && ((param_6 & 0x30000) != 0x10000)) {
    local_a8._0_4_ = 0x7368696d;
    local_68 = *param_8 + 1;
    if ((param_6 & 0x80000) != 0) {
      local_a8._4_4_ = 0xd;
    }
    local_ac = param_4;
    iVar2 = RmDeprecatedConvertOs02ToOs32Flags(param_6,&stack0xffffffffffffff70,local_8c,local_a0);
    if (iVar2 == 0) {
      *param_7 = 0;
      iVar2 = (*(code *)*param_1)(param_1,param_2,param_3,&local_ac,param_5,&local_a8,0x80);
      if ((iVar2 == 0) && (param_6 >> 0x1e == 0)) {
        iVar2 = (*(code *)param_1[3])(param_1,param_2,param_3,local_ac,0,*param_8 + 1,param_7,0);
        if (iVar2 != 0) {
          (*(code *)param_1[2])(param_1,param_2,local_ac);
        }
      }
      return iVar2;
    }
  }
  return 0x29;
}


// ===== 0028dd20 RmDeprecatedAllocMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedAllocMemory(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = 0;
  do {
    if (param_2[3] == (&rmAllocMemoryTable)[uVar2 * 4]) {
      uVar1 = (*(code *)(&PTR__rmAllocMemorySystem_00cdfe08)[(uVar2 & 0xffffffff) * 2])
                        (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2 + 6,
                         param_2 + 8);
      param_2[10] = uVar1;
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 9);
  param_2[10] = 0x22;
  return;
}


// ===== 0028ddb0 ctrlparamRelease =====

void ctrlparamRelease(long param_1,long *param_2,long param_3)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  
  if (*param_2 == 0) {
    return;
  }
  uVar3 = (int)param_2[0x14] - 1;
  if (uVar3 != 0) {
    plVar2 = param_2 + (ulong)uVar3 * 5;
    do {
      if ((*(int *)((ulong)*(uint *)(plVar2 + 3) + *(long *)(param_3 + 0x10)) != 0) &&
         (*plVar2 != 0)) {
        lVar1 = plVar2[1];
        *(long *)((ulong)*(uint *)((long)plVar2 + 0x14) + *(long *)(param_3 + 0x10)) = lVar1;
        RmCopyUserForDeprecatedApi(1,1,lVar1,(int)plVar2[2],plVar2,*(int *)(param_1 + 4) != 1);
      }
      plVar2 = plVar2 + -5;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  RmCopyUserForDeprecatedApi(1,1,param_2[1],(int)param_2[2],param_2,*(int *)(param_1 + 4) == 0);
  *(long *)(param_3 + 0x10) = param_2[1];
  return;
}


// ===== 0028dea0 _ctrl_convert_v2_NV0073_CTRL_CMD_DP_SET_MSA_PROPERTIES =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV0073_CTRL_CMD_DP_SET_MSA_PROPERTIES
              (long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *local_40 [2];
  
  local_40[0] = (undefined4 *)0x0;
  local_40[0] = (undefined4 *)portMemAllocNonPaged(0x40);
  if (local_40[0] == (undefined4 *)0x0) {
    nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x2a0,
                 "_ctrl_convert_v2_NV0073_CTRL_CMD_DP_SET_MSA_PROPERTIES",4,
                 "NVRM: No memory for pParams\n");
    return 0x51;
  }
  iVar1 = RmCopyUserForDeprecatedApi
                    (0,0,*(undefined8 *)(param_3 + 4),0x40,local_40,*(int *)(param_1 + 4) == 0);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "RmCopyUserForDeprecatedApi(RMAPI_DEPRECATED_COPYIN, RMAPI_DEPRECATED_BUFFER_EMPLACE, pArgs->params, sizeof(*pParams), (void**)&pParams, pSecInfo->paramLocation == PARAM_LOCATION_USER)"
               ,"interface/deprecated/rmapi_deprecated_control.c",0x2a4);
    goto LAB_0028e019;
  }
  puVar2 = (undefined4 *)portMemAllocNonPaged(0x50);
  puVar3 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = 0x51;
    nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x2b0,
                 "_ctrl_convert_v2_NV0073_CTRL_CMD_DP_SET_MSA_PROPERTIES",4,
                 "NVRM: No memory for pParams2\n");
    goto LAB_0028e019;
  }
  do {
    *(undefined1 *)puVar3 = 0;
    puVar4 = (undefined4 *)((long)puVar3 + 2);
    *(undefined1 *)((long)puVar3 + 1) = 0;
    puVar3 = puVar4;
  } while (puVar2 + 0x14 != puVar4);
  *puVar2 = *local_40[0];
  puVar2[1] = local_40[0][1];
  *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(local_40[0] + 2);
  *(undefined1 *)((long)puVar2 + 9) = *(undefined1 *)((long)local_40[0] + 9);
  *(undefined1 *)((long)puVar2 + 10) = *(undefined1 *)((long)local_40[0] + 10);
  *(undefined8 *)((long)puVar2 + 0xb) = *(undefined8 *)((long)local_40[0] + 0xb);
  *(undefined8 *)((long)puVar2 + 0x12) = *(undefined8 *)((long)local_40[0] + 0x12);
  *(undefined8 *)((long)puVar2 + 0x1a) = *(undefined8 *)((long)local_40[0] + 0x1a);
  *(undefined8 *)((long)puVar2 + 0x22) = *(undefined8 *)((long)local_40[0] + 0x22);
  *(undefined8 *)((long)puVar2 + 0x2a) = *(undefined8 *)((long)local_40[0] + 0x2a);
  *(undefined2 *)((long)puVar2 + 0x32) = *(undefined2 *)((long)local_40[0] + 0x32);
  if (*(long *)(local_40[0] + 0xe) == 0) {
LAB_0028dfe3:
    iVar1 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x731381,puVar2,0x50);
    if (iVar1 == 0) {
      if ((*(long *)(local_40[0] + 0xe) == 0) ||
         (iVar1 = RmCopyUserForDeprecatedApi
                            (1,0,*(long *)(local_40[0] + 0xe),0x1a,
                             (undefined1 *)((long)puVar2 + 0x36),*(int *)(param_1 + 4) != 1),
         iVar1 == 0)) {
        iVar1 = RmCopyUserForDeprecatedApi
                          (1,0,*(undefined8 *)(param_3 + 4),0x40,local_40,*(int *)(param_1 + 4) == 0
                          );
        if (iVar1 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar1,
                     "RmCopyUserForDeprecatedApi(RMAPI_DEPRECATED_COPYOUT, RMAPI_DEPRECATED_BUFFER_EMPLACE, pArgs->params, sizeof(*pParams), (void**)&pParams, pSecInfo->paramLocation == PARAM_LOCATION_USER)"
                     ,"interface/deprecated/rmapi_deprecated_control.c",0x2de);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar1,
                   "RmCopyUserForDeprecatedApi(RMAPI_DEPRECATED_COPYOUT, RMAPI_DEPRECATED_BUFFER_EMPLACE, pParams->pFeatureDebugValues, sizeof(pParams2->featureDebugValues), (void**)&pParams2->featureDebugValues, pSecInfo->paramLocation != PARAM_LOCATION_KERNEL)"
                   ,"interface/deprecated/rmapi_deprecated_control.c",0x2d4);
      }
    }
  }
  else {
    *(undefined1 *)(puVar2 + 0xd) = 1;
    iVar1 = RmCopyUserForDeprecatedApi
                      (0,0,*(undefined8 *)(local_40[0] + 0xe),0x1a,
                       (undefined1 *)((long)puVar2 + 0x36),*(int *)(param_1 + 4) != 1);
    if (iVar1 == 0) goto LAB_0028dfe3;
    nvCheckOkFailedNoLog
              (4,iVar1,
               "RmCopyUserForDeprecatedApi(RMAPI_DEPRECATED_COPYIN, RMAPI_DEPRECATED_BUFFER_EMPLACE, pParams->pFeatureDebugValues, sizeof(pParams2->featureDebugValues), (void**)&pParams2->featureDebugValues, pSecInfo->paramLocation != PARAM_LOCATION_KERNEL)"
               ,"interface/deprecated/rmapi_deprecated_control.c",0x2c2);
  }
  portMemFree(puVar2);
LAB_0028e019:
  if (local_40[0] != (undefined4 *)0x0) {
    portMemFree();
  }
  return iVar1;
}


// ===== 0028e1c0 ctrlparamAcquire.constprop.0 =====

int ctrlparamAcquire_constprop_0(long param_1,long *param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long *plVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  uint uVar9;
  
  if (3 < (int)param_2[0x14] - 1U) {
    return 0x1f;
  }
  iVar5 = RmCopyUserForDeprecatedApi
                    (0,1,param_2[1],(int)param_2[2],param_2,*(int *)(param_1 + 4) == 0);
  if (iVar5 == 0) {
    lVar7 = *param_2;
    *(long *)(param_3 + 0x10) = lVar7;
    if (1 < *(uint *)(param_2 + 0x14)) {
      uVar9 = 1;
      plVar4 = param_2;
      do {
        plVar8 = plVar4 + 5;
        uVar1 = *(uint *)((long)plVar4 + 0x3c);
        if (*(uint *)(plVar4 + 8) == 0xffffffff) {
          uVar6 = (ulong)*(uint *)(plVar4 + 7);
LAB_0028e264:
          lVar7 = *(long *)(lVar7 + (ulong)uVar1);
          plVar4[6] = lVar7;
          iVar5 = RmCopyUserForDeprecatedApi(0,1,lVar7,uVar6,plVar8,*(int *)(param_1 + 4) != 1);
          if (iVar5 != 0) {
            return iVar5;
          }
          *(long *)(*(long *)(param_3 + 0x10) + (ulong)uVar1) = *plVar8;
        }
        else {
          uVar2 = *(uint *)(lVar7 + (ulong)*(uint *)(plVar4 + 8));
          uVar6 = (ulong)uVar2;
          if (uVar2 != 0) {
            if (*(uint *)(plVar4 + 9) < uVar2) {
              return 0x5b;
            }
            if (*(char *)((long)plVar4 + 0x44) == '\0') {
              *(uint *)(plVar4 + 7) = uVar2;
            }
            else {
              uVar3 = uVar6 * *(uint *)(plVar4 + 7);
              *(int *)(plVar4 + 7) = (int)uVar3;
              uVar6 = uVar3 & 0xffffffff;
              if ((int)(uVar3 >> 0x20) != 0) {
                return 0x1f;
              }
            }
            lVar7 = *(long *)(param_3 + 0x10);
            goto LAB_0028e264;
          }
        }
        uVar9 = uVar9 + 1;
        if (*(uint *)(param_2 + 0x14) <= uVar9) {
          return 0;
        }
        lVar7 = *(long *)(param_3 + 0x10);
        plVar4 = plVar8;
      } while( true );
    }
  }
  return iVar5;
}


// ===== 0028e340 _ctrl_convert_v2_NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION
              (long param_1,long param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined4 local_40;
  undefined8 local_38;
  
  lVar5 = portMemAllocNonPaged(0x408);
  if (lVar5 == 0) {
    nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x1c8,
                 "_ctrl_convert_v2_NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION",4,
                 "NVRM: No memory for pParams2\n");
    return 0x51;
  }
  iVar3 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x13e,lVar5,0x408);
  if (iVar3 == 0) {
    uVar1 = *(undefined8 *)(param_3 + 4);
    puVar6 = &local_e0;
    do {
      *puVar6 = 0;
      puVar7 = puVar6 + 3;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6 = puVar7;
    } while (&local_38 != puVar7);
    local_d0 = 0x28;
    local_c8 = 0xffffffff;
    local_c4 = 0;
    local_c0 = 0;
    local_40 = 1;
    local_d8 = uVar1;
    iVar3 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
    if (iVar3 == 0) {
      puVar2 = *(uint **)(param_3 + 4);
      iVar3 = portStringLengthSafe(lVar5,0x100);
      uVar8 = iVar3 + 1;
      iVar3 = portStringLengthSafe(lVar5 + 0x100,0x100);
      uVar10 = iVar3 + 1;
      iVar3 = portStringLengthSafe(lVar5 + 0x300,0x100);
      uVar9 = iVar3 + 1;
      uVar4 = uVar10;
      if (uVar10 <= uVar8) {
        uVar4 = uVar8;
      }
      if (uVar4 < uVar9) {
        uVar4 = uVar9;
      }
      if (((*(long *)(puVar2 + 2) == 0) || (*(long *)(puVar2 + 4) == 0)) ||
         (*(long *)(puVar2 + 6) == 0)) {
        *puVar2 = uVar4;
        portMemFree(lVar5);
        ctrlparamRelease(param_1,&local_e0,param_3);
        return 0;
      }
      if (*puVar2 < uVar4) {
        portMemFree(lVar5);
        ctrlparamRelease(param_1,&local_e0,param_3);
        return 0x3a;
      }
      iVar3 = rmapiParamsCopyOut(0,lVar5,*(long *)(puVar2 + 2),uVar8,*(int *)(param_1 + 4) != 1);
      if (((iVar3 == 0) &&
          (iVar3 = rmapiParamsCopyOut(0,lVar5 + 0x100,*(undefined8 *)(puVar2 + 4),uVar10,
                                      *(int *)(param_1 + 4) != 1), iVar3 == 0)) &&
         (iVar3 = rmapiParamsCopyOut(0,lVar5 + 0x300,*(undefined8 *)(puVar2 + 6),uVar9,
                                     *(int *)(param_1 + 4) != 1), iVar3 == 0)) {
        puVar2[8] = *(uint *)(lVar5 + 0x400);
        puVar2[9] = *(uint *)(lVar5 + 0x404);
        iVar3 = 0;
      }
      else {
        iVar3 = 0x3a;
        nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x21a,
                     "_ctrl_convert_v2_NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION",4,
                     "NVRM: Unable to copy out build version info to User Space.\n");
      }
    }
    ctrlparamRelease(param_1,&local_e0,param_3);
  }
  portMemFree(lVar5);
  return iVar3;
}


// ===== 0028e6b0 __pfx__ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int __pfx__ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined4 uStack_c8;
  undefined1 uStack_c4;
  undefined4 uStack_c0;
  undefined8 uStack_a8;
  undefined4 uStack_a0;
  undefined1 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_40;
  undefined8 uStack_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar5 = &uStack_e0;
  do {
    *puVar5 = 0;
    puVar6 = puVar5 + 3;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5 = puVar6;
  } while (puVar6 != &uStack_38);
  uStack_c4 = 0;
  uStack_d0 = 0x10;
  uStack_c8 = 0xffffffff;
  uStack_c0 = 0;
  uStack_a0 = 0;
  uStack_9c = 1;
  uStack_a8 = 0x800000008;
  uStack_98 = 0xf;
  uStack_40 = 2;
  uStack_d8 = uVar2;
  iVar4 = ctrlparamAcquire_constprop_0(param_1,&uStack_e0,param_3);
  if (iVar4 == 0) {
    piVar3 = *(int **)(param_3 + 4);
    iVar4 = *piVar3;
    lVar7 = portMemAllocNonPaged(0x7c);
    if (lVar7 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x238,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO",4,
                   "NVRM: No memory for pParams2\n");
      ctrlparamRelease(param_1,&uStack_e0,param_3);
      return 0x51;
    }
    uVar1 = iVar4 * 8;
    lVar8 = 0;
    if (0x78 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x238,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar7);
      ctrlparamRelease(param_1,&uStack_e0,param_3);
      return 0x1a;
    }
    do {
      *(undefined1 *)(lVar7 + lVar8) = *(undefined1 *)((long)piVar3 + lVar8);
      lVar8 = lVar8 + 1;
    } while (lVar8 != 0x10);
    if (uVar1 == 0) {
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20800810,lVar7,0x7c);
    }
    else {
      lVar8 = *(long *)(piVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar7 + 4 + uVar10) = *(undefined1 *)(lVar8 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20800810,lVar7,0x7c);
      if (iVar4 == 0) {
        lVar8 = *(long *)(piVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar8 + uVar9) = *(undefined1 *)(lVar7 + 4 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar7);
  }
  ctrlparamRelease(param_1,&uStack_e0,param_3);
  return iVar4;
}


// ===== 0028e6c0 _ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar5 = &local_e0;
  do {
    *puVar5 = 0;
    puVar6 = puVar5 + 3;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5 = puVar6;
  } while (puVar6 != &local_38);
  local_c4 = 0;
  local_d0 = 0x10;
  local_c8 = 0xffffffff;
  local_c0 = 0;
  local_a0 = 0;
  local_9c = 1;
  local_a8 = 0x800000008;
  local_98 = 0xf;
  local_40 = 2;
  local_d8 = uVar2;
  iVar4 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
  if (iVar4 == 0) {
    piVar3 = *(int **)(param_3 + 4);
    iVar4 = *piVar3;
    lVar7 = portMemAllocNonPaged(0x7c);
    if (lVar7 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x238,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO",4,
                   "NVRM: No memory for pParams2\n");
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x51;
    }
    uVar1 = iVar4 * 8;
    lVar8 = 0;
    if (0x78 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x238,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_BIOS_GET_INFO",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar7);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1a;
    }
    do {
      *(undefined1 *)(lVar7 + lVar8) = *(undefined1 *)((long)piVar3 + lVar8);
      lVar8 = lVar8 + 1;
    } while (lVar8 != 0x10);
    if (uVar1 == 0) {
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20800810,lVar7,0x7c);
    }
    else {
      lVar8 = *(long *)(piVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar7 + 4 + uVar10) = *(undefined1 *)(lVar8 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20800810,lVar7,0x7c);
      if (iVar4 == 0) {
        lVar8 = *(long *)(piVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar8 + uVar9) = *(undefined1 *)(lVar7 + 4 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar7);
  }
  ctrlparamRelease(param_1,&local_e0,param_3);
  return iVar4;
}


// ===== 0028e9c0 _ctrl_convert_v2_NV2080_CTRL_CMD_BUS_GET_INFO =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV2080_CTRL_CMD_BUS_GET_INFO
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar5 = &local_e0;
  do {
    *puVar5 = 0;
    puVar6 = puVar5 + 3;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5 = puVar6;
  } while (puVar6 != &local_38);
  local_c4 = 0;
  local_d0 = 0x10;
  local_c8 = 0xffffffff;
  local_c0 = 0;
  local_a0 = 0;
  local_9c = 1;
  local_a8 = 0x800000008;
  local_98 = 0x34;
  local_40 = 2;
  local_d8 = uVar2;
  iVar4 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
  if (iVar4 == 0) {
    piVar3 = *(int **)(param_3 + 4);
    iVar4 = *piVar3;
    lVar7 = portMemAllocNonPaged(0x1a4);
    if (lVar7 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x24c,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_BUS_GET_INFO",4,
                   "NVRM: No memory for pParams2\n");
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x51;
    }
    uVar1 = iVar4 * 8;
    lVar8 = 0;
    if (0x1a0 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x24c,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_BUS_GET_INFO",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar7);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1a;
    }
    do {
      *(undefined1 *)(lVar7 + lVar8) = *(undefined1 *)((long)piVar3 + lVar8);
      lVar8 = lVar8 + 1;
    } while (lVar8 != 0x10);
    if (uVar1 == 0) {
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20801823,lVar7,0x1a4);
    }
    else {
      lVar8 = *(long *)(piVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar7 + 4 + uVar10) = *(undefined1 *)(lVar8 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20801823,lVar7,0x1a4);
      if (iVar4 == 0) {
        lVar8 = *(long *)(piVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar8 + uVar9) = *(undefined1 *)(lVar7 + 4 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar7);
  }
  ctrlparamRelease(param_1,&local_e0,param_3);
  return iVar4;
}


// ===== 0028ecc0 _ctrl_convert_v2_NV0080_CTRL_CMD_BSP_GET_CAPS =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV0080_CTRL_CMD_BSP_GET_CAPS
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar6 = &local_e0;
  do {
    *puVar6 = 0;
    puVar7 = puVar6 + 3;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = puVar7;
  } while (&local_38 != puVar7);
  local_c4 = 0;
  local_d0 = 0x18;
  local_c8 = 0xffffffff;
  local_c0 = 0;
  local_a0 = 0;
  local_9c = 1;
  local_a8 = 0x800000001;
  local_98 = 8;
  local_40 = 2;
  local_d8 = uVar2;
  iVar5 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
  if (iVar5 == 0) {
    puVar3 = *(uint **)(param_3 + 4);
    uVar1 = *puVar3;
    lVar8 = portMemAllocNonPaged(0xc);
    if (lVar8 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x263,
                   "_ctrl_convert_v2_NV0080_CTRL_CMD_BSP_GET_CAPS",4,
                   "NVRM: No memory for pParams2\n");
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x51;
    }
    if (8 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x263,
                   "_ctrl_convert_v2_NV0080_CTRL_CMD_BSP_GET_CAPS",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar8);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1a;
    }
    if (*puVar3 != 8) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x271,
                   "_ctrl_convert_v2_NV0080_CTRL_CMD_BSP_GET_CAPS",4,
                   "NVRM: pParams capsTblSize %d invalid\n");
      portMemFree(lVar8);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1f;
    }
    *(uint *)(lVar8 + 8) = puVar3[4];
    if ((ulong)uVar1 == 0) {
      iVar5 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x801c02,lVar8,0xc);
    }
    else {
      lVar4 = *(long *)(puVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar8 + uVar10) = *(undefined1 *)(lVar4 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar5 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x801c02,lVar8,0xc);
      if (iVar5 == 0) {
        lVar4 = *(long *)(puVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar4 + uVar9) = *(undefined1 *)(lVar8 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar8);
  }
  ctrlparamRelease(param_1,&local_e0,param_3);
  return iVar5;
}


// ===== 0028f000 _ctrl_convert_v2_NV2080_CTRL_CMD_GPU_GET_INFO =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV2080_CTRL_CMD_GPU_GET_INFO
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar5 = &local_e0;
  do {
    *puVar5 = 0;
    puVar6 = puVar5 + 3;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5 = puVar6;
  } while (puVar6 != &local_38);
  local_c4 = 0;
  local_d0 = 0x10;
  local_c8 = 0xffffffff;
  local_c0 = 0;
  local_a0 = 0;
  local_9c = 1;
  local_a8 = 0x800000008;
  local_98 = 0x46;
  local_40 = 2;
  local_d8 = uVar2;
  iVar4 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
  if (iVar4 == 0) {
    piVar3 = *(int **)(param_3 + 4);
    iVar4 = *piVar3;
    lVar7 = portMemAllocNonPaged(0x234);
    if (lVar7 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x285,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_GPU_GET_INFO",4,
                   "NVRM: No memory for pParams2\n");
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x51;
    }
    uVar1 = iVar4 * 8;
    lVar8 = 0;
    if (0x230 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x285,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_GPU_GET_INFO",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar7);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1a;
    }
    do {
      *(undefined1 *)(lVar7 + lVar8) = *(undefined1 *)((long)piVar3 + lVar8);
      lVar8 = lVar8 + 1;
    } while (lVar8 != 0x10);
    if (uVar1 == 0) {
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20800102,lVar7,0x234);
    }
    else {
      lVar8 = *(long *)(piVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar7 + 4 + uVar10) = *(undefined1 *)(lVar8 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20800102,lVar7,0x234);
      if (iVar4 == 0) {
        lVar8 = *(long *)(piVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar8 + uVar9) = *(undefined1 *)(lVar7 + 4 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar7);
  }
  ctrlparamRelease(param_1,&local_e0,param_3);
  return iVar4;
}


// ===== 0028f300 _ctrl_convert_v2_NV0080_CTRL_CMD_MSENC_GET_CAPS =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV0080_CTRL_CMD_MSENC_GET_CAPS
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar6 = &local_e0;
  do {
    *puVar6 = 0;
    puVar7 = puVar6 + 3;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = puVar7;
  } while (&local_38 != puVar7);
  local_c4 = 0;
  local_d0 = 0x10;
  local_c8 = 0xffffffff;
  local_c0 = 0;
  local_a0 = 0;
  local_9c = 1;
  local_a8 = 0x800000001;
  local_98 = 6;
  local_40 = 2;
  local_d8 = uVar2;
  iVar5 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
  if (iVar5 == 0) {
    puVar3 = *(uint **)(param_3 + 4);
    uVar1 = *puVar3;
    lVar8 = portMemAllocNonPaged(0xc);
    if (lVar8 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x2fc,
                   "_ctrl_convert_v2_NV0080_CTRL_CMD_MSENC_GET_CAPS",4,
                   "NVRM: No memory for pParams2\n");
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x51;
    }
    if (6 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x2fc,
                   "_ctrl_convert_v2_NV0080_CTRL_CMD_MSENC_GET_CAPS",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar8);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1a;
    }
    if (*puVar3 != 6) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x30a,
                   "_ctrl_convert_v2_NV0080_CTRL_CMD_MSENC_GET_CAPS",2,
                   "NVRM: pParams capsTblSize %d invalid\n");
      portMemFree(lVar8);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1f;
    }
    *(undefined4 *)(lVar8 + 8) = 0;
    if ((ulong)uVar1 == 0) {
      iVar5 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x801b02,lVar8,0xc);
    }
    else {
      lVar4 = *(long *)(puVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar8 + uVar10) = *(undefined1 *)(lVar4 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar5 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x801b02,lVar8,0xc);
      if (iVar5 == 0) {
        lVar4 = *(long *)(puVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar4 + uVar9) = *(undefined1 *)(lVar8 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar8);
  }
  ctrlparamRelease(param_1,&local_e0,param_3);
  return iVar5;
}


// ===== 0028f640 _ctrl_convert_v2_NV2080_CTRL_CMD_FB_GET_INFO =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _ctrl_convert_v2_NV2080_CTRL_CMD_FB_GET_INFO
              (undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar2 = *(undefined8 *)(param_3 + 4);
  puVar5 = &local_e0;
  do {
    *puVar5 = 0;
    puVar6 = puVar5 + 3;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5 = puVar6;
  } while (puVar6 != &local_38);
  local_c4 = 0;
  local_d0 = 0x10;
  local_c8 = 0xffffffff;
  local_c0 = 0;
  local_a0 = 0;
  local_9c = 1;
  local_a8 = 0x800000008;
  local_98 = 0x80;
  local_40 = 2;
  local_d8 = uVar2;
  iVar4 = ctrlparamAcquire_constprop_0(param_1,&local_e0,param_3);
  if (iVar4 == 0) {
    piVar3 = *(int **)(param_3 + 4);
    iVar4 = *piVar3;
    lVar7 = portMemAllocNonPaged(0x404);
    if (lVar7 == 0) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x31e,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_FB_GET_INFO",4,"NVRM: No memory for pParams2\n"
                  );
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x51;
    }
    uVar1 = iVar4 * 8;
    lVar8 = 0;
    if (0x400 < uVar1) {
      nvDbg_Printf("interface/deprecated/rmapi_deprecated_control.c",0x31e,
                   "_ctrl_convert_v2_NV2080_CTRL_CMD_FB_GET_INFO",4,
                   "NVRM: pParams2 static array too small\n");
      portMemFree(lVar7);
      ctrlparamRelease(param_1,&local_e0,param_3);
      return 0x1a;
    }
    do {
      *(undefined1 *)(lVar7 + lVar8) = *(undefined1 *)((long)piVar3 + lVar8);
      lVar8 = lVar8 + 1;
    } while (lVar8 != 0x10);
    if (uVar1 == 0) {
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20801303,lVar7,0x404);
    }
    else {
      lVar8 = *(long *)(piVar3 + 2);
      uVar10 = 0;
      do {
        *(undefined1 *)(lVar7 + 4 + uVar10) = *(undefined1 *)(lVar8 + uVar10);
        uVar10 = uVar10 + 1;
      } while (uVar1 != uVar10);
      iVar4 = (**(code **)(param_2 + 8))(param_2,*param_3,param_3[1],0x20801303,lVar7,0x404);
      if (iVar4 == 0) {
        lVar8 = *(long *)(piVar3 + 2);
        uVar9 = 0;
        do {
          *(undefined1 *)(lVar8 + uVar9) = *(undefined1 *)(lVar7 + 4 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar10 != uVar9);
      }
    }
    portMemFree(lVar7);
  }
  ctrlparamRelease(param_1,&local_e0,param_3);
  return iVar4;
}


// ===== 0028f920 IsGssLegacyCall =====

uint IsGssLegacyCall(uint param_1)

{
  return param_1 >> 0xf & 1;
}


// ===== 0028f940 RmDeprecatedGetControlHandler =====

code * RmDeprecatedGetControlHandler(undefined4 *param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 local_28;
  long local_20 [2];
  
  local_28 = 0;
  local_20[0] = 0;
  iVar1 = serverGetClientUnderLock(g_resServ,*param_1,&local_28);
  if (iVar1 == 0) {
    gpuGetByHandle(local_28,param_1[1],0,local_20);
    uVar2 = 0;
    uVar4 = 0x101;
    do {
      if (param_1[2] == uVar4) {
        if (param_1[3] != 0) {
          nvAssertFailedNoLog("IRQL and BYPASS_LOCK control calls currently unsupported for deprecated control calls"
                              ,"interface/deprecated/rmapi_deprecated_control.c",0x7b);
          return (code *)0x0;
        }
        return *(code **)(rmDeprecatedControlTable + (uVar2 & 0xffffffff) * 0x10 + 8);
      }
      uVar2 = uVar2 + 1;
      uVar4 = *(uint *)(rmDeprecatedControlTable + uVar2 * 0x10);
    } while (uVar4 != 0);
    if ((local_20[0] != 0) && ((param_1[2] & 0x8000) != 0)) {
      pcVar3 = RmGssLegacyRpcCmd;
      if (*(char *)(local_20[0] + 0x908) == '\0' && *(char *)(local_20[0] + 0x909) == '\0') {
        pcVar3 = (code *)0x0;
      }
      return pcVar3;
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar1,"serverGetClientUnderLock(&g_resServ, pArgs->hClient, &pClient)",
               "interface/deprecated/rmapi_deprecated_control.c",0x6c);
  }
  return (code *)0x0;
}


// ===== 0028fa60 RmDeprecatedAllocObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] RmDeprecatedAllocObject(undefined8 *param_1,undefined4 *param_2)

{
  undefined1 auVar1 [16];
  undefined4 uVar2;
  ulong uStack_20;
  
  uVar2 = (*(code *)*param_1)(param_1,*param_2,param_2[1],param_2 + 2,param_2[3],0);
  param_2[4] = uVar2;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uStack_20;
  return auVar1 << 0x40;
}


// ===== 0028faa0 RmDeprecatedAddVblankCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedAddVblankCallback(undefined8 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  
  if (param_2[0xc] != 0) {
    local_38 = *(undefined8 *)(param_2 + 4);
    local_2c = 0;
    local_30 = param_2[6];
    local_28 = *(undefined8 *)(param_2 + 8);
    local_20 = *(undefined8 *)(param_2 + 10);
    uVar1 = (*(code *)*param_1)(param_1,*param_2,param_2[1],param_2 + 2,0x9010,&local_38,0x20);
    param_2[0xd] = uVar1;
    return;
  }
  uVar1 = (*(code *)param_1[2])(param_1,*param_2,param_2[2]);
  param_2[0xd] = uVar1;
  return;
}


// ===== 0028fb30 RmDeprecatedAllocContextDma =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void RmDeprecatedAllocContextDma(undefined8 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined4 local_68;
  int local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar2 = *param_2;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  iVar1 = RmDeprecatedGetHandleParent(param_1,uVar2,param_2[6],&local_68);
  if (iVar1 != 0) {
    param_2[0xc] = iVar1;
    return;
  }
  iVar1 = RmDeprecatedGetClassID(param_1,uVar2,param_2[6],&local_64);
  if ((iVar1 == 0) && (local_64 == 0x70)) {
    puVar4 = &local_60;
    uVar3 = 0x70;
    local_50 = 0;
    uVar5 = 0x18;
    local_60 = *(undefined8 *)(param_2 + 8);
    local_58 = *(undefined8 *)(param_2 + 10);
  }
  else {
    puVar4 = &local_48;
    local_48 = CONCAT44(param_2[4],param_2[1]);
    local_40 = CONCAT44(local_40._4_4_,param_2[6]);
    uVar5 = 0x20;
    uVar3 = param_2[3];
    local_38 = *(undefined8 *)(param_2 + 8);
    local_30 = *(undefined8 *)(param_2 + 10);
  }
  uVar2 = (*(code *)*param_1)(param_1,uVar2,local_68,param_2 + 2,uVar3,puVar4,uVar5);
  param_2[0xc] = uVar2;
  return;
}


// ===== 0028fc40 RmDeprecatedBindContextDma =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedBindContextDma(long param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  int local_1c [3];
  
  local_20 = 0;
  iVar1 = RmDeprecatedGetClassID(param_1,*param_2,param_2[2],local_1c);
  if ((iVar1 != 0) || (uVar2 = 0, local_1c[0] != 0x70)) {
    local_20 = param_2[1];
    uVar2 = (**(code **)(param_1 + 8))(param_1,*param_2,param_2[2],0x20102,&local_20,4);
  }
  param_2[3] = uVar2;
  return;
}


// ===== 0028fcb0 RmDeprecatedI2CAccess =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

void RmDeprecatedI2CAccess(long param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  char local_3d;
  undefined4 local_3c;
  long local_38;
  long local_30;
  
  local_3d = '\0';
  local_38 = 0;
  local_30 = 0;
  iVar1 = RmDeprecatedFindOrCreateSubDeviceHandle(param_1,*param_2,param_2[1],&local_3c,&local_3d);
  if (iVar1 != 0) {
    uVar5 = 0;
    lVar4 = 0;
    goto LAB_0028fda0;
  }
  iVar1 = (**(code **)(param_1 + 0x20))(param_1,0,1,*(undefined8 *)(param_2 + 4),0x28,&local_38);
  if (iVar1 != 0) {
    uVar5 = 0;
    lVar4 = 0;
    goto LAB_0028fda0;
  }
  uVar3 = *(uint *)(local_38 + 4);
  uVar5 = *(uint *)(local_38 + 0x1c);
  lVar4 = *(long *)(local_38 + 0x10);
  if (uVar3 < 5) {
    if (uVar3 < 3) goto LAB_0028fe4e;
    *(uint *)(local_38 + 0x1c) = (uint)(lVar4 != 0);
    uVar3 = 1;
    if (lVar4 != 0) {
LAB_0028fd55:
      iVar1 = (**(code **)(param_1 + 0x20))(param_1,0,1,lVar4,uVar3,&local_30);
      if (iVar1 != 0) goto LAB_0028fda0;
      *(long *)(local_38 + 0x10) = local_30;
    }
  }
  else {
    if (uVar3 - 0x14 < 2) {
      if (uVar5 == 0) goto LAB_0028fe5e;
      uVar3 = uVar5;
      if (uVar5 < 0x1001) goto LAB_0028fd55;
    }
LAB_0028fe4e:
    *(undefined4 *)(local_38 + 0x1c) = 0;
    *(undefined8 *)(local_38 + 0x10) = 0;
  }
LAB_0028fe5e:
  iVar1 = (**(code **)(param_1 + 8))(param_1,*param_2,local_3c,0x20800610,local_38,0x28);
LAB_0028fda0:
  if (local_30 != 0) {
    *(long *)(local_38 + 0x10) = lVar4;
    iVar2 = (**(code **)(param_1 + 0x20))
                      (param_1,1,1,lVar4,*(undefined4 *)(local_38 + 0x1c),&local_30);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  if (local_38 != 0) {
    *(uint *)(local_38 + 0x1c) = uVar5;
    iVar2 = (**(code **)(param_1 + 0x20))(param_1,1,1,*(undefined8 *)(param_2 + 4),0x28,&local_38);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  if (local_3d != '\0') {
    (**(code **)(param_1 + 0x10))(param_1,*param_2,local_3c);
  }
  param_2[6] = iVar1;
  return;
}


// ===== 0028feb0 RmDeprecatedIdleChannels =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedIdleChannels(long param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  long local_70;
  long local_68;
  long local_60;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  ulong local_30;
  
  local_58 = *(undefined8 *)(param_2 + 1);
  local_30 = *(ulong *)(param_2 + 10);
  local_4c = 0;
  uStack_48 = 0;
  local_44 = 0;
  uStack_40 = 0;
  local_50 = param_2[3];
  local_3c = 0;
  uStack_38 = 0;
  local_34 = 0;
  iVar1 = local_50 * 4;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  if (local_50 == 0) {
LAB_0028fff0:
    iVar2 = (**(code **)(param_1 + 8))(param_1,*param_2,*param_2,0x283,&local_58,0x30);
  }
  else {
    iVar2 = 0x1f;
    if (local_50 >> 0x1e != 0) goto LAB_0028ff3b;
    if ((local_30 & 0xf0) != 0) goto LAB_0028fff0;
    iVar2 = (**(code **)(param_1 + 0x20))(param_1,0,1,*(undefined8 *)(param_2 + 4),iVar1,&local_70);
    if (iVar2 == 0) {
      uStack_48 = (undefined4)local_70;
      local_44 = (undefined4)((ulong)local_70 >> 0x20);
      iVar2 = (**(code **)(param_1 + 0x20))
                        (param_1,0,1,*(undefined8 *)(param_2 + 6),iVar1,&local_68);
      if (iVar2 == 0) {
        uStack_40 = (undefined4)local_68;
        local_3c = (undefined4)((ulong)local_68 >> 0x20);
        iVar2 = (**(code **)(param_1 + 0x20))
                          (param_1,0,1,*(undefined8 *)(param_2 + 8),iVar1,&local_60);
        if (iVar2 == 0) {
          uStack_38 = (undefined4)local_60;
          local_34 = (undefined4)((ulong)local_60 >> 0x20);
          goto LAB_0028fff0;
        }
      }
    }
  }
  if (local_70 != 0) {
    (**(code **)(param_1 + 0x20))(param_1,2,1,*(undefined8 *)(param_2 + 4),iVar1,&local_70);
  }
  if (local_68 != 0) {
    (**(code **)(param_1 + 0x20))(param_1,2,1,*(undefined8 *)(param_2 + 6),iVar1,&local_68);
  }
  if (local_60 != 0) {
    (**(code **)(param_1 + 0x20))(param_1,2,1,*(undefined8 *)(param_2 + 8),iVar1,&local_60);
  }
LAB_0028ff3b:
  param_2[0xc] = iVar2;
  return;
}


// ===== 002900a0 RmDeprecatedGetHandleParent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedGetHandleParent(long param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  ulong local_28;
  undefined8 local_20;
  
  local_28 = (ulong)param_3 | 0x100000000;
  local_20 = 0;
  (**(code **)(param_1 + 8))(param_1,param_2,param_2,0xd02,&local_28,0x10);
  *param_4 = (undefined4)local_20;
  return;
}


// ===== 002900f0 RmDeprecatedGetClassID =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedGetClassID(long param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  ulong local_28 [3];
  
  local_28[0] = (ulong)param_3 | 0x200000000;
  local_28[1] = 0;
  (**(code **)(param_1 + 8))(param_1,param_2,param_2,0xd02,local_28,0x10);
  *param_4 = (int)local_28[1];
  return;
}


// ===== 00290140 RmDeprecatedFindOrCreateSubDeviceHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16]
RmDeprecatedFindOrCreateSubDeviceHandle
          (undefined8 *param_1,ulong param_2,uint param_3,uint *param_4,undefined1 *param_5)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 local_50;
  ulong local_48;
  ulong local_40;
  
  uVar1 = (ulong)param_3;
  local_48 = uVar1 | 0x200000000;
  local_50 = 0;
  local_40 = 0;
  auVar5._0_8_ = (*(code *)param_1[1])(param_1,param_2,param_2 & 0xffffffff,0xd02,&local_48,0x10);
  uVar2 = local_40;
  if ((int)auVar5._0_8_ == 0) {
    if ((int)local_40 == 0x2080) {
      *param_5 = 0;
      *param_4 = param_3;
      auVar5._8_8_ = local_40;
      return auVar5;
    }
    auVar5._0_8_ = 0x1f;
    if ((int)local_40 == 0x80) {
      local_50 = local_50 & 0xffffffff00000000;
      auVar5._0_8_ = (*(code *)param_1[1])(param_1,param_2 & 0xffffffff,uVar1,0x800293,&local_50,8);
      if ((int)auVar5._0_8_ == 0) {
        uVar2 = (ulong)local_50._4_4_;
        if (local_50._4_4_ != 0) {
          *param_5 = 0;
          *param_4 = local_50._4_4_;
          goto LAB_002901f4;
        }
      }
      *param_5 = 1;
      *param_4 = 0;
      auVar4._0_8_ = (*(code *)*param_1)(param_1,param_2 & 0xffffffff,uVar1,param_4,0x2080,0);
      auVar4._8_8_ = 0;
      return auVar4;
    }
  }
LAB_002901f4:
  auVar3._8_8_ = uVar2;
  auVar3._0_8_ = auVar5._0_8_;
  return auVar3;
}


// ===== 00290270 RmDeprecatedConvertOs32ToOs02Flags =====

int RmDeprecatedConvertOs32ToOs02Flags(uint param_1,uint param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  if ((param_1 >> 0x1b & 3) == 1) {
    iVar4 = 0;
    uVar2 = 0x10;
  }
  else {
    iVar4 = 0x29;
    uVar2 = 0;
    if ((~(param_1 >> 0x1b) & 1) != 0) {
      iVar4 = 0;
      uVar2 = 0;
    }
  }
  if ((param_1 & 0x2000000) == 0) {
    if ((param_1 >> 0x19 & 3) == 0) {
      uVar2 = (uint)CONCAT11(2,(char)uVar2);
      bVar5 = param_1 >> 0x1d == 3;
      bVar1 = false;
      goto joined_r0x002902be;
    }
    iVar4 = 0x29;
  }
  bVar5 = param_1 >> 0x1d == 3;
  bVar1 = bVar5;
joined_r0x002902be:
  if (bVar5) {
    uVar2 = uVar2 | 0x3000;
  }
  else {
    param_1 = param_1 >> 0x1d;
    if (param_1 < 3 || bVar1) {
      if (param_1 == 1) {
        uVar2 = uVar2 | 0x1000;
      }
      else if (param_1 == 2) {
        uVar2 = uVar2 | 0x2000;
      }
    }
    else if (param_1 == 4) {
      uVar2 = uVar2 | 0x4000;
    }
    else if (param_1 == 5) {
      uVar2 = uVar2 | 0x5000;
    }
    else {
      iVar4 = 0x29;
    }
  }
  if ((param_2 >> 2 & 3) == 1) {
    uVar2 = uVar2 | 0x40000;
  }
  else if ((param_2 >> 2 & 1) != 0) {
    iVar4 = 0x29;
  }
  if ((int)param_2 < 0) {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = uVar2 | 0x40080000;
  if ((param_3 & 0x2000000) == 0) {
    uVar3 = uVar2 | 0x40000000;
  }
  if ((param_3 & 0x4000000) != 0) {
    uVar3 = uVar3 | 0x200000;
  }
  if ((param_3 & 0x8000000) != 0) {
    uVar3 = uVar3 | 0x400000;
  }
  if ((param_2 & 0x400000) != 0) {
    uVar3 = uVar3 | 0x200000;
  }
  if ((param_2 & 0x800000) != 0) {
    uVar3 = uVar3 | 0x400000;
  }
  if ((param_2 & 0x10000) != 0) {
    uVar3 = uVar3 | 0x100000;
  }
  if ((param_2 & 0x6000000) == 0x2000000) {
    uVar3 = uVar3 | 0x2000000;
  }
  else if ((param_2 & 0x6000000) == 0x4000000) {
    uVar3 = uVar3 | 0x4000000;
  }
  if (iVar4 == 0) {
    *param_4 = uVar3;
  }
  return iVar4;
}


// ===== 00290450 RmDeprecatedConvertOs02ToOs32Flags =====

int RmDeprecatedConvertOs02ToOs32Flags(uint param_1,uint *param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = (-(uint)((param_1 & 0xf0) == 0) & 0x8000000) + 0x8000000;
  uVar2 = param_1 >> 8 & 0xf;
  if (uVar2 == 0) {
    uVar1 = uVar1 | 0x2000000;
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    if (uVar2 != 2) {
      iVar3 = 0x29;
    }
  }
  uVar2 = param_1 >> 0xc & 0xf;
  if (uVar2 == 3) {
    uVar1 = uVar1 | 0x60000000;
  }
  else if ((param_1 & 0xc000) == 0) {
    if (uVar2 == 1) {
      uVar1 = uVar1 | 0x20000000;
    }
    else if (uVar2 == 2) {
      uVar1 = uVar1 | 0x40000000;
    }
  }
  else if (uVar2 == 4) {
    uVar1 = uVar1 | 0x80000000;
  }
  else if (uVar2 == 5) {
    uVar1 = uVar1 | 0xa0000000;
  }
  else {
    iVar3 = 0x29;
  }
  uVar2 = (-(uint)((param_1 & 0x40000) == 0) & 4) + 4;
  if ((param_1 & 0x100000) != 0) {
    uVar2 = uVar2 | 0x10000;
  }
  if ((param_1 & 0x200000) != 0) {
    uVar2 = uVar2 | 0x400000;
  }
  if ((param_1 & 0x400000) != 0) {
    uVar2 = uVar2 | 0x800000;
  }
  if ((param_1 & 0x8000000) != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if ((param_1 & 0x6000000) == 0x2000000) {
    uVar2 = uVar2 | 0x2000000;
  }
  else if ((param_1 & 0x6000000) == 0x4000000) {
    uVar2 = uVar2 | 0x4000000;
  }
  if (iVar3 == 0) {
    *param_4 = (param_1 & 0x80000) << 6;
    *param_2 = uVar1;
    *param_3 = uVar2;
  }
  return iVar3;
}


// ===== 002905e0 _rmVidHeapControlAllocCommon =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _rmVidHeapControlAllocCommon
               (undefined8 *param_1,long param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5,long param_6)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_6 + 8);
  if ((uVar1 & 0x4000) == 0) {
    *param_5 = 0;
    uVar1 = *(uint *)(param_6 + 8);
  }
  *(undefined4 *)(param_6 + 0x6c) = *(undefined4 *)(param_2 + 0xc);
  iVar2 = 0x50a0;
  if ((uVar1 & 0x80000) == 0) {
    iVar2 = (-(uint)((*(uint *)(param_6 + 0x18) & 0x6000000) == 0) & 2) + 0x3e;
  }
  (*(code *)*param_1)(param_1,param_3,param_4,param_5,iVar2,param_6,0x80);
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x18) = 0;
  return;
}


// ===== 00290660 _nvos32FunctionAllocSize =====

undefined4 _nvos32FunctionAllocSize(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_98 [2];
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_20;
  
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_98 + uVar3) = 0;
    *(undefined8 *)((long)local_98 + uVar3 + 8) = 0;
    *(undefined8 *)((long)&local_88 + uVar3) = 0;
    *(undefined8 *)((long)&local_80 + uVar3) = 0;
  } while (uVar1 < 0x80);
  if ((param_2[0xd] & 0x20000) != 0) {
    local_68 = *(undefined8 *)(param_2 + 0x20);
    local_60 = *(undefined8 *)(param_2 + 0x22);
  }
  param_2[0x12] = 0x100;
  local_98[0] = CONCAT44(param_2[0xc],param_2[10]);
  local_88._0_4_ = param_2[0x14];
  local_98[1] = CONCAT44(param_2[0x13],param_2[0xd]);
  local_80._0_4_ = param_2[0xe];
  local_58 = *(undefined8 *)(param_2 + 0x16);
  local_50 = *(undefined8 *)(param_2 + 0x18);
  local_20 = param_2[0x26];
  local_48 = *(undefined8 *)(param_2 + 0x1a);
  local_80._4_4_ = param_2[0x24];
  local_40 = *(undefined8 *)(param_2 + 0x1c);
  local_38 = *(undefined8 *)(param_2 + 0x1e);
  local_78 = (undefined4)*(undefined8 *)(param_2 + 0xf);
  uStack_74 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0xf) >> 0x20);
  local_70 = param_2[0x11];
  local_30 = param_2[0x25];
  uVar2 = _rmVidHeapControlAllocCommon(param_1,param_2,*param_2,param_2[1],param_2 + 0xb,local_98);
  *(undefined8 *)(param_2 + 0x16) = local_58;
  *(undefined8 *)(param_2 + 0x1a) = local_48;
  *(ulong *)(param_2 + 0xe) = CONCAT44(local_78,(undefined4)local_80);
  *(undefined8 *)(param_2 + 0x1c) = local_40;
  *(ulong *)(param_2 + 0x10) = CONCAT44(local_70,uStack_74);
  *(undefined8 *)(param_2 + 0x1e) = local_38;
  *(ulong *)(param_2 + 0x24) = CONCAT44(local_30,local_80._4_4_);
  return uVar2;
}


// ===== 002907e0 _nvos32FunctionAllocSizeRange =====

undefined4 _nvos32FunctionAllocSizeRange(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 uStack_8c;
  undefined4 local_80;
  undefined8 uStack_7c;
  undefined8 uStack_74;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar1 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)&uStack_8c + uVar3) = 0;
    *(undefined8 *)(&stack0xffffffffffffff7c + uVar3) = 0;
    *(undefined8 *)((long)&uStack_7c + uVar3) = 0;
    *(undefined8 *)((long)&uStack_74 + uVar3) = 0;
  } while (uVar1 < 0x60);
  param_2[0x12] = 0x100;
  local_98 = CONCAT44(param_2[0xc],param_2[10]);
  local_80 = param_2[0xe];
  local_90 = param_2[0xd];
  local_68 = *(undefined8 *)(param_2 + 0x1c);
  local_60 = *(undefined8 *)(param_2 + 0x1e);
  local_58 = *(undefined8 *)(param_2 + 0x14);
  local_50 = *(undefined8 *)(param_2 + 0x16);
  local_20 = CONCAT44(local_20._4_4_,param_2[0x24]);
  local_48 = *(undefined8 *)(param_2 + 0x18);
  uStack_7c._0_4_ = param_2[0x22];
  local_40 = *(undefined8 *)(param_2 + 0x1a);
  local_38 = *(undefined8 *)(param_2 + 0x20);
  uStack_7c._4_4_ = (undefined4)*(undefined8 *)(param_2 + 0xf);
  uStack_74._0_4_ = (undefined4)((ulong)*(undefined8 *)(param_2 + 0xf) >> 0x20);
  uStack_74._4_4_ = param_2[0x11];
  local_30 = CONCAT44(local_30._4_4_,param_2[0x23]);
  uVar2 = _rmVidHeapControlAllocCommon(param_1,param_2,*param_2,param_2[1],param_2 + 0xb,&local_98);
  *(undefined8 *)(param_2 + 0x14) = local_58;
  *(undefined8 *)(param_2 + 0x18) = local_48;
  *(ulong *)(param_2 + 0xe) = CONCAT44(uStack_7c._4_4_,local_80);
  *(undefined8 *)(param_2 + 0x1a) = local_40;
  *(ulong *)(param_2 + 0x10) = CONCAT44(uStack_74._4_4_,(undefined4)uStack_74);
  *(undefined8 *)(param_2 + 0x20) = local_38;
  *(ulong *)(param_2 + 0x22) = CONCAT44((undefined4)local_30,(undefined4)uStack_7c);
  return uVar2;
}


// ===== 00290950 _nvos32FunctionAllocTiledPitchHeight =====

undefined4 _nvos32FunctionAllocTiledPitchHeight(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 local_98 [2];
  uint local_88;
  int local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_20;
  
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_98 + uVar3) = 0;
    *(undefined8 *)((long)local_98 + uVar3 + 8) = 0;
    *(undefined8 *)((long)&local_88 + uVar3) = 0;
    *(undefined8 *)((long)&local_80 + uVar3) = 0;
  } while (uVar1 < 0x80);
  local_84 = param_2[0xf];
  local_88 = param_2[0xe];
  local_58 = (ulong)local_88 * (long)local_84;
  *(long *)(param_2 + 0x16) = local_58;
  if ((param_2[0xd] & 0x20000) != 0) {
    local_68 = *(undefined8 *)(param_2 + 0x20);
    local_60 = *(undefined8 *)(param_2 + 0x22);
  }
  param_2[0x15] = 0x100;
  local_98[0] = CONCAT44(param_2[0xc],param_2[10]);
  local_98[1] = CONCAT44(param_2[0x11],param_2[0xd]);
  local_80._0_4_ = param_2[0x10];
  local_50 = *(undefined8 *)(param_2 + 0x18);
  local_20 = param_2[0x26];
  local_48 = *(undefined8 *)(param_2 + 0x1a);
  local_80._4_4_ = param_2[0x24];
  local_40 = *(undefined8 *)(param_2 + 0x1c);
  local_38 = *(undefined8 *)(param_2 + 0x1e);
  local_78 = *(undefined8 *)(param_2 + 0x12);
  local_70 = param_2[0x14];
  local_30 = param_2[0x25];
  uVar2 = _rmVidHeapControlAllocCommon(param_1,param_2,*param_2,param_2[1],param_2 + 0xb,local_98);
  *(long *)(param_2 + 0x16) = local_58;
  *(undefined8 *)(param_2 + 0x1a) = local_48;
  param_2[0x10] = (undefined4)local_80;
  *(undefined8 *)(param_2 + 0x1c) = local_40;
  *(undefined8 *)(param_2 + 0x1e) = local_38;
  *(undefined8 *)(param_2 + 0x12) = local_78;
  param_2[0x14] = local_70;
  *(ulong *)(param_2 + 0x24) = CONCAT44(local_30,local_80._4_4_);
  return uVar2;
}


// ===== 00290ad0 _nvos32FunctionFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvos32FunctionFree(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if ((*(byte *)(param_2 + 0xc) & 1) != 0) {
    uVar1 = (**(code **)(param_1 + 0x10))(param_1,*param_2,param_2[0xb]);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00290b00 _nvos32FunctionReleaseReacquireCompr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _nvos32FunctionReleaseReacquireCompr(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  if ((*(byte *)(param_2 + 0xb) & 1) != 0) {
    local_9 = param_2[2] == 0x10;
    uVar1 = (**(code **)(param_1 + 8))(param_1,*param_2,param_2[0xc],0x410119,&local_9,1);
    return uVar1;
  }
  return 0x29;
}


// ===== 00290b50 _nvos32FunctionHwAlloc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 _nvos32FunctionHwAlloc(undefined8 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  if ((*(byte *)((long)param_2 + 0x31) & 0x40) == 0) {
    param_2[0xb] = 0;
  }
  uStack_8c = param_2[0xf];
  local_90 = param_2[10];
  uStack_64 = param_2[0x1e];
  uStack_7c = param_2[0x12];
  local_88 = *(undefined8 *)(param_2 + 0xd);
  local_48 = *(undefined8 *)(param_2 + 0x10);
  local_60 = *(undefined8 *)(param_2 + 0x18);
  local_38 = *(undefined8 *)(param_2 + 0x26);
  local_58 = *(undefined8 *)(param_2 + 0x1a);
  local_78 = (undefined4)*(undefined8 *)(param_2 + 0x13);
  uStack_74 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x13) >> 0x20);
  local_68 = param_2[0x17];
  local_70 = (undefined4)*(undefined8 *)(param_2 + 0x15);
  uStack_6c = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x15) >> 0x20);
  local_50 = *(undefined8 *)(param_2 + 0x20);
  local_28 = *(undefined8 *)(param_2 + 0x2a);
  local_80 = param_2[0x22];
  local_20 = param_2[0x2c];
  local_30 = *(undefined8 *)(param_2 + 0x28);
  local_40 = *(undefined8 *)(param_2 + 0x24);
  uVar1 = (*(code *)*param_1)(param_1,*param_2,param_2[1],param_2 + 0xb,0xb1,&local_90,0x78);
  param_2[0xd] = (undefined4)local_88;
  param_2[0xf] = uStack_8c;
  *(undefined8 *)(param_2 + 0x10) = local_48;
  *(ulong *)(param_2 + 0x12) = CONCAT44(local_78,uStack_7c);
  *(ulong *)(param_2 + 0x14) = CONCAT44(local_70,uStack_74);
  *(ulong *)(param_2 + 0x16) = CONCAT44(local_68,uStack_6c);
  *(undefined8 *)(param_2 + 0x18) = local_60;
  *(undefined8 *)(param_2 + 0x1a) = local_58;
  *(ulong *)(param_2 + 0x1c) = CONCAT44(local_88._4_4_,param_2[0xb]);
  param_2[0x1e] = uStack_64;
  *(undefined8 *)(param_2 + 0x20) = local_50;
  param_2[0x23] = local_80;
  *(undefined8 *)(param_2 + 0x26) = local_38;
  *(undefined8 *)(param_2 + 0x28) = local_30;
  *(undefined8 *)(param_2 + 0x2a) = local_28;
  param_2[0x2c] = local_20;
  *(undefined8 *)(param_2 + 0x24) = local_40;
  return uVar1;
}


// ===== 00290cf0 _nvos32FunctionHwFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvos32FunctionHwFree(long param_1,undefined4 *param_2)

{
  (**(code **)(param_1 + 0x10))(param_1,*param_2,param_2[10]);
  return;
}


// ===== 00290d10 _nvos32FunctionAllocOsDesc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nvos32FunctionAllocOsDesc(undefined8 *param_1,undefined4 *param_2)

{
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_28 = *(undefined8 *)(param_2 + 0xd);
  local_30 = *(undefined8 *)(param_2 + 0xb);
  local_c = 0;
  local_20 = *(undefined8 *)(param_2 + 0x10);
  local_18 = *(undefined8 *)(param_2 + 0x12);
  local_10 = param_2[0x14];
  if ((*(byte *)((long)param_2 + 0x31) & 0x40) == 0) {
    param_2[10] = 0;
  }
  (*(code *)*param_1)(param_1,*param_2,param_2[1],param_2 + 10,0x71,&local_30,0x28);
  return;
}


// ===== 00290d80 _nvos32FunctionGetMemAlignment =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _nvos32FunctionGetMemAlignment(long param_1,undefined4 *param_2)

{
  int iVar1;
  char local_55;
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_50 = *(undefined8 *)(param_2 + 10);
  local_30 = *(undefined8 *)(param_2 + 0x12);
  local_44 = 0;
  local_28 = *(undefined8 *)(param_2 + 0x14);
  local_48 = param_2[0xc];
  local_40 = *(undefined8 *)(param_2 + 0xe);
  local_20 = *(undefined8 *)(param_2 + 0x16);
  local_38 = *(undefined8 *)(param_2 + 0x10);
  iVar1 = RmDeprecatedFindOrCreateSubDeviceHandle(param_1,*param_2,param_2[1],&local_54,&local_55);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1 + 8))(param_1,*param_2,local_54,0x20801342,&local_50,0x38);
    *(undefined8 *)(param_2 + 10) = local_50;
    param_2[0xc] = local_48;
    *(undefined8 *)(param_2 + 0xe) = local_40;
    *(undefined8 *)(param_2 + 0x10) = local_38;
    *(undefined8 *)(param_2 + 0x12) = local_30;
    *(undefined8 *)(param_2 + 0x14) = local_28;
    *(undefined8 *)(param_2 + 0x16) = local_20;
    if (local_55 != '\0') {
      (**(code **)(param_1 + 0x10))(param_1,*param_2,local_54);
    }
  }
  return iVar1;
}


// ===== 00290e70 _nvos32FunctionInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _nvos32FunctionInfo(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  char local_435;
  undefined4 local_434;
  undefined8 local_430;
  uint local_428;
  undefined4 local_424;
  uint local_420;
  undefined4 local_41c;
  uint local_418;
  undefined4 local_414;
  uint local_410;
  undefined4 local_40c;
  uint local_408;
  undefined4 local_404;
  uint local_400;
  
  memset(&local_430,0,0x404);
  uVar1 = *param_2;
  iVar2 = RmDeprecatedFindOrCreateSubDeviceHandle(param_1,uVar1,param_2[1],&local_434,&local_435);
  if (iVar2 == 0) {
    local_430 = 0x1600000006;
    local_424 = 9;
    local_41c = 0x10;
    local_414 = 0x11;
    local_40c = 0x12;
    local_404 = 0x13;
    iVar2 = (**(code **)(param_1 + 8))(param_1,uVar1,local_434,0x20801303,&local_430,0x404);
    *(ulong *)(param_2 + 8) = (ulong)local_428 << 10;
    *(ulong *)(param_2 + 6) = ((ulong)local_420 + (ulong)local_418) * 0x400;
    *(ulong *)(param_2 + 0x10) = (ulong)local_410 << 10;
    *(ulong *)(param_2 + 0xe) = (ulong)local_408 << 10;
    *(ulong *)(param_2 + 0xc) = (ulong)local_400 << 10;
    if (local_435 != '\0') {
      (**(code **)(param_1 + 0x10))(param_1,uVar1,local_434);
    }
  }
  return iVar2;
}


// ===== 00290fc0 RmDeprecatedVidHeapControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmDeprecatedVidHeapControl(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar1 = 0x56;
  if (*(short *)(param_2 + 0x10) < 1) {
    uVar2 = 0;
    do {
      if (*(int *)(param_2 + 8) == (&rmVidHeapControlTable)[uVar2 * 4]) {
        uVar1 = (*(code *)(&PTR__nvos32FunctionAllocSize_00ce0648)[(uVar2 & 0xffffffff) * 2])();
        *(undefined4 *)(param_2 + 0x14) = uVar1;
        return;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0xb);
    uVar1 = 0x1f;
  }
  *(undefined4 *)(param_2 + 0x14) = uVar1;
  return;
}


// ===== 00291030 RmGssLegacyRpcCmd =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int RmGssLegacyRpcCmd(int *param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  int local_cc;
  long local_c8;
  undefined8 local_c0;
  undefined1 local_b8 [144];
  
  local_c8 = 0;
  local_c0 = 0;
  local_cc = 0;
  if ((param_3[2] & 0x8000) == 0) {
    nvAssertFailedNoLog("(pArgs->cmd & RM_GSS_LEGACY_MASK)",
                        "interface/deprecated/rmapi_gss_legacy_control.c",0x35);
    return 0x40;
  }
  if (((~param_3[2] & 0xc000) == 0) && (*param_1 == 0)) {
    return 0x1b;
  }
  threadStateInit(local_b8,0);
  if (param_1[1] == 0) {
    lVar2 = portMemAllocNonPaged(param_3[6]);
    if (lVar2 != 0) {
      iVar1 = portMemExCopyFromUser(*(undefined8 *)(param_3 + 4),lVar2,param_3[6]);
      if (iVar1 == 0) goto LAB_002910b9;
      goto LAB_002910ce;
    }
    if (local_cc != 0) {
      rmGpuGroupLockRelease(local_cc,0);
    }
    iVar1 = 0x51;
LAB_002910dc:
    if (param_1[1] != 0) goto LAB_002910ec;
  }
  else {
    lVar2 = *(long *)(param_3 + 4);
LAB_002910b9:
    iVar1 = rmapiLockAcquire(2,0x200);
    if (iVar1 != 0) {
LAB_002910ce:
      if (local_cc != 0) {
        rmGpuGroupLockRelease(local_cc,0);
      }
      goto LAB_002910dc;
    }
    iVar1 = serverGetClientUnderLock(g_resServ,*param_3,&local_c0);
    uVar5 = 0x58;
    pcVar4 = "serverGetClientUnderLock(&g_resServ, pArgs->hClient, &pClient)";
    if (iVar1 == 0) {
      iVar1 = gpuGetByHandle(local_c0,param_3[1],0,&local_c8,0x58);
      if (iVar1 != 0) {
        uVar5 = 0x5d;
        pcVar4 = "gpuGetByHandle(pClient, pArgs->hObject, NULL, &pGpu)";
        goto LAB_0029131c;
      }
      osRefGpuAccessNeeded(*(undefined8 *)(local_c8 + 0x4e0));
      iVar1 = rmGpuGroupLockAcquire(*(undefined4 *)(local_c8 + 0x7a4),0,0,0x8002,&local_cc);
      if (iVar1 != 0) goto joined_r0x00291330;
      if (*(char *)(local_c8 + 0x908) == '\0') {
        iVar1 = (**(code **)(local_c8 + 0x3b90))
                          (local_c8 + 0x3b58,*param_3,param_3[1],param_3[2],lVar2,param_3[6]);
joined_r0x002913a1:
        if (local_cc != 0) {
          rmGpuGroupLockRelease(local_cc,0);
        }
        if (local_c8 != 0) goto LAB_00291201;
        goto LAB_0029120d;
      }
      lVar3 = gpuGetRpc();
      if (lVar3 != 0) {
        iVar1 = (**(code **)(lVar3 + 0x358))
                          (local_c8,lVar3,*param_3,param_3[1],param_3[2],lVar2,param_3[6]);
        goto joined_r0x002913a1;
      }
      nvAssertFailedNoLog("pRpc != NULL","interface/deprecated/rmapi_gss_legacy_control.c",0x6e);
      if (local_cc != 0) {
        rmGpuGroupLockRelease(local_cc,0);
        if (local_c8 != 0) goto LAB_002913f2;
LAB_00291428:
        rmapiLockRelease();
        if (param_1[1] == 0) goto LAB_0029140b;
LAB_00291435:
        iVar1 = 0x1a;
        goto LAB_002910ec;
      }
      if (local_c8 == 0) goto LAB_00291428;
LAB_002913f2:
      osUnrefGpuAccessNeeded(*(undefined8 *)(local_c8 + 0x4e0));
      rmapiLockRelease();
      if (param_1[1] != 0) goto LAB_00291435;
LAB_0029140b:
      iVar1 = 0x1a;
    }
    else {
LAB_0029131c:
      nvCheckOkFailedNoLog(2,iVar1,pcVar4,"interface/deprecated/rmapi_gss_legacy_control.c",uVar5);
joined_r0x00291330:
      if (local_cc != 0) {
        rmGpuGroupLockRelease(local_cc,0);
      }
      if (local_c8 == 0) {
        rmapiLockRelease();
        goto LAB_002910dc;
      }
LAB_00291201:
      osUnrefGpuAccessNeeded(*(undefined8 *)(local_c8 + 0x4e0));
LAB_0029120d:
      rmapiLockRelease();
      if (param_1[1] != 0) goto LAB_002910ec;
      if (iVar1 == 0) {
        iVar1 = portMemExCopyToUser(lVar2,*(undefined8 *)(param_3 + 4),param_3[6]);
      }
    }
  }
  portMemFree(lVar2);
LAB_002910ec:
  threadStateFree(local_b8,0);
  return iVar1;
}


// ===== 00291440 finn_read_buffer =====

ulong finn_read_buffer(ulong *param_1,byte param_2)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  byte bVar4;
  ulong uVar5;
  
  bVar4 = (byte)param_1[3];
  uVar3 = *param_1;
  if (bVar4 < param_2) {
    puVar1 = (ulong *)param_1[1];
    param_2 = param_2 - bVar4;
    uVar5 = 0;
    if (puVar1 < (ulong *)param_1[2]) {
      param_1[1] = (ulong)(puVar1 + 1);
      uVar5 = *puVar1;
    }
    if (0x3f < param_2) {
      *param_1 = 0;
      return uVar5;
    }
    uVar2 = (~(-1L << (param_2 & 0x3f)) & uVar5) << (bVar4 & 0x3f) | uVar3;
    uVar3 = uVar5;
    bVar4 = 0x40;
  }
  else {
    uVar2 = ~(-1L << (param_2 & 0x3f)) & uVar3;
  }
  *(byte *)(param_1 + 3) = bVar4 - param_2;
  *param_1 = uVar3 >> (param_2 & 0x3f);
  return uVar2;
}


// ===== 002914e0 finn_write_buffer =====

bool finn_write_buffer(ulong *param_1,ulong param_2,byte param_3)

{
  byte bVar1;
  ulong uVar2;
  byte bVar3;
  char cVar4;
  ulong uVar5;
  
  bVar1 = (byte)param_1[4];
  if (param_3 < bVar1) {
    uVar5 = param_1[3];
    bVar3 = bVar1;
  }
  else {
    param_3 = param_3 - bVar1;
    uVar2 = *param_1 | param_2 << (-bVar1 & 0x3f);
    if (param_1[3] == 0) {
      param_1[2] = param_1[2] + 8;
      *param_1 = 0;
      param_1[1] = uVar2 ^ (ulong)((uint)param_1[1] & 1) ^ param_1[1] * 2;
      if (param_3 == 0) {
        *(undefined1 *)(param_1 + 4) = 0x40;
        return false;
      }
      uVar5 = 0;
    }
    else {
      *(ulong *)param_1[2] = uVar2;
      param_1[2] = param_1[2] + 8;
      uVar5 = param_1[3];
      *param_1 = 0;
      param_1[1] = uVar2 ^ param_1[1] * 2 ^ (ulong)((uint)param_1[1] & 1);
      if (param_3 == 0) {
        cVar4 = '@';
        goto LAB_00291500;
      }
    }
    bVar3 = 0x40;
    param_2 = param_2 >> (bVar1 & 0x3f);
  }
  cVar4 = bVar3 - param_3;
  *param_1 = *param_1 | param_2 << (-bVar3 & 0x3f);
LAB_00291500:
  *(char *)(param_1 + 4) = cVar4;
  if (uVar5 == 0) {
    return false;
  }
  return param_3 != 0 && uVar5 <= param_1[2];
}


// ===== 002915c0 finn_write_buffer.constprop.0 =====

bool finn_write_buffer_constprop_0(long *param_1)

{
  long lVar1;
  bool bVar2;
  
  lVar1 = param_1[4];
  *(char *)(param_1 + 4) = (char)lVar1 + -1;
  bVar2 = false;
  *param_1 = 1L << (-(char)lVar1 & 0x3fU);
  if (param_1[3] != 0) {
    bVar2 = (ulong)param_1[3] <= (ulong)param_1[2];
  }
  return bVar2;
}


// ===== 002915f0 finn_write_buffer.constprop.1 =====

byte finn_write_buffer_constprop_1(ulong *param_1)

{
  ulong uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ulong uVar5;
  bool bVar6;
  
  bVar2 = (byte)param_1[4];
  uVar5 = param_1[3];
  if (bVar2 < 2) {
    uVar1 = *param_1;
    if (uVar5 != 0) {
      *(ulong *)param_1[2] = uVar1 | 0x8000000000000000;
      uVar5 = param_1[3];
    }
    param_1[2] = param_1[2] + 8;
    *param_1 = 0;
    bVar6 = bVar2 == 1;
    bVar2 = 0x40;
    param_1[1] = param_1[1] * 2 ^ (ulong)((uint)param_1[1] & 1) ^ (uVar1 | 0x8000000000000000);
    if (bVar6) {
      bVar4 = 0;
      bVar3 = bVar2;
      goto LAB_00291645;
    }
  }
  bVar3 = bVar2 - 1;
  bVar4 = 1;
  *param_1 = *param_1 | 1L << (-bVar2 & 0x3f);
LAB_00291645:
  *(byte *)(param_1 + 4) = bVar3;
  bVar2 = 0;
  if (uVar5 != 0) {
    bVar2 = uVar5 <= param_1[2] & bVar4;
  }
  return bVar2;
}


// ===== 00291680 finn_write_buffer.constprop.2 =====

bool finn_write_buffer_constprop_2(ulong *param_1,ulong param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  ulong uVar4;
  char cVar5;
  ulong uVar6;
  
  bVar2 = (byte)param_1[4];
  if (bVar2 < 0x21) {
    uVar6 = param_2 << (-bVar2 & 0x3f) | *param_1;
    uVar4 = 0;
    if (param_1[3] != 0) {
      *(ulong *)param_1[2] = uVar6;
      uVar4 = param_1[3];
    }
    param_1[2] = param_1[2] + 8;
    *param_1 = 0;
    param_1[1] = param_1[1] * 2 ^ (ulong)((uint)param_1[1] & 1) ^ uVar6;
    if (bVar2 == 0x20) {
      cVar3 = '@';
      cVar5 = '\0';
      goto LAB_002916da;
    }
    cVar5 = ' ' - bVar2;
    param_2 = param_2 >> (bVar2 & 0x3f);
    bVar2 = 0x40;
  }
  else {
    uVar4 = param_1[3];
    cVar5 = ' ';
  }
  cVar3 = bVar2 - cVar5;
  *param_1 = *param_1 | param_2 << (-bVar2 & 0x3f);
LAB_002916da:
  *(char *)(param_1 + 4) = cVar3;
  bVar1 = false;
  if (uVar4 != 0) {
    bVar1 = cVar5 != '\0' && uVar4 <= param_1[2];
  }
  return bVar1;
}


// ===== 00291730 finn_read_buffer.constprop.0 =====

ulong finn_read_buffer_constprop_0(ulong *param_1)

{
  byte bVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  byte bVar5;
  
  bVar1 = (byte)param_1[3];
  uVar2 = *param_1;
  if (7 < bVar1) {
    *(byte *)(param_1 + 3) = bVar1 - 8;
    *param_1 = uVar2 >> 8;
    return uVar2 & 0xff;
  }
  puVar3 = (ulong *)param_1[1];
  bVar5 = 8 - bVar1;
  if ((ulong *)param_1[2] <= puVar3) {
    *param_1 = 0;
    *(byte *)(param_1 + 3) = '@' - bVar5;
    return uVar2;
  }
  param_1[1] = (ulong)(puVar3 + 1);
  uVar4 = *puVar3;
  *(byte *)(param_1 + 3) = '@' - bVar5;
  *param_1 = uVar4 >> (bVar5 & 0x3f);
  return uVar2 | (~(-1L << (bVar5 & 0x3f)) & uVar4) << (bVar1 & 0x3f);
}


// ===== 002917c0 finn_read_buffer.constprop.1 =====

ulong finn_read_buffer_constprop_1(ulong *param_1)

{
  ulong uVar1;
  ulong *puVar2;
  ulong uVar3;
  
  uVar1 = *param_1;
  if ((char)param_1[3] != '\0') {
    *(char *)(param_1 + 3) = (char)param_1[3] + -1;
    *param_1 = uVar1 >> 1;
    return (ulong)((uint)uVar1 & 1);
  }
  puVar2 = (ulong *)param_1[1];
  if ((ulong *)param_1[2] <= puVar2) {
    *(undefined1 *)(param_1 + 3) = 0x3f;
    *param_1 = 0;
    return uVar1;
  }
  param_1[1] = (ulong)(puVar2 + 1);
  uVar3 = *puVar2;
  *param_1 = uVar3 >> 1;
  *(undefined1 *)(param_1 + 3) = 0x3f;
  return uVar1 | (uint)uVar3 & 1;
}


// ===== 00291840 finn_read_buffer.constprop.2 =====

ulong finn_read_buffer_constprop_2(ulong *param_1)

{
  byte bVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  byte bVar5;
  
  bVar1 = (byte)param_1[3];
  uVar2 = *param_1;
  if (0x1f < bVar1) {
    *(byte *)(param_1 + 3) = bVar1 - 0x20;
    *param_1 = uVar2 >> 0x20;
    return uVar2 & 0xffffffff;
  }
  puVar3 = (ulong *)param_1[1];
  bVar5 = 0x20 - bVar1;
  if ((ulong *)param_1[2] <= puVar3) {
    *param_1 = 0;
    *(byte *)(param_1 + 3) = '@' - bVar5;
    return uVar2;
  }
  param_1[1] = (ulong)(puVar3 + 1);
  uVar4 = *puVar3;
  *(byte *)(param_1 + 3) = '@' - bVar5;
  *param_1 = uVar4 >> (bVar5 & 0x3f);
  return uVar2 | (~(-1L << (bVar5 & 0x3f)) & uVar4) << (bVar1 & 0x3f);
}


// ===== 002918d0 finnSerializeUnion_NV402C_CTRL_I2C_TRANSACTION_DATA =====

int finnSerializeUnion_NV402C_CTRL_I2C_TRANSACTION_DATA
              (long param_1,undefined8 param_2,char param_3,uint param_4)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  if (param_4 == 5) {
    iVar1 = finn_write_buffer_constprop_1(param_2);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer();
    return iVar1 * 2;
  }
  if (param_4 < 6) {
    if (param_4 == 2) {
      iVar1 = finn_write_buffer_constprop_1(param_2);
      if ((((iVar1 != 0) || (iVar1 = finn_write_buffer_constprop_1(), iVar1 != 0)) ||
          (iVar1 = finn_write_buffer(), iVar1 != 0)) ||
         (((iVar1 = finn_write_buffer_constprop_1(), iVar1 != 0 ||
           (iVar1 = finn_write_buffer_constprop_2(), iVar1 != 0)) ||
          (iVar1 = finn_write_buffer(), iVar1 != 0)))) {
        return 2;
      }
      lVar4 = *(long *)(param_1 + 8);
      if (lVar4 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 4) == 0) goto LAB_0029210d;
      uVar2 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 4));
      if (param_3 == '\0') {
        return 0;
      }
      lVar4 = *(long *)(param_1 + 8);
    }
    else {
      if (param_4 < 3) {
        if (param_4 != 0) {
          iVar1 = finn_write_buffer_constprop_1(param_2);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          return iVar1 * 2;
        }
        iVar1 = finn_write_buffer_constprop_1(param_2);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        return iVar1 * 2;
      }
      if (param_4 != 3) {
        iVar1 = finn_write_buffer_constprop_1(param_2);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        return iVar1 * 2;
      }
      iVar1 = finn_write_buffer_constprop_1(param_2);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      lVar4 = *(long *)(param_1 + 0x10);
      if (lVar4 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 0xc) == 0) goto LAB_0029210d;
      uVar2 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0xc));
      if (param_3 == '\0') {
        return 0;
      }
      lVar4 = *(long *)(param_1 + 0x10);
    }
  }
  else {
    if (param_4 == 8) {
      iVar1 = finn_write_buffer_constprop_1(param_2);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      if (0x20 < *(uint *)(param_1 + 4)) {
        return 0x5b;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(uint *)(param_1 + 0x28) < 0x21) {
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        lVar4 = param_1 + 0x28;
        lVar3 = param_1 + 8;
        while( true ) {
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) break;
          lVar3 = lVar3 + 1;
          if (lVar4 == lVar3) {
            lVar4 = param_1 + 0x2c;
            param_1 = param_1 + 0x4c;
            while( true ) {
              iVar1 = finn_write_buffer_constprop_1();
              if (iVar1 != 0) {
                return 2;
              }
              iVar1 = finn_write_buffer();
              if (iVar1 != 0) break;
              lVar4 = lVar4 + 1;
              if (lVar4 == param_1) {
                return 0;
              }
            }
            return 2;
          }
        }
        return 2;
      }
      return 0x5b;
    }
    if (param_4 < 9) {
      if (param_4 != 6) {
        iVar1 = finn_write_buffer_constprop_1(param_2);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        return iVar1 * 2;
      }
      iVar1 = finn_write_buffer_constprop_1(param_2);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      lVar4 = *(long *)(param_1 + 8);
      if (lVar4 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 4) == 0) goto LAB_0029210d;
      uVar2 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 4));
    }
    else {
      if (param_4 == 9) {
        iVar1 = finn_write_buffer_constprop_1(param_2);
        if (((iVar1 == 0) && (iVar1 = finn_write_buffer_constprop_1(), iVar1 == 0)) &&
           ((iVar1 = finn_write_buffer(), iVar1 == 0 &&
            (((iVar1 = finn_write_buffer_constprop_1(), iVar1 == 0 &&
              (iVar1 = finn_write_buffer_constprop_2(), iVar1 == 0)) &&
             (iVar1 = finn_write_buffer_constprop_1(), iVar1 == 0)))))) {
          if (4 < *(uint *)(param_1 + 8)) {
            return 0x5b;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (((iVar1 == 0) && (iVar1 = finn_write_buffer_constprop_1(), iVar1 == 0)) &&
             (iVar1 = finn_write_buffer_constprop_2(), iVar1 == 0)) {
            lVar4 = 0;
            do {
              iVar1 = finn_write_buffer_constprop_1();
              if (iVar1 != 0) {
                return 2;
              }
              iVar1 = finn_write_buffer();
              if (iVar1 != 0) {
                return 2;
              }
              lVar4 = lVar4 + 1;
            } while (lVar4 != 4);
            iVar1 = finn_write_buffer();
            if (iVar1 == 0) {
              lVar4 = *(long *)(param_1 + 0x18);
              if (lVar4 == 0) {
                return 0;
              }
              if (*(int *)(param_1 + 0x10) == 0) {
                if (param_3 == '\0') {
                  return 0;
                }
              }
              else {
                uVar2 = 0;
                do {
                  iVar1 = finn_write_buffer_constprop_1();
                  if (iVar1 != 0) {
                    return 2;
                  }
                  iVar1 = finn_write_buffer();
                  if (iVar1 != 0) {
                    return 2;
                  }
                  uVar2 = uVar2 + 1;
                } while (uVar2 < *(uint *)(param_1 + 0x10));
                if (param_3 == '\0') {
                  return 0;
                }
                lVar4 = *(long *)(param_1 + 0x18);
                if (lVar4 == 0) {
                  return 0;
                }
              }
              portMemFree(lVar4);
              return 0;
            }
          }
        }
        return 2;
      }
      if (param_4 != 10) {
        return 0x1f;
      }
      iVar1 = finn_write_buffer_constprop_1(param_2);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      lVar4 = *(long *)(param_1 + 8);
      if (lVar4 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 4) == 0) {
LAB_0029210d:
        if (param_3 == '\0') {
          return 0;
        }
        goto LAB_00292167;
      }
      uVar2 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 4));
    }
    if (param_3 == '\0') {
      return 0;
    }
    lVar4 = *(long *)(param_1 + 8);
  }
  if (lVar4 == 0) {
    return 0;
  }
LAB_00292167:
  portMemFree(lVar4);
  return 0;
}


// ===== 002921f0 finnSerializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS.isra.0 =====

undefined8
finnSerializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS_isra_0(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  iVar1 = finn_write_buffer_constprop_1(param_2);
  if ((((iVar1 == 0) && (iVar1 = finn_write_buffer_constprop_2(), iVar1 == 0)) &&
      (iVar1 = finn_write_buffer_constprop_1(), iVar1 == 0)) &&
     (iVar1 = finn_write_buffer_constprop_2(), iVar1 == 0)) {
    lVar3 = param_1 + 8;
    while ((iVar1 = finn_write_buffer_constprop_1(), iVar1 == 0 &&
           (uVar2 = finn_write_buffer(), (int)uVar2 == 0))) {
      lVar3 = lVar3 + 1;
      if (lVar3 == param_1 + 0x1008) {
        return uVar2;
      }
    }
  }
  return 2;
}


// ===== 00292270 finnSerializeRoot_FINN_RM_API.constprop.0 =====

ulong finnSerializeRoot_FINN_RM_API_constprop_0
                (ulong param_1,long param_2,uint *param_3,undefined8 param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint *puVar4;
  long lVar5;
  
  if (param_1 == 0x208006) {
    if (param_2 != 0x10) {
      return 0x56;
    }
    iVar1 = finn_write_buffer_constprop_0(param_4);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    if (0x100 < param_3[7]) {
      return 0x5b;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer();
    if (iVar1 != 0) {
      return 2;
    }
    uVar3 = 0;
    if (*(long *)(param_3 + 4) == 0) {
      return 0;
    }
    for (; uVar3 < param_3[7]; uVar3 = uVar3 + 1) {
      iVar1 = finn_write_buffer_constprop_1(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
    }
    goto LAB_0029306e;
  }
  if (param_1 < 0x208007) {
    if (param_1 == 0x8014) {
      if (param_2 != 1) {
        return 0x56;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      if (3 < *param_3) {
        return 0x5b;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 2) == 0) {
        return 0;
      }
      uVar3 = (ulong)*param_3;
      if (*param_3 != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *param_3);
        goto LAB_002932da;
      }
    }
    else if (param_1 < 0x8015) {
      if (param_1 == 0x8011) {
        if (param_2 != 2) {
          return 0x56;
        }
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 2) == 0) {
          return 0;
        }
        uVar3 = (ulong)*param_3;
        if (*param_3 != 0) {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *param_3);
LAB_002932da:
          if (param_5 == '\0') {
            return 0;
          }
          if (*(long *)(param_3 + 2) == 0) {
            return 0;
          }
          goto LAB_002932f1;
        }
      }
      else if (param_1 < 0x8012) {
        if (param_1 == 6) {
          if (param_2 != 2) {
            return 0x56;
          }
          iVar1 = finn_write_buffer_constprop_0(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          if (1000000 < param_3[3]) {
            return 0x5b;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          if (*(long *)param_3 == 0) {
            return 0;
          }
          uVar3 = (ulong)param_3[3];
          if (param_3[3] != 0) {
            uVar3 = 0;
            do {
              iVar1 = finn_write_buffer_constprop_1(param_4);
              if (iVar1 != 0) {
                return 2;
              }
              iVar1 = finn_write_buffer();
              if (iVar1 != 0) {
                return 2;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < param_3[3]);
            goto LAB_00293a46;
          }
        }
        else {
          if (param_1 != 0x8002) {
            return 0x56;
          }
          if (param_2 != 1) {
            return 0x56;
          }
          iVar1 = finn_write_buffer_constprop_0(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          if (*(long *)(param_3 + 2) == 0) {
            return 0;
          }
          uVar3 = (ulong)*param_3;
          if (*param_3 != 0) {
            uVar3 = 0;
            do {
              iVar1 = finn_write_buffer_constprop_1(param_4);
              if (iVar1 != 0) {
                return 2;
              }
              iVar1 = finn_write_buffer_constprop_2();
              if (iVar1 != 0) {
                return 2;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < *param_3);
            goto LAB_002932da;
          }
        }
      }
      else {
        if (param_1 != 0x8013) {
          return 0x56;
        }
        if (param_2 != 1) {
          return 0x56;
        }
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        if (3 < *param_3) {
          return 0x5b;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 2) == 0) {
          return 0;
        }
        uVar3 = (ulong)*param_3;
        if (*param_3 != 0) {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *param_3);
          goto LAB_002932da;
        }
      }
    }
    else if (param_1 == 0x801b) {
      if (param_2 != 1) {
        return 0x56;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      if (6 < *param_3) {
        return 0x5b;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 2) == 0) {
        return 0;
      }
      uVar3 = (ulong)*param_3;
      if (*param_3 != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *param_3);
        goto LAB_002932da;
      }
    }
    else if (param_1 < 0x801c) {
      if (param_1 != 0x8017) {
        if (param_1 != 0x8018) {
          return 0x56;
        }
        if (param_2 != 0xf) {
          return 0x56;
        }
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        puVar4 = param_3 + 2;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          puVar4 = puVar4 + 4;
        } while (param_3 + 10 != puVar4);
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 0xc) == 0) {
          return 0;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (param_5 == '\0') {
          return 0;
        }
        if (*(long *)(param_3 + 0xc) == 0) {
          return 0;
        }
        goto LAB_002932f1;
      }
      if (param_2 == 1) {
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        if (2 < *param_3) {
          return 0x5b;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 2) == 0) {
          return 0;
        }
        uVar3 = (ulong)*param_3;
        if (*param_3 != 0) {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *param_3);
          goto LAB_002932da;
        }
        goto LAB_00293a38;
      }
      if (param_2 != 0xd) {
        return 0x56;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 2) != 0) {
        if (*param_3 == 0) {
          if (param_5 != '\0') goto LAB_002939bf;
        }
        else {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer_constprop_2();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *param_3);
          if ((param_5 != '\0') && (*(long *)(param_3 + 2) != 0)) {
LAB_002939bf:
            portMemFree();
          }
        }
      }
      iVar1 = finn_write_buffer(param_4,*(long *)(param_3 + 4) != 0,1);
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 4) == 0) {
        return 0;
      }
      uVar3 = (ulong)*param_3;
      if (*param_3 != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *param_3);
        goto LAB_0029306e;
      }
    }
    else {
      if (param_1 != 0x208001) {
        return 0x56;
      }
      if (param_2 == 0x24) {
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 2) == 0) {
          return 0;
        }
        uVar3 = (ulong)param_3[1];
        if (param_3[1] != 0) {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer_constprop_2();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < param_3[1]);
          goto LAB_002932da;
        }
      }
      else if (param_2 == 0xe8) {
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 6) == 0) {
          return 0;
        }
        uVar3 = (ulong)param_3[1];
        if (param_3[1] != 0) {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer_constprop_2();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < param_3[1]);
          goto LAB_002935e6;
        }
      }
      else {
        if (param_2 != 0x23) {
          return 0x56;
        }
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        if (*(long *)(param_3 + 2) == 0) {
          return 0;
        }
        uVar3 = (ulong)*param_3;
        if (*param_3 != 0) {
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer_constprop_2();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *param_3);
          goto LAB_002932da;
        }
      }
    }
  }
  else if (param_1 == 0x20802a) {
    if (param_2 != 1) {
      return 0x56;
    }
    iVar1 = finn_write_buffer_constprop_0(param_4);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    if (2 < param_3[1]) {
      return 0x5b;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer();
    if (iVar1 != 0) {
      return 2;
    }
    if (*(long *)(param_3 + 2) == 0) {
      return 0;
    }
    uVar3 = (ulong)param_3[1];
    if (param_3[1] != 0) {
      uVar3 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3[1]);
      goto LAB_002932da;
    }
  }
  else if (param_1 < 0x20802b) {
    if (param_1 == 0x208022) {
      if (param_2 != 4) {
        return 0x56;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 4) == 0) {
        return 0;
      }
      uVar3 = (ulong)param_3[6];
      if (param_3[6] != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_3[6]);
        goto LAB_0029306e;
      }
    }
    else {
      if (param_1 < 0x208023) {
        if (param_1 == 0x208008) {
          if (param_2 != 6) {
            return 0x56;
          }
          iVar1 = finn_write_buffer_constprop_0(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = 0;
          if (*(long *)(param_3 + 4) == 0) {
            return 0;
          }
          for (; uVar3 < param_3[6]; uVar3 = uVar3 + 1) {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer();
            if (iVar1 != 0) {
              return 2;
            }
          }
        }
        else {
          if (param_1 != 0x208020) {
            return 0x56;
          }
          if (param_2 != 0x83) {
            return 0x56;
          }
          iVar1 = finn_write_buffer_constprop_0(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_1();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          if (*(long *)(param_3 + 4) == 0) {
            return 0;
          }
          uVar3 = (ulong)param_3[1];
          if (param_3[1] == 0) goto LAB_00293a38;
          uVar3 = 0;
          do {
            iVar1 = finn_write_buffer_constprop_1(param_4);
            if (iVar1 != 0) {
              return 2;
            }
            iVar1 = finn_write_buffer();
            if (iVar1 != 0) {
              return 2;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < param_3[1]);
        }
        goto LAB_0029306e;
      }
      if (param_1 != 0x208024) {
        return 0x56;
      }
      if (param_2 != 2) {
        return 0x56;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)param_3 == 0) {
        return 0;
      }
      uVar3 = (ulong)param_3[3];
      if (param_3[3] != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_3[3]);
LAB_00293a46:
        if (param_5 == '\0') {
          return 0;
        }
        if (*(long *)param_3 == 0) {
          return 0;
        }
        goto LAB_002932f1;
      }
    }
  }
  else if (param_1 == 0x83de03) {
    if (param_2 == 0x15) {
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 4) == 0) {
        return 0;
      }
      uVar3 = (ulong)param_3[1];
      if (param_3[1] != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_3[1]);
        goto LAB_0029306e;
      }
    }
    else {
      if (param_2 != 0x16) {
        return 0x56;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      if (*(long *)(param_3 + 4) == 0) {
        return 0;
      }
      uVar3 = (ulong)param_3[1];
      if (param_3[1] != 0) {
        uVar3 = 0;
        do {
          iVar1 = finn_write_buffer_constprop_1(param_4);
          if (iVar1 != 0) {
            return 2;
          }
          iVar1 = finn_write_buffer();
          if (iVar1 != 0) {
            return 2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_3[1]);
LAB_0029306e:
        if ((param_5 == '\0') || (*(long *)(param_3 + 4) == 0)) {
          return 0;
        }
        goto LAB_002932f1;
      }
    }
  }
  else {
    if (param_1 != 0xb06f01) {
      if (param_1 != 0x402c01) {
        return 0x56;
      }
      if (param_2 != 2) {
        if (param_2 != 5) {
          return 0x56;
        }
        iVar1 = finn_write_buffer_constprop_0(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_2();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer_constprop_1();
        if (iVar1 == 0) {
          if (10 < param_3[3]) {
            return 0x1f;
          }
          iVar1 = finn_write_buffer_constprop_2();
          if (iVar1 == 0) {
            iVar1 = finn_write_buffer_constprop_1();
            if (iVar1 == 0) {
              uVar3 = finnSerializeUnion_NV402C_CTRL_I2C_TRANSACTION_DATA
                                (param_3 + 4,param_4,param_5,param_3[3]);
              return uVar3;
            }
            return 2;
          }
          return 2;
        }
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      if (4 < param_3[2]) {
        return 0x5b;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_1();
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = finn_write_buffer_constprop_2();
      if (iVar1 != 0) {
        return 2;
      }
      lVar5 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        lVar5 = lVar5 + 1;
      } while (lVar5 != 4);
      iVar1 = finn_write_buffer();
      if (iVar1 != 0) {
        return 2;
      }
      uVar3 = 0;
      if (*(long *)(param_3 + 6) == 0) {
        return 0;
      }
      for (; uVar3 < param_3[4]; uVar3 = uVar3 + 1) {
        iVar1 = finn_write_buffer_constprop_1(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
      }
LAB_002935e6:
      if (param_5 == '\0') {
        return 0;
      }
      if (*(long *)(param_3 + 6) == 0) {
        return 0;
      }
      goto LAB_002932f1;
    }
    if (param_2 == 0x11) {
      uVar3 = finnSerializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS_isra_0(param_3,param_4);
      return uVar3;
    }
    if (param_2 == 0x12) {
      iVar1 = finn_write_buffer_constprop_0(param_4);
      if (iVar1 != 0) {
        return 2;
      }
      uVar2 = finnSerializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS_isra_0(param_3,param_4);
      return (ulong)(uVar2 & 2);
    }
    if (param_2 != 0xc) {
      return 0x56;
    }
    iVar1 = finn_write_buffer_constprop_0(param_4);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_1();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer_constprop_2();
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = finn_write_buffer();
    if (iVar1 != 0) {
      return 2;
    }
    if (*(long *)(param_3 + 2) == 0) {
      return 0;
    }
    uVar3 = (ulong)param_3[1];
    if (param_3[1] != 0) {
      uVar3 = 0;
      do {
        iVar1 = finn_write_buffer_constprop_1(param_4);
        if (iVar1 != 0) {
          return 2;
        }
        iVar1 = finn_write_buffer();
        if (iVar1 != 0) {
          return 2;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3[1]);
      goto LAB_002932da;
    }
  }
LAB_00293a38:
  if (param_5 == '\0') {
    return uVar3;
  }
LAB_002932f1:
  portMemFree();
  return 0;
}


// ===== 00293aa0 finnDeserializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS.isra.0 =====

undefined8
finnDeserializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS_isra_0
          (ulong *param_1,undefined4 *param_2,ulong param_3)

{
  ulong *puVar1;
  ulong uVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  byte bVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  ulong uVar11;
  
  if (param_3 < 0x1008) {
    return 2;
  }
  lVar6 = finn_read_buffer_constprop_1();
  if (lVar6 != 0) {
    uVar5 = finn_read_buffer_constprop_2();
    *param_2 = uVar5;
    lVar6 = finn_read_buffer_constprop_1();
    if (lVar6 != 0) {
      uVar5 = finn_read_buffer_constprop_2();
      param_2[1] = uVar5;
      puVar10 = param_2 + 2;
      do {
        uVar7 = *param_1;
        if ((char)param_1[3] == '\0') {
          puVar1 = (ulong *)param_1[1];
          if (puVar1 < (ulong *)param_1[2]) {
            param_1[1] = (ulong)(puVar1 + 1);
            uVar2 = *puVar1;
            *(undefined1 *)(param_1 + 3) = 0x3f;
            uVar11 = uVar2 >> 1;
            *param_1 = uVar11;
            if ((uVar2 & 1) == 0 && uVar7 == 0) {
              return 0x6a;
            }
            uVar7 = uVar2;
            bVar4 = 0x3f;
          }
          else {
            *param_1 = 0;
            *(undefined1 *)(param_1 + 3) = 0x3f;
            if (uVar7 == 0) {
              return 0x6a;
            }
            uVar11 = 0;
            uVar7 = 0;
            bVar4 = 0x3f;
          }
LAB_00293b2c:
          uVar7 = uVar7 >> 9;
          bVar8 = 8;
        }
        else {
          bVar3 = (char)param_1[3] - 1;
          uVar11 = uVar7 >> 1;
          *(byte *)(param_1 + 3) = bVar3;
          *param_1 = uVar11;
          if ((uVar7 & 1) == 0) {
            return 0x6a;
          }
          bVar4 = bVar3;
          if (7 < bVar3) goto LAB_00293b2c;
          puVar1 = (ulong *)param_1[1];
          bVar8 = 8 - bVar3;
          if (puVar1 < (ulong *)param_1[2]) {
            param_1[1] = (ulong)(puVar1 + 1);
            bVar4 = 0x40;
            uVar11 = uVar11 | (~(-1L << (bVar8 & 0x3f)) & *puVar1) << (bVar3 & 0x3f);
            uVar7 = *puVar1 >> (bVar8 & 0x3f);
          }
          else {
            bVar4 = 0x40;
            uVar7 = 0;
          }
        }
        *param_1 = uVar7;
        puVar9 = (undefined4 *)((long)puVar10 + 1);
        *(byte *)(param_1 + 3) = bVar4 - bVar8;
        *(char *)puVar10 = (char)uVar11;
        puVar10 = puVar9;
        if (puVar9 == param_2 + 0x402) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x6a;
}


// ===== 00293c40 finnSerializeInternal_FINN_RM_API =====

/* WARNING: Removing unreachable block (ram,0x00293d50) */
/* WARNING: Removing unreachable block (ram,0x00293d70) */
/* WARNING: Removing unreachable block (ram,0x00293d55) */

undefined8
finnSerializeInternal_FINN_RM_API
          (undefined8 param_1,undefined8 param_2,long param_3,undefined8 *param_4,long param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  if (((param_3 == 0 || param_4 == (undefined8 *)0x0) || (param_5 == 0)) ||
     (((ulong)param_4 & 7) != 0)) {
    return 0x1f;
  }
  puVar1 = param_4 + 4;
  puVar5 = (undefined8 *)(param_5 + (long)param_4 & 0xfffffffffffffff8);
  param_4[3] = param_2;
  *param_4 = 0;
  param_4[1] = 0;
  param_4[2] = param_1;
  uVar2 = finnSerializeRoot_FINN_RM_API_constprop_0();
  if (puVar1 < puVar5) {
    *puVar1 = 0;
    puVar3 = param_4 + 5;
    if (puVar3 < puVar5) {
      if ((~(ulong)puVar1 + (long)puVar5 >> 3 & 1) != 0) {
        *puVar3 = 0;
        puVar3 = param_4 + 6;
        if (puVar5 <= puVar3) goto LAB_00293d38;
      }
      do {
        *puVar3 = 0;
        puVar4 = puVar3 + 2;
        puVar3[1] = 0;
        puVar3 = puVar4;
      } while (puVar4 < puVar5);
    }
  }
LAB_00293d38:
  if ((int)uVar2 == 0) {
    param_4[1] = (long)puVar1 - (long)param_4;
  }
  return uVar2;
}


// ===== 00293d80 finnDeserializeInternal_FINN_RM_API =====

ulong finnDeserializeInternal_FINN_RM_API
                (ulong *param_1,ulong param_2,uint *param_3,ulong param_4,char param_5)

{
  ulong uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  ulong *puVar10;
  ulong uVar11;
  ulong uVar12;
  int iVar13;
  ulong uVar14;
  uint *puVar15;
  uint *puVar16;
  undefined8 *puVar17;
  undefined8 local_48;
  ulong *local_40;
  long local_38;
  undefined1 local_30;
  
  if ((((param_1 == (ulong *)0x0) || (param_2 == 0)) || (param_3 == (uint *)0x0)) ||
     ((param_4 == 0 || (((ulong)param_1 & 7) != 0)))) {
    return 0x1f;
  }
  uVar12 = *param_1;
  if (uVar12 != 0) {
    return 0x6a;
  }
  if (((param_2 < 0x20) || (param_1[1] < 0x20)) || (param_2 < param_1[1])) {
    return 2;
  }
  local_40 = param_1 + 4;
  uVar14 = param_1[2];
  local_38 = param_2 + (long)param_1;
  local_48 = 0;
  uVar1 = param_1[3];
  local_30 = 0;
  uVar11 = 0;
  if (uVar14 == 0x208006) {
    if (uVar1 != 0x10) goto LAB_00294030;
    if (param_4 < 0x28) {
      return 2;
    }
    lVar7 = finn_read_buffer_constprop_1(&local_48);
    if (lVar7 != 0) {
      uVar4 = finn_read_buffer_constprop_2();
      *param_3 = uVar4;
      lVar7 = finn_read_buffer_constprop_1();
      if (lVar7 != 0) {
        uVar4 = finn_read_buffer_constprop_2();
        param_3[1] = uVar4;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar4 = finn_read_buffer_constprop_2();
          param_3[2] = uVar4;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar4 = finn_read_buffer_constprop_2();
            param_3[3] = uVar4;
            lVar7 = finn_read_buffer_constprop_1();
            if (lVar7 != 0) {
              uVar4 = finn_read_buffer_constprop_2();
              param_3[6] = uVar4;
              lVar7 = finn_read_buffer_constprop_1();
              if (lVar7 != 0) {
                uVar4 = finn_read_buffer_constprop_2();
                param_3[7] = uVar4;
                if (0x100 < uVar4) goto LAB_0029597c;
                lVar7 = finn_read_buffer_constprop_1();
                if (lVar7 != 0) {
                  uVar6 = finn_read_buffer_constprop_2();
                  param_3[8] = uVar6;
                  lVar7 = finn_read_buffer_constprop_1();
                  if (lVar7 != 0) {
                    uVar6 = finn_read_buffer_constprop_2();
                    param_3[9] = uVar6;
                    lVar7 = finn_read_buffer_constprop_1();
                    puVar10 = local_40;
                    if (lVar7 == 0) {
                      if (param_5 == '\0') {
                        param_3[4] = 0;
                        param_3[5] = 0;
                      }
                    }
                    else {
                      if (param_5 == '\0') {
                        if (uVar4 == 0) {
                          return 2;
                        }
                        lVar7 = portMemAllocNonPaged(uVar4);
                        *(long *)(param_3 + 4) = lVar7;
                        if (lVar7 == 0) goto LAB_00295e85;
                        portMemSet(lVar7,0,param_3[7]);
                      }
                      else if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
                      for (; uVar11 < param_3[7]; uVar11 = uVar11 + 1) {
                        local_40 = puVar10;
                        lVar7 = finn_read_buffer_constprop_1(&local_48);
                        if (lVar7 == 0) goto LAB_00293fb0;
                        uVar2 = finn_read_buffer_constprop_0();
                        *(undefined1 *)(*(long *)(param_3 + 4) + uVar11) = uVar2;
                        puVar10 = local_40;
                      }
                    }
                    goto LAB_002942d0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (uVar14 < 0x208007) {
    if (uVar14 == 0x8014) {
      if (uVar1 != 1) goto LAB_00294030;
      if (param_4 < 0x10) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar12 = finn_read_buffer_constprop_2();
        *param_3 = (uint)uVar12;
        if (3 < (uint)uVar12) goto LAB_0029597c;
        lVar7 = finn_read_buffer_constprop_1();
        puVar10 = local_40;
        if (lVar7 == 0) {
          if (param_5 == '\0') {
            param_3[2] = 0;
            param_3[3] = 0;
          }
        }
        else {
          if (param_5 == '\0') {
            if ((int)uVar12 == 0) {
              return 2;
            }
            lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
            *(long *)(param_3 + 2) = lVar7;
            if (lVar7 == 0) goto LAB_00295e85;
            portMemSet(lVar7,0,*param_3);
          }
          else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
          uVar12 = 0;
          local_40 = puVar10;
          if (*param_3 != 0) {
            do {
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 == 0) goto LAB_00293fb0;
              uVar2 = finn_read_buffer_constprop_0();
              *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
              uVar12 = uVar12 + 1;
              puVar10 = local_40;
            } while (uVar12 < *param_3);
          }
        }
        goto LAB_002942d0;
      }
    }
    else {
      if (0x8014 < uVar14) {
        if (uVar14 == 0x801b) {
          if (uVar1 == 1) {
            if (param_4 < 0x10) {
              return 2;
            }
            lVar7 = finn_read_buffer_constprop_1(&local_48);
            if (lVar7 != 0) {
              uVar12 = finn_read_buffer_constprop_2();
              *param_3 = (uint)uVar12;
              if (6 < (uint)uVar12) goto LAB_0029597c;
              lVar7 = finn_read_buffer_constprop_1();
              puVar10 = local_40;
              if (lVar7 == 0) {
                if (param_5 == '\0') {
                  param_3[2] = 0;
                  param_3[3] = 0;
                }
              }
              else {
                if (param_5 == '\0') {
                  if ((int)uVar12 == 0) {
                    return 2;
                  }
                  lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                  *(long *)(param_3 + 2) = lVar7;
                  if (lVar7 == 0) goto LAB_00295e85;
                  portMemSet(lVar7,0,*param_3);
                }
                else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
                uVar12 = 0;
                local_40 = puVar10;
                if (*param_3 != 0) {
                  do {
                    lVar7 = finn_read_buffer_constprop_1(&local_48);
                    if (lVar7 == 0) goto LAB_00293fb0;
                    uVar2 = finn_read_buffer_constprop_0();
                    *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
                    uVar12 = uVar12 + 1;
                    puVar10 = local_40;
                  } while (uVar12 < *param_3);
                }
              }
              goto LAB_002942d0;
            }
            goto LAB_00293fb0;
          }
        }
        else {
          if (uVar14 < 0x801c) {
            if (uVar14 == 0x8017) {
              if (uVar1 != 1) {
                if (uVar1 != 0xd) goto LAB_00294030;
                if (param_4 < 0x18) {
                  return 2;
                }
                lVar7 = finn_read_buffer_constprop_1(&local_48);
                if (lVar7 == 0) goto LAB_00293fb0;
                uVar14 = finn_read_buffer_constprop_2();
                *param_3 = (uint)uVar14;
                lVar7 = finn_read_buffer_constprop_1();
                puVar10 = local_40;
                if (lVar7 != 0) {
                  if (param_5 == '\0') {
                    if ((uVar14 & 0xffffffff) == 0) {
                      return 2;
                    }
                    lVar7 = portMemAllocNonPaged((uVar14 & 0xffffffff) << 2);
                    *(long *)(param_3 + 2) = lVar7;
                    if (lVar7 != 0) {
                      portMemSet(lVar7,0,(ulong)*param_3 << 2);
                      goto LAB_002952ab;
                    }
LAB_00295e85:
                    uVar14 = 0x51;
                    goto LAB_00294036;
                  }
                  if (*(long *)(param_3 + 2) != 0) {
LAB_002952ab:
                    local_40 = puVar10;
                    if (*param_3 != 0) {
                      uVar14 = 0;
                      do {
                        lVar7 = finn_read_buffer_constprop_1(&local_48);
                        if (lVar7 == 0) goto LAB_00293fb0;
                        uVar5 = finn_read_buffer_constprop_2();
                        *(undefined4 *)(*(long *)(param_3 + 2) + uVar14 * 4) = uVar5;
                        uVar14 = uVar14 + 1;
                      } while (uVar14 < *param_3);
                    }
                    lVar7 = finn_read_buffer_constprop_1(&local_48);
                    if (lVar7 == 0) {
                      puVar10 = local_40;
                      if (param_5 != '\0') goto LAB_002942d0;
                      goto LAB_00296121;
                    }
                    if (param_5 == '\0') goto LAB_00295d49;
                    goto LAB_00295ff4;
                  }
LAB_00295edb:
                  uVar14 = 0x3d;
                  goto LAB_00294036;
                }
                if (param_5 == '\0') {
                  param_3[2] = 0;
                  param_3[3] = 0;
                  lVar7 = finn_read_buffer_constprop_1();
                  if (lVar7 == 0) {
LAB_00296121:
                    param_3[4] = 0;
                    param_3[5] = 0;
                    puVar10 = local_40;
                    goto LAB_002942d0;
                  }
LAB_00295d49:
                  puVar10 = local_40;
                  if ((ulong)*param_3 == 0) {
                    return 2;
                  }
                  lVar7 = portMemAllocNonPaged((ulong)*param_3 << 2);
                  *(long *)(param_3 + 4) = lVar7;
                  if (lVar7 == 0) goto LAB_00295e85;
                  portMemSet(lVar7,0,(ulong)*param_3 << 2);
                  local_40 = puVar10;
                }
                else {
                  lVar7 = finn_read_buffer_constprop_1();
                  puVar10 = local_40;
                  if (lVar7 == 0) goto LAB_002942d0;
LAB_00295ff4:
                  if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
                }
                puVar10 = local_40;
                if (*param_3 != 0) {
                  do {
                    lVar7 = finn_read_buffer_constprop_1(&local_48);
                    if (lVar7 == 0) goto LAB_00293fb0;
                    uVar5 = finn_read_buffer_constprop_2();
                    *(undefined4 *)(*(long *)(param_3 + 4) + uVar12 * 4) = uVar5;
                    uVar12 = uVar12 + 1;
                    puVar10 = local_40;
                  } while (uVar12 < *param_3);
                }
                goto LAB_002942d0;
              }
              if (param_4 < 0x10) {
                return 2;
              }
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 != 0) {
                uVar12 = finn_read_buffer_constprop_2();
                *param_3 = (uint)uVar12;
                if (2 < (uint)uVar12) goto LAB_0029597c;
                lVar7 = finn_read_buffer_constprop_1();
                puVar10 = local_40;
                if (lVar7 == 0) {
                  if (param_5 == '\0') {
                    param_3[2] = 0;
                    param_3[3] = 0;
                  }
                }
                else {
                  if (param_5 == '\0') {
                    if ((int)uVar12 == 0) {
                      return 2;
                    }
                    lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                    *(long *)(param_3 + 2) = lVar7;
                    if (lVar7 == 0) goto LAB_00295e85;
                    portMemSet(lVar7,0,*param_3);
                  }
                  else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
                  uVar12 = 0;
                  local_40 = puVar10;
                  if (*param_3 != 0) {
                    do {
                      lVar7 = finn_read_buffer_constprop_1(&local_48);
                      if (lVar7 == 0) goto LAB_00293fb0;
                      uVar2 = finn_read_buffer_constprop_0();
                      *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
                      uVar12 = uVar12 + 1;
                      puVar10 = local_40;
                    } while (uVar12 < *param_3);
                  }
                }
                goto LAB_002942d0;
              }
            }
            else {
              if ((uVar14 != 0x8018) || (uVar1 != 0xf)) goto LAB_00294030;
              if (param_4 < 0x40) {
                return 2;
              }
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 != 0) {
                uVar4 = finn_read_buffer_constprop_2();
                *param_3 = uVar4;
                lVar7 = finn_read_buffer_constprop_1();
                if (lVar7 != 0) {
                  uVar4 = finn_read_buffer_constprop_2();
                  param_3[1] = uVar4;
                  lVar7 = finn_read_buffer_constprop_1();
                  if (lVar7 != 0) {
                    uVar4 = finn_read_buffer_constprop_2();
                    param_3[10] = uVar4;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      puVar15 = param_3 + 2;
                      uVar4 = finn_read_buffer_constprop_2();
                      param_3[0xe] = uVar4;
                      do {
                        lVar7 = finn_read_buffer_constprop_1(&local_48);
                        if ((lVar7 == 0) || (lVar7 = finn_read_buffer_constprop_1(), lVar7 == 0))
                        goto LAB_00293fb0;
                        uVar8 = finn_read_buffer();
                        *(undefined8 *)puVar15 = uVar8;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 == 0) goto LAB_00293fb0;
                        uVar4 = finn_read_buffer_constprop_2();
                        puVar15[2] = uVar4;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 == 0) goto LAB_00293fb0;
                        uVar4 = finn_read_buffer_constprop_2();
                        puVar16 = puVar15 + 4;
                        puVar15[3] = uVar4;
                        puVar15 = puVar16;
                      } while (puVar16 != param_3 + 10);
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 == 0) {
                        puVar10 = local_40;
                        if (param_5 == '\0') {
                          param_3[0xc] = 0;
                          param_3[0xd] = 0;
                        }
                      }
                      else {
                        if (param_5 == '\0') {
                          lVar7 = portMemAllocNonPaged(8);
                          *(long *)(param_3 + 0xc) = lVar7;
                          if (lVar7 == 0) goto LAB_00295e85;
                          portMemSet(lVar7,0,8);
                        }
                        else if (*(long *)(param_3 + 0xc) == 0) goto LAB_00295edb;
                        lVar7 = finn_read_buffer_constprop_1(&local_48);
                        if (lVar7 == 0) goto LAB_00293fb0;
                        puVar17 = *(undefined8 **)(param_3 + 0xc);
                        uVar8 = finn_read_buffer();
                        *puVar17 = uVar8;
                        puVar10 = local_40;
                      }
                      goto LAB_002942d0;
                    }
                  }
                }
              }
            }
            goto LAB_00293fb0;
          }
          if (uVar14 == 0x208001) {
            if (uVar1 == 0x24) {
              if (param_4 < 0x10) {
                return 2;
              }
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 != 0) {
                uVar4 = finn_read_buffer_constprop_2();
                *param_3 = uVar4;
                lVar7 = finn_read_buffer_constprop_1();
                if (lVar7 != 0) {
                  uVar12 = finn_read_buffer_constprop_2();
                  param_3[1] = (uint)uVar12;
                  lVar7 = finn_read_buffer_constprop_1();
                  puVar10 = local_40;
                  if (lVar7 == 0) {
                    if (param_5 == '\0') {
                      param_3[2] = 0;
                      param_3[3] = 0;
                    }
                  }
                  else {
                    if (param_5 == '\0') {
                      if ((uVar12 & 0xffffffff) == 0) {
                        return 2;
                      }
                      lVar7 = portMemAllocNonPaged((uVar12 & 0xffffffff) << 2);
                      *(long *)(param_3 + 2) = lVar7;
                      if (lVar7 == 0) goto LAB_00295e85;
                      portMemSet(lVar7,0,(ulong)param_3[1] << 2);
                    }
                    else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
                    uVar12 = 0;
                    local_40 = puVar10;
                    if (param_3[1] != 0) {
                      do {
                        lVar7 = finn_read_buffer_constprop_1(&local_48);
                        if (lVar7 == 0) goto LAB_00293fb0;
                        uVar5 = finn_read_buffer_constprop_2();
                        *(undefined4 *)(*(long *)(param_3 + 2) + uVar12 * 4) = uVar5;
                        uVar12 = uVar12 + 1;
                        puVar10 = local_40;
                      } while (uVar12 < param_3[1]);
                    }
                  }
                  goto LAB_002942d0;
                }
              }
            }
            else if (uVar1 == 0xe8) {
              if (param_4 < 0x20) {
                return 2;
              }
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 != 0) {
                uVar2 = finn_read_buffer_constprop_0();
                *(undefined1 *)param_3 = uVar2;
                lVar7 = finn_read_buffer_constprop_1();
                if (lVar7 != 0) {
                  uVar12 = finn_read_buffer_constprop_2();
                  param_3[1] = (uint)uVar12;
                  lVar7 = finn_read_buffer_constprop_1();
                  if (lVar7 != 0) {
                    uVar8 = finn_read_buffer();
                    *(undefined8 *)(param_3 + 2) = uVar8;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      uVar8 = finn_read_buffer();
                      *(undefined8 *)(param_3 + 4) = uVar8;
                      lVar7 = finn_read_buffer_constprop_1();
                      puVar10 = local_40;
                      if (lVar7 == 0) {
                        if (param_5 == '\0') {
                          param_3[6] = 0;
                          param_3[7] = 0;
                        }
                      }
                      else {
                        if (param_5 == '\0') {
                          if ((uVar12 & 0xffffffff) == 0) {
                            return 2;
                          }
                          lVar7 = portMemAllocNonPaged();
                          *(long *)(param_3 + 6) = lVar7;
                          if (lVar7 == 0) goto LAB_00295e85;
                          portMemSet(lVar7,0,(ulong)param_3[1] << 2);
                        }
                        else if (*(long *)(param_3 + 6) == 0) goto LAB_00295edb;
                        for (; uVar11 < param_3[1]; uVar11 = uVar11 + 1) {
                          local_40 = puVar10;
                          lVar7 = finn_read_buffer_constprop_1(&local_48);
                          if (lVar7 == 0) goto LAB_00293fb0;
                          uVar5 = finn_read_buffer_constprop_2();
                          *(undefined4 *)(*(long *)(param_3 + 6) + uVar11 * 4) = uVar5;
                          puVar10 = local_40;
                        }
                      }
                      goto LAB_002942d0;
                    }
                  }
                }
              }
            }
            else {
              if (uVar1 != 0x23) goto LAB_00294030;
              if (param_4 < 0x10) {
                return 2;
              }
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 != 0) {
                uVar12 = finn_read_buffer_constprop_2();
                *param_3 = (uint)uVar12;
                lVar7 = finn_read_buffer_constprop_1();
                puVar10 = local_40;
                if (lVar7 == 0) {
                  if (param_5 == '\0') {
                    param_3[2] = 0;
                    param_3[3] = 0;
                  }
                }
                else {
                  if (param_5 == '\0') {
                    if ((uVar12 & 0xffffffff) == 0) {
                      return 2;
                    }
                    lVar7 = portMemAllocNonPaged((uVar12 & 0xffffffff) << 2);
                    *(long *)(param_3 + 2) = lVar7;
                    if (lVar7 == 0) goto LAB_00295e85;
                    portMemSet(lVar7,0,(ulong)*param_3 << 2);
                  }
                  else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
                  uVar12 = 0;
                  local_40 = puVar10;
                  if (*param_3 != 0) {
                    do {
                      lVar7 = finn_read_buffer_constprop_1(&local_48);
                      if (lVar7 == 0) goto LAB_00293fb0;
                      uVar5 = finn_read_buffer_constprop_2();
                      *(undefined4 *)(*(long *)(param_3 + 2) + uVar12 * 4) = uVar5;
                      uVar12 = uVar12 + 1;
                      puVar10 = local_40;
                    } while (uVar12 < *param_3);
                  }
                }
                goto LAB_002942d0;
              }
            }
            goto LAB_00293fb0;
          }
        }
        goto LAB_00294030;
      }
      if (uVar14 == 0x8011) {
        if (uVar1 != 2) goto LAB_00294030;
        if (param_4 < 0x10) {
          return 2;
        }
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar12 = finn_read_buffer_constprop_2();
          *param_3 = (uint)uVar12;
          lVar7 = finn_read_buffer_constprop_1();
          puVar10 = local_40;
          if (lVar7 == 0) {
            if (param_5 == '\0') {
              param_3[2] = 0;
              param_3[3] = 0;
            }
          }
          else {
            if (param_5 == '\0') {
              if ((int)uVar12 == 0) {
                return 2;
              }
              lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
              *(long *)(param_3 + 2) = lVar7;
              if (lVar7 == 0) goto LAB_00295e85;
              portMemSet(lVar7,0,*param_3);
            }
            else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
            uVar12 = 0;
            local_40 = puVar10;
            if (*param_3 != 0) {
              do {
                lVar7 = finn_read_buffer_constprop_1(&local_48);
                if (lVar7 == 0) goto LAB_00293fb0;
                uVar2 = finn_read_buffer_constprop_0();
                *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
                uVar12 = uVar12 + 1;
                puVar10 = local_40;
              } while (uVar12 < *param_3);
            }
          }
          goto LAB_002942d0;
        }
      }
      else if (uVar14 < 0x8012) {
        if (uVar14 == 6) {
          if (uVar1 != 2) goto LAB_00294030;
          if (param_4 < 0x10) {
            return 2;
          }
          lVar7 = finn_read_buffer_constprop_1(&local_48);
          if (lVar7 != 0) {
            uVar4 = finn_read_buffer_constprop_2(&local_48);
            param_3[2] = uVar4;
            lVar7 = finn_read_buffer_constprop_1();
            if (lVar7 != 0) {
              uVar14 = finn_read_buffer_constprop_2();
              param_3[3] = (uint)uVar14;
              if (1000000 < (uint)uVar14) goto LAB_0029597c;
              lVar7 = finn_read_buffer_constprop_1();
              puVar10 = local_40;
              if (lVar7 == 0) {
                if (param_5 == '\0') {
                  param_3[0] = 0;
                  param_3[1] = 0;
                }
              }
              else {
                if (param_5 == '\0') {
                  if ((int)uVar14 == 0) {
                    return 2;
                  }
                  lVar7 = portMemAllocNonPaged(uVar14 & 0xffffffff);
                  *(long *)param_3 = lVar7;
                  if (lVar7 == 0) goto LAB_00295e85;
                  portMemSet(lVar7,0,param_3[3]);
                }
                else if (*(long *)param_3 == 0) goto LAB_00295edb;
                local_40 = puVar10;
                if (param_3[3] != 0) {
                  do {
                    lVar7 = finn_read_buffer_constprop_1(&local_48);
                    if (lVar7 == 0) goto LAB_00293fb0;
                    uVar2 = finn_read_buffer_constprop_0();
                    *(undefined1 *)(*(long *)param_3 + uVar12) = uVar2;
                    uVar12 = uVar12 + 1;
                    puVar10 = local_40;
                  } while (uVar12 < param_3[3]);
                }
              }
              goto LAB_002942d0;
            }
          }
        }
        else {
          if ((uVar14 != 0x8002) || (uVar1 != 1)) {
LAB_00294030:
            uVar14 = 0x56;
            goto LAB_00294036;
          }
          if (param_4 < 0x10) {
            return 2;
          }
          lVar7 = finn_read_buffer_constprop_1(&local_48);
          if (lVar7 != 0) {
            uVar12 = finn_read_buffer_constprop_2();
            *param_3 = (uint)uVar12;
            lVar7 = finn_read_buffer_constprop_1();
            puVar10 = local_40;
            if (lVar7 == 0) {
              if (param_5 == '\0') {
                param_3[2] = 0;
                param_3[3] = 0;
              }
            }
            else {
              if (param_5 == '\0') {
                if ((uVar12 & 0xffffffff) == 0) {
                  return 2;
                }
                lVar7 = portMemAllocNonPaged((uVar12 & 0xffffffff) << 2);
                *(long *)(param_3 + 2) = lVar7;
                if (lVar7 == 0) goto LAB_00295e85;
                portMemSet(lVar7,0,(ulong)*param_3 << 2);
              }
              else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
              uVar12 = 0;
              local_40 = puVar10;
              if (*param_3 != 0) {
                do {
                  lVar7 = finn_read_buffer_constprop_1(&local_48);
                  if (lVar7 == 0) goto LAB_00293fb0;
                  uVar5 = finn_read_buffer_constprop_2();
                  *(undefined4 *)(*(long *)(param_3 + 2) + uVar12 * 4) = uVar5;
                  uVar12 = uVar12 + 1;
                  puVar10 = local_40;
                } while (uVar12 < *param_3);
              }
            }
            goto LAB_002942d0;
          }
        }
      }
      else {
        if ((uVar14 != 0x8013) || (uVar1 != 1)) goto LAB_00294030;
        if (param_4 < 0x10) {
          return 2;
        }
        lVar7 = finn_read_buffer_constprop_1(&local_48);
        if (lVar7 != 0) {
          uVar12 = finn_read_buffer_constprop_2();
          *param_3 = (uint)uVar12;
          if (3 < (uint)uVar12) goto LAB_0029597c;
          lVar7 = finn_read_buffer_constprop_1();
          puVar10 = local_40;
          if (lVar7 == 0) {
            if (param_5 == '\0') {
              param_3[2] = 0;
              param_3[3] = 0;
            }
          }
          else {
            if (param_5 == '\0') {
              if ((int)uVar12 == 0) {
                return 2;
              }
              lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
              *(long *)(param_3 + 2) = lVar7;
              if (lVar7 == 0) goto LAB_00295e85;
              portMemSet(lVar7,0,*param_3);
            }
            else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
            uVar12 = 0;
            local_40 = puVar10;
            if (*param_3 != 0) {
              do {
                lVar7 = finn_read_buffer_constprop_1(&local_48);
                if (lVar7 == 0) goto LAB_00293fb0;
                uVar2 = finn_read_buffer_constprop_0();
                *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
                uVar12 = uVar12 + 1;
                puVar10 = local_40;
              } while (uVar12 < *param_3);
            }
          }
          goto LAB_002942d0;
        }
      }
    }
  }
  else if (uVar14 == 0x20802a) {
    if (uVar1 != 1) goto LAB_00294030;
    if (param_4 < 0x10) {
      return 2;
    }
    lVar7 = finn_read_buffer_constprop_1();
    if (lVar7 != 0) {
      uVar4 = finn_read_buffer_constprop_2();
      *param_3 = uVar4;
      lVar7 = finn_read_buffer_constprop_1();
      if (lVar7 != 0) {
        uVar12 = finn_read_buffer_constprop_2();
        param_3[1] = (uint)uVar12;
        if (2 < (uint)uVar12) goto LAB_0029597c;
        lVar7 = finn_read_buffer_constprop_1();
        puVar10 = local_40;
        if (lVar7 == 0) {
          if (param_5 == '\0') {
            param_3[2] = 0;
            param_3[3] = 0;
          }
        }
        else {
          if (param_5 == '\0') {
            if ((int)uVar12 == 0) {
              return 2;
            }
            lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
            *(long *)(param_3 + 2) = lVar7;
            if (lVar7 == 0) goto LAB_00295e85;
            portMemSet(lVar7,0,param_3[1]);
          }
          else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
          uVar12 = 0;
          local_40 = puVar10;
          if (param_3[1] != 0) {
            do {
              lVar7 = finn_read_buffer_constprop_1(&local_48);
              if (lVar7 == 0) goto LAB_00293fb0;
              uVar2 = finn_read_buffer_constprop_0();
              *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
              uVar12 = uVar12 + 1;
              puVar10 = local_40;
            } while (uVar12 < param_3[1]);
          }
        }
        goto LAB_002942d0;
      }
    }
  }
  else if (uVar14 < 0x20802b) {
    if (uVar14 == 0x208022) {
      if (uVar1 != 4) goto LAB_00294030;
      if (param_4 < 0x20) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar4 = finn_read_buffer_constprop_2();
        *param_3 = uVar4;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar8 = finn_read_buffer();
          *(undefined8 *)(param_3 + 2) = uVar8;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar12 = finn_read_buffer_constprop_2();
            param_3[6] = (uint)uVar12;
            lVar7 = finn_read_buffer_constprop_1();
            puVar10 = local_40;
            if (lVar7 == 0) {
              if (param_5 == '\0') {
                param_3[4] = 0;
                param_3[5] = 0;
              }
            }
            else {
              if (param_5 == '\0') {
                if ((int)uVar12 == 0) {
                  return 2;
                }
                lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                *(long *)(param_3 + 4) = lVar7;
                if (lVar7 == 0) goto LAB_00295e85;
                portMemSet(lVar7,0,param_3[6]);
              }
              else if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
              uVar12 = 0;
              local_40 = puVar10;
              if (param_3[6] != 0) {
                do {
                  lVar7 = finn_read_buffer_constprop_1(&local_48);
                  if (lVar7 == 0) goto LAB_00293fb0;
                  uVar2 = finn_read_buffer_constprop_0();
                  *(undefined1 *)(*(long *)(param_3 + 4) + uVar12) = uVar2;
                  uVar12 = uVar12 + 1;
                  puVar10 = local_40;
                } while (uVar12 < param_3[6]);
              }
            }
            goto LAB_002942d0;
          }
        }
      }
    }
    else if (uVar14 < 0x208023) {
      if (uVar14 == 0x208008) {
        if (uVar1 != 6) goto LAB_00294030;
        if (param_4 < 0x28) {
          return 2;
        }
        lVar7 = finn_read_buffer_constprop_1(&local_48);
        if (lVar7 != 0) {
          uVar3 = finn_read_buffer();
          *(undefined2 *)param_3 = uVar3;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar2 = finn_read_buffer_constprop_0();
            *(undefined1 *)((long)param_3 + 2) = uVar2;
            lVar7 = finn_read_buffer_constprop_1();
            if (lVar7 != 0) {
              uVar3 = finn_read_buffer();
              *(undefined2 *)(param_3 + 1) = uVar3;
              lVar7 = finn_read_buffer_constprop_1();
              if (lVar7 != 0) {
                uVar4 = finn_read_buffer_constprop_2();
                param_3[2] = uVar4;
                lVar7 = finn_read_buffer_constprop_1();
                if (lVar7 != 0) {
                  uVar4 = finn_read_buffer_constprop_2();
                  param_3[6] = uVar4;
                  lVar7 = finn_read_buffer_constprop_1();
                  if (lVar7 != 0) {
                    uVar6 = finn_read_buffer_constprop_2();
                    param_3[7] = uVar6;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      uVar6 = finn_read_buffer_constprop_2();
                      param_3[8] = uVar6;
                      lVar7 = finn_read_buffer_constprop_1();
                      puVar10 = local_40;
                      if (lVar7 == 0) {
                        if (param_5 == '\0') {
                          param_3[4] = 0;
                          param_3[5] = 0;
                        }
                      }
                      else {
                        if (param_5 == '\0') {
                          if (uVar4 == 0) {
                            return 2;
                          }
                          lVar7 = portMemAllocNonPaged(uVar4);
                          *(long *)(param_3 + 4) = lVar7;
                          if (lVar7 == 0) goto LAB_00295e85;
                          portMemSet(lVar7,0,param_3[6]);
                        }
                        else if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
                        for (; uVar11 < param_3[6]; uVar11 = uVar11 + 1) {
                          local_40 = puVar10;
                          lVar7 = finn_read_buffer_constprop_1(&local_48);
                          if (lVar7 == 0) goto LAB_00293fb0;
                          uVar2 = finn_read_buffer_constprop_0();
                          *(undefined1 *)(*(long *)(param_3 + 4) + uVar11) = uVar2;
                          puVar10 = local_40;
                        }
                      }
                      goto LAB_002942d0;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        if ((uVar14 != 0x208020) || (uVar1 != 0x83)) goto LAB_00294030;
        if (param_4 < 0x18) {
          return 2;
        }
        lVar7 = finn_read_buffer_constprop_1(&local_48);
        if (lVar7 != 0) {
          uVar2 = finn_read_buffer_constprop_0();
          *(undefined1 *)param_3 = uVar2;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar4 = finn_read_buffer_constprop_2();
            param_3[1] = uVar4;
            lVar7 = finn_read_buffer_constprop_1();
            if (lVar7 != 0) {
              uVar6 = finn_read_buffer_constprop_2();
              param_3[2] = uVar6;
              lVar7 = finn_read_buffer_constprop_1();
              if (lVar7 != 0) {
                uVar6 = finn_read_buffer_constprop_2();
                param_3[3] = uVar6;
                lVar7 = finn_read_buffer_constprop_1();
                puVar10 = local_40;
                if (lVar7 == 0) {
                  if (param_5 == '\0') {
                    param_3[4] = 0;
                    param_3[5] = 0;
                  }
                }
                else {
                  if (param_5 == '\0') {
                    if (uVar4 == 0) {
                      return 2;
                    }
                    lVar7 = portMemAllocNonPaged(uVar4);
                    *(long *)(param_3 + 4) = lVar7;
                    if (lVar7 == 0) goto LAB_00295e85;
                    portMemSet(lVar7,0,param_3[1]);
                  }
                  else if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
                  for (; uVar11 < param_3[1]; uVar11 = uVar11 + 1) {
                    local_40 = puVar10;
                    lVar7 = finn_read_buffer_constprop_1(&local_48);
                    if (lVar7 == 0) goto LAB_00293fb0;
                    uVar2 = finn_read_buffer_constprop_0();
                    *(undefined1 *)(*(long *)(param_3 + 4) + uVar11) = uVar2;
                    puVar10 = local_40;
                  }
                }
                goto LAB_002942d0;
              }
            }
          }
        }
      }
    }
    else {
      if ((uVar14 != 0x208024) || (uVar1 != 2)) goto LAB_00294030;
      if (param_4 < 0x10) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar4 = finn_read_buffer_constprop_2();
        param_3[2] = uVar4;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar12 = finn_read_buffer_constprop_2();
          param_3[3] = (uint)uVar12;
          lVar7 = finn_read_buffer_constprop_1();
          puVar10 = local_40;
          if (lVar7 == 0) {
            if (param_5 == '\0') {
              param_3[0] = 0;
              param_3[1] = 0;
            }
          }
          else {
            if (param_5 == '\0') {
              if ((int)uVar12 == 0) {
                return 2;
              }
              lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
              *(long *)param_3 = lVar7;
              if (lVar7 == 0) goto LAB_00295e85;
              portMemSet(lVar7,0,param_3[3]);
            }
            else if (*(long *)param_3 == 0) goto LAB_00295edb;
            uVar12 = 0;
            local_40 = puVar10;
            if (param_3[3] != 0) {
              do {
                lVar7 = finn_read_buffer_constprop_1(&local_48);
                if (lVar7 == 0) goto LAB_00293fb0;
                uVar2 = finn_read_buffer_constprop_0();
                *(undefined1 *)(*(long *)param_3 + uVar12) = uVar2;
                uVar12 = uVar12 + 1;
                puVar10 = local_40;
              } while (uVar12 < param_3[3]);
            }
          }
          goto LAB_002942d0;
        }
      }
    }
  }
  else if (uVar14 == 0x83de03) {
    if (uVar1 == 0x15) {
      if (param_4 < 0x18) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar4 = finn_read_buffer_constprop_2();
        *param_3 = uVar4;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar4 = finn_read_buffer_constprop_2();
          param_3[1] = uVar4;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar8 = finn_read_buffer();
            *(undefined8 *)(param_3 + 2) = uVar8;
            lVar7 = finn_read_buffer_constprop_1();
            puVar10 = local_40;
            if (lVar7 == 0) {
              if (param_5 == '\0') {
                param_3[4] = 0;
                param_3[5] = 0;
              }
            }
            else {
              if (param_5 == '\0') {
                if (uVar4 == 0) {
                  return 2;
                }
                lVar7 = portMemAllocNonPaged(uVar4);
                *(long *)(param_3 + 4) = lVar7;
                if (lVar7 == 0) goto LAB_00295e85;
                portMemSet(lVar7,0,param_3[1]);
              }
              else if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
              uVar12 = 0;
              local_40 = puVar10;
              if (param_3[1] != 0) {
                do {
                  lVar7 = finn_read_buffer_constprop_1(&local_48);
                  if (lVar7 == 0) goto LAB_00293fb0;
                  uVar2 = finn_read_buffer_constprop_0();
                  *(undefined1 *)(*(long *)(param_3 + 4) + uVar12) = uVar2;
                  uVar12 = uVar12 + 1;
                  puVar10 = local_40;
                } while (uVar12 < param_3[1]);
              }
            }
            goto LAB_002942d0;
          }
        }
      }
    }
    else {
      if (uVar1 != 0x16) goto LAB_00294030;
      if (param_4 < 0x18) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar4 = finn_read_buffer_constprop_2();
        *param_3 = uVar4;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar4 = finn_read_buffer_constprop_2();
          param_3[1] = uVar4;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar8 = finn_read_buffer();
            *(undefined8 *)(param_3 + 2) = uVar8;
            lVar7 = finn_read_buffer_constprop_1();
            puVar10 = local_40;
            if (lVar7 == 0) {
              if (param_5 == '\0') {
                param_3[4] = 0;
                param_3[5] = 0;
              }
            }
            else {
              if (param_5 == '\0') {
                if (uVar4 == 0) {
                  return 2;
                }
                lVar7 = portMemAllocNonPaged(uVar4);
                *(long *)(param_3 + 4) = lVar7;
                if (lVar7 == 0) goto LAB_00295e85;
                portMemSet(lVar7,0,param_3[1]);
              }
              else if (*(long *)(param_3 + 4) == 0) goto LAB_00295edb;
              uVar12 = 0;
              local_40 = puVar10;
              if (param_3[1] != 0) {
                do {
                  lVar7 = finn_read_buffer_constprop_1(&local_48);
                  if (lVar7 == 0) goto LAB_00293fb0;
                  uVar2 = finn_read_buffer_constprop_0();
                  *(undefined1 *)(*(long *)(param_3 + 4) + uVar12) = uVar2;
                  uVar12 = uVar12 + 1;
                  puVar10 = local_40;
                } while (uVar12 < param_3[1]);
              }
            }
            goto LAB_002942d0;
          }
        }
      }
    }
  }
  else if (uVar14 == 0xb06f01) {
    if (uVar1 == 0x11) {
LAB_00295996:
      uVar4 = finnDeserializeMessage_NVB06F_CTRL_SAVE_ENGINE_CTX_DATA_PARAMS_isra_0();
      uVar14 = (ulong)uVar4;
      puVar10 = local_40;
      if (uVar4 != 0) goto LAB_00294036;
LAB_002942d0:
      uVar14 = 0x1f;
      if (param_1[1] == (long)puVar10 - (long)param_1) {
        uVar14 = 0;
      }
      goto LAB_00294036;
    }
    if (uVar1 == 0x12) {
      if (param_4 < 0x1008) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) goto LAB_00295996;
    }
    else {
      if (uVar1 != 0xc) goto LAB_00294030;
      if (param_4 < 0x10) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar4 = finn_read_buffer_constprop_2();
        *param_3 = uVar4;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar12 = finn_read_buffer_constprop_2();
          param_3[1] = (uint)uVar12;
          lVar7 = finn_read_buffer_constprop_1();
          puVar10 = local_40;
          if (lVar7 == 0) {
            if (param_5 == '\0') {
              param_3[2] = 0;
              param_3[3] = 0;
            }
          }
          else {
            if (param_5 == '\0') {
              if ((int)uVar12 == 0) {
                return 2;
              }
              lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
              *(long *)(param_3 + 2) = lVar7;
              if (lVar7 == 0) goto LAB_00295e85;
              portMemSet(lVar7,0,param_3[1]);
            }
            else if (*(long *)(param_3 + 2) == 0) goto LAB_00295edb;
            uVar12 = 0;
            local_40 = puVar10;
            if (param_3[1] != 0) {
              do {
                lVar7 = finn_read_buffer_constprop_1(&local_48);
                if (lVar7 == 0) goto LAB_00293fb0;
                uVar2 = finn_read_buffer_constprop_0();
                *(undefined1 *)(*(long *)(param_3 + 2) + uVar12) = uVar2;
                uVar12 = uVar12 + 1;
                puVar10 = local_40;
              } while (uVar12 < param_3[1]);
            }
          }
          goto LAB_002942d0;
        }
      }
    }
  }
  else {
    if (uVar14 != 0x402c01) goto LAB_00294030;
    if (uVar1 == 2) {
      if (param_4 < 0x20) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1(&local_48);
      if (lVar7 != 0) {
        uVar2 = finn_read_buffer_constprop_0();
        *(undefined1 *)param_3 = uVar2;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar2 = finn_read_buffer_constprop_0();
          *(undefined1 *)((long)param_3 + 1) = uVar2;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar3 = finn_read_buffer();
            *(undefined2 *)((long)param_3 + 2) = uVar3;
            lVar7 = finn_read_buffer_constprop_1();
            if (lVar7 != 0) {
              uVar4 = finn_read_buffer_constprop_2();
              param_3[1] = uVar4;
              lVar7 = finn_read_buffer_constprop_1();
              if (lVar7 != 0) {
                uVar4 = finn_read_buffer_constprop_2();
                param_3[2] = uVar4;
                if (4 < uVar4) goto LAB_0029597c;
                lVar7 = finn_read_buffer_constprop_1();
                if (lVar7 != 0) {
                  uVar8 = finn_read_buffer_constprop_2();
                  lVar7 = 0;
                  param_3[4] = (uint)uVar8;
                  do {
                    lVar9 = finn_read_buffer_constprop_1(&local_48);
                    if (lVar9 == 0) goto LAB_00293fb0;
                    uVar2 = finn_read_buffer_constprop_0();
                    iVar13 = (int)uVar8;
                    *(undefined1 *)((long)param_3 + lVar7 + 0xc) = uVar2;
                    lVar7 = lVar7 + 1;
                  } while (lVar7 != 4);
                  lVar7 = finn_read_buffer_constprop_1();
                  puVar10 = local_40;
                  if (lVar7 == 0) {
                    if (param_5 == '\0') {
                      param_3[6] = 0;
                      param_3[7] = 0;
                    }
                  }
                  else {
                    if (param_5 == '\0') {
                      if (iVar13 == 0) {
                        return 2;
                      }
                      lVar7 = portMemAllocNonPaged(iVar13);
                      *(long *)(param_3 + 6) = lVar7;
                      if (lVar7 == 0) goto LAB_00295e85;
                      portMemSet(lVar7,0,param_3[4]);
                    }
                    else if (*(long *)(param_3 + 6) == 0) goto LAB_00295edb;
                    for (; uVar12 < param_3[4]; uVar12 = uVar12 + 1) {
                      local_40 = puVar10;
                      lVar7 = finn_read_buffer_constprop_1(&local_48);
                      if (lVar7 == 0) goto LAB_00293fb0;
                      uVar2 = finn_read_buffer_constprop_0();
                      *(undefined1 *)(*(long *)(param_3 + 6) + uVar12) = uVar2;
                      puVar10 = local_40;
                    }
                  }
                  goto LAB_002942d0;
                }
              }
            }
          }
        }
      }
    }
    else {
      if (uVar1 != 5) goto LAB_00294030;
      if (param_4 < 0x60) {
        return 2;
      }
      lVar7 = finn_read_buffer_constprop_1();
      if (lVar7 != 0) {
        uVar2 = finn_read_buffer_constprop_0();
        *(undefined1 *)param_3 = uVar2;
        lVar7 = finn_read_buffer_constprop_1();
        if (lVar7 != 0) {
          uVar4 = finn_read_buffer_constprop_2();
          param_3[1] = uVar4;
          lVar7 = finn_read_buffer_constprop_1();
          if (lVar7 != 0) {
            uVar3 = finn_read_buffer();
            *(undefined2 *)(param_3 + 2) = uVar3;
            lVar7 = finn_read_buffer_constprop_1();
            if (lVar7 != 0) {
              uVar14 = finn_read_buffer_constprop_2();
              uVar4 = (uint)uVar14;
              param_3[3] = uVar4;
              uVar14 = uVar14 & 0xffffffff;
              if (10 < uVar4) {
                return 0x1f;
              }
              lVar7 = finn_read_buffer_constprop_1();
              if (lVar7 != 0) {
                if (uVar4 == 5) {
                  lVar7 = finn_read_buffer_constprop_1();
                  if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                    uVar2 = finn_read_buffer_constprop_1();
                    *(undefined1 *)(param_3 + 4) = uVar2;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      uVar2 = finn_read_buffer_constprop_0();
                      *(undefined1 *)((long)param_3 + 0x11) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar3 = finn_read_buffer();
                        *(undefined2 *)((long)param_3 + 0x12) = uVar3;
                        puVar10 = local_40;
                        goto LAB_002942d0;
                      }
                    }
                  }
                }
                else if (uVar4 < 6) {
                  if (uVar4 == 2) {
                    lVar7 = finn_read_buffer_constprop_1();
                    if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                      uVar2 = finn_read_buffer_constprop_1();
                      *(undefined1 *)(param_3 + 4) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar12 = finn_read_buffer_constprop_2();
                        param_3[5] = (uint)uVar12;
                        lVar7 = finn_read_buffer_constprop_1();
                        puVar10 = local_40;
                        if (lVar7 == 0) {
                          if (param_5 == '\0') {
                            param_3[6] = 0;
                            param_3[7] = 0;
                          }
                        }
                        else {
                          if (param_5 == '\0') {
                            if ((int)uVar12 == 0) goto LAB_00294036;
                            lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                            *(long *)(param_3 + 6) = lVar7;
                            if (lVar7 == 0) goto LAB_00295e85;
                            portMemSet(lVar7,0,param_3[5]);
                          }
                          else if (*(long *)(param_3 + 6) == 0) goto LAB_00295edb;
                          for (; uVar11 < param_3[5]; uVar11 = uVar11 + 1) {
                            local_40 = puVar10;
                            lVar7 = finn_read_buffer_constprop_1(&local_48);
                            if (lVar7 == 0) goto LAB_00293fb0;
                            uVar2 = finn_read_buffer_constprop_0();
                            *(undefined1 *)(*(long *)(param_3 + 6) + uVar11) = uVar2;
                            puVar10 = local_40;
                          }
                        }
                        goto LAB_002942d0;
                      }
                    }
                  }
                  else if (uVar4 < 3) {
                    if (uVar4 == 0) {
                      lVar7 = finn_read_buffer_constprop_1();
                      if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                        uVar2 = finn_read_buffer_constprop_1();
                        *(undefined1 *)(param_3 + 4) = uVar2;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar4 = finn_read_buffer_constprop_2();
                          param_3[5] = uVar4;
                          puVar10 = local_40;
                          goto LAB_002942d0;
                        }
                      }
                    }
                    else {
                      lVar7 = finn_read_buffer_constprop_1();
                      if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                        uVar2 = finn_read_buffer_constprop_1();
                        *(undefined1 *)(param_3 + 4) = uVar2;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar2 = finn_read_buffer_constprop_0();
                          *(undefined1 *)((long)param_3 + 0x11) = uVar2;
                          puVar10 = local_40;
                          goto LAB_002942d0;
                        }
                      }
                    }
                  }
                  else if (uVar4 == 3) {
                    lVar7 = finn_read_buffer_constprop_1();
                    if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                      uVar2 = finn_read_buffer_constprop_1();
                      *(undefined1 *)(param_3 + 4) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar4 = finn_read_buffer_constprop_2();
                        param_3[5] = uVar4;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar2 = finn_read_buffer_constprop_0();
                          *(undefined1 *)(param_3 + 6) = uVar2;
                          lVar7 = finn_read_buffer_constprop_1();
                          if (lVar7 != 0) {
                            uVar12 = finn_read_buffer_constprop_2();
                            param_3[7] = (uint)uVar12;
                            lVar7 = finn_read_buffer_constprop_1();
                            puVar10 = local_40;
                            if (lVar7 == 0) {
                              if (param_5 == '\0') {
                                param_3[8] = 0;
                                param_3[9] = 0;
                              }
                            }
                            else {
                              if (param_5 == '\0') {
                                if ((int)uVar12 == 0) {
                                  return 2;
                                }
                                lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                                *(long *)(param_3 + 8) = lVar7;
                                if (lVar7 == 0) goto LAB_00295e85;
                                portMemSet(lVar7,0,param_3[7]);
                              }
                              else if (*(long *)(param_3 + 8) == 0) goto LAB_00295edb;
                              for (; uVar11 < param_3[7]; uVar11 = uVar11 + 1) {
                                local_40 = puVar10;
                                lVar7 = finn_read_buffer_constprop_1(&local_48);
                                if (lVar7 == 0) goto LAB_00293fb0;
                                uVar2 = finn_read_buffer_constprop_0();
                                *(undefined1 *)(*(long *)(param_3 + 8) + uVar11) = uVar2;
                                puVar10 = local_40;
                              }
                            }
                            goto LAB_002942d0;
                          }
                        }
                      }
                    }
                  }
                  else {
                    lVar7 = finn_read_buffer_constprop_1();
                    if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                      uVar2 = finn_read_buffer_constprop_1();
                      *(undefined1 *)(param_3 + 4) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar2 = finn_read_buffer_constprop_0();
                        *(undefined1 *)((long)param_3 + 0x11) = uVar2;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar2 = finn_read_buffer_constprop_0();
                          *(undefined1 *)((long)param_3 + 0x12) = uVar2;
                          puVar10 = local_40;
                          goto LAB_002942d0;
                        }
                      }
                    }
                  }
                }
                else if (uVar4 == 8) {
                  lVar7 = finn_read_buffer_constprop_1();
                  if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                    uVar2 = finn_read_buffer_constprop_0();
                    *(undefined1 *)(param_3 + 4) = uVar2;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      uVar4 = finn_read_buffer_constprop_2();
                      param_3[5] = uVar4;
                      if (uVar4 < 0x21) {
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 == 0) goto LAB_00293fb0;
                        uVar4 = finn_read_buffer_constprop_2();
                        param_3[0xe] = uVar4;
                        if (uVar4 < 0x21) {
                          lVar7 = 0;
                          do {
                            lVar9 = finn_read_buffer_constprop_1(&local_48);
                            if (lVar9 == 0) goto LAB_00293fb0;
                            uVar2 = finn_read_buffer_constprop_0();
                            *(undefined1 *)((long)param_3 + lVar7 + 0x18) = uVar2;
                            lVar7 = lVar7 + 1;
                            lVar9 = 0;
                          } while (lVar7 != 0x20);
                          do {
                            lVar7 = finn_read_buffer_constprop_1(&local_48);
                            if (lVar7 == 0) goto LAB_00293fb0;
                            uVar2 = finn_read_buffer_constprop_0();
                            *(undefined1 *)((long)param_3 + lVar9 + 0x3c) = uVar2;
                            lVar9 = lVar9 + 1;
                            puVar10 = local_40;
                          } while (lVar9 != 0x20);
                          goto LAB_002942d0;
                        }
                      }
LAB_0029597c:
                      uVar14 = 0x5b;
                      goto LAB_00294036;
                    }
                  }
                }
                else if (uVar4 < 9) {
                  if (uVar4 == 6) {
                    lVar7 = finn_read_buffer_constprop_1();
                    if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                      uVar2 = finn_read_buffer_constprop_1();
                      *(undefined1 *)(param_3 + 4) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar2 = finn_read_buffer_constprop_0();
                        *(undefined1 *)((long)param_3 + 0x11) = uVar2;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar12 = finn_read_buffer_constprop_2();
                          param_3[5] = (uint)uVar12;
                          lVar7 = finn_read_buffer_constprop_1();
                          puVar10 = local_40;
                          if (lVar7 == 0) {
                            if (param_5 == '\0') {
                              param_3[6] = 0;
                              param_3[7] = 0;
                            }
                          }
                          else {
                            if (param_5 == '\0') {
                              if ((int)uVar12 == 0) {
                                return 2;
                              }
                              lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                              *(long *)(param_3 + 6) = lVar7;
                              if (lVar7 == 0) goto LAB_00295e85;
                              portMemSet(lVar7,0,param_3[5]);
                            }
                            else if (*(long *)(param_3 + 6) == 0) goto LAB_00295edb;
                            for (; uVar11 < param_3[5]; uVar11 = uVar11 + 1) {
                              local_40 = puVar10;
                              lVar7 = finn_read_buffer_constprop_1(&local_48);
                              if (lVar7 == 0) goto LAB_00293fb0;
                              uVar2 = finn_read_buffer_constprop_0();
                              *(undefined1 *)(*(long *)(param_3 + 6) + uVar11) = uVar2;
                              puVar10 = local_40;
                            }
                          }
                          goto LAB_002942d0;
                        }
                      }
                    }
                  }
                  else {
                    lVar7 = finn_read_buffer_constprop_1();
                    if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                      uVar2 = finn_read_buffer_constprop_0();
                      *(undefined1 *)(param_3 + 4) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar3 = finn_read_buffer();
                        *(undefined2 *)((long)param_3 + 0x12) = uVar3;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar3 = finn_read_buffer();
                          *(undefined2 *)(param_3 + 5) = uVar3;
                          puVar10 = local_40;
                          goto LAB_002942d0;
                        }
                      }
                    }
                  }
                }
                else if (uVar4 == 9) {
                  lVar7 = finn_read_buffer_constprop_1();
                  if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                    uVar2 = finn_read_buffer_constprop_1();
                    *(undefined1 *)(param_3 + 4) = uVar2;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      uVar4 = finn_read_buffer_constprop_2();
                      param_3[5] = uVar4;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar4 = finn_read_buffer_constprop_2();
                        param_3[6] = uVar4;
                        if (4 < uVar4) goto LAB_0029597c;
                        lVar7 = finn_read_buffer_constprop_1();
                        if (lVar7 != 0) {
                          uVar8 = finn_read_buffer_constprop_2();
                          lVar7 = 0;
                          param_3[8] = (uint)uVar8;
                          do {
                            lVar9 = finn_read_buffer_constprop_1(&local_48);
                            if (lVar9 == 0) goto LAB_00293fb0;
                            uVar2 = finn_read_buffer_constprop_0();
                            iVar13 = (int)uVar8;
                            *(undefined1 *)((long)param_3 + lVar7 + 0x1c) = uVar2;
                            lVar7 = lVar7 + 1;
                          } while (lVar7 != 4);
                          lVar7 = finn_read_buffer_constprop_1();
                          puVar10 = local_40;
                          if (lVar7 == 0) {
                            if (param_5 == '\0') {
                              param_3[10] = 0;
                              param_3[0xb] = 0;
                            }
                          }
                          else {
                            if (param_5 == '\0') {
                              if (iVar13 == 0) {
                                return 2;
                              }
                              lVar7 = portMemAllocNonPaged(iVar13);
                              *(long *)(param_3 + 10) = lVar7;
                              if (lVar7 == 0) goto LAB_00295e85;
                              portMemSet(lVar7,0,param_3[8]);
                            }
                            else if (*(long *)(param_3 + 10) == 0) goto LAB_00295edb;
                            for (; uVar12 < param_3[8]; uVar12 = uVar12 + 1) {
                              local_40 = puVar10;
                              lVar7 = finn_read_buffer_constprop_1(&local_48);
                              if (lVar7 == 0) goto LAB_00293fb0;
                              uVar2 = finn_read_buffer_constprop_0();
                              *(undefined1 *)(*(long *)(param_3 + 10) + uVar12) = uVar2;
                              puVar10 = local_40;
                            }
                          }
                          goto LAB_002942d0;
                        }
                      }
                    }
                  }
                }
                else {
                  lVar7 = finn_read_buffer_constprop_1();
                  if ((lVar7 != 0) && (lVar7 = finn_read_buffer_constprop_1(), lVar7 != 0)) {
                    uVar2 = finn_read_buffer_constprop_0();
                    *(undefined1 *)(param_3 + 4) = uVar2;
                    lVar7 = finn_read_buffer_constprop_1();
                    if (lVar7 != 0) {
                      uVar2 = finn_read_buffer_constprop_0();
                      *(undefined1 *)((long)param_3 + 0x11) = uVar2;
                      lVar7 = finn_read_buffer_constprop_1();
                      if (lVar7 != 0) {
                        uVar12 = finn_read_buffer_constprop_2();
                        param_3[5] = (uint)uVar12;
                        lVar7 = finn_read_buffer_constprop_1();
                        puVar10 = local_40;
                        if (lVar7 == 0) {
                          if (param_5 == '\0') {
                            param_3[6] = 0;
                            param_3[7] = 0;
                          }
                        }
                        else {
                          if (param_5 == '\0') {
                            if ((int)uVar12 == 0) {
                              return 2;
                            }
                            lVar7 = portMemAllocNonPaged(uVar12 & 0xffffffff);
                            *(long *)(param_3 + 6) = lVar7;
                            if (lVar7 == 0) goto LAB_00295e85;
                            portMemSet(lVar7,0,param_3[5]);
                          }
                          else if (*(long *)(param_3 + 6) == 0) goto LAB_00295edb;
                          for (; uVar11 < param_3[5]; uVar11 = uVar11 + 1) {
                            local_40 = puVar10;
                            lVar7 = finn_read_buffer_constprop_1(&local_48);
                            if (lVar7 == 0) goto LAB_00293fb0;
                            uVar2 = finn_read_buffer_constprop_0();
                            *(undefined1 *)(*(long *)(param_3 + 6) + uVar11) = uVar2;
                            puVar10 = local_40;
                          }
                        }
                        goto LAB_002942d0;
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
LAB_00293fb0:
  uVar14 = 0x6a;
LAB_00294036:
  return uVar14 & 0xffffffff;
}


// ===== 002970c0 FinnRmApiGetSerializedSize =====

/* WARNING: Removing unreachable block (ram,0x0029712c) */
/* WARNING: Removing unreachable block (ram,0x00297116) */
/* WARNING: Removing unreachable block (ram,0x00297180) */
/* WARNING: Removing unreachable block (ram,0x0029711b) */
/* WARNING: Removing unreachable block (ram,0x0029714a) */
/* WARNING: Removing unreachable block (ram,0x0029714f) */
/* WARNING: Removing unreachable block (ram,0x00297160) */

undefined8 FinnRmApiGetSerializedSize(void)

{
  int iVar1;
  
  iVar1 = finnSerializeRoot_FINN_RM_API_constprop_0();
  if (iVar1 == 0) {
    return 0x20;
  }
  return 0;
}


// ===== 00297190 FinnRmApiGetUnserializedSize =====

uint FinnRmApiGetUnserializedSize(ulong param_1,ulong param_2)

{
  uint uVar1;
  
  if (param_1 == 0x208006) {
    uVar1 = 0;
    if (param_2 == 0x10) {
      uVar1 = 0x28;
    }
    return uVar1;
  }
  if (param_1 < 0x208007) {
    if (param_1 < 0x8015) {
      if ((0x8012 < param_1) || (param_1 == 0x8002)) {
LAB_00297249:
        return (uint)(param_2 == 1) << 4;
      }
      if ((param_1 == 0x8011) || (param_1 == 6)) {
LAB_002971dd:
        return (uint)(param_2 == 2) << 4;
      }
    }
    else {
      if (param_1 == 0x801b) goto LAB_00297249;
      if (param_1 < 0x801c) {
        if (param_1 == 0x8017) {
          if (param_2 == 1) {
            return 0x10;
          }
          uVar1 = 0;
          if (param_2 == 0xd) {
            uVar1 = 0x18;
          }
          return uVar1;
        }
        if (param_1 == 0x8018) {
          return (uint)(param_2 == 0xf) << 6;
        }
      }
      else if (param_1 == 0x208001) {
        if (param_2 < 0x25) {
          return (uint)(0x22 < param_2) << 4;
        }
        return (uint)(param_2 == 0xe8) << 5;
      }
    }
  }
  else {
    if (param_1 == 0x20802a) goto LAB_00297249;
    if (param_1 < 0x20802b) {
      if (param_1 == 0x208022) {
        return (uint)(param_2 == 4) << 5;
      }
      if (param_1 < 0x208023) {
        if (param_1 == 0x208008) {
          uVar1 = 0;
          if (param_2 == 6) {
            uVar1 = 0x28;
          }
          return uVar1;
        }
        if (param_1 == 0x208020) {
          uVar1 = 0;
          if (param_2 == 0x83) {
            uVar1 = 0x18;
          }
          return uVar1;
        }
      }
      else if (param_1 == 0x208024) goto LAB_002971dd;
    }
    else {
      if (param_1 == 0x83de03) {
        return -(uint)(param_2 - 0x15 < 2) & 0x18;
      }
      if (param_1 == 0xb06f01) {
        if (param_2 == 0xc) {
          return 0x10;
        }
        return -(uint)(param_2 - 0x11 < 2) & 0x1008;
      }
      if (param_1 == 0x402c01) {
        if (param_2 == 2) {
          return 0x20;
        }
        uVar1 = 0;
        if (param_2 == 5) {
          uVar1 = 0x60;
        }
        return uVar1;
      }
    }
  }
  return 0;
}


// ===== 002973b0 _fabricCacheInsert =====

undefined8
_fabricCacheInsert(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar1 = multimapFindItem_IMPL();
  if (lVar1 == 0) {
    lVar1 = multimapFindSubmap_IMPL(param_1,param_2);
    if (lVar1 == 0) {
      lVar1 = multimapInsertSubmap_IMPL(param_1,param_2);
      if (lVar1 != 0) {
        lVar3 = multimapInsertItemNew_IMPL(param_1,param_2,param_3);
        if (lVar3 != 0) {
          uVar4 = portMemAllocatorGetGlobalNonPaged();
          mapInit_IMPL(lVar3,uVar4,8);
          puVar2 = (undefined8 *)mapInsertNew_IMPL(lVar3,param_4);
          if (puVar2 != (undefined8 *)0x0) goto LAB_002973f2;
          mapDestroy_IMPL(lVar3);
          multimapRemoveItem_IMPL(param_1,lVar3);
        }
        multimapRemoveSubmap_IMPL(param_1,lVar1);
      }
    }
    else {
      lVar1 = multimapInsertItemNew_IMPL(param_1,param_2,param_3);
      if (lVar1 != 0) {
        uVar4 = portMemAllocatorGetGlobalNonPaged();
        mapInit_IMPL(lVar1,uVar4,8);
        puVar2 = (undefined8 *)mapInsertNew_IMPL(lVar1,param_4);
        if (puVar2 != (undefined8 *)0x0) goto LAB_002973f2;
        mapDestroy_IMPL(lVar1);
        multimapRemoveItem_IMPL(param_1,lVar1);
      }
    }
  }
  else {
    puVar2 = (undefined8 *)mapInsertNew_IMPL(lVar1,param_4);
    if (puVar2 != (undefined8 *)0x0) {
LAB_002973f2:
      *puVar2 = param_5;
      return 0;
    }
  }
  return 0x40;
}


// ===== 00297510 _fabricCacheDelete =====

void _fabricCacheDelete(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = multimapFindItem_IMPL();
  if (lVar2 != 0) {
    mapRemoveByKey_IMPL(lVar2,param_4);
    iVar1 = mapCount_IMPL(lVar2);
    if (iVar1 == 0) {
      mapDestroy_IMPL(lVar2);
      multimapRemoveItem_IMPL(param_1,lVar2);
      lVar2 = multimapFindSubmap_IMPL(param_1,param_2);
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pSubmap != NULL","src/kernel/compute/fabric.c",0x70);
        return;
      }
      iVar1 = mapCount_IMPL(lVar2);
      if (iVar1 == 0) {
        multimapRemoveSubmap_IMPL(param_1,lVar2);
        return;
      }
    }
  }
  return;
}


// ===== 002975f0 fabricWakeUpThreadCallback =====

void fabricWakeUpThreadCallback(void)

{
  osWakeUp();
  return;
}


// ===== 00297600 fabricSetImexEvent_IMPL =====

undefined8 fabricSetImexEvent_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_2 == 0) || (uVar1 = 0x17, *(long *)(param_1 + 0x100) == 0)) {
    *(long *)(param_1 + 0x100) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00297630 fabricGetImexEvent_IMPL =====

undefined8 fabricGetImexEvent_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x100);
}


// ===== 00297640 fabricSetNodeId_IMPL =====

void fabricSetNodeId_IMPL(long param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x108) = param_2;
  return;
}


// ===== 00297650 fabricGetNodeId_IMPL =====

undefined2 fabricGetNodeId_IMPL(long param_1)

{
  return *(undefined2 *)(param_1 + 0x108);
}


// ===== 00297660 fabricIsMemAllocDisabled_IMPL =====

bool fabricIsMemAllocDisabled_IMPL(long param_1)

{
  return *(char *)(param_1 + 0x118) == '\0';
}


// ===== 00297670 fabricDisableMemAlloc_IMPL =====

void fabricDisableMemAlloc_IMPL(long param_1)

{
  *(undefined1 *)(param_1 + 0x118) = 0;
  return;
}


// ===== 00297680 fabricEnableMemAlloc_IMPL =====

void fabricEnableMemAlloc_IMPL(long param_1)

{
  *(undefined1 *)(param_1 + 0x118) = 1;
  return;
}


// ===== 00297690 fabricExtractEventsV2_IMPL =====

bool fabricExtractEventsV2_IMPL(long param_1,long param_2,uint *param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  
  lVar1 = param_1 + 0x60;
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x88));
  uVar4 = 0;
  if (*param_3 != 0) {
    uVar4 = 0;
    do {
      lVar3 = listHead_IMPL(lVar1);
      if (lVar3 == 0) break;
      portMemCopy(param_2,0x58,lVar3,0x58);
      uVar4 = uVar4 + 1;
      listRemove_IMPL(lVar1,lVar3);
      param_2 = param_2 + 0x58;
    } while (uVar4 < *param_3);
  }
  *param_3 = uVar4;
  iVar2 = listCount_IMPL(lVar1);
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x88));
  return iVar2 != 0;
}


// ===== 00297740 fabricFlushUnhandledEvents_IMPL =====

void fabricFlushUnhandledEvents_IMPL(long param_1)

{
  long lVar1;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x88));
  while( true ) {
    lVar1 = listHead_IMPL(param_1 + 0x60);
    if (lVar1 == 0) break;
    listRemove_IMPL(param_1 + 0x60,lVar1);
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x88));
  return;
}


// ===== 002977a0 fabricGenerateEventId_IMPL =====

long fabricGenerateEventId_IMPL(long param_1)

{
  long *plVar1;
  long lVar2;
  
  LOCK();
  plVar1 = (long *)(param_1 + 0x110);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  return lVar2 + 1;
}


// ===== 002977c0 fabricImportCacheInsert_IMPL =====

undefined4
fabricImportCacheInsert_IMPL(long param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0xc0));
  uVar1 = _fabricCacheInsert(param_1 + 0x90,param_2[1],*param_2,param_3,param_4);
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0xc0));
  return uVar1;
}


// ===== 00297820 fabricImportCacheDelete_IMPL =====

void fabricImportCacheDelete_IMPL(long param_1,undefined8 *param_2,undefined8 param_3)

{
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0xc0));
  _fabricCacheDelete(param_1 + 0x90,param_2[1],*param_2,param_3);
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0xc0));
  return;
}


// ===== 00297880 fabricImportCacheGet_IMPL =====

undefined8 fabricImportCacheGet_IMPL(long param_1,undefined8 *param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0xc0));
  lVar1 = multimapFindItem_IMPL(param_1 + 0x90,param_2[1],*param_2);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)mapFind_IMPL(lVar1,param_3);
    portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0xc0));
    uVar3 = 0;
    if (puVar2 != (undefined8 *)0x0) {
      uVar3 = *puVar2;
    }
    return uVar3;
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0xc0));
  return 0;
}


// ===== 00297920 fabricUnimportCacheGet_IMPL =====

undefined8 fabricUnimportCacheGet_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0xf8));
  lVar1 = multimapFindItem_IMPL(param_1 + 200,param_2,0);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)mapFind_IMPL(lVar1,0);
    portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0xf8));
    uVar3 = 0;
    if (puVar2 != (undefined8 *)0x0) {
      uVar3 = *puVar2;
    }
    return uVar3;
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0xf8));
  return 0;
}


// ===== 002979a0 _fabricWaitOnUnimportCallback =====

void _fabricWaitOnUnimportCallback(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(g_pSys + 0x260);
  lVar2 = fabricUnimportCacheGet_IMPL(lVar1,param_1);
  if (lVar2 != 0) {
    osWaitInterruptible(lVar2);
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0xf8));
    _fabricCacheDelete(lVar1 + 200,param_1,0,0);
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0xf8));
    osFreeWaitQueue(lVar2);
    return;
  }
  return;
}


// ===== 00297a30 fabricPostEventsV2_IMPL =====

int fabricPostEventsV2_IMPL(long param_1,char *param_2,uint param_3)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  code *local_40;
  
  if (param_3 == 0) {
    return 0;
  }
  uVar9 = 0;
  lVar10 = param_1 + 0x60;
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x88));
  do {
    lVar5 = listAppendNew_IMPL(lVar10);
    if (lVar5 == 0) {
      iVar3 = 0x51;
LAB_00297af4:
      if (uVar9 == 0) goto LAB_00297bf6;
      goto LAB_00297b00;
    }
    local_58 = 0;
    lVar7 = *(long *)(g_pSys + 0x260);
    local_50 = 0;
    if (*param_2 == '\x01') {
      iVar3 = threadStateGetCurrent(&local_58,0);
      if (iVar3 == 0) {
        local_48 = *(undefined8 *)(param_2 + 8);
        local_40 = _fabricWaitOnUnimportCallback;
        iVar3 = osAllocWaitQueue(&local_50);
        lVar2 = local_50;
        if (iVar3 == 0) {
          uVar1 = *(undefined8 *)(param_2 + 8);
          portSyncRwLockAcquireWrite(*(undefined8 *)(lVar7 + 0xf8));
          iVar3 = _fabricCacheInsert(lVar7 + 200,uVar1,0,0,lVar2);
          portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0xf8));
          if (iVar3 == 0) {
            iVar3 = threadStateEnqueueCallbackOnFree(local_58,&local_48);
            if (iVar3 == 0) goto LAB_00297a80;
          }
          else {
            iVar3 = 0x40;
          }
          uVar1 = *(undefined8 *)(param_2 + 8);
          portSyncRwLockAcquireWrite(*(undefined8 *)(lVar7 + 0xf8));
          _fabricCacheDelete(lVar7 + 200,uVar1,0,0);
          portSyncRwLockReleaseWrite(*(undefined8 *)(lVar7 + 0xf8));
          if (local_50 != 0) {
            osFreeWaitQueue();
          }
        }
      }
      goto LAB_00297af4;
    }
LAB_00297a80:
    portMemCopy(lVar5,0x58,param_2);
    uVar9 = uVar9 + 1;
    param_2 = param_2 + 0x58;
  } while (param_3 != uVar9);
  if (*(long *)(param_1 + 0x100) == 0) {
    iVar3 = 0x55;
    nvDbg_Printf("src/kernel/compute/fabric.c",0x112,"_fabricNotifyEvent",4,
                 "NVRM: Unable to notify ImexSessionApi\n");
LAB_00297b00:
    uVar8 = 0;
    do {
      pcVar6 = (char *)listTail_IMPL(lVar10);
      if (*pcVar6 == '\x01') {
        lVar5 = *(long *)(g_pSys + 0x260);
        iVar4 = threadStateGetCurrent(&local_50,0);
        if (iVar4 == 0) {
          local_40 = _fabricWaitOnUnimportCallback;
          local_48 = *(undefined8 *)(pcVar6 + 8);
          threadStateRemoveCallbackOnFree(local_50,&local_48);
          lVar7 = fabricUnimportCacheGet_IMPL(lVar5,*(undefined8 *)(pcVar6 + 8));
          if (lVar7 != 0) {
            uVar1 = *(undefined8 *)(pcVar6 + 8);
            portSyncRwLockAcquireWrite(*(undefined8 *)(lVar5 + 0xf8));
            _fabricCacheDelete(lVar5 + 200,uVar1,0,0);
            portSyncRwLockReleaseWrite(*(undefined8 *)(lVar5 + 0xf8));
            osFreeWaitQueue(lVar7);
          }
        }
        else {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/compute/fabric.c",0xd0);
        }
      }
      uVar8 = uVar8 + 1;
      listRemove_IMPL(lVar10);
    } while (uVar8 < uVar9);
  }
  else {
    iVar3 = 0;
    osSetEvent(0);
  }
LAB_00297bf6:
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x88));
  return iVar3;
}


// ===== 00297d60 fabricUnimportCacheInvokeCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */

undefined8 fabricUnimportCacheInvokeCallback_IMPL(long param_1,undefined8 param_2,code *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0xf8));
  lVar1 = multimapFindItem_IMPL(param_1 + 200,param_2,0);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)mapFind_IMPL(lVar1,0);
    if (puVar2 != (undefined8 *)0x0) {
      (*param_3)(*puVar2);
      uVar3 = 1;
      goto LAB_00297db9;
    }
  }
  uVar3 = 0;
LAB_00297db9:
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0xf8));
  return uVar3;
}


// ===== 00297de0 fabricUnimportCacheIterateAll_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */

void fabricUnimportCacheIterateAll_IMPL(long param_1,code *param_2)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0xf8));
  uVar3 = multimapLastItem_IMPL(param_1 + 200);
  uVar4 = multimapFirstItem_IMPL(param_1 + 200);
  multimapItemIterRange_IMPL(&local_88,param_1 + 200,uVar4,uVar3);
  local_68 = local_88;
  local_60 = local_80;
  local_58 = local_78;
  local_50 = local_70;
  while( true ) {
    cVar2 = multimapItemIterNext_IMPL(&local_68);
    puVar1 = local_68;
    if (cVar2 == '\0') break;
    uVar3 = mapFindLEQ_IMPL(local_68,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(puVar1,0);
    mapIterRange_IMPL(&local_88,puVar1,uVar4,uVar3);
    local_48 = local_88;
    local_40 = local_80;
    local_38 = local_78;
    local_30 = local_70;
    while( true ) {
      cVar2 = mapIterNext_IMPL(&local_48);
      if (cVar2 == '\0') break;
      (*param_2)(*local_48);
    }
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0xf8));
  return;
}


// ===== 00297f00 fabricMulticastSetupCacheInsert_IMPL =====

undefined4 fabricMulticastSetupCacheInsert_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x150));
  uVar1 = _fabricCacheInsert(param_1 + 0x120,0,param_2,0,param_3);
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x150));
  return uVar1;
}


// ===== 00297f60 fabricMulticastSetupCacheDelete_IMPL =====

void fabricMulticastSetupCacheDelete_IMPL(long param_1,undefined8 param_2)

{
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x150));
  _fabricCacheDelete(param_1 + 0x120,0,param_2,0);
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x150));
  return;
}


// ===== 00297fa0 fabricMulticastSetupCacheGet_IMPL =====

undefined8 fabricMulticastSetupCacheGet_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x150));
  lVar1 = multimapFindItem_IMPL(param_1 + 0x120,0,param_2);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)mapFind_IMPL(lVar1,0);
    portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x150));
    uVar3 = 0;
    if (puVar2 != (undefined8 *)0x0) {
      uVar3 = *puVar2;
    }
    return uVar3;
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x150));
  return 0;
}


// ===== 00298020 fabricMulticastCleanupCacheInsert_IMPL =====

undefined4
fabricMulticastCleanupCacheInsert_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x150));
  uVar1 = _fabricCacheInsert(param_1 + 0x120,1,param_2,0,param_3);
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x150));
  return uVar1;
}


// ===== 00298080 fabricMulticastCleanupCacheGet_IMPL =====

undefined8 fabricMulticastCleanupCacheGet_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  portSyncRwLockAcquireRead(*(undefined8 *)(param_1 + 0x150));
  lVar1 = multimapFindItem_IMPL(param_1 + 0x120,1,param_2);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)mapFind_IMPL(lVar1,0);
    portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x150));
    uVar3 = 0;
    if (puVar2 != (undefined8 *)0x0) {
      uVar3 = *puVar2;
    }
    return uVar3;
  }
  portSyncRwLockReleaseRead(*(undefined8 *)(param_1 + 0x150));
  return 0;
}


// ===== 00298100 fabricMulticastCleanupCacheInvokeCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */

void fabricMulticastCleanupCacheInvokeCallback_IMPL(long param_1,undefined8 param_2,code *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  
  portSyncRwLockAcquireWrite(*(undefined8 *)(param_1 + 0x150));
  lVar1 = multimapFindItem_IMPL(param_1 + 0x120,1,param_2);
  if (lVar1 != 0) {
    puVar2 = (undefined8 *)mapFind_IMPL(lVar1,0);
    if (puVar2 != (undefined8 *)0x0) {
      (*param_3)(*puVar2);
    }
  }
  portSyncRwLockReleaseWrite(*(undefined8 *)(param_1 + 0x150));
  return;
}


// ===== 00298170 fabricSetFmSessionFlags_IMPL =====

void fabricSetFmSessionFlags_IMPL(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x58) = param_2;
  return;
}


// ===== 00298180 fabricGetFmSessionFlags_IMPL =====

undefined4 fabricGetFmSessionFlags_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0x58);
}


// ===== 00298190 fabricDestruct_IMPL =====

/* WARNING: Type propagation algorithm not settling */

void fabricDestruct_IMPL(long param_1)

{
  short sVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x144) != 0) {
    nvAssertFailedNoLog("multimapCountItems(&pFabric->fabricMulticastCache) == 0",
                        "src/kernel/compute/fabric.c",0x38c);
  }
  multimapDestroy_IMPL(param_1 + 0x120);
  if (*(long *)(param_1 + 0x50) != 0) {
    portSyncRwLockDestroy();
  }
  if (*(long *)(param_1 + 0x150) != 0) {
    portSyncRwLockDestroy();
  }
  iVar2 = listCount_IMPL(param_1 + 0x60);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0xec);
  }
  else {
    nvAssertFailedNoLog("listCount(&pFabric->fabricEventListV2) == 0","src/kernel/compute/fabric.c",
                        0x396);
    iVar2 = *(int *)(param_1 + 0xec);
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0xb4);
  }
  else {
    nvAssertFailedNoLog("multimapCountItems(&pFabric->unimportCache) == 0",
                        "src/kernel/compute/fabric.c",0x398);
    iVar2 = *(int *)(param_1 + 0xb4);
  }
  if (iVar2 == 0) {
    sVar1 = *(short *)(param_1 + 0x108);
  }
  else {
    nvAssertFailedNoLog("multimapCountItems(&pFabric->importCache) == 0",
                        "src/kernel/compute/fabric.c",0x399);
    sVar1 = *(short *)(param_1 + 0x108);
  }
  if (sVar1 != -1) {
    nvAssertFailedNoLog("pFabric->nodeId == NV_FABRIC_INVALID_NODE_ID","src/kernel/compute/fabric.c"
                        ,0x39b);
  }
  if (*(long *)(param_1 + 0x48) != 0) {
    portSyncRwLockDestroy();
  }
  if (*(long *)(param_1 + 0xf8) != 0) {
    portSyncRwLockDestroy();
  }
  if (*(long *)(param_1 + 0xc0) != 0) {
    portSyncRwLockDestroy();
  }
  if (*(long *)(param_1 + 0x88) != 0) {
    portSyncRwLockDestroy();
  }
  multimapDestroy_IMPL(param_1 + 200);
  multimapDestroy_IMPL(param_1 + 0x90);
  listDestroy_IMPL(param_1 + 0x60);
  return;
}


// ===== 00298350 fabricConstruct_IMPL =====

undefined8 fabricConstruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x60,uVar1,0x58);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(param_1 + 0x90,uVar1,0x20,0x20,0x10);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(param_1 + 200,uVar1,0x20,0x20,0x10);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(param_1 + 0x120,uVar1,0x20,0x20,0x10);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  lVar2 = portSyncRwLockCreate(uVar1);
  *(long *)(param_1 + 0x88) = lVar2;
  if (lVar2 != 0) {
    uVar1 = portMemAllocatorGetGlobalNonPaged();
    lVar2 = portSyncRwLockCreate(uVar1);
    *(long *)(param_1 + 0xc0) = lVar2;
    if (lVar2 != 0) {
      uVar1 = portMemAllocatorGetGlobalNonPaged();
      lVar2 = portSyncRwLockCreate(uVar1);
      *(long *)(param_1 + 0xf8) = lVar2;
      if (lVar2 != 0) {
        uVar1 = portMemAllocatorGetGlobalNonPaged();
        lVar2 = portSyncRwLockCreate(uVar1);
        *(long *)(param_1 + 0x48) = lVar2;
        if (lVar2 != 0) {
          *(undefined1 *)(param_1 + 0x118) = 1;
          *(undefined2 *)(param_1 + 0x108) = 0xffff;
          uVar1 = portMemAllocatorGetGlobalNonPaged();
          lVar2 = portSyncRwLockCreate(uVar1);
          *(long *)(param_1 + 0x50) = lVar2;
          if (lVar2 != 0) {
            uVar1 = portMemAllocatorGetGlobalNonPaged();
            lVar2 = portSyncRwLockCreate(uVar1);
            *(long *)(param_1 + 0x150) = lVar2;
            if (lVar2 != 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  fabricDestruct_IMPL(param_1);
  return 0x51;
}


// ===== 002984b0 fabricMulticastWaitOnTeamCleanupCallback =====

void fabricMulticastWaitOnTeamCleanupCallback(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(g_pSys + 0x260);
  lVar2 = fabricMulticastCleanupCacheGet_IMPL(lVar1,param_1);
  if (lVar2 != 0) {
    osWaitInterruptible(lVar2);
    portSyncRwLockAcquireWrite(*(undefined8 *)(lVar1 + 0x150));
    _fabricCacheDelete(lVar1 + 0x120,1,param_1,0);
    portSyncRwLockReleaseWrite(*(undefined8 *)(lVar1 + 0x150));
    osFreeWaitQueue(lVar2);
    return;
  }
  return;
}


// ===== 00298540 _clearFmState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _clearFmState(char param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  lVar4 = g_pSys;
  uVar2 = fabricGetFmSessionFlags_IMPL(*(undefined8 *)(g_pSys + 0x260));
  if (*(char *)(lVar4 + 0x6c) == '\0') {
    nvDbg_Printf("src/kernel/compute/fm_session_api.c",0x53,"_clearFmState",1,
                 "NVRM: Fabric manager state is already cleared.\n");
    return;
  }
  *(undefined1 *)(lVar4 + 0x6c) = 0;
  nvDbg_Printf("src/kernel/compute/fm_session_api.c",0x5a,"_clearFmState",1,
               "NVRM: Fabric manager state is cleared.\n");
  if ((uVar2 & 1) != 0) {
    return;
  }
  local_34 = 0;
  local_30 = 0;
  local_2c[0] = 0;
  cVar1 = rmGpuLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/compute/fm_session_api.c",0x34);
  }
  gpumgrGetGpuAttachInfo(&local_30,&local_34);
  while( true ) {
    lVar4 = gpumgrGetNextGpu(local_34,local_2c);
    if (lVar4 == 0) break;
    iVar3 = (**(code **)(lVar4 + 0x3b90))
                      (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                       *(undefined4 *)(lVar4 + 0x3b3c),0x20800a4a,0,0);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/compute/fm_session_api.c",0x43,"_clearOutstandingComputeChannels",4);
    }
  }
  if (param_1 == '\0') {
    pcVar6 = "NVRM: nvidia-fabricmanager daemon has invoked robust channel recovery!\n";
    uVar5 = 0x66;
  }
  else {
    pcVar6 = 
    "NVRM: nvidia-fabricmanager daemon shutdown detected, robust channel recovery invoked!\n";
    uVar5 = 0x62;
  }
  nvDbg_Printf("src/kernel/compute/fm_session_api.c",uVar5,"_clearFmState",4,pcVar6);
  return;
}


// ===== 00298730 fmsessionapiConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int fmsessionapiConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  long *plVar6;
  
  lVar3 = g_pSys;
  lVar1 = *(long *)(g_pSys + 0x260);
  plVar6 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (plVar6 == (long *)0x0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/compute/fm_session_api.c",0x79);
    iVar5 = 0x23;
  }
  else {
    puVar2 = *(undefined8 **)(param_3 + 0x40);
    osRmCapInitDescriptor(param_1 + 0xd8);
    if (*(uint *)(param_2 + 0x28) < 2) {
      if (*(char *)(lVar3 + 0x6d) == '\0') {
        iVar5 = osRmCapAcquire(0,0x200,*puVar2,param_1 + 0xd8);
        if (iVar5 == 0x56) {
          cVar4 = (**(code **)(*plVar6 + 0xe0))(plVar6,*(undefined4 *)(param_2 + 0x28));
          if (cVar4 == '\0') {
            nvDbg_Printf("src/kernel/compute/fm_session_api.c",0x9c,"fmsessionapiConstruct_IMPL",4,
                         "NVRM: insufficient permissions\n");
            return 0x1b;
          }
        }
        else if (iVar5 != 0) {
          nvDbg_Printf("src/kernel/compute/fm_session_api.c",0xa2,"fmsessionapiConstruct_IMPL",4,
                       "NVRM: Capability validation failed\n");
          return iVar5;
        }
        if (lVar1 != 0) {
          fabricSetFmSessionFlags_IMPL(lVar1,*(undefined4 *)(puVar2 + 1));
        }
        *(undefined1 *)(lVar3 + 0x6d) = 1;
        iVar5 = 0;
      }
      else {
        nvDbg_Printf("src/kernel/compute/fm_session_api.c",0x88,"fmsessionapiConstruct_IMPL",4,
                     "NVRM: duplicate object creation\n");
        iVar5 = 99;
      }
    }
    else {
      nvDbg_Printf("src/kernel/compute/fm_session_api.c",0x81,"fmsessionapiConstruct_IMPL",4,
                   "NVRM: only supported for usermode clients\n");
      iVar5 = 0x56;
    }
  }
  return iVar5;
}


// ===== 00298930 fmsessionapiDestruct_IMPL =====

void fmsessionapiDestruct_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = g_pSys;
  _clearFmState(1);
  osRmCapRelease(*(undefined8 *)(param_1 + 0xd8));
  *(undefined1 *)(lVar1 + 0x6d) = 0;
  return;
}


// ===== 00298970 fmsessionapiCtrlCmdSetFmState_IMPL =====

undefined8 fmsessionapiCtrlCmdSetFmState_IMPL(void)

{
  if (*(char *)(g_pSys + 0x6c) == '\0') {
    *(undefined1 *)(g_pSys + 0x6c) = 1;
    nvDbg_Printf("src/kernel/compute/fm_session_api.c",0xcf,"fmsessionapiCtrlCmdSetFmState_IMPL",1,
                 "NVRM: Fabric manager state is set.\n");
    return 0;
  }
  nvDbg_Printf("src/kernel/compute/fm_session_api.c",200,"fmsessionapiCtrlCmdSetFmState_IMPL",1,
               "NVRM: Fabric manager state is already set.\n");
  return 0;
}


// ===== 002989f0 fmsessionapiCtrlCmdClearFmState_IMPL =====

undefined8 fmsessionapiCtrlCmdClearFmState_IMPL(void)

{
  _clearFmState(0);
  return 0;
}


// ===== 00298a10 _setImexRecoveryAction =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _setImexRecoveryAction(void)

{
  char cVar1;
  long lVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  local_24 = 0;
  local_20 = 0;
  local_1c[0] = 0;
  gpumgrGetGpuAttachInfo(&local_24,&local_20);
  while( true ) {
    lVar2 = gpumgrGetNextGpu(local_20,local_1c);
    if (lVar2 == 0) {
      return;
    }
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 == '\0') break;
    *(undefined1 *)(lVar2 + 0x4b9) = 1;
    (**(code **)(lVar2 + 0x140))(lVar2,1);
    *(undefined1 *)(lVar2 + 0x4b9) = 0;
  }
  nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/compute/imex_session_api.c",0xf3);
  return;
}


// ===== 00298aa0 _performRcAndDisableChannels =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _performRcAndDisableChannels(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b38),0x802008,param_2,0x324);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x44,"_performRcAndDisableChannels",4,
               "NVRM: Failed to disable channels for GPU %d\n",*(undefined4 *)(param_1 + 0x7a4));
  return;
}


// ===== 00298b20 rcAndDisableOutstandingClientsWithImportedMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char rcAndDisableOutstandingClientsWithImportedMemory(long param_1,short param_2)

{
  long *plVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  char local_419;
  undefined8 local_418;
  undefined8 local_410;
  undefined8 local_408;
  undefined8 local_400;
  undefined8 local_3f8;
  undefined8 local_3f0;
  undefined8 local_3e8;
  long local_3e0;
  undefined8 local_3d8;
  int local_3bc;
  int local_3b8;
  int local_3b4;
  undefined1 local_3b0 [8];
  undefined8 local_3a8;
  undefined8 local_3a0;
  undefined8 local_398;
  undefined8 local_390;
  undefined8 local_388;
  undefined8 local_380;
  undefined8 local_378;
  long local_370;
  undefined8 local_368;
  uint local_35c;
  undefined4 auStack_358 [202];
  
  local_3bc = 0;
  local_3b8 = 0;
  local_3b4 = 0;
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/compute/imex_session_api.c",0x9f);
  }
  if (param_1 == 0) {
    gpumgrGetGpuAttachInfo(&local_3b8,&local_3bc);
    if (local_3b8 == 0) goto LAB_00298b9c;
  }
  else {
    local_3b8 = 1;
    local_3bc = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
  }
  cVar2 = rmGpuLockIsOwner();
  if ((cVar2 == '\0') && (cVar2 = rmGpuGroupLockIsOwner(0,2,&local_3bc), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmGpuLockIsOwner() || rmGpuGroupLockIsOwner(0, GPU_LOCK_GRP_MASK, &gpuMask)"
                        ,"src/kernel/compute/imex_session_api.c",0xad);
  }
LAB_00298b9c:
  local_419 = '\0';
  do {
    lVar6 = gpumgrGetNextGpu(local_3bc,&local_3b4);
    if (lVar6 == 0) {
      return local_419;
    }
    local_35c = 0;
    plVar7 = (long *)serverutilGetFirstClientUnderLock();
joined_r0x00298be3:
    if (plVar7 != (long *)0x0) {
      do {
        plVar1 = (long *)*plVar7;
        lVar9 = 0;
        if (plVar1 != (long *)0x0) {
          lVar9 = plVar1[0x20];
        }
        uVar4 = (**(code **)(*plVar1 + 0xd8))(plVar1);
        if ((uVar4 < 2) && (cVar2 = rmclientIsCapable_IMPL(plVar1,4), cVar2 == '\0')) {
          clientRefIter(&local_3a8,lVar9,0,0xf96871,0,1);
          cVar2 = '\0';
          while (cVar3 = clientRefIterNext(lVar9,&local_3a8), cVar3 != '\0') {
            lVar8 = __nvoc_dynamicCast(*(undefined8 *)(local_370 + 8),
                                       __nvoc_class_def_MemoryFabricImportV2);
            if ((lVar8 != 0) && ((param_2 == -1 || (param_2 == *(short *)(lVar8 + 0x220))))) {
              cVar2 = '\x01';
              memoryfabricimportv2RemoveFromCache_IMPL(lVar8);
            }
          }
          clientRefIter(&local_418,lVar9,0,0x130210,0,1);
          local_3a8 = local_418;
          local_3a0 = local_410;
          local_398 = local_408;
          local_390 = local_400;
          local_388 = local_3f8;
          local_380 = local_3f0;
          local_378 = local_3e8;
          local_370 = local_3e0;
          local_368 = local_3d8;
          while (cVar3 = clientRefIterNext(lVar9,&local_3a8), cVar3 != '\0') {
            lVar8 = __nvoc_dynamicCast(*(undefined8 *)(local_370 + 8),
                                       __nvoc_class_def_MemoryMulticastFabric);
            if (((lVar8 != 0) && (*(char *)(lVar8 + 0x222) != '\0')) &&
               ((param_2 == -1 || (param_2 == *(short *)(lVar8 + 0x220))))) {
              cVar2 = '\x01';
              memorymulticastfabricRemoveFromCache_IMPL(lVar8);
            }
          }
          if (cVar2 != '\0') {
            *(undefined1 *)(lVar9 + 0x50) = 0;
            iVar5 = deviceGetByGpu_IMPL(lVar9,lVar6,1,local_3b0);
            if (iVar5 == 0) {
              auStack_358[local_35c] = *(undefined4 *)(lVar9 + 0x48);
              local_35c = local_35c + 1;
              if (local_35c == 200) goto code_r0x00298e07;
            }
          }
        }
        plVar7 = (long *)serverutilGetNextClientUnderLock(plVar7);
        if (plVar7 == (long *)0x0) break;
      } while( true );
    }
    if (local_35c != 0) {
      _performRcAndDisableChannels(lVar6,&local_35c);
      local_419 = '\x01';
    }
  } while( true );
code_r0x00298e07:
  _performRcAndDisableChannels(lVar6,&local_35c);
  local_35c = 0;
  plVar7 = (long *)serverutilGetNextClientUnderLock(plVar7);
  local_419 = cVar2;
  goto joined_r0x00298be3;
}


// ===== 00298f10 imexsessionapiConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int imexsessionapiConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  undefined8 local_40 [2];
  
  lVar4 = g_pSys;
  uVar2 = *(undefined8 *)(g_pSys + 0x260);
  puVar3 = *(undefined8 **)(param_3 + 0x40);
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  plVar8 = (long *)__nvoc_dynamicCast(*(long *)(param_2 + 8),__nvoc_class_def_RmClient);
  local_40[0] = 0;
  if (plVar8 == (long *)0x0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/compute/imex_session_api.c",0x10b);
    return 0x23;
  }
  if (((*(int *)(puVar3 + 1) != 0) || (puVar3[2] == 0)) || (*(short *)(puVar3 + 3) == -1)) {
    nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x112,"imexsessionapiConstruct_IMPL",4,
                 "NVRM: Invalid input value\n");
    return 0x1f;
  }
  iVar6 = osUserHandleToKernelPtr(uVar1,puVar3[2],local_40);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x11a,"imexsessionapiConstruct_IMPL",4,
                 "NVRM: Invalid event handle: 0x%x\n",iVar6);
    return iVar6;
  }
  iVar6 = fabricSetImexEvent_IMPL(uVar2,local_40[0]);
  if (iVar6 == 0) {
    osRmCapInitDescriptor(param_1 + 0xd8);
    iVar7 = osRmCapAcquire(*(undefined8 *)(lVar4 + 0x188),4,*puVar3,param_1 + 0xd8);
    if (iVar7 == 0x56) {
      cVar5 = (**(code **)(*plVar8 + 0xe0))(plVar8,*(undefined4 *)(param_2 + 0x28));
      if (cVar5 == '\0') {
        iVar6 = 0x1b;
        nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x137,"imexsessionapiConstruct_IMPL",4,
                     "NVRM: insufficient permissions\n");
        goto LAB_00299109;
      }
    }
    else if (iVar7 != 0) {
      nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x13e,"imexsessionapiConstruct_IMPL",4,
                   "NVRM: Capability validation failed\n");
      iVar6 = iVar7;
LAB_00299109:
      iVar7 = fabricSetImexEvent_IMPL(uVar2,0);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,"fabricSetImexEvent(pFabric, NULL)","src/kernel/compute/imex_session_api.c"
                   ,0x14c);
      }
      goto LAB_00299161;
    }
    fabricSetNodeId_IMPL(uVar2,*(undefined2 *)(puVar3 + 3));
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(puVar3 + 1);
    fabricEnableMemAlloc_IMPL(uVar2);
    _setImexRecoveryAction();
  }
  else {
    nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x125,"imexsessionapiConstruct_IMPL",4,
                 "NVRM: Unable to set event: 0x%x\n",iVar6);
LAB_00299161:
    osDereferenceObjectCount(local_40[0]);
  }
  return iVar6;
}


// ===== 002991ce imexsessionapiDestruct_IMPL.cold =====

void imexsessionapiDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002991e0 imexsessionapiDestruct_IMPL =====

void imexsessionapiDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 local_70 [72];
  
  uVar1 = *(undefined8 *)(g_pSys + 0x260);
  uVar7 = fabricGetImexEvent_IMPL(uVar1);
  if (param_1 != 0) {
    uVar2 = **(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48);
    clientRefIter(local_70,uVar2,0,&DAT_00e7ac53,0,1);
    cVar4 = clientRefIterNext(uVar2,local_70);
    if (cVar4 != '\0') {
      fabricDisableMemAlloc_IMPL(uVar1);
      nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x16b,"imexsessionapiDestruct_IMPL",4,
                   "NVRM: Abrupt nvidia-imex daemon shutdown detected, disabled fabric allocations\n"
                  );
    }
    uVar5 = fabricGetNodeId_IMPL(uVar1);
    memoryexportClearCache(uVar5);
    iVar6 = fabricSetImexEvent_IMPL(uVar1,0);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,"fabricSetImexEvent(pFabric, NULL)","src/kernel/compute/imex_session_api.c",
                 0x172);
    }
    fabricSetNodeId_IMPL(uVar1,0xffff);
    osDereferenceObjectCount(uVar7);
    osRmCapRelease(*(undefined8 *)(param_1 + 0xd8));
    fabricFlushUnhandledEvents_IMPL(uVar1);
    fabricUnimportCacheIterateAll_IMPL(uVar1,fabricWakeUpThreadCallback);
    if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {
      cVar4 = rcAndDisableOutstandingClientsWithImportedMemory(0,0xffff);
      if (cVar4 != '\0') {
        nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x181,"imexsessionapiDestruct_IMPL",4,
                     "NVRM: Abrupt nvidia-imex daemon shutdown detected, robust channel recovery invoked\n"
                    );
      }
    }
    _setImexRecoveryAction();
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 00299370 imexsessionapiCtrlCmdGetFabricEvents_IMPL =====

undefined8 imexsessionapiCtrlCmdGetFabricEvents_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar1 = *(undefined8 *)(g_pSys + 0x260);
  *(undefined4 *)(param_2 + 0x2c00) = 0x80;
  uVar2 = fabricExtractEventsV2_IMPL(uVar1,param_2,param_2 + 0x2c00);
  *(undefined1 *)(param_2 + 0x2c04) = uVar2;
  return 0;
}


// ===== 002993c0 imexsessionapiCtrlCmdFinishMemUnimport_IMPL =====

undefined8 imexsessionapiCtrlCmdFinishMemUnimport_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (*(int *)(param_2 + 0x800) - 1U < 0x100) {
    lVar3 = 0;
    uVar2 = *(undefined8 *)(g_pSys + 0x260);
    do {
      lVar1 = lVar3 * 8;
      lVar3 = lVar3 + 1;
      fabricUnimportCacheInvokeCallback_IMPL
                (uVar2,*(undefined8 *)(param_2 + lVar1),fabricWakeUpThreadCallback);
    } while ((uint)lVar3 < *(uint *)(param_2 + 0x800));
    return 0;
  }
  return 0x1f;
}


// ===== 00299440 imexsessionapiCtrlCmdDisableImporters_IMPL =====

undefined4 imexsessionapiCtrlCmdDisableImporters_IMPL(long param_1,undefined2 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0x56;
  if ((*(uint *)(param_1 + 0xe0) & 1) == 0) {
    cVar1 = rcAndDisableOutstandingClientsWithImportedMemory(0,*param_2);
    if (cVar1 != '\0') {
      nvDbg_Printf("src/kernel/compute/imex_session_api.c",0x1c5,
                   "imexsessionapiCtrlCmdDisableImporters_IMPL",4,
                   "NVRM: nvidia-imex daemon has invoked robust channel recovery for remote node: %u\n"
                   ,*param_2);
      return 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002994c0 mpsApiConstruct_IMPL =====

undefined8 mpsApiConstruct_IMPL(void)

{
  return 0;
}


// ===== 002994d0 mpsApiDestruct_IMPL =====

void mpsApiDestruct_IMPL(void)

{
  return;
}


// ===== 002994e0 _bindataWriteStorageToBuffer =====

undefined8 _bindataWriteStorageToBuffer(long param_1,long param_2,int param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pBinStorage != NULL","src/kernel/core/bin_data.c",0x5e);
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pBuffer != NULL","src/kernel/core/bin_data.c",0x5f);
  }
  else {
    lVar1 = *(long *)(param_1 + 8);
    if (lVar1 != 0) {
      if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
        portMemCopy(param_2,param_3,lVar1,param_3);
      }
      else {
        iVar2 = utilGzGetData(lVar1,param_3,0,param_3);
        if (param_3 != iVar2) {
          nvDbg_Printf("src/kernel/core/bin_data.c",0x6d,"_bindataWriteStorageToBuffer",4,
                       "NVRM: failed to get inflated data, got %u bytes, expecting %u\n",iVar2,
                       param_3);
          return 0x18;
        }
      }
      return 0;
    }
    nvAssertFailedNoLog("pBinStoragePvt->pData != NULL","src/kernel/core/bin_data.c",0x61);
  }
  return 0x1f;
}


// ===== 002995e0 bindataWriteToBuffer =====

void bindataWriteToBuffer(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  osPagedSegmentAccessCheck();
  _bindataWriteStorageToBuffer(param_1,param_2,param_3);
  return;
}


// ===== 00299610 bindataGetBufferSize =====

undefined4 bindataGetBufferSize(undefined4 *param_1)

{
  osPagedSegmentAccessCheck();
  if (param_1 != (undefined4 *)0x0) {
    return *param_1;
  }
  return 0;
}


// ===== 00299640 bindataArchiveGetStorage =====

undefined8 bindataArchiveGetStorage(uint *param_1,uint param_2)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  
  osPagedSegmentAccessCheck();
  if (param_1 != (uint *)0x0) {
    puVar3 = param_1 + 2;
    uVar2 = 0;
    if (*param_1 != 0) {
      do {
        if (*puVar3 == param_2) {
          return *(undefined8 *)(param_1 + uVar2 * 4 + 4);
        }
        uVar1 = (int)uVar2 + 1;
        uVar2 = (ulong)uVar1;
        puVar3 = puVar3 + 4;
      } while (uVar1 != *param_1);
    }
  }
  return 0;
}


// ===== 002996a0 bindataInitialize =====

void bindataInitialize(void)

{
  return;
}


// ===== 002996b0 bindataDestroy =====

void bindataDestroy(void)

{
  return;
}


// ===== 002996c0 bindataStorageAcquireData =====

int bindataStorageAcquireData(undefined4 *param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  
  osPagedSegmentAccessCheck();
  if (param_1 == (undefined4 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *param_1;
  }
  lVar2 = portMemAllocNonPaged(uVar3);
  *param_2 = lVar2;
  if (lVar2 != 0) {
    osPagedSegmentAccessCheck();
    iVar1 = _bindataWriteStorageToBuffer(param_1,lVar2,uVar3);
    if (iVar1 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/core/bin_data.c",0xdb,"bindataStorageAcquireData",4,
                 "NVRM: bindataWriteToBuffer failed. Freeing alloced memory, return code %u\n",iVar1
                );
    portMemFree(*param_2);
    *param_2 = 0;
    return iVar1;
  }
  nvDbg_Printf("src/kernel/core/bin_data.c",0xd3,"bindataStorageAcquireData",4,
               "NVRM: bindata memory alloc failed\n");
  return 0x51;
}


// ===== 002997b0 bindataStorageReleaseData =====

void bindataStorageReleaseData(void)

{
  portMemFree();
  return;
}


// ===== 002997c0 objhalGetModuleDescriptor_IMPL =====

long objhalGetModuleDescriptor_IMPL(long param_1)

{
  return param_1 + 0x48;
}


// ===== 002997d0 registerHalModule =====

int registerHalModule(undefined4 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  uVar1 = *(undefined8 *)(g_pSys + 600);
  iVar2 = halmgrCreateHal_IMPL(uVar1,param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  lVar3 = halmgrGetHal_IMPL(uVar1,param_1);
  if (lVar3 == 0) {
    nvAssertFailedNoLog(&DAT_00ce1147,"src/kernel/core/hal/hal.c",0x3d);
  }
  *(undefined8 *)(lVar3 + 0x48) = param_2;
  return 0;
}


// ===== 00299870 rpc_iGrp_ipVersions_Install_v03_00 =====

void rpc_iGrp_ipVersions_Install_v03_00(void)

{
  return;
}


// ===== 00299880 rpc_iGrp_ipVersions_getInfo =====

undefined8 rpc_iGrp_ipVersions_getInfo(long param_1)

{
  *(undefined1 **)(param_1 + 0x10) = rpc_iGrp_ipVersions_table_153;
  *(undefined4 *)(param_1 + 0x18) = 0x8b;
  *(code **)(param_1 + 0x20) = rpc_iGrp_ipVersions_Wrapup;
  return 0;
}


// ===== 002998a0 rpcHalIfacesSetup_TU102 =====

void rpcHalIfacesSetup_TU102(undefined8 param_1)

{
  memcpy(param_1,rpcHalIfacesInitStruct_GA100_12,0x4a8);
  return;
}


// ===== 002998c0 rpcHalIfacesSetup_GA102 =====

void rpcHalIfacesSetup_GA102(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = memcpy(param_1,rpcHalIfacesInitStruct_GA100_12,0x4a8);
  *(code **)(lVar1 + 0x1e8) = rpcVgpuGspRingDoorbell_GA102;
  *(code **)(lVar1 + 0x210) = rpcVgpuGspWriteScratchRegister_GA102;
  return;
}


// ===== 00299900 rpcHalIfacesSetup_AD102 =====

void rpcHalIfacesSetup_AD102(undefined8 param_1)

{
  memcpy(param_1,rpcHalIfacesInitStruct_AD102_10,0x4a8);
  return;
}


// ===== 00299920 rpcHalIfacesSetup_T234D =====

void rpcHalIfacesSetup_T234D(undefined8 param_1)

{
  memcpy(param_1,rpcHalIfacesInitStruct_T234D_2,0x4a8);
  return;
}


// ===== 00299940 rpcstructurecopy_iGrp_ipVersions_getInfo =====

undefined8 rpcstructurecopy_iGrp_ipVersions_getInfo(long param_1)

{
  *(undefined1 **)(param_1 + 0x10) = rpcstructurecopy_iGrp_ipVersions_table_224;
  *(undefined4 *)(param_1 + 0x18) = 0x45;
  *(code **)(param_1 + 0x20) = rpcstructurecopy_iGrp_ipVersions_Wrapup;
  return 0;
}


// ===== 00299960 rpcstructurecopyHalIfacesSetup_TU102 =====

void rpcstructurecopyHalIfacesSetup_TU102(undefined8 param_1)

{
  memcpy(param_1,rpcstructurecopyHalIfacesInitStruct_TU102_225,0x1c0);
  return;
}


// ===== 00299980 rpcstructurecopy_iGrp_ipVersions_Wrapup =====

undefined8 rpcstructurecopy_iGrp_ipVersions_Wrapup(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  code *pcVar4;
  
  lVar2 = *(long *)(param_1 + 8);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  uVar1 = *(uint *)(lVar2 + 0x1c8);
  if (uVar1 < 0x2b060000) {
    pcVar4 = *(code **)(lVar2 + 8);
    if (uVar1 + 0xfd000000 < 0x28020000) {
      *(code **)(lVar2 + 0x10) = deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v03_00;
      if (0x2505ffff < uVar1) {
        *(code **)(lVar2 + 0x18) =
             deserialize_NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS_v25_06;
        *(code **)(lVar2 + 0x20) = deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS_v20_04;
        *(code **)(lVar2 + 0x28) = deserialize_VGPU_P2P_CAPABILITY_PARAMS_v25_03;
        *(code **)(lVar2 + 0x30) = deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01;
        goto LAB_0029a864;
      }
      if (0x2003ffff < uVar1) {
        *(code **)(lVar2 + 0x20) = deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS_v20_04;
        if (uVar1 < 0x25030000) {
          if (uVar1 < 0x22010000) {
            if (0x210bffff < uVar1) {
              *(code **)(lVar2 + 0x40) = deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C;
              *(code **)(lVar2 + 0x48) =
                   deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03;
              *(code **)(lVar2 + 0x50) =
                   deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v1F_01;
              goto LAB_00299b55;
            }
            *(code **)(lVar2 + 0x48) = deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03
            ;
            *(code **)(lVar2 + 0x50) =
                 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v1F_01;
            goto LAB_0029a782;
          }
          *(code **)(lVar2 + 0x30) = deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01;
          *(code **)(lVar2 + 0x40) = deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C;
          *(code **)(lVar2 + 0x48) = deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03;
        }
        else {
          *(code **)(lVar2 + 0x28) = deserialize_VGPU_P2P_CAPABILITY_PARAMS_v25_03;
          *(code **)(lVar2 + 0x30) = deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01;
          *(code **)(lVar2 + 0x40) = deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C;
          *(code **)(lVar2 + 0x48) = deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03;
        }
        goto LAB_00299a11;
      }
      if ((uVar1 < 0x15030000) ||
         (*(code **)(lVar2 + 0x48) = deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03,
         0xb00ffff < uVar1 + 0xe0ff0000)) goto LAB_0029a1b4;
      *(code **)(lVar2 + 0x50) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v1F_01;
LAB_0029a782:
      if (0xfeffff < uVar1 + 0xd8fb0000) goto LAB_00299b55;
      *(code **)(lVar2 + 0x58) =
           deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v27_05;
      goto LAB_0029a160;
    }
    if (0x2b01ffff < uVar1) {
      *(code **)(lVar2 + 0x10) = deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v2B_02;
      *(code **)(lVar2 + 0x18) =
           deserialize_NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS_v25_06;
      *(code **)(lVar2 + 0x20) = deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS_v20_04;
      *(code **)(lVar2 + 0x28) = deserialize_VGPU_P2P_CAPABILITY_PARAMS_v25_03;
      *(code **)(lVar2 + 0x30) = deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01;
LAB_0029a864:
      *(code **)(lVar2 + 0x40) = deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C;
      *(code **)(lVar2 + 0x48) = deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03;
      if (0xb00ffff < uVar1 + 0xe0ff0000) goto LAB_00299b4d;
LAB_00299a11:
      *(code **)(lVar2 + 0x50) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v1F_01;
      if (0x1ffffff < uVar1 + 0xdafb0000) goto LAB_0029a782;
      *(code **)(lVar2 + 0x58) =
           deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v25_05;
      if (0x250dffff < uVar1) goto LAB_0029a160;
      *(code **)(lVar2 + 0x68) = deserialize_NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_v03_00;
      *(code **)(lVar2 + 0x70) =
           deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v18_0B;
      goto LAB_00299a4f;
    }
LAB_0029a1b4:
    if (0x2ffffff < uVar1) goto LAB_00299b61;
LAB_0029a1c0:
    if (0x1f7ffff < uVar1 + 0xd4f80000) {
LAB_0029a58b:
      if (0x2cffffff < uVar1) goto LAB_0029a2cb;
      if (0x1e01ffff < uVar1) goto LAB_00299be8;
      if (0x1d03ffff < uVar1) goto LAB_00299c00;
      if (0x1c05ffff < uVar1) goto LAB_0029a302;
      if ((0x2ffffff < uVar1) &&
         (*(code **)(lVar2 + 0xe0) =
               deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS_v03_00, 0x1200ffff < uVar1)
         ) {
        *(code **)(lVar2 + 0xe8) = deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS_v12_01;
        if (uVar1 < 0x1b050000) {
          if (0x1a06ffff < uVar1) {
            *(code **)(lVar2 + 0x100) = deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07;
          }
          goto LAB_0029a5c7;
        }
        goto LAB_0029af77;
      }
LAB_0029a5c7:
      if (uVar1 < 0x16000000) {
        if (uVar1 + 0xeafe0000 < 0x160f0000) goto LAB_0029a5e1;
        goto LAB_0029a5ec;
      }
      *(code **)(lVar2 + 0x140) =
           deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00;
      if (uVar1 < 0x1a070000) {
LAB_0029a5e1:
        *(code **)(lVar2 + 0x160) = deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v15_02
        ;
        goto LAB_0029a5ec;
      }
      *(code **)(lVar2 + 0x150) = deserialize_NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS_v1A_07;
      *(code **)(lVar2 + 0x160) = deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v15_02;
      if (0xb01ffff < uVar1 + 0xe4ff0000) goto LAB_0029a5ec;
LAB_0029aa02:
      *(code **)(lVar2 + 0x170) = deserialize_VGPU_STATIC_PROPERTIES_v1B_01;
LAB_0029a3ed:
      *(code **)(lVar2 + 400) = deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18;
      *(code **)(lVar2 + 0x198) =
           deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F;
      if (uVar1 + 0xdbfa0000 < 0x1fc0000) goto LAB_0029a415;
LAB_0029a4e6:
      if (uVar1 + 0xd7ff0000 < 0x70000) {
        *(code **)(lVar2 + 0x1a0) = deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v28_01;
        *(code **)(lVar2 + 0x1a8) = deserialize_VGPU_CE_GET_CAPS_V2_v24_09;
        *(code **)(lVar2 + 0x1b0) = deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v25_00;
      }
      else if (uVar1 + 0xd7f80000 < 0x3fa0000) {
        *(code **)(lVar2 + 0x1a0) = deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v28_08;
        *(code **)(lVar2 + 0x1a8) = deserialize_VGPU_CE_GET_CAPS_V2_v24_09;
        *(code **)(lVar2 + 0x1b0) = deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v25_00;
      }
      else {
LAB_0029a5f8:
        if (uVar1 < 0x2c020000) goto LAB_0029a420;
        *(code **)(lVar2 + 0x1a0) = deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v2C_02;
        pcVar3 = deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v2C_07;
        *(code **)(lVar2 + 0x1a8) = deserialize_VGPU_CE_GET_CAPS_V2_v24_09;
        if (uVar1 + 0xdb000000 < 0x7070000) {
          pcVar3 = deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v25_00;
        }
        *(code **)(lVar2 + 0x1b0) = pcVar3;
      }
LAB_0029a519:
      *(code **)(lVar2 + 0x1b8) = deserialize_VGPU_GET_LATENCY_BUFFER_SIZE_v27_02;
      if (pcVar4 == iGrp_ipVersions_UNASSIGNED) goto LAB_0029a531;
      goto LAB_00299dc6;
    }
    *(code **)(lVar2 + 0xb0) = deserialize_VGPU_STATIC_DATA_v2B_08;
    if (0x2b0fffff < uVar1) goto LAB_0029a2d6;
    *(code **)(lVar2 + 0xc0) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS_v1E_02;
    *(code **)(lVar2 + 200) =
         deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_REQ_ATOMICS_CAPS_PARAMS_v25_0B;
    *(code **)(lVar2 + 0xd0) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS_v1D_04;
    *(code **)(lVar2 + 0xd8) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS_v1C_06;
    *(code **)(lVar2 + 0xe0) = deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS_v03_00;
    *(code **)(lVar2 + 0xe8) = deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS_v12_01;
LAB_0029a22b:
    if (uVar1 + 0xd4ff0000 < 0x2010000) {
      *(code **)(lVar2 + 0xf0) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v2B_01;
      *(code **)(lVar2 + 0xf8) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS_v1B_05;
      *(code **)(lVar2 + 0x100) = deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07;
      *(code **)(lVar2 + 0x108) = deserialize_NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS_v21_0A;
    }
    else {
      if (uVar1 < 0x2d020000) {
LAB_0029af77:
        *(code **)(lVar2 + 0xf8) =
             deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS_v1B_05;
        *(code **)(lVar2 + 0x100) = deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07;
        goto LAB_0029a565;
      }
      *(code **)(lVar2 + 0xf0) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v2D_02;
      *(code **)(lVar2 + 0xf8) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS_v1B_05;
      *(code **)(lVar2 + 0x100) = deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07;
      *(code **)(lVar2 + 0x108) = deserialize_NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS_v21_0A;
    }
LAB_00299c70:
    *(code **)(lVar2 + 0x110) = deserialize_GPU_EXEC_SYSPIPE_INFO_v26_01;
LAB_00299c7b:
    *(code **)(lVar2 + 0x118) = deserialize_VGPU_BSP_GET_CAPS_v25_00;
    *(code **)(lVar2 + 0x120) =
         deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS_v1F_08;
    if (uVar1 + 0xdbfb0000 < 0x3fd0000) goto LAB_0029a360;
    *(code **)(lVar2 + 0x128) = deserialize_GPU_PARTITION_INFO_v28_02;
    if (uVar1 < 0x2b100000) goto LAB_0029a36b;
    *(code **)(lVar2 + 0x130) = deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10;
    *(code **)(lVar2 + 0x138) = deserialize_NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_PARAMS_v1E_09;
    *(code **)(lVar2 + 0x140) =
         deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00;
    *(code **)(lVar2 + 0x148) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ROP_INFO_PARAMS_v1B_05;
    *(code **)(lVar2 + 0x150) = deserialize_NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS_v1A_07;
    *(code **)(lVar2 + 0x158) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_RECORD_SIZE_PARAMS_v1B_05;
    if (uVar1 + 0xeafe0000 < 0x160f0000) goto LAB_0029a3a2;
    *(code **)(lVar2 + 0x160) = deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v2B_11;
    *(code **)(lVar2 + 0x168) = deserialize_NV2080_CTRL_BUS_GET_INFO_V2_PARAMS_v1C_09;
    *(code **)(lVar2 + 0x170) = deserialize_VGPU_STATIC_PROPERTIES_v29_03;
    *(code **)(lVar2 + 0x178) =
         deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01;
LAB_00299d3a:
    *(code **)(lVar2 + 0x180) =
         deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06;
    *(code **)(lVar2 + 0x188) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS_v25_07;
    *(code **)(lVar2 + 400) = deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18;
    *(code **)(lVar2 + 0x198) = deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F;
LAB_00299d66:
    if (0xfcffff < uVar1 + 0xd8fc0000) goto LAB_0029a4e6;
    *(code **)(lVar2 + 0x1a0) = deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v27_04;
LAB_00299d89:
    *(code **)(lVar2 + 0x1a8) = deserialize_VGPU_CE_GET_CAPS_V2_v24_09;
    if (0x706ffff < uVar1 + 0xdb000000) goto LAB_00299da0;
    *(code **)(lVar2 + 0x1b0) = deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v25_00;
    if (0xaf8ffff < uVar1 + 0xe3f70000) goto LAB_0029a519;
LAB_00299dae:
    *(code **)(lVar2 + 0x1b8) = deserialize_VGPU_GET_LATENCY_BUFFER_SIZE_v1C_09;
  }
  else {
    *(code **)(lVar2 + 8) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06;
    *(code **)(lVar2 + 0x10) = deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v2B_02;
    *(code **)(lVar2 + 0x18) =
         deserialize_NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS_v25_06;
    *(code **)(lVar2 + 0x20) = deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS_v20_04;
    *(code **)(lVar2 + 0x28) = deserialize_VGPU_P2P_CAPABILITY_PARAMS_v25_03;
    *(code **)(lVar2 + 0x30) = deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01;
    if (uVar1 < 0x2b0a0000) {
      pcVar4 = 
      deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06;
      goto LAB_0029a864;
    }
    *(code **)(lVar2 + 0x38) =
         deserialize_NV2080_CTRL_MC_GET_INTR_CATEGORY_SUBTREE_MAP_PARAMS_v2B_0A;
    *(code **)(lVar2 + 0x40) = deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C;
    *(code **)(lVar2 + 0x48) = deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03;
    if (uVar1 + 0xd5fe0000 < 0x1090000) {
      pcVar4 = 
      deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06;
LAB_00299b4d:
      *(code **)(lVar2 + 0x50) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v2A_02;
    }
    else {
      *(code **)(lVar2 + 0x50) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v2B_0B;
      pcVar4 = 
      deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06;
    }
LAB_00299b55:
    if (uVar1 < 0x28040000) {
LAB_00299b61:
      *(code **)(lVar2 + 0x68) = deserialize_NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_v03_00;
      if ((uVar1 + 0xe7f50000 < 0xd080000) &&
         (*(code **)(lVar2 + 0x70) =
               deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v18_0B
         , 0x2404ffff < uVar1)) {
LAB_00299a4f:
        *(code **)(lVar2 + 0x80) = deserialize_NVC637_CTRL_EXEC_PARTITIONS_GET_PARAMS_v24_05;
        if (uVar1 + 0xdbf90000 < 0x4f90000) {
LAB_00299a68:
          *(code **)(lVar2 + 0x88) =
               deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v24_07;
        }
        *(code **)(lVar2 + 0x90) = deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES_v1A_07;
LAB_00299a7e:
        *(code **)(lVar2 + 0x98) =
             deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1B_05;
        if (uVar1 + 0xdbf80000 < 0x8f80000) {
LAB_00299aa0:
          *(code **)(lVar2 + 0xa0) = deserialize_VGPU_DISPLAYLESS_INFO_v24_08;
          *(code **)(lVar2 + 0xa8) = deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D;
          if (0x1f1ffff < uVar1 + 0xdaf20000) {
LAB_0029a4b9:
            if (0xffff < uVar1 + 0xd9000000) goto LAB_00299bcb;
            *(code **)(lVar2 + 0xb0) = deserialize_VGPU_STATIC_DATA_v27_00;
            *(code **)(lVar2 + 0xc0) =
                 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS_v1E_02;
            goto LAB_0029a2ec;
          }
          *(code **)(lVar2 + 0xb0) = deserialize_VGPU_STATIC_DATA_v25_0E;
        }
        else {
LAB_00299bc0:
          *(code **)(lVar2 + 0xa8) = deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D;
LAB_00299bcb:
          if (0x305ffff < uVar1 + 0xd8ff0000) goto LAB_0029b00d;
          *(code **)(lVar2 + 0xb0) = deserialize_VGPU_STATIC_DATA_v27_01;
        }
      }
      else {
        if (uVar1 < 0x1a070000) goto LAB_0029a1c0;
        *(code **)(lVar2 + 0x90) = deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES_v1A_07;
        if (0x1b04ffff < uVar1) goto LAB_00299a7e;
        if (uVar1 + 0xe5f30000 < 0x12f60000) goto LAB_00299bc0;
LAB_0029b00d:
        if (0x100ffff < uVar1 + 0xd5f90000) goto LAB_0029a1c0;
        *(code **)(lVar2 + 0xb0) = deserialize_VGPU_STATIC_DATA_v2A_07;
      }
LAB_00299be8:
      *(code **)(lVar2 + 0xc0) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS_v1E_02;
      if (0x250affff < uVar1) goto LAB_0029a2ec;
LAB_00299c00:
      *(code **)(lVar2 + 0xd0) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS_v1D_04;
      *(code **)(lVar2 + 0xd8) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS_v1C_06;
      *(code **)(lVar2 + 0xe0) = deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS_v03_00;
      *(code **)(lVar2 + 0xe8) = deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS_v12_01;
    }
    else {
      *(code **)(lVar2 + 0x58) =
           deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v28_04;
LAB_0029a160:
      *(code **)(lVar2 + 0x60) = deserialize_NV2080_CTRL_BIOS_GET_SKU_INFO_PARAMS_v25_0E;
      *(code **)(lVar2 + 0x68) = deserialize_NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_v03_00;
      if (uVar1 + 0xe7f50000 < 0xd080000) {
        *(code **)(lVar2 + 0x70) =
             deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v18_0B;
        goto LAB_00299a4f;
      }
      *(code **)(lVar2 + 0x70) =
           deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v25_13;
      if (uVar1 < 0x29050000) {
        *(code **)(lVar2 + 0x80) = deserialize_NVC637_CTRL_EXEC_PARTITIONS_GET_PARAMS_v24_05;
        if (0x4f8ffff < uVar1 + 0xdbf90000) goto LAB_0029a482;
        goto LAB_00299a68;
      }
      *(code **)(lVar2 + 0x78) = deserialize_NV2080_CTRL_INTERNAL_CCU_SAMPLE_INFO_PARAMS_v29_05;
      *(code **)(lVar2 + 0x80) = deserialize_NVC637_CTRL_EXEC_PARTITIONS_GET_PARAMS_v24_05;
      if (uVar1 + 0xd7000000 < 0x3030000) {
LAB_0029a482:
        *(code **)(lVar2 + 0x88) = deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v29_00
        ;
        *(code **)(lVar2 + 0x90) = deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES_v1A_07;
        *(code **)(lVar2 + 0x98) =
             deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1B_05;
        *(code **)(lVar2 + 0xa0) = deserialize_VGPU_DISPLAYLESS_INFO_v24_08;
        *(code **)(lVar2 + 0xa8) = deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D;
        goto LAB_0029a4b9;
      }
      *(code **)(lVar2 + 0x88) = deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v2C_03;
      *(code **)(lVar2 + 0x90) = deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES_v1A_07;
      *(code **)(lVar2 + 0x98) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1B_05;
      if (uVar1 + 0xdbf80000 < 0x8f80000) goto LAB_00299aa0;
      *(code **)(lVar2 + 0xa0) = deserialize_VGPU_DISPLAYLESS_INFO_v2D_00;
      if (uVar1 + 0xe5f30000 < 0x12f60000) {
        *(code **)(lVar2 + 0xa8) = deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D;
        goto LAB_0029a58b;
      }
      *(code **)(lVar2 + 0xa8) = deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v2D_03;
LAB_0029a2cb:
      *(code **)(lVar2 + 0xb0) = deserialize_VGPU_STATIC_DATA_v2D_00;
LAB_0029a2d6:
      *(code **)(lVar2 + 0xb8) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10;
      *(code **)(lVar2 + 0xc0) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS_v1E_02;
LAB_0029a2ec:
      *(code **)(lVar2 + 200) =
           deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_REQ_ATOMICS_CAPS_PARAMS_v25_0B;
      *(code **)(lVar2 + 0xd0) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS_v1D_04;
LAB_0029a302:
      *(code **)(lVar2 + 0xd8) =
           deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS_v1C_06;
      *(code **)(lVar2 + 0xe0) = deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS_v03_00;
      *(code **)(lVar2 + 0xe8) = deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS_v12_01;
      if (0xdfdffff < uVar1 + 0xe2fd0000) goto LAB_0029a22b;
    }
    *(code **)(lVar2 + 0xf0) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v1D_03;
    *(code **)(lVar2 + 0xf8) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS_v1B_05;
    *(code **)(lVar2 + 0x100) = deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07;
    if (uVar1 < 0x210a0000) {
      if (0x1f07ffff < uVar1) {
        *(code **)(lVar2 + 0x120) =
             deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS_v1F_08;
        goto LAB_0029a36b;
      }
LAB_0029a565:
      if (0x1e08ffff < uVar1) goto LAB_0029a36b;
    }
    else {
      *(code **)(lVar2 + 0x108) = deserialize_NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS_v21_0A;
      if (0x2600ffff < uVar1) goto LAB_00299c70;
      if (0x24ffffff < uVar1) goto LAB_00299c7b;
      *(code **)(lVar2 + 0x120) =
           deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS_v1F_08;
      if (0x3fcffff < uVar1 + 0xdbfb0000) goto LAB_0029a36b;
LAB_0029a360:
      *(code **)(lVar2 + 0x128) = deserialize_GPU_PARTITION_INFO_v24_05;
LAB_0029a36b:
      *(code **)(lVar2 + 0x138) = deserialize_NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_PARAMS_v1E_09;
    }
    *(code **)(lVar2 + 0x140) =
         deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00;
    *(code **)(lVar2 + 0x148) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ROP_INFO_PARAMS_v1B_05;
    *(code **)(lVar2 + 0x150) = deserialize_NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS_v1A_07;
    *(code **)(lVar2 + 0x158) =
         deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_RECORD_SIZE_PARAMS_v1B_05;
LAB_0029a3a2:
    *(code **)(lVar2 + 0x160) = deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v15_02;
    if (uVar1 < 0x1c090000) {
      if (uVar1 + 0xe4ff0000 < 0xb020000) goto LAB_0029aa02;
LAB_0029a5ec:
      if (uVar1 < 0x1a180000) goto LAB_0029a5f8;
      *(code **)(lVar2 + 400) = deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18;
      if (0x1a1effff < uVar1) {
        *(code **)(lVar2 + 0x198) =
             deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F;
        goto LAB_00299d66;
      }
    }
    else {
      *(code **)(lVar2 + 0x168) = deserialize_NV2080_CTRL_BUS_GET_INFO_V2_PARAMS_v1C_09;
      if (uVar1 + 0xe4ff0000 < 0xb020000) {
        *(code **)(lVar2 + 0x170) = deserialize_VGPU_STATIC_PROPERTIES_v1B_01;
        if (uVar1 < 0x25010000) goto LAB_0029a3ed;
        *(code **)(lVar2 + 0x178) =
             deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01;
        if (0x2506ffff < uVar1) {
          *(code **)(lVar2 + 0x188) =
               deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS_v25_07;
          *(code **)(lVar2 + 400) = deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18;
          *(code **)(lVar2 + 0x198) =
               deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F;
          if (0x1fbffff < uVar1 + 0xdbfa0000) goto LAB_0029af47;
          goto LAB_0029a415;
        }
      }
      else {
        if (uVar1 + 0xd9fd0000 < 0x3000000) {
          *(code **)(lVar2 + 0x170) = deserialize_VGPU_STATIC_PROPERTIES_v26_03;
          *(code **)(lVar2 + 0x178) =
               deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01;
        }
        else {
          *(code **)(lVar2 + 0x170) = deserialize_VGPU_STATIC_PROPERTIES_v29_03;
          *(code **)(lVar2 + 0x178) =
               deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01;
          if (0x2b05ffff < uVar1) goto LAB_00299d3a;
        }
        if (0x2506ffff < uVar1) {
          *(code **)(lVar2 + 0x188) =
               deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS_v25_07;
          *(code **)(lVar2 + 400) = deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18;
          *(code **)(lVar2 + 0x198) =
               deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F;
LAB_0029af47:
          if (0x101ffff < uVar1 + 0xd9fe0000) goto LAB_00299d66;
          *(code **)(lVar2 + 0x1a0) = deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v26_02;
          goto LAB_00299d89;
        }
      }
      *(code **)(lVar2 + 400) = deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18;
      *(code **)(lVar2 + 0x198) =
           deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F;
LAB_0029a415:
      *(code **)(lVar2 + 0x1a0) = deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v24_06;
LAB_0029a420:
      if (0x2408ffff < uVar1) goto LAB_00299d89;
    }
LAB_00299da0:
    if (uVar1 + 0xe3f70000 < 0xaf90000) goto LAB_00299dae;
  }
  if (pcVar4 == iGrp_ipVersions_UNASSIGNED) {
LAB_0029a531:
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x66a);
    return 0x56;
  }
LAB_00299dc6:
  if (*(code **)(lVar2 + 0x10) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x66b);
  }
  else if (*(code **)(lVar2 + 0x18) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x66c);
  }
  else if (*(code **)(lVar2 + 0x20) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x66d);
  }
  else if (*(code **)(lVar2 + 0x28) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_P2P_CAPABILITY_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x66e);
  }
  else if (*(code **)(lVar2 + 0x30) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x66f);
  }
  else if (*(code **)(lVar2 + 0x38) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_MC_GET_INTR_CATEGORY_SUBTREE_MAP_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x670);
  }
  else if (*(code **)(lVar2 + 0x40) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x671);
  }
  else if (*(code **)(lVar2 + 0x48) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x672);
  }
  else if (*(code **)(lVar2 + 0x50) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x673);
  }
  else if (*(code **)(lVar2 + 0x58) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x674);
  }
  else if (*(code **)(lVar2 + 0x60) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_BIOS_GET_SKU_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x675);
  }
  else if (*(code **)(lVar2 + 0x68) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GPU_GET_GID_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x676);
  }
  else if (*(code **)(lVar2 + 0x70) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x677);
  }
  else if (*(code **)(lVar2 + 0x78) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_CCU_SAMPLE_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x678);
  }
  else if (*(code **)(lVar2 + 0x80) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NVC637_CTRL_EXEC_PARTITIONS_GET_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x679);
  }
  else if (*(code **)(lVar2 + 0x88) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x67a);
  }
  else if (*(code **)(lVar2 + 0x90) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x67b);
  }
  else if (*(code **)(lVar2 + 0x98) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x67c);
  }
  else if (*(code **)(lVar2 + 0xa0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_DISPLAYLESS_INFO != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x67d);
  }
  else if (*(code **)(lVar2 + 0xa8) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x67e);
  }
  else if (*(code **)(lVar2 + 0xb0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_STATIC_DATA != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x67f);
  }
  else if (*(code **)(lVar2 + 0xb8) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x680);
  }
  else if (*(code **)(lVar2 + 0xc0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x681);
  }
  else if (*(code **)(lVar2 + 200) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_REQ_ATOMICS_CAPS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x682);
  }
  else if (*(code **)(lVar2 + 0xd0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x683);
  }
  else if (*(code **)(lVar2 + 0xd8) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x684);
  }
  else if (*(code **)(lVar2 + 0xe0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x685);
  }
  else if (*(code **)(lVar2 + 0xe8) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x686);
  }
  else if (*(code **)(lVar2 + 0xf0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x687);
  }
  else if (*(code **)(lVar2 + 0xf8) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x688);
  }
  else if (*(code **)(lVar2 + 0x100) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x689);
  }
  else if (*(code **)(lVar2 + 0x108) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x68a);
  }
  else if (*(code **)(lVar2 + 0x110) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_GPU_EXEC_SYSPIPE_INFO != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x68b);
  }
  else if (*(code **)(lVar2 + 0x118) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_BSP_GET_CAPS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x68c);
  }
  else if (*(code **)(lVar2 + 0x120) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x68d);
  }
  else if (*(code **)(lVar2 + 0x128) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_GPU_PARTITION_INFO != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x68e);
  }
  else if (*(code **)(lVar2 + 0x130) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x68f);
  }
  else if (*(code **)(lVar2 + 0x138) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x690);
  }
  else if (*(code **)(lVar2 + 0x140) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x691);
  }
  else if (*(code **)(lVar2 + 0x148) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ROP_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x692);
  }
  else if (*(code **)(lVar2 + 0x150) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x693);
  }
  else if (*(code **)(lVar2 + 0x158) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_RECORD_SIZE_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x694);
  }
  else if (*(code **)(lVar2 + 0x160) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x695);
  }
  else if (*(code **)(lVar2 + 0x168) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_BUS_GET_INFO_V2_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x696);
  }
  else if (*(code **)(lVar2 + 0x170) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_STATIC_PROPERTIES != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x697);
  }
  else if (*(code **)(lVar2 + 0x178) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x698);
  }
  else if (*(code **)(lVar2 + 0x180) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x699);
  }
  else if (*(code **)(lVar2 + 0x188) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x69a);
  }
  else if (*(code **)(lVar2 + 400) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x69b);
  }
  else if (*(code **)(lVar2 + 0x198) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x69c);
  }
  else if (*(code **)(lVar2 + 0x1a0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x69d);
  }
  else if (*(code **)(lVar2 + 0x1a8) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_CE_GET_CAPS_V2 != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x69e);
  }
  else if (*(code **)(lVar2 + 0x1b0) == iGrp_ipVersions_UNASSIGNED) {
    nvAssertFailed("pRpcstructurecopyHal->deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x69f);
  }
  else {
    if (*(code **)(lVar2 + 0x1b8) != iGrp_ipVersions_UNASSIGNED) {
      return 0;
    }
    nvAssertFailed("pRpcstructurecopyHal->deserialize_VGPU_GET_LATENCY_BUFFER_SIZE != (void *) iGrp_ipVersions_UNASSIGNED"
                   ,"generated/g_rpcstructurecopy_private.h",0x6a0);
  }
  return 0x56;
}


// ===== 0029b0c0 rpc_iGrp_ipVersions_Wrapup =====

undefined4 rpc_iGrp_ipVersions_Wrapup(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  code *pcVar4;
  
  lVar2 = *(long *)(param_1 + 8);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  uVar1 = *(uint *)(lVar2 + 0x4d0);
  if (uVar1 < 0x1a230000) {
    pcVar4 = *(code **)(lVar2 + 0x28);
    if (uVar1 < 0x15000000) {
      if (0x1300ffff < uVar1) goto LAB_0029ccec;
      if (0x1200ffff < uVar1) {
        *(code **)(lVar2 + 0x68) = rpcGpuExecRegOps_v12_01;
        goto LAB_0029cd08;
      }
      if (0x2ffffff < uVar1) {
        *(code **)(lVar2 + 0x80) = rpcAllocShareDevice_v03_00;
        if (0x800ffff < uVar1) goto LAB_0029e1d2;
        *(code **)(lVar2 + 0xf0) = rpcFree_v03_00;
        goto LAB_0029b2f2;
      }
    }
    else {
      *(code **)(lVar2 + 0x30) = rpcVgpuPfRegRead32_v15_00;
      if (0x1811ffff < uVar1) {
        *(code **)(lVar2 + 0x40) = rpcDumpProtobufComponent_v18_12;
        *(code **)(lVar2 + 0x50) = rpcAllocMemory_v13_01;
        goto LAB_0029cec0;
      }
LAB_0029ccec:
      *(code **)(lVar2 + 0x50) = rpcAllocMemory_v13_01;
      *(code **)(lVar2 + 0x68) = rpcGpuExecRegOps_v12_01;
LAB_0029ccfc:
      if (0x1a0fffff < uVar1) goto LAB_0029b156;
LAB_0029cd08:
      *(code **)(lVar2 + 0x80) = rpcAllocShareDevice_v03_00;
      if (0x1a09ffff < uVar1) {
        *(code **)(lVar2 + 0x88) = rpcCtrlPreempt_v1A_0A;
        if ((0x1a0dffff < uVar1) &&
           (*(code **)(lVar2 + 0x90) = rpcCtrlGpuInitializeCtx_v1A_0E, 0x1a0effff < uVar1)) {
          *(code **)(lVar2 + 0x98) = rpcCtrlReservePmAreaSmpc_v1A_0F;
        }
LAB_0029cd50:
        *(code **)(lVar2 + 200) = rpcCtrlSetZbcDepthClear_v1A_09;
        *(code **)(lVar2 + 0xd0) = rpcCtrlResetIsolatedChannel_v1A_09;
        if (uVar1 < 0x1a0e0000) goto LAB_0029e1d2;
        goto LAB_0029cd80;
      }
      if (0x1a08ffff < uVar1) goto LAB_0029cd50;
LAB_0029e1d2:
      *(code **)(lVar2 + 0xe0) = rpcAllocSubdevice_v08_01;
      *(code **)(lVar2 + 0xf0) = rpcFree_v03_00;
      if (uVar1 < 0x14000000) goto LAB_0029b2f2;
LAB_0029cdc5:
      *(code **)(lVar2 + 0x118) = rpcGetGspStaticInfo_v14_00;
      *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
      if (0x16ffffff < uVar1) {
LAB_0029cde7:
        *(code **)(lVar2 + 0x130) = rpcGspSetSystemInfo_v17_00;
        if (0x1a0bffff < uVar1) goto LAB_0029cdfe;
      }
    }
LAB_0029b2fd:
    if (uVar1 + 0xd4fb0000 < 0x70000) {
      *(code **)(lVar2 + 0x1b8) = rpcCtrlGpuGetInfoV2_v2B_05;
LAB_0029b320:
      *(code **)(lVar2 + 0x1c0) = rpcCtrlGetHsCredits_v21_08;
      *(code **)(lVar2 + 0x1c8) = rpcCtrlGrSetCtxswPreemptionMode_v1A_0E;
      *(code **)(lVar2 + 0x1d0) = rpcCtrlB0ccExecRegOps_v1A_0F;
      if (uVar1 + 0xe5e30000 < 0x10ec0000) goto LAB_0029bd3e;
      goto LAB_0029b54e;
    }
    if (uVar1 + 0xd4f40000 < 0x70000) {
LAB_0029b522:
      *(code **)(lVar2 + 0x1b8) = rpcCtrlGpuGetInfoV2_v2B_0C;
      *(code **)(lVar2 + 0x1c0) = rpcCtrlGetHsCredits_v21_08;
      *(code **)(lVar2 + 0x1c8) = rpcCtrlGrSetCtxswPreemptionMode_v1A_0E;
      *(code **)(lVar2 + 0x1d0) = rpcCtrlB0ccExecRegOps_v1A_0F;
      goto LAB_0029b54e;
    }
LAB_0029bae5:
    if (0x2b12ffff < uVar1) {
LAB_0029dc23:
      *(code **)(lVar2 + 0x1b8) = rpcCtrlGpuGetInfoV2_v2B_13;
      *(code **)(lVar2 + 0x1c0) = rpcCtrlGetHsCredits_v21_08;
      *(code **)(lVar2 + 0x1c8) = rpcCtrlGrSetCtxswPreemptionMode_v1A_0E;
      *(code **)(lVar2 + 0x1d0) = rpcCtrlB0ccExecRegOps_v1A_0F;
      goto LAB_0029b55a;
    }
    if (0x2107ffff < uVar1) goto LAB_0029b320;
    if (0x1a0dffff < uVar1) {
      *(code **)(lVar2 + 0x1c8) = rpcCtrlGrSetCtxswPreemptionMode_v1A_0E;
      if (0x1a0effff < uVar1) {
        *(code **)(lVar2 + 0x1d0) = rpcCtrlB0ccExecRegOps_v1A_0F;
        if (uVar1 + 0xe5e30000 < 0x10ec0000) {
          *(code **)(lVar2 + 0x1d8) = rpcCtrlGrmgrGetGrFsInfo_v1A_1D;
        }
        goto LAB_0029d07b;
      }
      if (0x10ebffff < uVar1 + 0xe5e30000) goto LAB_0029bb15;
      *(code **)(lVar2 + 0x1d8) = rpcCtrlGrmgrGetGrFsInfo_v1A_1D;
      *(code **)(lVar2 + 0x1e0) = rpcCtrlGetZbcClearTable_v1A_09;
      *(code **)(lVar2 + 0x1e8) = rpcCleanupSurface_v03_00;
      *(code **)(lVar2 + 0x1f0) = rpcCtrlSetTimeslice_v1A_0A;
      goto LAB_0029b586;
    }
    if (0x1a08ffff < uVar1) {
LAB_0029bb15:
      *(code **)(lVar2 + 0x1e0) = rpcCtrlGetZbcClearTable_v1A_09;
      *(code **)(lVar2 + 0x1e8) = rpcCleanupSurface_v03_00;
      if (uVar1 < 0x1a0a0000) goto LAB_0029d141;
      *(code **)(lVar2 + 0x1f0) = rpcCtrlSetTimeslice_v1A_0A;
      goto LAB_0029bb50;
    }
    if (0x2ffffff < uVar1) {
      *(code **)(lVar2 + 0x1e8) = rpcCleanupSurface_v03_00;
      goto LAB_0029d141;
    }
LAB_0029d1b0:
    if (uVar1 < 0x1c040000) {
      if (0x1a1dffff < uVar1) {
        *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
        *(code **)(lVar2 + 0x2e8) = rpcSetSurfaceProperties_v07_07;
        if (uVar1 < 0x1a1f0000) goto LAB_0029e0fd;
        *(code **)(lVar2 + 0x2f8) = rpcCtrlTimerSetGrTickFreq_v1A_1F;
LAB_0029e02a:
        *(code **)(lVar2 + 0x308) = rpcAllocEvent_v03_00;
        *(code **)(lVar2 + 0x310) = rpcCtrlGrPcSamplingMode_v1A_1F;
        *(code **)(lVar2 + 0x318) = rpcCtrlMcServiceInterrupts_v1A_0E;
        goto LAB_0029e04b;
      }
      if (0x706ffff < uVar1) {
        *(code **)(lVar2 + 0x2e8) = rpcSetSurfaceProperties_v07_07;
LAB_0029e0fd:
        *(code **)(lVar2 + 0x308) = rpcAllocEvent_v03_00;
        if (uVar1 < 0x1a0e0000) {
          if (0x1a08ffff < uVar1) {
            *(code **)(lVar2 + 0x328) = rpcCtrlSetZbcColorClear_v1A_09;
            *(code **)(lVar2 + 0x330) = rpcGetEncoderCapacity_v07_00;
            *(code **)(lVar2 + 0x340) = rpcPerfGetLevelInfo_v03_00;
            goto joined_r0x0029cfc6;
          }
        }
        else {
          *(code **)(lVar2 + 0x318) = rpcCtrlMcServiceInterrupts_v1A_0E;
          *(code **)(lVar2 + 0x328) = rpcCtrlSetZbcColorClear_v1A_09;
        }
LAB_0029e130:
        *(code **)(lVar2 + 0x330) = rpcGetEncoderCapacity_v07_00;
        goto LAB_0029e13b;
      }
      if (uVar1 < 0x3000000) goto LAB_0029d3c6;
      *(code **)(lVar2 + 0x308) = rpcAllocEvent_v03_00;
      if (0x6ffffff < uVar1) goto LAB_0029e130;
      *(code **)(lVar2 + 0x340) = rpcPerfGetLevelInfo_v03_00;
      if (uVar1 + 0xd9000000 < 0x2060000) goto LAB_0029cfd0;
LAB_0029d21a:
      if (0x2c00ffff < uVar1) {
        *(code **)(lVar2 + 0x348) = rpcAllocObject_v2C_01;
        *(code **)(lVar2 + 0x350) = rpcCtrlGpuHandleVfPriFault_v1A_09;
        goto LAB_0029d23c;
      }
LAB_0029cfed:
      if (0x1a08ffff < uVar1) goto LAB_0029b7f0;
LAB_0029b818:
      if (uVar1 + 0xdae90000 < 0x10000) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_17;
        goto LAB_0029b835;
      }
      if (0xffff < uVar1 + 0xdae80000) goto LAB_0029bd5b;
      *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_18;
LAB_0029e4e6:
      if (0x1ffff < uVar1 + 0xd3fc0000) goto LAB_0029bd78;
      *(code **)(lVar2 + 0x358) = rpcRmApiControl_v2C_04;
      *(code **)(lVar2 + 0x360) = rpcCtrlFabricMemStats_v1E_0C;
      *(code **)(lVar2 + 0x368) = rpcCtrlCmdNvlinkInbandSendData_v26_05;
      *(code **)(lVar2 + 0x370) = rpcCtrlGrCtxswZcullBind_v1A_0E;
    }
    else {
LAB_0029e091:
      *(code **)(lVar2 + 0x2d0) = rpcCtrlGrGetTpcPartitionMode_v1C_04;
      *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
LAB_0029bc99:
      *(code **)(lVar2 + 0x2e8) = rpcSetSurfaceProperties_v07_07;
      *(code **)(lVar2 + 0x2f8) = rpcCtrlTimerSetGrTickFreq_v1A_1F;
      if (uVar1 < 0x1f0a0000) goto LAB_0029e02a;
LAB_0029bcbb:
      *(code **)(lVar2 + 0x300) = rpcCtrlGpfifoSetWorkSubmitTokenNotifIndex_v1F_0A;
      *(code **)(lVar2 + 0x308) = rpcAllocEvent_v03_00;
      *(code **)(lVar2 + 0x310) = rpcCtrlGrPcSamplingMode_v1A_1F;
      *(code **)(lVar2 + 0x318) = rpcCtrlMcServiceInterrupts_v1A_0E;
      if (0x2105ffff < uVar1) goto LAB_0029b774;
LAB_0029e04b:
      *(code **)(lVar2 + 0x328) = rpcCtrlSetZbcColorClear_v1A_09;
      *(code **)(lVar2 + 0x330) = rpcGetEncoderCapacity_v07_00;
      if (0x1f0cffff < uVar1) {
        *(code **)(lVar2 + 0x338) = rpcCtrlGetP2pCaps_v1F_0D;
        goto LAB_0029b7b2;
      }
LAB_0029e13b:
      *(code **)(lVar2 + 0x340) = rpcPerfGetLevelInfo_v03_00;
LAB_0029d3c6:
      if (uVar1 + 0xd9000000 < 0x2060000) {
        *(code **)(lVar2 + 0x348) = rpcAllocObject_v27_00;
        if (0x1fdffff < uVar1 + 0xd6fa0000) goto LAB_0029cfdb;
      }
      else if (0x1fdffff < uVar1 + 0xd6fa0000) goto LAB_0029b98f;
      *(code **)(lVar2 + 0x348) = rpcAllocObject_v29_06;
LAB_0029d3eb:
      *(code **)(lVar2 + 0x350) = rpcCtrlGpuHandleVfPriFault_v1A_09;
LAB_0029d250:
      if (uVar1 + 0xdaf00000 < 0x40000) {
LAB_0029b9db:
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_10;
        goto LAB_0029b9e6;
      }
      if (uVar1 + 0xdaec0000 < 0x10000) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_14;
        goto LAB_0029d27f;
      }
LAB_0029be15:
      if (uVar1 + 0xdaeb0000 < 0x10000) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_15;
        goto LAB_0029be32;
      }
      if (0xffff < uVar1 + 0xdaea0000) goto LAB_0029b818;
      *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_16;
LAB_0029e199:
      if (uVar1 + 0xd6f70000 < 0xff0000) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v29_09;
        *(code **)(lVar2 + 0x360) = rpcCtrlFabricMemStats_v1E_0C;
        goto LAB_0029be5a;
      }
LAB_0029b835:
      if (0x1fbffff < uVar1 + 0xd5f80000) goto LAB_0029e4e6;
      *(code **)(lVar2 + 0x358) = rpcRmApiControl_v2A_08;
      *(code **)(lVar2 + 0x360) = rpcCtrlFabricMemStats_v1E_0C;
      *(code **)(lVar2 + 0x368) = rpcCtrlCmdNvlinkInbandSendData_v26_05;
      *(code **)(lVar2 + 0x370) = rpcCtrlGrCtxswZcullBind_v1A_0E;
    }
LAB_0029bdb0:
    if (0x10dffff < uVar1 + 0xd6000000) {
      *(code **)(lVar2 + 0x378) = rpcCtrlInternalMemsysSetZbcReferenced_v2B_0E;
LAB_0029cbb4:
      *(code **)(lVar2 + 0x380) = rpcSetupHibernationBuffer_v2A_06;
      *(code **)(lVar2 + 0x388) = rpcCtrlPerfRatedTdpSetControl_v1A_1F;
      *(code **)(lVar2 + 0x390) = rpcCtrlExecPartitionsCreate_v24_05;
      *(code **)(lVar2 + 0x398) = rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A;
      *(code **)(lVar2 + 0x3a0) = rpcIdleChannels_v03_00;
      if (0x2508ffff < uVar1) goto LAB_0029be05;
LAB_0029e472:
      *(code **)(lVar2 + 0x3b8) = rpcRestoreHibernationData_v1E_0E;
      if (0x2104ffff < uVar1) goto LAB_0029befa;
LAB_0029df13:
      *(code **)(lVar2 + 0x3c8) = rpcCtrlInternalSriovPromotePmaStream_v1C_0C;
LAB_0029df1e:
      *(code **)(lVar2 + 0x3d8) = rpcInitGspTraceCrashBuffer_v03_00;
      if (0x1a09ffff < uVar1) goto LAB_0029bf38;
      if (0x6ffffff < uVar1) {
        *(code **)(lVar2 + 0x3f0) = rpcAllocRoot_v07_00;
        if (0x1a08ffff < uVar1) {
          *(code **)(lVar2 + 0x418) = rpcCtrlNvencSwSessionUpdateInfo_v1A_09;
        }
        *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
        if (uVar1 < 0x1a090000) goto LAB_0029df54;
        *(code **)(lVar2 + 0x470) = rpcCtrlPerfBoost_v1A_09;
        goto LAB_0029e288;
      }
      if (uVar1 < 0x3000000) goto LAB_0029cb1c;
      *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
LAB_0029df54:
      if (uVar1 < 0x15000000) goto LAB_0029cb1c;
      *(code **)(lVar2 + 0x490) = rpcUpdateBarPde_v15_00;
      if (0x2904ffff < uVar1 + 0xfd000000) {
        if (uVar1 + 0xd8ff0000 < 0x4060000) goto LAB_0029cb30;
        if (uVar1 < 0x1a080000) goto joined_r0x0029d02f;
        goto LAB_0029e360;
      }
      *(code **)(lVar2 + 0x4a0) = rpcMapMemoryDma_v03_00;
      if (uVar1 + 0xd8ff0000 < 0x4060000) goto LAB_0029cf17;
      if (uVar1 < 0x1a080000) goto LAB_0029d018;
      *(code **)(lVar2 + 0x4b0) = rpcCtrlSetVgpuFbUsage_v1A_08;
      *(code **)(lVar2 + 0x4b8) = rpcUnmapMemoryDma_v03_00;
      goto LAB_0029cb65;
    }
    *(code **)(lVar2 + 0x378) = rpcCtrlInternalMemsysSetZbcReferenced_v2A_00;
    if (0x2a05ffff < uVar1) goto LAB_0029cbb4;
    *(code **)(lVar2 + 0x388) = rpcCtrlPerfRatedTdpSetControl_v1A_1F;
    *(code **)(lVar2 + 0x390) = rpcCtrlExecPartitionsCreate_v24_05;
    *(code **)(lVar2 + 0x398) = rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A;
    *(code **)(lVar2 + 0x3a0) = rpcIdleChannels_v03_00;
LAB_0029be05:
    *(code **)(lVar2 + 0x3a8) = rpcCtrlCmdInternalGpuStartFabricProbe_v25_09;
LAB_0029bee4:
    *(code **)(lVar2 + 0x3b0) = rpcGetBrandCaps_v25_12;
LAB_0029beef:
    *(code **)(lVar2 + 0x3b8) = rpcRestoreHibernationData_v1E_0E;
LAB_0029befa:
    *(code **)(lVar2 + 0x3c0) = rpcCtrlFlaSetupInstanceMemBlock_v21_05;
    *(code **)(lVar2 + 0x3c8) = rpcCtrlInternalSriovPromotePmaStream_v1C_0C;
    if (uVar1 + 0xdc000000 < 0x2040000) {
LAB_0029bf22:
      *(code **)(lVar2 + 0x3d0) = rpcCtrlFbGetFsInfo_v24_00;
      *(code **)(lVar2 + 0x3d8) = rpcInitGspTraceCrashBuffer_v03_00;
      goto LAB_0029bf38;
    }
    if (0x502ffff < uVar1 + 0xd9fc0000) goto LAB_0029ba54;
    pcVar3 = rpcCtrlFbGetFsInfo_v26_04;
LAB_0029ba67:
    *(code **)(lVar2 + 0x3d0) = pcVar3;
    *(code **)(lVar2 + 0x3d8) = rpcInitGspTraceCrashBuffer_v03_00;
    *(code **)(lVar2 + 0x3e0) = rpcCtrlSetChannelInterleaveLevel_v1A_0A;
    *(code **)(lVar2 + 1000) = rpcCtrlDbgResumeContext_v1A_10;
    *(code **)(lVar2 + 0x3f0) = rpcAllocRoot_v07_00;
    *(code **)(lVar2 + 0x3f8) = rpcCtrlFifoDisableChannels_v1A_0A;
LAB_0029bf7c:
    *(code **)(lVar2 + 0x400) = rpcCtrlSetHsCredits_v21_08;
LAB_0029bf87:
    *(code **)(lVar2 + 0x408) = rpcGetEngineUtilization_v1F_0E;
    *(code **)(lVar2 + 0x410) = rpcCtrlGetZbcClearTableEntry_v1A_0E;
    *(code **)(lVar2 + 0x418) = rpcCtrlNvencSwSessionUpdateInfo_v1A_09;
    *(code **)(lVar2 + 0x420) = rpcCtrlDbgSuspendContext_v1A_10;
    *(code **)(lVar2 + 0x428) = rpcCtrlGetP2pCapsMatrix_v1A_0E;
    *(code **)(lVar2 + 0x430) = rpcCtrlDbgExecRegOps_v1A_10;
    if (uVar1 < 0x1a1f0000) {
LAB_0029e23d:
      *(code **)(lVar2 + 0x440) = rpcCtrlSetTsgInterleaveLevel_v1A_0A;
      *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
LAB_0029e253:
      *(code **)(lVar2 + 0x470) = rpcCtrlPerfBoost_v1A_09;
      if (0x1a0fffff < uVar1) {
        *(code **)(lVar2 + 0x478) = rpcCtrlDbgSetModeMmuDebug_v1A_10;
        if (uVar1 < 0x1a160000) goto LAB_0029ca85;
        *(code **)(lVar2 + 0x480) = rpcCtrlFifoSetChannelProperties_v1A_16;
      }
LAB_0029e288:
      *(code **)(lVar2 + 0x490) = rpcUpdateBarPde_v15_00;
      if (uVar1 < 0x1a0f0000) goto LAB_0029e29f;
LAB_0029ca90:
      *(code **)(lVar2 + 0x498) = rpcCtrlBindPmResources_v1A_0F;
      if (uVar1 + 0xfd000000 < 0x29050000) goto LAB_0029cab0;
LAB_0029cc70:
      if (uVar1 + 0xd8ff0000 < 0x4060000) {
        *(code **)(lVar2 + 0x4a8) = rpcUpdateGpmGuestBufferInfo_v27_01;
        if (uVar1 < 0x2b070000) goto LAB_0029cc93;
      }
      else if (uVar1 < 0x2b070000) goto joined_r0x0029d02f;
LAB_0029c0a7:
      *(code **)(lVar2 + 0x4a8) = rpcUpdateGpmGuestBufferInfo_v2B_07;
      *(code **)(lVar2 + 0x4b0) = rpcCtrlSetVgpuFbUsage_v1A_08;
      if (uVar1 + 0xfd000000 < 0x29050000) {
        *(code **)(lVar2 + 0x4b8) = rpcUnmapMemoryDma_v03_00;
        goto LAB_0029cc0b;
      }
      if (uVar1 < 0x2c050000) goto LAB_0029c0e7;
      *(code **)(lVar2 + 0x4b8) = rpcUnmapMemoryDma_v2C_05;
    }
    else {
      *(code **)(lVar2 + 0x438) = rpcCtrlFreePmaStream_v1A_1F;
      *(code **)(lVar2 + 0x440) = rpcCtrlSetTsgInterleaveLevel_v1A_0A;
LAB_0029bfeb:
      *(code **)(lVar2 + 0x448) = rpcCtrlMasterGetVirtualFunctionErrorContIntrMask_v1F_0D;
      if (uVar1 < 0x29070000) {
        *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
      }
      else {
        *(code **)(lVar2 + 0x450) = rpcCtrlReserveHes_v29_07;
        *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
        if (0x2a04ffff < uVar1) {
          *(code **)(lVar2 + 0x460) = rpcCtrlDbgGetModeMmuGccDebug_v2A_05;
        }
      }
LAB_0029c02b:
      *(code **)(lVar2 + 0x468) = rpcCtrlExecPartitionsDelete_v1F_0A;
      *(code **)(lVar2 + 0x470) = rpcCtrlPerfBoost_v1A_09;
      *(code **)(lVar2 + 0x478) = rpcCtrlDbgSetModeMmuDebug_v1A_10;
      *(code **)(lVar2 + 0x480) = rpcCtrlFifoSetChannelProperties_v1A_16;
      if (uVar1 < 0x21020000) {
LAB_0029ca85:
        *(code **)(lVar2 + 0x490) = rpcUpdateBarPde_v15_00;
        goto LAB_0029ca90;
      }
      *(code **)(lVar2 + 0x488) = rpcCtrlSubdeviceGetP2pCaps_v21_02;
      *(code **)(lVar2 + 0x490) = rpcUpdateBarPde_v15_00;
      *(code **)(lVar2 + 0x498) = rpcCtrlBindPmResources_v1A_0F;
      if (0x2904ffff < uVar1 + 0xfd000000) {
        if (0x2c04ffff < uVar1) {
          *(code **)(lVar2 + 0x4a0) = rpcMapMemoryDma_v2C_05;
          goto LAB_0029c0a7;
        }
        goto LAB_0029cc70;
      }
LAB_0029cab0:
      *(code **)(lVar2 + 0x4a0) = rpcMapMemoryDma_v03_00;
      if (0x405ffff < uVar1 + 0xd8ff0000) {
        if (uVar1 < 0x2b070000) {
          if (0x1a07ffff < uVar1) goto LAB_0029cae0;
          goto LAB_0029caeb;
        }
        goto LAB_0029c0a7;
      }
      *(code **)(lVar2 + 0x4a8) = rpcUpdateGpmGuestBufferInfo_v27_01;
      if (0x2b06ffff < uVar1) goto LAB_0029c0a7;
LAB_0029cae0:
      *(code **)(lVar2 + 0x4b0) = rpcCtrlSetVgpuFbUsage_v1A_08;
LAB_0029caeb:
      *(code **)(lVar2 + 0x4b8) = rpcUnmapMemoryDma_v03_00;
      if (uVar1 + 0xeafe0000 < 0x10190000) goto LAB_0029cb65;
LAB_0029cc0b:
      if (uVar1 < 0x251b0000) goto LAB_0029c0e7;
    }
    *(code **)(lVar2 + 0x4c0) = rpcSetGuestSystemInfoExt_v25_1B;
  }
  else {
    *(code **)(lVar2 + 0x28) = rpcCtrlFifoSetupVfZombieSubctxPdb_v1A_23;
    *(code **)(lVar2 + 0x30) = rpcVgpuPfRegRead32_v15_00;
    if (uVar1 < 0x21030000) {
      *(code **)(lVar2 + 0x40) = rpcDumpProtobufComponent_v18_12;
      pcVar4 = rpcCtrlFifoSetupVfZombieSubctxPdb_v1A_23;
      *(code **)(lVar2 + 0x50) = rpcAllocMemory_v13_01;
      if (0x1e0affff < uVar1) goto LAB_0029b137;
LAB_0029cec0:
      *(code **)(lVar2 + 0x68) = rpcGpuExecRegOps_v12_01;
      if (uVar1 < 0x1a200000) goto LAB_0029ccfc;
    }
    else {
      *(code **)(lVar2 + 0x38) = rpcCtrlBusUnsetP2pMapping_v21_03;
      *(code **)(lVar2 + 0x40) = rpcDumpProtobufComponent_v18_12;
      if (uVar1 < 0x23050000) {
        *(code **)(lVar2 + 0x50) = rpcAllocMemory_v13_01;
        if (uVar1 < 0x21060000) goto LAB_0029b137;
      }
      else {
        *(code **)(lVar2 + 0x48) = rpcEccNotifierWriteAck_v23_05;
        *(code **)(lVar2 + 0x50) = rpcAllocMemory_v13_01;
      }
      *(code **)(lVar2 + 0x58) = rpcCtrlDbgReadSingleSmErrorState_v21_06;
LAB_0029b137:
      *(code **)(lVar2 + 0x60) = rpcDisableChannels_v1E_0B;
      pcVar4 = rpcCtrlFifoSetupVfZombieSubctxPdb_v1A_23;
      *(code **)(lVar2 + 0x68) = rpcGpuExecRegOps_v12_01;
    }
    *(code **)(lVar2 + 0x70) = rpcCtrlGpuPromoteCtx_v1A_20;
LAB_0029b156:
    *(code **)(lVar2 + 0x78) = rpcCtrlDbgSetNextStopTriggerType_v1A_10;
    *(code **)(lVar2 + 0x80) = rpcAllocShareDevice_v03_00;
    *(code **)(lVar2 + 0x88) = rpcCtrlPreempt_v1A_0A;
    *(code **)(lVar2 + 0x90) = rpcCtrlGpuInitializeCtx_v1A_0E;
    *(code **)(lVar2 + 0x98) = rpcCtrlReservePmAreaSmpc_v1A_0F;
    if (uVar1 < 0x21070000) {
      *(code **)(lVar2 + 0xa8) = rpcCtrlDbgSetModeErrbarDebug_v1A_10;
      if (((uVar1 + 0xe5ec0000 < 0xef70000) &&
          (*(code **)(lVar2 + 0xb0) = rpcCtrlPmaStreamUpdateGetPut_v1A_14, 0x1e0bffff < uVar1)) &&
         (*(code **)(lVar2 + 0xb8) = rpcCtrlFabricMemoryDescribe_v1E_0C, 0x1f03ffff < uVar1))
      goto LAB_0029b1d4;
      *(code **)(lVar2 + 200) = rpcCtrlSetZbcDepthClear_v1A_09;
      *(code **)(lVar2 + 0xd0) = rpcCtrlResetIsolatedChannel_v1A_09;
LAB_0029cd80:
      *(code **)(lVar2 + 0xd8) = rpcCtrlDmaSetDefaultVaspace_v1A_0E;
      *(code **)(lVar2 + 0xe0) = rpcAllocSubdevice_v08_01;
      if (0x290bffff < uVar1) goto LAB_0029b3b1;
      *(code **)(lVar2 + 0xf0) = rpcFree_v03_00;
LAB_0029cdad:
      if (0x1a0fffff < uVar1) {
        *(code **)(lVar2 + 0x100) = rpcCtrlDbgClearSingleSmErrorState_v1A_10;
        if (uVar1 < 0x1e050000) {
          *(code **)(lVar2 + 0x118) = rpcGetGspStaticInfo_v14_00;
          *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
        }
        else {
          *(code **)(lVar2 + 0x108) = rpcUnsetPageDirectory_v1E_05;
          *(code **)(lVar2 + 0x118) = rpcGetGspStaticInfo_v14_00;
          if (0x1e0dffff < uVar1) {
            *(code **)(lVar2 + 0x120) = rpcSaveHibernationData_v1E_0E;
            *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
            *(code **)(lVar2 + 0x130) = rpcGspSetSystemInfo_v17_00;
            if (0x210affff < uVar1) {
              *(code **)(lVar2 + 0x138) = rpcCtrlPmAreaPcSampler_v21_0B;
              goto LAB_0029d349;
            }
            *(code **)(lVar2 + 0x148) = rpcCtrlDbgSetExceptionMask_v1A_0C;
            goto LAB_0029ce15;
          }
          *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
        }
        goto LAB_0029cde7;
      }
      if (0x13ffffff < uVar1) goto LAB_0029cdc5;
      if (0x2ffffff < uVar1) {
LAB_0029b2f2:
        *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
      }
      goto LAB_0029b2fd;
    }
    *(code **)(lVar2 + 0xa0) = rpcCtrlGpuMigratableOps_v21_07;
    *(code **)(lVar2 + 0xa8) = rpcCtrlDbgSetModeErrbarDebug_v1A_10;
    if (uVar1 + 0xe5ec0000 < 0xef70000) {
      *(code **)(lVar2 + 0xb0) = rpcCtrlPmaStreamUpdateGetPut_v1A_14;
      *(code **)(lVar2 + 0xb8) = rpcCtrlFabricMemoryDescribe_v1E_0C;
LAB_0029b1d4:
      *(code **)(lVar2 + 0xc0) = rpcAllocChannelDma_v1F_04;
      *(code **)(lVar2 + 200) = rpcCtrlSetZbcDepthClear_v1A_09;
      *(code **)(lVar2 + 0xd0) = rpcCtrlResetIsolatedChannel_v1A_09;
      *(code **)(lVar2 + 0xd8) = rpcCtrlDmaSetDefaultVaspace_v1A_0E;
      *(code **)(lVar2 + 0xe0) = rpcAllocSubdevice_v08_01;
LAB_0029b20b:
      *(code **)(lVar2 + 0xf0) = rpcFree_v03_00;
      if (uVar1 < 0x24050000) goto LAB_0029cdad;
      *(code **)(lVar2 + 0xf8) = rpcDmaControl_v24_05;
      *(code **)(lVar2 + 0x100) = rpcCtrlDbgClearSingleSmErrorState_v1A_10;
      *(code **)(lVar2 + 0x108) = rpcUnsetPageDirectory_v1E_05;
      if (0x2906ffff < uVar1) goto LAB_0029b3e8;
      *(code **)(lVar2 + 0x118) = rpcGetGspStaticInfo_v14_00;
      *(code **)(lVar2 + 0x120) = rpcSaveHibernationData_v1E_0E;
      *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
      *(code **)(lVar2 + 0x130) = rpcGspSetSystemInfo_v17_00;
      *(code **)(lVar2 + 0x138) = rpcCtrlPmAreaPcSampler_v21_0B;
      if (0x2901ffff < uVar1) goto LAB_0029b436;
LAB_0029d349:
      *(code **)(lVar2 + 0x148) = rpcCtrlDbgSetExceptionMask_v1A_0C;
      if (uVar1 < 0x27060000) {
LAB_0029ce15:
        *(code **)(lVar2 + 0x158) = rpcCtrlVaspaceCopyServerReservedPdes_v1E_04;
        *(code **)(lVar2 + 0x168) = rpcCtrlGrCtxswPreemptionBind_v1A_0E;
        *(code **)(lVar2 + 0x170) = rpcCtrlAllocPmaStream_v1A_14;
        goto joined_r0x0029ce3c;
      }
      *(code **)(lVar2 + 0x150) = rpcCtrlSetZbcStencilClear_v27_06;
      *(code **)(lVar2 + 0x158) = rpcCtrlVaspaceCopyServerReservedPdes_v1E_04;
      if (0xdf8ffff < uVar1 + 0xe5f20000) goto LAB_0029e564;
      *(code **)(lVar2 + 0x168) = rpcCtrlGrCtxswPreemptionBind_v1A_0E;
LAB_0029d393:
      *(code **)(lVar2 + 0x170) = rpcCtrlAllocPmaStream_v1A_14;
      *(code **)(lVar2 + 400) = rpcCtrlReserveHwpmLegacy_v1A_0F;
      if (uVar1 < 0x1a1f0000) goto LAB_0029b2fd;
LAB_0029ce60:
      *(code **)(lVar2 + 0x198) = rpcCtrlPerfRatedTdpGetStatus_v1A_1F;
      if (uVar1 < 0x1c080000) goto LAB_0029b2fd;
      *(code **)(lVar2 + 0x1a0) = rpcCtrlInternalQuiescePmaChannel_v1C_08;
      if (uVar1 + 0xd7fd0000 < 0x30000) {
        *(code **)(lVar2 + 0x1a8) = rpcCtrlSubdeviceGetVgpuHeapStats_v28_03;
        *(code **)(lVar2 + 0x1b0) = rpcCtrlBusSetP2pMapping_v21_03;
        goto LAB_0029b505;
      }
      if (0x2805ffff < uVar1) goto LAB_0029b4e3;
      if (uVar1 + 0xdefd0000 < 0x8050000) {
        *(code **)(lVar2 + 0x1b0) = rpcCtrlBusSetP2pMapping_v21_03;
      }
      if (uVar1 + 0xdaef0000 < 0x4f30000) goto LAB_0029b505;
      goto LAB_0029bae5;
    }
    *(code **)(lVar2 + 0xb0) = rpcCtrlPmaStreamUpdateGetPut_v29_0B;
    *(code **)(lVar2 + 0xb8) = rpcCtrlFabricMemoryDescribe_v1E_0C;
    *(code **)(lVar2 + 0xc0) = rpcAllocChannelDma_v1F_04;
    *(code **)(lVar2 + 200) = rpcCtrlSetZbcDepthClear_v1A_09;
    *(code **)(lVar2 + 0xd0) = rpcCtrlResetIsolatedChannel_v1A_09;
    *(code **)(lVar2 + 0xd8) = rpcCtrlDmaSetDefaultVaspace_v1A_0E;
    *(code **)(lVar2 + 0xe0) = rpcAllocSubdevice_v08_01;
    if (uVar1 < 0x290c0000) goto LAB_0029b20b;
LAB_0029b3b1:
    *(code **)(lVar2 + 0xe8) = rpcCtrlExecPartitionsExport_v29_0C;
    *(code **)(lVar2 + 0xf0) = rpcFree_v03_00;
    *(code **)(lVar2 + 0xf8) = rpcDmaControl_v24_05;
    *(code **)(lVar2 + 0x100) = rpcCtrlDbgClearSingleSmErrorState_v1A_10;
    *(code **)(lVar2 + 0x108) = rpcUnsetPageDirectory_v1E_05;
LAB_0029b3e8:
    *(code **)(lVar2 + 0x110) = rpcCtrlReserveCcuProf_v29_07;
    *(code **)(lVar2 + 0x118) = rpcGetGspStaticInfo_v14_00;
    *(code **)(lVar2 + 0x120) = rpcSaveHibernationData_v1E_0E;
    *(code **)(lVar2 + 0x128) = rpcDupObject_v03_00;
    *(code **)(lVar2 + 0x130) = rpcGspSetSystemInfo_v17_00;
    if (uVar1 < 0x210b0000) {
LAB_0029cdfe:
      *(code **)(lVar2 + 0x148) = rpcCtrlDbgSetExceptionMask_v1A_0C;
      if (0x1e03ffff < uVar1) goto LAB_0029ce15;
      if (uVar1 + 0xe5f20000 < 0xdf90000) {
        *(code **)(lVar2 + 0x168) = rpcCtrlGrCtxswPreemptionBind_v1A_0E;
        if (0x1a13ffff < uVar1) goto LAB_0029d393;
        if (0x1a0effff < uVar1) {
          *(code **)(lVar2 + 400) = rpcCtrlReserveHwpmLegacy_v1A_0F;
        }
      }
      goto LAB_0029b2fd;
    }
    *(code **)(lVar2 + 0x138) = rpcCtrlPmAreaPcSampler_v21_0B;
LAB_0029b436:
    *(code **)(lVar2 + 0x140) = rpcCtrlSubdeviceGetLibosHeapStats_v29_02;
    *(code **)(lVar2 + 0x148) = rpcCtrlDbgSetExceptionMask_v1A_0C;
    *(code **)(lVar2 + 0x150) = rpcCtrlSetZbcStencilClear_v27_06;
    *(code **)(lVar2 + 0x158) = rpcCtrlVaspaceCopyServerReservedPdes_v1E_04;
    if (uVar1 < 0x290a0000) {
LAB_0029e564:
      *(code **)(lVar2 + 0x168) = rpcCtrlGrCtxswPreemptionBind_v28_07;
      *(code **)(lVar2 + 0x170) = rpcCtrlAllocPmaStream_v1A_14;
joined_r0x0029ce3c:
      if (0x2909ffff < uVar1) goto LAB_0029b4a6;
      if (uVar1 < 0x29070000) {
        *(code **)(lVar2 + 400) = rpcCtrlReserveHwpmLegacy_v1A_0F;
        goto LAB_0029ce60;
      }
      *(code **)(lVar2 + 0x188) = rpcCtrlReleaseHes_v29_07;
    }
    else {
      *(code **)(lVar2 + 0x160) = rpcCtrlCmdGetChipletHsCreditPool_v29_0A;
      *(code **)(lVar2 + 0x168) = rpcCtrlGrCtxswPreemptionBind_v28_07;
      *(code **)(lVar2 + 0x170) = rpcCtrlAllocPmaStream_v1A_14;
      if (uVar1 < 0x2b120000) goto joined_r0x0029ce3c;
      *(code **)(lVar2 + 0x178) = rpcCtrlCmdInternalGpuCheckCtsIdValid_v2B_12;
LAB_0029b4a6:
      *(code **)(lVar2 + 0x180) = rpcCtrlCmdGetHsCreditsMapping_v29_0A;
      *(code **)(lVar2 + 0x188) = rpcCtrlReleaseHes_v29_07;
    }
    *(code **)(lVar2 + 400) = rpcCtrlReserveHwpmLegacy_v1A_0F;
    *(code **)(lVar2 + 0x198) = rpcCtrlPerfRatedTdpGetStatus_v1A_1F;
    *(code **)(lVar2 + 0x1a0) = rpcCtrlInternalQuiescePmaChannel_v1C_08;
LAB_0029b4e3:
    *(code **)(lVar2 + 0x1a8) = rpcCtrlSubdeviceGetVgpuHeapStats_v28_06;
    if (uVar1 + 0xdefd0000 < 0x8050000) {
      *(code **)(lVar2 + 0x1b0) = rpcCtrlBusSetP2pMapping_v21_03;
LAB_0029b505:
      *(code **)(lVar2 + 0x1b8) = rpcCtrlGpuGetInfoV2_v25_11;
      if (uVar1 + 0xd4f40000 < 0x70000) goto LAB_0029b522;
      if (uVar1 < 0x2b130000) goto LAB_0029b320;
      goto LAB_0029dc23;
    }
    *(code **)(lVar2 + 0x1b0) = rpcCtrlBusSetP2pMapping_v29_08;
    if (uVar1 + 0xdaef0000 < 0x4f30000) goto LAB_0029b505;
    if (uVar1 + 0xd5fc0000 < 0xff0000) {
      *(code **)(lVar2 + 0x1b8) = rpcCtrlGpuGetInfoV2_v2A_04;
      goto LAB_0029b320;
    }
    if (0x1ffff < uVar1 + 0xd4fd0000) goto LAB_0029b2fd;
    *(code **)(lVar2 + 0x1b8) = rpcCtrlGpuGetInfoV2_v2B_03;
    *(code **)(lVar2 + 0x1c0) = rpcCtrlGetHsCredits_v21_08;
    *(code **)(lVar2 + 0x1c8) = rpcCtrlGrSetCtxswPreemptionMode_v1A_0E;
    *(code **)(lVar2 + 0x1d0) = rpcCtrlB0ccExecRegOps_v1A_0F;
LAB_0029bd3e:
    *(code **)(lVar2 + 0x1d8) = rpcCtrlGrmgrGetGrFsInfo_v1A_1D;
LAB_0029b54e:
    if (uVar1 < 0x2b090000) {
LAB_0029d07b:
      *(code **)(lVar2 + 0x1e0) = rpcCtrlGetZbcClearTable_v1A_09;
      *(code **)(lVar2 + 0x1e8) = rpcCleanupSurface_v03_00;
      if (0x1a09ffff < uVar1) {
        *(code **)(lVar2 + 0x1f0) = rpcCtrlSetTimeslice_v1A_0A;
        if (0x1fbffff < uVar1 + 0xdbfa0000) goto LAB_0029b586;
        *(code **)(lVar2 + 0x1f8) = rpcCtrlGpuQueryEccStatus_v24_06;
        if (0x2503ffff < uVar1) {
          *(code **)(lVar2 + 0x200) = rpcCtrlDbgGetModeMmuDebug_v25_04;
          *(code **)(lVar2 + 0x208) = rpcCtrlDbgClearAllSmErrorStates_v1A_0C;
          *(code **)(lVar2 + 0x218) = rpcCtrlGrSetTpcPartitionMode_v1C_04;
          *(code **)(lVar2 + 0x220) = rpcCtrlGetTotalHsCredits_v21_08;
          *(code **)(lVar2 + 0x228) = rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07;
          goto LAB_0029b5e6;
        }
LAB_0029bb5c:
        *(code **)(lVar2 + 0x208) = rpcCtrlDbgClearAllSmErrorStates_v1A_0C;
        if (0x1c03ffff < uVar1) {
          *(code **)(lVar2 + 0x218) = rpcCtrlGrSetTpcPartitionMode_v1C_04;
          if (0x2107ffff < uVar1) {
            *(code **)(lVar2 + 0x220) = rpcCtrlGetTotalHsCredits_v21_08;
            *(code **)(lVar2 + 0x228) = rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07;
            goto LAB_0029bba6;
          }
          if (0x1e06ffff < uVar1) {
            *(code **)(lVar2 + 0x228) = rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07;
            *(code **)(lVar2 + 0x240) = rpcSetPageDirectory_v1E_05;
            if (uVar1 < 0x1f0d0000) goto LAB_0029e701;
            *(code **)(lVar2 + 0x248) = rpcCtrlGetP2pCapsV2_v1F_0D;
            goto LAB_0029bbc8;
          }
          if (uVar1 < 0x1e050000) goto LAB_0029d141;
          *(code **)(lVar2 + 0x240) = rpcSetPageDirectory_v1E_05;
LAB_0029e701:
          *(code **)(lVar2 + 600) = rpcCtrlGetCePceMask_v1A_0E;
          *(code **)(lVar2 + 0x260) = rpcCtrlGpuEvictCtx_v1A_1C;
          if (0x1e05ffff < uVar1) {
            *(code **)(lVar2 + 0x268) = rpcCtrlGetMmuDebugMode_v1E_06;
            goto LAB_0029bbf5;
          }
          goto LAB_0029e1f9;
        }
        if ((0x1a0dffff < uVar1) &&
           (*(code **)(lVar2 + 600) = rpcCtrlGetCePceMask_v1A_0E, 0x1a1bffff < uVar1))
        goto LAB_0029b629;
LAB_0029e20d:
        *(code **)(lVar2 + 0x298) = rpcSwitchToVga_v03_00;
LAB_0029d16c:
        *(code **)(lVar2 + 0x2a0) = rpcCtrlResetChannel_v1A_09;
        if (uVar1 < 0x1a0a0000) {
          *(code **)(lVar2 + 0x2b0) = rpcSetRegistry_v17_00;
          goto LAB_0029d1b0;
        }
        *(code **)(lVar2 + 0x2a8) = rpcCtrlGpfifoSchedule_v1A_0A;
        goto LAB_0029d18e;
      }
LAB_0029d141:
      if (uVar1 < 0x1a0e0000) {
        if (0x2ffffff < uVar1) goto LAB_0029d155;
        goto LAB_0029d1b0;
      }
      *(code **)(lVar2 + 600) = rpcCtrlGetCePceMask_v1A_0E;
LAB_0029b629:
      *(code **)(lVar2 + 0x260) = rpcCtrlGpuEvictCtx_v1A_1C;
      if (0x1e05ffff < uVar1) {
        *(code **)(lVar2 + 0x268) = rpcCtrlGetMmuDebugMode_v1E_06;
LAB_0029b64b:
        *(code **)(lVar2 + 0x270) = rpcInvalidateTlb_v23_03;
        *(code **)(lVar2 + 0x278) = rpcCtrlDbgSetSingleSmSingleStep_v1C_02;
LAB_0029b661:
        *(code **)(lVar2 + 0x280) = rpcUnloadingGuestDriver_v1F_07;
        *(code **)(lVar2 + 0x290) = rpcGetConsolidatedGrStaticInfo_v1B_04;
        *(code **)(lVar2 + 0x298) = rpcSwitchToVga_v03_00;
        *(code **)(lVar2 + 0x2a0) = rpcCtrlResetChannel_v1A_09;
        *(code **)(lVar2 + 0x2a8) = rpcCtrlGpfifoSchedule_v1A_0A;
        *(code **)(lVar2 + 0x2b0) = rpcSetRegistry_v17_00;
        if (uVar1 < 0x2a050000) goto LAB_0029bc43;
        *(code **)(lVar2 + 0x2b8) = rpcCtrlDbgSetModeMmuGccDebug_v2A_05;
        if (uVar1 + 0xd7f70000 < 0x3080000) goto LAB_0029b8c8;
        if (0x1efffff < uVar1 + 0xd4ef0000) {
          *(code **)(lVar2 + 0x2c0) = rpcCtrlGetNvlinkStatus_v2D_01;
LAB_0029b940:
          *(code **)(lVar2 + 0x2c8) = rpcGetStaticData_v2D_00;
          *(code **)(lVar2 + 0x2d0) = rpcCtrlGrGetTpcPartitionMode_v1C_04;
          *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
          goto LAB_0029b8fa;
        }
        *(code **)(lVar2 + 0x2c0) = rpcCtrlGetNvlinkStatus_v2B_11;
        if (0x5feffff < uVar1 + 0xd8ff0000) goto LAB_0029b940;
        *(code **)(lVar2 + 0x2c8) = rpcGetStaticData_v27_01;
        *(code **)(lVar2 + 0x2d0) = rpcCtrlGrGetTpcPartitionMode_v1C_04;
        *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
        *(code **)(lVar2 + 0x2e0) = rpcCtrlCmdInternalControlGspTrace_v28_00;
        *(code **)(lVar2 + 0x2e8) = rpcSetSurfaceProperties_v07_07;
        goto LAB_0029b732;
      }
LAB_0029e1f9:
      if (uVar1 < 0x1c020000) {
        if (uVar1 < 0x1b040000) goto LAB_0029e20d;
      }
      else {
        *(code **)(lVar2 + 0x278) = rpcCtrlDbgSetSingleSmSingleStep_v1C_02;
      }
LAB_0029bc0c:
      *(code **)(lVar2 + 0x290) = rpcGetConsolidatedGrStaticInfo_v1B_04;
      *(code **)(lVar2 + 0x298) = rpcSwitchToVga_v03_00;
      *(code **)(lVar2 + 0x2a0) = rpcCtrlResetChannel_v1A_09;
      *(code **)(lVar2 + 0x2a8) = rpcCtrlGpfifoSchedule_v1A_0A;
      *(code **)(lVar2 + 0x2b0) = rpcSetRegistry_v17_00;
LAB_0029bc43:
      if (0x504ffff < uVar1 + 0xdcfc0000) goto LAB_0029d199;
      *(code **)(lVar2 + 0x2c0) = rpcCtrlGetNvlinkStatus_v23_04;
      if (0x1f2ffff < uVar1 + 0xdaf20000) {
        if (uVar1 + 0xd8ff0000 < 0x5ff0000) {
          *(code **)(lVar2 + 0x2c8) = rpcGetStaticData_v27_01;
          *(code **)(lVar2 + 0x2d0) = rpcCtrlGrGetTpcPartitionMode_v1C_04;
          *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
          if (0x27ffffff < uVar1) goto LAB_0029b8fa;
          goto LAB_0029bc99;
        }
        goto LAB_0029e091;
      }
      *(code **)(lVar2 + 0x2c8) = rpcGetStaticData_v25_0E;
      *(code **)(lVar2 + 0x2d0) = rpcCtrlGrGetTpcPartitionMode_v1C_04;
      *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
      goto LAB_0029bc99;
    }
LAB_0029b55a:
    *(code **)(lVar2 + 0x1d8) = rpcCtrlGrmgrGetGrFsInfo_v2B_09;
    *(code **)(lVar2 + 0x1e0) = rpcCtrlGetZbcClearTable_v1A_09;
    *(code **)(lVar2 + 0x1e8) = rpcCleanupSurface_v03_00;
    *(code **)(lVar2 + 0x1f0) = rpcCtrlSetTimeslice_v1A_0A;
LAB_0029b586:
    if (0x2601ffff < uVar1) {
      *(code **)(lVar2 + 0x1f8) = rpcCtrlGpuQueryEccStatus_v26_02;
      *(code **)(lVar2 + 0x200) = rpcCtrlDbgGetModeMmuDebug_v25_04;
      *(code **)(lVar2 + 0x208) = rpcCtrlDbgClearAllSmErrorStates_v1A_0C;
      *(code **)(lVar2 + 0x218) = rpcCtrlGrSetTpcPartitionMode_v1C_04;
      *(code **)(lVar2 + 0x220) = rpcCtrlGetTotalHsCredits_v21_08;
      *(code **)(lVar2 + 0x228) = rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07;
      if (0x3ffffff < uVar1 + 0xd9000000) {
LAB_0029b5e6:
        if (uVar1 < 0x2b000000) goto LAB_0029bba6;
        *(code **)(lVar2 + 0x230) = rpcCtrlFbGetInfoV2_v2B_00;
        *(code **)(lVar2 + 0x240) = rpcSetPageDirectory_v1E_05;
        *(code **)(lVar2 + 0x248) = rpcCtrlGetP2pCapsV2_v1F_0D;
LAB_0029b613:
        *(code **)(lVar2 + 0x250) = rpcCtrlNvlinkGetInbandReceivedData_v25_0C;
        *(code **)(lVar2 + 600) = rpcCtrlGetCePceMask_v1A_0E;
        goto LAB_0029b629;
      }
      *(code **)(lVar2 + 0x230) = rpcCtrlFbGetInfoV2_v27_00;
LAB_0029bba6:
      *(code **)(lVar2 + 0x240) = rpcSetPageDirectory_v1E_05;
      *(code **)(lVar2 + 0x248) = rpcCtrlGetP2pCapsV2_v1F_0D;
      if (0x250bffff < uVar1) goto LAB_0029b613;
LAB_0029bbc8:
      *(code **)(lVar2 + 600) = rpcCtrlGetCePceMask_v1A_0E;
      *(code **)(lVar2 + 0x260) = rpcCtrlGpuEvictCtx_v1A_1C;
      *(code **)(lVar2 + 0x268) = rpcCtrlGetMmuDebugMode_v1E_06;
      if (0x2302ffff < uVar1) goto LAB_0029b64b;
LAB_0029bbf5:
      *(code **)(lVar2 + 0x278) = rpcCtrlDbgSetSingleSmSingleStep_v1C_02;
      if (0x1f06ffff < uVar1) goto LAB_0029b661;
      goto LAB_0029bc0c;
    }
LAB_0029bb50:
    if (0x1a0bffff < uVar1) goto LAB_0029bb5c;
LAB_0029d155:
    *(code **)(lVar2 + 0x298) = rpcSwitchToVga_v03_00;
    if (0x1a08ffff < uVar1) goto LAB_0029d16c;
    if (uVar1 < 0x17000000) goto LAB_0029d1b0;
LAB_0029d18e:
    *(code **)(lVar2 + 0x2b0) = rpcSetRegistry_v17_00;
LAB_0029d199:
    if (0x307ffff < uVar1 + 0xd7f70000) goto LAB_0029d1b0;
LAB_0029b8c8:
    *(code **)(lVar2 + 0x2c0) = rpcCtrlGetNvlinkStatus_v28_09;
    *(code **)(lVar2 + 0x2c8) = rpcGetStaticData_v27_01;
    *(code **)(lVar2 + 0x2d0) = rpcCtrlGrGetTpcPartitionMode_v1C_04;
    *(code **)(lVar2 + 0x2d8) = rpcCtrlStopChannel_v1A_1E;
LAB_0029b8fa:
    *(code **)(lVar2 + 0x2e0) = rpcCtrlCmdInternalControlGspTrace_v28_00;
    *(code **)(lVar2 + 0x2e8) = rpcSetSurfaceProperties_v07_07;
    if (uVar1 < 0x29070000) {
      *(code **)(lVar2 + 0x2f8) = rpcCtrlTimerSetGrTickFreq_v1A_1F;
      goto LAB_0029bcbb;
    }
LAB_0029b732:
    *(code **)(lVar2 + 0x2f0) = rpcCtrlReleaseCcuProf_v29_07;
    *(code **)(lVar2 + 0x2f8) = rpcCtrlTimerSetGrTickFreq_v1A_1F;
    *(code **)(lVar2 + 0x300) = rpcCtrlGpfifoSetWorkSubmitTokenNotifIndex_v1F_0A;
    *(code **)(lVar2 + 0x308) = rpcAllocEvent_v03_00;
    *(code **)(lVar2 + 0x310) = rpcCtrlGrPcSamplingMode_v1A_1F;
    *(code **)(lVar2 + 0x318) = rpcCtrlMcServiceInterrupts_v1A_0E;
LAB_0029b774:
    *(code **)(lVar2 + 800) = rpcCtrlDbgReadAllSmErrorStates_v21_06;
    *(code **)(lVar2 + 0x328) = rpcCtrlSetZbcColorClear_v1A_09;
    *(code **)(lVar2 + 0x330) = rpcGetEncoderCapacity_v07_00;
    *(code **)(lVar2 + 0x338) = rpcCtrlGetP2pCaps_v1F_0D;
    if (uVar1 + 0xfd000000 < 0x280d0000) {
LAB_0029b7b2:
      *(code **)(lVar2 + 0x340) = rpcPerfGetLevelInfo_v03_00;
      if (uVar1 + 0xdaf80000 < 0xf80000) {
        pcVar3 = rpcAllocObject_v27_00;
        if (0x205ffff < uVar1 + 0xd9000000) {
          pcVar3 = rpcAllocObject_v25_08;
        }
        *(code **)(lVar2 + 0x348) = pcVar3;
      }
      else {
        if (0xffffff < uVar1 + 0xda000000) goto LAB_0029d3c6;
        *(code **)(lVar2 + 0x348) = rpcAllocObject_v26_00;
        if (0x205ffff < uVar1 + 0xd9000000) goto LAB_0029d3eb;
        *(code **)(lVar2 + 0x348) = rpcAllocObject_v27_00;
      }
LAB_0029b7f0:
      *(code **)(lVar2 + 0x350) = rpcCtrlGpuHandleVfPriFault_v1A_09;
      if (uVar1 + 0xdaf30000 < 0x20000) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_0D;
        goto LAB_0029b818;
      }
LAB_0029d23c:
      if (0xffff < uVar1 + 0xdaf10000) goto LAB_0029d250;
    }
    else {
      *(code **)(lVar2 + 0x340) = rpcPerfGetLevelInfo_v2B_0D;
joined_r0x0029cfc6:
      if (uVar1 + 0xd9000000 < 0x2060000) {
LAB_0029cfd0:
        *(code **)(lVar2 + 0x348) = rpcAllocObject_v27_00;
LAB_0029cfdb:
        if (0xfcffff < uVar1 + 0xd4fc0000) goto LAB_0029cfed;
      }
      else {
LAB_0029b98f:
        if (0xfcffff < uVar1 + 0xd4fc0000) goto LAB_0029d21a;
      }
      *(code **)(lVar2 + 0x348) = rpcAllocObject_v2B_04;
      *(code **)(lVar2 + 0x350) = rpcCtrlGpuHandleVfPriFault_v1A_09;
      if (0xffff < uVar1 + 0xdaf10000) {
        if (0x3ffff < uVar1 + 0xdaf00000) goto LAB_0029be15;
        goto LAB_0029b9db;
      }
    }
    *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_0F;
LAB_0029bd5b:
    if (uVar1 + 0xdae70000 < 0x10000) {
      *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_19;
LAB_0029bd78:
      if (0x2c05ffff < uVar1) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v2C_06;
        *(code **)(lVar2 + 0x360) = rpcCtrlFabricMemStats_v1E_0C;
        *(code **)(lVar2 + 0x368) = rpcCtrlCmdNvlinkInbandSendData_v26_05;
        *(code **)(lVar2 + 0x370) = rpcCtrlGrCtxswZcullBind_v1A_0E;
        goto LAB_0029bdb0;
      }
LAB_0029ba03:
      if (0x1e0bffff < uVar1) goto LAB_0029d29c;
      if (0x1a0dffff < uVar1) {
        *(code **)(lVar2 + 0x370) = rpcCtrlGrCtxswZcullBind_v1A_0E;
        if (uVar1 < 0x1a1f0000) goto LAB_0029ba32;
        *(code **)(lVar2 + 0x388) = rpcCtrlPerfRatedTdpSetControl_v1A_1F;
        goto LAB_0029def1;
      }
      if (0x2ffffff < uVar1) {
LAB_0029ba32:
        *(code **)(lVar2 + 0x3a0) = rpcIdleChannels_v03_00;
        goto LAB_0029ba3d;
      }
LAB_0029cb1c:
      if (0x2904ffff < uVar1 + 0xfd000000) {
        if (0x405ffff < uVar1 + 0xd8ff0000) goto joined_r0x0029d02f;
        goto LAB_0029cb30;
      }
      *(code **)(lVar2 + 0x4a0) = rpcMapMemoryDma_v03_00;
      if (uVar1 + 0xd8ff0000 < 0x4060000) goto LAB_0029cf17;
LAB_0029d018:
      *(code **)(lVar2 + 0x4b8) = rpcUnmapMemoryDma_v03_00;
    }
    else {
LAB_0029b9e6:
      if (uVar1 + 0xdae60000 < 0x1e90000) {
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v25_1A;
        goto LAB_0029ba03;
      }
LAB_0029d27f:
      if (0x200ffff < uVar1 + 0xd8fd0000) {
LAB_0029be32:
        if (0x4ffff < uVar1 + 0xd6fc0000) goto LAB_0029e199;
        *(code **)(lVar2 + 0x358) = rpcRmApiControl_v29_04;
        *(code **)(lVar2 + 0x360) = rpcCtrlFabricMemStats_v1E_0C;
        goto LAB_0029be5a;
      }
      *(code **)(lVar2 + 0x358) = rpcRmApiControl_v27_03;
LAB_0029d29c:
      *(code **)(lVar2 + 0x360) = rpcCtrlFabricMemStats_v1E_0C;
      if (uVar1 < 0x26050000) {
        *(code **)(lVar2 + 0x370) = rpcCtrlGrCtxswZcullBind_v1A_0E;
        if (uVar1 + 0xe0fb0000 < 0xafb0000) goto LAB_0029be82;
      }
      else {
LAB_0029be5a:
        *(code **)(lVar2 + 0x368) = rpcCtrlCmdNvlinkInbandSendData_v26_05;
        *(code **)(lVar2 + 0x370) = rpcCtrlGrCtxswZcullBind_v1A_0E;
        if (0xafaffff < uVar1 + 0xe0fb0000) goto LAB_0029bdb0;
LAB_0029be82:
        *(code **)(lVar2 + 0x378) = rpcCtrlInternalMemsysSetZbcReferenced_v1F_05;
      }
      *(code **)(lVar2 + 0x388) = rpcCtrlPerfRatedTdpSetControl_v1A_1F;
      if (0x2404ffff < uVar1) {
        *(code **)(lVar2 + 0x390) = rpcCtrlExecPartitionsCreate_v24_05;
        *(code **)(lVar2 + 0x398) = rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A;
        *(code **)(lVar2 + 0x3a0) = rpcIdleChannels_v03_00;
        if (uVar1 < 0x25090000) goto LAB_0029beef;
        *(code **)(lVar2 + 0x3a8) = rpcCtrlCmdInternalGpuStartFabricProbe_v25_09;
        if (0x2511ffff < uVar1) goto LAB_0029bee4;
        *(code **)(lVar2 + 0x3b8) = rpcRestoreHibernationData_v1E_0E;
        *(code **)(lVar2 + 0x3c0) = rpcCtrlFlaSetupInstanceMemBlock_v21_05;
        *(code **)(lVar2 + 0x3c8) = rpcCtrlInternalSriovPromotePmaStream_v1C_0C;
        goto LAB_0029bf22;
      }
      if (0x1f09ffff < uVar1) {
        *(code **)(lVar2 + 0x398) = rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A;
        *(code **)(lVar2 + 0x3a0) = rpcIdleChannels_v03_00;
        goto LAB_0029e472;
      }
LAB_0029def1:
      *(code **)(lVar2 + 0x3a0) = rpcIdleChannels_v03_00;
      if (0x1e0dffff < uVar1) {
        *(code **)(lVar2 + 0x3b8) = rpcRestoreHibernationData_v1E_0E;
        goto LAB_0029df13;
      }
LAB_0029ba3d:
      if (uVar1 < 0x1c0c0000) goto LAB_0029df1e;
      *(code **)(lVar2 + 0x3c8) = rpcCtrlInternalSriovPromotePmaStream_v1C_0C;
LAB_0029ba54:
      if (0x2b06ffff < uVar1) {
        pcVar3 = rpcCtrlFbGetFsInfo_v2B_07;
        goto LAB_0029ba67;
      }
      *(code **)(lVar2 + 0x3d8) = rpcInitGspTraceCrashBuffer_v03_00;
LAB_0029bf38:
      *(code **)(lVar2 + 0x3e0) = rpcCtrlSetChannelInterleaveLevel_v1A_0A;
      if (0x1a0fffff < uVar1) {
        *(code **)(lVar2 + 1000) = rpcCtrlDbgResumeContext_v1A_10;
        *(code **)(lVar2 + 0x3f0) = rpcAllocRoot_v07_00;
        *(code **)(lVar2 + 0x3f8) = rpcCtrlFifoDisableChannels_v1A_0A;
        if (0x2107ffff < uVar1) goto LAB_0029bf7c;
        if (0x1f0dffff < uVar1) goto LAB_0029bf87;
        *(code **)(lVar2 + 0x410) = rpcCtrlGetZbcClearTableEntry_v1A_0E;
        *(code **)(lVar2 + 0x418) = rpcCtrlNvencSwSessionUpdateInfo_v1A_09;
        *(code **)(lVar2 + 0x420) = rpcCtrlDbgSuspendContext_v1A_10;
        *(code **)(lVar2 + 0x428) = rpcCtrlGetP2pCapsMatrix_v1A_0E;
        *(code **)(lVar2 + 0x430) = rpcCtrlDbgExecRegOps_v1A_10;
        if (uVar1 < 0x1a1f0000) goto LAB_0029e23d;
        *(code **)(lVar2 + 0x438) = rpcCtrlFreePmaStream_v1A_1F;
        *(code **)(lVar2 + 0x440) = rpcCtrlSetTsgInterleaveLevel_v1A_0A;
        if (0x1f0cffff < uVar1) goto LAB_0029bfeb;
        *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
        if (uVar1 < 0x1f0a0000) goto LAB_0029e253;
        goto LAB_0029c02b;
      }
      *(code **)(lVar2 + 0x3f0) = rpcAllocRoot_v07_00;
      *(code **)(lVar2 + 0x3f8) = rpcCtrlFifoDisableChannels_v1A_0A;
      if (0x1a0dffff < uVar1) {
        *(code **)(lVar2 + 0x410) = rpcCtrlGetZbcClearTableEntry_v1A_0E;
        *(code **)(lVar2 + 0x418) = rpcCtrlNvencSwSessionUpdateInfo_v1A_09;
        *(code **)(lVar2 + 0x428) = rpcCtrlGetP2pCapsMatrix_v1A_0E;
        *(code **)(lVar2 + 0x440) = rpcCtrlSetTsgInterleaveLevel_v1A_0A;
        *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
        goto LAB_0029e253;
      }
      *(code **)(lVar2 + 0x418) = rpcCtrlNvencSwSessionUpdateInfo_v1A_09;
      *(code **)(lVar2 + 0x440) = rpcCtrlSetTsgInterleaveLevel_v1A_0A;
      *(code **)(lVar2 + 0x458) = rpcLog_v03_00;
      *(code **)(lVar2 + 0x470) = rpcCtrlPerfBoost_v1A_09;
      *(code **)(lVar2 + 0x490) = rpcUpdateBarPde_v15_00;
LAB_0029e29f:
      if (uVar1 + 0xfd000000 < 0x29050000) {
        *(code **)(lVar2 + 0x4a0) = rpcMapMemoryDma_v03_00;
        if (uVar1 + 0xd8ff0000 < 0x4060000) {
LAB_0029cf17:
          *(code **)(lVar2 + 0x4a8) = rpcUpdateGpmGuestBufferInfo_v27_01;
        }
        goto LAB_0029cae0;
      }
      if (0x405ffff < uVar1 + 0xd8ff0000) {
LAB_0029e360:
        *(code **)(lVar2 + 0x4b0) = rpcCtrlSetVgpuFbUsage_v1A_08;
        goto LAB_0029cb65;
      }
LAB_0029cb30:
      *(code **)(lVar2 + 0x4a8) = rpcUpdateGpmGuestBufferInfo_v27_01;
      if (0x2b06ffff < uVar1) goto LAB_0029c0a7;
      if (uVar1 < 0x1a080000) goto joined_r0x0029d02f;
LAB_0029cc93:
      *(code **)(lVar2 + 0x4b0) = rpcCtrlSetVgpuFbUsage_v1A_08;
    }
joined_r0x0029d02f:
    if (uVar1 + 0xeafe0000 < 0x10190000) {
LAB_0029cb65:
      *(code **)(lVar2 + 0x4c0) = rpcSetGuestSystemInfoExt_v15_02;
      if (pcVar4 != iGrp_ipVersions_UNASSIGNED) goto LAB_0029c0f4;
      goto LAB_0029cb7d;
    }
  }
LAB_0029c0e7:
  if (pcVar4 != iGrp_ipVersions_UNASSIGNED) {
LAB_0029c0f4:
    if (*(code **)(lVar2 + 0x30) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcVgpuPfRegRead32 != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd73);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x38) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlBusUnsetP2pMapping != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd74);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x40) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcDumpProtobufComponent != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd75);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x48) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcEccNotifierWriteAck != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd76);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x50) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocMemory != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd77);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x58) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgReadSingleSmErrorState != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd78);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x60) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcDisableChannels != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd79);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x68) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGpuExecRegOps != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd7a);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x70) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuPromoteCtx != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd7b);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x78) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgSetNextStopTriggerType != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd7c);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x80) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocShareDevice != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd7d);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x88) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlPreempt != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd7e);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x90) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuInitializeCtx != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd7f);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x98) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlReservePmAreaSmpc != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd80);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xa0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuMigratableOps != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd81);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xa8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgSetModeErrbarDebug != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd82);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xb0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlPmaStreamUpdateGetPut != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd83);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xb8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFabricMemoryDescribe != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd84);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xc0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocChannelDma != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd85);
      return 0x56;
    }
    if (*(code **)(lVar2 + 200) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSetZbcDepthClear != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd86);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xd0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlResetIsolatedChannel != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd87);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xd8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDmaSetDefaultVaspace != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd88);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xe0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocSubdevice != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd89);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xe8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlExecPartitionsExport != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd8a);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xf0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcFree != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd8b);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0xf8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcDmaControl != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd8c);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x100) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgClearSingleSmErrorState != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd8d);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x108) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcUnsetPageDirectory != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd8e);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x110) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlReserveCcuProf != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd8f);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x118) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGetGspStaticInfo != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd90);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x120) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcSaveHibernationData != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd91);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x128) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcDupObject != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd92);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x130) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGspSetSystemInfo != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd93);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x138) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlPmAreaPcSampler != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd94);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x140) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSubdeviceGetLibosHeapStats != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd95);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x148) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgSetExceptionMask != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd96);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x150) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSetZbcStencilClear != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd97);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x158) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlVaspaceCopyServerReservedPdes != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd98);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x160) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlCmdGetChipletHsCreditPool != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd99);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x168) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrCtxswPreemptionBind != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd9a);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x170) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlAllocPmaStream != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd9b);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x178) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlCmdInternalGpuCheckCtsIdValid != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd9c);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x180) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlCmdGetHsCreditsMapping != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xd9d);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x188) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlReleaseHes != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd9e);
      return 0x56;
    }
    if (*(code **)(lVar2 + 400) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlReserveHwpmLegacy != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xd9f);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x198) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlPerfRatedTdpGetStatus != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda0);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1a0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlInternalQuiescePmaChannel != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xda1);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1a8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSubdeviceGetVgpuHeapStats != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xda2);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1b0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlBusSetP2pMapping != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda3);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1b8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuGetInfoV2 != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda4);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1c0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetHsCredits != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda5);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1c8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrSetCtxswPreemptionMode != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xda6);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1d0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlB0ccExecRegOps != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda7);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1d8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrmgrGetGrFsInfo != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda8);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1e0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetZbcClearTable != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xda9);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1e8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCleanupSurface != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdaa);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1f0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSetTimeslice != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdab);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x1f8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuQueryEccStatus != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdac);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x200) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgGetModeMmuDebug != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdad);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x208) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgClearAllSmErrorStates != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdae);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x218) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrSetTpcPartitionMode != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdaf);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x220) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetTotalHsCredits != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb0);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x228) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlInternalPromoteFaultMethodBuffers != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdb1);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x230) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFbGetInfoV2 != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb2);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x240) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcSetPageDirectory != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb3);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x248) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetP2pCapsV2 != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb4);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x250) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlNvlinkGetInbandReceivedData != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdb5);
      return 0x56;
    }
    if (*(code **)(lVar2 + 600) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetCePceMask != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb6);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x260) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuEvictCtx != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb7);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x268) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetMmuDebugMode != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb8);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x270) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcInvalidateTlb != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdb9);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x278) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgSetSingleSmSingleStep != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdba);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x280) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcUnloadingGuestDriver != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdbb);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x290) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGetConsolidatedGrStaticInfo != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdbc);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x298) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcSwitchToVga != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdbd);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2a0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlResetChannel != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdbe);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2a8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpfifoSchedule != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdbf);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2b0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcSetRegistry != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc0);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2b8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgSetModeMmuGccDebug != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc1);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2c0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetNvlinkStatus != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc2);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2c8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGetStaticData != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc3);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2d0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrGetTpcPartitionMode != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc4);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2d8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlStopChannel != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc5);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2e0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlCmdInternalControlGspTrace != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdc6);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2e8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcSetSurfaceProperties != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc7);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2f0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlReleaseCcuProf != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc8);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x2f8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlTimerSetGrTickFreq != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdc9);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x300) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpfifoSetWorkSubmitTokenNotifIndex != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdca);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x308) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocEvent != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdcb);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x310) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrPcSamplingMode != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdcc);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x318) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlMcServiceInterrupts != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdcd);
      return 0x56;
    }
    if (*(code **)(lVar2 + 800) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgReadAllSmErrorStates != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdce);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x328) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSetZbcColorClear != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdcf);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x330) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGetEncoderCapacity != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd0);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x338) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetP2pCaps != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd1);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x340) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcPerfGetLevelInfo != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd2);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x348) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocObject != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd3);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x350) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpuHandleVfPriFault != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd4);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x358) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcRmApiControl != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd5);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x360) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFabricMemStats != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd6);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x368) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlCmdNvlinkInbandSendData != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdd7);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x370) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGrCtxswZcullBind != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdd8);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x378) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlInternalMemsysSetZbcReferenced != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xdd9);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x380) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcSetupHibernationBuffer != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdda);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x388) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlPerfRatedTdpSetControl != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xddb);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x390) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlExecPartitionsCreate != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xddc);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x398) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGpfifoGetWorkSubmitToken != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xddd);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3a0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcIdleChannels != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdde);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3a8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlCmdInternalGpuStartFabricProbe != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xddf);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3b0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGetBrandCaps != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde0);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3b8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcRestoreHibernationData != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde1);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3c0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFlaSetupInstanceMemBlock != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xde2);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3c8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlInternalSriovPromotePmaStream != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xde3);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3d0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFbGetFsInfo != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde4);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3d8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcInitGspTraceCrashBuffer != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde5);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3e0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSetChannelInterleaveLevel != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xde6);
      return 0x56;
    }
    if (*(code **)(lVar2 + 1000) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgResumeContext != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde7);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3f0) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcAllocRoot != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde8);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x3f8) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFifoDisableChannels != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xde9);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x400) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlSetHsCredits != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdea);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x408) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcGetEngineUtilization != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdeb);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x410) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetZbcClearTableEntry != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdec);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x418) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlNvencSwSessionUpdateInfo != (void *) iGrp_ipVersions_UNASSIGNED"
                     ,"generated/g_rpc_private.h",0xded);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x420) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgSuspendContext != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdee);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x428) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlGetP2pCapsMatrix != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdef);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x430) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlDbgExecRegOps != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdf0);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x438) == iGrp_ipVersions_UNASSIGNED) {
      nvAssertFailed("pRpcHal->rpcCtrlFreePmaStream != (void *) iGrp_ipVersions_UNASSIGNED",
                     "generated/g_rpc_private.h",0xdf1);
      return 0x56;
    }
    if (*(code **)(lVar2 + 0x440) != iGrp_ipVersions_UNASSIGNED) {
      if (*(code **)(lVar2 + 0x448) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlMasterGetVirtualFunctionErrorContIntrMask != (void *) iGrp_ipVersions_UNASSIGNED"
                       ,"generated/g_rpc_private.h",0xdf3);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x450) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlReserveHes != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdf4);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x458) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcLog != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdf5);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x460) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlDbgGetModeMmuGccDebug != (void *) iGrp_ipVersions_UNASSIGNED"
                       ,"generated/g_rpc_private.h",0xdf6);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x468) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlExecPartitionsDelete != (void *) iGrp_ipVersions_UNASSIGNED"
                       ,"generated/g_rpc_private.h",0xdf7);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x470) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlPerfBoost != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdf8);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x478) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlDbgSetModeMmuDebug != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdf9);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x480) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlFifoSetChannelProperties != (void *) iGrp_ipVersions_UNASSIGNED"
                       ,"generated/g_rpc_private.h",0xdfa);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x488) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlSubdeviceGetP2pCaps != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdfb);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x490) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcUpdateBarPde != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdfc);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x498) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlBindPmResources != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdfd);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x4a0) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcMapMemoryDma != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xdfe);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x4a8) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcUpdateGpmGuestBufferInfo != (void *) iGrp_ipVersions_UNASSIGNED"
                       ,"generated/g_rpc_private.h",0xdff);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x4b0) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcCtrlSetVgpuFbUsage != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xe00);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x4b8) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcUnmapMemoryDma != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xe01);
        return 0x56;
      }
      if (*(code **)(lVar2 + 0x4c0) == iGrp_ipVersions_UNASSIGNED) {
        nvAssertFailed("pRpcHal->rpcSetGuestSystemInfoExt != (void *) iGrp_ipVersions_UNASSIGNED",
                       "generated/g_rpc_private.h",0xe02);
        return 0x56;
      }
      return 0;
    }
    nvAssertFailed("pRpcHal->rpcCtrlSetTsgInterleaveLevel != (void *) iGrp_ipVersions_UNASSIGNED",
                   "generated/g_rpc_private.h",0xdf2);
    return 0x56;
  }
LAB_0029cb7d:
  nvAssertFailed("pRpcHal->rpcCtrlFifoSetupVfZombieSubctxPdb != (void *) iGrp_ipVersions_UNASSIGNED"
                 ,"generated/g_rpc_private.h",0xd72);
  return 0x56;
}


// ===== 0029ed10 rpc_iGrp_ipVersions_Install_v04_00 =====

void rpc_iGrp_ipVersions_Install_v04_00(void)

{
  return;
}


// ===== 0029ed20 rpc_iGrp_ipVersions_Install_v05_00 =====

void rpc_iGrp_ipVersions_Install_v05_00(void)

{
  return;
}


// ===== 0029ed30 rpc_iGrp_ipVersions_Install_v06_00 =====

void rpc_iGrp_ipVersions_Install_v06_00(void)

{
  return;
}


// ===== 0029ed40 rpc_iGrp_ipVersions_Install_v07_00 =====

void rpc_iGrp_ipVersions_Install_v07_00(void)

{
  return;
}


// ===== 0029ed50 rpc_iGrp_ipVersions_Install_v07_07 =====

void rpc_iGrp_ipVersions_Install_v07_07(void)

{
  return;
}


// ===== 0029ed60 rpc_iGrp_ipVersions_Install_v08_01 =====

void rpc_iGrp_ipVersions_Install_v08_01(void)

{
  return;
}


// ===== 0029ed70 rpc_iGrp_ipVersions_Install_v09_08 =====

void rpc_iGrp_ipVersions_Install_v09_08(void)

{
  return;
}


// ===== 0029ed80 rpc_iGrp_ipVersions_Install_v09_0B =====

void rpc_iGrp_ipVersions_Install_v09_0B(void)

{
  return;
}


// ===== 0029ed90 rpc_iGrp_ipVersions_Install_v12_01 =====

void rpc_iGrp_ipVersions_Install_v12_01(void)

{
  return;
}


// ===== 0029eda0 rpc_iGrp_ipVersions_Install_v13_01 =====

void rpc_iGrp_ipVersions_Install_v13_01(void)

{
  return;
}


// ===== 0029edb0 rpc_iGrp_ipVersions_Install_v14_00 =====

void rpc_iGrp_ipVersions_Install_v14_00(void)

{
  return;
}


// ===== 0029edc0 rpc_iGrp_ipVersions_Install_v14_01 =====

void rpc_iGrp_ipVersions_Install_v14_01(void)

{
  return;
}


// ===== 0029edd0 rpc_iGrp_ipVersions_Install_v14_02 =====

void rpc_iGrp_ipVersions_Install_v14_02(void)

{
  return;
}


// ===== 0029ede0 rpc_iGrp_ipVersions_Install_v15_00 =====

void rpc_iGrp_ipVersions_Install_v15_00(void)

{
  return;
}


// ===== 0029edf0 rpc_iGrp_ipVersions_Install_v15_02 =====

void rpc_iGrp_ipVersions_Install_v15_02(void)

{
  return;
}


// ===== 0029ee00 rpc_iGrp_ipVersions_Install_v17_00 =====

void rpc_iGrp_ipVersions_Install_v17_00(void)

{
  return;
}


// ===== 0029ee10 rpc_iGrp_ipVersions_Install_v18_12 =====

void rpc_iGrp_ipVersions_Install_v18_12(void)

{
  return;
}


// ===== 0029ee20 rpc_iGrp_ipVersions_Install_v1A_05 =====

void rpc_iGrp_ipVersions_Install_v1A_05(void)

{
  return;
}


// ===== 0029ee30 rpc_iGrp_ipVersions_Install_v1A_08 =====

void rpc_iGrp_ipVersions_Install_v1A_08(void)

{
  return;
}


// ===== 0029ee40 rpc_iGrp_ipVersions_Install_v1A_09 =====

void rpc_iGrp_ipVersions_Install_v1A_09(void)

{
  return;
}


// ===== 0029ee50 rpc_iGrp_ipVersions_Install_v1A_0A =====

void rpc_iGrp_ipVersions_Install_v1A_0A(void)

{
  return;
}


// ===== 0029ee60 rpc_iGrp_ipVersions_Install_v1A_0C =====

void rpc_iGrp_ipVersions_Install_v1A_0C(void)

{
  return;
}


// ===== 0029ee70 rpc_iGrp_ipVersions_Install_v1A_0E =====

void rpc_iGrp_ipVersions_Install_v1A_0E(void)

{
  return;
}


// ===== 0029ee80 rpc_iGrp_ipVersions_Install_v1A_0F =====

void rpc_iGrp_ipVersions_Install_v1A_0F(void)

{
  return;
}


// ===== 0029ee90 rpc_iGrp_ipVersions_Install_v1A_10 =====

void rpc_iGrp_ipVersions_Install_v1A_10(void)

{
  return;
}


// ===== 0029eea0 rpc_iGrp_ipVersions_Install_v1A_14 =====

void rpc_iGrp_ipVersions_Install_v1A_14(void)

{
  return;
}


// ===== 0029eeb0 rpc_iGrp_ipVersions_Install_v1A_16 =====

void rpc_iGrp_ipVersions_Install_v1A_16(void)

{
  return;
}


// ===== 0029eec0 rpc_iGrp_ipVersions_Install_v1A_1A =====

void rpc_iGrp_ipVersions_Install_v1A_1A(void)

{
  return;
}


// ===== 0029eed0 rpc_iGrp_ipVersions_Install_v1A_1C =====

void rpc_iGrp_ipVersions_Install_v1A_1C(void)

{
  return;
}


// ===== 0029eee0 rpc_iGrp_ipVersions_Install_v1A_1D =====

void rpc_iGrp_ipVersions_Install_v1A_1D(void)

{
  return;
}


// ===== 0029eef0 rpc_iGrp_ipVersions_Install_v1A_1E =====

void rpc_iGrp_ipVersions_Install_v1A_1E(void)

{
  return;
}


