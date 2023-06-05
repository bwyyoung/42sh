You should justify the use of the following functions:


#####MAINTEST

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#          ~ TESTS WITH ONE ARGUMENT ~              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



Success:	 ls -l


Success:	 ls -a


Success:	 ls -r


Success:	 ls -R


Success:	 ls -t

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#      ~ TESTS WITH TWO OR MORE ARGUMENT ~          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ls: -a: No such file or directory
Files your and our differ

Error:		 ls -l -a

1,2c1,4
< t_dir:
< total 24
---
> total 32
> drwxr-xr-x@ 6 byoung-w  2014_paris  204 Jan 26 14:47 .
> drwxr-xr-x@ 7 byoung-w  2014_paris  238 Jan 26 14:51 ..
> -rw-r--r--@ 1 byoung-w  2014_paris   16 Jan 26 14:47 .president
ls: -a: No such file or directory
ls: -r: No such file or directory
Files your and our differ

Error:		 ls -l -a -r

1,4c1
< t_dir:
< total 24
< -rw-r--r--@ 1 byoung-w  2014_paris    3 Jan 26 14:47 42
< -rw-r--r--@ 1 byoung-w  2014_paris  759 Jan 26 14:47 couloir
---
> total 32
5a3,7
> -rw-r--r--@ 1 byoung-w  2014_paris  759 Jan 26 14:47 couloir
> -rw-r--r--@ 1 byoung-w  2014_paris    3 Jan 26 14:47 42
> -rw-r--r--@ 1 byoung-w  2014_paris   16 Jan 26 14:47 .president
> drwxr-xr-x@ 7 byoung-w  2014_paris  238 Jan 26 14:51 ..
> drwxr-xr-x@ 6 byoung-w  2014_paris  204 Jan 26 14:47 .
ls: -R: No such file or directory
ls: -a: No such file or directory
ls: -r: No such file or directory
Files your and our differ

Error:		 ls -l -a -r -R

1,4c1
< t_dir:
< total 24
< -rw-r--r--@ 1 byoung-w  2014_paris    3 Jan 26 14:47 42
< -rw-r--r--@ 1 byoung-w  2014_paris  759 Jan 26 14:47 couloir
---
> total 32
5a3,7
> -rw-r--r--@ 1 byoung-w  2014_paris  759 Jan 26 14:47 couloir
> -rw-r--r--@ 1 byoung-w  2014_paris    3 Jan 26 14:47 42
> -rw-r--r--@ 1 byoung-w  2014_paris   16 Jan 26 14:47 .president
> drwxr-xr-x@ 7 byoung-w  2014_paris  238 Jan 26 14:51 ..
> drwxr-xr-x@ 6 byoung-w  2014_paris  204 Jan 26 14:47 .
ls: -R: No such file or directory
ls: -a: No such file or directory
ls: -r: No such file or directory
ls: -t: No such file or directory
Files your and our differ

Error:		 ls -l -a -r -R -t

1,4c1
< t_dir:
< total 24
< -rw-r--r--@ 1 byoung-w  2014_paris    3 Jan 26 14:47 42
< -rw-r--r--@ 1 byoung-w  2014_paris  759 Jan 26 14:47 couloir
---
> total 32
5a3,7
> -rw-r--r--@ 1 byoung-w  2014_paris  759 Jan 26 14:47 couloir
> -rw-r--r--@ 1 byoung-w  2014_paris    3 Jan 26 14:47 42
> -rw-r--r--@ 1 byoung-w  2014_paris   16 Jan 26 14:47 .president
> drwxr-xr-x@ 6 byoung-w  2014_paris  204 Jan 26 14:47 .
> drwxr-xr-x@ 7 byoung-w  2014_paris  238 Jan 26 14:51 ..
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#        ~ TEST WITH JOINED ARGUMENTS ~             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



Success:	 ls -la


Success:	 ls -rla


Success:	 ls -rlRa


Success:	 ls -trlRa

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#          ~ TESTS THAT FAILS IN /bin/ls -1 ~       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



Error:		 ls -.

/bin/ls return: 1 | ft_ls return: 0


Error:		 ls -l.

/bin/ls return: 1 | ft_ls return: 0


Error:		 ls -.r

/bin/ls return: 1 | ft_ls return: 0


