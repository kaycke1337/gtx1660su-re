// ===== 0026596b FUN_0026596b =====

undefined8 FUN_0026596b(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  int local_c;
  
  lVar1 = *(long *)(param_1 + 8);
  if (*param_2 != 2) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("dstatus->phase == HWLOC_DISC_PHASE_CPU",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-noos.c"
                  ,0x19,"hwloc_look_noos");
  }
  if (*(long *)(*(long *)**(undefined8 **)(lVar1 + 0x18) + 0xb8) == 0) {
    local_c = FUN_0024da86(0);
    if (local_c < 1) {
      local_c = 1;
    }
    else {
      **(undefined1 **)(lVar1 + 0x288) = 1;
    }
    FUN_002531e1(*(undefined8 *)**(undefined8 **)(lVar1 + 0x18));
    FUN_0024dad7(lVar1,local_c);
  }
  lVar2 = FUN_0024dac5();
  if (0 < lVar2) {
    *(long *)(lVar1 + 0x338) = lVar2;
  }
  FUN_00265779(lVar1,0);
  return 0;
}


// ===== 00265a53 FUN_00265a53 =====

long FUN_00265a53(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = FUN_0025f967(param_1,param_2);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    *(code **)(lVar1 + 0x48) = FUN_0026596b;
  }
  return lVar1;
}


// ===== 00265aac FUN_00265aac =====

bool FUN_00265aac(undefined8 param_1,undefined4 param_2)

{
  int local_c;
  
  local_c = 1;
  FUN_002543c3(param_1,param_2,&local_c);
  if (local_c == 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("filter != HWLOC_TYPE_FILTER_KEEP_IMPORTANT",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/plugins.h"
                  ,0x218,"hwloc_filter_check_keep_object_type");
  }
  return local_c != 1;
}


// ===== 00265b0c FUN_00265b0c =====

void FUN_00265b0c(char *param_1,char *param_2,size_t param_3)

{
  strncasecmp(param_1,param_2,param_3);
  return;
}


// ===== 00265b39 FUN_00265b39 =====

undefined8 FUN_00265b39(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xd) || (param_1 == 0x13)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00265b5a FUN_00265b5a =====

undefined8 FUN_00265b5a(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 4) || (0xb < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00265b7b FUN_00265b7b =====

void FUN_00265b7b(long param_1,long *param_2,size_t param_3,int param_4)

{
  ulong uVar1;
  long lVar2;
  int local_d8 [13];
  int local_a4;
  char *local_a0;
  char *local_98;
  char *local_90;
  undefined4 local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  int local_68;
  uint local_64;
  void *local_60;
  void *local_58;
  size_t local_50;
  uint local_44;
  char *local_40;
  int local_38;
  uint local_34;
  ulong local_30;
  uint local_24;
  uint local_20;
  uint local_1c;
  ulong local_18;
  char *local_10;
  
  local_10 = (char *)*param_2;
  local_50 = param_2[1];
  local_58 = (void *)0x0;
  if (local_10 == (char *)0x0) {
    return;
  }
  local_58 = calloc(param_3,4);
  if (local_58 == (void *)0x0) {
    if (param_4 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"Failed to allocate synthetic index array of size %lu\n"
              ,param_3);
      return;
    }
    return;
  }
  local_18 = strspn(local_10,"0123456789,");
  if (local_18 == local_50) {
    local_18 = 0;
    while( true ) {
      if (param_3 <= local_18) {
        param_2[2] = (long)local_58;
        return;
      }
      uVar1 = strtoul(local_10,&local_90,10);
      local_84 = (undefined4)uVar1;
      if (local_10 == local_90) break;
      *(undefined4 *)(local_18 * 4 + (long)local_58) = local_84;
      if (local_18 == param_3 - 1) {
        local_10 = local_90;
      }
      else {
        if (*local_90 != ',') {
          if (param_4 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "Missing comma after synthetic index #%lu at \'%s\'\n",local_18,local_10);
          }
          goto LAB_0026680c;
        }
        local_10 = local_90 + 1;
      }
      local_18 = local_18 + 1;
    }
    if (param_4 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"Failed to read synthetic index #%lu at \'%s\'\n",
              local_18,local_10);
    }
  }
  else {
    local_1c = 1;
    local_24 = (uint)param_3;
    local_30 = 1;
    local_40 = local_10;
    while (((local_40 != (char *)0x0 && (local_40 = strchr(local_40,0x3a), local_40 != (char *)0x0))
           && (local_40 < local_10 + local_50))) {
      local_1c = local_1c + 1;
      local_40 = local_40 + 1;
    }
    local_60 = malloc((ulong)(local_1c + 1) * 0xc);
    if (local_60 != (void *)0x0) {
      if ((*local_10 < '0') || ('9' < *local_10)) {
        local_20 = 0;
        for (local_40 = local_10; local_40 != (char *)0x0; local_40 = local_40 + 1) {
          local_6c = FUN_002584c0(local_40,&local_a4,local_d8,0x28);
          if (local_6c < 0) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Failed to read synthetic index interleaving loop type \'%s\'\n",local_40);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          if (((local_a4 == 0x11) || (local_a4 == 0xe)) || ((local_a4 == 0xf || (local_a4 == 0x10)))
             ) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Misc object type disallowed in synthetic index interleaving loop type \'%s\'\n"
                      ,local_40);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          local_18 = 0;
          while (*(int *)(local_18 * 0x50 + param_1 + 0x30) != 0) {
            if ((*(int *)(local_18 * 0x50 + param_1 + 0x40) == local_a4) &&
               (((local_a4 != 0xc || (local_d8[0] == -1)) ||
                (local_d8[0] == *(int *)(local_18 * 0x50 + param_1 + 0x44))))) {
              *(int *)((long)local_60 + (ulong)local_20 * 0xc + 8) = (int)local_18;
              goto LAB_0026625d;
            }
            local_18 = local_18 + 1;
          }
          *(undefined4 *)((long)local_60 + (ulong)local_20 * 0xc + 8) = 0xffffffff;
LAB_0026625d:
          if (*(int *)((long)local_60 + (ulong)local_20 * 0xc + 8) == -1) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Failed to find level for synthetic index interleaving loop type \'%s\'\n",
                      local_40);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          local_40 = strchr(local_40,0x3a);
          if ((local_40 == (char *)0x0) || (local_10 + local_50 < local_40)) break;
          local_20 = local_20 + 1;
        }
        for (local_20 = 0; local_20 < local_1c; local_20 = local_20 + 1) {
          local_70 = *(uint *)((long)local_60 + (ulong)local_20 * 0xc + 8);
          local_44 = 0;
          for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
            if ((local_70 == *(uint *)((long)local_60 + local_18 * 0xc + 8)) &&
               (local_18 != local_20)) {
              if (param_4 != 0) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "Invalid duplicate interleaving loop type in synthetic index \'%s\'\n",
                        local_10);
              }
              free(local_60);
              goto LAB_0026680c;
            }
            if ((*(uint *)((long)local_60 + local_18 * 0xc + 8) < local_70) &&
               (local_44 < *(uint *)((long)local_60 + local_18 * 0xc + 8))) {
              local_44 = *(uint *)((long)local_60 + local_18 * 0xc + 8);
            }
          }
          local_74 = (uint)(param_3 / *(ulong *)((ulong)local_70 * 0x50 + param_1 + 0x38));
          uVar1 = *(ulong *)((ulong)local_70 * 0x50 + param_1 + 0x38) /
                  *(ulong *)((ulong)local_44 * 0x50 + param_1 + 0x38);
          local_78 = (int)uVar1;
          *(uint *)((ulong)local_20 * 0xc + (long)local_60) = local_74;
          *(int *)((long)local_60 + (ulong)local_20 * 0xc + 4) = local_78;
          if (local_78 == 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("nb",
                          "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                          ,0x103,"hwloc_synthetic_process_indexes");
          }
          if (local_74 == 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("step",
                          "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                          ,0x104,"hwloc_synthetic_process_indexes");
          }
          if (local_74 < local_24) {
            local_24 = local_74;
          }
          local_30 = (uVar1 & 0xffffffff) * local_30;
        }
      }
      else {
        local_20 = 0;
        local_40 = local_10;
        while (local_40 != (char *)0x0) {
          lVar2 = strtol(local_40,&local_98,0);
          local_64 = (uint)lVar2;
          if ((local_40 == local_98) || (*local_98 != '*')) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Failed to read synthetic index interleaving loop \'%s\' without number before \'*\'\n"
                      ,local_40);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          if (local_64 == 0) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Invalid interleaving loop with step 0 at \'%s\'\n",local_40);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          local_98 = local_98 + 1;
          uVar1 = strtol(local_98,&local_a0,0);
          local_68 = (int)uVar1;
          if ((local_a0 == local_98) ||
             ((((*local_a0 != '\0' && (*local_a0 != ':')) && (*local_a0 != ')')) &&
              (*local_a0 != ' ')))) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Failed to read synthetic index interleaving loop \'%s\' without number between \'*\' and \':\'\n"
                      ,local_40);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          if (local_68 == 0) {
            if (param_4 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Invalid interleaving loop with number 0 at \'%s\'\n",local_98);
            }
            free(local_60);
            goto LAB_0026680c;
          }
          *(uint *)((ulong)local_20 * 0xc + (long)local_60) = local_64;
          *(int *)((long)local_60 + (ulong)local_20 * 0xc + 4) = local_68;
          if (local_64 < local_24) {
            local_24 = local_64;
          }
          local_30 = (uVar1 & 0xffffffff) * local_30;
          local_20 = local_20 + 1;
          if ((*local_a0 == ')') || (*local_a0 == ' ')) break;
          local_40 = local_a0 + 1;
        }
      }
      if (local_30 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("nbs",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                      ,0x10a,"hwloc_synthetic_process_indexes");
      }
      if (local_30 != param_3) {
        if ((ulong)local_24 != param_3 / local_30) {
          if (param_4 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "Invalid index interleaving total width %lu instead of %lu\n",local_30,param_3);
          }
          free(local_60);
          goto LAB_0026680c;
        }
        *(undefined4 *)((long)local_60 + (ulong)local_1c * 0xc) = 1;
        *(int *)((long)local_60 + (ulong)local_1c * 0xc + 4) = (int)(param_3 / local_30);
        local_1c = local_1c + 1;
      }
      local_38 = 1;
      for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
        local_7c = *(uint *)((long)local_60 + local_18 * 0xc);
        local_80 = *(uint *)((long)local_60 + local_18 * 0xc + 4);
        for (local_34 = 0; local_34 < param_3; local_34 = local_34 + 1) {
          *(uint *)((long)local_58 + (ulong)local_34 * 4) =
               ((local_34 / local_7c) % local_80) * local_38 +
               *(int *)((long)local_58 + (ulong)local_34 * 4);
        }
        local_38 = local_38 * local_80;
      }
      free(local_60);
      local_34 = 0;
      while( true ) {
        if (param_3 <= local_34) {
          param_2[2] = (long)local_58;
          return;
        }
        if (param_3 <= *(uint *)((long)local_58 + (ulong)local_34 * 4)) break;
        if ((*(int *)((long)local_58 + (ulong)local_34 * 4) == 0) && (local_34 != 0)) {
          if (param_4 != 0) {
            fwrite("Invalid index interleaving generates duplicate index values\n",1,0x3c,
                   *(FILE **)PTR_stderr_0032efe0);
          }
          goto LAB_0026680c;
        }
        local_34 = local_34 + 1;
      }
      if (param_4 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "Invalid index interleaving generates out-of-range index %u\n",
                (ulong)*(uint *)((long)local_58 + (ulong)local_34 * 4));
      }
    }
  }
LAB_0026680c:
  free(local_58);
  return;
}


// ===== 00266821 FUN_00266821 =====

ulonglong FUN_00266821(char *param_1,long *param_2)

{
  int iVar1;
  char *local_18;
  ulonglong local_10;
  
  local_10 = strtoull(param_1,&local_18,0);
  iVar1 = FUN_00265b0c(local_18,&DAT_002ee44d,2);
  if (iVar1 == 0) {
    local_10 = local_10 * 1000000000000;
    local_18 = local_18 + 2;
  }
  else {
    iVar1 = FUN_00265b0c(local_18,&DAT_002ee450,3);
    if (iVar1 == 0) {
      local_10 = local_10 << 0x28;
      local_18 = local_18 + 3;
    }
    else {
      iVar1 = FUN_00265b0c(local_18,&DAT_002ee454,2);
      if (iVar1 == 0) {
        local_10 = local_10 * 1000000000;
        local_18 = local_18 + 2;
      }
      else {
        iVar1 = FUN_00265b0c(local_18,&DAT_002ee457,3);
        if (iVar1 == 0) {
          local_10 = local_10 << 0x1e;
          local_18 = local_18 + 3;
        }
        else {
          iVar1 = FUN_00265b0c(local_18,&DAT_002ee45b,2);
          if (iVar1 == 0) {
            local_10 = local_10 * 1000000;
            local_18 = local_18 + 2;
          }
          else {
            iVar1 = FUN_00265b0c(local_18,&DAT_002ee45e,3);
            if (iVar1 == 0) {
              local_10 = local_10 << 0x14;
              local_18 = local_18 + 3;
            }
            else {
              iVar1 = FUN_00265b0c(local_18,&DAT_002ee462,2);
              if (iVar1 == 0) {
                local_10 = local_10 * 1000;
                local_18 = local_18 + 2;
              }
              else {
                iVar1 = FUN_00265b0c(local_18,&DAT_002ee465,3);
                if (iVar1 == 0) {
                  local_10 = local_10 << 10;
                  local_18 = local_18 + 3;
                }
              }
            }
          }
        }
      }
    }
  }
  *param_2 = (long)local_18;
  return local_10;
}


// ===== 00266a12 FUN_00266a12 =====

undefined8 FUN_00266a12(char *param_1,long *param_2,undefined4 *param_3,long *param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  char *local_50 [2];
  size_t local_40;
  int local_34;
  char *local_30;
  undefined4 local_24;
  size_t local_20;
  char *local_18;
  undefined8 local_10;
  
  local_24 = *param_3;
  local_10 = 0;
  local_18 = (char *)0x0;
  local_20 = 0;
  local_50[0] = param_1;
  local_30 = strchr(param_1,0x29);
  if (local_30 == (char *)0x0) {
    if (param_5 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "Missing attribute closing bracket in synthetic string doesn\'t have a number of objects at \'%s\'\n"
              ,local_50[0]);
    }
    piVar2 = __errno_location();
    *piVar2 = 0x16;
  }
  else {
    do {
      while( true ) {
        if (*local_50[0] == ')') {
          *(undefined8 *)(param_3 + 4) = local_10;
          if (local_18 != (char *)0x0) {
            if ((*param_4 != 0) && (param_5 != 0)) {
              fwrite("Overwriting duplicate indexes attribute with last occurence\n",1,0x3c,
                     *(FILE **)PTR_stderr_0032efe0);
            }
            *param_4 = (long)local_18;
            param_4[1] = local_20;
          }
          *param_2 = (long)(local_30 + 1);
          return 0;
        }
        local_34 = FUN_00265b5a(local_24);
        if ((local_34 == 0) || (iVar1 = strncmp("size=",local_50[0],5), iVar1 != 0)) {
          if ((local_34 == 0) && (iVar1 = strncmp("memory=",local_50[0],7), iVar1 == 0)) {
            local_10 = FUN_00266821(local_50[0] + 7,local_50);
          }
          else {
            iVar1 = strncmp("indexes=",local_50[0],8);
            if (iVar1 == 0) {
              local_18 = local_50[0] + 8;
              local_50[0] = local_50[0] + 8;
              local_20 = strcspn(local_50[0]," )");
              local_50[0] = local_50[0] + local_20;
            }
            else {
              local_40 = strcspn(local_50[0]," )");
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "hwloc/synthetic: Ignoring unknown attribute at \'%s\'\n",local_50[0]);
              local_50[0] = local_50[0] + local_40;
            }
          }
        }
        else {
          local_10 = FUN_00266821(local_50[0] + 5,local_50);
        }
        if (*local_50[0] != ' ') break;
        local_50[0] = local_50[0] + 1;
      }
    } while (*local_50[0] == ')');
    if (param_5 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"Missing parameter separator at \'%s\'\n",local_50[0]);
    }
    piVar2 = __errno_location();
    *piVar2 = 0x16;
  }
  return 0xffffffff;
}


// ===== 00266cc6 FUN_00266cc6 =====

void FUN_00266cc6(int *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0xc) {
    if (param_1[1] == -1) {
      iVar1 = *(int *)(param_2 + 0x30);
      *(int *)(param_2 + 0x30) = iVar1 + -1;
      param_1[1] = iVar1;
    }
  }
  else {
    iVar2 = FUN_00265b5a(iVar1);
    if (iVar2 == 0) {
      if ((iVar1 == 0xd) && (*(long *)(param_1 + 4) == 0)) {
        param_1[4] = 0x40000000;
        param_1[5] = 0;
      }
    }
    else if (*(long *)(param_1 + 4) == 0) {
      if (param_1[1] == 1) {
        param_1[4] = 0x8000;
        param_1[5] = 0;
      }
      else {
        *(long *)(param_1 + 4) = 0x40000L << ((char)param_1[1] * '\x02' & 0x3fU);
      }
    }
  }
  return;
}


// ===== 00266d83 FUN_00266d83 =====

void FUN_00266d83(long param_1)

{
  void *__ptr;
  int *piVar1;
  long *plVar2;
  uint local_c;
  
  for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
    piVar1 = (int *)(param_1 + (ulong)local_c * 0x50 + 0x30);
    plVar2 = (long *)(piVar1 + 0x12);
    while (*plVar2 != 0) {
      __ptr = (void *)*plVar2;
      *plVar2 = *(long *)((long)__ptr + 0x18);
      free(__ptr);
    }
    free(*(void **)(piVar1 + 0xe));
    if (*piVar1 == 0) break;
  }
  free(*(void **)(param_1 + 0x20));
  return;
}


// ===== 00266e36 FUN_00266e36 =====

/* WARNING: Type propagation algorithm not settling */

int FUN_00266e36(undefined8 *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char *local_158;
  undefined8 *local_150;
  undefined4 local_148 [2];
  undefined4 local_140;
  undefined4 local_134;
  undefined1 local_118 [12];
  int local_10c [21];
  char *local_b8;
  uint local_ac;
  undefined8 *local_a8;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  char *local_68;
  int *local_60;
  ulong local_58;
  int local_4c;
  char *local_48;
  long local_40;
  long *local_38;
  long local_30;
  int local_24;
  uint local_20;
  uint local_1c;
  ulong local_18;
  char *local_10;
  
  local_24 = 0;
  local_158 = param_2;
  local_150 = param_1;
  local_48 = getenv("HWLOC_SYNTHETIC_VERBOSE");
  local_30 = 1;
  if (local_48 != (char *)0x0) {
    local_24 = atoi(local_48);
  }
  local_150[1] = 0;
  local_150[4] = 0;
  local_150[7] = 1;
  *(undefined4 *)(local_150 + 8) = 0;
  local_150[0xb] = 0;
  local_150[0xd] = 0;
  local_150[10] = 0;
  local_150[0xf] = 0;
  local_10c[1] = 1;
  if (*local_158 == '(') {
    local_4c = FUN_00266a12(local_158 + 1,&local_158,local_150 + 8,local_150 + 0xb,local_24);
    if (local_4c < 0) {
      return local_4c;
    }
  }
  local_150[2] = 0;
  local_150[4] = 0;
  local_18 = 1;
  local_10 = local_158;
  while (*local_10 != '\0') {
    local_10c[0] = -1;
    *(undefined4 *)(local_150 + (local_18 - 1) * 10 + 6) = 0;
    for (; (*local_10 == ' ' || (*local_10 == '\n')); local_10 = local_10 + 1) {
    }
    if (*local_10 == '\0') break;
    if (*local_10 == '[') {
      local_10 = local_10 + 1;
      iVar1 = FUN_002584c0(local_10,local_10c,local_148,0x28);
      if (iVar1 < 0) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "Synthetic string with unknown attached object type at \'%s\'\n",local_10);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
LAB_00268292:
        FUN_00266d83(local_150);
        return -1;
      }
      if (local_10c[0] != 0xd) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "Synthetic string with disallowed attached object type at \'%s\'\n",local_10);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        goto LAB_00268292;
      }
      local_150[1] = local_150[1] + local_150[(local_18 - 1) * 10 + 7];
      local_60 = malloc(0x20);
      if (local_60 != (int *)0x0) {
        *local_60 = local_10c[0];
        local_60[4] = 0;
        local_60[5] = 0;
        local_60[6] = 0;
        local_60[7] = 0;
        for (local_38 = local_150 + (local_18 - 1) * 10 + 0xf; *local_38 != 0;
            local_38 = (long *)(*local_38 + 0x18)) {
        }
        *local_38 = (long)local_60;
      }
      local_b8 = strchr(local_10,0x5d);
      if (local_b8 == (char *)0x0) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "Synthetic string doesn\'t have a closing `]\' after attached object type at \'%s\'\n"
                  ,local_10);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        goto LAB_00268292;
      }
      local_68 = strchr(local_10,0x28);
      if (((local_68 != (char *)0x0) && (local_68 < local_b8)) && (local_60 != (int *)0x0)) {
        local_4c = FUN_00266a12(local_68 + 1,local_118,local_60,local_150 + 2,local_24);
        if (local_4c < 0) goto LAB_00268292;
      }
      local_b8 = local_b8 + 1;
    }
    else {
      local_150[(local_18 + 1) * 10 + 1] = 0;
      local_150[local_18 * 10 + 0xd] = 0;
      local_150[local_18 * 10 + 0xf] = 0;
      if ((*local_10 < '0') || ('9' < *local_10)) {
        iVar1 = FUN_002584c0(local_10,local_10c,local_148,0x28);
        if (iVar1 < 0) {
          iVar1 = strncmp(local_10,"Tile",4);
          if ((iVar1 != 0) && (iVar1 = strncmp(local_10,"Module",6), iVar1 != 0)) {
            if (local_24 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "Synthetic string with unknown object type at \'%s\'\n",local_10);
            }
            piVar2 = __errno_location();
            *piVar2 = 0x16;
            goto LAB_00268292;
          }
          local_10c[0] = 0xc;
        }
        if ((((local_10c[0] == 0) || (local_10c[0] == 0x11)) || (local_10c[0] == 0xe)) ||
           ((local_10c[0] == 0xf || (local_10c[0] == 0x10)))) {
          if (local_24 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "Synthetic string with disallowed object type at \'%s\'\n",local_10);
          }
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          goto LAB_00268292;
        }
        local_b8 = strchr(local_10,0x3a);
        if (local_b8 == (char *)0x0) {
          if (local_24 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "Synthetic string doesn\'t have a `:\' after object type at \'%s\'\n",local_10);
          }
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          goto LAB_00268292;
        }
        local_10 = local_b8 + 1;
      }
      *(int *)(local_150 + local_18 * 10 + 8) = local_10c[0];
      *(undefined4 *)((long)local_150 + local_18 * 0x50 + 0x44) = 0xffffffff;
      *(undefined4 *)(local_150 + local_18 * 10 + 9) = 0xffffffff;
      iVar1 = FUN_00265b5a(local_10c[0]);
      if (iVar1 == 0) {
        if (local_10c[0] == 0xc) {
          *(undefined4 *)((long)local_150 + local_18 * 0x50 + 0x44) = local_148[0];
        }
      }
      else {
        *(undefined4 *)((long)local_150 + local_18 * 0x50 + 0x44) = local_140;
        *(undefined4 *)(local_150 + local_18 * 10 + 9) = local_134;
      }
      local_58 = strtoul(local_10,&local_b8,0);
      if (local_10 == local_b8) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "Synthetic string doesn\'t have a number of objects at \'%s\'\n",local_10);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        goto LAB_00268292;
      }
      if (local_58 == 0) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "Synthetic string with disallowed 0 number of objects at \'%s\'\n",local_10);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        goto LAB_00268292;
      }
      local_30 = local_30 * local_58;
      local_150[local_18 * 10 + 7] = local_30;
      local_150[(local_18 + 1) * 10 + 1] = 0;
      local_150[local_18 * 10 + 0xd] = 0;
      local_150[(local_18 + 1) * 10] = 0;
      if (*local_b8 == '(') {
        local_4c = FUN_00266a12(local_b8 + 1,&local_b8,local_150 + local_18 * 10 + 8,
                                local_150 + (local_18 + 1) * 10 + 1,local_24);
        if (local_4c < 0) goto LAB_00268292;
      }
      if (0x7f < local_18 + 1) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"Too many synthetic levels, max %d\n",0x80);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        goto LAB_00268292;
      }
      if (0xffffffff < local_58) {
        if (local_24 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"Too big arity, max %u\n",0xffffffff);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        goto LAB_00268292;
      }
      *(int *)(local_150 + (local_18 - 1) * 10 + 6) = (int)local_58;
      local_18 = local_18 + 1;
    }
    local_10 = local_b8;
  }
  if ((*(int *)(local_150 + (local_18 - 1) * 10 + 8) == -1) ||
     (*(int *)(local_150 + (local_18 - 1) * 10 + 8) == 3)) {
    *(undefined4 *)(local_150 + (local_18 - 1) * 10 + 8) = 3;
    for (local_1c = 0; local_1c < 0x14; local_1c = local_1c + 1) {
      local_10c[(ulong)local_1c + 1] = 0;
    }
    for (local_1c = (int)local_18 - 1; local_1c != 0; local_1c = local_1c - 1) {
      local_ac = *(uint *)(local_150 + (ulong)local_1c * 10 + 8);
      if (local_ac != 0xffffffff) {
        local_10c[(ulong)local_ac + 1] = local_10c[(ulong)local_ac + 1] + 1;
      }
    }
    if (local_10c[4] == 0) {
      if (local_24 != 0) {
        fwrite("Synthetic string missing ending number of PUs\n",1,0x2e,
               *(FILE **)PTR_stderr_0032efe0);
      }
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      iVar1 = -1;
    }
    else if (local_10c[4] < 2) {
      if (local_10c[2] < 2) {
        if (local_10c[0x14] < 2) {
          if (local_10c[0xe] < 2) {
            if ((local_10c[0xe] == 0) || (local_150[1] == 0)) {
              if (local_10c[3] < 2) {
                local_20 = 0;
                for (local_1c = 1; (ulong)local_1c < local_18 - 1; local_1c = local_1c + 1) {
                  if (*(int *)(local_150 + (ulong)local_1c * 10 + 8) == -1) {
                    local_20 = local_20 + 1;
                  }
                }
                if ((local_20 == 0) || ((ulong)local_20 == local_18 - 2)) {
                  if (local_20 != 0) {
                    iVar1 = (int)local_18 + -2;
                    if ((iVar1 == 0) || (local_150[1] != 0)) {
                      local_70 = 0;
                    }
                    else {
                      local_70 = 1;
                    }
                    iVar1 = iVar1 - local_70;
                    local_74 = (uint)(iVar1 != 0);
                    iVar1 = iVar1 - local_74;
                    local_78 = (uint)(iVar1 != 0);
                    local_80 = iVar1 - local_78;
                    local_7c = 4;
                    if (local_80 < 5) {
                      local_7c = local_80;
                    }
                    local_80 = local_80 - local_7c;
                    for (local_1c = 0; local_1c < local_80; local_1c = local_1c + 1) {
                      local_a0 = local_1c + 1;
                      *(undefined4 *)(local_150 + (ulong)local_a0 * 10 + 8) = 0xc;
                      local_10c[0xd] = local_10c[0xd] + 1;
                    }
                    if (local_74 != 0) {
                      local_84 = local_80 + 1;
                      *(undefined4 *)(local_150 + (ulong)local_84 * 10 + 8) = 1;
                      local_10c[2] = 1;
                    }
                    if (local_70 != 0) {
                      local_88 = local_74 + local_80 + 1;
                      *(undefined4 *)(local_150 + (ulong)local_88 * 10 + 8) = 0xd;
                      local_10c[0xe] = 1;
                    }
                    if (local_7c != 0) {
                      local_8c = local_70 + local_80 + local_74 + 1;
                      local_90 = local_8c + (2 < local_7c);
                      local_94 = local_90 + 1;
                      local_98 = local_90 + 2;
                      if (2 < local_7c) {
                        *(undefined4 *)(local_150 + (ulong)local_8c * 10 + 8) = 6;
                        *(undefined4 *)((long)local_150 + (ulong)local_8c * 0x50 + 0x44) = 3;
                        *(undefined4 *)(local_150 + (ulong)local_8c * 10 + 9) = 0;
                        local_10c[7] = 1;
                      }
                      *(undefined4 *)(local_150 + (ulong)local_90 * 10 + 8) = 5;
                      *(undefined4 *)((long)local_150 + (ulong)local_90 * 0x50 + 0x44) = 2;
                      *(undefined4 *)(local_150 + (ulong)local_90 * 10 + 9) = 0;
                      local_10c[6] = 1;
                      if (1 < local_7c) {
                        *(undefined4 *)(local_150 + (ulong)local_94 * 10 + 8) = 4;
                        *(undefined4 *)((long)local_150 + (ulong)local_94 * 0x50 + 0x44) = 1;
                        *(undefined4 *)(local_150 + (ulong)local_94 * 10 + 9) = 1;
                        local_10c[5] = 1;
                      }
                      if (3 < local_7c) {
                        *(undefined4 *)(local_150 + (ulong)local_98 * 10 + 8) = 9;
                        *(undefined4 *)((long)local_150 + (ulong)local_98 * 0x50 + 0x44) = 1;
                        *(undefined4 *)(local_150 + (ulong)local_98 * 10 + 9) = 2;
                        local_10c[10] = 1;
                      }
                    }
                    local_6c = local_80;
                    if (local_78 != 0) {
                      local_9c = local_7c + local_80 + local_74 + local_70 + 1;
                      *(undefined4 *)(local_150 + (ulong)local_9c * 10 + 8) = 2;
                      local_10c[3] = 1;
                    }
                  }
                  if ((local_10c[0xe] == 0) && (local_150[1] == 0)) {
                    if (local_24 != 0) {
                      fwrite("Inserting a NUMA level with a single object at depth 1\n",1,0x37,
                             *(FILE **)PTR_stderr_0032efe0);
                    }
                    memmove(local_150 + 0x1a,local_150 + 0x10,local_18 * 0x50);
                    *(undefined4 *)(local_150 + 0x12) = 0xd;
                    local_150[0x15] = 0;
                    local_150[0x17] = 0;
                    local_150[0x14] = 0;
                    local_150[0x11] = local_150[7];
                    *(undefined4 *)(local_150 + 0x10) = *(undefined4 *)(local_150 + 6);
                    *(undefined4 *)(local_150 + 6) = 1;
                    local_18 = local_18 + 1;
                  }
                  for (local_1c = 0; local_1c < local_18; local_1c = local_1c + 1) {
                    local_a8 = local_150 + (ulong)local_1c * 10 + 6;
                    FUN_00266cc6(local_a8 + 2,local_10c + 1);
                    for (local_40 = local_a8[9]; local_40 != 0;
                        local_40 = *(long *)(local_40 + 0x18)) {
                      FUN_00266cc6(local_40,local_10c + 1);
                    }
                    FUN_00265b7b(local_150,local_a8 + 5,local_a8[1],local_24);
                  }
                  FUN_00265b7b(local_150,local_150 + 2,local_150[1],local_24);
                  pcVar3 = strdup(local_158);
                  *local_150 = pcVar3;
                  *(undefined4 *)(local_150 + (local_18 - 1) * 10 + 6) = 0;
                  iVar1 = 0;
                }
                else {
                  if (local_24 != 0) {
                    fwrite("Synthetic string cannot mix unspecified and specified types for levels\n"
                           ,1,0x47,*(FILE **)PTR_stderr_0032efe0);
                  }
                  piVar2 = __errno_location();
                  *piVar2 = 0x16;
                  iVar1 = -1;
                }
              }
              else {
                if (local_24 != 0) {
                  fwrite("Synthetic string cannot have several core levels\n",1,0x31,
                         *(FILE **)PTR_stderr_0032efe0);
                }
                piVar2 = __errno_location();
                *piVar2 = 0x16;
                iVar1 = -1;
              }
            }
            else {
              if (local_24 != 0) {
                fwrite("Synthetic string cannot have NUMA nodes both as a level and attached\n",1,
                       0x45,*(FILE **)PTR_stderr_0032efe0);
              }
              piVar2 = __errno_location();
              *piVar2 = 0x16;
              iVar1 = -1;
            }
          }
          else {
            if (local_24 != 0) {
              fwrite("Synthetic string cannot have several NUMA node levels\n",1,0x36,
                     *(FILE **)PTR_stderr_0032efe0);
            }
            piVar2 = __errno_location();
            *piVar2 = 0x16;
            iVar1 = -1;
          }
        }
        else {
          if (local_24 != 0) {
            fwrite("Synthetic string cannot have several die levels\n",1,0x30,
                   *(FILE **)PTR_stderr_0032efe0);
          }
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          iVar1 = -1;
        }
      }
      else {
        if (local_24 != 0) {
          fwrite("Synthetic string cannot have several package levels\n",1,0x34,
                 *(FILE **)PTR_stderr_0032efe0);
        }
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        iVar1 = -1;
      }
    }
    else {
      if (local_24 != 0) {
        fwrite("Synthetic string cannot have several PU levels\n",1,0x2f,
               *(FILE **)PTR_stderr_0032efe0);
      }
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      iVar1 = -1;
    }
  }
  else {
    if (local_24 != 0) {
      fwrite("Synthetic string cannot use non-PU type for last level\n",1,0x37,
             *(FILE **)PTR_stderr_0032efe0);
    }
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    iVar1 = -1;
  }
  return iVar1;
}


// ===== 002682a8 FUN_002682a8 =====

void FUN_002682a8(long param_1,undefined4 *param_2)

{
  long lVar1;
  void *pvVar2;
  
  switch(*param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 0x13:
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    *(undefined4 *)(*(long *)(param_2 + 10) + 8) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(*(long *)(param_2 + 10) + 0xc) = 0x40;
    *(undefined4 *)(*(long *)(param_2 + 10) + 0x14) = *(undefined4 *)(param_1 + 8);
    **(undefined8 **)(param_2 + 10) = *(undefined8 *)(param_1 + 0x10);
    break;
  case 0xc:
    *(undefined4 *)(*(long *)(param_2 + 10) + 4) = 10;
    *(int *)(*(long *)(param_2 + 10) + 8) = *(int *)(param_1 + 4) + -1;
    break;
  case 0xd:
    **(undefined8 **)(param_2 + 10) = *(undefined8 *)(param_1 + 0x10);
    *(undefined4 *)(*(long *)(param_2 + 10) + 8) = 1;
    lVar1 = *(long *)(param_2 + 10);
    pvVar2 = malloc(0x10);
    *(void **)(lVar1 + 0x10) = pvVar2;
    memset(*(void **)(*(long *)(param_2 + 10) + 0x10),0,0x10);
    **(undefined8 **)(*(long *)(param_2 + 10) + 0x10) = 0x1000;
    *(ulong *)(*(long *)(*(long *)(param_2 + 10) + 0x10) + 8) = *(ulong *)(param_1 + 0x10) >> 0xc;
    break;
  default:
                    /* WARNING: Subroutine does not return */
    __assert_fail("0",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                  ,0x37d,"hwloc_synthetic_set_attr");
  }
  return;
}


// ===== 0026840b FUN_0026840b =====

uint FUN_0026840b(long param_1,int param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = local_c + 1;
  if (*(long *)(param_1 + 0x10) == 0) {
    iVar1 = FUN_00265b5a(param_2);
    if ((iVar1 != 0) || (param_2 == 0xc)) {
      local_c = 0xffffffff;
    }
  }
  else {
    local_c = *(uint *)(*(long *)(param_1 + 0x10) + (ulong)local_c * 4);
  }
  return local_c;
}


// ===== 00268474 FUN_00268474 =====

void FUN_00268474(undefined8 param_1,long param_2,int *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_3 != (int *)0x0) {
    if (*param_3 != 0xd) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("attached->attr.type == HWLOC_OBJ_NUMANODE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                    ,0x39c,"hwloc_synthetic_insert_attached");
    }
    uVar1 = FUN_0026840b(param_2 + 0x10,0xd);
    lVar2 = FUN_0024febd(param_1,*param_3,uVar1);
    uVar3 = FUN_002611e2(param_4);
    *(undefined8 *)(lVar2 + 0xb8) = uVar3;
    uVar3 = FUN_00260eab();
    *(undefined8 *)(lVar2 + 200) = uVar3;
    FUN_0026197d(*(undefined8 *)(lVar2 + 200),uVar1);
    FUN_002682a8(param_3,lVar2);
    FUN_0024fb45(param_1,0,lVar2,"synthetic:attached");
    FUN_00268474(param_1,param_2,*(undefined8 *)(param_3 + 6),param_4);
  }
  return;
}


// ===== 00268589 FUN_00268589 =====

void FUN_00268589(undefined8 param_1,long param_2,int param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  uint local_c;
  
  puVar4 = (uint *)(param_2 + (long)param_3 * 0x50 + 0x30);
  uVar1 = puVar4[4];
  iVar2 = FUN_00265b39(uVar1);
  if ((iVar2 == 0) && (uVar1 != 0xd)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc__obj_type_is_normal(type) || type == HWLOC_OBJ_NUMANODE",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                  ,0x3c2,"hwloc__look_synthetic");
  }
  if (uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("type != HWLOC_OBJ_MACHINE",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                  ,0x3c3,"hwloc__look_synthetic");
  }
  uVar3 = FUN_0026840b(puVar4 + 10,uVar1);
  uVar5 = FUN_00260eab();
  if (*puVar4 == 0) {
    FUN_0026197d(uVar5,uVar3);
  }
  else {
    for (local_c = 0; local_c < *puVar4; local_c = local_c + 1) {
      FUN_00268589(param_1,param_2,param_3 + 1,uVar5);
    }
  }
  FUN_00262517(param_4,param_4,uVar5);
  iVar2 = FUN_00265aac(param_1,uVar1);
  if (iVar2 != 0) {
    lVar6 = FUN_0024febd(param_1,uVar1,uVar3);
    uVar7 = FUN_002611e2(uVar5);
    *(undefined8 *)(lVar6 + 0xb8) = uVar7;
    if (uVar1 == 0xd) {
      uVar7 = FUN_00260eab();
      *(undefined8 *)(lVar6 + 200) = uVar7;
      FUN_0026197d(*(undefined8 *)(lVar6 + 200),uVar3);
    }
    FUN_002682a8(puVar4 + 4,lVar6);
    FUN_0024fb45(param_1,0,lVar6,"synthetic");
  }
  FUN_00268474(param_1,param_2,*(undefined8 *)(puVar4 + 0x12),uVar5);
  FUN_00260f71(uVar5);
  return;
}


// ===== 0026878b FUN_0026878b =====

undefined8 FUN_0026878b(long param_1,int *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  uint local_c;
  
  lVar1 = *(long *)(param_1 + 8);
  puVar2 = *(undefined8 **)(param_1 + 0x38);
  uVar3 = FUN_00260eab();
  if (*param_2 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("dstatus->phase == HWLOC_DISC_PHASE_GLOBAL",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                  ,0x3f0,"hwloc_look_synthetic");
  }
  if (*(long *)(*(long *)**(undefined8 **)(lVar1 + 0x18) + 0xb8) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!topology->levels[0][0]->cpuset",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-synthetic.c"
                  ,0x3f2,"hwloc_look_synthetic");
  }
  FUN_002531e1(*(undefined8 *)**(undefined8 **)(lVar1 + 0x18));
  **(undefined1 **)(lVar1 + 0x288) = 1;
  *(undefined1 *)(*(long *)(lVar1 + 0x288) + 1) = 1;
  *(undefined1 *)(*(long *)(lVar1 + 0x288) + 2) = 1;
  local_c = 0;
  while (*(int *)(puVar2 + (ulong)local_c * 10 + 6) != 0) {
    *(undefined4 *)(puVar2 + (ulong)local_c * 10 + 0xe) = 0;
    local_c = local_c + 1;
  }
  *(undefined4 *)(puVar2 + 5) = 0;
  *(undefined4 *)(puVar2 + (ulong)local_c * 10 + 0xe) = 0;
  **(undefined4 **)**(undefined8 **)(lVar1 + 0x18) = *(undefined4 *)(puVar2 + 8);
  FUN_002682a8(puVar2 + 8,*(undefined8 *)**(undefined8 **)(lVar1 + 0x18));
  for (local_c = 0; local_c < *(uint *)(puVar2 + 6); local_c = local_c + 1) {
    FUN_00268589(lVar1,puVar2,1,uVar3);
  }
  FUN_00268474(lVar1,puVar2,puVar2[0xf],uVar3);
  FUN_00260f71(uVar3);
  FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(lVar1 + 0x18),"Backend","Synthetic");
  FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(lVar1 + 0x18),"SyntheticDescription",*puVar2);
  return 0;
}


// ===== 002689c3 FUN_002689c3 =====

void FUN_002689c3(long param_1)

{
  undefined8 *__ptr;
  
  __ptr = *(undefined8 **)(param_1 + 0x38);
  FUN_00266d83(__ptr);
  free((void *)*__ptr);
  free(__ptr);
  return;
}


// ===== 00268a05 FUN_00268a05 =====

void * FUN_00268a05(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  void *__ptr;
  void *__ptr_00;
  int *piVar2;
  char *local_48;
  
  local_48 = param_4;
  if ((param_4 == (char *)0x0) && (local_48 = getenv("HWLOC_SYNTHETIC"), local_48 == (char *)0x0)) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
  }
  else {
    __ptr = (void *)FUN_0025f967(param_1,param_2);
    if (__ptr != (void *)0x0) {
      __ptr_00 = malloc(0x2830);
      if (__ptr_00 == (void *)0x0) {
        piVar2 = __errno_location();
        *piVar2 = 0xc;
      }
      else {
        iVar1 = FUN_00266e36(__ptr_00,local_48);
        if (-1 < iVar1) {
          *(void **)((long)__ptr + 0x38) = __ptr_00;
          *(code **)((long)__ptr + 0x48) = FUN_0026878b;
          *(code **)((long)__ptr + 0x40) = FUN_002689c3;
          *(undefined4 *)((long)__ptr + 0x30) = 0;
          return __ptr;
        }
        free(__ptr_00);
      }
      free(__ptr);
    }
  }
  return (void *)0x0;
}


// ===== 00268b1a FUN_00268b1a =====

undefined8 FUN_00268b1a(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else if (iVar1 == -2) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00258070(param_1,iVar1);
  }
  return uVar2;
}


// ===== 00268b6a FUN_00268b6a =====

void FUN_00268b6a(undefined8 param_1)

{
  FUN_002580d2(param_1,0,0);
  return;
}


// ===== 00268b8e FUN_00268b8e =====

undefined8 FUN_00268b8e(long param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0xe0) <= local_c) {
      return 0;
    }
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0xd8) + (ulong)local_c * 0x10);
    iVar1 = strcmp((char *)*puVar2,param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return puVar2[1];
}


// ===== 00268bfe FUN_00268bfe =====

undefined8 FUN_00268bfe(uint param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = param_1 >> 8;
  if ((((((uVar1 == 3) || (uVar1 == 2)) || (uVar1 == 1)) || ((uVar1 == 0 || (uVar1 == 0xb)))) ||
      ((param_1 == 0xc04 || ((param_1 == 0xc06 || (param_1 == 0x502)))))) ||
     ((uVar1 == 6 || (uVar1 == 0x12)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00268c61 FUN_00268c61 =====

bool FUN_00268c61(int param_1)

{
  return param_1 != 4;
}


// ===== 00268c74 FUN_00268c74 =====

bool FUN_00268c74(undefined8 param_1,undefined4 param_2)

{
  int local_c;
  
  local_c = 1;
  FUN_002543c3(param_1,param_2,&local_c);
  if (local_c == 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("filter != HWLOC_TYPE_FILTER_KEEP_IMPORTANT",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/plugins.h"
                  ,0x218,"hwloc_filter_check_keep_object_type");
  }
  return local_c != 1;
}


// ===== 00268cd4 FUN_00268cd4 =====

undefined8 FUN_00268cd4(undefined8 param_1,int *param_2)

{
  undefined8 uVar1;
  int local_10;
  int local_c;
  
  local_c = *param_2;
  local_10 = 1;
  FUN_002543c3(param_1,local_c,&local_10);
  if (local_10 == 1) {
    return 0;
  }
  if (local_10 == 3) {
    if (local_c == 0xf) {
      uVar1 = FUN_00268bfe(*(undefined2 *)(*(long *)(param_2 + 10) + 6));
      return uVar1;
    }
    if (local_c == 0x10) {
      uVar1 = FUN_00268c61(**(undefined4 **)(param_2 + 10));
      return uVar1;
    }
  }
  return 1;
}


// ===== 00268d5e FUN_00268d5e =====

int FUN_00268d5e(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 2) {
    if ((param_1 == 0) || (3 < param_1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = param_1 + 8;
    }
  }
  else if ((param_1 == 0) || (5 < param_1)) {
    iVar1 = -1;
  }
  else {
    iVar1 = param_1 + 3;
  }
  return iVar1;
}


// ===== 00268da4 FUN_00268da4 =====

undefined8 FUN_00268da4(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xd) || (param_1 == 0x13)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00268dc5 FUN_00268dc5 =====

undefined8 FUN_00268dc5(int param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0xd) || (param_1 == 0x12)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00268de6 FUN_00268de6 =====

undefined8 FUN_00268de6(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xe) || (0x11 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00268e07 FUN_00268e07 =====

undefined8 FUN_00268e07(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xe) || (0x10 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00268e28 FUN_00268e28 =====

undefined8 FUN_00268e28(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 4) || (0xb < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00268e49 FUN_00268e49 =====

int FUN_00268e49(void)

{
  char *__nptr;
  
  if (DAT_01218370 == 0) {
    __nptr = getenv("HWLOC_XML_VERBOSE");
    if (__nptr != (char *)0x0) {
      DAT_01218374 = atoi(__nptr);
    }
    DAT_01218370 = 1;
  }
  return DAT_01218374;
}


// ===== 00268e96 FUN_00268e96 =====

uint FUN_00268e96(void)

{
  int iVar1;
  char *pcVar2;
  
  if (DAT_01218378 == 0) {
    pcVar2 = getenv("HWLOC_LIBXML");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = getenv("HWLOC_LIBXML_IMPORT");
      if (pcVar2 != (char *)0x0) {
        iVar1 = atoi(pcVar2);
        DAT_0121837c = (uint)(iVar1 == 0);
      }
    }
    else {
      iVar1 = atoi(pcVar2);
      DAT_0121837c = (uint)(iVar1 == 0);
    }
    DAT_01218378 = 1;
  }
  return DAT_0121837c;
}


// ===== 00268f1e FUN_00268f1e =====

void FUN_00268f1e(long *param_1)

{
  if (DAT_01218360 == 0) {
    DAT_01218360 = *param_1;
  }
  if (DAT_01218368 == 0) {
    DAT_01218368 = param_1[1];
  }
  return;
}


// ===== 00268f5e FUN_00268f5e =====

void FUN_00268f5e(void)

{
  DAT_01218360 = 0;
  DAT_01218368 = 0;
  return;
}


// ===== 00268f7b FUN_00268f7b =====

void FUN_00268f7b(long param_1,long param_2,int *param_3,char *param_4,char *param_5,long param_6,
                 undefined4 *param_7)

{
  int iVar1;
  ulong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  void *pvVar6;
  double dVar7;
  undefined4 local_b8;
  undefined1 local_b4 [4];
  undefined1 local_b0 [4];
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [4];
  undefined2 local_9c [2];
  undefined2 local_98 [2];
  undefined2 local_94 [2];
  undefined2 local_90 [2];
  undefined2 local_8c [2];
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [4];
  uint local_7c;
  ulonglong local_78;
  ulong local_70;
  int local_64;
  ulong local_60;
  ulonglong local_58;
  ulong local_50;
  ulong local_48;
  ulong local_40;
  ulong local_38;
  ulonglong local_30;
  long local_28;
  ulong local_20;
  long local_18;
  ulong local_10;
  
  iVar1 = strcmp(param_4,"type");
  if (iVar1 != 0) {
    iVar1 = strcmp(param_4,"os_index");
    if (iVar1 == 0) {
      uVar2 = strtoul(param_5,(char **)0x0,10);
      param_3[4] = (int)uVar2;
    }
    else {
      iVar1 = strcmp(param_4,"gp_index");
      if (iVar1 == 0) {
        uVar3 = strtoull(param_5,(char **)0x0,10);
        *(ulonglong *)(param_3 + 0x3c) = uVar3;
        if ((*(long *)(param_3 + 0x3c) == 0) && (iVar1 = FUN_00268e49(), iVar1 != 0)) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "%s: unexpected zero gp_index, topology may be invalid\n",
                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
        }
        if (*(ulong *)(param_1 + 0xe0) <= *(ulong *)(param_3 + 0x3c)) {
          *(long *)(param_1 + 0xe0) = *(long *)(param_3 + 0x3c) + 1;
        }
      }
      else {
        iVar1 = strcmp(param_4,"id");
        if (iVar1 == 0) {
          iVar1 = strncmp(param_5,"obj",3);
          if (iVar1 == 0) {
            uVar3 = strtoull(param_5 + 3,(char **)0x0,10);
            *(ulonglong *)(param_3 + 0x3c) = uVar3;
            if ((*(long *)(param_3 + 0x3c) == 0) && (iVar1 = FUN_00268e49(), iVar1 != 0)) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "%s: unexpected zero id, topology may be invalid\n",
                      *(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
            }
            if (*(ulong *)(param_1 + 0xe0) <= *(ulong *)(param_3 + 0x3c)) {
              *(long *)(param_1 + 0xe0) = *(long *)(param_3 + 0x3c) + 1;
            }
          }
          else {
            iVar1 = FUN_00268e49();
            if (iVar1 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "%s: unexpected id `%s\' not-starting with `obj\', ignoring\n",
                      *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),param_5);
            }
          }
        }
        else {
          iVar1 = strcmp(param_4,"cpuset");
          if (iVar1 == 0) {
            if (*(long *)(param_3 + 0x2e) == 0) {
              uVar4 = FUN_00260eab();
              *(undefined8 *)(param_3 + 0x2e) = uVar4;
            }
            FUN_002615d6(*(undefined8 *)(param_3 + 0x2e),param_5);
          }
          else {
            iVar1 = strcmp(param_4,"complete_cpuset");
            if (iVar1 == 0) {
              if (*(long *)(param_3 + 0x30) == 0) {
                uVar4 = FUN_00260eab();
                *(undefined8 *)(param_3 + 0x30) = uVar4;
              }
              FUN_002615d6(*(undefined8 *)(param_3 + 0x30),param_5);
            }
            else {
              iVar1 = strcmp(param_4,"allowed_cpuset");
              if (iVar1 == 0) {
                if (*(long *)(param_3 + 0x12) == 0) {
                  FUN_002615d6(*(undefined8 *)(param_1 + 0x1b8),param_5);
                }
              }
              else {
                iVar1 = strcmp(param_4,"nodeset");
                if (iVar1 == 0) {
                  if (*(long *)(param_3 + 0x32) == 0) {
                    uVar4 = FUN_00260eab();
                    *(undefined8 *)(param_3 + 0x32) = uVar4;
                  }
                  FUN_002615d6(*(undefined8 *)(param_3 + 0x32),param_5);
                }
                else {
                  iVar1 = strcmp(param_4,"complete_nodeset");
                  if (iVar1 == 0) {
                    if (*(long *)(param_3 + 0x34) == 0) {
                      uVar4 = FUN_00260eab();
                      *(undefined8 *)(param_3 + 0x34) = uVar4;
                    }
                    FUN_002615d6(*(undefined8 *)(param_3 + 0x34),param_5);
                  }
                  else {
                    iVar1 = strcmp(param_4,"allowed_nodeset");
                    if (iVar1 == 0) {
                      if (*(long *)(param_3 + 0x12) == 0) {
                        FUN_002615d6(*(undefined8 *)(param_1 + 0x1c0),param_5);
                      }
                    }
                    else {
                      iVar1 = strcmp(param_4,"name");
                      if (iVar1 == 0) {
                        if (*(long *)(param_3 + 6) != 0) {
                          free(*(void **)(param_3 + 6));
                        }
                        pcVar5 = strdup(param_5);
                        *(char **)(param_3 + 6) = pcVar5;
                      }
                      else {
                        iVar1 = strcmp(param_4,"subtype");
                        if (iVar1 == 0) {
                          if (*(long *)(param_3 + 2) != 0) {
                            free(*(void **)(param_3 + 2));
                          }
                          pcVar5 = strdup(param_5);
                          *(char **)(param_3 + 2) = pcVar5;
                        }
                        else {
                          iVar1 = strcmp(param_4,"cache_size");
                          if (iVar1 == 0) {
                            local_78 = strtoull(param_5,(char **)0x0,10);
                            iVar1 = FUN_00268e28(*param_3);
                            if (((iVar1 == 0) && (*param_3 != 0x15)) && (*param_3 != 0x12)) {
                              iVar1 = FUN_00268e49();
                              if (iVar1 != 0) {
                                fprintf(*(FILE **)PTR_stderr_0032efe0,
                                        "%s: ignoring cache_size attribute for non-cache object type\n"
                                        ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                              }
                            }
                            else {
                              **(ulonglong **)(param_3 + 10) = local_78;
                            }
                          }
                          else {
                            iVar1 = strcmp(param_4,"cache_linesize");
                            if (iVar1 == 0) {
                              local_70 = strtoul(param_5,(char **)0x0,10);
                              iVar1 = FUN_00268e28(*param_3);
                              if (((iVar1 == 0) && (*param_3 != 0x15)) && (*param_3 != 0x12)) {
                                iVar1 = FUN_00268e49();
                                if (iVar1 != 0) {
                                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                                          "%s: ignoring cache_linesize attribute for non-cache object type\n"
                                          ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                }
                              }
                              else {
                                *(int *)(*(long *)(param_3 + 10) + 0xc) = (int)local_70;
                              }
                            }
                            else {
                              iVar1 = strcmp(param_4,"cache_associativity");
                              if (iVar1 == 0) {
                                local_64 = atoi(param_5);
                                iVar1 = FUN_00268e28(*param_3);
                                if (((iVar1 == 0) && (*param_3 != 0x15)) && (*param_3 != 0x12)) {
                                  iVar1 = FUN_00268e49();
                                  if (iVar1 != 0) {
                                    fprintf(*(FILE **)PTR_stderr_0032efe0,
                                            "%s: ignoring cache_associativity attribute for non-cache object type\n"
                                            ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                  }
                                }
                                else {
                                  *(int *)(*(long *)(param_3 + 10) + 0x10) = local_64;
                                }
                              }
                              else {
                                iVar1 = strcmp(param_4,"cache_type");
                                if (iVar1 == 0) {
                                  local_60 = strtoul(param_5,(char **)0x0,10);
                                  iVar1 = FUN_00268e28(*param_3);
                                  if (((iVar1 == 0) && (*param_3 != 0x15)) && (*param_3 != 0x12)) {
                                    iVar1 = FUN_00268e49();
                                    if (iVar1 != 0) {
                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                              "%s: ignoring cache_type attribute for non-cache object type\n"
                                              ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                    }
                                  }
                                  else if (((local_60 == 0) || (local_60 == 1)) || (local_60 == 2))
                                  {
                                    *(int *)(*(long *)(param_3 + 10) + 0x14) = (int)local_60;
                                  }
                                  else {
                                    iVar1 = FUN_00268e49();
                                    if (iVar1 != 0) {
                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                              "%s: ignoring invalid cache_type attribute %lu\n",
                                              *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                              local_60);
                                    }
                                  }
                                }
                                else {
                                  iVar1 = strcmp(param_4,"local_memory");
                                  if (iVar1 == 0) {
                                    local_58 = strtoull(param_5,(char **)0x0,10);
                                    if (*param_3 == 0xd) {
                                      **(ulonglong **)(param_3 + 10) = local_58;
                                    }
                                    else if (*(long *)(param_3 + 0x12) == 0) {
                                      *(ulonglong *)(param_1 + 0x338) = local_58;
                                    }
                                    else {
                                      iVar1 = FUN_00268e49();
                                      if (iVar1 != 0) {
                                        fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                "%s: ignoring local_memory attribute for non-NUMAnode non-root object\n"
                                                ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                      }
                                    }
                                  }
                                  else {
                                    iVar1 = strcmp(param_4,"depth");
                                    if (iVar1 == 0) {
                                      local_50 = strtoul(param_5,(char **)0x0,10);
                                      iVar1 = FUN_00268e28(*param_3);
                                      if (((iVar1 == 0) && (*param_3 != 0x15)) && (*param_3 != 0x12)
                                         ) {
                                        if (((*param_3 != 0xc) && (*param_3 != 0xe)) &&
                                           (iVar1 = FUN_00268e49(), iVar1 != 0)) {
                                          fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                  "%s: ignoring depth attribute for object type without depth\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                        }
                                      }
                                      else {
                                        *(int *)(*(long *)(param_3 + 10) + 8) = (int)local_50;
                                      }
                                    }
                                    else {
                                      iVar1 = strcmp(param_4,"kind");
                                      if (iVar1 == 0) {
                                        local_48 = strtoul(param_5,(char **)0x0,10);
                                        if (*param_3 == 0xc) {
                                          *(int *)(*(long *)(param_3 + 10) + 4) = (int)local_48;
                                        }
                                        else {
                                          iVar1 = FUN_00268e49();
                                          if (iVar1 != 0) {
                                            fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                        
                                                  "%s: ignoring kind attribute for non-group object type\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                          }
                                        }
                                      }
                                      else {
                                        iVar1 = strcmp(param_4,"subkind");
                                        if (iVar1 == 0) {
                                          local_40 = strtoul(param_5,(char **)0x0,10);
                                          if (*param_3 == 0xc) {
                                            *(int *)(*(long *)(param_3 + 10) + 8) = (int)local_40;
                                          }
                                          else {
                                            iVar1 = FUN_00268e49();
                                            if (iVar1 != 0) {
                                              fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                            
                                                  "%s: ignoring subkind attribute for non-group object type\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                            }
                                          }
                                        }
                                        else {
                                          iVar1 = strcmp(param_4,"dont_merge");
                                          if (iVar1 == 0) {
                                            local_38 = strtoul(param_5,(char **)0x0,10);
                                            if (*param_3 == 0xc) {
                                              *(char *)(*(long *)(param_3 + 10) + 0xc) =
                                                   (char)local_38;
                                            }
                                            else {
                                              iVar1 = FUN_00268e49();
                                              if (iVar1 != 0) {
                                                fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                
                                                  "%s: ignoring dont_merge attribute for non-group object type\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                              }
                                            }
                                          }
                                          else {
                                            iVar1 = strcmp(param_4,"pci_busid");
                                            if (iVar1 == 0) {
                                              if (*param_3 - 0xeU < 2) {
                                                iVar1 = sscanf(param_5,"%x:%02x:%02x.%01x",&local_7c
                                                               ,local_80,local_84,local_88);
                                                if (iVar1 == 4) {
                                                  if (local_7c < 0x10000) {
                                                    **(undefined2 **)(param_3 + 10) =
                                                         (short)local_7c;
                                                    *(undefined1 *)(*(long *)(param_3 + 10) + 2) =
                                                         local_80[0];
                                                    *(undefined1 *)(*(long *)(param_3 + 10) + 3) =
                                                         local_84[0];
                                                    *(undefined1 *)(*(long *)(param_3 + 10) + 4) =
                                                         local_88[0];
                                                  }
                                                  else {
                                                    if ((DAT_01218380 == 0) &&
                                                       (iVar1 = FUN_0024d64f(), iVar1 == 0)) {
                                                      fwrite(
                                                  "hwloc/xml: Ignoring PCI device with non-16bit domain.\nPass --enable-32bits-pci-domain to configure to support such devices\n(warning: it would break the library ABI, don\'t enable unless really needed).\n"
                                                  ,1,0xc9,*(FILE **)PTR_stderr_0032efe0);
                                                  }
                                                  DAT_01218380 = 1;
                                                  *param_7 = 1;
                                                  }
                                                }
                                                else {
                                                  iVar1 = FUN_00268e49();
                                                  if (iVar1 != 0) {
                                                    fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                        
                                                  "%s: ignoring invalid pci_busid format string %s\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                                  param_5);
                                                  }
                                                  *param_7 = 1;
                                                }
                                              }
                                              else {
                                                iVar1 = FUN_00268e49();
                                                if (iVar1 != 0) {
                                                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                    
                                                  "%s: ignoring pci_busid attribute for non-PCI object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                }
                                              }
                                            }
                                            else {
                                              iVar1 = strcmp(param_4,"pci_type");
                                              if (iVar1 == 0) {
                                                if (*param_3 - 0xeU < 2) {
                                                  iVar1 = sscanf(param_5,
                                                  "%x [%04x:%04x] [%04x:%04x] %02x",local_8c,
                                                  local_90,local_94,local_98,local_9c,local_a0);
                                                  if (iVar1 == 6) {
                                                    *(undefined2 *)(*(long *)(param_3 + 10) + 6) =
                                                         local_8c[0];
                                                    *(undefined2 *)(*(long *)(param_3 + 10) + 8) =
                                                         local_90[0];
                                                    *(undefined2 *)(*(long *)(param_3 + 10) + 10) =
                                                         local_94[0];
                                                    *(undefined2 *)(*(long *)(param_3 + 10) + 0xc) =
                                                         local_98[0];
                                                    *(undefined2 *)(*(long *)(param_3 + 10) + 0xe) =
                                                         local_9c[0];
                                                    *(undefined1 *)(*(long *)(param_3 + 10) + 0x10)
                                                         = local_a0[0];
                                                  }
                                                  else {
                                                    iVar1 = FUN_00268e49();
                                                    if (iVar1 != 0) {
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring invalid pci_type format string %s\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                                  param_5);
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar1 = FUN_00268e49();
                                                  if (iVar1 != 0) {
                                                    fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                        
                                                  "%s: ignoring pci_type attribute for non-PCI object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  }
                                                }
                                              }
                                              else {
                                                iVar1 = strcmp(param_4,"pci_link_speed");
                                                if (iVar1 == 0) {
                                                  if (*param_3 - 0xeU < 2) {
                                                    dVar7 = atof(param_5);
                                                    *(float *)(*(long *)(param_3 + 10) + 0x14) =
                                                         (float)dVar7;
                                                  }
                                                  else {
                                                    iVar1 = FUN_00268e49();
                                                    if (iVar1 != 0) {
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring pci_link_speed attribute for non-PCI object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar1 = strcmp(param_4,"bridge_type");
                                                  if (iVar1 == 0) {
                                                    if (*param_3 == 0xe) {
                                                      iVar1 = sscanf(param_5,"%u-%u",&local_a4,
                                                                     &local_a8);
                                                      if (iVar1 == 2) {
                                                        *(undefined4 *)
                                                         (*(long *)(param_3 + 10) + 0x18) = local_a4
                                                        ;
                                                        *(undefined4 *)
                                                         (*(long *)(param_3 + 10) + 0x20) = local_a8
                                                        ;
                                                      }
                                                      else {
                                                        iVar1 = FUN_00268e49();
                                                        if (iVar1 != 0) {
                                                          fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                                    
                                                  "%s: ignoring invalid bridge_type format string %s\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                                  param_5);
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = FUN_00268e49();
                                                    if (iVar1 != 0) {
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring bridge_type attribute for non-bridge object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = strcmp(param_4,"bridge_pci");
                                                    if (iVar1 == 0) {
                                                      if (*param_3 == 0xe) {
                                                        iVar1 = sscanf(param_5,"%x:[%02x-%02x]",
                                                                       &local_ac,local_b0,local_b4);
                                                        if (iVar1 == 3) {
                                                          if (local_ac < 0x10000) {
                                                            *(short *)(*(long *)(param_3 + 10) +
                                                                      0x1c) = (short)local_ac;
                                                            *(undefined1 *)
                                                             (*(long *)(param_3 + 10) + 0x1e) =
                                                                 local_b0[0];
                                                            *(undefined1 *)
                                                             (*(long *)(param_3 + 10) + 0x1f) =
                                                                 local_b4[0];
                                                          }
                                                          else {
                                                            if ((DAT_01218384 == 0) &&
                                                               (iVar1 = FUN_0024d64f(), iVar1 == 0))
                                                            {
                                                              fwrite(
                                                  "hwloc/xml: Ignoring bridge to PCI with non-16bit domain.\nPass --enable-32bits-pci-domain to configure to support such devices\n(warning: it would break the library ABI, don\'t enable unless really needed).\n"
                                                  ,1,0xcc,*(FILE **)PTR_stderr_0032efe0);
                                                  }
                                                  DAT_01218384 = 1;
                                                  *param_7 = 1;
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = FUN_00268e49();
                                                    if (iVar1 != 0) {
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring invalid bridge_pci format string %s\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                                  param_5);
                                                  }
                                                  *param_7 = 1;
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = FUN_00268e49();
                                                    if (iVar1 != 0) {
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring bridge_pci attribute for non-bridge object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = strcmp(param_4,"osdev_type");
                                                    if (iVar1 == 0) {
                                                      if (*param_3 == 0x10) {
                                                        iVar1 = sscanf(param_5,"%u",&local_b8);
                                                        if (iVar1 == 1) {
                                                          **(undefined4 **)(param_3 + 10) = local_b8
                                                          ;
                                                        }
                                                        else {
                                                          iVar1 = FUN_00268e49();
                                                          if (iVar1 != 0) {
                                                            fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                                        
                                                  "%s: ignoring invalid osdev_type format string %s\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                                  param_5);
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar1 = FUN_00268e49();
                                                    if (iVar1 != 0) {
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring osdev_type attribute for non-osdev object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    if (*(uint *)(param_2 + 0x58) < 2) {
                                                      iVar1 = strcmp(param_4,"os_level");
                                                      if (iVar1 == 0) {
                                                        return;
                                                      }
                                                      iVar1 = strcmp(param_4,"online_cpuset");
                                                      if (iVar1 == 0) {
                                                        return;
                                                      }
                                                      iVar1 = strcmp(param_4,"dmi_board_vendor");
                                                      if (iVar1 == 0) {
                                                        if (*param_5 == '\0') {
                                                          return;
                                                        }
                                                        FUN_0024dfb5(param_3,"DMIBoardVendor",
                                                                     param_5);
                                                        return;
                                                      }
                                                      iVar1 = strcmp(param_4,"dmi_board_name");
                                                      if (iVar1 == 0) {
                                                        if (*param_5 == '\0') {
                                                          return;
                                                        }
                                                        FUN_0024dfb5(param_3,"DMIBoardName",param_5)
                                                        ;
                                                        return;
                                                      }
                                                      if (*(int *)(param_2 + 0x58) == 0) {
                                                        iVar1 = strcmp(param_4,"memory_kB");
                                                        if (iVar1 == 0) {
                                                          local_30 = strtoull(param_5,(char **)0x0,
                                                                              10);
                                                          if (*param_3 == 0x15) {
                                                            **(long **)(param_3 + 10) =
                                                                 local_30 << 10;
                                                            return;
                                                          }
                                                          if (*param_3 == 0xd) {
                                                            **(long **)(param_3 + 10) =
                                                                 local_30 << 10;
                                                            return;
                                                          }
                                                          if (*(long *)(param_3 + 0x12) == 0) {
                                                            *(ulonglong *)(param_1 + 0x338) =
                                                                 local_30 << 10;
                                                            return;
                                                          }
                                                          iVar1 = FUN_00268e49();
                                                          if (iVar1 == 0) {
                                                            return;
                                                          }
                                                          fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                                    
                                                  "%s: ignoring memory_kB attribute for non-NUMAnode non-root object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  return;
                                                  }
                                                  iVar1 = strcmp(param_4,"huge_page_size_kB");
                                                  if (iVar1 == 0) {
                                                    local_20 = strtoul(param_5,(char **)0x0,10);
                                                    if ((*param_3 != 0xd) &&
                                                       (*(long *)(param_3 + 0x12) != 0)) {
                                                      iVar1 = FUN_00268e49();
                                                      if (iVar1 == 0) {
                                                        return;
                                                      }
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring huge_page_size_kB attribute for non-NUMAnode non-root object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  return;
                                                  }
                                                  if (*param_3 == 0xd) {
                                                    local_28 = *(long *)(param_3 + 10);
                                                  }
                                                  else {
                                                    local_28 = param_1 + 0x338;
                                                  }
                                                  if (*(long *)(local_28 + 0x10) == 0) {
                                                    pvVar6 = malloc(0x10);
                                                    *(void **)(local_28 + 0x10) = pvVar6;
                                                    *(undefined4 *)(local_28 + 8) = 1;
                                                  }
                                                  if (*(long *)(local_28 + 0x10) != 0) {
                                                    **(long **)(local_28 + 0x10) = local_20 << 10;
                                                    return;
                                                  }
                    /* WARNING: Subroutine does not return */
                                                  __assert_fail("memory->page_types",
                                                                                                                                
                                                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                                                  ,0x1ce,"hwloc__xml_import_object_attr");
                                                  }
                                                  iVar1 = strcmp(param_4,"huge_page_free");
                                                  if (iVar1 == 0) {
                                                    local_10 = strtoul(param_5,(char **)0x0,10);
                                                    if ((*param_3 != 0xd) &&
                                                       (*(long *)(param_3 + 0x12) != 0)) {
                                                      iVar1 = FUN_00268e49();
                                                      if (iVar1 == 0) {
                                                        return;
                                                      }
                                                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                            
                                                  "%s: ignoring huge_page_free attribute for non-NUMAnode non-root object\n"
                                                  ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
                                                  return;
                                                  }
                                                  if (*param_3 == 0xd) {
                                                    local_18 = *(long *)(param_3 + 10);
                                                  }
                                                  else {
                                                    local_18 = param_1 + 0x338;
                                                  }
                                                  if (*(long *)(local_18 + 0x10) == 0) {
                                                    pvVar6 = malloc(0x10);
                                                    *(void **)(local_18 + 0x10) = pvVar6;
                                                    *(undefined4 *)(local_18 + 8) = 1;
                                                  }
                                                  if (*(long *)(local_18 + 0x10) != 0) {
                                                    *(ulong *)(*(long *)(local_18 + 0x10) + 8) =
                                                         local_10;
                                                    return;
                                                  }
                    /* WARNING: Subroutine does not return */
                                                  __assert_fail("memory->page_types",
                                                                                                                                
                                                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                                                  ,0x1dd,"hwloc__xml_import_object_attr");
                                                  }
                                                  }
                                                  }
                                                  iVar1 = FUN_00268e49();
                                                  if (iVar1 != 0) {
                                                    fprintf(*(FILE **)PTR_stderr_0032efe0,
                                                                                                                        
                                                  "%s: ignoring unknown object attribute %s\n",
                                                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),
                                                  param_4);
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
  return;
}


// ===== 0026a833 FUN_0026a833 =====

undefined8 FUN_0026a833(undefined8 *param_1,undefined8 *param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = 0;
  while( true ) {
    while( true ) {
      iVar1 = (**(code **)(*(long *)(param_3 + 8) + 0x18))(param_3,&local_20,&local_28);
      if (iVar1 < 0) {
        *param_1 = local_10;
        *param_2 = local_18;
        uVar2 = (**(code **)(*(long *)(param_3 + 8) + 0x28))(param_3);
        return uVar2;
      }
      iVar1 = strcmp(local_20,"name");
      if (iVar1 != 0) break;
      local_10 = local_28;
    }
    iVar1 = strcmp(local_20,"value");
    if (iVar1 != 0) break;
    local_18 = local_28;
  }
  return 0xffffffff;
}


// ===== 0026a8f1 FUN_0026a8f1 =====

int FUN_0026a8f1(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  char *local_20;
  char *local_18;
  int local_c;
  
  local_18 = (char *)0x0;
  local_20 = (char *)0x0;
  local_c = FUN_0026a833(&local_18,&local_20,param_3);
  if ((-1 < local_c) && (local_18 != (char *)0x0)) {
    if ((*(uint *)(param_1 + 0x58) < 2) &&
       ((iVar1 = strcmp(local_18,"Type"), iVar1 == 0 ||
        (iVar1 = strcmp(local_18,"CoProcType"), iVar1 == 0)))) {
      if (local_20 != (char *)0x0) {
        if (*(long *)(param_2 + 8) != 0) {
          free(*(void **)(param_2 + 8));
        }
        pcVar2 = strdup(local_20);
        *(char **)(param_2 + 8) = pcVar2;
      }
    }
    else if (local_20 != (char *)0x0) {
      FUN_0024dfb5(param_2,local_18,local_20);
    }
  }
  return local_c;
}


// ===== 0026a9e8 FUN_0026a9e8 =====

undefined8 FUN_0026a9e8(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *local_38;
  char *local_30;
  void *local_28;
  uint local_1c;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = 0;
  local_18 = 0;
  while( true ) {
    while( true ) {
      iVar1 = (**(code **)(*(long *)(param_3 + 8) + 0x18))(param_3,&local_30,&local_38);
      if (iVar1 < 0) {
        if (local_10 != 0) {
          local_1c = *(uint *)(param_2 + 8);
          local_28 = realloc(*(void **)(param_2 + 0x10),(ulong)(local_1c + 1) << 4);
          if (local_28 != (void *)0x0) {
            *(void **)(param_2 + 0x10) = local_28;
            *(uint *)(param_2 + 8) = local_1c + 1;
            *(ulonglong *)((ulong)local_1c * 0x10 + *(long *)(param_2 + 0x10)) = local_10;
            *(ulonglong *)((ulong)local_1c * 0x10 + *(long *)(param_2 + 0x10) + 8) = local_18;
          }
        }
        uVar2 = (**(code **)(*(long *)(param_3 + 8) + 0x28))(param_3);
        return uVar2;
      }
      iVar1 = strcmp(local_30,"size");
      if (iVar1 != 0) break;
      local_10 = strtoull(local_38,(char **)0x0,10);
    }
    iVar1 = strcmp(local_30,"count");
    if (iVar1 != 0) break;
    local_18 = strtoull(local_38,(char **)0x0,10);
  }
  return 0xffffffff;
}


// ===== 0026ab46 FUN_0026ab46 =====

undefined8 FUN_0026ab46(long param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  double dVar3;
  undefined1 local_98 [56];
  char *local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  char *local_40;
  float local_38;
  int local_34;
  undefined8 *local_30;
  void *local_28;
  uint local_20;
  float local_1c;
  ulong local_18;
  ulong local_10;
  
  local_10 = 0;
  local_18 = 0;
  local_1c = 0.0;
  while (iVar1 = (**(code **)(*(long *)(param_3 + 8) + 0x18))(param_3,&local_48,&local_50),
        -1 < iVar1) {
    iVar1 = strcmp(local_48,"nbobjs");
    if (iVar1 == 0) {
      local_18 = strtoul(local_50,(char **)0x0,10);
    }
    else {
      iVar1 = strcmp(local_48,"relative_depth");
      if (iVar1 == 0) {
        local_10 = strtoul(local_50,(char **)0x0,10);
      }
      else {
        iVar1 = strcmp(local_48,"latency_base");
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        dVar3 = atof(local_50);
        local_1c = (float)dVar3;
      }
    }
  }
  if (((local_18 != 0) && (local_10 != 0)) && (local_1c != 0.0)) {
    local_28 = malloc(local_18 * local_18 * 4);
    local_30 = malloc(0x28);
    if ((local_28 == (void *)0x0) || (local_30 == (undefined8 *)0x0)) {
      iVar1 = FUN_00268e49();
      if (iVar1 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "%s: failed to allocate v1distance matrix for %lu objects\n",
                *(undefined8 *)(*(long *)(param_3 + 8) + 0x48),local_18);
      }
      free(local_30);
      free(local_28);
      return 0xffffffff;
    }
    *local_30 = 5;
    *(int *)(local_30 + 1) = (int)local_18;
    local_30[2] = local_28;
    for (local_20 = 0; (ulong)local_20 < local_18 * local_18; local_20 = local_20 + 1) {
      local_34 = (**(code **)(*(long *)(param_3 + 8) + 0x20))(param_3,local_98,&local_40);
      if ((local_34 < 1) || (iVar1 = strcmp(local_40,"latency"), iVar1 != 0)) {
        free(local_28);
        free(local_30);
        return 0xffffffff;
      }
      local_34 = (**(code **)(*(long *)(param_3 + 8) + 0x18))(local_98,&local_58,&local_60);
      if ((local_34 < 0) || (iVar1 = strcmp(local_58,"value"), iVar1 != 0)) {
        free(local_28);
        free(local_30);
        return 0xffffffff;
      }
      dVar3 = atof(local_60);
      local_38 = (float)dVar3;
      *(float *)((long)local_28 + (ulong)local_20 * 4) = local_38 * local_1c;
      local_34 = (**(code **)(*(long *)(param_3 + 8) + 0x28))(local_98);
      if (local_34 < 0) {
        free(local_28);
        free(local_30);
        return 0xffffffff;
      }
      (**(code **)(*(long *)(param_3 + 8) + 0x30))(local_98);
    }
    if (local_18 < 2) {
      if (local_18 != 1) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("nbobjs == 1",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                      ,0x2a1,"hwloc__xml_v1import_distances");
      }
      iVar1 = FUN_00268e49();
      if (iVar1 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "%s: ignoring invalid distance matrix with only 1 object\n",
                *(undefined8 *)(*(long *)(param_3 + 8) + 0x48));
      }
      free(local_28);
      free(local_30);
    }
    else if (*(long *)(param_2 + 0x48) == 0) {
      local_30[3] = *(undefined8 *)(param_1 + 0x80);
      local_30[4] = 0;
      if (*(long *)(param_1 + 0x80) == 0) {
        *(undefined8 **)(param_1 + 0x78) = local_30;
      }
      else {
        *(undefined8 **)(*(long *)(param_1 + 0x80) + 0x20) = local_30;
      }
      *(undefined8 **)(param_1 + 0x80) = local_30;
    }
    else {
      free(local_28);
      free(local_30);
    }
  }
  uVar2 = (**(code **)(*(long *)(param_3 + 8) + 0x28))(param_3);
  return uVar2;
}


// ===== 0026afef FUN_0026afef =====

undefined8 FUN_0026afef(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  size_t sVar2;
  char *__format;
  char *pcVar3;
  undefined8 uVar4;
  undefined *local_80;
  long local_78;
  undefined8 local_70;
  undefined1 local_68 [8];
  char *local_60;
  char *local_58;
  ulong local_50;
  char *local_48;
  ulong local_40;
  void *local_38;
  int local_2c;
  long local_28;
  char *local_20;
  uint local_14;
  ulong local_10;
  
  local_10 = 0;
  local_14 = 0;
  local_20 = (char *)0x0;
  while (iVar1 = (**(code **)(*(long *)(param_3 + 8) + 0x18))(param_3,&local_58,&local_60),
        -1 < iVar1) {
    iVar1 = strcmp(local_58,"length");
    if (iVar1 == 0) {
      local_10 = strtoul(local_60,(char **)0x0,10);
    }
    else {
      iVar1 = strcmp(local_58,"encoding");
      if (iVar1 == 0) {
        iVar1 = strcmp(local_60,"base64");
        local_14 = (uint)(iVar1 == 0);
      }
      else {
        iVar1 = strcmp(local_58,"name");
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        local_20 = local_60;
      }
    }
  }
  if (*(long *)(param_1 + 0x2b0) == 0) {
    local_50 = local_10;
    if (local_14 != 0) {
      local_50 = (local_10 + 2) / 3 << 2;
    }
    local_2c = (**(code **)(*(long *)(param_3 + 8) + 0x38))(param_3,local_68,local_50);
    if (local_2c < 0) {
      return 0xffffffff;
    }
  }
  else if (*(int *)(param_1 + 0x2b8) == 0) {
    if ((local_14 == 0) || (local_10 == 0)) {
      local_80 = &DAT_002efc1c;
      if ((local_10 != 0) &&
         (local_2c = (**(code **)(*(long *)(param_3 + 8) + 0x38))(param_3,&local_80,local_10),
         local_2c < 0)) {
        return 0xffffffff;
      }
      (**(code **)(param_1 + 0x2b0))(param_1,param_2,local_20,local_80,local_10);
    }
    else {
      local_28 = (local_10 + 2) / 3 << 2;
      local_2c = (**(code **)(*(long *)(param_3 + 8) + 0x38))(param_3,&local_78,local_28);
      if (local_2c < 0) {
        return 0xffffffff;
      }
      if (local_2c != 0) {
        local_38 = malloc(local_10 + 1);
        if (local_38 == (void *)0x0) {
          return 0xffffffff;
        }
        if (*(char *)(local_28 + local_78) != '\0') {
                    /* WARNING: Subroutine does not return */
          __assert_fail("encoded_buffer[encoded_length] == 0",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                        ,0x2f6,"hwloc__xml_import_userdata");
        }
        local_2c = FUN_0028d9af(local_78,local_38,local_10 + 1);
        if (local_2c != (int)local_10) {
          free(local_38);
          return 0xffffffff;
        }
        (**(code **)(param_1 + 0x2b0))(param_1,param_2,local_20,local_38,local_10);
        free(local_38);
      }
    }
  }
  else {
    local_40 = local_10;
    if (local_14 != 0) {
      local_40 = (local_10 + 2) / 3 << 2;
    }
    local_2c = (**(code **)(*(long *)(param_3 + 8) + 0x38))(param_3,&local_70,local_40);
    if (local_2c < 0) {
      return 0xffffffff;
    }
    if (local_20 == (char *)0x0) {
      sVar2 = 0xc;
    }
    else {
      sVar2 = strlen(local_20);
      sVar2 = sVar2 + 8;
    }
    local_48 = malloc(sVar2);
    if (local_48 == (char *)0x0) {
      return 0xffffffff;
    }
    if (local_20 == (char *)0x0) {
      pcVar3 = "anon";
      uVar4 = 0x2d;
    }
    else {
      uVar4 = 0x3a;
      pcVar3 = local_20;
    }
    if (local_14 == 0) {
      __format = "normal%c%s";
    }
    else {
      __format = "base64%c%s";
    }
    sprintf(local_48,__format,uVar4,pcVar3);
    (**(code **)(param_1 + 0x2b0))(param_1,param_2,local_48,local_70,local_10);
    free(local_48);
  }
  (**(code **)(*(long *)(param_3 + 8) + 0x40))(param_3);
  uVar4 = (**(code **)(*(long *)(param_3 + 8) + 0x28))(param_3);
  return uVar4;
}


// ===== 0026b49d FUN_0026b49d =====

void FUN_0026b49d(long param_1,long param_2,long param_3)

{
  undefined *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined1 local_c8 [64];
  undefined *local_88;
  undefined *local_80;
  undefined1 local_78 [72];
  void *local_30;
  void *local_28;
  char *local_20;
  char *local_18;
  char *local_10;
  
  local_10 = (char *)FUN_0026590a(param_1);
  local_18 = (char *)FUN_00268b8e(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"hwlocVersion");
  local_20 = (char *)FUN_00268b8e(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"ProcessName");
  local_80 = (undefined *)0x0;
  local_88 = (undefined *)0x0;
  FUN_00261562(&local_28,*(undefined8 *)(param_2 + 0xb8));
  FUN_00261562(&local_30,*(undefined8 *)(param_2 + 0xc0));
  FUN_00258b4a(local_78,0x40,param_2,0);
  if (*(long *)(param_3 + 0xb8) != 0) {
    FUN_00261562(&local_80,*(undefined8 *)(param_3 + 0xb8));
  }
  if (*(long *)(param_3 + 0xc0) != 0) {
    FUN_00261562(&local_88,*(undefined8 *)(param_3 + 0xc0));
  }
  FUN_00258b4a(local_c8,0x40,param_3,0);
  fwrite("****************************************************************************\n",1,0x4d,
         *(FILE **)PTR_stderr_0032efe0);
  fwrite("* hwloc has encountered an out-of-order XML topology load.\n",1,0x3b,
         *(FILE **)PTR_stderr_0032efe0);
  fprintf(*(FILE **)PTR_stderr_0032efe0,"* Object %s cpuset %s complete %s\n",local_78,local_28,
          local_30);
  puVar4 = local_88;
  if (local_88 == (undefined *)0x0) {
    puVar4 = &DAT_002efceb;
  }
  puVar1 = local_80;
  if (local_80 == (undefined *)0x0) {
    puVar1 = &DAT_002efceb;
  }
  fprintf(*(FILE **)PTR_stderr_0032efe0,"* was inserted after object %s with %s and %s.\n",local_c8,
          puVar1,puVar4);
  pcVar2 = local_10;
  if (local_10 == (char *)0x0) {
    pcVar2 = "<unknown>";
  }
  fprintf(*(FILE **)PTR_stderr_0032efe0,
          "* The error occured in hwloc %s inside process `%s\', while\n","2.9.2",pcVar2);
  if ((local_18 == (char *)0x0) && (local_20 == (char *)0x0)) {
    fwrite("* the input XML was generated by an unspecified ancient hwloc release.\n",1,0x47,
           *(FILE **)PTR_stderr_0032efe0);
  }
  else {
    pcVar2 = local_20;
    if (local_20 == (char *)0x0) {
      pcVar2 = "<unknown>";
    }
    pcVar3 = local_18;
    if (local_18 == (char *)0x0) {
      pcVar3 = "(unknown version)";
    }
    fprintf(*(FILE **)PTR_stderr_0032efe0,
            "* the input XML was generated by hwloc %s inside process `%s\'.\n",pcVar3,pcVar2);
  }
  fwrite("* Please check that your input topology XML file is valid.\n",1,0x3b,
         *(FILE **)PTR_stderr_0032efe0);
  fwrite("* Set HWLOC_DEBUG_CHECK=1 in the environment to detect further issues.\n",1,0x47,
         *(FILE **)PTR_stderr_0032efe0);
  fwrite("****************************************************************************\n",1,0x4d,
         *(FILE **)PTR_stderr_0032efe0);
  free(local_28);
  free(local_30);
  free(local_80);
  free(local_88);
  free(local_10);
  return;
}


// ===== 0026b826 FUN_0026b826 =====

undefined8
FUN_0026b826(long param_1,long param_2,int *param_3,int *param_4,undefined4 *param_5,long param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int *piVar7;
  int *local_d0;
  char *local_b8;
  char *local_b0;
  undefined1 local_a8 [48];
  char *local_78;
  int local_70;
  int local_6c;
  undefined8 *local_68;
  long local_60;
  int *local_58;
  int *local_50;
  long local_48;
  long local_40;
  long local_38;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_6c = 0;
  local_70 = 0;
  local_1c = 0;
  local_20 = 0;
  *(int **)(param_4 + 0x12) = param_3;
  while (iVar3 = (**(code **)(*(long *)(param_6 + 8) + 0x18))(param_6,&local_b0,&local_b8),
        local_d0 = param_3, -1 < iVar3) {
    iVar3 = strcmp(local_b0,"type");
    if (iVar3 == 0) {
      iVar3 = FUN_002584c0(local_b8,param_4,0,0);
      if (iVar3 < 0) {
        iVar3 = strcasecmp(local_b8,"Cache");
        if (iVar3 == 0) {
          *param_4 = 0x15;
          local_1c = 1;
        }
        else {
          iVar3 = strcasecmp(local_b8,"System");
          if (iVar3 == 0) {
            if (param_3 != (int *)0x0) {
              iVar3 = FUN_00268e49();
              if (iVar3 != 0) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "%s: obsolete System object only allowed at root\n",
                        *(undefined8 *)(*(long *)(param_6 + 8) + 0x48));
              }
              goto LAB_0026ce6b;
            }
            *param_4 = 0;
          }
          else {
            iVar3 = strcasecmp(local_b8,"Tile");
            if (iVar3 == 0) {
              *param_4 = 0xc;
              *(undefined4 *)(*(long *)(param_4 + 10) + 4) = 0x67;
            }
            else {
              iVar3 = strcasecmp(local_b8,"Module");
              if (iVar3 == 0) {
                *param_4 = 0xc;
                *(undefined4 *)(*(long *)(param_4 + 10) + 4) = 0x66;
              }
              else {
                iVar3 = strcasecmp(local_b8,"MemCache");
                if (iVar3 != 0) {
                  iVar3 = FUN_00268e49();
                  if (iVar3 != 0) {
                    fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: unrecognized object type string %s\n"
                            ,*(undefined8 *)(*(long *)(param_6 + 8) + 0x48),local_b8);
                  }
                  goto LAB_0026ce6b;
                }
                *param_4 = 0x16;
                local_6c = 1;
                iVar3 = FUN_00268e49();
                if (iVar3 != 0) {
                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                          "%s: %s object not-supported, will be ignored\n",
                          *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),local_b8);
                }
              }
            }
          }
        }
      }
    }
    else {
      if (*param_4 == -1) {
        iVar3 = FUN_00268e49();
        if (iVar3 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: object attribute %s found before type\n",
                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),local_b0);
        }
        goto LAB_0026ce6b;
      }
      FUN_00268f7b(param_1,param_2,param_4,local_b0,local_b8,param_6,&local_6c);
    }
  }
  while( true ) {
    local_78 = (char *)0x0;
    local_24 = (**(code **)(*(long *)(param_6 + 8) + 0x20))(param_6,local_a8,&local_78);
    if (local_24 < 0) {
      return 0xffffffff;
    }
    if ((local_24 == 0) || (iVar3 = strcmp(local_78,"object"), iVar3 == 0)) break;
    iVar3 = strcmp(local_78,"page_type");
    if (iVar3 == 0) {
      if (*param_4 == 0xd) {
        local_24 = FUN_0026a9e8(param_1,*(undefined8 *)(param_4 + 10),local_a8);
      }
      else if (param_3 == (int *)0x0) {
        local_24 = FUN_0026a9e8(param_1,param_1 + 0x338,local_a8);
      }
      else {
        iVar3 = FUN_00268e49();
        if (iVar3 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid non-NUMAnode object child %s\n",
                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),local_78);
        }
        local_24 = -1;
      }
    }
    else {
      iVar3 = strcmp(local_78,"info");
      if (iVar3 == 0) {
        local_24 = FUN_0026a8f1(param_2,param_4,local_a8);
      }
      else if ((*(uint *)(param_2 + 0x58) < 2) && (iVar3 = strcmp(local_78,"distances"), iVar3 == 0)
              ) {
        local_24 = FUN_0026ab46(param_2,param_4,local_a8);
      }
      else {
        iVar3 = strcmp(local_78,"userdata");
        if (iVar3 == 0) {
          local_24 = FUN_0026afef(param_1,param_4,local_a8);
        }
        else {
          iVar3 = FUN_00268e49();
          if (iVar3 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid special object child %s\n",
                    *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),local_78);
          }
          local_24 = -1;
        }
      }
    }
    if (local_24 < 0) {
      return 0xffffffff;
    }
    (**(code **)(*(long *)(param_6 + 8) + 0x30))(local_a8);
  }
  if ((param_3 != (int *)0x0) && (*param_4 == 0)) {
    *param_4 = 0xc;
  }
  if ((param_3 == (int *)0x0) || (*(uint *)(param_2 + 0x58) < 2)) {
    if ((param_3 != (int *)0x0) && (*(uint *)(param_2 + 0x58) < 2)) {
      iVar3 = FUN_00268da4(*param_4);
      if ((iVar3 == 0) && (*param_4 != 0xd)) {
        iVar3 = FUN_00268e07(*param_4);
        if ((iVar3 != 0) && (*param_3 == 0x11)) {
          iVar3 = FUN_00268e49();
          if (iVar3 != 0) {
            uVar5 = FUN_002582d8(*param_4);
            fprintf(*(FILE **)PTR_stderr_0032efe0,"I/O object %s cannot be child of Misc parent\n",
                    uVar5);
          }
          goto LAB_0026ce6b;
        }
      }
      else {
        iVar3 = FUN_00268de6(*param_3);
        if (iVar3 != 0) {
          iVar3 = FUN_00268e49();
          if (iVar3 != 0) {
            uVar5 = FUN_002582d8(*param_3);
            uVar6 = FUN_002582d8(*param_4);
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "v1.x normal v1.x object %s cannot be child of special parent %s\n",uVar6,uVar5)
            ;
          }
          goto LAB_0026ce6b;
        }
      }
    }
  }
  else {
    iVar3 = FUN_00268da4(*param_4);
    if (iVar3 == 0) {
      iVar3 = FUN_00268dc5(*param_4);
      if (iVar3 == 0) {
        iVar3 = FUN_00268e07(*param_4);
        if ((iVar3 != 0) && ((iVar3 = FUN_00268dc5(*param_3), iVar3 != 0 || (*param_3 == 0x11)))) {
          iVar3 = FUN_00268e49();
          if (iVar3 != 0) {
            uVar5 = FUN_002582d8(*param_3);
            uVar6 = FUN_002582d8(*param_4);
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "I/O object %s cannot be child of non-normal-or-I/O parent %s\n",uVar6,uVar5);
          }
          goto LAB_0026ce6b;
        }
      }
      else {
        iVar3 = FUN_00268e07(*param_3);
        if ((iVar3 != 0) || (*param_3 == 0x11)) {
          iVar3 = FUN_00268e49();
          if (iVar3 != 0) {
            uVar5 = FUN_002582d8(*param_3);
            uVar6 = FUN_002582d8(*param_4);
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "Memory object %s cannot be child of non-normal-or-memory parent %s\n",uVar6,
                    uVar5);
          }
          goto LAB_0026ce6b;
        }
      }
    }
    else {
      iVar3 = FUN_00268da4(*param_3);
      if (iVar3 == 0) {
        iVar3 = FUN_00268e49();
        if (iVar3 != 0) {
          uVar5 = FUN_002582d8(*param_3);
          uVar6 = FUN_002582d8(*param_4);
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "normal object %s cannot be child of non-normal parent %s\n",uVar6,uVar5);
        }
        goto LAB_0026ce6b;
      }
    }
  }
  if (*(uint *)(param_2 + 0x58) < 2) {
    if (((param_3 != (int *)0x0) && (*param_3 == 0xd)) &&
       (local_d0 = *(int **)(param_3 + 0x12), local_d0 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                    ,0x3e6,"hwloc__xml_import_object");
    }
    if (*param_4 == 0xd) {
      if (local_d0 == (int *)0x0) {
        local_58 = (int *)FUN_0024febd(param_1,0,0xffffffff);
        uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x2e));
        *(undefined8 *)(local_58 + 0x2e) = uVar5;
        uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x2e));
        *(undefined8 *)(local_58 + 0x30) = uVar5;
        uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x32));
        *(undefined8 *)(local_58 + 0x32) = uVar5;
        uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x34));
        *(undefined8 *)(local_58 + 0x34) = uVar5;
        *(int **)**(undefined8 **)(param_1 + 0x18) = local_58;
        local_d0 = local_58;
        local_20 = 1;
      }
      else {
        iVar3 = FUN_00262158(*(undefined8 *)(param_4 + 0x30),*(undefined8 *)(local_d0 + 0x30));
        if (iVar3 == 0) {
          local_28 = 1;
          local_48 = *(long *)(local_d0 + 0x24);
          if ((((local_48 != 0) && (*(long *)(local_48 + 8) == 0)) &&
              ((*(long *)(local_48 + 0x58) == 0 &&
               ((*(long *)(param_4 + 2) != 0 &&
                (iVar3 = strcmp(*(char **)(param_4 + 2),"MCDRAM"), iVar3 == 0)))))) &&
             (iVar3 = FUN_002620a3(*(undefined8 *)(param_4 + 0x30)), iVar3 != 0)) {
            local_28 = 0;
          }
          if ((local_28 != 0) && (iVar3 = FUN_00268c74(param_1,0xc), iVar3 != 0)) {
            local_50 = (int *)FUN_0024febd(param_1,0xc,0xffffffff);
            local_50[0x3c] = 0;
            local_50[0x3d] = 0;
            uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x2e));
            *(undefined8 *)(local_50 + 0x2e) = uVar5;
            uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x2e));
            *(undefined8 *)(local_50 + 0x30) = uVar5;
            uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x32));
            *(undefined8 *)(local_50 + 0x32) = uVar5;
            uVar5 = FUN_002611e2(*(undefined8 *)(param_4 + 0x34));
            *(undefined8 *)(local_50 + 0x34) = uVar5;
            *(undefined4 *)(*(long *)(local_50 + 10) + 4) = 0x3e9;
            FUN_0024fc99(param_1,local_d0,local_50);
            local_d0 = local_50;
          }
        }
      }
    }
    if (local_1c != 0) {
      if (*param_4 != 0x15) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->type == (HWLOC_OBJ_TYPE_MAX+1)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                      ,0x41e,"hwloc__xml_import_object");
      }
      iVar3 = FUN_00268d5e(*(undefined4 *)(*(long *)(param_4 + 10) + 8),
                           *(undefined4 *)(*(long *)(param_4 + 10) + 0x14));
      *param_4 = iVar3;
    }
    if ((*param_4 == 0x11) && (*(long *)(param_4 + 0x2e) != 0)) {
      *param_4 = 0xc;
    }
    if ((*(long *)(param_4 + 0x30) == 0) == (*(long *)(param_4 + 0x2e) == 0)) {
      if ((*(long *)(param_4 + 0x34) == 0) == (*(long *)(param_4 + 0x32) == 0)) {
        if ((*(long *)(param_4 + 0x32) != 0) && (*(long *)(param_4 + 0x2e) == 0)) {
          if (*param_4 != 0xc) {
            iVar3 = FUN_00268e49();
            if (iVar3 != 0) {
              uVar1 = param_4[4];
              uVar5 = FUN_002582d8(*param_4);
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "%s: invalid object %s P#%u with either cpuset or nodeset missing\n",
                      *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar1);
            }
            goto LAB_0026ce6b;
          }
          local_6c = 1;
        }
      }
      else {
        if (*param_4 != 0xc) {
          iVar3 = FUN_00268e49();
          if (iVar3 != 0) {
            uVar1 = param_4[4];
            uVar5 = FUN_002582d8(*param_4);
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "%s: invalid object %s P#%u with some missing nodesets\n",
                    *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar1);
          }
          goto LAB_0026ce6b;
        }
        local_6c = 1;
      }
    }
    else {
      if (*param_4 != 0xc) {
        iVar3 = FUN_00268e49();
        if (iVar3 != 0) {
          uVar1 = param_4[4];
          uVar5 = FUN_002582d8(*param_4);
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "%s: invalid object %s P#%u with some missing cpusets\n",
                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar1);
        }
        goto LAB_0026ce6b;
      }
      local_6c = 1;
    }
  }
  if ((*param_4 == 0xc) &&
     ((*(int *)(*(long *)(param_4 + 10) + 4) == 0x68 ||
      ((*(long *)(param_4 + 2) != 0 && (iVar3 = strcmp(*(char **)(param_4 + 2),"Die"), iVar3 == 0)))
      ))) {
    *param_4 = 0x13;
  }
  iVar3 = FUN_00268e28(*param_4);
  if ((iVar3 == 0) ||
     (iVar3 = *param_4,
     iVar4 = FUN_00268d5e(*(undefined4 *)(*(long *)(param_4 + 10) + 8),
                          *(undefined4 *)(*(long *)(param_4 + 10) + 0x14)), iVar3 == iVar4)) {
    if ((*(long *)(param_4 + 0x2e) == 0) && (iVar3 = FUN_00268de6(*param_4), iVar3 == 0)) {
      iVar3 = FUN_00268e49();
      if (iVar3 != 0) {
        uVar1 = param_4[4];
        uVar5 = FUN_002582d8(*param_4);
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid normal object %s P#%u without cpuset\n",
                *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar1);
      }
    }
    else if ((*(long *)(param_4 + 0x2e) == 0) || (iVar3 = FUN_00268de6(*param_4), iVar3 == 0)) {
      if ((*(long *)(param_4 + 0x2e) == 0) ||
         ((local_d0 == (int *)0x0 || (*(long *)(local_d0 + 0x2e) != 0)))) {
        if ((*(long *)(param_4 + 0x32) == 0) ||
           ((local_d0 == (int *)0x0 || (*(long *)(local_d0 + 0x32) != 0)))) {
          if (*param_4 == 0xd) {
            if (*(long *)(param_4 + 0x32) == 0) {
              iVar3 = FUN_00268e49();
              if (iVar3 != 0) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "%s: invalid NUMA node object P#%u without nodeset\n",
                        *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),(ulong)(uint)param_4[4]);
              }
              goto LAB_0026ce6b;
            }
            *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
            *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x70);
            param_4[0xe] = 0;
            param_4[0xf] = 0;
            if (*(long *)(param_2 + 0x70) == 0) {
              *(int **)(param_2 + 0x68) = param_4;
            }
            else {
              *(int **)(*(long *)(param_2 + 0x70) + 0x38) = param_4;
            }
            *(int **)(param_2 + 0x70) = param_4;
          }
          iVar3 = FUN_00268cd4(param_1,param_4);
          if ((iVar3 == 0) && (local_d0 != (int *)0x0)) {
            local_6c = 1;
          }
          if ((local_d0 != (int *)0x0) && (local_6c == 0)) {
            FUN_0024fc99(param_1,local_d0,param_4);
          }
          do {
            if (local_78 == (char *)0x0) break;
            iVar3 = strcmp(local_78,"object");
            if (iVar3 == 0) {
              local_60 = FUN_0024febd(param_1,0x14,0xffffffff);
              piVar7 = param_4;
              if (local_6c != 0) {
                piVar7 = local_d0;
              }
              *(int **)(local_60 + 0x48) = piVar7;
              piVar7 = param_4;
              if (local_6c != 0) {
                piVar7 = local_d0;
              }
              local_2c = FUN_0026b826(param_1,param_2,piVar7,local_60,&local_70,local_a8);
            }
            else {
              iVar3 = FUN_00268e49();
              if (iVar3 != 0) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "%s: invalid special object child %s while looking for objects\n",
                        *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),local_78);
              }
              local_2c = -1;
            }
            if (local_2c < 0) {
joined_r0x0026cc2c:
              if ((local_d0 != (int *)0x0) && (local_6c == 0)) {
                return 0xffffffff;
              }
              goto LAB_0026ce6b;
            }
            (**(code **)(*(long *)(param_6 + 8) + 0x30))(local_a8);
            local_78 = (char *)0x0;
            local_2c = (**(code **)(*(long *)(param_6 + 8) + 0x20))(param_6,local_a8,&local_78);
            if (local_2c < 0) goto joined_r0x0026cc2c;
          } while (local_2c != 0);
          if (local_20 != 0) {
            for (local_30 = 0; local_30 < (uint)param_4[0x38]; local_30 = local_30 + 1) {
              local_68 = (undefined8 *)(*(long *)(param_4 + 0x36) + (ulong)local_30 * 0x10);
              FUN_0024dfb5(local_d0,*local_68,local_68[1]);
            }
          }
          if (local_6c == 0) {
            if (*(long *)(param_4 + 0x1e) != 0) {
              local_38 = *(long *)(param_4 + 0x1e);
              for (local_40 = *(long *)(local_38 + 0x58); local_40 != 0;
                  local_40 = *(long *)(local_40 + 0x58)) {
                iVar3 = FUN_00262ca9(*(undefined8 *)(local_40 + 0xc0),
                                     *(undefined8 *)(local_38 + 0xc0));
                if (iVar3 < 0) {
                  if (((local_70 == 0) && (DAT_01218388 == 0)) &&
                     (iVar3 = FUN_0024d64f(), iVar3 < 2)) {
                    FUN_0026b49d(param_1,local_40,local_38);
                    DAT_01218388 = 1;
                  }
                  FUN_00250cb5(param_4);
                  break;
                }
                local_38 = local_40;
              }
            }
          }
          else {
            FUN_0024e0d0(param_4);
            *param_5 = 1;
          }
          uVar5 = (**(code **)(*(long *)(param_6 + 8) + 0x28))(param_6);
          return uVar5;
        }
        iVar3 = FUN_00268e49();
        if (iVar3 != 0) {
          uVar1 = param_4[4];
          uVar5 = FUN_002582d8(*param_4);
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "%s: invalid object %s P#%u with nodeset while parent has none\n",
                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar1);
        }
      }
      else {
        iVar3 = FUN_00268e49();
        if (iVar3 != 0) {
          uVar1 = param_4[4];
          uVar5 = FUN_002582d8(*param_4);
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "%s: invalid object %s P#%u with cpuset while parent has none\n",
                  *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar1);
        }
      }
    }
    else {
      iVar3 = FUN_00268e49();
      if (iVar3 != 0) {
        uVar5 = FUN_002582d8(*param_4);
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid special object %s with cpuset\n",
                *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5);
      }
    }
  }
  else {
    iVar3 = FUN_00268e49();
    if (iVar3 != 0) {
      uVar1 = *(uint *)(*(long *)(param_4 + 10) + 0x14);
      uVar2 = *(uint *)(*(long *)(param_4 + 10) + 8);
      uVar5 = FUN_002582d8(*param_4);
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "%s: invalid cache type %s with attribute depth %u and type %d\n",
              *(undefined8 *)(*(long *)(param_6 + 8) + 0x48),uVar5,(ulong)uVar2,(ulong)uVar1);
    }
  }
LAB_0026ce6b:
  if (local_d0 == (int *)0x0) {
    return 0xffffffff;
  }
  FUN_0024e0d0(param_4);
  return 0xffffffff;
}


// ===== 0026ce9b FUN_0026ce9b =====

undefined8 FUN_0026ce9b(long param_1,long param_2)

{
  int iVar1;
  char *local_28;
  char *local_20;
  int local_14;
  char *local_10;
  
  local_10 = (char *)0x0;
  local_14 = 1;
  while (iVar1 = (**(code **)(*(long *)(param_2 + 8) + 0x18))(param_2,&local_20,&local_28),
        -1 < iVar1) {
    iVar1 = strcmp(local_20,"name");
    if (iVar1 == 0) {
      local_10 = local_28;
    }
    else {
      iVar1 = strcmp(local_20,"value");
      if (iVar1 == 0) {
        local_14 = atoi(local_28);
      }
      else {
        iVar1 = FUN_00268e49();
        if (iVar1 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring unknown support attribute %s\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),local_20);
        }
      }
    }
  }
  if ((local_10 != (char *)0x0) && ((*(ulong *)(param_1 + 0x20) & 8) != 0)) {
    iVar1 = strcmp("discovery.pu",local_10);
    if (iVar1 == 0) {
      **(undefined1 **)(param_1 + 0x288) = (char)local_14;
    }
    else {
      iVar1 = strcmp("discovery.numa",local_10);
      if (iVar1 == 0) {
        *(char *)(*(long *)(param_1 + 0x288) + 1) = (char)local_14;
      }
      else {
        iVar1 = strcmp("discovery.numa_memory",local_10);
        if (iVar1 == 0) {
          *(char *)(*(long *)(param_1 + 0x288) + 2) = (char)local_14;
        }
        else {
          iVar1 = strcmp("discovery.disallowed_pu",local_10);
          if (iVar1 == 0) {
            *(char *)(*(long *)(param_1 + 0x288) + 3) = (char)local_14;
          }
          else {
            iVar1 = strcmp("discovery.disallowed_numa",local_10);
            if (iVar1 == 0) {
              *(char *)(*(long *)(param_1 + 0x288) + 4) = (char)local_14;
            }
            else {
              iVar1 = strcmp("discovery.cpukind_efficiency",local_10);
              if (iVar1 == 0) {
                *(char *)(*(long *)(param_1 + 0x288) + 5) = (char)local_14;
              }
              else {
                iVar1 = strcmp("cpubind.set_thisproc_cpubind",local_10);
                if (iVar1 == 0) {
                  **(undefined1 **)(param_1 + 0x290) = (char)local_14;
                }
                else {
                  iVar1 = strcmp("cpubind.get_thisproc_cpubind",local_10);
                  if (iVar1 == 0) {
                    *(char *)(*(long *)(param_1 + 0x290) + 1) = (char)local_14;
                  }
                  else {
                    iVar1 = strcmp("cpubind.set_proc_cpubind",local_10);
                    if (iVar1 == 0) {
                      *(char *)(*(long *)(param_1 + 0x290) + 2) = (char)local_14;
                    }
                    else {
                      iVar1 = strcmp("cpubind.get_proc_cpubind",local_10);
                      if (iVar1 == 0) {
                        *(char *)(*(long *)(param_1 + 0x290) + 3) = (char)local_14;
                      }
                      else {
                        iVar1 = strcmp("cpubind.set_thisthread_cpubind",local_10);
                        if (iVar1 == 0) {
                          *(char *)(*(long *)(param_1 + 0x290) + 4) = (char)local_14;
                        }
                        else {
                          iVar1 = strcmp("cpubind.get_thisthread_cpubind",local_10);
                          if (iVar1 == 0) {
                            *(char *)(*(long *)(param_1 + 0x290) + 5) = (char)local_14;
                          }
                          else {
                            iVar1 = strcmp("cpubind.set_thread_cpubind",local_10);
                            if (iVar1 == 0) {
                              *(char *)(*(long *)(param_1 + 0x290) + 6) = (char)local_14;
                            }
                            else {
                              iVar1 = strcmp("cpubind.get_thread_cpubind",local_10);
                              if (iVar1 == 0) {
                                *(char *)(*(long *)(param_1 + 0x290) + 7) = (char)local_14;
                              }
                              else {
                                iVar1 = strcmp("cpubind.get_thisproc_last_cpu_location",local_10);
                                if (iVar1 == 0) {
                                  *(char *)(*(long *)(param_1 + 0x290) + 8) = (char)local_14;
                                }
                                else {
                                  iVar1 = strcmp("cpubind.get_proc_last_cpu_location",local_10);
                                  if (iVar1 == 0) {
                                    *(char *)(*(long *)(param_1 + 0x290) + 9) = (char)local_14;
                                  }
                                  else {
                                    iVar1 = strcmp("cpubind.get_thisthread_last_cpu_location",
                                                   local_10);
                                    if (iVar1 == 0) {
                                      *(char *)(*(long *)(param_1 + 0x290) + 10) = (char)local_14;
                                    }
                                    else {
                                      iVar1 = strcmp("membind.set_thisproc_membind",local_10);
                                      if (iVar1 == 0) {
                                        **(undefined1 **)(param_1 + 0x298) = (char)local_14;
                                      }
                                      else {
                                        iVar1 = strcmp("membind.get_thisproc_membind",local_10);
                                        if (iVar1 == 0) {
                                          *(char *)(*(long *)(param_1 + 0x298) + 1) = (char)local_14
                                          ;
                                        }
                                        else {
                                          iVar1 = strcmp("membind.set_proc_membind",local_10);
                                          if (iVar1 == 0) {
                                            *(char *)(*(long *)(param_1 + 0x298) + 2) =
                                                 (char)local_14;
                                          }
                                          else {
                                            iVar1 = strcmp("membind.get_proc_membind",local_10);
                                            if (iVar1 == 0) {
                                              *(char *)(*(long *)(param_1 + 0x298) + 3) =
                                                   (char)local_14;
                                            }
                                            else {
                                              iVar1 = strcmp("membind.set_thisthread_membind",
                                                             local_10);
                                              if (iVar1 == 0) {
                                                *(char *)(*(long *)(param_1 + 0x298) + 4) =
                                                     (char)local_14;
                                              }
                                              else {
                                                iVar1 = strcmp("membind.get_thisthread_membind",
                                                               local_10);
                                                if (iVar1 == 0) {
                                                  *(char *)(*(long *)(param_1 + 0x298) + 5) =
                                                       (char)local_14;
                                                }
                                                else {
                                                  iVar1 = strcmp("membind.set_area_membind",local_10
                                                                );
                                                  if (iVar1 == 0) {
                                                    *(char *)(*(long *)(param_1 + 0x298) + 6) =
                                                         (char)local_14;
                                                  }
                                                  else {
                                                    iVar1 = strcmp("membind.get_area_membind",
                                                                   local_10);
                                                    if (iVar1 == 0) {
                                                      *(char *)(*(long *)(param_1 + 0x298) + 7) =
                                                           (char)local_14;
                                                    }
                                                    else {
                                                      iVar1 = strcmp("membind.alloc_membind",
                                                                     local_10);
                                                      if (iVar1 == 0) {
                                                        *(char *)(*(long *)(param_1 + 0x298) + 8) =
                                                             (char)local_14;
                                                      }
                                                      else {
                                                        iVar1 = strcmp("membind.firsttouch_membind",
                                                                       local_10);
                                                        if (iVar1 == 0) {
                                                          *(char *)(*(long *)(param_1 + 0x298) + 9)
                                                               = (char)local_14;
                                                        }
                                                        else {
                                                          iVar1 = strcmp("membind.bind_membind",
                                                                         local_10);
                                                          if (iVar1 == 0) {
                                                            *(char *)(*(long *)(param_1 + 0x298) +
                                                                     10) = (char)local_14;
                                                          }
                                                          else {
                                                            iVar1 = strcmp(
                                                  "membind.interleave_membind",local_10);
                                                  if (iVar1 == 0) {
                                                    *(char *)(*(long *)(param_1 + 0x298) + 0xb) =
                                                         (char)local_14;
                                                  }
                                                  else {
                                                    iVar1 = strcmp("membind.nexttouch_membind",
                                                                   local_10);
                                                    if (iVar1 == 0) {
                                                      *(char *)(*(long *)(param_1 + 0x298) + 0xc) =
                                                           (char)local_14;
                                                    }
                                                    else {
                                                      iVar1 = strcmp("membind.migrate_membind",
                                                                     local_10);
                                                      if (iVar1 == 0) {
                                                        *(char *)(*(long *)(param_1 + 0x298) + 0xd)
                                                             = (char)local_14;
                                                      }
                                                      else {
                                                        iVar1 = strcmp(
                                                  "membind.get_area_memlocation",local_10);
                                                  if (iVar1 == 0) {
                                                    *(char *)(*(long *)(param_1 + 0x298) + 0xe) =
                                                         (char)local_14;
                                                  }
                                                  else {
                                                    iVar1 = strcmp("custom.exported_support",
                                                                   local_10);
                                                    if (iVar1 == 0) {
                                                      **(undefined1 **)(param_1 + 0x2a0) = 1;
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
      }
    }
  }
  return 0;
}


// ===== 0026d548 FUN_0026d548 =====

undefined8 FUN_0026d548(long param_1,long param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined1 local_108 [56];
  char *local_d0;
  undefined4 local_c4;
  char *local_c0;
  char *local_b8;
  char *local_b0;
  char *local_a8;
  char *local_a0;
  char *local_98;
  char *local_90;
  int local_84;
  ulonglong local_80;
  char *local_78;
  ulonglong local_70;
  uint local_68;
  int local_64;
  char *local_60;
  char *local_58;
  int local_50;
  int local_4c;
  void *local_48;
  void *local_40;
  uint local_38;
  uint local_34;
  ulong local_30;
  char *local_28;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  
  local_84 = -1;
  local_10 = (void *)0x0;
  local_14 = 0;
  local_1c = 0;
  local_28 = (char *)0x0;
  local_30 = 0;
  local_20 = param_3;
  local_18 = param_3;
  while (iVar2 = (**(code **)(*(long *)(param_2 + 8) + 0x18))(param_2,&local_90,&local_98),
        -1 < iVar2) {
    iVar2 = strcmp(local_90,"nbobjs");
    if (iVar2 == 0) {
      uVar3 = strtoul(local_98,(char **)0x0,10);
      local_14 = (uint)uVar3;
    }
    else {
      iVar2 = strcmp(local_90,"type");
      if (iVar2 == 0) {
        iVar2 = FUN_002584c0(local_98,&local_84,0,0);
        if (iVar2 < 0) {
          iVar2 = FUN_00268e49();
          if (iVar2 != 0) {
            if (param_3 == 0) {
              pcVar4 = "distances2";
            }
            else {
              pcVar4 = "distances2hetero";
            }
            fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: unrecognized %s type %s\n",
                    *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,local_98);
          }
          return 0xffffffff;
        }
      }
      else {
        iVar2 = strcmp(local_90,"indexing");
        if (iVar2 == 0) {
          local_18 = 1;
          iVar2 = strcmp(local_98,"os");
          if (iVar2 == 0) {
            local_1c = 1;
          }
          else {
            iVar2 = strcmp(local_98,"gp");
            if (iVar2 == 0) {
              local_20 = 1;
            }
          }
        }
        else {
          iVar2 = strcmp(local_90,"kind");
          if (iVar2 == 0) {
            local_30 = strtoul(local_98,(char **)0x0,10);
          }
          else {
            iVar2 = strcmp(local_90,"name");
            if (iVar2 == 0) {
              local_28 = local_98;
            }
            else {
              iVar2 = FUN_00268e49();
              if (iVar2 != 0) {
                if (param_3 == 0) {
                  pcVar4 = "distances2";
                }
                else {
                  pcVar4 = "distances2hetero";
                }
                fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring unknown %s attribute %s\n",
                        *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,local_90);
              }
            }
          }
        }
      }
    }
  }
  if ((local_14 == 0) ||
     ((((param_3 == 0 && (local_84 == -1)) || (local_18 == 0)) || (local_30 == 0)))) {
    iVar2 = FUN_00268e49();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    if (param_3 == 0) {
      pcVar4 = "distances2";
    }
    else {
      pcVar4 = "distances2hetero";
    }
    fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s missing some attributes\n",
            *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4);
    return 0xffffffff;
  }
  local_40 = malloc((ulong)local_14 << 3);
  local_48 = malloc((ulong)(local_14 * local_14) << 3);
  if (param_3 != 0) {
    local_10 = malloc((ulong)local_14 << 2);
  }
  if (((local_40 == (void *)0x0) || (local_48 == (void *)0x0)) ||
     ((param_3 != 0 && (local_10 == (void *)0x0)))) {
    iVar2 = FUN_00268e49();
    if (iVar2 != 0) {
      if (param_3 == 0) {
        pcVar4 = "distances2";
      }
      else {
        pcVar4 = "distances2hetero";
      }
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: failed to allocate %s arrays for %u objects\n",
              *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)local_14);
    }
  }
  else {
    local_34 = 0;
    local_38 = 0;
    while( true ) {
      local_4c = 0;
      local_50 = 0;
      local_64 = (**(code **)(*(long *)(param_2 + 8) + 0x20))(param_2,local_108,&local_b0);
      if (local_64 < 1) break;
      iVar2 = strcmp(local_b0,"indexes");
      if (iVar2 == 0) {
        local_4c = 1;
      }
      else {
        iVar2 = strcmp(local_b0,"u64values");
        if (iVar2 == 0) {
          local_50 = 1;
        }
      }
      if ((local_4c == 0) && (local_50 == 0)) {
        iVar2 = FUN_00268e49();
        if (iVar2 != 0) {
          if (param_3 == 0) {
            pcVar4 = "distances2";
          }
          else {
            pcVar4 = "distances2hetero";
          }
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s with unrecognized child %s\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,local_b0);
        }
        goto LAB_0026e265;
      }
      iVar2 = (**(code **)(*(long *)(param_2 + 8) + 0x18))(local_108,&local_a0,&local_a8);
      if ((iVar2 < 0) || (iVar2 = strcmp(local_a0,"length"), iVar2 != 0)) {
        iVar2 = FUN_00268e49();
        if (iVar2 != 0) {
          if (param_3 == 0) {
            pcVar4 = "distances2";
          }
          else {
            pcVar4 = "distances2hetero";
          }
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s child must have length attribute\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4);
        }
        goto LAB_0026e265;
      }
      local_68 = atoi(local_a8);
      local_64 = (**(code **)(*(long *)(param_2 + 8) + 0x38))
                           (local_108,&local_b8,(long)(int)local_68);
      if (local_64 < 0) {
        iVar2 = FUN_00268e49();
        if (iVar2 != 0) {
          if (param_3 == 0) {
            pcVar4 = "distances2";
          }
          else {
            pcVar4 = "distances2hetero";
          }
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s child needs content of length %d\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)local_68);
        }
        goto LAB_0026e265;
      }
      if (local_4c != 0) {
        if (local_34 < local_14) {
          local_58 = local_b8;
          do {
            if (param_3 != 0) {
              local_c4 = 0xffffffff;
              if (*local_58 == '\0') goto LAB_0026ded8;
              iVar2 = FUN_002584c0(local_58,&local_c4,0,0);
              if (iVar2 < 0) {
                iVar2 = FUN_00268e49();
                if (iVar2 != 0) {
                  if (param_3 == 0) {
                    pcVar4 = "distances2";
                  }
                  else {
                    pcVar4 = "distances2hetero";
                  }
                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                          "%s: %s with unrecognized heterogeneous type %s\n",
                          *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,local_58);
                }
                goto LAB_0026e265;
              }
              local_78 = strchr(local_58,0x3a);
              if (local_78 == (char *)0x0) {
                iVar2 = FUN_00268e49();
                if (iVar2 != 0) {
                  if (param_3 == 0) {
                    pcVar4 = "distances2";
                  }
                  else {
                    pcVar4 = "distances2hetero";
                  }
                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                          "%s: %s with missing colon after heterogeneous type %s\n",
                          *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,local_58);
                }
                goto LAB_0026e265;
              }
              local_58 = local_78 + 1;
              *(undefined4 *)((ulong)local_34 * 4 + (long)local_10) = local_c4;
            }
            local_80 = strtoull(local_58,&local_c0,0);
            if (local_58 == local_c0) goto LAB_0026ded8;
            uVar1 = local_34 + 1;
            *(ulonglong *)((ulong)local_34 * 8 + (long)local_40) = local_80;
            local_34 = uVar1;
            if ((*local_c0 != ' ') || (uVar1 == local_14)) goto LAB_0026ded8;
            local_58 = local_c0 + 1;
          } while( true );
        }
        iVar2 = FUN_00268e49();
        if (iVar2 != 0) {
          if (param_3 == 0) {
            pcVar4 = "distances2";
          }
          else {
            pcVar4 = "distances2hetero";
          }
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s with more than %u indexes\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)local_14);
        }
        goto LAB_0026e265;
      }
      if (local_50 != 0) {
        if (local_14 * local_14 <= local_38) {
          iVar2 = FUN_00268e49();
          if (iVar2 != 0) {
            if (param_3 == 0) {
              pcVar4 = "distances2";
            }
            else {
              pcVar4 = "distances2hetero";
            }
            fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s with more than %u u64values\n",
                    *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,
                    (ulong)(local_14 * local_14));
          }
          goto LAB_0026e265;
        }
        local_60 = local_b8;
        while (local_70 = strtoull(local_60,&local_d0,0), local_60 != local_d0) {
          uVar1 = local_38 + 1;
          *(ulonglong *)((ulong)local_38 * 8 + (long)local_48) = local_70;
          local_38 = uVar1;
          if ((*local_d0 != ' ') || (uVar1 == local_14 * local_14)) break;
          local_60 = local_d0 + 1;
        }
      }
LAB_0026ded8:
      (**(code **)(*(long *)(param_2 + 8) + 0x40))(local_108);
      local_64 = (**(code **)(*(long *)(param_2 + 8) + 0x28))(local_108);
      if (local_64 < 0) {
        iVar2 = FUN_00268e49();
        if (iVar2 != 0) {
          if (param_3 == 0) {
            pcVar4 = "distances2";
          }
          else {
            pcVar4 = "distances2hetero";
          }
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s with more than %u indexes\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)local_14);
        }
        goto LAB_0026e265;
      }
      (**(code **)(*(long *)(param_2 + 8) + 0x30))(local_108);
    }
    if (local_34 == local_14) {
      if (local_38 == local_14 * local_14) {
        if (local_14 < 2) {
          iVar2 = FUN_00268e49();
          if (iVar2 != 0) {
            if (param_3 == 0) {
              pcVar4 = "distances2";
            }
            else {
              pcVar4 = "distances2hetero";
            }
            fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring %s with only %u objects\n",
                    *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)local_14);
          }
        }
        else {
          if ((local_84 == 3) || (local_84 == 0xd)) {
            if (local_1c == 0) {
              iVar2 = FUN_00268e49();
              if (iVar2 != 0) {
                if (param_3 == 0) {
                  pcVar4 = "distances2";
                }
                else {
                  pcVar4 = "distances2hetero";
                }
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "%s: ignoring PU or NUMA %s without os_indexing\n",
                        *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4);
              }
              goto LAB_0026e205;
            }
          }
          else if (local_20 == 0) {
            iVar2 = FUN_00268e49();
            if (iVar2 != 0) {
              if (param_3 == 0) {
                pcVar4 = "distances2";
              }
              else {
                pcVar4 = "distances2hetero";
              }
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "%s: ignoring !PU or !NUMA %s without gp_indexing\n",
                      *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4);
            }
            goto LAB_0026e205;
          }
          if ((*(ulong *)(param_1 + 0x20) & 0x80) == 0) {
            FUN_00259c6e(param_1,local_28,local_84,local_10,local_14,local_40,local_48,local_30,0);
            local_40 = (void *)0x0;
            local_48 = (void *)0x0;
            local_10 = (void *)0x0;
          }
        }
LAB_0026e205:
        free(local_10);
        free(local_40);
        free(local_48);
        uVar5 = (**(code **)(*(long *)(param_2 + 8) + 0x28))(param_2);
        return uVar5;
      }
      iVar2 = FUN_00268e49();
      if (iVar2 != 0) {
        if (param_3 == 0) {
          pcVar4 = "distances2";
        }
        else {
          pcVar4 = "distances2hetero";
        }
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s with less than %u u64values\n",
                *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)(local_14 * local_14));
      }
    }
    else {
      iVar2 = FUN_00268e49();
      if (iVar2 != 0) {
        if (param_3 == 0) {
          pcVar4 = "distances2";
        }
        else {
          pcVar4 = "distances2hetero";
        }
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: %s with less than %u indexes\n",
                *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),pcVar4,(ulong)local_14);
      }
    }
  }
LAB_0026e265:
  free(local_10);
  free(local_40);
  free(local_48);
  return 0xffffffff;
}


// ===== 0026e296 FUN_0026e296 =====

undefined8 FUN_0026e296(undefined8 param_1,undefined4 param_2,ulong param_3,long param_4)

{
  int iVar1;
  undefined8 uVar2;
  int local_88 [2];
  long local_80;
  ulonglong local_78;
  undefined1 local_70 [16];
  char *local_60;
  char *local_58;
  undefined4 local_4c;
  ulonglong local_48;
  ulonglong local_40;
  char *local_38;
  char *local_30;
  char *local_28;
  char *local_20;
  char *local_18;
  char *local_10;
  
  local_10 = (char *)0x0;
  local_18 = (char *)0x0;
  local_20 = (char *)0x0;
  local_28 = (char *)0x0;
  local_30 = (char *)0x0;
  local_38 = (char *)0x0;
  local_4c = 0xffffffff;
  while (iVar1 = (**(code **)(*(long *)(param_4 + 8) + 0x18))(param_4,&local_58,&local_60),
        -1 < iVar1) {
    iVar1 = strcmp(local_58,"target_obj_gp_index");
    if (iVar1 == 0) {
      local_10 = local_60;
    }
    else {
      iVar1 = strcmp(local_58,"target_obj_type");
      if (iVar1 == 0) {
        local_18 = local_60;
      }
      else {
        iVar1 = strcmp(local_58,"value");
        if (iVar1 == 0) {
          local_20 = local_60;
        }
        else {
          iVar1 = strcmp(local_58,"initiator_cpuset");
          if (iVar1 == 0) {
            local_28 = local_60;
          }
          else {
            iVar1 = strcmp(local_58,"initiator_obj_gp_index");
            if (iVar1 == 0) {
              local_30 = local_60;
            }
            else {
              iVar1 = strcmp(local_58,"initiator_obj_type");
              if (iVar1 != 0) {
                iVar1 = FUN_00268e49();
                if (iVar1 != 0) {
                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                          "%s: ignoring unknown memattr_value attribute %s\n",
                          *(undefined8 *)(*(long *)(param_4 + 8) + 0x48),local_58);
                }
                return 0xffffffff;
              }
              local_38 = local_60;
            }
          }
        }
      }
    }
  }
  if (local_18 == (char *)0x0) {
    iVar1 = FUN_00268e49();
    if (iVar1 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring memattr_value without target_obj_type.\n",
              *(undefined8 *)(*(long *)(param_4 + 8) + 0x48));
    }
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_002584c0(local_18,&local_4c,0,0);
    if (iVar1 < 0) {
      iVar1 = FUN_00268e49();
      if (iVar1 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "%s: failed to identify memattr_value target object type %s\n",
                *(undefined8 *)(*(long *)(param_4 + 8) + 0x48),local_18);
      }
      uVar2 = 0xffffffff;
    }
    else if ((local_20 == (char *)0x0) || (local_10 == (char *)0x0)) {
      iVar1 = FUN_00268e49();
      if (iVar1 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "%s: ignoring memattr_value without value and target_obj_gp_index\n",
                *(undefined8 *)(*(long *)(param_4 + 8) + 0x48));
      }
      uVar2 = 0xffffffff;
    }
    else {
      local_40 = strtoull(local_10,(char **)0x0,10);
      local_48 = strtoull(local_20,(char **)0x0,10);
      if ((param_3 & 4) == 0) {
        FUN_0025c155(param_1,param_2,local_4c,local_40,0xffffffff,0,local_48);
      }
      else {
        if ((local_28 == (char *)0x0) && ((local_30 == (char *)0x0 || (local_38 == (char *)0x0)))) {
          iVar1 = FUN_00268e49();
          if (iVar1 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "%s: ignoring memattr_value without initiator attributes\n",
                    *(undefined8 *)(*(long *)(param_4 + 8) + 0x48));
          }
          return 0xffffffff;
        }
        if (local_28 == (char *)0x0) {
          local_88[0] = 0;
          local_78 = strtoull(local_30,(char **)0x0,10);
          iVar1 = FUN_002584c0(local_38,local_70,0,0);
          if (iVar1 < 0) {
            iVar1 = FUN_00268e49();
            if (iVar1 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "%s: failed to identify memattr_value initiator object type %s\n",
                      *(undefined8 *)(*(long *)(param_4 + 8) + 0x48),local_38);
            }
            return 0xffffffff;
          }
        }
        else {
          local_88[0] = 1;
          local_80 = FUN_00260eab();
          if (local_80 == 0) {
            iVar1 = FUN_00268e49();
            if (iVar1 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "%s: failed to allocated memattr_value initiator cpuset\n",
                      *(undefined8 *)(*(long *)(param_4 + 8) + 0x48));
            }
            return 0xffffffff;
          }
          FUN_002615d6(local_80,local_28);
        }
        FUN_0025c155(param_1,param_2,local_4c,local_40,0xffffffff,local_88,local_48);
        if (local_88[0] == 1) {
          FUN_00260f71(local_80);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 0026e74f FUN_0026e74f =====

undefined8 FUN_0026e74f(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_78 [48];
  char *local_48;
  ulong local_40;
  undefined4 local_34;
  char *local_30;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulong local_18;
  char *local_10;
  
  local_10 = (char *)0x0;
  local_18 = 0xffffffffffffffff;
  local_1c = 0xffffffff;
  while (iVar1 = (**(code **)(*(long *)(param_2 + 8) + 0x18))(param_2,&local_28,&local_30),
        -1 < iVar1) {
    iVar1 = strcmp(local_28,"name");
    if (iVar1 == 0) {
      local_10 = local_30;
    }
    else {
      iVar1 = strcmp(local_28,"flags");
      if (iVar1 != 0) {
        iVar1 = FUN_00268e49();
        if (iVar1 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring unknown memattr attribute %s\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),local_28);
        }
        return 0xffffffff;
      }
      local_18 = strtoul(local_30,(char **)0x0,10);
    }
  }
  if (((local_10 != (char *)0x0) && (local_18 != 0xffffffffffffffff)) &&
     ((*(ulong *)(param_1 + 0x20) & 0x100) == 0)) {
    local_20 = FUN_0025b497(param_1,local_10,&local_34);
    if (local_20 < 0) {
      local_20 = FUN_0025b56f(param_1,local_10,local_18,&local_34);
      if (local_20 == 0) {
        local_1c = local_34;
      }
    }
    else {
      local_20 = FUN_0025b514(param_1,local_34,&local_40);
      if ((local_20 == 0) && (local_18 == local_40)) {
        local_1c = local_34;
      }
    }
  }
  while( true ) {
    local_20 = (**(code **)(*(long *)(param_2 + 8) + 0x20))(param_2,local_78,&local_48);
    if (local_20 < 1) {
      uVar2 = (**(code **)(*(long *)(param_2 + 8) + 0x28))(param_2);
      return uVar2;
    }
    iVar1 = strcmp(local_48,"memattr_value");
    if (iVar1 == 0) {
      local_20 = FUN_0026e296(param_1,local_1c,local_18,local_78);
    }
    else {
      iVar1 = FUN_00268e49();
      if (iVar1 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: memattr with unrecognized child %s\n",
                *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),local_48);
      }
      local_20 = -1;
    }
    if (local_20 < 0) break;
    (**(code **)(*(long *)(param_2 + 8) + 0x30))(local_78);
  }
  return 0xffffffff;
}


// ===== 0026e9ac FUN_0026e9ac =====

undefined8 FUN_0026e9ac(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_88 [56];
  long local_50;
  long local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined4 local_1c;
  int local_18;
  int local_14;
  long local_10;
  
  local_10 = 0;
  local_14 = -1;
  local_1c = 0;
  local_28 = 0;
  while (iVar1 = (**(code **)(*(long *)(param_2 + 8) + 0x18))(param_2,&local_30,&local_38),
        -1 < iVar1) {
    iVar1 = strcmp(local_30,"cpuset");
    if (iVar1 == 0) {
      if (local_10 == 0) {
        local_10 = FUN_00260eab();
      }
      FUN_002615d6(local_10,local_38);
    }
    else {
      iVar1 = strcmp(local_30,"forced_efficiency");
      if (iVar1 != 0) {
        iVar1 = FUN_00268e49();
        if (iVar1 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring unknown cpukind attribute %s\n",
                  *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),local_30);
        }
        FUN_00260f71(local_10);
        return 0xffffffff;
      }
      local_14 = atoi(local_38);
    }
  }
  while (local_18 = (**(code **)(*(long *)(param_2 + 8) + 0x20))(param_2,local_88,&local_40),
        0 < local_18) {
    iVar1 = strcmp(local_40,"info");
    if (iVar1 == 0) {
      local_48 = 0;
      local_50 = 0;
      local_18 = FUN_0026a833(&local_48,&local_50,local_88);
      if (((local_18 == 0) && (local_48 != 0)) && (local_50 != 0)) {
        FUN_0024dbec(&local_28,&local_1c,local_48,local_50);
      }
    }
    else {
      iVar1 = FUN_00268e49();
      if (iVar1 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: cpukind with unrecognized child %s\n",
                *(undefined8 *)(*(long *)(param_2 + 8) + 0x48),local_40);
      }
      local_18 = -1;
    }
    if (local_18 < 0) goto LAB_0026eca8;
    (**(code **)(*(long *)(param_2 + 8) + 0x30))(local_88);
  }
  if (local_10 == 0) {
    iVar1 = FUN_00268e49();
    if (iVar1 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: ignoring cpukind without cpuset\n",
              *(undefined8 *)(*(long *)(param_2 + 8) + 0x48));
    }
LAB_0026eca8:
    FUN_0024db80(local_28,local_1c);
    FUN_00260f71(local_10);
    uVar2 = 0xffffffff;
  }
  else {
    if ((*(ulong *)(param_1 + 0x20) & 0x200) == 0) {
      FUN_0025d167(param_1,local_10,local_14,local_28,local_1c,1);
      FUN_0024db80(local_28,local_1c);
    }
    else {
      FUN_0024db80(local_28,local_1c);
      FUN_00260f71(local_10);
    }
    uVar2 = (**(code **)(*(long *)(param_2 + 8) + 0x28))(param_2);
  }
  return uVar2;
}


// ===== 0026eccc FUN_0026eccc =====

undefined8 FUN_0026eccc(long param_1,long *param_2,long *param_3)

{
  int iVar1;
  ulonglong uVar2;
  char *pcVar3;
  undefined8 uVar4;
  char *local_60;
  char *local_58;
  undefined4 *local_50;
  int local_44;
  char *local_40;
  char *local_38;
  char *local_30;
  char *local_28;
  char *local_20;
  char *local_18;
  char *local_10;
  
  local_10 = (char *)0x0;
  local_18 = (char *)0x0;
  local_20 = (char *)0x0;
  local_28 = (char *)0x0;
  local_30 = (char *)0x0;
  local_38 = (char *)0x0;
  local_40 = (char *)0x0;
  while (iVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x18))(param_1,&local_58,&local_60),
        -1 < iVar1) {
    iVar1 = strcmp(local_58,"type");
    if (iVar1 == 0) {
      local_10 = local_60;
    }
    else {
      iVar1 = strcmp(local_58,"obj_depth");
      if (iVar1 == 0) {
        local_18 = local_60;
      }
      else {
        iVar1 = strcmp(local_58,"obj_index");
        if (iVar1 == 0) {
          local_20 = local_60;
        }
        else {
          iVar1 = strcmp(local_58,"obj_attr_type");
          if (iVar1 == 0) {
            local_28 = local_60;
          }
          else {
            iVar1 = strcmp(local_58,"obj_attr_index");
            if (iVar1 != 0) {
              iVar1 = strcmp(local_58,"obj_attr_name");
              if (iVar1 == 0) {
                local_30 = local_60;
              }
              else {
                iVar1 = strcmp(local_58,"obj_attr_oldvalue");
                if (iVar1 == 0) {
                  local_38 = local_60;
                }
                else {
                  iVar1 = strcmp(local_58,"obj_attr_newvalue");
                  if (iVar1 != 0) {
                    iVar1 = FUN_00268e49();
                    if (iVar1 != 0) {
                      fprintf(*(FILE **)PTR_stderr_0032efe0,
                              "%s: ignoring unknown diff attribute %s\n",
                              *(undefined8 *)(*(long *)(param_1 + 8) + 0x48),local_58);
                    }
                    return 0xffffffff;
                  }
                  local_40 = local_60;
                }
              }
            }
          }
        }
      }
    }
  }
  if ((local_10 == (char *)0x0) || (iVar1 = atoi(local_10), iVar1 != 0)) goto LAB_0026f103;
  if ((local_18 == (char *)0x0) || ((local_20 == (char *)0x0 || (local_28 == (char *)0x0)))) {
    iVar1 = FUN_00268e49();
    if (iVar1 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: missing mandatory obj attr generic attributes\n",
              *(undefined8 *)(*(long *)(param_1 + 8) + 0x48));
    }
    goto LAB_0026f103;
  }
  if ((local_38 == (char *)0x0) || (local_40 == (char *)0x0)) {
    iVar1 = FUN_00268e49();
    if (iVar1 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: missing mandatory obj attr value attributes\n",
              *(undefined8 *)(*(long *)(param_1 + 8) + 0x48));
    }
    goto LAB_0026f103;
  }
  local_44 = atoi(local_28);
  if ((local_44 == 2) && (local_30 == (char *)0x0)) {
    iVar1 = FUN_00268e49();
    if (iVar1 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: missing mandatory obj attr info name attribute\n",
              *(undefined8 *)(*(long *)(param_1 + 8) + 0x48));
    }
    goto LAB_0026f103;
  }
  local_50 = malloc(0x38);
  if (local_50 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *local_50 = 0;
  iVar1 = atoi(local_18);
  local_50[4] = iVar1;
  iVar1 = atoi(local_20);
  local_50[5] = iVar1;
  memset(local_50 + 6,0,0x20);
  local_50[6] = local_44;
  if (local_44 == 1) {
LAB_0026f08c:
    pcVar3 = strdup(local_38);
    *(char **)(local_50 + 10) = pcVar3;
    pcVar3 = strdup(local_40);
    *(char **)(local_50 + 0xc) = pcVar3;
  }
  else if (local_44 == 0) {
    uVar2 = strtoull(local_38,(char **)0x0,0);
    *(ulonglong *)(local_50 + 10) = uVar2;
    uVar2 = strtoull(local_40,(char **)0x0,0);
    *(ulonglong *)(local_50 + 0xc) = uVar2;
  }
  else if (local_44 == 2) {
    pcVar3 = strdup(local_30);
    *(char **)(local_50 + 8) = pcVar3;
    goto LAB_0026f08c;
  }
  if (*param_2 == 0) {
    *param_2 = (long)local_50;
  }
  else {
    *(undefined4 **)(*param_3 + 8) = local_50;
  }
  *param_3 = (long)local_50;
  *(undefined8 *)(local_50 + 2) = 0;
LAB_0026f103:
  uVar4 = (**(code **)(*(long *)(param_1 + 8) + 0x28))(param_1);
  return uVar4;
}


// ===== 0026f11a FUN_0026f11a =====

int FUN_0026f11a(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined1 local_58 [48];
  char *local_28;
  undefined8 local_20;
  undefined8 local_18;
  int local_c;
  
  local_18 = 0;
  local_20 = 0;
  *param_2 = 0;
  while( true ) {
    local_c = (**(code **)(*(long *)(param_1 + 8) + 0x20))(param_1,local_58,&local_28);
    if (local_c < 0) {
      return -1;
    }
    if (local_c == 0) break;
    iVar1 = strcmp(local_28,"diff");
    if (iVar1 == 0) {
      local_c = FUN_0026eccc(local_58,&local_18,&local_20);
    }
    else {
      local_c = -1;
    }
    if (local_c < 0) {
      return local_c;
    }
    (**(code **)(*(long *)(param_1 + 8) + 0x30))(local_58);
  }
  *param_2 = local_18;
  return 0;
}


// ===== 0026f1eb FUN_0026f1eb =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0026f1eb(undefined8 param_1,int param_2,long param_3,long param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  float fVar3;
  double dVar4;
  float local_4c;
  char local_48 [32];
  float local_28;
  float local_24;
  char *local_20;
  float local_14;
  int local_10;
  uint local_c;
  
  local_14 = DAT_002f1230;
  local_20 = getenv("HWLOC_XML_V1DIST_SCALE");
  if (local_20 == (char *)0x0) {
    local_10 = 1;
    for (local_c = 0; local_c < (uint)(param_2 * param_2); local_c = local_c + 1) {
      local_24 = *(float *)(param_3 + (ulong)local_c * 4);
      if (local_24 < 0.0) {
        local_10 = 0;
        break;
      }
      local_28 = modff(local_24,&local_4c);
      if ((_DAT_002f1234 < local_28) && (local_28 < DAT_002f1238)) {
        local_10 = 0;
        break;
      }
      *(long *)(param_4 + (ulong)local_c * 8) = (long)(int)(DAT_002f123c + local_24);
    }
    if (local_10 != 0) {
      return;
    }
  }
  else {
    dVar4 = atof(local_20);
    local_14 = (float)dVar4;
  }
  for (local_c = 0; local_c < (uint)(param_2 * param_2); local_c = local_c + 1) {
    fVar3 = *(float *)(param_3 + (ulong)local_c * 4) * local_14;
    if (DAT_002f1240 <= fVar3) {
      uVar1 = (long)(fVar3 - DAT_002f1240) ^ 0x8000000000000000;
    }
    else {
      uVar1 = (ulong)fVar3;
    }
    *(ulong *)((ulong)local_c * 8 + param_4) = uVar1;
  }
  sprintf(local_48,"%f",(double)local_14);
  uVar2 = FUN_00268b6a(param_1);
  FUN_0024dfb5(uVar2,"xmlv1DistancesScale",local_48);
  return;
}


// ===== 0026f3d1 FUN_0026f3d1 =====

undefined8 FUN_0026f3d1(long param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  int local_d4;
  char *local_d0;
  undefined1 local_c8 [48];
  undefined1 local_98 [8];
  undefined8 *local_90;
  void *local_68;
  void *local_60;
  uint local_54;
  undefined8 *local_50;
  int local_44;
  undefined8 *local_40;
  long local_38;
  uint local_2c;
  long local_28;
  undefined8 *local_20;
  long local_18;
  long local_10;
  
  local_38 = *(long *)(param_1 + 8);
  local_90 = *(undefined8 **)(param_1 + 0x38);
  local_10 = *(long *)**(undefined8 **)(local_38 + 0x18);
  local_d4 = 0;
  local_40 = local_90;
  if (*param_2 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("dstatus->phase == HWLOC_DISC_PHASE_GLOBAL",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                  ,0x821,"hwloc_look_xml");
  }
  if (*(long *)(local_10 + 0xb8) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!root->cpuset",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                  ,0x825,"hwloc_look_xml");
  }
  *(undefined4 *)(local_90 + 0xc) = 0;
  local_90[0xe] = 0;
  local_90[0xd] = local_90[0xe];
  local_90[0x10] = 0;
  local_90[0xf] = local_90[0x10];
  local_44 = (*(code *)*local_90)(local_90,local_98);
  if (-1 < local_44) {
    if (2 < *(uint *)(local_40 + 0xb)) {
      iVar2 = FUN_00268e49();
      if (iVar2 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: cannot import XML version %u.%u > 2\n",
                local_40[9],(ulong)*(uint *)(local_40 + 0xb),(ulong)*(uint *)((long)local_40 + 0x5c)
               );
      }
      goto LAB_0026fcc1;
    }
    local_44 = (*(code *)local_90[4])(local_98,local_c8,&local_d0);
    if ((((-1 < local_44) && (local_44 != 0)) && (iVar2 = strcmp(local_d0,"object"), iVar2 == 0)) &&
       (local_44 = FUN_0026b826(local_38,local_40,0,local_10,&local_d4,local_c8), -1 < local_44)) {
      (*(code *)local_90[6])(local_c8);
      if (local_d4 != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!gotignored",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                      ,0x842,"hwloc_look_xml");
      }
      local_10 = *(long *)**(undefined8 **)(local_38 + 0x18);
      if (*(uint *)(local_40 + 0xb) < 2) {
LAB_0026f826:
        (*(code *)local_90[5])(local_98);
LAB_0026f840:
        if (*(long *)(local_10 + 0xb8) == 0) {
          iVar2 = FUN_00268e49();
          if (iVar2 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid root object without cpuset\n",
                    local_40[9]);
          }
        }
        else {
          if ((*(uint *)(local_40 + 0xb) < 2) && (local_40[0xd] != 0)) {
            local_18 = local_40[0xd];
            do {
              if ((**(int **)(local_18 + 0x48) == 0xc) &&
                 (*(long *)(*(long *)(local_18 + 0x48) + 0xf0) == 0)) {
                lVar1 = *(long *)(local_38 + 0xe0);
                *(long *)(local_38 + 0xe0) = lVar1 + 1;
                *(long *)(*(long *)(local_18 + 0x48) + 0xf0) = lVar1;
              }
              local_18 = *(long *)(local_18 + 0x38);
            } while (local_18 != 0);
          }
          if ((*(uint *)(local_40 + 0xb) < 2) && (local_40[0xf] != 0)) {
            local_20 = (undefined8 *)local_40[0xf];
            while( true ) {
              local_50 = local_20;
              if (local_20 == (undefined8 *)0x0) break;
              local_54 = *(uint *)(local_20 + 1);
              local_20 = (undefined8 *)local_20[4];
              if ((local_54 == *(uint *)(local_40 + 0xc)) &&
                 ((*(ulong *)(local_38 + 0x20) & 0x80) == 0)) {
                local_60 = malloc((ulong)local_54 << 3);
                local_68 = malloc((ulong)(local_54 * local_54) << 3);
                if (*(int *)(local_40 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
                  __assert_fail("data->nbnumanodes > 0",
                                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                                ,0x894,"hwloc_look_xml");
                }
                if (local_40[0xd] == 0) {
                    /* WARNING: Subroutine does not return */
                  __assert_fail("data->first_numanode",
                                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                                ,0x895,"hwloc_look_xml");
                }
                if ((local_60 == (void *)0x0) || (local_68 == (void *)0x0)) {
                  free(local_60);
                  free(local_68);
                }
                else {
                  local_2c = 0;
                  local_28 = local_40[0xd];
                  for (; local_2c < local_54; local_2c = local_2c + 1) {
                    *(long *)((ulong)local_2c * 8 + (long)local_60) = local_28;
                    local_28 = *(long *)(local_28 + 0x38);
                  }
                  FUN_0026f1eb(local_38,local_54,local_50[2],local_68);
                  FUN_00259d57(local_38,0,local_54,local_60,local_68,*local_50,0);
                }
              }
              free((void *)local_50[2]);
              free(local_50);
            }
            local_40[0x10] = 0;
            local_40[0xf] = local_40[0x10];
          }
          if (*(uint *)(local_40 + 0xb) < 2) {
LAB_0026fbb8:
            FUN_002531e1(local_10);
            if ((*(ulong *)(local_38 + 0x20) & 8) == 0) {
              **(undefined1 **)(local_38 + 0x288) = 1;
              *(undefined1 *)(*(long *)(local_38 + 0x288) + 3) = 1;
              if (*(int *)(local_40 + 0xc) != 0) {
                *(undefined1 *)(*(long *)(local_38 + 0x288) + 1) = 1;
                *(undefined1 *)(*(long *)(local_38 + 0x288) + 2) = 1;
                *(undefined1 *)(*(long *)(local_38 + 0x288) + 4) = 1;
              }
            }
            if (local_40[1] != 0) {
              (*(code *)local_40[1])(local_40,0);
            }
            return 0;
          }
          if (*(long *)(local_10 + 200) == 0) {
            iVar2 = FUN_00268e49();
            if (iVar2 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid root object without nodeset\n",
                      local_40[9]);
            }
          }
          else {
            iVar2 = FUN_002620a3(*(undefined8 *)(local_10 + 200));
            if (iVar2 == 0) goto LAB_0026fbb8;
            iVar2 = FUN_00268e49();
            if (iVar2 != 0) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: invalid root object with empty nodeset\n",
                      local_40[9]);
            }
          }
        }
        goto LAB_0026fcc1;
      }
      while (local_44 = (*(code *)local_90[4])(local_98,local_c8,&local_d0), -1 < local_44) {
        if (local_44 == 0) goto LAB_0026f826;
        iVar2 = strcmp(local_d0,"distances2");
        if (iVar2 == 0) {
          local_44 = FUN_0026d548(local_38,local_c8,0);
        }
        else {
          iVar2 = strcmp(local_d0,"distances2hetero");
          if (iVar2 == 0) {
            local_44 = FUN_0026d548(local_38,local_c8,1);
          }
          else {
            iVar2 = strcmp(local_d0,"support");
            if (iVar2 == 0) {
              local_44 = FUN_0026ce9b(local_38,local_c8);
            }
            else {
              iVar2 = strcmp(local_d0,"memattr");
              if (iVar2 == 0) {
                local_44 = FUN_0026e74f(local_38,local_c8);
              }
              else {
                iVar2 = strcmp(local_d0,"cpukind");
                if (iVar2 != 0) {
                  iVar2 = FUN_00268e49();
                  if (iVar2 != 0) {
                    fprintf(*(FILE **)PTR_stderr_0032efe0,
                            "%s: ignoring unknown tag `%s\' after root object.\n",local_40[9],
                            local_d0);
                  }
                  goto LAB_0026f840;
                }
                local_44 = FUN_0026e9ac(local_38,local_c8);
              }
            }
          }
        }
        if (local_44 < 0) break;
        (*(code *)local_90[6])(local_c8);
      }
    }
  }
  if (local_40[1] != 0) {
    (*(code *)local_40[1])(local_40,0xffffffff);
  }
  iVar2 = FUN_00268e49();
  if (iVar2 != 0) {
    fprintf(*(FILE **)PTR_stderr_0032efe0,"%s: XML component discovery failed.\n",local_40[9]);
  }
LAB_0026fcc1:
  FUN_0024e34c(*(undefined8 *)(local_10 + 0x78));
  *(undefined8 *)(local_10 + 0x78) = 0;
  FUN_0024e34c(*(undefined8 *)(local_10 + 0x90));
  *(undefined8 *)(local_10 + 0x90) = 0;
  FUN_0024e34c(*(undefined8 *)(local_10 + 0xa0));
  *(undefined8 *)(local_10 + 0xa0) = 0;
  FUN_0024e34c(*(undefined8 *)(local_10 + 0xb0));
  *(undefined8 *)(local_10 + 0xb0) = 0;
  if (*(long *)(local_10 + 0xb8) != 0) {
    FUN_0026180c(*(undefined8 *)(local_10 + 0xb8));
  }
  if (*(long *)(local_10 + 200) != 0) {
    FUN_0026180c(*(undefined8 *)(local_10 + 200));
  }
  return 0xffffffff;
}


// ===== 0026fd90 FUN_0026fd90 =====

char * FUN_0026fd90(char *param_1)

{
  size_t sVar1;
  char *pcVar2;
  char *local_18;
  char *local_10;
  
  sVar1 = strlen(param_1);
  pcVar2 = malloc(sVar1 + 1);
  local_18 = param_1;
  local_10 = pcVar2;
  if (pcVar2 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    for (; *local_18 != '\0'; local_18 = local_18 + 1) {
      if (((('\x1f' < *local_18) && (*local_18 != '\x7f')) || (*local_18 == '\t')) ||
         ((*local_18 == '\n' || (*local_18 == '\r')))) {
        *local_10 = *local_18;
        local_10 = local_10 + 1;
      }
    }
    *local_10 = '\0';
  }
  return pcVar2;
}


// ===== 0026fe3f FUN_0026fe3f =====

void FUN_0026fe3f(long param_1,long param_2,int *param_3,uint param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 local_288 [8];
  code *local_280;
  code *local_278;
  code *local_268;
  undefined1 local_228 [16];
  code *local_218;
  code *local_208;
  char local_1c8 [264];
  void *local_c0;
  void *local_b8;
  void *local_b0;
  void *local_a8;
  uint local_9c;
  void *local_98;
  uint local_90;
  int local_8c;
  void *local_88;
  void *local_80;
  void *local_78;
  undefined8 local_70;
  undefined8 local_68;
  uint local_5c;
  long local_58;
  int local_4c;
  undefined4 *local_48;
  uint local_3c;
  long local_38;
  int *local_30;
  int local_24;
  uint local_20;
  uint local_1c;
  
  local_b8 = (void *)0x0;
  local_c0 = (void *)0x0;
  local_5c = param_4 & 1;
  if (((param_4 & 1) == 0) || (*param_3 != 1)) {
    if (((param_4 & 1) == 0) || (*param_3 != 0x13)) {
      if (((param_4 & 1) == 0) || (iVar3 = FUN_00268e28(*param_3), iVar3 == 0)) {
        pcVar1 = *(code **)(param_1 + 0x10);
        uVar5 = FUN_002582d8(*param_3);
        (*pcVar1)(param_1,&DAT_002ef02a,uVar5);
      }
      else {
        (**(code **)(param_1 + 0x10))(param_1,&DAT_002ef02a,"Cache");
      }
    }
    else {
      (**(code **)(param_1 + 0x10))(param_1,&DAT_002ef02a,"Group");
    }
  }
  else {
    (**(code **)(param_1 + 0x10))(param_1,&DAT_002ef02a,"Socket");
  }
  if (param_3[4] != -1) {
    sprintf(local_1c8,"%u",(ulong)(uint)param_3[4]);
    (**(code **)(param_1 + 0x10))(param_1,"os_index",local_1c8);
  }
  if (*(long *)(param_3 + 0x2e) != 0) {
    local_24 = 0;
    if ((local_5c != 0) && (piVar2 = param_3, *param_3 == 0xd)) {
      while (local_30 = piVar2, iVar3 = FUN_00258198(*local_30), iVar3 == 0) {
        if (local_30[0x14] != 0) {
          local_24 = 1;
          break;
        }
        piVar2 = *(int **)(local_30 + 0x12);
      }
    }
    if (local_24 == 0) {
      FUN_00261562(&local_b8,*(undefined8 *)(param_3 + 0x2e));
      (**(code **)(param_1 + 0x10))(param_1,"cpuset",local_b8);
      FUN_00261562(&local_c0,*(undefined8 *)(param_3 + 0x30));
      (**(code **)(param_1 + 0x10))(param_1,"complete_cpuset",local_c0);
      free(local_c0);
      if (local_5c != 0) {
        (**(code **)(param_1 + 0x10))(param_1,"online_cpuset",local_b8);
      }
      free(local_b8);
      if (local_5c == 0) {
        if (*(long *)(param_3 + 0x12) == 0) {
          FUN_00261562(&local_b8,*(undefined8 *)(param_2 + 0x1b8));
          (**(code **)(param_1 + 0x10))(param_1,"allowed_cpuset",local_b8);
          free(local_b8);
        }
      }
      else {
        local_68 = FUN_002611e2(*(undefined8 *)(param_3 + 0x2e));
        FUN_002626c1(local_68,local_68,*(undefined8 *)(param_2 + 0x1b8));
        FUN_00261562(&local_b8,local_68);
        (**(code **)(param_1 + 0x10))(param_1,"allowed_cpuset",local_b8);
        free(local_b8);
        FUN_00260f71(local_68);
      }
    }
    else {
      (**(code **)(param_1 + 0x10))(param_1,"cpuset",&DAT_002f10b9);
      (**(code **)(param_1 + 0x10))(param_1,"online_cpuset",&DAT_002f10b9);
      (**(code **)(param_1 + 0x10))(param_1,"complete_cpuset",&DAT_002f10b9);
      (**(code **)(param_1 + 0x10))(param_1,"allowed_cpuset",&DAT_002f10b9);
    }
    FUN_00261562(&local_b8,*(undefined8 *)(param_3 + 0x32));
    (**(code **)(param_1 + 0x10))(param_1,"nodeset",local_b8);
    free(local_b8);
    FUN_00261562(&local_b8,*(undefined8 *)(param_3 + 0x34));
    (**(code **)(param_1 + 0x10))(param_1,"complete_nodeset",local_b8);
    free(local_b8);
    if (local_5c == 0) {
      if (*(long *)(param_3 + 0x12) == 0) {
        FUN_00261562(&local_b8,*(undefined8 *)(param_2 + 0x1c0));
        (**(code **)(param_1 + 0x10))(param_1,"allowed_nodeset",local_b8);
        free(local_b8);
      }
    }
    else {
      local_70 = FUN_002611e2(*(undefined8 *)(param_3 + 0x32));
      FUN_002626c1(local_70,local_70,*(undefined8 *)(param_2 + 0x1c0));
      FUN_00261562(&local_b8,local_70);
      (**(code **)(param_1 + 0x10))(param_1,"allowed_nodeset",local_b8);
      free(local_b8);
      FUN_00260f71(local_70);
    }
  }
  if (local_5c == 0) {
    sprintf(local_1c8,"%llu",*(undefined8 *)(param_3 + 0x3c));
    (**(code **)(param_1 + 0x10))(param_1,"gp_index",local_1c8);
  }
  if ((*(long *)(param_3 + 6) != 0) &&
     (local_78 = (void *)FUN_0026fd90(*(undefined8 *)(param_3 + 6)), local_78 != (void *)0x0)) {
    (**(code **)(param_1 + 0x10))(param_1,&DAT_002ef149,local_78);
    free(local_78);
  }
  if (((local_5c == 0) && (*(long *)(param_3 + 2) != 0)) &&
     (local_80 = (void *)FUN_0026fd90(*(undefined8 *)(param_3 + 2)), local_80 != (void *)0x0)) {
    (**(code **)(param_1 + 0x10))(param_1,"subtype",local_80);
    free(local_80);
  }
  switch(*param_3) {
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0x12:
    sprintf(local_1c8,"%llu",**(undefined8 **)(param_3 + 10));
    (**(code **)(param_1 + 0x10))(param_1,"cache_size",local_1c8);
    sprintf(local_1c8,"%u",(ulong)*(uint *)(*(long *)(param_3 + 10) + 8));
    (**(code **)(param_1 + 0x10))(param_1,"depth",local_1c8);
    sprintf(local_1c8,"%u",(ulong)*(uint *)(*(long *)(param_3 + 10) + 0xc));
    (**(code **)(param_1 + 0x10))(param_1,"cache_linesize",local_1c8);
    sprintf(local_1c8,"%d",(ulong)*(uint *)(*(long *)(param_3 + 10) + 0x10));
    (**(code **)(param_1 + 0x10))(param_1,"cache_associativity",local_1c8);
    sprintf(local_1c8,"%d",(ulong)*(uint *)(*(long *)(param_3 + 10) + 0x14));
    (**(code **)(param_1 + 0x10))(param_1,"cache_type",local_1c8);
    break;
  case 0xc:
    if (local_5c == 0) {
      sprintf(local_1c8,"%u",(ulong)*(uint *)(*(long *)(param_3 + 10) + 4));
      (**(code **)(param_1 + 0x10))(param_1,&DAT_002ef374,local_1c8);
      sprintf(local_1c8,"%u",(ulong)*(uint *)(*(long *)(param_3 + 10) + 8));
      (**(code **)(param_1 + 0x10))(param_1,"subkind",local_1c8);
      if (*(char *)(*(long *)(param_3 + 10) + 0xc) != '\0') {
        (**(code **)(param_1 + 0x10))(param_1,"dont_merge",&DAT_002f10c5);
      }
    }
    else {
      sprintf(local_1c8,"%u",(ulong)**(uint **)(param_3 + 10));
      (**(code **)(param_1 + 0x10))(param_1,"depth",local_1c8);
      if (*(char *)(*(long *)(param_3 + 10) + 0xc) != '\0') {
        (**(code **)(param_1 + 0x10))(param_1,"dont_merge",&DAT_002f10c5);
      }
    }
    break;
  case 0xd:
    if (**(long **)(param_3 + 10) != 0) {
      sprintf(local_1c8,"%llu",**(undefined8 **)(param_3 + 10));
      (**(code **)(param_1 + 0x10))(param_1,"local_memory",local_1c8);
    }
    for (local_1c = 0; local_1c < *(uint *)(*(long *)(param_3 + 10) + 8); local_1c = local_1c + 1) {
      (**(code **)(param_1 + 8))(param_1,local_228,"page_type");
      sprintf(local_1c8,"%llu",
              *(undefined8 *)(*(long *)(*(long *)(param_3 + 10) + 0x10) + (ulong)local_1c * 0x10));
      (*local_218)(local_228,&DAT_002efb08,local_1c8);
      sprintf(local_1c8,"%llu",
              *(undefined8 *)
               (*(long *)(*(long *)(param_3 + 10) + 0x10) + (ulong)local_1c * 0x10 + 8));
      (*local_218)(local_228,"count",local_1c8);
      (*local_208)(local_228,"page_type");
    }
    break;
  case 0xe:
    sprintf(local_1c8,"%d-%d",(ulong)*(uint *)(*(long *)(param_3 + 10) + 0x18),
            (ulong)*(uint *)(*(long *)(param_3 + 10) + 0x20));
    (**(code **)(param_1 + 0x10))(param_1,"bridge_type",local_1c8);
    sprintf(local_1c8,"%u",(ulong)*(uint *)(*(long *)(param_3 + 10) + 0x24));
    (**(code **)(param_1 + 0x10))(param_1,"depth",local_1c8);
    if (*(int *)(*(long *)(param_3 + 10) + 0x20) == 1) {
      sprintf(local_1c8,"%04x:[%02x-%02x]",(ulong)*(ushort *)(*(long *)(param_3 + 10) + 0x1c),
              (ulong)*(byte *)(*(long *)(param_3 + 10) + 0x1e),
              (ulong)*(byte *)(*(long *)(param_3 + 10) + 0x1f));
      (**(code **)(param_1 + 0x10))(param_1,"bridge_pci",local_1c8);
    }
    if (*(int *)(*(long *)(param_3 + 10) + 0x18) != 1) break;
  case 0xf:
    sprintf(local_1c8,"%04x:%02x:%02x.%01x",(ulong)**(ushort **)(param_3 + 10),
            (ulong)*(byte *)(*(long *)(param_3 + 10) + 2),
            (ulong)*(byte *)(*(long *)(param_3 + 10) + 3),
            (ulong)*(byte *)(*(long *)(param_3 + 10) + 4));
    (**(code **)(param_1 + 0x10))(param_1,"pci_busid",local_1c8);
    sprintf(local_1c8,"%04x [%04x:%04x] [%04x:%04x] %02x",
            (ulong)*(ushort *)(*(long *)(param_3 + 10) + 6),
            (ulong)*(ushort *)(*(long *)(param_3 + 10) + 8),
            (ulong)*(ushort *)(*(long *)(param_3 + 10) + 10),
            (ulong)*(ushort *)(*(long *)(param_3 + 10) + 0xc),
            (ulong)*(ushort *)(*(long *)(param_3 + 10) + 0xe),
            (ulong)*(byte *)(*(long *)(param_3 + 10) + 0x10));
    (**(code **)(param_1 + 0x10))(param_1,"pci_type",local_1c8);
    sprintf(local_1c8,"%f",(double)*(float *)(*(long *)(param_3 + 10) + 0x14));
    (**(code **)(param_1 + 0x10))(param_1,"pci_link_speed",local_1c8);
    break;
  case 0x10:
    sprintf(local_1c8,"%d",(ulong)**(uint **)(param_3 + 10));
    (**(code **)(param_1 + 0x10))(param_1,"osdev_type",local_1c8);
    break;
  default:
  }
  for (local_1c = 0; local_1c < (uint)param_3[0x38]; local_1c = local_1c + 1) {
    local_a8 = (void *)FUN_0026fd90(*(undefined8 *)
                                     (*(long *)(param_3 + 0x36) + (ulong)local_1c * 0x10));
    local_b0 = (void *)FUN_0026fd90(*(undefined8 *)
                                     (*(long *)(param_3 + 0x36) + (ulong)local_1c * 0x10 + 8));
    if ((local_a8 != (void *)0x0) && (local_b0 != (void *)0x0)) {
      (**(code **)(param_1 + 8))(param_1,local_228,&DAT_002effaa);
      (*local_218)(local_228,&DAT_002ef149,local_a8);
      (*local_218)(local_228,"value",local_b0);
      (*local_208)(local_228,&DAT_002effaa);
    }
    free(local_a8);
    free(local_b0);
  }
  if (((local_5c != 0) && (*(long *)(param_3 + 2) != 0)) &&
     (local_88 = (void *)FUN_0026fd90(*(undefined8 *)(param_3 + 2)), local_88 != (void *)0x0)) {
    if ((*param_3 == 0x10) && (**(int **)(param_3 + 10) == 5)) {
      local_8c = 1;
    }
    else {
      local_8c = 0;
    }
    (**(code **)(param_1 + 8))(param_1,local_228,&DAT_002effaa);
    if (local_8c == 0) {
      pcVar6 = "Type";
    }
    else {
      pcVar6 = "CoProcType";
    }
    (*local_218)(local_228,&DAT_002ef149,pcVar6);
    (*local_218)(local_228,"value",local_88);
    (*local_208)(local_228,&DAT_002effaa);
    free(local_88);
  }
  if ((local_5c != 0) && (*param_3 == 0x13)) {
    (**(code **)(param_1 + 8))(param_1,local_228,&DAT_002effaa);
    (*local_218)(local_228,&DAT_002ef149,&DAT_002efaf8);
    (*local_218)(local_228,"value",&DAT_002f021a);
    (*local_208)(local_228,&DAT_002effaa);
  }
  if ((local_5c != 0) && (*(long *)(param_3 + 0x12) == 0)) {
    FUN_0025a1b0(param_2);
    for (local_38 = *(long *)(param_2 + 0x2c0); local_38 != 0; local_38 = *(long *)(local_38 + 0x50)
        ) {
      local_90 = *(uint *)(local_38 + 0x18);
      uVar4 = FUN_00268b1a(param_2,*(undefined4 *)(local_38 + 0xc));
      if (((local_90 == uVar4) && ((*(ulong *)(local_38 + 0x30) & 4) != 0)) &&
         ((*(ulong *)(local_38 + 0x30) & 0x10) == 0)) {
        local_98 = malloc((ulong)local_90 << 2);
        if (local_98 == (void *)0x0) {
          iVar3 = FUN_0024d64f();
          if (iVar3 == 0) {
            fwrite("hwloc/xml/export/v1: failed to allocated logical_to_v2array\n",1,0x3c,
                   *(FILE **)PTR_stderr_0032efe0);
          }
        }
        else {
          for (local_1c = 0; local_1c < local_90; local_1c = local_1c + 1) {
            *(uint *)((ulong)*(uint *)(*(long *)(*(long *)(local_38 + 0x40) + (ulong)local_1c * 8) +
                                      0x34) * 4 + (long)local_98) = local_1c;
          }
          if (*(int *)(local_38 + 0xc) == 0xd) {
            local_3c = 0xffffffff;
            for (local_1c = 0; local_1c < local_90; local_1c = local_1c + 1) {
              local_48 = *(undefined4 **)
                          (*(long *)(*(long *)(local_38 + 0x40) + (ulong)local_1c * 8) + 0x48);
              while (iVar3 = FUN_00268dc5(*local_48), iVar3 != 0) {
                local_48 = *(undefined4 **)(local_48 + 0x12);
              }
              if ((int)local_3c < local_48[0xc] + 1) {
                local_3c = local_48[0xc] + 1;
              }
            }
          }
          else {
            local_4c = 0;
            for (local_1c = 0; local_1c < local_90; local_1c = local_1c + 1) {
              for (local_58 = *(long *)(*(long *)(*(long *)(local_38 + 0x40) + (ulong)local_1c * 8)
                                       + 0x48); local_58 != 0; local_58 = *(long *)(local_58 + 0x48)
                  ) {
                if (*(long *)(local_58 + 0x90) != 0) {
                  local_4c = 1;
                  goto LAB_00271279;
                }
              }
            }
LAB_00271279:
            iVar3 = FUN_00257fb0(param_2,*(undefined4 *)(local_38 + 0xc));
            local_3c = local_4c + iVar3;
          }
          (**(code **)(param_1 + 8))(param_1,local_288,"distances");
          sprintf(local_1c8,"%u",(ulong)local_90);
          (*local_278)(local_288,"nbobjs",local_1c8);
          sprintf(local_1c8,"%d",(ulong)local_3c);
          (*local_278)(local_288,"relative_depth",local_1c8);
          sprintf(local_1c8,"%f",DAT_002f1248);
          (*local_278)(local_288,"latency_base",local_1c8);
          for (local_1c = 0; local_1c < local_90; local_1c = local_1c + 1) {
            for (local_20 = 0; local_20 < local_90; local_20 = local_20 + 1) {
              local_9c = *(int *)((long)local_98 + (ulong)local_20 * 4) +
                         *(int *)((long)local_98 + (ulong)local_1c * 4) * local_90;
              (*local_280)(local_288,local_228,"latency");
              sprintf(local_1c8,"%f",
                      (double)*(ulong *)(*(long *)(local_38 + 0x28) + (ulong)local_9c * 8));
              (*local_218)(local_228,"value",local_1c8);
              (*local_208)(local_228,"latency");
            }
          }
          (*local_268)(local_288,"distances");
          free(local_98);
        }
      }
    }
  }
  if ((*(long *)(param_3 + 0x3a) != 0) && (*(long *)(param_2 + 0x2a8) != 0)) {
    (**(code **)(param_2 + 0x2a8))(param_1,param_2,param_3);
  }
  return;
}


// ===== 00271565 FUN_00271565 =====

void FUN_00271565(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined1 local_68 [32];
  code *local_48;
  long local_10;
  
  (**(code **)(param_1 + 8))(param_1,local_68,"object");
  FUN_0026fe3f(local_68,param_2,param_3,param_4);
  for (local_10 = *(long *)(param_3 + 0x90); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00271565(local_68,param_2,local_10,param_4);
  }
  for (local_10 = *(long *)(param_3 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00271565(local_68,param_2,local_10,param_4);
  }
  for (local_10 = *(long *)(param_3 + 0xa0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00271565(local_68,param_2,local_10,param_4);
  }
  for (local_10 = *(long *)(param_3 + 0xb0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00271565(local_68,param_2,local_10,param_4);
  }
  (*local_48)(local_68,"object");
  return;
}


// ===== 002716b5 FUN_002716b5 =====

int * FUN_002716b5(long param_1,long param_2)

{
  int *local_28;
  long local_10;
  
  local_10 = param_2;
  if (param_2 == 0) {
    local_28 = *(int **)(param_1 + 0x90);
LAB_0027172e:
    for (; *local_28 != 0xd; local_28 = *(int **)(local_28 + 0x24)) {
    }
    if (local_28 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("cur",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                    ,0xae6,"hwloc__xml_v1export_object_next_numanode");
    }
  }
  else {
    do {
      if (*(long *)(local_10 + 0x58) != 0) {
        local_28 = *(int **)(local_10 + 0x58);
        goto LAB_0027172e;
      }
      local_10 = *(long *)(local_10 + 0x48);
    } while (local_10 != param_1);
    local_28 = (int *)0x0;
  }
  return local_28;
}


// ===== 00271765 FUN_00271765 =====

int FUN_00271765(long param_1,long *param_2,undefined8 *param_3)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  int local_14;
  long local_10;
  
  if (*(long *)(param_1 + 0x90) == 0) {
    *param_2 = 0;
    *param_3 = 0;
    local_14 = 0;
  }
  else {
    iVar1 = FUN_00262e86(*(undefined8 *)(param_1 + 200));
    if (iVar1 < 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("nr > 0",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                    ,0xaf8,"hwloc__xml_v1export_object_list_numanodes");
    }
    plVar2 = calloc((long)iVar1,8);
    if (plVar2 == (long *)0x0) {
      lVar3 = FUN_002716b5(param_1,0);
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("cur",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                      ,0xaff,"hwloc__xml_v1export_object_list_numanodes");
      }
      *param_2 = lVar3;
      *param_3 = 0;
      local_14 = 1;
    }
    else {
      local_14 = 0;
      local_10 = 0;
      while( true ) {
        local_10 = FUN_002716b5(param_1,local_10);
        if (local_10 == 0) break;
        plVar2[local_14] = local_10;
        local_14 = local_14 + 1;
      }
      *param_2 = *plVar2;
      *param_3 = plVar2;
    }
  }
  return local_14;
}


// ===== 002718c8 FUN_002718c8 =====

void FUN_002718c8(undefined1 *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined8 local_158;
  void *local_150;
  undefined1 local_148 [32];
  code *local_128;
  undefined1 local_e8 [8];
  code *local_e0;
  code *local_c8;
  undefined1 local_88 [32];
  code *local_68;
  long local_28;
  uint local_20;
  uint local_1c;
  long local_18;
  undefined1 *local_10;
  
  local_10 = param_1;
  local_20 = FUN_00271765(param_3,&local_158,&local_150);
  if (((1 < *(uint *)(*(long *)(param_3 + 0x48) + 0x68)) && (1 < local_20)) &&
     (**(long **)(param_1 + 0x28) != 0)) {
    local_28 = **(long **)(param_1 + 0x28);
    (**(code **)(param_1 + 8))(param_1,local_88,"object");
    *(undefined8 *)(local_28 + 0x48) = *(undefined8 *)(param_3 + 0x48);
    *(undefined8 *)(local_28 + 0xb8) = *(undefined8 *)(param_3 + 0xb8);
    *(undefined8 *)(local_28 + 0xc0) = *(undefined8 *)(param_3 + 0xc0);
    *(undefined8 *)(local_28 + 200) = *(undefined8 *)(param_3 + 200);
    *(undefined8 *)(local_28 + 0xd0) = *(undefined8 *)(param_3 + 0xd0);
    FUN_0026fe3f(local_88,param_2,local_28,param_4);
    *(undefined8 *)(local_28 + 0xb8) = 0;
    *(undefined8 *)(local_28 + 0xc0) = 0;
    *(undefined8 *)(local_28 + 200) = 0;
    *(undefined8 *)(local_28 + 0xd0) = 0;
    local_10 = local_88;
  }
  (**(code **)(local_10 + 8))(local_10,local_e8,"object");
  FUN_0026fe3f(local_e8,param_2,local_158,param_4);
  (*local_e0)(local_e8,local_148,"object");
  FUN_0026fe3f(local_148,param_2,param_3,param_4);
  for (local_18 = *(long *)(param_3 + 0x78); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    FUN_00271c66(local_148,param_2,local_18,param_4);
  }
  for (local_18 = *(long *)(param_3 + 0xa0); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    FUN_00271c66(local_148,param_2,local_18,param_4);
  }
  for (local_18 = *(long *)(param_3 + 0xb0); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    FUN_00271c66(local_148,param_2,local_18,param_4);
  }
  (*local_128)(local_148,"object");
  (*local_c8)(local_e8,"object");
  for (local_1c = 1; local_1c < local_20; local_1c = local_1c + 1) {
    FUN_00271c66(local_10,param_2,*(undefined8 *)((long)local_150 + (ulong)local_1c * 8),param_4);
  }
  free(local_150);
  if (local_10 == local_88) {
    (*local_68)(local_88,"object");
  }
  return;
}


// ===== 00271c66 FUN_00271c66 =====

void FUN_00271c66(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined1 local_68 [32];
  code *local_48;
  long local_10;
  
  (**(code **)(param_1 + 8))(param_1,local_68,"object");
  FUN_0026fe3f(local_68,param_2,param_3,param_4);
  for (local_10 = *(long *)(param_3 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    if (*(int *)(local_10 + 0x8c) == 0) {
      FUN_00271c66(local_68,param_2,local_10,param_4);
    }
    else {
      FUN_002718c8(local_68,param_2,local_10,param_4);
    }
  }
  for (local_10 = *(long *)(param_3 + 0xa0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00271c66(local_68,param_2,local_10,param_4);
  }
  for (local_10 = *(long *)(param_3 + 0xb0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00271c66(local_68,param_2,local_10,param_4);
  }
  (*local_48)(local_68,"object");
  return;
}


// ===== 00271da2 FUN_00271da2 =====

void FUN_00271da2(long param_1,long *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 local_348 [16];
  code *local_338;
  code *local_330;
  code *local_328;
  char local_2e8 [256];
  char local_1e8 [16];
  char local_1d8 [16];
  char local_1c8 [16];
  undefined1 local_1b8 [8];
  code *local_1b0;
  code *local_1a8;
  code *local_198;
  char local_158 [264];
  uint local_50;
  uint local_4c;
  long local_48;
  uint local_40;
  uint local_3c;
  long local_38;
  uint local_30;
  uint local_2c;
  long local_28;
  uint local_1c;
  
  local_50 = *(uint *)(param_2 + 3);
  if (param_2[2] == 0) {
    (**(code **)(param_1 + 8))(param_1,local_1b8,"distances2");
    pcVar1 = local_1a8;
    uVar3 = FUN_002582d8(*(undefined4 *)((long)param_2 + 0xc));
    (*pcVar1)(local_1b8,&DAT_002ef02a,uVar3);
  }
  else {
    (**(code **)(param_1 + 8))(param_1,local_1b8,"distances2hetero");
  }
  sprintf(local_158,"%u",(ulong)local_50);
  (*local_1a8)(local_1b8,"nbobjs",local_158);
  sprintf(local_158,"%lu",param_2[6]);
  (*local_1a8)(local_1b8,&DAT_002ef374,local_158);
  if (*param_2 != 0) {
    (*local_1a8)(local_1b8,&DAT_002ef149,*param_2);
  }
  if (param_2[2] == 0) {
    if ((*(int *)((long)param_2 + 0xc) == 3) || (*(int *)((long)param_2 + 0xc) == 0xd)) {
      puVar4 = &DAT_002f07b3;
    }
    else {
      puVar4 = &DAT_002f07b6;
    }
    (*local_1a8)(local_1b8,"indexing",puVar4);
  }
  if (param_2[2] == 0) {
    local_30 = 0;
    while (local_30 < local_50) {
      local_38 = 0;
      (*local_1b0)(local_1b8,local_348,"indexes");
      for (local_3c = 0; (local_3c + local_30 < local_50 && (local_3c < 10));
          local_3c = local_3c + 1) {
        iVar2 = sprintf(local_2e8 + local_38,"%llu ",
                        *(undefined8 *)(param_2[4] + (ulong)(local_3c + local_30) * 8));
        local_38 = local_38 + iVar2;
      }
      local_30 = local_30 + local_3c;
      sprintf(local_1d8,"%lu",local_38);
      (*local_338)(local_348,"length",local_1d8);
      (*local_330)(local_348,local_2e8,local_38);
      (*local_328)(local_348,"indexes");
    }
  }
  else {
    local_1c = 0;
    while (local_1c < local_50) {
      local_28 = 0;
      (*local_1b0)(local_1b8,local_348,"indexes");
      for (local_2c = 0; (local_2c + local_1c < local_50 && (local_2c < 10));
          local_2c = local_2c + 1) {
        uVar3 = *(undefined8 *)(*(long *)(param_2[8] + (ulong)(local_2c + local_1c) * 8) + 0xf0);
        uVar5 = FUN_002582d8(**(undefined4 **)(param_2[8] + (ulong)(local_2c + local_1c) * 8));
        iVar2 = sprintf(local_2e8 + local_28,"%s:%llu ",uVar5,uVar3);
        local_28 = local_28 + iVar2;
      }
      local_1c = local_1c + local_2c;
      sprintf(local_1c8,"%lu",local_28);
      (*local_338)(local_348,"length",local_1c8);
      (*local_330)(local_348,local_2e8,local_28);
      (*local_328)(local_348,"indexes");
    }
  }
  local_40 = 0;
  while (local_40 < local_50 * local_50) {
    local_48 = 0;
    (*local_1b0)(local_1b8,local_348,"u64values");
    for (local_4c = 0; (local_40 + local_4c < local_50 * local_50 && (local_4c < 10));
        local_4c = local_4c + 1) {
      iVar2 = sprintf(local_2e8 + local_48,"%llu ",
                      *(undefined8 *)(param_2[5] + (ulong)(local_4c + local_40) * 8));
      local_48 = local_48 + iVar2;
    }
    local_40 = local_40 + local_4c;
    sprintf(local_1e8,"%lu",local_48);
    (*local_338)(local_348,"length",local_1e8);
    (*local_330)(local_348,local_2e8,local_48);
    (*local_328)(local_348,"u64values");
  }
  if (param_2[2] == 0) {
    pcVar6 = "distances2";
  }
  else {
    pcVar6 = "distances2hetero";
  }
  (*local_198)(local_1b8,pcVar6);
  return;
}


// ===== 0027237f FUN_0027237f =====

void FUN_0027237f(undefined8 param_1,long param_2)

{
  undefined8 local_10;
  
  for (local_10 = *(long *)(param_2 + 0x2c0); local_10 != 0; local_10 = *(long *)(local_10 + 0x50))
  {
    if (*(long *)(local_10 + 0x10) == 0) {
      FUN_00271da2(param_1,local_10);
    }
  }
  for (local_10 = *(long *)(param_2 + 0x2c0); local_10 != 0; local_10 = *(long *)(local_10 + 0x50))
  {
    if (*(long *)(local_10 + 0x10) != 0) {
      FUN_00271da2(param_1,local_10);
    }
  }
  return;
}


// ===== 0027241a FUN_0027241a =====

void FUN_0027241a(long param_1,long param_2)

{
  char local_73 [11];
  undefined1 local_68 [16];
  code *local_58;
  code *local_48;
  
  if (**(char **)(param_2 + 0x288) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"discovery.pu");
    if (**(char **)(param_2 + 0x288) != '\x01') {
      sprintf(local_73,"%u",(ulong)**(byte **)(param_2 + 0x288));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x288) + 1) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"discovery.numa");
    if (*(char *)(*(long *)(param_2 + 0x288) + 1) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x288) + 1));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x288) + 2) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"discovery.numa_memory");
    if (*(char *)(*(long *)(param_2 + 0x288) + 2) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x288) + 2));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x288) + 3) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"discovery.disallowed_pu");
    if (*(char *)(*(long *)(param_2 + 0x288) + 3) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x288) + 3));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x288) + 4) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"discovery.disallowed_numa");
    if (*(char *)(*(long *)(param_2 + 0x288) + 4) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x288) + 4));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x288) + 5) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"discovery.cpukind_efficiency");
    if (*(char *)(*(long *)(param_2 + 0x288) + 5) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x288) + 5));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (**(char **)(param_2 + 0x290) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.set_thisproc_cpubind");
    if (**(char **)(param_2 + 0x290) != '\x01') {
      sprintf(local_73,"%u",(ulong)**(byte **)(param_2 + 0x290));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 1) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_thisproc_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 1) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 1));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 2) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.set_proc_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 2) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 2));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 3) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_proc_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 3) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 3));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 4) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.set_thisthread_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 4) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 4));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 5) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_thisthread_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 5) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 5));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 6) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.set_thread_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 6) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 6));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 7) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_thread_cpubind");
    if (*(char *)(*(long *)(param_2 + 0x290) + 7) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 7));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 8) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_thisproc_last_cpu_location");
    if (*(char *)(*(long *)(param_2 + 0x290) + 8) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 8));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 9) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_proc_last_cpu_location");
    if (*(char *)(*(long *)(param_2 + 0x290) + 9) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 9));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x290) + 10) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"cpubind.get_thisthread_last_cpu_location");
    if (*(char *)(*(long *)(param_2 + 0x290) + 10) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x290) + 10));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (**(char **)(param_2 + 0x298) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.set_thisproc_membind");
    if (**(char **)(param_2 + 0x298) != '\x01') {
      sprintf(local_73,"%u",(ulong)**(byte **)(param_2 + 0x298));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 1) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.get_thisproc_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 1) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 1));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 2) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.set_proc_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 2) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 2));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 3) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.get_proc_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 3) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 3));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 4) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.set_thisthread_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 4) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 4));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 5) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.get_thisthread_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 5) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 5));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 6) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.set_area_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 6) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 6));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 7) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.get_area_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 7) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 7));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 8) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.alloc_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 8) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 8));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 9) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.firsttouch_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 9) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 9));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 10) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.bind_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 10) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 10));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 0xb) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.interleave_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 0xb) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 0xb));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 0xc) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.nexttouch_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 0xc) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 0xc));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 0xd) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.migrate_membind");
    if (*(char *)(*(long *)(param_2 + 0x298) + 0xd) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 0xd));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  if (*(char *)(*(long *)(param_2 + 0x298) + 0xe) != '\0') {
    (**(code **)(param_1 + 8))(param_1,local_68,"support");
    (*local_58)(local_68,&DAT_002ef149,"membind.get_area_memlocation");
    if (*(char *)(*(long *)(param_2 + 0x298) + 0xe) != '\x01') {
      sprintf(local_73,"%u",(ulong)*(byte *)(*(long *)(param_2 + 0x298) + 0xe));
      (*local_58)(local_68,"value",local_73);
    }
    (*local_48)(local_68,"support");
  }
  (**(code **)(param_1 + 8))(param_1,local_68,"support");
  (*local_58)(local_68,&DAT_002ef149,"custom.exported_support");
  (*local_48)(local_68,"support");
  return;
}


// ===== 00273b4f FUN_00273b4f =====

void FUN_00273b4f(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  void *local_190;
  char local_188 [256];
  undefined1 local_88 [16];
  code *local_78;
  code *local_68;
  int *local_28;
  uint local_1c;
  
  if ((*(ulong *)(param_2 + 8) & 4) == 0) {
    (**(code **)(param_1 + 8))(param_1,local_88,"memattr_value");
    pcVar1 = local_78;
    uVar2 = FUN_002582d8(*(undefined4 *)(param_3 + 8));
    (*pcVar1)(local_88,"target_obj_type",uVar2);
    snprintf(local_188,0xff,"%llu",*(undefined8 *)(param_3 + 0x10));
    (*local_78)(local_88,"target_obj_gp_index",local_188);
    snprintf(local_188,0xff,"%llu",*(undefined8 *)(param_3 + 0x18));
    (*local_78)(local_88,"value",local_188);
    (*local_68)(local_88,"memattr_value");
  }
  else {
    for (local_1c = 0; local_1c < *(uint *)(param_3 + 0x20); local_1c = local_1c + 1) {
      local_28 = (int *)((ulong)local_1c * 0x28 + *(long *)(param_3 + 0x28));
      (**(code **)(param_1 + 8))(param_1,local_88,"memattr_value");
      pcVar1 = local_78;
      uVar2 = FUN_002582d8(*(undefined4 *)(param_3 + 8));
      (*pcVar1)(local_88,"target_obj_type",uVar2);
      snprintf(local_188,0xff,"%llu",*(undefined8 *)(param_3 + 0x10));
      (*local_78)(local_88,"target_obj_gp_index",local_188);
      snprintf(local_188,0xff,"%llu",*(undefined8 *)(local_28 + 8));
      (*local_78)(local_88,"value",local_188);
      if (*local_28 == 0) {
        snprintf(local_188,0xff,"%llu",*(undefined8 *)(local_28 + 4));
        (*local_78)(local_88,"initiator_obj_gp_index",local_188);
        pcVar1 = local_78;
        uVar2 = FUN_002582d8(local_28[6]);
        (*pcVar1)(local_88,"initiator_obj_type",uVar2);
      }
      else {
        if (*local_28 != 1) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("0",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                        ,0xc2e,"hwloc__xml_export_memattr_target");
        }
        FUN_00261562(&local_190,*(undefined8 *)(local_28 + 2));
        if (local_190 != (void *)0x0) {
          (*local_78)(local_88,"initiator_cpuset",local_190);
        }
        free(local_190);
      }
      (*local_68)(local_88,"memattr_value");
    }
  }
  return;
}


// ===== 00273ead FUN_00273ead =====

void FUN_00273ead(long param_1,long param_2)

{
  undefined1 local_178 [16];
  code *local_168;
  code *local_158;
  char local_118 [256];
  undefined8 *local_18;
  uint local_10;
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_2 + 0x2d4); local_c = local_c + 1) {
    if (((local_c != 0) && (local_c != 1)) &&
       ((local_18 = (undefined8 *)(*(long *)(param_2 + 0x2d8) + (ulong)local_c * 0x20), 7 < local_c
        || (*(int *)((long)local_18 + 0x14) != 0)))) {
      (**(code **)(param_1 + 8))(param_1,local_178,"memattr");
      (*local_168)(local_178,&DAT_002ef149,*local_18);
      snprintf(local_118,0xff,"%lu",local_18[1]);
      (*local_168)(local_178,"flags",local_118);
      for (local_10 = 0; local_10 < *(uint *)((long)local_18 + 0x14); local_10 = local_10 + 1) {
        FUN_00273b4f(local_178,local_18,local_18[3] + (ulong)local_10 * 0x30);
      }
      (*local_158)(local_178,"memattr");
    }
  }
  return;
}


// ===== 00274031 FUN_00274031 =====

void FUN_00274031(long param_1,long param_2)

{
  undefined1 local_f8 [8];
  code *local_f0;
  code *local_e8;
  code *local_d8;
  undefined1 local_98 [16];
  code *local_88;
  code *local_78;
  char local_3b [11];
  void *local_30;
  void *local_28;
  void *local_20;
  undefined8 *local_18;
  uint local_10;
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_2 + 0x2e0); local_c = local_c + 1) {
    local_18 = (undefined8 *)((ulong)local_c * 0x28 + *(long *)(param_2 + 0x2e8));
    (**(code **)(param_1 + 8))(param_1,local_f8,"cpukind");
    FUN_00261562(&local_30,*local_18);
    (*local_e8)(local_f8,"cpuset",local_30);
    free(local_30);
    if (*(int *)((long)local_18 + 0xc) != -1) {
      snprintf(local_3b,0xb,"%d",(ulong)*(uint *)((long)local_18 + 0xc));
      (*local_e8)(local_f8,"forced_efficiency",local_3b);
    }
    for (local_10 = 0; local_10 < *(uint *)(local_18 + 3); local_10 = local_10 + 1) {
      local_20 = (void *)FUN_0026fd90(*(undefined8 *)(local_18[4] + (ulong)local_10 * 0x10));
      local_28 = (void *)FUN_0026fd90(*(undefined8 *)(local_18[4] + (ulong)local_10 * 0x10 + 8));
      (*local_f0)(local_f8,local_98,&DAT_002effaa);
      (*local_88)(local_98,&DAT_002ef149,local_20);
      (*local_88)(local_98,"value",local_28);
      (*local_78)(local_98,&DAT_002effaa);
      free(local_20);
      free(local_28);
    }
    (*local_d8)(local_f8,"cpukind");
  }
  return;
}


// ===== 00274251 FUN_00274251 =====

void FUN_00274251(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  undefined1 local_f8 [8];
  code *local_f0;
  code *local_d8;
  undefined1 local_98 [32];
  code *local_78;
  undefined8 local_40;
  void *local_38;
  uint local_2c;
  char *local_28;
  long local_20;
  uint local_14;
  long local_10;
  
  local_20 = FUN_00268b6a(param_2);
  if ((param_3 & 1) == 0) {
    FUN_00271565(param_1,param_2,local_20,param_3);
    FUN_0027237f(param_1,param_2);
    local_28 = getenv("HWLOC_XML_EXPORT_SUPPORT");
    if ((local_28 == (char *)0x0) || (iVar1 = atoi(local_28), iVar1 != 0)) {
      FUN_0027241a(param_1,param_2);
    }
    FUN_00273ead(param_1,param_2);
    FUN_00274031(param_1,param_2);
    return;
  }
  local_2c = FUN_00271765(local_20,&local_40,&local_38);
  if (local_2c == 0) {
    FUN_00271c66(param_1,param_2,local_20,param_3);
  }
  else {
    (**(code **)(param_1 + 8))(param_1,local_f8,"object");
    FUN_0026fe3f(local_f8,param_2,local_20,param_3);
    (*local_f0)(local_f8,local_98,"object");
    FUN_0026fe3f(local_98,param_2,local_40,param_3);
    for (local_10 = *(long *)(local_20 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)
        ) {
      FUN_00271c66(local_98,param_2,local_10,param_3);
    }
    for (local_10 = *(long *)(local_20 + 0xa0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)
        ) {
      FUN_00271c66(local_98,param_2,local_10,param_3);
    }
    for (local_10 = *(long *)(local_20 + 0xb0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)
        ) {
      FUN_00271c66(local_98,param_2,local_10,param_3);
    }
    (*local_78)(local_98,"object");
    for (local_14 = 1; local_14 < local_2c; local_14 = local_14 + 1) {
      FUN_00271c66(local_f8,param_2,*(undefined8 *)((long)local_38 + (ulong)local_14 * 8),param_3);
    }
    (*local_d8)(local_f8,"object");
  }
  free(local_38);
  return;
}


// ===== 00274566 FUN_00274566 =====

void FUN_00274566(long param_1,uint *param_2)

{
  uint *local_178;
  undefined1 local_168 [16];
  code *local_158;
  code *local_148;
  char local_108 [256];
  
  local_178 = param_2;
  while( true ) {
    if (local_178 == (uint *)0x0) {
      return;
    }
    (**(code **)(param_1 + 8))(param_1,local_168,&DAT_002f0eb4);
    sprintf(local_108,"%d",(ulong)*local_178);
    (*local_158)(local_168,&DAT_002ef02a,local_108);
    if (*local_178 != 0) break;
    sprintf(local_108,"%d",(ulong)local_178[4]);
    (*local_158)(local_168,"obj_depth",local_108);
    sprintf(local_108,"%u",(ulong)local_178[5]);
    (*local_158)(local_168,"obj_index",local_108);
    sprintf(local_108,"%d",(ulong)local_178[6]);
    (*local_158)(local_168,"obj_attr_type",local_108);
    if (local_178[6] == 0) {
      sprintf(local_108,"%llu",*(undefined8 *)(local_178 + 8));
      (*local_158)(local_168,"obj_attr_index",local_108);
      sprintf(local_108,"%llu",*(undefined8 *)(local_178 + 10));
      (*local_158)(local_168,"obj_attr_oldvalue",local_108);
      sprintf(local_108,"%llu",*(undefined8 *)(local_178 + 0xc));
      (*local_158)(local_168,"obj_attr_newvalue",local_108);
    }
    else if (local_178[6] < 3) {
      if (*(long *)(local_178 + 8) != 0) {
        (*local_158)(local_168,"obj_attr_name",*(undefined8 *)(local_178 + 8));
      }
      (*local_158)(local_168,"obj_attr_oldvalue",*(undefined8 *)(local_178 + 10));
      (*local_158)(local_168,"obj_attr_newvalue",*(undefined8 *)(local_178 + 0xc));
    }
    (*local_148)(local_168,&DAT_002f0eb4);
    local_178 = *(uint **)(local_178 + 2);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("0",
                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                ,0xce4,"hwloc__xml_export_diff");
}


// ===== 002748aa FUN_002748aa =====

void FUN_002748aa(long param_1)

{
  void *__ptr;
  
  __ptr = *(void **)(param_1 + 0x38);
  (**(code **)((long)__ptr + 0x10))(__ptr);
  free(*(void **)((long)__ptr + 0x48));
  free(__ptr);
  return;
}


// ===== 002748f2 FUN_002748f2 =====

void * FUN_002748f2(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                   long param_5,undefined4 param_6)

{
  int iVar1;
  void *__ptr;
  void *__ptr_00;
  int *piVar2;
  char *pcVar3;
  int local_1c;
  char *local_18;
  char *local_10;
  
  if (DAT_01218360 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_nolibxml_callbacks",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml.c"
                  ,0xe41,"hwloc_xml_component_instantiate");
  }
  local_10 = param_4;
  if (((param_4 == (char *)0x0) && (param_5 == 0)) &&
     (local_10 = getenv("HWLOC_XMLFILE"), local_10 == (char *)0x0)) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
  }
  else {
    __ptr = (void *)FUN_0025f967(param_1,param_2);
    if (__ptr != (void *)0x0) {
      __ptr_00 = malloc(0x88);
      if (__ptr_00 == (void *)0x0) {
        piVar2 = __errno_location();
        *piVar2 = 0xc;
      }
      else {
        *(void **)((long)__ptr + 0x38) = __ptr_00;
        *(code **)((long)__ptr + 0x48) = FUN_0026f3d1;
        *(code **)((long)__ptr + 0x40) = FUN_002748aa;
        *(undefined4 *)((long)__ptr + 0x30) = 0;
        if (local_10 == (char *)0x0) {
          local_18 = "xmlbuffer";
        }
        else {
          local_18 = strrchr(local_10,0x2f);
          if (local_18 == (char *)0x0) {
            local_18 = local_10;
          }
          else {
            local_18 = local_18 + 1;
          }
        }
        pcVar3 = strdup(local_18);
        *(char **)((long)__ptr_00 + 0x48) = pcVar3;
        iVar1 = FUN_00268e96();
        while ((DAT_01218368 != (undefined8 *)0x0 &&
               ((DAT_01218360 == (undefined8 *)0x0 || (iVar1 == 0))))) {
          local_1c = (*(code *)*DAT_01218368)(__ptr_00,local_10,param_5,param_6);
          if ((-1 < local_1c) || (piVar2 = __errno_location(), *piVar2 != 0x26)) goto LAB_00274ae7;
          DAT_01218368 = (undefined8 *)0x0;
        }
        local_1c = (*(code *)*DAT_01218360)(__ptr_00,local_10,param_5,param_6);
LAB_00274ae7:
        if (-1 < local_1c) {
          return __ptr;
        }
        free(*(void **)((long)__ptr_00 + 0x48));
        free(__ptr_00);
      }
      free(__ptr);
    }
  }
  return (void *)0x0;
}


// ===== 00274b26 FUN_00274b26 =====

char * FUN_00274b26(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strspn(param_1," \t\n");
  return param_1 + sVar1;
}


// ===== 00274b51 FUN_00274b51 =====

undefined8 FUN_00274b51(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  undefined8 uVar4;
  long local_18;
  long local_10;
  
  if (*(long *)(param_1 + 0x18) != 0) {
    pcVar2 = (char *)FUN_00274b26(*(undefined8 *)(param_1 + 0x18));
    sVar3 = strspn(pcVar2,"abcdefghijklmnopqrstuvwxyz_");
    if ((pcVar2[sVar3] == '=') && (pcVar2[sVar3 + 1] == '\"')) {
      pcVar2[sVar3] = '\0';
      *param_2 = pcVar2;
      pcVar2 = pcVar2 + sVar3 + 2;
      *param_3 = pcVar2;
      local_10 = 0;
      local_18 = 0;
      do {
        if (pcVar2[local_10 + local_18] == '\"') {
          pcVar2[local_10] = '\0';
          uVar4 = FUN_00274b26(pcVar2 + local_18 + local_10 + 1);
          *(undefined8 *)(param_1 + 0x18) = uVar4;
          return 0;
        }
        if (pcVar2[local_10 + local_18] == '&') {
          iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"#10;",4);
          if (iVar1 == 0) {
            local_18 = local_18 + 4;
            pcVar2[local_10] = '\n';
          }
          else {
            iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"#13;",4);
            if (iVar1 == 0) {
              local_18 = local_18 + 4;
              pcVar2[local_10] = '\r';
            }
            else {
              iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"#9;",3);
              if (iVar1 == 0) {
                local_18 = local_18 + 3;
                pcVar2[local_10] = '\t';
              }
              else {
                iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"quot;",5);
                if (iVar1 == 0) {
                  local_18 = local_18 + 5;
                  pcVar2[local_10] = '\"';
                }
                else {
                  iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"lt;",3);
                  if (iVar1 == 0) {
                    local_18 = local_18 + 3;
                    pcVar2[local_10] = '<';
                  }
                  else {
                    iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"gt;",3);
                    if (iVar1 == 0) {
                      local_18 = local_18 + 3;
                      pcVar2[local_10] = '>';
                    }
                    else {
                      iVar1 = strncmp(pcVar2 + local_18 + local_10 + 1,"amp;",4);
                      if (iVar1 != 0) {
                        return 0xffffffff;
                      }
                      local_18 = local_18 + 4;
                      pcVar2[local_10] = '&';
                    }
                  }
                }
              }
            }
          }
        }
        else {
          pcVar2[local_10] = pcVar2[local_10 + local_18];
        }
        local_10 = local_10 + 1;
      } while (pcVar2[local_10 + local_18] != '\0');
    }
  }
  return 0xffffffff;
}


// ===== 00274ee6 FUN_00274ee6 =====

undefined8 FUN_00274ee6(long param_1,long *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  *param_2 = param_1;
  param_2[1] = *(long *)(param_1 + 8);
  if (*(int *)(param_1 + 0x28) == 0) {
    pcVar2 = (char *)FUN_00274b26(uVar1);
    if (*pcVar2 == '<') {
      pcVar2 = pcVar2 + 1;
      if (*pcVar2 == '/') {
        uVar1 = 0;
      }
      else {
        param_2[4] = (long)pcVar2;
        pcVar3 = strchr(pcVar2,0x3e);
        if (pcVar3 == (char *)0x0) {
          uVar1 = 0xffffffff;
        }
        else {
          *pcVar3 = '\0';
          param_2[2] = (long)(pcVar3 + 1);
          if (pcVar3[-1] == '/') {
            *(undefined4 *)(param_2 + 5) = 1;
            pcVar3[-1] = '\0';
          }
          else {
            *(undefined4 *)(param_2 + 5) = 0;
          }
          sVar4 = strspn(pcVar2,"abcdefghijklmnopqrstuvwxyz1234567890_");
          if (pcVar2[sVar4] == '\0') {
            param_2[3] = 0;
            *param_3 = pcVar2;
            uVar1 = 1;
          }
          else if (pcVar2[sVar4] == ' ') {
            pcVar2[sVar4] = '\0';
            param_2[3] = (long)(pcVar2 + sVar4 + 1);
            *param_3 = pcVar2;
            uVar1 = 1;
          }
          else {
            uVar1 = 0xffffffff;
          }
        }
      }
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 002750a5 FUN_002750a5 =====

undefined8 FUN_002750a5(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    pcVar3 = (char *)FUN_00274b26(*(long *)(param_1 + 0x10));
    if (*pcVar3 == '<') {
      pcVar4 = strchr(pcVar3 + 1,0x3e);
      if (pcVar4 == (char *)0x0) {
        uVar2 = 0xffffffff;
      }
      else {
        *pcVar4 = '\0';
        *(long *)(param_1 + 0x10) = (long)(pcVar4 + 1);
        if ((pcVar3[1] == '/') &&
           (iVar1 = strcmp(pcVar3 + 2,*(char **)(param_1 + 0x20)), iVar1 == 0)) {
          return 0;
        }
        uVar2 = 0xffffffff;
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00275175 FUN_00275175 =====

void FUN_00275175(long *param_1)

{
  *(long *)(*param_1 + 0x10) = param_1[2];
  return;
}


// ===== 002751a9 FUN_002751a9 =====

undefined8 FUN_002751a9(long param_1,undefined8 *param_2,long param_3)

{
  char *__s;
  undefined8 uVar1;
  char *pcVar2;
  
  __s = *(char **)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x28) == 0) {
    pcVar2 = strchr(__s,0x3c);
    if (pcVar2 == (char *)0x0) {
      uVar1 = 0xffffffff;
    }
    else if ((long)pcVar2 - (long)__s == param_3) {
      *(char **)(param_1 + 0x10) = pcVar2;
      *pcVar2 = '\0';
      *param_2 = __s;
      uVar1 = 1;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else if (param_3 == 0) {
    *param_2 = &DAT_002f14ce;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== 0027526c FUN_0027526c =====

void FUN_0027526c(long param_1)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    **(undefined1 **)(param_1 + 0x10) = 0x3c;
  }
  return;
}


// ===== 00275298 FUN_00275298 =====

undefined8 FUN_00275298(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  long local_30;
  undefined8 *local_28;
  char *local_20;
  char *local_18;
  char *local_10;
  
  local_28 = param_2 + 2;
  local_30 = *(long *)(param_1 + 0x50);
  local_18 = *(char **)(local_30 + 8);
  while ((iVar1 = strncmp(local_18,"<?xml ",6), iVar1 == 0 ||
         (iVar1 = strncmp(local_18,"<!DOCTYPE ",10), iVar1 == 0))) {
    local_18 = strchr(local_18,10);
    if (local_18 == (char *)0x0) {
      return 0xffffffff;
    }
    local_18 = local_18 + 1;
  }
  iVar1 = sscanf(local_18,"<topology version=\"%u.%u\">",&local_34,&local_38);
  if (iVar1 == 2) {
    *(undefined4 *)(param_1 + 0x58) = local_34;
    *(undefined4 *)(param_1 + 0x5c) = local_38;
    local_10 = strchr(local_18,0x3e);
    local_10 = local_10 + 1;
    local_20 = "topology";
  }
  else {
    iVar1 = strncmp(local_18,"<topology>",10);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x58) = 1;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      local_10 = local_18 + 10;
      local_20 = "topology";
    }
    else {
      iVar1 = strncmp(local_18,"<root>",6);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 9;
      local_10 = local_18 + 6;
      local_20 = "root";
    }
  }
  *(code **)(param_2[1] + 0x18) = FUN_00274b51;
  *(code **)(param_2[1] + 0x20) = FUN_00274ee6;
  *(code **)(param_2[1] + 0x28) = FUN_002750a5;
  *(code **)(param_2[1] + 0x30) = FUN_00275175;
  *(code **)(param_2[1] + 0x38) = FUN_002751a9;
  *(code **)(param_2[1] + 0x40) = FUN_0027526c;
  *param_2 = 0;
  *(undefined4 *)(local_28 + 3) = 0;
  *local_28 = local_10;
  local_28[2] = local_20;
  local_28[1] = 0;
  return 0;
}


// ===== 002754e2 FUN_002754e2 =====

void FUN_002754e2(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x50);
  if (*(long *)(lVar1 + 8) != 0) {
    free(*(void **)(lVar1 + 8));
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  return;
}


// ===== 00275526 FUN_00275526 =====

void FUN_00275526(undefined8 param_1,int param_2)

{
  int iVar1;
  
  FUN_002754e2(param_1);
  if (param_2 < 0) {
    iVar1 = FUN_00268e49();
    if (iVar1 != 0) {
      fwrite("Failed to parse XML input with the minimalistic parser. If it was not\ngenerated by hwloc, try enabling full XML support with libxml2.\n"
             ,1,0x86,*(FILE **)PTR_stderr_0032efe0);
    }
  }
  return;
}


// ===== 00275576 FUN_00275576 =====

void FUN_00275576(long param_1)

{
  void *__ptr;
  
  __ptr = *(void **)(param_1 + 0x50);
  FUN_002754e2(param_1);
  free(__ptr);
  return;
}


// ===== 002755a9 FUN_002755a9 =====

undefined8 FUN_002755a9(char *param_1,undefined8 *param_2,long *param_3)

{
  int iVar1;
  char *local_e0;
  undefined1 local_d8 [24];
  uint local_c0;
  long local_a8;
  void *local_40;
  size_t local_38;
  FILE *local_30;
  void *local_28;
  size_t local_20;
  long local_18;
  size_t local_10;
  
  iVar1 = strcmp(param_1,"-");
  local_e0 = param_1;
  if (iVar1 == 0) {
    local_e0 = "/dev/stdin";
  }
  local_30 = fopen(local_e0,"r");
  if (local_30 != (FILE *)0x0) {
    local_10 = 0x1000;
    iVar1 = FUN_002935b0(local_e0,local_d8);
    if ((iVar1 == 0) && ((local_c0 & 0xf000) == 0x8000)) {
      local_10 = local_a8 + 1;
    }
    local_28 = malloc(local_10 + 1);
    if (local_28 != (void *)0x0) {
      local_18 = 0;
      local_20 = local_10;
      while( true ) {
        local_38 = fread((void *)((long)local_28 + local_18),1,local_20,local_30);
        local_18 = local_18 + local_38;
        *(undefined1 *)(local_18 + (long)local_28) = 0;
        if (local_38 != local_20) {
          fclose(local_30);
          *param_2 = local_28;
          *param_3 = local_18 + 1;
          return 0;
        }
        local_10 = local_10 * 2;
        local_40 = realloc(local_28,local_10 + 1);
        if (local_40 == (void *)0x0) break;
        local_20 = local_10 >> 1;
        local_28 = local_40;
      }
      free(local_28);
    }
    fclose(local_30);
  }
  return 0xffffffff;
}


// ===== 0027576b FUN_0027576b =====

undefined8 FUN_0027576b(undefined8 *param_1,undefined8 param_2,void *param_3,int param_4)

{
  int iVar1;
  long *__ptr;
  void *pvVar2;
  undefined8 uVar3;
  
  __ptr = malloc(0x10);
  if (__ptr == (long *)0x0) {
LAB_00275886:
    uVar3 = 0xffffffff;
  }
  else {
    param_1[10] = __ptr;
    if (param_3 == (void *)0x0) {
      iVar1 = FUN_002755a9(param_2,__ptr + 1,__ptr);
      if (iVar1 < 0) goto LAB_00275877;
    }
    else {
      pvVar2 = malloc((long)(param_4 + 1));
      __ptr[1] = (long)pvVar2;
      if (__ptr[1] == 0) {
LAB_00275877:
        free(__ptr);
        goto LAB_00275886;
      }
      *__ptr = (long)(param_4 + 1);
      memcpy((void *)__ptr[1],param_3,(long)param_4);
      *(undefined1 *)((long)param_4 + __ptr[1]) = 0;
    }
    *param_1 = FUN_00275298;
    param_1[1] = FUN_00275526;
    param_1[2] = FUN_00275576;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 0027588d FUN_0027588d =====

int FUN_0027588d(undefined8 *param_1,undefined8 param_2,void *param_3,int param_4,undefined8 param_5
                ,undefined8 *param_6)

{
  int iVar1;
  char *local_80;
  char *local_78;
  long local_70;
  char *local_68;
  char *local_60;
  undefined1 local_58 [52];
  int local_24;
  undefined8 *local_20;
  char *local_18;
  char *local_10;
  
  local_20 = param_1 + 2;
  local_10 = (char *)0x0;
  if (param_3 == (void *)0x0) {
    local_24 = FUN_002755a9(param_2,&local_60,&local_70);
    if (local_24 < 0) {
      return -1;
    }
  }
  else {
    local_60 = malloc((long)param_4);
    if (local_60 == (char *)0x0) {
      return -1;
    }
    memcpy(local_60,param_3,(long)param_4);
    local_70 = (long)param_4;
  }
  local_18 = local_60;
  while ((iVar1 = strncmp(local_18,"<?xml ",6), iVar1 == 0 ||
         (iVar1 = strncmp(local_18,"<!DOCTYPE ",10), iVar1 == 0))) {
    local_18 = strchr(local_18,10);
    if (local_18 == (char *)0x0) {
      local_18 = (char *)0x0;
LAB_00275b7f:
      free(local_60);
      free(local_10);
      return -1;
    }
    local_18 = local_18 + 1;
  }
  *(code **)(param_1[1] + 0x18) = FUN_00274b51;
  *(code **)(param_1[1] + 0x20) = FUN_00274ee6;
  *(code **)(param_1[1] + 0x28) = FUN_002750a5;
  *(code **)(param_1[1] + 0x30) = FUN_00275175;
  *(code **)(param_1[1] + 0x38) = FUN_002751a9;
  *(code **)(param_1[1] + 0x40) = FUN_0027526c;
  *param_1 = 0;
  *(undefined4 *)(local_20 + 3) = 0;
  *local_20 = local_18;
  local_20[2] = 0;
  local_20[1] = 0;
  local_24 = FUN_00274ee6(param_1,local_58,&local_68);
  if ((-1 < local_24) &&
     ((local_68 != (char *)0x0 && (iVar1 = strcmp(local_68,"topologydiff"), iVar1 == 0)))) {
    while( true ) {
      iVar1 = FUN_00274b51(local_58,&local_78,&local_80);
      if (iVar1 < 0) {
        local_24 = FUN_0026f11a(local_58,param_5);
        if ((param_6 == (undefined8 *)0x0) || (local_24 != 0)) {
          free(local_10);
        }
        else {
          *param_6 = local_10;
        }
        free(local_60);
        return local_24;
      }
      iVar1 = strcmp(local_78,"refname");
      if (iVar1 != 0) break;
      free(local_10);
      local_10 = strdup(local_80);
    }
  }
  goto LAB_00275b7f;
}


// ===== 00275ba4 FUN_00275ba4 =====

void FUN_00275ba4(long *param_1,int param_2)

{
  int local_14;
  
  if (-1 < param_2) {
    param_1[1] = param_1[1] + (long)param_2;
    local_14 = param_2;
    if ((int)param_1[2] <= param_2) {
      if (param_1[2] == 0) {
        local_14 = 0;
      }
      else {
        local_14 = (int)param_1[2] + -1;
      }
    }
    *param_1 = *param_1 + (long)local_14;
    param_1[2] = param_1[2] - (long)local_14;
  }
  return;
}


// ===== 00275c2d FUN_00275c2d =====

void * FUN_00275c2d(char *param_1)

{
  size_t sVar1;
  size_t __n;
  void *__dest;
  char *local_40;
  int local_14;
  undefined4 *local_10;
  
  sVar1 = strlen(param_1);
  __n = strcspn(param_1,"\n\r\t\"<>&");
  if (__n == sVar1) {
    __dest = (void *)0x0;
  }
  else {
    __dest = malloc(sVar1 * 6 + 1);
    memcpy(__dest,param_1,__n);
    local_10 = (undefined4 *)((long)__dest + __n);
    for (local_40 = param_1 + __n; *local_40 != '\0'; local_40 = local_40 + sVar1) {
      switch(*local_40) {
      case '\t':
        *local_10 = 0x3b392326;
        *(undefined1 *)(local_10 + 1) = 0;
        local_14 = 4;
        break;
      case '\n':
        *local_10 = 0x30312326;
        *(undefined2 *)(local_10 + 1) = 0x3b;
        local_14 = 5;
        break;
      default:
        local_14 = 0;
        break;
      case '\r':
        *local_10 = 0x33312326;
        *(undefined2 *)(local_10 + 1) = 0x3b;
        local_14 = 5;
        break;
      case '\"':
        *local_10 = 0x6f757126;
        *(undefined2 *)(local_10 + 1) = 0x3b74;
        *(undefined1 *)((long)local_10 + 6) = 0;
        local_14 = 6;
        break;
      case '&':
        *local_10 = 0x706d6126;
        *(undefined2 *)(local_10 + 1) = 0x3b;
        local_14 = 5;
        break;
      case '<':
        *local_10 = 0x3b746c26;
        *(undefined1 *)(local_10 + 1) = 0;
        local_14 = 4;
        break;
      case '>':
        *local_10 = 0x3b746726;
        *(undefined1 *)(local_10 + 1) = 0;
        local_14 = 4;
      }
      local_40 = local_40 + 1;
      sVar1 = strcspn(local_40,"\n\r\t\"<>&");
      memcpy((undefined1 *)((long)local_10 + (long)local_14),local_40,sVar1);
      local_10 = (undefined4 *)((undefined1 *)((long)local_10 + (long)local_14) + sVar1);
    }
    *(undefined1 *)local_10 = 0;
  }
  return __dest;
}


// ===== 00275e24 FUN_00275e24 =====

void FUN_00275e24(long param_1,long *param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long *plVar2;
  long *plVar3;
  
  plVar2 = (long *)(param_1 + 0x30);
  plVar3 = param_2 + 6;
  if (*(int *)(param_1 + 0x50) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!npdata->has_content",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml-nolibxml.c"
                  ,0x255,"hwloc__nolibxml_export_new_child");
  }
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = FUN_002654ee(*plVar2,*(undefined8 *)(param_1 + 0x40),&DAT_002f165e);
    FUN_00275ba4(plVar2,uVar1);
  }
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  *param_2 = param_1;
  param_2[1] = *(long *)(param_1 + 8);
  param_2[2] = *(long *)(param_1 + 0x10);
  param_2[3] = *(long *)(param_1 + 0x18);
  param_2[4] = *(long *)(param_1 + 0x20);
  param_2[5] = *(long *)(param_1 + 0x28);
  *plVar3 = *plVar2;
  param_2[7] = *(long *)(param_1 + 0x38);
  param_2[8] = *(long *)(param_1 + 0x40);
  *(int *)(param_2 + 9) = *(int *)(param_1 + 0x48) + 2;
  *(undefined4 *)((long)param_2 + 0x4c) = 0;
  *(undefined4 *)(param_2 + 10) = 0;
  uVar1 = FUN_002654ee(*plVar3,param_2[8],"%*s<%s",*(undefined4 *)(param_1 + 0x48),&DAT_002f14ce,
                       param_3);
  FUN_00275ba4(plVar3,uVar1);
  return;
}


// ===== 00275fd1 FUN_00275fd1 =====

void FUN_00275fd1(long param_1,undefined8 param_2,void *param_3)

{
  undefined4 uVar1;
  void *__ptr;
  
  __ptr = (void *)FUN_00275c2d(param_3);
  if (__ptr != (void *)0x0) {
    param_3 = __ptr;
  }
  uVar1 = FUN_002654ee(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0x40)," %s=\"%s\"",
                       param_2,param_3);
  FUN_00275ba4((undefined8 *)(param_1 + 0x30),uVar1);
  free(__ptr);
  return;
}


// ===== 0027605f FUN_0027605f =====

void FUN_0027605f(long *param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  undefined4 local_c;
  
  plVar2 = param_1 + 6;
  lVar1 = *param_1;
  if (((int)param_1[10] != 0) && (*(int *)((long)param_1 + 0x4c) != 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!(ndata->has_content && ndata->nr_children)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml-nolibxml.c"
                  ,0x280,"hwloc__nolibxml_export_end_object");
  }
  if ((int)param_1[10] == 0) {
    if (*(int *)((long)param_1 + 0x4c) == 0) {
      local_c = FUN_002654ee(*plVar2,param_1[8],&DAT_002f16b5);
    }
    else {
      local_c = FUN_002654ee(*plVar2,param_1[8],"%*s</%s>\n",*(undefined4 *)(lVar1 + 0x48),
                             &DAT_002f14ce,param_2);
    }
  }
  else {
    local_c = FUN_002654ee(*plVar2,param_1[8],"</%s>\n",param_2);
  }
  FUN_00275ba4(plVar2,local_c);
  *(long *)(lVar1 + 0x30) = *plVar2;
  *(long *)(lVar1 + 0x38) = param_1[7];
  *(long *)(lVar1 + 0x40) = param_1[8];
  return;
}


// ===== 002761ae FUN_002761ae =====

void FUN_002761ae(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x4c) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!ndata->nr_children",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-xml-nolibxml.c"
                  ,0x295,"hwloc__nolibxml_export_add_content");
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    uVar1 = FUN_002654ee(*puVar2,*(undefined8 *)(param_1 + 0x40),&DAT_002f16cd);
    FUN_00275ba4(puVar2,uVar1);
  }
  *(undefined4 *)(param_1 + 0x50) = 1;
  uVar1 = FUN_002654ee(*puVar2,*(undefined8 *)(param_1 + 0x40),&DAT_002f16cf,param_2);
  FUN_00275ba4(puVar2,uVar1);
  return;
}


// ===== 00276289 FUN_00276289 =====

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffffb8 : 0x00276374 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long FUN_00276289(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,ulong param_5
                 )

{
  undefined8 uVar1;
  long lVar2;
  char *pcVar3;
  undefined1 local_d8 [96];
  undefined1 local_78 [8];
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  uint local_14;
  undefined8 *local_10;
  
  lVar2 = local_38;
  uVar1 = local_48;
  local_10 = &local_48;
  local_14 = (uint)param_5 & 1;
  local_70 = FUN_00275e24;
  local_68 = FUN_00275fd1;
  local_60 = FUN_002761ae;
  local_58 = FUN_0027605f;
  local_30 = 0;
  local_40 = 0;
  local_38 = (long)param_4;
  local_2c = 1;
  local_28 = 0;
  if ((param_5 & 1) == 0) {
    pcVar3 = "hwloc2.dtd";
  }
  else {
    pcVar3 = "hwloc.dtd";
  }
  local_50 = param_2;
  local_48 = param_3;
  local_18 = FUN_002654ee(uVar1,lVar2,
                          "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE topology SYSTEM \"%s\">\n"
                          ,pcVar3);
  FUN_00275ba4(local_10,local_18);
  FUN_00275e24(local_78,local_d8,"topology");
  if ((param_5 & 1) == 0) {
    FUN_00275fd1(local_d8,"version",&DAT_002f1730);
  }
  FUN_00274251(local_d8,param_1,param_5);
  FUN_0027605f(local_d8,"topology");
  return local_10[1] + 1;
}


// ===== 0027642c FUN_0027642c =====

undefined8
FUN_0027642c(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4,
            undefined8 param_5)

{
  void *__ptr;
  undefined8 uVar1;
  ulong __size;
  void *local_10;
  
  __ptr = malloc(0x4000);
  if (__ptr == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    __size = FUN_00276289(param_1,param_2,__ptr,0x4000,param_5);
    local_10 = __ptr;
    if (0x4000 < __size) {
      local_10 = realloc(__ptr,__size);
      if (local_10 == (void *)0x0) {
        free(__ptr);
        return 0xffffffff;
      }
      FUN_00276289(param_1,param_2,local_10,__size & 0xffffffff,param_5);
    }
    *param_3 = local_10;
    *param_4 = (int)__size;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0027651c FUN_0027651c =====

int FUN_0027651c(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  size_t sVar2;
  int *piVar3;
  int local_34;
  void *local_30;
  int local_24;
  FILE *local_20;
  
  local_24 = FUN_0027642c(param_1,param_2,&local_30,&local_34,param_4);
  if (local_24 < 0) {
    local_24 = 0xffffffff;
  }
  else {
    iVar1 = strcmp(param_3,"-");
    if (iVar1 == 0) {
      local_20 = *(FILE **)PTR_stdout_0032ef48;
    }
    else {
      local_20 = fopen(param_3,"w");
      if (local_20 == (FILE *)0x0) {
        free(local_30);
        return 0xffffffff;
      }
    }
    sVar2 = fwrite(local_30,1,(long)(local_34 + -1),local_20);
    local_24 = (int)sVar2;
    if (local_24 == local_34 + -1) {
      local_24 = 0;
    }
    else {
      piVar3 = __errno_location();
      iVar1 = ferror(local_20);
      *piVar3 = iVar1;
      local_24 = 0xffffffff;
    }
    free(local_30);
    if (local_20 != *(FILE **)PTR_stdout_0032ef48) {
      fclose(local_20);
    }
  }
  return local_24;
}


// ===== 00276643 FUN_00276643 =====

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffffb8 : 0x00276701 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

long FUN_00276643(undefined8 param_1,long param_2,undefined8 param_3,int param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 local_d8 [96];
  undefined1 local_78 [8];
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_14;
  undefined8 *local_10;
  
  lVar2 = local_38;
  uVar1 = local_48;
  local_10 = &local_48;
  local_70 = FUN_00275e24;
  local_68 = FUN_00275fd1;
  local_60 = FUN_002761ae;
  local_58 = FUN_0027605f;
  local_50 = 0;
  local_30 = 0;
  local_40 = 0;
  local_38 = (long)param_4;
  local_2c = 1;
  local_28 = 0;
  local_48 = param_3;
  local_14 = FUN_002654ee(uVar1,lVar2,
                          "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE topologydiff SYSTEM \"hwloc2-diff.dtd\">\n"
                         );
  FUN_00275ba4(local_10,local_14);
  FUN_00275e24(local_78,local_d8,"topologydiff");
  if (param_2 != 0) {
    FUN_00275fd1(local_d8,"refname",param_2);
  }
  FUN_00274566(local_d8,param_1);
  FUN_0027605f(local_d8,"topologydiff");
  return local_10[1] + 1;
}


// ===== 002767b0 FUN_002767b0 =====

undefined8
FUN_002767b0(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  void *__ptr;
  undefined8 uVar1;
  ulong __size;
  void *local_10;
  
  __ptr = malloc(0x4000);
  if (__ptr == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    __size = FUN_00276643(param_1,param_2,__ptr,0x4000);
    local_10 = __ptr;
    if (0x4000 < __size) {
      local_10 = realloc(__ptr,__size);
      if (local_10 == (void *)0x0) {
        free(__ptr);
        return 0xffffffff;
      }
      FUN_00276643(param_1,param_2,local_10,__size & 0xffffffff);
    }
    *param_3 = local_10;
    *param_4 = (int)__size;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0027688a FUN_0027688a =====

int FUN_0027688a(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  int *piVar3;
  int local_34;
  void *local_30;
  int local_24;
  FILE *local_20;
  
  local_24 = FUN_002767b0(param_1,param_2,&local_30,&local_34);
  if (local_24 < 0) {
    local_24 = 0xffffffff;
  }
  else {
    iVar1 = strcmp(param_3,"-");
    if (iVar1 == 0) {
      local_20 = *(FILE **)PTR_stdout_0032ef48;
    }
    else {
      local_20 = fopen(param_3,"w");
      if (local_20 == (FILE *)0x0) {
        free(local_30);
        return 0xffffffff;
      }
    }
    sVar2 = fwrite(local_30,1,(long)(local_34 + -1),local_20);
    local_24 = (int)sVar2;
    if (local_24 == local_34 + -1) {
      local_24 = 0;
    }
    else {
      piVar3 = __errno_location();
      iVar1 = ferror(local_20);
      *piVar3 = iVar1;
      local_24 = 0xffffffff;
    }
    free(local_30);
    if (local_20 != *(FILE **)PTR_stdout_0032ef48) {
      fclose(local_20);
    }
  }
  return local_24;
}


// ===== 002769a6 FUN_002769a6 =====

void FUN_002769a6(void *param_1)

{
  free(param_1);
  return;
}


// ===== 002769c1 FUN_002769c1 =====

long FUN_002769c1(undefined8 param_1,int param_2)

{
  long local_10;
  
  local_10 = 0;
  do {
    local_10 = FUN_00276ab2(param_1,0xd,local_10);
    if (local_10 == 0) {
      return 0;
    }
  } while (param_2 != *(int *)(local_10 + 0x10));
  return local_10;
}


// ===== 00276a13 FUN_00276a13 =====

undefined8 FUN_00276a13(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else if (iVar1 == -2) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00258070(param_1,iVar1);
  }
  return uVar2;
}


// ===== 00276a63 FUN_00276a63 =====

undefined8 FUN_00276a63(undefined8 param_1,int param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = FUN_002580d2(param_1,param_2,0);
  }
  else if (param_2 == *(int *)(param_3 + 0x30)) {
    uVar1 = *(undefined8 *)(param_3 + 0x38);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00276ab2 FUN_00276ab2 =====

undefined8 FUN_00276ab2(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if ((iVar1 == -1) || (iVar1 == -2)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00276a63(param_1,iVar1,param_3);
  }
  return uVar2;
}


// ===== 00276b03 FUN_00276b03 =====

void FUN_00276b03(undefined8 param_1)

{
  FUN_002580d2(param_1,0,0);
  return;
}


// ===== 00276b27 FUN_00276b27 =====

undefined8 FUN_00276b27(long param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0xe0) <= local_c) {
      return 0;
    }
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0xd8) + (ulong)local_c * 0x10);
    iVar1 = strcmp((char *)*puVar2,param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return puVar2[1];
}


// ===== 00276b97 FUN_00276b97 =====

int FUN_00276b97(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 2) {
    if ((param_1 == 0) || (3 < param_1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = param_1 + 8;
    }
  }
  else if ((param_1 == 0) || (5 < param_1)) {
    iVar1 = -1;
  }
  else {
    iVar1 = param_1 + 3;
  }
  return iVar1;
}


// ===== 00276bdd FUN_00276bdd =====

ulong FUN_00276bdd(char *param_1)

{
  int iVar1;
  double dVar2;
  ulong uVar3;
  
  iVar1 = strncmp(param_1,"2.5 ",4);
  if (iVar1 == 0) {
    uVar3 = (ulong)DAT_002f4da0;
  }
  else {
    iVar1 = strncmp(param_1,"5 ",2);
    if (iVar1 == 0) {
      uVar3 = (ulong)DAT_002f4da4;
    }
    else {
      dVar2 = atof(param_1);
      dVar2 = (DAT_002f4da8 * dVar2) / DAT_002f4db0;
      uVar3 = CONCAT44((int)((ulong)dVar2 >> 0x20),(float)dVar2);
    }
  }
  return uVar3;
}


// ===== 00276c63 FUN_00276c63 =====

undefined8 FUN_00276c63(int param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0xd) || (param_1 == 0x12)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00276c84 FUN_00276c84 =====

undefined8 FUN_00276c84(uint param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = param_1 >> 8;
  if ((((((uVar1 == 3) || (uVar1 == 2)) || (uVar1 == 1)) || ((uVar1 == 0 || (uVar1 == 0xb)))) ||
      ((param_1 == 0xc04 || ((param_1 == 0xc06 || (param_1 == 0x502)))))) ||
     ((uVar1 == 6 || (uVar1 == 0x12)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00276ce7 FUN_00276ce7 =====

bool FUN_00276ce7(undefined8 param_1,undefined4 param_2)

{
  int local_c;
  
  local_c = 1;
  FUN_002543c3(param_1,param_2,&local_c);
  if (local_c == 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("filter != HWLOC_TYPE_FILTER_KEEP_IMPORTANT",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/plugins.h"
                  ,0x218,"hwloc_filter_check_keep_object_type");
  }
  return local_c != 1;
}


// ===== 00276d47 FUN_00276d47 =====

void FUN_00276d47(void)

{
  return;
}


// ===== 00276da0 FUN_00276da0 =====

void FUN_00276da0(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                 undefined8 param_5,uint param_6)

{
  syscall(0xed,param_1,param_2,(ulong)param_3,param_4,param_5,(ulong)param_6);
  return;
}


// ===== 00276df8 FUN_00276df8 =====

void FUN_00276df8(uint param_1,undefined8 param_2,undefined8 param_3)

{
  syscall(0xee,(ulong)param_1,param_2,param_3);
  return;
}


// ===== 00276e29 FUN_00276e29 =====

void FUN_00276e29(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 uint param_5)

{
  syscall(0xef,param_1,param_2,param_3,param_4,(ulong)param_5);
  return;
}


// ===== 00276e72 FUN_00276e72 =====

void FUN_00276e72(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  syscall(0x100,(ulong)param_1,param_2,param_3,param_4);
  return;
}


// ===== 00276eae FUN_00276eae =====

void FUN_00276eae(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,uint param_6)

{
  syscall(0x117,(ulong)param_1,param_2,param_3,param_4,param_5,(ulong)param_6);
  return;
}


// ===== 00276f05 FUN_00276f05 =====

char * FUN_00276f05(char *param_1,int param_2)

{
  char *local_10;
  
  local_10 = param_1;
  if (-1 < param_2) {
    for (; *local_10 == '/'; local_10 = local_10 + 1) {
    }
  }
  return local_10;
}


// ===== 00276f36 FUN_00276f36 =====

int FUN_00276f36(undefined8 param_1,int param_2)

{
  int iVar1;
  char *__file;
  
  __file = (char *)FUN_00276f05(param_1,param_2);
  if (__file == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = openat(param_2,__file,0);
  }
  return iVar1;
}


// ===== 00276f85 FUN_00276f85 =====

FILE * FUN_00276f85(undefined8 param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  FILE *pFVar3;
  
  iVar1 = strcmp(param_2,"r");
  if (iVar1 == 0) {
    iVar1 = FUN_00276f36(param_1,param_3);
    if (iVar1 == -1) {
      pFVar3 = (FILE *)0x0;
    }
    else {
      pFVar3 = fdopen(iVar1,param_2);
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x5f;
    pFVar3 = (FILE *)0x0;
  }
  return pFVar3;
}


// ===== 00276ff5 FUN_00276ff5 =====

int FUN_00276ff5(undefined8 param_1,int param_2,int param_3)

{
  int iVar1;
  char *__file;
  
  __file = (char *)FUN_00276f05(param_1,param_3);
  if (__file == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = faccessat(param_3,__file,param_2,0);
  }
  return iVar1;
}


// ===== 00277042 FUN_00277042 =====

undefined8 FUN_00277042(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00276f05(param_1,param_4);
  if (lVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_002935d0(param_4,lVar1,param_2,param_3);
  }
  return uVar2;
}


// ===== 00277092 FUN_00277092 =====

DIR * FUN_00277092(undefined8 param_1,int param_2)

{
  int __fd;
  char *__file;
  DIR *pDVar1;
  
  __file = (char *)FUN_00276f05(param_1,param_2);
  if (__file == (char *)0x0) {
    pDVar1 = (DIR *)0x0;
  }
  else {
    __fd = openat(param_2,__file,0x10000);
    if (__fd < 0) {
      pDVar1 = (DIR *)0x0;
    }
    else {
      pDVar1 = fdopendir(__fd);
    }
  }
  return pDVar1;
}


// ===== 002770fb FUN_002770fb =====

ssize_t FUN_002770fb(undefined8 param_1,char *param_2,size_t param_3,int param_4)

{
  char *__path;
  ssize_t sVar1;
  
  __path = (char *)FUN_00276f05(param_1,param_4);
  if (__path == (char *)0x0) {
    sVar1 = 0xffffffff;
  }
  else {
    sVar1 = readlinkat(param_4,__path,param_2,param_3);
  }
  return sVar1;
}


// ===== 0027714d FUN_0027714d =====

void FUN_0027714d(undefined8 param_1,undefined4 param_2)

{
  FUN_00276f36(param_1,param_2);
  return;
}


// ===== 0027716f FUN_0027716f =====

void FUN_0027716f(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00276f85(param_1,param_2,param_3);
  return;
}


// ===== 0027719a FUN_0027719a =====

void FUN_0027719a(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00276ff5(param_1,param_2,param_3);
  return;
}


// ===== 002771c2 FUN_002771c2 =====

void FUN_002771c2(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00277042(param_1,param_2,0,param_3);
  return;
}


// ===== 002771f1 FUN_002771f1 =====

void FUN_002771f1(undefined8 param_1,undefined4 param_2)

{
  FUN_00277092(param_1,param_2);
  return;
}


// ===== 00277213 FUN_00277213 =====

void FUN_00277213(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  FUN_002770fb(param_1,param_2,param_3,param_4);
  return;
}


// ===== 00277243 FUN_00277243 =====

ssize_t FUN_00277243(undefined8 param_1,void *param_2,long param_3,undefined4 param_4)

{
  int __fd;
  ssize_t sVar1;
  
  __fd = FUN_0027714d(param_1,param_4);
  if (__fd < 0) {
    sVar1 = -1;
  }
  else {
    sVar1 = read(__fd,param_2,param_3 - 1);
    close(__fd);
    if (sVar1 < 1) {
      sVar1 = -1;
    }
    else {
      *(undefined1 *)((long)param_2 + sVar1) = 0;
    }
  }
  return sVar1;
}


// ===== 002772c8 FUN_002772c8 =====

undefined8 FUN_002772c8(undefined8 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char local_13 [11];
  
  lVar2 = FUN_00277243(param_1,local_13,0xb,param_3);
  if (lVar2 < 1) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = atoi(local_13);
    *param_2 = iVar1;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 0027731c FUN_0027731c =====

undefined8 FUN_0027731c(undefined8 param_1,undefined4 *param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  char local_13 [11];
  
  lVar1 = FUN_00277243(param_1,local_13,0xb,param_3);
  if (lVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = strtoul(local_13,(char **)0x0,10);
    *param_2 = (int)uVar3;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0027737a FUN_0027737a =====

undefined8 FUN_0027737a(undefined8 param_1,ulonglong *param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  char local_28 [32];
  
  lVar1 = FUN_00277243(param_1,local_28,0x16,param_3);
  if (lVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = strtoull(local_28,(char **)0x0,10);
    *param_2 = uVar3;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002773da FUN_002773da =====

undefined8 FUN_002773da(int param_1,undefined8 *param_2,size_t *param_3)

{
  size_t sVar1;
  undefined8 uVar2;
  void *__ptr;
  size_t sVar3;
  bool bVar4;
  ulong local_20;
  size_t local_18;
  void *local_10;
  
  local_18 = *param_3;
  local_10 = malloc(local_18 + 1);
  if (local_10 == (void *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    local_20 = read(param_1,local_10,local_18 + 1);
    if ((long)local_20 < 0) {
      free(local_10);
      uVar2 = 0xffffffff;
    }
    else {
      if (local_18 + 1 <= local_20) {
        do {
          sVar1 = local_18 * 2;
          __ptr = realloc(local_10,sVar1 + 1);
          if (__ptr == (void *)0x0) {
            free(local_10);
            return 0xffffffff;
          }
          sVar3 = read(param_1,(void *)(local_18 + 1 + (long)__ptr),local_18);
          if ((long)sVar3 < 0) {
            free(__ptr);
            return 0xffffffff;
          }
          local_20 = local_20 + sVar3;
          bVar4 = local_18 == sVar3;
          local_18 = sVar1;
          local_10 = __ptr;
        } while (bVar4);
      }
      *(undefined1 *)(local_20 + (long)local_10) = 0;
      *param_2 = local_10;
      *param_3 = local_18;
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 00277548 FUN_00277548 =====

undefined8 FUN_00277548(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  char *local_58;
  long local_50;
  long local_48;
  void *local_40;
  int local_38;
  int local_34;
  ulong local_30;
  int local_24;
  char *local_20;
  int local_18;
  int local_14;
  void *local_10;
  
  local_14 = 0;
  local_18 = DAT_00380748;
  local_34 = FUN_0027714d(param_1,param_3);
  if (-1 < local_34) {
    local_48 = DAT_01218390;
    if (DAT_01218390 == 0) {
      local_48 = sysconf(0x1e);
    }
    local_38 = FUN_002773da(local_34,&local_58,&local_48);
    close(local_34);
    if (-1 < local_38) {
      DAT_01218390 = local_48;
      local_10 = malloc((long)local_18 << 3);
      if (local_10 != (void *)0x0) {
        FUN_0026180c(param_2);
        local_20 = local_58;
        do {
          iVar1 = sscanf(local_20,"%lx",&local_50);
          if (iVar1 != 1) {
LAB_002776f3:
            free(local_58);
            for (local_24 = 0; local_24 < (local_14 + 1) / 2; local_24 = local_24 + 1) {
              local_30 = *(ulong *)((long)local_10 + (long)(local_14 + local_24 * -2) * 8 + -8);
              if (local_24 * 2 + 1 < local_14) {
                local_30 = local_30 |
                           *(long *)((long)local_10 + (long)(local_14 + local_24 * -2) * 8 + -0x10)
                           << 0x20;
              }
              FUN_00261c9e(param_2,local_24,local_30);
            }
            free(local_10);
            if (DAT_00380748 < local_18) {
              DAT_00380748 = local_18;
            }
            return 0;
          }
          if (local_14 == local_18) {
            local_40 = realloc(local_10,(long)local_18 << 4);
            if (local_40 == (void *)0x0) {
              free(local_10);
              break;
            }
            local_18 = local_18 << 1;
            local_10 = local_40;
          }
          local_20 = strchr(local_20,0x2c);
          if (local_20 == (char *)0x0) {
            *(long *)((long)local_14 * 8 + (long)local_10) = local_50;
            local_20 = (char *)0x0;
            local_14 = local_14 + 1;
            goto LAB_002776f3;
          }
          local_20 = local_20 + 1;
          if ((local_50 != 0) || (local_14 != 0)) {
            *(long *)((long)local_14 * 8 + (long)local_10) = local_50;
            local_14 = local_14 + 1;
          }
        } while( true );
      }
      free(local_58);
    }
  }
  return 0xffffffff;
}


// ===== 002777e0 FUN_002777e0 =====

long FUN_002777e0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_00260eab();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = FUN_00277548(param_1,lVar2,param_2);
    if (iVar1 < 0) {
      FUN_00260f71(lVar2);
      lVar2 = 0;
    }
  }
  return lVar2;
}


// ===== 0027783e FUN_0027783e =====

undefined8 FUN_0027783e(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  char *local_48;
  char *local_40;
  long local_38;
  int local_2c;
  char *local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  char *local_10;
  
  local_38 = sysconf(0x1e);
  local_1c = FUN_0027714d(param_1,param_3);
  if (local_1c < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    local_20 = FUN_002773da(local_1c,&local_40,&local_38);
    close(local_1c);
    if (local_20 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      FUN_0026187f(param_2);
      local_10 = local_40;
      local_14 = -1;
      while( true ) {
        local_28 = strchr(local_10,0x2c);
        if (local_28 != (char *)0x0) {
          *local_28 = '\0';
        }
        uVar3 = strtoul(local_10,&local_48,0);
        local_2c = (int)uVar3;
        iVar1 = local_2c;
        if (*local_48 == '-') {
          uVar3 = strtoul(local_48 + 1,(char **)0x0,0);
          iVar1 = (int)uVar3;
        }
        local_18 = iVar1;
        if (local_14 + 1 <= local_2c + -1) {
          FUN_00261d97(param_2,local_14 + 1,local_2c + -1);
        }
        local_14 = local_18;
        if (local_28 == (char *)0x0) break;
        local_10 = local_28 + 1;
      }
      FUN_00261d97(param_2,local_18 + 1,0xffffffff);
      free(local_40);
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 002779b7 FUN_002779b7 =====

long FUN_002779b7(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_00260f39();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = FUN_0027783e(param_1,lVar2,param_2);
    if (iVar1 < 0) {
      FUN_00260f71(lVar2);
      lVar2 = 0;
    }
  }
  return lVar2;
}


// ===== 00277a15 FUN_00277a15 =====

int FUN_00277a15(undefined8 param_1,__pid_t param_2,undefined8 param_3)

{
  int iVar1;
  int *piVar2;
  ulong uVar3;
  size_t __n;
  cpu_set_t *__cpuset;
  uint local_c;
  
  iVar1 = FUN_00262b2e(param_3);
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    iVar1 = -1;
  }
  else {
    uVar3 = (long)(iVar1 + 1) + 0x3fU >> 6;
    __n = uVar3 << 3;
    __cpuset = __sched_cpualloc((long)(iVar1 + 1));
    memset(__cpuset,0,__n);
    iVar1 = FUN_00262e86(param_3);
    if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(hwloc_set) != -1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                    ,0x36b,"hwloc_linux_set_tid_cpubind");
    }
    for (local_c = FUN_00262aab(param_3); local_c != 0xffffffff;
        local_c = FUN_00262ba7(param_3,local_c)) {
      if ((ulong)local_c < uVar3 << 6) {
        __cpuset->__bits[local_c >> 6] =
             __cpuset->__bits[local_c >> 6] | 1L << ((byte)local_c & 0x3f);
      }
    }
    iVar1 = sched_setaffinity(param_2,__n,__cpuset);
    __sched_cpufree(__cpuset);
  }
  return iVar1;
}


// ===== 00277b6c FUN_00277b6c =====

int FUN_00277b6c(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  cpu_set_t *__cpuset;
  size_t __cpusetsize;
  int local_c;
  
  local_c = DAT_0038074c;
  iVar1 = DAT_0038074c;
  if (DAT_0038074c == -1) {
    if (*(long *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0) != 0) {
      local_c = FUN_00262b2e(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0));
      local_c = local_c + 1;
    }
    if (local_c < 1) {
      local_c = 1;
    }
    lVar3 = FUN_002779b7("/sys/devices/system/cpu/possible",0xffffffff);
    if (lVar3 != 0) {
      iVar1 = FUN_00262b2e(lVar3);
      if (local_c < iVar1 + 1) {
        local_c = iVar1 + 1;
      }
      FUN_00260f71(lVar3);
    }
    while( true ) {
      __cpuset = __sched_cpualloc((long)local_c);
      __cpusetsize = ((long)local_c + 0x3fU >> 6) << 3;
      iVar2 = sched_getaffinity(0,__cpusetsize,__cpuset);
      __sched_cpufree(__cpuset);
      local_c = (int)__cpusetsize;
      iVar1 = local_c << 3;
      if (iVar2 == 0) break;
      local_c = local_c << 4;
    }
  }
  DAT_0038074c = iVar1;
  return DAT_0038074c;
}


// ===== 00277c96 FUN_00277c96 =====

undefined8 FUN_00277c96(long param_1,__pid_t param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  cpu_set_t *__cpuset;
  undefined8 uVar5;
  uint local_10;
  uint local_c;
  
  iVar2 = FUN_00277b6c(param_1);
  uVar4 = (long)iVar2 + 0x3fU >> 6;
  __cpuset = __sched_cpualloc((long)iVar2);
  iVar3 = sched_getaffinity(param_2,uVar4 << 3,__cpuset);
  if (iVar3 < 0) {
    __sched_cpufree(__cpuset);
    uVar5 = 0xffffffff;
  }
  else {
    local_10 = 0xffffffff;
    if (*(long *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0) != 0) {
      local_10 = FUN_00262b2e(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0));
    }
    if (local_10 == 0xffffffff) {
      local_10 = iVar2 - 1;
    }
    FUN_0026180c(param_3);
    for (local_c = 0; local_c <= local_10; local_c = local_c + 1) {
      if (((ulong)local_c < uVar4 << 6) &&
         ((__cpuset->__bits[local_c >> 6] >> ((byte)local_c & 0x3f) & 1) != 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_0026197d(param_3,local_c);
      }
    }
    __sched_cpufree(__cpuset);
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 00277df9 FUN_00277df9 =====

undefined8 FUN_00277df9(DIR *param_1,uint *param_2,undefined8 *param_3)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined1 local_c8 [16];
  uint local_b8;
  void *local_38;
  dirent *local_30;
  void *local_28;
  uint local_20;
  uint local_1c;
  
  local_1c = 0;
  local_20 = 0x20;
  iVar2 = dirfd(param_1);
  iVar2 = FUN_002935c0(iVar2,local_c8);
  if (iVar2 == 0) {
    local_20 = local_b8;
  }
  local_28 = malloc((ulong)local_20 << 2);
  if (local_28 == (void *)0x0) {
    piVar3 = __errno_location();
    *piVar3 = 0xc;
    uVar4 = 0xffffffff;
  }
  else {
    rewinddir(param_1);
    while (local_30 = readdir(param_1), local_30 != (dirent *)0x0) {
      pvVar1 = local_28;
      if (local_1c == local_20) {
        local_20 = local_20 + 8;
        local_38 = realloc(local_28,(ulong)local_20 * 4);
        pvVar1 = local_38;
        if (local_38 == (void *)0x0) {
          free(local_28);
          piVar3 = __errno_location();
          *piVar3 = 0xc;
          return 0xffffffff;
        }
      }
      local_28 = pvVar1;
      iVar2 = strcmp(local_30->d_name,".");
      if ((iVar2 != 0) && (iVar2 = strcmp(local_30->d_name,".."), iVar2 != 0)) {
        piVar3 = (int *)((ulong)local_1c * 4 + (long)local_28);
        local_1c = local_1c + 1;
        iVar2 = atoi(local_30->d_name);
        *piVar3 = iVar2;
      }
    }
    *param_2 = local_1c;
    *param_3 = local_28;
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00277fa1 FUN_00277fa1 =====

int FUN_00277fa1(undefined8 param_1,uint param_2,code *param_3,undefined8 param_4)

{
  int iVar1;
  int *piVar2;
  uint local_c0;
  uint local_bc;
  void *local_b8;
  void *local_b0;
  char local_a8 [128];
  DIR *local_28;
  int local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  if (param_2 == 0) {
    builtin_strncpy(local_a8,"/proc/self/task",0x10);
  }
  else {
    snprintf(local_a8,0x80,"/proc/%u/task",(ulong)param_2);
  }
  local_28 = opendir(local_a8);
  if (local_28 == (DIR *)0x0) {
    piVar2 = __errno_location();
    if (*piVar2 == 2) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
    }
    local_1c = -1;
  }
  else {
    local_1c = FUN_00277df9(local_28,&local_bc,&local_b0);
    if (-1 < local_1c) {
      do {
        local_10 = 0;
        for (local_c = 0; local_c < local_bc; local_c = local_c + 1) {
          local_1c = (*param_3)(param_1,*(undefined4 *)((long)local_b0 + (ulong)local_c * 4),param_4
                                ,local_c);
          if (local_1c < 0) {
            local_10 = local_10 + 1;
            piVar2 = __errno_location();
            local_14 = *piVar2;
          }
        }
        local_1c = FUN_00277df9(local_28,&local_c0,&local_b8);
        if (local_1c < 0) goto LAB_002781f4;
        if (local_c0 == local_bc) {
          iVar1 = memcmp(local_b8,local_b0,(ulong)local_bc * 4);
          if ((iVar1 == 0) && ((local_10 == 0 || (local_10 == local_bc)))) {
            free(local_b8);
            if (local_10 == 0) {
              local_1c = 0;
            }
            else {
              local_1c = -1;
              piVar2 = __errno_location();
              *piVar2 = local_14;
            }
            goto LAB_002781f4;
          }
        }
        free(local_b0);
        local_b0 = local_b8;
        local_bc = local_c0;
        local_18 = local_18 + 1;
      } while (local_18 < 0xb);
      piVar2 = __errno_location();
      *piVar2 = 0xb;
      local_1c = -1;
LAB_002781f4:
      free(local_b0);
    }
    closedir(local_28);
  }
  return local_1c;
}


// ===== 00278217 FUN_00278217 =====

void FUN_00278217(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  FUN_00277a15(param_1,param_2,param_3);
  return;
}


// ===== 00278244 FUN_00278244 =====

void FUN_00278244(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  FUN_00277fa1(param_1,param_2,FUN_00278217,param_3);
  return;
}


// ===== 00278279 FUN_00278279 =====

undefined8 FUN_00278279(undefined8 param_1,undefined4 param_2,undefined8 *param_3,int param_4)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  
  uVar4 = *param_3;
  uVar2 = param_3[1];
  uVar1 = *(uint *)(param_3 + 2);
  iVar3 = FUN_00277c96(param_1,param_2,uVar2);
  if (iVar3 == 0) {
    if (param_4 == 0) {
      FUN_0026180c(uVar4);
    }
    if ((uVar1 & 4) == 0) {
      FUN_00262517(uVar4,uVar4,uVar2);
    }
    else if (param_4 == 0) {
      FUN_00261201(uVar4,uVar2);
    }
    else {
      iVar3 = FUN_00262158(uVar4,uVar2);
      if (iVar3 == 0) {
        piVar5 = __errno_location();
        *piVar5 = 0x12;
        return 0xffffffff;
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


// ===== 00278356 FUN_00278356 =====

undefined4 FUN_00278356(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_14;
  undefined8 local_10;
  
  local_30 = FUN_00260eab();
  local_38 = param_3;
  local_28 = param_4;
  local_10 = local_30;
  local_14 = FUN_00277fa1(param_1,param_2,FUN_00278279,&local_38);
  FUN_00260f71(local_10);
  return local_14;
}


// ===== 002783bc FUN_002783bc =====

void FUN_002783bc(long param_1,int param_2,undefined8 param_3,uint param_4)

{
  undefined4 local_14;
  
  local_14 = param_2;
  if (param_2 == 0) {
    local_14 = *(int *)(param_1 + 0xd4);
  }
  if ((param_4 & 2) == 0) {
    FUN_00278244(param_1,local_14,param_3,param_4);
  }
  else {
    FUN_00277a15(param_1,local_14,param_3);
  }
  return;
}


// ===== 0027841e FUN_0027841e =====

void FUN_0027841e(long param_1,int param_2,undefined8 param_3,uint param_4)

{
  undefined4 local_14;
  
  local_14 = param_2;
  if (param_2 == 0) {
    local_14 = *(int *)(param_1 + 0xd4);
  }
  if ((param_4 & 2) == 0) {
    FUN_00278356(param_1,local_14,param_3,param_4);
  }
  else {
    FUN_00277c96(param_1,local_14,param_3);
  }
  return;
}


// ===== 00278480 FUN_00278480 =====

void FUN_00278480(long param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00278244(param_1,*(undefined4 *)(param_1 + 0xd4),param_2,param_3);
  return;
}


// ===== 002784b2 FUN_002784b2 =====

void FUN_002784b2(long param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00278356(param_1,*(undefined4 *)(param_1 + 0xd4),param_2,param_3);
  return;
}


// ===== 002784e4 FUN_002784e4 =====

undefined8 FUN_002784e4(long param_1,undefined8 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    uVar2 = FUN_00277a15(param_1,0,param_2);
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x26;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 0027852e FUN_0027852e =====

undefined8 FUN_0027852e(long param_1,undefined8 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    uVar2 = FUN_00277c96(param_1,0,param_2);
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x26;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 00278578 FUN_00278578 =====

undefined8 FUN_00278578(long param_1,pthread_t param_2,undefined8 param_3)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  pthread_t pVar4;
  ulong uVar5;
  size_t __n;
  cpu_set_t *__cpuset;
  uint local_c;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    if (PTR_pthread_self_0032efb0 == (undefined *)0x0) {
      piVar2 = __errno_location();
      *piVar2 = 0x26;
      uVar3 = 0xffffffff;
    }
    else {
      pVar4 = pthread_self();
      if (param_2 == pVar4) {
        uVar3 = FUN_00277a15(param_1,0,param_3);
      }
      else if (PTR_pthread_setaffinity_np_0032ef58 == (undefined *)0x0) {
        piVar2 = __errno_location();
        *piVar2 = 0x26;
        uVar3 = 0xffffffff;
      }
      else {
        iVar1 = FUN_00262b2e(param_3);
        if (iVar1 == -1) {
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          uVar3 = 0xffffffff;
        }
        else {
          uVar5 = (long)(iVar1 + 1) + 0x3fU >> 6;
          __n = uVar5 << 3;
          __cpuset = __sched_cpualloc((long)(iVar1 + 1));
          memset(__cpuset,0,__n);
          iVar1 = FUN_00262e86(param_3);
          if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("hwloc_bitmap_weight(hwloc_set) != -1",
                          "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                          ,0x53a,"hwloc_linux_set_thread_cpubind");
          }
          for (local_c = FUN_00262aab(param_3); local_c != 0xffffffff;
              local_c = FUN_00262ba7(param_3,local_c)) {
            if ((ulong)local_c < uVar5 << 6) {
              __cpuset->__bits[local_c >> 6] =
                   __cpuset->__bits[local_c >> 6] | 1L << ((byte)local_c & 0x3f);
            }
          }
          iVar1 = pthread_setaffinity_np(param_2,__n,__cpuset);
          __sched_cpufree(__cpuset);
          if (iVar1 == 0) {
            uVar3 = 0;
          }
          else {
            piVar2 = __errno_location();
            *piVar2 = iVar1;
            uVar3 = 0xffffffff;
          }
        }
      }
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x26;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0027877b FUN_0027877b =====

undefined8 FUN_0027877b(long param_1,pthread_t param_2,undefined8 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  pthread_t pVar6;
  ulong uVar7;
  cpu_set_t *__cpuset;
  uint local_c;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    if (PTR_pthread_self_0032efb0 == (undefined *)0x0) {
      piVar4 = __errno_location();
      *piVar4 = 0x26;
      uVar5 = 0xffffffff;
    }
    else {
      pVar6 = pthread_self();
      if (param_2 == pVar6) {
        uVar5 = FUN_00277c96(param_1,0,param_3);
      }
      else if (PTR_pthread_getaffinity_np_0032ef88 == (undefined *)0x0) {
        piVar4 = __errno_location();
        *piVar4 = 0x26;
        uVar5 = 0xffffffff;
      }
      else {
        uVar2 = FUN_00262b2e(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0));
        if (uVar2 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("last != -1",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                        ,0x58f,"hwloc_linux_get_thread_cpubind");
        }
        uVar7 = (long)(int)(uVar2 + 1) + 0x3fU >> 6;
        __cpuset = __sched_cpualloc((long)(int)(uVar2 + 1));
        iVar3 = pthread_getaffinity_np(param_2,uVar7 << 3,__cpuset);
        if (iVar3 == 0) {
          FUN_0026180c(param_3);
          for (local_c = 0; local_c <= uVar2; local_c = local_c + 1) {
            if (((ulong)local_c < uVar7 << 6) &&
               ((__cpuset->__bits[local_c >> 6] >> ((byte)local_c & 0x3f) & 1) != 0)) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (bVar1) {
              FUN_0026197d(param_3,local_c);
            }
          }
          __sched_cpufree(__cpuset);
          uVar5 = 0;
        }
        else {
          __sched_cpufree(__cpuset);
          piVar4 = __errno_location();
          *piVar4 = iVar3;
          uVar5 = 0xffffffff;
        }
      }
    }
  }
  else {
    piVar4 = __errno_location();
    *piVar4 = 0x26;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ===== 00278967 FUN_00278967 =====

undefined8 FUN_00278967(undefined8 param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  int local_474;
  int local_45c;
  char local_458 [64];
  char local_418 [16];
  undefined8 local_408 [126];
  int local_14;
  char *local_10;
  
  local_418[0] = '\0';
  local_418[1] = '\0';
  local_418[2] = '\0';
  local_418[3] = '\0';
  local_418[4] = '\0';
  local_418[5] = '\0';
  local_418[6] = '\0';
  local_418[7] = '\0';
  local_418[8] = '\0';
  local_418[9] = '\0';
  local_418[10] = '\0';
  local_418[0xb] = '\0';
  local_418[0xc] = '\0';
  local_418[0xd] = '\0';
  local_418[0xe] = '\0';
  local_418[0xf] = '\0';
  puVar5 = local_408;
  for (lVar4 = 0x7e; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_474 = param_2;
  if (param_2 == 0) {
    lVar4 = syscall(0xba);
    local_474 = (int)lVar4;
  }
  snprintf(local_458,0x40,"/proc/%lu/stat",(long)local_474);
  local_14 = FUN_00277243(local_458,local_418,0x400,0xffffffff);
  if (local_14 < 1) {
    piVar2 = __errno_location();
    *piVar2 = 0x26;
    uVar3 = 0xffffffff;
  }
  else {
    local_10 = strrchr(local_418,0x29);
    if (local_10 == (char *)0x0) {
      piVar2 = __errno_location();
      *piVar2 = 0x26;
      uVar3 = 0xffffffff;
    }
    else {
      local_10 = local_10 + 2;
      for (local_45c = 0; local_45c < 0x24; local_45c = local_45c + 1) {
        local_10 = strchr(local_10,0x20);
        if (local_10 == (char *)0x0) {
          piVar2 = __errno_location();
          *piVar2 = 0x26;
          return 0xffffffff;
        }
        local_10 = local_10 + 1;
      }
      iVar1 = sscanf(local_10,"%d ",&local_45c);
      if (iVar1 == 1) {
        FUN_002618f3(param_3,local_45c);
        uVar3 = 0;
      }
      else {
        piVar2 = __errno_location();
        *piVar2 = 0x26;
        uVar3 = 0xffffffff;
      }
    }
  }
  return uVar3;
}


// ===== 00278b23 FUN_00278b23 =====

undefined8 FUN_00278b23(undefined8 param_1,undefined4 param_2,undefined8 *param_3,int param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = *param_3;
  uVar1 = param_3[1];
  iVar2 = FUN_00278967(param_1,param_2,uVar1);
  if (iVar2 == 0) {
    if (param_4 == 0) {
      FUN_0026180c(uVar3);
    }
    FUN_00262517(uVar3,uVar3,uVar1);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 00278ba8 FUN_00278ba8 =====

undefined4 FUN_00278ba8(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_14;
  undefined8 local_10;
  
  local_20 = FUN_00260eab();
  local_28 = param_3;
  local_10 = local_20;
  local_14 = FUN_00277fa1(param_1,param_2,FUN_00278b23,&local_28);
  FUN_00260f71(local_10);
  return local_14;
}


// ===== 00278c08 FUN_00278c08 =====

void FUN_00278c08(long param_1,int param_2,undefined8 param_3,uint param_4)

{
  undefined4 local_14;
  
  local_14 = param_2;
  if (param_2 == 0) {
    local_14 = *(int *)(param_1 + 0xd4);
  }
  if ((param_4 & 2) == 0) {
    FUN_00278ba8(param_1,local_14,param_3,param_4);
  }
  else {
    FUN_00278967(param_1,local_14,param_3);
  }
  return;
}


// ===== 00278c6a FUN_00278c6a =====

void FUN_00278c6a(long param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00278ba8(param_1,*(undefined4 *)(param_1 + 0xd4),param_2,param_3);
  return;
}


// ===== 00278c9c FUN_00278c9c =====

undefined8 FUN_00278c9c(long param_1,undefined8 param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    iVar1 = sched_getcpu();
    if (iVar1 < 0) {
      uVar3 = FUN_00278967(param_1,0,param_2);
    }
    else {
      FUN_002618f3(param_2,iVar1);
      uVar3 = 0;
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x26;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 00278d0c FUN_00278d0c =====

undefined8 FUN_00278d0c(undefined4 *param_1,int param_2,uint param_3)

{
  int *piVar1;
  
  if (param_2 == 1) {
    *param_1 = 4;
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
LAB_00278d83:
      piVar1 = __errno_location();
      *piVar1 = 0x26;
      return 0xffffffff;
    }
    *param_1 = 0;
  }
  else if (param_2 == 2) {
    if ((param_3 & 4) == 0) {
      *param_1 = 5;
    }
    else {
      *param_1 = 2;
    }
  }
  else {
    if (param_2 != 3) goto LAB_00278d83;
    *param_1 = 3;
  }
  return 0;
}


// ===== 00278d9c FUN_00278d9c =====

undefined8 FUN_00278d9c(undefined8 param_1,long param_2,uint *param_3,undefined8 *param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined8 local_48;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = 0;
  iVar1 = FUN_002620fd(param_2);
  local_48 = param_2;
  if (iVar1 != 0) {
    local_48 = FUN_00260eab();
    FUN_002618f3(local_48,0);
    local_28 = local_48;
  }
  local_1c = FUN_00262b2e(local_48);
  if (local_1c == -1) {
    local_1c = 0;
  }
  uVar2 = local_1c + 0x40;
  pvVar3 = calloc((ulong)(uVar2 >> 6),8);
  if (pvVar3 == (void *)0x0) {
    FUN_00260f71(local_28);
    piVar4 = __errno_location();
    *piVar4 = 0xc;
    uVar5 = 0xffffffff;
  }
  else {
    for (local_20 = 0; local_20 < uVar2 >> 6; local_20 = local_20 + 1) {
      uVar5 = FUN_002618ab(local_48,local_20);
      *(undefined8 *)((ulong)local_20 * 8 + (long)pvVar3) = uVar5;
    }
    if (local_28 != 0) {
      FUN_00260f71(local_28);
    }
    *param_3 = uVar2 & 0xffffffc0;
    *param_4 = pvVar3;
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 00278ece FUN_00278ece =====

void FUN_00278ece(undefined8 param_1,undefined8 param_2,uint param_3,long param_4)

{
  undefined4 local_c;
  
  FUN_0026180c(param_2);
  for (local_c = 0; local_c < param_3 >> 6; local_c = local_c + 1) {
    FUN_00261c9e(param_2,local_c,*(undefined8 *)(param_4 + (ulong)local_c * 8));
  }
  return;
}


// ===== 00278f32 FUN_00278f32 =====

ulong FUN_00278f32(undefined8 param_1,ulong param_2,long param_3,undefined8 param_4,
                  undefined4 param_5,uint param_6)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  int *piVar5;
  int local_2c;
  void *local_28;
  int local_1c;
  ulong local_18;
  uint local_10;
  undefined4 local_c;
  
  local_c = 0;
  lVar2 = sysconf(0x1e);
  local_18 = param_2 & lVar2 - 1U;
  lVar2 = param_2 - local_18;
  param_3 = param_3 + local_18;
  local_10 = FUN_00278d0c(&local_2c,param_5,param_6);
  if ((int)local_10 < 0) {
    uVar3 = (ulong)local_10;
  }
  else {
    if ((DAT_00380750 == 1) && (local_2c == 5)) {
      local_2c = 1;
    }
    if (local_2c == 0) {
      uVar3 = FUN_00276da0(lVar2,param_3,0,0,0,0);
    }
    else if (local_2c == 4) {
      uVar4 = FUN_00255653(param_1);
      iVar1 = FUN_00262158(param_4,uVar4);
      if (iVar1 == 0) {
        piVar5 = __errno_location();
        *piVar5 = 0x12;
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = FUN_00276da0(lVar2,param_3,1,0,0,0);
      }
    }
    else {
      local_10 = FUN_00278d9c(param_1,param_4,&local_1c,&local_28);
      if (-1 < (int)local_10) {
        if (((param_6 & 8) != 0) && (local_c = 2, (param_6 & 4) != 0)) {
          local_c = 3;
        }
        local_10 = FUN_00276da0(lVar2,param_3,local_2c,local_28,local_1c + 1,local_c);
        if ((local_2c == 5) && (DAT_00380750 == -1)) {
          if (local_10 == 0) {
            DAT_00380750 = 0;
          }
          else {
            piVar5 = __errno_location();
            if ((*piVar5 == 0x16) &&
               (local_10 = FUN_00276da0(lVar2,param_3,1,local_28,local_1c + 1,local_c),
               local_10 == 0)) {
              FUN_00276d47(
                          "MPOL_PREFERRED_MANY not supported, reverting to MPOL_PREFERRED (with a single node)\n"
                          );
              DAT_00380750 = 1;
            }
          }
        }
        if (-1 < (int)local_10) {
          free(local_28);
          return 0;
        }
        free(local_28);
      }
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}


// ===== 00279180 FUN_00279180 =====

void * FUN_00279180(undefined8 param_1,size_t param_2,undefined8 param_3,undefined4 param_4,
                   uint param_5)

{
  int iVar1;
  void *__addr;
  
  __addr = (void *)FUN_0026054e(param_1,param_2);
  if (__addr == (void *)0x0) {
    __addr = (void *)0x0;
  }
  else {
    iVar1 = FUN_00278f32(param_1,__addr,param_2,param_3,param_4,param_5);
    if ((iVar1 < 0) && ((param_5 & 4) != 0)) {
      munmap(__addr,param_2);
      __addr = (void *)0x0;
    }
  }
  return __addr;
}


// ===== 00279218 FUN_00279218 =====

ulong FUN_00279218(undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  int *piVar4;
  int local_2c;
  void *local_28;
  uint local_1c;
  void *local_18;
  uint local_c;
  
  local_c = FUN_00278d0c(&local_2c,param_3,param_4);
  if ((int)local_c < 0) {
    return (ulong)local_c;
  }
  if ((DAT_00380754 == 1) && (local_2c == 5)) {
    local_2c = 1;
  }
  if (local_2c == 0) {
    uVar2 = FUN_00276df8(0,0,0);
    return uVar2;
  }
  if (local_2c == 4) {
    uVar3 = FUN_00255653(param_1);
    iVar1 = FUN_00262158(param_2,uVar3);
    if (iVar1 != 0) {
      uVar2 = FUN_00276df8(1,0,0);
      return uVar2;
    }
    piVar4 = __errno_location();
    *piVar4 = 0x12;
    return 0xffffffff;
  }
  local_c = FUN_00278d9c(param_1,param_2,&local_1c,&local_28);
  if ((int)local_c < 0) {
    return 0xffffffff;
  }
  if ((param_4 & 8) != 0) {
    local_18 = malloc((ulong)(local_1c >> 6) << 3);
    if (local_18 == (void *)0x0) goto LAB_00279449;
    memset(local_18,0xf,(ulong)(local_1c >> 6) * 8);
    local_c = FUN_00276e72(0,local_1c + 1,local_18,local_28);
    free(local_18);
    if (((int)local_c < 0) && ((param_4 & 4) != 0)) goto LAB_00279449;
  }
  local_c = FUN_00276df8(local_2c,local_28,local_1c + 1);
  if ((local_2c == 5) && (DAT_00380754 == -1)) {
    if (local_c == 0) {
      DAT_00380754 = 0;
    }
    else {
      piVar4 = __errno_location();
      if ((*piVar4 == 0x16) && (local_c = FUN_00276df8(1,local_28,local_1c + 1), local_c == 0)) {
        FUN_00276d47(
                    "MPOL_PREFERRED_MANY not supported, reverting to MPOL_PREFERRED (with a single node)\n"
                    );
        DAT_00380754 = 1;
      }
    }
  }
  if (-1 < (int)local_c) {
    free(local_28);
    return 0;
  }
LAB_00279449:
  free(local_28);
  return 0xffffffff;
}


// ===== 0027945f FUN_0027945f =====

int FUN_0027945f(void)

{
  int iVar1;
  int *piVar2;
  undefined1 local_28 [4];
  int local_24;
  void *local_20;
  int local_14;
  long local_10;
  
  iVar1 = DAT_00380758;
  if (DAT_00380758 == -1) {
    DAT_01218398 = 0x40;
    local_10 = FUN_002779b7("/sys/devices/system/node/possible",0xffffffff);
    if (local_10 != 0) {
      local_14 = FUN_00262b2e(local_10);
      if (DAT_01218398 < local_14 + 1) {
        DAT_01218398 = local_14 + 1;
      }
      FUN_00260f71(local_10);
    }
    while( true ) {
      iVar1 = DAT_01218398;
      if (DAT_01218398 < 0) {
        iVar1 = DAT_01218398 + 0x3f;
      }
      local_20 = malloc((long)(iVar1 >> 6) << 3);
      iVar1 = DAT_01218398;
      if (local_20 == (void *)0x0) break;
      local_24 = FUN_00276e29(local_28,local_20,(long)DAT_01218398,0,0);
      free(local_20);
      if (local_24 == 0) {
        DAT_00380758 = DAT_01218398;
        return DAT_01218398;
      }
      piVar2 = __errno_location();
      if (*piVar2 != 0x16) {
        DAT_00380758 = DAT_01218398;
        return DAT_01218398;
      }
      DAT_01218398 = DAT_01218398 * 2;
    }
  }
  DAT_00380758 = iVar1;
  return iVar1;
}


// ===== 0027958a FUN_0027958a =====

undefined8 FUN_0027958a(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  switch(param_1) {
  case 0:
  case 4:
    *param_2 = 1;
    uVar2 = 0;
    break;
  case 1:
  case 2:
  case 5:
    *param_2 = 2;
    uVar2 = 0;
    break;
  case 3:
    *param_2 = 3;
    uVar2 = 0;
    break;
  default:
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 00279608 FUN_00279608 =====

undefined8 FUN_00279608(uint param_1,long param_2)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (param_1 >> 6 <= local_c) {
      return 1;
    }
    if (*(long *)(param_2 + (ulong)local_c * 8) != 0) break;
    local_c = local_c + 1;
  }
  return 0;
}


// ===== 00279653 FUN_00279653 =====

undefined8 FUN_00279653(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  int local_20;
  int local_1c;
  void *local_18;
  uint local_c;
  
  local_c = FUN_0027945f(param_1);
  local_18 = malloc((ulong)(local_c >> 6) << 3);
  if (local_18 != (void *)0x0) {
    local_1c = FUN_00276e29(&local_20,local_18,local_c,0,0);
    if (-1 < local_1c) {
      if ((local_20 == 1) && (iVar1 = FUN_00279608(local_c,local_18), iVar1 != 0)) {
        local_20 = 4;
      }
      if ((local_20 == 0) || (local_20 == 4)) {
        uVar2 = FUN_00255674(param_1);
        FUN_00261201(param_2,uVar2);
      }
      else {
        FUN_00278ece(param_1,param_2,local_c,local_18);
      }
      local_1c = FUN_0027958a(local_20,param_3);
      if (-1 < local_1c) {
        free(local_18);
        return 0;
      }
    }
    free(local_18);
  }
  return 0xffffffff;
}


// ===== 00279778 FUN_00279778 =====

undefined8
FUN_00279778(undefined8 param_1,ulong param_2,long param_3,undefined8 param_4,undefined4 *param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int local_48;
  int local_44;
  void *local_40;
  void *local_38;
  uint local_2c;
  int local_28;
  uint local_24;
  ulong local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_48 = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_18 = 1;
  lVar2 = sysconf(0x1e);
  local_28 = (int)lVar2;
  local_2c = FUN_0027945f(param_1);
  local_38 = malloc((ulong)(local_2c >> 6) << 3);
  local_40 = malloc((ulong)(local_2c >> 6) << 3);
  if ((local_38 == (void *)0x0) || (local_40 == (void *)0x0)) {
LAB_002799e2:
    free(local_38);
    free(local_40);
    uVar3 = 0xffffffff;
  }
  else {
    memset(local_40,0,8);
    for (local_20 = param_2 & (long)-local_28; local_20 < param_3 + param_2;
        local_20 = local_20 + (long)local_28) {
      local_44 = FUN_00276e29(&local_48,local_38,local_2c,local_20,2);
      if (local_44 < 0) goto LAB_002799e2;
      if ((local_48 == 1) && (iVar1 = FUN_00279608(local_2c,local_38), iVar1 != 0)) {
        local_48 = 4;
      }
      if (local_18 == 0) {
        if (local_c != local_48) {
          local_10 = 1;
        }
      }
      else {
        local_c = local_48;
      }
      if (((local_14 == 0) && (local_48 != 0)) && (local_48 != 4)) {
        for (local_24 = 0; local_24 < local_2c >> 6; local_24 = local_24 + 1) {
          *(ulong *)((long)local_40 + (ulong)local_24 * 8) =
               *(ulong *)((long)local_38 + (ulong)local_24 * 8) |
               *(ulong *)((long)local_40 + (ulong)local_24 * 8);
        }
      }
      else {
        local_14 = 1;
      }
      local_18 = 0;
    }
    if (local_10 == 0) {
      local_44 = FUN_0027958a(local_48,param_5);
      if (local_44 < 0) goto LAB_002799e2;
    }
    else {
      *param_5 = 0xffffffff;
    }
    if (local_14 == 0) {
      FUN_00278ece(param_1,param_4,local_2c,local_40);
    }
    else {
      uVar3 = FUN_00255674(param_1);
      FUN_00261201(param_4,uVar3);
    }
    free(local_38);
    free(local_40);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00279a01 FUN_00279a01 =====

int FUN_00279a01(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  void *__ptr;
  void *__ptr_00;
  undefined4 local_10;
  undefined4 local_c;
  
  lVar3 = sysconf(0x1e);
  iVar1 = (int)lVar3;
  uVar2 = (uint)param_2 & iVar1 - 1U;
  uVar4 = ((param_3 + (ulong)uVar2 + (long)iVar1) - 1) / (ulong)(long)iVar1;
  __ptr = malloc(uVar4 << 3);
  __ptr_00 = malloc(uVar4 << 2);
  if ((__ptr == (void *)0x0) || (__ptr_00 == (void *)0x0)) {
    local_c = -1;
  }
  else {
    for (local_10 = 0; local_10 < uVar4; local_10 = local_10 + 1) {
      *(ulong *)((long)__ptr + (ulong)local_10 * 8) =
           (param_2 - (ulong)uVar2) + (ulong)(iVar1 * local_10);
    }
    local_c = FUN_00276eae(0,uVar4,__ptr,0,__ptr_00,0);
    if (-1 < local_c) {
      FUN_0026180c(param_4);
      for (local_10 = 0; local_10 < uVar4; local_10 = local_10 + 1) {
        if (-1 < *(int *)((long)__ptr_00 + (ulong)local_10 * 4)) {
          FUN_0026197d(param_4,*(undefined4 *)((long)__ptr_00 + (ulong)local_10 * 4));
        }
      }
      local_c = 0;
    }
  }
  free(__ptr);
  free(__ptr_00);
  return local_c;
}


// ===== 00279ba1 FUN_00279ba1 =====

undefined8 FUN_00279ba1(long param_1)

{
  int iVar1;
  void *local_20;
  int local_14;
  char *local_10;
  
  local_20 = (void *)0x0;
  local_14 = -1;
  local_10 = getenv("HWLOC_FSROOT");
  if (local_10 == (char *)0x0) {
    local_10 = "/";
  }
  iVar1 = strcmp(local_10,"/");
  if ((iVar1 == 0) || (local_14 = open(local_10,0x10000), -1 < local_14)) {
    FUN_002833bf(param_1,local_10,local_14,&local_20);
    if (local_20 != (void *)0x0) {
      FUN_0024dd20(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xd8,
                   *(long *)**(undefined8 **)(param_1 + 0x18) + 0xe0,"LinuxCgroup",local_20,1);
      free(local_20);
    }
    if (local_14 != -1) {
      close(local_14);
    }
  }
  return 0xffffffff;
}


// ===== 00279ca4 FUN_00279ca4 =====

void FUN_00279ca4(undefined8 *param_1,long param_2)

{
  param_1[2] = FUN_002784e4;
  param_1[3] = FUN_0027852e;
  *param_1 = FUN_00278480;
  param_1[1] = FUN_002784b2;
  param_1[4] = FUN_002783bc;
  param_1[5] = FUN_0027841e;
  param_1[6] = FUN_00278578;
  param_1[7] = FUN_0027877b;
  param_1[9] = FUN_00278c9c;
  param_1[8] = FUN_00278c6a;
  param_1[10] = FUN_00278c08;
  param_1[0xd] = FUN_00279218;
  param_1[0xe] = FUN_00279653;
  param_1[0x12] = FUN_00279778;
  param_1[0x11] = FUN_00278f32;
  param_1[0x13] = FUN_00279a01;
  param_1[0x15] = FUN_00279180;
  param_1[0x14] = FUN_0026054e;
  param_1[0x16] = FUN_0026059d;
  *(undefined1 *)(*(long *)(param_2 + 0x10) + 9) = 1;
  *(undefined1 *)(*(long *)(param_2 + 0x10) + 10) = 1;
  *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xb) = 1;
  *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xd) = 1;
  param_1[0x17] = FUN_00279ba1;
  return;
}


// ===== 00279e23 FUN_00279e23 =====

void FUN_00279e23(undefined4 *param_1,undefined8 *param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  char local_588 [256];
  char local_488 [1024];
  char *local_88;
  char *local_80;
  undefined1 local_78 [8];
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_50;
  char *local_48;
  char *local_40;
  char *local_38;
  void *local_30;
  size_t local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  long local_10;
  
  *param_2 = 0;
  if (param_3 == 0) {
    local_10 = setmntent("/proc/mounts",&DAT_002f19cb);
  }
  else {
    local_20 = asprintf(&local_50,"%s/proc/mounts",param_3);
    if (local_20 < 0) {
      return;
    }
    local_10 = setmntent(local_50,&DAT_002f19cb);
    free(local_50);
  }
  if (local_10 != 0) {
    lVar2 = sysconf(0x1e);
    local_28 = lVar2 << 2;
    local_30 = malloc(local_28);
    if (local_30 == (void *)0x0) {
      endmntent(local_10);
    }
    else {
      do {
        while( true ) {
          while( true ) {
            lVar2 = getmntent_r(local_10,local_78,local_30,local_28 & 0xffffffff);
            if (lVar2 == 0) goto LAB_0027a23a;
            iVar1 = strcmp(local_68,"cgroup2");
            if (iVar1 == 0) break;
            iVar1 = strcmp(local_68,"cpuset");
            if (iVar1 == 0) {
              FUN_00276d47("Found cpuset mount point on %s\n",local_70);
              *param_1 = 2;
              pcVar3 = strdup(local_70);
              *param_2 = pcVar3;
              goto LAB_0027a23a;
            }
            iVar1 = strcmp(local_68,"cgroup");
            if (iVar1 == 0) {
              local_88 = local_60;
              local_18 = 0;
              local_1c = 0;
              while (local_38 = strsep(&local_88,","), local_38 != (char *)0x0) {
                iVar1 = strcmp(local_38,"cpuset");
                if (iVar1 == 0) {
                  local_18 = 1;
                }
                else {
                  iVar1 = strcmp(local_38,"noprefix");
                  if (iVar1 == 0) {
                    local_1c = 1;
                  }
                }
              }
              if (local_18 != 0) {
                if (local_1c == 0) {
                  FUN_00276d47("Found cgroup1/cpuset mount point on %s\n",local_70);
                  *param_1 = 1;
                  pcVar3 = strdup(local_70);
                  *param_2 = pcVar3;
                }
                else {
                  FUN_00276d47("Found cgroup1 emulating a cpuset mount point on %s\n",local_70);
                  *param_1 = 2;
                  pcVar3 = strdup(local_70);
                  *param_2 = pcVar3;
                }
                goto LAB_0027a23a;
              }
            }
          }
          FUN_00276d47("Found cgroup2 mount point on %s\n",local_70);
          snprintf(local_588,0x100,"%s/cgroup.controllers",local_70);
          local_20 = FUN_00277243(local_588,local_488,0x400,param_4);
          if (0 < local_20) break;
          FUN_00276d47("Failed to read cgroup2 controllers from `%s\'\n",local_588);
        }
        local_80 = local_488;
        local_14 = 0;
        local_40 = strchr(local_488,10);
        if (local_40 != (char *)0x0) {
          *local_40 = '\0';
        }
        FUN_00276d47("Looking for `cpuset\' controller in list `%s\'\n",local_488);
        do {
          local_48 = strsep(&local_80," ");
          if (local_48 == (char *)0x0) goto LAB_0027a02f;
          iVar1 = strcmp(local_48,"cpuset");
        } while (iVar1 != 0);
        local_14 = 1;
LAB_0027a02f:
      } while (local_14 == 0);
      FUN_00276d47("Found cgroup2/cpuset mount point on %s\n",local_70);
      *param_1 = 0;
      pcVar3 = strdup(local_70);
      *param_2 = pcVar3;
LAB_0027a23a:
      endmntent(local_10);
      free(local_30);
    }
  }
  return;
}


// ===== 0027a25a FUN_0027a25a =====

char * FUN_0027a25a(undefined4 param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  char local_1f8 [256];
  char local_f8 [32];
  char local_d8 [32];
  char local_b8 [128];
  char *local_38;
  char *local_30;
  char *local_28;
  char *local_20;
  int local_14;
  FILE *local_10;
  
  if (param_2 == 0) {
    local_14 = FUN_00277243("/proc/self/cpuset",local_b8,0x80,param_1);
  }
  else {
    builtin_strncpy(local_d8,"/proc/XXXXXXXXXXX/cpuset",0x19);
    snprintf(local_d8,0x19,"/proc/%d/cpuset",(ulong)param_2);
    local_14 = FUN_00277243(local_d8,local_b8,0x80,param_1);
  }
  if (local_14 < 1) {
    if (param_2 == 0) {
      local_10 = (FILE *)FUN_0027716f("/proc/self/cgroup",&DAT_002f19cb,param_1);
    }
    else {
      builtin_strncpy(local_f8,"/proc/XXXXXXXXXXX/cgroup",0x19);
      snprintf(local_f8,0x19,"/proc/%d/cgroup",(ulong)param_2);
      local_10 = (FILE *)FUN_0027716f(local_f8,&DAT_002f19cb,param_1);
    }
    if (local_10 == (FILE *)0x0) {
LAB_0027a53f:
      FUN_00276d47(&DAT_002f1d83,"No cgroup or cpuset found\n");
      pcVar2 = (char *)0x0;
    }
    else {
      do {
        do {
          pcVar2 = fgets(local_1f8,0x100,local_10);
          if (pcVar2 == (char *)0x0) {
            fclose(local_10);
            goto LAB_0027a53f;
          }
          local_28 = strchr(local_1f8,0x3a);
        } while (local_28 == (char *)0x0);
        iVar1 = strncmp(local_28,":cpuset:",8);
        if (iVar1 == 0) {
          local_20 = local_28 + 8;
          goto LAB_0027a4bd;
        }
        iVar1 = strncmp(local_28,"::",2);
      } while (iVar1 != 0);
      local_20 = local_28 + 2;
LAB_0027a4bd:
      fclose(local_10);
      local_30 = strchr(local_20,10);
      if (local_30 != (char *)0x0) {
        *local_30 = '\0';
      }
      FUN_00276d47("Found cgroup-cpuset %s\n",local_20);
      pcVar2 = strdup(local_20);
    }
  }
  else {
    local_38 = strchr(local_b8,10);
    if (local_38 != (char *)0x0) {
      *local_38 = '\0';
    }
    FUN_00276d47("Found cgroup name `%s\'\n",local_b8);
    pcVar2 = strdup(local_b8);
  }
  return pcVar2;
}


// ===== 0027a55e FUN_0027a55e =====

void FUN_0027a55e(undefined4 param_1,int param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  char local_118 [268];
  int local_c;
  
  if (param_2 == 1) {
    snprintf(local_118,0x100,"%s%s/cpuset.%s",param_3,param_4,param_5);
    FUN_00276d47("Trying to read cgroup1 file <%s>\n",local_118);
  }
  else if (param_2 == 0) {
    snprintf(local_118,0x100,"%s%s/cpuset.%s.effective",param_3,param_4,param_5);
    FUN_00276d47("Trying to read cgroup2 file <%s>\n",local_118);
  }
  else if (param_2 == 2) {
    snprintf(local_118,0x100,"%s%s/%s",param_3,param_4,param_5);
    FUN_00276d47("Trying to read cpuset file <%s>\n",local_118);
  }
  local_c = FUN_0027783e(local_118,param_6,param_1);
  if (local_c < 0) {
    FUN_00276d47("failed to read cpuset \'%s\' attribute \'%s\'\n",param_4,param_5);
    FUN_0026187f(param_6);
  }
  return;
}


// ===== 0027a71d FUN_0027a71d =====

void FUN_0027a71d(long param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  ulonglong uVar2;
  char local_1018 [4104];
  char *local_10;
  
  lVar1 = FUN_00277243(param_2,local_1018,0x1000,*(undefined4 *)(param_1 + 8));
  if (0 < lVar1) {
    local_10 = strstr(local_1018,"MemTotal: ");
    if (local_10 != (char *)0x0) {
      uVar2 = strtoull(local_10 + 10,(char **)0x0,10);
      *param_3 = uVar2 << 10;
    }
  }
  return;
}


// ===== 0027a7c2 FUN_0027a7c2 =====

void FUN_0027a7c2(long param_1,undefined8 param_2,long param_3,uint param_4,long *param_5)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulonglong uVar4;
  long lVar5;
  uint local_124;
  char local_108 [128];
  char local_88 [76];
  uint local_3c;
  void *local_38;
  dirent *local_30;
  DIR *local_28;
  ulong local_20;
  
  local_20 = 1;
  local_28 = (DIR *)FUN_002771f1(param_2,*(undefined4 *)(param_1 + 8));
  local_124 = param_4;
  if (local_28 != (DIR *)0x0) {
    while (local_30 = readdir(local_28), local_30 != (dirent *)0x0) {
      iVar1 = strncmp(local_30->d_name,"hugepages-",10);
      if (iVar1 == 0) {
        if (local_124 <= local_20) {
          local_38 = realloc(*(void **)(param_3 + 0x10),(ulong)(local_124 * 2) << 4);
          if (local_38 == (void *)0x0) break;
          *(void **)(param_3 + 0x10) = local_38;
          local_124 = local_124 << 1;
        }
        uVar2 = strtoul(local_30->d_name + 10,(char **)0x0,0);
        *(ulong *)(*(long *)(param_3 + 0x10) + local_20 * 0x10) = uVar2 << 10;
        local_3c = snprintf(local_108,0x80,"%s/%s/nr_hugepages",param_2,local_30->d_name);
        if ((local_3c < 0x80) &&
           (lVar3 = FUN_00277243(local_108,local_88,0x40,*(undefined4 *)(param_1 + 8)), 0 < lVar3))
        {
          lVar3 = *(long *)(param_3 + 0x10);
          lVar5 = local_20 * 0x10;
          uVar4 = strtoull(local_88,(char **)0x0,0);
          *(ulonglong *)(lVar3 + lVar5 + 8) = uVar4;
          *param_5 = *param_5 -
                     *(long *)(*(long *)(param_3 + 0x10) + local_20 * 0x10) *
                     *(long *)(*(long *)(param_3 + 0x10) + local_20 * 0x10 + 8);
          local_20 = local_20 + 1;
        }
      }
    }
    closedir(local_28);
    *(int *)(param_3 + 8) = (int)local_20;
  }
  return;
}


// ===== 0027aa1e FUN_0027aa1e =====

void FUN_0027aa1e(long param_1,ulong *param_2)

{
  void *pvVar1;
  ulong local_b0;
  undefined1 local_a8 [16];
  int local_98;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 1;
  local_14 = FUN_002771c2("/sys/kernel/mm/hugepages",local_a8,*(undefined4 *)(param_1 + 8));
  if (local_14 == 0) {
    local_10 = local_98 + -1;
    if (local_10 < 3) {
      local_10 = 3;
    }
    local_c = 1;
  }
  pvVar1 = calloc((long)local_10,0x10);
  param_2[2] = (ulong)pvVar1;
  if (param_2[2] == 0) {
    *(undefined4 *)(param_2 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 1) = 1;
    FUN_0027a71d(param_1,"/proc/meminfo",param_2);
    local_b0 = *param_2;
    if (local_c != 0) {
      FUN_0027a7c2(param_1,"/sys/kernel/mm/hugepages",param_2,local_10,&local_b0);
    }
    *(ulong *)param_2[2] = (ulong)*(uint *)(param_1 + 0x1bc);
    *(ulong *)(param_2[2] + 8) = local_b0 / *(ulong *)param_2[2];
  }
  return;
}


// ===== 0027ab89 FUN_0027ab89 =====

void FUN_0027ab89(long param_1,uint param_2,ulong *param_3)

{
  void *pvVar1;
  ulong local_1b0;
  undefined1 local_1a8 [16];
  int local_198;
  char local_118 [128];
  char local_98 [132];
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 1;
  sprintf(local_98,"/sys/devices/system/node/node%d/hugepages",(ulong)param_2);
  local_14 = FUN_002771c2(local_98,local_1a8,*(undefined4 *)(param_1 + 8));
  if (local_14 == 0) {
    local_10 = local_198 + -1;
    if (local_10 < 3) {
      local_10 = 3;
    }
    local_c = 1;
  }
  pvVar1 = calloc((long)local_10,0x10);
  param_3[2] = (ulong)pvVar1;
  if (param_3[2] == 0) {
    *(undefined4 *)(param_3 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_3 + 1) = 1;
    sprintf(local_118,"/sys/devices/system/node/node%d/meminfo",(ulong)param_2);
    FUN_0027a71d(param_1,local_118,param_3);
    local_1b0 = *param_3;
    if (local_c != 0) {
      FUN_0027a7c2(param_1,local_98,param_3,local_10,&local_1b0);
    }
    *(ulong *)param_3[2] = (ulong)*(uint *)(param_1 + 0x1bc);
    *(ulong *)(param_3[2] + 8) = local_1b0 / *(ulong *)param_3[2];
  }
  return;
}


// ===== 0027ad42 FUN_0027ad42 =====

undefined8 FUN_0027ad42(uint param_1,long param_2,ulong *param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  char local_c8 [128];
  char *local_48;
  undefined4 local_40;
  uint local_3c;
  char *local_38;
  ulong local_30;
  uint local_24;
  char *local_20;
  uint local_14;
  ulong *local_10;
  
  local_30 = (ulong)(param_1 * 0xb);
  local_10 = param_3;
  local_38 = malloc(local_30);
  if (local_38 == (char *)0x0) {
LAB_0027aebf:
    uVar3 = 0xffffffff;
  }
  else {
    for (local_14 = 0; local_14 < param_1; local_14 = local_14 + 1) {
      local_3c = *(uint *)(param_2 + (ulong)local_14 * 4);
      sprintf(local_c8,"/sys/devices/system/node/node%u/distance",(ulong)local_3c);
      lVar1 = FUN_00277243(local_c8,local_38,local_30,param_4);
      if (lVar1 < 1) {
LAB_0027aeb0:
        free(local_38);
        goto LAB_0027aebf;
      }
      local_24 = 0;
      local_20 = local_38;
      while (local_20 != (char *)0x0) {
        uVar2 = strtoul(local_20,&local_48,0);
        local_40 = (undefined4)uVar2;
        if (local_20 == local_48) break;
        *local_10 = uVar2 & 0xffffffff;
        local_10 = local_10 + 1;
        local_24 = local_24 + 1;
        if (local_24 == param_1) break;
        local_20 = local_48 + 1;
      }
      if (local_24 != param_1) goto LAB_0027aeb0;
    }
    free(local_38);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 0027aec6 FUN_0027aec6 =====

void FUN_0027aec6(long param_1,undefined8 param_2,long param_3,uint param_4,char *param_5,
                 undefined8 param_6)

{
  long lVar1;
  char local_58 [72];
  char *local_10;
  
  strcpy((char *)((ulong)param_4 + param_3),param_5);
  lVar1 = FUN_00277243(param_3,local_58,0x40,*(undefined4 *)(param_1 + 8));
  if ((0 < lVar1) && (local_58[0] != '\0')) {
    local_10 = strchr(local_58,10);
    if (local_10 != (char *)0x0) {
      *local_10 = '\0';
    }
    FUN_00276d47("found %s \'%s\'\n",param_6,local_58);
    FUN_0024dfb5(param_2,param_6,local_58);
  }
  return;
}


// ===== 0027af84 FUN_0027af84 =====

void FUN_0027af84(long param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  DIR *local_18;
  uint local_c;
  
  local_98 = 0x7665642f7379732f;
  local_90 = 0x7269762f73656369;
  local_88 = 0x696d642f6c617574;
  local_80 = 0x64692f;
  local_18 = (DIR *)FUN_002771f1(&local_98,*(undefined4 *)(param_1 + 8));
  if (local_18 == (DIR *)0x0) {
    local_98 = 0x616c632f7379732f;
    local_90 = 0x692f696d642f7373;
    local_88 = CONCAT62(local_88._2_6_,100);
    local_18 = (DIR *)FUN_002771f1(&local_98,*(undefined4 *)(param_1 + 8));
    if (local_18 == (DIR *)0x0) {
      return;
    }
    local_c = 0x11;
  }
  else {
    local_c = 0x1b;
  }
  closedir(local_18);
  uVar1 = (ulong)local_c;
  local_c = local_c + 1;
  *(undefined1 *)((long)&local_98 + uVar1) = 0x2f;
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"product_name","DMIProductName");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"product_version","DMIProductVersion");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"product_serial","DMIProductSerial");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"product_uuid","DMIProductUUID");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"board_vendor","DMIBoardVendor");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"board_name","DMIBoardName");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"board_version","DMIBoardVersion");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"board_serial","DMIBoardSerial");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"board_asset_tag","DMIBoardAssetTag");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"chassis_vendor","DMIChassisVendor");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"chassis_type","DMIChassisType");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"chassis_version","DMIChassisVersion");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"chassis_serial","DMIChassisSerial");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"chassis_asset_tag","DMIChassisAssetTag");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"bios_vendor","DMIBIOSVendor");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"bios_version","DMIBIOSVersion");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"bios_date","DMIBIOSDate");
  FUN_0027aec6(param_1,param_2,&local_98,local_c,"sys_vendor","DMISysVendor");
  return;
}


// ===== 0027b3bc FUN_0027b3bc =====

int FUN_0027b3bc(int *param_1,int *param_2)

{
  return *param_1 - *param_2;
}


// ===== 0027b3ea FUN_0027b3ea =====

undefined8 FUN_0027b3ea(uint param_1,long param_2,uint *param_3)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_14;
  uint local_10;
  uint local_c;
  
  *param_3 = 1;
  param_3[4] = 10;
  param_3[5] = 0;
  param_3[2] = param_1;
  if (param_1 == 1) {
    uVar3 = 0;
  }
  else if (((param_1 == 2) || (param_1 == 4)) || (param_1 == 8)) {
    if (param_2 == 0) {
      iVar2 = FUN_0024d64f();
      if (iVar2 < 2) {
        fwrite("hwloc/linux: Ignoring KNL NUMA quirk, distance matrix missing.\n",1,0x3f,
               *(FILE **)PTR_stderr_0032efe0);
      }
      uVar3 = 0xffffffff;
    }
    else {
      for (local_c = 0; local_c < param_1; local_c = local_c + 1) {
        local_10 = local_c;
        if (*(long *)(param_2 + (ulong)((param_1 + 1) * local_c) * 8) != 10) {
          iVar2 = FUN_0024d64f();
          if (iVar2 < 2) {
            fwrite("hwloc/linux: hwloc/linux: Ignoring KNL NUMA quirk, distance matrix does not contain 10 on the diagonal.\n"
                   ,1,0x68,*(FILE **)PTR_stderr_0032efe0);
          }
          return 0xffffffff;
        }
        while (local_10 = local_10 + 1, local_10 < param_1) {
          uVar1 = *(ulong *)(param_2 + (ulong)(local_10 + local_c * param_1) * 8);
          if (uVar1 != *(ulong *)(param_2 + (ulong)(local_c + local_10 * param_1) * 8)) {
            iVar2 = FUN_0024d64f();
            if (iVar2 < 2) {
              fwrite("hwloc/linux: Ignoring KNL NUMA quirk, distance matrix isn\'t symmetric.\n",1,
                     0x47,*(FILE **)PTR_stderr_0032efe0);
            }
            return 0xffffffff;
          }
          if (uVar1 < 0xb) {
            iVar2 = FUN_0024d64f();
            if (iVar2 < 2) {
              fwrite("hwloc/linux: Ignoring KNL NUMA quirk, distance matrix contains values <= 10.\n"
                     ,1,0x4d,*(FILE **)PTR_stderr_0032efe0);
            }
            return 0xffffffff;
          }
          for (local_14 = 0; local_14 < *param_3; local_14 = local_14 + 1) {
            if (uVar1 == *(ulong *)(param_3 + (ulong)local_14 * 4 + 4)) {
              param_3[(ulong)local_14 * 4 + 2] = param_3[(ulong)local_14 * 4 + 2] + 1;
              break;
            }
          }
          if (local_14 == *param_3) {
            if (local_14 == 4) {
              iVar2 = FUN_0024d64f();
              if (iVar2 < 2) {
                fwrite("hwloc/linux: Ignoring KNL NUMA quirk, distance matrix contains more than 4 different values.\n"
                       ,1,0x5d,*(FILE **)PTR_stderr_0032efe0);
              }
              return 0xffffffff;
            }
            *(ulong *)(param_3 + (ulong)local_14 * 4 + 4) = uVar1;
            param_3[(ulong)local_14 * 4 + 2] = 1;
            *param_3 = *param_3 + 1;
          }
        }
      }
      qsort(param_3 + 2,(ulong)*param_3,0x10,FUN_0027b3bc);
      if (param_1 == 2) {
        if (*param_3 != 2) {
          iVar2 = FUN_0024d64f();
          if (iVar2 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc/linux: Ignoring KNL NUMA quirk, distance matrix for 2 nodes cannot contain %u different values instead of 2.\n"
                    ,(ulong)*param_3);
          }
          return 0xffffffff;
        }
      }
      else if (param_1 == 4) {
        if ((*param_3 != 2) && (*param_3 != 4)) {
          iVar2 = FUN_0024d64f();
          if (iVar2 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc/linux: Ignoring KNL NUMA quirk, distance matrix for 8 nodes cannot contain %u different values instead of 2 or 4.\n"
                    ,(ulong)*param_3);
          }
          return 0xffffffff;
        }
      }
      else {
        if (param_1 != 8) {
                    /* WARNING: Subroutine does not return */
          abort();
        }
        if (*param_3 != 4) {
          iVar2 = FUN_0024d64f();
          if (iVar2 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc/linux: Ignoring KNL NUMA quirk, distance matrix for 8 nodes cannot contain %u different values instead of 4.\n"
                    ,(ulong)*param_3);
          }
          return 0xffffffff;
        }
      }
      FUN_00276d47("Summary of KNL distance matrix:\n");
      for (local_14 = 0; local_14 < *param_3; local_14 = local_14 + 1) {
        FUN_00276d47("  Found %u times distance %llu\n",param_3[(ulong)local_14 * 4 + 2],
                     *(undefined8 *)(param_3 + (ulong)local_14 * 4 + 4));
      }
      uVar3 = 0;
    }
  }
  else {
    iVar2 = FUN_0024d64f();
    if (iVar2 < 2) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc/linux: Ignoring KNL NUMA quirk, nbnodes (%u) isn\'t 2, 4 or 8.\n",
              (ulong)param_1);
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0027b876 FUN_0027b876 =====

undefined8 FUN_0027b876(long param_1,int *param_2,undefined4 *param_3,uint *param_4)

{
  long lVar1;
  undefined8 uVar2;
  uint local_c;
  
  FUN_00276d47("Trying to identify 4 KNL NUMA nodes in SNC-2 cluster mode...\n");
  if ((((*param_2 == 4) && (param_2[2] == 1)) && (param_2[6] == 2)) &&
     ((param_2[10] == 3 && (param_2[0xe] == 4)))) {
    *param_3 = 0;
    lVar1 = *(long *)(param_2 + 4);
    param_3[1] = 0;
    FUN_00276d47("  DDR#0 is NUMAnode#0\n");
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if (lVar1 == *(long *)(param_1 + (ulong)local_c * 8)) {
        param_3[1] = local_c;
        FUN_00276d47("  DDR#1 is NUMAnode#%u\n",local_c);
        break;
      }
    }
    if (param_3[1] == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      lVar1 = *(long *)(param_2 + 8);
      param_4[1] = 0;
      *param_4 = param_4[1];
      for (local_c = 1; local_c < 4; local_c = local_c + 1) {
        if (lVar1 == *(long *)(param_1 + (ulong)local_c * 8)) {
          FUN_00276d47("  MCDRAM#0 is NUMAnode#%u\n",local_c);
          *param_4 = local_c;
        }
        else if (lVar1 == *(long *)(param_1 + (ulong)(local_c + param_3[1] * 4) * 8)) {
          FUN_00276d47("  MCDRAM#1 is NUMAnode#%u\n",local_c);
          param_4[1] = local_c;
        }
      }
      if ((*param_4 == 0) || (param_4[1] == 0)) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 0027ba75 FUN_0027ba75 =====

undefined8 FUN_0027ba75(long param_1,int *param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  uint local_10;
  uint local_c;
  
  FUN_00276d47("Trying to identify 8 KNL NUMA nodes in SNC-4 cluster mode...\n");
  if ((((*param_2 == 4) && (param_2[2] == 4)) && (param_2[6] == 6)) &&
     ((param_2[10] == 8 && (param_2[0xe] == 0x12)))) {
    *param_3 = 0;
    FUN_00276d47("  DDR#0 is NUMAnode#0\n");
    lVar2 = *(long *)(param_2 + 8);
    param_3[3] = 0;
    param_3[2] = param_3[3];
    param_3[1] = param_3[2];
    local_10 = 1;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (lVar2 == *(long *)(param_1 + (ulong)local_c * 8)) {
        FUN_00276d47("  DDR#%u is NUMAnode#%u\n",local_10,local_c);
        uVar1 = local_10 + 1;
        param_3[local_10] = local_c;
        local_10 = uVar1;
        if (uVar1 == 4) break;
      }
    }
    if (((local_10 == 4) && (param_3[1] != 0)) && ((param_3[2] != 0 && (param_3[3] != 0)))) {
      lVar2 = *(long *)(param_2 + 4);
      param_4[3] = 0;
      param_4[2] = param_4[3];
      param_4[1] = param_4[2];
      *param_4 = param_4[1];
      for (local_c = 1; local_c < 8; local_c = local_c + 1) {
        if (lVar2 == *(long *)(param_1 + (ulong)local_c * 8)) {
          FUN_00276d47("  MCDRAM#0 is NUMAnode#%u\n",local_c);
          *param_4 = local_c;
        }
        else if (lVar2 == *(long *)(param_1 + (ulong)(local_c + param_3[1] * 8) * 8)) {
          FUN_00276d47("  MCDRAM#1 is NUMAnode#%u\n",local_c);
          param_4[1] = local_c;
        }
        else if (lVar2 == *(long *)(param_1 + (ulong)(local_c + param_3[2] * 8) * 8)) {
          FUN_00276d47("  MCDRAM#2 is NUMAnode#%u\n",local_c);
          param_4[2] = local_c;
        }
        else if (lVar2 == *(long *)(param_1 + (ulong)(local_c + param_3[3] * 8) * 8)) {
          FUN_00276d47("  MCDRAM#3 is NUMAnode#%u\n",local_c);
          param_4[3] = local_c;
        }
      }
      if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0027bdb5 FUN_0027bdb5 =====

undefined8 FUN_0027bdb5(long param_1,void *param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  char local_238 [516];
  int local_34;
  char *local_30;
  char *local_28;
  size_t local_20;
  size_t local_18;
  char *local_10;
  
  local_34 = 0;
  pcVar4 = local_238;
  for (lVar5 = 0x40; lVar5 != 0; lVar5 = lVar5 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  local_10 = (char *)0x0;
  iVar1 = asprintf(&local_30,"%s/knl_memoryside_cache",*(undefined8 *)(param_1 + 0x10));
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_00276d47("Reading knl cache data from: %s\n",local_30);
    lVar5 = FUN_00277243(local_30,local_238,0x200,*(undefined4 *)(param_1 + 8));
    if (lVar5 < 1) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      FUN_00276d47("Unable to open KNL data file `%s\' (%s)\n",local_30,pcVar4);
      free(local_30);
      uVar2 = 0xffffffff;
    }
    else {
      free(local_30);
      local_10 = local_238;
      iVar1 = sscanf(local_10,"version: %d",&local_34);
      if (iVar1 == 1) {
        while( true ) {
          local_28 = strchr(local_10,10);
          if (local_28 == (char *)0x0) break;
          if (0 < local_34) {
            iVar1 = strncmp("cache_size:",local_10,10);
            if (iVar1 == 0) {
              sscanf(local_10,"cache_size: %lld",(long)param_2 + 0x40);
              FUN_00276d47("read cache_size=%lld\n",*(undefined8 *)((long)param_2 + 0x40));
            }
            else {
              iVar1 = strncmp("line_size:",local_10,10);
              if (iVar1 == 0) {
                sscanf(local_10,"line_size: %d",(long)param_2 + 0x50);
                FUN_00276d47("read line_size=%d\n",*(undefined4 *)((long)param_2 + 0x50));
              }
              else {
                iVar1 = strncmp("inclusiveness:",local_10,0xe);
                if (iVar1 == 0) {
                  sscanf(local_10,"inclusiveness: %d",(long)param_2 + 0x4c);
                  FUN_00276d47("read inclusiveness=%d\n",*(undefined4 *)((long)param_2 + 0x4c));
                }
                else {
                  iVar1 = strncmp("associativity:",local_10,0xe);
                  if (iVar1 == 0) {
                    sscanf(local_10,"associativity: %d\n",(long)param_2 + 0x48);
                    FUN_00276d47("read associativity=%d\n",*(undefined4 *)((long)param_2 + 0x48));
                  }
                }
              }
            }
          }
          if (1 < local_34) {
            iVar1 = strncmp("cluster_mode: ",local_10,0xe);
            if (iVar1 == 0) {
              local_10 = local_10 + 0xe;
              local_18 = (long)local_28 - (long)local_10;
              if (0x1f < local_18) {
                local_18 = 0x1f;
              }
              memcpy((void *)((long)param_2 + 0x20),local_10,local_18);
              *(undefined1 *)((long)param_2 + local_18 + 0x20) = 0;
              FUN_00276d47("read cluster_mode=%s\n",(long)param_2 + 0x20);
            }
            else {
              iVar1 = strncmp("memory_mode: ",local_10,0xd);
              if (iVar1 == 0) {
                local_10 = local_10 + 0xd;
                local_20 = (long)local_28 - (long)local_10;
                if (0x1f < local_20) {
                  local_20 = 0x1f;
                }
                memcpy(param_2,local_10,local_20);
                *(undefined1 *)(local_20 + (long)param_2) = 0;
                FUN_00276d47("read memory_mode=%s\n",param_2);
              }
            }
          }
          local_10 = local_28 + 1;
        }
        if ((((*(long *)((long)param_2 + 0x40) == -1) || (*(int *)((long)param_2 + 0x50) == -1)) ||
            (*(int *)((long)param_2 + 0x48) == -1)) || (*(int *)((long)param_2 + 0x4c) == -1)) {
          FUN_00276d47("Incorrect file format cache_size=%lld line_size=%d associativity=%d inclusiveness=%d\n"
                       ,*(undefined8 *)((long)param_2 + 0x40),*(undefined4 *)((long)param_2 + 0x50),
                       *(undefined4 *)((long)param_2 + 0x48),*(undefined4 *)((long)param_2 + 0x4c));
          *(undefined8 *)((long)param_2 + 0x40) = 0xffffffffffffffff;
        }
        uVar2 = 0;
      }
      else {
        fwrite("hwloc/linux/hwdata: Invalid knl_memoryside_cache header, expected \"version: <int>\".\n"
               ,1,0x54,*(FILE **)PTR_stderr_0032efe0);
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}


// ===== 0027c286 FUN_0027c286 =====

void FUN_0027c286(char *param_1,long param_2,int param_3,int *param_4)

{
  int iVar1;
  
  FUN_00276d47("Trying to guess missing KNL configuration information...\n");
  param_1[0x48] = '\x01';
  param_1[0x49] = '\0';
  param_1[0x4a] = '\0';
  param_1[0x4b] = '\0';
  param_1[0x4c] = '\x01';
  param_1[0x4d] = '\0';
  param_1[0x4e] = '\0';
  param_1[0x4f] = '\0';
  param_1[0x50] = '@';
  param_1[0x51] = '\0';
  param_1[0x52] = '\0';
  param_1[0x53] = '\0';
  if (((0 < *(long *)(param_1 + 0x40)) && (param_1[0x20] != '\0')) && (*param_1 != '\0')) {
    return;
  }
  if (param_3 == 1) {
    if (param_1[0x20] == '\0') {
      builtin_strncpy(param_1 + 0x20,"Quadrant",9);
    }
    if (*param_1 == '\0') {
      builtin_strncpy(param_1,"Cache",6);
    }
    if (*(long *)(param_1 + 0x40) < 1) {
      param_1[0x40] = '\0';
      param_1[0x41] = '\0';
      param_1[0x42] = '\0';
      param_1[0x43] = '\0';
      param_1[0x44] = '\x04';
      param_1[0x45] = '\0';
      param_1[0x46] = '\0';
      param_1[0x47] = '\0';
    }
  }
  else if (param_3 == 2) {
    iVar1 = strcmp(param_1,"Cache");
    if (((iVar1 == 0) || (iVar1 = strcmp(param_1 + 0x20,"SNC2"), iVar1 == 0)) ||
       (iVar1 = FUN_002620a3(*(undefined8 *)(*(long *)(param_2 + 8) + 0xb8)), iVar1 == 0)) {
      if (param_1[0x20] == '\0') {
        builtin_strncpy(param_1 + 0x20,"SNC2",5);
      }
      if (*param_1 == '\0') {
        builtin_strncpy(param_1,"Cache",6);
      }
      if (*(long *)(param_1 + 0x40) < 1) {
        param_1[0x40] = '\0';
        param_1[0x41] = '\0';
        param_1[0x42] = '\0';
        param_1[0x43] = '\0';
        param_1[0x44] = '\x02';
        param_1[0x45] = '\0';
        param_1[0x46] = '\0';
        param_1[0x47] = '\0';
      }
    }
    else {
      if (param_1[0x20] == '\0') {
        builtin_strncpy(param_1 + 0x20,"Quadrant",9);
      }
      if (*param_1 == '\0') {
        if (*(long *)(param_1 + 0x40) == 0x100000000) {
          builtin_strncpy(param_1,"Hybrid25",9);
        }
        else if (*(long *)(param_1 + 0x40) == 0x200000000) {
          builtin_strncpy(param_1,"Hybrid50",9);
        }
        else {
          builtin_strncpy(param_1,"Flat",5);
        }
      }
      else if (*(long *)(param_1 + 0x40) < 1) {
        iVar1 = strcmp(param_1,"Hybrid25");
        if (iVar1 == 0) {
          param_1[0x40] = '\0';
          param_1[0x41] = '\0';
          param_1[0x42] = '\0';
          param_1[0x43] = '\0';
          param_1[0x44] = '\x01';
          param_1[0x45] = '\0';
          param_1[0x46] = '\0';
          param_1[0x47] = '\0';
        }
        else {
          iVar1 = strcmp(param_1,"Hybrid50");
          if (iVar1 == 0) {
            param_1[0x40] = '\0';
            param_1[0x41] = '\0';
            param_1[0x42] = '\0';
            param_1[0x43] = '\0';
            param_1[0x44] = '\x02';
            param_1[0x45] = '\0';
            param_1[0x46] = '\0';
            param_1[0x47] = '\0';
          }
        }
      }
    }
  }
  else if (param_3 == 4) {
    iVar1 = strcmp(param_1 + 0x20,"SNC2");
    if ((iVar1 == 0) || (*param_4 == 4)) {
      if (param_1[0x20] == '\0') {
        builtin_strncpy(param_1 + 0x20,"SNC2",5);
      }
      if (*param_1 == '\0') {
        if (*(long *)(param_1 + 0x40) == 0x80000000) {
          builtin_strncpy(param_1,"Hybrid25",9);
        }
        else if (*(long *)(param_1 + 0x40) == 0x100000000) {
          builtin_strncpy(param_1,"Hybrid50",9);
        }
        else {
          builtin_strncpy(param_1,"Flat",5);
        }
      }
      else if (*(long *)(param_1 + 0x40) < 1) {
        iVar1 = strcmp(param_1,"Hybrid25");
        if (iVar1 == 0) {
          param_1[0x40] = '\0';
          param_1[0x41] = '\0';
          param_1[0x42] = '\0';
          param_1[0x43] = -0x80;
          param_1[0x44] = '\0';
          param_1[0x45] = '\0';
          param_1[0x46] = '\0';
          param_1[0x47] = '\0';
        }
        else {
          iVar1 = strcmp(param_1,"Hybrid50");
          if (iVar1 == 0) {
            param_1[0x40] = '\0';
            param_1[0x41] = '\0';
            param_1[0x42] = '\0';
            param_1[0x43] = '\0';
            param_1[0x44] = '\x01';
            param_1[0x45] = '\0';
            param_1[0x46] = '\0';
            param_1[0x47] = '\0';
          }
        }
      }
    }
    else {
      if (param_1[0x20] == '\0') {
        builtin_strncpy(param_1 + 0x20,"SNC4",5);
      }
      if (*param_1 == '\0') {
        builtin_strncpy(param_1,"Cache",6);
      }
      if (*(long *)(param_1 + 0x40) < 1) {
        param_1[0x40] = '\0';
        param_1[0x41] = '\0';
        param_1[0x42] = '\0';
        param_1[0x43] = '\0';
        param_1[0x44] = '\x01';
        param_1[0x45] = '\0';
        param_1[0x46] = '\0';
        param_1[0x47] = '\0';
      }
    }
  }
  else if (param_3 == 8) {
    if (param_1[0x20] == '\0') {
      builtin_strncpy(param_1 + 0x20,"SNC4",5);
    }
    if (*param_1 == '\0') {
      if (*(long *)(param_1 + 0x40) == 0x40000000) {
        builtin_strncpy(param_1,"Hybrid25",9);
      }
      else if (*(long *)(param_1 + 0x40) == 0x80000000) {
        builtin_strncpy(param_1,"Hybrid50",9);
      }
      else {
        builtin_strncpy(param_1,"Flat",5);
      }
    }
    else if (*(long *)(param_1 + 0x40) < 1) {
      iVar1 = strcmp(param_1,"Hybrid25");
      if (iVar1 == 0) {
        param_1[0x40] = '\0';
        param_1[0x41] = '\0';
        param_1[0x42] = '\0';
        param_1[0x43] = '@';
        param_1[0x44] = '\0';
        param_1[0x45] = '\0';
        param_1[0x46] = '\0';
        param_1[0x47] = '\0';
      }
      else {
        iVar1 = strcmp(param_1,"Hybrid50");
        if (iVar1 == 0) {
          param_1[0x40] = '\0';
          param_1[0x41] = '\0';
          param_1[0x42] = '\0';
          param_1[0x43] = -0x80;
          param_1[0x44] = '\0';
          param_1[0x45] = '\0';
          param_1[0x46] = '\0';
          param_1[0x47] = '\0';
        }
      }
    }
  }
  FUN_00276d47("  Found cluster=%s memory=%s cache=%lld\n",param_1 + 0x20,param_1,
               *(undefined8 *)(param_1 + 0x40));
  return;
}


// ===== 0027c7ef FUN_0027c7ef =====

void FUN_0027c7ef(long param_1,long param_2,long param_3,long param_4,int param_5,int param_6,
                 int *param_7)

{
  char *pcVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long local_70;
  long local_68;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined4 *local_38;
  long local_30;
  long local_28;
  long local_20;
  long local_18;
  long local_10;
  
  local_10 = 0;
  if (param_3 != 0) {
    pcVar1 = strdup("MCDRAM");
    *(char **)(param_3 + 8) = pcVar1;
    FUN_00261201(*(undefined8 *)(param_3 + 0xb8),*(undefined8 *)(param_2 + 0xb8));
    local_10 = FUN_0024febd(param_1,0xc,0xffffffff);
    FUN_00250615(local_10,param_2);
    FUN_00250615(local_10,param_3);
    pcVar1 = strdup("Cluster");
    *(char **)(local_10 + 8) = pcVar1;
    *(undefined4 *)(*(long *)(local_10 + 0x28) + 4) = 100;
    local_10 = FUN_0024fb45(param_1,0,local_10,"linux:knl:snc:group");
  }
  local_70 = param_3;
  local_68 = param_2;
  if (local_10 == 0) {
    local_18 = FUN_0024fb45(param_1,0,param_2,"linux:knl:ddr");
    if (local_18 != param_2) {
      *param_7 = *param_7 + 1;
      local_68 = 0;
    }
    if (param_3 != 0) {
      local_18 = FUN_0024fb45(param_1,0,param_3,"linux:knl:mcdram");
      if (local_18 != param_3) {
        *param_7 = *param_7 + 1;
        local_70 = 0;
      }
    }
  }
  else {
    local_20 = FUN_0024f974(param_1,local_10,param_2,"linux:knl:snc:ddr");
    if (local_20 != param_2) {
      *param_7 = *param_7 + 1;
      local_68 = 0;
    }
    local_20 = FUN_0024f974(param_1,local_10,param_3,"linux:knl:snc:mcdram");
    if (local_20 != param_3) {
      *param_7 = *param_7 + 1;
      local_70 = 0;
    }
  }
  if (((local_68 != 0) && (local_70 != 0)) && ((*(ulong *)(param_1 + 0x20) & 0x100) == 0)) {
    local_28 = (long)(int)(90000 / (long)param_6);
    local_30 = (long)(int)(360000 / (long)param_6);
    local_58[0] = 1;
    local_50 = *(undefined8 *)(local_68 + 0xb8);
    FUN_0025c155(param_1,2,0xd,0xffffffffffffffff,*(undefined4 *)(local_68 + 0x10),local_58,local_28
                );
    FUN_0025c155(param_1,2,0xd,0xffffffffffffffff,*(undefined4 *)(local_70 + 0x10),local_58,local_30
                );
  }
  if ((local_68 != 0) && (0 < *(long *)(param_4 + 0x40))) {
    local_38 = (undefined4 *)FUN_0024febd(param_1,6,0xffffffff);
    if (local_38 != (undefined4 *)0x0) {
      *(undefined4 *)(*(long *)(local_38 + 10) + 8) = 3;
      *(undefined4 *)(*(long *)(local_38 + 10) + 0x14) = 0;
      **(undefined8 **)(local_38 + 10) = *(undefined8 *)(param_4 + 0x40);
      *(undefined4 *)(*(long *)(local_38 + 10) + 0xc) = *(undefined4 *)(param_4 + 0x50);
      *(undefined4 *)(*(long *)(local_38 + 10) + 0x10) = *(undefined4 *)(param_4 + 0x48);
      if (*(int *)(param_4 + 0x4c) == 0) {
        puVar2 = &DAT_002f295c;
      }
      else {
        puVar2 = &DAT_002f295a;
      }
      FUN_0024dfb5(local_38,"Inclusive",puVar2);
      uVar3 = FUN_002611e2(*(undefined8 *)(local_68 + 0xb8));
      *(undefined8 *)(local_38 + 0x2e) = uVar3;
      uVar3 = FUN_002611e2(*(undefined8 *)(local_68 + 200));
      *(undefined8 *)(local_38 + 0x32) = uVar3;
      if (param_5 == 0) {
        *local_38 = 0x12;
        local_38[0xc] = 1;
        if (local_10 == 0) {
          FUN_0024fb45(param_1,0,local_38,"linux:knl:memcache");
        }
        else {
          FUN_0024f974(param_1,local_10,local_38,"linux:knl:snc:memcache");
        }
      }
      else {
        pcVar1 = strdup("MemorySideCache");
        *(char **)(local_38 + 2) = pcVar1;
        FUN_0024fb45(param_1,0,local_38,"linux:knl:memcache:l3cache");
      }
    }
  }
  return;
}


// ===== 0027cc6d FUN_0027cc6d =====

void FUN_0027cc6d(long param_1,undefined8 param_2,undefined8 *param_3,uint param_4,
                 undefined8 param_5,int *param_6)

{
  int iVar1;
  uint local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  uint local_108;
  uint local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  undefined1 local_e8 [80];
  char local_98 [32];
  char local_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  long local_40;
  long local_38;
  int local_2c;
  char *local_28;
  int local_1c;
  char *local_18;
  uint local_c;
  
  local_18 = getenv("HWLOC_KNL_HDH_FALLBACK");
  if (local_18 == (char *)0x0) {
    local_1c = -1;
  }
  else {
    local_1c = atoi(local_18);
  }
  local_28 = getenv("HWLOC_KNL_MSCACHE_L3");
  if (local_28 == (char *)0x0) {
    local_2c = 1;
  }
  else {
    local_2c = atoi(local_28);
  }
  if ((*param_6 == 0) && (iVar1 = FUN_0027b3ea(param_4,param_5,local_e8), -1 < iVar1)) {
    local_98[0] = '\0';
    local_78[0] = '\0';
    local_58 = 0xffffffffffffffff;
    local_50 = 0xffffffff;
    local_4c = 0xffffffff;
    local_48 = 0xffffffff;
    if (local_1c == 1) {
      FUN_00276d47("KNL dumped hwdata ignored, forcing fallback to heuristics\n");
    }
    else {
      FUN_0027bdb5(param_2,local_98);
    }
    if (local_1c != 0) {
      FUN_0027c286(local_98,param_3,param_4,local_e8);
    }
    iVar1 = strcmp(local_78,"All2All");
    if ((((iVar1 == 0) || (iVar1 = strcmp(local_78,"Hemisphere"), iVar1 == 0)) ||
        (iVar1 = strcmp(local_78,"Quadrant"), iVar1 == 0)) ||
       ((iVar1 = strcmp(local_78,"SNC2"), iVar1 == 0 ||
        (iVar1 = strcmp(local_78,"SNC4"), iVar1 == 0)))) {
      iVar1 = strcmp(local_98,"Cache");
      if (((iVar1 == 0) ||
          ((iVar1 = strcmp(local_98,"Flat"), iVar1 == 0 ||
           (iVar1 = strcmp(local_98,"Hybrid25"), iVar1 == 0)))) ||
         (iVar1 = strcmp(local_98,"Hybrid50"), iVar1 == 0)) {
        if (local_2c == 0) {
          iVar1 = FUN_00276ce7(param_1,0x12);
          if (iVar1 == 0) {
            local_58 = 0;
          }
        }
        else {
          iVar1 = FUN_00276ce7(param_1,6);
          if (iVar1 == 0) {
            local_58 = 0;
          }
        }
        FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"ClusterMode",local_78);
        FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"MemoryMode",local_98);
        iVar1 = strcmp(local_78,"All2All");
        if (((iVar1 == 0) || (iVar1 = strcmp(local_78,"Hemisphere"), iVar1 == 0)) ||
           (iVar1 = strcmp(local_78,"Quadrant"), iVar1 == 0)) {
          iVar1 = strcmp(local_98,"Cache");
          if (iVar1 == 0) {
            if (param_4 == 1) {
              FUN_0027c7ef(param_1,*param_3,0,local_98,local_2c,1,param_6);
              return;
            }
            iVar1 = FUN_0024d64f();
            if (iVar1 < 2) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "hwloc/linux: Found %u NUMA nodes instead of 1 in mode %s-%s\n",(ulong)param_4
                      ,local_78,local_98);
            }
          }
          else {
            if (param_4 == 2) {
              iVar1 = strcmp(local_98,"Flat");
              if (iVar1 == 0) {
                local_58 = 0;
              }
              FUN_0027c7ef(param_1,*param_3,param_3[1],local_98,local_2c,1,param_6);
              return;
            }
            iVar1 = FUN_0024d64f();
            if (iVar1 < 2) {
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "hwloc/linux: Found %u NUMA nodes instead of 2 in mode %s-%s\n",(ulong)param_4
                      ,local_78,local_98);
            }
          }
        }
        else {
          iVar1 = strcmp(local_78,"SNC2");
          if (iVar1 == 0) {
            iVar1 = strcmp(local_98,"Cache");
            if (iVar1 == 0) {
              if (param_4 == 2) {
                FUN_0027c7ef(param_1,*param_3,0,local_98,local_2c,2,param_6);
                FUN_0027c7ef(param_1,param_3[1],0,local_98,local_2c,2,param_6);
                return;
              }
              iVar1 = FUN_0024d64f();
              if (iVar1 < 2) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc/linux: Found %u NUMA nodes instead of 2 in mode %s-%s\n",
                        (ulong)param_4,local_78,local_98);
              }
            }
            else if (param_4 == 4) {
              iVar1 = FUN_0027b876(param_5,local_e8,&local_f0,&local_f8);
              if (-1 < iVar1) {
                iVar1 = strcmp(local_98,"Flat");
                if (iVar1 == 0) {
                  local_58 = 0;
                }
                FUN_0027c7ef(param_1,param_3[local_f0],param_3[local_f8],local_98,local_2c,2,param_6
                            );
                FUN_0027c7ef(param_1,param_3[local_ec],param_3[local_f4],local_98,local_2c,2,param_6
                            );
                return;
              }
              iVar1 = FUN_0024d64f();
              if (iVar1 < 2) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "Uhwloc/linux: nexpected distance layout for mode %s-%s\n",local_78,local_98
                       );
              }
            }
            else {
              iVar1 = FUN_0024d64f();
              if (iVar1 < 2) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc/linux: Found %u NUMA nodes instead of 2 in mode %s-%s\n",
                        (ulong)param_4,local_78,local_98);
              }
            }
          }
          else {
            iVar1 = strcmp(local_78,"SNC4");
            if (iVar1 != 0) {
              return;
            }
            iVar1 = strcmp(local_98,"Cache");
            if (iVar1 == 0) {
              if (param_4 == 4) {
                FUN_0027c7ef(param_1,*param_3,0,local_98,local_2c,4,param_6);
                FUN_0027c7ef(param_1,param_3[1],0,local_98,local_2c,4,param_6);
                FUN_0027c7ef(param_1,param_3[2],0,local_98,local_2c,4,param_6);
                FUN_0027c7ef(param_1,param_3[3],0,local_98,local_2c,4,param_6);
                return;
              }
              iVar1 = FUN_0024d64f();
              if (iVar1 < 2) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc/linux: Found %u NUMA nodes instead of 4 in mode %s-%s\n",
                        (ulong)param_4,local_78,local_98);
              }
            }
            else if (param_4 == 8) {
              iVar1 = FUN_0027ba75(param_5,local_e8,&local_108,&local_118);
              if (-1 < iVar1) {
                iVar1 = strcmp(local_98,"Flat");
                if (iVar1 == 0) {
                  local_58 = 0;
                }
                FUN_0027c7ef(param_1,param_3[local_108],param_3[local_118],local_98,local_2c,4,
                             param_6);
                FUN_0027c7ef(param_1,param_3[local_104],param_3[local_114],local_98,local_2c,4,
                             param_6);
                FUN_0027c7ef(param_1,param_3[local_100],param_3[local_110],local_98,local_2c,4,
                             param_6);
                FUN_0027c7ef(param_1,param_3[local_fc],param_3[local_10c],local_98,local_2c,4,
                             param_6);
                return;
              }
              iVar1 = FUN_0024d64f();
              if (iVar1 < 2) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc/linux: Unexpected distance layout for mode %s-%s\n",local_78,local_98
                       );
              }
            }
            else {
              iVar1 = FUN_0024d64f();
              if (iVar1 < 2) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc/linux: Found %u NUMA nodes instead of 2 in mode %s-%s\n",
                        (ulong)param_4,local_78,local_98);
              }
            }
          }
        }
      }
      else {
        iVar1 = FUN_0024d64f();
        if (iVar1 < 2) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc/linux: Failed to find a usable KNL memory mode (%s)\n",local_98);
        }
      }
    }
    else {
      iVar1 = FUN_0024d64f();
      if (iVar1 < 2) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "hwloc/linux: Failed to find a usable KNL cluster mode (%s)\n",local_78);
      }
    }
  }
  for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
    local_38 = param_3[local_c];
    if ((local_38 != 0) &&
       (local_40 = FUN_0024fb45(param_1,0,local_38,"linux:knl:basic:numa"), local_40 != local_38)) {
      *param_6 = *param_6 + 1;
    }
  }
  return;
}


// ===== 0027d976 FUN_0027d976 =====

undefined8 FUN_0027d976(uint param_1,uint param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  local_10 = 0;
  for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
    if ((local_14 != param_1) && (*(long *)(param_3 + (ulong)local_14 * 8) != 0)) {
      if (*(ulong *)(param_4 + (ulong)(local_14 + param_1 * param_2) * 8) < (ulong)local_c) {
        local_c = (uint)*(undefined8 *)(param_4 + (ulong)(local_14 + param_1 * param_2) * 8);
        local_10 = 1;
      }
      else if (*(ulong *)(param_4 + (ulong)(local_14 + param_1 * param_2) * 8) == (ulong)local_c) {
        local_10 = local_10 + 1;
      }
    }
  }
  if (((*(ulong *)(param_4 + (ulong)((param_2 + 1) * param_1) * 8) < (ulong)local_c) &&
      (local_c != 0xffffffff)) && (local_10 != param_2 - 1)) {
    for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
      if (((local_14 != param_1) && (*(long *)(param_3 + (ulong)local_14 * 8) != 0)) &&
         (*(ulong *)(param_4 + (ulong)(local_14 + param_1 * param_2) * 8) == (ulong)local_c)) {
        FUN_00262517(*(undefined8 *)(*(long *)(param_3 + (ulong)param_1 * 8) + 0xb8),
                     *(undefined8 *)(*(long *)(param_3 + (ulong)param_1 * 8) + 0xb8),
                     *(undefined8 *)(*(long *)(param_3 + (ulong)local_14 * 8) + 0xb8));
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== 0027db80 FUN_0027db80 =====

undefined8 FUN_0027db80(long param_1,long param_2,uint param_3,long param_4)

{
  int iVar1;
  int local_ac;
  char local_a8 [136];
  dirent *local_20;
  uint local_14;
  DIR *local_10;
  
  sprintf(local_a8,"/sys/devices/system/node/node%u/access1/initiators",
          (ulong)*(uint *)(param_2 + 0x10));
  local_10 = (DIR *)FUN_002771f1(local_a8,*(undefined4 *)(param_1 + 8));
  if (local_10 == (DIR *)0x0) {
    sprintf(local_a8,"/sys/devices/system/node/node%u/access0/initiators",
            (ulong)*(uint *)(param_2 + 0x10));
    local_10 = (DIR *)FUN_002771f1(local_a8,*(undefined4 *)(param_1 + 8));
    if (local_10 == (DIR *)0x0) {
      return 0xffffffff;
    }
  }
  do {
    do {
      local_20 = readdir(local_10);
      if (local_20 == (dirent *)0x0) {
        closedir(local_10);
        return 0;
      }
      iVar1 = sscanf(local_20->d_name,"node%u",&local_ac);
    } while ((iVar1 != 1) || (*(int *)(param_2 + 0x10) == local_ac));
    for (local_14 = 0; local_14 < param_3; local_14 = local_14 + 1) {
      if ((*(long *)(param_4 + (ulong)local_14 * 8) != 0) &&
         (*(int *)(*(long *)(param_4 + (ulong)local_14 * 8) + 0x10) == local_ac)) {
        FUN_00262517(*(undefined8 *)(param_2 + 0xb8),*(undefined8 *)(param_2 + 0xb8),
                     *(undefined8 *)(*(long *)(param_4 + (ulong)local_14 * 8) + 0xb8));
        break;
      }
    }
  } while( true );
}


// ===== 0027dd6c FUN_0027dd6c =====

undefined8 FUN_0027dd6c(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  undefined4 local_158 [2];
  undefined8 local_150;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  char local_128 [160];
  char local_88 [128];
  
  local_12c = 0;
  local_130 = 0;
  local_134 = 0;
  local_138 = 0;
  sprintf(local_88,"/sys/devices/system/node/node%u/access1/initiators",
          (ulong)*(uint *)(param_3 + 0x10));
  iVar1 = FUN_0027719a(local_88,1,*(undefined4 *)(param_2 + 8));
  if (iVar1 < 0) {
    sprintf(local_88,"/sys/devices/system/node/node%u/access0/initiators",
            (ulong)*(uint *)(param_3 + 0x10));
  }
  local_158[0] = 1;
  local_150 = *(undefined8 *)(param_3 + 0xb8);
  sprintf(local_128,"%s/read_bandwidth",local_88);
  iVar1 = FUN_0027731c(local_128,&local_12c,*(undefined4 *)(param_2 + 8));
  if ((iVar1 == 0) && (local_12c != 0)) {
    FUN_0025c155(param_1,4,0xd,0xffffffffffffffff,*(undefined4 *)(param_3 + 0x10),local_158,
                 local_12c);
  }
  sprintf(local_128,"%s/write_bandwidth",local_88);
  iVar1 = FUN_0027731c(local_128,&local_130,*(undefined4 *)(param_2 + 8));
  if ((iVar1 == 0) && (local_130 != 0)) {
    FUN_0025c155(param_1,5,0xd,0xffffffffffffffff,*(undefined4 *)(param_3 + 0x10),local_158,
                 local_130);
  }
  if ((local_12c != 0) && (local_130 != 0)) {
    FUN_0025c155(param_1,2,0xd,0xffffffffffffffff,*(undefined4 *)(param_3 + 0x10),local_158,
                 (uint)(local_130 + local_12c) >> 1);
  }
  sprintf(local_128,"%s/read_latency",local_88);
  iVar1 = FUN_0027731c(local_128,&local_134,*(undefined4 *)(param_2 + 8));
  if ((iVar1 == 0) && (local_134 != 0)) {
    FUN_0025c155(param_1,6,0xd,0xffffffffffffffff,*(undefined4 *)(param_3 + 0x10),local_158,
                 local_134);
  }
  sprintf(local_128,"%s/write_latency",local_88);
  iVar1 = FUN_0027731c(local_128,&local_138,*(undefined4 *)(param_2 + 8));
  if ((iVar1 == 0) && (local_138 != 0)) {
    FUN_0025c155(param_1,7,0xd,0xffffffffffffffff,*(undefined4 *)(param_3 + 0x10),local_158,
                 local_138);
  }
  if ((local_134 != 0) && (local_138 != 0)) {
    FUN_0025c155(param_1,3,0xd,0xffffffffffffffff,*(undefined4 *)(param_3 + 0x10),local_158,
                 (uint)(local_138 + local_134) >> 1);
  }
  return 0;
}


// ===== 0027e169 FUN_0027e169 =====

undefined8 FUN_0027e169(undefined8 param_1,long param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  int local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  char local_c8 [136];
  long local_40;
  uint local_34;
  dirent *local_30;
  DIR *local_28;
  uint local_1c;
  long local_18;
  long local_10;
  
  local_18 = *param_3;
  local_1c = *(uint *)(local_18 + 0x10);
  local_10 = local_18;
  sprintf(local_c8,"/sys/devices/system/node/node%u/memory_side_cache",(ulong)local_1c);
  local_28 = (DIR *)FUN_002771f1(local_c8,*(undefined4 *)(param_2 + 8));
  if (local_28 == (DIR *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    while (local_30 = readdir(local_28), local_30 != (dirent *)0x0) {
      iVar1 = strncmp(local_30->d_name,"index",5);
      if (iVar1 == 0) {
        local_34 = atoi(local_30->d_name + 5);
        sprintf(local_c8,"/sys/devices/system/node/node%u/memory_side_cache/index%u/size",
                (ulong)local_1c,(ulong)local_34);
        iVar1 = FUN_0027737a(local_c8,&local_d0,*(undefined4 *)(param_2 + 8));
        if (-1 < iVar1) {
          sprintf(local_c8,"/sys/devices/system/node/node%u/memory_side_cache/index%u/line_size",
                  (ulong)local_1c,(ulong)local_34);
          iVar1 = FUN_0027731c(local_c8,&local_d4,*(undefined4 *)(param_2 + 8));
          if (-1 < iVar1) {
            sprintf(local_c8,"/sys/devices/system/node/node%u/memory_side_cache/index%u/indexing",
                    (ulong)local_1c,(ulong)local_34);
            iVar1 = FUN_0027731c(local_c8,&local_d8,*(undefined4 *)(param_2 + 8));
            if ((-1 < iVar1) && (local_40 = FUN_0024febd(param_1,0x12,0xffffffff), local_40 != 0)) {
              uVar2 = FUN_002611e2(*(undefined8 *)(local_18 + 200));
              *(undefined8 *)(local_40 + 200) = uVar2;
              uVar2 = FUN_002611e2(*(undefined8 *)(local_18 + 0xb8));
              *(undefined8 *)(local_40 + 0xb8) = uVar2;
              **(undefined8 **)(local_40 + 0x28) = local_d0;
              *(uint *)(*(long *)(local_40 + 0x28) + 8) = local_34;
              *(undefined4 *)(*(long *)(local_40 + 0x28) + 0xc) = local_d4;
              *(undefined4 *)(*(long *)(local_40 + 0x28) + 0x14) = 0;
              *(uint *)(*(long *)(local_40 + 0x28) + 0x10) = (uint)(local_d8 == 0);
              *(long *)(local_40 + 0x90) = local_10;
              local_10 = local_40;
            }
          }
        }
      }
    }
    closedir(local_28);
    *param_3 = local_10;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0027e43c FUN_0027e43c =====

bool FUN_0027e43c(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_1c8 [144];
  char local_138 [304];
  
  snprintf(local_138,300,"/sys/bus/dax/drivers/kmem/%s",param_1);
  iVar1 = FUN_002771c2(local_138,local_1c8,param_2);
  return iVar1 == 0;
}


// ===== 0027e4a7 FUN_0027e4a7 =====

void FUN_0027e4a7(undefined8 param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  char local_1158 [4096];
  char local_158 [304];
  undefined *local_28;
  char *local_20;
  int local_14;
  char *local_10;
  
  snprintf(local_158,300,"/sys/bus/dax/devices/%s",param_2);
  local_14 = FUN_00277213(local_158,local_1158,0x1000,param_3);
  if (-1 < local_14) {
    local_10 = local_1158;
    while( true ) {
      iVar1 = strncmp(local_10,"../",3);
      if (iVar1 != 0) break;
      local_10 = local_10 + 3;
    }
    iVar1 = strncmp(local_10,"devices/",8);
    if (iVar1 == 0) {
      local_10 = local_10 + 8;
    }
    iVar1 = strncmp(local_10,"platform/",9);
    if (iVar1 == 0) {
      local_10 = local_10 + 9;
    }
    local_20 = strstr(local_10,param_2);
    if (((local_20 != (char *)0x0) && (*local_20 = '\0', local_20 != local_10)) &&
       (local_20[-1] == '/')) {
      local_20[-1] = '\0';
    }
    pcVar2 = strstr(local_10,"ndbus");
    if (pcVar2 == (char *)0x0) {
      local_28 = &DAT_002f2e49;
    }
    else {
      local_28 = &DAT_002f2e45;
    }
    FUN_0024dfb5(param_1,"DAXType",local_28);
    FUN_0024dfb5(param_1,"DAXParent",local_10);
  }
  return;
}


// ===== 0027e641 FUN_0027e641 =====

void FUN_0027e641(undefined8 param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  char local_168 [308];
  int local_34;
  long local_30;
  int local_24;
  dirent *local_20;
  DIR *local_18;
  uint local_c;
  
  local_18 = (DIR *)FUN_002771f1("/sys/bus/dax/devices/",param_4);
  if (local_18 != (DIR *)0x0) {
LAB_0027e798:
    local_20 = readdir(local_18);
    if (local_20 != (dirent *)0x0) {
      iVar1 = FUN_0027e43c(local_20->d_name,param_4);
      if (iVar1 != 0) {
        snprintf(local_168,300,"/sys/bus/dax/devices/%s/target_node",local_20->d_name);
        iVar1 = FUN_002772c8(local_168,&local_34,param_4);
        if ((-1 < iVar1) && (-1 < local_34)) {
          local_24 = local_34;
          for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
            local_30 = *(long *)(param_3 + (ulong)local_c * 8);
            if ((local_30 != 0) && (local_34 == *(int *)(local_30 + 0x10))) {
              FUN_0024dfb5(local_30,"DAXDevice",local_20->d_name);
              FUN_0027e4a7(local_30,local_20->d_name,param_4);
              break;
            }
          }
        }
      }
      goto LAB_0027e798;
    }
    closedir(local_18);
  }
  return;
}


// ===== 0027e7c4 FUN_0027e7c4 =====

void * FUN_0027e7c4(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  void *local_58;
  void *local_50;
  char *local_48;
  void *local_40;
  uint local_34;
  dirent *local_30;
  DIR *local_28;
  long local_20;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_10 = 0;
  local_20 = FUN_002779b7("/sys/devices/system/node/online",*(undefined4 *)(param_2 + 8));
  if (local_20 == 0) {
    local_28 = (DIR *)FUN_002771f1("/sys/devices/system/node",*(undefined4 *)(param_2 + 8));
    if (local_28 == (DIR *)0x0) {
      return (void *)0x0;
    }
    local_20 = FUN_00260eab();
    if (local_20 == 0) {
      closedir(local_28);
      return (void *)0x0;
    }
    while (local_30 = readdir(local_28), local_30 != (dirent *)0x0) {
      iVar2 = strncmp(local_30->d_name,"node",4);
      if (iVar2 == 0) {
        uVar3 = strtoul(local_30->d_name + 4,&local_48,0);
        local_c = (int)uVar3;
        if (local_30->d_name + 4 != local_48) {
          FUN_0026197d(local_20,uVar3 & 0xffffffff);
          local_10 = local_10 + 1;
        }
      }
    }
    closedir(local_28);
    uVar1 = local_10;
    if (local_10 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("nbnodes >= 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                    ,0xf0e,"list_sysfsnode");
    }
  }
  else {
    local_34 = FUN_00262e86(local_20);
    uVar1 = local_34;
    if ((int)local_34 < 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("_nbnodes >= 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                    ,0xef1,"list_sysfsnode");
    }
  }
  local_10 = uVar1;
  iVar2 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200));
  if ((iVar2 == 0) &&
     (iVar2 = FUN_00262158(local_20,*(undefined8 *)
                                     (*(long *)**(undefined8 **)(param_1 + 0x18) + 200)), iVar2 == 0
     )) {
    FUN_00261562(&local_50,local_20);
    FUN_00261562(&local_58,*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200));
    iVar2 = FUN_0024d64f();
    if (iVar2 < 2) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc/linux: ignoring nodes because nodeset %s doesn\'t match existing nodeset %s.\n"
              ,local_58,local_50);
    }
    free(local_50);
    free(local_58);
    FUN_00260f71(local_20);
    local_40 = (void *)0x0;
  }
  else {
    local_40 = calloc((ulong)local_10,4);
    if (local_40 == (void *)0x0) {
      FUN_00260f71(local_20);
      local_40 = (void *)0x0;
    }
    else {
      local_14 = 0;
      iVar2 = FUN_00262e86(local_20);
      if (iVar2 == -1) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_bitmap_weight(nodeset) != -1",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                      ,0xf2d,"list_sysfsnode");
      }
      for (local_c = FUN_00262aab(local_20); local_c != -1; local_c = FUN_00262ba7(local_20,local_c)
          ) {
        *(int *)((ulong)local_14 * 4 + (long)local_40) = local_c;
        local_14 = local_14 + 1;
      }
      FUN_00260f71(local_20);
      *param_3 = local_10;
    }
  }
  return local_40;
}


// ===== 0027eb01 FUN_0027eb01 =====

undefined8 FUN_0027eb01(long param_1,long param_2,uint *param_3)

{
  int iVar1;
  uint local_34;
  void *local_30;
  void *local_28;
  void *local_20;
  uint local_14;
  long local_10;
  
  local_20 = (void *)FUN_0027e7c4(param_1,param_2,&local_34);
  if (local_20 != (void *)0x0) {
    local_28 = calloc((ulong)local_34,8);
    local_30 = malloc((ulong)(local_34 * local_34) << 3);
    if ((local_28 == (void *)0x0) || (local_30 == (void *)0x0)) {
      free(local_28);
      free(local_20);
      free(local_30);
    }
    else {
      for (local_10 = FUN_00276ab2(param_1,0xd,0); local_10 != 0;
          local_10 = FUN_00276ab2(param_1,0xd,local_10)) {
        if (local_10 == 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("node",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                        ,0xf5c,"annotate_sysfsnode");
        }
        for (local_14 = 0; local_14 < local_34; local_14 = local_14 + 1) {
          if (*(int *)((long)local_20 + (ulong)local_14 * 4) == *(int *)(local_10 + 0x10)) {
            *(long *)((ulong)local_14 * 8 + (long)local_28) = local_10;
            break;
          }
        }
        FUN_0027ab89(param_2,*(undefined4 *)(local_10 + 0x10),*(undefined8 *)(local_10 + 0x28));
      }
      *(undefined1 *)(*(long *)(param_1 + 0x288) + 1) = 1;
      *(undefined1 *)(*(long *)(param_1 + 0x288) + 2) = 1;
      *(undefined1 *)(*(long *)(param_1 + 0x288) + 4) = 1;
      if ((((local_34 < 2) || (*(int *)(param_2 + 0x24) == 0)) ||
          (iVar1 = FUN_0027ad42(local_34,local_20,local_30,*(undefined4 *)(param_2 + 8)), iVar1 != 0
          )) || ((*(ulong *)(param_1 + 0x20) & 0x80) != 0)) {
        free(local_28);
        free(local_30);
      }
      else {
        FUN_00259d57(param_1,"NUMALatency",local_34,local_28,local_30,5,1);
      }
      free(local_20);
      *param_3 = local_34;
    }
  }
  return 0;
}


// ===== 0027ed5e FUN_0027ed5e =====

undefined8 FUN_0027ed5e(long param_1,long param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  char local_468 [256];
  char local_368 [304];
  char local_238 [304];
  long local_108;
  long local_100;
  int local_f8;
  uint local_f4;
  long local_f0;
  long local_e8;
  uint local_dc;
  long local_d8;
  long local_d0;
  int *local_c8;
  int local_bc;
  int *local_b8;
  int local_ac;
  char *local_a8;
  long local_a0;
  int local_94;
  char *local_90;
  int local_84;
  dirent *local_80;
  int local_74;
  char *local_70;
  DIR *local_68;
  long local_60;
  void *local_58;
  void *local_50;
  void *local_48;
  int local_3c;
  uint local_38;
  uint local_34;
  int *local_30;
  char *local_28;
  uint local_1c;
  void *local_18;
  uint local_c;
  
  local_f8 = 0;
  pcVar3 = getenv("HWLOC_DEBUG_ALLOW_OVERLAPPING_NODE_CPUSETS");
  local_38 = (uint)(pcVar3 != (char *)0x0);
  local_3c = FUN_00276ce7(param_1,0x12);
  FUN_00276d47("\n\n * Topology extraction from /sys/devices/system/node *\n\n");
  local_48 = (void *)FUN_0027e7c4(param_1,param_2,&local_f4);
  if (local_48 == (void *)0x0) {
    return 0;
  }
  local_50 = calloc((ulong)local_f4,8);
  local_58 = calloc((ulong)local_f4,8);
  local_18 = malloc((ulong)(local_f4 * local_f4) << 3);
  local_60 = FUN_00260eab();
  if ((((local_50 == (void *)0x0) || (local_58 == (void *)0x0)) || (local_18 == (void *)0x0)) ||
     (local_60 == 0)) {
    free(local_50);
    free(local_58);
    free(local_48);
    free(local_18);
    FUN_00260f71(local_60);
    local_f4 = 0;
  }
  else {
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 1) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 2) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 4) = 1;
    for (local_1c = 0; local_1c < local_f4; local_1c = local_1c + 1) {
      local_dc = *(uint *)((long)local_48 + (ulong)local_1c * 4);
      sprintf(local_238,"/sys/devices/system/node/node%u/cpumap",(ulong)local_dc);
      local_e8 = FUN_002777e0(local_238,*(undefined4 *)(param_2 + 8));
      if (local_e8 == 0) {
        local_f8 = local_f8 + 1;
      }
      else {
        iVar2 = FUN_002622a3(local_60,local_e8);
        if (iVar2 != 0) {
          if (local_38 == 0) {
            FUN_00260f71(local_e8);
            local_f8 = local_f8 + 1;
            goto LAB_0027f0b3;
          }
          iVar2 = FUN_0024d64f();
          if (iVar2 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc/linux: node P#%u cpuset intersects with previous nodes, forcing its acceptance\n"
                    ,(ulong)local_dc);
          }
        }
        FUN_00262517(local_60,local_60,local_e8);
        local_f0 = FUN_0024febd(param_1,0xd,local_dc);
        *(long *)(local_f0 + 0xb8) = local_e8;
        uVar4 = FUN_00260eab();
        *(undefined8 *)(local_f0 + 200) = uVar4;
        FUN_0026197d(*(undefined8 *)(local_f0 + 200),local_dc);
        FUN_0027ab89(param_2,local_dc,*(undefined8 *)(local_f0 + 0x28));
        *(long *)((ulong)local_1c * 8 + (long)local_50) = local_f0;
      }
LAB_0027f0b3:
    }
    local_68 = (DIR *)FUN_002771f1("/proc/driver/nvidia/gpus",*(undefined4 *)(param_2 + 8));
    if (local_68 != (DIR *)0x0) {
      local_70 = getenv("HWLOC_KEEP_NVIDIA_GPU_NUMA_NODES");
      if ((local_70 == (char *)0x0) || (iVar2 = atoi(local_70), iVar2 == 0)) {
        local_74 = 0;
      }
      else {
        local_74 = 1;
      }
LAB_0027f355:
      local_80 = readdir(local_68);
      if (local_80 != (dirent *)0x0) {
        snprintf(local_368,300,"/proc/driver/nvidia/gpus/%s/numa_status",local_80->d_name);
        local_84 = FUN_00277243(local_368,local_468,0x100,*(undefined4 *)(param_2 + 8));
        if ((0 < local_84) && (local_90 = strstr(local_468,"Node:"), local_90 != (char *)0x0)) {
          for (local_28 = local_90 + 5; (*local_28 == ' ' || (*local_28 == '\t'));
              local_28 = local_28 + 1) {
          }
          local_94 = atoi(local_28);
          FUN_00276d47("os node %u is NVIDIA GPU %s integrated memory\n",local_94,local_80->d_name);
          for (local_1c = 0; local_1c < local_f4; local_1c = local_1c + 1) {
            local_a0 = *(long *)((long)local_50 + (ulong)local_1c * 8);
            if ((local_a0 != 0) && (local_94 == *(int *)(local_a0 + 0x10))) {
              if (local_74 == 0) {
                FUN_0024e0d0(local_a0);
                *(undefined8 *)((long)local_50 + (ulong)local_1c * 8) = 0;
              }
              else {
                pcVar3 = strdup("GPUMemory");
                *(char **)(local_a0 + 8) = pcVar3;
                FUN_0024dfb5(local_a0,"PCIBusID",local_80->d_name);
                snprintf(local_238,300,"/sys/bus/pci/devices/%s/local_cpus",local_80->d_name);
                local_84 = FUN_00277548(local_238,*(undefined8 *)(local_a0 + 0xb8),
                                        *(undefined4 *)(param_2 + 8));
                if (local_84 != 0) {
                  FUN_0026180c(*(undefined8 *)(local_a0 + 0xb8));
                }
              }
              break;
            }
          }
        }
        goto LAB_0027f355;
      }
      closedir(local_68);
    }
    FUN_0027e641(param_1,local_f4,local_50,*(undefined4 *)(param_2 + 8));
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 1) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 2) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 4) = 1;
    FUN_00260f71(local_60);
    if (local_f4 < 2) {
      *(undefined4 *)(param_2 + 0x24) = 0;
    }
    if (*(int *)(param_2 + 0x24) == 0) {
      free(local_18);
      local_18 = (void *)0x0;
    }
    if ((local_18 != (void *)0x0) &&
       (iVar2 = FUN_0027ad42(local_f4,local_48,local_18,*(undefined4 *)(param_2 + 8)), iVar2 < 0)) {
      free(local_18);
      local_18 = (void *)0x0;
    }
    free(local_48);
    if (*(int *)(param_2 + 0x1c) != 0) {
      local_a8 = getenv("HWLOC_KNL_NUMA_QUIRK");
      if ((local_a8 == (char *)0x0) || (iVar2 = atoi(local_a8), iVar2 != 0)) {
        local_ac = 0;
      }
      else {
        local_ac = 1;
      }
      if (local_ac == 0) {
        FUN_0027cc6d(param_1,param_2,local_50,local_f4,local_18,&local_f8);
        free(local_18);
        free(local_50);
        free(local_58);
        goto LAB_0027f94b;
      }
    }
    local_c = 0;
    for (local_1c = 0; local_1c < local_f4; local_1c = local_1c + 1) {
      local_d8 = *(long *)((long)local_50 + (ulong)local_1c * 8);
      if ((local_d8 != 0) && (iVar2 = FUN_002620a3(*(undefined8 *)(local_d8 + 0xb8)), iVar2 == 0)) {
        if (*(int *)(param_2 + 0x2c) != 0) {
          FUN_0027db80(param_2,local_d8,local_f4,local_50);
        }
        local_100 = local_d8;
        if (local_3c != 0) {
          FUN_0027e169(param_1,param_2,&local_100);
        }
        *(long *)((ulong)local_c * 8 + (long)local_58) = local_100;
        local_c = local_c + 1;
      }
    }
    for (local_1c = 0; local_1c < local_f4; local_1c = local_1c + 1) {
      local_d0 = *(long *)((long)local_50 + (ulong)local_1c * 8);
      if (local_d0 != 0) {
        iVar2 = FUN_002620a3(*(undefined8 *)(local_d0 + 0xb8));
        if (iVar2 != 0) {
          if ((((*(int *)(param_2 + 0x2c) == 0) ||
               (iVar2 = FUN_0027db80(param_2,local_d0,local_f4,local_50), iVar2 != 0)) ||
              (iVar2 = FUN_002620a3(*(undefined8 *)(local_d0 + 0xb8)), iVar2 != 0)) &&
             ((local_18 != (void *)0x0 && (*(int *)(param_2 + 0x28) != 0)))) {
            FUN_0027d976(local_1c,local_f4,local_50,local_18);
          }
          local_108 = local_d0;
          if (local_3c != 0) {
            FUN_0027e169(param_1,param_2,&local_108);
          }
          *(long *)((ulong)local_c * 8 + (long)local_58) = local_108;
          local_c = local_c + 1;
        }
        if ((*(ulong *)(param_1 + 0x20) & 0x100) == 0) {
          FUN_0027dd6c(param_1,param_2,local_d0);
        }
      }
    }
    for (local_1c = 0; local_1c < local_c; local_1c = local_1c + 1) {
      local_30 = *(int **)((long)local_58 + (ulong)local_1c * 8);
      while (piVar1 = local_30, local_30 != (int *)0x0) {
        local_b8 = local_30;
        local_bc = *local_30;
        if (*(long *)(local_30 + 0x16) != 0) {
          local_30 = *(int **)(local_30 + 0x24);
                    /* WARNING: Subroutine does not return */
          __assert_fail("!cur_obj->next_sibling",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                        ,0x1068,"look_sysfsnode");
        }
        local_30 = *(int **)(local_30 + 0x24);
        local_c8 = (int *)FUN_0024fb45(param_1,0,piVar1,"linux:sysfs:numa");
        if ((local_c8 != local_b8) && (local_bc == 0xd)) {
          for (local_34 = 0; local_34 < local_f4; local_34 = local_34 + 1) {
            if (local_b8 == *(int **)((long)local_50 + (ulong)local_34 * 8)) {
              *(int **)((ulong)local_34 * 8 + (long)local_50) = local_c8;
            }
          }
          local_f8 = local_f8 + 1;
        }
      }
    }
    free(local_58);
    if ((*(ulong *)(param_1 + 0x20) & 0x80) != 0) {
      free(local_18);
      local_18 = (void *)0x0;
    }
    if (local_18 == (void *)0x0) {
      free(local_50);
    }
    else {
      FUN_00259d57(param_1,"NUMALatency",local_f4,local_50,local_18,5,1);
    }
  }
LAB_0027f94b:
  *param_3 = local_f4 - local_f8;
  return 0;
}


// ===== 0027f969 FUN_0027f969 =====

void FUN_0027f969(undefined8 *param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 4;
  pvVar1 = malloc((ulong)*(uint *)((long)param_1 + 0xc) << 4);
  *param_1 = pvVar1;
  return;
}


// ===== 0027f9ad FUN_0027f9ad =====

void FUN_0027f9ad(long *param_1,undefined4 param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  void *pvVar3;
  undefined8 uVar4;
  uint local_1c;
  
  for (local_1c = 0; local_1c < *(uint *)(param_1 + 1); local_1c = local_1c + 1) {
    if (param_3 == *(long *)(*param_1 + (ulong)local_1c * 0x10)) {
      FUN_0026197d(*(undefined8 *)(*param_1 + (ulong)local_1c * 0x10 + 8),param_2);
      return;
    }
  }
  if ((int)param_1[1] == *(int *)((long)param_1 + 0xc)) {
    pvVar3 = realloc((void *)*param_1,(ulong)(uint)(*(int *)((long)param_1 + 0xc) * 2) << 4);
    if (pvVar3 == (void *)0x0) {
      return;
    }
    *param_1 = (long)pvVar3;
    *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) * 2;
  }
  lVar2 = *param_1;
  uVar1 = *(uint *)(param_1 + 1);
  uVar4 = FUN_00260eab();
  *(undefined8 *)(lVar2 + (ulong)uVar1 * 0x10 + 8) = uVar4;
  if (*(long *)((ulong)*(uint *)(param_1 + 1) * 0x10 + *param_1 + 8) != 0) {
    *(long *)(*param_1 + (ulong)*(uint *)(param_1 + 1) * 0x10) = param_3;
    FUN_0026197d(*(undefined8 *)((ulong)*(uint *)(param_1 + 1) * 0x10 + *param_1 + 8),param_2);
    *(int *)(param_1 + 1) = (int)param_1[1] + 1;
  }
  return;
}


// ===== 0027fb21 FUN_0027fb21 =====

int FUN_0027fb21(undefined8 *param_1,undefined8 *param_2)

{
  return (int)*param_1 - (int)*param_2;
}


// ===== 0027fb53 FUN_0027fb53 =====

void FUN_0027fb53(long *param_1,long param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  char local_48 [32];
  undefined8 local_28;
  char *local_20;
  uint local_c;
  
  qsort((void *)*param_1,(ulong)*(uint *)(param_1 + 1),0x10,FUN_0027fb21);
  for (local_c = 0; local_c < *(uint *)(param_1 + 1); local_c = local_c + 1) {
    local_20 = local_48;
    local_28 = param_3;
    snprintf(local_48,0x20,"%lu",*(undefined8 *)(*param_1 + (ulong)local_c * 0x10));
    uVar1 = local_c;
    if (param_4 == 0) {
      uVar1 = 0xffffffff;
    }
    FUN_0025d167(param_2,*(undefined8 *)(*param_1 + (ulong)local_c * 0x10 + 8),uVar1,&local_28,1,0);
    *(undefined8 *)(*param_1 + (ulong)local_c * 0x10 + 8) = 0;
  }
  if ((int)param_1[1] != 0) {
    *(undefined1 *)(*(long *)(param_2 + 0x288) + 5) = 1;
  }
  return;
}


// ===== 0027fc6b FUN_0027fc6b =====

void FUN_0027fc6b(long *param_1)

{
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 1); local_c = local_c + 1) {
    FUN_00260f71(*(undefined8 *)(*param_1 + (ulong)local_c * 0x10 + 8));
  }
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  free((void *)*param_1);
  return;
}


// ===== 0027fcd5 FUN_0027fcd5 =====

void FUN_0027fcd5(long *param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  uint local_10;
  uint local_c;
  
  lVar2 = FUN_00260eab();
  if (lVar2 != 0) {
    local_c = 0;
    while ((local_c < *(uint *)(param_1 + 1) &&
           (param_3 != *(long *)(*param_1 + (ulong)local_c * 0x10)))) {
      local_c = local_c + 1;
    }
    if (*(uint *)(param_1 + 1) <= local_c) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("first < cpukinds->nr_sets",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                    ,0x1100,"hwloc_linux_cpukinds_merge_values");
    }
    for (local_10 = 0; local_10 < *(uint *)(param_1 + 1); local_10 = local_10 + 1) {
      if (local_10 != local_c) {
        FUN_002626c1(lVar2,*(undefined8 *)(*param_1 + (ulong)local_10 * 0x10 + 8),param_2);
        iVar1 = FUN_002620a3(lVar2);
        if (iVar1 == 0) {
          FUN_00262517(*(undefined8 *)(*param_1 + (ulong)local_c * 0x10 + 8),
                       *(undefined8 *)(*param_1 + (ulong)local_c * 0x10 + 8),lVar2);
          FUN_00262868(*(undefined8 *)(*param_1 + (ulong)local_10 * 0x10 + 8),
                       *(undefined8 *)(*param_1 + (ulong)local_10 * 0x10 + 8),lVar2);
          iVar1 = FUN_002620a3(*(undefined8 *)(*param_1 + (ulong)local_10 * 0x10 + 8));
          if (iVar1 != 0) {
            FUN_00260f71(*(undefined8 *)(*param_1 + (ulong)local_10 * 0x10 + 8));
            memmove((void *)(*param_1 + (ulong)local_10 * 0x10),
                    (void *)((ulong)(local_10 + 1) * 0x10 + *param_1),
                    (ulong)(((int)param_1[1] - local_10) - 1) << 4);
            *(int *)(param_1 + 1) = (int)param_1[1] + -1;
            if (local_10 < local_c) {
              local_c = local_c - 1;
            }
            local_10 = local_10 - 1;
          }
        }
      }
    }
    FUN_00260f71(lVar2);
  }
  return;
}


// ===== 0027fefa FUN_0027fefa =====

/* WARNING: Removing unreachable block (ram,0x002800db) */

void FUN_0027fefa(long *param_1,long *param_2,uint param_3)

{
  int iVar1;
  float fVar2;
  ulong local_20;
  ulong local_18;
  uint local_10;
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_2 + 1); local_c = local_c + 1) {
    local_18 = 0xffffffff;
    local_20 = 0;
    for (local_10 = 0; local_10 < *(uint *)(param_1 + 1); local_10 = local_10 + 1) {
      iVar1 = FUN_002622a3(*(undefined8 *)(*param_2 + (ulong)local_c * 0x10 + 8),
                           *(undefined8 *)(*param_1 + (ulong)local_10 * 0x10 + 8));
      if (iVar1 != 0) {
        if (*(ulong *)(*param_1 + (ulong)local_10 * 0x10) < local_18) {
          local_18 = *(ulong *)(*param_1 + (ulong)local_10 * 0x10);
        }
        if (local_20 < *(ulong *)(*param_1 + (ulong)local_10 * 0x10)) {
          local_20 = *(ulong *)(*param_1 + (ulong)local_10 * 0x10);
        }
      }
    }
    if (local_18 != 0xffffffff) {
      if (local_18 == local_20) {
        FUN_00276d47("linux/cpufreq: max frequencies always %lu when base=%lu\n",local_18,
                     *(undefined8 *)(*param_2 + (ulong)local_c * 0x10));
      }
      else {
        fVar2 = (float)(local_20 - local_18) / (float)local_18;
        FUN_00276d47("linux/cpufreq: max frequencies in [%lu-%lu] when base=%lu\n",local_18,local_20
                     ,*(undefined8 *)(*param_2 + (ulong)local_c * 0x10));
        if (fVar2 * DAT_002f4db8 < (float)param_3) {
          FUN_00276d47("linux/cpufreq: max frequencies overrated up to %u%% < %u%%, adjust all to %lu\n"
                       ,(long)(DAT_002f4db8 * fVar2) & 0xffffffff,param_3,local_18);
          FUN_0027fcd5(param_1,*(undefined8 *)(*param_2 + (ulong)local_c * 0x10 + 8),local_18);
        }
      }
    }
  }
  return;
}


// ===== 0028016c FUN_0028016c =====

undefined8 FUN_0028016c(long param_1,long param_2)

{
  int iVar1;
  undefined4 local_194;
  uint local_190;
  uint local_18c;
  char local_188 [304];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [8];
  int local_30;
  char *local_20;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = -1;
  local_14 = 10;
  local_20 = getenv("HWLOC_CPUKINDS_MAXFREQ");
  if (local_20 != (char *)0x0) {
    iVar1 = strcmp(local_20,"0");
    if (iVar1 == 0) {
      local_10 = 0;
    }
    else {
      iVar1 = strcmp(local_20,"1");
      if (iVar1 == 0) {
        local_10 = 1;
      }
      else {
        iVar1 = strncmp(local_20,"adjust=",7);
        if (iVar1 == 0) {
          local_14 = atoi(local_20 + 7);
        }
      }
    }
  }
  if (local_10 == 1) {
    FUN_00276d47(
                "linux/cpufreq: max frequency values are enforced even if it makes CPUs unexpectedly hybrid\n"
                );
  }
  else if (local_10 == 0) {
    FUN_00276d47("linux/cpufreq: max frequency values are ignored\n");
  }
  else {
    FUN_00276d47("linux/cpufreq: max frequency values will be adjusted by up to %u%%\n",local_14);
  }
  FUN_0027f969(local_38);
  FUN_0027f969(local_48);
  iVar1 = FUN_00262e86(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
  if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_bitmap_weight(topology->levels[0][0]->cpuset) != -1",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                  ,0x1165,"look_sysfscpukinds");
  }
  for (local_18 = FUN_00262aab(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
      local_18 != 0xffffffff;
      local_18 = FUN_00262ba7(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8),
                              local_18)) {
    local_18c = 0;
    local_190 = 0;
    sprintf(local_188,"/sys/devices/system/cpu/cpu%d/cpufreq/cpuinfo_max_freq",(ulong)local_18);
    iVar1 = FUN_0027731c(local_188,&local_18c,*(undefined4 *)(param_2 + 8));
    if ((-1 < iVar1) && (local_18c != 0)) {
      FUN_0027f9ad(local_38,local_18,(ulong)local_18c / 1000);
    }
    sprintf(local_188,"/sys/devices/system/cpu/cpu%d/cpufreq/base_frequency",(ulong)local_18);
    iVar1 = FUN_0027731c(local_188,&local_190,*(undefined4 *)(param_2 + 8));
    if ((-1 < iVar1) && (local_190 != 0)) {
      FUN_0027f9ad(local_48,local_18,(ulong)local_190 / 1000);
    }
    if ((local_18c != 0) && (local_190 == 0)) {
      local_c = 1;
    }
  }
  if (((local_10 == -1) && (local_30 != 0)) && (local_c == 0)) {
    FUN_0027fefa(local_38,local_48,local_14);
  }
  if (local_10 != 0) {
    FUN_0027fb53(local_38,param_1,"FrequencyMaxMHz",0);
  }
  FUN_0027fb53(local_48,param_1,"FrequencyBaseMHz",0);
  FUN_0027fc6b(local_38);
  FUN_0027fc6b(local_48);
  FUN_0027f969(local_58);
  iVar1 = FUN_00262e86(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
  if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_bitmap_weight(topology->levels[0][0]->cpuset) != -1",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                  ,0x1182,"look_sysfscpukinds");
  }
  for (local_18 = FUN_00262aab(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
      local_18 != 0xffffffff;
      local_18 = FUN_00262ba7(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8),
                              local_18)) {
    sprintf(local_188,"/sys/devices/system/cpu/cpu%d/cpu_capacity",(ulong)local_18);
    iVar1 = FUN_0027731c(local_188,&local_194,*(undefined4 *)(param_2 + 8));
    if (-1 < iVar1) {
      FUN_0027f9ad(local_58,local_18,local_194);
    }
  }
  FUN_0027fb53(local_58,param_1,"LinuxCapacity",1);
  FUN_0027fc6b(local_58);
  return 0;
}


// ===== 002805f4 FUN_002805f4 =====

undefined8 FUN_002805f4(long param_1,long param_2,int param_3,long param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  undefined4 local_370;
  undefined4 local_36c;
  uint local_368;
  uint local_364;
  uint local_360;
  uint local_35c;
  char local_358 [28];
  int local_33c;
  char *local_338;
  char local_32a [2];
  char local_328 [520];
  ulong local_120;
  long local_118;
  int local_10c;
  long local_108;
  undefined8 local_100;
  long local_f8;
  long local_f0;
  int local_e4;
  long local_e0;
  int local_d4;
  long local_d0;
  long local_c8;
  long local_c0;
  long local_b8;
  long local_b0;
  undefined4 local_a4;
  char *local_a0;
  dirent *local_98;
  undefined8 local_90;
  DIR *local_88;
  long local_80;
  undefined4 local_74;
  long local_70;
  long local_68;
  long local_60;
  int local_54;
  int local_50;
  int local_4c;
  long local_48;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  long local_30;
  long local_28;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  if (*(int *)(param_2 + 0x20) == 0) {
    local_14 = 0;
  }
  else {
    local_14 = 0xffffffff;
  }
  FUN_00276d47("\n\n * Topology extraction from /sys/devices/system/cpu/ *\n\n");
  local_80 = FUN_002779b7("/sys/devices/system/cpu/online",*(undefined4 *)(param_2 + 8));
  local_88 = (DIR *)FUN_002771f1("/sys/devices/system/cpu",*(undefined4 *)(param_2 + 8));
  if (local_88 == (DIR *)0x0) {
    piVar3 = __errno_location();
    FUN_00276d47("failed to open sysfscpu path /sys/devices/system/cpu (%d)\n",*piVar3);
    FUN_00260f71(local_80);
    uVar4 = 0xffffffff;
  }
  else {
    local_90 = FUN_00260eab();
LAB_002808c8:
    local_98 = readdir(local_88);
    if (local_98 != (dirent *)0x0) {
      iVar1 = strncmp(local_98->d_name,"cpu",3);
      if ((iVar1 == 0) &&
         (local_120 = strtoul(local_98->d_name + 3,&local_338,0), local_98->d_name + 3 != local_338)
         ) {
        FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0),
                     local_120 & 0xffffffff);
        if (local_80 == 0) {
          sprintf(local_328,"/sys/devices/system/cpu/cpu%lu/online",local_120);
          lVar6 = FUN_00277243(local_328,local_32a,2,*(undefined4 *)(param_2 + 8));
          if ((0 < lVar6) && (iVar1 = atoi(local_32a), iVar1 == 0)) {
            FUN_00276d47("os proc %lu is offline\n",local_120);
            goto LAB_002808c8;
          }
        }
        else {
          iVar1 = FUN_0026203b(local_80,local_120 & 0xffffffff);
          if (iVar1 == 0) {
            FUN_00276d47("os proc %lu is offline\n",local_120);
            goto LAB_002808c8;
          }
        }
        sprintf(local_328,"/sys/devices/system/cpu/cpu%lu/topology",local_120);
        iVar1 = FUN_0027719a(local_328,1,*(undefined4 *)(param_2 + 8));
        if ((iVar1 < 0) && (piVar3 = __errno_location(), *piVar3 == 2)) {
          FUN_00276d47("os proc %lu has no accessible /sys/devices/system/cpu/cpu%lu/topology\n",
                       local_120,local_120);
        }
        else {
          FUN_0026197d(local_90,local_120 & 0xffffffff);
        }
      }
      goto LAB_002808c8;
    }
    closedir(local_88);
    **(undefined1 **)(param_1 + 0x288) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0x288) + 3) = 1;
    local_a0 = getenv("HWLOC_DONT_MERGE_CLUSTER_GROUPS");
    if ((local_a0 == (char *)0x0) || (iVar1 = atoi(local_a0), iVar1 == 0)) {
      local_a4 = 0;
    }
    else {
      local_a4 = 1;
    }
    iVar1 = FUN_00262e86(local_90);
    if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(cpuset) != -1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-linux.c"
                    ,0x11ea,"look_sysfscpu");
    }
    for (local_c = FUN_00262aab(local_90); local_c != 0xffffffff;
        local_c = FUN_00262ba7(local_90,local_c)) {
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      iVar1 = FUN_00276ce7(param_1,2);
      if (iVar1 != 0) {
        if (param_3 == 0) {
          sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/core_cpus",(ulong)local_c);
        }
        else {
          sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/thread_siblings",(ulong)local_c)
          ;
        }
        local_b0 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
        if (local_b0 != 0) {
          local_34 = -1;
          local_38 = 0;
          FUN_002626c1(local_b0,local_b0,local_90);
          iVar1 = FUN_00262e86(local_b0);
          if ((1 < iVar1) && (local_14 == 0xffffffff)) {
            local_34 = -1;
            sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/core_id",(ulong)local_c);
            iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
            if (iVar1 == 0) {
              local_34 = local_33c;
            }
            local_38 = 1;
            local_3c = FUN_00262aab(local_b0);
            if (local_3c == local_c) {
              local_3c = FUN_00262ba7(local_b0,local_c);
            }
            local_40 = -1;
            sprintf(local_328,"/sys/devices/system/cpu/cpu%u/topology/core_id",(ulong)local_3c);
            iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
            if (iVar1 == 0) {
              local_40 = local_33c;
            }
            local_14 = (uint)(local_40 != local_34);
          }
          uVar2 = FUN_00262aab(local_b0);
          if (local_c != uVar2) {
            local_20 = 1;
            local_1c = 1;
            local_18 = 1;
          }
          if ((local_18 == 0) || (local_14 != 0)) {
            if (local_38 == 0) {
              local_34 = -1;
              sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/core_id",(ulong)local_c);
              iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
              if (iVar1 == 0) {
                local_34 = local_33c;
              }
            }
            local_b8 = FUN_0024febd(param_1,2,local_34);
            if (local_14 != 0) {
              FUN_002618f3(local_b0,local_c);
            }
            *(long *)(local_b8 + 0xb8) = local_b0;
            FUN_0024fb45(param_1,0,local_b8,"linux:sysfs:core");
            local_b0 = 0;
          }
          else {
            FUN_00260f71(local_b0);
          }
        }
      }
      if ((local_18 == 0) && (iVar1 = FUN_00276ce7(param_1,0xc), iVar1 != 0)) {
        sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/cluster_cpus",(ulong)local_c);
        local_30 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
        if (local_30 != 0) {
          FUN_002626c1(local_30,local_30,local_90);
          iVar1 = FUN_00262e86(local_30);
          if (iVar1 == 1) {
            FUN_00260f71(local_30);
            local_30 = 0;
          }
          else {
            uVar2 = FUN_00262aab(local_30);
            if (local_c != uVar2) {
              FUN_00260f71(local_30);
              local_30 = 0;
              local_20 = 1;
              local_1c = 1;
            }
          }
        }
      }
      if ((local_1c == 0) && (iVar1 = FUN_00276ce7(param_1,0x13), iVar1 != 0)) {
        sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/die_cpus",(ulong)local_c);
        local_28 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
        if (local_28 != 0) {
          FUN_002626c1(local_28,local_28,local_90);
          iVar1 = FUN_00262e86(local_28);
          if (iVar1 == 1) {
            FUN_00260f71(local_28);
            local_28 = 0;
          }
          else {
            uVar2 = FUN_00262aab(local_28);
            if (local_c != uVar2) {
              FUN_00260f71(local_28);
              local_28 = 0;
              local_20 = 1;
            }
          }
          if (((local_30 != 0) && (local_28 != 0)) &&
             (iVar1 = FUN_00262158(local_28,local_30), iVar1 != 0)) {
            FUN_00260f71(local_30);
            local_30 = 0;
          }
        }
      }
      if ((local_20 == 0) && (iVar1 = FUN_00276ce7(param_1,1), iVar1 != 0)) {
        if (param_3 == 0) {
          sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/package_cpus",(ulong)local_c);
        }
        else {
          sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/core_siblings",(ulong)local_c);
        }
        local_48 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
        if (local_48 != 0) {
          FUN_002626c1(local_48,local_48,local_90);
          if ((local_28 != 0) && (iVar1 = FUN_00262158(local_48,local_28), iVar1 != 0)) {
            FUN_00260f71(local_28);
            local_28 = 0;
          }
          if ((local_30 != 0) && (iVar1 = FUN_00262158(local_48,local_30), iVar1 != 0)) {
            FUN_00260f71(local_30);
            local_30 = 0;
          }
          uVar2 = FUN_00262aab(local_48);
          if (local_c == uVar2) {
            local_4c = -1;
            sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/physical_package_id",
                    (ulong)local_c);
            iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
            if (iVar1 == 0) {
              local_4c = local_33c;
            }
            local_c0 = FUN_0024febd(param_1,1,local_4c);
            *(long *)(local_c0 + 0xb8) = local_48;
            if (param_4 != 0) {
              for (local_10 = 0; (int)local_10 < param_5; local_10 = local_10 + 1) {
                if (local_c == (uint)*(undefined8 *)(param_4 + (long)(int)local_10 * 0x18)) {
                  FUN_0024de0e(local_c0 + 0xd8,local_c0 + 0xe0,
                               param_4 + (long)(int)local_10 * 0x18 + 8,
                               param_4 + (long)(int)local_10 * 0x18 + 0x10);
                }
              }
            }
            FUN_0024fb45(param_1,0,local_c0,"linux:sysfs:package");
            local_48 = 0;
          }
          FUN_00260f71(local_48);
        }
      }
      if (local_30 != 0) {
        local_50 = -1;
        sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/cluster_id",(ulong)local_c);
        iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
        if (iVar1 == 0) {
          local_50 = local_33c;
        }
        local_c8 = FUN_0024febd(param_1,0xc,local_50);
        *(long *)(local_c8 + 0xb8) = local_30;
        pcVar5 = strdup("Cluster");
        *(char **)(local_c8 + 8) = pcVar5;
        *(undefined4 *)(*(long *)(local_c8 + 0x28) + 4) = 0xde;
        *(char *)(*(long *)(local_c8 + 0x28) + 0xc) = (char)local_a4;
        FUN_0024fb45(param_1,0,local_c8,"linux:sysfs:cluster");
      }
      if (local_28 != 0) {
        local_54 = -1;
        sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/die_id",(ulong)local_c);
        iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
        if (iVar1 == 0) {
          local_54 = local_33c;
        }
        local_d0 = FUN_0024febd(param_1,0x13,local_54);
        *(long *)(local_d0 + 0xb8) = local_28;
        FUN_0024fb45(param_1,0,local_d0,"linux:sysfs:die");
      }
      if ((*(int *)(param_2 + 0x18) == 4) && (iVar1 = FUN_00276ce7(param_1,0xc), iVar1 != 0)) {
        sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/book_siblings",(ulong)local_c);
        local_60 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
        if (local_60 != 0) {
          FUN_002626c1(local_60,local_60,local_90);
          uVar2 = FUN_00262aab(local_60);
          if (local_c == uVar2) {
            local_d4 = -1;
            sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/book_id",(ulong)local_c);
            iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
            if (iVar1 == 0) {
              local_d4 = local_33c;
              local_e0 = FUN_0024febd(param_1,0xc,local_33c);
              *(long *)(local_e0 + 0xb8) = local_60;
              pcVar5 = strdup("Book");
              *(char **)(local_e0 + 8) = pcVar5;
              *(undefined4 *)(*(long *)(local_e0 + 0x28) + 4) = 0x6e;
              *(undefined4 *)(*(long *)(local_e0 + 0x28) + 8) = 0;
              FUN_0024fb45(param_1,0,local_e0,"linux:sysfs:group:book");
              local_60 = 0;
            }
          }
          FUN_00260f71(local_60);
          sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/drawer_siblings",(ulong)local_c)
          ;
          local_68 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
          if (local_68 != 0) {
            FUN_002626c1(local_68,local_68,local_90);
            uVar2 = FUN_00262aab(local_68);
            if (local_c == uVar2) {
              local_e4 = -1;
              sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/drawer_id",(ulong)local_c);
              iVar1 = FUN_002772c8(local_328,&local_33c,*(undefined4 *)(param_2 + 8));
              if (iVar1 == 0) {
                local_e4 = local_33c;
                local_f0 = FUN_0024febd(param_1,0xc,local_33c);
                *(long *)(local_f0 + 0xb8) = local_68;
                pcVar5 = strdup("Drawer");
                *(char **)(local_f0 + 8) = pcVar5;
                *(undefined4 *)(*(long *)(local_f0 + 0x28) + 4) = 0x6e;
                *(undefined4 *)(*(long *)(local_f0 + 0x28) + 8) = 1;
                FUN_0024fb45(param_1,0,local_f0,"linux:sysfs:group:drawer");
                local_68 = 0;
              }
            }
            FUN_00260f71(local_68);
          }
        }
      }
      local_f8 = FUN_0024febd(param_1,3,local_c);
      local_100 = FUN_00260eab();
      FUN_002618f3(local_100,local_c);
      *(undefined8 *)(local_f8 + 0xb8) = local_100;
      FUN_0024fb45(param_1,0,local_f8,"linux:sysfs:pu");
      for (local_10 = 0; (int)local_10 < 10; local_10 = local_10 + 1) {
        sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/shared_cpu_map",
                (ulong)local_c,(ulong)local_10);
        local_70 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
        if (local_70 == 0) {
LAB_00281c22:
          FUN_00260f71(local_70);
        }
        else {
          iVar1 = FUN_002620a3(local_70);
          if (iVar1 != 0) {
            if (param_3 == 0) {
              sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/core_cpus",(ulong)local_c);
            }
            else {
              sprintf(local_328,"/sys/devices/system/cpu/cpu%d/topology/thread_siblings",
                      (ulong)local_c);
            }
            local_108 = FUN_002777e0(local_328,*(undefined4 *)(param_2 + 8));
            if (local_108 != 0) {
              FUN_00260f71(local_70);
              local_70 = local_108;
            }
          }
          FUN_002626c1(local_70,local_70,local_90);
          uVar2 = FUN_00262aab(local_70);
          if (local_c != uVar2) goto LAB_00281c22;
          local_74 = 0;
          local_370 = 0xffffffff;
          sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/level",(ulong)local_c,
                  (ulong)local_10);
          iVar1 = FUN_0027731c(local_328,&local_36c,*(undefined4 *)(param_2 + 8));
          if (iVar1 < 0) {
            FUN_00260f71(local_70);
          }
          else {
            sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/type",(ulong)local_c,
                    (ulong)local_10);
            lVar6 = FUN_00277243(local_328,local_358,0x14,*(undefined4 *)(param_2 + 8));
            if (0 < lVar6) {
              iVar1 = strncmp(local_358,"Data",4);
              if (iVar1 == 0) {
                local_74 = 1;
              }
              else {
                iVar1 = strncmp(local_358,"Unified",7);
                if (iVar1 == 0) {
                  local_74 = 0;
                }
                else {
                  iVar1 = strncmp(local_358,"Instruction",0xb);
                  if (iVar1 == 0) {
                    local_74 = 2;
                  }
                }
              }
            }
            sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/id",(ulong)local_c,
                    (ulong)local_10);
            FUN_0027731c(local_328,&local_370,*(undefined4 *)(param_2 + 8));
            local_10c = FUN_00276b97(local_36c,local_74);
            if ((local_10c == -1) || (iVar1 = FUN_00276ce7(param_1,local_10c), iVar1 == 0)) {
              FUN_00260f71(local_70);
            }
            else {
              local_35c = 0;
              sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/size",(ulong)local_c,
                      (ulong)local_10);
              FUN_0027731c(local_328,&local_35c,*(undefined4 *)(param_2 + 8));
              if ((local_35c != 0) || ((local_10c != 6 || (*(int *)(param_2 + 0x1c) == 0)))) {
                local_360 = 0;
                sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/coherency_line_size",
                        (ulong)local_c,(ulong)local_10);
                FUN_0027731c(local_328,&local_360,*(undefined4 *)(param_2 + 8));
                local_364 = 0;
                sprintf(local_328,"/sys/devices/system/cpu/cpu%d/cache/index%d/number_of_sets",
                        (ulong)local_c,(ulong)local_10);
                FUN_0027731c(local_328,&local_364,*(undefined4 *)(param_2 + 8));
                local_368 = 1;
                sprintf(local_328,
                        "/sys/devices/system/cpu/cpu%d/cache/index%d/physical_line_partition",
                        (ulong)local_c,(ulong)local_10);
                FUN_0027731c(local_328,&local_368,*(undefined4 *)(param_2 + 8));
                local_118 = FUN_0024febd(param_1,local_10c,local_370);
                **(long **)(local_118 + 0x28) = (ulong)local_35c << 10;
                *(undefined4 *)(*(long *)(local_118 + 0x28) + 8) = local_36c;
                *(uint *)(*(long *)(local_118 + 0x28) + 0xc) = local_360;
                *(undefined4 *)(*(long *)(local_118 + 0x28) + 0x14) = local_74;
                if ((local_360 == 0) || ((local_368 == 0 || (local_364 == 0)))) {
                  *(undefined4 *)(*(long *)(local_118 + 0x28) + 0x10) = 0;
                }
                else if (local_364 == 1) {
                  *(undefined4 *)(*(long *)(local_118 + 0x28) + 0x10) = 0;
                }
                else {
                  *(uint *)(*(long *)(local_118 + 0x28) + 0x10) =
                       (((local_35c << 10) / local_360) / local_368) / local_364;
                }
                *(long *)(local_118 + 0xb8) = local_70;
                FUN_0024fb45(param_1,0,local_118,"linux:sysfs:cache");
                local_70 = 0;
                goto LAB_00281c22;
              }
              FUN_00260f71(local_70);
            }
          }
        }
      }
    }
    FUN_00260f71(local_90);
    FUN_00260f71(local_80);
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00281c7f FUN_00281c7f =====

undefined8 FUN_00281c7f(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = strcmp("vendor_id",param_1);
  if (iVar1 == 0) {
    if (*param_2 != '\0') {
      FUN_0024dbec(param_3,param_4,"CPUVendor",param_2);
    }
  }
  else {
    iVar1 = strcmp("model name",param_1);
    if (iVar1 == 0) {
      if (*param_2 != '\0') {
        FUN_0024dbec(param_3,param_4,"CPUModel",param_2);
      }
    }
    else {
      iVar1 = strcmp("model",param_1);
      if (iVar1 == 0) {
        if (*param_2 != '\0') {
          FUN_0024dbec(param_3,param_4,"CPUModelNumber",param_2);
        }
      }
      else {
        iVar1 = strcmp("cpu family",param_1);
        if (iVar1 == 0) {
          if (*param_2 != '\0') {
            FUN_0024dbec(param_3,param_4,"CPUFamilyNumber",param_2);
          }
        }
        else {
          iVar1 = strcmp("stepping",param_1);
          if ((iVar1 == 0) && (*param_2 != '\0')) {
            FUN_0024dbec(param_3,param_4,"CPUStepping",param_2);
          }
        }
      }
    }
  }
  return 0;
}


// ===== 00281dff FUN_00281dff =====

undefined8 FUN_00281dff(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = strcmp("vendor",param_1);
  if (iVar1 == 0) {
    if (*param_2 != '\0') {
      FUN_0024dbec(param_3,param_4,"CPUVendor",param_2);
    }
  }
  else {
    iVar1 = strcmp("model name",param_1);
    if (iVar1 == 0) {
      if (*param_2 != '\0') {
        FUN_0024dbec(param_3,param_4,"CPUModel",param_2);
      }
    }
    else {
      iVar1 = strcmp("model",param_1);
      if (iVar1 == 0) {
        if (*param_2 != '\0') {
          FUN_0024dbec(param_3,param_4,"CPUModelNumber",param_2);
        }
      }
      else {
        iVar1 = strcmp("family",param_1);
        if ((iVar1 == 0) && (*param_2 != '\0')) {
          FUN_0024dbec(param_3,param_4,"CPUFamilyNumber",param_2);
        }
      }
    }
  }
  return 0;
}


// ===== 00281f36 FUN_00281f36 =====

undefined8 FUN_00281f36(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = strcmp("Processor",param_1);
  if ((iVar1 == 0) || (iVar1 = strcmp("model name",param_1), iVar1 == 0)) {
    if (*param_2 != '\0') {
      FUN_0024dbec(param_3,param_4,"CPUModel",param_2);
    }
    return 0;
  }
  iVar1 = strcmp("CPU implementer",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"CPUImplementer",param_2);
    return 0;
  }
  iVar1 = strcmp("CPU architecture",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"CPUArchitecture",param_2);
    return 0;
  }
  iVar1 = strcmp("CPU variant",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"CPUVariant",param_2);
    return 0;
  }
  iVar1 = strcmp("CPU part",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"CPUPart",param_2);
    return 0;
  }
  iVar1 = strcmp("CPU revision",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"CPURevision",param_2);
    return 0;
  }
  iVar1 = strcmp("Hardware",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"HardwareName",param_2);
    return 0;
  }
  iVar1 = strcmp("Revision",param_1);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      return 0;
    }
    FUN_0024dbec(param_3,param_4,"HardwareRevision",param_2);
    return 0;
  }
  iVar1 = strcmp("Serial",param_1);
  if (iVar1 != 0) {
    return 0;
  }
  if (*param_2 == '\0') {
    return 0;
  }
  FUN_0024dbec(param_3,param_4,"HardwareSerial",param_2);
  return 0;
}


// ===== 002821f1 FUN_002821f1 =====

undefined8
FUN_002821f1(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = strcmp("cpu",param_1);
  if (iVar1 == 0) {
    if (*param_2 != '\0') {
      FUN_0024dbec(param_3,param_4,"CPUModel",param_2);
    }
  }
  else {
    iVar1 = strcmp("platform",param_1);
    if (iVar1 == 0) {
      if (*param_2 != '\0') {
        FUN_0024dbec(param_3,param_4,"PlatformName",param_2);
      }
    }
    else {
      iVar1 = strcmp("model",param_1);
      if (iVar1 == 0) {
        if (*param_2 != '\0') {
          FUN_0024dbec(param_3,param_4,"PlatformModel",param_2);
        }
      }
      else {
        iVar1 = strcasecmp("vendor",param_1);
        if (iVar1 == 0) {
          if (*param_2 != '\0') {
            FUN_0024dbec(param_3,param_4,"PlatformVendor",param_2);
          }
        }
        else {
          iVar1 = strcmp("Board ID",param_1);
          if (iVar1 == 0) {
            if (*param_2 != '\0') {
              FUN_0024dbec(param_3,param_4,"PlatformBoardID",param_2);
            }
          }
          else {
            iVar1 = strcmp("Board",param_1);
            if ((iVar1 != 0) && (iVar1 = strcasecmp("Machine",param_1), iVar1 != 0)) {
              iVar1 = strcasecmp("Revision",param_1);
              if ((iVar1 == 0) || (iVar1 = strcmp("Hardware rev",param_1), iVar1 == 0)) {
                if (*param_2 == '\0') {
                  return 0;
                }
                if (param_5 == 0) {
                  pcVar2 = "CPURevision";
                }
                else {
                  pcVar2 = "PlatformRevision";
                }
                FUN_0024dbec(param_3,param_4,pcVar2,param_2);
                return 0;
              }
              iVar1 = strcmp("SVR",param_1);
              if (iVar1 == 0) {
                if (*param_2 == '\0') {
                  return 0;
                }
                FUN_0024dbec(param_3,param_4,"SystemVersionRegister",param_2);
                return 0;
              }
              iVar1 = strcmp("PVR",param_1);
              if (iVar1 != 0) {
                return 0;
              }
              if (*param_2 == '\0') {
                return 0;
              }
              FUN_0024dbec(param_3,param_4,"ProcessorVersionRegister",param_2);
              return 0;
            }
            if (*param_2 != '\0') {
              FUN_0024dd20(param_3,param_4,"PlatformModel",param_2,1);
            }
          }
        }
      }
    }
  }
  return 0;
}


// ===== 002824d8 FUN_002824d8 =====

undefined8 FUN_002824d8(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = strcmp("model name",param_1);
  if ((((iVar1 != 0) && (iVar1 = strcmp("Processor",param_1), iVar1 != 0)) &&
      (iVar1 = strcmp("chip type",param_1), iVar1 != 0)) &&
     ((iVar1 = strcmp("cpu model",param_1), iVar1 != 0 &&
      (iVar1 = strcasecmp("cpu",param_1), iVar1 != 0)))) {
    return 0;
  }
  if (*param_2 != '\0') {
    FUN_0024dd20(param_3,param_4,"CPUModel",param_2,1);
  }
  return 0;
}


// ===== 0028259d FUN_0028259d =====

uint FUN_0028259d(long param_1,undefined8 param_2,undefined8 *param_3,long param_4,long param_5)

{
  uint uVar1;
  long lVar2;
  void *pvVar3;
  int iVar4;
  size_t sVar5;
  long lVar6;
  char *pcVar7;
  char *local_f0;
  char local_e8 [128];
  void *local_68;
  ulong local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  FILE *local_40;
  int local_34;
  char *local_30;
  code *local_28;
  uint local_20;
  uint local_1c;
  void *local_18;
  uint local_c;
  
  local_c = 0;
  local_18 = (void *)0x0;
  local_1c = 0;
  local_20 = 0xffffffff;
  local_28 = (code *)0x0;
  local_40 = (FILE *)FUN_0027716f(param_2,&DAT_002f19cb,*(undefined4 *)(param_1 + 8));
  if (local_40 == (FILE *)0x0) {
    FUN_00276d47("could not open %s\n",param_2);
    local_1c = 0xffffffff;
  }
  else {
    FUN_00276d47("\n\n * Topology extraction from %s *\n\n",param_2);
    while (pcVar7 = fgets(local_e8,0x80,local_40), pcVar7 != (char *)0x0) {
      local_34 = 0;
      local_30 = strchr(local_e8,10);
      if (local_30 == (char *)0x0) {
        local_34 = 1;
      }
      else {
        *local_30 = '\0';
      }
      if (local_e8[0] == '\0') {
        local_20 = 0xffffffff;
      }
      else {
        local_48 = strchr(local_e8,0x3a);
        if ((local_48 != (char *)0x0) &&
           (((local_e8[0] < '{' && ('`' < local_e8[0])) ||
            ((local_e8[0] < '[' && ('@' < local_e8[0])))))) {
          local_50 = local_e8;
          for (local_30 = local_48; (local_30[-1] == ' ' || (local_30[-1] == '\t'));
              local_30 = local_30 + -1) {
          }
          *local_30 = '\0';
          sVar5 = strspn(local_48 + 1," \t");
          local_58 = local_48 + sVar5 + 1;
          iVar4 = strcmp("processor",local_50);
          if (iVar4 == 0) {
            local_60 = strtoul(local_58,&local_f0,0);
            if (local_58 == local_f0) {
              FUN_00276d47("no number in processor field of %s\n",param_2);
LAB_00282a33:
              fclose(local_40);
              free(local_18);
              *param_3 = 0;
              return 0xffffffff;
            }
            if (local_60 == 0xffffffffffffffff) {
              FUN_00276d47("too big processor number in %s\n",param_2);
              goto LAB_00282a33;
            }
            FUN_00276d47("processor %lu\n",local_60);
            uVar1 = local_1c + 1;
            local_20 = local_1c;
            local_1c = uVar1;
            pvVar3 = local_18;
            if (local_c < uVar1) {
              if (local_c == 0) {
                local_c = 8;
              }
              else {
                local_c = local_c << 1;
              }
              local_68 = realloc(local_18,(ulong)local_c * 0x18);
              pvVar3 = local_68;
              if (local_68 == (void *)0x0) goto LAB_00282a33;
            }
            local_18 = pvVar3;
            *(ulong *)((long)(int)local_20 * 0x18 + (long)local_18) = local_60;
            *(undefined8 *)((long)local_18 + (long)(int)local_20 * 0x18 + 8) = 0;
            *(undefined4 *)((long)local_18 + (long)(int)local_20 * 0x18 + 0x10) = 0;
          }
          else {
            iVar4 = *(int *)(param_1 + 0x18);
            if (iVar4 == 1) {
              local_28 = FUN_00281dff;
            }
            else if (iVar4 == 0) {
              local_28 = FUN_00281c7f;
            }
            else if (iVar4 == 2) {
              local_28 = FUN_00281f36;
            }
            else if (iVar4 == 3) {
              local_28 = FUN_002821f1;
            }
            else {
              local_28 = FUN_002824d8;
            }
            lVar6 = param_4;
            lVar2 = param_5;
            if (-1 < (int)local_20) {
              lVar6 = (long)local_18 + (long)(int)local_20 * 0x18 + 8;
              lVar2 = (long)local_18 + (long)(int)local_20 * 0x18 + 0x10;
            }
            (*local_28)(local_50,local_58,lVar6,lVar2,local_20 >> 0x1f);
          }
          if (local_34 != 0) {
            iVar4 = fscanf(local_40,"%*[^\n]");
            if (iVar4 == -1) break;
            _IO_getc(local_40);
          }
        }
      }
    }
    fclose(local_40);
    *param_3 = local_18;
  }
  return local_1c;
}


// ===== 00282a60 FUN_00282a60 =====

void FUN_00282a60(void *param_1,uint param_2,undefined8 param_3,undefined4 param_4)

{
  uint local_c;
  
  if (param_1 != (void *)0x0) {
    for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
      FUN_0024db80(*(undefined8 *)((long)param_1 + (ulong)local_c * 0x18 + 8),
                   *(undefined4 *)((long)param_1 + (ulong)local_c * 0x18 + 0x10));
    }
    free(param_1);
  }
  FUN_0024db80(param_3,param_4);
  return;
}


// ===== 00282af7 FUN_00282af7 =====

void FUN_00282af7(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  ulonglong uVar4;
  char *pcVar5;
  char local_a8 [8];
  char acStack_a0 [2];
  char cStack_9e;
  char acStack_9d [3];
  char acStack_9a [8];
  char acStack_92 [114];
  char *local_20;
  char *local_18;
  FILE *local_10;
  
  memset((void *)(param_2 + 0x30),0,0x186);
  *(undefined4 *)(param_2 + 0x1b8) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x1bc) = 0x1000;
  if (*(int *)(param_1 + 200) != 0) {
    uname((utsname *)(param_2 + 0x30));
    uVar1 = FUN_0024da86(0);
    *(undefined4 *)(param_2 + 0x1b8) = uVar1;
    lVar3 = sysconf(0x1e);
    *(int *)(param_2 + 0x1bc) = (int)lVar3;
  }
  if ((*(int *)(param_2 + 0xc) == 0) &&
     (local_10 = (FILE *)FUN_0027716f("/proc/hwloc-nofile-info",&DAT_002f19cb,
                                      *(undefined4 *)(param_2 + 8)), local_10 != (FILE *)0x0)) {
    while (pcVar5 = fgets(local_a8,0x80,local_10), pcVar5 != (char *)0x0) {
      local_18 = strchr(local_a8,10);
      iVar2 = strncmp("OSName: ",local_a8,8);
      if (iVar2 == 0) {
        if (local_18 != (char *)0x0) {
          *local_18 = '\0';
        }
        strncpy((char *)(param_2 + 0x30),acStack_a0,0x41);
        *(undefined1 *)(param_2 + 0x70) = 0;
      }
      else {
        iVar2 = strncmp("OSRelease: ",local_a8,0xb);
        if (iVar2 == 0) {
          if (local_18 != (char *)0x0) {
            *local_18 = '\0';
          }
          strncpy((char *)(param_2 + 0xb2),acStack_9d,0x41);
          *(undefined1 *)(param_2 + 0xf2) = 0;
        }
        else {
          iVar2 = strncmp("OSVersion: ",local_a8,0xb);
          if (iVar2 == 0) {
            if (local_18 != (char *)0x0) {
              *local_18 = '\0';
            }
            strncpy((char *)(param_2 + 0xf3),acStack_9d,0x41);
            *(undefined1 *)(param_2 + 0x133) = 0;
          }
          else {
            iVar2 = strncmp("HostName: ",local_a8,10);
            if (iVar2 == 0) {
              if (local_18 != (char *)0x0) {
                *local_18 = '\0';
              }
              strncpy((char *)(param_2 + 0x71),&cStack_9e,0x41);
              *(undefined1 *)(param_2 + 0xb1) = 0;
            }
            else {
              iVar2 = strncmp("Architecture: ",local_a8,0xe);
              if (iVar2 == 0) {
                if (local_18 != (char *)0x0) {
                  *local_18 = '\0';
                }
                strncpy((char *)(param_2 + 0x134),acStack_9a,0x41);
                *(undefined1 *)(param_2 + 0x174) = 0;
              }
              else {
                iVar2 = strncmp("FallbackNbProcessors: ",local_a8,0x16);
                if (iVar2 == 0) {
                  if (local_18 != (char *)0x0) {
                    *local_18 = '\0';
                  }
                  iVar2 = atoi(acStack_92);
                  *(int *)(param_2 + 0x1b8) = iVar2;
                }
                else {
                  iVar2 = strncmp("PageSize: ",local_a8,10);
                  if (iVar2 == 0) {
                    if (local_18 != (char *)0x0) {
                      *local_18 = '\0';
                    }
                    uVar4 = strtoull(&cStack_9e,(char **)0x0,10);
                    *(int *)(param_2 + 0x1bc) = (int)uVar4;
                  }
                  else {
                    FUN_00276d47("ignored /proc/hwloc-nofile-info line %s\n",local_a8);
                  }
                }
              }
            }
          }
        }
      }
    }
    fclose(local_10);
  }
  local_20 = getenv("HWLOC_DUMP_NOFILE_INFO");
  if (((local_20 != (char *)0x0) && (*local_20 != '\0')) &&
     (local_10 = fopen(local_20,"w"), local_10 != (FILE *)0x0)) {
    if (*(char *)(param_2 + 0x30) != '\0') {
      fprintf(local_10,"OSName: %s\n",param_2 + 0x30);
    }
    if (*(char *)(param_2 + 0xb2) != '\0') {
      fprintf(local_10,"OSRelease: %s\n",param_2 + 0xb2);
    }
    if (*(char *)(param_2 + 0xf3) != '\0') {
      fprintf(local_10,"OSVersion: %s\n",param_2 + 0xf3);
    }
    if (*(char *)(param_2 + 0x71) != '\0') {
      fprintf(local_10,"HostName: %s\n",param_2 + 0x71);
    }
    if (*(char *)(param_2 + 0x134) != '\0') {
      fprintf(local_10,"Architecture: %s\n",param_2 + 0x134);
    }
    fprintf(local_10,"FallbackNbProcessors: %d\n",(ulong)*(uint *)(param_2 + 0x1b8));
    fprintf(local_10,"PageSize: %llu\n",(ulong)*(uint *)(param_2 + 0x1bc));
    fclose(local_10);
  }
  if (*(int *)(param_1 + 200) != 0) {
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  if ((*(int *)(param_2 + 0x18) == 5) && (*(char *)(param_2 + 0x134) != '\0')) {
    iVar2 = strcmp((char *)(param_2 + 0x134),"x86_64");
    if (((iVar2 == 0) ||
        ((*(char *)(param_2 + 0x134) == 'i' &&
         (iVar2 = strcmp((char *)(param_2 + 0x136),"86"), iVar2 == 0)))) ||
       (iVar2 = strcmp((char *)(param_2 + 0x134),"k1om"), iVar2 == 0)) {
      *(undefined4 *)(param_2 + 0x18) = 0;
    }
    else {
      iVar2 = strncmp((char *)(param_2 + 0x134),"arm",3);
      if (iVar2 == 0) {
        *(undefined4 *)(param_2 + 0x18) = 2;
      }
      else {
        iVar2 = strncmp((char *)(param_2 + 0x134),"ppc",3);
        if ((iVar2 == 0) || (iVar2 = strncmp((char *)(param_2 + 0x134),"power",5), iVar2 == 0)) {
          *(undefined4 *)(param_2 + 0x18) = 3;
        }
        else {
          iVar2 = strncmp((char *)(param_2 + 0x134),"s390",4);
          if (iVar2 == 0) {
            *(undefined4 *)(param_2 + 0x18) = 4;
          }
          else {
            iVar2 = strcmp((char *)(param_2 + 0x134),"ia64");
            if (iVar2 == 0) {
              *(undefined4 *)(param_2 + 0x18) = 1;
            }
          }
        }
      }
    }
  }
  return;
}


// ===== 00283275 FUN_00283275 =====

undefined8 FUN_00283275(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 uVar4;
  char local_98 [128];
  long local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(param_1 + 8);
  local_18 = *(long *)(param_1 + 0x38);
  pcVar2 = getenv("HWLOC_NO_HARDWIRED_TOPOLOGY");
  if (pcVar2 != (char *)0x0) {
    return 0xffffffff;
  }
  iVar1 = strcmp((char *)(local_18 + 0x134),"s64fx");
  if (iVar1 == 0) {
    lVar3 = FUN_00277243("/proc/cpuinfo",local_98,0x80,*(undefined4 *)(local_18 + 8));
    if (lVar3 < 1) {
      return 0xffffffff;
    }
    iVar1 = strncmp(local_98,"cpu\t",4);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    pcVar2 = strstr(local_98,"Fujitsu SPARC64 VIIIfx");
    if (pcVar2 != (char *)0x0) {
      uVar4 = FUN_002880ae(local_10);
      return uVar4;
    }
    pcVar2 = strstr(local_98,"Fujitsu SPARC64 IXfx");
    if (pcVar2 != (char *)0x0) {
      uVar4 = FUN_00288451(local_10);
      return uVar4;
    }
    pcVar2 = strstr(local_98,"FUJITSU SPARC64 XIfx");
    if (pcVar2 != (char *)0x0) {
      uVar4 = FUN_002887f4(local_10);
      return uVar4;
    }
  }
  return 0xffffffff;
}


// ===== 002833bf FUN_002833bf =====

void FUN_002833bf(long param_1,undefined8 param_2,undefined4 param_3,long *param_4)

{
  void *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = 0;
  FUN_00279e23(&local_14,&local_20,param_2,param_3);
  if (local_20 != (void *)0x0) {
    local_10 = FUN_0027a25a(param_3,*(undefined4 *)(param_1 + 0xd4));
    if (local_10 != 0) {
      FUN_0027a55e(param_3,local_14,local_20,local_10,&DAT_002f4083,*(undefined8 *)(param_1 + 0x1b8)
                  );
      FUN_0027a55e(param_3,local_14,local_20,local_10,&DAT_002f4088,*(undefined8 *)(param_1 + 0x1c0)
                  );
    }
    free(local_20);
  }
  *param_4 = local_10;
  return;
}


// ===== 00283491 FUN_00283491 =====

void FUN_00283491(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = *(long *)(param_1 + 0x38);
  if (*(int *)(lVar2 + 0x1b8) < 1) {
    *(undefined4 *)(lVar2 + 0x1b8) = 1;
  }
  else {
    **(undefined1 **)(lVar1 + 0x288) = 1;
  }
  FUN_0024dad7(lVar1,*(undefined4 *)(lVar2 + 0x1b8));
  return;
}


// ===== 002834fe FUN_002834fe =====

undefined8 FUN_002834fe(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  char local_1018 [4104];
  uint local_10;
  int local_c;
  
  iVar1 = FUN_0027719a("/sys/devices/system/cpu",5,param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_0027719a("/sys/devices/system/cpu/cpu0/topology/package_cpus",4,param_1);
    if ((iVar1 == 0) ||
       (iVar1 = FUN_0027719a("/sys/devices/system/cpu/cpu0/topology/core_cpus",4,param_1),
       iVar1 == 0)) {
      return 0;
    }
    iVar1 = FUN_0027719a("/sys/devices/system/cpu/cpu0/topology/core_siblings",4,param_1);
    if ((iVar1 == 0) ||
       (iVar1 = FUN_0027719a("/sys/devices/system/cpu/cpu0/topology/thread_siblings",4,param_1),
       iVar1 == 0)) {
      *param_2 = 1;
      return 0;
    }
  }
  FUN_00276d47("Failed to find sysfs cpu files using cpu0, looking at online CPUs...\n");
  local_c = FUN_0027731c("/sys/devices/system/cpu/online",&local_10,param_1);
  if (local_c == 0) {
    FUN_00276d47("Found CPU#%u as first online CPU\n",local_10);
    iVar1 = FUN_0027719a("/sys/devices/system/cpu",5,param_1);
    if (iVar1 == 0) {
      snprintf(local_1018,0x1000,"/sys/devices/system/cpu/cpu%u/topology/package_cpus",
               (ulong)local_10);
      iVar1 = FUN_0027719a(local_1018,4,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      snprintf(local_1018,0x1000,"/sys/devices/system/cpu/cpu%u/topology/core_cpus",(ulong)local_10)
      ;
      iVar1 = FUN_0027719a(local_1018,4,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      snprintf(local_1018,0x1000,"/sys/devices/system/cpu/cpu%u/topology/core_siblings",
               (ulong)local_10);
      iVar1 = FUN_0027719a(local_1018,4,param_1);
      if (iVar1 == 0) {
        *param_2 = 1;
        return 0;
      }
      snprintf(local_1018,0x1000,"/sys/devices/system/cpu/cpu%u/topology/thread_siblings",
               (ulong)local_10);
      iVar1 = FUN_0027719a(local_1018,4,param_1);
      if (iVar1 == 0) {
        *param_2 = 1;
        return 0;
      }
    }
  }
  else {
    FUN_00276d47("Failed to find read /sys/devices/system/cpu/online.\n");
  }
  return 0xffffffff;
}


// ===== 0028379b FUN_0028379b =====

undefined8 FUN_0028379b(long param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  int local_78;
  undefined4 local_74;
  undefined8 local_70;
  long local_68;
  void *local_60;
  undefined4 local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined8 *local_48;
  long local_40;
  char *local_38;
  char *local_30;
  char *local_28;
  uint local_20;
  int local_1c;
  
  local_40 = *(long *)(param_1 + 8);
  local_48 = *(undefined8 **)(param_1 + 0x38);
  local_60 = (void *)0x0;
  local_68 = 0;
  local_70 = 0;
  local_74 = 0;
  local_78 = 0;
  local_4c = FUN_002834fe(*(undefined4 *)(local_48 + 1),&local_78);
  if (local_78 == 0) {
    puVar2 = &DAT_002f42f3;
  }
  else {
    puVar2 = &DAT_002f42ef;
  }
  FUN_00276d47("Found sysfs cpu files under /sys/devices/system/cpu with %s topology filenames\n",
               puVar2);
  if (local_4c < 0) {
    iVar1 = FUN_0024d64f();
    if (iVar1 < 2) {
      fwrite("hwloc/linux: failed to find sysfs cpu topology directory, aborting linux discovery.\n"
             ,1,0x54,*(FILE **)PTR_stderr_0032efe0);
    }
    uVar3 = 0xffffffff;
  }
  else {
    if ((*(long *)(*(long *)**(undefined8 **)(local_40 + 0x18) + 0xc0) == 0) ||
       (iVar1 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(local_40 + 0x18) + 0xc0)),
       iVar1 != 0)) {
      local_50 = 0;
    }
    else {
      local_50 = 1;
    }
    if ((*(long *)(*(long *)**(undefined8 **)(local_40 + 0x18) + 0xd0) == 0) ||
       (iVar1 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(local_40 + 0x18) + 0xd0)),
       iVar1 != 0)) {
      local_54 = 0;
    }
    else {
      local_54 = 1;
    }
    if (local_54 != 0) {
      FUN_00252fa3(local_40,0);
    }
    FUN_002531e1(*(undefined8 *)**(undefined8 **)(local_40 + 0x18));
    FUN_00282af7(local_40,local_48);
    local_1c = FUN_0028259d(local_48,"/proc/cpuinfo",&local_68,&local_70,&local_74);
    if (local_1c < 0) {
      local_1c = 0;
    }
    if ((*(int *)(local_48 + 3) == 0) && (0 < local_1c)) {
      local_28 = (char *)0x0;
      local_30 = (char *)0x0;
      local_38 = (char *)0x0;
      for (local_20 = 0; local_20 < *(uint *)(local_68 + 0x10); local_20 = local_20 + 1) {
        iVar1 = strcmp(*(char **)(*(long *)(local_68 + 8) + (ulong)local_20 * 0x10),"CPUVendor");
        if (iVar1 == 0) {
          local_28 = *(char **)(*(long *)(local_68 + 8) + (ulong)local_20 * 0x10 + 8);
        }
        else {
          iVar1 = strcmp(*(char **)(*(long *)(local_68 + 8) + (ulong)local_20 * 0x10),
                         "CPUFamilyNumber");
          if (iVar1 == 0) {
            local_30 = *(char **)(*(long *)(local_68 + 8) + (ulong)local_20 * 0x10 + 8);
          }
          else {
            iVar1 = strcmp(*(char **)(*(long *)(local_68 + 8) + (ulong)local_20 * 0x10),
                           "CPUModelNumber");
            if (iVar1 == 0) {
              local_38 = *(char **)(*(long *)(local_68 + 8) + (ulong)local_20 * 0x10 + 8);
            }
          }
        }
      }
      if (((((local_28 != (char *)0x0) && (iVar1 = strcmp(local_28,"GenuineIntel"), iVar1 == 0)) &&
           (local_30 != (char *)0x0)) &&
          ((iVar1 = strcmp(local_30,"6"), iVar1 == 0 && (local_38 != (char *)0x0)))) &&
         ((iVar1 = strcmp(local_38,"87"), iVar1 == 0 || (iVar1 = strcmp(local_38,"133"), iVar1 == 0)
          ))) {
        *(undefined4 *)((long)local_48 + 0x1c) = 1;
      }
      if (((local_28 != (char *)0x0) && (iVar1 = strcmp(local_28,"AuthenticAMD"), iVar1 == 0)) &&
         ((local_30 != (char *)0x0 &&
          ((iVar1 = strcmp(local_30,"21"), iVar1 == 0 || (iVar1 = strcmp(local_30,"22"), iVar1 == 0)
           ))))) {
        *(undefined4 *)(local_48 + 4) = 1;
      }
    }
    if ((*(ulong *)(param_2 + 8) & 2) == 0) {
      FUN_002833bf(local_40,*local_48,*(undefined4 *)(local_48 + 1),&local_60);
      *(ulong *)(param_2 + 8) = *(ulong *)(param_2 + 8) | 2;
    }
    if ((local_50 == 0) && (local_4c = FUN_00283275(param_1), local_4c != 0)) {
      lVar4 = FUN_00276b03(local_40);
      lVar5 = FUN_00276b03(local_40);
      FUN_0024de0e(lVar5 + 0xd8,lVar4 + 0xe0,&local_70,&local_74);
      iVar1 = FUN_002805f4(local_40,local_48,local_78,local_68,local_1c);
      if (iVar1 < 0) {
        FUN_00283491(param_1);
      }
    }
    if ((*(ulong *)(local_40 + 0x20) & 0x200) == 0) {
      FUN_0028016c(local_40,local_48);
    }
    FUN_0027aa1e(local_48,local_40 + 0x338);
    iVar1 = FUN_0027719a("/sys/devices/system/node",5,*(undefined4 *)(local_48 + 1));
    if (iVar1 == 0) {
      iVar1 = FUN_00276a13(local_40,0xd);
      if (iVar1 < 1) {
        FUN_0027ed5e(local_40,local_48,&local_58);
      }
      else {
        FUN_0027eb01(local_40,local_48,&local_58);
      }
    }
    else {
      local_58 = 0;
    }
    FUN_0027af84(local_48,*(undefined8 *)**(undefined8 **)(local_40 + 0x18));
    FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(local_40 + 0x18),"Backend","Linux");
    if (local_60 != (void *)0x0) {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(local_40 + 0x18),"LinuxCgroup",local_60);
      free(local_60);
    }
    FUN_00265779(local_40,local_48 + 6);
    FUN_00282a60(local_68,local_1c,local_70,local_74);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00283d99 FUN_00283d99 =====

undefined8 FUN_00283d99(long param_1,ushort *param_2,undefined8 param_3)

{
  int iVar1;
  char local_118 [260];
  int local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  snprintf(local_118,0x100,"/sys/bus/pci/devices/%04x:%02x:%02x.%01x/local_cpus",(ulong)*param_2,
           (ulong)(byte)param_2[1],(ulong)*(byte *)((long)param_2 + 3),(ulong)(byte)param_2[2]);
  local_14 = FUN_00277548(local_118,param_3,*(undefined4 *)(local_10 + 8));
  if ((local_14 == 0) && (iVar1 = FUN_002620a3(param_3), iVar1 == 0)) {
    return 0;
  }
  return 0xffffffff;
}


// ===== 00283e7a FUN_00283e7a =====

undefined8 FUN_00283e7a(undefined8 param_1,undefined4 param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  int local_11c;
  char local_118 [268];
  int local_c;
  
  if ((int)param_4 < 0) {
    snprintf(local_118,0x100,"%s/numa_node",param_3);
    local_c = FUN_002772c8(local_118,&local_11c,param_2);
    if ((local_c == 0) && (-1 < local_11c)) {
      uVar1 = FUN_002769c1(param_1,local_11c);
    }
    else {
      if ((param_4 & 0x40000000) != 0) {
        snprintf(local_118,0x100,"%s/../numa_node",param_3);
        local_c = FUN_002772c8(local_118,&local_11c,param_2);
        if ((local_c == 0) && (-1 < local_11c)) {
          uVar1 = FUN_002769c1(param_1,local_11c);
          return uVar1;
        }
      }
      uVar1 = 0;
    }
  }
  else {
    snprintf(local_118,0x100,"%s/device/numa_node",param_3);
    local_c = FUN_002772c8(local_118,&local_11c,param_2);
    if ((local_c == 0) && (-1 < local_11c)) {
      uVar1 = FUN_002769c1(param_1,local_11c);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ===== 00284038 FUN_00284038 =====

undefined4 * FUN_00284038(long param_1,undefined4 param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  char *pcVar2;
  char local_258 [256];
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  char local_148 [264];
  undefined8 local_40;
  int local_34;
  undefined4 *local_30;
  char *local_28;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_40 = *(undefined8 *)(param_1 + 8);
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_34 = FUN_00277213(param_3,local_148,0x100,param_2);
  if (local_34 < 0) {
    snprintf(local_258,0x100,"%s/device",param_3);
    local_34 = FUN_00277213(local_258,local_148,0x100,param_2);
    if (local_34 < 0) {
      return (undefined4 *)0x0;
    }
  }
  local_148[local_34] = '\0';
  if (((param_4 & 1) == 0) && (pcVar2 = strstr(local_148,"/virtual/"), pcVar2 != (char *)0x0)) {
    local_30 = (undefined4 *)0x0;
  }
  else if (((param_4 & 2) == 0) && (pcVar2 = strstr(local_148,"/usb"), pcVar2 != (char *)0x0)) {
    local_30 = (undefined4 *)0x0;
  }
  else {
    local_28 = strstr(local_148,"/pci");
    if (local_28 == (char *)0x0) {
      local_28 = (char *)0x0;
    }
    else {
      local_28 = strchr(local_28 + 4,0x2f);
      if (local_28 == (char *)0x0) {
        local_28 = (char *)0x0;
      }
      else {
        local_28 = local_28 + 1;
        local_c = 0;
        while( true ) {
          while (iVar1 = sscanf(local_28,"%x:%x:%x.%x",&local_14c,&local_150,&local_154,&local_158),
                iVar1 == 4) {
            local_c = 1;
            local_10 = local_14c;
            local_14 = local_150;
            local_18 = local_154;
            local_1c = local_158;
            local_28 = strchr(local_28 + 4,0x3a);
            local_28 = local_28 + 9;
          }
          iVar1 = sscanf(local_28,"%x:%x.%x",&local_150,&local_154,&local_158);
          if (iVar1 != 3) break;
          local_c = 1;
          local_10 = 0;
          local_14 = local_150;
          local_18 = local_154;
          local_1c = local_158;
          local_28 = local_28 + 8;
        }
        if ((local_c != 0) &&
           (local_30 = (undefined4 *)FUN_00264bbb(local_40,local_10,local_14,local_18,local_1c),
           local_30 != (undefined4 *)0x0)) {
          return local_30;
        }
      }
    }
    local_30 = (undefined4 *)FUN_00283e7a(local_40,param_2,param_3,param_4);
    if (local_30 == (undefined4 *)0x0) {
      local_30 = (undefined4 *)FUN_00276b03(local_40);
    }
    else {
      while (iVar1 = FUN_00276c63(*local_30), iVar1 != 0) {
        local_30 = *(undefined4 **)(local_30 + 0x12);
      }
    }
  }
  return local_30;
}


// ===== 00284364 FUN_00284364 =====

long FUN_00284364(long param_1,undefined8 param_2,undefined4 param_3,char *param_4)

{
  undefined8 uVar1;
  long lVar2;
  char *pcVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  lVar2 = FUN_0024febd(uVar1,0x10,0xffffffff);
  pcVar3 = strdup(param_4);
  *(char **)(lVar2 + 0x18) = pcVar3;
  **(undefined4 **)(lVar2 + 0x28) = param_3;
  FUN_0024fc99(uVar1,param_2,lVar2);
  return lVar2;
}


// ===== 002843e2 FUN_002843e2 =====

void FUN_002843e2(undefined8 param_1,undefined4 param_2,long param_3,undefined8 param_4,uint param_5
                 )

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  uint local_320;
  uint local_31c;
  char local_318 [56];
  ulong local_2e0;
  char local_2d8 [56];
  ulong local_2a0;
  char local_298 [56];
  ulong local_260;
  char local_258 [56];
  ulong local_220;
  ulong local_218 [8];
  char local_1d8 [10];
  char cStack_1ce;
  char cStack_1cd;
  char acStack_1cc [2];
  char acStack_1ca [4];
  char acStack_1c6 [110];
  char local_158 [296];
  char *local_30;
  FILE *local_28;
  char *local_20;
  ulonglong local_18;
  int local_10;
  uint local_c;
  
  local_218[0] = 0;
  local_218[1] = 0;
  local_218[2] = 0;
  local_218[3] = 0;
  local_218[4] = 0;
  local_218[5] = 0;
  local_218[6] = 0;
  local_218[7] = 0;
  local_258[0] = '\0';
  local_258[1] = '\0';
  local_258[2] = '\0';
  local_258[3] = '\0';
  local_258[4] = '\0';
  local_258[5] = '\0';
  local_258[6] = '\0';
  local_258[7] = '\0';
  local_258[8] = '\0';
  local_258[9] = '\0';
  local_258[10] = '\0';
  local_258[0xb] = '\0';
  local_258[0xc] = '\0';
  local_258[0xd] = '\0';
  local_258[0xe] = '\0';
  local_258[0xf] = '\0';
  local_258[0x10] = '\0';
  local_258[0x11] = '\0';
  local_258[0x12] = '\0';
  local_258[0x13] = '\0';
  local_258[0x14] = '\0';
  local_258[0x15] = '\0';
  local_258[0x16] = '\0';
  local_258[0x17] = '\0';
  local_258[0x18] = '\0';
  local_258[0x19] = '\0';
  local_258[0x1a] = '\0';
  local_258[0x1b] = '\0';
  local_258[0x1c] = '\0';
  local_258[0x1d] = '\0';
  local_258[0x1e] = '\0';
  local_258[0x1f] = '\0';
  local_258[0x20] = '\0';
  local_258[0x21] = '\0';
  local_258[0x22] = '\0';
  local_258[0x23] = '\0';
  local_258[0x24] = '\0';
  local_258[0x25] = '\0';
  local_258[0x26] = '\0';
  local_258[0x27] = '\0';
  local_258[0x28] = '\0';
  local_258[0x29] = '\0';
  local_258[0x2a] = '\0';
  local_258[0x2b] = '\0';
  local_258[0x2c] = '\0';
  local_258[0x2d] = '\0';
  local_258[0x2e] = '\0';
  local_258[0x2f] = '\0';
  local_258[0x30] = '\0';
  local_258[0x31] = '\0';
  local_258[0x32] = '\0';
  local_258[0x33] = '\0';
  local_258[0x34] = '\0';
  local_258[0x35] = '\0';
  local_258[0x36] = '\0';
  local_258[0x37] = '\0';
  local_220 = 0;
  local_298[0] = '\0';
  local_298[1] = '\0';
  local_298[2] = '\0';
  local_298[3] = '\0';
  local_298[4] = '\0';
  local_298[5] = '\0';
  local_298[6] = '\0';
  local_298[7] = '\0';
  local_298[8] = '\0';
  local_298[9] = '\0';
  local_298[10] = '\0';
  local_298[0xb] = '\0';
  local_298[0xc] = '\0';
  local_298[0xd] = '\0';
  local_298[0xe] = '\0';
  local_298[0xf] = '\0';
  local_298[0x10] = '\0';
  local_298[0x11] = '\0';
  local_298[0x12] = '\0';
  local_298[0x13] = '\0';
  local_298[0x14] = '\0';
  local_298[0x15] = '\0';
  local_298[0x16] = '\0';
  local_298[0x17] = '\0';
  local_298[0x18] = '\0';
  local_298[0x19] = '\0';
  local_298[0x1a] = '\0';
  local_298[0x1b] = '\0';
  local_298[0x1c] = '\0';
  local_298[0x1d] = '\0';
  local_298[0x1e] = '\0';
  local_298[0x1f] = '\0';
  local_298[0x20] = '\0';
  local_298[0x21] = '\0';
  local_298[0x22] = '\0';
  local_298[0x23] = '\0';
  local_298[0x24] = '\0';
  local_298[0x25] = '\0';
  local_298[0x26] = '\0';
  local_298[0x27] = '\0';
  local_298[0x28] = '\0';
  local_298[0x29] = '\0';
  local_298[0x2a] = '\0';
  local_298[0x2b] = '\0';
  local_298[0x2c] = '\0';
  local_298[0x2d] = '\0';
  local_298[0x2e] = '\0';
  local_298[0x2f] = '\0';
  local_298[0x30] = '\0';
  local_298[0x31] = '\0';
  local_298[0x32] = '\0';
  local_298[0x33] = '\0';
  local_298[0x34] = '\0';
  local_298[0x35] = '\0';
  local_298[0x36] = '\0';
  local_298[0x37] = '\0';
  local_260 = 0;
  local_2d8[0] = '\0';
  local_2d8[1] = '\0';
  local_2d8[2] = '\0';
  local_2d8[3] = '\0';
  local_2d8[4] = '\0';
  local_2d8[5] = '\0';
  local_2d8[6] = '\0';
  local_2d8[7] = '\0';
  local_2d8[8] = '\0';
  local_2d8[9] = '\0';
  local_2d8[10] = '\0';
  local_2d8[0xb] = '\0';
  local_2d8[0xc] = '\0';
  local_2d8[0xd] = '\0';
  local_2d8[0xe] = '\0';
  local_2d8[0xf] = '\0';
  local_2d8[0x10] = '\0';
  local_2d8[0x11] = '\0';
  local_2d8[0x12] = '\0';
  local_2d8[0x13] = '\0';
  local_2d8[0x14] = '\0';
  local_2d8[0x15] = '\0';
  local_2d8[0x16] = '\0';
  local_2d8[0x17] = '\0';
  local_2d8[0x18] = '\0';
  local_2d8[0x19] = '\0';
  local_2d8[0x1a] = '\0';
  local_2d8[0x1b] = '\0';
  local_2d8[0x1c] = '\0';
  local_2d8[0x1d] = '\0';
  local_2d8[0x1e] = '\0';
  local_2d8[0x1f] = '\0';
  local_2d8[0x20] = '\0';
  local_2d8[0x21] = '\0';
  local_2d8[0x22] = '\0';
  local_2d8[0x23] = '\0';
  local_2d8[0x24] = '\0';
  local_2d8[0x25] = '\0';
  local_2d8[0x26] = '\0';
  local_2d8[0x27] = '\0';
  local_2d8[0x28] = '\0';
  local_2d8[0x29] = '\0';
  local_2d8[0x2a] = '\0';
  local_2d8[0x2b] = '\0';
  local_2d8[0x2c] = '\0';
  local_2d8[0x2d] = '\0';
  local_2d8[0x2e] = '\0';
  local_2d8[0x2f] = '\0';
  local_2d8[0x30] = '\0';
  local_2d8[0x31] = '\0';
  local_2d8[0x32] = '\0';
  local_2d8[0x33] = '\0';
  local_2d8[0x34] = '\0';
  local_2d8[0x35] = '\0';
  local_2d8[0x36] = '\0';
  local_2d8[0x37] = '\0';
  local_2a0 = 0;
  local_318[0] = '\0';
  local_318[1] = '\0';
  local_318[2] = '\0';
  local_318[3] = '\0';
  local_318[4] = '\0';
  local_318[5] = '\0';
  local_318[6] = '\0';
  local_318[7] = '\0';
  local_318[8] = '\0';
  local_318[9] = '\0';
  local_318[10] = '\0';
  local_318[0xb] = '\0';
  local_318[0xc] = '\0';
  local_318[0xd] = '\0';
  local_318[0xe] = '\0';
  local_318[0xf] = '\0';
  local_318[0x10] = '\0';
  local_318[0x11] = '\0';
  local_318[0x12] = '\0';
  local_318[0x13] = '\0';
  local_318[0x14] = '\0';
  local_318[0x15] = '\0';
  local_318[0x16] = '\0';
  local_318[0x17] = '\0';
  local_318[0x18] = '\0';
  local_318[0x19] = '\0';
  local_318[0x1a] = '\0';
  local_318[0x1b] = '\0';
  local_318[0x1c] = '\0';
  local_318[0x1d] = '\0';
  local_318[0x1e] = '\0';
  local_318[0x1f] = '\0';
  local_318[0x20] = '\0';
  local_318[0x21] = '\0';
  local_318[0x22] = '\0';
  local_318[0x23] = '\0';
  local_318[0x24] = '\0';
  local_318[0x25] = '\0';
  local_318[0x26] = '\0';
  local_318[0x27] = '\0';
  local_318[0x28] = '\0';
  local_318[0x29] = '\0';
  local_318[0x2a] = '\0';
  local_318[0x2b] = '\0';
  local_318[0x2c] = '\0';
  local_318[0x2d] = '\0';
  local_318[0x2e] = '\0';
  local_318[0x2f] = '\0';
  local_318[0x30] = '\0';
  local_318[0x31] = '\0';
  local_318[0x32] = '\0';
  local_318[0x33] = '\0';
  local_318[0x34] = '\0';
  local_318[0x35] = '\0';
  local_318[0x36] = '\0';
  local_318[0x37] = '\0';
  local_2e0 = 0;
  local_c = 0;
  local_10 = 0;
  snprintf(local_158,0x128,"%s/size",param_4);
  lVar2 = FUN_00277243(local_158,local_1d8,0x80,param_2);
  if (0 < lVar2) {
    local_18 = strtoull(local_1d8,(char **)0x0,10);
    if ((param_5 & 4) == 0) {
      uVar3 = local_18 >> 10;
    }
    else {
      uVar3 = local_18 >> 1;
    }
    snprintf(local_1d8,0x80,"%llu",uVar3);
    FUN_0024dfb5(param_3,&DAT_002f447d,local_1d8);
  }
  snprintf(local_158,0x128,"%s/queue/hw_sector_size",param_4);
  lVar2 = FUN_00277243(local_158,local_1d8,0x80,param_2);
  if (0 < lVar2) {
    uVar3 = strtoul(local_1d8,(char **)0x0,10);
    local_c = (uint)uVar3;
  }
  if (local_c != 0) {
    snprintf(local_1d8,0x80,"%u",(ulong)local_c);
    FUN_0024dfb5(param_3,"SectorSize",local_1d8);
  }
  if ((int)param_5 < 0) {
    if ((param_5 & 0x40000000) == 0) {
      snprintf(local_158,0x128,"%s/devtype",param_4);
    }
    else {
      snprintf(local_158,0x128,"%s/../devtype",param_4);
    }
  }
  else {
    snprintf(local_158,0x128,"%s/device/devtype",param_4);
  }
  lVar2 = FUN_00277243(local_158,local_1d8,0x80,param_2);
  if ((0 < lVar2) && (iVar1 = strncmp(local_1d8,"nd_",3), iVar1 == 0)) {
    local_10 = 1;
  }
  snprintf(local_158,0x128,"%s/dev",param_4);
  lVar2 = FUN_00277243(local_158,local_1d8,0x80,param_2);
  if ((0 < lVar2) && (iVar1 = sscanf(local_1d8,"%u:%u",&local_31c,&local_320), iVar1 == 2)) {
    local_20 = strchr(local_1d8,10);
    if (local_20 != (char *)0x0) {
      *local_20 = '\0';
    }
    FUN_0024dfb5(param_3,"LinuxDeviceID",local_1d8);
    snprintf(local_158,0x128,"/run/udev/data/b%u:%u",(ulong)local_31c,(ulong)local_320);
    local_28 = (FILE *)FUN_0027716f(local_158,&DAT_002f19cb,param_2);
    if (local_28 != (FILE *)0x0) {
      while (pcVar4 = fgets(local_1d8,0x80,local_28), pcVar4 != (char *)0x0) {
        local_20 = strchr(local_1d8,10);
        if (local_20 != (char *)0x0) {
          *local_20 = '\0';
        }
        iVar1 = strncmp(local_1d8,"E:ID_VENDOR=",0xc);
        if (iVar1 == 0) {
          strncpy((char *)local_218,acStack_1cc,0x40);
          local_218[7] = local_218[7] & 0xffffffffffffff;
        }
        else {
          iVar1 = strncmp(local_1d8,"E:ID_MODEL=",0xb);
          if (iVar1 == 0) {
            strncpy(local_258,&cStack_1cd,0x40);
            local_220 = local_220 & 0xffffffffffffff;
          }
          else {
            iVar1 = strncmp(local_1d8,"E:ID_REVISION=",0xe);
            if (iVar1 == 0) {
              strncpy(local_2d8,acStack_1ca,0x40);
              local_2a0 = local_2a0 & 0xffffffffffffff;
            }
            else {
              iVar1 = strncmp(local_1d8,"E:ID_SERIAL_SHORT=",0x12);
              if (iVar1 == 0) {
                strncpy(local_298,acStack_1c6,0x40);
                local_260 = local_260 & 0xffffffffffffff;
              }
              else {
                iVar1 = strncmp(local_1d8,"E:ID_TYPE=",10);
                if (iVar1 == 0) {
                  strncpy(local_318,&cStack_1ce,0x40);
                  local_2e0 = local_2e0 & 0xffffffffffffff;
                }
              }
            }
          }
        }
      }
      fclose(local_28);
    }
  }
  iVar1 = strcasecmp((char *)local_218,"ATA");
  if (iVar1 == 0) {
    local_218[0] = local_218[0] & 0xffffffffffffff00;
  }
  if ((char)local_218[0] == '\0') {
    iVar1 = strncasecmp(local_258,"wd",2);
    if (iVar1 == 0) {
      local_218[0] = 0x206e726574736557;
      local_218[1] = 0x6c617469676944;
    }
    else {
      iVar1 = strncasecmp(local_258,"st",2);
      if (iVar1 == 0) {
        local_218[0] = 0x65746167616553;
      }
      else {
        iVar1 = strncasecmp(local_258,"samsung",7);
        if (iVar1 == 0) {
          local_218[0] = 0x676e75736d6153;
        }
        else {
          iVar1 = strncasecmp(local_258,"sandisk",7);
          if (iVar1 == 0) {
            local_218[0] = 0x6b7369446e6153;
          }
          else {
            iVar1 = strncasecmp(local_258,"toshiba",7);
            if (iVar1 == 0) {
              local_218[0] = 0x61626968736f54;
            }
          }
        }
      }
    }
  }
  if ((char)local_218[0] != '\0') {
    FUN_0024dfb5(param_3,"Vendor",local_218);
  }
  if (local_258[0] != '\0') {
    FUN_0024dfb5(param_3,"Model",local_258);
  }
  if (local_2d8[0] != '\0') {
    FUN_0024dfb5(param_3,"Revision",local_2d8);
  }
  if (local_298[0] != '\0') {
    FUN_0024dfb5(param_3,"SerialNumber",local_298);
  }
  local_30 = (char *)FUN_00276b27(param_3,"DAXType");
  if (local_30 == (char *)0x0) {
    if (local_10 == 0) {
      iVar1 = strcmp(local_318,"disk");
      if ((iVar1 == 0) || (iVar1 = strncmp(*(char **)(param_3 + 0x18),"nvme",4), iVar1 == 0)) {
        pcVar4 = strdup("Disk");
        *(char **)(param_3 + 8) = pcVar4;
      }
      else {
        iVar1 = strcmp(local_318,"tape");
        if (iVar1 == 0) {
          pcVar4 = strdup("Tape");
          *(char **)(param_3 + 8) = pcVar4;
        }
        else {
          iVar1 = strcmp(local_318,"cd");
          if (((iVar1 == 0) || (iVar1 = strcmp(local_318,"floppy"), iVar1 == 0)) ||
             (iVar1 = strcmp(local_318,"optical"), iVar1 == 0)) {
            pcVar4 = strdup("Removable Media Device");
            *(char **)(param_3 + 8) = pcVar4;
          }
        }
      }
    }
    else {
      pcVar4 = strdup("NVM");
      *(char **)(param_3 + 8) = pcVar4;
    }
  }
  else {
    pcVar4 = strdup(local_30);
    *(char **)(param_3 + 8) = pcVar4;
  }
  return;
}


// ===== 00284e8c FUN_00284e8c =====

undefined8 FUN_00284e8c(long param_1,uint param_2)

{
  int iVar1;
  undefined1 local_1d8 [144];
  char local_148 [264];
  undefined8 local_40;
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/block",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          ((local_2c = snprintf(local_148,0x100,"/sys/class/block/%s/partition",local_28->d_name),
           0xff < local_2c || (iVar1 = FUN_002771c2(local_148,local_1d8,local_14), iVar1 < 0)))) &&
         ((local_2c = snprintf(local_148,0x100,"/sys/class/block/%s",local_28->d_name),
          local_2c < 0x100 &&
          (local_38 = FUN_00284038(param_1,local_14,local_148,param_2 | 4), local_38 != 0)))) {
        local_40 = FUN_00284364(param_1,local_38,0,local_28->d_name);
        FUN_002843e2(param_1,local_14,local_40,local_148,param_2 | 4);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 00285072 FUN_00285072 =====

undefined8 FUN_00285072(long param_1,uint param_2)

{
  int iVar1;
  char local_168 [304];
  undefined8 local_38;
  long local_30;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/bus/dax/devices",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if (((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
         (iVar1 = FUN_0027e43c(local_28->d_name,local_14), iVar1 == 0)) {
        snprintf(local_168,300,"/sys/bus/dax/devices/%s",local_28->d_name);
        local_30 = FUN_00284038(param_1,local_14,local_168,param_2 | 0xc0000000);
        if (local_30 != 0) {
          local_38 = FUN_00284364(param_1,local_30,0,local_28->d_name);
          FUN_0027e4a7(local_38,local_28->d_name,local_14);
          FUN_002843e2(param_1,local_14,local_38,local_168,param_2 | 0xc0000000);
        }
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 00285224 FUN_00285224 =====

void FUN_00285224(undefined4 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  char local_298 [24];
  char *local_280;
  char local_278 [16];
  char local_268 [128];
  char local_1e8 [304];
  undefined1 local_b8 [152];
  ulong local_20;
  char *local_18;
  int local_c;
  
  snprintf(local_1e8,0x128,"%s/address",param_3);
  lVar2 = FUN_00277243(local_1e8,local_268,0x80,param_1);
  if (0 < lVar2) {
    local_18 = strchr(local_268,10);
    if (local_18 != (char *)0x0) {
      *local_18 = '\0';
    }
    FUN_0024dfb5(param_2,"Address",local_268);
  }
  snprintf(local_1e8,0x128,"%s/device/infiniband",param_3);
  iVar1 = FUN_002771c2(local_1e8,local_b8,param_1);
  if (iVar1 == 0) {
    snprintf(local_1e8,0x128,"%s/dev_port",param_3);
    local_c = FUN_00277243(local_1e8,local_278,0x10,param_1);
    if (local_c < 0) {
      snprintf(local_1e8,0x128,"%s/dev_id",param_3);
      local_c = FUN_00277243(local_1e8,local_278,0x10,param_1);
    }
    if (0 < local_c) {
      local_20 = strtoul(local_278,&local_280,0);
      if (local_280 != local_278) {
        snprintf(local_298,0x15,"%lu",local_20 + 1);
        FUN_0024dfb5(param_2,&DAT_002f4662,local_298);
      }
    }
  }
  iVar1 = strncmp(*(char **)(param_2 + 0x18),"hsn",3);
  if (iVar1 == 0) {
    snprintf(local_1e8,0x128,"%s/device/cxi",param_3);
    iVar1 = FUN_0027719a(local_1e8,5,param_1);
    if (iVar1 == 0) {
      pcVar3 = strdup("Slingshot");
      *(char **)(param_2 + 8) = pcVar3;
    }
  }
  return;
}


// ===== 002854da FUN_002854da =====

undefined8 FUN_002854da(long param_1,undefined4 param_2)

{
  int iVar1;
  char local_148 [264];
  undefined8 local_40;
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/net",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          (local_2c = snprintf(local_148,0x100,"/sys/class/net/%s",local_28->d_name),
          local_2c < 0x100)) &&
         (local_38 = FUN_00284038(param_1,local_14,local_148,param_2), local_38 != 0)) {
        local_40 = FUN_00284364(param_1,local_38,2,local_28->d_name);
        FUN_00285224(local_14,local_40,local_148);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 0028564b FUN_0028564b =====

void FUN_0028564b(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  char local_1e8 [32];
  char local_1c8 [20];
  char acStack_1b4 [31];
  char local_195 [11];
  undefined1 local_18a;
  undefined1 local_189;
  char local_188 [32];
  char local_168 [304];
  size_t local_38;
  size_t local_30;
  size_t local_28;
  size_t local_20;
  size_t local_18;
  uint local_10;
  uint local_c;
  
  snprintf(local_168,0x128,"%s/node_guid",param_3);
  lVar2 = FUN_00277243(local_168,local_188,0x14,param_1);
  if (0 < lVar2) {
    local_18 = strspn(local_188,"0123456789abcdefx:");
    local_188[local_18] = '\0';
    FUN_0024dfb5(param_2,"NodeGUID",local_188);
  }
  snprintf(local_168,0x128,"%s/sys_image_guid",param_3);
  lVar2 = FUN_00277243(local_168,local_188,0x14,param_1);
  if (0 < lVar2) {
    local_20 = strspn(local_188,"0123456789abcdefx:");
    local_188[local_20] = '\0';
    FUN_0024dfb5(param_2,"SysImageGUID",local_188);
  }
  local_c = 1;
  while( true ) {
    snprintf(local_168,0x128,"%s/ports/%u/state",param_3,(ulong)local_c);
    lVar2 = FUN_00277243(local_168,&local_18a,2,param_1);
    if (lVar2 < 1) break;
    local_189 = 0;
    snprintf(local_1c8,0x20,"Port%uState",(ulong)local_c);
    FUN_0024dfb5(param_2,local_1c8,&local_18a);
    snprintf(local_168,0x128,"%s/ports/%u/lid",param_3,(ulong)local_c);
    lVar2 = FUN_00277243(local_168,local_195,0xb,param_1);
    if (0 < lVar2) {
      local_28 = strspn(local_195,"0123456789abcdefx");
      local_195[local_28] = '\0';
      snprintf(local_1c8,0x20,"Port%uLID",(ulong)local_c);
      FUN_0024dfb5(param_2,local_1c8,local_195);
    }
    snprintf(local_168,0x128,"%s/ports/%u/lid_mask_count",param_3,(ulong)local_c);
    lVar2 = FUN_00277243(local_168,local_195,0xb,param_1);
    if (0 < lVar2) {
      local_30 = strspn(local_195,"0123456789");
      local_195[local_30] = '\0';
      snprintf(local_1c8,0x20,"Port%uLMC",(ulong)local_c);
      FUN_0024dfb5(param_2,local_1c8,local_195);
    }
    local_10 = 0;
    while( true ) {
      snprintf(local_168,0x128,"%s/ports/%u/gids/%u",param_3,(ulong)local_c,(ulong)local_10);
      lVar2 = FUN_00277243(local_168,local_1c8,0x28,param_1);
      if (lVar2 < 1) break;
      local_38 = strspn(local_1c8,"0123456789abcdefx:");
      local_1c8[local_38] = '\0';
      iVar1 = strncmp(acStack_1b4,"0000:0000:0000:0000",0x13);
      if (iVar1 != 0) {
        snprintf(local_1e8,0x20,"Port%uGID%u",(ulong)local_c,(ulong)local_10);
        FUN_0024dfb5(param_2,local_1e8,local_1c8);
      }
      local_10 = local_10 + 1;
    }
    local_c = local_c + 1;
  }
  return;
}


// ===== 00285af5 FUN_00285af5 =====

undefined8 FUN_00285af5(long param_1,undefined4 param_2)

{
  int iVar1;
  char local_148 [264];
  undefined8 local_40;
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/infiniband",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          (iVar1 = strncmp(local_28->d_name,"scif",4), iVar1 != 0)) &&
         ((local_2c = snprintf(local_148,0x100,"/sys/class/infiniband/%s",local_28->d_name),
          local_2c < 0x101 &&
          (local_38 = FUN_00284038(param_1,local_14,local_148,param_2), local_38 != 0)))) {
        local_40 = FUN_00284364(param_1,local_38,3,local_28->d_name);
        FUN_0028564b(local_14,local_40,local_148);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 00285c8d FUN_00285c8d =====

void FUN_00285c8d(undefined4 param_1,long param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  char local_178 [64];
  char local_138 [296];
  char *local_10;
  
  pcVar1 = strdup("BXI");
  *(char **)(param_2 + 8) = pcVar1;
  snprintf(local_138,0x128,"%s/uuid",param_3);
  lVar2 = FUN_00277243(local_138,local_178,0x40,param_1);
  if (0 < lVar2) {
    local_10 = strchr(local_178,10);
    if (local_10 != (char *)0x0) {
      *local_10 = '\0';
    }
    FUN_0024dfb5(param_2,"BXIUUID",local_178);
  }
  return;
}


// ===== 00285d5e FUN_00285d5e =====

undefined8 FUN_00285d5e(long param_1,undefined4 param_2)

{
  int iVar1;
  char local_148 [264];
  undefined8 local_40;
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/bxi",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          (local_2c = snprintf(local_148,0x100,"/sys/class/bxi/%s",local_28->d_name),
          local_2c < 0x101)) &&
         (local_38 = FUN_00284038(param_1,local_14,local_148,param_2), local_38 != 0)) {
        local_40 = FUN_00284364(param_1,local_38,3,local_28->d_name);
        FUN_00285c8d(local_14,local_40,local_148);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 00285ecf FUN_00285ecf =====

void FUN_00285ecf(undefined4 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  uint local_1ac;
  char local_1a8 [64];
  char local_168 [296];
  size_t local_40;
  size_t local_38;
  size_t local_30;
  size_t local_28;
  size_t local_20;
  char *local_18;
  char *local_10;
  
  pcVar2 = strdup("VectorEngine");
  *(char **)(param_2 + 8) = pcVar2;
  snprintf(local_168,0x128,"%s/model",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_10 = strchr(local_1a8,10);
    if (local_10 != (char *)0x0) {
      *local_10 = '\0';
    }
    FUN_0024dfb5(param_2,"VectorEngineModel",local_1a8);
  }
  snprintf(local_168,0x128,"%s/serial",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_18 = strchr(local_1a8,10);
    if (local_18 != (char *)0x0) {
      *local_18 = '\0';
    }
    FUN_0024dfb5(param_2,"VectorEngineSerialNumber",local_1a8);
  }
  snprintf(local_168,0x128,"%s/partitioning_mode",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    iVar1 = atoi(local_1a8);
    if (0 < iVar1) {
      FUN_0024dfb5(param_2,"VectorEngineNUMAPartitioned",&DAT_002f295a);
    }
  }
  snprintf(local_168,0x128,"%s/num_of_core",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_20 = strspn(local_1a8,"0123456789");
    local_1a8[local_20] = '\0';
    FUN_0024dfb5(param_2,"VectorEngineCores",local_1a8);
  }
  snprintf(local_168,0x128,"%s/memory_size",param_3);
  iVar1 = FUN_0027731c(local_168,&local_1ac,param_1);
  if (iVar1 == 0) {
    snprintf(local_1a8,0x40,"%llu",(ulong)local_1ac << 0x14);
    FUN_0024dfb5(param_2,"VectorEngineMemorySize",local_1a8);
  }
  snprintf(local_168,0x128,"%s/cache_llc",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_28 = strspn(local_1a8,"0123456789");
    local_1a8[local_28] = '\0';
    FUN_0024dfb5(param_2,"VectorEngineLLCSize",local_1a8);
  }
  snprintf(local_168,0x128,"%s/cache_l2",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_30 = strspn(local_1a8,"0123456789");
    local_1a8[local_30] = '\0';
    FUN_0024dfb5(param_2,"VectorEngineL2Size",local_1a8);
  }
  snprintf(local_168,0x128,"%s/cache_l1d",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_38 = strspn(local_1a8,"0123456789");
    local_1a8[local_38] = '\0';
    FUN_0024dfb5(param_2,"VectorEngineL1dSize",local_1a8);
  }
  snprintf(local_168,0x128,"%s/cache_l1i",param_3);
  lVar3 = FUN_00277243(local_168,local_1a8,0x40,param_1);
  if (0 < lVar3) {
    local_40 = strspn(local_1a8,"0123456789");
    local_1a8[local_40] = '\0';
    FUN_0024dfb5(param_2,"VectorEngineL1iSize",local_1a8);
  }
  return;
}


// ===== 00286455 FUN_00286455 =====

undefined8 FUN_00286455(long param_1,undefined4 param_2)

{
  int iVar1;
  char local_148 [264];
  undefined8 local_40;
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/ve",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          (local_2c = snprintf(local_148,0x100,"/sys/class/ve/%s",local_28->d_name),
          local_2c < 0x101)) &&
         (local_38 = FUN_00284038(param_1,local_14,local_148,param_2), local_38 != 0)) {
        local_40 = FUN_00284364(param_1,local_38,5,local_28->d_name);
        FUN_00285ecf(local_14,local_40,local_148);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 002865c6 FUN_002865c6 =====

undefined8 FUN_002865c6(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_1c8 [144];
  char local_138 [256];
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/drm",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          ((local_2c = snprintf(local_138,0x100,"/sys/class/drm/%s/dev",local_28->d_name),
           0xff < local_2c || (iVar1 = FUN_002771c2(local_138,local_1c8,local_14), -1 < iVar1)))) &&
         ((local_2c = snprintf(local_138,0x100,"/sys/class/drm/%s",local_28->d_name),
          local_2c < 0x100 &&
          (local_38 = FUN_00284038(param_1,local_14,local_138,param_2), local_38 != 0)))) {
        FUN_00284364(param_1,local_38,1,local_28->d_name);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 0028677a FUN_0028677a =====

undefined8 FUN_0028677a(long param_1,undefined4 param_2)

{
  int iVar1;
  char local_138 [256];
  long local_38;
  uint local_2c;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/class/dma",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strcmp(local_28->d_name,".");
      if ((((iVar1 != 0) && (iVar1 = strcmp(local_28->d_name,".."), iVar1 != 0)) &&
          (local_2c = snprintf(local_138,0x100,"/sys/class/dma/%s",local_28->d_name),
          local_2c < 0x100)) &&
         (local_38 = FUN_00284038(param_1,local_14,local_138,param_2), local_38 != 0)) {
        FUN_00284364(param_1,local_38,4,local_28->d_name);
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 002868cf FUN_002868cf =====

void FUN_002868cf(undefined4 param_1,long param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  char local_198 [64];
  char local_158 [320];
  ulonglong local_18;
  ulonglong local_10;
  
  pcVar1 = strdup("CXLMem");
  *(char **)(param_2 + 8) = pcVar1;
  snprintf(local_158,0x136,"%s/ram/size",param_3);
  lVar2 = FUN_00277243(local_158,local_198,0x40,param_1);
  if (0 < lVar2) {
    local_10 = strtoull(local_198,(char **)0x0,0);
    if (local_10 != 0) {
      snprintf(local_198,0x40,"%llu",local_10 >> 10);
      FUN_0024dfb5(param_2,"CXLRAMSize",local_198);
    }
  }
  snprintf(local_158,0x136,"%s/pmem/size",param_3);
  lVar2 = FUN_00277243(local_158,local_198,0x40,param_1);
  if (0 < lVar2) {
    local_18 = strtoull(local_198,(char **)0x0,0);
    if (local_18 != 0) {
      snprintf(local_198,0x40,"%llu",local_18 >> 10);
      FUN_0024dfb5(param_2,"CXLPMEMSize",local_198);
    }
  }
  return;
}


// ===== 00286a8d FUN_00286a8d =====

undefined8 FUN_00286a8d(long param_1,uint param_2)

{
  int iVar1;
  char local_168 [304];
  undefined8 local_38;
  long local_30;
  dirent *local_28;
  DIR *local_20;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x38);
  local_14 = *(undefined4 *)(local_10 + 8);
  local_20 = (DIR *)FUN_002771f1("/sys/bus/cxl/devices",local_14);
  if (local_20 != (DIR *)0x0) {
    while (local_28 = readdir(local_20), local_28 != (dirent *)0x0) {
      iVar1 = strncmp(local_28->d_name,"mem",3);
      if (iVar1 == 0) {
        snprintf(local_168,300,"/sys/bus/cxl/devices/%s",local_28->d_name);
        local_30 = FUN_00284038(param_1,local_14,local_168,param_2 | 0xc0000000);
        if (local_30 != 0) {
          local_38 = FUN_00284364(param_1,local_30,0,local_28->d_name);
          FUN_002868cf(local_14,local_38,local_168);
        }
      }
    }
    closedir(local_20);
  }
  return 0;
}


// ===== 00286bd6 FUN_00286bd6 =====

undefined8 FUN_00286bd6(char *param_1)

{
  undefined8 uVar1;
  size_t sVar2;
  size_t sVar3;
  
  if (*param_1 == '\0') {
    uVar1 = 0;
  }
  else {
    sVar2 = strspn(param_1," ");
    sVar3 = strlen(param_1);
    if (sVar2 == sVar3) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ===== 00286c2f FUN_00286c2f =====

undefined8
FUN_00286c2f(undefined8 param_1,undefined4 param_2,undefined8 param_3,FILE *param_4,long param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  undefined8 uVar4;
  undefined4 local_134;
  undefined8 local_130;
  char local_128 [256];
  long local_28;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_130 = 0;
  local_134 = 0;
  local_18 = 0;
  local_c = (uint)*(byte *)(param_5 + 1);
  local_14 = 1;
  while( true ) {
    iVar1 = fseek(param_4,(ulong)local_c,0);
    if ((iVar1 < 0) || (pcVar2 = fgets(local_128,0x100,param_4), pcVar2 == (char *)0x0))
    goto LAB_00286fe5;
    local_10 = 0;
    while( true ) {
      if (local_128[local_10] == '\0') goto LAB_00286fe5;
      sVar3 = strlen(local_128 + local_10);
      local_1c = (int)sVar3;
      if (local_1c + local_10 == 0xff) break;
      if (local_14 == *(byte *)(param_5 + 0x17)) {
        iVar1 = FUN_00286bd6(local_128 + local_10);
        if (iVar1 != 0) {
          FUN_0024dbec(&local_130,&local_134,"Vendor",local_128 + local_10);
          local_18 = 1;
        }
      }
      else if (local_14 == *(byte *)(param_5 + 0x18)) {
        iVar1 = FUN_00286bd6(local_128 + local_10);
        if (iVar1 != 0) {
          FUN_0024dbec(&local_130,&local_134,"SerialNumber",local_128 + local_10);
          local_18 = 1;
        }
      }
      else if (local_14 == *(byte *)(param_5 + 0x19)) {
        iVar1 = FUN_00286bd6(local_128 + local_10);
        if (iVar1 != 0) {
          FUN_0024dbec(&local_130,&local_134,"AssetTag",local_128 + local_10);
          local_18 = 1;
        }
      }
      else if (local_14 == *(byte *)(param_5 + 0x1a)) {
        iVar1 = FUN_00286bd6(local_128 + local_10);
        if (iVar1 != 0) {
          FUN_0024dbec(&local_130,&local_134,"PartNumber",local_128 + local_10);
          local_18 = 1;
        }
      }
      else if (local_14 == *(byte *)(param_5 + 0x10)) {
        iVar1 = FUN_00286bd6(local_128 + local_10);
        if (iVar1 != 0) {
          FUN_0024dbec(&local_130,&local_134,"DeviceLocation",local_128 + local_10);
        }
      }
      else {
        if (local_14 != *(byte *)(param_5 + 0x11)) goto LAB_00286fe5;
        iVar1 = FUN_00286bd6(local_128 + local_10);
        if (iVar1 != 0) {
          FUN_0024dbec(&local_130,&local_134,"BankLocation",local_128 + local_10);
        }
      }
      local_10 = local_10 + local_1c + 1;
      local_14 = local_14 + 1;
    }
    if (local_10 == 0) break;
    local_c = local_c + local_10;
  }
  iVar1 = FUN_0024d64f();
  if (iVar1 < 2) {
    fprintf(*(FILE **)PTR_stderr_0032efe0,
            "hwloc/linux: hwloc could read a DMI firmware entry #%u in %s\n",(ulong)local_14,param_3
           );
  }
LAB_00286fe5:
  if ((local_18 == 0) || (local_28 = FUN_0024febd(param_1,0x11,param_2), local_28 == 0)) {
    FUN_0024db80(local_130,local_134);
    uVar4 = 0;
  }
  else {
    pcVar2 = strdup("MemoryModule");
    *(char **)(local_28 + 8) = pcVar2;
    FUN_0024de0e(local_28 + 0xd8,local_28 + 0xe0,&local_130,&local_134);
    uVar4 = FUN_00276b03(param_1);
    FUN_0024fc99(param_1,uVar4,local_28);
    uVar4 = 1;
  }
  return uVar4;
}


// ===== 002870ab FUN_002870ab =====

undefined8 FUN_002870ab(undefined8 param_1,long param_2)

{
  size_t sVar1;
  undefined1 local_c8;
  byte local_c7;
  char local_a8 [140];
  int local_1c;
  FILE *local_18;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    snprintf(local_a8,0x80,"/sys/firmware/dmi/entries/17-%u/raw",(ulong)local_c);
    local_18 = (FILE *)FUN_0027716f(local_a8,&DAT_002f19cb,*(undefined4 *)(param_2 + 8));
    if (local_18 == (FILE *)0x0) {
      return 0;
    }
    sVar1 = fread(&local_c8,0x1b,1,local_18);
    local_1c = (int)sVar1;
    if (local_1c != 1) break;
    if (local_c7 < 0x1b) {
      fclose(local_18);
      return 0;
    }
    FUN_00286c2f(param_1,local_c,local_a8,local_18,&local_c8);
    fclose(local_18);
    local_c = local_c + 1;
  }
  fclose(local_18);
  return 0;
}


// ===== 002871b3 FUN_002871b3 =====

/* WARNING: Removing unreachable block (ram,0x002878ad) */

undefined8 FUN_002871b3(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  char local_1e8 [64];
  undefined1 local_1a8 [8];
  undefined1 local_1a0;
  int local_a0;
  int local_9c;
  char local_98 [16];
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  uint local_74;
  undefined8 local_70;
  int local_64;
  long local_60;
  undefined2 *local_58;
  long local_50;
  int local_48;
  uint local_44;
  dirent *local_40;
  DIR *local_38;
  undefined4 local_2c;
  undefined8 local_28;
  long local_20;
  uint local_14;
  float local_10;
  undefined2 local_a;
  
  local_20 = *(long *)(param_1 + 0x38);
  local_28 = *(undefined8 *)(param_1 + 8);
  local_70 = 0;
  local_2c = *(undefined4 *)(local_20 + 8);
  local_38 = (DIR *)FUN_002771f1("/sys/bus/pci/devices/",local_2c);
  if (local_38 != (DIR *)0x0) {
LAB_002878fb:
    local_40 = readdir(local_38);
    if (local_40 != (dirent *)0x0) {
      iVar1 = sscanf(local_40->d_name,"%x:%02x:%02x.%01x",&local_74,&local_78,&local_7c,&local_80);
      if (iVar1 == 4) {
        if (0xffff < local_74) {
          if ((DAT_0121839c == 0) && (iVar1 = FUN_0024d64f(), iVar1 == 0)) {
            fwrite("hwloc/linux: Ignoring PCI device with non-16bit domain.\nPass --enable-32bits-pci-domain to configure to support such devices\n(warning: it would break the library ABI, don\'t enable unless really needed).\n"
                   ,1,0xcb,*(FILE **)PTR_stderr_0032efe0);
          }
          DAT_0121839c = 1;
          goto LAB_002878fb;
        }
        memset(local_1a8,0xff,0x100);
        local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/config",local_40->d_name);
        if (local_44 < 0x40) {
          FUN_00277243(local_1e8,local_1a8,0x101,local_2c);
        }
        local_a = 0;
        local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/class",local_40->d_name);
        if ((local_44 < 0x40) && (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)
           ) {
          uVar3 = strtoul(local_98,(char **)0x0,0x10);
          local_a = (undefined2)(uVar3 >> 8);
        }
        local_48 = FUN_002652c0(local_a,local_1a8);
        if ((local_48 != 0xe) ||
           (iVar1 = FUN_00265300(local_74,local_78,local_7c,local_80,local_84,local_88,local_1a8),
           -1 < iVar1)) {
          if (local_48 == 0xf) {
            FUN_002543c3(local_28,0xf,&local_9c);
            if ((local_9c == 1) || ((local_9c == 3 && (iVar1 = FUN_00276c84(local_a), iVar1 == 0))))
            goto LAB_002878fb;
          }
          else if ((local_48 == 0xe) && (FUN_002543c3(local_28,0xe,&local_a0), local_a0 == 1))
          goto LAB_002878fb;
          local_50 = FUN_0024febd(local_28,local_48,0xffffffff);
          if (local_50 == 0) goto LAB_00287919;
          local_58 = *(undefined2 **)(local_50 + 0x28);
          *local_58 = (short)local_74;
          *(char *)(local_58 + 1) = (char)local_78;
          *(char *)((long)local_58 + 3) = (char)local_7c;
          *(char *)(local_58 + 2) = (char)local_80;
          if (local_48 == 0xe) {
            local_60 = *(long *)(local_50 + 0x28);
            *(undefined4 *)(local_60 + 0x18) = 1;
            *(undefined4 *)(local_60 + 0x20) = 1;
            *(short *)(local_60 + 0x1c) = (short)local_74;
            *(char *)(local_60 + 0x1e) = local_84[0];
            *(char *)(local_60 + 0x1f) = local_88[0];
          }
          local_58[4] = 0;
          local_58[5] = 0;
          local_58[3] = local_a;
          *(undefined1 *)(local_58 + 8) = 0;
          local_58[6] = 0;
          local_58[7] = 0;
          *(undefined4 *)(local_58 + 10) = 0;
          local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/vendor",local_40->d_name);
          if ((local_44 < 0x40) &&
             (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)) {
            uVar3 = strtoul(local_98,(char **)0x0,0x10);
            local_58[4] = (short)uVar3;
          }
          local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/device",local_40->d_name);
          if ((local_44 < 0x40) &&
             (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)) {
            uVar3 = strtoul(local_98,(char **)0x0,0x10);
            local_58[5] = (short)uVar3;
          }
          local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/subsystem_vendor",
                              local_40->d_name);
          if ((local_44 < 0x40) &&
             (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)) {
            uVar3 = strtoul(local_98,(char **)0x0,0x10);
            local_58[6] = (short)uVar3;
          }
          local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/subsystem_device",
                              local_40->d_name);
          if ((local_44 < 0x40) &&
             (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)) {
            uVar3 = strtoul(local_98,(char **)0x0,0x10);
            local_58[7] = (short)uVar3;
          }
          *(undefined1 *)(local_58 + 8) = local_1a0;
          local_64 = FUN_00265093(local_1a8,0x10);
          if ((local_64 == 0) || (0x100 < local_64 + 0x14U)) {
            local_10 = 0.0;
            local_14 = 0;
            local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/current_link_speed",
                                local_40->d_name);
            if ((local_44 < 0x40) &&
               (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)) {
              local_10 = (float)FUN_00276bdd(local_98);
            }
            local_44 = snprintf(local_1e8,0x40,"/sys/bus/pci/devices/%s/current_link_width",
                                local_40->d_name);
            if ((local_44 < 0x40) &&
               (lVar2 = FUN_00277243(local_1e8,local_98,0x10,local_2c), 0 < lVar2)) {
              local_14 = atoi(local_98);
            }
            *(float *)(local_58 + 10) = ((float)local_14 * local_10) / DAT_002f4dbc;
          }
          else {
            FUN_00265174(local_1a8,local_64,local_58 + 10);
          }
          FUN_00263e31(&local_70,local_50);
        }
      }
      goto LAB_002878fb;
    }
LAB_00287919:
    closedir(local_38);
    FUN_002647ed(*(undefined8 *)(param_1 + 8),local_70);
  }
  return 0;
}


// ===== 00287946 FUN_00287946 =====

undefined8 FUN_00287946(long param_1)

{
  int iVar1;
  long lVar2;
  char local_c8 [64];
  char local_88 [64];
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  dirent *local_38;
  DIR *local_30;
  undefined4 local_24;
  long local_20;
  undefined8 local_18;
  int *local_10;
  
  local_18 = *(undefined8 *)(param_1 + 8);
  local_20 = *(long *)(param_1 + 0x38);
  local_24 = *(undefined4 *)(local_20 + 8);
  local_30 = (DIR *)FUN_002771f1("/sys/bus/pci/slots/",local_24);
  if (local_30 != (DIR *)0x0) {
    while (local_38 = readdir(local_30), local_38 != (dirent *)0x0) {
      if ((((local_38->d_name[0] != '.') &&
           (local_3c = snprintf(local_c8,0x40,"/sys/bus/pci/slots/%s/address",local_38->d_name),
           local_3c < 0x40)) && (lVar2 = FUN_00277243(local_c8,local_88,0x40,local_24), 0 < lVar2))
         && (iVar1 = sscanf(local_88,"%x:%x:%x",&local_40,&local_44,&local_48), iVar1 == 3)) {
        local_10 = (int *)FUN_00264e51(local_18,local_40,local_44,local_48,0);
        while (((local_10 != (int *)0x0 &&
                (((*local_10 == 0xf ||
                  ((*local_10 == 0xe && (*(int *)(*(long *)(local_10 + 10) + 0x18) == 1)))) &&
                 (**(ushort **)(local_10 + 10) == local_40)))) &&
               ((*(byte *)(*(long *)(local_10 + 10) + 2) == local_44 &&
                (*(byte *)(*(long *)(local_10 + 10) + 3) == local_48))))) {
          FUN_0024dfb5(local_10,"PCISlot",local_38->d_name);
          local_10 = *(int **)(local_10 + 0x16);
        }
      }
    }
    closedir(local_30);
  }
  return 0;
}


// ===== 00287b35 FUN_00287b35 =====

undefined8 FUN_00287b35(long param_1,int *param_2)

{
  char *pcVar1;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined8 local_18;
  uint local_c;
  
  local_18 = *(undefined8 *)(param_1 + 8);
  if (*param_2 == 2) {
    FUN_0028379b(param_1,param_2);
  }
  else {
    FUN_002543c3(local_18,0xf,&local_1c);
    FUN_002543c3(local_18,0xe,&local_20);
    FUN_002543c3(local_18,0x10,&local_24);
    FUN_002543c3(local_18,0x11,&local_28);
    if ((*param_2 == 8) && ((local_20 != 1 || (local_1c != 1)))) {
      FUN_002871b3(param_1);
      param_2[1] = param_2[1] | 8;
    }
    if ((*param_2 == 0x40) && ((local_20 != 1 || (local_1c != 1)))) {
      FUN_00287946(param_1);
    }
    if ((*param_2 == 0x10) && (local_24 != 1)) {
      local_c = 0;
      pcVar1 = getenv("HWLOC_VIRTUAL_LINUX_OSDEV");
      if (pcVar1 != (char *)0x0) {
        local_c = local_c | 1;
      }
      if (local_24 == 0) {
        local_c = local_c | 2;
      }
      FUN_00284e8c(param_1,local_c);
      FUN_00285072(param_1,local_c);
      FUN_002854da(param_1,local_c);
      FUN_00285af5(param_1,local_c);
      FUN_00286455(param_1,local_c);
      FUN_00285d5e(param_1,local_c);
      FUN_00286a8d(param_1,local_c);
      if (local_24 != 3) {
        FUN_002865c6(param_1,local_c);
        FUN_0028677a(param_1,local_c);
      }
    }
    if ((*param_2 == 0x20) && (local_28 != 1)) {
      FUN_002870ab(local_18,*(undefined8 *)(param_1 + 0x38));
    }
  }
  return 0;
}


// ===== 00287d42 FUN_00287d42 =====

void FUN_00287d42(long param_1)

{
  undefined8 *__ptr;
  
  __ptr = *(undefined8 **)(param_1 + 0x38);
  if (-1 < *(int *)(__ptr + 1)) {
    free((void *)*__ptr);
    close(*(int *)(__ptr + 1));
  }
  free(__ptr);
  return;
}


// ===== 00287d91 FUN_00287d91 =====

void * FUN_00287d91(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  void *__ptr;
  undefined8 *__ptr_00;
  int *piVar3;
  char *pcVar4;
  int local_14;
  char *local_10;
  
  local_14 = -1;
  __ptr = (void *)FUN_0025f967(param_1,param_2);
  if (__ptr != (void *)0x0) {
    __ptr_00 = malloc(0x1c0);
    if (__ptr_00 == (undefined8 *)0x0) {
      piVar3 = __errno_location();
      *piVar3 = 0xc;
    }
    else {
      *(undefined8 **)((long)__ptr + 0x38) = __ptr_00;
      *(code **)((long)__ptr + 0x48) = FUN_00287b35;
      *(code **)((long)__ptr + 0x50) = FUN_00283d99;
      *(code **)((long)__ptr + 0x40) = FUN_00287d42;
      *(undefined4 *)(__ptr_00 + 3) = 5;
      *(undefined4 *)((long)__ptr_00 + 0x1c) = 0;
      *(undefined4 *)(__ptr_00 + 4) = 0;
      *(undefined4 *)((long)__ptr_00 + 0xc) = 1;
      *__ptr_00 = 0;
      local_10 = getenv("HWLOC_FSROOT");
      if (local_10 == (char *)0x0) {
        local_10 = "/";
      }
      iVar1 = strcmp(local_10,"/");
      if (iVar1 == 0) {
LAB_00287f53:
        *(int *)(__ptr_00 + 1) = local_14;
        pcVar4 = getenv("HWLOC_DUMPED_HWDATA_DIR");
        __ptr_00[2] = pcVar4;
        if (__ptr_00[2] == 0) {
          __ptr_00[2] = "/hwloc/";
        }
        *(undefined4 *)((long)__ptr_00 + 0x24) = 1;
        *(undefined4 *)(__ptr_00 + 5) = 1;
        *(undefined4 *)((long)__ptr_00 + 0x2c) = 1;
        pcVar4 = getenv("HWLOC_USE_NUMA_DISTANCES");
        if (pcVar4 == (char *)0x0) {
          return __ptr;
        }
        uVar2 = atoi(pcVar4);
        *(uint *)((long)__ptr_00 + 0x24) = (uint)((uVar2 & 3) != 0);
        *(uint *)(__ptr_00 + 5) = (uint)((uVar2 & 2) != 0);
        *(uint *)((long)__ptr_00 + 0x2c) = (uint)((uVar2 & 4) != 0);
        return __ptr;
      }
      local_14 = open(local_10,0x10000);
      if (-1 < local_14) {
        *(undefined4 *)((long)__ptr + 0x30) = 0;
        *(undefined4 *)((long)__ptr_00 + 0xc) = 0;
        pcVar4 = strdup(local_10);
        *__ptr_00 = pcVar4;
        uVar2 = fcntl(local_14,1,0);
        if ((uVar2 != 0xffffffff) && (iVar1 = fcntl(local_14,2,(ulong)(uVar2 | 1)), iVar1 != -1))
        goto LAB_00287f53;
        close(local_14);
      }
      free((void *)*__ptr_00);
      free(__ptr_00);
    }
    free(__ptr);
  }
  return (void *)0x0;
}


// ===== 0028804e FUN_0028804e =====

bool FUN_0028804e(undefined8 param_1,undefined4 param_2)

{
  int local_c;
  
  local_c = 1;
  FUN_002543c3(param_1,param_2,&local_c);
  if (local_c == 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("filter != HWLOC_TYPE_FILTER_KEEP_IMPORTANT",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/plugins.h"
                  ,0x218,"hwloc_filter_check_keep_object_type");
  }
  return local_c != 1;
}


// ===== 002880ae FUN_002880ae =====

undefined8 FUN_002880ae(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  uint local_c;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    uVar2 = FUN_00260eab();
    FUN_0026197d(uVar2,local_c);
    iVar1 = FUN_0028804e(param_1,9);
    if (iVar1 != 0) {
      lVar3 = FUN_0024febd(param_1,9,0xffffffff);
      uVar4 = FUN_002611e2(uVar2);
      *(undefined8 *)(lVar3 + 0xb8) = uVar4;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 2;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 1;
      **(undefined8 **)(lVar3 + 0x28) = 0x8000;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x80;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 2;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:k:l1icache");
    }
    iVar1 = FUN_0028804e(param_1,4);
    if (iVar1 != 0) {
      lVar3 = FUN_0024febd(param_1,4,0xffffffff);
      uVar4 = FUN_002611e2(uVar2);
      *(undefined8 *)(lVar3 + 0xb8) = uVar4;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 1;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 1;
      **(undefined8 **)(lVar3 + 0x28) = 0x8000;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x80;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 2;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:k:l1dcache");
    }
    iVar1 = FUN_0028804e(param_1,2);
    if (iVar1 == 0) {
      FUN_00260f71(uVar2);
    }
    else {
      lVar3 = FUN_0024febd(param_1,2,local_c);
      *(undefined8 *)(lVar3 + 0xb8) = uVar2;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:k:core");
    }
  }
  uVar2 = FUN_00260eab();
  FUN_00261a1b(uVar2,0,7);
  iVar1 = FUN_0028804e(param_1,5);
  if (iVar1 != 0) {
    lVar3 = FUN_0024febd(param_1,5,0xffffffff);
    uVar4 = FUN_002611e2(uVar2);
    *(undefined8 *)(lVar3 + 0xb8) = uVar4;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 0;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 2;
    **(undefined8 **)(lVar3 + 0x28) = 0x600000;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x80;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 0xc;
    FUN_0024fb45(param_1,0,lVar3,"hardwired:k:l2cache");
  }
  iVar1 = FUN_0028804e(param_1,1);
  if (iVar1 == 0) {
    FUN_00260f71(uVar2);
  }
  else {
    lVar3 = FUN_0024febd(param_1,1,0);
    *(undefined8 *)(lVar3 + 0xb8) = uVar2;
    FUN_0024dfb5(lVar3,"CPUVendor","Fujitsu");
    FUN_0024dfb5(lVar3,"CPUModel","SPARC64 VIIIfx");
    FUN_0024fb45(param_1,0,lVar3,"hardwired:k:package");
  }
  **(undefined1 **)(param_1 + 0x288) = 1;
  FUN_0024dad7(param_1,8);
  return 0;
}


// ===== 00288451 FUN_00288451 =====

undefined8 FUN_00288451(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  uint local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    uVar2 = FUN_00260eab();
    FUN_0026197d(uVar2,local_c);
    iVar1 = FUN_0028804e(param_1,9);
    if (iVar1 != 0) {
      lVar3 = FUN_0024febd(param_1,9,0xffffffff);
      uVar4 = FUN_002611e2(uVar2);
      *(undefined8 *)(lVar3 + 0xb8) = uVar4;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 2;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 1;
      **(undefined8 **)(lVar3 + 0x28) = 0x8000;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x80;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 2;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:fx10:l1icache");
    }
    iVar1 = FUN_0028804e(param_1,4);
    if (iVar1 != 0) {
      lVar3 = FUN_0024febd(param_1,4,0xffffffff);
      uVar4 = FUN_002611e2(uVar2);
      *(undefined8 *)(lVar3 + 0xb8) = uVar4;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 1;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 1;
      **(undefined8 **)(lVar3 + 0x28) = 0x8000;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x80;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 2;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:fx10:l1dcache");
    }
    iVar1 = FUN_0028804e(param_1,2);
    if (iVar1 == 0) {
      FUN_00260f71(uVar2);
    }
    else {
      lVar3 = FUN_0024febd(param_1,2,local_c);
      *(undefined8 *)(lVar3 + 0xb8) = uVar2;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:fx10:core");
    }
  }
  uVar2 = FUN_00260eab();
  FUN_00261a1b(uVar2,0,0xf);
  iVar1 = FUN_0028804e(param_1,5);
  if (iVar1 != 0) {
    lVar3 = FUN_0024febd(param_1,5,0xffffffff);
    uVar4 = FUN_002611e2(uVar2);
    *(undefined8 *)(lVar3 + 0xb8) = uVar4;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 0;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 2;
    **(undefined8 **)(lVar3 + 0x28) = 0xc00000;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x80;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 0x18;
    FUN_0024fb45(param_1,0,lVar3,"hardwired:fx10:l2cache");
  }
  iVar1 = FUN_0028804e(param_1,1);
  if (iVar1 == 0) {
    FUN_00260f71(uVar2);
  }
  else {
    lVar3 = FUN_0024febd(param_1,1,0);
    *(undefined8 *)(lVar3 + 0xb8) = uVar2;
    FUN_0024dfb5(lVar3,"CPUVendor","Fujitsu");
    FUN_0024dfb5(lVar3,"CPUModel","SPARC64 IXfx");
    FUN_0024fb45(param_1,0,lVar3,"hardwired:fx10:package");
  }
  **(undefined1 **)(param_1 + 0x288) = 1;
  FUN_0024dad7(param_1,0x10);
  return 0;
}


// ===== 002887f4 FUN_002887f4 =====

undefined8 FUN_002887f4(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  uint local_c;
  
  for (local_c = 0; local_c < 0x22; local_c = local_c + 1) {
    uVar4 = FUN_00260eab();
    FUN_0026197d(uVar4,local_c);
    iVar1 = FUN_0028804e(param_1,9);
    if (iVar1 != 0) {
      lVar3 = FUN_0024febd(param_1,9,0xffffffff);
      uVar2 = FUN_002611e2(uVar4);
      *(undefined8 *)(lVar3 + 0xb8) = uVar2;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 2;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 1;
      **(undefined8 **)(lVar3 + 0x28) = 0x10000;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x100;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 4;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:fx100:l1icache");
    }
    iVar1 = FUN_0028804e(param_1,4);
    if (iVar1 != 0) {
      lVar3 = FUN_0024febd(param_1,4,0xffffffff);
      uVar2 = FUN_002611e2(uVar4);
      *(undefined8 *)(lVar3 + 0xb8) = uVar2;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 1;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 1;
      **(undefined8 **)(lVar3 + 0x28) = 0x10000;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x100;
      *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 4;
      FUN_0024fb45(param_1,0,lVar3,"hardwired:fx100:l1dcache");
    }
    iVar1 = FUN_0028804e(param_1,2);
    if (iVar1 == 0) {
      FUN_00260f71(uVar4);
    }
    else {
      lVar3 = FUN_0024febd(param_1,2,local_c);
      *(undefined8 *)(lVar3 + 0xb8) = uVar4;
      FUN_0024fb45(param_1,0,lVar3,"hardwired::fx100:core");
    }
  }
  iVar1 = FUN_0028804e(param_1,5);
  if (iVar1 != 0) {
    lVar3 = FUN_0024febd(param_1,5,0xffffffff);
    uVar4 = FUN_00260eab();
    *(undefined8 *)(lVar3 + 0xb8) = uVar4;
    FUN_00261a1b(*(undefined8 *)(lVar3 + 0xb8),0,0xf);
    FUN_0026197d(*(undefined8 *)(lVar3 + 0xb8),0x20);
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 0;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 2;
    **(undefined8 **)(lVar3 + 0x28) = 0xc00000;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x100;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 0x18;
    FUN_0024fb45(param_1,0,lVar3,"hardwired:fx100:l2cache#0");
    lVar3 = FUN_0024febd(param_1,5,0xffffffff);
    uVar4 = FUN_00260eab();
    *(undefined8 *)(lVar3 + 0xb8) = uVar4;
    FUN_00261a1b(*(undefined8 *)(lVar3 + 0xb8),0x10,0x1f);
    FUN_0026197d(*(undefined8 *)(lVar3 + 0xb8),0x21);
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x14) = 0;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 8) = 2;
    **(undefined8 **)(lVar3 + 0x28) = 0xc00000;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0xc) = 0x100;
    *(undefined4 *)(*(long *)(lVar3 + 0x28) + 0x10) = 0x18;
    FUN_0024fb45(param_1,0,lVar3,"hardwired:fx100:l2cache#1");
  }
  iVar1 = FUN_0028804e(param_1,1);
  if (iVar1 != 0) {
    lVar3 = FUN_0024febd(param_1,1,0);
    uVar4 = FUN_00260eab();
    *(undefined8 *)(lVar3 + 0xb8) = uVar4;
    FUN_00261a1b(*(undefined8 *)(lVar3 + 0xb8),0,0x21);
    FUN_0024dfb5(lVar3,"CPUVendor","Fujitsu");
    FUN_0024dfb5(lVar3,"CPUModel","SPARC64 XIfx");
    FUN_0024fb45(param_1,0,lVar3,"hardwired:fx100:package");
  }
  **(undefined1 **)(param_1 + 0x288) = 1;
  FUN_0024dad7(param_1,0x22);
  return 0;
}


// ===== 00288c86 FUN_00288c86 =====

long FUN_00288c86(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  long local_10;
  
  local_10 = FUN_00288d52(param_1,param_3,param_4);
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    while ((local_10 != 0 &&
           (iVar1 = FUN_002622a3(param_2,*(undefined8 *)(local_10 + 0xb8)), iVar1 == 0))) {
      local_10 = *(long *)(local_10 + 0x38);
    }
  }
  return local_10;
}


// ===== 00288cfb FUN_00288cfb =====

undefined8 FUN_00288cfb(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_3);
  if ((iVar1 == -1) || (iVar1 == -2)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00288c86(param_1,param_2,iVar1,param_4);
  }
  return uVar2;
}


// ===== 00288d52 FUN_00288d52 =====

undefined8 FUN_00288d52(undefined8 param_1,int param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = FUN_002580d2(param_1,param_2,0);
  }
  else if (param_2 == *(int *)(param_3 + 0x30)) {
    uVar1 = *(undefined8 *)(param_3 + 0x38);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00288da1 FUN_00288da1 =====

void FUN_00288da1(undefined8 param_1)

{
  FUN_002580d2(param_1,0,0);
  return;
}


// ===== 00288dc5 FUN_00288dc5 =====

undefined8 FUN_00288dc5(long param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0xe0) <= local_c) {
      return 0;
    }
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0xd8) + (ulong)local_c * 0x10);
    iVar1 = strcmp((char *)*puVar2,param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return puVar2[1];
}


// ===== 00288e35 FUN_00288e35 =====

bool FUN_00288e35(undefined8 param_1,undefined4 param_2)

{
  int local_c;
  
  local_c = 1;
  FUN_002543c3(param_1,param_2,&local_c);
  if (local_c == 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("filter != HWLOC_TYPE_FILTER_KEEP_IMPORTANT",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/plugins.h"
                  ,0x218,"hwloc_filter_check_keep_object_type");
  }
  return local_c != 1;
}


// ===== 00288e95 FUN_00288e95 =====

int FUN_00288e95(ulong param_1)

{
  undefined8 local_20;
  undefined4 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    local_20 = param_1;
    if ((param_1 & 0xffffffff00000000) != 0) {
      local_20 = param_1 >> 0x20;
      local_c = 0x21;
    }
    if ((local_20 & 0xffff0000) != 0) {
      local_20 = local_20 >> 0x10;
      local_c = local_c + 0x10;
    }
    if ((local_20 & 0xff00) != 0) {
      local_20 = local_20 >> 8;
      local_c = local_c + 8;
    }
    if ((local_20 & 0xf0) != 0) {
      local_20 = local_20 >> 4;
      local_c = local_c + 4;
    }
    if ((local_20 & 0xc) != 0) {
      local_20 = local_20 >> 2;
      local_c = local_c + 2;
    }
    if ((local_20 & 2) != 0) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


// ===== 00288f4b FUN_00288f4b =====

int FUN_00288f4b(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 2) {
    if ((param_1 == 0) || (3 < param_1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = param_1 + 8;
    }
  }
  else if ((param_1 == 0) || (5 < param_1)) {
    iVar1 = -1;
  }
  else {
    iVar1 = param_1 + 3;
  }
  return iVar1;
}


// ===== 00288f91 FUN_00288f91 =====

void FUN_00288f91(void)

{
  return;
}


// ===== 00288fea FUN_00288fea =====

undefined8 FUN_00288fea(void)

{
  return 1;
}


// ===== 00288ff5 FUN_00288ff5 =====

void FUN_00288ff5(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    piVar2 = (int *)cpuid_basic_info(0);
  }
  else if (iVar1 == 1) {
    piVar2 = (int *)cpuid_Version_info(1);
  }
  else if (iVar1 == 2) {
    piVar2 = (int *)cpuid_cache_tlb_info(2);
  }
  else if (iVar1 == 3) {
    piVar2 = (int *)cpuid_serial_info(3);
  }
  else if (iVar1 == 4) {
    piVar2 = (int *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (iVar1 == 5) {
    piVar2 = (int *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (iVar1 == 6) {
    piVar2 = (int *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (iVar1 == 7) {
    piVar2 = (int *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (iVar1 == 9) {
    piVar2 = (int *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (iVar1 == 10) {
    piVar2 = (int *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (iVar1 == 0xb) {
    piVar2 = (int *)cpuid_Extended_Topology_info(0xb);
  }
  else if (iVar1 == 0xd) {
    piVar2 = (int *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (iVar1 == 0xf) {
    piVar2 = (int *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (iVar1 == -0x7ffffffe) {
    piVar2 = (int *)cpuid_brand_part1_info(0x80000002);
  }
  else if (iVar1 == -0x7ffffffd) {
    piVar2 = (int *)cpuid_brand_part2_info(0x80000003);
  }
  else if (iVar1 == -0x7ffffffc) {
    piVar2 = (int *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    piVar2 = (int *)cpuid(iVar1);
  }
  iVar1 = *piVar2;
  iVar3 = piVar2[2];
  iVar4 = piVar2[3];
  *param_2 = piVar2[1];
  *param_1 = iVar1;
  *param_3 = iVar4;
  *param_4 = iVar3;
  return;
}


// ===== 00289040 FUN_00289040 =====

void FUN_00289040(int *param_1)

{
  if (*param_1 != 0) {
    free(*(void **)(param_1 + 2));
  }
  free(param_1);
  return;
}


// ===== 00289075 FUN_00289075 =====

int * FUN_00289075(char *param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  char local_c8 [128];
  FILE *local_48;
  char *local_40;
  size_t local_38;
  int *local_30;
  uint local_24;
  long local_20;
  
  local_30 = malloc(0x10);
  if (local_30 == (int *)0x0) {
    fprintf(*(FILE **)PTR_stderr_0032efe0,
            "hwloc/x86: Failed to allocate cpuiddump for PU #%u, ignoring cpuiddump.\n",
            (ulong)param_2);
  }
  else {
    local_38 = strlen(param_1);
    local_38 = local_38 + 0xf;
    local_40 = malloc(local_38);
    if (local_40 != (char *)0x0) {
      snprintf(local_40,local_38,"%s/pu%u",param_1,(ulong)param_2);
      local_48 = fopen(local_40,"r");
      if (local_48 == (FILE *)0x0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "hwloc/x86: Could not read dumped cpuid file %s, ignoring cpuiddump.\n",local_40);
      }
      else {
        local_24 = 0;
        while (pcVar2 = fgets(local_c8,0x80,local_48), pcVar2 != (char *)0x0) {
          local_24 = local_24 + 1;
        }
        pvVar3 = malloc((ulong)local_24 * 0x24);
        *(void **)(local_30 + 2) = pvVar3;
        if (*(long *)(local_30 + 2) != 0) {
          fseek(local_48,0,0);
          local_20 = *(long *)(local_30 + 2);
          local_24 = 0;
          while (pcVar2 = fgets(local_c8,0x80,local_48), pcVar2 != (char *)0x0) {
            if ((local_c8[0] != '#') &&
               (iVar1 = sscanf(local_c8,"%x %x %x %x %x => %x %x %x %x",local_20,local_20 + 4,
                               local_20 + 8,local_20 + 0xc,local_20 + 0x10,local_20 + 0x14,
                               local_20 + 0x18,local_20 + 0x1c,local_20 + 0x20), iVar1 == 9)) {
              local_20 = local_20 + 0x24;
              local_24 = local_24 + 1;
            }
          }
          *local_30 = local_24;
          fclose(local_48);
          free(local_40);
          return local_30;
        }
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "hwloc/x86: Failed to allocate %u cpuiddump entries for PU #%u, ignoring cpuiddump.\n"
                ,(ulong)local_24,(ulong)param_2);
        fclose(local_48);
      }
      free(local_40);
    }
    free(local_30);
  }
  return (int *)0x0;
}


// ===== 00289335 FUN_00289335 =====

void FUN_00289335(uint *param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*param_5 <= local_c) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc/x86: Couldn\'t find %x,%x,%x,%x in dumped cpuid, returning 0s.\n",
              (ulong)*param_1,(ulong)*param_2,(ulong)*param_3,(ulong)*param_4);
      *param_1 = 0;
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      return;
    }
    puVar1 = (uint *)((ulong)local_c * 0x24 + *(long *)(param_5 + 2));
    if ((((((*puVar1 & 1) == 0) || (*param_1 == puVar1[1])) &&
         (((*puVar1 & 2) == 0 || (*param_2 == puVar1[2])))) &&
        (((*puVar1 & 4) == 0 || (*param_3 == puVar1[3])))) &&
       (((*puVar1 & 8) == 0 || (*param_4 == puVar1[4])))) break;
    local_c = local_c + 1;
  }
  *param_1 = puVar1[5];
  *param_2 = puVar1[6];
  *param_3 = puVar1[7];
  *param_4 = puVar1[8];
  return;
}


// ===== 002894b5 FUN_002894b5 =====

void FUN_002894b5(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 long param_5)

{
  if (param_5 == 0) {
    FUN_00288ff5(param_1,param_2,param_3,param_4);
  }
  else {
    FUN_00289335(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}


// ===== 00289514 FUN_00289514 =====

void FUN_00289514(long param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  ulong local_10;
  
  local_10 = 0;
  if (param_2 == 1) {
    local_10 = (ulong)((param_5 >> 0x18) << 10);
  }
  else if (param_2 == 2) {
    local_10 = (ulong)((param_5 >> 0x10) << 10);
  }
  else if (param_2 == 3) {
    local_10 = (ulong)((param_5 >> 0x12) << 0x13);
  }
  if ((local_10 != 0) &&
     (pvVar2 = realloc(*(void **)(param_1 + 0x38),(ulong)(*(int *)(param_1 + 0x34) + 1) * 0x30),
     pvVar2 != (void *)0x0)) {
    *(void **)(param_1 + 0x38) = pvVar2;
    uVar1 = *(uint *)(param_1 + 0x34);
    *(uint *)(param_1 + 0x34) = uVar1 + 1;
    puVar3 = (undefined4 *)((ulong)uVar1 * 0x30 + *(long *)(param_1 + 0x38));
    *puVar3 = param_3;
    puVar3[1] = param_2;
    puVar3[2] = param_4;
    puVar3[4] = param_5 & 0xff;
    puVar3[5] = 0;
    puVar3[6] = 0;
    if (param_2 == 1) {
      puVar3[7] = param_5 >> 0x10 & 0xff;
      if (puVar3[7] == 0xff) {
        puVar3[7] = 0xffffffff;
      }
    }
    else {
      puVar3[7] = *(undefined4 *)(&DAT_002f5ba0 + (ulong)(param_5 >> 0xc & 0xf) * 4);
    }
    *(ulong *)(puVar3 + 10) = local_10;
    puVar3[8] = 0;
    FUN_00288f91("cache L%u t%u linesize %u ways %d size %luKB\n",puVar3[1],puVar3[2],puVar3[4],
                 puVar3[7],*(ulong *)(puVar3 + 10) >> 10);
  }
  return;
}


// ===== 002896fe FUN_002896fe =====

void FUN_002896fe(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  uint local_18;
  uint local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  local_c = 0x80000005;
  FUN_002894b5(&local_c,local_10,&local_14,&local_18,param_2);
  FUN_00289514(param_1,1,1,1,local_14);
  FUN_00289514(param_1,1,2,1,local_18);
  local_c = 0x80000006;
  FUN_002894b5(&local_c,local_10,&local_14,&local_18,param_2);
  if ((local_14 & 0xf000) != 0) {
    FUN_00289514(param_1,2,0,1,local_14);
  }
  if ((local_18 & 0xf000) != 0) {
    FUN_00289514(param_1,3,0,param_3,local_18);
  }
  return;
}


// ===== 002897fc FUN_002897fc =====

void FUN_002897fc(long param_1,undefined8 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  ulong local_38;
  ulong local_30;
  ulong local_28;
  ulong local_20;
  int *local_18;
  int local_c;
  
  if (*(int *)(param_1 + 0x34) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!infos->numcaches",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-x86.c"
                  ,0x13b,"read_amd_caches_topoext");
  }
  local_c = 0;
  while( true ) {
    local_3c = 0x8000001d;
    local_44 = local_c;
    FUN_002894b5(&local_3c,&local_40,&local_44,&local_48,param_2);
    if ((local_3c & 0x1f) == 0) break;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
    local_c = local_c + 1;
  }
  pvVar3 = malloc((ulong)*(uint *)(param_1 + 0x34) * 0x30);
  *(void **)(param_1 + 0x38) = pvVar3;
  local_18 = *(int **)(param_1 + 0x38);
  if (local_18 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  else {
    local_c = 0;
    while( true ) {
      local_3c = 0x8000001d;
      local_44 = local_c;
      FUN_002894b5(&local_3c,&local_40,&local_44,&local_48,param_2);
      if ((local_3c & 0x1f) == 0) break;
      if ((local_3c & 0x1f) == 1) {
        *local_18 = 1;
      }
      else if ((local_3c & 0x1f) == 2) {
        *local_18 = 2;
      }
      else {
        *local_18 = 0;
      }
      local_18[1] = local_3c >> 5 & 7;
      local_18[2] = (local_3c >> 0xe & 0xfff) + 1;
      uVar1 = (local_40 & 0xfff) + 1;
      local_20 = (ulong)uVar1;
      local_18[4] = uVar1;
      uVar1 = (local_40 >> 0xc & 0x3ff) + 1;
      local_28 = (ulong)uVar1;
      local_18[5] = uVar1;
      uVar1 = (local_40 >> 0x16) + 1;
      local_30 = (ulong)uVar1;
      if ((local_3c & 0x200) == 0) {
        local_18[7] = uVar1;
      }
      else {
        local_18[7] = -1;
      }
      local_38 = (ulong)(local_44 + 1U);
      local_18[8] = local_44 + 1U;
      *(ulong *)(local_18 + 10) = local_20 * local_28 * local_30 * local_38;
      local_18[6] = local_48 & 2;
      if (*local_18 == 1) {
        uVar2 = 100;
      }
      else if (*local_18 == 2) {
        uVar2 = 0x69;
      }
      else {
        uVar2 = 0x75;
      }
      FUN_00288f91("cache %u L%u%c t%u linesize %lu linepart %lu ways %lu sets %lu, size %luKB\n",
                   local_c,local_18[1],uVar2,local_18[2],local_20,local_28,local_30,local_38,
                   *(ulong *)(local_18 + 10) >> 10);
      local_18 = local_18 + 0xc;
      local_c = local_c + 1;
    }
  }
  return;
}


// ===== 00289ab6 FUN_00289ab6 =====

void FUN_00289ab6(long param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  ulong local_48;
  ulong local_40;
  ulong local_38;
  ulong local_30;
  void *local_28;
  uint local_20;
  uint local_1c;
  int *local_18;
  int local_c;
  
  local_1c = *(uint *)(param_2 + 0x34);
  local_c = 0;
  while( true ) {
    local_4c = 4;
    local_54 = local_c;
    FUN_002894b5(&local_4c,&local_50,&local_54,&local_58,param_3);
    FUN_00288f91("cache %u type %u\n",local_c,local_4c & 0x1f);
    if (((local_4c & 0x1f) == 0) ||
       ((local_20 = local_4c >> 5 & 7, *(int *)(param_1 + 0x20) != 0 && (local_20 == 3)))) break;
    *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) + 1;
    local_c = local_c + 1;
  }
  local_28 = realloc(*(void **)(param_2 + 0x38),(ulong)*(uint *)(param_2 + 0x34) * 0x30);
  if (local_28 == (void *)0x0) {
    *(uint *)(param_2 + 0x34) = local_1c;
  }
  else {
    *(void **)(param_2 + 0x38) = local_28;
    local_18 = (int *)((ulong)local_1c * 0x30 + *(long *)(param_2 + 0x38));
    local_c = 0;
    while( true ) {
      local_4c = 4;
      local_54 = local_c;
      FUN_002894b5(&local_4c,&local_50,&local_54,&local_58,param_3);
      if (((local_4c & 0x1f) == 0) ||
         ((local_20 = local_4c >> 5 & 7, *(int *)(param_1 + 0x20) != 0 && (local_20 == 3)))) break;
      if ((local_4c & 0x1f) == 1) {
        *local_18 = 1;
      }
      else if ((local_4c & 0x1f) == 2) {
        *local_18 = 2;
      }
      else {
        *local_18 = 0;
      }
      local_18[1] = local_20;
      local_18[2] = (local_4c >> 0xe & 0xfff) + 1;
      uVar1 = (local_50 & 0xfff) + 1;
      local_30 = (ulong)uVar1;
      local_18[4] = uVar1;
      uVar1 = (local_50 >> 0xc & 0x3ff) + 1;
      local_38 = (ulong)uVar1;
      local_18[5] = uVar1;
      uVar1 = (local_50 >> 0x16) + 1;
      local_40 = (ulong)uVar1;
      if ((local_4c & 0x200) == 0) {
        local_18[7] = uVar1;
      }
      else {
        local_18[7] = -1;
      }
      local_48 = (ulong)(local_54 + 1U);
      local_18[8] = local_54 + 1U;
      *(ulong *)(local_18 + 10) = local_30 * local_38 * local_40 * local_48;
      local_18[6] = local_58 & 2;
      if (*local_18 == 1) {
        uVar2 = 100;
      }
      else if (*local_18 == 2) {
        uVar2 = 0x69;
      }
      else {
        uVar2 = 0x75;
      }
      FUN_00288f91("cache %u L%u%c t%u linesize %lu linepart %lu ways %lu sets %lu, size %luKB\n",
                   local_c,local_18[1],uVar2,local_18[2],local_30,local_38,local_40,local_48,
                   *(ulong *)(local_18 + 10) >> 10);
      local_18 = local_18 + 0xc;
      local_c = local_c + 1;
    }
  }
  return;
}


// ===== 00289dd5 FUN_00289dd5 =====

void FUN_00289dd5(long param_1,undefined8 param_2)

{
  undefined1 local_2c [4];
  uint local_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_20 = 0x80000008;
  FUN_002894b5(&local_20,local_24,&local_28,local_2c,param_2);
  local_10 = local_28 >> 0xc & 0xf;
  FUN_00288f91("core ID size: %u\n",local_10);
  if (local_10 == 0) {
    local_c = (local_28 & 0xff) + 1;
  }
  else {
    local_c = 1 << ((byte)local_10 & 0x1f);
  }
  FUN_00288f91("Thus max # of cores: %u\n",local_c);
  local_14 = 1;
  FUN_00288f91("and max # of threads: %u\n",1);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 4) / local_c;
  local_18 = *(uint *)(param_1 + 4) % local_c;
  *(uint *)(param_1 + 0xc) = local_18 / local_14;
  local_1c = local_18 % local_14;
  FUN_00288f91("this is thread %u of core %u\n",local_1c,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== 00289ef1 FUN_00289ef1 =====

void FUN_00289ef1(long param_1,ulong param_2,undefined8 param_3)

{
  undefined1 local_28 [4];
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = 0;
  local_1c = 0x8000001e;
  FUN_002894b5(&local_1c,&local_20,&local_24,local_28,param_3);
  local_10 = local_1c;
  *(undefined4 *)(param_1 + 4) = local_1c;
  if ((param_2 & 2) != 0) {
    if (*(int *)(param_1 + 0x88) == 0x16) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      local_c = 1;
    }
    else {
      *(uint *)(param_1 + 0x10) = local_24 & 0xff;
      local_c = (local_24 >> 8 & 7) + 1;
    }
    if ((((*(int *)(param_1 + 0x88) == 0x15) && (2 < local_c)) ||
        (((*(int *)(param_1 + 0x88) == 0x17 || (*(int *)(param_1 + 0x88) == 0x18)) && (4 < local_c))
        )) || ((*(int *)(param_1 + 0x88) == 0x19 && (1 < local_c)))) {
      FUN_00288f91("warning: undefined nodes_per_proc value %u, assuming it means %u\n",local_c,
                   local_c);
    }
  }
  if (*(uint *)(param_1 + 0x88) < 0x17) {
    *(uint *)(param_1 + 0x14) = local_20 & 0xff;
    local_18 = (local_20 >> 8 & 0xff) + 1;
    FUN_00288f91("topoext %08x, %u nodes, node %u, %u cores in unit %u\n",local_10,local_c,
                 *(undefined4 *)(param_1 + 0x10),local_18,*(undefined4 *)(param_1 + 0x14));
  }
  else {
    *(uint *)(param_1 + 0xc) = local_20 & 0xff;
    local_14 = (local_20 >> 8 & 0xff) + 1;
    FUN_00288f91("topoext %08x, %u nodes, node %u, %u threads in core %u\n",local_10,local_c,
                 *(undefined4 *)(param_1 + 0x10),local_14,*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ===== 0028a0a4 FUN_0028a0a4 =====

void FUN_0028a0a4(long param_1,uint param_2,undefined8 param_3)

{
  void *pvVar1;
  byte bVar2;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_c = 0;
  while( true ) {
    local_38 = local_c;
    local_30 = param_2;
    FUN_002894b5(&local_30,&local_34,&local_38,&local_3c,param_3);
    if ((local_30 == 0) && (local_34 == 0)) break;
    local_1c = local_30 & 0x1f;
    local_c = local_c + 1;
  }
  if (local_c != 0) {
    pvVar1 = malloc((ulong)local_c << 2);
    *(void **)(param_1 + 0x28) = pvVar1;
    if (*(long *)(param_1 + 0x28) != 0) {
      *(uint *)(param_1 + 0x30) = local_c;
      local_c = 0;
      while( true ) {
        local_38 = local_c;
        local_30 = param_2;
        FUN_002894b5(&local_30,&local_34,&local_38,&local_3c,param_3);
        bVar2 = (byte)local_14;
        if ((local_30 == 0) && (local_34 == 0)) break;
        local_20 = local_30 & 0x1f;
        local_24 = local_34 & 0xffff;
        local_28 = local_38 >> 8 & 0xff;
        local_10 = local_3c;
        local_2c = (1 << ((char)local_1c - bVar2 & 0x1f)) - 1U & local_3c >> (bVar2 & 0x1f);
        FUN_00288f91("x2APIC %08x %u: nextshift %u num %2u type %u id %2u\n",local_3c,local_c,
                     local_20,local_24,local_28,local_2c);
        *(uint *)(param_1 + 4) = local_10;
        *(undefined4 *)(*(long *)(param_1 + 0x28) + (ulong)local_c * 4) = 0xffffffff;
        switch(local_28) {
        default:
          FUN_00288f91("x2APIC %u: unknown type %u\n",local_c,local_28);
          *(uint *)((ulong)local_c * 4 + *(long *)(param_1 + 0x28)) =
               local_10 >> ((byte)local_14 & 0x1f);
          break;
        case 1:
          local_18 = local_2c;
          break;
        case 2:
          *(uint *)(param_1 + 0xc) = local_2c;
          break;
        case 3:
          *(uint *)(param_1 + 0x1c) = local_2c;
          break;
        case 4:
          *(uint *)(param_1 + 0x18) = local_2c;
          break;
        case 5:
          *(uint *)(param_1 + 0x20) = local_2c;
        }
        local_14 = local_20;
        local_c = local_c + 1;
      }
      *(uint *)(param_1 + 4) = local_10;
      *(uint *)(param_1 + 8) = local_10 >> (bVar2 & 0x1f);
      FUN_00288f91("x2APIC remainder: %u\n",*(undefined4 *)(param_1 + 8));
      FUN_00288f91("this is thread %u of core %u\n",local_18,*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ===== 0028a350 FUN_0028a350 =====

/* WARNING: Type propagation algorithm not settling */

void FUN_0028a350(long param_1,undefined4 *param_2,undefined8 param_3,uint param_4,uint param_5,
                 long param_6,int param_7,undefined8 param_8)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined8 local_70;
  uint local_60 [3];
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  long local_48;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  long local_20;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_20 = *(long *)(param_1 + 0x38);
  local_60[1] = 0;
  *param_2 = 1;
  local_54 = 1;
  FUN_002894b5(&local_54,local_60 + 2,local_60 + 1,local_60,param_8);
  param_2[1] = local_60[2] >> 0x18;
  if ((local_60[0] & 0x10000000) == 0) {
    FUN_00288f91("HTT bit not set in CPUID 0x01.edx, assuming legacy_max_log_proc = 1\n");
    local_10 = 1;
  }
  else {
    bVar2 = FUN_00288e95((local_60[2] >> 0x10 & 0xff) - 1);
    local_10 = 1 << (bVar2 & 0x1f);
  }
  FUN_00288f91("APIC ID 0x%02x legacy_max_log_proc %u\n",param_2[1],local_10);
  param_2[2] = (uint)param_2[1] / local_10;
  local_24 = (uint)param_2[1] % local_10;
  FUN_00288f91("phys %u legacy thread %u\n",param_2[2],local_24);
  local_28 = local_54 >> 4 & 0xf;
  local_2c = local_54 >> 0x10 & 0xf;
  local_30 = local_54 >> 8 & 0xf;
  local_34 = local_54 >> 0x14 & 0xff;
  if ((((param_7 == 0) || (param_7 == 1)) || (param_7 == 3)) && (local_30 == 0xf)) {
    param_2[0x22] = local_34 + 0xf;
  }
  else {
    param_2[0x22] = local_30;
  }
  if (((param_7 == 0) && ((local_30 == 6 || (local_30 == 0xf)))) ||
     ((((param_7 == 1 || (param_7 == 3)) && (local_30 == 0xf)) ||
      ((param_7 == 2 && ((local_30 == 6 || (local_30 == 7)))))))) {
    param_2[0x21] = local_2c * 0x10 + local_28;
  }
  else {
    param_2[0x21] = local_28;
  }
  param_2[0x20] = local_54 & 0xf;
  if (((param_7 == 0) && (param_2[0x22] == 6)) &&
     ((param_2[0x21] == 0x57 || (param_2[0x21] == 0x85)))) {
    *(undefined4 *)(local_20 + 0x20) = 1;
  }
  memset(&local_78,0,0x10);
  local_78 = 0;
  FUN_002894b5(&local_78,&uStack_74,(long)&local_70 + 4,&local_70,param_8);
  memcpy(param_2 + 0x10,&uStack_74,0xc);
  if (0x80000003 < param_5) {
    memset(&local_78,0,0x10);
    local_78 = 0x80000002;
    FUN_002894b5(&local_78,&uStack_74,&local_70,(long)&local_70 + 4,param_8);
    *(ulong *)((long)param_2 + 0x4d) = CONCAT44(uStack_74,local_78);
    *(undefined8 *)((long)param_2 + 0x55) = local_70;
    local_78 = 0x80000003;
    FUN_002894b5(&local_78,&uStack_74,&local_70,(long)&local_70 + 4,param_8);
    *(ulong *)((long)param_2 + 0x5d) = CONCAT44(uStack_74,local_78);
    *(undefined8 *)((long)param_2 + 0x65) = local_70;
    local_78 = 0x80000004;
    FUN_002894b5(&local_78,&uStack_74,&local_70,(long)&local_70 + 4,param_8);
    *(ulong *)((long)param_2 + 0x6d) = CONCAT44(uStack_74,local_78);
    *(undefined8 *)((long)param_2 + 0x75) = local_70;
  }
  if (((param_7 != 1) && (param_7 != 3)) && (3 < param_4)) {
    local_54 = 4;
    local_60[1] = 0;
    FUN_002894b5(&local_54,local_60 + 2,local_60 + 1,local_60,param_8);
    if ((local_54 & 0x1f) != 0) {
      FUN_00288f91("Trying to get core/thread IDs from 0x04...\n");
      local_38 = (local_54 >> 0x1a) + 1;
      FUN_00288f91("found %u cores max\n",local_38);
      if (local_38 == 0) {
        FUN_00288f91("cannot detect core/thread IDs from 0x04 without a valid max of cores\n");
      }
      else {
        local_3c = local_10 / local_38;
        FUN_00288f91("found %u threads max\n",local_3c,local_10 % local_38);
        if (local_3c == 0) {
          FUN_00288f91("cannot detect core/thread IDs from 0x04 without a valid max of threads\n");
        }
        else {
          local_40 = local_24 % local_3c;
          param_2[3] = local_24 / local_3c;
          FUN_00288f91("this is thread %u of core %u\n",local_40,param_2[3]);
        }
      }
    }
  }
  if ((0x19 < param_4) && ((*(uint *)(param_6 + 0x48) & 0x8000) != 0)) {
    local_54 = 0x1a;
    local_60[1] = 0;
    FUN_002894b5(&local_54,local_60 + 2,local_60 + 1,local_60,param_8);
    param_2[0x23] = local_54 >> 0x18;
    param_2[0x24] = local_54 & 0xffffff;
  }
  if (((param_7 != 0) && (param_7 != 2)) &&
     ((0x80000007 < param_5 && ((*(uint *)(param_6 + 0x10) & 0x200000) == 0)))) {
    FUN_00289dd5(param_2,param_8);
  }
  if (((param_7 != 0) && (param_7 != 2)) && ((*(uint *)(param_6 + 0x18) & 0x400000) != 0)) {
    FUN_00289ef1(param_2,param_3,param_8);
  }
  if ((param_7 == 0) && (0x1e < param_4)) {
    FUN_0028a0a4(param_2,0x1f,param_8);
  }
  else if ((((param_7 == 0) || ((param_7 == 1 || (param_7 == 2)))) && (10 < param_4)) &&
          ((*(uint *)(param_6 + 0x10) & 0x200000) != 0)) {
    FUN_0028a0a4(param_2,0xb,param_8);
  }
  param_2[0xd] = 0;
  *(undefined8 *)(param_2 + 0xe) = 0;
  if (((param_7 == 0) || (param_7 == 2)) || ((*(uint *)(param_6 + 0x18) & 0x400000) == 0)) {
    if (((param_7 != 0) && (param_7 != 2)) && (0x80000005 < param_5)) {
      FUN_002896fe(param_2,param_8,local_10);
    }
  }
  else {
    FUN_002897fc(param_2,param_8);
  }
  if (((param_7 != 1) && (param_7 != 3)) && (3 < param_4)) {
    FUN_00289ab6(local_20,param_2,param_8);
  }
  for (local_c = 0; local_c < (uint)param_2[0xd]; local_c = local_c + 1) {
    local_48 = (ulong)local_c * 0x30 + *(long *)(param_2 + 0xe);
    *(uint *)(local_48 + 0xc) = (uint)param_2[1] / *(uint *)(local_48 + 8);
    if (param_7 == 0) {
      local_4c = FUN_00288e95(*(int *)(local_48 + 8) + -1);
      local_50 = -(1 << ((byte)local_4c & 0x1f));
      *(uint *)(local_48 + 0xc) = param_2[1] & local_50;
    }
    else if (param_7 == 1) {
      if (((uint)param_2[0x22] < 0x17) || (*(int *)(local_48 + 4) != 3)) {
        if ((((param_2[0x22] == 0x10) && ((param_2[0x21] == 9 && (*(int *)(local_48 + 4) == 3)))) &&
            ((*(int *)(local_48 + 0x1c) == -1 || ((*(uint *)(local_48 + 0x1c) & 1) == 0)))) &&
           (7 < *(uint *)(local_48 + 8))) {
          if (*(int *)(local_48 + 8) == 0x10) {
            *(undefined4 *)(local_48 + 8) = 0xc;
          }
          *(uint *)(local_48 + 8) = *(uint *)(local_48 + 8) >> 1;
          *(ulong *)(local_48 + 0x28) = *(ulong *)(local_48 + 0x28) >> 1;
          if (*(int *)(local_48 + 0x1c) != -1) {
            *(int *)(local_48 + 0x1c) = *(int *)(local_48 + 0x1c) / 2;
          }
          *(uint *)(local_48 + 0xc) =
               ((uint)param_2[1] % local_10) / *(uint *)(local_48 + 8) +
               ((uint)param_2[1] / local_10) * 2;
        }
        else if (((param_2[0x22] == 0x15) &&
                 (((param_2[0x21] == 1 || (param_2[0x21] == 2)) && (*(int *)(local_48 + 4) == 3))))
                && (*(int *)(local_48 + 8) == 6)) {
          *(uint *)(local_48 + 0xc) =
               ((uint)param_2[1] % local_10) / *(uint *)(local_48 + 8) +
               ((uint)param_2[1] / local_10) * 2;
        }
      }
      else {
        local_14 = *(uint *)(local_48 + 8);
        if ((local_14 - 1 & local_14) != 0) {
          lVar1 = 0;
          if (local_14 != 0) {
            for (; (local_14 >> lVar1 & 1) == 0; lVar1 = lVar1 + 1) {
            }
          }
          cVar3 = (char)lVar1;
          if (local_14 == 0) {
            cVar3 = -1;
          }
          local_14 = 1 << (cVar3 + 2U & 0x1f);
        }
        *(uint *)(local_48 + 0xc) = (uint)param_2[1] / local_14;
      }
    }
    else if ((((param_7 == 3) && (param_2[0x22] == 0x18)) && (*(int *)(local_48 + 4) == 3)) &&
            (*(int *)(local_48 + 8) == 6)) {
      *(uint *)(local_48 + 0xc) = (uint)param_2[1] >> 3;
    }
  }
  iVar4 = FUN_0026203b(*(undefined8 *)(local_20 + 8),param_2[1]);
  if (iVar4 == 0) {
    FUN_0026197d(*(undefined8 *)(local_20 + 8),param_2[1]);
  }
  else {
    *(undefined4 *)(local_20 + 0x10) = 0;
  }
  return;
}


// ===== 0028ad7a FUN_0028ad7a =====

void FUN_0028ad7a(long param_1,long param_2,undefined4 param_3)

{
  char local_1c [12];
  char *local_10;
  
  if (*(char *)(param_2 + 0x40) != '\0') {
    FUN_0024dd20(param_1 + 0xd8,param_1 + 0xe0,"CPUVendor",param_2 + 0x40,param_3);
  }
  snprintf(local_1c,0xc,"%u",(ulong)*(uint *)(param_2 + 0x88));
  FUN_0024dd20(param_1 + 0xd8,param_1 + 0xe0,"CPUFamilyNumber",local_1c,param_3);
  snprintf(local_1c,0xc,"%u",(ulong)*(uint *)(param_2 + 0x84));
  FUN_0024dd20(param_1 + 0xd8,param_1 + 0xe0,"CPUModelNumber",local_1c,param_3);
  if (*(char *)(param_2 + 0x4d) != '\0') {
    for (local_10 = (char *)(param_2 + 0x4d); *local_10 == ' '; local_10 = local_10 + 1) {
    }
    FUN_0024dd20(param_1 + 0xd8,param_1 + 0xe0,"CPUModel",local_10,param_3);
  }
  snprintf(local_1c,0xc,"%u",(ulong)*(uint *)(param_2 + 0x80));
  FUN_0024dd20(param_1 + 0xd8,param_1 + 0xe0,"CPUStepping",local_1c,param_3);
  return;
}


// ===== 0028af32 FUN_0028af32 =====

void FUN_0028af32(undefined8 param_1,long param_2,uint param_3,undefined8 param_4,uint param_5,
                 char *param_6,undefined4 param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  char *pcVar5;
  uint local_c;
  
  while( true ) {
    local_c = FUN_00262aab(param_4);
    if (local_c == 0xffffffff) break;
    iVar1 = *(int *)(param_2 + (ulong)local_c * 0x98 + 8);
    iVar2 = *(int *)((ulong)local_c * 0x98 + param_2 + 8 + (ulong)param_5 * 4);
    if (iVar2 == -1) {
      FUN_00261cf0(param_4,local_c);
    }
    else {
      uVar3 = FUN_00260eab();
      for (; local_c < param_3; local_c = local_c + 1) {
        if (*(int *)((ulong)local_c * 0x98 + param_2 + 8 + (ulong)param_5 * 4) == -1) {
          FUN_00261cf0(param_4,local_c);
        }
        else if ((iVar1 == *(int *)(param_2 + (ulong)local_c * 0x98 + 8)) &&
                (iVar2 == *(int *)((ulong)local_c * 0x98 + param_2 + 8 + (ulong)param_5 * 4))) {
          FUN_0026197d(uVar3,local_c);
          FUN_00261cf0(param_4,local_c);
        }
      }
      lVar4 = FUN_0024febd(param_1,0xc,iVar2);
      *(undefined8 *)(lVar4 + 0xb8) = uVar3;
      pcVar5 = strdup(param_6);
      *(char **)(lVar4 + 8) = pcVar5;
      *(undefined4 *)(*(long *)(lVar4 + 0x28) + 4) = param_7;
      *(undefined1 *)(*(long *)(lVar4 + 0x28) + 0xc) = param_8;
      FUN_0024fb45(param_1,0,lVar4,"x86:group");
    }
  }
  return;
}


// ===== 0028b132 FUN_0028b132 =====

void FUN_0028b132(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined *puVar12;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  lVar3 = *(long *)(param_1 + 8);
  uVar1 = **(uint **)(param_1 + 0x38);
  uVar7 = FUN_00260eab();
  local_2c = 0xffffffff;
  local_30 = 0;
  for (local_1c = 0; local_1c < uVar1; local_1c = local_1c + 1) {
    if (*(int *)(param_2 + (ulong)local_1c * 0x98) != 0) {
      FUN_0026197d(uVar7,local_1c);
      local_2c = local_1c;
    }
  }
  if (local_2c == 0xffffffff) {
    FUN_00260f71(uVar7);
  }
  else {
    uVar8 = FUN_00260eab();
    iVar4 = FUN_00288e35(lVar3,1);
    if (iVar4 != 0) {
      FUN_00261201(uVar8,uVar7);
      while (uVar5 = FUN_00262aab(uVar8), uVar5 != 0xffffffff) {
        if ((param_3 & 1) == 0) {
          uVar9 = FUN_00260eab();
          FUN_0026197d(uVar9,uVar5);
          lVar10 = FUN_00288cfb(lVar3,uVar9,1,0);
          FUN_00260f71(uVar9);
          if (lVar10 == 0) {
            uVar9 = FUN_00288da1(lVar3);
            FUN_0028ad7a(uVar9,(ulong)uVar5 * 0x98 + param_2,1);
            break;
          }
          FUN_0028ad7a(lVar10,(ulong)uVar5 * 0x98 + param_2,1);
          FUN_00262868(uVar8,uVar8,*(undefined8 *)(lVar10 + 0xb8));
        }
        else {
          iVar4 = *(int *)(param_2 + (ulong)uVar5 * 0x98 + 8);
          uVar9 = FUN_00260eab();
          for (local_20 = uVar5; local_20 < uVar1; local_20 = local_20 + 1) {
            if (iVar4 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 8)) {
              FUN_0026197d(uVar9,local_20);
              FUN_00261cf0(uVar8,local_20);
            }
          }
          lVar10 = FUN_0024febd(lVar3,1,iVar4);
          *(undefined8 *)(lVar10 + 0xb8) = uVar9;
          FUN_0028ad7a(lVar10,(ulong)uVar5 * 0x98 + param_2,0);
          FUN_0024fb45(lVar3,0,lVar10,"x86:package");
        }
      }
    }
    if (((param_3 & 1) != 0) && ((param_3 & 2) != 0)) {
      FUN_00261201(uVar8,uVar7);
      while (local_20 = FUN_00262aab(uVar8), local_20 != 0xffffffff) {
        iVar4 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 8);
        iVar6 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 0x10);
        if (iVar6 == -1) {
          FUN_00261cf0(uVar8,local_20);
        }
        else {
          uVar9 = FUN_00260eab();
          for (; local_20 < uVar1; local_20 = local_20 + 1) {
            if (*(int *)(param_2 + (ulong)local_20 * 0x98 + 0x10) == -1) {
              FUN_00261cf0(uVar8,local_20);
            }
            else if ((iVar4 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 8)) &&
                    (iVar6 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 0x10))) {
              FUN_0026197d(uVar9,local_20);
              FUN_00261cf0(uVar8,local_20);
            }
          }
          lVar10 = FUN_0024febd(lVar3,0xd,iVar6);
          *(undefined8 *)(lVar10 + 0xb8) = uVar9;
          uVar9 = FUN_00260eab();
          *(undefined8 *)(lVar10 + 200) = uVar9;
          FUN_0026197d(*(undefined8 *)(lVar10 + 200),iVar6);
          FUN_0024fb45(lVar3,0,lVar10,"x86:numa");
          local_30 = local_30 + 1;
        }
      }
    }
    iVar4 = FUN_00288e35(lVar3,0xc);
    if ((iVar4 != 0) && ((param_3 & 1) != 0)) {
      FUN_00261201(uVar8,uVar7);
      FUN_0028af32(lVar3,param_2,uVar1,uVar8,3,"Compute Unit",0x78,0);
      FUN_00261201(uVar8,uVar7);
      FUN_0028af32(lVar3,param_2,uVar1,uVar8,5,"Module",0x66,0);
      FUN_00261201(uVar8,uVar7);
      FUN_0028af32(lVar3,param_2,uVar1,uVar8,4,&DAT_002f580c,0x67,0);
      if (*(long *)(param_2 + (long)(int)local_2c * 0x98 + 0x28) != 0) {
        local_28 = *(uint *)(param_2 + (long)(int)local_2c * 0x98 + 0x30);
        while (local_28 = local_28 - 1,
              local_28 <= *(int *)(param_2 + (long)(int)local_2c * 0x98 + 0x30) - 1U) {
          if (*(int *)(*(long *)(param_2 + (long)(int)local_2c * 0x98 + 0x28) + (ulong)local_28 * 4)
              != -1) {
            FUN_00261201(uVar8,uVar7);
            while (local_20 = FUN_00262aab(uVar8), local_20 != 0xffffffff) {
              iVar4 = *(int *)(*(long *)(param_2 + (ulong)local_20 * 0x98 + 0x28) +
                              (ulong)local_28 * 4);
              uVar9 = FUN_00260eab();
              for (; local_20 < uVar1; local_20 = local_20 + 1) {
                if (iVar4 == *(int *)(*(long *)(param_2 + (ulong)local_20 * 0x98 + 0x28) +
                                     (ulong)local_28 * 4)) {
                  FUN_0026197d(uVar9,local_20);
                  FUN_00261cf0(uVar8,local_20);
                }
              }
              lVar10 = FUN_0024febd(lVar3,0xc,iVar4);
              *(undefined8 *)(lVar10 + 0xb8) = uVar9;
              *(undefined4 *)(*(long *)(lVar10 + 0x28) + 4) = 0x65;
              *(uint *)(*(long *)(lVar10 + 0x28) + 8) = local_28;
              FUN_0024fb45(lVar3,0,lVar10,"x86:group:unknown");
            }
          }
        }
      }
    }
    iVar4 = FUN_00288e35(lVar3,0x13);
    if ((iVar4 != 0) && ((param_3 & 1) != 0)) {
      FUN_00261201(uVar8,uVar7);
      while (local_20 = FUN_00262aab(uVar8), local_20 != 0xffffffff) {
        iVar4 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 8);
        iVar6 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 0x20);
        if (iVar6 == -1) {
          FUN_00261cf0(uVar8,local_20);
        }
        else {
          uVar9 = FUN_00260eab();
          for (; local_20 < uVar1; local_20 = local_20 + 1) {
            if (*(int *)(param_2 + (ulong)local_20 * 0x98 + 0x20) == -1) {
              FUN_00261cf0(uVar8,local_20);
            }
            else if ((iVar4 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 8)) &&
                    (iVar6 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 0x20))) {
              FUN_0026197d(uVar9,local_20);
              FUN_00261cf0(uVar8,local_20);
            }
          }
          lVar10 = FUN_0024febd(lVar3,0x13,iVar6);
          *(undefined8 *)(lVar10 + 0xb8) = uVar9;
          FUN_0024fb45(lVar3,0,lVar10,"x86:die");
        }
      }
    }
    iVar4 = FUN_00288e35(lVar3,2);
    if ((iVar4 != 0) && ((param_3 & 1) != 0)) {
      FUN_00261201(uVar8,uVar7);
      while (local_20 = FUN_00262aab(uVar8), local_20 != 0xffffffff) {
        iVar4 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 8);
        iVar6 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 0x10);
        iVar2 = *(int *)(param_2 + (ulong)local_20 * 0x98 + 0xc);
        if (iVar2 == -1) {
          FUN_00261cf0(uVar8,local_20);
        }
        else {
          uVar9 = FUN_00260eab();
          for (; local_20 < uVar1; local_20 = local_20 + 1) {
            if (*(int *)(param_2 + (ulong)local_20 * 0x98 + 0xc) == -1) {
              FUN_00261cf0(uVar8,local_20);
            }
            else if (((iVar4 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 8)) &&
                     (iVar6 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 0x10))) &&
                    (iVar2 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 0xc))) {
              FUN_0026197d(uVar9,local_20);
              FUN_00261cf0(uVar8,local_20);
            }
          }
          lVar10 = FUN_0024febd(lVar3,2,iVar2);
          *(undefined8 *)(lVar10 + 0xb8) = uVar9;
          FUN_0024fb45(lVar3,0,lVar10,"x86:core");
        }
      }
    }
    if ((param_3 & 1) != 0) {
      FUN_00288f91(&DAT_002f5849,"\n\n * CPU cpusets *\n\n");
      for (local_1c = 0; local_1c < uVar1; local_1c = local_1c + 1) {
        if (*(int *)(param_2 + (ulong)local_1c * 0x98) != 0) {
          lVar10 = FUN_0024febd(lVar3,3,local_1c);
          uVar9 = FUN_00260eab();
          *(undefined8 *)(lVar10 + 0xb8) = uVar9;
          FUN_002618f3(*(undefined8 *)(lVar10 + 0xb8),local_1c);
          FUN_0024fb45(lVar3,0,lVar10,"x86:pu");
        }
      }
    }
    local_28 = 0;
    for (local_1c = 0; local_1c < uVar1; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(uint *)(param_2 + (ulong)local_1c * 0x98 + 0x34);
          local_20 = local_20 + 1) {
        if (local_28 <
            *(uint *)((ulong)local_20 * 0x30 + *(long *)(param_2 + (ulong)local_1c * 0x98 + 0x38) +
                     4)) {
          local_28 = *(uint *)((ulong)local_20 * 0x30 +
                               *(long *)(param_2 + (ulong)local_1c * 0x98 + 0x38) + 4);
        }
      }
    }
    for (; local_28 != 0; local_28 = local_28 - 1) {
      for (local_34 = 0; local_34 < 3; local_34 = local_34 + 1) {
        iVar4 = FUN_00288f4b(local_28,local_34);
        if ((iVar4 != -1) && (iVar6 = FUN_00288e35(lVar3,iVar4), iVar6 != 0)) {
          FUN_00261201(uVar8,uVar7);
          while (uVar5 = FUN_00262aab(uVar8), uVar5 != 0xffffffff) {
            local_24 = 0;
            while ((local_24 < *(uint *)(param_2 + (ulong)uVar5 * 0x98 + 0x34) &&
                   ((local_28 !=
                     *(uint *)((ulong)local_24 * 0x30 +
                               *(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + 4) ||
                    (local_34 !=
                     *(uint *)((ulong)local_24 * 0x30 +
                              *(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38))))))) {
              local_24 = local_24 + 1;
            }
            if (local_24 == *(uint *)(param_2 + (ulong)uVar5 * 0x98 + 0x34)) {
              FUN_00261cf0(uVar8,uVar5);
            }
            else {
              uVar9 = FUN_00260eab();
              FUN_0026197d(uVar9,uVar5);
              lVar10 = FUN_00288cfb(lVar3,uVar9,iVar4,0);
              FUN_00260f71(uVar9);
              if (lVar10 == 0) {
                iVar6 = *(int *)(param_2 + (ulong)uVar5 * 0x98 + 8);
                iVar2 = *(int *)((ulong)local_24 * 0x30 +
                                 *(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + 0xc);
                uVar9 = FUN_00260eab();
                for (local_20 = uVar5; local_20 < uVar1; local_20 = local_20 + 1) {
                  local_38 = 0;
                  while ((local_38 < *(uint *)(param_2 + (ulong)local_20 * 0x98 + 0x34) &&
                         ((local_28 !=
                           *(uint *)((ulong)local_38 * 0x30 +
                                     *(long *)(param_2 + (ulong)local_20 * 0x98 + 0x38) + 4) ||
                          (local_34 !=
                           *(uint *)((ulong)local_38 * 0x30 +
                                    *(long *)(param_2 + (ulong)local_20 * 0x98 + 0x38))))))) {
                    local_38 = local_38 + 1;
                  }
                  if (local_38 == *(uint *)(param_2 + (ulong)local_20 * 0x98 + 0x34)) {
                    FUN_00261cf0(uVar8,local_20);
                  }
                  else if ((iVar6 == *(int *)(param_2 + (ulong)local_20 * 0x98 + 8)) &&
                          (iVar2 == *(int *)((ulong)local_38 * 0x30 +
                                             *(long *)(param_2 + (ulong)local_20 * 0x98 + 0x38) +
                                            0xc))) {
                    FUN_0026197d(uVar9,local_20);
                    FUN_00261cf0(uVar8,local_20);
                  }
                }
                lVar10 = FUN_0024febd(lVar3,iVar4,0xffffffff);
                *(uint *)(*(long *)(lVar10 + 0x28) + 8) = local_28;
                **(undefined8 **)(lVar10 + 0x28) =
                     *(undefined8 *)
                      (*(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + (ulong)local_24 * 0x30 +
                      0x28);
                *(undefined4 *)(*(long *)(lVar10 + 0x28) + 0xc) =
                     *(undefined4 *)
                      (*(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + (ulong)local_24 * 0x30 +
                      0x10);
                *(undefined4 *)(*(long *)(lVar10 + 0x28) + 0x10) =
                     *(undefined4 *)
                      (*(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + (ulong)local_24 * 0x30 +
                      0x1c);
                *(undefined4 *)(*(long *)(lVar10 + 0x28) + 0x14) =
                     *(undefined4 *)
                      (*(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + (ulong)local_24 * 0x30);
                *(undefined8 *)(lVar10 + 0xb8) = uVar9;
                if (*(int *)((ulong)local_24 * 0x30 +
                             *(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + 0x18) == 0) {
                  puVar12 = &DAT_002f585f;
                }
                else {
                  puVar12 = &DAT_002f585d;
                }
                FUN_0024dfb5(lVar10,"Inclusive",puVar12);
                FUN_0024fb45(lVar3,0,lVar10,"x86:cache");
              }
              else {
                lVar11 = FUN_00288dc5(lVar10,"Inclusive");
                if (lVar11 == 0) {
                  if (*(int *)((ulong)local_24 * 0x30 +
                               *(long *)(param_2 + (ulong)uVar5 * 0x98 + 0x38) + 0x18) == 0) {
                    puVar12 = &DAT_002f585f;
                  }
                  else {
                    puVar12 = &DAT_002f585d;
                  }
                  FUN_0024dfb5(lVar10,"Inclusive",puVar12);
                }
                FUN_00262868(uVar8,uVar8,*(undefined8 *)(lVar10 + 0xb8));
              }
            }
          }
        }
      }
    }
    FUN_00260f71(uVar8);
    FUN_00260f71(uVar7);
    if (local_30 != 0) {
      *(undefined1 *)(*(long *)(lVar3 + 0x288) + 1) = 1;
    }
  }
  return;
}


// ===== 0028c72c FUN_0028c72c =====

undefined8
FUN_0028c72c(long param_1,long param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
            long param_6,undefined4 param_7,code *param_8,code *param_9,long param_10)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_50;
  undefined8 local_48;
  uint local_3c;
  long local_38;
  uint *local_30;
  long local_28;
  uint local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_30 = *(uint **)(param_1 + 0x38);
  local_38 = *(long *)(param_1 + 8);
  local_3c = *local_30;
  local_10 = 0;
  local_18 = 0;
  if (*(long *)(local_30 + 6) == 0) {
    local_10 = FUN_00260eab();
    iVar1 = (*param_8)(local_38,local_10,4);
    if (iVar1 != 0) {
      FUN_00260f71(local_10);
      return 0xffffffff;
    }
    local_18 = FUN_00260eab();
  }
  local_1c = 0;
  do {
    if (local_3c <= local_1c) {
      if (*(long *)(local_30 + 6) == 0) {
        (*param_9)(local_38,local_10,0);
        FUN_00260f71(local_18);
        FUN_00260f71(local_10);
      }
      if (((local_30[4] != 0) &&
          (FUN_0028b132(param_1,param_2,param_3), (*(uint *)(param_6 + 0x48) & 0x8000) != 0)) &&
         ((*(ulong *)(local_38 + 0x20) & 0x200) == 0)) {
        local_48 = FUN_00260eab();
        local_50 = FUN_00260eab();
        for (local_1c = 0; local_1c < local_3c; local_1c = local_1c + 1) {
          if (*(int *)(param_2 + (ulong)local_1c * 0x98 + 0x8c) == 0x20) {
            FUN_0026197d(local_48,local_1c);
          }
          else if (*(int *)(param_2 + (ulong)local_1c * 0x98 + 0x8c) == 0x40) {
            FUN_0026197d(local_50,local_1c);
          }
        }
        iVar1 = FUN_002620a3(local_48);
        if (iVar1 == 0) {
          local_68 = "CoreType";
          local_60 = "IntelAtom";
          FUN_0025d167(local_38,local_48,0xffffffff,&local_68,1,0);
        }
        else {
          FUN_00260f71(local_48);
        }
        iVar1 = FUN_002620a3(local_50);
        if (iVar1 == 0) {
          local_78 = "CoreType";
          local_70 = "IntelCore";
          FUN_0025d167(local_38,local_50,0xffffffff,&local_78,1,0);
        }
        else {
          FUN_00260f71(local_50);
        }
      }
      return 0;
    }
    local_28 = 0;
    if ((param_10 == 0) || (iVar1 = FUN_0026203b(param_10,local_1c), iVar1 != 0)) {
      if (*(long *)(local_30 + 6) == 0) {
        FUN_002618f3(local_18,local_1c);
        FUN_00288f91("binding to CPU%u\n",local_1c);
        iVar1 = (*param_9)(local_38,local_18,4);
        if (iVar1 == 0) goto LAB_0028c8aa;
        piVar2 = __errno_location();
        pcVar3 = strerror(*piVar2);
        FUN_00288f91("could not bind to CPU%u: %s\n",local_1c,pcVar3);
      }
      else {
        local_28 = FUN_00289075(*(undefined8 *)(local_30 + 6),local_1c);
        if (local_28 != 0) {
LAB_0028c8aa:
          FUN_0028a350(param_1,(ulong)local_1c * 0x98 + param_2,param_3,param_4,param_5,param_6,
                       param_7,local_28);
          if (*(long *)(local_30 + 6) != 0) {
            FUN_00289040(local_28);
          }
        }
      }
    }
    local_1c = local_1c + 1;
  } while( true );
}


// ===== 0028cb2a FUN_0028cb2a =====

void FUN_0028cb2a(void)

{
  return;
}


// ===== 0028cb39 FUN_0028cb39 =====

void FUN_0028cb39(void)

{
  return;
}


// ===== 0028cb48 FUN_0028cb48 =====

undefined8 FUN_0028cb48(void)

{
  return 0;
}


// ===== 0028cb5e FUN_0028cb5e =====

undefined8 FUN_0028cb5e(void)

{
  return 0;
}


// ===== 0028cb74 FUN_0028cb74 =====

int FUN_0028cb74(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  undefined1 local_1c7 [15];
  undefined1 local_1b8 [16];
  undefined1 *local_1a8;
  code *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  undefined1 local_d0 [8];
  int local_c8 [4];
  int local_b8;
  int local_b0;
  int local_a4;
  int local_80;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  void *local_58;
  uint local_4c;
  long local_48;
  uint *local_40;
  int local_34;
  long local_30;
  long local_28;
  code *local_20;
  code *local_18;
  int local_10;
  uint local_c;
  
  local_40 = *(uint **)(param_1 + 0x38);
  local_48 = *(long *)(param_1 + 8);
  local_4c = *local_40;
  local_6c = 0;
  piVar3 = local_c8;
  for (lVar2 = 9; lVar2 != 0; lVar2 = lVar2 + -1) {
    piVar3[0] = 0;
    piVar3[1] = 0;
    piVar3 = piVar3 + 2;
  }
  *piVar3 = 0;
  local_58 = (void *)0x0;
  local_10 = 4;
  local_18 = (code *)0x0;
  local_20 = (code *)0x0;
  local_28 = 0;
  local_30 = 0;
  local_34 = -1;
  memset(&local_198,0,0xc0);
  local_1a8 = local_1c7;
  FUN_00260a80(&local_198,local_1b8);
  if (*(long *)(local_40 + 6) == 0) {
    if ((local_180 == (code *)0x0) || (local_188 == (code *)0x0)) {
      if ((local_190 == (code *)0x0) || (local_198 == (code *)0x0)) {
        if (1 < local_4c) goto LAB_0028d27c;
        local_18 = FUN_0028cb48;
        local_20 = FUN_0028cb5e;
      }
      else {
        local_18 = local_190;
        local_20 = local_198;
      }
    }
    else {
      local_18 = local_180;
      local_20 = local_188;
    }
  }
  else {
    local_30 = FUN_00289075(*(undefined8 *)(local_40 + 6),0);
    if (local_30 == 0) goto LAB_0028d27c;
  }
  if ((*(ulong *)(local_48 + 0x20) & 0x10) != 0) {
    local_28 = FUN_00260eab();
    if (local_28 == 0) goto LAB_0028d27c;
    if (local_190 == (code *)0x0) {
      if (local_180 != (code *)0x0) {
        (*local_180)(local_48,local_28,0);
      }
    }
    else {
      (*local_190)(local_48,local_28,0);
    }
    iVar1 = FUN_002620a3(local_28);
    if (iVar1 != 0) {
      FUN_00260f71(local_28);
      local_28 = 0;
    }
  }
  if (((local_30 != 0) || (iVar1 = FUN_00288fea(), iVar1 != 0)) &&
     (local_58 = calloc((ulong)local_4c,0x98), local_58 != (void *)0x0)) {
    for (local_c = 0; local_c < local_4c; local_c = local_c + 1) {
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 8) = 0xffffffff;
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 0xc) = 0xffffffff;
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 0x10) = 0xffffffff;
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 0x14) = 0xffffffff;
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 0x18) = 0xffffffff;
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 0x1c) = 0xffffffff;
      *(undefined4 *)((long)local_58 + (ulong)local_c * 0x98 + 0x20) = 0xffffffff;
    }
    local_64 = 0;
    FUN_002894b5(&local_64,&local_68,&local_6c,&local_70,local_30);
    local_5c = local_64;
    if (((local_68 == 0x756e6547) && (local_6c == 0x6c65746e)) && (local_70 == 0x49656e69)) {
      local_10 = 0;
    }
    else if (((local_68 == 0x68747541) && (local_6c == 0x444d4163)) && (local_70 == 0x69746e65)) {
      local_10 = 1;
    }
    else if ((((local_68 == 0x746e6543) && (local_6c == 0x736c7561)) && (local_70 == 0x48727561)) ||
            (((local_68 == 0x68532020 && (local_6c == 0x20206961)) && (local_70 == 0x68676e61)))) {
      local_10 = 2;
    }
    else if (((local_68 == 0x6f677948) && (local_6c == 0x656e6975)) && (local_70 == 0x6e65476e)) {
      local_10 = 3;
    }
    FUN_00288f91("highest cpuid %x, cpuid type %u\n",local_64,local_10);
    if (local_5c != 0) {
      local_64 = 1;
      FUN_002894b5(&local_64,&local_68,&local_6c,&local_70,local_30);
      local_c8[0] = local_70;
      local_b8 = local_6c;
      local_64 = 0x80000000;
      FUN_002894b5(&local_64,&local_68,&local_6c,&local_70,local_30);
      local_60 = local_64;
      FUN_00288f91("highest extended cpuid %x\n",local_64);
      if (6 < local_5c) {
        local_64 = 7;
        local_6c = 0;
        FUN_002894b5(&local_64,&local_68,&local_6c,&local_70,local_30);
        local_a4 = local_68;
        local_80 = local_70;
      }
      if ((local_10 != 0) && (0x80000000 < local_60)) {
        local_64 = 0x80000001;
        FUN_002894b5(&local_64,&local_68,&local_6c,&local_70,local_30);
        local_c8[1] = local_70;
        local_b0 = local_6c;
      }
      FUN_0028cb2a(local_d0,local_30);
      local_34 = FUN_0028c72c(param_1,local_58,param_2,local_5c,local_60,local_c8,local_10,local_18,
                              local_20,local_28);
      if ((local_34 != 0) && (local_4c == 1)) {
        FUN_0028a350(param_1,local_58,param_2,local_5c,local_60,local_c8,local_10,local_30);
        FUN_0028b132(param_1,local_58,param_2);
        local_34 = 0;
      }
      FUN_0028cb39(local_d0,local_30);
    }
    if (local_58 != (void *)0x0) {
      for (local_c = 0; local_c < local_4c; local_c = local_c + 1) {
        free(*(void **)((long)local_58 + (ulong)local_c * 0x98 + 0x38));
        free(*(void **)((long)local_58 + (ulong)local_c * 0x98 + 0x28));
      }
      free(local_58);
    }
  }
LAB_0028d27c:
  FUN_00260f71(local_28);
  if (local_30 != 0) {
    FUN_00289040(local_30);
  }
  return local_34;
}


// ===== 0028d2a0 FUN_0028d2a0 =====

undefined8 FUN_0028d2a0(long param_1,int *param_2)

{
  int *piVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  int local_18;
  ulong local_10;
  
  piVar1 = *(int **)(param_1 + 0x38);
  lVar2 = *(long *)(param_1 + 8);
  local_10 = 0;
  bVar3 = false;
  if (*param_2 != 2) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("dstatus->phase == HWLOC_DISC_PHASE_CPU",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-x86.c"
                  ,0x664,"hwloc_x86_discover");
  }
  if ((*(ulong *)(lVar2 + 0x20) & 0x40) == 0) {
    pcVar6 = getenv("HWLOC_X86_TOPOEXT_NUMANODES");
    if (pcVar6 != (char *)0x0) {
      local_10 = 2;
    }
    if (*(long *)(piVar1 + 6) == 0) {
      local_18 = FUN_0024da86(1);
      if (local_18 < 1) {
        local_18 = 1;
      }
      else {
        **(undefined1 **)(lVar2 + 0x288) = 1;
      }
      *piVar1 = local_18;
    }
    else {
      if (*piVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("data->nbprocs > 0",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-x86.c"
                      ,0x679,"hwloc_x86_discover");
      }
      **(undefined1 **)(lVar2 + 0x288) = 1;
    }
    if (*(long *)(*(long *)**(undefined8 **)(lVar2 + 0x18) + 0xb8) == 0) {
      FUN_002531e1(*(undefined8 *)**(undefined8 **)(lVar2 + 0x18));
    }
    else {
      FUN_00252fa3(lVar2,0);
      if ((*(int *)(lVar2 + 4) != 2) || (*(int *)(*(long *)(lVar2 + 0x10) + 4) != *piVar1)) {
        iVar4 = FUN_0028cb74(param_1,local_10);
        if (iVar4 != 0) {
          FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(lVar2 + 0x18),"Backend",&DAT_002f594d);
        }
        return 0;
      }
      bVar3 = true;
    }
    iVar4 = FUN_0028cb74(param_1,local_10 | 1);
    if ((iVar4 < 0) && (!bVar3)) {
      FUN_0024dad7(lVar2,*piVar1);
    }
    FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(lVar2 + 0x18),"Backend",&DAT_002f594d);
    if (*(long *)(piVar1 + 6) == 0) {
      FUN_00265779(lVar2,0);
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 0028d4e7 FUN_0028d4e7 =====

undefined8 FUN_0028d4e7(char *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  char *local_70;
  char local_68 [40];
  ulong local_40;
  dirent *local_38;
  FILE *local_30;
  char *local_28;
  DIR *local_20;
  
  local_20 = opendir(param_1);
  if (local_20 != (DIR *)0x0) {
    sVar3 = strlen(param_1);
    local_28 = malloc(sVar3 + 0x12);
    if (local_28 != (char *)0x0) {
      sprintf(local_28,"%s/hwloc-cpuid-info",param_1);
      local_30 = fopen(local_28,"r");
      if (local_30 == (FILE *)0x0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,"hwloc/x86: Couldn\'t open dumped cpuid summary %s\n",
                local_28);
      }
      else {
        pcVar4 = fgets(local_68,0x20,local_30);
        if (pcVar4 == (char *)0x0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,"hwloc/x86: Found read dumped cpuid summary in %s\n"
                  ,local_28);
          fclose(local_30);
        }
        else {
          fclose(local_30);
          iVar1 = strcmp(local_68,"Architecture: x86\n");
          if (iVar1 == 0) {
            free(local_28);
            while (local_38 = readdir(local_20), local_38 != (dirent *)0x0) {
              iVar1 = strncmp(local_38->d_name,"pu",2);
              if (iVar1 == 0) {
                local_40 = strtoul(local_38->d_name + 2,&local_70,10);
                if (*local_70 == '\0') {
                  FUN_0026197d(param_2,local_40 & 0xffffffff);
                }
                else {
                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                          "hwloc/x86: Ignoring invalid dirent `%s\' in dumped cpuid directory `%s\'\n"
                          ,local_38->d_name,param_1);
                }
              }
            }
            closedir(local_20);
            iVar1 = FUN_002620a3(param_2);
            if (iVar1 == 0) {
              iVar1 = FUN_00262b2e(param_2);
              iVar2 = FUN_00262e86(param_2);
              if (iVar1 == iVar2 + -1) {
                return 0;
              }
              fprintf(*(FILE **)PTR_stderr_0032efe0,
                      "hwloc/x86: Found non-contigous pu%%u range in dumped cpuid directory `%s\'\n"
                      ,param_1);
              return 0xffffffff;
            }
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc/x86: Did not find any valid pu%%u entry in dumped cpuid directory `%s\'\n"
                    ,param_1);
            return 0xffffffff;
          }
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc/x86: Found non-x86 dumped cpuid summary in %s: %s\n",local_28,local_68);
        }
      }
      free(local_28);
    }
    closedir(local_20);
  }
  return 0xffffffff;
}


// ===== 0028d7ba FUN_0028d7ba =====

void FUN_0028d7ba(long param_1)

{
  void *__ptr;
  
  __ptr = *(void **)(param_1 + 0x38);
  FUN_00260f71(*(undefined8 *)((long)__ptr + 8));
  free(*(void **)((long)__ptr + 0x18));
  free(__ptr);
  return;
}


// ===== 0028d801 FUN_0028d801 =====

void * FUN_0028d801(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *__ptr;
  undefined4 *puVar3;
  int *piVar4;
  undefined8 uVar5;
  char *pcVar6;
  
  __ptr = (void *)FUN_0025f967(param_1,param_2);
  if (__ptr != (void *)0x0) {
    puVar3 = malloc(0x28);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 **)((long)__ptr + 0x38) = puVar3;
      *(code **)((long)__ptr + 0x48) = FUN_0028d2a0;
      *(code **)((long)__ptr + 0x40) = FUN_0028d7ba;
      puVar3[8] = 0;
      uVar5 = FUN_00260eab();
      *(undefined8 *)(puVar3 + 2) = uVar5;
      puVar3[4] = 1;
      *(undefined8 *)(puVar3 + 6) = 0;
      pcVar6 = getenv("HWLOC_CPUID_PATH");
      if (pcVar6 == (char *)0x0) {
        return __ptr;
      }
      uVar5 = FUN_00260eab();
      iVar1 = FUN_0028d4e7(pcVar6,uVar5);
      if (iVar1 == 0) {
        *(undefined4 *)((long)__ptr + 0x30) = 0;
        pcVar6 = strdup(pcVar6);
        *(char **)(puVar3 + 6) = pcVar6;
        iVar1 = FUN_002620a3(uVar5);
        if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("!hwloc_bitmap_iszero(set)",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology-x86.c"
                        ,0x725,"hwloc_x86_component_instantiate");
        }
        uVar2 = FUN_00262e86(uVar5);
        *puVar3 = uVar2;
      }
      else {
        fwrite("hwloc/x86: Ignoring dumped cpuid directory.\n",1,0x2c,*(FILE **)PTR_stderr_0032efe0)
        ;
      }
      FUN_00260f71(uVar5);
      return __ptr;
    }
    piVar4 = __errno_location();
    *piVar4 = 0xc;
    free(__ptr);
  }
  return (void *)0x0;
}


// ===== 0028d9af FUN_0028d9af =====

uint FUN_0028d9af(char *param_1,long param_2,ulong param_3)

{
  char *pcVar1;
  char cVar2;
  int __c;
  char *pcVar3;
  ushort **ppuVar4;
  char *local_30;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_c = 0;
  pcVar1 = param_1;
  while( true ) {
    local_30 = pcVar1;
    pcVar1 = local_30 + 1;
    __c = (int)*local_30;
    if (__c == 0) break;
    ppuVar4 = __ctype_b_loc();
    if (((*ppuVar4)[__c] & 0x2000) == 0) {
      if (__c == 0x3d) break;
      pcVar3 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",__c);
      if (pcVar3 == (char *)0x0) {
        return 0xffffffff;
      }
      cVar2 = (char)pcVar3;
      if (local_10 == 1) {
        if (param_2 != 0) {
          if (param_3 <= local_c + 1) {
            return 0xffffffff;
          }
          *(byte *)(param_2 + (ulong)local_c) =
               *(byte *)(param_2 + (ulong)local_c) | (byte)((long)(pcVar3 + -0x2f5c80) >> 4);
          *(char *)(param_2 + (ulong)(local_c + 1)) = cVar2 * '\x10';
        }
        local_c = local_c + 1;
        local_10 = 2;
      }
      else if (local_10 == 0) {
        if (param_2 != 0) {
          if (param_3 <= local_c) {
            return 0xffffffff;
          }
          *(char *)(param_2 + (ulong)local_c) = cVar2 * '\x04';
        }
        local_10 = 1;
      }
      else if (local_10 == 2) {
        if (param_2 != 0) {
          if (param_3 <= local_c + 1) {
            return 0xffffffff;
          }
          *(byte *)(param_2 + (ulong)local_c) =
               *(byte *)(param_2 + (ulong)local_c) | (byte)((long)(pcVar3 + -0x2f5c80) >> 2);
          *(char *)(param_2 + (ulong)(local_c + 1)) = cVar2 * '@';
        }
        local_c = local_c + 1;
        local_10 = 3;
      }
      else if (local_10 == 3) {
        if (param_2 != 0) {
          if (param_3 <= local_c) {
            return 0xffffffff;
          }
          *(byte *)(param_2 + (ulong)local_c) = *(byte *)(param_2 + (ulong)local_c) | cVar2 + 0x80U;
        }
        local_c = local_c + 1;
        local_10 = 0;
      }
    }
  }
  if (__c != 0x3d) {
    if (local_10 == 0) {
      return local_c;
    }
    return 0xffffffff;
  }
  local_30 = local_30 + 2;
  local_14 = (int)*pcVar1;
  if (local_10 == 2) {
    while ((local_14 != 0 && (ppuVar4 = __ctype_b_loc(), ((*ppuVar4)[local_14] & 0x2000) != 0))) {
      local_14 = (int)*local_30;
      local_30 = local_30 + 1;
    }
    if (local_14 != 0x3d) {
      return 0xffffffff;
    }
    local_14 = (int)*local_30;
    local_30 = local_30 + 1;
  }
  else {
    if (local_10 < 2) {
      return 0xffffffff;
    }
    if (local_10 != 3) {
      return local_c;
    }
  }
  while( true ) {
    if (local_14 == 0) {
      if ((param_2 != 0) && (*(char *)(param_2 + (ulong)local_c) != '\0')) {
        local_c = 0xffffffff;
      }
      return local_c;
    }
    ppuVar4 = __ctype_b_loc();
    if (((*ppuVar4)[local_14] & 0x2000) == 0) break;
    local_14 = (int)*local_30;
    local_30 = local_30 + 1;
  }
  return 0xffffffff;
}


// ===== 0028dd70 FUN_0028dd70 =====

int FUN_0028dd70(long param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_60 [30];
  byte local_42;
  byte local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  byte local_1a;
  byte local_19;
  
  iVar2 = FUN_0028e880();
  if (iVar2 == 0) {
    bVar1 = *(byte *)(param_1 + 0x130) & 0x7f;
    if (bVar1 == 1) {
      puVar3 = malloc(0x30);
      if (puVar3 != (undefined1 *)0x0) {
        FUN_0028ec80(param_1,&local_40,0x18,0x28,local_60);
        *puVar3 = local_40;
        puVar3[1] = local_3f;
        puVar3[2] = local_3e;
        puVar3[3] = local_3d;
        puVar3[4] = local_3c & 0xf;
        *(uint *)(puVar3 + 0xc) =
             (uint)local_28 * 0x10000 + (uint)local_27 * 0x1000000 + (local_3c & 0xf0) * 0x100;
        *(uint *)(puVar3 + 0x10) =
             (local_3b & 0xf0) * 0x100 +
             (uint)local_26 * 0x10000 + 0xfff + (uint)local_25 * 0x1000000;
        puVar3[5] = local_38 & 0xf;
        *(uint *)(puVar3 + 0x14) = (local_38 & 0xf0) * 0x10000 + (uint)local_37 * 0x1000000;
        *(uint *)(puVar3 + 0x18) = (local_36 & 0xf0) * 0x10000 + 0xffff + (uint)local_35 * 0x1000000
        ;
        puVar3[6] = local_34 & 0xf;
        *(ulong *)(puVar3 + 0x20) =
             (ulong)local_33 * 0x1000000 + ((ulong)local_30 << 0x20) + ((ulong)local_2f << 0x28) +
             ((ulong)local_2e << 0x30) + ((ulong)local_2d << 0x38) +
             (ulong)((local_34 & 0xf0) << 0x10);
        *(ulong *)(puVar3 + 0x28) =
             (ulong)((local_32 & 0xf0) << 0x10) +
             (ulong)local_31 * 0x1000000 + 0xffff + ((ulong)local_2c << 0x20) +
             ((ulong)local_2b << 0x28) + ((ulong)local_2a << 0x30) + ((ulong)local_29 << 0x38);
        *(ushort *)(puVar3 + 10) = (ushort)local_19 * 0x100 + (ushort)local_1a;
        *(ushort *)(puVar3 + 8) = (ushort)local_39 * 0x100 + (ushort)local_3a;
      }
    }
    else {
      if (bVar1 != 2) {
        return 0;
      }
      puVar3 = malloc(0x28);
      if (puVar3 != (undefined1 *)0x0) {
        FUN_0028ec80(param_1,&local_42,0x16,0x2a,local_60);
        *puVar3 = local_40;
        puVar3[1] = local_3f;
        puVar3[2] = local_3e;
        puVar3[3] = local_3d;
        *(uint *)(puVar3 + 0x18) =
             (uint)local_39 * 0x1000000 +
             (uint)local_3c + (uint)local_3a * 0x10000 + (uint)local_3b * 0x100;
        *(uint *)(puVar3 + 0x1c) =
             (uint)local_35 * 0x1000000 +
             (uint)local_38 + (uint)local_36 * 0x10000 + (uint)local_37 * 0x100;
        *(uint *)(puVar3 + 0x20) =
             (uint)local_31 * 0x1000000 +
             (uint)local_34 + (uint)local_32 * 0x10000 + (uint)local_33 * 0x100;
        *(uint *)(puVar3 + 0x24) =
             (uint)local_2d * 0x1000000 +
             (uint)local_30 + (uint)local_2e * 0x10000 + (uint)local_2f * 0x100;
        *(uint *)(puVar3 + 8) =
             (uint)local_29 * 0x1000000 +
             (uint)local_2c + (uint)local_2a * 0x10000 + (uint)local_2b * 0x100;
        *(uint *)(puVar3 + 0xc) =
             (uint)local_25 * 0x1000000 +
             (uint)local_28 + (uint)local_26 * 0x10000 + (uint)local_27 * 0x100;
        *(uint *)(puVar3 + 0x10) =
             (uint)local_21 * 0x1000000 +
             (uint)local_24 + (uint)local_22 * 0x10000 + (uint)local_23 * 0x100;
        *(uint *)(puVar3 + 0x14) =
             (uint)local_1d * 0x1000000 +
             (uint)local_20 + (uint)local_1e * 0x10000 + (uint)local_1f * 0x100;
        *(ushort *)(puVar3 + 4) = (ushort)local_41 * 0x100 + (ushort)local_42;
        *(ushort *)(puVar3 + 6) = (ushort)local_19 * 0x100 + (ushort)local_1a;
      }
    }
    *(undefined1 **)(param_1 + 0x148) = puVar3;
  }
  return iVar2;
}


// ===== 0028e180 FUN_0028e180 =====

undefined8 FUN_0028e180(long param_1)

{
  byte bVar1;
  
  if (*(long *)(param_1 + 0x148) == 0) {
    FUN_0028dd70();
    bVar1 = *(byte *)(param_1 + 0x130);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x130);
  }
  if ((bVar1 & 0x7f) == 1) {
    return *(undefined8 *)(param_1 + 0x148);
  }
  return 0;
}


// ===== 0028e1c0 FUN_0028e1c0 =====

undefined8 FUN_0028e1c0(long param_1)

{
  char cVar1;
  
  if (*(long *)(param_1 + 0x148) == 0) {
    FUN_0028dd70();
    cVar1 = *(char *)(param_1 + 0x130);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x130);
  }
  if (cVar1 == '\x02') {
    return *(undefined8 *)(param_1 + 0x148);
  }
  return 0;
}


// ===== 0028e200 FUN_0028e200 =====

undefined8 FUN_0028e200(long param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  
  if ((char)(*(uint *)(param_1 + 0x10) >> 0x10) != '\x06') {
    return 0x13;
  }
  uVar1 = *(uint *)(param_1 + 0x10) >> 8 & 0xff;
  if (uVar1 == 4) {
    if (*(long *)(param_1 + 0x148) == 0) {
      FUN_0028dd70();
    }
    if ((*(byte *)(param_1 + 0x130) & 0x7f) == 1) {
LAB_0028e290:
      *param_2 = (uint)**(byte **)(param_1 + 0x148);
      *param_3 = (uint)*(byte *)(*(long *)(param_1 + 0x148) + 1);
      *param_4 = (uint)*(byte *)(*(long *)(param_1 + 0x148) + 2);
      return 0;
    }
  }
  else if (3 < uVar1) {
    if (uVar1 != 7) {
      return 0;
    }
    if (*(long *)(param_1 + 0x148) == 0) {
      FUN_0028dd70();
    }
    if ((*(byte *)(param_1 + 0x130) & 0x7f) == 2) goto LAB_0028e290;
  }
  *param_2 = (uint)*(byte *)(param_1 + 2);
  *param_3 = 0xffffffff;
  *param_4 = 0xffffffff;
  return 0;
}


// ===== 0028e320 FUN_0028e320 =====

long FUN_0028e320(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = 0xffffffffffffffff;
  local_30 = 0xffffffffffffffff;
  local_20 = 0;
  local_28 = 0xffff0000060400;
  if ((param_1 == 0) || (lVar1 = FUN_0028e440(&local_38), lVar1 == 0)) {
    return 0;
  }
  do {
    lVar2 = FUN_0028e4d0(lVar1);
    if (lVar2 == 0) break;
  } while (((*(int *)(lVar2 + 0x124) != *(int *)(param_1 + 0x124)) ||
           (lVar3 = FUN_0028e180(lVar2), lVar3 == 0)) ||
          (*(char *)(lVar3 + 1) != *(char *)(param_1 + 2)));
  FUN_0028e4b0(lVar1);
  return lVar2;
}


// ===== 0028e3d0 FUN_0028e3d0 =====

undefined4 * FUN_0028e3d0(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  
  if (DAT_01218780 == 0) {
    return (undefined4 *)0x0;
  }
  puVar4 = malloc(0x28);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0;
    if (param_1 == (undefined8 *)0x0) {
      puVar4[1] = 0;
      return puVar4;
    }
    uVar1 = param_1[2];
    puVar4[1] = 1;
    uVar2 = *param_1;
    uVar3 = param_1[1];
    *(undefined8 *)(puVar4 + 6) = uVar1;
    *(undefined8 *)(puVar4 + 2) = uVar2;
    *(undefined8 *)(puVar4 + 4) = uVar3;
    return puVar4;
  }
  return (undefined4 *)0x0;
}


// ===== 0028e440 FUN_0028e440 =====

undefined4 * FUN_0028e440(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  if (DAT_01218780 == 0) {
    return (undefined4 *)0x0;
  }
  puVar3 = malloc(0x28);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
    if (param_1 == (undefined8 *)0x0) {
      puVar3[1] = 0;
      return puVar3;
    }
    uVar1 = *param_1;
    uVar2 = param_1[1];
    puVar3[1] = 2;
    *(undefined8 *)(puVar3 + 2) = uVar1;
    *(undefined8 *)(puVar3 + 4) = uVar2;
    uVar1 = param_1[3];
    *(undefined8 *)(puVar3 + 6) = param_1[2];
    *(undefined8 *)(puVar3 + 8) = uVar1;
    return puVar3;
  }
  return (undefined4 *)0x0;
}


// ===== 0028e4b0 FUN_0028e4b0 =====

void FUN_0028e4b0(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
    return;
  }
  return;
}


// ===== 0028e4d0 FUN_0028e4d0 =====

long FUN_0028e4d0(uint *param_1)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  
  if (param_1 != (uint *)0x0) {
    uVar3 = param_1[1];
    if (uVar3 == 1) {
      uVar3 = *param_1;
      while (uVar1 = (ulong)uVar3, uVar1 < *(ulong *)(DAT_01218780 + 8)) {
        uVar3 = uVar3 + 1;
        lVar2 = uVar1 * 0x160 + *(long *)(DAT_01218780 + 0x10);
        *param_1 = uVar3;
        if ((((param_1[2] == 0xffffffff) || (param_1[2] == *(uint *)(lVar2 + 0x124))) &&
            ((param_1[3] == 0xffffffff || (param_1[3] == (uint)*(byte *)(lVar2 + 2))))) &&
           ((param_1[4] == 0xffffffff || (param_1[4] == (uint)*(byte *)(lVar2 + 3))))) {
          if (param_1[5] == 0xffffffff) {
            return lVar2;
          }
          if (param_1[5] == (uint)*(byte *)(lVar2 + 4)) {
            return lVar2;
          }
        }
      }
    }
    else if (uVar3 == 0) {
      uVar3 = *param_1;
      if ((ulong)uVar3 < *(ulong *)(DAT_01218780 + 8)) {
        lVar2 = *(long *)(DAT_01218780 + 0x10);
        *param_1 = uVar3 + 1;
        return (ulong)uVar3 * 0x160 + lVar2;
      }
    }
    else if (uVar3 == 2) {
      uVar3 = *param_1;
      while (uVar1 = (ulong)uVar3, uVar1 < *(ulong *)(DAT_01218780 + 8)) {
        uVar3 = uVar3 + 1;
        lVar2 = uVar1 * 0x160 + *(long *)(DAT_01218780 + 0x10);
        *param_1 = uVar3;
        if ((((param_1[2] == 0xffffffff) || (param_1[2] == (uint)*(ushort *)(lVar2 + 6))) &&
            ((param_1[3] == 0xffffffff || (param_1[3] == (uint)*(ushort *)(lVar2 + 8))))) &&
           ((((param_1[4] == 0xffffffff || (param_1[4] == (uint)*(ushort *)(lVar2 + 10))) &&
             ((param_1[5] == 0xffffffff || (param_1[5] == (uint)*(ushort *)(lVar2 + 0xc))))) &&
            ((*(uint *)(lVar2 + 0x10) & param_1[7]) == param_1[6])))) {
          return lVar2;
        }
      }
    }
  }
  return 0;
}


// ===== 0028e630 FUN_0028e630 =====

void FUN_0028e630(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_38 = 0;
  local_34 = 1;
  local_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  local_24 = param_4;
  FUN_0028e4d0(&local_38);
  return;
}


// ===== 0028e660 FUN_0028e660 =====

undefined8 FUN_0028e660(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_0028ffb0();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00290ed0();
  return uVar2;
}


// ===== 0028e690 FUN_0028e690 =====

void FUN_0028e690(void)

{
  return;
}


// ===== 0028e6a0 FUN_0028e6a0 =====

void FUN_0028e6a0(void)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  void *__ptr;
  
  if (DAT_01218780 != (long *)0x0) {
    FUN_0028ef50();
    __ptr = (void *)DAT_01218780[2];
    plVar1 = DAT_01218780;
    if (__ptr != (void *)0x0) {
      if (DAT_01218780[1] != 0) {
        uVar2 = 0;
        do {
          lVar4 = uVar2 * 0x160;
          iVar3 = 0;
          while( true ) {
            FUN_0028ec20((void *)((long)__ptr + lVar4),iVar3);
            if (iVar3 + 1 == 6) break;
            __ptr = (void *)DAT_01218780[2];
            iVar3 = iVar3 + 1;
          }
          free(*(void **)(DAT_01218780[2] + 0x128 + lVar4));
          free(*(void **)(DAT_01218780[2] + 0x138 + lVar4));
          plVar1 = DAT_01218780;
          *(undefined8 *)(DAT_01218780[2] + 0x128 + lVar4) = 0;
          *(undefined8 *)(plVar1[2] + 0x138 + lVar4) = 0;
          if (*(code **)(*plVar1 + 8) != (code *)0x0) {
            (**(code **)(*plVar1 + 8))(plVar1[2] + lVar4);
            plVar1 = DAT_01218780;
          }
          uVar2 = (ulong)((int)uVar2 + 1);
          __ptr = (void *)plVar1[2];
        } while (uVar2 < (ulong)plVar1[1]);
      }
      free(__ptr);
      plVar1 = DAT_01218780;
      DAT_01218780[2] = 0;
      plVar1[1] = 0;
    }
    if (*(code **)*plVar1 != (code *)0x0) {
      (**(code **)*plVar1)();
      plVar1 = DAT_01218780;
    }
    free(plVar1);
    DAT_01218780 = (long *)0x0;
    return;
  }
  return;
}


// ===== 0028e7f0 FUN_0028e7f0 =====

undefined8 FUN_0028e7f0(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0028e807. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x10))();
    return uVar1;
  }
  return 0xe;
}


// ===== 0028e820 FUN_0028e820 =====

undefined8 FUN_0028e820(void)

{
  undefined8 uVar1;
  
  if (*(code **)(*DAT_01218780 + 0x50) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0028e836. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x50))();
    return uVar1;
  }
  return 0;
}


// ===== 0028e850 FUN_0028e850 =====

undefined8 FUN_0028e850(void)

{
  undefined8 uVar1;
  
  if (*(code **)(*DAT_01218780 + 0x58) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0028e866. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x58))();
    return uVar1;
  }
  return 0;
}


// ===== 0028e880 FUN_0028e880 =====

undefined8 FUN_0028e880(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0028e892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x18))();
    return uVar1;
  }
  return 0xe;
}


// ===== 0028e8a0 FUN_0028e8a0 =====

int FUN_0028e8a0(ulong *param_1,ulong param_2,ulong param_3,undefined4 param_4,undefined8 *param_5)

{
  ulong *puVar1;
  int iVar2;
  size_t __size;
  ulong *puVar3;
  void *__ptr;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  
  *param_5 = 0;
  if (param_1 == (ulong *)0x0) {
    return 0xe;
  }
  uVar5 = 0;
  puVar1 = param_1;
  while( true ) {
    if (((puVar1[6] != 0) && (uVar6 = puVar1[5], uVar6 <= param_2)) &&
       (uVar6 = puVar1[6] + uVar6, param_2 < uVar6)) break;
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    puVar1 = puVar1 + 5;
    if (uVar4 == 6) {
      return 2;
    }
  }
  if (uVar6 < param_2 + param_3) {
    return 7;
  }
  iVar2 = (int)param_1[0x2b];
  puVar1 = (ulong *)param_1[0x2a];
  __size = 0x20;
  if (iVar2 != 0) {
    puVar3 = puVar1;
    do {
      if ((param_2 == *puVar3) && (param_3 == puVar3[1])) {
        return 0x16;
      }
      puVar3 = puVar3 + 4;
    } while (puVar1 + (ulong)(iVar2 - 1) * 4 + 4 != puVar3);
    __size = (ulong)(iVar2 + 1) << 5;
  }
  __ptr = realloc(puVar1,__size);
  if (__ptr != (void *)0x0) {
    *(ulong *)((long)__ptr + (ulong)(uint)param_1[0x2b] * 0x20) = param_2;
    *(ulong *)((long)__ptr + (ulong)(uint)param_1[0x2b] * 0x20 + 8) = param_3;
    *(int *)((long)__ptr + (ulong)(uint)param_1[0x2b] * 0x20 + 0x10) = (int)uVar5;
    *(undefined4 *)((long)__ptr + (ulong)(uint)param_1[0x2b] * 0x20 + 0x14) = param_4;
    *(undefined8 *)((long)__ptr + (ulong)(uint)param_1[0x2b] * 0x20 + 0x18) = 0;
    if ((param_1[uVar5 * 5 + 3] == 0) &&
       (iVar2 = (**(code **)(*DAT_01218780 + 0x20))
                          (param_1,(void *)((ulong)(uint)param_1[0x2b] * 0x20 + (long)__ptr)),
       iVar2 != 0)) {
      __ptr = realloc(__ptr,(ulong)(uint)param_1[0x2b] << 5);
    }
    else {
      iVar2 = 0;
      *param_5 = *(undefined8 *)((long)__ptr + (ulong)(uint)param_1[0x2b] * 0x20 + 0x18);
      *(int *)(param_1 + 0x2b) = (int)param_1[0x2b] + 1;
    }
    param_1[0x2a] = (ulong)__ptr;
    return iVar2;
  }
  return 0xc;
}


// ===== 0028ea90 FUN_0028ea90 =====

undefined8 FUN_0028ea90(long param_1,uint param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_2 < 6) {
    lVar1 = param_1 + (ulong)param_2 * 0x28;
    if (*(long *)(lVar1 + 0x30) != 0) {
      if (*(long *)(lVar1 + 0x18) != 0) {
        return 0;
      }
      uVar2 = FUN_0028e8a0(param_1,*(undefined8 *)(lVar1 + 0x28),*(long *)(lVar1 + 0x30),
                           param_3 != 0,param_1 + 0x18 + (ulong)param_2 * 0x28);
      return uVar2;
    }
  }
  return 2;
}


// ===== 0028eaf0 FUN_0028eaf0 =====

void FUN_0028eaf0(void)

{
  FUN_0028e8a0();
  return;
}


// ===== 0028eb00 FUN_0028eb00 =====

int FUN_0028eb00(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  void *pvVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 0xe;
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    lVar1 = *(long *)(param_1 + 0x150);
    iVar6 = 0;
    lVar4 = lVar1;
    do {
      if ((param_2 == *(long *)(lVar4 + 0x18)) && (param_3 == *(long *)(lVar4 + 8))) {
        iVar2 = (**(code **)(*DAT_01218780 + 0x28))(param_1,lVar4);
        if (iVar2 == 0) {
          pvVar5 = *(void **)(param_1 + 0x150);
          uVar3 = *(int *)(param_1 + 0x158) - 1;
          if (uVar3 - iVar6 != 0) {
            memmove((void *)((long)pvVar5 + (lVar4 - lVar1)),
                    (void *)((ulong)(iVar6 + 1) * 0x20 + (long)pvVar5),(ulong)(uVar3 - iVar6) << 5);
            pvVar5 = *(void **)(param_1 + 0x150);
            uVar3 = *(int *)(param_1 + 0x158) - 1;
          }
          *(uint *)(param_1 + 0x158) = uVar3;
          pvVar5 = realloc(pvVar5,(ulong)uVar3 << 5);
          *(void **)(param_1 + 0x150) = pvVar5;
        }
        return iVar2;
      }
      iVar6 = iVar6 + 1;
      lVar4 = lVar4 + 0x20;
    } while (iVar6 != *(int *)(param_1 + 0x158));
  }
  return 2;
}


// ===== 0028ec20 FUN_0028ec20 =====

undefined8 FUN_0028ec20(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 0xe;
  }
  uVar2 = 2;
  if (param_2 < 6) {
    lVar1 = param_1 + (ulong)param_2 * 0x28;
    if (*(long *)(lVar1 + 0x30) != 0) {
      uVar2 = FUN_0028eb00(param_1,*(undefined8 *)(lVar1 + 0x18));
      if ((int)uVar2 == 0) {
        *(undefined8 *)(lVar1 + 0x18) = 0;
      }
    }
    return uVar2;
  }
  return uVar2;
}


// ===== 0028ec70 thunk_FUN_0028eb00 =====

int thunk_FUN_0028eb00(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  void *pvVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 0xe;
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    lVar1 = *(long *)(param_1 + 0x150);
    iVar6 = 0;
    lVar4 = lVar1;
    do {
      if ((param_2 == *(long *)(lVar4 + 0x18)) && (param_3 == *(long *)(lVar4 + 8))) {
        iVar2 = (**(code **)(*DAT_01218780 + 0x28))(param_1,lVar4);
        if (iVar2 == 0) {
          pvVar5 = *(void **)(param_1 + 0x150);
          uVar3 = *(int *)(param_1 + 0x158) - 1;
          if (uVar3 - iVar6 != 0) {
            memmove((void *)((long)pvVar5 + (lVar4 - lVar1)),
                    (void *)((ulong)(iVar6 + 1) * 0x20 + (long)pvVar5),(ulong)(uVar3 - iVar6) << 5);
            pvVar5 = *(void **)(param_1 + 0x150);
            uVar3 = *(int *)(param_1 + 0x158) - 1;
          }
          *(uint *)(param_1 + 0x158) = uVar3;
          pvVar5 = realloc(pvVar5,(ulong)uVar3 << 5);
          *(void **)(param_1 + 0x150) = pvVar5;
        }
        return iVar2;
      }
      iVar6 = iVar6 + 1;
      lVar4 = lVar4 + 0x20;
    } while (iVar6 != *(int *)(param_1 + 0x158));
  }
  return 2;
}


// ===== 0028ec80 FUN_0028ec80 =====

undefined8 FUN_0028ec80(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = (**(code **)(*DAT_01218780 + 0x30))();
    return uVar1;
  }
  return 0xe;
}


// ===== 0028ecc0 FUN_0028ecc0 =====

ulong FUN_0028ecc0(void)

{
  ulong uVar1;
  undefined8 local_10;
  
  uVar1 = FUN_0028ec80();
  if (((int)uVar1 == 0) && (uVar1 = uVar1 & 0xffffffff, local_10 != 1)) {
    uVar1 = 6;
  }
  return uVar1;
}


// ===== 0028ecf0 FUN_0028ecf0 =====

ulong FUN_0028ecf0(void)

{
  ulong uVar1;
  undefined8 local_10;
  
  uVar1 = FUN_0028ec80();
  if (((int)uVar1 == 0) && (uVar1 = uVar1 & 0xffffffff, local_10 != 2)) {
    uVar1 = 6;
  }
  return uVar1;
}


// ===== 0028ed20 FUN_0028ed20 =====

ulong FUN_0028ed20(void)

{
  ulong uVar1;
  undefined8 local_10;
  
  uVar1 = FUN_0028ec80();
  if (((int)uVar1 == 0) && (uVar1 = uVar1 & 0xffffffff, local_10 != 4)) {
    uVar1 = 6;
  }
  return uVar1;
}


// ===== 0028ed50 FUN_0028ed50 =====

undefined8 FUN_0028ed50(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = (**(code **)(*DAT_01218780 + 0x38))();
    return uVar1;
  }
  return 0xe;
}


// ===== 0028ed90 FUN_0028ed90 =====

ulong FUN_0028ed90(undefined8 param_1,undefined1 param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined1 local_1c [12];
  long local_10 [2];
  
  local_1c[0] = param_2;
  uVar1 = FUN_0028ed50(param_1,local_1c,param_3,1,local_10);
  if (((int)uVar1 == 0) && (uVar1 = uVar1 & 0xffffffff, local_10[0] != 1)) {
    uVar1 = 0x1c;
  }
  return uVar1;
}


// ===== 0028edd0 FUN_0028edd0 =====

ulong FUN_0028edd0(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined2 local_12;
  long local_10 [2];
  
  local_12 = param_2;
  uVar1 = FUN_0028ed50(param_1,&local_12,param_3,2,local_10);
  if (((int)uVar1 == 0) && (uVar1 = uVar1 & 0xffffffff, local_10[0] != 2)) {
    uVar1 = 0x1c;
  }
  return uVar1;
}


// ===== 0028ee10 FUN_0028ee10 =====

ulong FUN_0028ee10(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined4 local_14;
  long local_10 [2];
  
  local_14 = param_2;
  uVar1 = FUN_0028ed50(param_1,&local_14,param_3,4,local_10);
  if (((int)uVar1 == 0) && (uVar1 = uVar1 & 0xffffffff, local_10[0] != 4)) {
    uVar1 = 0x1c;
  }
  return uVar1;
}


// ===== 0028ee50 FUN_0028ee50 =====

void FUN_0028ee50(undefined8 param_1,uint param_2,uint param_3,undefined8 param_4)

{
  int iVar1;
  uint local_2c [3];
  
  iVar1 = FUN_0028ed20(param_1,local_2c,param_4);
  if (iVar1 == 0) {
    local_2c[0] = local_2c[0] & ~param_2 | param_3;
    FUN_0028ee10(param_1,local_2c[0],param_4);
  }
  return;
}


// ===== 0028eea0 FUN_0028eea0 =====

void FUN_0028eea0(long param_1)

{
  if ((param_1 != 0) && (*(code **)(*DAT_01218780 + 0x48) != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0028eebb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_01218780 + 0x48))();
    return;
  }
  return;
}


// ===== 0028eed0 FUN_0028eed0 =====

undefined8 FUN_0028eed0(undefined8 param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_2 < 0x100001) && (param_2 + param_3 < 0x100001)) {
    if (*(code **)(*DAT_01218780 + 0xa8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0028eefe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(*DAT_01218780 + 0xa8))();
      return uVar1;
    }
    return 0x26;
  }
  return 0x16;
}


// ===== 0028ef20 FUN_0028ef20 =====

undefined8 FUN_0028ef20(void)

{
  undefined8 uVar1;
  
  if (*(code **)(*DAT_01218780 + 0xb0) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0028ef39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0xb0))();
    return uVar1;
  }
  return 0x26;
}


// ===== 0028ef50 FUN_0028ef50 =====

void FUN_0028ef50(void)

{
  return;
}


// ===== 0028ef60 FUN_0028ef60 =====

void * FUN_0028ef60(ulong *param_1,ulong param_2,long param_3)

{
  code *pcVar1;
  ulong *puVar2;
  void *__ptr;
  long lVar3;
  int iVar4;
  ulong uVar5;
  
  pcVar1 = *(code **)(*DAT_01218780 + 0x60);
  if (pcVar1 != (code *)0x0) {
    iVar4 = 0;
    puVar2 = param_1;
    do {
      if (((((param_1[(long)iVar4 * 5 + 7] & 1) != 0) && (uVar5 = puVar2[5], uVar5 <= param_2)) &&
          (uVar5 = uVar5 + puVar2[6], param_2 <= uVar5)) && (param_2 + param_3 <= uVar5)) {
        __ptr = malloc(0x20);
        if (__ptr == (void *)0x0) {
          return (void *)0x0;
        }
        lVar3 = (*pcVar1)(__ptr,param_1,iVar4,param_2,param_3);
        if (lVar3 == 0) {
          free(__ptr);
          return (void *)0x0;
        }
        return __ptr;
      }
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 5;
    } while (iVar4 != 6);
  }
  return (void *)0x0;
}


// ===== 0028f020 FUN_0028f020 =====

void * FUN_0028f020(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  void *__ptr;
  long lVar2;
  
  pcVar1 = *(code **)(*DAT_01218780 + 0x68);
  if (pcVar1 != (code *)0x0) {
    __ptr = malloc(0x20);
    if (__ptr != (void *)0x0) {
      lVar2 = (*pcVar1)(__ptr,param_1,param_2,param_3);
      if (lVar2 != 0) {
        return __ptr;
      }
      free(__ptr);
    }
  }
  return (void *)0x0;
}


// ===== 0028f0a0 FUN_0028f0a0 =====

void FUN_0028f0a0(long param_1,void *param_2)

{
  if (((param_1 != 0) && (param_2 != (void *)0x0)) &&
     (*(code **)(*DAT_01218780 + 0x70) != (code *)0x0)) {
    (**(code **)(*DAT_01218780 + 0x70))();
  }
  free(param_2);
  return;
}


// ===== 0028f0d0 FUN_0028f0d0 =====

undefined8 FUN_0028f0d0(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if ((ulong)(param_2 + 4) <= *(ulong *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0028f0e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x78))();
    return uVar1;
  }
  return 0xffffffff;
}


// ===== 0028f100 FUN_0028f100 =====

undefined8 FUN_0028f100(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if ((ulong)(param_2 + 2) <= *(ulong *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0028f116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x80))();
    return uVar1;
  }
  return 0xffffffff;
}


// ===== 0028f130 FUN_0028f130 =====

undefined8 FUN_0028f130(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if ((ulong)(param_2 + 1) <= *(ulong *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0028f146. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*DAT_01218780 + 0x88))();
    return uVar1;
  }
  return 0xffffffff;
}


// ===== 0028f160 FUN_0028f160 =====

void FUN_0028f160(long param_1,int param_2)

{
  if ((ulong)(param_2 + 4) <= *(ulong *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0028f176. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_01218780 + 0x90))();
    return;
  }
  return;
}


// ===== 0028f190 FUN_0028f190 =====

void FUN_0028f190(long param_1,undefined8 param_2,undefined2 param_3)

{
  if ((ulong)((int)param_2 + 2) <= *(ulong *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0028f1a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_01218780 + 0x98))(param_1,param_2,param_3);
    return;
  }
  return;
}


// ===== 0028f1c0 FUN_0028f1c0 =====

void FUN_0028f1c0(long param_1,undefined8 param_2,undefined1 param_3)

{
  if ((ulong)((int)param_2 + 1) <= *(ulong *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0028f1d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_01218780 + 0xa0))(param_1,param_2,param_3);
    return;
  }
  return;
}


// ===== 0028f1f0 FUN_0028f1f0 =====

bool FUN_0028f1f0(long param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if (*(char *)(param_1 + 0x13) == '.') {
    bVar1 = false;
    if (*(char *)(param_1 + 0x14) != '\0') {
      if (*(char *)(param_1 + 0x14) == '.') {
        return *(char *)(param_1 + 0x15) != '\0';
      }
      return true;
    }
  }
  return bVar1;
}


// ===== 0028f220 FUN_0028f220 =====

void FUN_0028f220(void)

{
  return;
}


// ===== 0028f230 FUN_0028f230 =====

void FUN_0028f230(undefined8 param_1,void *param_2,size_t param_3)

{
  munmap(param_2,param_3);
  return;
}


// ===== 0028f240 FUN_0028f240 =====

void FUN_0028f240(undefined8 param_1,long param_2)

{
  if (-1 < *(int *)(param_2 + 0x18)) {
    close(*(int *)(param_2 + 0x18));
    return;
  }
  return;
}


// ===== 0028f260 FUN_0028f260 =====

int FUN_0028f260(long param_1,__off_t param_2,size_t param_3,uint param_4,undefined8 *param_5)

{
  int __fd;
  void *pvVar1;
  int *piVar2;
  int iVar3;
  char local_1038 [4104];
  
  iVar3 = (-(uint)((param_4 & 1) == 0) & 0xfffffffe) + 0x80002;
  if (param_1 != 0) {
    do {
      snprintf(local_1038,0x1000,"/sys/class/pci_bus/%04x:%02x/legacy_mem",
               (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2));
      __fd = open(local_1038,iVar3);
      if (-1 < __fd) goto LAB_0028f305;
      param_1 = FUN_0028e320(param_1);
    } while (param_1 != 0);
  }
  __fd = open("/dev/mem",iVar3);
  if (__fd < 0) {
    piVar2 = __errno_location();
    iVar3 = *piVar2;
  }
  else {
LAB_0028f305:
    iVar3 = 0;
    pvVar1 = mmap((void *)0x0,param_3,(-(uint)((param_4 & 1) == 0) & 0xfffffffe) + 3,1,__fd,param_2)
    ;
    *param_5 = pvVar1;
    if (pvVar1 == (void *)0xffffffffffffffff) {
      piVar2 = __errno_location();
      iVar3 = *piVar2;
    }
    close(__fd);
  }
  return iVar3;
}


// ===== 0028f380 FUN_0028f380 =====

undefined8 *
FUN_0028f380(undefined8 *param_1,long param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  int iVar1;
  char acStack_1028 [4104];
  
  snprintf(acStack_1028,0x1000,"%s/%04x:%02x:%02x.%1u/resource%d","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_2 + 0x124),(ulong)*(byte *)(param_2 + 2),
           (ulong)*(byte *)(param_2 + 3),(ulong)*(byte *)(param_2 + 4),param_3);
  iVar1 = open(acStack_1028,0x80002);
  *(int *)(param_1 + 3) = iVar1;
  if (iVar1 < 0) {
    param_1 = (undefined8 *)0x0;
  }
  else {
    *param_1 = param_4;
    param_1[1] = param_5;
    *(undefined4 *)((long)param_1 + 0x1c) = 0;
  }
  return param_1;
}


// ===== 0028f420 FUN_0028f420 =====

int FUN_0028f420(long param_1,long *param_2)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  ulong uVar5;
  ulong uVar6;
  uint __oflag;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  int __prot;
  long __offset;
  char local_138 [264];
  
  uVar1 = *(uint *)((long)param_2 + 0x14);
  uVar5 = (ulong)*(uint *)(param_2 + 2);
  uVar9 = (ulong)*(byte *)(param_1 + 2);
  uVar7 = (ulong)*(byte *)(param_1 + 4);
  uVar8 = (ulong)*(uint *)(param_1 + 0x124);
  __offset = *param_2 - *(long *)(param_1 + 0x28 + uVar5 * 0x28);
  __oflag = uVar1 * 2 & 2 | 0x80000;
  __prot = (-(uint)((uVar1 & 1) == 0) & 0xfffffffe) + 3;
  uVar6 = (ulong)*(byte *)(param_1 + 3);
  if ((uVar1 & 2) != 0) {
    snprintf(local_138,0xff,"%s/%04x:%02x:%02x.%1u/resource%u_wc","/sys/bus/pci/devices",uVar8,uVar9
             ,uVar6,uVar7,uVar5);
    iVar2 = open(local_138,__oflag);
    if (iVar2 != -1) {
      pvVar3 = mmap((void *)0x0,param_2[1],__prot,1,iVar2,__offset);
      param_2[3] = (long)pvVar3;
      if (pvVar3 != (void *)0xffffffffffffffff) {
        close(iVar2);
        return 0;
      }
      param_2[3] = 0;
      close(iVar2);
    }
    piVar4 = __errno_location();
    if (*piVar4 == 0) {
      return 0;
    }
    uVar7 = (ulong)*(byte *)(param_1 + 4);
    uVar6 = (ulong)*(byte *)(param_1 + 3);
    uVar9 = (ulong)*(byte *)(param_1 + 2);
    uVar5 = (ulong)*(uint *)(param_2 + 2);
    uVar8 = (ulong)*(uint *)(param_1 + 0x124);
  }
  snprintf(local_138,0xff,"%s/%04x:%02x:%02x.%1u/resource%u","/sys/bus/pci/devices",uVar8,uVar9,
           uVar6,uVar7,uVar5);
  iVar2 = open(local_138,__oflag);
  if (iVar2 != -1) {
    pvVar3 = mmap((void *)0x0,param_2[1],__prot,1,iVar2,__offset);
    param_2[3] = (long)pvVar3;
    if (pvVar3 != (void *)0xffffffffffffffff) {
      close(iVar2);
      return 0;
    }
    param_2[3] = 0;
    close(iVar2);
  }
  piVar4 = __errno_location();
  return *piVar4;
}


// ===== 0028f5f0 FUN_0028f5f0 =====

ulong FUN_0028f5f0(long *param_1,ulong param_2,ulong param_3)

{
  int __fd;
  ulong uVar1;
  undefined1 local_c [12];
  
  __fd = (int)param_1[3];
  local_c[0] = (undefined1)param_3;
  if (__fd < 0) {
    out((short)*param_1 + (short)param_2,(char)(param_3 & 0xffffffff));
    return param_3 & 0xffffffff;
  }
  if (*(int *)((long)param_1 + 0x1c) == 0) {
    uVar1 = pwrite(__fd,local_c,1,param_2 & 0xffffffff);
    return uVar1;
  }
  uVar1 = pwrite(__fd,local_c,1,(param_2 & 0xffffffff) + *param_1);
  return uVar1;
}


// ===== 0028f650 FUN_0028f650 =====

ulong FUN_0028f650(long *param_1,ulong param_2,ulong param_3)

{
  int __fd;
  ulong uVar1;
  undefined2 local_c [6];
  
  __fd = (int)param_1[3];
  local_c[0] = (undefined2)param_3;
  if (__fd < 0) {
    out((short)*param_1 + (short)param_2,(short)(param_3 & 0xffffffff));
    return param_3 & 0xffffffff;
  }
  if (*(int *)((long)param_1 + 0x1c) == 0) {
    uVar1 = pwrite(__fd,local_c,2,param_2 & 0xffffffff);
    return uVar1;
  }
  uVar1 = pwrite(__fd,local_c,2,(param_2 & 0xffffffff) + *param_1);
  return uVar1;
}


// ===== 0028f6b0 FUN_0028f6b0 =====

ulong FUN_0028f6b0(long *param_1,ulong param_2,uint param_3)

{
  int __fd;
  ulong uVar1;
  uint local_c [3];
  
  __fd = (int)param_1[3];
  if (__fd < 0) {
    out((short)*param_1 + (short)param_2,param_3);
    return (ulong)param_3;
  }
  local_c[0] = param_3;
  if (*(int *)((long)param_1 + 0x1c) == 0) {
    uVar1 = pwrite(__fd,local_c,4,param_2 & 0xffffffff);
    return uVar1;
  }
  uVar1 = pwrite(__fd,local_c,4,*param_1 + (param_2 & 0xffffffff));
  return uVar1;
}


// ===== 0028f710 FUN_0028f710 =====

undefined1 FUN_0028f710(long *param_1,ulong param_2)

{
  int __fd;
  undefined1 uVar1;
  undefined1 local_9 [9];
  
  __fd = (int)param_1[3];
  if (__fd < 0) {
    uVar1 = in((short)*param_1 + (short)param_2);
    return uVar1;
  }
  if (*(int *)((long)param_1 + 0x1c) == 0) {
    pread(__fd,local_9,1,param_2 & 0xffffffff);
    return local_9[0];
  }
  pread(__fd,local_9,1,*param_1 + (param_2 & 0xffffffff));
  return local_9[0];
}


// ===== 0028f770 FUN_0028f770 =====

undefined2 FUN_0028f770(long *param_1,ulong param_2)

{
  int __fd;
  undefined2 uVar1;
  undefined2 local_a [5];
  
  __fd = (int)param_1[3];
  if (__fd < 0) {
    uVar1 = in((short)*param_1 + (short)param_2);
    return uVar1;
  }
  if (*(int *)((long)param_1 + 0x1c) == 0) {
    pread(__fd,local_a,2,param_2 & 0xffffffff);
    return local_a[0];
  }
  pread(__fd,local_a,2,*param_1 + (param_2 & 0xffffffff));
  return local_a[0];
}


// ===== 0028f7d0 FUN_0028f7d0 =====

undefined4 FUN_0028f7d0(long *param_1,ulong param_2)

{
  int __fd;
  undefined4 uVar1;
  undefined4 local_c [3];
  
  __fd = (int)param_1[3];
  if (__fd < 0) {
    uVar1 = in((short)*param_1 + (short)param_2);
    return uVar1;
  }
  if (*(int *)((long)param_1 + 0x1c) == 0) {
    pread(__fd,local_c,4,param_2 & 0xffffffff);
    return local_c[0];
  }
  pread(__fd,local_c,4,*param_1 + (param_2 & 0xffffffff));
  return local_c[0];
}


// ===== 0028f830 FUN_0028f830 =====

undefined8 * FUN_0028f830(undefined8 *param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  char acStack_1038 [4104];
  
  for (; param_2 != 0; param_2 = FUN_0028e320(param_2)) {
    snprintf(acStack_1038,0x1000,"/sys/class/pci_bus/%04x:%02x/legacy_io",
             (ulong)*(uint *)(param_2 + 0x124),(ulong)*(byte *)(param_2 + 2));
    iVar1 = open(acStack_1038,0x80002);
    *(int *)(param_1 + 3) = iVar1;
    if (-1 < iVar1) goto LAB_0028f8ab;
  }
  if ((*(int *)(param_1 + 3) < 0) && (iVar1 = iopl(3), iVar1 != 0)) {
    param_1 = (undefined8 *)0x0;
  }
  else {
LAB_0028f8ab:
    *param_1 = param_3;
    param_1[1] = param_4;
    *(undefined4 *)((long)param_1 + 0x1c) = 1;
  }
  return param_1;
}


// ===== 0028f8f0 FUN_0028f8f0 =====

bool FUN_0028f8f0(long param_1)

{
  int __fd;
  ssize_t sVar1;
  bool bVar2;
  char local_11b [3];
  char local_118 [264];
  
  bVar2 = false;
  snprintf(local_118,0xff,"%s/%04x:%02x:%02x.%1u/boot_vga","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2),
           (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)(param_1 + 4));
  __fd = open(local_118,0x80000);
  if (__fd != -1) {
    sVar1 = read(__fd,local_11b,1);
    bVar2 = (int)sVar1 == 1 && local_11b[0] == '1';
    close(__fd);
  }
  return bVar2;
}


// ===== 0028f990 FUN_0028f990 =====

void FUN_0028f990(long param_1)

{
  int __fd;
  char acStack_108 [256];
  
  snprintf(acStack_108,0xff,"%s/%04x:%02x:%02x.%1u/enable","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2),
           (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)(param_1 + 4));
  __fd = open(acStack_108,0x80002);
  if (__fd != -1) {
    write(__fd,"1",1);
    close(__fd);
  }
  return;
}


// ===== 0028fa10 FUN_0028fa10 =====

int FUN_0028fa10(long param_1,void *param_2,long param_3,size_t param_4,long *param_5)

{
  int __fd;
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  size_t __n;
  char acStack_138 [264];
  
  if (param_5 != (long *)0x0) {
    *param_5 = 0;
  }
  snprintf(acStack_138,0xff,"%s/%04x:%02x:%02x.%1u/config","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2),
           (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)(param_1 + 4));
  __fd = open(acStack_138,0x80001);
  __n = param_4;
  if (__fd == -1) {
    piVar2 = __errno_location();
    iVar3 = *piVar2;
  }
  else {
    for (; __n != 0; __n = __n - sVar1) {
      sVar1 = pwrite64(__fd,param_2,__n,param_3);
      if (sVar1 == 0) {
        iVar3 = 0;
        goto LAB_0028fabd;
      }
      if (sVar1 < 0) {
        piVar2 = __errno_location();
        iVar3 = *piVar2;
        goto LAB_0028fabd;
      }
      param_3 = param_3 + sVar1;
      param_2 = (void *)((long)param_2 + sVar1);
    }
    __n = 0;
    iVar3 = 0;
LAB_0028fabd:
    if (param_5 != (long *)0x0) {
      *param_5 = param_4 - __n;
    }
    close(__fd);
  }
  return iVar3;
}


// ===== 0028fb10 FUN_0028fb10 =====

int FUN_0028fb10(long param_1,void *param_2,long param_3,size_t param_4,long *param_5)

{
  int __fd;
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  size_t __nbytes;
  char acStack_138 [264];
  
  if (param_5 != (long *)0x0) {
    *param_5 = 0;
  }
  snprintf(acStack_138,0xff,"%s/%04x:%02x:%02x.%1u/config","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2),
           (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)(param_1 + 4));
  __fd = open(acStack_138,0x80000);
  __nbytes = param_4;
  if (__fd == -1) {
    piVar2 = __errno_location();
    iVar3 = *piVar2;
  }
  else {
    for (; __nbytes != 0; __nbytes = __nbytes - sVar1) {
      sVar1 = pread64(__fd,param_2,__nbytes,param_3);
      if (sVar1 == 0) {
        iVar3 = 0;
        goto LAB_0028fbbd;
      }
      if (sVar1 < 0) {
        piVar2 = __errno_location();
        iVar3 = *piVar2;
        goto LAB_0028fbbd;
      }
      param_3 = param_3 + sVar1;
      param_2 = (void *)((long)param_2 + sVar1);
    }
    __nbytes = 0;
    iVar3 = 0;
LAB_0028fbbd:
    if (param_5 != (long *)0x0) {
      *param_5 = param_4 - __nbytes;
    }
    close(__fd);
  }
  return iVar3;
}


// ===== 0028fc10 thunk_FUN_00291520 =====

int thunk_FUN_00291520(undefined8 param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = munmap(*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8));
  iVar3 = 0;
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    iVar3 = *piVar2;
  }
  return iVar3;
}


// ===== 0028fc20 FUN_0028fc20 =====

undefined4 FUN_0028fc20(ulonglong *param_1)

{
  ulonglong *puVar1;
  undefined4 uVar2;
  int __fd;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  uint uVar6;
  ulong uVar7;
  ulong local_448;
  char *local_440;
  char local_438 [256];
  undefined1 local_338 [14];
  undefined1 local_32a;
  byte local_2fc;
  char local_238 [511];
  undefined1 local_39;
  
  uVar2 = FUN_0028fb10(param_1,local_338,0,0x100,&local_448);
  if (0x3f < local_448) {
    *(uint *)(param_1 + 0x22) = (uint)local_2fc;
    *(undefined1 *)(param_1 + 0x26) = local_32a;
    snprintf(local_438,0xff,"%s/%04x:%02x:%02x.%1u/resource","/sys/bus/pci/devices",
             (ulong)*(uint *)((long)param_1 + 0x124),(ulong)*(byte *)((long)param_1 + 2),
             (ulong)*(byte *)((long)param_1 + 3),(ulong)*(byte *)((long)param_1 + 4));
    __fd = open(local_438,0x80000);
    if (__fd != -1) {
      local_448 = read(__fd,local_238,0x200);
      local_39 = 0;
      close(__fd);
      uVar7 = 0;
      puVar1 = param_1;
      local_440 = local_238;
      do {
        puVar5 = puVar1 + 5;
        uVar3 = strtoull(local_440,&local_440,0x10);
        *puVar5 = uVar3;
        uVar3 = strtoull(local_440,&local_440,0x10);
        uVar4 = strtoull(local_440,&local_440,0x10);
        if (*puVar5 != 0) {
          puVar1[6] = (uVar3 + 1) - *puVar5;
          *(byte *)(param_1 + uVar7 * 5 + 7) = (byte)param_1[uVar7 * 5 + 7] & 0xf8 | (byte)uVar4 & 1
          ;
        }
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulong)uVar6;
        puVar1 = puVar5;
      } while (uVar6 != 6);
      uVar3 = strtoull(local_440,&local_440,0x10);
      uVar4 = strtoull(local_440,&local_440,0x10);
      strtoull(local_440,&local_440,0x10);
      if (uVar3 != 0) {
        param_1[0x28] = uVar3;
        param_1[0x21] = (uVar4 + 1) - uVar3;
      }
    }
  }
  return uVar2;
}


// ===== 0028fe00 FUN_0028fe00 =====

int FUN_0028fe00(long param_1,long param_2)

{
  int __fildes;
  int iVar1;
  ssize_t sVar2;
  int *piVar3;
  ulong uVar4;
  ulong uVar5;
  stat sStack_1b8;
  char local_128 [264];
  
  snprintf(local_128,0xff,"%s/%04x:%02x:%02x.%1u/rom","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2),
           (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)(param_1 + 4));
  __fildes = open(local_128,0x80002);
  if (__fildes != -1) {
    iVar1 = __fxstat(1,__fildes,&sStack_1b8);
    if (iVar1 != -1) {
      uVar5 = sStack_1b8.st_size;
      if (sStack_1b8.st_size == 0) {
        uVar5 = 0x10000;
      }
      uVar4 = 0;
      write(__fildes,"1",1);
      lseek(__fildes,0,0);
      do {
        sVar2 = read(__fildes,(void *)(param_2 + uVar4),uVar5 - uVar4);
        iVar1 = (int)sVar2;
        if (iVar1 == -1) {
          piVar3 = __errno_location();
          iVar1 = *piVar3;
          goto LAB_0028fed7;
        }
      } while ((iVar1 != 0) && (uVar4 = uVar4 + (long)iVar1, uVar4 < uVar5));
      iVar1 = 0;
LAB_0028fed7:
      lseek(__fildes,0,0);
      write(__fildes,"0",1);
      close(__fildes);
      return iVar1;
    }
    close(__fildes);
  }
  piVar3 = __errno_location();
  return *piVar3;
}


// ===== 0028ff40 FUN_0028ff40 =====

uint FUN_0028ff40(long param_1)

{
  uint uVar1;
  stat local_198;
  char local_108 [256];
  
  snprintf(local_108,0xff,"%s/%04x:%02x:%02x.%1u/driver","/sys/bus/pci/devices",
           (ulong)*(uint *)(param_1 + 0x124),(ulong)*(byte *)(param_1 + 2),
           (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)(param_1 + 4));
  uVar1 = __xstat(1,local_108,&local_198);
  return ~uVar1 >> 0x1f;
}


// ===== 0028ffb0 FUN_0028ffb0 =====

int FUN_0028ffb0(void)

{
  undefined2 *puVar1;
  undefined8 *puVar2;
  undefined *__cmp;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined8 *puVar7;
  void *pvVar8;
  ulong uVar9;
  ulonglong uVar10;
  char *pcVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long local_460;
  long local_458;
  uint local_420;
  uint local_410;
  uint local_40c;
  uint local_408;
  uint local_404;
  dirent **local_400;
  ulonglong local_3f8 [2];
  uint local_3e8;
  undefined8 local_3e0;
  undefined8 local_3d8;
  undefined8 local_3d0;
  stat local_3c8;
  long local_338 [32];
  byte local_238;
  byte local_237;
  byte local_236;
  byte local_235;
  undefined1 local_230;
  byte local_22f;
  byte local_22e;
  byte local_22d;
  byte local_20c;
  byte local_20b;
  byte local_20a;
  byte local_209;
  undefined1 local_39;
  
  iVar3 = __xstat(1,"/sys/bus/pci/devices",&local_3c8);
  if (iVar3 == 0) {
    puVar7 = calloc(1,0x30);
    __cmp = PTR_alphasort_0032ef68;
    DAT_01218780 = puVar7;
    if (puVar7 == (undefined8 *)0x0) {
      iVar3 = 0xc;
    }
    else {
      local_400 = (dirent **)0x0;
      *puVar7 = &PTR_FUN_0032ebe0;
      iVar4 = scandir("/sys/bus/pci/devices",&local_400,FUN_0028f1f0,(__cmp *)__cmp);
      iVar3 = 0;
      if (iVar4 < 1) {
        free(local_400);
      }
      else {
        puVar7[1] = (long)iVar4;
        pvVar8 = calloc((long)iVar4,0x160);
        puVar7[2] = pvVar8;
        if (pvVar8 != (void *)0x0) {
          local_458 = 0;
          local_460 = 0;
          do {
            puVar1 = (undefined2 *)((long)pvVar8 + local_460);
            sscanf((char *)(*(long *)((long)local_400 + local_458) + 0x13),"%x:%02x:%02x.%1u",
                   &local_410,&local_40c,&local_408,&local_404);
            uVar14 = (ulong)local_410;
            *(uint *)(puVar1 + 0x92) = local_410;
            uVar9 = 0xffffffff;
            if (local_410 < 0x10000) {
              uVar9 = uVar14;
            }
            *puVar1 = (short)uVar9;
            *(char *)(puVar1 + 1) = (char)local_40c;
            uVar15 = (ulong)(local_40c & 0xff);
            *(char *)((long)puVar1 + 3) = (char)local_408;
            uVar12 = (ulong)(local_408 & 0xff);
            *(char *)(puVar1 + 2) = (char)local_404;
            uVar9 = (ulong)(local_404 & 0xff);
            pcVar11 = "vendor";
            lVar13 = 0;
            while( true ) {
              snprintf((char *)local_338,0xff,"%s/%04x:%02x:%02x.%1u/%s","/sys/bus/pci/devices",
                       uVar14,uVar15,uVar12,uVar9,pcVar11);
              iVar5 = open((char *)local_338,0x80000);
              if (iVar5 == -1) break;
              read(iVar5,&local_238,0x200);
              local_39 = 0;
              close(iVar5);
              uVar10 = strtoull((char *)&local_238,(char **)0x0,0x10);
              *(ulonglong *)((long)local_3f8 + lVar13) = uVar10;
              if (lVar13 + 8 == 0x30) {
                puVar1[3] = (short)local_3f8[0];
                puVar1[4] = (short)local_3f8[1];
                *(uint *)(puVar1 + 8) = local_3e8 & 0xffffff;
                *(char *)(puVar1 + 10) = (char)local_3e0;
                puVar1[5] = (short)local_3d8;
                puVar1[6] = (short)local_3d0;
                goto LAB_0029028a;
              }
              uVar12 = (ulong)*(byte *)((long)puVar1 + 3);
              uVar15 = (ulong)*(byte *)(puVar1 + 1);
              uVar14 = (ulong)*(uint *)(puVar1 + 0x92);
              pcVar11 = *(char **)((long)&PTR_s_device_002f5e76_0xa_00329728 + lVar13);
              uVar9 = (ulong)*(byte *)(puVar1 + 2);
              lVar13 = lVar13 + 8;
            }
            piVar6 = __errno_location();
            if (*piVar6 != 0) {
              iVar5 = FUN_0028fb10(puVar1,&local_238,0,0x30,local_338);
              if (local_338[0] == 0x30) {
                if (iVar5 != 0) goto LAB_00290307;
                puVar1[3] = (ushort)local_237 * 0x100 + (ushort)local_238;
                puVar1[4] = (ushort)local_235 * 0x100 + (ushort)local_236;
                *(uint *)(puVar1 + 8) =
                     (uint)local_22d * 0x10000 + (uint)local_22e * 0x100 + (uint)local_22f;
                *(undefined1 *)(puVar1 + 10) = local_230;
                puVar1[5] = (ushort)local_20b * 0x100 + (ushort)local_20c;
                puVar1[6] = (ushort)local_209 * 0x100 + (ushort)local_20a;
              }
              else if (iVar5 != 0) goto LAB_00290307;
            }
LAB_0029028a:
            local_460 = local_460 + 0x160;
            local_458 = local_458 + 8;
            iVar5 = iVar3;
            if (((ulong)(iVar4 - 1) + 1) * 0x160 == local_460) goto LAB_00290307;
            pvVar8 = (void *)puVar7[2];
          } while( true );
        }
        iVar5 = 0xc;
LAB_00290307:
        iVar3 = iVar5;
        local_420 = iVar4 - 1;
        lVar13 = 0;
        do {
          puVar2 = (undefined8 *)((long)local_400 + lVar13);
          lVar13 = lVar13 + 8;
          free((void *)*puVar2);
        } while ((ulong)local_420 * 8 + 8 != lVar13);
        free(local_400);
        if (iVar3 != 0) {
          free((void *)puVar7[2]);
          puVar7[2] = 0;
        }
      }
    }
  }
  else {
    piVar6 = __errno_location();
    iVar3 = *piVar6;
  }
  return iVar3;
}


// ===== 00290440 FUN_00290440 =====

undefined1  [16]
FUN_00290440(uint param_1,uint param_2,undefined8 param_3,ulong param_4,undefined4 *param_5,
            uint param_6)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  undefined1 auVar6 [16];
  
  if ((((param_1 < 0x100) && (param_2 < 0x20)) && ((uint)param_3 < 8)) &&
     (((param_4 < 0x100 && (param_6 < 5)) && (param_6 != 3)))) {
    sVar5 = ((ushort)param_4 & 3) + 0xcfc;
    uVar3 = in(0xcf8);
    out(0xcf8,(uint)param_3 << 8 | 0x80000000 | param_2 << 0xb | param_1 << 0x10 |
              (uint)param_4 & 0xfffffffc);
    if (param_6 == 2) {
      uVar2 = in(sVar5);
      *(undefined2 *)param_5 = uVar2;
    }
    else if (param_6 == 4) {
      uVar4 = in(sVar5);
      *param_5 = uVar4;
    }
    else if (param_6 == 1) {
      uVar1 = in(sVar5);
      *(undefined1 *)param_5 = uVar1;
    }
    out(0xcf8,uVar3);
    return ZEXT816(0xcf8) << 0x40;
  }
  auVar6._8_8_ = param_3;
  auVar6._0_8_ = 5;
  return auVar6;
}


// ===== 002904f0 FUN_002904f0 =====

undefined1  [16]
FUN_002904f0(uint param_1,uint param_2,undefined8 param_3,ulong param_4,undefined4 *param_5,
            uint param_6)

{
  undefined4 uVar1;
  short sVar2;
  undefined1 auVar3 [16];
  
  if ((((param_1 < 0x100) && (param_2 < 0x20)) && ((uint)param_3 < 8)) &&
     (((param_4 < 0x100 && (param_6 < 5)) && (param_6 != 3)))) {
    sVar2 = ((ushort)param_4 & 3) + 0xcfc;
    uVar1 = in(0xcf8);
    out(0xcf8,(uint)param_3 << 8 | 0x80000000 | param_2 << 0xb | param_1 << 0x10 |
              (uint)param_4 & 0xfffffffc);
    if (param_6 == 2) {
      out(sVar2,*(undefined2 *)param_5);
    }
    else if (param_6 == 4) {
      out(sVar2,*param_5);
    }
    else if (param_6 == 1) {
      out(sVar2,*(undefined1 *)param_5);
    }
    out(0xcf8,uVar1);
    return ZEXT816(0xcf8) << 0x40;
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = 5;
  return auVar3;
}


// ===== 002905b0 FUN_002905b0 =====

undefined1  [16]
FUN_002905b0(uint param_1,uint param_2,undefined8 param_3,ulong param_4,undefined4 *param_5,
            int param_6)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  
  if ((((param_1 < 0x100) && (param_2 < 0x10)) && ((uint)param_3 < 8)) && (param_4 < 0x100)) {
    uVar1 = (ushort)(param_2 << 8) | (ushort)param_4;
    out(0xcf8,(char)param_3 * '\x02' | 0xf0);
    out(0xcfa,(char)param_1);
    if (param_6 == 2) {
      uVar3 = in(uVar1 | 0xc000);
      uVar5 = 0;
      *(undefined2 *)param_5 = uVar3;
    }
    else if (param_6 == 4) {
      uVar4 = in(uVar1 | 0xc000);
      uVar5 = 0;
      *param_5 = uVar4;
    }
    else {
      uVar5 = 5;
      if (param_6 == 1) {
        uVar2 = in(uVar1 | 0xc000);
        uVar5 = 0;
        *(undefined1 *)param_5 = uVar2;
      }
    }
    out(0xcf8,0);
    auVar6._8_8_ = 0xcf8;
    auVar6._0_8_ = uVar5;
    return auVar6;
  }
  auVar7._8_8_ = param_3;
  auVar7._0_8_ = 5;
  return auVar7;
}


// ===== 00290660 FUN_00290660 =====

undefined1  [16]
FUN_00290660(uint param_1,uint param_2,undefined8 param_3,ulong param_4,undefined4 *param_5,
            int param_6)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  if ((((param_1 < 0x100) && (param_2 < 0x10)) && ((uint)param_3 < 8)) && (param_4 < 0x100)) {
    uVar1 = (ushort)(param_2 << 8) | (ushort)param_4;
    out(0xcf8,(char)param_3 * '\x02' | 0xf0);
    out(0xcfa,(char)param_1);
    if (param_6 == 2) {
      out(uVar1 | 0xc000,*(undefined2 *)param_5);
      uVar2 = 0;
    }
    else if (param_6 == 4) {
      out(uVar1 | 0xc000,*param_5);
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
      if (param_6 == 1) {
        out(uVar1 | 0xc000,*(undefined1 *)param_5);
        uVar2 = 0;
      }
    }
    out(0xcf8,0);
    auVar3._8_8_ = 0xcf8;
    auVar3._0_8_ = uVar2;
    return auVar3;
  }
  auVar4._8_8_ = param_3;
  auVar4._0_8_ = 5;
  return auVar4;
}


// ===== 00290720 FUN_00290720 =====

undefined8 FUN_00290720(long param_1,long param_2,long param_3,ulong param_4,long *param_5)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  
  lVar1 = DAT_01218780;
  *param_5 = 0;
  while( true ) {
    if (param_4 == 0) {
      return 0;
    }
    iVar5 = 4;
    uVar4 = 4;
    if (param_4 < 4) {
      iVar5 = (int)param_4;
      uVar4 = param_4;
    }
    uVar2 = (uint)param_3 & 3;
    if (4 - (ulong)uVar2 < uVar4) {
      iVar5 = 4 - uVar2;
    }
    uVar3 = (**(code **)(lVar1 + 0x38))
                      (*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3),
                       *(undefined1 *)(param_1 + 4),param_3,param_2,iVar5);
    if ((int)uVar3 != 0) break;
    lVar6 = (long)iVar5;
    *param_5 = *param_5 + lVar6;
    param_3 = param_3 + lVar6;
    param_2 = param_2 + lVar6;
    param_4 = param_4 - lVar6;
  }
  return uVar3;
}


// ===== 002907f0 FUN_002907f0 =====

void FUN_002907f0(void)

{
  return;
}


// ===== 00290800 FUN_00290800 =====

undefined4 FUN_00290800(short *param_1,short param_2)

{
  undefined4 uVar1;
  
  uVar1 = in(*param_1 + param_2);
  return uVar1;
}


// ===== 00290810 FUN_00290810 =====

undefined2 FUN_00290810(short *param_1,short param_2)

{
  undefined2 uVar1;
  
  uVar1 = in(*param_1 + param_2);
  return uVar1;
}


// ===== 00290820 FUN_00290820 =====

undefined1 FUN_00290820(short *param_1,short param_2)

{
  undefined1 uVar1;
  
  uVar1 = in(*param_1 + param_2);
  return uVar1;
}


// ===== 00290830 FUN_00290830 =====

undefined4 FUN_00290830(short *param_1,short param_2,undefined4 param_3)

{
  out(*param_1 + param_2,param_3);
  return param_3;
}


// ===== 00290840 FUN_00290840 =====

undefined4 FUN_00290840(short *param_1,short param_2,undefined4 param_3)

{
  out(*param_1 + param_2,(short)param_3);
  return param_3;
}


// ===== 00290850 FUN_00290850 =====

undefined4 FUN_00290850(short *param_1,short param_2,undefined4 param_3)

{
  out(*param_1 + param_2,(char)param_3);
  return param_3;
}


// ===== 00290860 FUN_00290860 =====

undefined8 FUN_00290860(long param_1,long param_2,long param_3,ulong param_4,long *param_5)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  
  lVar3 = DAT_01218780;
  *param_5 = 0;
  while( true ) {
    if (param_4 == 0) {
      return 0;
    }
    bVar1 = 0;
    for (uVar2 = ((uint)param_3 & 3) + 4; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
      bVar1 = bVar1 + 1;
    }
    iVar5 = 1 << (bVar1 & 0x1f);
    if (param_4 < (ulong)(long)iVar5) {
      iVar5 = (int)param_4;
    }
    uVar4 = (**(code **)(lVar3 + 0x30))
                      (*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3),
                       *(undefined1 *)(param_1 + 4),param_3,param_2,iVar5);
    if ((int)uVar4 != 0) break;
    lVar6 = (long)iVar5;
    *param_5 = *param_5 + lVar6;
    param_3 = param_3 + lVar6;
    param_2 = param_2 + lVar6;
    param_4 = param_4 - lVar6;
  }
  return uVar4;
}


// ===== 00290920 thunk_FUN_00291520 =====

int thunk_FUN_00291520(undefined8 param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = munmap(*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8));
  iVar3 = 0;
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    iVar3 = *piVar2;
  }
  return iVar3;
}


// ===== 00290930 FUN_00290930 =====

void FUN_00290930(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStack_28 [8];
  undefined8 local_20;
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = 0;
  local_20 = param_3;
  local_10 = param_2;
  FUN_00291520(param_1,auStack_28);
  return;
}


// ===== 00290960 FUN_00290960 =====

int FUN_00290960(long param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  long lVar10;
  byte local_46;
  byte local_45;
  uint local_44;
  uint local_40;
  undefined4 local_3c [3];
  
  iVar3 = FUN_0028ecc0(param_1,&local_46,0x3c);
  if (iVar3 == 0) {
    *(uint *)(param_1 + 0x110) = (uint)local_46;
    iVar3 = FUN_0028ecc0(param_1,&local_45,0xe);
    if (iVar3 == 0) {
      iVar3 = 0;
      iVar9 = 0x10;
      do {
        bVar2 = local_45 & 0x7f;
        if (bVar2 == 1) {
          iVar4 = 2;
        }
        else if (bVar2 == 0) {
          iVar4 = 6;
        }
        else {
          if (bVar2 != 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,"unknown header type %02x\n");
LAB_00290b10:
            if ((*(uint *)(param_1 + 0x10) & 0xffff00) != 0x30000) {
              return 0;
            }
            *(undefined8 *)(param_1 + 0x108) = 0x10000;
            return 0;
          }
          iVar4 = 1;
        }
        if (iVar4 <= iVar3) goto LAB_00290b10;
        lVar10 = (long)iVar9;
        iVar4 = iVar9 + 4;
        iVar5 = FUN_0028ed20(param_1,&local_44,lVar10);
        if ((iVar5 == 0) && (iVar5 = FUN_0028ee10(param_1,0xffffffff,lVar10), iVar5 == 0)) {
          FUN_0028ed20(param_1,&local_40,lVar10);
          FUN_0028ee10(param_1,local_44,lVar10);
          lVar10 = (long)iVar3;
          if ((local_44 & 1) != 0) {
            pbVar1 = (byte *)(param_1 + 0x38 + lVar10 * 0x28);
            *pbVar1 = *pbVar1 | 1;
          }
          if ((local_44 & 4) != 0) {
            pbVar1 = (byte *)(param_1 + 0x38 + lVar10 * 0x28);
            *pbVar1 = *pbVar1 | 4;
          }
          if ((local_44 & 8) != 0) {
            pbVar1 = (byte *)(param_1 + 0x38 + lVar10 * 0x28);
            *pbVar1 = *pbVar1 | 2;
          }
          uVar8 = 0;
          if (local_40 != 0) {
            uVar7 = local_40 & 0xfffffff0;
            if ((local_40 & 1) != 0) {
              uVar7 = local_40 & 0xfffffffc;
            }
            uVar6 = (ulong)uVar7;
            if (uVar7 != 0) {
              uVar7 = 1;
              do {
                uVar6 = uVar6 >> 1;
                uVar7 = uVar7 * 2;
              } while ((uVar6 & 1) == 0);
              uVar8 = (ulong)uVar7;
            }
          }
          lVar10 = param_1 + lVar10 * 0x28;
          *(ulong *)(lVar10 + 0x30) = uVar8;
          if ((*(byte *)(lVar10 + 0x38) & 4) == 0) {
            uVar7 = local_44 & 0xfffffff0;
            if ((local_44 & 1) != 0) {
              uVar7 = local_44 & 0xfffffffc;
            }
            *(ulong *)(lVar10 + 0x28) = (ulong)uVar7;
          }
          else {
            iVar5 = FUN_0028ed20(param_1,local_3c,(long)iVar4);
            if (iVar5 == 0) {
              uVar7 = local_44 & 0xfffffff0;
              if ((local_44 & 1) != 0) {
                uVar7 = local_44 & 0xfffffffc;
              }
              iVar3 = iVar3 + 1;
              *(ulong *)(lVar10 + 0x28) = CONCAT44(local_3c[0],uVar7);
              iVar4 = iVar9 + 8;
            }
          }
        }
        iVar9 = iVar4;
        iVar3 = iVar3 + 1;
      } while( true );
    }
  }
  return iVar3;
}


// ===== 00290bc0 FUN_00290bc0 =====

undefined4 FUN_00290bc0(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  short local_2c;
  short local_2a;
  
  iVar2 = 0;
  do {
    iVar1 = (*(code *)*param_1)(0,iVar2,0,10,&local_2c,2);
    if (iVar1 == 0) {
      if (local_2c == 0x600) {
        return 0;
      }
      if (local_2c == 0x300) {
        return 0;
      }
      iVar1 = (*(code *)*param_1)(0,iVar2,0,0,&local_2a,2);
      if (iVar1 == 0) {
        if (local_2a == -0x7f7a) {
          return 0;
        }
        if (local_2c == 0xe11) {
          return 0;
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x20) {
      return 0x13;
    }
  } while( true );
}


// ===== 00290c60 FUN_00290c60 =====

int FUN_00290c60(long param_1,void *param_2)

{
  int __fd;
  uint uVar1;
  int iVar2;
  void *__src;
  int *piVar3;
  
  if ((*(uint *)(param_1 + 0x10) & 0xffff00) != 0x30000) {
    return 0x26;
  }
  __fd = open("/dev/mem",0);
  if (__fd < 0) {
    if (__fd == -1) goto LAB_00290d3d;
LAB_00290cd9:
    __src = mmap((void *)0x0,*(size_t *)(param_1 + 0x108),1,0,__fd,0xc0000);
    if (__src != (void *)0xffffffffffffffff) {
      memcpy(param_2,__src,*(size_t *)(param_1 + 0x108));
      munmap(__src,*(size_t *)(param_1 + 0x108));
      close(__fd);
      return 0;
    }
  }
  else {
    uVar1 = fcntl(__fd,1);
    if (uVar1 != 0xffffffff) {
      iVar2 = fcntl(__fd,2,(ulong)(uVar1 | 1));
      if (iVar2 != -1) goto LAB_00290cd9;
    }
  }
  close(__fd);
LAB_00290d3d:
  piVar3 = __errno_location();
  return *piVar3;
}


// ===== 00290d60 FUN_00290d60 =====

int FUN_00290d60(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = iopl(0);
  iVar2 = 0;
  if (iVar1 != 0) {
    piVar3 = __errno_location();
    iVar2 = *piVar3;
  }
  return iVar2;
}


// ===== 00290d80 thunk_FUN_00290d60 =====

int thunk_FUN_00290d60(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = iopl(0);
  iVar2 = 0;
  if (iVar1 != 0) {
    piVar3 = __errno_location();
    iVar2 = *piVar3;
  }
  return iVar2;
}


// ===== 00290d90 FUN_00290d90 =====

int FUN_00290d90(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = iopl(3);
  iVar2 = 0;
  if (iVar1 != 0) {
    piVar3 = __errno_location();
    iVar2 = *piVar3;
  }
  return iVar2;
}


// ===== 00290db0 FUN_00290db0 =====

undefined8 *
FUN_00290db0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_00290d90();
  *param_1 = param_3;
  param_1[1] = param_4;
  *(undefined4 *)((long)param_1 + 0x1c) = 1;
  return param_1;
}


// ===== 00290de0 FUN_00290de0 =====

int FUN_00290de0(undefined8 param_1,__off_t *param_2)

{
  int __fd;
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  
  __fd = open("/dev/mem",2);
  if (__fd < 0) {
    if (__fd == -1) {
      piVar4 = __errno_location();
      return *piVar4;
    }
  }
  else {
    uVar1 = fcntl(__fd,1);
    if ((uVar1 == 0xffffffff) || (iVar2 = fcntl(__fd,2,(ulong)(uVar1 | 1)), iVar2 == -1)) {
      close(__fd);
      goto LAB_00290e80;
    }
  }
  pvVar3 = mmap((void *)0x0,param_2[1],
                (-(uint)((*(uint *)((long)param_2 + 0x14) & 1) == 0) & 0xfffffffe) + 3,1,__fd,
                *param_2);
  param_2[3] = (__off_t)pvVar3;
  close(__fd);
  if (param_2[3] != -1) {
    return 0;
  }
LAB_00290e80:
  piVar4 = __errno_location();
  return *piVar4;
}


// ===== 00290ea0 FUN_00290ea0 =====

void FUN_00290ea0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined8 *param_5)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_14;
  undefined8 local_10;
  
  local_28 = param_2;
  local_20 = param_3;
  local_14 = param_4;
  FUN_00290de0(param_1,&local_28);
  *param_5 = local_10;
  return;
}


// ===== 00290ed0 FUN_00290ed0 =====

int FUN_00290ed0(void)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined8 *__ptr;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  int local_4c;
  char local_3d;
  uint local_3c [3];
  
  iVar3 = FUN_00290d90();
  if (iVar3 != 0) {
    return iVar3;
  }
  __ptr = calloc(1,0x40);
  if (__ptr == (undefined8 *)0x0) {
    FUN_00290d60();
    return 0xc;
  }
  out(0xcfb,1);
  uVar4 = in(0xcf8);
  out(0xcf8,0x80000000);
  iVar3 = in(0xcf8);
  DAT_01218780 = __ptr;
  if (iVar3 == -0x80000000) {
    out(0xcf8,uVar4);
    __ptr[6] = FUN_00290440;
    __ptr[7] = FUN_002904f0;
    iVar3 = FUN_00290bc0(__ptr + 6);
    if (iVar3 != 0) goto LAB_00290f4b;
LAB_00290fa0:
    iVar9 = 0;
    iVar3 = 0;
    *DAT_01218780 = &PTR_thunk_FUN_00290d60_0032eca0;
    do {
      iVar8 = 0;
LAB_00290fd8:
      do {
        iVar5 = (*(code *)__ptr[6])(iVar3,iVar8,0,0xe,&local_3d,1);
        if (iVar5 == 0) {
          iVar5 = ((int)local_3d >> 0x1f & 7U) + 1;
        }
        else if (iVar5 < 1) {
          iVar8 = iVar8 + 1;
          if (iVar8 == 0x20) break;
          goto LAB_00290fd8;
        }
        iVar10 = 0;
        do {
          iVar6 = (*(code *)__ptr[6])(iVar3,iVar8,iVar10,0,local_3c,4);
          if ((iVar6 == 0) && ((local_3c[0] & 0xffff) != 0xffff)) {
            iVar9 = iVar9 + (uint)((local_3c[0] & 0xffff) != 0);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar5);
        iVar8 = iVar8 + 1;
      } while (iVar8 != 0x20);
      puVar1 = DAT_01218780;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x100);
    iVar3 = 0;
    DAT_01218780[1] = (long)iVar9;
    puVar7 = calloc((long)iVar9,0x160);
    puVar1[2] = puVar7;
    if (puVar7 == (undefined2 *)0x0) {
      FUN_00290d60();
      free(__ptr);
      local_4c = 0xc;
      DAT_01218780 = (undefined8 *)0x0;
    }
    else {
      do {
        iVar9 = 0;
LAB_002910a0:
        do {
          iVar8 = (*(code *)__ptr[6])(iVar3,iVar9,0,0xe,&local_3d,1);
          if (iVar8 == 0) {
            iVar8 = ((int)local_3d >> 0x1f & 7U) + 1;
          }
          else if (iVar8 < 1) {
            iVar9 = iVar9 + 1;
            if (iVar9 == 0x20) break;
            goto LAB_002910a0;
          }
          iVar5 = 0;
          puVar11 = puVar7;
          do {
            iVar10 = (*(code *)__ptr[6])(iVar3,iVar9,iVar5,0,local_3c,4);
            puVar7 = puVar11;
            if (((iVar10 == 0) && ((local_3c[0] & 0xffff) != 0xffff)) &&
               ((local_3c[0] & 0xffff) != 0)) {
              puVar11[3] = (short)local_3c[0];
              *puVar11 = 0;
              *(undefined4 *)(puVar11 + 0x92) = 0;
              *(char *)(puVar11 + 1) = (char)iVar3;
              *(char *)((long)puVar11 + 3) = (char)iVar9;
              *(char *)(puVar11 + 2) = (char)iVar5;
              puVar11[4] = (short)(local_3c[0] >> 0x10);
              iVar10 = (*(code *)__ptr[6])(iVar3,iVar9,iVar5,8,local_3c,4);
              if (iVar10 == 0) {
                *(char *)(puVar11 + 10) = (char)local_3c[0];
                *(uint *)(puVar11 + 8) = local_3c[0] >> 8;
                iVar10 = (*(code *)__ptr[6])(iVar3,iVar9,iVar5,0x2c,local_3c,4);
                if (iVar10 == 0) {
                  puVar7 = puVar11 + 0xb0;
                  puVar11[5] = (short)local_3c[0];
                  puVar11[6] = (short)(local_3c[0] >> 0x10);
                }
              }
            }
            iVar5 = iVar5 + 1;
            puVar11 = puVar7;
          } while (iVar5 < iVar8);
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x20);
        iVar3 = iVar3 + 1;
        local_4c = 0;
      } while (iVar3 != 0x100);
    }
  }
  else {
    out(0xcf8,uVar4);
LAB_00290f4b:
    out(0xcfb,0);
    out(0xcf8,0);
    out(0xcfa,0);
    cVar2 = in(0xcf8);
    if ((cVar2 == '\0') && (cVar2 = in(0xcfa), cVar2 == '\0')) {
      __ptr[6] = FUN_002905b0;
      __ptr[7] = FUN_00290660;
      iVar3 = FUN_00290bc0(__ptr + 6);
      if (iVar3 == 0) goto LAB_00290fa0;
    }
    FUN_00290d60();
    free(__ptr);
    local_4c = 0x13;
    DAT_01218780 = (undefined8 *)0x0;
  }
  return local_4c;
}


// ===== 002912c0 FUN_002912c0 =====

int FUN_002912c0(long param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  byte bVar4;
  byte local_42;
  char local_41;
  byte local_40;
  byte local_3f;
  byte local_3e [2];
  uint local_3c [3];
  
  iVar1 = FUN_0028ecf0(param_1,local_3e,6);
  if ((((iVar1 == 0) && (iVar1 = 0x26, (local_3e[0] & 0x10) != 0)) &&
      (iVar1 = FUN_0028ecc0(param_1,&local_42,0x34), iVar1 == 0)) && (local_42 != 0)) {
    do {
      iVar2 = FUN_0028ecc0(param_1,&local_41);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_0028ecc0(param_1,&local_40,(ulong)local_42 + 1);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_41 == '\x02') {
        iVar2 = FUN_0028ecc0(param_1,&local_3f,local_42 + 2);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = FUN_0028ed20(param_1,local_3c,(ulong)local_42 + 4);
        if (iVar2 != 0) {
          return iVar2;
        }
        puVar3 = calloc(1,0xc);
        if (puVar3 == (uint *)0x0) {
          return 0xc;
        }
        *(uint **)(param_1 + 0x138) = puVar3;
        *puVar3 = (uint)local_42;
        *(byte *)((long)puVar3 + 5) = local_3f & 0xf;
        bVar4 = (byte)local_3c[0] & 7;
        *(byte *)(puVar3 + 1) = local_3f >> 4;
        if ((local_3c[0] & 8) != 0) {
          bVar4 = bVar4 * '\x04';
        }
        *(byte *)((long)puVar3 + 6) = bVar4 & 0xf;
        *(byte *)((long)puVar3 + 7) =
             *(byte *)((long)puVar3 + 7) & 0x80 | (byte)(local_3c[0] >> 4) & 1 |
             ((byte)(local_3c[0] >> 5) & 1) * '\x02' | (byte)(((local_3c[0] >> 6 ^ 1) & 1) << 2) |
             ((byte)local_3c[0] >> 7) << 3 | (byte)((local_3c[0] >> 8 & 1) << 4) |
             (byte)((local_3c[0] >> 9 & 1) << 5) | (byte)((local_3c[0] >> 0x10 & 1) << 6);
        *(char *)(puVar3 + 2) = (char)(1 << ((byte)(local_3c[0] >> 0xd) & 7)) + '\x04';
        *(char *)((long)puVar3 + 10) = (char)(local_3c[0] >> 0x18) + '\x01';
        *(byte *)((long)puVar3 + 9) = (byte)(local_3c[0] >> 10) & 7;
      }
      else {
        printf("Unknown cap 0x%02x @ 0x%02x\n");
      }
      local_42 = local_40;
    } while (local_40 != 0);
  }
  return iVar1;
}


// ===== 002914e0 FUN_002914e0 =====

long FUN_002914e0(long param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (*(long *)(param_1 + 0x138) == 0) {
    (**(code **)(*DAT_01218780 + 0x40))();
    return *(long *)(param_1 + 0x138);
  }
  return *(long *)(param_1 + 0x138);
}


// ===== 00291520 FUN_00291520 =====

int FUN_00291520(undefined8 param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = munmap(*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8));
  iVar3 = 0;
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    iVar3 = *piVar2;
  }
  return iVar3;
}


// ===== 00291550 FUN_00291550 =====

undefined4 FUN_00291550(char *param_1,char *param_2,char **param_3,size_t *param_4)

{
  char cVar1;
  int iVar2;
  size_t __n;
  FILE *__stream;
  ulong uVar3;
  size_t sVar4;
  undefined4 uVar5;
  char *__s1;
  
  __n = strlen(param_2);
  __stream = fopen(param_1,"r");
  if (__stream == (FILE *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    do {
      uVar3 = __getdelim(param_3,param_4,10,__stream);
      if ((long)uVar3 < 0) {
        uVar5 = 0xffffffff;
        goto LAB_002915dd;
      }
      __s1 = *param_3;
      iVar2 = strncmp(__s1,param_2,__n);
    } while (iVar2 != 0);
    sVar4 = 0;
    if (__n < uVar3) {
      do {
        cVar1 = __s1[__n];
        if ((byte)(cVar1 - 0x30U) < 10) {
          __s1[sVar4] = cVar1 - 0x30U;
LAB_00291614:
          sVar4 = sVar4 + 1;
        }
        else {
          if ((byte)(cVar1 + 0xbfU) < 6) {
            __s1[sVar4] = cVar1 + -0x37;
            goto LAB_00291614;
          }
          if ((byte)(cVar1 + 0x9fU) < 6) {
            __s1[sVar4] = cVar1 + -0x57;
            goto LAB_00291614;
          }
        }
        __n = __n + 1;
        if (__n == uVar3) break;
        __s1 = *param_3;
      } while( true );
    }
    *param_4 = sVar4;
    uVar5 = 0;
LAB_002915dd:
    fclose(__stream);
  }
  return uVar5;
}


// ===== 00291680 FUN_00291680 =====

void FUN_00291680(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 002916a0 FUN_002916a0 =====

void FUN_002916a0(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 002916c0 FUN_002916c0 =====

void FUN_002916c0(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 002916e0 FUN_002916e0 =====

void FUN_002916e0(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 00291700 FUN_00291700 =====

void FUN_00291700(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 00291720 FUN_00291720 =====

void FUN_00291720(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 00291740 FUN_00291740 =====

void FUN_00291740(long *param_1)

{
  if (*param_1 != 0) {
    dlclose();
    return;
  }
  return;
}


// ===== 00291760 FUN_00291760 =====

void FUN_00291760(void)

{
  thunk_FUN_00292ff0(&DAT_01218520);
  return;
}


// ===== 00291770 FUN_00291770 =====

void FUN_00291770(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218520);
  return;
}


// ===== 00291780 FUN_00291780 =====

void FUN_00291780(void)

{
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218520);
  return;
}


// ===== 00291790 FUN_00291790 =====

void FUN_00291790(timespec *param_1)

{
  if (DAT_00380788 != -1) {
    clock_gettime(DAT_00380788,param_1);
    return;
  }
  return;
}


// ===== 002917b0 FUN_002917b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_002917b0(int *param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  timespec local_28;
  
  uVar1 = 0;
  if (DAT_00380788 != -1) {
    clock_gettime(DAT_00380788,&local_28);
    auVar2._4_12_ = SUB1612((undefined1  [16])0x0,4);
    auVar2._0_4_ = (float)((int)local_28.tv_nsec - param_1[2]) / _DAT_002f6014 +
                   (float)((int)local_28.tv_sec - *param_1) * _DAT_002ca504;
    uVar1 = auVar2._0_8_;
  }
  return uVar1;
}


