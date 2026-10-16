// ===== 0025b580 _nvswitch_i2c_set_port_pmgr =====

void _nvswitch_i2c_set_port_pmgr(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  uint *puVar5;
  
  lVar3 = *(long *)(param_1 + 0xf48);
  if (3 < param_2) {
    nvswitch_assert_log();
  }
  lVar1 = lVar3 + (ulong)param_2 * 4;
  uVar2 = *(uint *)(lVar1 + 0x164);
  *(uint *)(lVar1 + 0x164) = uVar2 | 1;
  *(undefined4 *)(lVar3 + 0x50 + (ulong)param_2 * 0x58) = 0;
  if (*(uint *)(lVar3 + 400) != 0) {
    puVar4 = *(uint **)(lVar3 + 0x188);
    puVar5 = puVar4 + (ulong)*(uint *)(lVar3 + 400) * 4;
    do {
      if (*puVar4 == param_2) {
        *(uint *)(lVar1 + 0x164) = uVar2 | 3;
        return;
      }
      puVar4 = puVar4 + 4;
    } while (puVar4 != puVar5);
  }
  return;
}


// ===== 0025b620 _nvswitch_read_rom_bytes.isra.0 =====

undefined8
_nvswitch_read_rom_bytes_isra_0
          (undefined8 param_1,undefined1 param_2,ushort param_3,uint param_4,uint param_5,
          long param_6,uint param_7)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined1 local_14c;
  undefined1 local_14b;
  ushort local_14a;
  undefined4 local_148;
  undefined1 local_140;
  undefined1 local_13f;
  uint local_13c;
  undefined1 local_138 [264];
  
  memset(&local_14c,0,0x114);
  if ((uint)(1 << ((byte)param_4 & 0x1f)) < param_7 + param_5) {
    uVar1 = 0xffffffff;
  }
  else {
    local_14b = 1;
    if (param_4 < 9) {
      local_148 = 0xc2f;
      local_14a = param_3;
    }
    else {
      local_13f = (undefined1)param_5;
      local_14a = (ushort)(param_5 >> 0xf) & 6 | param_3;
      local_148 = 0xc4f;
      param_5 = param_5 >> 8;
    }
    local_140 = (undefined1)param_5;
    local_13c = param_7;
    local_14c = param_2;
    uVar1 = nvswitch_ctrl_i2c_indexed(param_1,&local_14c);
    if (((int)uVar1 == 0) && (local_13c != 0)) {
      uVar2 = 0;
      do {
        *(undefined1 *)(param_6 + uVar2) = local_138[uVar2];
        uVar2 = uVar2 + 1;
      } while (local_13c != uVar2);
    }
  }
  return uVar1;
}


// ===== 0025b730 nvswitch_read_rom_tables =====

void nvswitch_read_rom_tables(undefined8 param_1,uint *param_2)

{
  ulong uVar1;
  uint uVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  short *psVar9;
  undefined8 uVar10;
  ulong *puVar11;
  ushort unaff_R12W;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char cVar16;
  uint uVar17;
  uint uVar18;
  ushort local_b9;
  undefined4 local_b7;
  byte local_b3;
  byte local_b2 [2];
  ushort local_b0;
  ushort local_ae;
  short local_ac;
  char cStack_aa;
  char cStack_a9;
  char cStack_a8;
  char cStack_a7;
  short sStack_a6;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  char local_82;
  char cStack_81;
  byte bStack_80;
  byte bStack_7f;
  byte bStack_7e;
  ushort uStack_7d;
  undefined1 uStack_7b;
  undefined1 uStack_7a;
  ushort uStack_79;
  ushort uStack_77;
  byte bStack_75;
  byte bStack_74;
  byte bStack_73;
  undefined8 local_72;
  undefined8 local_6a;
  undefined2 local_62;
  undefined8 local_60;
  undefined2 uStack_58;
  ushort uStack_56;
  undefined4 uStack_54;
  ushort local_50;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  byte bStack_4b;
  undefined2 uStack_4a;
  undefined4 local_48;
  undefined4 uStack_44;
  ulong local_40 [2];
  
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  iVar6 = nvswitch_get_rom_info(param_1,&local_a0);
  if (iVar6 == 0) {
    *param_2 = 0;
    local_60._0_1_ = '\0';
    local_60._1_1_ = 0;
    local_60._2_1_ = '\0';
    local_60._3_1_ = '\0';
    local_60._4_1_ = 0;
    local_60._5_1_ = 0;
    local_60._6_2_ = 0;
    uStack_58 = 0;
    uStack_56 = 0;
    uStack_54 = 0;
    local_50 = 0;
    uStack_4e = 0;
    uStack_4d = 0;
    uStack_4c = 0;
    bStack_4b = 0;
    uStack_4a = 0;
    local_48 = 0;
    uStack_44 = 0;
    iVar6 = _nvswitch_read_rom_bytes_isra_0
                      (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,0,&local_60,0x20)
    ;
    if ((((iVar6 == 0) && ((char)local_60 == 'N')) && (local_60._1_1_ == 0x56)) &&
       ((local_60._2_1_ == 'L' && (local_60._3_1_ == 'S')))) {
      puVar11 = &local_60;
      uVar8 = 0;
      do {
        uVar1 = *puVar11;
        puVar11 = puVar11 + 1;
        uVar8 = (uVar8 & 0x7f7f7f7f7f7f7f7f) + (uVar1 & 0x7f7f7f7f7f7f7f7f) ^
                (uVar1 ^ uVar8) & 0x8080808080808080;
      } while (puVar11 != local_40);
      if ((char)((char)uVar8 + (char)(uVar8 >> 8) + (char)(uVar8 >> 0x10) + (char)(uVar8 >> 0x18) +
                 (char)(uVar8 >> 0x20) + (char)(uVar8 >> 0x28) + (char)(uVar8 >> 0x30) +
                (char)(uVar8 >> 0x38)) == '\0') {
        _local_ac = 0;
        *(ulong *)(param_2 + 1) = CONCAT44(uStack_54,CONCAT22(uStack_56,uStack_58));
        local_a4 = 0;
        *param_2 = (uint)local_50 << 9;
        uVar17 = (uint)local_60._6_2_;
        iVar6 = _nvswitch_read_rom_bytes_isra_0
                          (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                           local_60._6_2_,&local_ac,0xc);
        if ((((iVar6 == 0) && (local_ac == -0x4701)) &&
            ((cStack_aa == 'B' &&
             (((cStack_a9 == 'I' && (cStack_a8 == 'T')) && (cStack_a7 == '\0')))))) &&
           (sStack_a6 == 0x100)) {
          psVar9 = &local_ac;
          cVar16 = '\0';
          do {
            cVar16 = cVar16 + (char)*psVar9;
            psVar9 = (short *)((long)psVar9 + 1);
          } while (psVar9 != (short *)&local_a0);
          if (((cVar16 == '\0') && (uVar17 = (local_a4 & 0xff) + uVar17, uVar17 < *param_2)) &&
             (local_a4._2_1_ != 0)) {
            uVar7 = (uint)local_a4._2_1_;
            uVar2 = local_a4 >> 8;
            uVar12 = 0;
            local_b0 = unaff_R12W;
            while( true ) {
              iVar6 = _nvswitch_read_rom_bytes_isra_0
                                (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,uVar17,
                                 local_b2,6);
              if (iVar6 != 0) break;
              if (*param_2 <= (uint)local_ae) goto LAB_0025bb20;
              if (local_b2[0] == 0x52) {
                *(undefined1 *)(param_2 + 3) = 0;
                uVar5 = 0x18;
                if (local_b0 < 0x19) {
                  uVar5 = local_b0;
                }
                local_60._0_1_ = '\0';
                local_60._1_1_ = 0;
                local_60._2_1_ = '\0';
                local_60._3_1_ = '\0';
                local_60._4_1_ = 0;
                local_60._5_1_ = 0;
                local_60._6_2_ = 0;
                uStack_58 = 0;
                uStack_56 = 0;
                uStack_54 = 0;
                local_50 = 0;
                uStack_4e = 0;
                uStack_4d = 0;
                uStack_4c = 0;
                bStack_4b = 0;
                uStack_4a = 0;
                iVar6 = _nvswitch_read_rom_bytes_isra_0
                                  (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                   local_ae,&local_60,uVar5);
                if (iVar6 != 0) goto LAB_0025bb20;
                *(undefined1 *)(param_2 + 3) = 1;
                if (local_b0 < 4) {
                  param_2[4] = 0;
                  *(undefined1 *)(param_2 + 5) = 0;
LAB_0025bdb9:
                  *(undefined2 *)((long)param_2 + 0x1d) = 0;
LAB_0025bdc1:
                  uVar4 = 0xffff;
                }
                else {
                  param_2[4] = CONCAT13(local_60._3_1_,
                                        CONCAT12(local_60._2_1_,
                                                 CONCAT11(local_60._1_1_,(char)local_60)));
                  if (local_b0 == 4) {
                    *(undefined1 *)(param_2 + 5) = 0;
                    goto LAB_0025bdb9;
                  }
                  *(undefined1 *)(param_2 + 5) = local_60._4_1_;
                  if ((local_b0 < 0xf) ||
                     (nvswitch_os_memcpy((long)param_2 + 0x15,(long)&local_60 + 7,8),
                     local_b0 < 0x13)) goto LAB_0025bdb9;
                  *(byte *)((long)param_2 + 0x1d) = ~uStack_54._3_1_ & 1;
                  if (local_b0 < 0x16) {
                    *(undefined1 *)((long)param_2 + 0x1e) = 0;
                    goto LAB_0025bdc1;
                  }
                  if (bStack_4b < 0x41) {
                    uVar8 = (ulong)bStack_4b;
                    if (bStack_4b != 0) goto LAB_0025c3fe;
                  }
                  else {
                    uVar8 = 0x40;
LAB_0025c3fe:
                    iVar6 = _nvswitch_read_rom_bytes_isra_0
                                      (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                       CONCAT11(uStack_4c,uStack_4d),(long)param_2 + 0x1e,uVar8);
                    if (iVar6 != 0) {
                      uVar8 = 0;
                    }
                  }
                  *(undefined1 *)((long)param_2 + uVar8 + 0x1e) = 0;
                  uVar4 = uStack_4a;
                  if (local_b0 < 0x18) goto LAB_0025bdc1;
                }
                *(undefined2 *)(param_2 + 0x18) = uVar4;
              }
              else if (local_b2[0] < 0x53) {
                if (local_b2[0] == 0x43) {
                  *(undefined1 *)(param_2 + 0x19) = 0;
                  uVar5 = 0x1c;
                  if (local_b0 < 0x1d) {
                    uVar5 = local_b0;
                  }
                  local_60._0_1_ = '\0';
                  local_60._1_1_ = 0;
                  local_60._2_1_ = '\0';
                  local_60._3_1_ = '\0';
                  local_60._4_1_ = 0;
                  local_60._5_1_ = 0;
                  local_60._6_2_ = 0;
                  uStack_58 = 0;
                  uStack_56 = 0;
                  uStack_54 = 0;
                  local_50 = 0;
                  uStack_4e = 0;
                  uStack_4d = 0;
                  uStack_4c = 0;
                  bStack_4b = 0;
                  uStack_4a = 0;
                  local_48 = 0;
                  iVar6 = _nvswitch_read_rom_bytes_isra_0
                                    (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                     local_ae,&local_60,uVar5);
                  if ((iVar6 == 0) && (3 < local_b0)) {
                    uVar18 = CONCAT13(local_60._3_1_,
                                      CONCAT12(local_60._2_1_,
                                               CONCAT11(local_60._1_1_,(char)local_60)));
                    if ((uVar18 != 0) && ((ulong)uVar18 + 4 <= (ulong)*param_2)) {
                      local_b7 = local_b7 & 0xffffff;
                      iVar6 = _nvswitch_read_rom_bytes_isra_0
                                        (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_
                                         ,(ulong)uVar18,&local_b7,4);
                      if ((((iVar6 == 0) && ((char)local_b7 == 'P')) && (local_b7._1_1_ == '\x04'))
                         && (local_b7._2_1_ == '\x13')) {
                        uVar15 = (uint)local_b7._3_1_;
                        *(undefined1 *)(param_2 + 0x19) = 1;
                        *(undefined1 *)(param_2 + 0x1a) = 0;
                        if (local_b7._3_1_ != 0) {
                          uVar14 = uVar18 + 4;
                          do {
                            if ((ulong)*param_2 < (ulong)uVar14 + 0x13) break;
                            iVar6 = _nvswitch_read_rom_bytes_isra_0
                                              (param_1,local_a0 & 0xffffffff,local_a0._4_4_,
                                               local_98._4_4_,(ulong)uVar14,&local_82,0x13);
                            if (iVar6 != 0) break;
                            if ((local_82 == '\a') && ((char)param_2[0x1a] == '\0')) {
                              *(undefined1 *)(param_2 + 0x1a) = 1;
                              param_2[0x1b] = (uint)CONCAT11(bStack_80,cStack_81);
                              param_2[0x1c] = (uint)CONCAT11(bStack_7e,bStack_7f);
                              param_2[0x1d] = (uint)uStack_7d;
                              param_2[0x1e] = (uint)CONCAT11(uStack_7a,uStack_7b);
                              param_2[0x1f] = (uint)uStack_79;
                              param_2[0x20] = (uint)uStack_77;
                              param_2[0x21] = (uint)bStack_75;
                              param_2[0x22] = (uint)bStack_74;
                              param_2[0x23] = (uint)bStack_73;
                              param_2[0x24] = (uint)(byte)local_72;
                              param_2[0x25] = (uint)local_72._1_1_;
                              param_2[0x26] = (uint)local_72._2_1_;
                            }
                            uVar14 = uVar14 + 0x13;
                          } while (uVar15 * 0x13 + 4 + uVar18 != uVar14);
                        }
                      }
                    }
                  }
                }
                else if (local_b2[0] == 0x49) {
                  *(undefined1 *)(param_2 + 0x28) = 0;
                  uVar5 = 0x22;
                  if (local_b0 < 0x23) {
                    uVar5 = local_b0;
                  }
                  local_82 = '\0';
                  cStack_81 = '\0';
                  bStack_80 = 0;
                  bStack_7f = 0;
                  bStack_7e = 0;
                  uStack_7d = 0;
                  uStack_7b = 0;
                  uStack_7a = 0;
                  uStack_79 = 0;
                  uStack_77 = 0;
                  bStack_75 = 0;
                  bStack_74 = 0;
                  bStack_73 = 0;
                  local_72 = 0;
                  local_6a = 0;
                  local_62 = 0;
                  iVar6 = _nvswitch_read_rom_bytes_isra_0
                                    (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                     local_ae,&local_82,uVar5);
                  if (((0x1d < local_b0) && (iVar6 == 0)) &&
                     ((local_6a._4_2_ != 0 && (local_6a._4_2_ + 0x25 <= *param_2)))) {
                    iVar6 = _nvswitch_read_rom_bytes_isra_0
                                      (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                       local_6a._4_2_,&local_60,0x25);
                    if (((iVar6 == 0) && (local_60._1_1_ != 0)) && ((char)local_60 == '\x01')) {
                      *(undefined1 *)(param_2 + 0x28) = 1;
                      if (local_60._1_1_ < 0xc) {
                        param_2[0x2a] = 0xffffffff;
                        param_2[0x2b] = 0xffffffff;
LAB_0025bb15:
                        uVar10 = 0;
                      }
                      else {
                        *(ulong *)(param_2 + 0x2a) =
                             ~CONCAT26(uStack_56,
                                       CONCAT24(uStack_58,
                                                CONCAT22(local_60._6_2_,
                                                         CONCAT11(local_60._5_1_,local_60._4_1_))));
                        if (local_60._1_1_ < 0x25) goto LAB_0025bb15;
                        uVar10 = CONCAT53((undefined5)local_40[0],uStack_44._1_3_);
                      }
                      *(undefined8 *)(param_2 + 0x2c) = uVar10;
                    }
                  }
                }
              }
              else if (local_b2[0] == 0x6e) {
                *(undefined1 *)(param_2 + 0x2e) = 0;
                uVar5 = 2;
                if (local_b0 < 3) {
                  uVar5 = local_b0;
                }
                iVar6 = _nvswitch_read_rom_bytes_isra_0
                                  (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                   local_ae,&local_b9,uVar5);
                if (((iVar6 == 0) && (local_b9 != 0)) && ((uint)local_b9 < *param_2)) {
                  iVar6 = _nvswitch_read_rom_bytes_isra_0
                                    (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_,
                                     local_b9,&local_60,0x23);
                  if (((iVar6 == 0) && (9 < local_60._1_1_)) &&
                     (((char)local_60 == 'A' && (CONCAT22(uStack_58,local_60._6_2_) == 0x4edcbdcb)))
                     ) {
                    uVar5 = CONCAT11(local_60._5_1_,local_60._4_1_);
                    if ((uVar5 != 0) && (uVar5 + 8 <= *param_2)) {
                      iVar6 = _nvswitch_read_rom_bytes_isra_0
                                        (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_
                                         ,(uint)uVar5,&local_82,8);
                      if ((iVar6 == 0) &&
                         (((local_82 == 'A' && (cStack_81 == '\b')) && (bStack_80 != 0)))) {
                        uVar15 = (uint)bStack_80;
                        uVar18 = uVar5 + 0xc;
                        uVar14 = (uint)bStack_7f;
                        uVar13 = 0;
                        do {
                          if (*param_2 < uVar18) break;
                          iVar6 = _nvswitch_read_rom_bytes_isra_0
                                            (param_1,local_a0 & 0xffffffff,local_a0._4_4_,
                                             local_98._4_4_,uVar18 - 4,&local_b7,4);
                          if (iVar6 != 0) break;
                          if ((local_b7 & 0x1c) == 0) {
                            uVar8 = 0;
                            do {
                              if ((local_b7 & 0x1f) == (uint)(&bStack_7e)[uVar8]) {
                                uVar8 = uVar8 & 0xffffffff;
                                *(undefined1 *)(param_2 + uVar8 * 3 + 0x2f) = 1;
                                param_2[uVar8 * 3 + 0x30] = local_b7 >> 0x1c;
                                *(byte *)(param_2 + uVar8 * 3 + 0x31) = (byte)(local_b7 >> 10) & 1;
                                break;
                              }
                              uVar8 = uVar8 + 1;
                            } while (uVar8 != 4);
                          }
                          uVar13 = uVar13 + 1;
                          uVar18 = uVar18 + uVar14;
                        } while (uVar15 != uVar13);
                      }
                    }
                    uVar5 = CONCAT11(uStack_4d,uStack_4e);
                    if ((uVar5 != 0) && (uVar5 + 5 <= *param_2)) {
                      bStack_80 = 0;
                      iVar6 = _nvswitch_read_rom_bytes_isra_0
                                        (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_
                                         ,(uint)uVar5,&local_82,5);
                      bVar3 = bStack_80;
                      if (((iVar6 == 0) && ((local_82 == '@' && (cStack_81 == '\x05')))) &&
                         ((bStack_7f == 4 && (param_2[0x3b] = 0, bStack_80 != 0)))) {
                        uVar18 = uVar5 + 9;
                        uVar15 = 0;
                        do {
                          if ((*param_2 < uVar18) || (0xf < param_2[0x3b])) break;
                          iVar6 = _nvswitch_read_rom_bytes_isra_0
                                            (param_1,local_a0 & 0xffffffff,local_a0._4_4_,
                                             local_98._4_4_,uVar18 - 4,&local_b7,4);
                          if (iVar6 != 0) break;
                          if ((local_b7 & 0xff) != 0xff) {
                            uVar8 = (ulong)param_2[0x3b];
                            param_2[0x3b] = param_2[0x3b] + 1;
                            param_2[uVar8 * 4 + 0x3e] = local_b7 & 0xff;
                            param_2[uVar8 * 4 + 0x3d] = local_b7 >> 8 & 0xff;
                            param_2[uVar8 * 4 + 0x3c] = local_b7 >> 0x14 & 1 | local_b7 >> 0x1a & 2;
                          }
                          uVar15 = uVar15 + 1;
                          uVar18 = uVar18 + 4;
                        } while (uVar15 != bVar3);
                      }
                    }
                    if ((uStack_56 != 0) && (uStack_56 + 6 <= *param_2)) {
                      bStack_80 = 0;
                      uVar18 = (uint)uStack_56;
                      iVar6 = _nvswitch_read_rom_bytes_isra_0
                                        (param_1,local_a0 & 0xffffffff,local_a0._4_4_,local_98._4_4_
                                         ,(uint)uStack_56,&local_82,6);
                      if ((iVar6 == 0) &&
                         ((((local_82 == 'B' && (cStack_81 == '\x06')) && (bStack_7f == 5)) &&
                          (param_2[0x7c] = 0, bStack_80 != 0)))) {
                        uVar13 = (uint)bStack_80;
                        uVar14 = (uint)bStack_80;
                        uVar15 = uVar18 + 0xb;
                        do {
                          if ((*param_2 < uVar15) || (param_2[0x7c] == 0x19)) break;
                          iVar6 = _nvswitch_read_rom_bytes_isra_0
                                            (param_1,local_a0 & 0xffffffff,local_a0._4_4_,
                                             local_98._4_4_,uVar15 - 5,&local_b7,5);
                          if (iVar6 != 0) break;
                          if (local_b7._1_1_ != 0xff) {
                            uVar8 = (ulong)param_2[0x7c];
                            param_2[0x7c] = param_2[0x7c] + 1;
                            param_2[uVar8 * 4 + 0x7e] = (uint)local_b7._1_1_;
                            param_2[uVar8 * 4 + 0x7d] = local_b7 & 0x3f;
                            param_2[uVar8 * 4 + 0x7f] = local_b7 >> 0x18 & 0x1f;
                            param_2[uVar8 * 4 + 0x80] = (uint)(local_b3 >> 4);
                          }
                          uVar15 = uVar15 + 5;
                        } while (uVar15 != uVar14 + uVar13 * 4 + 0xb + uVar18);
                      }
                    }
                  }
                }
              }
LAB_0025bb20:
              uVar12 = uVar12 + 1;
              if (uVar12 == uVar7) {
                return;
              }
              uVar17 = uVar17 + (uVar2 & 0xff);
              if (*param_2 <= uVar17) {
                return;
              }
            }
          }
        }
      }
      return;
    }
  }
  return;
}


// ===== 0025c4a0 nvswitch_smbpbi_init =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvswitch_smbpbi_init(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0xd20) == 0) {
    return 0xfffffff8;
  }
  lVar1 = nvswitch_os_malloc_trace(0x18,0,0);
  *(long *)(param_1 + 0xf50) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xfffffffe;
    uVar3 = 0;
  }
  else {
    nvswitch_os_memset(lVar1,0,0x18);
    (**(code **)(param_1 + 0x8b0))(param_1);
    uVar2 = (**(code **)(param_1 + 0x870))(param_1);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    uVar3 = *(undefined8 *)(param_1 + 0xf50);
  }
  nvswitch_os_free(uVar3);
  return uVar2 & 0xffffffff;
}


// ===== 0025c530 nvswitch_smbpbi_post_init =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_smbpbi_post_init(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0xf50) != 0) {
    uVar1 = (**(code **)(param_1 + 0x878))();
    return uVar1;
  }
  return 0xfffffff3;
}


// ===== 0025c550 nvswitch_smbpbi_unload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_smbpbi_unload(long param_1)

{
  if (*(long *)(param_1 + 0xf50) != 0) {
    (**(code **)(param_1 + 0x888))();
    (**(code **)(param_1 + 0x898))();
    return;
  }
  return;
}


// ===== 0025c5a0 nvswitch_smbpbi_destroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nvswitch_smbpbi_destroy(long param_1)

{
  if (*(long *)(param_1 + 0xf50) != 0) {
    (**(code **)(param_1 + 0x880))();
    nvswitch_os_free(*(undefined8 *)(param_1 + 0xf50));
    *(undefined8 *)(param_1 + 0xf50) = 0;
    return;
  }
  return;
}


// ===== 0025c5f0 nvswitch_smbpbi_refresh_ecc_counts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 nvswitch_smbpbi_refresh_ecc_counts(long param_1)

{
  long lVar1;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  if ((((*(long **)(param_1 + 0xf50) != (long *)0x0) && (**(long **)(param_1 + 0xf50) != 0)) &&
      (*(long *)(param_1 + 0xf40) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xf40) + 0xf68), lVar1 != 0)) {
    (**(code **)(param_1 + 0x838))(param_1,*(undefined8 *)(lVar1 + 0x10),&local_28,local_20);
    lVar1 = **(long **)(param_1 + 0xf50);
    *(undefined8 *)(lVar1 + 0x88) = local_28;
    *(undefined8 *)(lVar1 + 0x80) = local_20[0];
    return 0;
  }
  return 0xfffffff3;
}


// ===== 0025c680 nvswitch_smbpbi_set_link_error_info =====

undefined1  [16]
nvswitch_smbpbi_set_link_error_info(long param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 *puVar4;
  undefined1 local_74 [4];
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  undefined1 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48;
  undefined8 local_44;
  
  if (*(long *)(param_1 + 0xf50) != 0) {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_64,0,0x3c);
    local_60 = 3;
    local_64[0] = 0x2809;
    local_5c = *param_2;
    local_48 = *param_3;
    local_58 = *(undefined8 *)(param_2 + 8);
    local_50 = *(undefined8 *)(param_2 + 0x10);
    local_44 = *(undefined8 *)(param_3 + 8);
    nvswitch_timeout_create(1000000000,local_70);
    puVar4 = local_74;
    auVar2._0_8_ = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,puVar4,local_70);
    auVar2._8_8_ = puVar4;
    return auVar2;
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = 0xfffffff3;
  return auVar3;
}


// ===== 0025c740 soeService_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeService_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0x80) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0x80))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c770 soeServiceHalt_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void soeServiceHalt_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x88) != (code *)0x0) {
    (**(code **)(*param_2 + 0x88))();
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 0025c7a0 soeEmemTransfer_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void soeEmemTransfer_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0x90) != (code *)0x0) {
    (**(code **)(*param_2 + 0x90))();
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 0025c7e0 soeGetEmemSize_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeGetEmemSize_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0x98) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0x98))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c810 soeGetEmemStartOffset_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeGetEmemStartOffset_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0xa0) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0xa0))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c840 soeEmemPortToRegAddr_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeEmemPortToRegAddr_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0xa8) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0xa8))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0x1f;
}


// ===== 0025c870 soeServiceExterr_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void soeServiceExterr_HAL(undefined8 param_1,long *param_2)

{
  if (*(code **)(*param_2 + 0xb0) != (code *)0x0) {
    (**(code **)(*param_2 + 0xb0))();
    return;
  }
  nvswitch_assert_log();
  return;
}


// ===== 0025c8a0 soeGetExtErrRegAddrs_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeGetExtErrRegAddrs_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0xb8) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0xb8))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0x1f;
}


// ===== 0025c8d0 soeEmemPortSizeGet_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeEmemPortSizeGet_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0xc0) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0xc0))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c900 soeIsCpuHalted_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeIsCpuHalted_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 200) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 200))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c930 soeTestDma_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeTestDma_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0xd0) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0xd0))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0xffffffff;
}


// ===== 0025c960 soeProcessMessages_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeProcessMessages_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0x70) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0x70))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c990 soeWaitForInitAck_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeWaitForInitAck_HAL(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_2 + 0x78) != (code *)0x0) {
    uVar1 = (**(code **)(*param_2 + 0x78))();
    return uVar1;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c9c0 soeI2CAccess_HAL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 soeI2CAccess_HAL(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(code **)(**(long **)(param_1 + 0xd20) + 0x100);
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  nvswitch_assert_log();
  return 0;
}


// ===== 0025c9f0 _soeQueueSeqInfoGet_IMPL =====

long _soeQueueSeqInfoGet_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_3 < *(uint *)(*(long *)(param_2 + 8) + 0x34)) {
    lVar1 = param_2 + 0x10 + (ulong)param_3 * 0x28;
  }
  return lVar1;
}


// ===== 0025ca10 _soeQueueCmdValidate_IMPL =====

undefined4
_soeQueueCmdValidate_IMPL
          (undefined8 param_1,long param_2,byte *param_3,undefined8 param_4,undefined8 param_5,
          int param_6)

{
  uint uVar1;
  
  if ((param_6 == 0) &&
     (uVar1 = *(uint *)(*(long *)(*(long *)(*(long *)(param_2 + 8) + 0x58) + 0x30) + 0x90),
     (uint)param_3[1] <= uVar1 >> 1)) {
    return CONCAT31((uint3)(uVar1 >> 9),*param_3 < 0x12);
  }
  return 0;
}


// ===== 0025ca50 _soeEmemCopyFrom_IMPL =====

undefined1  [16] _soeEmemCopyFrom_IMPL(void)

{
  undefined1 auVar1 [16];
  undefined8 uStack_10;
  
  soeEmemTransfer_HAL();
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = 1;
  return auVar1;
}


// ===== 0025ca70 _soeEmemCopyTo_IMPL =====

undefined1  [16] _soeEmemCopyTo_IMPL(void)

{
  undefined1 auVar1 [16];
  undefined8 uStack_10;
  
  soeEmemTransfer_HAL();
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uStack_10;
  return auVar1 << 0x40;
}


// ===== 0025ca90 soeAllocNew =====

long soeAllocNew(void)

{
  long lVar1;
  
  lVar1 = nvswitch_os_malloc_trace(0x2820,0,0);
  if (lVar1 != 0) {
    nvswitch_os_memset(lVar1,0,0x2820);
  }
  return lVar1;
}


// ===== 0025cad0 soeInit =====

int soeInit(undefined8 param_1,long *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  if (*param_2 == 0) {
    lVar3 = nvswitch_os_malloc_trace(0x108,0,0);
    *param_2 = lVar3;
    if (lVar3 == 0) {
      iVar2 = -2;
      goto LAB_0025cb07;
    }
    nvswitch_os_memset(lVar3,0,0x108);
  }
  iVar2 = flcnableInit(param_1,param_2,param_3);
  if (iVar2 == 0) {
    cVar1 = nvswitch_is_lr10_device_id(param_3);
    if (cVar1 == '\0') {
      cVar1 = nvswitch_is_ls10_device_id(param_3);
      if (cVar1 == '\0') {
        nvswitch_assert_log();
      }
      else {
        soeSetupHal_LS10(param_2);
      }
    }
    else {
      soeSetupHal_LR10(param_2);
    }
    lVar3 = *param_2;
    *(code **)(lVar3 + 0x18) = _soeEmemCopyTo_IMPL;
    *(code **)(lVar3 + 0x10) = _soeEmemCopyFrom_IMPL;
    *(code **)(lVar3 + 0x28) = _soeQueueSeqInfoGet_IMPL;
    *(code **)(lVar3 + 0x40) = _soeQueueCmdValidate_IMPL;
    return 0;
  }
LAB_0025cb07:
  flcnableDestroy(param_1,param_2);
  if (*param_2 != 0) {
    nvswitch_os_free();
    *param_2 = 0;
  }
  return iVar2;
}


// ===== 0025cbf0 soeDestroy =====

void soeDestroy(undefined8 param_1,long *param_2)

{
  flcnableDestroy();
  if (*param_2 != 0) {
    nvswitch_os_free();
    *param_2 = 0;
  }
  return;
}


// ===== 0025cc20 nvswitch_spi_init =====

undefined1  [16] nvswitch_spi_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 *puVar4;
  undefined1 local_74 [4];
  undefined1 local_70 [12];
  undefined2 local_64 [2];
  undefined1 local_60;
  
  if (*(long *)(param_1 + 0xd20) != 0) {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xd20) + 8);
    nvswitch_os_memset(local_64,0,0x3c);
    local_60 = 0;
    local_64[0] = 0x507;
    nvswitch_timeout_create(30000000,local_70);
    puVar4 = local_74;
    auVar2._0_8_ = flcnQueueCmdPostBlocking(param_1,uVar1,local_64,0,0,0,puVar4,local_70);
    auVar2._8_8_ = puVar4;
    return auVar2;
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = 0xfffffff8;
  return auVar3;
}


// ===== 0025ccb0 osNv_cpuid =====

undefined8
osNv_cpuid(int param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (param_1 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (param_1 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (param_1 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (param_1 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (param_1 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (param_1 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (param_1 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (param_1 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (param_1 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (param_1 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (param_1 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (param_1 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (param_1 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (param_1 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (param_1 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(param_1);
  }
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  *param_3 = *puVar1;
  *param_4 = uVar2;
  *param_5 = uVar4;
  *param_6 = uVar3;
  return 1;
}


// ===== 0025cce0 osNv_rdcr4 =====

void osNv_rdcr4(void)

{
  return;
}


// ===== 0025ccf0 timerCallbackToRemoveIdleHoldoff =====

void timerCallbackToRemoveIdleHoldoff(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = osQueueWorkItem(param_1,RmRemoveIdleHoldoff,0,0x100);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x5d6,"timerCallbackToRemoveIdleHoldoff",4,
               "NVRM: Queuing of remove idle holdoff work item failed with status : 0x%x\n",iVar1);
  return;
}


// ===== 0025cd50 RmScheduleCallbackForIdlePreConditionsUnderGpuLock =====

void RmScheduleCallbackForIdlePreConditionsUnderGpuLock(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  undefined1 local_20;
  
  lVar3 = 0;
  if ((param_1 != 0) && (lVar3 = 0, *(long **)(param_1 + 0x4e0) != (long *)0x0)) {
    lVar3 = **(long **)(param_1 + 0x4e0);
  }
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "arch/nvalloc/unix/src/dynamic-power.c",0x773);
  }
  if ((*(char *)(lVar3 + 0x218) == '\0') && (*(long *)(lVar3 + 0x208) != 0)) {
    portMemSet(&local_30,0,0x18);
    local_20 = 0;
    local_30 = *(undefined8 *)(lVar3 + 0x208);
    local_28 = (-(ulong)(*(char *)(param_1 + 0x45d) == '\0') & 4500000000) + 500000000;
    iVar2 = tmrCtrlCmdEventSchedule(param_1,&local_30);
    if (iVar2 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x796,
                   "RmScheduleCallbackForIdlePreConditionsUnderGpuLock",4,
                   "NVRM: Error scheduling precondition callback\n");
      return;
    }
    *(undefined1 *)(lVar3 + 0x218) = 1;
  }
  return;
}


// ===== 0025ce50 RmScheduleCallbackToRemoveIdleHoldoff =====

void RmScheduleCallbackToRemoveIdleHoldoff(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  undefined8 local_28;
  undefined1 local_20;
  
  lVar3 = 0;
  if ((param_1 != 0) && (lVar3 = 0, *(long **)(param_1 + 0x4e0) != (long *)0x0)) {
    lVar3 = **(long **)(param_1 + 0x4e0);
  }
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "arch/nvalloc/unix/src/dynamic-power.c",0x7f4);
  }
  if (*(long *)(lVar3 + 0x220) != 0) {
    portMemSet(&local_30,0,0x18);
    local_20 = 0;
    local_30 = *(undefined8 *)(lVar3 + 0x220);
    local_28 = 5000000000;
    iVar2 = tmrCtrlCmdEventSchedule(param_1,&local_30);
    if (iVar2 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x802,
                   "RmScheduleCallbackToRemoveIdleHoldoff",4,
                   "NVRM: Error scheduling kernel refcount decrement callback\n");
      return;
    }
    *(undefined1 *)(lVar3 + 0x228) = 1;
  }
  return;
}


// ===== 0025cf2d RmCancelCallbackToRemoveIdleHoldoff.cold =====

void RmCancelCallbackToRemoveIdleHoldoff_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025cf40 RmCancelCallbackToRemoveIdleHoldoff =====

void RmCancelCallbackToRemoveIdleHoldoff(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 local_28 [2];
  
  if ((param_1 != 0) && (*(long **)(param_1 + 0x4e0) != (long *)0x0)) {
    lVar1 = **(long **)(param_1 + 0x4e0);
    if (*(long *)(lVar1 + 0x220) != 0) {
      portMemSet(local_28,0,0x10);
      local_28[0] = *(undefined8 *)(lVar1 + 0x220);
      tmrCtrlCmdEventCancel(param_1,local_28);
    }
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0025cfb0 RmPowerManagement =====

undefined8 RmPowerManagement(long param_1,uint param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long lVar7;
  int local_1c;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar7 = 0;
  plVar1 = *(long **)(param_1 + 0x4e0);
  if (plVar1 != (long *)0x0) {
    lVar7 = *plVar1;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x1c20);
  lVar3 = *(long *)(param_1 + 0x1b78);
  if (param_2 < 2) {
    if (*(char *)(param_1 + 0x493) == '\0') {
      if (*(char *)((long)plVar1 + 0x2ff) != '\0') {
        *(undefined4 *)(lVar3 + 0xbfc) = 0x40;
      }
    }
    else {
      *(undefined4 *)(lVar3 + 0xbfc) = 0x10;
    }
    if (param_2 == 1) {
      *(undefined1 *)(lVar7 + 0x1e0) = 0;
      uVar5 = intrGetIntrEn_IMPL(uVar2);
      *(undefined4 *)(lVar7 + 0x1dc) = uVar5;
      intrSetIntrEn_IMPL(uVar2,0);
      uVar6 = gpuEnterStandby_IMPL(param_1);
    }
    else {
      *(undefined1 *)(lVar7 + 0x1e0) = 1;
      uVar5 = intrGetIntrEn_IMPL(uVar2);
      *(undefined4 *)(lVar7 + 0x1dc) = uVar5;
      intrSetIntrEn_IMPL(uVar2,0);
      uVar6 = gpuEnterHibernate_IMPL(param_1);
    }
  }
  else {
    uVar6 = 0x1f;
    if (param_2 == 2) {
      if (*(char *)(lVar7 + 0x1e0) == '\0') {
        gpuResumeFromStandby_IMPL(param_1);
      }
      else {
        gpuResumeFromHibernate_IMPL();
      }
      intrSetIntrEn_IMPL(uVar2,*(undefined4 *)(lVar7 + 0x1dc));
      local_1c = 0;
      if (*(char *)(param_1 + 0x485) == '\0') {
        uVar6 = 0;
      }
      else {
        iVar4 = nv_acpi_get_powersource(&local_1c);
        if (iVar4 == 0) {
          RmPowerSourceChangeEvent(plVar1,local_1c == 0);
        }
        RmRequestDNotifierState(plVar1);
        uVar6 = 0;
      }
    }
  }
  *(undefined4 *)(lVar3 + 0xbfc) = 0;
  return uVar6;
}


// ===== 0025d17c RmCheckForGcxSupportOnCurrentState.cold =====

void RmCheckForGcxSupportOnCurrentState_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  
  rmapiGetInterface(4);
  portMemSet(unaff_RBP + -0x12,0,2);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025d1a0 RmCheckForGcxSupportOnCurrentState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool RmCheckForGcxSupportOnCurrentState(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  char local_1a;
  char local_19;
  
  if (param_1 == 0) {
    rmapiGetInterface(4);
    portMemSet(&local_1a,0,2);
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x4e0);
  lVar4 = rmapiGetInterface(4);
  portMemSet(&local_1a,0,2);
  iVar3 = (**(code **)(lVar4 + 0x38))
                    (lVar4,*(undefined4 *)(lVar1 + 0x310),*(undefined4 *)(lVar1 + 0x318),0x2080a7d7,
                     &local_1a,2);
  if (iVar3 == 0) {
    return local_1a != '\0' || local_19 != '\0';
  }
  nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x596,"RmCheckForGcxSupportOnCurrentState",4,
               "NVRM: NVRM, Failed to get GCx pre-requisite, status=0x%x\n",iVar3);
  return false;
}


// ===== 0025d254 RmRemoveIdleHoldoff.cold =====

void RmRemoveIdleHoldoff_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025d260 RmRemoveIdleHoldoff =====

void RmRemoveIdleHoldoff(void)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  long lVar5;
  
  lVar5 = gpumgrGetGpu();
  if ((lVar5 == 0) || (plVar1 = *(long **)(lVar5 + 0x4e0), plVar1 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar2 = *plVar1;
  if (*(char *)(lVar2 + 0x228) != '\x01') {
    return;
  }
  cVar4 = RmCheckForGcxSupportOnCurrentState(lVar5);
  if ((cVar4 != '\x01') && (*(char *)(lVar2 + 0x218) == '\0')) {
    RmScheduleCallbackToRemoveIdleHoldoff(lVar5);
    return;
  }
  nv_indicate_idle(plVar1);
  *(undefined1 *)(lVar2 + 0x228) = 0;
  return;
}


// ===== 0025d2f0 RmCanEnterGcxUnderGpuLock =====

undefined8 RmCanEnterGcxUnderGpuLock(long param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_20;
  
  lVar4 = 0;
  if ((param_1 != 0) && (lVar4 = 0, *(long **)(param_1 + 0x4e0) != (long *)0x0)) {
    lVar4 = **(long **)(param_1 + 0x4e0);
  }
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "arch/nvalloc/unix/src/dynamic-power.c",0x129);
  }
  if (((*(char *)(param_1 + 0x487) == '\0') || (*(char *)(lVar4 + 600) == '\0')) &&
     (*(char *)(param_1 + 0x45d) == '\0')) {
    local_20 = 0;
    iVar2 = memmgrGetUsedRamSize_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78),&local_20);
    if (((iVar2 != 0) || (*(ulong *)(lVar4 + 0x230) < local_20)) || (*(int *)(lVar4 + 0x22c) != 0))
    {
      return 0;
    }
  }
  uVar3 = RmCheckForGcxSupportOnCurrentState(param_1);
  return uVar3;
}


// ===== 0025d3c0 RmHandleIdleSustained =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RmHandleIdleSustained(void)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 local_40;
  long local_38;
  undefined1 local_30;
  
  lVar3 = gpumgrGetGpu();
  if (lVar3 == 0) {
    lVar5 = 0;
    lVar4 = 0;
    nv_revoke_gpu_mappings(0);
    cVar1 = rmDeviceGpuLockIsOwner(_DAT_000007a4);
  }
  else {
    lVar5 = 0;
    if (*(long **)(lVar3 + 0x4e0) != (long *)0x0) {
      lVar5 = **(long **)(lVar3 + 0x4e0);
    }
    nv_revoke_gpu_mappings();
    lVar4 = 0;
    if (*(long **)(lVar3 + 0x4e0) != (long *)0x0) {
      lVar4 = **(long **)(lVar3 + 0x4e0);
    }
    cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4));
  }
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "arch/nvalloc/unix/src/dynamic-power.c",0x7c7);
  }
  if (*(long *)(lVar4 + 0x210) != 0) {
    portMemSet(&local_40,0,0x18);
    local_30 = 0;
    local_40 = *(undefined8 *)(lVar4 + 0x210);
    local_38 = (-(ulong)(*(char *)(lVar3 + 0x45d) == '\0') & 0xffffffffe2329b00) + 700000000;
    iVar2 = tmrCtrlCmdEventSchedule(lVar3,&local_40);
    if (iVar2 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x7e0,"RmScheduleCallbackToIndicateIdle",
                   4,"NVRM: Error scheduling indicate idle callback\n");
    }
  }
  *(undefined1 *)(lVar5 + 0x22a) = 0;
  return;
}


// ===== 0025d4f0 RmAcpiD3ColdDsm =====

bool RmAcpiD3ColdDsm(undefined8 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint local_1c;
  
  local_1c = param_3;
  iVar1 = nv_acpi_d3cold_dsm_for_upstream_port(param_1,PEX_DSM_GUID,4,param_2,&local_1c);
  if (iVar1 != 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0xbd4,"RmAcpiD3ColdDsm",2,
                 "NVRM: %s: PEX _DSM subfunction: 0x%X failed.\n","RmAcpiD3ColdDsm",param_2);
    return false;
  }
  if (param_2 != 10) {
    if (param_2 != 0xb) {
      return (~local_1c & 0xc00) == 0;
    }
    return param_3 == local_1c;
  }
  return local_1c - 1 < 2;
}


// ===== 0025d5a7 RmConfigureUpstreamPortForRTD3.cold =====

void RmConfigureUpstreamPortForRTD3_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025d5c0 RmConfigureUpstreamPortForRTD3 =====

undefined4 RmConfigureUpstreamPortForRTD3(long *param_1,char param_2)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint local_2c;
  
  if ((param_1 == (long *)0x0) || (plVar1 = (long *)*param_1, plVar1 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  if ((char)plVar1[0x48] != '\0') {
    return 1;
  }
  lVar2 = *plVar1;
  uVar5 = RmAcpiD3ColdDsm(param_1,0,0);
  if ((char)uVar5 != '\0') {
    uVar7 = 0;
    if (param_2 != '\0') {
      uVar7 = (uint)*(ushort *)(lVar2 + 0x4b30);
    }
    local_2c = uVar7;
    iVar6 = nv_acpi_d3cold_dsm_for_upstream_port(param_1,PEX_DSM_GUID,4,0xb,&local_2c);
    if (iVar6 == 0) {
      if (uVar7 == local_2c) {
        if (param_2 == '\0') {
          cVar4 = RmAcpiD3ColdDsm(param_1,10,0);
          pcVar8 = "cleared";
          if (cVar4 == '\0') {
            return 0;
          }
        }
        else {
          cVar4 = RmAcpiD3ColdDsm(param_1,10,*(undefined2 *)(lVar2 + 0x4b32));
          pcVar8 = "applied";
          if (cVar4 == '\0') {
            RmAcpiD3ColdDsm(param_1,0xb,0);
            return 0;
          }
        }
        nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0xc0b,"RmConfigureUpstreamPortForRTD3",
                     2,"NVRM: Aux Power and Pex delay settings %s successfully.\n",pcVar8);
        return uVar5;
      }
    }
    else {
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0xbd4,"RmAcpiD3ColdDsm",2,
                   "NVRM: %s: PEX _DSM subfunction: 0x%X failed.\n","RmAcpiD3ColdDsm",0xb);
    }
    return 0;
  }
  return uVar5;
}


// ===== 0025d780 nv_dynamic_power_state_transition =====

ulong nv_dynamic_power_state_transition(long *param_1,uint param_2,uint param_3)

{
  char *pcVar1;
  uint *puVar2;
  char *pcVar3;
  bool bVar4;
  
  puVar2 = (uint *)&DAT_000001f8;
  if (param_1 != (long *)0x0) {
    puVar2 = (uint *)(*param_1 + 0x1f8);
  }
  if (param_2 == param_3) {
    nvAssertFailedNoLog("old_state != new_state","arch/nvalloc/unix/src/dynamic-power.c",0x100);
  }
  LOCK();
  bVar4 = param_2 == *puVar2;
  if (bVar4) {
    *puVar2 = param_3;
  }
  UNLOCK();
  if (!bVar4) {
    if (param_3 < 5) {
      pcVar3 = *(char **)(CSWTCH_95 + (ulong)param_3 * 8);
    }
    else {
      nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0xe6);
      pcVar3 = "UNEXPECTED";
    }
    if (param_2 < 5) {
      pcVar1 = *(char **)(CSWTCH_95 + (ulong)param_2 * 8);
    }
    else {
      nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0xe6);
      pcVar1 = "UNEXPECTED";
    }
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x10f,"nv_dynamic_power_state_transition",1
                 ,"NVRM: %s: FAILED state transition %s -> %s\n","nv_dynamic_power_state_transition"
                 ,pcVar1,pcVar3);
    goto LAB_0025d808;
  }
  if (param_3 < 5) {
    pcVar3 = *(char **)(CSWTCH_95 + (ulong)param_3 * 8);
    if (4 < param_2) goto LAB_0025d83a;
LAB_0025d7d2:
    pcVar1 = *(char **)(CSWTCH_95 + (ulong)param_2 * 8);
  }
  else {
    nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0xe6);
    pcVar3 = "UNEXPECTED";
    if (param_2 < 5) goto LAB_0025d7d2;
LAB_0025d83a:
    nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0xe6);
    pcVar1 = "UNEXPECTED";
  }
  nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x108,"nv_dynamic_power_state_transition",1,
               "NVRM: %s: state transition %s -> %s\n","nv_dynamic_power_state_transition",pcVar1,
               pcVar3);
LAB_0025d808:
  return CONCAT71((int7)((ulong)puVar2 >> 8),bVar4) & 0xffffffff;
}


// ===== 0025d93c RmForceGpuNotIdle.cold =====

void RmForceGpuNotIdle_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025d950 RmForceGpuNotIdle =====

void RmForceGpuNotIdle(void)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  undefined4 local_2c;
  
  lVar7 = gpumgrGetGpu();
  if ((lVar7 == 0) || (plVar2 = *(long **)(lVar7 + 0x4e0), plVar2 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar3 = *plVar2;
  portSyncMutexAcquire(*(undefined8 *)(lVar3 + 0x200));
  iVar1 = *(int *)(lVar3 + 0x1f8);
  if (iVar1 != 3) {
    if (iVar1 != 4) {
      if (iVar1 == 0) {
        nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0x18d);
      }
      goto LAB_0025d9af;
    }
    nv_indicate_not_idle(plVar2);
    if (*(char *)(lVar3 + 500) == '\0') {
      nvAssertFailedNoLog("nvp->dynamic_power.deferred_idle_enabled",
                          "arch/nvalloc/unix/src/dynamic-power.c",0x182);
    }
    iVar6 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar7 + 0x7a4),0,0,0x4002,&local_2c);
    if (iVar6 == 0) {
      RmScheduleCallbackForIdlePreConditionsUnderGpuLock(lVar7);
      rmGpuGroupLockRelease(local_2c,0);
    }
  }
  cVar5 = nv_dynamic_power_state_transition(plVar2,iVar1,2);
  if (cVar5 != '\x01') {
    nvAssertFailedNoLog(&DAT_00cc9e51,"arch/nvalloc/unix/src/dynamic-power.c",0x187);
  }
LAB_0025d9af:
  nv_acquire_mmap_lock(plVar2);
  nv_set_safe_to_mmap_locked(plVar2,1);
  nv_release_mmap_lock(plVar2);
  portSyncMutexRelease(*(undefined8 *)(lVar3 + 0x200));
  return;
}


// ===== 0025dab0 timerCallbackToIndicateIdle =====

void timerCallbackToIndicateIdle(long param_1)

{
  char cVar1;
  long *plVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    plVar2 = (long *)0x0;
    piVar3 = (int *)&DAT_000001f8;
  }
  else {
    plVar2 = *(long **)(param_1 + 0x4e0);
    piVar3 = (int *)&DAT_000001f8;
    if (plVar2 != (long *)0x0) {
      piVar3 = (int *)(*plVar2 + 0x1f8);
    }
  }
  nv_acquire_mmap_lock(plVar2);
  cVar1 = nv_get_all_mappings_revoked_locked(plVar2);
  if ((cVar1 != '\0') && (*piVar3 == 3)) {
    cVar1 = RmCanEnterGcxUnderGpuLock(param_1);
    if (cVar1 != '\0') {
      osQueueWorkItem(param_1,RmIndicateIdle,0,0);
      goto LAB_0025db13;
    }
  }
  if (*piVar3 == 3) {
    nv_dynamic_power_state_transition(plVar2,3,2);
  }
  RmScheduleCallbackForIdlePreConditionsUnderGpuLock(param_1);
LAB_0025db13:
  nv_release_mmap_lock(plVar2);
  return;
}


// ===== 0025db74 RmIndicateIdle.cold =====

void RmIndicateIdle_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025db80 RmIndicateIdle =====

void RmIndicateIdle(void)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined4 local_2c [3];
  
  lVar6 = gpumgrGetGpu();
  if ((lVar6 == 0) || (plVar1 = *(long **)(lVar6 + 0x4e0), plVar1 == (long *)0x0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar2 = *plVar1;
  portSyncMutexAcquire(*(undefined8 *)(lVar2 + 0x200));
  nv_acquire_mmap_lock(plVar1);
  cVar4 = nv_get_all_mappings_revoked_locked(plVar1);
  if ((cVar4 != '\0') && (*(int *)(lVar2 + 0x1f8) == 3)) {
    iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar6 + 0x7a4),0,0,0x4002);
    if (iVar5 == 0) {
      cVar4 = RmCanEnterGcxUnderGpuLock(lVar6);
      rmGpuGroupLockRelease(local_2c[0],0);
      if (cVar4 != '\0') {
        nv_set_safe_to_mmap_locked(plVar1,0);
        nv_dynamic_power_state_transition(plVar1,3,4);
        nv_indicate_idle(plVar1);
        goto LAB_0025dbf6;
      }
    }
  }
  iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar6 + 0x7a4),0,0,0x4002,local_2c);
  if (iVar5 == 0) {
    RmScheduleCallbackForIdlePreConditionsUnderGpuLock(lVar6);
    rmGpuGroupLockRelease(local_2c[0],0);
  }
LAB_0025dbf6:
  nv_release_mmap_lock(plVar1);
  portSyncMutexRelease(*(undefined8 *)(lVar2 + 0x200));
  return;
}


// ===== 0025dcb7 timerCallbackForIdlePreConditions.cold =====

void timerCallbackForIdlePreConditions_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025dcd0 timerCallbackForIdlePreConditions =====

void timerCallbackForIdlePreConditions(long param_1)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  
  if ((param_1 == 0) || (plVar2 = *(long **)(param_1 + 0x4e0), plVar2 == (long *)0x0)) {
    DAT_00000218 = 0;
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar3 = *plVar2;
  *(undefined1 *)(lVar3 + 0x218) = 0;
  if (*(int *)(lVar3 + 0x1f8) != 1) {
    cVar5 = RmCanEnterGcxUnderGpuLock();
    uVar1 = *(uint *)(lVar3 + 0x1f8);
    if (cVar5 == '\0') {
      if (uVar1 == 3) {
        nv_dynamic_power_state_transition(plVar2,3,2);
      }
    }
    else {
      if (uVar1 == 3) {
        if (*(long **)(param_1 + 0x4e0) == (long *)0x0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        lVar3 = **(long **)(param_1 + 0x4e0);
        if (*(char *)(lVar3 + 0x22a) == '\0') {
          iVar6 = osQueueWorkItem(param_1,RmHandleIdleSustained,0,0x100);
          if (iVar6 != 0) {
            nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0xb77,
                         "RmQueueIdleSustainedWorkitem",3,
                         "NVRM: Failed to queue RmHandleIdleSustained() workitem.\n");
            goto LAB_0025dd52;
          }
          *(undefined1 *)(lVar3 + 0x22a) = 1;
        }
        return;
      }
      if (uVar1 < 4) {
        if (uVar1 != 0) {
          if (uVar1 == 2) {
            nv_dynamic_power_state_transition(plVar2,2,3);
          }
          goto LAB_0025dd52;
        }
        nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0x633);
      }
      else if (uVar1 != 4) goto LAB_0025dd52;
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x636,"timerCallbackForIdlePreConditions"
                   ,4,"NVRM: unexpected dynamic power state 0x%x\n",*(undefined4 *)(lVar3 + 0x1f8));
    }
  }
LAB_0025dd52:
  RmScheduleCallbackForIdlePreConditionsUnderGpuLock(param_1);
  return;
}


// ===== 0025de60 rm_schedule_gpu_wakeup =====

void rm_schedule_gpu_wakeup(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_2 != (long *)0x0) && (uVar1 = 0, (undefined8 *)*param_2 != (undefined8 *)0x0)) {
    uVar1 = *(undefined8 *)*param_2;
  }
  osQueueWorkItem(uVar1,RmForceGpuNotIdle,0,0);
  return;
}


// ===== 0025de90 RmUpdateGc6ConsoleRefCount =====

void RmUpdateGc6ConsoleRefCount(long *param_1,char param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = 0;
  if (param_1 != (long *)0x0) {
    lVar2 = *param_1;
  }
  if (*(char *)((long)param_1 + 0x2fd) == '\0') {
    return;
  }
  portSyncMutexAcquire(*(undefined8 *)(lVar2 + 0x200));
  iVar1 = *(int *)(lVar2 + 0x1fc);
  if (param_2 == '\0') {
    if (iVar1 < 3) {
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x214,"RmUpdateGc6ConsoleRefCount",1,
                   "NVRM: %s: Unexpected dynamic power refcount value\n");
    }
    else {
      *(int *)(lVar2 + 0x1fc) = iVar1 + -1;
    }
  }
  else if (iVar1 < 2) {
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x202,"RmUpdateGc6ConsoleRefCount",1,
                 "NVRM: %s: Unexpected dynamic power refcount value\n");
  }
  else {
    *(int *)(lVar2 + 0x1fc) = iVar1 + 1;
  }
  portSyncMutexRelease(*(undefined8 *)(lVar2 + 0x200));
  return;
}


// ===== 0025df70 subdeviceCtrlCmdOsUnixAudioDynamicPower_IMPL =====

undefined8 subdeviceCtrlCmdOsUnixAudioDynamicPower_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x4e0);
  }
  nv_audio_dynamic_power(uVar2);
  return 0;
}


// ===== 0025df9b osClientGcoffDisallowRefcount.cold =====

void osClientGcoffDisallowRefcount_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025dfb0 osClientGcoffDisallowRefcount =====

void osClientGcoffDisallowRefcount(long *param_1,char param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *param_1;
  if (*(int *)(lVar1 + 0x1f0) == 0) {
    return;
  }
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x200));
  iVar3 = *(int *)(lVar1 + 0x22c) + -1;
  if (param_2 != '\0') {
    iVar3 = *(int *)(lVar1 + 0x22c) + 1;
  }
  *(int *)(lVar1 + 0x22c) = iVar3;
  portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x200));
  return;
}


// ===== 0025e016 subdeviceCtrlCmdOsUnixAllowDisallowGcoff_IMPL.cold =====

void subdeviceCtrlCmdOsUnixAllowDisallowGcoff_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025e030 subdeviceCtrlCmdOsUnixAllowDisallowGcoff_IMPL =====

undefined4 subdeviceCtrlCmdOsUnixAllowDisallowGcoff_IMPL(long param_1,int *param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*param_2 == 1) {
    if (*(char *)(param_1 + 0x6b5) == '\0') {
      nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0x2d2);
      return 0x1f;
    }
    *(undefined1 *)(param_1 + 0x6b5) = 0;
    plVar2 = *(long **)(lVar1 + 0x4e0);
    if (plVar2 == (long *)0x0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    lVar1 = *plVar2;
    uVar4 = 0;
    if (*(int *)(lVar1 + 0x1f0) != 0) {
      portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x200));
      *(int *)(lVar1 + 0x22c) = *(int *)(lVar1 + 0x22c) + -1;
      portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x200));
      return 0;
    }
  }
  else if (*param_2 == 2) {
    if (*(char *)(param_1 + 0x6b5) == '\0') {
      *(undefined1 *)(param_1 + 0x6b5) = 1;
      plVar2 = *(long **)(lVar1 + 0x4e0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar1 = *plVar2;
      uVar4 = 0;
      if (*(int *)(lVar1 + 0x1f0) != 0) {
        portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x200));
        *(int *)(lVar1 + 0x22c) = *(int *)(lVar1 + 0x22c) + 1;
        portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x200));
        return 0;
      }
    }
    else {
      nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0x2e0);
      uVar4 = 0x1f;
    }
  }
  else {
    uVar4 = 0x1f;
  }
  return uVar4;
}


// ===== 0025e170 rm_init_tegra_dynamic_power_management =====

void rm_init_tegra_dynamic_power_management(undefined8 param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_2 != (long *)0x0) {
    lVar1 = *param_2;
  }
  if (*(char *)((long)param_2 + 0x2b1) != '\0') {
    portMemSet(lVar1 + 0x1f0,0,0x50);
    *(undefined1 *)((long)param_2 + 0x2b2) = 0;
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x343,
                 "rm_init_tegra_dynamic_power_management",1,
                 "NVRM: NVRM: Tegra PCI iGPU detected, Rail-Gating is supported.\n");
    return;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x338,
               "rm_init_tegra_dynamic_power_management",1,
               "NVRM: NVRM: Tegra PCI iGPU Rail-Gating is not supported on this platform.\n");
  return;
}


// ===== 0025e210 rm_check_s0ix_regkey_and_platform_support =====

void rm_check_s0ix_regkey_and_platform_support(void)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int local_1c [3];
  
  lVar1 = g_pSys;
  cVar2 = nv_platform_supports_s0ix();
  if (cVar2 != '\0') {
    iVar3 = osReadRegistryDword(0,"EnableS0ixPowerManagement",local_1c);
    if (iVar3 == 0) {
      *(bool *)(lVar1 + 0x87) = local_1c[0] == 1;
      return;
    }
  }
  *(undefined1 *)(lVar1 + 0x87) = 0;
  return;
}


// ===== 0025e270 rm_init_dynamic_power_management =====

void rm_init_dynamic_power_management(undefined8 param_1,long *param_2,char param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  int iVar8;
  bool bVar9;
  uint local_40;
  int local_3c [3];
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *param_2;
  cVar4 = *(char *)((long)param_2 + 0x2b1);
  *(undefined4 *)(lVar1 + 0x238) = 0xffffffff;
  lVar6 = *param_2;
  iVar5 = osReadRegistryDword(0,"DynamicPowerManagement",local_3c);
  if (iVar5 == 0) {
    iVar8 = local_3c[0];
    if (local_3c[0] == 3) {
      if ((*(uint *)(lVar6 + 0x254) >> 0x14 & 0x3ff) < 0x172) {
LAB_0025e2fb:
        iVar8 = (uint)(*(char *)((long)param_2 + 0x2b1) != '\0') * 2;
      }
      else {
        cVar3 = nv_is_chassis_notebook();
        if (cVar3 == '\0') {
          cVar3 = nv_acpi_is_battery_present();
          if (cVar3 == '\0') goto LAB_0025e2fb;
          iVar8 = 2;
        }
        else {
          iVar8 = 2;
        }
      }
    }
    *(int *)(lVar1 + 0x238) = local_3c[0];
    *(char *)(lVar1 + 0x259) = param_3;
    cVar3 = nv_dynamic_power_available(param_2);
    if ((cVar3 != '\0') && (param_3 != '\0' || cVar4 != '\0')) goto LAB_0025e365;
  }
  else {
    *(char *)(lVar1 + 0x259) = param_3;
    nv_dynamic_power_available(param_2);
  }
  iVar8 = 0;
  nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x385,"rm_init_dynamic_power_management",2,
               "NVRM: %s: Disabling dynamic power management either due to lack of system support or due to error (%d) in reading regkey.\n"
               ,"rm_init_dynamic_power_management",iVar5);
LAB_0025e365:
  iVar5 = osReadRegistryDword(0,"DynamicPowerManagementVideoMemoryThreshold",&local_40);
  if ((iVar5 == 0) && (local_40 < 0x401)) {
    lVar6 = (ulong)local_40 << 0x14;
  }
  else {
    local_40 = 0x400;
    lVar6 = 0x40000000;
  }
  *(long *)(lVar1 + 0x230) = lVar6;
  uVar7 = portMemAllocatorGetGlobalNonPaged();
  lVar6 = portSyncMutexCreate(uVar7);
  *(long *)(lVar1 + 0x200) = lVar6;
  if (lVar6 == 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x3a2,"rm_init_dynamic_power_management",4,
                 "NVRM: %s: failed to create power mutex\n");
    *(undefined4 *)(lVar1 + 0x1f0) = 0;
  }
  else {
    if (iVar8 == 1) {
      *(undefined4 *)(lVar1 + 0x1f0) = 1;
    }
    else if (iVar8 == 2) {
      *(undefined4 *)(lVar1 + 0x1f0) = 2;
      if (*(int *)(lVar1 + 0x238) == 3) {
        if (cVar4 == '\0') {
          nv_allow_runtime_suspend(param_2);
        }
        else {
          cVar4 = nv_pci_tegra_pm_init();
          if (cVar4 != '\0') {
            nv_printf(0,"NVRM: Tegra PCI iGPU railgating is enabled\n");
            *(undefined1 *)((long)param_2 + 0x2b2) = 1;
            nv_allow_runtime_suspend(param_2);
          }
        }
      }
    }
    else {
      if (iVar8 != 0) {
        nv_printf(4,
                  "NVRM: Unknown DynamicPowerManagement value \'%u\' specified; disabling dynamic power management.\n"
                  ,iVar8);
      }
      *(undefined4 *)(lVar1 + 0x1f0) = 0;
    }
    *(undefined1 *)((long)param_2 + 700) = 0;
    nv_set_primary_vga_status(param_2);
    cVar4 = rm_get_uefi_console_status(param_2);
    bVar9 = true;
    if (cVar4 == '\0') {
      bVar9 = *(char *)((long)param_2 + 700) != '\0';
    }
    *(bool *)((long)param_2 + 0x2fd) = bVar9;
    *(undefined4 *)(lVar1 + 0x1fc) = 1;
    nv_dynamic_power_state_transition(param_2,0,1);
  }
  return;
}


// ===== 0025e587 rm_cleanup_dynamic_power_management.cold =====

void rm_cleanup_dynamic_power_management_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025e590 rm_cleanup_dynamic_power_management =====

void rm_cleanup_dynamic_power_management(undefined8 param_1,long *param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *param_2;
  if (((*(int *)(lVar1 + 0x1f0) == 2) && (*(int *)(lVar1 + 0x238) == 3)) ||
     (*(char *)((long)param_2 + 0x2b2) != '\0')) {
    nv_disallow_runtime_suspend(param_2);
    if (*(char *)((long)param_2 + 0x2b2) == '\0') goto LAB_0025e5c2;
    nv_pci_tegra_pm_deinit(param_2);
    *(undefined1 *)((long)param_2 + 0x2b2) = 0;
    nv_printf(0,"NVRM: Tegra PCI iGPU railgating is disabled\n");
    uVar4 = *(uint *)(lVar1 + 0x1f8);
    if (3 < uVar4) goto LAB_0025e670;
LAB_0025e5d3:
    if (uVar4 < 2) {
      if (uVar4 == 0) {
        nvAssertFailedNoLog(&DAT_00cc9db4,"arch/nvalloc/unix/src/dynamic-power.c",0x422);
      }
      goto LAB_0025e5f8;
    }
  }
  else {
LAB_0025e5c2:
    uVar4 = *(uint *)(lVar1 + 0x1f8);
    if (uVar4 < 4) goto LAB_0025e5d3;
LAB_0025e670:
    if (uVar4 != 4) goto LAB_0025e5f8;
    nv_indicate_not_idle(param_2);
    uVar4 = 4;
  }
  cVar3 = nv_dynamic_power_state_transition(param_2,uVar4,1);
  if (cVar3 != '\x01') {
    nvAssertFailedNoLog(&DAT_00cc9e51,"arch/nvalloc/unix/src/dynamic-power.c",0x41d);
  }
LAB_0025e5f8:
  if (*(long *)(lVar1 + 0x200) != 0) {
    portSyncMutexDestroy();
    *(undefined8 *)(lVar1 + 0x200) = 0;
  }
  return;
}


// ===== 0025e6b5 os_ref_dynamic_power.cold =====

void os_ref_dynamic_power_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025e6c0 os_ref_dynamic_power =====

int os_ref_dynamic_power(long *param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_1c;
  
  if ((param_1 == (long *)0x0) || (lVar1 = *param_1, lVar1 == 0)) {
    if (*(char *)((long)param_1 + 0x2fc) == '\0') {
      nvAssertFailedNoLog("nv->removed","arch/nvalloc/unix/src/dynamic-power.c",0x467);
    }
    return 0;
  }
  if (*(uint *)(lVar1 + 0x1f0) < param_2) {
    return 0;
  }
  portSyncMutexAcquire(*(undefined8 *)(lVar1 + 0x200));
  iVar5 = *(int *)(lVar1 + 0x1fc);
  *(int *)(lVar1 + 0x1fc) = iVar5 + 1;
  if (iVar5 < 0) {
    nvAssertFailedNoLog("ref >= 0","arch/nvalloc/unix/src/dynamic-power.c",0x474);
LAB_0025e798:
    uVar6 = *(uint *)(lVar1 + 0x1f8);
    if (uVar6 < 4) {
      if (uVar6 < 2) {
LAB_0025e898:
        nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x490,"os_ref_dynamic_power",4,
                     "NVRM: Unexpected dynamic power state 0x%x\n");
        goto LAB_0025e80a;
      }
    }
    else {
      if (uVar6 != 4) goto LAB_0025e898;
LAB_0025e80a:
      iVar5 = nv_indicate_not_idle(param_1);
      if (iVar5 != 0) {
        *(int *)(lVar1 + 0x1fc) = *(int *)(lVar1 + 0x1fc) + -1;
        goto LAB_0025e732;
      }
      if (*(char *)(lVar1 + 500) != '\0') {
        if ((long *)*param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        lVar2 = *(long *)*param_1;
        iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar2 + 0x7a4),0,0,0x4002,&local_1c);
        if (iVar5 == 0) {
          RmScheduleCallbackForIdlePreConditionsUnderGpuLock(lVar2);
          rmGpuGroupLockRelease(local_1c,0);
        }
      }
    }
    while (cVar4 = nv_dynamic_power_state_transition(param_1,uVar6,1), cVar4 == '\0') {
      uVar6 = *(uint *)(lVar1 + 0x1f8);
      if (1 < uVar6 - 2) {
        nvAssertFailedNoLog("old_state == NV_DYNAMIC_POWER_STATE_IDLE_INSTANT || old_state == NV_DYNAMIC_POWER_STATE_IDLE_SUSTAINED"
                            ,"arch/nvalloc/unix/src/dynamic-power.c",0x4a6);
      }
    }
  }
  else {
    if (iVar5 == 0) goto LAB_0025e798;
    if (*(int *)(lVar1 + 0x1f8) != 1) {
      nvAssertFailedNoLog("nvp->dynamic_power.state == NV_DYNAMIC_POWER_STATE_IN_USE",
                          "arch/nvalloc/unix/src/dynamic-power.c",0x478);
    }
  }
  iVar5 = 0;
LAB_0025e732:
  portSyncMutexRelease(*(undefined8 *)(lVar1 + 0x200));
  return iVar5;
}


// ===== 0025e8f0 rm_ref_dynamic_power =====

void rm_ref_dynamic_power(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  os_ref_dynamic_power(param_2,param_3);
  return;
}


// ===== 0025e900 os_unref_dynamic_power =====

void os_unref_dynamic_power(long *param_1,uint param_2)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  
  if ((param_1 == (long *)0x0) || (lVar2 = *param_1, lVar2 == 0)) {
    if (*(char *)((long)param_1 + 0x2fc) == '\0') {
      nvAssertFailedNoLog("nv->removed","arch/nvalloc/unix/src/dynamic-power.c",0x51f);
      return;
    }
  }
  else if (param_2 <= *(uint *)(lVar2 + 0x1f0)) {
    portSyncMutexAcquire(*(undefined8 *)(lVar2 + 0x200));
    piVar1 = (int *)(lVar2 + 0x1fc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      nvAssertFailedNoLog("ref >= 0","arch/nvalloc/unix/src/dynamic-power.c",0x52c);
    }
    else if (*piVar1 == 0) {
      if (*(int *)(lVar2 + 0x1f8) != 1) {
        nvAssertFailedNoLog("nvp->dynamic_power.state == NV_DYNAMIC_POWER_STATE_IN_USE",
                            "arch/nvalloc/unix/src/dynamic-power.c",0x53a);
      }
      if (*(char *)(lVar2 + 500) == '\0') {
        nv_indicate_idle(param_1);
        cVar3 = nv_dynamic_power_state_transition(param_1,1,4);
        if (cVar3 != '\x01') {
          nvAssertFailedNoLog(&DAT_00cc9e51,"arch/nvalloc/unix/src/dynamic-power.c",0x547);
        }
      }
      else {
        cVar3 = nv_dynamic_power_state_transition(param_1,1,2);
        if (cVar3 != '\x01') {
          nvAssertFailedNoLog(&DAT_00cc9e51,"arch/nvalloc/unix/src/dynamic-power.c",0x540);
        }
      }
    }
    portSyncMutexRelease(*(undefined8 *)(lVar2 + 0x200));
    return;
  }
  return;
}


// ===== 0025ea7d rm_enable_dynamic_power_management.cold =====

void rm_enable_dynamic_power_management_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025ea90 rm_enable_dynamic_power_management =====

void rm_enable_dynamic_power_management(undefined8 param_1,long *param_2)

{
  code *pcVar1;
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if ((*(int *)(*param_2 + 0x1f0) != 0) && (*(char *)((long)param_2 + 0x2fd) == '\0')) {
    os_unref_dynamic_power(param_2,1);
    return;
  }
  return;
}


// ===== 0025ead0 subdeviceCtrlCmdOsUnixGc6BlockerRefCnt_IMPL =====

undefined8 subdeviceCtrlCmdOsUnixGc6BlockerRefCnt_IMPL(long param_1,int *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*param_2 == 1) {
    uVar2 = os_ref_dynamic_power(*(undefined8 *)(lVar1 + 0x4e0),2);
    return uVar2;
  }
  if (*param_2 != 2) {
    return 0x1f;
  }
  os_unref_dynamic_power(*(undefined8 *)(lVar1 + 0x4e0),2);
  return 0;
}


// ===== 0025eb40 rm_unref_dynamic_power =====

void rm_unref_dynamic_power(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  os_unref_dynamic_power(param_2,param_3);
  return;
}


// ===== 0025eb50 osRefGpuAccessNeeded =====

void osRefGpuAccessNeeded(undefined8 param_1)

{
  os_ref_dynamic_power(param_1,2);
  return;
}


// ===== 0025eb60 osUnrefGpuAccessNeeded =====

void osUnrefGpuAccessNeeded(undefined8 param_1)

{
  os_unref_dynamic_power(param_1,2);
  return;
}


// ===== 0025eb70 osGetDynamicPowerSupportMask =====

undefined4 osGetDynamicPowerSupportMask(void)

{
  return dynamicPowerSupportGpuMask;
}


// ===== 0025eb7b RmDestroyDeferredDynamicPowerManagement.cold =====

void RmDestroyDeferredDynamicPowerManagement_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025eb90 RmDestroyDeferredDynamicPowerManagement =====

void RmDestroyDeferredDynamicPowerManagement(long *param_1)

{
  long lVar1;
  long lVar2;
  byte bVar3;
  code *pcVar4;
  undefined8 local_28 [2];
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  param_1 = (long *)*param_1;
  if (param_1 != (long *)0x0) {
    lVar1 = *param_1;
    if (*(char *)((long)param_1 + 0x229) == '\x01') {
      *(undefined4 *)(param_1 + 0x3e) = 2;
      *(undefined1 *)((long)param_1 + 0x229) = 0;
    }
    if ((char)param_1[0x45] == '\x01') {
      nv_indicate_idle();
      *(undefined1 *)(param_1 + 0x45) = 0;
    }
    if ((lVar1 != 0) && (*(long **)(lVar1 + 0x4e0) != (long *)0x0)) {
      lVar2 = **(long **)(lVar1 + 0x4e0);
      if (*(long *)(lVar2 + 0x208) != 0) {
        portMemSet(local_28,0,0x10);
        local_28[0] = *(undefined8 *)(lVar2 + 0x208);
        tmrCtrlCmdEventCancel(lVar1,local_28);
      }
      if (*(long *)(lVar2 + 0x210) != 0) {
        portMemSet(local_28,0,0x10);
        local_28[0] = *(undefined8 *)(lVar2 + 0x210);
        tmrCtrlCmdEventCancel(lVar1,local_28);
      }
      RmCancelCallbackToRemoveIdleHoldoff(lVar1);
      *(undefined1 *)(lVar2 + 0x218) = 0;
      if (*(long **)(lVar1 + 0x4e0) != (long *)0x0) {
        lVar2 = **(long **)(lVar1 + 0x4e0);
        if (*(long *)(lVar2 + 0x208) != 0) {
          portMemSet(local_28,0,0x10);
          local_28[0] = *(undefined8 *)(lVar2 + 0x208);
          tmrCtrlCmdEventDestroy(lVar1,local_28);
          *(undefined8 *)(lVar2 + 0x208) = 0;
        }
        if (*(long *)(lVar2 + 0x210) != 0) {
          portMemSet(local_28,0,0x10);
          local_28[0] = *(undefined8 *)(lVar2 + 0x210);
          tmrCtrlCmdEventDestroy(lVar1,local_28);
          *(undefined8 *)(lVar2 + 0x210) = 0;
        }
        if (*(long *)(lVar2 + 0x220) != 0) {
          portMemSet(local_28,0,0x10);
          local_28[0] = *(undefined8 *)(lVar2 + 0x220);
          tmrCtrlCmdEventDestroy(lVar1,local_28);
          *(undefined8 *)(lVar2 + 0x220) = 0;
        }
        *(undefined1 *)(lVar2 + 500) = 0;
        bVar3 = (byte)*(undefined4 *)(lVar1 + 0x7a4) & 0x1f;
        dynamicPowerSupportGpuMask =
             dynamicPowerSupportGpuMask & (-2 << bVar3 | 0xfffffffeU >> 0x20 - bVar3);
        return;
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 0025edb0 RmGcxPowerManagement =====

ulong RmGcxPowerManagement(long param_1,char param_2,char param_3,undefined1 *param_4)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong local_40;
  undefined8 local_38;
  undefined1 local_30;
  undefined1 local_2e;
  
  lVar7 = 0;
  plVar1 = *(long **)(param_1 + 0x4e0);
  lVar2 = *(long *)(param_1 + 0x1b70);
  if (plVar1 != (long *)0x0) {
    lVar7 = *plVar1;
  }
  if ((*(char *)(param_1 + 0x226e) != '\0') && (*(char *)(param_1 + 0x485) == '\0')) {
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x944,"RmGcxPowerManagement",1,
                 "NVRM: AML overrides present in Desktop");
  }
  *(undefined1 *)((long)plVar1 + 0x301) = 0;
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 0x494) != '\0') {
      uVar6 = RmPowerManagement(param_1,2);
      *(undefined1 *)(param_1 + 0x494) = 0;
      *(undefined1 *)(lVar2 + 0x2a0) = 0;
      return uVar6;
    }
    if (*(char *)(param_1 + 0x496) != '\0') {
      uVar6 = RmPowerManagement(param_1,2);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      *(undefined1 *)(param_1 + 0x496) = 0;
      return uVar6;
    }
    portMemSet(&local_38,0,8);
    local_38._0_6_ = CONCAT15(1,(undefined5)local_38);
    local_38 = local_38 & 0xffffffff00000000;
    uVar6 = gpuGc6Exit_IMPL(param_1,&local_38);
    return uVar6;
  }
  local_40 = 0;
  lVar3 = *(long *)(param_1 + 0x1b78);
  cVar4 = '\0';
  if (((*(char *)(param_1 + 0x487) != '\0') && (cVar4 = '\0', *(char *)(lVar7 + 600) != '\0')) &&
     (cVar4 = '\x01', param_3 == '\0')) {
    cVar4 = nv_s2idle_pm_configured();
  }
  if (*(char *)(param_1 + 0x45d) != '\0') {
    *(undefined1 *)(param_1 + 0x495) = 1;
    uVar6 = RmPowerManagement(param_1,1);
    *(undefined1 *)(param_1 + 0x495) = 0;
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    *(undefined1 *)(param_1 + 0x496) = 1;
    return uVar6;
  }
  iVar5 = memmgrGetUsedRamSize_IMPL(param_1,lVar3,&local_40);
  if (iVar5 == 0) {
    if (cVar4 == '\0') {
      uVar6 = fbsrReserveSysMemoryForPowerMgmt_IMPL(param_1,*(undefined8 *)(lVar3 + 0xbd0));
      if ((int)uVar6 != 0) {
        if (param_3 != '\0') {
          if ((int)uVar6 != 0x51) {
            return uVar6;
          }
          *param_4 = 1;
          return uVar6;
        }
        goto LAB_0025f06c;
      }
    }
    else {
      lVar7 = 0;
      if (*(long **)(param_1 + 0x4e0) != (long *)0x0) {
        lVar7 = **(long **)(param_1 + 0x4e0);
      }
      if (param_3 == '\0') {
        uVar6 = *(ulong *)(lVar7 + 0x248);
      }
      else {
        if (*(int *)(lVar7 + 0x22c) != 0) goto LAB_0025f0a0;
        uVar6 = *(ulong *)(lVar7 + 0x230);
      }
      if (((uVar6 == 0) || (uVar6 < local_40)) ||
         (iVar5 = fbsrReserveSysMemoryForPowerMgmt_IMPL(param_1,*(undefined8 *)(lVar3 + 0xbd0)),
         iVar5 != 0)) goto LAB_0025f0a0;
    }
    *(undefined1 *)(param_1 + 0x493) = 1;
    if (*(char *)(lVar3 + 0xd34) == '\0') {
      *(undefined1 *)(lVar2 + 0x2a0) = 1;
    }
    uVar6 = RmPowerManagement(param_1,1);
    *(undefined1 *)(param_1 + 0x493) = 0;
    if ((int)uVar6 == 0) {
      *(undefined1 *)(param_1 + 0x494) = 1;
    }
    else {
      fbsrFreeReservedSysMemoryForPowerMgmt_IMPL(*(undefined8 *)(lVar3 + 0xbd0));
      uVar6 = uVar6 & 0xffffffff;
      *(undefined1 *)(lVar2 + 0x2a0) = 0;
    }
  }
  else {
    if (cVar4 == '\0') {
      if (param_3 != '\0') {
        return 0xffff;
      }
LAB_0025f06c:
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x9ca,"RmGcxPowerManagement",4,
                   "NVRM: System suspend failed with current system suspend configuration. Please change the system suspend configuration to s2idle in /sys/power/mem_sleep.\n"
                  );
      return 0x56;
    }
LAB_0025f0a0:
    portMemSet(&local_38,0,0xc);
    local_2e = param_3 == '\0';
    local_38 = 0x200000000;
    local_30 = 1;
    uVar6 = gpuGc6Entry_IMPL(param_1,&local_38);
    if (((int)uVar6 == 0) && ((*(byte *)(plVar1 + 2) & 0x80) != 0)) {
      *(undefined1 *)((long)plVar1 + 0x301) = 1;
    }
  }
  return uVar6;
}


// ===== 0025f1a0 rm_power_management =====

int rm_power_management(undefined8 param_1,long *param_2,int param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined1 local_c9;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0x80);
  bVar6 = param_3 != 2;
  iVar4 = os_flush_work_queue(param_2[0x5e],bVar6);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"os_flush_work_queue(pNv->queue, pmAction != NV_PM_ACTION_RESUME)",
               "arch/nvalloc/unix/src/dynamic-power.c",0x9fd);
  }
  if (((char)param_2[0x69] != '\0') && (*(char *)((long)param_2 + 0x349) == '\0')) {
    os_disable_console_access();
  }
  iVar4 = rmapiLockAcquire(0,0x4002);
  if (iVar4 != 0) goto LAB_0025f2e5;
  if ((((long *)*param_2 != (long *)0x0) && (lVar2 = *(long *)*param_2, lVar2 != 0)) &&
     (iVar4 = os_ref_dynamic_power(param_2,2), iVar4 == 0)) {
    iVar4 = rmGpuLocksAcquire(0,0x4002);
    if (iVar4 == 0) {
      if (*(char *)(lVar2 + 0x45a) == '\0') {
        lVar3 = *param_2;
        if (param_3 == 2) {
          if ((*(char *)(lVar3 + 0x241) != '\0') && (*(char *)(lVar3 + 0x1e0) == '\0'))
          goto LAB_0025f3e3;
        }
        else {
          if (*(char *)(lVar3 + 0x228) == '\x01') {
            nv_indicate_idle(param_2);
            RmCancelCallbackToRemoveIdleHoldoff(lVar2);
            cVar1 = *(char *)(lVar3 + 0x241);
            *(undefined1 *)(lVar3 + 0x228) = 0;
          }
          else {
            cVar1 = *(char *)(lVar3 + 0x241);
          }
          if ((cVar1 != '\0') && (param_3 == 1)) {
LAB_0025f3e3:
            iVar4 = RmGcxPowerManagement(lVar2,param_3 == 1,0,&local_c9);
            goto LAB_0025f2c6;
          }
        }
        iVar4 = RmPowerManagement(lVar2,param_3);
      }
      else {
        iVar4 = RmPowerManagementTegra(lVar2,param_3);
        if ((iVar4 != 0) && (bVar6)) {
          RmPowerManagementTegra(lVar2,2);
        }
      }
LAB_0025f2c6:
      rmGpuLocksRelease(0,0);
    }
    os_unref_dynamic_power(param_2,2);
  }
  rmapiLockRelease();
LAB_0025f2e5:
  if (((char)param_2[0x69] != '\0') && (*(char *)((long)param_2 + 0x349) == '\0')) {
    os_enable_console_access();
  }
  iVar5 = os_flush_work_queue(param_2[0x5e],bVar6);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"os_flush_work_queue(pNv->queue, pmAction != NV_PM_ACTION_RESUME)",
               "arch/nvalloc/unix/src/dynamic-power.c",0xa5d);
  }
  threadStateFree(local_c8,0);
  return iVar4;
}


// ===== 0025f460 rm_transition_dynamic_power =====

int rm_transition_dynamic_power(undefined8 param_1,long *param_2,char param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_d0;
  long local_c8;
  char local_bc;
  
  lVar2 = 0;
  if ((param_2 != (long *)0x0) && (lVar2 = 0, (long *)*param_2 != (long *)0x0)) {
    lVar2 = *(long *)*param_2;
  }
  if ((*(byte *)(param_2 + 2) & 0x10) != 0) {
    return 0;
  }
  threadStateInit(&local_c8,0);
  if (((param_3 == '\0' && local_bc == '\0') && (local_c8 == 0)) &&
     (*(char *)(lVar2 + 0x45d) != '\0')) {
    threadStateResetTimeout(lVar2);
  }
  if (((char)param_2[0x69] != '\0') && (*(char *)((long)param_2 + 0x349) == '\0')) {
    os_disable_console_access();
  }
  iVar1 = rmGpuLocksAcquire(0,0x4002);
  if (iVar1 == 0) {
    rmapiEnterRtd3PmPath();
    local_d0 = 0;
    if (lVar2 != 0) {
      local_d0 = *(undefined8 *)(lVar2 + 0x4e0);
    }
    iVar1 = RmGcxPowerManagement(lVar2,param_3,1,param_4);
    if ((param_3 == '\0') && (iVar1 == 0)) {
      nv_idle_holdoff(local_d0);
      RmScheduleCallbackToRemoveIdleHoldoff(lVar2);
    }
    rmapiLeaveRtd3PmPath();
    rmGpuLocksRelease(0,0);
  }
  if (((char)param_2[0x69] != '\0') && (*(char *)((long)param_2 + 0x349) == '\0')) {
    os_enable_console_access();
  }
  threadStateFree(&local_c8,0);
  return iVar1;
}


// ===== 0025f5ea RmHandleDisplayChange.cold =====

void RmHandleDisplayChange_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  
  portMemSet(unaff_RBP + -0x18,0,8);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025f610 RmHandleDisplayChange =====

void RmHandleDisplayChange(undefined8 param_1,long *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_24;
  undefined1 local_20 [8];
  
  if ((((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) ||
      (lVar1 = *(long *)*param_2, lVar1 == 0)) ||
     ((*(int *)(lVar1 + 0x4b34) != 3 && (*(char *)(lVar1 + 0x494) == '\0')))) {
    return;
  }
  iVar3 = os_ref_dynamic_power(param_2,2);
  if (iVar3 != 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0xb0a,"RmHandleDisplayChange",4,
                 "NVRM: Failed to increment dynamic power refcount\n");
    return;
  }
  if ((long *)*param_2 != (long *)0x0) {
    lVar1 = *(long *)*param_2;
    portMemSet(local_20,0,8);
    iVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),0,0,0x40000,&local_24);
    if (iVar3 == 0) {
      gpuNotifySubDeviceEvent_IMPL(lVar1,1,local_20,8,0,0);
      rmGpuGroupLockRelease(local_24,0);
    }
    os_unref_dynamic_power(param_2,2);
    return;
  }
  portMemSet(local_20,0,8);
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0025f726 RmInitPowerManagement.cold =====

void RmInitPowerManagement_cold(void)

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
  rmapiGetInterface(4);
  *(undefined8 *)(unaff_RBP + -0x50) = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025f750 RmInitPowerManagement =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmInitPowerManagement(long *param_1)

{
  char cVar1;
  undefined4 uVar2;
  long *plVar3;
  code *pcVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  undefined8 extraout_RDX_05;
  undefined8 extraout_RDX_06;
  undefined8 extraout_RDX_07;
  undefined8 extraout_RDX_08;
  undefined8 extraout_RDX_09;
  undefined8 uVar10;
  char *pcVar11;
  long lVar12;
  long *plVar13;
  ulong local_58;
  code *local_50;
  long local_48;
  undefined4 local_40;
  
  iVar7 = rmGpuLocksAcquire(0,0x400000);
  if (iVar7 != 0) {
    return;
  }
  if ((param_1 == (long *)0x0) || (plVar3 = (long *)*param_1, plVar3 == (long *)0x0)) {
    rmapiGetInterface(4);
    local_58 = 0;
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar12 = *plVar3;
  lVar8 = rmapiGetInterface(4);
  local_58 = 0;
  if (*(char *)(lVar12 + 0x48f) == '\0') {
    pcVar11 = "NVRM: RTD3 is not supported for this arch\n";
    uVar10 = 0x81e;
LAB_0025f978:
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",uVar10,"RmCheckRtd3GcxSupport",2,pcVar11);
    plVar3 = (long *)*param_1;
    lVar12 = *plVar3;
    iVar7 = (int)plVar3[0x3e];
    uVar10 = extraout_RDX_02;
  }
  else {
    cVar5 = *(char *)(lVar12 + 0x487);
    if ((char)plVar3[0x48] == '\0') {
      if (cVar5 == '\0' && *(char *)(lVar12 + 0x492) == '\0') goto LAB_0025f8c8;
LAB_0025f7f0:
      iVar7 = (**(code **)(lVar8 + 0x38))
                        (lVar8,(int)param_1[0x62],*(undefined4 *)((long)param_1 + 0x314),0x800289,
                         &local_58,8);
      if (iVar7 == 0) {
        if (1 < (uint)local_58) {
          pcVar11 = "NVRM: RTD3 is not supported on VM\n";
          uVar10 = 0x841;
          goto LAB_0025f978;
        }
        if ((*(char *)((long)plVar3 + 0x259) == '\0') && (*(char *)(lVar12 + 0x45d) == '\0')) {
          nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x848,"RmCheckRtd3GcxSupport",2,
                       "NVRM: RTD3 ACPI support is not available.\n");
          plVar3 = (long *)*param_1;
          lVar12 = *plVar3;
          iVar7 = (int)plVar3[0x3e];
          uVar10 = extraout_RDX_09;
          goto joined_r0x0025f993;
        }
        plVar3 = (long *)*param_1;
        lVar12 = *plVar3;
        if ((int)plVar3[0x3e] == 2) {
          uVar2 = *(undefined4 *)(lVar12 + 0x7a4);
          *(undefined1 *)((long)plVar3 + 0x229) = 0;
          dynamicPowerSupportGpuMask = dynamicPowerSupportGpuMask | 1 << ((byte)uVar2 & 0x1f);
          uVar9 = 0x208;
          lVar8 = 0;
          if (*(long **)(lVar12 + 0x4e0) != (long *)0x0) {
            lVar8 = **(long **)(lVar12 + 0x4e0);
            uVar9 = lVar8 + 0x208;
          }
          portMemSet(&local_58,0,0x20);
          local_50 = timerCallbackForIdlePreConditions;
          local_40 = 8;
          local_58 = uVar9;
          local_48 = lVar12;
          iVar7 = tmrCtrlCmdEventCreate(lVar12,&local_58);
          if (iVar7 == 0) {
            portMemSet(&local_58,0,0x20);
            local_58 = lVar8 + 0x210;
            local_50 = timerCallbackToIndicateIdle;
            local_40 = 8;
            local_48 = lVar12;
            iVar7 = tmrCtrlCmdEventCreate(lVar12,&local_58);
            if (iVar7 != 0) {
              nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x742,
                           "CreateDynamicPowerCallbacks",4,
                           "NVRM: Error creating callback to indicate GPU idle\n");
              goto LAB_0025fb56;
            }
            portMemSet(&local_58,0,0x20);
            local_58 = lVar8 + 0x220;
            local_50 = timerCallbackToRemoveIdleHoldoff;
            local_40 = 8;
            local_48 = lVar12;
            iVar7 = tmrCtrlCmdEventCreate(lVar12,&local_58);
            if (iVar7 != 0) {
              nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x756,
                           "CreateDynamicPowerCallbacks",4,
                           "NVRM: Error creating callback to decrease kernel refcount\n");
              goto LAB_0025fb56;
            }
            RmScheduleCallbackForIdlePreConditionsUnderGpuLock(lVar12);
            *(undefined1 *)((long)plVar3 + 500) = 1;
            *(undefined4 *)((long)plVar3 + 0x22c) = 0;
            plVar13 = (long *)*param_1;
            cVar1 = (char)plVar13[0x48];
            uVar10 = extraout_RDX_03;
          }
          else {
            nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x72e,"CreateDynamicPowerCallbacks"
                         ,4,"NVRM: Error creating dynamic power precondition check callback\n");
LAB_0025fb56:
            *(undefined8 *)(lVar8 + 0x208) = 0;
            *(undefined8 *)(lVar8 + 0x210) = 0;
            *(undefined8 *)(lVar8 + 0x220) = 0;
            nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x876,
                         "RmInitDeferredDynamicPowerManagement",4,
                         "NVRM: Failed to register for dynamic power callbacks\n");
            plVar13 = (long *)*param_1;
            cVar1 = (char)plVar13[0x48];
            uVar10 = extraout_RDX_04;
          }
          if (cVar1 != '\0') {
            if (cVar5 == '\0') goto LAB_0025f995;
            goto LAB_0025f87a;
          }
LAB_0025fbb4:
          if (cVar5 == '\0') goto LAB_0025f995;
        }
        else {
          uVar10 = extraout_RDX;
          if (((char)plVar3[0x48] == '\0') || (plVar13 = plVar3, cVar5 == '\0')) goto LAB_0025fbb4;
LAB_0025f87a:
          cVar5 = nv_platform_supports_s0ix();
          uVar10 = extraout_RDX_00;
          if ((cVar5 != '\0') &&
             ((iVar7 = osReadRegistryDword(0,"EnableS0ixPowerManagement",&local_58),
              uVar10 = extraout_RDX_07, iVar7 == 0 && ((uint)local_58 == 1)))) {
            *(undefined1 *)((long)plVar13 + 0x241) = 1;
            iVar7 = osReadRegistryDword(0,"S0ixPowerManagementVideoMemoryThreshold",&local_58);
            uVar10 = extraout_RDX_08;
            if (iVar7 == 0) {
              plVar13[0x49] = (local_58 & 0xffffffff) << 0x14;
            }
          }
        }
        if ((*(char *)((long)plVar3 + 0x241) != '\0') || ((int)plVar3[0x3e] == 2)) {
          uVar6 = RmConfigureUpstreamPortForRTD3(param_1,1);
          *(undefined1 *)(plVar3 + 0x4b) = uVar6;
          uVar10 = extraout_RDX_05;
        }
        goto LAB_0025f995;
      }
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x838,"RmCheckRtd3GcxSupport",4,
                   "NVRM: Failed to get Virtualization mode, status=0x%x\n",iVar7);
      plVar3 = (long *)*param_1;
      lVar12 = *plVar3;
      iVar7 = (int)plVar3[0x3e];
      uVar10 = extraout_RDX_06;
    }
    else {
      if (cVar5 != '\0') goto LAB_0025f7f0;
LAB_0025f8c8:
      if (*(char *)(lVar12 + 0x45d) != '\0') goto LAB_0025f7f0;
      uVar10 = 0;
      nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x82a,"RmCheckRtd3GcxSupport",2,
                   "NVRM: Disabling RTD3. [GC6 support=%d GCOFF support=%d RG support=%d]\n",0,0,0);
      plVar3 = (long *)*param_1;
      lVar12 = *plVar3;
      iVar7 = (int)plVar3[0x3e];
    }
  }
joined_r0x0025f993:
  if (iVar7 == 2) {
    *(undefined4 *)(plVar3 + 0x3e) = 0;
    *(undefined1 *)((long)plVar3 + 0x229) = 1;
    nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x865,
                 "RmInitDeferredDynamicPowerManagement",2,"NVRM: RTD3 is not supported.\n");
    uVar10 = extraout_RDX_01;
  }
LAB_0025f995:
  *(undefined1 *)((long)param_1 + 0x399) = *(undefined1 *)(lVar12 + 0x474);
  rmGpuLocksRelease(0,0,uVar10);
  return;
}


// ===== 0025fd5a RmDestroyPowerManagement.cold =====

void RmDestroyPowerManagement_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025fd70 RmDestroyPowerManagement =====

void RmDestroyPowerManagement(long *param_1)

{
  code *pcVar1;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (*(char *)(*param_1 + 600) == '\0') {
    RmDestroyDeferredDynamicPowerManagement();
    return;
  }
  RmConfigureUpstreamPortForRTD3(param_1,0);
  RmDestroyDeferredDynamicPowerManagement(param_1);
  return;
}


// ===== 0025fdad rm_get_power_info.cold =====

void rm_get_power_info_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0025fdc0 rm_get_power_info =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rm_get_power_info(undefined8 param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *local_e8;
  char *local_e0;
  undefined4 local_d4;
  long local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar3 = rmapiLockAcquire(0,0x4002);
  if (iVar3 == 0) {
    if ((((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) ||
        (lVar4 = *(long *)*param_2, lVar4 == 0)) ||
       (iVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar4 + 0x7a4),0,0,0x4002,&local_d4),
       iVar3 != 0)) {
      pcVar8 = "?";
      local_e8 = "?";
      pcVar5 = "?";
      pcVar7 = "?";
      pcVar6 = "?";
      local_e0 = "?";
    }
    else {
      lVar1 = *param_2;
      pcVar6 = "Active";
      pcVar5 = "Enabled (fine-grained)";
      if (*(char *)(lVar4 + 0x494) != '\0') {
        pcVar6 = "Off";
      }
      iVar3 = *(int *)(lVar1 + 0x1f0);
      if (((iVar3 != 2) && (pcVar5 = "Enabled (coarse-grained)", iVar3 != 1)) &&
         (pcVar5 = "Not supported", iVar3 == 0)) {
        pcVar5 = "Disabled";
        if ((*(int *)(lVar1 + 0x238) != 0) &&
           (pcVar5 = "Disabled by default", *(int *)(lVar1 + 0x238) != 3)) {
          pcVar5 = "Not supported";
        }
      }
      if (*(char *)(lVar4 + 0x48f) == '\0') {
        local_e0 = "Not Supported";
        pcVar7 = "Not Supported";
      }
      else {
        local_e0 = "Supported";
        if (*(char *)(lVar4 + 0x487) == '\0') {
          local_e0 = "Not Supported";
        }
        pcVar7 = "Supported";
        if ((*(char *)(lVar4 + 0x492) == '\0') && (*(char *)(lVar4 + 0x491) == '\0')) {
          pcVar7 = "Not Supported";
        }
      }
      local_e8 = "Enabled";
      if (*(char *)(lVar1 + 0x241) == '\0') {
        local_e8 = "Disabled";
      }
      iVar3 = *(int *)(lVar1 + 0x244);
      if (iVar3 == -1) {
        lVar4 = rmapiGetInterface(4);
        iVar3 = os_alloc_mem(&local_d0,0x374);
        if (iVar3 == 0) {
          if ((long *)*param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)invalidInstructionException();
            (*pcVar2)();
          }
          *(undefined4 *)(local_d0 + 4) = *(undefined4 *)(*(long *)*param_2 + 0x7ac);
          *(undefined4 *)(local_d0 + 0x10) = 2;
          iVar3 = (**(code **)(lVar4 + 0x38))
                            (lVar4,(int)param_2[0x62],(int)param_2[0x62],0x13b,local_d0,0x374);
          if (iVar3 == 0) {
            os_free_mem(local_d0);
            pcVar8 = "Supported";
            *(undefined4 *)(lVar1 + 0x244) = 1;
          }
          else {
            os_free_mem(local_d0);
            pcVar8 = "Not Supported";
            *(uint *)(lVar1 + 0x244) = -(uint)(iVar3 != 0x56);
            if (iVar3 != 0x56) {
              pcVar8 = "?";
            }
          }
        }
        else {
          pcVar8 = "?";
          nvDbg_Printf("arch/nvalloc/unix/src/dynamic-power.c",0x4cb,"os_get_dynamic_boost_support",
                       4,"NVRM: Failed to allocate memory\n");
          *(undefined4 *)(lVar1 + 0x244) = 0xffffffff;
        }
      }
      else {
        pcVar8 = "Not Supported";
        if ((iVar3 != 0) && (pcVar8 = "Supported", iVar3 != 1)) {
          pcVar8 = "?";
        }
      }
      rmGpuGroupLockRelease(local_d4,0);
    }
    rmapiLockRelease();
  }
  else {
    pcVar8 = "?";
    local_e8 = "?";
    pcVar5 = "?";
    pcVar7 = "?";
    pcVar6 = "?";
    local_e0 = "?";
  }
  threadStateFree(local_c8,0);
  *param_3 = pcVar6;
  param_3[1] = pcVar5;
  param_3[2] = local_e0;
  param_3[3] = pcVar7;
  param_3[4] = local_e8;
  param_3[5] = pcVar8;
  return;
}


// ===== 00260160 RmCreateOsDescriptor =====

void RmCreateOsDescriptor(long param_1)

{
  long lVar1;
  ulong uVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 local_38;
  undefined8 local_30 [2];
  
  uVar2 = *(ulong *)(param_1 + 0x40);
  local_38 = 0;
  local_30[0] = 0;
  if ((~os_page_mask & uVar2) == 0) {
    if (*(ulong *)(param_1 + 0x48) != 0xffffffffffffffff) {
      lVar1 = *(ulong *)(param_1 + 0x48) / os_page_size + 1;
      bVar3 = *(byte *)(param_1 + 0x3a) >> 6 & 1 ^ 1;
      iVar4 = os_lock_user_pages(uVar2,lVar1,local_30,bVar3);
      if (iVar4 == 0) {
        uVar5 = 1;
        uVar6 = local_30[0];
      }
      else {
        if ((iVar4 != 0x1e) || (iVar4 = os_lookup_user_io_memory(uVar2,lVar1,&local_38), iVar4 != 0)
           ) goto LAB_00260235;
        uVar5 = 2;
        uVar6 = local_38;
      }
      *(undefined4 *)(param_1 + 0x50) = uVar5;
      *(undefined8 *)(param_1 + 0x40) = uVar6;
      Nv04VidHeapControlWithSecInfo(param_1);
      if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x50) == 1)) {
        os_unlock_user_pages(lVar1,local_30[0],bVar3);
        return;
      }
      return;
    }
    iVar4 = 0x2e;
  }
  else {
    iVar4 = 0x56;
  }
LAB_00260235:
  *(int *)(param_1 + 0x14) = iVar4;
  return;
}


// ===== 002602a0 RmValidateIoctl =====

undefined8 RmValidateIoctl(byte param_1,uint param_2)

{
  ulong uVar1;
  
  uVar1 = 0;
  if (param_1 == 0x2b) {
    if ((param_2 & 0xffffffef) == 0x20) {
      return 0;
    }
    nv_printf(4,"NVRM: invalid %d structure size!\n",0x2b);
  }
  else {
    while ((&RmIoctlsTable_2)[uVar1 * 2] != (uint)param_1) {
      uVar1 = uVar1 + 1;
      if (uVar1 == 0x14) {
        return 0x24;
      }
    }
    if ((&DAT_00ccabc4)[(uVar1 & 0xffffffff) * 2] == param_2) {
      return 0;
    }
    nv_printf(4,"NVRM: invalid %d structure size, expected %d, got %d!\n",param_1,
              (&DAT_00ccabc4)[(uVar1 & 0xffffffff) * 2],param_2);
  }
  return 0x1f;
}


// ===== 00260340 RmIoctl =====

ulong RmIoctl(long param_1,long param_2,uint param_3,int *param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  int *piVar10;
  undefined4 uVar11;
  uint uVar12;
  ulong uVar13;
  bool bVar14;
  long local_90;
  long local_88;
  uint local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined8 local_60;
  long *local_58;
  ulong local_50;
  undefined8 local_48;
  char *local_40;
  
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  local_6c = 0;
  uStack_68 = 0;
  local_64 = 0;
  cVar5 = osIsAdministrator();
  uVar4 = local_6c;
  uVar11 = uStack_70;
  lVar9 = *(long *)(param_2 + 0x58);
  if (*(long *)(param_2 + 0x58) == 0) {
    lVar9 = param_2;
  }
  if (param_3 == 0x4d) {
    if (param_5 != 0x48) {
      return 0x1f;
    }
    if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
      iVar7 = rm_access_registry(*param_4,param_4[1],param_4[2],*(undefined8 *)(param_4 + 4),
                                 param_4[3],*(undefined8 *)(param_4 + 8),param_4[6],
                                 *(undefined8 *)(param_4 + 0xc),param_4 + 10,param_4 + 0xe,
                                 param_4 + 0xf);
      param_4[0x10] = iVar7;
      return 0;
    }
    return 0x1f;
  }
  local_80 = (uint)(cVar5 != '\0');
  uStack_70 = (undefined4)lVar9;
  local_6c = (undefined4)((ulong)lVar9 >> 0x20);
  if (0x4d < param_3) {
    if (param_3 == 0x59) {
      if (param_5 != 0x10) {
        return 0x1f;
      }
      if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
        return 0x1f;
      }
      uStack_70 = uVar11;
      local_6c = uVar4;
      Nv04BindContextDmaWithSecInfo(param_4);
      return 0;
    }
    if (param_3 < 0x5a) {
      if (param_3 == 0x54) {
        if (param_5 != 0x38) {
          return 0x1f;
        }
        if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
          return 0x1f;
        }
        uStack_70 = uVar11;
        local_6c = uVar4;
        Nv04AllocContextDmaWithSecInfo(param_4);
        return 0;
      }
      if (param_3 < 0x55) {
        if (param_3 == 0x4e) {
          if (param_5 != 0x38) {
            return 0x1f;
          }
          if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
            return 0x1f;
          }
          param_4[0xb] = param_4[0xb] & 0xfc7fffffU | 0x3000000;
          Nv04MapMemoryWithSecInfo(param_4);
          if (param_4[10] != 0) {
            return 0;
          }
          uVar13 = (ulong)(uint)param_4[0xc];
          iVar7 = rm_create_mmap_context
                            (*param_4,param_4[1],param_4[2],*(undefined8 *)(param_4 + 8),
                             *(undefined8 *)(param_4 + 6),*(undefined8 *)(param_4 + 4),
                             (uint)param_4[0xb] >> 0x17 & 7);
          param_4[10] = iVar7;
          if (iVar7 != 0) {
            portMemSet(&local_60,0,0x20,uVar13);
            local_60 = *(undefined8 *)param_4;
            local_58 = (long *)CONCAT44(local_58._4_4_,param_4[2]);
            local_50 = *(ulong *)(param_4 + 8);
            local_48 = CONCAT44(param_4[0xb],(undefined4)local_48);
            Nv04UnmapMemoryWithSecInfo(&local_60);
            return 0;
          }
          return 0;
        }
        if (param_3 == 0x4f) {
          if (param_5 != 0x20) {
            return 0x1f;
          }
          if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
            uStack_70 = uVar11;
            local_6c = uVar4;
            Nv04UnmapMemoryWithSecInfo(param_4);
            return 0;
          }
          return 0x1f;
        }
      }
      else {
        if (param_3 == 0x57) {
          if (param_5 != 0x40) {
            return 0x1f;
          }
          if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
            uStack_70 = uVar11;
            local_6c = uVar4;
            Nv04MapMemoryDmaWithSecInfo(param_4);
            return 0;
          }
          return 0x1f;
        }
        if (param_3 == 0x58) {
          if (param_5 != 0x30) {
            return 0x1f;
          }
          if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
            uStack_70 = uVar11;
            local_6c = uVar4;
            Nv04UnmapMemoryDmaWithSecInfo(param_4);
            return 0;
          }
          return 0x1f;
        }
      }
    }
    else {
      if (param_3 == 0xc9) {
        local_60 = 0;
        if (param_5 != 4) {
          return 0x1f;
        }
        uStack_70 = uVar11;
        local_6c = uVar4;
        uVar6 = rmapiLockAcquire(0,0x1000);
        if (uVar6 == 0) {
          if (*(long *)(param_2 + 0x58) != 0) {
            rmapiLockRelease();
            return 0x40;
          }
          lVar9 = nv_get_file_private(*param_4,1,&local_60);
          if (lVar9 != 0) {
            if ((param_2 != lVar9) && (*(long *)(lVar9 + 0x58) == 0)) {
              LOCK();
              bVar14 = *(int *)(param_2 + 0x68) == 0;
              if (bVar14) {
                *(int *)(param_2 + 0x68) = 2;
              }
              UNLOCK();
              if (!bVar14) {
                nv_put_file_private(local_60);
                rmapiLockRelease();
                return 0x17;
              }
              LOCK();
              *(long *)(param_2 + 0x58) = lVar9;
              UNLOCK();
              *(undefined8 *)(param_2 + 0x60) = local_60;
              rmapiLockRelease();
              return 0;
            }
            nv_put_file_private(local_60);
          }
          rmapiLockRelease();
          return 0x1f;
        }
        return (ulong)uVar6;
      }
      if (param_3 < 0xca) {
        if (param_3 == 0x5e) {
          if (param_5 != 0x28) {
            return 0x1f;
          }
          if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
            return 0x1f;
          }
          uStack_70 = uVar11;
          local_6c = uVar4;
          iVar7 = rm_update_device_mapping_info
                            (*param_4,param_4[1],param_4[2],*(undefined8 *)(param_4 + 4),
                             *(undefined8 *)(param_4 + 6));
          param_4[8] = iVar7;
          return 0;
        }
        if (param_3 == 0x5f) {
          if (param_5 != 0x3c34) {
            return 0x1f;
          }
          if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
            return 0x1f;
          }
          uStack_70 = uVar11;
          local_6c = uVar4;
          cVar5 = osIsAdministrator();
          if (cVar5 != '\0') {
            iVar7 = *param_4;
            if (iVar7 == 0x605) {
              uVar6 = cliresCtrlCmdNvdGetNvlogBufferInfo_IMPL(0,param_4 + 2);
              uVar13 = (ulong)uVar6;
            }
            else if (iVar7 == 0x606) {
              uVar6 = cliresCtrlCmdNvdGetNvlog_IMPL(0,param_4 + 2);
              uVar13 = (ulong)uVar6;
            }
            else {
              uVar13 = 0x56;
              if (iVar7 == 0x604) {
                uVar6 = cliresCtrlCmdNvdGetNvlogInfo_IMPL(0,param_4 + 2);
                uVar13 = (ulong)uVar6;
              }
            }
            param_4[1] = (int)uVar13;
            return uVar13;
          }
          return 0x1b;
        }
      }
      else if (param_3 == 0xd1) {
        if (param_5 != 0xc) {
          return 0x1f;
        }
        if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
          return 0x1f;
        }
        uStack_70 = uVar11;
        local_6c = uVar4;
        lVar9 = nv_get_adapter_state(*param_4,(char)param_4[1],*(undefined1 *)((long)param_4 + 5));
        if (lVar9 == 0) {
          return 0x1f;
        }
        uVar13 = rm_get_adapter_status(lVar9,param_4 + 2);
        return uVar13;
      }
    }
LAB_002607a8:
    uStack_70 = uVar11;
    local_6c = uVar4;
    nvDbg_Printf("arch/nvalloc/unix/src/escape.c",0x3ea,"RmIoctl",4,
                 "NVRM: unknown NVRM ioctl command: 0x%x\n",param_3);
    return 0xffff;
  }
  if (param_3 == 0x34) {
    if (param_5 != 0x1c) {
      return 0x1f;
    }
    if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
      uStack_70 = uVar11;
      local_6c = uVar4;
      Nv04DupObjectWithSecInfo(param_4);
      return 0;
    }
    return 0x1f;
  }
  if (0x34 < param_3) {
    if (param_3 == 0x41) {
      if (param_5 != 0x38) {
        return 0x1f;
      }
      if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
        uStack_70 = uVar11;
        local_6c = uVar4;
        Nv04IdleChannelsWithSecInfo(param_4);
        return 0;
      }
      return 0x1f;
    }
    if (param_3 < 0x42) {
      if (param_3 == 0x35) {
        if (param_5 != 0x18) {
          return 0x1f;
        }
        if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
          uStack_70 = uVar11;
          local_6c = uVar4;
          Nv04ShareWithSecInfo(param_4);
          return 0;
        }
        return 0x1f;
      }
      if (param_3 == 0x39) {
        if (param_5 != 0x20) {
          return 0x1f;
        }
        if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
          uStack_70 = uVar11;
          local_6c = uVar4;
          Nv04I2CAccessWithSecInfo(param_4);
          return 0;
        }
        return 0x1f;
      }
    }
    else if (param_3 == 0x4a) {
      if (param_5 != 0xb8) {
        return 0x1f;
      }
      if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
        if (param_4[2] != 0x1b) {
          uStack_70 = uVar11;
          local_6c = uVar4;
          Nv04VidHeapControlWithSecInfo(param_4);
          return 0;
        }
        uStack_70 = uVar11;
        local_6c = uVar4;
        RmCreateOsDescriptor(param_4);
        return 0;
      }
      return 0x1f;
    }
    goto LAB_002607a8;
  }
  if (param_3 == 0x29) {
    if (param_5 != 0x10) {
      return 0x1f;
    }
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      return 0x1f;
    }
    uStack_70 = uVar11;
    local_6c = uVar4;
    Nv01FreeWithSecInfo(param_4);
    if (param_4[3] != 0) {
      return 0;
    }
    if (param_4[2] == *param_4) {
      rm_client_free_os_events();
      return 0;
    }
    return 0;
  }
  if (0x29 < param_3) {
    if (param_3 == 0x2a) {
      local_90 = 0;
      if (param_5 != 0x20) {
        return 0x1f;
      }
      if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
        return 0x1f;
      }
      if (param_4[2] == 0xe00101) {
        uVar6 = 0x418;
      }
      else {
        uStack_70 = uVar11;
        local_6c = uVar4;
        if (param_4[2] != 0xfd0104) goto LAB_0026099b;
        uVar6 = 0x10;
      }
      local_58 = &local_88;
      local_60 = *(undefined8 *)(param_4 + 4);
      local_40 = "RmGetDeviceFd";
      local_50 = (ulong)uVar6;
      local_48 = CONCAT71(local_48._1_7_,1);
      uStack_70 = uVar11;
      local_6c = uVar4;
      uVar6 = rmapiParamsAcquire(&local_60,1);
      if (uVar6 != 0) {
        return (ulong)uVar6;
      }
      if (param_4[2] == 0xe00101) {
        iVar7 = *param_4;
        iVar1 = *(int *)(local_88 + 4);
        uVar11 = (undefined4)*(undefined8 *)(local_88 + 0x410);
        iVar8 = rmapiParamsRelease(&local_60);
        if (iVar8 != 0) {
          nvAssertFailedNoLog("rmapiParamsRelease(&paramCopy) == NV_OK",
                              "arch/nvalloc/unix/src/escape.c",0x80);
        }
        if (iVar1 == iVar7) goto LAB_0026099b;
      }
      else {
        if (param_4[2] != 0xfd0104) {
          nvAssertFailedNoLog(&DAT_00ccab88,"arch/nvalloc/unix/src/escape.c",0x7c);
          iVar7 = rmapiParamsRelease(&local_60);
          if (iVar7 != 0) {
            nvAssertFailedNoLog("rmapiParamsRelease(&paramCopy) == NV_OK",
                                "arch/nvalloc/unix/src/escape.c",0x80);
          }
          goto LAB_0026099b;
        }
        uVar11 = *(undefined4 *)(local_88 + 8);
        iVar7 = rmapiParamsRelease(&local_60);
        if (iVar7 != 0) {
          nvAssertFailedNoLog("rmapiParamsRelease(&paramCopy) == NV_OK",
                              "arch/nvalloc/unix/src/escape.c",0x80);
        }
      }
      lVar9 = nv_get_file_private(uVar11,0,&local_90);
      if (lVar9 == 0) {
        return 0x26;
      }
      LOCK();
      bVar14 = *(int *)(lVar9 + 0x68) == 0;
      if (bVar14) {
        *(int *)(lVar9 + 0x68) = 1;
      }
      UNLOCK();
      if ((!bVar14) && (*(int *)(lVar9 + 0x68) != 1)) {
        nv_put_file_private(local_90);
        return 0x17;
      }
LAB_0026099b:
      local_80 = (uint)(cVar5 != '\0');
      Nv04ControlWithSecInfo(param_4);
      if ((param_4[7] != 0) && (local_90 != 0)) {
        nv_put_file_private();
      }
      return 0;
    }
    if (param_3 != 0x2b) goto LAB_002607a8;
    if ((param_5 & 0xffffffef) != 0x20) {
      return 0x1f;
    }
    uVar6 = param_4[3];
    if (uVar6 == 0x41) {
LAB_002605bb:
      if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
        return 0x1f;
      }
      param_4[3] = 0x41;
    }
    else {
      if (uVar6 < 0x42) {
        if (uVar6 < 2) goto LAB_002605bb;
        if (uVar6 == 5) goto LAB_002605ce;
      }
      else if (uVar6 < 0x7a) {
        if (0x77 < uVar6) goto LAB_002605ce;
      }
      else if (uVar6 == 0x7e) goto LAB_002605ce;
      if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
        return 0x1f;
      }
    }
LAB_002605ce:
    if (param_5 != 0x30) {
      uStack_70 = uVar11;
      local_6c = uVar4;
      Nv04AllocWithSecInfo(param_4);
      return 0;
    }
    uStack_70 = uVar11;
    local_6c = uVar4;
    Nv04AllocWithAccessSecInfo(param_4);
    return 0;
  }
  if (param_3 != 0x27) {
    if (param_3 == 0x28) {
      if (param_5 != 0x14) {
        return 0x1f;
      }
      if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
        return 0x1f;
      }
      uStack_70 = uVar11;
      local_6c = uVar4;
      Nv01AllocObjectWithSecInfo(param_4);
      return 0;
    }
    goto LAB_002607a8;
  }
  if (param_5 != 0x38) {
    return 0x1f;
  }
  if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
    return 0x1f;
  }
  uVar6 = param_4[4];
  if (param_4[3] != 0x71) {
    uStack_70 = uVar11;
    local_6c = uVar4;
    Nv01AllocMemoryWithSecInfo(param_4);
    if (param_4[3] != 0x3e) {
      return 0;
    }
    if ((uVar6 & 0x30000) == 0x10000) {
      return 0;
    }
    if (uVar6 >> 0x1e == 1) {
      return 0;
    }
    if (param_4[10] == 0) {
      iVar7 = rm_create_mmap_context
                        (*param_4,param_4[1],param_4[2],*(undefined8 *)(param_4 + 6),
                         *(long *)(param_4 + 8) + 1,0,6,param_4[0xc]);
      if (iVar7 != 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/escape.c",0x1a8,"RmIoctl",3,
                     "NVRM: could not create mmap context for %p\n",*(undefined8 *)(param_4 + 6));
        return 0x1f;
      }
      return 0;
    }
    return 0;
  }
  local_60 = CONCAT44(uStack_7c,local_80);
  local_58 = (long *)CONCAT44(uStack_74,uStack_78);
  local_48 = CONCAT44(local_64,uStack_68);
  if ((uVar6 & 0xc0000f00) != 0x40000000) {
LAB_00260ddd:
    iVar7 = 0x29;
LAB_00260de2:
    param_4[10] = iVar7;
    return 0;
  }
  if ((uVar6 & 0xb000) == 0x1000) {
    uVar12 = 0xa2000000;
  }
  else {
    uVar12 = 0x2000000;
    if ((uVar6 & 0xf000) != 0) goto LAB_00260ddd;
  }
  uVar3 = uVar12 | 0x10000000;
  if ((uVar6 & 0xf0) != 0) {
    uVar3 = uVar12 | 0x8000000;
  }
  uVar12 = (-(uint)((uVar6 & 0x40000) == 0) & 4) + 4;
  if ((uVar6 & 0x6000000) == 0x4000000) {
    uVar12 = uVar12 | 0x4000000;
  }
  local_50 = lVar9;
  piVar10 = (int *)portMemAllocNonPaged(0xb8);
  if (piVar10 == (int *)0x0) {
    iVar7 = 0x51;
    goto LAB_00260de2;
  }
  portMemSet(piVar10,0,0xb8);
  *piVar10 = *param_4;
  iVar7 = param_4[1];
  piVar10[2] = 0x1b;
  piVar10[1] = iVar7;
  if ((param_4[4] & 0x200000U) == 0) {
    if ((param_4[4] & 0x400000U) == 0) goto LAB_00260f87;
  }
  else {
    uVar12 = uVar12 | 0x400000;
  }
  uVar12 = uVar12 | 0x800000;
LAB_00260f87:
  iVar7 = param_4[2];
  piVar10[0xc] = 0xc000;
  piVar10[0xd] = uVar3;
  piVar10[10] = iVar7;
  piVar10[0xe] = uVar12;
  *(undefined8 *)(piVar10 + 0x10) = *(undefined8 *)(param_4 + 6);
  uVar2 = *(undefined8 *)(param_4 + 8);
  piVar10[0x14] = 0;
  *(undefined8 *)(piVar10 + 0x12) = uVar2;
  RmCreateOsDescriptor(piVar10);
  param_4[10] = piVar10[5];
  portMemFree(piVar10);
  return 0;
}


// ===== 00261130 memset =====

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)os_mem_set(__s,(char)__c);
  return pvVar1;
}


// ===== 00261140 memcpy =====

void memcpy(void)

{
  os_mem_copy();
  return;
}


// ===== 00261150 nv_parse_config_params =====

undefined8
nv_parse_config_params(undefined8 param_1,undefined8 param_2,char param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 local_48;
  long local_40 [2];
  
  uVar6 = 0x57;
  uVar3 = rm_remove_spaces();
  local_48 = uVar3;
  while( true ) {
    local_40[0] = rm_string_token(&local_48,(int)param_3);
    if (local_40[0] == 0) break;
    lVar4 = rm_string_token(local_40,0x3d);
    if (lVar4 != 0) {
      iVar1 = os_string_length(lVar4);
      if (iVar1 != 0) {
        lVar5 = rm_string_token(local_40,0x3d);
        if (lVar5 != 0) {
          iVar1 = os_string_length(lVar5);
          if (iVar1 != 0) {
            uVar2 = os_strtoul(lVar5,0,0);
            iVar1 = os_string_compare(lVar4,param_2);
            if (iVar1 == 0) {
              uVar6 = 0;
              *param_4 = uVar2;
            }
          }
        }
      }
    }
  }
  os_free_mem(uVar3);
  return uVar6;
}


// ===== 00261230 hypervisorIsVgxHyper_IMPL =====

void hypervisorIsVgxHyper_IMPL(void)

{
  os_is_vgx_hyper();
  return;
}


// ===== 00261240 hypervisorInjectInterrupt_IMPL =====

undefined8 hypervisorInjectInterrupt_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_30 [32];
  
  iVar1 = os_call_vgpu_vfio(local_30,2);
  if (((iVar1 != 0) && (*(long *)(param_2 + 0x18) != 0)) && (*(int *)(param_2 + 0x20) != 0)) {
    uVar2 = os_inject_vgx_msi(*(undefined2 *)(param_2 + 0x10));
    return uVar2;
  }
  return 0x56;
}


// ===== 00261290 nv_get_hypervisor_type =====

void nv_get_hypervisor_type(void)

{
  hypervisorGetHypervisorType_IMPL(*(undefined8 *)(g_pSys + 0x238));
  return;
}


// ===== 002612b0 nv_vgpu_get_type_info =====

int nv_vgpu_get_type_info
              (undefined8 param_1,long *param_2,int param_3,undefined8 param_4,int param_5,
              undefined1 param_6)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  uint local_d0;
  undefined4 local_cc;
  undefined1 local_c8 [152];
  
  lVar4 = *(long *)(g_pSys + 0x1f8);
  local_cc = 0;
  threadStateInit(local_c8,0);
  iVar3 = rmapiLockAcquire(0,0x8000);
  if (iVar3 == 0) {
    iVar3 = kvgpumgrGetPgpuIndex(lVar4,*(undefined4 *)((long)param_2 + 0x24),&local_d0);
    if (iVar3 == 0) {
      lVar4 = lVar4 + (ulong)local_d0 * 0xbbb80;
      lVar1 = lVar4 + 0x400;
      while (piVar2 = *(int **)(lVar4 + 0x280), piVar2 != (int *)0x0) {
        if (*piVar2 == param_3) {
          iVar3 = 0x1f;
          if (param_5 == 2) {
            if (((long *)*param_2 == (long *)0x0) || (lVar4 = *(long *)*param_2, lVar4 == 0)) {
              iVar3 = 0x40;
              nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x8f,"nv_vgpu_get_type_info",4,
                           "NVRM: %s GPU handle is not valid \n");
            }
            else {
              iVar3 = kvgpumgrGetAvailableInstances(&local_cc,lVar4,piVar2,(ulong)local_d0,param_6);
              if (iVar3 == 0) {
                os_snprintf(param_4,0x100,&DAT_00ccacae,local_cc);
              }
            }
          }
          break;
        }
        lVar4 = lVar4 + 8;
        if (lVar4 == lVar1) break;
      }
    }
    rmapiLockRelease();
  }
  threadStateFree(local_c8,0);
  return iVar3;
}


// ===== 00261440 nv_vgpu_get_type_ids =====

int nv_vgpu_get_type_ids
              (undefined8 param_1,long *param_2,uint *param_3,long param_4,char param_5,
              undefined1 param_6,char param_7)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined4 *puVar7;
  uint local_d0;
  int local_cc;
  undefined1 local_c8 [152];
  
  lVar2 = *(long *)(g_pSys + 0x1f8);
  local_cc = 0;
  if ((param_4 == 0) || (param_3 == (uint *)0x0)) {
    return 0x1f;
  }
  threadStateInit(local_c8,0);
  iVar3 = rmapiLockAcquire(0,0x8000);
  if (iVar3 == 0) {
    iVar3 = kvgpumgrGetPgpuIndex(lVar2,*(undefined4 *)((long)param_2 + 0x24),&local_d0);
    if (iVar3 == 0) {
      uVar5 = (ulong)local_d0;
      if ((*(char *)(lVar2 + 0xbb838 + uVar5 * 0xbbb80) == '\0') || (param_5 != '\0')) {
        lVar6 = uVar5 * 0xbbb80 + lVar2;
        uVar1 = *(uint *)(lVar6 + 0x250);
        *param_3 = 0;
        if (uVar1 == 0) {
          iVar3 = 0;
        }
        else {
          puVar7 = *(undefined4 **)(lVar6 + 0x280);
          uVar4 = 0;
          if (param_7 == '\0') {
            uVar4 = 0;
            while( true ) {
              uVar4 = uVar4 + 1;
              *(undefined4 *)(param_4 + (ulong)*param_3 * 4) = *puVar7;
              *param_3 = *param_3 + 1;
              if (uVar1 == uVar4) break;
              puVar7 = *(undefined4 **)
                        (lVar2 + 0x10 + ((ulong)uVar4 + 0x4e + (ulong)local_d0 * 0x17770) * 8);
            }
          }
          else {
            while (((long *)*param_2 != (long *)0x0 && (lVar6 = *(long *)*param_2, lVar6 != 0))) {
              iVar3 = kvgpumgrGetAvailableInstances(&local_cc,lVar6,puVar7,uVar5,param_6);
              if (iVar3 == 0) {
                if (local_cc != 0) {
                  *(undefined4 *)(param_4 + (ulong)*param_3 * 4) = *puVar7;
                  *param_3 = *param_3 + 1;
                }
              }
              else {
                nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0xf1,"nv_vgpu_get_type_ids",4,
                             "NVRM: Failed to get available instances for vGPU ID: %d, status: 0x%x\n"
                             ,*puVar7);
              }
              if (uVar1 == uVar4 + 1) goto LAB_00261620;
              uVar4 = uVar4 + 1;
              uVar5 = (ulong)local_d0;
              puVar7 = *(undefined4 **)(lVar2 + 0x10 + ((ulong)uVar4 + 0x4e + uVar5 * 0x17770) * 8);
            }
            nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0xe7,"nv_vgpu_get_type_ids",4,
                         "NVRM: %s GPU handle is not valid \n");
          }
        }
      }
      else {
        *param_3 = 0;
      }
    }
LAB_00261620:
    rmapiLockRelease();
  }
  threadStateFree(local_c8,0);
  return iVar3;
}


// ===== 00261740 nv_vgpu_delete =====

int nv_vgpu_delete(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  int iVar1;
  undefined1 local_b8 [152];
  
  threadStateInit(local_b8,0);
  iVar1 = rmapiLockAcquire(0,0x8000);
  if (iVar1 == 0) {
    iVar1 = kvgpumgrDeleteRequestVgpu(param_2,param_3);
    rmapiLockRelease();
  }
  threadStateFree(local_b8,0);
  return iVar1;
}


// ===== 002617c0 nv_vgpu_process_vf_info =====

int nv_vgpu_process_vf_info
              (undefined8 param_1,long param_2,undefined1 param_3,undefined4 param_4,
              undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
              undefined8 param_9)

{
  int iVar1;
  undefined8 extraout_RDX;
  undefined8 uVar2;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar1 = rmapiLockAcquire(0,0x8000);
  uVar2 = extraout_RDX;
  if (iVar1 == 0) {
    iVar1 = kvgpumgrProcessVfInfo
                      (*(undefined4 *)(param_2 + 0x24),param_3,param_4,param_5,param_6,param_7,
                       param_8);
    rmapiLockRelease();
    uVar2 = param_9;
  }
  threadStateFree(local_c8,0,uVar2);
  return iVar1;
}


// ===== 00261870 nv_vgpu_create_request =====

int nv_vgpu_create_request
              (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8)

{
  int iVar1;
  undefined8 extraout_RDX;
  undefined8 uVar2;
  undefined8 uStack_e0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  uStack_e0 = 0x2618b5;
  iVar1 = rmapiLockAcquire(0,0x8000);
  uVar2 = extraout_RDX;
  if (iVar1 == 0) {
    iVar1 = kvgpumgrCreateRequestVgpu
                      (*(undefined4 *)(param_2 + 0x24),param_3,param_4,param_5,param_6,param_7,
                       param_8);
    rmapiLockRelease();
    uVar2 = uStack_e0;
  }
  threadStateFree(local_c8,0,uVar2);
  return iVar1;
}


// ===== 00261910 nv_vgpu_update_sysfs_info =====

int nv_vgpu_update_sysfs_info
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
              undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 local_c8 [152];
  
  lVar4 = *(long *)(g_pSys + 0x1f8);
  threadStateInit(local_c8,0);
  iVar1 = rmapiLockAcquire(0,0x8000);
  if (iVar1 == 0) {
    lVar4 = lVar4 + 0x17770b0;
    for (lVar3 = listHead_IMPL(lVar4); lVar3 != 0; lVar3 = listNext_IMPL(lVar4,lVar3)) {
      iVar2 = portMemCmp(lVar3 + 4,param_3,0x10);
      if (iVar2 == 0) {
        if (param_4 == 0) {
          iVar1 = kvgpumgrSetGpuInstanceId(lVar3,*param_5);
          goto LAB_00261a24;
        }
        if (param_4 == 1) {
          iVar1 = kvgpumgrSetPlacementId(lVar3,*param_5);
          goto LAB_00261a24;
        }
        if (param_4 != 2) goto LAB_00261a24;
        *param_5 = *(undefined4 *)(lVar3 + 0x20);
        rmapiLockRelease();
        goto LAB_002619e3;
      }
    }
    iVar1 = 0x57;
LAB_00261a24:
    rmapiLockRelease();
  }
LAB_002619e3:
  threadStateFree(local_c8,0);
  return iVar1;
}


// ===== 00261a60 nv_vgpu_get_hbm_info =====

int nv_vgpu_get_hbm_info
              (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  undefined8 *puVar1;
  int iVar2;
  long local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  if ((param_5 == (undefined8 *)0x0) || (param_4 == (undefined8 *)0x0)) {
    iVar2 = 0x1f;
  }
  else {
    iVar2 = rmapiLockAcquire(0,0x8000);
    if (iVar2 == 0) {
      if (((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) ||
         (*(long *)*param_2 == 0)) {
        iVar2 = 0x40;
        nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x271,"nv_vgpu_get_hbm_info",4,
                     "NVRM: %s GPU handle is not valid \n");
      }
      else {
        iVar2 = kvgpumgrGetHostVgpuDeviceFromVgpuDevName
                          (*(undefined4 *)((long)param_2 + 0x24),param_3,&local_d0);
        if (iVar2 == 0) {
          if (*(uint *)(local_d0 + 0x300) < 2) {
            puVar1 = *(undefined8 **)(local_d0 + 0x2f8);
          }
          else {
            nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x27c,"nv_vgpu_get_hbm_info",2,
                         "NVRM: non contiguous HBM region is not supported\n");
            nvAssertFailedNoLog(&DAT_00ccad32,"arch/nvalloc/unix/src/os-hypervisor.c",0x27d);
            puVar1 = *(undefined8 **)(local_d0 + 0x2f8);
          }
          if (puVar1 != (undefined8 *)0x0) {
            *param_4 = *puVar1;
            *param_5 = *(undefined8 *)(*(long *)(local_d0 + 0x2f8) + 8);
            rmapiLockRelease();
            goto LAB_00261b2e;
          }
          *param_4 = 0;
          *param_5 = 0;
        }
      }
      rmapiLockRelease();
    }
  }
LAB_00261b2e:
  threadStateFree(local_c8,0);
  return iVar2;
}


// ===== 00261c00 nv_vgpu_rm_get_bar_info =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nv_vgpu_rm_get_bar_info
              (long param_1,undefined8 param_2,ulong *param_3,long param_4,long param_5,
              uint *param_6,undefined1 *param_7,undefined8 param_8)

{
  undefined1 uVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  int local_50;
  uint local_4c;
  undefined4 *local_48;
  long local_40 [2];
  
  if (param_1 == 0) {
    iVar7 = 0x40;
    nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x171,"is_bar_64bit",4,
                 "NVRM: %s GPU handle is not valid \n");
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 0x3af0);
    *param_7 = uVar1;
    nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x18b,"is_bar_64bit",1,
                 "NVRM: BAR%d region is_64bit: %d\n",0,uVar1);
    iVar7 = kvgpumgrGetHostVgpuDeviceFromVgpuDevName
                      (*(undefined4 *)(param_1 + 0x7ac),param_2,&local_48);
    if (iVar7 == 0) {
      iVar7 = 0;
LAB_00261c9d:
      do {
        if ((*(char *)(param_1 + 0x491d) != '\0') && (iVar7 != 1)) {
          *param_3 = 0;
LAB_00261cbb:
          iVar7 = iVar7 + 1;
          if (iVar7 == 4) {
LAB_00261cc9:
            lVar3 = *(long *)(param_1 + 0x1b88);
            lVar9 = gpuGetKernelFifoShared_IMPL(param_1);
            lVar4 = *(long *)(param_1 + 7000);
            local_50 = 0;
            *param_6 = 0;
            if (local_48[6] == 0) {
              iVar7 = nv_parse_config_params(param_8,"direct_gpu_timer_access",0x2c,&local_50);
              if ((iVar7 == 0) && (local_50 != 0)) {
                local_40[0] = 0;
                local_4c = 0;
                iVar7 = (**(code **)(lVar3 + 0x1f8))(param_1,lVar3);
                if (iVar7 == 0) {
                  *(long *)(param_4 + (ulong)*param_6 * 8) = local_40[0];
                  *(ulong *)(param_5 + (ulong)*param_6 * 8) = (ulong)local_4c;
                  *param_6 = *param_6 + 1;
                }
              }
              else {
                iVar7 = 0;
              }
              local_40[0] = 0;
              local_4c = 0;
              iVar8 = (**(code **)(lVar9 + 0x1e0))(param_1,lVar9,local_40,&local_4c);
              if (iVar8 == 0) {
                *(long *)(param_4 + (ulong)*param_6 * 8) = local_40[0];
                *(ulong *)(param_5 + (ulong)*param_6 * 8) = (ulong)local_4c;
                *param_6 = *param_6 + 1;
                return iVar7;
              }
            }
            else {
              iVar7 = (**(code **)(lVar4 + 0x260))(param_1,lVar4,local_48,os_page_size,param_6,0,0);
              if (iVar7 == 0) {
                if (*param_6 < 6) {
                  iVar7 = (**(code **)(lVar4 + 0x260))
                                    (param_1,lVar4,local_48,os_page_size,param_6,param_4,param_5);
                  return iVar7;
                }
                nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x2d1,
                             "_nv_vgpu_get_sparse_mmap",4,
                             "NVRM: Not enough space for sparse mmap region info\n");
                return 0x1a;
              }
            }
            return iVar7;
          }
          param_3 = param_3 + 1;
          goto LAB_00261c9d;
        }
        while( true ) {
          puVar6 = local_48;
          uVar5 = *(undefined8 *)(&DAT_00001b90 + param_1);
          local_50 = 0;
          lVar3 = *(long *)(g_pSys + 0x1f8);
          uVar10 = kbusGetPciBarSize_IMPL(uVar5,iVar7);
          *param_3 = uVar10;
          if (iVar7 == 1) break;
          if (iVar7 - 2U < 2) {
            iVar8 = nv_parse_config_params(param_8,"address64",0x2c,&local_50);
            if (iVar8 == 0 && local_50 == 0) goto LAB_00261cbb;
            if (iVar7 == 2) {
              *param_3 = 0;
              iVar7 = 3;
              param_3 = param_3 + 1;
              goto LAB_00261c9d;
            }
            uVar10 = kbusGetPciBarSize_IMPL(uVar5,2);
            *param_3 = uVar10;
            goto LAB_00261cc9;
          }
          param_3 = param_3 + 1;
          iVar7 = 1;
        }
        local_4c = 0;
        iVar7 = kvgpumgrGetVgpuTypeInfo(*puVar6,local_40);
        if (iVar7 != 0) {
          nvAssertOkFailedNoLog
                    (iVar7,"kvgpumgrGetVgpuTypeInfo(pKernelHostVgpuDevice->vgpuType, &vgpuTypeInfo)"
                     ,"arch/nvalloc/unix/src/os-hypervisor.c",0x1a5);
LAB_00262212:
          nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x32c,"nv_vgpu_rm_get_bar_info",4,
                       "NVRM: Failed to query BAR size for index %u 0x%x\n",1,iVar7);
          return iVar7;
        }
        *param_3 = *(long *)(local_40[0] + 0x378) << 0x14;
        iVar7 = kvgpumgrGetPgpuIndex(lVar3,*(undefined4 *)(param_1 + 0x7ac),&local_4c);
        if (iVar7 != 0) {
          nvAssertOkFailedNoLog
                    (iVar7,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &pgpuIndex)",
                     "arch/nvalloc/unix/src/os-hypervisor.c",0x1a9);
          goto LAB_00262212;
        }
        iVar7 = nv_parse_config_params(local_40[0] + 0x394,"override_bar1_size",0x3b,&local_50);
        if (iVar7 == 0) {
          cVar2 = *(char *)(param_1 + 0x4a79);
          if (local_50 == 0) goto joined_r0x00262132;
joined_r0x00262125:
          if (cVar2 != '\0') {
            uVar10 = *(ulong *)(param_1 + 0x3a78);
            if (*param_3 <= uVar10) {
              iVar7 = portStringCompare("Compute",local_40[0] + 0x44,7);
              if (iVar7 != 0) goto LAB_00262067;
              uVar10 = *(ulong *)(param_1 + 0x3a78);
            }
            *param_3 = uVar10;
          }
LAB_00262067:
          uVar10 = kbusGetPciBarSize_IMPL(uVar5,1);
          if (*(char *)(lVar3 + 0xbb838 + (ulong)local_4c * 0xbbb80) == '\0') {
            if (0x10000000 < uVar10) {
              uVar10 = uVar10 / *(uint *)(local_40[0] + 0x310);
              uVar10 = uVar10 >> 1 | uVar10;
              uVar10 = uVar10 | uVar10 >> 2;
              uVar10 = uVar10 | uVar10 >> 4;
              uVar10 = uVar10 | uVar10 >> 8;
              uVar10 = uVar10 | uVar10 >> 0x10;
              uVar10 = uVar10 | uVar10 >> 0x20;
              uVar10 = uVar10 - (uVar10 >> 1);
              goto LAB_00261f7e;
            }
          }
          else {
LAB_00262180:
            *param_3 = *(ulong *)(param_1 + 0x3a78);
          }
        }
        else {
          iVar7 = nv_parse_config_params(param_8,"override_bar1_size",0x2c,&local_50);
          cVar2 = *(char *)(param_1 + 0x4a79);
          if ((iVar7 == 0) && (local_50 != 0)) goto joined_r0x00262125;
joined_r0x00262132:
          if (cVar2 != '\0') {
            uVar10 = *(ulong *)(param_1 + 0x3a78);
            if (uVar10 < *param_3) {
LAB_00261f7e:
              *param_3 = uVar10;
            }
            else {
              iVar7 = portStringCompare("Compute",local_40[0] + 0x44,7);
              if (iVar7 == 0) goto LAB_00262180;
            }
          }
        }
        param_3 = param_3 + 1;
        iVar7 = 2;
      } while( true );
    }
  }
  return iVar7;
}


// ===== 002622c0 nv_vgpu_get_bar_info =====

int nv_vgpu_get_bar_info
              (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  int iVar2;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar2 = rmapiLockAcquire(0,0x8000);
  if (iVar2 == 0) {
    if (((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) ||
       (lVar1 = *(long *)*param_2, lVar1 == 0)) {
      iVar2 = 0x40;
      nvDbg_Printf("arch/nvalloc/unix/src/os-hypervisor.c",0x205,"nv_vgpu_get_bar_info",4,
                   "NVRM: %s GPU handle is not valid \n");
    }
    else {
      iVar2 = nv_vgpu_rm_get_bar_info(lVar1,param_3,param_4,param_5,param_6,param_7,param_8);
    }
    rmapiLockRelease();
  }
  threadStateFree(local_c8,0);
  return iVar2;
}


// ===== 002623b0 nv_gpu_unbind_event =====

int nv_gpu_unbind_event(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 local_bc;
  undefined1 local_b8 [152];
  
  threadStateInit(local_b8,0);
  iVar1 = rmapiLockAcquire(0,0x8000);
  if (iVar1 == 0) {
    local_bc = param_2;
    CliAddSystemEvent(1,&local_bc,param_3);
    rmapiLockRelease();
  }
  threadStateFree(local_b8,0);
  return iVar1;
}


// ===== 00262440 nv_gpu_bind_event =====

int nv_gpu_bind_event(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 local_bc;
  undefined1 local_b8 [152];
  
  threadStateInit(local_b8,0);
  iVar1 = rmapiLockAcquire(0,0x8000);
  if (iVar1 == 0) {
    local_bc = param_2;
    CliAddSystemEvent(2,&local_bc,param_3);
    rmapiLockRelease();
  }
  threadStateFree(local_b8,0);
  return iVar1;
}


// ===== 002624d0 osIsVgpuVfioPresent =====

void osIsVgpuVfioPresent(void)

{
  undefined1 local_20 [24];
  
  os_call_vgpu_vfio(local_20,2);
  return;
}


// ===== 002624f0 osIsVfioPciCorePresent =====

void osIsVfioPciCorePresent(void)

{
  undefined1 local_20 [24];
  
  os_call_vgpu_vfio(local_20,3);
  return;
}


// ===== 00262510 osWakeRemoveVgpu =====

void osWakeRemoveVgpu(uint param_1,undefined4 param_2)

{
  undefined1 local_20 [8];
  uint local_18;
  uint local_14;
  uint local_10;
  undefined4 local_c;
  
  local_18 = param_1 >> 0x10;
  local_10 = param_1 & 0xff;
  local_14 = param_1 >> 8 & 0xff;
  local_c = param_2;
  os_call_vgpu_vfio(local_20,1);
  return;
}


// ===== 00262550 osIsGridSupported =====

bool osIsGridSupported(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = os_is_grid_supported();
  if (cVar1 == '\0') {
    iVar2 = os_get_grid_csp_support();
    if (iVar2 == 0) {
      cVar1 = os_is_vgx_hyper();
      return cVar1 != '\0';
    }
  }
  return true;
}


// ===== 00262590 osGetGridCspSupport =====

void osGetGridCspSupport(void)

{
  os_get_grid_csp_support();
  return;
}


// ===== 002625a0 initVGXSpecificRegistry =====

void initVGXSpecificRegistry(undefined8 param_1)

{
  int iVar1;
  undefined1 local_1c [12];
  
  osWriteRegistryDword(param_1,"RMPowerFeature",0x55455555);
  osWriteRegistryDword(param_1,"RmDisableInforomBBX",1);
  osWriteRegistryDword(param_1,"RMProcessNonStallIntrInLocklessIsr",1);
  iVar1 = osReadRegistryDword(param_1,"RMDumpNvLog",local_1c);
  if (iVar1 != 0) {
    osWriteRegistryDword(param_1,"RMDumpNvLog",1);
  }
  osWriteRegistryDword(param_1,"RmRcWatchdog",0);
  osWriteRegistryDword(param_1,"ForceP2P",0);
  return;
}


// ===== 00262650 __pfx_rm_is_vgpu_supported_device =====

undefined8 __pfx_rm_is_vgpu_supported_device(long param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  short *psVar2;
  
  if (*(long *)(g_pSys + 0x238) == 0) {
    return 0;
  }
  if (*(char *)(*(long *)(g_pSys + 0x238) + 0x4a) != '\0' && (param_2 & 0x30000) != 0x10000) {
    if ((param_2 & 0x30000) != 0x20000) {
      return 0;
    }
    cVar1 = os_is_grid_supported();
    if (((cVar1 == '\0') || (cVar1 = gpumgrIsVgxRmFirmwareCapableChip(param_3), cVar1 != '\0')) &&
       (cVar1 = os_is_grid_supported(), cVar1 != '\0')) {
      psVar2 = &sVgpuUsmTypes;
      do {
        if ((*(short *)(param_1 + 0x1e) == *psVar2) && (*(short *)(param_1 + 0x20) == psVar2[1])) {
          return 0;
        }
        psVar2 = psVar2 + 3;
      } while (psVar2 != (short *)"arch/nvalloc/unix/src/os.c");
    }
    return 0x56;
  }
  return 0;
}


// ===== 00262660 rm_is_vgpu_supported_device =====

undefined8 rm_is_vgpu_supported_device(long param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  short *psVar2;
  
  if (*(long *)(g_pSys + 0x238) == 0) {
    return 0;
  }
  if (*(char *)(*(long *)(g_pSys + 0x238) + 0x4a) != '\0' && (param_2 & 0x30000) != 0x10000) {
    if ((param_2 & 0x30000) != 0x20000) {
      return 0;
    }
    cVar1 = os_is_grid_supported();
    if (((cVar1 == '\0') || (cVar1 = gpumgrIsVgxRmFirmwareCapableChip(param_3), cVar1 != '\0')) &&
       (cVar1 = os_is_grid_supported(), cVar1 != '\0')) {
      psVar2 = &sVgpuUsmTypes;
      do {
        if ((*(short *)(param_1 + 0x1e) == *psVar2) && (*(short *)(param_1 + 0x20) == psVar2[1])) {
          return 0;
        }
        psVar2 = psVar2 + 3;
      } while (psVar2 != (short *)"arch/nvalloc/unix/src/os.c");
    }
    return 0x56;
  }
  return 0;
}


// ===== 00262730 osIsVgpuDeviceVmPresent =====

void osIsVgpuDeviceVmPresent(void)

{
  os_device_vm_present();
  return;
}


// ===== 00262740 osGetPagesInfo =====

byte osGetPagesInfo(long param_1,undefined8 *param_2,ulong *param_3,ulong *param_4)

{
  char cVar1;
  byte bVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  uVar4 = 0x1000;
  if (0xfff < os_page_size) {
    uVar4 = os_page_size;
  }
  uVar4 = -uVar4 & (uVar4 - 1) + *(long *)(param_1 + 0x30);
  *param_3 = uVar4 >> (((os_page_size & 0xff00ff00) != 0) << 3 |
                       ((os_page_size & 0xffff0000) != 0) << 4 | (os_page_size & 0xaaaaaaaa) != 0 |
                       ((os_page_size & 0xf0f0f0f0) != 0) << 2 |
                      ((os_page_size & 0xcccccccc) != 0) * '\x02');
  *param_4 = uVar4 >> 0xc;
  uVar3 = memdescGetAdjustedPageSize();
  *param_2 = uVar3;
  cVar1 = memdescGetContiguity(param_1,0);
  if ((cVar1 == '\0') && (*(ulong *)(param_1 + 0x20) < *param_4)) {
    nvAssertFailedNoLog("*rmPageCount <= pMemDesc->pageArraySize","arch/nvalloc/unix/src/os.c",0x3b5
                       );
    bVar2 = 0x1f;
  }
  else {
    bVar2 = 0x2e;
    if (*param_3 < 0x100000000) {
      bVar2 = -(0xffffffff < *param_4) & 0x2e;
    }
  }
  return bVar2;
}


// ===== 00262840 _allocOsRmCaps =====

int _allocOsRmCaps(undefined8 *param_1,uint param_2)

{
  int iVar1;
  uint *local_20;
  
  *param_1 = 0;
  iVar1 = os_alloc_mem(&local_20,0x10);
  if (iVar1 != 0) {
    return iVar1;
  }
  *local_20 = param_2;
  iVar1 = os_alloc_mem(local_20 + 2,(ulong)param_2 << 3);
  if (iVar1 == 0) {
    os_mem_set(*(undefined8 *)(local_20 + 2),0,param_2 * 8);
    *param_1 = local_20;
    return 0;
  }
  os_free_mem();
  return iVar1;
}


// ===== 002628f0 osTegraDceClientIpcCallback =====

void osTegraDceClientIpcCallback
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_c8 [152];
  
  uVar1 = nv_tegra_get_rm_interface_type(param_2);
  threadStateInit(local_c8,0);
  iVar2 = rmLocksAcquireAll(0x40002);
  if (iVar2 == 0) {
    dceclientHandleAsyncRpcCallback(param_1,uVar1,param_3,param_4,param_5);
    rmLocksReleaseAll();
  }
  threadStateFree(local_c8,0);
  return;
}


// ===== 00262980 skipIovaMappingForTegra =====

undefined4 skipIovaMappingForTegra(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("nv != NULL","arch/nvalloc/unix/src/os.c",0xd62);
  }
  if (((*(byte *)(param_2 + 0x10) & 0x10) == 0) || (*(char *)(param_2 + 0x330) != '\0')) {
    return 0;
  }
  cVar1 = memdescGetFlag(*(undefined8 *)(param_1 + 8),0x4000000000);
  if (cVar1 != '\0') {
    return 0;
  }
  uVar2 = memdescGetFlag(*(undefined8 *)(param_1 + 8),0x800000);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xd69,"skipIovaMappingForTegra",1,
               "NVRM: %s: Skip memdescMapIommu mapping\n");
  return 1;
}


// ===== 00262a50 _initializeExportObjectFd.part.0 =====

int _initializeExportObjectFd_part_0
              (undefined8 *param_1,undefined4 param_2,int param_3,ushort param_4,long param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 local_5c;
  long local_50;
  long local_48 [3];
  
  if (param_3 == 0) {
    local_5c = 0x20;
    uVar5 = 0xffffffff;
  }
  else {
    iVar3 = serverutilGetResourceRef(param_2,param_3,&local_50);
    if (iVar3 != 0) {
      return iVar3;
    }
    lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_50 + 8),__nvoc_class_def_Device);
    if (lVar4 == 0) {
      return 0x3b;
    }
    local_5c = *(undefined4 *)(lVar4 + 0x180);
    lVar1 = *(long *)(*(long *)(lVar4 + 0x128) + 0xe0);
    if ((((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) ||
        (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar2 == '\0')) ||
       (iVar3 = kmigmgrGetInstanceRefFromDevice_IMPL
                          (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),lVar4,local_48), iVar3 != 0)) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(undefined4 *)(local_48[0] + 0x968);
    }
  }
  iVar3 = os_alloc_mem(param_1,(ulong)param_4 << 2);
  if (iVar3 == 0) {
    os_mem_set(*param_1,0,(ulong)param_4 << 2);
    *(ushort *)(param_1 + 1) = param_4;
    *(undefined4 *)(param_1 + 2) = uVar5;
    *(undefined4 *)((long)param_1 + 0xc) = local_5c;
    if (param_5 != 0) {
      os_mem_copy((long)param_1 + 0x14,param_5,0x40);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"os_alloc_mem((void **)&nvfp->handles, sizeof(nvfp->handles[0]) * maxObjects)",
               "arch/nvalloc/unix/src/os.c",0x8ef);
  }
  return iVar3;
}


// ===== 00262bb0 osIsRaisedIRQL =====

bool osIsRaisedIRQL(void)

{
  char cVar1;
  
  cVar1 = os_semaphore_may_sleep();
  return cVar1 == '\0';
}


// ===== 00262bd0 osIsISR =====

void osIsISR(void)

{
  os_is_isr();
  return;
}


// ===== 00262be0 osGetMonotonicTimeNs =====

void osGetMonotonicTimeNs(void)

{
  os_get_monotonic_time_ns();
  return;
}


// ===== 00262bf0 osGetMonotonicTickResolutionNs =====

void osGetMonotonicTickResolutionNs(void)

{
  os_get_monotonic_tick_resolution_ns();
  return;
}


// ===== 00262c00 osGetPerformanceCounter =====

undefined8 osGetPerformanceCounter(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = os_get_monotonic_time_ns_hr();
  *param_1 = uVar1;
  return 0;
}


// ===== 00262c20 osGetSystemTime =====

void osGetSystemTime(void)

{
  os_get_system_time();
  return;
}


// ===== 00262c30 osGetTimestamp =====

long osGetTimestamp(void)

{
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_c = 0;
  os_get_system_time(&local_10,&local_c);
  return (ulong)local_10 * 1000000 + (ulong)local_c;
}


// ===== 00262c70 osGetTimestampFreq =====

undefined8 osGetTimestampFreq(void)

{
  return 1000000;
}


// ===== 00262c80 osDelay =====

void osDelay(void)

{
  os_delay();
  return;
}


// ===== 00262c90 osDelayUs =====

void osDelayUs(void)

{
  os_delay_us();
  return;
}


// ===== 00262ca0 osDelayNs =====

void osDelayNs(uint param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)param_1 / 1000;
  if (param_1 < 1000) {
    uVar1 = 1;
  }
  os_delay_us(uVar1);
  return;
}


// ===== 00262cd0 osGetCpuFrequency =====

ulong osGetCpuFrequency(void)

{
  ulong uVar1;
  
  uVar1 = os_get_cpu_frequency();
  return uVar1 / 1000000;
}


// ===== 00262d00 osPciInitHandle =====

undefined8
osPciInitHandle(ulong param_1,undefined1 param_2,undefined1 param_3,char param_4,undefined2 *param_5
               ,undefined2 *param_6)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_4 != '\0') {
    uVar1 = os_pci_init_handle(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  lVar2 = gpumgrGetGpuFromBusInfo();
  if (lVar2 != 0) {
    lVar2 = *(long *)(lVar2 + 0x4e0);
    if (param_5 != (undefined2 *)0x0) {
      *param_5 = *(undefined2 *)(lVar2 + 0x1c);
    }
    if (param_6 != (undefined2 *)0x0) {
      *param_6 = *(undefined2 *)(lVar2 + 0x1e);
    }
    return *(undefined8 *)(lVar2 + 0x48);
  }
  uVar1 = os_pci_init_handle(param_1 & 0xffffffff,param_2,param_3,0);
  return uVar1;
}


// ===== 00262da0 osPciReadByte =====

undefined1 osPciReadByte(undefined8 param_1,undefined8 param_2)

{
  undefined1 local_9;
  
  os_pci_read_byte(param_1,param_2,&local_9);
  return local_9;
}


// ===== 00262dc0 osPciReadWord =====

undefined2 osPciReadWord(undefined8 param_1,undefined8 param_2)

{
  undefined2 local_a;
  
  os_pci_read_word(param_1,param_2,&local_a);
  return local_a;
}


// ===== 00262de0 osPciReadDword =====

undefined4 osPciReadDword(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_c;
  
  os_pci_read_dword(param_1,param_2,&local_c);
  return local_c;
}


// ===== 00262e00 osPciWriteWord =====

void osPciWriteWord(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  os_pci_write_word(param_1,param_2,param_3);
  return;
}


// ===== 00262e10 osPciWriteDword =====

void osPciWriteDword(void)

{
  os_pci_write_dword();
  return;
}


// ===== 00262e20 osMapKernelSpace =====

long osMapKernelSpace(ulong param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("Size != 0","arch/nvalloc/unix/src/os.c",0x131);
  }
  else {
    uVar2 = ~os_page_mask & param_1;
    if ((!CARRY8(param_2,uVar2)) && (param_2 + uVar2 <= os_page_mask)) {
      lVar1 = os_map_kernel_space(os_page_mask & param_1,
                                  ((param_2 + uVar2) - os_page_mask) - 1 & os_page_mask);
      if (lVar1 == 0) {
        uVar2 = 0;
      }
      return lVar1 + uVar2;
    }
  }
  return 0;
}


// ===== 00262ea0 osUnmapKernelSpace =====

void osUnmapKernelSpace(ulong param_1,long param_2)

{
  if (param_2 != 0) {
    os_unmap_kernel_space
              (param_1 & os_page_mask,
               ((~os_page_mask & param_1) - 1) + (param_2 - os_page_mask) & os_page_mask);
    return;
  }
  nvAssertFailedNoLog("Size != 0","arch/nvalloc/unix/src/os.c",0x150);
  return;
}


// ===== 00262ef0 osGetNumMemoryPages =====

undefined8 osGetNumMemoryPages(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = memdescGetMemData();
  if (lVar1 != 0) {
    uVar2 = nv_get_num_phys_pages(lVar1,param_2);
    return uVar2;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1d4,"osGetNumMemoryPages",4,
               "NVRM: pAllocPrivate is NULL!\n");
  return 0x40;
}


// ===== 00262f50 osGetMemoryPages =====

undefined8 osGetMemoryPages(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = memdescGetMemData();
  if (lVar1 != 0) {
    uVar2 = nv_get_phys_pages(lVar1,param_2,param_3);
    return uVar2;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1e7,"osGetMemoryPages",4,
               "NVRM: pAllocPrivate is NULL!\n");
  return 0x40;
}


// ===== 00262fc0 osMapSystemMemory =====

int osMapSystemMemory(long *param_1,long param_2,ulong param_3,char param_4,undefined4 param_5,
                     ulong *param_6,undefined8 *param_7)

{
  ulong uVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar11;
  ulong uVar12;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40 [2];
  
  lVar7 = *param_1;
  local_58 = 0;
  puVar6 = (undefined8 *)memdescGetRootMemDesc(param_1,&local_58);
  uVar12 = param_2 + local_58;
  uVar4 = ~(uint)os_page_mask & (uint)uVar12;
  if (lVar7 == 0) {
    local_50 = 0;
    uVar11 = 0;
  }
  else {
    local_50 = 0;
    uVar11 = *(undefined8 *)(lVar7 + 0x4e0);
    if ((*(char *)(lVar7 + 0x454) != '\0') && (iVar5 = memdescGetAddressSpace(puVar6), iVar5 == 2))
    {
      uVar10 = puVar6[3];
      lVar7 = *(long *)(lVar7 + 0x1b70);
      local_48 = 0;
      local_40[0] = uVar10;
      plVar8 = (long *)memdescGetPteArrayForGpu(puVar6,*puVar6,0);
      if ((*(char *)(g_pSys + 400) != '\0') &&
         (cVar3 = memdescGetContiguity(puVar6,0), cVar3 == '\0')) {
        local_40[0] = (ulong)*(uint *)(puVar6 + 0x2c);
        if (os_page_size < *(uint *)(puVar6 + 0x2c)) {
          local_40[0] = os_page_size;
        }
        local_40[0] = (ulong)puVar6[7] / local_40[0];
      }
      lVar9 = portMemAllocNonPaged(local_40[0] * 8);
      if (lVar9 == 0) {
        return 0x51;
      }
      if (((*(char *)(g_pSys + 400) == '\0') ||
          (cVar3 = memdescGetContiguity(puVar6,0), cVar3 != '\0')) && (0x1000 < os_page_size)) {
        local_40[0] = (ulong)((uVar10 & (long)((1 << (os_page_shift - 0xc & 0x1f)) + -1)) != 0) +
                      (uVar10 >> (os_page_shift - 0xc & 0x3f));
      }
      cVar3 = memdescGetContiguity(puVar6,0);
      if (cVar3 == '\0') {
        uVar1 = uVar10;
        if (((*(char *)(g_pSys + 400) != '\0') &&
            (cVar3 = memdescGetContiguity(puVar6,0), cVar3 == '\0')) &&
           (uVar1 = local_40[0], (ulong)puVar6[4] < local_40[0])) {
          nvAssertFailedNoLog("pMemDesc->pageArraySize >= numOsPages","arch/nvalloc/unix/src/os.c",
                              0x184);
          portMemFree(lVar9);
          return 0x40;
        }
        portMemCopy(lVar9,uVar1 * 8,plVar8,uVar1 * 8);
        if ((*(char *)(g_pSys + 400) == '\0') ||
           (cVar3 = memdescGetContiguity(puVar6,0), cVar3 != '\0')) {
          if (0x1000 < os_page_size) {
            RmDeflateRmToOsPageArray(lVar9,uVar10);
          }
        }
        else {
          convertPageArrayBetweenOsAndRm
                    (lVar9,(ulong)puVar6[7] / (ulong)*(uint *)(puVar6 + 0x2c),
                     (ulong)*(uint *)(puVar6 + 0x2c),(ulong)puVar6[7] / os_page_size,os_page_size,
                     local_40);
        }
        if (local_40[0] != 0) {
          uVar10 = 0;
          do {
            plVar8 = (long *)(lVar9 + uVar10 * 8);
            *plVar8 = *plVar8 + *(long *)(lVar7 + 0x478);
            uVar10 = uVar10 + 1;
          } while (uVar10 < local_40[0]);
        }
      }
      else if (local_40[0] != 0) {
        lVar7 = *(long *)(lVar7 + 0x478) + *plVar8;
        uVar10 = 0;
        do {
          *(long *)(lVar9 + uVar10 * 8) = lVar7;
          uVar10 = uVar10 + 1;
          lVar7 = lVar7 + os_page_size;
        } while (uVar10 < local_40[0]);
      }
      iVar5 = nv_register_phys_pages(uVar11,lVar9,local_40[0],0,&local_48);
      if (iVar5 != 0) {
        portMemFree(lVar9);
        return iVar5;
      }
      memdescSetMemData(puVar6,local_48,0);
      portMemFree(lVar9);
      iVar5 = memdescGetAddressSpace(puVar6);
      uVar4 = memdescGetPhysAddr(puVar6,(iVar5 == 2) + '\x01',uVar12);
      uVar4 = ~(uint)os_page_mask & uVar4;
    }
  }
  *param_6 = 0;
  *param_7 = 0;
  bVar2 = os_page_shift;
  if ((CARRY8(uVar12,param_3)) || ((ulong)puVar6[6] < uVar12 + param_3)) {
    return 0x1f;
  }
  lVar7 = memdescGetMemData(puVar6);
  if (lVar7 == 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x222,"osMapSystemMemory",4,
                 "NVRM: pAllocPrivate is NULL!\n");
    return 0x40;
  }
  uVar12 = uVar12 >> (bVar2 & 0x3f);
  if (param_4 != '\0') {
    uVar12 = nv_alloc_kernel_mapping(uVar11,lVar7,uVar12,uVar4,param_3,&local_50);
    if (uVar12 == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x22c,"osMapSystemMemory",4,
                   "NVRM: failed to create system memory kernel mapping!\n");
      return 0xffff;
    }
    *param_6 = uVar12;
    *param_7 = local_50;
    return 0;
  }
  iVar5 = nv_alloc_user_mapping(uVar11,lVar7,uVar12,uVar4,param_3,param_5,local_40,&local_50);
  if (iVar5 != 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x23d,"osMapSystemMemory",4,
                 "NVRM: failed to create system memory user mapping!\n");
    return iVar5;
  }
  *param_6 = local_40[0];
  *param_7 = local_50;
  return 0;
}


// ===== 002635b0 osUnmapSystemMemory =====

void osUnmapSystemMemory(long *param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  lVar1 = *param_1;
  if (lVar1 != 0) {
    uVar5 = *(undefined8 *)(lVar1 + 0x4e0);
  }
  uVar3 = memdescGetRootMemDesc(param_1,0);
  lVar4 = memdescGetMemData(uVar3);
  if (param_2 == '\0') {
    nv_free_user_mapping(uVar5,lVar4,param_3,param_4);
  }
  else {
    nv_free_kernel_mapping();
  }
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x454) != '\0')) {
    iVar2 = memdescGetAddressSpace(uVar3);
    if ((lVar4 != 0) && (iVar2 == 2)) {
      nv_unregister_phys_pages(uVar5,lVar4);
      memdescSetMemData(uVar3,0,0);
      return;
    }
  }
  return;
}


// ===== 00263680 osIsAdministrator =====

void osIsAdministrator(void)

{
  os_is_administrator();
  return;
}


// ===== 00263690 osCheckAccess =====

void osCheckAccess(undefined2 param_1)

{
  os_check_access(param_1);
  return;
}


// ===== 002636a0 osGetCurrentProcess =====

void osGetCurrentProcess(void)

{
  os_get_current_process();
  return;
}


// ===== 002636b0 osGetCurrentProcessName =====

void osGetCurrentProcessName(void)

{
  os_get_current_process_name();
  return;
}


// ===== 002636c0 osGetCurrentThread =====

undefined8 osGetCurrentThread(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  if (param_1 == (undefined8 *)0x0) {
    return 0x1f;
  }
  uVar1 = os_get_current_thread(local_20);
  if ((int)uVar1 == 0) {
    *param_1 = local_20[0];
    return uVar1;
  }
  *param_1 = 0;
  return uVar1;
}


// ===== 00263720 osGetPidInfo =====

void osGetPidInfo(void)

{
  os_get_pid_info();
  return;
}


// ===== 00263730 osPutPidInfo =====

void osPutPidInfo(void)

{
  os_put_pid_info();
  return;
}


// ===== 00263740 osFindNsPid =====

void osFindNsPid(void)

{
  os_find_ns_pid();
  return;
}


// ===== 00263750 osIsInitNs =====

void osIsInitNs(void)

{
  os_is_init_ns();
  return;
}


// ===== 00263760 osAttachToProcess =====

undefined8 osAttachToProcess(undefined8 *param_1)

{
  *param_1 = 0;
  return 0;
}


// ===== 00263770 osDetachFromProcess =====

void osDetachFromProcess(void)

{
  return;
}


// ===== 00263780 osAcquireRmSema =====

undefined8 osAcquireRmSema(void)

{
  return 0;
}


// ===== 00263790 osCondAcquireRmSema =====

undefined8 osCondAcquireRmSema(void)

{
  return 0;
}


// ===== 002637a0 osReleaseRmSema =====

undefined8 osReleaseRmSema(void)

{
  return 0;
}


// ===== 002637b0 osSpinLoop =====

void osSpinLoop(void)

{
  return;
}


// ===== 002637c0 osGetMaxUserVa =====

void osGetMaxUserVa(void)

{
  os_get_max_user_va();
  return;
}


// ===== 002637d0 osSchedule =====

void osSchedule(void)

{
  os_schedule();
  return;
}


// ===== 002637e0 osQueueWorkItem =====

ulong osQueueWorkItem(long param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  undefined4 uVar1;
  ushort *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  puVar2 = (ushort *)portMemAllocNonPaged(0x18);
  if (puVar2 == (ushort *)0x0) {
    uVar3 = 0x51;
  }
  else {
    puVar2[0] = 0;
    puVar2[1] = 0;
    *puVar2 = (ushort)((param_4 >> 3 & 1) << 3) | (ushort)param_4 & 1 | 4 |
              (ushort)((param_4 >> 4 & 3) << 4) | (ushort)((param_4 >> 6 & 1) << 6) |
              (ushort)((param_4 >> 7 & 1) << 7) | (ushort)((param_4 >> 8 & 1) << 8) |
              (ushort)((param_4 >> 9 & 1) << 9) | (ushort)((param_4 >> 10 & 1) << 10);
    uVar1 = *(undefined4 *)(param_1 + 0x7a4);
    *(undefined8 *)(puVar2 + 4) = param_2;
    *(undefined4 *)(puVar2 + 2) = uVar1;
    *(undefined8 *)(puVar2 + 8) = param_3;
    uVar4 = 0;
    if (*(long *)(param_1 + 0x4e0) != 0) {
      uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x4e0) + 0x2f0);
    }
    uVar3 = os_queue_work_item(uVar4,puVar2);
    if ((int)uVar3 != 0) {
      portMemFree(puVar2);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  return uVar3;
}


// ===== 00263900 osQueueSystemWorkItem =====

ulong osQueueSystemWorkItem(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  puVar1 = (undefined4 *)portMemAllocNonPaged(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x51;
  }
  *puVar1 = 0;
  *(undefined8 *)(puVar1 + 2) = param_1;
  *(undefined8 *)(puVar1 + 4) = param_2;
  uVar2 = os_queue_work_item(0,puVar1);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  portMemFree(puVar1);
  return uVar2 & 0xffffffff;
}


// ===== 00263990 osQueueMMUFaultHandler =====

void osQueueMMUFaultHandler(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  nv_schedule_uvm_isr(uVar1);
  return;
}


// ===== 002639a5 osGpuSupportsAts.cold =====

void osGpuSupportsAts_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002639b0 osGpuSupportsAts =====

bool osGpuSupportsAts(long param_1)

{
  code *pcVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (*(char *)(*(long *)(param_1 + 0x4e0) + 0x329) != '\0') {
    return *(char *)(param_1 + 0x45b) != '\0';
  }
  return false;
}


// ===== 002639f0 osQueueDrainP2PHandler =====

void osQueueDrainP2PHandler(void)

{
  nv_schedule_uvm_drain_p2p();
  return;
}


// ===== 00263a00 osQueueResumeP2PHandler =====

void osQueueResumeP2PHandler(void)

{
  nv_schedule_uvm_resume_p2p();
  return;
}


// ===== 00263a10 osDmaSetAddressSize =====

void osDmaSetAddressSize(void)

{
  nv_set_dma_address_size();
  return;
}


// ===== 00263a20 osAllocPagesInternal =====

int osAllocPagesInternal(long *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulong uVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  long lVar16;
  byte bVar17;
  undefined1 uVar18;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  ulong local_40 [2];
  
  lVar4 = g_pSys;
  lVar16 = 0;
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar16 = *(long *)(lVar3 + 0x4e0);
  }
  uVar1 = *(undefined4 *)((long)param_1 + 0x164);
  local_58 = 0;
  iVar8 = memdescGetAddressSpace(param_1);
  uVar2 = *(undefined4 *)((long)param_1 + 0x74);
  memdescSetMemData(param_1,0,0);
  if ((param_1[1] & 0x88000000000000U) == 0) {
    cVar5 = memdescGetFlag(param_1,0x100);
    if (cVar5 == '\0') {
      if ((lVar16 != 0) && (cVar5 = memdescGetFlag(param_1,0x20000000000), cVar5 != '\0')) {
        *(undefined1 *)(lVar16 + 0x300) = 1;
      }
      uVar6 = memdescGetFlag(param_1,0x200000000000);
      if (lVar3 == 0) {
        iVar8 = osGetPagesInfo(param_1,&local_50,&local_48,local_40);
        if (iVar8 != 0) {
          return iVar8;
        }
        uVar9 = memdescGetPteArrayForGpu(param_1,*param_1,0);
        uVar18 = *(undefined1 *)(lVar4 + 0x65);
        uVar7 = memdescGetContiguity(param_1,0);
        uVar11 = 0;
      }
      else {
        if ((*(char *)(lVar3 + 0x45a) != '\0') && (iVar8 == 1)) {
          cVar5 = memdescGetFlag(param_1,0x4000000000);
          if ((cVar5 == '\0') && (*(char *)(lVar16 + 0x330) == '\0')) {
            nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x41d,"osAllocPagesInternal",1,
                         "NVRM: Forcing physically contiguous flags for ISO\n");
            memdescSetContiguity(param_1,0,1);
          }
          cVar5 = memdescGetFlag(param_1,0x4000000000);
          if ((cVar5 != '\0') && (*(char *)(lVar16 + 0x331) == '\0')) {
            nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x424,"osAllocPagesInternal",1,
                         "NVRM: Forcing physically contiguous flags for NISO\n");
            memdescSetContiguity(param_1,0,1);
          }
        }
        iVar8 = osGetPagesInfo(param_1,&local_50,&local_48,local_40);
        if (iVar8 != 0) {
          return iVar8;
        }
        uVar9 = memdescGetPteArrayForGpu(param_1,*param_1,0);
        uVar18 = *(undefined1 *)(lVar4 + 0x65);
        uVar7 = memdescGetContiguity(param_1,0);
        uVar11 = *(undefined8 *)(lVar3 + 0x4e0);
      }
      iVar8 = nv_alloc_pages(uVar11,local_48,local_50,uVar7,uVar2,uVar18,uVar6,uVar1,uVar9,&local_58
                            );
      if ((lVar16 != 0) && (*(char *)(lVar16 + 0x300) != '\0')) {
        *(undefined1 *)(lVar16 + 0x300) = 0;
      }
      goto LAB_00263b69;
    }
    if ((param_1[1] & 0x88000000000000U) != 0) goto LAB_00263a92;
  }
  else {
LAB_00263a92:
    cVar5 = memdescGetContiguity(param_1,0);
    if (cVar5 == '\0') {
      return 0x56;
    }
  }
  iVar8 = osGetPagesInfo(param_1,&local_50,&local_48,local_40);
  if (iVar8 != 0) {
    return iVar8;
  }
  if ((((*(char *)(g_pSys + 400) == '\0') ||
       (cVar5 = memdescGetContiguity(param_1,0), cVar5 != '\0')) && (0x1000 < os_page_size)) &&
     (cVar5 = memdescGetContiguity(param_1,0), uVar12 = local_40[0], cVar5 == '\0')) {
    uVar11 = memdescGetPteArrayForGpu(param_1,*param_1,0);
    RmDeflateRmToOsPageArray(uVar11,uVar12);
  }
  uVar12 = param_1[1];
  uVar9 = memdescGetPteArrayForGpu(param_1,*param_1,0);
  uVar10 = memdescGetGuestId(param_1);
  uVar6 = memdescGetContiguity(param_1,0);
  uVar11 = 0;
  if (lVar3 != 0) {
    uVar11 = *(undefined8 *)(lVar3 + 0x4e0);
  }
  iVar8 = nv_alias_pages(uVar11,local_48,local_50,uVar6,uVar2,uVar10,uVar9,
                         (uVar12 & 0x88000000000000) != 0,&local_58);
LAB_00263b69:
  if (iVar8 != 0) {
    return iVar8;
  }
  memdescSetMemData(param_1,local_58,0);
  cVar5 = memdescGetFlag(param_1,0x100);
  if (cVar5 == '\0') {
    if ((*(char *)(g_pSys + 400) == '\0') ||
       (cVar5 = memdescGetContiguity(param_1,0), uVar12 = os_page_size, cVar5 != '\0')) {
      if (((*(byte *)((long)param_1 + 9) & 4) == 0) &&
         ((ulong)param_1[4] < (local_40[0] & 0xfffffffffffff))) {
        nvAssertOkFailedNoLog
                  (2,"memdescSetAllocSizeFields(pMemDesc, rmPageCount * RM_PAGE_SIZE, RM_PAGE_SIZE)"
                   ,"arch/nvalloc/unix/src/os.c",0x44f);
        return 2;
      }
      param_1[3] = local_40[0] & 0xfffffffffffff;
      param_1[7] = local_40[0] << 0xc;
      *(undefined4 *)(param_1 + 0x2c) = 0x1000;
    }
    else {
      bVar17 = 0xc;
      uVar13 = CONCAT44(uStack_44,local_48) * os_page_size;
      uVar15 = (uint)os_page_size;
      uVar14 = uVar15;
      if (uVar15 != 0x1000) {
        cVar5 = memdescGetContiguity(param_1,0);
        uVar14 = 0x1000;
        if (cVar5 == '\0') {
          bVar17 = (0xffff < uVar15) << 4 | (uVar12 & 0xaaaaaaaa) != 0 |
                   ((uVar12 & 0xff00ff00) != 0) << 3 | ((uVar12 & 0xf0f0f0f0) != 0) << 2 |
                   ((uVar12 & 0xcccccccc) != 0) * '\x02';
          uVar14 = uVar15;
        }
      }
      uVar12 = uVar13 >> bVar17;
      if (((*(byte *)((long)param_1 + 9) & 4) == 0) && ((ulong)param_1[4] < uVar12)) {
        nvAssertOkFailedNoLog
                  (2,"memdescSetAllocSizeFields(pMemDesc, osPageCount * os_page_size, os_page_size)"
                   ,"arch/nvalloc/unix/src/os.c",1099);
        return 2;
      }
      param_1[3] = uVar12;
      param_1[7] = uVar13;
      *(uint *)(param_1 + 0x2c) = uVar14;
    }
  }
  if ((*(char *)(g_pSys + 400) == '\0') || (cVar5 = memdescGetContiguity(param_1,0), cVar5 != '\0'))
  {
    if ((0x1000 < os_page_size) && (cVar5 = memdescGetContiguity(param_1,0), cVar5 == '\0')) {
      lVar16 = param_1[3];
      uVar11 = memdescGetPteArrayForGpu(param_1,*param_1,0);
      RmInflateOsToRmPageArray(uVar11,lVar16);
    }
  }
  else if (*(uint *)(param_1 + 0x2c) != os_page_size) {
    nvAssertOkFailedNoLog
              (0x1f,"pMemDesc->pageArrayGranularity == os_page_size","arch/nvalloc/unix/src/os.c",
               0x459);
    return 0x1f;
  }
  iVar8 = 0;
  if (((lVar3 != 0) && (*(char *)(lVar3 + 0x908) != '\0')) &&
     (iVar8 = vgpuUpdateGuestSysmemPfnBitMap(lVar3,param_1,1), iVar8 != 0)) {
    nvAssertOkFailedNoLog
              (iVar8,"vgpuUpdateGuestSysmemPfnBitMap(pGpu, pMemDesc, NV_TRUE)",
               "arch/nvalloc/unix/src/os.c",0x463);
  }
  return iVar8;
}


// ===== 002640f0 osFreePagesInternal =====

void osFreePagesInternal(long *param_1)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  
  lVar2 = *param_1;
  if ((lVar2 != 0) && (*(char *)(lVar2 + 0x908) != '\0')) {
    iVar6 = vgpuUpdateGuestSysmemPfnBitMap(lVar2,param_1,0);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("vgpuUpdateGuestSysmemPfnBitMap(pGpu, pMemDesc, NV_FALSE) == NV_OK",
                          "arch/nvalloc/unix/src/os.c",0x471);
      return;
    }
  }
  if (*(char *)(g_pSys + 400) != '\0') {
    cVar5 = memdescGetContiguity(param_1,0);
    if (cVar5 == '\0') {
      if (*(uint *)(param_1 + 0x2c) != os_page_size) {
        nvAssertFailedNoLog("pMemDesc->pageArrayGranularity == os_page_size",
                            "arch/nvalloc/unix/src/os.c",0x475);
      }
      uVar9 = param_1[3];
      goto LAB_00264179;
    }
  }
  if (0x1000 < os_page_size) {
    cVar5 = memdescGetContiguity(param_1,0);
    if (cVar5 == '\0') {
      uVar3 = param_1[3];
      uVar9 = (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & uVar3) != 0) +
              (uVar3 >> (os_page_shift - 0xcU & 0x3f));
      uVar8 = memdescGetPteArrayForGpu(param_1,*param_1,0);
      RmDeflateRmToOsPageArray(uVar8,uVar3);
      goto LAB_00264179;
    }
  }
  uVar9 = (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & param_1[3]) != 0) +
          ((ulong)param_1[3] >> (os_page_shift - 0xcU & 0x3f));
LAB_00264179:
  uVar7 = memdescGetMemData(param_1);
  uVar1 = *(undefined4 *)((long)param_1 + 0x74);
  uVar4 = memdescGetContiguity(param_1,0);
  uVar8 = 0;
  if (lVar2 != 0) {
    uVar8 = *(undefined8 *)(lVar2 + 0x4e0);
  }
  iVar6 = nv_free_pages(uVar8,uVar9 & 0xffffffff,uVar4,uVar1,uVar7);
  if (iVar6 == 0) {
    return;
  }
  nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/os.c",0x489);
  return;
}


// ===== 002642f0 osLockMem =====

undefined8 osLockMem(void)

{
  return 0x56;
}


// ===== 00264300 osUnlockMem =====

undefined8 osUnlockMem(void)

{
  return 0x56;
}


// ===== 00264310 osMapPciMemoryAreaUser =====

int osMapPciMemoryAreaUser
              (undefined8 param_1,ulong *param_2,long param_3,undefined8 param_4,undefined4 param_5,
              long *param_6,undefined8 *param_7)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  undefined1 local_88 [40];
  ulong *local_60;
  long local_58;
  ulong local_50;
  long local_48;
  undefined1 local_40;
  undefined4 local_3c;
  
  if (param_3 == 0) {
    *param_6 = 0;
    *param_7 = 0;
    return 0;
  }
  lVar1 = param_3 + -1;
  uVar2 = *param_2;
  uVar6 = -os_page_size & uVar2;
  *param_2 = uVar6;
  param_2[1] = param_2[1] + (uVar2 - uVar6);
  uVar3 = param_2[lVar1 * 2 + 1];
  param_2[lVar1 * 2 + 1] = -os_page_size & os_page_size + -1 + uVar3;
  portMemSet(local_88,0,0x50);
  local_50 = *param_2;
  local_48 = os_page_size;
  local_40 = 1;
  local_60 = param_2;
  local_58 = param_3;
  local_3c = param_5;
  plVar5 = (long *)tlsEntryAcquire(2);
  if (plVar5 == (long *)0x0) {
    nvAssertFailedNoLog("ppNvuap != NULL","arch/nvalloc/unix/src/os.c",0x4cb);
    return 0x40;
  }
  iVar4 = os_alloc_mem(plVar5,0x50);
  if (iVar4 == 0) {
    param_3 = param_3 << 4;
    portMemCopy(*plVar5,0x50,local_88,0x50);
    iVar4 = os_alloc_mem(*plVar5 + 0x28,param_3);
    if (iVar4 == 0) {
      portMemCopy(*(undefined8 *)(*plVar5 + 0x28),param_3,param_2,param_3);
      *param_6 = (uVar2 - uVar6) + *param_2;
      goto LAB_0026448e;
    }
    nvAssertOkFailedNoLog
              (iVar4,"os_alloc_mem((void**) &((*ppNvuap)->memArea.pRanges), totalRangeSize)",
               "arch/nvalloc/unix/src/os.c",0x4d4);
    os_free_mem(*plVar5);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"os_alloc_mem((void**) ppNvuap, sizeof(nv_alloc_mapping_context_t))",
               "arch/nvalloc/unix/src/os.c",0x4cd);
  }
  tlsEntryRelease(2);
LAB_0026448e:
  param_2[lVar1 * 2 + 1] = uVar3;
  param_2[1] = param_2[1] + (uVar6 - uVar2);
  *param_2 = uVar2;
  return iVar4;
}


// ===== 00264570 osMapPciMemoryUser =====

void osMapPciMemoryUser(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_3;
  osMapPciMemoryAreaUser(param_1,&local_18,1,param_4,param_7,param_5,param_6);
  return;
}


// ===== 002645a0 osUnmapPciMemoryUser =====

void osUnmapPciMemoryUser(void)

{
  return;
}


// ===== 002645b0 osMapPciMemoryKernelOld =====

undefined8
osMapPciMemoryKernelOld
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,long *param_5,
          undefined4 param_6)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = 0;
  if (param_1 != 0) {
    lVar3 = *(long *)(param_1 + 0x4e0);
  }
  if (param_5 != (long *)0x0) {
    lVar1 = os_map_kernel_space(param_2,param_3,param_6);
    *param_5 = lVar1;
    if (lVar1 != 0) {
      plVar2 = (long *)portMemAllocNonPaged(0x20);
      if (plVar2 != (long *)0x0) {
        *plVar2 = *param_5;
        plVar2[1] = param_3;
        *(undefined4 *)(plVar2 + 2) = param_6;
        plVar2[3] = *(long *)(lVar3 + 0x2d8);
        *(long **)(lVar3 + 0x2d8) = plVar2;
        return 0;
      }
      os_unmap_kernel_space(*param_5,param_3);
      *param_5 = 0;
    }
  }
  return 0xffff;
}


// ===== 00264690 osMapPciMemoryKernel64 =====

undefined8
osMapPciMemoryKernel64
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,long *param_5,
          undefined4 param_6)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_1 != 0) {
    lVar4 = *(long *)(param_1 + 0x4e0);
  }
  lVar1 = os_map_kernel_space(param_2,param_3,param_6);
  if (lVar1 == 0) {
    uVar3 = 0xffff;
  }
  else {
    plVar2 = (long *)portMemAllocNonPaged(0x20);
    if (plVar2 == (long *)0x0) {
      os_unmap_kernel_space(lVar1,param_3);
      uVar3 = 0xffff;
      lVar1 = 0;
    }
    else {
      *plVar2 = lVar1;
      plVar2[1] = param_3;
      *(undefined4 *)(plVar2 + 2) = param_6;
      plVar2[3] = *(long *)(lVar4 + 0x2d8);
      *(long **)(lVar4 + 0x2d8) = plVar2;
      uVar3 = 0;
    }
  }
  *param_5 = lVar1;
  return uVar3;
}


// ===== 00264760 osUnmapPciMemoryKernelOld =====

void osUnmapPciMemoryKernelOld(long param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  
  lVar5 = 0;
  if (param_1 != 0) {
    lVar5 = *(long *)(param_1 + 0x4e0);
  }
  if (param_2 != 0) {
    plVar1 = *(long **)(lVar5 + 0x2d8);
    plVar2 = plVar1;
    plVar4 = plVar1;
    while (plVar3 = plVar4, plVar4 = plVar2, plVar4 != (long *)0x0) {
      plVar2 = (long *)plVar4[3];
      if (*plVar4 == param_2) {
        if (plVar1 == plVar4) {
          *(long **)(lVar5 + 0x2d8) = plVar2;
        }
        else {
          plVar3[3] = (long)plVar2;
        }
        os_unmap_kernel_space(*plVar4,plVar4[1]);
        portMemFree(plVar4);
        return;
      }
    }
  }
  return;
}


// ===== 00264800 osUnmapPciMemoryKernel64 =====

void osUnmapPciMemoryKernel64(void)

{
  osUnmapPciMemoryKernelOld();
  return;
}


// ===== 00264810 osMapGPU =====

undefined1  [16]
osMapGPU(long param_1,uint param_2,ulong param_3,undefined8 param_4,undefined4 param_5,long *param_6
        ,undefined8 param_7)

{
  ulong uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  long local_18;
  undefined8 local_10;
  
  if (1 < param_2) {
    uVar1 = *(ulong *)(param_1 + 0x938);
    auVar2._8_8_ = param_3 + *(ulong *)(param_1 + 0x938);
    *param_6 = auVar2._8_8_;
    auVar2._0_4_ = -(uint)CARRY8(param_3,uVar1) & 0x2e;
    auVar2._4_4_ = 0;
    return auVar2;
  }
  auVar4._8_8_ = param_3 + *(ulong *)(param_1 + 0x848);
  if (!CARRY8(param_3,*(ulong *)(param_1 + 0x848))) {
    local_18 = auVar4._8_8_;
    local_10 = param_4;
    auVar3._0_8_ = osMapPciMemoryAreaUser(*(undefined8 *)(param_1 + 0x4e0),&local_18,1,param_5,1);
    auVar3._8_8_ = param_7;
    return auVar3;
  }
  auVar4._0_8_ = 0x2e;
  return auVar4;
}


// ===== 00264880 osUnmapGPU =====

void osUnmapGPU(void)

{
  return;
}


// ===== 00264890 osDereferenceObjectCount =====

undefined8 osDereferenceObjectCount(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = nv_get_ctl_state();
  portSyncSpinlockAcquire(*(undefined8 *)(lVar2 + 0x2d0));
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
    nvAssertFailedNoLog("event->refcount > 0","arch/nvalloc/unix/src/os.c",0x6aa);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  *(int *)(param_1 + 0x28) = iVar1 + -1;
  if ((iVar1 + -1 == 0) && (*(char *)(param_1 + 0x24) == '\0')) {
    portMemFree(param_1);
  }
  portSyncSpinlockRelease(*(undefined8 *)(lVar2 + 0x2d0));
  return 0;
}


// ===== 00264910 osNotifyEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 osNotifyEvent(long param_1,long param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  
  iVar2 = *(int *)(param_2 + 0x10);
  if (iVar2 == 0x79) {
    lVar6 = *(long *)(param_2 + 0x28);
    uVar1 = *(undefined1 *)(param_2 + 0x1c);
    uVar3 = *(undefined4 *)(param_2 + 0xc);
    uVar4 = *(undefined4 *)(param_2 + 4);
    lVar7 = nv_get_ctl_state();
    portSyncSpinlockAcquire(*(undefined8 *)(lVar7 + 0x2d0));
    if (*(char *)(lVar6 + 0x24) != '\0') {
      *(int *)(lVar6 + 0x28) = *(int *)(lVar6 + 0x28) + 1;
      portSyncSpinlockRelease(*(undefined8 *)(lVar7 + 0x2d0));
      nv_post_event(lVar6,uVar4,uVar3,0,0,uVar1);
      uVar8 = osDereferenceObjectCount(lVar6);
      return uVar8;
    }
    portSyncSpinlockRelease(*(undefined8 *)(lVar7 + 0x2d0));
  }
  else if (iVar2 == 0x7e) {
    puVar5 = *(undefined8 **)(param_2 + 0x28);
    if ((puVar5 != (undefined8 *)0x0) && ((code *)*puVar5 != (code *)0x0)) {
      (*(code *)*puVar5)(puVar5[1],0,*(undefined4 *)(param_2 + 4));
    }
  }
  else {
    if (iVar2 != 0x78) {
      return 0xffff;
    }
    if (*(code **)(param_2 + 0x28) != (code *)0x0) {
      uVar8 = 0;
      if (param_1 != 0) {
        uVar8 = *(undefined8 *)(param_1 + 0x4e0);
      }
      (**(code **)(param_2 + 0x28))(uVar8);
    }
  }
  return 0;
}


// ===== 00264a30 osSetEvent =====

undefined8 osSetEvent(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = nv_get_ctl_state();
  portSyncSpinlockAcquire(*(undefined8 *)(lVar1 + 0x2d0));
  if (*(char *)(param_2 + 0x24) != '\0') {
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 1;
    portSyncSpinlockRelease(*(undefined8 *)(lVar1 + 0x2d0));
    nv_post_event(param_2,0,0,0,0,0);
    osDereferenceObjectCount(param_2);
    return 1;
  }
  portSyncSpinlockRelease(*(undefined8 *)(lVar1 + 0x2d0));
  return 1;
}


// ===== 00264ab0 osObjectEventNotification =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 osObjectEventNotification(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  long lVar5;
  long lVar6;
  long in_RCX;
  int in_R8D;
  undefined8 in_R9;
  
  nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x668,"osObjectEventNotification",1,"NVRM: %s()\n");
  do {
    if (in_RCX == 0) {
      return 0;
    }
    if (in_R8D != -1) {
      while (*(int *)(in_RCX + 0xc) != in_R8D) {
        in_RCX = *(long *)(in_RCX + 0x40);
        if (in_RCX == 0) {
          return 0;
        }
      }
    }
    if (*(int *)(in_RCX + 0x10) == 0x79) {
      uVar2 = *(undefined4 *)(in_RCX + 4);
      lVar5 = *(long *)(in_RCX + 0x28);
      uVar1 = *(undefined1 *)(in_RCX + 0x1c);
      uVar3 = *(undefined4 *)(in_RCX + 0xc);
      lVar6 = nv_get_ctl_state();
      portSyncSpinlockAcquire(*(undefined8 *)(lVar6 + 0x2d0));
      if (*(char *)(lVar5 + 0x24) == '\0') {
        portSyncSpinlockRelease(*(undefined8 *)(lVar6 + 0x2d0));
      }
      else {
        *(int *)(lVar5 + 0x28) = *(int *)(lVar5 + 0x28) + 1;
        portSyncSpinlockRelease(*(undefined8 *)(lVar6 + 0x2d0));
        nv_post_event(lVar5,uVar2,uVar3,0,0,uVar1);
        osDereferenceObjectCount(lVar5);
      }
    }
    else if (((*(int *)(in_RCX + 0x10) == 0x7e) &&
             (puVar4 = *(undefined8 **)(in_RCX + 0x28), puVar4 != (undefined8 *)0x0)) &&
            ((code *)*puVar4 != (code *)0x0)) {
      (*(code *)*puVar4)(puVar4[1],in_R9,*(undefined4 *)(in_RCX + 4));
    }
    in_RCX = *(long *)(in_RCX + 0x40);
  } while( true );
}


// ===== 00264c20 osEventNotificationWithInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8
osEventNotificationWithInfo
          (long param_1,long param_2,int param_3,undefined4 param_4,undefined2 param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 *puVar6;
  code *pcVar7;
  long lVar8;
  undefined8 uVar9;
  
  if (param_2 == 0) {
    return 0;
  }
  do {
    if (param_3 != -1) {
      while (*(int *)(param_2 + 0xc) != param_3) {
        param_2 = *(long *)(param_2 + 0x40);
        if (param_2 == 0) {
          return 0;
        }
      }
    }
    uVar2 = *(uint *)(param_2 + 0x10);
    if (uVar2 == 0x7e) {
      puVar6 = *(undefined8 **)(param_2 + 0x28);
      if ((puVar6 != (undefined8 *)0x0) && (pcVar7 = (code *)*puVar6, pcVar7 != (code *)0x0)) {
        (*pcVar7)(puVar6[1],param_6,*(undefined4 *)(param_2 + 4),0,0,pcVar7,param_6,param_4);
      }
    }
    else if (uVar2 < 0x7f) {
      if (uVar2 == 0x78) {
        if (*(code **)(param_2 + 0x28) != (code *)0x0) {
          uVar9 = 0;
          if (param_1 != 0) {
            uVar9 = *(undefined8 *)(param_1 + 0x4e0);
          }
          (**(code **)(param_2 + 0x28))(uVar9);
        }
      }
      else if (uVar2 == 0x79) goto LAB_00264cb1;
    }
    else if (uVar2 == 0x7f) {
LAB_00264cb1:
      uVar3 = *(undefined4 *)(param_2 + 0xc);
      lVar5 = *(long *)(param_2 + 0x28);
      uVar1 = *(undefined1 *)(param_2 + 0x1c);
      uVar4 = *(undefined4 *)(param_2 + 4);
      lVar8 = nv_get_ctl_state();
      portSyncSpinlockAcquire(*(undefined8 *)(lVar8 + 0x2d0));
      if (*(char *)(lVar5 + 0x24) == '\0') {
        portSyncSpinlockRelease();
      }
      else {
        *(int *)(lVar5 + 0x28) = *(int *)(lVar5 + 0x28) + 1;
        portSyncSpinlockRelease(*(undefined8 *)(lVar8 + 0x2d0));
        nv_post_event(lVar5,uVar4,uVar3,param_4,param_5,uVar1);
        osDereferenceObjectCount();
      }
    }
    param_2 = *(long *)(param_2 + 0x40);
    if (param_2 == 0) {
      return 0;
    }
  } while( true );
}


// ===== 00264dc0 osEventNotification =====

undefined8 osEventNotification(void)

{
  osEventNotificationWithInfo();
  return 0;
}


// ===== 00264de0 osUserHandleToKernelPtr =====

undefined4 osUserHandleToKernelPtr(int param_1,int param_2,undefined8 *param_3)

{
  int *piVar1;
  long lVar2;
  undefined4 uVar3;
  
  lVar2 = nv_get_ctl_state();
  portSyncSpinlockAcquire(*(undefined8 *)(lVar2 + 0x2d0));
  piVar1 = *(int **)(lVar2 + 0x2c8);
  do {
    if (piVar1 == (int *)0x0) {
      uVar3 = 0x57;
LAB_00264e3c:
      portSyncSpinlockRelease(*(undefined8 *)(lVar2 + 0x2d0));
      return uVar3;
    }
    if ((piVar1[8] == param_2) && (*piVar1 == param_1)) {
      piVar1[10] = piVar1[10] + 1;
      uVar3 = 0;
      *param_3 = piVar1;
      goto LAB_00264e3c;
    }
    piVar1 = *(int **)(piVar1 + 0xc);
  } while( true );
}


// ===== 00264e60 osFlushCpuCache =====

void osFlushCpuCache(void)

{
  os_flush_cpu_cache_all();
  return;
}


// ===== 00264e70 osFlushCpuWriteCombineBuffer =====

void osFlushCpuWriteCombineBuffer(void)

{
  os_flush_cpu_write_combine_buffer();
  return;
}


// ===== 00264e80 osFlushGpuCoherentCpuCacheRange =====

void osFlushGpuCoherentCpuCacheRange(void)

{
  nv_flush_coherent_cpu_cache_range();
  return;
}


// ===== 00264e90 osErrorLogV =====

void osErrorLogV(long param_1,undefined8 param_2,undefined8 param_3,char *param_4,undefined8 param_5
                )

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x4e0);
  }
  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
    iVar1 = nv_log_error(uVar2,param_2,param_4,param_5);
    if (iVar1 == 0) {
      return;
    }
    nvAssertFailedNoLog("rmStatus == NV_OK","arch/nvalloc/unix/src/os.c",0x705);
    return;
  }
  return;
}


// ===== 00264ef0 osDevWriteReg008 =====

void osDevWriteReg008(undefined8 param_1,long *param_2,uint param_3,undefined1 param_4)

{
  if ((ulong)param_3 < (ulong)param_2[2]) {
    *(undefined1 *)(*param_2 + (ulong)param_3) = param_4;
    return;
  }
  nvAssertFailedNoLog("thisAddress < pMapping->gpuNvLength","arch/nvalloc/unix/src/os.c",0x722);
  return;
}


// ===== 00264f20 osDevWriteReg016 =====

void osDevWriteReg016(undefined8 param_1,long *param_2,ulong param_3,undefined2 param_4)

{
  if ((param_3 & 0xffffffff) < (ulong)param_2[2]) {
    *(undefined2 *)(*param_2 + (param_3 >> 1 & 0x7fffffff) * 2) = param_4;
    return;
  }
  nvAssertFailedNoLog("thisAddress < pMapping->gpuNvLength","arch/nvalloc/unix/src/os.c",0x732);
  return;
}


// ===== 00264f60 osDevWriteReg032 =====

void osDevWriteReg032(undefined8 param_1,long *param_2,uint param_3,undefined4 param_4)

{
  char local_29 [9];
  
  local_29[0] = '\0';
  vgpuDevWriteReg032(param_1,param_3,param_4,local_29);
  if (local_29[0] == '\0') {
    if ((ulong)param_2[2] <= (ulong)param_3) {
      nvAssertFailedNoLog("thisAddress < pMapping->gpuNvLength","arch/nvalloc/unix/src/os.c",0x74a);
      return;
    }
    *(undefined4 *)(*param_2 + (ulong)(param_3 >> 2) * 4) = param_4;
  }
  return;
}


// ===== 00264fe0 osDevReadReg008 =====

undefined1 osDevReadReg008(undefined8 param_1,long *param_2,uint param_3)

{
  if ((ulong)param_3 < (ulong)param_2[2]) {
    return *(undefined1 *)(*param_2 + (ulong)param_3);
  }
  nvAssertFailedNoLog("thisAddress < pMapping->gpuNvLength","arch/nvalloc/unix/src/os.c",0x75b);
  return 0;
}


// ===== 00265020 osDevReadReg016 =====

undefined2 osDevReadReg016(undefined8 param_1,long *param_2,ulong param_3)

{
  if ((param_3 & 0xffffffff) < (ulong)param_2[2]) {
    return *(undefined2 *)(*param_2 + (param_3 >> 1 & 0x7fffffff) * 2);
  }
  nvAssertFailedNoLog("thisAddress < pMapping->gpuNvLength","arch/nvalloc/unix/src/os.c",0x76d);
  return 0;
}


// ===== 00265060 osDevReadReg032 =====

ulong osDevReadReg032(undefined8 param_1,long *param_2,uint param_3)

{
  ulong uVar1;
  char local_19;
  
  local_19 = '\0';
  uVar1 = vgpuDevReadReg032(param_1,param_3,&local_19);
  if (local_19 == '\0') {
    if ((ulong)param_2[2] <= (ulong)param_3) {
      nvAssertFailedNoLog("thisAddress < pMapping->gpuNvLength","arch/nvalloc/unix/src/os.c",0x786);
      return uVar1 & 0xffffffff;
    }
    uVar1 = (ulong)*(uint *)(*param_2 + (ulong)(param_3 >> 2) * 4);
  }
  return uVar1;
}


// ===== 002650d0 osReadRegistryDwordBase =====

void osReadRegistryDwordBase(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  RmReadRegistryDword(uVar1);
  return;
}


// ===== 002650f0 osWriteRegistryDword =====

void osWriteRegistryDword(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  RmWriteRegistryDword(uVar1);
  return;
}


// ===== 00265110 osReadRegistryBinary =====

void osReadRegistryBinary(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  RmReadRegistryBinary(uVar1);
  return;
}


// ===== 00265130 osWriteRegistryBinary =====

void osWriteRegistryBinary(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  RmWriteRegistryBinary(uVar1);
  return;
}


// ===== 00265150 osWriteRegistryVolatile =====

undefined8 osWriteRegistryVolatile(void)

{
  return 0x56;
}


// ===== 00265160 osReadRegistryVolatile =====

undefined8 osReadRegistryVolatile(void)

{
  return 0x56;
}


// ===== 00265170 osReadRegistryVolatileSize =====

undefined8 osReadRegistryVolatileSize(void)

{
  return 0x56;
}


// ===== 00265180 osReadRegistryStringBase =====

void osReadRegistryStringBase(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  RmReadRegistryString(uVar1);
  return;
}


// ===== 002651a0 osPackageRegistry =====

void osPackageRegistry(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  RmPackageRegistry(uVar1);
  return;
}


// ===== 002651c0 osGetCpuCount =====

void osGetCpuCount(void)

{
  os_get_cpu_count();
  return;
}


// ===== 002651d0 osGetCurrentProcessorNumber =====

void osGetCurrentProcessorNumber(void)

{
  os_get_cpu_number();
  return;
}


// ===== 002651e0 osGetTimeoutParams =====

void osGetTimeoutParams(long param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x1b20) < 1) {
    cVar1 = hypervisorIsVgxHyper_IMPL();
    uVar2 = -(uint)(cVar1 == '\0') & 2200000;
  }
  else {
    cVar1 = hypervisorIsVgxHyper_IMPL();
    uVar2 = -(uint)(cVar1 == '\0') & 28200000;
  }
  *param_2 = uVar2 + 1800000;
  *param_4 = 8;
  *param_3 = 1;
  if ((*(char *)(param_1 + 0x446) != '\0') || (*(char *)(param_1 + 0x490e) != '\0')) {
    *param_3 = 0x3c;
  }
  return;
}


// ===== 00265265 cliresCtrlCmdOsUnixFlushUserCache_IMPL.cold =====

void cliresCtrlCmdOsUnixFlushUserCache_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00265280 cliresCtrlCmdOsUnixFlushUserCache_IMPL =====

int cliresCtrlCmdOsUnixFlushUserCache_IMPL(long param_1,long *param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  iVar6 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),(int)param_2[3],
                              &local_20);
  if (iVar6 != 0) {
    return iVar6;
  }
  plVar1 = *(long **)(local_20 + 0x118);
  iVar6 = memdescGetAddressSpace(plVar1);
  if (iVar6 == 1) {
    if (*(int *)((long)plVar1 + 0x74) == 0) {
      uVar2 = param_2[1];
      if (*(uint *)(param_2 + 2) == 2) {
        uVar8 = *(ulong *)(local_20 + 0x100);
        if (uVar2 <= uVar8) {
          if (*plVar1 == 0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)invalidInstructionException();
            (*pcVar4)();
          }
          lVar3 = *(long *)(*plVar1 + 0x4e0);
          if ((((*(int *)(lVar3 + 0x28) != -1) && (lVar7 = memdescGetIommuMap(plVar1), lVar7 != 0))
              && (*(long *)(lVar7 + 0x20) != 0)) &&
             ((cVar5 = memdescGetFlag(*(undefined8 *)(lVar7 + 8),0x100), cVar5 == '\0' &&
              (cVar5 = memdescGetFlag(*(undefined8 *)(lVar7 + 8),0x80000000), cVar5 == '\0')))) {
            nv_dma_cache_invalidate(*(undefined8 *)(lVar3 + 0x2e0),*(undefined8 *)(lVar7 + 0x20));
            return 0;
          }
          return 0x1f;
        }
      }
      else {
        if ((*(uint *)(param_2 + 2) & 0xfffffffd) != 1) {
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x87c,"cliresCtrlCmdOsUnixFlushUserCache_IMPL",4
                       ,"NVRM: %s: cacheOps not specified\n");
          return 0x24;
        }
        uVar8 = *(ulong *)(local_20 + 0x100);
        if (uVar2 <= uVar8) {
          iVar6 = os_flush_user_cache();
          return iVar6;
        }
      }
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x882,"cliresCtrlCmdOsUnixFlushUserCache_IMPL",4,
                   "NVRM: %s: end address 0x%llx exceeded buffer length: 0x%llx\n",
                   "cliresCtrlCmdOsUnixFlushUserCache_IMPL",uVar2 + *param_2,uVar8);
      return 0x2e;
    }
    nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x868,"cliresCtrlCmdOsUnixFlushUserCache_IMPL",4,
                 "NVRM: %s: wrong caching type %d\n","cliresCtrlCmdOsUnixFlushUserCache_IMPL",
                 *(int *)((long)plVar1 + 0x74));
  }
  else {
    uVar9 = memdescGetAddressSpace(plVar1);
    nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x861,"cliresCtrlCmdOsUnixFlushUserCache_IMPL",4,
                 "NVRM: %s: wrong address space %d\n","cliresCtrlCmdOsUnixFlushUserCache_IMPL",uVar9
                );
  }
  return 0x24;
}


// ===== 002654c5 cliresCtrlCmdOsUnixExportObjectToFd_IMPL.cold =====

void cliresCtrlCmdOsUnixExportObjectToFd_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002654d0 cliresCtrlCmdOsUnixExportObjectToFd_IMPL =====

ulong cliresCtrlCmdOsUnixExportObjectToFd_IMPL(long param_1,int *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  ulong uVar3;
  long *plVar4;
  int local_24;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  local_24 = 0;
  local_20 = 0;
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48);
  if ((((*(byte *)(param_2 + 5) & 1) != 0) || (*param_2 != 1)) || (param_2[4] == -1)) {
    return 0x3b;
  }
  uVar3 = RmExportObject(uVar1,param_2[3],&local_24,0);
  if ((int)uVar3 == 0) {
    if (local_24 == 0) {
      nvAssertFailedNoLog("hExportHandle != 0","arch/nvalloc/unix/src/os.c",0x925);
    }
    plVar4 = (long *)nv_get_file_private(param_2[4],1,&local_20);
    if (plVar4 != (long *)0x0) {
      if (*plVar4 == 0) {
        uVar3 = _initializeExportObjectFd_part_0(plVar4,uVar1,param_2[1],1,0);
        if ((int)uVar3 == 0) {
          *(int *)*plVar4 = local_24;
          goto joined_r0x002655fe;
        }
      }
      else {
        uVar3 = 99;
      }
      goto LAB_002655e5;
    }
    if (local_20 != 0) {
      nvAssertFailedNoLog("priv == NULL","arch/nvalloc/unix/src/os.c",0x92a);
      uVar3 = 0x3b;
      goto LAB_002655e5;
    }
    if (local_24 == 0) {
      return 0x3b;
    }
    uVar3 = 0x3b;
  }
  else {
LAB_002655e5:
    if (local_24 == 0) goto joined_r0x002655fe;
  }
  RmFreeObjExportHandle();
  uVar3 = uVar3 & 0xffffffff;
joined_r0x002655fe:
  if (local_20 != 0) {
    nv_put_file_private();
    return uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 00265656 cliresCtrlCmdOsUnixCreateExportObjectFd_IMPL.cold =====

void cliresCtrlCmdOsUnixCreateExportObjectFd_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00265660 cliresCtrlCmdOsUnixCreateExportObjectFd_IMPL =====

ulong cliresCtrlCmdOsUnixCreateExportObjectFd_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  long *plVar3;
  ulong uVar4;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  local_20 = 0;
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48);
  if (*(short *)(param_2 + 1) == 0) {
    return 0x3b;
  }
  plVar3 = (long *)nv_get_file_private(param_2[0x12],1,&local_20);
  if (plVar3 == (long *)0x0) {
    if (local_20 == 0) {
      return 0x3b;
    }
    nvAssertFailedNoLog("priv == NULL","arch/nvalloc/unix/src/os.c",0x95f);
    uVar4 = 0x3b;
  }
  else {
    uVar4 = 99;
    if (*plVar3 == 0) {
      uVar4 = _initializeExportObjectFd_part_0
                        (plVar3,uVar1,*param_2,*(undefined2 *)(param_2 + 1),(long)param_2 + 6);
    }
  }
  if (local_20 != 0) {
    nv_put_file_private();
    return uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 0026573f cliresCtrlCmdOsUnixExportObjectsToFd_IMPL.cold =====

void cliresCtrlCmdOsUnixExportObjectsToFd_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00265780 cliresCtrlCmdOsUnixExportObjectsToFd_IMPL =====

int cliresCtrlCmdOsUnixExportObjectsToFd_IMPL(long param_1,undefined4 *param_2)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  int local_4c;
  long local_48;
  long local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  local_48 = 0;
  local_40[0] = 0;
  uVar3 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48);
  plVar8 = (long *)nv_get_file_private(*param_2,1,&local_48);
  if (plVar8 == (long *)0x0) {
    if (local_48 == 0) {
      if (local_40[0] == 0) {
        return 0x3b;
      }
    }
    else {
      nvAssertFailedNoLog("priv == NULL","arch/nvalloc/unix/src/os.c",0x985);
      if (local_40[0] == 0) goto LAB_002658d0;
    }
LAB_002658ae:
    iVar6 = 0x3b;
    bVar5 = false;
    if (*(short *)(param_2 + 0x213) != 0) goto LAB_00265846;
    os_free_mem(local_40[0]);
LAB_002658d0:
    iVar6 = 0x3b;
    goto LAB_002658e0;
  }
  if (*plVar8 == 0) {
    if (*(short *)(param_2 + 2) == 0) {
      if (local_40[0] != 0) goto LAB_002658ae;
      goto LAB_002658d0;
    }
    iVar6 = _initializeExportObjectFd_part_0
                      (plVar8,uVar3,param_2[1],*(short *)(param_2 + 2),(long)param_2 + 10);
    if (iVar6 != 0) {
      if (local_40[0] == 0) goto LAB_002658e0;
      bVar5 = false;
      if (*(short *)(param_2 + 0x213) == 0) goto LAB_00265b22;
LAB_00265846:
      lVar9 = 0;
      lVar10 = local_40[0];
      do {
        if (*(int *)(lVar10 + lVar9 * 4) != 0) {
          RmFreeObjExportHandle();
          lVar10 = local_40[0];
        }
        lVar9 = lVar9 + 1;
      } while ((uint)lVar9 < (uint)*(ushort *)(param_2 + 0x213));
      if (lVar10 != 0) goto LAB_00265a45;
      goto LAB_00265a4d;
    }
    if (*plVar8 != 0) {
      uVar2 = *(ushort *)(param_2 + 0x213);
      bVar5 = true;
      if (uVar2 < 0x201) goto LAB_002657ff;
      if (local_40[0] == 0) goto LAB_00265a2f;
      iVar6 = 0x3b;
      bVar5 = true;
      goto LAB_00265846;
    }
    if (local_40[0] != 0) {
      iVar6 = 0x3b;
      bVar5 = true;
      if (*(short *)(param_2 + 0x213) != 0) goto LAB_00265846;
      os_free_mem(local_40[0]);
    }
LAB_00265a2f:
    iVar6 = 0x3b;
  }
  else {
    uVar2 = *(ushort *)(param_2 + 0x213);
    bVar5 = false;
    if (0x200 < uVar2) {
      iVar6 = 0x3b;
      bVar5 = false;
      if (local_40[0] != 0) goto LAB_00265846;
      goto LAB_002658d0;
    }
LAB_002657ff:
    if ((uint)*(ushort *)(plVar8 + 1) < (uint)*(ushort *)((long)param_2 + 0x84e) + (uint)uVar2) {
      iVar7 = 0x5b;
    }
    else {
      iVar6 = os_alloc_mem(local_40,(ulong)uVar2 * 4);
      iVar7 = iVar6;
      if (iVar6 == 0) {
        if (*(short *)(param_2 + 0x213) != 0) {
          lVar10 = 0;
          do {
            *(undefined4 *)(local_40[0] + lVar10 * 4) = 0;
            if (param_2[lVar10 + 0x13] != 0) {
              iVar7 = RmExportObject(uVar3,param_2[lVar10 + 0x13],lVar10 * 4 + local_40[0],&local_4c
                                    );
              if (iVar7 != 0) goto LAB_00265829;
              if (*(int *)(local_40[0] + lVar10 * 4) == 0) {
                nvAssertFailedNoLog("exportHandles[i] != 0","arch/nvalloc/unix/src/os.c",0x9c9);
              }
              if (*(int *)((long)plVar8 + 0xc) != local_4c) {
                iVar7 = 0x3b;
                goto LAB_00265829;
              }
            }
            lVar10 = lVar10 + 1;
          } while ((uint)lVar10 < (uint)*(ushort *)(param_2 + 0x213));
          if (*(ushort *)(param_2 + 0x213) != 0) {
            lVar10 = 0;
            do {
              piVar1 = (int *)(*plVar8 +
                              (ulong)((uint)*(ushort *)((long)param_2 + 0x84e) + (int)lVar10) * 4);
              if (*piVar1 != 0) {
                RmFreeObjExportHandle();
                *piVar1 = 0;
              }
              lVar9 = lVar10 * 4;
              lVar10 = lVar10 + 1;
              *piVar1 = *(int *)(local_40[0] + lVar9);
            } while ((uint)lVar10 < (uint)*(ushort *)(param_2 + 0x213));
          }
        }
        if (local_40[0] == 0) goto LAB_002658e0;
LAB_00265b22:
        os_free_mem(local_40[0]);
        goto LAB_002658e0;
      }
    }
LAB_00265829:
    iVar6 = iVar7;
    if (local_40[0] != 0) {
      lVar10 = local_40[0];
      if (*(short *)(param_2 + 0x213) != 0) goto LAB_00265846;
LAB_00265a45:
      os_free_mem(lVar10);
    }
LAB_00265a4d:
    if (!bVar5) goto LAB_002658e0;
  }
  os_free_mem(*plVar8);
  *plVar8 = 0;
  *(undefined2 *)(plVar8 + 1) = 0;
LAB_002658e0:
  if (local_48 != 0) {
    nv_put_file_private();
  }
  return iVar6;
}


// ===== 00265bc4 cliresCtrlCmdOsUnixImportObjectFromFd_IMPL.cold =====

void cliresCtrlCmdOsUnixImportObjectFromFd_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00265bd0 cliresCtrlCmdOsUnixImportObjectFromFd_IMPL =====

ulong cliresCtrlCmdOsUnixImportObjectFromFd_IMPL(long param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  local_20 = 0;
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48);
  if ((param_2[1] != 1) || (*param_2 == -1)) {
    return 0x3b;
  }
  puVar4 = (undefined8 *)nv_get_file_private(*param_2,1,&local_20);
  if (puVar4 == (undefined8 *)0x0) {
    if (local_20 == 0) {
      return 0x3b;
    }
    nvAssertFailedNoLog("priv == NULL","arch/nvalloc/unix/src/os.c",0xa16);
  }
  else if ((((int *)*puVar4 != (int *)0x0) && (iVar2 = *(int *)*puVar4, iVar2 != 0)) &&
          (*(short *)(puVar4 + 1) != 0)) {
    uVar5 = RmImportObject(uVar1,param_2[3],param_2 + 4,iVar2,0);
    goto joined_r0x00265c99;
  }
  uVar5 = 0x3b;
joined_r0x00265c99:
  if (local_20 != 0) {
    nv_put_file_private();
    return uVar5 & 0xffffffff;
  }
  return uVar5;
}


// ===== 00265cc2 cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL.cold =====

void cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00265d00 cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL(long param_1,undefined4 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  undefined4 *puVar9;
  int iVar10;
  ulong uVar11;
  int *piVar12;
  long local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  local_40[0] = 0;
  uVar3 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48);
  plVar7 = (long *)nv_get_file_private(*param_2,1,local_40);
  if (plVar7 == (long *)0x0) {
    if (local_40[0] != 0) {
      nvAssertFailedNoLog("priv == NULL","arch/nvalloc/unix/src/os.c",0xa43);
    }
  }
  else {
    lVar8 = *plVar7;
    if ((lVar8 != 0) && (uVar1 = *(ushort *)(param_2 + 0xa2), uVar1 < 0x81)) {
      uVar2 = *(ushort *)((long)param_2 + 0x28a);
      if ((uint)*(ushort *)(plVar7 + 1) < (uint)uVar1 + (uint)uVar2) {
        iVar6 = 0x5b;
        rmapiGetInterface(3);
      }
      else {
        if (uVar1 != 0) {
          puVar9 = param_2 + 2;
          uVar11 = 0;
          while( true ) {
            iVar10 = (int)uVar11;
            iVar4 = *(int *)(lVar8 + (ulong)((uint)uVar2 + iVar10) * 4);
            if (iVar4 == 0) {
              *(undefined1 *)((long)param_2 + (uVar11 & 0xffffffff) + 0x208) = 0;
            }
            else {
              iVar6 = RmImportObject(uVar3,param_2[1],puVar9,iVar4,(long)param_2 + uVar11 + 0x208);
              if (iVar6 != 0) {
                nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xa6a,
                             "cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL",4,
                             "NVRM: %s: Unable to import handle (%x, %x, %x)\n",
                             "cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL",param_2[1],
                             param_2[(uVar11 & 0xffffffff) + 2],iVar4);
                lVar8 = rmapiGetInterface(3);
                if (iVar10 != 0) {
                  piVar12 = param_2 + (ulong)(iVar10 - 1) + 2;
                  do {
                    if (*piVar12 != 0) {
                      (**(code **)(lVar8 + 0x18))(lVar8,uVar3);
                    }
                    piVar12 = piVar12 + -1;
                  } while (param_2 + 1 != piVar12);
                }
                goto LAB_00265ee7;
              }
            }
            uVar11 = uVar11 + 1;
            if ((uint)*(ushort *)(param_2 + 0xa2) <= (uint)uVar11) break;
            uVar2 = *(ushort *)((long)param_2 + 0x28a);
            lVar8 = *plVar7;
            puVar9 = puVar9 + 1;
          }
        }
        iVar6 = 0;
      }
      goto LAB_00265ee7;
    }
  }
  iVar6 = 0x3b;
  rmapiGetInterface(3);
LAB_00265ee7:
  if (local_40[0] != 0) {
    nv_put_file_private();
  }
  return iVar6;
}


// ===== 00265f50 cliresCtrlCmdOsUnixGetExportObjectInfo_IMPL =====

undefined8 cliresCtrlCmdOsUnixGetExportObjectInfo_IMPL(undefined8 param_1,int *param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long local_20 [2];
  
  local_20[0] = 0;
  if (*param_2 < 0) {
    return 0x3b;
  }
  plVar1 = (long *)nv_get_file_private(*param_2,1,local_20);
  if (plVar1 == (long *)0x0) {
    if (local_20[0] == 0) {
      return 0x3b;
    }
    nvAssertFailedNoLog("priv == NULL","arch/nvalloc/unix/src/os.c",0xa9b);
  }
  else if (*plVar1 != 0) {
    *(short *)(param_2 + 3) = (short)plVar1[1];
    param_2[1] = *(int *)((long)plVar1 + 0xc);
    param_2[2] = (int)plVar1[2];
    uVar2 = 0;
    os_mem_copy((long)param_2 + 0xe,(long)plVar1 + 0x14,0x40);
    goto LAB_00265faf;
  }
  uVar2 = 0x3b;
LAB_00265faf:
  if (local_20[0] != 0) {
    nv_put_file_private();
  }
  return uVar2;
}


// ===== 00266010 osCallACPI_DSM =====

ulong osCallACPI_DSM(long param_1,uint param_2,int param_3,undefined8 param_4,short *param_5)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  long lVar8;
  long *plVar9;
  int local_40;
  uint local_3c [3];
  
  if (param_1 == 0) {
    plVar9 = (long *)0x0;
    lVar8 = 0;
  }
  else {
    plVar9 = *(long **)(param_1 + 0x4e0);
    lVar8 = 0;
    if (plVar9 != (long *)0x0) {
      lVar8 = *plVar9;
    }
  }
  local_40 = param_3;
  local_3c[0] = param_2;
  uVar3 = checkDsmCall(param_1,local_3c,&local_40,param_4,param_5);
  if (uVar3 == 0x10005) {
    if (local_3c[0] == 6) {
      sVar2 = *param_5;
      uVar5 = 0;
      uVar6 = 0x200;
      puVar7 = GPS_DSM_GUID;
    }
    else if (local_3c[0] < 7) {
      if (local_3c[0] == 3) {
        uVar5 = 0;
        sVar2 = 4;
        uVar6 = 0x102;
        puVar7 = NBCI_DSM_GUID;
      }
      else if (local_3c[0] < 4) {
        if (local_3c[0] == 1) {
          uVar5 = 0;
          sVar2 = 4;
          uVar6 = 0x102;
          puVar7 = NVHG_DSM_GUID;
        }
        else if (local_3c[0] == 2) {
          uVar5 = 0;
          sVar2 = 4;
          uVar6 = 0x300;
          puVar7 = DSM_MXM_GUID;
        }
        else {
          uVar5 = 0;
          sVar2 = 4;
          uVar6 = 0x101;
          puVar7 = NBSI_DSM_GUID;
        }
      }
      else if (local_3c[0] == 4) {
        uVar5 = 0;
        sVar2 = 4;
        uVar6 = 0x100;
        puVar7 = NVOP_DSM_GUID;
      }
      else {
        uVar5 = 0;
        sVar2 = 4;
        uVar6 = 0x100;
        puVar7 = PCFG_DSM_GUID;
      }
    }
    else if (local_3c[0] == 9) {
      sVar2 = *param_5;
      uVar5 = 1;
      uVar6 = 0x200;
      puVar7 = NVPCF_ACPI_DSM_GUID;
    }
    else if (local_3c[0] < 10) {
      if (local_3c[0] == 7) {
        uVar5 = 0;
        sVar2 = 4;
        uVar6 = 0x103;
        puVar7 = JT_DSM_GUID;
      }
      else if (local_40 == 8) {
        uVar5 = 0;
        uVar6 = 2;
        puVar7 = PEX_DSM_GUID;
        sVar2 = *param_5 + 3;
      }
      else {
        uVar5 = 0;
        sVar2 = 4;
        uVar6 = 2;
        puVar7 = PEX_DSM_GUID;
      }
    }
    else if (local_3c[0] == 10) {
      cVar1 = rmcfg_IsTU10X(param_1);
      if (cVar1 == '\0') {
        return 0x56;
      }
      sVar2 = *param_5;
      uVar5 = 0;
      uVar6 = 0x100;
      puVar7 = GPS_DSM_GUID;
    }
    else {
      if (local_3c[0] != 0xb) {
        return 0x56;
      }
      sVar2 = *param_5;
      uVar5 = 1;
      uVar6 = 0x100;
      puVar7 = NVPCF_ACPI_DSM_GUID;
    }
    uVar4 = nv_acpi_dsm_method(plVar9,puVar7,uVar6,uVar5,local_40,param_4,sVar2,0,param_4,param_5);
    if ((int)uVar4 == 0) {
      if (local_40 == 0) {
        cacheDsmSupportedFunction(param_1,local_3c[0],0,param_4,*param_5);
      }
    }
    else if (*(char *)(lVar8 + 0x240) != '\0') {
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xb40,"osCallACPI_DSM",4,
                   "NVRM: osCallACPI_DSM: Error during 0x%x DSM subfunction 0x%x! status=0x%x\n",
                   local_3c[0],local_40,uVar4);
    }
    return uVar4 & 0xffffffff;
  }
  return (ulong)uVar3;
}


// ===== 00266360 osCallACPI_DOD =====

undefined8 osCallACPI_DOD(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = nv_acpi_dod_method(uVar1);
    return uVar1;
  }
  return 0x3d;
}


// ===== 00266390 osCallACPI_DDC =====

undefined8
osCallACPI_DDC(long param_1,undefined8 param_2,long param_3,undefined4 *param_4,undefined1 param_5)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  if ((param_3 != 0) && (param_4 != (undefined4 *)0x0)) {
    portMemSet(param_3,0,*param_4);
    uVar1 = nv_acpi_ddc_method(uVar1,param_3,param_4,param_5);
    return uVar1;
  }
  return 0x3d;
}


// ===== 00266410 osCallACPI_NVHG_ROM =====

undefined8 osCallACPI_NVHG_ROM(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  if ((param_3 != 0) && (param_2 != 0)) {
    if (*(uint *)(param_2 + 4) < 0x1001) {
      uVar1 = nv_acpi_rom_method(uVar1);
      return uVar1;
    }
    return 0x1f;
  }
  return 0x3d;
}


// ===== 00266460 osInitSystemStaticConfig =====

void osInitSystemStaticConfig(undefined1 *param_1)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = nv_is_chassis_notebook();
  if (cVar1 == '\0') {
    cVar1 = nv_acpi_is_battery_present();
    bVar2 = cVar1 != '\0';
  }
  else {
    bVar2 = true;
  }
  *param_1 = bVar2;
  param_1[8] = os_cc_sme_enabled._4_1_;
  param_1[9] = os_cc_sme_enabled._3_1_;
  param_1[10] = (undefined1)os_cc_sme_enabled;
  param_1[0xb] = os_cc_sme_enabled._2_1_;
  param_1[0xc] = os_cc_sme_enabled._1_1_;
  return;
}


// ===== 002664d0 osApiLockAcquireConfigureFlags =====

undefined4 osApiLockAcquireConfigureFlags(undefined4 param_1)

{
  return param_1;
}


// ===== 002664e0 osGpuLocksQueueRelease =====

undefined8 osGpuLocksQueueRelease(void)

{
  return 1;
}


// ===== 002664f0 osSyncWithRmDestroy =====

void osSyncWithRmDestroy(void)

{
  return;
}


// ===== 00266500 osSyncWithGpuDestroy =====

void osSyncWithGpuDestroy(void)

{
  return;
}


// ===== 00266510 osModifyGpuSwStatePersistence =====

void osModifyGpuSwStatePersistence(long param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = os_is_bif_reset_supported();
  if (cVar1 != '\0') {
    uVar2 = *(uint *)(param_1 + 0x10) | 0x800;
    if (param_2 == '\0') {
      uVar2 = *(uint *)(param_1 + 0x10) & 0xfffff7ff;
    }
    *(uint *)(param_1 + 0x10) = uVar2;
  }
  return;
}


// ===== 00266550 osCallACPI_MXDS =====

undefined8 osCallACPI_MXDS(long param_1,undefined4 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  if (param_3 != 0) {
    uVar1 = nv_acpi_mux_method(uVar1,param_3,param_2,&DAT_00cccf43);
    return uVar1;
  }
  return 0x3d;
}


// ===== 00266590 osCallACPI_MXDM =====

undefined8 osCallACPI_MXDM(long param_1,undefined4 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  if (param_3 != 0) {
    uVar1 = nv_acpi_mux_method(uVar1,param_3,param_2,&DAT_00cccf48);
    return uVar1;
  }
  return 0x3d;
}


// ===== 002665d0 osGetVersionDump =====

int osGetVersionDump(undefined8 param_1)

{
  int iVar1;
  undefined4 *local_50;
  undefined8 local_41;
  undefined7 local_39;
  undefined4 uStack_32;
  undefined8 local_2e;
  undefined6 local_26;
  undefined2 uStack_20;
  undefined6 uStack_1e;
  
  local_26 = 0x20646c697562;
  local_2e = 0x206e776f6e6b6e55;
  local_41 = 0x206e776f6e6b6e55;
  local_39 = 0x6420646c697562;
  local_50 = (undefined4 *)0x0;
  uStack_20 = 0x6576;
  uStack_1e = 0x6e6f697372;
  uStack_32 = 0x657461;
  iVar1 = os_alloc_mem(&local_50,0x20);
  if (iVar1 == 0) {
    portMemSet(local_50,0,0x20);
    prbEncAddUInt32(param_1,prb_fields_nvdebug_systeminfo_osinfo,2);
    iVar1 = os_get_version_info(local_50);
    if (iVar1 == 0) {
      prbEncAddUInt32(param_1,0xc5e5f8,*local_50);
      prbEncAddUInt32(param_1,0xc5e610,local_50[1]);
      prbEncAddUInt32(param_1,0xc5e628,local_50[2]);
      if (*(long *)(local_50 + 4) == 0) {
        *(undefined8 **)(local_50 + 4) = &local_2e;
      }
      prbEncAddString(param_1,0xc5e658);
      if (*(long *)(local_50 + 6) == 0) {
        *(undefined8 **)(local_50 + 6) = &local_41;
      }
      prbEncAddString(param_1,0xc5e670);
    }
    os_free_mem(local_50);
    return iVar1;
  }
  nvAssertOkFailedNoLog
            (iVar1,"os_alloc_mem((void**)&pOsVersionInfo, sizeof(os_version_info))",
             "arch/nvalloc/unix/src/os.c",0xc05);
  return iVar1;
}


// ===== 00266760 osTegraiGpuPerfBoost =====

void osTegraiGpuPerfBoost(long param_1,undefined1 param_2)

{
  os_tegra_igpu_perf_boost(*(undefined8 *)(param_1 + 0x4e0),param_2);
  return;
}


// ===== 00266780 osGC6PowerControl =====

undefined8 osGC6PowerControl(undefined8 param_1,uint param_2,uint *param_3)

{
  undefined8 uVar1;
  undefined2 local_1e;
  uint local_1c;
  
  local_1e = 4;
  if (((param_2 & 7) == 0) && (param_3 == (uint *)0x0)) {
    uVar1 = 0x1f;
  }
  else {
    local_1c = param_2;
    uVar1 = osCallACPI_DSM(param_1,7,3,&local_1c,&local_1e);
    if (((int)uVar1 != 0) || (param_3 == (uint *)0x0)) {
      return uVar1;
    }
    *param_3 = local_1c;
  }
  return uVar1;
}


// ===== 00266800 osTestPcieExtendedConfigAccess =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 osTestPcieExtendedConfigAccess(undefined8 param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c[0] = 0;
  if (param_2 < 0x100) {
    return 1;
  }
  if (retryAllowed_11 != '\0') {
    lVar3 = gpumgrGetSomeGpu();
    if (lVar3 != 0) {
      lVar1 = *(long *)(lVar3 + 7000);
      retryAllowed_11 = '\0';
      if ((lVar1 != 0) && (iVar2 = (**(code **)(lVar3 + 0x168))(lVar3), iVar2 == 3)) {
        (**(code **)(lVar1 + 0x1f0))(lVar3,lVar1,&local_20,local_1c);
        os_pci_read_dword(param_1,local_20,&local_28);
        os_pci_read_dword(param_1,local_1c[0],&local_24);
        iVar2 = (**(code **)(lVar1 + 0x1f8))(lVar3,lVar1,local_28,local_24);
        if (iVar2 == 0) {
          configAccess_10 = 1;
          return 1;
        }
      }
    }
    return configAccess_10;
  }
  return configAccess_10;
}


// ===== 00266930 osIovaMap =====

ulong osIovaMap(undefined4 *param_1)

{
  ulong uVar1;
  ulong *puVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 uVar13;
  ulong uVar14;
  undefined8 uVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  char *pcVar19;
  bool bVar20;
  bool local_57;
  bool local_56;
  int local_54;
  long local_40 [2];
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x1f;
  }
  lVar9 = gpumgrGetGpuFromId(*param_1);
  if (lVar9 == 0) {
    return 0x1f;
  }
  plVar10 = (long *)memdescGetRootMemDesc(*(undefined8 *)(param_1 + 2),0);
  iVar6 = memdescGetAddressSpace(*(undefined8 *)(param_1 + 2));
  cVar4 = gpumgrCheckIndirectPeer_IMPL(lVar9,*plVar10);
  lVar16 = *(long *)(param_1 + 2);
  if ((cVar4 == '\0') || (iVar6 != 2)) {
    bVar20 = false;
    if (iVar6 != 1) {
      uVar8 = memdescGetAddressSpace();
      uVar13 = memdescGetApertureString(uVar8);
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xd9e,"osIovaMap",1,
                   "NVRM: %s passed memory descriptor in an unsupported address space (%s)\n",
                   "osIovaMap",uVar13);
      return 0x56;
    }
    uVar11 = *(ulong *)(lVar16 + 8);
  }
  else {
    bVar20 = true;
    uVar11 = *(ulong *)(lVar16 + 8);
  }
  if ((uVar11 & 0x88000000000000) != 0) {
    return 0;
  }
  cVar4 = memdescGetFlag(lVar16,0x100);
  if (cVar4 != '\0') {
    return 0;
  }
  lVar9 = *(long *)(lVar9 + 0x4e0);
  if ((*(char *)(g_pSys + 400) == '\0') ||
     (cVar4 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0), cVar4 != '\0')) {
    lVar16 = *(long *)(param_1 + 2);
    local_54 = (uint)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & *(ulong *)(lVar16 + 0x18)
                      ) != 0) + (int)(*(ulong *)(lVar16 + 0x18) >> (os_page_shift - 0xcU & 0x3f));
  }
  else {
    lVar16 = *(long *)(param_1 + 2);
    if (*(uint *)(lVar16 + 0x160) != os_page_size) {
      nvAssertFailedNoLog("os_page_size == pIovaMapping->pPhysMemDesc->pageArrayGranularity",
                          "arch/nvalloc/unix/src/os.c",0xdb8);
      return 0x3b;
    }
    local_54 = *(int *)(lVar16 + 0x18);
  }
  cVar4 = memdescGetFlag(lVar16,0x80000000);
  if (cVar4 != '\0') {
    cVar4 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0);
    if (cVar4 == '\0') {
      nvAssertFailedNoLog("memdescGetContiguity(pIovaMapping->pPhysMemDesc, AT_CPU)",
                          "arch/nvalloc/unix/src/os.c",0xdc5);
    }
    uVar11 = nv_dma_map_mmio(*(undefined8 *)(lVar9 + 0x2e0),local_54,param_1 + 10);
    uVar12 = uVar11 & 0xffffffff;
    if ((int)uVar11 == 0) {
      return uVar12;
    }
    uVar13 = 4;
    uVar15 = 0xdcd;
    pcVar19 = "NVRM: %s: failed to map peer IO mem (status = 0x%x)\n";
    goto LAB_00266d70;
  }
  lVar16 = 0;
  if (*plVar10 != 0) {
    lVar16 = *(long *)(*plVar10 + 0x4e0);
  }
  cVar4 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0);
  if ((*(char *)(g_pSys + 400) == '\0') ||
     (cVar5 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0), cVar5 != '\0')) {
    lVar17 = *(long *)(param_1 + 2);
    if ((0x1000 < os_page_size) && (cVar4 == '\0')) {
      RmDeflateRmToOsPageArray(param_1 + 10,*(undefined8 *)(lVar17 + 0x18));
      lVar17 = *(long *)(param_1 + 2);
    }
  }
  else {
    lVar17 = *(long *)(param_1 + 2);
    uVar13 = 0xde0;
    if (*(uint *)(lVar17 + 0x160) != os_page_size) goto LAB_00266ed1;
  }
  uVar11 = memdescGetPhysAddr(lVar17,0,0);
  puVar2 = *(ulong **)(lVar16 + 0x140);
  uVar12 = **(ulong **)(lVar16 + 0x108);
  if ((uVar11 < uVar12) ||
     (uVar18 = *(long *)(*(long *)(param_1 + 2) + 0x30) - 1, uVar14 = uVar18 + uVar11,
     CARRY8(uVar18,uVar11))) {
    if ((puVar2 != (ulong *)0x0) &&
       (((uVar12 = puVar2[1], uVar12 != 0 && (uVar18 = *puVar2, uVar18 <= uVar11)) &&
        (uVar1 = *(long *)(*(long *)(param_1 + 2) + 0x30) - 1, uVar14 = uVar1 + uVar11,
        !CARRY8(uVar1,uVar11))))) {
      local_57 = false;
      goto LAB_00266b27;
    }
    local_40[0] = memdescGetMemData();
LAB_00266cbb:
    if (local_40[0] == 0) {
      return 0x40;
    }
    cVar5 = skipIovaMappingForTegra(param_1,lVar9);
    if (cVar5 != '\0') {
      return 0;
    }
LAB_00266cd8:
    if ((*(long *)(lVar9 + 0x2e8) == 0) ||
       (cVar5 = memdescGetFlag(*(undefined8 *)(param_1 + 2),0x4000000000), cVar5 == '\0')) {
      uVar13 = *(undefined8 *)(lVar9 + 0x2e0);
    }
    else {
      uVar13 = *(undefined8 *)(lVar9 + 0x2e8);
    }
    uVar7 = nv_dma_map_alloc(uVar13,local_54,param_1 + 10,cVar4,local_40);
    uVar12 = (ulong)uVar7;
    lVar9 = local_40[0];
    if (uVar7 != 0) {
      uVar13 = 4;
      uVar15 = 0xe17;
      pcVar19 = "NVRM: %s: failed to map allocation (status = 0x%x)\n";
      uVar11 = uVar12;
LAB_00266d70:
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",uVar15,"osIovaMap",uVar13,pcVar19,"osIovaMap",uVar11
                  );
      return uVar12;
    }
  }
  else {
    local_57 = uVar14 <= (uVar12 + (*(ulong **)(lVar16 + 0x108))[1]) - 1;
    if (((puVar2 == (ulong *)0x0) || (uVar12 = puVar2[1], uVar12 == 0)) ||
       (uVar18 = *puVar2, uVar11 < uVar18)) {
LAB_00266e00:
      local_40[0] = memdescGetMemData();
      if (local_57 == false) goto LAB_00266cbb;
      local_56 = false;
      bVar3 = local_57;
      if (bVar20 != false) {
LAB_00266e1c:
        nvAssertFailedNoLog("!bIsBar0 && bIsFbOffset","arch/nvalloc/unix/src/os.c",0xdf8);
        local_57 = true;
        goto LAB_00266e38;
      }
      local_56 = false;
    }
    else {
LAB_00266b27:
      if ((uVar18 - 1) + uVar12 < uVar14) goto LAB_00266e00;
      local_40[0] = memdescGetMemData();
      bVar3 = local_57;
      if (bVar20 == false) {
        local_56 = true;
      }
      else {
        local_56 = bVar20;
        if (local_57 != false) {
          local_56 = local_57;
          goto LAB_00266e1c;
        }
LAB_00266e38:
        iVar6 = 1;
        if (cVar4 == '\0') {
          iVar6 = local_54;
        }
        uVar7 = memdescGetNvLinkGpa(*plVar10,iVar6,param_1 + 10);
        if (uVar7 != 0) {
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xe04,"osIovaMap",4,
                       "NVRM: %s Failed to get SPA\n");
          return (ulong)uVar7;
        }
      }
    }
    cVar5 = skipIovaMappingForTegra(param_1,lVar9);
    if (cVar5 != '\0') {
      return 0;
    }
    if ((!bVar3) && (local_56 != true || bVar20 != false)) goto LAB_00266cd8;
    if (lVar16 == lVar9) {
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xe34,"osIovaMap",1,
                   "NVRM: cannot map a GPU\'s BAR to itself\n");
      return 0x56;
    }
    uVar7 = nv_dma_map_peer(*(undefined8 *)(lVar9 + 0x2e0),*(undefined8 *)(lVar16 + 0x2e0),
                            local_57 ^ 1,local_54,param_1 + 10);
    uVar12 = (ulong)uVar7;
    lVar9 = 0;
    if (uVar7 != 0) {
      uVar13 = 1;
      pcVar19 = "NVRM: %s: failed to map peer (base = 0x%llx, status = 0x%x)\n";
      uVar15 = 0xe25;
      goto LAB_00266d70;
    }
  }
  *(long *)(param_1 + 8) = lVar9;
  if ((*(char *)(g_pSys + 400) == '\0') ||
     (cVar5 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0), cVar5 != '\0')) {
    if ((0x1000 < os_page_size) && (cVar4 == '\0')) {
      RmInflateOsToRmPageArray(param_1 + 10,*(undefined8 *)(*(long *)(param_1 + 2) + 0x18));
    }
  }
  else if (*(uint *)(*(long *)(param_1 + 2) + 0x160) != os_page_size) {
    uVar13 = 0xe3e;
LAB_00266ed1:
    nvAssertFailedNoLog("pIovaMapping->pPhysMemDesc->pageArrayGranularity == os_page_size",
                        "arch/nvalloc/unix/src/os.c",uVar13);
    return 0x1f;
  }
  return 0;
}


// ===== 00267100 osIovaUnmap =====

void osIovaUnmap(undefined4 *param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  long lVar4;
  long lVar5;
  undefined1 auVar6 [16];
  undefined8 uStack_50;
  long local_30 [2];
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  lVar2 = gpumgrGetGpuFromId(*param_1);
  if (((lVar2 != 0) && ((*(ulong *)(*(long *)(param_1 + 2) + 8) & 0x88000000000000) == 0)) &&
     (cVar1 = memdescGetFlag(*(long *)(param_1 + 2),0x100), cVar1 == '\0')) {
    lVar2 = *(long *)(lVar2 + 0x4e0);
    cVar1 = skipIovaMappingForTegra(param_1,lVar2);
    if (cVar1 == '\0') {
      if ((*(char *)(g_pSys + 400) == '\0') ||
         (cVar1 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0), cVar1 != '\0')) {
        lVar4 = *(long *)(param_1 + 2);
        lVar5 = (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) &
                        *(ulong *)(lVar4 + 0x18)) != 0) +
                (*(ulong *)(lVar4 + 0x18) >> (os_page_shift - 0xcU & 0x3f));
      }
      else {
        lVar4 = *(long *)(param_1 + 2);
        lVar5 = *(long *)(lVar4 + 0x18);
        if (*(uint *)(lVar4 + 0x160) != os_page_size) {
          nvAssertFailedNoLog("os_page_size == pIovaMapping->pPhysMemDesc->pageArrayGranularity",
                              "arch/nvalloc/unix/src/os.c",0xe7b);
          lVar4 = *(long *)(param_1 + 2);
        }
      }
      cVar1 = memdescGetFlag(lVar4,0x80000000);
      if (cVar1 != '\0') {
        nv_dma_unmap_mmio(*(undefined8 *)(lVar2 + 0x2e0),lVar5,*(undefined8 *)(param_1 + 10));
        return;
      }
      local_30[0] = *(long *)(param_1 + 8);
      if ((*(char *)(g_pSys + 400) == '\0') ||
         (cVar1 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0), cVar1 != '\0')) {
        if ((0x1000 < os_page_size) &&
           (cVar1 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0), cVar1 == '\0')) {
          RmDeflateRmToOsPageArray(param_1 + 10,*(undefined8 *)(*(long *)(param_1 + 2) + 0x18));
        }
      }
      else if (*(uint *)(*(long *)(param_1 + 2) + 0x160) != os_page_size) {
        nvAssertFailedNoLog("pIovaMapping->pPhysMemDesc->pageArrayGranularity == os_page_size",
                            "arch/nvalloc/unix/src/os.c",0xe93);
      }
      if (local_30[0] == 0) {
        nv_dma_unmap_peer(*(undefined8 *)(lVar2 + 0x2e0),lVar5,*(undefined8 *)(param_1 + 10));
        uVar3 = extraout_RDX;
      }
      else {
        uStack_50 = 0x267226;
        auVar6 = nv_dma_unmap_alloc(*(undefined8 *)(lVar2 + 0x2e0),lVar5,param_1 + 10,local_30);
        uVar3 = auVar6._8_8_;
        if (auVar6._0_4_ != 0) {
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xea3,"osIovaUnmap",4,
                       "NVRM: %s: failed to unmap allocation (status = 0x%x)\n","osIovaUnmap",
                       auVar6._0_8_);
          uVar3 = uStack_50;
        }
      }
      if ((*(char *)(g_pSys + 400) == '\0') ||
         (cVar1 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0,uVar3),
         uVar3 = extraout_RDX_00, cVar1 != '\0')) {
        if ((0x1000 < os_page_size) &&
           (cVar1 = memdescGetContiguity(*(undefined8 *)(param_1 + 2),0,uVar3), cVar1 == '\0')) {
          RmInflateOsToRmPageArray(param_1 + 10,*(undefined8 *)(*(long *)(param_1 + 2) + 0x18));
        }
      }
      else if (*(uint *)(*(long *)(param_1 + 2) + 0x160) != os_page_size) {
        nvAssertFailedNoLog("pIovaMapping->pPhysMemDesc->pageArrayGranularity == os_page_size",
                            "arch/nvalloc/unix/src/os.c",0xeb5);
      }
      *(undefined8 *)(param_1 + 8) = 0;
    }
  }
  return;
}


// ===== 00267450 osBugCheck =====

void osBugCheck(uint param_1)

{
  if (7 < param_1) {
    param_1 = 0;
  }
  os_bug_check((ulong)param_1,(&ppOsBugCheckBugcodeStr)[param_1]);
  return;
}


// ===== 00267470 osAssertFailed =====

void osAssertFailed(void)

{
  os_dump_stack();
  return;
}


// ===== 00267480 osGetSecurityToken =====

long osGetSecurityToken(void)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = portMemAllocNonPaged(8);
  if (lVar3 != 0) {
    iVar1 = os_get_euid(lVar3);
    if (iVar1 != 0) {
      portMemFree(lVar3);
      return 0;
    }
    uVar2 = os_get_current_process();
    *(undefined4 *)(lVar3 + 4) = uVar2;
  }
  return lVar3;
}


// ===== 002674e0 osGetCurrentUidToken =====

long osGetCurrentUidToken(void)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = portMemAllocNonPaged(4);
  lVar3 = lVar2;
  if (lVar2 != 0) {
    iVar1 = os_get_euid(lVar2);
    if (iVar1 != 0) {
      lVar3 = 0;
      portMemFree(lVar2);
    }
  }
  return lVar3;
}


// ===== 00267530 osValidateClientTokens =====

undefined8 osValidateClientTokens(int *param_1,int *param_2)

{
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    if (*param_1 != *param_2) {
      if (param_1[1] != param_2[1]) {
        nvDbg_Printf("arch/nvalloc/unix/src/os.c",0xf80,"osValidateClientTokens",1,
                     "NVRM: NVRM: %s: Current security token doesn\'t match the one in the client database. Current EUID: %d, PID: %d; Client DB EUID: %d, PID: %d\n"
                     ,"osValidateClientTokens",*param_2,param_2[1],*param_1,param_1[1]);
        return 0x23;
      }
    }
    return 0;
  }
  return 0x3d;
}


// ===== 002675a0 osUidTokensEqual =====

undefined4 osUidTokensEqual(int *param_1,int *param_2)

{
  if (param_1 == (int *)0x0) {
    nvAssertFailedNoLog("(pTokenUser1 != NULL)","arch/nvalloc/unix/src/os.c",4000);
  }
  else {
    if (param_2 != (int *)0x0) {
      return CONCAT31((int3)((uint)*param_2 >> 8),*param_1 == *param_2);
    }
    nvAssertFailedNoLog("(pTokenUser2 != NULL)","arch/nvalloc/unix/src/os.c",0xfa1);
  }
  return 0;
}


// ===== 00267600 osRemoveGpuSupported =====

void osRemoveGpuSupported(void)

{
  os_pci_remove_supported();
  return;
}


// ===== 00267610 osGetFbNumaInfo =====

undefined8 osGetFbNumaInfo(void)

{
  return 0x56;
}


// ===== 00267620 osGetAcpiRsdpFromUefi =====

void osGetAcpiRsdpFromUefi(void)

{
  os_get_acpi_rsdp_from_uefi();
  return;
}


// ===== 00267630 osIsNvswitchPresent =====

void osIsNvswitchPresent(void)

{
  os_is_nvswitch_present();
  return;
}


// ===== 00267640 osAddRecordForCrashLog =====

void osAddRecordForCrashLog(void)

{
  os_add_record_for_crashLog();
  return;
}


// ===== 00267650 osDeleteRecordForCrashLog =====

void osDeleteRecordForCrashLog(void)

{
  os_delete_record_for_crashLog();
  return;
}


// ===== 00267660 osNumaMemblockSize =====

void osNumaMemblockSize(void)

{
  os_numa_memblock_size();
  return;
}


// ===== 00267670 osNumaOnliningEnabled =====

undefined1  [16] osNumaOnliningEnabled(undefined8 param_1)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  undefined1 auVar3 [16];
  int local_c;
  
  local_c = -1;
  uVar2 = nv_get_device_memory_config(param_1,0,0,0,0,0);
  if ((int)uVar2 == 0) {
    auVar3._1_7_ = (undefined7)((ulong)uVar2 >> 8);
    auVar3[0] = local_c != -1;
    auVar3._8_8_ = &local_c;
    return auVar3;
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = &local_c;
  return auVar1 << 0x40;
}


// ===== 002676c0 osAllocPagesNode =====

undefined8 osAllocPagesNode(int param_1,ulong param_2,uint param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_2 >> 0x20 == 0 && -1 < param_1) && (param_4 != 0)) {
    uVar1 = os_alloc_pages_node(param_1,param_2,param_3 & 1);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00267700 osAllocAcquirePage =====

void osAllocAcquirePage(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      os_get_page((ulong)(uint)(iVar1 << (os_page_shift & 0x1f)) + param_1);
      iVar1 = iVar2;
    } while (param_2 != iVar2);
    return;
  }
  return;
}


// ===== 00267760 osAllocReleasePage =====

void osAllocReleasePage(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      os_put_page((ulong)(uint)(iVar1 << (os_page_shift & 0x1f)) + param_1);
      iVar1 = iVar2;
    } while (param_2 != iVar2);
    return;
  }
  return;
}


// ===== 002677c0 osGetPageRefcount =====

void osGetPageRefcount(void)

{
  os_get_page_refcount();
  return;
}


// ===== 002677d0 osCountTailPages =====

void osCountTailPages(void)

{
  os_count_tail_pages();
  return;
}


// ===== 002677e0 osGetPageSize =====

undefined8 osGetPageSize(void)

{
  return os_page_size;
}


// ===== 002677f0 osGetSupportedSysmemPageSizeMask =====

ulong osGetSupportedSysmemPageSizeMask(void)

{
  return os_max_page_size * 2 - 1U & -os_page_size;
}


// ===== 00267810 osGetPageShift =====

undefined1 osGetPageShift(void)

{
  return os_page_shift;
}


// ===== 00267820 osOpenTemporaryFile =====

void osOpenTemporaryFile(void)

{
  os_open_temporary_file();
  return;
}


// ===== 00267830 osCloseFile =====

void osCloseFile(void)

{
  os_close_file();
  return;
}


// ===== 00267840 osWriteToFile =====

void osWriteToFile(void)

{
  os_write_file();
  return;
}


// ===== 00267850 osReadFromFile =====

void osReadFromFile(void)

{
  os_read_file();
  return;
}


// ===== 00267860 osRmCapUnregister =====

void osRmCapUnregister(undefined8 *param_1)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    lVar2 = *(long *)(piVar1 + 2);
    uVar3 = *piVar1 - 1;
    if (-1 < (int)uVar3) {
      lVar4 = (ulong)uVar3 << 3;
      do {
        if (*(long *)(lVar2 + lVar4) != 0) {
          os_nv_cap_destroy_entry();
          lVar2 = *(long *)(piVar1 + 2);
        }
        uVar3 = uVar3 - 1;
        lVar4 = lVar4 + -8;
      } while (uVar3 != 0xffffffff);
    }
    os_free_mem(lVar2);
    os_free_mem(piVar1);
    *param_1 = 0;
  }
  return;
}


// ===== 002678f0 osRmCapRegisterGpu =====

int osRmCapRegisterGpu(undefined8 param_1,long *param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long local_30;
  undefined1 local_28 [15];
  undefined1 local_19;
  
  uVar1 = nv_get_dev_minor();
  if (nvidia_caps_root == 0) {
    return 0;
  }
  iVar2 = 0x1f;
  if (*param_2 == 0) {
    iVar2 = _allocOsRmCaps(&local_30,2);
    if (iVar2 != 0) {
      return iVar2;
    }
    *param_2 = local_30;
    os_snprintf(local_28,0x10,"gpu%u",uVar1);
    local_19 = 0;
    lVar3 = os_nv_cap_create_dir_entry(nvidia_caps_root,local_28,0x16d);
    if (lVar3 == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1282,"osRmCapRegisterGpu",4,
                   "NVRM: Failed to setup gpu%u directory\n",uVar1);
    }
    else {
      **(long **)(local_30 + 8) = lVar3;
      lVar3 = os_nv_cap_create_dir_entry(lVar3,&DAT_00ccd2af,0x16d);
      if (lVar3 != 0) {
        *(long *)(*(long *)(local_30 + 8) + 8) = lVar3;
        return 0;
      }
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x128f,"osRmCapRegisterGpu",4,
                   "NVRM: Failed to setup mig directory\n");
    }
    osRmCapUnregister(param_2);
    iVar2 = 0x59;
  }
  return iVar2;
}


// ===== 00267a70 osRmCapRegisterSmcPartition =====

int osRmCapRegisterSmcPartition(long param_1,long *param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long local_40;
  undefined1 local_38 [15];
  undefined1 local_29;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((*param_2 == 0) && (param_3 != -1)) {
    lVar2 = *(long *)(*(long *)(param_1 + 8) + 8);
    if (lVar2 == 0) {
      iVar1 = 0x40;
    }
    else {
      iVar1 = _allocOsRmCaps(&local_40,2);
      if (iVar1 == 0) {
        *param_2 = local_40;
        os_snprintf(local_38,0x10,&DAT_00ccd305,param_3);
        local_29 = 0;
        lVar2 = os_nv_cap_create_dir_entry(lVar2,local_38,0x16d);
        if (lVar2 == 0) {
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x12d5,"osRmCapRegisterSmcPartition",4,
                       "NVRM: Failed to setup gi%u directory\n",param_3);
        }
        else {
          **(long **)(local_40 + 8) = lVar2;
          lVar2 = os_nv_cap_create_file_entry(lVar2,"access",0x124);
          if (lVar2 != 0) {
            *(long *)(*(long *)(local_40 + 8) + 8) = lVar2;
            return 0;
          }
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x12e1,"osRmCapRegisterSmcPartition",4,
                       "NVRM: Failed to setup access file for ID:%u\n",param_3);
        }
        osRmCapUnregister(param_2);
        iVar1 = 0x59;
      }
    }
    return iVar1;
  }
  return 0x1f;
}


// ===== 00267c10 osRmCapRegisterSmcExecutionPartition =====

int osRmCapRegisterSmcExecutionPartition(long param_1,long *param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long local_40;
  undefined1 local_38 [15];
  undefined1 local_29;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((*param_2 == 0) && (param_3 != -1)) {
    lVar2 = **(long **)(param_1 + 8);
    if (lVar2 == 0) {
      iVar1 = 0x40;
    }
    else {
      iVar1 = _allocOsRmCaps(&local_40,2);
      if (iVar1 == 0) {
        *param_2 = local_40;
        os_snprintf(local_38,0x10,&DAT_00ccd36d,param_3);
        local_29 = 0;
        lVar2 = os_nv_cap_create_dir_entry(lVar2,local_38,0x16d);
        if (lVar2 == 0) {
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x132a,"osRmCapRegisterSmcExecutionPartition",4,
                       "NVRM: Failed to setup ci%u directory\n",param_3);
        }
        else {
          **(long **)(local_40 + 8) = lVar2;
          lVar2 = os_nv_cap_create_file_entry(lVar2,"access",0x124);
          if (lVar2 != 0) {
            *(long *)(*(long *)(local_40 + 8) + 8) = lVar2;
            return 0;
          }
          nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1336,"osRmCapRegisterSmcExecutionPartition",4,
                       "NVRM: Failed to setup access file for ID:%u\n",param_3);
        }
        osRmCapUnregister(param_2);
        iVar1 = 0x59;
      }
    }
    return iVar1;
  }
  return 0x1f;
}


// ===== 00267db0 osRmCapRelease =====

void osRmCapRelease(long param_1)

{
  if (param_1 != -1) {
    os_nv_cap_close_fd();
    return;
  }
  return;
}


// ===== 00267dd0 osRmCapRegisterSys =====

int osRmCapRegisterSys(long *param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long local_30 [2];
  
  if (nvidia_caps_root == 0) {
    return 0x56;
  }
  iVar2 = _allocOsRmCaps(local_30,7);
  if (iVar2 != 0) {
    return iVar2;
  }
  *param_1 = local_30[0];
  plVar1 = *(long **)(local_30[0] + 8);
  lVar3 = os_nv_cap_create_dir_entry(nvidia_caps_root,&DAT_00ccd2af,0x16d);
  if (lVar3 == 0) {
    nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1379,"osRmCapRegisterSys",4,
                 "NVRM: Failed to create mig directory\n");
  }
  else {
    *plVar1 = lVar3;
    lVar4 = os_nv_cap_create_file_entry(lVar3,"config",0x100);
    if (lVar4 == 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1382,"osRmCapRegisterSys",4,
                   "NVRM: Failed to create mig config file\n");
    }
    else {
      plVar1[1] = lVar4;
      lVar3 = os_nv_cap_create_file_entry(lVar3,"monitor",0x124);
      if (lVar3 == 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x138b,"osRmCapRegisterSys",4,
                     "NVRM: Failed to create mig monitor file\n");
      }
      else {
        plVar1[2] = lVar3;
        lVar3 = os_nv_cap_create_file_entry(nvidia_caps_root,"fabric-imex-mgmt",0x100);
        if (lVar3 != 0) {
          plVar1[3] = lVar3;
          return 0;
        }
        nvDbg_Printf("arch/nvalloc/unix/src/os.c",0x1394,"osRmCapRegisterSys",4,
                     "NVRM: Failed to create imex file\n");
      }
    }
  }
  osRmCapUnregister(param_1);
  return 0x59;
}


// ===== 00267fb0 osRmCapAcquire =====

undefined8 osRmCapAcquire(uint *param_1,uint param_2,undefined4 param_3,long *param_4)

{
  undefined8 uVar1;
  long lVar2;
  int local_c;
  
  *param_4 = -1;
  if (param_2 == 4) {
    lVar2 = 3;
  }
  else {
    if (param_2 < 5) {
      if (param_2 != 2) {
        lVar2 = 2;
        if (param_2 != 3) {
          return 0x1f;
        }
        goto LAB_00267fff;
      }
    }
    else {
      if (param_2 == 0x200) {
        uVar1 = nv_acquire_fabric_mgmt_cap(param_3,&local_c);
        if ((int)uVar1 != 0) {
          return uVar1;
        }
        goto LAB_00268023;
      }
      if ((param_2 & 0xfffffdff) != 0x100) {
        return 0x1f;
      }
    }
    lVar2 = 1;
  }
LAB_00267fff:
  if (param_1 == (uint *)0x0) {
    return 0x56;
  }
  if (*param_1 <= (uint)lVar2) {
    return 0x1f;
  }
  local_c = os_nv_cap_validate_and_dup_fd
                      (*(undefined8 *)(*(long *)(param_1 + 2) + lVar2 * 8),param_3);
  if (local_c < 0) {
    return 0x1b;
  }
LAB_00268023:
  *param_4 = (long)local_c;
  return 0;
}


// ===== 00268090 osRmCapInitDescriptor =====

void osRmCapInitDescriptor(undefined8 *param_1)

{
  *param_1 = 0xffffffffffffffff;
  return;
}


// ===== 002680a0 osImexChannelIsSupported =====

undefined1 osImexChannelIsSupported(void)

{
  return os_imex_channel_is_supported;
}


// ===== 002680b0 osImexChannelCount =====

void osImexChannelCount(void)

{
  os_imex_channel_count();
  return;
}


// ===== 002680c0 osImexChannelGet =====

void osImexChannelGet(void)

{
  os_imex_channel_get();
  return;
}


// ===== 002680d0 osGetRandomBytes =====

void osGetRandomBytes(undefined8 param_1,undefined2 param_2)

{
  os_get_random_bytes(param_1,param_2);
  return;
}


// ===== 002680e0 osGetCurrentProcessFlags =====

void osGetCurrentProcessFlags(void)

{
  os_get_current_process_flags();
  return;
}


// ===== 002680f0 osAllocWaitQueue =====

void osAllocWaitQueue(void)

{
  os_alloc_wait_queue();
  return;
}


// ===== 00268100 osFreeWaitQueue =====

void osFreeWaitQueue(void)

{
  os_free_wait_queue();
  return;
}


// ===== 00268110 osWaitInterruptible =====

void osWaitInterruptible(void)

{
  os_wait_interruptible();
  return;
}


// ===== 00268120 osWakeUp =====

void osWakeUp(void)

{
  os_wake_up();
  return;
}


// ===== 00268130 osTegraDceRegisterIpcClient =====

undefined8 osTegraDceRegisterIpcClient(int param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = nv_tegra_dce_register_ipc_client(0,param_2,0,param_3);
    return uVar1;
  }
  if (param_1 != 1) {
    return 0x1f;
  }
  uVar1 = nv_tegra_dce_register_ipc_client(1,param_2,osTegraDceClientIpcCallback,param_3);
  return uVar1;
}


// ===== 00268170 osTegraDceUnregisterIpcClient =====

void osTegraDceUnregisterIpcClient(void)

{
  nv_tegra_dce_unregister_ipc_client();
  return;
}


// ===== 00268180 osTegraDceClientIpcSendRecv =====

void osTegraDceClientIpcSendRecv(void)

{
  nv_tegra_dce_client_ipc_send_recv();
  return;
}


// ===== 00268190 osTegraSocGetImpImportData =====

undefined8 osTegraSocGetImpImportData(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x45a) == '\0') {
    return 0x56;
  }
  uVar1 = nv_imp_get_import_data(param_2);
  return uVar1;
}


// ===== 002681b0 osTegraSocGetImpUefiData =====

void osTegraSocGetImpUefiData(void)

{
  nv_imp_get_uefi_data();
  return;
}


// ===== 002681c0 osTegraSocGetDispClockRates =====

undefined8
osTegraSocGetDispClockRates
          (long param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x33c);
    *param_3 = *(undefined4 *)(param_1 + 0x340);
    *param_4 = *(undefined4 *)(param_1 + 0x344);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 002681f0 osTegraAllocateDisplayBandwidth =====

undefined8 osTegraAllocateDisplayBandwidth(long param_1)

{
  undefined8 uVar1;
  
  if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
    return 0x56;
  }
  uVar1 = nv_imp_icc_set_bw();
  return uVar1;
}


// ===== 00268210 osCreateNanoTimer =====

undefined8 osCreateNanoTimer(void)

{
  nv_create_nano_timer();
  return 0;
}


// ===== 00268230 osStartNanoTimer =====

undefined8 osStartNanoTimer(void)

{
  nv_start_nano_timer();
  return 0;
}


// ===== 00268250 osCancelNanoTimer =====

undefined8 osCancelNanoTimer(void)

{
  nv_cancel_nano_timer();
  return 0;
}


// ===== 00268270 osDestroyNanoTimer =====

undefined8 osDestroyNanoTimer(void)

{
  nv_destroy_nano_timer();
  return 0;
}


// ===== 00268290 osGetSyncpointAperture =====

void osGetSyncpointAperture
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  nv_get_syncpoint_aperture(param_2,param_3,param_4,param_5);
  return;
}


// ===== 002682b0 osConfigurePcieReqAtomics =====

ulong osConfigurePcieReqAtomics(long param_1,uint *param_2)

{
  int iVar1;
  ulong uVar2;
  
  if ((param_2 == (uint *)0x0) || (*param_2 = 0, param_1 == 0)) {
    return 0x56;
  }
  iVar1 = os_enable_pci_req_atomics(*(undefined8 *)(param_1 + 0x48),0);
  if (iVar1 == 0) {
    *param_2 = *param_2 | 1;
  }
  iVar1 = os_enable_pci_req_atomics(*(undefined8 *)(param_1 + 0x48),1);
  if (iVar1 == 0) {
    *param_2 = *param_2 | 2;
  }
  uVar2 = os_enable_pci_req_atomics(*(undefined8 *)(param_1 + 0x48),2);
  if ((int)uVar2 != 0) {
    return (ulong)(-(uint)(*param_2 == 0) & 0x56);
  }
  *param_2 = *param_2 | 4;
  return uVar2;
}


// ===== 00268340 osIsGpuAccessible =====

void osIsGpuAccessible(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  nv_is_gpu_accessible(uVar1);
  return;
}


// ===== 00268360 osIsGpuShutdown =====

undefined1 osIsGpuShutdown(long param_1)

{
  if ((param_1 != 0) && (*(long *)(param_1 + 0x4e0) != 0)) {
    return *(undefined1 *)(*(long *)(param_1 + 0x4e0) + 0x325);
  }
  return 1;
}


// ===== 00268390 osMatchGpuOsInfo =====

void osMatchGpuOsInfo(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  nv_match_gpu_os_info(uVar1);
  return;
}


// ===== 002683b0 osReleaseGpuOsInfo =====

void osReleaseGpuOsInfo(void)

{
  nv_put_file_private();
  return;
}


// ===== 002683c0 osGetNumaMemoryUsage =====

void osGetNumaMemoryUsage(void)

{
  int iVar1;
  
  iVar1 = os_get_numa_node_memory_usage();
  if (iVar1 == 0) {
    return;
  }
  nvAssertFailedNoLog("status == NV_OK","arch/nvalloc/unix/src/os.c",0x1741);
  return;
}


// ===== 00268400 osNumaAddGpuMemory =====

void osNumaAddGpuMemory(long param_1)

{
  os_numa_add_gpu_memory(*(undefined8 *)(param_1 + 0x48));
  return;
}


// ===== 00268410 osNumaRemoveGpuMemory =====

void osNumaRemoveGpuMemory(long param_1)

{
  int iVar1;
  
  iVar1 = os_numa_remove_gpu_memory(*(undefined8 *)(param_1 + 0x48));
  if (iVar1 == 0) {
    return;
  }
  nvAssertFailedNoLog("status == NV_OK","arch/nvalloc/unix/src/os.c",0x1775);
  return;
}


// ===== 00268450 osDmabufIsSupported =====

undefined1 osDmabufIsSupported(void)

{
  return os_dma_buf_enabled;
}


// ===== 00268460 osGetEgmInfo =====

void osGetEgmInfo(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x4e0);
  }
  nv_get_egm_info(uVar1);
  return;
}


// ===== 00268480 osOfflinePageAtAddress =====

void osOfflinePageAtAddress(void)

{
  os_offline_page_at_address();
  return;
}


// ===== 00268490 osAllocatedRmClient =====

void osAllocatedRmClient(long param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x6c) = 1;
  }
  return;
}


// ===== 0026849e osDisableConsoleManagement.cold =====

void osDisableConsoleManagement_cold(void)

{
  code *pcVar1;
  
  DAT_00000348 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002684b0 osDisableConsoleManagement =====

void osDisableConsoleManagement(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x4e0) + 0x348) = 1;
    return;
  }
  DAT_00000348 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002684e0 RmInflatePageArray =====

void RmInflatePageArray(long param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5)

{
  byte bVar1;
  
  if (param_4 < param_2) {
    nvAssertFailedNoLog("pageCountFrom <= pageCountTo","arch/nvalloc/unix/src/osapi.c",0x76);
  }
  if (param_3 < param_5) {
    nvAssertFailedNoLog("pageSizeFrom >= pageSizeTo","arch/nvalloc/unix/src/osapi.c",0x77);
  }
  if (param_4 != 0) {
    bVar1 = (((param_3 & 0xff00ff00) != 0) << 3 | ((param_3 & 0xffff0000) != 0) << 4 |
             (param_3 & 0xaaaaaaaa) != 0 | ((param_3 & 0xf0f0f0f0) != 0) << 2 |
            ((param_3 & 0xcccccccc) != 0) * '\x02') -
            (((param_5 & 0xff00ff00) != 0) << 3 | ((param_5 & 0xffff0000) != 0) << 4 |
             (param_5 & 0xaaaaaaaa) != 0 | ((param_5 & 0xf0f0f0f0) != 0) << 2 |
            ((param_5 & 0xcccccccc) != 0) * '\x02');
    do {
      param_4 = param_4 - 1;
      *(ulong *)(param_1 + param_4 * 8) =
           ((long)((1 << (bVar1 & 0x1f)) + -1) & param_4) * param_5 +
           *(long *)(param_1 + (param_4 >> (bVar1 & 0x3f)) * 8);
    } while (param_4 != 0);
  }
  return;
}


// ===== 00268680 RmDeflatePageArray =====

void RmDeflatePageArray(long param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5)

{
  ulong uVar1;
  
  if (param_2 < param_4) {
    nvAssertFailedNoLog("pageCountFrom >= pageCountTo","arch/nvalloc/unix/src/osapi.c",0x91);
    if (param_5 < param_3) {
      nvAssertFailedNoLog("pageSizeFrom <= pageSizeTo","arch/nvalloc/unix/src/osapi.c",0x92);
    }
  }
  else {
    if (param_5 < param_3) {
      nvAssertFailedNoLog("pageSizeFrom <= pageSizeTo","arch/nvalloc/unix/src/osapi.c",0x92);
    }
    if (param_4 == 0) goto LAB_0026877e;
  }
  uVar1 = 0;
  do {
    *(undefined8 *)(param_1 + uVar1 * 8) =
         *(undefined8 *)
          (param_1 +
          (uVar1 << ((((param_5 & 0xff00ff00) != 0) << 3 | ((param_5 & 0xffff0000) != 0) << 4 |
                      (param_5 & 0xaaaaaaaa) != 0 | ((param_5 & 0xf0f0f0f0) != 0) << 2 |
                     ((param_5 & 0xcccccccc) != 0) * '\x02') -
                     (((param_3 & 0xff00ff00) != 0) << 3 | ((param_3 & 0xffff0000) != 0) << 4 |
                      (param_3 & 0xaaaaaaaa) != 0 | ((param_3 & 0xf0f0f0f0) != 0) << 2 |
                     ((param_3 & 0xcccccccc) != 0) * '\x02') & 0x3fU)) * 8);
    uVar1 = uVar1 + 1;
  } while (uVar1 < param_4);
  param_2 = param_2 - param_4;
  param_1 = param_1 + param_4 * 8;
LAB_0026877e:
  portMemSet(param_1,0,param_2 * 8);
  return;
}


// ===== 00268850 free_os_events =====

void free_os_events(long param_1,int param_2)

{
  long lVar1;
  int *piVar2;
  int *piVar3;
  
  lVar1 = nv_get_ctl_state();
  portSyncSpinlockAcquire(*(undefined8 *)(lVar1 + 0x2d0));
  piVar3 = *(int **)(lVar1 + 0x2c8);
  if (piVar3 != (int *)0x0) {
    piVar2 = (int *)(lVar1 + 0x2c8);
    do {
      while ((*piVar3 != param_2 && (*(long *)(piVar3 + 6) != param_1))) {
        piVar2 = piVar3 + 0xc;
LAB_002688aa:
        piVar3 = *(int **)piVar2;
        if (piVar3 == (int *)0x0) goto LAB_002688e4;
      }
      *(undefined8 *)piVar2 = *(undefined8 *)(piVar3 + 0xc);
      *(undefined1 *)(piVar3 + 9) = 0;
      if (piVar3[10] != 0) goto LAB_002688aa;
      portMemFree();
      piVar3 = *(int **)piVar2;
    } while (piVar3 != (int *)0x0);
  }
LAB_002688e4:
  portSyncSpinlockRelease(*(undefined8 *)(lVar1 + 0x2d0));
  return;
}


// ===== 00268900 _tmrEventServiceTimerWorkItem =====

void _tmrEventServiceTimerWorkItem(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = gpumgrGetGpu();
  iVar1 = tmrEventServiceTimer_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1b88),param_2);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0xd52,"_tmrEventServiceTimerWorkItem",4,
               "NVRM: Timer event failed from OS timer callback workitem with status :0x%x\n",iVar1)
  ;
  return;
}


// ===== 00268970 rm_i2c_add_adapter =====

void rm_i2c_add_adapter(long *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = 0;
  if (param_1 != (long *)0x0) {
    lVar8 = *param_1;
  }
  plVar2 = (long *)(lVar8 + 0x50);
  uVar6 = 0x10;
  uVar5 = 0;
  do {
    while (*plVar2 != 0) {
      if ((int)plVar2[1] == param_2) {
        lVar9 = 0;
        while( true ) {
          iVar1 = *(int *)(lVar8 + uVar5 * 0x18 + 0x5c + lVar9 * 4);
          if (iVar1 == -1) {
            *(undefined4 *)(lVar8 + 0xc + (lVar9 + 0x14) * 4 + uVar5 * 0x18) = param_3;
            return;
          }
          nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x1045,"rm_i2c_add_adapter",1,
                       "NVRM: %s: adapter  already exists (port=0x%x, displayId=0x%x)\n",
                       "rm_i2c_add_adapter",param_2,iVar1);
          if (lVar9 == 1) break;
          lVar9 = 1;
        }
        pcVar7 = "NVRM: %s: no more free display Id entries in adapter\n";
        uVar3 = 0x104e;
        goto LAB_00268a94;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulong)uVar4;
      plVar2 = plVar2 + 3;
      if (uVar4 == 0x10) goto LAB_002689d3;
    }
    if ((int)uVar6 == 0x10) {
      uVar6 = uVar5;
    }
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    plVar2 = plVar2 + 3;
  } while (uVar4 != 0x10);
LAB_002689d3:
  if ((int)uVar6 != 0x10) {
    uVar3 = nv_i2c_add_adapter(param_1,param_2);
    *(undefined8 *)(lVar8 + 0x50 + uVar6 * 0x18) = uVar3;
    *(int *)(lVar8 + 0x58 + uVar6 * 0x18) = param_2;
    *(undefined4 *)(lVar8 + 0x5c + uVar6 * 0x18) = param_3;
    return;
  }
  pcVar7 = "NVRM: %s: no more free adapter entries exist\n";
  uVar3 = 0x1058;
LAB_00268a94:
  nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",uVar3,"rm_i2c_add_adapter",4,pcVar7);
  return;
}


// ===== 00268b00 rm_notify_gpu_addition_removal_helper =====

void rm_notify_gpu_addition_removal_helper(long param_1,byte param_2)

{
  int iVar1;
  undefined4 local_b0;
  uint local_ac;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  iVar1 = rmapiLockAcquire(0,0x1000);
  if (iVar1 == 0) {
    local_b0 = *(undefined4 *)(param_1 + 0x24);
    local_ac = (uint)param_2;
    CliAddSystemEvent(3,&local_b0,0);
    rmapiLockRelease();
  }
  else {
    nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x17b9,"rm_notify_gpu_addition_removal_helper",4,
                 "NVRM: Fail to acquire rmApi lock. Skip notification.");
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 00268bb0 _deferredClientListFreeCallback =====

void _deferredClientListFreeCallback(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = serverFreeDisabledClients(g_resServ,0,*(undefined4 *)(g_pSys + 0x184));
  if (iVar1 != 0) {
    iVar1 = osQueueSystemWorkItem(_deferredClientListFreeCallback,param_1);
    if (iVar1 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0xb9a,"_deferredClientListFreeCallback",2,
                   "NVRM: Failed to schedule deferred free callback. Freeing immediately.\n");
      serverFreeDisabledClients(g_resServ,0,0);
      return;
    }
  }
  return;
}


// ===== 00268c40 RmGetGpuUuidRaw.part.0 =====

long RmGetGpuUuidRaw_part_0(long *param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long local_30;
  
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    iVar3 = rmapiLockAcquire(2,0x80000);
    if (iVar3 == 0) {
      bVar1 = true;
      goto LAB_00268c67;
    }
LAB_00268cbd:
    local_30 = 0;
  }
  else {
    bVar1 = false;
LAB_00268c67:
    lVar4 = 0;
    if ((((long *)*param_1 == (long *)0x0) || (lVar4 = *(long *)*param_1, lVar4 == 0)) ||
       (*(char *)(lVar4 + 0x490e) == '\0')) {
      if (*(char *)((long)param_1 + 0x3d) == '\0') {
        iVar3 = pciPbiReadUuid(param_1[9],(long)param_1 + 0x2d);
        *(undefined1 *)((long)param_1 + 0x3d) = 1;
        *(int *)(param_1 + 8) = iVar3;
      }
      else {
        iVar3 = (int)param_1[8];
      }
      if (iVar3 != 0) {
        if (iVar3 == 0x56) goto LAB_00268c81;
        goto joined_r0x00268ced;
      }
      iVar3 = gpumgrSetUuid(*(undefined4 *)((long)param_1 + 0x24),(long)param_1 + 0x2d);
      if (iVar3 != 0) {
        if (!bVar1) goto LAB_00268cbd;
        goto LAB_00268da0;
      }
    }
    else {
LAB_00268c81:
      nv_printf(0,"NVRM: PBI is not supported for GPU %04x:%02x:%02x.%x\n",
                *(undefined4 *)((long)param_1 + 0x14),(char)param_1[3],
                *(undefined1 *)((long)param_1 + 0x19),*(undefined1 *)((long)param_1 + 0x1a));
joined_r0x00268ced:
      if (((lVar4 == 0) || (iVar3 = gpuGetGidInfo_IMPL(lVar4,0,0,2), iVar3 != 0)) ||
         (*(char *)(lVar4 + 0x7c4) == '\0')) {
        if (bVar1) {
LAB_00268da0:
          rmapiLockRelease();
        }
        goto LAB_00268cbd;
      }
      os_mem_copy((long)param_1 + 0x2d,lVar4 + 0x7c5,0x10);
    }
    local_30 = (long)param_1 + 0x2d;
    *(undefined1 *)((long)param_1 + 0x2c) = 1;
    if (!bVar1) {
      return local_30;
    }
    rmapiLockRelease();
  }
  return local_30;
}


// ===== 00268e00 RmGetMmapPteArray =====

int RmGetMmapPteArray(long param_1,undefined8 param_2,undefined4 param_3,long param_4)

{
  long *plVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  ulong extraout_RDX;
  ulong uVar6;
  ulong uVar7;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong uVar8;
  undefined8 *puVar9;
  undefined1 auVar10 [16];
  long local_30;
  
  if (param_4 == 0) {
    return 0x1f;
  }
  iVar3 = clientGetResourceRef_IMPL(param_2,param_3,&local_30);
  if (iVar3 == 0) {
    auVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_30 + 8),__nvoc_class_def_Memory);
    uVar6 = auVar10._8_8_;
    if (auVar10._0_8_ == 0) {
      cVar2 = *(char *)(param_4 + 0x48);
      goto LAB_00268e3b;
    }
    puVar9 = *(undefined8 **)(auVar10._0_8_ + 0x118);
    cVar2 = memdescGetContiguity(puVar9,0);
    *(char *)(param_4 + 0x48) = cVar2;
    uVar6 = extraout_RDX_00;
    if (cVar2 == '\0') goto LAB_00268f14;
LAB_00268e43:
    uVar6 = *(ulong *)(*(long *)(param_4 + 0x28) + 8);
    uVar4 = uVar6 / os_page_size;
    uVar6 = uVar6 % os_page_size;
  }
  else {
    cVar2 = *(char *)(param_4 + 0x48);
    uVar6 = extraout_RDX;
LAB_00268e3b:
    puVar9 = (undefined8 *)0x0;
    if (cVar2 != '\0') goto LAB_00268e43;
LAB_00268f14:
    if ((*(char *)(g_pSys + 400) == '\0') ||
       (cVar2 = memdescGetContiguity(puVar9,0), uVar6 = extraout_RDX_01, cVar2 != '\0')) {
      uVar4 = *(ulong *)(*(long *)(param_4 + 0x28) + 8) >> 0xc;
    }
    else {
      uVar7 = (ulong)*(uint *)(puVar9 + 0x2c);
      if (os_page_size < *(uint *)(puVar9 + 0x2c)) {
        uVar7 = os_page_size;
      }
      uVar6 = *(ulong *)(*(long *)(param_4 + 0x28) + 8);
      uVar4 = uVar6 / uVar7;
      uVar6 = uVar6 % uVar7;
    }
  }
  if (uVar4 == 0) {
    nvAssertFailedNoLog("pages != 0","arch/nvalloc/unix/src/osapi.c",0x8c9);
    return 0x1f;
  }
  iVar3 = os_alloc_mem(param_4 + 0x18,uVar4 * 8,uVar6);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar6 = uVar4;
  if (*(char *)(param_4 + 0x48) != '\0') {
    **(undefined8 **)(param_4 + 0x18) = **(undefined8 **)(param_4 + 0x28);
    lVar5 = 0;
    uVar7 = 1;
    if (uVar4 != 1) {
      do {
        plVar1 = (long *)(*(long *)(param_4 + 0x18) + lVar5);
        lVar5 = lVar5 + 8;
        *(ulong *)(*(long *)(param_4 + 0x18) + uVar7 * 8) = os_page_size + *plVar1;
        uVar7 = uVar7 + 1;
      } while (uVar7 != uVar4);
    }
    goto LAB_00268ec0;
  }
  lVar5 = memdescGetPteArrayForGpu(puVar9,*puVar9,0);
  if ((*(char *)(g_pSys + 400) == '\0') || (cVar2 = memdescGetContiguity(puVar9,0), cVar2 != '\0'))
  {
    uVar7 = *(ulong *)(param_4 + 0x10) >> 0xc;
  }
  else {
    uVar7 = (ulong)*(uint *)(puVar9 + 0x2c);
    if (os_page_size < *(uint *)(puVar9 + 0x2c)) {
      uVar7 = os_page_size;
    }
    uVar7 = *(ulong *)(param_4 + 0x10) / uVar7;
  }
  uVar8 = puVar9[4];
  if (uVar4 <= (ulong)puVar9[4]) {
    uVar8 = uVar4;
  }
  portMemCopy(*(undefined8 *)(param_4 + 0x18),uVar8 << 3,lVar5 + uVar7 * 8,uVar8 << 3);
  if ((*(char *)(g_pSys + 400) == '\0') || (cVar2 = memdescGetContiguity(puVar9,0), cVar2 != '\0'))
  {
    if (0x1000 < os_page_size) {
      RmDeflatePageArray(*(undefined8 *)(param_4 + 0x18),uVar4,0x1000,
                         (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & uVar4) != 0) +
                         (uVar4 >> (os_page_shift - 0xcU & 0x3f)));
      uVar6 = (uVar4 >> (os_page_shift - 0xcU & 0x3f)) +
              (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) & uVar4) != 0);
      goto LAB_002691a8;
    }
LAB_00269012:
    lVar5 = *(long *)(param_4 + 0x18);
    uVar4 = uVar6;
  }
  else {
    uVar8 = (ulong)*(uint *)(puVar9 + 0x2c);
    lVar5 = *(long *)(param_4 + 0x18);
    uVar7 = *(ulong *)(*(long *)(param_4 + 0x28) + 8);
    uVar6 = uVar7 / os_page_size;
    uVar7 = uVar7 / uVar8;
    if (uVar8 < os_page_size) {
      RmDeflatePageArray(lVar5,uVar7,uVar8,uVar6);
LAB_002691a8:
      if (uVar6 == 0) goto LAB_00268ec0;
      goto LAB_00269012;
    }
    if (os_page_size < uVar8) {
      RmInflatePageArray(lVar5,uVar7,uVar8,uVar6);
      lVar5 = *(long *)(param_4 + 0x18);
    }
  }
  uVar6 = uVar4;
  uVar4 = 0;
  while( true ) {
    plVar1 = (long *)(lVar5 + uVar4 * 8);
    *plVar1 = *plVar1 + *(long *)(param_1 + 0x478);
    uVar4 = uVar4 + 1;
    if (uVar4 == uVar6) break;
    lVar5 = *(long *)(param_4 + 0x18);
  }
LAB_00268ec0:
  *(ulong *)(param_4 + 0x20) = uVar6;
  return 0;
}


// ===== 002691e0 convertPageArrayBetweenOsAndRm =====

void convertPageArrayBetweenOsAndRm
               (undefined8 param_1,undefined8 param_2,ulong param_3,undefined8 param_4,ulong param_5
               ,undefined8 *param_6)

{
  if (param_3 < param_5) {
    RmDeflatePageArray();
    if (param_6 != (undefined8 *)0x0) {
      *param_6 = param_4;
    }
    return;
  }
  if (param_3 <= param_5) {
    return;
  }
  RmInflatePageArray();
  return;
}


// ===== 00269220 RmUnixRmApiPrologue =====

undefined8 RmUnixRmApiPrologue(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  threadStateInit(param_2,0);
  iVar1 = rmapiLockAcquire(0,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x310) != 0) {
      iVar1 = os_ref_dynamic_power(param_1,2);
      if (iVar1 == 0) {
        uVar2 = rmapiGetInterface(3);
        return uVar2;
      }
    }
    rmapiLockRelease();
  }
  threadStateFree(param_2,0);
  return 0;
}


// ===== 002692b0 RmGpuHasIOSpaceEnabled =====

byte RmGpuHasIOSpaceEnabled(long param_1)

{
  byte local_a [2];
  
  os_pci_read_word(*(undefined8 *)(param_1 + 0x48),4,local_a);
  return local_a[0] & 1;
}


// ===== 002692e0 osHandleDeferredRecovery =====

void osHandleDeferredRecovery(void)

{
  return;
}


// ===== 002692f0 osIsSwPreInitOnly =====

undefined8 osIsSwPreInitOnly(void)

{
  return 0;
}


// ===== 00269300 RmGetGpuUuidRaw =====

long RmGetGpuUuidRaw(long param_1)

{
  long lVar1;
  
  if (*(char *)(param_1 + 0x2c) != '\0') {
    return param_1 + 0x2d;
  }
  lVar1 = RmGetGpuUuidRaw_part_0();
  return lVar1;
}


// ===== 00269320 RmLogGpuCrash =====

void RmLogGpuCrash(long param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  cVar1 = *(char *)(param_1 + 0x44c);
  cVar2 = *(char *)(param_1 + 0x455);
  if ((cVar1 == '\0') || (cVar2 != '\0')) {
    if (*(int *)(**(long **)(param_1 + 0x4e0) + 8) ==
        **(int **)((*(long **)(param_1 + 0x4e0))[0x21] + 0x20)) {
      *(undefined1 *)(param_1 + 0x44c) = 1;
      *(undefined1 *)(param_1 + 0x455) = 0;
    }
  }
  iVar4 = rcdbAddRmGpuDump(param_1);
  if ((iVar4 == 0) || (iVar4 == 0x10005)) {
    nv_printf(4,
              "NVRM: A GPU crash dump has been created. If possible, please run\nNVRM: nvidia-bug-report.sh as root to collect this data before\nNVRM: the NVIDIA kernel module is unloaded.\n"
             );
    if (*(char *)(param_1 + 0x909) == '\0') {
      cVar3 = hypervisorIsVgxHyper_IMPL();
      if (cVar3 != '\0') {
        nv_printf(4,"NVRM: Dumping nvlogs buffers\n");
        nvlogDumpToKernelLog(0);
      }
    }
  }
  else {
    nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x1b5,"RmLogGpuCrash",4,
                 "NVRM: %s: failed to save GPU crash data\n");
  }
  *(char *)(param_1 + 0x44c) = cVar1;
  *(char *)(param_1 + 0x455) = cVar2;
  osModifyGpuSwStatePersistence(*(undefined8 *)(param_1 + 0x4e0),*(undefined1 *)(param_1 + 0x453));
  return;
}


// ===== 00269440 rm_client_free_os_events =====

void rm_client_free_os_events(undefined4 param_1)

{
  free_os_events(0,param_1);
  return;
}


// ===== 00269450 RmFreeUnusedClients =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmFreeUnusedClients(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint local_34;
  long local_30 [2];
  
  lVar3 = rmapiGetInterface(3);
  iVar2 = rmapiGetClientHandlesFromOSInfo(param_2,local_30,&local_34);
  if (iVar2 == 0) {
    if (local_34 != 0) {
      lVar4 = 0;
      do {
        lVar1 = lVar4 * 4;
        lVar4 = lVar4 + 1;
        nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x239,"RmFreeUnusedClients",1,
                     "NVRM: freeing abandoned client 0x%x\n",*(undefined4 *)(local_30[0] + lVar1));
      } while ((uint)lVar4 < local_34);
      if (local_34 != 0) {
        (**(code **)(lVar3 + 0x28))(lVar3,local_30[0]);
        portMemFree(local_30[0]);
      }
    }
  }
  else {
    local_34 = 0;
  }
  free_os_events(param_2,0);
  return;
}


// ===== 00269530 RmPowerSourceChangeEvent =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void RmPowerSourceChangeEvent(long param_1,int param_2)

{
  long lVar1;
  uint local_1c;
  
  local_1c = 0;
  lVar1 = rmapiGetInterface(4);
  local_1c = (uint)(param_2 != 0);
  (**(code **)(lVar1 + 0x38))
            (lVar1,*(undefined4 *)(param_1 + 0x310),*(undefined4 *)(param_1 + 0x318),0x2080205b,
             &local_1c,4);
  return;
}


// ===== 002695a0 RmRequestDNotifierState =====

undefined8 RmRequestDNotifierState(long *param_1)

{
  undefined8 uVar1;
  undefined2 local_e;
  undefined4 local_c;
  
  uVar1 = 0;
  if ((param_1 != (long *)0x0) && (uVar1 = 0, (undefined8 *)*param_1 != (undefined8 *)0x0)) {
    uVar1 = *(undefined8 *)*param_1;
  }
  local_e = 4;
  local_c = 0;
  uVar1 = osCallACPI_DSM(uVar1,6,0x12,&local_c,&local_e);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x500,"RmRequestDNotifierState",1,
               "NVRM: %s: Failed to request Dx event update, status 0x%x\n");
  return uVar1;
}


// ===== 00269630 rm_init_private_state =====

void rm_init_private_state(undefined8 param_1,undefined8 param_2)

{
  RmInitPrivateState(param_2);
  return;
}


// ===== 00269640 rm_free_private_state =====

void rm_free_private_state(undefined8 param_1,undefined8 param_2)

{
  RmFreePrivateState(param_2);
  return;
}


// ===== 00269650 rm_init_adapter =====

undefined4 rm_init_adapter(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c8 [4];
  undefined1 local_c4 [4];
  undefined1 local_c0 [4];
  undefined1 local_bc [4];
  long local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0x80);
  local_b0 = 0;
  nv_get_screen_info(param_2,&local_b0,local_c8,local_c4,local_c0,local_bc,&local_b8);
  *(bool *)(param_2 + 0x348) = local_b8 != 0;
  if ((local_b8 != 0) && (*(char *)(param_2 + 0x349) == '\0')) {
    os_disable_console_access();
  }
  uVar2 = 0;
  iVar1 = rmapiLockAcquire(0,0x400000);
  if (iVar1 == 0) {
    iVar1 = gpumgrQueryGpuDrainState(*(undefined4 *)(param_2 + 0x24),&local_b0,0);
    if ((iVar1 != 0) || ((char)local_b0 == '\0')) {
      if ((*(byte *)(param_2 + 0x11) & 8) == 0) {
        uVar2 = RmInitAdapter(param_2);
      }
      else {
        uVar2 = RmPartiallyInitAdapter();
      }
    }
    rmapiLockRelease();
  }
  if ((*(char *)(param_2 + 0x348) != '\0') && (*(char *)(param_2 + 0x349) == '\0')) {
    os_enable_console_access();
  }
  threadStateFree(local_a8,0);
  return uVar2;
}


// ===== 00269790 rm_disable_adapter =====

void rm_disable_adapter(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  iVar1 = os_flush_work_queue(*(undefined8 *)(param_2 + 0x2f0),1);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"os_flush_work_queue(pNv->queue, NV_TRUE)","arch/nvalloc/unix/src/osapi.c",
               0x6ec);
  }
  if ((*(char *)(param_2 + 0x348) != '\0') && (*(char *)(param_2 + 0x349) == '\0')) {
    os_disable_console_access();
  }
  iVar1 = rmapiLockAcquire(0,0x800001);
  if (iVar1 == 0) {
    if ((*(byte *)(param_2 + 0x11) & 8) == 0) {
      RmDisableAdapter();
    }
    else {
      RmPartiallyDisableAdapter(param_2);
    }
    rmapiLockRelease();
  }
  if ((*(char *)(param_2 + 0x348) != '\0') && (*(char *)(param_2 + 0x349) == '\0')) {
    os_enable_console_access();
  }
  iVar1 = os_flush_work_queue(*(undefined8 *)(param_2 + 0x2f0),1);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"os_flush_work_queue(pNv->queue, NV_TRUE)","arch/nvalloc/unix/src/osapi.c",
               0x708);
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 002698b0 rm_shutdown_adapter =====

void rm_shutdown_adapter(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  if ((*(char *)(param_2 + 0x348) != '\0') && (*(char *)(param_2 + 0x349) == '\0')) {
    os_disable_console_access();
  }
  iVar1 = rmapiLockAcquire(0,0x800001);
  if (iVar1 == 0) {
    RmShutdownAdapter(param_2);
    rmapiLockRelease();
  }
  if ((*(char *)(param_2 + 0x348) != '\0') && (*(char *)(param_2 + 0x349) == '\0')) {
    os_enable_console_access();
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 00269950 rm_exclude_adapter =====

undefined4 rm_exclude_adapter(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  uVar1 = RmExcludeAdapter(param_2);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 002699a0 rm_acquire_api_lock =====

undefined4 rm_acquire_api_lock(void)

{
  undefined4 uVar1;
  undefined1 local_98 [144];
  
  threadStateInit(local_98,0);
  uVar1 = rmapiLockAcquire(0,0x1000);
  threadStateFree(local_98,0);
  return uVar1;
}


// ===== 002699f0 rm_release_api_lock =====

undefined8 rm_release_api_lock(void)

{
  undefined1 local_98 [144];
  
  threadStateInit(local_98,0);
  rmapiLockRelease();
  threadStateFree(local_98,0);
  return 0;
}


// ===== 00269a30 rm_acquire_gpu_lock =====

undefined4 rm_acquire_gpu_lock(undefined8 param_1,long *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  uVar2 = 0;
  if ((param_2 != (long *)0x0) && (uVar2 = 0, (undefined8 *)*param_2 != (undefined8 *)0x0)) {
    uVar2 = *(undefined8 *)*param_2;
  }
  uVar1 = rmDeviceGpuLocksAcquire(uVar2,0,0x1000);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 00269a90 rm_release_gpu_lock =====

undefined8 rm_release_gpu_lock(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  uVar1 = 0;
  if ((param_2 != (long *)0x0) && (uVar1 = 0, (undefined8 *)*param_2 != (undefined8 *)0x0)) {
    uVar1 = *(undefined8 *)*param_2;
  }
  rmDeviceGpuLocksRelease(uVar1,0,0);
  threadStateFree(local_a8,0);
  return 0;
}


// ===== 00269af0 rm_acquire_all_gpus_lock =====

undefined4 rm_acquire_all_gpus_lock(void)

{
  undefined4 uVar1;
  undefined1 local_98 [144];
  
  threadStateInit(local_98,0);
  uVar1 = rmGpuLocksAcquire(0,0x1000);
  threadStateFree(local_98,0);
  return uVar1;
}


// ===== 00269b40 rm_release_all_gpus_lock =====

undefined8 rm_release_all_gpus_lock(void)

{
  undefined1 local_98 [144];
  
  threadStateInit(local_98,0);
  rmGpuLocksRelease(0,0);
  threadStateFree(local_98,0);
  return 0;
}


// ===== 00269b80 rm_acpi_notify =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong rm_acpi_notify(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 local_b0;
  undefined1 local_a8 [152];
  
  if (param_3 == 0xc0) {
    local_b0 = 0;
    lVar4 = RmUnixRmApiPrologue(param_2,local_a8,0x4001);
    uVar3 = 0;
    if (lVar4 != 0) {
      local_b0 = CONCAT44(local_b0._4_4_,800);
      uVar2 = (**(code **)(lVar4 + 0x38))
                        (lVar4,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x310),
                         0x122,&local_b0,8);
      os_unref_dynamic_power(param_2,2);
      rmapiLockRelease();
      threadStateFree(local_a8,0);
      uVar3 = (ulong)uVar2;
      if (uVar2 != 0) {
        uVar3 = nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x7ea,"RmHandleGPSStatusChange",4,
                             "NVRM: %s: Failed to handle ACPI GPS status change event, status=0x%x\n"
                             ,"RmHandleGPSStatusChange",uVar3);
      }
    }
  }
  else if (param_3 < 0xc1) {
    if (param_3 != 0x81) {
LAB_00269da8:
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x819,"rm_acpi_notify",1,
                   "NVRM: No support for 0x%x event\n",param_3);
      uVar3 = nvAssertFailedNoLog(&DAT_00ccdb19,"arch/nvalloc/unix/src/osapi.c",0x81a);
      return uVar3;
    }
    threadStateInit(local_a8,0);
    RmHandleDisplayChange(param_1,param_2);
    uVar3 = threadStateFree(local_a8,0);
  }
  else {
    if (4 < param_3 - 0xd1) goto LAB_00269da8;
    if (param_3 == 0xd4) {
      iVar1 = 3;
    }
    else {
      iVar1 = 4;
      if ((param_3 != 0xd5) && (iVar1 = 1, param_3 != 0xd2)) {
        iVar1 = (uint)(param_3 == 0xd3) * 2;
      }
    }
    local_b0 = CONCAT44(local_b0._4_4_,iVar1);
    lVar4 = RmUnixRmApiPrologue(param_2,local_a8,0x4001);
    uVar3 = 0;
    if (lVar4 != 0) {
      uVar2 = (**(code **)(lVar4 + 0x38))
                        (lVar4,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x318),
                         0x20802092,&local_b0,4);
      os_unref_dynamic_power(param_2,2);
      rmapiLockRelease();
      threadStateFree(local_a8,0);
      uVar3 = (ulong)uVar2;
      if (uVar2 != 0) {
        nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x53c,"RmHandleDNotifierEvent",4,
                     "NVRM: %s: Failed to handle ACPI D-Notifier event, status=0x%x\n");
      }
    }
  }
  return uVar3;
}


// ===== 00269dfa rm_create_mmap_context.cold =====

void rm_create_mmap_context_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  
  *(undefined8 *)(unaff_RBP + -0x60) = 0;
  *(undefined8 *)(unaff_RBP + -0x58) = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00269e10 rm_create_mmap_context =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int rm_create_mmap_context
              (undefined4 param_1,int param_2,undefined4 param_3,ulong param_4,ulong param_5,
              ulong param_6,undefined4 param_7,undefined4 param_8)

{
  ulong *puVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  undefined4 uVar15;
  ulong uVar16;
  ulong *puVar17;
  bool bVar18;
  undefined8 local_80;
  long local_78;
  long local_70;
  long local_68;
  ulong *local_60;
  long local_58;
  ulong local_50;
  ulong local_48;
  undefined8 local_40;
  
  iVar6 = rmapiLockAcquire(2,0x1000);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = serverutilAcquireClient(param_1,0,&local_80,&local_78);
  if (iVar6 != 0) {
    rmapiLockRelease();
    return 0x23;
  }
  iVar6 = *(int *)(local_78 + 0x118);
  iVar7 = osGetCurrentProcess();
  iVar8 = 0x23;
  if ((iVar6 != iVar7) || (iVar8 = rmGpuLocksAcquire(0,0x1000), iVar8 != 0)) goto LAB_00269e96;
  local_70 = 0;
  if (local_78 == 0) {
    local_68 = 0;
    local_60 = (ulong *)0x0;
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar11 = *(long *)(local_78 + 0x100);
  local_68 = 0;
  local_60 = (ulong *)0x0;
  if ((param_2 == *(int *)(lVar11 + 0x48)) ||
     (iVar6 = CliSetGpuContext(*(int *)(lVar11 + 0x48),param_2,&local_70,0), iVar6 == 0)) {
LAB_00269f3b:
    local_60 = (ulong *)tlsEntryGet(2);
    if (local_60 != (ulong *)0x0) {
      iVar6 = tlsEntryRelease(2);
      if (iVar6 != 0) {
        nvAssertFailedNoLog("tlsEntryRelease(TLS_ENTRY_ID_MAPPING_CONTEXT) == 0",
                            "arch/nvalloc/unix/src/osapi.c",0x942);
      }
      if (local_70 == 0) {
        lVar9 = 0;
LAB_0026a485:
        lVar11 = 0;
        uVar15 = 3;
      }
      else {
        lVar9 = *(long *)(local_70 + 0x4e0);
        lVar11 = 0;
        uVar15 = 3;
      }
LAB_00269f80:
      iVar8 = nv_add_mapping_context_to_file(lVar9,local_60,uVar15,lVar11,local_68,param_8);
      goto LAB_00269f9a;
    }
    iVar8 = os_alloc_mem(&local_60,0x50);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"os_alloc_mem((void**)&nvuap, sizeof(nv_usermap_access_params_t))",
                 "arch/nvalloc/unix/src/osapi.c",0x94c);
      goto LAB_00269fcc;
    }
    portMemSet(local_60,0,0x50);
    iVar8 = os_alloc_mem(local_60 + 5,0x10);
    if (iVar8 == 0) {
      *local_60 = param_4;
      uVar13 = os_page_size;
      *(undefined4 *)((long)local_60 + 0x4c) = param_7;
      uVar16 = *local_60;
      uVar14 = uVar13 - 1;
      uVar13 = -uVar13;
      local_60[2] = param_6;
      local_60[1] = param_5;
      *(undefined1 *)(local_60 + 9) = 1;
      local_60[6] = 1;
      *(ulong *)local_60[5] = uVar16 & uVar13;
      *(ulong *)(local_60[5] + 8) = (uVar16 & uVar14) + uVar14 + param_5 & uVar13;
      local_60[2] = local_60[2] & uVar13;
      if (local_70 == 0) {
LAB_0026a199:
        lVar9 = nv_get_ctl_state();
        uVar14 = os_page_mask;
        cVar4 = rmapiLockIsOwner();
        if (cVar4 == '\0') {
          nvAssertFailedNoLog("rmapiLockIsOwner()","arch/nvalloc/unix/src/osapi.c",0xa00);
          iVar8 = 0x2f;
        }
        else {
          iVar8 = clientGetResourceRef_IMPL(*(undefined8 *)(local_78 + 0x100),param_3,&local_50);
          if (iVar8 == 0) {
            plVar10 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_50 + 8),
                                                 __nvoc_class_def_RmResource);
            if (plVar10 == (long *)0x0) {
              iVar8 = 0x31;
            }
            else {
              iVar8 = (**(code **)(*plVar10 + 0x110))
                                (plVar10,&local_58,*(code **)(*plVar10 + 0x110));
              if (iVar8 == 0) {
                cVar4 = memdescGetFlag(local_58,0x100000000);
                cVar5 = memdescGetFlag(local_58,0x80000000);
                if (((cVar5 == '\0' && *(char *)(local_58 + 100) == '\0') &&
                    ((*(ulong *)(local_58 + 8) & 0x88000000000000) == 0)) &&
                   (cVar5 = memdescGetFlag(local_58,0x20000000000000), cVar5 == '\0')) {
                  nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0xa19,"RmGetAllocPrivate",4,
                               "NVRM: Mmap is not allowed\n");
                }
                else {
                  iVar6 = memdescGetAddressSpace(local_58);
                  if ((iVar6 == 1) && (lVar11 = memdescGetMemData(local_58), lVar11 != 0)) {
                    iVar8 = os_match_mmap_offset(lVar11,param_4 & uVar14,&local_68);
                    if (iVar8 != 0) goto LAB_00269f9a;
                    uVar14 = (ulong)(~(uint)uVar14 & (uint)param_4);
                    uVar16 = param_5 + uVar14;
                    if ((!CARRY8(param_5,uVar14)) &&
                       (uVar14 = uVar16 / os_page_size,
                       uVar16 = (ulong)(uVar16 % os_page_size != 0) + local_68,
                       uVar13 = uVar16 + uVar14, !CARRY8(uVar16,uVar14))) {
                      if ((*(char *)(g_pSys + 400) == '\0') ||
                         (cVar5 = memdescGetContiguity(local_58,0), cVar5 != '\0')) {
                        if (uVar13 <= (ulong)(((long)((1 << (os_page_shift - 0xcU & 0x1f)) + -1) &
                                              *(ulong *)(local_58 + 0x18)) != 0) +
                                      (*(ulong *)(local_58 + 0x18) >> (os_page_shift - 0xcU & 0x3f))
                           ) goto LAB_0026a344;
                      }
                      else {
                        if (uVar13 <= *(ulong *)(local_58 + 0x18)) {
LAB_0026a344:
                          uVar15 = 1;
                          if (cVar4 == '\0') {
                            uVar15 = 3;
                          }
                          goto LAB_00269f80;
                        }
                        nvAssertFailedNoLog("pageCount <= pMemDesc->PageCount",
                                            "arch/nvalloc/unix/src/osapi.c",0xa43);
                      }
                    }
LAB_0026a652:
                    iVar8 = 0x1f;
                    goto LAB_00269f9a;
                  }
                }
                iVar8 = 0x57;
              }
            }
          }
        }
      }
      else {
        lVar12 = *(long *)(local_70 + 0x1b70);
        lVar9 = *(long *)(local_70 + 0x4e0);
        if (lVar12 == 0) {
LAB_0026a48f:
          bVar18 = false;
          bVar3 = false;
        }
        else if (*(char *)(local_70 + 0x454) == '\0') {
          bVar18 = false;
          bVar3 = false;
        }
        else if (((*(long *)(lVar12 + 0x4b0) == 0) ||
                 (uVar14 = *(long *)(lVar12 + 0x4a8) + *(ulong *)(lVar12 + 0x478), param_4 < uVar14)
                 ) || (*(long *)(lVar12 + 0x4b0) + uVar14 < param_4 + param_5)) {
          if (param_4 < *(ulong *)(lVar12 + 0x478)) goto LAB_0026a48f;
          bVar18 = param_4 + param_5 <= *(ulong *)(lVar12 + 0x480);
          bVar3 = false;
        }
        else {
          bVar18 = false;
          bVar3 = true;
        }
        if (lVar9 == 0) goto LAB_0026a199;
        uVar14 = **(ulong **)(lVar9 + 0x108);
        if (((((param_4 < uVar14) || (CARRY8(param_5 - 1,param_4))) ||
             ((uVar14 + (*(ulong **)(lVar9 + 0x108))[1]) - 1 < (param_5 - 1) + param_4)) &&
            (((puVar1 = *(ulong **)(lVar9 + 0x140), puVar1 == (ulong *)0x0 || (puVar1[1] == 0)) ||
             ((param_4 < *puVar1 ||
              ((CARRY8(param_5 - 1,param_4) || ((puVar1[1] - 1) + *puVar1 < (param_5 - 1) + param_4)
               ))))))) && (!bVar18 && !bVar3)) {
          uVar14 = *(ulong *)(lVar9 + 0xe0);
          if ((((uVar14 != 0) && (*(long *)(lVar9 + 0xe8) != 0)) && (uVar14 <= param_4)) &&
             ((!CARRY8(param_5 - 1,param_4) &&
              ((param_5 - 1) + param_4 <= (uVar14 - 1) + *(long *)(lVar9 + 0xe8)))))
          goto LAB_0026a3a1;
          goto LAB_0026a199;
        }
        if (bVar3) {
          iVar8 = RmGetMmapPteArray(lVar12,lVar11,param_3,local_60);
          if (iVar8 != 0) goto LAB_00269f9a;
LAB_0026a3a9:
          if ((char)local_60[9] != '\0') goto LAB_0026a3b7;
          puVar1 = (ulong *)local_60[3];
          if (puVar1 != (ulong *)0x0) {
            uVar16 = *puVar1;
            uVar14 = uVar16;
            if (1 < local_60[4]) {
              puVar17 = puVar1 + 1;
              do {
                uVar13 = *puVar17;
                if (uVar16 < uVar13) {
                  uVar16 = uVar13;
                }
                if (uVar13 < uVar14) {
                  uVar14 = uVar13;
                }
                puVar17 = puVar17 + 1;
              } while (puVar17 != puVar1 + local_60[4]);
            }
            lVar11 = uVar16 + os_page_size;
            local_60[7] = uVar14;
            uVar16 = lVar11 - uVar14;
            local_60[8] = uVar16;
            goto LAB_0026a3ca;
          }
LAB_0026a635:
          nvAssertOkFailedNoLog
                    (0x1f,"RmSetUserMapAccessRange(nvuap)","arch/nvalloc/unix/src/osapi.c",0x99e);
          goto LAB_0026a652;
        }
LAB_0026a3a1:
        if (!bVar18) goto LAB_0026a3a9;
        iVar8 = RmGetMmapPteArray(lVar12,lVar11,param_3,local_60);
        if (iVar8 != 0) goto LAB_00269f9a;
        os_free_mem(local_60[3]);
        local_60[3] = 0;
        if ((char)local_60[9] == '\0') goto LAB_0026a635;
LAB_0026a3b7:
        uVar14 = *(ulong *)local_60[5];
        local_60[7] = uVar14;
        uVar16 = ((ulong *)local_60[5])[1];
        local_60[8] = uVar16;
LAB_0026a3ca:
        local_50 = 0;
        local_48 = 0;
        local_40 = 0;
        lVar12 = rmapiGetInterface(4);
        cVar4 = osIsAdministrator();
        lVar11 = 0;
        if (cVar4 != '\0') goto LAB_0026a485;
        local_50 = uVar14;
        local_48 = uVar16;
        iVar8 = (**(code **)(lVar12 + 0x38))
                          (lVar12,*(undefined4 *)(lVar9 + 0x310),*(undefined4 *)(lVar9 + 0x318),
                           0x20800198,&local_50,0x18);
        if (iVar8 == 0) {
          uVar15 = (undefined4)local_40;
          goto LAB_00269f80;
        }
      }
LAB_00269f9a:
      os_free_mem(local_60[5]);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,"os_alloc_mem((void**)&(nvuap->memArea.pRanges), sizeof(MemoryRange))",
                 "arch/nvalloc/unix/src/osapi.c",0x94f);
    }
    os_free_mem(local_60);
  }
  else {
    iVar8 = subdeviceGetByHandle_IMPL(lVar11,param_2,&local_50);
    if (iVar8 == 0) {
      local_70 = *(long *)(*(long *)(local_50 + 0x158) + 0xe0);
      goto LAB_00269f3b;
    }
  }
LAB_00269fcc:
  rmGpuLocksRelease(0,0);
LAB_00269e96:
  serverutilReleaseClient(0,local_80);
  rmapiLockRelease();
  return iVar8;
}


// ===== 0026a780 rm_get_adapter_status =====

undefined4 rm_get_adapter_status(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = rmapiLockAcquire(2,0x1000);
  if (iVar1 != 0) {
    return 0x59;
  }
  uVar2 = RmGetAdapterStatus(param_1,param_2);
  rmapiLockRelease();
  return uVar2;
}


// ===== 0026a7e0 rm_get_adapter_status_external =====

undefined4 rm_get_adapter_status_external(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_1c [3];
  
  iVar1 = rmapiLockAcquire(2,0x1000);
  if (iVar1 == 0) {
    iVar1 = RmGetAdapterStatus(param_2,local_1c);
    rmapiLockRelease();
    if (iVar1 == 0) {
      return local_1c[0];
    }
  }
  return 0x59;
}


// ===== 0026a830 rm_init_rm =====

void rm_init_rm(void)

{
  RmInitRm();
  return;
}


// ===== 0026a840 rm_shutdown_rm =====

void rm_shutdown_rm(void)

{
  RmShutdownRm();
  return;
}


// ===== 0026a850 rm_init_event_locks =====

bool rm_init_event_locks(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  lVar2 = portSyncSpinlockCreate(uVar1);
  *(long *)(param_2 + 0x2d0) = lVar2;
  return lVar2 != 0;
}


// ===== 0026a880 rm_destroy_event_locks =====

void rm_destroy_event_locks(undefined8 param_1,long param_2)

{
  if ((param_2 != 0) && (*(long *)(param_2 + 0x2d0) != 0)) {
    portSyncSpinlockDestroy();
    return;
  }
  return;
}


// ===== 0026a8b0 rm_stop_user_channels =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined4 rm_stop_user_channels(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 local_a9;
  undefined1 local_a8 [152];
  
  local_a9 = 0;
  lVar2 = RmUnixRmApiPrologue(param_2,local_a8,0x80003);
  if (lVar2 != 0) {
    local_a9 = 1;
    uVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x318),
                       0x20801117,&local_a9,1);
    os_unref_dynamic_power(param_2,2);
    rmapiLockRelease();
    threadStateFree(local_a8,0);
    return uVar1;
  }
  return 0x40;
}


// ===== 0026a960 rm_restart_user_channels =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined4 rm_restart_user_channels(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 local_a9;
  undefined1 local_a8 [152];
  
  local_a9 = 0;
  lVar2 = RmUnixRmApiPrologue(param_2,local_a8,0x80003);
  if (lVar2 != 0) {
    local_a9 = 0;
    uVar1 = (**(code **)(lVar2 + 0x38))
                      (lVar2,*(undefined4 *)(param_2 + 0x310),*(undefined4 *)(param_2 + 0x318),
                       0x20801117,&local_a9,1);
    os_unref_dynamic_power(param_2,2);
    rmapiLockRelease();
    threadStateFree(local_a8,0);
    return uVar1;
  }
  return 0x40;
}


// ===== 0026aa10 rm_is_chipset_io_coherent =====

undefined1 rm_is_chipset_io_coherent(void)

{
  if (*(long *)(g_pSys + 0x208) != 0) {
    return *(undefined1 *)(*(long *)(g_pSys + 0x208) + 0x68);
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0xb04,"rm_is_chipset_io_coherent",4,
               "NVRM: %s: no CL object found, setting io coherent by default\n");
  return 0;
}


// ===== 0026aa60 rm_validate_ioctls =====

undefined8 rm_validate_ioctls(char param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = RmValidateIoctl();
  if ((((int)uVar1 == 0x24) && (((param_1 == -0x32 || (param_1 == -0x31)) || (param_1 == 'R')))) &&
     (uVar1 = 0, param_2 != 0x10)) {
    nv_printf(4,"NVRM: invalid %d structure size, expected %d, got %d!\n",param_1,0x10,param_2);
    uVar1 = 0x1f;
  }
  return uVar1;
}


// ===== 0026aac0 rm_ioctl =====

undefined4
rm_ioctl(undefined8 param_1,undefined8 param_2,long param_3,int param_4,int *param_5,int param_6)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  long lVar8;
  undefined8 uVar9;
  undefined4 *local_c0;
  undefined1 local_b8 [4];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined2 local_a8;
  
  if (param_4 == 0xce) {
    if (param_6 != 0x10) {
      return 0x1f;
    }
    iVar5 = param_5[2];
    iVar6 = *param_5;
    lVar8 = nv_get_ctl_state();
    piVar7 = (int *)portMemAllocNonPaged(0x38);
    if (piVar7 == (int *)0x0) {
      uVar9 = 0x51;
LAB_0026ac78:
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x286,"allocate_os_event",4,
                   "NVRM: failed to allocate OS event: 0x%08x\n",uVar9);
      portMemFree(piVar7);
      iVar5 = 0x1a;
    }
    else {
      *(long *)(piVar7 + 6) = param_3;
      *(undefined1 *)(piVar7 + 9) = 1;
      *piVar7 = iVar6;
      piVar7[8] = iVar5;
      piVar7[10] = 0;
      portSyncSpinlockAcquire(*(undefined8 *)(lVar8 + 0x2d0));
      for (piVar1 = *(int **)(lVar8 + 0x2c8); piVar1 != (int *)0x0; piVar1 = *(int **)(piVar1 + 0xc)
          ) {
        if ((iVar6 == *piVar1) && (iVar5 == piVar1[8])) {
          portSyncSpinlockRelease(*(undefined8 *)(lVar8 + 0x2d0));
          uVar9 = 0x1f;
          goto LAB_0026ac78;
        }
      }
      *(int **)(piVar7 + 0xc) = *(int **)(lVar8 + 0x2c8);
      *(int **)(lVar8 + 0x2c8) = piVar7;
      *(undefined1 *)(param_3 + 0x6c) = 1;
      portSyncSpinlockRelease(*(undefined8 *)(lVar8 + 0x2d0));
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x280,"allocate_os_event",1,
                   "NVRM: allocated OS event:\n");
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x281,"allocate_os_event",1,
                   "NVRM:    hParent: 0x%x\n",iVar6);
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x282,"allocate_os_event",1,"NVRM:    fd: %d\n",
                   iVar5);
      iVar5 = 0;
    }
  }
  else {
    if (param_4 != 0xcf) {
      if (param_4 != 0x52) {
        threadStateInit(local_b8,0);
        uVar4 = RmIoctl(param_2,param_3,param_4,param_5,param_6);
        threadStateFree(local_b8,0);
        return uVar4;
      }
      if (param_6 == 0x10) {
        uVar9 = *(undefined8 *)param_5;
        iVar5 = os_alloc_mem(&local_c0,0x10);
        if (iVar5 == 0) {
          iVar6 = nv_get_event(param_3,local_b8,param_5 + 2);
          iVar5 = 0x59;
          if (iVar6 == 0) {
            os_mem_set(local_c0,0,0x10);
            *local_c0 = local_b4;
            local_c0[1] = local_b0;
            local_c0[2] = local_ac;
            *(undefined2 *)(local_c0 + 3) = local_a8;
            iVar5 = os_memcpy_to_user(uVar9,local_c0,0x10);
          }
          os_free_mem(local_c0);
        }
        param_5[3] = iVar5;
        return 0;
      }
      return 0x1f;
    }
    if (param_6 != 0x10) {
      return 0x1f;
    }
    iVar5 = param_5[2];
    iVar6 = *param_5;
    lVar8 = nv_get_ctl_state();
    portSyncSpinlockAcquire(*(undefined8 *)(lVar8 + 0x2d0));
    piVar7 = *(int **)(lVar8 + 0x2c8);
    piVar3 = piVar7;
    piVar1 = piVar7;
    while (piVar2 = piVar3, piVar2 != (int *)0x0) {
      if ((iVar5 == piVar2[8]) && (iVar6 == *piVar2)) {
        if (piVar7 == piVar2) {
          *(undefined8 *)(lVar8 + 0x2c8) = *(undefined8 *)(piVar2 + 0xc);
        }
        else {
          *(undefined8 *)(piVar1 + 0xc) = *(undefined8 *)(piVar2 + 0xc);
        }
        *(undefined1 *)(piVar2 + 9) = 0;
        if (piVar2[10] == 0) {
          portMemFree();
          portSyncSpinlockRelease(*(undefined8 *)(lVar8 + 0x2d0));
        }
        else {
          portSyncSpinlockRelease(*(undefined8 *)(lVar8 + 0x2d0));
        }
        nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2b2,"free_os_event",1,
                     "NVRM: freed OS event:\n");
        nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2b3,"free_os_event",1,
                     "NVRM:    hParent: 0x%x\n",iVar6);
        nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2b4,"free_os_event",1,"NVRM:    fd: %d\n",
                     iVar5);
        iVar5 = 0;
        goto LAB_0026aeff;
      }
      piVar1 = piVar2;
      piVar3 = *(int **)(piVar2 + 0xc);
    }
    portSyncSpinlockRelease(*(undefined8 *)(lVar8 + 0x2d0));
    nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2b8,"free_os_event",4,
                 "NVRM: failed to find OS event:\n");
    nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2b9,"free_os_event",4,"NVRM:    hParent: 0x%x\n",
                 iVar6);
    nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2ba,"free_os_event",4,"NVRM:    fd: %d\n",iVar5);
    iVar5 = 0x28;
  }
LAB_0026aeff:
  param_5[3] = iVar5;
  return 0;
}


// ===== 0026b0c0 rm_cleanup_file_private =====

long rm_cleanup_file_private(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined4 local_cc;
  undefined1 local_c8 [152];
  
  lVar1 = g_pSys;
  local_cc = 0;
  if ((*(char *)((long)param_3 + 0x6c) != '\0') || (*param_3 != 0)) {
    uVar3 = rmapiGetInterface(0);
    threadStateInit(local_c8,0);
    threadStateSetTimeoutOverride(local_c8,10000);
    lVar4 = rmapiPrologue(uVar3,&local_cc);
    if ((int)lVar4 != 0) {
      return lVar4;
    }
    iVar2 = rmapiLockAcquire(4,0x1000);
    if (iVar2 == 0) {
      lVar4 = *param_3;
      if (lVar4 != 0) {
        if ((short)param_3[1] != 0) {
          lVar5 = 0;
          do {
            if (*(int *)(lVar4 + lVar5 * 4) != 0) {
              RmFreeObjExportHandle();
              *(undefined4 *)(*param_3 + lVar5 * 4) = 0;
              lVar4 = *param_3;
            }
            lVar5 = lVar5 + 1;
          } while ((uint)lVar5 < (uint)*(ushort *)(param_3 + 1));
        }
        os_free_mem(lVar4);
        *param_3 = 0;
        *(undefined2 *)(param_3 + 1) = 0;
      }
      RmFreeUnusedClients(param_2,param_3);
      if (*(char *)(lVar1 + 0x180) == '\0') {
        serverFreeDisabledClients(g_resServ,1,0);
      }
      rmapiLockRelease();
    }
    if (*(char *)(lVar1 + 0x180) != '\0') {
      _deferredClientListFreeCallback(0);
    }
    rmapiEpilogue(uVar3,&local_cc);
    threadStateFree(local_c8,0);
  }
  if (param_3[0xb] != 0) {
    nv_put_file_private(param_3[0xc]);
    LOCK();
    lVar1 = param_3[0xb];
    param_3[0xb] = 0;
    UNLOCK();
    param_3[0xc] = 0;
    return lVar1;
  }
  return 0;
}


// ===== 0026b290 rm_unbind_lock =====

void rm_unbind_lock(undefined8 param_1,long *param_2)

{
  int iVar1;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  iVar1 = rmapiLockAcquire(0,0x1000);
  if (iVar1 == 0) {
    if ((((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) || (*(long *)*param_2 == 0)
        ) || (iVar1 = gpuGetUserClientCount_IMPL(), iVar1 == 0)) {
      *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x4000;
    }
    rmapiLockRelease();
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 0026b310 rm_read_registry_dword =====

ulong rm_read_registry_dword(undefined8 param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_2 != (long *)0x0) {
    uVar2 = rmapiLockAcquire(2,0x1000);
    if ((int)uVar2 == 0) {
      if ((undefined8 *)*param_2 == (undefined8 *)0x0) {
        uVar1 = osReadRegistryDword(0,param_3,param_4);
      }
      else {
        uVar1 = osReadRegistryDword(*(undefined8 *)*param_2,param_3,param_4);
      }
      rmapiLockRelease();
      uVar2 = (ulong)uVar1;
    }
    return uVar2;
  }
  uVar2 = osReadRegistryDword(0,param_3,param_4);
  return uVar2;
}


// ===== 0026b390 rm_write_registry_dword =====

ulong rm_write_registry_dword(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_2 != 0) {
    uVar2 = rmapiLockAcquire(0,0x1000);
    if ((int)uVar2 == 0) {
      uVar1 = RmWriteRegistryDword(param_2,param_3,param_4);
      rmapiLockRelease();
      uVar2 = (ulong)uVar1;
    }
    return uVar2;
  }
  uVar2 = RmWriteRegistryDword(0,param_3,param_4);
  return uVar2;
}


// ===== 0026b400 rm_write_registry_binary =====

ulong rm_write_registry_binary
                (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,
                undefined4 param_5)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_2 != 0) {
    uVar2 = rmapiLockAcquire(0,0x1000);
    if ((int)uVar2 == 0) {
      uVar1 = RmWriteRegistryBinary(param_2,param_3,param_4,param_5);
      rmapiLockRelease();
      uVar2 = (ulong)uVar1;
    }
    return uVar2;
  }
  uVar2 = RmWriteRegistryBinary(0,param_3,param_4,param_5);
  return uVar2;
}


// ===== 0026b480 rm_write_registry_string =====

ulong rm_write_registry_string
                (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,int param_5)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_2 != 0) {
    uVar2 = rmapiLockAcquire(0,0x1000);
    if ((int)uVar2 == 0) {
      uVar1 = RmWriteRegistryString(param_2,param_3,param_4,param_5 + 1);
      rmapiLockRelease();
      uVar2 = (ulong)uVar1;
    }
    return uVar2;
  }
  uVar2 = RmWriteRegistryString(0,param_3,param_4,param_5 + 1);
  return uVar2;
}


// ===== 0026b500 rm_remove_spaces =====

char * rm_remove_spaces(char *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *local_20 [2];
  
  iVar3 = os_string_length();
  iVar3 = os_alloc_mem(local_20,iVar3 + 1);
  if (iVar3 != 0) {
    return (char *)0x0;
  }
  cVar2 = *param_1;
  pcVar4 = local_20[0];
  while (cVar2 != '\0') {
    if ((4 < (byte)(cVar2 - 9U)) && (cVar2 != ' ')) {
      *pcVar4 = cVar2;
      pcVar4 = pcVar4 + 1;
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar4 = '\0';
  return local_20[0];
}


// ===== 0026b580 rm_string_token =====

char * rm_string_token(undefined8 *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_1 == (undefined8 *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = (char *)*param_1;
    if (pcVar4 != (char *)0x0) {
      *param_1 = 0;
      cVar1 = *pcVar4;
      pcVar2 = pcVar4;
      while (cVar1 != '\0') {
        pcVar3 = pcVar2 + 1;
        if (param_2 == cVar1) {
          *pcVar2 = '\0';
          *param_1 = pcVar3;
          return pcVar4;
        }
        pcVar2 = pcVar3;
        cVar1 = *pcVar3;
      }
    }
  }
  return pcVar4;
}


// ===== 0026b600 rm_parse_option_string =====

void rm_parse_option_string(undefined8 param_1,long param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  ulong uVar6;
  char cVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  
  if (param_2 == 0) {
    return;
  }
  pcVar5 = (char *)rm_remove_spaces(param_2);
  if (pcVar5 == (char *)0x0) {
    return;
  }
  cVar2 = *pcVar5;
  pcVar1 = pcVar5;
joined_r0x0026b646:
  pcVar11 = pcVar1;
  cVar7 = cVar2;
  if (cVar2 != '\0') {
    do {
      pcVar9 = pcVar11 + 1;
      pcVar10 = pcVar1;
      if (cVar7 == ';') {
        *pcVar11 = '\0';
        cVar2 = *pcVar1;
        if (cVar2 != '\0') goto LAB_0026b6ad;
        os_string_length(pcVar1);
        goto LAB_0026b745;
      }
      pcVar11 = pcVar9;
      cVar7 = *pcVar9;
    } while (*pcVar9 != '\0');
    pcVar9 = (char *)0x0;
LAB_0026b6ad:
    do {
      pcVar11 = pcVar10 + 1;
      if (cVar2 == '=') {
        *pcVar10 = '\0';
        iVar3 = os_string_length(pcVar1);
        if (iVar3 == 0) goto LAB_0026b740;
        cVar2 = pcVar10[1];
        pcVar10 = pcVar11;
        goto joined_r0x0026b6d2;
      }
      cVar2 = *pcVar11;
      pcVar10 = pcVar11;
    } while (cVar2 != '\0');
    os_string_length(pcVar1);
    goto LAB_0026b740;
  }
  os_string_length(pcVar1);
LAB_0026b75c:
  os_free_mem(pcVar5);
  return;
joined_r0x0026b6d2:
  if (cVar2 == '\0') goto LAB_0026b7a0;
  pcVar8 = pcVar10 + 1;
  if (cVar2 == '=') {
    *pcVar10 = '\0';
    iVar3 = os_string_length(pcVar11);
    if (iVar3 == 0) goto LAB_0026b740;
    cVar2 = pcVar10[1];
    goto joined_r0x0026b715;
  }
  cVar2 = *pcVar8;
  pcVar10 = pcVar8;
  goto joined_r0x0026b6d2;
joined_r0x0026b715:
  if (cVar2 == '\0') goto LAB_0026b740;
  if (cVar2 == '=') {
    *pcVar8 = '\0';
    goto LAB_0026b740;
  }
  cVar2 = pcVar8[1];
  pcVar8 = pcVar8 + 1;
  goto joined_r0x0026b715;
LAB_0026b7a0:
  iVar3 = os_string_length(pcVar11);
  if (iVar3 != 0) {
    uVar4 = os_strtoul(pcVar11,0,0);
    if (nv_parms != (undefined *)0x0) {
      uVar6 = 0;
      do {
        iVar3 = os_string_compare();
        if (iVar3 == 0) {
          if ((&nv_parms)[uVar6 * 2] != (undefined *)0x0) {
            *(undefined4 *)(&PTR_NVreg_ResmanDebugLevel_005702e8)[uVar6 * 2] = uVar4;
            goto LAB_0026b740;
          }
          break;
        }
        uVar6 = (ulong)((int)uVar6 + 1);
      } while ((&nv_parms)[uVar6 * 2] != (undefined *)0x0);
    }
    RmWriteRegistryDword(0,pcVar1,uVar4);
  }
LAB_0026b740:
  if (pcVar9 == (char *)0x0) goto LAB_0026b75c;
LAB_0026b745:
  cVar2 = *pcVar9;
  pcVar1 = pcVar9;
  goto joined_r0x0026b646;
}


// ===== 0026b840 rm_run_rc_callback =====

undefined8 rm_run_rc_callback(undefined8 param_1,long *param_2)

{
  long lVar1;
  char cVar2;
  
  if ((((param_2 != (long *)0x0) && ((long *)*param_2 != (long *)0x0)) &&
      (lVar1 = *(long *)*param_2, lVar1 != 0)) && (*(int *)((long)param_2 + 0x2c4) != 0)) {
    cVar2 = gpuIsGpuFullPower_IMPL();
    if ((((cVar2 != '\0') && (*(char *)(lVar1 + 0x44c) != '\0')) &&
        ((*(char *)(lVar1 + 0x44f) == '\0' &&
         ((*(char *)(lVar1 + 0x450) == '\0' && (*(char *)(lVar1 + 0x451) == '\0')))))) &&
       (*(char *)(lVar1 + 0x455) == '\0')) {
      cVar2 = gpuCheckSysmemAccess_IMPL();
      if (cVar2 != '\0') {
        osRun1HzCallbacksNow(lVar1);
        return 0;
      }
    }
    return 0xffff;
  }
  return 0xffff;
}


// ===== 0026b8e0 rm_run_nano_timer_callback =====

int rm_run_nano_timer_callback(undefined8 param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined1 local_a8 [144];
  
  if ((param_2 == (long *)0x0) || ((long *)*param_2 == (long *)0x0)) {
    return 0xffff;
  }
  lVar1 = *(long *)*param_2;
  if ((((lVar1 != 0) && (cVar2 = gpuIsGpuFullPowerForPmResume_IMPL(lVar1), cVar2 != '\0')) &&
      (*(char *)(lVar1 + 0x44c) != '\0')) &&
     (((*(char *)(lVar1 + 0x44f) == '\0' && (*(char *)(lVar1 + 0x450) == '\0')) &&
      ((*(char *)(lVar1 + 0x451) == '\0' && (*(char *)(lVar1 + 0x455) == '\0')))))) {
    threadStateInitISRAndDeferredIntHandler(local_a8,lVar1,4);
    iVar3 = osQueueWorkItem(lVar1,_tmrEventServiceTimerWorkItem,param_3,0x81);
    if (iVar3 != 0) {
      nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0xd6d,"RmRunNanoTimerCallback",4,
                   "NVRM: Queuing workitem for timer event failed with status :0x%x\n");
    }
    threadStateFreeISRAndDeferredIntHandler(local_a8,lVar1,4);
    return iVar3;
  }
  return 0xffff;
}


// ===== 0026ba20 rm_execute_work_item =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rm_execute_work_item(undefined8 param_1,byte *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  local_b0 = 0;
  local_ac = 0;
  if (((*param_2 & 4) == 0) && ((0x3f < *param_2 || ((param_2[1] & 3) != 0)))) {
    nvAssertFailedNoLog(&DAT_00ccdb19,"arch/nvalloc/unix/src/osapi.c",0x2cf);
  }
  else {
    iVar3 = workItemLocksAcquire
                      (*(undefined4 *)(param_2 + 4),*(undefined4 *)param_2,&local_ac,&local_b0);
    if (iVar3 == 0) {
      if ((*param_2 & 4) == 0) {
        if (((param_2[1] & 4) == 0) || (cVar2 = os_is_queue_flush_ongoing(0), cVar2 == '\0')) {
          (**(code **)(param_2 + 8))(*(undefined8 *)(param_2 + 0x10));
        }
      }
      else {
        lVar5 = gpumgrGetGpu(*(undefined4 *)(param_2 + 4));
        if (lVar5 == 0) {
          nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x2f0,"RmExecuteWorkItem",4,
                       "NVRM: Invalid GPU instance for workitem\n");
        }
        else {
          lVar1 = *(long *)(lVar5 + 0x4e0);
          if (lVar1 == 0) {
            nvAssertFailedNoLog("nv != NULL","arch/nvalloc/unix/src/osapi.c",0x2e3);
          }
          else {
            uVar4 = gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar5 + 0x7a4));
            if (((param_2[1] & 4) == 0) ||
               (cVar2 = os_is_queue_flush_ongoing(*(undefined8 *)(lVar1 + 0x2f0)), cVar2 == '\0')) {
              (**(code **)(param_2 + 8))
                        (*(undefined4 *)(param_2 + 4),*(undefined8 *)(param_2 + 0x10));
            }
            gpumgrSetCurrentGpuInstance(uVar4);
          }
        }
      }
    }
  }
  workItemLocksRelease(local_ac,local_b0);
  if ((*(long *)(param_2 + 0x10) != 0) && ((*param_2 & 1) == 0)) {
    portMemFree();
  }
  portMemFree(param_2);
  threadStateFree(local_a8,0);
  return;
}


// ===== 0026bc00 rm_get_device_name =====

char * rm_get_device_name(short param_1,short param_2,short param_3)

{
  short *psVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  
  psVar1 = &sChipsReleased;
  pcVar5 = (char *)0x0;
  uVar4 = 0;
  do {
    if (*psVar1 == param_1) {
      if ((psVar1[2] == 0) && (psVar1[1] == 0)) {
        pcVar5 = *(char **)(psVar1 + 4);
      }
      else if ((psVar1[2] == param_2) && (psVar1[1] == param_3)) {
        pcVar5 = (&PTR_s_NVIDIA_TITAN_RTX_00cd5a68)[uVar4 * 2];
        goto LAB_0026bc5b;
      }
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    psVar1 = psVar1 + 8;
    if (uVar3 == 0x786) {
LAB_0026bc5b:
      pcVar2 = "Unknown";
      if (pcVar5 != (char *)0x0) {
        pcVar2 = pcVar5;
      }
      return pcVar2;
    }
  } while( true );
}


// ===== 0026bc80 rm_access_registry =====

/* WARNING: Type propagation algorithm not settling */

uint rm_access_registry(int param_1,int param_2,int param_3,undefined8 param_4,int param_5,
                       undefined8 param_6,uint param_7,undefined8 param_8,int *param_9,
                       undefined4 *param_10)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  int local_10c;
  int local_ec [3];
  long local_e0;
  long local_d8;
  long local_d0;
  long local_c8;
  long local_c0;
  long local_b8;
  undefined8 local_b0;
  long *local_a8;
  uint local_a0;
  uint local_9c;
  undefined1 local_98;
  char *local_90;
  undefined8 local_88;
  long *local_80;
  int local_78;
  uint local_74;
  undefined1 local_70;
  char *local_68;
  undefined8 local_60;
  long *local_58;
  int local_50;
  uint local_4c;
  undefined1 local_48;
  char *local_40;
  
  uVar3 = rmapiLockAcquire((param_3 == 1 || param_3 == 6) * '\x02',0x1000);
  if (uVar3 != 0) {
    return uVar3;
  }
  local_ec[0] = 0;
  uVar3 = 0x23;
  local_ec[1] = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_ec[2] = 0;
  iVar4 = serverAcquireClient(g_resServ,param_1,1,&local_e0);
  if (iVar4 != 0) goto LAB_0026be9a;
  local_10c = 0;
  if (param_1 == param_2) {
    bVar1 = false;
    uVar7 = 0;
    uVar3 = 0x59;
LAB_0026bd72:
    if (param_9 != (int *)0x0) {
      local_ec[2] = *param_9;
    }
    if (param_5 == 0) {
LAB_0026bf30:
      if (param_7 != 0) {
        if (0xff < param_7) goto LAB_0026bd9d;
        local_80 = &local_c0;
        local_68 = "RmAccessRegistry";
        local_78 = param_7 + 1;
        local_74 = 0;
        local_70 = 1;
        local_88 = param_6;
        iVar4 = rmapiParamsAcquire(&local_88,1);
        if (iVar4 != 0) goto LAB_0026c105;
        uVar3 = 0;
        if (*(char *)(local_c0 + (ulong)param_7) != '\0') {
          local_10c = 0;
          uVar3 = 0x1f;
          goto LAB_0026bda3;
        }
      }
      if (1 < param_3 - 6U) {
        if (param_3 == 1) {
          uVar3 = osReadRegistryDword(uVar7,local_c0,param_10);
        }
        else if (param_3 == 2) {
          if ((bVar1) && (cVar2 = osIsAdministrator(), cVar2 != '\0')) {
            do {
              lVar6 = gpumgrGetNextGpu(local_ec[0],local_ec + 1);
              if (lVar6 == 0) break;
              uVar3 = osWriteRegistryDword(lVar6,local_c0,*param_10);
            } while (uVar3 == 0);
          }
          else {
            uVar3 = osWriteRegistryDword(uVar7,local_c0,*param_10);
          }
        }
        else {
          uVar3 = 0x1d;
        }
        goto LAB_0026bda3;
      }
      if (0xff < local_ec[2] - 1U) goto LAB_0026bd9d;
      local_58 = &local_b8;
      local_40 = "RmAccessRegistry";
      local_4c = 0;
      local_60 = param_8;
      local_50 = local_ec[2];
      local_48 = 1;
      if (param_3 == 6) {
        local_4c = 2;
        iVar4 = rmapiParamsAcquire(&local_60,1);
        if (iVar4 != 0) goto LAB_0026c105;
        uVar3 = osReadRegistryBinary(uVar7,local_c0,local_b8,local_ec + 2);
        local_10c = 0;
        if (uVar3 == 0) {
          local_10c = local_ec[2];
        }
      }
      else {
        iVar4 = rmapiParamsAcquire(&local_60,1);
        if (iVar4 == 0) {
          if ((bVar1) && (cVar2 = osIsAdministrator(), cVar2 != '\0')) {
            do {
              lVar6 = gpumgrGetNextGpu(local_ec[0],local_ec + 1);
              if (lVar6 == 0) {
                local_10c = 0;
                uVar3 = 0;
                goto LAB_0026bda3;
              }
              uVar3 = osWriteRegistryBinary(lVar6,local_c0,local_b8,local_ec[2]);
            } while (uVar3 == 0);
            local_10c = 0;
          }
          else {
            uVar3 = osWriteRegistryBinary(uVar7,local_c0,local_b8,local_ec[2]);
            local_10c = 0;
          }
        }
        else {
LAB_0026c105:
          uVar3 = 0x59;
        }
      }
    }
    else {
      if (param_5 + 1U < 0x101) {
        local_a8 = &local_c8;
        local_90 = "RmAccessRegistry";
        local_98 = 1;
        local_9c = 8;
        local_b0 = param_4;
        local_a0 = param_5 + 1U;
        iVar4 = rmapiParamsAcquire(&local_b0,1);
        uVar3 = 0;
        if (iVar4 == 0) goto LAB_0026bf30;
        goto LAB_0026c105;
      }
LAB_0026bd9d:
      uVar3 = 0x41;
    }
LAB_0026bda3:
    if (local_ec[0] != 0) {
      rmGpuGroupLockRelease(local_ec[0],0);
    }
  }
  else {
    uVar7 = *(undefined8 *)(local_e0 + 8);
    iVar4 = deviceGetByHandle_IMPL(uVar7,param_2,&local_d8);
    if (iVar4 == 0) {
      uVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(local_d8 + 0x180),1,0,0x80000,local_ec);
      if (uVar3 == 0) {
        bVar1 = true;
        uVar7 = *(undefined8 *)(*(long *)(local_d8 + 0x128) + 0xe0);
        goto LAB_0026bd72;
      }
      local_ec[0] = 0;
    }
    else {
      uVar5 = subdeviceGetByHandle_IMPL(uVar7,param_2,&local_d0);
      uVar3 = uVar5;
      if (uVar5 != 0) goto LAB_0026bda3;
      uVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(local_d0 + 0x334),0,0,0x80000,local_ec);
      if (uVar3 == 0) {
        bVar1 = false;
        uVar7 = *(undefined8 *)(*(long *)(local_d0 + 0x158) + 0xe0);
        uVar3 = uVar5;
        goto LAB_0026bd72;
      }
      local_ec[0] = 0;
    }
  }
  if (local_c8 != 0) {
    local_9c = local_9c | 4;
    local_a0 = 0;
    iVar4 = rmapiParamsRelease(&local_b0);
    if ((iVar4 != 0) && (uVar3 == 0)) {
      uVar3 = 0x59;
    }
  }
  if (local_c0 == 0) {
LAB_0026be40:
    if (local_b8 != 0) {
      if ((uVar3 == 0) && (local_10c != 0)) {
        local_50 = local_10c;
        iVar4 = rmapiParamsRelease(&local_60);
        uVar3 = -(uint)(iVar4 != 0) & 0x59;
      }
      else {
        local_4c = local_4c | 4;
        local_50 = local_10c;
        iVar4 = rmapiParamsRelease(&local_60);
        if ((uVar3 == 0) && (iVar4 != 0)) {
          uVar3 = 0x59;
        }
      }
LAB_0026be76:
      *param_9 = local_10c;
    }
  }
  else {
    local_74 = local_74 | 4;
    local_78 = 0;
    iVar4 = rmapiParamsRelease(&local_88);
    if (iVar4 == 0) goto LAB_0026be40;
    if (uVar3 == 0) {
      uVar3 = 0x59;
    }
    if (local_b8 != 0) {
      local_4c = local_4c | 4;
      local_50 = local_10c;
      rmapiParamsRelease(&local_60);
      goto LAB_0026be76;
    }
  }
  serverReleaseClient(g_resServ,1,local_e0);
LAB_0026be9a:
  rmapiLockRelease();
  return uVar3;
}


// ===== 0026c350 rm_update_device_mapping_info =====

ulong rm_update_device_mapping_info
                (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  int local_64;
  long local_60;
  long local_58;
  long local_50;
  long local_48;
  long local_40 [2];
  
  uVar4 = rmapiLockAcquire(2,0x80000);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  local_64 = 0;
  uVar2 = serverAcquireClient(g_resServ,param_1,1,&local_60);
  if (uVar2 != 0) {
    rmapiLockRelease();
    goto LAB_0026c3c5;
  }
  uVar1 = *(undefined8 *)(local_60 + 8);
  iVar3 = deviceGetByHandle_IMPL(uVar1,param_2,&local_48);
  if (iVar3 == 0) {
    uVar2 = rmGpuGroupLockAcquire(*(undefined4 *)(local_48 + 0x180),1,0,0x80000,&local_64);
joined_r0x0026c461:
    if ((uVar2 == 0) && (uVar2 = clientGetResourceRef_IMPL(uVar1,param_3,&local_58), uVar2 == 0)) {
      lVar5 = objDynamicCastById_IMPL(*(undefined8 *)(local_58 + 8),0x4789f2);
      if ((lVar5 == 0) &&
         ((lVar5 = objDynamicCastById_IMPL(*(undefined8 *)(local_58 + 8),0x3abed3), lVar5 == 0 &&
          (lVar5 = objDynamicCastById_IMPL(*(undefined8 *)(local_58 + 8),0x5d8d70), lVar5 == 0)))) {
        uVar2 = 0x33;
      }
      else {
        uVar2 = refFindCpuMappingWithFilter
                          (local_58,param_4,serverutilMappingFilterCurrentUserProc,&local_50);
        if (uVar2 == 0) {
          *(undefined8 *)(local_50 + 0x18) = param_5;
        }
      }
    }
  }
  else {
    uVar2 = subdeviceGetByHandle_IMPL(uVar1,param_2,local_40);
    if (uVar2 == 0) {
      uVar2 = rmGpuGroupLockAcquire(*(undefined4 *)(local_40[0] + 0x334),0,0,0x80000,&local_64);
      goto joined_r0x0026c461;
    }
  }
  if (local_64 != 0) {
    rmGpuGroupLockRelease(local_64,0);
  }
  serverReleaseClient(g_resServ,1,local_60);
  rmapiLockRelease();
LAB_0026c3c5:
  return (ulong)uVar2;
}


// ===== 0026c550 rm_is_supported_device =====

int rm_is_supported_device(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  uint *puVar7;
  ulong uVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  char *pcVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined2 uVar14;
  undefined1 local_cc [4];
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  uVar4 = *(undefined8 *)(g_pSys + 600);
  puVar7 = (uint *)osMapKernelSpace(**(undefined8 **)(param_2 + 0x108),os_page_size,1,1);
  if (puVar7 == (uint *)0x0) {
    iVar6 = 0x59;
    nv_printf(4,"NVRM: failed to map registers!\n");
    uVar8 = extraout_RDX_02;
  }
  else {
    uVar1 = puVar7[1];
    uVar2 = *puVar7;
    uVar3 = puVar7[0x280];
    osUnmapKernelSpace(puVar7,os_page_size);
    if ((uVar2 & uVar3) == 0xffffffff) {
      iVar6 = 0xf;
      nv_printf(4,
                "NVRM: The NVIDIA GPU %04x:%02x:%02x.%x\nNVRM: (PCI ID: %04x:%04x) installed in this system has\nNVRM: fallen off the bus and is not responding to commands.\n"
                ,*(undefined4 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 0x18),
                *(undefined1 *)(param_2 + 0x19),*(undefined1 *)(param_2 + 0x1a),
                *(undefined2 *)(param_2 + 0x1c),*(undefined2 *)(param_2 + 0x1e));
      uVar8 = extraout_RDX_01;
    }
    else {
      iVar6 = halmgrGetHalForGpu_IMPL(uVar4,uVar2,uVar3,local_cc);
      if (iVar6 == 0) {
        iVar6 = rm_is_vgpu_supported_device(param_2,uVar1,uVar3);
        uVar8 = extraout_RDX;
        if (iVar6 == 0) goto LAB_0026c628;
        uVar8 = (ulong)*(ushort *)(param_2 + 0x1e);
        uVar9 = *(undefined1 *)(param_2 + 0x18);
        pcVar11 = 
        "NVRM: The NVIDIA vGPU %04x:%02x:%02x.%x (PCI ID: %04x:%04x)\nNVRM: installed in this system is not supported by open\nNVRM: nvidia.ko.\nNVRM: Please see the \'Open Linux Kernel Modules\' and \'GSP\nNVRM: Firmware\' sections in the NVIDIA Virtual GPU (vGPU)\nNVRM: Software documentation, available at docs.nvidia.com.\n"
        ;
        uVar10 = *(undefined4 *)(param_2 + 0x14);
        uVar14 = *(undefined2 *)(param_2 + 0x1c);
        uVar13 = *(undefined1 *)(param_2 + 0x1a);
        uVar12 = *(undefined1 *)(param_2 + 0x19);
      }
      else {
        cVar5 = gpumgrIsDeviceRmFirmwareCapable
                          (uVar3,(uVar1 & 0x30000) == 0x20000,*(uint *)(param_2 + 0x10) & 0x10,0,0);
        if (cVar5 != '\0') {
          nv_printf(4,
                    "NVRM: The NVIDIA GPU %04x:%02x:%02x.%x (PCI ID: %04x:%04x)\nNVRM: installed in this system is not supported by the\nNVRM: NVIDIA %s driver release.\nNVRM: Please see \'Appendix A - Supported NVIDIA GPU Products\'\nNVRM: in this release\'s README, available on the operating system\nNVRM: specific graphics driver download page at www.nvidia.com.\n"
                    ,*(undefined4 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 0x18),
                    *(undefined1 *)(param_2 + 0x19),*(undefined1 *)(param_2 + 0x1a),
                    *(undefined2 *)(param_2 + 0x1c),*(undefined2 *)(param_2 + 0x1e),&DAT_00cce42e);
          uVar8 = extraout_RDX_00;
          goto LAB_0026c628;
        }
        cVar5 = hypervisorIsVgxHyper_IMPL();
        uVar8 = (ulong)*(ushort *)(param_2 + 0x1e);
        uVar14 = *(undefined2 *)(param_2 + 0x1c);
        uVar13 = *(undefined1 *)(param_2 + 0x1a);
        uVar12 = *(undefined1 *)(param_2 + 0x19);
        uVar9 = *(undefined1 *)(param_2 + 0x18);
        uVar10 = *(undefined4 *)(param_2 + 0x14);
        if (cVar5 == '\0') {
          pcVar11 = 
          "NVRM: The NVIDIA GPU %04x:%02x:%02x.%x (PCI ID: %04x:%04x)\nNVRM: installed in this system is not supported by open\nNVRM: nvidia.ko because it does not include the required GPU\nNVRM: System Processor (GSP).\nNVRM: Please see the \'Open Linux Kernel Modules\' and \'GSP\nNVRM: Firmware\' sections in the driver README, available on\nNVRM: the Linux graphics driver download page at\nNVRM: www.nvidia.com.\n"
          ;
        }
        else {
          pcVar11 = 
          "NVRM: The NVIDIA GPU %04x:%02x:%02x.%x (PCI ID: %04x:%04x)\nNVRM: installed in this vGPU host system is not supported by\nNVRM: open nvidia.ko.\nNVRM: Please see the \'Open Linux Kernel Modules\' and \'GSP\nNVRM: Firmware\' sections in the NVIDIA Virtual GPU (vGPU)\nNVRM: Software documentation, available at docs.nvidia.com.\n"
          ;
        }
      }
      nv_printf(4,pcVar11,uVar10,uVar9,uVar12,uVar13,uVar14);
    }
  }
LAB_0026c628:
  threadStateFree(local_c8,0,uVar8);
  return iVar6;
}


// ===== 0026c7c0 rm_is_supported_pci_device =====

uint rm_is_supported_pci_device(char param_1,uint param_2,undefined4 param_3,ushort param_4)

{
  uint uVar1;
  undefined3 uVar2;
  
  uVar1 = 0;
  if (param_1 == '\x03') {
    uVar2 = (undefined3)((uint)param_3 >> 8);
    uVar1 = ((uint)((short)param_3 != 0x10de) | CONCAT31(uVar2,param_4 < 0x20) |
            CONCAT31(uVar2,(param_2 & 0xfd) != 0)) ^ 1;
  }
  return uVar1;
}


// ===== 0026c800 rm_i2c_transfer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int rm_i2c_transfer(undefined8 param_1,long *param_2,long param_3,uint param_4,byte param_5,
                   undefined1 param_6,uint param_7,byte *param_8)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  code *pcVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  ulong uVar9;
  undefined1 *puVar10;
  long lVar11;
  undefined4 *puVar12;
  long *plVar13;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long lVar14;
  undefined1 auVar15 [16];
  long lStack_100;
  undefined1 local_f0;
  undefined1 local_c8 [152];
  
  if (param_2 == (long *)0x0) {
    threadStateInit(local_c8,0);
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar4 = *param_2;
  threadStateInit(local_c8,0);
  if ((*(byte *)(lVar4 + 0x48) & 0x80) == 0) {
    if (((long *)*param_2 == (long *)0x0) || (bVar6 = false, *(long *)*param_2 == 0)) {
      iVar8 = 0xffff;
      goto LAB_0026c8a4;
    }
LAB_0026c86c:
    plVar13 = (long *)(lVar4 + 0x50);
    uVar9 = 0;
    do {
      if (*plVar13 == param_3) {
        iVar8 = 0;
        lStack_100 = uVar9 * 0x18;
        lVar1 = lVar4 + 8 + lStack_100;
        lVar14 = lVar4 + lStack_100;
        goto LAB_0026c950;
      }
      uVar7 = (int)uVar9 + 1;
      uVar9 = (ulong)uVar7;
      plVar13 = plVar13 + 3;
    } while (uVar7 != 0x10);
    iVar8 = 0xffff;
    goto LAB_0026c89b;
  }
  iVar8 = rmapiLockAcquire(0,0x100000);
  if (iVar8 != 0) goto LAB_0026c8a4;
  iVar8 = rmGpuLocksAcquire(0,0x100000);
  if (iVar8 == 0) {
    if (((long *)*param_2 != (long *)0x0) && (bVar6 = true, *(long *)*param_2 != 0))
    goto LAB_0026c86c;
    iVar8 = 0xffff;
    goto LAB_0026c910;
  }
  goto LAB_0026c919;
LAB_0026c950:
  do {
    iVar2 = *(int *)(lVar14 + 0x5c);
    if (iVar2 != -1) {
      if (iVar2 == 0) {
        uVar3 = *(undefined4 *)(lVar4 + 0x58 + uVar9 * 0x18);
        lVar11 = rmapiGetInterface(4,lVar4,lStack_100);
        auVar15 = portMemAllocNonPaged(0x60);
        lStack_100 = auVar15._8_8_;
        puVar10 = auVar15._0_8_;
        if (puVar10 == (undefined1 *)0x0) {
LAB_0026cc00:
          iVar8 = 0x51;
          goto LAB_0026c970;
        }
        portMemSet(puVar10,0,0x60);
        local_f0 = (undefined1)uVar3;
        *puVar10 = local_f0;
        *(ushort *)(puVar10 + 8) = (ushort)param_5 * 2;
        if (param_4 == 6) {
LAB_0026cc49:
          *(undefined4 *)(puVar10 + 0xc) = 0;
          goto LAB_0026cbb0;
        }
        if (param_4 < 7) {
          if (param_4 == 3) {
            if (param_7 != 2) goto LAB_0026cd62;
LAB_0026ce10:
            *(undefined4 *)(puVar10 + 0xc) = 5;
            *(undefined2 *)(puVar10 + 0x12) = *(undefined2 *)param_8;
            puVar10[0x11] = param_6;
          }
          else {
            if (param_4 < 4) {
              if (param_4 != 1) {
                if (param_4 != 2) goto LAB_0026cd19;
                puVar10[0x10] = 1;
              }
              *(undefined4 *)(puVar10 + 0xc) = 2;
              *(uint *)(puVar10 + 0x14) = param_7;
              *(byte **)(puVar10 + 0x18) = param_8;
              goto LAB_0026cbb0;
            }
            if (param_4 != 4) {
              puVar10[0x10] = 1;
              goto LAB_0026cc49;
            }
            puVar10[0x10] = 1;
            if (param_7 == 2) goto LAB_0026ce10;
LAB_0026cd62:
            *(undefined4 *)(puVar10 + 0xc) = 4;
            puVar10[0x12] = *param_8;
            puVar10[0x11] = param_6;
          }
          iVar8 = (**(code **)(lVar11 + 0x38))
                            (lVar11,(int)param_2[0x62],*(undefined4 *)((long)param_2 + 0x31c),
                             0x402c0105,puVar10,0x60);
          if ((iVar8 == 0) && (param_4 == 3)) {
            if (param_7 == 2) {
              *param_8 = (byte)*(undefined2 *)(puVar10 + 0x12);
              param_8[1] = puVar10[0x13];
              portMemFree(puVar10);
            }
            else {
              *param_8 = puVar10[0x12];
              portMemFree(puVar10);
            }
            iVar8 = 0;
            break;
          }
        }
        else {
          if (param_4 == 9) {
LAB_0026cc65:
            *(undefined4 *)(puVar10 + 0xc) = 3;
            puVar10[0x18] = param_6;
            *(uint *)(puVar10 + 0x1c) = param_7;
            *(byte **)(puVar10 + 0x20) = param_8;
          }
          else {
            if (9 < param_4) {
              if (param_4 != 10) {
LAB_0026cd19:
                iVar8 = 0x1f;
                portMemFree(puVar10);
                lStack_100 = extraout_RDX_02;
                goto LAB_0026c970;
              }
              puVar10[0x10] = 1;
              goto LAB_0026cc65;
            }
            if (param_4 == 7) {
              *(undefined4 *)(puVar10 + 0xc) = 6;
              puVar10[0x11] = param_6;
              *(uint *)(puVar10 + 0x14) = param_7;
              *(byte **)(puVar10 + 0x18) = param_8;
            }
            else {
              if (param_7 <= *param_8) goto LAB_0026cd19;
              puVar10[0x10] = 1;
              *(undefined4 *)(puVar10 + 0xc) = 6;
              puVar10[0x11] = param_6;
              *(uint *)(puVar10 + 0x14) = (uint)*param_8;
              *(byte **)(puVar10 + 0x18) = param_8 + 1;
            }
          }
LAB_0026cbb0:
          iVar8 = (**(code **)(lVar11 + 0x38))
                            (lVar11,(int)param_2[0x62],*(undefined4 *)((long)param_2 + 0x31c),
                             0x402c0105,puVar10,0x60);
        }
        portMemFree(puVar10);
        lStack_100 = extraout_RDX_00;
LAB_0026cbee:
        if (iVar8 == 0) break;
      }
      else {
        if (param_4 - 1 < 2) {
          lVar11 = rmapiGetInterface(4);
          if (param_7 < 0x101) {
            auVar15 = portMemAllocNonPaged(0x114);
            lStack_100 = auVar15._8_8_;
            puVar12 = auVar15._0_8_;
            if (puVar12 == (undefined4 *)0x0) goto LAB_0026cc00;
            portMemSet(puVar12,0,0x114);
            puVar12[2] = (uint)param_5;
            *puVar12 = 0;
            puVar12[1] = iVar2;
            puVar12[0x44] = param_7;
            *(bool *)(puVar12 + 3) = param_4 == 2;
            if (param_4 == 2) {
              portMemCopy((long)puVar12 + 0xd,0x100,param_8,param_7);
              iVar8 = (**(code **)(lVar11 + 0x38))
                                (lVar11,(int)param_2[0x62],(int)param_2[100],0x73137c,puVar12,0x114)
              ;
              portMemFree(puVar12);
              lStack_100 = extraout_RDX_01;
              goto LAB_0026cbee;
            }
            iVar8 = (**(code **)(lVar11 + 0x38))
                              (lVar11,(int)param_2[0x62],(int)param_2[100],0x73137c,puVar12,0x114);
            if (iVar8 != 0) {
              portMemFree(puVar12);
              lStack_100 = extraout_RDX;
              goto LAB_0026c970;
            }
            portMemCopy(param_8,param_7,(long)puVar12 + 0xd,puVar12[0x44]);
            portMemFree(puVar12);
            break;
          }
          lStack_100 = 0x100;
          nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0xefd,"RmDpAuxI2CTransfer",4,
                       "NVRM: %s: requested I2C transfer length %u is greater than maximum supported length %u\n"
                       ,"RmDpAuxI2CTransfer",param_7);
        }
        iVar8 = 0x56;
      }
    }
LAB_0026c970:
    lVar14 = lVar14 + 4;
  } while (lVar1 != lVar14);
LAB_0026c89b:
  if (!bVar6) goto LAB_0026c8a4;
LAB_0026c910:
  rmGpuLocksRelease(0,0);
LAB_0026c919:
  rmapiLockRelease();
LAB_0026c8a4:
  threadStateFree(local_c8,0);
  return iVar8;
}


// ===== 0026ce34 RmI2cAddGpuPorts.cold =====

void RmI2cAddGpuPorts_cold(void)

{
  code *pcVar1;
  long lVar2;
  undefined8 unaff_RBX;
  long unaff_RBP;
  undefined4 *puVar3;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  byte bVar4;
  
  bVar4 = 0;
  rmapiGetInterface(3);
  *(undefined8 *)(unaff_RBP + -0x28) = unaff_RBX;
  *(undefined8 *)(unaff_RBP + -0x20) = unaff_R12;
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
  puVar3 = (undefined4 *)(unaff_RBP + -0x8c);
  for (lVar2 = 3; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar4 * -2 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026ce80 RmI2cAddGpuPorts =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void RmI2cAddGpuPorts(long *param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  uint uVar11;
  byte bVar12;
  undefined8 local_94;
  undefined4 local_8c;
  long local_88;
  undefined8 local_80;
  long local_78;
  undefined8 local_70;
  int iStack_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  bVar12 = 0;
  if (param_1 == (long *)0x0) {
    rmapiGetInterface(3);
  }
  else {
    lVar6 = *param_1;
    lVar3 = rmapiGetInterface(3);
    if ((long *)*param_1 != (long *)0x0) {
      local_94 = 0;
      local_8c = 0;
      if ((*(char *)(*(long *)*param_1 + 0x908) == '\0') && ((*(byte *)(param_1 + 2) & 0x10) == 0))
      {
        puVar4 = (undefined4 *)(lVar6 + 0x5c);
        do {
          *puVar4 = 0xffffffff;
          puVar5 = puVar4 + 6;
          puVar4[1] = 0xffffffff;
          puVar4 = puVar5;
        } while ((undefined4 *)(lVar6 + 0x1dc) != puVar5);
        if (*(int *)((long)param_1 + 0x31c) != 0) {
          local_78 = 0;
          local_70 = 0;
          iVar2 = (**(code **)(lVar3 + 0x38))
                            (lVar3,(int)param_1[0x62],*(int *)((long)param_1 + 0x31c),0x402c0101,
                             &local_78,0x10);
          if (iVar2 == 0) {
            uVar8 = 0;
            do {
              while ((~*(byte *)((long)&local_78 + uVar8) & 0x11) == 0) {
                uVar9 = uVar8 & 0xffffffff;
                uVar8 = uVar8 + 1;
                rm_i2c_add_adapter(param_1,uVar9,0);
                if (uVar8 == 0x10) goto LAB_0026cfb4;
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 != 0x10);
          }
        }
LAB_0026cfb4:
        if ((int)param_1[100] != 0) {
          local_94 = local_94 & 0xffffffff00000000;
          iVar2 = (**(code **)(lVar3 + 0x38))
                            (lVar3,(int)param_1[0x62],(int)param_1[100],0x730107,&local_94,0xc);
          if (iVar2 == 0) {
            for (uVar7 = local_94._4_4_; uVar7 != 0; uVar7 = uVar7 & uVar7 - 1) {
              local_70 = 0;
              uVar11 = -uVar7 & uVar7;
              local_68 = 0;
              local_60 = 0;
              local_58 = 0;
              local_50 = 0;
              local_48 = 0;
              local_78 = (ulong)uVar11 << 0x20;
              iVar2 = (**(code **)(lVar3 + 0x38))
                                (lVar3,(int)param_1[0x62],(int)param_1[100],0x73028b,&local_78,0x38)
              ;
              if ((((iStack_6c == 2) && ((int)local_68 - 8U < 2)) &&
                  (iVar2 == 0 && local_60._4_4_ == 0)) && (local_48._1_1_ == '\0')) {
                local_80 = 0;
                local_88 = (ulong)uVar11 << 0x20;
                iVar2 = (**(code **)(lVar3 + 0x38))
                                  (lVar3,(int)param_1[0x62],(int)param_1[100],0x730211,&local_88,
                                   0x10);
                if ((iVar2 == 0) && (local_80._4_4_ != 0)) {
                  rm_i2c_add_adapter(param_1,local_80._4_4_ + -1,uVar11);
                }
              }
            }
          }
        }
      }
      return;
    }
  }
  puVar10 = &local_94;
  for (lVar6 = 3; lVar6 != 0; lVar6 = lVar6 + -1) {
    *(undefined4 *)puVar10 = 0;
    puVar10 = (undefined8 *)((long)puVar10 + (ulong)bVar12 * -8 + 4);
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026d140 rm_i2c_remove_adapters =====

void rm_i2c_remove_adapters(undefined8 param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = 0;
  if (param_2 != (long *)0x0) {
    lVar3 = *param_2;
  }
  plVar1 = (long *)(lVar3 + 0x50);
  do {
    while (*plVar1 != 0) {
      plVar2 = plVar1 + 3;
      nv_i2c_del_adapter(param_2);
      *plVar1 = 0;
      plVar1[1] = -0x100000000;
      *(undefined4 *)(plVar1 + 2) = 0xffffffff;
      plVar1 = plVar2;
      if (plVar2 == (long *)(lVar3 + 0x1d0)) {
        return;
      }
    }
    plVar1 = plVar1 + 3;
  } while (plVar1 != (long *)(lVar3 + 0x1d0));
  return;
}


// ===== 0026d1e0 rm_i2c_is_smbus_capable =====

uint rm_i2c_is_smbus_capable(undefined8 param_1,long *param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long *plVar7;
  undefined1 local_b8 [152];
  
  if (param_2 == (long *)0x0) {
    threadStateInit(local_b8,0);
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *param_2;
  threadStateInit(local_b8,0);
  if ((*(byte *)(lVar1 + 0x48) & 0x80) == 0) {
    if (((long *)*param_2 == (long *)0x0) || (*(long *)*param_2 == 0)) {
LAB_0026d2a0:
      uVar4 = 0;
      goto LAB_0026d257;
    }
    bVar3 = false;
LAB_0026d22c:
    plVar7 = (long *)(lVar1 + 0x50);
    uVar6 = 0;
    do {
      if (*plVar7 == param_3) {
        uVar4 = (uint)CONCAT71((int7)((ulong)param_3 >> 8),
                               *(int *)(lVar1 + 0x60 + uVar6 * 0x18) == 0) |
                (uint)CONCAT71((int7)(uVar6 * 3 >> 8),*(int *)(lVar1 + 0x5c + uVar6 * 0x18) == 0);
        if (bVar3) goto LAB_0026d2c6;
        goto LAB_0026d257;
      }
      uVar4 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar4;
      plVar7 = plVar7 + 3;
    } while (uVar4 != 0x10);
    uVar4 = 0;
    if (!bVar3) goto LAB_0026d257;
  }
  else {
    iVar5 = rmapiLockAcquire(0,0x100000);
    if (iVar5 != 0) goto LAB_0026d2a0;
    if (((long *)*param_2 != (long *)0x0) && (*(long *)*param_2 != 0)) {
      bVar3 = true;
      goto LAB_0026d22c;
    }
    uVar4 = 0;
  }
LAB_0026d2c6:
  rmapiLockRelease();
LAB_0026d257:
  threadStateFree(local_b8,0);
  return uVar4;
}


// ===== 0026d300 rm_perform_version_check =====

undefined8 rm_perform_version_check(undefined8 param_1,int *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 local_d8 [32];
  undefined1 local_b8 [152];
  
  uVar4 = 0x1f;
  threadStateInit(local_b8,0);
  if (param_3 == 0x48) {
    param_2[1] = 1;
    lVar3 = 0;
    if (*param_2 == 0x32) {
      os_string_copy(param_2 + 2,&DAT_00cce42e);
LAB_0026d410:
      uVar4 = 0;
    }
    else {
      do {
        cVar1 = *(char *)((long)param_2 + lVar3 + 8);
        if (cVar1 != (&DAT_00cce42e)[lVar3]) break;
        if (((cVar1 == '.') && (*param_2 == 0x31)) || (cVar1 == '\0')) goto LAB_0026d410;
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0x40);
      *(undefined1 *)((long)param_2 + 0x47) = 0;
      uVar2 = os_get_current_process();
      os_get_current_process_name(local_d8,0x20);
      nv_printf(4,
                "NVRM: API mismatch: the client \'%s\' (pid %u)\nNVRM: has the version %s, but this kernel module has\nNVRM: the version %s.  Please make sure that this\nNVRM: kernel module and all NVIDIA driver components\nNVRM: have the same version.\n"
                ,local_d8,uVar2,param_2 + 2,&DAT_00cce42e);
      uVar4 = 0xffff;
      os_string_copy(param_2 + 2,&DAT_00cce42e);
    }
  }
  threadStateFree(local_b8,0);
  return uVar4;
}


// ===== 0026d420 rm_power_source_change_event =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void rm_power_source_change_event(undefined8 param_1,int param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined1 auVar4 [16];
  undefined8 uStack_d0;
  uint local_ac;
  undefined1 local_a8 [144];
  
  if ((first_event_seen_5 != '\0') && (last_event_val_4 == param_2)) {
    return;
  }
  first_event_seen_5 = 1;
  last_event_val_4 = param_2;
  threadStateInit(local_a8,0);
  uStack_d0 = 0x26d471;
  iVar2 = rmapiLockAcquire(0,0x1002);
  if (iVar2 == 0) {
    auVar4 = gpumgrGetGpu(0);
    uStack_d0 = auVar4._8_8_;
    if (auVar4._0_8_ == 0) goto LAB_0026d510;
    lVar1 = *(long *)(auVar4._0_8_ + 0x4e0);
    iVar2 = os_ref_dynamic_power(lVar1,2);
    if (iVar2 == 0) {
      iVar2 = rmGpuLocksAcquire(0,0x1002);
      if (iVar2 == 0) {
        local_ac = 0;
        lVar3 = rmapiGetInterface(4);
        local_ac = (uint)(param_2 != 0);
        iVar2 = (**(code **)(lVar3 + 0x38))
                          (lVar3,*(undefined4 *)(lVar1 + 0x310),*(undefined4 *)(lVar1 + 0x318),
                           0x2080205b,&local_ac,4);
        rmGpuLocksRelease(0,0);
        os_unref_dynamic_power(lVar1,2);
        uStack_d0 = 0x26d5be;
        rmapiLockRelease();
        if (iVar2 == 0) {
          uStack_d0 = 0;
          goto LAB_0026d510;
        }
      }
      else {
        os_unref_dynamic_power(lVar1,2);
        uStack_d0 = 0x26d4d6;
        rmapiLockRelease();
      }
    }
    else {
      uStack_d0 = 0x26d53b;
      rmapiLockRelease();
    }
  }
  nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x119d,"rm_power_source_change_event",4,
               "NVRM: %s: Failed to handle Power Source change event, status=0x%x\n",
               "rm_power_source_change_event",iVar2);
LAB_0026d510:
  threadStateFree(local_a8,0,uStack_d0);
  return;
}


// ===== 0026d5d5 rm_request_dnotifier_state.cold =====

void rm_request_dnotifier_state_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026d5e0 rm_request_dnotifier_state =====

void rm_request_dnotifier_state(undefined8 param_1,long *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_ac;
  undefined1 local_a8 [152];
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (*(char *)(*param_2 + 0x240) == '\0') {
    return;
  }
  threadStateInit(local_a8,0);
  iVar3 = rmapiLockAcquire(0,0x4001);
  if (iVar3 == 0) {
    if (((long *)*param_2 != (long *)0x0) && (lVar1 = *(long *)*param_2, lVar1 != 0)) {
      iVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),0,0,0x4001,&local_ac);
      if (iVar3 == 0) {
        RmRequestDNotifierState(param_2);
        rmGpuGroupLockRelease(local_ac,0);
      }
    }
    rmapiLockRelease();
  }
  threadStateFree(local_a8,0);
  return;
}


// ===== 0026d6c0 rm_p2p_dma_map_pages =====

int rm_p2p_dma_map_pages
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulong param_4,uint param_5,
              long *param_6,undefined8 *param_7)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  long *plVar9;
  uint uVar10;
  uint uVar11;
  long *plVar12;
  uint uVar13;
  long local_f8;
  long *local_d0;
  undefined1 local_c8 [152];
  
  if (param_7 == (undefined8 *)0x0) {
    return 0x1f;
  }
  *param_7 = 0;
  threadStateInit(local_c8,0);
  iVar3 = rmapiLockAcquire(0,0x20001);
  if (iVar3 != 0) goto LAB_0026d72c;
  lVar6 = gpumgrGetGpuFromUuid(param_3,2);
  if (lVar6 == 0) {
    iVar3 = 0x1f;
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x4e0);
    if (*(char *)(lVar6 + 0x326) == '\0') {
      cVar2 = nv_grdma_pci_topology_supported(lVar6,param_2);
      if (cVar2 == '\0') {
        iVar3 = 0x56;
      }
      else if (param_5 != 0) {
        uVar7 = 0;
        plVar12 = param_6;
        do {
          iVar3 = nv_dma_map_peer(param_2,*(undefined8 *)(lVar6 + 0x2e0),1,param_4 / os_page_size,
                                  plVar12);
          if (iVar3 != 0) {
            plVar12 = param_6 + uVar7;
            if ((int)uVar7 != 0) {
              do {
                plVar9 = param_6 + 1;
                nv_dma_unmap_peer(param_2,param_4 / os_page_size,*param_6);
                param_6 = plVar9;
              } while (plVar9 != plVar12);
            }
            break;
          }
          uVar11 = (int)uVar7 + 1;
          uVar7 = (ulong)uVar11;
          plVar12 = plVar12 + 1;
        } while (param_5 != uVar11);
      }
    }
    else {
      local_d0 = (long *)0x0;
      if (param_4 < os_page_size) {
        iVar3 = 0x1f;
        nvAssertFailedNoLog("(pageSize >= os_page_size)","arch/nvalloc/unix/src/osapi.c",0x602);
      }
      else {
        bVar1 = false;
        local_f8 = 0;
        if (*(char *)(lVar6 + 0x328) == '\x02') {
          local_f8 = nv_dma_get_dev_pagemap(*param_6);
          if (local_f8 == 0) {
            iVar3 = 0x56;
            nvDbg_Printf("arch/nvalloc/unix/src/osapi.c",0x60a,"RmP2PDmaMapPages",4,
                         "NVRM: Failed to get a reference on dev_pagemap in CDMM(driver) mode\n");
            goto LAB_0026d860;
          }
          bVar1 = true;
        }
        if (param_4 == os_page_size) {
          iVar3 = nv_dma_map_alloc(param_2,param_5,param_6,0,param_7);
        }
        else {
          uVar13 = (uint)(param_4 / os_page_size);
          uVar11 = param_5 * uVar13;
          uVar7 = (ulong)uVar11;
          iVar3 = os_alloc_mem(&local_d0,uVar7 * 8,param_4 % os_page_size);
          iVar5 = iVar3;
          if (iVar3 == 0) {
            if (param_5 == 0) {
              iVar5 = nv_dma_map_alloc(param_2,0,local_d0,0,param_7);
              if (iVar5 == 0) goto LAB_0026dab6;
            }
            else {
              uVar8 = 0;
              plVar12 = param_6;
              do {
                iVar5 = (int)uVar8;
                local_d0[uVar8] = *plVar12;
                uVar10 = iVar5 + 1;
                uVar8 = (ulong)uVar10;
                if (1 < uVar13) {
                  do {
                    uVar4 = (int)uVar8 + 1;
                    local_d0[uVar8] = os_page_size + local_d0[(int)uVar8 - 1];
                    uVar8 = (ulong)uVar4;
                  } while (iVar5 + uVar13 != uVar4);
                  uVar8 = (ulong)((uVar13 - 1) + uVar10);
                }
                plVar12 = plVar12 + 1;
              } while (plVar12 != param_6 + param_5);
              iVar5 = nv_dma_map_alloc(param_2,uVar7,local_d0,0,param_7);
              if (iVar5 == 0) {
                uVar8 = 0;
                plVar12 = param_6;
                if (1 < uVar11) {
                  uVar10 = 0;
                  plVar9 = local_d0;
                  do {
                    uVar10 = uVar10 + 1;
                    if (uVar13 == uVar10) {
                      uVar10 = 0;
                    }
                    else if (plVar9[1] != *plVar9 + os_page_size) {
                      iVar3 = nv_dma_unmap_alloc(param_2,uVar7,local_d0,param_7);
                      if (iVar3 != 0) {
                        nvAssertOkFailedNoLog
                                  (iVar3,
                                   "nv_dma_unmap_alloc(peer, osPageCount, pOsDmaAddresses, ppPriv)",
                                   "arch/nvalloc/unix/src/osapi.c",0x66c);
                      }
                      iVar5 = 0x40;
                      goto LAB_0026da65;
                    }
                    plVar9 = plVar9 + 1;
                  } while (local_d0 + (ulong)(uVar11 - 2) + 1 != plVar9);
                }
                do {
                  plVar9 = plVar12 + 1;
                  *plVar12 = local_d0[uVar8];
                  uVar8 = (ulong)((int)uVar8 + uVar13);
                  plVar12 = plVar9;
                } while (param_6 + param_5 != plVar9);
LAB_0026dab6:
                os_free_mem(local_d0);
                if (bVar1) {
                  nv_dma_put_dev_pagemap(local_f8);
                }
                goto LAB_0026d860;
              }
            }
          }
LAB_0026da65:
          iVar3 = iVar5;
          if (local_d0 != (long *)0x0) {
            os_free_mem();
          }
        }
        if (bVar1) {
          nv_dma_put_dev_pagemap(local_f8);
        }
      }
    }
  }
LAB_0026d860:
  rmapiLockRelease();
LAB_0026d72c:
  threadStateFree(local_c8,0);
  return iVar3;
}


// ===== 0026dbe5 rm_p2p_get_gpu_info.cold =====

void rm_p2p_get_gpu_info_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026dbf0 rm_p2p_get_gpu_info =====

int rm_p2p_get_gpu_info(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4
                       ,long *param_5)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar2 = rmapiLockAcquire(0,0x20001);
  if (iVar2 != 0) goto LAB_0026dc34;
  iVar2 = RmP2PGetGpuByAddress(param_2,param_3,&local_d0);
  if (iVar2 == 0) {
    if (local_d0 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar3 = *(long *)(local_d0 + 0x4e0) + 0x2d;
    if (*(char *)(*(long *)(local_d0 + 0x4e0) + 0x2c) == '\0') {
      lVar3 = RmGetGpuUuidRaw_part_0();
      iVar2 = 0x12;
      if (lVar3 != 0) goto LAB_0026dcab;
    }
    else {
LAB_0026dcab:
      iVar2 = os_alloc_mem(param_4,0x10);
      if (iVar2 == 0) {
        os_mem_copy(*param_4,lVar3,0x10);
      }
    }
    *param_5 = local_d0;
  }
  rmapiLockRelease();
LAB_0026dc34:
  threadStateFree(local_c8,0);
  return iVar2;
}


// ===== 0026dcf0 rm_p2p_get_pages_persistent =====

int rm_p2p_get_pages_persistent
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined8 param_8,
              undefined8 param_9,undefined8 param_10,undefined8 param_11)

{
  int iVar1;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar1 = rmapiLockAcquire(0,0x20001);
  if (iVar1 == 0) {
    iVar1 = RmP2PGetPagesPersistent
                      (param_2,param_3,param_4,param_5,param_6,param_11,param_7,param_8,param_9,
                       param_10);
    rmapiLockRelease();
  }
  threadStateFree(local_c8,0);
  return iVar1;
}


// ===== 0026dd97 rm_p2p_get_pages.cold =====

void rm_p2p_get_pages_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0026ddb0 rm_p2p_get_pages =====

int rm_p2p_get_pages(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                    undefined8 param_9,undefined8 *param_10,undefined8 param_11,undefined1 *param_12
                    )

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long local_e0;
  long local_d0;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar3 = rmapiLockAcquire(0,0x20001);
  if (iVar3 != 0) goto LAB_0026ddfb;
  iVar3 = RmP2PGetPagesWithoutCallbackRegistration
                    (param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_12,
                     &local_d0,param_11);
  if (iVar3 == 0) {
    if (local_d0 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    lVar1 = *(long *)(local_d0 + 0x4e0);
    if (*(char *)(lVar1 + 0x2c) == '\0') {
      local_e0 = RmGetGpuUuidRaw_part_0(lVar1);
      if (local_e0 != 0) goto LAB_0026de89;
      iVar3 = RmP2PPutPages(param_2,param_3,param_4,param_11);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,"RmP2PPutPages(p2pToken, vaSpaceToken, gpuVirtualAddress, pPlatformData)",
                   "arch/nvalloc/unix/src/osapi.c",0x12b1);
      }
      iVar3 = 0xffff;
    }
    else {
      local_e0 = lVar1 + 0x2d;
LAB_0026de89:
      iVar3 = os_alloc_mem(param_10,0x10);
      if (iVar3 == 0) {
        os_mem_copy(*param_10,local_e0,0x10);
      }
    }
    *param_12 = *(undefined1 *)(lVar1 + 0x326);
  }
  rmapiLockRelease();
LAB_0026ddfb:
  threadStateFree(local_c8,0);
  return iVar3;
}


// ===== 0026df30 rm_p2p_register_callback =====

int rm_p2p_register_callback
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar1 = rmapiLockAcquire(0,0x20001);
  if (iVar1 == 0) {
    iVar1 = RmP2PRegisterCallback(param_2,param_3,param_4,param_5,param_6,param_7);
    rmapiLockRelease();
  }
  threadStateFree(local_c8,0);
  return iVar1;
}


// ===== 0026dfd0 rm_p2p_put_pages_persistent =====

int rm_p2p_put_pages_persistent
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 local_b8 [144];
  
  threadStateInit(local_b8,0);
  iVar1 = rmapiLockAcquire(0,0x20001);
  if (iVar1 == 0) {
    iVar1 = RmP2PPutPagesPersistent(param_2,param_3,param_4);
    rmapiLockRelease();
  }
  threadStateFree(local_b8,0);
  return iVar1;
}


// ===== 0026e050 rm_p2p_put_pages =====

int rm_p2p_put_pages(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                    undefined8 param_5)

{
  int iVar1;
  undefined1 local_c8 [152];
  
  threadStateInit(local_c8,0);
  iVar1 = rmapiLockAcquire(0,0x20001);
  if (iVar1 == 0) {
    iVar1 = RmP2PPutPages(param_2,param_3,param_4,param_5);
    rmapiLockRelease();
  }
  threadStateFree(local_c8,0);
  return iVar1;
}


// ===== 0026e0e0 rm_get_gpu_uuid =====

undefined8 rm_get_gpu_uuid(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  uint local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  iVar2 = os_alloc_mem(&local_b8,0x29);
  if (iVar2 == 0) {
    lVar3 = param_2 + 0x2d;
    if (*(char *)(param_2 + 0x2c) == '\0') {
      lVar3 = RmGetGpuUuidRaw_part_0(param_2);
      if (lVar3 == 0) {
        lVar3 = portStringLength("GPU-????????-????-????-????-????????????");
        portStringCopy(local_b8,0x29,"GPU-????????-????-????-????-????????????",lVar3 + 1);
        goto LAB_0026e17f;
      }
    }
    uVar1 = local_b8;
    iVar2 = transformGidToUserFriendlyString(lVar3,0x10,&local_b0,&local_bc,0,0);
    if (iVar2 == 0) {
      if (local_bc < 0x2a) {
        portMemCopy(uVar1,0x29,local_b0);
        portMemFree(local_b0);
        goto LAB_0026e17f;
      }
      portMemFree();
    }
    os_free_mem(local_b8);
  }
  local_b8 = 0;
LAB_0026e17f:
  threadStateFree(local_a8,0);
  return local_b8;
}


// ===== 0026e210 rm_get_gpu_uuid_raw =====

long rm_get_gpu_uuid_raw(undefined8 param_1,long param_2)

{
  undefined1 local_a8 [152];
  
  threadStateInit(local_a8,0);
  if (*(char *)(param_2 + 0x2c) == '\0') {
    param_2 = RmGetGpuUuidRaw_part_0(param_2);
  }
  else {
    param_2 = param_2 + 0x2d;
  }
  threadStateFree(local_a8,0);
  return param_2;
}