#####MOULITEST
find: /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/includes: No such file or directory
find: /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/srcs: No such file or directory
make exec_tests
find: /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/includes: No such file or directory
find: /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/srcs: No such file or directory
echo "tests/00_test_without_opt.spec.c tests/01_test_opt_R.spec.c tests/02_test_sorted.spec.c tests/03_test_multiple_dir.spec.c tests/04_test_opt_a.spec.c tests/05_test_opt_r.spec.c tests/06_test_opt_rR.spec.c tests/07_test_opt_t.spec.c tests/07_test_opt_tR_bis.spec.c tests/08_test_opt_l.spec.c tests/09_test_opt_aR.spec.c tests/10_test_opt_aRl.spec.c tests/11_test_single_file.spec.c tests/12_test_permissions.spec.c tests/13_test_hyphen_hard.spec.c tests/14_test_hyphen_harder.spec.c tests/20_test_error_handling.spec.c tests/21_test_symlink.spec.c tests/22_test_no_username.spec.c tests/23_test_no_groupname.spec.c tests/24_test_multiple_files.spec.c tests/25_perm_special_bits.spec.c tests/26_perm_special_bits_dir.spec.c tests/30_test_opt_mix.spec.c tests/bonus_01_test_opt_d.spec.c tests/bonus_02_test_opt_p.spec.c tests/bonus_03_test_opt_U.spec.c tests/bonus_04_test_opt_c.spec.c tests/bonus_05_test_opt_S.spec.c tests/bonus_06_test_opt_u.spec.c tests/bonus_07_test_opt_A.spec.c tests/bonus_08_test_opt_1.spec.c tests/bonus_09_test_opt_f.spec.c tests/bonus_10_test_opt_T.spec.c tests/bonus_11_test_opt_g.spec.c tests/bonus_12_test_opt_o_og.spec.c tests/bonus_13_test_opt_F_Fp.spec.c tests/bonus_20_test_opt_comb_aA.spec.c tests/bonus_21_test_opt_mix_sort.spec.c tests/bonus_22_test_sort_comb.spec.c tests/bonus_30_test_xattr.spec.c tests/bonus_31_test_usr_xattr.spec.c tests/bonus_32_test_ACL.spec.c tests/bonus_34_test_redis.spec.c tests/bonus_40_dir_root.spec.c tests/sys_00_test_user_bin.spec.c tests/sys_01_test_dev.spec.c tests/sys_02_test_etc.spec.c tests/sys_03_test_many_files.spec.c tests/sys_04_test_var_run.spec.c"
tests/00_test_without_opt.spec.c tests/01_test_opt_R.spec.c tests/02_test_sorted.spec.c tests/03_test_multiple_dir.spec.c tests/04_test_opt_a.spec.c tests/05_test_opt_r.spec.c tests/06_test_opt_rR.spec.c tests/07_test_opt_t.spec.c tests/07_test_opt_tR_bis.spec.c tests/08_test_opt_l.spec.c tests/09_test_opt_aR.spec.c tests/10_test_opt_aRl.spec.c tests/11_test_single_file.spec.c tests/12_test_permissions.spec.c tests/13_test_hyphen_hard.spec.c tests/14_test_hyphen_harder.spec.c tests/20_test_error_handling.spec.c tests/21_test_symlink.spec.c tests/22_test_no_username.spec.c tests/23_test_no_groupname.spec.c tests/24_test_multiple_files.spec.c tests/25_perm_special_bits.spec.c tests/26_perm_special_bits_dir.spec.c tests/30_test_opt_mix.spec.c tests/bonus_01_test_opt_d.spec.c tests/bonus_02_test_opt_p.spec.c tests/bonus_03_test_opt_U.spec.c tests/bonus_04_test_opt_c.spec.c tests/bonus_05_test_opt_S.spec.c tests/bonus_06_test_opt_u.spec.c tests/bonus_07_test_opt_A.spec.c tests/bonus_08_test_opt_1.spec.c tests/bonus_09_test_opt_f.spec.c tests/bonus_10_test_opt_T.spec.c tests/bonus_11_test_opt_g.spec.c tests/bonus_12_test_opt_o_og.spec.c tests/bonus_13_test_opt_F_Fp.spec.c tests/bonus_20_test_opt_comb_aA.spec.c tests/bonus_21_test_opt_mix_sort.spec.c tests/bonus_22_test_sort_comb.spec.c tests/bonus_30_test_xattr.spec.c tests/bonus_31_test_usr_xattr.spec.c tests/bonus_32_test_ACL.spec.c tests/bonus_34_test_redis.spec.c tests/bonus_40_dir_root.spec.c tests/sys_00_test_user_bin.spec.c tests/sys_01_test_dev.spec.c tests/sys_02_test_etc.spec.c tests/sys_03_test_many_files.spec.c tests/sys_04_test_var_run.spec.c
make re -k -C /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/libft
make re -k -C /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1 -L /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/libft -lft
make[3]: Nothing to be done for `/Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/libft'.
make -k -C ../testframework/v3/
rm -f *.o
cc -Wall -Werror -Wextra -ggdb -I includes -c srcs/**/*.c
ar rc libmt_framework.a *.o
cc -g -I . -I ../testframework/v3//includes -I /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1 -I /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/includes -I /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/includes/builtin -I /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/libs/libtowel/includes -I /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/libft/includes -I /Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/srcs/libft/includes -D__MOULITEST__ -DPROTOTYPES="MT_ADD_PROTO(00_test_without_opt); MT_ADD_PROTO(01_test_opt_R); MT_ADD_PROTO(02_test_sorted); MT_ADD_PROTO(03_test_multiple_dir); MT_ADD_PROTO(04_test_opt_a); MT_ADD_PROTO(05_test_opt_r); MT_ADD_PROTO(06_test_opt_rR); MT_ADD_PROTO(07_test_opt_t); MT_ADD_PROTO(07_test_opt_tR_bis); MT_ADD_PROTO(08_test_opt_l); MT_ADD_PROTO(09_test_opt_aR); MT_ADD_PROTO(10_test_opt_aRl); MT_ADD_PROTO(11_test_single_file); MT_ADD_PROTO(12_test_permissions); MT_ADD_PROTO(13_test_hyphen_hard); MT_ADD_PROTO(14_test_hyphen_harder); MT_ADD_PROTO(20_test_error_handling); MT_ADD_PROTO(21_test_symlink); MT_ADD_PROTO(22_test_no_username); MT_ADD_PROTO(23_test_no_groupname); MT_ADD_PROTO(24_test_multiple_files); MT_ADD_PROTO(25_perm_special_bits); MT_ADD_PROTO(26_perm_special_bits_dir); MT_ADD_PROTO(30_test_opt_mix); MT_ADD_PROTO(bonus_01_test_opt_d); MT_ADD_PROTO(bonus_02_test_opt_p); MT_ADD_PROTO(bonus_03_test_opt_U); MT_ADD_PROTO(bonus_04_test_opt_c); MT_ADD_PROTO(bonus_05_test_opt_S); MT_ADD_PROTO(bonus_06_test_opt_u); MT_ADD_PROTO(bonus_07_test_opt_A); MT_ADD_PROTO(bonus_08_test_opt_1); MT_ADD_PROTO(bonus_09_test_opt_f); MT_ADD_PROTO(bonus_10_test_opt_T); MT_ADD_PROTO(bonus_11_test_opt_g); MT_ADD_PROTO(bonus_12_test_opt_o_og); MT_ADD_PROTO(bonus_13_test_opt_F_Fp); MT_ADD_PROTO(bonus_20_test_opt_comb_aA); MT_ADD_PROTO(bonus_21_test_opt_mix_sort); MT_ADD_PROTO(bonus_22_test_sort_comb); MT_ADD_PROTO(bonus_30_test_xattr); MT_ADD_PROTO(bonus_31_test_usr_xattr); MT_ADD_PROTO(bonus_32_test_ACL); MT_ADD_PROTO(bonus_34_test_redis); MT_ADD_PROTO(bonus_40_dir_root); MT_ADD_PROTO(sys_00_test_user_bin); MT_ADD_PROTO(sys_01_test_dev); MT_ADD_PROTO(sys_02_test_etc); MT_ADD_PROTO(sys_03_test_many_files); MT_ADD_PROTO(sys_04_test_var_run); " -DADD_TESTS="MT_ADD_SUITE(mt, 00_test_without_opt, suite_00_test_without_opt); MT_ADD_SUITE(mt, 01_test_opt_R, suite_01_test_opt_R); MT_ADD_SUITE(mt, 02_test_sorted, suite_02_test_sorted); MT_ADD_SUITE(mt, 03_test_multiple_dir, suite_03_test_multiple_dir); MT_ADD_SUITE(mt, 04_test_opt_a, suite_04_test_opt_a); MT_ADD_SUITE(mt, 05_test_opt_r, suite_05_test_opt_r); MT_ADD_SUITE(mt, 06_test_opt_rR, suite_06_test_opt_rR); MT_ADD_SUITE(mt, 07_test_opt_t, suite_07_test_opt_t); MT_ADD_SUITE(mt, 07_test_opt_tR_bis, suite_07_test_opt_tR_bis); MT_ADD_SUITE(mt, 08_test_opt_l, suite_08_test_opt_l); MT_ADD_SUITE(mt, 09_test_opt_aR, suite_09_test_opt_aR); MT_ADD_SUITE(mt, 10_test_opt_aRl, suite_10_test_opt_aRl); MT_ADD_SUITE(mt, 11_test_single_file, suite_11_test_single_file); MT_ADD_SUITE(mt, 12_test_permissions, suite_12_test_permissions); MT_ADD_SUITE(mt, 13_test_hyphen_hard, suite_13_test_hyphen_hard); MT_ADD_SUITE(mt, 14_test_hyphen_harder, suite_14_test_hyphen_harder); MT_ADD_SUITE(mt, 20_test_error_handling, suite_20_test_error_handling); MT_ADD_SUITE(mt, 21_test_symlink, suite_21_test_symlink); MT_ADD_SUITE(mt, 22_test_no_username, suite_22_test_no_username); MT_ADD_SUITE(mt, 23_test_no_groupname, suite_23_test_no_groupname); MT_ADD_SUITE(mt, 24_test_multiple_files, suite_24_test_multiple_files); MT_ADD_SUITE(mt, 25_perm_special_bits, suite_25_perm_special_bits); MT_ADD_SUITE(mt, 26_perm_special_bits_dir, suite_26_perm_special_bits_dir); MT_ADD_SUITE(mt, 30_test_opt_mix, suite_30_test_opt_mix); MT_ADD_SUITE(mt, bonus_01_test_opt_d, suite_bonus_01_test_opt_d); MT_ADD_SUITE(mt, bonus_02_test_opt_p, suite_bonus_02_test_opt_p); MT_ADD_SUITE(mt, bonus_03_test_opt_U, suite_bonus_03_test_opt_U); MT_ADD_SUITE(mt, bonus_04_test_opt_c, suite_bonus_04_test_opt_c); MT_ADD_SUITE(mt, bonus_05_test_opt_S, suite_bonus_05_test_opt_S); MT_ADD_SUITE(mt, bonus_06_test_opt_u, suite_bonus_06_test_opt_u); MT_ADD_SUITE(mt, bonus_07_test_opt_A, suite_bonus_07_test_opt_A); MT_ADD_SUITE(mt, bonus_08_test_opt_1, suite_bonus_08_test_opt_1); MT_ADD_SUITE(mt, bonus_09_test_opt_f, suite_bonus_09_test_opt_f); MT_ADD_SUITE(mt, bonus_10_test_opt_T, suite_bonus_10_test_opt_T); MT_ADD_SUITE(mt, bonus_11_test_opt_g, suite_bonus_11_test_opt_g); MT_ADD_SUITE(mt, bonus_12_test_opt_o_og, suite_bonus_12_test_opt_o_og); MT_ADD_SUITE(mt, bonus_13_test_opt_F_Fp, suite_bonus_13_test_opt_F_Fp); MT_ADD_SUITE(mt, bonus_20_test_opt_comb_aA, suite_bonus_20_test_opt_comb_aA); MT_ADD_SUITE(mt, bonus_21_test_opt_mix_sort, suite_bonus_21_test_opt_mix_sort); MT_ADD_SUITE(mt, bonus_22_test_sort_comb, suite_bonus_22_test_sort_comb); MT_ADD_SUITE(mt, bonus_30_test_xattr, suite_bonus_30_test_xattr); MT_ADD_SUITE(mt, bonus_31_test_usr_xattr, suite_bonus_31_test_usr_xattr); MT_ADD_SUITE(mt, bonus_32_test_ACL, suite_bonus_32_test_ACL); MT_ADD_SUITE(mt, bonus_34_test_redis, suite_bonus_34_test_redis); MT_ADD_SUITE(mt, bonus_40_dir_root, suite_bonus_40_dir_root); MT_ADD_SUITE(mt, sys_00_test_user_bin, suite_sys_00_test_user_bin); MT_ADD_SUITE(mt, sys_01_test_dev, suite_sys_01_test_dev); MT_ADD_SUITE(mt, sys_02_test_etc, suite_sys_02_test_etc); MT_ADD_SUITE(mt, sys_03_test_many_files, suite_sys_03_test_many_files); MT_ADD_SUITE(mt, sys_04_test_var_run, suite_sys_04_test_var_run); " -DRENDU_PATH="\"/Users/byoung-w/ANNEE_1/ft_ls/test_clone_1\"" tests/00_test_without_opt.spec.c tests/01_test_opt_R.spec.c tests/02_test_sorted.spec.c tests/03_test_multiple_dir.spec.c tests/04_test_opt_a.spec.c tests/05_test_opt_r.spec.c tests/06_test_opt_rR.spec.c tests/07_test_opt_t.spec.c tests/07_test_opt_tR_bis.spec.c tests/08_test_opt_l.spec.c tests/09_test_opt_aR.spec.c tests/10_test_opt_aRl.spec.c tests/11_test_single_file.spec.c tests/12_test_permissions.spec.c tests/13_test_hyphen_hard.spec.c tests/14_test_hyphen_harder.spec.c tests/20_test_error_handling.spec.c tests/21_test_symlink.spec.c tests/22_test_no_username.spec.c tests/23_test_no_groupname.spec.c tests/24_test_multiple_files.spec.c tests/25_perm_special_bits.spec.c tests/26_perm_special_bits_dir.spec.c tests/30_test_opt_mix.spec.c tests/bonus_01_test_opt_d.spec.c tests/bonus_02_test_opt_p.spec.c tests/bonus_03_test_opt_U.spec.c tests/bonus_04_test_opt_c.spec.c tests/bonus_05_test_opt_S.spec.c tests/bonus_06_test_opt_u.spec.c tests/bonus_07_test_opt_A.spec.c tests/bonus_08_test_opt_1.spec.c tests/bonus_09_test_opt_f.spec.c tests/bonus_10_test_opt_T.spec.c tests/bonus_11_test_opt_g.spec.c tests/bonus_12_test_opt_o_og.spec.c tests/bonus_13_test_opt_F_Fp.spec.c tests/bonus_20_test_opt_comb_aA.spec.c tests/bonus_21_test_opt_mix_sort.spec.c tests/bonus_22_test_sort_comb.spec.c tests/bonus_30_test_xattr.spec.c tests/bonus_31_test_usr_xattr.spec.c tests/bonus_32_test_ACL.spec.c tests/bonus_34_test_redis.spec.c tests/bonus_40_dir_root.spec.c tests/sys_00_test_user_bin.spec.c tests/sys_01_test_dev.spec.c tests/sys_02_test_etc.spec.c tests/sys_03_test_many_files.spec.c tests/sys_04_test_var_run.spec.c main.c utils.c   -o ft_ls_test -L../testframework/v3/ -lmt_framework
/Volumes/bwyyoung_42_2/Dropbox/42_LOCAL/Documents/ANNEE_2/42FileChecker/moulitest_42projects/ft_ls_tests/ft_ls_test

--

>>>> Tests for ft_ls
Source: github.com/yyang42/moulitest
Legend: (.) Ok / (F) Fail / (S) Segfault / (B) Bus error / (T) Timeout / (A) Abort

[ -------STARTING ALL UNIT TESTS------- ]
>>>> 00_test_without_opt.spec.c -- [Ok !] ...
>>>> 01_test_opt_R.spec.c -------- [Ok !] .......
>>>> 02_test_sorted.spec.c ------- [Ok !] ...
>>>> 03_test_multiple_dir.spec.c - [Ok !] .....
>>>> 04_test_opt_a.spec.c -------- [Ok !] ..
>>>> 05_test_opt_r.spec.c -------- [Ok !] ...
>>>> 06_test_opt_rR.spec.c ------- [Ok !] ....
>>>> 07_test_opt_t.spec.c -------- [FAIL] ......F [FAIL] simple_test_6 -> strcmp(ls(cmd), ft_ls(cmd)) == 0
>>>> 07_test_opt_tR_bis.spec.c --- [Ok !] .
>>>> 08_test_opt_l.spec.c -------- [FAIL] ......F [FAIL] simple_test_6 -> strcmp(ls(cmd), ft_ls(cmd)) == 0
>>>> 09_test_opt_aR.spec.c ------- [Ok !] ..
>>>> 10_test_opt_aRl.spec.c ------ [Ok !] .
>>>> 11_test_single_file.spec.c -- [Ok !] ..
>>>> 12_test_permissions.spec.c -- [Ok !] ..
>>>> 13_test_hyphen_hard.spec.c -- [Ok !] ........
>>>> 14_test_hyphen_harder.spec.c  [Ok !] ..........
>>>> 20_test_error_handling.spec.c [FAIL] ..............F.FFF.FFFFF [FAIL] unitTest_14 -> strcmp(ls_out_str, ft_ls_out_str) == 0
>>>> 21_test_symlink.spec.c ------ [Ok !] ....
>>>> 22_test_no_username.spec.c -- [Ok !] .
>>>> 23_test_no_groupname.spec.c - [Ok !] .
>>>> 24_test_multiple_files.spec.c [Ok !] ...
>>>> 25_perm_special_bits.spec.c - [Ok !] ................
>>>> 26_perm_special_bits_dir.spec [Ok !] ................
>>>> 30_test_opt_mix.spec.c ------ [Ok !] .
>>>> bonus_01_test_opt_d.spec.c -- [Ok !] ..........
>>>> bonus_02_test_opt_p.spec.c -- [Ok !] .....
>>>> bonus_03_test_opt_U.spec.c -- [Ok !] ...
>>>> bonus_04_test_opt_c.spec.c -- [FAIL] .....FF [FAIL] unitTest_05 -> strcmp(ls(cmd), ft_ls(cmd)) == 0
>>>> bonus_05_test_opt_S.spec.c -- [Ok !] .....
>>>> bonus_06_test_opt_u.spec.c -- [Ok !] ......................
>>>> bonus_07_test_opt_A.spec.c -- [Ok !] ....
>>>> bonus_08_test_opt_1.spec.c -- [Ok !] ..
>>>> bonus_09_test_opt_f.spec.c -- [Ok !] ..
>>>> bonus_10_test_opt_T.spec.c -- [Ok !] .
>>>> bonus_11_test_opt_g.spec.c -- [Ok !] ...
>>>> bonus_12_test_opt_o_og.spec.c [Ok !] ....
>>>> bonus_13_test_opt_F_Fp.spec.c [Ok !] .......
>>>> bonus_20_test_opt_comb_aA.spe [Ok !] ..
>>>> bonus_21_test_opt_mix_sort.sp [Ok !] ..
>>>> bonus_22_test_sort_comb.spec. [FAIL] ...F........ [FAIL] unitTest_03 -> strcmp(ls(cmd), ft_ls(cmd)) == 0
>>>> bonus_30_test_xattr.spec.c -- [Ok !] .
>>>> bonus_31_test_usr_xattr.spec. [Ok !] ..
>>>> bonus_32_test_ACL.spec.c ---- [Ok !] .
>>>> bonus_34_test_redis.spec.c -- [Ok !] .
>>>> bonus_40_dir_root.spec.c ---- [Ok !] .
>>>> sys_00_test_user_bin.spec.c - [Ok !] ....
>>>> sys_01_test_dev.spec.c ------ [Ok !] ...
>>>> sys_02_test_etc.spec.c ------ [Ok !] .
>>>> sys_03_test_many_files.spec.c [Ok !] .
>>>> sys_04_test_var_run.spec.c -- [Ok !] .
[ ----------END OF UNIT TESTS---------- ]

>>>> Result: 45/50 test suites passed. 227/241 tests passed (dots).


#####Forbidden Functions

------------------------------------
/Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/ft_ls_l.c

-> acl_get_link_np
   (line #021: facl = acl_get_link_np(name, ACL_TYPE_EXTENDED);)

-> acl_get_entry
   (line #022: if (facl && (acl_get_entry(facl, ACL_FIRST_ENTRY, &ae) == -1)))
7
-> acl_free
   (line #024: acl_free(facl);)

-> acl_free
   (line #029: acl_free(facl);)

-> acl_free
   (line #032: acl_free(facl);)




#####SPEED TEST
Your program is compared with the original 'ls'.

How it works:
Both programs are executed one at a time with the same options so that time needed for execution is greater than 10 seconds.
During 10 seconds, the stdout of each program is saved in a temporary file and then the lines are counted.
The rate is calculated by comparing both line counts.

Warning: Your program must work perfectly (the same stdout from the original program) and you should perform your own test with a greater interval of time.

-----------------

# Your program:
/Users/byoung-w/ANNEE_1/ft_ls/test_clone_1/ft_ls -1lR /
--> 72496 lines written on stdout

# Original program:
ls -1lR /
--> 129237 lines written on stdout

Estimated speed rate:  56%

#####LEAKS

Process:         ft_ls [6327]
Path:            /Volumes/bwyyoung_42_2/Dropbox/42_LOCAL/Documents/ANNEE_1/ft_ls/test_clone_1/ft_ls
Load Address:    0x1012f4000
Identifier:      ft_ls
Version:         ???
Code Type:       X86-64
Parent Process:  sh [6325]

Date/Time:       2017-01-26 14:50:33.656 +0100
Launch Time:     2017-01-26 14:50:28.029 +0100
OS Version:      Mac OS X 10.11.6 (15G1217)
Report Version:  7
Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
Analysis Tool Version:  Xcode 8.2.1 (8C1002)
----

leaks Report Version:  2.0
Process 6327: 190324 nodes malloced for 8726 KB
Process 6327: 189010 leaks for 8825120 total leaked bytes.
Leak: 0x7fef78403ae0  size=16  zone: DefaultMallocZone_0x1012fd000  length: 10  ".fseventsd"
Leak: 0x7fef78403af0  size=32  zone: DefaultMallocZone_0x1012fd000  length: 16  "/.hotfiles.btree"
Leak: 0x7fef78403c00  size=16  zone: DefaultMallocZone_0x1012fd000  length: 15  ".hotfiles.btree"
Leak: 0x7fef78403c10  size=32  zone: DefaultMallocZone_0x1012fd000  length: 21  "/.OSInstallerMessages"
Leak: 0x7fef78403cd0  size=16  zone: DefaultMallocZone_0x1012fd000  length: 10  ".fseventsd"
Leak: 0x7fef78403ce0  size=32  zone: DefaultMallocZone_0x1012fd000  length: 16  "/.Spotlight-V100"
Leak: 0x7fef78403d00  size=32  zone: DefaultMallocZone_0x1012fd000  length: 17  "//.Spotlight-V100"
Leak: 0x7fef78403d20  size=16  zone: DefaultMallocZone_0x1012fd000  length: 15  "//Applications/"
Leak: 0x7fef78403d50  size=32  zone: DefaultMallocZone_0x1012fd000  length: 20  ".OSInstallerMessages"
Leak: 0x7fef78403de0  size=16  zone: DefaultMallocZone_0x1012fd000  length: 15  "/Calculator.app"
Leak: 0x7fef78403e70  size=16  zone: DefaultMallocZone_0x1012fd000  length: 15  ".TemporaryItems"
Leak: 0x7fef78403e80  size=16  zone: DefaultMallocZone_0x1012fd000  length: 9  ".DS_Store"
Leak: 0x7fef78403e90  size=16  zone: DefaultMallocZone_0x1012fd000  length: 6  "/.file"
Leak: 0x7fef78403eb0  size=16  zone: DefaultMallocZone_0x1012fd000  length: 15  ".Spotlight-V100"
Leak: 0x7fef78403ee0  size=32  zone: DefaultMallocZone_0x1012fd000  length: 20  "Jan 26 14:24:46 2017"
Leak: 0x7fef78403f00  size=16  zone: DefaultMallocZone_0x1012fd000  length: 5  ".file"
Leak: 0x7fef78403f10  size=16  zone: DefaultMallocZone_0x1012fd000  length: 11  "/.fseventsd"
Leak: 0x7fef78403f40  size=32  zone: DefaultMallocZone_0x1012fd000  length: 22  "//.OSInstallerMessages"
Leak: 0x7fef78403f60  size=16  zone: DefaultMallocZone_0x1012fd000  length: 12  "Applications"
